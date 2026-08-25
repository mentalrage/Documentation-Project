** TARGET-REPORT-UID:00016I **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

## Supervisor Disposition - Duplicate Historical Lead, Do Not Execute

2026-06-29 supervisor manual research-folder check: this loose B011 report is not active work and must not be executed or continued unless a future supervisor explicitly reopens it. The same target is already covered by the newer executed report `executed-b-agent-research/B002/00016I-GrafPortDrawGlyph-source-quality.md`, and `auto-generated/-ag-research-tracker.md` lists [UID:00016I] at `90/92`, report count `1`, author `B002`, path `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md`. Preserve this file only as historical lead material.

2026-07-02 B011 backlog review: disposition remains duplicate historical lead. Current target doc `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md` already has the B002 implementation result: `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter [UID:00005V], formal `GrafPort::DrawGlyph(...)` C++ populated, and current support documentation handled by the executed B002 flow. This loose B011 report is not report-only work awaiting validation, not callback-ready, and not already-implemented by B011; it is superseded by the executed B002 report and should not receive `execute_report`.

# 00016I GrafPortDrawGlyph Source-Quality Research

Report-only B-agent pass for `[UID:00016I] by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md`.

Assignment note: the generated tracker row still names stale path `by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md`. The live corrected UID path is `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md`; this report uses the live file and does not edit generated tracker/coverage files.

## Final Recommendation

Implement the target in the live `00016I` page after supervisor validation. The function is source-shape reconstructable now, and the current no-code rationale in the target is stale because it cites an older 90/90+ gate. Under the current Rule 26 / B-agent standard, this target clears the formal-code gate:

- `RECONSTRUCTABLE:TRUE`.
- Current target score is `COMPLETION:86`, `CONFIDENCE:89`, average `87.5`.
- Owner and emitter are already populated: `CANONICAL_OWNER:00005V`, `EMITTER_UIDS:00005V`.
- Owner/emitter support clears 85/85: `by-class/GrafPort.md` `[UID:00005V]` is `88/90`, and its file owner/emitter `by-file/GrafPort.md` `[UID:0000JR]` is `89/88`.
- MCP confirms exact bounds, two direct callers, support helper calls, callback slots, and the current half-open end `0x004bb7e0`.

Recommended target metadata after implementation:

- Keep `CANONICAL_OWNER:00005V`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00005V`.
- Keep `EMITTER_POSITION_OPTIONAL` blank unless the validator assigns an insertion position.
- Keep `Nested:-8`.
- Raise target metadata from `86/89` to `89/90`.
- Do not raise higher yet: exact original spellings for a few GrafPort fields and callback globals remain source-facing inferred names, not 100% recovered names.

No new helper child page is required. All named helper/type/resource dependencies already have existing support pages or non-emitting route pages, and the target can be implemented by synchronizing the target and GrafPort support docs.

## Current MCP Evidence

MCP was mandatory for this report and was responsive during the evidence pass.

