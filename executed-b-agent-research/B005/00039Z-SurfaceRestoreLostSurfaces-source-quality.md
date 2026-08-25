** TARGET-REPORT-UID:00039Z **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 00039Z **
# 00039Z SurfaceRestoreLostSurfaces Source-Quality Reanalysis

Assignment: `B005-goal2-surface-restore-lost-surfaces-source-quality-00039Z-20260619`  
Agent: B005  
Target: [UID:00039Z] `by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md`  
Required mode: report-only. No by-* documentation file and no `by-memory/-coverage-report.md` should be edited by this pass.

## Current Recommendation

The target should remain a reconstructable source-authored helper, but the direct owner/emitter should not remain [UID:0000OC][Surface](by-file/Surface.md). The best-supported source-facing method is:

```cpp
void ScreenPane::RestoreLostSurfaces();
```

Recommended target metadata:

| Metadata | Recommended value | Reason |
| --- | --- | --- |
| `COMPLETION` | `88` | Body, range, caller, DirectDraw constants, DirectDraw slots, field roles, owner/source placement, and first-draft C++ are now source-quality. |
| `CONFIDENCE` | `91` | The function body and sole caller are exact, and the DirectDraw API mapping is strong. Confidence is capped because original field spellings and the assignment site for `+0x18` are not recovered. |
| `CANONICAL_OWNER` | `0000CB` | The receiver is the `ScreenPane` object stored in `g_pScreenPane`, and the method restores ScreenPane/GrafPort-held surface fields. |
| `RECONSTRUCTABLE` | `TRUE` | Single modeled method, exact body, no jump table, no raw-entry liveness problem, no unresolved helper callees except typed COM vtable calls. |
| `EMITTER_UIDS` | `0000CB` | Emit as a `ScreenPane` class method, with source route through [UID:0000NB][ScreenPane](by-file/ScreenPane.md), `NexusTK/ui/core/ScreenPane.cpp`. |

The current filename can remain `0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md` to avoid link churn, but the target title/status should name the source-facing method as `ScreenPane::RestoreLostSurfaces`. The coverage row below keeps the existing path.

## Exact Evidence Checked

Project documentation checked:

- Target [UID:00039Z] `by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md`.
- Aggregate [UID:0001G6] `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`.
- Class owner candidate [UID:0000CB] `by-class/ScreenPane.md`.
- Source route candidate [UID:0000NB] `by-file/ScreenPane.md`.
- Current owner candidate [UID:0000OC] `by-file/Surface.md`.
- Singleton context [UID:0000S7] `by-global/g_pScreenPane.md`, as referenced by the ScreenPane class/file docs.
- Adjacent helper docs [UID:00039Y] `0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md` and [UID:0003A0] `0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md`.

IDA-exported function records checked from `source-3/core/data/readonly/prewave/exported-functions/`:

- `0x00559170.json`: exact target body, size, generated names, xref count, caller address, Ghidra and IDA decompilation.
- `0x00465f20.json`: caller body; Ghidra-assisted name `Main_WndProc`; switch case `7` calls the target through `DAT_0067a7cc`.
- `0x00556910.json`: `ScreenPane::ScreenPane`; initializes `g_pScreenPane`, `+0x18`, `+0x100`, and `+0x108`.
- `0x00556a60.json`: `ScreenPane::~ScreenPane`; releases `+0x108`, `+0x18`, and `+0x100`.
- `0x00558840.json`: surface/minimap initializer; creates/aliases `+0x100` and creates `+0x108`.
- `0x005595d0.json`: display blit helper; uses `+0x100` as the display/presentation DirectDraw destination and restores it on `DDERR_SURFACELOST`.

Rule 26 handling: no valid detail from the reanalysis is intentionally dropped. Evidence from recovered wave2/simroot source was not used as authority.

## Range And Split Decision

