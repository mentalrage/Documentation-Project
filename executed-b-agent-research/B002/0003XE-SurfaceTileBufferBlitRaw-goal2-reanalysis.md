** TARGET-REPORT-UID:0003XE **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003XE **
# 0003XE SurfaceTileBufferBlitRaw Goal 2 Reanalysis

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003XE] `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP CODE`, and score `84/88`.
- Final disposition: source-authored raw helper remains reconstructable but no-owner/non-emitting. The best forced family is Surface/render tile-buffer support, inferred/descriptive, but not assignment-safe.
- Required action: update the target page only if the supervisor wants this 2026-06-18 recheck recorded; no required by-memory coverage row change beyond keeping the current row state.
- Confidence: strong for range, bytes, negative PE liveness, callback/palette dependency, and rejected alternatives; medium for original source placement because no caller, pointer table, constructor, vtable, or receiver type route is known.

## Target

- Target UID: `0003XE`
- Target path: `by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md`
- Assignment: current Goal 2 no-owner/non-emitting source-quality reanalysis for [UID:0003XE].
- Current coverage row: `by-memory/-coverage-report.md` under the `0x004b8bf0-0x004bb8c4` GrafPort split/index section, row records reconstructable `84% : strong`, owner `NONE`, blank emitters, no C++.
- Current scores and parent state: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:` blank.
- Address/range: raw body `0x004bb260-0x004bb2d7`; `0x004bb252-0x004bb260` and `0x004bb2d7-0x004bb2e0` are `0xcc` padding envelopes.

## Executive Recommendation

Do not raise [UID:0003XE] through the completion gate yet. The body is clearly source-shaped project code, but the owner/emitter blocker is concrete: current binary bytes still provide no entry reference, no direct branch/call, no pointer literal, no table slot assignment, no constructor/vtable route, and no receiver type proof. The strongest descriptive source direction is a private Surface tile-scratch/tile-buffer blit helper, but assigning it to [UID:0000OC] `Surface` would rely on dependency and behavior family only.

The current `84/88` score is still the correct cap. Completion should remain below `85` because owner/emitter placement is not defensible. Confidence can remain `88` because the exact range, behavior model, and negative liveness evidence are strong.

## Supervisor Active Recheck

- The supervisor specifically asked for a fresh Goal 2 reanalysis because the live generated row is still no-owner, blank-emitter, reconstructable, and below the completion gate at `84/88`.
- No split repair is required. The earlier range correction to `0x004bb260-0x004bb2d7` is already applied, and the raw body is an exact child of the mixed [UID:000160] GrafPort split/index.
- Live IDA MCP could not be reached from this session at `http://127.0.0.1:13337/mcp`; `Invoke-WebRequest` returned `Unable to connect to the remote server`. I therefore revalidated the current IDA-backed documentation against the original executable bytes at `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` and recorded live-MCP validation commands below.

## Inference Research Guidance Check

`by-structure.md` separates semantic ownership from emitter routing and requires final C++ only when a reconstructable item has a confirmed emitter route and `(COMPLETION + CONFIDENCE) / 2 > 85`. [UID:0003XE] has average `86`, but fails the emitter route and source-shape gates. `inference_research.md` also warns that adjacency and consumer xrefs alone are weak ownership evidence; the report therefore treats callback-table and palette use as dependencies, not proof of source declaration ownership.

Existing docs were treated as leads, not authority. The current page, the prior B003 split report, and the prior B002 raw-island report are validated where they match the fresh PE scan and current support docs. Their no-owner conclusion remains correct, but this report adds the current comparison against assigned no-entry raw helpers such as [UID:00035C] and explains why that comparison does not justify assignment here.

## Heuristic / Inference Reanalysis And Validation

Issues checked:

- Raw-helper liveness: fresh PE scan found `0` absolute VA dword hits, `0` RVA dword hits, and `0` direct `E8/E9/0F 8*` or short-conditional branch hits for `0x004bb260` and for the corrected end `0x004bb2d7`. Positive controls worked: `0x004bb2e0` has two direct rel32 call hits, `0x004bb5e0` has two, `0x004b99f0` has three, `0x0069b3e8` has 114 absolute data/code operand hits, and callback targets `0x004bc090` / `0x004c0f80` each have two absolute target hits from the callback initializer/table context. This makes the zero-hit result meaningful rather than a scan blind spot.
- Function/model boundary: current docs and map evidence agree there is no modeled/public `sub_4BB260`, while the successor `sub_4BB2E0` is a modeled/public function. Bytes at `0x004bb2d4` are `c2 08 00`, so the current half-open end `0x004bb2d7` is correct.
- Behavior model: the body preserves `this` in `esi`, preserves the source descriptor in `edi`, calls `GetMemoryMan` and `ReallocateOrThrow`, calls a receiver vtable slot `+0x0c` with `record + 0x10`, resolves a null palette through [UID:0000RW] `g_pPaletteLib` / `PaletteLib::GetCurrentPalette`, computes `(record[0x1c] - record[0x14]) * record[0x0c] * 2`, resizes `this+0x20`, stores source pitch/row width at `this+0x28`, copies the source rectangle to `this+0x2c`, and dispatches [UID:0000TN] `SurfaceRenderCallbackTable` slot `dword_69B3E8`.
- Receiver/type model: best descriptive receiver is still `SurfaceTileScratch` or `SurfaceTileBuffer`, not proven `Surface` and not proven `GrafPort`. The vtable call proves the receiver is object-like, but no constructor, vtable, allocation site, or caller identifies the class.
- Field/global/helper names: keep `this+0x20` as an owned/resizable 16bpp scratch buffer, `this+0x28` as copied source pitch/row width, `this+0x2c` as cached source rectangle, stack arg 2 as optional `DLPalette*` or palette/render context, `dword_69B3E8` as a dependency on the primary tile/frame blit callback slot. These are descriptive, not original names.
- Surface candidate: strongest forced family because the helper is 16bpp render-buffer work, uses current palette fallback, and calls `dword_69B3E8`, the primary tile/frame/sprite Surface render slot. Rejected as canonical owner because dependency and behavior family do not prove original direct source ownership, and the mixed neighborhood has multiple non-Surface children.
- GrafPort candidate: rejected. Physical containment inside the former GrafPort aggregate is a split artifact. The known GrafPort class/page owns draw state, text/glyph helpers, clip state, and backing storage; this raw receiver's `+0x20/+0x28/+0x2c` scratch-buffer fields are not proven GrafPort fields, and no GrafPort method calls the raw start.
- NumericString candidate: rejected. [UID:0003XD] immediately precedes the target and is a live NumericString fixed `9x11` glyph tile-context helper, but [UID:0003XE] has no NumericString caller, no `9x11`/`99` glyph constants, no `9X11FONT.BIN` edge, and no font-resource route.
- LineClip candidate: rejected. [UID:00016H] starts at `0x004bb2e0`, has two software line-callback callers, and performs Liang-Barsky clipping. [UID:0003XE] is buffer/palette/callback setup and does not share line geometry behavior.
- SurfaceRenderCallbackTable ownership: rejected. The helper calls slot `dword_69B3E8` at `0x004bb2ca`; it is not assigned into the callback table. Table target evidence points to `0x004bc090` and `0x004c0f80`, not to this raw body.
- PaletteLib ownership: rejected. `g_pPaletteLib` and `PaletteLib::GetCurrentPalette` are service dependencies. PaletteLib owns palette selection/lifecycle, not a tile scratch blit helper.
- New helper-file alternative: a descriptive `render/SurfaceTileScratch.cpp`, `render/SurfaceBlitScratch.cpp`, or broader `render/SurfaceBlitters.cpp` could fit the body if a caller/constructor appears later. Creating a new owner now is rejected because one unreferenced raw body with no vtable, constructor, sibling cluster, or table route would overfit the evidence.
- Split/merge/range correctness: no further split is recommended. The raw body is compact, begins after fourteen `0xcc` bytes, ends after the full `retn 8`, and is followed by nine `0xcc` bytes before the live LineClip function. Merging into [UID:00016H] LineClip or [UID:0003XD] NumericString would create a mixed-owner page.
- Comparison with assigned no-entry raw helpers: [UID:00035C] has no raw-start refs but sits inside the coherent `0x004b9820-0x004ba24a` SurfacePaintHelpers cluster between `RenderTileFrame` and `ForwardToTileFrameBlitHelper`; [UID:0003XB]/[UID:0003XC] sit inside coherent GrafPort state/clip clusters and use GrafPort receiver fields. [UID:0003XE] does not have equivalent clustering because its immediate neighbors are NumericString and Surface LineClip, while the wider parent also contains DAT and GrafPort text/glyph code. That difference is why assignment remains unsafe here.

