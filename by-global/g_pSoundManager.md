*** UID:0004UF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SoundManager;

SoundManager *g_pSoundManager = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_AUDIO_SOUNDMANAGER_H
#define NEXUSTK_AUDIO_SOUNDMANAGER_H

#include <windows.h>
#include <dsound.h>
#include <string.h>
#include <vector>

#include "../util/Singleton.h"
#include "../util/StringBase.h"
#include "../util/TimerHandler.h"

typedef signed long S32;
typedef unsigned long U32;

typedef void *HSAMPLE;
typedef void *HDIGDRIVER;
typedef void *HSTREAM;
typedef void *HREDBOOK;

#ifndef AILCALL
#define AILCALL __stdcall
#endif

#ifndef AILCALLBACK
#define AILCALLBACK __stdcall
#endif

typedef U32 (AILCALLBACK *AILFileOpenCallbackProc)(const char *, U32 *);
typedef void (AILCALLBACK *AILFileCloseCallbackProc)(U32);
typedef S32 (AILCALLBACK *AILFileSeekCallbackProc)(U32, S32, U32);
typedef U32 (AILCALLBACK *AILFileReadCallbackProc)(U32, void *, U32);
typedef void (AILCALLBACK *AILStreamCallbackProc)(HSTREAM);

extern "C"
{
U32 AILCALL AIL_sample_status(HSAMPLE sample);
void AILCALL AIL_set_sample_volume(HSAMPLE sample, S32 volume);
void AILCALL AIL_start_sample(HSAMPLE sample);
S32 AILCALL AIL_set_sample_file(HSAMPLE sample, const void *fileImage,
                                S32 block);
void AILCALL AIL_set_DirectSound_HWND(HDIGDRIVER driver, HWND window);
void AILCALL AIL_release_sample_handle(HSAMPLE sample);
HSAMPLE AILCALL AIL_allocate_sample_handle(HDIGDRIVER driver);
void AILCALL AIL_set_redist_directory(const char *directory);
void AILCALL AIL_close_digital_driver(HDIGDRIVER driver);
HDIGDRIVER AILCALL AIL_open_digital_driver(U32 frequency, S32 bits,
                                            S32 channels, U32 flags);
void AILCALL AIL_release_all_timers();
const char *AILCALL AIL_last_error();
S32 AILCALL AIL_set_preference(U32 preference, S32 value);
void AILCALL AIL_shutdown();
S32 AILCALL AIL_get_DirectSound_info(
    HDIGDRIVER driver,
    LPDIRECTSOUND *directSound,
    LPDIRECTSOUNDBUFFER *primaryBuffer);
void AILCALL AIL_redbook_close(HREDBOOK redbook);
U32 AILCALL AIL_redbook_tracks(HREDBOOK redbook);
void AILCALL AIL_init_sample(HSAMPLE sample);
void AILCALL AIL_redbook_track_info(HREDBOOK redbook, U32 track,
                                     U32 *start, U32 *end);
U32 AILCALL AIL_redbook_position(HREDBOOK redbook);
U32 AILCALL AIL_redbook_play(HREDBOOK redbook, U32 start, U32 end);
void AILCALL AIL_redbook_stop(HREDBOOK redbook);
void AILCALL AIL_redbook_pause(HREDBOOK redbook);
void AILCALL AIL_redbook_resume(HREDBOOK redbook);
void AILCALL AIL_set_file_callbacks(
    AILFileOpenCallbackProc openCallback,
    AILFileCloseCallbackProc closeCallback,
    AILFileSeekCallbackProc seekCallback,
    AILFileReadCallbackProc readCallback);
AILStreamCallbackProc AILCALL AIL_register_stream_callback(
    HSTREAM stream, AILStreamCallbackProc callback);
U32 AILCALL AIL_stream_status(HSTREAM stream);
void AILCALL AIL_set_stream_loop_count(HSTREAM stream, S32 loopCount);
void AILCALL AIL_set_stream_volume(HSTREAM stream, S32 volume);
void AILCALL AIL_startup();
void AILCALL AIL_set_digital_master_volume(HDIGDRIVER driver, S32 volume);
void AILCALL AIL_pause_stream(HSTREAM stream, S32 paused);
void AILCALL AIL_start_stream(HSTREAM stream);
void AILCALL AIL_close_stream(HSTREAM stream);
HSTREAM AILCALL AIL_open_stream(HDIGDRIVER driver, const char *filename,
                                S32 streamMemory);
HREDBOOK AILCALL AIL_redbook_open_drive(S32 drive);
S32 AILCALL AIL_redbook_set_volume(HREDBOOK redbook, S32 volume);
}

