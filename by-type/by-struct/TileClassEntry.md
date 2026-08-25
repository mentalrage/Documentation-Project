*** UID:0001WC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000E2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000E2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TileClassEntry

## Status

- Confidence: very strong for exact four-byte size, offsets, owner class, constructor/parser/renderer/destructor use, class-H declaration route, and source-facing descriptive field names; original identifiers remain inferred.
- Rebuild handling: source-authored struct declaration for resource-derived `TILEC` rows.
- Owner class: [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md).
- Source file: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md).
- Source resources: `TILEC.TBL` in current mode, `TILEC.TBD` in legacy mode.
- Assignment: attached to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) after this struct reached `85/88`, the direct class parent is `86/85`, and the source file parent is `86/85`.

## Layout

```text
TileClassEntry
  +0x00  uint16 tileFrameId
  +0x02  uint8  allowPaletteFilter
  +0x03  uint8  reserved
```

## Notes

- The constructor selects `TILEC.TBL` when `byte_66DA97 == 1` and `TILEC.TBD` otherwise, reads the row count, validates it against the tile catalog header, and allocates `4 * tileClassCount` bytes at `StaticObjImageLib + 0x08`.
- Each resource row is a signed 16-bit encoded value. `tileFrameId` stores the low 15 bits (`value & 0x7fff`), while `allowPaletteFilter` stores whether the original value had the signed high bit set.
- `RenderStaticObject` indexes the table as `tileClasses + 4 * tileId`, tests byte `+0x02` when the palette/filter predicate is active, and passes the `uint16` at `+0x00` into the TILEC frame lookup path. When filtering is active and `allowPaletteFilter` is clear, the draw/remap path is skipped.
- Offset `+0x03` is part of the four-byte stride. The current constructor and renderer evidence does not show a meaningful read or write, so it remains a reserved byte rather than a named source field.
- `paletteRemapFlag` remains a usable explanatory alias, and `highBitSet` remains mechanically accurate, but B007 prefers `allowPaletteFilter` because it describes the renderer branch rather than the raw encoding.
- The complete four-byte source declaration appears exactly once in [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) H. This child keeps blank CPP/H so the class header owns the type without duplicate emission.

## Evidence

- 2026-05-31 IDA MCP decompilation of `0x004dcf60` confirms `StaticObjImageLib` allocates `4 * tileClassCount` bytes for the tile-class table at object offset `+0x08`, reads one signed/encoded 16-bit row from `TILEC.TBL` or `TILEC.TBD`, stores `value & 0x7fff` as the `uint16` tile id at record offset `+0x00`, and stores whether the original value was negative/high-bit-set at byte `+0x02`.
- 2026-05-31 IDA MCP decompilation of `0x004dd2c0` confirms `RenderStaticObject` indexes the table as `this->tileClasses + 4 * tileId`, reads the `uint16` tile id from `+0x00` for palette/frame lookup, and tests byte `+0x02` when palette filtering is active.
- 2026-05-31 IDA MCP decompilation of `0x004dd1e0` confirms the tile-class table at `StaticObjImageLib + 0x08` is owned by `StaticObjImageLib` and freed by the destructor.
- 2026-06-11 A001 IDA MCP recheck of `0x004dcf60` confirms the constructor stores the table pointer in `this[2]` (`StaticObjImageLib + 0x08`), allocates `4 * v16` bytes, loops over `v16` `TILEC` rows, writes the high-bit boolean at `this[2] + 4 * row + 2`, and writes the low-15-bit frame id at `this[2] + 4 * row + 0`.
- 2026-06-11 A001 IDA MCP recheck of `0x004dd2c0` confirms the renderer tests `*(_BYTE *)(tileClasses + 4 * tileId + 2)` and reads `*(uint16 *)(tileClasses + 4 * tileId)` for the TILEC frame remap call. When the filter predicate is true and the `allowPaletteFilter` byte is clear, the remap/draw branch is skipped.
- 2026-06-11 A001 IDA MCP recheck of `0x004dd1e0` confirms the ordinary destructor frees `v1[2]`, the same `StaticObjImageLib + 0x08` tile-class table pointer.
- 2026-06-11 A001 continuation recheck: live IDA MCP `lookup_funcs` reports `sub_4DCF60` size `0x278`, `sub_4DD1E0` size `0xde`, and `sub_4DD2C0` size `0x58a`. Decompilation again shows `sub_4DCF60` selects `TILEC.TBL` / `TILEC.TBD`, reads the table count, allocates `4 * v16`, writes `v18[0] < 0` to record byte `+0x02`, and writes `v18[0] & 0x7fff` to record word `+0x00`; `sub_4DD1E0` frees `v1[2]`; and `sub_4DD2C0` reads the record through `*((StaticObjImageLib*)this + 2) + 4 * tileId`.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md). This struct page is `90/95`, the direct class parent is `92/96`, and file parent [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) is `90/94`. The relationship is direct because `StaticObjImageLibLayout` stores `TileClassEntry *tileClasses` at `+0x08`, and constructor, renderer, and destructor access the four-byte rows only through the owning class.

## Score Rationale

- `COMPLETION:90`: the page records the complete four-byte field map, encoded input semantics, exact row stride, modern/legacy resources, constructor population, renderer branch, destructor ownership, class-H declaration route, and direct parent chain.
- `CONFIDENCE:95`: constructor, renderer, destructor, resource widths, and class layout agree on every field and source ownership. Confidence remains below final-source certainty because `tileFrameId`, `allowPaletteFilter`, and `reserved` are reconstructed rather than symbol-proven spellings.

## Historical Terminology

- `paletteRemapFlag` and `highBitSet` remain useful historical/mechanical aliases for byte `+0x02`, but active source uses `allowPaletteFilter` because it describes the observed branch. The evidence is retained; only the preferred human source name changes.

## Cross-References

- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md)
- [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md)
- [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- 2026-08-11 B005 UID000184 class-H synchronization: raised `85/88` to `90/95`, preserved owner/emitter UID0000E2 and blank child formal channels, and documented exact four-byte class-H ownership, parser/render/destructor semantics, source-name rationale, and historical aliases without duplicate declaration emission.

- 2026-06-11 A001:
  - Before: `74/86`, parent blank, with constructor/render/destructor evidence but no strict-gate assignment section.
  - After: `85/88`, `AUTOGEN_PARENT_UID:0000E2`.
  - Evidence: live IDA MCP rechecked the constructor at `0x004dcf60`, render path at `0x004dd2c0`, and ordinary destructor at `0x004dd1e0`. The child struct, direct class parent [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md), and file parent [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) all clear the strict `85/85` gate, while final source field names remain below the final-C++ threshold.
- 2026-06-11 A001 continuation:
  - Score unchanged at `85/88` because [by-type/by-struct/-coverage-report.md](-coverage-report.md) is currently leased to another agent, so this pass improved evidence without changing the coverage row.
  - Evidence: live IDA MCP reconfirmed constructor, destructor, and renderer function sizes and the exact constructor/destructor/render accesses that prove the four-byte record layout.
- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing layout notes. Changed to `COMPLETION:74`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked constructor allocation/population, render-time table lookup, and destructor ownership. The score remains below final-source level because final original field names and TILEC resource semantics still need broader resource-format audit.
- 2026-06-21 B007 Rule 26 incorporation:
  - Scores unchanged at `85/88`.
  - Evidence: accepted `allowPaletteFilter` as the current source-facing name for byte `+0x02`, retained `paletteRemapFlag` / `highBitSet` as historical/mechanical aliases, and documented the renderer branch evidence for skipping draw/remap when palette filtering is active and the flag is clear.
