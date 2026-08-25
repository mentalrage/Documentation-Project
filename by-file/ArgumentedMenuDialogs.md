*** UID:0000HI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ArgumentedMenuDialogs

## Status

- Confidence: strong for argumented menu behavior, vtables, factory route, exact dialog/list children, ignored glue/padding policy, and the closed standalone `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp/.h` placement. The former possible fold into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) is superseded historical uncertainty only.
- Proposed module: exact standalone `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp` with sibling `NexusTK/ui/dialogs/ArgumentedMenuDialogs.h`.
- Documentation basis: IDA-confirmed dialog/list ranges, vtable-family evidence, factory xrefs, and linked class/memory/type docs.
- Vtable/layout anchor: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- Exact dialog/list memory slices: [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md), now a first-draft source-bearing dialog method child, plus `ArgumentedMenuMenuItemList` children [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md)-[UID:0003VO][0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem](by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md).
- Validator staging targets: standalone `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp` and `NexusTK/ui/dialogs/ArgumentedMenuDialogs.h`; no active TextMenuDialogs fold.

## File Role

Standalone `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp/.h` owns the item-argument variant of server-driven menu dialogs. These classes parse argumented entries with item data, quantity/price fields, description text, help display, and buy-confirm dispatch. The former TextMenuDialogs fold question is closed and retained only in dated history below.

IDA confirms `ArgumentedMenuMenuDialog` vtables at `0x0061f428`, `0x0061f488`, and `0x0061f4b8`, plus `ArgumentedMenuMenuItemList` vtables at `0x0061f4c4`, `0x0061f54c`, and `0x0061f57c`. Earlier staging metadata omitted these vtables; the by-type vtable page and IDA xrefs carry the current evidence.

Destructor support for `ArgumentedMenuMenuItemList` is generated ABI glue in [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md) and [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md). Rebuild it from the class declaration and vtable layout here, not by emitting thunk or scalar-deleting-wrapper C++ from those no-code pages.

Shared default dialog destructor note: the `ArgumentedMenuMenuDialog` primary vtable slot `0x0061f428` uses [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md), with secondary/tertiary slots `0x0061f488` and `0x0061f4b8` routed through [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md). This is compiler-generated deleting-destructor glue for the `DialogPane`-derived dialog object; source reconstruction should declare/default the dialog destructor and rely on [UID:0000IT][DialogPane](by-file/DialogPane.md) for ordinary cleanup, not hand-port the wrapper.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md) | [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) | Packet-driven argumented item/menu dialog; exact child emits first-draft constructor/command/update C++ while preserving the raw `0x0051f140` caveat. |
| [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md) | [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md)-[UID:0003VO][0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem](by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md) and destructor support [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md)/[UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md) | Specialized argumented item row list, copied context helpers, retained explicit-context constructor [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md), first-draft append helper [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md), purchase/quantity helpers, packet send helper, rendering/selection/mouse behavior, and compiler-generated destructor support. |

[UID:0003VM][0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate](by-memory/0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate.md) is the exact 11-byte `ArgumentedMenuMenuItemList::OnItemActivated` source child in this standalone module. It occupies primary ListPane slot 31 / `+0x7c`, loads `ArgumentedMenuMenuDialog *m_ownerDialog` from `this+0x158`, and tail-forwards to `DialogPane::ActivateFocusedControl` at `0x0049de70`; UID00000I owns its one CPP definition and H declaration.

[UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) is the shared creator/dispatcher that allocates `ArgumentedMenuMenuDialog` for packet subtype `10` / `kArgumentedItemMenu` using `RectBounds` from `InitDlgMerc1Bounds`. Keep the helper adjacent to the broader merchant/menu dialog family under [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md); this file remains the owner for the concrete argumented dialog/list classes.

## 2026-06-10 B001-008 IDA Refresh

