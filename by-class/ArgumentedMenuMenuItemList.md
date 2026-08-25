*** UID:00000I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ArgumentedItemQuantityInputDialogPane;
class ArgumentedItemConfirmInputDialogPane;

struct ArgumentedMenuItemEntry
{
    unsigned short itemId;
    unsigned char itemStyle;
    unsigned int price;
    wchar_t name[0x100];
    wchar_t description[0x100];
    unsigned int argumentId;
    unsigned int maxQuantity;
};

class ArgumentedMenuMenuItemList : public ListPane
{
public:
    ArgumentedMenuMenuItemList(
        unsigned char commandType,
        unsigned int ownerId,
        unsigned short listParameter,
        ArgumentedMenuMenuDialog *ownerDialog);
    ArgumentedMenuMenuItemList(
        const ArgumentedMenuMenuItemList &source);
    virtual ~ArgumentedMenuMenuItemList();

    void AppendItem(unsigned short itemId,
                    unsigned char itemStyle,
                    unsigned int price,
                    const wchar_t *name,
                    const wchar_t *description,
                    unsigned int argumentId,
                    unsigned char maxQuantity);
    const ArgumentedMenuItemEntry *GetSelectedEntry() const;

protected:
    virtual void OnItemSelected(int rowIndex, int notify);
    virtual void OnItemActivated();
    virtual bool OnMouseEvent(MouseEvent *event);
    virtual void DrawListEntry(int rowIndex, void *rowData,
                               RectBounds *rowBounds);

private:
    friend class ArgumentedItemQuantityInputDialogPane;
    friend class ArgumentedItemConfirmInputDialogPane;

    void OpenBuyConfirmDialog();
    void OpenQuantityDialogOrSendSingle(
        unsigned int maxQuantity,
        unsigned int argumentId);
    void SendArgumentedItemQuantityPacket(
        unsigned int argumentId,
        unsigned char quantity);

    unsigned char m_commandType;
    unsigned int m_ownerId;
    unsigned short m_listParameter;
    ArgumentedMenuMenuDialog *m_ownerDialog;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ArgumentedMenuMenuItemList

## Status

- Confidence: strong for exact child pages, vtable slots, constructor callers, list role, source-file ownership, and rejected input-dialog ownership for purchase helpers.
- Current source file: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md); the former possible fold into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) is historical packaging uncertainty.
- Main address range: [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- Destructor/thunk range: [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)
- Autogen parent: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), position `20`.
- Documentation basis: linked by-file owner, exact by-memory children [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md)-[UID:0003VO][0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem](by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md), destructor/thunk support pages, non-emitting item-helper index, and vtable-family page.

## Class Purpose

`ArgumentedMenuMenuItemList` is the specialized `ListPane` for argumented item menu rows. It tracks the dialog command type, owner dialog id, list parameter, and owner dialog pointer. It updates the description text for the selected item, handles item-help hover behavior, and draws icon/name/count/price or percent metadata for each row.

## Class Shape

- Base family: specialized `ListPane` used by argumented menu dialogs.
- Owned context: command type at `+0x14c`, owner id at `+0x150`, list parameter at `+0x154`, and owner dialog pointer at `+0x158` are documented by the related packet helper.
- UI role: selection updates description text and item-help state; draw path renders icon/name/count/price/percent row metadata.
- Vtable layout: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) records primary table `0x0061f4c4`, secondary table `0x0061f54c`, tertiary table `0x0061f57c`, the larger list-pane shape of 33 primary slots, 11 secondary slots, and 2 tertiary slots, and constructor/store xrefs back to `0x0051e9a0` and `0x0051f290`.
- Destructor layout: primary vtable slot `0x0061f4c4` points to [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md); secondary slot `0x0061f54c` points to [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md) thunk `0x00520abb` (`this -= 0xa0`); tertiary slot `0x0061f57c` points to thunk `0x00520ac6` (`this -= 0xa4`). Source C++ should use an ordinary/defaulted virtual destructor declaration when the class declaration is populated, not emitted `sub ecx` adjustor bodies or a hand-ported scalar deleting wrapper.
- Source placement: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), with this class at emitter position `20` and exact source-bearing children routed through its `[[CHILDREN]]` marker.

## Row Layout

The argumented menu list row is a `0x410`-byte record. Source-facing name `ArgumentedMenuItemEntry` is descriptive/inferred but is now strong enough for first-draft child C++.

