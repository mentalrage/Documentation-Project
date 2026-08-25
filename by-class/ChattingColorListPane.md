*** UID:00001S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChattingColorPane;
struct RectBounds;

struct ChattingColorSwatchItem
{
    int row;
    int colorValue;
};

class ChattingColorListPane : public ListPane
{
public:
    ChattingColorListPane(ChattingColorPane *colorPane, bool isForegroundList);
    virtual ~ChattingColorListPane() {}

    void SelectCurrentColor();
    int GetSelectedColorValue();
    int FindIndexByColorValue(int colorValue);
    virtual void DrawItem(
        int row,
        const ChattingColorSwatchItem *item,
        const RectBounds *drawBounds);
    virtual void OnItemSelected(int row, int notify);

private:
    ChattingColorPane *m_pColorPane;
    bool m_isForegroundList;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChattingColorListPane

## Status

- Confidence: strong for exact local child pages through `0x00483490`; low for many later currently attached methods.
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md) or split `social/ChatColorDialog.cpp`
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingColorListPane.cpp`

## Class Purpose

`ChattingColorListPane` is the color swatch list used by the chat color dialog. It selects the current color from a table, finds color entries by value, draws color swatches, and writes the selected color into the owner object's foreground or background color arrays.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:0002G7][0x00482fb0-0x00483206.ChattingColorListPaneConstructor](by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md) | `0x00482fb0-0x00483206` | First-draft-ready constructor at `90/93`; builds the color list pane through `ListPane(8,18,18,18,0,1,16)`, stores `m_pColorPane`/`m_isForegroundList`, represents the 80 swatches as `kChattingColorSwatchValues`, clears background row zero, and appends rows through `ListPane::AddEntry`. The source table covers [UID:0003AV][0x00615460-0x00615560.ChattingColorTableConstants](by-memory/0x00615460-0x00615560.ChattingColorTableConstants.md)'s 0x100-byte / 16-xmmword seed block; that data page must not emit a separate raw object. |
| [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md) | `0x00483210-0x0048325b` | Selects the row matching the owner's current foreground/background color for the active category; first-draft-ready as `SelectCurrentColor()`. |
| [UID:0002G9][0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw](by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md) | `0x00483260-0x0048326f` | First-draft-ready retained `GetSelectedColorValue()` helper at `88/91`; raw body lowers inherited selected row `this+0x134` through indexed `ListPane::GetItem(row)` / `GetEntryAt(row)` (`0x004f3dc0`) and returns `ChattingColorSwatchItem::colorValue`. No modeled function/direct-xref route remains a confidence cap, not a no-code reason. |
| [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) | `0x00483270-0x004832b9` | First-draft-ready `FindIndexByColorValue(int colorValue)`; scans swatch item `colorValue` fields and returns the first matching row or `0` fallback. |
| [UID:0002GB][0x004832c0-0x00483414.ChattingColorListPaneDrawItem](by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md) | `0x004832c0-0x00483414` | `91/94` source-quality `DrawItem(int row, const ChattingColorSwatchItem *item, const RectBounds *drawBounds)`: vtable-only slot `0x00615228`; independent zero-color inset-2 palette `136`; selected full palette `128` plus inset-2 palette `143`; unconditional inset-3 `item->colorValue`; four explicit `InitRectBounds`/`SetMode`/`SetDrawColor`/`g_pfnFillRect` groups; twelve-byte trailing alignment. |
| [UID:0002GC][0x00483420-0x00483487.ChattingColorListPaneOnItemSelected](by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md) | `0x00483420-0x00483487` | Stores selected color into the color owner and refreshes the target. |
| `ScalarDeletingDestructor` | `0x00483b00` | Local deletion helper. |

## UID0002GB DrawItem Source-Quality Incorporation

### Exact target contract

- [UID:0002GB][0x004832c0-0x00483414.ChattingColorListPaneDrawItem](by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md) is one 340-byte source-authored virtual body with current function-byte SHA256 `C9AFE1EFFF38BF2C570E789781598F8EEA90A9CDF51AAF374B97FDC99822CDEB`.
- Vtable cell `0x00615228 -> 0x004832c0` is its sole inbound xref. Empty ordinary callers therefore mean vtable-only dispatch, not dead or compiler-generated code.
- Source signature is `void ChattingColorListPane::DrawItem(int row, const ChattingColorSwatchItem *item, const RectBounds *drawBounds)` with three four-byte explicit arguments and `retn 0x0c`.
- `ChattingColorSwatchItem` is exactly eight bytes: `int row` at `+0x00`, `int colorValue` at `+0x04`. Constructor, selected-value getter, find-index, draw, and OnItemSelected writeback all corroborate this record.
- `ListPane` occupies the base through derived offset `+0x14c`; `m_pColorPane` is the four-byte member at `+0x14c`; `m_isForegroundList` is the one-byte member at `+0x150`; normal x86 tail padding closes the derived object at `+0x154`.

### Rendering behavior and dependencies

1. A zero-valued swatch independently draws inset-2 bounds with palette `136`.
2. A selected row independently draws the full bounds with palette `128`, then inset-2 bounds with palette `143`.
3. Every row unconditionally draws inset-3 bounds with `item->colorValue`.
4. Every fill is the explicit observed sequence `InitRectBounds -> SetMode(1) -> SetDrawColor(color) -> g_pfnFillRect(this, &bounds)`.

- `0x004b7c50` is source-facing `InitRectBounds`; `0x004f3f00` is inherited `IsItemSelected(row)`; `0x005446b0` is inherited `SetMode(1)`; `0x004b9660` is inherited `SetDrawColor(unsigned int)`; `0x0069b3fc` is the typed shared `SurfaceFillRectProc` callback best named `g_pfnFillRect`.
- The twelve bytes `[0x00483414,0x00483420)` are `0xcc` alignment before OnItemSelected and are not a source-bearing child.
- The current source route remains [UID:0000I5][Chatting](by-file/Chatting.md) / `NexusTK/social/Chatting.cpp`. A future color-dialog family split is broader cleanup, not a reason to move this one method now.

### Formal source placement

- The formal CPP channel now owns the complete local-core declaration required before child bodies: forward declarations, exact eight-byte `ChattingColorSwatchItem`, `ChattingColorListPane : public ListPane`, constructor/destructor, local methods, matching virtual `DrawItem(...)`, `OnItemSelected(...)`, exact two known members, then `[[CHILDREN]]` after the closed class.
- Formal H remains intentionally blank. The project currently emits this complete declaration through the class-owner CPP route; duplicating a partial class or a free method prototype in H would be invalid or conflict with the child emitter.
- UID0002GB owns only the out-of-line body in its own formal CPP channel. It must not duplicate the item/class declaration.

### Positive, negative, and inference evidence

- Positive evidence combines exact bytes/range, vtable routing, stack ABI, four repeated call groups, typed global callback state, constructor/item consumers, neighboring class methods, and current owner/emitter/source metadata.
- `ChattingColorSwatchItem`, `colorValue`, `row`, `drawBounds`, `bounds`, `InitRectBounds`, `IsItemSelected`, `SetMode`, `SetDrawColor`, and `g_pfnFillRect` are human source spellings supported by role and project vocabulary. Exact original spelling remains inferred where symbols are lost, but raw IDA names are not suitable final source.
- Reject the prior compressed `FillPaletteRect`/`InsetRectBounds` target draft: neither helper is called by this body, and compression hides four observed mode/color/callback transitions.
- Reject added null/range/callback/clipping guards, ownership by `ChattingColorPane` or base `ListPane`, a free-helper interpretation, and a one-method source split. None is present in the executable.
- Historical Wave2/Wave3, raw `sub_`/`dword_` labels, blank-C++ language, and the B002 compressed draft remain historical evidence only. They do not override the current source-quality result.
- Class score remains `86/88`: UID0002GB is locally closed at `91/94`, but later attached board/article/item-menu/user-list methods remain known wrong-owner pollution and require separate cleanup.

## Data Notes

- Wave3 currently attaches 42 methods to this class, including many methods from board/article, item menu, user list, and other domains.
- Treat only the exact local `0x00482fb0-0x00483490` child pages and destructor/thunks as strong chat color-list ownership until a caller/owner pass cleans up the rest.
- `0x00574510` is currently emitted as `ChattingColorListPane::ApplySelectedColor`, but a 2026-05-24 IDA MCP recheck shows only `ServerSelectPane::OnDialogAction` callers and server-select packet/config behavior. Treat it as [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md), not chat-color code.
- `ClientSpellMenuDialog::UpdateActionButtonState` currently uses a generated local `ChattingColorListPane*` spelling for its child-slot `6` list pointer. 2026-05-24 IDA evidence shows that pointer is a spell-list object from [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md), not this class.
- `0x0051f450` is currently emitted as `ChattingColorListPane::ShowBuyConfirmDialog`, but a 2026-05-24 IDA MCP recheck shows it creates `ArgumentedItemConfirmInputDialogPane` from selected argumented menu-entry fields. Treat it as an [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md), not chat-color code.
- B002 2026-06-17 source-quality reanalysis resolves local field and item roles:
  - `+0x14c`: `m_pColorPane`, owning `ChattingColorPane`.
  - `+0x150`: `m_isForegroundList`; nonzero selects/writes owner `m_chatColorForeground`, zero selects/writes owner `m_chatColorBackground`.
  - List item offset `+0x04`: `ChattingColorSwatchItem::colorValue`.
  - The secondary/background list deliberately zeroes swatch index `0`, making that entry the default/empty background color choice.
- B005 2026-06-21 Rule 26 incorporation resolves [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md) as first-draft C++ ready at `87/91`. The method reads `m_pColorPane->m_selectedChatColorCategory`, chooses `m_chatColorForeground` when `m_isForegroundList` is nonzero and `m_chatColorBackground` when it is zero, calls [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md), then dispatches the inherited `ListPane` slot `+0x78` as source-facing `SetSelectedIndex(row, false)`. Exact inherited spelling may later standardize as `SelectItem`, `SetSelectedIndex`, or `OnItemSelected`, but raw `[vtable+0x78]` should not appear in emitted target C++.
- B007 2026-06-19 source-quality reanalysis resolves [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) as first-draft C++ ready at `87/92`. It uses `ListPane::GetItemCount()` and the indexed `ListPane::GetItem(row)` / `GetEntryAt(row)` helper to scan `ChattingColorSwatchItem::colorValue` at item offset `+0x04`, returning the first matching row or `0` as the default/fallback row. `0x004f3dc0` should not be described as selected-entry-only in color-list docs: it tail-dispatches the primary list's indexed getter, and callers decide whether the index is the selected row or an explicit loop/validated row.
- B014 2026-06-19 source-quality verification independently confirms the current [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) disposition without changing class score: `FindIndexByColorValue(int colorValue)` is a source-authored color-list method, direct callers are only the two [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md) sites, `ListPane::GetItemCount()` and indexed `ListPane::GetItem(row)` are inherited helpers, item `+0x04` is `ChattingColorSwatchItem::colorValue`, row `0` is the intentional empty/no-match fallback, and a future `social/ChatColorDialog.cpp` split remains broader source-tree cleanup rather than a blocker for this class.
- B010 2026-06-29 implementation resolves the [UID:0002G7][0x00482fb0-0x00483206.ChattingColorListPaneConstructor](by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md) empty-emitter blocker without changing class score. Current MCP database `B006_0002F1_20260629` reconfirmed the exact constructor bounds, the two [UID:0002FX][0x004824e0-0x00482b01.ChattingColorPaneConstructor](by-memory/0x004824e0-0x00482b01.ChattingColorPaneConstructor.md) call sites at `0x00482837/0x0048295d`, foreground/background child stores at owner `+0x270/+0x274`, `m_pColorPane` at list `+0x14c`, `m_isForegroundList` at list `+0x150`, the three class vtable writes as compiler output, and the `ListPane::AddEntry` append loop. Source-facing constructor C++ now uses a `static const int kChattingColorSwatchValues[80]`; row zero is overwritten with `0` only for the background list. The first `ChattingColorSwatchItem` dword remains aggregate-initialized with the row index rather than overnamed; `colorValue` at item `+0x04` remains the proven field.
- B011 2026-07-04 UID0003AV support sync keeps the color constants as source-declared/generated-binary covered-by data, not a standalone class data object. Current MCP session `aa3930bd` proves [UID:0003AV][0x00615460-0x00615560.ChattingColorTableConstants](by-memory/0x00615460-0x00615560.ChattingColorTableConstants.md) is a 0x100-byte / 16-xmmword / 64-dword seed-vector block; every vector address has exactly one data xref and all are inside [UID:0002G7][0x00482fb0-0x00483206.ChattingColorListPaneConstructor](by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md). The constructor-local `kChattingColorSwatchValues[80]` remains the source-facing representation; reject raw `xmmword_*`, `__m128i[16]`, or `int[64]` C++ on the data page.
- B001 2026-06-29 implementation resolves [UID:0002G9][0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw](by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md) as first-draft-ready retained `int GetSelectedColorValue()` without changing class score. Current MCP session `c9671f69` reconfirmed exact helper bytes `ff b1 34 01 00 00 e8 55 0b 07 00 8b 40 04 c3`, five leading and one trailing `0xcc` padding, no modeled function/direct xrefs/pointer-route hits, selected-index input at inherited `this+0x134`, indexed `0x004f3dc0` item accessor semantics, and `ChattingColorSwatchItem::colorValue` at item `+0x04`. The no-route state is retained as a confidence cap while the child now emits formal C++ through this class.

## Evidence Notes

- IDA MCP confirms exact child bodies at `0x00482fb0-0x00483206`, `0x00483210-0x0048325b`, `0x00483270-0x004832b9`, `0x004832c0-0x00483414`, `0x00483420-0x00483487`, and the scalar deleting destructor at `0x00483b00`.
- IDA raw-byte review confirms the unmodeled helper at `0x00483260-0x0048326f` and `0xcc` alignment gaps at `0x00483206-0x00483210`, `0x0048325b-0x00483260`, `0x0048326f-0x00483270`, `0x004832b9-0x004832c0`, `0x00483414-0x00483420`, and `0x00483487-0x00483490`.
- B002 2026-06-16 reanalysis kept [UID:0002G9][0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw](by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md) as a retained no-route `ChattingColorListPane` helper and inferred the selected item record as `ChattingColorSwatchItem`/`ChattingColorListItem`; item offset `+0x04` was best named `colorValue`, validated by find-index comparisons and selected-item writes to the owner color table. B001 2026-06-29 implementation accepts the stronger source-facing model: retained first-draft `GetSelectedColorValue()` uses inherited selected row `this+0x134`, `ListPane::GetItem(row)` / `GetSelectedItem()` lowering, and `ChattingColorSwatchItem::colorValue`; no modeled function/direct-xref exposure remains a confidence cap rather than an empty-C++ blocker.
- IDA vtable data points `0x00615220` to `0x00483420` and `0x00615228` to `0x004832c0`, confirming the selected-item and draw-item virtual ownership.
- B005 local PE/Capstone recheck of [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md) found direct rel32 refs from [UID:0002G1][0x00482c60-0x00482c9f.ChattingColorPaneSyncColorListsToCategoryRaw](by-memory/0x00482c60-0x00482c9f.ChattingColorPaneSyncColorListsToCategoryRaw.md) at `0x00482c8c/0x00482c98` and [UID:0002G6][0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged](by-memory/0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged.md) at `0x00482f90/0x00482f9b`, with no VA/RVA pointer refs to the target start. The final selection dispatch is inherited ListPane slot `+0x78` rather than a new color-list vtable entry.
- B007 local PE byte recheck of [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) confirmed one leading `0xcc`, seven trailing `0xcc`, only two direct call sites from [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md) at `0x00483236/0x0048324d`, `ListPane::GetItemCount` calls at `0x00483279/0x00483299`, and an indexed `ListPane::GetItem` call at `0x00483289`. The no-match/empty-list return stays `0`, not `-1`, because [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md) immediately uses the result as the row passed to the inherited selection update.
- B014 PE-section verification of the same [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) range corroborates the B007 facts and adds that no absolute VA/RVA pointer refs to `0x00483270` were found, preserving direct helper reachability through [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md) rather than vtable/table dispatch.
- IDA xrefs to the constructor are only the two `ChattingColorPane` constructor allocation sites at `0x00482837` and `0x0048295d`.
- The constructor uses constants near `0x00615460-0x00615550` to build the 80-entry color table, then zeroes index `0` for the secondary list.
- B011 reclassifies those constants precisely as [UID:0003AV][0x00615460-0x00615560.ChattingColorTableConstants](by-memory/0x00615460-0x00615560.ChattingColorTableConstants.md)'s 0x100-byte / 16-xmmword seed block, covered by the constructor table rather than emitted as a class-owned raw data object.
- Generated source for the local core uses color-table and color-owner fields consistent with chat color customization.
- IDA MCP confirms `0x00574510` at the later address is real code, but ownership belongs to the server-select cluster by caller and data-flow evidence.
- IDA MCP confirms `0x0051f450` is a real function of size `0xae`; `xrefs_to` reports no direct callers in the current IDB, and decompilation is an argumented buy-confirm path.
- `xrefs_to 0x00482fb0` reports chat-color pane constructor callers at `0x00482837` and `0x0048295d`; no spell-menu constructor path reaches the real chat color-list constructor.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:00001T][ChattingColorPane](by-class/ChattingColorPane.md)
- [UID:00001U][ChattingColorSelectPane](by-class/ChattingColorSelectPane.md)
- [UID:0002G7][0x00482fb0-0x00483206.ChattingColorListPaneConstructor](by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md)
- [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md)
- [UID:0002G9][0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw](by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md)
- [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md)
- [UID:0002GB][0x004832c0-0x00483414.ChattingColorListPaneDrawItem](by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md)
- [UID:0002GC][0x00483420-0x00483487.ChattingColorListPaneOnItemSelected](by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md)
- [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md)

## Changes

- What existed before: the page documented the reliable chat color-list core and several wrong-owner generated attachments, but metadata remained `0/0`.
- What it was changed to: scores were set to `74/78`.
- Summary and evidence: local color-list methods, constructor callers, and polluted helper exclusions are documented; confidence is capped by the still-polluted generated file and remaining owner cleanup.
- 2026-05-31: Updated completion/confidence from `74/78` to `86/88`.
  - Before: the reliable local core was summarized as a broad `0x00482fb0-0x00483486` range with method starts only.
  - After: exact by-memory child pages cover the constructor, select-current helper, raw selected-color accessor, find-index helper, draw-item virtual, selected-item virtual, and internal padding through `0x00483490`.
  - Summary and evidence: IDA MCP function iteration, decompilation, xref review, vtable-slot review, color-table constant review, and raw byte audit support the split; confidence remains below 100 because later generated class attachments remain polluted and destructor/thunk cleanup still needs a focused pass.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE` and attached the class to [UID:0000I5][Chatting](by-file/Chatting.md). Current IDA MCP `lookup_funcs` reconfirmed constructor/select/find/draw/selected/destructor starts at `0x00482fb0`, `0x00483210`, `0x00483270`, `0x004832c0`, `0x00483420`, and `0x00483b00`, and `callers` shows construction from the chat-color dialog path. Both class (`86/88`) and file (`83/87`) clear the 80+ attachment gate; reconstruction C++ remains blank because generated owner pollution and final field names are still unresolved.
