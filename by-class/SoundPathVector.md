*** UID:0000DI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SoundPathVector

## Status

- Confidence: strong for container behavior, method ownership, and SoundManager field use; medium-high for exact element type and original source split.
- Likely source file: [UID:0000NV][SoundManager](by-file/SoundManager.md), as an audio-private helper or local specialized vector.
- Main address doc: [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md)
- Rebuild handling: reconstructable helper attached to SoundManager because both parent and class now clear the 80/80 gate; final C++ remains blank until the exact element type and member names clear the 95/95 code gate.

## Class Purpose

`SoundPathVector` is a three-pointer vector for refcounted or object-backed audio path strings used by [UID:0000DG][SoundManager](by-class/SoundManager.md). It supports growing insertion, destruction, explicit reallocation, and clear/reset behavior for playlist entries, scanned local music paths, and track filename fallback state.

The class replaced older missing-reference projections such as `SoundManagerList_57BAC0` and `ScanMusicDirectoryHelper_57BD90`. It should stay with audio path-management code rather than move into a generic container module unless broader non-audio callers are found.

## Layout Notes

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `m_begin` | Start pointer for contiguous path-entry storage. |
| `0x04` | `m_end` | One-past-last path entry. |
| `0x08` | `m_capacity` | One-past-capacity path entry. |

Existing docs model entries as `LObject`, while SoundManager use indicates path-string semantics. Keep final element type provisional until the underlying `LObject`/string class is reconciled.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GrowAndInsert` | `0x0057b860-0x0057b99a` | Grows by 1.5x, copy-constructs entries around the insert position, destroys old storage, and returns inserted entry. |
| `~SoundPathVector` | `0x0057bac0-0x0057bb2a` | Destroys entries, frees aligned storage, clears the triplet. |
| `Reallocate` | `0x0057bd90-0x0057be52` | Allocates a new buffer of requested capacity, copy-constructs existing entries, destroys old storage, updates triplet. |
| [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) | `0x0057bf40-0x0057bf6e` | Destroys current entries and resets `end = begin`; used by SoundManager track filename vectors. |

## SoundManager Relationships

- [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md) confirms the contiguous three-pointer helper island, the grow/destructor/reallocate/clear method family, the clean `0x0057bf6e-0x0057bf70` padding boundary before SoundStatusPane, and delegated deque cleanup that should stay outside this class.
- [UID:0001IA][0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan](by-memory/0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan.md) ties the helper to SoundManager's `+0x1028` scanned local music path vector.
- [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) ties `Clear` callers at `0x00579f9a` and `0x0057a214` to the `+0x109c` track filename/direct fallback vector.
- [UID:0000NV][SoundManager](by-file/SoundManager.md) and [UID:0000DG][SoundManager](by-class/SoundManager.md) place this helper with audio manager state rather than a generic container module.

## Boundary Caveats

IDA MCP recheck on 2026-05-25 confirms the end-exclusive boundaries: `GrowAndInsert` is `0x0057b860-0x0057b99a`, `Reallocate` is `0x0057bd90-0x0057be52`, and `Clear` is `0x0057bf40-0x0057bf6e`. Active generated metadata still uses shorter Ghidra-sized method ends for the first two methods.

2026-05-26 recheck: current `class_SoundPathVector.cpp` still emits only `GrowAndInsert`, destructor, and `Reallocate`; the `0x0057bf40` clear helper still has no active `.cpp` body. IDA MCP callers still place `Clear` in SoundManager track-selection and zone-music fallback paths, so keep it with the audio path-vector helper family.

The adjacent `DequeDestroyOwnedEntries` helper is a delegated cleanup dependency, not a SoundPathVector method. Keep it excluded unless broader class evidence shows the deque helper belongs in this class.

## Score Rationale

Completion is raised to `84` because the page now records the layout, method family, SoundManager offsets, clear-call ownership, parent attachment, and exclusion boundary for the interleaved deque helper. Confidence is raised to `82` because the supporting by-memory and by-file pages agree on ownership and behavior; it remains below final-rewrite level because the exact element type, member names, and original source split are still unresolved.

## Cross-References

- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md)
- [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md)
- [UID:0001IA][0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan](by-memory/0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan.md)
- [UID:0001Q8][client_audio](by-meta/client_audio.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `78`.
- Evidence: the page documents vector role, layout, main helper methods, exact IDA boundary caveats, clear-helper ownership, and SoundManager use; confidence remains capped by provisional element type and exact original placement.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the path-vector grow, destructor, reallocate, and clear anchors at `0x0057b860`, `0x0057bac0`, `0x0057bd90`, and `0x0057bf40`. The helper is NexusTK-owned audio container code, but class confidence is `78`, so the parent UID stays blank until the 80/80 gate is met.
- 2026-06-06 A001: Raised to completion `84`, confidence `82`, and attached parent [UID:0000NV][SoundManager](by-file/SoundManager.md).
- Evidence: existing IDA-backed SoundManager, SoundPathVector, SoundPathVectorClear, and SoundManagerMusicDirectoryScan docs confirm the three-pointer layout, `+0x1028` and `+0x109c` SoundManager relationships, grow/destructor/reallocate/clear method family, deque-helper exclusion, and parent SoundManager source placement. Final C++ stays blank under the 95/95 gate because the element type and exact original source split remain provisional.
