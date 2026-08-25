** TARGET-REPORT-UID:0003MB **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B003 Source-Quality Report: MusicControlDialog Constructor And Command Handler

Assignment: `B003-goal2-music-control-dialog-source-quality-0003MB-0003MD-20260618`

Primary targets:

- [UID:0003MB] `by-memory/0x00528e60-0x0052976c.MusicControlDialogConstructor.md`
- [UID:0003MD] `by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md`

Required output path:

`tools/leaser/Agents/Agent-B003/research/0003MB-0003MD-MusicControlDialog-source-quality.md`

This pass is report-only. I did not edit by-memory docs, by-class docs, by-file docs, generated reports/source, the IDA database, or `by-memory/-coverage-report.md`.

## Evidence Checked

- Read the active supervisor and agent instructions:
  - `tools/leaser/Agents/Supervisor.md`
  - `tools/leaser/Agents/Agent-B003/goal.md`
  - `tools/leaser/Agents/Agent-B003/notes.md`
  - `by-structure.md`
  - `inference_research.md`
  - `by-project-structure/proposed-source-tree.md`
- Read both primary targets:
  - [UID:0003MB] constructor page, current `COMPLETION:84`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:00008U], blank formal C++.
  - [UID:0003MD] command-handler page, current `COMPLETION:84`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:00008U], blank formal C++, range includes body plus switch table.
- Read direct support pages:
  - [UID:00008U] `by-class/MusicControlDialog.md`
  - [UID:0000LN] `by-file/MusicControlDialog.md`
  - [UID:0001CP] `by-memory/0x00528e60-0x0052a535.MusicControlDialog.md`
  - [UID:00025Y] `MusicControlDialogReadOnlyData`
  - [UID:00027V] `MusicControlDriveRootBuffers`
  - [UID:0003ME] `MusicControlDialogUnmodeledSoundEffectApply`
  - [UID:0003MF] `MusicControlDialogSoundEffectPacketHandler`
  - [UID:0003MG] `MusicControlDialogDirectoryPacketHandler`
  - [UID:0003MH] `MusicControlDialogRefreshControlStates`
  - [UID:0003MI] `MusicControlDialogFolderPathSelected`
  - [UID:0003MJ] `MusicControlDialogDrivePopupPopulate`
  - [UID:0003MK] `MusicControlDialogApplyPlaybackState`
  - [UID:0003ML] `MusicControlDialogTogglePauseState`
  - [UID:0003MM] `MusicControlDialogRefreshFolderPathControl`
  - [UID:0003MN] `MusicControlDialogNextTrackHelper`
  - [UID:0003MO] `MusicControlDialogPreviousTrackHelper`
  - [UID:0003MP] `MusicControlDialogApplySoundEffectEnabled`
  - [UID:0003MQ] `MusicControlDialogApplyOutputSelection`
  - [UID:0002N2]/[UID:0002N3] folder callback wrapper/destructor pages
  - [UID:0003MR] scalar deleting destructor page
- Read audio/config/network support:
  - [UID:0000DG] `by-class/SoundManager.md`
  - [UID:0000NV] `by-file/SoundManager.md`
  - [UID:0001I9] `SoundManagerPlaybackControls`
  - [UID:0001IA] `SoundManagerMusicDirectoryScan`
  - [UID:0001IB] `SoundManagerRedbookPlayback`
  - [UID:00028Q] `g_pConfig`
  - [UID:00028R] `g_pSoundManager`
  - [UID:0001HU] `QueueAndSendPacket`
  - [UID:0001P0]/[UID:0000Q5] `g_packetSender`
  - [UID:0001DY] `SendOptionPacket11B`
  - [UID:0001DQ] `OptionPaneSendOptionPacket11B`
  - [UID:0000TL] `SendOptionPacket11B_540E50`
- Checked generated state:
  - `by-memory/-coverage-report.md` still has a stale [UID:0001CP] aggregate row at `76%` and no visible child rows for [UID:0003MB] or [UID:0003MD] in the local coverage block.
  - `project-level/-auto-completion-stats.md` is generated and should be refreshed by the normal supervisor validator/rescore flow, not edited by this report.
