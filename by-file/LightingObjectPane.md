*** UID:0000KO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# LightingObjectPane

## 2026-08-18 Complete Source-Family Incorporation

- `NexusTK/map/LightingObjectPane.cpp/.h` owns the complete nine-method authored family `[0x0053c5e0,0x0053ca1b)`, 1,083 bytes, SHA256 `EFB2268CDFDF38A1626AF9FD0414FB2EF7223E95111339BFF6A7233C5004CE9A`: constructor, ordinary destructor, `GetBrightness`, `GetAnchorScreenPoint`, `GetLightBounds`, `QueueLightBounds`, `SetLightImageIndex`, `ApplyLightAtAnchor`, and `ApplyLightMode2AtAnchor` in exact address/source order.
- Exact `0x138` layout remains ObjectPane base `+0x000..+0x127`, `m_lightImageIndex +0x128`, `m_localOffsetY +0x12c`, `m_localOffsetX +0x130`, and borrowed `ObjectPane *m_anchorSource +0x134`. Constructor object type is 10; destruction detaches the borrowed anchor.
- Compiler-only inventory is the scalar deleting destructor `[0x0053d380,0x0053d422)`, adjustor thunks `[0x0053cf28,0x0053cf33)` and `[0x0053cf33,0x0053cf3e)`, and six RTTI/vtable items in `[0x00620a38,0x00620ae4)`. These are emitted from the ordinary class declaration and receive no handwritten duplicate.
- Exact alignment inventory is `[0x53c5da,0x53c5e0)` 6, `[0x53c6a1,0x53c6b0)` 15, `[0x53c6f7,0x53c700)` 9, `[0x53c802,0x53c810)` 14, `[0x53c92e,0x53c930)` 2, `[0x53c97b,0x53c980)` 5, `[0x53c9b5,0x53c9c0)` 11, `[0x53c9eb,0x53c9f0)` 5, `[0x53ca1b,0x53ca20)` 5, and `[0x53d422,0x53d430)` 14 bytes. These are compiler alignment, not owner boundaries.
- The predecessor ending at `0x0053c5da` remains the separate LivingObjectPane family (UID0001DE), and the successor beginning exactly at `0x0053ca20` remains SoundObjectPane (UID0001DJ). Neither neighbor is absorbed by this file.
- Support closure: UID0001D8 supplies AttachedObjectPane position resolution; LightObjImageLib supplies bounds/brightness/draw APIs through its header; ProtectedArray supplies the reusable table template; MapPane grants friendship and consumes `RectBounds`. No file-owned global, static, string, resource, table, or import exists.
- The former exclusion of the adjacent AttachmentAnchorResolver family is retained only as corrected history. All five former synthetic children now emit through UID000075. Score is `94/95`; unknown private spellings and raw-body retention cause cap confidence.

## Status

- Confidence: strong for lifecycle, light-image-index ownership, four-field layout, vtable stores, callers, map-object placement, and direct class/child routing; original source-path/header split and private spellings remain inferred.
- Proposed module: `map/LightingObjectPane.cpp`
- Evidence basis: live IDA MCP function, caller, disassembly, vtable-data, and boundary checks through 2026-06-12.
- Primary class doc: [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md)
- Main address docs: [UID:0001DG][0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle](by-memory/0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle.md), [UID:0001DI][0x0053c980-0x0053c9b5.LightingObjectPaneSetLightImageIndex](by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetLightImageIndex.md), and [UID:0001DM][0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor](by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md)

## File Role

`LightingObjectPane.cpp` owns the map-object wrapper for client-side light objects. The `0x138`-byte class derives from [UID:0000M5][ObjectPane](by-file/ObjectPane.md) and adds `m_lightImageIndex`, local Y/X offsets, and borrowed `ObjectPane *m_anchorSource`. It detaches/rebinds itself when its selected LightObjImageLib/table row changes.

The file should stay in the map-object family even though it calls into render/light infrastructure. The object pane is created from map/effect packet flows and behaves like a live object in the map scene, while the render light library should own reusable light rendering and asset state.

## Header And Consumer Route

