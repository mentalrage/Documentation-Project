** TARGET-REPORT-UID:00015H **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00015H FpsPaneUpdateStatistics Source-Quality Research

## Final Recommendation

- Keep [UID:00015H] as source-bearing `FpsPane` project code, not generated timer glue and not a no-code page.
- Recommended source-facing name/signature: `bool FpsPane::UpdateStatistics(int, int, int)`.
- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00005F`.
- Recommended source route: direct owner [UID:00005F][FpsPane](by-class/FpsPane.md), emitted through [UID:0000JK][FpsPane](by-file/FpsPane.md) to `NexusTK/ui/diagnostics/FpsPane.cpp`.
- Formal C++ is ready for a first draft under the active combined-score/emitter gate. The old 95/95 blank-code blocker is stale and should be removed when this report is accepted for implementation.
- No by-* docs, generated files, IDA DB, project-level reports, or `by-memory/-coverage-report.md` were edited in this report-only pass.

## Target Paths

- Assignment id: `B005-goal2-fps-pane-update-statistics-source-quality-00015H-20260619`
- Target UID: [UID:00015H]
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\00015H-FpsPaneUpdateStatistics-source-quality.md`
- Current target state: `84/90`, `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005F`, blank formal C++.

## Evidence Checked

- Workflow and source-quality rules:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B005/goal.md`
- Target/support docs:
  - `by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md`
  - `by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md`
  - `by-class/FpsPane.md`
  - `by-file/FpsPane.md`
  - `by-type/by-struct/FpsPaneLayout.md`
  - `by-type/by-vtable/FpsPane_vtables.md`
  - `by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md`
  - `by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md`
  - `by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw.md`
  - `by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md`
- Dependency/support docs:
  - [UID:0000PR] `by-global/g_activeMapPane.md`
  - [UID:0001OW] `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md`
  - [UID:00007Q] `by-class/MapPane.md`
  - [UID:0000L3] `by-file/MapPane.md`
  - [UID:0001AR] `by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md`
  - [UID:0001D3] `by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md`
  - [UID:0001D2] `by-memory/0x00532530-0x0053272e.MapPaneSpatialIndex.md`
  - [UID:0001K8] `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
- Exported function data:
  - `resources/exported_data/functions/0x004b68b0.json`
  - IDA signature: `char __thiscall sub_4B68B0(int this, int, int, int)`
  - IDA size: `0x100`
  - IDA xrefs-to: data pointer from `0x0061a6a0`
  - Direct callees: `0x00505290`, `0x00532670`, `0x005326d0`, `0x00532610`, `0x005975e0`, and `0x005c772f`
- Prior report lead:
  - Existing pending `Agent-B013/research/00015H-FpsPaneUpdateStatistics-source-quality.md` was found and preserved. It was used only as a lead; this B005 report independently rechecks current docs, exported data, and local executable bytes.
