*** UID:00005K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FunctionObject

## Status

- Confidence: strong for callback-base role, medium for final source name.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Current recovered file: `source-3/simroot_v2/class_FunctionObject.cpp`
- Memory documentation: [UID:000123][0x0049b090-0x0049b28e.FunctionObjectDestructors](by-memory/0x0049b090-0x0049b28e.FunctionObjectDestructors.md)

## Class Purpose

`FunctionObject` is a small `LObject`-derived base for callback objects. Current active output only exposes scalar deleting destructor support, but the generated callback subclasses use this family to store and dispatch bound member-function callbacks.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| scalar deleting destructor | `0x0049b090-0x0049b0ce` | Resets the base vtable to `FunctionObject`, destroys `LObject`, and conditionally deletes storage. |
| scalar deleting destructor | `0x0049b250-0x0049b28e` | Duplicate emitted destructor body with the same behavior. |

## Evidence Notes

- `simroot_v2/class_FunctionObject.cpp` emits only the two destructor bodies.
- Cached prewave records name both functions as `~FunctionObject`.
- IDA MCP `lookup_funcs` on 2026-05-25 confirms both starts as real `0x3e` byte functions.
- The duplicate bodies are likely compiler/vtable support emissions, not separate hand-written feature logic.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:000123][0x0049b090-0x0049b28e.FunctionObjectDestructors](by-memory/0x0049b090-0x0049b28e.FunctionObjectDestructors.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `68/78`. Summary: callback-base role and duplicate destructor emissions are documented, but final source naming and broader callback hierarchy details remain incomplete. Evidence: destructor memory page `0x0049b090-0x0049b28e`, IDA-confirmed function starts, and FunctionObject template cross-reference.