Live IDA MCP `py_eval` against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirms the owner-specific vtable child for this file. `ArgumentedMenuMenuDialog` bases `0x0061f428`, `0x0061f488`, and `0x0061f4b8` have complete-object-locator pointers at `0x0061f424`, `0x0061f484`, and `0x0061f4b4`, and constructor stores at `0x0051ea16`, `0x0051ea1c`, and `0x0051ea26`. `ArgumentedMenuMenuItemList` bases `0x0061f4c4`, `0x0061f54c`, and `0x0061f57c` have owner/list/destructor stores at `0x0051eb7f-0x0051eb8f`, `0x0051f2b6-0x0051f2c6`, raw stores near `0x0051f35b-0x0051f393`, and `0x00520bb6-0x00520bc6`. The next named vtable at `0x0061f588` is `ArgumentedItemQuantityInputDialogPane`, which supports keeping the menu dialog/list here and the input panes in [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md).

## Autogen And File-Root Status

- File root: reconstructable by-file root staged by the validator as standalone `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp` with sibling `NexusTK/ui/dialogs/ArgumentedMenuDialogs.h`; the TextMenuDialogs fold is not an active route.
- Attached children: [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md) at position `10`, [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md) at position `20`, and [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) at position `100`.
- Related non-emitting index: [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md) is attached to [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) because it constructs or calls the argumented input panes. Its source-bearing helper bodies are already routed through UID00000I children in this ArgumentedMenuDialogs owner; no final fold question remains.
- After the 2026-06-16 B001 split, [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md) is a non-emitting cross-reference index. Exact source-bearing purchase/quantity behavior is owned by [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md) through [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md), [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md), and [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md).
- C++: intentionally blank at the file root because this page is the ownership bucket and completed children supply source. [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) emits `ArgumentedMenuMenuDialog` methods; UID00000I routes its declaration and child definitions; [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md) emits the explicit-context constructor; [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md) emits `AppendItem`; and UIDs `0003VK`, `0003VM`, `0003VN`, and `0003VO` emit `OnItemSelected`, `OnItemActivated`, `OnMouseEvent`, and `DrawListEntry`. The current standalone `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp/.h` route supersedes the historical possible TextMenuDialogs fold.

## 2026-06-03 IDA Refresh

- Restarted IDA MCP confirms `ArgumentedMenuMenuDialog` functions at `0x0051e9a0-0x0051f136`, `0x0051f160-0x0051f24c`, and `0x0051f250-0x0051f28d`.
- The constructor is reached from packet-dispatch sites `0x00517750` and `0x00517c97`, matching the subtype `10` factory route.
- The dialog primary vtable at `0x0061f428` points command/update slots to `0x0051f160` and `0x0051f250`; secondary/tertiary bases `0x0061f488` and `0x0061f4b8` are written by the constructor.
- The contiguous slice contains a raw, unreferenced code-shaped island at `0x0051f140-0x0051f158`; it is documented in [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) but is not promoted to source-level method identity.
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) now carries `84/87` evidence for decorated vtable symbols, RTTI locator placement, slot counts, inherited `0x00517d80` action-string virtual, constructor/store xrefs, and the boundary before later argumented-input vtables.
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) is already attached to this file root and records the list-pane methods, purchase helper adjacency, and ownership decision for the argumented item-menu sibling of the text menu family.
- B001 2026-06-16 split audit reclassifies [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) as a non-emitting split index now that exact source-bearing children [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md)-[UID:0003VO][0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem](by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md) and ignored internal padding/glue rows exist.
- B002 2026-06-20 source-quality pass resolves [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md) as a retained explicit-context constructor overload with first-draft C++. It keeps the no-xref/no-pointer liveness caveat, but the constructor source shape, `ListPane::ListPane(0x410, 0x10, 0x16a, 0x18, 0, 1, 1)` base call, `m_commandType`, `m_ownerId`, `m_listParameter`, and `m_ownerDialog` field mapping are no longer open for this child.
- B004 2026-06-20 source-quality pass resolves [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md) as retained out-of-line `AppendItem`. The helper builds a `0x410` `ArgumentedMenuItemEntry` row with `itemId`, `itemStyle`, `price`, `name`, `description`, `argumentId`, and `maxQuantity`, then appends through `ListPane::AddEntry` at `0x004f3c50`; inline row construction at `0x0051ed05-0x0051ed79` proves the same source shape in the live dialog constructor.
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) lists `ArgumentedMenuDialogs.cpp` under `NexusTK/ui/dialogs/`, matching the file root's proposed reconstruction path.

