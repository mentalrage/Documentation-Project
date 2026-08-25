** TARGET-REPORT-UID:0003ME **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003-goal2-music-control-dialog-helper-family-source-quality-0003ME-0003MR-20260618

Report-only source-quality review for the remaining `MusicControlDialog` helper family after the constructor/command-handler pass.

## Evidence Checked

- Assignment and agent policy files: `tools/leaser/Agents/Supervisor.md`, `tools/leaser/Agents/Agent-B003/goal.md`, `tools/leaser/Agents/Agent-B003/notes.md`, `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.
- Prior B003 applied report: `tools/leaser/Agents/Agent-B003/research/executed/0003MB-0003MD-MusicControlDialog-source-quality.md`.
- Primary helper pages: [UID:0003ME] through [UID:0003MQ], plus [UID:0002N2], [UID:0002N3], and [UID:0003MR].
- Support pages: [UID:00008U] `by-class/MusicControlDialog.md`, [UID:0000LN] `by-file/MusicControlDialog.md`, [UID:0001CP] `0x00528e60-0x0052a535.MusicControlDialog.md`, [UID:0003MB], [UID:0003MD], [UID:0000AL] `PlainMemberFunctionObjectT...MusicControlDialog...`, [UID:0000JO] `FunctionObjects`, [UID:0000JF] `FolderSelectDialog`, [UID:0001CJ] `MiscWorkThreadAndNotifications`, [UID:0001SP] `MiscWorkThreadMessageId`, [UID:00028Q] `g_pConfig`, [UID:0000NV] `SoundManager`, [UID:0001I8] `SoundManagerAudioHelperCluster`, [UID:0001IA] `SoundManagerMusicDirectoryScan`, and [UID:0001IB] `SoundManagerRedbookPlayback`.
- Generated/source-lead checks: `project-documentation/auto-generated/NexusTK/ui/dialogs/MusicControlDialog.cpp` has only the constructor and command-handler drafts; `simroot_v2/class_MusicControlDialog.cpp` still contains older generated helper bodies and stale `ChattingColorPane` pollution.
- Direct PE checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:
  - Relative call/jmp and little-endian VA/RVA pointer scans for `0x00529b70`, `0x00529be0`, `0x00529c60`, `0x00529d00`, `0x00529ee0`, `0x0052a010`, `0x0052a120`, `0x0052a180`, `0x0052a1f0`, `0x0052a230`, `0x0052a280`, `0x0052a2d0`, `0x0052a310`, `0x0052a3e0`, `0x0052a4a0`, and `0x0052a4e0`.
  - Confirmed direct refs: `0x00529be0` vtable pointer at `0x0061fc74`; `0x00529c60` vtable pointer at `0x0061fc7c`; `0x00529d00` call at `0x00529731` plus vtable pointer `0x0061fc50`; `0x00529ee0` member-function pointer store at `0x0052984b`; `0x0052a120` calls at `0x00529b0b` and `0x00529feb`; `0x0052a180` calls/jumps at `0x005299fd`, `0x00529a46`, `0x0052a129`, `0x0052a26a`, and `0x0052a2c4`; `0x0052a2d0` call at `0x005299af`; `0x0052a3e0` vtable pointer at `0x0061fcf8`; `0x0052a4a0` vtable pointer at `0x0061fcec`; `0x0052a4e0` adjustor jumps at `0x0052a444` and `0x0052a44f` plus vtable pointer at `0x0061fc04`.
  - Confirmed no direct rel/VA/RVA refs to `0x00529b70`, `0x0052a010`, `0x0052a1f0`, `0x0052a230`, `0x0052a280`, or `0x0052a310`.
  - Section-mapped byte review for `0x0052a1f0` shows the current [UID:0003MM] filename/range is wrong: bytes `5e 5d c2 04 00` end the body at `0x0052a226`, so the half-open exclusive end must be `0x0052a227`; padding begins at `0x0052a227`.
- Fresh local disassembly rechecks for the ambiguous bodies:
  - [UID:0003MF] confirms payload pointer `[arg+0x0c]`, leading `'#'` check, parse at `payload+5`, inverse control id `1` selection, config byte `g_pConfig+0x28de48`, and SoundManager enable/disable calls.
  - [UID:0003MG] confirms message id `[arg+8] == 0x42446972`, payload pointer `[arg+0x0c]+4`, ANSI/string conversion/destruction calls, clear of `g_pApplication+0x84f`, and no call to [UID:0003MI].
  - [UID:0003MQ] confirms selection zero calls SoundManager mute and returns; changed nonzero selection writes `g_pConfig+0x291914`, constructs localized alert `244`, then calls playback-enabled/unmute helpers.

## Heuristic / Inference Reanalysis And Validation

### Cross-Cutting Field And Helper Names

Use the music-control config cluster names already validated by the constructor/command pass and the `g_pConfig` support page:

| Storage | Recommended descriptive name | Evidence |
| --- | --- | --- |
| `g_pConfig+0x28de48` | `soundEffectsEnabled` | Written by [UID:0003ME], [UID:0003MF], [UID:0003MP]; paired with `SoundManager::EnableSoundEffects`/`DisableSoundEffects`. |
| `g_pConfig+0x291908` | `musicSourceMode` | Values `0/1/2` drive disabled/fallback, stream/local, and Redbook/CD behavior. |
| `g_pConfig+0x29190c` | `localMusicPath` / `musicFolderPath` | Compared/copied by [UID:0003MI], displayed in control id `6`, and passed to `SoundManager::ScanMusicDirectory`. |
| `g_pConfig+0x291910` | `redbookDriveLetter` / `cdDriveLetter` | Compared against A-Z CD enumeration and passed to `SoundManager::OpenRedbookDrive`. |
| `g_pConfig+0x291912` | `randomizeMusicOrder` / `shuffleMusic` | Used by local music scan and Redbook order construction. |
| `g_pConfig+0x291913` | `musicRepeatEnabled` / `repeatMusic` | Inverted UI selection for repeat/wrap behavior. |
| `g_pConfig+0x291914` | `musicOutputSelection` | Written by command case `3` and [UID:0003MQ]; alert `244` is shown on changed nonzero selection. |
| `this+0x26c` | `m_musicPaused` | Constructor clears it, [UID:0003ML] toggles it, [UID:0003MK]/[UID:0003MN]/[UID:0003MO] clear it through `TogglePauseState` when needed. |

Control ids `1..14` should keep the constructor/command names: `kControlSoundEffects`, `kControlSampleVolume`, `kControlMusicOutput`, `kControlMusicVolume`, `kControlMusicSourceMode`, `kControlMusicFolderPath`, `kControlBrowseFolder`, `kControlCdDrive`, `kControlShuffleMusic`, `kControlRepeatMusic`, `kControlPreviousTrack`, `kControlPausePlay`, `kControlNextTrack`, and `kControlClose`.

The shared control virtual slots used by [UID:0003MH] are now source-inferable: slot `+0x4c` is `EnableControl`/`SetEnabled(true)` and slot `+0x50` is `DisableControl`/`SetEnabled(false)`. Evidence: control id `2` sample volume is enabled when sound effects selection is `0` and disabled when selection is nonzero; control id `4` music volume is disabled when output selection is `0` and enabled when nonzero. The same polarity makes mode `0` disable all music controls, mode `1` enable local-folder controls and disable CD drive, and mode `2` disable local-folder controls and enable CD drive.

SoundManager helper names can be descriptive without blocking C++:

- `0x0057a760`: `SoundManager::EnableSoundEffects`.
- `0x0057a770`: `SoundManager::DisableSoundEffects`.
- `0x0057a3e0`: `SoundManager::MuteMusic` or `DisableMusicOutput`; used only for output selection `0`.
- `0x0057a3d0`: `SoundManager::IsPlaybackEnabled`.
- `0x0057a400`: `SoundManager::UnmuteMusic` or `EnableMusicOutput`.
- `0x0057a890`: `SoundManager::ScanMusicDirectory`.
- `0x0057b020`: `SoundManager::OpenRedbookDrive`.
- `0x0057b240`: `SoundManager::AdvanceRedbookTrack`.
- `0x0057b2c0`: `SoundManager::RewindRedbookTrack`.
- `0x0057b2e0`: `SoundManager::SetRedbookPaused`.
- `0x0057b370`: `SoundManager::RestartMusic`.
- `0x0057a4e0`: `SoundManager::SetStreamPaused`.

### [UID:0003ME] `0x00529b70-0x00529bda`

Best name/role: retained raw `MusicControlDialog::ApplySoundEffectPayload` or `MusicControlDialog::ApplySoundEffectPacketValue` body.

Validated behavior: `ecx` is a `MusicControlDialog*`; the helper parses the byte at argument `+5`, retrieves control id `1` through the dialog control manager, sets the control selection inverse to the parsed enable value, writes `g_pConfig+0x28de48`, calls `SoundManager::EnableSoundEffects` if the parsed value is `1`, calls `SoundManager::DisableSoundEffects` otherwise, and returns `true`.

Rejected alternatives:

- Not `TextEditPane`, not generated padding, and not SoundManager-owned: it uses `this+0x15c`/control-manager state, control id `1`, and sits inside the verified MusicControlDialog island.
- Not the live command helper [UID:0003MP]: [UID:0003MP] is file-local, takes a boolean, has a direct call from the command switch, and has no `this`.
- Not the vtable packet handler [UID:0003MF]: [UID:0003MF] checks a leading `'#'` and is vtable-backed at `0x0061fc74`; [UID:0003ME] has no such leading tag check and no recovered vtable/caller.

Source-placement impact: keep `CANONICAL_OWNER:00008U`, `EMITTER_UIDS:00008U`. The no-direct-caller status is now solved as a target-specific no-code reason, not an unknown: direct rel/VA/RVA scans found no entry route, and the live command/vtable paths already cover sound-effect application.

### [UID:0003MF] `0x00529be0-0x00529c5a`

Best name/signature: `bool MusicControlDialog::HandleSoundEffectPacket(const MusicDialogPacketMessage* message)` or `OnSoundEffectPacket`. The packet/message type should be a descriptive interface record with payload pointer at `+0x0c`; exact final class name remains open but no longer blocks first-draft C++.

Validated behavior: returns `false` unless `message->payload[0] == '#'`; parses `payload+5`; updates control id `1` selection inverse; writes `g_pConfig+0x28de48`; calls SoundManager enable/disable; returns `true` after handling.

Rejected alternatives:

- Not raw/no-source: vtable/data pointer at `0x0061fc74` proves an indirect entry.
- Not file-local helper: the body uses `ecx` as `MusicControlDialog*` and the control manager.
- Not packet `0x011b` sender: it consumes packet-like payload; packet `0x011b` is sent inline by constructor/command paths.

Source-placement and C++ impact: keep owner/emitter [UID:00008U]. Populate formal C++ with a descriptive `PacketMessage` type instead of leaving it blank for packet-type uncertainty.

### [UID:0003MG] `0x00529c60-0x00529cf8`

Best name/signature: `bool MusicControlDialog::HandleBrowseDirectoryNotification(const WorkNotification* notification)`.

Validated behavior: checks `notification->messageId == 0x42446972` (`BDir` / `BrowseDirectory`); reads `notification->payload + 4`; if nonempty, runs string conversion/temporary cleanup helpers; then clears `byte [g_pApplication + 0x84f]` and returns `true`. If the id does not match, returns `false`.

Important contradiction of current shallow wording: this body does not call [UID:0003MI] `FolderPathSelected`; direct xref scan for `0x00529ee0` only found the member-function pointer store at `0x0052984b`, and disassembly of `0x00529c60` contains no relative call to `0x00529ee0`. Do not document this handler as the selected-path callback. It is a notification consumer for `BDir` and an application pending-flag clearer.

Pending flag inference: `g_pApplication+0x84f` is best documented as `m_browseDirectoryPending` or `m_pendingBrowseDirectory`. Owner is Application/UI shell state, not MusicControlDialog. MusicControlDialog clears it after consuming a `BDir` notification. There is no evidence to move that field into `MusicControlDialog`.

Rejected alternatives:

- Not FolderSelectDialog-owned: FolderSelectDialog is the modal UI producer; support docs state MusicControlDialog opens it, but the callback wrapper belongs to FunctionObjects/MusicControlDialog use sites.
- Not MiscWorkThread-owned source: `MiscWorkThread` produces/posts `BDir`; this vtable-backed handler consumes it.
- Not safe to call `FolderPathSelected` in first-draft C++ unless a future xref/source path is recovered.

Source-placement and C++ impact: keep owner/emitter [UID:00008U]. Populate first-draft C++ with a conservative notification-consumer body that preserves the observed side effects and leaves the string temporary as a `ConvertAnsiBrowsePathForNotification` placeholder if exact helper semantics are not final.

### [UID:0003MH] `0x00529d00-0x00529ed1`

Best name/signature: `void MusicControlDialog::RefreshControlStates()`.

Resolved helper names: control vtable slot `+0x4c` is enable, slot `+0x50` is disable. Use wrapper names `SetControlEnabled(controlId, bool)` or `ControlPane::SetEnabled(bool)`.

Validated behavior:

- Sound effects selected value `0` enables sample-volume control id `2`; any nonzero value disables it.
- Music output selected value `0` disables music-volume control id `4`; nonzero enables it.
- Music source mode control id `5`:
  - mode `0`: disables ids `6,7,8,9,10,11,12,13`.
  - mode `1`: enables local path/browse ids `6,7`, disables CD drive id `8`, enables ids `9,10,11,12,13`.
  - mode `2`: disables local path/browse ids `6,7`, enables CD drive id `8`, enables ids `9,10,11,12,13`.
  - other values: returns after the sound/music-volume updates.

Rejected alternatives: not a redraw helper and not playback-state application; it only toggles control enablement. The constructor call at `0x00529731` proves the initialization route.

Source-placement and C++ impact: keep owner/emitter [UID:00008U]. Populate formal C++.

### [UID:0003MI] `0x00529ee0-0x0052a00c`

Best name/signature: `void MusicControlDialog::FolderPathSelected(const String& path)`.

Resolved string/config roles:

- Reject empty selected path.
- Compare selected path against `g_pConfig->localMusicPath`; return if identical.
- Copy selected path into `g_pConfig->localMusicPath`.
- Update control id `6` display text and reset the embedded edit selection to `0..0` through `TextEditPane` selection helper `0x0058f2a0`.
- Convert/copy the selected path to the narrow/local path form used by `SoundManager::ScanMusicDirectory`.
- Call `SoundManager::ScanMusicDirectory(path, g_pConfig->randomizeMusicOrder, true)`.
- Call `ApplyPlaybackState`.

Rejected alternatives: generated `ChattingColorPane` ownership is stale; xrefs and constructor/command callback setup route this to MusicControlDialog. It is not just a control-text refresh; it owns config copy, SoundManager scan, and playback reapply.

Source-placement and C++ impact: keep owner/emitter [UID:00008U]. Populate formal C++ with descriptive string helpers.

### [UID:0003MJ] `0x0052a010-0x0052a120`

Best name/signature: `void MusicControlDialog::PopulateCdDrivePopup()`.

Validated behavior: retrieves control id `8`, loops `A` through `Z`, mutates the shared root/label buffers at [UID:00027V] (`"X:\"` and `L"X:"`), calls `GetDriveTypeA`, appends only `DRIVE_CDROM` entries to the popup/list control, selects the entry matching `g_pConfig->redbookDriveLetter`, and appends a final blank entry.

