*** UID:0000B4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Source uses ProtectedArray<GameServerConfig::NationEntry> as
// GameServerConfig::m_nationEntries. Do not emit a generated wrapper class
// named ProtectedArray_struct_GameServerConfig__NationEntry_; the reusable
// template bodies belong to ProtectedArray support pages, and [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md)
// emits the concrete GameServerConfig::NationEntry Resize(int count) body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray_struct_GameServerConfig__NationEntry_

## Status

- Confidence: very strong for destructor behavior, resize behavior, vtable anchors, and GameServerConfig embedding; medium-high for final source-level header basename.
- Proposed file: [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- Primary executable ranges: deleting destructor `0x00514d50-0x00514d7f`; companion `GameServerConfig` cleanup `0x00514d80-0x00514ddc`; resize helper `0x00514ee0-0x00514f6b`.
- Read-only vtable data: [UID:0003II][0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData](by-memory/0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData.md).
- Evidence basis: live IDA MCP disassembly/decompilation on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Responsibility

This is the protected-array backing container for `GameServerConfig::NationEntry` records. The concrete deleting destructor resets the protected-array vtable, frees the backing entry buffer at object offset `+0x08`, and conditionally deletes the 0x54-byte container object. The concrete resize helper is the emitted `ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)` instantiation of the reusable `ProtectedArray<T>::Resize` template body.

The element layout is tracked separately as [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md): a 68-byte record with a 16-bit nation id followed by a 33-wide-character label.

## Method

| Address | Method | Role |
| --- | --- | --- |
| [UID:000372][0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor](by-memory/0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor.md) | `ScalarDeletingDestructor(unsigned char deleteFlag)` | Frees `m_entries`, restores the `ProtectedArray<GameServerConfig::NationEntry>` vtable, and conditionally deletes the 0x54-byte protected-array object. |
| [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) | `Resize(int count)` | Concrete `ProtectedArray<GameServerConfig::NationEntry>` instantiation of the reusable `ProtectedArray<T>::Resize` body; positive-count resize with `NationEntry` default id initialization, prefix preservation, and dynamic array replacement. |

## Live IDA Evidence

- IDA names the vtable at `0x0061e704` as `??_7?$ProtectedArray@UNationEntry@GameServerConfig@@@@6B@`; the vtable slot points to `0x00514d50`, and data refs from `0x00503a1c`, `0x00503a5c`, `0x00504481`, `0x00514d59`, and `0x00514d8f` tie it to construction, cleanup, and the deleting destructor.
- 2026-06-12 A003 Batch326 split the exact one-slot vtable child to [UID:0003II][0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData](by-memory/0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData.md), separating it from the neighboring `GameServerConfig` class vtable and `MapPane` RTTI boundary in [UID:0002SP][0x0061e704-0x0061e71c.GameServerConfigVtableData](by-memory/0x0061e704-0x0061e71c.GameServerConfigVtableData.md).
- `0x005039f0-0x00503a42` is a raw `GameServerConfig` constructor-shaped body: it stores `dword_69B4C4`, installs the outer `GameServerConfig` vtable at `0x0061e70c`, installs the embedded protected-array vtable at `this+4`, writes fallback nation id `-1` at protected-array offset `+0x10`, sets offset `+0x0c` to `10`, and clears count/pointer fields at `+0x04/+0x08`.
- `0x00504110` repeats the same initialization sequence inside MapPane initialization at `0x00504478-0x00504499`, which confirms this protected-array instance is embedded in the map/game-server configuration path.
- `0x00514d50-0x00514d7f` pushes `[this+0x08]` to `free`, restores the protected-array vtable at `[this]`, and passes size `0x54` to the conditional delete path when the scalar-delete flag is set.
- `0x00514ee0-0x00514f6b` is the concrete resize helper. The sole direct code ref is parser call `0x00503d4f`, where `ecx` is loaded with `GameServerConfig+4`; the helper multiplies the requested count by `0x44`, initializes the first word of every new record to `-1`, copies `min(oldCount,newCount) * 0x44` bytes with `memmove`, frees the previous buffer, then updates protected-array offsets `+0x08` and `+0x04`.

## Ownership Notes

- This specialization is the direct documentation parent for the concrete binary helper at [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md).
- The reusable source body belongs to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) / [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md); the concrete instantiation is emitted in the [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) map/game-server source route because the only caller and record type are feature-local.
- This should migrate with `map/GameServerConfig.cpp` or remain a private helper near `MapPane` if the nation table is folded into `MapPane.cpp`.
- The exact page name is a tool-facing concrete-instantiation spelling. Prefer a source-level declaration such as `ProtectedArray<GameServerConfig::NationEntry>` in reconstructed code.
- The reusable template behavior is tracked in [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md); this page remains map-owned because the concrete nation-entry table belongs to `GameServerConfig`.
- B009 resolves the stale empty marker with a formal no-duplicate comment rather than a generated wrapper class declaration. Source uses `ProtectedArray<GameServerConfig::NationEntry>` as `GameServerConfig::m_nationEntries`; reusable template bodies belong to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) / [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md), and the concrete resize body remains [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md).

