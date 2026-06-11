*** UID:0000TY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArgumentedItemPurchaseHelpers_51f450_51f640

## Status

- Confidence: strong for helper behavior, exact function boundaries, direct packet-helper call refs, packet constants, and source placement.
- Remaining caveat: `0x0051f450` and `0x0051f510` have no direct code/data refs to their starts in the current IDB, so their live reachability remains unresolved.
- Proposed owner file: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), possibly folded into [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md)
- Exact memory ranges: [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) and [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md)
- Parent attachment: attached to [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), now `82/88`, because the helper cluster and parent both have live IDA-backed high confidence.

## Helper Summary

| Address range | Proposed name | Behavior |
| --- | --- | --- |
| `0x0051f450-0x0051f4fe` | `ShowBuyConfirmDialog` / `OpenArgumentedItemConfirmDialog` | Reads the selected argumented menu entry, formats the buy/price-confirm prompt, allocates `ArgumentedItemConfirmInputDialogPane`, and passes item id, argument id, and expected price. |
| `0x0051f510-0x0051f5a5` | `OpenQuantityDialogOrSendSingle` | If available quantity is `0` or `1`, sends quantity `1` through `SendArgumentedItemQuantityPacket`; otherwise allocates `ArgumentedItemQuantityInputDialogPane` using prompt resource id `246`. |
| `0x0051f640-0x0051f706` | `SendArgumentedItemQuantityPacket` | Serializes the final 14-byte opcode `0x39` argumented item purchase packet from the selected `ArgumentedMenuMenuItemList` context and sends it through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / historical `dword_67A7EC`. |

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- `0x0051f450-0x0051f4fe`, size `0xae`, final `retn` at `0x0051f4fd`; no direct code/data refs to the start.
- `0x0051f510-0x0051f5a5`, size `0x95`, final `retn 8` at `0x0051f5a2`; no direct code/data refs to the start.
- `0x0051f640-0x0051f706`, size `0xc6`, final `retn 8` at `0x0051f703`.
- `0x0051f450` reads the selected row index, fetches row context, references the buy/price-confirm prompt string, and calls `0x005200d0` at `0x0051f4de`.
- `0x0051f510` sends quantity `1` directly for `<= 1`, otherwise allocates class id `628`, reads prompt resource id `246` through `dword_67A750`, and calls the quantity constructor at `0x0051f570`.
- `0x0051f640` writes opcode `0x39`, context fields from offsets `+0x14c`, `+0x150`, and `+0x154`, a constant item-action byte `1`, the selected argument id, and the requested quantity, then sends 14 bytes through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / historical `dword_67A7EC` with `sub_574BB0`.
- Direct calls to `0x0051f640` come from `0x0051f504`, `0x0051f58d`, `0x0052008e`, and `0x00520501`.
- `0x00520046` resolves inside the quantity action handler `0x0051ff70-0x005200c4`, not to a separate function start.

## Ownership Decision

These helpers are argumented merchant/menu purchase helpers, not chat-color, frame-chrome, or generic item-dialog code. The strongest source placement is `NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp` because the helpers construct or call the two argumented input panes and share their packet sender. If final migration folds input panes into `ArgumentedMenuDialogs.cpp`, these helpers should move with that argumented-menu source family.

Do not migrate `0x0051f450` as chat-color code. Do not model `0x00520046` as an alert, ranking, chat, or separate pane method.

## Cross-References

- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
- [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md)

## Changes

- 2026-06-07: Replaced the raw `dword_67A7EC` argumented item send reference with canonical [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) wording.
  - Before: the helper summary and live IDA evidence described the final packet send through the historical generated global only.
  - After: the page links the resolved packet sender while retaining the historical label and `sub_574BB0` call evidence.
  - Evidence: the generated resolved-name report maps `dword_67A7EC` to `g_packetSender`, and the existing IDA evidence ties `0x0051f640` to the 14-byte opcode `0x39` argumented item purchase packet.

- 2026-06-04: Raised grading from `76/82` to `82/88`, marked `RECONSTRUCTABLE:TRUE`, and attached `AUTOGEN_PARENT_UID:0000HH`.
  - Before: the page documented helper behavior and older IDA starts, but still carried stale ownership/provenance caveats and had no parent attachment.
  - After: live IDA MCP evidence records exact half-open boundaries, helper tail instructions, direct refs to the packet helper, prompt/resource/global refs, packet opcode/length, context offsets, and false-start handling for `0x00520046`.
  - Score rationale: completion and confidence increased because the helper cluster now has strong live evidence tying it to the argumented input-dialog parent. It remains below final-code level because `0x0051f450`/`0x0051f510` still lack direct start refs and final source-facing helper names are provisional.
