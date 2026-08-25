** TARGET-REPORT-UID:0001IB **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001IB SoundManager Redbook Playback Source-Quality Report

Assignment: `B003-goal2-soundmanager-redbook-playback-source-quality-0001IB-20260618`  
Agent: `Agent-B003`  
Date: 2026-06-18  
Target: [UID:0001IB] `by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md`

This is report-only research. I did not edit by-* docs, generated reports/source, the IDA DB, or `by-memory/-coverage-report.md`. The only file created is this report.

## Evidence Checked

Read required workflow files:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B003/goal.md`
- `tools/leaser/Agents/Agent-B003/notes.md`
- `project-documentation/by-structure.md` sections governing source-quality gates, aggregate/container treatment, and exact-child split expectations.
- `project-documentation/inference_research.md` sections on separating direct facts from inference.
- `by-project-structure/proposed-source-tree.md` audio rows, which place SoundManager under `NexusTK/audio/SoundManager.cpp`, keep `MidiPlayer.cpp` separate, and keep generic timer wrappers under `TimerMgr.cpp`.

Read target and support docs:

- [UID:0001IB] `by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md`
- [UID:0000DG] `by-class/SoundManager.md`
- [UID:0000NV] `by-file/SoundManager.md`
- [UID:0001I8] `by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md`
- [UID:0001I9] `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md`
- [UID:0001IA] `by-memory/0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan.md`
- [UID:0001IC] `by-memory/0x0057b490-0x0057bf6e.SoundManagerDriverDestructorAndPathHelpers.md`
- [UID:0001K9] `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md`
- [UID:00028Q] `by-global/g_pConfig.md`
- [UID:00028R] `by-global/g_pSoundManager.md`
- MusicControlDialog support pages for [UID:0003MK] `ApplyPlaybackState`, [UID:0003ML] `TogglePauseState`, [UID:0003MN] `NextTrackHelper`, [UID:0003MO] `PreviousTrackHelper`, [UID:0003MQ] `ApplyOutputSelection`, and generated `auto-generated/NexusTK/ui/dialogs/MusicControlDialog.cpp`.
- Current `by-memory/-coverage-report.md` row for [UID:0001IB].

Current [UID:0001IB] state:

- `COMPLETION: 84`
- `CONFIDENCE: 88`
- `RECONSTRUCTABLE: TRUE`
- `CANONICAL_OWNER: 0000NV`
- `EMITTER_UIDS: 0000NV`
- Formal C++ is blank.

Direct executable evidence checked against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- PE section map: `.text` at image RVA `0x1000`, `.rdata` at image RVA `0x20d000`, `.data` at image RVA `0x26d000`, image base `0x400000`.
- Direct relative-call/reference and little-endian VA/RVA pointer scans for the target function starts:

| Start | Relative refs found | VA/RVA pointer hits |
| --- | --- | --- |
| `0x0057b020` | `0x0052a15a` call | none |
| `0x0057b160` | `0x0050467e`, `0x0057b3b3`, `0x0057b3cc` calls | none |
| `0x0057b1b0` | `0x0057a882`, `0x0057b225`, `0x0057b271`, `0x0057b292`, `0x0057b2d4`, `0x0057b3a7` calls | none |
| `0x0057b240` | `0x005299e2`, `0x0052a252`, `0x005a721e` calls | none |
| `0x0057b2c0` | `0x00529a1d`, `0x0052a29e` calls | none |
| `0x0057b2e0` | `0x0052a1b1` call | none |
| `0x0057b350` | none | none |
| `0x0057b370` | `0x004f8afe`, `0x0052a163` calls | none |
| `0x0057b3f0` | none | none |

Boundary bytes checked:

- `0x0057b152-0x0057b160`: fourteen `0xcc` bytes.
- `0x0057b23f-0x0057b240`: one `0xcc` byte.
- `0x0057b2b7-0x0057b2c0`: nine `0xcc` bytes.
- `0x0057b2df-0x0057b2e0`: one `0xcc` byte.
- `0x0057b34a-0x0057b350`: six `0xcc` bytes.
- `0x0057b36a-0x0057b370`: six `0xcc` bytes.
- `0x0057b3ec-0x0057b3f0`: four `0xcc` bytes.
- `0x0057b48d-0x0057b490`: three `0xcc` bytes before the next modeled SoundManager driver helper.

Direct Capstone disassembly checked:

- `0x0057a5c0-0x0057a6bf` `SoundManager::PlaySample`, to resolve the sample-slot layout used again by raw `0x0057b3f0`.
- `0x0057b3f0-0x0057b48d`, to compare raw sample-slot rotation against `PlaySample`.
- `0x0057b490-0x0057b550`, to confirm the next modeled helper starts after `0x0057b48d` padding and handles driver reinitialization/sample-handle allocation.

Validation/state commands run:

> Executable block R001 was removed from this report and preserved verbatim in [0001IB-SoundManagerRedbookPlayback-source-quality-removed.md](0001IB-SoundManagerRedbookPlayback-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The direct Capstone script parsed the PE section headers itself, translated VAs to file offsets, and disassembled `0x0057a5c0-0x0057a6bf`, `0x0057b3f0-0x0057b48d`, and `0x0057b490-0x0057b550` from the read-only executable bytes.

Important direct disassembly findings:

- `0x0057a5c0` scans eight sample slots at `this+0x48`, tests each slot's first dword with `AIL_sample_status`, rotates an 8-byte slot into `this+0x48`, calls `AIL_init_sample`, reads the sample payload pointer table at `this+0x88 + 4*sampleId`, calls `AIL_set_sample_file`, stores the second argument into `this+0x4c`, computes Miles sample volume from `this+0x44 * arg2 * 0x7f / 10000`, calls `AIL_set_sample_volume`, and starts the sample when sound effects are enabled.
- This proves the eight slots at `this+0x48-0x87` are `SoundSampleSlot[8]`, each 8 bytes: first dword is a Miles `HSAMPLE` handle; second dword is per-play sample volume/scale state. The second dword is not a payload pointer; payload pointers live separately at `this+0x88 + 4*sampleId`.
- `0x0057b3f0` is the same slot rotation/reinitialization half without payload lookup, volume update, or `AIL_start_sample`. It is sample/SFX maintenance, not Redbook/CD playback.
- `0x0057b350` only calls `AIL_redbook_stop(this+0x18)` and cancels timer token `0x504e4354`; it does not close the handle and does not clear Redbook fields.
- `0x0057b490` starts the driver reinitialization helper after the `0x0057b48d-0x0057b490` padding, so the target's historical range endpoint is correct as a half-open range ending before driver setup.

## Heuristic / Inference Reanalysis And Validation

The current SoundManager ownership is valid. Every modeled helper uses `ecx=this` and SoundManager fields; callers reach them through `g_pSoundManager` from MusicControlDialog, MapPane cleanup, the SoundManager timer vfunc, main/bootstrap music setup, and one local/player control path. No evidence supports MusicControlDialog ownership, TimerMgr ownership, MidiPlayer ownership, or a DAT/resource owner.

Best source placement:

1. `SoundManager` class methods in `NexusTK/audio/SoundManager.cpp`. This is strongest because the helpers directly read/write SoundManager fields, use Miles audio imports, share `SoundManager::StopStream`, `SoundManager::SetStreamVolume`, `SoundManager::PlayTrackByIndex`, and `SoundManager::OnTimerEvent`, and are consumed by UI as SoundManager API.
2. Private SoundManager helper methods in the same file for `0x0057b350` and `0x0057b3f0`. This is plausible from `ecx=this`, field access, and adjacency, but entry routes are absent.
3. A hypothetical `Redbook` helper file is weaker. There is no separate vtable, global, RTTI, namespace evidence, string island, or proposed-source-tree evidence separating Redbook from SoundManager.
4. MusicControlDialog is rejected. It only calls and configures SoundManager playback. The dialog-side pages now consistently name the consumer calls but do not own the audio behavior.
5. TimerMgr/TimerHandler is rejected. The wrappers at `0x005975e0` and `0x00597610` are generic timer-forwarding helpers documented by [UID:0001K9], while this target only schedules/cancels the Redbook track-ended token through those wrappers.
6. MidiPlayer is rejected. `MidiPlayer.cpp` owns WinMM MIDI paths, not Miles Redbook/stream/sample playback.
7. DAT/audio resource callback modules are rejected for this cluster. The file callbacks and driver setup support Miles streams and samples, but the Redbook methods manage CD playback policy and SoundManager state.

Best source-facing names and signatures:

| Range | Best name/signature | Evidence | Rejected alternatives |
| --- | --- | --- | --- |
| `0x0057b020-0x0057b152` | `void SoundManager::OpenRedbookDrive(uint16_t driveLetter)` | Loads `[ebp+8]` as a word, closes existing Redbook state, calls `AIL_redbook_open_drive`, applies `SetStreamVolume(this+0x10)`, queries track count, builds `this+0x1034` play order from config shuffle flag. MusicControlDialog stores/uses `g_pConfig+0x291910` as `redbookDriveLetter`. | `OpenCdDrive` is possible but weaker than docs and dialog wording; `InitializeRedbook` is too broad because the function opens a passed drive and rebuilds the order table. |
| `0x0057b160-0x0057b1b0` | `void SoundManager::CloseRedbookDevice()` | Stops, cancels timer, closes `this+0x18`, clears `+0x18/+0x1c/+0x20/+0x24`, cancels timer again. Called by MapPane cleanup and restart paths. | `StopRedbook` is too weak; this helper closes the Miles handle and clears state. |
| `0x0057b1b0-0x0057b23f` | `void SoundManager::PlayRedbookTrack(uint32_t trackNumber)` | Stores current track at `+0x24`, calls `AIL_redbook_track_info`, `AIL_redbook_play`, and schedules the Redbook track-ended timer for `end-start`; wraps to track 1 when requested track is greater than count and repeat is enabled. | `PlayCdTrack` is plausible but less consistent with Miles API and current docs. `PlayTrack` is too ambiguous against stream/list helpers. |
| `0x0057b240-0x0057b2b7` | `bool SoundManager::AdvanceRedbookTrack()` | Increments `+0x20`, chooses the next byte from `this+0x1034`, wraps when `g_pConfig+0x291913` is true, otherwise stops and cancels timer at end of table. Returns `al` true/false. Called by MusicControlDialog next-track paths and local/player control path `0x005a721e`. | `NextRedbookTrack` is acceptable as a source synonym, but `AdvanceRedbookTrack` best matches current docs and behavior. |
| `0x0057b2c0-0x0057b2df` | `bool SoundManager::RewindRedbookTrack()` | If `+0x20 > 0`, decrements the order index and calls `PlayRedbookTrack(order[index])`; otherwise returns false. Called by MusicControlDialog previous-track paths. | `PreviousRedbookTrack` is acceptable as a source synonym, but `RewindRedbookTrack` is already established in support docs. |
| `0x0057b2e0-0x0057b34a` | `void SoundManager::SetRedbookPaused(bool paused)` | Byte arg controls pause/resume. Pause cancels timer and calls `AIL_redbook_pause`. Resume calls `AIL_redbook_track_info`, `AIL_redbook_resume`, `AIL_redbook_position`, and schedules remaining duration. | `PauseRedbook` misses the resume half. |
| `0x0057b350-0x0057b36a` | `SoundManager::StopRedbookAndCancelTrackTimerRaw` as a descriptive raw helper | No IDA function and no direct relative/VA/RVA route. Body is source-shaped and only stops Redbook handle plus cancels token `0x504e4354`. | `CloseRedbookDevice` is false because no close/clear. `CompactStopHelper` is too generic. Formal source name remains unproven because no entry route exists. |
| `0x0057b370-0x0057b3ec` | `void SoundManager::RestartMusic(int fadeOutMilliseconds)` | Calls `StopStream`/stop-fade helper `0x0057a260` with arg, reads `g_pConfig+0x291908`, starts Redbook order[0] for mode 2, closes Redbook and starts stream/local track 1 for mode 1, closes Redbook and optionally restarts zone/list playback when mode 0 and `this+0x10a9` is set. Main/bootstrap passes `0xbb8`; dialog applies `0`. | `ApplyMusicMode` is a good behavior label but weaker than current support name and callers. Parameter could be `stopDelay` or `fadeOutMs`; `fadeOutMilliseconds` is best inference from stream fade/timer behavior and `0xbb8` caller. |
| `0x0057b3f0-0x0057b48d` | `SoundManager::RotateReusableSampleSlotRaw` as a descriptive raw helper | No IDA function and no direct relative/VA/RVA route. Disassembly exactly matches the sample-slot rotation subset from `PlaySample` and calls `AIL_init_sample`; it touches SFX slots, not Redbook state. | Any Redbook/CD name is rejected. `PlaySample` is false because no payload lookup, no file assignment, no volume update, and no start call. Formal source name remains unproven because no entry route exists. |

Resolved field/type/global names:

| Storage | Best name/type | Evidence and confidence |
| --- | --- | --- |
| `this+0x8` | `HDIGDRIVER m_digitalDriver` | Driver setup and sample/stream playback require it; existing class/file docs agree. |
| `this+0x10` | `int m_musicVolume` or `m_streamVolume` | `OpenRedbookDrive` calls `SetStreamVolume(this+0x10)` after opening Redbook; playback controls use the same field as stream/master volume. Use `m_musicVolume` in class-level docs when Redbook and stream share it. |
| `this+0x14` | `HSTREAM m_stream` | Adjacent playback controls and driver cleanup close active stream handles. |
| `this+0x18` | `HREDBOOK m_redbook` / `m_redbookHandle` | Every Redbook helper passes this field to Miles Redbook imports. |
| `this+0x1c` | `uint32_t m_redbookTrackCount` | Set from `AIL_redbook_tracks`; used as order table length and range guard. |
| `this+0x20` | `uint32_t m_redbookOrderIndex` | Incremented/decremented by advance/rewind and used as an index into `this+0x1034`. |
| `this+0x24` | `uint32_t m_currentRedbookTrack` | Set before `AIL_redbook_track_info`; timer dispatch calls `PlayRedbookTrack(this+0x24 + 1)`. |
| `this+0x40` | `bool m_musicAdvanceRequested` / `m_listAdvanceRequested` | MusicControlDialog and the local/player control path set it before next-track behavior; [UID:0001I9] still treats this as local/list advance state. Keep name descriptive until stream/list logic is fully final. |
| `this+0x48-0x87` | `SoundSampleSlot m_sampleSlots[8]` | Direct `PlaySample` and raw `0x57b3f0` disassembly both walk eight 8-byte slots. First dword is passed to `AIL_sample_status`, `AIL_init_sample`, `AIL_set_sample_file`, `AIL_set_sample_volume`, and `AIL_start_sample`, so it is `HSAMPLE handle`. Second dword receives `PlaySample` arg2 and participates in volume calculation, so it is per-play volume/scale state. |
| `this+0x88 + 4*sampleId` | `void* m_samplePayloads[1000]` / DAT-backed sample payload table | `PlaySample` rejects `sampleId > 999`, then reads this table and passes the pointer to `AIL_set_sample_file`. |
| `this+0x1034` | `uint8_t m_redbookOrder[100]` | `OpenRedbookDrive` zeros 100 bytes and fills sequential or randomized track numbers; advance/rewind read bytes from it. Redbook CDs are effectively capped below 100 tracks, so no separate dynamic vector is implied. |
| `this+0x10a8` | `bool m_randomizeZonePlaylist` | Existing playback/local-list docs. Not directly Redbook shuffle; Redbook shuffle uses config `+0x291912`. |
| `this+0x10a9` | `bool m_zonePlaylistActive` / `m_listTrackModeActive` | `RestartMusic` mode 0 tests it before starting track 1 through the stream/list helper. This is not Redbook state. |
| `g_pConfig+0x291908` | `int musicSourceMode` | MusicControlDialog source-mode control and SoundManager restart paths use values 0 disabled/fallback, 1 stream/local, 2 Redbook/CD. |
| `g_pConfig+0x291910` | `uint16_t redbookDriveLetter` | MusicControlDialog drive popup stores a word and `OpenRedbookDrive` consumes a word argument. |
| `g_pConfig+0x291912` | `bool randomizeMusicOrder` / shuffle flag | Redbook order construction and local scan both use this as shuffle/randomize. |
| `g_pConfig+0x291913` | `bool repeatMusic` | Redbook out-of-range and advance behavior wrap only when this flag is true; local next-track docs also use it as repeat/wrap policy. |
| `g_pConfig+0x291914` | `uint8_t musicOutputSelection` | Dialog output selection helper writes this; not directly read by Redbook helpers except through broader SoundManager output policy. |
| Timer token `0x504e4354` | `kRedbookTrackEndedTimer` behavior label | Used by Redbook play/pause/stop/close/advance and SoundManager timer dispatch. Do not claim original enum spelling from the numeric token. |

Validation/contradiction of current docs:

- Validated: SoundManager ownership, file placement under `audio/SoundManager.cpp`, seven modeled function starts, two raw method-shaped bodies, Miles Redbook API use, timer token `0x504e4354`, Redbook order construction, shuffle/repeat config offsets, MusicControlDialog caller relationships, MapPane cleanup close caller, and TimerMgr wrapper exclusion.
- Strengthened: `this+0x48-0x87` is no longer just "sample-slot state." It is eight 8-byte slots; first word is `HSAMPLE`, second word is per-play volume/scale state. This comes from direct `PlaySample` disassembly, not from a guess.
- Strengthened: The C++ blocker is no longer "field/config/timer names not source-final enough" for the seven modeled methods. The blocker is aggregate/source-shape: [UID:0001IB] is a broad method cluster containing independently reconstructable methods plus two raw no-entry helpers, one of which is not Redbook behavior.
- Contradicted: Treating `0x0057b3f0-0x0057b48d` as part of "RedbookPlayback" is only physically true by range. Behaviorally it belongs to sample/SFX slot maintenance and should be split/cross-linked with playback-control/driver docs.
- Contradicted: Any final-code policy phrased as "blank until 95/95" is stale. The active gate is reconstructable, nonblank emitter route, and average score above 85 with source-quality code. The modeled children meet that code-entry standard after this pass.

Hidden table/computed-call/raw route findings:

- No direct relative call/jump, little-endian VA pointer, or RVA pointer route was found for raw `0x0057b350` or raw `0x0057b3f0`.
- No vtable route is supported. SoundManager's known vtable references the timer vfunc; the Redbook helpers are normal methods called directly from class/file code, not virtual overrides.
- No jump-table route is supported. The observed MusicControlDialog jump table routes to inline command-handler cases and to dialog helpers, not to these SoundManager raw starts.
- `0x0057b350` may be a private source helper retained without a caller, or an unreferenced compiler/product build artifact. It should not be turned into formal C++ without a recovered entry route, even though the body is understandable.
- `0x0057b3f0` is likely a dead or unreferenced helper that factors the sample-slot rotation code also inlined inside `PlaySample`. No current caller proves it is live. It should be documented, split, and left blank for formal C++ until an entry route is recovered.

Split/range decision:

- [UID:0001IB] is currently a method cluster, not a single source function. Under the current by-structure rules, this should not receive monolithic formal C++ containing multiple child methods and raw bodies.
- The preferred supervisor action is to split exact children for the seven modeled Redbook/source methods plus the two raw helper bodies. After that split, [UID:0001IB] should become a non-emitting family/index page with blank formal C++.
- If the supervisor does not split immediately, [UID:0001IB] can remain reconstructable as a reviewed cluster with `86/90` and blank aggregate C++, but the report should record that first-draft C++ belongs on exact children, not on the broad cluster.

## Recommended Metadata And Score Changes

Immediate recommendation for current [UID:0001IB] if no child split is applied in the same supervisor pass:

| Field | Current | Recommended | Reason |
| --- | ---: | ---: | --- |
| `COMPLETION` | `84` | `86` | Direct PE/Capstone pass resolves source-facing method signatures, field meanings, config names, caller routes, raw no-route status, sample-slot layout, and exact C++ blocker. Capped because exact child pages are not created and raw helper entry routes remain unresolved. |
| `CONFIDENCE` | `88` | `90` | Strong direct executable evidence supports boundaries, callers, fields, config offsets, and ownership. Capped because original source spellings and raw helper liveness remain unproven. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` for unsplit cluster | Current page still has reconstructable source-bearing methods, but aggregate C++ should stay blank until split. |
| `CANONICAL_OWNER` | `0000NV` | `0000NV` | As a broad file/source-family cluster, the file-level SoundManager owner remains acceptable. |
| `EMITTER_UIDS` | `0000NV` | `0000NV` for unsplit cluster | Keep only if unsplit. Exact children should emit through [UID:0000DG] `SoundManager`. |

