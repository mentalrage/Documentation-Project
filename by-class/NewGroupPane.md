*** UID:000090 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// NewGroupPane method implementations are emitted by exact by-memory children.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../ui/core/PanelPane.h"

class Event;
class Layer;
class ScrollNewGroupPane;

class NewGroupPane : public PanelPane
{
public:
    NewGroupPane();
    virtual ~NewGroupPane();
    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void SetBounds(const RectBounds *bounds,
                           const RectBounds *previousBounds);
    virtual void AddToLayer(RectBounds *bounds, int order,
                            Pane *previousPane, Layer *layer);
    virtual void RemoveFromLayer();
    virtual void OnPaint();
    virtual void OnActivate(const unsigned char *packetData);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);

private:
    void UpdateScrollRange();
    void SetScrollPosition(unsigned char orientation,
                           short oldPosition, short newPosition);
    bool ParseGroupListPacket(const unsigned char *packetData);
    bool UpdateGroupMemberStatus(const unsigned char *packetData);
    void DrawNumberString(const wchar_t *text, int left, int top,
                          unsigned char colorVariant);
    void ToggleExpandedMode();

    unsigned char m_unusedState[4];
    signed char m_firstVisibleMember;
    signed char m_groupMemberCount;
    ScrollNewGroupPane *m_scrollPane;
    char *m_numericGlyphs;
    int m_toggleButtonState;
    bool m_expanded;

    [[CHILDREN]]
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewGroupPane

## Status

