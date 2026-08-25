** TARGET-REPORT-UID:00017M **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00017M EffectObjImageLib RenderEffectFrame Source-Quality Report

Assignment: `B002-goal2-effectobj-render-frame-source-quality-00017M-20260617`  
Primary target: [UID:00017M] `by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md`  
Disposition: report-only recommendation for supervisor execution.

## Executive Recommendation

- Raise [UID:00017M] from `82/88` to `86/90`.
- Keep `CANONICAL_OWNER:00004A`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004A`, and blank `EMITTER_POSITION_OPTIONAL`.
- Keep source placement under [UID:00004A] `EffectObjImageLib`, routed by [UID:0000IY] `EffectObjImageLib` to `NexusTK/render/EffectObjImageLib.cpp`.
- Do not populate the target's formal `RECONSTRUCTION_CPP` block yet. A first-draft source shape is included below for review, but the formal block should stay blank until the shared surface callback typedef, combined frame-draw state type, and `IntAlphaSurface`/`AlphaMaskSurface` parameter split are declared source-quality.
- Replace stale target wording that says `arg_18` is the overlay target pointer. `arg_18` is best treated as an overlay-mask gate pointer or gate value sourced from the caller's render context (`MapPane + 0x3e0` in the only caller); the target passed to `DrawEncodedAlphaFrame` is the second method parameter.

## Evidence Checked

- Target and support docs: [UID:00017M], [UID:00004A], [UID:0000IY], [UID:00017K], [UID:0001U9], [UID:0001U7], [UID:0001U8], [UID:0001UA], [UID:0000UX], [UID:0000UH], [UID:00029J], [UID:0001D9], `PaletteSlotTable`, `SurfaceRenderCallbackTable`, `AlphaMaskSurfaceLayout`, and related EffectObjectPane/MapPane context.
- Existing B reports search: `rg -n "00017M|EffectObjImageLibRenderEffectFrame|RenderEffectFrame|0x004de190|0x00538ba0|EffectObjectPane" tools/leaser/Agents -g "*.md"`. Relevant old leads were [B001 `00029J-ImageLibraryLoadErrorFlag.md`] and B001 MapPane effect-object split reports; they were treated as leads, not authority.
- Live IDA MCP session `b002_00017m_effectobj_render_20260617` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:
  - `lookup_funcs 0x004de190` reports `sub_4DE190`, size `0x110`; `0x004de2a0` is the next function.
  - `analyze_function 0x004de190` reports prototype `int __thiscall(int *this, int, int, int, int, float, int, int, float)`, size `272`, caller `sub_538AF0`, callees `sub_457A60`, `LoadFrameDrawRecord`, `sub_543E40`, `unk_69B3E8`, `sub_462F20`, and security-cookie check.
  - `disasm 0x004de190` confirms `retn 20h`, `cmp byte ptr unk_69B420, 0`, object offsets `+0x4c/+0x50/+0x58/+0x5c`, palette category push `0Bh`, callback call through `unk_69B3E8`, overlay constants at `0x006104cc` and `0x006104b0`, and `sub_462F20` call at `0x004de289`.
  - `analyze_function 0x00538af0` confirms the sole caller copies the 16-byte `EffectFrameRecord` into the call frame and passes `arg_18` from caller `a2 + 0x3e0` plus overlay strength from caller `a2 + 0x3dc` and `EffectObjectPane + 0x11c`.
  - `decompile 0x00457a60` confirms a 40-byte combined draw-state initializer, not two unrelated local records.
  - `decompile 0x004d1600` confirms the archive metadata loader writes fields across that same draw-state block.
  - `decompile 0x00543e40` confirms `PaletteLib::GetSlotPalette`-style behavior; the target passes `(11, selectedRemap, 0)`.
  - `analyze_function 0x00462f20` confirms the encoded-alpha helper has nine code xrefs, including `0x004de289`, and uses the alpha-surface layout family.
- Read-only PE scan:
  - Section-mapped rel32 scan found exactly one direct call to `0x004de190`, at `0x00538ba0`.
  - The same scan found no raw VA pointer hits for `0x004de190`, so there is no table/indirect-use evidence that would change owner or liveness treatment.
- Generated-output check:
  - `source-3/simroot_v2/class_EffectObjImageLib.cpp` exists and contains a generated `RenderEffectFrame` body.
  - No `.disabled` companion is present.
  - `class_EffectObjImageLib.meta_wave3` marks the method `disabled:false`, `effective_grade:96.0`, but `effective_included:false`.
  - `project-documentation/auto-generated/NexusTK/render/EffectObjImageLib.cpp` is present as a zero-byte file, so the active project generated route is still effectively empty for this source body.

## Function Boundary And Liveness

The exact function body is `0x004de190-0x004de2a0` half-open. The target filename uses inclusive-end style `0x004de29f`, which is acceptable as long as the body text records the IDA exclusive end. The terminal instruction is `retn 20h`, matching eight stack arguments after `this`.

The only direct executable caller is `0x00538ba0` inside `EffectObjectPane::RenderEffect` (`0x00538af0-0x00538baa`). PE scanning found the same single rel32 call and no function-entry pointer hits. This supports normal source-authored method treatment, not retained duplicate/helper artifact treatment.

## Source Shape And Parameter Names

Best defensible method name remains:

```cpp
int EffectObjImageLib::RenderEffectFrame(
    MapPane *mapPaneOrRenderContext,
    IntAlphaSurface *drawTarget,
    int frameResourceId,
    int timerDelayAndRenderArg,
    float renderScalar,
    int lightingAndRenderArg,
    AlphaMaskSurface *overlayMaskGate,
    float overlayStrength);
