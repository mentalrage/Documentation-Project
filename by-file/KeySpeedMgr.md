*** UID:0000KJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/input/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# KeySpeedMgr

## Status

- Confidence: strong for behavior and file placement.
- Proposed module: `input/KeySpeedMgr.cpp`
- Main address range: [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- Type anchors: [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md), [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)

## File Role

`KeySpeedMgr` preserves the user's Windows keyboard repeat settings and lets the client temporarily set a fast repeat profile. Startup constructs the singleton, reads `SPI_GETKEYBOARDDELAY` and `SPI_GETKEYBOARDSPEED`, then calls the file-local helper that sets keyboard delay to `0` and speed to `31`. Shutdown/deactivation/error paths call `RestoreSystemKeyboardSettings` to restore the original values.

This belongs in `NexusTK/input/KeySpeedMgr.cpp` rather than inside [UID:0000K6][InputMan](by-file/InputMan.md): `InputMan` handles Win32 input messages and IME state, while `KeySpeedMgr` only manages system keyboard repeat settings. A platform source path is plausible from the `SystemParametersInfoW` dependency, but the documented source tree and current file root keep this module in `input/`.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md) | `0x004efea0-0x004f0008` | Singleton class shell, field declarations, load/restore/apply keyboard-repeat settings, and ordinary destructor body. |
| [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md) | `0x004efea0-0x004f0008` | Non-emitting executable-island split/index over exact child pages, padding, and compiler wrapper evidence. |
| [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) | `0x004efea0-0x004efedd` | Source constructor publishes `g_pKeySpeedMgr` and initializes saved keyboard delay/speed fields to invalid sentinels; base/vptr/return mechanics stay compiler-generated. |
| [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) | `0x004efee0-0x004efef5` | Ordinary `~KeySpeedMgr` source destructor; source body clears `g_pKeySpeedMgr`, with vptr restoration and `LObject` base cleanup emitted by the compiler. |
| [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md) | `0x004eff00-0x004eff25` | Saves current Windows keyboard delay/speed into `m_savedKeyboardDelay` and `m_savedKeyboardSpeed` before startup applies fast repeat; both `SystemParametersInfoW` getter return values are ignored. |
| [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) | `0x004eff30-0x004eff5d` | Emits `void KeySpeedMgr::RestoreSystemKeyboardSettings()`, restoring saved keyboard delay/speed on cleanup/deactivation/error/exit paths with direct `SystemParametersInfoW` setter calls and no delete/destructor behavior. |
| [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md) | `0x004eff60-0x004eff91` | Retained no-xref file-local `static void __stdcall ApplyKeyboardRepeatSettings(UINT delay, UINT speed)` helper; applies caller-supplied keyboard delay/speed values with the same range limits and preserves the no-live-route caveat. |
| [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md) | `0x004effa0-0x004effbd` | File-local `static void ApplyFastKeyboardRepeatSettings()` helper; sets keyboard delay to `0` and keyboard speed to `31`. |
| [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) | `0x004effc0-0x004f0008` | Compiler-emitted scalar deleting destructor wrapper referenced by the vtable; reconstructable generated-binary evidence with a comment-only no-code marker rather than a handwritten source method. |
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
- 2026-06-21 B010 direct PE/Capstone recheck confirms the exact child ranges and padding in [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md), `SystemParametersInfoW` import at IAT `0x0060d3f8`, and file-local ownership for the raw/fast setter family.
- 2026-06-19 B014 constructor recheck confirms [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) should emit only source-shaped constructor effects: publish `g_pKeySpeedMgr`, set `m_savedKeyboardDelay` and `m_savedKeyboardSpeed` to `UINT(-1)`, and leave the `LObject` base call, vptr store, generated return-this lowering, and singleton-base/null-adjust pattern to compiler/header reconstruction.
- Earlier B006 caller-window evidence showed `Application::Initialize` calling `0x004effa0` after `mov ecx, esi` and `BaramAppOnActivate` calling it after loading/testing `g_pKeySpeedMgr`; B010 treats that as lifecycle context, not sufficient class-method proof, because the helper body reads no fields, singleton, or vtable state.
- The raw two-argument setter remains no-function/no-xref, but its `ret 8` stack signature, identical setter API pattern, adjacency to restore/fast-repeat, and paired naming make `static void __stdcall ApplyKeyboardRepeatSettings(UINT delay, UINT speed)` the best source-facing route. Keep original spelling/liveness below final-audit confidence rather than leaving the issue uninvestigated.
- 2026-06-21 B007 restore-method review confirms [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) is no longer an omitted/disabled method. It emits through the `KeySpeedMgr` class in this file, uses `m_savedKeyboardDelay` and `m_savedKeyboardSpeed`, calls direct Unicode `SystemParametersInfoW` with `SPI_SETKEYBOARDDELAY`, `SPI_SETKEYBOARDSPEED`, and `SPIF_UPDATEINIFILE`, and treats `InputMan`, `Application`, `WinMain`, and `ExceptionHandler` as caller/context owners only.
- 2026-06-21 B012 scalar-wrapper reanalysis keeps [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) routed through this file as class-specific compiler output. It should appear only as a comment marker in generated coverage/output; [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) carries the source destructor body.
- 2026-06-19 B015 load-method review confirms [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md) belongs in this file through the `KeySpeedMgr` class route: one startup caller at `0x00463aae`, no callback/vtable/data-pointer route, two direct `SystemParametersInfoW` getter calls, and no local error/range branching. Keep `Application`, `InputMan`, `WinMain`, `ExceptionHandler`, and generic platform code as caller/context alternatives only for this method.