Direct-route issue: direct rel/VA/RVA scan found no entry reference to `0x0052a010`; the constructor contains its own equivalent CD-drive enumeration. Unlike the raw helpers [UID:0003MM]/[UID:0003MN]/[UID:0003MO], this is a modeled IDA function with stable body and source-shaped helper semantics. Treat it as a retained out-of-line private method/helper that may have been inlined or no longer referenced, not as padding or generated artifact.

Rejected alternatives: not FolderSelectDialog drive enumeration; it uses the MusicControlDialog CD-drive control id `8` and music config field `+0x291910`.

Source-placement and C++ impact: keep owner/emitter [UID:00008U]. Populate first-draft C++ but record the no-direct-xref caveat; confidence should remain capped below the directly called helpers.

### [UID:0003MK] `0x0052a120-0x0052a17f`

Best name/signature: `void MusicControlDialog::ApplyPlaybackState()`.

Validated behavior:

- If `m_musicPaused` is set, first calls `TogglePauseState()` to resume/unpause before changing playback mode.
- Reads `g_pConfig->musicSourceMode`.
- Mode `0`: stops current SoundManager stream/music state and calls the UI/zone fallback helper at `0x00509480` through the global at `0x0067a764`. Source-facing name should remain descriptive, such as `RestoreZoneMusicPlayback`, until that UI helper is audited.
- Mode `1`: calls `SoundManager::RestartMusic(0)`.
- Mode `2`: calls `SoundManager::OpenRedbookDrive(g_pConfig->redbookDriveLetter)` and then restarts music.
- Other values return.

