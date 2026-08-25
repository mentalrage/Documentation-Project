*** UID:0000FV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct BINK;
typedef BINK *HBINK;

class VideoPlayerPane : public Pane
{
public:
    VideoPlayerPane();
    virtual ~VideoPlayerPane();

    virtual void OnChangeMessage(LObject *owner, Message *message);
    virtual void OnPaint();
    virtual void StartPlayback();
    virtual void StopPlayback();

protected:
    bool OpenBinkVideo(const void *segmentData, unsigned int segmentSize);
    virtual void OnClose() {}
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void CloseBinkVideo();
    void SetBinkSoundEnabled(bool enabled);
    void SeekBinkFrame(unsigned int frame);

    bool m_isPlaying;
    HBINK m_binkHandle;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# VideoPlayerPane

## Status

- Confidence: very strong for class behavior, exact `0x100` layout, Bink lifecycle, complete primary/EventHandler/TimerHandler vtable maps, source file parent, and protected `OpenBinkVideo` base-helper direction. Private lexical spellings remain descriptive high-probability source names rather than original-symbol proof.
- Likely source file: [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md)
- Address range: [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md)
- Current recovered file: `source-3/simroot_v2/class_VideoPlayerPane.cpp`

## Class Purpose

`VideoPlayerPane` is a `Pane`-derived Bink playback surface. It owns Bink handle lifetime, playback state, paint-time frame decoding, copy-to-surface behavior, timer-delivered completion, and the common LObject change callback used for application termination cleanup.

The source declaration has exactly one direct base, `Pane`. RTTI lists inherited `EventHandler` and `TimerHandler` facets at complete-object offsets `+0xa0` and `+0xa4`, but those are already inside the `Pane` subtree. Declaring them again as direct bases would duplicate state and generate the wrong RTTI/vtable layout.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x005c0040-0x005c0083` | Constructs the base pane, installs `VideoPlayerPane` vtables, clears playing flag and Bink handle. |
| non-deleting destructor body | `0x005c0090-0x005c010a` | Calls inherited `g_pApplication->UnregisterChangeListener(this, kApplicationTerminateTag, false)`, closes the Bink handle, and tears down the base pane. |
| protected `OpenBinkVideo` helper | `0x005c0110-0x005c0174` | Configures Bink DirectSound, calls inherited `g_pApplication->RegisterChangeListener(this, kApplicationTerminateTag, false)`, and opens a memory-backed stream from `const void *segmentData`; both current callers are `LogoPlayerPane`, but field use, locality, and lifecycle behavior make this a protected base helper. |
| private `CloseBinkVideo` | `0x005c0180-0x005c019f` | Retained source-shaped raw helper. If a Bink handle exists, calls virtual `StopPlayback`, reloads the member, and calls `BinkClose` again. No current route was found; retain the exact quirk rather than deleting or simplifying it. |
| private `SetBinkSoundEnabled` | `0x005c01a0-0x005c01c5` | Retained source-shaped raw helper. Compares BINK `SoundOn` state at `+0x230` with the byte argument and calls `BinkSetSoundOnOff(handle, 1)` when different, even when the requested value would suggest disabling. |
| private `SeekBinkFrame` | `0x005c01d0-0x005c01e8` | Retained source-shaped raw helper. Calls `BinkGoto(m_binkHandle, frame, 0)`. |
| `StartPlayback` | `0x005c01f0-0x005c0206` | Marks pane/playback active and invalidates or refreshes drawing through the pane vtable. |
| `StopPlayback` | `0x005c0210-0x005c0259` | Stops playback, hides/deactivates pane, restores Bink sound, closes handle. |
| `OnChangeMessage(LObject *, Message *)` | `0x005c0260-0x005c0291` | Common LObject override; handles the `MessageType` `term` application notification and closes the active Bink handle. |
| `OnPaint` | `0x005c02a0-0x005c0349` | Primary vtable slot `+0x44`; waits, decodes, copies, advances, and services Bink frames, then stops and schedules exact completion ID `'ViSD'` (`0x56695344`). Historical `OnIdle` is rejected by the table slot. |
| `OnTimer` | `0x005c0350-0x005c037b` | TimerHandler facet slot `+0x04`; delegates IDs other than `'ViSD'` to `Pane::OnTimer`, adjusts to the complete object on `'ViSD'`, calls virtual `OnClose`, and returns true. Historical generic done-handler wording is superseded. |
| `OnClose` | shared body `0x0041b6a0` | Empty base virtual introduced after StopPlayback. The compiler folds it with a shared Pane no-op body; LogoPlayerPane overrides the slot at `0x004f5620`. |
| deleting-destructor thunks | `0x005c037b`, `0x005c0386` | Compiler adjustor thunks; subtract `0xa0`/`0xa4` and forward to `0x005c03a0`. |
| scalar deleting destructor | `0x005c03a0-0x005c045b` | Full deleting wrapper for video-pane teardown. |

## Exact Layout And Inheritance

| Offset | Size | Source-facing state |
| --- | ---: | --- |
| `+0x00` | `0xf8` | inherited `Pane` complete base, including EventHandler at `+0xa0` and TimerHandler at `+0xa4` |
| `+0xf8` | `1` | `bool m_isPlaying` |
| `+0xf9` | `3` | ordinary compiler alignment before the handle; not semantic source fields |
| `+0xfc` | `4` | `HBINK m_binkHandle` |

- Exact complete-object size is `0x100`. `LogoPlayerPane` begins its first derived member at `+0x100`, independently confirming the boundary.
- Type descriptor `0x006770d0` is `.?AVVideoPlayerPane@@`. CHD `0x00649f68` has six base descriptors: VideoPlayerPane, Pane, GrafPort, LObject, EventHandler `+0xa0`, and TimerHandler `+0xa4`.
- The formal H relies on normal compiler alignment after `m_isPlaying`; it intentionally does not invent source padding members.

## Data Notes

- Inherited `Pane::m_isVisible` at `+0xf5` is set by StartPlayback and cleared by StopPlayback. The name is descriptive but agrees with other Pane-derived source work.
- BINK `+0x00/+0x04` are Width/Height, `+0x08` is total `Frames`, `+0x0c` is current `FrameNum`, and `+0x230` is the sound-on state consumed by the two sound paths. The offsets and behavior are exact; the SDK-style field spelling at `+0x230` is inferred.
- `OnPaint` writes to inherited `m_surfaceContext.pixelData` at complete `+0x20`, with `2 * rowStridePixels` from `+0x28`, height `bounds.bottom - bounds.top` from `+0x38/+0x30`, and `BINKSURFACE555` versus `BINKSURFACE565` selected by `g_surfaceUsesRgb565Pixels`.
- `g_pApplication` is the LObject owner receiver for inherited registration/unregistration; this VideoPlayerPane is the listener and both calls pass `false`.
- [UID:0002Z5][0x0063104c-0x006310dc.VideoPlayerPaneVtableData](by-memory/0x0063104c-0x006310dc.VideoPlayerPaneVtableData.md) is the exact primary/adjusted vtable-data child for this class.

## Complete Vtable Shape

- The primary table at `0x0063104c` has 21 slots. VideoPlayerPane-owned slots are scalar deleting destructor `+0x00`, OnChangeMessage `+0x08`, OnPaint `+0x44`, StartPlayback `+0x48`, StopPlayback `+0x4c`, and empty OnClose `+0x50`; all intervening slots are inherited LObject/GrafPort/Pane methods.
- The inherited EventHandler table at `0x006310a4` has 11 slots: deleting-destructor adjustor plus the complete ten-method EventHandler interface. It has complete-object offset `+0xa0`.
- The inherited TimerHandler table at `0x006310d4` has two slots: deleting-destructor adjustor and OnTimer. It has complete-object offset `+0xa4`.
- Constructor, ordinary destructor, and scalar deleting wrapper each store all three table bases. The two 0x0b adjustor thunks subtract `0xa0`/`0xa4` and jump to the scalar deleting wrapper.
- Vtable arrays, RTTI objects, adjustor thunks, and the scalar deleting wrapper are compiler-generated. Only the class declaration and ordinary method bodies belong in authored C++.

## Evidence Notes

- `LogoPlayerPane::LogoPlayerPane` calls the constructor at `0x005c0040`.
- Vtable data xrefs cover playback virtuals, the LObject message callback, OnPaint, OnTimer, and OnClose.
- 2026-06-11 A005 Batch230 live IDA MCP reconfirmed the exact vtable child size `0x90` / 144 bytes (Verified with `int_convert.py`), named bases at `0x0063104c`, `0x006310a4`, and `0x006310d4`, first slot targets `0x005c03a0`, `0x005c037b`, and `0x005c0386`, and constructor/destructor/scalar-deleting-destructor store xrefs for all three bases.
- `OnPaint` calls `BinkWait`, `BinkService`, `BinkDoFrame`, `BinkCopyToBuffer`, and `BinkNextFrame`.
- `term` is exact `0x7465726d`. The completion timer is exact `'ViSD'` / `0x56695344`; historical `VisD` would encode a different integer and is rejected.
- ChangeMan dispatch and the LObject vtable resolve the former generic `OnMessage` interpretation as `OnChangeMessage(LObject *, Message *)`; `Message::m_type` at `+4` carries the `term` tag.
- `0x005c0110` calls `BinkOpen` with `0x04080000`, matching `BINKFROMMEMORY | BINKNOSKIP` in public Bink flag references and the memory-buffer callers from `LogoPlayerPane`.
- 2026-06-20 B003 support sync resolves `0x005c0110` as protected `VideoPlayerPane::OpenBinkVideo(const void *segmentData, unsigned int segmentSize)`: `LogoPlayerPane` constructor and `AdvanceToNextSegment` are the only current direct callers, but both pass memory-backed payload slices into a helper physically surrounded by base-video lifecycle methods and operating on `m_binkHandle`. The second argument is retained in the source-facing signature because both callers pass it even though the recovered helper body does not consume it.
- IDA MCP 2026-06-02 linear disassembly found three previously undocumented unpromoted helpers at `0x005c0180`, `0x005c01a0`, and `0x005c01d0`; all operate on `m_binkHandle`. The 2026-07-26 B004 recheck found zero direct xrefs and zero VA/RVA pointer hits for every raw start. They remain retained private source methods because their exact bounded bodies and class state establish ownership; absence of current liveness is not proof of padding or foreign ownership.
- 2026-07-26 B004 live session `5a570ede` enumerated the complete 21/11/2 table family, three COLs, six-entry RTTI graph, source method identities, raw helper boundaries, and derived LogoPlayerPane comparison. It resolves all previous class-declaration blockers sufficiently for the formal H above.

## Behavior Quirks Preserved In Source

- `OpenBinkVideo` keeps the caller-visible `segmentSize` parameter even though optimized code does not consume it.
- `CloseBinkVideo` and OnChangeMessage call virtual StopPlayback and then reload/call `BinkClose` again. StopPlayback clears the member, so the second call observes the reloaded member; the redundant-looking behavior must not be simplified away.
- `SetBinkSoundEnabled` always passes integer `1` when the current sound state differs from the argument. The formal source preserves that observed constant rather than replacing it with `enabled`.
- StopPlayback expects a valid handle on its routed calls, tests BINK `+0x230`, closes it, and clears `m_binkHandle`.
- OnPaint schedules `'ViSD'` after virtual StopPlayback and then reaches the final BinkService call with the reloaded member state, matching the executable flow.

## Rejected Alternatives And Historical Corrections

- Historical `OnIdle` is rejected because `0x005c02a0` occupies primary slot `+0x44`, the Pane paint slot, and performs surface painting.
- Historical `HandleVideoDoneMessage` is retained only as superseded terminology; `0x005c0350` is the TimerHandler-facet OnTimer override.
- `LogoPlayerPane` is a caller/derived consumer, not the owner of OpenBinkVideo or the base destructor.
- Direct `EventHandler`/`TimerHandler` bases are rejected because RTTI places both within Pane's subtree.
- Hand-authored RTTI/vtable/deleting-destructor source is rejected as compiler output.
- The raw helpers are not discarded merely because liveness scans are negative.

## Cross-References

- [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md)
- [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md)
- [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)

## Changes

- 2026-07-26 B004 UID0002Z5 accepted class implementation:
  - Raised `89/90` to `94/96`; preserved UID0000P4 owner/emitter and reconstructable state.
  - Added the complete class declaration to H and kept CPP blank so method bodies remain on their exact executable by-memory owner.
  - Added exact `0x100` layout, Pane-only direct inheritance, inherited `+0xa0/+0xa4` facets, complete 21/11/2 vtable shape, BINK partial-field reasoning, and source/compiler boundaries.
  - Corrected current `OnIdle`/generic done-handler/`VisD` wording to OnPaint/OnTimer/`ViSD`, preserved old terminology as rejected history, and recorded every exact behavior quirk and raw-helper zero-route rationale.

- 2026-07-13 Agent-B003 UID0000ZW support synchronization:
  - Changed `88/88` to `89/90`; normalized `OnMessage` to the common `OnChangeMessage(LObject *, Message *)` override and recorded inherited Application-owner register/unregister calls with `false`.
  - Preserved all Bink lifecycle, protected `OpenBinkVideo`, LogoPlayerPane caller, frame-field, vtable, raw-helper/no-route, compiler-thunk, and source-file ownership evidence.
  - Kept the class formal block blank because broader Bink/member/helper declaration blockers remain; callback type resolution does not justify inventing the rest of the class declaration.

- 2026-06-11 A005 Batch230 parent-gate repair:
  - Changed score from `86/84` to `87/86`.
  - Summary/evidence: live IDA reconfirmed the exact VideoPlayerPane vtable child, store xrefs, first slot targets, and successor boundary. [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md) now clears `86/86`, so this class can directly parent the vtable-data child while final C++ remains blank below the final-source gate.
- 2026-06-20 B003 `OpenBinkVideo` support sync:
  - Changed score from `87/86` to `88/88`.
  - Summary/evidence: [UID:0002PU][0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment](by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md) now provides caller-side proof for protected `VideoPlayerPane::OpenBinkVideo(const void*, unsigned int)`, inherited `StartPlayback()`, `m_binkHandle`, and BINK frame-field naming. The class C++ block remains blank because raw helpers, exact flags, and full declaration names need broader coordination.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the Bink playback constructor/destructor/open/start/stop/message/idle/done/thunk method map, field notes, Bink API call evidence, and `term`/`VisD` behavior; confidence remains capped by `OpenBinkVideo` ownership and active Wave3 omission caveats.
- 2026-06-02 IDA MCP refresh:
  - Changed to: `COMPLETION:86` and `CONFIDENCE:84`.
  - Summary/evidence: added unpromoted close/sound/seek helpers in the `0x005c0174-0x005c01f0` area, marked the class reconstructable, and attached it to [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md). C++ remains blank because the class is below the 95+ final-source threshold.
