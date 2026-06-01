*** UID:0000AB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:62 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PatchPane::PatchFileData

## Status

- Confidence: medium
- Likely source file: [UID:0000MH][PatchPane](by-file/PatchPane.md)
- Current recovered file: `source-3/simroot_v2/class_PatchPane__PatchFileData.cpp`
- Memory range: [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)

## Class Purpose

`PatchPane::PatchFileData` is a nested support object for patch-file backing storage. Current recovered output only exposes its scalar deleting destructor at `0x00548500`, which frees or releases the backing store pointer.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x00548500-0x00548554` | scalar deleting destructor | Resets the vtable, releases backing storage at the observed `+0x208` field, clears it, and optionally deletes the object. |

## Evidence Notes

- `PatchPane` constructor writes the nested `PatchFileData` vtable into an embedded subobject.
- IDA MCP confirms `0x00548500` as a real function immediately before `PatchPane` scalar deleting destructor.
- The helper is too tightly coupled to patch entry storage to be a standalone original source file.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms the `PatchFileData` vtable at `0x00621dc4` with only the scalar deleting destructor slot.

## Cross-References

- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000A9][PatchPane](by-class/PatchPane.md)
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite the page identifying this as a nested patch backing-storage object with a known scalar deleting destructor.
- Changed to: `COMPLETION:62` and `CONFIDENCE:68`.
- Evidence: destructor behavior, backing-store pointer release, vtable slot, and tight ownership by `PatchPane` are documented; completion and confidence remain moderate because only one emitted method is understood and the full nested layout/lifetime semantics are not yet reconstructed.
