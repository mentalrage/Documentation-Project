*** UID:0000FD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UInt32Vector

## Status

- Disposition: synthetic 12-byte binary-layout documentation overlay for a Visual C++ `std::vector<unsigned int>` header, not a recovered product class.
- Semantic index: [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), itself a non-standalone path-`NONE` documentation root.
- Source artifact: none. No `UInt32Vector.cpp`, class declaration, compatibility template, marker, or generated class file is source-authentic.
- Main documented function: [UID:0001B2][0x00514a10-0x00514ab7.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab7.UInt32VectorConstructor.md)
- Metadata: `91/94`, owner [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), `RECONSTRUCTABLE:FALSE`, blank emitter, blank CPP/H. The owner records semantic indexing only and does not create an emission chain.

## Physical Layout And Source Consequence

The binary overlay contains exactly three four-byte fields: `begin` at `+0x00`, `end`/current at `+0x04`, and `capacityEnd`/end-of-storage at `+0x08`, for total size `0x0c`. These descriptive field names document the ABI observed in constructors, copies, growth, fills, and destruction; they are not proof of a user-authored `UInt32Vector` UDT.

Final source should use the real caller-owned `std::vector<unsigned int>` or evidenced project typedef. That ordinary declaration naturally carries the three-pointer release-layout consequence under the selected MSVC/Dinkumware implementation. The compiler-covered exact children remain separately documented for binary fidelity, but neither this overlay nor those physical helper bodies emit source.

## Class Purpose

`UInt32Vector` is a documentation/helper bucket for `std::vector<unsigned int>`-style contiguous `uint32_t` storage support. Its main exact child is the out-of-line fill-constructor body that allocates `count` dwords, sets `begin/end/capacityEnd`, and fills every element from the supplied value pointer. The bucket name is not proof that the original source had a standalone product `UInt32Vector.cpp` class.

## Method Notes

| Address | Method | Role |
| --- | --- | --- |
| `0x00514a10` | fill constructor compiler lowering | Allocates `count` dwords and fills them with one `uint32_t` value. [UID:0001B2][0x00514a10-0x00514ab7.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab7.UInt32VectorConstructor.md) is exact, compiler-covered, and non-emitting; typed MapPane/WorldMapPane vector source owns the behavior. |
| `0x00420de0` | shared 4-byte value/pointer-slot grow-insert helper | Older reports classified this as a `UInt32Vector` insert helper; the newer fitting-room helper-island page and B010 reanalysis show it is generic 4-byte vector/template support with fitting-room integer, fitting-room pointer, and non-fitting-room `NewHumanImageLib` integer callers. |
| `0x00421290` | pointer-vector copy helper | Older reports classified this as a `UInt32Vector` family helper; current evidence shows three-pointer vector-header copy/construct behavior with mixed callers. |
| `0x00437710-0x00437869` | [UID:00050O][0x00437710-0x00437869.Vector4ByteGrowInsertCompilerSupport](by-memory/0x00437710-0x00437869.Vector4ByteGrowInsertCompilerSupport.md) | Exact `0x159`-byte body inserts one dword/four-byte slot, grows capacity, preserves prefix/suffix with `memmove`, handles 32-byte-aligned large allocations, frees old storage, and returns the inserted address. Seventeen callers span JsonCpp, MiniMap, DAT, and MapPane, proving shared compiler support rather than a `UInt32Vector` method. |

## Ownership Notes

IDA caller checks for the fill constructor show calls from `MapPane::HandleObjectCreatePacket` and `WorldMapPane::BuildReachabilityData`. Keep this as shared vector support; the feature files own the algorithms that consume the temporary bitsets.

[UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) is now a path-`NONE`, non-emitting semantic index. Earlier `util/VectorHelpers.h` and generated-class projections are superseded historical assumptions. This page remains linked to that index for discoverability while its blank emitter prevents a source route.