- Confidence: very strong for group UI ownership, exact `0x110` layout, packet/render/input behavior, all twenty-one source bodies, the UID0003F2 pooled-literal covered-by child, and the class/file emitter route. Original lexical spellings and historical translation-unit naming remain inferred.
- Likely source file: [UID:0000JS][Group](by-file/Group.md)
- Address range: [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md); exact vtable data [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md); destructor thunks at [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_NewGroupPane.cpp`
- Autogen status: attached to direct file parent [UID:0000JS][Group](by-file/Group.md), now `91/88`; formal CPP composes the twenty-one exact method/helper source children plus UID0003F2's position-75 covered-by marker, and formal H carries the complete class declaration.

## Class Purpose

`NewGroupPane` is the main party/group management pane. It requests the group member list, owns a custom scroll child, lays out normal and expanded views, renders member rows with status and HP/MP information, handles keyboard/mouse input, parses group list packets into player data, updates map markers, and toggles expanded mode.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewGroupPane` | `0x0056ca20-0x0056caeb` | Constructs panel state, loads number font data, creates `ScrollNewGroupPane`, and initializes collapsed/expanded state. Exact source: [UID:0004YZ][0x0056ca20-0x0056caeb.NewGroupPaneConstructor](by-memory/0x0056ca20-0x0056caeb.NewGroupPaneConstructor.md). |
| `~NewGroupPane` | `0x0056caf0-0x0056cb73` | Non-deleting destructor; deletes the `ScrollNewGroupPane` child at `+0x100`, releases the number-font data at `+0x104`, reinstalls vtables, and calls the `PanelPane` destructor. |
| `OnActivate(const unsigned char *packetData)` | `0x0056cb80-0x0056cbe6` | Primary `+0x48` activation override. The packet argument is unused; behavior sends group-list request opcode `0x2d`, subcommand `1`. Exact source: [UID:0004Z1][0x0056cb80-0x0056cbe6.NewGroupPaneOnActivate](by-memory/0x0056cb80-0x0056cbe6.NewGroupPaneOnActivate.md). |
| `UpdateRenderRegion(const RectBounds *bounds)` | `0x0056cbf0-0x0056cc78` | Primary `+0x0c` override; lays out the scrollbar, delegates to PanelPane, and reconciles range. Historical `OnLayout` is rejected. Exact source: [UID:0004Z2][0x0056cbf0-0x0056cc78.NewGroupPaneUpdateRenderRegion](by-memory/0x0056cbf0-0x0056cc78.NewGroupPaneUpdateRenderRegion.md). |
| `SetBounds(const RectBounds *bounds, const RectBounds *previousBounds)` | `0x0056cc80-0x0056cd25` | Primary `+0x2c` override; selects normal/expanded bounds, stores inherited origin, localizes the rectangle, and redispatches render-region update. Exact source: [UID:0004Z3][0x0056cc80-0x0056cd25.NewGroupPaneSetBounds](by-memory/0x0056cc80-0x0056cd25.NewGroupPaneSetBounds.md). |
| `UpdateScrollRange` | `0x0056cd30-0x0056ce4a` | Loads `ScrollNewGroupPane *` from `+0x100`, derives the maximum from cached member count `+0xfd` minus 6 normal or 12 expanded rows selected by `+0x10c`, calls [UID:000450][0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange](by-memory/0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange.md) `SetMaxRange` at `0x0056cda2` only when the child range differs, then clamps/applies the current position through [UID:000451][0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition](by-memory/0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition.md) at `0x0056ce39`. |
| `OnPaint` | `0x0056ce50-0x0056da02` | Draws background, member rows, names, class/status, HP/MP bars, and number strings. |
| `HandleKeyOrTextEvent(Event *event)` | `0x0056da10-0x0056daf7` | EventHandler key/text override for navigation and expanded-mode actions. Exact source: [UID:0004Z6][0x0056da10-0x0056daf7.NewGroupPaneHandleKeyOrTextEvent](by-memory/0x0056da10-0x0056daf7.NewGroupPaneHandleKeyOrTextEvent.md). |
| `HandlePointerOrMouseEvent(Event *event)` | `0x0056db00-0x0056dd46` | EventHandler pointer/mouse override; handles wheel, row/toggle interaction, and child forwarding. The wheel path signed-clamps owner state and calls UID000451 at `0x0056dbbd`. Exact source: [UID:0004Z7][0x0056db00-0x0056dd46.NewGroupPaneHandlePointerOrMouseEvent](by-memory/0x0056db00-0x0056dd46.NewGroupPaneHandlePointerOrMouseEvent.md). |
| `HandlePacketEvent(Event *event)` | `0x0056dd50-0x0056def6` | EventHandler packet override; accepts opcode `99`, dispatches subtype `2` full-list parsing, and handles subtype `3` member-status updates. Exact source: [UID:0004Z8][0x0056dd50-0x0056def6.NewGroupPaneHandlePacketEvent](by-memory/0x0056dd50-0x0056def6.NewGroupPaneHandlePacketEvent.md). |
| `SetScrollPosition` | `0x0056df00-0x0056df37` | Applies the scrollbar-owner callback; callsite `0x0056df1c` synchronizes the accepted signed position back to UID000451 before range/layout/invalidation follow-up. |
| `AddToLayer` / `RemoveFromLayer` | `0x0056df40-0x0056dfc6` | Primary layer overrides; attach/detach the pane and owned scrollbar in binary order. Exact sources: UID0004ZA and UID0004ZB. Historical `OnOpen` / `OnClose` aliases are rejected. |
| `GetGroupToggleButtonRect` | `0x0056dfd0-0x0056e027` | File-local helper returning the expanded/collapsed toggle rect. Exact source: [UID:0004ZC][0x0056dfd0-0x0056e027.GetGroupToggleButtonRect](by-memory/0x0056dfd0-0x0056e027.GetGroupToggleButtonRect.md). |
| `GetGroupMemberRowRect` | `0x0056e030-0x0056e086` | Retained file-local source helper; writes six fixed member-row rectangles or invalid bounds. Exact source: [UID:0004ZD][0x0056e030-0x0056e086.GetGroupMemberRowRect](by-memory/0x0056e030-0x0056e086.GetGroupMemberRowRect.md). |
| `HitTestGroupMemberRow` | `0x0056e090-0x0056e126` | Retained file-local source helper; tests rows `0..5` and returns row or `-1`. Exact source: [UID:0004ZE][0x0056e090-0x0056e126.HitTestGroupMemberRow](by-memory/0x0056e090-0x0056e126.HitTestGroupMemberRow.md). |
| `ParseGroupListPacket` | `0x0056e130-0x0056e565` | Parses group list packet, updates cached members, refreshes map markers, and repaints. |
| `UpdateGroupMemberStatus` | `0x0056e570-0x0056e6c1` | Retained member source helper; decodes subtype-3 member id/name/current HP/current MP, updates cached fields `+0x338/+0x340`, refreshes the marker/range, and invalidates. The live packet handler inlines equivalent logic; no caller is invented. Exact source: [UID:0004ZG][0x0056e570-0x0056e6c1.NewGroupPaneUpdateGroupMemberStatus](by-memory/0x0056e570-0x0056e6c1.NewGroupPaneUpdateGroupMemberStatus.md). |
| `DrawNumberString` | `0x0056e6d0-0x0056e813` | Draws digits and punctuation from `9X11FONT.BIN`/comma EPF assets. |
| `HitTestGroupToggleButton` | `0x0056e820-0x0056e8b4` | Retained file-local source helper; tests toggle part `6` at `(168,37,185,54)` and returns `6` or `-1`. Exact source: [UID:0004ZI][0x0056e820-0x0056e8b4.HitTestGroupToggleButton](by-memory/0x0056e820-0x0056e8b4.HitTestGroupToggleButton.md). |
| `ToggleExpandedMode` | `0x0056e8c0-0x0056e939` | Toggles expanded view and relayouts/repaints. |

## UID0003F2 Resource Literal Ownership And Route - 2026-08-15

[UID:0003F2][0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings](by-memory/0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings.md) is the exact class-owned physical literal child for [UID:0004Z5][0x0056ce50-0x0056da03.NewGroupPaneOnPaint](by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md). Its 68 bytes have SHA256 `1A235EB91D69386B623C22DA79C998C57E1BE65D661B4F0116412783FF64EAE4` and contain seven physical IDA items: `GROUPCOL.EPF`, alignment, `GROUPCOL.PAL`, alignment, the named `%d` head, unnamed `%%\0` suffix, and final alignment.

The complete reference set is confined to UID0004Z5: `0x0056d012` loads `L"GROUPCOL.EPF"`, `0x0056d04c` supplies `L"GROUPCOL.PAL"`, and `0x0056d5c6`/`0x0056d884` use the one physically split `L"%d%%"` for HP/MP percentages. The three alignment cells and format suffix have zero independent xrefs. Current source already has exactly one EPF expression, one PAL expression, and two percent-format expressions.

Canonical owner/emitter is therefore UID000090, not CollectionPane or direct-file UID0000JS. UID0003F2 enters this class's CPP child stream at position `75`, after UID0004Z5 position `70` and before UID0004Z6 position `80`, and emits only a three-line covered-by marker. It emits no data storage, paint code, or H declaration. Compiler/linker pooling accounts for the physical cells; no static constant, table, synthetic file, per-literal split, or handwritten vtable/data object is introduced. The class remains `94/95`, with all twenty-one method children and the complete H declaration unchanged.

## UID0003F6 Percentage Scale Dependency - 2026-08-15

[UID:0003F6][0x00624bd0-0x00624be0.GroupPaneScaleConstant](by-memory/0x00624bd0-0x00624be0.GroupPaneScaleConstant.md) supplies the one physical compiler-pooled `double 100.0` consumed twice by [UID:0004Z5][0x0056ce50-0x0056da03.NewGroupPaneOnPaint](by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md). The exact xrefs are `0x0056d5b8` for `currentHitPoints / maximumHitPoints * 100.0` and `0x0056d876` for `currentManaPoints / maximumManaPoints * 100.0`; both feed unsigned percentage conversion and the accepted `L"%d%%"` formatting path.

The physical UID0003F6 range is 16 bytes: the unique eight-byte literal at `[0x00624bd0,0x00624bd8)` followed by eight zero alignment bytes. It remains canonically owned/emitted by UID0000JS because it is file-local pooled evidence, while this class and UID0004Z5 are semantic consumers. The complete class H gains no member, static, constant, macro, or declaration. Existing CPP keeps both inline `100.0` expressions, and UID0003F6 contributes only a covered-by marker through Group.cpp. This dependency changes no NewGroupPane metadata, child order, source owner, formal class declaration, or method body.

## UpdateScrollRange Child Contract

`NewGroupPane::UpdateScrollRange` at `[0x0056cd30,0x0056ce4b)` is the sole direct caller of [UID:000450][0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange](by-memory/0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange.md). The caller reads the cached member count from `NewGroupPane +0xfd`, selects six visible rows in normal mode or twelve in expanded mode from flag `+0x10c`, subtracts that allowance, and clamps a negative result to zero before comparing it with the scroll child's signed range at `ScrollNewGroupPane +0x100`.

When that desired maximum differs, callsite `0x0056cda2` invokes UID000450 on the child pointer stored at `NewGroupPane +0x100`. UID000450 independently preserves the same-range no-op, signed `0..30000` clamp, direct current-position clamp, and ordered one/two invalidations. The caller then reloads the child, derives the valid current position from first-visible-row state at `NewGroupPane +0xfc`, and calls [UID:000451][0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition](by-memory/0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition.md) at `0x0056ce39` when needed.

The update method has ten incoming code references from layout, key, mouse, packet, scroll-callback, open-lifecycle, parser/raw-status, and expanded-mode paths. This caller family proves the child range setter is normal live `NewGroupPane` behavior, not an orphaned or retained clone.

UID000451 has two additional direct NewGroupPane callsites outside the immediate `UpdateScrollRange` reconciliation. `OnMouseClick` calls it at `0x0056dbbd` only after the owner-side mouse-wheel calculation has been signed-clamped to `[0, m_scrollRange]`. `NewGroupPane::SetScrollPosition` calls it at `0x0056df1c` while synchronizing the scrollbar-owner callback. Together with `0x0056ce39`, these three paths establish a deliberate division of responsibility: NewGroupPane and `SetMaxRange` own range policy, while UID000451 only applies a changed signed position and invalidates inherited `m_visibleBounds` once.

The 39-byte UID000451 body is byte-identical to the typed ScrollCollectionPane and ScrollVolumePane setters. That proof fixes the child declaration as `void SetScrollPosition(short position)`, rejects the decompiler short return, and confirms equality is a complete no-op. This class page records caller semantics and owner policy only; exact child C++ remains on UID000451.

## Evidence Notes

- IDA MCP confirms the listed real function starts and the constructor xref from `GeneralPurposePanel` at `0x004b84f5`.
- IDA confirms `ParseGroupListPacket` at `0x0056e130`; it calls `MapPane`-style marker helpers at `0x0050e810` and `0x0050e4c0`.
- IDA currently reports no function object at raw start `0x0056e570`; exact bytes/fence and inline-equivalent behavior nevertheless support retained source helper [UID:0004ZG][0x0056e570-0x0056e6c1.NewGroupPaneUpdateGroupMemberStatus](by-memory/0x0056e570-0x0056e6c1.NewGroupPaneUpdateGroupMemberStatus.md). Historical Wave3 `UpdateGroupEntry` spelling is rejected.
- Primary, secondary, and tertiary vtables are `0x00624554`, `0x006245a4`, and `0x006245d4`; the secondary/tertiary destructor slots use adjustor thunks `0x0057329f` and `0x005732aa`, and the scalar deleting destructor is `0x00573570-0x00573634` in [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md).
- 2026-05-31 IDA MCP confirms the exact vtable-data child [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md): the range starts at `NewGroupPane` RTTI and ends before `CollectionPane`.
- 2026-06-07 A001 Batch094 live IDA `lookup_funcs` reconfirmed the modeled NewGroupPane functions from constructor `0x0056ca20-0x0056caeb` through toggle `0x0056e8c0-0x0056e939`, including the previously omitted secondary-vtable handler `0x0056dd50-0x0056def6`.
- 2026-06-07 `xrefs_to` reconfirmed constructor call `0x004b84f5`, secondary-vtable handler data ref `0x006245b4`, parser call `0x0056dd84 -> 0x0056e130`, no xrefs to raw `0x0056e570`, and constructor/destructor stores to vtable bases `0x00624554`, `0x006245a4`, and `0x006245d4`.
- 2026-06-07 decompilation of `0x0056dd50` shows packet opcode byte `99`; subtype `2` dispatches to `0x0056e130`, while subtype `3` decodes a member id/name/position payload, updates cached group member fields, calls `MapPane` marker helper `0x0050e4c0`, refreshes the scroll range through `0x0056cd30`, and invalidates the pane through vtable slot `+0x20`.
- 2026-06-30 parent-gate check: direct parent [UID:0000JS][Group](by-file/Group.md) is `90/86`, and this class continues to clear the corrected child-and-parent `85/85` gate.
- 2026-07-13 B004 UID00015Y callback resolves the prior swapped semantic labels through vtable position. `0x0056cb80` occupies primary `+0x48` and is the common `OnActivate(const unsigned char *packetData)` override whose behavior requests the group list; its packet argument is unused. `0x0056cc80` is the render-region/layout override that computes normal or expanded bounds. Historical `RequestGroupList` and layout labels remain behavior aliases, not common virtual declaration names.

## Cross-References

- [UID:0000JS][Group](by-file/Group.md)
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md)
- [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md)
- [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md)
- [UID:0003F2][0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings](by-memory/0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings.md)

