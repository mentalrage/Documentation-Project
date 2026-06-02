*** UID:0000FA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TreeItor_near_class_EventHandler___

## Status

- Confidence: strong for generated destructor behavior; medium for final source placement.
- Likely source file: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), as the `TreeItor<EventHandler*>` iterator used by dispatcher traversal.
- Current generated file: `source-3/simroot_v2/class_TreeItor_near_class_EventHandler___.cpp`
- Imported source hint: `TreeItor_near_class_EventHandler___.cpp`
- Main address doc: [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)

## Class Purpose

`TreeItor<EventHandler*>` is the generated iterator helper for the event-handler tree. [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) constructs stack iterator records with this vtable while routing events through child handlers and translated child coordinates.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~TreeItor<EventHandler*>` | `0x004a7cf0-0x004a7cf6` | Reinstalls iterator vtable. |
| `ScalarDeletingDestructor` | `0x004a7dd0-0x004a7df3` | Reinstalls vtable and conditionally frees heap storage. |

## Ownership Notes

Keep this with the dispatcher handler-tree support code. It should not be a standalone source migration target unless the original project used a broad template implementation file and other `TreeItor<>` specializations point to the same source.

## Evidence Notes

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) is scored `88/80`, has the valid proposed path `NexusTK/ui/core/`, and explicitly lists `TreeItor<EventHandler*>` as dispatcher handler traversal/support content.
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md) records the exact iterator destructor at `0x004a7cf0-0x004a7cf6` and scalar deleting destructor at `0x004a7dd0-0x004a7df3`.
- The same memory page records stack iterator construction with `TreeItor<EventHandler*>::vftable` during `RouteEventToHandlers`, `DispatchToChildren`, and `DispatchToTranslatedChildren`.
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) documents the iterator record layout: vtable at `+0x00`, tree pointer at `+0x04`, and current index at `+0x08`.
- [UID:000258][0x00619344-0x006196c0.ErrorEventReadOnlyData](by-memory/0x00619344-0x006196c0.ErrorEventReadOnlyData.md) places the `TreeItor<EventHandler*>` vtable in the Error/Event read-only data run with neighboring EventDispatcher/Event/EventMan vtables.

## Autogen Status

- Reconstructable: true for dispatcher-local iterator support.
- Parent: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md). Both parent and child now meet the confidence threshold for attachment.
- Code: intentionally blank. The destructor and iterator-record behavior are clear, but final template/header declaration details are not source-quality.

## Score Rationale

- Completion is raised to 78 because the destructor pair, stack iterator usage, layout evidence, vtable neighborhood, and parent assignment are documented.
- Confidence is raised to 84 because multiple IDA-backed docs agree that this specialization is EventDispatcher traversal infrastructure, not a standalone feature class.

## Cross-References

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md)
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md)
- [UID:000258][0x00619344-0x006196c0.ErrorEventReadOnlyData](by-memory/0x00619344-0x006196c0.ErrorEventReadOnlyData.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:72` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the iterator destructor/deleting-destructor mapping, dispatcher ownership notes, and layout/memory cross-references; score remains moderate because the page covers a small generated specialization and final template source placement is not proven.
- 2026-06-02: Raised to `78/84`, marked reconstructable, attached to [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and added parent/path, layout, helper-island, stack-iterator, and read-only-data evidence. C++ remains blank because final template/header spelling is still not source-quality.