Preferred post-split metadata:

- Change [UID:0001IB] to a non-emitting family/index page:
  - `COMPLETION: 87`
  - `CONFIDENCE: 90`
  - `RECONSTRUCTABLE: FALSE`
  - `CANONICAL_OWNER: 0000NV`
  - `EMITTER_UIDS:` blank
  - Rationale: after exact children carry source ownership, the parent no longer represents a source-emitting function.
- Create exact children:

| Proposed filename | Kind | Owner/emitter | Recommended score | Formal C++ |
| --- | --- | --- | --- | --- |
| `0x0057b020-0x0057b152.SoundManagerOpenRedbookDrive.md` | method | `CANONICAL_OWNER:0000DG`, `EMITTER_UIDS:0000DG` | `88/92` | yes |
| `0x0057b160-0x0057b1b0.SoundManagerCloseRedbookDevice.md` | method | `0000DG` / `0000DG` | `88/92` | yes |
| `0x0057b1b0-0x0057b23f.SoundManagerPlayRedbookTrack.md` | method | `0000DG` / `0000DG` | `88/92` | yes |
| `0x0057b240-0x0057b2b7.SoundManagerAdvanceRedbookTrack.md` | method | `0000DG` / `0000DG` | `88/92` | yes |
| `0x0057b2c0-0x0057b2df.SoundManagerRewindRedbookTrack.md` | method | `0000DG` / `0000DG` | `88/92` | yes |
| `0x0057b2e0-0x0057b34a.SoundManagerSetRedbookPaused.md` | method | `0000DG` / `0000DG` | `88/92` | yes |
| `0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw.md` | raw method-shaped helper | `0000DG` / blank or `0000DG` per supervisor raw policy | `85/87` | no, entry route absent |
| `0x0057b370-0x0057b3ec.SoundManagerRestartMusic.md` | method | `0000DG` / `0000DG` | `87/91` | yes |
| `0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md` | raw method-shaped helper | `0000DG` / blank or `0000DG` per supervisor raw policy | `85/87` | no, entry route absent and behavior is sample/SFX rather than Redbook |

