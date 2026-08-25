*** UID:0000U3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00054Z | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BuildClippedAlphaSurfaceView 0x00462320

## Final Alias Disposition

This by-item page is a non-emitting semantic index for exact source child [UID:00054Z][0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo](by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md). The exact child owns the range, formal CPP/H, [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md) route, source position, caller, partial failure-write contract, and score. Retaining this item as another emitter would duplicate the same function.

All prior behavior and layout evidence below remains valid historical support. `BuildClippedAlphaSurfaceView` is retained as a searchable provisional name only; final source uses `IntAlphaSurface::GetClippedBufferInfo`.

## Status

- Confidence: very strong for the exact alias-to-child relationship, range, behavior, and source route; the retained alias spelling is descriptive rather than an asserted original symbol.
- Entity kind: non-emitting semantic alias/index for one exact by-memory method child.
- Exact range: `0x00462320-0x004623b5`.
- Accepted physical source module: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), reached only through exact class-owned child [UID:00054Z][0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo](by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md); this alias itself has no emitter.
- Owner route: exact source child [UID:00054Z][0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo](by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md); this alias is `RECONSTRUCTABLE:FALSE`, has no emitter, and must not duplicate the child source. The child emits through [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md) in [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md).
- Output record: [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md).

## Behavior

`BuildClippedAlphaSurfaceView` builds a non-owning byte-buffer view over an existing alpha surface:

1. Requires a source pixel pointer and a non-null clip rectangle.
2. Intersects the requested clip against source bounds `{0,0,width,height}`.
3. Writes adjusted pixel pointer, clipped width, clipped height, and original stride into the output view.
4. Clears output ownership byte/flags at `+0x10`.

If there is no source pixel pointer, no clip rectangle, or no intersection, the output pixel pointer is set to null and the view is marked non-owning.

## IDA MCP Evidence

- `lookup_funcs 0x00462320` reports a real function size of `0x95`; `149 == 0x95` was verified with `int_convert.py`.
- `decompile 0x00462320` shows the source bounds initialization, rectangle intersection call, adjusted pixel pointer calculation, width/height/stride stores, and non-owning flag clear.
- `xrefs_to 0x00462320` and `callers 0x00462320` both report a live `StaticObjImageLib` caller at `0x004dd66a`.
- The function consumes the same alpha-surface object offsets documented in [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md).
- 2026-06-14 IDA MCP recheck confirms the modeled range is `0x00462320-0x004623b5`: `lookup_funcs 0x004623b4` resolves inside `sub_462320`, `lookup_funcs 0x004623b5` reports not-a-function, the byte stream after the final `ret` byte is `0xcc` padding, and the next real function starts at `0x004623c0`.
- 2026-06-14 `analyze_function 0x00462320` reports one caller (`sub_4DD2C0`), callees `sub_4B7C50`, `sub_4B7CC0`, and `@__security_check_cookie@4`, six basic blocks, and cyclomatic complexity four.
- 2026-05-30 IDA MCP recheck confirms the modeled range is `0x00462320-0x004623b5`, and the only observed code xref is still [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) caller `0x004dd66a`.
- 2026-05-30 decompilation confirms output layout: pixel pointer at `+0x00`, width at `+0x04`, height at `+0x08`, stride at `+0x0c`, and non-owning flag byte at `+0x10`.
- 2026-06-16 C001 live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed the `0x95` / 149-byte range, one `StaticObjImageLib` caller at `0x004dd66a`, callees `sub_4B7C50`, `sub_4B7CC0`, and `@__security_check_cookie@4`, and saved the low-risk function label `BuildClippedAlphaSurfaceView` after dry-run validation. No prototype, member, local, or raw-function edit was made.
- 2026-07-07 B007 session `ef57d27f` reconfirmed this helper as half-open `0x00462320-0x004623b5`, size `0x95`, with one direct `StaticObjImageLib` caller at `0x004dd66a`. Its then-current recommendation to wait for exact by-memory promotion is historical and superseded: exact child [UID:00054Z][0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo](by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md) now exists and owns the formal CPP/H and [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md) route, while this alias correctly remains non-emitting.

## Current Source Disposition

The exact source body and declaration belong only to [UID:00054Z][0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo](by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md). This page preserves the searchable provisional name and detailed behavioral evidence but intentionally has blank formal CPP/H, no emitter, and no source position so the function is emitted exactly once.

## Historical / Superseded Reconstruction Notes

