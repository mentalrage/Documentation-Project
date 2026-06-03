*** UID:00005K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FunctionObject

## Status

- Confidence: strong for callback-base/destructor/vtable role, medium for final original header/source spelling.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Current recovered file: `source-3/simroot_v2/class_FunctionObject.cpp`
- Memory documentation: [UID:000123][0x0049b090-0x0049b28e.FunctionObjectDestructors](by-memory/0x0049b090-0x0049b28e.FunctionObjectDestructors.md)
- Autogen parent: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md); C++ remains blank because the class is below the `95/95` reconstruction-code gate.

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
- 2026-06-03 IDA MCP `lookup_funcs` reconfirmed `0x0049b090` and `0x0049b250` as `0x3e` byte functions; `0x0049b0ce` and `0x0049b28e` are not independent function starts, matching exclusive function ends.
- 2026-06-03 IDA MCP `callers` returned no direct code callers for either destructor, while `xrefs_to` reported data/vtable references at `0x006187e8`, `0x0061a3b0`, `0x00620184`, `0x0062dde8`, and `0x006186a8`.
- 2026-06-03 IDA MCP `list_globals '*FunctionObject*'` identifies `0x006186a8` as `FunctionObject::vftable` and the other data xrefs as generated `PlainMemberFunctionObject` / `DoubleParamMemberFunctionObject` vtables that reuse the base destructor slot.
- 2026-06-03 IDA MCP decompilation/disassembly shows both bodies store `FunctionObject::vftable`, call `sub_4F4A90`, conditionally call `sub_4F4AC0` for heap deletion, and otherwise return `this`; the remaining `_guard_check_icall_nop` path is compiler/security glue for non-freeing delete-flag combinations.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:000123][0x0049b090-0x0049b28e.FunctionObjectDestructors](by-memory/0x0049b090-0x0049b28e.FunctionObjectDestructors.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)

## Changes

- 2026-06-03 MCP verification and parent attachment:
  - What existed before: the class was scored `68/78` with blank reconstructable and parent metadata.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JO`.
  - Summary/evidence: fresh IDA MCP lookup, caller/callee, xref, list-globals, decompile, and disassembly checks confirm the base destructor/vtable role and show the class belongs to the shared [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) utility family. C++ remains blank because final declaration names, all template relationships, and emitted destructor handling are not at the `95/95` gate.
- Completion/confidence score update: existed before as `0/0`; changed to `68/78`. Summary: callback-base role and duplicate destructor emissions are documented, but final source naming and broader callback hierarchy details remain incomplete. Evidence: destructor memory page `0x0049b090-0x0049b28e`, IDA-confirmed function starts, and FunctionObject template cross-reference.