The semantic owner is [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md). Exact child [UID:0001B2][0x00514a10-0x00514ab7.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab7.UInt32VectorConstructor.md) remains shared `std::vector<unsigned int>` fill-constructor evidence, but the current whole-file audit supersedes B006's marker route: blank/no-emitter reclassification is accepted, while standalone class source, direct feature ownership, and a decompiler-shaped constructor remain rejected.

## Evidence Notes

- [UID:0001B2][0x00514a10-0x00514ab7.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab7.UInt32VectorConstructor.md) records the exact `0xa7` byte constructor, caller xrefs from `0x00511db0` and `0x005c4bd0`, and the fill behavior over contiguous dword storage.
- [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md), and their memory pages all treat this as temporary dword-vector/bitset support consumed by map/world-map algorithms.
- [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md) refines earlier `UInt32Vector` helper classifications: `0x00420de0` is shared 4-byte value/pointer-slot grow-insert support used by integer/enumeration and pointer callers, while `0x00421290` is shared pointer-vector copy support. These helpers are not proof of a clean standalone `UInt32Vector.cpp`.
- 2026-06-10 IDA MCP recheck:
  - `lookup_funcs` reports `sub_514A10` at `0x00514a10-0x00514ab7` and `sub_437710` at `0x00437710-0x00437869`.
  - `callers 0x00514a10` returns two call sites inside `sub_511DB0` at `0x00511f00` and `sub_5C4BD0` at `0x005c4df3`, matching map/world-map temporary vector consumers.
  - `decompile 0x00514a10` confirms the three-pointer vector header clear, overflow guard at `0x3fffffff`, small/large allocation split at 0x1000 bytes, 0x20-aligned large allocation with stored raw pointer, fill loop from `*a3`, and end/capacity pointer updates.
  - `callers 0x00437710` returns 16 call sites from `sub_428D70`, `sub_4523D0`, `sub_49C800`, and `sub_50B2B0`, proving the insert helper is shared across JsonCpp/MiniMap/dialog/map paths instead of being a clean `UInt32Vector`-only method.
  - `decompile 0x00437710` confirms a 4-byte-element vector insert/grow helper with 1.5x capacity growth, prefix/suffix `memmove`, old-storage free via `0x005c7526`, and the same large-allocation validation pattern as the fill constructor.
- 2026-06-12 A003 Batch 242 live IDA MCP reconfirmed `sub_514A10` as `0x00514a10-0x00514ab7`, calls from `sub_511DB0` at `0x00511f00` and `sub_5C4BD0` at `0x005c4df3`, callees `operator new`, `sub_421500`, and `__invalid_parameter_noinfo_noreturn`, plus decompiled three-header-pointer zeroing, `count > 0x3fffffff` guard, small vs large allocation split at `0x1000` bytes, 0x20-aligned large allocation with saved raw pointer, fill loop from `*fillValue`, and final end/capacity pointer updates.
- 2026-06-28 B006 source-quality implementation for [UID:0001B2][0x00514a10-0x00514ab7.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab7.UInt32VectorConstructor.md) rechecked current MCP session `b009_0001Q4_20260628`: `sub_514A10` remains a `0xa7` / 167-byte function (Verified with `tools/int_convert.py`), incoming code xrefs remain exactly `0x00511f00` and `0x005c4df3`, callees remain `operator new`, [UID:0002E1][0x00421500-0x0042151a.MsvcVectorThrowHelpers](by-memory/0x00421500-0x0042151a.MsvcVectorThrowHelpers.md), and `__invalid_parameter_noinfo_noreturn`, and the disassembly shows `retn 0Ch` with an unused allocator-like third stack argument. This supports a `std::vector<unsigned int>` / `uint32_t` fill-constructor-template interpretation rather than a hand-authored two-argument `UInt32Vector` class constructor.

## Autogen Status

- Reconstructable: false. This page is a synthetic layout/index, not an original source class.
- Parent/index: [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), with no emitter route.
- Code: CPP and H are intentionally blank. Exact helper behavior is compiler-covered; typed caller-owned container source replaces both a class body and marker-only output.

## Score Rationale

