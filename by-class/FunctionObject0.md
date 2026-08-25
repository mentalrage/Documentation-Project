*** UID:00005L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FunctionObject0 abstract zero-argument callback base declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md).
// Its RTTI and vtable ranges are compiler/linker-generated and covered by [UID:000482][0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer](by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md) and [UID:0003OE][0x0061262c-0x00612640.FunctionObject0VtableData](by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md).

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FunctionObject0

## Status

- Confidence: strong for zero-argument callback-base role.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Generated-output lead retained only for search context: `class_FunctionObject0.cpp`
- Related memory: [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md), now a non-emitting mixed container whose exact FunctionObject0 children are [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) and [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md); read-only data children are [UID:000482][0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer](by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md) and [UID:0003OE][0x0061262c-0x00612640.FunctionObject0VtableData](by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md).
- Rebuild handling: source-declared callback base with compiler-emitted vtable/destructor support.
- Scalar destructor policy: [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) and [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md) are intentional non-emitting source-declared/generated-binary metadata with blank `EMITTER_UIDS:` and blank formal C++; the compiler should regenerate the exact scalar deleting destructors from the shared `FunctionObject0` / FunctionObjects declaration. Do not use a handwritten destructor body or formal comment marker for scalar destructor glue.
- Parent handling: attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md); this page is now `85/88` and the parent file clears the active assignment gate for the exact destructor children.

## Class Purpose

`FunctionObject0` is the zero-argument callback-object base. It supplies destructor support and a pure-virtual slot used by derived callback wrappers such as the `Application` zero-argument member-function object.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) | scalar deleting destructor metadata | Resets the vtable, runs the base cleanup, and conditionally deletes storage depending on the MSVC deleting-destructor flag byte; guard-mode size constant is `0x18` / decimal `24`. B007 current MCP proof keeps this exact target non-emitting with blank formal C++ and blank `EMITTER_UIDS:`. |
| [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md) | scalar deleting destructor metadata | Base/small `FunctionObject0::vftable` scalar deleting destructor variant. B010 current MCP proof keeps this exact target non-emitting with blank formal C++ and blank `EMITTER_UIDS:`; it is the `0x04` / decimal `4` guard-size sibling to [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md), not a separate source body. |
| pure virtual call slot | `0x005ca28c-0x005ca2a7` | Shared CRT `_purecall` body used by abstract vtable slots; `FunctionObject0` owns the pure-virtual declaration, not this runtime helper implementation. |

## Evidence Notes

- Older generated output emits both destructor bodies and the pure-virtual helper, but the current score is based on IDA and existing documentation rather than generated source.
- IDA `lookup_funcs` confirms `0x005ca28c` as `__purecall` sized `0x1b`.
- The related `PlainMemberFunctionObject0<Application>` derived wrapper has an `Invoke` method at `0x004671a0` and an object-size virtual at `0x004673f0`.

## FunctionObject0 RTTI And Primary Vtable Closure

- Dated live MCP session `supervisor_uid0000od_rollbackverify_20260817` identifies [UID:000482][0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer](by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md) as the exact four-byte primary-vftable[-1] pointer. Bytes `e0 21 64 00`, SHA256 `A3F68AF9435AEF06EACE678C843830D3114FA98A88CF2C465E1C3D78E03C1F88`, decode to decorated complete-object locator `??_R4FunctionObject0@@6B@` at `0x006421e0`; the target has zero direct xrefs and its unique byte pattern occurs only once.
- The COL has signature/offset/cdOffset `0/0/0`, TypeDescriptor `0x006746bc`, and ClassHierarchyDescriptor `0x006421f4`. The TypeDescriptor payload is `.?AVFunctionObject0@@`. The CHD declares two bases; base-array order is the FunctionObject0 self descriptor at `0x00642210`, then the shared `LObject` descriptor at `0x00640348`. The self descriptor PMD is `{0,-1,0}` with attributes `0x40`.
- [UID:0003OE][0x0061262c-0x00612640.FunctionObject0VtableData](by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md) has SHA256 `62833EE08E31F1AE254B4622E593AE9D4F3070A0DC469258B89A28CEBECA9F7A` and exactly five slots: scalar deleting destructor `0x004672c0`, inherited `LObject::GetRuntimeClass` `0x004f4b10`, inherited `LObject::OnChangeMessage` `0x0041b6c0`, pure `Invoke` `0x005ca28c`, and pure `GetObjectSize` `0x005ca28c`.
- Vtable-head xrefs at `0x004671f6` and `0x004672c6` are the two compiler deleting-destructor variants. Their data-only vptr writes prove the compiler products are live even though the locator cell has no direct incoming xref.
- The five-slot order is regenerated by the sole source declaration in [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md): `FunctionObject0 : public LObject`, inline virtual destructor, pure `Invoke()`, and pure `GetObjectSize() const`. This class page owns the direct compiler-product children but does not duplicate that H declaration or emit raw RTTI/vtable storage.
- The formal `[[CHILDREN]]` directive immediately after the class-level covered-by marker projects the UID000482 locator marker followed by the UID0003OE vtable marker into `NexusTK/util/FunctionObjects.cpp`. Generated H continues to receive exactly one complete declaration through UID0001WQ.
- Range and ownership remain exact: UID000482 is one four-byte data item, UID0003OE is the following twenty-byte vtable, and [UID:00024T][0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData](by-memory/0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData.md) is only a mixed no-owner address index. Do not merge the siblings, assign Application ownership, clear reconstructability, author raw tables, or rename decorated ABI entities.
- Score remains `85/88` because this narrow closure resolves the primary RTTI/vtable pair but does not prove the complete callback-family map, exact historical header spelling, or all template-instantiation source organization.

