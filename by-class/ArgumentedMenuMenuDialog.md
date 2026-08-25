*** UID:00000H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ArgumentedMenuDialogs.h"
#include "ArgumentedItemInputDialogs.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "MerchantDialogPane.h"

class ArgumentedMenuMenuItemList;

class ArgumentedMenuMenuDialog : public MerchantDialogPane
{
public:
    ArgumentedMenuMenuDialog(const RectBounds& bounds,
                             const unsigned char *payload,
                             unsigned char menuMode);

protected:
    void HandleMenuCommand(int commandId, void *context);
    void UpdateActionButtonState();

private:
    ArgumentedMenuMenuItemList *GetArgumentedMenuList(
        int controlIndex) const;

    unsigned char m_commandType;          // +0x274
    unsigned char m_reserved275[3];       // +0x275..+0x277
};

typedef char ArgumentedMenuMenuDialogSizeMustBe632[
    (sizeof(ArgumentedMenuMenuDialog) == 0x278) ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ArgumentedMenuMenuDialog

## Status

- Confidence: accepted `91/93` for behavior, vtable slots, constructor callers, shared-base layout, and standalone ArgumentedMenuDialogs placement.
- Accepted source file: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md); the former TextMenuDialogs fold option is historical only.
- Address range: [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md), nested under [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- Documentation basis: the reviewed by-file owner, exact by-memory child, broad aggregate, and merchant-menu vtable-family page.
- Direct child routing: [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) now emits first-draft method bodies through this class and [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md).

## Class Purpose

`ArgumentedMenuMenuDialog` is the parameterized item/menu variant of the NPC merchant dialog. It parses packet data for command type, NPC/dialog id, portrait/object asset data, dialog text, list parameter, and item entries. It builds a `DLGMERC3.EPF` dialog with object image, static text, scrollable item list, and action buttons.

## Class Shape

- Base family: merchant/text-menu dialog family.
- Child list: owns or constructs [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md).
- Resource anchor: `DLGMERC3.EPF`.
- Command behavior: command `1` opens item price confirm, command `2` sends a menu request/cancel packet, and command `3` closes.
- Source placement: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md). A TextMenuDialogs fold was considered historically and is superseded.
- Factory constructor shape: [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) reaches this class through subtype `10` / `kArgumentedItemMenu` as `ArgumentedMenuMenuDialog(const RectBounds& bounds, const unsigned char *payload, unsigned char menuMode)`. The dispatcher remains owned/emitted through [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md); this class remains owned/emitted through [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md).

## Field Layout

Known and inferred class fields from the constructor and list/purchase helpers:

| Offset | Field | Evidence |
| ---: | --- | --- |
| `+0x26c` | inherited `MerchantDialogPane`/menu mode byte | Constructor stores the wrapper-supplied mode byte here before dialog-specific packet fields. |
| inherited `+0x270` | `MerchantDialogPane::m_menuObjectId` dword | Parsed from `payload+1`; consumed by inherited `MerchantDialogPane::SendMenuRequestPacket()` and copied into the list's distinct list-owned `m_ownerId`. The dialog does not redeclare this dword. |
| `+0x274` | `m_commandType` byte | Parsed from `payload[0]`; copied into `ArgumentedMenuMenuItemList::m_commandType` and used by the quantity packet path. |
| `+0x275..+0x277` | padding after `m_commandType` | Required to preserve the `0x278` / 632-byte allocation and field alignment; no independent source field is modeled. |

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0051e9a0-0x0051f136` | `ArgumentedMenuMenuDialog` | Constructor and packet parser; builds `ArgumentedMenuMenuItemList`, parses item entry blocks, and creates dialog controls. |
| `0x0051f140-0x0051f158` | raw action/list forwarding island | Code-shaped non-function island with no IDA xrefs; loads child pointer `this+0x1fc`, calls child virtual slot `+0x10` with argument `7`, then tail-jumps to `0x00498ca0`. |
| `0x0051f160-0x0051f24c` | `HandleMenuCommand` | Opens buy-confirm input dialog for command `1`, sends cancel/request packet for command `2`, or closes on command `3`. |
| `0x0051f250-0x0051f28d` | `UpdateActionButtonState` | Enables/disables the action button depending on selected list state. |

## Evidence Notes

- [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) now records the validator-staged file root, child ordering, factory route, vtable-family anchor, and source-tree placement for the argumented menu family.
- [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) documents the constructor, raw `0x0051f140` island, command handler, action-button updater, padding boundaries, constructor callers, command strings, and vtable slots.
- UID0001BS ties this exact dialog slice to the item-list/purchase-helper tail; current source placement is the standalone UID0000HI route, while the prior TextMenuDialogs fold possibility is historical.
- IDA MCP confirms all three method starts and vtable refs for `0x0051f160` and `0x0051f250`.
- 2026-06-03 restarted IDA MCP recheck corrects the exact half-open function ranges to `0x0051e9a0-0x0051f136`, `0x0051f160-0x0051f24c`, and `0x0051f250-0x0051f28d`.
- Focused disassembly confirms a raw code-shaped island at `0x0051f140-0x0051f158`, but IDA has no function object, no xrefs to `0x0051f140`, and no dialog vtable slot targeting that address.
- The constructor is called from packet-dispatch sites `0x00517750` and `0x00517c97`.
- The primary dialog vtable at `0x0061f428` points command/update slots to `0x0051f160` and `0x0051f250`; secondary/tertiary bases `0x0061f488` and `0x0061f4b8` are installed by the constructor.
- The command `1` path opens [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md) at `0x005200d0` with the prompt text `Do you want to buy this?\n\nConfirm the price.`
- A separate generated helper at `0x0051f450` builds the same confirm pane but is currently emitted under `ChattingColorListPane`; treat it as an argumented item purchase helper, not chat-color code.
- Command `2` calls inherited [UID:0004H8][0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket](by-memory/0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket.md) `MerchantDialogPane::SendMenuRequestPacket()`, using inherited `m_menuObjectId`; this is shared-base reuse, not TextMenuDialog ownership.
- 2026-06-14 live IDA MCP database `b001_0003gy` reconfirms constructor `sub_51E9A0` size `0x796`, no function/xrefs at `0x0051f140`, command handler `sub_51F160` size `0xec`, updater `sub_51F250` size `0x3d`, and successor list constructor `sub_51F290` size `0x7b`.
- The same pass reconfirms constructor callers at `0x00517750` and `0x00517c97`, constructor vtable stores to `0x0061f428`/`0x0061f488`/`0x0061f4b8`, command/update slots at `0x0061f470`/`0x0061f474`, `DLGMERC3.EPF` constructor refs at `0x0051eded` and `0x0051f0dd`, and command-handler prompt ref at `0x0051f1db`.
- Fresh command-handler decompilation confirms command `1` allocates the argumented confirm pane through `0x005200d0`, command `2` calls the shared menu packet helper `0x00517ec0`, and command `3` closes through `0x0049dad0`; fresh updater decompilation confirms selected-list availability controls the action-button virtual dispatch.
- B002 2026-06-25 source-quality pass adds live MCP session `4fee46af-266c-4175-acfa-17b665497c67` / database `80de0a67`: constructor `0x0051e9a0` size `0x796`, command handler `0x0051f160` size `0xec`, updater `0x0051f250` size `0x3d`, constructor callers `0x00517750` and `0x00517c97`, command/update vtable refs `0x0061f470`/`0x0061f474`, zero xrefs/no function/no vtable slot for raw `0x0051f140`, `DLGMERC3.EPF` refs `0x0051eded`/`0x0051f0dd`, and prompt ref `0x0051f1db`.
- Current source-facing fields are inherited mode byte at `+0x26c`, inherited `m_menuObjectId` at `+0x270`, derived `m_commandType` at `+0x274`, and padding at `+0x275..+0x277`. The distinct list-owned context identifier remains on `ArgumentedMenuMenuItemList`. Method-body C++ is emitted by UID0002TW; this class page emits the declaration skeleton.

## Split and Reconstruction State

- This class page is attached to [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), clears the support gate for its exact executable child, and now carries declaration-level first-draft C++.
- Keep [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) as the exact executable range; this page should summarize class ownership and method families rather than duplicate every boundary detail.
- Method-body C++ belongs on UID0002TW and emits through UID0000HI. The former `TextMenuDialogs.cpp` fold option is retained only in historical changes below.

## Score Rationale

Completion is accepted at `91` because the page records class purpose, method map, exact executable child, constructor callers, vtable stores/slots, resource and prompt refs, command behavior, accepted source placement, inherited-base layout, declaration-level H, and method-body routing through UID0002TW.

Confidence is accepted at `93` because function/xref/decompile/byte evidence, the file root, vtable pages, factory helper, list row layout, packet field flow, inherited `m_menuObjectId`, and MerchantDialogPane request route agree on this class owner and declaration shape. Remaining uncertainty is limited to stripped local/helper spellings and the unreferenced raw island.

## Cross-References

- [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)
- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md)

## Changes

- 2026-08-22 B002 UID0000OP implementation callback: rebased the active layout, command-2 route, score rationale, and accepted reconciliation to sole inherited source name `MerchantDialogPane::m_menuObjectId +0x270`. The derived H declaration continues to omit the base field/method; list-owned `m_ownerId`, offsets, behavior, and score are unchanged.
- 2026-08-21 B002 Gate 2A repair: corrected active source placement, field layout, command-2 route, and score rationale to standalone ArgumentedMenuDialogs, inherited `m_dialogId`, and `MerchantDialogPane::SendMenuRequestPacket()`. That then-current inherited spelling is superseded by the 2026-08-22 callback; the earlier dialog-owned `m_ownerId` and TextMenuDialogs fold wording below remains superseded history, while the list's distinct `m_ownerId` remains unchanged.
- 2026-08-17 B010 ArgumentedItemInputDialogs dependency closure:
  - Raised `88/90` to `91/93`, established source position `10`, moved the declaration out of the CPP channel, and created the complete sibling-header route required by the argumented input-dialog classes.
  - The CPP channel now includes `ArgumentedMenuDialogs.h` and `ArgumentedItemInputDialogs.h` before child definitions. The H channel owns the source-facing constructor, command/update methods, list accessor, and natural `m_ownerId`/`m_commandType` fields without reverse-engineering padding members.
  - The historical TextMenuDialogs fold possibility remains only a confidence cap; standalone ArgumentedMenuDialogs placement is the accepted reconstruction route.

- 2026-06-25 B002 source-quality implementation:
  - Changed to: `88/90`, with declaration-level class C++, field notes for `+0x26c`, `+0x270`, `+0x274`, and `+0x275..+0x277`, and method-body routing through [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md).
  - Evidence: B002 MCP session `4fee46af-266c-4175-acfa-17b665497c67` / database `80de0a67` reconfirmed constructor/command/updater boundaries, constructor callers, vtable slots, resource/prompt refs, raw `0x0051f140` no-route evidence, and packet/list field names. The stale `90/90+` no-code gate is superseded by the current combined-score/emitter rule.

- 2026-06-14 A002 direct-child gate refresh:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`.
  - Summary/evidence: live IDA MCP database `b001_0003gy` reconfirmed the constructor/command/updater/successor function map, constructor callers, three constructor vtable stores, command/update vtable slots, `DLGMERC3.EPF` and confirm prompt refs, command-handler behavior, and updater selected-state dispatch. This cleared the direct-owner gate for [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md); the older no-code conclusion is superseded by the 2026-06-25 declaration and method-body routing above.

