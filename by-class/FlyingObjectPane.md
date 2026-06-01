*** UID:000057 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FlyingObjectPane

## Status

- Confidence: strong for role and anchors.
- Likely source file: [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_FlyingObjectPane.cpp`
- Current Wave3 grade: `96.0`
- Current Wave3 coverage: 6 modeled methods, zero missing target refs.

## Class Purpose

`FlyingObjectPane` is a temporary map object for thrown or launched item visuals. It interpolates an item glyph along an arc, schedules short timer ticks, plays impact sound, triggers linked-object impact animation when applicable, and either drops a new object or removes the temporary pane.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00537cb0-0x00537d60` | Initializes start/end coordinates, motion parameters, segment count, and inherited object state. |
| `GetBoundingRect` | `0x00537d80-0x00537f1d` | Computes the current arc-interpolated item glyph bounds. |
| `OnAnimationTick` | `0x00537f20-0x005380af` | Advances the flight, schedules timers, handles hit animation/sound, and resolves final drop/removal. |
| scalar deleting destructor | `0x0053d1a0-0x0053d237` | Tears down the object pane and frees the object from the object heap when requested. |

## Evidence Notes

- IDA shows constructor xrefs from MapPane packet/update helpers at `0x0050dfa0` and `0x00512d60`.
- Wave3 currently models `0x00512d60` as `MapPane::HandleObjectUpdatePacket`, but reports `0x0050dfa0` as unknown. Keep the constructor relationship as IDA evidence pending MapPane ownership cleanup.

## Cross-References

- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/86`. Summary: temporary thrown-item pane role, constructor, bounds, animation tick, destructor, and key caller evidence are documented with strong confidence; remaining work is deeper layout naming and final C++ reconstruction. Evidence: documented address cluster `0x00537cb0-0x005380af`, destructor `0x0053d1a0-0x0053d237`, IDA constructor xrefs, and ItemObjectPane/MapPane cross-references.