- Attempted current MCP access at `http://127.0.0.1:13337/mcp`; the endpoint was unavailable in this run. I therefore used the already-written MCP-backed target/support evidence and direct PE/disassembly checks from the read-only executable.
- Direct PE/disassembly evidence checked against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:
  - Verified the image base/section mapping sufficiently to inspect VAs in the target ranges.
  - Verified wide resource literals `DLGSCNTL.EPF` at `0x0061fcb4` and `PFLOOK.PAL` at `0x0061fc9c`.
  - Verified mutable drive buffers [UID:00027V]: ASCII `X:\` at `0x0066debc` and UTF-16 `X:` at `0x0066dec0`.
  - Verified command-handler switch table dwords at `0x00529b30-0x00529b68`:
    - control `1` -> `0x00529978`
    - control `2` -> `0x00529951`
    - control `3` -> `0x005298b0`
    - control `4` -> `0x00529889`
    - control `5` -> `0x00529a50`
    - control `6` -> `0x00529b10`
    - control `7` -> `0x005297de`
    - control `8` -> `0x00529abe`
    - control `9` -> `0x00529a7c`
    - control `10` -> `0x00529a9d`
    - control `11` -> `0x00529a07`
    - control `12` -> `0x005299fd`
    - control `13` -> `0x005299c3`
    - control `14` -> `0x005299b9`
  - Verified constructor broad shape:
    - base/dialog construction then three `MusicControlDialog` vptr writes at object offsets `+0`, `+0xa0`, and `+0xa4`;
    - pause byte `this+0x26c` cleared;
    - resource branch loads `DLGSCNTL.EPF` with `PFLOOK.PAL`;
    - controls are constructed/attached through common radio group, slider, static/text, image button, popup menu, and EPF image/control helpers;
    - control `6` is initialized from `g_pConfig+0x29190c`;
    - CD drive popup control `8` is populated by `A..Z` `GetDriveTypeA` checks using [UID:00027V] buffers and selected against `g_pConfig+0x291910`;
    - initial control states come from `SoundManager` volume/playback/SFX accessors and config offsets `+0x291908`, `+0x291912`, `+0x291913`, and `+0x291914`;
    - constructor calls `0x00529d00` `RefreshControlStates`;
    - constructor inlines a three-byte `0x011b` option/settings packet with option code `0`.
  - Verified command-handler cases:
    - case `1`: sends `0x011b` option code `0x0d`, reads control `1`, and calls `0x0052a2d0` with `selectedValue != 1`;
    - case `2`: applies control `2` slider word at `+0xfa` through `SoundManager::SetSampleVolume`;
    - case `3`: applies output/playback selection from control `3`, writes `g_pConfig+0x291914`, constructs localized alert `244` when changed, and mutes/unmutes through `SoundManager` depending on selection;
    - case `4`: applies control `4` slider word at `+0xfa` through `SoundManager::SetStreamVolume`;
    - case `5`: writes changed music source mode from control `5` to `g_pConfig+0x291908` and calls `0x0052a120`;
    - case `6`: no-op/default body;
    - case `7`: allocates folder dialog/callback state, reads control `6`, writes callback target `0x00529ee0`, and launches the folder-selection path;
    - case `8`: reads selected drive text from control `8`, parses a drive letter/value, writes `g_pConfig+0x291910` if changed, and calls `0x0052a120`;
    - case `9`: writes `g_pConfig+0x291912 = (control9Selected != 0)`;
    - case `10`: writes `g_pConfig+0x291913 = (control10Selected == 0)`, so this UI selection is inverted relative to the stored repeat/wrap flag;
    - case `11`: previous-track path, stream/local mode calls the previous stream track helper when current index permits, Redbook mode calls `SoundManager::RewindRedbookTrack`, then clears pause through `TogglePauseState` if needed;
    - case `12`: calls `0x0052a180` `TogglePauseState`;
    - case `13`: next-track path, sets `g_pSoundManager+0x40 = 1`, stream/local mode calls `SoundManager::PlayNextTrack`, Redbook mode calls `SoundManager::AdvanceRedbookTrack`, then clears pause through `TogglePauseState` if needed;
    - case `14`: calls the dialog close/accept helper.
  - Verified support-doc offset correction for Redbook playback:
    - `SoundManager::OpenRedbookDrive` uses `g_pConfig+0x291912` for Redbook order randomization, not `+0x2919d2`;
    - Redbook play/advance and local next-track logic use `g_pConfig+0x291913` for repeat/wrap policy, not `+0x2919d3`;
    - `SoundManager::RestartMusic` uses `g_pConfig+0x291908` for music source mode, not `+0x2919c8`.

## Heuristic / Inference Reanalysis And Validation

### Source Placement And Ownership

Keep both target pages owned and emitted by [UID:00008U] `MusicControlDialog`, with source file [UID:0000LN] `MusicControlDialog.cpp`.

Evidence:

- The constructor writes the `MusicControlDialog` vtables, initializes instance state at `this+0x26c`, builds dialog controls, and sends the initial option packet from inside the dialog constructor path.
- The command handler consumes control IDs `1..14`, directly calls or inlines local MusicControlDialog helpers, and stores a `MusicControlDialog` member callback target (`0x00529ee0`) in the folder-selection function object.
- `SoundManager`, `Config`, packet sender, control-pane classes, and `FolderSelectDialog` are dependencies. They do not own the dialog policy. The dialog owns UI construction, config-field writes, and user-command dispatch.
- [UID:0000LN] already rejects generated `ChattingColorPane` pollution for the music path/playback helpers. This pass reinforces that rejection: `0x00529ee0`, `0x0052a120`, `0x0052a180`, and `0x0052a2d0` are reached from this dialog cluster and should stay in `MusicControlDialog.cpp` or file-local helper scope, not in chat code.

Rejected alternatives:

- Do not move [UID:0003MB] or [UID:0003MD] to `SoundManager`. SoundManager owns playback primitives; the targets are UI/controller code.
- Do not move them to `Config` or `RegistryConfig`. Config owns storage; the targets are readers/writers of persisted fields.
- Do not split [UID:0003MD] into a separate source-owned switch-table data page. The table is compiler-generated switch lowering immediately following and exclusively referenced by the method body. The by-memory range should continue to include it, while formal C++ should emit a `switch` statement rather than a literal jump table.
- Do not leave the targets non-emitting only because final original names are not proven. Current supervisor policy uses the `RECONSTRUCTABLE:TRUE`, nonblank emitter, and average score gate; both targets can meet it with descriptive names.

### Constructor Shape And Control Factories

The constructor source shape is defensibly a `MusicControlDialog::MusicControlDialog()` method that delegates visual/control construction to common UI control constructors and then initializes runtime values from config and SoundManager.

Best descriptive control/factory names:

| Binary evidence | Recommended descriptive source role | Rejected or weaker alternative |
| --- | --- | --- |
| `0x00495f70` call family | `RadioGroupControlPane` construction / selection control construction | Generated raw `sub_495f70`; not enough for source docs. |
| `0x00496630` call family | `SliderControlPane` construction | Generic widget helper; not MusicControlDialog-owned. |
| `0x00499030` call family | static/text control construction | Exact original class spelling still depends on control docs, but role is stable. |
| `0x00495bf0` call family | image/button control construction | Not a music playback helper. |
| `0x00498040` plus popup forwarders | popup/menu control construction for CD drive list | Do not model the drive list as a raw string vector owned by config. |
| `0x004991f0` call family | EPF image/resource control construction | Resource art/layout support, not business logic. |
| `0x00496110` | selection value setter for radio/selection controls | Keep generic control helper ownership. |
| `0x004967c0` | slider value setter | Keep generic control helper ownership. |
| `0x00495cb0` | `SelectionControlPaneSetSelectionAndRefresh` for pause/play frame update | Already documented as [UID:00011D], not music-dialog-owned. |

Remaining uncertainty is exact original widget class spelling and constructor parameter names, not the source-role direction. That uncertainty should cap the constructor below final-name quality but should not keep formal C++ blank.

### Config Fields And Instance Fields

Recommended field names are descriptive/inferred. Exact original member spelling is not recovered, but the roles are strong enough for source-quality docs and first-draft C++.

| Field | Recommended descriptive name | Evidence | Confidence and caveat |
| --- | --- | --- | --- |
| `this+0x26c` | `m_musicPaused` or `m_pauseActive` | Constructor clears it; `TogglePauseState` flips it; previous/next paths call `TogglePauseState` when it is set. | Strong role, exact spelling unknown. |
| `g_pConfig+0x28de48` | `soundEffectsEnabled` | [UID:0003MP]/[UID:0003MF] update it and call SoundManager enable/disable helpers; [UID:00028Q] already records sound/effects enablement. | Strong. |
| `g_pConfig+0x28de4c` | `sampleVolume` / `soundEffectVolume` | [UID:0001I9] records sample/SFX volume usage; constructor initializes control `2` via SoundManager accessor. | Strong support-doc role; constructor does not write it directly. |
| `g_pConfig+0x28de54` | `musicVolume` / `streamVolume` | [UID:0001I9] records stream/music volume usage; constructor initializes control `4` via SoundManager accessor. | Strong support-doc role; constructor does not write it directly. |
| `g_pConfig+0x291908` | `musicSourceMode` / `musicPlaybackMode` | Constructor sets control `5`; command case `5` writes it; `ApplyPlaybackState` and `SoundManager::RestartMusic` branch on values `0`, `1`, and `2`. | Strong. Values are `0` disabled/fallback, `1` stream/local/DAT, `2` Redbook/CD. Exact UI labels unknown. |
| `g_pConfig+0x29190c` | `localMusicPath` / `musicFolderPath` | Constructor initializes control `6`; folder callback compares/copies it and rescans local music. | Strong. |
| `g_pConfig+0x291910` | `redbookDriveLetter` / `cdDriveLetter` | Constructor and drive popup compare selected A-Z drive; command case `8` writes parsed selected drive. | Strong. Stored as a wide/word drive letter, not a root-path string. |
| `g_pConfig+0x291912` | `randomizeMusicOrder` / `shuffleMusic` | Constructor initializes control `9`; command case `9` writes it; folder callback passes it to local music scan; `OpenRedbookDrive` randomizes Redbook order when true. | Strong. |
| `g_pConfig+0x291913` | `musicRepeatEnabled` / `repeatMusic` | Constructor initializes control `10` with inverted UI selection; command case `10` writes `selected == 0`; local and Redbook next/advance paths use it for wrap/repeat behavior. | Strong role, exact UI label unknown because of inversion. |
| `g_pConfig+0x291914` | `musicOutputSelection` / `musicPlaybackOutputMode` | Constructor initializes control `3` from `SoundManager::IsPlaybackEnabled()` and this byte; command case `3` and [UID:0003MQ] write it, alert localized id `244`, and mute/unmute SoundManager. | Strong role, exact UI text unknown. |

Rejected alternatives:

- Do not preserve stale `g_config+0x2919c8`, `+0x2919d2`, or `+0x2919d3` in Redbook support docs. Direct PE checks and the MusicControlDialog cluster converge on `+0x291908`, `+0x291912`, and `+0x291913`.
- Do not name `+0x291912` as Redbook-only shuffle. It is also passed into the local music directory scan.
- Do not name `+0x291913` as a simple checkbox value without noting inversion at control `10`; the stored flag is true when control `10` selected value is zero.
- Do not name `+0x291914` as generic `enabled` only. The value participates in output/playback selection and may hold values beyond boolean on the UI side.

### Command IDs And Helper Names

Recommended command/control map:

| ID | Recommended control/source role | Evidence and action |
| --- | --- | --- |
| `1` | `kControlSoundEffects` | Sends option packet `0x011b` with option code `0x0d`; reads selected value from control `1`; calls `ApplySoundEffectEnabled(selected != 1)`. |
| `2` | `kControlSampleVolume` / `kControlSoundEffectVolume` | Reads slider word at `+0xfa`; calls `SoundManager::SetSampleVolume`. |
| `3` | `kControlMusicOutput` / `kControlPlaybackOutput` | Reads selected value at `+0x10c`; applies output selection, alert `244`, mute/unmute. |
| `4` | `kControlMusicVolume` / `kControlStreamVolume` | Reads slider word at `+0xfa`; calls `SoundManager::SetStreamVolume`. |
| `5` | `kControlMusicSourceMode` | Writes changed selected value to `g_pConfig+0x291908`; calls `ApplyPlaybackState`. |
| `6` | `kControlMusicFolderPath` | Constructor and folder callback update the displayed local path; command case is no-op. |
| `7` | `kControlBrowseFolder` | Allocates folder-selection callback object with target `MusicControlDialog::FolderPathSelected`. |
| `8` | `kControlCdDrive` / `kControlRedbookDrive` | Popup/menu selection parsed into `g_pConfig+0x291910`; changed selection reapplies playback. |
| `9` | `kControlShuffleMusic` / `kControlRandomizeMusic` | Writes `g_pConfig+0x291912 = selected != 0`. |
| `10` | `kControlRepeatMusic` | Writes `g_pConfig+0x291913 = selected == 0`; document UI inversion. |
| `11` | `kControlPreviousTrack` | Previous local/Redbook path; clears pause if active. |
| `12` | `kControlPause` / `kControlPausePlay` | Calls `TogglePauseState`; [UID:0003ML] updates icon/frame ids `37`/`48`. |
| `13` | `kControlNextTrack` | Sets `g_pSoundManager+0x40 = 1`; advances local/Redbook; clears pause if active. |
| `14` | `kControlClose` / `kControlOk` | Calls shared dialog close/accept helper. |

Recommended helper names/signatures:

| Address | Recommended name/signature | Evidence |
| --- | --- | --- |
| `0x00529d00` | `void MusicControlDialog::RefreshControlStates()` | Constructor calls it after initialization; [UID:0003MH] shows it enables/disables controls `2`, `4`, `6..13` based on selections in controls `1`, `3`, and `5`. It is not playback application. |
| `0x00529ee0` | `void MusicControlDialog::FolderPathSelected(const String& path)` or equivalent wide-string callback | Command case `7` stores this address in a `PlainMemberFunctionObjectT<MusicControlDialog, String>`; body updates config path, control `6`, local scan, and playback. |
| `0x0052a010` | `void MusicControlDialog::PopulateCdDrivePopup()` | Constructor and support page enumerate A-Z CD drives into control `8`. |
| `0x0052a120` | `void MusicControlDialog::ApplyPlaybackState()` | Command cases `5` and `8`, and folder callback, call it after mode/path/drive changes; body applies modes `0..2`. |
| `0x0052a180` | `void MusicControlDialog::TogglePauseState()` | Case `12` and next/previous cleanup paths call it; toggles `this+0x26c` and calls stream/Redbook pause helpers. |
| `0x0052a2d0` | `void ApplySoundEffectEnabled(bool enabled)` or `MusicControlDialog::ApplySoundEffectEnabled(bool enabled)` | Case `1` only direct caller in this pass; [UID:0003MP] treats it as file-local helper. Either method or file-local helper is source-defensible; file-local is slightly better because support page owner is [UID:0000LN]. |
| `0x0052a310` | `void ApplyOutputSelection(int selection)` | Command case `3` duplicates or calls equivalent output selection behavior; [UID:0003MQ] exact helper body exists. If supervisor chooses de-duplication in source, use this helper name. |
| `0x0052a230` | `void MusicControlDialog::NextTrack()` or hidden/inlined next helper | Body duplicates case `13` pattern but no normal direct xref. Keep as hidden helper child until route is solved. |
| `0x0052a280` | `void MusicControlDialog::PreviousTrack()` or hidden/inlined previous helper | Body duplicates case `11` pattern but no normal direct xref. Keep as hidden helper child until route is solved. |

Rejected alternatives:

- `0x00529d00` should not be called `ApplyPlaybackState`; [UID:0003MH] and constructor evidence show it refreshes enabled/disabled UI state. The playback application helper is `0x0052a120`.
- The case `7` callback is not an anonymous global callback. The command handler writes a concrete `MusicControlDialog` member-function callback target `0x00529ee0`.
- The case `1` packet send should not be described as a bespoke music-packet protocol. It is the same three-byte option/settings opcode family documented by [UID:0001DY]/[UID:0001DQ].

### Packet 0x011b Meaning

`0x011b` is best described as the shared option/settings packet opcode, sent as a three-byte packet `{ word opcode 0x011b, uint8_t optionCode }`.

Evidence:

- [UID:0001DY] and [UID:0001DQ] document the shared helper layout and caller-provided option-code byte.
- MusicControlDialog does not call the shared helper; it inlines the same stack packet/send shape through `g_packetSender` and `QueueAndSendPacket`.
- Constructor sends option code `0`.
- Command case `1` sends option code `0x0d` before applying sound-effect enablement.

Remaining uncertainty:

- The server-side names for option code `0` and `0x0d` are not recovered here. `0x0d` is strongly tied to the sound-effect toggle because it is sent in case `1`; option `0` is an initial music/settings sync request from the constructor. This uncertainty does not affect source owner or first-draft C++ readiness, but it should cap protocol-label confidence below final-original naming.

### Resource Branch And Drive Buffers

`DLGSCNTL.EPF` and `PFLOOK.PAL` are resource literals for the MusicControlDialog visual/control resource branch. They should be recorded in constructor/read-only-data docs but not treated as separate source owners.

The A-Z drive enumeration uses [UID:00027V] buffers:

- ASCII `X:\` at `0x0066debc` for `GetDriveTypeA`.
- UTF-16 `X:` at `0x0066dec0` for popup display text.

The constructor and [UID:0003MJ] use the same buffers and same `GetDriveTypeA == DRIVE_CDROM` filter. That supports one shared descriptive helper direction, `PopulateCdDrivePopup`, and a config field name `redbookDriveLetter` / `cdDriveLetter` for `g_pConfig+0x291910`.

### Switch Table And Generated-Output Policy

[UID:0003MD] should remain one by-memory range covering:

- `0x00529790-0x00529b2e`: source-authored command-handler body.
- `0x00529b2e-0x00529b30`: two-byte alignment.
- `0x00529b30-0x00529b68`: compiler-generated switch table.
- `0x00529b68-0x00529b70`: `0xcc` padding before the next helper.

Formal C++ should contain a `switch (controlId)` and should not emit a literal table. The table belongs in the by-memory evidence and coverage row because it is physically in the target range and exclusively referenced by the dispatch instruction.

### Validation Or Contradiction Of Current Docs

Validated current docs:

- Owner/emitter [UID:00008U] for both targets remains correct.
- [UID:0003MD] range is correct to include the compiler switch table.
- `this+0x26c` pause-state byte is correct.
- `DLGSCNTL.EPF` / `PFLOOK.PAL` resource branch is correct.
- Drive enumeration through [UID:00027V] is correct.
- `g_pConfig+0x291908`, `+0x29190c`, `+0x291910`, `+0x291912`, `+0x291913`, and `+0x291914` are the relevant music-control cluster offsets.
- [UID:0003MH] is the constructor's post-initialization UI state refresh helper.

Contradicted or stale current docs:

- The target Reconstruction Notes saying final C++ should remain blank because control/config/helper names are provisional is now stale. Descriptive names are defensible enough to populate first-draft C++ under the current code-entry gate.
- Any old `95/95` gate wording in class/file/aggregate/support pages is stale. The current policy is not the old `95/95` threshold.
- `SoundManagerRedbookPlayback` support text that says `g_config+0x2919c8`, `+0x2919d2`, or `+0x2919d3` should be corrected to `g_pConfig+0x291908`, `+0x291912`, and `+0x291913`.
- Treating `0x00529d00` as a playback apply helper is stale. It is `RefreshControlStates`; `0x0052a120` is the playback apply helper.

## Recommended Metadata And Score Changes

| UID | Current | Recommended | Owner/emitter | C++ |
| --- | --- | --- | --- | --- |
| [UID:0003MB] | `84/88` | `87/90` | Keep `CANONICAL_OWNER:00008U`, `EMITTER_UIDS:00008U` | Populate first-draft constructor C++. |
| [UID:0003MD] | `84/88` | `88/90` | Keep `CANONICAL_OWNER:00008U`, `EMITTER_UIDS:00008U` | Populate first-draft command-handler C++; do not emit the raw switch table. |

Rationale:

- [UID:0003MB] clears the current code-entry gate: `(87 + 90) / 2 = 88.5`, reconstructable true, direct emitter route present. It remains below final-perfect source quality because exact UI label strings, exact common widget constructor parameter names, and original config member spelling are not recovered.
- [UID:0003MD] clears the current code-entry gate: `(88 + 90) / 2 = 89`, reconstructable true, direct emitter route present. It has stronger behavioral completeness than the constructor because every switch case has a direct control/action mapping and the compiler table is fully bounded. It remains below final-perfect source quality because the original names of output option values and option-packet subcodes are not recovered.
- No owner/emitter change is recommended.
- No range split change is recommended for [UID:0003MD]; the switch table is still part of the by-memory child range.
- [UID:0001CP] aggregate row in coverage should no longer remain at `76%` after its exact child split and the two major child source-quality passes. If the supervisor updates the aggregate now, `87/89` is defensible for the aggregate after applying this report, but aggregate formal C++ can stay blank until the remaining helper children are individually populated.
- [UID:00008U] and [UID:0000LN] may remain `87/87` unless the supervisor wants support-doc score movement. The evidence supports a small support-score bump to `88/88` after applying the config/control table updates, but this assignment does not require changing class/file scores.

## First-Draft C++ Recommendation

Both targets are reconstructable, source-emitting, and clear the current code-entry gate after the score recommendations above. Do not keep formal C++ blank solely because original source spellings are imperfect. Use descriptive names and keep compiler-generated table bytes out of C++.

The following draft is intentionally source-facing rather than byte-for-byte raw decompiler output. It should be inserted into the two target `RECONSTRUCTION_CPP` blocks, with common enums/helper declarations either repeated locally as draft scaffolding or moved to the class/file page by the supervisor.

### Shared Draft Declarations

```cpp
enum MusicControlId {
    kControlSoundEffects = 1,
    kControlSampleVolume = 2,
    kControlMusicOutput = 3,
    kControlMusicVolume = 4,
    kControlMusicSourceMode = 5,
    kControlMusicFolderPath = 6,
    kControlBrowseFolder = 7,
    kControlCdDrive = 8,
    kControlShuffleMusic = 9,
    kControlRepeatMusic = 10,
    kControlPreviousTrack = 11,
    kControlPausePlay = 12,
    kControlNextTrack = 13,
    kControlClose = 14,
};

