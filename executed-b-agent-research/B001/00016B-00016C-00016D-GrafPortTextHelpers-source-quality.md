** TARGET-REPORT-UID:00016B **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-grafport-text-helper-cluster-source-quality-00016B-00016C-00016D-20260618

## Finalized Report / Current Recommendation

Recommended disposition:

- [UID:00016B] `0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md`: keep direct owner/emitter [UID:00005V][GrafPort](../../../by-class/GrafPort.md), keep `RECONSTRUCTABLE:TRUE`, populate formal C++ now, and raise metadata from `86/90` to `88/91`.
- [UID:00016C] `0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`: reroute direct owner/emitter from file bucket [UID:0000JR][GrafPort](../../../by-file/GrafPort.md) to class [UID:00005V][GrafPort](../../../by-class/GrafPort.md), keep `RECONSTRUCTABLE:TRUE`, populate formal C++ now, and raise metadata from `86/89` to `88/90`. The current memory coverage row is stale at `78%` and should be replaced.
- [UID:00016D] `0x004bad70-0x004baf92.DrawTextInRect.md`: keep direct owner/emitter [UID:00005V][GrafPort](../../../by-class/GrafPort.md), keep `RECONSTRUCTABLE:TRUE`, populate formal C++ now, and raise metadata from `86/90` to `88/91`.

The best source placement remains `NexusTK/render/GrafPort.cpp` through [UID:0000JR][GrafPort](../../../by-file/GrafPort.md). No child split is recommended. The three current aggregates are source-coherent: [UID:00016B] covers text fit/suffix helpers, [UID:00016C] covers width/line/run/outline text helpers, and [UID:00016D] covers the wrapped rectangle text method. Feature panes, FontImageLib, Surface, and generated caller classes remain dependencies or consumers, not owners.

The primary source-quality blockers in the target pages are resolved enough for first-draft C++: source-facing names/signatures, field roles at `+0x68/+0x6c/+0x70/+0x71/+0x74/+0x78/+0x7c/+0x80/+0x84/+0x88/+0x8a/+0x8c`, `g_pFontImageLib` naming, `StringIter` role, `RectBounds` role, callback-table dependencies, 00016C owner/source placement, and the stale 00016C coverage row.

## Evidence Checked

Documents and support pages checked:

- [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](../../../by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md).
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](../../../by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md).
- [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](../../../by-memory/0x004bad70-0x004baf92.DrawTextInRect.md).
- [UID:00005V][GrafPort](../../../by-class/GrafPort.md), [UID:0000JR][GrafPort](../../../by-file/GrafPort.md), and [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](../../../by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md).
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](../../../by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](../../../by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md), [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](../../../by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md), [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](../../../by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md), [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](../../../by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md), and [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](../../../by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md).
- Font dependencies: [UID:0000JH][FontImageLib](../../../by-file/FontImageLib.md), [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](../../../by-memory/0x004b5f00-0x004b6409.FontImageLib.md), [UID:0000QX][g_pFontImageLib](../../../by-global/g_pFontImageLib.md), [UID:0002HQ][0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics](../../../by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md), and [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](../../../by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md).
- Type/callback dependencies: [UID:0000E7][StringIter](../../../by-class/StringIter.md), [UID:0001VP][RectBoundsLayout](../../../by-type/by-struct/RectBoundsLayout.md), [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](../../../by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md), [UID:0000TN][SurfaceRenderCallbackTable](../../../by-global/SurfaceRenderCallbackTable.md), and [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](../../../by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md).
- Current coverage rows in `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md`.
- Executed B-agent support reports already applied to docs for nearby GrafPort helpers: B003 `GrafPort::BlitSurface` / [UID:000167], B002 `GrafPort::DrawRectFrame` / [UID:000168], B002 `GrafPort::DrawTiledBackground` / [UID:00016A], and B002/B003 `GrafPortPatternPackRaw` / [UID:0003XF]. These were used only as already-incorporated support evidence; no unexecuted B002/B003 conclusions were treated as proof.

Tooling and raw evidence:

- Current IDA MCP connection at `127.0.0.1:13337` was unavailable for this turn, so no IDA DB edits or new IDA-backed names were written. The current pass used the existing by-* IDA evidence plus local raw PE and Capstone disassembly.
- Binary checked: `E:\NTK\Resources\NexusTK\NexusTK.exe`.
- Custom PE parser confirmed image base `0x00400000` and `.text` section RVA `0x1000`.
- Local Capstone disassembly and raw `E8 rel32` scans were used to validate function body behavior and direct call counts. The raw scan used exact PE bytes, not generated source.
- Direct `E8 rel32` references found in `.text`:
  - `0x004ba820`: 21 direct call references.
  - `0x004ba8b0`: 4 direct call references.
  - `0x004ba9a0`: 117 direct call references.
  - `0x004baa70`: 64 direct call references.
  - `0x004baaa0`: 67 direct call references.
  - `0x004baad0`: 4 direct call references.
  - `0x004bab20`: 3 direct call references.
  - `0x004bab70`: 188 direct call references.
  - `0x004bacd0`: 31 direct call references.
  - `0x004bad70`: 130 direct call references.
  - `0x004bb5e0`: 2 direct call references, both from [UID:00016C] at `0x004bab57` and `0x004bac8a`.
- Raw dword operand scans found 52 `.text` references to `0x0067ab24` / `g_pFontImageLib`, including target refs at `0x004ba8e1`, `0x004ba9cc`, `0x004baab1`, `0x004babe4`, `0x004badb3`, and [UID:00016I] refs at `0x004bb5f6`, `0x004bb6ae`, `0x004bb6f4`, `0x004bb73c`.
- Raw dword operand scans also confirmed target-related callback slots in `SurfaceRenderCallbackTable`: `0x0069b3e8` is the sprite/tile blit callback used by `GrafPortDrawGlyph`, and `0x0069b3fc` is the fill/invalidate/presentation callback used by [UID:00016C] background fill and [UID:00016I] optional glyph fill paths.

## Raw PE / Disassembly Facts

### [UID:00016B] `0x004ba820-0x004ba991`

`0x004ba820-0x004ba8a2` is a `GrafPort` receiver method with `ret 0x10` and four explicit stack arguments. The source-facing signature is best modeled as:

```cpp
void GrafPort::FitTextAndAppendSuffix(wchar_t *text,
                                      size_t textCapacity,
                                      const wchar_t *suffix,
                                      int maxPixelWidth);
```

The body measures the destination text by calling `0x004ba9a0`, compares the width against `maxPixelWidth`, measures the suffix by calling `0x004ba9a0`, subtracts the suffix width, calls `0x004ba8b0` to find the number of original characters that still fit, writes `text[keepCount] = L'\0'`, and calls `wcscat_s` at `0x005de0f0` with the original destination buffer, destination capacity, and suffix.

`0x004ba8b0-0x004ba991` is a `GrafPort` receiver method with `ret 8` and two explicit stack arguments. The source-facing signature is best modeled as:

```cpp
int GrafPort::CountCharsFittingWidth(const wchar_t *text, int maxPixelWidth);
```

The body constructs `StringIter(text, wcslen(text))`, reads current and next glyphs with `StringIter::GetNextChar`, calls `g_pFontImageLib->MeasureGlyphWidth(m_fontStyleId, glyph, nextGlyph, ..., &advance, ...)`, accumulates advances, and returns the count before the accumulated width would exceed `maxPixelWidth`. It reads the receiver font/style field at `this + 0x8a`.

### [UID:00016C] `0x004ba9a0-0x004bad66`

`0x004ba9a0-0x004baa67` is a `GrafPort` receiver method with `ret 8`, explicit arguments `(const wchar_t *text, int charCount)`, and a 16-bit width return. It constructs `StringIter(text, charCount)`, calls `FontImageLib::MeasureGlyphWidth` for each glyph with `m_fontStyleId` from `this + 0x8a`, and returns the sum of glyph advances. The best source-facing name is `GrafPort::GetTextWidth(const wchar_t *text, int charCount)`.

`0x004baa70-0x004baa9e` is the null-terminated overload with `ret 4`; it computes `wcslen(text)` and forwards to `0x004ba9a0`. The best source-facing name is `GrafPort::GetTextWidth(const wchar_t *text)`.

`0x004baaa0-0x004baac5` is a no-explicit-argument `GrafPort` receiver method. It calls `g_pFontImageLib->GetFontMetrics(m_fontStyleId, NULL, &lineHeight)` and returns the line height. The best source-facing name is `GrafPort::GetLineHeight()`.

`0x004baad0-0x004bab12` is a standalone or file-local helper with `ret 8` and explicit arguments `(const wchar_t *text, int count)`. It does not read the `GrafPort` receiver even when callers happen to preserve/set `ecx`. It scans backward over trailing `L' '`, `L'\t'`, and `L'\r'`, computes the last non-trailing-whitespace index, and returns either the original count or that index through the observed `cmovle` shape. Existing "trims trailing spaces" wording is directionally useful but incomplete: the exact source semantics are an adjustment of a visible count/limit, not a simple string trim. The best descriptive source name is `AdjustVisibleCountForTrailingWhitespace` or `TrimVisibleCountLimit`; use `AdjustVisibleCountForTrailingWhitespace` in drafts because it preserves the conditional nature of the return value.

`0x004bab20-0x004bab6c` is a `GrafPort` receiver method with `ret 8` and explicit glyph/next-glyph arguments. It builds a six-byte color pattern from `this + 0x7c` and `this + 0x80`, then calls [UID:00016I][GrafPortDrawGlyph](../../../by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md) with fill/background flag `0`. The best source-facing name is `GrafPort::DrawGlyphWithTextColors(wchar_t ch, wchar_t nextCh)`.

`0x004bab70-0x004bacc8` is a `GrafPort` receiver method with `ret 8` and explicit arguments `(const wchar_t *text, int charCount)`. If the signed low word of `charCount` is negative, it returns. It builds the same six-byte text color pattern, optionally fills/invalidates the text background rectangle when `m_textDrawMode` at `this + 0x88` is `0` or `2`, iterates the run with `StringIter`, and calls `DrawGlyph` once per glyph. The best source-facing name is `GrafPort::DrawWideText(const wchar_t *text, int charCount)`.

`0x004bacd0-0x004bad67` is a `GrafPort` receiver method with `ret 0x10` and explicit arguments `(int x, int y, const wchar_t *text, int charCount)`. It saves `m_textColor`, temporarily copies `m_textBackColor` to `m_textColor`, draws the run at `(x, y-1)`, `(x, y+1)`, `(x-1, y)`, and `(x+1, y)`, restores the original text color, then draws the main run at `(x, y)`. The best source-facing name is `GrafPort::DrawOutlinedText(int x, int y, const wchar_t *text, int charCount)`.

### [UID:00016D] `0x004bad70-0x004baf92`

`0x004bad70-0x004baf92` is a `GrafPort` receiver method with `ret 0x0c` and explicit stack-argument order `(const wchar_t *text, int length, const RectBounds *rect)`. The best source-facing signature is:

```cpp
void GrafPort::DrawTextInRect(const wchar_t *text, int length, const RectBounds *rect);
```

The body exits early when `m_drawEnabled` at `this + 0x71` is clear, saves `m_currentY` and `m_currentX` from `this + 0x68/+0x6c`, obtains line height through `g_pFontImageLib->GetFontMetrics(m_fontStyleId, NULL, &lineHeight)`, initializes the cursor to `rect->left/top`, and loops until `index >= length` or `m_currentY > rect->bottom`.

Each line calls `CountCharsFittingWidth(text + index, rect->right - rect->left)`, clamps to remaining length, copies `fit * sizeof(wchar_t)` bytes into a stack line buffer through the memmove wrapper at `0x00516220`, range-checks against the `0x200` byte buffer before null termination, increments the Y cursor by the line height, chooses alignment from `this + 0x8c`, calls `DrawWideText(line, fit)`, advances by `fit`, and skips a single following space at a wrap boundary. The epilogue restores `m_currentX` and `m_currentY`.

## Heuristic / Inference Reanalysis And Validation

### Source-Facing Names And Signatures