- Local PE / Capstone recheck:
  - Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - Size: `2679296`
  - MD5: `4247e04e20b65d6414c7238aa8ff5515`
  - SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
  - Image base: `0x00400000`
  - Sections checked: `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, `.data 0x0066d000-0x0069ce24`, `.rsrc 0x0069d000-0x006b2e00`
  - Capstone 5.0.7 was available. `pefile` was not installed, so the PE section table was parsed directly.

## Exact Boundary And Route Evidence

- The exact half-open range remains `0x004b68b0-0x004b69b0`, size `0x100`.
- File offset for the target start in the checked PE is `0x000b5cb0` in `.text`.
- Predecessor bytes at `0x004b68a0-0x004b68b0` are:

```text
33 cd e8 88 0e 11 00 8b e5 5d c3 cc cc cc cc cc
```

  This preserves the [UID:00015G] return sequence at `0x004b68a0-0x004b68aa` and five `0xcc` alignment bytes at `0x004b68ab-0x004b68b0`.
- Successor bytes at `0x004b69b0-0x004b69d0` are:

```text
55 8b ec 51 57 8b f9 ff 15 0c d5 60 00 83 3d 90 da 66 00 00 0f 57 c0 89 87 48 01 00 00 c7 87 4c
```

  This proves there is no trailing padding after [UID:00015H]. `0x004b69b0` begins the raw start-session helper [UID:00015I], not an extension of `UpdateStatistics`.
- Local `.text` branch scan found zero direct `call`, `jmp`, conditional-branch, or short-branch refs to `0x004b68b0` and zero branch refs to the exclusive end `0x004b69b0`.
- Four-byte literal scan found exactly one absolute `0x004b68b0` pointer: `0x0061a6a0` in `.rdata`.
- No target RVA (`0x000b68b0`), target raw offset (`0x000b5cb0`), target end VA (`0x004b69b0`), target end RVA (`0x000b69b0`), or target end raw offset (`0x000b5db0`) literal hits were found.
- This matches the documented vtable/timer dispatch route: tertiary FpsPane timer/update vtable base `0x0061a69c`, slot `+0x04` at `0x0061a6a0`, value `0x004b68b0`.
- Absence of direct callers is expected. The callback is reached through the timer/update vtable facet and scheduler, not through direct `call 0x004b68b0` instructions.

## Disassembly-Level Body Evidence

Local Capstone disassembly confirms the target is a normal `__thiscall` callback body with a security-cookie prologue, three stack callback arguments popped by `ret 0x0c`, and receiver in `ECX` saved to `ESI`.

Key instruction sequence:

- `0x004b68c3`: `mov eax, dword ptr [esi + 0x54]`
  - Reads the timer-facet-relative frame count. With `FpsPane +0xa4` receiver normalization, this is owner `+0xf8` / `m_frameCount`.
- `0x004b68c6`: `mov dword ptr [esi + 0x54], 0`
  - Resets `m_frameCount` after sampling.
- `0x004b68cd-0x004b68e1`: converts the sampled count to floating point through the MSVC signed/unsigned conversion idiom with correction table `0x0060dfc0`.
- `0x004b68e5`: loads timer `+0xa8`, owner `+0x14c`, current `m_minFps`.
- `0x004b68f0`: writes the current sample to timer `+0x5c`, owner `+0x100`, `m_currentFps`.
- `0x004b68f5-0x004b68f7`: updates timer `+0xa8`, owner `+0x14c`, when the new sample is below `m_minFps`.
- `0x004b68ff-0x004b6908`: updates timer `+0xac`, owner `+0x150`, when the new sample is above `m_maxFps`.
- `0x004b6910`: increments timer `+0xb0`, owner `+0x154`, `m_sampleCount`.
- `0x004b6916-0x004b6921`: promotes the sample to double, adds it to timer `+0xb4`, owner `+0x158`, `m_totalFps`.
- `0x004b6929-0x004b6931`: loads and null-checks `dword_67A764`, best project name `g_activeMapPane`.
- `0x004b6935-0x004b6939`: passes a local four-int rectangle to `0x00505290`, best current name `MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const`.
- `0x004b693e-0x004b6946`: reloads `g_activeMapPane`, loads local `top` from `[ebp-0x10]`, and reads `MapPane +0x424` as `m_objectList`.
- `0x004b694c-0x004b6977`: loops while local `top < bottom`, where bottom is `[ebp-0x08]`.
- `0x004b6954`: calls `0x00532670`, current descriptive name `ObjectList::GetFrontRowBucket(row)`.
- `0x004b695c-0x004b695f`: reads returned list count at `+0x0c` and adds it to timer `+0xbc`, owner `+0x160`, `m_totalLivingObjects`.
- `0x004b6965`: calls `0x005326d0`, current descriptive name `ObjectList::GetBackRowBucket(row)`.
- `0x004b696b-0x004b696e`: reads returned list count at `+0x0c` and adds it to timer `+0xc4`, owner `+0x168`, `m_totalStaticObjects`.
- `0x004b697b`: calls `0x00532610`, current descriptive name `ObjectList::GetVisibleObjectList()`.
- `0x004b6982-0x004b6985`: reads returned list count at `+0x0c` and adds it to timer `+0xc0`, owner `+0x164`, `m_totalBalloonObjects`.
- `0x004b698b-0x004b6998`: pushes `(0, 0, 1000, 0)`, sets `ECX = ESI`, and calls `0x005975e0`.
- `0x004b69a0`: returns `AL = 1`.
- `0x004b69a5`: calls security-cookie check `0x005c772f`.
- `0x004b69ad`: `ret 0x0c`, confirming three explicit stack callback arguments.

Direct call list from local Capstone:

| Callsite | Target | Source-quality role |
| --- | --- | --- |
| `0x004b6939` | `0x00505290` | `MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const` |
| `0x004b6954` | `0x00532670` | `ObjectList::GetFrontRowBucket(row)` |
| `0x004b6965` | `0x005326d0` | `ObjectList::GetBackRowBucket(row)` |
| `0x004b697b` | `0x00532610` | `ObjectList::GetVisibleObjectList()` |
| `0x004b6998` | `0x005975e0` | `TimerHandler::ScheduleTimer` / local FpsPane timer start wrapper |
| `0x004b69a5` | `0x005c772f` | MSVC security-cookie check |

There are no internal switch tables, embedded data islands, thunk jumps, or destructor/delete behavior in the body.

## Heuristic / Inference Reanalysis And Validation

### Source-Bearing Versus No-Code

Best conclusion: [UID:00015H] is handwritten/source-authored `FpsPane::UpdateStatistics`, not generated-only code.

Evidence:

- Normal modeled function body at `0x004b68b0-0x004b69b0`.
- Vtable-only dispatch through `0x0061a6a0`, exactly the FpsPane timer/update vtable slot.
- `ret 0x0c` and return value `1`, matching a timer callback interface with three stack callback parameters.
- Direct FpsPane state updates after `+0xa4` receiver normalization: `m_frameCount`, `m_currentFps`, `m_minFps`, `m_maxFps`, `m_sampleCount`, `m_totalFps`, and object-count accumulators.
- Ordinary MapPane/ObjectList read-only diagnostics dependencies and generic TimerHandler reschedule dependency.
- Exact boundary split from [UID:00015G] and into raw [UID:00015I].

Rejected alternatives:

- Compiler-generated thunk: no `this` adjustment stub, no tail jump to another method, no vtable/dtor-only shape, and a full statistics body is present.
- Scalar deleting destructor: no delete flag, no vtable teardown, no base destructor call, no `operator delete`, and the function returns true through `ret 0x0c`.
- TimerHandler/TimerMgr-owned method: `0x005975e0` is only a generic scheduler callee. The target body owns FpsPane fields and should remain FpsPane-owned.
- MapPane/ObjectList owner: those classes provide read-only count and bounds data. The accumulation fields and vtable dispatch are FpsPane-owned.
- No-code/generated-vtable page: the vtable data is [UID:0002MJ] at `0x0061a61c-0x0061a6a4`; this target is executable source behavior.
- Merge with raw start-session helper: successor `0x004b69b0` begins a separate raw helper with no padding after this method; this target ends at `ret 0x0c` at `0x004b69ad`.

### Name And Signature

Recommended source-facing signature:

```cpp
bool FpsPane::UpdateStatistics(int, int, int);
```

Evidence:

- IDA records `char __thiscall sub_4B68B0(int this, int, int, int)`.
- Local disassembly ends with `mov al, 1` and `ret 0x0c`.
- The three stack arguments are unused. Leaving them unnamed in the first draft is cleaner than inventing false parameter semantics.
- The function is reached through the timer/update vtable facet at owner offset `+0xa4`, so the source-facing class method should normalize `this` back to the containing `FpsPane` and use normal fields.

Rejected signature/name alternatives:

- `bool FpsPane::UpdateStatistics()` is too weak for the binary ABI because `ret 0x0c` proves three callback arguments.
- `char sub_4B68B0(int this, int a2, int a3, int a4)` preserves IDA artifacts rather than source-facing class code.
- `FpsPane::OnTimer` is plausible as a generic timer-interface spelling, but existing target/class docs and behavior-specific source naming support `UpdateStatistics` better. `OnTimer` should remain a low-confidence naming-sweep alternate only.
- `FpsPaneUpdateStatistics` should remain the documentation slug, not the source method spelling.

### Timer-Subobject Offset Normalization

The binary receiver is the embedded timer/update facet at `FpsPane +0xa4`. All raw offsets in the body must be normalized by adding `0xa4` to recover owner fields.

| Timer-facet offset | Owner offset | Recommended field/type | Evidence |
| --- | --- | --- | --- |
| `+0x54` | `+0xf8` | `int`/`uint32_t m_frameCount` | [UID:00015G] increments owner `+0xf8`; this method reads and clears timer `+0x54` once per callback. |
| `+0x5c` | `+0x100` | `float m_currentFps` | This method writes timer `+0x5c`; [UID:00015G] reads owner `+0x100` and formats it as `L"%5.1f FPS"`. |
| `+0xa8` | `+0x14c` | `float m_minFps` | Compared against the new sample and lowered when the sample is smaller; start-session paths initialize it to `300.0f`; summary writes `minFPS`. |
| `+0xac` | `+0x150` | `float m_maxFps` | Compared against the new sample and raised when the sample is larger; start-session paths initialize it to `0.0f`; summary writes `maxFPS`. |
| `+0xb0` | `+0x154` | `int m_sampleCount` | Incremented once per statistics callback; start-session paths initialize it to `1`; summary divides accumulated totals by it. |
| `+0xb4` | `+0x158` | `double m_totalFps` | Accumulates each sample as a double; summary divides by `m_sampleCount` for average FPS. |
| `+0xbc` | `+0x160` | `int m_totalLivingObjects` | Adds count from `GetFrontRowBucket(row)` for each visible row; summary writes `aveLivingObject`. |
| `+0xc0` | `+0x164` | `int m_totalBalloonObjects` | Adds count from `GetVisibleObjectList()` once per sample; summary writes `aveBalloonObject`. |
| `+0xc4` | `+0x168` | `int m_totalStaticObjects` | Adds count from `GetBackRowBucket(row)` for each visible row; summary writes `aveStaticObject`. |

Rejected field interpretations:

- `+0xf8` as elapsed time or timer id: paint increments it once per rendered frame, and this callback samples/resets it.
- `+0x100` as average/min/max FPS: min/max and totals live at owner `+0x14c` onward; this field is the displayed current FPS value.
- `+0x160/+0x164/+0x168` as already-averaged values: the summary helper computes averages later by dividing by `m_sampleCount`. This target stores running totals.

### FPS Timing Model

This method does not call `timeGetTime`, `GetTickCount`, `GetLocalTime`, or any Win32 timing API directly.

The source timing model is:

1. [UID:00015G] `FpsPane::OnPaint` increments `m_frameCount` and displays `m_currentFps`.
2. [UID:00015H] samples `m_frameCount` once per timer callback, resets it, writes `m_currentFps`, updates min/max/sample/sum fields, then schedules another callback after 1000 ms.
3. [UID:00015F]/[UID:00015I]/[UID:00015J] handle log-session start, time stamp, elapsed tick, and summary file output.

The MSVC `cvtdq2pd` plus correction-table conversion at `0x0060dfc0` is compiler codegen for integer-to-floating conversion. It should be represented as `static_cast<float>(m_frameCount)` in source C++.

### MapPane And ObjectList Diagnostic Counts

Best current mapping:

- `dword_67A764` is [UID:0000PR] `g_activeMapPane`, not `g_activeGameServerConfig`, weather state, or a FpsPane-owned global.
- `0x00505290` is best current source name `MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const`.
- The local four-int rectangle should be represented as `MapRect` or an equivalent tile-rectangle type. Current MapPane docs identify fields as left/top/right/bottom with right/bottom loop-exclusive.
- The target uses only `top` and loop-exclusive `bottom`: local `[ebp-0x10]` becomes `row`, and local `[ebp-0x08]` is the loop bound.
- `MapPane +0x424` is `m_objectList`.
- `0x00532670` is current descriptive `ObjectList::GetFrontRowBucket(row)`.
- `0x005326d0` is current descriptive `ObjectList::GetBackRowBucket(row)`.
- `0x00532610` is current descriptive `ObjectList::GetVisibleObjectList()`.
- The returned list/count object has a count dword at `+0x0c`; first-draft C++ should express this as `GetCount()` or equivalent list-count access.

Count accumulation order:

| Source data | Accumulator | Evidence |
| --- | --- | --- |
| `GetFrontRowBucket(row)->GetCount()` | `m_totalLivingObjects` owner `+0x160` | `0x004b6954` then add to timer `+0xbc`; summary string labels this total as `aveLivingObject`. |
| `GetBackRowBucket(row)->GetCount()` | `m_totalStaticObjects` owner `+0x168` | `0x004b6965` then add to timer `+0xc4`; summary labels this total as `aveStaticObject`. |
| `GetVisibleObjectList()->GetCount()` | `m_totalBalloonObjects` owner `+0x164` | `0x004b697b` then add to timer `+0xc0`; summary labels this total as `aveBalloonObject`. |

Open source-quality caveat:

- The row-tier names `front`/`back` and object categories `living`/`static`/`balloon` are best supported by current ObjectList and FpsPane summary docs, but the exact original ObjectList method names are not symbol-proven. This is a confidence cap, not a C++ blocker, because the call targets, order, returned count field, and accumulator mapping are stable.

### Timer Reschedule Helper

The final call is:

```text
sub_5975E0(this, 0, 1000, 0, 0)
```

with `this` still pointing to the timer/update facet.

Recommended source wording:

- In dependency prose, call `0x005975e0` `TimerHandler::ScheduleTimer` or a generic timer-handler schedule wrapper, as [UID:0001K8] documents.
- In first-draft FpsPane source, `m_updateTimer.StartTimer(0, 1000, 0, 0)` is acceptable and consistent with current FpsPane sibling drafts. If later TimerHandler API cleanup standardizes on `ScheduleTimer`, only rename the wrapper call; do not change arguments or timing.

Rejected helper interpretations:

- `FittingRoomDialog::meth_0x5975e0` is stale generated owner pollution from older timer-wrapper attribution.
- The delay is `1000` ms / one second, not timer id `1000`. The first argument is event id `0`; the second is the delay/duration.
- The final two zeros are unused payload slots in this path.

### Owner / Emitter / Source Placement

Accepted:

- Direct class owner: [UID:00005F] `FpsPane`.
- Source file/emitter route: [UID:0000JK] `FpsPane`, `NexusTK/ui/diagnostics/FpsPane.cpp`.
- Method source placement: `FpsPane.cpp`, beside `OnPaint`, `UpdateFpsLogSession`, retained start/summary helpers, and FpsPane globals.

Evidence:

- Tertiary FpsPane timer/update vtable slot at `0x0061a6a0`.
- FpsPane layout normalization ties every modified statistic field to owner offsets.
- [UID:00015G] consumes `m_currentFps` and produces `m_frameCount`, proving the pair.
- File doc already assigns the diagnostics overlay/logging module to `NexusTK/ui/diagnostics/FpsPane.cpp`.

Rejected owners:

- `MapPane`: only supplies active map pointer, visible bounds, and `m_objectList` for diagnostics.
- `ObjectList` / `MapPaneSpatialIndex`: only supplies row/list count helpers.
- `TimerHandler` / `TimerMgr`: only supplies the generic scheduler wrapper.
- `MainUiGraph` / `MainUiLayerSlots`: relevant to session start/layer parentage, not this callback body.
- `ParcelPane`: stale generated metadata pollution; no state or vtable evidence ties this target to ParcelPane.
- `FpsPaneDiagnostics` aggregate page: useful inventory, but this exact method page should carry the method C++.

### Stale Generated-Name And No-Code Issues

The current target still names many dependencies only as `sub_*` and says final C++ is blank because the page is below a 95/95 threshold. Both are stale under current policy:

- Active code-entry policy allows reconstruction C++ when a page is `RECONSTRUCTABLE:TRUE`, has a valid nonblank emitter route, and clears the active combined-score gate after source-quality issues are resolved or explicitly documented.
- Current target already averages `87.0`; recommended `88/91` averages `89.5`.
- The emitter route `00015H -> 00005F -> 0000JK -> NexusTK/ui/diagnostics/FpsPane.cpp` is valid.
- Remaining exact original spellings for the callback name, `MapRect` type, ObjectList row-tier helpers, and timer wrapper are real caveats but do not block first-draft source representation.
- Replace raw/generated labels with source-facing roles while preserving exact addresses as evidence.

## First-Draft C++ Readiness

This target is ready for first-draft C++ after supervisor acceptance. The following code is intentionally source-facing rather than decompiler-shaped. Exact final type/API spelling may be adapted to accepted `MapRect`, `ObjectList`, list-count, and TimerHandler declarations, but behavior and call order should remain unchanged.

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

Implementation notes:

- If final project declarations use `ScheduleTimer` instead of `StartTimer`, rename only the final call; keep `(0, 1000, 0, 0)`.
- If MapPane later exposes `GetObjectList()` instead of direct `m_objectList`, adapt the one access site without changing ownership.
- If the list count accessor is not literally `GetCount()`, adapt the local call to the accepted list/container API. The binary reads count at returned object `+0x0c` in all three cases.
- The three callback arguments should stay unnamed unless a later TimerHandler interface pass recovers exact parameter names.

## Recommended Target Changes

Target: `by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md`

1. Update metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Replace stale blank-C++ explanation:

```text
This page clears the active combined-score/emitter reconstruction-code gate. Formal C++ should be populated as `bool FpsPane::UpdateStatistics(int,int,int)`; remaining caveats are exact original callback spelling, exact `MapRect` type spelling, final ObjectList row-tier helper names, and final TimerHandler wrapper method spelling.
```

3. Populate formal C++ with the first-draft body above.
4. Add exact local PE/Capstone evidence:
   - PE hash and image-base details.
   - Function size `0x100`.
   - Five `0xcc` bytes before the start at `0x004b68ab-0x004b68b0`.
   - No trailing padding; raw start-session helper begins at `0x004b69b0`.
   - Zero direct branch/call refs to start/end.
   - Exactly one absolute target pointer at `0x0061a6a0`.
   - No VA/RVA/raw-offset literal hits for the exclusive end.
5. Add timer-facet offset-normalization table from this report.
6. Add helper-role table for `0x00505290`, `0x00532670`, `0x005326d0`, `0x00532610`, and `0x005975e0`.
7. Add relation to [UID:00015G]:
   - `OnPaint` increments `m_frameCount` and displays `m_currentFps`.
   - `UpdateStatistics` samples/resets owner `+0xf8`, writes owner `+0x100`, updates log/session statistics, and reschedules the next one-second callback.
8. Add rejected alternatives:
   - reject no-code, compiler thunk, scalar deleting destructor, raw start-session merge, MapPane/ObjectList/TimerHandler ownership, ParcelPane ownership, and raw `sub_4B68B0` source naming.
9. Update change log with B005 source-quality pass, recommended `88/91`, local PE/Capstone recheck, helper-name cleanup, and first-draft C++ readiness.

## Recommended Support-Doc Updates

Only update support docs during an implementation callback if facts are missing or weaker than this report.

- `by-class/FpsPane.md`
  - Add or expand the `UpdateStatistics` row/note to say it is first-draft C++ ready as `bool FpsPane::UpdateStatistics(int,int,int)`.
  - Preserve the timer-facet normalization from `+0xa4` to owner fields.
  - Record `m_frameCount +0xf8`, `m_currentFps +0x100`, `m_minFps +0x14c`, `m_maxFps +0x150`, `m_sampleCount +0x154`, `m_totalFps +0x158`, `m_totalLivingObjects +0x160`, `m_totalBalloonObjects +0x164`, and `m_totalStaticObjects +0x168`.
  - Add that `OnPaint` and `UpdateStatistics` form the frame-count/current-FPS producer-consumer pair.
  - State that MapPane/ObjectList/TimerHandler are dependencies, not owners.
- `by-file/FpsPane.md`
  - State that `NexusTK/ui/diagnostics/FpsPane.cpp` should emit `FpsPane::UpdateStatistics`, not an empty marker.
  - Add dependency wording for `g_activeMapPane`, `MapPane::GetClampedVisibleTileBounds`, ObjectList row/list accessors, and `TimerHandler::ScheduleTimer`.
  - Preserve rejection of ParcelPane/MapPane/ObjectList ownership for this method.
- `by-type/by-struct/FpsPaneLayout.md`
  - Already has the key field map. If touched, add this target as concrete evidence for owner fields `+0xf8/+0x100/+0x14c..+0x168` and emphasize totals-versus-averages.
- `by-type/by-vtable/FpsPane_vtables.md` and `by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md`
  - Already document `0x0061a6a0 -> 0x004b68b0`. No required support edit unless implementation wants to mention the B005 route-negative scan.
- `by-global/g_activeMapPane.md` and `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md`
  - Already identify `dword_67A764` as `g_activeMapPane`. No required edit unless adding [UID:00015H] as another read-only consumer.
- `by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md`
  - Already resolves `0x00505290` as `MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const`; no required edit unless implementation wants to add [UID:00015H] as a concrete consumer.
- `by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md` and `by-memory/0x00532530-0x0053272e.MapPaneSpatialIndex.md`
  - Already record the FpsPane diagnostics consumer and helper names. No required edit unless implementation wants to mirror the exact accumulator mapping.
- `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
  - Already identifies the generic scheduler wrapper and broad caller fan-in. No required edit unless implementation wants to add this method as one exact `ScheduleTimer(0,1000,0,0)` consumer.