Support-doc score recommendations:

- [UID:0000DG] `by-class/SoundManager.md`: raise `86/86 -> 87/88` if the class page is updated with the resolved Redbook fields, method signatures, timer token behavior label, and 8-byte sample-slot layout.
- [UID:0000NV] `by-file/SoundManager.md`: keep `90/85` or raise confidence only to `86` if desired. Source placement is stronger, but active generated `auto-generated/NexusTK/audio/SoundManager.cpp` remains empty and several other SoundManager children still have source-split debt.
- [UID:0001I9] `SoundManagerPlaybackControls`: no score change required, but update sample-slot wording from generic "sample-slot state" to the resolved 8-byte `SoundSampleSlot` layout.
- [UID:0001IC] `SoundManagerDriverDestructorAndPathHelpers`: no score change required, but revise the sample-slot blocker. The slot layout is now partly resolved; callback typedefs and exact driver helper source split remain blockers.
- [UID:00028Q] `g_pConfig`: no score change required; its music config field names already match the stronger names used here.
- MusicControlDialog support pages: no required score changes; current generated/dialog docs already use the SoundManager Redbook method names, but should stop treating those names as blocked by SoundManager-side unknowns.

## First-Draft C++ Recommendation

Do not populate a monolithic formal C++ block on [UID:0001IB] while it remains a broad cluster. Populate formal C++ on exact child pages for the seven modeled methods. The following draft is suitable for supervisor placement after child split, or as a "first-draft child C++" section in the target page if the split is deferred.