- [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md) now owns the complete guarded `LightingObjectPane.h` declaration. Its CPP channel includes that header before the exact method children; this by-file page remains documentation-only and does not duplicate either formal channel.
- [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) is the exact ObjectList consumer. It needs the complete type to construct a `LightingObjectPane`, call `SetLightImageIndex`, register it in ObjectList, and attach it to the matching `StaticObjectPane`.
- The source-facing include route is `ObjectList.cpp -> LightingObjectPane.h -> ObjectPane.h`. This keeps the class declaration in its historical map header while allowing ObjectList to compile the complete-object construction and method calls.

Historical light type/radius/intensity/color and owned light-binding-interface claims are superseded. Constructor stores, resolver bounds lookup, static/effect callers, and exact ObjectPane Attach/Detach slots prove the current layout and borrowed relationship.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `LightingObjectPane` | `0x0053c5e0-0x0053c6a1`, scalar wrapper at `0x0053d380` | Source constructor/ordinary destructor plus class-owned compiler deleting-wrapper output; exact four-field tail and borrowed anchor cleanup. |
| `SetLightImageIndex` | `0x0053c980-0x0053c9b5` | `void` method with exact unchanged-value no-op and `DetachObject` -> index write -> `AttachObject(this)` order. |
| `LightingObjectPane` vtable data | [UID:000359][0x00620a38-0x00620ae4.LightingObjectPaneVtableData](by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md) | Source-declared/generated-binary RTTI/vtable child for the class. |
| resolved neighboring light-table apply helper | [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) | AttachmentAnchorResolver-owned helper: live callers compute bounds, resolve an anchor point, then call global light-table slot `+0x0c`. Keep it outside UID0001DI `LightingObjectPane::SetLightImageIndex`; the shared table-index concept does not merge their owners. |

## Evidence Notes

- Accepted 2026-07-13 B003 session `c81909be` confirms constructor `0x0053c5e0-0x0053c640`, ordinary destructor `0x0053c640-0x0053c6a1`, `SetLightImageIndex` `0x0053c980-0x0053c9b5`, adjustor thunks `0x0053cf28`/`0x0053cf33`, and scalar deleting destructor `0x0053d380-0x0053d422`.
- Constructor callers are `0x0050a9a5` in `0x0050a940` and `0x00530e79` in `0x00530d00`; setter callers are `0x00530dbe` in `0x00530d00` and `0x00538a90` in `0x005389d0`.
- The constructor calls `ObjectPane(10,0,mapX,mapY)`, initializes index/Y-offset/X-offset/anchor at `+0x128/+0x12c/+0x130/+0x134`, and installs three vtable views. Both creators allocate exact `0x138` bytes.
- The ordinary destructor and scalar wrapper both restore the three views and call borrowed anchor `DetachObject`; only the wrapper adds flags and UID000197 storage free. Bit `4` uses the observed guarded size/no-free one-byte stub path, not source-authored placement-delete logic.
- Vtable data refs tie `0x00620a3c -> 0x0053d380`, `0x00620aac -> 0x0053cf28`, and `0x00620adc -> 0x0053cf33`; constructor/destructor code writes all three slots.
- 2026-06-12 direct JSON-RPC checks reconfirmed [UID:000359][0x00620a38-0x00620ae4.LightingObjectPaneVtableData](by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md): the range starts at `??_R4LightingObjectPane@@6B@`, has primary/adjusted slots to `0x0053d380`, `0x0053cf28`, and `0x0053cf33`, receives vptr refs from constructor, ordinary destructor, and scalar deleting destructor paths, and ends before `0x00620ae4 -> ??_R4SoundObjectPane@@6B@`.

## Boundary Notes

- `0x0053c700-0x0053c92e` is not `LightingObjectPane`; it belongs to [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md) / attached-object screen-bounds helper code.
- Current source ownership keeps `SetLightImageIndex` at `0x0053c980`; both older `SetIntensity` and `EffectObjectPaneHelper_53C980` labels remain superseded search history.
- `EffectObjectPane::UpdateEffectAnimation` calls `SetLightImageIndex` at `0x00538a90` with effect-frame record `+0x0c` unless the signed value is `-1`; that caller relationship does not move `LightingObjectPane` into [UID:0000IZ][Effects](by-file/Effects.md).
- Disabled thunks `0x0053cf28` and `0x0053cf33` are adjustor thunks forwarding to the scalar deleting destructor.