| Range | Decision | Evidence |
| --- | --- | --- |
| `0x00559170-0x005591fc` | Keep as one modeled method. | `0x00559170.json` reports IDA and Ghidra size `140` bytes (`0x8c`), no thunk status, one function start, and one logical body. |
| `0x005591fc-0x00559200` | Keep as padding. | Current target and aggregate both record this as padding before the next child at `0x00559200`. |
| `0x0055916b-0x00559170` | Remains preceding padding owned by adjacent inventory, not this target. | [UID:00039Y] ends at `0x0055916b`; aggregate padding inventory already preserves this gap. |
| `0x00559200-0x00559359` | Do not merge with this target. | The next helper is the ScreenPane presentation-transition cluster [UID:0003A0], semantically separate from lost-surface restoration and separated by padding. |

There is no key-handler jump table or internal switch in this target. The only branch structure is three DirectDraw-surface restore checks and two bounded retry loops.

## Body Semantics

IDA decompilation of `sub_559170`:

- Loads `this[6]`, byte offset `+0x18`.
- If the pointer is non-null and vtable slot `+0x60` returns `-2005532222`, it calls vtable slot `+0x6c` once.
- Loads `this[64]`, byte offset `+0x100`.
- If the pointer is non-null and vtable slot `+0x60` returns any negative HRESULT, it repeatedly calls slot `+0x6c` until success or until `10000` failed attempts. If all attempts fail, the helper returns immediately and skips `+0x108`.
- Loads `this[66]`, byte offset `+0x108`.
- If the pointer is non-null and vtable slot `+0x60` returns any negative HRESULT, it calls slot `+0x6c` up to `10000` times and stops on success. If it never succeeds, the helper simply falls through to return.

The exact constant mapping is:

| Raw value | Hex | Best source name | Evidence |
| --- | --- | --- | --- |
| `-2005532222` | `0x887601C2` | `DDERR_SURFACELOST` | Same HRESULT is used in the display blit helper when DirectDraw `Blt` / `BltFast` reports a lost surface before `Restore`. |
| `10000` | `0x2710` | `kRestoreLostSurfaceMaxAttempts` or local literal | Exact retry cap in both retry loops. |

The exact DirectDraw vtable slot mapping is:

| Slot | Decimal | Best source method | Evidence |
| --- | --- | --- | --- |
| `+0x60` | `96` | `IDirectDrawSurface::IsLost()` | The result is compared with `DDERR_SURFACELOST` or `< 0`; this matches DirectDraw lost-surface status checking. |
| `+0x6c` | `108` | `IDirectDrawSurface::Restore()` | Called only after lost/failed state and after `DDERR_SURFACELOST` in neighboring blit code; this matches DirectDraw surface restore. |

No direct static callees are listed because these are COM vtable calls. Treating them as unknown internal helpers would be incorrect.

## Caller And Reachability

The target has one direct code caller:

| Caller | Location | Reachability meaning |
| --- | --- | --- |
| `0x0046602e` | inside `0x00465f20`, Ghidra-assisted `Main_WndProc` | Windows message `7` (`WM_SETFOCUS`) focus-gain path checks `g_pScreenPane` and calls the target on that object. |

Caller detail from `0x00465f20.json`:

- The function is named `Main_WndProc` by ghidrassist and is the application window procedure.
- In `case 7`, it first calls `0x004a8b20` if `DAT_0067a754` is non-null.
- It then checks `DAT_0067a7cc`; if null, it returns `0`.
- If non-null, it calls `cls_0x557380::meth_0x559170(DAT_0067a7cc)`.
- `DAT_0067a7cc` is the same root singleton documented as [UID:0000S7] `g_pScreenPane`, published by `ScreenPane::ScreenPane` and cleared by `ScreenPane::~ScreenPane`.

This is not a dead retained helper and not a raw no-xref island. The runtime path is: application window gains focus -> main window procedure -> root `ScreenPane` singleton -> restore lost DirectDraw surfaces.

## Field And Type Map