## Changes

- 2026-08-15 B003 UID0003F6 accepted callback: linked the exact pooled `100.0` plus alignment child and both HP/MP `NewGroupPane::OnPaint` xrefs, preserved inline literal source, and rejected any class member/static/H declaration while retaining all class metadata and child assembly.
- 2026-08-15 B008 UID0003F2 accepted callback: added the exact 68-byte NewGroupPane resource/format literal child at CPP position 75, recorded all four UID0004Z5 source-use xrefs and the pooled/no-object disposition, and preserved `94/95`, all twenty-one method children, complete formal CPP/H, and unrelated class evidence.
- 2026-07-29 B007 UID000451 accepted support callback: retained `85/86` and UID0000JS ownership; expanded the child-scroll contract from the existing `0x0056ce39` range reconciliation to all three direct UID000451 callers, including `0x0056dbbd` caller-side signed mouse-wheel clamp and `0x0056df1c` owner-callback synchronization. Recorded that UID000451 performs no local clamp, uses `void SetScrollPosition(short position)`, and invalidates inherited `m_visibleBounds` only after a changed store.
- 2026-07-29 B002 UID000450 accepted support callback: scores and owner/emitter remain `85/86`, UID0000JS; expanded `UpdateScrollRange` with exact `+0x100` child, `+0xfd` count, `+0x10c` expanded flag, six/twelve-row calculation, UID000450/UID000451 callsites, first-visible-row follow-up, and ten-caller live-use evidence.
- 2026-07-13 B004 UID00015Y accepted callback: scores remain `85/86`; corrected `0x0056cb80` to the common pointer-valued `OnActivate` override with `RequestGroupList` behavior, corrected `0x0056cc80` to `UpdateRenderRegion`/layout behavior, preserved historical aliases and every unrelated method/vtable/raw-helper fact, and retained the existing class-level no-code proof.
- 2026-06-30 B002 Group empty-emitter implementation:
  - Inserted the formal no class-level C++ body marker.
  - Updated current prose from blank class-level C++ to marker disposition while preserving raw-helper/member-name and final declaration caveats.
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

