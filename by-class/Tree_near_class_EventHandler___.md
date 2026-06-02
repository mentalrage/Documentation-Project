*** UID:0000F8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Evidence Notes

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) is scored `88/80`, has the valid proposed path `NexusTK/ui/core/`, and explicitly lists `Tree<EventHandler*>` as handler traversal/support content.
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md) records the exact destructor at `0x004a7cd0-0x004a7ce8` and scalar deleting destructor at `0x004a7d80-0x004a7dc7`.
- The same memory page records the dispatcher constructor installing `Tree<EventHandler*>::vftable` on the embedded tree and sentinel-node setup for traversal.
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) documents the embedded tree at dispatcher offset `+0x4`, 28-byte handler records, and the node-vector field accessed through tree offset `+0x04`.
- [UID:000258][0x00619344-0x006196c0.ErrorEventReadOnlyData](by-memory/0x00619344-0x006196c0.ErrorEventReadOnlyData.md) places the `Tree<EventHandler*>` vtable in the Error/Event read-only data run with the neighboring EventDispatcher/Event/EventMan vtables.

## Autogen Status

- Reconstructable: true for dispatcher-local tree support.
- Parent: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md). Both parent and child now meet the confidence threshold for attachment.
- Code: intentionally blank. The binary destructor behavior and layout are clear, but the final template/header declaration is not recovered at source-quality level.

## Score Rationale

- Completion is raised to 78 because the destructor pair, embedded tree ownership, layout evidence, vtable neighborhood, and parent assignment are documented.
- Confidence is raised to 84 because multiple IDA-backed docs agree that this specialization is EventDispatcher traversal infrastructure, not a standalone feature class.

## Cross-References

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md)
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md)
- [UID:000258][0x00619344-0x006196c0.ErrorEventReadOnlyData](by-memory/0x00619344-0x006196c0.ErrorEventReadOnlyData.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:72` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the destructor/deleting-destructor behavior, dispatcher-embedded ownership, and memory/layout links; score remains moderate because this is a small generated specialization rather than a proven standalone source file.
- 2026-06-02: Raised to `78/84`, marked reconstructable, attached to [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and added parent/path, layout, helper-island, and read-only-data evidence. C++ remains blank because final template/header spelling is still not source-quality.