## Migration Notes

- Candidate source path: `input/KeySpeedMgr.cpp`; `platform/KeySpeedMgr.cpp` remains a rejected/weaker alternative until the source tree moves Win32 keyboard state into a broader platform module.
- Keep `0x004eff60` and `0x004effa0` with this module as file-local helpers in `KeySpeedMgr.cpp`. The earlier B006 member-method route is a superseded historical assumption; B010 prefers file-local placement because neither helper uses `this`, the singleton global, or vtable state.
- Keep the restore method, ordinary destructor, and scalar deleting destructor in the file inventory even if generated coverage is temporarily stale.
- Keep the scalar deleting destructor as a routed generated-binary child with no handwritten wrapper source. The wrapper's vptr restore, singleton clear, base cleanup, delete flag tests, optional free, and guard-check path are compiler/MSVC ABI output.
- Keep [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) as a class method with source C++. The stale "disabled restore" and old 95/95 blank-code wording are superseded by the B006/B007 Rule 26 passes.
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

### 2026-08-17 B007 UID0000PA provider-header and WinMain-consumer sync

- `KeySpeedMgr.cpp` now begins with `#include "KeySpeedMgr.h"` and emits exact method/global children after the header include. `KeySpeedMgr.h` owns the complete guarded LObject-derived `0x0c` declaration and `g_pKeySpeedMgr` extern.
- [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md) restores system keyboard settings before invoking [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md); that helper performs ordinary `delete g_pKeySpeedMgr` and stays WinMain-local.
- This consumer relationship does not move the class or global out of KeySpeedMgr. Constructor/destructor/method children, saved delay/speed fields, and the storage definition remain in this provider.

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

### 2026-06-18 B003 destructor source-shape support

- Recorded [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) as the ordinary `~KeySpeedMgr` source destructor with first-draft body `g_pKeySpeedMgr = 0;`, and [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) as compiler wrapper evidence.
- Evidence: B003 raw PE/Capstone recheck confirmed exact bytes, padding, vptr store, singleton clear, tail jump to `LObject` cleanup, no direct route to the ordinary destructor start, and vtable route through the scalar deleting destructor.

### 2026-06-20 B006 Rule 26 source-quality incorporation

- Changed scores from `90/88` to `91/90`.
- Incorporated the aggregate non-emitting policy, raw/fast member-method reroute, `input/KeySpeedMgr.cpp` over `platform/KeySpeedMgr.cpp`, and [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) WinMain cleanup boundary.
- Evidence: B006 direct PE/Capstone and manual reference scans confirm exact aggregate child boundaries, all internal `0xcc` padding, `g_pKeySpeedMgr` refs, vtable refs, direct `SystemParametersInfoW` import use, restore/fast caller windows, and the lack of direct refs to the raw two-argument setter start.

### 2026-06-21 B007 restore-method source-quality sync

- Updated the file inventory and migration notes to reflect that [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) now carries accepted first-draft C++ through this source file.
- Evidence: B007 local IDA export review validates the exact restore body, import pointer, saved-field semantics, void source signature, four lifecycle callers, and restore-before-delete ordering in `_WinMain@16`; no source ownership moved to InputMan/Application/WinMain/ExceptionHandler.

### 2026-06-21 B010 aggregate source-quality sync

- Kept source path `NexusTK/input/KeySpeedMgr.cpp` and explicitly rejected `Application`, `WinMain`, `InputMan`, and generic `platform` ownership for the manager object and helper family. Those files remain lifecycle consumers or neighboring subsystem context.
- Changed the raw setter and fast-repeat inventory from class-member wording to file-local helper wording: `static void __stdcall ApplyKeyboardRepeatSettings(UINT delay, UINT speed)` and `static void ApplyFastKeyboardRepeatSettings()`.
- Kept [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md) as a non-emitting split/index. Exact child pages own method/helper C++ or scalar-wrapper no-body policy.
- Added the first-draft global recommendation `KeySpeedMgr *g_pKeySpeedMgr = 0;` through [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md); [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md) remains address evidence and should not duplicate the definition.

### 2026-06-21 B012 scalar deleting destructor source-quality sync

- Updated the file inventory after [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) moved from non-reconstructable/non-emitting wording to reconstructable source-declared/generated-binary wrapper wording.
- The source file route remains `NexusTK/input/KeySpeedMgr.cpp`. The wrapper contributes only a comment marker; no source-authored scalar deleting destructor body should be added.

### 2026-06-19 B014 constructor source-quality sync

- Updated the file inventory to describe [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) as source-shaped constructor code rather than decompiler/vtable mechanics.
- Evidence: B014 raw PE/Capstone and local IDA-export review confirmed the sole direct constructor caller at `0x00463a9a`, follow-on startup calls to load and fast-repeat helpers at `0x00463aae`/`0x00463ab5`, exact 61-byte body, singleton write, saved-field sentinels, three-byte successor padding, and `Singleton<KeySpeedMgr>` RTTI as a final-header lead.

### 2026-06-19 B015 load-method source-quality sync

- Updated the file inventory for [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md) to record the exact saved-field writes, ignored getter return values, and startup-only reachability.
- Evidence: B015 raw PE check confirmed the 37-byte load body, two `SystemParametersInfoW` getter calls for `SPI_GETKEYBOARDDELAY` and `SPI_GETKEYBOARDSPEED`, one rel32 caller at `0x00463aae`, no VA pointer hits, and clean eleven-byte padding before the restore method.
