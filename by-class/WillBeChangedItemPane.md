*** UID:0000G5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct LocalInventorySlotRecord;

class WillBeChangedItemPane : public Pane,
                              public Singleton<WillBeChangedItemPane>
{
public:
    WillBeChangedItemPane(Pane *owner,
                          char inventorySlot,
                          int y,
                          int x,
                          int pointerY,
                          int pointerX,
                          bool compactDisplay);
    virtual ~WillBeChangedItemPane();

protected:
    virtual void OnPaintFrame();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    LocalInventorySlotRecord *m_inventorySlotRecord;
    char m_inventorySlot;
    bool m_compactDisplay;
    int m_initialPointerY;
    int m_initialPointerX;
    int m_drawY;
    int m_drawX;
};

typedef char WillBeChangedItemPaneSizeMustBe272[
    sizeof(WillBeChangedItemPane) == 0x110 ? 1 : -1];

extern WillBeChangedItemPane *g_pWillBeChangedItemPane;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WillBeChangedItemPane

## Declaration-Channel Correction - 2026-08-16

The accepted seven-argument constructor, exact `0x110` class layout, virtual declarations, size guard, and singleton extern now live in the formal H channel. CPP retains only `[[CHILDREN]]`, so method definitions remain namespace-scope source children and the class is not duplicated in both generated channels. No behavior, ownership, score, field, or signature changed.

## Status

