*** UID:00006Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "KeySpeedMgr.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_INPUT_KEYSPEEDMGR_H
#define NEXUSTK_INPUT_KEYSPEEDMGR_H

#include "../util/LObject.h"
#include <windows.h>

class KeySpeedMgr : public LObject
{
public:
    KeySpeedMgr();
    virtual ~KeySpeedMgr();

    void LoadSystemKeyboardSettings();
    void RestoreSystemKeyboardSettings();

private:
    UINT m_savedKeyboardDelay;
    UINT m_savedKeyboardSpeed;
};

extern KeySpeedMgr *g_pKeySpeedMgr;

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# KeySpeedMgr

## Status

- Confidence: strong for class identity, singleton lifecycle, object layout, keyboard repeat behavior, and source-file placement.
- Likely source file: [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- Main address range: [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- Type anchors: [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md), [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)
- Generated parent: attached to [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md); both pages clear the 80/80 parent gate and the file page owns the proposed `NexusTK/input/` source root.

## Class Purpose

`KeySpeedMgr` is a tiny `LObject`-derived singleton that stores and restores Windows keyboard repeat settings. It reads keyboard delay/speed through `SystemParametersInfoW`, allows the client to force repeat settings, and restores saved values during teardown, deactivation, crash, and exit paths.

The class page emits only the declaration shell and `[[CHILDREN]]`; exact by-memory children own constructor/load/restore/destructor method bodies. The aggregate [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md) is a non-emitting executable-island index after the B010 Rule 26 review, not a source-authored method body.

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) | `0x004efea0-0x004efedd` | Source constructor publishes `g_pKeySpeedMgr` and initializes saved keyboard delay/speed to `UINT(-1)`; `LObject` base construction, vptr setup, singleton-base adjustment, and return-this lowering are compiler/header mechanics. |
| [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) | `0x004efee0-0x004efef5` | Ordinary `~KeySpeedMgr` source destructor; formal source body clears `g_pKeySpeedMgr`, while the vptr store and `LObject` base cleanup are compiler-emitted destructor mechanics. |
| [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md) | `0x004eff00-0x004eff25` | Saves current Windows keyboard delay/speed into `m_savedKeyboardDelay` and `m_savedKeyboardSpeed` with `SystemParametersInfoW(SPI_GETKEYBOARDDELAY)` and `SystemParametersInfoW(SPI_GETKEYBOARDSPEED)`; ignored return values and no local range checks are intentional source behavior. |
| [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) | `0x004eff30-0x004eff5d` | Source-bearing `void KeySpeedMgr::RestoreSystemKeyboardSettings()` method; restores saved delay if `0..3` and saved speed if `0..31` using direct `SystemParametersInfoW` calls with `SPIF_UPDATEINIFILE`; caller return values are ignored, so the local decompiler's integer return is an artifact. |
| [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md) | `0x004eff60-0x004eff91` | Retained file-local `static void __stdcall ApplyKeyboardRepeatSettings(UINT delay, UINT speed)` helper in `KeySpeedMgr.cpp`; no `this`, singleton, vtable, caller, or pointer-table route is proven. |
| [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md) | `0x004effa0-0x004effbd` | File-local `static void ApplyFastKeyboardRepeatSettings()` helper that applies delay `0` and speed `31`; callers are lifecycle paths, but the body has no class-state access. |
| [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) | `0x004effc0-0x004f0008` | Compiler-emitted scalar deleting destructor wrapper referenced by the vtable; reconstructable source-declared/generated-binary evidence that emits only a comment marker while the ordinary destructor page carries source C++. |

## Data Notes

- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md) is at [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md).
- Stored fields at offsets `0x4` and `0x8` are `m_savedKeyboardDelay` and `m_savedKeyboardSpeed`.
- IDA confirms the object allocation size is `0x0c`: vptr at `+0x00`, saved delay at `+0x04`, and saved speed at `+0x08`.
- IDA confirms the RTTI-backed primary vtable at `0x0061c9c8`.
- 2026-06-06 live IDA refresh reconfirms all exact method/helper boundaries, ten `g_pKeySpeedMgr` data xrefs, and the `0x0061c9c8` vtable stores from constructor, ordinary destructor, and scalar deleting destructor.
- The exact by-memory method pages are the authority for migration; do not rely on generated-source omissions or historical metadata grades for the final source shape.
- B010 direct PE/Capstone recheck confirmed `SystemParametersInfoW` is imported from `USER32.dll` at IAT `0x0060d3f8`; the load, restore, raw setter, and fast-repeat bodies all call that import directly rather than a project-local wrapper.
- B010 supersedes the earlier B006 member-helper route for `0x004eff60` and `0x004effa0`. The helpers remain in the `KeySpeedMgr.cpp` neighborhood, but neither body reads object fields, the singleton global, or vtable state; they should be emitted as file-local helpers rather than class members. The older `ecx` caller-window observation remains a historical assumption and lifecycle-context clue only.
- Local RTTI reports `Singleton<KeySpeedMgr>` as a hierarchy lead. B014 local IDA export review narrows this to `KeySpeedMgr`, `LObject`, and `Singleton<KeySpeedMgr>` base-class descriptors, with the singleton-base descriptor using member displacement `4`; keep this in class/header reconstruction notes, but do not alter the proven `0x0c` object size or force the emitted base list until the final header pass resolves MSVC empty-base representation.
- Keep [UID:0000K6][InputMan](by-file/InputMan.md), [UID:0000HG][Application](by-file/Application.md), [UID:0000PA][WinMain](by-file/WinMain.md), and [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) as caller or neighboring subsystem context only. They do not own the `KeySpeedMgr` object fields, vtable, singleton, or repeat-setting method bodies.
- B007 restore-method reanalysis preserves [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) as source-bearing class code rather than no-code/compiler glue. It confirms the preferred source signature `void`, direct Unicode `SystemParametersInfoW` use with `SPI_SETKEYBOARDDELAY`, `SPI_SETKEYBOARDSPEED`, and `SPIF_UPDATEINIFILE`, saved-field names `m_savedKeyboardDelay` and `m_savedKeyboardSpeed`, and separation from [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md), [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md), and [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md).
- B012 scalar-wrapper reanalysis keeps [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) owned/emitted by this class as reconstructable generated-binary destructor ABI support, not as `CANONICAL_OWNER:NONE` or non-reconstructable glue. The target's comment-only marker is the whole emitted contribution; do not add a source-authored `ScalarDeletingDestructor` method to this class shell.
- B015 load-method reanalysis reconfirms [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md) as a source-authored class method, not a file-local helper, callback, constructor inline, or Application-owned routine. Its exact source body saves the current Windows keyboard delay/speed into the two fields, ignores both Win32 getter return values, and relies on the later restore method to range-check before writing settings back.

