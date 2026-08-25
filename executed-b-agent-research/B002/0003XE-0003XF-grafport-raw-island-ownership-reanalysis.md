** TARGET-REPORT-UID:0003XE **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003XE **
# 0003XE / 0003XF GrafPort Raw Island Ownership Reanalysis

Assignment: `B002-goal2-grafport-raw-island-reanalysis-0003XE-0003XF-20260617`  
Agent: `B002`  
Mode: report-only; no by-* docs, generated reports/source, IDA DB, source files, or `by-memory/-coverage-report.md` were edited.

## Executive Recommendation

[UID:0003XE] should remain `CANONICAL_OWNER:NONE`, non-emitting, and formal C++ blank. The best source-family is still Surface/render tile-buffer support, not GrafPort class code, but current IDA and PE evidence still provides no live entry, pointer-table entry, caller, or safe direct owner. I do recommend correcting the exact range from `0x004bb260-0x004bb2d5` to `0x004bb260-0x004bb2d7` because the current half-open end cuts through the `retn 8` immediate. With that correction and the stronger field model below, score should move from `83/87` to `84/88`, still below the `85/85` owner/emitter/final-C++ gate.

[UID:0003XF] should also remain `CANONICAL_OWNER:NONE`, non-emitting, and formal C++ blank. The best forced source-family is GrafPort glyph/text support, but there is still no call from `GrafPortDrawGlyph`, no text-run edge, no callback slot entry, and no PE pointer/call evidence. I recommend raising only to `84/88` after adding the source-facing signature and rejection analysis below.

The prior B003 no-owner conclusion is validated for both targets. The material correction is the [UID:0003XE] range/padding boundary; the rest of this report adds the best defensible names, signatures, field/type models, and ranked owner rejections required by the current B-agent rules.

## Evidence Checked

IDA MCP evidence from the active IDB:

| Check | [UID:0003XE] `0x004bb260` | [UID:0003XF] `0x004bb5b0` |
| --- | --- | --- |
| `lookup_funcs` | no IDA function at entry | no IDA function at entry |
| `xrefs_to` entry | zero refs | zero refs |
| `xrefs_to` end/successor control | `0x004bb2e0` has live callers; raw entry does not | `0x004bb5e0` has live callers; raw entry does not |
| `insn_query` | complete source-shaped body ending in `retn 8` | complete three-argument body ending in `retn 0x0c` |
| `make_signature_for_range` | unique raw signature | unique raw signature |
| callback/global surface | data ref to `dword_69B3E8` inside raw body only | no globals/callees |

PE-aware scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

| VA scanned | absolute VA dword hits | RVA dword hits | direct `E8/E9/0F 8*` rel32 hits | Interpretation |
| --- | ---: | ---: | ---: | --- |
| `0x004bb260` | 0 | 0 | 0 | no PE-visible entry/caller/pointer evidence |
| `0x004bb2d5` | 0 | 0 | 0 | no accidental branch/pointer to old end |
| `0x004bb5b0` | 0 | 0 | 0 | no PE-visible entry/caller/pointer evidence |
| `0x004bb5d1` | 0 | 0 | 0 | no accidental branch/pointer to end |
| positive control `0x004bb2e0` | 0 | 0 | 2 | live line helper call surface is detectable |
| positive control `0x004bb5e0` | 0 | 0 | 2 | live glyph helper call surface is detectable |
| positive control `0x0069b3e8` | 114 | broad | 0 | callback slot is broadly referenced, but not an entry pointer to either raw helper |

The positive controls matter: the scan method finds real call surfaces for the neighboring modeled functions and broad data references for `SurfaceRenderCallbackTable`, so the zero-hit result for the raw starts is meaningful rather than a tool blind spot.

## [UID:0003XE] Behavior And Type Model

Exact source-shaped body:

