** TARGET-REPORT-UID:0003A2 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003A2 **
# B007 source-quality report: [UID:0003A2] ScreenPanePaletteVisibleTilesRedrawRaw

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0003A2-ScreenPanePaletteVisibleTilesRedrawRaw-source-quality.md`

Target path: `source-3/project-documentation/by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md`

Assignment: B-agent report-only source-quality / heuristic pass. I did not edit the target by-memory page, support by-* pages, generated files, or `by-memory/-coverage-report.md`.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003A2] as source-authored, reconstructable, and emitting through [UID:0000NB] `ScreenPane.cpp`, but rename/reframe the source-facing role as a file-static ScreenPane palette refresh bridge rather than leaving the raw page name as the source name.
- Final disposition: source-bearing code, not no-code compiler glue, not generated binary data, and not a MapPane or PaletteLib-owned method.
- Required action after supervisor review: update target/support docs, raise score modestly, and populate first-draft C++ if the supervisor accepts the inferred file-static helper name.
- Confidence: strong for exact bytes, behavior, dependency roles, and ScreenPane file ownership; capped below final-audit quality by no modeled IDA function object and no recovered direct caller/pointer route to the raw start.

Recommended metadata after implementation:

```text
COMPLETION:88
CONFIDENCE:88
CANONICAL_OWNER:0000NB
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NB
```

Recommended source-facing helper name:

```cpp
static void RefreshVisibleTilesForPaletteChange();
```

Acceptable alternate names:

```cpp
static void RefreshActiveMapPaneAfterPaletteReset();
static void RedrawVisibleTilesForPaletteUpdate();
```

Avoid finalizing `ScreenPanePaletteVisibleTilesRedrawRaw` as a source name. It is a useful documentation title but still carries raw-address/source-quality wording.

## Target

- Target UID: `0003A2`
- Target path: `source-3/project-documentation/by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md`
- Current score: `85/86`
- Current owner/emitter: [UID:0000NB] `ScreenPane` by-file, emitted to `auto-generated/NexusTK/ui/core/ScreenPane.cpp`
- Source queue/report state: `auto-generated/-ag-memory-coverage.md` has the item as emitting through `0000NB`; current `by-memory/-coverage-report.md` is stale for the `SurfacePresentation` split block and has no [UID:0003A2] child row.
- Current C++ state: formal `RECONSTRUCTION_CPP` block is blank and generated `ScreenPane.cpp` has an empty emitter marker for this UID.

## Executive Recommendation

This should stay a source-bearing ScreenPane file helper. The raw body is a complete helper that:

1. Reads [UID:0000RW] `g_pPaletteLib`.
2. If the palette singleton is absent, returns.
3. Sets the PaletteLib screen-palette mode/state to `1`.
4. Resets the screen palette slot/bank state through `PaletteLib` / `ScreenPanePaletteState_543D30::ResetSlots`.
5. Reads [UID:0000PR] `g_activeMapPane`.
6. If the active map pane exists and [UID:0000A2] `Pane::IsAttachedToLayer` returns true, calls [UID:0001AR] `MapPane::RedrawVisibleTiles()` and then calls the pane vtable slot at `+0x20` with `0`.
7. Reads [UID:0000R0] `g_pGeneralPurposePanel`.
8. If the general-purpose panel exists, calls [UID:00015W] `GeneralPurposePanel::DispatchActiveChildRefresh()`.
9. Restores the PaletteLib screen-palette mode/state to `0`.

The best source placement is a `static` helper in `NexusTK/ui/core/ScreenPane.cpp`. It is not a `ScreenPane` class method because the body has no receiver and uses only global state. It is not a `MapPane` method because `MapPane::RedrawVisibleTiles()` is a callee reached through `g_activeMapPane`. It is not PaletteLib-owned because PaletteLib supplies mode/reset methods and state, but this wrapper also refreshes ScreenPane/UI side effects outside the palette manager.

## Supervisor Active Recheck

The supervisor instruction asked for report-only B-agent source-quality work on:

- raw helper liveness
- final source-facing name/signature
- PaletteLib / active-pane / root-update dependency names
- MapPane versus ScreenPane ownership
- no-xref implications
- support-doc updates
- score
- exact supervisor-owned coverage row
- first-draft C++ or no-code proof

This target does not require split repair. The current exact child range is already correct and bounded by documented padding. The missing work is source-quality naming, C++ readiness, support-doc synchronization, and coverage-row repair.

## Evidence Checked

Documentation checked:

- `by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md`
- `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`
- `by-memory/0x00556910-0x00557132.ScreenPane.md`
- `by-file/ScreenPane.md`
- `by-class/ScreenPane.md`
- `by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md`
- `by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md`
- `by-class/ScreenPanePaletteState_543D30.md`
- `by-file/Palette.md`
- `by-file/PaletteLib.md`
- `by-global/g_pPaletteLib.md`
- `by-global/g_activeMapPane.md`
- `by-global/g_pGeneralPurposePanel.md`
- `by-file/GeneralPurposePanel.md`
- `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md`
- `by-memory/0x00544460-0x00545086.PaneCore.md`
- `tools/leaser/Agents/Agent-B005/research/executed/0001AR-DrawVisibleTilesHelper-source-quality.md`
- `tools/leaser/Agents/Agent-B001/research/executed/older/0001G6-SurfacePresentation.md`
- `auto-generated/-ag-memory-coverage.md`
- `by-memory/-coverage-report.md`
- `auto-generated/NexusTK/ui/core/ScreenPane.cpp`
- `source-3/simroot_v2/class_ScreenPane.cpp`

Export and binary evidence checked:

- `resources/exported_data/functions/0x00556d50.json`
- `resources/exported_data/functions/0x005051c0.json`
- `resources/exported_data/functions/0x00544c50.json`
- `resources/exported_data/functions/0x00543d30.json`
- `resources/exported_data/functions/0x00543ee0.json`
- `resources/exported_data/functions/0x004b8630.json`
- local PE bytes from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- local PE bytes from the same executable path available at `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