## Score And Metadata Rationale

- `COMPLETION:88`: target has exact range, padding/successor boundary, vtable-only route, no direct branch refs, body call order, normalized field map, source name/signature, helper roles, relationship to OnPaint/log-summary siblings, rejected alternatives, and first-draft C++. It stays below 90+ because exact original callback spelling, final MapRect type spelling, ObjectList row-tier helper names, and TimerHandler wrapper spelling remain inferred/descriptive.
- `CONFIDENCE:91`: local PE/Capstone evidence, exported IDA/Ghidra records, and current support docs strongly confirm the body, boundary, dispatch route, field usage, helper order, and owner. Confidence remains below final-audit levels because some helper/API names are project-normalized source-facing names rather than recovered original spellings.
- Keep `CANONICAL_OWNER:00005F`: FpsPane owns the timer/update vtable slot, statistics fields, frame-counter/current-FPS pair, and diagnostic accumulators.
- Keep `RECONSTRUCTABLE:TRUE`: this is source-authored code with a valid C++ representation.
- Keep `EMITTER_UIDS:00005F`: class emitter route reaches [UID:0000JK] `FpsPane.cpp`.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during this report-only pass. Replace the existing [UID:00015H] row with:

```markdown
        - [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) 0x004b68b0-0x004b69b0 | method | FpsPaneUpdateStatistics : reconstructable : 88% : very-strong : B005 source-quality pass keeps this as source-bearing `FpsPane::UpdateStatistics(int,int,int)` under [UID:00005F] with emitter route to [UID:0000JK]; local PE/Capstone scan over `NexusTK.exe` confirms exact `0x100` body, five leading `0xcc` bytes after [UID:00015G], no trailing padding before raw [UID:00015I] start-session helper at `0x004b69b0`, no direct branch/call refs to start or end, and the only absolute target pointer at timer/update vtable slot `0x0061a6a0`; body evidence resolves TimerHandler-facet receiver normalization from `FpsPane+0xa4`, frame counter `+0xf8` reset, current FPS `+0x100`, min/max/sample/sum fields `+0x14c/+0x150/+0x154/+0x158`, object-count totals `+0x160/+0x164/+0x168`, `g_activeMapPane`/`MapPane::GetClampedVisibleTileBounds`, ObjectList `GetFrontRowBucket`/`GetBackRowBucket`/`GetVisibleObjectList` count accumulation, generic `TimerHandler::ScheduleTimer(0,1000,0,0)` reschedule, stale 95/95 no-code wording, and first-draft C++ readiness with only final ObjectList tier names, MapRect spelling, and unused callback parameter names still descriptive.
```

