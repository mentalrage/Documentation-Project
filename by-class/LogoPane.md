*** UID:00007G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FunctionObject0;
struct Event;

class LogoPane : public Pane
{
public:
    LogoPane(const wchar_t *logoPath, FunctionObject0 *completionCallback);
    virtual ~LogoPane();

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void RequestAdvance();
    void MarkReadyAndScheduleAdvance();
    void AdvanceToNextScreen();
    void LoadStaticLogoFromFile(const wchar_t *logoPath);
    void AttachStaticLogoSurface();
    void QueueAdvanceToNextScreen();

    EPFTileContext m_logoTileContext;       // +0x0f8
    DLPalette m_logoPalette;                // +0x120
    bool m_advanceRequestedBeforeReady;     // +0x34c
    bool m_logoReady;                       // +0x34d
    bool m_advanceQueued;                   // +0x34e
    unsigned char m_reserved34f;
    FunctionObject0 *m_completionCallback;  // +0x350
};

*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LogoPane

## Status

- Confidence: strong for behavior and startup ownership.
- Likely source file: [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- Address range: [UID:00019C][0x004f4c10-0x004f53a8.LogoPane](by-memory/0x004f4c10-0x004f53a8.LogoPane.md)
- Current recovered file: `source-3/simroot_v2/class_LogoPane.cpp`

## Class Purpose

`LogoPane` displays the static startup logo, loads and inflates the `.LGO` image, draws it through the tile/palette path, and advances startup after a timer or user click. It owns the completion callback that hands control back to the application startup flow.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | [UID:0002PL][0x004f4c10-0x004f4eac.LogoPaneConstructor](by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md) | First-draft emitted `LogoPane::LogoPane(const wchar_t *logoPath, FunctionObject0 *completionCallback)`; initializes pane/vtables, reads compressed logo pixels and palette, builds mask data, attaches to layer, and registers the delayed-ready zero-argument callback. |
| non-deleting destructor body | [UID:0002PM][0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor](by-memory/0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor.md) | Ordinary `LogoPane::~LogoPane()` source body; releases `m_logoTileContext` buffers and frees live `m_logoPalette` data. |
| `RequestAdvance` | [UID:0003LF][0x004f4f30-0x004f4f61.LogoPaneRawAdvanceRequest](by-memory/0x004f4f30-0x004f4f61.LogoPaneRawAdvanceRequest.md) | Retained unpromoted zero-argument helper; now emits first-draft C++. It checks ready/queued flags, stops pending timers, queues advancement, or latches an early advance request. |
| `OnPaint` | [UID:0003LG][0x004f4f70-0x004f4f94.LogoPaneOnPaint](by-memory/0x004f4f70-0x004f4f94.LogoPaneOnPaint.md) | Primary `+0x44` Pane override; draws the decoded logo through `g_pfnDrawEPFTile`. |
| `HandleKeyOrTextEvent` | [UID:0003LH][0x004f4fa0-0x004f4fde.LogoPaneHandleKeyOrTextEvent](by-memory/0x004f4fa0-0x004f4fde.LogoPaneHandleKeyOrTextEvent.md) | EventHandler `+0x08` adjusted-this override; advances when ready or records an early request. |
| `HandlePointerOrMouseEvent` | [UID:0003LI][0x004f4fe0-0x004f502c.LogoPaneHandlePointerOrMouseEvent](by-memory/0x004f4fe0-0x004f502c.LogoPaneHandlePointerOrMouseEvent.md) | EventHandler `+0x04` override; handles left-button-up event code `3`. |
| `OnTimer` / `AdvanceToNextScreenCallback` | [UID:0003LJ][0x004f5030-0x004f5040.LogoPaneAdvanceToNextScreenCallback](by-memory/0x004f5030-0x004f5040.LogoPaneAdvanceToNextScreenCallback.md) | First-draft `bool LogoPane::OnTimer(int, int, int)` for the tertiary `LogoPane+0xa4` `TimerHandler` view; recovers the complete object, calls `QueueAdvanceToNextScreen`, and returns handled. |
| `MarkReadyAndScheduleAdvance` | [UID:0003LK][0x004f5040-0x004f506a.LogoPaneMarkReadyAndScheduleAdvance](by-memory/0x004f5040-0x004f506a.LogoPaneMarkReadyAndScheduleAdvance.md) | Marks load-ready and schedules delayed or immediate advance. |
| `AdvanceToNextScreen` | [UID:0003LL][0x004f5070-0x004f50a1.LogoPaneAdvanceToNextScreen](by-memory/0x004f5070-0x004f50a1.LogoPaneAdvanceToNextScreen.md) | Invokes and destroys completion callback, restores screen/cursor state, and marks pane for deletion. |
| retained static-logo loader / attach helpers | [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) | Unpromoted private helper bodies best named `LoadStaticLogoFromFile(const wchar_t *path)` and `AttachStaticLogoSurface()`. They have no direct call/pointer route in the final image but duplicate the constructor's static-logo load/attach flow as retained out-of-line definitions. |
| `QueueAdvanceToNextScreen` | [UID:0002PP][0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen](by-memory/0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen.md) | First-draft emitted queue helper; sets `m_advanceQueued` and enqueues a `PlainMemberFunctionObject0<LogoPaneCallback0, LogoPane>` targeting `AdvanceToNextScreen`. |
| deleting-destructor thunks | [UID:0002PQ][0x004f52de-0x004f52f4.LogoPaneDeletingDestructorThunks](by-memory/0x004f52de-0x004f52f4.LogoPaneDeletingDestructorThunks.md) | Compiler adjustor thunks; subtract `0xa0`/`0xa4` and forward to `0x004f5300`. |
| scalar deleting destructor | [UID:0002PR][0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor](by-memory/0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor.md) | MSVC scalar deleting destructor wrapper; generated from the virtual destructor declaration and ordinary destructor body. |

## Data Notes

- `this + 0xf8` is `EPFTileContext m_logoTileContext`; `+0xfc` is the decoded pixel pointer, `+0x104` the row stride, `+0x108` the `RectBounds`, `+0x118` the encoded-mask byte count, and `+0x11c` the encoded-mask bytes pointer.
- `this + 0x120` is `DLPalette m_logoPalette`; the field follows the `0x28`-byte tile context and runs through the palette lookup table before LogoPane-specific flags start at `+0x34c`.
- Layout closure: `Pane` derived state starts at `+0xf8`; `EPFTileContext` is `0x28` bytes, so the palette begins at `+0x120`; `DLPalette` occupies through object offset `+0x22b`, so LogoPane-specific flags begin at `+0x34c`; the completion callback pointer at `+0x350` closes the object at `+0x354`, matching the scalar deleting destructor guard size.
- B010 constructor source-quality closure names the LogoPane-specific tail fields as `bool m_advanceRequestedBeforeReady` at `+0x34c`, `bool m_logoReady` at `+0x34d`, `bool m_advanceQueued` at `+0x34e`, and `FunctionObject0 *m_completionCallback` at `+0x350`. The constructor clears the three latches and stores the callback; [UID:0003LK][0x004f5040-0x004f506a.LogoPaneMarkReadyAndScheduleAdvance](by-memory/0x004f5040-0x004f506a.LogoPaneMarkReadyAndScheduleAdvance.md), [UID:0003LF][0x004f4f30-0x004f4f61.LogoPaneRawAdvanceRequest](by-memory/0x004f4f30-0x004f4f61.LogoPaneRawAdvanceRequest.md), and [UID:0002PP][0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen](by-memory/0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen.md) supply the flag/callback use evidence.
- The constructor queues the ready path through `PlainMemberFunctionObject0<LogoPaneCallback0, LogoPane>` where `LogoPaneCallback0` is `void (__thiscall LogoPane::*)()`, target `&LogoPane::MarkReadyAndScheduleAdvance`, zero `this` adjustment, and captured `this`. The raw callback-vtable bytes stay under `FunctionObjects` compiler-generated template-data policy rather than being emitted from this class.
- `word_66DA94` and `word_66DA98` provide the startup logo/screen width and height, now resolved as [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) and [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md).
- `dword_69BE14` is the `WideApiDispatchTable` `_wfopen` slot, best provisional source name `g_pfnWideOpenFile`, used for the logo file.
- `dword_67A7CC` and `g_pTileImageLib` are callback/tile scheduling dependencies.
- `dword_69B36C` is a [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) UI layer/context slot used when attaching the pane to the startup layer; `g_mainUiLayerSlots.overlayPaneLayerContext` is descriptive but still provisional.

## Evidence Notes

- IDA xrefs show `LogoPane::LogoPane` is constructed from application startup around `0x004f643c`.
- The logo resource format is image-size dword, compressed image bytes, palette-size dword, palette bytes.
- `MarkReadyAndScheduleAdvance` schedules a `3000` ms delay unless the user has already clicked.
- 2026-06-12 A001 live IDA split verified the former [UID:0002PN][0x004f4f30-0x004f50a1.LogoPaneAdvanceAndBlitHandlers](by-memory/0x004f4f30-0x004f50a1.LogoPaneAdvanceAndBlitHandlers.md) mixed cluster as seven exact child bodies plus `0xcc` padding. The child pages document the field contract: `+0x34c` early-click/pending-skip latch, `+0x34d` ready latch, `+0x34e` queued-transition latch, and `+0x350` completion callback pointer.
- Current active generated output includes an unrelated `HeadSelectDialog` callback alias and duplicate normalized include comments near the file header. Ignore those as generated-source artifacts.
- Disabled generated output marks `0x004f52e9` missing, but IDA confirms it as the second `0xb` adjustor thunk.
- 2026-06-17 B002 source-quality reanalysis of [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) verified that `0x004f50b0-0x004f521e` and `0x004f5220-0x004f5246` are source-authored retained helper bodies. IDA and PE scans show zero direct xrefs, rel32 edges, or VA/RVA pointer hits to the helper starts, while the constructor contains the duplicate static-logo load/attach flow. Treat them as private `LogoPane` helpers whose bodies were inlined into the constructor and retained out of line.
- 2026-06-18 B002 destructor source-quality closure: [UID:0002PM][0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor](by-memory/0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor.md) should emit `LogoPane::~LogoPane()` with `m_logoTileContext.ReleaseBuffers();` and `m_logoPalette.FreePaletteData();`. The scalar deleting destructor [UID:0002PR][0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor](by-memory/0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor.md) and adjustor thunks [UID:0002PQ][0x004f52de-0x004f52f4.LogoPaneDeletingDestructorThunks](by-memory/0x004f52de-0x004f52f4.LogoPaneDeletingDestructorThunks.md) remain compiler-generated destructor-dispatch glue and should not be hand-written as source C++.
- 2026-06-25 B010 constructor source-quality implementation: [UID:0002PL][0x004f4c10-0x004f4eac.LogoPaneConstructor](by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md) now emits first-draft `LogoPane::LogoPane(const wchar_t *logoPath, FunctionObject0 *completionCallback)`. Live MCP session `80de0a67` reconfirmed the one caller at `0x004f643c`, vtable setup, `_wfopen` static-logo load path, layer attach, callback object allocation, and binary-faithful failure fallthrough. [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) remains a blank-C++ retained helper because no direct xref/rel32/pointer route exists.
- 2026-06-25 B008 source-quality implementation for [UID:0002PN][0x004f4f30-0x004f50a1.LogoPaneAdvanceAndBlitHandlers](by-memory/0x004f4f30-0x004f50a1.LogoPaneAdvanceAndBlitHandlers.md) reconfirms the advance/blit cluster as a non-emitting split index, not a class-level source body. Current MCP session `80de0a67` ties the exact child handlers to `m_advanceRequestedBeforeReady` at `+0x34c`, `m_logoReady` at `+0x34d`, `m_advanceQueued` at `+0x34e`, and `m_completionCallback` at `+0x350`; timer calls use `TimerHandler::RemovePendingTimers()` / `TimerHandler::ScheduleTimer()`, the queue route uses `ScreenPane::QueueFadeOutCallback`, and callback objects use `PlainMemberFunctionObject0<LogoPaneCallback0, LogoPane>`. Class score is unchanged because broader declaration and virtual-slot source names remain below final audit.
- 2026-06-29 B010 implementation for [UID:0003LF][0x004f4f30-0x004f4f61.LogoPaneRawAdvanceRequest](by-memory/0x004f4f30-0x004f4f61.LogoPaneRawAdvanceRequest.md) promotes the retained raw advance helper to formal first-draft `void LogoPane::RequestAdvance()` C++. Current MCP session `b2ae72ec` reconfirmed the exact raw `0x004f4f30-0x004f4f61` body, `0x31`/49 byte size, `0xcc` pre/post padding, no IDA function record, zero inbound code/data xrefs, zero VA/RVA/endpoint pointer hits, unique entry/range signatures, and queue-helper tail call at `0x004f4f53`. The no-route result remains a retained-helper liveness caveat and confidence cap, not a reason to clear the [UID:00007G] owner/emitter or leave an empty marker.
- 2026-06-29 B001 implementation for [UID:0003LJ][0x004f5030-0x004f5040.LogoPaneAdvanceToNextScreenCallback](by-memory/0x004f5030-0x004f5040.LogoPaneAdvanceToNextScreenCallback.md) promotes the tertiary `LogoPane+0xa4` timer callback to formal first-draft `bool LogoPane::OnTimer(int, int, int)` C++. Current MCP session `b2ae72ec` proves the exact `0x10` body, four-byte pre-padding, `0x0061cff8` vtable data xref, constructor store at `0x004f4c6a`, `this -0xa4` recovery from the `TimerHandler` view, call to [UID:0002PP][0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen](by-memory/0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen.md), handled return, and `retn 0xc` three-argument cleanup. The wildcard signature also matches `0x004c7610`, so byte-only naming remains a confidence cap; the class/vtable/callee route resolves the empty-emitter blocker.

## Virtual Contract And Historical Names

- The corrected LogoPane record has three decorated views and the exact hierarchy `LogoPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler`. Constructor, ordinary-destructor, and scalar-wrapper paths write each table head, yielding nine exact stores.
- Primary `+0x44` at `0x0061cfbc` resolves `OnPaint`; EventHandler `+0x04` at `0x0061cfc8` resolves `HandlePointerOrMouseEvent(Event *)`; EventHandler `+0x08` at `0x0061cfcc` resolves `HandleKeyOrTextEvent(Event *)`; TimerHandler `+0x04` at `0x0061cff8` remains `OnTimer`.
- `BlitLogoFrame`, `HandleAdvanceRequest`, and `OnMouseDown` were behaviorally useful names introduced before the complete inherited-slot audit. They are retained as disproven historical assumptions; the formal H uses the compile-consistent inherited contracts.
- The prior `int BlitLogoFrame()` return and `MouseEvent`/integer parameter forms mirrored decompiler output and stack cleanup. The virtual contracts resolve human source signatures without changing runtime behavior.
- Completion is `93` and confidence is `94`: class layout, fields, callback lifecycle, full vtable/RTTI family, source virtuals, and formal declaration are complete. Original private/helper/member spellings remain the sub-95 cap.

## Cross-References

- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:00019C][0x004f4c10-0x004f53a8.LogoPane](by-memory/0x004f4c10-0x004f53a8.LogoPane.md)
- [UID:0002PN][0x004f4f30-0x004f50a1.LogoPaneAdvanceAndBlitHandlers](by-memory/0x004f4f30-0x004f50a1.LogoPaneAdvanceAndBlitHandlers.md)
- [UID:0001RN][startup-logo-media](by-resource/startup-logo-media.md)

