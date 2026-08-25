** TARGET-REPORT-UID:0001JR **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B006 Source-Quality Report: [UID:0001JR] DrawTextRunCallback

## Finalized Report / Current Recommendation

- Target: [UID:0001JR] `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`.
- Current target state: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000ON`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ON`, blank formal C++.
- Recommendation: keep owner/emitter/reconstructable metadata unchanged, raise target score to `90/91`, and populate the target formal `RECONSTRUCTION_CPP CODE` block with the exact formal block in this report.
- Source placement: file-local callback in [UID:0000ON] `TextEditPane` / `NexusTK/ui/controls/TextEditPane.cpp`, not a `TextEditPane` virtual/member method and not FittingRoom source.
- Implementation scope after supervisor acceptance: update the target at report-level detail, update the TextEditPane/file/item/support pages listed below, preserve raw-neighbor no-route separation, and run scoped validators. Do not edit manual coverage reports or generated files by hand.
- No by-* docs, generated files, project-level generated files, validator state/cache, coverage reports, or IDA DB files were edited in this report-only pass.

## MCP And Tool Provenance

- Required MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Active IDB session: `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active, worker backend, not analyzing.
- Listener/process status checked during this pass:
  - `127.0.0.1:13337` listener owned by PID `13684`.
  - Visible MCP/IDA-related processes included `idalib-mcp.exe` PID `17084`, Python listener PID `13684`, and worker PID `26892`.
- `server_health` after retry: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- One broad xref query against the lower renderer temporarily timed out; bounded retry recovered with `idb_list` and `server_health`, so this report is MCP-backed and not fallback-only.

## Evidence Checked

IDA MCP evidence:

- `lookup_funcs` for `0x00593db0`, `0x00593ef5`, `0x00593ef6`, `0x00593f00`, `0x00594040`, `0x005946b0`, and `0x0059489f`.
- `xrefs_to` for `0x00593db0`, `0x00593f00`, and sibling `0x00593c20`.
- `callees` for `0x00593db0`.
- `decompile` and prior disassembly evidence for `0x00593db0`.
- `decompile` for `0x00590810` (`TextEditPane::OnDraw` route), `0x00593500` (`TextEditPane::IterateTextRuns`), and `0x005946b0` (lower text-run renderer).
- `get_bytes` for `0x00593dad`, `0x00593ef0`, `0x00591670`, and `0x005908d0` to confirm padding and address-taken setup bytes.

Documentation/generated evidence:

- Target page [UID:0001JR].
- Item mirror [UID:0000UK] `by-item/DrawTextRunCallback_00593DB0.md`.
- Sibling/neighbor pages [UID:0001JQ], [UID:0003FC], [UID:0003FD], [UID:0001JS].
- Parent/support pages [UID:0000ON] `TextEditPane`, [UID:0000EO] `TextEditPane`, [UID:00016C] `GrafPortTextRunHelpers`, [UID:000162] `GrafPortDrawStateAccessors`, [UID:000164] `GrafPortGetClipRect`, [UID:00015S] `RectGeometryHelpers`, [UID:0000TN] `SurfaceRenderCallbackTable`, [UID:0000EN] `TextEditObject`, and [UID:00004H] `EPFTextEditObject`.
- Executed B007 report for [UID:0001JQ] and existing TextEditPane support docs, used only after current MCP checks.
- Generated TextEditPane output is stale evidence only: `auto-generated/NexusTK/ui/controls/TextEditPane.cpp` still lists [UID:0001JR] as `78/86` with an empty marker while the target page is `86/89`.

Tool conversion evidence:

- Decimal/hex conversions were verified from `E:\NTK\GhidraBridge\source-3\project-documentation` with:

> Executable block R001 was removed from this report and preserved verbatim in [0001JR-DrawTextRunCallback-source-quality-removed.md](0001JR-DrawTextRunCallback-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Relevant confirmed conversions: target size `0x146` = `326` bytes; lower renderer size `0x1ef` = `495` bytes; draw state first 32-byte rect block `0x20` = `32`; draw state byte slot through padded size `0x24` = `36`; `m_editorFlags` offset `0x15c` = `348`; `m_maskedText` offset `0x16a` = `362`; `m_formatMode` offset `0x173` = `371`.

## Executive Recommendation

Keep [UID:0001JR] as a source-bearing, reconstructable, file-local callback in `TextEditPane.cpp`. The prior blockers are now resolved far enough for first-draft C++:

- The callback signature is the same eight-argument cdecl ABI proven by `TextEditPane::IterateTextRuns` at `0x00593500`.
- The draw-state layout is directly proven: two `RectBounds` records at state `+0x00` and `+0x10`, plus a byte flag at `+0x20`.
- The format payload is the same `TextRunFormatData` built by the iterator; target uses `format+0x04` as run text color and `format+0x08` as optional `TextEditObject *`.
- The target has exactly two address-taking refs and no direct call refs; it is a callback, not a member method.
- The raw neighbor [UID:0003FD] at `0x00593f00` has zero direct start refs and remains separate/blank.

Recommended callback signature:

```text
static bool __cdecl DrawTextRunCallback(
    TextRunDrawLineRecord *line,
    const TextRunFormatData *format,
    const wchar_t *text,
    int textOffset,
    unsigned short charCount,
    unsigned short segmentFlags,
    TextRunDrawState *state,
    TextEditPane *pane);
