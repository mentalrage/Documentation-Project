** TARGET-REPORT-UID:0003XC **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# Agent-B005 Report: UID0003XC GrafPortEffectiveClipAndBackingRelease Source Quality


## Report Provenance

- Agent: `Agent-B005`
- Assignment: `B005-report-0003XC-GrafPortEffectiveClipAndBackingRelease-20260702`
- Target UID: `0003XC`
- Target file: `by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md`
- Report path: `tools/leaser/Agents/Agent-B005/research/0003XC-GrafPortEffectiveClipAndBackingRelease-source-quality.md`
- Workflow: project-level `ntk-b-agent-workflow`, report-only phase.
- Boundary: no target/support by-* docs, generated files, coverage/project-level files, validator state, queues, archives, or supervisor ledgers were edited.
- Lifecycle boundary: no `execute_report`, report lifecycle, registry lifecycle, manual report move, archive, or equivalent command was run.

## Target

- UID: `0003XC`.
- Target path: `by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md`.
- Tracker row/source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; assigned row is `[UID:0003XC] ... | 85/88 | 86.5 | true | 0 reports`.
- Current queue classification: by-memory not-covered reconstructable research item, new Medium report-only assignment.
- Current scores: `COMPLETION:85`, `CONFIDENCE:88`.
- Current metadata: `CANONICAL_OWNER:00005V`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005V`, blank `EMITTER_POSITION_OPTIONAL`, blank formal `RECONSTRUCTION_CPP CODE`.
- Current source route: GrafPort class owner [UID:00005V] through `NexusTK/render/GrafPort.cpp` / [UID:0000JR].

[UID:0003XC] currently covers `0x004b9770-0x004b981e` as a GrafPort-owned mixed helper page with blank formal C++.

The current page combines two different source-quality cases:

- `0x004b9770`: a raw no-function effective-clip Region helper with no direct entry route.
- `0x004b97d0`: a modeled `sub_4B97D0` release helper with six direct branch callers and clear GrafPort backing-store cleanup behavior.

The combined target should not receive one formal C++ block. The modeled release helper is C++-ready only after it is split out from the raw no-route effective-clip helper.

## Current Target State

- Header score: `COMPLETION:85`, `CONFIDENCE:88`.
- Ownership: `CANONICAL_OWNER:00005V` / `GrafPort`.
- Emission: `EMITTER_UIDS:00005V`.
- C++: blank.
- Existing summary says the raw helper is no-entry and blocks formal C++, while the release helper frees software backing storage and releases DirectDraw backing storage.
- Existing range inventory has a boundary defect: it lists raw `0x004b9770-0x004b97cd` and padding `0x004b97cd-0x004b97d0`, but current disassembly and bytes show `retn 4` at `0x004b97cc` is a three-byte instruction ending at `0x004b97cf`; the correct raw helper half-open range is `0x004b9770-0x004b97cf`, followed by one byte of `0xcc` padding at `0x004b97cf-0x004b97d0`.

## Evidence Checked

- `goal.md` in `tools/leaser/Agents/Agent-B005`.
- Project workflow reference `b-agent-research-and-implementation-workflow.md`.
- `by-structure.md` routing/owner/emitter/code-gate guidance.
- Target: `by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md`.
- Support docs: `by-class/GrafPort.md`, `by-file/GrafPort.md`, `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`, `by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md`, `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`, `by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md`, `by-memory/0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers.md`, `by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md`, `by-memory/0x00506170-0x005061d3.MapPaneDetachObjectPane.md`, `by-global/g_pDirectX.md`, `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md`, `by-memory/0x005057d0-0x005058ac.MapPaneRawObjectCleanupSweep.md`, and selected MapPane/FlyingObjectPane caller support pages.
- Prior reports used as leads after search-gating: B003 `000160-00022M-grafport-source-quality.md`, B002 MapPane teardown report, B005 `0003XE-SurfaceTileBufferBlitRaw-source-route-recheck.md`, B009 `000164-GrafPortClipRectHelper-source-quality.md`, and B011 `00042C-MapPaneRawObjectCleanupSweep-by-memory-source-quality.md`.

## IDA MCP State

IDA MCP was available. The active server was `ida-pro-mcp` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, session `supervisor_resume_20260629`. `server_health` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

One `idb_list` attempt timed out, then the corrected request succeeded. This was not repeated MCP unavailability.

## Positive Evidence Summary

- `lookup_funcs` reports no function at `0x004b9770`, a modeled `sub_4B97D0` at `0x004b97d0` size `0x4e`, no function at `0x004b981e`, and successor `sub_4B9820` at `0x004b9820`.
- `xrefs_to 0x004b97d0` reports six code refs: `0x00505876`, `0x005061b4`, `0x0050e05e`, `0x0050f1df`, `0x0050f230`, and `0x00512e81`.
- Raw PE route scan of `NexusTK.exe` also finds six branch hits to `0x004b97d0` and zero VA/RVA dword hits, matching the MCP xrefs.
- `decompile 0x004b97d0` shows a `thiscall` cleanup helper: if byte `this+0x94` and pointer `this+0x98` are set, it frees the heap buffer and clears `this+0x98`; then if `this+0x18`, `g_pDirectX`, and `g_pDirectX->m_pDirectDraw` are present, it calls vtable slot `+8` on the DirectDraw surface and clears `this+0x18`.
- GrafPort support docs identify `this+0x94` as `m_usesSoftwareBuffer`, `this+0x98` as the software buffer pointer, and `this+0x18` as the DirectDraw surface pointer.
- `by-global/g_pDirectX.md` and exact memory child `0x0067ab20-0x0067ab24.g_pDirectX.md` support `g_pDirectX->m_pDirectDraw` as the DirectDraw wrapper dependency, not GrafPort ownership.
- `MapPaneDetachObjectPane` and B002 teardown evidence name the modeled release helper as `GrafPort::ReleaseBackingStore` and reject ObjectPane-only ownership.
- `disasm 0x004b9770` shows a real source-shaped raw body using `ecx` as GrafPort receiver and `[ebp+8]` as a Region output/input object, copying `this+0x04`, intersecting with `this+0x54` when non-empty, then intersecting with the bounds rectangle at `this+0x2c`.
- `GrafPortGetClipRect` at `0x004b96c0` performs the closely related effective-clip operation and gives strong layout/name support for the raw helper's Region, clip, exposed/dirty, and surface-bounds behavior.

## Negative Evidence Summary

- No direct entry route was found for `0x004b9770`: MCP `xrefs_to` returned zero refs and the raw PE route scan found zero branch hits, zero VA dword hits, and zero RVA dword hits.
- No direct route was found to the current target end boundary `0x004b981e`: MCP and raw PE route checks found zero xrefs/hits. The boundary is a function end, not a callable symbol.
- `lookup_funcs 0x004b9770` reports `Not a function`; Hex-Rays therefore cannot provide a function prototype or original calling convention for the raw helper.
- The existing internal split is not correct: `0x004b97cc` is `retn 4` and spans through `0x004b97ce`, so the raw helper does not end at `0x004b97cd`; the one-byte alignment span is `0x004b97cf-0x004b97d0`.
- The modeled release helper should not be kept blank merely because of its raw sibling. The blank C++ rationale applies to the unsplit mixed page, not to `0x004b97d0-0x004b981e` after an exact split.
- Raw-helper sibling precedents such as `[UID:0003XB]` and `[UID:0003XE]` support GrafPort ownership for no-entry raw code, but they do not justify emitting C++ for `0x004b9770` or keeping the directly referenced release helper trapped in a no-code page.
- ObjectPane ownership is rejected for `0x004b97d0`: object-pane/MapPane callers pass object panes as GrafPort-derived receivers, but the fields cleaned are GrafPort backing fields at `+0x18`, `+0x94`, and `+0x98`; ObjectPane is a consumer/derived class context, not the source owner.
- Surface/DirectX ownership is rejected: DirectDraw surface and `g_pDirectX->m_pDirectDraw` are dependencies used by GrafPort backing-store cleanup, while GrafPort owns the retained surface pointer and software buffer state.
- No-owner/non-emitting for the modeled release helper is rejected: `0x004b97d0` is an IDA-modeled function with six direct branches and a stable GrafPort receiver layout, so it has enough route and owner proof for an emitting exact child.
- Generic child names such as `sub_4B97D0`, `Cleanup`, `FreeBuffer`, or `ReleaseSurface` are rejected because they lose the paired software-buffer plus DirectDraw-surface behavior. `ReleaseBackingStore` best captures both sides and is already supported by MapPane teardown documentation.
- Remaining uncertainty: exact original source spelling of the raw effective-clip helper and exact field/API spellings (`m_softwareBuffer`, `m_ddSurface`, `m_pDirectDraw`) are inferred from layout/support docs rather than recovered PDB/source names. This caps confidence but does not block the release helper's first-draft C++ after split.

## Heuristic / Inference Reanalysis And Validation

The current single-page no-code rationale is overbroad. The page contains one raw no-entry helper and one normal modeled helper. The correct source-quality move is to split before final C++.

The raw helper inference was validated by matching its instruction sequence against `GrafPortGetClipRect`: both start from the GrafPort exposed/dirty Region at `+0x04`, optionally intersect with clip Region `+0x54`, and incorporate surface bounds at `+0x2c`. The difference is that `GetClipRect` writes a rectangle result, while the raw helper mutates or builds a Region object passed at `[ebp+8]`. Because no caller proves how that argument is named or whether it is input/output, formal C++ for the raw helper remains blocked.

The release helper inference was validated independently from callers, layout, and decompilation. The helper is a modeled function, uses `ecx` as `this`, only touches GrafPort backing fields, calls `free` for the software path, and calls the DirectDraw surface COM `Release` slot through vtable offset `+8`. Six direct branch callers prove liveness. Cross-doc MapPane teardown evidence already uses `GrafPort::ReleaseBackingStore` and rejects an ObjectPane-only destructor-helper interpretation.

## Function / Child Inventory

| Range | Proposed disposition | Evidence |
| --- | --- | --- |
| `0x004b9768-0x004b9770` | predecessor padding | eight `0xcc` bytes before current target start |
| `0x004b9770-0x004b97cf` | new raw child `GrafPortBuildEffectiveClipRegionRaw` | no IDA function/no route; source-shaped GrafPort Region helper; includes `retn 4` at `0x004b97cc-0x004b97ce` |
| `0x004b97cf-0x004b97d0` | ignored alignment padding | one `0xcc` byte |
| `0x004b97d0-0x004b981e` | new modeled child `GrafPortReleaseBackingStore` | IDA `sub_4B97D0`, size `0x4e`, six direct branch callers, C++-ready after split |
| `0x004b981e-0x004b9820` | successor padding | two `0xcc` bytes before `sub_4B9820` |

## Direct Xref / Caller Inventory

MCP and PE route scans agree on the direct branch callers to `0x004b97d0`:

| Call site | Containing function / doc context | Interpretation |
| --- | --- | --- |
| `0x00505876` | raw MapPane object cleanup sweep `[UID:00042C]` | non-type-5 object cleanup dependency |
| `0x005061b4` | `sub_506170`, `[UID:0002QP] MapPaneDetachObjectPane` | non-static object pane backing-store release before delete |
| `0x0050e05e` | `sub_50DFA0`, MapPane/FlyingObjectPane update helper area | object/flying update cleanup or replacement path |
| `0x0050f1df` | `sub_50F130`, MapPane static-object tile-region refresh area | stale static-object/tile-region cleanup path |
| `0x0050f230` | `sub_50F130` | second cleanup path in same static-object tile refresh function |
| `0x00512e81` | `sub_512D60`, MapPane flying-object update packet handler | object replacement/update cleanup path |

These are caller evidence, not ownership evidence for MapPane. They show GrafPort-derived object panes releasing their retained render backing before removal/replacement.

## Ranked Ownership Analysis

1. [UID:00005V] `GrafPort` class / [UID:0000JR] `GrafPort.cpp`: accepted. The receiver layout, backing fields, sibling clip helpers, and class/file docs all point to GrafPort. The release helper cleans fields owned by GrafPort, and the raw helper manipulates GrafPort Regions and bounds.
2. [UID:00007Q] `MapPane`: rejected as owner. MapPane contains multiple callers and orchestrates object lifecycle, but it neither owns the GrafPort backing fields nor the effective-clip Region state.
3. ObjectPane-derived classes: rejected as owner. Object panes inherit or embed GrafPort behavior and are receivers at some call sites, but the helper operates on GrafPort base fields.
4. [UID:0000OC] `Surface`: rejected. Surface helpers start at `0x004b9820` and consume/render surfaces, but this target cleans GrafPort's retained surface pointer and software buffer.
5. [UID:0000IW]/[UID:0000QS] DirectX / `g_pDirectX`: rejected as owner. The global and wrapper provide the DirectDraw interface dependency; they do not own the GrafPort member surface pointer.
6. No-owner/non-emitting: rejected for the modeled release helper because direct route and owner proof are strong; accepted only for emission of the raw effective-clip child until a real entry route is found.

## Source Placement

Keep source placement under `NexusTK/render/GrafPort.cpp` through [UID:0000JR] `GrafPort` and [UID:00005V] `GrafPort` class documentation. Do not move either child to MapPane, ObjectPane, Surface, or DirectX. Those modules are consumers or dependencies.

## Range / Split / Padding Recommendation

Recommended implementation:

1. Convert current [UID:0003XC] page into a non-emitting split/container audit for the two exact GrafPort children.
2. Create exact child page `by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md`.
3. Create exact child page `by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md`.
4. Add or keep ignored padding coverage for `0x004b97cf-0x004b97d0` and `0x004b981e-0x004b9820` as appropriate under current project conventions.
5. Update `by-class/GrafPort.md`, `by-file/GrafPort.md`, and `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md` child inventory to reference the exact children and remove the stale implication that the release helper is blocked by raw-helper liveness.

If the supervisor declines new child creation, the fallback no-split repair is to keep [UID:0003XC] blank C++, correct the raw subrange to `0x004b9770-0x004b97cf`, document the six callers to `0x004b97d0`, and cap the combined target at `86/90`. This fallback is inferior because it leaves the modeled release helper trapped in a mixed no-code page.

## First-Draft C++ Recommendation

Do not add formal C++ to the unsplit [UID:0003XC] page. Its C++ block should stay blank if it remains a mixed container.

For new exact child `0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md`, keep `EMITTER_UIDS` blank and C++ blank. No route to the raw start has been found, and exact source API spelling/argument direction remains unproven.

For new exact child `0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md`, use this first-draft C++:

```cpp
void GrafPort::ReleaseBackingStore()
{
    if (m_usesSoftwareBuffer && m_softwareBuffer != NULL) {
        free(m_softwareBuffer);
        m_softwareBuffer = NULL;
    }

    if (m_ddSurface != NULL && g_pDirectX != NULL && g_pDirectX->m_pDirectDraw != NULL) {
        m_ddSurface->Release();
        m_ddSurface = NULL;
    }
}
```

This aligns with the recommended split and score `89/91` for the exact release-helper child. It does not apply to the raw helper or the unsplit parent.

## Score And Metadata Recommendation

Preferred split disposition:

| Page | Completion / confidence | Owner | Reconstructable | Emitter | C++ |
| --- | --- | --- | --- | --- | --- |
| current `[UID:0003XC] 0x004b9770-0x004b981e` | `86/90` | `00005V` | `FALSE` | blank | blank |
| new `0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw` | `85/89` | `00005V` | `TRUE` | blank | blank |
| new `0x004b97d0-0x004b981e.GrafPortReleaseBackingStore` | `89/91` | `00005V` | `TRUE` | `00005V` | populated with first-draft C++ above |

Rationale:

- Parent completion rises only modestly because it becomes an exact split audit rather than source-emitting code.
- Raw child remains completion-capped by no entry route, no prototype, and no original source spelling.
- Release child reaches `89/91` because it is modeled, directly referenced, owner-stable, source-placeable, and semantically clear. Confidence remains capped by exact original spelling uncertainty for member/global field names.

## Recommended Target / Support Doc Changes

- `by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md`: change to split/container wording for range `0x004b9770-0x004b981e`; correct internal raw range; list the two children; preserve evidence that raw helper is no-route and release helper is live; remove the stale combined no-code rationale as the reason for blocking the release child; set preferred metadata to `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00005V`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- Create `by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md`: range `0x004b9770-0x004b97cf`; metadata `COMPLETION:85`, `CONFIDENCE:89`, `CANONICAL_OWNER:00005V`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++; document MCP no-function/no-xref/no-PE-route evidence, effective-clip Region behavior, sibling `GetClipRect` comparison, owner reasoning, no-owner/non-emitting rejection for ownership but no-emitter/no-code proof for generation.
- Create `by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md`: range `0x004b97d0-0x004b981e`; metadata `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00005V`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005V`, blank `EMITTER_POSITION_OPTIONAL`, formal C++ populated with this report's first-draft code; document six callers, decompile/disassembly behavior, field offsets, `g_pDirectX->m_pDirectDraw` dependency, MapPane/ObjectPane consumer distinction, negative evidence, and rejected owner alternatives.
- `by-class/GrafPort.md`: replace the broad `[UID:0003XC]` note with exact raw effective-clip and release-backstore child notes; preserve owner/emitter route through `00005V`; record that the release child is source-ready while raw child remains no-emitter; incorporate caller/resource evidence, negative evidence, score rationale, and original-spelling uncertainty.
- `by-file/GrafPort.md`: update proposed contents for `GrafPort.cpp` to include `GrafPort::ReleaseBackingStore()` and raw effective-clip helper evidence separately; keep DirectX/Surface as dependencies; record the exact child paths and source-placement rationale.
- `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`: update child inventory and raw island closure with the corrected child ranges, padding `0x004b97cf-0x004b97d0` and `0x004b981e-0x004b9820`, split disposition, release-helper C++ readiness, and raw-helper no-code/no-route proof.