| Offset | Field direction | Consumers |
| ---: | --- | --- |
| `+0x000` | `itemId` word | [UID:0003VO][0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem](by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md) item-image lookup/draw. |
| `+0x002` | `itemStyle` byte | Draw helper style/type input. |
| `+0x004` | `price` dword | Buy-confirm helper, draw `%u` formatting, comma insertion, and `1gold` prefix behavior when quantity is greater than one. |
| `+0x008` | `name[0x100]` | Draw row label and [UID:0003VN][0x0051f720-0x0051f840.ArgumentedMenuMenuItemListHandleMouseEvent](by-memory/0x0051f720-0x0051f840.ArgumentedMenuMenuItemListHandleMouseEvent.md) item-help display text. |
| `+0x208` | `description[0x100]` | [UID:0003VK][0x0051f5b0-0x0051f63d.ArgumentedMenuMenuItemListSelectItemAndUpdateText](by-memory/0x0051f5b0-0x0051f63d.ArgumentedMenuMenuItemListSelectItemAndUpdateText.md) owner description/control id `7` update. |
| `+0x408` | `argumentId` dword | [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md), [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md), and [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md) helpers. |
| `+0x40c` | `maxQuantity` dword, zero-extended from byte argument | Draw count display, buy-confirm/quantity prompt path, and direct packet quantity gate. |

[UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md) writes the same offsets from seven stack arguments and then calls `ListPane::AddEntry` at `0x004f3c50`. The owning dialog also builds the same record inline at `0x0051ed05-0x0051ed79`, which supports treating the raw retained helper as source-shaped `AppendItem` rather than dead padding or compiler glue. Do not model a separate row percent field from the `L"(%d%%)"` display-name decoration; that byte is folded into the display string before insertion.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md) | context copy constructor | Constructs/copies list-pane state from an existing source list state. |
| [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md) | retained explicit-context constructor overload | Raw source-shaped `ArgumentedMenuMenuItemList(unsigned char commandType, unsigned int ownerId, unsigned short listParameter, ArgumentedMenuMenuDialog *ownerDialog)` overload; no direct start refs or pointer hits, but source shape is resolved and it now emits guarded first-draft C++. |
| [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md) | `AppendItem` / retained raw append-entry helper | Builds `ArgumentedMenuItemEntry`, copies name/description strings, and appends the row through `ListPane::AddEntry`; no direct raw-start refs remain, but first-draft C++ now emits from the exact child. |
| [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md) | buy-confirm helper | Selected-row helper that constructs `ArgumentedItemConfirmInputDialogPane`; input pane is a callee, not the owner. |
| [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md) | quantity-or-send helper | Sends quantity `1` or constructs `ArgumentedItemQuantityInputDialogPane`; input pane is a callee, not the owner. |
| [UID:0003VK][0x0051f5b0-0x0051f63d.ArgumentedMenuMenuItemListSelectItemAndUpdateText](by-memory/0x0051f5b0-0x0051f63d.ArgumentedMenuMenuItemListSelectItemAndUpdateText.md) | `OnItemSelected` | Accepted ListPane inherited-slot override; selects a row, updates owner control id `7` from `ArgumentedMenuItemEntry::description`, and delegates to `ListPane::OnItemSelected`. |
| [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md) | quantity packet helper | Serializes the opcode `0x39` item quantity packet from this list context. |
| [UID:0003VM][0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate](by-memory/0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate.md) | `OnItemActivated` | Accepted ListPane inherited-slot override; loads `m_ownerDialog` and tail-forwards to `DialogPane::ActivateFocusedControl`. |
| [UID:0003VN][0x0051f720-0x0051f840.ArgumentedMenuMenuItemListHandleMouseEvent](by-memory/0x0051f720-0x0051f840.ArgumentedMenuMenuItemListHandleMouseEvent.md) | `OnMouseEvent` | ListPane mouse-event override; handles event `1`/`4`, row hit testing, active-help dismissal, EPF-gated `ItemHelpPane` replacement, and base fallback. |
| [UID:0003VO][0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem](by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md) | `DrawListEntry` | Accepted ListPane inherited-slot override; draws item icon, name, quantity, comma-grouped price, and the conditional `1gold` prefix without a separate percent field. |
| [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md) | vtable adjustor thunks | Compiler-generated this-adjustors forwarding to the destructor. |
| [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md) | scalar deleting destructor | Compiler-generated deleting-destructor wrapper for the class teardown path. |

## Evidence Notes

