*** UID:0000RB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
KeySpeedMgr *g_pKeySpeedMgr = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pKeySpeedMgr

## Status

- Confidence: strong for address and singleton role.
- Address: [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md)
- Likely owner file: [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)

## Purpose

`g_pKeySpeedMgr` stores the active [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md) singleton. The manager preserves the user's keyboard repeat delay/speed and restores those settings during shutdown or deactivation paths.

## Evidence Notes

- IDA MCP decompilation of `0x004efea0` writes `dword_67AB48 = this`.
- IDA MCP decompilation of `0x004efee0` and `0x004effc0` clears `dword_67AB48`.
- 2026-05-24 IDA recheck found ten data refs, including startup/init callers at `0x00464af6`, `0x00464b04`, `0x00466a1a`, cleanup/deactivation/error/exit refs at `0x00466ad1`, `0x004673c0`, `0x004ab833`, and `0x004f5edc`, plus constructor/destructor refs at `0x004efebd`, `0x004efee6`, and `0x004effcc`.
- 2026-06-10 B001-014 confirms [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) reads this global and deletes the active singleton from the `WinMain` early-exit path. That wrapper is a consumer/cleanup policy helper owned by [UID:0000PA][WinMain](by-file/WinMain.md); this global and the object lifecycle remain owned by [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md).
- 2026-05-26 exact memory page: [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md), with the same startup/cleanup/destructor xref family.
- 2026-05-26 layout/vtable pass: [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md) records the `0x0c` object and saved keyboard fields; [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md) records the RTTI-backed vtable at `0x0061c9c8`.
- Generated source names this storage `g_pKeySpeedMgr`.
- Current `simroot_v2/class_KeySpeedMgr.cpp` assigns `g_pKeySpeedMgr = this` in `KeySpeedMgr::KeySpeedMgr`, clears it in the constructor guard path, declares `KeySpeedMgr* g_pKeySpeedMgr`, and clears it in `KeySpeedMgr::ScalarDeletingDestructor`.
- `simroot_v2/class_KeySpeedMgr.cpp.source_map.json` maps `global-data:g_pKeySpeedMgr` to data range `0x0067ab48-0x0067ab4b` with `memory_range_coverage_status: resolved` and no missing memory-range lines.
- Historical generation caveat: older generated-source material left `RestoreSystemKeyboardSettings` at `0x004eff30` in `class_KeySpeedMgr.cpp.disabled`, while `class_KeySpeedMgr.meta_wave3` still listed it in the KeySpeedMgr method family. The B006/B007 Rule 26 passes supersede that disabled-state blocker: [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) now carries accepted first-draft C++ and emits through [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md) to [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md).
- 2026-06-16 C001 live IDA refresh in session `b001_mappane_0001AW_20260616` reconfirmed the current `.data` window `0x0067ab40-0x0067ab8f` is zero-filled in the saved IDB, not `0xffffffff`; reconfirmed the ten xrefs to `0x0067ab48`; decompiled the restore helper range-checking `SystemParametersInfoW(0x17, delay, 0, 1)` and `SystemParametersInfoW(0x0b, speed, 0, 1)`; and saved labels `g_pKeySpeedMgr`, `KeySpeedMgr_Constructor`, `KeySpeedMgr_Destructor`, `KeySpeedMgr_RestoreSystemKeyboardSettings`, `ApplyFastKeyboardRepeatSettings`, `KeySpeedMgr_ScalarDeletingDestructor`, and `DestroyKeySpeedMgr`.
- 2026-06-20 B006 Rule 26 pass confirms this global is the single `KeySpeedMgr` singleton definition emitted by the file root. Do not duplicate the definition from exact storage [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md); the storage page remains the address evidence.
- 2026-06-21 B007 restore-method sync confirms this global's restore callers now route to a source-bearing [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) method. [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) still remains WinMain-owned cleanup after restore; singleton declaration ownership stays here under the `KeySpeedMgr` file root.
- 2026-06-21 B010 aggregate review reaffirms first-draft source as `KeySpeedMgr *g_pKeySpeedMgr = 0;` under [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md). Constructor, ordinary destructor, scalar deleting destructor wrapper, restore, fast-repeat, WinMain cleanup, and exception paths are consumers/writers of this singleton; [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) remains WinMain cleanup glue, not global ownership.

