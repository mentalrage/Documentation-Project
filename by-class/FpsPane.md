*** UID:00005F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FpsPane.h"

#include "../../map/MapPane.h"
#include "../../map/ObjectList.h"
#include "../../util/List.h"
#include "../../util/StringBase.h"
#include "../MainUiGraph.h"

#include <mmsystem.h>
#include <stdio.h>

template <>
Singleton<FpsPane>::Singleton()
{
    g_pFpsPane = static_cast<FpsPane *>(this);
}

template <>
Singleton<FpsPane>::~Singleton()
{
    g_pFpsPane = 0;
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_DIAGNOSTICS_FPSPANE_H
#define NEXUSTK_UI_DIAGNOSTICS_FPSPANE_H

#include <windows.h>

#include "../core/Pane.h"
#include "../../util/Singleton.h"

class FpsPane : public Pane, public Singleton<FpsPane>
{
public:
    FpsPane();
    virtual ~FpsPane();

    void UpdateFpsLogSession(bool startNew);

protected:
    virtual void OnPaint();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void StartLogSession();
    void WriteLogSummary();

    int m_frameCount;
    unsigned int m_reservedFrameState;
    float m_currentFps;
    char m_logFileName[50];
    SYSTEMTIME m_logStartTime;
    DWORD m_logStartTick;
    float m_minFps;
    float m_maxFps;
    unsigned int m_sampleCount;
    double m_totalFps;
    unsigned int m_totalLivingObjects;
    unsigned int m_totalBalloonObjects;
    unsigned int m_totalStaticObjects;
};

extern int g_fpsDebugActive;
extern bool g_fpsLogEnabled;
extern FpsPane *g_pFpsPane;

typedef char FpsPaneSizeMustBe0x170[(sizeof(FpsPane) == 0x170) ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FpsPane

## UID00029O Incidental IME-Layer Reuse - 2026-07-21

`UpdateFpsLogSession` uses independent [UID:0004VG][g_pIMEPaneLayer](by-global/g_pIMEPaneLayer.md) once as the frame parent when beginning a visible logging session. This is incidental reuse and does not transfer ownership or justify an Fps-specific global alias. Complete diagnostics/logging/timer/resource/field/helper behavior, raw-body liveness caveat, class layout, method inventory, and scores remain unchanged.

## Status

- Confidence: strong for overlay/statistics responsibility, vtable/global ownership, modeled paint/statistics/destructor behavior, and child vtable parentage; medium for the raw constructor/session-start boundaries.
- Likely source file: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Current generated source: `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`

## g_fpsLogEnabled Support Note

- This class owns the methods that consume [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md), but it does not own or emit the file-level variable definition as class C++.
- The exact one-byte storage child is [UID:0002W1][0x0069b338-0x0069b339.g_fpsLogEnabled](by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md). Original-PE mapping places it in the unbacked writable `.data` virtual tail, so its default value is loader zero rather than a stored `0xff` initializer.
- Exactly four FpsPane diagnostics instructions read the byte: `0x004b653f` gates new log-file creation, `0x004b6645` gates final summary output, `0x004b6a17` gates retained `StartLogSession` output, and `0x004b6ae4` implements `WriteLogSummary`'s early disabled return. All are `cmp byte ptr ...,0` reads; no writer appears in the exact xrefs, pointer searches, current generated source, or FPS config/UI/input searches.
- The strongest human-source form is default-off `bool g_fpsLogEnabled;`, emitted exactly once by UID0000PZ through [UID:0000JK][FpsPane](by-file/FpsPane.md) in `NexusTK/ui/diagnostics/FpsPane.cpp`. UID0002W1 emits only a covered-by comment, and this class page must not duplicate either the global definition or a header declaration.
- Historical `db ?`, `0xff`, saved-rename, and ParcelPane-source conclusions are retained on the global/memory/file pages as limited or disproved history. They do not change this class's score, ownership, emitter route, or blank formal CPP/H blocks.
- Historical generated-data caveat: `source-3/simroot_v2/class_FpsPane.cpp`, `source-3/simroot_v2/class_ParcelPane.meta_wave3`, and ParcelPane global-data rows remain stale lead material for FPS globals and the old `0x004b64a0` owner context.
- Memory range: [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- Layout docs: [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)
- Exact vtable data: [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md)

## Class Purpose

`FpsPane` is a small diagnostic overlay pane. It displays the current frames-per-second value, samples FPS once per second, records min/max/average statistics, and collects map object-count metrics by reading the `ObjectList` row buckets used by `MapPane`.

This class is a consumer of [UID:00009Q][ObjectList](by-class/ObjectList.md), not an owner of the map object index.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x004b6410-0x004b646b` | `FpsPane::FpsPane` | Raw constructor calls `Pane(1)`, installs three compiler vtable views, publishes through the Singleton base specialization, sets inherited `m_hasPendingMotionRegion`, and zeros `m_currentFps`. It deliberately does not initialize `+0xf8/+0xfc`. |
| `0x004b6470-0x004b6499` | `FpsPane::~FpsPane()` | IDA-confirmed ordinary destructor with an empty authored body. Singleton clear, three FpsPane vtable restores, and the `Pane::~Pane()` tail chain are base/compiler mechanics rather than handwritten statements. |
| `0x004b64a0-0x004b67a7` | `UpdateFpsLogSession` | Exact source uses `RectBounds::SetLTRB`, inherited layer attachment/removal and timer APIs, `g_pIMEPaneLayer`, and retained `StartLogSession()` / `WriteLogSummary()` helpers. Zero inbound xref/pointer-route evidence remains a liveness cap, not an ownership or C++ blocker. |
| `0x004b67b0-0x004b68ab` | `OnPaint` | First-draft C++ is now populated as `void FpsPane::OnPaint()`. The method increments `m_frameCount` at `+0xf8`, formats `m_currentFps` at `+0x100` with UTF-16 `L"%5.1f FPS"`, copies inherited bounds, clears/fills those bounds through [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `0x0069b3fc`, then draws two counted UTF-16 text passes at `(1,13)` color `128` and `(0,12)` color `14`. |
| `0x004b68b0-0x004b69b0` | `OnTimer` (`UpdateStatistics` historical alias) | Exact source is `bool FpsPane::OnTimer(int, int, int)`. The TimerHandler facet is reached through owner `+0xa4`; the body samples/resets `m_frameCount +0xf8`, writes `m_currentFps +0x100`, updates FPS and object-count totals through `+0x168`, and calls inherited `ScheduleTimer(0, 1000, 0, 0)`. |
| `0x004b69b0-0x004b6adc` | retained private `StartLogSession` helper | [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md) is now the source-facing child page. IDA still leaves the entry raw/unmodeled with no direct xrefs, but MCP session `80de0a67` confirms the complete 70-instruction helper body, duplicate start-session shape in `UpdateFpsLogSession`, exact string/global refs, and `0x004b6adc-0x004b6ae0` padding. Best current inference remains a retained private helper or old implementation duplicated/inlined into `UpdateFpsLogSession`; the no-route result is a confidence cap, not a C++ blocker. |
| `0x004b6ae0-0x004b6c2b` | retained private `WriteLogSummary` helper | [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md) is now the source-facing child page at `88/89` with formal `FpsPane::WriteLogSummary()` C++ retained. B003's current MCP session `80de0a67` keeps the raw entry unmodeled with no direct xrefs/callers and no VA/RVA/raw-offset pointer route, but decodes the complete 84-instruction `0x14b` byte body with SHA16 `93961235a91a75d1`, four `0xcc` pre-padding bytes, and the direct `retn`-to-adjustor-thunk boundary at `0x004b6c2b`. The helper gates on `g_fpsLogEnabled`, opens `m_logFileName` in append mode through the `0x0061a700` `"a"` literal, writes elapsed seconds, FPS min/max/average, and computed object-count averages, and then closes the file. Best current inference remains a retained private helper or old helper implementation duplicated/inlined into `UpdateFpsLogSession`; no-route status is a liveness/final-audit cap, not a C++ blocker. |
| [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md) | vtable adjustment thunks | Compiler-generated thunks that forward to scalar deleting destructor with `this - 0x28` and `this - 0x29` dwords. Disabled in Wave3 active output and listed in ignored memory ranges. |
| `0x004b6c50-0x004b6caf` | scalar deleting destructor wrapper | Compiler-generated vtable/delete support for `FpsPane::~FpsPane()`. It clears `g_pFpsPane`, destroys the pane base, optionally deletes memory, and has a guard-check flag-4 path with size `0x170`, but should not be hand-authored as a source method. The exact child carries only a comment/no-code marker. |

## Layout Notes

B006's 2026-07-04 UID00015D implementation keeps this class as the direct owner/emitter for exact source-bearing children while converting [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) into a reviewed non-emitting split/index parent. The broad parent records the range map and current MCP evidence; it should not duplicate child method C++, claim class-level source ownership over the aggregate body, or remain an empty emitter marker. Raw starts remain no-route confidence caps on their exact child pages.

See [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md) for normalized offsets. `OnTimer` is reached through the TimerHandler view at owner offset `+0xa4`, so raw offsets normalize by adding `0xa4`. Paint and timer paths share owner fields `+0xf8` and `+0x100`; logging-session fields occupy `+0x104` through `+0x168`.

B003's source-quality pass standardizes the descriptive field names used by the first-draft method bodies: inherited `m_visible` / `m_isVisible` at `+0xf5`, `m_frameCount` at `+0xf8`, `m_currentFps` at `+0x100`, `m_logFileName` at `+0x104`, `m_logStartTime` at `+0x136`, `m_logStartTick` at `+0x148`, `m_minFps` at `+0x14c`, `m_maxFps` at `+0x150`, `m_sampleCount` at `+0x154`, `m_totalFps` at `+0x158`, `m_totalLivingObjects` at `+0x160`, `m_totalBalloonObjects` at `+0x164`, and `m_totalStaticObjects` at `+0x168`. Names remain descriptive/inferred, but they are the best current source-facing names.

## OnPaint Source-Quality Note

B005's 2026-06-19 implementation confirms the paint child [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md) is source-bearing `FpsPane::OnPaint`, not compiler glue or a no-code vtable artifact. Local PE/Capstone evidence over `NexusTK.exe` confirms the exact `0xfb` range, nine leading `0xcc` bytes before `0x004b67b0`, five trailing `0xcc` bytes before the [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) start at `0x004b68b0`, zero direct branch/call refs to the start or end, and the sole absolute target pointer at primary vtable slot `0x0061a664`.

`OnPaint` and `OnTimer` form the frame-count/current-FPS producer-consumer pair. `OnPaint` increments `m_frameCount` at `+0xf8` and displays `m_currentFps` at `+0x100`; `OnTimer`, reached through the TimerHandler view at owner offset `+0xa4`, samples/resets `+0xf8` and writes `+0x100` once per second. This pair is FpsPane-owned. GrafPort, StringBase, MapPane, ObjectList, TimerHandler, and MainUiGraph remain dependencies; ParcelPane remains rejected historical pollution.

Helper roles for the paint child are source-facing but still address-backed: `0x00583280` constructs/formats the local wide string, `0x00584cf0` returns its length, `0x00584540` returns its data pointer, `0x00582b70` releases it, `0x004b8e00` copies inherited bounds, `0x004b9660` sets active draw/fill color, `0x0069b3fc` is the active rectangle fill callback, `0x004b9680` supplies the text-pass color state, `0x004b9600` moves the text cursor, and `0x004bab70` draws counted UTF-16 text. Raw generated labels such as `sub_4B67B0`, `dword_69B3FC`, `g_pfnLockSurface`, and caller-biased GrafPort helper names should stay evidence labels, not source method names.

## OnTimer Source-Quality Note (Historical UpdateStatistics Alias)

Current accepted evidence identifies [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) as source-bearing `bool FpsPane::OnTimer(int, int, int)`, not no-code timer glue, a compiler thunk, a scalar deleting destructor, or a MapPane/ObjectList/TimerHandler-owned helper. `UpdateStatistics` remains the historical documentation slug. Local evidence confirms the exact `0x100` body, five leading `0xcc` bytes after `OnPaint`, no trailing padding before the raw start-session helper at `0x004b69b0`, zero direct branch/call refs to the start or end, and the sole absolute target pointer at timer vtable slot `0x0061a6a0`.

The callback is reached through the embedded timer/update facet at owner offset `+0xa4`. B005 preserves the normalized field map: `m_frameCount +0xf8`, `m_currentFps +0x100`, `m_minFps +0x14c`, `m_maxFps +0x150`, `m_sampleCount +0x154`, `m_totalFps +0x158`, `m_totalLivingObjects +0x160`, `m_totalBalloonObjects +0x164`, and `m_totalStaticObjects +0x168`. `OnPaint` and `UpdateStatistics` are the producer/consumer pair: `OnPaint` increments the frame counter and displays the latest FPS sample, while `UpdateStatistics` samples/resets the counter, writes the current FPS, updates session statistics, and repeats the timer after 1000 ms.

MapPane, ObjectList, and TimerHandler are dependencies for this method, not owners. `g_activeMapPane` supplies the active map, `MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const` supplies the loop-exclusive visible row range, `MapPane +0x424` supplies `m_objectList`, `ObjectList::GetFrontRowBucket(row)` and `GetBackRowBucket(row)` provide row-bucket counts, `ObjectList::GetVisibleObjectList()` supplies the visible/balloon count, and `TimerHandler::ScheduleTimer` / `m_updateTimer.StartTimer(0, 1000, 0, 0)` reschedules the callback. The ObjectList row-tier names and exact `MapRect` spelling remain descriptive source-facing names, but the call order, count field at returned object `+0x0c`, and accumulator mapping are stable enough for first-draft C++.

## Vtable Ownership And Child Gate

[UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md) is a direct child of this class page. It represents the source-declared virtual layout for `FpsPane` itself, not a free file-level table. The owning file [UID:0000JK][FpsPane](by-file/FpsPane.md) is already `87/85`, and this class is now `85/86`, so class-level vtable children can clear the strict child/direct-parent `85/85` assignment gate when their own evidence is sufficient.

The vtable evidence is now specific enough for that parent gate: the primary view at `0x0061a620`, secondary pane view at `0x0061a66c`, and timer/update view at `0x0061a69c` are installed by the raw constructor, non-deleting destructor, and scalar deleting destructor. The primary paint slot points at `0x004b67b0`, the tertiary timer/update slot points at `0x004b68b0`, and the two secondary/tertiary delete entries are compiler adjustor thunks into the scalar deleting destructor.

## Destructor Source-Quality Note

B004's 2026-06-20 implementation and B012's local export/listing recheck resolve [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) as source-bearing `FpsPane::~FpsPane()`. The exact binary body is `0x29` / 41 bytes, has no direct caller/xref route, stores the primary/secondary/timer vtable views at owner offsets `+0x00`, `+0xa0`, and `+0xa4`, clears [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md) at `0x004b648a`, and tail-jumps to `Pane::~Pane()` / pane-base destructor helper `0x00544580`. The source-level body is only `g_pFpsPane = 0;`; vtable restoration and base-destruction are compiler/implicit destructor lowering.

[UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) remains the MSVC scalar deleting destructor wrapper. Its primary vtable slot at `0x0061a620`, secondary/timer adjustor thunk jumps at `0x004b6c31` and `0x004b6c3c`, repeated vtable restores, singleton clear at `0x004b6c70`, `Pane::~Pane()` call, optional `sub_4F4AC0` delete path, and `_guard_check_icall_nop` / `0x170` flag-4 path are wrapper evidence regenerated from the virtual destructor and class layout. The exact page is class-owned/reconstructable because `virtual ~FpsPane()` must regenerate it, but source output should stay a comment/no-code marker rather than a handwritten `ScalarDeletingDestructor` method. Do not move scalar-delete flag handling into the source destructor.

## Method Child Gate

[UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) is also a direct child of this class. B008's 2026-06-25 IDA MCP pass keeps the unresolved liveness cap because the current IDB still has no function object, direct caller/xref, or literal VA/RVA/raw-offset pointer route to `0x004b64a0`, but it confirms the method-shaped 190-instruction body, exact boundary/hash, FpsPane logging fields, FpsPane globals, paired start/summary helper string refs, and timer show/hide flow. The child is now `89/89` and first-draft C++ ready under this class; the raw-entry route gap is a final-audit score cap, not a reason to attach it to the file root or blank its C++.

## Evidence Notes

- 2026-06-10 A001 live IDA pass reconfirmed the current boundary split: `0x004b6470`, `0x004b67b0`, `0x004b68b0`, `0x004b6c2b`, `0x004b6c36`, and `0x004b6c50` are functions, while `0x004b6410`, `0x004b64a0`, `0x004b69b0`, and `0x004b6ae0` remain raw code starts with no direct xrefs.
- 2026-06-10 A001 xrefs show `g_pFpsPane` writes only from the raw constructor start, non-deleting destructor, and scalar deleting destructor. The three FpsPane vtable views at `0x0061a620`, `0x0061a66c`, and `0x0061a69c` are likewise installed by the constructor/destructor/scalar-delete paths, and the `0x0061a66c`/`0x0061a69c` slots point to the two adjustor thunks.
- 2026-06-10 A001 decompilation check confirms `OnPaint` formats the `"%5.1f FPS"` string, increments the frame counter, and performs the paired foreground/shadow text draws; `UpdateStatistics` resets the sampled frame counter, updates min/max/sample/total fields, reads the `MapPane` visible row range, accumulates front/back/object-list bucket counts, and schedules the next 1000 ms timer.
- 2026-06-19 B005 source-quality implementation updates the OnPaint child to `88/91` with first-draft C++. The class-level implication is that `FpsPane` owns the paint route, the source file [UID:0000JK][FpsPane](by-file/FpsPane.md) should emit the method in `NexusTK/ui/diagnostics/FpsPane.cpp`, and non-FpsPane owners remain rejected for the paint body.
- 2026-06-23 B002 source-quality implementation renames [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md) from the old raw-suffixed page name while preserving the raw/unmodeled evidence. MCP session `80de0a67` confirms no function/caller/xref/literal route to `0x004b69b0`, a decoded 70-instruction start-session helper, `g_fpsDebugActive` refs at `0x004b69bd`/`0x004b6acd`, `g_fpsLogEnabled` ref at `0x004b6a17`, start-string refs at `0x004b6a60`/`0x004b6a6d`/`0x004b6a7c`/`0x004b6ab1`, and four `0xcc` padding bytes before the summary helper.
- 2026-06-23 B003 WriteLogSummary source-quality implementation keeps [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md) under `FpsPane` at `88/89` with formal `FpsPane::WriteLogSummary()` C++ retained. MCP session `80de0a67` confirms no function object, no direct xrefs/callers, no loaded-image VA/RVA/raw-offset pointer route to `0x004b6ae0`, 84 decoded instructions, body SHA16 `93961235a91a75d1`, four `0xcc` pre-padding bytes after [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md), and a positive successor-thunk vtable pointer at `0x0061a66c` proving `0x004b6c2b` starts the adjustor thunk island. The method appends the summary through `0x0061a700` `"a"` and the broad formatted-write wrapper `sub_443990`; source output stays `fprintf(file, ...)`, not an IDA helper call.
- 2026-06-10 A001 raw disassembly check keeps the session helpers as unresolved private/raw starts: `0x004b69b0` duplicates the session reset/log filename setup shape and `0x004b6ae0` gates summary writing on `g_fpsLogEnabled`, but both have no direct xrefs in the current IDB.
- 2026-06-11 A002 live IDA MCP rechecked the vtable child parentage: `lookup_funcs` reports modeled functions at `0x004b6470`, `0x004b67b0`, `0x004b68b0`, `0x004b6c2b`, `0x004b6c36`, and `0x004b6c50`; `xrefs_to` the three vtable bases reports the same constructor/destructor/scalar-delete store triads; a dword scan confirms the slot targets through `0x0061a6a0` and the `0x0061a6a4` `FPSDATA` string boundary; decompilation confirms the paint slot, timer/update slot, and scalar-delete vtable restoration behavior.
- 2026-06-13 A001 live IDA MCP rechecked `UpdateFpsLogSession` child parentage: `lookup_funcs` still reports no function at `0x004b64a0`, `insn_query 0x004b64a0-0x004b67a8` decodes the complete raw prologue/start/finalize/dual-return body, xrefs to `g_fpsDebugActive` and `g_fpsLogEnabled` remain confined to this diagnostics island, the FPSDATA/summary strings are referenced only by the session body and raw sibling helpers, and literal-address search finds no direct pointer to the raw entry. This supports class attachment at `85/85`; after B003, the same no-xref fact is treated as a liveness score cap rather than a first-draft C++ blocker.
- 2026-06-25 B008 implementation refreshes [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) to `89/89` while retaining this class as owner/emitter and retaining the formal `FpsPane::UpdateFpsLogSession(bool startNew)` C++ body. MCP session `80de0a67` confirms modeled neighbors at `0x004b6470`, `0x004b67b0`, `0x004b68b0`, `0x004b6c2b`, `0x004b6c36`, and `0x004b6c50`; no function/decompile body for raw starts `0x004b64a0`, `0x004b69b0`, or `0x004b6ae0`; a 190-instruction target body with SHA-256 `5dfaffba35e1013a192cd1c812c0c135b0544b94a515d10f148dfb75c6de596e`; paired global/string refs with the 70-instruction `StartLogSession` and 84-instruction `WriteLogSummary` helpers; and zero VA/RVA/raw-offset pointer hits to the raw starts. No-route status remains a liveness cap.
- 2026-06-17 B003 source-quality pass replaces the stale no-C++ caveat for eligible children: no modeled function/caller/xref status is a score/final-audit cap, not a blocker to first-draft C++ once owner/emitter routing and combined score clear the active gate. It also records local IDA export facts for `g_pFpsPane` as `dd ?`, `g_fpsLogEnabled` as `db ?`, and `g_fpsDebugActive` as `dd 1`.
- IDA MCP confirms real functions at `0x004b6470`, `0x004b67b0`, `0x004b68b0`, `0x004b6c2b`, `0x004b6c36`, and `0x004b6c50`.
- IDA MCP does not currently mark `0x004b6410`, `0x004b64a0`, `0x004b69b0`, or `0x004b6ae0` as functions, while raw disassembly shows method-shaped code starts. Treat those starts as unresolved boundary data, not as proof the code is absent.
- IDA MCP vtable inspection shows the FpsPane primary vtable at `0x0061a620`, secondary view at `0x0061a66c`, and timer/update view at `0x0061a69c`.
- 2026-05-31 IDA MCP dword scan confirms the exact FpsPane RTTI/vtable data span [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md), bounded by preceding read-only data at `0x0061a618` and FPS diagnostic string data at `0x0061a6a4`.
- 2026-05-26 IDA MCP layout follow-up confirms `UpdateStatistics` is subobject-relative to the `+0xa4` timer/update view; normalized owner offsets now line up with `OnPaint` and the raw logging helpers.
- IDA MCP xrefs to `g_fpsDebugActive` and `g_fpsLogEnabled` all land inside the FPS diagnostics neighborhood, including `0x004b64a0` and the raw helper tails.
- `UpdateStatistics` calls [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) at `0x00532670`, `0x005326d0`, and `0x00532610` only to read counts for diagnostics; `MapPaneSpatialIndex` is only a retained generated alias for that ObjectList surface.
- 2026-05-26 IDA MCP reconfirmed `0x004b6c2b` and `0x004b6c36` as 0xb-byte vtable-only adjustor thunks with data refs from `0x0061a66c` and `0x0061a69c`; keep them out of handwritten source reconstruction.

## Remaining Source-Quality Caps

- Raw starts `0x004b6410`, `0x004b64a0`, `0x004b69b0`, and `0x004b6ae0` still have no modeled function objects, direct callers, xrefs, or literal pointers; this caps final-audit score.
- The best current inference for `0x004b69b0` and `0x004b6ae0` is retained private helpers or old helper implementations duplicated/inlined into `UpdateFpsLogSession`; no stronger live call path is currently proven.
- Final inherited Pane/timer method names remain open. The former slot-name cap is closed: `dword_69B37C` is independent `g_pIMEPaneLayer`, while its use here remains incidental.

## Cross-References

- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md)
- [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md)
- [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md)
- [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md)
- [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md)
- [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md)
- [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md)
- [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md)
- [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md)
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)
- [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md)
- [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md)
- [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md)
- [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md)
- [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md)
- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)

## 2026-08-24 Accepted Class Reconstruction

- The complete declaration is formal H output above: direct `Pane` and `Singleton<FpsPane>` bases, virtual destructor, `OnPaint`, `OnTimer`, public session controller, private retained helpers, exact `0x170` size, and fields at owner offsets `+0xf8` through `+0x168`. `m_reservedFrameState` preserves unused `+0xfc` without claiming behavior.
- The class formal CPP owns includes and explicit `Singleton<FpsPane>` constructor/destructor specializations around `[[CHILDREN]]`. Those specializations publish and clear the sole `g_pFpsPane` cell; authored constructor/destructor bodies do not duplicate singleton lifecycle writes.
- Exact child source order is constructor, destructor, `UpdateFpsLogSession`, `OnPaint`, `OnTimer`, `StartLogSession`, and `WriteLogSummary`, followed by compiler-covered scalar/vtable/layout/data and semantic globals through the file route.
- Primary vtable slot `0x0061a664` owns `OnPaint`; tertiary slot `0x0061a6a0` owns `OnTimer`; secondary/tertiary deleting-destructor slots use compiler adjustors `0x004b6c2b` and `0x004b6c36`. The 34 vtable dwords and 12 RTTI records prove the three-view class shape and Singleton direct-base PMD `+0xf8`.
- Exact global declarations are centralized in the formal H block: `g_fpsDebugActive`, `g_fpsLogEnabled`, and `g_pFpsPane`. Definitions remain on semantic global pages, while physical children emit covered-storage comments.
- Negative evidence remains material: no original symbols or stable FpsPane UDT, no conventional inbound route to four raw starts, no use of `+0xfc`, and no `g_fpsLogEnabled` writer/config route. These facts cap scores without blocking the complete human-shaped source.
- Final metadata is completion `94`, confidence `96`, canonical owner/emitter `0000JK`, reconstructable `TRUE`.

## Changes

- 2026-08-04 B009 `g_fpsLogEnabled` support sync:
  - Score and metadata remain `87/88`, owner/emitter UID0000JK, reconstructable true, and blank class-level CPP/H.
  - Added exact loader-zero storage, four read-only gates, no-writer closure, and one-definition source placement while explicitly preventing duplicate class-owned global output.

- 2026-07-04 B006 UID00015D split/index support sync:
  - Score unchanged.
  - Updated current generated-source context from stale `source-3/simroot_v2/class_FpsPane.cpp` wording to `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`.
  - Clarified that exact children remain class-owned/source-bearing while [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) is a reviewed non-emitting split/index parent with raw-start no-route confidence caps preserved.

- 2026-06-25 B008 UpdateFpsLogSession implementation:
  - Score unchanged.
  - Updated the [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) class-row and child-gate notes to reflect target `89/89`, retained formal C++, current MCP session `80de0a67` evidence, and the no-function/no-caller/no-pointer route as a final-audit liveness cap rather than an owner/emitter or C++ blocker.

- 2026-06-23 B003 WriteLogSummary source-quality support sync:
  - Score unchanged.
  - Synchronized [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md) to the accepted current-session `80de0a67` evidence. The class row now records target `88/89`, formal `FpsPane::WriteLogSummary()` C++ retention, no function/xref/caller/pointer route, exact `0x14b` byte SHA16 `93961235a91a75d1`, four-byte pre-padding, successor thunk boundary, append-mode literal `0x0061a700` `"a"`, `sub_443990` as a formatted-output wrapper represented by `fprintf`, and no-route status as a liveness cap rather than an owner/emitter or C++ blocker.

- 2026-06-23 B002 StartLogSession source-quality support sync:
  - Score unchanged.
  - Synchronized [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md) to the renamed source-facing child [0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md). The class row now records MCP session `80de0a67` proof for the complete helper body, no-route result, duplicate `UpdateFpsLogSession` start path, exact global/string refs, and `0x004b6adc-0x004b6ae0` padding while preserving the retained-helper/no-proven-caller confidence cap.

- 2026-06-21 B012 scalar-deleting-destructor source-quality incorporation:
  - Score unchanged.
  - Added B012's local export/listing confirmation for the destructor split: [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) is the source-bearing `FpsPane::~FpsPane()` body, while [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) is class-owned generated-binary scalar deleting destructor glue. Local evidence confirms `sub_4B6470` size `0x29`, `sub_4B6C50` size `0x5f`, adjustor-thunk jumps from `0x004b6c31` and `0x004b6c3c`, primary vtable slot `0x0061a620`, singleton clears at `0x004b648a`/`0x004b6c70`, optional delete wrapper `sub_4F4AC0`, and guard-size path `0x170`.

- 2026-06-22 B013 UpdateStatistics root-report verification:
  - Score unchanged.
  - Confirmed the [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) first-draft C++ and source-quality route are already represented in the class documentation. B013 keeps the method under [UID:00005F][FpsPane](by-class/FpsPane.md), rejects stale no-code/timer-glue and non-FpsPane ownership alternatives, and treats ObjectList row-tier names, `MapRect` spelling, local timer-wrapper spelling, and unused callback payload names as confidence caps rather than blockers.

- 2026-06-20 B005 UpdateStatistics source-quality implementation:
  - Score unchanged.
  - Added the accepted [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) implementation facts: first-draft `bool FpsPane::UpdateStatistics(int, int, int)` readiness, timer-facet normalization from owner `+0xa4`, frame-count/current-FPS producer-consumer relationship with [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md), min/max/sample/total FPS field updates, MapPane/ObjectList diagnostic count accumulation, one-second timer reschedule, and rejection of no-code/timer-glue/thunk/destructor/MapPane/ObjectList/TimerHandler/ParcelPane ownership alternatives.

- 2026-06-20 B004 destructor source-quality implementation:
  - Score unchanged.
  - Updated [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) from generic non-deleting destructor wording to `FpsPane::~FpsPane()`, recorded first-draft destructor C++ readiness, and synchronized the scalar deleting destructor wrapper policy. The class now states that the ordinary destructor's source-authored work is `g_pFpsPane = 0;`, while vtable restores, the `Pane::~Pane()` tail chain, adjustor thunk routing, and optional delete handling are compiler output.

- 2026-06-19 B005 OnPaint source-quality support update:
  - Score unchanged.
  - Added the accepted [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md) implementation facts: first-draft `void FpsPane::OnPaint()` readiness, `m_frameCount +0xf8`, `m_currentFps +0x100`, UTF-16 `L"%5.1f FPS"` formatting, inherited bounds copy, bounds fill/clear through SurfaceRenderCallbackTable slot `0x0069b3fc`, two text passes at `(1,13)` color `128` and `(0,12)` color `14`, vtable-only dispatch at `0x0061a664`, and rejected non-FpsPane owners.

- 2026-06-17 B003 source-quality execution:
  - Before: `85/86` with open questions asking agents to decide whether raw helpers were dead duplicates/private methods/boundary artifacts and stale no-C++ caveat language.
  - Changed to: `87/88`; helper role is now documented as retained private helpers or old helper implementations duplicated/inlined into `UpdateFpsLogSession`, with no-proven-caller as a score cap.
  - Incorporated B003 report details: standardized source-facing field names through `+0x168`, helper names `StartLogSession`/`WriteLogSummary`, timestamp order month/day/hour/minute/second, CP949 log string roles, zero-initialized `g_pFpsPane` and `g_fpsLogEnabled`, explicit `g_fpsDebugActive = 1`, `dword_69B37C` as MainUiLayerSlots dependency, rejected ParcelPane/MapPane/ObjectList/padding/thunk alternatives, and first-draft C++ readiness for eligible child method pages.

- 2026-06-01 autogen parent attachment:
  - What existed before: the class was marked `RECONSTRUCTABLE:TRUE` but had no `AUTOGEN_PARENT_UID`.
  - Changed to: parent [UID:0000JK][FpsPane](by-file/FpsPane.md).
  - Summary/evidence: the by-file page now has a validated `ui/diagnostics/` reconstruction path, and IDA MCP recheck confirms the class-owned vtable/global/function cluster belongs to the FPS diagnostics module.

- 2026-06-10 A001 score update: existed before as `82/80`; changed to `84/86`. Summary/evidence: live IDA reconfirmed the FpsPane function/nonfunction split, singleton/vtable xrefs, vtable-only paint/statistics/adjustor reachability, scalar-delete cleanup, OnPaint rendering behavior, UpdateStatistics timer and MapPane/ObjectList counting behavior, and raw session-helper/no-xref caveats. Completion remains below the final-source gate because raw constructor/session starts and final helper names are still unresolved.
- 2026-06-11 A002 parent-gate update: existed before as `84/86`; changed to `85/86`. Summary/evidence: live IDA MCP rechecked the three-view vtable slot map, constructor/destructor/scalar-delete vtable-store triads, paint/update/scalar-delete decompilation, and `FPSDATA` string boundary, closing the specific class-level parent evidence needed by [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md). Raw constructor/session helper caveats remain open, so confidence and completion stay well below final-audit levels.
- 2026-06-13 A001 method-child parent note: score remained `85/86`; added the `UpdateFpsLogSession` direct-child gate note. Summary/evidence: live IDA MCP reconfirmed the raw method-shaped body at `0x004b64a0-0x004b67a7`, exact boundaries, local logging globals/strings, and unresolved no-function/no-caller status. This supports [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) attaching to this class rather than bypassing it to the file root.
- Completion/confidence score update: existed before as `0/0`; changed to `82/80`. Summary: diagnostic overlay purpose, FPS/session methods, layout normalization, raw-start caveats, vtable addresses, global ownership, and ObjectList/MapPane consumer boundaries are documented; confidence remains limited by constructor/session boundary discrepancies. Evidence: diagnostics memory cluster `0x004b6410-0x004b6caf`, individual by-memory pages for constructor/destructor/session/paint/statistics helpers, `FpsPaneLayout`, and `FpsPane_vtables`.
- 2026-05-31: Reconstructable metadata clarified.
  - Before: `RECONSTRUCTABLE` was blank despite the class being documented as NexusTK-owned diagnostic pane source.
  - After: marked `RECONSTRUCTABLE:TRUE`; parent/code fields remain blank.
  - Summary/evidence: IDA MCP reconfirmed FpsPane vtable writes, destructor/paint/statistics/scalar-destructor functions, raw FpsPane-shaped constructor/session helper starts, and owned globals, but final source folder and raw helper treatment remain below autogen attachment confidence.
- 2026-05-31: Added exact vtable-data child [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md). Evidence: IDA MCP dword scan and vtable xrefs prove the RTTI/vtable span and adjacent string-data boundary.
