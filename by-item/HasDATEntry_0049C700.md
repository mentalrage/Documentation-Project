*** UID:0000UT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HasDATEntry 0x0049C700

## Status

- Confidence: strong
- Entity kind: global helper
- Canonical global page: [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- Likely source module: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Autogen parent: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Exact range: [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)

## Behavior

`HasDATEntry_49C700` checks whether the global DAT manager can resolve a named archive entry. It does not return the archive location; it forwards to `_DATFileMgr::FindEntryByName` with a null output-location pointer.

Observed implementation:

- Reads the public DAT manager singleton/global [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) at `0x0067ab40`.
- Uses the inner manager pointer at offset `+0x4`.
- Calls `_DATFileMgr::FindEntryByName(entryName, 0)`.
- Returns true if lookup succeeds.

## Caller Families

IDA MCP recheck on 2026-06-04 reports 17 direct callers. The caller set spans PCX loading (`0x004a180a`), image-frame loading (`0x004d10cd`), tile metadata and EPF archive-table builders (`0x004d1be5`, `0x004db915`, `0x004ddac5`, `0x004de485`), sprite-part resolution (`0x004e1a35`, `0x004e1a5e`, `0x004e1d72`), palette/archive checks (`0x00543a7e`, `0x00586544`, `0x00589daa`), SoundManager resource selection (`0x00579c0f`, `0x0057a124`, `0x0057a192`, `0x0057a1fb`), and the Miles file-open callback (`0x0057b689`).

IDA MCP decompile and disassembly confirm the whole body is a one-line forwarder:

- `0x0049c703`: read `dword_67AB40`;
- `0x0049c709`: push null output-location argument;
- `0x0049c70b`: push `entryName`;
- `0x0049c70e`: load the inner manager at `+0x04`;
- `0x0049c711`: call `sub_49CAD0(innerManager, entryName, 0)`;
- `0x0049c716-0x0049c718`: convert the boolean result with `test al, al` / `setnz al`.

## Ownership Decision

This helper belongs with DAT manager lookup code. Higher-level modules should call it, but it should not be owned by rendering, sound, or tile-specific source files.

## Live IDA Evidence

Checked on 2026-06-04:

- `lookup_funcs` reports `sub_49C700` at `0x0049c700`, size `0x1d`; `0x0049c71d` is not a function and the next function is `sub_49C720` at `0x0049c720`, with `cc cc cc` padding between them.
- `lookup_funcs` reports the lookup callee `sub_49CAD0` at `0x0049cad0`, size `0xd5`; the helper body has exactly one xref to it at `0x0049c711`.
- `xrefs_to 0x0049c700` reports 17 direct code callers, and the call contexts pass stack/local entry-name buffers or archive-name globals immediately before the call.
- `xrefs_to 0x0067ab40` and body disassembly show the only global access inside this helper is `mov ecx, dword_67AB40` at `0x0049c703`.
- Hex-Rays decompiles the helper as `sub_49CAD0(*(_DWORD **)(dword_67AB40 + 4), String, 0) != 0`.

## Cross-References

- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)
- [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the helper, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now reflects the IDA-confirmed manager-forwarding helper. Parent UID and C++ remain blank because canonical reconstruction should be coordinated with the DAT manager pages before autogen attachment.
  - Evidence: IDA MCP confirms the exact `0x0049c700-0x0049c71d` range, 17 callers, sole callee `0x0049cad0`, and the decompiled `FindEntryByName(..., 0) != 0` body.
- 2026-06-04: Raised completion/confidence from `70/85` to `84/90` and attached [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) as the autogen parent.
  - Before: the page had the helper behavior and rough caller families, but no parent metadata and no current instruction-level evidence block.
  - After: the page records exact live function boundaries, post-function padding, 11-instruction body, singleton read, sole `_DATFileMgr` lookup callee, all 17 direct caller sites, and DAT manager parent attachment. C++ remains blank because original source-facing signature and naming are still below the `95/95` final-code gate.
  - Evidence: live IDA MCP `lookup_funcs`, `disasm`, `decompile`, `xrefs_to`, and `py_eval` on 2026-06-04.