enum MusicSourceMode {
    kMusicSourceDisabled = 0,
    kMusicSourceStream = 1,
    kMusicSourceRedbook = 2,
};

static void SendMusicDialogOptionPacket(uint8_t optionCode)
{
    uint8_t packet[3];
    packet[0] = 0x1b;
    packet[1] = 0x01;
    packet[2] = optionCode;
    QueueAndSendPacket(g_packetSender, packet, sizeof(packet));
}
```

### [UID:0003MB] Constructor Draft

```cpp
MusicControlDialog::MusicControlDialog()
    : DialogPane()
{
    m_musicPaused = false;

    LoadDialogControlResource(L"DLGSCNTL.EPF", L"PFLOOK.PAL");

    // The exact rectangles/frame ids should be copied from the constructor operands
    // when common control constructors are formalized.
    AddControl(kControlSoundEffects, new RadioGroupControlPane(/* resource/control operands */));
    AddControl(kControlSampleVolume, new SliderControlPane(/* resource/control operands */));
    AddControl(kControlMusicOutput, new RadioGroupControlPane(/* resource/control operands */));
    AddControl(kControlMusicVolume, new SliderControlPane(/* resource/control operands */));
    AddControl(kControlMusicSourceMode, new RadioGroupControlPane(/* resource/control operands */));
    AddControl(kControlMusicFolderPath, new TextEditPane(/* resource/control operands */));
    AddControl(kControlBrowseFolder, new ImageButtonControlPane(/* resource/control operands */));
    AddControl(kControlCdDrive, new PopupMenuControlPane(/* resource/control operands */));
    AddControl(kControlShuffleMusic, new RadioGroupControlPane(/* resource/control operands */));
    AddControl(kControlRepeatMusic, new RadioGroupControlPane(/* resource/control operands */));
    AddControl(kControlPreviousTrack, new ImageButtonControlPane(/* resource/control operands */));
    AddControl(kControlPausePlay, new SelectionControlPane(/* resource/control operands */));
    AddControl(kControlNextTrack, new ImageButtonControlPane(/* resource/control operands */));
    AddControl(kControlClose, new ImageButtonControlPane(/* resource/control operands */));

    SetControlText(kControlMusicFolderPath, g_pConfig->localMusicPath);
    ResetTextSelection(kControlMusicFolderPath, 0, 0);

    PopupMenuControlPane* drivePopup = GetControlAs<PopupMenuControlPane>(kControlCdDrive);
    for (wchar_t drive = L'A'; drive <= L'Z'; ++drive) {
        char rootPath[] = "X:\\";
        wchar_t label[] = L"X:";
        rootPath[0] = static_cast<char>(drive);
        label[0] = drive;

        if (GetDriveTypeA(rootPath) != DRIVE_CDROM) {
            continue;
        }

        const int itemIndex = drivePopup->AppendString(label);
        if (drive == g_pConfig->redbookDriveLetter) {
            drivePopup->SetSelectedIndex(itemIndex);
        }
    }
    drivePopup->AppendString(L"");

    SetSliderValue(kControlSampleVolume, g_pSoundManager->GetSampleVolume());
    SetSliderValue(kControlMusicVolume, g_pSoundManager->GetStreamVolume());

    int outputSelection = 0;
    if (g_pSoundManager->IsPlaybackEnabled()) {
        outputSelection = (g_pConfig->musicOutputSelection == 2) ? 2 : 1;
    }
    SetSelectedValue(kControlMusicOutput, outputSelection);

    // Control 1 stores the inverse of SoundManager's enabled boolean.
    SetSelectedValue(kControlSoundEffects,
        g_pSoundManager->IsSoundEffectsEnabled() ? 0 : 1);

    SetSelectedValue(kControlMusicSourceMode, g_pConfig->musicSourceMode);
    SetSelectedValue(kControlShuffleMusic, g_pConfig->randomizeMusicOrder ? 1 : 0);

    // Control 10 is inverted relative to the persisted repeat/wrap flag.
    SetSelectedValue(kControlRepeatMusic, g_pConfig->musicRepeatEnabled ? 0 : 1);

    RefreshControlStates();
    SendMusicDialogOptionPacket(0);
}
```

Constructor draft notes:

- The draft uses source-facing helper wrappers for control construction because exact common control constructor signatures and layout operands should be copied from the binary by the supervisor or by a dedicated common-control pass. This is not a reason to leave [UID:0003MB] C++ blank.
- `LoadDialogControlResource`, `SetControlText`, `ResetTextSelection`, `SetSliderValue`, and `SetSelectedValue` are descriptive placeholders for already-documented UI helper calls. If the common control docs provide final names, use those instead.
- `SendMusicDialogOptionPacket(0)` represents the constructor's inline stack packet `{0x1b, 0x01, 0x00}` sent through `QueueAndSendPacket`.

### [UID:0003MD] Command Handler Draft

```cpp
void MusicControlDialog::HandleControlCommand(int controlId, int notification)
{
    (void)notification;

    switch (controlId) {
    case kControlSoundEffects: {
        SendMusicDialogOptionPacket(0x0d);

        const int selected = GetSelectedValue(kControlSoundEffects);
        ApplySoundEffectEnabled(selected != 1);
        break;
    }

    case kControlSampleVolume: {
        const uint16_t volume = GetSliderValue(kControlSampleVolume);
        g_pSoundManager->SetSampleVolume(volume);
        break;
    }

    case kControlMusicOutput: {
        const int selected = GetSelectedValue(kControlMusicOutput);
        if (selected == 0) {
            g_pSoundManager->MuteMusic();
            break;
        }

        if (g_pConfig->musicOutputSelection != selected) {
            g_pConfig->musicOutputSelection = static_cast<uint8_t>(selected);
            ShowLocalizedAlert(244);
        }

        if (!g_pSoundManager->IsPlaybackEnabled()) {
            g_pSoundManager->UnmuteMusic();
        }
        break;
    }

    case kControlMusicVolume: {
        const uint16_t volume = GetSliderValue(kControlMusicVolume);
        g_pSoundManager->SetStreamVolume(volume);
        break;
    }

    case kControlMusicSourceMode: {
        const int mode = GetSelectedValue(kControlMusicSourceMode);
        if (g_pConfig->musicSourceMode != mode) {
            g_pConfig->musicSourceMode = mode;
            ApplyPlaybackState();
        }
        break;
    }

    case kControlMusicFolderPath:
        break;

    case kControlBrowseFolder: {
        const String currentPath = GetControlText(kControlMusicFolderPath);
        FolderSelectDialog::Show(
            currentPath,
            PlainMemberFunctionObjectT<MusicControlDialog, String>(
                this, &MusicControlDialog::FolderPathSelected));
        break;
    }

    case kControlCdDrive: {
        PopupMenuControlPane* popup = GetControlAs<PopupMenuControlPane>(kControlCdDrive);
        const int selectedIndex = popup->GetSelectedIndex();
        if (selectedIndex == -1) {
            break;
        }

        const String selectedText = popup->GetSelectedText(selectedIndex);
        const wchar_t driveLetter = ParseDriveLetter(selectedText);
        if (driveLetter != 0 && g_pConfig->redbookDriveLetter != driveLetter) {
            g_pConfig->redbookDriveLetter = driveLetter;
            ApplyPlaybackState();
        }
        break;
    }

    case kControlShuffleMusic:
        g_pConfig->randomizeMusicOrder =
            (GetSelectedValue(kControlShuffleMusic) != 0);
        break;

    case kControlRepeatMusic:
        // The UI selection is inverted relative to the persisted repeat/wrap flag.
        g_pConfig->musicRepeatEnabled =
            (GetSelectedValue(kControlRepeatMusic) == 0);
        break;

    case kControlPreviousTrack: {
        switch (g_pConfig->musicSourceMode) {
        case kMusicSourceStream:
            if (g_pSoundManager->currentStreamTrackIndex() > 1) {
                g_pSoundManager->PlayStreamTrack(
                    g_pSoundManager->currentStreamTrackIndex() - 1,
                    100,
                    true);
            }
            break;

        case kMusicSourceRedbook:
            g_pSoundManager->RewindRedbookTrack();
            break;

        default:
            break;
        }

        if (m_musicPaused) {
            TogglePauseState();
        }
        break;
    }

    case kControlPausePlay:
        TogglePauseState();
        break;

    case kControlNextTrack: {
        g_pSoundManager->setMusicAdvanceRequested(true);

        switch (g_pConfig->musicSourceMode) {
        case kMusicSourceStream:
            g_pSoundManager->PlayNextTrack();
            break;

        case kMusicSourceRedbook:
            g_pSoundManager->AdvanceRedbookTrack();
            break;

        default:
            break;
        }

        if (m_musicPaused) {
            TogglePauseState();
        }
        break;
    }

    case kControlClose:
        CloseDialog();
        break;

    default:
        break;
    }
}
```

Command-handler draft notes:

- `notification` is present because the binary returns with two stack arguments; this pass found no evidence that the second argument affects behavior.
- The draft emits a source switch. The jump table at `0x00529b30-0x00529b68` should remain by-memory evidence only.
- If the supervisor prefers the existing [UID:0003MQ] helper, replace the case `3` inline block with `ApplyOutputSelection(GetSelectedValue(kControlMusicOutput));`. The behavior is equivalent to the documented helper body.
- If the supervisor prefers exact hidden helpers, replace case `11`/`13` bodies with `PreviousTrack()` / `NextTrack()` once [UID:0003MN]/[UID:0003MO] reach caller/source-shape certainty. Current case bodies are directly evidenced and avoid asserting hidden-helper call routes not present in [UID:0003MD].

## Exact Supervisor Changes Required

### [UID:0003MB] Target Page

Metadata replacement:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Populate the formal C++ block with the constructor draft from `## First-Draft C++ Recommendation`.

