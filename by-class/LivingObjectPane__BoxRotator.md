*** UID:00007C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Covered by LivingObjectPane::BoxRotator in UID00007B.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## B001 UID0002QY Accepted Callback Synchronization - 2026-07-14

- Final metadata is `90/93`, owner/emitter UID00007B, reconstructable true, and blank position. Destination 11 is the exact declaration-covered marker; the complete nested class is emitted once inside Destination 9.
- BoxRotator is an eight-byte private nested FrameHandler derivative with one LivingObjectPane owner pointer and the existing virtual Advance child. Decorated identity, constructor stores, delete size, adjusted callback, destructor, RTTI, and vtable evidence remain preserved.
- A duplicate top-level BoxRotator declaration/body, raw vtable array, deleting wrapper, adjustor, or explicit compiler teardown is rejected. Existing child work and unrelated historical evidence remain intact.

# LivingObjectPane::BoxRotator

## Status

- Canonical source-facing name: `LivingObjectPane::BoxRotator`.
- Generated/search name: `LivingObjectPane__BoxRotator`.
- Confidence: strong that the helper is a nested `LivingObjectPane` helper represented by the `BoxRotator@LivingObjectPane` vtable; strong that it follows the `FrameHandler` helper pattern; medium-high on the final declaration spelling and exact method/base names.
- Direct parent: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- Likely source file: [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- Parent attachment: attached to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md). The nested helper, direct class parent, and file root now all clear the strict `85/85` gate.
- Current recovered file: `source-3/simroot_v2/class_LivingObjectPane__BoxRotator.cpp`
- Address range: `0x0053d030-0x0053d052` in Wave3, `0x0053d030-0x0053d053` in IDA.
- Exact memory pages: [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) and [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md)
- Exact vtable page: [UID:000357][0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData](by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md)
- Reconstruction note: class-level C++ remains blank until the full `LivingObjectPane::BoxRotator` declaration is reviewed. Exact children carry source C++ or generated-wrapper markers: [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md) carries the source-authored callback body, and [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) carries the compiler-generated scalar deleting destructor marker covered by this class.

## Class Purpose

`LivingObjectPane__BoxRotator` is generated/search naming for a small `LivingObjectPane` nested helper. IDA references it from the `??_7BoxRotator@LivingObjectPane@@6B@` vtable, which supports the source-level name `LivingObjectPane::BoxRotator`.

The original source should model this as a nested/private `FrameHandler`-style helper declared inside or beside `LivingObjectPane`, not as a separate top-level gameplay file and not as a Boost-derived class. Constructor evidence stores the helper vptr at `LivingObjectPane + 0x1f0`, writes the owner pointer at `+0x1f4`, and initializes the owner rotation state at `+0x1ec`. The delete size `8` in [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) supports an 8-byte helper subobject: vptr plus `LivingObjectPane *m_owner`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| scalar deleting destructor | [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) | Compiler-generated virtual deleting-destructor ABI wrapper. It calls the FrameHandler destructor path at `0x004b6cb0`, tests scalar-delete flag bit `0`, conditionally releases the 8-byte helper object, and now emits only the formal covered-by marker for this class. |
| vtable slot callback | [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md) | Source-authored callback. It uses the owner pointer from `[this+4]`, advances `LivingObjectPane + 0x1ec` modulo four, calls the FrameHandler scheduling wrapper `0x004b6d30(this, 10)`, and refreshes/invalidates the owner through its virtual method at slot `0x20`. |

## Evidence Notes

- IDA confirms the scalar deleting destructor at `0x0053d030-0x0053d053` and the vtable-slot callback at `0x0053d7c0-0x0053d7f4`.
- IDA names the vtable `??_7BoxRotator@LivingObjectPane@@6B@`, making it a `LivingObjectPane` nested helper rather than unrelated frame infrastructure.
- `sub_53A110` and `sub_53A360` store the `BoxRotator` vtable base at `LivingObjectPane + 0x1f0`; the same construction paths store the owning `LivingObjectPane*` at `+0x1f4`.
- [UID:000357][0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData](by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md) records the exact RTTI/vtable range, the `0x0053d030` and `0x0053d7c0` slot targets, and the predecessor/successor boundaries.
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) records the same vtable and method boundary in the proposed `LivingObjectPane.cpp` source bucket.
- [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) keeps this destructor with the LivingObjectPane core while documenting non-Living object-pane overlap boundaries.
- B009's 2026-06-26 MCP session `80de0a67` confirms that [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) calls `0x004b6cb0`, whose current decompilation writes the `FrameHandler` vtable and unregisters through `g_frameRegistry`. That contradicts IDA's stale `boost::exception` destructor label and supports the FrameHandler-style helper model.
- Wave3 reports `LivingObjectPane__BoxRotator` grade `97.5` with one method, but current scores and parent decisions are based on IDA evidence and current project docs rather than generated-source trust.

