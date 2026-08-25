*** UID:00000G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ArgumentedItemInputDialogs.h"

#include "AlertPanes.h"
#include "ArgumentedMenuDialogs.h"
#include "../MainUiGraph.h"
#include "../controls/ButtonControlPane.h"
#include "../controls/EPFImageControlPane.h"
#include "../controls/StaticTextControlPane.h"
#include "../controls/TextEditControlPane.h"
#include "../../localization/LanguageMan.h"
#include "../../map/BackPane.h"

#include <wchar.h>

namespace
{
enum
{
    kConfirmControlIndex = 1,
    kCancelControlIndex = 2,
    kTextEditControlIndex = 4,
    kConfirmButtonId = 14,
    kCancelButtonId = 22,
    kMaximumPurchaseQuantity = 100,
    kQuantityPromptStringId = 246
};
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../core/DialogPane.h"

class ArgumentedMenuMenuItemList;

class ArgumentedItemQuantityInputDialogPane : public DialogPane
{
public:
    ArgumentedItemQuantityInputDialogPane(
        const wchar_t *promptText,
        ArgumentedMenuMenuItemList *menuContext,
        unsigned int argumentId);

    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    ArgumentedMenuMenuItemList *m_menuContext;
    unsigned int m_argumentId;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ArgumentedItemQuantityInputDialogPane

## Status

- Confidence: very strong for behavior, boundaries, constructor callers, vtable/RTTI anchors, exact 0x274 layout, validation constants, packet dispatch, and formal CPP/H route.
- Accepted source file: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md); the former folded alternative is historical.
- Address range: [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md)
- Parent attachment: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) at source position 20; file/class now score `93/94` and `92/94`.
- Historical B008 2026-07-04 limited callback: the aggregate split was known but child creation was outside that callback. UID000554/000555 now supply the exact constructor/action bodies.

## Class Purpose

`ArgumentedItemQuantityInputDialogPane` asks for the quantity to buy after the user has confirmed an argumented item price. It validates the typed quantity, rejects zero and values above 100, and sends the final opcode `0x39` item quantity packet.

## Class Shape

- Base family: command/input dialog pane for argumented item purchase flow.
- Context ownership: copies argumented menu/list context so the final quantity packet can be serialized without depending on transient UI selection state.
- Validation: accepts only quantity values in the documented `1..100` range.
- Dispatch dependency: successful confirm calls `SendArgumentedItemQuantityPacket` at `0x0051f640`.
- Source placement: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), with the same folded-into-argumented-menu caveat as the confirm pane.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0051fc90-0x0051ff6c` | [UID:000554][0x0051fc90-0x0051ff6c.ArgumentedItemQuantityInputDialogPaneConstructor](by-memory/0x0051fc90-0x0051ff6c.ArgumentedItemQuantityInputDialogPaneConstructor.md) | Exact class-owned constructor source, position 10. |
| `0x0051ff70-0x005200c4` | [UID:000555][0x0051ff70-0x005200c4.ArgumentedItemQuantityInputDialogPaneOnControlCommand](by-memory/0x0051ff70-0x005200c4.ArgumentedItemQuantityInputDialogPaneOnControlCommand.md) | Exact `OnControlCommand(int,int)` source, position 20. |

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- Constructor boundary `0x0051fc90-0x0051ff6c`, size `0x2dc`, final `retn 0Ch` at `0x0051ff69`.
- Constructor callers at `0x0051f570` and `0x005204ec`.
- Constructor vtable stores at `0x0051fcec`, `0x0051fcf2`, and `0x0051fcfc` to `??_7ArgumentedItemQuantityInputDialogPane@@6B@` and the secondary quantity-pane vtables.
- Action handler boundary `0x0051ff70-0x005200c4`, size `0x154`, final `retn 8` at `0x005200c1`.
- The action handler is referenced by vtable data at `0x0061f5d0`.
- The action handler parses decimal text, compares the parsed quantity with `0x64` (`100`), uses the `You can't buy more than 100.` and `How much?` alert strings for invalid values, and calls `0x0051f640` at `0x0052008e` for valid nonzero quantities.
- `0x00520046` resolves inside `0x0051ff70-0x005200c4`, so it is not a separate method/function start.

2026-06-16 Agent-C001 IDA MCP refresh confirmed in that historical session:

- `lookup_funcs` before rename still showed raw names `sub_51FC90` and `sub_51FF70`; after a dry-run rename with no conflicts, that C001 IDA session named them `ArgumentedItemQuantityInputDialogPane_Constructor` and `ArgumentedItemQuantityInputDialogPane_OnDialogAction`. Current B008 session `eb7ce28b` again reports raw `sub_*` names, so the constructor/action spellings are documentation/source-facing names rather than current live IDB names.
- `xrefs_to 0x0051fc90` reports constructor callers at `0x0051f570` from the quantity-or-send helper and `0x005204ec` from the confirm action.
- `xrefs_to 0x0051ff70` reports the handler vtable data ref at `0x0061f5d0`.
- Current `.rdata` names bound the quantity vtables at `0x0061f588`, `0x0061f5e8`, and `0x0061f618`, with constructor stores at `0x0051fcec`, `0x0051fcf2`, and `0x0051fcfc`.
- `analyze_component` confirms the handler calls the now-renamed `SendArgumentedItemQuantityPacket`, while the helper/dialog source parent [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) is now `86/89` and the exact memory child [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md) is refreshed to `85/89`.

