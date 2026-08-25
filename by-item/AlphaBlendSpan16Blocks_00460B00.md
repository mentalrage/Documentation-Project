*** UID:0000TW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md). Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000TW].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AlphaBlendSpan16Blocks 0x00460B00

## Status

- Confidence: strong for behavior and source ownership.
- Entity kind: free render helper.
- Likely source module: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Autogen parent: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md).
- Exact range: `0x00460b00-0x00460c0a`

## Behavior

`AlphaBlendSpan16Blocks` blends RGB565 rows in four-pixel blocks using a 0..32 weight. It is the non-50-percent bulk path under `AlphaBlendSpan16`, handling the row loop and pitch advancement while writing blended pixels into the destination span.

## Source Form Decision

2026-06-29 B003 implementation resolves the by-memory target [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md) as a first-draft MSVC x86 inline-assembly helper emitted through [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md). The target C++ uses local qword RGB565 masks for the binary constants at `0x00610ea8` and `0x00610eb0`, and local qword source/inverse weight vectors for the binary scratch cells at `0x0067a820` and `0x0067a828`. This follows the support-page policy that the clean source may fold scratch data into local MMX temporaries when behavior is preserved.

2026-06-30 B013 implementation resolves this by-item empty marker as a duplicate alias only. The address `0x00460b00` is the same body as canonical [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md), which already emits formal C++; this item now emits a target-specific covered-by comment to avoid a duplicate helper definition.

The source-facing helper name remains `AlphaBlendSpan16Blocks` because it pairs with `AlphaBlendSpan16` and the sibling block helper names, but current MCP does not prove it as the active IDA symbol. Current session `dad3692b` exposes the function as `sub_460B00`; the 2026-06-16 saved-label observation is retained as historical evidence only.

## Evidence

- Live IDA MCP on 2026-06-04 identifies `0x00460b00-0x00460c0a` as `sub_460B00`, the weighted RGB565 block helper called from `AlphaBlendSpan16` at `0x004605fd`.
- The function expands source/inverse weights into `qword_67a820`/`qword_67a828`, uses RGB565 masks at `0x00610ea8`/`0x00610eb0`, processes four pixels per MMX iteration, and ends with `emms`.
- The function has no object receiver or asset-library state.
- 2026-06-14 A001 live IDA MCP session `a001_goal2_class_batch` reconfirmed active `NexusTK.exe.i64`, `sub_460B00` at `0x00460b00` with size `0x10a` / 266 bytes, exactly one code xref from `sub_460500` at `0x004605fd`, and disassembly references to scratch qwords `0x0067a820`/`0x0067a828` plus RGB565 masks `0x00610ea8`/`0x00610eb0`.
- 2026-06-16 C001 live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed the same `0x10a` / 266-byte range, sole caller at `0x004605fd`, no callees, RGB565 MMX mask/weight behavior, and saved the low-risk function label `AlphaBlendSpan16Blocks` after dry-run validation. No prototype, local, type, or inline-assembly reconstruction was forced.
- 2026-06-29 B003 MCP session `dad3692b` reconfirmed `sub_460B00`, size `0x10a`, no callees, one caller at `0x004605fd`, data xrefs to `0x0067a820/0x0067a828/0x00610ea8/0x00610eb0`, and adjacent `0xcc` padding. The same pass found no active MCP name entry for `AlphaBlendSpan16Blocks`, so the C001 label claim is historicalized rather than treated as current active-symbol proof.

## Cross-References

- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md)
- [UID:0000TV][AlphaBlendSpan16_00460500](by-item/AlphaBlendSpan16_00460500.md)
- [UID:0000US][HalfBlendSpan16Blocks_00460C10](by-item/HalfBlendSpan16Blocks_00460C10.md)

## Changes

- 2026-06-16 C001 Goal 2 item/IDA refresh:
  - Before: score was `85/90` and IDA still used `sub_460B00`.
  - After: raised to `86/91`, saved the IDA label `AlphaBlendSpan16Blocks`, and reconfirmed the direct SoftwareBlend16 owner/emitter route.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `analyze_component`, `decompile`, dry-run rename validation, applied rename, `idb_save ok:true`, and post-save lookup. This saved-label observation is historical; current 2026-06-29 MCP session `dad3692b` exposes `sub_460B00`.
- 2026-06-29 B003 implementation callback:
  - By-memory target [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md) now contains first-draft formal C++ as an MSVC x86 inline-assembly helper.
  - The accepted source form uses local qword masks and local qword weight vectors rather than requiring separate support declarations for `0x00610ea8/0x00610eb0` or `0x0067a820/0x0067a828`.
  - Rejected alternatives remain documented: no no-owner/non-emitting reclassification, no range split/merge, no portable scalar/decompiler-shaped body, and no claim that the current active IDA name proves original source spelling.
- 2026-06-14 A001 Goal 2 by-item score pass:
  - Raised completion from `84` to `85`; confidence remains `90`.
  - Summary/evidence: live IDA MCP reconfirmed the exact `0x00460b00-0x00460c0a` function, `0x10a` / 266-byte size, single caller at `0x004605fd`, MMX scratch qword setup, RGB565 mask reads, and unchanged [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md) owner/emitter route. 2026-06-30 B013 resolves this by-item row as a covered-by alias because canonical [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md) owns the formal body.
- 2026-06-04: Parent metadata aligned and live IDA evidence refreshed.
  - Before: score was already `84/90`, but reconstructable/autogen metadata was blank and the evidence referenced stale restoration metadata.
  - After: marked reconstructable, attached to [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md), and replaced stale source wording with live IDA range/caller/MMX evidence.
  - Evidence: live IDA confirms `0x00460b00-0x00460c0a`, caller `0x004605fd`, scratch qwords `0x0067a820/0x0067a828`, RGB565 masks, four-pixel MMX loop, and `emms`.

- 2026-05-30: Grading changed from `0/0` to `84/90`.
  - Before: page documented behavior, ownership, caller evidence, and cross-links but remained unevaluated.
  - After: score reflects strong documentation for this small RGB565 row/block blend helper.
  - Evidence: IDA caller evidence ties `0x00460b00-0x00460c0a` directly to [UID:0000TV][AlphaBlendSpan16_00460500](by-item/AlphaBlendSpan16_00460500.md) under [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md).