## 2026-07-31 B002 UID000090 Accepted Source-Quality Callback

- Current source decision: NewGroupPane is a  x110 field-bearing PanelPane subclass in NexusTK/social/Group.cpp, not an aggregate-only audit or an address-named decompiler artifact.
- Exact tail layout after the  xf8 base: m_unusedState[4] at +0xf8, signed m_firstVisibleMember at +0xfc, signed m_groupMemberCount at +0xfd, alignment at +0xfe, m_scrollPane at +0x100, m_numericGlyphs at +0x104, m_toggleButtonState at +0x108, m_expanded at +0x10c, and compiler tail alignment through  x110.
- Exact source roles:  x56cbf0 is UpdateRenderRegion,  x56cc80 is the two-argument SetBounds,  x56df40/ x56dfb0 are AddToLayer/RemoveFromLayer, and the EventHandler facet owns pointer, key/text, and packet overrides.
-  x56dfd0, raw  x56e030, raw  x56e090, and raw  x56e820 are narrow file-local geometry/hit-test helpers. Raw  x56e570 is retained UpdateGroupMemberStatus source whose live subtype-3 path is inlined. Zero current xrefs do not turn complete source-shaped bodies into padding.
- Constructor ownership is fixed by the sole  x4b84f5 allocation/call route and all three vptr stores. Vtable bases have constructor, destructor, and scalar-wrapper store triads. UpdateScrollRange has ten callers and delegates signed range/position mechanics to UID000450/UID000451.
- Full-list and status packet behavior, member record stride  x12c, id/name/online/appearance/HP/MP fields, map-marker removal/refresh, six-versus-twelve-row policy, numeric drawing, and expanded-mode behavior are preserved in the exact child pages.
- Source-facing names are evidence-backed inferred human names. Historical UpdateGroupEntry, swapped OnLayout/UpdateRenderRegion, OnOpen/OnClose, and no-route-equals-no-source conclusions remain rejected history.
- Compiler scalar-deleting and facet-adjustor wrappers plus all RTTI/vtable arrays remain compiler output and are not handwritten source.

