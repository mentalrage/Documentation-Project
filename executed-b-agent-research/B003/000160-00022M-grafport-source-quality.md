** TARGET-REPORT-UID:000160 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 GrafPort Source-Quality / Split Report: UID 000160 and UID 00022M

Assignment: `B003-goal2-grafport-source-quality-000160-00022M-20260617`

Primary targets:
- [UID:000160] `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`
- [UID:00022M] `by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md`

## Finalized Recommendation

The split-first repair is now executed.

- [UID:000160] is no longer a reconstructable source-emitting aggregate. It is now a reviewed `RECONSTRUCTABLE:FALSE` split/index at `86/90`, with `EMITTER_UIDS` blank. Exact children carry source ownership and output routing.
- [UID:00022M] is now `GrafPort::EnableSoftwareBuffer`, not a dirty flag setter. It is `87/91`, owner/emitter [UID:00005V] GrafPort, and its formal C++ block is populated.
- Five new child pages were created and validated for the formerly open raw/split islands:
  - [UID:0003XB] `0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers`
  - [UID:0003XC] `0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease`
  - [UID:0003XD] `0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit`
  - [UID:0003XE] `0x004bb260-0x004bb2d5.SurfaceTileBufferBlitRaw`
  - [UID:0003XF] `0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw`

No raw-island issue remains deferred. Weak-liveness islands are now exact child docs with explicit no-owner/no-emitter blockers and score impact.

## Changes Applied

Edited existing target docs:
- `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`
  - Before: `82/88`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000JR], open raw split caveats.
  - After: `86/90`, `RECONSTRUCTABLE:FALSE`, owner [UID:0000JR], emitters blank, formal C++ blank, raw islands mapped to exact child pages.
- `by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md`
  - Before: `82/88`, dirty/MarkDirty wording, C++ blank.
  - After: `87/91`, `GrafPort::EnableSoftwareBuffer`, field `m_usesSoftwareBuffer`, C++ populated.

Created child docs:
- `by-memory/0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers.md`
  - [UID:0003XB], `85/88`, owner/emitter [UID:00005V], C++ blank.
- `by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md`
  - [UID:0003XC], `85/88`, owner/emitter [UID:00005V], C++ blank.
- `by-memory/0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit.md`
  - [UID:0003XD], `85/88`, owner/emitter [UID:0000M2], C++ blank.
- `by-memory/0x004bb260-0x004bb2d5.SurfaceTileBufferBlitRaw.md`
  - [UID:0003XE], `83/87`, owner `NONE`, emitter blank, C++ blank.
- `by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md`
  - [UID:0003XF], `83/87`, owner `NONE`, emitter blank, C++ blank.

Updated support docs:
- `by-class/GrafPort.md`
  - Added `GrafPort::EnableSoftwareBuffer`, rejected dirty-flag wording for `this+0x94`, and linked the GrafPort raw-helper split children.
- `by-file/GrafPort.md`
  - Converted [UID:000160] to a non-emitting split/index entry, closed source placement to `NexusTK/render/GrafPort.cpp`, and linked [UID:0003XB]/[UID:0003XC].
- `by-file/NumericStringControlPane.md`
  - Added [UID:0003XD] as the fixed `9x11` glyph tile-context helper owned by NumericStringControlPane rather than GrafPort or FontImageLib.

Validator side effects:
- File-mode validator registration assigned UIDs `0003XB` through `0003XF`, resolved TMP references in [UID:000160], refreshed validator-owned autogen state, and updated generated autogen reports/source as part of the required split workflow.
- `by-memory/-coverage-report.md` was not edited directly; exact replacement/insertion rows are below.

## Heuristic / Inference Reanalysis And Validation

### [UID:00022M] field and method name

Best inference: `GrafPort::EnableSoftwareBuffer`, writing `m_usesSoftwareBuffer = true`.