Do not edit manual `-coverage-report.md` files during implementation unless the supervisor explicitly overrides. Generated coverage/tracker refresh should be validator-owned after source doc changes.

## Claim And Incorporation Ledger

| Claim / detail | Evidence | Incorporation requirement | State |
| --- | --- | --- | --- |
| Current target is mixed raw plus modeled helper | MCP `lookup_funcs`, disasm/decompile, bytes | Parent page split/container wording | applied: [UID:0003XC] now `RECONSTRUCTABLE:FALSE`, blank emitter/code, and lists exact children [UID:0004DI] and [UID:0004DJ]. |
| Raw helper correct range is `0x004b9770-0x004b97cf` | `retn 4` at `0x004b97cc` spans three bytes | Correct target inventory and new raw child range | applied: [UID:0004DI] created for `0x004b9770-0x004b97cf`; parent/support pages record the corrected boundary. |
| One-byte padding is `0x004b97cf-0x004b97d0` | `get_bytes` / disasm alignment | Padding note or ignored coverage update if applicable | applied: parent [UID:0003XC] and aggregate [UID:000160] document `0x004b97cf-0x004b97d0` as one byte of alignment. |
| `0x004b9770` has no route | MCP zero xrefs; PE scan zero branch/VA/RVA hits | Raw child no-emitter/no-code proof | applied: [UID:0004DI] has blank `EMITTER_UIDS`/C++ and target-specific no-code proof. |
| Raw helper is GrafPort effective-clip Region logic | disasm plus `GrafPortGetClipRect` support | Raw child behavior and GrafPort class/file notes | applied: [UID:0004DI], `by-class/GrafPort.md`, and `by-file/GrafPort.md` describe exposed/clip/bounds Region composition and sibling `GetClipRect` relationship. |
| `0x004b97d0` has six direct branch callers | MCP xrefs and PE scan | Release child caller inventory | applied: [UID:0004DJ] direct caller table lists all six call sites and contexts. |
| Release helper frees software buffer at `+0x98` gated by `+0x94` | Hex-Rays decompile; GrafPort layout docs | Release child behavior/C++ | applied: [UID:0004DJ] behavior and formal C++ include `m_usesSoftwareBuffer` / `m_softwareBuffer` cleanup. |
| Release helper releases DirectDraw surface at `+0x18` through COM slot `+8` | Hex-Rays decompile; DirectX/global docs | Release child behavior/C++ | applied: [UID:0004DJ] behavior and formal C++ include `m_ddSurface->Release()` under `g_pDirectX->m_pDirectDraw` guard. |
| `GrafPort::ReleaseBackingStore` is the best name | MapPane teardown docs and behavior | Release child title/proposed name/C++ | applied: [UID:0004DJ] title, status, and formal C++ use `GrafPort::ReleaseBackingStore()`. |
| ObjectPane/MapPane/Surface/DirectX ownership alternatives are rejected | caller/dependency direction and layout | Ownership/rejected alternatives in affected docs | applied: [UID:0003XC], [UID:0004DI], [UID:0004DJ], `by-class/GrafPort.md`, `by-file/GrafPort.md`, and [UID:000160] include the rejected alternatives and dependency/caller distinctions. |
| Exact original method/API spelling remains uncertain | no PDB/source symbols; field names from docs | Score rationale and confidence cap | applied: child score rationales and support-page notes preserve exact-original-spelling uncertainty as confidence cap. |
| Release child first-draft C++ aligns with `89/91` | modeled function, six callers, owner proof | New exact child C++ block only | applied: [UID:0004DJ] is `89/91`, owner/emitter [UID:00005V], and formal C++ block is populated; parent and raw child remain blank. |