- The linked by-file, by-memory, by-item, and by-type pages agree that this is the specialized list-pane implementation for argumented item dialogs, including selection text updates and contextual help-pane behavior.
- [UID:0003VM][0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate](by-memory/0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate.md) is the exact source-bearing `OnItemActivated` override at `[0x0051f710,0x0051f71b)`. Its bytes are `8b 89 58 01 00 00 e9 55 e7 f7 ff` (SHA256 `773941C48827A5DF25122D29ACA0F8BBCE0002DD613701BB2E0A3C8CF46BA741`): load four-byte `ArgumentedMenuMenuDialog *m_ownerDialog` from `+0x158`, then tail-jump to `DialogPane::ActivateFocusedControl` at `0x0049de70`.
- The target is primary vtable cell `0x0061f540`, slot index 31 / offset `+0x7c` from base `0x0061f4c4`. Base `ListPane` dispatcher event case `2` invokes selection slot `+0x78` at `0x004f427d` and activation slot `+0x7c` at `0x004f4284`, proving live indirect activation dispatch. UID0003VM has zero incoming code xrefs and one incoming data xref, `0x0061f540 -> 0x0051f710`; lack of direct callers is therefore not a liveness defect.
- UID0003VM's exact ten-byte prepad `[0x0051f706,0x0051f710)` and five-byte postpad `[0x0051f71b,0x0051f720)` remain ignored padding. Its formal CPP body and this page's sole `virtual void OnItemActivated();` declaration already express the complete source shape, so no class source change, duplicate declaration, split, or compiler-only treatment is required.
- IDA MCP confirms all modeled method starts. B001 2026-06-16 confirms `0x0051f310-0x0051f37a` is real raw `ArgumentedMenuMenuItemList` constructor/context-copy code with no entry refs; B002 2026-06-20 rechecked the local PE bytes and resolved it as an explicit-context constructor overload whose source-facing signature is `ArgumentedMenuMenuItemList(unsigned char commandType, unsigned int ownerId, unsigned short listParameter, ArgumentedMenuMenuDialog *ownerDialog)`. It calls `ListPane::ListPane(0x410, 0x10, 0x16a, 0x18, 0, 1, 1)`, stores `m_commandType`, `m_ownerId`, `m_listParameter`, and `m_ownerDialog`, installs the `0x0061f4c4/0x0061f54c/0x0061f57c` vtables, returns `this`, and remains exact child [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md), not padding and not a blocker.
- 2026-06-03 restarted IDA MCP recheck confirms the constructor at `0x0051f290-0x0051f30b`, list methods at `0x0051f5b0`, `0x0051f710`, `0x0051f720`, and `0x0051f840`, and no function at `0x0051f310`.
- The primary list vtable at `0x0061f4c4` points selection/draw slots to `0x0051f720` and `0x0051f840`, while secondary/tertiary vtable bases `0x0061f54c` and `0x0061f57c` share the constructor/destructor write sites.
- [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) is now `82/86`, staged at `auto-generated/NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp`, and records this class as attached child position `20`.
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) lists this class's constructor, selection update, tiny state forwarder, mouse/help behavior, and draw method in the contiguous argumented-menu aggregate.
- Constructor callers are in the argumented confirm/input flow at `0x0051feec` and `0x00520347`, while the owning dialog builds an equivalent list object inline during packet construction.
- `SendArgumentedItemQuantityPacket` at `0x0051f640` consumes this list's command type, owner id, selected item argument, and owner dialog pointer fields.
- The source-facing context field names are now stabilized across [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md), [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md), and [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md): `m_commandType` byte at `+0x14c`, `m_ownerId` dword at `+0x150`, `m_listParameter` word at `+0x154`, and `m_ownerDialog` pointer at `+0x158`. The `0x410` list-row stride is best kept as a literal until a row-layout by-struct page documents an `ArgumentedMenuMenuItemRow` or equivalent.
- Purchase/quantity helpers [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md), [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md), and [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md) are class/list-context helpers. `ArgumentedItemConfirmInputDialogPane` and `ArgumentedItemQuantityInputDialogPane` are callees or callers, not the canonical source owners for these helper bodies.
- B004 2026-06-20 source-quality incorporation resolves the raw append helper [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md) as inferred/descriptive `ArgumentedMenuMenuItemList::AppendItem(...)`. The local body constructs a `0x410` row, copies `name` and `description` with `_wcscpy_s`, stores `itemId`, `itemStyle`, `price`, `argumentId`, and zero-extended `maxQuantity`, and calls [UID:0003U0][0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md) `ListPane::AddEntry` at `0x004f3c50`. It remains no-direct-start-ref retained code, but that is now a confidence cap rather than a C++ blocker.
- B002 2026-06-25 source-quality implementation confirms that the owning dialog child [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) now emits first-draft constructor C++ that inline-builds the same `ArgumentedMenuItemEntry` row layout and copies the same context fields into `ArgumentedMenuMenuItemList`.
- Historical generated output omitted some excluded helper/thunk bodies even though IDA confirms the thunk functions; keep the IDA-backed destructor/thunk memory page as the durable range anchor.
- 2026-06-11 Batch166 split review added exact non-reconstructable destructor-glue children [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md) and [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md). These pages document the adjustor pair, scalar deleting destructor boundary, vtable refs, and neighboring mixed-island exclusions without treating compiler wrapper bytes as handwritten source.