Evidence checked:
- Raw body: `mov byte ptr [ecx+94h], 1; retn`.
- IDA decompile: `this[148] = 1`.
- One direct caller at `0x00468411`, after a GrafPort construction path.
- Constructor initializes `this+0x94` false.
- `UpdateRenderRegion` uses false for the DirectDraw surface path and true for the software heap-buffer path.
- Cleanup/destructor and paint/blit helpers use the same byte to release/select software backing state.

Rejected alternatives:
- Dirty flag: contradicted by Region-based dirty/exposed state and by the DirectDraw/software branch.
- DirectDraw lock flag: contradicted because DirectDraw is used when the byte is false.
- Pure owns-buffer flag: incomplete because the flag selects the software backing mode before allocation as well as controlling release.

Impact:
- Score can rise to `87/91`.
- The active C++ gate is met and the formal C++ block is safe.

### [UID:000160] aggregate/source shape

Best inference: [UID:000160] is a non-emitting split/index, not a source body.

Evidence checked:
- IDA function inventory shows core GrafPort methods plus many exact children and mixed adjacent source owners.
- The range includes GrafPort class methods, Surface paint/callback helpers, a NumericStringControlPane glyph helper, DAT file loading support, Surface line clipping, GrafPort glyph drawing, and raw no-entry islands.
- by-structure says broad mixed-owner convenience pages should be `RECONSTRUCTABLE:FALSE` once exact children carry source ownership.

Rejected alternatives:
- Keep [UID:000160] reconstructable/emitting with blank C++: rejected after split repair because exact children now carry source semantics and the parent would duplicate or cross owner boundaries.
- Emit one large parent C++ block: rejected because by-memory parent C++ cannot include child/sibling ranges and would mix GrafPort, Surface, NumericString, DAT, and no-owner raw helpers.
- Leave raw islands inside the parent as caveats: rejected by split-first workflow; exact children were created.

