*** UID:0000KP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# LightObjImageLib

## 2026-08-18 Generated Header Route

`NexusTK/render/LightObjImageLib.h` now owns `LightInfo`, the complete class declaration, the `extern g_pLightObjImageLib` declaration, and inline `GetBrightness`. CPP includes that header, retains exactly one zero-initialized global definition, and emits every existing constructor/destructor/bounds/draw child unchanged. The complete ProtectedArray H is the required transitive dependency; no duplicate local declarations remain. Existing ranges, table parsing, virtual layout, compiler artifacts, and score remain intact.

## UID0001PR Accepted Header Source Order And One-Definition Contract - 2026-07-21

- This file root is prose-only and intentionally has no `RECONSTRUCTION_CPP` metadata. Ordinary emitters route through it to `NexusTK/render/LightObjImageLib.cpp`; source text belongs on [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md), [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md), exact type children, and exact method children.
- Accepted generated order is deterministic: semantic global definition [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md) at position `0`; [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md) at `1`; complete [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md) class/extern declaration at `2`; constructor at `10`; ordinary destructor at `30`; GetLightBounds at `40`; DrawLightMode1 at `50`; DrawLightMode2 at `60`.
- The physical storage page [UID:0001PR][0x0069b450-0x0069b454.g_pLightObjImageLib](by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md) remains non-emitting. The semantic global emits exactly one external-linkage definition, `LightObjImageLib *g_pLightObjImageLib = 0;`; the complete class declaration provides the matching `extern` declaration. No header-static or second storage definition is permitted.
- `LightObjImageLib` directly inherits `LObject` and `Singleton<LightObjImageLib>`. RTTI PMD `{4,-1,0}`, `0x30` allocation size, and EBO place the empty Singleton base and `ProtectedArray<LightInfo> m_lightInfos` at `+0x04`. The member contains count `+0x08`, entries `+0x0c`, default capacity `+0x10`, and inline default row `+0x14..+0x2f`.
- Authored source is the global definition, `LightInfo`, class declaration, constructor, ordinary destructor frame loop, bounds helper, and two draw methods. Singleton publication/clear, ProtectedArray storage teardown, vptr/EH/cookie lowering, scalar delete flags, object storage free, RTTI, vtable arrays, and exact helper [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md) are compiler/template/ABI output and must not be handwritten.
- The constructor preserves `LIGHT.TBL`, four-int/two-float row reads, `0x1c` resize/copy/free behavior, positive-radius odd-sized frame creation, clear/center/brightness rounding/elliptic-gradient sequence, and default-row selection. Singleton publication is supplied by the direct base initializer, not a manual assignment.
- The ordinary destructor authors only deletion of non-null generated frames in live entries. ProtectedArray member destruction frees row storage, Singleton base destruction clears the global, and LObject destruction handles base cleanup. [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) remains a non-emitting ABI wrapper.
- The complete 19-reference global inventory spans constructor publication/fallback clear, ordinary/helper/scalar cleanup, shutdown, and thirteen rendering/attachment consumers. Those reads confirm lifetime and visibility but do not create additional storage owners or definitions.
- Historical prose below that describes separate `lightInfoArray`/fallback members, a handwritten global clear/free in the ordinary destructor, reconstructable cleanup/vtable pages, or generated empty markers records pre-callback assumptions. It is superseded by this accepted current source route while remaining useful binary-history evidence.

## Status

- Confidence: strong for high-level behavior, singleton/vtable evidence, observed offsets, exact vtable-data boundaries, the `GetLightBounds` source route, and B003-resolved `LightInfo` field names; bounded for exact original spelling of inferred helpers/fields.
- Proposed module: `render/LightObjImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_LightObjImageLib.cpp`
- Main address ranges: `0x004df7e0-0x004dfd0a`, `0x004e5bb0-0x004e5bbb`, and `0x004e65e0-0x004e669d`
- Primary global instance: [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md) at `0x0069b450`
- Primary vtable: [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md) at `0x0061b754`
- Exact vtable data: [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md)

