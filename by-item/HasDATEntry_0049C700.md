*** UID:0000UT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HasDATEntry 0x0049C700

## Status

- Confidence: strong
- Entity kind: global helper
- Current Wave3 owner file: `HasDATEntry_0049C700.cpp`
- Canonical global page: [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- Likely source module: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Exact range: [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)

## Behavior

`HasDATEntry_49C700` checks whether the global DAT manager can resolve a named archive entry. It does not return the archive location; it forwards to `_DATFileMgr::FindEntryByName` with a null output-location pointer.

Observed implementation:

- Reads the public DAT manager singleton/global [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) at `0x0067ab40`.
- Uses the inner manager pointer at offset `+0x4`.
- Calls `_DATFileMgr::FindEntryByName(entryName, 0)`.
- Returns true if lookup succeeds.

## Caller Families

IDA MCP recheck on 2026-05-31 reports 17 direct callers. The known families include PCX loading, image-frame loading, tile metadata, tilec/effect table building, sprite-part resolution, palette/archive loading, and SoundManager resource selection.

IDA MCP decompile confirms the whole body is a one-line forwarder:

- read `dword_67AB40`;
- load the inner manager at `+0x04`;
- call `sub_49CAD0(innerManager, entryName, 0)`;
- return whether the result is nonzero.

## Ownership Decision

This helper belongs with DAT manager lookup code. Higher-level modules should call it, but it should not be owned by rendering, sound, or tile-specific source files.

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