- Port/process status: TCP listener on `127.0.0.1:13337`; listener PID observed as `13684`; active MCP worker observed as PID `26892`.
- JSON-RPC status: `initialize` OK, `tools/list` OK with 65 tools.
- Active IDB: session `80de0a67`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health`: status OK, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

MCP function/boundary evidence:

- `lookup_funcs(0x004bb5e0)` returns `sub_4BB5E0`, size `0x200`.
- `lookup_funcs(0x004bb7e0)` returns the next function `sub_4BB7E0`, size `0xe4`.
- `get_bytes` around `0x004bb5e0` shows pre-start padding followed by the target prologue at `0x004bb5e0`.
- `get_bytes` around `0x004bb7d0` shows the target epilogue ending with `retn 10h` at `0x004bb7dd`, followed by the next function prologue at `0x004bb7e0`.
- `analyze_function(0x004bb5e0)` reports size 512 bytes, 13 basic blocks, cyclomatic complexity 6, and two direct callers.
- `int_convert.py` verified `0x200` as 512 and `0x10` as 16.

MCP caller/reachability evidence:

- `xrefs_to(0x004bb5e0)` returns exactly two code xrefs:
  - `0x004bab57` inside `0x004bab20`.
  - `0x004bac8a` inside `0x004bab70`.
- `decompile(0x004bab20)` shows the narrow glyph wrapper builds the six-byte color pattern from `m_textBackColor` and `m_textColor`, then calls `sub_4BB5E0(this, ch, nextCh, 0, pattern)`.
- `decompile(0x004bab70)` shows the wide text loop builds the same color pattern, performs optional text background fill outside this target, iterates characters, and calls `sub_4BB5E0(this, ch, nextCh, 0, pattern)`.
- No MCP xrefs were found to the adjacent raw helper starts `0x004bb5b0` or `0x004bb5d1`; the existing `0003XF` no-owner/non-emitting route remains separate and should not be merged into `00016I`.

MCP callee/helper evidence:

- `callees(0x004bb5e0)` reports calls to:
  - `0x00457a60` `EPFTileContext` initializer.
  - `0x004b6020` `FontImageLib::MeasureGlyphWidth`.
  - `0x004b5ff0` `FontImageLib::GetFontMetrics`.
  - `0x0069b3fc` surface fill/invalidate callback slot.
  - `0x0069b3e8` surface sprite blit callback slot.
  - `0x005c772f` security cookie check.
- `xrefs_to(0x0067ab24)` includes target reads at `0x004bb5f4`, `0x004bb6ac`, `0x004bb6f2`, and `0x004bb73a`; this is the existing `g_pFontImageLib` global.
- `xrefs_to(0x004b6020)` includes the target call at `0x004bb634`.
- `xrefs_to(0x004b5ff0)` includes target calls at `0x004bb64a`, `0x004bb6b5`, `0x004bb700`, and `0x004bb743`.
- `xrefs_to(0x0069b3fc)` includes the target call at `0x004bb688`.
- `xrefs_to(0x0069b3e8)` includes the target call at `0x004bb7c1`.

## Source Shape

The target is a private `GrafPort` glyph renderer used by the text-run helpers. The callers already establish the intended source signature shape:

- `DrawGlyphWithTextColors` and `DrawWideText` pass `ch`, `nextCh`, a background-fill flag, and a six-byte color pattern.
- The binary target preserves the ABI parameter for `nextCh` but does not use it. The formal C++ should retain the parameter and mark it unused; dropping it would break caller/source consistency and the `retn 10h` ABI shape.
- The target leaves an advance value in `EAX` as a decompiler artifact, but both callers ignore the return. The source-facing method should be `void`.

Target behavior from MCP decompilation/disassembly:

- Construct and initialize a local `EPFTileContext`.
- Return early when `m_drawEnabled` (`this+0x71`) is false.
- Decode/measure the glyph with `g_pFontImageLib->MeasureGlyphWidth(m_fontStyleId, ch, 0, 1, colorPattern, NULL, &advance, &glyphTile)`.
- If `fillBackground` is nonzero, get font width/height, build a background rect from current text cursor coordinates, temporarily copy `m_textDrawMode` and `m_textBackFillColor` into the active render mode/color fields, call the surface fill/invalidate callback, and restore the saved mode/color.
- Compute the glyph destination rect from the decoded tile bounds and current cursor.
- For low-codepoint glyphs with nonzero `m_fontStyleId`, apply the observed nonzero-font offset: left/right minus 2 and top/bottom minus 1.
- Otherwise apply the default placement: top/bottom plus 1 and no horizontal shift.
- Map `m_textDrawMode` `0 -> 1`, `2 -> 3`, else pass it through.
- Call the surface sprite blit callback with source context, tile bounds, destination rect, mapped mode, `m_brushHandle`, and flags `0`.
- Advance `m_currentX` by the measured glyph advance.

## Ownership And Routing

Keep the target under GrafPort:

- Target UID `00016I` belongs to `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md`.
- Direct owner/emitter remains `by-class/GrafPort.md` `[UID:00005V]`.
- File route remains `by-file/GrafPort.md` `[UID:0000JR]`, reconstruction path `NexusTK/render/GrafPort.cpp`.
- Direct callers are in `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` `[UID:00016C]`, which already emits caller-side formal C++ that calls `DrawGlyph(ch, nextCh, 0, colors)`.

Rejected alternate owners:

- `FontImageLib` is a dependency only. It supplies metrics and glyph decoding, but the target reads/writes GrafPort cursor, render state, draw color, text color state, and surface callback state.
- `SurfaceRenderCallbackTable` is a callback dependency only. The target uses two callback slots but owns no surface callback table logic.
- The adjacent raw helper `0003XF` has no xrefs into this function and remains an already documented non-emitting helper route.
- The stale generated/tracker old end `0x004bb7df` is not a source/range owner; the live target file and MCP function boundary use half-open end `0x004bb7e0`.

## Helper And Support Page Handling

No new child pages are needed for implementation. Required support is already present:

- `by-class/GrafPort.md` `[UID:00005V]`: owner/emitter class, `88/90`, above 85/85. Needs a support-note sync that `00016I` is now formal-code ready with signature `GrafPort::DrawGlyph(wchar_t ch, wchar_t nextCh, bool fillBackground, const unsigned char *colorPattern)`.
- `by-file/GrafPort.md` `[UID:0000JR]`: file owner/emitter route, `89/88`, above 85/85. Needs a support-note sync that live target path is `0x004bb5e0-0x004bb7e0` and the stale `0x004bb7df` generated row is not the implementation path.
- `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` `[UID:00016C]`: caller support already emits calls to `DrawGlyph(ch, nextCh, 0, colors)`. A short dependency note can be added after implementation to say the callee now has formal C++ and keeps the unused `nextCh` ABI parameter.
- `by-file/FontImageLib.md` `[UID:0000JH]`, `by-class/FontImageLib.md` `[UID:00005B]`, `by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md` `[UID:0002HQ]`, and `by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md` `[UID:0002HR]`: existing metric/decode dependency pages already clear 85/85 or document support helper behavior; no new page or metadata change is required for this target.
- `by-file/EPFTileContext.md` `[UID:0000J4]`, `by-class/EPFTileContext.md` `[UID:00004I]`, and `by-type/by-struct/RectBoundsLayout.md` `[UID:0001VP]`: existing type/layout support is sufficient. Formal code uses `EPFTileContext::Initialize()` because the current class formal block exposes `Initialize`.
- `by-global/SurfaceRenderCallbackTable.md` `[UID:0000TN]` and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` `[UID:0001PI]`: existing callback table pages document slot 2 as `g_pfnBlitSprite`/sprite blit and slot 7 as the broad fill/invalidate callback. No new page is needed.
- `by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md` `[UID:0003XF]`: existing no-owner/non-emitting page remains correct; no implementation merge is needed.

