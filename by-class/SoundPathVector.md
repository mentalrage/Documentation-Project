*** UID:0000DI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SoundPathVector

## Status

- Confidence: final-audit quality for the three-pointer ABI, ANSI StringBase element type, exact helper ranges/callers, and old-MSVC `std::vector` source cause; exact original typedef spelling remains an explicitly inferred naming detail.
- Source placement: no standalone custom class source. The bodies are compiler/STL instantiations caused by typed container use in [UID:0000NV][SoundManager](by-file/SoundManager.md).
- Main address doc: [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md)
- Rebuild handling: non-reconstructable, non-emitting documentation projection for compiler-generated `std::vector<SoundPathString>` implementation bodies. Keep this class declaration/formal C++ and all vector exact-child bodies blank. Human source belongs in typed SoundManager methods such as source-ready UID0001IA. UID0004FM is excluded from this compiler-only set and routes through StringBaseTemplate.

## Class Purpose

`SoundPathVector` is retained as a convenient documentation name for the binary's three-pointer old-MSVC `std::vector<SoundPathString>` instantiations used by [UID:0000DG][SoundManager](by-class/SoundManager.md). It is not a source-authored NexusTK class. `SoundPathString` is the inferred local alias for ANSI `mystr::StringBase<char, mystr::mychar_traits<char> >`; the layout and element family are proven even though the exact typedef spelling is not.

Historical projections `SoundManagerList_57BAC0`, `ScanMusicDirectoryHelper_57BD90`, and the later custom `SoundPathVector` method model remain useful search provenance. Current reconstruction emits standard container operations from consumer source and does not create `SoundPathVector.cpp` or a custom declaration.

## Layout Notes

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `m_begin` | Start pointer for contiguous path-entry storage. |
| `0x04` | `m_end` | One-past-last path entry. |
| `0x08` | `m_capacity` | One-past-capacity path entry. |

Older docs modeled entries as `LObject`, but current StringBase and [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) evidence resolves the clear path to four-byte ANSI `StringBase` path-string entries. Keep only the final public typedef/header spelling provisional; do not treat the target child as blocked by generic `LObject` terminology.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:0004FJ][0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert](by-memory/0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert.md) | `0x0057b860-0x0057b99a` | Compiler `std::vector` push/insert slow path: exact 1.5x growth, append/middle branches, StringBase construction, commit, cleanup/free/rethrow, and three SoundManager callers. Non-emitting. |
| [UID:0004FK][0x0057bac0-0x0057bb2a.SoundPathVectorDestructor](by-memory/0x0057bac0-0x0057bb2a.SoundPathVectorDestructor.md) | `0x0057bac0-0x0057bb2a` | Compiler vector destructor lowering for automatic/member vectors: destroys `[begin,end)`, frees storage, zeroes the triplet, and has five normal plus EH callers. Non-emitting. |
| [UID:0004FL][0x0057bd90-0x0057be52.SoundPathVectorReallocate](by-memory/0x0057bd90-0x0057be52.SoundPathVectorReallocate.md) | `0x0057bd90-0x0057be52` | Compiler `std::vector::reserve` reallocation lowering used once by UID0001IA at `0x0057aea5`; preserves exact allocator/copy/commit/cleanup/free behavior. Non-emitting. |
| [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) | `0x0057bf40-0x0057bf6e` | Compiler `std::vector::clear` lowering for `m_zoneMusicTracks.clear()` at callers `0x00579f9a` and `0x0057a214`. Non-emitting. |
| [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md) | `0x0057bc60-0x0057bcdc` | Source-authored StringBase lowercase-copy member template instantiation, not vector support; source in `ecx`, hidden result on stack, copy/detach/lowercase/return behavior. Owned/emitted through UID0001WS. |
| [UID:0004FN][0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage](by-memory/0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage.md)-[UID:0004FO][0x0057bd60-0x0057bd84.SoundPathStringDestroyRange](by-memory/0x0057bd60-0x0057bd84.SoundPathStringDestroyRange.md) | `0x0057bce0-0x0057bd84` | Compiler vector storage commit plus EH destroy-range support; exact old-entry destruction, large-allocation free, triplet replacement, and cleanup-only caller evidence retained. Both non-emitting. |
| [UID:0004FP][0x0057be60-0x0057becf.SoundPathStringCopyConstructRange](by-memory/0x0057be60-0x0057becf.SoundPathStringCopyConstructRange.md) | `0x0057be60-0x0057becf` | Compiler uninitialized-copy helper for grow/insert with partial-destination cleanup on exception. Non-emitting. |
| [UID:0004FQ][0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail](by-memory/0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail.md) | `0x0057bed0-0x0057bf3e` | Compiler append-copy tail support used only by grow/insert; exact return, padding, caller, StringBase callee, and EH evidence retained. Non-emitting. |