## Rejected Alternatives

- Stale `boost::exception` inheritance/source naming is rejected as IDA type pollution on the FrameHandler destructor path.
- Generated standalone `LivingObjectPane__BoxRotator.cpp` is retained only as search/history wording; the source-facing route remains nested under `LivingObjectPane`.
- A handwritten `ScalarDeletingDestructor(char)` method is rejected. [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) is compiler-generated wrapper glue and its formal output is a covered-by marker, while [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md) is the source-authored callback child.
- A no-owner or file-only route is rejected because the decorated nested vtable, constructor stores, owner backlink, and sibling callback all identify the direct nested class owner.

## Autogen Status

- Marked reconstructable and attached to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) as the direct nested helper owner. This preserves the semantic parent chain: exact memory children attach to `LivingObjectPane::BoxRotator`, the helper attaches to `LivingObjectPane`, and `LivingObjectPane` attaches to [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md).
- Keep class-level generated source empty until a full source-quality declaration is accepted. Exact children may still emit: [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md) carries the callback body, and [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) carries a marker because the compiler should regenerate the scalar deleting destructor wrapper from this class declaration.

## Score Rationale

- Completion is raised to `88` because the page now records the direct nested class parent, exact destructor child with formal marker, exact vtable-data child, constructor subobject offsets, 8-byte layout inference, FrameHandler base relation, vtable-slot callback behavior, source-file placement, and rejected stale Boost/standalone routes.
- Confidence is raised to `91` because decorated RTTI/vtable name, constructor vptr/owner-pointer stores, exact method boundaries, owner-state callback behavior, and the current `0x004b6cb0` FrameHandler destructor evidence all support the same `LivingObjectPane::BoxRotator` interpretation.
- Confidence remains below final-source level because the original nested/private declaration text and exact method spellings are not final.

## Cross-References

- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md)
- [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md)
- [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md)
- [UID:000357][0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData](by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/74`. Summary: the small helper is well identified as `LivingObjectPane`-owned and likely nested/private, but the exact original declaration form remains medium confidence. Evidence: IDA function boundary, scalar deleting destructor behavior, and `??_7BoxRotator@LivingObjectPane@@6B@` vtable xref evidence.
- 2026-06-02: Raised from `72/74` to `82/84`, marked reconstructable, and attached to [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md).
  - Before: the page identified the helper but had no exact child page or autogen parent.
  - After: the page links exact destructor page [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md), the LivingObjectPane core aggregate, and the vtable-data group while keeping reconstructed C++ gated.
  - Evidence: IDA-recorded function boundary and `??_7BoxRotator@LivingObjectPane@@6B@` vtable xref evidence already captured in the file and memory documentation.
- 2026-06-12 A003 Batch270:
  - Raised `82/84` to `86/89` and changed the direct parent from file [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) to class [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md), which now clears `85/85`.
  - Added IDA-backed evidence for the `0x0062096c-0x00620978` exact vtable child, constructor subobject offset `+0x1f0`, owner pointer offset `+0x1f4`, owner state offset `+0x1ec`, and the `0x0053d7c0-0x0053d7f4` callback slot.
- 2026-06-18 B001 continuation:
  - Added exact callback child [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md) with first-draft `LivingObjectPane::BoxRotator::Advance` C++ and explicit vtable/no-direct-branch evidence.
- 2026-06-26 B009 implementation callback:
  - Raised `86/89` to `88/91`.
  - Incorporated the [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) report findings: the scalar deleting destructor is compiler-generated ABI glue covered by this class, the helper is FrameHandler-style, delete size `8` supports vptr plus owner pointer layout, and stale Boost/standalone generated-class routes are rejected.