Current-session IDA MCP status:

- Tried `http://127.0.0.1:13337/mcp`.
- Result: `MCP_UNAVAILABLE: Unable to connect to the remote server`.
- This report therefore distinguishes current-session local PE/export checks from prior live-MCP evidence preserved in existing docs.

Current-session local raw-byte check:

- Used the documented PE image base `0x00400000` and `.text` raw-offset delta `0xC00`, consistent with previous raw-byte reports.
- Decoded local bytes for `0x005593a2-0x00559410`.
- Confirmed `0x005593a2-0x005593b0` is all `0xcc`.
- Confirmed raw body starts at `0x005593b0`.
- Confirmed body returns at `0x0055940b`.
- Confirmed `0x0055940c-0x00559410` is all `0xcc`.

## Local PE Disassembly Check

Current-session local decode of `0x005593a2-0x00559410`:

```text
0x005593a2: int3
...
0x005593af: int3
0x005593b0: push    esi
0x005593b1: mov     esi, dword ptr [0x67a7e0]
0x005593b7: test    esi, esi
0x005593b9: je      0x55940a
0x005593bb: push    edi
0x005593bc: push    1
0x005593be: mov     ecx, esi
0x005593c0: call    0x543d30
0x005593c5: mov     ecx, esi
0x005593c7: call    0x543ee0
0x005593cc: mov     edi, dword ptr [0x67a764]
0x005593d2: test    edi, edi
0x005593d4: je      0x5593f1
0x005593d6: mov     ecx, edi
0x005593d8: call    0x544c50
0x005593dd: test    al, al
0x005593df: je      0x5593f1
0x005593e1: mov     ecx, edi
0x005593e3: call    0x5051c0
0x005593e8: mov     eax, dword ptr [edi]
0x005593ea: mov     ecx, edi
0x005593ec: push    0
0x005593ee: call    dword ptr [eax + 0x20]
0x005593f1: mov     ecx, dword ptr [0x67a874]
0x005593f7: pop     edi
0x005593f8: test    ecx, ecx
0x005593fa: je      0x559401
0x005593fc: call    0x4b8630
0x00559401: push    0
0x00559403: mov     ecx, esi
0x00559405: call    0x543d30
0x0055940a: pop     esi
0x0055940b: ret
0x0055940c: int3
0x0055940d: int3
0x0055940e: int3
0x0055940f: int3
```

