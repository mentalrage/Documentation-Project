*** UID:00007H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FunctionObject0;
struct KeyEvent;
struct MouseEvent;

class LogoPlayerPane : public VideoPlayerPane
{
public:
    LogoPlayerPane(const wchar_t *moviePath, FunctionObject0 *completionCallback);
    virtual ~LogoPlayerPane();

protected:
    virtual void OnClose();
    virtual bool OnKeyEvent(const KeyEvent *event);
    virtual bool OnMouseEvent(const MouseEvent *event);

private:
    void AdvanceToNextSegment();

    _AUTOBUF<unsigned char> m_movieData;         // +0x100; loaded segmented Bink payload.
    FunctionObject0 *m_completionCallback;       // +0x10c; non-null startup completion callback.
    bool m_hasRequestedSegmentAdvance;           // +0x110; guard set before the second open attempt.
    unsigned char m_reserved111[3];              // +0x111..+0x113 alignment before the saved size.
    unsigned int m_firstSegmentSize;             // +0x114; first payload dword.
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LogoPlayerPane

## Status

- Confidence: strong for behavior, source ownership, pane/helper boundaries, vtable reachability, destructor routing, declaration-level class shape, constructor/segment-advance field names, callback handling, first-draft child C++ readiness, and protected `OpenBinkVideo` base-helper direction; medium-high for exact original member spellings and constructor caller recovery.
- Likely source file: [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- Address range: [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md)
- Non-contiguous video helper: [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md)
- Current recovered file: `source-3/simroot_v2/class_LogoPlayerPane.cpp`
- Direct parent: [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md), which clears the strict `85/85` routing gate at `88/86`.

## Class Purpose

`LogoPlayerPane` is the startup intro movie pane. It derives from [UID:0000FV][VideoPlayerPane](by-class/VideoPlayerPane.md), reads a custom segmented Bink payload into an embedded `_AUTOBUF<unsigned char>`, opens the first segment, and advances to the next segment on Enter, Escape, Space, or left mouse button release/up.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x004f53b0-0x004f5500` | First-draft ready `LogoPlayerPane::LogoPlayerPane(const wchar_t *moviePath, FunctionObject0 *completionCallback)`. Constructs `VideoPlayerPane`, initializes `m_movieData`, stores `m_completionCallback`, clears `m_hasRequestedSegmentAdvance`, reads the caller-supplied movie file, stores `m_firstSegmentSize`, opens the first Bink segment, and throws `FileError(L"%s corrupted")` on first open failure. |
| cleanup destructor | `0x004f5510-0x004f556a` | Ordinary non-deleting `LogoPlayerPane::~LogoPlayerPane()` body. The source body deletes owned `FunctionObject0 *m_completionCallback` at `+0x10c`; compiler lowering restores the three `LogoPlayerPane` vtable views, destructs embedded `_AUTOBUF<unsigned char> m_movieData` at `+0x100/+0x104/+0x108`, tears down the embedded `LObject` shell, and chains to `VideoPlayerPane::~VideoPlayerPane()` at `0x005c0090`. |
| `void AdvanceToNextSegment()` | `0x004f5570-0x004f55c8` | Source-authored segment-transition method. It checks `m_hasRequestedSegmentAdvance`, advances only while inherited `m_binkHandle->FrameNum < 100`, opens `m_movieData.m_data + 4 + m_firstSegmentSize` with protected `VideoPlayerPane::OpenBinkVideo`, and either calls inherited `StartPlayback()` or `Pane::MarkForDeletion()`. |
| `OnKeyEvent` | `0x004f55d0-0x004f55fc` | EventMan type `8` (`KeyDown`) with translated key byte Enter, Escape, or Space triggers segment advance; the handler still returns handled for non-triggering keys. |
| `OnMouseEvent` | `0x004f5600-0x004f561d` | EventMan type `3` (`LeftButtonUp` / left-button release) triggers segment advance; the handler still returns handled for other mouse events. |
| `OnClose` | `0x004f5620-0x004f5634` | Parameterless close/completion virtual at primary vtable slot `+0x50`; marks the pane for deferred deletion through inherited `Pane::MarkForDeletion`, then invokes non-null `FunctionObject0* m_completionCallback` at `+0x10c` through the `Invoke` slot `+0x0c`. B003 2026-06-18 raw PE recheck confirms vtable-only reachability through `0x0061d068` and supports first-draft C++ population. |
| AUTOBUF constructor helper | `0x004f5640-0x004f566a` | Adjacent compiler-emitted `_AUTOBUF<unsigned char>` constructor; not part of the pane class. |
| deleting-destructor thunks | `0x004f566a`, `0x004f5675` | Non-reconstructable compiler ABI glue; `0x004f566a` subtracts `0xa0` for the Pane/EventHandler secondary view, `0x004f5675` subtracts `0xa4` for the tertiary timer/event view, and both tail-jump to `0x004f5680`. These regenerate from the class declaration and virtual destructor; [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks](by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md) is non-emitting and formal C++ stays blank. |
| scalar deleting destructor | `0x004f5680-0x004f570c` | Compiler scalar deleting wrapper for `LogoPlayerPane::~LogoPlayerPane()`. It repeats the callback/AUTOBUF/base cleanup, receives delete flags, and optionally frees object storage; the source body belongs to [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md), not this wrapper. |
| inherited `OpenBinkVideo` | `0x005c0110-0x005c0174` | Protected `VideoPlayerPane::OpenBinkVideo(const void *segmentData, unsigned int segmentSize)` opens the current memory-backed Bink segment after configuring DirectSound. It is only called by the constructor and segment-advance path in this binary, but physical locality, `m_binkHandle` state, and Bink lifecycle keep ownership with [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md). |

## Data Notes

- Offset `+0x100` is the embedded `_AUTOBUF<unsigned char> m_movieData` storage in current generated layout.
- Offset `+0x104` is `m_movieData.m_data`, the loaded segmented startup movie payload pointer freed by both destructor paths.
- Offset `+0x108` is `m_movieData.m_count`, the loaded payload byte count used by the second-segment size arithmetic.
- The destructor paths free `m_movieData` through compiler-emitted AUTOBUF member destruction. `LogoPlayerPane` source should not explicitly free `m_movieData.m_data`, call the embedded `LObject` teardown, or call `VideoPlayerPane::~VideoPlayerPane()`.
- B011 suggested `m_logoData` / `m_logoBuffer` as descriptive alternatives for the embedded payload storage, but this class keeps `m_movieData` because constructor and segment-advance child C++ already use it consistently for the segmented startup movie payload. Treat those alternatives as historical/descriptive aliases unless later source-symbol evidence appears.
- The first dword in the buffer is treated as the size of the first Bink segment.
- Offset `+0x10c` stores the non-null startup completion callback pointer. B003 models it as `FunctionObject0* m_completionCallback`: constructor code stores the second argument here, cleanup/scalar destructor paths release it through callback vslot `+0x00`, and `OnClose` invokes vslot `+0x0c`.
- Offset `+0x110` is `m_hasRequestedSegmentAdvance`, a one-shot guard set before the second `OpenBinkVideo` attempt; failed opens still consume the request.
- Offset `+0x114` stores `m_firstSegmentSize`, the first payload dword saved by the constructor and used by `AdvanceToNextSegment`.

## Declaration And Split Policy

B006's aggregate source-quality review resolves the safe class-level C++ shape as a declaration-only `LogoPlayerPane : public VideoPlayerPane` shell emitted through [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md), with `[[CHILDREN]]` after the class so exact child method definitions emit outside the declaration. The class page should declare the constructor, virtual destructor, `OnClose`, input overrides, private `AdvanceToNextSegment`, and the four accepted fields; it should not duplicate child method bodies.

The method-body split is source-authored for constructor [UID:0002PS][0x004f53b0-0x004f5500.LogoPlayerPaneConstructor](by-memory/0x004f53b0-0x004f5500.LogoPlayerPaneConstructor.md), ordinary destructor semantics [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md), segment advance [UID:0002PU][0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment](by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md), input handlers [UID:0002PV][0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers](by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md), and close handler [UID:0002PW][0x004f5620-0x004f5634.LogoPlayerPaneOnClose](by-memory/0x004f5620-0x004f5634.LogoPlayerPaneOnClose.md). The adjacent [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) remains `_AUTOBUF<unsigned char>` template support, and [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks](by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md) plus [UID:0002PY][0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor](by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md) are compiler-generated from the class declaration and destructor.

B011's destructor-family reanalysis resolves [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md) as the source-bearing ordinary destructor body. [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks](by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md) secondary/tertiary deleting-destructor thunks and [UID:0002PY][0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor](by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md) scalar deleting destructor are compiler-generated destructor dispatch/delete glue and must keep formal C++ blank.

B009's [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks](by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md) source-policy cleanup removes the stale child-emitter route for the adjusted-this thunk pair. The class declaration/destructor must still preserve the `+0xa0` EventHandler secondary view and `+0xa4` tertiary timer/event view so MSVC regenerates the vtable entries, but no source file should contain a function named after `sub_4F566A`, `sub_4F5675`, or a handwritten `LogoPlayerPaneDeletingDestructorThunk`.

Rejected routes remain `VideoPlayerPane` for the class itself, `Pane`/`EventHandler` for the input pair, `FunctionObjects` for the feature method that uses the callback, `_AUTOBUF` for the pane, and a new standalone `LogoPlayerPane.cpp` file unless later source-tree evidence proves a real split. Current documentation keeps `m_hasRequestedSegmentAdvance` as the accepted guard name because it matches the later populated constructor/advance C++ and explicitly captures that the byte is set before success is known. B006's `m_secondSegmentAttempted` wording is a useful historical/alternate name for the same guard, while `m_isPlayingSecondSegment`, `m_hasAdvancedToNextSegment`, `m_filePath`, and `LogoPlayerPaneCallback` are rejected.

## Evidence Notes

- 2026-06-13 A001 live IDA MCP `analyze_component` over `0x004f53b0`, `0x004f5570`, `0x004f55d0`, `0x004f5600`, `0x004f5620`, `0x004f5640`, `0x004f566a`, `0x004f5675`, `0x004f5680`, `0x005c0090`, and `0x005c0110` reconfirmed the method island: constructor size `0x150` / 336 bytes, cleanup body range `0x5a` / 90 bytes, advance helper size `0x58` / 88 bytes, key handler size `0x2c` / 44 bytes, mouse handler size `0x1d` / 29 bytes, close handler size `0x14` / 20 bytes, AUTOBUF helper size `0x2a` / 42 bytes, each destructor thunk size `0x0b` / 11 bytes, scalar deleting destructor size `0x8c` / 140 bytes, and `OpenBinkVideo` size `0x64` / 100 bytes. These conversions were verified with `tools/int_convert.py`.
- The same IDA component pass reported shared vtable data refs for `??_7LogoPlayerPane@@6B@` at `0x0061d018`, `??_7LogoPlayerPane@@6B@_0` at `0x0061d070`, `??_7LogoPlayerPane@@6B@_1` at `0x0061d0a0`, and `_AUTOBUF<uchar>` at `0x0061b868`.
- 2026-06-13 `xrefs_to` shows no direct xrefs to the constructor start or unpromoted cleanup start, two code xrefs to `AdvanceToNextSegment` from the key and mouse handlers, vtable-only xrefs to the input and close handlers, vtable xrefs to both destructor thunks, and `OpenBinkVideo` xrefs only from the constructor at `0x004f5476` and advance helper at `0x004f55af`.
- 2026-06-13 IDA `insn_query` over `0x004f5510-0x004f556a` decoded a complete unpromoted cleanup body with no owning function object: vtable writes at `0x004f551a`, `0x004f5520`, and `0x004f552a`; callback delete through `[this+0x10c]`; AUTOBUF vtable reset/free at `+0x100/+0x104`; embedded `LObject` teardown; and final tail jump to `0x005c0090`.
- 2026-06-13 IDA `get_bytes` reconfirmed the `0x004f5500-0x004f5510` padding before the cleanup body, the `0x004f566a-0x004f5680` thunk bytes (`sub ecx, 0xa0` / `sub ecx, 0xa4` then jumps to `0x004f5680`), and the `0x004f570c-0x004f5710` padding before the standalone startup-logo Bink playback helper.
- IDA confirms `LogoPlayerPane::OpenBinkVideo` is called only from the constructor and `AdvanceToNextSegment`.
- `OpenBinkVideo` calls `SoundManager::GetDirectSound`, `BinkSetSoundSystem(BinkOpenDirectSound, ...)`, closes any old Bink handle, registers the `term` notification, and calls `BinkOpen` with flags `67633152` / `0x04080000`.
- The first argument passed to `OpenBinkVideo` is a pointer into the AUTOBUF payload, not a filesystem path. The helper's generated `filePath` parameter name is a data issue; use `segmentData` or `binkData` until the final signature is set.
- `0x005c0090` is most likely the `VideoPlayerPane` non-deleting destructor body called from `LogoPlayerPane` cleanup, not the derived `LogoPlayerPane` destructor.
- IDA xrefs show `0x005c0090` is called from LogoPlayerPane constructor EH cleanup at `0x004f5565`, scalar deleting destructor cleanup at `0x004f56d6`, and another constructor EH path at `0x00600f33`.
- IDA xrefs show `0x005c0110` is called only from the constructor at `0x004f5476` and `AdvanceToNextSegment` at `0x004f55af`.
- IDA disassembly at `0x004f5510-0x004f556a` shows an unpromoted derived cleanup body with the same three vtable writes as the constructor/destructor, callback deletion through virtual slot `+0`, AUTOBUF free/`LObject` teardown, and a tail-call to `0x005c0090`.
- 2026-06-17 B001 source-quality reanalysis for [UID:0002PV][0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers](by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md) closes the input-handler event questions: `OnKeyEvent` consumes EventMan type `8` key-down events and translated key bytes at `event+0x08`, `OnMouseEvent` consumes type `3` left-button release/up events, both are vtable-only through the Pane/EventHandler secondary view at `+0xa0`, and both unconditionally return handled after optionally calling `AdvanceToNextSegment`.
- 2026-06-18 B003 source-quality reanalysis for [UID:0002PW][0x004f5620-0x004f5634.LogoPlayerPaneOnClose](by-memory/0x004f5620-0x004f5634.LogoPlayerPaneOnClose.md) resolves the close/completion hook as `void LogoPlayerPane::OnClose()`. Raw PE confirms exact 20-byte bounds, three bytes of padding before and twelve after, no rel32 call/jump route, and sole dword pointer route through primary vtable slot `0x0061d068` / `+0x50`. The body calls inherited `Pane::MarkForDeletion()` before invoking `FunctionObject0* m_completionCallback` at `+0x10c` through `Invoke` slot `+0x0c`; the callback is released by destructor paths through vslot `+0x00`.
- 2026-06-20 B003 source-quality reanalysis for [UID:0002PU][0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment](by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md) resolves the segment-advance blockers: the source method is `void LogoPlayerPane::AdvanceToNextSegment()`, the guard is `m_hasRequestedSegmentAdvance`, the first segment field is `m_firstSegmentSize`, AUTOBUF fields are `m_movieData.m_data/m_count`, the inherited Bink handle current-frame field is `m_binkHandle->FrameNum`, the success virtual is inherited `VideoPlayerPane::StartPlayback()`, and `0x005c0110` is best modeled as protected `VideoPlayerPane::OpenBinkVideo(const void*, unsigned int)` despite Logo-only current direct callers.
- 2026-06-20 B004 source-quality reanalysis for [UID:0002PS][0x004f53b0-0x004f5500.LogoPlayerPaneConstructor](by-memory/0x004f53b0-0x004f5500.LogoPlayerPaneConstructor.md) resolves the constructor blocker enough for first-draft C++. The source signature is `LogoPlayerPane::LogoPlayerPane(const wchar_t *moviePath, FunctionObject0 *completionCallback)`, with `m_movieData` at `+0x100/+0x104/+0x108`, `m_completionCallback` at `+0x10c`, `m_hasRequestedSegmentAdvance` at `+0x110`, `m_firstSegmentSize` at `+0x114`, stack `StdioFile` open/read of `moviePath`, protected `VideoPlayerPane::OpenBinkVideo`, and `FileError(L"%s corrupted")` on first-segment open failure. Local PE/Capstone scans found no direct REL32, VA/RVA, vtable, active startup-flow, allocation, or factory/callback construction route to `0x004f53b0`; keep this as retained/alternate startup movie pane code or an unproven indirect route, not as a blocker to reconstructing the constructor itself.
- 2026-06-21 B011 source-quality reanalysis for [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md) resolves the destructor factoring: raw PE bytes confirm the complete non-deleting body at `0x004f5510-0x004f556a`, no raw direct/vtable route to `0x004f5510`, primary vtable dispatch through scalar wrapper `0x004f5680`, and secondary/tertiary dispatch through thunks `0x004f566a/0x004f5675`. The source body is `delete m_completionCallback;`; vtable stores, AUTOBUF member destruction, embedded `LObject` teardown, base `VideoPlayerPane` teardown, scalar-delete flags, and thunk adjustments are compiler output.

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

## Score And Routing

`LogoPlayerPane` now clears the `85/85` child gate at `88/91`, and its direct source parent [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md) already clears `88/86`, so the existing parent route remains valid. The class still stays below final-source quality because the direct constructor caller is not recovered and exact original field spellings are not symbol-proven.

The class-level reconstruction C++ block is intentionally declaration-only with `[[CHILDREN]]` after the class. Method-level C++ is present where ready: constructor [UID:0002PS][0x004f53b0-0x004f5500.LogoPlayerPaneConstructor](by-memory/0x004f53b0-0x004f5500.LogoPlayerPaneConstructor.md), destructor source semantics [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md), segment advance [UID:0002PU][0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment](by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md), and close handler [UID:0002PW][0x004f5620-0x004f5634.LogoPlayerPaneOnClose](by-memory/0x004f5620-0x004f5634.LogoPlayerPaneOnClose.md).

## Changes

- 2026-06-30 B008 UID0000O4 implementation callback:
  - Recorded that [UID:0002PV][0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers](by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md) now emits formal first-draft `OnKeyEvent` and `OnMouseEvent` bodies using EventMan type `8` key-down and type `3` left-button release/up support.
  - Recorded that [UID:0002PY][0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor](by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md) now carries a formal covered-by comment for ordinary destructor [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md). The class declaration remains the source-level route; no hand-written scalar deleting wrapper or new `LogoPlayerPane.cpp` split is introduced.
- 2026-06-13 A001 Goal 2 low-confidence pass:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:80`, with the page still listed under project-level Low_Confidence even though child memory pages and the direct file parent had stronger evidence.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000O4` unchanged.
  - Summary/evidence: live IDA MCP `analyze_component`, `xrefs_to`, `insn_query`, and `get_bytes` reconfirmed the method island, cleanup body, vtable-only handlers, destructor thunk bytes, `OpenBinkVideo` callers, AUTOBUF/template separation, and base-video teardown xrefs. The strict parent gate is satisfied by child `00007H` at `86/88` and direct file parent `0000O4` at `88/85`; class-level C++ was still incomplete at that historical checkpoint because constructor reachability, final source names, and exact `OpenBinkVideo` exposure were below final-source confidence; this is superseded in part by the current class declaration and UID0002PV input-handler formal block.
- 2026-06-17 B001 source-quality sync:
  - Summary/evidence: [UID:0002PV][0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers](by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md) is now `87/90`; this class page now records EventMan type `8` as key-down, type `3` as left-button release/up, and the `+0xa0` Pane/EventHandler secondary-view route. Class score is unchanged because broader constructor/member/OpenBinkVideo source names remain below final-source quality.
- 2026-06-18 B003 OnClose source-quality sync:
  - Score unchanged at `86/88`.
  - Summary/evidence: [UID:0002PW][0x004f5620-0x004f5634.LogoPlayerPaneOnClose](by-memory/0x004f5620-0x004f5634.LogoPlayerPaneOnClose.md) is now `86/91` with first-draft C++; this class page records `void LogoPlayerPane::OnClose()`, primary slot `+0x50`, inherited delete-mark ordering, and the `FunctionObject0* m_completionCallback` field at `+0x10c`. Class score is unchanged because the direct constructor caller and exact callback instantiation remain broader class-level open questions.
- 2026-06-20 B003 AdvanceToNextSegment source-quality sync:
  - Changed score from `86/88` to `87/89`.
  - Summary/evidence: [UID:0002PU][0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment](by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md) is now `87/92` with first-draft `void LogoPlayerPane::AdvanceToNextSegment()` C++; this class page records resolved segment payload fields, the one-shot guard, Bink current-frame semantics, inherited `StartPlayback`, and protected base-helper `OpenBinkVideo` ownership. Remaining class-level questions are exact original spellings, constructor caller recovery, and coordinated event/callback declarations.
- 2026-06-20 B004 Constructor source-quality sync:
  - Changed score from `87/89` to `88/90`.
  - Summary/evidence: [UID:0002PS][0x004f53b0-0x004f5500.LogoPlayerPaneConstructor](by-memory/0x004f53b0-0x004f5500.LogoPlayerPaneConstructor.md) is now `88/91` with first-draft constructor C++; this class page records resolved constructor signature, `m_movieData`, `m_completionCallback`, `m_hasRequestedSegmentAdvance`, `m_firstSegmentSize`, `StdioFile::ReadRemaining`, protected `OpenBinkVideo`, `FileError(L"%s corrupted")`, and the active no-direct-construction-site investigation. Remaining class-level questions at that time were exact original spellings, constructor reachability, final class declaration, and destructor factoring; the destructor factoring is resolved by the later B011 entry.
- 2026-06-21 B006 aggregate Rule 26 incorporation:
  - Changed confidence from `90` to `91`; completion remains `88`.
  - Summary/evidence: incorporated B006's aggregate source-quality review by adding a declaration-only class C++ shell with `[[CHILDREN]]` after the class, recording the accepted child/body split, confirming StartupLogoPanes as the source route, rejecting VideoPlayerPane/Pane/EventHandler/FunctionObjects/AUTOBUF/new-file ownership alternatives, and documenting `m_secondSegmentAttempted` as a historical alternate for the accepted `m_hasRequestedSegmentAdvance` guard name.
- 2026-06-21 B011 destructor Rule 26 incorporation:
  - Score unchanged at `88/91`.
  - Summary/evidence: recorded the ordinary destructor source body, scalar-wrapper/thunk split, raw vtable dispatch route, `m_completionCallback` release semantics, AUTOBUF member-destructor handling, and `m_logoData`/`m_logoBuffer` as rejected descriptive aliases for the accepted `m_movieData` member name.
- 2026-06-21 B009 deleting-thunk source-policy incorporation:
  - Score unchanged at `88/91`.
  - Summary/evidence: updated [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks](by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md) from a stale class-owned emitter to non-reconstructable compiler glue. The class page now carries the source requirement: preserve the virtual destructor and the `+0xa0`/`+0xa4` pane-event subobject layout so the compiler regenerates the thunks; do not hand-write adjusted-this thunk functions.
- Completion/confidence score update: existed before as `0/0`; changed to `84/80`. Summary: the startup movie pane has detailed segment-buffer, input skip, callback, destructor, AUTOBUF, and Bink helper documentation, but confidence is capped by exact helper placement and final `OpenBinkVideo` ownership. Evidence: linked pane/video helper ranges, constructor/advance xrefs, DirectSound/Bink setup notes, embedded segment payload behavior, and generated parameter-name caveat.
