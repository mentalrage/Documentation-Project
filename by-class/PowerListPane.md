*** UID:0000AQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PowerListPane

## Status

- Confidence: strong for embedded list-control behavior, live method/vtable boundaries, `g_pPowerDialog` ownership, and private placement under `PowerDialogPane`; medium only for exact original private-class spelling.
- Reconstructability: reconstructable as a private list-control class in [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md), but final C++ is intentionally blank until the 95/95 bar is reached.
- Parent source file: [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- Address range: [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)

## Class Purpose

`PowerListPane` is the embedded [UID:00007A][ListPane](by-class/ListPane.md)-derived control used by [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md). It draws power entries with a color swatch and right-aligned label, manages drag/click/double-click selection, and clears selection from sibling power lists when a new list starts dragging.

The large routine at `0x00549c20` should not remain class-owned by the list control. It builds the containing `PowerDialogPane`, not a standalone list pane. The real list-control methods are the `0x0054b000-0x0054b5d5` block.

The temporary `g_activePowerListPane` label should also not remain list-owned. Live IDA xrefs show the storage is [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md) at `0x0069ba34`; `OnMouseEvent` reads it only to access the containing dialog's sibling list controls.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| `OnMouseEvent` | `0x0054b000-0x0054b210` | Handles move/down/double-click/up events, hit-tests rows through `ListPane`, clears sibling list selections, starts and ends drag state through `g_pMetaMan`. |
| `DrawListItem` | `0x0054b220-0x0054b34b` | Draws selected row frame, fills a color swatch, then right-aligns the UTF-16 entry label. |
| `FillColorRect` | `0x0054b350-0x0054b4f0` | Clips and fills a 16-bit rectangle using a palette converter and current render mode. |
| Destructor and thunks | `0x0054b506-0x0054b5d5` | Compiler [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md) plus scalar deleting destructor that chains to the `ListPane` destructor core at `0x004f3b60`. |

## Entry Data

Constructor and drawing behavior point to an inline row record:

| Field | Type | Notes |
| --- | --- | --- |
| `entryId` | `int` | Sent back by `PowerDialogPane::ApplyPowerSlot`. |
| `listColumn` | `uint8_t` | Chooses one of the four embedded lists. |
| `amount` | `int` | Accumulated into the dialog row-total grid. |
| `label[256]` | `wchar_t[256]` | Converted from packet text with `MultiByteToWideChar`. |
| `displayColor` | `int` | Encoded as `52 + 8 * thresholdValue`; drawing splits it into palette/page and color index. |

## Evidence Notes

- Live IDA MCP confirms function boundaries: `0x0054b000-0x0054b210`, `0x0054b220-0x0054b34b`, `0x0054b350-0x0054b4f0`, adjustor thunks at `0x0054b506-0x0054b511` and `0x0054b511-0x0054b51c`, scalar deleting destructor `0x0054b580-0x0054b5d5`, then `int3` padding through `0x0054b5df` before the next function at `0x0054b5e0`.
- Live vtable names bind the class: primary `??_7PowerListPane@@6B@` at `0x006221f4`, secondary `??_7PowerListPane@@6B@_0` at `0x0062227c`, and tertiary `??_7PowerListPane@@6B@_1` at `0x006222ac`. Constructor/setup writes occur at `0x00549f58`, `0x00549f5e`, `0x00549f68`, `0x0054af10`, `0x0054af16`, and `0x0054af20`; the destructor resets the same three vtables at `0x0054b586`, `0x0054b58c`, and `0x0054b596`.
- Primary vtable slots include scalar deleting destructor `0x006221f4 -> 0x0054b580`, mouse handler `0x00622254 -> 0x0054b000`, and draw handler `0x00622274 -> 0x0054b220`. Secondary/tertiary slots point to the `this`-adjusting destructor thunks at `0x0062227c -> 0x0054b506` and `0x006222ac -> 0x0054b511`.
- IDA decompilation of `0x0054b000` shows a mouse-event switch on the byte at event offset `+4`, coordinates from `+8/+12`, drag state at `this+329`, hit tests through `0x004f4480`, visibility updates through `0x004f4920`, and sibling-list selection clearing through the owner dialog's control lookup at `g_pPowerDialog + 0x1fc`.
- `g_pPowerDialog` storage at `0x0069ba34` has the expected live xrefs: constructor write `0x0054a44c`, dialog reset/destructor clears `0x0054a49a` and `0x0054b540`, accessor read `0x0054a4b0`, and this list's read `0x0054b010`.
- IDA decompilation of `0x0054b220` shows selected-row decoration via `0x004f3f00`, swatch fill through local helper `0x0054b350`, color value from row offset `+0x20c`, and UTF-16 label rendering from row offset `+0x0c`.
- IDA decompilation of `0x0054b350` confirms clipping against the pane rect, palette conversion through `0x00543e40` and `0x00542ac0`, and 16-bit fill loops using the current surface mode.
- IDA MCP reports `0x0054aec0` is not a defined function in the database; it is not counted as a handwritten list method.
- `0x0054b506` and `0x0054b511` are real `0xb` compiler adjustor thunk starts. They are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md), not as feature methods.

## Source Layout Decision

Keep `PowerListPane` adjacent to `PowerDialogPane` in `ui/dialogs/PowerDialogPane.cpp`. It is feature-private: current evidence only ties it to the power dialog, and it depends on the dialog's four-list selection model and packet row format. Generic list behavior should stay in [UID:00007A][ListPane](by-class/ListPane.md).

## Cross-References

- [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md)
- [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md)
- [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md)
- [UID:00007A][ListPane](by-class/ListPane.md)

## Score Rationale

- `COMPLETION:86`: live IDA evidence now covers the method island, vtable slots, constructor/setup writes, destructor reset, global ownership, row draw fields, and padding boundary. Remaining work is mostly exact private-class spelling and broader PowerDialogPane constructor cleanup.
- `CONFIDENCE:88`: confidence is raised because the class name is present in live vtable symbols and the behavior is independently supported by decompilation and xrefs. It stays below final-source confidence because the enclosing dialog constructor and private class declaration have not been fully reconstructed.
- `RECONSTRUCTABLE:TRUE`: the class can be reconstructed as a private implementation detail under [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md), while compiler thunks remain ignored and final C++ remains blank.

## Changes

- 2026-06-04: Raised completion/confidence from `82/76` to `86/88`, marked `RECONSTRUCTABLE:TRUE`, and attached the class to [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md). The increase is justified by fresh live IDA MCP research proving the exact function ranges, vtable slots at `0x006221f4`, `0x0062227c`, and `0x006222ac`, setup/destructor vtable writes, `g_pPowerDialog` xrefs, mouse-event switch behavior, drawing helper behavior, and the post-destructor padding boundary.
- Before: completion/confidence metadata were `0/0` even though the page already documented embedded-list behavior, constructor ownership pollution, method roles, entry data, vtable/thunk evidence, and source-layout decision.
- Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
- Evidence: `OnMouseEvent`, `DrawListItem`, `FillColorRect`, destructor/thunk behavior, row record fields, `g_pPowerDialog` ownership correction, and private `PowerDialogPane` placement are documented; confidence remained medium-high because final original class name and `0x00549c20` ownership cleanup were still open.