Replace the current `## Reconstruction Notes` section with:

```markdown
## Reconstruction Notes

The prior blank-C++ blocker is resolved for first-draft emission. The exact original UI labels and common control constructor parameter names are still not fully recovered, but the source-facing constructor shape, owner, resource branch, control roles, config fields, drive enumeration, refresh helper, and initial `0x011b` option-packet send are defensible.

Use descriptive field names for the music-control config cluster until the final `Config` layout is named: `musicSourceMode` at `g_pConfig+0x291908`, `localMusicPath` at `+0x29190c`, `redbookDriveLetter` at `+0x291910`, `randomizeMusicOrder` at `+0x291912`, `musicRepeatEnabled` at `+0x291913`, and `musicOutputSelection` at `+0x291914`. The pause byte at `this+0x26c` should be documented as `m_musicPaused` / `m_pauseActive`.

The constructor's final stack packet is the shared option/settings opcode `0x011b` with option code `0`, sent inline through `g_packetSender` and `QueueAndSendPacket`; it is not a separate music-specific packet protocol.
```

Append to `## Changes`:

```markdown
- 2026-06-18 B003 source-quality pass: raised recommended score to `87/90`, kept owner/emitter [UID:00008U], resolved the stale blank-C++ blocker, tied the constructor to descriptive control IDs/config fields, confirmed `DLGSCNTL.EPF`/`PFLOOK.PAL`, A-Z CD-drive enumeration through [UID:00027V], `RefreshControlStates` at `0x00529d00`, and inline `0x011b` option code `0`; first-draft constructor C++ is ready for supervisor insertion.
```