| Address | Final best source-facing name/signature | Basis | Rejected alternatives |
| --- | --- | --- | --- |
| `0x004ba820` | `void GrafPort::FitTextAndAppendSuffix(wchar_t *text, size_t textCapacity, const wchar_t *suffix, int maxPixelWidth)` | Four explicit args, receiver calls text width helper twice, sibling fit-count helper, NUL write, `wcscat_s` append. | `ClanItemListPane` helper is caller-biased; `sub_4BA820` is generated; `TruncateString` loses suffix behavior. |
| `0x004ba8b0` | `int GrafPort::CountCharsFittingWidth(const wchar_t *text, int maxPixelWidth)` | Two explicit args, `StringIter`, `g_pFontImageLib->MeasureGlyphWidth`, accumulated width threshold. | `MeasureTextWidth` is wrong because it returns count; `FontImageLib` owner is wrong because receiver state supplies font/style and helper is used by GrafPort wrappers. |
| `0x004ba9a0` | `short GrafPort::GetTextWidth(const wchar_t *text, int charCount)` | Two explicit args, summed glyph advances, broad callers, null-terminated overload forwards here. | `MeasureStringWidth` acceptable as a descriptive alias but weaker than overload pair `GetTextWidth`; generated feature-owner names are caller pollution. |
| `0x004baa70` | `short GrafPort::GetTextWidth(const wchar_t *text)` | One explicit arg, computes `wcslen`, forwards to length overload. | Separate helper class or free utility rejected because receiver and overload chain are GrafPort text state. |
| `0x004baaa0` | `short GrafPort::GetLineHeight()` | No explicit args, calls `FontImageLib::GetFontMetrics` for current `m_fontStyleId`. | `FontImageLib::GetLineHeight` owner rejected because body reads GrafPort current font/style. |
| `0x004baad0` | `static int __stdcall AdjustVisibleCountForTrailingWhitespace(const wchar_t *text, int count)` | Ignores receiver, scans trailing `space/tab/CR`, used only by text callback area, exact return is visible-count adjustment. | `CountVisibleChars` overstates the trim effect; `GrafPort` method not proven because receiver is unused; separate public API not supported by only four direct callers. |
| `0x004bab20` | `void GrafPort::DrawGlyphWithTextColors(wchar_t ch, wchar_t nextCh)` | Two explicit glyph args, builds color pattern from GrafPort text colors, only calls `DrawGlyph`. | `CollectionEntryControlPane` owner is caller-biased; `DrawChar` alone omits use of paired next-glyph argument and text colors. |
| `0x004bab70` | `void GrafPort::DrawWideText(const wchar_t *text, int charCount)` | Text run iteration, background fill, per-glyph draw, 188 direct callers. | `DrawString` plausible but less precise because all text is UTF-16/wide and length-counted. |
| `0x004bacd0` | `void GrafPort::DrawOutlinedText(int x, int y, const wchar_t *text, int charCount)` | Four one-pixel offset passes in background/outline color followed by foreground pass. | `DrawShadowedText` rejected for this exact helper because offsets are all four cardinal directions, not a one-direction shadow. |
| `0x004bad70` | `void GrafPort::DrawTextInRect(const wchar_t *text, int length, const RectBounds *rect)` | Three explicit args in raw stack order, line wrapping, alignment, bounded line buffer, broad callers. | `TextButtonControlPane::DrawTextInRect` is historical generated/caller lead; stack order `(text, rect, length)` is contradicted by raw argument use. |

### Owner / Source Placement

Ranked owner analysis:

1. [UID:00005V][GrafPort](../../../by-class/GrafPort.md) in [UID:0000JR][GrafPort](../../../by-file/GrafPort.md), source path `NexusTK/render/GrafPort.cpp`: accepted. Every receiver-bearing function in this cluster reads or writes GrafPort draw state, font state, cursor state, text color state, or alignment state. Neighboring accepted GrafPort render helpers [UID:000167], [UID:000168], [UID:00016A], and [UID:00016I] also share these fields and callback-table dependencies. This route supports formal C++ emission.
2. [UID:0000JR][GrafPort](../../../by-file/GrafPort.md) as direct owner/emitter for [UID:00016C]: rejected as final direct owner, but retained as the source-file container. The file bucket was a conservative interim route while field/API names were unresolved. The class is now strong enough for direct owner/emitter metadata because six of seven functions are `GrafPort` receiver methods and the local static helper is only a text-run support routine.
3. A separate `render/TextDrawing.cpp` or private GrafPort text utility split: not recommended now. It is plausible as a historical source-file organization, but no independent class, vtable, global namespace, or non-GrafPort state boundary is visible. Current proposed source tree already places `GrafPort.cpp` under `render/`.
4. Feature pane owners such as `ClanItemListPane`, `FittingRoomDownloadControlPane`, `CollectionEntryControlPane`, `RankingEventListPane`, and `TextButtonControlPane`: rejected. They are consumers from generated output or caller samples. Raw call counts show broad UI fan-in, and the bodies operate on GrafPort state.
5. `FontImageLib`: rejected. The helpers call FontImageLib for metrics/glyph advances but do not own font slots or glyph decode state. The current receiver supplies font/style and draw colors.
6. `Surface` or render callback table owners: rejected. `dword_69B3E8` and `dword_69B3FC` are backend callback dependencies. The target functions are high-level text layout and draw methods on GrafPort state.

### Field / Type / Global Names

Best field names for supervisor incorporation:

| Offset | Recommended name | Evidence and validation |
| --- | --- | --- |
| `this + 0x68` | `m_currentY` | Saved/restored by DrawTextInRect; set by `MoveTo` second argument in [UID:000162]; used as text baseline/Y cursor. |
| `this + 0x6c` | `m_currentX` | Saved/restored by DrawTextInRect; set by `MoveTo` first argument in [UID:000162]; advanced by DrawGlyph; used for text line X alignment. |
| `this + 0x70` | `m_renderMode` or `m_drawMode` | Used by rect/tile/glyph callbacks as active draw/blit mode; WaterFilterEffecter writes mode `2` before tiled background; DrawWideText temporarily copies `m_textDrawMode` here before fill/invalidate. |
| `this + 0x71` | `m_drawEnabled` | Explicit early-out gate in DrawTextInRect and nearby frame helpers. |
| `this + 0x74` | `m_drawColor` | Active fill/draw color passed to callback slot `0x0069b3fc`; set by `0x004b9660`. Do not call this final text color. |
| `this + 0x78` | `m_textBackFillColor` | Copied into `m_drawColor` during DrawWideText background fill/invalidation; set by `0x004b9670`. |
| `this + 0x7c` | `m_textColor` | Primary foreground text color. DrawOutlinedText saves/restores this field and temporarily replaces it with `m_textBackColor` for outline passes. DrawWideText pattern uses it as foreground. |
| `this + 0x80` | `m_textBackColor` | Secondary/background/outline text color. DrawOutlinedText copies it into `m_textColor` for offset outline passes. DrawWideText pattern uses it as background. |
| `this + 0x84` | `m_brushHandle` or `m_paletteBrushHandle` | Confirmed by [UID:000163] accessor pair; DrawGlyph also passes/uses this nearby state. |
| `this + 0x88` | `m_textDrawMode` | DrawWideText only performs background fill for values `0` and `2`; DrawGlyph maps mode `0 -> 1` and `2 -> 3` for sprite blit callback, otherwise preserving the mode. This is not a dirty byte. |
| `this + 0x8a` | `m_fontStyleId` | `SetFontId` only accepts `0` or `1`; all width/height/glyph helpers pass it to FontImageLib. |
| `this + 0x8c` | `m_textAlign` | DrawTextInRect branches as left/default, center for `1`, right for `2`. Other callers compare additional text edit modes, but this helper only uses left/center/right. |

