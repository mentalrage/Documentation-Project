*** UID:0000BZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "RidingImageLib.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_RENDER_RIDINGIMAGELIB_H
#define NEXUSTK_RENDER_RIDINGIMAGELIB_H

#include "../util/LObject.h"

struct ArchiveMetadataTable;
struct ImageAnimationTable;
struct ImageAnimationGroup;
struct ImageAnimationFrame;
struct RidingDefinition;
struct ObjectStatusBlob;
struct RectBounds;
class GrafPort;
class NewHumanImageLib;

class RidingImageLib : public LObject
{
public:
    RidingImageLib();
    virtual ~RidingImageLib();

    void LoadRidingDefinitions();
    void RenderRiding(
        GrafPort *target,
        const RectBounds *bounds,
        const ObjectStatusBlob *objectStatus,
        unsigned int animationGroup,
        unsigned int animationFrame);
    const RidingDefinition *GetDefinitionOrDefault(
        unsigned int ridingDefinitionIndex) const;

private:
    friend class NewHumanImageLib;
    RidingDefinition *ridingDefinitions;
    unsigned int ridingDefinitionCount;
    ArchiveMetadataTable *ridingEpfPackage;
};

extern RidingImageLib *g_pRidingImageLib;
extern ImageAnimationTable g_ridingDefinitionGroups;

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RidingImageLib

## Status

