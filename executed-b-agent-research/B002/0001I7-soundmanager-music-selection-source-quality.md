** TARGET-REPORT-UID:0001I7 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Report - [UID:0001I7] SoundManagerMusicSelection

Assignment: `B002-goal2-soundmanager-music-selection-source-quality-0001I7-20260617`

Primary target: [UID:0001I7][0x005797b0-0x0057a25c.SoundManagerMusicSelection](../../../../../by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md)

Report-only output. No by-* docs, generated docs/source, IDA DB, source files, or `by-memory/-coverage-report.md` were edited.

## Recommendation Summary

Recommend raising [UID:0001I7] from `82/88` to `88/91`, keeping `RECONSTRUCTABLE:TRUE`, and changing the direct owner/emitter from the file UID to the class UID:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000DG
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000DG
RECONSTRUCTION_CPP: keep blank
```

Source placement remains [UID:0000NV][SoundManager](../../../../../by-file/SoundManager.md), generated route `auto-generated/NexusTK/audio/SoundManager.cpp`. The direct semantic owner should be [UID:0000DG][SoundManager](../../../../../by-class/SoundManager.md) because every function in this range is a `SoundManager` instance method; DAT, Miles AIL, local file scanning, Redbook, MapPane, MusicControlDialog, Bink/startup-logo, and SoundPathVector are dependencies or callers, not direct owners.

Do not populate the formal `RECONSTRUCTION_CPP` block yet. This target now clears the current 85/85 score gate, but it is a multi-method aggregate with constructor, destructor, stream/playlist policy, a tiny driver accessor, and string/path-vector helpers whose exact source declarations should be finalized at the class/string-helper layer before accepted C++ is committed.

## Evidence Checked

I read the target, SoundManager class/file docs, audio helper aggregate, playback controls, directory scan, Redbook helpers, SoundPathVector clear, read-only audio strings, DAT audio resource item, HasDATEntry global, client audio meta, generated coverage, and active generated route files.

Existing executed B reports were searched for `0001I7`, `SoundManagerMusicSelection`, and `0x005797b0-0x0057a25c`; no prior B report for this UID or contained/sibling target was found.

Current IDA MCP session evidence was captured before the endpoint dropped:

- `lookup_funcs` confirmed starts and exact modeled ends: `0x005797b0-0x00579943`, `0x00579950-0x00579a2a`, `0x00579a30-0x00579ca5`, `0x00579cb0-0x00579dbf`, `0x00579dc0-0x00579dc4`, `0x00579e30-0x0057a0a5`, `0x0057a0b0-0x0057a25d`, then successor `0x0057a260`.
- `xrefs_to 0x005797b0` found only `PlayMusicByZone` callers at `0x0057a178` and `0x0057a1cc`.
- `xrefs_to 0x00579950` found MapPane transition/effect-state callers at `0x0050bc05` and `0x0051068f`.
- `xrefs_to 0x00579a30` found construction from application/audio startup at `0x00464697`.
- `xrefs_to 0x00579cb0` found no direct call, consistent with ordinary destructor use through compiler glue/unwind paths.
- `xrefs_to 0x00579dc0` found one caller at `0x004f57d6` inside the startup-logo Bink loop. The body is `mov eax, [ecx+8]; retn`, so it is a digital-driver accessor, not destructor/lifetime tail.
- `xrefs_to 0x00579e30` found 15 stream-play callers, including music-control previous/apply paths, SoundManager timer/next/restart helpers, app activate paths, and zone selector `0x0057a22d`.
- `xrefs_to 0x0057a0b0` found music-apply/map-related callers, consistent with zone-based music selection.
- `get_string` confirmed audio resource literals: `%03d.wav` at `0x0062ce84`, ASCII `%08d.MP3` at `0x0062ce98`, UTF-16 `%08d.MP3` at `0x0062cea4`, `%08d.LST` at `0x0062ceb8`, `%08d.LSR` at `0x0062cecc`, `\*` at `0x0062cee0`, `.mp3` at `0x0062cee4`, and `/` at `0x0062ceec`.
- `get_bytes` before endpoint loss confirmed start padding `0x005797ae-0x005797b0`, inter-function padding after `0x00579943`, after `0x00579a2a`, single padding byte after `0x00579dbf`, and successor-boundary bytes at `0x0057a25c` as `00 cc cc cc`; byte `0x0057a25c` is the `ret 0x10` immediate, so the exact half-open function end is `0x0057a25d` and external padding starts at `0x0057a25d`.

The final small retry for additional padding bytes failed because the local IDA MCP HTTP endpoint began refusing connections. That does not affect the main conclusions because all function starts/ends and decompilations were already captured from the same active session.

## Source Shape And Names

Recommended source-facing method inventory:

| Range | Recommended source name/signature | Notes |
| --- | --- | --- |
| `0x005797b0-0x00579943` | `void SoundManager::LoadTrackListFromFile(const SimpleUString& playlistName)` | Reads a DAT `.LST` or `.LSR` playlist, parses first-line track count and subsequent decimal track IDs, formats each as `%08d.MP3`, and stores paths in `m_zoneMusicTracks`. `SimpleUString` is the best current source-name placeholder for the 4-byte refcounted string object; final string-owner pass may rename it. |
| `0x00579950-0x00579a2a` | `void SoundManager::StopStreamAndResetZone(int fadeOutMillis)` | Stronger than current `StopStreamAndReset`: immediate stop clears current track and current zone; fade path marks the current track negative and schedules stream fade/stop timers. Callers are MapPane map/effect-state transitions, not generic stream stop. |
| `0x00579a30-0x00579ca5` | `SoundManager::SoundManager()` | Publishes `g_pSoundManager`, constructs the timer base, installs the vtable, reinitializes Miles, loads config volume/enabled state, preloads `%03d.wav` DAT sample entries, and starts local music-directory scanning. |
| `0x00579cb0-0x00579dbf` | `SoundManager::~SoundManager()` | Ordinary source-authored destructor. Releases cached samples, stream, digital driver, timers, Redbook handle/state, both SoundPathVector fields, timer base, and singleton ownership. |
| `0x00579dc0-0x00579dc4` | `HDIGDRIVER SoundManager::GetDigitalDriver() const` | Four-byte accessor returning `this+0x8`. It should be documented as a tiny source-authored accessor or inline-out-of-line retained function, not lifetime tail. The exact typedef may be `HDIGDRIVER` or project-local Miles driver pointer; `GetDigitalDriver` is the best semantic name. |
| `0x00579e30-0x0057a0a5` | `void SoundManager::PlayTrackByIndex(int trackIndex, int fadeOutMillis, int loopCount)` | Resolves DAT direct/playlist/local loose-file stream paths, handles pending fade/restart state, opens an AIL stream, starts playback, registers callback, and stores current track. Existing `PlayTrackByIndex` remains defensible because callers pass list positions as well as direct zone IDs. |
| `0x0057a0b0-0x0057a25d` | `void SoundManager::PlayMusicByZone(int zoneId, int fallbackTrackIndex, int fadeOutMillis, int loopCount)` | Selects DAT `%08d.LST`, DAT `%08d.LSR`, direct DAT `%08d.MP3`, or fallback track, then delegates to `PlayTrackByIndex`. |

Rejected method-name alternatives:

- `LoadPlaylist` alone is too broad; the function only loads DAT `.LST/.LSR` entries into the zone-music path vector and formats MP3 names.
- `StopStreamAndReset` is acceptable as a short name, but it hides the important zone reset and MapPane transition role. `StopMusicAndResetZone` would also be acceptable; I prefer `StopStreamAndResetZone` because it only affects the AIL stream path and separately stops Redbook.
- `GetDirectSound` for `0x00579dc0` is rejected. [UID:0001I9] already documents a larger DirectSound query helper around `0x0057a7e0`; this four-byte body returns `this+0x8`, the Miles digital driver handle.
- `PlayTrackById` is rejected because playlist `.LST/.LSR` entries are converted to vector elements and later addressed as 1-based list positions. Direct DAT `%08d.MP3` playback also uses a zone/track number. `PlayTrackByIndex` best preserves both modes.
- `SelectMusicForMap` is rejected for `PlayMusicByZone`; callers include UI music controls and SoundManager restart paths, not only map loading.

## Fields, Globals, And Resource Policy

Recommended field/global/type names for this target and support docs:

| Offset/global | Recommended name/type | Evidence |
| --- | --- | --- |
| `this+0x8` | `HDIGDRIVER m_digitalDriver` | Constructor initializes and driver reinit fills it; stream/sample APIs consume it; `0x00579dc0` returns it directly. |
| `this+0xc` | `bool m_musicEnabled` or `m_streamPlaybackEnabled` | `PlayTrackByIndex` refuses stream open when false. Constructor/config load initializes it from audio config. Exact UI label should be checked with config docs. |
| `this+0x10` | `int m_musicVolume` | Used to reapply AIL stream volume. Playback sibling confirms stream-volume semantics. |
| `this+0x14` | `HSTREAM m_stream` | Opened by `AIL_open_stream`, closed by `AIL_close_stream`, callback registered after start. |
| `this+0x18` | Redbook handle | Redbook sibling owns final names; this target stops/cancels it in reset/destructor. |
| `this+0x28` | `int m_lastFadeOutMillis` / transition fade | `PlayTrackByIndex` stores the fade argument and timer paths use it. |
| `this+0x2c` | `int m_currentTrackIndex` | Positive current stream track/list index; negative means the same track is fading out and can be restored. Immediate reset clears it. |
| `this+0x30` | `int m_currentLoopCount` | Passed to `AIL_set_stream_loop_count`. |
| `this+0x34` | `int m_pendingTrackIndex` | Queued when a different track is requested during a fade. Constructor initializes to `-1`. |
| `this+0x38` | `int m_pendingFadeOutMillis` | Fade value queued with `m_pendingTrackIndex`. |
| `this+0x3c` | `int m_pendingLoopCount` | Loop count queued with `m_pendingTrackIndex`. |
| `this+0x40` | `bool m_localListAdvancePending` | Playback-control sibling uses this for local-directory next-track behavior; not owned by this target but `PlayTrackByIndex` must preserve it. |
| `this+0x48-0x87` | cached sample-slot table | Constructor fills `%03d.wav` DAT payload pointers and destructor releases sample handles/state. |
| `this+0x1028/+0x102c/+0x1030` | `SoundPathVector m_localMusicPaths` | Directory scan sibling populates it; `PlayTrackByIndex` reads it when config music mode is local-directory. |
| `this+0x1098` | `int m_currentMusicZoneId` | Zone selector stores the current DAT zone/playlist ID; reset clears it. |
| `this+0x109c/+0x10a0/+0x10a4` | `SoundPathVector m_zoneMusicTracks` | `LoadTrackListFromFile` fills it; `PlayTrackByIndex` consumes it; `SoundPathVector::Clear` callers at `0x00579f9a` and `0x0057a214`. |
| `this+0x10a8` | `bool m_randomizeZonePlaylist` | Word writes in `PlayMusicByZone` set `0` for `.LST` and `1` for `.LSR`; next-list helper uses this low byte for sequential versus random choice. |
| `this+0x10a9` | `bool m_zonePlaylistActive` | Word writes set it to `1` for both `.LST` and `.LSR`; direct `.MP3` path clears it. |
| `g_pSoundManager` / `0x0067a7d0` | `SoundManager* g_pSoundManager` | Constructor publishes, destructor/scalar-delete paths clear, many callers read it. |
| `HasDATEntry_49C700` | `bool HasDATEntry(const wchar_t* path)` | Resource lookup dependency. It belongs to DAT archive/global docs, not SoundManager. |
| `g_pConfig+0x291908` | music source/mode config byte/int | `PlayTrackByIndex` distinguishes DAT stream mode (`0`) from local-directory mode (`1`). Redbook paths in sibling docs cover other modes. |
| `%03d.wav` | DAT sample cache pattern | Constructor scans IDs `0..999`. |
| `%08d.MP3` | direct DAT stream filename and playlist entry expansion | `LoadTrackListFromFile`, direct zone path, and `PlayTrackByIndex` use it. |
| `%08d.LST` | sequential zone playlist | Zone selector loads list and starts track `1`; same-zone calls reuse current track. |
| `%08d.LSR` | randomized zone playlist | Zone selector loads list and starts `rand() % count + 1`; same-zone calls reuse current track. |
| `\*`, `.mp3`, `/` | local-directory scan literals | Owned by [UID:0001IA], but relevant to local-mode branch in `PlayTrackByIndex`. |

The DAT-vs-local policy should be documented as follows:

- DAT mode first checks zone playlists. `.LST` is sequential and `.LSR` is randomized; both fill `m_zoneMusicTracks`.
- If no playlist exists but direct `%08d.MP3` exists, SoundManager clears playlist mode and plays that DAT stream directly.
- If neither playlist nor direct MP3 exists, `fallbackTrackIndex` is played.
- Local-directory mode uses the scanned `m_localMusicPaths` vector and opens loose MP3 paths, with a UI/message fallback on `AIL_open_stream` failure.
- DAT archive code owns lookup/open/read; SoundManager owns naming policy and audio playback.

## Reachability And Split Decisions

[UID:0001I7] is live and source-relevant:

- The playlist loader has two direct callers from `PlayMusicByZone`; it is not a dead helper.
- The reset helper has direct MapPane transition/effect-state callers. It is source policy for map changes, not an IDA artifact.
- Constructor/destructor are source-authored `SoundManager` lifecycle methods.
- `0x00579dc0` has a direct Bink/startup-logo caller and a real accessor body. It should be split or documented as a child accessor under this target, not folded into destructor tail.
- Track playback and zone selection are broadly reached by UI, app activation, timer, restart, and zone-map paths.

Recommended child/aggregate handling:

- Keep [UID:0001I7] as a reconstructable emitting aggregate until exact child pages exist, but update its child inventory to include `GetDigitalDriver`.
- If the supervisor chooses to split, the most valuable exact child split is `0x00579dc0-0x00579dc4.SoundManagerGetDigitalDriver.md` because the current target doc is materially wrong about this point.
- Do not create child pages from this B report unless a separate safe split assignment is issued.
- [UID:0001I8] should remain a support aggregate, not the final source C++ owner for every child. Its coverage row still has stale `0x0057bc58` text and should be repaired.

Exact range/padding recommendations:

- Target code starts at `0x005797b0` after already documented padding `0x005797ae-0x005797b0`.
- IDA function ends are half-open. The final function in this target ends at `0x0057a25d`, not `0x0057a25c`; `0x0057a25c` is the immediate byte of `ret 0x10`.
- External padding before [UID:0001I9] is `0x0057a25d-0x0057a260`, three `0xcc` bytes from the captured bytes at `0x0057a25c`.
- Current filename can remain historical if supervisor wants minimal churn, but the page body and coverage row should record the half-open range `0x005797b0-0x0057a25d`.

## Generated Output And Source Placement

Generated route is valid:

- `auto-generated/-ag-file-coverage.md` routes [UID:0000NV] to `auto-generated/NexusTK/audio/SoundManager.cpp`.
- `auto-generated/-ag-class-coverage.md` routes [UID:0000DG] to the same file through [UID:0000NV].
- `auto-generated/-ag-memory-coverage.md` currently routes [UID:0001I7] through [UID:0000NV].
- `auto-generated/NexusTK/audio/SoundManager.cpp` exists but is zero bytes, so this target is effectively omitted from active generated C++ output.

Recommended route after metadata update:

```text
[UID:0001I7] -> [UID:0000DG] SoundManager -> [UID:0000NV] NexusTK/audio/SoundManager.cpp
```

Rejected source-placement alternatives:

- DATFile/DATArchive: rejected because this code chooses audio resource names and calls Miles AIL; DAT is only lookup/open/read dependency.
- MapPane: rejected because MapPane only calls the reset helper during map transitions.
- MusicControlDialog: rejected because it only calls playback selection helpers from UI controls.
- StartupLogoPanes/Bink: rejected for `0x00579dc0`; the startup-logo caller consumes a driver accessor but does not own SoundManager driver state.
- SoundPathVector: rejected for [UID:0001I7] as a whole. `SoundPathVector` owns vector helper methods such as [UID:0001IF], but the fields and call sites here are SoundManager policy.
- Redbook/MidiPlayer: rejected because this range stops Redbook during reset/destructor but does not implement Redbook or MIDI ownership.

## Heuristic / Inference Reanalysis And Validation

Best defensible inferences:

- The unresolved `0x00579dc0` item is `SoundManager::GetDigitalDriver() const`, not destructor tail. Evidence: exact four-byte body returns `[ecx+8]`; direct caller from startup-logo Bink path; sibling docs already identify a distinct DirectSound helper around `0x0057a7e0`.
- The source class owner should be [UID:0000DG] `SoundManager`, not [UID:0000NV] as direct owner. Evidence: all functions in the target are methods using `this`; the class page clears 85/85 and already routes to [UID:0000NV].
- `StopStreamAndResetZone` is the best semantic name for `0x00579950`. Evidence: immediate path clears `m_currentTrackIndex` and `m_currentMusicZoneId`; callers are map/effect transition paths. Generic `StopStream` is already represented by sibling `0x0057a260`.
- `m_zoneMusicTracks`, `m_randomizeZonePlaylist`, and `m_zonePlaylistActive` are stronger names than generic path-vector flags. Evidence: `.LST` writes word `0x0100`, `.LSR` writes `0x0101`, direct MP3 clears playlist active, and `PlayTrackByIndex` consumes the vector only when playlist active.
- `PlayTrackByIndex` remains stronger than `PlayTrackById`. Evidence: direct DAT mode uses numeric filenames, but playlist mode uses 1-based vector positions and same-zone playlist reuse calls `abs(m_currentTrackIndex)`.
- DAT resource handling belongs in SoundManager source as policy, while `HasDATEntry`, `DATFile::Open`, and DAT line reading remain archive dependencies.

Evidence checked and validation/rejection:

- Current target doc says `0x00579dc0` is a small modeled start inside destructor/lifetime tail. Rejected by direct body/xref evidence; target and class docs should be updated.
- Current target doc says MCP timed out and no new unseen IDA facts were used. Rejected for this pass; current IDA function/xref/decompile/string evidence was captured, although the endpoint later refused the final padding retry.
- Current target row ends at `0x0057a25c`. Refined: the modeled function ends half-open at `0x0057a25d`; `0x0057a25c` is not padding.
- Existing SoundManager file placement is validated. Folder `audio/` remains best documented path; `sound/` remains a low-impact historical-name uncertainty but not a blocker.
- Existing blank generated output is validated by the zero-byte `auto-generated/NexusTK/audio/SoundManager.cpp`; generated route exists but no accepted formal C++ for this target is present.

Remaining evidence-bound limits:

- Exact original string wrapper name is still not fully solved. `SimpleUString`/project string object is a defensible placeholder because ABI uses a 4-byte refcounted string object and surrounding string docs are still unresolved.
- Exact Miles typedef names should be synchronized with the final third-party header/import layer. `HDIGDRIVER`/`HSTREAM` are semantically correct, but final source may use project-local aliases.
- Config field names around `g_pConfig+0x291908` and adjacent audio volumes need a config-layout pass before locking user-facing names.

Impact:

- Completion can rise to `88` because the main behavioral, ownership, split, field, resource, and generated-output blockers are resolved or reduced to bounded type-name issues.
- Confidence can rise to `91` because current IDA evidence confirms function inventory, direct callers, strings, and the key `0x00579dc0` correction.
- Direct owner/emitter should change to [UID:0000DG], while source file route remains [UID:0000NV].
- Formal C++ should remain blank despite clearing the score gate because this aggregate is not the right granularity for accepted source code and still depends on class-wide string/Miles/config naming.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP` block for [UID:0001I7] in this pass.