## File Role

`LightObjImageLib` is the light-source image library. Unlike the tile/item/riding libraries, it does not primarily load sprite frames from EPF archives. It reads `LIGHT.TBL`, builds per-light radial frames procedurally, and exposes two draw modes that center a prebuilt frame at a target screen position.

This should stay in render/image ownership but separate from the EPF frame-table loaders. It depends on DAT table reads, alpha-mask frame creation, and the shared [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md) member blitter, but the table schema and procedural radial frame generation are light-specific.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `LIGHT.TBL` | Light source table: `tableId`, `innerRadius`, X/Y radii, brightness, `blendScale`, and generated-frame parameters. |

## Behavior Summary

The constructor opens `LIGHT.TBL`, reads the record count, resizes the light-info array, and decodes each light record. When both radii are positive, it creates a frame of size `(2 * radiusX + 1)` by `(2 * radiusY + 1)`, clears it, finds its center, and draws a radial light texture into the frame using brightness converted to a 0..32 alpha-like value.

The `LIGHT.TBL` row is `tableId`, `innerRadius`, `radiusX`, `radiusY`, `brightness`, `blendScale`, and `generatedFrame`. `innerRadius` is passed to `AlphaMaskSurface::FillEllipticGradient`; `blendScale` is the falloff/scale float for that gradient. The older `lightSource` and `blendValue` labels are superseded by the B003 source-quality audit.

`DrawLightMode1` and `DrawLightMode2` select either the requested light record or a fallback entry, compute a destination rectangle centered around `(centerX, centerY)`, and call `targetSurface->DrawFrameWithBlendMode(...)` with blend mode `1` or `2`. The frame blitter is owned by [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md); LightObjImageLib only consumes it after generating light frames.

The object layout is now anchored by [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md). The record table uses `0x1c`-byte [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md) rows, with the in-object fallback `LightInfo` at `this + 0x14` represented as `m_lightInfos.m_defaultEntry` inside the single ProtectedArray member.

The generated `ProtectedArray_struct_LightInfo_` file is only the concrete template cleanup support for the light record table. `LightObjImageLib` owns `LIGHT.TBL` parsing and frame generation; [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) owns the reusable container pattern.

Batch 139 split the exact [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md) child out of the broader image-library read-only aggregate. That split records the class RTTI/vtable dwords and keeps the adjacent `ProtectedArray<LightInfo>` vtable as template support rather than source owned by this file.

2026-06-17 B003 source-quality audit resolved the first-draft blockers for the constructor, ordinary destructor, and two draw-mode vtable slots. The accepted current source file emits `LightObjImageLib::LightObjImageLib`, `LightObjImageLib::~LightObjImageLib`, `GetLightBounds`, `DrawLightMode1`, and `DrawLightMode2`; the scalar deleting destructor remains compiler output and is not hand-authored.

The same B003 cleanup audit classified [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md) as constructor/static cleanup glue. Current source-shape reanalysis resolves it specifically as compiler/template lowering for the direct Singleton base. The local PE bytes are exactly `c7 05 50 b4 69 00 00 00 00 00 c3`, the helper has no `this`, no callees, and only clears `g_pLightObjImageLib`; the constructor cleanup jump at `0x006001d0` proves liveness without implying a source API.

2026-06-20 B001 local-cluster source-quality recheck confirms [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md) should remain a non-emitting ownerless index. The source-authored constructor, ordinary destructor, `GetLightBounds`, `DrawLightMode1`, and `DrawLightMode2` are exact child pages emitted through this file; the singleton clear helper and scalar deleting destructor remain attached behavior evidence with blank formal C++ by cleanup-glue/compiler-wrapper policy. The same recheck rejects the stale `0x004df7e0-0x004e669d` aggregate because NewHumanImageLib starts at `0x004dfd10` after `0xcc` padding.

