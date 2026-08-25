** TARGET-REPORT-UID:00039Q **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID00039Q SurfaceFlipSurfaces Source-Quality Report

## Finalized Report / Current Recommendation

Reroute [UID:00039Q] `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md` from the provisional [UID:0000OC] Surface bucket to direct [UID:0000CB] ScreenPane class ownership, emitted through [UID:0000NB] `NexusTK/ui/core/ScreenPane.cpp`.

Recommended metadata after acceptance:

```text
COMPLETION: 88
CONFIDENCE: 90
CANONICAL_OWNER: 0000CB
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000CB
EMITTER_POSITION_OPTIONAL: blank
```

Recommended source-facing method name: `ScreenPane::PrepareDirectDrawPresentation()`. This name is descriptive, not recovered original symbol proof. It is more accurate than the stale `SurfaceFlipSurfaces` label because current MCP maps the observed surface operation to `IDirectDrawSurface::Blt(..., DDBLT_COLORFILL, ...)` plus `Restore()`, not to the SDK `Flip` slot.

Populate the formal C++ block with the first-draft code in this report. The remaining uncertainties are final method spelling, final field names for ScreenPane and Application offsets, and the source rationale for the unused `GetWindowRect(GetDesktopWindow(), ...)` local. They are naming/source-shape caveats, not blockers to source output.

## Final Recommendation

Final disposition for UID00039Q: treat `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md` as source-ready ScreenPane class code, not as a Surface-owned helper. The accepted source-facing name is `ScreenPane::PrepareDirectDrawPresentation()`, emitted through [UID:0000NB] `NexusTK/ui/core/ScreenPane.cpp` under direct [UID:0000CB] ScreenPane class ownership.

Exact target changes applied/recommended: set `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CB`, leave `EMITTER_POSITION_OPTIONAL` blank, and place the formal first-draft `ScreenPane::PrepareDirectDrawPresentation()` C++ in the target `RECONSTRUCTION_CPP CODE` block. The target documentation should retain the MCP session `31debdf2` evidence for exact range `0x00557470-0x0055769d`, `__thiscall` receiver shape, `g_pScreenPane` callers, ScreenPane fields `+0x100/+0x110/+0x111/+0x112/+0x114/+0x116`, paired UID00039R flag clearing, DirectDraw slots `+0x50/+0x54`, DirectDrawSurface `Blt`/`Restore` slots `+0x14/+0x6c`, and negative evidence that `Flip` slot `+0x2c` is not called.

Parent assignment disposition: do not assign the parent aggregate [UID:0001G6] `0x00557140-0x00559aef.SurfacePresentation` to ScreenPane or Surface as a whole. Keep that aggregate parentless, mixed-owner, and non-emitting; update only the UID00039Q child row to ScreenPane class owner `88/90` with `ScreenPane.cpp` emission. Keep [UID:0000OC] Surface as DirectDraw presentation address-neighborhood/dependency context for this child, not as canonical owner or emitter.

No-owner/non-emitting disposition: UID00039Q itself is no longer no-owner and should be reconstructable/emitting through ScreenPane. The only no-owner/non-emitting disposition in this recommendation is the surrounding mixed `SurfacePresentation` container, which remains non-reconstructable and parentless because it spans Surface, ScreenPane, ScreenshotCapture, DirectX, MapPane, and Pane traversal responsibilities.

Support disposition: sync `by-class/ScreenPane.md`, `by-file/ScreenPane.md`, `by-file/Surface.md`, `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`, and `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md` with the ScreenPane ownership and `Blt`/`Restore` evidence while preserving UID00039W's own Surface/minimap ownership. Exclude optional DirectX and UID0002GJ support edits unless a later supervisor callback identifies a concrete stale direct-conflict there.

Future work outside this scope: recover final original method and field names for `PrepareDirectDrawPresentation`, ScreenPane offsets, and Application window-offset fields; resolve the source rationale for the unused `GetWindowRect(GetDesktopWindow(), ...)` local; run any generated-output refresh through the normal validator/generator workflow; and perform any broader SurfacePresentation family owner cleanup as a separate task.

## Supporting Research

