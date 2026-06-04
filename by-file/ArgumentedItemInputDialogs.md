*** UID:0000HH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ArgumentedItemInputDialogs

## Status

- Confidence: strong for the confirm/quantity dialog behavior, exact function boundaries, vtable anchors, caller set, and packet-send helper format.
- Remaining caveat: medium-high for whether the original source file was standalone or folded into `ArgumentedMenuDialogs.cpp`/`TextMenuDialogs.cpp`; the preferred reconstruction folder is `NexusTK/ui/dialogs/`.
- Proposed module folder: `ui/dialogs/`
- Candidate file: `NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp`
- Possible folded owner: `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp`
- Evidence basis: live IDA MCP function/disassembly/decompilation checks on 2026-06-04, including direct xrefs, tail instructions, vtable/RTTI data, resource/string refs, and packet constants.

## Hypothesis

The original client likely kept the argumented item purchase confirmation and quantity dialogs near the argumented merchant menu code. These panes are not general item-action prompts: they are opened from an argumented menu row, validate the displayed price, optionally ask for a quantity, and send fixed opcode `0x39` using the copied argumented menu context.

Likely compact source layout:

```text
NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp
NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp
```

Possible folded layout:

```text
NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp
```

## Proposed Contents

| Entity | Exact range | Role |
| --- | --- | --- |
| `ShowBuyConfirmDialog` / `OpenArgumentedItemConfirmDialog` | `0x0051f450-0x0051f4fe` | Reads the selected argumented menu entry, formats the buy/price-confirm prompt, allocates `ArgumentedItemConfirmInputDialogPane`, and passes item/argument/price context. |
| `OpenQuantityDialogOrSendSingle` | `0x0051f510-0x0051f5a5` | Sends quantity `1` directly when count is `0` or `1`; otherwise allocates `ArgumentedItemQuantityInputDialogPane` with prompt resource id `246`. |
| `SendArgumentedItemQuantityPacket` | `0x0051f640-0x0051f706` | Serializes the final 14-byte opcode `0x39` argumented item quantity packet and sends it through the client packet sender. |
| `ArgumentedItemQuantityInputDialogPane` constructor | `0x0051fc90-0x0051ff6c` | Builds the `ArgumentQuantity` dialog and copies menu/list context. |
| `ArgumentedItemQuantityInputDialogPane` action handler | `0x0051ff70-0x005200c4` | Parses quantity text, validates `1..100`, shows validation alerts, sends the packet, and closes the dialog. |
| `ArgumentedItemConfirmInputDialogPane` constructor | `0x005200d0-0x005203be` | Builds the price-confirm dialog and stores copied menu context, available quantity, expected price, and selected argument id. |
| `ArgumentedItemConfirmInputDialogPane` action handler | `0x005203c0-0x00520539` | Validates typed price, alerts on mismatch, sends quantity `1`, or opens the quantity dialog. |

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- Function boundaries and tails:
  - `0x0051f450-0x0051f4fe`, final `retn` at `0x0051f4fd`; no direct code/data refs to the start.
  - `0x0051f510-0x0051f5a5`, final `retn 8` at `0x0051f5a2`; no direct code/data refs to the start.
  - `0x0051f640-0x0051f706`, final `retn 8` at `0x0051f703`.
  - `0x0051fc90-0x0051ff6c`, final `retn 0Ch` at `0x0051ff69`.
  - `0x0051ff70-0x005200c4`, final `retn 8` at `0x005200c1`.
  - `0x005200d0-0x005203be`, final `retn 14h` at `0x005203bb`.
  - `0x005203c0-0x00520539`, final `retn 8` at `0x00520536`.