- Source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md); a dedicated `WillBeChangedPanes.cpp` remains rejected absent build/source evidence.
- Address range: [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_WillBeChangedItemPane.cpp`
- Confidence: very strong for method boundaries, direct-base hierarchy, singleton lifecycle, exact layout/signatures, complete declaration, and HelpPanes source placement.

## Class Purpose

`WillBeChangedItemPane` is a temporary item preview pane used while changing or dragging item slots. It renders the item icon, key binding, and item name in standard or compact display modes, tracks anchor/cursor deltas, and dismisses itself from input events.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `WillBeChangedItemPane` | [UID:0004V4][0x004c78e0-0x004c7b76.WillBeChangedItemPaneConstructor](by-memory/0x004c78e0-0x004c7b76.WillBeChangedItemPaneConstructor.md) | Constructs the Pane(1)/Singleton preview, resolves inventory state, computes compact/standard bounds, attaches the overlay, and localizes anchors. |
| `~WillBeChangedItemPane` | [UID:0004V5][0x004c7b80-0x004c7ba9.WillBeChangedItemPaneDestructor](by-memory/0x004c7b80-0x004c7ba9.WillBeChangedItemPaneDestructor.md) | Authored empty virtual destructor; implicit base teardown generates singleton clearing. |
| `OnPaintFrame` | [UID:0004V6][0x004c7bb0-0x004c7efd.WillBeChangedItemPaneOnPaintFrame](by-memory/0x004c7bb0-0x004c7efd.WillBeChangedItemPaneOnPaintFrame.md) | Draws icon, slot key, and item display name with exact compact/standard behavior. |
| `HandlePointerOrMouseEvent` | [UID:0004V7][0x004c7f00-0x004c7f4e.WillBeChangedItemPaneHandlePointerOrMouseEvent](by-memory/0x004c7f00-0x004c7f4e.WillBeChangedItemPaneHandlePointerOrMouseEvent.md) | Handles Y/X movement, invalidation, dismissal, and false return. |
| `HandleKeyOrTextEvent` | [UID:0004V8][0x004c7f50-0x004c7f8f.WillBeChangedItemPaneHandleKeyOrTextEvent](by-memory/0x004c7f50-0x004c7f8f.WillBeChangedItemPaneHandleKeyOrTextEvent.md) | Translates the key and dismisses on key-down except lowercase `i`. |
| `ScalarDeletingDestructor` | [UID:0003Z1][0x004ce670-0x004ce6cf.WillBeChangedItemPaneScalarDeletingDestructor](by-memory/0x004ce670-0x004ce6cf.WillBeChangedItemPaneScalarDeletingDestructor.md) | Compiler scalar deleting destructor wrapper; clears singleton, tears down pane, optionally deletes storage, and keeps formal C++ blank. |

## 2026-06-16 C001 Live Evidence Refresh

- Live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed item-pane function records for constructor `0x004c78e0-0x004c7b76`, non-deleting reset body `0x004c7b80-0x004c7ba9`, paint `0x004c7bb0-0x004c7efd`, event `0x004c7f00-0x004c7f4e`, key handler `0x004c7f50-0x004c7f8f`, adjustor thunks `0x004ce3b9` and `0x004ce3c4`, and scalar deleting destructor `0x004ce670-0x004ce6cf`.
- `xrefs_to 0x004c78e0` reconfirmed the single static constructor caller at `0x004ed40f` inside `0x004ecb50-0x004ed9c4`. Paint/event/key remain vtable-only through entries `0x0061ad38`, `0x0061ad44`, and `0x0061ad48`.
- `analyze_function 0x004c78e0` reconfirmed pane construction, singleton publish/fallback clear at `0x004c7939`/`0x004c7940`, three `WillBeChangedItemPane` vtable stores at `0x004c794d`/`0x004c7953`/`0x004c795d`, item slot lookup through [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md), icon bounds through `0x004df460`, compact/standard display-mode sizing, pane registration through `0x00544c70`, and anchor/cursor delta setup.
- B006 resolves that lookup as a `LocalInventorySlotRecord *` over the local-player inventory table. This pane consumes selected slot display/icon fields for preview state; it does not own the slot table.
- `xrefs_to 0x0061acf4`, `0x0061ad40`, and `0x0061ad70` reconfirmed constructor, reset-body, and scalar-destructor stores for all three item-pane vtable views. [UID:00025G][0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData](by-memory/0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md) remains the source-declared/generated-binary data anchor.
- `xrefs_to 0x0069b414` reconfirmed exactly five singleton accesses: constructor publish/clear, non-deleting destructor clear, helper clear at `0x004ce340`, and scalar deleting destructor clear at `0x004ce690`. `analyze_function 0x004ce670` reconfirmed the scalar deleting destructor restores all three vtable views, clears the singleton, calls pane teardown, and conditionally frees storage based on the delete flag.
- IDA DB source-quality update applied and saved: `sub_4C78E0 -> WillBeChangedItemPane_Constructor`, `sub_4C7BB0 -> WillBeChangedItemPane_OnPaint`, `sub_4CE670 -> WillBeChangedItemPane_ScalarDeletingDestructor`, and data name `unk_69B414 -> g_pWillBeChangedItemPane`.
- IDA DB candidates skipped: no event/key/reset/helper renames, prototypes, local names, or type/member edits were applied because event enum names, item-slot structures, compact-mode fields, and final pane/source split are still provisional.

## Evidence Notes

- IDA confirms the constructor and virtual function starts.
- IDA xrefs show the constructor called from `0x004ed40f`.
- This class is source-adjacent to help/tooltips but is specifically a temporary item change preview.
- 2026-05-26 IDA MCP storage check confirms [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md) as a 4-byte `.data` singleton adjacent to `g_pMetaMan`.
- Current owner/emitter remains [UID:0000JU][HelpPanes](by-file/HelpPanes.md). Exact source-ready children, class layout, and one-definition support close the former blank-formal blockers.
- The complete C++03 declaration above is the accepted source shape. The class closes before the extern and `[[CHILDREN]]`, so all exact child definitions emit at namespace scope.

## 2026-07-21 B003 Complete Class Closure

- RTTI proves direct polymorphic `Pane` and direct empty `Singleton<WillBeChangedItemPane>` bases. GrafPort, LObject, EventHandler, and TimerHandler are transitive Pane facets rather than additional source bases.
- Vtable heads are `0x0061acf4`, `0x0061ad40`, and `0x0061ad70`. RTTI roots are COL `0x006480f0`, CHD `0x00648104`, and BCA `0x00648114`; seven descriptors cover the class, Pane facets, and Singleton. Singleton PMD `+0xf8,-1,0` proves direct EBO.
- Exact layout is inherited Pane `+0x000..+0x0f7`; Singleton EBO and `LocalInventorySlotRecord *m_inventorySlotRecord` overlap at `+0x0f8`; `char m_inventorySlot` at `+0x0fc`; `bool m_compactDisplay` at `+0x0fd`; natural alignment only at `+0x0fe..+0x0ff`; then Y/X anchor and draw integers at `+0x100/+0x104/+0x108/+0x10c`. Total size is exactly `0x110`.
- The sole constructor caller at `0x004ed40f` allocates `0x110` and proves the seven-argument source order: owner, slot, Y, X, pointer Y, pointer X, compact flag.
- The virtual identities and exact bodies are UID0004V4 constructor position 10, UID0004V5 destructor 20, UID0004V6 paint 30, UID0004V7 pointer/mouse 40, and UID0004V8 key/text 50.
- Direct Singleton inheritance regenerates publish/clear and EH cleanup. UID0003Z1 owns compiler scalar-wrapper evidence. No explicit singleton store, vptr write, base-destructor call, scalar flags, operator delete, EH labels, raw RTTI/vtable arrays, raw offsets, or synthetic padding members appear in human source.
- Source placement remains `NexusTK/ui/controls/HelpPanes.cpp`; exact binary/rdata locality and the existing family route outweigh the unsupported narrower-file alternative.

## 2026-06-17 Scalar Destructor Wrapper Split

- B003 split [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) and assigned the exact `0x004ce670-0x004ce6cf` wrapper to [UID:0003Z1][0x004ce670-0x004ce6cf.WillBeChangedItemPaneScalarDeletingDestructor](by-memory/0x004ce670-0x004ce6cf.WillBeChangedItemPaneScalarDeletingDestructor.md) at `87/92`, owner/emitter [UID:0000G5].
- Source-facing name is `virtual WillBeChangedItemPane::~WillBeChangedItemPane()`. The wrapper and adjustor thunks are compiler ABI output and formal wrapper C++ stays blank.
- The wrapper validates `g_pWillBeChangedItemPane` (`dword_69B414`) cleanup, primary vtable slot `0x0061acf4`, and secondary/tertiary views `0x0061ad40/0x0061ad70`; no spell-pane singleton analogue is proven.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md)
- [UID:0000SS][g_pWillBeChangedItemPane](by-global/g_pWillBeChangedItemPane.md)
- [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md)
- [UID:0003Z1][0x004ce670-0x004ce6cf.WillBeChangedItemPaneScalarDeletingDestructor](by-memory/0x004ce670-0x004ce6cf.WillBeChangedItemPaneScalarDeletingDestructor.md)

## Changes

- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Replaced raw slot-lookup wording with the `LocalInventorySlotRecord` accessor dependency.
- 2026-06-16 C001 class-completion refresh:
  - Before: `82/86`, with constructor/paint/event/key/destructor inventory but stale singleton/source-placement support.
  - Changed to: `85/88`; owner/emitter remain [UID:0000JU][HelpPanes](by-file/HelpPanes.md), and reconstruction C++ remains blank.
  - Summary/evidence: live IDA MCP reconfirmed function boundaries, constructor caller, vtable-only paint/event/key entries, three item-pane vtable view stores, five singleton xrefs, and scalar deleting destructor behavior. IDA DB names were updated for the constructor, paint method, scalar deleting destructor, and singleton data slot; event/key/reset helper names, field names, and final `HelpPanes.cpp` versus `WillBeChangedPanes.cpp` split remain unresolved.
- 2026-06-17 B003 destructor-wrapper split sync:
  - Added exact scalar wrapper child [UID:0003Z1][0x004ce670-0x004ce6cf.WillBeChangedItemPaneScalarDeletingDestructor](by-memory/0x004ce670-0x004ce6cf.WillBeChangedItemPaneScalarDeletingDestructor.md), preserved blank formal C++ policy, and recorded singleton/vtable evidence.

- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000JU][HelpPanes](by-file/HelpPanes.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the constructor, paint, event, key, and scalar deleting destructor starts at `0x004c78e0`, `0x004c7bb0`, `0x004c7f00`, `0x004c7f50`, and `0x004ce670`; the class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:86`.
  - Summary/evidence: scored from the item preview constructor/paint/event/key/destructor map, singleton storage evidence, constructor xref, and help/tooltip source grouping caveat.
