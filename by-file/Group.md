*** UID:0000JS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Group

## Status

- Confidence: strong for `NewGroupPane`, `GroupPane`, `GroupPane2`, group packet/list behavior, and group marker helpers; medium for `GroupListPane` source emission and exact scrollbar class boundaries.
- Proposed module folder: `social/`
- Proposed source file: `social/Group.cpp`
- Possible split files: `social/GroupPane.cpp`, `social/GroupChatInput.cpp`, [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md), and [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- Evidence basis: Wave3 class inspection, generated `simroot_v2` sources, older Wave2 notes in `by-memory/-report.md`, and IDA MCP function-boundary/decompilation checks on 2026-05-23.

## Hypothesis

The original group/party UI likely had a feature-owned source file for the visible group panes, packet parsing, group member drawing, and map-marker synchronization. `NewGroupPane` is the strongest anchor: it constructs the custom scroll child, requests group lists with opcode `0x2d`, parses the server member list, draws names/levels/HP/MP rows, toggles expanded mode, and updates map markers through `MapPane`.

`GroupPane` and `GroupPane2` look like older or alternate group list shells. They allocate a `0x174`-byte `GroupListPane` text-list child, refresh a fixed list viewport, and paint the `GROUP.EPF` background/tab graphic.

`SayToGroupMessageInputPane` is feature-related but may belong with the broader say/chat input family rather than the main group pane file. `GroupInputPane` is already documented with command input panes because its confirmed function sends generic group-command opcode `0x2e` from a line prompt.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `GroupPane` | `0x0056c4c0-0x0056c750`, destructor `0x00573490-0x0057353d` | `class_GroupPane.cpp` | Older group panel shell with a `GroupListPane`/text child, fixed list viewport refresh, and `GROUP.EPF` paint. |
| `GroupPane2` | `0x0056c770-0x0056ca00`, destructor `0x005733e0-0x0057348d` | `class_GroupPane2.cpp` | Alternate group panel shell with the same list viewport behavior plus tab/background drawing. |
| `GroupPane`/`GroupPane2` false virtual stubs | `0x0056c4a0-0x0056c4b5` | shared local stubs | Two tiny `return false` virtual/default stubs immediately before the `GroupPane` constructors. |
| `NewGroupPane` | `0x0056ca20-0x0056e939`, destructor/thunks at `0x0057329f`, `0x005732aa`, `0x00573570-0x00573634` | `class_NewGroupPane.cpp` | Main group management pane: request list, layout, render rows, handle input, parse group list packets, update scroll range, and toggle expanded mode. |
| `ScrollNewGroupPane` | core `0x00560900-0x0056141f`, hit-test `0x00561420-0x0056173d`, part rect `0x00561740-0x005619c7`, interaction helpers `0x005619d0-0x00561db0` | `class_ScrollNewGroupPane.cpp`, plus current `TextEditPane`-owned generated helpers | Custom EPF-backed scrollbar used by `NewGroupPane`; current simroot ownership is polluted for several helper methods. |
| `GroupListPane` | raw [UID:0001H8][0x0056baa0-0x0056bb00.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bb00.GroupListPaneRawConstructor.md), real [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md), nearby [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) | `class_GroupListPane.cpp` | Standalone constructor bytes exist but IDA does not auto-model them as a function; `GroupPane` and `GroupPane2` inline the same child setup. |
| `SayToGroupMessageInputPane` | `0x005b1ec0-0x005b2152` | `class_SayToGroupMessageInputPane.cpp` | Group chat input pane; stores destination group name and sends opcode `0x19` with group name and message text. |
| `GroupInputPane` | `0x005b5440-0x005b5547`, projected constructor `0x005b5400` | `class_GroupInputPane.cpp` | Generic group command prompt; see [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md). |
| `RefreshGroupMemberMarkers_5ADC20` | `0x005adc20-0x005adc62` | `recovered/RefreshGroupMemberMarkers_005ADC20.cpp` | Replays cached group members into `MapPane::ProcessMapEvent`. |
| `ClearGroupMemberMarkers_5ADC70` | `0x005adc70-0x005adcb2` | `recovered/ClearGroupMemberMarkers_005ADC70.cpp` | Clears cached group members through `MapPane::ActivateLinkedObjectById`. |

## Boundary And Data Notes

- IDA MCP confirms the main group pane function starts at `0x0056c4c0`, `0x0056c5c0`, `0x0056c630`, `0x0056c6c0`, `0x0056c770`, `0x0056c870`, `0x0056c8e0`, `0x0056c970`, `0x0056ca20`, `0x0056cb80`, `0x0056cbf0`, `0x0056cc80`, `0x0056cd30`, `0x0056ce50`, `0x0056da10`, `0x0056db00`, `0x0056df00`, `0x0056df40`, `0x0056dfb0`, `0x0056dfd0`, `0x0056e130`, `0x0056e6d0`, and `0x0056e8c0`.
- IDA reports no auto-function at Wave3 starts `0x0056baa0`, `0x005619d0`, `0x00561d50`, `0x0056e570`, or `0x005b5400`. The `0x0056baa0-0x0056bafd` bytes are a constructor-shaped manual boundary and are now documented separately.
- `GroupListPane` vtables are `0x00624214`, `0x0062428c`, and `0x006242bc`; exact data lives at [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md). `GroupPane`, `GroupPane2`, and `NewGroupPane` use the same `+0x00`, `+0xa0`, `+0xa4` vtable pattern documented in [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md), with exact data children [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md), [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md), and [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md).
- The mixed destructor area is split between [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md) for `GroupPane2`/`GroupPane` and [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md) for `NewGroupPane`.
- IDA confirms nearby real functions `0x00561420`, `0x00561b00`, and `0x00561bc0`; a 2026-05-26 xref/callback pass ties them to `ScrollNewGroupPane` despite current generated `TextEditPane` ownership. Raw helper starts `0x005619d0`, `0x00561a40`, and `0x00561d50` are method-shaped but not IDA auto-functions.
- IDA decompilation at `0x0056bb20` constructs a `SpelledPane`/text-edit style object and is called from other UI code, so it should not be used as clean `GroupListPane` ownership without more evidence.
- `NewGroupPane::UpdateGroupEntry` is currently projected at `0x0056e570`, but IDA says `0x0056e570` is not a function; the confirmed parser at `0x0056e130` ends at `0x0056e565`, and the next confirmed function is `0x0056e6d0`.
- 2026-05-28 IDA MCP resolved `0x0056c493-0x0056c4c0` as padding plus two tiny false virtual stubs at `0x0056c4a0-0x0056c4b5`; keep those with the group pane family.

## Migration Notes

Do not run source ownership migrations until the projected starts above are either corrected or explicitly marked projected/non-IDA. A future dry-run should keep `GroupInputPane` with command inputs unless stronger evidence ties it to the main group pane file.

```powershell
python source-3\wave3.py create file Group.cpp --kind source --simpath social/Group.cpp --dry-run
python source-3\wave3.py attach class GroupPane --to-file Group.cpp
python source-3\wave3.py attach class GroupPane2 --to-file Group.cpp
python source-3\wave3.py attach class NewGroupPane --to-file Group.cpp
python source-3\wave3.py attach class ScrollNewGroupPane --to-file Group.cpp
```

Review `SayToGroupMessageInputPane` with the broader `Say*InputPane` family before attaching it to `Group.cpp`.

## Cross-References

- [UID:00005Y][GroupPane](by-class/GroupPane.md)
- [UID:00005Z][GroupPane2](by-class/GroupPane2.md)
- [UID:000090][NewGroupPane](by-class/NewGroupPane.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- [UID:00005X][GroupListPane](by-class/GroupListPane.md)
- [UID:0001H8][0x0056baa0-0x0056bb00.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bb00.GroupListPaneRawConstructor.md)
- [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md)
- [UID:00023W][0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs](by-memory/0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs.md)
- [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md)
- [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md)
- [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md)
- [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md)
- [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md)
- [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md)
- [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md)
- [UID:0000C4][SayToGroupMessageInputPane](by-class/SayToGroupMessageInputPane.md)
- [UID:00005W][GroupInputPane](by-class/GroupInputPane.md)
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0001GP][0x00560900-0x0056141f.ScrollNewGroupPaneCore](by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md)
- [UID:0001GQ][0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart](by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md)
- [UID:0001GR][0x00561740-0x005619c7.ScrollNewGroupPanePartRect](by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md)
- [UID:0001GS][0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers](by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md)
- [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md)
- [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md)
- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)

