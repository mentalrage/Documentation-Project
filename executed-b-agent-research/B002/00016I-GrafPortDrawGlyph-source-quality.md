** TARGET-REPORT-UID:00016I **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00016I GrafPortDrawGlyph Source-Quality Research

Agent: B002
Assignment: B002-report-00016I-grafport-draw-glyph-20260626
Date: 2026-06-26
Target: [UID:00016I] `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md`
Mode: report-only research accepted by supervisor; implementation callback applied on 2026-06-26.

## Executive Summary

[UID:00016I] is no longer a no-code target. The live IDA/MCP evidence now supports a first-draft formal `GrafPort::DrawGlyph` body at report-level detail. The stale blocker in the target page was a former "90/90+" caution; current project policy uses the combined-score/emitter gate, and this function already has a canonical owner/emitter route through [UID:00005V] `GrafPort` and [UID:0000JR] `GrafPort.md`.

The target should be updated from `COMPLETION:86`, `CONFIDENCE:89` to `COMPLETION:90`, `CONFIDENCE:92`, with `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00005V`, and `EMITTER_UIDS:00005V` unchanged. The score should not go above the low 90s until callback typedef spelling, original member spelling for the slot at `this+0x84`, and the FontImageLib method signatures are normalized across their owning docs.

Recommended implementation after supervisor acceptance: populate the formal C++ block in [UID:00016I], update the target evidence/reconstruction sections, and lightly synchronize the GrafPort class/file and caller support docs so the new code does not conflict with their existing text-helper and field evidence.

## Evidence Sources Checked

### Project and Documentation Sources

- Read the updated B002 goal at `tools/leaser/Agents/Agent-B002/goal.md`; it assigns `[UID:00016I] by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md` and warns not to recreate the stale generated `0x004bb7df` filename.
- Read project workflow and review standards from:
  - `tools/leaser/Agents/Supervisor.md`
  - `by-structure.md`
  - `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
  - `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
  - `by-memory/-guidance.md`