## Cross-References

- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md)
- [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md)
- [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)
- [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md)
- [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md)
- [UID:0001QD][client_input_and_text_entry](by-meta/client_input_and_text_entry.md)

## Changes

### 2026-08-17 B007 UID0000PA provider and current-regression sync

- Preserved `KeySpeedMgr *g_pKeySpeedMgr = 0;` as the single source definition under KeySpeedMgr and moved the complete extern/class declaration into `KeySpeedMgr.h`.
- Fresh UID0000PA evidence confirms the exact storage bytes are `00 00 00 00`, the slot has ten direct references, and the current IDB may display the automatic alias `unk_67AB48` when the previously saved semantic head name is absent. That display regression does not change the source-facing identity or ownership.
- WinMain remains a consumer: it calls the restore method and then its file-local [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) helper. Constructor publication, destructor clears, Application setup, fast-repeat policy, deactivation, and error cleanup remain the other documented readers/writers.

### 2026-06-10 B001-014 WinMain cleanup reference

- Changed from `84/88` to `85/88`.
- Added the missing `0x004673c0` read/reference and linked [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) as a non-owned `WinMain` cleanup wrapper.
- Summary and evidence: IDA MCP confirms `0x004673c0` loads `dword_67AB48`, null-checks it, and invokes the deleting destructor via the object's vtable; the only direct caller found is `WinMain` at `0x004f5eeb`, after keyboard-setting restore.

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence header values while already documenting the singleton address, purpose, IDA xrefs, layout/vtable anchors, and owner.
- What changed: completion/confidence were raised to `84/88`, and the evidence notes included current generated-code writes/clears, source-map binding, and the then-current disabled-companion caveat for `RestoreSystemKeyboardSettings`.
- Summary and evidence: source-map data resolves `g_pKeySpeedMgr` to `0x0067ab48-0x0067ab4b`, and generated code shows constructor/destructor singleton lifecycle behavior. That restore-omission caveat is historical only after the B006/B007 Rule 26 passes; the remaining score cap is final declaration/header placement and complete xref detail, not `00018P` being no-code.

### 2026-06-05 autogen parent correction

- What existed before: `g_pKeySpeedMgr` was reconstructable but unassigned, while [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md) pointed to this global page as its autogen parent.
- What changed: `AUTOGEN_PARENT_UID` now points to [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md), giving the global page a valid by-file root chain.
- Summary and evidence: both this global page (`84/88`) and the `KeySpeedMgr` by-file page (`90/88`) clear the 80/80 attachment gate, and the evidence notes already tie the singleton storage to the `KeySpeedMgr` constructor/destructor lifecycle.

### 2026-06-16 C001 safe IDA refresh

- Changed scores from `85/88` to `87/90`.
- Summary/evidence: live IDA reconfirmed ten direct singleton xrefs, current zero-filled storage bytes, constructor/destructor/restore/fast-repeat/deleting-destructor/deletion-wrapper bounds, and saved the `g_pKeySpeedMgr` data label plus six KeySpeedMgr/WinMain cleanup function labels. The later B006/B007 Rule 26 passes resolve the restore-method generated-source caveat; final declaration/header placement remains the only singleton-page C++ caveat.

### 2026-06-20 B006 Rule 26 source-quality incorporation

- Changed scores from `87/90` to `89/91` and populated formal global C++ as `KeySpeedMgr *g_pKeySpeedMgr = 0;`.
- Preserved object/global ownership split: [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) remains WinMain-owned cleanup glue, while this global and the `KeySpeedMgr` object lifecycle remain owned by [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md).

### 2026-06-21 B010 source-quality sync

- Preserved `89/91` and the formal global definition.
- Reconfirmed that exact storage [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md) should stay blank to avoid duplicate emitted definitions.
- Rejected moving ownership to `Application`, `WinMain`, `InputMan`, or generic platform code; those paths read or clean up the singleton but do not own the object/global declaration.
