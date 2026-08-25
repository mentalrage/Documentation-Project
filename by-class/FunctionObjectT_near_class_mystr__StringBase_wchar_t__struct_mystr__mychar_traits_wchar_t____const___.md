*** UID:00005N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FunctionObjectT<const StringBaseW&> specialization is covered by the shared FunctionObjectT declaration in [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md).
// Concrete string callback wrappers are documented on their direct instantiation and vtable rows.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___

## Status

- Confidence: strong for const-reference string callback-base support and FunctionObjects routing.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Reconstruction parent: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- Related memory: [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md)
- Reconstructable: true as emitted callback-template destructor support; target-level scalar deleting destructor pages remain non-emitting metadata with blank formal C++ and, for [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md), blank `EMITTER_UIDS:`.
- Parent gate: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) is above `80/80`, and this page now clears the child-side threshold for source-family attachment.
- Rebuild handling: `source-declared/generated-binary`; source should provide the shared callback-template declaration/destructor semantics, while the compiler/linker emits these concrete destructor bodies.

## Class Purpose

This is a compiler-emitted instantiation of `FunctionObjectT<const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>&>`. Observed binary evidence exposes destructor support for const-reference string callback bases used by dialog callback vtables.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| scalar deleting destructor | `0x0052f780-0x0052f7be` | Complete `0x3e` / decimal `62` function. Resets the local function-object vtable, destroys the base callback object, and conditionally deletes storage with delete-size immediate `4` through the scalar deleting flag gate. |
| scalar deleting destructor | `0x0052f7c0-0x0052f7fe` | Complete `0x3e` / decimal `62` function for `PlainMemberFunctionObjectT<..., const StringBase&>` vtables. It has the same cleanup/guard shape and delete-size immediate `0x18` / decimal `24`. |

## Destructor Evidence

| Evidence | Detail | Interpretation |
| --- | --- | --- |
| Exact memory page | [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) | Confirms this page represents two narrow emitted destructor-support ranges. |
| B007 current MCP pass | Session `b009_0001Q4_20260628` confirmed `sub_52F780` and `sub_52F7C0` as exact `0x3e` / decimal `62` functions, confirmed healthy Hex-Rays/strings state, and made no IDA DB edits. | Current evidence supports non-emitting metadata, not a formal emitted source body. |
| IDA function bounds | `lookup_funcs` on 2026-06-03 reports `sub_52F780` and `sub_52F7C0`, each size `0x3e`. | Both rows are real modeled functions, not padding or arbitrary data. |
| Vtable refs | `xrefs_to` reports `0x0052f780` from `0x0061ff58` and `0x0052f7c0` from `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4`. | These are virtual destructor entries for const-reference string callback-template vtables. |
| Decompilation shape | Both functions write `off_61FF58`, call base cleanup `sub_4F4A90`, pass through `@_guard_check_icall_nop@4`, then conditionally call delete helper `sub_4F4AC0`; the delete-size immediates are `4` and `0x18` / decimal `24`. | Behavior is compiler-emitted callback-template destructor support, not string-buffer logic. |
| Caller shape | `callers` reports no direct code callers for either destructor. | Vtable dispatch/data references are the expected reference path for this family. |
| Endpoint negative evidence | B007 confirms `0x0052f7be` and `0x0052f7fe` are not functions, have no refs, and have no discovered pointer patterns. | The range is exactly two complete functions, not a split/container or hidden endpoint target. |

IDA reads of the vtable data show `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4` are `PlainMemberFunctionObjectT<..., const StringBase&>` vtables for create-user / Nexonclub dialog callback contexts. This supports grouping the reusable template declarations under [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), while leaving feature-specific construction and callback targets in the owning dialog modules.

Live IDA MCP on 2026-06-14, session `a001_goal2_class_batch`, reconfirmed both destructor functions: `sub_52F780` and `sub_52F7C0` are each size `0x3e`, have no direct code callers, call `sub_4F4A90`, conditionally call `sub_4F4AC0` only when scalar-delete flags allow it, and include the guard-check thunk. The xref split remains one vtable ref for `0x0052f780` at `0x0061ff58`, and four vtable refs for `0x0052f7c0` at `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4`.

B007 live MCP on 2026-06-28 ties the concrete vtables to construction sites without moving ownership: `sub_52B650` uses vtable `0x0061ff70` and member target `sub_52B730`, `sub_52D100` uses `0x0062004c` and `sub_52D1E0`, `sub_52E970` uses `0x00620094` and `sub_52EA50`, and `sub_553610` uses `0x00622cf4` and `sub_5534A0`; each path allocates a `0x18` callback object and passes it to `sub_52F950`.

## Ownership Boundaries

| Candidate owner | Decision | Evidence |
| --- | --- | --- |
| [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) | Parent/owner for reconstruction grouping. | Shared callback template page, client callback dispatch meta notes, and proposed source-tree placement all route reusable callback declarations/destructor support here. |
| create-user / Nexonclub dialog modules | Consumer/instantiation contexts only. | Vtable names identify concrete dialog callback consumers, but the destructor body is generic callback-template support. |
| [UID:0000OB][StringUtil](by-file/StringUtil.md) / [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) | Type evidence only. | The template parameter proves a `StringBase` const-reference argument; the cleanup path is function-object plus base callback cleanup, not string utility logic. |

