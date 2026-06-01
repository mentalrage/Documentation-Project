*** UID:00007C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LivingObjectPane__BoxRotator

## Status

- Confidence: strong that the helper is tied to `LivingObjectPane`; medium on whether it was a nested class or file-local helper in the original source.
- Likely source file: [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_LivingObjectPane__BoxRotator.cpp`
- Address range: `0x0053d030-0x0053d052` in Wave3, `0x0053d030-0x0053d053` in IDA.

## Class Purpose

`LivingObjectPane__BoxRotator` is Wave3's standalone name for a small `LivingObjectPane` helper that destroys a frame-handler style rotator object. IDA references it from the `??_7BoxRotator@LivingObjectPane@@6B@` vtable, which supports the source-level name `LivingObjectPane::BoxRotator`.

The original source should probably model this as a nested/private helper declared near `LivingObjectPane`, not as a separate top-level gameplay file.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| scalar deleting destructor | `0x0053d030-0x0053d053` | Calls `FrameHandler` cleanup and conditionally deletes the helper object. |

## Evidence Notes

- Wave3 reports `LivingObjectPane__BoxRotator` grade `97.5` with one method.
- IDA confirms a function at `0x0053d030-0x0053d053`.
- IDA xref sample points to `??_7BoxRotator@LivingObjectPane@@6B@`, making it a `LivingObjectPane` nested helper rather than unrelated frame infrastructure.

## Cross-References

- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/74`. Summary: the small helper is well identified as `LivingObjectPane`-owned and likely nested/private, but the exact original declaration form remains medium confidence. Evidence: IDA function boundary, scalar deleting destructor behavior, and `??_7BoxRotator@LivingObjectPane@@6B@` vtable xref evidence.
