*** UID:0000FV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# VideoPlayerPane

## Status

- Confidence: strong for class behavior, Bink lifecycle, vtable references, and source file parent; medium-high for `OpenBinkVideo` final exposure because it is generic base logic but only called by `LogoPlayerPane`.
- Likely source file: [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md)
- Address range: [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md)
- Current recovered file: `source-3/simroot_v2/class_VideoPlayerPane.cpp`

## Class Purpose

`VideoPlayerPane` is a `Pane`-derived Bink playback surface. It owns Bink handle lifetime, playback state, idle-time frame decoding, copy-to-surface behavior, completion messages, and application notification cleanup.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x005c0040-0x005c0083` | Constructs the base pane, installs `VideoPlayerPane` vtables, clears playing flag and Bink handle. |
| non-deleting destructor body | `0x005c0090-0x005c010a` | Unregisters `term`, closes Bink handle, and tears down the base pane. Omitted from `VideoPlayerPane` active Wave3 output. |
| possible open helper | `0x005c0110-0x005c0174` | Configures Bink DirectSound and opens a memory-backed stream; currently Wave3-owned by `LogoPlayerPane`. |
| close-current-video helper | `0x005c0180-0x005c019f` | Unpromoted IDA code; if a Bink handle exists, calls virtual slot `+0x4c` then closes the handle. |
| Bink sound toggle helper | `0x005c01a0-0x005c01c5` | Unpromoted IDA code; compares Bink field `+0x230` with caller state and calls `BinkSetSoundOnOff`. |
| Bink seek helper | `0x005c01d0-0x005c01e8` | Unpromoted IDA code; calls `BinkGoto(handle, frame, 0)`. |
| `StartPlayback` | `0x005c01f0-0x005c0206` | Marks pane/playback active and invalidates or refreshes drawing through the pane vtable. |
| `StopPlayback` | `0x005c0210-0x005c0259` | Stops playback, hides/deactivates pane, restores Bink sound, closes handle. |
| `OnMessage` | `0x005c0260-0x005c0291` | Handles the `term` application notification and closes the active Bink handle. |
| `OnIdle` | `0x005c02a0-0x005c0349` | Services Bink, decodes/copies frames, advances frames, and posts `VisD` on completion. |
| `HandleVideoDoneMessage` | `0x005c0350-0x005c037b` | Handles `VisD` by notifying the owner object reached through the secondary pane subobject offset. |
| deleting-destructor thunks | `0x005c037b`, `0x005c0386` | Compiler adjustor thunks; subtract `0xa0`/`0xa4` and forward to `0x005c03a0`. |
| scalar deleting destructor | `0x005c03a0-0x005c045b` | Full deleting wrapper for video-pane teardown. |

## Data Notes

- `+0xf5` is marked active/visible during playback in current generated source.
- `+0xf8` is the playing flag.
- `+0xfc` stores the Bink handle in IDA decompilation and current generated source.
- `g_use32BitColor` selects the Bink copy mode.
- `g_pApplication` is used for app notification registration/unregistration.

## Evidence Notes

- `LogoPlayerPane::LogoPlayerPane` calls the constructor at `0x005c0040`.
- Vtable data xrefs cover playback virtuals and message/idle handlers.
- `OnIdle` calls `BinkWait`, `BinkService`, `BinkDoFrame`, `BinkCopyToBuffer`, and `BinkNextFrame`.
- The `term` and `VisD` four-character tags are central to shutdown/completion handling.
- `0x005c0110` calls `BinkOpen` with `0x04080000`, matching `BINKFROMMEMORY | BINKNOSKIP` in public Bink flag references and the memory-buffer callers from `LogoPlayerPane`.
- IDA MCP 2026-06-02 linear disassembly found three previously undocumented unpromoted helpers at `0x005c0180`, `0x005c01a0`, and `0x005c01d0`; all operate on the Bink handle at `+0xfc`, so they belong with this class until stronger evidence proves otherwise.
- Current active generated output omits the non-deleting destructor at `0x005c0090`; `class_LogoPlayerPane.cpp` currently emits it under the derived class.
- Disabled generated output marks `0x005c037b` missing and emits `0x005c0386` with bad adjusted-this syntax, though IDA confirms both as real `0xb` thunks.

## Cross-References

- [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md)
- [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md)
- [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the Bink playback constructor/destructor/open/start/stop/message/idle/done/thunk method map, field notes, Bink API call evidence, and `term`/`VisD` behavior; confidence remains capped by `OpenBinkVideo` ownership and active Wave3 omission caveats.
- 2026-06-02 IDA MCP refresh:
  - Changed to: `COMPLETION:86` and `CONFIDENCE:84`.
  - Summary/evidence: added unpromoted close/sound/seek helpers in the `0x005c0174-0x005c01f0` area, marked the class reconstructable, and attached it to [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md). C++ remains blank because the class is below the 95+ final-source threshold.
