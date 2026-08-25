*** UID:0000AJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete PlainMemberFunctionObject0<Application> instantiation.
// The reusable declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md); the invoke and object-size helpers are covered by [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) and [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_

## Status

- Confidence: strong for zero-argument `Application` callback wrapper role.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support, instantiated by [UID:0000HG][Application](by-file/Application.md) paths.
- Related memory: [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md), now a non-emitting mixed inventory with exact callback children [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) and [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md). Read-only callback metadata is split as [UID:000486][0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer](by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md) and [UID:0003OF][0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData](by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md).
- Rebuild handling: source-declared/generated-binary; keep reusable template declarations under [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) and feature-specific construction in [UID:0000HG][Application](by-file/Application.md).
- Autogen parent: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md). Exact target [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) now carries a formal comment-only generated-template marker because current MCP evidence proves its vtable and [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md) construction route. Exact target [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) carries the sibling formal comment-only object-size marker because B008 MCP evidence proves the vtable slot and emitted `0x18` size helper. Broader template/header spelling remains below final source quality.
- Parent gate: this page now clears the active `85/85` gate for the exact invoke/object-size children, while [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) remains the source-family parent.

## Class Purpose

This compiler-emitted template instantiation binds a zero-argument `Application` member function to a small callback object. The source model belongs with the reusable FunctionObjects callback declarations, while the feature code that constructs concrete callbacks remains with `Application`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Invoke` | [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) | Applies the stored `this` adjustment and calls the captured `Application` member callback; the exact target emits a comment-only generated-template proof marker rather than a handwritten wrapper body. |
| `GetObjectSize` | [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) | Returns the 24-byte callback object size; B008 proves this is a compiler-emitted object-size virtual and records a target-level formal marker, not a handwritten `return 24;` body. |

## Evidence Notes

- IDA `lookup_funcs` confirms `0x004671a0` as a real `0x0d` byte function.
- IDA `xrefs_to 0x004671a0` and `0x004673f0` reports vtable/data references, not direct feature calls.
- The documented callback layout contains a callback pointer, bound object pointer bytes, `this` adjustment, and reserved size slot.
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) now has an explicit attachment policy for high-confidence generated `FunctionObject*` instantiations and records this wrapper as shared callback-template support rather than an original standalone source file.
- [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) and [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) now carry the exact child evidence for the two rows. [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) is a non-emitting mixed inventory.
- B002 MCP session `d4d50b81` rechecked [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) as `sub_4671A0` size `0x0d` with zero code refs/callers, data refs only, vtable slot `0x00612e4c -> 0x004671a0`, sibling object-size slot `0x00612e50 -> 0x004673f0`, and [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md) construction store `0x00464ec6` writing vtable `0x00612e40` into the 24-byte callback object.
- B008 MCP session `d4d50b81` rechecked [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) as `sub_4673F0` size `0x06`, bytes `b8 18 00 00 00 c3`, `return 24`, no callees, `0xcc` padding before/after, fourteen data-only vtable refs, and local vtable slot `0x00612e50 -> 0x004673f0`. This is vtable-dispatch metadata for the `PlainMemberFunctionObject0<Application>` object-size virtual, not dead code or a feature method.

## Ownership Boundaries

| Candidate owner | Decision | Evidence |
| --- | --- | --- |
| [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) | Parent/owner for reusable callback-template declarations and emitted support. | Shared callback-template policy, vtable-reached invoke/object-size rows, and related FunctionObject0 destructor support all route here. |
| [UID:0000HG][Application](by-file/Application.md) | Consumer/construction context only. | The bound member function belongs to `Application`, but the generic wrapper and object-size virtual are shared callback-template mechanics. |
| Standalone long generated class file | Rejected as source-file owner. | The long template spelling is a compiler-emitted instantiation name; final source should not create a one-off file from it. |

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `85` | The page records the callback-template role, exact child UID pages for invoke/object-size, FunctionObjects/Application ownership split, active parent-gate status, rebuild handling, related mixed-inventory container, and target-level comment-marker policy for [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md). It remains at the gate because final template declaration spelling, complete construction-site inventory, and original header shape remain open. |
| Confidence | `86` | IDA function-boundary and vtable/data-xref evidence, exact child pages, and FunctionObjects ownership policy support the interpretation. Confidence is below final because the template/header names and all construction contexts are still inferred rather than source-final. |

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:00005L][FunctionObject0](by-class/FunctionObject0.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:00000D][Application](by-class/Application.md)
- [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md)
- [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md)
- [UID:000486][0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer](by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md)
- [UID:0003OF][0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData](by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md)

## 2026-06-29 Empty-Emitter Closeout

This row is the direct concrete `PlainMemberFunctionObject0<Application>` instantiation anchor. The reusable declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md), while the generated invoke and object-size helpers are covered by [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) and [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md).

Current MCP evidence ties child data rows to this instantiation: UID000486 is the RTTI locator pointer at `0x00612e3c -> 0x0064222c`, and UID0003OF is the `??_7?$PlainMemberFunctionObject0@P8Application@@AEXXZV1@@@6B@` vtable at `0x00612e40-0x00612e54`. UID0003OF has slots `0x004671f0`, `0x004f4b10`, `0x0041b6c0`, `0x004671a0`, and `0x004673f0`, and its sole construction/data ref is `0x00464ec6` in the Application request-exit family. Those data rows are direct children of this instantiation after metadata repair.

## Changes

- 2026-06-29 B008 [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) implementation sync:
  - Score unchanged at `85/86`.
  - Merged UID00032C into the B002 UID000324 target-local marker policy on this support page.
  - Added B008 MCP session `d4d50b81` proof that [UID:00032C][0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize](by-memory/0x004673f0-0x004673f6.PlainMemberFunctionObject0ApplicationGetObjectSize.md) is a six-byte compiler-emitted object-size virtual reached through vtable/data refs, not handwritten `Application` logic.

- 2026-06-29 B002 UID000324 implementation sync:
  - Score unchanged at `85/86`.
  - Replaced stale old `95/95` blank-C++ gate wording with the current marker policy for [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md): the exact invoke wrapper may emit a formal comment-only generated-template proof because MCP session `d4d50b81` proves `sub_4671A0` size `0x0d`, zero code refs, data-only reachability, vtable `0x00612e40`, slot `0x00612e4c`, sibling object-size slot `0x00612e50`, and [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md) construction store `0x00464ec6`.
  - Preserved this class as shared `FunctionObjects` template support; [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md) remains the consumer/construction site.

- 2026-06-27 B004 00024T PlainMemberFunctionObject0<Application> data support sync:
  - Score unchanged at `85/86`.
  - Added exact RTTI/vtable children [UID:000486][0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer](by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md) and [UID:0003OF][0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData](by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md) to related memory and cross-references.

- 2026-06-03 parent attachment and rebuild disposition:
  - Before: scored `68/82` with blank reconstructable and parent metadata.
  - After: scored `74/84`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
  - Summary/evidence: the parent file's attachment policy covers generated `FunctionObject*` instantiations, the exact invoke and object-size rows are IDA/source-map backed, and the related memory container routes this compiler-emitted template support into `util/FunctionObjects.cpp`. This older blank-C++ note is superseded for [UID:000324][0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke](by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md) by the 2026-06-29 B002 comment-only generated-template marker policy.
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