```

`TextRunDrawLineRecord` is a target-local draw overlay for the same line table storage used by [UID:0001JQ]. I do not recommend editing [UID:0001JQ] formal C++ in this callback pass: that accepted measure block already emits `TextRunFormatData` and segment flags earlier in `TextEditPane.cpp`; this target only needs the draw-only line fields at `+0x04` and `+0x14`.

Recommended score: `90/91`. Completion rises because the report now supplies formal target C++, callback ABI, state layout, draw-line overlay, source-placement proof, raw-neighbor proof, and support-doc edit scope. Confidence rises because the behavior is direct MCP-backed. It remains capped below final audit because exact original spellings for `m_textAreaLeft`, `m_textAreaTop`, `m_textAreaRight`, `m_textAlignment`, `DrawTextRunSegment`, and the inline object hook remain inferred source-facing names.

## Exact Formal RECONSTRUCTION_CPP CODE For [UID:0001JR]

This is exact formal target-block insertion content for `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`. It is not an illustrative side sample. During implementation, replace the target's formal marker/block with this exact marker/block content.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct TextRunDrawLineRecord
{
    unsigned short startIndex;
    unsigned short reserved02;
    int top;
    int remainingWidth;
    unsigned short wrapState;
    unsigned short reserved0e;
    unsigned short endIndex;
    unsigned short reserved12;
    int bottom;
};

struct TextRunDrawState
{
    RectBounds lineRect;
    RectBounds clippedLineRect;
    bool applyRunTextColor;
};

enum TextEditPaneTextAlignment
{
    kTextEditAlignLeft = 0,
    kTextEditAlignCenter = 1,
    kTextEditAlignRight = 2,
    kTextEditAlignTrimFinalWhitespace = 3
};

static bool __cdecl DrawTextRunCallback(TextRunDrawLineRecord *line,
                                        const TextRunFormatData *format,
                                        const wchar_t *text,
                                        int textOffset,
                                        unsigned short charCount,
                                        unsigned short segmentFlags,
                                        TextRunDrawState *state,
                                        TextEditPane *pane)
{
    (void)textOffset;

    unsigned short visibleCount = charCount;

    if (segmentFlags <= kTextRunHasNextSegment) {
        state->lineRect.left = pane->m_textAreaLeft;
        state->lineRect.top = pane->m_textAreaTop + line->top;
        state->lineRect.right = pane->m_textAreaRight;
        state->lineRect.bottom = pane->m_textAreaTop + line->bottom;

        pane->GetClipRect(&state->clippedLineRect);
        IntersectRects(&state->clippedLineRect, &state->lineRect, &state->clippedLineRect);

        const unsigned int oldDrawColor = pane->m_drawColor;
        pane->m_renderMode = 0;
        pane->SetDrawColor((pane->m_editorFlags & 0x02) == 0 ? pane->m_textBackColor : 0);
        g_pfnFillOrInvalidateRect(pane, &state->clippedLineRect);
        pane->SetDrawColor(oldDrawColor);

        int horizontalOffset = 0;
        if (pane->m_textAlignment == kTextEditAlignCenter) {
            horizontalOffset = line->remainingWidth / 2;
        } else if (pane->m_textAlignment == kTextEditAlignRight) {
            horizontalOffset = line->remainingWidth;
        }

        pane->MoveTo(state->lineRect.left + horizontalOffset,
                     state->lineRect.top + pane->GetLineHeight());
    }

    if (state->applyRunTextColor) {
        pane->SetTextColor(format->formatValue1);
    }

    if (format->object != NULL) {
        format->object->OnUpdate();
        return false;
    }

    if (pane->m_textAlignment == kTextEditAlignTrimFinalWhitespace &&
        (segmentFlags & kTextRunHasNextSegment) == 0) {
        visibleCount = static_cast<unsigned short>(
            AdjustVisibleCountForTrailingWhitespace(text, visibleCount));
    }

    pane->DrawTextRunSegment(text, visibleCount, 0, segmentFlags);
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why the formal block preserves behavior:

- Initializes the draw-state rectangles only for first/only fragment flags `0` or `1`, matching `(__int16)segmentFlags <= 1`.
- Builds `lineRect` from TextEditPane text-area bounds `+0x120/+0x124/+0x128` and line fields `+0x04/+0x14`.
- Calls `GetClipRect`, intersects clip and line rects, clears render mode byte `+0x70`, temporarily sets active draw color `+0x74`, dispatches slot `0x0069b3fc`, and restores old draw color.
- Uses line `remainingWidth` at `+0x08` for center/right horizontal offset and then moves to `lineRect.left + offset`, `lineRect.top + GetLineHeight()`.
- Applies run text color from `TextRunFormatData+0x04` only when caller state byte `+0x20` is true.
- Dispatches optional `TextEditObject` vtable slot `+0x0c` and returns without drawing plain text when `format->object` is non-null.
- Trims trailing visible whitespace only when TextEditPane alignment/mode `+0x8c` equals `3` and the segment is final (`segmentFlags & 1` clear).
- For plain text, forwards to lower renderer `0x005946b0` with the same arguments: text pointer, visible count, zero, and segment flags.
- Always returns false / zero, matching the final `xor al, al`.

Source-shape caveats for implementation:

- `TextRunFormatData`, `kTextRunHasNextSegment`, and `kTextRunHasPreviousSegment` are already emitted by [UID:0001JQ] before this target in `TextEditPane.cpp`; do not duplicate those definitions in [UID:0001JR].
- `TextRunDrawLineRecord` is intentionally draw-specific. A future shared text-run layout page can merge it with [UID:0001JQ]'s smaller measure-facing `TextRunLineRecord`, but that merge is not required for this target callback.
- `format->object->OnUpdate()` uses the current accepted [UID:00040S] provisional slot name. The target evidence strengthens that slot as an inline-object draw hook, but I am not recommending support C++ renaming in this pass.
- `m_textAreaLeft`, `m_textAreaTop`, `m_textAreaRight`, `m_textAlignment`, and `DrawTextRunSegment` are behavior-backed provisional source names. Implementation must document that they are inferred names, not original-proof spellings.

## Current MCP Facts

Function and boundary facts:

- `lookup_funcs` reports `0x00593db0` as `sub_593DB0`, size `0x146`; `0x00593ef5` resolves inside that function; `0x00593ef6` is not a function.
- The target half-open IDA range is `0x00593db0-0x00593ef6`; the existing page filename uses last-byte endpoint `0x00593ef5`.
- `get_bytes 0x00593dad` begins `cc cc cc 55 8b ec`, proving three pre-padding bytes before the prologue.
- `get_bytes 0x00593ef0` shows the target tail through `5d c3`, followed by ten `0xcc` bytes and the raw neighbor prologue at `0x00593f00`.
- `lookup_funcs 0x00593f00` reports not a function; `xrefs_to 0x00593f00` returns zero xrefs.

Address-taking route:

- `xrefs_to 0x00593db0` returns exactly two data/address-taking xrefs:
  - `0x005908e6` inside `sub_590810` size `0x1d3`.
  - `0x0059168c` in a raw/no-function island.
- `get_bytes 0x005908d0` and `0x00591670` both show `push 0x00593db0` and local state zeroing before `call sub_593500`.
- `decompile 0x00590810` shows `TextEditPane::OnDraw` computes visible line indices, writes `state+0x20` from `((*m_editorFlags & 0x40) == 0)`, zeros the first 32 bytes of state, pushes `sub_593DB0`, and calls `sub_593500`.
- The raw `0x00591650-0x005916b2` island mirrors the same setup for the invalidation/draw-list path and ends in `retn 8`; IDA still has no function object there.

Iterator ABI:

- `decompile 0x00593500` proves callback call shape:

```text
a4(v33, &v29, v41 + 2 * lineStart, lineStart, lineEnd - lineStart, flags, callerState, this)
```

- `v33` is the line-record pointer from `m_lineTable` at `this+0x138`.
- `&v29` is the stack `TextRunFormatData` built from the format/style table: the callback sees `formatValue0` at `+0x00`, `formatValue1` at `+0x04`, and optional `TextEditObject *object` at `+0x08`.
- Segment flags are generated as bit `0` = has next segment and bit `1` = has previous segment. Target uses the same `kTextRunHasNextSegment` semantics accepted for [UID:0001JQ].

Callee and behavior facts:

- `callees 0x00593db0` returns `0x004b96c0`, `0x004b7cc0`, `0x004b9660`, external `0x0069b3fc`, `0x004baaa0`, `0x004b9600`, `0x004b9680`, `0x004baad0`, and `0x005946b0`.
- Target decompile maps those to: `GetClipRect`, `IntersectRects`, `SetDrawColor`, fill/invalidate dispatch, `GetLineHeight`, `MoveTo`, text-color setter, `AdjustVisibleCountForTrailingWhitespace`, and the lower text-run renderer.
- Target reads/writes:
  - TextEditPane text-area bounds `+0x120/+0x124/+0x128`.
  - GrafPort render mode/draw color `+0x70/+0x74`.
  - GrafPort text/back colors `+0x7c/+0x80` through support helpers.
  - TextEditPane alignment/mode `+0x8c`.
  - TextEditPane editor flags `+0x15c`, specifically bit `1` for background fill color selection and bit `0x40` at callers for state `+0x20`.
  - Line record fields `+0x04`, `+0x08`, and `+0x14`.
  - Draw state fields `+0x00..+0x0f`, `+0x10..+0x1f`, and byte `+0x20`.
- `decompile 0x005946b0` confirms the lower renderer size `0x1ef` and role: it sets text draw mode byte `+0x88`, handles masked text via `m_maskedText +0x16a`, handles numeric/comma mode byte `+0x173`, detects leading `<B>` / `<b>` tag markup, calls `GetDrawPosition`, `MoveTo`, `DrawGlyphWithTextColors`, and `DrawWideText`.

## State And Field Layout Recommendation

`TextRunDrawState`:

| Field | Offset | Recommended name | Evidence |
| --- | ---: | --- | --- |
| `lineRect` | `+0x00` | unclipped line draw rectangle | Target writes left/top/right/bottom from pane text-area fields and line record fields before clipping. |
| `clippedLineRect` | `+0x10` | current line clip rectangle | Target calls `GetClipRect`, intersects with `lineRect`, then sends this rect to slot `0x0069b3fc`. |
| `applyRunTextColor` | `+0x20` | apply current run text color flag | Both callers write byte `state+0x20` from `((*m_editorFlags & 0x40) == 0)` before passing state; target checks it before calling `0x004b9680`. |

`TextRunDrawLineRecord` overlay:

| Field | Offset | Recommended name | Evidence |
| --- | ---: | --- | --- |
| `startIndex` | `+0x00` | start text index | Same line-record start used by iterator and [UID:0001JQ]. |
| `top` | `+0x04` | line top relative to text area | Target adds it to pane `+0x124` for `lineRect.top`. |
| `remainingWidth` | `+0x08` | measured unused/slack width | [UID:0001JQ] writes this field after measurement; target uses it for center/right alignment offset. |
| `wrapState` | `+0x0c` | existing line/wrap state | Already documented by [UID:0001JQ]; target does not read it. |
| `endIndex` | `+0x10` | line end text index | Iterator reads `v33[8]` at `+0x10` to find the line end. Target does not read it directly. |
| `bottom` | `+0x14` | line bottom relative to text area | Target adds it to pane `+0x124` for `lineRect.bottom`. |

TextEditPane field/name additions for support docs:

| Offset | Recommended source-facing name | Evidence |
| ---: | --- | --- |
| `+0x120` | `m_textAreaLeft` | Used with `+0x128` as available width by [UID:0001JQ] and as draw rect left by this target. |
| `+0x124` | `m_textAreaTop` | Subtracted from clip y values in OnDraw and added to line top/bottom in this target. |
| `+0x128` | `m_textAreaRight` | Used with `+0x120` for available line width and as draw rect right. |
| `+0x8c` | `m_textAlignment` / text alignment mode | Values `1` and `2` use half/full `remainingWidth`; value `3` trims trailing whitespace on final segments. |
| `0x005946b0` | `TextEditPane::DrawTextRunSegment` | Lower renderer for visible text slices; exact original spelling remains inferred. |

## Rejected Alternatives

- `TextEditPane::DrawTextRunCallback` member method: rejected. The target is a `__cdecl` callback and is passed by address to `TextEditPane::IterateTextRuns`.
- FittingRoom owner/generated stale slice: rejected. The stale FittingRoom slice begins/ends inside real TextEditPane callback bodies, and current xrefs route only to TextEditPane draw/invalidation paths.
- Merge with [UID:0003FD] raw thiscall variant: rejected. `0x00593f00` is not an IDA function and has zero direct start xrefs; it remains a separate raw no-route variant.
- Keep formal C++ blank: rejected for [UID:0001JR]. The target-specific state layout and source-facing callback shape are now sufficiently proven for first-draft C++.
- Rewrite [UID:0001JQ] formal structs now: rejected for this pass. The target can introduce a draw-line overlay without invalidating the accepted measure callback.
- Rename `TextEditObject::OnUpdate()` in support C++ now: rejected. This target improves the slot role to inline-object draw hook evidence, but support C++ renaming should be a separate class/source-shape decision.

## Recommended Target Doc Changes

Target path: `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`

Required implementation details:

- Set `COMPLETION:90`, `CONFIDENCE:91`.
- Preserve `CANONICAL_OWNER:0000ON`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ON`, blank emitter position, and `Nested:0`.
- Replace the formal C++ marker/block with the exact formal block from this report.
- Update Item Summary to state that the callback is first-draft C++ ready with `TextRunDrawState`, `TextRunDrawLineRecord`, two address-taken iterator refs, MCP session `80de0a67`, raw-neighbor separation, and lower renderer forwarding.
- Add report-level evidence for:
  - `sub_593DB0` size `0x146` / 326 bytes and IDA half-open range `0x00593db0-0x00593ef6`.
  - `0x00593dad-0x00593db0` pre-padding and `0x00593ef6-0x00593f00` post-padding.
  - Address-taking refs `0x005908e6` and `0x0059168c`, and zero raw-start xrefs for `0x00593f00`.
  - `TextEditPane::IterateTextRuns` callback ABI and segment flags.
  - `TextRunDrawState` layout `+0x00/+0x10/+0x20`.
  - TextEditPane text-area fields `+0x120/+0x124/+0x128`, alignment/mode `+0x8c`, flags `+0x15c`, and caller-set run-color flag from bit `0x40`.
  - GrafPort dependencies `GetClipRect`, `IntersectRects`, `SetDrawColor`, `MoveTo`, text-color setter `0x004b9680`, `GetLineHeight`, `AdjustVisibleCountForTrailingWhitespace`, `g_pfnFillOrInvalidateRect`, and `DrawTextRunSegment`.
  - Optional `TextEditObject` object pointer at `TextRunFormatData+0x08` and vtable slot `+0x0c`.
  - Generated/autogen stale state: generated TextEditPane output still shows [UID:0001JR] as `78/86` with empty marker before accepted implementation.

