*** UID:0000N6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# RidingImageLib

## Status

- Confidence: very strong for class role, resource ownership, singleton/vtable evidence, parser/constructor/destructor/RenderRiding source route, exact five-argument rendering behavior, globals/types, and observed layout; strong for inferred original filename/member spellings.
- Proposed module: `render/RidingImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_RidingImageLib.cpp`
- Main address ranges: `0x004dc420-0x004dca14` and `0x004e68b0-0x004e6981`
- Primary global instance: [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md) at `0x0069b444`
- Primary vtable: [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md) at `0x0061b6f4`
- Global riding definition table: [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md) at `0x0069b430`

## File Role

`RidingImageLib` is the riding/mount sprite library. It owns the `RIDINGS.DNA` definition parser, the per-riding bucket/group tables, and the `RIDINGS.EPF` frame-table package used for riding sprite rendering.

This should remain a separate render/image module. It depends on shared DAT and EPF frame-table code, but the DNA schema, singleton global, riding definition lifetime, and default bucket seeding are riding-specific.

[UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibRenderRiding](by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md) is retained project source in this root, despite having no surviving direct entry route. Its exact void thiscall ABI is RidingImageLib plus `GrafPort *`, `const RectBounds *`, `const ObjectStatusBlob *`, animation group, and animation frame. It selects a 12-byte RidingDefinition through unsigned-16 appearance wrapping, preserves two shared GetFrame calls, performs signed-low-16 `RIDINGS.EPF` lookup, constructs destination bounds, and preserves all projection/clipping branches before calling the scaled RLE tint callback.

## Owned Helpers And Shared Dependencies

[UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md) is constructor-only. It reads the riding count, allocates the definition array, pre-seeds 21 default bucket groups with a `0..30000` range, then reads each riding definition and its nested bucket entries from `RIDINGS.DNA`.

The constructor calls [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) at `0x004d0f50` for `RIDINGS.EPF`. The current generated source names that callee `OpenResourcePackage`, but IDA MCP identifies the target as the shared EPF frame-table loader.

The bucket/group allocation helpers near `0x005289d0` and `0x00528be0` are shared with the monster image-library table family and should not be made riding-only without a separate helper-class review. The [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md) page records the `0x0c` definition rows, 8-byte bucket rows, and 10-byte bucket-entry rows parsed from `RIDINGS.DNA`.

See [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) for the current shared helper-class documentation.

B003's 2026-06-17 cleanup audit resolves the ordinary destructor source-form decision for [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md). The body should emit first-draft `RidingImageLib::~RidingImageLib()` through this file, freeing `ridingEpfPackage` and its `ArchiveMetadataTable::records`, destroying `ridingDefinitions` with the source-facing `DestroyRidingDefinitionArray` alias, freeing that allocation with `FreeRidingDefinitionArray`, and clearing `g_pRidingImageLib`. The audit rejects leaving the destructor blank merely because the vector helper spelling is inferred: the helper aliases are bounded but the class ownership, field roles, resource cleanup, singleton clear, and scalar-wrapper parity are strong enough for first-draft C++.

## IDA-Confirmed Supplemental Bodies And Data

| Range | Body/Data | Role |
| --- | --- | --- |
| `0x004dc420-0x004dc68d` | [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md) | Constructor-only `RIDINGS.DNA` parser and riding-definition table loader. |
| `0x004dc690-0x004dc722` | [UID:0002Y0][0x004dc690-0x004dc722.RidingImageLibConstructor](by-memory/0x004dc690-0x004dc722.RidingImageLibConstructor.md) | Singleton constructor; initializes the base/vtable, publishes `g_pRidingImageLib`, loads `RIDINGS.DNA`, and opens `RIDINGS.EPF`. |
| `0x004dc730-0x004dc7d8` | [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md) | Frees the `RIDINGS.EPF` package, destroys the riding definition vector, calls `LObject` cleanup, and then clears the singleton. |
| `0x004dc7e0-0x004dca14` | [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibRenderRiding](by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md) | Retained source-ready `RidingImageLib::RenderRiding`; exact `0x234`/564-byte five-argument body resolves definition/frame state, loads `RIDINGS.EPF`, performs branch-exact rectangle/projection math, and dispatches scaled RLE tint. |
| `0x004e5bf0-0x004e5bfb` | [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md) | Clears `g_pRidingImageLib`. |
| `0x004e68b0-0x004e6981` | [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md) | Compiler-generated, false/non-emitting primary-vtable wrapper. It duplicates/inlines UID00017G cleanup rather than calling it, clears `g_pRidingImageLib`, applies `(flags & 1) != 0 && (flags & 4) == 0` optional storage release, and returns `this`; the class virtual declaration and ordinary destructor are the sole source carriers. |
| `0x0069b430-0x0069b43c` | [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) | `MonsterImageLibTable_5289D0`-shaped global table seeded by `LoadRidingDefinitions`. |
| `0x0069b444-0x0069b448` | [UID:0001PO][0x0069b444-0x0069b448.g_pRidingImageLib](by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md) | Runtime pointer to the riding image-library singleton. |

