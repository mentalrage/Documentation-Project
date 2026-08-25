*** UID:0000IW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# DirectX

## Status

- Confidence: very strong for class responsibility, two-base ABI shape, complete CPP/H assembly, and file placement.
- Proposed module: `NexusTK/render/DirectX.cpp`
- Historical recovered source: `source-3/simroot_v2/class_DirectX.cpp`; it is incomplete generated evidence and no longer current source authority.
- Main address range: `0x004a1b60-0x004a1d6a`
- Primary vtable: [UID:0003HP][DirectXVtable](by-type/by-vtable/DirectXVtable.md), backed by exact data [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md)

## File Role

This module owns the client DirectDraw bootstrap wrapper. It creates the process-wide DirectDraw interface during application startup, exposes it through `g_pDirectX`, and releases the interface on shutdown. The class is intentionally small: it is infrastructure for render surfaces, not a surface or pane renderer itself.

`GrafPort` is the main confirmed consumer in this research batch. It reads the DirectDraw interface from `g_pDirectX` while creating RGB565 offscreen surfaces.

The broader presentation helpers are tracked in [UID:0000OC][Surface](by-file/Surface.md). Keep `DirectX` limited to DirectDraw object/interface lifetime; surface locks, blits, and presentation policy belong elsewhere.

B005's 2026-06-23 [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md) implementation supersedes the earlier Surface-owned wording while reinforcing the same DirectX boundary. `ScreenPane::RestoreDirectDrawState()` consumes `g_pDirectX->m_pDirectDraw` to call `IDirectDraw::RestoreDisplayMode()` and `IDirectDraw::SetCooperativeLevel(hwnd, DDSCL_NORMAL)`, but both direct callers pass `g_pScreenPane` and the body mutates ScreenPane bytes `+0x111/+0x110`; the exact method therefore belongs to [UID:0000CB][ScreenPane](by-class/ScreenPane.md), not `DirectX.cpp`. DirectX remains the singleton/interface dependency.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `DirectX` | `0x004a1b60-0x004a1d6a` | `LObject` plus empty `Singleton<DirectX>` wrapper, x86 size `0x08`, with public `LPDIRECTDRAW m_pDirectDraw` at `+0x04`. |
| `g_pDirectX` | `0x0067ab20` by IDA evidence | Sole semantic definition and explicit Singleton publication/clear specializations on [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md); exact storage UID000295 is covered-by only. |
| Out-of-line Singleton destructor specialization | `0x004a1cc0` | Source `Singleton<DirectX>::~Singleton()` body selected by constructor EH; not a standalone DirectX helper. |
| SDK `IID_IDirectDraw` | `0x00631570` by current evidence | Interface GUID passed to `QueryInterface`; this is the DirectDraw SDK IID, not a project-authored `kDirectDrawInterfaceId` or Browser-owned GUID. |

## Exact Support Pages

| Evidence page | Current score | Why it supports this file root |
| --- | ---: | --- |
| [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md) | `92/94` | Exact source methods, four local functions, four far groups, five padding spans, atomic caller/callee inventory, and compiler/source split. |
| [UID:00003Y][DirectX](by-class/DirectX.md) | `92/94` | Complete guarded H, CPP include/child channel, LObject/Singleton EBO layout, public field, ten RTTI objects, and ordered children. |
| [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) | `92/94` | Exact four-dword record, inherited slots, three atomic vptr stores, and compiler-covered class source cause. |
| [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md) | `92/94` | Sole definition, both explicit Singleton specializations, and all nineteen independent global xrefs. |

## Complete Source Assembly

`NexusTK/render/DirectX.cpp` is assembled through [UID:00003Y][DirectX](by-class/DirectX.md). Its CPP preamble includes `DirectX.h` and required complete-type dependency `../util/Error.h`, then emits four children in exact order: UID0000QS position `0`, UID000137 position `1`, UID0002MD position `2`, and UID0003AY position `3`.

`NexusTK/render/DirectX.h` is emitted by UID00003Y as one guarded declaration. It includes `../util/LObject.h`, `../util/Singleton.h`, and `<ddraw.h>`; declares direct bases `LObject` and `Singleton<DirectX>`; declares constructor and virtual destructor; exposes public `LPDIRECTDRAW m_pDirectDraw`; declares `extern DirectX *g_pDirectX`; and asserts `sizeof(DirectX) == 0x8` for the recovered x86 ABI.