2026-06-28 B008 `DrawFrameWithBlendMode` source-quality cleanup updates this file's dependency wording after [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md) was resolved as `AlphaMaskSurface::DrawFrameWithBlendMode`. Current MCP evidence proves the destination surface is passed in `ecx`, with four explicit stack arguments and `retn 10h`. The two draw-mode child pages now call `targetSurface->DrawFrameWithBlendMode(...)`; this file remains the owner of the light draw methods but not the alpha-mask blitter.

## IDA-Confirmed Bodies

| Range | Body | Role |
| --- | --- | --- |
| `0x004df7e0-0x004dfaa6` | [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md) | Constructs the singleton, loads `LIGHT.TBL`, allocates `LightInfo` rows, and generates radial light frames. |
| `0x004dfab0-0x004dfb36` | [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md) | Deletes generated frames, frees the `LightInfo` buffer, clears the singleton, and tail-calls `LObject` cleanup. |
| `0x004dfb40-0x004dfbb0` | [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) | Writes local light bounds derived from the selected `LightInfo` radii; formal first-draft C++ now emits through this source file. |
| `0x004dfbb0-0x004dfc5a` | [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md) | Draws a centered generated light frame with blend mode `1`. |
| `0x004dfc60-0x004dfd0a` | [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md) | Draws a centered generated light frame with blend mode `2`. |
| `0x004e5bb0-0x004e5bbb` | [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md) | Clears `g_pLightObjImageLib`. |
| `0x004e65e0-0x004e669d` | [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) | Virtual deleting destructor wrapper over the same generated-frame cleanup semantics. |
| `0x0069b450-0x0069b454` | [UID:0001PR][0x0069b450-0x0069b454.g_pLightObjImageLib](by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md) | Runtime pointer to the light image-library singleton. |

## Caveats

Wave3's current `class_LightObjImageLib.cpp` is useful as behavior evidence but still contains modern C++ artifacts and unresolved helper names. The class-level effective grade is `41.5` even though each modeled method is imported with effective grade `97.0`. Active generated metadata reports `vtable_count: 0` and omits the ordinary destructor at `0x004dfab0`, while IDA confirms both the vtable and raw destructor body. Treat generated field names and inventory as provisional until this class is rewritten. The active project generated `NexusTK/render/LightObjImageLib.cpp` now has first-draft exact child method bodies for the constructor, ordinary destructor, bounds helper, and two draw modes; [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) remains blank by scalar deleting destructor wrapper policy.

## Cross-References