## Parent-Gate Evidence

This page now clears the strict parent gate for the riding-definition global table and the singleton cleanup helper. The concrete global page [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md) is riding-specific storage, while [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) remains the shared helper implementation owner. The direct riding evidence is the `RIDINGS.DNA` parser child [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md), the exact default table storage [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md), the riding singleton [UID:0001PO][0x0069b444-0x0069b448.g_pRidingImageLib](by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md), the static-lifetime clear helper [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md), and the `RIDINGS.EPF`/`RIDINGS.DNA` resource pair. Confidence remains capped below final-source confidence because final helper type/field names and the exact original filename are still provisional.

## 2026-06-14 IDA MCP Refresh

- `lookup_funcs` reconfirms the current split: parser `0x004dc420` size `0x26d` (`621` bytes), constructor `0x004dc690` size `0x92`, ordinary destructor `0x004dc730` size `0xa8`, raw draw helper `0x004dc7e0` is still not an IDA function, successor helper `0x004dca20` size `0x23`, singleton clear helper `0x004e5bf0` size `0x0b`, and scalar deleting destructor `0x004e68b0` size `0xd1`.
- `xrefs_to` confirms constructor-only parser reachability (`0x004dc420` only from `0x004dc6f5` in `sub_4DC690`), constructor startup reachability from `0x004f60ed` inside `sub_4F5FB0`, no direct refs to raw draw helper `0x004dc7e0`, the scalar deleting destructor vtable data ref at `0x0061b6f4`, and the singleton clear helper jump/reference from constructor cleanup at `0x005fff4c`.
- `xrefs_to 0x0069b444` returns 20 singleton refs spanning constructor/destructor, static clear, render/image consumers, and cleanup paths; `xrefs_to 0x0061b6f4` returns constructor/destructor/scalar-destructor vtable refs; `xrefs_to 0x0069b430` and `0x0069b438` reconfirm the riding-definition global table and parser access.
- `callees` confirms the parser calls the shared monster table helpers `0x005289d0` and `0x00528be0`, the constructor calls `LObject` construction, the parser, and `0x004d0f50` frame-table loading, and both destructor forms call shared frame-table/list cleanup plus `LObject` cleanup. This supports the current ownership split: RidingImageLib owns the riding-specific parser/singleton/source root, while shared table helpers stay with [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md).

## Resource Inputs

| Resource | Role |
| --- | --- |
| `RIDINGS.DNA` | Riding definition table: riding id, bucket count/default bucket, animation group, and nested frame bucket entries. |
| `RIDINGS.EPF` | Riding/mount sprite frame archive loaded through the shared EPF frame-table loader. |

## 2026-06-30 B008 Empty-Emitter Source-Quality Callback (Historical)

B008's accepted empty-emitter family report kept this page as the `NexusTK/render/RidingImageLib.cpp` source root and raised the file score to `90/90`. Before that callback, generated `auto-generated/NexusTK/render/RidingImageLib.cpp` contained first-draft [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md) plus 15 empty markers. That historical disposition converted the markers into source declarations/bodies, compiler proof comments, or explicit non-emitting support pages. The UID0002Y4 proof-comment decision is superseded below; its valid binary and ownership evidence remains retained.

