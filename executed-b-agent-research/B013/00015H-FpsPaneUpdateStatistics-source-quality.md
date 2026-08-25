** TARGET-REPORT-UID:00015H **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00015H FpsPaneUpdateStatistics Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00015H] as the exact source-bearing FpsPane timer/statistics callback owned by [UID:00005F][FpsPane] and emitted through [UID:00005F] to [UID:0000JK][FpsPane.cpp].
- Final disposition: source-quality fix, not a split. Replace the stale "below 95/95 no C++" rationale with the current combined-score/emitter gate and enter first-draft C++ for the statistics callback.
- Required action: update target metadata/body and formal `RECONSTRUCTION_CPP CODE`; do not edit `by-memory/-coverage-report.md` directly, but apply the replacement row in this report during supervisor-owned coverage work.
- Confidence: high for exact body, receiver adjustment, FPS field behavior, timer callback signature, owner/emitter route, and helper set; medium-high for original helper/field spelling because `ObjectList` row-tier names and callback payload names remain descriptive.

Recommended target metadata after implementation:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended formal C++ block:

```cpp
bool FpsPane::UpdateStatistics(int, int, int)
{
    const float fps = static_cast<float>(m_frameCount);
    m_frameCount = 0;
    m_currentFps = fps;

    if (fps < m_minFps)
        m_minFps = fps;

    if (m_maxFps < fps)
        m_maxFps = fps;

    ++m_sampleCount;
    m_totalFps += fps;

    if (g_activeMapPane != NULL) {
        MapRect visibleTiles;
        g_activeMapPane->GetClampedVisibleTileBounds(&visibleTiles);

        ObjectList *objectList = g_activeMapPane->m_objectList;
        for (int row = visibleTiles.top; row < visibleTiles.bottom; ++row) {
            m_totalLivingObjects += objectList->GetFrontRowBucket(row)->GetCount();
            m_totalStaticObjects += objectList->GetBackRowBucket(row)->GetCount();
        }

        m_totalBalloonObjects += objectList->GetVisibleObjectList()->GetCount();
    }

    m_updateTimer.StartTimer(0, 1000, 0, 0);
    return true;
}
```

## Supporting Research

## Target

- Target UID: `00015H`
- Target path: `source-3/project-documentation/by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/00015H-FpsPaneUpdateStatistics-source-quality.md`
- Supervisor classification: B-agent source-quality / heuristic research for `FpsPaneUpdateStatistics`
- Current scores and parent state: `84/90`, `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005F`, blank C++.
- Current generated route: `auto-generated/-ag-memory-coverage.md` lists [UID:00015H] as `emits` through `00005F` to `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`.
- Current generated source: `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` contains only an empty emitter marker for [UID:00015H].
- Current manual coverage row: `by-memory/-coverage-report.md` row near `0x004b68b0` lists `reconstructable : 84% : strong`.

## Executive Recommendation

The target should stay a `FpsPane` method page. No owner, emitter, source file, or range split change is needed. The direct semantic owner remains [UID:00005F][FpsPane], and the generated route through [UID:0000JK] `NexusTK/ui/diagnostics/FpsPane.cpp` is already valid because the class is `87/88`, the file root is `88/87`, and this target already emits through the class.

The stale blocker is the target text that leaves C++ blank because the page is below an old `95/95` reconstruction-code threshold and cites an old class score of `82/80`. Current siblings in the same FpsPane island now carry first-draft C++ at 85/85+ under the active combined-score/emitter gate. This target already has average `87.0`; recommended `88/91` gives average `89.5` and clears the active gate.

The right source shape is a timer callback named `FpsPane::UpdateStatistics(int, int, int)`. The binary receiver is the embedded `TimerHandler`/timer facet at `FpsPane + 0xa4`; source-facing code should use normalized owner fields and omit names for the three ignored callback payloads. The method samples the one-second frame count, resets it, updates current/min/max/sample/sum FPS statistics, samples active map object counts, schedules the next one-second callback, and returns `true`.

No by-* docs, generated files, coverage reports, or target files were edited in this B-agent report pass.

## Evidence Checked

Primary target evidence:

- Target page records IDA `sub_4B68B0`, exact `0x004b68b0-0x004b69b0` range, vtable/timer dispatch through `0x0061a69c + 0x04`, no direct callers, and boundary into raw `0x004b69b0` start-session helper.
- Exported function data at `resources/exported_data/functions/0x004b68b0.json` records IDA signature `char __thiscall sub_4B68B0(int this, int a2, int a3, int a4)`, raw `ret 0xc`, direct callees `sub_505290`, `sub_532670`, `sub_5326D0`, `sub_532610`, `sub_5975E0`, and `__security_check_cookie`.
- The exported disassembly shows frame counter reset at timer offset `+0x54`, current FPS write at `+0x5c`, min/max at `+0xa8/+0xac`, sample count at `+0xb0`, total FPS double at `+0xb4`, object totals at `+0xbc/+0xc0/+0xc4`, and timer reschedule through `sub_5975E0(this, 0, 1000, 0, 0)`.
- The same disassembly shows the visible-bounds loop uses the second and fourth `MapRect` fields, matching `top` and loop-exclusive `bottom`: it loads `[ebp-0x10]`, compares against `[ebp-0x08]`, and calls `sub_532670`/`sub_5326D0` once per row.

Support docs checked:

- [UID:00005F][FpsPane] and [UID:0001UO][FpsPaneLayout] normalize target offsets to owner fields: `m_frameCount +0xf8`, `m_currentFps +0x100`, `m_minFps +0x14c`, `m_maxFps +0x150`, `m_sampleCount +0x154`, `m_totalFps +0x158`, `m_totalLivingObjects +0x160`, `m_totalBalloonObjects +0x164`, and `m_totalStaticObjects +0x168`.
- [UID:00015G][FpsPaneOnPaint] increments `m_frameCount` and formats `m_currentFps` as `"%5.1f FPS"`, confirming the producer/consumer pair with this target.
- [UID:00015F][FpsPaneUpdateFpsLogSessionRaw], [UID:00015I][FpsPaneStartLogSessionRaw], and [UID:00015J][FpsPaneWriteLogSummaryRaw] confirm the session reset and summary behavior: `m_minFps = 300.0f`, `m_maxFps = 0.0f`, `m_sampleCount = 1`, zeroed object totals, and summary averages divided by `m_sampleCount`.
- [UID:0000PR][g_activeMapPane] resolves `dword_67A764` as the active `MapPane *` singleton; [UID:00007Q][MapPane] resolves `MapPane +0x424` as `m_objectList`.
- [UID:0001AR][DrawVisibleTilesHelper] and [UID:0001AP][MapPaneWeatherCoordinateObjectCore] resolve `0x00505290` as `MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const`.
- [UID:0001D3][ObjectListAccessorsAndSweeps] and [UID:0001D2][MapPaneSpatialIndex] resolve `0x00532670` as `GetFrontRowBucket`, `0x005326d0` as `GetBackRowBucket`, and `0x00532610` as `GetVisibleObjectList`, all owned by [UID:00009Q][ObjectList].
- [UID:0001K8][TimerHandlerScheduleRemoveWrappers] resolves `0x005975e0` as the generic `TimerHandler::ScheduleTimer` wrapper; FpsPane's local sibling draft currently spells the member wrapper as `m_updateTimer.StartTimer`.

Current tooling/evidence limits:

- Local IDA MCP at `http://127.0.0.1:13337/mcp` was unavailable in this pass (`Unable to connect to the remote server`). This report therefore uses the existing recorded live IDA evidence plus exported function/disassembly records already present in the workspace.
- `python tools/validator.py --mode file --file by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md --uid-only` currently returns `ok: 1` for the unmodified target.

## Source-Quality Reanalysis

### Signature and timer receiver

Best source signature: `bool FpsPane::UpdateStatistics(int, int, int)`.

Evidence:

- IDA records a `char __thiscall` return and three stack arguments, with `ret 0xc`.
- The three callback arguments are unused by the body. This matches other timer callback pages that use `bool ...::OnTimer(int timerId, int, int)` source shapes when the binary receiver is a `TimerHandler` subobject.
- The raw receiver is `FpsPane +0xa4`, so decompiler offsets are timer-facet-relative. The formal source should use owner-field names and should not preserve raw `this + 0x54` style offsets.

Rejected signature alternatives:

- `bool FpsPane::UpdateStatistics()` is too weak for the binary ABI because the function returns with `ret 0xc`.
- `char sub_4B68B0(int this, int a2, int a3, int a4)` is an IDA/decompiler signature, not source-facing class C++.
- `FpsPane::OnTimer` is plausible as a generic interface name, but the target, class, and generated route already use `UpdateStatistics`; keep the descriptive method name unless a later header/symbol pass proves otherwise.

### FPS timing and reset behavior

This method does not call `timeGetTime`, `GetTickCount`, `GetLocalTime`, or any Win32 time API directly. Its timing model is a repeated one-second scheduler callback:

- [UID:00015F] starts the session and schedules `m_updateTimer.StartTimer(0, 1000, 0, 0)`.
- [UID:00015G] increments `m_frameCount` on paint.
- [UID:00015H] samples `m_frameCount` once per callback, resets it to zero, writes `m_currentFps`, updates min/max/sample/sum fields, then schedules the next one-second callback.
- [UID:00015I]/[UID:00015J] use Win32 `timeGetTime` and `GetLocalTime` for log-session start/summary, but those APIs are not target callees.

The source draft should use `static_cast<float>(m_frameCount)` and `m_frameCount = 0`. The exported IDA/Ghidra code shows an MSVC signed-int-to-float conversion artifact through `DAT_0060dfc0`; this is compiler codegen, not a source expression to preserve.

### Object-count sampling

Best current mapping:

- `m_totalLivingObjects` at owner `+0x160` / timer `+0xbc`: adds `GetFrontRowBucket(row)->GetCount()` for each visible row.
- `m_totalBalloonObjects` at owner `+0x164` / timer `+0xc0`: adds `GetVisibleObjectList()->GetCount()` once per sample.
- `m_totalStaticObjects` at owner `+0x168` / timer `+0xc4`: adds `GetBackRowBucket(row)->GetCount()` for each visible row.

Evidence:

- IDA order is `sub_532670` -> add to `this + 0xbc`, `sub_5326D0` -> add to `this + 0xc4`, then `sub_532610` -> add to `this + 0xc0`.
- `FpsPaneWriteLogSummaryRaw` prints `aveLivingObject`, `aveBalloonObject`, and `aveStaticObject` from owner `+0x160/+0x164/+0x168`.
- `ObjectListAccessorsAndSweeps` identifies the three accessors and notes this target is a read-only diagnostics consumer.

Open source-quality caveat: `ObjectList` row-tier names (`front`, `back`, visible/global list) are accepted descriptive names, but final original object-type spellings are not proven. That should cap confidence below final audit, not block C++ entry.

### Owner, emitter, and source-file route

Accepted route:

```text
[UID:00015H] by-memory method -> [UID:00005F] FpsPane -> [UID:0000JK] FpsPane.cpp -> auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp
```

Rejected owner/source alternatives:

- `MapPane`: rejected because the target only reads `g_activeMapPane`, visible bounds, and ObjectList counts for diagnostics.
- `ObjectList` / `MapPaneSpatialIndex`: rejected because those are callee/helper providers; this target owns only FPS overlay statistics accumulation.
- `TimerMgr` / `TimerHandler`: rejected as source owner because `0x005975e0` is a generic scheduling dependency, not the target body.
- `MainUiGraph` / `MainUiLayerSlots`: rejected because they provide parent/layer context for session start only, not this callback's source body.
- raw/generated `FittingRoomDialog::meth_0x5975e0` naming from unrefined artifacts: rejected as stale generated owner pollution for the generic timer wrapper.

## Exact Recommended Doc Changes

Target header changes:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep these header fields unchanged:

```text
*** CANONICAL_OWNER:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the blank formal C++ block with the first-draft C++ shown at the top of this report.

Replace stale status bullets:

```text
- Parent attachment: attached to [UID:00005F][FpsPane](by-class/FpsPane.md); the class now clears the active gate at `87/88`, and the file route [UID:0000JK][FpsPane](by-file/FpsPane.md) clears it at `88/87`.
- Final C++ should be populated because this exact source-authored callback is reconstructable, has a nonblank emitter route, clears the active combined-score gate, and has a resolved first-draft source shape. The old 95/95 blank-code threshold is stale.
```

Add a source-quality section to the target:

```text
## 2026-06-19 B013 Source-Quality Reanalysis

B013 resolves this as the FpsPane timer/statistics callback `bool FpsPane::UpdateStatistics(int, int, int)`. The binary receiver is the `TimerHandler` facet at `FpsPane +0xa4`, so raw offsets are normalized to FpsPane owner fields. IDA/exported evidence shows `ret 0xc`, three ignored callback arguments, FPS sample/reset/min/max/sample/sum updates, and a final true return.

`dword_67A764` should be named [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md). The visible-bounds helper `sub_505290` is `MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const`. The ObjectList callees are current descriptive names `GetFrontRowBucket`, `GetBackRowBucket`, and `GetVisibleObjectList`; their row-tier semantics remain descriptive but are source-quality enough for first-draft C++.

