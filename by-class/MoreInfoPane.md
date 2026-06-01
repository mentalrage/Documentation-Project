*** UID:00008Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MoreInfoPane

## Status

- Confidence: strong for behavior; strong that it is user-look local unless later evidence finds external construction.
- Likely source file: [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- Address range: [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- Current recovered file: `source-3/simroot_v2/class_MoreInfoPane.cpp`

## Class Purpose

`MoreInfoPane` is a minimal read-only child pane used by `UserLookPane` for the more-info view. It is constructed inline by `UserLookPane::UserLookPane` after a generic text/edit pane setup call, then receives its own vtable.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AlwaysFalse` | `0x005a2340-0x005a2345` | Virtual gate that always returns false. |
| `AlwaysFalse2` | `0x005a2350-0x005a2355` | Second virtual gate that always returns false. |

## Evidence Notes

- Wave3 reports `MoreInfoPane` grade `97.5`, two active methods, and no missing refs.
- IDA xrefs to the two functions are vtable slots at `0x0062edd8` and `0x0062edb8`.
- IDA decompilation of `UserLookPane::UserLookPane` allocates a `372`-byte pane, calls the common pane constructor, and installs `MoreInfoPane` vtables before storing it at `UserLookPane::this[62]`.

## Cross-References

- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: the small user-look child pane has clear inline construction, vtable, storage, and two-method behavior evidence, but the page is inherently concise because the class only exposes two always-false virtual gates. Evidence: linked UserLookPane/profile range, `UserLookPane::UserLookPane` allocation/store evidence, vtable xrefs, and current Wave3 grade/method count.
