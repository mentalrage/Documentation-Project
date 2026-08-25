*** UID:0000QS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003Y | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DirectX *g_pDirectX = NULL;

template <>
Singleton<DirectX>::Singleton()
{
    g_pDirectX = static_cast<DirectX *>(this);
}

template <>
Singleton<DirectX>::~Singleton()
{
    g_pDirectX = NULL;
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pDirectX

## Status

- Symbol kind: process-wide singleton pointer / global data.
- IDA address: `0x0067ab20` (`dword_67AB20`).
- Proposed type: `DirectX*`.
- Proposed owner module: [UID:0000IW][DirectX](by-file/DirectX.md).
- Confidence: very strong for storage, type, owner module, and source-ready child route.

## Role

`g_pDirectX` exposes the client DirectDraw bootstrap object after application startup constructs [UID:00003Y][DirectX](by-class/DirectX.md). Render and presentation code load this pointer when they need the stored DirectDraw interface, especially while creating or managing DirectDraw surfaces.

B009's 2026-07-04 physical-child definition is retained as historical evidence but superseded for one-definition ownership. This semantic page now emits exactly three independent source actions: the sole `DirectX *g_pDirectX = NULL;` definition, the explicit `Singleton<DirectX>` constructor specialization that publishes `static_cast<DirectX *>(this)`, and the explicit destructor specialization that clears the pointer. Exact storage child [UID:000295][0x0067ab20-0x0067ab24.g_pDirectX](by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md) is marker-only. This page emits through [UID:00003Y][DirectX](by-class/DirectX.md) at position `0`, before DirectX method bodies.

B005's 2026-06-23 [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md) implementation names this global as the DirectDraw wrapper dependency for `ScreenPane::RestoreDirectDrawState()`. The method reads `g_pDirectX->m_pDirectDraw` for `IDirectDraw::RestoreDisplayMode()` and `IDirectDraw::SetCooperativeLevel(hwnd, DDSCL_NORMAL)`, but its receiver, callers, and flags are ScreenPane-owned; this is consumer evidence only and does not move the method into `DirectX.cpp` or move this global out of [UID:0000IW][DirectX](by-file/DirectX.md).

This is not a font or text-layout singleton. Some UI text call sites currently use the `g_pDirectX` name, but IDA shows those specific sites load adjacent [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) at `0x0067ab24`. Keep that alias issue separate from this global.

## Lifetime Evidence

- The source constructor specialization publishes the complete object from the empty Singleton subobject. Compiler lowering produces the non-null adjusted write at `0x004a1ba2` and null-adjustment branch at `0x004a1ba9`.
- The source destructor specialization clears the pointer. It is inlined in ordinary destruction at `0x004a1c9d`, emitted out of line at `0x004a1cc0` for constructor unwind, and inlined in scalar deletion at `0x004a1d14`.
- B009 MCP session `ddf5b602` on 2026-07-04 rechecked the exact storage child. `lookup_funcs` reports `Not a function` for `0x0067ab18`, `0x0067ab1c`, `0x0067ab20`, and `0x0067ab24`; `get_bytes` and `get_global_value` report `00 00 00 00` / `0x0` for `0x0067ab20`; `xrefs_to` reports exactly 19 xrefs with `more:false`; `find_bytes` reports 19 matches for VA operand pattern `20 AB 67 00` and zero matches for RVA pattern `20 AB 27 00`.
- B009 representative consumer checks preserve the consumer boundary: application cleanup reads the global at `0x00464b44`, `ScreenPane::RestoreDirectDrawState()` reads it at `0x005576d0` and uses `[g_pDirectX + 4]` for DirectDraw calls, and raw Surface copy helper `0x00559a10` reads it at `0x00559a63`. These are dependency uses, not ownership transfers.

## Exact Xref Inventory

The current global query returns exactly nineteen rows with no continuation. Each route is independently checkable; no aggregate "all xrefs" claim carries authority.

| Claim | Source -> target | Exact disposition |
| --- | --- | --- |
| `C0000IW-079` | `0x00464b44 -> 0x0067ab20` | Application shutdown read. |
| `C0000IW-080` | `0x004a1ba2 -> 0x0067ab20` | Complete-object publication write from the non-null Singleton base path. |
| `C0000IW-081` | `0x004a1ba9 -> 0x0067ab20` | Null write on the null-adjustment publication branch. |
| `C0000IW-082` | `0x004a1c9d -> 0x0067ab20` | Ordinary destruction clear. |
| `C0000IW-083` | `0x004a1cc0 -> 0x0067ab20` | Out-of-line Singleton destructor-specialization clear. |
| `C0000IW-084` | `0x004a1d14 -> 0x0067ab20` | Compiler-generated scalar-deletion clear. |
| `C0000IW-085` | `0x004b8d78 -> 0x0067ab20` | Independent render/UI consumer read. |
| `C0000IW-086` | `0x004b92bc -> 0x0067ab20` | Independent render/UI consumer read. |
| `C0000IW-087` | `0x004b9800 -> 0x0067ab20` | Independent render/UI consumer read. |
| `C0000IW-088` | `0x004bb83f -> 0x0067ab20` | Independent render/UI consumer read. |
| `C0000IW-089` | `0x00556b22 -> 0x0067ab20` | ScreenPane destructor consumer read. |
| `C0000IW-090` | `0x00556b77 -> 0x0067ab20` | Second ScreenPane destructor consumer read. |
| `C0000IW-091` | `0x005574a0 -> 0x0067ab20` | Surface/GrafPort-family consumer read. |
| `C0000IW-092` | `0x005576d0 -> 0x0067ab20` | Surface/GrafPort-family consumer read used by ScreenPane DirectDraw restore. |
| `C0000IW-093` | `0x005583d0 -> 0x0067ab20` | Independent DirectDraw consumer read. |
| `C0000IW-094` | `0x005586a3 -> 0x0067ab20` | `InitializeSurfaceRenderCallbacks` consumer read. |
| `C0000IW-095` | `0x00558875 -> 0x0067ab20` | Independent DirectDraw consumer read. |
| `C0000IW-096` | `0x00558b24 -> 0x0067ab20` | Second read in the `0x00558840` DirectDraw consumer. |
| `C0000IW-097` | `0x00559a63 -> 0x0067ab20` | Final exact DirectDraw consumer read. |

## Ownership Decision

Keep this global with `render/DirectX.cpp`. It is installed and cleared by `DirectX` lifetime code and then consumed by other render modules. `GrafPort`, `Surface`, screenshot presentation, and UI panes should reference it as a dependency, not own the declaration.

This semantic page carries the source definition and both template specializations. `EMITTER_UIDS:00003Y` plus position `0` orders it before the DirectX method child. The complete `DirectX.h` block on UID00003Y supplies the single `extern DirectX *g_pDirectX` declaration. UID000295 retains exact storage/xref evidence but emits only a covered-by marker.

B014 correctly observed publication before the throwing DirectDraw setup calls. The accepted source-cause reanalysis classifies `0x004a1cc0` more precisely as the out-of-line `Singleton<DirectX>::~Singleton()` specialization selected by compiler EH. Ordinary and scalar destruction inline the same source specialization. Manual `g_pDirectX` writes inside `DirectX` methods, a generic Singleton storage cell, a class-static member, a getter/friend facade, and physical-child duplicate definition are rejected.

## Score Rationale

- Completion is `92` because the page now owns the exact global definition, constructor specialization, destructor specialization, class-position-zero emitter route, nineteen atomic xrefs, complete-object pointer adjustment, and one-definition/extern/covered-storage policy.
- Confidence is `94` because RTTI PMD `+0x04`, constructor/destructor lowering, the exact out-of-line body, zero-initialized storage, complete xref query, shared Singleton policy, and cross-module consumers all agree. Original template-token spelling remains the only bounded non-PDB uncertainty.

## Cross-References

- [UID:0000IW][DirectX](by-file/DirectX.md)
- [UID:00003Y][DirectX](by-class/DirectX.md)
- [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md)
- [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-08-14 B004 accepted UID0000IW whole-file implementation:
  - Raised `90/90` to `92/94`, changed the emitter from UID0000IW to class UID00003Y at position `0`, and installed the sole global definition plus independent constructor/destructor specializations in the formal CPP channel.
  - Added all nineteen xrefs as one-to-one rows and superseded manual DirectX-method writes, pure-helper classification, generic/class-static storage, and physical-child definition with the storage-free Singleton source cause.

- 2026-07-04 B009 UID000295 source-ready route:
  - Score raised from `88/86` to `90/90`; owner/emitter/reconstructable remain [UID:0000IW][DirectX](by-file/DirectX.md), [UID:0000IW][DirectX](by-file/DirectX.md), and `TRUE`.
  - Added `EMITTER_POSITION_OPTIONAL:0` and formal `[[CHILDREN]]` so exact child [UID:000295][0x0067ab20-0x0067ab24.g_pDirectX](by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md) emits the single `DirectX *g_pDirectX = NULL;` definition before DirectX constructor/destructor bodies in `NexusTK/render/DirectX.cpp`.
  - Evidence: B009 MCP session `ddf5b602` confirms zero bytes/value, no function at adjacent data slots, exactly 19 xrefs, 19 VA operand hits with zero RVA hits, DirectX lifetime writer/clear sites, and render/surface consumers. This page remains semantic parent/order route and does not duplicate the child definition.

- 2026-06-23 B005 SurfaceDirectDrawRestoreMaintenance dependency sync: replaced stale Surface-owned wording for [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md) with the accepted ScreenPane route. The method remains a `g_pDirectX` consumer, but the exact owner/emitter is [UID:0000CB][ScreenPane](by-class/ScreenPane.md); scores stay `88/86`.
- 2026-06-20 B002 SurfaceDirectDrawRestoreMaintenance dependency sync, superseded by the 2026-06-23 B005 reroute: recorded [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md) as a Surface-owned consumer of `g_pDirectX`.
- 2026-06-19 B014 source-quality incorporation: added constructor-unwind interpretation, pointer-throw context, virtual-destructor cleanup relationship, and consumer-versus-owner clarification. Scores stay `88/86`.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/86`. Summary/evidence: the page documents address, proposed type/owner, DirectDraw role, lifetime writes/clears, render/surface consumers, alias warning, and file/class/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000IW][DirectX](by-file/DirectX.md). Evidence: live IDA MCP reports 19 xrefs to `0x0067ab20`; decompilation confirms `0x004a1b60` writes `dword_67AB20`, `0x004a1c60` and `0x004a1cc0` clear it, and `0x004a1cd0` clears it in the deleting destructor path.
