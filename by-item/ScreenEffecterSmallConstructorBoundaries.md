*** UID:0000VE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScreenEffecter Small Constructor Boundaries

## Status

- Entity kind: raw constructor-boundary evidence.
- Confidence: strong that these are real project-code constructors, medium for IDA-modeled function boundaries.
- Autogen parent: [UID:0000IZ][Effects](by-file/Effects.md).
- Related range cluster: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md).
- Rebuild handling: source-declared constructor code produced by screen-effecter class declarations. Marked reconstructable and attached to `Effects`, but C++ is blank until class layouts, surrounding effecter ranges, and constructor boundaries are near-final.

## Summary

Several runtime effecter constructors are too small for the current IDA database to model as function records, but the bytes at each address are normal constructor-shaped code. They install the expected vtable, initialize local fields when needed, return cleanly, and are separated from the next routine by alignment bytes.

Do not discard these rows just because IDA `lookup_funcs` has no function object at the start. The correct reconstruction owner remains the shared runtime effects module.

## Live IDA MCP Raw-Body Evidence

2026-06-03 live IDA MCP `lookup_funcs` and `py_eval` inspection found no function object and no direct code xrefs to the raw start addresses below, but confirmed the constructor bytes and vtable data xrefs:

| Range | Class | Confirming bytes / behavior |
| --- | --- | --- |
| `0x0055a2a0-0x0055a2b3` | [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) | Prologue, `this` save, `mov [ecx], 0x006235c4`, returns `this`, then `align 10h`; vtable ref in range at `0x0055a2a9`. |
| `0x0055b000-0x0055b037` | [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md) | Calls `FilterEffecter` at `0x0055ad00`, then stores four cloud vtable views at `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`, ending at `retn` then alignment. |
| `0x0055b090-0x0055b0c7` | [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md) | Same constructor shape as cloud, but stores static-cloud vtables `0x00623b3c`, `0x00623b5c`, `0x00623ba8`, and `0x00623bd8`. |
| `0x0055b110-0x0055b151` | [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) | Stores vtable `0x00623be4`, reads timer state from `dword_67AB80 + 0x18`, subtracts `0x3c`, stores the two `short` arguments at `+0x04`/`+0x06`, zeros state at `+0x08`/`+0x0c`, and returns with `retn 8`. |
| `0x0055b4a0-0x0055b4b3` | [UID:0000GD][YFlipEffecter](by-class/YFlipEffecter.md) | Minimal constructor stores vtable `0x00623c2c`, returns `this`, then aligns before the IDA-modeled body at `0x0055b4c0`. |
| `0x0055b810-0x0055b851` | [UID:000070][LakeEffecter](by-class/LakeEffecter.md) | Clamps the float argument with constants at `0x00623d40` and `0x00620c68`, stores vtable `0x00623cf8`, stores clamped blend/timer state, and returns with `retn 4`. |

Neighboring modeled functions remain intact: `sub_55A2C0` starts at `0x0055a2c0`, `nullsub_50` starts at `0x0055b040`, `sub_55B160` starts at `0x0055b160`, `sub_55B4C0` starts at `0x0055b4c0`, `sub_55B860` starts at `0x0055b860`, and `sub_55B870` starts at `0x0055b870`. That confirms these constructor islands are not accidental overlap with adjacent modeled functions.

## Reconstruction Guidance

- Keep these as reconstructable constructors in `render/Effects.cpp`.
- Keep the class docs honest: IDA currently lacks function records for the starts, but raw disassembly and vtable xrefs confirm the code identities.
- Use [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) as the vtable/layout authority.
- Treat absent direct xrefs to these tiny starts as an IDA database limitation or construction-through-thunk issue, not proof that the constructors are dead.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP raw-disassembly verification on 2026-05-31 reconfirmed constructor-shaped bytes and absent IDA function records at the exact starts. The score remains below 95 because function-boundary modeling, caller paths, and final effecter class/source placement are not fully audited.
- 2026-06-03 update: live IDA MCP rechecked all six raw constructor islands, exact neighboring modeled functions, vtable-store xrefs, return cleanup, and absent direct code xrefs to the raw starts. Completion increased from 70 to 82 and confidence from 85 to 90 because the raw boundaries and `Effects` parent assignment are now documented from current IDA output without relying on old staging metadata. The score remains below 95 because IDA still lacks function objects at the raw starts and the direct construction call paths are not proven.