- Preserves `this` in `esi` and `record`/source descriptor in `edi`.
- Calls [UID:0001BC] `GetMemoryMan` and [UID:0001BG] `ReallocateOrThrow`.
- Calls the receiver vtable slot `+0x0c` with `record + 0x10`, before allocating the scratch buffer.
- If the second stack argument is null, loads [UID:0000RW] `g_pPaletteLib` / `dword_67A7E0` and calls `0x00543d40`, documented in [UID:0001E6] as `PaletteLib::GetCurrentPalette`.
- Computes byte count as `(record[0x1c] - record[0x14]) * record[0x0c] * 2`.
- Reallocates `this+0x20`, stores the result back to `this+0x20`.
- Copies `record+0x0c` to `this+0x28`.
- Copies 16 bytes from `record+0x10` to `this+0x2c`.
- Calls `dword_69B3E8` with the source record, source rect pointer, cached rect pointer, zero, palette/current palette, and zero.
- Returns with `retn 8`.

Best descriptive name/signature, not safe for formal source output:

```cpp
// Descriptive only; do not enter into formal RECONSTRUCTION_CPP.
void __thiscall SurfaceTileScratch::BlitTileBuffer(
    TileFrameDrawRecord* record,
    DLPalette* paletteOrNull);
```

Best field/type directions:

| Item | Best defensible meaning |
| --- | --- |
| `this+0x20` | owned/resizable 16bpp scratch pixel buffer |
| `this+0x28` | copied source pitch/row-width field from `record+0x0c` |
| `this+0x2c` | cached/copy of source draw rectangle from `record+0x10` |
| `record+0x0c` | row width or pitch in pixels, used with 2-byte pixels |
| `record+0x10..0x1f` | source/draw rectangle passed to receiver prep and callback |
| `record+0x14` / `record+0x1c` | vertical bounds used to compute height |
| stack arg 2 | optional `DLPalette*` or palette/render context; null means `PaletteLib::GetCurrentPalette()` |
| `dword_69B3E8` | [UID:0000TN] `SurfaceRenderCallbackTable` primary frame/tile blit callback slot, dependency only |

The current page name `SurfaceTileBufferBlitRaw` remains acceptable. If renamed for source quality, `SurfaceTileScratchBlitRaw` is slightly better because the receiver is a small scratch/buffer object, not proven to be `Surface` or `GrafPort`.

## [UID:0003XF] Behavior And Type Model

Exact source-shaped body:

```text
out[0] = secondByte
out[1] = firstByte
out[2] = secondByte
out[3] = firstByte
out[4] = firstByte
out[5] = secondByte
```

It has three stack arguments and returns with `retn 0x0c`; there is no `this`, no global, no callee, and no callback-table involvement.

Best descriptive name/signature, not safe for formal source output:

```cpp
// Descriptive only; do not enter into formal RECONSTRUCTION_CPP.
static void PackTwoColorSixPixelPattern(
    unsigned char firstByte,
    unsigned char secondByte,
    unsigned char* outPattern);
```

Best semantic direction: a two-color, six-byte mini pattern packer likely used by old glyph/pixel drawing code. The exact order `{second, first, second, first, first, second}` does not match line clipping, allocator glue, destructor glue, thunking, or callback dispatch. It looks source-authored and retained, but unreferenced by currently visible code.

## Ownership Candidate Ranking

### [UID:0003XE]

1. [UID:0000OC] `Surface` / render tile-buffer helper family: best forced source-family. Evidence is `dword_69B3E8`, `g_pPaletteLib`, 16bpp scratch-buffer sizing, rect copy, and current-palette fallback. Rejected for canonical ownership because the helper is not a callback-table target, has no caller or pointer literal, and its receiver type is not proven to be the documented `Surface` class.
2. [UID:0000TN] `SurfaceRenderCallbackTable`: dependency, not owner. The helper calls callback slot `dword_69B3E8`; the table owns dispatch configuration, not this unreferenced caller body.
3. [UID:00005V]/[UID:0000JR] `GrafPort`: physical locality only. Rejected because known GrafPort methods do not call this entry, accepted GrafPort field layout does not prove `this+0x20/+0x28/+0x2c`, and the behavior is a tile-buffer preparation wrapper rather than pane-backed port state.
4. NumericString/glyph/tile helper family: rejected. [UID:0003XD] immediately precedes this target, but it has a live NumericString caller and fixed 9x11 glyph context behavior; [UID:0003XE] has no NumericString constants, caller, or font-resource edge.
5. Line clip helpers: rejected. Successor [UID:00016H] is live Liang-Barsky line clipping; [UID:0003XE] is buffer/palette/callback dispatch.
6. New narrow render helper file: not justified now. A new file or class for one uncalled raw body would overfit without a caller, table registration, type, or sibling cluster.
7. No-owner/non-emitting: current best policy.