Use descriptive inferred field/config names. Original source spellings are not provable, but the behavior and signatures are strong enough for draft emission.

```cpp
namespace {
constexpr uint32_t kRedbookTrackEndedTimer = 0x504e4354;
constexpr int kMaxRedbookTracks = 100;

enum MusicSourceMode {
    kMusicSourceDisabled = 0,
    kMusicSourceStream = 1,
    kMusicSourceRedbook = 2,
};
}

void SoundManager::OpenRedbookDrive(uint16_t driveLetter)
{
    if (m_redbookHandle != nullptr)
    {
        AIL_redbook_stop(m_redbookHandle);
        CancelTimer(kRedbookTrackEndedTimer);
        AIL_redbook_close(m_redbookHandle);

        m_redbookHandle = nullptr;
        m_redbookTrackCount = 0;
        m_redbookOrderIndex = 0;
        m_currentRedbookTrack = 0;

        CancelTimer(kRedbookTrackEndedTimer);
    }

    m_redbookHandle = AIL_redbook_open_drive(driveLetter);
    SetStreamVolume(m_musicVolume);

    if (m_redbookHandle == nullptr)
        return;

    m_redbookTrackCount = AIL_redbook_tracks(m_redbookHandle);
    memset(m_redbookOrder, 0, sizeof(m_redbookOrder));

    // The binary uses 100-byte stack/order buffers. Redbook CDs are expected
    // to stay within this limit.
    const int count = m_redbookTrackCount;
    if (g_pConfig->randomizeMusicOrder)
    {
        uint8_t remaining[kMaxRedbookTracks] = {};
        for (int i = 0; i < count && i < kMaxRedbookTracks; ++i)
            remaining[i] = static_cast<uint8_t>(i + 1);

        int remainingCount = count;
        for (int out = 0; out < count && out < kMaxRedbookTracks; ++out)
        {
            int pick = rand() % remainingCount;
            for (int i = 0; i < count && i < kMaxRedbookTracks; ++i)
            {
                if (remaining[i] == 0)
                    continue;

                if (pick-- == 0)
                {
                    m_redbookOrder[out] = remaining[i];
                    remaining[i] = 0;
                    --remainingCount;
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < count && i < kMaxRedbookTracks; ++i)
            m_redbookOrder[i] = static_cast<uint8_t>(i + 1);
    }
}

void SoundManager::CloseRedbookDevice()
{
    if (m_redbookHandle == nullptr)
        return;

    AIL_redbook_stop(m_redbookHandle);
    CancelTimer(kRedbookTrackEndedTimer);
    AIL_redbook_close(m_redbookHandle);

    m_redbookHandle = nullptr;
    m_redbookTrackCount = 0;
    m_redbookOrderIndex = 0;
    m_currentRedbookTrack = 0;

    CancelTimer(kRedbookTrackEndedTimer);
}

void SoundManager::PlayRedbookTrack(uint32_t trackNumber)
{
    CancelTimer(kRedbookTrackEndedTimer);

    if (trackNumber <= m_redbookTrackCount)
    {
        uint32_t start = 0;
        uint32_t end = 0;

        m_currentRedbookTrack = trackNumber;
        AIL_redbook_track_info(m_redbookHandle, trackNumber, &start, &end);
        AIL_redbook_play(m_redbookHandle, start, end);
        ScheduleTimer(kRedbookTrackEndedTimer, end - start, 0, 0);
        return;
    }

    if (m_redbookTrackCount != 0 && g_pConfig->repeatMusic)
    {
        PlayRedbookTrack(1);
        return;
    }

    m_currentRedbookTrack = 0;
}

bool SoundManager::AdvanceRedbookTrack()
{
    ++m_redbookOrderIndex;

    if (g_pConfig->repeatMusic)
    {
        if (m_redbookTrackCount != 0)
        {
            m_redbookOrderIndex %= m_redbookTrackCount;
            PlayRedbookTrack(m_redbookOrder[m_redbookOrderIndex]);
            return true;
        }

        m_redbookOrderIndex = 0;
    }
    else
    {
        if (m_redbookOrderIndex < m_redbookTrackCount)
        {
            PlayRedbookTrack(m_redbookOrder[m_redbookOrderIndex]);
            return true;
        }

        m_redbookOrderIndex = m_redbookTrackCount;
    }

    AIL_redbook_stop(m_redbookHandle);
    CancelTimer(kRedbookTrackEndedTimer);
    return false;
}

bool SoundManager::RewindRedbookTrack()
{
    if (m_redbookOrderIndex == 0)
        return false;

    --m_redbookOrderIndex;
    PlayRedbookTrack(m_redbookOrder[m_redbookOrderIndex]);
    return true;
}

void SoundManager::SetRedbookPaused(bool paused)
{
    if (paused)
    {
        CancelTimer(kRedbookTrackEndedTimer);
        AIL_redbook_pause(m_redbookHandle);
        return;
    }

    uint32_t start = 0;
    uint32_t end = 0;
    AIL_redbook_track_info(m_redbookHandle, m_currentRedbookTrack, &start, &end);
    AIL_redbook_resume(m_redbookHandle);

    const uint32_t position = AIL_redbook_position(m_redbookHandle);
    ScheduleTimer(kRedbookTrackEndedTimer, end - position, 0, 0);
}

void SoundManager::RestartMusic(int fadeOutMilliseconds)
{
    StopStream(fadeOutMilliseconds);

    switch (g_pConfig->musicSourceMode)
    {
    case kMusicSourceRedbook:
        if (m_redbookTrackCount != 0)
            PlayRedbookTrack(m_redbookOrder[0]);
        break;

    case kMusicSourceStream:
        CloseRedbookDevice();
        PlayTrackByIndex(1, 100, true);
        break;

    case kMusicSourceDisabled:
    default:
        CloseRedbookDevice();
        if (m_zonePlaylistActive)
            PlayTrackByIndex(1, 100, true);
        break;
    }
}
```