This confirms the target's current range and rejects a split, merge, or no-code/padding interpretation.

## Heuristic / Inference Reanalysis And Validation

### 1. Raw helper liveness

Facts:

- IDA does not model `0x005593b0` as a function object in the existing target/support docs.
- Prior B001 live reference scans found zero direct callers, zero absolute pointers, and zero direct rel32 call/jump encodings targeting `0x005593b0`.
- Current local PE decode proves a complete body bounded by `0xcc` padding.
- Current export evidence for callees records raw xrefs from inside this body:
  - `0x005593d8 -> 0x00544c50`
  - `0x005593e3 -> 0x005051c0`
  - `0x005593fc -> 0x004b8630`
  - `0x005593c0` and `0x00559405 -> 0x00543d30`
  - `0x005593c7 -> 0x00543ee0`

Best inference:

```text
Retained source-authored file-static ScreenPane helper with unresolved direct caller route.
```

This is stronger than "dead code" because the body is source-shaped and duplicates the modeled `ScreenPane::HandleMessage` palette refresh branch. It is weaker than ordinary modeled liveness because no caller or pointer route to the raw start is currently recovered.

Score impact:

- Keep confidence below `90` until a direct caller, callback table, EH route, or compiler-retained static helper explanation is found.
- Do not classify as ignored/no-code. The body is handwritten UI/palette/map-refresh logic.

### 2. Final source-facing name/signature

Facts:

- The raw body has no stack arguments and no `this` receiver.
- It reads only globals and calls other methods.
- It returns with plain `ret`, and no caller proves a meaningful return value.
- It mirrors the `ScreenPane::HandleMessage` branch for message `1`, but without the application/screen-field gating and timer scheduling in the enclosing method.

Best source signature:

```cpp
static void RefreshVisibleTilesForPaletteChange();
```

Why this name:

- "Refresh" covers both redraw and invalidation/active-child refresh.
- "VisibleTiles" preserves the central MapPane redraw side effect.
- "PaletteChange" covers why PaletteLib mode is set and restored around the redraw.
- File-static `void` matches the no-args/no-receiver/no-meaningful-return body.

Rejected names:

- `ScreenPanePaletteVisibleTilesRedrawRaw`: descriptive page label only; not human source style.
- `MapPane::RedrawVisibleTiles`: already belongs to [UID:0001AR].
- `PaletteLib::ResetSlots`: already belongs to the PaletteLib facet at `0x00543ee0`.
- `DispatchRootUpdate`: stale and too vague; the `0x004b8630` dependency is now resolved as `GeneralPurposePanel::DispatchActiveChildRefresh`.
- `ScreenPane::RefreshVisibleTilesForPaletteChange`: possible but weaker than file-static because no `this` is passed.

### 3. PaletteLib dependency names

Facts:

- `0x005593b1` loads `dword_67A7E0`, documented as [UID:0000RW] `g_pPaletteLib`.
- `0x005593c0` calls [UID:0001E8] `0x00543d30`, a simple setter writing object offset `+0x04`.
- `0x005593c7` calls [UID:0001E8] `0x00543ee0`, the reset routine that resets slot states and reapplies one of the two 25-entry banks.
- `0x00559405` calls the same setter with `0`.
- `PaletteLib::PaletteLib` initializes the fields consumed by these methods, and `Palette.md` treats this as a PaletteLib-resident screen-palette facet.

Best source-facing names for use in this target:

```cpp
g_pPaletteLib
PaletteLib::SetScreenPaletteMode(int mode)       // descriptive, inferred
PaletteLib::ResetScreenPaletteSlots()            // descriptive, inferred
```

