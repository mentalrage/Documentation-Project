*** UID:0000P4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# VideoPlayerPane

## Status

- Confidence: strong for class responsibility, medium for final folder placement.
- Proposed module: `ui/core/VideoPlayerPane.cpp`
- Current recovered source: `class_VideoPlayerPane.cpp`
- Main class: [UID:0000FV][VideoPlayerPane](by-class/VideoPlayerPane.md)
- Main address doc: [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md)
- Related startup class: [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md)
- Evidence basis: existing docs plus IDA MCP boundary/xref/decompilation checks refreshed on 2026-06-02.

## File Role

`VideoPlayerPane.cpp` owns the generic pane-level Bink playback surface. It constructs the pane, starts and stops playback, services Bink frames during idle, copies decoded frames into the pane surface, handles the `term` application notification, and tears down Bink handles.

This should be a reusable UI/media pane module. Startup movie sequencing remains in [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md), while audio backend ownership remains in [UID:0000NV][SoundManager](by-file/SoundManager.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `VideoPlayerPane` | `0x005c0040-0x005c045b` | Base Bink playback pane, idle frame pump, app notification handling, destructor/thunks. |
| non-deleting destructor body | `0x005c0090-0x005c010a` | Resets to `VideoPlayerPane` vtables, unregisters the `term` notification, closes the Bink handle, and tears down the base pane. Wave3 currently mis-emits this under `LogoPlayerPane`. |
| `OpenBinkVideo` helper | `0x005c0110-0x005c0174` | Opens a memory-backed Bink stream after configuring DirectSound. Current Wave3 owner is `LogoPlayerPane`; final placement may be protected base helper or startup-logo helper. |
| close/sound/seek helpers | `0x005c0180-0x005c01e8` | Three IDA-unpromoted helper bodies operating on the Bink handle at `+0xfc`: close current video, set sound on/off, and seek through `BinkGoto`. |
| deleting-destructor thunks | `0x005c037b`, `0x005c0386` | Compiler-generated adjustor thunks for the scalar deleting destructor. |
| globals | `g_pApplication`, `g_use32BitColor`, `g_pSoundManager` | Application message routing, color-copy mode, and Bink audio bridge dependencies. |

## Evidence Notes

- IDA confirms real starts at `0x005c0040`, `0x005c0090`, `0x005c0110`, `0x005c01f0`, `0x005c0210`, `0x005c0260`, `0x005c02a0`, `0x005c0350`, `0x005c037b`, `0x005c0386`, and `0x005c03a0`.
- `VideoPlayerPane::VideoPlayerPane` is called by `LogoPlayerPane::LogoPlayerPane`.
- `StartPlayback`, `StopPlayback`, `OnMessage`, `OnIdle`, and `HandleVideoDoneMessage` are vtable-referenced at `0x61d0xx` and `0x6310xx`.
- `OnIdle` calls `BinkWait`, `BinkService`, `BinkDoFrame`, `BinkCopyToBuffer`, `BinkNextFrame`, then posts `VisD` when playback finishes.
- The `term` tag is decimal `1952805485` and is used for application/video teardown notifications.
- IDA MCP decompilation of `0x005c0110` shows `BinkOpen(segmentData, 67633152)`, where `67633152 == 0x04080000`. Public Bink flag references identify that bit pair as `BINKFROMMEMORY | BINKNOSKIP`, matching the in-memory segment callers.
- IDA MCP confirms the video deleting-destructor adjustor thunks at `0x005c037b` and `0x005c0386`; they subtract `0xa0`/`0xa4` and forward to `0x005c03a0`.
- IDA MCP 2026-06-02 linear disassembly confirms the previously skipped `0x005c0174-0x005c01f0` region contains `0xcc` padding plus three unpromoted helper bodies at `0x005c0180`, `0x005c01a0`, and `0x005c01d0`; these use `BinkClose`, `BinkSetSoundOnOff`, and `BinkGoto`.

## Ownership Notes

The source path `ui/core/VideoPlayerPane.cpp` is preferred because this class is a `Pane` subclass and its virtuals are UI event/idle handlers. A `media/VideoPlayerPane.cpp` folder would also be defensible if later project-structure evidence shows a media layer.

The helper at `0x005c0110` is the only mixed-ownership function in this island. Its current callers are both `LogoPlayerPane` methods, but its implementation is generic Bink open/setup logic and uses Bink's memory-open flag. Keep the class-owner ambiguity visible until more video callers or original file evidence appear, but do not name its first parameter `filePath` in source migration.

Current generated `class_VideoPlayerPane.cpp` omits the non-deleting destructor body at `0x005c0090`, and disabled output omits `0x005c037b` while emitting `0x005c0386` with bad adjusted-this syntax. Treat both as data cleanup issues.

The proposed reconstruction path is `NexusTK/ui/core/`, matching the current source-placement decision for a reusable pane subclass. Keep the helper at `0x005c0110` documented as caller-sensitive until final source recovery decides whether the method is protected base API or startup-logo-only glue.

## Cross-References

- [UID:0000FV][VideoPlayerPane](by-class/VideoPlayerPane.md)
- [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md)
- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md)
- [UID:0001RN][startup-logo-media](by-resource/startup-logo-media.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/80`. Summary/evidence: the page documents the Bink playback pane role, memory/class refs, ownership notes, and external video dependency, while final folder placement and possible `OpenBink` helper ownership remain unresolved.
