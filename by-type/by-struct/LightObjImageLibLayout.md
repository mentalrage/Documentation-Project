*** UID:0001UX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000076 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000076 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class LightObjImageLib : public LObject, public Singleton<LightObjImageLib>
{
public:
    LightObjImageLib();
    virtual ~LightObjImageLib();

    void GetLightBounds(int lightImageIndex, RectBounds *outBounds);
    virtual void DrawLightMode1(
        IntAlphaSurface *targetSurface,
        int centerX,
        int centerY,
        int lightImageIndex);
    virtual void DrawLightMode2(
        IntAlphaSurface *targetSurface,
        int centerX,
        int centerY,
        int lightImageIndex);

    float GetBrightness(int lightImageIndex)
    {
        return m_lightInfos.GetAtOrDefault(lightImageIndex)->brightness;
    }

private:
    ProtectedArray<LightInfo> m_lightInfos;
};

extern LightObjImageLib *g_pLightObjImageLib;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LightObjImageLib Layout

## 2026-08-18 Header And Brightness Closure

The exact `0x30` LObject/Singleton/ProtectedArray layout and virtual order remain unchanged. Complete class and extern declarations now emit in formal H, and `GetBrightness(int)` exposes the exact current/fallback `ProtectedArray<LightInfo>::GetAtOrDefault` selector needed by LightingObjectPane. The old CPP-local declaration is historical; compiler clear/scalar/RTTI/vtable artifacts and score remain unchanged.

## UID0001PR Accepted Complete Declaration And EBO Layout - 2026-07-21

- This page now emits the complete `LightObjImageLib` declaration at [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md) position `2`, after [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md) at position `1` and before method children at `10/30/40/50/60`.
- RTTI proves direct `LObject` and `Singleton<LightObjImageLib>` bases. The Singleton PMD `{4,-1,0}` places its empty subobject at `+0x04`; Visual C++ EBO permits the non-empty `ProtectedArray<LightInfo> m_lightInfos` member to begin at the same offset. This source shape explains both vtable stores without inventing an authored singleton pointer member.
- Exact object allocation is `0x30`. `LObject` occupies `+0x00..+0x03`; `m_lightInfos` occupies `+0x04..+0x2f` with its vptr at `+0x04`, count at `+0x08`, entries at `+0x0c`, default capacity at `+0x10`, and inline `LightInfo m_defaultEntry` at `+0x14..+0x2f`.
- The historical source-facing split into `lightInfoArray` plus `fallbackLightInfo` is superseded. Those labels describe binary subregions of one `ProtectedArray<LightInfo>` member; the accepted member expression is `m_lightInfos.m_defaultEntry`.
- The declaration exposes only authored methods. Singleton publication/clear, ProtectedArray teardown, scalar delete flags, vptr stores, RTTI, and vtable data remain compiler/template/ABI output. The sole global definition remains [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md); this declaration provides only `extern` visibility.
- The class has no authored storage beyond `m_lightInfos`, no explicit padding member, and no source-visible helper for the `0x004e5bb0` cleanup thunk. The `0x30` size follows naturally from the direct bases and member layout.

## Status

- Confidence: strong for observed offsets, `ProtectedArray<LightInfo>` shape, fallback row placement, generated-frame lifetime, singleton/vtable anchors, and draw/bounds consumers; medium-high for final field names.
- Owner class: [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md).
- Autogen parent: attached to [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md); the class scores `84/80` and this layout scores `84/86`, so both sides satisfy the 80/80 parent gate.
- Evidence: IDA constructor/destructor/draw decompilation and xrefs on 2026-05-26.

## Layout

```text
LightObjImageLib
  +0x00  LObject/vtable base
  +0x04  Singleton<LightObjImageLib> empty base (PMD {4,-1,0})
  +0x04  ProtectedArray<LightInfo> m_lightInfos (EBO overlap)
  +0x30  end / sizeof
```

Expanded view:

```text
  +0x04  void* m_lightInfos vtable
  +0x08  int m_lightInfos.m_count
  +0x0c  LightInfo* m_lightInfos.m_entries
  +0x10  int m_lightInfos.m_defaultCapacity
  +0x14  LightInfo m_lightInfos.m_defaultEntry
```

The fallback record at `+0x14` is `0x1c` bytes, so the observed object state ends exactly at the `0x30` allocation boundary.

## Notes