Safer documentation wording:

```text
PaletteLib screen-palette mode setter at `0x00543d30` and PaletteLib screen-palette slot reset at `0x00543ee0`.
```

Do not assign this raw wrapper to PaletteLib. PaletteLib owns the callee methods and state, but the wrapper coordinates ScreenPane/UI/map repaint work.

### 4. Active-pane / MapPane dependency names

Facts:

- `0x005593cc` loads [UID:0000PR] `g_activeMapPane` from `dword_67A764`.
- `0x005593d8` calls `0x00544c50`.
- `PaneCore.md` documents `0x00544c50-0x00544c66` as `Pane::IsAttachedToLayer`, which reads `Layer*` at `+0xa8` and asks the layer whether this pane is present.
- `0x005593e3` calls [UID:0001AR] `MapPane::RedrawVisibleTiles()`.
- `0x005593ee` calls the active map pane's vtable slot `+0x20` with argument `0`; Pane docs identify slot `+0x20` as the invalidate/refresh-style virtual.

Best documentation wording:

```text
If `g_activeMapPane` is non-null and still attached to its layer, the helper calls `MapPane::RedrawVisibleTiles()` and then invalidates/refreshes that pane through the inherited vtable slot `+0x20` with a null/full redraw argument.
```

Rejected owner alternative:

- MapPane owns the tile redraw callee, not this wrapper. This wrapper reads the active MapPane singleton as a dependency and also touches PaletteLib and GeneralPurposePanel state.

### 5. Root-update / GeneralPurposePanel dependency names

Facts:

- The target's older wording calls `0x004b8630` a root update helper.
- Current docs resolve `dword_67A874` as [UID:0000R0] `g_pGeneralPurposePanel`.
- [UID:00015W] documents `0x004b8630-0x004b8643` as `GeneralPurposePanel::DispatchActiveChildRefresh`.
- Export evidence shows xrefs to `0x004b8630` from `0x00556e06` inside `ScreenPane::HandleMessage` and `0x005593fc` inside this raw helper.
- The helper dispatches the active child pane's vtable slot `+0x20` with argument `0` when the active child index is not `-1`.

Best source-facing dependency name:

```cpp
g_pGeneralPurposePanel->DispatchActiveChildRefresh();
```

Support-doc correction:

```text
Replace "root update helper" for `0x004b8630` with "GeneralPurposePanel active-child refresh dispatcher" unless the surrounding context truly means the root screen layer list.
```

### 6. MapPane versus ScreenPane ownership

Ranked candidates:

| Candidate | Evidence for | Evidence against | Decision |
| --- | --- | --- | --- |
| [UID:0000NB] ScreenPane by-file | Same sequence exists in `ScreenPane::HandleMessage`; body coordinates screen/UI repaint side effects; no receiver means file-level helper fits better than class method; generated route already emits to `ScreenPane.cpp`. | No direct caller to raw start and no `ScreenPane *this` argument. | Accepted as file-static ScreenPane helper. |
| [UID:0000CB] ScreenPane class | Same source family and message-handler branch. | No receiver; uses only globals. | Reject as direct owner, keep as related class context. |
| [UID:00007Q] MapPane class / [UID:0000L3] MapPane file | Calls `MapPane::RedrawVisibleTiles()`. | MapPane is a callee/active receiver only; wrapper also toggles PaletteLib and dispatches GeneralPurposePanel refresh. | Reject direct ownership. |
| [UID:0000MA]/[UID:0000MB] Palette/PaletteLib | Uses `g_pPaletteLib`, mode setter, and reset. | PaletteLib is a dependency; wrapper triggers UI/map/panel repaint outside palette source responsibility. | Reject direct ownership. |
| [UID:0001G6] SurfacePresentation | Physical neighborhood parent. | Mixed non-emitting container; exact children carry real owners. | Reject as owner, keep as split source container. |
| No-owner/non-emitting | No direct xref to raw start. | Full source-authored body, exact dependencies, matching `ScreenPane::HandleMessage` branch, and valid emitter route. | Reject. |

