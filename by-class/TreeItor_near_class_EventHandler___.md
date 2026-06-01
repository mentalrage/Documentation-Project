*** UID:0000FA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Cross-References

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md)
- [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md)
- [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:72` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the iterator destructor/deleting-destructor mapping, dispatcher ownership notes, and layout/memory cross-references; score remains moderate because the page covers a small generated specialization and final template source placement is not proven.