class SoundManager;

extern SoundManager *g_pSoundManager;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Position-zero SoundManager emitter owns the sole CPP pointer definition and opens the standalone H guard with seven direct includes, local 32-bit Miles compatibility declarations, all 37 imported APIs, and the external pointer declaration; UID0000DG emits the complete class tail and closes the guard. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# g_pSoundManager

## Status

- Kind: externally linked process-wide `SoundManager *` singleton pointer.
- Source module: [UID:0000NV][SoundManager](by-file/SoundManager.md), `NexusTK/audio/SoundManager.cpp`, emitter position `0`.
- Exact backing storage: [UID:00028R][0x0067a7d0-0x0067a7d4.g_pSoundManager](by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md).
- Source disposition: this page owns the sole initialized module definition. The physical storage page is false/non-emitting evidence so generated output cannot duplicate storage.
- Confidence: very strong for name, type, linkage, storage, source root, lifetime, one-definition handling, standalone H prerequisites, bounded local Miles ABI, and deterministic guard split; null-literal style remains a lexical cap.

## Source Definition And Header Split

- The CPP block is routed into `SoundManager.cpp`; it contains the local incomplete-type declaration needed by the pointer definition and the single zero initialization.
- The H block opens `NEXUSTK_AUDIO_SOUNDMANAGER_H`, includes exactly `<windows.h>`, `<dsound.h>`, `<string.h>`, `<vector>`, `../util/Singleton.h`, `../util/StringBase.h`, and `../util/TimerHandler.h`, supplies the bounded local Miles declarations, and emits `extern SoundManager *g_pSoundManager;`.
- UID0000DG follows at position `10`, emits the complete class using those definitions, and closes the same guard. This deterministic split creates one standalone `SoundManager.h`, not two headers or an unterminated fragment.
- A pointer definition is legal with an incomplete class type. No raw address, storage alias, `void *`, static-template member, anonymous-namespace variable, or second source file is needed.
- External linkage is mandatory because 112 non-lifetime reads span Application, OptionPane, MusicControlDialog, MapPane, UserPane, Bink/video, status panes, hotkeys, and other source modules.

## Local Miles And Platform Boundary

- Windows SDK headers provide `HWND`, `LPDIRECTSOUND`, and `LPDIRECTSOUNDBUFFER`. Project headers provide complete Singleton, StringBase, TimerHandler, and vector-element/base definitions; `<string.h>` supplies `_strlwr_s` used by the existing StringBase inline surface.
- No Miles SDK header, compatibility shim, source tree, or import library exists in the repository. The local block therefore declares only the executable-observed boundary: `S32`/`U32` as signed/unsigned long, four opaque pointer handles, guarded `AILCALL`/`AILCALLBACK`, five callback procedure types, and all 37 imported functions inside `extern "C"`.
- Decorated imports establish `__stdcall` arities, current IDB use establishes 32-bit handle widths and consumed return categories, and UID0004WV supplies the four exact callback declarations. This is a bounded compatibility declaration, not copied proprietary middleware source.
- Rejected routes are unavailable `<mss.h>`, a new unowned shim file, precompiled-header assumptions, implicit declarations, and unverifiable third-party source import.

## Exact Storage And Xrefs

- Exact storage is the four zero bytes `[0x0067a7d0,0x0067a7d4)`. The surrounding data window is also zero initialized, but adjacent globals have independent xref families and ownership.
- The target has exactly 117 direct data xrefs. Five are direct compiler-lowered lifetime writes or clears; the remaining 112 are reads.
- Predecessor [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) has 145 refs. Successor [UID:0001OY][0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2](by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md) has nine. Their separate counts and lifecycle routes reject aggregate/table ownership.

## Lifetime And Compiler Separation

- Constructor publication at `0x00579a67` and its null fallback at `0x00579a6e` are compiler lowering for the direct `Singleton<SoundManager>` base. RTTI PMD evidence shows the empty Singleton base at `+4`, followed by adjustment back to the complete object pointer before the store.
- Ordinary destruction clears the pointer at `0x00579da3` while reversing direct-base construction.
- Constructor unwind clear `0x0057b9a0` is an exact 11-byte compiler EH cleanup reached only from the constructor funclet at `0x0060831c` after the Singleton-base adjustment.
- Scalar deleting destructor clear `0x0057bc29` is part of compiler wrapper lowering reached from the vtable, not an independently authored source assignment.
- Application shutdown reads and null-checks this global at `0x00464b14`, passes deleting flag `1`, and invokes virtual slot zero at `0x00464b22`.
- Human constructor/destructor source must not handwrite publication, clear, `this+4`/`this-4`, vptr writes, EH cleanup, scalar flags, object free, member-vector destruction, or TimerHandler/base teardown.

