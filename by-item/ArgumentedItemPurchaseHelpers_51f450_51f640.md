*** UID:0000TY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000I | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ArgumentedItemPurchaseHelpers_51f450_51f640

## Status

- Disposition: non-emitting procurement/purchase-helper index.
- Confidence: strong for helper behavior, exact child split, direct packet-helper call refs, packet constants, and corrected source placement.
- Remaining caveat: `0x0051f450` and `0x0051f510` have no direct code/data refs, VA/RVA pointer hits, rel32 calls, or rel32 jumps to their starts in the dated IDB/PE scan. This remains a raw-start liveness confidence cap, but complete retained bodies, source adjacency, row/context flow, and exact input-dialog dependencies make it unsuitable as a source-emission blocker.
- Canonical source owner for exact helper children: [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md).
- Exact source-bearing child pages: [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md), [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md), and [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md).
- Input dialog relation: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) owns the input pane constructors/actions that consume the list helpers; it is not the canonical source owner for `0x0051f450`, `0x0051f510`, or `0x0051f640`.

## Helper Summary

| Address range | Proposed name | Behavior |
| --- | --- | --- |
| [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md) | `ArgumentedMenuOpenBuyConfirmDialog` | Reads the selected argumented menu entry, formats the buy/price-confirm prompt, allocates `ArgumentedItemConfirmInputDialogPane`, and passes item id, argument id, and expected price. |
| [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md) | `ArgumentedMenuOpenQuantityDialogOrSendSingle` | If available quantity is `0` or `1`, sends quantity `1` through [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md); otherwise allocates `ArgumentedItemQuantityInputDialogPane` using prompt resource id `246`. |
| [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md) | `ArgumentedMenuSendItemQuantityPacket` | Serializes the final 14-byte opcode `0x39` argumented item purchase packet from the selected `ArgumentedMenuMenuItemList` context and sends it through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / historical `dword_67A7EC`. |

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

2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed:

- `lookup_funcs` reports `0x0051f450` size `0xae`, `0x0051f510` size `0x95`, and `0x0051f640` size `0xc6`; `0x00520046` still resolves inside `sub_51FF70` rather than a separate function.
- `xrefs_to 0x0051f450` and `xrefs_to 0x0051f510` remain empty, preserving the live-reachability caveat for the confirm and quantity-or-send helper starts.
- `xrefs_to 0x0051f640` still reports four direct call sites at `0x0051f504`, `0x0051f58d`, `0x0052008e`, and `0x00520501`.
- Decompilation of `0x0051f450` shows allocation of `636 == 0x27c` bytes (verified with `int_convert.py`) and a call to the confirm input-dialog constructor path at `0x005200d0`.
- Decompilation of `0x0051f510` still sends quantity `1` directly when the available count is `<= 1`, otherwise reads prompt resource id `246 == 0xf6` (verified with `int_convert.py`) and allocates the quantity input dialog.
- Decompilation of `0x0051f640` writes opcode `57 == 0x39` and sends length `14 == 0x0e` (both verified with `int_convert.py`) through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), with context fields read from offsets `+0x14c`, `+0x150`, and `+0x154`.

2026-06-16 A001 live IDA/PE refresh on session `b001_selflookpane_0001H7_20260616` reconfirmed:

- `lookup_funcs` still reports `0x0051f450` as `sub_51F450` size `0xae`, `0x0051f510` as `sub_51F510` size `0x95`, and `0x0051f640` as named `SendArgumentedItemQuantityPacket` size `0xc6`; the four dialog methods at `0x0051fc90`, `0x0051ff70`, `0x005200d0`, and `0x005203c0` retain their current constructor/action names.
- `xrefs_to` still returns zero refs for `0x0051f450` and `0x0051f510`. It returns four refs to `0x0051f640`: raw jump at `0x0051f504`, call from `sub_51F510` at `0x0051f58d`, quantity action call at `0x0052008e`, and confirm action call at `0x00520501`.
- `xrefs_to` reconfirms quantity constructor calls at `0x0051f570` and `0x005204ec`, confirm constructor calls at `0x0051f22a` and `0x0051f4de`, and handler vtable refs at `0x0061f5d0` and `0x0061f66c`.
- Section-mapped PE scanning of `NexusTK.exe` found zero absolute VA pointer hits, zero RVA pointer hits, and zero rel32 calls/jumps to `0x0051f450` or `0x0051f510`. The same scan found exactly the four expected rel32 references to `0x0051f640` and no pointer hits.
- Byte reads around `0x0051f430`, `0x0051f510`, and `0x0051f640` reconfirm alignment-separated function bodies, including `0xcc` padding before the first two helper starts and after the packet helper tail.

## Ownership Decision

