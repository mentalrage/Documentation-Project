*** UID:0000UK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0001JR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this callback item is covered by [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DrawTextRunCallback 0x00593DB0

## Status

- Confidence: strong for IDA callback bounds, address-taking xrefs, callee/call-site behavior, TextEditPane ownership, callback ABI, draw-state layout, draw-line overlay fields, and first-draft readiness on the exact memory page.
- Entity: file-local/free callback `DrawTextRunCallback`.
- Range: `0x00593db0-0x00593ef6` in IDA end-exclusive form; last instruction is `0x00593ef5`.
- Likely source file: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Parent attachment: [UID:0000ON][TextEditPane](by-file/TextEditPane.md) clears the current gate, and exact callback memory [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) is now `90/91`; attaching under the file parent remains justified by current parent and child evidence.
- C++ reconstruction: the exact memory page [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) now owns the first-draft formal C++ block. This item mirror stays prose-only and must not duplicate the target block.
- B004 corrected TextEditPane implementation callback: this by-item page is a covered mirror for [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md). The formal block intentionally contains only a covered-by comment, and the canonical owner is the exact memory page.

## Purpose

`DrawTextRunCallback` is the per-run callback used by `TextEditPane::IterateTextRuns`. It prepares the visible line rectangle, intersects it with the pane clip region, swaps temporary drawing state, applies run color/effect state, trims trailing whitespace for right-aligned final segments, and forwards the final UTF-16 slice into the existing text renderer.

## Evidence Notes

- Live IDA evidence shows it is address-taken as a callback, not directly called as a member method. A source-facing callback shape consistent with the stack arguments is:

```text
static bool __cdecl DrawTextRunCallback(TextEditLineRecord *line,
                                        const TextRunFormatData *format,
                                        const wchar_t *text,
                                        int textOffset,
                                        unsigned short charCount,
                                        unsigned short segmentFlags,
                                        TextRunDrawState *state,
                                        TextEditPane *pane)
```

- 2026-05-30 live IDA MCP reports the function object as `sub_593DB0`, `0x00593db0-0x00593ef6`, size `326`.
- Live IDA xrefs to the callback address are two address-taking pushes: `0x005908e6` inside `sub_590810` and `0x0059168c` in the adjacent text-edit selection/invalidation region. Both use `push offset sub_593DB0`.
- Live IDA callees are [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md), [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) subrange `0x004b7cc0`, [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) subranges `0x004baaa0` and `0x004baad0`, callback slot [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) `dword_69B3FC`, and lower text renderer `0x005946b0`.
- The sibling [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) handles row-width measurement for the same text-run iteration family.
- 2026-06-04 live IDA MCP recheck confirms `sub_593DB0` at `0x00593db0-0x00593ef6`, previous text-run callback `sub_593C20` at `0x00593c20-0x00593ce5`, and the lower renderer `sub_5946B0` at `0x005946b0-0x0059489f`.
- 2026-06-04 live IDA `xrefs_to` still reports only two data/address-taking references to the callback: `0x005908e6` inside `sub_590810` and `0x0059168c` in a raw `.text` code island between `sub_591520` and `sub_591740`.
- Caller-context disassembly shows both xrefs zero a local callback-state rectangle block, push the state pointer and `offset sub_593DB0`, then call `sub_593500`, the text-run iterator. The raw `0x00591650-0x005916b2` island ends with `retn 8` and is recorded as raw code rather than a named function because IDA has no function object there.
- 2026-06-04 live IDA call-site inventory inside the callback confirms calls at `0x00593e05`, `0x00593e0d`, `0x00593e34`, `0x00593e3c`, `0x00593e47`, `0x00593e75`, `0x00593e8a`, `0x00593ea0`, `0x00593eae`, `0x00593ed4`, and `0x00593ee8`, covering clip/intersect, draw-state swap, surface render callback, text origin update, style color update, optional style-object virtual dispatch, trailing visible-character trim, and final UTF-16 text draw.
- 2026-06-14 live IDA MCP refresh under session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`, `sub_593DB0` size `0x146` / 326 bytes (Verified with `int_convert.py`), no function at `0x00593ef6` or `0x00593f00`, and successor `sub_594040` at `0x00594040`.
- The same refresh reconfirmed exactly two address-taking xrefs to the callback start: `0x005908e6` inside `sub_590810` and raw/no-function site `0x0059168c`. `xrefs_to 0x00593f00` returned no references, so the raw code after the padding remains separate from this callback.
- 2026-06-14 `callees 0x00593db0` returned `0x004b96c0`, `0x004b7cc0`, `0x004b9660`, external callback slot `0x0069b3fc`, `0x004baaa0`, `0x004b9600`, `0x004b9680`, `0x004baad0`, and `0x005946b0`, matching the documented GrafPort/geometry/text-renderer interpretation.
- Byte evidence at the tail shows the callback ending with `xor al, al; pop ebx; mov esp, ebp; pop ebp; retn`, followed by ten `0xcc` bytes before the raw `0x00593f00` prologue. This supports the exact `0x00593db0-0x00593ef6` half-open range and the separate raw-neighbor caveat already tracked by the exact memory page.
- 2026-06-16 live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed `sub_593DB0` size `0x146`, prototype-shaped `char __cdecl(_DWORD *, int, wchar_t *Source, int, unsigned __int16, int, int, int)`, two data/address-taking xrefs at `0x005908e6` and `0x0059168c`, no IDA function at `0x00593ef6` or `0x00593f00`, and successor `sub_594040` with direct callers at `0x0058ebb1` and `0x00590daa`.
- A 2026-06-16 PE byte scan found exactly two absolute-VA immediate references to `0x00593db0` at `0x005908e7` and `0x0059168d`, no RVA-pointer hits, and no rel32 calls. The same scan found no absolute/RVA pointer hits and no rel32 branches for the raw neighbor `0x00593f00`.
- 2026-06-16 `get_bytes` around `0x00593dad`, `0x00593ee8`, `0x00593f00`, and `0x00591670` reconfirmed the three-byte pre-padding, ten-byte post-padding, raw-neighbor prologue, and the raw call-site `push 0x00593db0` pattern at `0x0059168c`.
- 2026-06-26 B006 MCP-backed source-quality implementation used active session `80de0a67` and reconfirmed the source-quality blockers that now make the exact memory page first-draft ready:
  - `lookup_funcs` reports `sub_593DB0` size `0x146` / 326 bytes (Verified with `int_convert.py`) and half-open range `0x00593db0-0x00593ef6`.
  - `TextEditPane::IterateTextRuns` at `0x00593500` proves the eight-argument cdecl callback ABI: line record, `TextRunFormatData`, UTF-16 pointer, text offset, character count, segment flags, caller state, and `TextEditPane *`.
  - `TextRunDrawState` is a two-rectangle plus byte caller state: `lineRect` at `+0x00`, `clippedLineRect` at `+0x10`, and `applyRunTextColor` at `+0x20`.
  - The historical callback-only name `TextRunDrawLineRecord` is superseded by the shared 16-byte `TextEditLineRecord`: `+0x04` line top, `+0x08` remaining/slack width, and the following record's top at effective `+0x14` are consumed by this callback, while [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) covers the shared measure-facing layout.
  - `TextRunFormatData+0x04` supplies the run text color and `TextRunFormatData+0x08` is an optional [UID:0000EN][TextEditObject](by-class/TextEditObject.md) pointer. Non-null objects dispatch vtable slot `+0x0c` and suppress plain text drawing.
  - The callback uses `TextEditPane` text-area bounds `+0x120/+0x124/+0x128`, alignment/mode `+0x8c`, editor flags `+0x15c`, inherited GrafPort draw state `+0x70/+0x74`, shared text color setter `0x004b9680`, visible-count helper `0x004baad0`, exact Surface slot-7 `g_pfnFillRect`, and lower renderer `0x005946b0`.
  - `xrefs_to 0x00593f00` still returns zero direct raw-start refs, keeping [UID:0003FD][0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw](by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md) separate from this cdecl callback.

## Score Rationale

| Field | Score | Rationale |
| --- | --- | --- |
| Completion | `90` | Exact range, address-taking xrefs, caller context, callees, padding boundary, sibling/raw-neighbor relationship, parent route, exact memory support, PE pointer/branch reachability checks, iterator ABI, state layout, line overlay, source-facing helper names, and first-draft readiness on [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) are documented. |
| Confidence | `91` | IDA function metadata, xrefs, callees, bytes, PE immediate-reference scanning, TextEditPane ownership, caller setup, and iterator decompilation agree on the callback shape. Confidence stays below final-audit levels because exact original spellings for text-area fields, alignment enum, lower renderer, and inline-object hook remain inferred. |

## Ownership Decision

Treat this as a file-local/free helper in `TextEditPane.cpp`. Its only known live purpose is servicing the editor's run iterator, but the calling convention and callback shape are not a `TextEditPane` member function.

The accepted source-facing support names for current reconstruction are `TextRunDrawState`, shared `TextEditLineRecord`, `m_textAreaLeft`, `m_textAreaTop`, `m_textAreaRight`, `m_textAlignment`, inherited `m_drawMode`, `kTextEditBlackBackground`, exact `g_pfnFillRect`, and `DrawTextRunSegment`. These names are behavior-backed inferred names, not original-proof spellings.

## UID00030C Current Source Contract - 2026-07-19

- Signature and state-layout proof are no longer missing. Canonical [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) owns the complete source-ready body; this item remains only a covered mirror and emits no second definition.
- The eight-argument cdecl contract is `TextEditLineRecord *`, `const TextRunFormatData *`, `const wchar_t *`, text offset, `unsigned short` character count, `unsigned short` segment flags, `TextRunDrawState *`, and `TextEditPane *`.
- The complete header-defined `TextRunDrawState` is `RectBounds lineRect`, `RectBounds clippedLineRect`, and `unsigned char applyRunTextColor`. UID00030C zero-initializes it and sets the byte from `kTextEditUseCurrentTextColor`; no duplicate callback-local state definition remains.
- Current source tokens are shared `TextEditLineRecord`, inherited `m_drawMode`, `kTextEditBlackBackground`, and exact Surface slot-7 `g_pfnFillRect`. Historical `TextRunDrawLineRecord`, `m_renderMode`, raw `dword_69B3FC`, `g_pfnFillOrInvalidateRect`, and generated `g_pfnLockSurface` are rejected from emitted source.
- The exact two address-taking routes, raw-neighbor exclusion, optional `TextEditObject` dispatch, final-segment whitespace trim, and lower `DrawTextRunSegment` forwarding remain unchanged. No score, owner, emitter, covered-by formal, or unrelated evidence changes.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md)
- [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md)

## Changes

- 2026-07-19 B004 UID00030C accepted implementation callback:
  - Preserved `91/91`, canonical owner UID0001JR, emitter UID0000ON, reconstructable true, blank position, the exact covered-by managed comment, callback identity/range/xrefs/callees, raw-neighbor evidence, and all history.
  - Replaced current callback-only line-record wording with shared `TextEditLineRecord` and recorded the complete header-defined state plus `m_drawMode`, `kTextEditBlackBackground`, and `g_pfnFillRect` tokens.
  - Historicalized only the formerly unresolved signature/state-layout blocker. Canonical source remains exclusively on UID0001JR; no separate item emitter or duplicate body was added.

- 2026-06-30 B004 corrected TextEditPane implementation callback:
  - Before: `90/91`, canonical owner [UID:0000ON][TextEditPane](by-file/TextEditPane.md), and formal C++ blank even though the exact memory page already owned the callback body.
  - Changed to: `91/91`, canonical owner [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md), with a covered-by formal comment so this item mirror does not duplicate the first-draft C++ body.
  - Evidence: the revised B004 [UID:0000ON][TextEditPane](by-file/TextEditPane.md) report treated this as an already-resolved exact child: the cdecl callback ABI, state layout, draw-line overlay, optional `TextEditObject` vtable dispatch, raw-neighbor exclusion, and first-draft body live on [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md).

- What existed before: The page had `0` completion/confidence and used generated import/recovered-file statements as evidence.
- What it was changed to: The page now records live IDA MCP function extent, address-taking callback xrefs, concrete callees, and the callback-source ownership decision.
- Summary and evidence: IDA confirms `sub_593DB0` at `0x00593db0-0x00593ef6`, two `push offset sub_593DB0` xrefs at `0x005908e6` and `0x0059168c`, and outgoing calls through `0x004b96c0`, `0x004b7cc0`, `0x004b9660`, `0x004b9680`, `0x004baaa0`, `0x004baad0`, `dword_69B3FC`, and `0x005946b0`.
- 2026-06-04 live IDA parent-attachment and score update:
  - Before: scores were `70/85`, with blank reconstructable and parent metadata.
  - After: scores set to `78/86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000ON`.
  - Summary/evidence: live IDA revalidated function bounds, exact callback xrefs, caller context for both iterator uses, the raw `0x00591650-0x005916b2` code-island caveat, the complete call-site inventory inside the callback, and sibling/parent TextEditPane ownership. Final C++ stays blank because the callback-state structure and source-facing signature are not yet source-quality under the current code-entry gate.
- 2026-06-14: Raised completion/confidence from `78/86` to `85/88`.
  - Before: the item still carried the older low-completion score and stale parent score wording despite exact memory support reaching `85/88`.
  - After: the page records the current live IDA session refresh, successor/no-function checks, byte-level tail padding, current parent/memory scores, and a score rationale. Final C++ remains blank under the current code-entry gate because callback state fields and source-facing signature are still unresolved.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, and `get_bytes` on 2026-06-14.
- 2026-06-16 A001 Goal 2 by-item evidence refresh:
  - Before: score `85/88`; final C++ remained blank for callback-state and source-signature blockers.
  - Changed to: score `86/89`; owner/emitter remain [UID:0000ON][TextEditPane](by-file/TextEditPane.md), and final C++ remains blank.
  - Evidence: live IDA MCP reconfirmed callback size, data xrefs, no-function raw neighbor, successor function, and callee set. PE scanning found only two absolute-VA immediate references to the callback and no branch/pointer evidence for the raw neighbor, and byte reads reconfirmed both padding boundaries plus the raw `push offset` call-site pattern.
- 2026-06-26 B006 Rule 26 source-quality mirror sync:
  - Changed to: `COMPLETION:90`, `CONFIDENCE:91`; owner/emitter/reconstructable metadata unchanged.
  - Evidence: exact target [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) now contains the first-draft formal C++ block and documents MCP session `80de0a67`, `0x146`-byte function extent, two address-taking refs, raw-neighbor exclusion, iterator ABI, `TextRunDrawState`, draw-line overlay, text-area/alignment fields, optional `TextEditObject` dispatch, and lower renderer forwarding. This item page remains a prose mirror and intentionally does not duplicate the formal target C++.
