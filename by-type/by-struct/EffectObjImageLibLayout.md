*** UID:0001U9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EffectObjImageLib Layout

## Status

- Confidence: very strong for exact allocation size, field offsets, direct Singleton EBO, array/table ownership, singleton/vtable anchors, and render/loader/destructor field use; private source spellings remain the bounded cap.
- Owner class: [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md).
- Evidence: IDA constructor/destructor/render/load decompilation on 2026-05-26.
- Source disposition: false/non-emitting layout evidence covered completely by [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md). The formal block is exactly blank; no duplicate `EffectObjImageLibLayout` struct or proof marker is emitted.

## Layout

```text
EffectObjImageLib
  +0x00  LObject/vtable
  +0x04  empty Singleton<EffectObjImageLib> direct base (PMD +4/-1/0)
  +0x04  ProtectedArray<EffectInfo> effectInfoArray (EBO overlap)
  +0x14  EffectInfo effectInfoScratch
  +0x48  ProtectedArray<EffectPixMapInfo> effectPixMapInfoArray
  +0x58  EffectPixMapInfo fallbackFrameRemap
  +0x5c  ArchiveMetadataTable* effectFileInfo
```

## Notes

- The allocation size is exactly `0x60` bytes. RTTI names direct bases `LObject` and `Singleton<EffectObjImageLib>`; the Singleton base descriptor PMD `+4/-1/0` proves empty-base optimization overlap with `effectInfoArray` at `+0x04` rather than an extra data field.

- The constructor writes the [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md), initializes both protected arrays with capacity `10`, loads descriptor/remap tables, and stores the archive metadata table pointer at `+0x5c`.
- `LoadEffectTables` resizes `effectInfoArray` to the `EFFECT.TBL` count and stores 52-byte [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) records.
- `LoadEffectTables` resizes `effectPixMapInfoArray` to the `EFFECT.FRM` count and stores four-byte [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md) records.
- `RenderEffectFrame` uses `+0x4c` as the remap count, `+0x50` as the remap entries, `+0x58` as the fallback remap, and `+0x5c` as the archive metadata table passed to [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md). B002 2026-06-17 reanalysis confirmed these offsets were not blockers for [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md); B008's 2026-06-30 callback later attached formal first-draft renderer C++ while preserving shared callback/draw-state/alpha-surface type caveats.
- The ordinary and scalar deleting destructors release descriptor-owned frame arrays and the archive metadata table; compiler-generated member/base teardown releases both protected-array buffers and clears [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md) through the reverse Singleton base.
- Generated-output check on 2026-06-16 found active `source-3/simroot_v2/class_EffectObjImageLib.cpp` now contains the ordinary destructor, `RenderEffectFrame`, `GetEffectInfo`, `LoadEffectTables`, scalar deleting destructor, and singleton clear helper. That resolves the older "method omitted from active output" caveat, but the emitted file is still below source-quality threshold and uses unstable helper/member names such as `m_defaultPaletteSlot`, `m_paletteSlotCount`, and a generic local `EffectInfo` overlay.

## Parent Rationale

Attach this layout declaration to [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md). The offsets describe the `EffectObjImageLib` object itself, the owner class clears the `80/80` attachment gate and is already attached to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), and the nested `EffectInfo` / `EffectPixMapInfo` records are separately documented type dependencies rather than alternate parents for this object layout.

The class page now emits every real base/member declaration. This page remains its non-emitting binary-layout proof: it must preserve exact offsets, allocation size, uses, and EBO while contributing no standalone struct, marker, or duplicated fields.

## IDA Evidence

- 2026-05-31 IDA MCP `decompile 0x004ddf60` confirms vtable writes, singleton storage, protected-array vtable setup, initial capacity `10`, `LoadEffectTables`, and archive metadata assignment at `this[23]` (`+0x5c`).
- IDA MCP `decompile 0x004de190` confirms render uses `+0x4c` as remap count, `+0x50` as remap entry storage, `+0x58` as fallback remap, and `+0x5c` as the archive metadata table.
- IDA MCP `decompile 0x004de050` and `0x004e62f0` confirm descriptor array cleanup at `+0x0c`, remap array cleanup at `+0x50`, and singleton clear through `dword_69B44C`.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed modeled method starts and sizes for the layout-driving methods: constructor `0x004ddf60` size `0xee`, ordinary destructor `0x004de050` size `0x13a`, render `0x004de190` size `0x110`, `GetEffectInfo` `0x004de3e0` size `0x40`, loader `0x004de7d0` size `0x453`, and scalar deleting destructor `0x004e62f0` size `0x166`.
- Live `analyze_function 0x004ddf60` confirmed constructor layout writes: publish [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md), install `EffectObjImageLib` vtable, initialize embedded `ProtectedArray<EffectInfo>` and `ProtectedArray<EffectPixMapInfo>` views with initial capacity `10`, call `LoadEffectTables`, build `EFFECT.EPF` archive metadata, and store the archive table pointer at `this[23]` (`+0x5c`).
- Live `analyze_function 0x004de190` confirmed renderer field use: guard on the image-library load-error flag, compare frame/remap index against `this[19]` (`+0x4c`), read remap entries from `this[20]` (`+0x50`) or fallback `this + 22` (`+0x58`), pass `this[23]` (`+0x5c`) to the frame-record loader, and optionally perform the alpha overlay pass.
- Live `analyze_function 0x004de7d0` confirmed `EFFECT.TBL` loading into 52-byte `EffectInfo` records and retained the existing `EFFECT.FRM` remap relationship documented by [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md).
- Live `xrefs_to 0x0061b724` returned the three `EffectObjImageLib` vtable stores from constructor, ordinary destructor, and scalar deleting destructor. Live `xrefs_to 0x0069b44c` returned 12 singleton refs spanning constructor publish/fallback, ordinary/helper/scalar destructor clears, shutdown reads, and map/effect consumer reads.
- Supporting owner pages now clear the route for this class-local layout: [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md) is `85/87`, and [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) is `89/86` with the effect resource ownership, method cluster, and generated-output caveats documented.
- 2026-06-16 live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed current modeled starts and sizes: constructor `0x004ddf60` size `0xee`, ordinary destructor `0x004de050` size `0x13a`, renderer `0x004de190` size `0x110`, `GetEffectInfo` `0x004de3e0` size `0x40`, loader `0x004de7d0` size `0x453`, singleton clear `0x004e5b70` size `0x0b`, and scalar deleting destructor `0x004e62f0` size `0x166`.
- The same session reconfirmed `xrefs_to 0x0061b724` as exactly three vtable stores from constructor/destructor/scalar destructor and `xrefs_to 0x0069b44c` as 12 singleton references, including constructor publish/fallback null, destructor/helper clears, shutdown read, map/effect descriptor reads, and `EffectObjectPane` bounds/render reads.
- UID0001PQ target-specific RTTI reanalysis resolved the missing direct-base fact: `EffectObjImageLib` directly derives from `LObject` and `Singleton<EffectObjImageLib>`, and Singleton PMD `+4/-1/0` exactly matches the adjusted constructor/destructor global lifecycle writes and `+0x04` EBO overlap.