## Autogen Status

- Reconstructable: true, because this is the source-level argumented menu row-list class that must exist in the rebuilt dialog source.
- Parent: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), position `20`.
- C++: the class CPP block is the child insertion route. Source-bearing child pages emit exact method bodies; [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md) emits the guarded explicit-context constructor, [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md) emits `AppendItem`, and UIDs `0003VK`, `0003VM`, `0003VN`, and `0003VO` emit `OnItemSelected`, `OnItemActivated`, `OnMouseEvent`, and `DrawListEntry`. The H block owns the matching declarations once.

## Score Rationale

- Completion rises because the page now lists every exact source-bearing child in the list tail, the raw context constructor, raw append helper, purchase/quantity helpers, packet helper, vtable methods, destructor support, and ignored glue/padding policy.
- Confidence rises because B001 live IDA MCP and raw PE scans confirm the function inventory, no-function raw children, vtable refs, direct packet-helper refs, and rejected owner routes.
- Confidence remains below final reconstruction quality because some private helper signatures and exact original lexical spellings remain inferred; the row fields, four list virtual identities, and standalone ArgumentedMenuDialogs source route are current and closed.
- The [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md) append-helper row layout is now resolved at first-draft level. Remaining row-name uncertainty is local to final naming, not a blocker for the child emitter.

## Cross-References

- [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)

## Changes

- 2026-08-24 B002 UID0003VM source-quality support incorporation:
  - Added exact `[0x0051f710,0x0051f71b)` bytes/hash, primary `0x0061f540` slot index 31 / `+0x7c`, base ListPane dispatch at `0x004f4284`, `m_ownerDialog` `+0x158` load, `DialogPane::ActivateFocusedControl` tail destination, one-vtable-xref/zero-code-xref liveness, and exact padding disposition.
  - Preserved `91/93`, UID0000HI ownership/position, the existing CPP child route, and the one class-owned `virtual void OnItemActivated();` declaration without source duplication.

- 2026-08-22 B002 UID0000OP Gate 2A repair:
  - Preserved owner/emitter UID0000HI, position `20`, `91/93`, both constructors, row layout, purchase helpers, and all compiler-only dispositions.
  - Added the four matching virtual declarations and reconciled UIDs `0003VK`, `0003VM`, `0003VN`, and `0003VO` as source-bearing `OnItemSelected`, `OnItemActivated`, `OnMouseEvent`, and `DrawListEntry` children. The former blank-marker state and possible TextMenuDialogs fold are historical.

- 2026-08-17 B010 ArgumentedItemInputDialogs dependency closure:
  - Raised `87/89` to `91/93`, established class source position `20`, added the child-definition route, and made this page the single `ArgumentedMenuDialogs.h` owner for `ArgumentedMenuItemEntry` and the complete list-context declaration.
  - The declaration preserves the exact `0x410` row fields and natural padding, the `0x15c` list context, both constructor forms, virtual destructor source shape, append/selection surface, two input-dialog friends, and the three private purchase/quantity helpers.
  - Fresh read-only helper evidence corrects the earlier no-argument draft for `OpenQuantityDialogOrSendSingle`: the retained out-of-line body receives `maxQuantity` and `argumentId` directly. This is a source-signature correction, not a change to the accepted owner or behavior.

- 2026-06-06 provenance cleanup:
  - Before: the status/evidence/rationale wording still used recovered-source and generated-summary framing even though the page already had durable by-* evidence.
  - Changed to: by-file/by-memory/by-item/by-type documentation basis wording, a neutral `0x0051f310` projected non-function label, and durable destructor/thunk memory-page ownership language. Scores and parent attachment were unchanged.
  - Evidence: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md), [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md), [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md), and [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md).