Raw no-code proof for `0x0057b350-0x0057b36a`:

- It is source-shaped and understandable, but IDA does not model it as a function.
- Direct PE scans found no relative call/jump, VA pointer, or RVA pointer route to `0x0057b350`.
- It is not in the SoundManager vtable and is not reached by a known jump table.
- It has no null guard and only performs `AIL_redbook_stop(this+0x18)` plus `CancelTimer(0x504e4354)`.
- Formal C++ should stay blank until a live entry route or intentional source helper role is recovered. A non-formal reference draft, if needed in notes only, is:

```cpp
void SoundManager::StopRedbookAndCancelTrackTimer()
{
    AIL_redbook_stop(m_redbookHandle);
    CancelTimer(kRedbookTrackEndedTimer);
}
```

Raw no-code proof for `0x0057b3f0-0x0057b48d`:

- It is source-shaped and understandable, but IDA does not model it as a function.
- Direct PE scans found no relative call/jump, VA pointer, or RVA pointer route to `0x0057b3f0`.
- It is not Redbook behavior despite living in the historical Redbook cluster range. It touches `this+0x48-0x87` sample slots and calls `AIL_sample_status`/`AIL_init_sample`.
- `PlaySample` at `0x0057a5c0` contains the live slot-rotation behavior plus payload lookup, volume update, and sample start. The raw helper may be dead/unreferenced or a private helper that was inlined at live call sites.
- Formal C++ should stay blank until a live entry route is recovered. A non-formal reference draft, if needed in notes only, is:

```cpp
void SoundManager::RotateReusableSampleSlot()
{
    int slot = 7;
    for (int i = 0; i < 8; ++i)
    {
        if (m_sampleSlots[i].handle != nullptr &&
            AIL_sample_status(m_sampleSlots[i].handle) == 2)
        {
            slot = i;
            break;
        }
    }

    SoundSampleSlot selected = m_sampleSlots[slot];
    memmove(&m_sampleSlots[1], &m_sampleSlots[0], slot * sizeof(SoundSampleSlot));
    m_sampleSlots[0] = selected;

    if (m_sampleSlots[0].handle != nullptr)
        AIL_init_sample(m_sampleSlots[0].handle);
}
```