### [UID:0003MD] Target Page

Metadata replacement:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Populate the formal C++ block with the command-handler draft from `## First-Draft C++ Recommendation`. Do not emit the raw jump table in C++.

Replace the current `## Reconstruction Notes` section with:

```markdown
## Reconstruction Notes

The prior blank-C++ blocker is resolved for first-draft emission. Every command ID `1..14` has a defensible control role and action, the switch table is fully bounded, and the remaining uncertainty is limited to original UI label text, exact option-code server-side names, and final helper spelling.

The by-memory child should continue to cover the method body plus the compiler-generated switch table at `0x00529b30-0x00529b68`. Formal source should be a `switch (controlId)` command handler; it should not emit a literal jump table.

Use descriptive command IDs: sound effects, sample volume, music output, music volume, music source mode, folder path, browse folder, CD drive, shuffle/randomize, repeat/wrap, previous, pause/play, next, and close. Control `10` writes the persisted repeat/wrap flag inverted as `selected == 0`.

The case `1` packet is the shared option/settings opcode `0x011b` with option code `0x0d`, sent inline before applying sound-effect enablement. The exact server-side option name remains unrecovered, but the client-side control route is strong.
```

Append to `## Changes`:

```markdown
- 2026-06-18 B003 source-quality pass: raised recommended score to `88/90`, kept owner/emitter [UID:00008U], decoded the complete `1..14` command map, confirmed switch-table ownership at `0x00529b30-0x00529b68`, identified the folder-selection member callback target `0x00529ee0`, separated `RefreshControlStates` (`0x00529d00`) from `ApplyPlaybackState` (`0x0052a120`), tied cases to config fields `+0x291908/+0x291910/+0x291912/+0x291913/+0x291914`, and provided first-draft command-handler C++.
```

