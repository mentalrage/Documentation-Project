*** UID:0000KO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LightingObjectPane

## Status

- Confidence: strong for lifecycle and intensity ownership; medium for the omitted light-manager render helper.
- Proposed module: `map/LightingObjectPane.cpp`
- Current generated source: `source-3/simroot_v2/class_LightingObjectPane.cpp`
- Primary class doc: [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md)
- Main address docs: [UID:0001DG][0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle](by-memory/0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle.md), [UID:0001DI][0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity](by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity.md), and [UID:0001DM][0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor](by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md)

## File Role

`LightingObjectPane.cpp` likely owns the map-object wrapper for client-side light objects. The class derives through [UID:0000M5][ObjectPane](by-file/ObjectPane.md), stores light type/radius/intensity/color fields, stores a constructor-supplied attached object/light-binding interface pointer at `+0x134`, and refreshes that relationship when intensity changes.

The file should stay in the map-object family even though it calls into render/light infrastructure. The object pane is created from map/effect packet flows and behaves like a live object in the map scene, while the render light library should own reusable light rendering and asset state.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `LightingObjectPane` | `0x0053c5e0-0x0053c6a1`, scalar destructor at `0x0053d380` | Light-source object pane with attached object/light-binding cleanup. |
| `SetIntensity` | `0x0053c980-0x0053c9b5` | Calls release/rebind virtual slots on the attached object/light-binding pointer when intensity changes. |
| probable render/light-manager virtual | `0x0053c9c0-0x0053c9eb` | Omitted from active output; calls a light-manager vtable slot with map/render context and a field at `+0x128`. Owner still needs final confirmation. |

## Boundary Notes

- `0x0053c700-0x0053c92e` is not `LightingObjectPane`; it belongs to [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md) / attached-object screen-bounds helper code.
- Current generated output correctly owns `SetIntensity` at `0x0053c980`; older report text had a stale `EffectObjectPaneHelper_53C980` projection.
- `EffectObjectPane::UpdateEffectAnimation` at `0x005389d0` calls `SetIntensity`, but that caller relationship should not move `LightingObjectPane` into [UID:0000IZ][Effects](by-file/Effects.md).
- Disabled thunks `0x0053cf28` and `0x0053cf33` are adjustor thunks forwarding to the scalar deleting destructor.

## Cross-References

- [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md)
- [UID:0001DG][0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle](by-memory/0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle.md)
- [UID:0001DI][0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity](by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity.md)
- [UID:0001DM][0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor](by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md)
- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:78`.
  - Summary/evidence: lifecycle, intensity rebinding, object-pane/map/render boundaries, excluded attachment-helper range, and destructor/thunk refs are documented; completion and confidence remain moderate because the light-manager render helper at `0x0053c9c0-0x0053c9eb` still needs final ownership and behavior review.
- 2026-06-01 `+0x134` wording correction:
  - What existed before: `+0x134` was described as an owned lighting interface.
  - Changed to: constructor-supplied attached object/light-binding interface pointer.
  - Summary/evidence: IDA MCP shows constructor `0x0053c5e0` stores the first constructor argument into `+0x134`, creator paths pass the source object pane there, SetIntensity calls virtual slots `+0x4c`/`+0x48`, and destructors call slot `+0x4c`.
