*** UID:000029 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanDepItemDialog

## Status

- Confidence: strong for confirmed methods; medium for the shared slide animation owner.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Current recovered file: `source-3/simroot_v2/class_ClanDepItemDialog.cpp`

## Class Purpose

`ClanDepItemDialog` is the clan-bank item deposit dialog. It parses packet-supplied depositor and item-description text, creates the `DL` dialog with an item list and amount edit control, sends a deposit-item packet, and closes through the shared dialog animation path. Its item picker is the reusable [UID:00008W][MyItemListPane](by-class/MyItemListPane.md), not a clan-private list pane.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanDepItemDialog` | `0x0048a1c0-0x0048a689` | Builds the dialog, decodes packet text, creates item/object list and amount edit controls, and attaches to the desktop/main window. |
| vtable-reset helper | `0x0048a690-0x0048a6af` | Real IDA function with no Wave3 memory owner; resets class vtables before base cleanup. |
| `OnButtonClick` | `0x0048a6b0-0x0048a780` | On OK, reads selected item and amount, sends deposit packet, then OK/Cancel closes. |
| `SendDepositItemPacket` | `0x0048a790-0x0048a804` | Sends opcode `0x4b`, subtype `5`, action `1`, deposit mode, and big-endian amount via `g_packetSender`. |
| `AnimateSlideIn` | `0x0049ec80-0x0049ed57` | Horizontal slide animation using map repaint and motion offsets. |

## Evidence Notes

- IDA confirms real starts at `0x0048a1c0`, `0x0048a690`, `0x0048a6b0`, `0x0048a790`, and `0x0049ec80`.
- IDA reports a `MyItemListPane` constructor call at `0x0048a50d` inside the dialog constructor.
- The generated source's `g_packetSender` queue path matches other clan opcode `0x4b` item dialog flows.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010O][0x0048a1c0-0x0048a805.ClanDepItemDialog](by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md)
- [UID:00012V][0x0049ec80-0x0049ee41.ClanDialogSlideAnimation](by-memory/0x0049ec80-0x0049ee41.ClanDialogSlideAnimation.md)
- [UID:00002F][ClanItemDialog](by-class/ClanItemDialog.md)
- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)

## Changes

- What existed before: the page documented item-deposit dialog behavior, packet sender, MyItemListPane ownership, and slide animation caveat, but metadata remained `0/0`.
- What it was changed to: scores were set to `72/80`.
- Summary and evidence: constructor, vtable reset, button action, deposit packet helper, and item-list dependency are covered; shared slide animation ownership and detailed dialog field layout remain open.