## Changes

- 2026-06-01: Set projected reconstruction path to `NexusTK/social/`.
  - Evidence: this page already proposes `social/Group.cpp`; current IDA evidence on [UID:0001GP][0x00560900-0x0056141f.ScrollNewGroupPaneCore](by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md) confirms a Group-owned child can attach here.
  - Scope: path assignment only; reconstructed C++ remains gated by exact child-page confidence and final helper naming quality.
- 2026-05-28: Added `0x0056c4a0-0x0056c4b5` as group-pane false virtual stubs.
  - Before: the range between `LegendPane` and `GroupPanes` was an UNKNOWN gap.
  - After: padding is separated from two real `return false` stubs that belong with the group pane family.
  - Evidence: IDA MCP reports functions at `0x0056c4a0-0x0056c4a5` and `0x0056c4b0-0x0056c4b5`, both `xor al, al; retn 4`, with `0xcc` alignment around them.
- 2026-05-28: Added exact group-pane destructor island pages.
  - Before: group-pane destructor references were listed as start addresses only.
  - After: exact destructor endpoints and owning mixed destructor pages are recorded for `GroupPane2`, `GroupPane`, and `NewGroupPane`.
  - Evidence: IDA MCP reports `sub_5733e0`, `sub_573490`, and `sub_573570` as the scalar deleting destructors for those vtable families.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: group pane generations, custom scroll child, raw constructors/stubs, vtable/destructor islands, group packet/list behavior, marker helpers, migration notes, and split caveats are documented; confidence is capped by exact `GroupListPane` emission and scrollbar/helper source ownership.
- 2026-05-31: Added exact group-pane vtable-data child references.
  - Before: vtable ownership was summarized through the family page only.
  - After: the source-file page points to exact by-memory children for `GroupListPane`, `GroupPane`, `GroupPane2`, and `NewGroupPane`.
  - Evidence: IDA MCP `py_eval` and `xrefs_to` checks confirmed class-specific RTTI boundaries and store xrefs.
