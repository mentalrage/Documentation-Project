*** UID:00000F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ArgumentedItemConfirmInputDialogPane : public DialogPane
{
public:
    ArgumentedItemConfirmInputDialogPane(
        const wchar_t *promptText,
        ArgumentedMenuMenuItemList *menuContext,
        unsigned int maxQuantity,
        unsigned int expectedPrice,
        unsigned int argumentId);

    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    ArgumentedMenuMenuItemList *m_menuContext;
    unsigned int m_maxQuantity;
    unsigned int m_expectedPrice;
    unsigned int m_argumentId;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ArgumentedItemConfirmInputDialogPane

## Status

- Confidence: very strong for behavior, boundaries, constructor callers, vtable/RTTI anchors, exact 0x27c layout, action dispatch, and formal CPP/H route.
- Accepted source file: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md); the former folded alternative is historical.
- Address range: [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md)
- Parent attachment: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) at source position 30; file/class now score `93/94` and `92/94`.
- Historical B008 2026-07-04 limited callback: the aggregate split was known but child creation was outside that callback. UID000557/000558 now supply the exact constructor/action bodies.

## Class Purpose

`ArgumentedItemConfirmInputDialogPane` is the price-confirm dialog opened from an argumented item menu row. It displays a confirmation prompt, reads the typed price, compares it against the expected price from the selected row, and either shows a mismatch alert, sends a quantity-one purchase packet, or opens `ArgumentedItemQuantityInputDialogPane`.

## Class Shape