Global/callback naming:

- `0x0067ab24` should be `g_pFontImageLib`, not `dword_67AB24`.
- `0x0069b3e8` is the sprite/tile/glyph blit callback, best named `g_pfnBlitSprite` or `SurfaceSpriteBlitProc` in support docs.
- `0x0069b3fc` is not source-proven as `g_pfnLockSurface`; that generated name is rejected for this target. The observed role in this cluster is a fill/invalidate/presentation callback taking GrafPort state and a rectangle. Best descriptive naming is `g_pfnFillOrInvalidateRect`, `SurfaceFillOrInvalidateProc`, or `SurfaceRenderCallbackTable::FillOrInvalidateRect` until the callback typedef is fully recovered.
- `StringIter` is a 16-byte UTF-16 iterator object used by width and draw loops. Its constructor at `0x00584d80`, next-character helper at `0x00584e40`, and destructor at `0x00584df0` match the existing StringIter docs.
- `RectBounds` is the four-int rectangle layout `left/top/right/bottom` at offsets `0/4/8/0xc`.

### Current Docs Validated, Corrected, Or Superseded

Validated:

- [UID:00016B] is GrafPort-owned, not ClanItemListPane-owned.
- [UID:00016D] is GrafPort-owned, not TextButtonControlPane-owned.
- `g_pFontImageLib` and FontImageLib metric/glyph helper dependencies are correct.
- `DrawTextInRect` line wrapping, alignment, stack buffer, space-skip, and cursor restore behavior are correct.
- `DrawWideText` and `DrawOutlinedText` are shared text infrastructure, not feature-pane code.

Corrected:

- [UID:00016C] should no longer remain direct file-owned [UID:0000JR]. It should route directly to [UID:00005V] as a GrafPort class helper cluster while still emitting in `NexusTK/render/GrafPort.cpp`.
- The old [UID:00016C] coverage row at `78%` is stale and contradicts live target metadata `86/89`.
- The old broad statement that `0x004baad0` "trims trailing spaces" should be refined to an exact visible-count adjustment helper with odd but preserved `cmovle` return semantics.
- `+0x88` should not be carried forward as a dirty byte or `m_textRunDirty`. In this cluster, it is text draw/background/blit mode.
- [UID:000162] color accessors should not name `+0x7c` as background and `+0x80` as foreground. DrawOutlinedText proves `+0x7c` is the primary text/foreground color and `+0x80` is the secondary/background/outline text color.

Superseded:

- `sub_4BA820`, `sub_4BA8B0`, `sub_4BA9A0`, `sub_4BAA70`, `sub_4BAAA0`, `sub_4BAAD0`, `sub_4BAB20`, `sub_4BAB70`, `sub_4BACD0`, and generated feature-owner helper names should be replaced in source-facing text with the names above.
- Generated-owner pollution from FittingRoom, Collection, Ranking, ClanItemListPane, and TextButtonControlPane should remain as caller evidence only.

### Split / Merge / Container Boundary

No executable split repair is required. [UID:00016B], [UID:00016C], and [UID:00016D] should remain separate aggregates:

- [UID:00016B] is a two-function fit/suffix cluster with an internal edge and shared responsibility.
- [UID:00016C] is a seven-function text-run cluster. Six functions are GrafPort receiver methods; one function is a static/local visible-count adjustment helper used by the wider text callback area. Splitting the static helper into a child would add more routing overhead than value because it has only four direct callers and no independent owner.
- [UID:00016D] is a single public/shared wrapped-text method.

Do not merge these three into [UID:000160]. The broad GrafPort neighborhood is already a non-emitting split index, while these exact child pages carry source-bearing code.

Do not merge [UID:0003XF] `GrafPortPatternPackRaw` into [UID:00016C] or [UID:00016I]. Existing executed evidence finds no direct caller, branch route, pointer-table entry, or text-run caller into the raw pattern packer. It remains adjacent support/no-owner raw evidence, not part of the live text-run helper cluster.

### First-Draft C++ Readiness

All three primary targets clear the current code-entry gate:

- `RECONSTRUCTABLE:TRUE`.
- Nonblank emitter route.
- Combined score above 85 now, and recommended score remains above gate.
- Source container `NexusTK/render/GrafPort.cpp` is known.
- Remaining original-name uncertainty does not block a first draft because descriptive names are strongly supported by raw behavior and local field usage.

Formal C++ should be populated for all three primary targets. The draft code below is source-style C++ and not raw decompiler output. It preserves the important binary-visible behavior: UTF-16 counted text, FontImageLib width/height calls, StringIter iteration, text color/background state, outline passes, text background fill mode gating, DrawTextInRect argument order, bounded 0x200-byte line buffer, range-check semantics, and cursor restore.

Remaining caveats after C++ insertion:

- Exact historical names for `m_textBackFillColor`, `m_textBackColor`, and `m_textDrawMode` are inferred/descriptive, not original-proof.
- Exact callback typedef/name for `0x0069b3fc` remains descriptive.
- `AdjustVisibleCountForTrailingWhitespace` has odd return semantics; source may have had a macro, inline, or signed/unsigned expression that compiled into the observed `cmovle`. The draft intentionally preserves the observed result rather than an intuitive trim count.