- Read the target page [UID:00016I]. Current state is `COMPLETION:86`, `CONFIDENCE:89`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00005V`, `EMITTER_UIDS:00005V`, blank formal C++, direct callers `0x004bab20` and `0x004bab70`, and exact live range `0x004bb5e0-0x004bb7e0`.
- Read support docs:
  - [UID:00016C] `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
  - [UID:0003XF] `by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md`
  - [UID:00005V] `by-class/GrafPort.md`
  - [UID:0000JR] `by-file/GrafPort.md`
  - [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md`
  - [UID:00004I] `by-class/EPFTileContext.md`
  - [UID:0002HQ] `by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md`
  - [UID:0002HR] `by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md`
  - [UID:0002HT] `by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md`
  - [UID:0000JH] `by-file/FontImageLib.md`
  - [UID:0001UK] `by-type/by-struct/FontGlyphRecord.md`
  - [UID:0000QX] `by-global/g_pFontImageLib.md`
  - [UID:000160] `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`
- Checked generated/tracker state only as read-only evidence. The generated tracker and coverage rows still carry stale `0x004bb7df` references, but they must not be edited by this report-only assignment.

### MCP Availability and Session Evidence

MCP is responding and was used for the target evidence.

- TCP endpoint `127.0.0.1:13337` accepted a connection.
- MCP `initialize` returned HTTP 200.
- MCP `tools/list` returned HTTP 200 and exposed `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, and `xrefs_to`.
- `idb_list` returned active session `80de0a67`, owned/adopted by this workflow, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, `is_analyzing:false`, backend `worker`.
- MCP `server_health` command `#20` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `imagebase:"0x400000"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.

MCP command IDs used for this report:

- `#20` `server_health`
- `#21` `lookup_funcs` for `0x004bb5b0`, `0x004bb5e0`, `0x004bb7df`, `0x004bb7e0`, `0x004bb8c4`
- `#22` `analyze_function` on `0x004bb5e0` with assembly
- `#25` `xrefs_to` for `0x004bb5e0`, `0x004bb5b0`, `0x0067ab24`, `0x0069b3e8`, `0x0069b3fc`
- `#26` `decompile` on `0x004bb5e0`
- `#27` `disasm` on `0x004bb5e0`
- `#28` `analyze_function` on caller `0x004bab20`
- `#29` `analyze_function` on caller `0x004bab70`
- `#30` `lookup_funcs` for direct caller and callee addresses

## Live IDA/MCP Findings

### Boundary and Split Evidence

`lookup_funcs` command `#21` reports:

- `0x004bb5e0` is function `sub_4BB5E0`, size `0x200`.
- `0x004bb7df` is still inside `sub_4BB5E0`.
- `0x004bb7e0` is the next function, `sub_4BB7E0`, size `0xe4`.
- `0x004bb5b0` is not a function start.
- `0x004bb8c4` is not a function start.

`disasm` command `#27` shows the target epilogue ends with `retn 10h` at `0x004bb7dd`, confirming the live half-open range `0x004bb5e0-0x004bb7e0`. The stale generated/manual `0x004bb7df` path is a final-byte style reference and must not be recreated.

[UID:0003XF] `0x004bb5b0-0x004bb5d1` remains a separate no-owner raw helper. `xrefs_to` command `#25` found no xrefs to `0x004bb5b0`; the helper should not be merged into [UID:00016I].

### Caller Evidence

`analyze_function` command `#22` for `0x004bb5e0` reports direct callers:

- `sub_4BAB20`, xref at `0x004bab57`
- `sub_4BAB70`, xref at `0x004bac8a`

`xrefs_to` command `#25` independently reports the same two xrefs for `0x004bb5e0`.

Caller `0x004bab20` command `#28` builds the six-byte color pattern from `this+0x80` and `this+0x7c` as `{back, text, back, text, text, back}`. MCP decompile evidence reports this call shape; this is evidence only, not reconstruction code:

```text
sub_4BB5E0((__int16 *)this, glyph, nextGlyph, 0, pattern);
```

Caller `0x004bab70` command `#29` builds the same pattern. MCP decompile evidence reports this call shape; this is evidence only, not reconstruction code:

```text
sub_4BB5E0(this, glyph, nextGlyph, 0, pattern);
```

The caller evidence matches [UID:00016C]'s current formal C++ shape: text helpers call `DrawGlyph(ch, nextCh, 0, colors)`. However, the target itself does not read or forward the `nextCh` argument; it passes `0` into `FontImageLib::MeasureGlyphWidth` for the third parameter.

### Callee and Global Evidence

`analyze_function` command `#22` reports target callees:

- `sub_457A60`: `EPFTileContext::Initialize` / tile-context initializer.
- `sub_4B6020`: `FontImageLib::MeasureGlyphWidth` with decode output into an `EPFTileContext`.
- `sub_4B5FF0`: `FontImageLib::GetFontMetrics`.
- `unk_69B3FC`: fill/invalidate callback slot documented by [UID:0000TN].
- `unk_69B3E8`: sprite/tile blit callback slot documented by [UID:0000TN].
- `@__security_check_cookie@4`: compiler stack-cookie check only.

`xrefs_to` command `#25` confirms target references to `g_pFontImageLib` at:

- `0x004bb5f4`
- `0x004bb6ac`
- `0x004bb6f2`
- `0x004bb73a`

`analyze_function`/`disasm` command `#22`/`#27` confirms callback calls:

- `unk_69B3FC` at `0x004bb688` for optional background fill/invalidation.
- `unk_69B3E8` at `0x004bb7c1` for final glyph tile blit.

### Target Behavior

The live target sequence is:

1. Allocate local `EPFTileContext`, local destination/background rects, and short output variables.
2. Call `EPFTileContext::Initialize` before checking `this+0x71`.
3. If `this+0x71` is zero, return without drawing or advancing the cursor.
4. Read font/style id from `this+0x8a`.
5. Call `FontImageLib::MeasureGlyphWidth` with:
   - font/style id from `this+0x8a`
   - glyph id from argument 0
   - `0` as the third FontImageLib parameter
   - clear/decode flag `1`
   - caller-supplied color-pattern pointer from argument `0x10`
   - `NULL` output bounds pointer
   - local `short` advance output
   - local `EPFTileContext` output
6. If the background flag argument is nonzero:
   - call `FontImageLib::GetFontMetrics` for width and height.
   - build a background rect from `m_currentX`, `m_currentY - fontHeight`, `m_currentX + fontWidth`, and `m_currentY`.
   - save `this+0x70` and `this+0x74`.
   - set `this+0x70 = this+0x88` and `this+0x74 = this+0x78`.
   - call the fill/invalidation callback `dword_69B3FC`.
   - restore `this+0x70` and `this+0x74`.
7. Call `FontImageLib::GetFontMetrics` again for placement height.
8. Build the glyph destination rect from the decoded glyph bounds, current cursor, and font height:
   - If the glyph code is byte-sized and font id is nonzero, subtract `2` from horizontal placement and subtract `1` from vertical placement.
   - Otherwise, keep horizontal placement unadjusted and add `1` to vertical placement.
9. Map text draw mode from `this+0x88` for the blit callback:
   - `0` maps to `1`.
   - `2` maps to `3`.
   - all other values pass through unchanged.
10. Call the sprite/tile blit callback `dword_69B3E8` with:
    - receiver `this`
    - decoded `EPFTileContext`
    - source rect `glyphContext.bounds`
    - destination rect
    - mapped blit mode
    - handle from `this+0x84`
    - trailing flags/value `0`
11. Add the signed glyph advance output to `this+0x6c`.
12. Return with `retn 10h`.

## Field and Helper Name Decisions

The following source names are supported by existing GrafPort/TextRunHelper docs and live target evidence:

| Offset / Symbol | Recommended source-facing name | Evidence |
| --- | --- | --- |
| `this+0x68` | `m_currentY` | [UID:00016C] formal C++ and target rect math |
| `this+0x6c` | `m_currentX` | [UID:00016C] formal C++ and target cursor advance |
| `this+0x70` | `m_renderMode` | [UID:00016C] formal C++; saved/restored around fill callback |
| `this+0x71` | `m_drawEnabled` | [UID:00005V] field inventory; target early draw gate |
| `this+0x74` | `m_drawColor` | [UID:00016C] formal C++; saved/restored around fill callback |
| `this+0x78` | `m_textBackFillColor` | [UID:00016C] formal C++; used as temporary fill color |
| `this+0x7c` | `m_textColor` | [UID:00016C] pattern construction in callers |
| `this+0x80` | `m_textBackColor` | [UID:00016C] pattern construction in callers |
| `this+0x84` | `m_brushHandle` | [UID:00005V] brush/context-handle evidence; exact original member spelling remains inferred |
| `this+0x88` | `m_textDrawMode` | [UID:00016C] formal C++; target mode mapping |
| `this+0x8a` | `m_fontStyleId` | [UID:00016C] formal C++; FontImageLib calls |
| `0x0067ab24` | `g_pFontImageLib` | [UID:0000QX] and target refs |
| `0x0069b3e8` | `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` | [UID:0000TN] slot-2 evidence and target call |
| `0x0069b3fc` | `g_pfnFillOrInvalidateRect` | [UID:0000TN] slot-7 evidence and target optional fill |
| `0x00457a60` | `EPFTileContext::Initialize` | [UID:00004I] and target local setup |
| `0x004b5ff0` | `FontImageLib::GetFontMetrics` | [UID:0002HQ] and target calls |
| `0x004b6020` | `FontImageLib::MeasureGlyphWidth` | [UID:0002HR] and target decode/advance call |

The six-byte color pattern helper [UID:0003XF] remains a raw helper, not the implementation source for [UID:00016I]. The callers construct the same pattern inline and pass it to the glyph drawer.

## Ownership and Source Placement

Accepted owner/emitter should remain:

- `CANONICAL_OWNER:00005V`
- `EMITTER_UIDS:00005V`
- file route through [UID:0000JR] `GrafPort.md`

Rejected alternate ownership:

- FontImageLib: the target consumes FontImageLib metrics/decode services but owns GrafPort cursor, render mode, color, and callback state.
- EPFTileContext: the target initializes and fills a local tile context but does not own the type.
- Surface/global callback table: the target dispatches through callback slots but is not a global callback-table definition.
- Raw pattern helper [UID:0003XF]: the helper has no live xrefs and no owner/emitter route; it should remain separate no-code evidence.
- Broad physical parent [UID:000160]: the parent is a split index, not the source owner for this function.

Recommended source placement remains `NexusTK/render/` under the GrafPort emitter path already used by [UID:0000JR].

## First-Draft C++ Recommendation

The target should receive a formal C++ block. This is the exact proposed `RECONSTRUCTION_CPP CODE` insertion content for [UID:00016I], including the repository header markers; it is not an illustrative snippet and is not body-only report code.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void GrafPort::DrawGlyph(wchar_t ch, wchar_t nextCh, bool fillBackground, const unsigned char *glyphColors)
{
    EPFTileContext glyphContext;
    RectBounds backgroundRect;
    RectBounds destinationRect;
    short glyphAdvance = 0;
    short fontWidth = 0;
    short fontHeight = 0;
    unsigned char blitMode;

    glyphContext.Initialize();

    if (!m_drawEnabled) {
        return;
    }

    g_pFontImageLib->MeasureGlyphWidth(m_fontStyleId,
                                       ch,
                                       0,
                                       1,
                                       glyphColors,
                                       NULL,
                                       &glyphAdvance,
                                       &glyphContext);

    if (fillBackground) {
        unsigned char savedRenderMode;
        unsigned int savedDrawColor;

        g_pFontImageLib->GetFontMetrics(m_fontStyleId, &fontWidth, &fontHeight);

        backgroundRect.left = m_currentX;
        backgroundRect.top = m_currentY - fontHeight;
        backgroundRect.right = m_currentX + fontWidth;
        backgroundRect.bottom = m_currentY;

        savedRenderMode = m_renderMode;
        savedDrawColor = m_drawColor;
        m_renderMode = m_textDrawMode;
        m_drawColor = m_textBackFillColor;
        g_pfnFillOrInvalidateRect(this, &backgroundRect);
        m_renderMode = savedRenderMode;
        m_drawColor = savedDrawColor;
    }

    g_pFontImageLib->GetFontMetrics(m_fontStyleId, NULL, &fontHeight);

    if (static_cast<unsigned short>(ch) <= 0x00ff && m_fontStyleId != 0) {
        destinationRect.left = m_currentX + glyphContext.bounds.left - 2;
        destinationRect.top = m_currentY - fontHeight + glyphContext.bounds.top - 1;
        destinationRect.right = m_currentX + glyphContext.bounds.right - 2;
        destinationRect.bottom = m_currentY - fontHeight + glyphContext.bounds.bottom - 1;
    } else {
        destinationRect.left = m_currentX + glyphContext.bounds.left;
        destinationRect.top = m_currentY - fontHeight + glyphContext.bounds.top + 1;
        destinationRect.right = m_currentX + glyphContext.bounds.right;
        destinationRect.bottom = m_currentY - fontHeight + glyphContext.bounds.bottom + 1;
    }

    if (m_textDrawMode == 0) {
        blitMode = 1;
    } else if (m_textDrawMode == 2) {
        blitMode = 3;
    } else {
        blitMode = m_textDrawMode;
    }

    g_pfnBlitSprite(this,
                    &glyphContext,
                    &glyphContext.bounds,
                    &destinationRect,
                    blitMode,
                    m_brushHandle,
                    0);

    m_currentX += glyphAdvance;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Source-shape recheck for this correction:

- No names, signature, or body statements were changed from the prior report during this correction; only the formal repository markers and implementation wording were added.
- The code uses era-plausible human C++ and contains no IDA/decompiler labels, raw address names, `sub_`/`unk_` names, `a1` temporaries, or decompiler-shaped locals.
- The body preserves the runtime behavior recorded by MCP: initialize the local tile context before the draw-enabled gate, call `MeasureGlyphWidth` with third argument `0` and decode flag `1`, optionally fill the background with saved/restored render state, call `GetFontMetrics` again for placement, apply the byte-glyph placement offsets, map text draw mode `0 -> 1` and `2 -> 3`, call the sprite blit callback with the brush/context handle, then advance `m_currentX` by the signed glyph advance.

Notes for implementation:

- Keep the `nextCh` parameter in the source-facing signature because both text-run callers pass it, but the body should not use it. The binary passes `0` to the third `FontImageLib::MeasureGlyphWidth` argument.
- `m_brushHandle` is the best current source-facing name for `this+0x84`; if the implementation callback finds a stronger accepted member name in nearby GrafPort helper docs, use that stronger established spelling and record the substitution in the checklist proof.
- The return type should be `void`. The decompiler's `_DWORD *` return is an artifact of returning the blit callback/cursor expression through `eax`; both direct callers ignore it and the function is behaviorally a draw operation.

## Score and Metadata Recommendation

| Field | Current target value | Recommended after accepted implementation | Reason |
| --- | --- | --- | --- |
| `COMPLETION` | `86` | `90` | Exact boundary, callers, callees, field mapping, callback semantics, cursor advance, and first-draft C++ are now supported. |
| `CONFIDENCE` | `89` | `92` | Live MCP confirms behavior and caller usage; keep below 95 because callback typedefs and some member spellings remain inferred. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Eligible and now has formal C++ recommendation. |
| `CANONICAL_OWNER` | `00005V` | `00005V` | GrafPort owns receiver state and cursor/callback behavior. |
| `EMITTER_UIDS` | `00005V` | `00005V` | Existing emitter route through GrafPort remains correct. |
| `EMITTER_POSITION` | blank | blank | No precise source-order position evidence beyond GrafPort file route. |
| Formal C++ | blank | populated | Current combined score/emitter policy supports first draft. |

## Required Documentation Edits After Acceptance

Do not edit these files until the supervisor accepts this report and issues an implementation callback.

1. `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md`
   - Update score metadata to `COMPLETION:90`, `CONFIDENCE:92`.
   - Replace the stale no-C++ blocker with the current combined-score/emitter-gate rationale.
   - Add live MCP evidence: command IDs, boundary proof, callers, callees, global refs, callback slots, and exact cursor advance.
   - Add a field/helper mapping table at target level.
   - Insert the exact formal `RECONSTRUCTION_CPP CODE` header/block content above, including all three repository marker lines.
   - Keep stale `0x004bb7df` as a boundary caveat only; do not point target filename or range back to the stale final-byte path.

2. `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
   - Add a short support note that [UID:00016I] now has a formal `DrawGlyph` body and that the direct callers pass `nextCh`, but the glyph drawer itself ignores/does not forward that parameter.
   - Do not rewrite the existing formal text-helper C++; it already matches the call shape.

3. `by-class/GrafPort.md`
   - Update the dependency/source-readiness note for [UID:00016I] to say the glyph drawer has enough evidence for first-draft formal C++.
   - Add or align the `this+0x84` member note with the selected implementation spelling, currently recommended as `m_brushHandle`.

4. `by-file/GrafPort.md`
   - Update the GrafPort proposed contents/source-readiness section for `0x004bb5e0-0x004bb7e0` to record the accepted `DrawGlyph` reconstruction and callback/FontImageLib dependencies.

5. `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`
   - Update only the child inventory/support note for [UID:00016I] if needed, recording that the child now has first-draft C++ and exact live half-open range.
   - Do not convert the broad parent into an emitter or add C++ to it.

6. No changes recommended unless supervisor explicitly requests them:
   - `by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md`: already has equal-or-greater no-owner helper detail; no xrefs.
   - `by-global/SurfaceRenderCallbackTable.md`: already names slot 2 and slot 7 adequately for target usage.
   - `by-class/EPFTileContext.md`: already documents the context layout and initializer needed by target.
   - FontImageLib pages: already document GetFontMetrics/MeasureGlyphWidth/DecodeGlyphBitmap enough for target-level code.
   - Generated tracker/coverage files and any `-coverage-report.md`: do not edit.

## Scoped Validators Required After Accepted Implementation

Run from `source-3/project-documentation` after editing each by-* file. Record command IDs, timestamps, exit status, and ok counts in this report checklist during the implementation callback.

Expected validators if the recommended edit set is applied:

> Executable block R001 was removed from this report and preserved verbatim in [00016I-GrafPortDrawGlyph-source-quality-removed.md](00016I-GrafPortDrawGlyph-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If implementation callback chooses not to edit one of the support files because it is already at equal-or-greater detail, record that explicit exclusion and do not run that file's validator.

## Implementation Tracking Checklist

Accepted implementation callback applied on 2026-06-26. Checked items include file/section proof, validator command ID/timestamp/exit status/ok count, and lease release proof.

- [x] Lease `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md`, update score metadata to `90/92`, add live MCP evidence, replace stale no-C++ blocker, add field/helper mapping, and insert the exact formal `RECONSTRUCTION_CPP CODE` header/block content from this report, including `*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`, `*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***`, the full `GrafPort::DrawGlyph` C++ body, and `*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***`.
  - Proof: `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md` now has `COMPLETION:90`, `CONFIDENCE:92`, unchanged `CANONICAL_OWNER:00005V` and `EMITTER_UIDS:00005V`, the formal `GrafPort::DrawGlyph` block at the repository `RECONSTRUCTION_CPP CODE` markers, live B002 MCP evidence for session `80de0a67` / command IDs `#20-#30`, the stale `0x004bb7df` final-byte caveat, field/helper mapping including `m_brushHandle` at `this+0x84`, current score rationale, and [UID:0003XF] non-merge/no-xref proof.
  - Validator: `python .\tools\validator.py --mode file --file by-memory\0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md --apply --queue-timeout 240`; command_id `000000002397`; command_timestamp `2026-06-26T04:44:10-04:00`; exit status `0`; `ok: 1`; generated_refresh `deferred` with command_id `000000002397` and timestamp `2026-06-26T04:44:10-04:00`. Validator also reported known missing-ref diagnostics, stale-path `path_update` from `0x004bb7df`, registry/score updates, `projected_stats_update`, and a coverage-report UID-link side effect that was restored.
  - Lease release: initial lease command returned `Success` for this path; later `python tools\leaser\leaser.py B002 unlease ...` returned `Rejected[No active lease]` because no active lease remained; `tools/leaser/Agents/current_leases.md` then showed `No active leases`.
- [x] Lease `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` if needed, add the caller/`nextCh` support note without rewriting existing formal C++.
  - Proof: `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` now has the support note at `2026-06-26 B002 [UID:00016I] implementation sync`: the two text-run callers pass `nextCh`, but `DrawGlyph` does not use/forward it and passes `0` to the third `FontImageLib::MeasureGlyphWidth` parameter. The page's existing formal C++ remains unchanged in shape and still calls `DrawGlyph(ch, nextCh, 0, colors)`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory\0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md --apply --queue-timeout 240`; command_id `000000002398`; command_timestamp `2026-06-26T04:44:44-04:00`; exit status `0`; `ok: 1`; generated_refresh `deferred` with command_id `000000002398` and timestamp `2026-06-26T04:44:44-04:00`. Validator also reported `missing_ref_uid 0003XF` registry warnings and `projected_stats_update` for `project-level/-auto-completion-stats.md`.
  - Lease release: initial lease command returned `Success` for this path; later unlease returned `Rejected[No active lease]`; final lease report showed `No active leases`.
- [x] Lease `by-class/GrafPort.md` if needed, synchronize [UID:00016I] dependency/source-readiness text and the selected `this+0x84` member spelling.
  - Proof: `by-class/GrafPort.md` documents [UID:00016I] as first-draft formal C++ under the GrafPort class/emitter route; the [UID:000163] brush/context handle note records `this+0x84` as `m_brushHandle` for the glyph drawer and says no stronger accepted spelling is currently documented. The `2026-06-26 B002 GrafPortDrawGlyph implementation sync` change entry records score unchanged and the `m_brushHandle` spelling.
  - Validator: `python .\tools\validator.py --mode file --file by-class\GrafPort.md --apply --queue-timeout 240`; command_id `000000002399`; command_timestamp `2026-06-26T04:44:50-04:00`; exit status `0`; `ok: 1`; generated_refresh `deferred` with command_id `000000002399` and timestamp `2026-06-26T04:44:50-04:00`. Validator reported existing `missing_ref_uid` warnings for raw helper UIDs `0003XE`, `0003XB`, and `0003XF`, plus `projected_stats_update`.
  - Lease release: initial lease command returned `Success` for this path; later unlease returned `Rejected[No active lease]`; final lease report showed `No active leases`.
- [x] Lease `by-file/GrafPort.md` if needed, synchronize GrafPort file contents/source-readiness for `0x004bb5e0-0x004bb7e0`.
  - Proof: `by-file/GrafPort.md` now has the Text measurement/drawing helpers row synchronized for [UID:00016I] as `GrafPort::DrawGlyph`, preserving FontImageLib metric/decode, EPFTileContext setup, optional fill/invalidation callback, sprite blit callback, `m_brushHandle`, draw-mode mapping, and cursor advance under `render/GrafPort.cpp`; Ownership Decision also records B002's 2026-06-26 DrawGlyph implementation as a GrafPort method rather than FontImageLib/Surface/callback-table/fitting-room code; the `2026-06-26 B002 GrafPortDrawGlyph implementation sync` change entry records score unchanged and first-draft formal C++.
  - Validator: `python .\tools\validator.py --mode file --file by-file\GrafPort.md --apply --queue-timeout 240`; command_id `000000002401`; command_timestamp `2026-06-26T04:45:01-04:00`; exit status `0`; `ok: 1`; generated_refresh `deferred` with command_id `000000002401` and timestamp `2026-06-26T04:45:01-04:00`. Validator reported existing `missing_ref_uid` warnings for raw helper UIDs `0003XB`, `0003XE`, and `0003XF`, plus `projected_stats_update`.
  - Lease release: initial lease command returned `Success` for this path; later unlease returned `Rejected[No active lease]`; final lease report showed `No active leases`.
- [x] Lease `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md` if needed, update only the child inventory/support row for [UID:00016I].
  - Proof: `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md` child inventory row for `0x004bb5e0-0x004bb7e0` now says [UID:00016I] has exact live half-open range and first-draft formal C++ in the child; the parent remains a non-emitting split/index page and does not duplicate the method body.
  - Validator: final rerun after trimming to row-only scope: `python .\tools\validator.py --mode file --file by-memory\0x004b8bf0-0x004bb8c4.GrafPort.md --apply --queue-timeout 240`; command_id `000000002410`; command_timestamp `2026-06-26T04:47:15-04:00`; exit status `0`; `ok: 1`; generated_refresh `deferred` with command_id `000000002410` and timestamp `2026-06-26T04:47:15-04:00`. Earlier run `000000002402` also exited `0`/`ok: 1` before the row-only trim. Validator reported existing `missing_ref_uid` warnings for raw helper UIDs `0003XB`, `0003ZP`, `0003XD`, `0003XE`, and `0003XF`, plus `projected_stats_update`.
  - Lease release: initial lease command returned `Success` for this path; later unlease returned `Rejected[No active lease]`; final lease report showed `No active leases`.
- [x] Explicitly record no edits for generated files, project-level generated files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, and all `-coverage-report.md` files.
  - Proof: No manual edits were made to generated files, validator/tool state, or IDA DB. Scoped validator commands reported validator-owned `projected_stats_update` side effects and deferred generated refreshes; the target validator also reported a `by-memory/-coverage-report.md` UID-link update from stale `0x004bb7df` to live `0x004bb7e0`, and that one manual coverage-report side effect was restored so no 00016I coverage-report diff remains from this task.
- [x] Confirm [UID:0003XF] remains separate no-owner/no-code helper and is not merged into [UID:00016I].
  - Proof: [UID:00016I] target evidence says command `#25` found no xrefs to `0x004bb5b0`; the target keeps [UID:0003XF] as adjacent raw helper non-merge proof. `by-class/GrafPort.md`, `by-file/GrafPort.md`, and the broad parent continue to list [UID:0003XF] separately as no-owner/non-emitting raw pattern helper with no caller/pointer-table/vtable/callback/branch route.
- [x] Record final lease status showing no active B002 leases.
  - Proof: Initial lease command returned `Success` for all five edited files. Release command `python tools\leaser\leaser.py B002 unlease ...` returned `Rejected[No active lease]` for all five paths because no active B002 lease remained by cleanup time. Follow-up `tools/leaser/Agents/current_leases.md` showed an empty table and `No active leases`.

## Implementation Callback Status

Implementation callback completed on 2026-06-26. Edited by-* docs were the accepted five-file scope only. The report checklist is fully checked. All scoped validators for edited by-* files exited `0` with `ok: 1`. No active B002 leases remain.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00016I-GrafPortDrawGlyph-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00016I-GrafPortDrawGlyph-source-quality.md","timestamp":"2026-06-26T04:51:46","uid":"00016I"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00016I-GrafPortDrawGlyph-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00016I-GrafPortDrawGlyph-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00016I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