Concrete reason: the target is a multi-method aggregate spanning playlist load, map reset, constructor, destructor, a tiny driver accessor, track-index playback, and zone selection. A first draft would either be a large partial `SoundManager.cpp` fragment with unresolved project string, DAT line-read, SoundPathVector element, Miles typedef, timer-token helper, and config-layout names, or a misleading simplified rewrite. The accepted C++ should be entered through exact child pages or after the SoundManager class layout/string wrapper names are promoted. The report therefore intentionally supplies source-shape and signature recommendations, not code.

If the supervisor still wants a future code-entry path, split or certify these child functions first:

```text
0x005797b0-0x00579943 SoundManager::LoadTrackListFromFile
0x00579950-0x00579a2a SoundManager::StopStreamAndResetZone
0x00579a30-0x00579ca5 SoundManager::SoundManager
0x00579cb0-0x00579dbf SoundManager::~SoundManager
0x00579dc0-0x00579dc4 SoundManager::GetDigitalDriver
0x00579e30-0x0057a0a5 SoundManager::PlayTrackByIndex
0x0057a0b0-0x0057a25d SoundManager::PlayMusicByZone
```

## Support Docs To Update

Recommended support updates for supervisor application:

- [UID:0001I7] target doc:
  - Set metadata to `88/91`, owner/emitter [UID:0000DG], reconstructable true, C++ blank.
  - Replace destructor/lifetime-tail wording with ordinary destructor plus separate `GetDigitalDriver` child at `0x00579dc0-0x00579dc4`.
  - Record exact function ends and final half-open range through `0x0057a25d`.
  - Add current IDA xref/decompile/string evidence and remove stale "MCP timed out" caveat.
  - Add field/global/resource-name table from this report.