Impact:
- [UID:000160] is `86/90`, `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank.
- Formal parent C++ remains blank by rule, not because of an open blocker.

### Raw island closure

| Raw start | Final action | Best classification | Owner/emitter decision | Score impact |
| --- | --- | --- | --- | --- |
| `0x004b94f0` | Created [UID:0003XB] | `GrafPort::ReleasePrimarySurface` candidate inside state/clip helper cluster | [UID:00005V]/[UID:00005V], C++ blank because raw entry has no refs | child `85/88` |
| `0x004b9510` | Covered by [UID:0003XB] | raw setter for `this+0x20` surface/paint state | [UID:00005V]/[UID:00005V], C++ blank | child `85/88` |
| `0x004b9520` | Covered by [UID:0003XB] | raw setter for `this+0x28` state/stride/origin candidate | [UID:00005V]/[UID:00005V], C++ blank | child `85/88` |
| `0x004b9550` | Covered by [UID:0003XB] | raw view-origin offset helper | [UID:00005V]/[UID:00005V], C++ blank | child `85/88` |
| `0x004b9770` | Created [UID:0003XC] | raw effective clip-region builder | [UID:00005V]/[UID:00005V], C++ blank | child `85/88` |
| `0x004b99c0` | Already split [UID:00035C] | Surface palette callback forwarder | [UID:0000OC], no GrafPort action | existing child |
| `0x004bb260` | Created [UID:0003XE] | raw Surface/tile-buffer blit candidate | `CANONICAL_OWNER:NONE`, emitters blank; Surface is best forced candidate but not safe | child `83/87` |
| `0x004bb5b0` | Created [UID:0003XF] | raw two-color six-byte pattern pack helper | `CANONICAL_OWNER:NONE`, emitters blank; GrafPort is best forced candidate but not safe | child `83/87` |

Evidence checked for all raw starts:
- IDA `lookup_funcs` for modeled versus non-modeled boundaries.
- IDA `xrefs_to` for raw starts.
- Raw disassembly/byte behavior and adjacent padding.
- PE-level scan for absolute VA literals, RVA literals, and direct relative branches.
- Positive controls in the same scan found the direct call to [UID:00022M], three calls to `0x004b9530`, and 21 calls to `0x004b9580`, so the zero-hit raw-start result is meaningful.

### Non-GrafPort child ownership

- [UID:0003XD] belongs to [UID:0000M2] NumericStringControlPane because it is called from NumericString rendering and initializes a fixed `9x11` glyph tile context from the numeric font resource. GrafPort and FontImageLib ownership are rejected.
- [UID:0003XE] cannot be safely assigned despite a Surface-leaning behavior shape. It has no modeled entry, xrefs, pointer/branch hits, or caller path. It is documented at `83/87` with no owner/emitter.
- [UID:0003XF] cannot be safely assigned despite adjacency to `GrafPort::DrawGlyph`. It has no modeled entry, xrefs, pointer/branch hits, or caller path. It is documented at `83/87` with no owner/emitter.

### Field/source placement validation

- `this+0x94` is `m_usesSoftwareBuffer`.
- `this+0x98` is the software buffer pointer.
- `this+0x9c` is software stride/pitch.
- `word_66DA94` in `UpdateRenderRegion` is [UID:0000SU] `g_screenWidth`, not `g_maxSurfacePitch`.
- DirectDraw device lifetime remains [UID:0000IW] DirectX.
- Generic callback/presentation helpers remain [UID:0000OC] Surface.
- GrafPort receiver draw/text/glyph helpers remain [UID:00005V] / [UID:0000JR].

## First-Draft C++ Recommendation

[UID:00022M] formal C++ is populated and should remain:

```cpp
void GrafPort::EnableSoftwareBuffer()
{
    m_usesSoftwareBuffer = true;
}
```

Why safe:
- The page is reconstructable, has a valid emitter route through [UID:00005V] to [UID:0000JR], and the combined score is `89`.
- The exact code range is a single byte write plus return.
- The field role is proven by constructor/update/destructor/paint/blit evidence.

Do not populate formal C++ for [UID:000160]. It is now `RECONSTRUCTABLE:FALSE`.

Do not populate formal C++ for [UID:0003XB], [UID:0003XC], or [UID:0003XD] despite their combined score and emitter routes:
- [UID:0003XB] and [UID:0003XC] include raw no-entry helpers and descriptive field/API names.
- [UID:0003XD] needs the exact tile-context type and helper name before final source is safe.

Do not populate formal C++ for [UID:0003XE] or [UID:0003XF]. They are below the code gate and intentionally no-owner/non-emitting.

## Exact Coverage Row Changes

Apply these under the GrafPort section of `by-memory/-coverage-report.md` in address order. Replace existing rows for [UID:00022M] and [UID:000160]. Insert rows for [UID:0003XB], [UID:0003XC], [UID:0003XD], [UID:0003XE], and [UID:0003XF] at the shown address positions. Preserve existing padding rows.

```md
    - [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md) 0x004b8be0-0x004b8be8 | method | GrafPortEnableSoftwareBuffer : reconstructable : 87% : very-strong : Exact GrafPort software-buffer mode setter; raw bytes write `1` to `this+0x94`, constructor/update/destructor/paint/blit evidence proves the field is `m_usesSoftwareBuffer`, the only direct caller is `0x00468411`, and formal C++ is populated as `GrafPort::EnableSoftwareBuffer`.
    - [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md) 0x004b8bf0-0x004bb8c4 | split/index | GrafPort physical split index : not_reconstructable : 86% : very-strong : B003 split repair converts this mixed overbroad GrafPort neighborhood to a non-emitting index; exact children now carry GrafPort, Surface, NumericString, DAT, glyph/text, and no-owner raw-helper source decisions, and all formerly open raw islands are either split or already documented.
    - [UID:0003XB][0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers](by-memory/0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers.md) 0x004b94f0-0x004b95d5 | method-cluster/raw-code | GrafPortStateAndClipRawHelpers : reconstructable : 85% : strong : Split GrafPort helper cluster covering raw no-entry surface release/state setters/view-origin helper plus modeled view-origin, clip-state, and draw-enabled helpers; IDA and PE scans prove no raw-start entry refs, so owner/emitter route to GrafPort is set but formal C++ remains blank.
    - [UID:0003XC][0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease](by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md) 0x004b9770-0x004b981e | method-pair/raw-code | GrafPortEffectiveClipAndBackingRelease : reconstructable : 85% : strong : Split GrafPort effective-clip raw helper and modeled backing-release helper; `0x004b9770` has no IDA/PE entry refs, `0x004b97d0` releases software buffer and DirectDraw surface storage, and formal C++ remains blank because Region/type names are source-descriptive rather than symbol-proven.
    - [UID:0003XD][0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit](by-memory/0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit.md) 0x004bb1e0-0x004bb252 | helper | NumericStringGlyphTileContextInit : reconstructable : 85% : strong : Live modeled helper called by NumericStringControlPane render code; initializes a fixed 9x11 numeric glyph tile context from `9X11FONT.BIN`, rejects GrafPort and FontImageLib ownership, and routes through NumericStringControlPane with formal C++ blank until exact tile-context type names are proven.
    - [UID:0003XE][0x004bb260-0x004bb2d5.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d5.SurfaceTileBufferBlitRaw.md) 0x004bb260-0x004bb2d5 | raw code | SurfaceTileBufferBlitRaw : reconstructable : 83% : strong : Exact raw Surface/tile-buffer blit candidate; raw disassembly shows allocation/rect copy/palette/default-context setup and dispatch through `dword_69B3E8`, but IDA and PE scans find no live entry or safe direct owner, so owner is `NONE`, emitters are blank, and C++ remains blank.
    - [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md) 0x004bb5b0-0x004bb5d1 | raw code | GrafPortPatternPackRaw : reconstructable : 83% : strong : Exact raw three-argument six-byte two-color pattern pack helper between LineClipHelpers and GrafPortDrawGlyph; GrafPort/glyph adjacency is the best forced candidate, but IDA and PE scans find no live entry or safe direct owner, so owner is `NONE`, emitters are blank, and C++ remains blank.