## First-Draft C++ Recommendation

Use this exact formal insertion text for the target page after supervisor validation:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void GrafPort::DrawGlyph(wchar_t ch, wchar_t nextCh, bool fillBackground, const unsigned char *colorPattern)
{
    (void)nextCh;

    EPFTileContext glyphTile;
    glyphTile.Initialize();

    if (!m_drawEnabled) {
        return;
    }

    short advance = 0;
    g_pFontImageLib->MeasureGlyphWidth(m_fontStyleId,
                                       ch,
                                       0,
                                       1,
                                       colorPattern,
                                       NULL,
                                       &advance,
                                       &glyphTile);

    if (fillBackground) {
        short fontWidth = 0;
        short fontHeight = 0;
        g_pFontImageLib->GetFontMetrics(m_fontStyleId, &fontWidth, &fontHeight);

        RectBounds backgroundRect;
        backgroundRect.left = m_currentX;
        backgroundRect.top = m_currentY - fontHeight;
        backgroundRect.right = m_currentX + fontWidth;
        backgroundRect.bottom = m_currentY;

        const unsigned char oldRenderMode = m_renderMode;
        const unsigned int oldDrawColor = m_drawColor;

        m_renderMode = m_textDrawMode;
        m_drawColor = m_textBackFillColor;
        g_pfnFillOrInvalidateRect(this, &backgroundRect);

        m_renderMode = oldRenderMode;
        m_drawColor = oldDrawColor;
    }

    short lineHeight = 0;
    RectBounds destinationRect;

    if (static_cast<unsigned short>(ch) <= 0x00ff && m_fontStyleId != 0) {
        g_pFontImageLib->GetFontMetrics(m_fontStyleId, NULL, &lineHeight);

        destinationRect.left = m_currentX + glyphTile.bounds.left - 2;
        destinationRect.top = m_currentY - lineHeight + glyphTile.bounds.top - 1;
        destinationRect.right = m_currentX + glyphTile.bounds.right - 2;
        destinationRect.bottom = m_currentY - lineHeight + glyphTile.bounds.bottom - 1;
    } else {
        g_pFontImageLib->GetFontMetrics(m_fontStyleId, NULL, &lineHeight);

        destinationRect.left = m_currentX + glyphTile.bounds.left;
        destinationRect.top = m_currentY - lineHeight + glyphTile.bounds.top + 1;
        destinationRect.right = m_currentX + glyphTile.bounds.right;
        destinationRect.bottom = m_currentY - lineHeight + glyphTile.bounds.bottom + 1;
    }

    unsigned char blitMode;
    if (m_textDrawMode == 0) {
        blitMode = 1;
    } else if (m_textDrawMode == 2) {
        blitMode = 3;
    } else {
        blitMode = m_textDrawMode;
    }

    g_pfnBlitSprite(this,
                    &glyphTile,
                    &glyphTile.bounds,
                    &destinationRect,
                    blitMode,
                    m_brushHandle,
                    0);

    m_currentX += advance;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Name notes for implementer:

- `DrawGlyph` is inferred from existing caller/source context, not an original symbol.
- `m_currentX`, `m_currentY`, `m_drawEnabled`, `m_renderMode`, `m_drawColor`, `m_textBackFillColor`, `m_textColor`, `m_textBackColor`, `m_brushHandle`, `m_textDrawMode`, and `m_fontStyleId` are best source-facing names from the accepted GrafPort support docs.
- `g_pfnFillOrInvalidateRect` and `g_pfnBlitSprite` are best source-facing callback names from the accepted callback table support docs.
- `nextCh` is intentionally retained and unused because both caller wrappers pass it and the target ABI returns with `retn 10h`.

## Generated And Project-Level Notes

Generated and project-level files were not edited in this report-only pass.

Known generated/project-level stale state to let validators refresh after implementation:

- `auto-generated/-ag-research-tracker.md` still lists `0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md` with older score `76/86`.
- `auto-generated/-ag-coverage-report-by-memory.md` still lists the stale `0x004bb5e0-0x004bb7df` row and a missing-file entry for that stale path.
- `project-level/-unresolved.md` still has raw-label entries involving this target, including `dword_67AB24`, `dword_69B3E8`, `dword_69B3FC`, `sub_4BAB20`, `sub_4BAB70`, `sub_4BB5E0`, and field offsets.

Do not hand-edit any generated file, project-level generated report, coverage report, or validator state/cache to resolve those. If a scoped validator refuses the live target because of stale old-path state, stop and report the exact validator/tooling blocker.

## Superseded Implementation Tracking Checklist - Do Not Execute

The checklist below is retained only as historical lead material from the original report-only pass. It must not be acted on under the current backlog-clearing instruction because the accepted/implemented lifecycle is already covered by executed report `executed-b-agent-research/B002/00016I-GrafPortDrawGlyph-source-quality.md`. No B011 implementation callback is pending for this report unless a future supervisor explicitly reopens it.

- [ ] Acquire short leases only for files that will be edited immediately; no leases are needed for this report-only document.
- [ ] Update `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md` `[UID:00016I]`: raise `COMPLETION:86 -> 89`, raise `CONFIDENCE:89 -> 90`, keep owner/emitter/reconstructable metadata unchanged, and keep the live path `0x004bb5e0-0x004bb7e0`.
- [ ] In the same target page, replace the stale no-code / old 90/90+ gate rationale with the current Rule 26 code-entry proof from this report.
- [ ] In the same target page, insert the exact `RECONSTRUCTION_CPP CODE` block from this report and keep the formal header/marker lines intact.
- [ ] In the same target page, add the 2026-06-25 MCP evidence summary: session `80de0a67`, exact `0x200` byte range, `retn 10h`, callers `0x004bab20` and `0x004bab70`, callees `0x00457a60`, `0x004b6020`, `0x004b5ff0`, `0x0069b3fc`, `0x0069b3e8`, and stale generated old-end note.
- [ ] Update `by-class/GrafPort.md` `[UID:00005V]` with a concise support sync for `00016I`: live corrected range, formal signature, owner/emitter unchanged, `nextCh` retained but unused, background fill/blit behavior, and callback/global names used by the formal body. No score change is required unless the validator requires metadata normalization.
- [ ] Update `by-file/GrafPort.md` `[UID:0000JR]` with a concise support sync for `00016I`: live corrected path `0x004bb5e0-0x004bb7e0`, route remains `NexusTK/render/GrafPort.cpp`, and generated old-end rows are stale. No score change is required.
- [ ] Update `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` `[UID:00016C]` only if needed to synchronize the dependency note: existing caller formal C++ already calls `DrawGlyph(ch, nextCh, 0, colors)` and matches this target signature. If no edit is needed, record proof in the report checklist after implementation.
- [ ] Confirm no new helper child pages are required: `0002HQ`, `0002HR`, `00004I`, `0001VP`, `0000TN`, `0001PI`, and `0003XF` already cover helper/type/callback/raw-neighbor support. Do not create child pages for these.
- [ ] Do not edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `project-level/-unresolved.md`, any validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`.
- [ ] Run scoped target validator from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md --apply --queue-timeout 240 --wait-generated`.
- [ ] Run scoped GrafPort class validator if edited: `python .\tools\validator.py --mode file --file by-class/GrafPort.md --apply --queue-timeout 240`.
- [ ] Run scoped GrafPort file validator if edited: `python .\tools\validator.py --mode file --file by-file/GrafPort.md --apply --queue-timeout 240`.
- [ ] Run scoped caller-support validator if `00016C` is edited: `python .\tools\validator.py --mode file --file by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md --apply --queue-timeout 240`.
- [ ] After validators, confirm generated refresh status instead of hand-editing generated files. If validator stale-path state still reports only `0x004bb7df` and blocks the live target, stop and report the exact command, timestamp, and validator output.
- [ ] Release all leases immediately after the edit/validator batch and record lease release proof.
- [ ] Update this report checklist with checked items, validator command IDs/timestamps/results, generated-refresh status, changed files, and any explicitly excluded items with concrete reasons.

## Report-Only Work Performed

- Read and followed the current B011 `goal.md` and the project `ntk-b-agent-workflow` instructions.
- Used current MCP evidence; did not finish from fallback-only evidence.
- Did not spawn subagents.
- Did not edit target/support `by-*` docs.
- Did not edit generated files, project-level files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`.
- Did not acquire leases because this was report-only work.

## Backlog Clearing Status

- 2026-07-02 B011 backlog review preserved the original `AUTHOR-AGENT-SPECS` header exactly.
- Classification: duplicate historical lead, superseded by executed B002 report. Not callback-ready and not executable as a B011 report.
- No by-* docs, generated files, coverage reports, project-level files, validator/tool state, queues, locks, archives, or IDA DB were edited during this backlog review.
- No leases or validators were needed because only this report status text was clarified.
