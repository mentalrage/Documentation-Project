*** UID:00005K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FunctionObject abstract callback base declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md).
// Scalar deleting destructor bytes such as [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) are compiler-generated from that declaration.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FunctionObject

## Status

- Confidence: strong for callback-base/destructor/vtable role after B001-0003LP confirmed the base vtable RTTI, destructor slot, and purecall slots; medium for final original header/source spelling.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Memory documentation: [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) as callback-template destructor support that enters this base cleanup, and [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md) as the base `FunctionObject::vftable` scalar deleting destructor child.
- Documentation basis: IDA-confirmed exact scalar deleting destructor boundaries, FunctionObject RTTI/vtable layout, purecall abstract slots, base/free callees, callback-family vtable reuse, the FunctionObject0 analogue, and the shared [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) source-family page.
- Final-source caveat: the binary evidence currently exposes the base destructor support and callback-family vtable reuse, while the final declaration shape should be driven by the callback template/source-family docs.
- Autogen parent: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md); C++ remains blank because the class is below the `95/95` reconstruction-code gate.
- Parent gate: this class now clears the corrected strict `85/85` gate after B001-0003LP added the base vtable/RTTI/purecall evidence. Exact base-class support pages may route through this class when they satisfy their own child-side gate. B001-000123 still routes the callback-template destructor page through the file-level [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) source family because that body is reused by concrete callback-template vtables rather than by the base `FunctionObject::vftable`.

## Class Purpose

`FunctionObject` is a small `LObject`-derived base for callback objects. The documented callback subclasses use this family to store and dispatch bound member-function callbacks, while the observed base-class machine code in this page is limited to scalar deleting destructor support.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| callback-template scalar deleting destructor support | [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) | Shared 24-byte callback-template destructor body that resets to `FunctionObject`, destroys `LObject`, and conditionally deletes storage; not the base vtable's own destructor slot. |
| base scalar deleting destructor | [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md) | Exact base `FunctionObject::vftable` scalar deleting destructor child. B001-0003LP confirms the base RTTI/vtable/purecall-slot layout and routes this child through this class. |

## Base Vtable Layout

B001-0003LP confirms the base `FunctionObject` vtable shape with live IDA MCP evidence:

| Address | Value | Meaning |
| --- | --- | --- |
| `0x006186a4` | `0x0064620c` | Complete-object locator named `??_R4FunctionObject@@6B@`. |
| `0x006186a8` | `0x0049b250` | Base `FunctionObject::vftable` scalar deleting destructor, documented by [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md). |
| `0x006186ac` | `0x004f4b10` | Shared support slot. |
| `0x006186b0` | `0x0041b6c0` | `nullsub_18` slot. |
| `0x006186b4` | `0x005ca28c` | `__purecall`, confirming an abstract callback-base slot. |
| `0x006186b8` | `0x005ca28c` | Second `__purecall` abstract callback-base slot. |