- 2026-06-16: Added B002 selected-color item/value inference for [UID:0002G9][0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw](by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md); class score unchanged.
- 2026-06-17 B002 DrawItem/OnItemSelected execution: no class score change. [UID:0002GB][0x004832c0-0x00483414.ChattingColorListPaneDrawItem](by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md) and [UID:0002GC][0x00483420-0x00483487.ChattingColorListPaneOnItemSelected](by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md) now carry first-draft C++, and their support evidence resolves `m_isForegroundList`, `m_pColorPane`, `ChattingColorSwatchItem::colorValue`, foreground/background owner arrays, and default/empty background swatch semantics.
- 2026-06-21 B005 Rule 26 incorporation: no class score change. [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md) is now `87/91` with first-draft `SelectCurrentColor()` C++; [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) is now `86/91` with first-draft `FindIndexByColorValue(int colorValue)` support. Current caveats are exact inherited `ListPane` helper spellings and possible future `social/ChatColorDialog.cpp` file split, not color-list ownership.
- 2026-06-21 B007 Rule 26 incorporation: no class score change. [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) is now `87/92`; B007's local PE byte and helper-role reanalysis confirms indexed `ListPane::GetItem(row)`, `ChattingColorSwatchItem::colorValue`, zero fallback/default-row semantics, and rejects selected-entry-only naming for `0x004f3dc0`.
- 2026-06-22 B014 Rule 26 verification: no class score or C++ change. B014 independently confirmed the already-incorporated [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) source route, helper roles, `colorValue` item field, row-zero fallback, no pointer/vtable route, and rejected alternative owners/types/names.
- 2026-06-29 B010 constructor empty-emitter implementation: no class score change. [UID:0002G7][0x00482fb0-0x00483206.ChattingColorListPaneConstructor](by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md) is now `90/93` with first-draft formal constructor C++ under the current [UID:0000I5][Chatting](by-file/Chatting.md) / `NexusTK/social/Chatting.cpp` route. Accepted details include the base `ListPane(8,18,18,18,0,1,16)` setup, `m_pColorPane`, `m_isForegroundList`, `kChattingColorSwatchValues[80]`, background row-zero clear, `ListPane::AddEntry`, and rejected alternatives against a `ChattingColorPane`, `ListPane`, or new `ChatColorDialog.cpp` owner move in this callback.
- 2026-07-04 B011 UID0003AV support sync: no class score change. [UID:0003AV][0x00615460-0x00615560.ChattingColorTableConstants](by-memory/0x00615460-0x00615560.ChattingColorTableConstants.md) is now documented as the exact 0x100-byte / 16-xmmword seed block covered by this constructor's `kChattingColorSwatchValues[80]` source table. The data page remains Chatting-routed source-declared/generated-binary support, not a standalone `ChattingColorListPane` raw array or `xmmword_*` emitter.
- 2026-06-29 B001 [UID:0002G9][0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw](by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md) empty-emitter implementation: no class score change. The retained raw helper is now `88/91` with first-draft formal `int ChattingColorListPane::GetSelectedColorValue()` under this class and the current [UID:0000I5][Chatting](by-file/Chatting.md) route. Accepted details include current MCP session `c9671f69`, exact bytes/signature, padding, no-function/no-xref/no-pointer confidence cap, selected-index lowering through `this+0x134`, indexed `0x004f3dc0` accessor role, `ChattingColorSwatchItem::colorValue`, and rejection of continued blank no-code treatment for this source-authored retained helper.
- 2026-08-06 B008 UID0002GB Rule 26 callback: kept class score `86/88`, owner/emitter [UID:0000I5][Chatting](by-file/Chatting.md), and blank formal H while populating formal CPP with the complete local-core declaration and `[[CHILDREN]]` route. Added the exact eight-byte `ChattingColorSwatchItem`, derived member offsets/size, matching virtual `DrawItem(...)` declaration, UID0002GB `91/94` range/hash/ABI/vtable/item/rendering/callback/padding evidence, explicit helper names, source placement, positive/negative inference, and the rejection of the prior compressed helper draft. Existing wrong-owner attachment history remains intact and continues to cap the class score.