- `SendArgumentedItemQuantityPacket` has direct call refs from `0x0051f504`, `0x0051f58d`, `0x0052008e`, and `0x00520501`, covering both helper paths and both dialog action paths.
- The quantity dialog constructor is called from `0x0051f570` and `0x005204ec`; the confirm dialog constructor is called from `0x0051f22a` and `0x0051f4de`.
- Constructor vtable stores anchor the two classes:
  - Quantity stores `??_7ArgumentedItemQuantityInputDialogPane@@6B@` at `0x0051fcec`, plus secondary vtables at `0x0051fcf2` and `0x0051fcfc`.
  - Confirm stores `??_7ArgumentedItemConfirmInputDialogPane@@6B@` at `0x00520147`, plus secondary vtables at `0x0052014d` and `0x00520157`.
- Vtable data refs point to the action handlers: `0x0061f5d0 -> 0x0051ff70` for the quantity handler and `0x0061f66c -> 0x005203c0` for the confirm handler.
- `0x00520046` resolves inside `0x0051ff70-0x005200c4`, not to a separate function start.
- The next function starts at `0x00520540` and belongs to `ObjectImageControlPane`, so the argumented input-dialog memory slice ends before that function.

Behavior evidence from live decompilation/disassembly:

- `0x0051f450` checks the selected row index, fetches the row context, uses the buy/price-confirm prompt string, and calls the confirm-dialog constructor at `0x005200d0`.
- `0x0051f510` branches on quantity `<= 1`: it calls `0x0051f640` with quantity `1`, otherwise allocates class id `628`, reads prompt resource id `246` through `dword_67A750`, and calls `0x0051fc90`.
- `0x0051f640` writes opcode `0x39`, context fields from offsets `+0x14c`, `+0x150`, and `+0x154`, the selected argument id, and the quantity byte, then sends 14 bytes through `dword_67A7EC`.
- `0x0051ff70` parses decimal input, rejects values above `100` with the `You can't buy more than 100.` alert string, rejects zero with the `How much?` alert string, and calls `0x0051f640` for valid nonzero quantities.
- `0x005203c0` parses the typed price, compares it with the expected price stored in the confirm dialog, uses the `Price is different.` alert string on mismatch, and otherwise dispatches to `0x0051f640` or `0x0051fc90`.

## Ownership Notes

- These helpers and panes belong to the argumented merchant/menu purchase flow, not chat-color, generic item-dialog, or frame-chrome code.
- `SendArgumentedItemQuantityPacket` consumes the `ArgumentedMenuMenuItemList` context layout: command type at `+0x14c`, owner id at `+0x150`, list parameter at `+0x154`, and owner dialog pointer at `+0x158`.
- The no-direct-xref status of `0x0051f450` and `0x0051f510` remains the main reachability caveat. Their bodies still match the argumented item purchase flow and are adjacent to the argumented menu/input dialog island.
- The final standalone-vs-folded file decision should be made with the neighboring [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) and [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) pages.

## Migration Notes

Preferred migration, once the broader argumented-menu source split is finalized:

```text
NexusTK/ui/dialogs/ArgumentedItemInputDialogs.cpp
  ArgumentedItemConfirmInputDialogPane
  ArgumentedItemQuantityInputDialogPane
  OpenArgumentedItemConfirmDialog / ShowBuyConfirmDialog
  OpenQuantityDialogOrSendSingle
  SendArgumentedItemQuantityPacket
```

Do not write final reconstruction C++ yet. The behavior and boundaries are strong, but final source-facing names, signatures, and the standalone-vs-folded source decision are still below the 95/95 final-code bar.

## Cross-References

- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
- [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)

## Changes

- 2026-06-04: Raised grading from `72/82` to `82/88` and set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/dialogs/`.
  - Before: the page relied on stale non-live provenance and older IDA notes, had inclusive endpoint wording for several ranges, and left the proposed path blank.
  - After: the page uses live IDA MCP evidence for exact half-open boundaries, direct refs, vtable stores, handler vtable slots, packet constants, resource/string refs, and false-start handling for `0x00520046`.
  - Score rationale: completion increased because the helper, constructor, action-handler, vtable, and packet-send evidence now reconstructs the module shape with high confidence. It remains below final-code level because `0x0051f450`/`0x0051f510` still have no direct start refs and the final standalone-vs-folded source split is unresolved.
