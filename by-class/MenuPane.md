*** UID:00007W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MenuPane class declaration is intentionally withheld until its field layout,
// callback object ownership, and final method names are ready for source-quality declaration C++.
[[CHILDREN]]

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MenuPane

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Main address range: [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- Current recovered file: `source-3/simroot_v2/class_MenuPane.cpp`

## Class Purpose

`MenuPane` is the reusable popup/context menu pane. It owns its list, every appended `MenuItem`, and the selection callback object supplied by PopupMenuControlPane. It lays out item regions, handles pointer and keyboard navigation, stores the owning DialogPane while open, and invokes the callback when selection changes.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00516290-0x00516345` | `MenuPane::MenuPane(FunctionObjectT<long> *selectionCallback)` | Constructs Pane mode 1, `List(sizeof(MenuItem *), 8)`, callback ownership, closed state, selected `-1`, and null parent. |
| `0x00516350-0x005163fa` | `~MenuPane()` | Releases entries, the entry list, callback target, and base pane state. |
| `0x00516400-0x005164d8` | `AppendItem(MenuItem *)` | Appends the item and recomputes all item bounds. |
| `0x005164e0-0x005164f7` | `GetItem(int) const` | Returns the indexed menu item object. |
| `0x00516500-0x0051650b` | `GetItemCount() const` | Tiny list-count accessor consumed by PopupMenuControlPane. |
| `0x00516510-0x00516663` | `Show(DialogPane *, int x, int y, long selectedIndex)` | Stores parent/selection, closes an existing presentation, computes menu bounds, attaches to the layer, and animates open. |
| `0x00516790-0x0051693e` | `BuildAndDrawItems()` / `InitializeLayout()` candidate | Builds menu background/border, per-item regions, and dispatches each item's `DrawItem(GrafPort *port)` virtual slot. |
| `0x00516940-0x00516a62` | `HandlePointerEvent(const PointerEvent*)` | Hit-tests mouse movement/click/cancel behavior. |
| `0x00516a70-0x00516ba8` | `HandleKeyboardEvent(const KeyEvent*)` | Handles Enter/Space/Escape and up/down navigation. |
| [UID:000376][0x00516ba8-0x00516c40.MenuPaneKeyDispatchTables](by-memory/0x00516ba8-0x00516c40.MenuPaneKeyDispatchTables.md) | key dispatch tables | Compiler-generated switch/lookup tables used by `HandleKeyboardEvent`; non-reconstructable exact data child. |
| [UID:000377][0x00516c40-0x00516c9a.MenuPaneFindPreviousEnabledItemRaw](by-memory/0x00516c40-0x00516c9a.MenuPaneFindPreviousEnabledItemRaw.md) | raw previous-enabled helper | Scans backward through enabled items from a starting index. |
| [UID:000378][0x00516ca0-0x00516cf3.MenuPaneFindNextEnabledItemRaw](by-memory/0x00516ca0-0x00516cf3.MenuPaneFindNextEnabledItemRaw.md) | raw next-enabled helper | Scans forward through enabled items from a starting index. |
| [UID:000379][0x00516d00-0x00516dc2.MenuPaneRecomputeItemBoundsRaw](by-memory/0x00516d00-0x00516dc2.MenuPaneRecomputeItemBoundsRaw.md) | raw bounds recompute helper | Two-pass item measurement and bounds rewrite helper. |
| `0x005172be-0x005172d4` | Adjustor/thunk helpers | Vtable-referenced deleting-destructor thunks. |
| `0x00517320-0x005173fe` | `ScalarDeletingDestructor(uint32_t flags)` | Destructor wrapper with scalar-delete flag handling. |

## Evidence Notes

- Wave3 grades the class at effective `97.0`.
- IDA MCP confirms all listed starts as exact functions.
- Older Wave2 notes restored `GetItemByIndex` under `MenuPane` after reviewing `PopupMenuControlPane::OnDraw` and `RadioGroupControlPane::GetItemByIndex`.
- `MenuPane` selection dispatch can invoke the popup callback helper documented as [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md).
- 2026-06-11 IDA MCP split review covers the previously raw `0x00516ba8-0x00516dd0` band: [UID:000376][0x00516ba8-0x00516c40.MenuPaneKeyDispatchTables](by-memory/0x00516ba8-0x00516c40.MenuPaneKeyDispatchTables.md) holds the keyboard switch tables, [UID:000377][0x00516c40-0x00516c9a.MenuPaneFindPreviousEnabledItemRaw](by-memory/0x00516c40-0x00516c9a.MenuPaneFindPreviousEnabledItemRaw.md) and [UID:000378][0x00516ca0-0x00516cf3.MenuPaneFindNextEnabledItemRaw](by-memory/0x00516ca0-0x00516cf3.MenuPaneFindNextEnabledItemRaw.md) are previous/next enabled-item scans over the `this+0xf8` list, and [UID:000379][0x00516d00-0x00516dc2.MenuPaneRecomputeItemBoundsRaw](by-memory/0x00516d00-0x00516dc2.MenuPaneRecomputeItemBoundsRaw.md) recomputes per-item bounds after measuring each item.
- B004's [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) recheck confirms that the `0x00516790-0x0051693e` helper is not layout-only: at `0x005168f0` it dispatches `item->DrawItem(port)` through vtable slot `+0x14` and ignores the return. Keep `InitializeLayout` as a candidate historical label, but source-quality prose should include the render/draw role until the final method name is proven.

## PopupMenuControlPane Contract And Lifetime

B005's accepted UID00011F MCP pass during database session `bf5519ae` reconfirmed the MenuPane constructor, destructor, append, indexed get, count leaf, and show helper while resolving the owning popup class:

| Offset | MenuPane state | Evidence |
| --- | --- | --- |
| `+0xf8` | owned `List *` of four-byte `MenuItem *` entries | Constructor `new List(4, 8)`; append/get/count/layout/destructor loops. |
| `+0xfc` | owned `FunctionObjectT<long> *` callback | Constructor stores PopupMenuControlPane callback; destructor scalar-deletes it. |
| `+0x100` | open/visible state byte | Constructor clears; Show tests/sets; close paths clear. |
| `+0x104` | current/initial selected index | Constructor `-1`; Show receives selected index; navigation consumes it. |
| `+0x108` | `DialogPane *` active parent | Constructor null; Show stores its first explicit argument. |

PopupMenuControlPane constructor [UID:0004IM][0x00498040-0x0049812b.PopupMenuControlPaneConstructor](by-memory/0x00498040-0x0049812b.PopupMenuControlPaneConstructor.md) allocates the 24-byte `PlainMemberFunctionObject<void (PopupMenuControlPane::*)(long), PopupMenuControlPane, long>` and transfers it to MenuPane. MenuPane's destructor iterates and deletes every MenuItem, deletes the list, deletes the callback, and then performs base cleanup. [UID:0004IN][0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw](by-memory/0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw.md) therefore deletes only the MenuPane directly.

[UID:0004IO][0x00498170-0x0049817f.PopupMenuControlPaneAppendItem](by-memory/0x00498170-0x0049817f.PopupMenuControlPaneAppendItem.md) forwards to `AppendItem`, [UID:0004IP][0x00498180-0x0049818f.PopupMenuControlPaneGetItem](by-memory/0x00498180-0x0049818f.PopupMenuControlPaneGetItem.md) to `GetItem`, and [UID:0004IQ][0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount](by-memory/0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount.md) to the count leaf. [UID:0004IV][0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent](by-memory/0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent.md) and [UID:0004IW][0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown](by-memory/0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown.md) call `Show(m_parentDialog, screenX + width - 1, screenY, m_selectedIndex)`. Decompiler EBX register artifacts in `0x00516510` are not an additional source argument; the helper has four explicit source arguments after `this`.

MenuPane is the owned dependency and nested lifetime owner, not the owner of PopupMenuControlPane methods. The current consolidated PopupMenuControls source route remains accepted; possible original physical MenuPane source splitting remains a file-layout confidence cap only.

## Cross-References

- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:00007V][MenuItem](by-class/MenuItem.md)
- [UID:0000AN][PopupMenuControlPane](by-class/PopupMenuControlPane.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)
- [UID:0004IM][0x00498040-0x0049812b.PopupMenuControlPaneConstructor](by-memory/0x00498040-0x0049812b.PopupMenuControlPaneConstructor.md)
- [UID:0004IN][0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw](by-memory/0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw.md)
- [UID:0004IO][0x00498170-0x0049817f.PopupMenuControlPaneAppendItem](by-memory/0x00498170-0x0049817f.PopupMenuControlPaneAppendItem.md)
- [UID:0004IP][0x00498180-0x0049818f.PopupMenuControlPaneGetItem](by-memory/0x00498180-0x0049818f.PopupMenuControlPaneGetItem.md)
- [UID:0004IQ][0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount](by-memory/0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount.md)
- [UID:0004IV][0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent](by-memory/0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent.md)
- [UID:0004IW][0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown](by-memory/0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown.md)

## Changes

- 2026-07-12 B005 UID00011F support synchronization:
  - Score, metadata, emitter position, and intentionally withheld formal class block remain unchanged at `86/89`.
  - Added exact `+0xf8/+0xfc/+0x100/+0x104/+0x108` list/callback/open/selection/parent state, callback and MenuItem nested ownership, constructor/destructor lifetime, corrected AppendItem/GetItem/GetItemCount names, four-argument Show contract, popup caller links, and dependency-not-owner/source-route disposition.
  - Historical `void *selectionTarget`, `GetItemByIndex`, and ambiguous EBX-source-argument interpretations are superseded by the accepted typed callback and caller/callee evidence.

- 2026-06-30 B008 empty-emitter implementation:
  - Score remains `86/89`; set `EMITTER_POSITION_OPTIONAL:20` and populated the formal block with a no-declaration route marker plus `[[CHILDREN]]`.
  - Evidence: B008 kept the existing source-root route through [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), while MCP/current docs show the larger `MenuPane` field layout, callback object ownership details, and final method names are not complete enough for a class declaration shell.
  - Source-quality decision: exact `MenuPane` method/range evidence continues to live on child pages and [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md); this class page clears the generated empty marker without inventing fields.
- 2026-06-05: Marked reconstructable and attached to [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) because the class is `82/86` and the parent is `84/80`, satisfying the 80/80 parent gate. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x00516290`, `0x00516350`, `0x005164e0`, `0x00516790`, `0x00516940`, `0x00516a70`, and `0x00517320`; `callers` confirms the constructor is reached from `0x004980f6` inside `PopupMenuControlPane`.
- Completion/confidence score update: existed before as `0/0`; changed to `82/86`. Summary: the popup/context menu pane has clear role, exact method boundaries, selection callback behavior, entry ownership, pointer/key navigation, and restored ownership evidence, with only final C++ rewrite and deeper state-field naming below full completion. Evidence: linked `MenuPaneAndItems` memory range, IDA-confirmed starts, Wave2 restoration note for `GetItemByIndex`, and popup selection callback reference.
- 2026-06-11 A002 Batch166 strict-gate refresh:
  - Before: `82/86`; the raw keyboard/layout helper band was only summarized in [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md).
  - Changed to: `86/89`, with exact split children for the keyboard dispatch tables, previous/next enabled-item scans, and item-bounds recompute helper.
  - Evidence: live IDA MCP confirms the raw helper bytes, padding boundaries, list access at `this+0xf8`, item enabled-state byte checks at `item+0x14`, item metric virtual calls, and the bounds write to `item+0x04`.
- 2026-06-20 B004 SeparatorMenuItem draw support sync:
  - Score unchanged at `86/89`.
  - Evidence: recorded the `0x00516790-0x0051693e` helper's generic draw-slot dispatch at `0x005168f0`, supporting `DrawItem(GrafPort *port)` source naming for concrete menu items.
