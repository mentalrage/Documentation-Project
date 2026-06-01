*** UID:0000KJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/input/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# KeySpeedMgr

## Status

- Confidence: strong for behavior and file placement.
- Proposed module: `input/KeySpeedMgr.cpp`
- Current recovered source: `source-3/simroot_v2/class_KeySpeedMgr.cpp`
- Main address range: [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- Type anchors: [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md), [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)

## File Role

`KeySpeedMgr` preserves the user's Windows keyboard repeat settings and lets the client temporarily set a fast repeat profile. Startup constructs the singleton, reads `SPI_GETKEYBOARDDELAY` and `SPI_GETKEYBOARDSPEED`, then a nearby helper sets keyboard delay to `0` and speed to `31`. Shutdown/deactivation/error paths call `RestoreSystemKeyboardSettings` to restore the original values.

This belongs near input/platform startup support rather than inside [UID:0000K6][InputMan](by-file/InputMan.md): `InputMan` handles Win32 input messages and IME state, while `KeySpeedMgr` only manages system keyboard repeat settings.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md) | `0x004efea0-0x004f0008` | Singleton lifecycle, load/restore keyboard repeat settings, deleting destructor. |
| [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) | `0x004eff30-0x004eff5d` | Restores saved keyboard delay and speed on cleanup/deactivation/error/exit paths. |
| [UID:0002IS][0x004eff60-0x004eff85.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff85.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md) | `0x004eff60-0x004eff85` | Raw unreferenced helper that applies caller-supplied keyboard delay/speed values with the same range limits. |
| [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md) | `0x004effa0-0x004effbd` | Sets keyboard delay to `0` and keyboard speed to `31`. |
| [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md) | [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md) | Singleton pointer set by constructor and cleared by destructors. |

## Evidence Notes

- IDA MCP confirms all relevant starts from `0x004efea0` through `0x004f0008`.
- IDA MCP confirms `Application::Initialize` allocates `0x0c` bytes for the singleton, then calls the constructor, load method, and fast-repeat helper.
- IDA MCP xrefs show constructor and load calls from `Application::Initialize`.
- IDA MCP xrefs show `RestoreSystemKeyboardSettings` is called from cleanup/deactivation/error paths, including `Application::CleanupResources`, `BaramApp::OnDeactivate`, `TopLevelExceptionFilter`, and `_WinMain@16`.
- 2026-05-24 IDA recheck confirms `RestoreSystemKeyboardSettings` callers at `0x00464aff`, `0x00466adb`, `0x004ab844`, and `0x004f5ee6`; the fast-repeat helper is called from `0x00463ab5` and `0x00466a24`.
- 2026-05-26 IDA vtable recheck confirms the RTTI-backed `KeySpeedMgr` vtable at `0x0061c9c8`, with stores in the constructor, non-deleting destructor, and scalar deleting destructor. Current Wave3 metadata reports `vtable_count: 0`.
- Current active generated output still disables `RestoreSystemKeyboardSettings`, omits the non-deleting destructor at `0x004efee0`, does not model the raw two-argument helper at `0x004eff60`, and does not attach the fast-repeat helper at `0x004effa0`.
- 2026-05-26 recheck using `simroot_v2` and IDA MCP only: active `class_KeySpeedMgr.cpp` still omits the restore and fast-repeat pages linked above, while the disabled restore body and live cleanup callers remain confirmed.

## Migration Notes

- Candidate simpath: `input/KeySpeedMgr.cpp`; `platform/KeySpeedMgr.cpp` is also plausible if the final tree groups all `SystemParametersInfoW` state in platform code.
- Keep `0x004eff60` and `0x004effa0` with this module as file-local keyboard-repeat setter helpers unless future IDA/source evidence proves the raw two-argument helper belongs elsewhere.
- Re-enable or attach `0x004eff30` before using active generated output as complete source.

## Cross-References

- [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md)
- [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md)
- [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)
- [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md)
- [UID:0002IS][0x004eff60-0x004eff85.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff85.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md)
- [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md)
- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md)
- [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md)
- [UID:0000K6][InputMan](by-file/InputMan.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0001QD][client_input_and_text_entry](by-meta/client_input_and_text_entry.md)

## Changes

### 2026-05-28 - Corrected KeySpeedMgr terminal byte

- What existed before: `KeySpeedMgr` file-level contents listed the aggregate range as `0x004efea0-0x004f0007`.
- What changed: the aggregate range now ends at `0x004f0008`.
- Evidence: IDA MCP shows `sub_4EFFC0` ending at `0x004f0008`; `0x004f0007` is the final byte of the scalar deleting destructor's `retn 4`, while `0x004f0008-0x004f0010` is alignment before `LanguageManLocalization`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:90` and `CONFIDENCE:88`.
  - Summary/evidence: keyboard repeat preservation, singleton lifecycle, exact method/helper ranges, global/type/vtable anchors, caller evidence, omitted generated bodies, migration notes, and terminal-byte correction are well documented; confidence is capped slightly by generated metadata omissions.

### 2026-05-31 - Assigned projected path and recorded raw setter

- What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the file page did not list the raw `0x004eff60-0x004eff85` helper.
- What changed: the projected reconstruction path is now `NexusTK/input/`, matching `by-project-structure/proposed-source-tree.md`, and the raw two-argument keyboard repeat setter is listed as a file-local helper candidate.
- Summary/evidence: IDA MCP byte review shows executable helper bytes at `0x004eff60-0x004eff85` with no current IDA function object or xrefs; proposed-source-tree already places `KeySpeedMgr.cpp` under `input/`.
