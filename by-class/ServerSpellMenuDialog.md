*** UID:0000D3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SpellMenuDialogs.h"
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "MerchantDialogPane.h"
#include "../controls/ListPane.h"

class DrawContext;
struct Rect;

class ServerSpellMenuDialog : public MerchantDialogPane
{
public:
    ServerSpellMenuDialog(const RectBounds& bounds,
                          const unsigned char *payload,
                          unsigned char menuMode);

protected:
    void HandleMenuCommand(int commandId, void *context);
    void UpdateActionButtonState();

private:
    unsigned char m_packetSubtype;        // +0x274
    unsigned char m_reserved275[3];       // +0x275..+0x277
};

typedef char ServerSpellMenuDialogSizeMustBe632[
    (sizeof(ServerSpellMenuDialog) == 0x278) ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ServerSpellMenuDialog

## Status

- Likely source file: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md).
- Exact method child: [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md).
- Parent split index: [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md).
- Direct vtable anchor: [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md).
- Formal source route: this class page emits the shared `SpellMenuDialogs.h` include and the ordered server-dialog H declaration; exact by-memory child UID0004Y4 owns the constructor/command/update definitions.

## Class Purpose

`ServerSpellMenuDialog` displays spell actions supplied by server packet data. It parses the packet text and row strings, builds a merchant-style spell menu, and sends the selected row text back in an opcode `0x39` packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ServerSpellMenuDialog` constructor | `0x0051ca40-0x0051d51a` | Parses packet/object data, creates `ServerSpellMenuItemList`, appends server-supplied row names, builds the `DLGMERC1` shell, and installs child slot `6`. |
| `HandleMenuCommand` | `0x0051d520-0x0051d6b2` | Command id `1` sends selected server row name and closes, command id `2` sends request/previous through `0x00517ec0`, command id `3` closes, and all other ids return. |
| `UpdateActionButtonState` | `0x0051d6c0-0x0051d6fd` | Fetches child slot `1` action button and child slot `6` server spell list, calls `ListPane::GetSelectionCount` on list storage `+0x108`, and enables/disables the action button through virtual slots `+0x4c/+0x50`. |

## Evidence Notes

- MCP session `80de0a67` reports constructor refs from `0x005176c3` and `0x00517b77`, command/update vtable refs at `0x0061f1b0` and `0x0061f1b4`, and `0xcc` padding around all three method endpoints.
- The server action path sends opcode `0x39` through [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md), which serializes the selected row text from server row offset `+2`.
- The request command uses route `0x00517ec0` and is separate from the inherited `MerchantDialogPane` action-string virtual at `0x00517d80`.
- The action-button updater's shared behavior is indexed by [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md), but exact source emission lives on [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md).

## Cross-References

- [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md)
- [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md)
- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md)
- [UID:00002R][ClientSpellMenuDialog](by-class/ClientSpellMenuDialog.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md)
- [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md)

## Changes

- 2026-08-22 B002 UID0000OP Gate 2A empty-emitter closure: set ordered emitter position `5`, emitted `#include "SpellMenuDialogs.h"` through the CPP channel, retained the complete inherited-base H declaration, and left all runtime definitions on exact source child UID0004Y4.
- 2026-08-22 B002 UID0000OP implementation callback: verified the complete derived H declaration inherits `MerchantDialogPane::m_menuObjectId +0x270` and `SendMenuRequestPacket()` without redeclaring either; only `m_packetSubtype +0x274` and three padding bytes remain derived.
- 2026-06-23 B001 accepted implementation: raised from `88/90` to `90/91`, updated exact half-open method endpoints, linked the new method child, and incorporated command ids `1/2/3`, request route `0x00517ec0`, server row-name send behavior, close behavior, action-button state evidence, and formal C++ location.

## B002 UID0000OP Accepted Shared-Base Reconciliation

Exact 0x278 declaration: inherited base `m_menuObjectId +0x270`/request method, packet subtype +0x274, three-byte padding, complete H with no inherited-member redeclaration, and method source on UID0004Y4.

All five factory wrappers allocate exactly `0x278`; live constructors place the packet dword at `this+0x270` and the family byte at `this+0x274`. This proves one inherited dword plus one derived byte and three bytes of tail padding without moving any list-owned identifier, allocation, vtable, packet field, or runtime branch. The existing family score is intentionally unchanged; only the accepted shared-base ownership/formal-source defect is corrected.