Rejected alternatives: not ChattingColorPane-owned; only callers are MusicControlDialog command case `5` and folder-path selected callback. Not the same as `RefreshControlStates`; it changes SoundManager playback.

Source-placement and C++ impact: keep owner/emitter [UID:00008U]. Populate formal C++ using the descriptive UI fallback helper name.

### [UID:0003ML] `0x0052a180-0x0052a1e9`

Best name/signature: `void MusicControlDialog::TogglePauseState()`.

Validated behavior: toggles `m_musicPaused`; if `g_pConfig->musicSourceMode == 1`, calls `SoundManager::SetStreamPaused(m_musicPaused)`; if mode `2`, calls `SoundManager::SetRedbookPaused(m_musicPaused)`; then updates control id `12` through `SelectionControlPaneSetSelectionAndRefresh`. The selected icon id is `37` when paused and `48` when unpaused.

Rejected alternatives: not a command-only helper; it is called from command case `12`, from previous/next helpers when pause is active, and from `ApplyPlaybackState`.

Source-placement and C++ impact: keep owner/emitter [UID:00008U]. Populate formal C++.

### [UID:0003MM] `0x0052a1f0-0x0052a225` Current Page

Required boundary repair: rename/range this page to `0x0052a1f0-0x0052a227.MusicControlDialogRefreshFolderPathControl.md`. The current `0x0052a225` exclusive end cuts through the final `ret 4` immediate. Section-mapped bytes show:

```text
0052a218: 00 6a 00 6a 00 e8 7e 50 06 00 5e 5d c2 04 00 cc
                         body epilogue and ret 4 end here ^^ ^^
```

Best name/role: raw retained `MusicControlDialog::RefreshFolderPathControl` or `SetMusicFolderPathControlText`.

Validated behavior: gets control id `6`, converts incoming wide string to display/control text, calls the text-control update helper, loads the embedded edit child at control offset `+0x10c`, and calls the `TextEditPane` selection helper `0x0058f2a0(0,0)`.

Rejected alternatives:

- Not `SoundManager::ScanMusicDirectory`: this raw helper does not update config, does not call the SoundManager scanner, and does not call `ApplyPlaybackState`.
- Not a replacement for [UID:0003MI]: it is only the UI text/selection subset.
- Not ready for formal C++: no direct caller, vtable slot, function-object member pointer, switch entry, VA pointer, or RVA pointer reaches it.

Source-placement and C++ impact: keep owner/emitter [UID:00008U] after range repair. Do not populate formal C++. The no-code proof is target-specific: the body is raw/no-function, no entry route is recovered, and the live source paths already perform the same control-text update inside constructor and [UID:0003MI].

### [UID:0003MN] `0x0052a230-0x0052a271`

Best name/role: raw retained `MusicControlDialog::NextTrackHelper`.

Validated behavior: sets SoundManager advance-request byte at `SoundManager+0x40` to `1`; in stream mode calls the next-stream-track helper; in Redbook mode calls `SoundManager::AdvanceRedbookTrack`; if `m_musicPaused` is set, tail-jumps to `TogglePauseState`.

Rejected alternatives: not the live next-button command body. Command case `13` contains an inline duplicate. Direct scans found no caller/data pointer to `0x0052a230`.

Source-placement and C++ impact: keep owner/emitter [UID:00008U], but do not populate formal C++. The exact entry/source reason is unresolved after direct caller, switch, vtable, and pointer-route checks.

### [UID:0003MO] `0x0052a280-0x0052a2cb`

Best name/role: raw retained `MusicControlDialog::PreviousTrackHelper`.

