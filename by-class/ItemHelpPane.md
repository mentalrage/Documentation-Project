*** UID:00006U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "HelpPanes.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ItemHelpPane : public Pane,
                     public Singleton<ItemHelpPane>
{
public:
    ItemHelpPane(const wchar_t *itemKey,
                 Pane *owner,
                 int x,
                 int y,
                 int timeoutMs,
                 const wchar_t *displayName,
                 int currentDurability,
                 unsigned char protectionCount);
    virtual ~ItemHelpPane();

protected:
    virtual void OnPaintFrame();
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    void PopulateItemData(const wchar_t *itemKey);
    short CountTextLines(const wchar_t *text, short textLength, int width);

    int m_contentWidth;
    int m_lineCount;
    bool m_isEquipmentItem;
    bool m_hasItemInstanceState;
    int m_currentDurability;
    wchar_t m_itemMetaKey[64];
    wchar_t m_itemDisplayName[64];
    wchar_t m_ownerName[64];
    wchar_t m_helpDescription[64];
    int m_protectionCount;
    wchar_t m_statLabels[20][20];
    wchar_t **m_statValueTextBuffers;
};

extern ItemHelpPane *g_pItemHelpPane;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ItemHelpPane

## 2026-08-22 UID0000KF Header-Route Closure

The already-proven ItemHelpPane declaration and `extern ItemHelpPane *g_pItemHelpPane` now emit through the HelpPanes H channel. The CPP channel retains only the owning header include and exact authored children. ItemMenuDialogs consumes the exact constructor `ItemHelpPane(const wchar_t *, Pane *, int, int, int, const wchar_t *, int, unsigned char)` and deletes UID0000R9 directly; it neither duplicates this declaration nor invents open/close wrappers.

## Status

