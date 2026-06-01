*** UID:000049 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EffectObjectPane

## Status

- Confidence: strong for runtime role and memory ownership, medium for final source module.
- Proposed source: `render/Effects.cpp` or a nearby object-pane/effects module.
- Current recovered source: `source-3/simroot_v2/class_EffectObjectPane.cpp`
- Core memory ranges: `0x005387b0-0x00538baa`
- Destructor range: `0x0053d100-0x0053d196`
- Wave3 summary: game object pane for visual effect rendering.

## Responsibility

`EffectObjectPane` is a game-object pane for animated effect sprites. It stores an effect id, frame/timeline descriptor, current frame, flags, and optional loop range. Runtime methods resolve sprite bounds, advance frames, trigger lighting state changes, update the parent object, schedule sounds, and render effect sprites through the effect render context.

This class consumes image data loaded by [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), but it is not the asset loader itself. It is closer to runtime object/render code and should be cross-linked from [UID:0000IZ][Effects](by-file/Effects.md) and [UID:0000L3][MapPane](by-file/MapPane.md).

Lighting intensity changes are delegated to [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md). Keep that class as the light-source object owner rather than folding it into `EffectObjectPane`.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x005387b0-0x0053887c` | `EffectObjectPane` | Constructs the attached object pane state from effect id, target object, duration, effect type, and constructor data. |
| `0x00538880-0x0053889f` | non-deleting destructor body | Resets EffectObjectPane vtables and delegates to the attached-object cleanup body. |
| `0x005388a0-0x005388b4` | `StartIdleTimer` candidate | Starts/schedules the embedded timer at `+0xa4`; generated BackPane ownership was rejected and replaced by caller/layout evidence. |
| `0x005388c0-0x00538956` | `GetEffectBounds` | Uses active frame entry and `GetSpriteBounds`, then offsets by attached screen position. |
| `0x00538960-0x005389c9` | `GetFrameBounds` | Copies active frame bounds or zero bounds into caller-provided rectangles. |
| `0x005389d0-0x00538aef` | `UpdateEffectAnimation` | Advances frame sequence, handles loop/end removal, updates lighting, parent sprite frame, and sound trigger. |
| `0x00538af0-0x00538baa` | `RenderEffect` | Draws current effect frame through [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md), with optional motion state. |
| `0x0053d100-0x0053d196` | `ScalarDeletingDestructor` | Resets vtables, destroys `AttachedObjectPane`, and optionally frees object memory. |

## Open Questions

- Whether `EffectObjectPane` originally lived in `render/Effects.cpp`, `map/ObjectPane.cpp`, or a small `EffectObjectPane.cpp` companion.
- Several local structs in the generated body should become named private structs or fields once layout evidence is reviewed.
- The exact owner of `g_effectRenderContext` should be reviewed with render-context globals.
- Final source-facing names for the `+0xa4` timer subobject and frame descriptor fields need one more class-layout naming pass before writing C++.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001D9][0x005387b0-0x00538baa.EffectObjectPaneCore](by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md)
- [UID:0002QV][0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor](by-memory/0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor.md)
- [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md)

## Changes

### 2026-05-28 - Corrected Core Range Endpoint

- What existed before: the core range and `RenderEffect` row ended at `0x00538ba9`.
- What changed: both now end at IDA exclusive end `0x00538baa`.
- Why: IDA MCP function review shows `sub_538AF0` ending at `0x00538baa`; byte `0x00538ba9` belongs to `RenderEffect`, while `0x00538baa-0x00538bb0` is alignment.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `74/80`.
  - Summary/evidence: runtime effect-pane role, constructor/bounds/frame/update/render/destructor methods, image-lib and lighting relationships, open source-module questions, and corrected endpoint are documented; remaining work is detailed layout review and render-context ownership.

### 2026-06-01 - Core Child Functions Completed

- What existed before: the class method table omitted the modeled destructor-style body at `0x00538880` and left the `0x005388a0` timer helper as a generated BackPane caveat elsewhere.
- What changed: the table now includes both child methods, and the class is attached to [UID:0000IZ][Effects](by-file/Effects.md) as reconstructable.
- Why: IDA MCP decompilation of the only caller constructs an `EffectObjectPane`, inserts that same object, then calls `0x005388a0`; neighboring vtable/destructor evidence ties `+0xa4` to the EffectObjectPane subobject layout.
- Completion/confidence score update: existed before as `74/80`; updated to `80/84` because core child coverage, caller evidence, and timer ownership are now resolved. Confidence remains below final-audit level pending field-name and source-file split cleanup.