Best guess if forced: a private Surface/render tile scratch-buffer blit helper, with source-facing descriptive name `SurfaceTileScratchBlitRaw` or the current `SurfaceTileBufferBlitRaw`. This is an inferred/descriptive family only.

Remaining blockers and score/source-placement/C++ impact:

- Completion remains capped below `85` because no canonical owner or emitter route is defensible.
- Confidence remains `88` because the behavior and negative liveness evidence are well supported.
- No `RECONSTRUCTION_CPP CODE` should be populated. The item lacks a nonblank emitter route, lacks a proven receiver type, and lacks final source names/signatures.

## Evidence Standards Used

- Fresh PE byte scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`.
- Current by-* documentation and executed B-agent reports, treated as documentation evidence.
- Current support docs for [UID:000160] GrafPort split index, [UID:0000OC] Surface, [UID:0000JR]/[UID:00005V] GrafPort, [UID:0000TN]/[UID:0001PI] SurfaceRenderCallbackTable, [UID:0000RW] g_pPaletteLib, [UID:0001E6] PaletteLibMethodCluster, [UID:0003XD] NumericStringGlyphTileContextInit, and [UID:00016H] LineClipHelpers.
- Negative evidence: no direct branch/call/pointer entry route, no callback-table registration, no receiver/vtable/constructor route, and no coherent source-family cluster sufficient to replace those missing routes.

## Binary / IDA-Backed Facts

Fresh local PE scan results:

| Target | Absolute VA dword hits | RVA dword hits | Direct branch/call hits | Meaning |
| --- | ---: | ---: | ---: | --- |
| `0x004bb260` | 0 | 0 | 0 | no visible entry/caller/pointer route |
| `0x004bb2d7` | 0 | 0 | 0 | no pointer/branch to corrected end |
| `0x004bb2e0` | 0 | 0 | 2 | positive control: live LineClip entry is detectable |
| `0x004bb5b0` | 0 | 0 | 0 | nearby raw pattern helper also orphaned |
| `0x004bb5e0` | 0 | 0 | 2 | positive control: live GrafPortDrawGlyph entry is detectable |
| `0x004b99c0` | 0 | 0 | 0 | assigned raw Surface forwarder also has no entry refs, but stronger cluster evidence |
| `0x004b99f0` | 0 | 0 | 3 | positive control: live Surface forwarder has direct callers |
| `0x0069b3e8` | 114 | 0 | 0 | callback slot broadly referenced |
| `0x004bc090` | 2 | 0 | 0 | compat callback-table target is detectable |
| `0x004c0f80` | 2 | 0 | 0 | RGB565 callback-table target is detectable |

Raw byte facts from the PE scan:

- `0x004bb252-0x004bb260`: fourteen `0xcc` bytes.
- `0x004bb260`: raw prologue begins `55 8b ec 53 56 57 8b f1 ...`.
- `0x004bb2d4-0x004bb2d6`: `c2 08 00`, the full `retn 8` immediate.
- `0x004bb2d7-0x004bb2e0`: nine `0xcc` bytes.
- `0x004bb2e0`: live LineClip function prologue begins.

IDA-backed documentation facts retained from current docs:

- `lookup_funcs` previously reported no modeled function at `0x004bb260`; the current map/export has a public `sub_4BB2E0` successor but no `sub_4BB260`.
- `xrefs_to 0x004bb260` previously reported zero direct refs.
- Current support docs record the call to `dword_69B3E8` at `0x004bb2ca`, the null-palette fallback through `g_pPaletteLib` / `PaletteLib::GetCurrentPalette`, and the scratch-buffer field model.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004bb1e0-0x004bb252` | [UID:0003XD] `NumericStringGlyphTileContextInit` | fixed `9x11` numeric glyph context helper | true | [UID:0000M2] NumericStringControlPane | `85/88` | live modeled predecessor, different owner |
| `0x004bb260-0x004bb2d7` | [UID:0003XE] `SurfaceTileBufferBlitRaw` | raw tile scratch-buffer blit helper candidate | true | `NONE` | `84/88` | current target, no owner/emitter |
| `0x004bb2e0-0x004bb5a5` | [UID:00016H] `LineClipHelpers` | software-render line clip helpers | true | [UID:0000OC] Surface | `86/89` page metadata, coverage row stale lower | live successor with two callback callers |
| `0x004bb5b0-0x004bb5d1` | [UID:0003XF] `GrafPortPatternPackRaw` | raw two-color pattern packer | true | `NONE` | `84/88` | separate no-owner raw island |
| `0x004bb5e0-0x004bb7e0` | [UID:00016I] `GrafPortDrawGlyph` | GrafPort glyph drawer | true | GrafPort family | coverage row `76/strong` | live modeled positive-control successor |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004bb260` | no direct PE branch/call/pointer/RVA hits found | no liveness route |
| `0x004bb2ca` | call through `dword_69B3E8` per current docs | Surface callback dependency, not owner |
| `0x0069b3e8` | 114 absolute operand hits in fresh PE scan | callback slot is broad and detectable |
| `0x004bc090` / `0x004c0f80` | two absolute hits each | actual callback-table targets for slot 2 are detectable; target is not one |
| `0x004bb2e0` | direct branch hits at `0x004bbc81`, `0x004c0b71` | LineClip positive control |
| `0x004bb5e0` | direct branch hits at `0x004bab57`, `0x004bac8a` | GrafPortDrawGlyph positive control |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page already records exact corrected range, scratch-buffer field model, `g_pPaletteLib` fallback, `dword_69B3E8` dependency, and no-owner/no-emitter policy.
- [UID:000160] GrafPort split index records the mixed physical parent and explicitly lists [UID:0003XE] as a Surface/render candidate without safe owner.
- [UID:0000OC] Surface records [UID:0003XE] as a reviewed no-owner orphan and says not to emit it under Surface until liveness is proven.
- [UID:0000TN] and [UID:0001PI] SurfaceRenderCallbackTable record [UID:0003XE] as a dependency caller of `dword_69B3E8`, not a table target.
- [UID:0003XD] and [UID:00016H] explain why the immediate neighbors have different owners and should not absorb this raw body.

Existing docs that are stale or require caution:

- Some coverage rows for nearby pages remain stale relative to page metadata, for example [UID:00035C] is assigned in its page but the coverage row still describes it as unassigned. Do not use that stale wording to justify assigning [UID:0003XE].
- Older reports used the obsolete `0x004bb260-0x004bb2d5` cut. The live target has already been corrected to `0x004bb260-0x004bb2d7`.

## Ranked Ownership Analysis

### 1. Surface / render tile-buffer support [UID:0000OC]

- Evidence for: `dword_69B3E8` slot 2 dependency, null-palette fallback through PaletteLib, 16bpp buffer sizing, rectangle copy, and adjacency to Surface-owned LineClip and later software-render callback families.
- Evidence against: no direct caller, no pointer/table registration, no constructor/vtable route, no proven `Surface` receiver type, and mixed local neighborhood with NumericString/DAT/GrafPort children.
- Decision: best forced family and descriptive source placement, but do not set canonical owner or emitter.

### 2. New private SurfaceTileScratch / SurfaceBlitScratch owner

- Evidence for: receiver-like object has retained scratch fields and a virtual prep slot, suggesting a small source-level helper class or private render context.
- Evidence against: no vtable page, constructor, allocation, caller, sibling methods, or source-file cluster proves the type. Creating a new owner for one orphan body would be speculative.
- Decision: reject for now. Reopen only if a vtable, constructor, pointer literal, or caller appears.

### 3. GrafPort [UID:00005V] / [UID:0000JR]

- Evidence for: physical parent range is the GrafPort split index.
- Evidence against: physical range is explicitly mixed; accepted GrafPort field model does not identify `this+0x20/+0x28/+0x2c` as this helper's scratch fields; behavior is tile-buffer/callback/palette setup, not GrafPort text, clip, or backing-storage management; no GrafPort method calls the raw start.
- Decision: reject.

### 4. SurfaceRenderCallbackTable [UID:0000TN]

- Evidence for: target calls `dword_69B3E8`.
- Evidence against: the table's source-declared storage and initializer targets are separate. Slot 2 targets are `0x004bc090` and `0x004c0f80`; [UID:0003XE] is a consumer/caller, not a stored callback.
- Decision: reject as owner; keep as dependency.

### 5. PaletteLib / g_pPaletteLib

- Evidence for: null palette is resolved through `g_pPaletteLib` and `PaletteLib::GetCurrentPalette`.
- Evidence against: broad service dependency only; PaletteLib owns palette selection, not the render scratch helper.
- Decision: reject as owner; keep as dependency.

### 6. NumericStringControlPane / FontImageLib

- Evidence for: immediate predecessor is NumericString glyph context setup.
- Evidence against: no caller, no fixed `9x11` or `99` glyph constants, no `9X11FONT.BIN` edge, no NumericString receiver, and no FontImageLib metric/decode calls.
- Decision: reject.

### 7. LineClipHelpers

- Evidence for: immediate successor is Surface-owned line clipping.
- Evidence against: behavior does not overlap; target uses buffer/palette/tile callback, while LineClip uses geometry and has two software line-callback callers.
- Decision: reject.

## Proposed New File / Grouping

No new owner/file should be created now. If future evidence proves liveness, the likely narrow grouping would be a Surface/render blitter support unit, not a standalone one-item file. Candidate contents would include Surface render wrappers such as [UID:000166] `ForwardToTileFrameBlitHelper`, [UID:000167] `SurfaceSpriteBlitHelper`, [UID:00016H] `LineClipHelpers`, and the exact software callback targets selected through [UID:0000TN]. [UID:0003XE] could belong near that family only after a caller, constructor/vtable, or table route proves it is actually retained source and identifies its receiver.

Rejected candidate related items:

- [UID:0003XD] belongs to NumericStringControlPane.
- [UID:0003XF] is best GrafPort glyph/text family but remains no-owner.
- [UID:00016I] belongs to GrafPort text/glyph, not Surface blitter setup.
- [UID:0000RW] / PaletteLib pages are dependencies, not contents of a new Surface helper file.

## Negative Evidence Summary

- Direct xref/entry route: none found.
- Table route: none found; callback-table slot 2 targets are other functions.
- Receiver route: none found; no constructor/vtable/allocation site identifies `this`.
- Source-family route: Surface is strongest but only by behavior/dependency, while local adjacency is mixed.
- Split route: no remaining mixed bytes inside the target and no merge target is behavior-compatible.
- Emitter route: none, because no safe source owner or final source shape exists.

## Recommended by-* Document Changes

Metadata for [UID:0003XE] should remain exactly:

```text
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended prose to add to the target page under `## Evidence`:

```markdown
- 2026-06-18 B002 local PE recheck against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found zero absolute VA dword hits, zero RVA dword hits, and zero direct branch/call hits for `0x004bb260` and `0x004bb2d7`. Positive controls in the same scan found two direct rel32 callers of `0x004bb2e0`, two of `0x004bb5e0`, three of `0x004b99f0`, 114 absolute references to `0x0069b3e8`, and callback-table target literals for `0x004bc090` / `0x004c0f80`, so the raw-entry zero-hit result remains meaningful. Live IDA MCP was unavailable in this session and should be rerun by the supervisor.
```

Recommended prose to add to the target page under `## Ownership Decision` after the first paragraph:

```markdown
The 2026-06-18 reanalysis compared this raw island with assigned no-entry raw helpers. [UID:00035C] is assignment-stronger because it is embedded inside the coherent SurfacePaintHelpers cluster between live Surface wrappers, while [UID:0003XB] and [UID:0003XC] are embedded inside coherent GrafPort state/clip clusters with matching GrafPort receiver fields. This target's immediate neighborhood is mixed: NumericString glyph context setup precedes it and Surface line clipping follows it, while the broader parent also contains DAT and GrafPort text/glyph code. That mixed locality prevents upgrading dependency-based Surface placement into a canonical owner.
```