The semantic global child emits the sole zero-initialized definition and explicit Singleton constructor/destructor specializations. UID000137 emits only the DirectX constructor and ordinary destructor. UID0002MD and UID0003AY emit covered-by comments; UID0003HP stays semantic/blank, and SDK UID0003OG stays external/blank.

## Exact Function And Boundary Inventory

| Claim | Half-open range / thunk | Role | Source disposition |
| --- | --- | --- | --- |
| `C0000IW-045` | `[0x004a1b60,0x004a1c56)` | DirectX constructor | Source body on UID000137. |
| `C0000IW-046` | `[0x004a1c60,0x004a1cbc)` | DirectX ordinary destructor | Source body on UID000137. |
| `C0000IW-047` | `[0x004a1cc0,0x004a1ccb)` | Out-of-line Singleton destructor specialization | Source body on UID0000QS; compiler EH placement. |
| `C0000IW-048` | `[0x004a1cd0,0x004a1d6a)` | DirectX scalar deleting destructor | Compiler-covered; no handwritten body. |
| `C0000IW-049` | `[0x005fd710,0x005fd750)` | Constructor EH/unwind | Compiler-covered. |
| `C0000IW-050` | `[0x005fd754,0x005fd76b)` | Destructor SEH/cookie/frame support | Compiler-covered. |
| `C0000IW-051` | `[0x005f6800,0x005f6817)` | Scalar-wrapper SEH/cookie/frame support | Compiler-covered. |
| `C0000IW-052` | `0x005c91f2` | Scalar-wrapper terminate thunk | Compiler-covered. |
| `C0000IW-053` | `[0x004a1b5e,0x004a1d70)` search window | Exactly four local functions; no fifth. | No extra source. |
| `C0000IW-054` | `[0x004a1b5e,0x004a1b60)` | 2-byte CC DIBitmap/constructor boundary | Padding, no source. |
| `C0000IW-055` | `[0x004a1c56,0x004a1c60)` | 10-byte CC constructor/destructor boundary | Padding, no source. |
| `C0000IW-056` | `[0x004a1cbc,0x004a1cc0)` | 4-byte CC destructor/specialization boundary | Padding, no source. |
| `C0000IW-057` | `[0x004a1ccb,0x004a1cd0)` | 5-byte CC specialization/scalar-wrapper boundary | Padding, no source. |
| `C0000IW-058` | `[0x004a1d6a,0x004a1d70)` | 6-byte CC scalar-wrapper/EmployeeDialog boundary | Padding, no source. |

## Exact Data And RTTI Inventory

| Claim | Half-open range | Item | Disposition |
| --- | --- | --- | --- |
| `C0000IW-006` | `[0x0067ab20,0x0067ab24)` | `g_pDirectX` physical storage | Covered by semantic UID0000QS definition. |
| `C0000IW-011` | `[0x00618e60,0x00618e70)` | DirectX COL pointer plus three-slot vtable | Compiler-generated from UID00003Y declaration. |
| `C0000IW-012` | `[0x00618e70,0x00618efc)` | Exact UTF-16 DirectX failure literal | Covered by two UID000137 throw expressions. |
| `C0000IW-013` | `[0x00631570,0x00631580)` | SDK `IID_IDirectDraw` | External SDK data. |
| `C0000IW-035` | `[0x0064681c,0x00646830)` | DirectX COL | Compiler-generated; links vtable prelude, TD, CHD. |
| `C0000IW-036` | `[0x00646830,0x00646840)` | DirectX CHD | Count `3`, BCA `0x00646840`. |
| `C0000IW-037` | `[0x00646840,0x00646850)` | DirectX BCA | DirectX, LObject, Singleton BCD entries. |
| `C0000IW-038` | `[0x00646850,0x0064686c)` | DirectX self BCD | PMD `{0,-1,0}`. |
| `C0000IW-039` | `[0x0064686c,0x00646888)` | Singleton base BCD | PMD `{+4,-1,0}`, TD `0x00675bf8`, CHD `0x00646888`. |
| `C0000IW-040` | `[0x00646888,0x00646898)` | Singleton CHD | Compiler-generated hierarchy support. |
| `C0000IW-041` | `[0x00646898,0x006468a0)` | Singleton BCA | Points to self BCD `0x006468a0`. |
| `C0000IW-042` | `[0x006468a0,0x006468bc)` | Singleton self BCD | PMD `{0,-1,0}`. |
| `C0000IW-043` | `[0x00675be0,0x00675bf8)` | DirectX type descriptor | Exact name `.?AVDirectX@@`. |
| `C0000IW-044` | `[0x00675bf8,0x00675c20)` | Singleton type descriptor | Exact name `.?AV?$Singleton@VDirectX@@@@`. |

