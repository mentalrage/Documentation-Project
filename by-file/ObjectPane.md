*** UID:0000M5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ObjectPane

## Status

- Confidence: strong for `ObjectPane` as a base map-object module.
- Proposed module: `map/ObjectPane.cpp`
- Primary class doc: [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- Main address doc: [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md)
- Evidence basis: live IDA MCP confirms core ObjectPane method boundaries, scattered virtual helpers, subclass construction/destruction reachability, and object-pane-family vtable slots.

## File Role

`ObjectPane.cpp` owns the base pane for renderable map objects. It sits below [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), item/object-info panes, and other map-object visual classes. It combines `Pane` behavior with object identity, sprite frame/palette state, attached light/object imagery, local bounds, object data, and map-position updates.

This file should not be merged into generic [UID:0000MC][Pane](by-file/Pane.md) infrastructure. `Pane` owns generic UI/window behavior; `ObjectPane` owns game-object rendering state and `MapPane` integration.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ObjectPane` | `0x005372d0-0x005378fa` plus virtuals at `0x00469050` and `0x00469080` | Base game-object pane for object type, sprite/frame/palette, attached object, bounds, object data, and map position. |
| attached object lifecycle | `0x005374f0`, `0x005375f0` | Replaces/releases attached light/object imagery and recalculates bounds. |
| object data virtuals | `0x00537800`, `0x00537880` | Sets/gets the 16-byte object data block at the object-state buffer. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Empty/bounds virtuals | `0x00469050`, `0x00469080` | Shared virtual rect helpers referenced by object-pane vtables. |
| Lifecycle | `0x005372d0`, `0x005373a0` | Constructs `Pane`, installs `ObjectPane` vtables, initializes object state, and releases attached object state in cleanup. |
| Attached object ownership | `0x005374f0`, `0x005375f0` | Attaches/detaches sprite/light object payloads, updates height offsets, and notifies `MapPane` when active. |
| Container/bounds operations | `0x00537720`, `0x00537740`, `0x00537760` | Releases object from container, stores bounds, and refreshes clipping/dirty regions. |
| Object data and position | `0x00537800`, `0x00537880`, `0x005378a0` | Updates packed object data, copies object data out, and moves the object through `MapPane::UpdateObjectPosition`. |

## Boundary Notes

- `ObjectPane` should be a base map-object source under `map/`, while [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) owns actor-specific movement, animation, command, and packet logic.
- Item/object overlay classes are now documented as companion modules: [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) owns ground/flying item objects, [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) owns attached/floating overlays such as balloons, object labels, hit bars, and damage numbers, [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md) owns static map props, [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md) owns light-source object panes, and [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md) owns positional sound objects.
- [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) is excluded from the `ObjectPane` family despite its misleading recovered name because it constructs through `Pane` and is allocated by [UID:0000P1][UserPane](by-file/UserPane.md).
- `ObjectPane::SetObjectData` at `0x00537800-0x0053787a` is a live IDA-verified virtual-slot body that updates the 16-byte object-data record and conditionally recomputes attached-state geometry. Keep it with this file until a later field-name audit proves a narrower helper owner.

## IDA MCP Evidence

Targeted checks on 2026-06-05 confirmed:

- `0x00469050-0x0046907a` and `0x00469080-0x004690a5` are real rect-helper virtuals referenced from vtables.
- `0x005372d0-0x00537395` is the constructor and has direct constructor-like xrefs from object-pane subclasses.
- `0x005373a0-0x005374cb` is the destructor.
- `0x005374f0-0x005375e1`, `0x005375f0-0x005376b5`, `0x00537720-0x00537739`, `0x00537740-0x00537751`, `0x00537760-0x005377f2`, `0x00537800-0x0053787a`, `0x00537880-0x00537894`, and `0x005378a0-0x005378fa` are real method starts/ranges.
- `SetObjectData`, `GetObjectData`, and `SetPosition` have object-pane-family vtable/data references, while the constructor/destructor caller sets tie the core range to the surrounding map-object subclasses.

## Cross-References

- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md)
- [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md)
- [UID:00020S][0x00469080-0x004690a5.ObjectPaneGetEmptyRect](by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md)
- [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md)
- [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md)

## Changes

- 2026-06-05 live IDA refresh:
  - What existed before: the file page already had the right module boundary but retained stale recovery-output caveats and older evidence wording.
  - What changed: raised completion/confidence to `88/86`, removed stale recovery-output references, and updated the evidence around `SetObjectData`, vtable slots, and constructor/destructor reachability.
  - Summary/evidence: live IDA confirms both scattered virtual helpers, all ten core ObjectPane method boundaries, object-pane-family vtable references, and subclass construction/destruction caller sets.

- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a reconstruction-path coverage error.
  - Changed to: `NexusTK/map/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented `ObjectPane` constructor anchor at `0x005372d0`; proposed-source-tree keeps this game-world object base under `map/`, separate from generic `ui/core/Pane.cpp` and from item/static/sound object companions.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `84`.
- Summary/evidence: the page documents the base map-object role, method families, boundary notes, IDA range checks, and subclass/module cross-references; confidence is strong for source role and remaining uncertainty is mostly final field/slot naming.
