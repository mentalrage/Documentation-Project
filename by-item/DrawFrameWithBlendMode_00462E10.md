*** UID:0000UI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000YN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DrawFrameWithBlendMode 0x00462E10

## Status

- Confidence: promoted support index; source-bearing evidence lives on [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md).
- Entity kind: non-emitting support/alias for the exact by-memory function page.
- Likely source module: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), emitted through [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md).
- Owner/emitter: no direct emitter on this support index.
- Exact range: `0x00462e10-0x00462f1e`

## Behavior

`AlphaMaskSurface::DrawFrameWithBlendMode` clips a source frame rectangle against an `AlphaMaskSurface` destination rectangle, computes matching source and destination byte pointers, and applies one of three transfer modes:

| Mode | Operation |
| --- | --- |
| `0` | Replace/copy source bytes into destination via [UID:00020C][0x00460df0-0x00460e79.ByteSpanCopyRows](by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md). |
| `1` | Add source bytes to destination bytes via [UID:00020D][0x00460e80-0x00460f09.ByteSpanAddRows](by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md). |
| `2` | Subtract source bytes from destination bytes via [UID:00020E][0x00460f10-0x00460f99.ByteSpanSubtractRows](by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md). |

## Evidence

- 2026-05-30 live IDA MCP reports `sub_462E10` at `0x00462e10-0x00462f1e`.
- IDA direct callers are `0x004dfc42` in `0x004dfbb0-0x004dfc5a` and `0x004dfcf2` in `0x004dfc60-0x004dfd0a`, the documented LightObjImageLib draw-mode helpers.
- The function guards against missing destination pixels (`[this+0x14] == 0`) and null rectangle/source arguments, then calls `0x004b7cc0` to clip/intersect the source and destination rectangles.
- After computing matching source/destination row starts, stride, width, and height, the mode dispatch at `0x00462ebf-0x00462ecc` calls `0x00460df0` for mode `0`, `0x00460e80` for mode `1`, and `0x00460f10` for mode `2`; unsupported modes fall through without drawing.
- Source ownership remains placed with [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) because the helper uses the AlphaMaskSurface pixel pointer/stride fields, but the row-operation callees live in the adjacent software span helper cluster.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed `DrawFrameWithBlendMode` at `0x00462e10` size `0x10e`, the three row helpers at `0x00460df0`, `0x00460e80`, and `0x00460f10` size `0x89` each, and exactly two direct code xrefs to this helper at `0x004dfc42` and `0x004dfcf2`.
- `analyze_function 0x00462e10` reports two callers and five callees. Targeted decompilation again shows clipping through `0x004b7cc0`, then mode dispatch to copy/add/subtract row helpers for modes `0`, `1`, and `2`.
- 2026-06-16 live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed `NexusTK.exe.i64` at imagebase `0x400000`, `sub_462E10` size `0x10e`, prototype-shaped `__thiscall(_DWORD *this, _DWORD *, int, _DWORD *, int)`, two callers (`LightObjImageLibDrawLightMode1` and `LightObjImageLibDrawLightMode2`), and callees `0x004b7cc0`, `0x00460df0`, `0x00460e80`, `0x00460f10`, and the security-cookie check.
- A 2026-06-16 PE byte scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found no absolute VA/RVA pointer hits for `0x00462e10`; it found only the two rel32 call sites at `0x004dfc42` and `0x004dfcf2`. The same scan found only one rel32 call to each row helper from this function: `0x00462f03` to copy rows, `0x00462eef` to add rows, and `0x00462edb` to subtract rows.
- Byte reads around `0x00462e03` and `0x00462f08` confirm `0xcc` alignment before the prologue and two `0xcc` bytes after the `retn 10h` endpoint, preserving the exact `[0x00462e10,0x00462f1e)` split.
- 2026-06-27 B008 MCP session `b001_000241_20260627` resolved the source-facing prototype as a member method, not a free helper: callers place the destination `AlphaMaskSurface` in `ecx`, push only `destinationRect`, `sourceFrame`, `sourceRect`, and `blendMode`, and the callee returns with `retn 10h`.
- Formal reconstruction C++ intentionally remains blank on this by-item page because [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md) is the canonical source-bearing by-memory emitter. This page exists only to preserve the promoted item/search alias and behavior evidence without duplicate output.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | -1 | Promoted support/index page. The source-bearing documentation and score live on [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md). |
| Confidence | -1 | Promoted support/index page. The by-memory page now carries the MCP-backed member-method evidence and formal C++. |

## Cross-References

- [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:00020C][0x00460df0-0x00460e79.ByteSpanCopyRows](by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md)
- [UID:00020D][0x00460e80-0x00460f09.ByteSpanAddRows](by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md)
- [UID:00020E][0x00460f10-0x00460f99.ByteSpanSubtractRows](by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE` and attached to [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md).
  - Before: the blend-mode alpha-frame helper was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned alpha-mask helper source under the validated AlphaMaskSurface file root; C++ remains blank because final source-facing names and exact frame/input types are not source-quality.
  - Evidence: live IDA MCP confirms `sub_462E10` at `0x00462e10`, size `0x10e`, with callees to the byte-span copy/add/subtract row helpers and clipping helper `0x004b7cc0`.

- What existed before: this page had the right high-level behavior but unevaluated completion/confidence metadata and a non-IDA metadata bullet as evidence.
- What changed to: the page now uses live IDA MCP evidence for range, callers, clipping, and mode dispatch. Completion/confidence were set to `82/86`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `sub_462E10` as `0x00462e10-0x00462f1e`, direct callers at `0x004dfc42` and `0x004dfcf2`, clipping via `0x004b7cc0`, mode `0` call to `0x00460df0`, mode `1` call to `0x00460e80`, and mode `2` call to `0x00460f10`.
- 2026-06-14 A001: Raised completion/confidence from `82/86` to `85/88`.
  - Before: the page had accurate IDA evidence, but no current refresh tying the row helper sizes, caller count, and final code blocker together.
  - After: added the 2026-06-14 live IDA MCP refresh, score rationale, and current code-entry caveat.
  - Evidence: `lookup_funcs`, `analyze_function`, `xrefs_to`, and targeted decompile checks reconfirm the exact helper and row-operation bounds, two LightObjImageLib caller sites, clip/intersect call, and mode dispatch.
- 2026-06-16 A001 Goal 2 by-item evidence refresh:
  - Before: score `85/88`; owner/emitter remained [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), with final C++ blank for source-quality type/name blockers.
  - Changed to: score `86/89`; owner/emitter and blank final C++ unchanged.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, and compact analysis reconfirmed function size, two LightObjImageLib callers, row-helper callees, and clip helper. A PE byte scan found no VA/RVA pointer hits and only the documented rel32 calls, and `get_bytes` reconfirmed the alignment-bounded endpoint.
- 2026-06-28 B008 duplicate-emission cleanup:
  - Before: this promoted by-item page was still `86/89`, reconstructable, and emitted through [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), duplicating the exact by-memory function page.
  - Changed to: support/index metadata `-1/-1`, `CANONICAL_OWNER:0000YN`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++.
  - Evidence: [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md) now owns the MCP-backed `AlphaMaskSurface::DrawFrameWithBlendMode` formal C++ and exact source-bearing range, so this page must remain a non-emitting alias/index only.