## Exact Caller Callee And Xref Inventory

| Claim | Exact source -> target | Meaning |
| --- | --- | --- |
| `C0000IW-059` | `0x004645aa -> 0x004a1b60` | Sole constructor caller. |
| `C0000IW-060` | `0x004a1b8c -> 0x004f4a80` | LObject constructor. |
| `C0000IW-061` | `0x004a1bcb -> 0x005c5c87`, IAT `0x0060d024` | DirectDrawCreate. |
| `C0000IW-062` | `0x004a1be0 -> [IDirectDraw+0x00]` | QueryInterface. |
| `C0000IW-132` | `0x004a1be8 -> 0x004f4aa0` | QueryInterface-failure 8-byte allocation. |
| `C0000IW-134` | `0x004a1c02 -> 0x004a67a0` | QueryInterface-failure MyError construction. |
| `C0000IW-133` | `0x004a1c1e -> 0x004f4aa0` | DirectDrawCreate-failure 8-byte allocation. |
| `C0000IW-135` | `0x004a1c38 -> 0x004a67a0` | DirectDrawCreate-failure MyError construction. |
| `C0000IW-065` | `0x004a1c51 -> 0x005ca20a` | Converged throw helper. |
| `C0000IW-066` | `0x005fd713 -> 0x004f4a90` | Constructor far LObject cleanup. |
| `C0000IW-067` | `0x005fd71e -> 0x004a1cc0` | Constructor far Singleton cleanup. |
| `C0000IW-136` | `0x005fd727 -> 0x004f4ac0` | QueryInterface-allocation cleanup. |
| `C0000IW-137` | `0x005fd732 -> 0x004f4ac0` | DirectDrawCreate-allocation cleanup. |
| `C0000IW-069` | `0x004a1c91 -> [IDirectDraw+0x08]` | Ordinary destructor Release. |
| `C0000IW-070` | `0x004a1ca7 -> 0x004f4a90` | Ordinary destructor base teardown. |
| `C0000IW-071` | no direct caller; vtable route | Ordinary destructor virtual liveness. |
| `C0000IW-072` | `0x005fd71e -> 0x004a1cc0` | Sole Singleton destructor-specialization caller. |
| `C0000IW-073` | `0x00618e64 -> 0x004a1cd0` | Scalar wrapper vtable-only inbound route. |
| `C0000IW-074` | `0x004a1d08 -> [IDirectDraw+0x08]` | Scalar wrapper Release. |
| `C0000IW-075` | `0x004a1d1e -> 0x004f4a90` | Scalar wrapper base teardown. |
| `C0000IW-076` | `0x004a1d2f -> 0x004f4ac0` | Scalar wrapper optional delete. |
| `C0000IW-077` | `0x004a1d4e -> 0x0041b6a0` | Scalar-wrapper flag-4 guard path. |
| `C0000IW-078` | `0x005c91f2 -> 0x005dce60` | Scalar-wrapper terminate thunk. |
| `C0000IW-079` | `0x00464b44 -> 0x0067ab20` | Application shutdown read. |
| `C0000IW-080` | `0x004a1ba2 -> 0x0067ab20` | Complete-object publication write. |
| `C0000IW-081` | `0x004a1ba9 -> 0x0067ab20` | Null-adjustment publication write. |
| `C0000IW-082` | `0x004a1c9d -> 0x0067ab20` | Ordinary destruction clear. |
| `C0000IW-083` | `0x004a1cc0 -> 0x0067ab20` | Out-of-line Singleton clear. |
| `C0000IW-084` | `0x004a1d14 -> 0x0067ab20` | Scalar-deletion clear. |
| `C0000IW-085` | `0x004b8d78 -> 0x0067ab20` | Render/UI consumer read. |
| `C0000IW-086` | `0x004b92bc -> 0x0067ab20` | Render/UI consumer read. |
| `C0000IW-087` | `0x004b9800 -> 0x0067ab20` | Render/UI consumer read. |
| `C0000IW-088` | `0x004bb83f -> 0x0067ab20` | Render/UI consumer read. |
| `C0000IW-089` | `0x00556b22 -> 0x0067ab20` | ScreenPane destructor read. |
| `C0000IW-090` | `0x00556b77 -> 0x0067ab20` | Second ScreenPane destructor read. |
| `C0000IW-091` | `0x005574a0 -> 0x0067ab20` | Surface/GrafPort-family read. |
| `C0000IW-092` | `0x005576d0 -> 0x0067ab20` | Surface/GrafPort-family read. |
| `C0000IW-093` | `0x005583d0 -> 0x0067ab20` | DirectDraw consumer read. |
| `C0000IW-094` | `0x005586a3 -> 0x0067ab20` | InitializeSurfaceRenderCallbacks read. |
| `C0000IW-095` | `0x00558875 -> 0x0067ab20` | DirectDraw consumer read. |
| `C0000IW-096` | `0x00558b24 -> 0x0067ab20` | Second read in the `0x00558840` consumer. |
| `C0000IW-097` | `0x00559a63 -> 0x0067ab20` | Final exact DirectDraw consumer read; total nineteen. |
| `C0000IW-098` | `0x004a1bbf -> 0x00618e64` | Constructor vptr store. |
| `C0000IW-099` | `0x004a1c88 -> 0x00618e64` | Ordinary destructor vptr store. |
| `C0000IW-100` | `0x004a1cf8 -> 0x00618e64` | Scalar wrapper vptr store. |
| `C0000IW-101` | `0x004a1bfb -> 0x00618e70` | QueryInterface-failure literal xref. |
| `C0000IW-102` | `0x004a1c31 -> 0x00618e70` | DirectDrawCreate-failure literal xref. |
| `C0000IW-103` | `0x004a1bd8 -> 0x00631570` | Sole SDK IID use feeding QueryInterface. |

