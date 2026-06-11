*** UID:0002ZH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StartupLogoBinkRestartFlag

## Status

- Address: `0x0066db42`
- Exact storage: `by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md`.
- Current IDA name: `byte_66DB42`.
- Kind: one-byte startup-logo Bink restart/reopen flag plus trailing storage byte.
- Proposed source owner: startup logo media playback support in [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md).
- Rebuild handling: source-declared mutable global/static state.

## Role

This byte starts initialized to `1`. The startup-logo Bink midpoint helper reads it before attempting a one-shot stream reopen and clears it before closing the active Bink handle and reopening from the next-segment payload pointer.

## Evidence

- 2026-06-07 A007 IDA MCP reads `01 00` at `0x0066db42-0x0066db44`.
- `xrefs_to 0x0066db42` reports a read/compare at `0x004f5ae0` and a write-clear at `0x004f5afa`, both inside [UID:00022U][0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart](by-memory/0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart.md).
- The instruction window shows the helper clearing the flag before `BinkClose`, then reopening `dword_69B474` with flags `0x04080000`.
- `xrefs_to 0x0066db43` is empty.

## Source Ownership

Keep this state with startup-logo media playback. The exact flag belongs with [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md); the remaining static-logo versus video source split caveat affects final file naming, not the direct ownership of this one-shot Bink restart flag.

## Assignment Gate

- `AUTOGEN_PARENT_UID` is set to [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md).
- This by-global parent is `86/91`, and the direct source-file parent is now `88/85`, so both sides clear the corrected `85/85` assignment gate.
- 2026-06-07 A010 Batch077 live IDA refresh reconfirmed the playback loop at `0x004f5710`, the midpoint helper at `0x004f5ae0`, the sole helper caller at `0x004f5aaf`, the read/clear xrefs for `0x0066db42`, and no xrefs to the trailing byte at `0x0066db43`.

## Cross-References

- [UID:00022U][0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart](by-memory/0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart.md)
- [UID:00022T][0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop](by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md)
- [UID:00029G][0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals](by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md)
- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:0001RN][startup-logo-media](by-resource/startup-logo-media.md)

## Changes

- 2026-06-07 A010 Batch077: Set `AUTOGEN_PARENT_UID:0000O4` after refreshing [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md) to `88/85`. This repairs generated coverage for memory child [UID:0002ZM][0x0066db42-0x0066db44.StartupLogoBinkRestartFlag](by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md) without changing this page's `86/91` score.
- 2026-06-07 A007 Batch 052: Created exact by-global parent for the split startup-logo Bink restart flag after live IDA confirmed the flag byte, read/write xrefs, and separation from the adjacent JPEG marker bytes.