### Exact NewGroupPane Source Split

| Exact child | Role | Route |
| --- | --- | --- |
| [UID:0004YZ][0x0056ca20-0x0056caeb.NewGroupPaneConstructor](by-memory/0x0056ca20-0x0056caeb.NewGroupPaneConstructor.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z0][0x0056caf0-0x0056cb73.NewGroupPaneDestructor](by-memory/0x0056caf0-0x0056cb73.NewGroupPaneDestructor.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z1][0x0056cb80-0x0056cbe6.NewGroupPaneOnActivate](by-memory/0x0056cb80-0x0056cbe6.NewGroupPaneOnActivate.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z2][0x0056cbf0-0x0056cc78.NewGroupPaneUpdateRenderRegion](by-memory/0x0056cbf0-0x0056cc78.NewGroupPaneUpdateRenderRegion.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z3][0x0056cc80-0x0056cd25.NewGroupPaneSetBounds](by-memory/0x0056cc80-0x0056cd25.NewGroupPaneSetBounds.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z4][0x0056cd30-0x0056ce4b.NewGroupPaneUpdateScrollRange](by-memory/0x0056cd30-0x0056ce4b.NewGroupPaneUpdateScrollRange.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z5][0x0056ce50-0x0056da03.NewGroupPaneOnPaint](by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0003F2][0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings](by-memory/0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings.md) | pooled-literal covered-by CPP child at position `75`; no H or source object | UID000090 -> UID0000JS |
| [UID:0003F8][0x00624bf0-0x00624c00.GroupPaneRectConstant](by-memory/0x00624bf0-0x00624c00.GroupPaneRectConstant.md) | pooled-local `RectBounds rowBounds = { 6, 14, 161, 54 };` covered-by CPP child at position `76`; no H or standalone object | UID000090 -> UID0000JS |
| [UID:0004Z6][0x0056da10-0x0056daf7.NewGroupPaneHandleKeyOrTextEvent](by-memory/0x0056da10-0x0056daf7.NewGroupPaneHandleKeyOrTextEvent.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z7][0x0056db00-0x0056dd46.NewGroupPaneHandlePointerOrMouseEvent](by-memory/0x0056db00-0x0056dd46.NewGroupPaneHandlePointerOrMouseEvent.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z8][0x0056dd50-0x0056def6.NewGroupPaneHandlePacketEvent](by-memory/0x0056dd50-0x0056def6.NewGroupPaneHandlePacketEvent.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z9][0x0056df00-0x0056df38.NewGroupPaneSetScrollPosition](by-memory/0x0056df00-0x0056df38.NewGroupPaneSetScrollPosition.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZA][0x0056df40-0x0056dfa6.NewGroupPaneAddToLayer](by-memory/0x0056df40-0x0056dfa6.NewGroupPaneAddToLayer.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZB][0x0056dfb0-0x0056dfc6.NewGroupPaneRemoveFromLayer](by-memory/0x0056dfb0-0x0056dfc6.NewGroupPaneRemoveFromLayer.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZC][0x0056dfd0-0x0056e027.GetGroupToggleButtonRect](by-memory/0x0056dfd0-0x0056e027.GetGroupToggleButtonRect.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZD][0x0056e030-0x0056e086.GetGroupMemberRowRect](by-memory/0x0056e030-0x0056e086.GetGroupMemberRowRect.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZE][0x0056e090-0x0056e126.HitTestGroupMemberRow](by-memory/0x0056e090-0x0056e126.HitTestGroupMemberRow.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZF][0x0056e130-0x0056e565.NewGroupPaneParseGroupListPacket](by-memory/0x0056e130-0x0056e565.NewGroupPaneParseGroupListPacket.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZG][0x0056e570-0x0056e6c1.NewGroupPaneUpdateGroupMemberStatus](by-memory/0x0056e570-0x0056e6c1.NewGroupPaneUpdateGroupMemberStatus.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZH][0x0056e6d0-0x0056e813.NewGroupPaneDrawNumberString](by-memory/0x0056e6d0-0x0056e813.NewGroupPaneDrawNumberString.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZI][0x0056e820-0x0056e8b4.HitTestGroupToggleButton](by-memory/0x0056e820-0x0056e8b4.HitTestGroupToggleButton.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZJ][0x0056e8c0-0x0056e939.NewGroupPaneToggleExpandedMode](by-memory/0x0056e8c0-0x0056e939.NewGroupPaneToggleExpandedMode.md) | exact source child | UID000090 -> UID0000JS |