- What existed before: the page had method and caveat evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `70/84`, and a class-shape section was added for base family, owned context offsets, UI role, and source placement.
- Summary and evidence: IDA-confirmed method starts and packet-helper field consumption support strong confidence; the non-function Wave3 method at `0x0051f310` and generated thunk omissions keep completion below high.
- 2026-06-03 parent/evidence update:
  - Before: the class was not attached to a reconstructable file parent despite file/class confidence being above the 80 threshold.
  - Changed to: `72/84`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) at position `20`, with fresh vtable and function-boundary evidence added.
  - Evidence: restarted IDA MCP function checks for list methods, no-function check at `0x0051f310`, vtable slot dump, and constructor caller xrefs.
- 2026-06-06 file-root/vtable evidence update:
  - Before: the class was attached to [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) but still scored `72/84` and did not summarize the stronger file-root, vtable-family, aggregate, and packet-helper evidence.
  - Changed to: `82/86`, with autogen status, vtable layout, aggregate method ownership, packet-helper field evidence, and no-final-C++ rationale added.
  - Evidence: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) is now `82/86` and stages `ArgumentedMenuDialogs.cpp`; [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) records list vtables `0x0061f4c4`, `0x0061f54c`, and `0x0061f57c` plus constructor/store xrefs; [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) lists the list-pane method cluster and `0x0051f310` non-function; [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md) documents packet-helper consumption of the list context fields. Class-level C++ remains blank because exact source-bearing child pages own method bodies.
- 2026-06-11 A002 Batch166 destructor-glue split:
  - Before: `82/86`, with destructor/thunk ranges only listed through the mixed [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) aggregate.
  - Changed to: `85/86`, with exact non-reconstructable children [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md) and [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md).
  - Evidence: live IDA-backed split confirms the `0x00520abb-0x00520ad0` adjustor pair and `0x00520bb0-0x00520c17` scalar deleting destructor as class-specific compiler glue next to unrelated shared/object-image/server-item glue.
- 2026-06-16 B001 supervisor-applied tail split:
  - Changed to: `87/89`, with exact list tail children [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md)-[UID:0003VO][0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem](by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md).
  - Evidence: B001 report-only split audit proved `0x0051f310-0x0051f37a` is real raw constructor/context-copy code, added raw append-entry helper [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md), assigned purchase/quantity helpers [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md), [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md), and [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md) to the list class, and rejected `ArgumentedItemInputDialogs` as canonical owner for those helpers.
- 2026-06-20 B002 Rule 26 source-quality incorporation:
  - Updated [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md) from raw context helper to retained explicit-context constructor overload with guarded first-draft C++.
  - Evidence: local PE/Capstone recheck confirmed `ListPane::ListPane(0x410, 0x10, 0x16a, 0x18, 0, 1, 1)`, `m_commandType`/`m_ownerId`/`m_listParameter`/`m_ownerDialog` stores, no direct refs/pointer hits to `0x0051f310`, owning-dialog inline construction equivalence, and rejected InputDialog/ListPane/copy/destructor/append ownership alternatives.
- 2026-06-20 B004 Rule 26 source-quality incorporation:
  - Added the `ArgumentedMenuItemEntry` row layout and changed [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md) from a blank raw helper to first-draft `AppendItem` child C++.
  - Evidence: B004 local disassembly of the raw helper, inline construction at `0x0051ed05-0x0051ed79`, `ListPane::AddEntry` at `0x004f3c50`, and row consumers [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md)-[UID:0003VO][0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem](by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md).
- 2026-06-20 B005 Rule 26 destructor-route incorporation:
  - Added exact destructor-layout note for primary slot `0x0061f4c4`, secondary/tertiary adjustor slots `0x0061f54c`/`0x0061f57c`, and the source rule that the rebuilt class should express a normal virtual destructor declaration/defaulted destructor while [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md) and [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md) stay non-emitting compiler glue.
  - Evidence: local PE/Capstone recheck in the B005 source-routing report and existing IDA-backed vtable/store docs agree on the slots, stores, thunk jumps, and owner route.
- 2026-06-25 B002 optional support sync:
  - Score unchanged. Recorded that [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) now emits first-draft owning-dialog constructor C++ that inline-builds this class's accepted row layout and list context.