## Changes

- 2026-08-01 Agent-B004 UID0003OO support callback:
  - Raised `90/91 -> 93/94`, moved the complete class declaration into formal H, kept `[[CHILDREN]]` in formal CPP, and replaced the three stale virtuals with `OnPaint`, `HandlePointerOrMouseEvent(Event *)`, and `HandleKeyOrTextEvent(Event *)`; `OnTimer` retains its exact three-argument bool contract.
  - Added three-view RTTI/vtable closure and preserved the prior helper-shaped identities in a dedicated historical section.
- 2026-06-30 B008 UID0000O4 implementation callback:
  - Changed class score from `88/90` to `90/91` and populated the formal declaration/`[[CHILDREN]]` block for `LogoPane` under [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md).
  - The declaration records the source-facing fields proven by child evidence: `m_logoTileContext` at `+0x0f8`, `m_logoPalette` at `+0x120`, `m_advanceRequestedBeforeReady` at `+0x34c`, `m_logoReady` at `+0x34d`, `m_advanceQueued` at `+0x34e`, and `m_completionCallback` at `+0x350`.
  - Stale child-level blank-C++ blockers are superseded for UID0003LG/0003LH/0003LI/0003LK/0003LL/0002PO/0002PP. Remaining names such as `g_pfnDrawEPFTile`, inherited `m_bounds`, and `g_mainUiLayerSlots.overlayPaneLayerContext` are confidence caps, not empty-emitter blockers.