Validated behavior: in Redbook mode calls `SoundManager::RewindRedbookTrack`; in stream mode checks the current stream track index and calls `SoundManager::PlayTrackByIndex(index - 1, 100, true)` when the index is greater than `1`; if `m_musicPaused` is set, tail-jumps to `TogglePauseState`.

Rejected alternatives: not the live previous-button command body. Command case `11` contains an inline duplicate. Direct scans found no caller/data pointer to `0x0052a280`.

Source-placement and C++ impact: keep owner/emitter [UID:00008U], but do not populate formal C++. Same target-specific no-code proof as [UID:0003MN].

### [UID:0003MP] `0x0052a2d0-0x0052a304`

Best name/signature: file-local `static void ApplySoundEffectEnabled(bool enabled)`.

Validated behavior: writes `g_pConfig->soundEffectsEnabled` at `+0x28de48`; calls `SoundManager::EnableSoundEffects` when true and `SoundManager::DisableSoundEffects` when false. Only direct caller is [UID:0003MD] command case `1` at `0x005299af`.

Ownership decision: keep `CANONICAL_OWNER:0000LN`, `EMITTER_UIDS:0000LN`. It has no `this`, no class field access, and is best represented as a file-local helper in `MusicControlDialog.cpp`, not a `MusicControlDialog` method and not a SoundManager method.

Source-placement and C++ impact: populate formal C++.

### [UID:0003MQ] `0x0052a310-0x0052a3e0`

Best name/signature: `void MusicControlDialog::ApplyOutputSelection(int selection)`.

Validated behavior and correction:

- If `selection == 0`, it calls SoundManager mute/disable-output helper `0x0057a3e0` and returns. The current page text saying it "restores the prior value" is contradicted by disassembly.
- Otherwise, if the incoming selection differs from `g_pConfig->musicOutputSelection`, it writes `g_pConfig+0x291914`, allocates/constructs the localized alert using id `244` and alert table `0x00613a18`, with `this` as owner/context.
- It then calls `SoundManager::IsPlaybackEnabled`; if false, calls `SoundManager::UnmuteMusic`.

Direct-route issue: no direct rel/VA/RVA ref was found to `0x0052a310`; command case `3` currently contains an inline duplicate. Because this is an IDA-modeled function with stable source-shaped body, keep it as a retained out-of-line private helper and populate C++, with the no-direct-xref caveat. Do not use the no-code policy reserved for raw/no-function helpers.

Source-placement and C++ impact: keep owner/emitter [UID:00008U]. Populate formal C++.

### [UID:0002N2] / [UID:0002N3] Callback Template Support

Best source placement: reusable declaration/template belongs to [UID:0000JO] `FunctionObjects`, with concrete wrapper class [UID:0000AL]. `MusicControlDialog.cpp` owns the construction site and target member [UID:0003MI], not the reusable template declaration. `FolderSelectDialog` consumes an abstract callback and does not own this wrapper.

Recommended metadata repair: change by-memory [UID:0002N2] and [UID:0002N3] from `CANONICAL_OWNER:0001CP` / `EMITTER_UIDS:0001CP` to `CANONICAL_OWNER:0000AL` / `EMITTER_UIDS:0000JO`. The physical address nesting under [UID:0001CP] remains useful coverage context, but the current metadata points at an aggregate instead of the semantic template class/source module.

No formal C++: these are source-declared/generated-binary support. First-draft source should instantiate `PlainMemberFunctionObjectT<MusicControlDialog, String>(this, &MusicControlDialog::FolderPathSelected)` in the command handler and rely on the shared template declaration; it should not hand-write the invoke wrapper or scalar deleting destructor body.

Coverage issue: `by-memory/-coverage-report.md` still shows stale `76%` and `74%` rows even though both pages are now `85/88`.

### [UID:0003MR] `0x0052a4e0-0x0052a535`

Best role: `MusicControlDialog` scalar deleting destructor wrapper generated from the class destructor.

Validated behavior: vtable-backed wrapper resets/tears down MusicControlDialog base state and conditionally deletes storage; adjustor thunk jumps at `0x0052a444` and `0x0052a44f` route into this deleting destructor path.

Rejected alternatives: not a source-authored hand-written helper and not file-local. Source should declare/destruct `MusicControlDialog`; compiler should regenerate scalar deleting destructor and adjustor thunks.

Source-placement and C++ impact: keep owner/emitter [UID:00008U]. Do not populate standalone formal C++ for this page.

## Recommended Metadata And Score Changes

| UID | Current | Recommended | Owner/emitter recommendation | C++ recommendation |
| --- | --- | --- | --- | --- |
| 0003ME | `85/86` | `86/88` | keep `00008U` / `00008U` | Keep blank; raw/no-entry no-code proof. |
| 0003MF | `85/88` | `87/90` | keep `00008U` / `00008U` | Populate first-draft C++. |
| 0003MG | `85/88` | `87/90` | keep `00008U` / `00008U` | Populate first-draft C++. |
| 0003MH | `85/88` | `88/90` | keep `00008U` / `00008U` | Populate first-draft C++. |
| 0003MI | `86/90` | `88/92` | keep `00008U` / `00008U` | Populate first-draft C++. |
| 0003MJ | `86/91` | `87/91` | keep `00008U` / `00008U` | Populate first-draft C++; record no-direct-xref caveat. |
| 0003MK | `86/91` | `88/92` | keep `00008U` / `00008U` | Populate first-draft C++. |
| 0003ML | `86/91` | `88/92` | keep `00008U` / `00008U` | Populate first-draft C++. |
| 0003MM | `85/88` | `86/88` after range repair | keep `00008U` / `00008U`; rename range to `0x0052a1f0-0x0052a227` | Keep blank; raw/no-entry no-code proof. |
| 0003MN | `85/88` | `86/88` | keep `00008U` / `00008U` | Keep blank; raw/no-entry no-code proof. |
| 0003MO | `85/88` | `86/88` | keep `00008U` / `00008U` | Keep blank; raw/no-entry no-code proof. |
| 0003MP | `86/90` | `88/92` | keep `0000LN` / `0000LN` | Populate first-draft C++ as file-local helper. |
| 0003MQ | `85/88` | `87/89` | keep `00008U` / `00008U` | Populate first-draft C++; record no-direct-xref caveat. |
| 0002N2 | `85/88` | `85/88` | change `0001CP` / `0001CP` to `0000AL` / `0000JO` | Keep blank; template-generated wrapper. |
| 0002N3 | `85/88` | `85/88` | change `0001CP` / `0001CP` to `0000AL` / `0000JO` | Keep blank; template-generated destructor. |
| 0003MR | `86/90` | `86/90` | keep `00008U` / `00008U` | Keep blank; scalar deleting destructor generated from class destructor. |
| 0001CP | `87/89` | `88/90` | keep `0000LN` aggregate routing | Aggregate C++ remains blank; children should emit individually. |