2026-07-04 Agent-B008 current MCP refresh and limited implementation:

- Active session `eb7ce28b` reports `sub_51FC90` size `0x2dc` and `sub_51FF70` size `0x154`; these are the current live names.
- `xrefs_to 0x0051fc90` reports constructor refs at `0x0051f570` and `0x005204ec`.
- `xrefs_to 0x0051ff70` reports the vtable data ref at `0x0061f5d0`; bytes at the slot contain little-endian `0x0051ff70`.
- UTF-16LE bytes confirm `ArgumentQuantity`, `You can't buy more than 100.`, and `How much?`; the validation limit remains `0x64` / decimal `100` (Verified with `int_convert.py`).
- UID0001BT now carries a formal aggregate `[[CHILDREN]]` route marker. Exact quantity method child pages are deferred by supervisor scope, so this class page remains a support page and does not receive a class declaration or method-body C++ in this callback.

## Historical Source-Quality Blockers And Resolution

- The former blank-C++/file-split blocker is resolved by the accepted standalone module, complete formal CPP/H above, exact method children, and [UID:000556][ArgumentedItemQuantityInputDialogPaneLayout](by-type/by-struct/ArgumentedItemQuantityInputDialogPaneLayout.md).
- `0x0051f450`/`0x0051f510` retain weak direct-start liveness, but exact bodies and UID00000I ownership make that a helper-spelling confidence cap rather than a blocker to this class.
- No derived destructor is authored. `m_menuContext` at `+0x26c` and unsigned `m_argumentId` at `+0x270` close the exact natural 0x274 layout; the observed compiler wrappers perform no pointer cleanup.

## 2026-08-17 B010 Formal Source Closure

- Class tail: `ArgumentedMenuMenuItemList *m_menuContext` at `+0x26c` and `unsigned int m_argumentId` at `+0x270`; natural size `0x274`.
- Three views: primary `0x0061f588`, EventHandler `0x0061f5e8` at `+0xa0`, and TimerHandler `0x0061f618` at `+0xa4`; seven-base RTTI uses type descriptor `0x00677b70`.
- UID000554 preserves full pointer-based EPF/image-button/static-text/text-edit constructor calls and setup order. UID000555 preserves unsigned comparison, over-100 and zero alerts, packet call, null-context path, and unconditional confirm close.
- [UID:00055A][0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData](by-memory/0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData.md), [UID:00055C][ArgumentedItemInputDialogVtables](by-type/by-vtable/ArgumentedItemInputDialogVtables.md), [UID:00055B][0x0061f99c-0x0061fa3c.ArgumentedItemInputDialogStrings](by-memory/0x0061f99c-0x0061fa3c.ArgumentedItemInputDialogStrings.md), and [UID:00055D][argumented-item-input-dialog-resources](by-resource/argumented-item-input-dialog-resources.md) close compiler/data/resource support without duplicate arrays.

## Cross-References

- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)

## Changes

- 2026-06-04: Raised grading from `70/86` to `82/88`, marked `RECONSTRUCTABLE:TRUE`, and attached `AUTOGEN_PARENT_UID:0000HH`.
  - Before: the page relied partly on stale non-live provenance and had no parent attachment.
  - After: live IDA MCP evidence documents exact half-open boundaries, constructor callers, vtable stores, action-handler vtable data ref, validation constants/alerts, the packet-send call, and the false-start status for `0x00520046`.
  - Score rationale: completion and confidence increased because the class can now be reconstructed as part of the argumented item input-dialog module. C++ remains blank because final names/signatures and the file split are still below the 95/95 bar.
- 2026-06-16 Agent-C001: Raised grading from `82/88` to `86/90` and applied the safe IDA function renames for the constructor/action handler.
  - Before: the page had strong behavior evidence but still referenced raw `sub_51FC90` / `sub_51FF70` IDA names and did not record the newer parent/helper support scores.
  - After: the page records the current IDA names, xref set, vtable-store anchors, refreshed support scores, and the remaining final-C++ blockers.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `analyze_component`, dry-run `rename`, verified post-rename lookup, and saved IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- 2026-07-04 Agent-B008 limited callback:
  - Score unchanged at `86/90`; no class C++ was inserted.
  - Synchronized this support page with UID0001BT's aggregate `[[CHILDREN]]` marker, current MCP session `eb7ce28b` raw-name evidence, quantity vtable slot proof, validation strings, and the supervisor-scoped deferral of exact child page creation.
