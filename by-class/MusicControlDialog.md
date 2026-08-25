*** UID:00008U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "MusicControlDialog.h"
#include "FolderSelectDialog.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "DialogPane.h"
#include "StringBase.h"

class Event;

typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > StringBaseW;

class MusicControlDialog : public DialogPane
{
public:
    MusicControlDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleType19Event(Event *event);

private:
    void FolderPathSelected(StringBaseW path);
    void PopulateCdDrivePopup();
    void ApplyPlaybackState();
    void TogglePauseState();
    void ApplySoundFrequencySelection(int selection);

    bool m_musicPaused;
};

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MusicControlDialog

## Status

- Confidence: very strong for class responsibility, direct inheritance, inherited facets, exact object size/member tail, method/override inventory, source ownership, callback ABI, SoundFreq policy, BDir StringBase helper roles, and active-map `PlayMusicByZone` fallback routing; strong for inferred original private/control spelling and retained-copy compiler-inlining explanation.
- Likely source file: [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- Address range: [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- Proposed source pair: `NexusTK/ui/dialogs/MusicControlDialog.h` and `NexusTK/ui/dialogs/MusicControlDialog.cpp`.
- Historical recovered lead: `source-3/simroot_v2/class_MusicControlDialog.cpp`; generated/recovered names remain evidence leads rather than source authority.

## Class Purpose

`MusicControlDialog` is the client music/sound settings dialog. It exposes sound-effect enablement, sample volume, playback enable/mode, stream volume, local music folder selection, CD drive selection, music behavior flags, previous/pause/next buttons, and close/accept behavior.

The object directly derives from `DialogPane` and has exact size `0x270` (`624`). The complete base occupies `0x26c`; the only derived state is `bool m_musicPaused` at `+0x26c`, followed by ordinary alignment. `EventHandler` and `TimerHandler` facets at `+0xa0` and `+0xa4` are inherited implementation views of `DialogPane`, not additional direct source bases, explicit vptr fields, or member subobjects.

## Source Layout And Virtual Topology

- RTTI orders the hierarchy `MusicControlDialog -> DialogPane -> Pane -> GrafPort -> LObject`; `EventHandler` and `TimerHandler` have PMDs at `0xa0` and `0xa4`. This establishes one direct public source base: `DialogPane`.
- Construction allocates `0x270`, calls the `DialogPane` base constructor, stores the primary/secondary/tertiary MusicControlDialog vtables at `+0/+0xa0/+0xa4`, and clears `m_musicPaused` at `+0x26c`.
- Both destructor paths restore the three inherited facets and delegate all cleanup to `DialogPane`; no derived member needs destruction. The source relies on the implicit virtual derived destructor and does not declare scalar-deleting or adjustor-thunk machinery.
- Comparison of the 23/11/2-entry MusicControlDialog tables with the corresponding DialogPane tables changes only the destructor family, primary slots `+0x48`/`+0x4c`, and EventHandler slots `+0x10`/`+0x18`. The source overrides are therefore `OnControlCommand`, `UpdateActionButton`, `HandlePacketEvent`, and `HandleType19Event`.
- The class H owns all declarations. The class CPP block provides the `MusicControlDialog.h` and `FolderSelectDialog.h` include/root channel with terminal `[[CHILDREN]]`; exact by-memory children own method definitions.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x00528e60-0x0052976c` | Builds `DLGSCNTL.EPF` controls, enumerates CD drives, initializes values from config and `SoundManager`, and queues packet `0x11b`. |
| non-deleting destructor helper | `0x00529770-0x0052978f` | Resets vtables and tears down the base dialog; IDA-confirmed, not modeled by Wave3 method lookup. |
| `OnControlCommand` | `0x00529790-0x00529b70` | Primary DialogPane slot `+0x48`; handles control ids `1..14` for SFX, volumes, playback modes, folder dialog, drive menu, previous/pause/next, and close. Case `3` is the live inline call-site path for `ApplySoundFrequencySelection`; the range includes the compiler switch table at `0x00529b30-0x00529b68`. |
| unmodeled sound-effect apply body | `0x00529b70-0x00529bda` | Source-like helper that updates control id `1`, config byte `+0x28de48`, and SoundManager enablement; B002 corrected the exclusive end and routed it to this class, while current B011 MCP confirms no function object or incoming xrefs, so its by-memory child carries a formal no-code marker. |
| `HandlePacketEvent` | `0x00529be0-0x00529c5a` | Inherited EventHandler secondary slot `+0x10`; reads Event packet data at `+0x0c`, accepts `'#'` payloads, updates sound-effect control/config state, and calls SoundManager enable/disable helpers. |
| `HandleType19Event` | `0x00529c60-0x00529cf8` | Inherited EventHandler secondary slot `+0x18`; accepts `BDir` channel `0x42446972`, consumes notification payload `+4` through ANSI-to-wide StringBase temporaries, clears `g_pApplication+0x84f`, and does not call `FolderPathSelected`. |
| `UpdateActionButton` | `0x00529d00-0x00529ed1` | Primary DialogPane slot `+0x4c`; enables/disables controls from sound-effect, SoundFreq, and music-source selections through the shared enable/disable control helpers. |
| `FolderPathSelected` | `0x00529ee0-0x0052a00c` | By-value `StringBaseW` callback confirmed by the concrete value specialization and callee-side incoming-argument destruction; stores the music path, updates/reset control id `6`, scans with `m_randomizeMusicOrder`, and reapplies playback state. |
| `PopulateCdDrivePopup` | `0x0052a010-0x0052a120` | Enumerates CD drives `A:` through `Z:` using the drive-root buffers, populates control id `8`, and selects `g_pConfig+0x291910`; IDA-modeled retained helper with no direct xref. |
| `ApplyPlaybackState` | `0x0052a120-0x0052a17f` | Applies `g_pConfig+0x291908` mode to active-map zone fallback, stream/local, or Redbook playback, opens `g_pConfig+0x291910` for Redbook, and clears pause through `TogglePauseState` when needed. Mode `0` reaches the shared `0x00509480` tail into `SoundManager::PlayMusicByZone` with `g_activeMapPane+0x4d0/+0x4d4/+0x4d8`. Current generated `ChattingColorPane` ownership is stale. |
| `TogglePauseState` | `0x0052a180-0x0052a1e9` | Toggles `this+0x26c` / `m_musicPaused`, pauses stream or Redbook playback for modes `1/2`, retrieves control id `12`, and updates pause/play icon ids `37`/`48` through [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md). |
| raw folder-control refresh helper | `0x0052a1f0-0x0052a227` | IDA-unpromoted body with corrected exclusive end; updates control id `6` display text and resets embedded TextEditPane selection only, with no config copy or SoundManager scan. |
| raw next-track helper | `0x0052a230-0x0052a271` | IDA-unpromoted retained body that marks SoundManager advance request, advances stream/Redbook playback, and tail-jumps to `TogglePauseState` if paused; command case `13` contains the live inline duplicate. |
| raw previous-track helper | `0x0052a280-0x0052a2cb` | IDA-unpromoted retained body that rewinds Redbook or plays the previous stream track and tail-jumps to `TogglePauseState` if paused; command case `11` contains the live inline duplicate. |
| file-local `ApplySoundEffectEnabled` | `0x0052a2d0-0x0052a304` | No `this` parameter; direct command-handler helper that writes `g_pConfig+0x28de48` and calls SoundManager enable/disable helpers. |
| `ApplySoundFrequencySelection` | `0x0052a310-0x0052a3e0` | Applies control id `3` SoundFreq selection: `0` mutes without changing config, `1/2` represent `22050/44100` Hz, and a changed active value writes `m_soundFrequency`, directly constructs localized AlertPane `244` with `this` as layout reference, then unmutes when needed. The retained copy has no direct entry route; command case `3` is the live inline source path. |
| [UID:0000AL][PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6](by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md) | `0x0052a3e0-0x0052a4de` | Template function-object invoke/destructor support for the [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) callback. |
| scalar deleting destructor | `0x0052a4e0-0x0052a535` | Resets vtables, destroys base dialog state, and conditionally deletes. |

## Data Notes

- [UID:00040O][0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer](by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md) is the primary `MusicControlDialog` complete-object-locator pointer at `vftable[-1]`, immediately before the generated vtable data at [UID:00025Y][0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData](by-memory/0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData.md). B006 split it out of the old MSGHandler physical tail; do not route this dword through MSGHandler.
- `this + 0x26c` is the dialog pause-state byte, recommended descriptive name `m_musicPaused` / `m_pauseActive`. The constructor clears it, `TogglePauseState` flips it, and previous/next paths clear pause by calling `TogglePauseState` when it is set.
- Config fields below are under [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md); the dialog consumes them but does not own config storage.
- `g_pConfig + 0x291908` stores the music source/playback mode used by control id `5`: `0` disabled/fallback, `1` stream/local/DAT music, and `2` Redbook/CD music.
- `g_pConfig + 0x29190c` stores the local music folder/path string displayed in control id `6` and consumed by the folder callback/local scanner.
- `g_pConfig + 0x291910` stores the selected Redbook/CD drive letter used by control id `8`.
- `g_pConfig + 0x291912` stores the randomize/shuffle flag used by control id `9`, the local music directory scan, and Redbook track-order construction.
- `g_pConfig + 0x291913` stores the repeat/wrap flag used by control id `10` and local/Redbook next-track paths; control id `10` writes it inverted as `selected == 0`.
- `g_pConfig + 0x291914` is `m_soundFrequency`, persisted under `SoundFreq`: `0` disables/mutes, `1` selects `22050` Hz, and `2` selects `44100` Hz. Control id `3`, the localized alert `244` path, SoundManager constructor preference, and audio-driver reinitialization all consume this contract.
- `g_pConfig + 0x28de48` is the sound-effects enablement byte used by control id `1`, the packet handler, and `ApplySoundEffectEnabled`.
- Control id `12` is the pause/play selection control. `TogglePauseState` passes icon/frame ids `37` and `48` into [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md), whose selected-value field lives at offset `+0x10c` in the control object.

## Evidence Notes

- Wave3 reports only five `MusicControlDialog` methods, while IDA confirms additional starts in the same vtable/function island.
- `ApplyMusicPlaybackState` has only two IDA callers: `0x00529790` and `0x00529ee0`; both are music-dialog paths.
- The folder callback object stores a `MusicControlDialog` owner pointer and a member-function pointer target. The reusable template declarations belong with [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), while this class owns the selected-path handler and callback setup.
- 2026-06-13 MCP `entity_query` and `lookup_funcs` confirm the formal MusicControlDialog island functions through `0x0052a535`, with `NewUserDialogPane2` starting at `0x0052a540`.
- 2026-06-13 MCP `insn_query` confirms previously hidden executable helper bodies at `0x00529b70`, `0x0052a1f0`, `0x0052a230`, and `0x0052a280`; they are local to the MusicControlDialog code/data cluster even though IDA has not promoted them to functions.
- 2026-06-13 MCP `xrefs_to` confirms the command-handler switch table, folder callback target, playback helper callers, pause-helper tail jumps, and scalar-deleting destructor adjustor thunks.
- 2026-06-18 B003 helper-family reanalysis resolves first-draft C++ readiness for `HandleSoundEffectPacket`, `HandleBrowseDirectoryNotification`, `RefreshControlStates`, `FolderPathSelected`, `PopulateCdDrivePopup`, `ApplyPlaybackState`, `TogglePauseState`, and `ApplyOutputSelection`. It keeps raw helper bodies at `0x00529b70`, `0x0052a1f0-0x0052a227`, `0x0052a230`, and `0x0052a280` blank for formal C++ because no caller, table, vtable, member-function pointer, VA pointer, or RVA pointer route was recovered.
- 2026-06-25 B011 MCP recheck confirms the class method inventory and field/global model: `this+0x26c` is the pause-active flag, [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) `+0x291908` selects music source/playback mode, `+0x29190c` stores local music path, `+0x291910` stores the CD drive letter, `+0x291912` and `+0x291913` hold shuffle/repeat flags, `+0x291914` stores output selection, and `+0x28de48` stores sound-effect enablement. The class consumes [UID:00028R][0x0067a7d0-0x0067a7d4.g_pSoundManager](by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md) and does not own SoundManager storage or playback internals.
- 2026-06-25 B011 correction-pass MCP resolves the two targeted helper routes: [UID:0003MG][0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler](by-memory/0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler.md) uses `0x00582730` ANSI StringBase construction, `0x00582830` ANSI-to-wide StringBase conversion, and `0x00582b70`/`0x00582b30` wide/ANSI release wrappers; [UID:0003MK][0x0052a120-0x0052a17f.MusicControlDialogApplyPlaybackState](by-memory/0x0052a120-0x0052a17f.MusicControlDialogApplyPlaybackState.md) mode `0` jumps through shared tail `0x00509480`, which rechecks config mode and calls [UID:0001I7][0x005797b0-0x0057a25c.SoundManagerMusicSelection](by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md) `SoundManager::PlayMusicByZone` with active MapPane arguments. Remaining non-final points are raw/no-entry helper route absence, no-direct modeled helper route absence, role-based active MapPane field spelling, and generated-row refresh.
- 2026-07-13 B004 UID0001IA caller audit resolves `FolderPathSelected` argument shape: the callback's apparent conversion/copy temporary is a wide StringBase lifetime expression, the scanner accepts the wide path and converts to ANSI internally, and no source-level `std::string`/`ToNarrowPath` step belongs in UID0003MI.
- 2026-07-07 B011 UID0003MN callback recheck used IDA MCP session `507affd6` and reconfirmed the raw next-track helper at `0x0052a230-0x0052a271`: `lookup_funcs` still reports no function object, incoming xrefs to `0x0052a230` remain zero, `find_bytes` finds no VA/RVA pointer forms (`30 A2 52 00` / `30 A2 12 00`), the command switch table still routes control id `13` to `0x005299c3`, `0x0052a271-0x0052a280` is `0xcc` padding before sibling [UID:0003MO][0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper](by-memory/0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper.md), and SoundManager/Config remain dependencies rather than class ownership transfers.
- 2026-07-01 B007 empty-emitter audit converts this page from an empty marker into the formal class-level route marker with `[[CHILDREN]]`. Exact child pages carry method bodies, static data declarations, or target-specific no-code markers while this class page waits for inherited `DialogPane` layout, secondary base spelling, and the full member map before emitting a broad class shell.
- 2026-07-29 B010 live source-quality recheck supersedes that wait state: current DialogPane size/H, allocation and constructor/destructor evidence, RTTI PMDs, and complete three-facet vtable comparison close the class to direct `DialogPane` inheritance, exact size `0x270`, one `m_musicPaused` byte, four overrides, five private source methods, and an implicit destructor. The accepted formal H shell now owns declarations while exact children emit CPP.

## Cross-References

- [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md)
- [UID:00028R][0x0067a7d0-0x0067a7d4.g_pSoundManager](by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md)
- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:00040O][0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer](by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md)
- [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md)
- [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- [UID:0003MB][0x00528e60-0x0052976c.MusicControlDialogConstructor](by-memory/0x00528e60-0x0052976c.MusicControlDialogConstructor.md)
- [UID:0003MD][0x00529790-0x00529b70.MusicControlDialogHandleControlCommand](by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md)
- [UID:0003MK][0x0052a120-0x0052a17f.MusicControlDialogApplyPlaybackState](by-memory/0x0052a120-0x0052a17f.MusicControlDialogApplyPlaybackState.md)

## 2026-07-29 Supervisor Gate 2B Reconciliation (Catalog 0353)

- Supervisor Gate 2B applied and read back the analysis-only `MusicControlDialog` UDT as exactly `0x270` bytes: `DialogPane base` at `+0x000`/`0x26c`, `bool m_musicPaused` at `+0x26c`/`1`, and `unsigned __int8 _tailPadding[3]` at `+0x26d`/`3`. Existing `DialogPane` and protected `Config` types were not changed. This IDA padding is analysis structure only; the human source H intentionally declares only `bool m_musicPaused`.
- The accepted method family was applied and verified at `0x00529790`, `0x00529be0`, `0x00529c60`, `0x00529d00`, `0x00529ee0`, `0x0052a010`, `0x0052a120`, `0x0052a180`, and target `0x0052a310`. Their former `sub_*` identities are retained only as historical search provenance. Comment-channel readback matches the bounded plan: regular function comments on the eight associated methods, a repeatable function comment on the target, and blank address comment channels.
- Prototype-driven frame normalization changed only existing argument presentation: `OnControlCommand` names/types its two dword arguments, both event handlers name/type their existing event argument, and `FolderPathSelected` names/types its existing by-value pointer-backed string argument. Offsets, widths, and nonargument storage remain unchanged; the type-19 handler and folder callback retain their extra raw stack slots.
- Persistence checkpoint: prestate IDB SHA256 `FD8282A51836D47961EA386D7C2D25F80D0BF88B96ACFF106FFA802277F78B16`, byte-identical backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B010-UID0003MQ-20260729-082218.i64`, and saved IDB SHA256 `6D20767D448CC568508E462790D05678838216C6CFEE77E3CFF5C4B5905244AB` (`143190049` bytes, `2026-07-29T08:26:09.5759690-04:00`). Supervisor catalog entry `0353` records `APPLIED_VERIFIED_RECONCILIATION_PENDING`; B010 performed no IDA mutation during reconciliation.

## 2026-07-29 Supervisor Constructor Gate 2B Reconciliation (Catalog 0358)

- The class's persisted method family now also includes constructor identity `MusicControlDialog__MusicControlDialog` at `0x00528e60` with analysis prototype `MusicControlDialog *__thiscall MusicControlDialog__MusicControlDialog(MusicControlDialog *this)`. Human source remains `MusicControlDialog::MusicControlDialog()`; the analysis return models the constructor object pointer and does not add a source return statement.
- The exact accepted regular function comment records controls 1-14, SoundFreq/music/effect initialization, CD-drive population, action-control update, and option packet `0x011b/0`. Address regular/repeatable and function-repeatable channels remain blank.
- Protected readback preserves all `2,316` constructor bytes at SHA256 `5DA9A7E4E026585EB9ABCA667BC267323D3C78FAA53AD812B21E3C50989E218A`, the sole `0x005a71f3` xref, all 14 frame tuples, all local storage, and the exact class/UDT topology. The former `sub_528E60`/weak `int this` presentation is historical prestate only.
- Catalog `0358` persistence checkpoint: prestate IDB SHA256 `24B033C1657266F5943A2EB0201F076673C53CEEA39E00F9D65BCED961ACEC31`; byte-identical backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B010-UID0003MQ-I13-20260729-123823.i64`; post-I13 saved checkpoint SHA256 `E9600F6C16B46FE1F5A7FEE463EF7890E415905CE465F8F6C55954FF5AA91611`, `143190173` bytes, saved `2026-07-29T12:39:14.0441568-04:00`. The shared IDB later advanced through verified supervisor work to historical checkpoints SHA256 `08D31FD1C7B80721D6CD7774B42C5A5157B3A4683670A3E27EA5660290554F5A`, `143190452` bytes, saved `2026-07-29T12:53:48.4762005-04:00`; SHA256 `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, `143190601` bytes, saved `2026-07-29T13:03:43.9987735-04:00`; SHA256 `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, `143190636` bytes, saved `2026-07-29T13:59:50.1387219-04:00`; and SHA256 `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, `143191631` bytes, saved `2026-07-29T14:12:44.7229687-04:00`. The current authoritative shared IDB is database `1da2b2ae`, SHA256 `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, `143190676` bytes, saved `2026-07-29T14:22:15.9735862-04:00`. Fresh bounded read-only readback preserves the exact constructor name/type/four comment channels, `2,316`-byte body SHA256 `5DA9A7E4E026585EB9ABCA667BC267323D3C78FAA53AD812B21E3C50989E218A`, sole xref from `0x005a71f3`, all 14 frame tuples including raw `arg_4`, locals, and class/UDT topology; the prior I01-I12 names/types/comments/frame normalization and protected Config state also survive exactly. Catalog entry `0358` remains the supervisor action authority; B010 performed no IDA mutation or save during reconciliation.

## Changes

- 2026-07-29 B010 implementation callback: raised to `93/95`, moved the class route from stale CPP prose into the exact `MusicControlDialog.h` declaration with `[[CHILDREN]]`, documented direct-base/inherited-facet/layout/destructor topology, normalized the override/private-method map and by-value folder callback, adopted `m_soundFrequency`/0-22050-44100 semantics, and preserved raw/no-entry helper exclusions as documented historical evidence rather than source declarations.
- 2026-07-13 B004 UID0001IA support sync: corrected `FolderPathSelected` inventory/evidence from a narrow caller conversion to a wide StringBase scanner call, retaining all config/UI/randomize/recurse/playback behavior, score, class marker, and unrelated methods.
- 2026-07-07 B011 UID0003MN support sync: added current MCP session `507affd6` no-entry proof for the raw next-track helper and preserved metadata/formal class marker unchanged.
- 2026-07-01 B007 empty-emitter implementation: raised completion/confidence to `89/89` and inserted the formal class-route no-standalone marker with `[[CHILDREN]]`, preserving [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) as owner/emitter and leaving exact output to child pages.
- 2026-06-25 B011 source-quality implementation: raised completion/confidence to `88/88`, added the active MCP session `80de0a67` class/field status note, normalized [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) and [UID:00028R][0x0067a7d0-0x0067a7d4.g_pSoundManager](by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md) dependency references, and preserved [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) as the class owner/emitter route.
- 2026-06-25 B011 correction pass: added the resolved BDir StringBase conversion chain and the `0x00509480` active-map `PlayMusicByZone` route to class notes, replacing the prior stale helper-route framing.
- 2026-06-18 B003 support sync: resolved the constructor/command-handler source-quality blockers for [UID:0003MB][0x00528e60-0x0052976c.MusicControlDialogConstructor](by-memory/0x00528e60-0x0052976c.MusicControlDialogConstructor.md) and [UID:0003MD][0x00529790-0x00529b70.MusicControlDialogHandleControlCommand](by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md), added the descriptive music-control config cluster names, documented command/control id roles `1..14`, clarified that `0x00529d00` is `RefreshControlStates` and `0x0052a120` is `ApplyPlaybackState`, and documented inline `0x011b` option-code sends from the constructor and sound-effect toggle.
- 2026-06-18 B003 helper-family Rule 26 incorporation: updated helper names/roles for packet, browse notification, refresh, folder, drive, playback, pause, sound-effect, and output-selection bodies; corrected raw folder-control helper range to `0x0052a1f0-0x0052a227`; recorded that raw no-entry helpers stay blank for formal C++ while modeled source-shaped helpers now have first-draft C++ in their by-memory pages.
- 2026-06-21 B006 RTTI support sync: added [UID:00040O][0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer](by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md) as the class-owned `vftable[-1]` complete-object-locator child immediately before [UID:00025Y][0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData](by-memory/0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData.md). Score unchanged; this is generated data from the class declaration, not handwritten C++.
- 2026-06-13 A003 parent gate pass:
  - What existed before: the class page was `86/80` and listed most helpers, but it did not include the corrected command-handler switch-table span or the hidden IDA-unpromoted helper bodies.
  - Changed to: scores `87/87`, refreshed method inventory, explicit hidden-helper no-entry evidence, and fresh MCP evidence.
  - Summary/evidence: the split [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md) now gives exact child support for the class, while MCP xrefs keep the folder/playback helpers inside MusicControlDialog rather than generated `ChattingColorPane` ownership.
- Completion/confidence score update: existed before as `0/0`; changed to `86/80`. Summary: the music/sound settings dialog was documented in high detail across constructor, controls, config offsets, SoundManager/CD/folder behavior, callback template, helper ownership, and generated ownership notes; B003/B011 passes now provide the current helper ownership and role-name evidence. Evidence: linked `MusicControlDialog` memory range, IDA-confirmed additional starts, control-id method table, config offset notes, callback wrapper class, and `SelectionControlPaneSetSelectionAndRefresh` reference.
- 2026-06-03 autogen consistency pass: marked the class reconstructable and attached it to [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) without changing scores or adding C++. Evidence: the existing IDA-backed memory/file docs and proposed source tree already place the class in `MusicControlDialog.cpp`; exact child pages now carry the method C++ and raw-helper no-code proofs.
