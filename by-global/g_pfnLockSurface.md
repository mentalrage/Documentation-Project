*** UID:0000QW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pfnLockSurface

## Status

- Symbol kind: generated alias for a render callback-table slot.
- Backing storage: `0x0069b3fc` / `dword_69B3FC`.
- Likely source module: [UID:0000OC][Surface](by-file/Surface.md).
- Related global: [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md).
- Confidence: strong for address/alias relationship, medium for final slot name and signature.

## Role

`g_pfnLockSurface` is a generated name currently emitted from `class_EPFImageControlPane.cpp`, but IDA MCP shows the call is really through [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `dword_69B3FC` at `0x0069b3fc`.

The name should be treated as a callsite-biased alias, not as an `EPFImageControlPane`-owned global. The slot is used broadly by pane paint/fill/presentation paths and is initialized by the surface render-family setup at `0x00558840`.

## Signature Caveat

Current `simroot_v2` generated source simplifies the EPF control call as:

```cpp
g_pfnLockSurface(drawSurface);
```

IDA decompilation of `0x00499310` shows the actual call shape as:

```cpp
dword_69B3FC(this, this + 68);
```

So the current one-argument generated signature is suspect. A safer provisional type is a two-argument render/pane callback taking an owner or pane pointer and a surface/rectangle/state pointer. Final naming should wait for a broader signature pass across the 206 IDA xrefs to `dword_69B3FC`.

## Evidence

- IDA MCP `lookup_funcs` reports `0x0069b3fc` is not a function, matching global function-pointer storage.
- IDA MCP decompilation of `EPFImageControlPane::LoadAndRenderImage` at `0x00499310` calls `dword_69B3FC(this, this + 68)` before the EPF frame load, then calls `dword_69B3E8` for the actual image blit.
- IDA MCP decompilation of the surface initializer at `0x00558840` assigns `dword_69B3FC` to either `0x004be680` or `0x004c4380` based on the active surface format family.
- The same callback slot appears in list, mail, map-tile, and pane paint paths, so ownership belongs with shared render infrastructure.
- 2026-05-31 IDA MCP `py_eval` recheck confirms `0x0069b3fc` is a 4-byte `.data` callback-table slot named `dword_69B3FC`, initialized to `0xffffffff`, with 206 data xrefs. The only direct writes found are initialization/reset writes at `0x00558770`, `0x00558bc6`, and `0x00558ee2`; the latter two assign `sub_4BE680` or `sub_4C4380` from the surface initializer.

## Ownership Decision

Keep this alias documented under [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) and [UID:0000OC][Surface](by-file/Surface.md). Do not treat `class_EPFImageControlPane.cpp` as the owner of the storage or final function-pointer type.

## Cross-References

- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md)
- [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md)
- [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- [UID:00011J][0x004991f0-0x0049b24f.EPFImageControlPane](by-memory/0x004991f0-0x0049b24f.EPFImageControlPane.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-05-31 reconstruction classification:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and coverage listed this alias under reconstructable rows.
  - Changed to: `COMPLETION:72`, `CONFIDENCE:84`, `RECONSTRUCTABLE:FALSE`, and coverage treats it as an ignored/generated alias.
  - Summary/evidence: IDA MCP confirms the address is a slot inside [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md), not a standalone EPFImageControlPane-owned source global. Reconstruction should model the callback table and surface initializer, not emit a separate `g_pfnLockSurface` global.