- [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md) writes [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md), stores the [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md), installs the `ProtectedArray<LightInfo>` vtable at `+0x04`, initializes capacity `10`, and seeds the fallback record from constants at `0x00619660`.
- The constructor initializes the embedded list/protected-array count to `0`, entry pointer to `0`, and capacity to `10`. `lightInfoCapacity` is the best source-facing name for `+0x10`; the older `initialOrGrowCapacity` label is descriptive but less source-like.
- The fallback row at `+0x14` is seeded from four `-1` integer constants and zeroed float/pointer fields, producing `{-1, -1, -1, -1, 0.0f, 0.0f, nullptr}` under the resolved `LightInfo` schema.
- The constructor opens `LIGHT.TBL`, reads a count, reallocates the entry buffer as `count * 0x1c`, then reads each [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md) row.
- [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md), [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md), and [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md) index the entry buffer by light index, falling back to `+0x14` when out of range.
- [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md) uses the same `lightInfoCount`, `lightInfoEntries`, and `fallbackLightInfo` selection pattern from a raw no-entry `AttachmentAnchorResolver` helper, then returns the selected row's `brightness` field at [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md) offset `+0x10`.
- B003 2026-06-17 reanalysis confirms [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) only depends on `lightInfoCount`, `lightInfoEntries`, `fallbackLightInfo`, and the `LightInfo` `radiusX`, `radiusY`, and `generatedFrame` fields. The fallback record's seeded negative integer fields do not affect the empty bounds path because `generatedFrame` is zero.
- B003 2026-06-17 source-quality audit resolves the row fields as `tableId`, `innerRadius`, `radiusX`, `radiusY`, `brightness`, `blendScale`, and `generatedFrame`; the older `lightSource` and `blendValue` labels are superseded.
- The ordinary and [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) delete each generated frame, free the entry buffer at `+0x0c`, restore the protected-array vtable, and clear [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md).

2026-06-16 C001 live IDA refresh reconfirmed the layout from current decompilation and xrefs: constructor `0x004df7e0-0x004dfaa6` installs the class vtable at `+0x00`, installs `ProtectedArray<LightInfo>` at `+0x04`, initializes `+0x08/+0x0c/+0x10`, copies fallback constants into `+0x14`, and allocates/resizes rows as `28 * count`. The bounds and draw methods index `this[3] + 28 * index` or `this + 0x14`, then use the generated-frame pointer at row `+0x18`; draw modes call the same blitter with modes `1` and `2`. `xrefs_to 0x0061b754`, `0x0061b74c`, and `0x0069b450` reconfirmed the documented class/template vtable stores and 19 singleton refs. IDA was safely renamed from `sub_4DF7E0`, `sub_4DFB40`, `sub_4DFBB0`, `sub_4DFC60`, `sub_4E65E0`, and `unk_69B450` to `LightObjImageLibConstructor`, `LightObjImageLibGetLightBounds`, `LightObjImageLibDrawLightMode1`, `LightObjImageLibDrawLightMode2`, `LightObjImageLibScalarDeletingDestructor`, and `g_pLightObjImageLib`; the IDB was saved.

## Cross-References

- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md)
- [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md)
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md)
- [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md)
- [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md)
- [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md)
- [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md)
- [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md)
- [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md)
- [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md)
- [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md)

## Changes

- 2026-06-06: Attached the object layout to [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md). Scores remain `84/86`; this parent metadata update follows the documented class-owned `ProtectedArray<LightInfo>` and fallback row.
- 2026-05-31 LightObjImageLib split pass:
  - What existed before: metadata scores were `0/0`, and the layout page referenced broad method roles without exact child pages for the constructor, bounds helper, draw modes, or scalar deleting destructor.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, with exact by-memory references for the verified method children.
  - Summary/evidence: IDA MCP verified the constructor, draw methods, bounds helper, ordinary destructor, scalar deleting destructor, vtable writes, singleton writes, `ProtectedArray<LightInfo>` vtable writes, and 0x1c-byte row stride. Final field names still need source-level refinement, so scores remain below near-final thresholds.
- 2026-06-16 C001 assignment `C001-goal2-type-layout-ida-refresh-pursuit-item-light-20260616-11`: raised `84/86 -> 86/90` after live IDA reconfirmed constructor/bounds/draw/destructor agreement on the `ProtectedArray<LightInfo>` header, `0x1c` fallback row, `28 * count` allocation, generated-frame pointer at row `+0x18`, singleton lifecycle refs, and class/template vtable stores. Owner/emitter stay [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md); C++ stays blank because final field names and declaration spelling remain provisional.
- 2026-06-17 B003 source-quality audit:
  - Changed to: `87/91`, renamed `+0x10` to `lightInfoCapacity`, recorded the resolved fallback row values, and synced the `LightInfo` field names with the constructor/draw/destructor evidence.
  - Summary/evidence: B003 rechecked the constructor initialization, protected-array state, fallback constants from `0x00619660`, downstream bounds/draw behavior, ordinary/scalar destructor cleanup, and LightObjImageLib first-draft source readiness.
- 2026-06-21 B011 AttachmentAnchorResolver consumer sync:
  - Score unchanged at `87/91`.
  - Summary/evidence: [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md) now records a raw no-entry resolver helper that uses `lightInfoCount`, `lightInfoEntries`, and `fallbackLightInfo` to select a row and return `LightInfo::brightness`; this strengthens consumer evidence for the layout without changing ownership or field names.
