*** UID:0001XX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# KeySpeedMgr Vtable

## Status

- Entity kind: vtable layout.
- Covered class: [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md).
- Likely owner source: [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md).
- Layout anchor: [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md).
- Confidence: strong for vptr base, RTTI pointer, store xrefs, and confirmed function-pointer slots.
- Evidence basis: IDA MCP `list_globals`, `xrefs_to`, `lookup_funcs`, `disasm`, `decompile`, and `py_eval` checks on 2026-05-26.

## Table

| Item | Address | Notes |
| --- | --- | --- |
| RTTI complete-object locator pointer | `0x0061c9c4` | Points to `??_R4KeySpeedMgr@@6B@` at `0x00649820`. |
| Primary vtable base | `0x0061c9c8` | Symbol `??_7KeySpeedMgr@@6B@`. |

## Confirmed Slots

| Slot | Target | Interpretation |
| --- | --- | --- |
| `+0x00` | `0x004effc0` | `KeySpeedMgr` scalar deleting destructor. |
| `+0x04` | `0x004f4b10` | Inherited `LObject` class-name/identity slot; returns `off_61CF44`, the `LObject` name record. |
| `+0x08` | `0x0041b6c0` | Inherited/default no-op callback slot (`retn 8`). |

The dwords at `0x0061c9d4` and `0x0061c9d8` both contain `0x400`; they are not code addresses and have no direct xrefs in the current IDA database. The next RTTI pointer at `0x0061c9dc` belongs to `LanguageMan`, so do not model those `0x400` constants as `KeySpeedMgr` virtual methods.

## Store And Xref Evidence

- IDA `list_globals *KeySpeedMgr*` reports vtable base `0x0061c9c8` and matching RTTI records.
- IDA `xrefs_to 0x0061c9c8` reports object vptr stores in the constructor at `0x004efecb`, non-deleting destructor at `0x004efee0`, and scalar deleting destructor at `0x004effc6`.
- IDA `xrefs_to 0x004effc0` reports the vtable data reference at `0x0061c9c8`.
- IDA disassembly identifies `0x004f4b10` as a tiny return of `off_61CF44`, annotated as `"LObject"`, and `0x0041b6c0` as a default `retn 8` no-op.
- Current `class_KeySpeedMgr.meta_wave3` reports `vtable_count: 0`, so generated metadata omits this confirmed RTTI-backed table.

## Source-Layout Implication

`KeySpeedMgr` is a compact `LObject`-derived input/platform singleton, not a plain C helper struct. Reconstruct the vtable as normal class inheritance; do not emit the inherited no-op slot or class-name helper as handwritten `KeySpeedMgr` source unless the final `LObject` header requires explicit overrides.

## Cross-References

- [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md)
- [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md)
- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md)
- [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md)
- [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md)
- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md)

## Changes

### 2026-05-31 - Rechecked score against IDA vtable evidence

- What existed before: the page had `COMPLETION:0`, `CONFIDENCE:0`, and a blank reconstructable flag despite detailed vtable evidence.
- What changed: scores now reflect the documented IDA-backed vtable/RTTI/store evidence, and the page is marked reconstructable as source-declared/generated-binary class metadata.
- Summary/evidence: IDA MCP confirms `??_R4KeySpeedMgr@@6B@` at `0x0061c9c4`, primary vtable `0x0061c9c8`, slots to `0x004effc0`, `0x004f4b10`, and `0x0041b6c0`, followed by non-slot `0x400` data and the next `LanguageMan` RTTI pointer.