Do not inflate any raw/no-entry helper above this band until a caller/table/vtable/member-pointer route is recovered. The raw bodies clear the documentation gate because behavior and ownership are strong, but not the formal source-entry gate.

## First-Draft C++ Recommendation

Shared draft declarations used by the snippets:

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

struct MusicDialogPacketMessage {
    uint32_t reserved0;
    uint32_t messageId;
    const char* payload;
};
```

Recommended formal C++ for [UID:0003MF]:

```cpp
bool MusicControlDialog::HandleSoundEffectPacket(const MusicDialogPacketMessage* message)
{
    const char* payload = message->payload;
    if (payload == nullptr || payload[0] != '#')
        return false;

    const bool enabled = ParseOptionByte(payload + 5) == 1;
    SetSelectedValue(kControlSoundEffects, enabled ? 0 : 1);

    g_pConfig->soundEffectsEnabled = enabled ? 1 : 0;
    if (enabled)
        g_pSoundManager->EnableSoundEffects();
    else
        g_pSoundManager->DisableSoundEffects();

    return true;
}
```

Recommended formal C++ for [UID:0003MG]:

```cpp
bool MusicControlDialog::HandleBrowseDirectoryNotification(
    const MusicDialogPacketMessage* notification)
{
    constexpr uint32_t kBrowseDirectoryNotification = 0x42446972; // BDir

    if (notification->messageId != kBrowseDirectoryNotification)
        return false;

    const char* path = notification->payload != nullptr
        ? notification->payload + 4
        : "";

    if (*path != '\0')
        ConsumeBrowseDirectoryPathString(path);

    g_pApplication->m_browseDirectoryPending = false;
    return true;
}
```

`ConsumeBrowseDirectoryPathString` is intentionally descriptive. The observed body constructs and destroys string temporaries from `payload+4`; it does not call `FolderPathSelected`, so the formal C++ must not invent that callback until a future xref proves it.

Recommended formal C++ for [UID:0003MH]:

```cpp
void MusicControlDialog::RefreshControlStates()
{
    SetControlEnabled(kControlSampleVolume,
        GetSelectedValue(kControlSoundEffects) == 0);
    SetControlEnabled(kControlMusicVolume,
        GetSelectedValue(kControlMusicOutput) != 0);

    switch (GetSelectedValue(kControlMusicSourceMode))
    {
    case kMusicSourceDisabled:
        SetControlEnabled(kControlMusicFolderPath, false);
        SetControlEnabled(kControlBrowseFolder, false);
        SetControlEnabled(kControlCdDrive, false);
        SetControlEnabled(kControlShuffleMusic, false);
        SetControlEnabled(kControlRepeatMusic, false);
        SetControlEnabled(kControlPreviousTrack, false);
        SetControlEnabled(kControlPausePlay, false);
        SetControlEnabled(kControlNextTrack, false);
        return;

    case kMusicSourceStream:
        SetControlEnabled(kControlMusicFolderPath, true);
        SetControlEnabled(kControlBrowseFolder, true);
        SetControlEnabled(kControlCdDrive, false);
        break;

    case kMusicSourceRedbook:
        SetControlEnabled(kControlMusicFolderPath, false);
        SetControlEnabled(kControlBrowseFolder, false);
        SetControlEnabled(kControlCdDrive, true);
        break;

    default:
        return;
    }

    SetControlEnabled(kControlShuffleMusic, true);
    SetControlEnabled(kControlRepeatMusic, true);
    SetControlEnabled(kControlPreviousTrack, true);
    SetControlEnabled(kControlPausePlay, true);
    SetControlEnabled(kControlNextTrack, true);
}
```

Recommended formal C++ for [UID:0003MI]:

```cpp
void MusicControlDialog::FolderPathSelected(const String& path)
{
    if (path.empty())
        return;

    if (g_pConfig->localMusicPath == path)
        return;

    g_pConfig->localMusicPath = path;
    SetControlText(kControlMusicFolderPath, path);
    ResetTextSelection(kControlMusicFolderPath, 0, 0);

    std::string narrowPath = ToNarrowPath(path);
    g_pSoundManager->ScanMusicDirectory(
        narrowPath.c_str(),
        g_pConfig->randomizeMusicOrder != 0,
        true);

    ApplyPlaybackState();
}
```

Recommended formal C++ for [UID:0003MJ]:

```cpp
void MusicControlDialog::PopulateCdDrivePopup()
{
    PopupMenuControlPane* popup = GetControlAs<PopupMenuControlPane>(kControlCdDrive);

    for (wchar_t drive = L'A'; drive <= L'Z'; ++drive)
    {
        char rootPath[] = "X:\\";
        wchar_t label[] = L"X:";
        rootPath[0] = static_cast<char>(drive);
        label[0] = drive;

        if (GetDriveTypeA(rootPath) != DRIVE_CDROM)
            continue;

        const int index = popup->AppendString(label);
        if (drive == g_pConfig->redbookDriveLetter)
            popup->SetSelectedIndex(index);
    }

    popup->AppendString(L"");
}
```

Recommended formal C++ for [UID:0003MK]:

```cpp
void MusicControlDialog::ApplyPlaybackState()
{
    if (m_musicPaused)
        TogglePauseState();

    switch (g_pConfig->musicSourceMode)
    {
    case kMusicSourceDisabled:
        g_pSoundManager->StopMusicPlayback(0);
        RestoreZoneMusicPlayback(g_pMainUiLayer);
        break;

    case kMusicSourceStream:
        g_pSoundManager->RestartMusic(0);
        break;

    case kMusicSourceRedbook:
        g_pSoundManager->OpenRedbookDrive(g_pConfig->redbookDriveLetter);
        g_pSoundManager->RestartMusic(0);
        break;

    default:
        break;
    }
}
```

`RestoreZoneMusicPlayback` names the `0x00509480` UI/zone fallback helper descriptively. Keep it descriptive until that target is audited.

Recommended formal C++ for [UID:0003ML]:

```cpp
void MusicControlDialog::TogglePauseState()
{
    m_musicPaused = !m_musicPaused;

    if (g_pConfig->musicSourceMode == kMusicSourceStream)
        g_pSoundManager->SetStreamPaused(m_musicPaused);
    else if (g_pConfig->musicSourceMode == kMusicSourceRedbook)
        g_pSoundManager->SetRedbookPaused(m_musicPaused);

    SetSelectedValue(kControlPausePlay, m_musicPaused ? 37 : 48);
}
```

Recommended formal C++ for [UID:0003MP]:

```cpp
static void ApplySoundEffectEnabled(bool enabled)
{
    g_pConfig->soundEffectsEnabled = enabled ? 1 : 0;

    if (enabled)
        g_pSoundManager->EnableSoundEffects();
    else
        g_pSoundManager->DisableSoundEffects();
}
```

Recommended formal C++ for [UID:0003MQ]:

```cpp
void MusicControlDialog::ApplyOutputSelection(int selection)
{
    if (selection == 0)
    {
        g_pSoundManager->MuteMusic();
        return;
    }

    if (g_pConfig->musicOutputSelection != selection)
    {
        g_pConfig->musicOutputSelection = static_cast<uint8_t>(selection);
        ShowLocalizedAlert(244);
    }

    if (!g_pSoundManager->IsPlaybackEnabled())
        g_pSoundManager->UnmuteMusic();
}
```

Target-specific no-code proofs:

- [UID:0003ME]: keep formal C++ blank. Raw/no-function body, no direct caller, no VA/RVA pointer, no vtable/member-pointer route; live command and packet paths cover the sound-effect logic.
- [UID:0003MM]: keep formal C++ blank and repair range first. Raw/no-function body, no direct caller/pointer/table route, and behavior is only the control-text subset already present in live constructor/folder callback paths.
- [UID:0003MN] and [UID:0003MO]: keep formal C++ blank. Raw/no-function bodies, no caller/pointer/table route, and command cases `13` and `11` contain inline duplicates.
- [UID:0002N2] and [UID:0002N3]: keep formal C++ blank. They are template-generated callback wrappers; emit the template declaration and the MusicControlDialog construction site instead.
- [UID:0003MR]: keep formal C++ blank. The class destructor declaration should regenerate scalar deleting destructor and adjustor thunks.

## Exact Supervisor Changes Required

1. Apply the metadata/score changes from the table above.

2. Rename and repair [UID:0003MM]:

```text
Rename:
source-3/project-documentation/by-memory/0x0052a1f0-0x0052a225.MusicControlDialogRefreshFolderPathControl.md
to:
source-3/project-documentation/by-memory/0x0052a1f0-0x0052a227.MusicControlDialogRefreshFolderPathControl.md