- [UID:0000DG] `SoundManager` class:
  - Replace `mbr_*` working names for this target with `m_digitalDriver`, `m_musicEnabled`/`m_streamPlaybackEnabled`, `m_musicVolume`, `m_stream`, `m_currentTrackIndex`, `m_pendingTrackIndex`, `m_localMusicPaths`, `m_currentMusicZoneId`, `m_zoneMusicTracks`, `m_randomizeZonePlaylist`, and `m_zonePlaylistActive`, keeping exact final string/config names caveated.
  - Add `GetDigitalDriver` to important methods.
  - Consider raising class confidence after these names are applied; no required coverage row change from this report.
- [UID:0000NV] `SoundManager` file:
  - Add the `GetDigitalDriver` correction and the DAT/local music policy wording.
  - Note active generated file is empty until formal C++ is populated.
- [UID:0001I8] aggregate:
  - Replace stale coverage text/range note for `0x005797b0-0x0057bc58`; the doc itself already says the corrected aggregate extends through `0x0057bf6e`.
  - Clarify that [UID:0001I7] direct owner can be class [UID:0000DG] even though source file remains [UID:0000NV].
- [UID:0001I9] playback controls:
  - Reference `StopStreamAndResetZone` as the map-transition reset helper distinct from `0x0057a260` stream stop.
  - Keep timer-token names aligned: `0x504e4354`, `0x534d736d`, `0x534d7374`.