## Cross-References

- [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md)
- [UID:0001DG][0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle](by-memory/0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle.md)
- [UID:0001DI][0x0053c980-0x0053c9b5.LightingObjectPaneSetLightImageIndex](by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetLightImageIndex.md)
- [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md)
- [UID:0001DM][0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor](by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md)
- [UID:000359][0x00620a38-0x00620ae4.LightingObjectPaneVtableData](by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md)
- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)

## Changes

- 2026-08-11 B003 UID00023D support synchronization: preserved file metadata `89/91`, owner `FILE`, and `NexusTK/map/`. Added the exact class-header ownership and ObjectList consumer/include route after moving the declaration into UID000075 H; this by-file page remains non-emitting by schema.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:78`.
  - Summary/evidence: lifecycle, intensity rebinding, object-pane/map/render boundaries, excluded attachment-helper range, and destructor/thunk refs are documented; completion and confidence remain moderate because the light-manager render helper at `0x0053c9c0-0x0053c9eb` still needs final ownership and behavior review.
- 2026-06-01 `+0x134` wording correction:
  - What existed before: `+0x134` was described as an owned lighting interface.
  - Changed to: constructor-supplied attached object/light-binding interface pointer.
  - Summary/evidence: IDA MCP shows constructor `0x0053c5e0` stores the first constructor argument into `+0x134`, creator paths pass the source object pane there, SetIntensity calls virtual slots `+0x4c`/`+0x48`, and destructors call slot `+0x4c`.
- 2026-06-03 neighbor resolution update:
  - Before: `0x0053c9c0-0x0053c9eb` was listed as an unresolved light-manager virtual near `LightingObjectPane`.
  - Changed to: linked [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) and kept `LightingObjectPane` ownership limited to lifecycle/destructor/`SetIntensity` behavior.
  - Evidence: restarted IDA MCP caller-context checks show `0x0053c9c0` is called after `AttachmentAnchorResolver::ComputeScreenBounds` and `ResolveAnchorPoint`, while `SetIntensity` has separate callers and a padding gap before `0x0053c9c0`.
- 2026-06-04 live IDA attachment and path update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, completion/confidence were `78/78`, and class/method children were not attached to this file for reconstruction.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`, completion `84`, confidence `86`, and exact class/method children now attach to this file.
  - Evidence: live IDA confirms constructor and `SetIntensity` callers, constructor field stores, three vtable slots, destructor/thunk references, base `ObjectPane` construction/teardown, and padding around adjacent non-owner helpers. The score remains below final-source quality because the `+0x134` interface type and slot names are still unresolved.
- 2026-06-12 A003 Batch274:
  - Raised `84/86` to `85/88` and added the exact [UID:000359][0x00620a38-0x00620ae4.LightingObjectPaneVtableData](by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md) child evidence needed for strict class/child routing.
  - Evidence: direct JSON-RPC rechecked raw RTTI/vtable dwords, vptr refs from constructor/destructor paths, exact method/thunk boundaries, and the `SoundObjectPane` successor boundary while preserving `NexusTK/map/` placement.
- 2026-07-13 B003 UID0001DM source-quality implementation callback:
  - Raised `85/88 -> 89/91`; kept `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`, file ownership, and all established neighbor exclusions.
  - Synchronized the exact four-field/`0x138` model, ordinary constructor/destructor source, validator-preserved UID0001DI `SetLightImageIndex` rename/body, UID0001DM compiler-wrapper policy, UID000359 generated-vtable policy, and historical rejected interface/intensity aliases.
  - Post-callback stale-current-state sweep corrected the neighboring UID0002TZ exclusion and UID0001D9 caller sentence to the accepted setter name, exact `0x00538a90` call, effect-frame `+0x0c`, and `-1` sentinel semantics; historical dated aliases below remain history only.
  - Score remains below `90/95` because the executable carries no original `.cpp`/header path string and exact private spellings/access are inferred, not because any current source body or route remains blocked.