## Boundary Notes

Keep [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) adjacent. Its quantity/confirm constructors and actions call the list-context children [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md) and [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md), but it does not own the `0x0051f450`, `0x0051f510`, or `0x0051f640` helper bodies.

## Score Rationale

- Completion rises because the page records the validator-staged file root, attached child ordering, first-draft source-bearing dialog child, exact list-tail children, ignored internal padding/glue, vtable-family anchor, subtype factory route, source-tree placement, and corrected input-dialog boundary.
- Confidence rises because independent class, memory, vtable, item-helper, B-agent split research, project-structure, and factory pages all support the same standalone `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp/.h` owner bucket.
- Confidence remains below final reconstruction quality because some private helper/protocol/API spellings remain inferred. The standalone file route and complete source-bearing list tail are current and closed.

## Cross-References

- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [ArgumentedMenuDialogVtables](by-type/by-vtable/ArgumentedMenuDialogVtables.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md)
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md)
- [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md)
- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)

## Changes

- 2026-08-25 B002 UID0003VM Gate 2A support repair:
  - Made exact standalone `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp/.h` the sole active Status/proposed-module/file-root route.
  - Reclassified every former possible `TextMenuDialogs.cpp` fold statement as superseded historical uncertainty; no active current placement ambiguity remains.
  - Added UID0003VM's exact `ArgumentedMenuMenuItemList::OnItemActivated` role: 11-byte primary slot 31 / `+0x7c` owner forwarder, `m_ownerDialog` at `+0x158`, and `DialogPane::ActivateFocusedControl` destination `0x0049de70`.

- 2026-08-22 B002 UID0000OP Gate 2A repair:
  - Preserved the standalone UID0000HI owner, `91/93`, class ordering, existing source, purchase/input boundary, and compiler-only dispositions.
  - Closed the four empty list-tail emitters: UID0003VK `OnItemSelected`, UID0003VM `OnItemActivated`, UID0003VN `OnMouseEvent`, and UID0003VO `DrawListEntry` now emit through UID00000I into `ArgumentedMenuDialogs.cpp`, with matching declarations in `ArgumentedMenuDialogs.h`.

- 2026-08-17 B010 ArgumentedItemInputDialogs dependency closure:
  - Raised `88/91` to `91/93` and accepted standalone `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp/.h` as the active source route; the former TextMenuDialogs fold option is retained only as superseded historical uncertainty.
  - [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md) and [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md) now provide complete CPP/H channels. The header owns one `ArgumentedMenuItemEntry` declaration, both list constructors, friend access for the two input dialogs, and the three private purchase/quantity methods.
  - [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md), [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md), [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md), and [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md) are source-ready children. [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md) retains its accepted body without a duplicate row declaration.
  - No third-party import applies. Original helper/file spellings and raw-start liveness remain confidence caps; they do not block the complete human-written C++03 source route.

- 2026-06-25 B002 source-quality implementation:
  - Changed to: `88/91`.
  - Historical evidence at that date: [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) emitted first-draft `ArgumentedMenuMenuDialog` method C++ after B002 MCP-backed resolution of packet fields, command/update behavior, raw-island no-route evidence, and the then-current combined-score/emitter code gate. The then-open `TextMenuDialogs.cpp` packaging caveat was superseded by the accepted standalone `ArgumentedMenuDialogs.cpp/.h` route on 2026-08-17.
- 2026-06-28 B010 [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) support sync:
  - Score unchanged at `88/91`.
  - Recorded subtype `10` / `kArgumentedItemMenu` factory creation through the `TextMenuDialogs.cpp` dispatcher with `RectBounds`, while preserving this file as the concrete `ArgumentedMenuMenuDialog` owner.