## Reconstruction Notes

- Keep the source model as reusable `FunctionObjectT<T>` / `PlainMemberFunctionObjectT<...>` callback template declarations under [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
- Do not create a standalone feature file from the long emitted class filename.
- Do not emit a formal destructor body or formal comment marker for the scalar deleting destructor glue. The target-level [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) metadata is intentionally blank-emitter/blank-formal C++ so generated `FunctionObjects.cpp` does not receive artificial source text for compiler-emitted destructor bodies.
- Generated class coverage resolves the current owner route through [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md). Keep this as source-declared/generated-binary support rather than feature-owned dialog code or StringBase/StringUtil source.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `85` | The page records the const-reference string callback-template role, exact destructor-support page, current MCP bounds/xref/caller evidence, endpoint negative evidence, FunctionObjects parent route, ownership boundaries against create-user/Nexonclub/StringUtil/StringBase, source-declared/generated-binary handling, and the accepted blank-emitter scalar-destructor policy. It remains below higher completion because the original template/header declaration spelling remains broader FunctionObjects work. |
| Confidence | `90` | Current MCP function bounds, vtable xrefs, no-direct-caller shape, endpoint negatives, decompilation behavior, construction-site evidence, and related FunctionObjects/template docs strongly support the interpretation. Confidence is capped below final audit because final source spelling and exact emitted-template split are still inferred. |

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md)
- [UID:00005M][FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____](by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)

## 2026-06-29 Empty-Emitter Closeout

This row remains a typed specialization evidence page, not a duplicated template declaration. The reusable `FunctionObjectT` declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md), and concrete const-string callback wrappers are documented on their direct instantiation and vtable rows.

The accepted scalar-destructor policy remains unchanged for generated const-string destructor glue: scalar deleting destructor pages should stay source-declared/generated-binary with blank formal C++ and blank `EMITTER_UIDS` unless a later supervisor explicitly approves a different marker policy.

## Changes

- 2026-06-28 B007 0001CS empty-emitter source-quality sync:
  - Score unchanged at `85/90`.
  - Evidence: live MCP session `b009_0001Q4_20260628` reconfirmed the two `0x3e` / decimal `62` destructor bodies, vtable/data refs at `0x0061ff58`, `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4`, no direct callers, endpoint non-functions/no refs/no pointer patterns, `off_61FF58` vtable reset, calls to `sub_4F4A90`, `sub_4F4AC0`, and `@_guard_check_icall_nop@4`, delete-size immediates `4` and `0x18` / decimal `24`, and create-user/Nexonclub construction sites.
  - Routing: [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) remains FunctionObjects source-family metadata with blank formal C++ and blank `EMITTER_UIDS:`; no formal destructor body, formal comment marker, `[[CHILDREN]]`, split, StringBase/StringUtil owner, or feature-dialog owner is recommended.

- 2026-06-14 A003 Goal 2 low-score by-class refresh:
  - Raised completion/confidence from `80/88` to `85/90`.
  - Evidence: live IDA MCP reconfirmed both `0x3e`-byte destructor bodies, no direct callers, vtable refs at `0x0061ff58`, `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4`, base cleanup through `sub_4F4A90`, scalar delete through `sub_4F4AC0`, and the shared `flags & 4` guard shape.
  - Routing: owner/emitter remains [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), generated through `auto-generated/NexusTK/util/FunctionObjects.cpp`; C++ remains blank because final template/header spelling is still not source-quality.

- 2026-06-03 documentation pass:
  - What existed before: `COMPLETION:70`, `CONFIDENCE:82`, blank reconstructable flag, blank autogen parent, and only short evidence notes.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JO`.
  - Summary/evidence: live IDA MCP reconfirmed both destructor functions at `0x0052f780` and `0x0052f7c0` as `0x3e`-byte modeled functions, with no direct callers, vtable/data xrefs, base cleanup through `sub_4F4A90`, conditional scalar delete through `sub_4F4AC0`, and the same `flags & 4` guard shape in both bodies. Parent attachment is justified by the already documented `FunctionObjects` parent policy; final C++ stays blank because template declarations and construction sites remain below the 95/95 gate.
- 2026-06-06 A004 parent-gate cleanup:
  - Changed completion from `78` to `80`; confidence remains `88`.
  - Added parent-gate status, source-declared/generated-binary rebuild handling, score rationale, and clarified compiler-emitted callback-template wording.
  - Evidence: [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md), [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), and [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) support shared callback-template ownership while final source remains below the code gate.
- Completion/confidence score update: existed before as `0/0`; changed to `70/82`. Summary: const-reference string callback-template purpose, destructor variants, vtable-reference evidence, and generated-support caveat are documented; full template split and exact vtable distinction remain open. Evidence: memory page `0x0052f780-0x0052f7fe`, IDA vtable xref note, and FunctionObject template documentation.