### [UID:00008U] Class Support Page

In `## Data Notes`, replace the current MusicControlDialog config bullets with:

```markdown
- `this + 0x26c` is the dialog pause-state byte, recommended descriptive name `m_musicPaused` / `m_pauseActive`. The constructor clears it, `TogglePauseState` flips it, and previous/next paths clear pause by calling `TogglePauseState` when it is set.
- `g_pConfig + 0x291908` stores the music source/playback mode used by control id `5`: `0` disabled/fallback, `1` stream/local/DAT music, and `2` Redbook/CD music.
- `g_pConfig + 0x29190c` stores the local music folder/path string displayed in control id `6` and consumed by the folder callback/local scanner.
- `g_pConfig + 0x291910` stores the selected Redbook/CD drive letter used by control id `8`.
- `g_pConfig + 0x291912` stores the randomize/shuffle flag used by control id `9`, the local music directory scan, and Redbook track-order construction.
- `g_pConfig + 0x291913` stores the repeat/wrap flag used by control id `10` and local/Redbook next-track paths; control id `10` writes it inverted as `selected == 0`.
- `g_pConfig + 0x291914` stores the music output/playback selection used by control id `3`, the localized alert `244` path, and SoundManager mute/unmute behavior.
- `g_pConfig + 0x28de48` is the sound-effects enablement byte used by control id `1`, the packet handler, and `ApplySoundEffectEnabled`.
- Control id `12` is the pause/play selection control. `TogglePauseState` passes frame ids `37` and `48` into [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md).
```