- 2026-06-25 B010 LogoPane constructor C++ readiness sync:
  - Score unchanged at `88/90`.
  - Summary/evidence: [UID:0002PL][0x004f4c10-0x004f4eac.LogoPaneConstructor](by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md) is now `90/92` with formal first-draft constructor C++. This class page records the constructor signature, source-facing latch/callback field names at `+0x34c`, `+0x34d`, `+0x34e`, and `+0x350`, the `PlainMemberFunctionObject0<LogoPaneCallback0, LogoPane>` zero-argument callback route, and the retained-helper/no-xref caveat for [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md). Class metadata is unchanged because broader class-level declaration and virtual-slot original names remain below final audit.
- 2026-06-25 B008 aggregate advance/blit source-quality sync:
  - Score unchanged at `88/90`.
  - Summary/evidence: [UID:0002PN][0x004f4f30-0x004f50a1.LogoPaneAdvanceAndBlitHandlers](by-memory/0x004f4f30-0x004f50a1.LogoPaneAdvanceAndBlitHandlers.md) is now `92/92` and remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and non-emitting. This class page records the resolved advance/ready/queued/completion field names and the timer/screen/callback helper route while leaving child C++ decisions on the exact child pages.
- 2026-06-29 B010 UID0003LF RequestAdvance implementation:
  - Score unchanged at `88/90`.
  - Summary/evidence: [UID:0003LF][0x004f4f30-0x004f4f61.LogoPaneRawAdvanceRequest](by-memory/0x004f4f30-0x004f4f61.LogoPaneRawAdvanceRequest.md) is now `88/90` with formal first-draft `void LogoPane::RequestAdvance()` C++. This class page records it as a retained source-shaped helper under `LogoPane`; the missing inbound xref/pointer route is preserved as a confidence cap while [UID:0003LH][0x004f4fa0-0x004f4fde.LogoPaneHandleKeyOrTextEvent](by-memory/0x004f4fa0-0x004f4fde.LogoPaneHandleKeyOrTextEvent.md)/[UID:0003LI][0x004f4fe0-0x004f502c.LogoPaneHandlePointerOrMouseEvent](by-memory/0x004f4fe0-0x004f502c.LogoPaneHandlePointerOrMouseEvent.md) remain the adjusted virtual/input handlers and [UID:0002PP][0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen](by-memory/0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen.md) remains the queue helper.
