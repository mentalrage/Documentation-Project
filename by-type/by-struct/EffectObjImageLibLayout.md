*** UID:0001U9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00004A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EffectObjImageLib Layout

## Status

- Confidence: strong for field offsets, medium for final field names.
- Owner class: [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md).
- Evidence: IDA constructor/destructor/render/load decompilation on 2026-05-26.
- Autogen status: attached under [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md) as the class-local object layout; final C++ remains blank under the `95/95` gate.

## Layout

```text
EffectObjImageLib
  +0x00  LObject/vtable
  +0x04  ProtectedArray<EffectInfo> effectInfoArray
  +0x14  EffectInfo effectInfoScratch
  +0x48  ProtectedArray<EffectPixMapInfo> effectPixMapInfoArray
  +0x58  EffectPixMapInfo fallbackFrameRemap
  +0x5c  ArchiveMetadataTable* effectFileInfo
```

## Notes

- The constructor writes the [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md), initializes both protected arrays with capacity `10`, loads descriptor/remap tables, and stores the archive metadata table pointer at `+0x5c`.
- `LoadEffectTables` resizes `effectInfoArray` to the `EFFECT.TBL` count and stores 52-byte [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) records.
- `LoadEffectTables` resizes `effectPixMapInfoArray` to the `EFFECT.FRM` count and stores four-byte [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md) records.
- `RenderEffectFrame` uses `+0x4c` as the remap count, `+0x50` as the remap entries, `+0x58` as the fallback remap, and `+0x5c` as the archive metadata table passed to [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md).
- The ordinary and scalar deleting destructors release descriptor-owned frame arrays, the archive metadata table, both protected-array entry buffers, and [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md).

## Parent Rationale

Attach this layout declaration to [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md). The offsets describe the `EffectObjImageLib` object itself, the owner class clears the `80/80` attachment gate and is already attached to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), and the nested `EffectInfo` / `EffectPixMapInfo` records are separately documented type dependencies rather than alternate parents for this object layout.

## IDA Evidence

- 2026-05-31 IDA MCP `decompile 0x004ddf60` confirms vtable writes, singleton storage, protected-array vtable setup, initial capacity `10`, `LoadEffectTables`, and archive metadata assignment at `this[23]` (`+0x5c`).
- IDA MCP `decompile 0x004de190` confirms render uses `+0x4c` as remap count, `+0x50` as remap entry storage, `+0x58` as fallback remap, and `+0x5c` as the archive metadata table.
- IDA MCP `decompile 0x004de050` and `0x004e62f0` confirm descriptor array cleanup at `+0x0c`, remap array cleanup at `+0x50`, and singleton clear through `dword_69B44C`.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md)
- [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md)
- [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md)
- [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md)
- [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the layout page was reconstructable with IDA-backed object offsets, but had no autogen parent.
  - Changed to: `COMPLETION:80` and `AUTOGEN_PARENT_UID:00004A`, with an explicit class-parent rationale.
  - Summary/evidence: [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md) owns the documented object layout, clears the attachment gate, and links the same constructor/destructor/render/load evidence; final C++ remains blank because nested resource-record field names are still provisional.
- 2026-05-31 IDA evidence and scoring update:
  - Before: metadata was unevaluated (`0/0`) and reconstructability was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`, with completion/confidence set to `78/86`.
  - Summary/evidence: IDA MCP constructor, render, loader, and destructor checks confirm the main object offsets and owned table roles; final field names remain conservative where resource semantics are not fully named.