The following candidate predates the exact child split and is retained only as historical source-shape evidence. It is not an active implementation recommendation and must not override [UID:00054Z][0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo](by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md).

Keep this with the alpha-surface/render helper module, not with `StaticObjImageLib`. The caller proves use, but the implementation is a generic clipped buffer-view builder over alpha-surface state.

Candidate source-level shape:

```cpp
void AlphaMaskSurface::BuildClippedView(AlphaSurfaceBufferView& out, const RectBounds* clip)
{
    RectBounds imageBounds(0, 0, m_width, m_height);
    RectBounds clipped;

    if (m_pixels != nullptr && clip != nullptr && imageBounds.Intersect(*clip, clipped)) {
        out.pixels = m_pixels + clipped.left + clipped.top * m_stride;
        out.width = clipped.right - clipped.left;
        out.height = clipped.bottom - clipped.top;
        out.stride = m_stride;
    } else {
        out.pixels = NULL;
    }

    out.ownsBuffer = false;
}
```

Names in this historical candidate were provisional, while the offset behavior remains valid IDA-backed evidence. The former request for future promotion is satisfied by exact child [UID:00054Z][0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo](by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md).

## Score Rationale

- Completion `95`: this page completely records its current non-emitting alias role, exact child, range, caller/callee and behavior evidence, output layout, historical naming context, and duplicate-emission prohibition.
- Confidence `95`: current metadata and the exact [UID:00054Z][0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo](by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md) split resolve the former class/file/source-body uncertainty. The alias spelling remains descriptive, but it is no longer used as a source symbol or score blocker.

## Cross-References

- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)

## Changes

- 2026-08-17 B005 UID0000HF Gate 2A reconciliation:
  - Replaced the active pre-split `86/91`, file-owned emitter, and future-promotion conclusions with the accepted `95/95` non-emitting alias disposition owned by exact child [UID:00054Z][0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo](by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md).
  - Historicalized the old `AlphaMaskSurface::BuildClippedView` candidate without deleting its valid behavioral detail; current formal CPP/H remains exclusively on the exact child.

- 2026-07-07 B007 UID0000YL aggregate implementation support sync:
  - Score and owner/emitter metadata unchanged.
  - Summary/evidence: added current session `ef57d27f` reconfirmation of range `0x00462320-0x004623b5`, one `StaticObjImageLib` caller at `0x004dd66a`, and the accepted disposition that formal C++ should wait for exact by-memory promotion/split rather than be emitted from UID0000YL's aggregate marker or this by-item support page.
- 2026-06-16 C001 Goal 2 item/IDA refresh:
  - Before: score was `85/90` and IDA still used `sub_462320`.
  - After: raised to `86/91`, saved the IDA label `BuildClippedAlphaSurfaceView`, and reconfirmed the single `StaticObjImageLib` caller plus AlphaMaskSurface owner/emitter route.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `analyze_component`, `decompile`, dry-run rename validation, applied rename, `idb_save ok:true`, and post-save lookup. Final C++ remains blank because the exact source-facing signature/class split and field names remain provisional.
- 2026-06-14: Raised completion/confidence from `84/88` to `85/90` and corrected the status range to `0x00462320-0x004623b5`.
  - Before: the status line still ended at `0x004623b4` even though the evidence section had already identified the modeled half-open end as `0x004623b5`, and the page lacked current boundary/callee/score-rationale detail.
  - After: live IDA MCP reconfirms `sub_462320` size `0x95`, the final byte at `0x004623b4`, the `0xcc` padding after `0x004623b5`, the next function at `0x004623c0`, one StaticObjImageLib caller, and rectangle-helper callees. Final C++ remains blank because the helper clears the minimum score/emitter gate but still lacks source-quality naming/signature evidence.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE` and attached to [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md).
  - Before: the clipped buffer-view helper was documented but unclassified in autogen coverage.
  - After: it is marked as source-level alpha-surface helper behavior under the validated AlphaMaskSurface file root; C++ remains blank because the final source-facing name/signature and class split are not source-quality yet.
  - Evidence: live IDA MCP confirms `sub_462320` at `0x00462320`, size `0x95`, one direct caller in `sub_4DD2C0`, and callees to rectangle helpers `0x004b7cc0` and `0x004b7c50`.

- 2026-05-30: Raised completion/confidence from `0/0` to `84/88`. Previously this page had behavior notes but no score; it now records the current IDA MCP range/xref/decompilation recheck, output-view offsets, and C++ reconstruction candidate.
