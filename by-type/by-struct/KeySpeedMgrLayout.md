*** UID:0001UV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006Z | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006Z | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# KeySpeedMgr Layout

## Status

- Entity kind: class/object layout.
- Covered class: [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md).
- Likely owner source: [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md).
- Vtable anchor: [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md).
- Confidence: strong for object size, field offsets, singleton storage, and keyboard-setting semantics.
- Autogen parent: attached to [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md); the class scores `86/88` and this layout scores `86/90`, so both sides satisfy the 80/80 parent gate.
- Evidence basis: IDA MCP decompilation/xref/byte checks on 2026-05-26 and 2026-05-31 plus `simroot_v2` only as a lead/cross-check.

## Layout

IDA shows the startup path allocating `0x0c` bytes before calling `KeySpeedMgr::KeySpeedMgr`. No fields beyond `+0x08` are observed.

| Offset | Size | Field hypothesis | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable pointer / `LObject` base vptr | Constructor writes `0x0061c9c8` at `0x004efecb`; non-deleting destructor writes it at `0x004efee0`; scalar deleting destructor writes it at `0x004effc6`. |
| `+0x04` | 4 | `UINT m_savedKeyboardDelay` | Constructor initializes to `0xffffffff`; `LoadSystemKeyboardSettings` passes this address to `SPI_GETKEYBOARDDELAY`; restore accepts values `0..3`. |
| `+0x08` | 4 | `UINT m_savedKeyboardSpeed` | Constructor initializes to `0xffffffff`; `LoadSystemKeyboardSettings` passes this address to `SPI_GETKEYBOARDSPEED`; restore accepts values `0..31`. |

## Behavior Evidence

- `Application::Initialize` allocates `0x0c` bytes for the singleton, calls `KeySpeedMgr::KeySpeedMgr`, then calls `LoadSystemKeyboardSettings` and the adjacent fast-repeat helper.
- `KeySpeedMgr::KeySpeedMgr` calls the `LObject` base constructor, stores `g_pKeySpeedMgr`, initializes both saved settings to `0xffffffff`, and installs the `KeySpeedMgr` vptr.
- `KeySpeedMgr::RestoreSystemKeyboardSettings` reads `+0x04` and `+0x08` and only restores values inside the Windows-supported ranges.
- B015 load-method reanalysis confirms `m_savedKeyboardDelay` and `m_savedKeyboardSpeed` are the best descriptive source field names for first-draft code: `LoadSystemKeyboardSettings` passes `&m_savedKeyboardDelay` to `SPI_GETKEYBOARDDELAY` and `&m_savedKeyboardSpeed` to `SPI_GETKEYBOARDSPEED`, while restore later validates the same values before setter calls.
- `0x004eff60-0x004eff91` is an IDA-unmodeled retained file-local helper that applies caller-supplied keyboard delay/speed values after validating them against the same `0..3` and `0..31` limits; no current xrefs are known, so original spelling and liveness remain capped below final-audit confidence.
- `ApplyFastKeyboardRepeatSettings` has no field reads and B010 classifies it as a file-local helper in `KeySpeedMgr.cpp`. Earlier B006 caller-window evidence showed callers loading the active object into `ecx`; keep that as lifecycle context only, not as a reason to add fields or force member-method layout.
- Local RTTI reports `Singleton<KeySpeedMgr>` as a hierarchy lead. B014 local IDA export review identifies `KeySpeedMgr`, `LObject`, and `Singleton<KeySpeedMgr>` base-class descriptors, with the singleton descriptor using member displacement `4`. Treat it as header-reconstruction evidence only; it does not move the proven vptr at `+0x00`, saved delay at `+0x04`, saved speed at `+0x08`, or object size `0x0c`.

## Reconstruction Notes

Model the source object as a tiny `LObject`-derived singleton:

```cpp
class KeySpeedMgr : public LObject, public Singleton<KeySpeedMgr> {
    UINT m_savedKeyboardDelay;
    UINT m_savedKeyboardSpeed;
};
```