Original Gate 1 research scope was report-only. After supervisor Gate 1 acceptance, the implementation callback applied the accepted by-* edits listed in the Changed Files and Implementation Tracking Checklist sections below. No generated files, coverage reports, lifecycle state, archives, supervisor ledgers, IDA DB state, MCP/IDA process state, or subagents were used.

Local docs checked as leads: target UID00039Q, [UID:0001G6] `SurfacePresentation`, [UID:0000OC] `Surface`, [UID:0000NB] `ScreenPane`, [UID:0000CB] `ScreenPane`, [UID:0000IW] `DirectX`, [UID:00039R] `ScreenPane::RestoreDirectDrawState`, [UID:00039W] `SurfaceMinimapRenderInitializer`, executed B005 UID00039R report, executed B001 UID0002GJ report, and tracker/generated coverage rows for UID00039Q.

MCP history for this pass: the supervisor-provided session `1fc4a5a7` was no longer present. A schema-current `idb_list` call returned active NexusTK session `31debdf2`, `pid:8276`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`. `server_health` on `31debdf2` returned `status:ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input executable `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.

## Target

- UID: `00039Q`
- Path: `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank formal C++.
- Current tracker row: by-memory not-covered reconstructable, score `85/88`, combined `86.5`, reports `0`.

## Current Target State

The target already documents the exact function range, SurfacePresentation split source, DirectDraw dependency, activation caller, minimap initializer caller, paired setup writes to ScreenPane bytes `+0x110/+0x111`, and the Surface-vs-ScreenPane caveat. Its current blocker is stale source shape: it remains Surface-owned with blank C++ even though current evidence proves the incoming object and state are ScreenPane.

The target's current owner statement is weaker than its own evidence. It says UID00039Q sets ScreenPane restore flags consumed by [UID:00039R] `ScreenPane::RestoreDirectDrawState()`, yet keeps the owner as Surface pending a dedicated pass. This report is that dedicated pass.

## Heuristic / Inference Reanalysis And Validation

The main inference question was whether UID00039Q is a generic Surface free helper that happens to receive `g_pScreenPane`, or a ScreenPane method in the mixed SurfacePresentation address neighborhood.

Current MCP validates the ScreenPane method interpretation:

- The target decompiles as `void __thiscall sub_557470(int this)` and immediately copies `ecx` to the object register in disassembly (`mov edi, ecx`).
- All object state used by the body is ScreenPane-shaped: `+0x100` primary/display surface, `+0x110` cooperative-level restore flag, `+0x111` display-mode restore flag, and dimension/depth words `+0x112/+0x114/+0x116`.
- The paired [UID:00039R] method is already accepted as `ScreenPane::RestoreDirectDrawState()` because it clears `+0x110/+0x111`; UID00039Q sets those exact bytes at `0x005574e5` and `0x00557537`.
- Three modeled call contexts and the tight unmodeled caller range pass `g_pScreenPane` or the same ScreenPane receiver. MCP confirms UID0002GJ activation loads `dword_67A7CC` before `call sub_557470`, and the unmodeled `0x00465cf0-0x00465d30` range loads `dword_67A7CC` before both its jump/call to the target.
- The DirectDraw calls are SDK service calls, not ownership evidence for Surface or DirectX.

The stale `FlipSurfaces` name was also rechecked. MCP `type_inspect IDirectDrawSurfaceVtbl` maps surface vtable `+0x14` to `Blt` and `+0x6c` to `Restore`; SDK `Flip` is at `+0x2c` and is not called in this body. The helper color-fills/restores the primary display surface after setting cooperative/display state. `PrepareDirectDrawPresentation` is therefore the best current source-facing name.

## Evidence Standards Used

Direct MCP facts are highest weight: session health, exact function lookup, Hex-Rays decompile, bounded disassembly/range queries, xrefs, byte reads, type inspection, and MCP `int_convert`. Current by-* docs and executed reports are documentation evidence and were used as leads/support only. Generated tracker/coverage rows were read-only state context. Historical or `needs-revalidation` report text was not treated as standalone proof unless the same fact is present in current docs or current MCP evidence.

## Evidence Checked