| UID | Callback disposition |
| --- | --- |
| [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md) | Historically emitted the class shell, globals, lifecycle/parser declarations, fields, and `[[CHILDREN]]`; current R2 additionally declares retained `RenderRiding` while preserving all of those elements. |
| [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md) | Emits first-draft `RidingImageLib::LoadRidingDefinitions` using accepted shared `ImageAnimationTable`, `ImageAnimationGroup`, and `ImageAnimationFrame` names. |
| [UID:0002Y0][0x004dc690-0x004dc722.RidingImageLibConstructor](by-memory/0x004dc690-0x004dc722.RidingImageLibConstructor.md) | Emits first-draft constructor source for singleton publish, parser call, and `RIDINGS.EPF` load. |
| [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md) | Reclassified as non-emitting split/container support; exact child pages carry source or no-code proofs. |
| [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibRenderRiding](by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md) | Historical blank-emitter decision is superseded. Current evidence recovers the complete five-argument ABI from `retn 0x14`/stack flow and an exact modeled RenderMonster sibling/caller; the retained member now emits through UID0000BZ. No function object/direct refs remain valid negative route evidence. |
| [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md) | Historical B008 state emitted a compiler-wrapper proof comment. Current state is `93/96`, compiler-generated, false, and non-emitting with blank CPP/H; source cleanup remains [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md), and the virtual class declaration causes the wrapper during compilation. |
| [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md) | Emits riding-specific POD/alias declarations while keeping the shared helper implementation with [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md). |
| [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md), [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md), [UID:00031E][0x0061b6f0-0x0061b700.RidingImageLibVtableData](by-memory/0x0061b6f0-0x0061b700.RidingImageLibVtableData.md) | Emit covered-by/compiler proof comments rather than duplicate layout or hand-authored vtable data. |
| [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md), [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) | Emit `ImageAnimationTable g_ridingDefinitionGroups;` and storage proof. Current MCP reads zero-filled storage, superseding stale all-`0xff` wording. |
| [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md), [UID:0001PO][0x0069b444-0x0069b448.g_pRidingImageLib](by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md) | Emit `RidingImageLib *g_pRidingImageLib = NULL;` and storage proof. Current MCP reads NULL/zero-filled storage, superseding stale `0xffffffff` wording. |
| [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md) | Reclassified as non-emitting cleanup support; source-visible lifetime is covered by constructor/destructor/global state. |

Current MCP evidence preserves the parser's sole constructor call, constructor startup route, UID0002Y1's absent function object/direct refs, singleton-clear behavior, scalar-wrapper vtable route, and zero-filled global storage. For UID0002Y1, the no-route facts no longer imply no code: the whole target hash is `0BF8FB87444BB45BAAB43BA1FA3DF6268EA666AD6E353D0450CBF29D524D6EDD`, all 169 instructions decode, `retn 0x14` proves five stack arguments, and the full RenderMonster control-flow sibling has a concrete LivingObjectPane caller.

Do not move the shared `ImageAnimationTable` helper implementation into RidingImageLib. That helper source remains owned by [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md); RidingImageLib owns the concrete `RIDINGS.DNA` parser, riding definition declarations, default riding table storage, singleton, and resource package lifecycle. The optional exact helper split for `0x004dca20-0x004dca43` remains deferred by supervisor instruction; existing NewHuman docs already use the source-facing name `RidingImageLib::GetDefinitionOrDefault`.

## 2026-07-14 RenderRiding Source And Compiler Disposition

- `RidingImageLib.cpp` remains the exact source root: target receiver fields `+0x04/+0x08`, `RIDINGS.EPF`, and surrounding class lifecycle exclude MonsterImageLibTables, Surface, MapPane, ResourceLayoutTable, EPFTileContext, and LivingObjectPane ownership.
- The modeled `MonsterImageLib::RenderMonster` sibling is source-factorization evidence, not a reason to move target code. Both preserve duplicate GetFrame calls, exact rectangle/projection thresholds, and the same callback argument order; only resource/archive resolution differs.
- `g_pfnBlitScaledRleTint` and `g_activeMapPane` remain global dependencies. Callback slot 4 is void with GrafPort receiver, EPFTileContext, source/destination rectangles, mode, float tint, row offset, vertical scale, and horizontal shear. MapPane `+0x3d0/+0x3d4/+0x3d8` supply tint/divisor-or-scale/shear.
- Security cookie, SSE/register staging, vtable/RTTI storage, scalar-deleting flags, and return-pop lowering remain compiler output and are not handwritten in this file.
- Parent UID00017F remains a non-emitting exact range index. UID0001CM remains the shared GetFrame implementation. UID0001VV now supplies only the riding-specific declaration/aliases needed by this source.
- The source-root score is `91/92`; exact original filename casing, RenderRiding/access spelling, retained-linker cause, and final MapPane member spellings remain explicit confidence caps.

## 2026-08-11 UID0002Y4 Compiler-Wrapper Resolution

