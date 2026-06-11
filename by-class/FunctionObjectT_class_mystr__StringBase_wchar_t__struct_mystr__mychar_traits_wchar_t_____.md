*** UID:00005M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____

## Status

- Confidence: strong for string-argument callback-base support.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Reconstruction parent: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Known method address: `0x0052a460-0x0052a49e`
- Reconstructable: true as emitted callback-template destructor support; C++ remains blank under the project-level 95/95 source-quality gate.
- Parent gate: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) is above `80/80`, and this page now clears the child-side threshold for source-family attachment.

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

## Ownership Boundaries

| Candidate owner | Decision | Evidence |
| --- | --- | --- |
| [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) | Parent/owner for reconstruction grouping. | Shared callback template page, client callback dispatch meta notes, and proposed source-tree placement all route reusable callback declarations/destructor support here. |
| [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) | Consumer/adjacency only. | The range sits beside MusicControlDialog folder callback wrappers, but the body is the generic string-argument callback base destructor. |
| [UID:0000OB][StringUtil](by-file/StringUtil.md) / [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) | Type evidence only. | The template parameter proves a `StringBase` callback argument; the cleanup path is `FunctionObjectT` plus `LObject`, not string utility logic. |

## Reconstruction Notes

- Keep the source model as a reusable `FunctionObjectT<T>` callback template declaration under [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
- Do not create a standalone feature file from the long generated class filename.
- Do not emit final C++ on this page yet. The destructor behavior is clear, but final-source-quality names and template structure are not proven to the project 95/95 threshold.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `80` | The page now records the string-argument callback-template role, parent file, exact destructor-support page, ownership boundaries against MusicControlDialog/StringUtil/StringBase, source-declared/generated-binary handling, parent gate, and final C++ blocker. It remains below higher completion because the full original template/header declaration shape and final source spelling are still open. |
| Confidence | `86` | IDA decompilation, exact memory-page evidence, FunctionObjects/template docs, and neighboring callback pages strongly support the owner and behavior. Confidence stays unchanged because final source names and header structure remain unresolved. |

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

## Changes

- 2026-06-02 documentation pass:
  - What existed before: `COMPLETION:66`, `CONFIDENCE:82`, blank reconstructable flag, and no autogen parent.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JO`.
  - Summary/evidence: attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) after parent confidence was raised to the project threshold from shared callback-template evidence. Added exact memory-page evidence, destructor behavior, ownership boundaries, string-type relationship notes, and MusicControlDialog adjacency caveats. C++ remains blank because the page is below the final-source reconstruction threshold.
- 2026-06-06 A004 parent-gate cleanup:
  - Changed completion from `74` to `80`; confidence remains `86`.
  - Removed generated-source path framing, added parent-gate status and score rationale, and clarified this as compiler-emitted callback-template destructor support.
  - Evidence: [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md), [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), and [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) support the shared callback-template ownership while final source remains below the code gate.
- Completion/confidence score update: existed before as `0/0`; changed to `66/82`. Summary: generated string-argument callback template purpose and scalar destructor behavior are documented, but the page is intentionally narrow and does not yet recover the full template/header structure. Evidence: destructor range `0x0052a460-0x0052a49e`, MusicControlDialog adjacency, and FunctionObject template documentation.