## Cross-References

- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md)
- [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)
- [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md)
- [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md)
- [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md)
- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md)
- [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0001QD][client_input_and_text_entry](by-meta/client_input_and_text_entry.md)

## Changes

- 2026-08-17 B007 UID0000PA provider-header closure:
  - Moved the exact `KeySpeedMgr : public LObject` declaration, two `UINT` saved settings, lifecycle/method declarations, and `g_pKeySpeedMgr` extern from the CPP channel into a complete guarded `KeySpeedMgr.h` payload with LObject and Windows dependencies.
  - The CPP channel now includes its own header before method/global children. This removes duplicate source declarations while supplying WinMain's typed delete and settings-restoration calls.
  - Object/global ownership stays in KeySpeedMgr. The source-local WinMain helper only orchestrates early-exit deletion and does not become the class or storage owner.

- Completion/confidence score update: existed before as `0/0`; changed to `82/86`. Summary: the class has highly detailed singleton purpose, layout, method, helper, global, vtable, and migration caveat documentation, but not a final source-level rewrite. Evidence: IDA-confirmed `SystemParametersInfoW` helper behavior, object size, vtable, singleton global, and linked by-memory pages.

### 2026-05-31 - Split method inventory and raw setter helper

- What existed before: the method inventory listed several ranges as bare names and did not include the raw `0x004eff60-0x004eff91` setter/helper.
- What changed: constructor, destructor, load, raw setter, and scalar deleting destructor entries now point to exact by-memory UID references; class scores were raised to `86/88` and marked reconstructable.
- Summary/evidence: IDA MCP reports exact function boundaries for `0x004efea0`, `0x004efee0`, `0x004eff00`, and `0x004effc0`, plus raw non-padding setter bytes at `0x004eff60-0x004eff91` and confirmed padding around each child range.

### 2026-06-06 - Attached class to source root

- What existed before: the class was reconstructable but had a blank autogen parent, leaving class-owned children with no generated-source root chain.
- What changed: `AUTOGEN_PARENT_UID` now points to [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md), and generated-source provenance caveats were removed from the class status notes.
- Summary/evidence: the by-file page is scored `90/88`, this class is scored `86/88`, and live IDA reconfirms the class method cluster, singleton slot, layout, and vtable evidence that place the class in `NexusTK/input/KeySpeedMgr.cpp`.