- Exact binary identity: `0x004e68b0-0x004e6981`, 209 bytes, 80 instructions, 13 basic blocks, SHA256 `A430FEB2B89FD946C458630446577831E24D9AF6E51CB692D52DAE1394670E2A`. Fifteen `0xcc` bytes follow through `0x004e6990`, so no split or range extension is required.
- Reachability and ownership: the wrapper has one inbound reference, primary-vtable data slot `0x0061b6f4`, and zero ordinary code callers. That slot points to the wrapper and is associated with vtable writes at `0x004dc6e9`, `0x004dc75a`, and `0x004e68e1`; semantic ownership therefore remains RidingImageLib.
- Behavior: the wrapper inlines the ordinary destructor's package release, 12-byte `ImageAnimationTable` array destruction, array-allocation release, `LObject` cleanup, and singleton clear. It does not call `0x004dc730`. Compiler-only lowering then releases object storage only when `(flags & 1) != 0 && (flags & 4) == 0`; the bit-4 route passes size 16 through the one-byte guard no-op at `0x0041b6a0`; EAX returns `this`.
- Source disposition: UID0002Y4 is false/non-emitting and contributes no body, declaration, or proof comment to `RidingImageLib.cpp`. `virtual ~RidingImageLib();` and UID00017G `RidingImageLib::~RidingImageLib()` remain the sole human source carriers. Shared `ImageAnimationTable` destruction and array-release helpers remain with the MonsterImageLibTables/runtime support family rather than moving into this file.
- Historical reconciliation: B008's exact range, class ownership, cleanup parity, singleton clear, optional-delete conclusion, and no-hand-written-wrapper conclusion remain accepted. Its reconstructable/class-emitter/proof-comment route and any wording that implies a call to UID00017G are superseded.

## 2026-08-16 Complete CPP/H Ownership Route

[UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md) now supplies both formal channels for this source root. The CPP channel contains only `#include "RidingImageLib.h"` followed by `[[CHILDREN]]`, so every existing method/global definition remains in its established order and no class or extern declaration is duplicated in `RidingImageLib.cpp`.

The H channel is the sole complete guarded declaration: `../util/LObject.h`, exact forward declarations, constructor/virtual destructor, `LoadRidingDefinitions`, five-argument `RenderRiding`, `GetDefinitionOrDefault`, the three private fields, and both externs. `friend class NewHumanImageLib;` occurs immediately before the private fields and legalizes exactly the two UID0002V8 reads of `ridingEpfPackage` at `+0x0c`. No public-field change, broad friendship, accessor, second header, child reorder, score change, or compiler-wrapper emission is introduced.

Generated `NexusTK/render/RidingImageLib.cpp` must include the owner H, retain all child method/global definitions once, and contain no class/extern redeclaration. Generated `RidingImageLib.h` must contain the complete declaration and narrow friend placement once. The file score remains `91/92`; UID0000BZ's declaration closure is `92/94`.

## Cross-References

- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)
- [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md)
- [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md)
- [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md)
- [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md)
- [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md)
- [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md)
- [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md)
- [UID:0002Y0][0x004dc690-0x004dc722.RidingImageLibConstructor](by-memory/0x004dc690-0x004dc722.RidingImageLibConstructor.md)
- [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibRenderRiding](by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md)
- [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-08-16 B001 ResourceLayoutTable whole-file implementation: file score unchanged at `91/92`. Recorded the complete owner CPP/H route, one-header/one-class/one-extern contract, preserved child order, and narrow NewHuman friendship over private `ridingEpfPackage`; retained all resource, layout, lifecycle, RenderRiding, and compiler-wrapper evidence.

- 2026-08-11 B006 UID0002Y4 source-quality callback:
  - Reconciled the supplemental inventory and historical B008 table to the target's current `93/96`, false, non-emitting disposition.
  - Preserved the exact 209-byte compiler-wrapper behavior and semantic RidingImageLib source family while removing active proof-comment/body routing.
  - Corrected the cleanup relationship to duplicated inline parity, retained UID00017G and the class virtual declaration as sole source carriers, and kept shared helper source under MonsterImageLibTables/runtime ownership.

- 2026-07-14 B003 UID0002Y1 source-quality callback:
  - Raised `90/90` to `91/92` with the existing `NexusTK/render/` route unchanged.
  - Replaced current raw/no-emitter inventory with retained source-ready `RidingImageLib::RenderRiding`, exact five-argument ABI, definition/GetFrame/resource/rectangle/projection/callback behavior, sibling factorization, shared-helper ownership, compiler exclusions, negative routes, and source-placement rationale.
  - Historicalized the B008 no-code conclusion while preserving all parser, constructor, destructor, scalar-wrapper, singleton/global, vtable/layout, optional successor-helper, and resource history.

- 2026-06-07 A005 Batch 047 split recheck sync:
  - Kept `85/85` but replaced the pending raw-helper/scalar-destructor rows with exact child links and updated the parser endpoint to `0x004dc68d`.
  - Evidence: A005 live IDA checks confirm the early cluster `0x004dc420-0x004dca14` and the separate scalar deleting destructor `0x004e68b0-0x004e6981`.
  - Assignment effect: supports the refreshed [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md) `85/86` parent gate and the new exact child assignments.

- 2026-06-06: Corrected the scalar deleting destructor endpoint to `0x004e6981` and added it to the supplemental body table.
  - Before: the main range ended at `0x004e6980`, which is still inside `sub_4E68B0`.
  - After: the page records the half-open `0x004e68b0-0x004e6981` range and links the renamed RidingImageLib aggregate.
  - Evidence: A002 IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, and `decompile` checks for the scalar deleting destructor and `RidingImageLib` vtable/global references.

- 2026-06-06: Added the IDA-missed raw draw-frame helper at `0x004dc7e0-0x004dca14` to the supplemental body table.
  - Before: the page's main range ended at the constructor/destructor neighborhood and did not account for the executable raw helper between the ordinary destructor and `sub_4DCA20`.
  - Historical after-state at that time: the main range and supplemental table included the raw helper while exact child-page promotion remained pending validator registration. Current state supersedes that blocker with registered UID0002Y1 `RidingImageLibRenderRiding` at `0x004dc7e0-0x004dca14`.
  - Evidence: A002 IDA MCP raw disassembly/call/data-ref pass found the helper's `RIDINGS.EPF` frame lookup, `OffsetRect` calls, `dword_69B3F0` dispatch, stack-cookie epilogue, and padding boundaries.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `80`.
  - Evidence: document covers role, resource inputs, singleton/global/vtable anchors, IDA-confirmed supplemental bodies, shared helper dependencies, layout/type cross-references, and source placement; confidence remains below strong because final original filename and nested field names are still medium-confidence.

- 2026-05-31: Set the proposed reconstruction path and linked the exact parser child page.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and `LoadRidingDefinitions` was referenced by address only.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, matching `render/RidingImageLib.cpp` in the proposed source tree, and parser references point to [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md).
  - Evidence: `by-project-structure/proposed-source-tree.md` places `RidingImageLib.cpp` under `render/`; IDA MCP confirms `0x004dc420-0x004dc68d` is the constructor-only `RIDINGS.DNA` parser owned by `RidingImageLib`.
- 2026-06-07 A002 Batch 042 parent-gate refresh:
  - Before: `COMPLETION:84` and `CONFIDENCE:80`.
  - After: `COMPLETION:85` and `CONFIDENCE:85`.
  - Evidence: existing exact docs now connect the riding-specific parser, global default table, singleton slot, resource inputs, destructor/singleton-clear evidence, vtable evidence, and shared-helper exclusion strongly enough for the strict parent gate. Scores remain deliberately capped because the raw draw-frame helper child is still pending new-file registration and final field/helper names are unresolved.
- 2026-06-08 A003 Batch122: Added explicit parent-gate support for [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md).
  - Before: the file listed the clear helper but did not state that the helper now clears the corrected `85/85` gate against this source root.
  - After: parent-gate evidence records the helper as direct by-file static-lifetime cleanup glue alongside the singleton global and destructor lifecycle.
  - Evidence: Batch122 IDA recheck on `0x004e5bf0` and `0x0069b444` reconfirmed the exact body, constructor cleanup jump, singleton lifecycle xrefs, and neighboring helper boundary.
- 2026-06-14 C001 Goal2 score refresh:
  - Before: score `85/85`.
  - Changed to: score `87/88`.
  - Summary/evidence: live IDA MCP reconfirmed parser/constructor/destructor/scalar-destructor/helper boundaries, raw draw helper non-function status, constructor-only parser reachability, startup constructor callsite, singleton/vtable/global-table xref counts, and callee separation between riding-owned parser/lifecycle code and shared monster-table/frame-table dependencies. No owner/emitter routing changed; exact final field names and original filename remain the main blockers to a higher score.
- 2026-06-17 B003 RidingImageLib cleanup/source-quality support update:
  - Score unchanged at `87/88` for the file root.
  - Summary/evidence: incorporated the B003 ordinary-destructor source-form audit for [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md). The exact child should emit first-draft `RidingImageLib::~RidingImageLib()` using `ridingEpfPackage`, `ArchiveMetadataTable::records`, `ridingDefinitions`, `ridingDefinitionCount`, `DestroyRidingDefinitionArray`, `FreeRidingDefinitionArray`, and `g_pRidingImageLib`, while helper spellings remain bounded inferred names rather than blockers.