Final owner/emitter recommendation:

```text
CANONICAL_OWNER:0000NB
EMITTER_UIDS:0000NB
```

### 7. Split/range decision

No split or merge is recommended.

Evidence:

- `0x005593a2-0x005593b0` is padding.
- `0x005593b0-0x0055940c` is one compact helper body.
- `0x0055940c-0x00559410` is padding.
- Next child starts at `0x00559410`.
- No internal alternate owner boundary exists inside the helper; PaletteLib/MapPane/GeneralPurposePanel calls are dependencies, not child ranges.

### 8. C++ readiness

This target meets the active code-entry gate:

- `RECONSTRUCTABLE:TRUE`
- nonblank `EMITTER_UIDS:0000NB`
- `(85 + 86) / 2 > 85`
- current investigation resolves helper role, dependencies, signature, and source placement well enough for a first-draft body

Recommendation:

- Populate C++ if the supervisor accepts the inferred helper name.
- Keep the score capped below `90/90` because the raw start has no direct caller/pointer route.

## First-Draft C++ Recommendation

Recommended formal C++ for the target after supervisor approval:

```cpp
static void RefreshVisibleTilesForPaletteChange()
{
    PaletteLib *paletteLib = g_pPaletteLib;
    if (paletteLib == NULL)
        return;

    paletteLib->SetScreenPaletteMode(1);
    paletteLib->ResetScreenPaletteSlots();

    MapPane *mapPane = g_activeMapPane;
    if (mapPane != NULL && mapPane->IsAttachedToLayer()) {
        mapPane->RedrawVisibleTiles();
        mapPane->InvalidateRect(NULL);
    }

    if (g_pGeneralPurposePanel != NULL)
        g_pGeneralPurposePanel->DispatchActiveChildRefresh();

    paletteLib->SetScreenPaletteMode(0);
}
```

Notes for implementation:

- `SetScreenPaletteMode` and `ResetScreenPaletteSlots` are inferred/descriptive source names for `0x00543d30` and `0x00543ee0`; if the accepted PaletteLib docs keep the shorter names, use `SetMode` and `ResetSlots`.
- `InvalidateRect(NULL)` represents the vtable slot `+0x20` call with argument `0`. If the Pane source standardizes a different method name for this slot, use that final name.
- Keep this as a file-static helper in `ScreenPane.cpp`, not as a `ScreenPane` member, unless future caller evidence proves a receiver.
- This draft deliberately does not include the `ScreenPane::HandleMessage` application/screen-field gates or timer call; those are outside this raw helper range.

Exact no-code proof is not applicable. The body is source-authored game/UI logic and should not be treated as compiler-generated or non-emitting.

## Recommended Target-Page Implementation Checklist

For `by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md`:

1. Change metadata to `COMPLETION:88`, `CONFIDENCE:88`; keep owner/emitter/reconstructable unchanged.
2. Add the current-session local PE byte evidence for `0x005593a2-0x00559410`, including the exact body and padding facts.
3. Replace raw dependency language:
   - `dword_67A7E0` -> [UID:0000RW] `g_pPaletteLib`
   - `0x00543d30` -> PaletteLib screen-palette mode setter, descriptive `SetScreenPaletteMode`
   - `0x00543ee0` -> PaletteLib screen-palette slot reset, descriptive `ResetScreenPaletteSlots`
   - `dword_67A764` -> [UID:0000PR] `g_activeMapPane`
   - `0x00544c50` -> [UID:0000A2] `Pane::IsAttachedToLayer`
   - `0x005051c0` -> [UID:0001AR] `MapPane::RedrawVisibleTiles`
   - vtable `+0x20` call -> inherited pane invalidate/refresh with null/full-redraw argument
   - `dword_67A874` -> [UID:0000R0] `g_pGeneralPurposePanel`
   - `0x004b8630` -> [UID:00015W] `GeneralPurposePanel::DispatchActiveChildRefresh`
4. Add the source-facing name/signature recommendation:

