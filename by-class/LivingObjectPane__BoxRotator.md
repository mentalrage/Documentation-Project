*** UID:00007C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LivingObjectPane__BoxRotator

## Status

- Confidence: strong that the helper is tied to `LivingObjectPane` and represented by the `BoxRotator@LivingObjectPane` vtable; medium on the final declaration shape inside the original source.
- Likely source file: [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- Parent attachment: attached to [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), whose current confidence is `80`.
- Current recovered file: `source-3/simroot_v2/class_LivingObjectPane__BoxRotator.cpp`
- Address range: `0x0053d030-0x0053d052` in Wave3, `0x0053d030-0x0053d053` in IDA.
- Exact memory page: [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md)
- Reconstruction note: C++ intentionally left blank until the surrounding `LivingObjectPane` class layout and helper declaration form are near-final.

## Class Purpose

`LivingObjectPane__BoxRotator` is Wave3's standalone name for a small `LivingObjectPane` helper that destroys a frame-handler style rotator object. IDA references it from the `??_7BoxRotator@LivingObjectPane@@6B@` vtable, which supports the source-level name `LivingObjectPane::BoxRotator`.

The original source should probably model this as a nested/private helper declared near `LivingObjectPane`, not as a separate top-level gameplay file.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| scalar deleting destructor | [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) | Calls `FrameHandler` cleanup and conditionally deletes the helper object. |

## Evidence Notes

- Wave3 reports `LivingObjectPane__BoxRotator` grade `97.5` with one method.
- IDA confirms a function at `0x0053d030-0x0053d053`.
- IDA xref sample points to `??_7BoxRotator@LivingObjectPane@@6B@`, making it a `LivingObjectPane` nested helper rather than unrelated frame infrastructure.
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) records the same vtable and method boundary in the proposed `LivingObjectPane.cpp` source bucket.
- [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) keeps this destructor with the LivingObjectPane core while documenting non-Living object-pane overlap boundaries.
- [UID:0002SN][0x00620954-0x00620b88.MotionLivingLightSoundObjectPaneVtableData](by-memory/0x00620954-0x00620b88.MotionLivingLightSoundObjectPaneVtableData.md) records the grouped read-only vtable data containing `LivingObjectPane::BoxRotator`.

## Autogen Status

- Marked reconstructable and attached to the `LivingObjectPane` source bucket after the child evidence raised this page above the `80` confidence attachment gate.
- Keep generated source empty until the page reaches the 95+ reconstruction gate; current evidence is enough for ownership and coverage, not final C++.

## Score Rationale

- Completion increased because the page now has a dedicated exact memory child, source-bucket parent, core aggregate evidence, and vtable-data cross-reference.
- Confidence increased because the decorated vtable name, exact boundary, and matching parent file evidence all support `LivingObjectPane::BoxRotator` ownership.
- Confidence remains below final-source level because the original nested/private declaration form and field/base naming are not final.

## Cross-References

- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md)
- [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md)
- [UID:0002SN][0x00620954-0x00620b88.MotionLivingLightSoundObjectPaneVtableData](by-memory/0x00620954-0x00620b88.MotionLivingLightSoundObjectPaneVtableData.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/74`. Summary: the small helper is well identified as `LivingObjectPane`-owned and likely nested/private, but the exact original declaration form remains medium confidence. Evidence: IDA function boundary, scalar deleting destructor behavior, and `??_7BoxRotator@LivingObjectPane@@6B@` vtable xref evidence.
- 2026-06-02: Raised from `72/74` to `82/84`, marked reconstructable, and attached to [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md).
  - Before: the page identified the helper but had no exact child page or autogen parent.
  - After: the page links exact destructor page [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md), the LivingObjectPane core aggregate, and the vtable-data group while keeping reconstructed C++ gated.
  - Evidence: IDA-recorded function boundary and `??_7BoxRotator@LivingObjectPane@@6B@` vtable xref evidence already captured in the file and memory documentation.