The twenty-one method pages use half-open body ranges only; UID0003F2 is the additional non-body covered-by child. Exact excluded  xcc fences are: 56caeb-caf0 (5), 56cb73-cb80 (13), 56cbe6-cbf0 (10), 56cc78-cc80 (8), 56cd25-cd30 (11), 56ce4b-ce50 (5), 56da03-da10 (13), 56daf7-db00 (9), 56dd46-dd50 (10), 56def6-df00 (10), 56df38-df40 (8), 56dfa6-dfb0 (10), 56dfc6-dfd0 (10), 56e027-e030 (9), 56e086-e090 (10), 56e126-e130 (10), 56e565-e570 (11), 56e6c1-e6d0 (15), 56e813-e820 (13), and 56e8b4-e8c0 (12). The aggregate successor fence remains [0x56e939,0x56e940).

### Evidence And Score Rationale

- Completion 94: class declaration, inheritance, exact size/tail fields, all method/helper roles, source route, split boundaries, formal child topology, and source bodies are now represented.
- Confidence 95: current live IDA established every modeled/raw/glue range, current declarations and frames, all required xref sets, four raw no-function starts, vtable/protected-successor bytes, and proposed-name collision negatives. Remaining uncertainty is stripped lexical spelling/access qualifiers, not behavior or routing.
- The formal CPP contains only [[CHILDREN]]; every method definition belongs to its exact address child. The formal H contains the one complete human source declaration and no compiler vtable arrays.

