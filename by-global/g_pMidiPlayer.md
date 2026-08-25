*** UID:0000RM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LD | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LD | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// g_pMidiPlayer is documented here as the process-wide MidiPlayer singleton.
// The concrete storage definition is emitted by the exact backing data page
// [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md), so this symbol-level page must not duplicate it.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MidiPlayer;

extern MidiPlayer *g_pMidiPlayer;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMidiPlayer

## Status

- Confidence: strong for identity, owner, lifecycle writes, representative consumers, external declaration, and one-definition routing.
- Symbol kind: global singleton pointer.
- Address: [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md)
- Likely owner: [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)

## Role

`g_pMidiPlayer` stores the active [UID:00008A][MidiPlayer](by-class/MidiPlayer.md) singleton. [UID:00041J][0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods](by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md) assigns it in the constructor and clears it in the destructor after stopping/resetting playback, releasing MIDI buffers, closing the stream, and closing the buffer-return event.

UI and application code use this global to pause/resume/stop MIDI playback or to pair MIDI toggles with broader music/sound state changes.

The H channel owns the source-facing forward declaration and `extern MidiPlayer *g_pMidiPlayer;`. The concrete CPP storage remains child-owned by UID00029A, so the symbol page adds no second definition. [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) includes `MidiPlayer.h` and consumes this declaration for its paired MIDI/music hotkey path.

## Evidence

- [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md) documents the exact four-byte `.data` slot as `MidiPlayer *g_pMidiPlayer;` and now scores `85/88`.
- Live IDA MCP on 2026-06-14 reports 18 xrefs to `0x0067ab4c` and confirms the current IDB bytes for the containing singleton window are zero-filled. This supersedes older notes that described the slot as `0xffffffff`.
- Constructor refs at `0x00525dff` and `0x00525e06` publish or clear the slot during construction, and the destructor ref at `0x00525f1e` clears it during teardown. [UID:00041J][0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods](by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md) is the exact source-lifecycle child for these writes.
- [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md) records the constructor EH singleton-clear helper at `0x00526570` and MSVC scalar deleting destructor at `0x00526580` as non-emitting compiler cleanup. These clear the same singleton slot but should not be emitted as hand-written source functions.
- Consumer refs cover Application cleanup, main-menu/music-control paths, BaramApp activation/deactivation helpers, SoundStatusPane/music status code, and MIDI playback helpers at `0x00526570` and `0x00526580`.
- Unreviewed consumer-side references should be renamed only after the surrounding methods are reviewed, but they do not change owner placement.
- 2026-06-16 C001 live IDA refresh in session `b001_mappane_0001AW_20260616` reconfirmed the current `0x0067ab40-0x0067ab8f` singleton window is zero-filled, preserved the 18-xref set, decompiled the tiny clear helper as a direct null store to `g_pMidiPlayer`, decompiled the scalar-deleting destructor clearing the same slot after WinMM/event cleanup, and saved labels `g_pMidiPlayer`, `MidiPlayer_Constructor`, `MidiPlayer_Destructor`, `ClearMidiPlayerSingleton`, and `MidiPlayer_ScalarDeletingDestructor`. Broader playback helper names were not changed because final class-versus-file-scope source shape remains provisional.

## Known Users

- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md): constructor/destructor ownership and playback methods.
- [UID:00041J][0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods](by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md): source-level constructor/destructor singleton writes.
- [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md): EH cleanup and scalar deleting destructor singleton clears.
- [UID:0000NV][SoundManager](by-file/SoundManager.md): pause/resume calls during broader music playback transitions.
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md): hotkey handling and status refresh for music/MIDI state.
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md): stops current MIDI playback when menu actions require it.
- [UID:00000V][BaramApp](by-class/BaramApp.md): activation/deactivation paths call MIDI enable/disable helpers.

## Ownership Guidance

Declare this in `audio/MidiPlayer.h`. Do not assign the storage to `SoundStatusPane`; that pane is a UI consumer. Do not assign it to `SoundManager` unless later evidence shows a monolithic original audio file, because `MidiPlayer` is the constructor/destructor owner. The exact backing storage definition belongs to [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md); this symbol map routes its existing CPP children while emitting only the external H declaration, avoiding duplicate storage.

## Score Rationale

- Completion `89`: exact storage/owner/lifecycle evidence now has a complete H forward/extern declaration, a verified child-owned CPP definition route, and the SoundStatusPane external consumer relationship.
- Confidence `92`: all 18 xrefs, lifecycle writes, semantic identity, class producer, physical child, generated order, and cross-TU consumers converge on one definition plus one header declaration.

## Cross-References

- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- [UID:00008A][MidiPlayer](by-class/MidiPlayer.md)
- [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md)
- [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md)
- [UID:00041J][0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods](by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md)
- [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0001Q8][client_audio](by-meta/client_audio.md)

## Changes

- 2026-08-24 B009 UID0000NX callback: Raised `87/90` to `89/92`. Added the exact `MidiPlayer` forward declaration and `g_pMidiPlayer` extern to H, preserved the child-owned CPP definition, and documented SoundStatusPane as an external consumer requiring this declaration.
- 2026-06-30 B013 bounded empty-emitter implementation:
  - Score unchanged at `87/90`.
  - Summary/evidence: populated the formal block with the accepted symbol-map no-code marker plus `[[CHILDREN]]`. The concrete declaration `MidiPlayer* g_pMidiPlayer = NULL;` is emitted by [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md), so this page must not duplicate storage.
- 2026-05-30: Previously this page carried a stale `0/0` completion/confidence score and cited only weak references for `0x0067ab4c`. It now links the exact singleton storage page, records constructor/destructor ownership, and calls out unresolved consumer-name caveats. Score changed to `78/80` because exact storage and lifecycle are well supported, but some consumer declarations remain unresolved.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LD`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067ab4c` and decompilation of `0x00525dc0` / `0x00525eb0` prove NexusTK-owned `MidiPlayer` singleton storage owned by [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-06 source-facing cleanup:
  - What existed before: score `78/80`, raw storage labels in evidence, and stale coverage-row caveats.
  - Changed to: score `84/88`, refreshed live xref/byte evidence, source-facing singleton wording, and synced the manual by-global coverage row.
  - Summary/evidence: current IDA MCP confirms initialized storage, constructor publish/fallback clear, destructor clear, Application/main-menu/music-control/BaramApp/SoundStatusPane/playback-helper consumers, and file-parent ownership through [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md). C++ remains blank under the final-code gate.
- 2026-06-14 A001 support sync:
  - Changed to: score `85/88`, current zero-filled IDB byte wording, and backing-storage score sync with [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md).
  - Summary/evidence: live IDA rechecked all 18 direct refs, constructor publish/guard-clear behavior, destructor cleanup clear, representative playback helpers, and the unchanged [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) emitter route. C++ remains blank because final declaration/header placement is not source-quality.
- 2026-06-16 C001 safe IDA refresh:
  - Changed scores from `85/88` to `87/90`.
  - Summary/evidence: live IDA reconfirmed zeroed singleton bytes, all 18 xrefs, lifecycle/helper decompilation, and saved the canonical data label plus constructor/destructor/clear/scalar-deleting-destructor labels. No final C++ was entered because declaration/header placement, WinMM state names, and some helper source shapes remain unresolved.
- 2026-06-25 B011 [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md) support sync:
  - Score unchanged.
  - Summary/evidence: added exact lifecycle child [UID:00041J][0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods](by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md) for source-level constructor/destructor singleton writes and compiler-cleanup child [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md) for the EH clear/scalar deleting destructor singleton clears. The cleanup child is non-emitting by design.