- 2026-06-06 evidence refresh:
  - Before: the page still used a generated-source line and Wave-derived evidence summary while the by-file owner, exact child page, aggregate, and vtable-family page had become stronger supporting sources.
  - Changed to: `82/84`, documented the by-* evidence basis, clarified the class/file attachment gate, and added split/reconstruction state while leaving C++ blank below the final-source threshold.
  - Evidence: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) is `82/86`, [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) is `82/86`, [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) carries the exact method/range evidence, and [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) supports the dialog vtables.
- What existed before: the page had behavior and boundary evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `68/82`, and a class-shape section was added for base family, child list, resource anchor, command behavior, and source placement.
- Summary and evidence: IDA-confirmed method starts and vtable references support strong behavior confidence, but final split from `TextMenuDialogs.cpp` and packet/layout fields remain unresolved.
- 2026-06-03 exact-slice update:
  - Before: the class still pointed only at the broad aggregate and omitted the raw `0x0051f140` island.
  - Changed to: `74/84`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) at position `10`, exact memory child [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md), and corrected half-open method endpoints.
  - Evidence: restarted IDA MCP function boundary checks, vtable-slot dump, constructor caller xrefs, command callee/string refs, and focused raw-island disassembly.

## B002 UID0000OP Accepted Shared-Base Reconciliation

Exact 0x278 declaration keeps only derived `m_commandType` at +0x274 plus padding; inherited `m_menuObjectId` owns +0x270. Duplicate dialog-owned `m_ownerId` is removed while the distinct list-owned identifier remains unchanged.

All five factory wrappers allocate exactly `0x278`; live constructors place the packet dword at `this+0x270` and the family byte at `this+0x274`. This proves one inherited dword plus one derived byte and three bytes of tail padding without moving any list-owned identifier, allocation, vtable, packet field, or runtime branch. The existing family score is intentionally unchanged; only the accepted shared-base ownership/formal-source defect is corrected.