| Offset | Raw references | Recommended source-facing name | Type | Evidence and caveat |
| --- | --- | --- | --- | --- |
| `+0x18` | `this[6]`, `this->mbr_0x18`, `(this->Pane).GrafPort.mbr_0x18` | `m_grafPortSurface` or, if placed in the inherited subobject, `GrafPort::m_directDrawSurface` | `IDirectDrawSurface *` / project typedef `LPDIRECTDRAWSURFACE` | Constructor zeros it, destructor releases it, target calls `IsLost`/`Restore`, and existing GrafPort/Surface docs associate `+0x18` with the GrafPort backing surface. Exact assignment site was not found in the checked bodies, so spelling is inferred. |
| `+0x100` | `this[64]`, `this->mbr_0x100` | `m_primarySurface` | `IDirectDrawSurface *` | Constructor zeros it, destructor releases it, minimap/surface initializer copies the `DDSCAPS_PRIMARYSURFACE` create result at `+0xfc` into `+0x100`, display blit uses it as the destination/display surface, and this target restores it with a retry loop. Alternate acceptable spelling: `m_displaySurface`. |
| `+0x104` | `this[65]`, used by `0x00558840` and `0x005595d0` | `m_offscreenSurface` / `m_backBufferSurface` candidate | `IDirectDrawSurface *` | Not directly used by this target, but used as a source surface in the display blit path and created by the initializer. Include only as supporting context when documenting `+0x100`. |
| `+0x108` | `this[66]`, `this->mbr_0x108` | `m_renderSurface` | `IDirectDrawSurface *` | Constructor zeros it, destructor releases it, minimap/surface initializer creates it first using full screen dimensions and later locks/unlocks it, target restores it with a bounded retry loop. Alternate acceptable spelling: `m_backBufferSurface`. |
| `+0xfc` | `this[63]`, `this->mbr_0xfc` | `m_primarySurfaceCreateResult` / temporary retained primary pointer | `IDirectDrawSurface *` | Initializer creates a `DDSCAPS_PRIMARYSURFACE` surface into this slot and copies it to `+0x100`. This is supporting evidence, not a field directly read by the target. |

The final header can use `IDirectDrawSurface *` or the project-local DirectDraw typedef if one is already established. The source-quality conclusion is that all three target fields are DirectDraw surface pointers owned by the root ScreenPane/GrafPort object, not globals.

## Ownership And Source Placement

Recommended direct semantic owner: [UID:0000CB][ScreenPane](by-class/ScreenPane.md).  
Recommended source route: [UID:0000NB][ScreenPane](by-file/ScreenPane.md), `NexusTK/ui/core/ScreenPane.cpp`.  
Rejected current direct owner: [UID:0000OC][Surface](by-file/Surface.md), retained only as dependency/neighborhood context.

Why ScreenPane wins:

- The target is a `__thiscall` method with a receiver, not a free function.
- The sole caller passes the root screen singleton `DAT_0067a7cc` / `g_pScreenPane`.
- The constructor and destructor that initialize/release the fields are `ScreenPane::ScreenPane` and `ScreenPane::~ScreenPane`.
- The target's fields belong to ScreenPane and its inherited GrafPort subobject: `+0x18`, `+0x100`, and `+0x108`.
- Neighboring child [UID:00039Y] has already been rerouted to ScreenPane class ownership even though it lives inside the same mixed `SurfacePresentation` aggregate. This target is another class-receiver exception inside that aggregate.

Why Surface remains relevant but not owner:

- The body is DirectDraw surface maintenance and lies in the `0x00557140-0x00559aef` presentation/surface neighborhood.
- The initializer/blit support functions in that aggregate still justify Surface as dependency context for render callback tables and presentation helpers.
- That context does not outweigh the direct class receiver, singleton caller, and ScreenPane field lifecycle evidence for this exact method.

## Relationship To Adjacent Helpers And Aggregate

- [UID:0001G6] `SurfacePresentation` remains a mixed-owner aggregate and must stay `RECONSTRUCTABLE:FALSE`. Only this child row should change owner/score.
- [UID:00039Y] before this target is ScreenPane class-owned callback/flag helper logic and ends at `0x0055916b`; `0x0055916b-0x00559170` is padding. It shares ScreenPane ownership with this target but should not merge because its semantics are timer/fade transition callbacks, not DirectDraw lost-surface restoration.
- [UID:0003A0] after this target starts at `0x00559200`; `0x005591fc-0x00559200` is padding. It shares ScreenPane transition state context but not this target's DirectDraw surface logic.
- [UID:00039W] `SurfaceMinimapRenderInitializer` is support evidence for fields `+0x100` and `+0x108`, not the owner of this restore method.
- [UID:0003A4] `BlitSurfaceToDisplay` is support evidence for `+0x100` and `DDERR_SURFACELOST` restore behavior, not the owner of this method.