In `## Method Notes`, adjust helper names if supervisor applies naming cleanup:

```markdown
| `RefreshControlStates` | `0x00529d00-0x00529ed1` | Enables/disables controls from current sound-effect, playback-output, and music-source selections; not the playback-apply helper. |
| `ApplyPlaybackState` | `0x0052a120-0x0052a17f` | Applies `g_pConfig+0x291908` mode to stream/local, Redbook, or disabled/fallback playback. |
| `ApplySoundEffectEnabled` | `0x0052a2d0-0x0052a304` | Applies control id `1` sound-effect enabled state to `g_pConfig+0x28de48` and `SoundManager`. |
| `ApplyOutputSelection` | `0x0052a310-0x0052a3e0` | Applies control id `3` output/playback selection, raises localized alert `244` on change, and mutes/unmutes SoundManager. |
```

Append to `## Changes`:

```markdown
- 2026-06-18 B003 support sync: resolved the constructor/command-handler source-quality blockers for [UID:0003MB] and [UID:0003MD], added the descriptive music-control config cluster names, documented command/control id roles `1..14`, clarified that `0x00529d00` is `RefreshControlStates` and `0x0052a120` is `ApplyPlaybackState`, and documented inline `0x011b` option-code sends from the constructor and sound-effect toggle.
```

### [UID:0000LN] File Support Page

Insert after `## File Role`:

```markdown
The constructor and command-handler targets now clear the current first-draft C++ gate with descriptive names. `MusicControlDialog.cpp` owns the UI/control policy, control ids `1..14`, folder-selection callback setup, music-control config writes, and inline sends of shared option opcode `0x011b` from the constructor and sound-effect toggle. `SoundManager.cpp` remains the playback engine owner; `Config` remains the storage owner; option-packet helpers remain shared protocol support.
```

Append to `## Changes`:

```markdown
- 2026-06-18 B003 source-quality sync: [UID:0003MB] and [UID:0003MD] now have defensible first-draft C++ recommendations. The file still owns the dialog/controller source; generated `ChattingColorPane` helper names remain rejected as owner pollution.
```

### [UID:0001CP] Aggregate Support Page

Replace the stale sentence in `## Score Rationale` that says the large constructor/command-handler still need stable control/helper names with:

```markdown
Completion remains below the final-source band because several helper children still need final original names and source-grade C++, but the constructor [UID:0003MB] and command handler [UID:0003MD] now have source-quality control/config/helper directions and first-draft C++ recommendations from the 2026-06-18 B003 pass.
```

Append to `## Changes`:

```markdown
- 2026-06-18 B003 source-quality sync: resolved the main constructor/command-handler blockers for [UID:0003MB] and [UID:0003MD], including control ids `1..14`, config offsets `+0x291908/+0x29190c/+0x291910/+0x291912/+0x291913/+0x291914`, shared option opcode `0x011b`, `RefreshControlStates` versus `ApplyPlaybackState`, and first-draft C++ readiness. Aggregate score can move to `87/89` if supervisor applies the child updates, while aggregate formal C++ may remain blank until the remaining helper children are handled.
```

### [UID:0001IB] SoundManagerRedbookPlayback Support Correction

In `by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md`, replace the stale config offsets:

```text
g_config+0x2919d2 -> g_pConfig+0x291912
g_config+0x2919d3 -> g_pConfig+0x291913
g_config+0x2919c8 -> g_pConfig+0x291908
```

Exact replacement for the affected behavior bullets:

```markdown
- `0x0057b020` closes an existing `this+0x18` Redbook handle if present, cancels event `0x504e4354`, clears `this+0x18`, `+0x1c`, `+0x20`, and `+0x24`, opens the requested drive with `AIL_redbook_open_drive`, calls the SoundManager volume helper at `0x0057a340`, reads track count with `AIL_redbook_tracks`, and fills the 100-byte order buffer at `this+0x1034`. The order is shuffled through `rand()` when config byte `g_pConfig+0x291912` is true; otherwise it is sequential.
- `0x0057b1b0` cancels event `0x504e4354`, handles out-of-range track requests by either wrapping to track 1 when config byte `g_pConfig+0x291913` is true or clearing the current-track field, then calls `AIL_redbook_track_info`, `AIL_redbook_play`, and schedules the track-ended timer through `0x005975e0`.
- `0x0057b370` calls the SoundManager stop/fade helper at `0x0057a260`, reads music mode from config dword `g_pConfig+0x291908`, closes Redbook and starts DAT/stream track 1 for mode 1, starts Redbook from the first order byte for mode 2, or closes Redbook and optionally restarts stream fallback when mode 0 and local flag `this+0x10a9` is set.
```

Exact replacement for the affected touched-state table rows:

```markdown
| `g_pConfig+0x291908` | Music source/playback mode selector. | `0x0057b370` branches on values 0, 1, and 2. |
| `g_pConfig+0x291912` | Music randomize/shuffle flag. | `0x0057b020` chooses random Redbook order construction when true; MusicControlDialog control id `9` writes the same flag and the local music scanner consumes it. |
| `g_pConfig+0x291913` | Music repeat/wrap flag. | `0x0057b1b0` and `0x0057b240` wrap playback when true; MusicControlDialog control id `10` writes the same flag inverted from UI selection. |
```

Append to that page's change log:

```markdown
- 2026-06-18 B003 support correction: replaced stale `g_config+0x2919c8/+0x2919d2/+0x2919d3` text with `g_pConfig+0x291908/+0x291912/+0x291913` after the MusicControlDialog constructor/command-handler pass and direct PE checks tied the Redbook helpers to the same music-control config cluster.
```

### [UID:00028Q] g_pConfig Support Page

