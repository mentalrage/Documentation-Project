*** UID:00005M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FunctionObjectT<StringBaseW> specialization is covered by the shared FunctionObjectT declaration in [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md).
// The scalar deleting destructor [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md) is compiler-generated and intentionally non-emitting.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____

## Status

- Confidence: strong for string-argument callback-base support.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Reconstruction parent: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Known method address: `0x0052a460-0x0052a49e`
- Reconstructable: true as emitted callback-template destructor support; C++ remains blank because the original source representation is the shared `FunctionObjectT<T>` declaration, while this exact scalar deleting destructor body is compiler/linker output.
- Parent gate: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), this class page, and exact memory child [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md) now clear the current documentation gate.

## Class Purpose

This is a compiler-emitted instantiation of `FunctionObjectT<mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>>`. The observed binary evidence for this class page is narrow: one scalar deleting destructor support body for the string-argument callback base.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| scalar deleting destructor | `0x0052a460-0x0052a49e` | Resets the `FunctionObjectT<StringBase>` vtable, destroys `LObject`, and conditionally deletes storage while respecting the `flags & 4` guard. |

## Destructor Evidence

| Evidence | Detail | Interpretation |
| --- | --- | --- |
| Exact memory page | [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md) | Confirms this page represents a single narrow destructor-support range. |
| IDA decompilation note | Decompilation writes the `FunctionObjectT<mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>>::vftable` before base cleanup. | The string spelling is type-parameter evidence for this callback template instantiation. |
| Base cleanup | The body calls the `LObject` base destructor helper after installing the local vtable. | Behavior matches `LObject`-derived callback object destruction, not string-buffer destruction. |
| Delete guard | Conditional storage delete follows scalar-deleting-destructor flag handling. | This is compiler-emitted destructor support, so direct feature callers are not expected. |
| Xref shape | Existing notes report vtable/data references and no normal direct callers for related callback destructor bodies. | Virtual dispatch metadata is the expected reference path for this family. |

## Evidence Notes

- This method is physically adjacent to [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md) callback support, including the folder-selection wrapper range in [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md) and the neighboring destructor wrapper in [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md).
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) documents this as one of the string-related generated `FunctionObjectT` destructor instantiations.
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) uses this generated vtable spelling as evidence for the `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>` type, but does not make the destructor a string module method.
- Existing string documentation previously flagged this generated file as template/deleting-destructor support rather than primary [UID:0000OB][StringUtil](by-file/StringUtil.md) ownership.
- 2026-06-14 C001 IDA MCP recheck against session `a001_goal2_class_batch` confirms `sub_52A460` size `0x3e`, no direct callers, callees `sub_4F4A90`, `sub_4F4AC0`, and guard-check support, and the vtable/data xref `0x0061fcd4 -> 0x0052a460`.
- The same recheck shows the destructor writes the `FunctionObjectT<mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>>::vftable`, calls `LObject`-style base cleanup, conditionally deletes object storage based on scalar-deleting flags, and is followed by padding before the neighboring callback destructor at `0x0052a4a0`.
- 2026-06-27 B006 accepted MCP session `398b87c1` reconfirms `sub_52A460` as an exact `0x3e`-byte scalar deleting destructor body at `0x0052a460-0x0052a49e`: it writes vtable slot `0x0061fcd4`, calls `sub_4F4A90`, conditionally calls `sub_4F4AC0`, has no direct code callers/refs, has only the `0x0061fcd4` data xref, has no pointer route to exclusive end `0x0052a49e`, and is followed by `CC CC` padding before the concrete MusicControlDialog callback destructor [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md).

## Ownership Boundaries

| Candidate owner | Decision | Evidence |
| --- | --- | --- |
| [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) | Parent/owner for reconstruction grouping. | Shared callback template page, client callback dispatch meta notes, and proposed source-tree placement all route reusable callback declarations/destructor support here. |
| [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) | Consumer/adjacency only. | The range sits beside MusicControlDialog folder callback wrappers, but the body is the generic string-argument callback base destructor. |
| [UID:0000OB][StringUtil](by-file/StringUtil.md) / [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) | Type evidence only. | The template parameter proves a `StringBase` callback argument; the cleanup path is `FunctionObjectT` plus `LObject`, not string utility logic. |