## Score Rationale

Completion is `92` because the page records the exact 0x60 object layout, direct Singleton EBO, protected-array subobjects, scratch/fallback records, archive pointer, method field use, singleton/vtable anchors, nested dependencies, and exact blank class-covered disposition. Confidence is `94` because constructor, renderer, loader, destructor, RTTI, vtable, and singleton facts agree; private names and exact original header spelling remain the only caps.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md)
- [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md)
- [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md)
- [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md)
- [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md)

## Changes

- 2026-07-21 B004 UID0001PQ source-quality callback:
  - Raised `86/89` to `92/94`, changed reconstructable true/emitter UID00004A/comment marker to false/blank emitter/exactly blank formal C++, and retained UID00004A as the layout's class owner.
  - Added exact 0x60 allocation size, direct `Singleton<EffectObjImageLib>` PMD `+4/-1/0`, EBO overlap at `+0x04`, and the compiler-lowered publication/reverse-clear relationship. Preserved all existing offsets, constructor/render/load/destructor evidence, nested record dependencies, resource roles, vtable/global xrefs, and historical generated caveats.
  - The complete class page now emits the real fields; this page intentionally emits no duplicate layout struct, source comment, or marker.

- 2026-06-30 B008 empty-emitter implementation callback:
  - Before: `86/89`, blank formal block.
  - After: score unchanged, formal no-duplicate-layout marker attached under [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md).
  - Summary/evidence: accepted report used current MCP session `supervisor_resume_20260629`, server-health call id `3`, constructor/render/load/destructor offset evidence, vtable and singleton anchors, and nested record dependencies to reject a separate emitted `EffectObjImageLibLayout` struct. The object layout remains represented by class fields and the source-declared resource PODs.

- 2026-06-16 A002 Goal2 type-confidence refresh:
  - Before: `85/88`.
  - After: `86/89`; owner/emitter remain [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md), with final C++ still blank.
  - Summary/evidence: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed method sizes, vtable-store refs, and 12 singleton refs. Active generated `class_EffectObjImageLib.cpp` was checked and now includes the methods previously described as omitted, but its helper/member names and local `EffectInfo` overlay are still generated/provisional, so final layout names remain blocked.
- 2026-06-14 A002 Goal2 by-type score refresh:
  - Before: `COMPLETION:80`, `CONFIDENCE:86`; the page had the broad layout and parent rationale but lacked the current live constructor/render/load/vtable/singleton refresh and still referenced older final-code gate phrasing.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`, with emitted source still deferred to class/member declarations.
  - Evidence: live MCP reconfirmed all layout-driving function sizes, constructor writes for the two protected arrays and archive table pointer, render reads of remap count/storage/fallback/archive table fields, loader handling for `EFFECT.TBL`, three vtable-store xrefs, and twelve `g_pEffectObjImageLib` singleton refs. Remaining blockers are final field names and nested resource-record naming.
- 2026-06-07 parent attachment update:
  - What existed before: the layout page was reconstructable with IDA-backed object offsets, but had no autogen parent.
  - Changed to: `COMPLETION:80` and `AUTOGEN_PARENT_UID:00004A`, with an explicit class-parent rationale.
  - Summary/evidence: [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md) owns the documented object layout, clears the attachment gate, and links the same constructor/destructor/render/load evidence. B008's 2026-06-30 callback later added a no-duplicate-layout marker because nested resource-record fields are emitted by member/type pages.
- 2026-05-31 IDA evidence and scoring update:
  - Before: metadata was unevaluated (`0/0`) and reconstructability was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`, with completion/confidence set to `78/86`.
  - Summary/evidence: IDA MCP constructor, render, loader, and destructor checks confirm the main object offsets and owned table roles; final field names remain conservative where resource semantics are not fully named.