Replace title:
# 0x0052a1f0-0x0052a225 MusicControlDialog RefreshFolderPathControl
with:
# 0x0052a1f0-0x0052a227 MusicControlDialog RefreshFolderPathControl

Replace Status address range bullet:
- Address range: `0x0052a1f0-0x0052a225` exclusive end.
with:
- Address range: `0x0052a1f0-0x0052a227` exclusive end.

Append to IDA Evidence:
- 2026-06-18 B003 PE byte recheck corrected the exclusive end from `0x0052a225` to `0x0052a227`: the final `ret 4` bytes are `c2 04 00` at `0x0052a224-0x0052a226`, and `0x0052a227-0x0052a230` is `0xcc` alignment before [UID:0003MN].
```

3. Replace [UID:0003MQ] behavior text with this corrected version:

```text
This helper applies the music-output selection. When the incoming selection is zero it calls the SoundManager mute/disable-output helper and returns without writing `g_pConfig+0x291914`. For nonzero selections, it compares the incoming value with `g_pConfig+0x291914`; when changed, it stores the byte, constructs localized alert `244` through alert table `0x00613a18` using this dialog as owner/context, then ensures SoundManager playback output is active by calling the playback-enabled probe and unmute helper when needed.
```

4. Update [UID:0002N2] and [UID:0002N3] metadata:

```text
*** CANONICAL_OWNER:0000AL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Append to each page's reconstruction notes:

```text
2026-06-18 B003 source-quality recheck: the physical bytes stay nested in the MusicControlDialog island for coverage, but semantic ownership is the concrete `PlainMemberFunctionObjectT<MusicControlDialog, String>` wrapper class and the reusable `FunctionObjects` template source. MusicControlDialog owns the construction site and target member only. Formal C++ stays blank because the invoke/destructor bodies are compiler-generated from the template declaration.
```

5. Update [UID:0001CP] aggregate row/table entries:

```text
Replace the [UID:0003MM] child link/range with [UID:0003MM][0x0052a1f0-0x0052a227.MusicControlDialogRefreshFolderPathControl](by-memory/0x0052a1f0-0x0052a227.MusicControlDialogRefreshFolderPathControl.md).
Replace its role summary with: "hidden folder-path/control text refresh helper | IDA-unpromoted body that updates control id `6` display text and resets the embedded TextEditPane selection; no config copy or SoundManager scan."
Raise the aggregate score text from `87/89` to `88/90` and state that first-draft C++ is now ready for the modeled helper children while raw no-entry children remain deliberately blank.
```

6. Update [UID:0000LN] `by-file/MusicControlDialog.md` support text:

```text
Add after the constructor/command-handler source-quality paragraph:
The 2026-06-18 B003 helper-family pass resolves the remaining modeled helper names enough for first-draft C++: sound-effect packet handling, browse-directory notification handling, control enablement refresh, folder-path selection, CD-drive popup population, playback-state application, pause toggling, file-local sound-effect enablement, and output-selection application. Raw/no-function retained bodies at `0x00529b70`, `0x0052a1f0`, `0x0052a230`, and `0x0052a280` remain documented but intentionally blank because no entry route was recovered. `0x0052a010` and `0x0052a310` are IDA-modeled retained helper functions with no current direct xref and should still receive source drafts with that caveat.
```

7. Update [UID:00008U] `by-class/MusicControlDialog.md` method/support notes with the same helper names and no-code policy:

```text
Use `RefreshControlStates`, `FolderPathSelected`, `PopulateCdDrivePopup`, `ApplyPlaybackState`, `TogglePauseState`, and `ApplyOutputSelection` as class methods. Keep `ApplySoundEffectEnabled(bool)` file-local under [UID:0000LN]. Record raw helper no-code proofs for `0x00529b70`, `0x0052a1f0-0x0052a227`, `0x0052a230`, and `0x0052a280`; they are MusicControlDialog-owned source-like retained bodies, but no caller, table, vtable, function-object pointer, VA pointer, or RVA pointer route was recovered.
```

8. Generated output policy:

```text
Do not hand-edit `project-documentation/auto-generated/NexusTK/ui/dialogs/MusicControlDialog.cpp`. After supervisor applies formal C++ to the eligible by-memory pages, regenerate output through the normal validator/autogen path. The current generated file contains only [UID:0003MB] and [UID:0003MD] drafts.
```

9. Validation commands for supervisor after applying changes:

> Executable block R001 was removed from this report and preserved verbatim in [0003ME-0003MR-MusicControlDialogHelperFamily-source-quality-removed.md](0003ME-0003MR-MusicControlDialogHelperFamily-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Coverage Report Replacement Text

Placement: replace the current [UID:0001CP] aggregate block in `by-memory/-coverage-report.md` from the line beginning:

```text
    - [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog]
```

through the existing [UID:0002N3] child row, leaving the following `0x0052a535-0x0052a540` padding row in place.

```text
    - [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md) 0x00528e60-0x0052a535 | aggregate | MusicControlDialog : reconstructable : 88% : strong : MusicControlDialog.cpp aggregate with exact child split through constructor, destructors, command handler plus switch table, packet/notification handlers, refresh/playback/pause helpers, retained raw helper bodies, folder callback wrappers, read-only data, and drive-root buffers; B003 2026-06-18 resolves modeled helper C++ readiness while raw no-entry helper children remain intentionally blank.
        - [UID:0003MB][0x00528e60-0x0052976c.MusicControlDialogConstructor](by-memory/0x00528e60-0x0052976c.MusicControlDialogConstructor.md) 0x00528e60-0x0052976c | constructor | MusicControlDialogConstructor : reconstructable : 87% : strong : Source-quality pass confirms MusicControlDialog owner/emitter, `DLGSCNTL.EPF`/`PFLOOK.PAL` resource branch, `this+0x26c` pause byte, control tree roles, config cluster `+0x291908/+0x29190c/+0x291910/+0x291912/+0x291913/+0x291914`, A-Z CD-drive enumeration, post-init `RefreshControlStates`, inline `0x011b` option code `0`, and first-draft constructor C++ readiness.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0052976c-0x00529770 | padding | MusicControlDialog constructor to non-deleting destructor alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
        - [UID:0003MC][0x00529770-0x0052978f.MusicControlDialogNonDeletingDestructor](by-memory/0x00529770-0x0052978f.MusicControlDialogNonDeletingDestructor.md) 0x00529770-0x0052978f | destructor helper | MusicControlDialogNonDeletingDestructor : reconstructable : 86% : strong : Source-declared/generated-binary non-deleting destructor path that restores three MusicControlDialog vtables and tears down the base dialog; formal source should come from the class destructor declaration, not a handwritten standalone helper.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0052978f-0x00529790 | padding | MusicControlDialog destructor to command handler alignment : ignored : 100% : strong : Confirmed `0xcc` alignment byte.
        - [UID:0003MD][0x00529790-0x00529b70.MusicControlDialogHandleControlCommand](by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md) 0x00529790-0x00529b70 | method plus switch table | MusicControlDialogHandleControlCommand : reconstructable : 88% : strong : Source-quality pass decodes command ids `1..14`, confirms switch-table ownership at `0x00529b30-0x00529b68`, folder callback target `0x00529ee0`, shared option opcode `0x011b` code `0x0d`, SoundManager/config interactions, and first-draft command-handler C++ readiness.
        - [UID:0003ME][0x00529b70-0x00529bda.MusicControlDialogUnmodeledSoundEffectApply](by-memory/0x00529b70-0x00529bda.MusicControlDialogUnmodeledSoundEffectApply.md) 0x00529b70-0x00529bda | raw helper | MusicControlDialogUnmodeledSoundEffectApply : reconstructable : 86% : strong : Raw MusicControlDialog sound-effect value helper with corrected boundary, control id `1`, `g_pConfig+0x28de48`, and SoundManager enable/disable behavior; no caller/table/vtable/VA/RVA route recovered, so formal C++ remains blank by target-specific no-code proof.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00529bda-0x00529be0 | padding | Sound-effect raw helper to packet handler alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
        - [UID:0003MF][0x00529be0-0x00529c5a.MusicControlDialogSoundEffectPacketHandler](by-memory/0x00529be0-0x00529c5a.MusicControlDialogSoundEffectPacketHandler.md) 0x00529be0-0x00529c5a | vtable packet handler | MusicControlDialogSoundEffectPacketHandler : reconstructable : 87% : strong : Vtable-backed handler at `0x0061fc74` that accepts `'#'` payloads, parses `payload+5`, updates sound-effect control id `1`, writes `g_pConfig+0x28de48`, calls SoundManager enable/disable helpers, and is ready for descriptive first-draft C++.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00529c5a-0x00529c60 | padding | Sound-effect packet handler to BDir notification handler alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
        - [UID:0003MG][0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler](by-memory/0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler.md) 0x00529c60-0x00529cf8 | vtable notification handler | MusicControlDialogDirectoryPacketHandler : reconstructable : 87% : strong : Vtable-backed `BDir`/browse-directory notification consumer at `0x0061fc7c`; checks id `0x42446972`, processes payload path text, clears `g_pApplication+0x84f` pending-browse flag, and does not call `FolderPathSelected`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00529cf8-0x00529d00 | padding | BDir handler to refresh-control-state alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
        - [UID:0003MH][0x00529d00-0x00529ed1.MusicControlDialogRefreshControlStates](by-memory/0x00529d00-0x00529ed1.MusicControlDialogRefreshControlStates.md) 0x00529d00-0x00529ed1 | method | MusicControlDialogRefreshControlStates : reconstructable : 88% : strong : Direct constructor-called control-state refresh; resolves control virtual slot `+0x4c` as enable and `+0x50` as disable, and maps source modes `0/1/2` to disabled/local/CD control enablement.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00529ed1-0x00529ee0 | padding | RefreshControlStates to FolderPathSelected alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
        - [UID:0003MI][0x00529ee0-0x0052a00c.MusicControlDialogFolderPathSelected](by-memory/0x00529ee0-0x0052a00c.MusicControlDialogFolderPathSelected.md) 0x00529ee0-0x0052a00c | method | MusicControlDialogFolderPathSelected : reconstructable : 88% : strong : Folder-selection callback target stored by command case `7`; rejects empty/unchanged paths, copies `g_pConfig+0x29190c`, updates control id `6`, resets TextEditPane selection, scans the local music folder with shuffle flag `+0x291912`, and reapplies playback.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0052a00c-0x0052a010 | padding | FolderPathSelected to DrivePopupPopulate alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
        - [UID:0003MJ][0x0052a010-0x0052a120.MusicControlDialogDrivePopupPopulate](by-memory/0x0052a010-0x0052a120.MusicControlDialogDrivePopupPopulate.md) 0x0052a010-0x0052a120 | method/helper | MusicControlDialogDrivePopupPopulate : reconstructable : 87% : strong : Modeled helper that populates CD-drive popup control id `8` by looping A-Z, using drive-root buffers, `GetDriveTypeA`, and `g_pConfig+0x291910`; no direct xref was recovered, but the source-shaped IDA-modeled helper is suitable for draft C++ with caveat.
        - [UID:0003MK][0x0052a120-0x0052a17f.MusicControlDialogApplyPlaybackState](by-memory/0x0052a120-0x0052a17f.MusicControlDialogApplyPlaybackState.md) 0x0052a120-0x0052a17f | method | MusicControlDialogApplyPlaybackState : reconstructable : 88% : strong : Called by command handler and folder callback; clears pause through `TogglePauseState`, applies config source mode `+0x291908`, opens Redbook drive `+0x291910`, restarts SoundManager music, or restores zone/fallback playback.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0052a17f-0x0052a180 | padding | ApplyPlaybackState to TogglePauseState alignment : ignored : 100% : strong : Confirmed `0xcc` alignment byte.
        - [UID:0003ML][0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState](by-memory/0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState.md) 0x0052a180-0x0052a1e9 | method | MusicControlDialogTogglePauseState : reconstructable : 88% : strong : Toggles `this+0x26c`, calls stream or Redbook pause helpers for config mode `1` or `2`, and sets pause/play control id `12` to icon `37` when paused or `48` when unpaused.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0052a1e9-0x0052a1f0 | padding | TogglePauseState to raw folder-control helper alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
        - [UID:0003MM][0x0052a1f0-0x0052a227.MusicControlDialogRefreshFolderPathControl](by-memory/0x0052a1f0-0x0052a227.MusicControlDialogRefreshFolderPathControl.md) 0x0052a1f0-0x0052a227 | raw helper | MusicControlDialogRefreshFolderPathControl : reconstructable : 86% : strong : Raw/no-function control id `6` text refresh helper; corrected exclusive end includes full `ret 4`, updates display text and resets embedded TextEditPane selection only, with no config copy or SoundManager scan; no caller/table/vtable/VA/RVA route recovered, so formal C++ remains blank.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0052a227-0x0052a230 | padding | Raw folder-control helper to next-track helper alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
        - [UID:0003MN][0x0052a230-0x0052a271.MusicControlDialogNextTrackHelper](by-memory/0x0052a230-0x0052a271.MusicControlDialogNextTrackHelper.md) 0x0052a230-0x0052a271 | raw helper | MusicControlDialogNextTrackHelper : reconstructable : 86% : strong : Raw/no-function retained next-track helper that marks SoundManager advance request, advances stream or Redbook playback, and tail-clears pause through `TogglePauseState`; no entry route recovered and command case `13` contains the live inline duplicate.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0052a271-0x0052a280 | padding | Next-track helper to previous-track helper alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
        - [UID:0003MO][0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper](by-memory/0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper.md) 0x0052a280-0x0052a2cb | raw helper | MusicControlDialogPreviousTrackHelper : reconstructable : 86% : strong : Raw/no-function retained previous-track helper that rewinds Redbook or plays previous stream track and tail-clears pause through `TogglePauseState`; no entry route recovered and command case `11` contains the live inline duplicate.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0052a2cb-0x0052a2d0 | padding | Previous-track helper to file-local SFX helper alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
        - [UID:0003MP][0x0052a2d0-0x0052a304.MusicControlDialogApplySoundEffectEnabled](by-memory/0x0052a2d0-0x0052a304.MusicControlDialogApplySoundEffectEnabled.md) 0x0052a2d0-0x0052a304 | file-local helper | MusicControlDialogApplySoundEffectEnabled : reconstructable : 88% : strong : Direct command-handler helper with no `this`; file-local `ApplySoundEffectEnabled(bool)` writes `g_pConfig+0x28de48` and calls SoundManager enable/disable helpers.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0052a304-0x0052a310 | padding | SFX helper to output-selection helper alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
        - [UID:0003MQ][0x0052a310-0x0052a3e0.MusicControlDialogApplyOutputSelection](by-memory/0x0052a310-0x0052a3e0.MusicControlDialogApplyOutputSelection.md) 0x0052a310-0x0052a3e0 | method/helper | MusicControlDialogApplyOutputSelection : reconstructable : 87% : strong : Modeled retained helper for music-output selection; selection `0` mutes/disabled output and returns, changed nonzero selection writes `g_pConfig+0x291914`, constructs localized alert `244`, and unmutes if playback output is inactive; no direct xref was recovered, but source-shaped helper is suitable for draft C++ with caveat.
        - [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md) 0x0052a3e0-0x0052a43e | template method | MusicControlDialogFolderCallbackInvoke : reconstructable : 85% : strong : Vtable/data-referenced `PlainMemberFunctionObjectT<MusicControlDialog, String>` invoke wrapper; semantic owner should route to [UID:0000AL]/[UID:0000JO], while MusicControlDialog owns the construction site and target member.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0052a43e-0x0052a454 | compiler-generated adjustor thunks | MusicControlDialogFolderCallbackDestructorAdjustorThunks : ignored : 80% : strong : This-adjustor thunks subtract `0xa0` or `0xa4` and forward to the callback scalar deleting destructor path; source declarations should regenerate them.
        - [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md) 0x0052a460-0x0052a49e | template destructor | FunctionObjectTStringDestructor : reconstructable : 80% : strong : Attached to FunctionObjects; exact string-argument callback-template scalar deleting destructor with IDA endpoint/body evidence, source-declared/generated-binary handling, parent-gate cleanup, StringBase type-name evidence, neighboring wrapper separation, and blank final C++ while final template/header shape remains open.
        - [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md) 0x0052a4a0-0x0052a4de | template destructor | MusicControlDialogFolderCallbackDestructor : reconstructable : 85% : strong : Vtable/data-referenced `PlainMemberFunctionObjectT<MusicControlDialog, String>` scalar deleting destructor; semantic owner should route to [UID:0000AL]/[UID:0000JO], and formal C++ stays blank because shared template declarations should regenerate it.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0052a4de-0x0052a4e0 | padding | Callback destructor to MusicControlDialog scalar deleting destructor alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
        - [UID:0003MR][0x0052a4e0-0x0052a535.MusicControlDialogScalarDeletingDestructor](by-memory/0x0052a4e0-0x0052a535.MusicControlDialogScalarDeletingDestructor.md) 0x0052a4e0-0x0052a535 | scalar deleting destructor | MusicControlDialogScalarDeletingDestructor : reconstructable : 86% : strong : MusicControlDialog scalar deleting destructor wrapper reached through vtable/adjustor thunks; class destructor declaration should regenerate this wrapper and formal standalone C++ stays blank.
```

## Remaining Blockers

- [UID:0003ME], [UID:0003MM], [UID:0003MN], and [UID:0003MO] still lack direct caller/table/vtable/member-pointer/VA/RVA routes. This is now a documented target-specific no-code proof, not an unresolved ownership question. A future IDA function creation or source emission for these should require new entry-route evidence.
- [UID:0003MG] path-string helper semantics are not fully named. The handler definitely does not call `FolderPathSelected`; the only durable observed side effect is clearing `g_pApplication+0x84f`. A stronger final name for `ConsumeBrowseDirectoryPathString` requires auditing the string helpers `0x582730`, `0x582830`, `0x582b70`, and `0x582b30`.
- [UID:0003MK] still uses a descriptive placeholder for the UI/zone fallback helper at `0x00509480`. This does not block first-draft C++ for MusicControlDialog, but it should cap naming confidence until the target owning `0x00509480` is audited.
- [UID:0003MJ] and [UID:0003MQ] have no direct entry xrefs despite modeled function starts. First-draft C++ is still recommended because they are stable IDA-modeled source-shaped helpers, but confidence should remain below directly called helpers.
- [UID:0002N2]/[UID:0002N3] metadata is currently inconsistent with [UID:0000AL] class support. Supervisor should reroute semantic owner/emitter as described and update stale coverage scores from `76/74` to `85/85`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0003ME-0003MR-MusicControlDialogHelperFamily-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"0003ME"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003ME-0003MR-MusicControlDialogHelperFamily-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0003ME-0003MR-MusicControlDialogHelperFamily-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003ME"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