Insert into `## Known Field Clusters` after the `+0x2918fc` row:

```markdown
| `+0x291908..+0x291914` | Music-control settings used by `MusicControlDialog` and `SoundManager`: `+0x291908` music source/playback mode dword (`0` disabled/fallback, `1` stream/local/DAT, `2` Redbook/CD), `+0x29190c` local music folder/path string, `+0x291910` selected Redbook/CD drive letter word, `+0x291912` randomize/shuffle flag used by the local music scanner and Redbook order construction, `+0x291913` repeat/wrap flag used by local and Redbook next-track paths, and `+0x291914` music output/playback selection byte used by MusicControlDialog control id `3`. Names are descriptive/inferred pending final `Config` member spelling. |
```

Append to `## Change Log`:

```markdown
- 2026-06-18 B003 MusicControlDialog support sync: added the `+0x291908..+0x291914` music-control cluster after constructor/command-handler and SoundManager checks tied those fields to MusicControlDialog controls, local music scanning, Redbook drive/order/repeat behavior, and SoundManager mute/unmute paths.
```

### Packet/Network Support Docs

Optional but recommended insertion in [UID:0001DY] `SendOptionPacket11B` after `## Behavior`:

```markdown
MusicControlDialog duplicates this packet shape inline rather than calling this helper: its constructor sends option code `0`, and control id `1` sends option code `0x0d` before applying sound-effect enablement. This confirms `0x011b` as a shared option/settings opcode family, not an option-pane-only protocol.
```

## Coverage Report Replacement Text

Do not edit `by-memory/-coverage-report.md` directly from this report. The supervisor should apply or regenerate coverage.

Placement: in `by-memory/-coverage-report.md`, replace the current [UID:0001CP] row under the `0x00528e60` MusicControlDialog block and insert the two target child rows immediately after it, before the existing [UID:0002N2] callback row. Preserve existing callback/destructor/ignored rows below.

Recommended replacement/insertion block:

```markdown
    - [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md) 0x00528e60-0x0052a535 | aggregate | MusicControlDialog : reconstructable : 87% : strong : MusicControlDialog.cpp aggregate with exact child split through constructor, command handler plus switch table, packet handlers, refresh/playback/pause helpers, folder callback wrappers, scalar deleting destructor, read-only data, and drive-root buffers; B003 2026-06-18 resolves the constructor/command-handler source-quality blockers, while remaining hidden/unreferenced helper children still cap aggregate final C++.
        - [UID:0003MB][0x00528e60-0x0052976c.MusicControlDialogConstructor](by-memory/0x00528e60-0x0052976c.MusicControlDialogConstructor.md) 0x00528e60-0x0052976c | constructor | MusicControlDialogConstructor : reconstructable : 87% : strong : Source-quality pass confirms MusicControlDialog owner/emitter, `DLGSCNTL.EPF`/`PFLOOK.PAL` resource branch, `this+0x26c` pause byte, control tree roles, config cluster `+0x291908/+0x29190c/+0x291910/+0x291912/+0x291913/+0x291914`, A-Z CD-drive enumeration through [UID:00027V], post-init `RefreshControlStates`, inline `0x011b` option code `0`, and first-draft constructor C++ readiness.
        - [UID:0003MD][0x00529790-0x00529b70.MusicControlDialogHandleControlCommand](by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md) 0x00529790-0x00529b70 | method plus switch table | MusicControlDialogHandleControlCommand : reconstructable : 88% : strong : Source-quality pass decodes command ids `1..14`, confirms switch-table ownership at `0x00529b30-0x00529b68`, folder callback target `0x00529ee0`, shared option opcode `0x011b` code `0x0d`, SoundManager/config interactions for SFX, volumes, output, mode, drive, shuffle, repeat, previous/pause/next/close, and first-draft command-handler C++ readiness; formal C++ should emit a source switch, not the raw jump table.
```

If the supervisor does not want to move the aggregate row yet, use only the two child rows above and leave [UID:0001CP] unchanged until a full aggregate rescore pass. The existing [UID:0001CP] `76%` text is stale relative to current split state, but this assignment's required targets are [UID:0003MB] and [UID:0003MD].

Generated stats row expectations after validator/rescore:

```text
0003MB should move from 84/88 to 87/90 with nonblank formal C++.
0003MD should move from 84/88 to 88/90 with nonblank formal C++.
```

## Validation Commands

Supervisor should run these after applying the changes:

> Executable block R001 was removed from this report and preserved verbatim in [0003MB-0003MD-MusicControlDialog-source-quality-removed.md](0003MB-0003MD-MusicControlDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If a live IDA/MCP session is available to the supervisor, re-run:

```text
lookup/decompile 0x00528e60
lookup/decompile 0x00529790
xrefs_to 0x00529b30
xrefs_to 0x00529ee0
xrefs_to 0x0052a120
xrefs_to 0x0052a180
byte/read 0x00529b30-0x00529b70
```

Expected validation results:

- No metadata/header validation errors.
- [UID:0003MB] and [UID:0003MD] have nonblank `RECONSTRUCTION_CPP` blocks.
- No remaining `95/95` or `below final source quality because names are provisional` blocker text on the two target pages.
- Redbook support docs no longer contain the stale offsets `0x2919c8`, `0x2919d2`, or `0x2919d3` unless mentioned explicitly as rejected stale text.
- Coverage rows reflect the new target scores after supervisor application/regeneration.

## Remaining Blockers

- Exact original UI label strings for controls `1..14` were not recovered in this pass. The binary behavior still supports descriptive control names and first-draft C++.
- Exact original `Config` member spellings are not recovered. The recommended names are descriptive and evidence-backed. This caps final-original-name confidence but does not block `85/85+` code entry.
- Exact server-side semantic names for `0x011b` option code `0` and `0x0d` are not recovered. Client-side behavior is clear: constructor sends code `0`; sound-effect toggle sends code `0x0d`.
- Exact common control constructor signatures and layout operand names remain in common control docs, not in these two target pages. The constructor draft uses descriptive helper wrappers for readability; supervisor can inline or expand exact operands if desired.
- Hidden helper call-route questions for [UID:0003MN]/[UID:0003MO] remain outside the two primary targets. [UID:0003MD] directly contains previous/next behavior, so the command-handler draft does not depend on proving hidden-helper calls.
- Current MCP endpoint was unavailable during this run. Existing MCP-backed docs plus direct PE/disassembly checks were sufficient for this report. A live supervisor MCP recheck is still recommended before applying IDA labels or claiming fresh IDB changes.

These blockers cap the targets below final-perfect reconstruction quality but do not justify leaving either target blank or below the current first-draft C++ gate.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0003MB-0003MD-MusicControlDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"0003MB"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003MB-0003MD-MusicControlDialog-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0003MB-0003MD-MusicControlDialog-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003MB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
