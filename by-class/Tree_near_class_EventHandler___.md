*** UID:0000F8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Tree_near_class_EventHandler___

## Status

- Confidence: strong for generated destructor behavior; medium for final source placement.
- Likely source file: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), as the `Tree<EventHandler*>` specialization used by the dispatcher.
- Current generated file: `source-3/simroot_v2/class_Tree_near_class_EventHandler___.cpp`
- Imported source hint: `Tree_near_class_EventHandler___.cpp`
- Main address doc: [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)

## Class Purpose

This is the generated `Tree<EventHandler*>` specialization used by [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) for handler traversal. It wraps an `LObject` base and `TreeNodeData` storage. The dispatcher constructor installs this vtable on its embedded tree at offset `0x4`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~Tree<EventHandler*>` | `0x004a7cd0-0x004a7ce8` | Reinstalls tree vtable, destroys node data, then destroys `LObject`. |
| `ScalarDeletingDestructor` | `0x004a7d80-0x004a7dc7` | Same destructor body with conditional heap free. |

## Ownership Notes

Do not treat this as a standalone container source file by default. The only current concrete role is the event-dispatcher handler tree. Keep it grouped with `ui/core/EventDispatcher.cpp` unless broader non-dispatcher uses are found.

## Cross-References

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md)
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:72` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the destructor/deleting-destructor behavior, dispatcher-embedded ownership, and memory/layout links; score remains moderate because this is a small generated specialization rather than a proven standalone source file.
