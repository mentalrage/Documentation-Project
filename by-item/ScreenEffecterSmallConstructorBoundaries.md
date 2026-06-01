*** UID:0000VE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScreenEffecter Small Constructor Boundaries

## Status

- Entity kind: raw constructor-boundary evidence.
- Confidence: strong that these are real project-code constructors, medium for IDA-modeled function boundaries.
- Proposed owner: [UID:0000IZ][Effects](by-file/Effects.md).
- Related range cluster: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md).
- Rebuild handling: `source-declared/generated-binary` constructor code produced by screen-effecter class declarations. Marked reconstructable, but parent attachment and C++ are blank until class layouts, surrounding effecter ranges, and constructor boundaries are near-final.

## Summary

Several runtime effecter constructors are too small for the current IDA database to model as function records, but the bytes at each address are normal constructor-shaped code. They install the expected vtable, initialize local fields when needed, return cleanly, and are separated from the next routine by alignment bytes.

Do not discard these rows just because IDA `lookup_funcs` has no function object at the start. Also do not treat the generated one-class files as original source layout. The correct reconstruction owner remains the shared runtime effects module.

## Read-Only IDA Recheck

2026-05-26 read-only IDA MCP `py_eval` inspection found no function object and no direct xrefs to the raw start addresses below, but confirmed the constructor bytes and vtable data xrefs:

| Range | Class | Confirming bytes / behavior |
| --- | --- | --- |
| `0x0055a2a0-0x0055a2b3` | [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) | Prologue, `mov [ecx], 0x006235c4`, returns `this`, then `align 10h`. Vtable xrefs to `0x006235c4` land at `0x0055a2a9` and at the [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) base path `0x0055a30b`. |
| `0x0055b000-0x0055b037` | [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md) | Calls `FilterEffecter` at `0x0055ad00`, then stores four cloud vtable views at offsets `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`, ending at `retn` then alignment. |
| `0x0055b090-0x0055b0c7` | [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md) | Same constructor shape as cloud, but stores the static-cloud vtable family at `0x00623b3c`, `0x00623b5c`, `0x00623ba8`, and `0x00623bd8`. |
| `0x0055b110-0x0055b151` | [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) | Stores vtable `0x00623be4`, reads timer state from `dword_67AB80 + 0x18`, subtracts `0x3c`, stores amplitudes from the two `short` arguments, zeros state, and returns with `retn 8`. |
| `0x0055b4a0-0x0055b4b3` | [UID:0000GD][YFlipEffecter](by-class/YFlipEffecter.md) | Minimal vtable install at `0x00623c2c`, returns `this`, then aligns before the IDA-modeled `ApplyEffect` body at `0x0055b4c0`. |
| `0x0055b810-0x0055b851` | [UID:000070][LakeEffecter](by-class/LakeEffecter.md) | Clamps the float argument with constants at `0x00623d40` and `0x00620c68`, stores vtable `0x00623cf8`, stores clamped blend/timer state, and returns with `retn 4`. |

2026-05-31 IDA MCP recheck confirmed all six raw starts still have no IDA function object at the exact address, but disassembly at each start is valid constructor code: standard prologue/`this` setup, expected vtable store(s), state initialization where applicable, return, and alignment. The raw starts also report no direct code xrefs in the current IDA database, so the "do not discard due missing IDA function record" warning remains current.

## Reconstruction Guidance

- Keep these as reconstructable constructors in `render/Effects.cpp`.
- Keep the class docs honest: IDA currently lacks function records for the starts, but raw disassembly and vtable xrefs confirm the code identities.
- Use [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) as the vtable/layout authority while generated metadata still reports `vtable_count: 0`.
- Treat absent direct xrefs to these tiny starts as an IDA database limitation or construction-through-thunk issue, not proof that the constructors are dead.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP raw-disassembly verification on 2026-05-31 reconfirmed constructor-shaped bytes and absent IDA function records at the exact starts. The score remains below 95 because function-boundary modeling, caller paths, and final effecter class/source placement are not fully audited.