## Recommended Support Doc Changes

Support path: `by-item/DrawTextRunCallback_00593DB0.md`

- Required. Sync with target state: score `90/91`, first-draft-ready status, exact callback ABI, `TextRunDrawState`, draw-line overlay, two address-taken refs, lower renderer route, raw-neighbor exclusion, and stale generated `78/86` note.
- Keep this as an item mirror/support page; do not insert the target formal C++ here.

Support path: `by-file/TextEditPane.md`

- Required. Update source-emission policy so both [UID:0001JQ] and [UID:0001JR] are target-level first-draft ready, while [UID:0003FC]/[UID:0003FD] raw variants remain blank/no-route.
- Update the `DrawTextRunCallback` row with `TextRunDrawState`, `TextRunDrawLineRecord`, text-area bounds `+0x120/+0x124/+0x128`, alignment `+0x8c`, caller state byte `+0x20`, `formatValue1` text color, optional inline object vtable dispatch, final-segment whitespace trim, and lower renderer `0x005946b0`.
- Replace stale wording that says draw/raw callback-state names block this target's formal C++. Keep broad helper/raw variant caveats where still true.
- Add source-shape note that file-local callbacks require access to TextEditPane/GrafPort fields and shared `AdjustVisibleCountForTrailingWhitespace`.

