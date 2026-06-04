*** UID:000029 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanDepItemDialog

## Status

- Confidence: strong for constructor, vtable, button-handler, and packet-sender evidence; medium for exact field names and shared slide-helper ownership.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)

## Class Purpose

`ClanDepItemDialog` is the clan-bank item deposit dialog. It parses packet-supplied depositor and item-description text, creates the `DL` dialog with an item list and amount edit control, sends a deposit-item packet, and closes through the shared dialog animation path. Its item picker is the reusable [UID:00008W][MyItemListPane](by-class/MyItemListPane.md), not a clan-private list pane.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanDepItemDialog` | `0x0048a1c0-0x0048a68a` | Builds the dialog, decodes packet text, creates item/object list and amount edit controls, and attaches to the desktop/main window. |
| vtable-reset helper | `0x0048a690-0x0048a6af` | Standalone reset helper; resets class vtables before base cleanup. |
| `OnButtonClick` | `0x0048a6b0-0x0048a781` | On OK, reads selected item and amount, sends the deposit packet through virtual slot `0x5c`, then OK/Cancel closes. |
| `SendDepositItemPacket` | `0x0048a790-0x0048a805` | Sends opcode `0x4b`, subtype `5`, action `1`, deposit mode, and big-endian amount through the packet sender. |
| shared slide-in helper | `0x0049ec80-0x0049ed58` | Horizontal slide animation dependency used by this dialog and sibling clan dialogs. |
| shared slide-close helper | `0x0049ed60-0x0049ee42` | Close animation dependency used by this dialog and other clan-bank dialog paths. |

## Evidence Notes

- Live IDA `py_eval` on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms modeled ranges `0x0048a1c0-0x0048a68a`, `0x0048a690-0x0048a6af`, `0x0048a6b0-0x0048a781`, `0x0048a790-0x0048a805`, `0x0049ec80-0x0049ed58`, and `0x0049ed60-0x0049ee42`; padding between adjacent bodies is `0xcc`.
- Constructor callers are `0x0048516e` inside `0x00484f70` and `0x00487e83` inside `0x00487e20`, matching the clan status/packet dialog-open path.
- Constructor vtable stores are `0x0048a21a -> 0x0061607c`, `0x0048a220 -> 0x006160e0`, and `0x0048a22a -> 0x00616110`. The primary vtable places `OnButtonClick` in slot 18 (`0x006160c4 -> 0x0048a6b0`) and `SendDepositItemPacket` in slot 23 (`0x006160d8 -> 0x0048a790`).
- The dialog allocates the reusable [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) at constructor call site `0x0048a50d`. Live caller fanout for `0x004aeb30` is `ClanDepItemDialog`, `AddItemDialog`, and `MixItemDialog`, so the picker remains shared item UI support.
- `OnButtonClick` branches on button ids `1` and `2`; the OK path reads the selected item from the list, parses the amount text, dispatches through virtual slot `0x5c`, and then calls the shared close helper at `0x0049ed60`.
- `SendDepositItemPacket` writes byte sequence pieces for opcode `0x4b`, subtype `5`, action `1`, deposit mode, and amount, then reads `dword_67A7EC` and calls `0x00574bb0` with length `6`.
- The slide helpers are intentionally kept as shared dependencies: `0x0049ec80` also has sibling clan-dialog callers, and `0x0049ed60` is called from clan money/item dialogs plus `ClanBankPane`.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010O][0x0048a1c0-0x0048a805.ClanDepItemDialog](by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md)
- [UID:00012V][0x0049ec80-0x0049ee41.ClanDialogSlideAnimation](by-memory/0x0049ec80-0x0049ee41.ClanDialogSlideAnimation.md)
- [UID:00002F][ClanItemDialog](by-class/ClanItemDialog.md)
- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)

## Changes

- Earlier baseline: the page documented item-deposit dialog behavior, packet sender, MyItemListPane ownership, and slide animation caveat, but metadata remained unevaluated.
- Earlier scoring pass: scores were set to `72/80` because constructor, vtable reset, button action, deposit packet helper, and item-list dependency were covered; shared slide animation ownership and detailed dialog field layout remained open.
- 2026-06-04: Raised from `72/80` to `82/86`, marked reconstructable, and attached to [UID:0000I9][ClanBank](by-file/ClanBank.md).
  - Before: page had strong behavior notes but lacked live boundary/caller/vtable evidence, had no reconstructable/parent metadata, and still included a recovered-file provenance line.
  - After: live IDA evidence records the executable identity, exact function ranges and padding, constructor callers, three vtable stores, virtual slots for button handling and packet send, `MyItemListPane` reuse, packet byte layout, and shared slide-helper caller caveat.
  - Reasoning: this is enough for reconstructable class-level documentation and parent attachment because [UID:0000I9][ClanBank](by-file/ClanBank.md) is already `86/80` with a valid `NexusTK/social/` path. Completion stays below the high-reconstruction threshold because final field names, signatures, and shared animation helper ownership remain provisional.