## Implementation Tracking Checklist

- [x] Lease only files about to be edited during an approved implementation callback. Proof: leased existing target/support docs with `python tools\leaser\leaser.py B005 lease ...` before by-* edits; new child files could not be leased before creation.
- [x] Edit `by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md` as a split/container audit for `0x004b9770-0x004b981e`, with corrected subranges, negative evidence, child inventory, score `86/90`, `CANONICAL_OWNER:00005V`, `RECONSTRUCTABLE:FALSE`, blank emitter/code, and no stale combined C++ rationale. Proof: [UID:0003XC] metadata and body updated; validator command `000000004577` returned exit 0 / `ok: 1`.
- [x] Create `by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md` for range `0x004b9770-0x004b97cf` with `COMPLETION:85`, `CONFIDENCE:89`, `CANONICAL_OWNER:00005V`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++, no-route proof, behavior, range/padding, and rejected alternatives. Proof: validator command `000000004572` assigned real UID [UID:0004DI].
- [x] Create `by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md` for range `0x004b97d0-0x004b981e` with `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00005V`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005V`, blank `EMITTER_POSITION_OPTIONAL`, six-caller inventory, field/global evidence, rejected owner alternatives, and the first-draft C++ from this report in the formal C++ block. Proof: validator command `000000004573` assigned real UID [UID:0004DJ]; command `000000004574` revalidated after removing stale missing UID references and returned `ok: 1`.
- [x] Update `by-class/GrafPort.md` to incorporate the split, exact child paths/ranges, release-helper source readiness, raw-helper no-emitter state, caller/resource evidence, negative evidence, and original-spelling uncertainty. Proof: class page now references [UID:0004DI]/[UID:0004DJ] and has a 2026-07-02 change note; validator command `000000004578` returned exit 0 / `ok: 1` with pre-existing missing-ref warnings for older `0003XB/0003XE` references.
- [x] Update `by-file/GrafPort.md` to incorporate the split, exact child paths/ranges, `GrafPort::ReleaseBackingStore()` source placement in `render/GrafPort.cpp`, raw-helper no-code state, and DirectX/Surface dependency distinctions. Proof: file page Proposed Contents/Ownership/Cross-References/Changes updated; validator command `000000004580` returned exit 0 / `ok: 1` with pre-existing missing-ref warnings for older `0003XB/0003XE` references.
- [x] Update `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md` child inventory/raw island closure with the corrected child ranges, padding ranges, split disposition, raw no-code proof, and release-helper C++ readiness. Proof: aggregate page inventory/raw-island/source-placement/changes updated; validator command `000000004581` returned exit 0 / `ok: 1` with pre-existing missing-ref warnings for older `0003XB/0003XD/0003XE/0003ZP` references.
- [x] Do not edit manual `by-memory/-coverage-report.md`, generated coverage/tracker files, validator state, queues, archives, or supervisor ledgers. Proof: no manual edits were made to those files; generated files and validator registry state changed only through scoped validator commands.
- [x] Run scoped validators only after approved implementation edits, from `source-3/project-documentation`, using `--apply --queue-timeout 240`: `python .\tools\validator.py --mode file --file by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class/GrafPort.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-file/GrafPort.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md --apply --queue-timeout 240`. Proof: commands `000000004572`, `000000004573`, `000000004574`, `000000004577`, `000000004578`, `000000004580`, and `000000004581` completed with exit 0.
- [x] If the implementation callback asks for generated freshness, rerun the target by-memory validator with `--wait-generated` and report the relevant generated GrafPort output freshness state without editing generated files by hand. Proof: callback did not require `--wait-generated`; generated refresh state was checked with queue-status command `000000004582`, which showed no queued/processing jobs. `auto-generated/NexusTK/render/GrafPort.cpp` header is command `000000004580` and includes [UID:0004DJ]; `auto-generated/-ag-memory-coverage.md` header is command `000000004581` and lists [UID:0004DI] as non-emits, [UID:0004DJ] as coded, and [UID:0003XC] as not_reconstructable.
- [x] Release leases immediately after the edit/validator batch. Proof: `python tools\leaser\leaser.py B005 unlease ...` reported `Rejected[No active lease]` for all leased paths, and the current lease report has no B005/GrafPort matches.
- [x] Update this report's ledger/checklist during implementation with applied/already-present/excluded-with-reason states and proof. Proof: this section and the ledger above now record applied states and validator proof.

## Validator Results

Scoped validators were run during the accepted implementation callback from `source-3/project-documentation`.

| Command | command_id | command_timestamp | Exit | ok count / result | Warnings / side effects |
| --- | --- | --- | --- | --- | --- |
| `python .\tools\validator.py --mode file --file by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md --apply --queue-timeout 240` | `000000004572` | `2026-07-02T15:02:09-04:00` | 0 | UID assigned: [UID:0004DI]; no `ok` line printed because metadata/UID updates were applied | Generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md --apply --queue-timeout 240` | `000000004573` | `2026-07-02T15:02:23-04:00` | 0 | UID assigned: [UID:0004DJ]; no `ok` line printed because metadata/UID updates were applied | Initial stale missing refs for `0003TJ`/`0003TR`; fixed in the child doc and revalidated. |
| `python .\tools\validator.py --mode file --file by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md --apply --queue-timeout 240` | `000000004574` | `2026-07-02T15:03:09-04:00` | 0 | `ok: 1` | Generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md --apply --queue-timeout 240` | `000000004577` | `2026-07-02T15:06:28-04:00` | 0 | `ok: 1` | Updated [UID:0003XC] to `86/90`, `RECONSTRUCTABLE:false`, blank emitter; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-class/GrafPort.md --apply --queue-timeout 240` | `000000004578` | `2026-07-02T15:06:34-04:00` | 0 | `ok: 1` | Pre-existing missing-ref warnings for older `0003XB`/`0003XE` links; [UID:0004DI]/[UID:0004DJ] reference indexes added. |
| `python .\tools\validator.py --mode file --file by-file/GrafPort.md --apply --queue-timeout 240` | `000000004580` | `2026-07-02T15:06:49-04:00` | 0 | `ok: 1` | Pre-existing missing-ref warnings for older `0003XB`/`0003XE` links; generated `auto-generated/NexusTK/render/GrafPort.cpp` refreshed and includes [UID:0004DJ]. |
| `python .\tools\validator.py --mode file --file by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md --apply --queue-timeout 240` | `000000004581` | `2026-07-02T15:06:55-04:00` | 0 | `ok: 1` | Pre-existing missing-ref warnings for older `0003XB`/`0003XD`/`0003XE`/`0003ZP` links; generated memory coverage refreshed. |
| `python .\tools\validator.py --queue-status` | `000000004582` | `2026-07-02T15:07:10-04:00` | 0 | queue status only | Worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`. |

Generated freshness checked after validators:

- `auto-generated/NexusTK/render/GrafPort.cpp`: header `validator-command-id: 000000004580`, `validator-refreshed-at: 2026-07-02T15:06:49-04:00`; contains [UID:0004DJ] `GrafPort::ReleaseBackingStore()`.
- `auto-generated/-ag-memory-coverage.md`: header `validator-command-id: 000000004581`, `validator-refreshed-at: 2026-07-02T15:06:55-04:00`; lists [UID:0004DI] as non-emits, [UID:0004DJ] as coded, and [UID:0003XC] as not_reconstructable.
- `auto-generated/-ag-research-tracker.md`: generated by validator refresh and lists [UID:0004DI] `85/89`, [UID:0004DJ] `89/91`, and [UID:0003XC] `86/90`, reconstructable false.

## Changed Files

- `by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md`
- `by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md`
- `by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md`
- `by-class/GrafPort.md`
- `by-file/GrafPort.md`
- `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`
- `tools/leaser/Agents/Agent-B005/research/0003XC-GrafPortEffectiveClipAndBackingRelease-source-quality.md`

Validator-owned generated/projected files refreshed during scoped validation. No manual edits were made to generated files, coverage reports, project-level files, validator state, queues, archives, or supervisor ledgers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004606","destination_path":"executed-b-agent-research/B005/0003XC-GrafPortEffectiveClipAndBackingRelease-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003XC-GrafPortEffectiveClipAndBackingRelease-source-quality.md","timestamp":"2026-07-02T15:21:12-04:00","uid":"0003XC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
