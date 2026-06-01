*** UID:0000S0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pPowerDialog / dword_69BA34

## Status

- Confidence: strong for address and owner; medium for final source-level name.
- Address: `0x0069ba34`
- IDA name: `dword_69BA34`
- Generated aliases observed: `g_pPowerDialog`, `g_activePowerListPane`
- Primary memory doc: [UID:0001PZ][0x0069ba34-0x0069ba38.g_pPowerDialog](by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md)
- Likely owner: [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)

## Purpose

This four-byte global stores the active `PowerDialogPane` singleton. Use `g_pPowerDialog` as the documentation alias unless later source evidence gives a better original name.

Do not treat generated `g_activePowerListPane` as a separate list-control singleton. That alias is attached to the same storage address, but the observed consumers use it as the owner dialog pointer so embedded `PowerListPane` instances can reach sibling list controls through the dialog's control collection.

## Evidence Notes

- IDA xrefs to `0x0069ba34` are confined to the power-dialog/list block: `0x0054a44c`, `0x0054a49a`, `0x0054a4b0`, `0x0054b010`, and `0x0054b540`.
- The constructor/packet initializer at `0x00549c20` stores `this` into `dword_69BA34` at `0x0054a44c` after installing `PowerDialogPane` vtables and attaching the dialog.
- The clear helper at `0x0054a480` and the scalar deleting destructor at `0x0054b520` both reinstall `PowerDialogPane` vtables and clear `dword_69BA34`.
- The tiny helper at `0x0054a4b0` returns `dword_69BA34`.
- `PowerListPane::OnMouseEvent` at `0x0054b000` reads `dword_69BA34` at `0x0054b010`, then dereferences the dialog control collection at `+0x1fc` to clear sibling list selections for controls `7-10`.
- Exact constructor and singleton-helper coverage now lives in [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md) and [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md).

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069ba34` is `dword_69BA34`, size `4`, in `.data`, with 5 data xrefs.
- Live IDA xrefs confirm constructor write at `0x0054a44c` in `sub_549C20`, singleton clear helper at `0x0054a49a` in `sub_54A480`, tiny accessor at `0x0054a4b0` in `sub_54A4B0`, `PowerListPane` use at `0x0054b010` in `sub_54B000`, and scalar deleting destructor clear at `0x0054b540` in `sub_54B520`.
- The xref set is confined to the power-dialog/list block, supporting the owner decision and the rejection of a separate list-control singleton interpretation.
- Completion remains below full because final source-level global spelling is still medium confidence.

## Config And Style Caveats

- The generated `g_powerThresholdConfig` name in `class_PowerListPane.cpp` is not a distinct power-owned global. IDA decompilation of the constructor shows a read of `dword_67A7C8` / `g_pConfig` at `0x00549cb0`, then uses config shorts at offsets `0x28de94`, `0x28de96`, `0x28de98`, and `0x28de9a`.
- The `g_defaultPaneStyle` generated name in the same constructor corresponds to broad UI style/global storage at `dword_69B36C`; it is not owned by the power dialog.

## Cross-References

- [UID:0001PZ][0x0069ba34-0x0069ba38.g_pPowerDialog](by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md)
- [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md)
- [UID:0000AQ][PowerListPane](by-class/PowerListPane.md)
- [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md)
- [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md)
- [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- [UID:0000IE][Config](by-file/Config.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `88`.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, and all 5 xrefs inside the power-dialog/list block; existing memory docs cover constructor, singleton helper, and list-control consumer behavior. Completion remains below full because final source-level global spelling is not proven.