### [UID:0003XF]

1. [UID:00005V]/[UID:0000JR] `GrafPort` glyph/text support: best forced source-family. Evidence is immediate adjacency to [UID:00016I] `GrafPortDrawGlyph` and a tiny two-color pattern consistent with glyph/pixel preparation. Rejected for canonical ownership because `GrafPortDrawGlyph` and its text-run callers do not call `0x004bb5b0`, and PE scans find no entry or pointer.
2. [UID:0000OC] `Surface`: plausible low-level pixel helper family, but weaker than GrafPort because no callback slot, surface state, rectangle, palette, or render-table dependency appears in the body.
3. NumericString/glyph/tile helper family: plausible from glyph semantics but rejected because there is no edge from [UID:0003XD], NumericString rendering, or font image helpers.
4. [UID:00016H] LineClipHelpers: rejected. The helper sits after the line helper range but is byte-pattern packing, not clipping or geometry.
5. Compiler artifact: rejected as the primary classification. The body is not a thunk, adjustor, scalar destructor, security-cookie helper, RTTI glue, or CRT wrapper. It is source-shaped retained support code.
6. No-owner/non-emitting: current best policy.

## Heuristic / Inference Reanalysis And Validation

Best defensible source directions:

- [UID:0003XE] is a source-authored, retained Surface/tile-buffer scratch blit helper or private support method. It is not safe to call it `Surface::...` or `GrafPort::...` because the entry is not modeled, no direct caller exists, and no table stores its address. The safest source-facing name direction is `SurfaceTileScratchBlitRaw` or retain current `SurfaceTileBufferBlitRaw`.
- [UID:0003XF] is a source-authored retained two-color six-pixel pattern packer. The safest source-facing name direction is `PackTwoColorSixPixelPattern`, with GrafPort glyph/text support as the best forced family but not a canonical owner.

Evidence checked:

- Current IDA function lookup, xrefs, callee/caller facts, raw instruction query, and signature uniqueness.
- Current `dword_69B3E8` / `SurfaceRenderCallbackTable` xref surface, including the raw [UID:0003XE] data ref at `0x004bb2ca`.
- Neighbor modeled functions: [UID:0003XD] `NumericStringGlyphTileContextInit`, [UID:00016H] `LineClipHelpers`, and [UID:00016I] `GrafPortDrawGlyph`.
- Support docs for [UID:000160] `GrafPort`, [UID:0000OC] `Surface`, [UID:0000JR] `GrafPort`, [UID:00005V] `GrafPort`, [UID:0000TN] `SurfaceRenderCallbackTable`, [UID:0001PI] callback-table data, [UID:0001BC] `GetMemoryMan`, [UID:0001BG] `ReallocateOrThrow`, [UID:0000RW] `g_pPaletteLib`, and [UID:0001E6] `PaletteLibMethodCluster`.
- PE-level absolute VA, RVA, direct relative call/jump, and conditional-branch scans with positive controls.

Rejected alternatives:

- Promoting either target to a direct owner/emitter is rejected because no liveness or ownership proof exists.
- Treating [UID:0003XE] as callback-table-owned is rejected because it calls the callback table; it is not registered in the table.
- Treating [UID:0003XE] as GrafPort-owned is rejected because physical containment inside the old broad GrafPort range is a split artifact, not a source ownership proof.
- Treating [UID:0003XF] as [UID:00016I] `GrafPortDrawGlyph` child code is rejected because the successor function has live callers and does not branch to the raw island.
- Treating either body as compiler-generated glue is rejected because both decode to ordinary source-shaped helper bodies, not thunks/destructors/unwind stubs/security-cookie machinery.
- Creating a new source file/group solely for these raw bodies is rejected because it would create an owner without a live source boundary, sibling cluster, or caller.

Validation of existing docs and prior B003 report:

