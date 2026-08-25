*** UID:000075 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "LightingObjectPane.h"

#include "AttachedObjectPane.h"
#include "LightObjImageLib.h"
#include "MapPane.h"
#include "../ui/core/RectBounds.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_MAP_LIGHTINGOBJECTPANE_H
#define NEXUSTK_MAP_LIGHTINGOBJECTPANE_H

#include "ObjectPane.h"

class MapPane;
struct MapPoint;
struct RectBounds;

class LightingObjectPane : public ObjectPane
{
public:
    LightingObjectPane(
        ObjectPane *anchorSource,
        int mapY,
        int mapX,
        int localOffsetX,
        int localOffsetY,
        int lightImageIndex);
    virtual ~LightingObjectPane();

    float GetBrightness() const;
    MapPoint *GetAnchorScreenPoint(MapPoint *outPoint) const;
    RectBounds *GetLightBounds(RectBounds *outBounds) const;
    void QueueLightBounds() const;
    void SetLightImageIndex(int lightImageIndex);
    void ApplyLightAtAnchor(MapPane *mapPane, int centerX, int centerY) const;
    void ApplyLightMode2AtAnchor(MapPane *mapPane, int centerX, int centerY) const;

private:
    int m_lightImageIndex;
    int m_localOffsetY;
    int m_localOffsetX;
    ObjectPane *m_anchorSource;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LightingObjectPane

## 2026-08-18 Complete Class Incorporation

- UID000075 is the sole class owner/emitter for all nine authored definitions. Exact child order is UID0001DG lifecycle, UID0002TX brightness, UID0001DH anchor/bounds, UID0002TY queue, UID0001DI setter, UID0002TZ mode 1, and UID0002U0 mode 2.
- The guarded formal H above is complete: six newly routed helper declarations join the existing constructor/destructor/setter, while the exact four-field tail remains `m_lightImageIndex`, Y offset, X offset, and borrowed `ObjectPane *m_anchorSource`. No synthetic nested resolver and no reserved tail are present.
- Scalar deleting destructor, two adjusted deleting-destructor thunks, RTTI, and three vtable views are compiler-covered from this virtual class declaration. Source score is `94/95`; no class-owned global/static/data/resource item exists.

## Status

- Confidence: very strong for lifecycle, light-image-index rebinding, four-field tail layout, vtable ownership, and direct class/file parent chain; exact original private spellings/access remain inferred.
- Likely source file: [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md)
- Evidence basis: live IDA MCP function, caller, disassembly, vtable-data, and boundary checks through 2026-06-12.
- Direct exact children now routed to this class: [UID:0001DG][0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle](by-memory/0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle.md), [UID:0001DI][0x0053c980-0x0053c9b5.LightingObjectPaneSetLightImageIndex](by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetLightImageIndex.md), [UID:0001DM][0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor](by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md), and [UID:000359][0x00620a38-0x00620ae4.LightingObjectPaneVtableData](by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md).

## Class Purpose

`LightingObjectPane` is the `ObjectPane` subclass for live map light sources. Its exact 16-byte derived tail is `int m_lightImageIndex` at `+0x128`, `int m_localOffsetY` at `+0x12c`, `int m_localOffsetX` at `+0x130`, and borrowed `ObjectPane *m_anchorSource` at `+0x134`, producing the proven `0x138` complete-object size. It detaches and reattaches itself to the anchor when the selected light-image/table row changes.

The earlier light type/radius/intensity/color array and owned light-binding-interface descriptions are superseded. Constructor stores, LightObjImageLib bounds consumption, static/effect callers, and ObjectPane Attach/Detach slots independently establish the current model.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x0053c5e0-0x0053c640` | Calls `ObjectPane(10, 0, mapX, mapY)`, initializes the four derived fields in layout order, and installs three compiler vtable views. |
| non-deleting destructor | `0x0053c640-0x0053c6a1` | Human-authored source is `m_anchorSource->DetachObject()`; vptr restoration and base teardown are compiler output. |
| `SetLightImageIndex` | `0x0053c980-0x0053c9b5` | On change, performs exact `DetachObject`, index write, `AttachObject(this)` order; source return is `void`. |
| scalar deleting destructor | `0x0053d380-0x0053d422` | Class-owned compiler ABI wrapper covered by ordinary lifecycle UID0001DG; normal free only for bit 1 set/bit 4 clear. |
| vtable/RTTI data | [UID:000359][0x00620a38-0x00620ae4.LightingObjectPaneVtableData](by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md) | Exact primary and adjusted `LightingObjectPane` RTTI/vtable views. |
| neighboring light-table apply helper | [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) | Now documented under AttachmentAnchorResolver-adjacent ownership; callers compute/resolve attachment anchors before calling it. |

## Evidence Notes

- Constructor callers include map/effect paths at `0x0050a940` and `0x00530d00`.
- [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) is the exact `0x00530d00` consumer: it constructs this class when a matching `StaticObjectPane` has no attached light, registers the new pane in ObjectList, attaches it to the static pane, and otherwise calls `SetLightImageIndex` on the existing instance.
- `SetLightImageIndex` callers are `0x00530d00` and [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md) animation update at `0x005389d0`; both use signed image/table indices, including `-1` absence.
- `0x0053c700-0x0053c92e` is adjacent but belongs to [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md), not this class.
- 2026-07-13 accepted B003 live IDA session `c81909be` confirms constructor writes `m_lightImageIndex`, Y/X local offsets, and borrowed anchor at `+0x128/+0x12c/+0x130/+0x134`, and installs vtables `0x00620a3c`, `0x00620aac`, and `0x00620adc`.
- The same evidence confirms ordinary and scalar destructors restore the same three vtable views, call exact `ObjectPane::DetachObject()` slot `+0x4c` through `m_anchorSource`, and then call `ObjectPane` teardown at `0x005373a0`. The scalar wrapper alone handles delete flags and operator delete.
- Vtable data refs tie the primary slot to scalar deleting destructor `0x0053d380` and the two secondary slots to adjustor thunks `0x0053cf28` and `0x0053cf33`.
- 2026-06-12 direct JSON-RPC checks reconfirm the exact vtable range: `0x00620a38 -> ??_R4LightingObjectPane@@6B@`, primary slot `0x00620a3c -> 0x0053d380`, adjusted slots `0x00620aac -> 0x0053cf28` and `0x00620adc -> 0x0053cf33`, and successor boundary `0x00620ae4 -> ??_R4SoundObjectPane@@6B@`.
- The same pass reconfirmed the method boundaries and direct routing basis: constructor `0x0053c5e0-0x0053c640`, ordinary destructor `0x0053c640-0x0053c6a1`, `SetIntensity` `0x0053c980-0x0053c9b5`, scalar deleting destructor `0x0053d380-0x0053d422`, and two adjustor thunks that jump to the scalar deleting destructor after applying `ecx` offsets.

## Cross-References

- [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md)
- [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md)
- [UID:0001DG][0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle](by-memory/0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle.md)
- [UID:0001DI][0x0053c980-0x0053c9b5.LightingObjectPaneSetLightImageIndex](by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetLightImageIndex.md)
- [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md)
- [UID:0001DM][0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor](by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md)
- [UID:000359][0x00620a38-0x00620ae4.LightingObjectPaneVtableData](by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md)

## Score Rationale

- Completion is `90` because the class now records all exact code/generated children, complete `0x138` layout, constructor/destructor/setter source contracts, adjusted-thunk behavior, direct route, and exact formal declaration in the H channel. The CPP channel includes `LightingObjectPane.h` before the namespace-scope `[[CHILDREN]]` insertion so ObjectList and other consumers receive one declaration owner.
- Confidence is `93` because current live MCP, RTTI/vtable, creator, ObjectPane Attach/Detach, and AttachmentAnchorResolver evidence agree. The score remains below rare final-audit level because exact original private spellings/access and inherited adjusted-facet names are not symbol-proven.

## Changes

- 2026-08-11 B003 UID00023D support synchronization: preserved `90/93`, owner/emitter `0000KO`, reconstructable true, blank position, and the existing child inventory. Moved the complete class declaration from CPP into guarded H, reduced CPP to its owning header plus `[[CHILDREN]]`, and documented the exact ObjectList create/update consumer without changing the inferred four-field layout or lifecycle semantics.
- Completion/confidence score update: existed before as `0/0`; changed to `80/84`. Summary: lifecycle, intensity mutation, owned interface teardown/rebind, caller evidence, and adjacent non-owner split are documented well, but one probable light-manager virtual still needs final owner confirmation. Evidence: constructor/destructor/set-intensity memory pages, `EffectObjectPane` caller evidence, object type `10`, interface slots `18`/`19`, and `AttachmentAnchorResolver` exclusion note.
- 2026-06-01 `+0x134` wording correction: existed before as an owned lighting interface claim; changed to constructor-supplied attached object/light-binding interface pointer. Evidence: IDA MCP constructor stores the first constructor argument at `+0x134`, creator paths pass the source object pane, and SetIntensity/destructors invoke slots `18`/`19` through that pointer.
- 2026-06-03 neighbor resolution update: existed before with `0x0053c9c0-0x0053c9eb` as a probable unresolved LightingObjectPane virtual; changed to link [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) as an AttachmentAnchorResolver-adjacent helper. Evidence: restarted IDA MCP caller-context checks show `0x0053c9c0` follows attachment bounds/intersection and anchor resolution, not the `SetIntensity` caller set.
- 2026-06-04 reconstructable attachment update:
  - What existed before: the class was `80/84` with no reconstructable flag or parent attachment.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000KO`.
  - Evidence: live IDA confirms exact lifecycle, intensity, thunk, scalar destructor, vtable, caller, and boundary evidence. Reconstructed C++ remains blank because final field/interface names are not final-source quality.
- 2026-06-12 A003 Batch274:
  - Raised `84/88` to `86/90`, retained file parent [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md), and repaired exact method/vtable children to route through this class as their direct semantic parent.
  - Evidence: direct JSON-RPC reconfirmed raw vtable dwords and xrefs, exact constructor/destructor/SetIntensity/scalar-destructor boundaries, adjusted thunk bodies, constructor/destructor stores of all three vtable views, and the `SoundObjectPane` successor boundary.
- 2026-07-13 B003 UID0001DM source-quality implementation callback:
  - Raised `86/90 -> 90/93` and inserted the accepted complete class declaration. `[[CHILDREN]]` is after the closing `};`, so exact child method definitions emit at namespace scope.
  - Replaced stale light type/radius/intensity/color and attached-interface claims with the exact four-field/`0x138` model. The borrowed anchor and Attach/Detach semantics are direct behavioral facts; member spellings/access remain documented inferences.
  - Synchronized UID0001DI's validator-preserving `SetLightImageIndex` rename, UID0001DG ordinary source responsibility, UID0001DM compiler-wrapper policy, UID000359 generated-vtable policy, two adjustor thunks, and historical rejected aliases without changing class owner/emitter route.
