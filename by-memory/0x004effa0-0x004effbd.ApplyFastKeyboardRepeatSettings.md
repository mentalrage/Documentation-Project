*** UID:00018Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Parent handling: attached to [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) as a file-local helper because live IDA shows no `this` access.

## Function

| Range | Function | Notes |
| --- | --- | --- |
| `0x004effa0-0x004effbd` | `ApplyFastKeyboardRepeatSettings` / `SetFastKeyboardRepeat` | Sets keyboard delay to `0` with `SPI_SETKEYBOARDDELAY` (`0x17`), then sets keyboard speed to `31` with `SPI_SETKEYBOARDSPEED` (`0x0b`), both with `SPIF_UPDATEINIFILE`. |

## Evidence Notes

- IDA MCP lookup on 2026-05-26 reports size `0x1d`.
- IDA callers are startup/deactivation paths at `0x00463ab5` and `0x00466a24`.
- IDA decompilation shows no `this` access; this should be modeled as a file-local helper near [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md), not as a method that uses object state.
- The helper pairs with [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md), which restores the user's saved settings.

## Raw Byte Evidence

2026-06-06 live IDA byte audit:

| Range | Bytes | Interpretation |
| --- | --- | --- |
| `0x004eff91-0x004effa0` | `cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc` | Alignment after the raw two-argument keyboard-repeat setter. |
| `0x004effa0-0x004effbd` | `6a 01 6a 00 6a 00 6a 17 ff 15 f8 d3 60 00 6a 01 6a 00 6a 1f 6a 0b ff 15 f8 d3 60 00 c3` | Complete fast-repeat helper: fixed delay call, fixed speed call, plain `ret`. |
| `0x004effbd-0x004effc0` | `cc cc cc` | Alignment before the scalar deleting destructor. |

## 2026-06-06 Live IDA Refresh

- `lookup_funcs 0x004effa0` reports `sub_4EFFA0` size `0x1d`, giving half-open range `0x004effa0-0x004effbd`; `lookup_funcs 0x004effbd` is not a function.
- `callers` and live code-reference scan both report the two live refs at `0x00463ab5` in `sub_4639D0` and `0x00466a24` in `sub_4669C0`; live data-reference scan reports no data references to the helper start.
- `callees 0x004effa0` reports only external `SystemParametersInfoW`, imported through `0x0060d3f8`.
- `decompile 0x004effa0` confirms the helper has no parameters and no `this` access: it first calls `SystemParametersInfoW(0x17, 0, 0, 1)` to set keyboard delay to zero, then returns `SystemParametersInfoW(0x0b, 0x1f, 0, 1)` to set keyboard speed to `31`.
- `disasm 0x004effa0` confirms the two fixed `SystemParametersInfoW` calls and a plain `retn` at `0x004effbc`. Disassembly at `0x004effbd` shows alignment before the scalar deleting destructor at `0x004effc0`, so this page should not extend into [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md).

## Score Rationale

- Completion is `86` because the page now records the exact raw bytes, neighboring padding, modeled IDA boundary, live caller list, import dependency, fixed Win32 action values, and no-`this` file-local helper shape. It remains below high completion because the final original-source helper name and final C++ reconstruction are still not audited at the 95/95 gate.
- Confidence is `91` because IDA models the function cleanly, decompilation and disassembly agree, and both callers are live application lifecycle paths. It remains below final-audit confidence because the source-level name is still inferred from behavior rather than recovered from source symbols.

## Cross-References

- [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md)
- [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md)
- [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md)
- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md)
- [UID:0001QD][client_input_and_text_entry](by-meta/client_input_and_text_entry.md)

## Changes

- 2026-06-06 A007: Added live raw byte evidence for the complete `0x004effa0-0x004effbd` body and neighboring `0xcc` padding, reconfirmed callers `0x00463ab5`/`0x00466a24`, import target `SystemParametersInfoW` at `0x0060d3f8`, and absence of data references to the helper start. Raised the page from `84/90` to `86/91`; final C++ remains blank below the 95/95 code gate.
- 2026-06-06: Raised completion/confidence from `70/85` to `84/90` and attached the helper to [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) after live IDA reconfirmed the exact function size, startup/deactivation callers, no-`this` helper shape, fixed fast-repeat `SystemParametersInfoW` calls, and alignment before the scalar deleting destructor. Final C++ remains blank because this is below the 95/95 reconstruction-code gate.