- B003 was correct that both entries have no IDA function object, no xrefs, no PE-visible entry references, no safe owner, and no formal C++ readiness.
- B003 was correct that [UID:0003XF] has exact `0x004bb5b0-0x004bb5d1` boundaries and is best interpreted as a small two-color pattern packer.
- B003 and the current [UID:0003XE] page are incomplete on exact range: the target's current half-open end `0x004bb2d5` cuts through `c2 08 00`. The full body is `0x004bb260-0x004bb2d7`; padding starts at `0x004bb2d7`, not `0x004bb2d5`.
- Existing Surface/GrafPort support docs remain directionally correct if they treat these as orphan raw children. They should not absorb either target into source output.

Score/source-placement/final-C++ impact:

- [UID:0003XE] can improve to `84/88` after the range correction and field/model text, but completion remains capped below `85` by no owner, no emitter, and no liveness evidence.
- [UID:0003XF] can improve to `84/88` after the better signature and owner-candidate rejection text, but completion remains capped below `85` by no owner, no emitter, and no liveness evidence.
- Neither target should receive `AUTOGEN_PARENT_UID`, `EMITTER_UIDS`, generated output, or formal C++.

## First-Draft C++ Recommendation

Do not populate formal `RECONSTRUCTION_CPP` for either target.

Reasons:

- [UID:0003XE] currently needs a supervisor-owned range rename to include the complete `retn 8`, and it still has no live entry, no owner, no emitter, and no proven receiver type.
- [UID:0003XF] has an exact small body, but still has no caller/owner/emitter and only a descriptive name. Emitting a standalone helper into GrafPort or Surface would make source ownership more certain than the evidence supports.

The pseudocode in the behavior sections is only a source-facing model for future reviewers. It should not be copied into the formal C++ block.

## Exact Metadata Recommendations

[UID:0003XE]:

```text
Path/title/range: rename by-memory/0x004bb260-0x004bb2d5.SurfaceTileBufferBlitRaw.md
to by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md

*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended [UID:0003XE] covered-range replacement:

```markdown
| `0x004bb252-0x004bb260` | padding before page | fourteen `0xcc` bytes after [UID:0003XD][0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit](by-memory/0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit.md) |
| `0x004bb260-0x004bb2d7` | raw code | allocates or resizes the owned 16bpp scratch buffer at `this+0x20`, copies source pitch/row width to `this+0x28`, copies the source rectangle to `this+0x2c`, resolves a null palette through [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md) / `PaletteLib::GetCurrentPalette`, and dispatches through [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `dword_69B3E8`; full range includes the `retn 8` immediate at `0x004bb2d4-0x004bb2d6` |
| `0x004bb2d7-0x004bb2e0` | padding after page | nine `0xcc` bytes before [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) |
```

[UID:0003XF]:

```text
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended [UID:0003XF] behavior/signature text to add:

```markdown
Best descriptive source-facing signature, not for formal C++ emission:

`static void PackTwoColorSixPixelPattern(unsigned char firstByte, unsigned char secondByte, unsigned char* outPattern);`

The helper writes `{secondByte, firstByte, secondByte, firstByte, firstByte, secondByte}` and returns with `retn 0x0c`. GrafPort glyph/text support is the best forced family from adjacency to [UID:00016I], but no caller, pointer-table entry, or PE-visible entry reference proves ownership.
```

## Supervisor-Owned Coverage Row Text

Replace the current [UID:0003XE] row in `by-memory/-coverage-report.md` with:

```markdown
    - [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) 0x004bb260-0x004bb2d7 | raw code | SurfaceTileBufferBlitRaw : reconstructable : 84% : strong : B002 reanalysis corrects the half-open end to include the full `retn 8` immediate at `0x004bb2d4-0x004bb2d6`; current IDA and PE scans still find no xrefs, VA/RVA hits, direct rel32 calls, pointer-table entry, or safe owner. Source-shaped helper allocates/resizes a 16bpp scratch buffer at `this+0x20`, copies source pitch to `this+0x28`, caches a rectangle at `this+0x2c`, resolves null palette through `g_pPaletteLib` / `PaletteLib::GetCurrentPalette`, and dispatches `dword_69B3E8`; Surface/render tile-buffer support is best forced family, but owner remains `NONE`, emitters blank, and C++ blank.
```

Replace the current [UID:0003XF] row in `by-memory/-coverage-report.md` with:

```markdown
    - [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md) 0x004bb5b0-0x004bb5d1 | raw code | GrafPortPatternPackRaw : reconstructable : 84% : strong : B002 reanalysis confirms the exact unique stdcall-like helper that writes a six-byte two-color pattern `{second, first, second, first, first, second}` and returns with `retn 0x0c`; current IDA and PE scans still find no xrefs, VA/RVA hits, direct rel32 calls, pointer-table entry, or safe owner. GrafPort glyph/text support is the best forced family from adjacency to `GrafPortDrawGlyph`, but owner remains `NONE`, emitters blank, and C++ blank.
```

No separate padding row currently exists in this coverage excerpt. If the supervisor adds or refreshes ignored padding rows, the post-[UID:0003XE] padding should be `0x004bb2d7-0x004bb2e0`, not `0x004bb2d5-0x004bb2e0`.

## Support Doc Recommendations

Update [UID:000160] `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md` split/index wording:

```markdown
- [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md): no-owner raw Surface/render tile-buffer scratch helper candidate. Range was corrected to include the complete `retn 8`; no IDA/PE caller, pointer-table entry, or safe owner was found.
- [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md): no-owner raw two-color six-byte pattern pack helper. GrafPort glyph/text is the best forced family, but no `GrafPortDrawGlyph` or text-run caller exists.
```

Add a caveat to [UID:0000OC] `by-file/Surface.md` or its open raw-helper list:

```markdown
- [UID:0003XE] remains a reviewed no-owner orphan: it uses `g_pPaletteLib`, `PaletteLib::GetCurrentPalette`, and `SurfaceRenderCallbackTable` slot `dword_69B3E8`, so Surface/render tile-buffer support is the best forced source family, but it is not a callback-table target and has no caller/pointer evidence. Do not emit it under Surface until liveness is proven.
```

Add a caveat to [UID:0000JR] `by-file/GrafPort.md` or [UID:00005V] `by-class/GrafPort.md`:

```markdown
- [UID:0003XF] remains adjacent to `GrafPortDrawGlyph` but unowned: it packs two input bytes into a six-byte pattern, yet current IDA and PE scans find no call from `GrafPortDrawGlyph`, no text-run caller, and no pointer-table entry. Keep it non-emitting/no-owner.
```

Add a dependency note to [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md`:

```markdown
- 2026-06-17 B002 reanalysis: orphan raw helper [UID:0003XE] calls slot `dword_69B3E8` at `0x004bb2ca`. This is dependency evidence only; the helper is not a callback-table target or owner candidate.
```

No generated source update is recommended.

## Validation Commands

After supervisor-owned edits:

> Executable block R001 was removed from this report and preserved verbatim in [0003XE-0003XF-grafport-raw-island-ownership-reanalysis-removed.md](0003XE-0003XF-grafport-raw-island-ownership-reanalysis-removed.md). The archived block is non-authoritative and must not be executed.

Also rerun the normal full rescore/coverage refresh used by the supervisor after metadata changes. The expected outcome is [UID:0003XE] and [UID:0003XF] at `84/88`, still `CANONICAL_OWNER:NONE`, with blank emitters and blank formal C++.

## Changed Files

Only this report was added:

- `tools/leaser/Agents/Agent-B002/research/0003XE-0003XF-grafport-raw-island-ownership-reanalysis.md`

## Blockers / Next Useful Follow-Up

No supervisor input is required to execute the recommendation. The only remaining blockers to an `85/85+` source/output route are concrete evidence gaps: a direct caller, a callback/pointer-table entry, an IDA-recognized function entry, unwind/registration evidence, or a source-adjacent sibling cluster proving a real owner. Without one of those, both targets should stay no-owner/non-emitting despite their source-shaped bodies.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003XE","source_path":"executed-b-agent-research/B002/0003XE-0003XF-grafport-raw-island-ownership-reanalysis.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
