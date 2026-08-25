*** UID:00018Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void ApplyFastKeyboardRepeatSettings()
{
    ::SystemParametersInfoW(SPI_SETKEYBOARDDELAY, 0, 0, SPIF_UPDATEINIFILE);
    ::SystemParametersInfoW(SPI_SETKEYBOARDSPEED, 31, 0, SPIF_UPDATEINIFILE);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Fast keyboard-repeat helper; live IDA confirms exact modeled range, complete 29-byte body, fixed SystemParametersInfoW calls for delay 0 and speed 31, callers 0x00463ab5/0x00466a24, no data refs to the helper start, and 0xcc padding on both sides. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# 0x004effa0-0x004effbd Apply Fast Keyboard Repeat Settings

## Status

- Confidence: strong for boundary and behavior.
- Entity kind: file-local helper.
- Likely source file: [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- Current generated status: should emit through [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md).
- Disposition: reconstructable project input/platform support helper.
- Parent handling: attached to [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md). B010 reanalysis treats the B006 caller-window `ecx` observation as lifecycle context only; the helper has no field, singleton, or vtable access, so file-local source placement is stronger.

## Function

| Range | Function | Notes |
| --- | --- | --- |
| `0x004effa0-0x004effbd` | `ApplyFastKeyboardRepeatSettings` / `SetFastKeyboardRepeat` | Sets keyboard delay to `0` with `SPI_SETKEYBOARDDELAY` (`0x17`), then sets keyboard speed to `31` with `SPI_SETKEYBOARDSPEED` (`0x0b`), both with `SPIF_UPDATEINIFILE`. |

## Evidence Notes

- IDA MCP lookup on 2026-05-26 reports size `0x1d`.
- IDA callers are startup/deactivation paths at `0x00463ab5` and `0x00466a24`.
- IDA decompilation shows no field access. B006 caller-window evidence showed `Application::Initialize` calling after `mov ecx, esi` and `BaramAppOnActivate` calling after loading/testing `g_pKeySpeedMgr`; B010 keeps those facts as caller/lifecycle context but does not treat unused `ecx` setup as enough proof for member-method ownership.
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

- Completion is `88` because the page now records the exact raw bytes, neighboring padding, modeled IDA boundary, live caller list, import dependency, fixed Win32 action values, file-local source route, and first-draft static helper C++.
- Confidence is `92` because IDA models the function cleanly, decompilation and disassembly agree, both callers are live application lifecycle paths, and B010 resolves the old file-local/member ambiguity with body evidence. It remains below final-audit confidence because the exact original helper spelling is still inferred from behavior rather than recovered from source symbols.

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

### 2026-06-20 B006 Rule 26 source-quality incorporation

- Changed scores from `86/91` to `88/92`, owner/emitter from [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) to [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md), and added first-draft `KeySpeedMgr::ApplyFastKeyboardRepeatSettings()` C++.
- Evidence: B006 direct call-site recheck shows `Application::Initialize` sets `ecx` to the constructed `KeySpeedMgr` before caller `0x00463ab5`, and `BaramAppOnActivate` loads/tests `g_pKeySpeedMgr` before caller `0x00466a24`. Therefore this is a `KeySpeedMgr` member method despite not reading fields.

### 2026-06-21 B010 source-quality sync

- Kept score `88/92`, changed owner/emitter back to [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md), and changed formal C++ to `static void ApplyFastKeyboardRepeatSettings()`.
- Rejected the B006 member-method conclusion as a historical assumption. The caller windows remain valid lifecycle evidence, but the helper body has no `this`, singleton, field, or vtable access and is best emitted as a file-local helper beside the raw two-argument setter.
- Source-facing return type is `void`; the binary leaves the second `SystemParametersInfoW` return in `EAX`, but both live callers ignore it and the helper is side-effect oriented.