- Selected source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md); a narrower `ui/controls/ItemHelpPane.cpp` remains a rejected unsupported alternative.
- Address range: [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md), now a non-emitting migration index over exact ItemHelpPane child pages; support helpers in [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_ItemHelpPane.cpp`
- Confirmed hierarchy: direct polymorphic base `Pane` plus direct empty `Singleton<ItemHelpPane>` base. `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler` are transitive/base views, not evidence that ItemHelpPane derives from HelpPane.
- Singleton contract: this header-facing page declares `extern ItemHelpPane *g_pItemHelpPane`; semantic global [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md) owns the sole externally linked definition, and physical UID0001PD is false/non-emitting storage evidence.
- Confidence: very strong for behavior, exact children, hierarchy, singleton declaration, complete natural `0x630` layout, and the HelpPanes source route. Residual uncertainty is limited to stripped lexical spellings.

## Class Purpose

`ItemHelpPane` is the rich item tooltip pane. It identifies inventory, equipment, or generic item contexts, copies display names, pulls item metadata through `MetaMan`, computes price/stat/requirement lines, sizes the tooltip, clamps it to parent and screen bounds, and draws formatted item help text.

RTTI rejects the historical `ItemHelpPane : HelpPane` model. The seven-descriptor hierarchy contains ItemHelpPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<ItemHelpPane>`. Pane is the direct polymorphic base; `Singleton<ItemHelpPane>` is a direct empty base at PMD `+0xf8,-1,0`; EventHandler and TimerHandler secondary views are at `+0xa0` and `+0xa4`. Constructor publication and ordinary/unwind/scalar clear stores for `g_pItemHelpPane` are implicit Singleton lowering rather than source-authored raw global assignments.

For inventory-backed help, B006 resolves the selected slot lookup as [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md). The pane may consume `LocalInventorySlotRecord::displayName`, `itemId`, and `iconStyle` as input before its richer `MetaMan` metadata pass; it does not own the local-player inventory slot table.

Current source-route decision: all ItemHelpPane declarations and authored children remain class-owned and emit through [UID:0000JU][HelpPanes](by-file/HelpPanes.md). No current build, address-order, or generated-source evidence justifies a narrower file split.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ItemHelpPane` | [UID:0003PL][0x004c82d0-0x004c8b13.ItemHelpPaneConstructor](by-memory/0x004c82d0-0x004c8b13.ItemHelpPaneConstructor.md) | Constructs item tooltip, selects item context, populates item data, sizes/clamps pane, and schedules timer. |
| `~ItemHelpPane` | [UID:0003PM][0x004c8b20-0x004c8bc2.ItemHelpPaneNonDeletingDestructor](by-memory/0x004c8b20-0x004c8bc2.ItemHelpPaneNonDeletingDestructor.md) | Frees allocated stat/value strings, clears [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md), and tears down base pane. |
| `OnPaintFrame` | [UID:0003PN][0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame](by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md) | Draws item name, description, buy/sell price, stats, owner, protection count, and class/tier requirements. |
| compiler switch data | [UID:0003PO][0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables](by-memory/0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables.md) | Non-emitting switch table generated from `OnPaintFrame`. |
| `OnTimer` | [UID:0003PP][0x004ccc20-0x004ccc3a.ItemHelpPaneOnTimerEvent](by-memory/0x004ccc20-0x004ccc3a.ItemHelpPaneOnTimerEvent.md) | TimerHandler override; timer id zero closes the pane and every path returns false. The file slug is historical. |
| `HandlePointerOrMouseEvent` | [UID:0003PQ][0x004ccc40-0x004ccc7e.ItemHelpPaneOnMouseEvent](by-memory/0x004ccc40-0x004ccc7e.ItemHelpPaneOnMouseEvent.md) | EventHandler override; invalidates inherited bounds, schedules timer zero for event types 1/4, and returns true. The file slug is historical. |
| `HandleKeyOrTextEvent` | [UID:0003PR][0x004ccc80-0x004ccc95.ItemHelpPaneDismissItemHelp](by-memory/0x004ccc80-0x004ccc95.ItemHelpPaneDismissItemHelp.md) | EventHandler override; ignores the event payload, null-safely deletes the active singleton, and returns false. The file slug is historical. |
| `PopulateItemData` | [UID:0003PS][0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData](by-memory/0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData.md) | Loads metadata rows and formats tooltip fields. |
| `CountTextLines` | [UID:0003PT][0x004ce100-0x004ce160.ItemHelpPaneCountTextLines](by-memory/0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md) | Counts wrapped line rows for a given width. |
| support helpers | [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) | Includes a UTF-16 SSO string comparison helper called from `PopulateItemData`, plus neighboring vector/singleton cleanup support shared with the HelpPanes family. |
| `ScalarDeletingDestructor` | [UID:0003YX][0x004ce430-0x004ce4fb.ItemHelpPaneScalarDeletingDestructor](by-memory/0x004ce430-0x004ce4fb.ItemHelpPaneScalarDeletingDestructor.md) | Compiler scalar deleting destructor wrapper; frees stat/value buffer table, clears `g_pItemHelpPane`, and keeps formal C++ blank because source is ordinary `virtual ItemHelpPane::~ItemHelpPane()`. |

The managed block is the complete source-clean declaration. It closes the class before `[[CHILDREN]]`, exposes one extern after the complete type, and keeps all eight definitions exclusively on child pages at emitter positions `10/20/30/40/50/60/70/80`.

## Item Display Layout Fields

B006 [UID:0003PN][0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame](by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md) source-quality incorporation resolves the paint/populate/destructor field direction for the item display data consumed by `OnPaintFrame`:

| Offset | Recommended name | Source shape and use |
| --- | --- | --- |
| `+0x100` | `m_isEquipmentItem` | Byte/bool flag; false selects compact value/durability drawing, true selects full equipment stats/owner/protection/requirements. |
| `+0x101` | `m_hasItemInstanceState` | Byte/bool flag gating current durability/state rows in the compact path. |
| `+0x104` | `m_currentDurability` | Integer durability/state value; not a generic item id. |
| `+0x108` | `m_itemMetaKey` / `m_itemKeyText` | Metadata key text populated before the richer item data pass. |
| `+0x188` | `m_itemDisplayName` | Title text copied by constructor/populate and drawn at the tooltip top. |
| `+0x208` | `m_ownerName` | Optional owner text; rejects stale `m_secondaryName`. |
| `+0x288` | `m_helpDescription` | Multiline description; `OnPaintFrame` calls `CountTextLines` to advance layout. |
| `+0x308` | `m_protectionCount` | Integer count formatted as `PROTECTED (%d)`; rejects stale durability naming. |
| `+0x334` | `m_valueLabel` | 20-wchar `Value` label. |
| `+0x35c` | `m_durabilityLabel` | 20-wchar `Durability` label. |
| `+0x384` | `m_armorLabel` pending exact literal binding | First equipment stat label. Current literal order supports `Armor`, but keep the note until [UID:0003PS][0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData](by-memory/0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData.md) literal writes are fully named. |
| `+0x3ac` | `m_hitLabel` | `Hit` label. |
| `+0x3d4` | `m_damageLabel` | `Damage` label. |
| `+0x3fc` | `m_vitalityIncreaseLabel` | `Vitality increase` label. |
| `+0x424` | `m_manaIncreaseLabel` | `Mana increase` label. |
| `+0x44c` | `m_mightIncreaseLabel` | `Might increase` label. |
| `+0x474` | `m_graceIncreaseLabel` | `Grace increase` label. |
| `+0x49c` | `m_willIncreaseLabel` | `Will increase` label. |
| `+0x4c4` | `m_wisdomIncreaseLabel` | `Wisdom increase` label. |
| `+0x4ec` | `m_constitutionLabel` | `Con` label. |
| `+0x514` | `m_requirementClassText` | Scratch/label buffer for `Any Class`, class names, and ascension-class labels. |
| `+0x53c` | `m_requirementLevelLabel` | `   Level ` label. |
| `+0x564` | `m_requirementSuffix` | ` Req ` label. |
| `+0x58c` | `m_regenLabel` | `Regen` label. |
| `+0x5b4` | `m_protectionLabel` | `Protection` label. |
| `+0x62c` | `m_statValueTextBuffers` | Fixed 20-row allocated display-text table. Destructor frees it; populate fills it; paint consumes rows 1-17. |

`m_statValueTextBuffers` row contract: row 1 value/price, row 2 durability, rows 3-12 equipment stats, row 13 class requirement code text, row 14 tier/ascension requirement code text, row 15 level requirement text, row 16 regeneration, and row 17 protection stat text. Rows 0, 18, and 19 exist because the storage is a fixed 20-row table but are not required by the observed paint path.

## OnPaintFrame Behavior

[UID:0003PN][0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame](by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md) is reached only through the primary `ItemHelpPane` vtable slot at `0x0061ae48`. It fills/invalidates the pane rectangle through SurfaceRenderCallbackTable slot `0x0069b3fc`, draws the frame, lays out the item name and optional multiline description, then chooses compact simple-item rows or the full equipment block.

The full equipment block draws value, optional durability, armor/hit/damage/stat-increase rows, optional owner text, optional `PROTECTED (%d)`, and class/tier/level requirements. Requirement rendering uses [UID:0003PO][0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables](by-memory/0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables.md): row 13 selects any-class/Warrior/Rogue/Mage/Poet/Archer, and row 14 selects full class versus `Il San`/`Ee San`/`Sam San`/`Sa San` ascension labels.

Do not model the stat row fragments or requirement cases as separate source functions. The binary has one large paint body plus private compiler labels; helper names such as `DrawCenteredLabelValue` or `DrawRequirementTriplet` are acceptable only as later source-style inline/macro abstractions after the class/source support docs accept that policy.

## Evidence Notes

- IDA confirms all listed function starts and sizes.
- IDA xrefs to the constructor include callers at `0x004ed957`, `0x0051b383`, `0x0051f7e3`, and `0x00568e84`.
- `PopulateItemData` uses `MetaMan` lookup helpers but remains item-tooltip presentation code.
- `DismissItemHelp` references the active singleton [UID:0001PD][0x0069ae04-0x0069ae08.g_pItemHelpPane](by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md).
- 2026-05-26 IDA MCP storage check confirms `g_pItemHelpPane` as a 4-byte `.data` singleton with 20 data references.
- 2026-05-28 IDA MCP confirms [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md): `0x004ce160` is called from `PopulateItemData`, and `0x004ce310` is the unwind helper that clears `g_pItemHelpPane`.
- 2026-06-14 C001 IDA MCP session `b001_0003gy` reconfirmed all target method starts and sizes: constructor `0x004c82d0` size `0x843`, non-deleting destructor `0x004c8b20` size `0xa2`, `OnPaintFrame` `0x004c8bd0` size `0x3fd0`, timer/mouse/dismiss helpers at `0x004ccc20`/`0x004ccc40`/`0x004ccc80`, `PopulateItemData` `0x004ccca0` size `0x1456`, `CountTextLines` `0x004ce100` size `0x60`, support helper `0x004ce160` size `0x4b`, singleton-clear unwind helper `0x004ce310` size `0x0b`, and scalar deleting destructor `0x004ce430` size `0xcb`.
- `analyze_component` shows the constructor calling `PopulateItemData` and `CountTextLines`, `OnPaintFrame` calling `CountTextLines`, and `PopulateItemData` calling the `0x004ce160` UTF-16 comparison/support helper, keeping the helper evidence inside the item-help presentation family rather than `MetaMan`.
- `xrefs_to 0x004c82d0` reconfirmed exactly four constructor callers at `0x004ed957`, `0x0051b383`, `0x0051f7e3`, and `0x00568e84`. `xrefs_to 0x0069ae04` reconfirmed 20 singleton references spanning constructor publication/guards, `DismissItemHelp`, destructor/scalar-deleting cleanup, unwind cleanup, and the item/inventory caller paths.
- `xrefs_to` for vtable heads `0x0061ae04`, `0x0061ae50`, and `0x0061ae80` shows constructor, non-deleting destructor, and scalar deleting destructor references for each head. `entity_query(kind=names)` places the item-help literal run after those vtables, including `ItemHelp%d`, `ItemInfo%d`, `Durability`, `Protection`, `Any Class`, class/ascension labels, and the `HierList` successor vtable at `0x0061b344`.
- RTTI PMD and hierarchy evidence resolves the direct bases as Pane plus `Singleton<ItemHelpPane>`, not HelpPane. GrafPort and LObject are inherited through Pane, while EventHandler/TimerHandler supply the secondary vtable views. Constructor/populate/paint/destructor accesses account naturally for every byte through object size `0x630`: two dwords, two bools, an aligned dword, four 64-wchar buffers, one dword, twenty 20-wchar labels, and one pointer table, with no explicit padding member.
- 2026-06-21 B006 [UID:0003PN][0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame](by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md) source-quality report maps the paint method's display fields, helper roles, and requirement switches: `OnPaintFrame` consumes display/owner/description/protection fields, the 20-row `m_statValueTextBuffers` table, GrafPort text/frame helpers, SurfaceRenderCallbackTable slot `0x0069b3fc`, `_wtol`, and the [UID:0003PO][0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables](by-memory/0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables.md) class/tier jump-table data.

## 2026-06-17 Scalar Destructor Wrapper Split

- B003 split [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) and assigned the exact `0x004ce430-0x004ce4fb` wrapper to [UID:0003YX][0x004ce430-0x004ce4fb.ItemHelpPaneScalarDeletingDestructor](by-memory/0x004ce430-0x004ce4fb.ItemHelpPaneScalarDeletingDestructor.md) at `87/92`, owner/emitter [UID:00006U].
- Source-facing name is `virtual ItemHelpPane::~ItemHelpPane()`. `ScalarDeletingDestructor` and secondary/tertiary `this` adjustors are compiler ABI glue and must not be hand-authored.
- The wrapper validates `g_pItemHelpPane` (`dword_69AE04`) cleanup, the 20-entry stat/value text-buffer table at `+0x62c`, and the primary vtable slot at `0x0061ae04`; secondary/tertiary views remain at `+0xa0/+0xa4`.
- Field naming direction from B003: prefer `m_statValueTextBuffers` or `m_statValueRows` for the `+0x62c` table. Avoid generic `m_pItemData` because paint/populate code uses item metadata separately.

## Source Emission Policy

- The complete class declaration is emitted before one extern, one external global definition, every authored child definition, and the close-helper delete. This removes the historical incomplete-type delete defect without making the class page a method-body owner.
- Exact authored definitions remain only on [UID:0003PL][0x004c82d0-0x004c8b13.ItemHelpPaneConstructor](by-memory/0x004c82d0-0x004c8b13.ItemHelpPaneConstructor.md), [UID:0003PM][0x004c8b20-0x004c8bc2.ItemHelpPaneNonDeletingDestructor](by-memory/0x004c8b20-0x004c8bc2.ItemHelpPaneNonDeletingDestructor.md), [UID:0003PN][0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame](by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md), [UID:0003PP][0x004ccc20-0x004ccc3a.ItemHelpPaneOnTimerEvent](by-memory/0x004ccc20-0x004ccc3a.ItemHelpPaneOnTimerEvent.md), [UID:0003PQ][0x004ccc40-0x004ccc7e.ItemHelpPaneOnMouseEvent](by-memory/0x004ccc40-0x004ccc7e.ItemHelpPaneOnMouseEvent.md), [UID:0003PR][0x004ccc80-0x004ccc95.ItemHelpPaneDismissItemHelp](by-memory/0x004ccc80-0x004ccc95.ItemHelpPaneDismissItemHelp.md), [UID:0003PS][0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData](by-memory/0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData.md), and [UID:0003PT][0x004ce100-0x004ce160.ItemHelpPaneCountTextLines](by-memory/0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md), in emitter order `10` through `80`.
- [UID:0003PO][0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables](by-memory/0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables.md), [UID:0003YX][0x004ce430-0x004ce4fb.ItemHelpPaneScalarDeletingDestructor](by-memory/0x004ce430-0x004ce4fb.ItemHelpPaneScalarDeletingDestructor.md), [UID:00025G][0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData](by-memory/0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md), and [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) emit no handwritten body or marker: explicit switches, virtual declarations/methods, literal operands, direct Singleton inheritance, ordinary lifetime code, comparison, and container source regenerate their compiler/linker output.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md)
- [UID:0003PL][0x004c82d0-0x004c8b13.ItemHelpPaneConstructor](by-memory/0x004c82d0-0x004c8b13.ItemHelpPaneConstructor.md)
- [UID:0003PM][0x004c8b20-0x004c8bc2.ItemHelpPaneNonDeletingDestructor](by-memory/0x004c8b20-0x004c8bc2.ItemHelpPaneNonDeletingDestructor.md)
- [UID:0003PN][0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame](by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md)
- [UID:0003PO][0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables](by-memory/0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables.md)
- [UID:0003PP][0x004ccc20-0x004ccc3a.ItemHelpPaneOnTimerEvent](by-memory/0x004ccc20-0x004ccc3a.ItemHelpPaneOnTimerEvent.md)
- [UID:0003PQ][0x004ccc40-0x004ccc7e.ItemHelpPaneOnMouseEvent](by-memory/0x004ccc40-0x004ccc7e.ItemHelpPaneOnMouseEvent.md)
- [UID:0003PR][0x004ccc80-0x004ccc95.ItemHelpPaneDismissItemHelp](by-memory/0x004ccc80-0x004ccc95.ItemHelpPaneDismissItemHelp.md)
- [UID:0003PS][0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData](by-memory/0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData.md)
- [UID:0003PT][0x004ce100-0x004ce160.ItemHelpPaneCountTextLines](by-memory/0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- [UID:0003YX][0x004ce430-0x004ce4fb.ItemHelpPaneScalarDeletingDestructor](by-memory/0x004ce430-0x004ce4fb.ItemHelpPaneScalarDeletingDestructor.md)
- [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)

## Changes

- 2026-06-21 Rule 26 incorporation of B006 [UID:0003PN][0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame](by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md) source-quality report:
  - Added `OnPaintFrame` source-route decision, method declaration direction, display-field map, stat-value row contract, paint behavior, switch-table dependency, and rejected split/abstraction notes.
- 2026-06-30 B004 HelpPanes empty-emitter first batch:
  - Added the accepted no-standalone class marker plus `[[CHILDREN]]` insertion point to the formal block.
  - Preserved exact child ownership for constructor, destructor, paint, jump table, timer, mouse, dismiss, populate, count-lines, and scalar destructor wrapper pages; this class page remains the route/evidence index.
- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Added the inventory-backed help dependency on `LocalInventorySlotRecord` while preserving `MetaMan` as the richer item metadata source.
- Completion/confidence score update: existed before as `0/0`; changed to `86/82`. Summary: rich item-tooltip responsibility, construction/destruction/painting/timer/mouse/dismiss/populate/count helpers, singleton, MetaMan usage, support helper split, storage checks, and caller evidence are documented in detail; confidence remains limited by exact source-file split within HelpPanes. Evidence: `ItemHelpPaneCore`, `HelpTooltipSupportHelpers`, `HelpTooltipDestructorThunks`, `g_pItemHelpPane`, `ItemDialogs`, and `InventoryPane`.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JU][HelpPanes](by-file/HelpPanes.md).
  - Before: reconstruction routing metadata was blank, leaving the rich item-tooltip pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000JU`, and `EMITTER_UIDS:0000JU`; left the C++ block blank because the page is below the final-source code-entry bar.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004c82d0`, `0x004c8b20`, `0x004c8bd0`, `0x004ccc20`, `0x004ccc40`, `0x004ccc80`, `0x004ccca0`, `0x004ce100`, and `0x004ce430`, with constructor callers from inventory/item-help contexts. The class now scores `86/86`, and parent [UID:0000JU][HelpPanes](by-file/HelpPanes.md) scores `90/86`, clearing the strict routing gate.
- 2026-06-14 C001 refreshed low-confidence batch:
  - Before: `COMPLETION:86`, `CONFIDENCE:82`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA MCP reconfirmed method sizes, internal helper call edges, four constructor callers, 20 singleton xrefs, three vtable-head xref sets, item-help literal-table boundaries, and the `HierList` successor. Confidence is now above the strict gate, while final C++ stays blank because field naming and final `HelpPanes.cpp` versus possible `ItemHelpPane.cpp` split remain below the code-entry bar.
- 2026-06-16 B001 source-quality split execution:
  - Score unchanged at `86/86`.
  - Summary/evidence: supervisor executed B001's split recommendation by creating exact child pages for the constructor, non-deleting destructor, paint method, paint jump table, timer handler, mouse handler, dismiss helper, populate method, and line-count helper. [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md) is now a non-emitting migration index; this class remains the direct semantic owner and still emits through [UID:0000JU][HelpPanes](by-file/HelpPanes.md) until a future source-layout pass proves a separate `ItemHelpPane.cpp`.
- 2026-06-17 B003 destructor-wrapper split sync:
  - Added exact scalar wrapper child [UID:0003YX][0x004ce430-0x004ce4fb.ItemHelpPaneScalarDeletingDestructor](by-memory/0x004ce430-0x004ce4fb.ItemHelpPaneScalarDeletingDestructor.md), preserved blank formal C++ policy, and recorded singleton/table/vtable naming details needed for the future class-layout pass.
- 2026-07-21 B004 UID0001PD source-quality callback:
  - Raised the class route from `86/86` to `88/91`, retained owner/emitter UID0000JU, preserved every method, field, child, history, and source-route fact, and installed the bounded forward/extern declaration block without duplicating child method bodies.
  - Corrected the historical HelpPane inheritance direction to direct Pane plus direct empty `Singleton<ItemHelpPane>`, recorded PMD `+0xf8,-1,0`, EventHandler/TimerHandler views `+0xa0/+0xa4`, the implicit singleton publication/clear contract, and the sole external UID0000R9 definition while retaining the full-layout and possible whole-family `ItemHelpPane.cpp` caps.
- 2026-07-21 B004 UID0001PD complete-source callback:
  - Raised `88/91 -> 92/94`, retained owner/emitter UID0000JU, replaced the superseded forward scaffold with the complete C++03 declaration, and closed the class before `[[CHILDREN]]`.
  - Installed exact direct bases, constructor/destructor and six method declarations, natural `0x630` member layout, one extern, source order, child positions `10/20/30/40/50/60/70/80`, and compiler/data/support non-emission boundaries without duplicating a child body.