- Completion is `91` because the exact 12-byte physical layout, constructor behavior, helper-family boundaries, caller/callee evidence, corrected endpoint, source-level standard-container consequence, semantic owner, no-emitter metadata, and independent CPP/H dispositions are resolved.
- Confidence is `94` because the fill constructor and generic four-byte helper families are corroborated across exact by-memory pages, caller modules, and live IDA evidence, while negative evidence rejects a product class/header/source artifact.
- Exact original typedef spelling remains unknown, but finalized source should infer the most plausible human-written typed container rather than retain `UInt32Vector` as an invented class.

## Cross-References

- [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md)
- [UID:0001B2][0x00514a10-0x00514ab7.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab7.UInt32VectorConstructor.md)
- [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-08-13 UID0000P3 accepted implementation callback:
  - Reclassified the synthetic overlay from `85/87`, reconstructable, emitter `0000P3` to `91/94`, `RECONSTRUCTABLE:FALSE`, blank emitter, and blank CPP/H.
  - Documented the exact `0x0c` begin/end/capacityEnd layout, typed caller-owned `std::vector<unsigned int>` source consequence, UID0001B2 exact `...ab7` endpoint, and UID00050O's full shared-helper split.
  - Superseded earlier generated `class_UInt32Vector.cpp`, `VectorHelpers.h`, compatibility-template, marker, and no-emitter-rejection assumptions while preserving them below as historical development.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:70` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the fill-constructor behavior, documented helper addresses, caller checks, and shared vector-support placement; score remains limited because only the constructor is strongly detailed here while the helper family still relies on earlier by-memory classification.
- 2026-06-02: Raised to `76/82`, marked reconstructable, and added source-structure, helper-island, and scoring rationale evidence. Parent remains blank because `VectorHelpers` is still provisional and below the child-attachment confidence threshold.
- 2026-06-02: Attached parent [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) after that file reached `82` confidence and a valid `NexusTK/util/` projection. C++ remains blank because final template/header shape is unresolved.
- 2026-06-10 strict-gate and helper recheck:
  - What existed before: the page was scored `76/82`, attached to [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), and still treated `0x00437710` as an unresolved older helper classification.
  - Changed to: raised the page to `82/86`, cleared `AUTOGEN_PARENT_UID` under the strict 85/85 gate, and documented live IDA evidence for both `0x00514a10` and `0x00437710`.
  - Summary/evidence: IDA MCP confirms the fill constructor, two map/world-map constructor callers, the 16-call-site shared dword insert helper, allocation/free/growth behavior, and why `VectorHelpers` remains the intended semantic owner even though validator attachment is withheld.
- 2026-06-12 A003 Batch 242 parent-gate repair:
  - Before: `82/86`, `AUTOGEN_PARENT_UID:` blank, and exact constructor child parentless because this class did not clear the strict child/direct-parent gate.
  - Changed to: `85/87`, `AUTOGEN_PARENT_UID:0000P3`, while keeping final C++ blank.
  - Summary/evidence: live IDA MCP reconfirmed the exact fill-constructor boundary, map/world-map callers, allocation guards, small/large allocation paths, fill loop, and pointer updates; [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) already clears `86/86`, so class and direct file parent now meet the strict gate.
- 2026-06-21 supervisor Rule 26/B010 source-quality incorporation: Updated the `0x00420de0` note to demote the historical `UInt32Vector_Insert_420DE0` alias. The helper is now documented as shared 4-byte value/pointer-slot grow-insert support with fitting-room integer, fitting-room pointer, and non-fitting-room `NewHumanImageLib` integer callers, so it should remain under [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) rather than this class as a concrete method.
- 2026-06-28 Agent-B006 implementation callback for accepted [UID:0001B2][0x00514a10-0x00514ab7.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab7.UInt32VectorConstructor.md) empty-emitter source-quality report: clarified that `UInt32Vector` is a documentation/helper bucket for `std::vector<unsigned int>`-style support, not proof of a standalone product class file. The exact child now carries a source-disposition marker; metadata and class-level formal C++ remain unchanged.