This method does not call Win32 time APIs directly. It is driven by the one-second timer scheduled through `0x005975e0`, currently documented generically as `TimerHandler::ScheduleTimer`; the local FpsPane draft spelling remains `m_updateTimer.StartTimer(0, 1000, 0, 0)` for consistency with [UID:00015F].
```

Add/update change-history note:

```text
- 2026-06-19 B013 source-quality reanalysis:
  - Before: `84/90`, blank C++, stale `95/95` no-code rationale, and stale parent-score wording.
  - Recommended after supervisor callback: `88/91` with first-draft `bool FpsPane::UpdateStatistics(int, int, int)` C++.
  - Evidence: target/exported IDA records exact `0x004b68b0-0x004b69b0` body, `ret 0xc`, timer/update vtable-only reachability, normalized FpsPane fields, frame-counter reset/current FPS/min/max/sample/sum updates, active-map visible-bounds helper, ObjectList count accumulation into living/balloon/static totals, generic timer reschedule, and boundary into the raw start-session helper. Remaining helper/type spellings are score caps, not code-entry blockers.
```

## Exact Pending Coverage Text

Current row to replace:

```text
        - [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) 0x004b68b0-0x004b69b0 | method | FpsPaneUpdateStatistics : reconstructable : 84% : strong : Live IDA reconfirms FpsPane UpdateStatistics bounds 0x004b68b0-0x004b69b0, timer/update vtable ref 0x0061a6a0, no direct callers, normalized owner offsets +0xf8/+0x100/+0x14c..+0x168, FPS min/max/average/sample updates, MapPane/ObjectList diagnostic count reads, one-second timer reschedule, boundary into raw start-session helper, parent FpsPane class attachment, unresolved final field/declaration caveat, and final C++ remains blank.
```

Replacement row:

```text
        - [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) 0x004b68b0-0x004b69b0 | method | FpsPaneUpdateStatistics : reconstructable : 88% : very strong : Source-quality reanalysis resolves the TimerHandler-adjusted receiver at FpsPane +0xa4, source-facing `UpdateStatistics(int,int,int)` timer callback shape, one-second frame counter reset/current FPS/min/max/sample/sum updates, `g_activeMapPane`/`MapPane::GetClampedVisibleTileBounds` and ObjectList `GetFrontRowBucket`/`GetBackRowBucket`/`GetVisibleObjectList` count accumulation into living/balloon/static totals, local `m_updateTimer.StartTimer(0,1000,0,0)` / generic `TimerHandler::ScheduleTimer` reschedule, vtable-only reachability through 0x0061a6a0, boundary into raw start-session helper, and first-draft C++ readiness under the active combined-score gate; ObjectList tier names and unused callback payload names remain descriptive.
```

## Validator Needs

Current unmodified target validator baseline:

_Executable command block removed from the research report; preserved in [00015H-FpsPaneUpdateStatistics-source-quality-removed.md](00015H-FpsPaneUpdateStatistics-source-quality-removed.md)._

Observed result in this pass: `ok: 1`; generated stats were skipped because it was a dry run.

After supervisor implementation callback, validate at least:

_Executable command block removed from the research report; preserved in [00015H-FpsPaneUpdateStatistics-source-quality-removed.md](00015H-FpsPaneUpdateStatistics-source-quality-removed.md)._

If generated stats/coverage are refreshed during the callback, also check the target rows in:

```text
auto-generated/-ag-memory-coverage.md
project-level/-auto-completion-stats.md
tools/validator.ini
```

Expected stats row after applying the recommendation:

```text
| `00015H` | 88 | 91 | 89.5 | `by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md` |
```

## Open Questions / Score Caps

- Original method spelling remains inferred. `UpdateStatistics` is the best current source-facing name; `OnTimer` remains a generic timer-interface alternative but is not better supported by current docs.
- `MapRect` field names are inferred from MapPane helper docs and the loop over `top` to loop-exclusive `bottom`; final header/type recovery should confirm the exact type spelling.
- `ObjectList` row-tier names are descriptive placeholders. The count order is strong, but final semantic names for front/back/visible tiers remain an ObjectList/MapPane source-quality cap.
- `m_updateTimer.StartTimer` is retained for local FpsPane consistency, while support docs now prefer generic `TimerHandler::ScheduleTimer` for `0x005975e0`. A later consistency pass may rename FpsPane timer member calls globally.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00015H-FpsPaneUpdateStatistics-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00015H"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015H-FpsPaneUpdateStatistics-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/00015H-FpsPaneUpdateStatistics-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015H"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