Support path: `by-class/TextEditPane.md`

- Required. Update method/helper table row for `0x00593db0` to say `DrawTextRunCallback` is a file-local first-draft-ready callback with `TextRunDrawState`; not a class method body.
- Add field-map prose for `m_textAreaLeft` `+0x120`, `m_textAreaTop` `+0x124`, `m_textAreaRight` `+0x128`, and `m_textAlignment` `+0x8c` as inferred source-facing names.
- State that method-body C++ lives on [UID:0001JR], while class formal C++ remains declaration-only.

Support path: `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md`

- Required. Update lower renderer row `0x005946b0-0x0059489f` with recommended name `TextEditPane::DrawTextRunSegment`, [UID:0001JR] caller evidence, lower renderer size `0x1ef` / 495 bytes, masked text `+0x16a`, format/comma mode `+0x173`, `<B>`/`<b>` markup branch, `DrawWideText`, `DrawGlyphWithTextColors`, `GetDrawPosition`, and `MoveTo`.
- Keep aggregate formal C++ blank because broad cursor/navigation/wrap/raw helper signatures remain unresolved.

Support path: `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`

- Required. Add [UID:0001JR] as the draw-side TextEditPane consumer of `GrafPort::GetLineHeight`, `AdjustVisibleCountForTrailingWhitespace`, `DrawGlyphWithTextColors`, and `DrawWideText` through lower renderer `0x005946b0`.
- Preserve GrafPort owner/emitter/score and existing formal C++; do not duplicate helpers into TextEditPane source without documenting shared visibility.