### 2026-06-18 B003 destructor source-shape support

- Updated [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) to treat `g_pKeySpeedMgr = 0;` as the ordinary destructor's first-draft source body and [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) as compiler wrapper evidence.
- Evidence: raw PE/Capstone recheck confirmed the ordinary destructor's vptr store, singleton clear, and tail jump to `LObject` cleanup, while vtable reachability points to the scalar deleting destructor at `0x004effc0`. Vptr restoration, base cleanup, delete flags, and guard checks are compiler-emitted destructor mechanics rather than explicit class source.

### 2026-06-20 B006 Rule 26 source-quality incorporation

- Changed scores from `86/88` to `89/91` and populated declaration-only class C++ with `[[CHILDREN]]`.
- Incorporated the B006 aggregate reanalysis: [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md) is now a non-emitting executable-island index, exact children own method bodies, `m_savedKeyboardDelay` and `m_savedKeyboardSpeed` are the class field names, raw setter and fast-repeat are class member methods, and the scalar deleting destructor is compiler wrapper evidence.
- Evidence: direct PE/Capstone recheck confirmed the aggregate child ranges, `0xcc` padding, import `SystemParametersInfoW` at `0x0060d3f8`, constructor/load/restore/raw/fast/scalar bytes, ten `g_pKeySpeedMgr` refs, vtable slot `0x0061c9c8`, and fast-repeat callers passing `g_pKeySpeedMgr`/constructed object in `ecx`.

### 2026-06-21 B007 restore-method source-quality sync

- Added explicit class-level support for [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) emitting source-bearing restore code through this class.
- Evidence: B007 local IDA export review confirms object-field reads, direct `SystemParametersInfoW` setter calls through the same import as the sibling methods, four live lifecycle callers, `_WinMain@16` restore-before-delete ordering, and rejection of scalar-delete/file-local/padding interpretations.

### 2026-06-21 B010 source-quality sync

- Changed score to `88/91` and removed the raw setter / fast-repeat declarations from the class shell. Constructor, virtual destructor, load, and restore remain class methods; the two setter helpers now emit as file-local helpers from [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md).
- Resolved class fields as `m_savedKeyboardDelay` at `+0x04` and `m_savedKeyboardSpeed` at `+0x08`; both store the user's original Windows keyboard repeat settings for later restore.
- Rejected class ownership for [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md) and [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md). The previous B006 `ecx`-based interpretation is kept above as historical context, but B010 treats no field/global/vtable access as stronger source-placement evidence for file-local helpers.
- Recorded `Singleton<KeySpeedMgr>` RTTI as a header-reconstruction lead only; final base-list spelling remains outside this class-page pass because proven field offsets and object size must not be disturbed.

### 2026-06-21 B012 scalar deleting destructor source-quality sync

- Updated the [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) class notes from non-reconstructable/non-emitting wording to reconstructable source-declared/generated-binary wrapper wording.
- The class declaration with `virtual ~KeySpeedMgr();` and [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) regenerate the ABI wrapper; the wrapper page emits only a comment marker and still must not become a handwritten class method.

### 2026-06-19 B014 constructor source-quality sync

- Updated the constructor method row to source-shaped C++ language: `g_pKeySpeedMgr = this`, `m_savedKeyboardDelay = UINT(-1)`, and `m_savedKeyboardSpeed = UINT(-1)`.
- Evidence: B014 raw PE/Capstone and local IDA-export review confirmed the exact 61-byte constructor, only direct caller at `0x00463a9a`, base-constructor call at `0x004efeaa`, singleton write at `0x0067ab48`, vptr store at `0x004efecb`, saved-field writes at `+0x04`/`+0x08`, three-byte padding before the ordinary destructor, and the `Singleton<KeySpeedMgr>` RTTI descriptor as header-reconstruction evidence.

### 2026-06-19 B015 load-method source-quality sync

- Updated the [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md) method row to record the resolved field names, ignored getter return values, and source-authored first-draft body.
- Evidence: B015 raw PE check confirmed the exact 37-byte body at file offset `0xef300`, direct calls through the `SystemParametersInfoW` import, one startup rel32 caller at `0x00463aae`, no data-pointer route to `0x004eff00`, and eleven `0xcc` bytes before the restore method.