- 2026-06-29 B001 UID0003LJ OnTimer implementation:
  - Score unchanged at `88/90`.
  - Summary/evidence: [UID:0003LJ][0x004f5030-0x004f5040.LogoPaneAdvanceToNextScreenCallback](by-memory/0x004f5030-0x004f5040.LogoPaneAdvanceToNextScreenCallback.md) is now `88/91` with formal first-draft `bool LogoPane::OnTimer(int, int, int)` C++. This class page records it as the `LogoPane+0xa4` `TimerHandler` callback route from [UID:0003LK][0x004f5040-0x004f506a.LogoPaneMarkReadyAndScheduleAdvance](by-memory/0x004f5040-0x004f506a.LogoPaneMarkReadyAndScheduleAdvance.md) to [UID:0002PP][0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen](by-memory/0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen.md). The exact original virtual-slot spelling remains a final-audit confidence cap, but `OnTimer` is the accepted first-draft source shape under the project `TimerHandler` callback contract.
- 2026-06-12 A001 Goal 2 parent-gate repair:
  - What existed before: `84/86`; the class was already attached to [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md) but was below the strict `85/85` completion gate for assigning newly split method children.
  - Changed to: `86/88`, with exact child links for the former advance/blit cluster, the live flag/callback field contract, and current IDA split evidence.
  - Summary/evidence: live IDA MCP confirmed exact child boundaries, vtable/callback data slots, constructor callback binding, queue-helper binding, and internal padding for [UID:0002PN][0x004f4f30-0x004f50a1.LogoPaneAdvanceAndBlitHandlers](by-memory/0x004f4f30-0x004f50a1.LogoPaneAdvanceAndBlitHandlers.md). The direct file parent [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md) already clears the `85/85` gate at `88/85`.