These helpers are argumented merchant/menu purchase helpers, not chat-color, frame-chrome, or generic item-dialog code. B001 2026-06-16 corrected the source route: the helpers operate on `ArgumentedMenuMenuItemList` selected-row/context fields, while the input panes are callees or callers. Exact source-bearing behavior is carried by [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md), [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md), and [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md); this item page is an index only.

Do not migrate `0x0051f450` as chat-color code. Do not model `0x00520046` as an alert, ranking, chat, or separate pane method.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page now records current function sizes, exact child pages, direct send-helper xrefs, confirm/quantity dialog construction behavior, packet opcode/length, field offsets, false-start exclusion, corrected list-class owner route, and non-emitting index disposition. |
| Confidence | 90 | IDA decompilation, xrefs, bytes, and PE scanning strongly support the argumented purchase-helper behavior and route through `ArgumentedMenuMenuItemList`. Confidence stays below final-source quality because `0x0051f450` and `0x0051f510` still have no direct refs and helper names remain provisional. |

## Cross-References

- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md)
- [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md)
- [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md)
- [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md)
- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
- [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md)

## Changes

- 2026-08-17 B010 source-quality closure:
  - Preserved this page as a non-emitting helper index at `88/90` with direct owner [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md).
  - Resolved source-facing child names and dispositions: [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md), [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md), and [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md) now emit their source-ready definitions through UID00000I.
  - The first two raw starts still have zero direct routes, and that negative evidence is retained. It caps confidence rather than overriding their complete source-shaped bodies or moving ownership to the input-dialog classes.

- 2026-06-16 A001 file/item completion refresh:
  - Before: `85/89`; owner/emitter already [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), final C++ blank.
  - Changed to: `86/90`; owner/emitter and blank final C++ unchanged.
  - Evidence: live IDA MCP `lookup_funcs`, `analyze_component`, `xrefs_to`, and `get_bytes` reconfirmed the helper/dialog function inventory, internal call edges, constructor/action refs, vtable refs, and padding-bounded helper bodies. A section-mapped PE scan found no VA/RVA pointer hits or rel32 refs to `0x0051f450`/`0x0051f510`, and exactly the four documented rel32 refs to `SendArgumentedItemQuantityPacket`. The no-reachability state for the first two helper starts is therefore documented as a real blocker, not a missing check.

- 2026-06-16 B001 supervisor-applied source-route correction:
  - Before: `86/90`, reconstructable, owner/emitter [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md).
  - Changed to: `88/90`, non-emitting index, owner [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md), blank emitter, and exact source-bearing children [UID:0003VI][0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog](by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md), [UID:0003VJ][0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle](by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md), and [UID:0003VL][0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket](by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md).
  - Evidence: B001 report-only split audit showed the helper bodies consume selected `ArgumentedMenuMenuItemList` context and only call or construct the input panes; input dialog docs own the pane constructors/actions, not these list helpers.

- 2026-06-07: Replaced the raw `dword_67A7EC` argumented item send reference with canonical [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) wording.
  - Before: the helper summary and live IDA evidence described the final packet send through the historical generated global only.
  - After: the page links the resolved packet sender while retaining the historical label and `sub_574BB0` call evidence.
  - Evidence: the generated resolved-name report maps `dword_67A7EC` to `g_packetSender`, and the existing IDA evidence ties `0x0051f640` to the 14-byte opcode `0x39` argumented item purchase packet.

- 2026-06-04: Raised grading from `76/82` to `82/88`, marked `RECONSTRUCTABLE:TRUE`, and attached owner/emitter route `0000HH`.
  - Before: the page documented helper behavior and older IDA starts, but still carried stale ownership/provenance caveats and had no parent attachment.
  - After: live IDA MCP evidence records exact half-open boundaries, helper tail instructions, direct refs to the packet helper, prompt/resource/global refs, packet opcode/length, context offsets, and false-start handling for `0x00520046`.
  - Score rationale: completion and confidence increased because the helper cluster now has strong live evidence tying it to the argumented input-dialog parent. It remains below final-code level because `0x0051f450`/`0x0051f510` still lack direct start refs and final source-facing helper names are provisional.
- 2026-06-14 A001: Raised from `82/88` to `85/89`.
  - Before: the page contained 2026-06-04 evidence but retained legacy parent wording and lacked a current ref/decompile refresh.
  - After: added current IDA evidence for all three helper sizes, preserved the no-xref caveat for the first two helpers, reconfirmed the four packet-helper call sites, documented confirm/quantity construction behavior, and verified packet/resource constants with `int_convert.py`.
  - Evidence: live IDA MCP `lookup_funcs`, `analyze_function`, `xrefs_to`, and targeted decompile checks on `0x0051f450`, `0x0051f510`, `0x0051f640`, and `0x00520046`.
