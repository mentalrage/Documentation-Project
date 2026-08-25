*** UID:0001VC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008N | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008N | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MonsterImageEntry
{
    int baseFrameIndex;
    unsigned char animationGroupCount;
    unsigned char projectionFlag;
    unsigned short paletteTableId;
    ImageAnimationGroup *groups;

    void AllocateGroups(unsigned int count);
    ImageAnimationGroup *GetGroup(unsigned int groupIndex);
    ImageAnimationFrame *GetFrame(unsigned int groupIndex, unsigned int frameIndex);
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MonsterImageEntry

## Status

- Confidence: strong for size, loader/destructor behavior, nested table pointer, lookup behavior, active render/bounds consumers, and direct owner class; medium for final original field spellings.
- Owner class: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).
- Size: `0x0c` / 12 bytes (Verified with int_convert.py).
- Evidence: [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md), `MonsterImageLib` destructor iterator, `GetEntryByIndex`, render/bounds consumers, and shared helper docs.
- Assignment status: assigned to [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md). This page documents and emits the concrete monster row declaration; [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) documents the shared helper implementation.

## Layout

```text
MonsterImageEntry
  +0x00  int32 baseFrameIndex
  +0x04  uint8 animationGroupCount
  +0x05  uint8 projectionFlag
  +0x06  uint16 paletteTableId
  +0x08  ImageAnimationGroup* groups
  sizeof = 0x0c
```

These are accepted source-facing inferred names, not recovered symbols. `animationGroupCount`, `projectionFlag`, and `groups` are strong. `paletteTableId` is the best current source-facing name for `+0x06`, but it remains weaker than the fields with direct allocation/render evidence.

## Field Evidence

| Offset | Accepted source-facing name | Evidence-backed role | Remaining caveat |
| --- | --- | --- | --- |
| `+0x00` | `baseFrameIndex` | `RenderMonster`, `RenderMonsterImage`, and `ComputeRenderBounds` add the signed `ImageAnimationFrame::frameOffset` returned by the nested lookup helper to this dword before resolving sprite payload or archive bounds. | Confirmed as the base image/frame index; original member spelling is unknown. |
| `+0x04` | `animationGroupCount` | `LoadMonsterTables` reads one byte here, `0x005289d0` uses it to allocate 8-byte group records, `0x00528b10` bounds-checks group indexes against it, and the row destructor clears it after freeing nested records. | Exact original spelling is unknown, but the count semantics are strong. |
| `+0x05` | `projectionFlag` | `RenderMonster`, `RenderMonsterImage`, and `ComputeRenderBounds` read this byte from the selected row and use it for vertical/projection adjustment decisions around tall sprites and overlay bounds. | Active render policy, not padding; full value domain remains open. |
| `+0x06` | `paletteTableId` | `LoadMonsterTables` reads a 16-bit value here. Render-side review shows this row word participates in palette/table selection context, but it is not consumed as directly as `+0x00/+0x04/+0x05/+0x08`. | Weaker than the other accepted names; if later evidence shows a variant/group meaning instead, update this field and the target C++ together. |
| `+0x08` | `groups` | `0x005289d0` writes the allocated array of 8-byte `ImageAnimationGroup` records here; `0x00528b10` starts from this pointer, selects an 8-byte group, then returns a 10-byte `ImageAnimationFrame` record or the shared default frame record. The row destructor frees this vector and clears the pointer. | The group/frame type names are inferred neutral source-facing names selected by B001, not original symbols. |

## Nested Type Relationship

The accepted `LoadMonsterTables` reconstruction uses the neutral shared helper vocabulary:

```text
ImageAnimationGroup
  +0x00  ImageAnimationFrame* frames
  +0x04  uint16 frameCount
  +0x06  uint16 reserved
  sizeof = 0x08

ImageAnimationFrame
  +0x00  int16 frameOffset
  +0x02  int16 frameDuration
  +0x04  uint8 blendAlpha
  +0x05  uint8 reserved
  +0x06  int16 auxFrameId
  +0x08  uint8 paletteIndex
  +0x09  uint8 effectIndex
  sizeof = 0x0a
```

