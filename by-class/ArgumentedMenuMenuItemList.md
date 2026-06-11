*** UID:00000I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArgumentedMenuMenuItemList

## Status

- Confidence: strong for included methods, vtable slots, constructor callers, list role, and source-file ownership; one generated method entry is not an IDA function.
- Likely source file: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), or folded into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- Main address range: [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- Destructor/thunk range: [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)
- Autogen parent: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), position `20`.
- Documentation basis: linked by-file owner, aggregate by-memory range, destructor/thunk memory page, item-helper page, and vtable-family page.

## Class Purpose

`ArgumentedMenuMenuItemList` is the specialized `ListPane` for argumented item menu rows. It tracks the dialog command type, owner dialog id, list parameter, and owner dialog pointer. It updates the description text for the selected item, handles item-help hover behavior, and draws icon/name/count/price or percent metadata for each row.

## Class Shape

- Base family: specialized `ListPane` used by argumented menu dialogs.
- Owned context: command type at `+0x14c`, owner id at `+0x150`, list parameter at `+0x154`, and owner dialog pointer at `+0x158` are documented by the related packet helper.
- UI role: selection updates description text and item-help state; draw path renders icon/name/count/price/percent row metadata.
- Vtable layout: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) records primary table `0x0061f4c4`, secondary table `0x0061f54c`, tertiary table `0x0061f57c`, the larger list-pane shape of 33 primary slots, 11 secondary slots, and 2 tertiary slots, and constructor/store xrefs back to `0x0051e9a0` and `0x0051f290`.
- Source placement: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), or folded into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md).

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0051f290-0x0051f30a` | `ArgumentedMenuMenuItemList` | Constructs/copies list-pane state from an existing source list state. |
| `0x0051f310` | projected non-function | Historical generated metadata listed an excluded method entry here, but IDA MCP reports no function at this address. |
| `0x0051f5b0-0x0051f63c` | `SelectItemAndUpdateText` | Selects a row and updates the dialog description/static text area. |
| `0x0051f710-0x0051f71a` | `ForwardUpdatePendingItemState` | Tiny owner/list state forwarder. |
| `0x0051f720-0x0051f83f` | `HandleMouseEvent` | Handles hover/select behavior and opens contextual `ItemHelpPane` when enabled. |
| `0x0051f840-0x0051fc8c` | `DrawMenuItem` | Draws item icon, name, quantity, price, and percent metadata. |
| `0x00520abb-0x00520ad0` | vtable adjustor thunks | Compiler-generated this-adjustors forwarding to the destructor. |
| `0x00520bb0-0x00520c16` | scalar deleting destructor | Resets vtables, notifies the global argumented-menu pane if present, tears down base list state, and deletes according to flags. |

## Evidence Notes

- The linked by-file, by-memory, by-item, and by-type pages agree that this is the specialized list-pane implementation for argumented item dialogs, including selection text updates and contextual help-pane behavior.
- IDA MCP confirms all included method starts and reports no function at `0x0051f310`.
- 2026-06-03 restarted IDA MCP recheck confirms the constructor at `0x0051f290-0x0051f30b`, list methods at `0x0051f5b0`, `0x0051f710`, `0x0051f720`, and `0x0051f840`, and no function at `0x0051f310`.
- The primary list vtable at `0x0061f4c4` points selection/draw slots to `0x0051f720` and `0x0051f840`, while secondary/tertiary vtable bases `0x0061f54c` and `0x0061f57c` share the constructor/destructor write sites.
- [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) is now `82/86`, staged at `auto-generated/NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp`, and records this class as attached child position `20`.
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) lists this class's constructor, selection update, tiny state forwarder, mouse/help behavior, and draw method in the contiguous argumented-menu aggregate.
- Constructor callers are in the argumented confirm/input flow at `0x0051feec` and `0x00520347`, while the owning dialog builds an equivalent list object inline during packet construction.
- `SendArgumentedItemQuantityPacket` at `0x0051f640` consumes this list's command type, owner id, selected item argument, and owner dialog pointer fields.
- Historical generated output omitted some excluded helper/thunk bodies even though IDA confirms the thunk functions; keep the IDA-backed destructor/thunk memory page as the durable range anchor.

## Autogen Status

- Reconstructable: true, because this is the source-level argumented menu row-list class that must exist in the rebuilt dialog source.
- Parent: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), position `20`.
- C++: intentionally blank. The class is below the `95/95` final-source gate, the exact row/member layout remains incomplete, and the list-pane core still needs exact child pages comparable to [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md).

## Score Rationale

- Completion rises because the page now records the current file-root parent status, vtable-family slot shape, aggregate method ownership, packet-helper field consumption, the `0x0051f310` non-function exclusion, and no-final-C++ gate.
- Confidence rises because the file page, vtable family, aggregate memory page, and packet-helper page agree on [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) as the current owner bucket.
- Confidence remains below final reconstruction quality because the list-pane methods do not yet have exact by-memory child splits, final row field names are incomplete, and final source split from [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) remains open.

## Cross-References

- [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)

## Changes

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
  - Evidence: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) is now `82/86` and stages `ArgumentedMenuDialogs.cpp`; [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) records list vtables `0x0061f4c4`, `0x0061f54c`, and `0x0061f57c` plus constructor/store xrefs; [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) lists the list-pane method cluster and `0x0051f310` non-function; [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md) documents packet-helper consumption of the list context fields. C++ remains blank under the final-source gate.
