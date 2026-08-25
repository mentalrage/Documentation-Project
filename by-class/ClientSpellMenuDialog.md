*** UID:00002R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ClientSpellMenuDialog definitions are emitted by source child UID0004Y6.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "MerchantDialogPane.h"

class ClientSpellMenuDialog : public MerchantDialogPane
{
public:
    ClientSpellMenuDialog(const RectBounds& bounds,
                          const unsigned char *payload,
                          unsigned char menuMode);

protected:
    void HandleMenuCommand(int commandId, void *context);
    void UpdateActionButtonState();

private:
    unsigned char m_packetSubtype;        // +0x274
    unsigned char m_reserved275[3];       // +0x275..+0x277
};

typedef char ClientSpellMenuDialogSizeMustBe632[
    (sizeof(ClientSpellMenuDialog) == 0x278) ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClientSpellMenuDialog

## Status

- Likely source file: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md).
- Exact method child: [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md).
- Parent split index: [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md).
- Direct vtable anchor: [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md).
- Formal source route: this class page emits the ordered client-dialog H declaration and an explicit CPP delegation comment; exact by-memory child UID0004Y6 owns the constructor/command/update definitions.

## Class Purpose

`ClientSpellMenuDialog` displays spell actions built from local player spell data. It parses the packet shell and object preview, populates the list from one-based local spell slots, and sends the selected spell slot/action byte in an opcode `0x39` packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClientSpellMenuDialog` constructor | `0x0051db40-0x0051e4d3` | Parses packet/object data, creates `ClientSpellMenuItemList`, loops one-based slots `1..52`, tests active byte at `g_pUserPane + slot * 0x148 + 0x13a834`, copies display name from `+0x13a83c`, builds the `DLGMERC1` shell, and installs child slot `6`. |
| `HandleMenuCommand` | `0x0051e4e0-0x0051e5f2` | Command id `1` sends selected one-byte spell slot/action byte and closes, command id `2` sends request/previous through `0x00517ec0`, command id `3` closes, and all other ids return. |
| `UpdateActionButtonState` | `0x0051e600-0x0051e63d` | Fetches child slot `1` action button and child slot `6` client spell list, calls `ListPane::GetSelectionCount` on list storage `+0x108`, and enables/disables the action button through virtual slots `+0x4c/+0x50`. |

## Evidence Notes

- MCP session `80de0a67` reports constructor refs from `0x0051770b` and `0x00517c07`, command/update vtable refs at `0x0061f310` and `0x0061f314`, and `0xcc` padding around all three method endpoints.
- The client action path sends opcode `0x39` through [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md), which serializes the selected row byte at `+0`; stale "spell code" wording is replaced with one-byte selected spell slot/action byte.
- The constructor's local spell data reads are a typed view of [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md), not a standalone `SpellManager` global.
- The request command uses route `0x00517ec0` and is separate from the inherited `MerchantDialogPane` action-string virtual at `0x00517d80`.
- The stale generated `ChattingColorListPane*` local type is rejected. MCP found the real chat-color constructor `0x00482fb0` only has chat callers `0x00482837` and `0x0048295d`, while this dialog constructs `ClientSpellMenuItemList` and its renderer reads spell row text from `entry + 4`.

## Cross-References

- [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md)
- [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md)
- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md)
- [UID:0000D3][ServerSpellMenuDialog](by-class/ServerSpellMenuDialog.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md)
- [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)

## Changes

- 2026-08-22 B002 UID0000OP Gate 2A empty-emitter closure: set ordered emitter position `30`, added explicit CPP delegation to UID0004Y6, and retained the complete inherited-base H declaration.
- 2026-08-22 B002 UID0000OP implementation callback: verified the complete derived H declaration inherits `MerchantDialogPane::m_menuObjectId +0x270` and `SendMenuRequestPacket()` without redeclaring either; only `m_packetSubtype +0x274` and three padding bytes remain derived.
- 2026-06-23 B001 accepted implementation: raised from `86/90` to `90/91`, updated exact half-open method endpoints, linked the new method child, and incorporated one-based spell slot loop, `g_pUserPane` offsets `+0x13a834/+0x13a83c`, selected spell slot/action byte wording, request route, close behavior, ChattingColorListPane rejection, and formal C++ location.

## B002 UID0000OP Accepted Shared-Base Reconciliation

Exact 0x278 declaration: inherited base `m_menuObjectId +0x270`/request method, packet subtype +0x274, three-byte padding, complete H with no inherited-member redeclaration, and method source on UID0004Y6.

All five factory wrappers allocate exactly `0x278`; live constructors place the packet dword at `this+0x270` and the family byte at `this+0x274`. This proves one inherited dword plus one derived byte and three bytes of tail padding without moving any list-owned identifier, allocation, vtable, packet field, or runtime branch. The existing family score is intentionally unchanged; only the accepted shared-base ownership/formal-source defect is corrected.