## Current Standard-Container Disposition

The direct source cause is typed `std::vector<SoundPathString>` use in SoundManager methods. `0x00421500` reaches the literal `vector<T> too long`; the helper island has the old Dinkumware three-pointer layout, 1.5x growth, reserve, uninitialized copy, range destruction, storage commit, erase shift, clear, and automatic cleanup patterns. These converging traits supersede the custom-class interpretation.

UID0001IA emits the scanner's `clear`, deque queue, `push_back`, `reserve`, random erase, and swap operations. Music-selection methods emit the `m_zoneMusicTracks` operations. The compiler regenerates this island; custom methods would duplicate compiler output and distort likely original source.

## 2026-06-11 Caller Refresh

Live IDA MCP Batch190 checks reconfirm the helper family as audio-local SoundManager path-vector code:

- `lookup_funcs` reports `0x0057b860` size `0x13a`, `0x0057bac0` size `0x6a`, `0x0057bd90` size `0xc2`, and `0x0057bf40` size `0x2e`; the half-open end addresses `0x0057b99a`, `0x0057bb2a`, `0x0057be52`, and `0x0057bf6e` are not function starts.
- `GrowAndInsert` callers are `0x005798e9` in `SoundManager::LoadTrackListFromFile` and `0x0057acab`/`0x0057aef5` in the local music-directory scan.
- The destructor callers are `0x00579d8c`/`0x00579d97` in SoundManager construction/setup, `0x0057afa6` in the directory scan, and `0x0057bc0e`/`0x0057bc19` in the SoundManager deleting-destructor path.
- `Reallocate` has the single checked caller `0x0057aea5` in the directory scan.
- [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) has only `0x00579f9a` and `0x0057a214` callers from SoundManager music selection.

B004's 2026-06-27 accepted support pass on MCP session `80de0a67` rechecked the same direct-owner split while implementing the parent UID0001I8 non-emitting index disposition:

- `0x57b860` decompiles as the three-pointer grow/insert helper that allocates a 1.5x buffer, constructs/copies entries, and updates begin/end/capacity through `0x57bce0`; callers remain `0x5798e9`, `0x57acab`, and `0x57aef5`.
- `0x57bd90` reserves/reallocates the vector buffer, copies existing entries, and updates the triplet through `0x57bce0`; its checked caller remains `0x57aea5` in directory scanning.
- `0x57bf40` clears entries by calling `sub_582B30` over `[begin,end)` and then setting `end = begin`; checked callers remain `0x579f9a` and `0x57a214`, both clearing the `SoundManager +0x109c` vector.
- The raw `0x57b9b0-0x57b9d1` entry-destroying body is interleaved between `0x57b9a0-0x57b9ab` singleton clear and the modeled Deque cleanup at `0x57b9e0`; it explains the helper island but does not move direct ownership of this class to the broad SoundManager aggregate.

## Historical 2026-06-28 Clear Source-Ready Update

B013's accepted report rechecked the exact clear helper and historically promoted it as a custom source method. The exact body facts below remain valid, but UID0001IA's later standard-container audit supersedes only that source/emitter classification:

- `0x0057bf40` is an exact `0x2e` body with two `0xcc` padding bytes before `0x0057bf70`.
- The only callers are `0x00579f9a` in `PlayTrackByIndex`-style logic and `0x0057a214` in `PlayMusicByZone`-style logic; both pass `SoundManager +0x109c` and clear `m_zonePlaylistActive` for direct `%08d.MP3` fallback.
- The only target callee is `0x00582b30`, which forwards to `0x005832f0` / ANSI `StringBase` release. The clear method should therefore destroy `SoundPathString` elements, not inline `ReleaseAnsiBuffer()` and not call a raw `sub_582B30` helper in source.
- [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) now carries first-draft formal `void SoundPathVector::Clear()` C++. The destructor child now carries first-draft formal `SoundPathVector::~SoundPathVector()` as well. This class page still keeps full class C++ blank because remaining grow/reallocate declarations, broader helper integration, and original typedef/header spelling are not fully audited.

## Historical 2026-07-03 B005 Split-First Update

B005's accepted UID0001ID implementation created the exact split/index and child boundaries. Its then-current custom-source promotions are historical; the ranges, callers, callees, EH, padding, and allocation/string facts remain accepted evidence:

- [UID:0004FJ][0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert](by-memory/0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert.md) has callers `0x005798e9`, `0x0057acab`, and `0x0057aef5`. B007's accepted evidence pass on then-active `fef9a7c2` keeps this exact child non-emitting at `87/91`; current supervisor-verified live MCP session for future UID0004FJ checks is `6a4af54d`. Layout and `SoundPathString` names are accepted, but source-safe output still needs the integrated allocator/free contract, append-tail copy strategy, partial-destroy bounds, storage-replacement/copy/destroy helper contracts as used together, and EH cleanup source shape.
- [UID:0004FK][0x0057bac0-0x0057bb2a.SoundPathVectorDestructor](by-memory/0x0057bac0-0x0057bb2a.SoundPathVectorDestructor.md) has callers `0x00579d8c`, `0x00579d97`, `0x0057afa6`, `0x0057bc0e`, and `0x0057bc19`. B003's current `6a4af54d` callback proof resolves this exact child as source-ready: exact range `0x0057bac0-0x0057bb2a`, size `0x6a`, padding `0x0057bab5-0x0057bac0` and `0x0057bb2a-0x0057bb30`, entry destruction through `0x00582b30 -> 0x005832f0`, storage free through `0x005c7526`, triplet reset, EH/unwind refs at `0x00608332`/`0x00608340`/`0x00608407`, and rejected raw/SoundManager/parent-aggregate/generic-StringBase routes.
- [UID:0004FL][0x0057bd90-0x0057be52.SoundPathVectorReallocate](by-memory/0x0057bd90-0x0057be52.SoundPathVectorReallocate.md) has caller `0x0057aea5`. B010's accepted current-session `aa3930bd` callback resolves the prior allocator/copy-failure blocker and promotes the child to source-ready `SoundPathVector::Reallocate(int newCapacity)`: exact range `0x0057bd90-0x0057be52`, size `0xc2`, allocator `0x00421520`, copy constructor `0x005829f0`, commit call `0x0057be1b` to UID0004FN `ChangeArray()`, cleanup xref `0x006085f3 -> 0x0057b9b0`, free wrapper `0x00423e00`, rejected direct SoundManager/generic-container/aggregate/raw-label routes, and inferred allocator/free helper spellings as confidence caps.
- Exact children [UID:0004FK][0x0057bac0-0x0057bb2a.SoundPathVectorDestructor](by-memory/0x0057bac0-0x0057bb2a.SoundPathVectorDestructor.md), [UID:0004FL][0x0057bd90-0x0057be52.SoundPathVectorReallocate](by-memory/0x0057bd90-0x0057be52.SoundPathVectorReallocate.md), [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md), [UID:0004FN][0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage](by-memory/0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage.md), [UID:0004FP][0x0057be60-0x0057becf.SoundPathStringCopyConstructRange](by-memory/0x0057be60-0x0057becf.SoundPathStringCopyConstructRange.md), and existing [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) now have exact source-ready child bodies; [UID:0004FO][0x0057bd60-0x0057bd84.SoundPathStringDestroyRange](by-memory/0x0057bd60-0x0057bd84.SoundPathStringDestroyRange.md) and [UID:0004FQ][0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail](by-memory/0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail.md) remain separate blank-emitter children.
- Raw `0x0057b9b0-0x0057b9d1` remains excluded from emitted class code because no safe entry/source-owner route is proven; SoundManager scalar deleting destructor glue at `0x0057bb30-0x0057bc59` is compiler/lifetime evidence, not a SoundPathVector method.

