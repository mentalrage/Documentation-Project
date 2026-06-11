*** UID:0000SB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pSoundStatusPane

## Status

- Confidence: strong for address, lifecycle, and class owner; medium-high for final declaration owner.
- Address: `0x0069b4d4`
- Preferred source name: `g_pSoundStatusPane`.
- Kind: process-wide singleton pointer to [UID:0000DJ][SoundStatusPane](by-class/SoundStatusPane.md)
- Proposed owner module: [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- Evidence basis: live IDA MCP xrefs, bytes, decompilation, and instruction windows, rechecked on 2026-06-06.

## Lifecycle

- `0x0069b4d4` is an exact four-byte `.data` singleton slot initialized to `0xff 0xff 0xff 0xff`; live IDA MCP reports 6 data xrefs.
- Set in `SoundStatusPane::SoundStatusPane` at `0x0057bfc0`, with a null/sentinel branch clear at `0x0057bfc7`.
- Cleared by the non-deleting cleanup helper at `0x0057c06a`.
- Cleared by the singleton-clear helper at `0x0057c240`.
- Cleared by the scalar deleting destructor at `0x0057c290`.
- Read during main UI shutdown at `0x005048e6`; the surrounding code checks the pointer and removes/closes the pane from the UI graph when non-null.

## Ownership Notes

The global belongs with the HUD sound-status pane, not with [UID:0000NV][SoundManager](by-file/SoundManager.md). It tracks the visible pane instance used by the main UI graph. Audio state itself lives in `g_pSoundManager`, `g_pMidiPlayer`, and persisted config fields.

## Data Caveats

Some decompiler views omit helper functions that write this global. Use the IDA-confirmed lifecycle above when migrating global ownership.

## Cross-References

- [UID:0000DJ][SoundStatusPane](by-class/SoundStatusPane.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)

## Changes

- 2026-06-05: Marked reconstructable and attached to [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to the `SoundStatusPane` constructor, cleanup helpers, scalar deleting destructor, and main UI shutdown read. No score change and no reconstruction C++ were added.
- What existed before: this page had the right lifecycle outline but unevaluated completion/confidence metadata and stale raw-label wording.
- What changed to: the page now cites live IDA MCP evidence for storage shape, all six data xrefs, lifecycle writes, and the UI shutdown read. Completion/confidence were set to `82/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0069b4d4` as a 4-byte `.data` singleton pointer with six xrefs: shutdown read at `0x005048e6`, constructor assignment/fallback at `0x0057bfc0`/`0x0057bfc7`, cleanup helper clear at `0x0057c06a`, singleton-clear helper at `0x0057c240`, and scalar deleting destructor clear at `0x0057c290`.
- 2026-06-06: Raised completion from `82` to `84` and removed raw storage-label/source-output wording.
  - Reasoning: current live IDA MCP verifies initialized bytes, all six references, constructor publish/fallback clear, non-deleting cleanup clear, singleton-clear helper, scalar deleting destructor clear, and main UI shutdown removal.
  - Summary and evidence: `0x0069b4d4` is an exact four-byte `.data` singleton slot initialized to `0xff 0xff 0xff 0xff`; refs cover shutdown read `0x005048e6`, publish/fallback `0x0057bfc0`/`0x0057bfc7`, cleanup clear `0x0057c06a`, singleton-clear helper `0x0057c240`, and deleting-destructor clear `0x0057c290`.