`frameOffset`, `frameDuration`, and `blendAlpha` are backed by render/scheduler/default-table evidence. `auxFrameId`, `paletteIndex`, and `effectIndex` remain weaker inferred names. This page records them because [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) must parse the complete serialized record, but the shared helper pages remain the canonical home for the helper bodies.

## IDA Verification Notes

- 2026-05-31 IDA MCP `lookup_funcs 0x004dac40` reports `sub_4DAC40` size `0x27d`, so [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) is the exact loader range.
- IDA MCP decompilation of `0x004dac40` shows the main vector allocation as `12 * rowCount + 4` with MSVC vector constructor element size `0x0c` / 12 bytes (Verified with int_convert.py).
- The loader writes the vector pointer to `MonsterImageLib +0x04` and the row count to `MonsterImageLib +0x08`.
- Per row, IDA shows reads of 4 bytes into `entry +0x00`, 1 byte into `entry +0x04`, 1 byte into `entry +0x05`, and 2 bytes into `entry +0x06`.
- IDA MCP decompilation of helper `0x005289d0` shows nested 8-byte record allocation using `entry +0x04` as the count and writes the nested pointer to `entry +0x08`.
- IDA MCP decompilation of helper `0x00528950` shows the row destructor frees the nested 8-byte records and resets the count byte at `+0x04` and pointer at `+0x08`.
- 2026-06-11 `0x00528b10` decompilation shows the nested lookup starting at `entry +0x08`, using byte `+0x04` to bounds-check the outer group, stepping 8 bytes per selected group, using the selected group's `+0x04` 16-bit count to bounds-check the frame index, and returning either `group.frames + 10 * frameIndex` or the default frame record at `0x0066deb0`.
- 2026-06-11 caller checks show `0x00528b10` is used by `RenderMonster` twice, `RenderMonsterImage` twice, and `ComputeRenderBounds` once, proving the nested frame-table lookup is part of the active monster render/bounds path.
- 2026-06-11 `GetEntryByIndex` decompilation shows `MonsterImageLib +0x04` plus `12 * index` when the requested index is in range, otherwise returning the concrete fallback/default table object at `0x0069b424`.
- 2026-06-25 B001 accepted rework adds render/scheduler field evidence: frame record `+0x00` is a signed frame offset, `+0x02` is timing/duration input to scheduler calls, and `+0x04` is a monster render blend alpha/mode byte. This supersedes older shared `endFrame` and `direction` wording.

## Notes

- `LoadMonsterTables` reads the first eight bytes of each row from `MONSTER.DNA` or `MONSTER.DND`, then allocates/fills nested `ImageAnimationGroup` / `ImageAnimationFrame` records behind the pointer at `+0x08`.
- `RenderMonster` and `RenderMonsterImage` add frame offsets from nested frame records to `baseFrameIndex` before retrieving sprite payload and bounds data.
- The same 12-byte outer helper shape is also used by `RidingImageLib::LoadRidingDefinitions` through the shared [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) helper island. This page documents the concrete monster-entry row owned by `MonsterImageLib`, not a claim that the shared helper implementation is monster-only.
- The current C++ block emits the accepted concrete monster row declaration with helper method declarations only. Method bodies for allocation/lookup helpers remain in the accepted [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) family and are not duplicated here. The method-level loader body remains on [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md).

## UID0003U8 Nested Frame Timing Synchronization - 2026-07-15

- The nested `ImageAnimationFrame` contract uses signed `int16`/C++ `short frameDuration` at `+0x02`. The enclosing `MonsterImageEntry` declaration, 12-byte row layout, group pointer, lookup declarations, score, owner/emitter route, and formal C++ remain unchanged.
- Five consumers at `0x0053a30b`, `0x0053aaae`, `0x0053b780`, `0x0053ba59`, and `0x005a37d6` sign-extend the selected frame's duration word before timing use. This is direct consumer evidence rather than inference from the loader alone.
- [UID:0003U8][0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation](by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md) is the local-player consumer. It obtains this row through bounds-checked `MonsterImageLib::GetEntryByIndex`, selects `groups[m_animationGroup]`, selects `frames[m_moveFrame]`, and forwards signed `frameDuration` to TimerMgr event `20`.
- Two-byte loader reads, decimal `30000` defaults, `0x0a` frame size, `frameOffset`, `blendAlpha`, and weaker tail-field caveats are preserved. Historical `uint16 frameDuration` wording is superseded; it is not a layout or parser-width change.

