*** UID:0000G8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WorldMapNodeEntryVector

## Status

- Confidence: strong for helper behavior, exact method boundaries, caller context, 0x94-byte element size, and allocation/free policy; medium only for final original type name.
- Likely source file: [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- Address range: [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)
- Evidence basis: live IDA MCP disassembly/decompilation on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Class Purpose

`WorldMapNodeEntryVector` is private storage for 0x94-byte world-map node records copied from the world-map packet. It owns a dynamically allocated buffer and preserves the binary's aligned large-allocation behavior.

The vector object is a three-pointer layout: begin at `+0x00`, current/end at `+0x04`, and capacity end at `+0x08`. Its record payload starts with two copied dwords, then a wide label copied to record offset `+0x08` with `_wcscpy_s(..., 0x40, ...)` in the caller.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~WorldMapNodeEntryVector` | `0x005c5510-0x005c557a` | Releases the node-entry buffer, handles aligned large allocations, and clears begin/current/capacity pointers. |
| `Assign` | `0x005c58c0-0x005c5a8f` | Assigns repeated 0x94-byte node-entry values across the vector, growing storage when needed. |
| free helper | `0x005c5a90-0x005c5aca` | Frees an existing node-entry allocation, including large-allocation raw-pointer recovery. |

## Evidence Notes

- Live IDA confirms `sub_5C5510` as `0x005c5510-0x005c557a`. The destructor reads begin/current/capacity from `this+0/+4/+8`; when the backing allocation is at least `0x1000` bytes it recovers the raw allocation pointer from `[begin-4]`, validates the aligned-pointer delta is at most `0x1f`, frees through `sub_5C7526`, and zeroes all three vector fields.
- `CodeRefsTo(0x005c5510)` reports the main destructor call at `0x005c33eb` with `ecx = this + 0x258`, plus cleanup funclet jump `0x0060bf1b` with the same `+0x258` offset.
- Live IDA confirms `sub_5C58C0` as `0x005c58c0-0x005c5a8f`. It divides pointer differences by `148`, grows capacity by roughly 1.5x when needed, clamps through the `0x1bacf91` maximum, allocates `count * 0x94` bytes, uses 32-byte aligned storage for allocations at least `0x1000` bytes, and fills entries with `qmemcpy(..., 0x94)`.
- The assign body proves the 0x94-byte record size independently: allocation uses `imul ..., 0x94`, pointer increments add `0x94`, and the copy loop uses `rep movsd` with count `0x25`.
- `CodeRefsTo(0x005c58c0)` reports two calls inside `WorldMapPane` construction/packet setup at `0x005c2d4f` and `0x005c301b`. Both caller paths `memset` a 0x94-byte stack template, pass the signed packet count, call the vector assign helper, then populate each allocated node record and copy the display label through `_wcscpy_s` with `0x40` wide characters.
- Treat the class name as descriptive until original type names are recovered.

## Cross-References

- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md)
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:74` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the private vector purpose, destructor/assign method mapping, 0x94 entry-size evidence, caller evidence from `WorldMapPane`, and final-name caveat.
- 2026-06-04: Raised completion from `74` to `84` and confidence from `76` to `88` after live IDA MCP verification.
  - Before: the page relied on a stale recovered-file path and did not show the disassembly evidence for record size, allocation policy, field layout, or caller population.
  - After: the page records exact destructor/assign/free-helper boundaries, vector field offsets, aligned large-allocation handling, two assign caller sites, caller-side 0x94 template setup and `_wcscpy_s` label copy, and multiple independent 0x94 stride/copy proofs inside the assign body.
  - Evidence: live IDA confirms `sub_5C5510`, `sub_5C58C0`, and `sub_5C5A90`; `CodeRefsTo(0x005c5510)` includes `0x005c33eb` and `0x0060bf1b`; `CodeRefsTo(0x005c58c0)` includes `0x005c2d4f` and `0x005c301b`. Scores remain below final reconstruction because the source-facing helper type name is still descriptive rather than recovered.
