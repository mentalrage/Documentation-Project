*** UID:0000IW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# DirectX

## Status

- Confidence: strong for class responsibility and file placement.
- Proposed module: `NexusTK/render/DirectX.cpp`
- Current recovered source: `source-3/simroot_v2/class_DirectX.cpp`
- Main address range: `0x004a1b60-0x004a1d6a`
- Primary vtable: [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md), summarized by [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)

## File Role

This module owns the client DirectDraw bootstrap wrapper. It creates the process-wide DirectDraw interface during application startup, exposes it through `g_pDirectX`, and releases the interface on shutdown. The class is intentionally small: it is infrastructure for render surfaces, not a surface or pane renderer itself.

`GrafPort` is the main confirmed consumer in this research batch. It reads the DirectDraw interface from `g_pDirectX` while creating RGB565 offscreen surfaces.

The broader presentation helpers are tracked in [UID:0000OC][Surface](by-file/Surface.md). Keep `DirectX` limited to DirectDraw object/interface lifetime; surface locks, blits, and presentation policy belong elsewhere.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `DirectX` | `0x004a1b60-0x004a1d6a` | Singleton wrapper around the DirectDraw interface. |
| `g_pDirectX` | `0x0067ab20` by IDA evidence | Global pointer installed by `DirectX::DirectX` and cleared by `~DirectX`. See [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md). |
| Constructor-unwind singleton clear helper | `0x004a1cc0` | Tiny helper that clears `g_pDirectX` if constructor setup unwinds. |
| `kDirectDrawInterfaceId` | unresolved data | Interface GUID passed to `QueryInterface`; keep with DirectX once the data symbol is recovered. |

## Ownership Decision

Keep this as a separate render infrastructure file. It is too small to be a broad rendering module, but merging it into `GrafPort.cpp` would obscure the startup-level lifetime boundary: application startup constructs `DirectX`, then many UI/render classes consume the singleton later.

The exact `DirectX` vtable data is now split at [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md). IDA MCP confirms the RTTI/vtable record ends before the adjacent DirectX diagnostic string data at `0x00618e70`.

Do not treat generated text-measurement uses of `g_pDirectX` as evidence that DirectX owns font behavior. IDA shows some of those sites actually load [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) at `0x0067ab24`, immediately after `g_pDirectX` at `0x0067ab20`. That is tracked as a Wave3 data issue.

## Cross-References

- [UID:00003Y][DirectX](by-class/DirectX.md)
- [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md)
- [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md)
- [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md)
- [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:88`.
  - Summary/evidence: DirectDraw bootstrap role, singleton/global lifetime, unwind helper, consumer boundary, and non-ownership of surface/font behavior are documented; confidence is strong because class responsibility and file placement are well supported.
- 2026-05-31 projected path and vtable child:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page referenced only the combined DIBitmap/DirectX vtable type page.
  - Changed to: proposed path `NexusTK/render/` and exact `DirectX` vtable-data child reference.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places `DirectX.cpp` under `render/`; IDA MCP confirms the exact `DirectX` vtable bytes and adjacent string boundary.
