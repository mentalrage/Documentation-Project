*** UID:0000DH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SoundObjectPane

## Status

- Confidence: strong for role and anchors.
- Likely source file: [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_SoundObjectPane.cpp`

## Class Purpose

`SoundObjectPane` is the map-object wrapper for positional or object-linked sound effects. It derives through [UID:00009R][ObjectPane](by-class/ObjectPane.md), stores sound position and trigger parameters, starts playback after construction, and either destroys itself or schedules follow-up triggers depending on its sound mode.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x0053ca20-0x0053cab4` | Builds an `ObjectPane` with object type `11`, copies sound/target position data, and stores playback parameters. |
| non-deleting destructor | `0x0053cac0-0x0053cb48` | Clears linked-object sound references, unregisters from map object manager, and destroys the base object pane. |
| `StartPlayback` | `0x0053cb50-0x0053cc5c` | Reads playback mode fields, plays immediately or schedules timer work, and may destroy the object. |
| `OnTriggerSound` | `0x0053cc70-0x0053ce3c` | Handles direct, counted, and probability-based trigger events. |
| scalar deleting destructor | `0x0053d660-0x0053d739` | Non-deleting cleanup plus optional object deletion. |

## Evidence Notes

- Constructor callers are the map packet/object handlers at `0x0050ec30` and `0x00512f20`.
- `StartPlayback` callers at `0x0050edb7` and `0x005132e0` occur immediately after construction paths, matching the class startup contract.
- Active generated output omits the non-deleting destructor at `0x0053cac0`; use the memory doc for migration.

## Cross-References

- [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md)
- [UID:0001DJ][0x0053ca20-0x0053ce3c.SoundObjectPaneCore](by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md)
- [UID:0001DN][0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors](by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `88`.
- Evidence: the page documents object-sound role, constructor/destructor/playback/trigger/scalar-destructor ranges, constructor/startup callers, active generated omission, and core owner cross-references; remaining completion gap is source-ready field naming and C++ rewrite detail.
