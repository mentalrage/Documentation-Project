*** UID:0000DI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SoundPathVector

## Status

- Confidence: strong for container behavior and SoundManager use; medium for exact original source placement.
- Likely source file: [UID:0000NV][SoundManager](by-file/SoundManager.md), probably as a private helper or local specialized vector.
- Current generated file: `source-3/simroot_v2/class_SoundPathVector.cpp`
- Imported/recovered source hint: `source-2\core\wave2\recovered\SoundPathVector.cpp`
- Main address doc: [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md)

## Class Purpose

`SoundPathVector` is a three-pointer vector for refcounted or object-backed audio path strings used by [UID:0000DG][SoundManager](by-class/SoundManager.md). It supports growing insertion, destruction, and explicit reallocation for playlist entries and scanned local music path storage.

The class replaced older missing-reference projections such as `SoundManagerList_57BAC0` and `ScanMusicDirectoryHelper_57BD90`. It should stay with audio path-management code rather than move into a generic container module unless broader non-audio callers are found.

## Layout Notes

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `m_begin` | Start pointer for contiguous path-entry storage. |
| `0x04` | `m_end` | One-past-last path entry. |
| `0x08` | `m_capacity` | One-past-capacity path entry. |

Generated code currently models entries as `LObject`, but the class summary and SoundManager use indicate these are audio path-string entries. Keep final element type provisional until the underlying `LObject`/string class is reconciled.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GrowAndInsert` | `0x0057b860-0x0057b99a` | Grows by 1.5x, copy-constructs entries around the insert position, destroys old storage, and returns inserted entry. |
| `~SoundPathVector` | `0x0057bac0-0x0057bb2a` | Destroys entries, frees aligned storage, clears the triplet. |
| `Reallocate` | `0x0057bd90-0x0057be52` | Allocates a new buffer of requested capacity, copy-constructs existing entries, destroys old storage, updates triplet. |
| [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) | `0x0057bf40-0x0057bf6e` | Destroys current entries and resets `end = begin`; used by SoundManager track filename vectors. |

## Boundary Caveats

IDA MCP recheck on 2026-05-25 confirms the end-exclusive boundaries: `GrowAndInsert` is `0x0057b860-0x0057b99a`, `Reallocate` is `0x0057bd90-0x0057be52`, and `Clear` is `0x0057bf40-0x0057bf6e`. Active generated metadata still uses shorter Ghidra-sized method ends for the first two methods.

2026-05-26 recheck: current `class_SoundPathVector.cpp` still emits only `GrowAndInsert`, destructor, and `Reallocate`; the `0x0057bf40` clear helper still has no active `.cpp` body. IDA MCP callers still place `Clear` in SoundManager track-selection and zone-music fallback paths, so keep it with the audio path-vector helper family.

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