## Exact Supervisor Changes Required

### Target Page Replacement Text

If the supervisor does not split exact children immediately, update [UID:0001IB] metadata only as follows:

```text
COMPLETION: 86
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 0000NV
EMITTER_UIDS: 0000NV
```

Replace the current autogen/rebuild paragraph block with:

```markdown
- Rebuild handling: source-authored `SoundManager` Redbook/CD policy methods around Miles AIL Redbook calls, track-order state, music-mode restart behavior, plus two raw method-shaped helpers inside the historical range.
- Autogen handling: keep this page as a reviewed SoundManager helper-family cluster until exact child pages are created. Do not add monolithic aggregate C++ here. The seven IDA-modeled methods are eligible for first-draft C++ as exact children; raw `0x0057b350` and raw `0x0057b3f0` remain blank for formal C++ because no direct relative-call, VA/RVA pointer, vtable, or jump-table entry route was found. `0x0057b3f0` is sample/SFX slot maintenance, not Redbook/CD behavior.
- Confidence: very strong for function boundaries, SoundManager ownership, Miles Redbook behavior, timer scheduling/cancel, music-dialog callers, config offsets, and adjacent padding; capped by missing exact child split, unproven original source spellings, and no-entry raw helper liveness.
```

Replace or add these touched-state rows:

```markdown
| `this+0x18` | Miles Redbook/CD handle (`HREDBOOK` working type). | Every Redbook helper passes this field to Miles Redbook imports; open stores it, close clears it, and stop/pause/play helpers consume it. |
| `this+0x1c` | Redbook track count. | Set from `AIL_redbook_tracks` in `OpenRedbookDrive`; range-checked by play/advance/restart helpers. |
| `this+0x20` | Redbook order-table index. | Incremented/decremented by advance/rewind and used to index `this+0x1034`. |
| `this+0x24` | Current Redbook track number. | Stored by `PlayRedbookTrack`; SoundManager timer dispatch calls `PlayRedbookTrack(this+0x24 + 1)`. |
| `this+0x48-0x87` | Eight 8-byte sound-effect sample slots. | Direct `PlaySample` disassembly proves slot dword 0 is a Miles `HSAMPLE` handle and slot dword 1 stores per-play volume/scale; raw `0x0057b3f0` rotates the same slots and calls `AIL_init_sample`. |
| `this+0x88 + 4*sampleId` | DAT-backed sound-effect sample payload pointer table. | `PlaySample` rejects ids above `999`, loads the pointer from this table, and passes it to `AIL_set_sample_file`; this table is separate from the 8-byte sample slots. |
| `this+0x1034` | 100-byte Redbook play-order table. | `OpenRedbookDrive` zeroes and fills this table sequentially or randomly; advance/rewind read selected track bytes from it. |
| `this+0x10a9` | Zone/list playlist active flag, not Redbook state. | `RestartMusic` mode 0 tests it before starting stream/list track 1. |
| `g_pConfig+0x291908` | Music source mode: 0 disabled/fallback, 1 stream/local, 2 Redbook/CD. | MusicControlDialog mode control and SoundManager `RestartMusic` use the same values. |
| `g_pConfig+0x291910` | Redbook drive letter/drive selector word. | MusicControlDialog drive popup writes this field; `OpenRedbookDrive` consumes a word argument. |
| `g_pConfig+0x291912` | Music order randomize/shuffle flag. | `OpenRedbookDrive` chooses random Redbook order construction when true; local music scanning also consumes it. |
| `g_pConfig+0x291913` | Music repeat/wrap flag. | `PlayRedbookTrack` and `AdvanceRedbookTrack` wrap Redbook playback when true; local next-track paths also use it as repeat policy. |
| `Timer event 0x504e4354` | Redbook track-ended timer behavior label. | Redbook play/pause/advance/close helpers and SoundManager timer dispatch use this token through generic TimerHandler wrappers. Do not claim original enum spelling from the numeric token. |
```

Replace the ownership decision with:

```markdown
This range belongs to `SoundManager` under `NexusTK/audio/SoundManager.cpp`. MusicControlDialog is a consumer, not the owner; TimerMgr owns only the generic schedule/cancel wrappers; MidiPlayer owns separate WinMM MIDI paths; DAT/file callbacks provide stream/sample data but do not own Redbook playback policy. A separate Redbook source file remains possible only as a weak historical-source hypothesis because no RTTI, vtable, global, namespace, string-island, or proposed-source-tree evidence separates these helpers from SoundManager.

The page should be split. The seven modeled functions are independent SoundManager methods and can carry first-draft C++ on exact child pages. Raw `0x0057b350` and raw `0x0057b3f0` should be documented as method-shaped no-entry helpers; `0x0057b3f0` should be cross-linked from sample/SFX support docs because its behavior is sample-slot maintenance, not Redbook/CD playback.
```

Replace the score rationale with:

```markdown
| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | Direct PE and Capstone reanalysis resolves source-facing names/signatures for the modeled Redbook helpers, config fields, Redbook state fields, timer token behavior, caller routes, no-entry raw helper status, split needs, and the sample-slot structure used by raw `0x0057b3f0`. Capped because the exact child split has not been applied and the two raw helper entry routes remain unresolved. |
| Confidence | 90 | Very strong for exact boundaries, SoundManager ownership, Miles API behavior, MusicControlDialog/MapPane/timer callers, config offsets, and raw-helper no-route evidence. Capped because original source spellings, `RestartMusic` parameter naming, and raw helper liveness are not provable from current evidence. |
```

Add a change-history bullet:

```markdown
- 2026-06-18 B003 source-quality reanalysis: recommend `84/88 -> 86/90` for the unsplit cluster, preserve [UID:0000NV] file ownership for the current aggregate, and recommend exact child splits for seven modeled methods plus two raw helpers. Direct PE/Capstone checks resolve Redbook method signatures, config fields `g_pConfig+0x291908/+0x291910/+0x291912/+0x291913/+0x291914`, Redbook fields `this+0x18/+0x1c/+0x20/+0x24/+0x1034`, sample slot layout at `this+0x48-0x87`, timer token `0x504e4354`, no-route status for raw `0x0057b350` and `0x0057b3f0`, and first-draft C++ for the modeled child methods. Formal C++ remains blank on this aggregate because child pages, not the broad cluster, should carry source bodies.
```

### Support Doc Text

For [UID:0000DG] `by-class/SoundManager.md`, replace the relevant key-data bullets with:

```markdown
- `m_musicVolume` / `this+0x10`: shared stream/Redbook music volume applied by `SetStreamVolume` and after opening a Redbook drive.
- `m_redbookHandle` / `this+0x18`: Miles Redbook/CD handle (`HREDBOOK` working type).
- `m_redbookTrackCount` / `this+0x1c`: count from `AIL_redbook_tracks`.
- `m_redbookOrderIndex` / `this+0x20`: current index into the Redbook play-order table.
- `m_currentRedbookTrack` / `this+0x24`: currently playing Redbook track number used by timer/resume paths.
- `m_musicAdvanceRequested` / `this+0x40`: next-track/advance request flag used by UI and local/stream playback paths; exact final source spelling remains open.
- `m_sampleSlots` / `this+0x48-0x87`: eight 8-byte sound-effect sample slots. Slot dword 0 is a Miles `HSAMPLE` handle; slot dword 1 stores per-play volume/scale state. DAT-backed sample payload pointers are separate at `this+0x88 + 4*sampleId`.
- `m_redbookOrder` / `this+0x1034`: 100-byte Redbook play-order table filled sequentially or randomly from `g_pConfig->randomizeMusicOrder`.
```

For [UID:0000DG] method table, replace the Redbook row with:

```markdown
| `0x0057b020-0x0057b48d` | Redbook and adjacent sample-slot helpers | `OpenRedbookDrive`, `CloseRedbookDevice`, `PlayRedbookTrack`, `AdvanceRedbookTrack`, `RewindRedbookTrack`, `SetRedbookPaused`, `RestartMusic`, a no-entry compact Redbook stop/timer helper at `0x0057b350`, and a no-entry sample-slot rotation helper at `0x0057b3f0`. The last helper is sample/SFX behavior despite physical adjacency. |
```

For [UID:0000NV] `by-file/SoundManager.md`, add under source-quality decisions:

```markdown
- B003's 2026-06-18 Redbook pass keeps Redbook/CD playback in `NexusTK/audio/SoundManager.cpp`; MusicControlDialog remains a consumer, TimerMgr owns only generic timer wrappers, and MidiPlayer remains separate WinMM MIDI code. The Redbook cluster should be split into exact SoundManager method children before generated `SoundManager.cpp` receives source bodies.
```

For [UID:0001I9] `SoundManagerPlaybackControls`, replace the `this+0x48-0x87` touched-state row with:

```markdown
| `this+0x48-0x87` | Eight 8-byte sound-effect sample slots. | `PlaySample` scans these slots, treats dword 0 as a Miles `HSAMPLE` handle, rotates a reusable slot into index 0, calls `AIL_init_sample`, stores the per-play volume/scale argument into dword 1, applies sample volume, and starts the sample. Raw `0x0057b3f0` in [UID:0001IB] repeats the rotation/reinit subset without payload lookup or playback start. |
```

For [UID:0001IC] `SoundManagerDriverDestructorAndPathHelpers`, replace the sample-slot blocker clause with:

```markdown
The sample-slot array at `this+0x48-0x87` is now partially resolved by B003's 2026-06-18 Redbook/playback pass as eight 8-byte `SoundSampleSlot` entries: first dword `HSAMPLE`, second dword per-play volume/scale. Remaining blockers are exact Miles callback typedef spelling, file-class declaration placement, driver branch details, and path-helper/source split.
```

No direct support-doc edit is required for [UID:00028Q] `g_pConfig`; it already holds the relevant music config field names. If consistency text is desired, use:

```markdown
- `musicSourceMode` at `+0x291908`, `redbookDriveLetter` at `+0x291910`, `randomizeMusicOrder` at `+0x291912`, `repeatMusic` at `+0x291913`, and `musicOutputSelection` at `+0x291914` are the names used by both MusicControlDialog and SoundManager Redbook/playback support docs.
```

Validation commands the supervisor should run after applying doc/coverage edits:

> Executable block R002 was removed from this report and preserved verbatim in [0001IB-SoundManagerRedbookPlayback-source-quality-removed.md](0001IB-SoundManagerRedbookPlayback-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Coverage Report Replacement Text

Immediate replacement row for `by-memory/-coverage-report.md` if the supervisor does not split child pages in the same pass:

```markdown
    - [UID:0001IB][0x0057b020-0x0057b48a.SoundManagerRedbookPlayback](by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md) 0x0057b020-0x0057b48a | method-cluster | SoundManagerRedbookPlayback : reconstructable : 86% : very strong : B003 2026-06-18 direct PE/Capstone reanalysis confirms seven modeled SoundManager Redbook/CD methods, exact padding boundaries, MusicControlDialog/MapPane/timer/bootstrap caller routes, Miles Redbook API behavior, Redbook fields `this+0x18/+0x1c/+0x20/+0x24/+0x1034`, config fields `g_pConfig+0x291908/+0x291910/+0x291912/+0x291913/+0x291914`, Redbook track-ended timer token `0x504e4354`, and no relative/VA/RVA/vtable/jump-table route for raw `0x0057b350` or raw `0x0057b3f0`; also resolves `this+0x48-0x87` as eight 8-byte SoundManager sample slots and identifies `0x0057b3f0` as sample/SFX slot rotation rather than Redbook behavior. Keep formal C++ blank on the unsplit aggregate and place first-draft C++ on exact child method pages after split.
```

Post-split coverage-row template requiring supervisor-assigned UIDs. Do not paste this block until new UIDs exist:

```markdown
    - [UID:<NEW_OPEN_REDBOOK>][0x0057b020-0x0057b152.SoundManagerOpenRedbookDrive](by-memory/0x0057b020-0x0057b152.SoundManagerOpenRedbookDrive.md) 0x0057b020-0x0057b152 | method | SoundManagerOpenRedbookDrive : reconstructable : 88% : very strong : Opens the configured Redbook drive, closes any prior Redbook handle, applies music volume, reads track count, and fills the 100-byte sequential/randomized Redbook order table from config shuffle state; first-draft child C++ recommended.
    - [UID:<NEW_CLOSE_REDBOOK>][0x0057b160-0x0057b1b0.SoundManagerCloseRedbookDevice](by-memory/0x0057b160-0x0057b1b0.SoundManagerCloseRedbookDevice.md) 0x0057b160-0x0057b1b0 | method | SoundManagerCloseRedbookDevice : reconstructable : 88% : very strong : Stops playback, cancels Redbook timer token `0x504e4354`, closes the Miles Redbook handle, clears Redbook state fields, and is called by MapPane cleanup and restart paths; first-draft child C++ recommended.
    - [UID:<NEW_PLAY_REDBOOK>][0x0057b1b0-0x0057b23f.SoundManagerPlayRedbookTrack](by-memory/0x0057b1b0-0x0057b23f.SoundManagerPlayRedbookTrack.md) 0x0057b1b0-0x0057b23f | method | SoundManagerPlayRedbookTrack : reconstructable : 88% : very strong : Cancels the Redbook timer, starts a requested track with `AIL_redbook_track_info`/`AIL_redbook_play`, schedules remaining track duration, and wraps to track 1 when repeat is enabled; first-draft child C++ recommended.
    - [UID:<NEW_ADVANCE_REDBOOK>][0x0057b240-0x0057b2b7.SoundManagerAdvanceRedbookTrack](by-memory/0x0057b240-0x0057b2b7.SoundManagerAdvanceRedbookTrack.md) 0x0057b240-0x0057b2b7 | method | SoundManagerAdvanceRedbookTrack : reconstructable : 88% : very strong : Advances the Redbook order index, wraps or stops according to repeat config, calls `PlayRedbookTrack`, returns success/failure, and is called by MusicControlDialog next-track paths plus a local/player control path; first-draft child C++ recommended.
    - [UID:<NEW_REWIND_REDBOOK>][0x0057b2c0-0x0057b2df.SoundManagerRewindRedbookTrack](by-memory/0x0057b2c0-0x0057b2df.SoundManagerRewindRedbookTrack.md) 0x0057b2c0-0x0057b2df | method | SoundManagerRewindRedbookTrack : reconstructable : 88% : very strong : Decrements the Redbook order index when possible, replays the selected order byte, returns success/failure, and is called by MusicControlDialog previous-track paths; first-draft child C++ recommended.
    - [UID:<NEW_SET_REDBOOK_PAUSED>][0x0057b2e0-0x0057b34a.SoundManagerSetRedbookPaused](by-memory/0x0057b2e0-0x0057b34a.SoundManagerSetRedbookPaused.md) 0x0057b2e0-0x0057b34a | method | SoundManagerSetRedbookPaused : reconstructable : 88% : very strong : Pauses by canceling Redbook timer and calling `AIL_redbook_pause`; resumes by querying current track end/position, calling `AIL_redbook_resume`, and scheduling remaining duration; first-draft child C++ recommended.
    - [UID:<NEW_STOP_REDBOOK_RAW>][0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw](by-memory/0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw.md) 0x0057b350-0x0057b36a | raw-method | SoundManagerStopRedbookAndCancelTrackTimerRaw : reconstructable : 85% : strong : Source-shaped raw helper with no IDA function and no relative/VA/RVA/vtable/jump-table route; stops the Redbook handle and cancels timer token `0x504e4354` but does not close or clear state. Keep formal C++ blank until entry route is recovered.
    - [UID:<NEW_RESTART_MUSIC>][0x0057b370-0x0057b3ec.SoundManagerRestartMusic](by-memory/0x0057b370-0x0057b3ec.SoundManagerRestartMusic.md) 0x0057b370-0x0057b3ec | method | SoundManagerRestartMusic : reconstructable : 87% : very strong : Stops/fades current stream playback, reads music source mode, starts Redbook order[0], stream/local track 1, or disabled/fallback list playback as appropriate, and is called by bootstrap and MusicControlDialog playback-state paths; first-draft child C++ recommended.
    - [UID:<NEW_ROTATE_SAMPLE_SLOT_RAW>][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md) 0x0057b3f0-0x0057b48d | raw-method | SoundManagerRotateReusableSampleSlotRaw : reconstructable : 85% : strong : Source-shaped raw helper with no IDA function and no relative/VA/RVA/vtable/jump-table route; scans eight 8-byte sample slots at `this+0x48`, selects a reusable `HSAMPLE` slot by `AIL_sample_status == 2` or slot 7, rotates it to slot 0, and calls `AIL_init_sample`. This is sample/SFX behavior, not Redbook playback; keep formal C++ blank until entry route is recovered.
```

If the split is applied, replace the original [UID:0001IB] row with a non-emitting overview row after UIDs exist. Proposed row:

```markdown
    - [UID:0001IB][0x0057b020-0x0057b48a.SoundManagerRedbookPlayback](by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md) 0x0057b020-0x0057b48a | method-cluster | SoundManagerRedbookPlayback : ignored : 87% : very strong : Non-emitting SoundManager helper-family overview after exact child split; tracks Redbook/CD method sequence, two raw no-entry helpers, exact padding, ownership/source-placement rationale, and links to source-emitting child pages. Formal C++ stays blank on the container.
```

## Remaining Blockers

- Child split is not applied in this report-only pass. Until the supervisor creates child pages, [UID:0001IB] should not receive aggregate formal C++ even though the modeled methods have draft code.
- Raw `0x0057b350` still has no direct relative-call, VA/RVA pointer, vtable, jump-table, or known computed-call route. It is understandable but not formally source-emitting yet.
- Raw `0x0057b3f0` still has no direct relative-call, VA/RVA pointer, vtable, jump-table, or known computed-call route. It should be documented as no-entry sample-slot maintenance, not Redbook playback.
- Exact original source spellings for `AdvanceRedbookTrack` versus `NextRedbookTrack`, `RewindRedbookTrack` versus `PreviousRedbookTrack`, and `RestartMusic(int fadeOutMilliseconds)` parameter naming remain inferred. The descriptive names are high probability from behavior and current support docs, but not symbol-proven.
- `this+0x40` remains a SoundManager-side working name. Current evidence supports an advance-request/list-next flag, but the final original field spelling and whether it is purely local-list or broader next-track state require a focused audit of `PlayNextTrack`, the local/player control path at `0x005a721e`, and stream/list helpers.
- Miles typedef exact spellings should use real Miles headers if available. `HREDBOOK` and `HSAMPLE` are appropriate working typedefs from Miles API conventions and import behavior, but not source-header-proven in this documentation set.
- `m_zonePlaylistActive` / `this+0x10a9` is high-confidence from SoundManager local/list docs and `RestartMusic` mode 0 behavior, but exact original field spelling remains unresolved.
- Active generated `auto-generated/NexusTK/audio/SoundManager.cpp` is still zero bytes as of this pass. Supervisor should not claim generated SoundManager code now exists unless a later generation pass populates it.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001IB-SoundManagerRedbookPlayback-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001IB"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001IB-SoundManagerRedbookPlayback-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001IB-SoundManagerRedbookPlayback-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001IB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