## Open Questions Resolved Or Remaining

Resolved or high-probability:

- `FitTextAndAppendSuffix`, `CountCharsFittingWidth`, `GetTextWidth` overloads, `GetLineHeight`, `AdjustVisibleCountForTrailingWhitespace`, `DrawGlyphWithTextColors`, `DrawWideText`, `DrawOutlinedText`, and `DrawTextInRect` are the best source-facing helper names.
- [UID:00016C] direct owner/emitter should be [UID:00005V] rather than [UID:0000JR].
- `+0x7c` is foreground/primary text color and `+0x80` is background/outline text color.
- `+0x88` is text draw/background/blit mode, not a dirty byte.
- `g_pFontImageLib` should replace raw `dword_67AB24` in target docs.
- Current aggregates are acceptable; no child split is needed.
- Formal C++ should be populated for all three targets.

Remaining but non-blocking:

- Exact original class member spellings are not recoverable from the binary. The recommended names are descriptive and should be marked inferred where docs distinguish original-proof names from descriptive names.
- Exact original callback name for `0x0069b3fc` is not recoverable from this cluster. Use a descriptive name and keep SurfaceRenderCallbackTable as the owning support page.
- `AdjustVisibleCountForTrailingWhitespace` original source may have been file-local, static inline, or in an anonymous helper namespace. Since there is no symbol or independent owner evidence, model it as a file-local/static helper in `GrafPort.cpp`.

## First-Draft C++ Recommendation

Populate formal C++ for [UID:00016B], [UID:00016C], and [UID:00016D]. The following draft uses recovered descriptive member names and dependency names. If the supervisor prefers shorter historic-style names, rename consistently but preserve signatures and behavior.

### [UID:00016B] Draft

```cpp
void GrafPort::FitTextAndAppendSuffix(wchar_t *text,
                                      size_t textCapacity,
                                      const wchar_t *suffix,
                                      int maxPixelWidth)
{
    const int textWidth = GetTextWidth(text, static_cast<int>(wcslen(text)));
    if (textWidth <= maxPixelWidth) {
        return;
    }

    const int suffixWidth = GetTextWidth(suffix, static_cast<int>(wcslen(suffix)));
    const int keepCount = CountCharsFittingWidth(text, maxPixelWidth - suffixWidth);

    text[keepCount] = L'\0';
    wcscat_s(text, textCapacity, suffix);
}

int GrafPort::CountCharsFittingWidth(const wchar_t *text, int maxPixelWidth)
{
    const int length = static_cast<int>(wcslen(text));
    StringIter iter(text, length);

    int visibleCount = 0;
    int width = 0;

    wchar_t ch = static_cast<wchar_t>(iter.GetNextChar());
    wchar_t nextCh = static_cast<wchar_t>(iter.GetNextChar());

    while (ch != L'\0') {
        short advance = 0;
        g_pFontImageLib->MeasureGlyphWidth(m_fontStyleId,
                                           ch,
                                           nextCh,
                                           0,
                                           0,
                                           NULL,
                                           &advance,
                                           NULL);

        width += advance;
        if (width > maxPixelWidth) {
            break;
        }

        ++visibleCount;
        ch = nextCh;
        nextCh = static_cast<wchar_t>(iter.GetNextChar());
    }

    return visibleCount;
}
```

### [UID:00016C] Draft

```cpp
static int __stdcall AdjustVisibleCountForTrailingWhitespace(const wchar_t *text, int count)
{
    if (count <= 0) {
        return count;
    }

    const wchar_t *first = text;
    const wchar_t *scan = text + count - 1;

    while (first <= scan) {
        const wchar_t ch = *scan;
        if (ch != L' ' && ch != L'\t' && ch != L'\r') {
            break;
        }
        --scan;
    }

    const int lastVisibleIndex = static_cast<int>(scan - first);
    if (count <= lastVisibleIndex) {
        return lastVisibleIndex;
    }

    return count;
}

short GrafPort::GetTextWidth(const wchar_t *text, int charCount)
{
    StringIter iter(text, charCount);

    short totalWidth = 0;
    wchar_t ch = static_cast<wchar_t>(iter.GetNextChar());
    wchar_t nextCh = static_cast<wchar_t>(iter.GetNextChar());

    while (ch != L'\0') {
        short advance = 0;
        g_pFontImageLib->MeasureGlyphWidth(m_fontStyleId,
                                           ch,
                                           nextCh,
                                           0,
                                           0,
                                           NULL,
                                           &advance,
                                           NULL);

        totalWidth = static_cast<short>(totalWidth + advance);
        ch = nextCh;
        nextCh = static_cast<wchar_t>(iter.GetNextChar());
    }

    return totalWidth;
}

short GrafPort::GetTextWidth(const wchar_t *text)
{
    return GetTextWidth(text, static_cast<int>(wcslen(text)));
}

short GrafPort::GetLineHeight()
{
    short lineHeight = 0;
    g_pFontImageLib->GetFontMetrics(m_fontStyleId, NULL, &lineHeight);
    return lineHeight;
}

void GrafPort::DrawGlyphWithTextColors(wchar_t ch, wchar_t nextCh)
{
    unsigned char colors[6];

    colors[0] = static_cast<unsigned char>(m_textBackColor);
    colors[1] = static_cast<unsigned char>(m_textColor);
    colors[2] = static_cast<unsigned char>(m_textBackColor);
    colors[3] = static_cast<unsigned char>(m_textColor);
    colors[4] = static_cast<unsigned char>(m_textColor);
    colors[5] = static_cast<unsigned char>(m_textBackColor);

    DrawGlyph(ch, nextCh, 0, colors);
}

void GrafPort::DrawWideText(const wchar_t *text, int charCount)
{
    if (static_cast<short>(charCount) < 0) {
        return;
    }

    unsigned char colors[6];
    colors[0] = static_cast<unsigned char>(m_textBackColor);
    colors[1] = static_cast<unsigned char>(m_textColor);
    colors[2] = static_cast<unsigned char>(m_textBackColor);
    colors[3] = static_cast<unsigned char>(m_textColor);
    colors[4] = static_cast<unsigned char>(m_textColor);
    colors[5] = static_cast<unsigned char>(m_textBackColor);

    if (m_textDrawMode == 0 || m_textDrawMode == 2) {
        short lineHeight = 0;
        g_pFontImageLib->GetFontMetrics(m_fontStyleId, NULL, &lineHeight);

        RectBounds backgroundRect;
        backgroundRect.left = m_currentX;
        backgroundRect.top = m_currentY - lineHeight;
        backgroundRect.right = m_currentX + GetTextWidth(text, charCount);
        backgroundRect.bottom = m_currentY;

        const unsigned char oldRenderMode = m_renderMode;
        const unsigned int oldDrawColor = m_drawColor;

        m_renderMode = m_textDrawMode;
        m_drawColor = m_textBackFillColor;
        g_pfnFillOrInvalidateRect(this, &backgroundRect);
        m_renderMode = oldRenderMode;
        m_drawColor = oldDrawColor;
    }

    StringIter iter(text, charCount);
    wchar_t ch = static_cast<wchar_t>(iter.GetNextChar());
    wchar_t nextCh = static_cast<wchar_t>(iter.GetNextChar());

    while (ch != L'\0') {
        DrawGlyph(ch, nextCh, 0, colors);
        ch = nextCh;
        nextCh = static_cast<wchar_t>(iter.GetNextChar());
    }
}

void GrafPort::DrawOutlinedText(int x, int y, const wchar_t *text, int charCount)
{
    const unsigned int oldTextColor = m_textColor;

    m_textColor = m_textBackColor;

    m_currentX = x;
    m_currentY = y - 1;
    DrawWideText(text, charCount);

    m_currentX = x;
    m_currentY = y + 1;
    DrawWideText(text, charCount);

    m_currentX = x - 1;
    m_currentY = y;
    DrawWideText(text, charCount);

    m_currentX = x + 1;
    m_currentY = y;
    DrawWideText(text, charCount);

    m_textColor = oldTextColor;

    m_currentX = x;
    m_currentY = y;
    DrawWideText(text, charCount);
}
```

