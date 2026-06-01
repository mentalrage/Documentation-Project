*** UID:0000AP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PowerDialogPane

## Status

- Confidence: strong for dialog ownership, medium for exact original filename.
- Likely source file: [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- Address range: [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- Current recovered sources: `source-3/simroot_v2/class_PowerDialogPane.cpp` and the constructor currently mis-emitted in `source-3/simroot_v2/class_PowerListPane.cpp`.

## Class Purpose

`PowerDialogPane` is the packet-opened power or ability configuration dialog. It constructs the `Power` dialog, owns the `POWER.EPF` background render path, displays a 5x5 power value grid, edits four configured threshold values, and sends opcode `0x4c` responses for apply-all and selected-slot actions.

The dialog contains four embedded [UID:0000AQ][PowerListPane](by-class/PowerListPane.md) controls. Those list controls render and select the power entries, but the large setup routine at `0x00549c20` is the dialog constructor/initializer rather than a list-pane method: it calls the [UID:00003T][DialogPane](by-class/DialogPane.md) constructor, installs `PowerDialogPane` vtables, creates header buttons and list controls, populates row totals from packet data, attaches the dialog to the root pane, and stores the singleton pointer.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md) | `0x00549c20-0x0054a472` | Currently named `PowerListPane::InitializeFromData`, but builds the full dialog from server packet case `0x46` and writes `PowerDialogPane` vtables. |
| [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md) | `0x0054a480-0x0054a4b6` | Retained cleanup/getter helpers over [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md); current IDA has no direct callers/xrefs. |
| `OnDialogAction` | `0x0054a4c0-0x0054a69d` | Action `0` reads controls `11-14`, stores four config shorts, and sends opcode `0x4c`, subcommand `1`; actions `1-5` delegate to `ApplyPowerSlot`; action `6` closes the dialog. |
| `OnPaint` | `0x0054a6f0-0x0054a7e9` | Draws `POWER.EPF`, sets text rendering state, and paints the 5x5 power total grid. |
| `ApplyPowerSlot` | `0x0054a7f0-0x0054a954` | Finds the selected embedded list, applies one encoded threshold value, and sends opcode `0x4c`, subcommand `2` with the selected entry id. |
| Dialog destructor and thunks | `0x0054b4f0-0x0054b57f` | Two compiler [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md) plus scalar deleting destructor; clears the power-dialog singleton before chaining to `DialogPane` cleanup. |

## Layout Notes

- Imported Wave2 notes identify a 644-byte dialog struct.
- `m_encodedPowerValues[4]` starts at `+0x26c`; values use the encoding `value * 8 + 52`.
- `m_powerGrid[25]` starts at `+0x280` and is drawn as a 5x5 value table in `OnPaint`.
- The singleton storage is [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md) at `0x0069ba34`. The generated `g_activePowerListPane` name in the constructor body is the same storage misnamed because `0x00549c20` is currently emitted under `PowerListPane`.
- Threshold defaults come from `g_pConfig` / `dword_67A7C8` shorts at offsets `0x28de94`, `0x28de96`, `0x28de98`, and `0x28de9a`; generated `g_powerThresholdConfig` is not a separate power-owned global.

## Evidence Notes

- IDA MCP confirms `0x00549c20` is a real `0x852`-byte function and is called from `MapPane::HandlePacket` at `0x0050876a`, where packet case `0x46` allocates `740` bytes and calls this initializer with the packet payload.
- 2026-05-26 IDA MCP recheck also reports a second caller at `0x00513b93` currently mislabeled `___std_parallel_algorithms_hw_threads@0_2`; keep that caller under review, but it does not change the constructor ownership.
- IDA MCP callees for `0x00549c20` include the `DialogPane` constructor, `ListPane` constructor at `0x004f3a50`, list append helper at `0x004f3c50`, list sort helper at `0x004f3540`, and `MultiByteToWideChar`.
- `source-3/simroot_v2/class_PowerListPane.cpp` explicitly shows the function calling `DialogPane::DialogPane(L"Power", -1, 1)` and writing three `PowerDialogPane` vtables before creating controls.
- IDA MCP xrefs to `0x0069ba34` show the constructor writes the dialog pointer at `0x0054a44c`, the cleanup/destructor clears it at `0x0054a49a` and `0x0054b540`, and `PowerListPane::OnMouseEvent` reads it at `0x0054b010` only to coordinate sibling list controls.
- IDA MCP confirms `0x0054a480` and `0x0054a4b0` as real singleton cleanup/getter helpers, but direct `callers` and `xrefs_to` are empty in the current IDB.
- IDA MCP confirms `0x0054b4f0`, `0x0054b4fb`, `0x0054b506`, and `0x0054b511` as four `0xb` adjustor thunks. These are now recorded in [UID:0000VN][-ignored](by-memory/-ignored.md).
- `OnDialogAction` and `ApplyPowerSlot` both send opcode `0x4c` through the packet writer/send helpers at `0x00575380` and `0x00574bb0`.
- IDA MCP reports `0x0054aec0` is not a function, so the disabled generated method there should not be used as class evidence.

## Source Layout Decision

Move the full dialog constructor at `0x00549c20` into `PowerDialogPane`. Keep the embedded list class in the same likely original source module as a private/helper UI class. This matches the late-1999 through mid-2000s pattern already seen in other feature dialogs: a `DialogPane` subclass and its private row/list control class usually live in one `.cpp`/`.h` pair unless the control has broad reuse.

## Cross-References

- [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- [UID:0000AQ][PowerListPane](by-class/PowerListPane.md)
- [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md)
- [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md)
- [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md)
- [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md)
- [UID:00003T][DialogPane](by-class/DialogPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite detailed dialog purpose, constructor re-ownership, method map, layout notes, singleton evidence, packet behavior, and source-layout decision.
- Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
- Evidence: IDA-backed constructor range, `OnDialogAction`, `OnPaint`, `ApplyPowerSlot`, singleton helpers, destructor/thunks, layout offsets, packet opcode `0x4c`, vtable/source-placement decisions, and Wave3 data caveats are documented; confidence stays medium-high because exact original filename and generated ownership pollution remain unresolved.
