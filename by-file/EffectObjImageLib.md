*** UID:0000IY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# EffectObjImageLib

## Status

- Confidence: very strong for complete class/source/compiler/global union, resource ownership, singleton storage/lifecycle, vtable/layout ownership, exact method boundaries, one-definition route, and generated contract; exact original filename and private names remain bounded caps.
- Proposed module: `render/EffectObjImageLib.cpp`
- Historical recovered source: `source-3/simroot_v2/class_EffectObjImageLib.cpp`; it remains evidence, not the current source authority.
- Historical generated-output caveat (2026-06-30): B008's family callback emitted file-owned declarations/helpers, source-form markers, and encountered suppressed class/global-owned children. That exact intermediate inventory is preserved in the 2026-06-30 change entry below and is superseded by the current complete class-plus-children route.
- Historical UID00017W marker state (2026-07-05): validators emitted a comment-only marker at `86/91`. UID0001PQ source-quality closure supersedes it with `93/96`, false/non-emitting metadata, and an exactly blank block because direct Singleton-base construction explains the compiler helper.
- Current source contract: `NexusTK/render/EffectObjImageLib.cpp` contains one complete class declaration, one external `g_pEffectObjImageLib` definition, authored constructor/destructor/render/get-info/load bodies plus BuildEffectArchiveTable/GetSpriteBounds helpers, and no physical-storage, Singleton-clear, scalar-wrapper, layout, vtable, RTTI-data, or aggregate marker/body.
- Main address ranges: `0x004ddf60-0x004dec23`, `0x004e5b70-0x004e5b7b`, and `0x004e62f0-0x004e6456` (`[start,end)` for exact function pages where rechecked)
- Primary global instance: [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md), backed by [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md)
- Primary vtable: [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md) at `0x0061b724`
- Layout/type docs: [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md), [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md), [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md), [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md)

## File Role

`EffectObjImageLib` is the effect sprite image library. It owns `EFFECT.TBL` effect descriptors, `EFFECT.FRM` frame-to-pixmap/palette remaps, the merged effect EPF archive metadata table, and effect bounds/render helper behavior.

This should remain a separate render source file from map/static object libraries. It shares the same EPF archive-table loader pattern, but the data model is effect-specific: each [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) descriptor has two heap-owned [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md) arrays, while the `EFFECT.FRM` table maps effect animation frames to four-byte [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md) remap entries.

This file is also separate from the runtime [UID:0000IZ][Effects](by-file/Effects.md) module. `EffectObjImageLib` loads and indexes effect sprite assets; runtime classes such as `EffectObjectPane`, `OverlayEffecter`, `FilterEffecter`, `WaterFilterEffecter`, and `XWaveEffecter` consume those assets or render over the map.

The generated `ProtectedArray_struct_EffectInfo_` and `ProtectedArray_struct_EffectPixMapInfo_` files are template-instantiation artifacts for the descriptor and frame-remap arrays owned here. Keep the reusable template in [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), not as effect-specific standalone source files.

UID0002H9 source-root sync: [UID:0002H9][0x004ddf60-0x004de04e.EffectObjImageLibConstructor](by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md) now emits first-draft `EffectObjImageLib::EffectObjImageLib()` through [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md) into `NexusTK/render/EffectObjImageLib.cpp`. MCP session `3fa0535f` confirmed the exact constructor body/range, `0xcc 0xcc` padding before the ordinary destructor, one startup caller, singleton publish/fallback-clear evidence, vtable and `ProtectedArray` capacity-10 setup, constructor-only `LoadEffectTables()` and `BuildEffectArchiveTable(L"EFFECT.EPF")`, archive-count validation, `DestroyDATFileMgr` / `DestroyExceptionHandler`, `MessageBoxW(0, L"Error on Effect File!", L"Data Error", MB_ICONEXCLAMATION)`, and `__loaddll(0)`. The source placement remains `NexusTK/render/`; exact original filename and some private field/type names are still confidence caps for the file page.

