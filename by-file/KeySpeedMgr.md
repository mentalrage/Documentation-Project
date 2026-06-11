*** UID:0000KJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/input/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# KeySpeedMgr

## Status

- Confidence: strong for behavior and file placement.
- Proposed module: `input/KeySpeedMgr.cpp`
- Main address range: [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- Type anchors: [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md), [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)

## File Role

`KeySpeedMgr` preserves the user's Windows keyboard repeat settings and lets the client temporarily set a fast repeat profile. Startup constructs the singleton, reads `SPI_GETKEYBOARDDELAY` and `SPI_GETKEYBOARDSPEED`, then a nearby helper sets keyboard delay to `0` and speed to `31`. Shutdown/deactivation/error paths call `RestoreSystemKeyboardSettings` to restore the original values.

This belongs near input/platform startup support rather than inside [UID:0000K6][InputMan](by-file/InputMan.md): `InputMan` handles Win32 input messages and IME state, while `KeySpeedMgr` only manages system keyboard repeat settings.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md) | `0x004efea0-0x004f0008` | Singleton lifecycle, load/restore keyboard repeat settings, deleting destructor. |
| [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) | `0x004efea0-0x004efedd` | Constructs the singleton object and installs the vtable. |
| [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) | `0x004efee0-0x004efef5` | Ordinary destructor body that clears the singleton slot and runs base cleanup. |
| [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md) | `0x004eff00-0x004eff25` | Saves current Windows keyboard delay and speed. |
| [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) | `0x004eff30-0x004eff5d` | Restores saved keyboard delay and speed on cleanup/deactivation/error/exit paths. |
| [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md) | `0x004eff60-0x004eff91` | Raw unreferenced helper that applies caller-supplied keyboard delay/speed values with the same range limits. |
| [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md) | `0x004effa0-0x004effbd` | Sets keyboard delay to `0` and keyboard speed to `31`. |
| [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) | `0x004effc0-0x004f0008` | Scalar deleting destructor wrapper referenced by the vtable. |
| [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md) | [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md) | Singleton pointer set by constructor and cleared by destructors. |
| related non-owned cleanup wrapper | [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) | `WinMain` early-exit cleanup helper that reads `g_pKeySpeedMgr` and deletes the singleton; source owner is [UID:0000PA][WinMain](by-file/WinMain.md), not this file. |

## Evidence Notes

- IDA MCP confirms all relevant starts from `0x004efea0` through `0x004f0008`.
- IDA MCP confirms `Application::Initialize` allocates `0x0c` bytes for the singleton, then calls the constructor, load method, and fast-repeat helper.
- IDA MCP xrefs show constructor and load calls from `Application::Initialize`.
- IDA MCP xrefs show `RestoreSystemKeyboardSettings` is called from cleanup/deactivation/error paths, including `Application::CleanupResources`, `BaramApp::OnDeactivate`, `TopLevelExceptionFilter`, and `_WinMain@16`.
- 2026-05-24 IDA recheck confirms `RestoreSystemKeyboardSettings` callers at `0x00464aff`, `0x00466adb`, `0x004ab844`, and `0x004f5ee6`; the fast-repeat helper is called from `0x00463ab5` and `0x00466a24`.
- 2026-05-26 IDA vtable recheck confirms the RTTI-backed `KeySpeedMgr` vtable at `0x0061c9c8`, with stores in the constructor, non-deleting destructor, and scalar deleting destructor.
- 2026-06-06 live IDA refresh reconfirms modeled functions at `0x004efea0-0x004efedd`, `0x004efee0-0x004efef5`, `0x004eff00-0x004eff25`, `0x004eff30-0x004eff5d`, `0x004effa0-0x004effbd`, and `0x004effc0-0x004f0008`.
- 2026-06-06 live IDA byte check keeps the raw helper as unmodeled code at `0x004eff60-0x004eff91`; every internal gap through `0x004f0010` is `0xcc` alignment.
- 2026-06-06 live IDA xrefs show ten refs to `g_pKeySpeedMgr` at `0x0067ab48`, including the B001-014-confirmed cleanup read at `0x004673c0`, and vtable refs to `0x0061c9c8` from `0x004efecb`, `0x004efee0`, and `0x004effc6`.
- 2026-06-10 B001-014 confirms [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) is not a KeySpeedMgr method: IDA MCP shows it reads `dword_67AB48`, null-checks it, dispatches the deleting destructor, and has only one direct caller found at [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md) `0x004f5eeb` after `KeySpeedMgrRestoreSystemKeyboardSettings`.