- 2026-06-17 B002 retained static-logo helper sync:
  - What existed before: the class page covered constructor and advance/skip behavior but did not record the source-quality decision for [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md).
  - Changed to: added the retained loader/attach helper row, `m_logoTileContext` and `m_logoPalette` field directions, and the `WideApiDispatchTable` / `MainUiLayerSlots` dependency decisions. Class score is unchanged because final per-member and virtual-slot names remain provisional.
  - Summary/evidence: B002 rechecked IDA function absence, PE xref/pointer scans, constructor duplicate flow, and support docs, raising [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) to `86/90` while keeping formal C++ blank by accepted emission-policy reasoning.
- 2026-06-18 B002 destructor closure:
  - Changed from `86/88` to `88/90`.
  - Evidence: [UID:0002PM][0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor](by-memory/0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor.md) now carries first-draft `LogoPane::~LogoPane()` C++; `m_logoTileContext` and `m_logoPalette` are layout-backed by Pane derived-state start, `EPFTileContext` size, `DLPalette` size, LogoPane flags at `+0x34c`, completion callback at `+0x350`, and scalar wrapper guard size `0x354`.
  - Source policy: ordinary destructor body is source-authored; scalar deleting destructor and adjusted-this thunks are generated ABI glue.
- Completion/confidence score update: existed before as `0/0`; changed to `84/86`. Summary: the static startup-logo pane is documented across resource loading, palette/mask setup, timer/click advancement, callback lifecycle, globals, cleanup, and generated artifact caveats. Evidence: linked `LogoPane` memory range, resource format notes, application startup constructor xref, delay/skip behavior, and confirmed adjustor thunk/destructor details.
- 2026-06-01 autogen attachment:
  - Marked reconstructable and attached to [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md) after the parent file was assigned to `NexusTK/app/`.
  - C++ was blank at that historical checkpoint because the class-level declarations and exact member names were not final-source quality; this is superseded by the 2026-06-30 B008 formal declaration block.