UID0001PQ source-quality closure adds the decisive source hierarchy: `EffectObjImageLib : public LObject, public Singleton<EffectObjImageLib>`, direct-base order in that sequence, and Singleton PMD `+4/-1/0` EBO. The direct base causes adjusted publication and reverse clear, so constructor/destructor source contains no explicit global lifecycle statements. UID0000QT owns one externally linked zero definition and UID00004A owns one matching extern. UID00017W, UID0002HC, UID0001U9, UID0001XG, UID0002MK, UID0001PQ, and UID00017K are compiler/data/layout/index evidence and emit nothing.

## Owned Methods And Helpers

| Range | Function | Role |
| --- | --- | --- |
| `0x004ddf60-0x004de04e` | [UID:0002H9][0x004ddf60-0x004de04e.EffectObjImageLibConstructor](by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md) | Authored constructor with direct LObject/Singleton bases, descriptor/remap arrays, effect table/archive loading, shared frame-count validation, and no explicit global publication source. |
| `0x004de050-0x004de189` | [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md) | Authored non-deleting cleanup body for effect frame arrays and EPF metadata; member/base teardown implicitly releases arrays and singleton state. |
| `0x004de190-0x004de29f` | [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md) | Real effect sprite draw method. The exact child page now carries B008 formal first-draft C++ plus corrected overlay-gate/source-shape evidence and remains the accuracy anchor. |
| `0x004de2a0-0x004de3d2` | [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md) | Effect-frame bounds helper using `EFFECT%d.EPF` in current mode or `EFFECT.EPD` in legacy mode. |
| `0x004de3e0-0x004de420` | [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md) | Copies a 1-based effect descriptor, falling back to the scratch descriptor when out of range. |
| `0x004de420-0x004de7c2` | [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md) | One-caller helper that scans `EFFECT%d.EPF` shards and builds the packed archive metadata table. |
| `0x004de7d0-0x004dec23` | [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md) | Loads `EFFECT.TBL` and `EFFECT.FRM` into descriptor/remap arrays. |
| `0x004e5b70-0x004e5b7b` | [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md) | False/non-emitting compiler Singleton-base unwind clear; exact bytes/xref/padding remain binary evidence with no helper marker or API. |
| `0x004e62f0-0x004e6456` | [UID:0002HC][0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor](by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md) | False/non-emitting compiler scalar deleting wrapper generated by the virtual ordinary destructor; retains cleanup/flags/delete ABI evidence only. |

B003's 2026-06-17 cleanup audit resolves [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md) as compiler constructor-unwind glue, not a source-authored helper API. The local PE bytes are exactly `c7 05 4c b4 69 00 00 00 00 00 c3`, the body has no `this`, no callees, and only clears `g_pEffectObjImageLib`; existing docs record the constructor cleanup jump at `0x0060008a`. Do not emit a `ClearEffectObjImageLibSingleton` function; direct `Singleton<EffectObjImageLib>` inheritance is the source contract that causes this compiler helper.

B004's 2026-07-05 current MCP recheck preserves that disposition and tightens the evidence: `lookup_funcs` id `16` confirms `sub_4E5B70` is exactly `0x004e5b70-0x004e5b7b`, `xrefs_to` id `20` confirms the single cleanup xref from `0x0060008a` and the 12 singleton xrefs, `callees` id `27` reports no callees, signature ids `24`/`25` show the exact bytes are unique while the operand-wildcarded helper shape is not unique, and `get_bytes` id `28` separates the five `cc` padding bytes at `0x004e5b7b-0x004e5b80` from the exact body. This supports the `NexusTK/render/EffectObjImageLib.cpp` source route while rejecting source API names such as `ClearEffectObjImageLibSingleton` or `EffectObjImageLib::ClearSingleton`.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `EFFECT.TBL` | Effect descriptor table. Header count followed by 52-byte [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) descriptors and two variable-length 16-byte frame arrays per descriptor. |
| `EFFECT.FRM` | Frame-remap table. Header count followed by four-byte [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md) records used by `RenderEffectFrame`. |
| `EFFECT.EPF` / `EFFECT%d.EPF` | Current effect image archive inputs and numbered archive shards. |
| `EFFECT.EPD` | Legacy effect bounds/image lookup path used by `GetSpriteBounds`. |
| `EFFECT.PAL` | Palette category `11` through [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md). |

