*** UID:0000HH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ArgumentedItemInputDialogs

## Status

- Confidence: strong for confirm/quantity dialog behavior and boundaries; medium for whether the original source split was separate from `ArgumentedMenuDialogs.cpp`.
- Proposed module folder: `ui/dialogs/`
- Candidate file: `ui/dialogs/ArgumentedItemInputDialogs.cpp`
- Possible folded owner: `ui/dialogs/ArgumentedMenuDialogs.cpp`
- Current generated sources: `class_ArgumentedItemConfirmInputDialogPane.cpp`, `class_ArgumentedItemQuantityInputDialogPane.cpp`, and recovered helper `recovered/SendArgumentedItemQuantityPacket_0051F640.cpp`
- Evidence basis: Wave3 class summaries, generated `simroot_v2` source, Wave2 recovered helper notes, and targeted IDA MCP checks on 2026-05-23 and 2026-05-24.

## Hypothesis

The original client likely kept the argumented item purchase confirmation and quantity dialogs near the argumented merchant menu code. These panes are not general item-action prompts: they are opened from an argumented menu row, validate the displayed price, optionally ask for a quantity, and send a fixed opcode `0x39` payload using the selected argumented menu context.

Likely compact source layout:

```text
ui/dialogs/ArgumentedMenuDialogs.cpp
ui/dialogs/ArgumentedItemInputDialogs.cpp
```

Possible folded layout:

```text
ui/dialogs/ArgumentedMenuDialogs.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `ShowBuyConfirmDialog` / `OpenArgumentedItemConfirmDialog` | `0x0051f450-0x0051f4fd` | currently `class_ChattingColorListPane.cpp` | Opens `ArgumentedItemConfirmInputDialogPane` for the selected argumented menu entry; generated owner is polluted. |
| `OpenQuantityDialogOrSendSingle` | `0x0051f510-0x0051f5a4` | no current Wave3 method owner | Sends quantity `1` directly or opens `ArgumentedItemQuantityInputDialogPane` when quantity is greater than one. |
| `SendArgumentedItemQuantityPacket` | `0x0051f640-0x0051f705` | `recovered/SendArgumentedItemQuantityPacket_0051F640.cpp` | Serializes the final opcode `0x39` argumented item quantity packet. |
| `ArgumentedItemQuantityInputDialogPane` | `0x0051fc90-0x005200c3` | `class_ArgumentedItemQuantityInputDialogPane.cpp` | Quantity-entry dialog that validates `1..100` and calls `SendArgumentedItemQuantityPacket`. |
| `ArgumentedItemConfirmInputDialogPane` | `0x005200d0-0x00520538` | `class_ArgumentedItemConfirmInputDialogPane.cpp` | Price-confirm dialog; checks typed price, alerts on mismatch, sends quantity `1`, or opens quantity dialog. |

## IDA MCP Evidence

Targeted checks on 2026-05-23 and 2026-05-24 confirmed:

- `0x0051f450-0x0051f4fe` creates the confirm dialog with selected row fields. IDA reports no direct xrefs in the current IDB, but the body is argumented item purchase flow, not chat-color behavior.
- `0x0051f510-0x0051f5a5`, a real IDA function that Wave3 currently does not expose as a method, dispatches to `SendArgumentedItemQuantityPacket` or `ArgumentedItemQuantityInputDialogPane`. IDA also reports no direct xrefs in the current IDB, so treat it as a retained or indirectly reached helper until caller provenance is resolved.
- `0x0051f640-0x0051f706`, `SendArgumentedItemQuantityPacket`, is called by `0x0051f504`, `0x0051f58d`, `0x0052008e`, and `0x00520501`.
- `0x0051fc90-0x0051ff6c`, `0x0051ff70-0x005200c4`, `0x005200d0-0x005203be`, and `0x005203c0-0x00520539` are the quantity and confirm dialog methods.
- IDA reports `0x00520046` as being inside `0x0051ff70-0x005200c4`, not a function start.

## Ownership Notes

- These panes should stay adjacent to [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), specifically the argumented menu subset, because `ArgumentedMenuMenuDialog::HandleMenuCommand` and `ShowBuyConfirmDialog` create the confirm pane.
- `SendArgumentedItemQuantityPacket` consumes the `ArgumentedMenuMenuItemList` context layout: command type at `+0x14c`, owner id at `+0x150`, list parameter at `+0x154`, and owner dialog pointer at `+0x158`.
- `ShowBuyConfirmDialog` is currently attached to `ChattingColorListPane`, but its behavior is argumented item purchase flow. Treat it as an argumented input/menu helper before migration.
- The unowned `0x0051f510` helper should be imported or assigned before running file migration.

## Migration Notes

Proposed dry-run sequence after helper ownership is cleaned:

```powershell
python source-3\wave3.py rename file class_ArgumentedItemConfirmInputDialogPane.cpp ArgumentedItemInputDialogs.cpp --dry-run
python source-3\wave3.py set file-simpath ArgumentedItemInputDialogs.cpp ui/dialogs/ArgumentedItemInputDialogs.cpp --dry-run
python source-3\wave3.py attach class ArgumentedItemQuantityInputDialogPane --file ArgumentedItemInputDialogs.cpp --dry-run
python source-3\wave3.py attach global SendArgumentedItemQuantityPacket --file ArgumentedItemInputDialogs.cpp --dry-run
```

Do not run these migrations until the `0x0051f510` helper and `0x0051f450` owner-review issue are resolved.

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

- What existed before: the page documented confirm/quantity dialog ownership and helper caveats but had unevaluated scores.
- What it was changed to: scores were set to `72/82`.
- Summary and evidence: dialog boundaries, packet helper calls, and adjacent class pages support strong behavior confidence; the original split from `ArgumentedMenuDialogs.cpp` and unowned helper cleanup keep the score moderate.
