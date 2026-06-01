*** UID:00018Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x004effa0-0x004effbd Apply Fast Keyboard Repeat Settings

## Status

- Confidence: strong for boundary and behavior.
- Entity kind: file-local/global helper.
- Likely source file: [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- Current generated status: not attached to active `class_KeySpeedMgr.cpp`.
- Disposition: reconstructable project input/platform support helper.

## Function

| Range | Function | Notes |
| --- | --- | --- |
| `0x004effa0-0x004effbd` | `ApplyFastKeyboardRepeatSettings` / `SetFastKeyboardRepeat` | Sets keyboard delay to `0` with `SPI_SETKEYBOARDDELAY` (`0x17`), then sets keyboard speed to `31` with `SPI_SETKEYBOARDSPEED` (`0x0b`), both with `SPIF_UPDATEINIFILE`. |

## Evidence Notes

- IDA MCP lookup on 2026-05-26 reports size `0x1d`.
- IDA callers are startup/deactivation paths at `0x00463ab5` and `0x00466a24`.
- IDA decompilation shows no `this` access; this should be modeled as a file-local helper near [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md), not as a method that uses object state.
- The helper pairs with [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md), which restores the user's saved settings.

## Cross-References

- [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md)
- [UID:0002IS][0x004eff60-0x004eff85.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff85.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md)
- [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md)
- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md)
- [UID:0001QD][client_input_and_text_entry](by-meta/client_input_and_text_entry.md)
