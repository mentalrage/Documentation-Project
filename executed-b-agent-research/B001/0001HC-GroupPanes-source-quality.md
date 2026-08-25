** TARGET-REPORT-UID:0001HC **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-group-panes-source-quality-0001HC-20260618

Primary target: [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](../../../by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)

Required output path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0001HC-GroupPanes-source-quality.md`

This report is report-only. I did not edit by-memory docs, generated reports, generated source, the IDA DB, or `by-memory/-coverage-report.md`.

## Finalized Report / Current Recommendation

Recommended disposition for [UID:0001HC] is to convert the broad `GroupPanes` executable range from a code-emitting aggregate into a non-emitting split/index. It is real NexusTK project code under the [UID:0000JS][Group](../../../by-file/Group.md) source root, but the current page is not a single source body: it spans `GroupPane`, `GroupPane2`, `NewGroupPane`, several vtable-only trivial stubs, modeled and raw private helpers, and internal alignment.

Recommended metadata after supervisor application:

| Field | Recommended value | Reason |
| --- | --- | --- |
| `COMPLETION` | `88` | The class owners, vtables, destructor/thunk routes, packet/list behavior, scroll-child relationship, map-marker side effects, raw helper boundaries, and raw no-route evidence are now resolved at report level. The score should not cross into final-source completeness because exact child pages and child C++ are not yet populated. |
| `CONFIDENCE` | `90` | Current docs, exported function data, vtable pages, and local PE byte checks agree on ownership, function boundaries, raw helper bodies, and successor/predecessor boundaries. Confidence is capped because the live IDA/MCP endpoint was unavailable in this pass and several tiny virtual/helper source spellings remain role-based. |
| `CANONICAL_OWNER` | `0000JS` | The feature source root remains `NexusTK/social/Group.cpp`; a narrower `GroupPane.cpp` split is plausible for a reconstructed tree but is not proved by binary evidence. |
| `RECONSTRUCTABLE` | `FALSE` | The broad page is a physical split/index, not a single reconstructable function or class body. |
| `EMITTER_UIDS` | blank | Exact child method/class pages should emit; the aggregate must not. |
| Formal C++ | blank | See target-specific no-code proof below. |

Key current-doc corrections:

- Add the omitted modeled `NewGroupPane` non-deleting destructor at `0x0056caf0-0x0056cb73`.
- Add the omitted modeled tiny stubs `0x0056c760-0x0056c765` for `GroupPane` and `0x0056ca10-0x0056ca15` for `GroupPane2`.
- Correct raw helper half-open ranges from `0x0056e030-0x0056e083` to `0x0056e030-0x0056e086`, and from `0x0056e090-0x0056e123` to `0x0056e090-0x0056e126`.
- Add the omitted raw helper `0x0056e820-0x0056e8b4`, a toggle-button hit-test helper with no known callers.
- Keep `0x0056e570-0x0056e6c1` as a raw no-route group-member status/update helper; it is source-shaped but duplicated by the live subtype-3 path in `0x0056dd50`.
- Treat [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs](../../../by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md) as predecessor boundary context only. Those stubs are `LegendPane` vtable targets, not `GroupPane` or `GroupPane2` source content.

Exact source placement recommendation:

- Keep the source root as [UID:0000JS][Group](../../../by-file/Group.md), proposed path `NexusTK/social/Group.cpp`.
- If the supervisor later introduces narrower reconstructed files, `GroupPane`, `GroupPane2`, `NewGroupPane`, `GroupListPane`, and `ScrollNewGroupPane` can reasonably live in `NexusTK/social/GroupPane.cpp` or equivalent, but that should be a source-tree organization choice under the same `Group` feature root. No binary evidence proves a distinct original file boundary.
- Do not move `ScrollNewGroupPane` to `TextEditPane` or `ScrollCollectionPane`: `NewGroupPane::NewGroupPane` calls the constructor at `0x0056caae`, calls `Show` at `0x0056cac3`, and the scrollbar cursor-to-position helper calls back into `NewGroupPane::SetScrollPosition` at `0x00561d35 -> 0x0056df00`.

## Evidence Checked

Rules and assignment context:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B001/goal.md`
- `tools/leaser/Agents/Agent-B001/notes.md`

Primary and support docs:

- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](../../../by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0000JS][Group](../../../by-file/Group.md)
- [UID:00005Y][GroupPane](../../../by-class/GroupPane.md)
- [UID:00005Z][GroupPane2](../../../by-class/GroupPane2.md)
- [UID:000090][NewGroupPane](../../../by-class/NewGroupPane.md)
- [UID:00005X][GroupListPane](../../../by-class/GroupListPane.md)
- [UID:0000CL][ScrollNewGroupPane](../../../by-class/ScrollNewGroupPane.md)
- [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs](../../../by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md)
- [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](../../../by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md)
- [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](../../../by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](../../../by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- [UID:0001GP][0x00560900-0x0056141f.ScrollNewGroupPaneCore](../../../by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md)
- [UID:0001GQ][0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart](../../../by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md)
- [UID:0001GR][0x00561740-0x005619c7.ScrollNewGroupPanePartRect](../../../by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md)
- [UID:0001GS][0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers](../../../by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md)
- [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](../../../by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](../../../by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md)
- [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](../../../by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md)
- [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](../../../by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md)
- [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](../../../by-memory/0x0056e940-0x0056fe75.CollectionPane.md)
- [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](../../../by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md)
- [UID:0001VP][RectBoundsLayout](../../../by-type/by-struct/RectBoundsLayout.md)
- [UID:00015S][RectBounds](../../../by-file/RectBounds.md)

Local exported and binary evidence:

- `resources/exported_data/functions/0x0056c4c0.json` through `0x0056e8c0.json` for function names, sizes, decompiles, callers, callees, and xrefs.
- `resources/exported_data/functions/0x0056e030.json`, `0x0056e090.json`, `0x0056e570.json`, and newly noticed `0x0056e820.json` for raw helper semantics and zero exported callers.
- `resources/exported_data/master_function_list.json`, `master_names.json`, `master_globals.json`, `master_vtables.json`, and `detection_differences.json` for address/name/vtable/global searches.
- Local PE byte reads from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, section `.text` VA `0x00001000`, raw pointer `0x400`, raw size `0x20b600`.
- Little-endian VA pointer scan of the local PE for `0x0056e030`, `0x0056e090`, `0x0056e570`, and `0x0056e820`: zero hits for all four address literals.
- Text search across docs and exports for raw helper addresses and the little-endian byte strings.
- Attempted `http://127.0.0.1:8181/mcp/tools/list`; the local IDA/MCP endpoint was not reachable in this pass. I did not change the IDB.

Current function and raw-helper inventory:

| Range | Current modeled status | Owner/role |
| --- | --- | --- |
| `0x0056c4c0-0x0056c5b1` | IDA/Ghidra modeled | `GroupPane::GroupPane()` constructor. |
| `0x0056c5c0-0x0056c62c` | IDA/Ghidra modeled | `GroupPane::~GroupPane()` non-deleting destructor. |
| `0x0056c630-0x0056c6bf` | IDA/Ghidra modeled, vtable slot | `GroupPane::RefreshGroupListDisplayArea()` high-probability role name. |
| `0x0056c6c0-0x0056c731` | IDA/Ghidra modeled, vtable slot | `GroupPane::OnPaint()`, draws `GROUP.EPF`. |
| `0x0056c740-0x0056c745` | IDA/Ghidra modeled, vtable slot | `GroupPane` tiny false/default virtual stub. |
| `0x0056c750-0x0056c755` | IDA/Ghidra modeled, vtable slot | `GroupPane` tiny false/default virtual stub. |
| `0x0056c760-0x0056c765` | IDA/Ghidra modeled, vtable slot | `GroupPane` tiny false/default virtual stub; omitted by the current target summary. |
| `0x0056c770-0x0056c861` | IDA/Ghidra modeled | `GroupPane2::GroupPane2()` constructor. |
| `0x0056c870-0x0056c8dc` | IDA/Ghidra modeled | `GroupPane2::~GroupPane2()` non-deleting destructor. |
| `0x0056c8e0-0x0056c96f` | IDA/Ghidra modeled, vtable slot | `GroupPane2::RefreshGroupListDisplayArea()` high-probability role name. |
| `0x0056c970-0x0056c9e1` | IDA/Ghidra modeled, vtable slot | `GroupPane2::DrawTabBackground()` / `OnPaint()`; draws `GROUP.EPF` with tab/background path. |
| `0x0056c9f0-0x0056c9f5` | IDA/Ghidra modeled, vtable slot | `GroupPane2` tiny false/default virtual stub. |
| `0x0056ca00-0x0056ca05` | IDA/Ghidra modeled, vtable slot | `GroupPane2` tiny false/default virtual stub. |
| `0x0056ca10-0x0056ca15` | IDA/Ghidra modeled, vtable slot | `GroupPane2` tiny false/default virtual stub; omitted by the current target summary. |
| `0x0056ca20-0x0056caeb` | IDA/Ghidra modeled, caller from `GeneralPurposePanel` | `NewGroupPane::NewGroupPane()` constructor. |
| `0x0056caf0-0x0056cb73` | IDA/Ghidra modeled | `NewGroupPane::~NewGroupPane()` non-deleting destructor; omitted by the current target summary. |
| `0x0056cb80-0x0056cbe6` | IDA/Ghidra modeled, vtable slot | `NewGroupPane::RequestGroupList()`, sends group-list request opcode `0x2d`, subcommand `1`. |
| `0x0056cbf0-0x0056cc78` | IDA/Ghidra modeled, vtable slot | `NewGroupPane::OnLayout(...)`, positions scrollbar and updates range. |
| `0x0056cc80-0x0056cd25` | IDA/Ghidra modeled, vtable slot | `NewGroupPane::OnActivate(...)` / bounds update for normal vs expanded view. |
| `0x0056cd30-0x0056ce4b` | IDA/Ghidra modeled, ten callers | `NewGroupPane::UpdateScrollRange()`. |
| `0x0056ce50-0x0056da03` | IDA/Ghidra modeled, vtable slot | `NewGroupPane::OnPaint()`, draws background, rows, member sprites, names, HP/MP bars, percent overlays, and toggle button. |
| `0x0056da10-0x0056daf7` | IDA/Ghidra modeled, vtable slot | `NewGroupPane::OnKeyPress(...)` / key event handler for page up/down and `f` toggle. |
| `0x0056db00-0x0056dd46` | IDA/Ghidra modeled, vtable slot | `NewGroupPane::OnMouseEvent(...)`, handles hover/click/wheel and forwards to scrollbar child. |
| `0x0056dd50-0x0056def6` | IDA/Ghidra modeled, vtable slot | `NewGroupPane::HandleGroupPacket(...)`, dispatches packet `'c'` subtype `2` full list and subtype `3` status update. |
| `0x0056df00-0x0056df38` | IDA/Ghidra modeled, scrollbar callback caller | `NewGroupPane::SetScrollPosition(int orientation, short oldPos, short newPos)`. |
| `0x0056df40-0x0056dfa6` | IDA/Ghidra modeled, vtable slot | `NewGroupPane::OnOpen(...)` / attach lifecycle. |
| `0x0056dfb0-0x0056dfc6` | IDA/Ghidra modeled, vtable slot | `NewGroupPane::OnClose()` / detach lifecycle. |
| `0x0056dfd0-0x0056e027` | IDA/Ghidra modeled, direct caller from `0x0056db00` | `NewGroupPane::GetToggleButtonRect(short part, RectBounds *out)` or file-local equivalent. |
| `0x0056e030-0x0056e086` | Ghidra modeled only, IDA null | Raw no-route `GetGroupMemberRowRect(unsigned short row, RectBounds *out)` candidate. |
| `0x0056e090-0x0056e126` | Ghidra modeled only, IDA null | Raw no-route `HitTestGroupMemberRow(int y, int x)` candidate. |
| `0x0056e130-0x0056e565` | IDA/Ghidra modeled, caller from `0x0056dd50` | `NewGroupPane::ParseGroupListPacket(const unsigned char *payload)`. |
| `0x0056e570-0x0056e6c1` | Ghidra modeled only, IDA null | Raw no-route `UpdateGroupMemberStatus(const unsigned char *payload)` candidate; duplicates live subtype-3 handling. |
| `0x0056e6d0-0x0056e813` | IDA/Ghidra modeled | `NewGroupPane::DrawNumberString(const wchar_t *text, int x, int y, int fontSet)`. |
| `0x0056e820-0x0056e8b4` | Ghidra modeled only, IDA null | Raw no-route toggle-button hit-test helper candidate; omitted from current docs. |
| `0x0056e8c0-0x0056e939` | IDA/Ghidra modeled, callers from key/mouse handlers | `NewGroupPane::ToggleExpandedMode()`. |

Byte-checked raw-helper and padding boundaries from the local PE:

| Range | PE evidence |
| --- | --- |
| `0x0056e027-0x0056e030` | nine `0xcc` bytes after `GetToggleButtonRect`. |
| `0x0056e030-0x0056e086` | complete raw prologue/body/epilogue for row rectangle helper; two `ret 8` exits. |
| `0x0056e086-0x0056e090` | ten `0xcc` bytes before row hit-test helper. |
| `0x0056e090-0x0056e126` | complete raw prologue/body/epilogue for row hit-test helper; two `ret 8` exits. |
| `0x0056e126-0x0056e130` | ten `0xcc` bytes before `ParseGroupListPacket`. |
| `0x0056e565-0x0056e570` | eleven `0xcc` bytes before raw status/update helper. |
| `0x0056e570-0x0056e6c1` | complete raw helper ending after the range-check-failure call path. |
| `0x0056e6c1-0x0056e6d0` | fifteen `0xcc` bytes before `DrawNumberString`. |
| `0x0056e813-0x0056e820` | thirteen `0xcc` bytes before omitted raw toggle hit-test helper. |
| `0x0056e820-0x0056e8b4` | complete raw toggle hit-test helper; returns `6` for the toggle rect or `-1`. |
| `0x0056e8b4-0x0056e8c0` | twelve `0xcc` bytes before `ToggleExpandedMode`. |
| `0x0056e939-0x0056e940` | seven `0xcc` bytes before successor `CollectionPane`. |

## Heuristic / Inference Reanalysis And Validation

Compiler/generated names:

- `sub_56C4C0`, `sub_56C770`, `sub_56CA20`, and neighboring `virt_meth_*`/`meth_*` names are tool names, not source names. The source-facing class names are backed by RTTI/vtable pages: `GroupPane`, `GroupPane2`, and `NewGroupPane`.
- [UID:0001HM][GroupPaneAdjustorThunks](../../../by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md) is compiler-generated multiple-inheritance destructor adjustor glue. It should remain non-emitting; source should express the class layout/destructors and let the compiler generate thunks.
- Scalar deleting destructors at `0x005733e0`, `0x00573490`, and `0x00573570` are outside this target. The non-deleting destructor bodies inside this target at `0x0056c5c0`, `0x0056c870`, and `0x0056caf0` are source-owned cleanup methods.
- The tiny five-byte stubs in `GroupPane` and `GroupPane2` vtables are source-authored trivial virtual defaults, but exact virtual names remain unresolved. They should be split and documented as vtable-only stubs, not used as an excuse to keep the broad aggregate emitting.

Raw helper roles and reachability:

| Start | Evidence checked | Best inference | Rejected alternatives | Impact |
| --- | --- | --- | --- | --- |
| `0x0056e030` | Ghidra export names it `FUN_0056e030`, size `0x56`, signature `__stdcall(row, outRect)`, callees only `0x004b7c50`; local PE shows exact half-open body `0x0056e030-0x0056e086`; exported callers are zero; IDA fields are null; vtable/global/doc search found no route; PE VA-literal scan found zero hits. | Private/static retained row rectangle helper, source-shaped as `GetGroupMemberRowRect(unsigned short row, RectBounds *out)`. Valid rows `0..5` use `(6, row * 40 + 14, 161, row * 40 + 62)`; invalid rows write `(-1,-1,-1,-1)`. | Live public/helper called from vtable: rejected by no vtable refs, no callers, no VA literal, no data-route hit. Method on `NewGroupPane`: rejected because calling convention is `__stdcall` and no `this` is read. Pure padding/data: rejected by prologue, calls, and return shape. | Create exact raw child if splitting, but keep child C++ blank until a caller/source-use route is found. Parent confidence rises because boundary is now corrected. |
| `0x0056e090` | Ghidra export names it `FUN_0056e090`, size `0x96`, signature `__stdcall(y,x)`, callees `0x004b7c50`, `0x004b7e80`, security cookie; local PE shows half-open body `0x0056e090-0x0056e126`; exported callers zero; IDA fields null; vtable/global/doc search found no route; PE VA-literal scan zero. | Private/static retained row hit-test helper, source-shaped as `HitTestGroupMemberRow(int y, int x)`. It tests the six row rectangles and returns matching row or `-1`. | Live `OnMouseEvent` route: rejected because `0x0056db00` does not call it and instead has separate toggle/scroll logic. Scrollbar helper: rejected because geometry is member-row `(6..161, 14+40n..62+40n)`, not scrollbar parts. | Split as raw no-route child; no formal C++ until route/name proof. |
| `0x0056e570` | Ghidra export names it `NewGroupPane::meth_0x56e570`, size `0x151`; callees include packet readers, `MultiByteToWideChar`, `MapPane::meth_0x50e4c0`, `UpdateScrollRange`, security cookie, and range-check failure; exported callers zero; IDA fields null; target docs already reported `xrefs_to` empty; PE VA-literal scan zero. | Retained/private helper for subtype-3 group member status update, source-shaped as `NewGroupPane::UpdateGroupMemberStatus(const unsigned char *payload)` or file-local `UpdateGroupMemberStatus(NewGroupPane *, const unsigned char *)`. It decodes id, ANSI name length/name, current HP, current MP, updates matching cached entry at `+0x338/+0x340`, refreshes map marker, updates scroll range, and invalidates. | Public live helper: rejected by no callers or pointers. Current dispatch target: rejected because live `0x0056dd50` inlines the same subtype-3 logic. Parser full-entry helper: rejected because it updates only current HP/MP, not full appearance fields. | Keep as raw no-route child. Do not enter C++ in the aggregate or class page until a source-use route is found; note duplicate/inlined relationship. |
| `0x0056e820` | Newly found in Ghidra `master_function_list` and `functions/0x0056e820.json`, size `0x94`; local PE shows body `0x0056e820-0x0056e8b4`, with padding `0x0056e813-0x0056e820` and `0x0056e8b4-0x0056e8c0`; callees `0x004b7c50`, `0x004b7e80`, security cookie; exported callers zero; no docs/vtables/globals refs; PE VA-literal scan zero. | Private/static retained toggle hit-test helper. It loops indices `0..6`, creates valid rect only for part `6` as `(168,37,185,54)`, returns `6` on hit, otherwise `-1`. Source-shaped as `HitTestToggleButton(int y, int x)` or `HitTestGroupPaneButton(int y, int x)`. | Padding between `DrawNumberString` and `ToggleExpandedMode`: rejected by full prologue, stack cookie, `InitRectBounds`, `PointInRect`, and two `ret 8` exits. Active called helper: rejected by no callers/pointers and by `OnMouseEvent` inlining equivalent logic around `0x0056db00`. | Current target docs are incomplete. Add raw no-route child and padding evidence; aggregate must not emit C++. |

Rectangle helper validation:

- `0x004b7c50` is the shared `InitRectBounds` / `SetLTRB` helper. It writes `left`, `top`, `right`, `bottom` to the four dwords documented by [UID:0001VP][RectBoundsLayout](../../../by-type/by-struct/RectBoundsLayout.md).
- `0x004b7e80` is the shared `PointInRect_4B7E80` predicate. Argument order is effectively `y, x, rect`; it tests `left <= x < right` and `top <= y < bottom`.
- The raw helpers should use `RectBounds`/`RectBoundsLayout`, not a target-specific rectangle type.

Field, type, protocol, and layout inference:

- `NewGroupPane +0xfc` is the first visible row / scroll offset byte. It is reset in `RequestGroupList`, read by `OnPaint`, clamped by `UpdateScrollRange`, and updated by keyboard, mouse-wheel, and scrollbar callback paths.
- `NewGroupPane +0xfd` is the cached group-member count byte. It mirrors `*(dword_67A748 + 0x3cb0)` and drives loops in `ParseGroupListPacket`, `HandleGroupPacket`, and painting.
- `NewGroupPane +0x100` is `ScrollNewGroupPane *m_scrollPane`. The constructor allocates it via `0x00560900`, calls `Show`, layout moves it to `(right-20, top+60, right-7, bottom-18)`, and the destructor calls its scalar deleting destructor with flag `1`.
- `NewGroupPane +0x104` is the loaded number-font/glyph buffer from `9X11FONT.BIN`; `DrawNumberString` indexes glyph cells by digit/punctuation and font set.
- `NewGroupPane +0x108` is the toggle-button visual state, with observed values `0`, `1`, and `2`; `OnMouseEvent` sets hover/pressed state, `ToggleExpandedMode` forces `2`, and `OnPaint` selects `INVENBUT.EPF` frame `7 * state + 3/4`.
- `NewGroupPane +0x10c` is the expanded/collapsed mode byte. It chooses normal six-row versus expanded twelve-row behavior, changes activation bounds, shifts first expanded row art by `+5`, and changes toggle art frame.
- `GroupPane` and `GroupPane2 +0xf8` are `GroupListPane *m_groupListPane`; both constructors allocate a `0x174` child, install `GroupListPane` vtables at `+0x00/+0xa0/+0xa4`, enable it, and position/sync it.

Group packet and cached-entry layout:

- `RequestGroupList` sends opcode `0x2d` with subcommand `1`.
- `HandleGroupPacket` accepts payloads whose first byte is `99` / `'c'`.
- Subtype `2` dispatches `payload + 2` to `ParseGroupListPacket`.
- Subtype `3` decodes one member id, a length-prefixed ANSI name, current HP, and current MP; it searches cached members by id and writes current HP to entry `+0x338` and current MP to entry `+0x340`.
- Full list count is read from the first byte of the subtype-2 payload and stored to both `dword_67A748 + 0x3cb0` and `NewGroupPane +0xfd`.
- Cached group entries begin at `dword_67A748 + 0x218`, with stride `0x12c` / 300 bytes.

High-probability cached member entry fields:

| Offset from `dword_67A748` entry base | Inference | Evidence |
| --- | --- | --- |
| `+0x218` | `uint32 memberId` / linked object id | Parsed by `sub_5754C0`; map marker helpers receive this id; subtype-3 update searches this field. |
| `+0x21c` | `wchar_t name[128]` | Full parser converts length-prefixed ANSI bytes through `MultiByteToWideChar` into this field; paint draws this wide string twice with small offsets. |
| `+0x31c` | online/active flag | Full parser stores boolean; paint chooses color `12` for true and `143` for false. |
| `+0x31e` through `+0x332` | appearance descriptor fields | Full parser reads a compact sequence of words/bytes; paint copies these values into the object-image descriptor passed to `0x004e09e0` and `0x004e06a0`. Exact source names such as head/body/armor/hair/weapon should remain role-based until matched to a shared avatar descriptor. |
| `+0x334` | max HP | Paint uses it as the denominator for the first bar. |
| `+0x338` | current HP | Full parser initializes it; subtype-3 update overwrites it; paint uses it as numerator for HP percent. |
| `+0x33c` | max MP | Paint uses it as the denominator for the second bar. |
| `+0x340` | current MP | Full parser initializes it; subtype-3 update overwrites it; paint uses it as numerator for MP percent. |

Map-marker interactions:

- When the new full-list count is smaller than the old count, `ParseGroupListPacket` loops old cached entries and calls `0x0050e810` / `MapPaneActivateLinkedObjectById` for each old member id, matching the clear/remove marker role.
- For each parsed member in a full list, `ParseGroupListPacket` calls `0x0050e4c0` / `MapPaneProcessMapEvent` with that member id.
- The subtype-3 update path in `HandleGroupPacket` also calls `0x0050e4c0` for the updated id after writing HP/MP.
- [UID:0001KR][GroupMemberMarkers](../../../by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md) independently confirms the same group-member count at `+0x3cb0`, id offset `+0x218`, stride `0x12c`, and downstream map helper pair.

Caller/reachability validation:

- `NewGroupPane::NewGroupPane` at `0x0056ca20` has a direct constructor call from `GeneralPurposePanel` at `0x004b84f5`.
- `ParseGroupListPacket` at `0x0056e130` has a direct caller from `HandleGroupPacket` at `0x0056dd84`.
- `ToggleExpandedMode` at `0x0056e8c0` has direct callers from key and mouse handlers at `0x0056dade` and `0x0056dc47`.
- `GetToggleButtonRect` at `0x0056dfd0` has a direct caller from `OnMouseEvent` at `0x0056dced`.
- `UpdateScrollRange` at `0x0056cd30` is heavily live: callers include layout, key, mouse, packet, scroll callback, open lifecycle, raw status helper, parser, and toggle paths.
- Raw starts `0x0056e030`, `0x0056e090`, `0x0056e570`, and `0x0056e820` have no exported callers, no IDA xrefs in the export cache, no vtable/global search hits, no documentation route except current target references for the first three, and no absolute VA literal hits in the local PE.

Boundary validation:

- The predecessor [UID:00023W] is `LegendPane`, not group-pane source content. The target should start at `0x0056c4c0`; the `0x0056c4b5-0x0056c4c0` padding row remains outside this target.
- [UID:0001H8] `GroupListPaneRawConstructor`, [UID:0001H9] `GroupListPaneVirtualStubs`, and [UID:0001HA] `SpelledPane` remain separate. Do not merge the `0x0056baa0` constructor island into [UID:0001HC].
- [UID:0001GP]/[UID:0001GQ]/[UID:0001GR]/[UID:0001GS] remain `ScrollNewGroupPane` child pages. They validate the `+0x100` scroll child and callback, but should not be merged into [UID:0001HC].
- [UID:0001HM] adjustor thunks and scalar deleting destructor islands are compiler/destructor support outside this target. They are evidence for vtable/class layout, not child source inside the target.
- [UID:0002NJ]/[UID:0002NK]/[UID:0002NL] validate exact vtable data for `GroupPane`, `GroupPane2`, and `NewGroupPane`. Their slot evidence supports splitting the current executable aggregate by class/method.
- The successor [UID:0001HD] `CollectionPane` begins at `0x0056e940`; local PE and current docs agree that `0x0056e939-0x0056e940` is seven bytes of `0xcc` padding.

Generated-output and final-C++ issues:

- Current generated coverage still treats [UID:0001HC] as `emits` through `auto-generated/NexusTK/social/Group.cpp`. That is stale for the broad target. Regenerated output should see this page as `not_reconstructable` / split-index after supervisor changes.
- The current target average is over 85, but the code-entry gate is satisfied only numerically. Structurally, the page is a mixed class/index container. Formal C++ here would be misleading and would duplicate future child method output.
- Exact child pages can later receive C++ when their own helper names, field names, and source-level declarations clear the final-source gate. The aggregate should stay blank.

## Open Questions Resolved Or Remaining

Resolved:

- `GroupPane`, `GroupPane2`, and `NewGroupPane` all belong under the [UID:0000JS][Group](../../../by-file/Group.md) source root.
- [UID:0001HC] should not remain a code-emitting aggregate. It should become a non-emitting split/index.
- The predecessor `0x0056c4a0-0x0056c4b5` stubs are `LegendPane`, not GroupPanes source content.
- `GroupPane` and `GroupPane2` both inline the same `GroupListPane` child construction at `+0xf8`; the standalone raw constructor remains [UID:0001H8], not part of this target.
- `NewGroupPane +0xfc`, `+0xfd`, `+0x100`, `+0x104`, `+0x108`, and `+0x10c` have defensible role names.
- Full-list and subtype-3 packet semantics are resolved at protocol/field level.
- HP/MP fields are resolved as `+0x334 maxHp`, `+0x338 currentHp`, `+0x33c maxMp`, and `+0x340 currentMp`.
- Raw no-route helper starts at `0x0056e030`, `0x0056e090`, and `0x0056e570` remain source-shaped but unreferenced; the correct strategy is private/no-route child documentation, not public/helper promotion.
- A fourth raw helper start at `0x0056e820` exists and should be added to the target docs and eventual split plan.
- The current raw endpoint text for `0x0056e030` and `0x0056e090` is stale by three bytes under half-open range convention.

Remaining, with impact:

- Exact original names for `GroupPane` and `GroupPane2` tiny false/default virtual stubs are still not defensible. Impact: child stub pages should remain role-named and C++-blank or use conservative trivial virtual notes; parent owner/source placement is unaffected.
- Exact source names for `NewGroupPane::OnLayout`, `OnActivate`, `OnOpen`, `OnClose`, `OnKeyPress`, and `OnMouseEvent` are high-probability role names but not original-symbol proof. Impact: acceptable for support docs and child page titles, but keep child formal C++ conservative until declarations are stable.
- Appearance descriptor field names in the cached group entry are not fully resolved beyond their use as avatar/object-image descriptor fields. Impact: do not emit final C++ struct declarations with specific equipment/body-part names yet.
- Raw no-route helpers `0x0056e030`, `0x0056e090`, `0x0056e570`, and `0x0056e820` have no current caller/table/source-use route. Impact: keep their completion below final-source C++ quality and do not place them in formal aggregate C++.
- Live IDA/MCP was unavailable during this pass. I used exported IDA/Ghidra data and local PE byte checks. Impact: confidence cap at `90`; supervisor can raise later if a fresh IDA live pass reconfirms all raw helper xrefs/bytes.

## First-Draft C++ Recommendation

Do not populate formal C++ for [UID:0001HC].

Target-specific no-code proof:

- The target range is not a source function and not a single class body. It contains at least three classes with distinct RTTI/vtable data: `GroupPane`, `GroupPane2`, and `NewGroupPane`.
- The range also contains vtable-only tiny stubs, a modeled non-deleting destructor omitted from current docs, several raw no-route static/private helper bodies, and internal alignment.
- Any single C++ block under [UID:0001HC] would either combine unrelated class methods into one artificial file-scope body or duplicate source that should be emitted by future exact child pages/classes.
- The newly discovered `0x0056e820` raw body and the corrected `0x0056e030`/`0x0056e090` half-open endpoints prove the current aggregate is still a physical coverage container, not a final source unit.
- By-structure practice in the already corrected [UID:0001HD][CollectionPane](../../../by-memory/0x0056e940-0x0056fe75.CollectionPane.md) range supports this disposition: broad mixed executable islands become non-emitting split indexes, and exact method children carry future source bodies.

Formal C++ should instead be considered later for exact child pages, starting with lower-risk modeled children such as:

- `GroupPane::GroupPane()`, `GroupPane::~GroupPane()`, `GroupPane::RefreshGroupListDisplayArea()`, and `GroupPane::OnPaint()`.
- `GroupPane2::GroupPane2()`, `GroupPane2::~GroupPane2()`, `GroupPane2::RefreshGroupListDisplayArea()`, and `GroupPane2::DrawTabBackground()/OnPaint()`.
- `NewGroupPane::RequestGroupList()`, `NewGroupPane::UpdateScrollRange()`, `NewGroupPane::SetScrollPosition(int, short, short)`, `NewGroupPane::ParseGroupListPacket(const unsigned char *)`, `NewGroupPane::DrawNumberString(const wchar_t *, int, int, int)`, and `NewGroupPane::ToggleExpandedMode()`.

Raw no-route helpers should not receive formal C++ until a caller/source-use route is found.

## Exact Supervisor Changes Required

Target metadata header replacement for [UID:0001HC]:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the current [UID:0001HC] `## Status` bullets with:

```markdown
- Disposition: non-emitting split/index over exact `GroupPane`, `GroupPane2`, and `NewGroupPane` executable method children.
- Entity kind: mixed physical executable island, not a single source function or class body.
- Covered owners: `GroupPane`, `GroupPane2`, `NewGroupPane`, and private/static raw helper bodies associated with `NewGroupPane`.
- Likely source module: [UID:0000JS][Group](by-file/Group.md), proposed path `NexusTK/social/Group.cpp`.
- Autogen status: do not emit from this aggregate. Exact child method/class pages should carry any future C++.
- Confidence: strong for class ownership, exact modeled function map, vtable-data children, destructor/thunk boundaries, packet/list behavior, scroll-child relationship, map-marker side effects, raw helper byte shapes, and parent routing; medium-high for exact original helper/stub names.
- C++ status: intentionally blank. This range spans multiple classes plus no-route raw helpers and should remain a split/index.
```

Replace the current [UID:0001HC] `## Score Rationale` table with:

```markdown
| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 88 | The page has source-owner routing, exact class/vtable/destructor support, a current modeled function map, corrected raw helper half-open ranges, an omitted raw helper at `0x0056e820`, packet/list-entry semantics, member field roles, scroll-child relationships, and map-marker side effects. It is not higher because exact child pages and source-quality child C++ are still pending. |
| Confidence | 90 | Exported IDA/Ghidra data, existing live-IDa-backed support docs, vtable pages, local PE byte checks, and pointer/text searches agree on ownership and boundaries. Confidence is capped because the live IDA/MCP endpoint was unavailable for this pass and exact original source spellings for tiny stubs/raw helpers remain unresolved. |
| Reconstructable | FALSE | The bytes are project code, but this broad page is a mixed physical executable island and should not emit C++. Exact child pages should carry reconstructable source bodies. |
```

Replace the current [UID:0001HC] `## Covered Ranges` table with:

```markdown
| Range | Current method or group | Notes |
| --- | --- | --- |
| `0x0056c4c0-0x0056c765` | `GroupPane` modeled methods and vtable-only stubs | Constructor, non-deleting destructor, list-child refresh, paint, and three tiny false/default virtual stubs. |
| `0x0056c770-0x0056ca15` | `GroupPane2` modeled methods and vtable-only stubs | Constructor, non-deleting destructor, list-child refresh, tab/background paint, and three tiny false/default virtual stubs. |
| `0x0056ca20-0x0056e027` | `NewGroupPane` modeled setup/input/layout/lifecycle methods | Constructor, non-deleting destructor, request, layout, activation, scroll range, paint, key/mouse input, packet handler, scroll callback, open/close, and toggle-rect helper. |
| `0x0056e030-0x0056e086` | raw `NewGroupPane` row rectangle helper | Ghidra-modeled/IDA-unmodeled source-shaped helper; writes one of six fixed member-row rectangles or invalid `-1` bounds. No caller/pointer route found. |
| `0x0056e090-0x0056e126` | raw `NewGroupPane` row hit-test helper | Ghidra-modeled/IDA-unmodeled source-shaped helper; tests rows `0..5` through `PointInRect_4B7E80` and returns row or `-1`. No caller/pointer route found. |
| `0x0056e130-0x0056e565` | `NewGroupPane::ParseGroupListPacket` | Parses subtype-2 full group list, updates cached members, refreshes map markers, scroll range, and repaint. |
| `0x0056e570-0x0056e6c1` | raw `NewGroupPane` member status/update helper | Ghidra-modeled/IDA-unmodeled source-shaped subtype-3 helper candidate; no caller/pointer route found, and live `0x0056dd50` inlines equivalent logic. |
| `0x0056e6d0-0x0056e813` | `NewGroupPane::DrawNumberString` | Draws percent/digit punctuation overlays from `9X11FONT.BIN` and shared comma/punctuation art. |
| `0x0056e820-0x0056e8b4` | raw `NewGroupPane` toggle-button hit-test helper | Newly documented Ghidra-modeled/IDA-unmodeled source-shaped helper; tests only part `6` at `(168,37,185,54)` and returns `6` or `-1`. No caller/pointer route found. |
| `0x0056e8c0-0x0056e939` | `NewGroupPane::ToggleExpandedMode` | Toggles expanded/collapsed state, relayouts, updates scroll range, and invalidates. |
```

Add a raw-padding note below the covered range table:

```markdown
Local PE byte checks confirm `0x0056e027-0x0056e030`, `0x0056e086-0x0056e090`, `0x0056e126-0x0056e130`, `0x0056e565-0x0056e570`, `0x0056e6c1-0x0056e6d0`, `0x0056e813-0x0056e820`, `0x0056e8b4-0x0056e8c0`, and `0x0056e939-0x0056e940` are `0xcc` alignment. The first and last of those are already represented by neighboring ignored rows; internal alignment should be split to ignored rows if exact child pages are created.
```

Exact child split recommendation if the supervisor creates child pages:

| Proposed child title | Range | Direct owner/emitter route | Score recommendation |
| --- | --- | --- | --- |
| `GroupPaneConstructor` | `0x0056c4c0-0x0056c5b1` | `00005Y` -> `0000JS` | `87/90` |
| `GroupPaneNonDeletingDestructor` | `0x0056c5c0-0x0056c62c` | `00005Y` -> `0000JS` | `86/90` |
| `GroupPaneRefreshGroupListDisplayArea` | `0x0056c630-0x0056c6bf` | `00005Y` -> `0000JS` | `86/89` |
| `GroupPaneOnPaint` | `0x0056c6c0-0x0056c731` | `00005Y` -> `0000JS` | `86/89` |
| `GroupPaneVirtualStubs` | `0x0056c740-0x0056c765` | `00005Y` -> `0000JS` | `85/89` |
| `GroupPane2Constructor` | `0x0056c770-0x0056c861` | `00005Z` -> `0000JS` | `87/90` |
| `GroupPane2NonDeletingDestructor` | `0x0056c870-0x0056c8dc` | `00005Z` -> `0000JS` | `86/90` |
| `GroupPane2RefreshGroupListDisplayArea` | `0x0056c8e0-0x0056c96f` | `00005Z` -> `0000JS` | `86/89` |
| `GroupPane2DrawTabBackground` | `0x0056c970-0x0056c9e1` | `00005Z` -> `0000JS` | `86/89` |
| `GroupPane2VirtualStubs` | `0x0056c9f0-0x0056ca15` | `00005Z` -> `0000JS` | `85/89` |
| `NewGroupPaneConstructor` | `0x0056ca20-0x0056caeb` | `000090` -> `0000JS` | `87/90` |
| `NewGroupPaneNonDeletingDestructor` | `0x0056caf0-0x0056cb73` | `000090` -> `0000JS` | `86/90` |
| `NewGroupPaneRequestGroupList` | `0x0056cb80-0x0056cbe6` | `000090` -> `0000JS` | `87/90` |
| `NewGroupPaneOnLayout` | `0x0056cbf0-0x0056cc78` | `000090` -> `0000JS` | `86/89` |
| `NewGroupPaneUpdateActiveBounds` | `0x0056cc80-0x0056cd25` | `000090` -> `0000JS` | `85/88` |
| `NewGroupPaneUpdateScrollRange` | `0x0056cd30-0x0056ce4b` | `000090` -> `0000JS` | `88/90` |
| `NewGroupPaneOnPaint` | `0x0056ce50-0x0056da03` | `000090` -> `0000JS` | `86/89` |
| `NewGroupPaneOnKeyPress` | `0x0056da10-0x0056daf7` | `000090` -> `0000JS` | `86/89` |
| `NewGroupPaneOnMouseEvent` | `0x0056db00-0x0056dd46` | `000090` -> `0000JS` | `86/89` |
| `NewGroupPaneHandleGroupPacket` | `0x0056dd50-0x0056def6` | `000090` -> `0000JS` | `88/90` |
| `NewGroupPaneSetScrollPosition` | `0x0056df00-0x0056df38` | `000090` -> `0000JS` | `87/90` |
| `NewGroupPaneOnOpen` | `0x0056df40-0x0056dfa6` | `000090` -> `0000JS` | `85/88` |
| `NewGroupPaneOnClose` | `0x0056dfb0-0x0056dfc6` | `000090` -> `0000JS` | `85/88` |
| `NewGroupPaneGetToggleButtonRect` | `0x0056dfd0-0x0056e027` | `000090` -> `0000JS` | `87/90` |
| `NewGroupPaneRowRectRawHelper` | `0x0056e030-0x0056e086` | `000090` -> `0000JS` | `84/89` |
| `NewGroupPaneRowHitTestRawHelper` | `0x0056e090-0x0056e126` | `000090` -> `0000JS` | `84/89` |
| `NewGroupPaneParseGroupListPacket` | `0x0056e130-0x0056e565` | `000090` -> `0000JS` | `88/91` |
| `NewGroupPaneUpdateGroupMemberStatusRawHelper` | `0x0056e570-0x0056e6c1` | `000090` -> `0000JS` | `84/89` |
| `NewGroupPaneDrawNumberString` | `0x0056e6d0-0x0056e813` | `000090` -> `0000JS` | `87/90` |
| `NewGroupPaneToggleButtonHitTestRawHelper` | `0x0056e820-0x0056e8b4` | `000090` -> `0000JS` | `84/89` |
| `NewGroupPaneToggleExpandedMode` | `0x0056e8c0-0x0056e939` | `000090` -> `0000JS` | `87/90` |

Support doc changes:

1. [UID:0000JS][Group](../../../by-file/Group.md)
   - In `## Proposed Contents`, replace the row:
     ```markdown
     | `GroupPane`/`GroupPane2` false virtual stubs | `0x0056c4a0-0x0056c4b5` | shared local stubs | Two tiny `return false` virtual/default stubs immediately before the `GroupPane` constructors. |
     ```
     with:
     ```markdown
     | `LegendPane` boundary false virtual stubs | `0x0056c4a0-0x0056c4b5` | boundary context only | Two tiny `LegendPane` `return false` vtable targets immediately before the `GroupPane` constructor range; keep them in [UID:00023W] and do not treat them as `Group.cpp` source content. |
     ```
   - In `## Boundary And Data Notes`, replace the bullet saying "keep those with the group pane family" with:
     ```markdown
     - 2026-06-15 live IDA route correction identifies `0x0056c4a0-0x0056c4b5` as `LegendPane` vtable targets. They are useful predecessor-boundary context for `GroupPane`, but they should not be emitted from `Group.cpp`.
     ```
   - Add a boundary/data bullet:
     ```markdown
     - B001 2026-06-18 source-quality reanalysis found a fourth raw NewGroupPane helper at `0x0056e820-0x0056e8b4`: it hit-tests only the toggle-button part `6` rectangle `(168,37,185,54)`, has no known callers or pointer refs, and should be tracked with the other no-route raw helpers.
     ```

2. [UID:000090][NewGroupPane](../../../by-class/NewGroupPane.md)
   - Insert after the constructor row in `## Method Notes`:
     ```markdown
     | `~NewGroupPane` | `0x0056caf0-0x0056cb73` | Non-deleting destructor; deletes the `ScrollNewGroupPane` child at `+0x100`, releases the number-font data at `+0x104`, reinstalls vtables, and calls the `PanelPane` destructor. |
     ```
   - Insert before `ParseGroupListPacket`:
     ```markdown
     | raw row rect helper | `0x0056e030-0x0056e086` | Ghidra-modeled/IDA-unmodeled no-route helper; writes six fixed member-row rectangles or invalid bounds. |
     | raw row hit-test helper | `0x0056e090-0x0056e126` | Ghidra-modeled/IDA-unmodeled no-route helper; tests rows `0..5` through `PointInRect_4B7E80` and returns row or `-1`. |
     ```
   - Insert after `DrawNumberString`:
     ```markdown
     | raw toggle hit-test helper | `0x0056e820-0x0056e8b4` | Ghidra-modeled/IDA-unmodeled no-route helper; tests only toggle part `6` at `(168,37,185,54)` and returns `6` or `-1`. |
     ```
   - Replace the raw entry update row with:
     ```markdown
     | raw entry update helper | `0x0056e570-0x0056e6c1` | Ghidra-modeled/IDA-unmodeled no-route helper; decodes subtype-3-style member id/name/current HP/current MP, updates cached fields `+0x338/+0x340`, refreshes the map marker, updates scroll range, and invalidates. Live `HandleGroupPacket` currently inlines equivalent subtype-3 logic, so this should stay a private/raw helper until a caller or source-use route is found. |
     ```

3. [UID:00005Y][GroupPane](../../../by-class/GroupPane.md)
   - Replace the method-note row for `false/default virtual stub` with:
     ```markdown
     | predecessor boundary stubs | `0x0056c4a0-0x0056c4b5` | Boundary context only: live IDA routes these two false-return stubs to `LegendPane`, not `GroupPane`; keep them in [UID:00023W]. |
     ```

4. [UID:00005Z][GroupPane2](../../../by-class/GroupPane2.md)
   - Replace the method-note row for `false/default virtual stub` with:
     ```markdown
     | predecessor boundary stubs | `0x0056c4a0-0x0056c4b5` | Boundary context only: live IDA routes these two false-return stubs to `LegendPane`, not `GroupPane2`; keep them in [UID:00023W]. |
     ```
   - Replace the `trivial virtuals` row with:
     ```markdown
     | trivial virtuals | `0x0056c9f0-0x0056c9f5`, `0x0056ca00-0x0056ca05`, `0x0056ca10-0x0056ca15` | Small return stubs in the `GroupPane2` secondary table. |
     ```

No changes recommended for [UID:0001GP]/[UID:0001GQ]/[UID:0001GR]/[UID:0001GS] beyond ensuring [UID:0001HC] cross-references all four `ScrollNewGroupPane` child pages when refreshed.

## Coverage Report Replacement Text

Placement context in `by-memory/-coverage-report.md`: replace the current [UID:0001HC] row under the `0x0056c4b5-0x0056c4c0` padding row and before the `0x0056e939-0x0056e940` padding row.

Current row to replace:

```markdown
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md) : reconstructable : 84% : strong : Live IDA MCP maps 31 modeled group-pane functions, raw method-shaped gaps at `0x0056e030`, `0x0056e090`, and `0x0056e570`, constructor/parser caller anchors, exact padding, vtable-data children, and parent routing to `Group.cpp`; final C++ remains blank because the aggregate spans multiple classes and unresolved source split decisions.
```

Replacement row:

```markdown
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md) 0x0056c4c0-0x0056e939 | split index | GroupPane, GroupPane2, and NewGroupPane executable family index : non-reconstructable : 88% : strong : B001 2026-06-18 source-quality reanalysis converts the broad multi-class range to a non-emitting split/index under [UID:0000JS][Group]; exact child method pages should carry future C++. The pass validates GroupPane/GroupPane2/NewGroupPane ownership, vtable/destructor routes, GroupListPane and ScrollNewGroupPane boundaries, packet/list-entry and map-marker semantics, corrected raw helper ranges `0x0056e030-0x0056e086` and `0x0056e090-0x0056e126`, no-route raw helper `0x0056e570-0x0056e6c1`, newly documented no-route raw helper `0x0056e820-0x0056e8b4`, and local PE padding around the raw bodies; formal C++ remains blank because this page is a physical split/index, not a source body.
```

If the supervisor creates exact child pages now, insert child coverage rows immediately after the replacement parent row and before the existing `0x0056e939-0x0056e940` ignored-padding row, using the exact child range/title/owner/score table from `## Exact Supervisor Changes Required`. UIDs must be supervisor/validator-assigned; do not invent final UIDs in this report.

No direct edit should be made to `auto-generated/-ag-memory-coverage.md`; regenerate it after metadata and child-page changes.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001HC-GroupPanes-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001HC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