Placement context: replace the current [UID:00015H] row under the FpsPane diagnostics block near `0x004b6410-0x004b6caf`, immediately after the [UID:00015G] row.

## Validator Needs

No validators were run because this was a report-only assignment and no by-* docs were edited.

Expected validation commands after an implementation callback, from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00015H-FpsPaneUpdateStatistics-source-quality-removed.md](00015H-FpsPaneUpdateStatistics-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run additional scoped validators for any optional support docs touched, especially:

> Executable block R002 was removed from this report and preserved verbatim in [00015H-FpsPaneUpdateStatistics-source-quality-removed.md](00015H-FpsPaneUpdateStatistics-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Implementation should inspect generated `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` after validation to confirm [UID:00015H] emits the first-draft body rather than an empty marker.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits were made. Recommended future IDA cleanup:

- Rename `sub_4B68B0` to `FpsPane::UpdateStatistics` or an IDA-safe equivalent such as `FpsPane_UpdateStatistics`.
- Apply type `bool __thiscall FpsPane::UpdateStatistics(FpsPane *this, int, int, int)` in source-facing notes, while preserving that the binary receiver is the timer/update subobject at `FpsPane +0xa4`.
- Add a function comment at `0x004b68b0`: "Timer/update callback; receiver is FpsPane+0xa4; normalize offsets by +0xa4."
- Add/confirm FpsPane fields:
  - `+0xf8`: `m_frameCount`, `int`/`uint32_t`.
  - `+0x100`: `m_currentFps`, `float`.
  - `+0x14c`: `m_minFps`, `float`.
  - `+0x150`: `m_maxFps`, `float`.
  - `+0x154`: `m_sampleCount`, `int`.
  - `+0x158`: `m_totalFps`, `double`.
  - `+0x160`: `m_totalLivingObjects`, `int`.
  - `+0x164`: `m_totalBalloonObjects`, `int`.
  - `+0x168`: `m_totalStaticObjects`, `int`.
- Name local stack variables:
  - `[ebp-0x14..-0x08]`: `MapRect visibleTiles`.
  - `[ebp-0x10]`: `visibleTiles.top` row start.
  - `[ebp-0x08]`: `visibleTiles.bottom` loop-exclusive row end.
- Comments:
  - `0x004b68c3`: sample one-second frame count from timer-facet `+0x54` / owner `+0xf8`.
  - `0x004b68f0`: write current displayed FPS owner `+0x100`.
  - `0x004b6939`: `g_activeMapPane->GetClampedVisibleTileBounds(&visibleTiles)`.
  - `0x004b6946`: load `g_activeMapPane->m_objectList` from `MapPane +0x424`.
  - `0x004b6954/0x004b6965/0x004b697b`: ObjectList front-row/back-row/visible-list count reads for FpsPane diagnostics.
  - `0x004b6998`: repeat timer schedule `(0, 1000, 0, 0)`.
  - `0x0061a6a0`: FpsPane timer/update vtable slot.

## Remaining Issues And Impact

- Exact original callback method spelling is not binary-proven. Impact: use `UpdateStatistics` now because target/class/file docs already align on that behavior-specific name; `OnTimer` remains a low-risk naming-sweep alternate only.
- Exact `MapRect` type spelling is not final. Impact: first-draft C++ uses `MapRect` because MapPane visible-tile docs already use that four-int left/top/right/bottom shape.
- Exact ObjectList row-tier names are descriptive. Impact: confidence stays below final audit; count order and accumulator mapping are stable enough for code entry.
- Exact TimerHandler wrapper spelling is not final. Impact: draft uses `m_updateTimer.StartTimer` for FpsPane consistency and documents generic `TimerHandler::ScheduleTimer` as the dependency role.
- A pending B013 report on the same UID exists and remains supervisor-owned. Impact: no file conflict; this B005 deliverable preserves the B005 assignment path and adds independent local PE/Capstone evidence.

FINISHED `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/00015H-FpsPaneUpdateStatistics-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00015H-FpsPaneUpdateStatistics-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"00015H"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015H-FpsPaneUpdateStatistics-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00015H-FpsPaneUpdateStatistics-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015H"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