- `tools/list` was checked before MCP evidence calls; relevant schemas used were `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `get_bytes`, `insn_query`, `type_inspect`, and `int_convert`.
- `server_health 31debdf2`: healthy NexusTK IDB, Hex-Rays ready.
- `lookup_funcs`: `0x00557470 -> sub_557470`, size `0x22d`; `0x0055769d` not a function; `0x005576a0 -> sub_5576A0`, size `0x170`; `0x004669c0 -> sub_4669C0`; `0x00558840 -> sub_558840`; `0x004f5fb0 -> sub_4F5FB0`; `0x00556a60 -> sub_556A60`; `0x00556910 -> sub_556910`.
- `decompile 0x00557470`: confirms `g_pDirectX` null guard, `g_pDirectX + 4` DirectDraw pointer load, conditional `SetCooperativeLevel`, conditional `SetDisplayMode`, flag writes at `this+272` and `this+273`, primary surface at `this+256`, screen words at `this+274/+276/+278`, `OffsetRect` using application offsets, `Blt`-style vtable call with literal `1024`, `DDERR_SURFACELOST`-style retry path through surface `Restore`, and DDError throws.
- `disasm 0x00557470` with `max_instructions:180`: confirms `.text` function body, `mov edi, ecx`, `cmp byte ptr [edi+110h],0`, `push 8` or `push 13h`, `call [esi+50h]`, `mov byte ptr [edi+110h],1`, `cmp byte ptr [edi+111h],0`, `call [ecx+54h]`, `mov byte ptr [edi+111h],1`, `mov esi,[edi+100h]`, `call [surface+14h]`, and `call [surface+6Ch]` on surface-lost retry.
- `xrefs_to 0x00557470`: four code xrefs: `0x00465d13`, `0x00465d1e`, `0x00466a02` in `sub_4669C0`, and `0x0055887d` in `sub_558840`.
- `xref_query 0x00557470`: confirms the same incoming refs plus one local flow record; no data-xref owner route was found in this bounded query.
- `insn_query 0x00465cf0-0x00465d30`: confirms the unmodeled range toggles `ApplicationActiveGate`, loads `dword_67A7CC`, then jumps/calls `sub_557470` at `0x00465d13`/`0x00465d1e`.
- `disasm 0x004669c0`: confirms `BaramApp::OnActivate` checks `ApplicationActiveGate` and `dword_67A7CC`, writes `g_pApplication + 0x838 = 1`, loads `ecx = dword_67A7CC`, then calls `sub_557470` at `0x00466a02`.
- `insn_query 0x00558870-0x00558890`: confirms `sub_558840` calls `sub_557470` at `0x0055887d` before DirectDraw surface setup and later reads ScreenPane dimension word `+0x112`.
- `get_bytes`: `0x00557468-0x00557470` is eight `0xcc` bytes; target prologue begins `55 8b ec 6a ff 68 d0 72 60 00 64 a1 00 00 00 00`; `0x0055769d-0x005576a0` is three `0xcc` bytes.
- `type_inspect IDirectDrawVtbl`: `+0x50` is `SetCooperativeLevel`, `+0x54` is `SetDisplayMode`.
- `type_inspect IDirectDrawSurfaceVtbl`: `+0x14` is `Blt`; `+0x2c` is `Flip` but is not called; `+0x6c` is `Restore`.
- `int_convert`: `0x22d` is 557 decimal, `0x110` is 272 decimal, `0x111` is 273 decimal, `0x100` is 256 decimal, `0x112/+0x114/+0x116` are 274/276/278 decimal, `0x13` is 19 decimal, `0x8` is 8 decimal, and `0x400` is 1024 decimal (Verified with MCP `int_convert`).
- One broad instruction scan for all calls to `0x00557470` timed out after narrower xref calls had already returned the complete incoming xref list. It was not repeated broadly under the MCP discipline.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00039Q-01 | Target range remains `0x00557470-0x0055769d`, modeled as `sub_557470`, with predecessor/successor `0xcc` padding. | High | MCP `lookup_funcs`, `get_bytes`, disasm. | Target Address Range / Evidence Basis; parent child row. | incorporate | applied: target Address Range / IDA MCP Evidence and parent `SurfacePresentation` child row updated. |
| C-00039Q-02 | Direct owner should change from Surface to [UID:0000CB] ScreenPane class, emitted through [UID:0000NB] ScreenPane.cpp. | High | `__thiscall` receiver, callers loading `g_pScreenPane`, ScreenPane fields, UID00039R lifecycle. | Target metadata/status; Surface/ScreenPane support docs. | applied: target metadata set to owner/emitter `0000CB`; ScreenPane class/file support added; Surface support demoted to dependency. |
| C-00039Q-03 | Source-facing name should be `ScreenPane::PrepareDirectDrawPresentation()`, not `SurfaceFlipSurfaces`. | Medium-high | Body sets DirectDraw presentation state and color-fills primary surface; no `Flip` slot call. | Target title/status/C++; caller support docs. | applied: target title/status/formal C++ and ScreenPane/Surface/minimap support use the ScreenPane method name while preserving stale generated label as history. |
| C-00039Q-04 | Body sets `m_restoreCooperativeLevelPending` at `+0x110` after `SetCooperativeLevel` succeeds. | High | MCP decompile/disasm write `0x005574e5`; UID00039R clears same flag. | Target behavior/field map; ScreenPane layout. | applied: target field map and ScreenPane support document setup write and UID00039R clearing relationship. |
| C-00039Q-05 | Body sets `m_restoreDisplayModePending` at `+0x111` after optional display-mode setup. | High | MCP decompile/disasm write `0x00557537`; UID00039R clears same flag. | Target behavior/field map; ScreenPane layout. | applied: target field map and ScreenPane support document setup write and UID00039R clearing relationship. |
| C-00039Q-06 | DirectDraw slot `+0x50` is `SetCooperativeLevel`; `+0x54` is `SetDisplayMode`. | High | MCP `type_inspect IDirectDrawVtbl`; target disasm. | Target DirectDraw evidence; DirectX dependency note. | incorporate | applied in target and required support; DirectX doc excluded-with-reason because optional and no concrete stale direct-owner conflict was found. |
| C-00039Q-07 | Surface slot `+0x14` is `Blt`, and slot `+0x6c` is `Restore`; SDK `Flip` is not used. | High | MCP `type_inspect IDirectDrawSurfaceVtbl`; target decompile/disasm. | Target helper naming/body evidence. | incorporate | applied: target and support docs record `Blt`/`Restore` and negative `Flip +0x2c` evidence. |
| C-00039Q-08 | Four code xrefs exist; activation and the unmodeled application-state range pass `g_pScreenPane`, and minimap initializer calls the helper before DirectDraw surface setup. | High | MCP `xrefs_to`, `xref_query`, disasm/insn_query ranges. | Target caller/reachability; caller support docs. | incorporate | applied in target and minimap support. UID0002GJ support excluded-with-reason: not in required support list and supervisor limited optional UID0002GJ edits. |
| C-00039Q-09 | DirectX is a dependency owner only. | High | `g_pDirectX->m_pDirectDraw` service use; DirectX doc boundary. | Target ownership rejection; DirectX support note if touched. | incorporate | applied in target and Surface support; DirectX support doc excluded-with-reason because optional and no concrete stale direct-owner claim found. |
| C-00039Q-10 | Formal C++ is now source-ready as a first draft with provisional field names. | Medium-high | Current decompile/disasm/type/xref evidence; remaining gaps are names only. | Target formal C++ block. | incorporate | applied: formal `RECONSTRUCTION_CPP CODE` block inserted in target doc and validated. |

## Positive Evidence Summary

- Current MCP proves exact range, function size, padding, decompile, disassembly, DirectDraw/DirectDrawSurface slot identities, incoming xrefs, and ScreenPane object offsets.
- Every object field in the target belongs to the already documented ScreenPane layout family: `+0x100`, `+0x110`, `+0x111`, `+0x112`, `+0x114`, and `+0x116`.
- The paired restore method [UID:00039R] is accepted ScreenPane class code, and UID00039Q sets the same flags that UID00039R clears.
- The stale `Flip` wording is actively contradicted by SDK vtable slot evidence: the body calls `Blt`, not `Flip`.
- DirectDraw and DDError dependencies are resolved enough for source-shaped code using existing project types and SDK names.

## Negative Evidence Summary

- No evidence supports DirectX ownership: the body is not a DirectX method and does not mutate DirectX object state beyond consuming `m_pDirectDraw`.
- No evidence supports a Surface object receiver: the incoming receiver is `g_pScreenPane` in caller evidence, and the field offsets match ScreenPane docs.
- No evidence supports a MapPane/minimap owner for the exact body: minimap initializer is a caller/dependency context, not a receiver owner.
- The current `SurfaceFlipSurfaces` label is behaviorally misleading because no `IDirectDrawSurface::Flip` call occurs.
- The broad all-text call scan timed out and was not used as evidence. The exact xref queries already returned the complete incoming xref list used here.

## Ranked Ownership Analysis

| Rank | Candidate | Evidence for | Evidence against | Decision |
| ---: | --- | --- | --- | --- |
| 1 | [UID:0000CB] ScreenPane class, emitted through [UID:0000NB] ScreenPane.cpp | `__thiscall`; callers load `g_pScreenPane`; ScreenPane surface/dimension/restore fields; constructor/destructor/UID00039R lifecycle; nearby ScreenPane helpers already rerouted by the same standard. | Address-neighboring SurfacePresentation helpers and historical Surface bucket naming. | Accept direct owner/emitter route. |
| 2 | [UID:0000OC] Surface | Mixed presentation neighborhood and DirectDraw surface operation. | No Surface receiver; stale `Flip` name; ScreenPane field lifecycle dominates locality. | Demote to neighborhood/dependency context. |
| 3 | [UID:0000IW] DirectX / [UID:00003Y] DirectX | Uses `g_pDirectX->m_pDirectDraw`. | DirectX owns interface lifetime, not ScreenPane display-state policy or primary surface field. | Reject direct owner; dependency only. |
| 4 | Application / BaramApp / startup helpers | Some callers orchestrate activation/startup state. | They pass `g_pScreenPane` and do not own the ScreenPane fields. | Reject direct owner; caller context only. |
| 5 | MapPane/minimap | UID00039W minimap initializer calls the target. | No MapPane receiver or fields in this target. | Reject direct owner; consumer/setup context only. |

## Source Placement

Recommended placement is `NexusTK/ui/core/ScreenPane.cpp` through [UID:0000CB] ScreenPane class ownership and [UID:0000NB] ScreenPane file emission. The target remains a child of the mixed [UID:0001G6] `SurfacePresentation` address-neighborhood container, but the exact source-bearing child should no longer emit through `NexusTK/render/Surface.cpp`.

Generated coverage currently says UID00039Q emits to `auto-generated/NexusTK/render/Surface.cpp` through [UID:0000OC]. That should change only through accepted by-* edits and validator/generator refresh, not by manual generated-file editing.

## First-Draft C++ Recommendation

Eligible for first-draft C++: yes.

Exact formal C++ block recommended for UID00039Q after supervisor acceptance:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScreenPane::PrepareDirectDrawPresentation()
{
    if (g_pDirectX == NULL)
        return;

    LPDIRECTDRAW directDraw = g_pDirectX->m_pDirectDraw;

    if (!m_restoreCooperativeLevelPending) {
        DWORD cooperativeFlags = ApplicationActiveGate
            ? DDSCL_NORMAL
            : (DDSCL_FULLSCREEN | DDSCL_ALLOWREBOOT | DDSCL_EXCLUSIVE);

        HRESULT hr = directDraw->SetCooperativeLevel(
            g_pApplication->GetMainWindowHandle(),
            cooperativeFlags);
        if (FAILED(hr))
            throw new DDError(hr);

        m_restoreCooperativeLevelPending = true;
    }

    if (!m_restoreDisplayModePending) {
        if (ApplicationActiveGate == 0) {
            RECT desktopRect;
            GetWindowRect(GetDesktopWindow(), &desktopRect);

            HRESULT hr = directDraw->SetDisplayMode(
                m_screenWidth,
                m_screenHeight,
                m_screenBitDepth);
            if (FAILED(hr))
                throw new DDError(hr);
        }

        m_restoreDisplayModePending = true;
    }

    if (m_primarySurface != NULL) {
        RECT fillRect;
        fillRect.left = 0;
        fillRect.top = 0;
        fillRect.right = m_screenWidth;
        fillRect.bottom = m_screenHeight;

        DDBLTFX bltFx;
        memset(&bltFx, 0, sizeof(bltFx));
        bltFx.dwSize = sizeof(bltFx);
        bltFx.dwFillColor = 0;

        if (ApplicationActiveGate) {
            OffsetRect(
                &fillRect,
                g_pApplication->m_windowOffsetX,
                g_pApplication->m_windowOffsetY);
        }

        HRESULT hr = m_primarySurface->Blt(
            &fillRect,
            NULL,
            NULL,
            DDBLT_COLORFILL,
            &bltFx);

        if (hr == DDERR_SURFACELOST) {
            m_primarySurface->Restore();
            m_primarySurface->Blt(
                &fillRect,
                NULL,
                NULL,
                DDBLT_COLORFILL,
                &bltFx);
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Behavioral notes for implementation:

- Do not add null checks for `g_pApplication`, `g_pDirectX->m_pDirectDraw`, or `m_primarySurface` beyond the checks shown. The binary only checks `g_pDirectX` and `m_primarySurface`.
- Preserve the unusual `GetWindowRect(GetDesktopWindow(), &desktopRect)` call even though the local rectangle is not subsequently used by the decompile.
- `m_windowOffsetX` / `m_windowOffsetY` are provisional names for `g_pApplication + 0xa5c` and `g_pApplication + 0xa58`; preserve the exact offset/order evidence in docs.
- `DDBLT_COLORFILL` corresponds to literal `0x400` / 1024 (Verified with MCP `int_convert`). `DDERR_SURFACELOST` corresponds to the observed negative HRESULT branch in the decompile; retain the retry semantics and do not add failure handling for the second `Blt` or `Restore` call because the binary does not.

## Recommended Target Doc Changes

For `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md` after supervisor Gate 1 acceptance:

- Set metadata to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CB`, blank `EMITTER_POSITION_OPTIONAL`.
- Replace the Surface-owned status with `ScreenPane::PrepareDirectDrawPresentation()` under [UID:0000CB], source route [UID:0000NB] `NexusTK/ui/core/ScreenPane.cpp`.
- Insert the formal C++ block above.
- Rename/source-shape note: historical `SurfaceFlipSurfaces` was a recovery label; current MCP proves no SDK `Flip` call, only `Blt`/`Restore`.
- Add current MCP evidence: session `31debdf2`; function `sub_557470` size `0x22d`; predecessor and successor padding; four xrefs; caller receiver setup; DirectDraw slot identities; DirectDrawSurface slot identities; flag writes; primary-surface fill/restore behavior; DDError throw paths.
- Preserve negative evidence and rejected alternatives for Surface, DirectX, Application/BaramApp/startup, and MapPane.

