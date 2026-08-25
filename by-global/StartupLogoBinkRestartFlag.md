*** UID:0002ZH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static bool g_startupLogoBinkRestartPending = true;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StartupLogoBinkRestartFlag

## Status

- Address: `0x0066db42`
- Exact storage: `by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md`.
- Current IDA name: `byte_66DB42`.
- Preferred source-facing name: `g_startupLogoBinkRestartPending` (inferred from behavior; no original symbol is present).
- Kind: one-byte startup-logo Bink restart/reopen flag plus trailing storage byte.
- Proposed source owner: startup logo media playback support in [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md).
- Rebuild handling: source-declared mutable global/static state.

## Role

`g_startupLogoBinkRestartPending` starts initialized to `1`. [UID:00022U][0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment](by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md) reads it before attempting a one-shot segment advance and clears it before closing the active Bink handle and reopening from the next-segment payload pointer.

## Evidence

- 2026-06-07 A007 IDA MCP reads `01 00` at `0x0066db42-0x0066db44`.
- `xrefs_to 0x0066db42` reports a read/compare at `0x004f5ae0` and a write-clear at `0x004f5afa`, both inside [UID:00022U][0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment](by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md).
- The instruction window shows the helper clearing the flag before `BinkClose`, then reopening `dword_69B474` with flags `0x04080000`.
- `xrefs_to 0x0066db43` is empty.

## Source Ownership

Keep this state with startup-logo media playback. The exact flag belongs with [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md); the remaining static-logo versus video source split caveat affects final file naming, not the direct ownership of this one-shot Bink restart flag. `g_startupLogoBinkRestartPending` is the preferred source-facing name for current first-draft helper C++, but the original spelling is still inferred.

## Assignment Gate

- `AUTOGEN_PARENT_UID` is set to [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md).
- This by-global parent is `86/91`, and the direct source-file parent is now `88/85`, so both sides clear the corrected `85/85` assignment gate.
- 2026-06-07 A010 Batch077 live IDA refresh reconfirmed the playback loop at `0x004f5710`, the midpoint helper at `0x004f5ae0`, the sole helper caller at `0x004f5aaf`, the read/clear xrefs for `0x0066db42`, and no xrefs to the trailing byte at `0x0066db43`.

## Cross-References

- [UID:00022U][0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment](by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md)
- [UID:00022T][0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop](by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md)
- [UID:00029G][0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals](by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md)
- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:0001RN][startup-logo-media](by-resource/startup-logo-media.md)

## Changes

- 2026-06-30 B008 UID0000O4 implementation callback: changed score from `86/91` to `88/92`, populated first-draft static global C++, and preserved byte/xref proof that `0x0066db42` is the startup-logo one-shot restart flag consumed by `TryAdvanceStartupLogoBinkSegment`.
- 2026-06-25 B013 TryAdvanceStartupLogoBinkSegment sync: Added preferred source-facing name `g_startupLogoBinkRestartPending` for the one-shot flag used by [UID:00022U][0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment](by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md). Preserved the inferred-name caveat, direct source owner, and no-ref trailing byte evidence; score unchanged at `86/91`.
- 2026-06-07 A010 Batch077: Set `AUTOGEN_PARENT_UID:0000O4` after refreshing [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md) to `88/85`. This repairs generated coverage for memory child [UID:0002ZM][0x0066db42-0x0066db44.StartupLogoBinkRestartFlag](by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md) without changing this page's `86/91` score.
- 2026-06-07 A007 Batch 052: Created exact by-global parent for the split startup-logo Bink restart flag after live IDA confirmed the flag byte, read/write xrefs, and separation from the adjacent JPEG marker bytes.