## Heuristic / Inference Reanalysis And Validation

### Generated Names And Placeholders

| Generated / unclear name | Best-supported replacement | Validation |
| --- | --- | --- |
| `sub_559170` | `ScreenPane::RestoreLostSurfaces` | IDA name for the exact target; body restores lost DirectDraw surfaces for the root screen object. |
| `meth_0x559170` | `ScreenPane::RestoreLostSurfaces` | Ghidra/OOAnalyzer method placeholder; caller passes `DAT_0067a7cc` / `g_pScreenPane`. |
| `FUN_00559170` | `ScreenPane::RestoreLostSurfaces` | Ghidra-style raw placeholder if encountered. |
| `cls_0x557380` | `ScreenPane` | Same class namespace as ScreenPane/cursor helpers; constructor/destructor docs and caller singleton tie this object to `ScreenPane`. |
| `this[6]` / `this->mbr_0x18` | `m_grafPortSurface` or `GrafPort::m_directDrawSurface` | DirectDraw `IsLost`/`Restore`/`Release` calls and inherited GrafPort field evidence. |
| `this[64]` / `this->mbr_0x100` | `m_primarySurface` | Primary/display surface creation, destructor release, blit destination use, and target retry loop. |
| `this[66]` / `this->mbr_0x108` | `m_renderSurface` | Fullscreen offscreen/render surface creation, lock/unlock use, destructor release, and target retry loop. |
| `DAT_0067a7cc` / `dword_67A7CC` | `g_pScreenPane` | ScreenPane constructor publishes it and destructor clears it; by-global page documents the singleton. |
| `-2005532222` | `DDERR_SURFACELOST` | Decimal value is `0x887601C2`; neighboring blit helper compares the same HRESULT before `Restore`. |
| vtable slot `+0x60` | `IDirectDrawSurface::IsLost` | Return value is tested for lost/negative HRESULT before restore attempts. |
| vtable slot `+0x6c` | `IDirectDrawSurface::Restore` | Called after lost/failed status and after `DDERR_SURFACELOST` in related DirectDraw helpers. |

### DirectDraw Type Inference

The best type is `IDirectDrawSurface *` / `LPDIRECTDRAWSURFACE`. The target uses only COM vtable calls, so the exact project include spelling is not recovered from this body. The slot mapping is strong enough for source-quality because:

- `+0x60` matches lost-state status behavior and is compared with `DDERR_SURFACELOST`.
- `+0x6c` is called only to recover from lost/failing states.
- Neighboring DirectDraw helpers use `Blt`, `BltFast`, `GetDC`, `ReleaseDC`, `Lock`, and `Unlock` style slots on the same field family.
- Destructor uses vtable `+0x8`, matching COM `Release`, on the same three fields.

### Field-Name Confidence

`+0x100` is the strongest field name: the initializer creates a primary surface and copies it to `+0x100`; the blit helper presents to it; the target restores it. Use `m_primarySurface` unless the established project naming prefers `m_displaySurface`.

`+0x108` is strong but not final spelling: it is a created fullscreen render surface and is locked/unlocked during render setup. Use `m_renderSurface`; `m_backBufferSurface` is an acceptable alternate if later field naming uses front/back vocabulary.

`+0x18` is type-strong but name-capped: constructor/destructor and target prove it is an owned DirectDraw surface pointer. Existing GrafPort layout evidence makes `GrafPort::m_directDrawSurface` or `m_grafPortSurface` the best name. The exact assignment site was not recovered in the checked evidence, so do not claim a more specific original member name such as `m_primarySurface` for `+0x18`.

### Ownership Validation

The previous target page accepted [UID:0000OC] Surface because the body is DirectDraw restoration and lies in the `SurfacePresentation` aggregate. That was a useful first split but it is weaker than the class-receiver evidence now checked. The direct owner should follow the receiver and field lifecycle:

- Constructor `0x00556910` initializes all three target fields on `ScreenPane`.
- Destructor `0x00556a60` releases all three target fields on `ScreenPane`.
- Caller `0x0046602e` invokes the target on `g_pScreenPane`.
- The body has no Surface global, Surface object, or render callback-table access.

Therefore the Surface owner is rejected for this exact target. Surface should keep a dependency note only.

### Caller / Reachability Validation

The helper is live and directly reached. The only xref is enough because the path is a top-level window-procedure focus event:

- `0x00465f20` is the window procedure.
- `case 7` is `WM_SETFOCUS`.
- It checks the root screen singleton and calls the method.

There is no need to preserve a retained-helper caveat for liveness. The only caveat is final method spelling.

### Open-Question Closure

| Question | Closure |
| --- | --- |
| Does owner/emitter remain [UID:0000OC] Surface? | No. Reroute to [UID:0000CB] `ScreenPane`, emitted through [UID:0000NB] `NexusTK/ui/core/ScreenPane.cpp`. Surface remains dependency context. |
| What is the final helper name/signature? | `void ScreenPane::RestoreLostSurfaces()`. No explicit parameters and no meaningful return value. |
| What are vtable `+0x60` and `+0x6c`? | `IDirectDrawSurface::IsLost` and `IDirectDrawSurface::Restore`. |
| What is `-2005532222`? | `DDERR_SURFACELOST` / `0x887601C2`. |
| What is field `+0x18`? | DirectDraw surface pointer in the inherited GrafPort/ScreenPane backing-surface area; best name `m_grafPortSurface` or `GrafPort::m_directDrawSurface`. Exact assignment site not recovered in checked bodies, so keep that caveat explicit. |
| What is field `+0x100`? | `m_primarySurface`, the primary/display DirectDraw surface used by blit/presentation and restored by this helper. |
| What is field `+0x108`? | `m_renderSurface`, the fullscreen render/offscreen DirectDraw surface created by the initializer and restored by this helper. |
| Should first-draft C++ be emitted now? | Yes. The function is single, exact, live, and source-shaped. Emit with field-name caveats documented. |
| Should the target split or merge with adjacent ScreenPane helpers? | No. Exact body is one method; adjacent helpers are separated by padding and different semantics. |

### Rejected Alternatives

| Alternative | Rejection reason |
| --- | --- |
| Keep [UID:0000OC] Surface as canonical owner/emitter. | Direct receiver is `g_pScreenPane`; fields are ScreenPane/GrafPort fields; constructor/destructor lifecycle is ScreenPane-owned. Surface is only neighborhood/dependency context. |
| Route to [UID:0000IW] DirectX. | DirectDraw APIs are dependencies. The method does not own the process DirectX object or DirectDraw interface lifetime. |
| Treat as a free helper `RestoreLostSurfaces(ScreenPane *)`. | Both IDA/Ghidra model the function as `__thiscall`; caller invokes it as a method on `DAT_0067a7cc`. |
| Merge into [UID:00039Y] or [UID:0003A0]. | Padding and behavior separate the methods; 00039Y is timer/fade callbacks, 0003A0 is transition state traversal, this target is DirectDraw surface restoration. |
| Name `+0x18` as another primary/display surface. | `+0x100` has much stronger primary/display evidence; `+0x18` is better treated as inherited GrafPort backing surface until an assignment site proves otherwise. |
| Leave C++ blank. | The body is exact, live, and source-shaped. Remaining uncertainty is member spelling, not control flow or ownership. |

## First-Draft C++ Recommendation

Emit first-draft C++ now. The following body preserves the exact observed behavior, including the one-shot `+0x18` restore and the early return if the `+0x100` restore never succeeds:

```cpp
namespace {
const int kRestoreLostSurfaceMaxAttempts = 10000;

bool RestoreSurfaceWithRetry(IDirectDrawSurface *surface)
{
    if (surface == 0)
        return true;

    if (surface->IsLost() >= 0)
        return true;

    for (int attempt = 0; attempt < kRestoreLostSurfaceMaxAttempts; ++attempt) {
        if (surface->Restore() >= 0)
            return true;
    }

    return false;
}
}

void ScreenPane::RestoreLostSurfaces()
{
    if (m_grafPortSurface != 0 && m_grafPortSurface->IsLost() == DDERR_SURFACELOST)
        m_grafPortSurface->Restore();

    if (!RestoreSurfaceWithRetry(m_primarySurface))
        return;

    RestoreSurfaceWithRetry(m_renderSurface);
}
```

Implementation notes:

- If the project uses `LPDIRECTDRAWSURFACE`, use that typedef instead of `IDirectDrawSurface *`.
- If final class layout keeps `+0x18` inside the inherited `GrafPort`, replace `m_grafPortSurface` with the established inherited-field spelling.
- Do not use a generic `HRESULT_FAILED` wrapper unless it preserves the exact equality check against `DDERR_SURFACELOST` for `+0x18`.
- Do not remove the early return after `m_primarySurface` fails `10000` restore attempts; the observed body skips the `+0x108` restore in that case.

## Proposed Metadata And Score

Target:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000CB`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000CB`

Support docs:

- [UID:0000CB] `by-class/ScreenPane.md`: if the full method row and field layout notes are incorporated, raising from `86/89` to `87/90` is justified.
- [UID:0000NB] `by-file/ScreenPane.md`: if the Proposed Contents row and source-route exception are incorporated, raising from `86/86` to `87/87` is justified.
- [UID:0000OC] `by-file/Surface.md`: keep `88/85`; add a dependency/reroute note without claiming this helper as Surface-owned.
- [UID:0001G6] aggregate: keep `88/90`, `RECONSTRUCTABLE:FALSE`; update only the 00039Z child row.

## Exact Target Implementation Checklist

For [UID:00039Z] `by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md`:

- Update metadata to `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000CB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CB`.
- Replace status wording with `ScreenPane::RestoreLostSurfaces`, direct semantic owner [UID:0000CB] `ScreenPane`, source route [UID:0000NB] `ScreenPane`, `NexusTK/ui/core/ScreenPane.cpp`.
- Preserve exact range: `0x00559170-0x005591fc` method body and `0x005591fc-0x00559200` padding.
- Document the sole caller: `0x0046602e` in `Main_WndProc` / `0x00465f20`, `WM_SETFOCUS` path, after checking `g_pScreenPane`.
- Document generated-name replacements: `sub_559170`, `meth_0x559170`, and raw `FUN_00559170` become `ScreenPane::RestoreLostSurfaces`; `cls_0x557380` becomes `ScreenPane`.
- Document DirectDraw constants and methods: `-2005532222` / `0x887601C2` as `DDERR_SURFACELOST`, slot `+0x60` as `IDirectDrawSurface::IsLost`, slot `+0x6c` as `IDirectDrawSurface::Restore`, retry cap `10000`.
- Add a field-state table for `+0x18`, `+0x100`, `+0x108`, and supporting `+0xfc/+0x104` context.
- Add body behavior including the one-shot `+0x18` restore, `+0x100` retry loop with early return on timeout, and `+0x108` retry loop with fallthrough on timeout.
- Add rejected alternatives: Surface owner, DirectX owner, free helper, adjacent-helper merge, over-specific `+0x18` primary-surface name.
- Add the first-draft C++ body above or an equivalent source-shaped implementation preserving exact behavior.
- Add a Changes entry referencing this report: `tools/leaser/Agents/Agent-B005/research/00039Z-SurfaceRestoreLostSurfaces-source-quality.md`.

## Exact Support-Doc Implementation Checklist

Required support docs for an accepted implementation:

- `by-class/ScreenPane.md`
  - Add a Method Notes row for [UID:00039Z] `0x00559170-0x005591fc` as `ScreenPane::RestoreLostSurfaces`.
  - Add layout notes for `+0x18` inherited GrafPort/ScreenPane backing surface, `+0x100` `m_primarySurface`, and `+0x108` `m_renderSurface`.
  - Cross-link [UID:00039Z].
  - Raise class score only if the report-level method and field details are incorporated.

