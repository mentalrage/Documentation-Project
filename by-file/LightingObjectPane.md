*** UID:0000KO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LightingObjectPane

## Status

- Confidence: strong for lifecycle, intensity ownership, vtable stores, callers, and map-object placement; capped below final-source quality by attached-object/light-binding interface names.
- Proposed module: `map/LightingObjectPane.cpp`
- Evidence basis: live IDA MCP function, caller, disassembly, vtable-data, and boundary checks through 2026-06-04.
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
| resolved neighboring light-table apply helper | [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) | Now documented as an AttachmentAnchorResolver-adjacent helper: live callers compute bounds, resolve an anchor point, then call global light-table slot `+0x0c`. Keep it outside `LightingObjectPane::SetIntensity`. |

## Evidence Notes

- 2026-06-04 live IDA MCP confirms constructor `0x0053c5e0-0x0053c640`, ordinary destructor `0x0053c640-0x0053c6a1`, `SetIntensity` `0x0053c980-0x0053c9b5`, adjustor thunks `0x0053cf28` and `0x0053cf33`, and scalar deleting destructor `0x0053d380-0x0053d422`.
- Constructor callers are `0x0050a9a5` in `0x0050a940` and `0x00530e79` in `0x00530d00`; `SetIntensity` callers are `0x00530dbe` in `0x00530d00` and `0x00538a90` in `0x005389d0`.
- The constructor calls `ObjectPane` base construction at `0x0053c5f4` with object type `10`, stores light state at `+0x128`, `+0x12c`, `+0x130`, stores the constructor-supplied binding pointer at `+0x134`, and installs vtable slots `0x00620a3c`, `0x00620aac`, and `0x00620adc`.
- The ordinary destructor and scalar deleting destructor both restore the three `LightingObjectPane` vtable slots, call virtual slot `+0x4c` through `+0x134`, and then tail into `ObjectPane` teardown. The scalar deleting destructor optionally frees `0x138` bytes depending on delete flags.
- Vtable data refs tie `0x00620a3c -> 0x0053d380`, `0x00620aac -> 0x0053cf28`, and `0x00620adc -> 0x0053cf33`; constructor/destructor code writes all three slots.

## Boundary Notes

- `0x0053c700-0x0053c92e` is not `LightingObjectPane`; it belongs to [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md) / attached-object screen-bounds helper code.
- Current source ownership keeps `SetIntensity` at `0x0053c980`; older report text had a stale `EffectObjectPaneHelper_53C980` projection.
- `EffectObjectPane::UpdateEffectAnimation` at `0x005389d0` calls `SetIntensity`, but that caller relationship should not move `LightingObjectPane` into [UID:0000IZ][Effects](by-file/Effects.md).
- Disabled thunks `0x0053cf28` and `0x0053cf33` are adjustor thunks forwarding to the scalar deleting destructor.

## Cross-References

- [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md)
- [UID:0001DG][0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle](by-memory/0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle.md)
- [UID:0001DI][0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity](by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity.md)
- [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md)
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
- 2026-06-03 neighbor resolution update:
  - Before: `0x0053c9c0-0x0053c9eb` was listed as an unresolved light-manager virtual near `LightingObjectPane`.
  - Changed to: linked [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) and kept `LightingObjectPane` ownership limited to lifecycle/destructor/`SetIntensity` behavior.
  - Evidence: restarted IDA MCP caller-context checks show `0x0053c9c0` is called after `AttachmentAnchorResolver::ComputeScreenBounds` and `ResolveAnchorPoint`, while `SetIntensity` has separate callers and a padding gap before `0x0053c9c0`.
- 2026-06-04 live IDA attachment and path update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, completion/confidence were `78/78`, and class/method children were not attached to this file for reconstruction.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`, completion `84`, confidence `86`, and exact class/method children now attach to this file.
  - Evidence: live IDA confirms constructor and `SetIntensity` callers, constructor field stores, three vtable slots, destructor/thunk references, base `ObjectPane` construction/teardown, and padding around adjacent non-owner helpers. The score remains below final-source quality because the `+0x134` interface type and slot names are still unresolved.
