** TARGET-REPORT-UID:0001BS **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Report: [UID:0001BS] ArgumentedMenuDialogs Tail Split

Report-only pass. I did not edit `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, or any `by-*` documentation file.

## Target

- Target page: [UID:0001BS] `by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md`
- Current score observed in docs: `82/86`
- Current physical state: exact dialog child [UID:0002TW] covers `0x0051e9a0-0x0051f28d`; the tail `0x0051f290-0x0051fc8d` is still represented only by the broad parent row.
- Recommendation: split the tail into exact child pages, record internal padding and two non-emitting raw glue spans, then make [UID:0001BS] a reviewed `ignored/non-emitting` split index at `88/90`, `RECONSTRUCTABLE:FALSE`.

## Evidence Scope

Reviewed repository docs:

- `by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md`
- `by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md`
- `by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md`
- `by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md`
- `by-file/ArgumentedMenuDialogs.md`
- `by-file/ArgumentedItemInputDialogs.md`
- `by-class/ArgumentedMenuMenuDialog.md`
- `by-class/ArgumentedMenuMenuItemList.md`
- `by-class/ArgumentedItemQuantityInputDialogPane.md`
- `by-class/ArgumentedItemConfirmInputDialogPane.md`
- `by-type/by-vtable/ArgumentedMenuDialogVtables.md`
- `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`
- `by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md`
- `by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md`
- `by-memory/-coverage-report.md` around the argumented menu block
- `project-level/-auto-completion-stats.md`
- `auto-generated/-ag-memory-coverage.md`

Live evidence used:

- IDA MCP server at `127.0.0.1:13337`, session `a002_goal65_20260616`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- MCP `entity_query`, `lookup_funcs`, `get_bytes`, `insn_query`, `xrefs_to`, and `decompile` over `0x0051e990-0x0051fca0`.
- Raw PE byte and pointer scans against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for VA constants, RVA constants, and E8/E9 rel32 references.

## Current Function Inventory

IDA function inventory for the target/successor band:

| Start | End | IDA state | Proposed treatment |
| --- | --- | --- | --- |
| `0x0051e9a0` | `0x0051f136` | `sub_51E9A0`, size `0x796` | Already child [UID:0002TW]. |
| `0x0051f160` | `0x0051f24c` | `sub_51F160`, size `0xec` | Already inside [UID:0002TW]. |
| `0x0051f250` | `0x0051f28d` | `sub_51F250`, size `0x3d` | Already inside [UID:0002TW]. |
| `0x0051f290` | `0x0051f30b` | `sub_51F290`, size `0x7b` | Create exact `ArgumentedMenuMenuItemList` child. |
| `0x0051f310` | `0x0051f37a` | raw code, no IDA function | Create exact raw constructor/helper child. |
| `0x0051f380` | `0x0051f3b5` | raw code, no IDA function | Ignore as duplicate non-emitting destructor body. |
| `0x0051f3c0` | `0x0051f44e` | raw code, no IDA function | Create exact raw append-entry helper child. |
| `0x0051f450` | `0x0051f4fe` | `sub_51F450`, size `0xae` | Create exact purchase/confirm helper child. |
| `0x0051f500` | `0x0051f509` | raw tail-jump alias | Ignore as non-emitting thunk/alias to `0x0051f640`. |
| `0x0051f510` | `0x0051f5a5` | `sub_51F510`, size `0x95` | Create exact purchase/quantity helper child. |
| `0x0051f5b0` | `0x0051f63d` | `sub_51F5B0`, size `0x8d` | Create exact selection/update child. |
| `0x0051f640` | `0x0051f706` | `SendArgumentedItemQuantityPacket`, size `0xc6` | Create exact packet-send child. |
| `0x0051f710` | `0x0051f71b` | `sub_51F710`, size `0xb` | Create exact vtable forwarder child. |
| `0x0051f720` | `0x0051f840` | `sub_51F720`, size `0x120` | Create exact mouse-handler child. |
| `0x0051f840` | `0x0051fc8d` | `sub_51F840`, size `0x44d` | Create exact item draw child. |
| `0x0051fc90` | successor | `ArgumentedItemQuantityInputDialogPane_Constructor` | Existing successor page [UID:0001BT]. |

`lookup_funcs` confirmed there is no modeled IDA function at `0x0051f310`, `0x0051f380`, `0x0051f3c0`, or `0x0051f500`.

## Byte And Gap Audit

All ranges are half-open.

| Range | Bytes/classification | Evidence | Recommendation |
| --- | --- | --- | --- |
| `0x0051f28d-0x0051f290` | `cc cc cc`; padding | `get_bytes` after [UID:0002TW] endpoint. | Add ignored padding row. |
| `0x0051f290-0x0051f30b` | modeled function | IDA function `sub_51F290`, direct rel32 calls from `0x0051feec` and `0x00520347`. | Create child [UID:0003VF]. |
| `0x0051f30b-0x0051f310` | five `0xcc` bytes; padding | `get_bytes` and disassembly boundary before raw prologue at `0x0051f310`. | Add ignored padding row. |
| `0x0051f310-0x0051f37a` | raw source-shaped code | Starts `55 8b ec 51 56`; calls `sub_4F3A50`; writes list vtables `0x0061f4c4`, `0x0061f54c`, `0x0061f57c`; copies fields into offsets `+0x14c/+0x150/+0x154/+0x158`; returns `retn 10h`; no IDA function, no start xrefs, no VA/RVA/rel32 hits. | Create raw child [UID:0003VG]. |
| `0x0051f37a-0x0051f380` | six `0xcc` bytes; padding | `get_bytes`; follows `retn 10h` at `0x0051f379`. | Add ignored padding row. |
| `0x0051f380-0x0051f3b5` | raw duplicate destructor body | Writes same list vtables, checks global `0x0069ae04`, calls virtual with argument `1` if present, then tail-jumps to `sub_4F3B60`; no function, no refs, no pointer hits. Live destructor entry is [UID:00037B] `0x00520bb0-0x00520c17` with vtable refs. | Add ignored non-emitting code row, not a source child. |
| `0x0051f3b5-0x0051f3c0` | eleven `0xcc` bytes; padding | `get_bytes`; aligns raw append helper. | Add ignored padding row. |
| `0x0051f3c0-0x0051f44e` | raw source-shaped helper | Security cookie prologue; two `_wcscpy_s` calls; builds stack row record; calls `sub_4F3C50`; returns `retn 1Ch`; no function, no refs, no pointer hits. | Create raw child [UID:0003VH]. |
| `0x0051f44e-0x0051f450` | two `0xcc` bytes; padding | `get_bytes`; aligns `sub_51F450`. | Add ignored padding row. |
| `0x0051f450-0x0051f4fe` | modeled helper | No inbound refs or pointer hits; gets selected row, formats confirm text, constructs `ArgumentedItemConfirmInputDialogPane`. | Create child [UID:0003VI]. |
| `0x0051f4fe-0x0051f500` | two `0xcc` bytes; padding | `get_bytes`. | Add ignored padding row. |
| `0x0051f500-0x0051f509` | raw tail-jump alias | `push ebp; mov ebp, esp; pop ebp; jmp SendArgumentedItemQuantityPacket`; no function, no inbound refs. | Add ignored thunk/alias row. |
| `0x0051f509-0x0051f510` | seven `0xcc` bytes; padding | `get_bytes`. | Add ignored padding row. |
| `0x0051f510-0x0051f5a5` | modeled helper | No inbound refs or pointer hits; quantity count gate; calls `0x0051f640` for single quantity or constructs quantity input pane. | Create child [UID:0003VJ]. |
| `0x0051f5a5-0x0051f5b0` | eleven `0xcc` bytes; padding | `get_bytes`. | Add ignored padding row. |
| `0x0051f5b0-0x0051f63d` | modeled vtable method | Vtable data ref at `0x0061f53c`; updates selected-row text/description through owner dialog pointer. | Create child [UID:0003VK]. |
| `0x0051f63d-0x0051f640` | three `0xcc` bytes; padding | `get_bytes`. | Add ignored padding row. |
| `0x0051f640-0x0051f706` | modeled helper | rel32 refs from `0x0051f504`, `0x0051f58d`, `0x0052008e`, `0x00520501`; sends opcode `0x39` / 57 packet with item id and quantity. | Create child [UID:0003VL]. |
| `0x0051f706-0x0051f710` | ten `0xcc` bytes; padding | `get_bytes`. | Add ignored padding row. |
| `0x0051f710-0x0051f71b` | modeled tiny vtable method | Two instructions: `mov ecx, [ecx+158h]`; `jmp 0x0049de70`; vtable data ref at `0x0061f540`. | Create child [UID:0003VM]. |
| `0x0051f71b-0x0051f720` | five `0xcc` bytes; padding | `get_bytes`. | Add ignored padding row. |
| `0x0051f720-0x0051f840` | modeled vtable method | Vtable data ref at `0x0061f524`; mouse event/hit-test/item-help behavior. | Create child [UID:0003VN]. |
| `0x0051f840-0x0051fc8d` | modeled vtable method | Vtable data ref at `0x0061f544`; row drawing, icon/text/price/quantity rendering. | Create child [UID:0003VO]. |
| `0x0051fc8d-0x0051fc90` | three `0xcc` bytes; padding | Existing ignored row already covers this successor alignment. | Keep existing ignored row. |

## Xref And Reachability Evidence

- `0x0051f290` has direct code callers from both input dialog constructors:
  - `0x0051feec` in `ArgumentedItemQuantityInputDialogPane_Constructor`
  - `0x00520347` in `ArgumentedItemConfirmInputDialogPane_Constructor`
- `0x0051f640` has four rel32 references:
  - `0x0051f504`, the raw alias/thunk at `0x0051f500`
  - `0x0051f58d`, the single-quantity path inside `0x0051f510`
  - `0x0052008e`, quantity input action
  - `0x00520501`, confirm input action
- `0x0051f5b0`, `0x0051f710`, `0x0051f720`, and `0x0051f840` have vtable data refs at `0x0061f53c`, `0x0061f540`, `0x0061f524`, and `0x0061f544`.
- `0x0061f4c4`, `0x0061f54c`, and `0x0061f57c` are `ArgumentedMenuMenuItemList` vtable pointers. They are written by the modeled/copy constructors, the raw `0x0051f310` body, the raw `0x0051f380` duplicate destructor, and the live scalar deleting destructor at `0x00520bb0`.
- Raw PE scan found no absolute VA constants, RVA constants, or rel32 E8/E9 call/jump references to `0x0051f310`, `0x0051f380`, `0x0051f3c0`, `0x0051f450`, `0x0051f500`, or `0x0051f510`.
- The lack of direct refs is not, by itself, a blocker. The raw `0x0051f310` and `0x0051f3c0` bodies decode as source-shaped list constructor/append logic, so they should be preserved as exact source-bearing raw children with blank final C++. The raw `0x0051f380` and `0x0051f500` spans are compiler/generated duplicate or alias code and should be ignored.

## Source Ownership Decision

The tail is not owned by `ArgumentedItemInputDialogs` even though input dialogs call into it and some helpers allocate input panes.

Best source route:

- `0x0051e9a0-0x0051f28d`: existing [UID:0002TW] `ArgumentedMenuMenuDialog`, direct owner [UID:00000H].
- `0x0051f290-0x0051fc8d` source-bearing children: direct owner/emitter [UID:00000I] `ArgumentedMenuMenuItemList`.
- Parent [UID:0001BS] remains the physical/source-file neighborhood [UID:0000HI] `ArgumentedMenuDialogs` and should be non-emitting.
- [UID:0001BT] `ArgumentedItemInputDialogs` owns only the input pane constructors/actions at `0x0051fc90-0x00520539`. Its constructors copy list context by calling `0x0051f290`, and its action handlers call `0x0051f640`.

Evidence for `ArgumentedMenuMenuItemList` ownership:

- `0x0051f290` and raw `0x0051f310` both construct a list object and install `ArgumentedMenuMenuItemList` vtables.
- `0x0051f5b0`, `0x0051f710`, `0x0051f720`, and `0x0051f840` are vtable-backed list methods.
- `0x0051f640` consumes the copied list context fields: owner/session pointer at `this+0x158`, menu/context byte at `this+0x14c`, argument id at `this+0x150`, and row/context word at `this+0x154`.
- Quantity and confirm input actions do not own the packet serialization. They call it on the embedded/copied list context.
- `0x0051f450` and `0x0051f510` operate on the selected list row and then create confirm/quantity panes. That constructor dependency does not make them `ArgumentedItemInputDialogs` methods.

Rejected owner routes:

- `ArgumentedItemInputDialogs`: dependency/caller only for the tail helper functions; it does own the successor input pane implementations.
- `ArgumentedMenu` as a generic owner: no direct function, vtable, or field evidence in the tail points to a separate `ArgumentedMenu` class owner.
- Generic `MenuDialog` or `MenuItemList`: base constructors/destructors are callees, but the vtable stores and field usage are specific to `ArgumentedMenuMenuItemList`.

## Proposed Child Pages

Public docs currently show [UID:0003V8] through [UID:0003VE] already allocated/executed. I found no public use of [UID:0003VF] through [UID:0003VO]. Use this exact sequence unless the supervisor has newer private allocations.

| UID | Path | Range | Title | Kind | Owner/emitter | Reconstructable | Score | Final C++ decision |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `0003VF` | `by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md` | `0x0051f290-0x0051f30b` | `ArgumentedMenuMenuItemListCopyConstructor` | class method / context copy constructor | `CANONICAL_OWNER:00000I`, `EMITTER_UIDS:00000I` | `TRUE` | `86/89` | Keep blank. Exact behavior is known, but source signature and copied-context field names remain unresolved. |
| `0003VG` | `by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md` | `0x0051f310-0x0051f37a` | `ArgumentedMenuMenuItemListRawContextConstructor` | raw class constructor/helper | `CANONICAL_OWNER:00000I`, `EMITTER_UIDS:00000I` | `TRUE` | `85/86` | Keep blank. No modeled function or entry refs; source shape is clear but liveness/name are unresolved. |
| `0003VH` | `by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md` | `0x0051f3c0-0x0051f44e` | `ArgumentedMenuMenuItemListRawAppendEntryHelper` | raw class helper | `CANONICAL_OWNER:00000I`, `EMITTER_UIDS:00000I` | `TRUE` | `85/86` | Keep blank. Row append shape is clear, but original helper name and row-record type are unresolved. |
| `0003VI` | `by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md` | `0x0051f450-0x0051f4fe` | `ArgumentedMenuOpenBuyConfirmDialog` | class helper | `CANONICAL_OWNER:00000I`, `EMITTER_UIDS:00000I` | `TRUE` | `85/88` | Keep blank. No inbound refs; selected-row and pane-construction behavior known, source name provisional. |
| `0003VJ` | `by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md` | `0x0051f510-0x0051f5a5` | `ArgumentedMenuOpenQuantityDialogOrSendSingle` | class helper | `CANONICAL_OWNER:00000I`, `EMITTER_UIDS:00000I` | `TRUE` | `85/88` | Keep blank. No inbound refs; quantity path known, original helper/field names unresolved. |
| `0003VK` | `by-memory/0x0051f5b0-0x0051f63d.ArgumentedMenuMenuItemListSelectItemAndUpdateText.md` | `0x0051f5b0-0x0051f63d` | `ArgumentedMenuMenuItemListSelectItemAndUpdateText` | vtable class method | `CANONICAL_OWNER:00000I`, `EMITTER_UIDS:00000I` | `TRUE` | `86/89` | Keep blank. Vtable slot is proven; final text-control/row-field names unresolved. |
| `0003VL` | `by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md` | `0x0051f640-0x0051f706` | `ArgumentedMenuSendItemQuantityPacket` | packet helper / class method | `CANONICAL_OWNER:00000I`, `EMITTER_UIDS:00000I` | `TRUE` | `87/90` | Keep blank. Packet layout is known but protocol/member names need source-level audit. |
| `0003VM` | `by-memory/0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate.md` | `0x0051f710-0x0051f71b` | `ArgumentedMenuMenuItemListForwardOwnerStateUpdate` | vtable forwarder | `CANONICAL_OWNER:00000I`, `EMITTER_UIDS:00000I` | `TRUE` | `85/88` | Keep blank. Exact two-instruction forwarder; final virtual slot name unresolved. |
| `0003VN` | `by-memory/0x0051f720-0x0051f840.ArgumentedMenuMenuItemListHandleMouseEvent.md` | `0x0051f720-0x0051f840` | `ArgumentedMenuMenuItemListHandleMouseEvent` | vtable class method | `CANONICAL_OWNER:00000I`, `EMITTER_UIDS:00000I` | `TRUE` | `86/89` | Keep blank. Mouse/item-help behavior known; event names and row payload names unresolved. |
| `0003VO` | `by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md` | `0x0051f840-0x0051fc8d` | `ArgumentedMenuMenuItemListDrawMenuItem` | vtable class method | `CANONICAL_OWNER:00000I`, `EMITTER_UIDS:00000I` | `TRUE` | `86/88` | Keep blank. Draw behavior known; resource/font/row-field names unresolved. |

Parent metadata recommendation:

```text
by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000HI
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
Disposition: reviewed non-emitting split index over ArgumentedMenuMenuDialog plus ArgumentedMenuMenuItemList tail children and ignored glue/padding.
```

## Ignored Spans To Add

Add a grouped entry to `by-memory/-ignored.md` for the internal tail padding and non-emitting glue:

```text
### 0x0051f28d-0x0051fc90 ArgumentedMenuDialogs tail padding and non-emitting glue