## Type, RTTI, And Source Ownership

- RTTI names exact `SoundManager`, `Singleton<SoundManager>`, and `TimerHandler`. The class hierarchy lists Singleton before TimerHandler; PMDs are `+4,-1,0` and `0,-1,0`, respectively, under old-MSVC empty-base optimization.
- Consumers invoke SoundManager methods and the shutdown route performs virtual destruction, proving `SoundManager *` rather than a byte pointer or opaque handle.
- [UID:0000DG][SoundManager](by-class/SoundManager.md) owns the declaration. [UID:0000NV][SoundManager](by-file/SoundManager.md) owns module placement. This semantic global owns only the single pointer definition.
- Config supplies audio options, DATFile/DATFileMgr supplies assets, Miles supplies middleware handles, and Application/UI/gameplay modules consume the pointer. None owns the definition.

## Consumer Inventory

- Representative reads include `0x00450e27`, `0x00464b14`, `0x0049e164`, `0x004f8af3`, `0x00504678`, `0x00528ecf`, `0x0053da1c`, `0x0053de20`, `0x0057b827`, `0x0058b3e3`, `0x005991ee`, `0x0059e12d`, `0x005aa6a6`, and `0x005c0116`.
- Old OptionPane mirrors controls 2 and 3 through SoundManager music and sound-effect state while Config remains the persistent settings provider.
- MusicControlDialog, MapPane, UserPane, sound-status UI, video/Bink, hotkey, and audio helper families all read the same pointer. Their fanout establishes external linkage without transferring source ownership.

## Range And No-Duplicate Policy

- The physical range remains exactly `[0x0067a7d0,0x0067a7d4)`. No merge, split, extension, or padding creation applies.
- This semantic page emits before the class at file position `0`. The class remains at `10`, source constructor/destructor at `20`/`30`, playback definitions at `100-290`, scanner at `300`, and Redbook definitions at `400-470`.
- Generated acceptance is exactly one `SoundManager *g_pSoundManager = 0;` definition before use and zero UID00028R storage markers or duplicate definitions.

## Score Rationale

- Completion `93`: the existing exact global definition/storage/lifecycle/consumer route now includes the complete standalone-header preamble, external declaration, seven direct includes, local compatibility aliases/handles/macros/callbacks, and all 37 Miles API declarations.
- Confidence `94`: exact imports/arities, handle widths, callsites, callback definitions, project header dependencies, platform SDK ownership, emitter order, and 117 global xrefs support the split. Best-supported API return spellings that are not consumed remain the bounded confidence cap.

## Rejected Alternatives And Historical Assumptions

- Rejected source spellings: `dword_67A7D0`, `DAT_0067a7d0`, `void *`, raw-address access, and decompiler labels.
- Rejected placement: Application.cpp, Config.cpp, DATFileMgr.cpp, UI consumers, anonymous namespace/file-static storage, and a new standalone globals source file.
- Rejected ownership: a qualified Singleton template static member or class static data member; no such symbol or separate storage exists, while project source vocabulary consistently uses unqualified `g_pSoundManager`.
- Historical direct attachment of UID00028R to the SoundManager file was useful binary evidence but conflated physical storage with semantic declaration ownership. It is superseded by this one-definition route.

## Cross-References

- [UID:00028R][0x0067a7d0-0x0067a7d4.g_pSoundManager](by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md)
- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0001I7][0x005797b0-0x0057a25c.SoundManagerMusicSelection](by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md)
- [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md)
- [UID:0001IC][0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver](by-memory/0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver.md)
- [UID:00026I][0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData](by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md)

## Change Log

- 2026-08-24 B009 UID0000NX callback: Raised completion `92` to `93`, preserved confidence `94` and the sole CPP definition, and added the exact position-zero standalone H preamble, seven direct includes, bounded local Miles/platform declarations, all 37 APIs, and `g_pSoundManager` extern for the UID0000DG class tail.
- 2026-07-20 B005 UID00028R callback: created the semantic global at `92/94`, established the sole externally linked module definition and separate future header declaration placement, recorded exact storage/xref/lifetime/RTTI/consumer/source ownership, and rejected duplicate physical or compiler-shaped source emission.