Recommended replacement for `## Score Rationale` in the target page:

```markdown
## Score Rationale

Recommended score remains `84/88`.

Completion stays below 85 because owner/emitter assignment, entry liveness, and receiver/source-file placement are not proven. Confidence remains strong for exact range, padding, source-shaped behavior, palette/callback dependencies, and negative PE liveness evidence. The best forced family is Surface/render tile-buffer support, but Surface placement is inferred/descriptive only and does not satisfy the current ownership/emitter gate.
```

Recommended `## Changes` entry to append to the target page:

```markdown
- 2026-06-18 B002 Goal 2 reanalysis:
  - Before: `84/88`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank formal C++.
  - After: unchanged at `84/88`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank formal C++.
  - Evidence: fresh PE byte scan rechecked absolute VA/RVA/direct-branch liveness for `0x004bb260` and positive controls, compared the target against assigned no-entry raw helpers, re-ranked Surface, GrafPort, NumericString, LineClip, PaletteLib, callback-table, and new-helper-file alternatives, and found no defensible owner/emitter route. Surface/render tile-buffer support remains the best forced family, inferred/descriptive only.
```

Support docs:

- No mandatory change is required for [UID:0000OC] `by-file/Surface.md`; it already carries the correct "reviewed no-owner orphan" caveat for [UID:0003XE].
- No mandatory change is required for [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md` or [UID:0001PI] `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`; both already state that [UID:0003XE] is a dependency caller, not a table target or ownership route.
- No mandatory change is required for [UID:000160] `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`; it already describes [UID:0003XE] as an exact no-owner child and the broader range as a non-emitting split/index.
- Optional support-doc sync, if the supervisor wants the new scan recorded outside the target page, is to add the same `2026-06-18 B002 Goal 2 reanalysis` change note to [UID:0000OC] `Surface.md` and [UID:000160] `GrafPort.md` with no score change.

## by-memory/-coverage-report.md Pending Supervisor Change

No mandatory coverage row change is required. The current row is directionally correct and already has the right metadata state: reconstructable, `84%`, strong confidence, owner `NONE`, blank emitters, C++ blank.

If the supervisor wants the row to reflect this reanalysis explicitly, replace the current [UID:0003XE] row with:

```markdown
    - [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) 0x004bb260-0x004bb2d7 | raw code | SurfaceTileBufferBlitRaw : reconstructable : 84% : strong : B002 2026-06-18 reanalysis keeps the corrected half-open range through the full `retn 8` at `0x004bb2d4-0x004bb2d6` and reconfirms no safe owner/emitter route. Fresh PE scan found no VA/RVA/direct-branch entry hits for `0x004bb260`, while positive controls found live calls to `0x004bb2e0`, `0x004bb5e0`, and `0x004b99f0`, 114 references to `0x0069b3e8`, and callback-target literals for `0x004bc090`/`0x004c0f80`. The body allocates/resizes a 16bpp scratch buffer at `this+0x20`, copies source pitch to `this+0x28`, caches a rectangle at `this+0x2c`, resolves null palette through `g_pPaletteLib` / `PaletteLib::GetCurrentPalette`, and dispatches `dword_69B3E8`; Surface/render tile-buffer support is the best forced family, inferred/descriptive only, so owner remains `NONE`, emitters blank, and C++ blank.
```

Before/after score recommendation:

- Before: `84/88`.
- After: `84/88`.

## First-Draft C++ / Precise No-Code Proof

Do not populate formal C++.

Source-facing descriptive pseudocode remains useful for reviewers but is not output-safe:

```cpp
// Descriptive only. Do not enter into RECONSTRUCTION_CPP.
void __thiscall SurfaceTileScratch::BlitTileBuffer(
    TileFrameDrawRecord* record,
    DLPalette* paletteOrNull);
```

No-code proof:

- The item has no nonblank `EMITTER_UIDS`, so it fails the strict by-structure C++ gate even though the score average is above `85`.
- The canonical owner is `NONE`; adding an emitter would implicitly choose a source route that the evidence does not prove.
- The receiver type is not proven; the strongest name `SurfaceTileScratch` is descriptive only.
- Final callback typedefs and record names remain unresolved.
- The body may be retained dead code or an unmodeled private helper; emitting it under Surface would overstate the evidence.

## Validation Needed

Supervisor should run these after any optional target-page or coverage-row update:

> Executable block R001 was removed from this report and preserved verbatim in [0003XE-SurfaceTileBufferBlitRaw-goal2-reanalysis-removed.md](0003XE-SurfaceTileBufferBlitRaw-goal2-reanalysis-removed.md). The archived block is non-authoritative and must not be executed.

Supervisor should also rerun live IDA MCP validation, because this session could not reach the server:

> Executable block R002 was removed from this report and preserved verbatim in [0003XE-SurfaceTileBufferBlitRaw-goal2-reanalysis-removed.md](0003XE-SurfaceTileBufferBlitRaw-goal2-reanalysis-removed.md). The archived block is non-authoritative and must not be executed.

Expected live IDA MCP checks:

```text
lookup_funcs 0x004bb260,0x004bb2e0,0x004bb5e0
xrefs_to 0x004bb260,0x004bb2e0,0x004bb5e0,0x0069b3e8
disasm or insn query for 0x004bb260-0x004bb2d7
search/py_eval pointer scan for little-endian VA `60 b2 4b 00`
```

Expected result: [UID:0003XE] remains `84/88`, `CANONICAL_OWNER:NONE`, blank emitters, blank formal C++.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B002/research/0003XE-SurfaceTileBufferBlitRaw-goal2-reanalysis.md`

Modified:

- None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003XE","source_path":"executed-b-agent-research/B002/0003XE-SurfaceTileBufferBlitRaw-goal2-reanalysis.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
