*** UID:0000MO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PowerDialogPane

## Status

- Confidence: strong for grouping `PowerDialogPane` and `PowerListPane`; medium for exact path.
- Proposed source path: `ui/dialogs/PowerDialogPane.cpp`
- Proposed header path: `ui/dialogs/PowerDialogPane.h`
- Main address range: [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- Current generated files: `source-3/simroot_v2/class_PowerDialogPane.cpp` and `source-3/simroot_v2/class_PowerListPane.cpp`

## File Role

This module should own the power or ability configuration dialog opened by a server packet. It is a feature dialog module: it constructs a `DialogPane`-based window, parses the incoming packet into four list models and a 5x5 totals grid, draws the `POWER.EPF` UI, and sends opcode `0x4c` updates when the player applies threshold values or applies a selected power slot.

The original source likely grouped the dialog and its private embedded list control in one file. `PowerListPane` is not reused broadly like [UID:0000KT][ListPane](by-file/ListPane.md); it exists to render the packet row format used by this dialog and to coordinate four sibling lists.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `PowerDialogPane` | [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md), `0x0054a4c0-0x0054a953`, `0x0054b520-0x0054b57f` | Dialog construction, action handling, `POWER.EPF` painting, packet submission, singleton cleanup. |
| Singleton helpers | [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md) | Retained cleanup/getter helpers for [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md); current IDA has no direct callers/xrefs, but byte/vtable/global evidence is exact. |
| `PowerListPane` | `0x0054b000-0x0054b5d5` | Feature-private list control for power entries, color swatches, and selection/drag behavior. |
| Destructor adjustor thunks | [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md) | Compiler-generated secondary/tertiary vtable thunks for the dialog and list destructors; not handwritten source. |
| `PowerEntryRecord` | local/packet row | File-local row payload used by constructor parsing and list drawing. |
| Power singleton/global pointer | [UID:0001PZ][0x0069ba34-0x0069ba38.g_pPowerDialog](by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md) | Canonical docs alias is [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md); generated `g_activePowerListPane` is the same storage misnamed from the constructor's bad owner. |

## Current Generated Split

| Current emitted owner | Address | Corrected source-layout decision |
| --- | --- | --- |
| `class_PowerListPane.cpp` | `0x00549c20` | Move to `PowerDialogPane` as the dialog constructor/packet initializer. |
| `class_PowerDialogPane.cpp` | `0x0054a4c0`, `0x0054a6f0`, `0x0054a7f0`, `0x0054b520` | Keep in `PowerDialogPane.cpp`. |
| `class_PowerListPane.cpp` | `0x0054b000`, `0x0054b220`, `0x0054b350`, `0x0054b580` | Keep in the same module as feature-private `PowerListPane` methods. |
| Disabled generated files | `0x0054aec0`, `0x0054b4f0`, `0x0054b4fb`, `0x0054b506`, `0x0054b511` | Drop `0x0054aec0`; preserve the four `0xb` thunk starts as compiler thunks. |

## Evidence Notes

- `MapPane::HandlePacket` packet case `0x46` allocates `740` bytes and calls `0x00549c20` with the packet payload.
- IDA MCP confirms `0x00549c20` is a single real function of size `0x852`, called from `MapPane` at `0x0050876a`.
- 2026-05-26 IDA MCP recheck reports a second caller at `0x00513b93` under a stale/misleading `___std_parallel_algorithms_hw_threads@0_2` label; it remains a caller-review note and does not change `PowerDialogPane` ownership.
- IDA MCP callees for `0x00549c20` include `DialogPane` construction, [UID:00007A][ListPane](by-class/ListPane.md) construction, list append/sort helpers, static/image control creation helpers, and `MultiByteToWideChar`.
- The generated constructor body writes `PowerDialogPane` vtables and builds controls with ids `6-14`, which fits the dialog class and not the embedded list class.
- IDA MCP xrefs to `0x0069ba34` show the constructor stores the dialog pointer, the dialog cleanup/destructor clears it, and `PowerListPane::OnMouseEvent` only reads it to reach sibling controls through the owner dialog. This resolves the `g_pPowerDialog` / `g_activePowerListPane` conflict in favor of `g_pPowerDialog`.
- IDA MCP 2026-06-01 recheck of [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md) confirms exact helper bounds, `PowerDialogPane` vtable writes, the `g_pPowerDialog` clear/getter, and `0xcc` alignment before/between/after the helpers.
- The generated `g_powerThresholdConfig` label in `class_PowerListPane.cpp` resolves to broad config storage: IDA decompilation reads `dword_67A7C8` / `g_pConfig` and then config shorts at offsets `0x28de94`, `0x28de96`, `0x28de98`, and `0x28de9a`.
- IDA MCP confirms `0x0054aec0` is not a function, while `0x0054b4f0`, `0x0054b4fb`, `0x0054b506`, and `0x0054b511` are real `0xb` thunk functions.
- The four thunk functions are now documented exactly and entered in [UID:0000VN][-ignored](by-memory/-ignored.md) as compiler-generated adjustor thunks.
- The neighboring [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) block begins at `0x0054b5e0`, so the power dialog/list block should end at `0x0054b5d5`.

## Migration Notes

- Proposed Wave3 source migration after review: set both generated class containers to `ui/dialogs/PowerDialogPane.cpp`, or attach `PowerListPane` as a private class in that module.
- Move method `0x00549c20` from `PowerListPane` ownership to `PowerDialogPane` ownership or rename it as a file-level `PowerDialogPane` packet constructor helper if the tool cannot move constructor ownership directly.
- Preserve `PowerListPane` as a `ListPane`-derived class; do not move its shared inherited list operations into this file.
- Normalize the singleton global at `0x0069ba34` to `g_pPowerDialog`; do not create a separate `g_activePowerListPane` storage symbol.
- Normalize generated `g_powerThresholdConfig` uses in this dialog to `g_pConfig` field offsets until config-field names are recovered.
- Treat helper labels such as `RankingDialog::SlideClose`, `ChattingColorPane::CloseDialog`, and `ClientItemMenuItemList::~ClientItemMenuItemList` inside generated code as provisional base/helper labels until those owners are reviewed.

## Cross-References

- [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md)
- [UID:0000AQ][PowerListPane](by-class/PowerListPane.md)
- [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md)
- [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md)
- [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md)
- [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `80`.
- Summary/evidence: the page documents dialog/list grouping, proposed contents, generated split correction, IDA evidence, migration notes, singleton/config naming caveats, and cross-references; confidence remains capped by exact path and unresolved caller-review note.

- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank despite the page proposing `ui/dialogs/PowerDialogPane.cpp`.
- Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
- Summary/evidence: this aligns the validator-generated reconstruction root with the page's stated proposed source path and allows attached reconstructable child pages to stage under the intended dialog module.
