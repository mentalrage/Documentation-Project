*** UID:0000RB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

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
- Generation caveat: `RestoreSystemKeyboardSettings` at `0x004eff30` remains in `class_KeySpeedMgr.cpp.disabled`, while `class_KeySpeedMgr.meta_wave3` still lists it in the KeySpeedMgr method family. Keep the restore behavior documented, but do not treat the current active generated file as fully complete.

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

### 2026-06-10 B001-014 WinMain cleanup reference

- Changed from `84/88` to `85/88`.
- Added the missing `0x004673c0` read/reference and linked [UID:00032A][0x004673c0-0x004673d1.DestroyKeySpeedMgr](by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md) as a non-owned `WinMain` cleanup wrapper.
- Summary and evidence: IDA MCP confirms `0x004673c0` loads `dword_67AB48`, null-checks it, and invokes the deleting destructor via the object's vtable; the only direct caller found is `WinMain` at `0x004f5eeb`, after keyboard-setting restore.

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence header values while already documenting the singleton address, purpose, IDA xrefs, layout/vtable anchors, and owner.
- What changed: completion/confidence were raised to `84/88`, and the evidence notes now include current generated-code writes/clears, source-map binding, and the disabled-companion caveat for `RestoreSystemKeyboardSettings`.
- Summary and evidence: source-map data resolves `g_pKeySpeedMgr` to `0x0067ab48-0x0067ab4b`, and generated code shows constructor/destructor singleton lifecycle behavior. The score remains below near-complete because the restore method is not currently emitted in the active source file and the page does not enumerate every startup/cleanup xref in detail.

### 2026-06-05 autogen parent correction

- What existed before: `g_pKeySpeedMgr` was reconstructable but unassigned, while [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md) pointed to this global page as its autogen parent.
- What changed: `AUTOGEN_PARENT_UID` now points to [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md), giving the global page a valid by-file root chain.
- Summary and evidence: both this global page (`84/88`) and the `KeySpeedMgr` by-file page (`90/88`) clear the 80/80 attachment gate, and the evidence notes already tie the singleton storage to the `KeySpeedMgr` constructor/destructor lifecycle.