## UID0003F8 Row-Initializer And OnPaint Dependency Closure - 2026-08-16

UID0003F8 is now the class-owned position-76 physical child immediately after UID0003F2 position 75. Its unique 16-byte `[6,14,161,54]` pool image has one `NewGroupPane::OnPaint` xref and lowers directly to a typed stack local. The child emits only a covered-by marker; the actual aggregate expression remains in UID0004Z5 and the class declaration gains no data member, static, accessor, or H fragment.

The corrected UID0004Z5 body keeps the existing `virtual void OnPaint();` declaration but closes its previously invalid dependencies: six explicit `EPFTileContext::Initialize()` calls, accepted `.bounds`, frame-zero `COMMA.EPF`, one reused tile context, global `GroupMemberRecord` accessed through narrow UserPane friendship, exact partial `HumanImageRenderParams` writes, full `NewHumanImageLib::CalculateBounds`/`Draw` contracts, and constructor-free `RectBounds` geometry. `rowBounds`, `commaFrame`, and `scratchContext` are human-source inferences; compiler/decompiler labels and invented helper APIs remain rejected.

The Group translation-unit preamble is UID0000JS-owned and emitted once through the first routed Group class carrier before all Group children. NewHuman/Palette declarations remain in their own headers. This class page continues to own only its complete class declaration plus the `[[CHILDREN]]` assembly point, preserving 94/95 metadata and all prior method, field, vtable, range, padding, and historical evidence.