## Migration Notes

- Candidate source path: `input/KeySpeedMgr.cpp`; `platform/KeySpeedMgr.cpp` is also plausible if the final tree groups all `SystemParametersInfoW` state in platform code.
- Keep `0x004eff60` and `0x004effa0` with this module as file-local keyboard-repeat setter helpers unless future IDA/source evidence proves the raw two-argument helper belongs elsewhere.
- Keep the restore method, ordinary destructor, and scalar deleting destructor in the file inventory even if generated coverage is temporarily stale.
- Keep [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) outside `KeySpeedMgr.cpp`; it is entry-point cleanup policy that consumes the singleton pointer after restore, while this file owns the object, vtable, methods, and global storage.

## Cross-References

- [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md)
- [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md)
- [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md)
- [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md)
- [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md)
- [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)
- [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md)
- [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md)
- [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md)
- [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md)
- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md)
- [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md)
- [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md)
- [UID:0000K6][InputMan](by-file/InputMan.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0001QD][client_input_and_text_entry](by-meta/client_input_and_text_entry.md)

## Changes

### 2026-06-10 B001-014 WinMain cleanup boundary

- Score unchanged at `90/88`.
- Added [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) as a related non-owned cleanup wrapper.
- Evidence: IDA MCP confirms the wrapper reads `g_pKeySpeedMgr` and dispatches deletion, but its only direct caller found is `WinMain` at `0x004f5eeb`; therefore KeySpeedMgr remains the object/global owner, not the source owner of that entry-point cleanup wrapper.

### 2026-05-28 - Corrected KeySpeedMgr terminal byte

- What existed before: `KeySpeedMgr` file-level contents listed the aggregate range as `0x004efea0-0x004f0007`.
- What changed: the aggregate range now ends at `0x004f0008`.
- Evidence: IDA MCP shows `sub_4EFFC0` ending at `0x004f0008`; `0x004f0007` is the final byte of the scalar deleting destructor's `retn 4`, while `0x004f0008-0x004f0010` is alignment before `LanguageManLocalization`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:90` and `CONFIDENCE:88`.
  - Summary/evidence: keyboard repeat preservation, singleton lifecycle, exact method/helper ranges, global/type/vtable anchors, caller evidence, omitted generated bodies, migration notes, and terminal-byte correction are well documented; confidence is capped slightly by generated metadata omissions.

### 2026-05-31 - Assigned projected path and recorded raw setter

- What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the file page did not list the raw `0x004eff60-0x004eff91` helper.
- What changed: the projected reconstruction path is now `NexusTK/input/`, matching `by-project-structure/proposed-source-tree.md`, and the raw two-argument keyboard repeat setter is listed as a file-local helper candidate.
- Summary/evidence: IDA MCP byte review shows executable helper bytes at `0x004eff60-0x004eff91` with no current IDA function object or xrefs; proposed-source-tree already places `KeySpeedMgr.cpp` under `input/`.

### 2026-06-06 - Refreshed exact method inventory

- What existed before: the file page linked the class, restore helper, raw setter, fast-repeat helper, and global, but omitted the exact constructor/destructor/load/scalar-deleting child pages from its proposed contents and still referenced generated-source caveats.
- What changed: exact lifecycle child pages are now linked from the file inventory, generated-source provenance was removed from the status/evidence notes, and the evidence notes now cite the live IDA function, padding, singleton, and vtable checks.
- Summary/evidence: live IDA MCP confirms all modeled function ranges, the raw `0x004eff60-0x004eff91` helper, all `0xcc` internal padding, ten `g_pKeySpeedMgr` xrefs, and vtable stores at `0x004efecb`, `0x004efee0`, and `0x004effc6`.