The base destructor body writes `FunctionObject::vftable`, calls the `LObject` cleanup helper, conditionally frees through the allocator/free helper on scalar-delete flags, and uses guard size `0x04`. That 4-byte guard path separates it from [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md), whose concrete callback-template vtable users and `0x18` guard size identify a 24-byte callback-template destructor support body.

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-05-25 confirms both starts as real `0x3e` byte functions.
- The duplicate bodies are likely compiler/vtable support emissions, not separate hand-written feature logic.
- 2026-06-03 IDA MCP `lookup_funcs` reconfirmed `0x0049b090` and `0x0049b250` as `0x3e` byte functions; `0x0049b0ce` and `0x0049b28e` are not independent function starts, matching exclusive function ends.
- 2026-06-03 IDA MCP `callers` returned no direct code callers for either destructor, while `xrefs_to` reported data/vtable references at `0x006187e8`, `0x0061a3b0`, `0x00620184`, `0x0062dde8`, and `0x006186a8`.
- 2026-06-03 IDA MCP `list_globals '*FunctionObject*'` identifies `0x006186a8` as `FunctionObject::vftable` and the other data xrefs as generated `PlainMemberFunctionObject` / `DoubleParamMemberFunctionObject` vtables that reuse the base destructor slot.
- 2026-06-03 IDA MCP decompilation/disassembly shows both bodies store `FunctionObject::vftable`, call `sub_4F4A90`, conditionally call `sub_4F4AC0` for heap deletion, and otherwise return `this`; the remaining `_guard_check_icall_nop` path is compiler/security glue for non-freeing delete-flag combinations.
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) and [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) document the reusable callback-template family, keeping this class in the shared utility source family rather than in feature-specific construction sites.
- 2026-06-13 B001-000123 recheck refines the earlier wording: `0x0049b090` is installed in concrete callback-template vtables and uses a 24-byte callback object size, while `0x0049b250` is the base `FunctionObject::vftable` slot. Treat [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) as FunctionObjects callback-template support and reserve the base-destructor conclusion for the sibling after separate research.
- 2026-06-13 B001-0003LP completes that sibling research: `0x0049b250` is an exact `0x3e` byte scalar deleting destructor with a sole destructor data xref from `0x006186a8`, which is named `FunctionObject::vftable`; the preceding vtable dword points to `FunctionObject` RTTI, and the following slots include `nullsub_18` plus two `__purecall` entries. This confirms the direct class-owner route for [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md).
- 2026-06-17 B002 VersatileAlertPane callback refresh: [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md) stores a shared callback pointer as `m_resultCallback` and invokes slot `+0x0c` with unsigned-long alert results. Cleanup/destructor paths call the callback object's slot `+0x00`, matching this shared base/destructor family rather than a pane-local interface.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `85` | The page now records the shared callback-base responsibility, source-file parent, exact base destructor child, callback-template destructor sibling, base RTTI/vtable/purecall layout, vtable-only reachability, callback-family vtable reuse, generated-output caveat, parent attachment gate, and final-C++ blocker. It remains below higher completion because the final header/template declaration shape and broader template hierarchy names are not source-final. |
| Confidence | `88` | IDA-backed function boundaries, sole base-vtable xref, RTTI locator, purecall slots, decompilation/disassembly, and the FunctionObjects/template pages strongly support the current ownership. Confidence is still capped below final source quality because original spelling and declaration structure remain inferred. |

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md)
- [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)

## 2026-06-29 Empty-Emitter Closeout

The abstract `FunctionObject` base declaration is covered by the central FunctionObjects template declaration block in [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md). This class row now emits only a covered-by marker so generated output no longer treats it as an empty emitter.

Current MCP revalidated [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) as a `0x3e`-byte scalar deleting destructor that resets `FunctionObject::vftable`, calls LObject cleanup support, and conditionally deletes. UID000123 is compiler-generated scalar deleting destructor glue, not a handwritten source body; its formal C++ block remains blank and its emitter route is cleared under the accepted scalar-destructor policy.

## Changes

- 2026-06-12 C001 barrier repair:
  - Score unchanged at `80/82`; updated memory documentation from a broad sparse destructor page to two exact destructor pages.
  - Corrected parent-gate wording: the exact destructor children remain parent-blank because this class does not clear the strict `85/85` gate.
- 2026-06-13 B001-000123 wording repair:
  - Score unchanged at `80/82`.
  - Clarified that [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) is shared 24-byte callback-template destructor support routed through [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), while sibling `0x0049b250` is the base `FunctionObject::vftable` destructor candidate.
- 2026-06-13 B001-0003LP parent repair:
  - Changed completion/confidence from `80/82` to `85/88`.
  - Added the confirmed base vtable layout, purecall slots, and exact base scalar deleting destructor child [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md).
  - Evidence: live IDA MCP confirms `0x006186a4 -> 0x0064620c` FunctionObject RTTI, `0x006186a8 -> 0x0049b250` destructor slot, `0x006186b4/0x006186b8 -> __purecall`, exact `0x0049b250-0x0049b28e` body, base cleanup/free callees, guard size `0x04`, and separation from the 24-byte callback-template sibling [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md).
- 2026-06-17 B002 VersatileAlertPane callback refresh:
  - Score unchanged at `85/88`.
  - Added `VersatileAlertPane::m_resultCallback` as another shared callback-family use while keeping final source declaration spelling deferred to the template/file pages.
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
- Completion/confidence score update: existed before as `0/0`; changed to `68/78`. Summary: callback-base role and duplicate destructor emissions are documented, but final source naming and broader callback hierarchy details remain incomplete. Evidence: exact destructor memory pages, IDA-confirmed function starts, and FunctionObject template cross-reference.