```

Parameter-name rationale:

- `mapPaneOrRenderContext`: the only caller passes its first render argument; that argument supplies `+0x3dc/+0x3e0` overlay state and is forwarded to the primary surface callback. `MapPane*` is plausible, but the formal type should wait for the shared object-pane render virtual signature.
- `drawTarget`: the second argument is passed to the primary surface callback and then used as the `this` object for `DrawEncodedAlphaFrame`. It is the destination/alpha output target, not merely a rectangle.
- `frameResourceId`: this is `EffectFrameRecord +0x00`; it indexes `EffectObjImageLib`'s `EFFECT.FRM` remap and is cast to `int16_t` for `LoadFrameDrawRecord`.
- `timerDelayAndRenderArg`: this is `EffectFrameRecord +0x04`; the renderer does not use it directly, but the source signature preserves the four-record-field forwarding contract.
- `renderScalar`: this is `EffectFrameRecord +0x08`; the target uses it only to enable/fill the alpha parameter block when positive.
- `lightingAndRenderArg`: this is `EffectFrameRecord +0x0c`; the renderer does not use it directly, but sibling update/bounds paths consume the same record field.
- `overlayMaskGate`: this is not the `DrawEncodedAlphaFrame` target. The caller pushes `MapPane/renderContext + 0x3e0`, and the target only tests it for nonzero before drawing encoded alpha into `drawTarget`.
- `overlayStrength`: scaled by `32.0f`, rounded with `+0.5f`, truncated to the low byte, then passed to `DrawEncodedAlphaFrame`.

Rejected names from older/generated docs:

- `frameIndex`: partly descriptive but weaker than `frameResourceId`, because the caller value is the record's frame-resource id, not the current animation index.
- `paletteId`: rejected. The palette/remap comes from `EFFECT.FRM` and category `11`; no caller-supplied palette id is used.
- `alpha` as the sole float name: rejected as too narrow. The float is the record's render scalar and only becomes an alpha-block value when positive.
- `drawFlags`: rejected. `arg_14` is the fourth `EffectFrameRecord` field and is unused in this body.
- `overlayTarget` for `arg_18`: rejected as exact target wording. It is a gate pointer/value; the actual alpha draw target is the second parameter.

## Field And Dependency Names

Recommended target documentation names:

| Address/offset | Recommended name | Evidence |
| --- | --- | --- |
| `this + 0x4c` | `effectPixMapInfoArray.count` / `frameRemapCount` | Compared against `frameResourceId` before array lookup. |
| `this + 0x50` | `effectPixMapInfoArray.entries` / `frameRemapEntries` | Indexed as `entries + 4 * frameResourceId`. |
| `this + 0x58` | `fallbackFrameRemap` | Used when `frameResourceId` is out of range; loader initializes it to `-1`. |
| `this + 0x5c` | `effectFileInfo` / `effectArchiveMetadataTable` | Passed to `LoadFrameDrawRecord`. |
| `EffectPixMapInfo +0x00` | `frameRemapOrPaletteSlot` | One dword from `EFFECT.FRM`, passed to palette slot `11`. |
| local `[ebp-0x58]` | `EffectRenderAlphaParams` scratch | First dword set to `1`, next float set to `renderScalar`, passed only when scalar is positive. |
| local `[ebp-0x2c..-0x05]` | combined `FrameDrawState` / draw-record plus clip-context | `sub_457A60` initializes 40 bytes; `LoadFrameDrawRecord` writes across the same block; callback and alpha helper receive its two subregions. |

Dependency naming:

- Use `ImageLibraryLoadErrorFlag` or `g_imageLibraryLoadErrorFlag` for `0x0069b420`, with ownership under [UID:0000K2] `ImageLib`. Do not describe it as EffectObjImageLib-owned.
- Use `g_pPaletteLib->GetSlotPalette(11, selectedRemap, 0)` or `PaletteLib::GetSlotPalette(kPaletteSlotEffect, selectedRemap, 0)`. `PaletteSlotTable` confirms slot `11` is `EFFECT.PAL`.
- Use `g_surfaceRenderCallbacks.primaryFrameBlit` or `SurfaceRenderCallbackTable::primaryFrameBlit` for `dword_69B3E8`. Avoid callsite-biased generated aliases such as `g_uiTileRenderer` or `g_pfnBlitTileFrame`.
- Use `DrawEncodedAlphaFrame` as the dependency name and keep it owned by `AlphaMaskSurface`/`IntAlphaSurface` support docs. The caller uses mode/constant pair `0, 1` and strength `uint8_t(overlayStrength * 32.0f + 0.5f)`.

## Caller-Side Ownership At 0x00538ba0

`0x00538ba0` belongs to `EffectObjectPane::RenderEffect`, not to this target. It validates current frame index at `EffectObjectPane + 0x144` against frame count at `+0x138`, indexes the copied frame-record sequence at `+0x12c`, and forwards all four `EffectFrameRecord` fields to `EffectObjImageLib::RenderEffectFrame`.

The optional overlay path is caller-side policy:

- If `EffectObjectPane + 0x11c` is zero or `sub_50AB40(g_activeMapPane)` returns false, the caller passes `overlayMaskGate = 0` and `overlayStrength = 0.0f`.
- Otherwise the caller passes `overlayMaskGate = renderContext + 0x3e0` and `overlayStrength = *(float *)(renderContext + 0x3dc) + *(float *)(EffectObjectPane + 0x11c)`.
- `sub_50AB40` checks active map pane/config state (`activeMapPane[247] < 0.60000002` and a config byte), so this is render-context/map overlay policy outside the image library.

Therefore this target owns frame rendering from effect image-library resources. It should not absorb `EffectObjectPane` animation ownership, MapPane render policy, or the alpha-surface implementation.

## Heuristic / Inference Reanalysis And Validation

Best defensible inferences:

- Source-facing owner and placement: [UID:00004A] `EffectObjImageLib`, source file [UID:0000IY] `NexusTK/render/EffectObjImageLib.cpp`. This is validated by object field use, singleton caller `g_pEffectObjImageLib`, local method cluster membership, resource ownership for `EFFECT.FRM`/`EFFECT.EPF`, and the sole caller acting as a consumer.
- Signature shape: eight arguments after `this`, preserving the caller's four-field `EffectFrameRecord` forwarding contract. The first two types are still best-effort because the shared object-pane render virtual and alpha-surface declarations are not final, but their roles are now stronger than the current generic wording.
- Resource fields: `+0x4c/+0x50/+0x58/+0x5c` are no longer open blockers. Existing layout and live IDA agree they are remap count, remap entries, fallback remap, and effect archive metadata.
- Overlay semantics: `arg_18` is a gate value/pointer, not the object consumed by the alpha helper. Existing docs that call it the optional overlay target pointer should be revised.
- Image-library flag: existing target/class wording should be updated to the [UID:00029J] resolution. `EffectObjImageLib` writes/reads the flag as a participant, but common [UID:0000K2] `ImageLib` owns the shared declaration.
- Generated output: current support docs that say there is a disabled companion are stale. The current state is no disabled companion, generated method text present in `simroot_v2`, metadata `effective_included:false`, and zero-byte project route output.

Evidence checked:

- Live IDA decompile/disassembly for target and sole caller.
- Live IDA decompile for palette lookup, draw-state initializer, frame-record loader, MapPane overlay predicate, and encoded-alpha helper.
- PE direct-call and raw pointer scan.
- Dedicated support docs for `EffectFrameRecord`, `EffectPixMapInfo`, `EffectObjImageLibLayout`, `ImageLibraryLoadErrorFlag`, `SurfaceRenderCallbackTable`, `PaletteSlotTable`, and alpha-surface layout.
- Existing executed B reports for [UID:00029J] and MapPane effect-object packet splits.

Rejected alternatives:

- Treat as a global utility/free helper: rejected because the body reads `this` object fields and is called through `g_pEffectObjImageLib`.
- Treat as a retained duplicate/compiler artifact: rejected because it has a source-level body, one real caller, nontrivial resource/callback behavior, and no duplicate sibling body.
- Move ownership to `EffectObjectPane` or `MapPane`: rejected because those callers select/runtime-schedule frames but do not own effect image-library remap/archive/palette resources.
- Keep final helper names uncertain without recommendation: rejected. The best current names above are defensible, while the remaining uncertainty is narrowed to formal C++ type declarations.
- Populate final C++ now: rejected because formal source would still need guessed shared callback typedefs, guessed combined draw-state declarations, and guessed `IntAlphaSurface`/`AlphaMaskSurface` parameter types. Entering guessed C++ would make generated output look more final than the dependency docs support.

Validation/rejection of existing docs:

- Validate owner/emitter, reconstructability, exact range, single caller, callee set, remap/archive field offsets, palette slot `11`, alpha scratch block, and overlay strength formula.
- Reject stale target wording for `arg_18` as exact overlay target.
- Reject stale target/class generated-output language that says active generated output is disabled by companion file.
- Reject `EffectObjImageLib`-owned language for `ImageLibraryLoadErrorFlag`; keep it as shared `ImageLib` state.

Score/source-placement/final-C++ impact:

- Completion can rise to `86` because source shape, parameter roles, overlay gate semantics, field/dependency names, generated-output state, and caller ownership are now resolved enough for source-quality documentation.
- Confidence can rise to `90` because live IDA, support docs, and PE reachability agree. It should stay below final-audit range because final shared render callback and alpha-surface declarations are unresolved.
- Source placement remains unchanged under `EffectObjImageLib`.
- Formal C++ remains blank despite clearing the `85/85` code-entry score gate.

## Score And Metadata Recommendations

Target [UID:00017M]:

```text
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:00004A
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00004A
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: leave blank
```

Support docs to update:

- [UID:00017M] target page:
  - Update scores and status.
  - Replace stale generated-output caveat with current no-disabled-companion/effective-excluded/zero-byte-route caveat.
  - Correct `arg_18` wording to overlay gate pointer/value.
  - Add current IDA/PE evidence and source-facing signature recommendation.
  - Add explicit first-draft C++ policy: do not populate formal block.
- [UID:00017K] local method cluster:
  - Update the Function Inventory row for [UID:00017M] from `82/88` to `86/90` and summarize the corrected overlay/source-quality findings.
- [UID:00004A] class page:
  - Replace the stale `byte_69B420` note saying to keep it near Effect until broader owner is proven. The broader owner is now [UID:0000K2] `ImageLib`; `EffectObjImageLib` is a participant.
  - Keep generated-output caveat, but mention this target remains effective-excluded and formal C++ blank.
- [UID:0000IY] file page:
  - Keep current generated-output caveat, but add the `arg_18` overlay-gate correction if method details are expanded.
- [UID:0001U9], [UID:0001UA], [UID:0001U7], [UID:0001D9]:
  - No score changes required. Optional text sync can mention that [UID:00017M] now uses `frameResourceId`, preserves unused record fields in the signature, and treats `arg_18` as an overlay gate.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP` block from this draft. It is included only to show the accepted source shape and naming direction. The exact shared types and callback declaration are not final-source quality.