- [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md)
- [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md)
- [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md)
- [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md)
- [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md)
- [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md)
- [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md)
- [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md)
- [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md)
- [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md)
- [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md)
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-06-08 A007 Batch 139 source-parent refresh:
  - What existed before: file scores were `86/80`, with vtable evidence present but not tied to an exact concrete vtable-data child.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:85`, exact vtable-data child link, and source-ownership text distinguishing `LightObjImageLib` from adjacent `ProtectedArray<LightInfo>` support.
  - Summary/evidence: [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md) records the five-slot vtable, target sizes, xrefs, and neighboring template/class boundaries. The file cleared the supporting `85/85` source gate for the class/vtable chain; B003 later resolved the main `LightInfo` field names and narrowed remaining caveats to exact original helper/declaration spelling.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: light image-library role, `LIGHT.TBL` resource inputs, radial frame generation, draw modes, layout/record/vtable anchors, supplemental destructor/singleton bodies, and caveats were documented at that time; B003 later resolved the main `LightInfo` field names and first-draft method emission, leaving generated metadata omissions and exact original declaration/helper spelling as bounded caveats.
- 2026-05-31 exact method split and projected path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the body list only called out the ordinary destructor, singleton-clear helper, and singleton storage.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, plus exact constructor, bounds helper, draw mode, and scalar deleting destructor by-memory references.
  - Summary/evidence: proposed tree already places this module at `render/LightObjImageLib.cpp`; IDA MCP verified exact bounds and behavior for `0x004df7e0`, `0x004dfb40`, `0x004dfbb0`, `0x004dfc60`, and `0x004e65e0`. This records the historical pre-B003 no-C++ state; exact child pages now emit first-draft constructor, ordinary destructor, bounds, and draw-mode C++ where source-owned.
- 2026-06-12 C001 ImageLib-family barrier repair:
  - Changed to: the broad LightObjImageLib memory aggregate is now [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md), a non-emitting local cluster ending before NewHumanImageLib. Singleton-clear and scalar-deleting destructor pages remain exact separate tails, and [UID:0003LZ][0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable](by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md) covers the independent table-loader helper just before this cluster.
  - Evidence: live IDA `entity_query`, `lookup_funcs`, `xrefs_to`, `callees`, and `decompile` on 2026-06-12 proved the old `0x004df7e0-0x004e669d` aggregate crossed NewHumanImageLib.
- 2026-06-13 B003 adjacent-helper correction:
  - Changed to: removed the stale cross-reference that associated [UID:0003LZ][0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable](by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md) with this source file. The helper is an `ItemObjImageLib` table loader, and [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md) is the adjacent raw `ItemObjImageLib` frame-availability helper.
  - Evidence: live IDA MCP showed the real `LightObjImageLib` source body starts at [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md) with `LIGHT.TBL`, `LightInfo` `0x1c` rows, `g_pLightObjImageLib`, and generated light-frame allocation; the pre-`0x004df7e0` helpers instead use `ITEM.*` resources and `ItemInfo` layout.
- 2026-06-17 B003 [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) source-quality execution:
  - Score unchanged at `87/85`.
  - Summary/evidence: [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) now documents `void LightObjImageLib::GetLightBounds(int lightIndex, RectBounds *outBounds)` and has formal first-draft C++. The only caller is an `AttachmentAnchorResolver` consumer, so source placement remains `NexusTK/render/LightObjImageLib.cpp`.
- 2026-06-17 B003 LightObjImageLib method-cluster source-quality execution:
  - Score unchanged at `87/85`.
  - Summary/evidence: B003 resolved the `LIGHT.TBL` row schema, constructor/destructor/draw first-draft C++ readiness, scalar deleting destructor no-code policy, DAT scalar-reader local aliases, global singleton alias policy, and source placement. Exact child pages [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md), [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md), [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md), and [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md) now carry formal first-draft C++.
- 2026-06-17 B003 singleton-clear cleanup audit:
  - Score unchanged at `87/85`.
  - Summary/evidence: incorporated the no-code source-form proof for [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md): exact singleton-zero PE bytes, constructor cleanup jump evidence, no `this`, no callees, singleton-only write, accepted Light no-code wrapper precedent, and rejection of a handwritten clear-helper API.
- 2026-06-20 B001 local-cluster Rule 26 incorporation:
  - Score unchanged at `87/85`.
  - Summary/evidence: the local cluster parent remains an ownerless non-emitting index; exact children emit the source-authored constructor, ordinary destructor, bounds helper, and two draw modes through this file. The B001 PE/Capstone scan preserved the `0x004dfd10` NewHumanImageLib boundary, singleton-clear cleanup jump, scalar-deleting wrapper route, inherited `LObject` vtable-slot interpretation, `g_pLightObjImageLib` alias policy, and current `LightInfo`/`LightObjImageLib` field names without changing this file's owner route.
- 2026-06-28 B008 AlphaMaskSurface dependency cleanup:
  - Score and owner metadata unchanged.
  - Summary/evidence: [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md) now carries the formal member-method C++ and proves LightObjImageLib is a caller/consumer. The two draw-mode child pages were updated from free-helper syntax to member-call syntax while preserving this file's ownership of the light draw methods.