```

## Validator Results

Commands run:

> Executable block R001 was removed from this report and preserved verbatim in [000160-00022M-grafport-source-quality-removed.md](000160-00022M-grafport-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Results:
- All scoped validator runs exited `0`.
- Parent validation assigned UIDs `0003XB` through `0003XF` and resolved twelve TMP references.
- Subsequent file-mode validations reported `ok:1` for each scoped file.
- The final unresolved-language audit returned no matches for the scoped open-question/future-work patterns above.
- Validator output also reported the pre-existing stale registry issue `autogen_registry_stale 00016P ... CachedHashTableRawHelpers.md registered file is missing`; this was not introduced by the GrafPort split and did not fail validation.

## Changed Files

Created:
- `by-memory/0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers.md`
- `by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md`
- `by-memory/0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit.md`
- `by-memory/0x004bb260-0x004bb2d5.SurfaceTileBufferBlitRaw.md`
- `by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md`

Modified:
- `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`
- `by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md`
- `by-class/GrafPort.md`
- `by-file/GrafPort.md`
- `by-file/NumericStringControlPane.md`
- `tools/leaser/Agents/Agent-B003/research/000160-00022M-grafport-source-quality.md`

Validator-owned generated side effects:
- Validator file-mode registration/autogen refresh updated validator-owned generated outputs/reports during the split workflow. The manual `by-memory/-coverage-report.md` was not edited directly.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/000160-00022M-grafport-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"000160"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000160-00022M-grafport-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/000160-00022M-grafport-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000160"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
