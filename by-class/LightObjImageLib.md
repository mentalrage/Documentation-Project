*** UID:000076 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "LightObjImageLib.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_GFX_LIGHTOBJIMAGELIB_H
#define NEXUSTK_GFX_LIGHTOBJIMAGELIB_H

#include "../util/LObject.h"
#include "../util/ProtectedArray.h"
#include "../util/Singleton.h"

class IntAlphaSurface;
struct RectBounds;

[[CHILDREN]]

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LightObjImageLib

## 2026-08-18 Complete Declaration Route

Formal H now supplies the guarded dependency shell and inserts the accepted LightInfo and complete class/extern child blocks. Formal CPP includes that H and preserves all existing method/global children. Virtual order, layout, one-definition global policy, and compiler-generated clear/scalar/RTTI/vtable dispositions are unchanged; only declaration ownership and the inline brightness selector were added.

## UID0001PR Accepted Source Route And Complete Class Contract - 2026-07-21

- [UID:0001PR][0x0069b450-0x0069b454.g_pLightObjImageLib](by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md) is the physical `.data` slot and remains a non-emitting evidence page. [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md) owns the sole source definition at file position `0`.
- The source declaration is split deliberately: [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md) emits the `0x1c` record at position `1`; [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md) emits the complete class and `extern` declaration at position `2`; exact by-memory children emit the constructor/destructor/bounds/draw bodies at positions `10/30/40/50/60`.
- The direct source bases are `LObject` followed by `Singleton<LightObjImageLib>`. RTTI records the Singleton PMD `{4,-1,0}`. The empty Singleton base begins at `+0x04` and shares that offset with the first non-empty `ProtectedArray<LightInfo>` member; this is compiler EBO, not evidence for a second authored pointer or a manually published singleton field.
- The accepted `0x30` object layout is: `LObject`/primary vptr at `+0x00`; Singleton EBO and the `ProtectedArray<LightInfo>` vptr at `+0x04`; `m_lightInfos.m_count` at `+0x08`; `m_lightInfos.m_entries` at `+0x0c`; `m_lightInfos.m_defaultCapacity` at `+0x10`; and the inline default `LightInfo` at `+0x14..+0x2f`.
- `m_lightInfos` is the one authored member. The prior prose model that treated `lightInfoArray` and `fallbackLightInfo` as separate source members is superseded by the observed ProtectedArray layout: the fallback record is `m_lightInfos.m_defaultEntry`.
- Source-authored lifetime behavior consists of the normal constructor body and deletion of each non-null generated frame in the ordinary destructor. Singleton publication/clear, ProtectedArray storage teardown, vptr stores, EH cleanup, scalar-delete flags, optional object deallocation, RTTI, and vtable arrays are compiler/template/ABI output and are not handwritten class methods.
- [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md), [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md), [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md), and [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) therefore remain source-non-emitting compiler/data evidence.
- The formal block above is intentionally only the stable class routing marker. It keeps the class closing brace inside the exact layout child and places `[[CHILDREN]]` at this outer owner so the generator emits one complete declaration and one ordered method family without duplicating source.

## Status

