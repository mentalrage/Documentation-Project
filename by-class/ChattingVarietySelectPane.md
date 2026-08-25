*** UID:00001Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChattingColorPane;
class Event;

class ChattingVarietySelectPane : public Pane,
                                  public Singleton<ChattingVarietySelectPane>
{
public:
    ChattingVarietySelectPane();
    virtual ~ChattingVarietySelectPane();

protected:
    virtual void OnPaint();
    virtual void SetupBackground();
    virtual void DrawBorder();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool OnDismiss(Event *event);

private:
    void GetItemRect(int row, RectBounds *outRect);
    signed char HitTest(int mouseY, int mouseX);

    bool m_pressCaptured;
    signed char m_hotRow;
};

extern ChattingVarietySelectPane *g_pChattingVarietySelectPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChattingVarietySelectPane

## Status

- Confidence: very strong for selector ownership, direct Singleton inheritance, vtable methods, row behavior, field roles/layout, constructor/destructor source shape, canonical Event contract, complete class-level declaration, and exact child-owned OnPaint source closure.
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingVarietySelectPane.cpp`
- Source declaration closure: the class is a direct `Pane` plus `Singleton<ChattingVarietySelectPane>` type, closes before `[[CHILDREN]]`, declares both selector row helpers already represented by exact child pages, and exposes one matching external singleton declaration after the class.
- Pointer-event closure: the class owns the sole declarations for source-ready children [UID:0002FJ][0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent](by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md) `HandlePointerOrMouseEvent(Event *event)` and [UID:0002FK][0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss](by-memory/0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss.md) `OnDismiss(Event *event)`. Each child emits its exact CPP body and keeps its formal H blank, avoiding duplicate declarations.
- Exact layout: `Pane` occupies through `+0xf8`; RTTI PMD `+0xf8` proves the empty Singleton base and EBO allows `m_pressCaptured` to share complete-object offset `+0xf8`; `m_hotRow` is `+0xf9`; normal four-byte complete-object alignment supplies implicit tail padding at `+0xfa..+0xfb`; and allocation size remains `0xfc`. No authored reserve member is emitted.
- Compiler boundary: Singleton publication/clear, vptr stores, constructor unwind, reverse base teardown, scalar deleting flags, optional free, EH/cookie state, adjustors, RTTI, and vtables are generated mechanics and are not class method declarations or handwritten bodies.
- Paint declaration/body boundary: this class block owns the sole `virtual void OnPaint();` declaration. [UID:0002FL][0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint](by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md) owns the exact method body; no body is duplicated at class scope and the class H channel remains physically blank.
- Background declaration/body boundary: this class block owns the sole `virtual void SetupBackground();` declaration. [UID:0002FN][0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground](by-memory/0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md) owns the source-ready method body; the child H channel remains physically blank and neither this class page nor the file page duplicates the definition.
- Border declaration/body boundary: this class block owns the sole `virtual void DrawBorder();` declaration. [UID:0002FO][0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder](by-memory/0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md) owns the source-ready method body; the child H channel remains physically blank and neither this class page, the aggregate, nor the file page duplicates the definition.

## Class Purpose

`ChattingVarietySelectPane` is the popup chat-mode selector. It lets the player choose Talk, Shout, Whisper, Group, Clan, or Color, then opens the matching input/color flow.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| compact button rectangle helper | [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md) | Raw IDA-unmodeled helper now kept with [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md); included here only because it sits immediately before the raw selector constructor and supports opening this popup. |
| compact button hit-test helper | [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md) | Raw IDA-unmodeled helper now kept with [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md); it tests the compact button rectangle, not the six-row popup list. |
| `ChattingVarietySelectPane` | [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md) | Retained source constructor at `92/94`: `Pane(1)`, direct Singleton base construction, `m_pressCaptured(false)`, and `m_hotRow(-1)`. No surviving call to the retained copy is optimizer-inlining evidence because UID0002FC contains an instruction-identical live inline construction; it is not no-source proof. |
| destructor body | [UID:0002FI][0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor](by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md) | Ordinary `92/94` selector destructor whose authored body calls only inherited `RemoveFromLayer()` and `UnregisterEventHandler()`. The later global clear and `Pane::~Pane()` are implicit reverse Singleton/Pane base destruction; scalar deleting output remains UID0002GI compiler glue. |
| `HandlePointerOrMouseEvent` | [UID:0002FJ][0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent](by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md) | Source-ready `94/95` EventHandler override. It uses Event type/Y/X at `+4/+8/+c`, rejects input while `g_pUserPane->m_inputLocked`, maps the adjusted facet receiver to complete-object `m_pressCaptured`, `m_hotRow`, and inherited `m_visibleBounds`, handles hover/capture/release, calls signed six-row `HitTest`, commits Talk/Shout/Whisper/Group/Clan/Color actions, refreshes the compact pane, and deletes this popup only on the exact outside-miss paths. |
| `OnDismiss` | [UID:0002FK][0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss](by-memory/0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss.md) | Source-ready `94/95` one-argument virtual. Its 31-byte body and `retn 4` ABI prove an ignored `Event *` parameter; it refreshes `g_pChattingVarietyPane`, calls inherited `MarkForDeletion()`, and returns false. Same-slot `0x00555ae0`/`0x005bd3a0` callbacks support the corrected declaration. |
| `OnPaint` | [UID:0002FL][0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint](by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md) | Source-ready `93/95` child. The exact `[0x00481490,0x004816ce)` body, SHA-256 `788A8F752904A9DEE29B670BB39D370956F4416CB1A27137E2FFA554C9B02360`, is reached only through primary-vtable slot `0x00614f70`; it calls `SetupBackground()` then `DrawBorder()`, emits six direct Talk/Shout/Whisper/Group/Clan/-Color- shadow/foreground text pairs, gates signed `m_hotRow` through private `GetItemRect`, and draws the four-edge bevel with inherited GrafPort calls while `m_pressCaptured` reverses palette indices 128/143. The child owns CPP; this class owns the sole declaration. |
| `SetupBackground` | [UID:0002FN][0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground](by-memory/0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md) | Source-ready `92/94` virtual. Its exact `[0x004816d0,0x00481741)` one-block body initializes one `EPFTileContext`, loads `L"SUBWIN.EPF"` frame 8 through `g_pEPFLib->LookupLayoutEntry`, copies inherited `m_visibleBounds`, writes inherited `m_drawMode = 1`, directly insets all four bounds by one pixel, and calls inherited `DrawTiledBackground(&backgroundBounds, &tile, L"SUBWIN.PAL")`. The child owns CPP; this class owns the sole declaration. |
| `DrawBorder` | [UID:0002FO][0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder](by-memory/0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md) | Source-ready `92/94` virtual. Its exact `[0x00481750,0x00481a72)` body is 802 bytes, SHA-256 `5669F9B6CA54AF32E11C5A1E4BF81F701D9DF170799EFC90C8EA5DDC0AB3592A`, 292 instructions, and nine blocks, reached only through primary-vtable slot `0x00614f78`. It initializes one `EPFTileContext`, derives local width/height from inherited `m_visibleBounds`, uses four mandatory seven-pixel `do` loops, and renders `SUBWIN.EPF` frames `1/6/3/4/0/2/5/7` through current ImageLib/ResourceLayoutTable/GrafPort contracts. The child owns CPP; this class owns the sole declaration. |
| `GetItemRect` | [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md) | Source-ready `92/94` private member. The sole OnPaint caller supplies selector `ECX`, signed row, and local `RectBounds`; it writes invalid `(-1,-1,-1,-1)` or normal `(0,row*16+6,67,row*16+22)` bounds and is inlined into `HitTest`. |
| `HitTest` | [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md) | Source-ready `92/94` private member `signed char HitTest(int mouseY, int mouseX)`. It tests six half-open row rectangles and returns `0..5` or `-1`; its exact child emits the body while this class emits the sole declaration. |
| `ScalarDeletingDestructor` | `0x00483db0` | Clears popup state during deletion. |

## SetupBackground Source Closure

[UID:0002FN][0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground](by-memory/0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md) closes the background virtual that [UID:0002FL][0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint](by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md) dispatches immediately before `DrawBorder()`.

- Exact binary identity: `[0x004816d0,0x00481741)`, `0x71` bytes, 39 instructions, one block, SHA-256 `FC6656E681D80DFA1D35C56E476EC8620FA209EE9C0DBEB259B0577639ED3FE0`.
- Exact virtual route: its only inbound reference is selector primary-vtable cell `0x00614f74`. The adjacent cells are `0x00614f70 -> OnPaint` and `0x00614f78 -> DrawBorder`, proving this class owns the method even though there are no direct code callers.
- Exact source behavior: initialize a local `EPFTileContext`; call `g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 8, &tile)`; copy inherited `m_visibleBounds`; set inherited `m_drawMode` to `1`; increment left/top and decrement right/bottom; call inherited `DrawTiledBackground` with `L"SUBWIN.PAL"`.
- Exact negative behavior: there is no branch, failed-resource check, explicit context cleanup, draw-mode restore, rectangle-helper call, or authored stack-cookie operation.
- Source contract closure: [UID:00004I][EPFTileContext](by-class/EPFTileContext.md), [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md), [UID:00005V][GrafPort](by-class/GrafPort.md), and [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) now resolve every dependency that formerly kept the child blank.
- Comparator closure: the target and three other pane background virtuals have the same `0x71`/39-instruction/one-block lowering but distinct vtable cells. This is repeated human member source, not a covered-by shared function.
- Historical disposition: B003's earlier blank-C++ decision is preserved as a valid dated dependency state, but current type/global/helper docs and the accepted VoteMenu comparator supersede its source-readiness blocker.

## DrawBorder Source Closure

[UID:0002FO][0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder](by-memory/0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md) closes the border virtual that [UID:0002FL][0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint](by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md) dispatches immediately after `SetupBackground()`.

- Exact binary identity: `[0x00481750,0x00481a72)`, `0x322` / 802 bytes, 292 instructions, nine blocks, SHA-256 `5669F9B6CA54AF32E11C5A1E4BF81F701D9DF170799EFC90C8EA5DDC0AB3592A`.
- Exact virtual route: sole external xref `0x00614f78 -> 0x00481750`; there are no direct code callers. Adjacent primary-vtable cells are `0x00614f70 -> OnPaint` and `0x00614f74 -> SetupBackground`, confirming class ownership and source order.
- Exact source behavior: initialize one `EPFTileContext`; create a zero-origin `7x7` `RectBounds`; derive width/height from inherited `m_visibleBounds`; render top/bottom/left/right through four entry-before-test loops stepping seven pixels; then render four corners. Resource-frame order is `1/6/3/4/0/2/5/7`, with direct `L"SUBWIN.EPF"` lookup, inherited `RenderTileFrame` mode `1`, `L"SUBWIN.PAL"`, and `NULL` options.
- Source contract closure: [UID:00004I][EPFTileContext](by-class/EPFTileContext.md), [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), `RectBounds`, `InitRectBounds`, source-facing `OffsetRect`, [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md), and [UID:00005V][GrafPort](by-class/GrafPort.md) resolve every dependency that formerly kept the child blank. IDA's `NexusTK_OffsetRect` prefix is only a Win32-name collision workaround.
- Exact bounds protection: predecessor `[0x00481741,0x00481750)` is fifteen `0xcc` bytes and successor `[0x00481a72,0x00481a80)` is fourteen `0xcc` bytes; neither belongs to the method body or class declaration.
- Comparator closure: three standalone methods plus one same-profile virtual share the `0x322`/292-instruction/nine-block shape, and one larger body inlines the same operation sequence. This proves repeated direct member source and rejects a synthetic `DrawSubwinTile` helper; copied-versus-header-inline origin remains only a bounded confidence cap.
- Exact negative behavior: no resource-failure branch, dimension clamp/guard, explicit context release, draw-state restore, pane-absolute destination, compiler-cookie source, or helper-body duplication is emitted.
- Historical disposition: B003's blank-C++ decision and raw `sub_`/`dword_`/`off_` aliases remain dated evidence of the then-unresolved dependency state. Current shared types/helpers/global and comparator source supersede that blocker without deleting its valid range/tile-order findings.

## Evidence Notes

- Historical B005 evidence from MCP session `80de0a67` correctly established the complete raw constructor bytes, no modeled entry/xrefs, six- and ten-byte padding, body SHA-256 `a0a8b1182eb3447701982d3849325580db4ce4940a6304468ce51bb504169350`, singleton/field/vtable writes, ordinary/scalar support, and matching inline construction. Its marker-only conclusion is superseded by the 2026-07-21 B002 source-shape closure: a retained out-of-line constructor can have every source call inlined, while direct Singleton RTTI and the complete source body make a destination-ready constructor defensible. The former marker was:

```cpp
// Emitted code for this range covered by [UID:0002FC]
```

The class remains declaration-only C++; the constructor body emits on UID0002FH and every other method body remains on its exact child page.
- IDA MCP raw decode also confirms unmodeled helper bodies at `0x00481010-0x00481056` and `0x00481060-0x004810ea`; current IDA xrefs do not identify callers for those helpers. Their `(0,0,62,24)` geometry matches the compact `ChattingVarietyPane` button, not the six-row popup selector list.
- IDA MCP confirms exact function boundaries and vtable entries for `0x00481150`, `0x004811c0`, `0x00481470`, `0x00481490`, `0x004816d0`, `0x00481750`, and `0x00481a80`.
- IDA MCP on 2026-05-26 confirms `0x00481ad0` is a six-row hit-test helper with callers only at `0x0048124d` and `0x00481430` inside the method now canonically named `ChattingVarietySelectPane::HandlePointerOrMouseEvent`; the old `OnMouseEvent` spelling remains only in the stable child filename and historical notes.
- B003's 2026-07-24 UID000106 closure confirms the exact `[0x00481ad0,0x00481b5b)` 139-byte body and SHA-256 `AFD9F146918CF5A289F5FD0D7724FD34C16B02E619F638196DDDCD53D1BE6E6B`. Both callers load this selector into `ECX`, pass `mouseY` then `mouseX`, and consume the signed `0..5/-1` result, proving the non-static private declaration already emitted above.
- The target's six-row `(0,row*16+6,67,row*16+22)` geometry and retained invalid-row branch match UID0002FM exactly. The strongest human source shape calls `GetItemRect` from `HitTest`; the compiler inlined it and added `/GS` cookie/register/epilogue mechanics. Those mechanics remain child-level compiler evidence and are not class declarations.
- Historical BulletinSession/file-local/static/x-y/blank-C++ interpretations are superseded. The compact `(0,0,62,24)` helpers remain ChattingVarietyPane-owned, while this selector's exact children now emit both private row-helper bodies in source/binary order.
- B002 2026-06-16 reanalysis moved the former `ChattingVarietySelectPaneStateCompareHelper` and `ChattingVarietySelectPaneStateSnapshotHelper` pages to `ChattingHandlePane`: their `this+0x111/+0x114/+0x118/+0x11c/+0x120/+0x124` active fields and 0x18-byte snapshot record match handle-pane render state, not variety-select popup state. Variety-select evidence remains with [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md) and [UID:0002FJ][0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent](by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md).
- Current source-quality closure ties selector rows to exact Default/current-mode, Shout, Whisper recipient-name, Group, Clan, and Color actions. The row-2 standard-library-style IDA alias is demonstrably polluted; source uses `OpenSayToUserNameInputPane`, supported by its sole caller, allocation, and recipient-name constructor path.
- B003 2026-06-17 selector source-quality reanalysis resolves the selector-specific fields: `m_pressCaptured` at `+0xf8` is set while a press inside the popup is active, `m_hotRow` at `+0xf9` stores row `0..5` or `-1`, and `+0xfa..+0xfb` have no reads, writes, initialization, serialization role, or other independent field evidence.
- B010 2026-08-05 closes `OnPaint` without changing class ownership or declaration shape. Exact source uses inherited `m_visibleBounds`, direct `MoveTo` / `DrawWideText` label pairs at y `21/37/53/69/85/101`, private `GetItemRect(m_hotRow, &itemBounds)`, endpoints `left + 4` / `right - 5`, and direct `SetDrawColor` / `LineTo` calls. Historical `DrawShadowedLabel`, `DrawHotRowFrame`, `GetVarietyItemRect`, raw `off_615364`, and unresolved GrafPort dependency descriptions are retained only as superseded child-level assumptions.
- B002 2026-07-21 post-callback ABI repair rechecked live MCP session `9b0396a3`: the retained constructor and instruction-identical inline construction write only `+0xf8` and `+0xf9`; the complete Chatting-family scan has zero `+0xfa` or `+0xfb` accesses; and the `0xfc` allocation follows naturally from the class's four-byte alignment. The earlier source-facing `m_reservedFA[2]` declaration encoded a reverse-engineered offset without semantic evidence and is superseded; these two bytes are implicit compiler tail padding, not an authored member.
- The selector row order is Talk, Shout, Whisper, Group, Clan, and Color. Rows `0..4` write the current chat variety mode byte at `dword_67A748 + 0x3eb4`; row `5` opens [UID:00001T][ChattingColorPane](by-class/ChattingColorPane.md) without writing a mode value.
- Exact source-facing row calls are `OpenInputPaneForCurrentSayMode`, `OpenShoutInputPane`, `OpenSayToUserNameInputPane`, `OpenSayToGroupMessageInputPane`, and `OpenSayToClanMessageInputPane`; the shared enum/prototype contract is owned by the `SayInputPanes.h` support route, not by either Chatting child.
- UID0002FJ has exact range `[0x004811c0,0x00481461)`, 673-byte body SHA256 `2B3B9A31FD6344668DE5BCBA88B6A343CD030E6EA39D434D5E67F658508F6E0A`, and sole vtable slot `0x00614f84`. UID0002FK has exact range `[0x00481470,0x0048148f)`, body SHA256 `67C3DCC1402F8F3F8013C72EC829C576042615B7BE17DB84BBBA6B75560E0638`, and sole slot `0x00614f88`.
- Negative evidence excludes base-class ownership, a second selector-state object, raw authored receiver adjustments, reversed X/Y, a Color mode write, inside-gap deletion, a zero-argument dismiss ABI, and STL hardware-thread behavior. These are preserved as rejected or superseded interpretations rather than source declarations.
- Historical no-entry cap: IDA still has no function entry, caller, pointer-table route, or vtable callback route for `0x004810f0`; that remains useful optimizer evidence but no longer blocks the complete source constructor on UID0002FH because the retained body, live inline duplicate, direct Singleton RTTI, class layout, and destructor family close source identity without duplication.
- Method bodies remain in exact by-memory children. The class-level C++ block is intentionally declaration-only with `[[CHILDREN]]`; by-class output must not contain selector method bodies.
- 2026-06-17 B001 comparison/source-quality closure confirms [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md) as source-ready `GetItemRect(int row, RectBounds *outRect)`: selector `OnPaint` directly calls it at `0x00481605` with `ECX=this`, signed hot row, and an output `RectBounds` local; the helper writes either `(-1,-1,-1,-1)` or `(0,row*16+6,67,row*16+22)` through `InitRectBounds`.
- 2026-06-18 B005 destructor-cluster source-quality pass resolves [UID:0002FI][0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor](by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md) as ordinary `ChattingVarietySelectPane::~ChattingVarietySelectPane()`. The explicit pre-base cleanup calls are inherited `Pane::RemoveFromLayer()` at `0x00544ce0` and `Pane::UnregisterEventHandler()` at `0x00544d70`; `Pane::~Pane()` at `0x00544580` is the implicit base destructor. Vtable stores, scalar deleting wrapper, adjustors, optional delete, and generated SEH/cookie mechanics are compiler output.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md)
- [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md)
- [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md)
- [UID:0002FI][0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor](by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md)
- [UID:0002FJ][0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent](by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md)
- [UID:0002FK][0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss](by-memory/0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss.md)
- [UID:0002FL][0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint](by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md)
- [UID:0002FN][0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground](by-memory/0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md)
- [UID:0002FO][0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder](by-memory/0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md)
- [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md)
- [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md)
- [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md)
- [UID:00001T][ChattingColorPane](by-class/ChattingColorPane.md)

## Changes

- 2026-08-06 B007 UID0002FO source-quality callback:
  - Preserved class score `93/94`, owner/emitter UID0000I5, position `10`, direct Pane/Singleton inheritance, exact `0xfc` layout, declaration-only formal class, blank formal H, external singleton declaration, and every unrelated selector method/lifecycle fact.
  - Expanded `DrawBorder` to a source-ready `92/94` child with exact range/hash/profile, sole vtable route, complete EPFTileContext/RectBounds/ImageLib-ResourceLayout/GrafPort contracts, four mandatory seven-pixel loops, frame order `1/6/3/4/0/2/5/7`, padding boundaries, comparator family, and negative behavior.
  - Preserved the sole `virtual void DrawBorder();` declaration at class scope, kept the child H blank, and historicalized the earlier raw-name/blank-child dependency state without removing valid earlier evidence.
- 2026-08-06 B005 UID0002FN source-quality callback:
  - Preserved class score `93/94`, owner/emitter `0000I5`, position `10`, complete formal declaration/layout, and every unrelated selector method/lifecycle fact.
  - Expanded `SetupBackground` to a source-ready `92/94` child with exact range/hash/vtable route, EPFTileContext/ImageLib/GrafPort contracts, SUBWIN literals, inherited fields, one-pixel inset, tiled-background call, negative behavior, and comparator evidence.
  - Preserved the sole `virtual void SetupBackground();` declaration at class scope, kept the child H blank, and historicalized the earlier blank-child dependency state without removing its valid range/behavior findings.
- 2026-08-05 B010 UID0002FL OnPaint source-quality callback:
  - Raised the class from `92/94` to `93/94` while preserving owner/emitter UID0000I5, position `10`, reconstructability, direct Pane/Singleton inheritance, exact `0xfc` layout, external singleton declaration, and every unrelated child/lifecycle fact.
  - Expanded the existing OnPaint row and evidence with the exact range/hash, vtable-only route, SetupBackground/DrawBorder order, six direct label pairs, signed hot-row/GetItemRect geometry, captured-state 128/143 bevel reversal, and child-CPP/class-declaration ownership.
  - Preserved the declaration-only formal block exactly: the class retains `virtual void OnPaint();`, no method body was added at class scope, and formal H remains physically blank.
- 2026-08-05 B002 UID0002FJ/UID0002FK accepted source-quality callback:
  - Retained class metadata `92/94`, owner/emitter `0000I5`, reconstructability, position `10`, class layout, inheritance, singleton declaration, and all unrelated method/lifecycle evidence.
  - Corrected the stale `virtual bool OnDismiss();` declaration to the physical and source-facing `virtual bool OnDismiss(Event *event);` ABI while retaining the existing `HandlePointerOrMouseEvent(Event *event)` declaration.
  - Source-closed UID0002FJ and UID0002FK as independent `94/95` body-emitting children with exact Event ABI, state/bounds mapping, six row actions, helper identities, refresh/deletion behavior, body hashes, vtable-only ownership, and ignored dismiss argument.
  - Preserved historical `OnMouseEvent`, reversed X/Y, raw-offset receiver, polluted STL alias, zero-argument dismiss, unresolved helper/header, and blank-child assumptions as superseded evidence.

- 2026-07-24 B003 UID000106 source-quality callback:
  - Kept class `92/94`, owner/emitter/position metadata, complete formal declaration, layout, and every unrelated method/lifecycle fact unchanged.
  - Enriched the UID0002FM and UID000106 rows with exact private-member ABI, Y/X signature, signed return, geometry, source-ready child scores, compiler-inlining evidence, and one-declaration/child-definition ownership.
  - Preserved corrected historical assumptions as superseded provenance rather than pruning them.
- 2026-07-21 B002 UID0002XB source-quality callback:
  - Raised the class to `92/94`, set emitter position `10`, added the RTTI-proven direct `Singleton<ChattingVarietySelectPane>` base, canonical `Event *` pointer-handler declaration, selector row helper declarations, exact fields/tail layout, one external singleton declaration, and moved `[[CHILDREN]]` after the class closing brace.
  - Source-closed UID0002FH and UID0002FI while preserving all raw/no-xref, byte/hash, vtable, scalar, row, paint, background, border, dismiss, padding, and historical evidence. Explicit publication/clear, base teardown, vptr/EH/scalar/adjustor/delete/RTTI/vtable mechanics remain compiler-only.
  - Post-callback ABI repair removed the unsupported historical `m_reservedFA[2]` source member. Exact `+0xfa..+0xfb` and `0xfc` layout facts remain documented as normal implicit tail padding after the two one-byte fields.
- 2026-06-17 B003 selector source-quality execution:
  - Changed to `87/91` and populated declaration-only class C++.
  - Summary/evidence: B003 reanalysis resolved selector ownership under [UID:0000I5][Chatting](by-file/Chatting.md), parent-gate readiness, `m_pressCaptured`/`m_hotRow` field names, row action semantics, compact-versus-selector helper boundary, raw constructor no-entry cap, and method-body C++ deferral. Exact selector method/helper bodies remain in by-memory children, while this class page emits only the class shell and `[[CHILDREN]]`.
- 2026-06-17 B003 `ChattingVarietyPane` source-quality reanalysis:
  - Score remains `84/88`.
  - The compact helpers [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md) and [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md) remain related adjacency/opening support only, not selector-owned row methods. This popup's own six-row geometry remains [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md) and [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md).
- 2026-06-23 B003 current MCP support refresh (historical, superseded for [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md) by the B005 entry below):
  - Metadata and declaration-only class C++ remain unchanged.
  - Summary/evidence: MCP session `ff68e691` reconfirmed the [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md) no-executable-body policy: exact raw constructor bytes, selector vtable stores, `g_pChattingVarietySelectPane`, `m_pressCaptured`, and `m_hotRow` are documented, but no modeled function, xref route, pointer-table route, or de-duplication-safe constructor liveness exists.
- 2026-06-23 B005 [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md) covered-by marker implementation:
  - Class metadata and declaration-only C++ remain unchanged.
  - Summary/evidence: accepted B005 rework raises [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md) to `85/91` under this class owner/emitter and replaces the empty child C++ block with the exact marker shown above. MCP session `80de0a67` reconfirmed exact bytes, six-byte pre-padding, ten-byte post-padding, `fn:null` instruction decode, no start/end/destructor-start xrefs, no VA/RVA/raw-offset pointer route, selector vtable/global writes, ordinary/scalar destructor support, and the live inline construction path in [UID:0002FC][0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent](by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md). Executable constructor statements remain omitted until an out-of-line callable route is proven.

- What existed before: the page documented confirmed popup methods, hit-test ownership, and constructor caveat, but metadata was still `0/0`.
- What it was changed to: scores were set to `72/80`.
- Summary and evidence: selector rows, mouse/dismiss/paint/background/border helpers, and hit-test helper are covered; projected constructor reachability and final field layout remain incomplete.
- 2026-05-31: Updated completion/confidence from `72/80` to `76/84` after documenting the raw unmodeled constructor/helper bodies and exact destructor body before the existing mouse-dispatch range. Evidence: IDA MCP raw decode, function boundary checks, decompilation, xref checks, and padding audit.
- 2026-05-31: Updated completion/confidence from `76/84` to `84/88` after adding exact pages for mouse dispatch, dismiss, paint, background setup, border drawing, row rectangle, hit-test, and the adjacent raw state compare/snapshot bodies through `0x00481c10`. Evidence: IDA MCP function iteration, vtable xrefs, decompilation, raw disassembly, and padding audit; 2026-06-16 B002 later moved the two raw state bodies to `ChattingHandlePane` ownership.
- 2026-06-03: Clarified that the raw `0x00481010`/`0x00481060` compact-button helpers are cross-referenced setup support but attach to [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md), while this popup's own six-row geometry remains [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md) and [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md).
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE` and attached the class to [UID:0000I5][Chatting](by-file/Chatting.md). Current IDA MCP `lookup_funcs` reconfirmed destructor/mouse/dismiss/paint/background/border/rect/hit-test/scalar-destructor starts at `0x00481150`, `0x004811c0`, `0x00481470`, `0x00481490`, `0x004816d0`, `0x00481750`, `0x00481a80`, `0x00481ad0`, and `0x00483db0`; constructor evidence remains raw/unmodeled as already documented. Both class (`84/88`) and file (`83/87`) clear the 80+ attachment gate; reconstruction C++ remains blank pending final raw-helper naming and field layout.
- 2026-06-16: Removed [UID:0002FP][0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw](by-memory/0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw.md) and [UID:0002FQ][0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw](by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md) from this class inventory after B002 reanalysis tied their state record to `ChattingHandlePane` render state rather than the popup selector.