```cpp
// Source-shape draft only. Do not paste into the formal target C++ block yet.
int EffectObjImageLib::RenderEffectFrame(
    MapPane *mapPaneOrRenderContext,
    IntAlphaSurface *drawTarget,
    int frameResourceId,
    int timerDelayAndRenderArg,
    float renderScalar,
    int lightingAndRenderArg,
    AlphaMaskSurface *overlayMaskGate,
    float overlayStrength)
{
    (void)timerDelayAndRenderArg;
    (void)lightingAndRenderArg;

    if (g_imageLibraryLoadErrorFlag) {
        return reinterpret_cast<int>(overlayMaskGate);
    }

    const EffectPixMapInfo *remap = &fallbackFrameRemap;
    if (frameResourceId >= 0 && frameResourceId < effectPixMapInfoArray.count) {
        remap = &effectPixMapInfoArray.entries[frameResourceId];
    }

    EffectFrameDrawState state;
    InitializeFrameDrawState(&state);
    LoadFrameDrawRecord(effectFileInfo, static_cast<int16_t>(frameResourceId), &state);

    void *palette = g_pPaletteLib->GetSlotPalette(11, remap->frameRemapOrPaletteSlot, 0);

    EffectRenderAlphaParams alphaParams;
    EffectRenderAlphaParams *alphaParamsPtr = nullptr;
    if (renderScalar > 0.0f) {
        alphaParams.enabled = 1;
        alphaParams.scalar = renderScalar;
        alphaParamsPtr = &alphaParams;
    }

    int result = g_surfaceRenderCallbacks.primaryFrameBlit(
        mapPaneOrRenderContext,
        &state.frameRecord,
        &state.clipContext,
        drawTarget,
        1,
        palette,
        alphaParamsPtr);

    if (overlayMaskGate != nullptr) {
        const unsigned char overlayByte =
            static_cast<unsigned char>(overlayStrength * 32.0f + 0.5f);

        return DrawEncodedAlphaFrame(
            drawTarget,
            &state.frameRecord,
            &state.clipContext,
            drawTarget->field_0c,
            overlayByte,
            drawTarget->field_04,
            0,
            1);
    }

    return result;
}
```