## 2026-06-06 Live IDA Class Audit

- `lookup_funcs` reports exact function sizes for the local family: `0x004671a0` is `0x0d`, the two `FunctionObject0` scalar deleting destructors at `0x004671f0` and `0x004672c0` are each `0x3e`, the related object-size virtual at `0x004673f0` is `0x06`, and shared `_purecall` at `0x005ca28c` is `0x1b`.
- Decompilation and disassembly of both destructor bodies show the same source-level shape: write `FunctionObject0::vftable`, call the base cleanup at `0x004f4a90`, inspect the deleting-destructor flag byte, and call the delete/free helper at `0x004f4ac0` only when the ordinary delete bit is set and the guard-mode bit is clear.
- Both destructor bodies have no ordinary code callers. Their reachability is vtable/data based: `0x004671f0` has five data xrefs, while duplicate body `0x004672c0` has one data xref.
- B007 2026-06-29 current MCP session `d4d50b81` narrows [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md): `sub_4671F0` is exactly `0x3e` / decimal `62` bytes, resets `FunctionObject0::vftable` at `0x0061262c`, calls `sub_4F4A90`, `sub_4F4AC0`, and `@_guard_check_icall_nop@4`, uses scalar-delete flag gates and guard size `0x18` / decimal `24`, has callback vtable/data refs from `0x00612e40`, `0x0061d000`, `0x0061d238`, `0x0061fed8`, and `0x00630a78`, has no code callers/xrefs, and has no endpoint refs or endpoint pointer pattern at `0x0046722e`. This supports the semantic class-owner route but clears the exact target's emitter because scalar deleting destructor glue remains compiler-generated metadata.
- B010 2026-06-29 current MCP session `c9671f69` narrows [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md): `sub_4672C0` is exactly `0x3e` / decimal `62` bytes, range endpoint `0x004672fe` is not a function, the range is padded by nine `CC` bytes before and two `CC` bytes after, the body resets `FunctionObject0::vftable` from `0x0061262c`, calls `sub_4F4A90`, tests scalar-delete flags `1` and `4`, conditionally calls `sub_4F4AC0`, and reaches `@_guard_check_icall_nop@4` through guard size `0x04` / decimal `4`. MCP reports one data ref from `0x0061262c`, no code callers/xrefs, no endpoint refs, no raw endpoint pointer pattern, and no raw `0x004672fe` pointer. This keeps the class owner but keeps the exact target non-emitting with blank formal C++ and blank `EMITTER_UIDS:`.
- The sibling `PlainMemberFunctionObject0<Application>` invoke at `0x004671a0` has four data xrefs, and its object-size virtual at `0x004673f0` returns `0x18` with fourteen data xrefs. This matches compiler-emitted callback-object vtable support under the shared `FunctionObjects` family.
- `_purecall` at `0x005ca28c` has forty-nine data xrefs across abstract vtable slots and calls the CRT purecall handler before aborting. Treat it as runtime support referenced by the abstract `FunctionObject0` slot, not as a NexusTK-authored method body.
- Remaining gaps: final original header/source spelling for the template family, exact source declaration style for the duplicate emitted destructors, and complete callback-family mapping across every consumer.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0000AJ][PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_](by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md)
- [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md)
- [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md)
- [UID:000482][0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer](by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md)
- [UID:0003OE][0x0061262c-0x00612640.FunctionObject0VtableData](by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md)