- Confidence: very strong for method roles, singleton/vtable evidence, observed layout offsets, and the complete RenderRiding ABI/body; strong for inferred source-facing spellings.
- Likely source file: [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- Address ranges: [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md) plus [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_RidingImageLib.cpp`
- Singleton: [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md) at `0x0069b444`
- Vtable: [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md) at `0x0061b6f4`
- Parent/C++ status: reconstructable and attached to the owning [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) source root. The CPP shell includes `RidingImageLib.h` and emits `[[CHILDREN]]`; the complete guarded class/API/field/extern declaration lives once in formal H. Source-bearing child pages provide method/global definitions. [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md) is retained only as non-emitting compiler-wrapper evidence and contributes neither a proof comment nor a body.

## Class Purpose

`RidingImageLib` is the singleton-backed riding/mount image library behind `g_pRidingImageLib`. It loads the mount animation/definition data from `RIDINGS.DNA`, loads the `RIDINGS.EPF` image frame table, and owns the lifetime of both resources.

## Observed State

```text
0x00  LObject/vtable base
0x04  RidingDefinition* riding definitions
0x08  uint32 riding definition count
0x0c  RIDINGS.EPF frame-table/package handle
```

`RidingDefinition` contains a riding id, bucket count, default bucket index, animation group id, and nested frame buckets. Each bucket entry stores frame range/stride plus direction, palette, and effect fields. See [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md) and [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md) for current offsets.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `LoadRidingDefinitions` | [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md) | Reads `RIDINGS.DNA`, allocates definition/bucket arrays, and fills nested riding bucket entries. |
| `RidingImageLib::RidingImageLib` | [UID:0002Y0][0x004dc690-0x004dc722.RidingImageLibConstructor](by-memory/0x004dc690-0x004dc722.RidingImageLibConstructor.md) | Sets `g_pRidingImageLib`, initializes the base/vtable, calls `LoadRidingDefinitions`, and loads `RIDINGS.EPF`. |
| `RidingImageLib::~RidingImageLib` | `0x004dc730` | Ordinary non-deleting destructor; frees `RIDINGS.EPF`, destroys riding definitions, calls `LObject` cleanup, and clears the singleton. |
| `RidingImageLib::RenderRiding` | [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibRenderRiding](by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md) | Retained source member with exact five-argument ABI; resolves appearance/definition/frame through the shared GetFrame helper, loads `RIDINGS.EPF`, preserves branch-exact rectangle/projection behavior, and calls scaled-RLE-tint slot 4. |
| `ClearRidingImageLibSingleton` | `0x004e5bf0` | Tiny helper that clears `g_pRidingImageLib`; no direct callers currently modeled. |
| `DeletingDestructor` | [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md) | Compiler-generated, false/non-emitting primary-vtable wrapper. It duplicates/inlines the [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md) cleanup rather than calling it, then applies `(flags & 1) != 0 && (flags & 4) == 0` optional storage release, traverses the bit-4 guard no-op path, and returns `this`. The virtual declaration and ordinary destructor are the sole human source carriers. |

IDA MCP on 2026-05-22 confirms `LoadRidingDefinitions` has only the constructor as an executable caller, and the constructor has one startup caller at `0x004f60ed`. IDA MCP on 2026-05-26 confirms the vtable at `0x0061b6f4`, singleton storage at `0x0069b444`, the ordinary destructor at `0x004dc730`, and the singleton clear helper at `0x004e5bf0`.

Current IDA MCP confirms retained `RenderRiding` still has no function object or direct entry xrefs, but the exact `0x234`/564-byte, 169-instruction body is bounded by parent-only `0xcc` padding at `0x004dc7d8-0x004dc7e0` and `0x004dca14-0x004dca20`. Whole-body SHA256 is `0BF8FB87444BB45BAAB43BA1FA3DF6268EA666AD6E353D0450CBF29D524D6EDD`; a cookie-protected epilogue and `retn 0x14` prove a standalone member body with five stack arguments.

The physical ABI is `void` thiscall: RidingImageLib in ECX, followed by `GrafPort *target`, `const RectBounds *bounds`, `const ObjectStatusBlob *objectStatus`, unsigned animation group, and unsigned animation frame. `objectStatus->m_appearanceId + 0x8000` wraps through unsigned 16 bits to select a 12-byte RidingDefinition. The body calls the shared GetFrame helper twice with the same group/frame; it uses the first result's `frameOffset` and deliberately preserves the second discarded call because modeled `MonsterImageLib::RenderMonster` contains the same sequence.

After rejecting a negative frame index, the member initializes EPFTileContext and performs `g_pEPFLib->LookupLayoutEntry(L"RIDINGS.EPF", static_cast<short>(frameIndex), ...)`, then constructs destination bounds from caller left/top plus exact source width/height. It preserves the post-lookup group-zero gate, source-bottom thresholds `< -4` and `> 5`, centered suppression, both OffsetRect formulas, clipping behavior, and the branch-local active-map null check. Slot `g_pfnBlitScaledRleTint` receives mode `3`, MapPane `+0x3d0` float tint, row offset `0`, and either fixed `1.5f/0.0f` or MapPane `+0x3d4/+0x3d8` vertical scale/horizontal shear.

Modeled `RenderMonster` at `0x004db100` is an instruction/control-flow-equivalent source sibling except for archive resolution, and its sole LivingObjectPane caller establishes the same source argument order and void return. The common definition sequence has exactly two matches; the target's RIDINGS lookup is unique. These facts supersede the old conclusion that no entry route required blank C++, while retaining the no-function/no-xref facts as source-name and reachability confidence caps.

IDA MCP on 2026-06-06 also confirms the scalar deleting destructor is `0x004e68b0-0x004e6981` half-open: `lookup_funcs` reports size `0xd1`, `0x004e6980` still resolves inside `sub_4E68B0`, and `0x004e6981` falls outside the function before the next modeled function at `0x004e6990`.

2026-06-17 B003 image-library cleanup audit resolves the ordinary destructor code-entry question: [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md) now emits first-draft `RidingImageLib::~RidingImageLib()` using `ridingEpfPackage`, `ridingDefinitions`, `ridingDefinitionCount`, and source-facing array destroy/free aliases. The scalar deleting destructor remains compiler wrapper glue and should stay blank in formal C++.

## 2026-06-30 B008 Source-Quality Callback (Historical)

This historical callback treated the class as the direct source owner for the RidingImageLib constructor, parser, ordinary destructor, scalar-wrapper proof, layout, vtable artifact proof, and riding-specific definition declarations. The class C++ block remains intentionally a source shell rather than a decompiler layout dump: it declares the three observed fields at `+0x04`, `+0x08`, and `+0x0c`, the singleton/global table externs, `LoadRidingDefinitions`, and the accepted source-facing lookup helper name `GetDefinitionOrDefault`. The scalar-wrapper proof-output portion of that decision is superseded by the 2026-08-11 resolution below.

The `[[CHILDREN]]` marker is deliberate. Exact source-bearing child pages emit the parser, constructor, ordinary destructor, layout/type declarations, and global declarations. The historical scalar-wrapper proof comment no longer emits because [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md) is compiler-generated and false/non-emitting. The broad [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md) no longer emits because it is only a split/container page.

The optional `0x004dca20-0x004dca43` split was not created in this callback per supervisor instruction. The class declaration keeps `GetDefinitionOrDefault` because B014 and current decompilation support the name and behavior, but the exact child page remains a deferred support plan until a future UID workflow creates it.

Rejected alternatives preserved from the historical report: do not move shared `ImageAnimationTable` helper implementation under RidingImageLib or hand-emit vtable storage. The old instruction not to model the no-xref body is superseded by UID0002Y1's exact ABI and RenderMonster factorization; no-route evidence remains bounded negative evidence rather than a no-code gate.

## 2026-07-14 RenderRiding Source-Quality Resolution

- The complete managed declaration above is the accepted class source shape. Forward declarations for GrafPort, RectBounds, and ObjectStatusBlob make the RenderRiding interface source-legal without altering the exact 0x10 object layout.
- Class fields remain exactly `ridingDefinitions` at `+0x04`, `ridingDefinitionCount` at `+0x08`, and `ridingEpfPackage` at `+0x0c`; no raw audit offsets or compiler machinery are emitted.
- The class closes before `[[CHILDREN]]`, so exact parser/constructor/destructor/RenderRiding/type/global child output remains at namespace scope.
- UID0001CM remains the single shared GetFrame implementation. RidingDefinition only declares the callable member; this class does not duplicate the shared body.
- Direct field loads of MapPane render state by RidingImageLib, MonsterImageLib, and NewHumanImageLib support public render-state fields or equivalent inlined public access. Protected-only access is impossible for these unrelated classes; per-class friendship and invented out-of-line getters are weaker source models.
- The class score is `91/92`: complete method inventory, retained body, ABI, dependencies, source route, and declaration are resolved. Exact original RenderRiding/access spelling, retained-route cause, and final render-field spellings remain inference caps.

## 2026-08-11 B006 Scalar-Wrapper Resolution

[UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md) is the exact half-open `0x004e68b0-0x004e6981` compiler scalar deleting wrapper: 209 bytes, 80 instructions, 13 basic blocks, and SHA256 `A430FEB2B89FD946C458630446577831E24D9AF6E51CB692D52DAE1394670E2A`. It has one inbound reference, the data xref from primary vtable slot `0x0061b6f4`, and no ordinary code caller. The slot is associated with constructor/destructor/wrapper vtable writes at `0x004dc6e9`, `0x004dc75a`, and `0x004e68e1`.

The wrapper does not call the ordinary destructor at `0x004dc730`. It duplicates that cleanup inline: release the `RIDINGS.EPF` package payload and handle, destroy the `this+0x04` array as 12-byte `ImageAnimationTable` elements, release the array allocation, run `LObject` cleanup, and clear `g_pRidingImageLib`. It then performs compiler-only deletion lowering: storage is released only when `(flags & 1) != 0 && (flags & 4) == 0`; the bit-4 path passes size 16 through the one-byte no-op guard at `0x0041b6a0`; and EAX returns the receiver.

The current source-quality disposition is `93/96`, `CANONICAL_OWNER:0000BZ`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/CPP/H, with the target's existing `Nested:-4` preserved. Semantic class ownership is exact, but no separate authored source exists. `virtual ~RidingImageLib();` in this class and [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md) ordinary destructor C++ are the only source carriers; recompilation regenerates the wrapper. The former proof-comment emitter route and any implication that the wrapper calls UID00017G are retained only as superseded historical assumptions.

## 2026-08-16 Header Ownership And Friendship Closure

The former CPP-local class and extern declarations are historical source placement. `RidingImageLib.cpp` now includes the complete owner H and retains all existing method/global children in their established source order; it contains no duplicate class or extern declaration. `RidingImageLib.h` owns the guard, `LObject` include, exact forwards, complete API, three exact private fields, and both extern declarations.

`friend class NewHumanImageLib;` appears immediately before `ridingDefinitions`, `ridingDefinitionCount`, and `ridingEpfPackage`. That narrow route legalizes the two direct UID0002V8 reads of private `ridingEpfPackage` at `+0x0c`, matching the binary, without making storage public or inventing an accessor. Completion/confidence rise from `91/92` to `92/94`; physical layout, methods, globals, children, wrapper disposition, and every prior evidence row remain unchanged.

## Cross-References

- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md)
- [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md)
- [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md)
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
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-08-16 B001 ResourceLayoutTable whole-file implementation: raised `91/92` to `92/94`. Moved the complete guarded class/API/field/extern declaration from the CPP shell into formal H, added the exact `LObject` dependency and narrow NewHuman friendship before private storage, and reduced formal CPP to `#include "RidingImageLib.h"` plus `[[CHILDREN]]`. Preserved all existing child definitions/order, physical layout, singleton/global evidence, and compiler-wrapper disposition.

- 2026-08-11 B006 UID0002Y4 source-quality callback:
  - Reclassified the scalar deleting destructor support route as compiler-generated, false, and non-emitting while preserving exact class ownership, binary behavior, vtable evidence, and the historical B008 conclusion that no hand-written wrapper body exists.
  - Removed active proof-comment/emitting-child language, corrected the ordinary-destructor relationship from a call to duplicated inline cleanup, and retained `virtual ~RidingImageLib();` plus UID00017G as the sole source carriers.
  - Recorded the exact 209-byte/hash/vtable/xref/flag/no-op facts and current target `93/96` disposition without changing this class's formal C++ or metadata.

- 2026-07-14 B003 UID0002Y1 source-quality callback:
  - Raised `89/90` to `91/92` and installed the accepted complete class declaration with `RenderRiding`, all existing fields/methods/globals, class closure, and `[[CHILDREN]]` preserved.
  - Synchronized the renamed retained member, five-argument ABI, appearance/definition/GetFrame flow, RIDINGS.EPF lookup, exact rectangle/projection branches, callback contract, RenderMonster sibling, source ownership, negative routes, compiler exclusions, and lexical confidence caps.
  - Historicalized the former no-route no-code decision while preserving all unrelated parser, constructor, destructor, singleton, global, vtable, layout, scalar-wrapper, and optional successor-helper facts.

- 2026-06-07 A005 Batch 047 parent-gate refresh:
  - Before: `83/82`, with the raw draw helper still pending exact child registration and the main memory reference overbroad.
  - After: `85/86`; the parser endpoint is corrected, constructor/raw-helper/scalar-destructor exact child pages are linked, and the old broad memory page was narrowed to [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md).
  - Evidence: A005 live IDA boundary checks plus existing singleton/vtable/layout/resource docs now cover the class method inventory enough for the corrected parent gate.
  - Assignment effect: direct parent now satisfies `85/85` for [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md), [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md), [UID:0002Y0][0x004dc690-0x004dc722.RidingImageLibConstructor](by-memory/0x004dc690-0x004dc722.RidingImageLibConstructor.md), [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibRenderRiding](by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md), and [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md).

- 2026-06-17 B003 image-library cleanup audit:
  - Class score unchanged, but [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md) is now `87/91` with first-draft ordinary destructor C++.
  - Evidence: package/table free sequence, `ridingDefinitions` vector destruction, source-facing helper aliases, singleton clear, ordinary/scalar destructor parity, and local PE start-byte confirmation.

- 2026-06-06 A008:
  - Before: the class met the 80/80 parent gate but remained unassigned, leaving child items such as [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md) and [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md) with an unknown autogen parent chain.
  - After: changed completion/confidence to `83/82`, set `AUTOGEN_PARENT_UID` to [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md), and documented that final class C++ remains blank pending a final naming/layout pass.
  - Evidence: [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) already has a valid `NexusTK/render/` source root and `84/80` scores, while this class page records the singleton, vtable, layout offsets, parser, ordinary destructor, raw draw-frame helper, singleton-clear helper, and scalar deleting destructor evidence.

- 2026-06-06: Corrected the scalar deleting destructor range to `0x004e68b0-0x004e6981`.
  - Before: the class inventory only listed the destructor start and linked to the aggregate under the stale `0x004e6980` endpoint.
  - After: the method table records the exact half-open scalar deleting destructor range and references the renamed aggregate.
  - Evidence: A002 IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, and `decompile` checks for `sub_4E68B0`, vtable slot `0x0061b6f4`, and singleton clear `0x0069b444`.

- 2026-06-06: Added the raw draw-frame helper `0x004dc7e0-0x004dca14` to the method inventory.
  - Before: the class documented loading/lifetime helpers but omitted the executable raw body between the ordinary destructor and `sub_4DCA20`.
  - After: the method table records the raw helper and its current evidence-bound role while keeping child-page/validator registration as follow-up work.
  - Evidence: A002 IDA MCP raw disassembly, `lookup_funcs`, data-ref/call audit, and raw address-byte scan.

- 2026-05-30: Changed completion/confidence from `0/0` to `82/80`.
  - Before: The page was unevaluated despite documenting singleton/vtable evidence, layout offsets, RIDINGS.DNA/EPF ownership, method roles, and destructor behavior.
  - After: Scored as high completion and medium-high confidence because method roles and lifetime are strong, while final nested-field names remain less certain.
  - Evidence: Existing state layout, method notes, IDA MCP constructor/vtable/singleton notes, and layout/global/memory cross-references support the score.

- 2026-05-31: Marked the class reconstructable and linked the exact `LoadRidingDefinitions` child memory page.
  - Before: `RECONSTRUCTABLE` was blank, and the parser was referenced only by its start address.
  - After: `RECONSTRUCTABLE:TRUE`, with the method table and cross-references pointing to the exact parser page.
  - Evidence: IDA MCP confirms the parser is source-authored `RidingImageLib` code, constructor-only at call site `0x004dc6f5`, and owns `RIDINGS.DNA` definition loading for this class.
