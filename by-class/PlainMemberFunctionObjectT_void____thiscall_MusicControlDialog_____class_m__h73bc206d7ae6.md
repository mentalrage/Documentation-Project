*** UID:0000AL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6

## Status

- Confidence: strong for `MusicControlDialog` folder-selection callback wrapper role.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support, instantiated by [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md).
- Current recovered file: `source-3/simroot_v2/class_PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.cpp`
- Canonical metadata name is longer and expands the `mystr::StringBase<wchar_t>` argument type.

## Class Purpose

This generated wrapper forwards a selected folder path from [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) to a `MusicControlDialog` member function. It copies the incoming wide string, adjusts the stored owner pointer, and invokes the captured member callback.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Invoke(const mystr::StringBase<wchar_t>&)` | [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md) | Copies the string argument and calls the stored `MusicControlDialog` member callback. |
| scalar deleting destructor | [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md) | Resets the string callback vtable, destroys `LObject`, and conditionally deletes storage. |

## Evidence Notes

- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md) already places this wrapper inside the music-dialog helper island.
- IDA `lookup_funcs 0x0052a3e0` confirms a `0x5e` byte function.
- IDA `xrefs_to 0x0052a3e0` and `0x0052a4a0` reports vtable/data references, matching callback-object dispatch.
- 2026-05-31 IDA MCP recheck confirms exact ranges `0x0052a3e0-0x0052a43e` and `0x0052a4a0-0x0052a4de`, no direct callers, and vtable/data references at `0x0061fcf8` and `0x0061fcec`.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md)
- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md)
- [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md)
- [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page documented the `MusicControlDialog` folder-selection callback wrapper, invoke body, scalar deleting destructor, and vtable/data evidence.
- Changed to: `COMPLETION:72` and `CONFIDENCE:82`.
- Evidence: the page links the wrapper to the music-dialog helper island, records the string-argument invoke and destructor ranges, and notes vtable/data xrefs; remaining gaps are final canonical template spelling and allocation/caller context.

- 2026-05-31 exact-page split:
  - What existed before: the two methods were documented only as raw address ranges on this class page.
  - Changed to: exact by-memory pages [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md) and [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md), metadata `RECONSTRUCTABLE:TRUE`, and scores `78/86`.
  - Summary/evidence: 2026-05-31 IDA MCP confirms exact function starts/sizes, vtable/data xrefs, and lack of normal callers; final C++ remains blank because the original template declaration and construction-site source shape are not fully audited.
