*** UID:0000O4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StartupLogoPanes

## Status

- Confidence: strong for class responsibilities, medium for exact original file split.
- Proposed module: `app/StartupLogoPanes.cpp`
- Alternate split: `app/LogoPane.cpp` plus `app/LogoPlayerPane.cpp`
- Current recovered source: `class_LogoPane.cpp`, `class_LogoPlayerPane.cpp`
- Main classes: [UID:00007G][LogoPane](by-class/LogoPane.md), [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md)
- Related base class: [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md)
- Main address docs: [UID:00019C][0x004f4c10-0x004f53a8.LogoPane](by-memory/0x004f4c10-0x004f53a8.LogoPane.md), [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md), [UID:00022T][0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop](by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md), [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md)
- Evidence basis: `simroot_v2` generated source, Wave3 metadata, Wave2 report notes, and IDA MCP boundary/xref/decompilation checks on 2026-05-24.

## File Role

`StartupLogoPanes.cpp` is the startup splash and intro-media UI module. It owns the static logo pane that inflates and renders the startup `.LGO` image, handles click/timer advancement, and calls back into the application startup flow. It also owns the logo video pane that reads a segmented Bink payload, opens each segment, and lets keyboard or mouse input skip to the next segment.

This module should stay app/startup-adjacent rather than moving into generic UI dialogs. The code is driven by startup sequencing, completion callbacks, logo resources, and application-level transition logic. The reusable Bink frame pumping belongs in [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `LogoPane` | `0x004f4c10-0x004f53a8` | Static startup logo display, image/palette load, click/timer skip path, completion callback, destructor/thunks. |
| `LogoPlayerPane` | `0x004f53b0-0x004f570c` | Segmented Bink startup movie reader, input skip handlers, close/completion callback, derived destructor wrapper. |
| standalone startup Bink playback loop | `0x004f5710-0x004f5ac7` | Loads `LOGO.PAK`/`LOGO.PAD`, opens memory-backed Bink playback, installs a temporary window procedure, pumps frames/messages, and tears playback down. |
| startup Bink midpoint/restart helper | `0x004f5ae0-0x004f5b1e` | One-shot helper called by the temporary window procedure to reopen Bink from the logo payload under `byte_66DB42`/frame-position conditions. |
| `LogoPlayerPane::OpenBinkVideo` | `0x005c0110-0x005c0174` | Opens the current memory-backed Bink segment after seeding DirectSound and registering the `term` app notification. Physically in the video-pane island. |
| callback function objects | `0x004f5040`, `0x004f5070`, `0x004f5250` | Deferred member callback wrappers used to advance the startup screen without running transition logic directly from input handlers. |
| `_AUTOBUF<unsigned char>` helper | `0x004f5640-0x004f5669` | Adjacent compiler-emitted template constructor, not a `LogoPlayerPane` method. See [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md) and [UID:00019E][0x004f5640-0x004f5669.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f5669.AUTOBUFUnsignedCharConstructor.md). |
| startup logo resources | `NEXON.LGO`, segmented Bink payload | Static logo image and movie payload format. See [UID:0001RN][startup-logo-media](by-resource/startup-logo-media.md). |

## Evidence Notes

- IDA MCP confirms a real `LogoPane` function island from `0x004f4c10` through `0x004f53a8`, including a Wave3-omitted non-deleting destructor body at `0x004f4eb0`.
- `LogoPane::LogoPane` is called from the application startup function around `0x004f643c`.
- `LogoPane::QueueAdvanceToNextScreen` is reached by click handling, a tiny virtual callback, and deferred transition paths.
- IDA confirms a compact `LogoPlayerPane` island from `0x004f53b0` through `0x004f570c`. The omitted `0x004f5640` helper constructs `_AUTOBUF<unsigned char>` and should not be migrated as a pane virtual.
- IDA confirms a standalone Bink playback helper at `0x004f5710-0x004f59c6` and temporary window procedure at `0x004f59d0-0x004f5ac7`. This code is called from the application startup flow and uses `LOGO.PAK`/`LOGO.PAD`, Bink imports, and global playback state rather than pane virtual dispatch.
- The temporary window procedure calls [UID:00022U][0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart](by-memory/0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart.md), a small adjacent helper that closes and reopens the global Bink handle from the logo payload under one-shot flag/frame-position conditions.
- `LogoPlayerPane::OpenBinkVideo` at `0x005c0110` is called from the logo-player constructor and segment advance helper only.
- Those callers pass pointers into the embedded `_AUTOBUF<unsigned char>` data: the constructor passes `buffer + 4`, and the segment advance path passes `buffer + firstSegmentSize + 4`. IDA shows the helper calls `BinkOpen` with `0x04080000`, matching memory-backed Bink input plus no-skip playback.
- `0x005c0090` is better interpreted as the non-deleting `VideoPlayerPane` teardown body called during `LogoPlayerPane` destruction, despite Wave3 currently emitting it as `LogoPlayerPane::~LogoPlayerPane`.
- IDA MCP recheck confirmed the destructor adjustor thunks are real two-instruction functions: `LogoPane` thunks at `0x004f52de` and `0x004f52e9` subtract `0xa0`/`0xa4` and forward to `0x004f5300`; `LogoPlayerPane` thunks at `0x004f566a` and `0x004f5675` subtract `0xa0`/`0xa4` and forward to `0x004f5680`.
- Current `class_LogoPane.cpp` still contains an unrelated `using RefreshFn = void(*)(HeadSelectDialog*)` alias and duplicate normalized include-section comments. Treat these as generated-source artifacts, not source-layout evidence.

## Ownership Notes

The strongest source-layout choice is one startup logo module containing both `LogoPane` and `LogoPlayerPane`. A two-file split is also plausible because the static `.LGO` renderer and Bink player have different dependencies. If split, keep both files under `app/` or an equivalent startup folder rather than generic `ui/dialogs/`.

Do not absorb [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md) into this file by default. The base class owns Bink frame stepping, `OnIdle`, message handling, and video teardown. `LogoPlayerPane` only specializes startup movie sequencing and completion behavior.

Before migration, clean the active generated output so `0x005c0090` is represented as base video teardown, `OpenBinkVideo` uses a memory-buffer parameter name, and the adjustor thunks are materialized as compiler thunks instead of missing code or nonsensical adjusted-this expressions.

## Cross-References

- [UID:00007G][LogoPane](by-class/LogoPane.md)
- [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md)
- [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md)
- [UID:00022T][0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop](by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md)
- [UID:00022U][0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart](by-memory/0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart.md)
- [UID:0001RN][startup-logo-media](by-resource/startup-logo-media.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document covers startup logo/video roles, proposed contents, Bink helper split, `_AUTOBUF` exclusion, IDA boundary/caller evidence, ownership notes, migration cleanup points, resources, and cross-references; confidence remains capped by exact static-logo vs video source split.
- 2026-06-01 reconstruction path assignment:
  - What changed: set the proposed reconstruction path to `NexusTK/app/`.
  - Evidence: the page already names `app/StartupLogoPanes.cpp` as the strongest placement, and IDA evidence ties the module to application startup at `0x004f5fb0-0x004f6490` rather than a generic UI/control subsystem.
