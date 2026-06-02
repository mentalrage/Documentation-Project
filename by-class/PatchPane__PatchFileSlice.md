*** UID:0000AC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

`PatchPane::PatchFileSlice` stores one patch-entry download slice owned by the PatchPane packet/update flow. The object keeps a vtable, small state bytes/fields, a size/index dword, and a payload pointer that is freed during destruction.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x005483a0-0x005483bb` | [UID:0001ES][0x005483a0-0x005483bb.PatchFileSliceConstructor](by-memory/0x005483a0-0x005483bb.PatchFileSliceConstructor.md) | Installs the vtable and clears state/data fields. Not emitted in active generated source. |
| `0x00548410-0x00548425` | [UID:0001ET][0x00548410-0x00548425.PatchFileSliceDestructor](by-memory/0x00548410-0x00548425.PatchFileSliceDestructor.md) | Frees payload pointer and leaves object storage in place. Not emitted in active generated source. |
| `0x00548430-0x005484da` | vector deleting destructor | Handles single-object and array destruction, freeing payload buffers and optionally freeing storage. |

## Evidence Notes

- IDA MCP decompilation of `0x005474f0` shows vector construction of `PatchFileSlice` entries using `0x005483a0` and `0x00548410`.
- Constructor callback xref evidence places `0x005483a0` at `0x005477e4` inside `PatchPanePacketResponseHandler`, where the slice array is constructed.
- The constructor installs the `PatchPane::PatchFileSlice` vtable, clears byte state at `+0x04`, clears the dword field at `+0x08`, and clears the payload pointer at `+0x0c`.
- The non-deleting destructor reinstalls the same vtable and frees the payload pointer at `+0x0c` if present; storage ownership is left to the vector/deleting-destructor path.
- [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) records the RTTI at `0x00621db8`, the one-slot vtable at `0x00621dbc`, and the slot target `0x00548430`.
- The vtable-data boundary ends before the `Auto Patch` string at `0x00621e64`, so the slice RTTI/vtable data is separated from later PatchPane read-only strings.
- Active Wave3 emits only `0x00548430`, so constructor and non-deleting destructor coverage should be restored before migration.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms the `PatchFileSlice` vtable at `0x00621dbc` with only the vector/scalar deleting destructor slot.

## Autogen Status

- Reconstructable: true. The nested class owner, constructor, destructor, deleting destructor, and one-slot vtable are now corroborated by the PatchPane file page, memory pages, and vtable family page.
- Parent: [UID:0000MH][PatchPane](by-file/PatchPane.md). The parent file has a valid proposed path and sufficient score for child attachment.
- Code: intentionally blank. The known fields are offset-level accurate, but their final source names and exact semantic roles are not recovered strongly enough for 95+/95+ C++ reconstruction.

## Score Rationale

- Completion is raised to 76 because the class purpose, parent, memory ranges, callback construction path, destructor behavior, and vtable evidence are documented, while exact member names and complete layout remain open.
- Confidence is raised to 84 because ownership by PatchPane is supported by the parent file, aggregate memory range, constructor/destructor xrefs, and vtable metadata.

## Cross-References

- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000A9][PatchPane](by-class/PatchPane.md)
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md)
- [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- [UID:0001ES][0x005483a0-0x005483bb.PatchFileSliceConstructor](by-memory/0x005483a0-0x005483bb.PatchFileSliceConstructor.md)
- [UID:0001ET][0x00548410-0x00548425.PatchFileSliceDestructor](by-memory/0x00548410-0x00548425.PatchFileSliceDestructor.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page documented the nested slice object, constructor/destructor/vector deleting destructor, and Wave3 omission.
- Changed to: `COMPLETION:70` and `CONFIDENCE:72`.
- Evidence: constructor, non-deleting destructor, vector deleting destructor, payload pointer cleanup, `PatchPane` packet-handler construction evidence, and vtable slot are documented; remaining gaps are field names, complete layout, and active generated-source coverage.
- 2026-06-02: Raised to `76/84`, marked reconstructable, attached to [UID:0000MH][PatchPane](by-file/PatchPane.md), and added constructor callback, offset-state, destructor cleanup, vtable-data, and scoring rationale evidence. C++ remains blank pending final member names.
