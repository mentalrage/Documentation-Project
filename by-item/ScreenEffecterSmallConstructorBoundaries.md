*** UID:0000VE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Raw constructor-boundary support only. The six constructor-shaped byte
// islands are source-authored, but current MCP still reports no IDA function
// objects and no direct xrefs to their starts. Emit declarations or exact child
// bodies from the owning class/memory pages, not from this support aggregate.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScreenEffecter Small Constructor Boundaries

## Status

- Entity kind: raw constructor-boundary evidence.
- Confidence: strong that these are real project-code constructors, medium for IDA-modeled function boundaries.
- Owner/emitter route: [UID:0000IZ][Effects](by-file/Effects.md).
- Related range cluster: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md).
- Rebuild handling: source-declared constructor code produced by screen-effecter class declarations. Marked reconstructable and attached to `Effects`, but C++ is blank until class layouts, surrounding effecter ranges, and constructor boundaries have source-quality evidence.

## Summary

Several runtime effecter constructors are too small for the current IDA database to model as function records, but the bytes at each address are normal constructor-shaped code. They install the expected vtable, initialize local fields when needed, return cleanly, and are separated from the next routine by alignment bytes.

Do not discard these rows just because IDA `lookup_funcs` has no function object at the start. The correct reconstruction owner remains the shared runtime effects module.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The page now has the six raw constructor islands, current no-function/no-direct-xref evidence, vtable-store xrefs, raw byte and padding checks, adjacent modeled function boundaries, exact support children for StaticCloud/YFlip/Lake, and current owner/emitter route. It remains below final audit because several raw starts still lack IDA function records and direct construction call paths are not proven. |
| Confidence `90` | Confidence remains strong for the raw-boundary classification and `Effects` routing because current bytes and vtable refs match the linked runtime cluster and exact child pages. It is not higher because final class layouts, constructor signatures, and original source split remain unresolved. |

## Live IDA MCP Raw-Body Evidence

2026-06-03 live IDA MCP `lookup_funcs` and `py_eval` inspection found no function object and no direct code xrefs to the raw start addresses below, but confirmed the constructor bytes and vtable data xrefs:

| Range | Class | Confirming bytes / behavior |
| --- | --- | --- |
| `0x0055a2a0-0x0055a2b3` | [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) | Prologue, `this` save, `mov [ecx], 0x006235c4`, returns `this`, then `align 10h`; vtable ref in range at `0x0055a2a9`. |
| `0x0055b000-0x0055b037` | [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md) | Calls `FilterEffecter` at `0x0055ad00`, then stores four cloud vtable views at `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`, ending at `retn` then alignment. |
| `0x0055b090-0x0055b0c7` | [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md) | Same constructor shape as cloud, but stores static-cloud vtables `0x00623b3c`, `0x00623b5c`, `0x00623ba8`, and `0x00623bd8`. |
| `0x0055b110-0x0055b151` | [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) | Stores vtable `0x00623be4`, reads `g_pTimerMgr->+0x18`, stores `m_lastShakeTick = currentTick - 0x3c` at `+0x10`, stores `m_xAmplitude`/`m_yAmplitude` short arguments at `+0x04/+0x06`, zeroes `m_currentXOffset` at `+0x0c` and `m_currentYOffset` at `+0x08`, and returns with `ret 8`; padding is `0x0055b151-0x0055b160`. |
| `0x0055b4a0-0x0055b4b3` | [UID:0000GD][YFlipEffecter](by-class/YFlipEffecter.md) | Minimal constructor stores vtable `0x00623c2c`, returns `this`, then aligns before the IDA-modeled body at `0x0055b4c0`. |
| `0x0055b810-0x0055b851` | [UID:000070][LakeEffecter](by-class/LakeEffecter.md) | Clamps the float argument with constants at `0x00623d40` and `0x00620c68`, stores vtable `0x00623cf8`, stores clamped blend/timer state, and returns with `retn 4`. |

Neighboring modeled functions remain intact: `sub_55A2C0` starts at `0x0055a2c0`, `nullsub_50` starts at `0x0055b040`, `sub_55B160` starts at `0x0055b160`, `sub_55B4C0` starts at `0x0055b4c0`, `sub_55B860` starts at `0x0055b860`, and `sub_55B870` starts at `0x0055b870`. That confirms these constructor islands are not accidental overlap with adjacent modeled functions.

2026-06-14 live IDA MCP refresh against database `a001_goal2_class_batch` reconfirms:

- `lookup_funcs` still reports no function object at raw constructor starts `0x0055a2a0`, `0x0055b000`, `0x0055b090`, `0x0055b110`, `0x0055b4a0`, and `0x0055b810`.
- Neighbor starts remain modeled and separate: `sub_55A2C0` size `0x07` / 7 (Verified with int_convert.py), `nullsub_50` size `0x03` / 3 (Verified with int_convert.py), `sub_55B160` size `0x133`, `sub_55B4C0` size `0x103`, `sub_55B860` size `0x07` / 7 (Verified with int_convert.py), and `sub_55B870` size `0x1b2`.
- `xrefs_to` on all six raw starts reports no direct xrefs, while vtable targets still point into the constructor bytes: `0x006235c4 -> 0x0055a2a9`, cloud views `0x00623a94/0x00623ab4/0x00623b00/0x00623b30 -> 0x0055b00f/0x0055b017/0x0055b01e/0x0055b028`, static-cloud views `0x00623b3c/0x00623b5c/0x00623ba8/0x00623bd8 -> 0x0055b09f/0x0055b0a7/0x0055b0ae/0x0055b0b8`, and single-primary stores `0x00623be4 -> 0x0055b114`, `0x00623c2c -> 0x0055b4a9`, `0x00623cf8 -> 0x0055b829`.
- `get_bytes` confirms constructor-shaped prologue/vtable-store/return bytes at each raw start and `0xcc` alignment after each island: `0x0055a2b3`, `0x0055b037`, `0x0055b0c7`, `0x0055b151`, `0x0055b4b3`, and `0x0055b851`.
- The Pixel/YFlip minimal constructors have 20-byte byte samples (`20 == 0x14`, Verified with int_convert.py); cloud/static-cloud samples cover 56 bytes (`56 == 0x38`, Verified with int_convert.py); Earthquake/Lake samples cover 66 bytes (`66 == 0x42`, Verified with int_convert.py) including the argument cleanup and first padding byte.
- B007 2026-06-19 Earthquake recheck adds the field-specific interpretation for `0x0055b110`: `+0x04/+0x06` are unsigned X/Y amplitudes, `+0x08/+0x0c` are current Y/X offsets, and `+0x10` is mutable `m_lastShakeTick` / `m_lastSampleTick`. A local PE scan found no rel32 call/jump/conditional branch and no VA/RVA/raw-offset pointer to `0x0055b110`; retain the no-route constructor caveat while documenting the source constructor shape.
- Existing exact support pages now cover StaticCloud [UID:0003O9][0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor](by-memory/0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor.md), YFlip constructor/apply [UID:0003OA][0x0055b4a0-0x0055b4b3.YFlipEffecterRawConstructor](by-memory/0x0055b4a0-0x0055b4b3.YFlipEffecterRawConstructor.md) / [UID:0003OB][0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect](by-memory/0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md), and Lake [UID:0003HA][0x0055b810-0x0055b851.LakeEffecterConstructor](by-memory/0x0055b810-0x0055b851.LakeEffecterConstructor.md).

## Reconstruction Guidance

- Keep these as reconstructable constructors in `render/Effects.cpp`.
- Keep the class docs honest: IDA currently lacks function records for the starts, but raw disassembly and vtable xrefs confirm the code identities.
- Use [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) as the vtable/layout authority.
- Treat absent direct xrefs to these tiny starts as an IDA database limitation or construction-through-thunk issue, not proof that the constructors are dead.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal output is now a comment-only support block. Current MCP confirms the six constructor-shaped raw islands at `0x0055a2a0`, `0x0055b000`, `0x0055b090`, `0x0055b110`, `0x0055b4a0`, and `0x0055b810`, but also confirms no IDA function objects for those starts and no direct xrefs to the checked raw starts. This page preserves byte/padding/vtable-store evidence and source placement under [UID:0000IZ][Effects](by-file/Effects.md); it must not emit duplicate constructor bodies. Declarations or exact bodies belong on the owning class/exact memory pages.

## Changes

- 2026-06-19 B007 EarthquakeEffecter support sync:
  - Score unchanged.
  - Summary/evidence: updated the Earthquake constructor row with resolved amplitude/current-offset/last-tick field names, constructor seed `g_pTimerMgr->+0x18 - 0x3c`, exact `ret 8`/padding, and no-route raw-constructor proof.
- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while owner/emitter routing and C++ remain under review.
- Summary and evidence: IDA MCP raw-disassembly verification on 2026-05-31 reconfirmed constructor-shaped bytes and absent IDA function records at the exact starts. The score remains below final audit because function-boundary modeling, caller paths, and final effecter class/source placement are not fully audited.
- 2026-06-03 update: live IDA MCP rechecked all six raw constructor islands, exact neighboring modeled functions, vtable-store xrefs, return cleanup, and absent direct code xrefs to the raw starts. Completion increased from 70 to 82 and confidence from 85 to 90 because the raw boundaries and `Effects` owner route are now documented from current IDA output without relying on old staging metadata. The score remains below final audit because IDA still lacks function objects at the raw starts and the direct construction call paths are not proven.
- 2026-06-14 A001: Raised completion from `82` to `85`; confidence remains `90`.
  - Before: the page had the correct six-island summary but no current post-child-split refresh, and it still used stale output-route and near-final wording.
  - After: the page records current owner/emitter terminology, score rationale, live IDA no-function/no-direct-xref checks, adjacent modeled starts, vtable-store xrefs, raw bytes and padding, and exact child support for StaticCloud, YFlip, and Lake.
  - Evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `get_bytes`, and `int_convert.py` checks.