## Reconstruction Notes

- Keep the source model as a reusable `FunctionObjectT<T>` callback template declaration under [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
- Do not create a standalone feature file from the long generated class filename.
- Do not emit final C++ on this page. The destructor behavior and route are clear, but this exact body is scalar deleting destructor glue generated from the shared template declaration. The target-level no-code proof lives in [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md); handwritten or comment-only destructor C++ here would model compiler output rather than original human source.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `86` | The page records the string-argument callback-template role, parent file, exact destructor-support page, current IDA function/vtable evidence, ownership boundaries against MusicControlDialog/StringUtil/StringBase, source-declared/generated-binary handling, parent gate, and final C++ blocker. It remains below higher completion because the full original template/header declaration shape and final source spelling are still open. |
| Confidence | `88` | Current IDA decompilation, xrefs, byte-boundary evidence, exact memory-page evidence, FunctionObjects/template docs, and neighboring callback pages strongly support the owner and behavior. Confidence remains below near-final because original template/header spelling and generated-wrapper emission shape remain inferred. |

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md)
- [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md)
- [UID:00005N][FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___](by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)

## 2026-06-29 Empty-Emitter Closeout

This row is a typed specialization evidence page for `FunctionObjectT<StringBaseW>`. The reusable source declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md), so this row now carries a covered-by marker instead of a duplicated declaration.

Current MCP revalidated [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md) as a `0x3e`-byte compiler scalar deleting destructor with a single vtable-data ref at `0x0061fcd4`, no normal code caller route, and the same cleanup/delete scalar-destructor structure as the rest of the FunctionObjects glue. UID0001CQ is intentionally non-emitting with a blank formal block.

## Changes

- 2026-06-02 documentation pass:
  - What existed before: `COMPLETION:66`, `CONFIDENCE:82`, blank reconstructable flag, and no parent metadata.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and legacy parent metadata for [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
  - Summary/evidence: attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) after parent confidence was raised to the project threshold from shared callback-template evidence. Added exact memory-page evidence, destructor behavior, ownership boundaries, string-type relationship notes, and MusicControlDialog adjacency caveats. C++ remained blank because the page was below the then-current source-entry threshold.
- 2026-06-06 A004 parent-gate cleanup:
  - Changed completion from `74` to `80`; confidence remains `86`.
  - Removed generated-source path framing, added parent-gate status and score rationale, and clarified this as compiler-emitted callback-template destructor support.
  - Evidence: [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md), [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), and [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) support the shared callback-template ownership while final source remained blocked by source-shape uncertainty.
- 2026-06-14 C001 Goal 2 IDA refresh:
  - Before: `80/86`, with stale final-code and old parent-threshold wording.
  - After: `86/88`, with current IDA 9.1 evidence for function size, vtable slot, no direct callers, scalar-deleting flag behavior, base cleanup/delete callees, and neighboring callback-wrapper separation. Owner/emitter routing remains [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md); final C++ stays blank until the original template/header form is source-quality.
- 2026-06-27 B006 0001CQ support sync:
  - Score unchanged at `86/88`.
  - Added current MCP session `398b87c1` proof for exact range, vtable slot `0x0061fcd4`, vtable-only reachability, endpoint padding, and the blank formal C++ policy for scalar deleting destructor glue. This class page keeps [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) ownership and treats [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) as type spelling evidence only.
- Completion/confidence score update: existed before as `0/0`; changed to `66/82`. Summary: generated string-argument callback template purpose and scalar destructor behavior are documented, but the page is intentionally narrow and does not yet recover the full template/header structure. Evidence: destructor range `0x0052a460-0x0052a49e`, MusicControlDialog adjacency, and FunctionObject template documentation.