Support path: `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`

- Required. Add [UID:0001JR] as a concrete consumer of `MoveTo`, `SetDrawColor`, and the `0x004b9680` text-color setter. Preserve the B001 correction that `0x004b9680` stores primary text color at `+0x7c`; do not regress to caller-biased `SetBkColor` wording for this target.
- Preserve owner/emitter/score and blank formal C++.

Support path: `by-class/TextEditObject.md`

- Required prose-only update. Add [UID:0001JR] as callsite evidence for vtable slot `+0x0c`: when `TextRunFormatData::object` is non-null, `DrawTextRunCallback` dispatches this slot and skips plain text drawing.
- Preserve the current provisional method name `OnUpdate()` unless a separate support-object class pass renames the virtual hook. This target alone should not edit class formal C++.

Support path: `by-class/EPFTextEditObject.md`

- Required prose-only update. Add that [UID:0001JR] is a live draw-callback callsite for the EPF derived slot `+0x0c` / `0x005955a0` virtual draw/layout helper when inline text objects are encountered.
- Preserve class score/formal C++ unless a separate EPF support-object pass chooses to rename fields/hooks.

Check-only pages with no edit recommended unless implementation discovers a contradiction:

- [UID:0001JQ] `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md`: no edit. Its `TextRunFormatData` and segment flags are reused; target adds a draw overlay instead of rewriting this accepted formal block.
- [UID:0003FC] `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md`: no edit. Separate raw measure variant remains blank/no-route.
- [UID:0003FD] `by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md`: no edit unless stale prose says the cdecl target is still blocked. Current no-function/zero-xref raw-route evidence remains valid.
- [UID:000164] `by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md`, [UID:00015S] `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`, and [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md`: no edit required because current pages already document the generic helper/table roles at adequate detail, and this target adds consumer evidence only.

## Score And Metadata Recommendation

Current target metadata:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000ON`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000ON`

Recommended target metadata:

- `COMPLETION:90`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000ON` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:0000ON` unchanged

Reason not higher:

- Exact original spellings for text-area fields, alignment enum, and lower renderer are still inferred.
- The target depends on [UID:0001JQ]'s existing `TextRunFormatData`/segment flag declarations rather than a final shared text-run layout header.
- The inline object virtual hook remains named `OnUpdate()` in current support C++; this target improves role evidence but does not resolve the product spelling.

Reason not lower:

- Function boundary, padding, xrefs, caller setup, iterator ABI, callee set, state layout, field use, optional object route, trim behavior, and raw-neighbor exclusion are all current MCP-backed.
- First-draft C++ can be written without `sub_`, `dword_`, `unk_`, or decompiler temporaries.
- Source placement and emitter route are already strong and unchanged.

## Open Questions With Attempted Resolution

- Exact original type names: unresolved, but `TextRunDrawState`, `TextRunDrawLineRecord`, and `TextRunFormatData` are behavior-backed and sufficient for first-draft C++.
- `+0x120/+0x124/+0x128` field spellings: exact original names unresolved. The best current names are `m_textAreaLeft`, `m_textAreaTop`, and `m_textAreaRight` because [UID:0001JQ] uses `right-left` as available width and this target uses them as draw rect coordinates.
- `+0x8c` mode name: exact enum unresolved. Values `1`, `2`, and `3` support `m_textAlignment` / text alignment mode; value `3` is documented descriptively as final whitespace trim mode.
- Lower renderer name: exact original spelling unresolved. `DrawTextRunSegment` is the best target-specific name from the two draw callbacks and renderer behavior.
- Inline object hook name: target proves the virtual callsite but not the product spelling. Keep support C++ name `OnUpdate()` and document the stronger draw-hook role.

## Validator Expectations

Run these exact scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` during accepted implementation, one command per edited by-* file:

- `python .\tools\validator.py --mode file --file by-memory\0x00593db0-0x00593ef5.DrawTextRunCallback.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-item\DrawTextRunCallback_00593DB0.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-file\TextEditPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-class\TextEditPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-class\TextEditObject.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-class\EPFTextEditObject.md --apply --queue-timeout 240`

Do not run validators for check-only pages unless implementation edits them due a contradiction. If edited, use the same exact command shape with that relative path.

Expected generated refresh:

- Generated TextEditPane C++ should refresh [UID:0001JR] from stale generated `78/86` empty marker to target `90/91` with the formal C++ block if the validator/autogen queue is functioning.
- Generated tracker/coverage files should refresh through validator-owned jobs only. Do not manually edit `auto-generated`, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.

## Report-Only Pass State

- Report-only file created/updated: `tools/leaser/Agents/Agent-B006/research/0001JR-DrawTextRunCallback-source-quality.md`.
- No by-* docs were edited.
- No generated/project-level generated files, manual coverage reports, validator/tool state, or IDA DB files were edited.
- No leases were taken in this report-only phase.
- Scoped validators were not run in this report-only phase; the exact required commands are listed above for the accepted implementation callback.
- Implementation checklist below is intentionally unchecked.

## Implementation Callback Pass State

- Supervisor acceptance received through `Agent-B006/goal.md`; implementation callback applied on 2026-06-26.
- Changed by-* files:
  - `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`
  - `by-item/DrawTextRunCallback_00593DB0.md`
  - `by-file/TextEditPane.md`
  - `by-class/TextEditPane.md`
  - `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md`
  - `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
  - `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
  - `by-class/TextEditObject.md`
  - `by-class/EPFTextEditObject.md`
- No-edit proof recorded for check-only pages: [UID:0001JQ], [UID:0003FC], [UID:0003FD], [UID:000164], [UID:00015S], and [UID:0000TN] were not edited because implementation found no contradiction with this report. Their existing roles remain adequate for this callback: [UID:0001JQ] supplies `TextRunFormatData` and segment flags, [UID:0003FC]/[UID:0003FD] remain raw/no-route variants, and GrafPortGetClipRect/RectGeometryHelpers/SurfaceRenderCallbackTable already document the generic dependency roles.
- Leases: each edited by-* file was leased as `B006` immediately before its edit/validator batch and released immediately after validation. Final lease release commands succeeded for all nine edited paths; no active B006 lease was intentionally retained.
- Manual exclusions honored: no manual edits were made to `auto-generated/*`, `project-level/*`, manual `-coverage-report.md` files, validator/leaser state, or IDA DB files. Validator-owned side effects updated generated/project-level/tool state as part of scoped validation.
- Validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory\0x00593db0-0x00593ef5.DrawTextRunCallback.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000002843`, `command_timestamp: 2026-06-26T16:21:48-04:00`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-item\DrawTextRunCallback_00593DB0.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000002844`, `command_timestamp: 2026-06-26T16:22:54-04:00`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-file\TextEditPane.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000002845`, `command_timestamp: 2026-06-26T16:24:09-04:00`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class\TextEditPane.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000002884`, `command_timestamp: 2026-06-26T16:26:49-04:00`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000002900`, `command_timestamp: 2026-06-26T16:27:52-04:00`, `ok: 1`, `generated_refresh: deferred`; validator also recorded `path_update` from the stale `0x00594040-0x00594e11.TextEditPaneInputNavigationAndWrap.md` path to the current filename and refreshed reference-source paths.
  - `python .\tools\validator.py --mode file --file by-memory\0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000002909`, `command_timestamp: 2026-06-26T16:28:56-04:00`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000002912`, `command_timestamp: 2026-06-26T16:29:44-04:00`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class\TextEditObject.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000002916`, `command_timestamp: 2026-06-26T16:30:29-04:00`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class\EPFTextEditObject.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000002918`, `command_timestamp: 2026-06-26T16:31:12-04:00`, `ok: 1`, `generated_refresh: deferred`.
- Validator diagnostics: scoped validators returned `ok: 1` for every edited file. Remaining diagnostics were existing stale/missing UID/reference/path warnings, mostly around unregistered split UIDs or stale historical paths; no target-specific validation failure was reported. Do not hand-edit validator state for those diagnostics.
- Generated refresh state: deferred jobs were allowed to drain. `python .\tools\validator.py --queue-status` at `command_id: 000000002926`, `2026-06-26T16:32:43-04:00`, reported `queued generated refresh jobs: 0` and `processing generated refresh jobs: 0`.
- Generated header freshness: `auto-generated/NexusTK/ui/controls/TextEditPane.cpp` now has `validator-command-id: 000000002918` and `validator-refreshed-at: 2026-06-26T16:31:12-04:00`, equal to the latest edited support validator and newer than the target validator. The generated file contains `// UID:0001JR | by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md | Completion:90 | Confidence:91` followed by the formal `TextRunDrawLineRecord`, `TextRunDrawState`, and `DrawTextRunCallback` block.

## Implementation Tracking Checklist

- [x] Supervisor acceptance received before by-* edits. Proof: implementation callback override is present in `Agent-B006/goal.md` for this accepted report.
- [x] Lease check completed immediately before edits; no active lease conflict for each edited path. Proof: `current_leases.md` only showed stale expired 2026-06-18 leases for unrelated FittingRoom/tracker paths; each edited by-* file was subsequently leased successfully as `B006`.
- [x] Target `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md` updated to `COMPLETION:90`, `CONFIDENCE:91`, owner/emitter/reconstructable preserved, Item Summary replaced, and exact formal `RECONSTRUCTION_CPP CODE` marker/block inserted from this report. Proof: validator `000000002843`, `ok: 1`; generated TextEditPane output now includes UID `0001JR` at `90/91` with the formal block.
- [x] Target prose updated with MCP session `80de0a67`, listener/process/health facts, function size `0x146` / 326, half-open range `0x00593db0-0x00593ef6`, padding, two address-taken refs, iterator ABI, state layout, line overlay, field offsets, lower renderer route, raw-neighbor separation, generated stale state, rejected alternatives, score rationale, and source-placement reasoning. Proof: target page now contains B006 source-quality sections for callback ABI/state/source shape and first-draft behavior notes.
- [x] `by-item/DrawTextRunCallback_00593DB0.md` updated as item mirror/support with score/status/evidence parity; no formal target C++ inserted there. Proof: validator `000000002844`, `ok: 1`; page is `90/91` and explicitly says the formal block lives on [UID:0001JR].
- [x] `by-file/TextEditPane.md` updated for first-draft-ready [UID:0001JR], TextRunDrawState, draw-line overlay, text-area fields, lower renderer, raw variants still blank/no-route, and generated stale-state caveat. Proof: validator `000000002845`, `ok: 1`.
- [x] `by-class/TextEditPane.md` updated for method/helper row, source-route wording, inferred text-area/alignment fields, and declaration-only class C++ policy. Proof: validator `000000002884`, `ok: 1`; class page now keeps method-body C++ on exact by-memory children.
- [x] `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md` updated for lower renderer `0x005946b0` / `DrawTextRunSegment` role and [UID:0001JR] caller proof; aggregate formal C++ remains blank. Proof: validator `000000002900`, `ok: 1`; generated/path registry also updated stale 0001JS path metadata.
- [x] `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` updated for [UID:0001JR] draw-side consumer proof and shared helper visibility; existing formal C++ preserved. Proof: validator `000000002909`, `ok: 1`.
- [x] `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md` updated for [UID:0001JR] consumers of `MoveTo`, `SetDrawColor`, and text-color setter `0x004b9680`; existing formal C++ preserved. Proof: validator `000000002912`, `ok: 1`; covered-function row now preserves the `0x004b9680` primary text-color correction.
- [x] `by-class/TextEditObject.md` updated with [UID:0001JR] callsite evidence for vtable slot `+0x0c`; no class formal C++ rename unless separately approved. Proof: validator `000000002916`, `ok: 1`; provisional `OnUpdate()` name preserved.
- [x] `by-class/EPFTextEditObject.md` updated with [UID:0001JR] as a live callsite for the derived virtual draw/layout helper `0x005955a0`; no class formal C++ inserted. Proof: validator `000000002918`, `ok: 1`.
- [x] Check-only no-edit proof recorded for [UID:0001JQ], [UID:0003FC], [UID:0003FD], GrafPortGetClipRect, RectGeometryHelpers, and SurfaceRenderCallbackTable unless implementation finds direct contradiction. Proof: implementation found no contradiction; no check-only page was edited or validated.
- [x] Exact scoped validators run for every edited by-* file using the commands listed above; record command, command_id, command_timestamp, exit code, ok count, warnings, and generated-refresh state. Proof: see Implementation Callback Pass State validators list; all nine returned exit `0` and `ok: 1`.
- [x] Report checklist updated after implementation with checked proof for every edit/no-edit decision, validators, generated-refresh observation, and lease release proof. Proof: this checklist and Implementation Callback Pass State section.
- [x] All B006 leases released immediately after edit/validator batch; no active B006 leases remain. Proof: `leaser.py B006 unlease <path>` succeeded for every edited by-* file after validation.
- [x] Manual coverage reports, generated files, project-level generated files, validator/tool state, and IDA DB were not edited manually. Proof: all generated/project-level/tool-state changes were validator-owned side effects; no manual edits were made to excluded files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001JR-DrawTextRunCallback-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0001JR-DrawTextRunCallback-source-quality.md","timestamp":"2026-06-26T16:38:34","uid":"0001JR"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001JR-DrawTextRunCallback-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0001JR-DrawTextRunCallback-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001JR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