## Ownership Decision

Keep this as a separate render infrastructure file. It is too small to be a broad rendering module, but merging it into `GrafPort.cpp` would obscure the startup-level lifetime boundary: application startup constructs `DirectX`, then many UI/render classes consume the singleton later.

The exact `DirectX` vtable data is now split at [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md). IDA MCP confirms the RTTI/vtable record ends before the adjacent DirectX diagnostic string data at `0x00618e70`.

Do not treat generated text-measurement uses of `g_pDirectX` as evidence that DirectX owns font behavior. IDA shows some of those sites actually load [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) at `0x0067ab24`, immediately after `g_pDirectX` at `0x0067ab20`. That is tracked as a Wave3 data issue.

## Source-Quality Notes

B014's 2026-06-19 reanalysis keeps this source file root but routes [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md) through the [UID:00003Y][DirectX](by-class/DirectX.md) class page for direct semantic ownership. The final generated path remains `NexusTK/render/DirectX.cpp`.

The source-authored DirectX code expresses the complete two-base declaration, sole global definition, explicit Singleton publication/clear specializations, constructor, ordinary virtual destructor, SDK `IID_IDirectDraw`, and pointer-thrown `MyError` failure paths. It does not hand-author the SDK GUID, scalar deleting destructor, vtable/RTTI data, base mechanics, far EH, or padding. The stored interface field is public `LPDIRECTDRAW m_pDirectDraw`; older `m_directDraw` wording is only a semantic alias.

B009's 2026-07-04 physical-child source-ready conclusion is retained as historical evidence but superseded for ODR allocation. UID0000QS now owns the definition and specializations; UID000295 is covered-by only. Surface, GrafPort, ScreenPane, raw Surface copy helpers, and Application startup/shutdown remain consumers/policy owners rather than DirectX source owners.

## Dependency And Error Support Closure