## SoundManager Relationships

- [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md) confirms the contiguous three-pointer helper island, the grow/destructor/reallocate/clear method family, the clean `0x0057bf6e-0x0057bf70` padding boundary before SoundStatusPane, and delegated deque cleanup that should stay outside this class.
- [UID:0001IA][0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan](by-memory/0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan.md) proves the `+0x1028` container's scanner operations and is the source-emitting policy owner.
- [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md) remains source-ready, but as a StringBase template-member instantiation owned by UID0001WS rather than this grouping.
- UID0004FK and UID0001IF retain exact destruction/clear caller, offset, StringBase-release, padding, and EH evidence as non-emitting compiler vector bodies.
- [UID:0000NV][SoundManager](by-file/SoundManager.md) and [UID:0000DG][SoundManager](by-class/SoundManager.md) own the consumer source/file and policy state; UID0001I8 contains the island only as a non-emitting address index.

## Boundary Caveats

IDA MCP recheck on 2026-05-25 confirms the end-exclusive boundaries: `GrowAndInsert` is `0x0057b860-0x0057b99a`, `Reallocate` is `0x0057bd90-0x0057be52`, and `Clear` is `0x0057bf40-0x0057bf6e`. Active generated metadata still uses shorter Ghidra-sized method ends for the first two methods.

2026-05-26 generated `class_SoundPathVector.cpp` and later custom child bodies are historical source-shape leads only. Current metadata intentionally removes the custom class and all compiler-vector child output; validators regenerate `SoundManager.cpp` from the consumer methods instead.

The adjacent `DequeDestroyOwnedEntries` helper is a delegated cleanup dependency, not a SoundPathVector method. Keep it excluded unless broader class evidence shows the deque helper belongs in this class.

## Score Rationale

Completion is `91` because the page preserves the complete exact child inventory, layout, SoundManager offsets, callers, allocation/copy/destruction/commit/clear behavior, EH and padding facts, and historical custom-class decisions, then resolves the source category to compiler-generated standard-vector code. Confidence is `95` because the `vector<T> too long` literal and full helper morphology converge with the three-pointer ABI and typed consumer operations; exact typedef spelling does not alter the no-custom-class decision. `RECONSTRUCTABLE:FALSE`, blank emitter, and blank formal C++ are final for this documentation projection.

## Cross-References

- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md)
- [UID:0004FJ][0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert](by-memory/0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert.md)
- [UID:0004FK][0x0057bac0-0x0057bb2a.SoundPathVectorDestructor](by-memory/0x0057bac0-0x0057bb2a.SoundPathVectorDestructor.md)
- [UID:0004FL][0x0057bd90-0x0057be52.SoundPathVectorReallocate](by-memory/0x0057bd90-0x0057be52.SoundPathVectorReallocate.md)
- [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md)
- [UID:0004FN][0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage](by-memory/0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage.md)
- [UID:0004FO][0x0057bd60-0x0057bd84.SoundPathStringDestroyRange](by-memory/0x0057bd60-0x0057bd84.SoundPathStringDestroyRange.md)
- [UID:0004FP][0x0057be60-0x0057becf.SoundPathStringCopyConstructRange](by-memory/0x0057be60-0x0057becf.SoundPathStringCopyConstructRange.md)
- [UID:0004FQ][0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail](by-memory/0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail.md)
- [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md)
- [UID:0001IA][0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan](by-memory/0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan.md)
- [UID:0001Q8][client_audio](by-meta/client_audio.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `78`.
- Evidence: the page documents vector role, layout, main helper methods, exact IDA boundary caveats, clear-helper ownership, and SoundManager use; confidence remains capped by provisional element type and exact original placement.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the path-vector grow, destructor, reallocate, and clear anchors at `0x0057b860`, `0x0057bac0`, `0x0057bd90`, and `0x0057bf40`. The helper is NexusTK-owned audio container code, but class confidence is `78`, so the parent UID stays blank until the 80/80 gate is met.
- 2026-06-06 A001: Raised to completion `84`, confidence `82`, and attached parent [UID:0000NV][SoundManager](by-file/SoundManager.md).
- Evidence: existing IDA-backed SoundManager, SoundPathVector, SoundPathVectorClear, and SoundManagerMusicDirectoryScan docs confirm the three-pointer layout, `+0x1028` and `+0x109c` SoundManager relationships, grow/destructor/reallocate/clear method family, deque-helper exclusion, and parent SoundManager source placement. This historical class-page C++ gate is superseded for exact child [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md), whose current evidence supports emitted `SoundPathVector::Clear()` source; the aggregate class page itself remains non-emitting because the other vector methods still need separate exact-source closure.
- 2026-06-11 A002 Batch190: Raised from `84/82` to `85/86` after live IDA MCP reconfirmed the four method boundaries and audio-local caller sets for grow/insert, destructor, reallocate, and clear.
  - Evidence: `lookup_funcs`, `callers`, and `callees` show the family is used by SoundManager playlist loading, music-directory scanning, music selection, and SoundManager destructor/setup paths, with no non-audio callers found in the checked set.
- 2026-06-13 C001 Goal 2 barrier repair:
  - Score unchanged at `85/86`.
  - Evidence: live IDA MCP confirmed the `SoundPathVector` memory aggregate is now contained by corrected SoundManager audio aggregate ranges and can attach directly to this class under the strict gate; no class layout or final element-type claims were changed.
- 2026-06-27 B004 support sync:
  - Score unchanged at `85/86`.
  - Evidence: live MCP session `80de0a67` reconfirmed `GrowAndInsert`, `Reallocate`, `Clear`, and raw `0x57b9b0` helper roles while implementing UID0001I8 as a non-emitting index. The broad SoundManager aggregate contains this range for address coverage, but direct ownership and any future C++ remain with `SoundPathVector` or exact child pages.
- 2026-06-28 B013 [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) implementation support:
  - Score unchanged at `85/86`.
  - Evidence: incorporated accepted current MCP session `supervisor_20260628_resume` proof that `SoundPathVector::Clear()` is source-ready as an exact child: exact `0x2e` body, caller pair `0x00579f9a`/`0x0057a214`, SoundManager `+0x109c` route, `m_zonePlaylistActive` clear, `0x00582b30 -> 0x005832f0` ANSI `StringBase` release semantics, and first-draft child C++. Class-level formal C++ remains blank for remaining helper/source-shape questions.
- 2026-07-03 B005 UID0001ID split-first implementation:
  - Score unchanged at `85/86`.
  - Evidence: incorporated accepted MCP session `c9ac3d5b` support for exact child pages [UID:0004FJ][0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert](by-memory/0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert.md), [UID:0004FK][0x0057bac0-0x0057bb2a.SoundPathVectorDestructor](by-memory/0x0057bac0-0x0057bb2a.SoundPathVectorDestructor.md), [UID:0004FL][0x0057bd90-0x0057be52.SoundPathVectorReallocate](by-memory/0x0057bd90-0x0057be52.SoundPathVectorReallocate.md), and helper-tail pages [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md), [UID:0004FN][0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage](by-memory/0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage.md), [UID:0004FO][0x0057bd60-0x0057bd84.SoundPathStringDestroyRange](by-memory/0x0057bd60-0x0057bd84.SoundPathStringDestroyRange.md), [UID:0004FP][0x0057be60-0x0057becf.SoundPathStringCopyConstructRange](by-memory/0x0057be60-0x0057becf.SoundPathStringCopyConstructRange.md), and [UID:0004FQ][0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail](by-memory/0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail.md). Broad UID0001ID is now a non-emitting index; at split creation those child emitters were blank with target-specific no-code proofs until final names/contracts were safe. Later accepted child passes promoted UID0004FK, UID0004FM, UID0004FN, UID0004FP, and UID0001IF to source-ready output while preserving other child-specific no-code decisions. B006's accepted UID0004FQ pass later corrected that child range to `0x0057bed0-0x0057bf3e`.
- 2026-07-03 B003 UID0004FM implementation support:
  - Score unchanged at `85/86`.
  - Evidence: incorporated accepted current MCP session `fef9a7c2` proof that exact child [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md) is source-ready as `PrepareLowercaseSoundPathString(...)`: one caller from SoundManager directory scanning at `0x57abb5`, caller setup from `FindFileData.cFileName`, `.mp3` test immediately after the helper, StringBase share/copy construction at `0x005829f0`, detach-if-shared at `0x00583050`, header-length lookup at `0x00583450`, `_strlwr_s` lowercase call through `0x00582900`, exact `0x7c` body, and boundary padding at `0x0057bc59` and `0x0057bcdc-0x0057bce0`. The class page remains blank at aggregate declaration level because other child helpers still need their own source-shape passes.
- 2026-07-03 B005 UID0004FP implementation support:
  - Score unchanged at `85/86`.
  - Evidence: incorporated accepted current MCP session `fef9a7c2` proof that exact child [UID:0004FP][0x0057be60-0x0057becf.SoundPathStringCopyConstructRange](by-memory/0x0057be60-0x0057becf.SoundPathStringCopyConstructRange.md) is source-ready as `CopyConstructSoundPathStringRange(...)`: exact `0x70` / 112-byte body, two `GrowAndInsert` call sites at `0x57b933` and `0x57b946`, four-byte ANSI `SoundPathString` construction through `0x005829f0`, cleanup landing path `0x608620 -> 0x0057b9b0`, predecessor padding at `0x0057be52-0x0057be60`, and successor sibling `0x0057bed0`. Exact helper spelling, public typedef/header spelling, and source-template provenance remain confidence caps; [UID:0004FQ][0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail](by-memory/0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail.md) remains a separate non-emitting child after B006's accepted range/no-code pass.
- 2026-07-03 B006 UID0004FQ implementation support:
  - Score unchanged at `85/86`.
  - Evidence: incorporated accepted historical B006 MCP evidence from now-stale session `fef9a7c2` proving that UID0004FQ is a modeled `0x6e` / 110-byte range copy-construction tail helper at corrected half-open `0x0057bed0-0x0057bf3e`, with byte `0x0057bf3d` as the final `00` of `retn 0Ch`, two-byte padding before Clear at `0x0057bf3e-0x0057bf40`, only caller `0x0057b927` from `GrowAndInsert`, callee `0x005829f0`, and four-byte source/destination advancement. It remains blank-emitter/formal because the caller ignores the decompiler-shaped return value, EH cleanup uses raw `0x0057b9b0`, and original helper/source retention remains unresolved.
- 2026-07-03 B007 UID0004FJ implementation support:
  - Score unchanged at `85/86`.
  - Evidence: incorporated accepted historical B007 MCP evidence gathered while session `fef9a7c2` was active, proving that [UID:0004FJ][0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert](by-memory/0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert.md) is the exact `0x13a` grow/insert child with full-vector callers `0x005798e9`, `0x0057acab`, and `0x0057aef5`, max-size guard `0x3fffffff`, 1.5x capacity growth, inserted-element construction at `0x57b90a`, append branch through UID0004FQ, middle-insert branch through UID0004FP, storage commit through UID0004FN, cleanup through UID0004FO/free/rethrow, and padding `0x0057b99a-0x0057b9a0`. Current supervisor-verified live MCP session for any future UID0004FJ check is `6a4af54d`. UID0004FJ remains blank-emitter/formal because accepted field names exist but integrated allocator/copy/destroy/replace helper contracts and EH cleanup source shape are not final.
- 2026-07-03 B004 UID0004FO implementation support:
  - Score unchanged at `85/86`.
  - Evidence: incorporated accepted historical B004 MCP evidence gathered while session `fef9a7c2` was active, proving that [UID:0004FO][0x0057bd60-0x0057bd84.SoundPathStringDestroyRange](by-memory/0x0057bd60-0x0057bd84.SoundPathStringDestroyRange.md) is modeled `sub_57BD60`, size `0x24`, with `0x0057bd84` not a function; it destroys a half-open range of four-byte ANSI `SoundPathString` entries by calling `0x00582b30 -> 0x005832f0` StringBase release. The only code xref is `0x0057b979` in UID0004FJ `GrowAndInsert` EH cleanup/rethrow flow, with no xref to the end address and a non-unique range signature. It stays SoundPathVector-owned and blank-emitter/no standalone helper; rejected routes remain `Clear()`, raw `0x0057b9b0`, direct SoundManager ownership, StringBase ownership, public helper/API, and exact original helper-name proof. Current supervisor-verified live MCP session for any future UID0004FO check is `6a4af54d`.
- 2026-07-03 B008 UID0004FN implementation support:
  - Score unchanged at `85/86`.
  - Evidence: incorporated the accepted source-ready decision for exact child [UID:0004FN][0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage](by-memory/0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage.md). UID0004FN now emits first-draft `SoundPathVector::ChangeArray()` through this class route into [UID:0000NV][SoundManager](by-file/SoundManager.md): exact `0x73` body, callers `0x0057b952` in `GrowAndInsert` and `0x0057be1b` in `Reallocate`, old-entry destruction through the `SoundPathString` destructor wrapper, MSVC large-allocation base validation before free, and final `m_begin`/`m_end`/`m_capacity` triplet replacement. Exact original helper spelling and final class/header organization remain confidence caps; this class page still keeps aggregate declaration C++ blank for broader helper integration work.
- 2026-07-03 B003 UID0004FK implementation support:
  - Score unchanged at `85/86`; class-level formal C++ remains blank because only the exact child destructor, not the broader class declaration, was accepted for emission.
  - Evidence: incorporated accepted current MCP session `6a4af54d` proof that [UID:0004FK][0x0057bac0-0x0057bb2a.SoundPathVectorDestructor](by-memory/0x0057bac0-0x0057bb2a.SoundPathVectorDestructor.md) is source-ready `SoundPathVector::~SoundPathVector()`: exact `0x6a` / 106-byte body, padding `0x0057bab5-0x0057bac0` and `0x0057bb2a-0x0057bb30`, normal callers `0x00579d8c`/`0x00579d97`/`0x0057afa6`/`0x0057bc0e`/`0x0057bc19`, EH/unwind refs `0x00608332`/`0x00608340`/`0x00608407`, StringBase release through `0x00582b30 -> 0x005832f0`, storage free through `0x005c7526`, triplet zeroing, stale-session replacement, rejected raw/SoundManager/parent aggregate/StringBase ownership alternatives, and confidence caps for exact field, typedef/header, and storage-helper spelling.
- 2026-07-04 B010 UID0004FL implementation support:
  - Score unchanged at `85/86`; class-level formal C++ remains blank because only the exact child reallocate method, not the broader class declaration, was accepted for emission.
  - Evidence: incorporated accepted current MCP session `aa3930bd` proof that [UID:0004FL][0x0057bd90-0x0057be52.SoundPathVectorReallocate](by-memory/0x0057bd90-0x0057be52.SoundPathVectorReallocate.md) is source-ready `SoundPathVector::Reallocate(int newCapacity)`: exact `0xc2` body, one caller `0x0057aea5` in local music scanning, allocator helper `0x00421520`, copy constructor helper `0x005829f0`, commit call `0x0057be1b` to source-ready `ChangeArray()`, cleanup xref `0x006085f3 -> 0x0057b9b0`, free wrapper `0x00423e00`, generated pre-callback non-emitting state, and rejected direct SoundManager/parent aggregate/broad audio aggregate/generic container/raw-label/plain `operator new[]` routes. `AllocateSoundPathStringStorage` and `FreeSoundPathStringStorage` are inferred source-facing names; exact helper spelling and final typedef/header organization remain confidence caps.
- 2026-07-13 B004 UID0001IA standard-container reclassification:
  - Raised `85/86 -> 91/95`, changed `RECONSTRUCTABLE:TRUE -> FALSE`, cleared emitter UID0000NV, and retained a blank formal block.
  - Reclassified this page as a documentation projection for old-MSVC `std::vector<SoundPathString>` instantiations. All exact child ranges, callers, allocation/copy/destruction/commit/clear, EH, padding, and historical custom-emitter decisions remain documented; only the current source category/output changes.
  - Moved UID0004FM source ownership to StringBaseTemplate UID0001WS and kept typed SoundManager consumer methods as the source that regenerates the vector helper island.
