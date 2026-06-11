*** UID:0001UV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00006Z | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

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
| `+0x04` | 4 | saved Windows keyboard delay | Constructor initializes to `0xffffffff`; `LoadSystemKeyboardSettings` passes this address to `SPI_GETKEYBOARDDELAY`; restore accepts values `0..3`. |
| `+0x08` | 4 | saved Windows keyboard speed | Constructor initializes to `0xffffffff`; `LoadSystemKeyboardSettings` passes this address to `SPI_GETKEYBOARDSPEED`; restore accepts values `0..31`. |

## Behavior Evidence

- `Application::Initialize` allocates `0x0c` bytes for the singleton, calls `KeySpeedMgr::KeySpeedMgr`, then calls `LoadSystemKeyboardSettings` and the adjacent fast-repeat helper.
- `KeySpeedMgr::KeySpeedMgr` calls the `LObject` base constructor, stores `g_pKeySpeedMgr`, initializes both saved settings to `0xffffffff`, and installs the `KeySpeedMgr` vptr.
- `KeySpeedMgr::RestoreSystemKeyboardSettings` reads `+0x04` and `+0x08` and only restores values inside the Windows-supported ranges.
- `0x004eff60-0x004eff91` is an IDA-unmodeled two-argument raw helper that applies caller-supplied keyboard delay/speed values after validating them against the same `0..3` and `0..31` limits; no current xrefs are known.
- `ApplyFastKeyboardRepeatSettings` has no `this` access; it is a file-local helper paired with the saved fields, not a `KeySpeedMgr` method.

## Reconstruction Notes

Model the source object as a tiny `LObject`-derived singleton:

```cpp
class KeySpeedMgr : public LObject {
    UINT m_savedKeyboardDelay;
    UINT m_savedKeyboardSpeed;
};
```

Use sentinel/invalid values such as `UINT(-1)` in source instead of carrying the decompiler's negative-pointer or raw `0xffffffff` artifacts into the rewritten constructor.

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
