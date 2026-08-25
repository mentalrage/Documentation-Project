*** UID:00004A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class IntAlphaSurface;
class MapPane;
struct ArchiveMetadataTable;
struct RectBounds;

ArchiveMetadataTable *BuildEffectArchiveTable(const wchar_t *unusedArchiveName);

class EffectObjImageLib;
extern EffectObjImageLib *g_pEffectObjImageLib;

class EffectObjImageLib : public LObject, public Singleton<EffectObjImageLib>
{
public:
    EffectObjImageLib();
    virtual ~EffectObjImageLib();

    int RenderEffectFrame(
        MapPane *mapPaneOrRenderContext,
        RectBounds *destinationBounds,
        int frameResourceId,
        int timerDelayAndRenderArg,
        float renderScalar,
        int lightingAndRenderArg,
        IntAlphaSurface *overlayMaskGate,
        float overlayStrength);
    EffectInfo *GetEffectInfo(EffectInfo *outInfo, int effectId);

private:
    void LoadEffectTables();

    ProtectedArray<EffectInfo> effectInfoArray;
    EffectInfo effectInfoScratch;
    ProtectedArray<EffectPixMapInfo> effectPixMapInfoArray;
    EffectPixMapInfo fallbackFrameRemap;
    ArchiveMetadataTable *effectFileInfo;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EffectObjImageLib

## Status

- Confidence: very strong for direct bases, method roles, singleton, vtable, exact layout, source-file ownership, complete source declaration, and compiler-support separation; stripped private field spellings and the exact original header name remain bounded confidence caps.
- Likely source file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- Address ranges: [UID:00017K][0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster](by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md), singleton clear helper [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md), and scalar deleting destructor [UID:0002HC][0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor](by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md)
- Singleton: [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md) at [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md)
- Vtable: [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md) at `0x0061b724`
- Layout: [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- Reconstructed source route: `NexusTK/render/EffectObjImageLib.cpp`; the historical `source-3/simroot_v2/class_EffectObjImageLib.cpp` artifact remains evidence only.

## Class Purpose

`EffectObjImageLib` is the global effect sprite image library behind `g_pEffectObjImageLib`. It loads effect descriptors and frame remaps, builds effect EPF archive metadata, serves effect records to animation/render callers, and draws effect frames for `EffectObjectPane`.

## Observed State

```text
EffectObjImageLib
  +0x00  LObject/vtable
  +0x04  empty Singleton<EffectObjImageLib> base (PMD +4/-1/0), overlapping ProtectedArray<EffectInfo> effectInfoArray
  +0x14  EffectInfo effectInfoScratch
  +0x48  ProtectedArray<EffectPixMapInfo> effectPixMapInfoArray
  +0x58  EffectPixMapInfo fallbackFrameRemap
  +0x5c  ArchiveMetadataTable* effectFileInfo
```

The allocation size is exactly `0x60` bytes. The layout is IDA-confirmed from constructor, destructor, `LoadEffectTables`, and `RenderEffectFrame` decompilation. RTTI proves direct base order `LObject` then `Singleton<EffectObjImageLib>` and Singleton PMD `+4/-1/0`; empty-base optimization overlaps that base with the first protected-array member at `+0x04`. Final source-facing names for some `EffectInfo` subfields are still descriptive, but offsets, widths, pointer/count ownership, and the complete declaration are stable.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `EffectObjImageLib::EffectObjImageLib` | [UID:0002H9][0x004ddf60-0x004de04e.EffectObjImageLibConstructor](by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md) | Authored constructor initializes direct `LObject` and `Singleton<EffectObjImageLib>` bases, descriptor/remap arrays, loads tables, builds effect EPF metadata, and validates `ArchiveMetadataTable::frameCount`; observed global publication/clear is implicit direct-base lowering. |
| `EffectObjImageLib::~EffectObjImageLib` | [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md) | Authored ordinary destructor frees descriptor-owned frame arrays and EPF metadata; protected-array/base teardown and singleton clear are compiler-generated reverse destruction. |
| `EffectObjImageLib::RenderEffectFrame` | [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md) | Draws one effect frame through the shared image draw callback and optional encoded-alpha overlay pass. |
| `GetSpriteBounds` | `0x004de2a0` | Resolves effect sprite bounds through `g_pEPFLib`, then centers them with map-tile pixel dimensions. |
| `GetEffectInfo` | [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md) | Copies one 1-based [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) descriptor or the scratch fallback. |
| `BuildEffectArchiveTable` | `0x004de420` | One-caller helper that scans numbered `EFFECT%d.EPF` shards into an archive metadata table. |
| `LoadEffectTables` | [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md) | Loads `EFFECT.TBL` descriptors/frame arrays and `EFFECT.FRM` remap entries. |
| `EffectObjImageLib Singleton-base cleanup support` | [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md) | Exact compiler unwind helper generated by direct Singleton-base construction; blank/non-emitting and not a hand-authored API. |
| `EffectObjImageLib scalar deleting support` | [UID:0002HC][0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor](by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md) | Compiler wrapper generated from the virtual ordinary destructor; blank/non-emitting, with optional `operator delete` retained as ABI evidence only. |

UID0002H9 source-quality sync: the exact constructor page carries formal `EffectObjImageLib::EffectObjImageLib()` C++ and emits it through this complete class to the [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) source root. MCP session `3fa0535f` confirmed the exact `0x004ddf60-0x004de04e` body, `0xcc 0xcc` padding at `0x004de04e`, one startup caller at `0x004f6113`, vtable and `ProtectedArray` capacity-10 setup, constructor-only `LoadEffectTables()` / `BuildEffectArchiveTable(L"EFFECT.EPF")`, archive `frameCount` validation, `DestroyDATFileMgr` / `DestroyExceptionHandler`, `MessageBoxW(0, L"Error on Effect File!", L"Data Error", MB_ICONEXCLAMATION)`, and `__loaddll(0)`. Direct RTTI and PMD evidence now classify publication/fallback clear as compiler lowering of the `Singleton<EffectObjImageLib>` base, so no explicit global assignment belongs in the authored constructor.

UID00017W cleanup-glue sync: B004's 2026-07-05 callback rejected a source-authored `EffectObjImageLib::ClearSingleton` method. Current MCP evidence identifies the exact `0x004e5b70-0x004e5b7b` helper as `sub_4E5B70`, size `0xb`, body `mov dword ptr unk_69B44C, 0; retn`, one cleanup xref from `0x0060008a`, no callees, no ordinary callsite evidence, unique exact signature `C7 05 4C B4 69 00 00 00 00 00 C3`, non-unique wildcard helper-family signature, and five `cc` padding bytes after the function. Direct Singleton-base evidence closes the source cause: UID00017W is false/non-emitting compiler unwind support and must contribute neither helper source nor a generated marker.

## Data Caveats

- Active generated `class_EffectObjImageLib.cpp` now includes the source-ready UID0002H9 constructor along with the ordinary destructor, `RenderEffectFrame`, `GetEffectInfo`, `LoadEffectTables`, scalar deleting destructor, and singleton clear helper. Several methods are still below source-quality threshold, and `RenderEffectFrame` remains incomplete/effective-excluded in `class_EffectObjImageLib.meta_wave3`.
- Active generated metadata now reports `vtable_count: 1`, matching IDA's class vtable at `0x0061b724`; final confidence is still limited by generated helper/member names and method-quality failures.
- The generated `EffectPixMapInfo` name is retained for traceability, but IDA currently proves a four-byte remap entry read from `EFFECT.FRM`, not a rich structure.
- `byte_69B420` / `ImageLibraryLoadErrorFlag` acts as an effect-data load error/suspend flag in loader and renderer paths, but the declaration owner is the broader [UID:0000K2][ImageLib](by-file/ImageLib.md) shared image-library state. `EffectObjImageLib` remains a writer/reader participant, not the canonical global owner.

## Score Rationale

This page clears the class ownership/layout route for [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md) and the method/type emitters routed through the class. The class owns the singleton lifecycle, effect descriptor/remap arrays, effect EPF metadata, resource-table loaders, bounds helper, render helper, vtable, and layout docs, all routed through direct file parent [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md). Live IDA MCP on 2026-06-13 reconfirmed the singleton storage bytes and all 12 xrefs to [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md): constructor publish/fallback null, ordinary/helper/scalar destructor clears, shutdown read, map/living descriptor reads, and `EffectObjectPane` setup/render reads.

Completion is `92` because the page now emits the complete source declaration required before all out-of-class member bodies: direct bases, virtual destructor, source methods, fields, one extern global, class closure, and `[[CHILDREN]]` order are explicit. Confidence is `94` because the class/file/global/storage chain, exact 0x60 layout, direct RTTI hierarchy, PMD/EBO, inherited virtual slots, and compiler-support split are independently established. Stripped private spellings and exact original header filename keep the scores below 95; they do not leave an implementation blocker.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00017K][0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster](by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md)
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

- 2026-07-21 B004 UID0001PQ source-quality callback:
  - Raised `86/89` to `92/94`, retaining owner/emitter UID0000IY and position 10, and replaced the marker-only block with the complete accepted class/header declaration.
  - Added direct base order `LObject, Singleton<EffectObjImageLib>`, PMD `+4/-1/0` EBO, exact 0x60 field layout, one external global declaration, inherited virtual-slot contract, class closure before `[[CHILDREN]]`, and the complete source method surface. Existing EffectInfo/EffectFrameRecord/EffectPixMapInfo and member-page bodies remain separate and preserved.
  - Historical explicit singleton writes and helper/scalar source interpretations are retained as corrected history: publication/clear, UID00017W, UID0002HC, vtable, RTTI, and layout artifacts are compiler output caused by this declaration and its direct Singleton base.

- 2026-07-05 B004 UID00017W implementation callback:
  - Changed confidence from `88` to `89`; completion, owner/emitter, reconstructable state, emitter position, and formal class marker are unchanged.
  - Summary/evidence: replaced the risky `EffectObjImageLib::ClearSingleton` row with a cleanup-glue row tied to [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md). Current MCP session `supervisor_recovery_20260705` confirmed exact range `0x004e5b70-0x004e5b7b`, body bytes/signature, one cleanup xref from `0x0060008a`, no callees or ordinary callsite evidence, non-unique wildcard singleton-helper pattern, and generated no-code marker routing through [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md). This supports the class route without promoting the helper to a hand-authored class method.
- 2026-06-30 B008 UID0000IY empty-emitter family implementation callback:
  - Changed scores from `85/87` to `86/88`, set `EMITTER_POSITION_OPTIONAL:10`, and added the formal class ownership/layout marker.
  - Summary/evidence: the accepted B008 report keeps this as the class-level route for `EffectObjImageLib` children while avoiding a duplicate generated wrapper class. UID00017L, UID00017M, UID0002HA, and UID0002HB now carry formal first-draft method bodies; file-level helpers/types/globals emit through [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md). The no-code marker is therefore a source-form proof for the class page, not a claim that class-owned methods are absent.
- 2026-06-29 B002 UID0002H9 implementation callback:
  - Score unchanged at `85/87`.
  - Summary/evidence: synchronized the method row and class source-quality note with the accepted UID0002H9 constructor repair. The constructor now emits first-draft `EffectObjImageLib::EffectObjImageLib()` through this class; MCP session `3fa0535f` supplies exact range/padding, startup caller, singleton publish/fallback-clear, vtable/protected-array setup, loader/archive calls, `EFFECT.EPF`, validation, fatal cleanup helpers, `MessageBoxW` strings, and `__loaddll(0)`. B008 later added the class ownership/layout marker while keeping exact method bodies on member pages.
- 2026-06-16 A002 generated-output caveat refresh:
  - Score unchanged at `85/87`.
  - Summary/evidence: active `class_EffectObjImageLib.cpp` and `class_EffectObjImageLib.meta_wave3` were checked. The stale statement that the active output omitted `RenderEffectFrame` and the ordinary destructor was replaced with current evidence: the active file contains those methods and metadata reports `vtable_count: 1`, but method completion, `RenderEffectFrame` effective inclusion, and generated helper/member names still block final-source confidence.
- 2026-06-13 A002 Goal 2 global-quality support refresh:
  - Before: `82/84`.
  - After: `85/87`.
  - Summary/evidence: added score rationale tied to live IDA MCP reconfirmation of the `g_pEffectObjImageLib` slot, complete 12-xref set, constructor/destructor/helper lifecycle, runtime consumer reads, direct file parent [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), and the documented generated-data caveats that keep the class below final-source confidence.

- 2026-06-07 A005 resolved-name cleanup:
  - Before: render-resource error-state evidence used only the historical `byte_69B420` label.
  - After: the page records resolved name `ImageLibraryLoadErrorFlag` beside the historical label.
  - Evidence: generated resolved-name report maps `byte_69B420` to `ImageLibraryLoadErrorFlag`; existing page evidence already ties the byte to effect-data loader and renderer suspend/error paths.
- 2026-06-17 B002 [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md) source-quality execution:
  - Score unchanged at `85/87`.
  - Summary/evidence: the class caveat now uses [UID:00029J][0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag](by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md) as shared ImageLib-owned state, and [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md) now records corrected overlay-gate semantics and current generated-output state. B008's 2026-06-30 callback later attached formal first-draft renderer C++ while preserving shared callback/type caveats.
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