## Assignment Gate

This struct is assigned under the strict supervisor gate.

- Child side: the page is `88/89` with exact size/stride, field offsets, loader read order, destructor cleanup, nested lookup, fallback/default behavior, render/bounds field consumers, shared-helper boundary, and formal struct declaration documented.
- Direct owner side: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) is the narrow class owner at `89/90`; [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) is the source file parent at `89/89`.
- Supporting docs: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) owns the shared monster/riding table-helper implementation, while this page owns the concrete monster table row layout used by [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).
- Classification: source-owned private monster animation-table row, assigned to [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page documents exact size/stride, all five row field offsets, loader read order, nested allocation and lookup, row destructor cleanup, fallback-row behavior, render/bounds field consumers, accepted source-facing field names, shared-helper boundary, strict-gate class assignment, and formal row declaration with helper method declarations. Completion remains below final because helper method bodies and the weakest frame fields still need broader helper-family declaration work. |
| Confidence `89` | Confidence is strong because live IDA lookup/decompilation/caller evidence aligns across `LoadMonsterTables`, `GetEntryByIndex`, render/bounds consumers, nested lookup helpers, and destructor cleanup. It is not higher because `paletteTableId`, `auxFrameId`, `paletteIndex`, `effectIndex`, and exact original symbols remain inferred. |

## Cross-References

- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md)
- [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md)

## Changes

- 2026-06-30 B011 empty-emitter family implementation callback:
  - Score changed from `86/88` to `88/89`.
  - Evidence: inserted the formal `MonsterImageEntry` struct declaration with `baseFrameIndex`, `animationGroupCount`, `projectionFlag`, `paletteTableId`, `groups`, and helper method declarations only. Preserved 0x0c stride, loader read order, row destructor cleanup, nested `ImageAnimationGroup`/`ImageAnimationFrame` relationship, accepted loader C++ compatibility, shared-helper method-body ownership under [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md), and weaker-field caveats.
- 2026-06-25 B001 implementation callback:
  - Score unchanged at `86/88`.
  - Evidence: synchronized row and nested field names with accepted [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) implementation. Updated `+0x04` to `animationGroupCount`, `+0x05` to `projectionFlag`, `+0x06` to `paletteTableId` with a weaker caveat, and `+0x08` to `groups`; added the accepted `ImageAnimationGroup` / `ImageAnimationFrame` nested layouts and superseded older `endFrame` / `direction` wording.
- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `78`, confidence `86`.
- Summary/evidence: IDA MCP on 2026-05-31 verified the exact `LoadMonsterTables` child range, 0x0c row stride, field reads at `+0x00/+0x04/+0x05/+0x06`, nested pointer at `+0x08`, and destructor cleanup behavior. Scores remain below `95` because final source names and all downstream field semantics are not yet exhaustively recovered.
- 2026-06-11 A005 Batch145:
  - What existed before: the row was reconstructable but unassigned at `78/86`; downstream render/bounds field use and the shared-helper boundary were underdocumented.
  - Changed to: raised to `86/88`, assigned to [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md), added field evidence for all offsets, documented nested lookup helper `0x00528b10`, fallback row `0x0069b424`, and live render/bounds consumers.
  - Summary/evidence: live IDA reconfirmed loader/destructor/render/bounds starts, `GetEntryByIndex` returning `entries + 12 * index` or the fallback row, `0x00528b10` selecting nested 10-byte frame records from `+0x08`, and active use of `+0x00`, `+0x04`, `+0x05`, and `+0x08`.