## Recommended Support Doc Changes

After supervisor acceptance, update these support docs as leases allow:

| Support path | Recommended action |
| --- | --- |
| `by-class/ScreenPane.md` | Add UID00039Q method row as `ScreenPane::PrepareDirectDrawPresentation()` at `0x00557470-0x0055769d`; consolidate field notes that it sets `+0x110/+0x111`, uses `+0x100/+0x112/+0x114/+0x116`, and pairs with `RestoreDirectDrawState()`. |
| `by-file/ScreenPane.md` | Add UID00039Q to proposed contents/source route through `NexusTK/ui/core/ScreenPane.cpp`; record that the old Surface bucket is demoted for this exact child. |
| `by-file/Surface.md` | Change UID00039Q row from Surface proposed content to SurfacePresentation-neighborhood dependency/context, similar to UID00039R/UID00039Z treatment; preserve DirectDraw dependency context. |
| `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` | Update the UID00039Q child row to ScreenPane class-owned `88/90` with the new method name, while keeping the master page parentless/non-emitting mixed container. |
| `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md` | Adjust the caller note: it calls ScreenPane-owned `PrepareDirectDrawPresentation()` before DirectDraw surface setup; this does not by itself reroute UID00039W. |
| `by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md` and executed UID0002GJ-derived support if touched | Replace formal/support call text `SurfaceFlipSurfaces(g_pScreenPane)` with `g_pScreenPane->PrepareDirectDrawPresentation()` after the target reroute. |
| `by-file/DirectX.md` | Optional dependency note only if stale wording appears: UID00039Q consumes `g_pDirectX->m_pDirectDraw`, but DirectX remains interface-lifetime owner, not presentation policy owner. |