- Confidence: strong for method roles, singleton/vtable evidence, observed layout offsets, the `GetLightBounds` caller/source route, draw-mode virtual slots, and source-facing `LightInfo` field names; bounded for exact original spelling of inferred fields/helpers.
- Likely source file: [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- Address ranges: [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md), singleton clear helper [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md), and scalar deleting destructor [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_LightObjImageLib.cpp`
- Singleton: [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md) at `0x0069b450`
- Vtable: [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md) at `0x0061b754`
- Exact vtable data: [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md)

## Class Purpose

`LightObjImageLib` is the singleton-backed light-source rendering library behind `g_pLightObjImageLib`. It loads light metadata from `LIGHT.TBL`, creates radial light frames at startup, renders those frames with two blend modes, and releases the generated frames during destruction.

## Observed State

```text
0x00  LObject/vtable base
0x04  ProtectedArray<LightInfo> vtable
0x08  int lightInfoCount
0x0c  LightInfo* lightInfoEntries
0x10  int lightInfoCapacity
0x14  LightInfo fallback/default record
```

The recovered [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md) rows are `0x1c` bytes and include `tableId`, `innerRadius`, `radiusX`, `radiusY`, `brightness`, `blendScale`, and `generatedFrame`. See [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md) for the current offset model.

## Source Declaration Direction

The current support direction is a normal `LObject`-derived image-library class with `LightInfo` table storage, not a generated aggregate over a memory span:

```cpp
struct LightInfo {
    int tableId;
    int innerRadius;
    int radiusX;
    int radiusY;
    float brightness;
    float blendScale;
    AlphaMaskSurface *generatedFrame;
};

class LightObjImageLib : public LObject {
public:
    LightObjImageLib();
    virtual ~LightObjImageLib();

    void GetLightBounds(int lightIndex, RectBounds *outBounds);
    virtual void DrawLightMode1(AlphaMaskSurface *targetSurface,
                                int centerX,
                                int centerY,
                                int lightIndex);
    virtual void DrawLightMode2(AlphaMaskSurface *targetSurface,
                                int centerX,
                                int centerY,
                                int lightIndex);

private:
    ProtectedArray<LightInfo> lightInfoArray;
    LightInfo fallbackLightInfo;
};
```

This is declaration guidance for the class/type support pages. The exact by-memory child pages own the first-draft method bodies, while [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md) stays a non-emitting address-layout index.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `LightObjImageLib::LightObjImageLib` | [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md) | Loads `LIGHT.TBL`, allocates light records, and prebuilds radial light frames. |
| `LightObjImageLib::~LightObjImageLib` | [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md) | Raw ordinary destructor body; releases generated frames, frees the record array, clears the singleton, and tail-calls `LObject` cleanup. |
| `GetLightBounds(int lightIndex, RectBounds *outBounds)` | [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) | Writes a local light bounds rectangle from the selected record radii; formal first-draft C++ is populated on the exact child page. |
| `DrawLightMode1` | [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md) | Draws a centered light frame through `DrawFrameWithBlendMode` using blend mode `1`. |
| `DrawLightMode2` | [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md) | Draws a centered light frame through `DrawFrameWithBlendMode` using blend mode `2`. |
| Constructor/static singleton cleanup helper | [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md) | File-level cleanup glue that clears `g_pLightObjImageLib`; reached by the constructor cleanup jump at `0x006001d0`, not a class method or source-facing `ClearLightObjImageLibSingleton` API. |
| `ScalarDeletingDestructor` | [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) | Releases generated frames, frees the light record array, clears `g_pLightObjImageLib`, and optionally deletes `this`. |

IDA MCP on 2026-05-22 confirms the constructor has one startup caller at `0x004f6139`. The two draw methods have no direct code refs because they are virtual dispatch targets, but IDA confirms slots `+0x0c` and `+0x10` in the class vtable and both methods call the same frame blitter at `0x00462e10`; see [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md).

2026-06-17 B003 source-quality audit resolves the LightObjImageLib method cluster above the first-draft C++ gate: constructor, ordinary destructor, and both virtual draw modes should emit through [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) `NexusTK/render/LightObjImageLib.cpp`. The scalar deleting destructor remains documented but formal C++ stays blank by compiler-wrapper policy.

2026-06-20 B001 recheck confirms the local method-cluster parent is not a source item. This class and [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) remain the semantic owners, while exact by-memory children carry method emission. The inherited vtable slots at `0x004f4b10` and `0x0041b6c0` are base-interface slots rather than LightObjImageLib-specific unresolved methods; `0x004f4b10` returns the `LObject` runtime descriptor/name block and `0x0041b6c0` is a `ret 8` no-op virtual.

## 2026-06-08 Vtable Gate Recheck

Batch 139 added [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md) for the exact compiler-emitted RTTI/vtable range. The child confirms `0x0061b750 -> ??_R4LightObjImageLib@@6B@`, five slot dwords, constructor/raw-destructor/scalar-deleting-destructor xrefs, and the neighboring `ProtectedArray<LightInfo>` and `NewHumanImageLib` boundaries.

This class is the direct source owner for [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md). The adjacent `ProtectedArray<LightInfo>` vtable remains template/container support and is not folded into the class primary vtable. The improved parent/source evidence is enough for the strict `85/85` parent gate, while exact original spelling for inferred fields/helpers remains below final-audit status.

## 2026-06-17 GetLightBounds Closure

B003 reanalysis closes the prior [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) method-name and caller-context blocker. Fresh IDA MCP evidence shows the only caller at `0x0053c82b` loads `g_pLightObjImageLib`, passes a light index and `RectBounds*`, then applies caller-side translation after this method returns. That supports `void LightObjImageLib::GetLightBounds(int lightIndex, RectBounds *outBounds)` as the source-facing shape. Broader class C++ is still incomplete, but this exact method is self-contained enough to emit first-draft C++.

## Cross-References

- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md)
- [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md)
- [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md)
- [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md)
- [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md)
- [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md)
- [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md)
- [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md)
- [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md)
- [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md)
- [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md)
- [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md)
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-06-08 A007 Batch 139 vtable-parent gate update:
  - What existed before: class scores were `84/80`, below the strict direct-parent gate for [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md).
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, exact vtable-data child link, and a vtable gate recheck section.
  - Summary/evidence: [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md) records the RTTI/vtable dwords, draw-mode virtual slots, target sizes, xrefs, and neighboring template/class boundaries. B003 later resolved the main `LightInfo` field names and exact child first-draft method emission; remaining class-level caveats are exact original helper/declaration spelling and generated metadata omissions.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) because this class is 84/80 and the parent file is 86/80. Live IDA MCP on `NexusTK.exe` confirmed constructor `0x004df7e0`, bounds/draw methods `0x004dfb40`, `0x004dfbb0`, `0x004dfc60`, singleton clear helper `0x004e5bb0`, and scalar deleting destructor `0x004e65e0`; the documented raw destructor address `0x004dfab0` is intentionally not used as attachment proof because IDA does not model it as a function start.
- Completion/confidence score update: existed before as `0/0`; changed to `84/80`. Summary: the singleton library was documented at a high level of detail across purpose, observed layout, vtable, global, `LIGHT.TBL` loading, generated light-frame lifetime, and draw methods, while field names were still medium-confidence at that time. B003 later resolved the main `LightInfo` names. Evidence: linked memory range, `LightInfo` and layout type pages, `g_pLightObjImageLib`, vtable slot evidence, constructor startup caller, and shared frame blitter reference.
- 2026-05-31 exact method split:
  - What existed before: the method table used bare addresses for the constructor, draw modes, and scalar deleting destructor and did not include the `0x004dfb40` bounds helper.
  - Changed to: exact by-memory links for the constructor, bounds helper, draw mode methods, and scalar deleting destructor.
  - Summary/evidence: IDA MCP verified exact function bounds, vtable slots for the two draw methods and deleting destructor, and an external caller for the bounds helper at `0x0053c82b`.
- 2026-06-13 B003 adjacent-helper correction:
  - Before: the status associated the pre-`0x004df7e0` table helper [UID:0003LZ][0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable](by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md) with this class.
  - After: this class starts at the `LightObjImageLib` constructor cluster at `0x004df7e0`; [UID:0003LZ][0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable](by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md) and the raw helper [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md) are documented as `ItemObjImageLib` children.
  - Evidence: B003 live IDA MCP found no `LIGHT.TBL`, `LightInfo` `0x1c` rows, `g_pLightObjImageLib`, or generated light-frame logic in those helpers; the real constructor at [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md) carries those signals.
- 2026-06-17 B003 [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) source-quality execution:
  - Score unchanged at `86/86`.
  - Summary/evidence: the class page now records `GetLightBounds(int lightIndex, RectBounds *outBounds)` as the source-facing method shape and notes that the exact child page has formal first-draft C++. The remaining class-level medium confidence applies to broader field/source declaration cleanup, not to the bounds method's ownership or caller route.
- 2026-06-17 B003 LightObjImageLib method-cluster source-quality execution:
  - Score unchanged at `86/86`.
  - Summary/evidence: B003 resolved the constructor/destructor/draw source readiness, `LightInfo` field names, `lightInfoCapacity`, singleton/global policy, vtable/deleting-destructor policy, and first-draft C++ placement. Exact child pages now emit constructor, ordinary destructor, and draw-mode method C++; scalar deleting destructor remains blank as compiler output.
- 2026-06-20 B001 local-cluster Rule 26 incorporation:
  - Score unchanged at `86/86`.
  - Summary/evidence: linked the ordinary destructor row to [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md), added class declaration guidance, and recorded that [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md) remains a non-emitting index. The B001 scan resolved the inherited slot roles for `0x004f4b10` and `0x0041b6c0`, preserved the exact-child method-emission policy, and kept `tableId`/central base-slot original spelling as support-level confidence caps rather than class ownership blockers.