IDA RTTI exposes `Singleton<KeySpeedMgr>` as a base-class descriptor at member displacement `4`. That singleton base appears to be empty/overlapped for data-layout purposes; the observed writable fields remain `+0x04` saved keyboard delay and `+0x08` saved keyboard speed, and the object allocation remains `0x0c` bytes.

Use sentinel/invalid values such as `UINT(-1)` in source instead of carrying the decompiler's negative-pointer or raw `0xffffffff` artifacts into the rewritten constructor.

Treat `m_savedKeyboardDelay` and `m_savedKeyboardSpeed` as final descriptive draft names for first-draft source. Their roles are strongly proven by constructor sentinels, load getter targets, restore range checks, and the fixed fast-repeat helper; only exact original member spelling remains unproven by recovered symbols.

## Cross-References

- [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md)
- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)
- [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md)
- [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md)
- [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md)
- [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md)
- [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md)
- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md)

## Changes

- 2026-06-06: Attached the tiny object layout to [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md). Scores remain `86/90`; this updates parent metadata only because the singleton class and layout pages already document the same 0x0c object.

### 2026-05-31 - Rechecked score and raw setter boundary

- What existed before: the page had `COMPLETION:0`, `CONFIDENCE:0`, and did not mention the raw two-argument helper at `0x004eff60`.
- What changed: scores now reflect the already documented IDA-backed layout, the page is marked reconstructable, and the raw setter/helper evidence was added.
- Summary/evidence: IDA MCP reports a `0x0c` allocation, vtable stores at `0x004efecb`, `0x004efee0`, and `0x004effc6`, singleton refs to `0x0067ab48`, `SystemParametersInfoW` field usage at `this+4` and `this+8`, and raw non-padding helper bytes at `0x004eff60-0x004eff91`.

### 2026-06-20 B006 Rule 26 source-quality incorporation

- Changed scores from `86/90` to `88/91`.
- Standardized the fields to `m_savedKeyboardDelay` at `+0x04` and `m_savedKeyboardSpeed` at `+0x08`, preserving `UINT` as the Win32 role type.
- Updated the raw/fast setter notes after B006 direct PE/Capstone recheck: the raw setter remains no-xref but is best modeled as `KeySpeedMgr::ApplyKeyboardRepeatSettings(UINT, UINT)`, while fast-repeat is a member method because its callers pass the constructed singleton or `g_pKeySpeedMgr` in `ecx`.

### 2026-06-21 B010 source-quality sync

- Preserved `88/91`, `0x0c` object size, and the field names `m_savedKeyboardDelay` / `m_savedKeyboardSpeed`.
- Superseded the B006 member-helper interpretation for `0x004eff60` and `0x004effa0`: B010 keeps both bodies in `KeySpeedMgr.cpp` but models them as file-local helpers because they do not read object fields, singleton storage, or vtable state.
- Added the `Singleton<KeySpeedMgr>` RTTI note as a header-pass lead without altering field offsets or emitted layout.

### 2026-06-19 B014 constructor/layout source-quality sync

- Refined the layout reconstruction snippet to include `Singleton<KeySpeedMgr>` as a header-reconstruction lead while preserving the exact `0x0c` object size and field offsets.
- Evidence: B014 raw PE/Capstone and local IDA-export review confirmed the constructor's singleton-base adjustment pattern before `g_pKeySpeedMgr` publication, the saved delay/speed sentinel writes at `+0x04` and `+0x08`, and the restore-range model (`0..3` delay, `0..31` speed) that makes `UINT(-1)` a deliberate invalid sentinel.

### 2026-06-19 B015 load-method source-quality sync

- Added explicit layout support for [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md): the load body writes current Windows keyboard repeat settings into `m_savedKeyboardDelay` and `m_savedKeyboardSpeed` without local error checks.
- Evidence: B015 raw PE check and existing IDA-backed docs agree on `this+0x04` as the `SPI_GETKEYBOARDDELAY` target and `this+0x08` as the `SPI_GETKEYBOARDSPEED` target; these field names are high-confidence descriptive draft names, with only exact original spelling unresolved.
