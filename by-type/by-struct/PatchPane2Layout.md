*** UID:0001VJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000AA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PatchPane2 Layout

## Status

- Confidence: strong for tail offsets and vtable subobject offsets, medium for final field names.
- Size: `0x294` bytes from current generated metadata.
- Source owner: [UID:0000MH][PatchPane](by-file/PatchPane.md)
- Class: [UID:0000AA][PatchPane2](by-class/PatchPane2.md)
- Reconstructable: yes, as source-declared class layout semantics. No C++ declaration is emitted yet because final field names and the exact source declaration shape remain below the required 95% audit threshold.

## Layout

| Offset | Type / role | Evidence |
| --- | --- | --- |
| `+0x000` | `DialogPane` primary/base region | Constructor calls the dialog constructor and writes primary vtable `0x00621f40`. |
| `+0x0a0` | secondary callback/listener subobject vtable | Constructor writes vtable `0x00621fa0`; adjustor thunk `0x0054934b` subtracts `0xa0`. Slots include the work-event predicate and main loop. |
| `+0x0a4` | tertiary callback/action subobject vtable | Constructor writes vtable `0x00621fd0`; adjustor thunk `0x00549356` subtracts `0xa4`. |
| `+0x269-0x26b` | alignment/padding after generated `DialogPane` body | Generated metadata exposes three undefined bytes before aligned tail fields. |
| `+0x26c` | final destination path string, currently initialized from `Patcher.exe` | Constructor initializes it with `sub_582B20`, assigns `Patcher.exe`, `SendDownloadRequest` uses it in the formatted request path, and close/rename code deletes/renames this final path. |
| `+0x270` | temporary download path string, initialized from `Patcher.exe.new` | Constructor assigns `Patcher.exe.new`; main loop opens this path for writing and rename helpers use it as the source temp path. |
| `+0x274` | file-name vector begin | Constructor zeroes vector triplet and pushes UTF-16 file names parsed from the packed input buffer. |
| `+0x278` | file-name vector end | Used with `+0x274` to compute vector length in the main loop. |
| `+0x27c` | file-name vector capacity | Destroyed with the vector cleanup in scalar deleting destructor `0x00549370`. |
| `+0x280` | current file-name index | `SendDownloadRequest` selects `vector[index]`; main loop increments or resets it. |
| `+0x284` | active output `FILE*` | Main loop stores the opened temp file here; `ClosePatchFile`, close/rename helper, and destructor close and clear it. |
| `+0x288` | retry/pass counter | Main loop increments it after cycling through the vector and fails after the observed `0x0a` threshold. |
| `+0x28c` | patch/download version component 0 | Constructor copies `a2[0]`; `SendDownloadRequest` formats it with `%d/%d/%s`. |
| `+0x290` | patch/download version component 1 | Constructor copies `a2[1]`; `SendDownloadRequest` formats it with `%d/%d/%s`. |

## Input Buffer

The constructor takes a packed patch/download descriptor:

- `uint16_t[0]` and `uint16_t[1]` become the two version/request path components at `+0x28c` and `+0x290`.
- byte `+0x04` is the number of file names.
- file names begin at byte `+0x05` and advance in `0x100`-byte records.

## IDA Evidence

- Constructor `0x00548690` writes `dword_69BA2C`, installs the three vtables, initializes strings at `+0x26c` and `+0x270`, initializes vector triplet `+0x274/+0x278/+0x27c`, zeroes `+0x280/+0x284/+0x288`, and copies version fields at `+0x28c/+0x290`.
- Main loop `0x00548a80` is entered through the secondary `+0xa0` subobject, so decompiled offsets such as `this + 460` and `this + 464` correspond to full-object offsets `+0x26c` and `+0x270`.
- Raw advance helper `0x00549020` uses full-object offsets `+0x274`, `+0x278`, `+0x280`, and `+0x288`.
- Close/rename helper `0x00549080` uses full-object offsets `+0x26c`, `+0x270`, and `+0x284`.
- Destructor `0x00549370` closes `+0x284`, destroys the vector at `+0x274`, destroys strings at `+0x270` and `+0x26c`, and clears [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md).

2026-05-31 IDA MCP recheck:

- `lookup_funcs` confirms modeled starts and sizes for constructor `0x00548690-0x00548a06`, main loop `0x00548a80-0x00548f1a`, close/rename helper `0x00549080-0x00549214`, send request `0x00549220-0x005492cf`, scalar deleting destructor `0x00549370-0x0054940f`, and the two adjustor thunks `0x0054934b-0x00549356` / `0x00549356-0x00549361`.
- Constructor disassembly writes the primary vtable at `+0x000`, secondary vtable at `+0x0a0`, and tertiary vtable at `+0x0a4`; it initializes `+0x26c`/`+0x270` as string objects, zeroes vector/counter/file fields through `+0x288`, and copies input words to `+0x28c/+0x290`.
- Constructor disassembly parses `*((byte*)input + 4)` names starting at `input + 5`, advancing by `0x100` bytes per name and appending converted strings into the `+0x274/+0x278/+0x27c` vector.
- `xrefs_to` confirms vtable constants `0x00621f40`, `0x00621fa0`, and `0x00621fd0` are written by the constructor and destructor and referenced by setup code; `0x0054934b` and `0x00549356` are referenced from the secondary/tertiary vtables.
- `xrefs_to 0x0069ba2c` confirms singleton writes/clears from the constructor, singleton clear helper, and destructor.
- `callers` confirms the constructor is reached from application startup/patch decision function `0x004f6d80`; `SendDownloadRequest` is called from the constructor and main-loop retry/progress cases.
- Destructor disassembly explicitly pushes `0x294` in the vector-delete path, upgrading the class-size evidence from generated metadata to IDA-verified code evidence.
- String search confirms the runtime uses `patcher.exe` at `0x00612f2c`; final string object contents are still documented semantically because one temp-path literal is represented through local string helper storage and not yet named as a standalone string.

## Generated-Data Caveat

Current generated field names are generic `mbr_0x26c` style names, and generated metadata reports `DialogPane` as a `617`-byte base followed by three undefined bytes. Treat the tail offsets above as IDA-backed layout facts, but keep names provisional until the C++ rewrite pass fixes the real class declaration.

## Cross-References

- [UID:0000AA][PatchPane2](by-class/PatchPane2.md)
- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md)
- [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md)
- [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md)
- [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md)
- [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md)

## Changes

- 2026-05-31 IDA recheck and grading:
  - What existed before: validator metadata was `0/0`, `RECONSTRUCTABLE` was blank, and the page relied partly on generated metadata for the `0x294` size.
  - What it was changed to: marked reconstructable, attached the layout page to [UID:0000AA][PatchPane2](by-class/PatchPane2.md), set scores to `76/84`, and added IDA evidence for function boundaries, vtable writes, tail offsets, input-buffer parsing, singleton xrefs, caller evidence, and destructor size.
  - Summary/evidence: IDA MCP `lookup_funcs`, `decompile`, focused `py_eval` disassembly, `xrefs_to`, `callers`, and string search confirm the field-offset model. Scores stay below 95 because final field names, source declaration shape, and some string/helper identities remain provisional.
