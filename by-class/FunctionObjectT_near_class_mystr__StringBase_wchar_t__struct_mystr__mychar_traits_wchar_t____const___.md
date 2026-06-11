*** UID:00005N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___

## Status

- Confidence: strong for const-reference string callback-base support.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Reconstruction parent: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Related memory: [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md)
- Reconstructable: true as emitted callback-template destructor support; C++ remains blank under the project-level 95/95 source-quality gate.
- Parent gate: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) is above `80/80`, and this page now clears the child-side threshold for source-family attachment.
- Rebuild handling: `source-declared/generated-binary`; source should provide the shared callback-template declaration/destructor semantics, while the compiler/linker emits these concrete destructor bodies.

## Class Purpose

This is a compiler-emitted instantiation of `FunctionObjectT<const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>&>`. Observed binary evidence exposes destructor support for const-reference string callback bases used by dialog callback vtables.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| scalar deleting destructor | `0x0052f780-0x0052f7be` | Resets the local function-object vtable, destroys the base callback object, and conditionally deletes storage while respecting the `flags & 4` guard. |
| scalar deleting destructor | `0x0052f7c0-0x0052f7fe` | Similar emitted destructor body for `PlainMemberFunctionObjectT<..., const StringBase&>` vtables; live IDA shows the same `flags & 4` scalar-delete guard. |

## Destructor Evidence

| Evidence | Detail | Interpretation |
| --- | --- | --- |
| Exact memory page | [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) | Confirms this page represents two narrow emitted destructor-support ranges. |
| IDA function bounds | `lookup_funcs` on 2026-06-03 reports `sub_52F780` and `sub_52F7C0`, each size `0x3e`. | Both rows are real modeled functions, not padding or arbitrary data. |
| Vtable refs | `xrefs_to` reports `0x0052f780` from `0x0061ff58` and `0x0052f7c0` from `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4`. | These are virtual destructor entries for const-reference string callback-template vtables. |
| Decompilation shape | Both functions write `off_61FF58`, call base cleanup `sub_4F4A90`, then conditionally call delete helper `sub_4F4AC0` when scalar-delete flags request deletion and do not set `flags & 4`. | Behavior is compiler-emitted callback-template destructor support, not string-buffer logic. |
| Caller shape | `callers` reports no direct code callers for either destructor. | Vtable dispatch/data references are the expected reference path for this family. |

IDA reads of the vtable data show `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4` are `PlainMemberFunctionObjectT<..., const StringBase&>` vtables for create-user / Nexonclub dialog callback contexts. This supports grouping the reusable template declarations under [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), while leaving feature-specific construction and callback targets in the owning dialog modules.

## Ownership Boundaries

| Candidate owner | Decision | Evidence |
| --- | --- | --- |
| [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) | Parent/owner for reconstruction grouping. | Shared callback template page, client callback dispatch meta notes, and proposed source-tree placement all route reusable callback declarations/destructor support here. |
| create-user / Nexonclub dialog modules | Consumer/instantiation contexts only. | Vtable names identify concrete dialog callback consumers, but the destructor body is generic callback-template support. |
| [UID:0000OB][StringUtil](by-file/StringUtil.md) / [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) | Type evidence only. | The template parameter proves a `StringBase` const-reference argument; the cleanup path is function-object plus base callback cleanup, not string utility logic. |

## Reconstruction Notes

- Keep the source model as reusable `FunctionObjectT<T>` / `PlainMemberFunctionObjectT<...>` callback template declarations under [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
- Do not create a standalone feature file from the long emitted class filename.
- Do not emit final C++ on this page yet. The destructor behavior is clear, but the final template declaration names and all construction sites are not proven to the project 95/95 threshold.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `80` | The page now records the const-reference string callback-template role, exact destructor-support page, IDA bounds/xref/caller evidence, FunctionObjects parent gate, ownership boundaries against create-user/Nexonclub/StringUtil/StringBase, source-declared/generated-binary handling, and final C++ blocker. It remains below higher completion because the original template/header declaration spelling and all construction sites remain open. |
| Confidence | `88` | IDA function bounds, vtable xrefs, no-direct-caller shape, decompilation behavior, and related FunctionObjects/template docs strongly support the interpretation. Confidence stays unchanged because final source spelling and exact emitted-template split are still inferred. |

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md)
- [UID:00005M][FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____](by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)

## Changes

- 2026-06-03 documentation pass:
  - What existed before: `COMPLETION:70`, `CONFIDENCE:82`, blank reconstructable flag, blank autogen parent, and only short evidence notes.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JO`.
  - Summary/evidence: live IDA MCP reconfirmed both destructor functions at `0x0052f780` and `0x0052f7c0` as `0x3e`-byte modeled functions, with no direct callers, vtable/data xrefs, base cleanup through `sub_4F4A90`, conditional scalar delete through `sub_4F4AC0`, and the same `flags & 4` guard shape in both bodies. Parent attachment is justified by the already documented `FunctionObjects` parent policy; final C++ stays blank because template declarations and construction sites remain below the 95/95 gate.
- 2026-06-06 A004 parent-gate cleanup:
  - Changed completion from `78` to `80`; confidence remains `88`.
  - Added parent-gate status, source-declared/generated-binary rebuild handling, score rationale, and clarified compiler-emitted callback-template wording.
  - Evidence: [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md), [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), and [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) support shared callback-template ownership while final source remains below the code gate.
- Completion/confidence score update: existed before as `0/0`; changed to `70/82`. Summary: const-reference string callback-template purpose, destructor variants, vtable-reference evidence, and generated-support caveat are documented; full template split and exact vtable distinction remain open. Evidence: memory page `0x0052f780-0x0052f7fe`, IDA vtable xref note, and FunctionObject template documentation.