Formal C++ blockers are concrete:

- `EffectFrameDrawState` is a 40-byte combined local state initialized by `sub_457A60`; the final source type and subfield names are not declared.
- `g_surfaceRenderCallbacks.primaryFrameBlit` has a proven slot and broad role, but not a final typedef/signature.
- `drawTarget` and `overlayMaskGate` are both alpha/render-surface-adjacent pointers, but the exact `MapPane` render virtual signature and `IntAlphaSurface`/`AlphaMaskSurface` split are still unresolved.
- `drawTarget->field_04` and `drawTarget->field_0c` must not be emitted as final member names.

## Coverage Row Recommendation

Replace the existing [UID:00017M] row under [UID:00017K] `EffectObjImageLibLocalMethodCluster`, between [UID:00017L] and [UID:0002HA], with:

```text
    - [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md) 0x004de190-0x004de29f | method | EffectObjImageLib::RenderEffectFrame : reconstructable : 86% : very-strong : B002 2026-06-17 source-quality audit confirms exact 0x004de190-0x004de2a0 function body, sole EffectObjectPane caller at 0x00538ba0, PE direct-call/no-pointer evidence, ImageLibraryLoadErrorFlag render guard, EffectPixMapInfo remap count/array/fallback and effect archive metadata offsets +0x4c/+0x50/+0x58/+0x5c, EFFECT.PAL palette category 11 via PaletteLib, SurfaceRenderCallbackTable slot 2 primary frame blit callback, positive-render-scalar alpha parameter block, optional encoded-alpha overlay with strength int(overlayStrength*32.0f+0.5f), corrected arg_18 overlay-gate semantics, and current generated-output caveats; formal C++ remains blank pending shared callback/draw-state/alpha-surface type finalization.
```

No other `by-memory/-coverage-report.md` row is required solely by this target recommendation.

## Validation Commands

Run after supervisor applies target/support-doc updates:

> Executable block R001 was removed from this report and preserved verbatim in [00017M-effectobj-render-frame-source-quality-removed.md](00017M-effectobj-render-frame-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Optional support validators if text is synced there:

> Executable block R002 was removed from this report and preserved verbatim in [00017M-effectobj-render-frame-source-quality-removed.md](00017M-effectobj-render-frame-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Report-Only Compliance

Created one report:

- `tools/leaser/Agents/Agent-B002/research/00017M-effectobj-render-frame-source-quality.md`

No by-* docs, generated reports, generated source, IDA DB files, source files, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00017M-effectobj-render-frame-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00017M"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00017M-effectobj-render-frame-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00017M-effectobj-render-frame-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00017M"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
