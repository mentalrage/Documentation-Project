*** UID:00005K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Memory documentation: [UID:000123][0x0049b090-0x0049b28e.FunctionObjectDestructors](by-memory/0x0049b090-0x0049b28e.FunctionObjectDestructors.md)
- Documentation basis: IDA-confirmed duplicate scalar deleting destructor boundaries, vtable-only xrefs, base/free callees, callback-family vtable reuse, and the shared [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) source-family page.
- Final-source caveat: the binary evidence currently exposes the base destructor support and callback-family vtable reuse, while the final declaration shape should be driven by the callback template/source-family docs.
- Autogen parent: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md); C++ remains blank because the class is below the `95/95` reconstruction-code gate.
- Parent gate: parent file [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) is above `80/80`, and this class now clears the child-side attachment threshold for destructor support pages.

## Class Purpose

`FunctionObject` is a small `LObject`-derived base for callback objects. The documented callback subclasses use this family to store and dispatch bound member-function callbacks, while the observed base-class machine code in this page is limited to scalar deleting destructor support.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| scalar deleting destructor | `0x0049b090-0x0049b0ce` | Resets the base vtable to `FunctionObject`, destroys `LObject`, and conditionally deletes storage. |
| scalar deleting destructor | `0x0049b250-0x0049b28e` | Duplicate emitted destructor body with the same behavior. |

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-05-25 confirms both starts as real `0x3e` byte functions.
- The duplicate bodies are likely compiler/vtable support emissions, not separate hand-written feature logic.
- 2026-06-03 IDA MCP `lookup_funcs` reconfirmed `0x0049b090` and `0x0049b250` as `0x3e` byte functions; `0x0049b0ce` and `0x0049b28e` are not independent function starts, matching exclusive function ends.
- 2026-06-03 IDA MCP `callers` returned no direct code callers for either destructor, while `xrefs_to` reported data/vtable references at `0x006187e8`, `0x0061a3b0`, `0x00620184`, `0x0062dde8`, and `0x006186a8`.
- 2026-06-03 IDA MCP `list_globals '*FunctionObject*'` identifies `0x006186a8` as `FunctionObject::vftable` and the other data xrefs as generated `PlainMemberFunctionObject` / `DoubleParamMemberFunctionObject` vtables that reuse the base destructor slot.
- 2026-06-03 IDA MCP decompilation/disassembly shows both bodies store `FunctionObject::vftable`, call `sub_4F4A90`, conditionally call `sub_4F4AC0` for heap deletion, and otherwise return `this`; the remaining `_guard_check_icall_nop` path is compiler/security glue for non-freeing delete-flag combinations.
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) and [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) document the reusable callback-template family, keeping this class in the shared utility source family rather than in feature-specific construction sites.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `80` | The page now records the shared callback-base responsibility, source-file parent, exact destructor-support memory page, duplicate emitted destructor bodies, vtable-only reachability, callback-family vtable reuse, generated-output caveat, parent attachment gate, and final-C++ blocker. It remains below higher completion because the final header/template declaration shape and broader template hierarchy names are not source-final. |
| Confidence | `82` | IDA-backed function boundaries, xrefs, decompilation/disassembly, and the FunctionObjects/template pages strongly support the current ownership. Confidence stays unchanged because final original spelling and declaration structure remain unresolved. |

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
- 2026-06-06 provenance cleanup:
  - Before: the status/evidence sections still presented a direct recovered-output path and current-output framing as evidence.
  - After: replaced that with the IDA-backed documentation basis and an explicit recovered-output caveat.
  - Evidence: IDA-confirmed destructor bounds, vtable-only xrefs, base/free callees, callback-family vtable reuse, and the shared FunctionObjects source-family page remain the authoritative support. Scores, parent, and blank C++ gate remain unchanged.
- 2026-06-06 A004 parent-gate cleanup:
  - Changed completion from `74` to `80`; confidence remains `82`.
  - Removed remaining generated-output/prewave evidence dependency, added the parent attachment gate, and added score rationale.
  - Evidence: the existing IDA destructor/vtable evidence plus [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) and [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) are sufficient for the class-level callback-base ownership, while final C++ stays blank below the final-source gate.
- Completion/confidence score update: existed before as `0/0`; changed to `68/78`. Summary: callback-base role and duplicate destructor emissions are documented, but final source naming and broader callback hierarchy details remain incomplete. Evidence: destructor memory page `0x0049b090-0x0049b28e`, IDA-confirmed function starts, and FunctionObject template cross-reference.