No manual generated-file, tracker, or coverage-report edits are recommended. Generated Surface.cpp/ScreenPane.cpp routing should refresh through validators after accepted by-* implementation.

## Score And Metadata Recommendation

Recommended target score: `88/90`.

Completion improves from `85` to `88` because the current pass resolves the named blockers: Surface-vs-ScreenPane ownership, DirectDraw vtable identities, surface vtable identities, helper naming, caller receiver setup, padding, flag lifecycle, and first-draft formal C++.

Confidence improves from `88` to `90` because current MCP directly proves the body, xrefs, field offsets, caller setup, and SDK vtable slots. It stays below `91+` because original method spelling is unknown, `m_windowOffsetX/Y` and some field names are provisional, the unmodeled `0x00465cf0` call range has no function owner, and the source reason for the unused desktop rectangle local remains unexplained.

Metadata should use [UID:0000CB] as both owner and emitter UID, matching the accepted UID00039R class-owned route. [UID:0000NB] remains the file/source path route.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution / score impact |
| --- | --- | --- |
| Original method spelling | Current IDA function name is `sub_557470`; no PDB/source name exists in docs or MCP. | Use descriptive `PrepareDirectDrawPresentation`; keep confidence below final-source range. |
| Whether `FlipSurfaces` should survive | MCP `IDirectDrawSurfaceVtbl` maps actual surface calls to `Blt` and `Restore`; `Flip` slot not used. | Historicalize/reject as stale recovery label. |
| Whether Surface still owns the helper because UID00039W calls it | UID00039W call site and body role checked; UID00039W remains broader Surface/minimap initializer but passes/uses ScreenPane receiver context. | UID00039W is caller/context, not owner; update support docs without rerouting UID00039W. |
| Application offset names at `+0xa5c/+0xa58` | Target decompile/disasm checked; current by-* support does not provide final names. | Use provisional `m_windowOffsetX/Y` with exact offset note; not a C++ blocker. |
| Unmodeled caller owner for `0x00465cf0-0x00465d30` | Tight MCP range query checked; `lookup_funcs` reports no modeled function for call sites. | Record as unmodeled application-state helper range that passes `g_pScreenPane`; not needed for target owner beyond caller evidence. |
| Whether broad call scan is needed | Exact `xrefs_to` returned four xrefs; one broad text scan timed out. | Do not repeat broad scan; exact xref list is sufficient and bounded. |