External dependencies are DirectDrawCreate through IAT `0x0060d024`, COM QueryInterface/Release, SDK `IID_IDirectDraw`, `LObject`, shared storage-free `Singleton<T>`, and runtime allocation/throw/delete/EH support. They are included/called, not imported as reconstructed bodies. No third-party source import directive or resource child belongs to this module.

Both `new MyError` expressions require a complete type, so `DirectX.cpp` includes `../util/Error.h`. The accepted associated support route is self-contained under `NexusTK/util/Error.cpp` plus `Error.h`:

| Function/range | Owner | Exact source disposition |
| --- | --- | --- |
| `[0x004a67a0,0x004a683d)` `MyError::MyError` | UID0002HO | Preserve exact constructor CPP using `new wchar_t[length + 1]`, `wcsncpy_s`, and explicit terminator; H blank. |
| `[0x004a6840,0x004a6858)` `MyError::FormatErrorMessage` | UID00008V | Exact integer-returning `wcscpy_s` CPP method. |
| `[0x004a6860,0x004a6882)` `MyError::~MyError` | UID00008V | Exact ordinary destructor CPP with `delete [] m_messageText`. |
| `[0x004a68e0,0x004a691e)` Error scalar deleting destructor | UID00004J H source cause | Compiler-generated from inline empty virtual `Error::~Error()`; exact 62-byte SHA256 `E8144E5BF8ADF60BD3FE8347E1B3871E3029191871D04A6AFE3B2B4C8BF00B2F`; no duplicate CPP. |
| `0x004a6a10` MyError scalar deleting destructor | UID00008V ordinary destructor source cause | Compiler-generated; no duplicate CPP. |
| `[0x004a6a70,0x004a6a76)` `Error::GetErrorName` | UID00004J | Exact CPP returns `L"Error"`. |

UID00004J owns the single guarded Error/MyError H declaration, inline Error destructor, pure virtual integer-returning wide formatter, GetErrorName, heap-message field, and x86 size assertions `Error == 0x4` / `MyError == 0x8`. UID00008V and UID0002HO H channels stay blank to prevent duplicate declarations. Broader unrelated Error siblings retain existing owners and do not block this DirectX compile-support closure.

## Rejected And Historical Alternatives

- The historical one-base class shell, private field, and manual `g_pDirectX` writes are superseded by RTTI PMDs, EBO, cross-module direct access, and Singleton specializations.
- Generic Singleton storage, class-static storage, a getter/friend family, and physical-child duplicate definition are rejected for lack of evidence and ODR conflict.
- Application, Surface, GrafPort, ScreenPane, DIBitmap, EmployeeDialog, and adjacent mixed-data pages are policy/consumer/boundary evidence, not DirectX owners.
- Raw vtable/RTTI arrays, standalone diagnostic data, a project-authored GUID, resource ownership, and third-party source import are rejected; compiler or SDK source causes are complete.
- No fifth local function, local `lpDD` release, destructor null guard, by-value `MyError`, or separate handwritten deleting/EH wrapper is invented.
- `m_directDraw`, exact guard token, and alternate access labels remain historical/inferred spellings; `m_pDirectDraw` and public access are the least-invented accepted source.

## Generated Source Audit

Historical validator command `000000023186` produced incomplete output: DirectX.h was absent, bases/access/includes were wrong or missing, methods manually wrote the global, and compiler/data children were empty markers. The accepted ordinary-document repair supplies complete formal CPP/H and nonempty coverage markers. Final generated `DirectX.cpp`, `DirectX.h`, and associated `util/Error.h` must be physically compared with these inventories after the coherent validator refresh; generated files remain validator-owned and are never edited manually.

## Parent-Gate Readiness

This file page and direct class root are both `92/94`. Completion is `92` because the source pair, class/global/method/data child order, complete formal H dependency closure, exact local/far/padding/data/RTTI inventories, atomic caller/callee/xrefs, ownership exclusions, generated prestate, and associated Error/MyError source/compiler dispositions are closed. Confidence is `94` because fresh accepted IDA evidence, project Singleton precedent, direct consumers, formal source, and generated-route design agree; no PDB proves exact original token/access/guard spelling, so the score remains below 95.

