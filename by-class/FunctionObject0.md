*** UID:00005L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FunctionObject0

## Status

- Confidence: strong for zero-argument callback-base role.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Generated-output lead retained only for search context: `class_FunctionObject0.cpp`
- Related memory: [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md), now a non-emitting mixed container whose exact FunctionObject0 children are [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) and [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md).
- Rebuild handling: source-declared callback base with compiler-emitted vtable/destructor support.
- Parent handling: attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md); this page is now `85/88` and the parent file clears the active assignment gate for the exact destructor children.

## Class Purpose

`FunctionObject0` is the zero-argument callback-object base. It supplies destructor support and a pure-virtual slot used by derived callback wrappers such as the `Application` zero-argument member-function object.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) | scalar deleting destructor | Resets the vtable, runs the base cleanup, and conditionally deletes storage depending on the MSVC deleting-destructor flag byte; guard-mode size constant is `0x18`. |
| [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md) | scalar deleting destructor | Duplicate emitted destructor body with the same behavior; guard-mode size constant is `0x04`. |
| pure virtual call slot | `0x005ca28c-0x005ca2a7` | Shared CRT `_purecall` body used by abstract vtable slots; `FunctionObject0` owns the pure-virtual declaration, not this runtime helper implementation. |

## Evidence Notes

- Older generated output emits both destructor bodies and the pure-virtual helper, but the current score is based on IDA and existing documentation rather than generated source.
- IDA `lookup_funcs` confirms `0x005ca28c` as `__purecall` sized `0x1b`.
- The related `PlainMemberFunctionObject0<Application>` derived wrapper has an `Invoke` method at `0x004671a0` and an object-size virtual at `0x004673f0`.

## 2026-06-06 Live IDA Class Audit

- `lookup_funcs` reports exact function sizes for the local family: `0x004671a0` is `0x0d`, the two `FunctionObject0` scalar deleting destructors at `0x004671f0` and `0x004672c0` are each `0x3e`, the related object-size virtual at `0x004673f0` is `0x06`, and shared `_purecall` at `0x005ca28c` is `0x1b`.
- Decompilation and disassembly of both destructor bodies show the same source-level shape: write `FunctionObject0::vftable`, call the base cleanup at `0x004f4a90`, inspect the deleting-destructor flag byte, and call the delete/free helper at `0x004f4ac0` only when the ordinary delete bit is set and the guard-mode bit is clear.
- Both destructor bodies have no ordinary code callers. Their reachability is vtable/data based: `0x004671f0` has five data xrefs, while duplicate body `0x004672c0` has one data xref.
- The sibling `PlainMemberFunctionObject0<Application>` invoke at `0x004671a0` has four data xrefs, and its object-size virtual at `0x004673f0` returns `0x18` with fourteen data xrefs. This matches compiler-emitted callback-object vtable support under the shared `FunctionObjects` family.
- `_purecall` at `0x005ca28c` has forty-nine data xrefs across abstract vtable slots and calls the CRT purecall handler before aborting. Treat it as runtime support referenced by the abstract `FunctionObject0` slot, not as a NexusTK-authored method body.
- Remaining gaps: final original header/source spelling for the template family, exact source declaration style for the duplicate emitted destructors, and complete callback-family mapping across every consumer.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0000AJ][PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_](by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md)
- [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md)
- [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/84`. Summary: zero-argument callback-base role, destructor variants, pure virtual slot, and related derived wrapper are documented with strong confidence; remaining gaps are final header/source template organization and full callback-family mapping. Evidence: related memory page `0x004671a0-0x004673f6`, `__purecall` range `0x005ca28c-0x005ca2a6`, and `PlainMemberFunctionObject0<Application>` cross-reference.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class is `72/84`, below the 80/80 parent-attachment gate, even though [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) remains the likely owner. Live IDA MCP `lookup_funcs` confirms exact starts for the destructor bodies at `0x004671f0` and `0x004672c0`, plus the pure virtual slot at `0x005ca28c`.
- 2026-06-06: Raised completion/confidence from `72/84` to `82/88` and attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) after live IDA reconfirmed exact destructor sizes, duplicate vtable-reset/base-cleanup/delete behavior, vtable-only reachability, the related zero-argument invoke/object-size slots, and the shared CRT `_purecall` distinction. Final C++ remains blank because the template/header declaration form is not at the 95/95 reconstruction gate.
- 2026-06-10 B001-014 exact-child split:
  - Before: this class documented the two destructor bodies by address but the broad [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) page still acted as the attached parent/container.
  - Changed to: raised completion to `85`, linked exact child pages [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) and [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md), and recorded that [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) is now a mixed non-emitting inventory.
  - Summary/evidence: live IDA MCP reconfirmed both exact destructor ranges, `FunctionObject0::vftable` writes, `0x004f4a90` cleanup, conditional delete through `0x004f4ac0`, vtable-only reachability, and the separate guard size constants.