```text
static void RefreshVisibleTilesForPaletteChange();
```

5. Explicitly reject MapPane and PaletteLib ownership in the target body, not only in cross references.
6. Add no-xref/liveness language:

```text
The raw start remains no-direct-xref/no-pointer in current evidence. The helper stays source-bearing because the body is complete source-authored repaint logic and duplicates the modeled `ScreenPane::HandleMessage` palette-refresh branch, but this unresolved route caps confidence below final audit.
```

7. Add the first-draft C++ block above unless the supervisor chooses to keep formal C++ blank for provisional naming. If blank is kept, add this exact blocker text:

```text
Formal C++ is deferred only because the raw start has no recovered direct caller/pointer route and the final original helper spelling is inferred. The body, signature, dependencies, and ScreenPane.cpp source placement are otherwise ready for first-draft source emission.
```

## Recommended Support-Doc Updates

### `by-file/ScreenPane.md`

Add a proposed contents row:

```text
palette visible-tile refresh helper | `0x005593b0-0x0055940c` | File-static ScreenPane.cpp helper, best named `RefreshVisibleTilesForPaletteChange`, that wraps PaletteLib screen-palette mode/reset, active `MapPane::RedrawVisibleTiles`, inherited pane invalidation, and `GeneralPurposePanel::DispatchActiveChildRefresh`.
```

Add or refine note:

```text
[UID:0003A2] is ScreenPane-file-owned wrapper logic. The `MapPane::RedrawVisibleTiles` call remains a dependency/caller context into [UID:00007Q] `MapPane`; it does not move the raw wrapper to MapPane.
```

### `by-class/ScreenPane.md`

Add method/dependency note:

```text
The raw helper [UID:0003A2] belongs to the ScreenPane source file rather than the ScreenPane class method table: it has no receiver, but duplicates the palette refresh branch in `ScreenPane::HandleMessage` and coordinates ScreenPane-side UI refresh through PaletteLib, active MapPane, and GeneralPurposePanel globals.
```

### `by-memory/0x00556910-0x00557132.ScreenPane.md`

Add cross-reference under `HandleMessage` notes:

```text
The message `1` palette refresh branch duplicates the raw file helper [UID:0003A2] `0x005593b0-0x0055940c`. Both sequences set PaletteLib screen-palette mode to `1`, reset palette slots, refresh `g_activeMapPane` when attached, dispatch `g_pGeneralPurposePanel` active-child refresh, and restore mode to `0`; the modeled method also performs its own application/screen gating and timer scheduling.
```

### `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`

Update the [UID:0003A2] child row:

```text
`0x005593b0-0x0055940c` | [UID:0003A2] | [UID:0000NB] ScreenPane file | `88/88` after B007 source-quality pass | Raw no-direct-xref file-static ScreenPane helper, best named `RefreshVisibleTilesForPaletteChange`; PaletteLib, MapPane, Pane, and GeneralPurposePanel are dependencies.
```

Add evidence note:

```text
Current local PE byte decode reconfirms `0x005593a2-0x005593b0` and `0x0055940c-0x00559410` as padding around the raw helper. The helper itself loads `g_pPaletteLib`, `g_activeMapPane`, and `g_pGeneralPurposePanel`, calls PaletteLib mode/reset helpers, `Pane::IsAttachedToLayer`, `MapPane::RedrawVisibleTiles`, a pane invalidate/refresh virtual, and `GeneralPurposePanel::DispatchActiveChildRefresh`.
```

### `by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md`

This support doc is already mostly correct after B005. Optional refinement:

```text
The raw xref at `0x005593e3` is now best described as ScreenPane file-static helper [UID:0003A2] `RefreshVisibleTilesForPaletteChange`, not only as an anonymous raw bridge.
```

### `by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md`

Add current target cross-reference:

```text
Raw helper [UID:0003A2] calls this same PaletteLib screen-palette sequence outside the modeled `ScreenPane::HandleMessage` body: `SetMode(1)`, `ResetSlots()`, active pane refresh, GeneralPurposePanel active-child refresh, then `SetMode(0)`.
```

