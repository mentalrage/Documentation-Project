*** UID:0000HI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ArgumentedMenuDialogs

## Status

- Confidence: strong for argumented menu behavior, vtables, factory route, exact dialog child, and `ui/dialogs/` placement; medium only for final physical split versus folding into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md).
- Proposed module: `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp`, or folded into `TextMenuDialogs.cpp`.
- Documentation basis: IDA-confirmed dialog/list ranges, vtable-family evidence, factory xrefs, and linked class/memory/type docs.
- Vtable/layout anchor: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- Exact dialog memory slice: [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md)
- Validator staging target: `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp`.

## File Role

`ArgumentedMenuDialogs.cpp` should own the item-argument variant of server-driven menu dialogs. These classes parse argumented entries with item data, quantity/price fields, description text, help display, and buy-confirm dispatch.

IDA confirms `ArgumentedMenuMenuDialog` vtables at `0x0061f428`, `0x0061f488`, and `0x0061f4b8`, plus `ArgumentedMenuMenuItemList` vtables at `0x0061f4c4`, `0x0061f54c`, and `0x0061f57c`. Earlier staging metadata omitted these vtables; the by-type vtable page and IDA xrefs carry the current evidence.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md) | [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) | Packet-driven argumented item/menu dialog; exact child slice now includes the raw `0x0051f140` caveat. |
| [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md) | `0x0051f290-0x0051fc8c`, destructor island `0x00520abb-0x00520c16` | Specialized argumented item row list and rendering/selection behavior. |

[UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) is the shared creator/dispatcher that allocates `ArgumentedMenuMenuDialog` for packet subtype `10`. Keep the helper adjacent to the broader merchant/menu dialog family.

## 2026-06-10 B001-008 IDA Refresh

Live IDA MCP `py_eval` against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirms the owner-specific vtable child for this file. `ArgumentedMenuMenuDialog` bases `0x0061f428`, `0x0061f488`, and `0x0061f4b8` have complete-object-locator pointers at `0x0061f424`, `0x0061f484`, and `0x0061f4b4`, and constructor stores at `0x0051ea16`, `0x0051ea1c`, and `0x0051ea26`. `ArgumentedMenuMenuItemList` bases `0x0061f4c4`, `0x0061f54c`, and `0x0061f57c` have owner/list/destructor stores at `0x0051eb7f-0x0051eb8f`, `0x0051f2b6-0x0051f2c6`, raw stores near `0x0051f35b-0x0051f393`, and `0x00520bb6-0x00520bc6`. The next named vtable at `0x0061f588` is `ArgumentedItemQuantityInputDialogPane`, which supports keeping the menu dialog/list here and the input panes in [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md).

## Autogen And File-Root Status

- File root: reconstructable by-file root staged by the validator as `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp`.
- Attached children: [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md) at position `10`, [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md) at position `20`, and [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) at position `100`.
- Related but not currently owned here: [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md) is attached to [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) because it constructs or calls the argumented input panes; it remains cross-referenced here because final migration may fold those helpers into the same argumented-menu source family.
- C++: intentionally blank at the file root. The page is an ownership bucket; final code should come from completed child pages only after the `95/95` source gate and final split from `TextMenuDialogs.cpp` are resolved.

## 2026-06-03 IDA Refresh

- Restarted IDA MCP confirms `ArgumentedMenuMenuDialog` functions at `0x0051e9a0-0x0051f136`, `0x0051f160-0x0051f24c`, and `0x0051f250-0x0051f28d`.
- The constructor is reached from packet-dispatch sites `0x00517750` and `0x00517c97`, matching the subtype `10` factory route.
- The dialog primary vtable at `0x0061f428` points command/update slots to `0x0051f160` and `0x0051f250`; secondary/tertiary bases `0x0061f488` and `0x0061f4b8` are written by the constructor.
- The contiguous slice contains a raw, unreferenced code-shaped island at `0x0051f140-0x0051f158`; it is documented in [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) but is not promoted to source-level method identity.
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) now carries `84/87` evidence for decorated vtable symbols, RTTI locator placement, slot counts, inherited `0x00517d80` action-string virtual, constructor/store xrefs, and the boundary before later argumented-input vtables.
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) is already attached to this file root and records the list-pane methods, purchase helper adjacency, and ownership decision for the argumented item-menu sibling of the text menu family.
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) lists `ArgumentedMenuDialogs.cpp` under `NexusTK/ui/dialogs/`, matching the file root's proposed reconstruction path.

## Boundary Notes

Keep [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) adjacent. The confirm/quantity input panes may fold into this file if final migration favors one argumented-menu source.

## Score Rationale

- Completion rises because the page now records the validator-staged file root, attached child ordering, exact dialog child, attached aggregate, vtable-family anchor, subtype factory route, source-tree placement, and related input-helper boundary.
- Confidence rises because independent class, memory, vtable, item-helper, and project-structure pages all support the same `ui/dialogs/ArgumentedMenuDialogs.cpp` owner bucket.
- Confidence remains below final reconstruction quality because final migration may still fold this source into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), the list-pane core still lacks an exact executable child split comparable to the dialog slice, and file-root C++ is not ready.

## Cross-References

- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [ArgumentedMenuDialogVtables](by-type/by-vtable/ArgumentedMenuDialogVtables.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md)
- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)

## Changes

- What existed before: the page identified argumented menu classes, vtables, and factory relationship but had unevaluated scores.
- What it was changed to: scores were set to `70/82`.
- Summary and evidence: menu behavior and vtables are strongly supported; completion/confidence stay moderate because final split from `TextMenuDialogs.cpp` and input-dialog folding remain open.
- 2026-06-03 path/child split update:
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the dialog span was only represented by the broad `ArgumentedMenuDialogs` aggregate.
  - Changed to: `76/84`, path `NexusTK/ui/dialogs/`, and an exact [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md).
  - Evidence: restarted IDA MCP function, constructor-caller, vtable-slot, command-handler, and raw `0x0051f140` disassembly checks.
- 2026-06-06 file-root evidence update:
  - Before: the page had the correct path and exact dialog child, but still scored `76/84` and did not summarize validator staging target/child ordering or the stronger vtable/aggregate/source-tree evidence.
  - Changed to: `82/86`, with file-root validator staging status, attached child order, related input-helper boundary, and score rationale added.
  - Evidence: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) is `84/87` and confirms the argumented dialog/list vtable bases and constructor/store xrefs; [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) is already attached to this root; [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md) and [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md) are attached children; [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `ArgumentedMenuDialogs.cpp` under `NexusTK/ui/dialogs/`. C++ remains blank under the final-source gate.
- 2026-06-06 provenance cleanup:
  - Before: the status and score-rationale prose still described the page in terms of current recovered/staged outputs.
  - Changed to: IDA/by-* documentation basis and validator-staging wording, without changing scores or ownership.
  - Evidence: the same linked dialog/list memory docs, vtable-family page, factory helper, and proposed source-tree entry support the owner bucket; no new final-source C++ was added below the `95/95` gate.
- 2026-06-10 B001-008 ownership-gate refresh:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`.
  - Evidence: live IDA MCP reconfirmed the argumented menu dialog/list vtable bases, complete-object-locator pointers, constructor/list/destructor store xrefs, the inherited `0x00517d80` secondary slot, and the `0x0061f588` boundary before `ArgumentedItemQuantityInputDialogPane`. The new split child [ArgumentedMenuDialogVtables](by-type/by-vtable/ArgumentedMenuDialogVtables.md) is assigned here, making this file root sufficient for the strict `85/85` parent gate while still holding final C++ below the source-code bar.