## Evidence

- IDA MCP confirms the vtable at `0x0061b724`; constructor, ordinary destructor, and scalar deleting destructor all store that vtable.
- IDA MCP confirms singleton storage [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md) as `dword_69B44C`, with constructor writes, destructor clears, application shutdown read, and effect/map consumer reads.
- IDA MCP caller checks show `RenderEffectFrame` at `0x004de190` has a modeled caller at `0x00538ba0` in the `EffectObjectPane` render path.
- IDA MCP caller checks show `BuildEffectArchiveTable` and `LoadEffectTables` are only called by the constructor.
- 2026-06-29 B002 UID0002H9 source-ready sync: MCP session `3fa0535f` confirms the constructor at `0x004ddf60-0x004de04e`, padding bytes at `0x004de04e`, one startup caller at `0x004f6113`, `EFFECT.EPF` string use, frame-count validation, fatal cleanup helpers, `MessageBoxW` strings, and `__loaddll(0)`; UID0002H9 now carries the formal constructor C++ while this file keeps other method caveats.
- IDA MCP recheck on 2026-05-31 confirms exact boundaries for constructor (`0xee` bytes), `GetEffectInfo` (`0x40` bytes), `LoadEffectTables` (`0x453` bytes), and scalar deleting destructor (`0x166` bytes).
- Historical 2026-06-16 generated-output refresh: `class_EffectObjImageLib.meta_wave3` reported no disabled companion and `vtable_count: 1`; `RenderEffectFrame` appeared but was incomplete/effectively excluded with provisional helper/member names. This checkpoint is evidence history, not current generated authority.
- 2026-06-17 B002 source-quality refresh corrected [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md) to treat `arg_18` as a caller-supplied overlay gate, not the alpha draw target. B008's 2026-06-30 callback later attached formal first-draft C++ while keeping shared callback, frame-draw-state, and alpha-surface declarations as confidence caps.
- 2026-06-30 B008 UID0000IY empty-emitter family callback supersedes the marker-only deferral for [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md), [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md), [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md), [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md), and [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md). MCP session `supervisor_resume_20260629` was healthy (`server_health` call id `3`, Hex-Rays ready), and targeted decompile call ids `6` through `17` support first-draft C++ for those five source-authored executable targets. The family disposition is source code/declaration insertions for [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md), [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md), [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md), [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md), [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md), [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md), [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md), [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md), [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md), and [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md); explicit no-code/source-form markers remain for class wrapper, scalar deleting destructor, layout, vtable, exact global storage, singleton cleanup glue, and vtable data pages.
- Historical 2026-07-05 UID00017W refresh: MCP session `supervisor_recovery_20260705` reconfirmed the exact half-open helper range, signatures, no-callee/no-ordinary-call state, cleanup xref, 12 singleton xrefs, and five excluded `cc` bytes; that callback's generated output carried a temporary no-code marker at `86/91`.
- UID0001PQ source-quality closure preserves those binary facts and completes the current union: exact loader-zero physical storage, one external global definition, one extern in the complete direct-base class, authored constructor/destructor/member/helper bodies, and false/blank compiler/data/layout/vtable/index pages. Direct Singleton PMD `+4/-1/0` explains all publication/clear effects without explicit global lifecycle source.

## Batch 012 Parent-Gate Evidence

