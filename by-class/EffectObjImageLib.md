*** UID:00004A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EffectObjImageLib

## Status

- Confidence: strong for method roles, singleton, vtable, and broad layout; medium for final field names inside `EffectInfo`.
- Likely source file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- Address ranges: [UID:00017K][0x004ddf60-0x004e6455.EffectObjImageLib](by-memory/0x004ddf60-0x004e6455.EffectObjImageLib.md)
- Singleton: [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md) at [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md)
- Vtable: [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md) at `0x0061b724`
- Layout: [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- Current recovered file: `source-3/simroot_v2/class_EffectObjImageLib.cpp`

## Class Purpose

`EffectObjImageLib` is the global effect sprite image library behind `g_pEffectObjImageLib`. It loads effect descriptors and frame remaps, builds effect EPF archive metadata, serves effect records to animation/render callers, and draws effect frames for `EffectObjectPane`.

## Observed State

```text
EffectObjImageLib
  +0x00  LObject/vtable
  +0x04  ProtectedArray<EffectInfo> effectInfoArray
  +0x14  EffectInfo effectInfoScratch
  +0x48  ProtectedArray<EffectPixMapInfo> effectPixMapInfoArray
  +0x58  EffectPixMapInfo fallbackFrameRemap
  +0x5c  ArchiveMetadataTable* effectFileInfo
```

The object is at least `0x60` bytes. The layout is IDA-confirmed from constructor, destructor, `LoadEffectTables`, and `RenderEffectFrame` decompilation. Final source-facing names for some `EffectInfo` subfields are still provisional, but the pointer/count ownership is stable.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `EffectObjImageLib::EffectObjImageLib` | [UID:0002H9][0x004ddf60-0x004de04e.EffectObjImageLibConstructor](by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md) | Initializes effect descriptor/frame arrays, writes [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md), loads effect tables, builds effect EPF metadata, and validates frame count. |
| `EffectObjImageLib::~EffectObjImageLib` | [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md) | Ordinary non-deleting destructor; frees descriptor-owned frame arrays, EPF metadata, descriptor/remap arrays, clears singleton, and calls `LObject` cleanup. |
| `EffectObjImageLib::RenderEffectFrame` | [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md) | Draws one effect frame through the shared image draw callback and optional encoded-alpha overlay pass. |
| `GetSpriteBounds` | `0x004de2a0` | Resolves effect sprite bounds through `g_pEPFLib`, then centers them with map-tile pixel dimensions. |
| `GetEffectInfo` | [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md) | Copies one 1-based [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) descriptor or the scratch fallback. |
| `BuildEffectArchiveTable` | `0x004de420` | One-caller helper that scans numbered `EFFECT%d.EPF` shards into an archive metadata table. |
| `LoadEffectTables` | [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md) | Loads `EFFECT.TBL` descriptors/frame arrays and `EFFECT.FRM` remap entries. |
| `EffectObjImageLib::ClearSingleton` | `0x004e5b70` | Tiny static/runtime teardown helper; writes `g_pEffectObjImageLib = nullptr`. |
| `EffectObjImageLib::ScalarDeletingDestructor` | [UID:0002HC][0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor](by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md) | Virtual/delete destructor body with optional `operator delete`. |

## Data Caveats

- Active generated `class_EffectObjImageLib.cpp` omits `RenderEffectFrame` and the ordinary destructor; `RenderEffectFrame` currently lives in `class_EffectObjImageLib.cpp.disabled`.
- Active generated metadata reports `vtable_count: 0`, but IDA confirms the class vtable at `0x0061b724`.
- The generated `EffectPixMapInfo` name is retained for traceability, but IDA currently proves a four-byte remap entry read from `EFFECT.FRM`, not a rich structure.
- `byte_69B420` / `ImageLibraryLoadErrorFlag` acts as an effect-data load error/suspend flag in loader and renderer paths; keep it near this file until a broader render-resource error-state owner is proven.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00017K][0x004ddf60-0x004e6455.EffectObjImageLib](by-memory/0x004ddf60-0x004e6455.EffectObjImageLib.md)
- [UID:0002H9][0x004ddf60-0x004de04e.EffectObjImageLibConstructor](by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md)
- [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md)
- [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md)
- [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md)
- [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md)
- [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md)
- [UID:0002HC][0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor](by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md)
- [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md)
- [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- 2026-06-07 A005 resolved-name cleanup:
  - Before: render-resource error-state evidence used only the historical `byte_69B420` label.
  - After: the page records resolved name `ImageLibraryLoadErrorFlag` beside the historical label.
  - Evidence: generated resolved-name report maps `byte_69B420` to `ImageLibraryLoadErrorFlag`; existing page evidence already ties the byte to effect-data loader and renderer suspend/error paths.
- 2026-06-03 autogen parent attachment:
  - Before: the class had strong file-owner evidence but blank autogen parent metadata.
  - After: attached to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) at position `10`.
  - Summary/evidence: the file page owns the effect sprite resource family, singleton, vtable, layout docs, and exact method/helper list; both file and class confidence are at least `84`, satisfying the parent-attachment threshold.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `82/84`.
  - Summary/evidence: singleton/library role, broad layout, constructor/destructor/render/query/load/build methods, vtable/global docs, data caveats, and cross-linked helper pages are documented; remaining uncertainty is final `EffectInfo` subfield naming and generated-source omissions.
- 2026-05-31 reconstructability and exact method links:
  - Before: the class had blank `RECONSTRUCTABLE` metadata and text-only rows for several exact methods.
  - After: marked `RECONSTRUCTABLE:TRUE` and linked constructor, `GetEffectInfo`, `LoadEffectTables`, and scalar deleting destructor rows to exact by-memory pages.
  - Summary/evidence: IDA MCP verified all listed method starts/sizes and confirmed the class owns the singleton, vtable, descriptor/remap arrays, and effect resource loaders.
