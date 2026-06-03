*** UID:0000A6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ParcelPane

## Status

- Confidence: strong for parcel notification pane behavior, vtables, layout, singleton ownership, and source-file placement; medium for final input helper semantics and whether helper classes were public or private original declarations.
- Likely source file: [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- Current recovered file: `source-3/simroot_v2/class_ParcelPane.cpp`
- Memory range: [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md)
- Vtable/type evidence: [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- Layout evidence: [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)
- Known generated-data pollution: ParcelPane metadata/global-data still references [UID:00005F][FpsPane](by-class/FpsPane.md) diagnostics code at `0x004b64a0` and the FPS globals.

## Class Purpose

`ParcelPane` is the small in-game parcel alert pane with two parcel/letter slots. It tracks left/right slot state, animates button frames, draws `ALERTBTN` resources, handles keyboard/mouse activation, and stores the active singleton in [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md).

## Layout Notes

`ParcelPane` starts from the common [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). Its own state starts at `+0xf8` and the `ParcelIconPane` constructor allocates the child as `0x124` bytes, so generated fields past `+0x124` are not parcel-child state. See [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md) for the slot bytes, button rectangles, animation counters, and secondary/tertiary callback offset normalization.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x00546290-0x00546435` | `ParcelPane::ParcelPane` | Initializes pane base, installs three vtable views, sets `g_pParcelPane`, initializes slot state/rectangles, positions the HUD pane, and starts a 100 ms timer. |
| `0x00546440-0x005464ac` | non-deleting destructor | Resets vtables, performs pane cleanup, clears `g_pParcelPane`, and destroys the base pane. Not emitted in active `class_ParcelPane.cpp`. |
| `0x005464b0-0x00546574` | `SetParcelSlotData` | Updates slot state/id bytes, resets dirty/animation state, positions the pane, and invalidates display. |
| `0x005465e0-0x00546609` | `OnKeyDown` | IDA-confirmed secondary key-event virtual at vtable slot `0x00621c98`; current behavior is tiny and still below final-source naming quality. |
| `0x00546610-0x00546806` | `OnMouseEvent` | Handles slot hit tests and dispatch/action behavior for parcel buttons. |
| `0x00546810-0x00546887` | `ProcessSlotAnimations` | Advances slot animation state and schedules another timer. |
| `0x00546890-0x0054696e` | `OnPaint` | Draws left and right parcel buttons from `ALERTBTN.EPF` / `ALERTBTN.PAL`. |
| `0x00546970-0x005469da` | `UpdateAnimationCounter` | Advances or resets left/right animation counters. |
| `0x005469e0-0x00546aaa` | `GetFrameIndex` | Maps slot state/id and side to `ALERTBTN` frame numbers. |
| `0x00546e80-0x00546e8a` | clear global helper | Clears `g_pParcelPane`. |
| `0x00546eb7-0x00546ecd` | destructor adjustor thunks | Secondary/tertiary vtable thunks forwarding to `0x00547000`. Compiler-generated; see [UID:0001EM][0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md). |
| `0x00547000-0x005470ad` | scalar deleting destructor | Clears layer/event state and `g_pParcelPane`, destroys base pane, and optionally frees memory. |

## Evidence Notes

- IDA MCP confirms all listed ParcelPane function starts. The separate `0x004b64a0` FPS range is now active under `class_FpsPane.cpp`; IDA still does not mark that address as a function.
- IDA MCP xrefs to `0x0069ba28` include constructor/destructor paths and `FlyingParcelPane::AnimateStep`, matching `g_pParcelPane`.
- `ParcelIconPane` constructor at `0x00545e40` allocates a `ParcelPane` child and initializes the same fields as the standalone constructor, so the pane family should be documented together.
- IDA MCP xrefs place the packet/update callback at `0x005461c0` in `ParcelIconPane`'s secondary vtable, not in the `ParcelPane` vtables. It still forwards to `ParcelPane::SetParcelSlotData` through the child pointer.
- IDA MCP vtable dump places `ParcelPane::OnMouseEvent` at secondary slot `+0x04`, `OnKeyDown` at secondary slot `+0x08`, and `ProcessSlotAnimations` at tertiary slot `+0x04`; the tertiary table ends before the `FlyingParcelPane` RTTI at `0x00621cc8`.
- [UID:0002OH][0x00621bb0-0x00621d50.ParcelNotificationVtableData](by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md) records the exact `ParcelPane` secondary vtable slot `0x00621c98 -> 0x005465e0`, and [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md) records the `+0xa0` secondary callback offset normalization used by `OnKeyDown` and `OnMouseEvent`.
- IDA MCP confirms generated `0x00544c50` is the shared `Pane` layer-membership helper and generated `0x005051c0` draws visible tiles from a cached surface at `this + 0x428`; neither belongs to the 0x124-byte `ParcelPane` child.
- `FlyingParcelPane` is tightly coupled through `g_pParcelPane` and parcel delivery animation state.

## Open Questions

- Reconcile stale ParcelPane metadata/global-data references to `0x004b64a0`, `g_fpsDebugActive`, and `g_fpsLogEnabled`.
- Recover full `OnKeyDown` and `OnMouseEvent` semantics before rewriting headers.

## Cross-References

- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md)
- [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md)
- [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md)
- [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)
- [UID:0001EK][0x00546440-0x005464ac.ParcelPaneDestructor](by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md)
- [UID:0001EP][0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor](by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md)
- [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md)
- [UID:00005F][FpsPane](by-class/FpsPane.md)

## Changes

- 2026-05-31: Marked reconstructable and attached to [UID:0000MF][ParcelPane](by-file/ParcelPane.md); remaining core methods now have exact child by-memory pages.
  - Before: class documentation had detailed method/layout evidence but validator autogen metadata was blank.
  - After: `RECONSTRUCTABLE:TRUE` with file parent set; C++ remains blank because input/event names, helper APIs, and final field names are below the 95+ final-source threshold.
  - Evidence: IDA MCP function enumeration/decompilation confirmed constructor, slot update, input, timer, paint, animation, frame-index, singleton, and destructor boundaries in the parcel family range.
- Before: completion/confidence metadata were `0/0` despite detailed layout, method, vtable, global, pollution, and open-question notes.
- Changed to: `COMPLETION:84` and `CONFIDENCE:76`.
- Evidence: constructor/destructor, slot updates, mouse/key/timer/paint helpers, animation counters, frame mapping, scalar deleting destructor, singleton xrefs, parcel-icon ownership, and known stale FPS pollution are documented; confidence remains medium because helper ownership and full input semantics still need review.
- 2026-06-03 confidence update:
  - What existed before: `CONFIDENCE:76` and the `OnKeyDown` row only described the tiny generated body.
  - Changed to: `CONFIDENCE:80`, with the key-event row tied to exact vtable-data and layout evidence.
  - Evidence: [UID:0000MF][ParcelPane](by-file/ParcelPane.md) is a validated `NexusTK/ui/panels/` parent at 80 confidence, [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md) and [UID:0002OH][0x00621bb0-0x00621d50.ParcelNotificationVtableData](by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md) document the `ParcelPane` secondary key-event slot, and [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md) documents the parcel callback subobject offsets. C++ remains blank because final field names and input semantics are still not at the 95+ gate.