The exact vtable-data child [UID:0002MK][0x0061b720-0x0061b730.EffectObjImageLibVtableData](by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md) is directly owned by this source module. Live IDA MCP on 2026-06-07 rechecked `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) and confirmed the `EffectObjImageLib` RTTI locator at `0x0061b720`, vtable slot dwords at `0x0061b724-0x0061b72c`, constructor/destructor/scalar-deleting-destructor vptr stores, and adjacent `ProtectedArray<EffectInfo>`, `ProtectedArray<EffectPixMapInfo>`, and `ProtectedArray<ItemInfo>` boundaries.

That evidence is enough to treat this by-file page as an `85/85` direct parent for the vtable-data child under the corrected Batch 012 assignment gate. The vtable bytes remain `source-declared/generated-binary`; this page owns the class declaration and virtual method set that should cause the rebuilt compiler/linker to emit the equivalent RTTI/vtable artifact, but the child should not contribute handwritten C++ code.

## Score Rationale

Completion is `92` because the file page now closes the complete source/compiler/global/resource union, direct hierarchy, one-definition route, exact method and helper ownership, physical/compiler exclusions, and generated contract. Confidence is `93` because all ranges, resources, direct bases, lifecycle effects, and source carriers are corroborated; stripped private names and the exact original filename remain bounded caps.

## Cross-References

- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:00017K][0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster](by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md)
- [UID:0002H9][0x004ddf60-0x004de04e.EffectObjImageLibConstructor](by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md)
- [UID:0002MK][0x0061b720-0x0061b730.EffectObjImageLibVtableData](by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md)
- [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md)
- [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md)
- [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md)
- [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md)
- [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md)
- [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md)
- [UID:0002HC][0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor](by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md)
- [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md)
- [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000IZ][Effects](by-file/Effects.md)

## Changes

- 2026-07-21 B004 UID0001PQ source-quality callback:
  - Raised `90/88` to `92/93` and preserved `NexusTK/render/` source placement, all resource inputs, every method/helper range, historical evidence, and unrelated file-family separation.
  - Added the complete `LObject, Singleton<EffectObjImageLib>` class/global/header contract, PMD `+4/-1/0` EBO, implicit publication/reverse-clear model, constructor `frameCount` correction, and one-definition order.
  - Synchronized current compiler/data exclusions: UID00017W, UID0002HC, UID0001U9, UID0001XG, UID0002MK, UID0001PQ, and UID00017K are false/blank and emit no source marker/body; authored children and file-owned helpers remain source-bearing. Historical marker/suppressed-child checkpoints remain documented as superseded evidence.

- 2026-07-05 B004 UID00017W implementation callback:
  - Score unchanged at `90/88`.
  - Summary/evidence: narrowed the UID00017W row to the exact half-open range `0x004e5b70-0x004e5b7b`, preserved `NexusTK/render/EffectObjImageLib.cpp` source placement, and incorporated current MCP/generated evidence for the no-code cleanup-glue policy. Current evidence rejects both `ClearEffectObjImageLibSingleton` and `EffectObjImageLib::ClearSingleton` as source-authored APIs while keeping UID00017W under the file owner/emitter route.
- 2026-06-30 B008 UID0000IY empty-emitter family implementation callback:
  - Changed scores from `89/86` to `90/88`.
  - Summary/evidence: incorporated the accepted B008 revised report for the `EffectObjImageLib.cpp` empty-emitter family. The callback preserves UID0002H9 constructor output, keeps source placement at `NexusTK/render/`, and records the family split between first-draft code/declarations and no-code/source-form markers. MCP session `supervisor_resume_20260629` rechecked the score-blocker targets: destructor call id `7`, renderer call ids `8`-`12` and caller call id `15`, loader call id `13`, archive builder call id `14`, and bounds helper call ids `6`, `16`, and `17`. Scoped B008 validator refreshes confirm the generated file is fresh and has no prior empty marker comments, while class-owned method child bodies remain generator-suppressed in that file. Ownership remains with this file; `Effects`, `EffectObjectPane`, `MapPane`, shared ImageLib state, ProtectedArray, and shared EPF resource docs remain consumers/support dependencies rather than source owners.
- 2026-06-29 B002 UID0002H9 implementation callback:
  - Score unchanged at `89/86`.
  - Summary/evidence: synchronized the file role, owned-method row, generated-output caveat, and evidence with the accepted UID0002H9 constructor repair. The constructor now emits first-draft `EffectObjImageLib::EffectObjImageLib()` through `NexusTK/render/EffectObjImageLib.cpp`; MCP session `3fa0535f` supplies exact range/padding, startup caller, singleton publish/fallback-clear, vtable/protected-array setup, loader/archive calls, `EFFECT.EPF`, validation, fatal cleanup helpers, `MessageBoxW` strings, and `__loaddll(0)`. The file page keeps the broader generated-output caveat and exact-original-filename/private-field confidence caps.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:84`.
  - Summary/evidence: effect image-library role, resource ownership, singleton/vtable/layout/type anchors, method/helper map, generated disabled-method caveat, asset/runtime separation, and cross-references are documented; confidence is strong with only final field names and exact original filename still medium.
