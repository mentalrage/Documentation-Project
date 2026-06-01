*** UID:0000AQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PowerListPane

## Status

- Confidence: strong for embedded list-control behavior, medium for exact original class name.
- Likely source file: [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- Address range: [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- Current recovered source: `source-3/simroot_v2/class_PowerListPane.cpp`

## Class Purpose

`PowerListPane` is the embedded [UID:00007A][ListPane](by-class/ListPane.md)-derived control used by [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md). It draws power entries with a color swatch and right-aligned label, manages drag/click/double-click selection, and clears selection from sibling power lists when a new list starts dragging.

The large generated `InitializeFromData` routine at `0x00549c20` should not remain here. It builds the containing `PowerDialogPane`, not a standalone list control. The real list-control methods are the `0x0054b000-0x0054b5d5` block.

The generated `g_activePowerListPane` name should also not remain list-owned. IDA shows the storage is [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md) at `0x0069ba34`; `OnMouseEvent` reads it only to access the containing dialog's sibling list controls.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| `OnMouseEvent` | `0x0054b000-0x0054b210` | Handles move/down/double-click/up events, hit-tests rows through `ListPane`, clears sibling list selections, starts and ends drag state through `g_pMetaMan`. |
| `DrawListItem` | `0x0054b220-0x0054b34b` | Draws selected row frame, fills a color swatch, then right-aligns the UTF-16 entry label. |
| `FillColorRect` | `0x0054b350-0x0054b4f0` | Clips and fills a 16-bit rectangle using a palette converter and current render mode. |
| Destructor and thunks | `0x0054b506-0x0054b5d5` | Compiler [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md) plus scalar deleting destructor that chains to the `ListPane` destructor core at `0x004f3b60`. |

## Entry Data

Generated code and drawing behavior point to an inline row record:

| Field | Type | Notes |
| --- | --- | --- |
| `entryId` | `int` | Sent back by `PowerDialogPane::ApplyPowerSlot`. |
| `listColumn` | `uint8_t` | Chooses one of the four embedded lists. |
| `amount` | `int` | Accumulated into the dialog row-total grid. |
| `label[256]` | `wchar_t[256]` | Converted from packet text with `MultiByteToWideChar`. |
| `displayColor` | `int` | Encoded as `52 + 8 * thresholdValue`; drawing splits it into palette/page and color index. |

## Evidence Notes

- IDA MCP confirms real functions at `0x0054b000`, `0x0054b220`, `0x0054b350`, `0x0054b506`, `0x0054b511`, and `0x0054b580`.
- IDA MCP callees for `0x0054b000` include `ListPane::HitTestItem` at `0x004f4480` and `ListPane::EnsureItemVisible` at `0x004f4920`.
- `0x0054b000` reads `dword_69BA34` at `0x0054b010`; the later dereference through `+0x1fc` is the owner dialog's control collection, so this read does not make the global a list-pane singleton.
- IDA MCP callees for `0x0054b220` include `ListPane::IsItemSelected` at `0x004f3f00` and the local fill helper at `0x0054b350`.
- IDA MCP reports `0x0054aec0` is not a function despite the disabled generated file listing missing code there.
- `0x0054b506` and `0x0054b511` are real `0xb` thunk starts, even though `0x0054b511` is currently emitted as missing code. They are compiler-generated adjustor thunks and are now tracked in [UID:0000VN][-ignored](by-memory/-ignored.md), not feature methods.

## Source Layout Decision

Keep `PowerListPane` adjacent to `PowerDialogPane` in `ui/dialogs/PowerDialogPane.cpp`. It is feature-private: current evidence only ties it to the power dialog, and it depends on the dialog's four-list selection model and packet row format. Generic list behavior should stay in [UID:00007A][ListPane](by-class/ListPane.md).

## Cross-References

- [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md)
- [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md)
- [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented embedded-list behavior, generated constructor pollution, method roles, entry data, vtable/thunk evidence, and source-layout decision.
- Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
- Evidence: `OnMouseEvent`, `DrawListItem`, `FillColorRect`, destructor/thunk behavior, row record fields, `g_pPowerDialog` ownership correction, and private `PowerDialogPane` placement are documented; confidence remains medium-high because final original class name and generated `0x00549c20` ownership pollution remain open.