- `by-file/ScreenPane.md`
  - Add [UID:00039Z] to Proposed Contents as a ScreenPane class-owned helper emitted through `NexusTK/ui/core/ScreenPane.cpp`.
  - Document this as a class-owner reroute from the generic SurfacePresentation surface bucket.
  - Preserve the `NexusTK/ui/core/` path.

- `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`
  - Update the child row for [UID:00039Z] from [UID:0000OC] Surface `85/87` to [UID:0000CB] ScreenPane class `88/91`.
  - Note that the helper is a live `ScreenPane::RestoreLostSurfaces` method reached from the `WM_SETFOCUS` path.
  - Keep the master page `RECONSTRUCTABLE:FALSE` and owner blank.

- `by-file/Surface.md`
  - Add a dependency/reroute note explaining that [UID:00039Z] remains in the surface/presentation neighborhood and uses DirectDraw surfaces, but direct owner/emitter is ScreenPane because the receiver and fields are ScreenPane/GrafPort-owned.
  - Do not add 00039Z as a Surface Proposed Contents owner row.
  - No score change required.

Strongly recommended support sync:

- `by-memory/0x00556910-0x00557132.ScreenPane.md`
  - Add constructor/destructor field lifecycle notes for `+0x18`, `+0x100`, and `+0x108`, and cross-link [UID:00039Z].

- `by-global/g_pScreenPane.md`
  - Add the `WM_SETFOCUS` / `Main_WndProc` restore-lost-surfaces consumer path.

- `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`
  - Sync naming for `+0x100` and `+0x108` if the current page still has raw `this[64]` / `this[66]` wording.

- `by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md`
  - Sync `+0x100` as the display/primary surface and retain the `DDERR_SURFACELOST` restore evidence.

- `by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md`
  - Sync `+0x100` naming only if current wording still uses raw offset names.

No required support edit:

- `by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md`
  - This target is adjacent and ScreenPane-owned but uses transition state, not DirectDraw lost-surface restore state. No naming dependency requires an edit unless adding a neighbor cross-link.

## Exact Supervisor-Owned Coverage Row

Do not edit `by-memory/-coverage-report.md` during report-only work. If the implementation is accepted, the supervisor-owned row should be:

```text
        - [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md) 0x00559170-0x005591fc | method | SurfaceRestoreLostSurfaces : reconstructable : 88% : very-strong : B005 2026-06-19 source-quality reanalysis reroutes direct owner/emitter from [UID:0000OC][Surface](by-file/Surface.md) to [UID:0000CB][ScreenPane](by-class/ScreenPane.md) through [UID:0000NB][ScreenPane](by-file/ScreenPane.md), names `sub_559170` / `meth_0x559170` as `ScreenPane::RestoreLostSurfaces`, confirms the sole caller at `0x0046602e` in `Main_WndProc` / `WM_SETFOCUS` after `g_pScreenPane` is checked, resolves DirectDraw slot `+0x60` as `IDirectDrawSurface::IsLost` and `+0x6c` as `IDirectDrawSurface::Restore`, resolves `-2005532222` as `DDERR_SURFACELOST` (`0x887601C2`), maps ScreenPane/GrafPort surface fields `+0x18`, `+0x100`, and `+0x108`, preserves `0x005591fc-0x00559200` padding, and recommends first-draft C++ while capping confidence for final header/member spelling and the unproven `+0x18` assignment site.
```

## Scoped Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00039Z-SurfaceRestoreLostSurfaces-source-quality-removed.md](00039Z-SurfaceRestoreLostSurfaces-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result summary:

- `apply: False`; dry run only.
- `scanned markdown files: 1`.
- `ok: 1`.
- `ok 00039Z by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md UID header exists`.
- `stats_incremental_skip 00039Z project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows`.
- No target validation errors were reported.

## Report-Only Change Record

Created report:

- `tools/leaser/Agents/Agent-B005/research/00039Z-SurfaceRestoreLostSurfaces-source-quality.md`

No by-* documentation file and no `by-memory/-coverage-report.md` was edited by this report-only pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 00039Z","source_path":"executed-b-agent-research/B005/00039Z-SurfaceRestoreLostSurfaces-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