- Base family: command/input dialog pane for argumented item purchase flow.
- Context ownership: copies an `ArgumentedMenuMenuItemList` context so the final packet can reuse command type, owner id, list parameter, selected argument id, and owner dialog pointer.
- Dispatch dependency: calls `SendArgumentedItemQuantityPacket` directly for quantity `1`, otherwise opens [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md).
- Source placement: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), with an open option to fold into [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md).

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005200d0-0x005203be` | [UID:000557][0x005200d0-0x005203be.ArgumentedItemConfirmInputDialogPaneConstructor](by-memory/0x005200d0-0x005203be.ArgumentedItemConfirmInputDialogPaneConstructor.md) | Exact class-owned constructor source, position 10. |
| `0x005203c0-0x00520539` | [UID:000558][0x005203c0-0x00520539.ArgumentedItemConfirmInputDialogPaneOnControlCommand](by-memory/0x005203c0-0x00520539.ArgumentedItemConfirmInputDialogPaneOnControlCommand.md) | Exact `OnControlCommand(int,int)` source, position 20. |

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- Constructor boundary `0x005200d0-0x005203be`, size `0x2ee`, final `retn 14h` at `0x005203bb`.
- Constructor callers at `0x0051f22a` and `0x0051f4de`.
- Constructor vtable stores at `0x00520147`, `0x0052014d`, and `0x00520157` to `??_7ArgumentedItemConfirmInputDialogPane@@6B@` and the secondary confirm-pane vtables.
- Action handler boundary `0x005203c0-0x00520539`, size `0x179`, final `retn 8` at `0x00520536`.
- The action handler is referenced by vtable data at `0x0061f66c`.
- The action handler parses decimal text, compares it with the expected price field, uses the `Price is different.` alert string on mismatch, reads prompt resource id `246` through `dword_67A750` for the quantity dialog, calls `0x0051fc90` for multi-quantity purchases, and calls `0x0051f640` at `0x00520501` for quantity-one purchases.
- The next function starts at `0x00520540` and belongs to `ObjectImageControlPane`, confirming the handler endpoint.

2026-06-16 Agent-C001 IDA MCP refresh confirmed in that historical session:

- `lookup_funcs` before rename still showed raw names `sub_5200D0` and `sub_5203C0`; after a dry-run rename with no conflicts, that C001 IDA session named them `ArgumentedItemConfirmInputDialogPane_Constructor` and `ArgumentedItemConfirmInputDialogPane_OnDialogAction`. Current B008 session `eb7ce28b` again reports raw `sub_*` names, so the constructor/action spellings are documentation/source-facing names rather than current live IDB names.
- `xrefs_to 0x005200d0` reports constructor callers at `0x0051f22a` from the argumented menu command handler and `0x0051f4de` from the buy-confirm helper.
- `xrefs_to 0x005203c0` reports the handler vtable data ref at `0x0061f66c`.
- Current `.rdata` names bound the confirm vtables at `0x0061f624`, `0x0061f684`, and `0x0061f6b4`, with constructor stores at `0x00520147`, `0x0052014d`, and `0x00520157`.
- `analyze_component` confirms the handler calls `SendArgumentedItemQuantityPacket` and the quantity constructor, while the helper/dialog source parent [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) is now `86/89` and the exact memory child [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md) is refreshed to `85/89`.

2026-07-04 Agent-B008 current MCP refresh and limited implementation:

- Active session `eb7ce28b` reports `sub_5200D0` size `0x2ee` and `sub_5203C0` size `0x179`; these are the current live names.
- `xrefs_to 0x005200d0` reports constructor refs at `0x0051f22a` and `0x0051f4de`.
- `xrefs_to 0x005203c0` reports the vtable data ref at `0x0061f66c`; bytes at the slot contain little-endian `0x005203c0`.
- UTF-16LE bytes confirm `ArgumentQuantity` and `Price is different.`; confirm action uses prompt id `0xf6` / decimal `246` and allocation size `0x274` / decimal `628` (Verified with `int_convert.py`) when it opens the quantity input dialog.
- UID0001BT now carries a formal aggregate `[[CHILDREN]]` route marker. Exact confirm method child pages are deferred by supervisor scope, so this class page remains a support page and does not receive a class declaration or method-body C++ in this callback.

## Historical Source-Quality Blockers And Resolution

- The former blank-C++/file-split blocker is resolved by the accepted standalone module, formal declaration above, exact method children, and [UID:000559][ArgumentedItemConfirmInputDialogPaneLayout](by-type/by-struct/ArgumentedItemConfirmInputDialogPaneLayout.md).
- `0x0051f450`/`0x0051f510` weak direct-start liveness remains a private-helper spelling cap only; it does not block this class's exact callers, fields, or runtime paths.
- The exact class tail is now closed. No source destructor cleanup is introduced because compiler-folded wrappers never read/delete the copied list pointer.

## 2026-08-17 B010 Formal Source Closure

- Class tail: copied list context `+0x26c`, maximum quantity `+0x270`, expected price `+0x274`, and argument id `+0x278`; natural size `0x27c`.
- Three views: primary `0x0061f624`, EventHandler `0x0061f684` at `+0xa0`, and TimerHandler `0x0061f6b4` at `+0xa4`; seven-base RTTI uses type descriptor `0x00677ba4`.
- UID000557 preserves full pointer-based control constructors, exact geometry/resources, field stores, copied context, and create/show/slide order. UID000558 preserves null-context return, mismatch alert/no-close behavior, one-item send or quantity-dialog branch, then match/cancel close ordering.
- [UID:00055A][0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData](by-memory/0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData.md), [UID:00055C][ArgumentedItemInputDialogVtables](by-type/by-vtable/ArgumentedItemInputDialogVtables.md), [UID:00055B][0x0061f99c-0x0061fa3c.ArgumentedItemInputDialogStrings](by-memory/0x0061f99c-0x0061fa3c.ArgumentedItemInputDialogStrings.md), and [UID:00055D][argumented-item-input-dialog-resources](by-resource/argumented-item-input-dialog-resources.md) close compiler/data/resource support without duplicate arrays.

## Cross-References

- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)

## Changes

- 2026-06-04: Raised grading from `70/86` to `82/88`, marked `RECONSTRUCTABLE:TRUE`, and attached `AUTOGEN_PARENT_UID:0000HH`.
  - Before: the page relied partly on stale non-live provenance and had no parent attachment.
  - After: live IDA MCP evidence documents exact half-open boundaries, constructor callers, vtable stores, action-handler vtable data ref, price-validation behavior, quantity-dialog dispatch, and the `0x0051f640` packet-send call.
  - Score rationale: completion and confidence increased because the class can now be reconstructed as part of the argumented item input-dialog module. C++ remains blank because final names/signatures and the file split are still below the 95/95 bar.
- 2026-06-16 Agent-C001: Raised grading from `82/88` to `86/90` and applied the safe IDA function renames for the constructor/action handler.
  - Before: the page had strong behavior evidence but still referenced raw `sub_5200D0` / `sub_5203C0` IDA names and did not record the newer parent/helper support scores.
  - After: the page records the current IDA names, xref set, vtable-store anchors, refreshed support scores, and the remaining final-C++ blockers.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `analyze_component`, dry-run `rename`, verified post-rename lookup, and saved IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- 2026-07-04 Agent-B008 limited callback:
  - Score unchanged at `86/90`; no class C++ was inserted.
  - Synchronized this support page with UID0001BT's aggregate `[[CHILDREN]]` marker, current MCP session `eb7ce28b` raw-name evidence, confirm vtable slot proof, price-validation string, quantity-dialog dispatch evidence, and the supervisor-scoped deferral of exact child page creation.