- Ranges:
  - `0x0051f28d-0x0051f290`, `0x0051f30b-0x0051f310`, `0x0051f37a-0x0051f380`, `0x0051f3b5-0x0051f3c0`, `0x0051f44e-0x0051f450`, `0x0051f4fe-0x0051f500`, `0x0051f509-0x0051f510`, `0x0051f5a5-0x0051f5b0`, `0x0051f63d-0x0051f640`, `0x0051f706-0x0051f710`, and `0x0051f71b-0x0051f720` are `0xcc` alignment padding between exact ArgumentedMenuMenuItemList children.
  - `0x0051f380-0x0051f3b5` is an unreferenced duplicate non-deleting `ArgumentedMenuMenuItemList` destructor body; the live vtable-owned scalar deleting destructor remains [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md).
  - `0x0051f500-0x0051f509` is an unreferenced raw tail-jump alias to [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md).
- Why ignored: padding has no source responsibility; the duplicate destructor body and send alias are compiler/linker emitted glue rather than standalone handwritten source. Exact source-bearing children carry the `ArgumentedMenuMenuItemList` behavior.
- Evidence: 2026-06-16 B001 IDA MCP and raw PE byte audit. Padding bytes are all `0xcc`; raw destructor duplicate has no function object, no entry xrefs, and no VA/RVA/rel32 pointer hits; raw alias at `0x0051f500` is `push ebp; mov ebp, esp; pop ebp; jmp 0x0051f640` with no inbound refs.
- Replacement/procurement: rebuild source through [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md), exact child pages [UID:0003VF]-[UID:0003VO], and existing destructor support [UID:00037A]/[UID:00037B]; let the compiler regenerate padding/destructor glue/thunk alias bytes.
```

The existing `0x0051fc8d-0x0051fc90` ignored padding row can remain as-is.

## Exact Coverage Replacement Rows

Replace the current [UID:0001BS] block and keep the existing successor `0x0051fc8d-0x0051fc90` ignored row after it. The replacement block should be:

```text
    - [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) 0x0051e9a0-0x0051fc8d | split-index | ArgumentedMenuDialogs : ignored/non-emitting : 88% : strong : B001 2026-06-16 report-only split recommendation reclassifies this broad range as a reviewed non-emitting split index over the exact ArgumentedMenuMenuDialog child, ArgumentedMenuMenuItemList tail method/raw-helper children, internal padding, and non-emitting duplicate destructor/thunk glue; exact children carry source ownership and parent C++ remains blank.
        - [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) 0x0051e9a0-0x0051f28d | class slice | ArgumentedMenuMenuDialog : reconstructable : 86% : strong : A002 2026-06-14 live IDA refresh corrected constructor size to 0x796, rerouted direct ownership through [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md), reconfirmed constructor callers, vtable stores/slots, resource/prompt refs, command/updater decompilation, raw 0x0051f140 no-xref caveat, and successor padding.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f28d-0x0051f290 | padding | ArgumentedMenuMenuDialog to item-list copy constructor alignment : ignored : 100% : strong : B001 byte audit shows three `0xcc` bytes after [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) and before [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md).
        - [UID:0003VF][0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor](by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md) 0x0051f290-0x0051f30b | class method | ArgumentedMenuMenuItemListCopyConstructor : reconstructable : 86% : strong : Exact ArgumentedMenuMenuItemList context-copy constructor called by both argumented item input dialog constructors; IDA confirms size 0x7b, list constructor call, vtable stores, copied context fields at offsets `+0x14c/+0x150/+0x154/+0x158`, and direct rel32 refs from `0x0051feec` and `0x00520347`. Final C++ remains blank pending source signature and field names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f30b-0x0051f310 | padding | item-list copy constructor to raw context constructor alignment : ignored : 100% : strong : B001 byte audit shows five `0xcc` bytes before raw body `0x0051f310`.
        - [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md) 0x0051f310-0x0051f37a | raw class helper | ArgumentedMenuMenuItemListRawContextConstructor : reconstructable : 85% : strong : Raw no-function ArgumentedMenuMenuItemList constructor/context-copy body; disassembly calls `sub_4F3A50`, writes vtables `0x0061f4c4/0x0061f54c/0x0061f57c`, copies context fields, returns `retn 10h`, and has no direct start xrefs or VA/RVA/rel32 pointer hits. Final C++ remains blank pending liveness and original helper name.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f37a-0x0051f380 | padding | raw context constructor to duplicate destructor alignment : ignored : 100% : strong : B001 byte audit shows six `0xcc` bytes after `retn 10h`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f380-0x0051f3b5 | compiler glue | duplicate ArgumentedMenuMenuItemList non-deleting destructor body : ignored : 86% : strong : Raw unreferenced duplicate destructor body writes ArgumentedMenuMenuItemList vtables, checks global `0x0069ae04`, and tail-jumps to `sub_4F3B60`; no function object, no start xrefs, and no pointer hits. Source responsibility stays with the class destructor and live vtable-owned [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f3b5-0x0051f3c0 | padding | duplicate destructor to raw append-entry helper alignment : ignored : 100% : strong : B001 byte audit shows eleven `0xcc` bytes.
        - [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md) 0x0051f3c0-0x0051f44e | raw class helper | ArgumentedMenuMenuItemListRawAppendEntryHelper : reconstructable : 85% : strong : Raw no-function list-row append helper; IDA disassembly shows security-cookie prologue, two `_wcscpy_s` copies, stack row-record construction, `sub_4F3C50` append call, `retn 1Ch`, and no direct xrefs or pointer hits. Final C++ remains blank pending original helper and row-record names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f44e-0x0051f450 | padding | raw append-entry helper to buy-confirm helper alignment : ignored : 100% : strong : B001 byte audit shows two `0xcc` bytes.
        - [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md) 0x0051f450-0x0051f4fe | class helper | ArgumentedMenuOpenBuyConfirmDialog : reconstructable : 85% : strong : Exact selected-row buy-confirm helper on ArgumentedMenuMenuItemList; fetches selected row, formats `Do you want to buy this?\n\nConfirm the price.`, allocates an ArgumentedItemConfirmInputDialogPane, and has no direct xrefs or pointer hits. Final C++ remains blank pending source helper name and row-field names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f4fe-0x0051f500 | padding | buy-confirm helper to send alias alignment : ignored : 100% : strong : B001 byte audit shows two `0xcc` bytes.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f500-0x0051f509 | compiler glue | unreferenced tail-jump alias to ArgumentedMenuSendItemQuantityPacket : ignored : 86% : strong : Raw alias bytes decode as `push ebp; mov ebp, esp; pop ebp; jmp 0x0051f640`; there is no IDA function object and no inbound refs. Source should call/rebuild [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md), not emit a standalone helper.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f509-0x0051f510 | padding | send alias to quantity helper alignment : ignored : 100% : strong : B001 byte audit shows seven `0xcc` bytes.
        - [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md) 0x0051f510-0x0051f5a5 | class helper | ArgumentedMenuOpenQuantityDialogOrSendSingle : reconstructable : 85% : strong : Exact selected-row quantity helper on ArgumentedMenuMenuItemList; sends quantity `1` directly through `0x0051f640` when count permits, otherwise loads prompt id `246` through `g_pLanguageMan` and allocates ArgumentedItemQuantityInputDialogPane. No direct xrefs or pointer hits; final C++ remains blank pending original helper and field names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f5a5-0x0051f5b0 | padding | quantity helper to selection-update method alignment : ignored : 100% : strong : B001 byte audit shows eleven `0xcc` bytes.
        - [UID:0003VK][0x0051f5b0-0x0051f63d.ArgumentedMenuMenuItemListSelectItemAndUpdateText](by-memory/0x0051f5b0-0x0051f63d.ArgumentedMenuMenuItemListSelectItemAndUpdateText.md) 0x0051f5b0-0x0051f63d | class method | ArgumentedMenuMenuItemListSelectItemAndUpdateText : reconstructable : 86% : strong : Exact vtable-backed selection/update method with data ref at `0x0061f53c`; fetches selected row, updates owner dialog text/description controls through the stored owner pointer, and delegates to the base list selection helper. Final C++ remains blank pending text-control and row-field names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f63d-0x0051f640 | padding | selection-update method to packet send helper alignment : ignored : 100% : strong : B001 byte audit shows three `0xcc` bytes.
        - [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md) 0x0051f640-0x0051f706 | packet helper | ArgumentedMenuSendItemQuantityPacket : reconstructable : 87% : strong : Exact ArgumentedMenuMenuItemList quantity packet serializer; rel32 refs from `0x0051f504`, `0x0051f58d`, `0x0052008e`, and `0x00520501`; writes opcode `0x39`, context byte/dword/word fields, subcommand `1`, item id, quantity, and sends 14 bytes through `g_packetSender`. Final C++ remains blank pending protocol and member names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f706-0x0051f710 | padding | quantity packet helper to owner-state forwarder alignment : ignored : 100% : strong : B001 byte audit shows ten `0xcc` bytes.
        - [UID:0003VM][0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate](by-memory/0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate.md) 0x0051f710-0x0051f71b | vtable forwarder | ArgumentedMenuMenuItemListForwardOwnerStateUpdate : reconstructable : 85% : strong : Exact two-instruction vtable helper with data ref at `0x0061f540`; forwards through owner pointer at `this+0x158` to `0x0049de70`. Final C++ remains blank pending virtual slot name.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051f71b-0x0051f720 | padding | owner-state forwarder to mouse handler alignment : ignored : 100% : strong : B001 byte audit shows five `0xcc` bytes.
        - [UID:0003VN][0x0051f720-0x0051f840.ArgumentedMenuMenuItemListHandleMouseEvent](by-memory/0x0051f720-0x0051f840.ArgumentedMenuMenuItemListHandleMouseEvent.md) 0x0051f720-0x0051f840 | class method | ArgumentedMenuMenuItemListHandleMouseEvent : reconstructable : 86% : strong : Exact vtable-backed mouse/event handler with data ref at `0x0061f524`; hides item help on leave, hit-tests rows, fetches selected row data, optionally opens ItemHelpPane, and delegates to base mouse handling otherwise. Final C++ remains blank pending event and row payload names.
        - [UID:0003VO][0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem](by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md) 0x0051f840-0x0051fc8d | class method | ArgumentedMenuMenuItemListDrawMenuItem : reconstructable : 86% : strong : Exact vtable-backed item draw method with data ref at `0x0061f544`; draws row icon/name/price/quantity text, uses `_wcscpy_s`/`_wcscat_s` formatting paths, and handles numeric formats including `%d`/`%u`. Final C++ remains blank pending renderer/resource and row-field names.
```

Keep the existing successor row:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051fc8d-0x0051fc90 | padding | ArgumentedMenuDialogs to ArgumentedItemInputDialogs alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
```

## Support Doc Edits Recommended

The supervisor can apply these as normal by-* edits after accepting the split.

1. `by-class/ArgumentedMenuMenuItemList.md`
   - Raise to `87/89`.
   - Add the exact child list [UID:0003VF]-[UID:0003VO].
   - Replace the old `0x0051f310` false-lead wording with: "B001 2026-06-16 confirmed `0x0051f310-0x0051f37a` is real raw `ArgumentedMenuMenuItemList` constructor/context-copy code with no entry refs; it is exact child [UID:0003VG], not padding and not a blocker."
   - Add `0x0051f3c0-0x0051f44e` as exact raw append-entry helper [UID:0003VH].
   - State that purchase/quantity helpers `0x0051f450`, `0x0051f510`, and `0x0051f640` are class/list-context helpers, while input panes are callees/callers.

2. `by-file/ArgumentedMenuDialogs.md`
   - Raise to `87/90`.
   - Add [UID:0003VF]-[UID:0003VO] to the ArgumentedMenuMenuItemList tail section.
   - State that [UID:0001BS] is non-emitting once exact children exist.

3. `by-file/ArgumentedItemInputDialogs.md`
   - Do not claim ownership of `0x0051f450`, `0x0051f510`, or `0x0051f640`.
   - Keep cross references saying quantity/confirm input dialog actions call [UID:0003VL] and constructors call [UID:0003VF].

4. `by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md` [UID:0000TY]
   - Convert to a non-emitting cross-reference index after exact children exist.
   - Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00000I
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
```

   - Body replacement summary: "This item page is a non-emitting procurement/purchase-helper index. Exact source-bearing behavior is carried by [UID:0003VI], [UID:0003VJ], and [UID:0003VL]. Input dialog pages own only the input pane constructors/actions that consume the list helpers."

## New Child Page Body Requirements

Each new page should include:

- Exact half-open range and neighboring padding/glue rows.
- Function/object status from IDA: modeled function or raw no-function span.
- Caller/callee/vtable evidence from the tables above.
- Owner/emitter route through [UID:00000I] `ArgumentedMenuMenuItemList`.
- `RECONSTRUCTION_CPP` blank with the final-C++ blocker stated in the child table.
- Cross-link to [UID:0001BS] parent split index and, where applicable, to [UID:0001BT] input dialogs as callers/callees rather than owners.

## Validation Commands

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after applying the supervisor edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001BS-argumented-menu-dialogs-tail-split-removed.md](0001BS-argumented-menu-dialogs-tail-split-removed.md). The archived block is non-authoritative and must not be executed.

Expected result:

- Each targeted validator exits `0` with `ok: 1`.
- [UID:0001BS] no longer appears in `project-level/-auto-completion-stats.md` Low_Completion/Low_Both after the normal stats refresh.
- `memory_ranges.py report` no longer has the unsplit `0x0051f290-0x0051fc8d` leaf under [UID:0001BS].
- The by-memory tool should keep Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan clear for this target.

## Final Recommendation

Split/create, not no-op.

Create exact child pages [UID:0003VF]-[UID:0003VO], add ignored rows for internal padding plus `0x0051f380-0x0051f3b5` and `0x0051f500-0x0051f509`, reclassify [UID:0001BS] as a non-emitting split index, and reroute purchase/quantity helpers from the current `ArgumentedItemInputDialogs` item-page ownership to [UID:00000I] `ArgumentedMenuMenuItemList` with input dialog pages treated as callers/callees.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001BS-argumented-menu-dialogs-tail-split.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001BS"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001BS-argumented-menu-dialogs-tail-split-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001BS-argumented-menu-dialogs-tail-split.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001BS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