## Validator Results

Implementation callback validators were run from `source-3/project-documentation` with:

> Executable block R001 was removed from this report and preserved verbatim in [00039Q-SurfaceFlipSurfaces-source-quality-removed.md](00039Q-SurfaceFlipSurfaces-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

| File | command_id | command_timestamp | Exit | ok | Warnings/errors |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md` | `000000005284` | `2026-07-03T09:47:23-04:00` | `0` | `1` | `missing_ref_uid: 11` for existing unregistered refs including `00039R/00039Z`; no validator error. Applied metadata/registry/reference updates for UID00039Q. |
| `by-class/ScreenPane.md` | `000000005285` | `2026-07-03T09:47:25-04:00` | `0` | `1` | `missing_ref_uid: 48` for existing unregistered refs; no validator error. |
| `by-file/ScreenPane.md` | `000000005286` | `2026-07-03T09:47:27-04:00` | `0` | `1` | `missing_ref_uid: 49` for existing unregistered refs; no validator error. |
| `by-file/Surface.md` | `000000005287` | `2026-07-03T09:47:38-04:00` | `0` | `1` | `missing_ref_uid: 30` for existing unregistered refs; no validator error. |
| `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` | `000000005288` | `2026-07-03T09:47:45-04:00` | `0` | `1` | `missing_ref_uid: 58` for existing unregistered refs; no validator error. |
| `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md` | `000000005289` | `2026-07-03T09:47:52-04:00` | `0` | `1` | `missing_ref_uid: 8` for existing unregistered refs; no validator error. Validator normalized two UID00039Q link labels. |

Generated refresh status: every validator reported `generated_refresh: deferred`; target command `000000005284` updated UID00039Q registry/canonical-owner metadata from `0000OC` to `0000CB` and projected stats, but no manual generated-file or coverage-report edit was made.

## Changed Files

Implementation callback changed files:

- `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md`
- `by-class/ScreenPane.md`
- `by-file/ScreenPane.md`
- `by-file/Surface.md`
- `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`
- `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`
- `tools/leaser/Agents/Agent-B008/research/00039Q-SurfaceFlipSurfaces-source-quality.md`

Validator `--apply` also updated validator-managed state (`tools/validator.ini` and projected stats). No manual generated-file, `-coverage-report.md`, lifecycle/archive, registry, queue, supervisor-ledger, IDA DB, or MCP/IDA process-management edits were made.

Lease handling: the callback began after a successful B008 lease request for the six by-* files listed above. After validation, `python .\tools\leaser\leaser.py B008 release ...` failed because this leaser uses `unlease`. The follow-up `unlease` command reported no active B008 lease for four files and active B007 leases for `by-class/ScreenPane.md` and `by-file/ScreenPane.md`; current lease report at that moment showed B007 leases created `2026-07-03T13:43:22Z`, expiring `2026-07-03T13:48:22Z`. No further by-* edits were made after that release-state observation.

## Implementation Tracking Checklist

- [x] Target doc `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md`: set `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CB`, blank emitter position, and insert the formal `ScreenPane::PrepareDirectDrawPresentation()` C++ block. State: applied.
- [x] Target doc: replace stale Surface/free-helper wording with ScreenPane class method status, current MCP session `31debdf2` evidence, exact range/padding, caller xrefs, DirectDraw/DirectDrawSurface slot identities, flag writes, primary-surface color-fill/restore behavior, and exception paths. State: applied.
- [x] Target doc: preserve historical/rejected alternatives and negative evidence: stale `SurfaceFlipSurfaces`/Flip wording, Surface bucket route, DirectX ownership, Application/BaramApp/startup ownership, MapPane/minimap ownership, no data owner route, and broad-scan timeout not used as proof. State: applied.
- [x] `by-class/ScreenPane.md`: add method row and layout notes for UID00039Q using `+0x100/+0x110/+0x111/+0x112/+0x114/+0x116` and the UID00039R paired lifecycle. State: applied.
- [x] `by-file/ScreenPane.md`: add UID00039Q as emitted ScreenPane source content in `NexusTK/ui/core/ScreenPane.cpp`. State: applied.
- [x] `by-file/Surface.md`: demote UID00039Q to SurfacePresentation neighborhood/dependency context, not Surface proposed content. State: applied.
- [x] `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`: update UID00039Q child row to ScreenPane class owner `88/90`, preserving parentless mixed-container status. State: applied.
- [x] `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`: update caller note from Surface flip helper to ScreenPane-owned presentation preparation helper without rerouting UID00039W. State: applied.
- [x] UID0002GJ activation target/support if included in callback scope: update source call from `SurfaceFlipSurfaces(g_pScreenPane)` to `g_pScreenPane->PrepareDirectDrawPresentation()` and preserve UID0002GJ's own owner/emitter. State: excluded-with-reason; not in required support-doc callback list and supervisor instructed not to edit optional UID0002GJ docs absent a concrete stale conflict directly requiring this callback.
- [x] Optional `by-file/DirectX.md`: update only if stale direct-ownership wording exists; otherwise leave as already sufficient dependency boundary. State: excluded-with-reason; no concrete stale DirectX ownership conflict found in required support review.
- [x] Do not edit generated files or manual/generated `-coverage-report.md` files. Let validators/generator refresh generated `Surface.cpp`, `ScreenPane.cpp`, and tracker rows. State: applied; no manual generated or coverage edits; validators reported generated refresh deferred.
- [x] Run scoped validators for every edited by-* file from `source-3/project-documentation` using `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240`. State: applied, command IDs `000000005284` through `000000005289`.
- [x] After validation, record command ids, command timestamps, exit codes, ok counts, warnings/errors, generated freshness observations, changed files, leases used/released, and checklist/ledger states. State: applied; lease release anomaly recorded above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000005311","destination_path":"executed-b-agent-research/B008/00039Q-SurfaceFlipSurfaces-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/00039Q-SurfaceFlipSurfaces-source-quality.md","timestamp":"2026-07-03T10:25:29-04:00","uid":"00039Q"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00039Q-SurfaceFlipSurfaces-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/00039Q-SurfaceFlipSurfaces-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00039Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