## 2026-06-29 Empty-Emitter Closeout

The abstract zero-argument callback base declaration is covered by the central FunctionObjects declaration block in [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md). This class row now emits only a covered-by marker.

Current MCP evidence places the FunctionObject0 RTTI locator pointer at `0x00612628 -> 0x006421e0` and the `??_7FunctionObject0@@6B@` vtable at `0x0061262c-0x00612640`. UID0003OE slots are `0x004672c0`, `0x004f4b10`, `0x0041b6c0`, `0x005ca28c`, and `0x005ca28c`, with refs at `0x004671f6` and `0x004672c6`. UID000482 and UID0003OE are direct data children of this class row after metadata repair; they should not emit raw RTTI or vtable dwords.

## Changes

- 2026-08-17 B008 UID000482 source-quality callback:
  - Preserved `85/88` and the UID0000JO owner/emitter route.
  - Added complete locator/COL/hierarchy/vtable/source-declaration evidence and inserted `[[CHILDREN]]` after the existing class marker so direct UID000482 then UID0003OE compiler-product markers project into generated FunctionObjects CPP.

- 2026-06-29 B007 000327 scalar destructor metadata sync:
  - Score unchanged at `85/88`.
  - Added accepted [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) non-emitting scalar deleting destructor policy and current MCP session `d4d50b81` evidence.
  - Summary/evidence: `FunctionObject0` remains the semantic owner, but the exact [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) by-memory page clears `EMITTER_UIDS:` and keeps formal C++ blank because the shared class/template declaration should regenerate the compiler-emitted scalar deleting destructor body.
- 2026-06-29 B010 000328 scalar destructor metadata sync:
  - Score unchanged at `85/88`.
  - Added accepted [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md) non-emitting scalar deleting destructor policy and current MCP session `c9671f69` evidence.
  - Summary/evidence: `FunctionObject0` remains the semantic owner, but the exact [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md) page clears `EMITTER_UIDS:` and keeps formal C++ blank because it is compiler-emitted `FunctionObject0::vftable` scalar deleting destructor glue with guard size `0x04` / decimal `4`, no code callers/xrefs, and only the local vtable data reference.
- 2026-06-27 B004 00024T FunctionObject0 data support sync:
  - Score unchanged at `85/88`.
  - Added exact RTTI/vtable data children [UID:000482][0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer](by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md) and [UID:0003OE][0x0061262c-0x00612640.FunctionObject0VtableData](by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md) to related memory and cross-references.

- Completion/confidence score update: existed before as `0/0`; changed to `72/84`. Summary: zero-argument callback-base role, destructor variants, pure virtual slot, and related derived wrapper are documented with strong confidence; remaining gaps are final header/source template organization and full callback-family mapping. Evidence: related memory page `0x004671a0-0x004673f6`, `__purecall` range `0x005ca28c-0x005ca2a6`, and `PlainMemberFunctionObject0<Application>` cross-reference.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class is `72/84`, below the 80/80 parent-attachment gate, even though [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) remains the likely owner. Live IDA MCP `lookup_funcs` confirms exact starts for the destructor bodies at `0x004671f0` and `0x004672c0`, plus the pure virtual slot at `0x005ca28c`.
- 2026-06-06: Raised completion/confidence from `72/84` to `82/88` and attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) after live IDA reconfirmed exact destructor sizes, duplicate vtable-reset/base-cleanup/delete behavior, vtable-only reachability, the related zero-argument invoke/object-size slots, and the shared CRT `_purecall` distinction. Final C++ remains blank because the template/header declaration form is not at the 95/95 reconstruction gate.
- 2026-06-10 B001-014 exact-child split:
  - Before: this class documented the two destructor bodies by address but the broad [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) page still acted as the attached parent/container.
  - Changed to: raised completion to `85`, linked exact child pages [UID:000327][0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24](by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md) and [UID:000328][0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4](by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md), and recorded that [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) is now a mixed non-emitting inventory.
  - Summary/evidence: live IDA MCP reconfirmed both exact destructor ranges, `FunctionObject0::vftable` writes, `0x004f4a90` cleanup, conditional delete through `0x004f4ac0`, vtable-only reachability, and the separate guard size constants.