## Cross-References

- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:00005O][GameServerConfig](by-class/GameServerConfig.md)
- [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md)
- [UID:0001B4][0x00514d50-0x00514ddc.GameServerNationTableDelete](by-memory/0x00514d50-0x00514ddc.GameServerNationTableDelete.md)
- [UID:000372][0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor](by-memory/0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor.md)
- [UID:0003II][0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData](by-memory/0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData.md)
- [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md)

## Changes

- 2026-06-19 B004 GameServerConfig accepted source-quality sync: score unchanged at `87/90`; [UID:00005O][GameServerConfig](by-class/GameServerConfig.md) now records `87/89` and keeps class-level C++ blank. This page remains the concrete owner for [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) as `ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)`, not an outer `GameServerConfig` method.
- 2026-07-01 B009 accepted empty-emitter-family implementation: raised to `88/91` and inserted a formal no-duplicate C++ comment. The implementation preserves concrete specialization evidence, [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) resize ownership, and the reusable-template split while rejecting duplicate generated wrapper class emission.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and assigned parent `0000JP`.
  - Before: reconstruction autogen classification and parent were blank for a documented `ProtectedArray<GameServerConfig::NationEntry>` instantiation.
  - After: classified as reconstructable source-facing template/declaration evidence attached to [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md).
  - Evidence at that time: live IDA MCP lookup confirmed modeled deleting destructor `0x00514d50` and resize helper `0x00514ee0`; existing notes documented the `0x0061e704` vtable, map/game-server config embedding, 68-byte nation-entry stride, and parser-only resize caller. This predated the strict `85/85` gate and is superseded by the 2026-06-11 A008 refresh, where the class reached `85/88` and the parent file remained `86/85`.

- 2026-05-30: Changed completion/confidence from `0/0` to `74/76`.
  - Before: The page was unevaluated despite documenting the protected-array role, nation-entry layout reference, destructor, resize helper, and ownership caveats.
  - After: Scored as moderate-high completion with medium-high confidence because the final source-level type spelling remains less certain than the helper behavior.
  - Evidence: Existing status, responsibility, method table, ownership notes, and GameServerConfig/global/memory cross-references cover the container role and remaining uncertainty.
- 2026-06-04: Raised completion from `74` to `84` and confidence from `76` to `88` after live IDA MCP verification of the concrete instantiation.
  - Before: the page relied on stale tool-output wording and did not record the vtable/store/caller evidence that proves ownership and layout.
  - After: the page records exact destructor and resize boundaries, the `0x0061e704` vtable slot and refs, constructor/destructor vtable stores, MapPane initialization embedding, parser-only resize caller, 0x44 record stride, 0x54 protected-array object size, and protected-array field offsets used by the destructor and resize helper.
  - Evidence: live IDA confirms `sub_514D50` is `0x00514d50-0x00514d7f`, `sub_514EE0` is `0x00514ee0-0x00514f6b`, raw constructor/destructor sequences at `0x005039f0` and `0x00503a50`, MapPane initialization stores at `0x00504478-0x00504499`, and parser call `0x00503d4f`. Scores remain below final reconstruction because final header spelling and template/source emission shape still need a source-level audit.
- 2026-06-11 A008 Batch 165: Raised completion from `84` to `85` and retained confidence `88` after splitting the exact deleting destructor into [UID:000372][0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor](by-memory/0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor.md). Evidence: live IDA MCP reconfirmed the destructor boundary, vtable slot, callee pair, vtable-store refs, and padding; the class can now serve as the direct parent for the exact destructor child under the strict `85/85` gate.
- 2026-06-12 A003 Batch326: Added exact read-only vtable child [UID:0003II][0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData](by-memory/0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData.md) after splitting the old mixed [UID:0002SP][0x0061e704-0x0061e71c.GameServerConfigVtableData](by-memory/0x0061e704-0x0061e71c.GameServerConfigVtableData.md) container. Score remains `85/88`; this only moves already-documented vtable evidence into an exact child.
- 2026-06-19 B008 implementation of accepted [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) report: raised score to `87/90`, renamed the resize row to `Resize(int count)`, and documented the concrete-specialization versus reusable-template split. Evidence: local PE/Capstone recheck in the B008 report confirms the sole parser caller passes `ecx = this + 4`, the body uses protected-array offsets, and the source body is reusable `ProtectedArray<T>::Resize` emitted for `GameServerConfig::NationEntry`.
