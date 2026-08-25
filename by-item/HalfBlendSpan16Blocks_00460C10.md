*** UID:0000US | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md). Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000US].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HalfBlendSpan16Blocks 0x00460C10

## Status

- Confidence: strong for behavior, exact IDA boundary, caller set, adjacent padding, MMX mask constants, and SoftwareBlend16 ownership; medium for final original helper name and filename.
- Entity kind: free render helper.
- Likely source module: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Exact range: `0x00460c10-0x00460c8c`
- Owner/emitter route: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- C++ reconstruction: this by-item mirror now emits a covered-by comment only. Canonical [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md) owns the formal helper implementation.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page now documents exact function bounds, previous/next helper boundaries, modeled plus raw caller sites, no-callee MMX body, 49-instruction disassembly shape, qword mask constants, adjacent padding, SoftwareBlend16 owner/emitter route, and remaining source signature/declaration blockers. |
| Confidence | 90 | IDA lookup/xref/disassembly, `get_int` mask reads, `get_bytes` padding checks, and the exact memory page [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md) align. Confidence stays below final-source level because the original helper spelling and public/private declaration shape are still unproven. |

## Behavior

`HalfBlendSpan16Blocks` is the exact 50 percent RGB565 block path. It averages source and destination pixels in four-pixel groups using the standard RGB565 half-blend mask formula, then advances source and destination spans by their pitches for each row.

## Evidence

- IDA MCP recheck on 2026-05-31 confirms `sub_460C10` starts at `0x00460c10`, ends half-open at `0x00460c8c`, has no project callees, and is referenced from `sub_460500` plus another alpha-blend-family code reference at `0x0046073e`.
- IDA MCP decompile shows the MMX four-pixel loop, RGB565 half-blend masks `0xF7DEF7DEF7DEF7DE` and `0x0821082108210821`, row-pitch advancement, `pushaw`/`popaw`, and `_m_empty()`.
- The generated body is a state-free block pixel helper.
- 2026-06-04 live IDA MCP `lookup_funcs` confirms `sub_460C10` at `0x00460c10` has size `0x7c`, previous function `sub_460B00` ends at `0x00460c0a`, and next function `sub_460C90` starts at `0x00460c90`.
- 2026-06-04 live IDA `xrefs_to` confirms exactly two code references: `0x00460544` inside `sub_460500` and raw code reference `0x0046073e` in the adjacent half-blend span helper area where IDA has no separate function object.
- Live IDA disassembly confirms a 49-instruction MMX body: `arg_10` is shifted by 3 to convert four-pixel blocks to bytes, `mm2` loads `qword_610EB8`, `mm3` loads `qword_610EC0`, the loop reads source/destination qwords, applies `pand`/`psrlw`/`paddw`, writes the blended qword back to destination, advances both pointers by 8, advances rows by the source/destination pitches, and exits through `popaw`/`emms`.
- Live IDA `py_eval` reads `qword_610EB8` as `0xf7def7def7def7de` and `qword_610EC0` as `0x0821082108210821`, with xrefs at `0x00460c21` and `0x00460c28`.
- Live byte inspection confirms `0x00460c0a-0x00460c10` is six `0xcc` alignment bytes and `0x00460c8c-0x00460c90` is four `0xcc` alignment bytes, so the function boundary is not overlapping neighboring helpers.

2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed:

- `lookup_funcs` resolves `0x00460c10` to `sub_460C10`, size `0x7c`; `0x00460c8c` is not a function and the next modeled function remains `0x00460c90`. Decimal size `124 == 0x7c` was verified with `int_convert.py`.
- `analyze_function 0x00460c10` reports no callees and a compact three-complexity body; `xrefs_to 0x00460c10` reports two direct code refs, one modeled from `0x00460544` inside `sub_460500` and one raw ref at `0x0046073e`.
- `disasm 0x00460c10` reports 49 total instructions (`49 == 0x31`, verified with `int_convert.py`), including `arg_10 << 3`, `pushaw`, `movq mm2, ds:qword_610EB8`, `movq mm3, ds:qword_610EC0`, MMX `pand`/`psrlw`/`paddw` blend operations, and `emms`.
- `get_int` reads `0x00610eb8` as `0xf7def7def7def7de` and `0x00610ec0` as `0x0821082108210821`; both decimal-to-hex values were verified with `int_convert.py`.
- `get_bytes` reconfirmed six `0xcc` bytes at `0x00460c0a-0x00460c10` and four `0xcc` bytes at `0x00460c8c-0x00460c90`; `6 == 0x6` and `4 == 0x4` were verified with `int_convert.py`.
- Final reconstruction C++ stays blank despite the confirmed emitter route because the exact source-facing function name, calling convention, declaration visibility, and surrounding helper prototypes are not yet final-source quality.

## Cross-References

- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md)
- [UID:0000TV][AlphaBlendSpan16_00460500](by-item/AlphaBlendSpan16_00460500.md)
- [UID:0000TW][AlphaBlendSpan16Blocks_00460B00](by-item/AlphaBlendSpan16Blocks_00460B00.md)
- [UID:000206][0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw](by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md)
- [UID:0002OO][0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants](by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented a 50 percent RGB565 helper, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata reflects the existing researched body and fresh IDA verification. 2026-06-30 B013 resolves this by-item row as a covered-by alias because canonical [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md) now owns the formal body.
  - Evidence: IDA MCP confirms the exact `0x00460c10-0x00460c8c` function range, two alpha-blend-family references, no project callees, and a decompiled MMX RGB565 half-blend loop.
- 2026-06-04 live IDA parent-attachment and score update:
  - Before: scores were `70/85`, with `RECONSTRUCTABLE:TRUE` but blank parent metadata and generated-provenance wording in the evidence.
  - After: scores set to `82/88` and owner/emitter route `0000NT`; generated-provenance wording was removed from the evidence basis.
  - Summary/evidence: live IDA revalidated the exact function boundary, two caller sites, raw-caller caveat at `0x0046073e`, 49-instruction MMX half-blend loop, mask constants at `0x00610eb8/0x00610ec0`, no callees, adjacent `0xcc` padding, and SoftwareBlend16 ownership. 2026-06-30 B013 resolves the by-item page as a covered-by alias while canonical [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md) carries the formal behavior-preserving C++ body.
- 2026-06-14 A001: Raised from `82/88` to `85/90`.
  - Before: the page had strong evidence but still used legacy parent/code-entry terminology and did not record current MCP memory reads for mask constants or padding.
  - After: added a score rationale table, current owner/emitter wording, fresh lookup/analyze/xref/disasm evidence, `get_int` qword mask reads, `get_bytes` padding checks, and `int_convert.py`-verified constants.
