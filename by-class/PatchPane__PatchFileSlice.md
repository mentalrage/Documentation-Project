*** UID:0000AC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PatchPane::PatchFileSlice

## Status

- Confidence: medium
- Likely source file: [UID:0000MH][PatchPane](by-file/PatchPane.md)
- Current recovered file: `source-3/simroot_v2/class_PatchPane__PatchFileSlice.cpp`
- Memory range: [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)

## Class Purpose

`PatchPane::PatchFileSlice` stores one patch-entry download slice. The object keeps a vtable, small state bytes/fields, a data size, and a payload pointer that is freed during destruction.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x005483a0-0x005483bb` | [UID:0001ES][0x005483a0-0x005483bb.PatchFileSliceConstructor](by-memory/0x005483a0-0x005483bb.PatchFileSliceConstructor.md) | Installs the vtable and clears state/data fields. Not emitted in active generated source. |
| `0x00548410-0x00548425` | [UID:0001ET][0x00548410-0x00548425.PatchFileSliceDestructor](by-memory/0x00548410-0x00548425.PatchFileSliceDestructor.md) | Frees payload pointer and leaves object storage in place. Not emitted in active generated source. |
| `0x00548430-0x005484da` | vector deleting destructor | Handles single-object and array destruction, freeing payload buffers and optionally freeing storage. |

## Evidence Notes

- IDA MCP decompilation of `0x005474f0` shows vector construction of `PatchFileSlice` entries using `0x005483a0` and `0x00548410`.
- Active Wave3 emits only `0x00548430`, so constructor and non-deleting destructor coverage should be restored before migration.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms the `PatchFileSlice` vtable at `0x00621dbc` with only the vector/scalar deleting destructor slot.

## Cross-References

- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000A9][PatchPane](by-class/PatchPane.md)
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- [UID:0001ES][0x005483a0-0x005483bb.PatchFileSliceConstructor](by-memory/0x005483a0-0x005483bb.PatchFileSliceConstructor.md)
- [UID:0001ET][0x00548410-0x00548425.PatchFileSliceDestructor](by-memory/0x00548410-0x00548425.PatchFileSliceDestructor.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page documented the nested slice object, constructor/destructor/vector deleting destructor, and Wave3 omission.
- Changed to: `COMPLETION:70` and `CONFIDENCE:72`.
- Evidence: constructor, non-deleting destructor, vector deleting destructor, payload pointer cleanup, `PatchPane` packet-handler construction evidence, and vtable slot are documented; remaining gaps are field names, complete layout, and active generated-source coverage.