- What existed before: the page identified argumented menu classes, vtables, and factory relationship but had unevaluated scores.
- What it was changed to: scores were set to `70/82`.
- Historical summary and evidence: menu behavior and vtables were strongly supported, while final split from `TextMenuDialogs.cpp` and input-dialog folding were then open. Both are superseded by the current standalone `ArgumentedMenuDialogs.cpp/.h` route and corrected input-dialog boundary.
- 2026-06-03 path/child split update:
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the dialog span was only represented by the broad `ArgumentedMenuDialogs` aggregate.
  - Changed to: `76/84`, path `NexusTK/ui/dialogs/`, and an exact [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md).
  - Evidence: restarted IDA MCP function, constructor-caller, vtable-slot, command-handler, and raw `0x0051f140` disassembly checks.
- 2026-06-06 file-root evidence update:
  - Before: the page had the correct path and exact dialog child, but still scored `76/84` and did not summarize validator staging target/child ordering or the stronger vtable/aggregate/source-tree evidence.
  - Changed to: `82/86`, with file-root validator staging status, attached child order, related input-helper boundary, and score rationale added.
  - Evidence: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) is `84/87` and confirms the argumented dialog/list vtable bases and constructor/store xrefs; [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) is already attached to this root; [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md) and [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md) are attached children; [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `ArgumentedMenuDialogs.cpp` under `NexusTK/ui/dialogs/`. File-root C++ remains blank because this page is an ownership bucket and exact child pages emit code.
- 2026-06-06 provenance cleanup:
  - Before: the status and score-rationale prose still described the page in terms of current recovered/staged outputs.
  - Changed to: IDA/by-* documentation basis and validator-staging wording, without changing scores or ownership.
  - Evidence: the same linked dialog/list memory docs, vtable-family page, factory helper, and proposed source-tree entry support the owner bucket. No file-root C++ was added because the root is an ownership bucket; later child pages now own emitted method code.
- 2026-06-10 B001-008 ownership-gate refresh:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`.
  - Evidence: live IDA MCP reconfirmed the argumented menu dialog/list vtable bases, complete-object-locator pointers, constructor/list/destructor store xrefs, the inherited `0x00517d80` secondary slot, and the `0x0061f588` boundary before `ArgumentedItemQuantityInputDialogPane`. The new split child [ArgumentedMenuDialogVtables](by-type/by-vtable/ArgumentedMenuDialogVtables.md) is assigned here, making this file root sufficient for the strict `85/85` parent gate while still holding final C++ below the source-code bar.
- 2026-06-16 B001 supervisor-applied tail split:
  - Changed to: `87/90`.
  - Evidence: B001 report-only audit split [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) into exact list-tail children [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md)-[UID:0003VO][0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem](by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md), added ignored internal padding/glue handling, converted [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) to a non-emitting split index, and converted [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md) into a non-emitting cross-reference index for helpers now owned by [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md).
- 2026-06-20 B002 Rule 26 source-quality incorporation:
  - Added [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md) as a guarded first-draft C++ child under [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md) rather than a blank raw helper.
  - Evidence: B002 local PE/Capstone audit confirmed the explicit-context constructor signature, base ListPane arguments, field names/widths, vtable stores, inline owning-dialog construction equivalence, and no direct start refs/pointer hits.
- 2026-06-20 B004 Rule 26 source-quality incorporation:
  - Added [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md) as a first-draft source-bearing child under [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md). The file root remains an ownership bucket and does not emit code directly.
  - Evidence: B004 local disassembly, inline construction at `0x0051ed05-0x0051ed79`, row consumers [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md)-[UID:0003VO][0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem](by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md), and shared `ListPane::AddEntry` support.
- 2026-06-20 B005 Rule 26 destructor-route incorporation:
  - Added the file-level rule that `ArgumentedMenuMenuItemList` destructor support should be rebuilt from declarations/vtables in this source bucket while [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md) and [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md) remain no-code generated ABI pages.
  - Evidence: B005 local PE/Capstone recheck confirms the primary destructor slot `0x0061f4c4`, secondary/tertiary adjustor slots `0x0061f54c`/`0x0061f57c`, and generated-only thunk/scalar-wrapper behavior.
