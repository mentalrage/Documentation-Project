*** UID:0000G8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WorldMapNodeEntryVector

## Status

- Disposition: non-emitting documentation facade for the old MSVC/Dinkumware `std::vector<WorldMapNode>` specialization, not a handwritten NexusTK class.
- Confidence: very strong for helper behavior, exact boundaries, caller context, 0x94-byte element size, allocation/free policy, standard-library identity, and rebuild handling.
- Likely source file: [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- Address range: [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md), with exact helper children.
- Evidence basis: live IDA MCP disassembly/decompilation on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Class Purpose

`WorldMapNodeEntryVector` is a historical documentation label for compiler-generated `std::vector<WorldMapNode>` specialization bodies. The source-facing member is ordinary `std::vector<WorldMapNode> m_nodes`; no custom source class should be emitted.

The vector object is a three-pointer layout: begin at `+0x00`, current/end at `+0x04`, and capacity end at `+0x08`. Its record payload starts with two copied dwords, then a wide label copied to record offset `+0x08` with `_wcscpy_s(..., 0x40, ...)` in the caller.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~WorldMapNodeEntryVector` | [UID:0003SZ][0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor](by-memory/0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor.md) | Releases the node-entry buffer, handles aligned large allocations, and clears begin/current/capacity pointers. |
| `Assign` | [UID:0003T7][0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign](by-memory/0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign.md) | Assigns repeated 0x94-byte node-entry values across the vector, growing storage when needed. |
| free helper | [UID:0003T8][0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation](by-memory/0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation.md) | Frees an existing node-entry allocation, including large-allocation raw-pointer recovery. |

## Evidence Notes

- B001 WorldMapPane executable split on 2026-06-16 created exact by-memory children for all three helpers: [UID:0003SZ][0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor](by-memory/0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor.md), [UID:0003T7][0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign](by-memory/0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign.md), and [UID:0003T8][0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation](by-memory/0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation.md).
- Live IDA confirms `sub_5C5510` as `0x005c5510-0x005c557a`. The destructor reads begin/current/capacity from `this+0/+4/+8`; when the backing allocation is at least `0x1000` bytes it recovers the raw allocation pointer from `[begin-4]`, validates the aligned-pointer delta is at most `0x1f`, frees through `sub_5C7526`, and zeroes all three vector fields.
- `CodeRefsTo(0x005c5510)` reports the main destructor call at `0x005c33eb` with `ecx = this + 0x258`, plus cleanup funclet jump `0x0060bf1b` with the same `+0x258` offset.
- Live IDA confirms `sub_5C58C0` as `0x005c58c0-0x005c5a8f`. It divides pointer differences by `148`, grows capacity by roughly 1.5x when needed, clamps through the `0x1bacf91` maximum, allocates `count * 0x94` bytes, uses 32-byte aligned storage for allocations at least `0x1000` bytes, and fills entries with `qmemcpy(..., 0x94)`.
- The assign body proves the 0x94-byte record size independently: allocation uses `imul ..., 0x94`, pointer increments add `0x94`, and the copy loop uses `rep movsd` with count `0x25`.
- `CodeRefsTo(0x005c58c0)` reports two calls inside `WorldMapPane` construction/packet setup at `0x005c2d4f` and `0x005c301b`. Both caller paths `memset` a 0x94-byte stack template, pass the signed packet count, call the vector assign helper, then populate each allocated node record and copy the display label through `_wcscpy_s` with `0x40` wide characters.
- The class/path name is retained as a descriptive navigation label only. Standard vector layout, allocator growth, destructor, assign, and free behavior reject a separate handwritten source type.

## Source Disposition And Rebuild Handling

- Keep this page and exact children as binary-behavior documentation under semantic source owner [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md).
- Keep `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, and a blank managed C++ block. Do not emit a custom class, wrapper, assign/destructor/free implementation, or separate source file.
- The source-facing declaration is `std::vector<WorldMapNode> m_nodes` in `WorldMapPane`; ordinary construction, `assign`, destruction, and allocator semantics regenerate the documented helper bodies.
- `WorldMapNode` has exact size `0x94`: coordinates at `+0x00/+0x04`, `wchar_t name[64]` at `+0x08`, a 16-bit travel field at `+0x88`, natural padding at `+0x8a`, and 32-bit travel payload fields at `+0x8c/+0x90`.
- Constructor calls at `0x005c2d4f` and `0x005c301b` assign records; UID0003SR derives node count from `(end - begin) / 0x94`. Destructor paths reach the specialization cleanup. These uses converge on one standard vector member.
- The large-allocation header recovery/alignment checks and approximately 1.5x growth are toolchain implementation details. They remain exact evidence but are intentionally absent from handwritten WorldMapPane source.

## Cross-References

- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md)
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)
- [UID:0003SZ][0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor](by-memory/0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor.md)
- [UID:0003T7][0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign](by-memory/0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign.md)
- [UID:0003T8][0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation](by-memory/0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation.md)

## Changes

- 2026-07-14 B004 UID0003SR callback:
  - What existed before: `86/89`, reconstructable/emitting custom node-vector hypothesis with blank C++ and descriptive type-name caveat.
  - Changed to: `90/94`, false/non-emitting documentation facade over `std::vector<WorldMapNode>`, retaining all exact 0x94-byte layout, allocation, caller, assign, destructor, and free evidence.
  - Summary/evidence: three-pointer layout, standard growth/maximum/aligned-allocation branches, repeated-value assign semantics, ordinary destructor cleanup, and UID0003SR `size()` arithmetic are compiler specialization evidence. Standard vector source/toolchain regenerates the bodies.

- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the node-entry vector destructor, assign helper, and free helper starts at `0x005c5510`, `0x005c58c0`, and `0x005c5a90`; the class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:74` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the private vector purpose, destructor/assign method mapping, 0x94 entry-size evidence, caller evidence from `WorldMapPane`, and final-name caveat.
- 2026-06-04: Raised completion from `74` to `84` and confidence from `76` to `88` after live IDA MCP verification.
  - Before: the page relied on a stale recovered-file path and did not show the disassembly evidence for record size, allocation policy, field layout, or caller population.
  - After: the page records exact destructor/assign/free-helper boundaries, vector field offsets, aligned large-allocation handling, two assign caller sites, caller-side 0x94 template setup and `_wcscpy_s` label copy, and multiple independent 0x94 stride/copy proofs inside the assign body.
  - Evidence: live IDA confirms `sub_5C5510`, `sub_5C58C0`, and `sub_5C5A90`; `CodeRefsTo(0x005c5510)` includes `0x005c33eb` and `0x0060bf1b`; `CodeRefsTo(0x005c58c0)` includes `0x005c2d4f` and `0x005c301b`. Scores remain below final reconstruction because the source-facing helper type name is still descriptive rather than recovered.
- 2026-06-16 B001 WorldMapPane executable split:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`; helper evidence was documented but exact by-memory child pages were missing.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:89`; added exact helper child links [UID:0003SZ][0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor](by-memory/0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor.md), [UID:0003T7][0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign](by-memory/0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign.md), and [UID:0003T8][0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation](by-memory/0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation.md).
  - Summary/evidence: B001 confirmed helper boundaries, constructor/destructor caller context, 0x94-byte node-entry stride, and private placement inside `WorldMapPane.cpp`; confidence remains below final source quality because the original helper type name is descriptive.
