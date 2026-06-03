*** UID:00007H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LogoPlayerPane

## Status

- Confidence: strong for behavior, medium for exact helper placement.
- Likely source file: [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- Address range: [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md)
- Non-contiguous video helper: [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md)
- Current recovered file: `source-3/simroot_v2/class_LogoPlayerPane.cpp`

## Class Purpose

`LogoPlayerPane` is the startup intro movie pane. It derives from [UID:0000FV][VideoPlayerPane](by-class/VideoPlayerPane.md), reads a custom segmented Bink payload into an embedded `_AUTOBUF<unsigned char>`, opens the first segment, and advances to the next segment on Enter, Escape, Space, or mouse-up.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x004f53b0-0x004f5500` | Constructs `VideoPlayerPane`, initializes the embedded AUTOBUF, reads the movie file, stores the first segment size, and opens the first Bink segment. |
| cleanup destructor | `0x004f5510-0x004f556a` | Unpromoted non-deleting destructor body; restores vtables, releases callback/AUTOBUF state, and tail-calls base video teardown. |
| `AdvanceToNextSegment` | `0x004f5570-0x004f55c8` | Guards against repeated skip, calculates the next segment pointer, opens it, and starts playback or deletes the pane if no segment opens. |
| `OnKeyEvent` | `0x004f55d0-0x004f55fc` | Enter, Escape, and Space trigger segment advance. |
| `OnMouseEvent` | `0x004f5600-0x004f561d` | Mouse-up triggers segment advance. |
| `OnClose` | `0x004f5620-0x004f5634` | Marks the pane for deletion and invokes the completion callback. |
| AUTOBUF constructor helper | `0x004f5640-0x004f566a` | Adjacent compiler-emitted `_AUTOBUF<unsigned char>` constructor; not part of the pane class. |
| deleting-destructor thunks | `0x004f566a`, `0x004f5675` | Compiler adjustor thunks; subtract `0xa0`/`0xa4` and forward to `0x004f5680`. Current generated source has one nonsensical adjusted-this expression and one missing body. |
| scalar deleting destructor | `0x004f5680-0x004f570c` | Releases callback, frees the AUTOBUF buffer, calls base video teardown, and optionally deletes. |
| `OpenBinkVideo` | `0x005c0110-0x005c0174` | Opens the current memory-backed Bink segment after configuring DirectSound. Physically documented with [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md). |

## Data Notes

- Offset `+0x100` is the embedded `_AUTOBUF<unsigned char>` storage in current generated layout.
- The first dword in the buffer is treated as the size of the first Bink segment.
- Offset `+0x10c` stores the completion callback pointer.
- Offset `+0x110` is a skip/advanced guard byte or flag in current source.
- Offset `+0x114` stores the first segment size.

## Evidence Notes

- IDA confirms `LogoPlayerPane::OpenBinkVideo` is called only from the constructor and `AdvanceToNextSegment`.
- `OpenBinkVideo` calls `SoundManager::GetDirectSound`, `BinkSetSoundSystem(BinkOpenDirectSound, ...)`, closes any old Bink handle, registers the `term` notification, and calls `BinkOpen` with flags `67633152` / `0x04080000`.
- The first argument passed to `OpenBinkVideo` is a pointer into the AUTOBUF payload, not a filesystem path. The helper's generated `filePath` parameter name is a data issue; use `segmentData` or `binkData` until the final signature is set.
- `0x005c0090` is most likely the `VideoPlayerPane` non-deleting destructor body called from `LogoPlayerPane` cleanup, not the derived `LogoPlayerPane` destructor.
- IDA xrefs show `0x005c0090` is called from LogoPlayerPane constructor EH cleanup at `0x004f5565`, scalar deleting destructor cleanup at `0x004f56d6`, and another constructor EH path at `0x00600f33`.
- IDA xrefs show `0x005c0110` is called only from the constructor at `0x004f5476` and `AdvanceToNextSegment` at `0x004f55af`.
- IDA disassembly at `0x004f5510-0x004f556a` shows an unpromoted derived cleanup body with the same three vtable writes as the constructor/destructor, callback deletion through virtual slot `+0`, AUTOBUF free/`LObject` teardown, and a tail-call to `0x005c0090`.

## Cross-References

- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md)
- [UID:0002PS][0x004f53b0-0x004f5500.LogoPlayerPaneConstructor](by-memory/0x004f53b0-0x004f5500.LogoPlayerPaneConstructor.md)
- [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md)
- [UID:0002PU][0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment](by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md)
- [UID:0002PV][0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers](by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md)
- [UID:0002PW][0x004f5620-0x004f5634.LogoPlayerPaneOnClose](by-memory/0x004f5620-0x004f5634.LogoPlayerPaneOnClose.md)
- [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks](by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md)
- [UID:0002PY][0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor](by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md)
- [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md)
- [UID:0000FV][VideoPlayerPane](by-class/VideoPlayerPane.md)
- [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md)
- [UID:0001RN][startup-logo-media](by-resource/startup-logo-media.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `84/80`. Summary: the startup movie pane has detailed segment-buffer, input skip, callback, destructor, AUTOBUF, and Bink helper documentation, but confidence is capped by exact helper placement and final `OpenBinkVideo` ownership. Evidence: linked pane/video helper ranges, constructor/advance xrefs, DirectSound/Bink setup notes, embedded segment payload behavior, and generated parameter-name caveat.