- 2026-05-31 projected path and exact memory-page split:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and several method rows were text-only entries inside the broad file page.
  - Changed to: projected path `NexusTK/render/`, with exact by-memory pages linked for constructor, `GetEffectInfo`, `LoadEffectTables`, and scalar deleting destructor.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `EffectObjImageLib.cpp` under `render/`, and IDA MCP rechecked exact function sizes, callers, resource names, and core field offsets on 2026-05-31.
- 2026-06-07 A003 Batch 012 parent gate:
  - What existed before: the page was `88/84`, below the corrected direct-parent assignment gate for [UID:0002MK][0x0061b720-0x0061b730.EffectObjImageLibVtableData](by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md).
  - Changed to: `89/86`, added current hash-backed vtable ownership evidence, and documented why this source-file page directly owns the source declaration effect.
  - Summary/evidence: the source module already documents the effect image-library role, methods, singleton, resources, and layout; the Batch 012 IDA recheck closes the specific vtable-data ownership gate while leaving final field names and exact original filename below final-audit confidence.
- 2026-06-12 C001 ImageLib-family barrier repair:
  - Changed to: the broad EffectObjImageLib memory aggregate is now [UID:00017K][0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster](by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md), a non-emitting local cluster; singleton-clear and scalar-deleting destructor pages remain exact separate tails.
  - Evidence: live IDA `entity_query` on 2026-06-12 proved the old `0x004ddf60-0x004e6455` aggregate crossed ItemObjImageLib, LightObjImageLib, NewHumanImageLib, and its own exact scalar-destructor endpoint.
- 2026-06-16 A002 generated-output caveat refresh:
  - Score unchanged at `89/86`.
  - Summary/evidence: active `class_EffectObjImageLib.cpp` and `class_EffectObjImageLib.meta_wave3` were checked. The stale disabled-companion/`vtable_count: 0` wording was removed; final source confidence still stays below audit quality because method completion, `RenderEffectFrame` effective inclusion, and generated helper/member names remain unstable.
- 2026-06-17 B002 [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md) source-quality execution:
  - Score unchanged at `89/86`.
  - Summary/evidence: the file page records the corrected overlay-gate semantics that B008 later used for the formal first-draft `RenderEffectFrame` implementation. Source placement remains `NexusTK/render/EffectObjImageLib.cpp`; runtime [UID:0000IZ][Effects](by-file/Effects.md) remains a consumer module.
- 2026-06-17 B003 singleton-clear cleanup audit:
  - Score unchanged at `89/86`.
  - Summary/evidence: incorporated the no-code source-form proof for [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md): exact singleton-zero PE bytes, constructor cleanup jump evidence, no `this`, no callees, singleton-only write, file-owner route, and rejection of a handwritten clear-helper API.
