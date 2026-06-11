*** UID:0000AJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_

## Status

- Confidence: strong for zero-argument `Application` callback wrapper role.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support, instantiated by [UID:0000HG][Application](by-file/Application.md) paths.
- Related memory: [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md), now a non-emitting mixed inventory with exact callback children [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) and [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md).
- Rebuild handling: source-declared/generated-binary; keep reusable template declarations under [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) and feature-specific construction in [UID:0000HG][Application](by-file/Application.md).
- Autogen parent: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md); C++ remains blank because final template declaration spelling and construction-site coverage are below the `95/95` reconstruction-code gate.
- Parent gate: this page now clears the active `85/85` gate for the exact invoke/object-size children, while [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) remains the source-family parent.

## Class Purpose

This compiler-emitted template instantiation binds a zero-argument `Application` member function to a small callback object. The source model belongs with the reusable FunctionObjects callback declarations, while the feature code that constructs concrete callbacks remains with `Application`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Invoke` | [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) | Applies the stored `this` adjustment and calls the captured `Application` member callback. |
| `GetObjectSize` | [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) | Returns the 24-byte callback object size. |

## Evidence Notes

- IDA `lookup_funcs` confirms `0x004671a0` as a real `0x0d` byte function.
- IDA `xrefs_to 0x004671a0` and `0x004673f0` reports vtable/data references, not direct feature calls.
- The documented callback layout contains a callback pointer, bound object pointer bytes, `this` adjustment, and reserved size slot.
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) now has an explicit attachment policy for high-confidence generated `FunctionObject*` instantiations and records this wrapper as shared callback-template support rather than an original standalone source file.
- [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) and [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) now carry the exact child evidence for the two rows. [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) is a non-emitting mixed inventory.

## Ownership Boundaries

| Candidate owner | Decision | Evidence |
| --- | --- | --- |
| [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) | Parent/owner for reusable callback-template declarations and emitted support. | Shared callback-template policy, vtable-reached invoke/object-size rows, and related FunctionObject0 destructor support all route here. |
| [UID:0000HG][Application](by-file/Application.md) | Consumer/construction context only. | The bound member function belongs to `Application`, but the generic wrapper and object-size virtual are shared callback-template mechanics. |
| Standalone long generated class file | Rejected as source-file owner. | The long template spelling is a compiler-emitted instantiation name; final source should not create a one-off file from it. |

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `85` | The page now records the callback-template role, exact child UID pages for invoke/object-size, FunctionObjects/Application ownership split, active parent-gate status, rebuild handling, related mixed-inventory container, and final C++ blocker. It remains at the gate because final template declaration spelling, allocation/construction sites, and complete original header shape remain open. |
| Confidence | `86` | IDA function-boundary and vtable/data-xref evidence, exact child pages, and FunctionObjects ownership policy support the interpretation. Confidence is below final because the template/header names and all construction contexts are still inferred rather than source-final. |

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:00005L][FunctionObject0](by-class/FunctionObject0.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:00000D][Application](by-class/Application.md)
- [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md)
- [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md)

## Changes

- 2026-06-03 parent attachment and rebuild disposition:
  - Before: scored `68/82` with blank reconstructable and parent metadata.
  - After: scored `74/84`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
  - Summary/evidence: the parent file's attachment policy covers generated `FunctionObject*` instantiations, the exact invoke and object-size rows are IDA/source-map backed, and the related memory container routes this compiler-emitted template support into `util/FunctionObjects.cpp`. C++ remains blank until final source-facing template declarations and construction-site coverage reach the `95/95` gate.
- 2026-06-06 A004 parent-gate cleanup:
  - Changed completion from `74` to `80`; confidence remains `84`.
  - Removed stale generated-source path framing, added parent-gate status, ownership boundaries, and score rationale.
  - Evidence: IDA-confirmed invoke/object-size rows, [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md), and [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) support shared callback-template ownership while final source remains below the code gate.
- 2026-06-10 B001-014 exact-child split:
  - Before: this page pointed at the broad [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) container for its two concrete methods and remained below the active `85/85` direct-parent gate.
  - Changed to: scores `85/86`, exact child links [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) and [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md), and updated parent-gate wording.
  - Summary/evidence: live IDA MCP reconfirmed exact sizes, the invoke tail-call through stored callback fields, the object-size constant `0x18`, and vtable/data-only reachability for both rows.

- Before: completion/confidence metadata were `0/0` despite the page documenting this as a zero-argument `Application` callback wrapper with concrete invoke and size virtuals.
- Changed to: `COMPLETION:68` and `CONFIDENCE:82`.
- Evidence: IDA-confirmed function starts, vtable/data xrefs, object-size virtual, generated callback layout, and `FunctionObjects`/`Application` placement are documented; completion remains moderate because the exact allocation/caller context and original template instantiation naming are not exhaustive.