### [UID:00016D] Draft

```cpp
void GrafPort::DrawTextInRect(const wchar_t *text, int length, const RectBounds *rect)
{
    if (!m_drawEnabled) {
        return;
    }

    const int oldY = m_currentY;
    const int oldX = m_currentX;

    short lineHeight = 0;
    g_pFontImageLib->GetFontMetrics(m_fontStyleId, NULL, &lineHeight);

    int index = 0;
    m_currentX = rect->left;
    m_currentY = rect->top;

    while (index < length && m_currentY <= rect->bottom) {
        const wchar_t *lineStart = text + index;
        int fitCount = CountCharsFittingWidth(lineStart, rect->right - rect->left);

        if (index + fitCount > length) {
            fitCount = length - index;
        }

        wchar_t line[256];
        if (fitCount >= static_cast<int>(_countof(line))) {
            __report_rangecheckfailure();
        }

        memmove(line, lineStart, fitCount * sizeof(wchar_t));
        line[fitCount] = L'\0';

        m_currentY += lineHeight;

        if (m_textAlign == 2) {
            m_currentX = rect->right - GetTextWidth(line, fitCount);
        } else if (m_textAlign == 1) {
            const int rectCenter = (rect->left + rect->right) / 2;
            m_currentX = rectCenter - (GetTextWidth(line, fitCount) / 2);
        } else {
            m_currentX = rect->left;
        }

        DrawWideText(line, fitCount);

        index += fitCount;
        if (text[index] == L' ') {
            ++index;
        }
    }

    m_currentX = oldX;
    m_currentY = oldY;
}
```

## Exact Supervisor Changes Required

### [UID:00016B] Metadata

Replace header values:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Placement context: replace the existing [UID:00016B] `## Reconstruction Notes` bullet saying to leave C++ blank. Recommended replacement:

```text
- `RECONSTRUCTABLE` is true because the two bodies have clean function boundaries, standard CRT/StringIter dependencies, receiver-state evidence, and a fully explained relationship to the neighboring `GrafPort` text-width helper.
- Formal C++ should be populated. The source-facing names are inferred but high-probability: `GrafPort::FitTextAndAppendSuffix(wchar_t *text, size_t textCapacity, const wchar_t *suffix, int maxPixelWidth)` and `GrafPort::CountCharsFittingWidth(const wchar_t *text, int maxPixelWidth)`. The remaining uncertainty is only exact historic spelling, not behavior, owner, signature, or source route.
```

### [UID:00016C] Metadata

Replace header values:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Placement context: replace the [UID:00016C] `## Status` bullets:

```text
- Confidence: very strong for function extents, shared text-rendering role, GrafPort ownership, and source route; medium only for exact historical method/member spellings.
- Current generated owners: `FittingRoomDownloadControlPane`, `CollectionEntryControlPane`, and `RankingEventListPane`; these are caller-biased generated-output leads, not source owners.
- Direct reconstruction owner: [UID:00005V][GrafPort](by-class/GrafPort.md) in [UID:0000JR][GrafPort](by-file/GrafPort.md).
- Primary dependencies: [UID:0000JH][FontImageLib](by-file/FontImageLib.md) through [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md), [UID:0000E7][StringIter](by-class/StringIter.md), [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md), and [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md).
- 2026-06-18 B001 source-quality status: raw PE/Capstone recheck confirms all seven modeled function bodies, direct rel32 caller counts `117`, `64`, `67`, `4`, `3`, `188`, and `31`, and the internal chain `0x004baa70 -> 0x004ba9a0`, `0x004bab70 -> 0x004ba9a0`, `0x004bacd0 -> 0x004bab70`. Formal C++ should be populated.
```

Placement context: replace the [UID:00016C] `## Covered Functions` table with:

```text
| Range | Source-facing role | Notes |
| --- | --- | --- |
| `0x004ba9a0-0x004baa66` | `GrafPort::GetTextWidth(const wchar_t *text, int charCount)` | Iterates a UTF-16 text run with [UID:0000E7][StringIter](by-class/StringIter.md), asks [UID:0002HR][FontImageLibMeasureGlyphWidth](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md) for each glyph advance through [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md), and returns the summed width as a 16-bit value. |
| `0x004baa70-0x004baa9d` | `GrafPort::GetTextWidth(const wchar_t *text)` | Computes `wcslen(text)` and forwards to the counted overload. |
| `0x004baaa0-0x004baac4` | `GrafPort::GetLineHeight()` | Reads current `m_fontStyleId` at `this+0x8a` and returns height from `FontImageLib::GetFontMetrics`. |
| `0x004baad0-0x004bab11` | `AdjustVisibleCountForTrailingWhitespace(const wchar_t *text, int count)` | Receiver-independent static/local helper. It scans trailing spaces, tabs, and carriage returns from a proposed visible count; preserve the observed visible-count adjustment semantics rather than modeling it as a simple string trim. |
| `0x004bab20-0x004bab6b` | `GrafPort::DrawGlyphWithTextColors(wchar_t ch, wchar_t nextCh)` | Builds the six-byte glyph color pattern from `m_textColor` at `this+0x7c` and `m_textBackColor` at `this+0x80`, then calls [UID:00016I][GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md). |
| `0x004bab70-0x004bacc7` | `GrafPort::DrawWideText(const wchar_t *text, int charCount)` | Optionally fills/invalidates the text background rectangle when `m_textDrawMode` at `this+0x88` is `0` or `2`, then walks the UTF-16 run with `StringIter` and calls `GrafPortDrawGlyph` once per glyph. |
| `0x004bacd0-0x004bad66` | `GrafPort::DrawOutlinedText(int x, int y, const wchar_t *text, int charCount)` | Draws four one-pixel offset passes in `m_textBackColor`, restores `m_textColor`, then draws the foreground text at the requested position. |
```

Placement context: replace the [UID:00016C] `## Reconstruction Notes` with:

```text
- `RECONSTRUCTABLE` is true because all seven functions have verified boundaries, broad shared call signatures, and direct receiver-state evidence tying them to GrafPort text rendering.
- Formal C++ should be populated. The only unresolved source-quality issue is exact historical spelling for member fields and callback typedefs; the behavior, signatures, receiver ownership, source route, and dependency set are strong enough for a first draft.
```

### [UID:00016D] Metadata

Replace header values:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Placement context: add to [UID:00016D] `## Function` or immediately after it:

```text
Source-facing signature should be `void GrafPort::DrawTextInRect(const wchar_t *text, int length, const RectBounds *rect)`. Raw stack use confirms argument order is text, length, rect, and the method returns with `ret 0x0c`.
```

Placement context: add to [UID:00016D] `## Evidence Notes`:

```text
- 2026-06-18 B001 raw PE/Capstone recheck confirms the source-facing stack-argument order `text`, `length`, `rect`; `m_drawEnabled` at `this+0x71`; saved/restored `m_currentY`/`m_currentX` at `this+0x68/+0x6c`; `m_fontStyleId` at `this+0x8a`; `m_textAlign` at `this+0x8c` with default/left, center for `1`, and right for `2`; a `0x200` byte local UTF-16 line buffer; and 130 direct rel32 callers. Formal C++ should be populated.
```

### [UID:00005V] GrafPort Support Text

Placement context: replace the existing paragraph for [UID:00016C] in [UID:00005V][GrafPort](../../../by-class/GrafPort.md):

```text
[UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) is now class-owned GrafPort text-run code rather than a direct file-bucket item. B001's 2026-06-18 source-quality pass resolves the counted and null-terminated `GetTextWidth` overloads, `GetLineHeight`, the static/local `AdjustVisibleCountForTrailingWhitespace` helper, `DrawGlyphWithTextColors`, `DrawWideText`, and `DrawOutlinedText`. The pass also corrects text color fields to `m_textColor` at `this+0x7c` and `m_textBackColor` at `this+0x80`, names `this+0x88` as text draw/background mode rather than a dirty byte, keeps `g_pFontImageLib` as the FontImageLib dependency, and recommends formal C++ emission through `NexusTK/render/GrafPort.cpp`.
```

### [UID:0000JR] GrafPort File Support Text

Placement context: replace the `Text measurement/drawing helpers` row in [UID:0000JR][GrafPort](../../../by-file/GrafPort.md) `## Proposed Contents`:

```text
| Text measurement/drawing helpers | `0x004ba820-0x004bb0db`, `0x004bb5e0-0x004bb7e0` | Shared UTF-16 fit/suffix, width, line-height, wrapped rect draw, outlined/shadowed text effects, run drawing, and per-glyph blit helpers. B001's 2026-06-18 source-quality pass routes [UID:00016B], [UID:00016C], and [UID:00016D] through the `GrafPort` class in this file, resolves source-facing method names/signatures, and rejects caller-biased feature-pane generated ownership. |
```

### [UID:000162] GrafPort Draw-State Accessor Support Text

Placement context: in [UID:000162][GrafPortDrawStateAccessors](../../../by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), replace the color-accessor role rows or add this corrective note:

```text
2026-06-18 B001 GrafPort text-helper correction: `0x004b9660` stores active draw/fill color at `this+0x74`; `0x004b9670` stores text-background fill color at `this+0x78`; `0x004b9680` stores primary foreground text color at `this+0x7c`; and `0x004b9690` stores secondary/background/outline text color at `this+0x80`. DrawOutlinedText proves the `+0x7c/+0x80` roles by saving/restoring `+0x7c`, temporarily copying `+0x80` into it for four outline passes, and then drawing the foreground pass. Do not carry forward older labels that make `+0x7c` the background or `+0x80` the foreground. `this+0x88` should be treated as text draw/background mode, not a dirty byte.
```

### [UID:00016I] GrafPortDrawGlyph Support Text

Placement context: add to [UID:00016I][GrafPortDrawGlyph](../../../by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md) evidence/support notes:

```text
2026-06-18 B001 text-helper dependency correction: direct callers remain [UID:00016C] `DrawGlyphWithTextColors` and `DrawWideText`. The caller-built six-byte color pattern uses `m_textColor` at `this+0x7c` and `m_textBackColor` at `this+0x80`. `m_textDrawMode` at `this+0x88` is mapped by DrawGlyph for sprite blitting (`0 -> 1`, `2 -> 3`, otherwise preserved), which rejects older dirty-byte labels for this field.
```

## Coverage Report Replacement Text

Do not edit `by-memory/-coverage-report.md` directly. Supervisor should replace the rows at current placement context near the GrafPort neighborhood, between [UID:00016A] and [UID:00016E].

Replace the [UID:00016B] row with:

```text
    - [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md) 0x004ba820-0x004ba991 | methods | GrafPortTextFitAndSuffixHelpers : reconstructable : 88% : very strong : B001 2026-06-18 source-quality pass resolves source-facing `GrafPort::FitTextAndAppendSuffix(wchar_t *text, size_t textCapacity, const wchar_t *suffix, int maxPixelWidth)` and `GrafPort::CountCharsFittingWidth(const wchar_t *text, int maxPixelWidth)` signatures; raw PE/Capstone recheck confirms `ret 0x10` and `ret 8`, direct rel32 caller counts `21` and `4`, sibling edge `0x004ba820 -> 0x004ba8b0`, `g_pFontImageLib` glyph-advance measurement through `FontImageLib::MeasureGlyphWidth`, `m_fontStyleId` at `this+0x8a`, `StringIter` iteration, ClanItemListPane/feature-pane owner rejection, direct [UID:00005V][GrafPort](by-class/GrafPort.md) ownership, and first-draft C++ should be populated through `auto-generated/NexusTK/render/GrafPort.cpp`.
```

Replace the [UID:00016C] row with:

```text
    - [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) 0x004ba9a0-0x004bad66 | methods | GrafPortTextRunHelpers : reconstructable : 88% : very strong : B001 2026-06-18 source-quality pass reroutes this helper cluster from file bucket [UID:0000JR][GrafPort](by-file/GrafPort.md) to direct class owner/emitter [UID:00005V][GrafPort](by-class/GrafPort.md); raw PE/Capstone recheck confirms seven function bodies and direct rel32 caller counts `117`, `64`, `67`, `4`, `3`, `188`, and `31`, source-facing text-width, null-terminated width, line-height, visible-count adjustment, glyph-with-colors, wide-text, and outlined-text signatures, `g_pFontImageLib` / `StringIter` / `FontImageLib` dependencies, `m_textColor` at `this+0x7c`, `m_textBackColor` at `this+0x80`, text draw/background mode at `this+0x88`, `SurfaceRenderCallbackTable` fill/invalidate callback slot `0x0069b3fc`, feature-owner and FontImageLib/Surface owner rejection, and first-draft C++ should be populated through `auto-generated/NexusTK/render/GrafPort.cpp`.
```

Replace the [UID:00016D] row with:

```text
    - [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md) 0x004bad70-0x004baf92 | method | GrafPortDrawTextInRect : reconstructable : 88% : very strong : B001 2026-06-18 source-quality pass resolves exact source-facing signature `GrafPort::DrawTextInRect(const wchar_t *text, int length, const RectBounds *rect)` with stack-argument order text/length/rect; raw PE/Capstone recheck confirms `ret 0x0c`, 130 direct rel32 callers, `m_drawEnabled` at `this+0x71`, saved/restored `m_currentY`/`m_currentX` at `this+0x68/+0x6c`, `m_fontStyleId` at `this+0x8a`, `m_textAlign` at `this+0x8c` with left/center/right branches, bounded `0x200`-byte UTF-16 stack copy and range-check path, wrapping through `CountCharsFittingWidth`, text-width alignment through `GetTextWidth`, drawing through `DrawWideText`, feature-pane owner rejection, and first-draft C++ should be populated through `auto-generated/NexusTK/render/GrafPort.cpp`.
```

Optional support coverage rows, if supervisor updates non-memory coverage reports with this pass:

Replace [UID:00005V] in `by-class/-coverage-report.md` with:

```text
- [UID:00005V][GrafPort](by-class/GrafPort.md) : reconstructable : 88% : very strong : Core graphics-port class with backing-store state, dirty/clip/draw helpers, constructor/update/destructor coverage, accepted ownership for text/blit/frame/tiled-background helpers, B003 `GrafPort::BlitSurface` routing for [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md), B002 `GrafPort::DrawRectFrame` routing for [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md), B002 `GrafPort::DrawTiledBackground` routing for [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md), and B001 text-helper routing for [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md), [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md), and [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md), including corrected text color fields `this+0x7c/+0x80`, text draw/background mode `this+0x88`, `g_pFontImageLib`, `StringIter`, and SurfaceRenderCallbackTable dependencies.
```

Replace [UID:0000JR] in `by-file/-coverage-report.md` with:

```text
- [UID:0000JR][GrafPort](by-file/GrafPort.md) : reconstructable : 89% : strong : Render-file bucket for GrafPort and related draw helpers, with accepted ownership for text helpers, [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) `GrafPort::BlitSurface`, [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) `GrafPort::DrawRectFrame`, [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) `GrafPort::DrawTiledBackground`, and B001 source-facing routes for [UID:00016B][TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md), [UID:00016C][GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md), and [UID:00016D][DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md); source route remains `NexusTK/render/GrafPort.cpp`, with FontImageLib, StringIter, RectBounds, and Surface callback/table docs retained as dependencies.
```

## Score / Metadata Summary

| UID | Current | Recommended | Owner/emitter | Formal C++ |
| --- | --- | --- | --- | --- |
| `00016B` | `86/90` | `88/91` | Keep `00005V` / `00005V` | Populate draft. |
| `00016C` | `86/89` | `88/90` | Change `0000JR` / `0000JR` to `00005V` / `00005V` | Populate draft. |
| `00016D` | `86/90` | `88/91` | Keep `00005V` / `00005V` | Populate draft. |
| `00005V` | `88/90` | Keep `88/90` | Keep `0000JR` / `0000JR` | Class C++ can remain blank unless supervisor is doing a full class declaration pass. |
| `0000JR` | `89/88` | Keep `89/88` | File bucket | No file-level formal C++ needed. |
| `000162` | `86/89` | Keep score; correct field text | Keep current route | No C++ recommendation in this assignment. |
| `00016I` | `86/89` | Keep score; add dependency correction | Keep current route | No C++ recommendation in this assignment. |

## Remaining Blockers

No blocker remains for this assignment's requested report or for first-draft C++ in the three primary targets.

Non-blocking items for later source-quality passes:

- Prove or rename the exact original typedef/source name for callback slot `0x0069b3fc`.
- If a later source-tree pass proves a historical `render/TextDrawing.cpp` split, move these methods as a source-file placement update without changing direct class ownership.
- Audit [UID:000162] in its own source-quality pass if the supervisor wants formal C++ for draw-state accessors; this report only supplies the field-role correction needed by the text helpers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00016B-00016C-00016D-GrafPortTextHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"00016B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