- [UID:00026I] read-only data and [UID:0000UB] DAT audio resources:
  - Confirm `.LST` sequential and `.LSR` randomized playlist semantics; direct `.MP3` fallback and local directory mode are SoundManager policy.

## Supervisor-Owned Coverage Rows

Replacement row for [UID:0001I8] support aggregate, replacing the current row at placement immediately after the `0x005797ae-0x005797b0` padding row and before [UID:0001I7]:

```text
    - [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md) 0x005797b0-0x0057bf6e | SoundManager aggregate | SoundManagerAudioHelperCluster : reconstructable : 85% : strong : Corrected SoundManager audio-helper aggregate attached to SoundManager source; support docs confirm the historical `0x0057bc58` endpoint was stale and the aggregate extends through the SoundPathVector/string-helper tail at `0x0057bf6e`. Final C++ remains blank because exact child methods and helper ownership carry the reconstructable source bodies.
```

Replacement row for [UID:0001I7], replacing the current row immediately after [UID:0001I8] and before [UID:0001I9]:

```text
    - [UID:0001I7][0x005797b0-0x0057a25c.SoundManagerMusicSelection](by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md) 0x005797b0-0x0057a25d | method-cluster | SoundManagerMusicSelection : reconstructable : 88% : very strong : B002 current IDA source-quality pass confirms SoundManager class ownership/emission through `NexusTK/audio/SoundManager.cpp`, DAT `.LST`/`.LSR` playlist loading, direct `%08d.MP3` fallback, local-directory branch, constructor `%03d.wav` DAT sample cache, map-transition stream reset, stream open/fade/restart state, ordinary destructor, and the `0x00579dc0-0x00579dc4` `GetDigitalDriver` accessor rather than destructor tail. Formal C++ stays blank because this is a multi-method aggregate with unresolved final string/Miles/config type names; exact child pages should carry accepted source snippets.
```