### `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md`

Current doc already records the `0x005593fc` xref. Optional wording improvement:

```text
The raw caller at `0x005593fc` is [UID:0003A2] `RefreshVisibleTilesForPaletteChange`, a ScreenPane.cpp helper that asks the general-purpose panel to refresh its active child after palette/visible-tile redraw.
```

### `by-global/g_pGeneralPurposePanel.md`

Add representative consumer:

```text
[UID:0003A2] reads this singleton at `0x005593f1` and calls `GeneralPurposePanel::DispatchActiveChildRefresh()` at `0x005593fc` after refreshing the active map pane for a palette change.
```

### `by-global/g_activeMapPane.md`

Add representative consumer:

```text
[UID:0003A2] reads `g_activeMapPane` at `0x005593cc`, checks it with `Pane::IsAttachedToLayer`, calls `MapPane::RedrawVisibleTiles()`, then invalidates/refreshes it through the inherited pane virtual slot.
```

## Exact Supervisor-Owned Coverage Row

Do not edit `by-memory/-coverage-report.md` during report-only work.

Current `by-memory/-coverage-report.md` has a stale `SurfacePresentation` block and no [UID:0003A2] child row. When the supervisor updates the coverage report, insert this exact row inside the [UID:0001G6] `SurfacePresentation` child block after the `0x005593a2-0x005593b0` padding row and before the `0x0055940c-0x00559410` padding row. If the neighboring child/padding rows are still absent in the current report, add this row as part of a full `SurfacePresentation` child-block refresh.

```text
        - [UID:0003A2][0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw](by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md) 0x005593b0-0x0055940c | raw file helper | ScreenPanePaletteVisibleTilesRedrawRaw : reconstructable : 88% : strong : B007 2026-06-19 source-quality pass keeps this as a ScreenPane.cpp file-static palette redraw bridge, best named `RefreshVisibleTilesForPaletteChange`; local PE bytes decode the full `0x005593b0-0x0055940b` body bracketed by `0xcc` padding at `0x005593a2-0x005593b0` and `0x0055940c-0x00559410`, while prior live-MCP docs report no IDA-modeled function and no direct entry/pointer xrefs. The helper loads `g_pPaletteLib`, calls PaletteLib screen-palette mode/reset helpers, validates `g_activeMapPane` with `Pane::IsAttachedToLayer`, calls `MapPane::RedrawVisibleTiles` plus inherited pane invalidate/refresh, dispatches `g_pGeneralPurposePanel` active-child refresh, restores palette mode to `0`, rejects MapPane/PaletteLib/GeneralPurposePanel as direct owners, and has first-draft C++ ready for ScreenPane.cpp.
```

Optional parent-row replacement if the supervisor refreshes the stale parent block in the same pass:

```text
    - [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) 0x00557140-0x00559aef | mixed-owner executable-neighborhood container | SurfacePresentation : ignored : 88% : strong : Reviewed mixed-owner container with exact child pages carrying source ownership; current docs split Surface, ScreenPane, ScreenshotCapture, Palette/MapPane dependency, and DirectDraw helper ranges, preserve internal `0xcc` padding, and keep the master non-emitting because no single source owner owns the whole interval.
```

Use the optional parent row only if coverage policy accepts `ignored` for this non-reconstructable mixed container. Otherwise keep the target row above and let the supervisor's coverage refresh tool decide the parent container status.

## Validation Commands Needed

After an implementation callback, run at minimum:

> Executable block R001 was removed from this report and preserved verbatim in [0003A2-ScreenPanePaletteVisibleTilesRedrawRaw-source-quality-removed.md](0003A2-ScreenPanePaletteVisibleTilesRedrawRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the coverage row:

> Executable block R002 was removed from this report and preserved verbatim in [0003A2-ScreenPanePaletteVisibleTilesRedrawRaw-source-quality-removed.md](0003A2-ScreenPanePaletteVisibleTilesRedrawRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended live IDA/MCP checks when the endpoint is available:

```text
lookup_funcs 0x005593b0 0x0055940c 0x00559410
disasm/get_bytes 0x005593a2 size covering through 0x00559410
xrefs_to 0x005593b0
xrefs_to 0x005051c0
xrefs_to 0x004b8630
xrefs_to 0x00543d30
xrefs_to 0x00543ee0
pointer/rel32 scan for 0x005593b0
decompile 0x00556d50 and compare the message 1 palette-refresh branch
```

## IDA Rename / Type / Comment Recommendations

No IDA edits were made.

If the IDA owner accepts raw-function labeling:

Suggested label:

```text
ScreenPane_RefreshVisibleTilesForPaletteChange_raw_5593B0
```

Suggested type:

```cpp
void __cdecl ScreenPane_RefreshVisibleTilesForPaletteChange_raw_5593B0(void);
```

`__stdcall` would be mechanically equivalent for a no-argument function returning with plain `ret`, but `__cdecl` is the safer neutral type unless a caller proves otherwise. Do not type it as a `ScreenPane` or `MapPane` method.

Suggested repeatable comment:

```text
Raw no-direct-xref ScreenPane.cpp helper. If g_pPaletteLib exists: set screen palette mode 1, reset palette slots, redraw/refresh g_activeMapPane if attached, dispatch g_pGeneralPurposePanel active-child refresh, then restore palette mode 0. Duplicates ScreenPane::HandleMessage palette-refresh branch but has no recovered direct caller.
```

Field/global comments:

- `dword_67A7E0`: use existing `g_pPaletteLib`.
- `dword_67A764`: use existing `g_activeMapPane`.
- `dword_67A874`: use existing `g_pGeneralPurposePanel`, not "root update".
- `0x00544c50`: `Pane::IsAttachedToLayer`.
- `0x005051c0`: `MapPane::RedrawVisibleTiles`.
- `0x004b8630`: `GeneralPurposePanel::DispatchActiveChildRefresh`.

## Open Questions And Closure

| Question | Resolution |
| --- | --- |
| Is this compiler glue/no-code? | No. Local PE bytes prove source-authored UI/palette/map refresh logic with multiple project calls. |
| Is the range correct? | Yes. Body is `0x005593b0-0x0055940c`, with padding before and after. |
| Is there a direct caller? | Not currently. Prior live-MCP scan found no caller/pointer/rel32 route; current MCP unavailable. This caps confidence but does not change source-bearing status. |
| Should it move to MapPane? | No. MapPane is the active receiver for `RedrawVisibleTiles`; the wrapper also controls PaletteLib and GeneralPurposePanel refresh. |
| Should it move to PaletteLib? | No. PaletteLib methods are callees. The wrapper performs ScreenPane/UI orchestration around them. |
| What is `dword_67A874` here? | [UID:0000R0] `g_pGeneralPurposePanel`; callee `0x004b8630` is `GeneralPurposePanel::DispatchActiveChildRefresh`. |
| What is `0x00544c50` here? | [UID:0000A2] `Pane::IsAttachedToLayer`, used to ensure `g_activeMapPane` is still attached before redraw. |
| Is first-draft C++ ready? | Yes, with inferred file-static helper and dependency names. Populate it if the supervisor accepts the provisional source spelling. |
| Should score exceed 90? | No. No direct caller/pointer route and provisional helper spelling keep this below final-audit confidence. |

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0003A2-ScreenPanePaletteVisibleTilesRedrawRaw-source-quality.md`

Modified:

- None. Report-only pass.

Moved/renamed:

- None.

## Implementation Readiness

Ready for supervisor review. The implementation callback should carry the first-draft C++ and dependency-name corrections into the target and support docs. The strongest remaining uncertainty is raw-start reachability, not behavior or ownership. It should be documented as a confidence cap rather than a blocker to source-bearing emission.

FINISHED for report-only research.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003A2","source_path":"executed-b-agent-research/B007/0003A2-ScreenPanePaletteVisibleTilesRedrawRaw-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
