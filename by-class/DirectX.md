*** UID:00003Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "DirectX.h"
#include "../util/Error.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_RENDER_DIRECTX_H
#define NEXUSTK_RENDER_DIRECTX_H

#include "../util/LObject.h"
#include "../util/Singleton.h"
#include <ddraw.h>

class DirectX : public LObject, public Singleton<DirectX>
{
public:
    DirectX();
    virtual ~DirectX();

    LPDIRECTDRAW m_pDirectDraw;
};

extern DirectX *g_pDirectX;

typedef char DirectXSizeMustBe0x8[
    sizeof(DirectX) == 0x8 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DirectX

## Status

- Confidence: very strong for the exact inheritance graph, x86 layout, virtual surface, source ownership, and ordered CPP/H assembly; original token spelling remains the bounded non-PDB uncertainty.
- Likely source file: [UID:0000IW][DirectX](by-file/DirectX.md)
- Address range: [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md)
- Historical recovered file: `source-3/simroot_v2/class_DirectX.cpp`; it is incomplete generated evidence rather than current source authority.
- Primary vtable: [UID:0003HP][DirectXVtable](by-type/by-vtable/DirectXVtable.md), backed by exact data [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) and split from aggregate [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- Direct autogen parent: [UID:0000IW][DirectX](by-file/DirectX.md)
- Source-quality note: B014 reanalysis keeps the file route but uses this class as the direct semantic emitter for [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md).

## Class Purpose

`DirectX` is the client DirectDraw bootstrap object. It creates a DirectDraw object, queries the interface used by the rest of the renderer, stores that interface in the object, and exposes the object through `g_pDirectX`.

This is not the renderer core. It is a lifetime/COM wrapper used by surface-management code such as `GrafPort`.

The class has two direct bases in source order: `LObject` at `+0x00` and storage-free `Singleton<DirectX>` at PMD `+0x04`. Empty-base optimization overlaps the Singleton subobject with `m_pDirectDraw` at `+0x04`, giving an x86 object size of `0x08`. The explicit `DirectXSizeMustBe0x8` assertion preserves that recovered ABI fact without hand-authoring padding.

B009's 2026-07-04 physical-storage interpretation is retained as history but superseded for source allocation. Semantic child [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md) now emits the sole module-global definition plus the explicit `Singleton<DirectX>` constructor/destructor specializations; exact storage child [UID:000295][0x0067ab20-0x0067ab24.g_pDirectX](by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md) is marker-only to prevent a duplicate definition. This class page remains the object layout/method owner; the singleton is not a `DirectX::s_*` class-static member.

## Observed State

```text
0x00  LObject base / primary vtable slot
0x04  empty Singleton<DirectX> base subobject
0x04  public LPDIRECTDRAW m_pDirectDraw (EBO overlap)
0x08  exclusive end / sizeof(DirectX)
```

`m_pDirectDraw` is public in the accepted reconstruction. Surface, GrafPort, ScreenPane, and other unrelated modules access the field directly; no getter or finite friend family is evidenced. Making it private would require invented API or friend declarations.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DirectX::DirectX` | `0x004a1b60-0x004a1c56` | Sets `g_pDirectX`, calls `DirectDrawCreate`, queries SDK `IID_IDirectDraw` into `m_pDirectDraw`, and pointer-throws `MyError` on setup failure. |
| `DirectX::~DirectX` | `0x004a1c60-0x004a1cbc` | Unconditionally releases `m_pDirectDraw`, clears the field and `g_pDirectX`, and destroys `LObject`. |
| Out-of-line `Singleton<DirectX>::~Singleton` specialization | `0x004a1cc0-0x004a1ccb` | Source specialization body placed on the constructor EH path; clears `g_pDirectX` and is not a standalone DirectX method. |
| Scalar deleting destructor wrapper | `0x004a1cd0-0x004a1d6a` | MSVC deleting-destructor wrapper emitted from `virtual ~DirectX()`; not handwritten source. |

## Ordered Child Assembly

The CPP block closes its include preamble before `[[CHILDREN]]`. The class-owned source order is exact and independently allocated:

| Position | Child | Purpose | Claim |
| ---: | --- | --- | --- |
| `0` | [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md) | Sole global definition and both `Singleton<DirectX>` specializations. | `C0000IW-138` |
| `1` | [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md) | Source constructor and ordinary destructor. | `C0000IW-140` |
| `2` | [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) | Compiler-generated vtable/RTTI covered-by marker. | `C0000IW-142` |
| `3` | [UID:0003AY][0x00618e70-0x00618efc.DirectXDiagnosticString](by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md) | Constructor-literal covered-by marker. | `C0000IW-144` |

## Exact RTTI Inventory

Each item below is compiler-generated from the complete H declaration; none receives a hand-authored data object.

| Claim | Half-open range | Object and exact evidence |
| --- | --- | --- |
| `C0000IW-035` | `[0x0064681c,0x00646830)` | DirectX complete-object locator linking vtable prelude `0x00618e60`, type descriptor `0x00675be0`, and CHD `0x00646830`. |
| `C0000IW-036` | `[0x00646830,0x00646840)` | DirectX CHD with base count `3` and BCA `0x00646840`. |
| `C0000IW-037` | `[0x00646840,0x00646850)` | DirectX BCA entries: DirectX BCD `0x00646850`, existing LObject BCD `0x00640348`, Singleton BCD `0x0064686c`. |
| `C0000IW-038` | `[0x00646850,0x0064686c)` | DirectX self BCD with PMD `{0,-1,0}`. |
| `C0000IW-039` | `[0x0064686c,0x00646888)` | `Singleton<DirectX>` base BCD with PMD `{+4,-1,0}`, type `0x00675bf8`, and CHD `0x00646888`. |
| `C0000IW-040` | `[0x00646888,0x00646898)` | `Singleton<DirectX>` CHD. |
| `C0000IW-041` | `[0x00646898,0x006468a0)` | `Singleton<DirectX>` BCA pointing to self BCD `0x006468a0`. |
| `C0000IW-042` | `[0x006468a0,0x006468bc)` | `Singleton<DirectX>` self BCD with PMD `{0,-1,0}`. |
| `C0000IW-043` | `[0x00675be0,0x00675bf8)` | DirectX type descriptor, exact name `.?AVDirectX@@`. |
| `C0000IW-044` | `[0x00675bf8,0x00675c20)` | Singleton type descriptor, exact name `.?AV?$Singleton@VDirectX@@@@`. |

## Source-Quality Notes

B014's 2026-06-19 source-quality pass resolved the field/GUID/failure-path basics. The accepted whole-file pass supersedes its one-base declaration and manual-global assumptions: the field at `+0x04` is public `LPDIRECTDRAW m_pDirectDraw`, the direct empty Singleton base causes publication/clear, and the coordinated H supplies both base includes plus the `extern` declaration. The constructor's `QueryInterface` GUID is SDK `IID_IDirectDraw`, not local project data, and both DirectDraw setup failure paths pointer-throw `MyError` from the exact DirectX diagnostic string.

The formal CPP owns only `DirectX.h`, required complete-type dependency `../util/Error.h`, and `[[CHILDREN]]`. The formal H owns the guarded declaration, direct bases, virtual destructor, public field, extern, and size assertion. Exact method bodies are emitted by UID000137. Scalar deleting destructor, vtable stores, far EH chunks, base mechanics, RTTI, and alignment gaps remain compiler output; `0x004a1cc0` is represented once by the semantic Singleton destructor specialization rather than as a DirectX helper.

The class H declares `extern DirectX *g_pDirectX` once. The semantic global child emits the sole definition and explicit specializations at position 0; the exact physical storage page is covered-by only.

The required `../util/Error.h` route is closed in the accepted associated support scope, not deferred. [UID:00004J][Error](by-class/Error.md) owns the guarded Error/MyError declarations and inline empty virtual `Error::~Error()`; [UID:00008V][MyError](by-class/MyError.md) owns formatter/destructor CPP; [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md) retains constructor CPP. The compiler-generated Error and MyError scalar wrappers receive no duplicate source bodies.

## Supporting Exact Evidence

- [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md) records exact function boundaries, alignment gaps, constructor/destructor/scalar-deleting-destructor behavior, DirectDraw call sequence, COM release, startup caller, `g_pDirectX` xrefs, and compiler EH helper caveats.
- [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) records the exact DirectX RTTI/vtable range and boundary before adjacent diagnostic string data.
- [UID:0000IW][DirectX](by-file/DirectX.md) records the file-root boundary: DirectDraw object/interface lifetime belongs here, while `GrafPort`, `Surface`, and font-image behavior remain separate consumers/owners.

## Evidence Notes

- Wave3 imports all three methods with high manual/automated grades.
- IDA MCP reports the constructor is called from application startup around `0x004645aa`.
- IDA MCP confirms the constructor calls `DirectDrawCreate` and the destructor dispatches a COM-style release.
- `GrafPort::UpdateRenderRegion` uses `g_pDirectX` while creating DirectDraw surfaces.
- IDA MCP confirms a primary vtable at `0x00618e64` and a tiny `0x004a1cc0` helper that clears [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md). Current Wave3 metadata still reports `vtable_count: 0` and active source omits the helper.
- 2026-05-31 IDA MCP confirms the exact vtable data span at `0x00618e60-0x00618e70`: RTTI pointer `??_R4DirectX@@6B@` at `0x00618e60`, vtable symbol `??_7DirectX@@6B@` at `0x00618e64`, three virtual slots, and DirectX diagnostic string data beginning at `0x00618e70`.

## Open Issues

- Some generated UI text call sites currently list `g_pDirectX` as the receiver for font measurement. IDA shows those specific call sites load [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) at `0x0067ab24`, not `g_pDirectX` at `0x0067ab20`; treat them as font-singleton aliasing until Wave3 data is repaired.

## Assignment Gate

The direct file owner remains [UID:0000IW][DirectX](by-file/DirectX.md). This class is `92/94`, owns the complete source pair assembly, and routes its four independently ordered children to `NexusTK/render/DirectX.cpp`; the file page owns the compilation-unit boundary.

## Score Rationale

- Completion is `92` because the page now carries the complete guarded H, exact CPP include/child channel, two-base EBO layout, public access decision, size assertion, extern, four atomic child entries, ten atomic RTTI objects, exact method/compiler split, and coordinated Error.h dependency route.
- Confidence is `94` because fresh accepted RTTI PMDs/type strings, constructor lowering, vtable/data ranges, direct consumer accesses, global lifecycle, exact formal source, and Error/MyError support all agree. It remains below 95 because no PDB proves original member/access/guard token spelling.

## Cross-References

- [UID:0000IW][DirectX](by-file/DirectX.md)
- [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md)
- [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md)
- [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md)
- [UID:0003HP][DirectXVtable](by-type/by-vtable/DirectXVtable.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md)
- [UID:00005V][GrafPort](by-class/GrafPort.md)
- [Wave3 noticed problems](../wave3_noticed_problems.md)

## Changes

- 2026-08-14 B004 accepted UID0000IW whole-file implementation:
  - Raised `85/88` to `92/94` and replaced the historical one-base/private-field CPP declaration with the exact CPP include/child channel and complete guarded H declaration.
  - Added direct `LObject` plus `Singleton<DirectX>` inheritance, PMD `+0x04` EBO overlap, public `m_pDirectDraw`, x86 size `0x08`, extern and size assertion, four independent child-order entries, and all ten independently bounded RTTI objects.
  - Superseded physical-child definition and pure-helper/manual-global history with semantic-global definition/specializations, covered physical storage, source `0x004a1cc0` specialization classification, and the completed `../util/Error.h` dependency route.

- 2026-07-04 B009 UID000295 support sync:
  - Score unchanged at `85/88`.
  - Recorded that `g_pDirectX` storage is now source-ready as exact child [UID:000295][0x0067ab20-0x0067ab24.g_pDirectX](by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md) through [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md). This class remains the object layout/method owner and should not duplicate the global definition or model it as a class-static member.

- 2026-06-19 B014 source-quality incorporation:
  - Added declaration-level first-draft C++ shell with `[[CHILDREN]]`, changed the field note from `m_directDraw` to `m_pDirectDraw`, and documented SDK `IID_IDirectDraw`, pointer-thrown `MyError`, unconditional `Release`, and compiler-glue exclusion for the unwind helper and scalar deleting destructor.
  - Scores stay `85/88`; the class already clears the direct-emitter gate and the new source-quality details are primarily carried by [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md).
- 2026-06-07 A003 Batch 084 class parent-gate update:
  - Changed to: `COMPLETION:85`, `AUTOGEN_PARENT_UID:0000IW`; confidence remains `88`.
  - Summary/evidence: added supporting exact evidence, assignment gate, and score rationale. Assignment to [UID:0000IW][DirectX](by-file/DirectX.md) is justified because the child is `85/88`, the direct file parent is `85/88`, and [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md) plus [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) document the exact code/vtable evidence.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `82/88`.
  - Summary/evidence: DirectDraw bootstrap responsibility, compact layout, constructor/destructor/unwind/scalar-destructor methods, singleton ownership, startup/GrafPort evidence, and generated alias issue are documented; remaining work is minimal source-facing polish and Wave3 data cleanup for unrelated font-singleton aliasing.
- 2026-05-31 exact vtable split:
  - Before: the page linked only the combined vtable type page and `RECONSTRUCTABLE` was blank.
  - After: the page is marked `RECONSTRUCTABLE:TRUE` and links the exact `0x00618e60-0x00618e70` vtable-data child.
  - Summary/evidence: IDA MCP `list_globals`, `xrefs_to`, and dword scan verify the `DirectX` RTTI/vtable record and prove the adjacent string boundary at `0x00618e70`.
- 2026-06-12 A004 Batch 317 cross-reference update: added [UID:0003HP][DirectXVtable](by-type/by-vtable/DirectXVtable.md) as the source-local reconstructable vtable page for this class. Scores stay `85/88`; the direct class gate already clears `85/85`.