## Cross-References

- [UID:00003Y][DirectX](by-class/DirectX.md)
- [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md)
- [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md)
- [UID:0003HP][DirectXVtable](by-type/by-vtable/DirectXVtable.md)
- [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md)
- [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-08-14 B004 accepted UID0000IW whole-file implementation:
  - Raised `85/88` to `92/94`; retained `NexusTK/render/` and file ownership.
  - Added complete CPP/H assembly, LObject/Singleton EBO/public-field ABI, semantic global/specializations, exact child order, exhaustive four-local/four-far/five-padding/ten-RTTI/data inventories, and every independent caller/callee/global/vtable/literal/GUID xref.
  - Preserved and historicalized rejected one-base/manual-global/private-field/physical-child/consumer/raw-data alternatives, recorded the incomplete generated command `000000023186` prestate, and closed the `../util/Error.h` dependency with exact Error/MyError declarations, source methods, constructor identity, and two compiler-wrapper no-code dispositions.

- 2026-07-04 B009 UID000295 source-ready singleton route:
  - Score unchanged at `85/88`.
  - Recorded that exact child [UID:000295][0x0067ab20-0x0067ab24.g_pDirectX](by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md) now carries the single `DirectX *g_pDirectX = NULL;` definition through [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md). Generated `DirectX.cpp` should contain that definition before DirectX constructor/destructor output and must not duplicate it.

- 2026-06-23 B005 SurfaceDirectDrawRestoreMaintenance dependency sync:
  - Score unchanged at `85/88`.
  - Replaced stale Surface-owned wording for [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md) with the accepted ScreenPane route: `ScreenPane::RestoreDirectDrawState()` uses `g_pDirectX->m_pDirectDraw`, `IDirectDraw::RestoreDisplayMode`, and `IDirectDraw::SetCooperativeLevel`, but DirectX is only the dependency owner.

- 2026-06-20 B002 SurfaceDirectDrawRestoreMaintenance dependency sync:
  - Score unchanged at `85/88`.
  - Superseded by the B005 2026-06-23 reroute above. This entry originally recorded [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md) as a `g_pDirectX`/DirectDraw consumer that remained Surface-owned before the ScreenPane receiver/field evidence was resolved.
- 2026-06-19 B014 source-quality incorporation:
  - Replaced unresolved `kDirectDrawInterfaceId` wording with SDK `IID_IDirectDraw`, updated [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md) support score to `88/91`, and documented class-owned emission through [UID:00003Y][DirectX](by-class/DirectX.md) while preserving this file as `NexusTK/render/DirectX.cpp`.
  - Added source-quality notes for `m_pDirectDraw`, pointer-thrown `MyError`, ordinary destructor C++ readiness, and compiler-glue exclusion for the constructor-unwind helper, scalar deleting destructor, vtable/base mechanics, far EH chunks, and padding.
- 2026-06-07 A003 Batch 084 parent-gate update:
  - Changed to: `COMPLETION:85`; confidence remains `88`.
  - Summary/evidence: added exact support-page table and parent-gate rationale for using this file as the direct owner of [UID:00003Y][DirectX](by-class/DirectX.md). The raised completion is justified by [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md), the exact vtable child, `g_pDirectX`, startup construction, DirectDraw/surface consumer boundary, and documented exclusion of font/surface ownership.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:88`.
  - Summary/evidence: DirectDraw bootstrap role, singleton/global lifetime, unwind helper, consumer boundary, and non-ownership of surface/font behavior are documented; confidence is strong because class responsibility and file placement are well supported.
- 2026-05-31 projected path and vtable child:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page referenced only the combined DIBitmap/DirectX vtable type page.
  - Changed to: proposed path `NexusTK/render/` and exact `DirectX` vtable-data child reference.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places `DirectX.cpp` under `render/`; IDA MCP confirms the exact `DirectX` vtable bytes and adjacent string boundary.
- 2026-06-12 A004 Batch 317 cross-reference update: added [UID:0003HP][DirectXVtable](by-type/by-vtable/DirectXVtable.md) as the class-owned source-local vtable page. Scores stay `85/88`; the file remains source context while the vtable routes first to [UID:00003Y][DirectX](by-class/DirectX.md).