Insert ignored padding row after the [UID:0001I7] replacement row and before [UID:0001I9] if the coverage report wants the refined half-open endpoint represented explicitly:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0057a25d-0x0057a260 | padding | SoundManagerMusicSelection to SoundManagerPlaybackControls alignment : ignored : 100% : strong : Current IDA byte check around `0x0057a25c` shows the final byte of `PlayMusicByZone` is the `ret 0x10` immediate and the successor padding before `0x0057a260` is three `0xcc` bytes.
```

If the supervisor prefers to keep the historical range without adding a padding row, still update the target page text to state that `0x0057a25c` is the final immediate byte and the exact half-open code end is `0x0057a25d`.

## Validation Commands

Commands already run or recommended for supervisor validation:

> Executable block R001 was removed from this report and preserved verbatim in [0001I7-soundmanager-music-selection-source-quality-removed.md](0001I7-soundmanager-music-selection-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA MCP validation commands used before endpoint loss:

```text
server_health
lookup_funcs: 0x005797b0, 0x00579950, 0x00579a30, 0x00579cb0, 0x00579dc0, 0x00579e30, 0x0057a0b0, 0x0057a260
xrefs_to: 0x005797b0, 0x00579950, 0x00579a30, 0x00579cb0, 0x00579dc0, 0x00579e30, 0x0057a0b0, 0x0062ce84, 0x0062ce98, 0x0062cea4, 0x0062ceb8, 0x0062cecc, 0x0067a7d0
callees/analyze_function: 0x005797b0, 0x00579950, 0x00579a30, 0x00579cb0, 0x00579dc0, 0x00579e30, 0x0057a0b0
get_string: 0x0062ce84, 0x0062ce98, 0x0062cea4, 0x0062ceb8, 0x0062cecc, 0x0062cee0, 0x0062cee4, 0x0062ceec
get_bytes: 0x005797ae, 0x00579943, 0x00579a2a, 0x00579dbf, 0x00579dc4, 0x0057a25c
```

Recommended final supervisor rerun after applying docs:

> Executable block R002 was removed from this report and preserved verbatim in [0001I7-soundmanager-music-selection-source-quality-removed.md](0001I7-soundmanager-music-selection-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Files Changed, Leases, And Blockers

Changed file:

- `tools/leaser/Agents/Agent-B002/research/0001I7-soundmanager-music-selection-source-quality.md`

Leases used: none. Per B002 goal rules, research report creation in the assigned folder does not require a lease; protected docs remain supervisor-owned.

Blockers: none for supervisor review. The only transient issue was the IDA MCP endpoint refusing connections during the final extra padding retry after the main evidence had already been collected.

Next useful follow-up: split or certify exact child pages for `SoundManager::GetDigitalDriver`, `SoundManager::StopStreamAndResetZone`, and `SoundManager::PlayMusicByZone` after the SoundManager class layout and string-wrapper names are promoted.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001I7-soundmanager-music-selection-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001I7"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001I7-soundmanager-music-selection-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001I7-soundmanager-music-selection-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001I7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
