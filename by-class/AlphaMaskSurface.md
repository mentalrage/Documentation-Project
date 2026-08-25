*** UID:00000C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AlphaMaskSurface

## Final Historical-Alias Disposition

`AlphaMaskSurface` is a historical project semantic label for the byte-mask subsystem and physical `AlphaMaskSurface.cpp/.h` filename, not a recovered C++ class. Fresh whole-file evidence found no `AlphaMaskSurface` RTTI string, type descriptor, hierarchy, vtable, or independent constructor family. Every former class method belongs to the unique RTTI-backed [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md) class in [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md).

This page remains at `95/95` as exhaustive historical and negative evidence, but it is `RECONSTRUCTABLE:FALSE`, has no emitter, and keeps both formal channels blank. Prior behavior, layout, method, caller, and source-placement research remains useful as provenance of the corrected IntAlphaSurface reconstruction. It must not generate a duplicate class declaration or implementation.

## Historical Pre-Callback Status

All class-shaped assertions in the retained sections below are dated hypotheses superseded by the final historical-alias disposition above. They are preserved to explain why the old name appeared and why the two-class interpretation was rejected.

- Confidence: strong for imported methods, layout, adjacent alpha view helper boundaries, and raw-byte evidence; medium-high for raw default-constructor callability and physical source colocation with `IntAlphaSurface`.
- Likely source file: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- Address range: [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md), plus raw default-constructor-shaped range [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md)
- Documentation basis: IDA-confirmed alpha-surface method ranges plus the [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) file page, exact by-memory range pages, and layout/vtable docs below.
- Layout docs: [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md), [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md)

## Class Purpose

`AlphaMaskSurface` owns a temporary byte alpha-mask buffer. It is used to build procedural light masks, overlay masks, and clipped byte-mask views that are later consumed by render blitters.

## Observed State

```text
0x00  vtable
0x04  Rect bounds
0x14  uint8_t* pixels
0x18  int width
0x1c  int height
0x20  int stride
0x24  bool ownsBuffer
```

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AlphaMaskSurface::AlphaMaskSurface` default/raw | `0x00462120-0x00462161` | Raw constructor-shaped bytes initialize an empty owning surface; IDA reports no function or xrefs at the start. |
| `AlphaMaskSurface::AlphaMaskSurface` | `0x00462170-0x00462227` | Initializes bounds and allocates `width * height` byte pixels; current B007 session reports four code xrefs. |
| `IntAlphaSurface` unwind cleanup | [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) | Compiler-generated EH cleanup target; not a handwritten method. |
| `IntAlphaSurface::ReleaseOwnedPixels` provisional | [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md) | Vtable slot helper that frees owned pixel storage for the sibling/view surface layout. |
| `GetCenterPoint` | `0x004622d0-0x004622f7` | Writes half-height and half-width into a caller-provided pair; current B007 session reports four code xrefs. |
| `GetBufferInfo` | `0x00462300-0x00462317` | Exact source-facing `void AlphaMaskSurface::GetBufferInfo(AlphaSurfaceBufferView *outView) const`; copies object `+0x14..+0x27` into the 0x14-byte output view. Its only callers are compat/RGB555 slot-5 provider `0x004bdf40` at `0x004bdfb5` and RGB565 provider [UID:0002TH][0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback](by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md) at `0x004c3d65`. |
| `BuildClippedAlphaSurfaceView` provisional | [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md) | Builds a non-owning clipped view over the current pixel buffer. |
| `InitAlphaSurfaceView` | [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) | AlphaMaskSurface helper that placement-initializes a caller-supplied full or clipped non-owning `IntAlphaSurface` view object. |
| `DrawFrameWithBlendMode` | [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md) | Member blitter that clips destination/source rectangles and dispatches copy/add/subtract byte-row modes into this surface. |
| `AlphaMaskSurface::DrawEncodedAlphaFrame` | [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md) | `int` member taking `RectBounds *dstRect`, `EPFTileContext *sourceContext`, `RectBounds *sourceOrigin`, alpha ramp endpoints, and blend mode. It reads `encodedMaskBytes` at `+0x24` and implements modes `0` replace / `1` add / `2` subtract. UID0000YO is `88/91`; formal C++ remains blank under its variant return-register no-code proof. |
| `ApplyRectAlpha` | `0x00462520-0x00462672` | Fills/adds/subtracts a clipped rectangle with a byte alpha value; current B007 session reports five code xrefs. |
| `FillRadialGradient` | `0x00462680-0x0046286b` | Rasterizes circular alpha falloff using replace/add/subtract behavior; current B007 session reports two UserPane constructor-path xrefs. |
| `FillEllipticGradient` | `0x00462870-0x00462e03` | Rasterizes elliptical alpha falloff with an inner flat-alpha radius; current B007 session reports one LightObjImageLib constructor-path xref. |

## Evidence Notes

### 2026-08-04 Slot-5 Callback-Facing Type Closure

- Both fixed Surface slot-5 providers receive `const AlphaMaskSurface *` and call the same `GetBufferInfo` accessor. The accessor performs only reads from the source object and writes the caller-provided view, so the source-facing accessor is const-qualified and returns logical `void`; stale output-pointer residue in EAX is not a source return.
- The exact output is [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md): `unsigned char *pixels`, signed `width`, `height`, and `stride`, one-byte `bool ownsBuffer`, and three bytes of explicit padding, total size 0x14.
- Compat provider `0x004bdf40` and RGB565 provider `0x004c3cf0` are the complete caller set. Both use the copied view for clipped source-row translation, while their RGB555/RGB565 bulk and lookup-tail math remains separate Surface-owned behavior.
- `AlphaMaskSurface` is the callback-facing source object because MapPane owns an allocated/deleted `AlphaMaskSurface *m_selectionOverlay` and passes that pointer through `g_pfnBlitAlphaLookup`. The related `IntAlphaSurface` RTTI/vtable and helper history remains valid for physical source-colocation and view-family research, but it does not change this callback parameter or make `GetBufferInfo` an IntAlphaSurface method.
- No partial class declaration is added to this class-level formal block. UID0001TQ owns the exact POD declaration, UID0000TN owns the callback typedef/global declaration, and exact method bodies remain on exact memory children or future splits.

- The class anchor is the IDA-confirmed constructor at `0x00462170`, with caller evidence from `LightObjImageLib`, `UserPane`, and `GameServerConfig`-adjacent paths.
- B001/supervisor vtable-owner application: live IDA MCP on 2026-06-08 reconfirmed that [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) is written by the active constructor/helper at `0x0046217b` and the view-initializer neighborhood at `0x00462237`/`0x00462415`, while B001 also confirmed RTTI naming `IntAlphaSurface` directly. This makes `AlphaMaskSurface` a real physical source-colocation candidate for vtable writes, but not the direct class/type owner.
- IDA MCP reports `DrawFrameWithBlendMode` callers from the two `LightObjImageLib` draw modes, supporting this class as shared render infrastructure.
- Adjacent functions at `0x00462260`, `0x00462320`, `0x004623c0`, and `0x00462f20` operate on the same `{bounds,pixels,width,height,stride,ownsBuffer}` layout. B009's 2026-06-28 implementation resolves [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) specifically as an AlphaMaskSurface-owned helper: `ECX` is the source alpha surface object, `arg_0` is a caller-supplied `IntAlphaSurface *` destination, and `arg_4` is an optional `RectBounds *` clip. Broader raw/default-constructor source splits remain provisional; UID0000YO's AlphaMaskSurface member route is resolved.
- 2026-05-26 IDA MCP caller/xref recheck maps `DrawEncodedAlphaFrame` modeled callers to [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md), and [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) overlay paths. The raw xrefs at `0x004d5ea6`, `0x004d6b16`, and `0x004dcca5` still need caller function-boundary recovery, but they are not owner, source-placement, or target-split evidence.
- IDA MCP recheck on 2026-05-25 confirms `0x00462320` has a live `StaticObjImageLib` caller, while `0x004623c0` and `0x00462260` are vtable/layout helpers without direct code callers in the current IDA database.
- 2026-05-26 IDA MCP recheck confirms the object offsets and view record layout: vtable at `+0x00`, bounds at `+0x04`, pixels at `+0x14`, width/height/stride at `+0x18/+0x1c/+0x20`, and ownership flag at `+0x24`.
- 2026-05-26 IDA MCP raw-disassembly recheck found constructor-shaped bytes at `0x00462120-0x00462161` that initialize the same layout with zero bounds and no pixels, but `lookup_funcs` and `xrefs_to` do not prove a callable function boundary.
- 2026-05-26 IDA MCP raw-disassembly/xref recheck found `0x00462230-0x00462258` as an EH-only cleanup target reached from `0x005fa593`; it writes the same `off_6112EC` vtable and releases owned pixels, but should be ignored for handwritten source reconstruction.
- Existing by-* evidence separates the IDA-modeled class methods at `0x00462170`, `0x004622d0`, `0x00462300`, `0x00462520`, `0x00462680`, and `0x00462870` from the raw default constructor, release/view helpers, and encoded-alpha blitter, which remain source-split questions.
- Nearby `0x004632c0` is not part of this class family; it uses vtable `0x00612574` and belongs to application error-state cleanup.
- 2026-05-30 IDA MCP recheck confirms the raw default constructor range still has no IDA function object or xrefs, but its raw bytes initialize the same vtable/layout and terminate at `0x00462160` before `0x00462161-0x00462170` alignment.
- 2026-05-30 IDA MCP recheck confirms `BuildClippedAlphaSurfaceView` writes a concrete 0x14-byte output view with pointer, dimensions, stride, and non-owning flag, strengthening the layout and helper documentation.
- 2026-05-30 IDA MCP recheck confirms `DrawEncodedAlphaFrame` is a shared encoded-row alpha blitter over this surface layout, with six modeled image-library callers and three raw image-library xrefs still requiring function-boundary recovery.
- 2026-06-16 A001 live IDA refresh reconfirmed `sub_462170` size `0xb7`, `sub_462260` size `0x22`, `sub_462300` size `0x17`, `sub_462320` size `0x95`, `sub_4623C0` size `0x154`, `sub_462E10` size `0x10e`, `sub_462F20` size `0x332`, and `sub_463270` size `0x41`; raw `0x00462120` is still not an IDA function.
- The same pass reconfirmed the constructor writes vtable `0x006112ec`, `RectBounds` at `+0x04`, pixels at `+0x14`, width/height/stride at `+0x18/+0x1c/+0x20`, and ownership byte `+0x24`; `0x006112ec` xrefs remain limited to the raw default-constructor store, modeled constructor, view/cleanup stores, and scalar destructor.
- A section-mapped PE scan found no absolute VA, RVA, or rel32 references to raw `0x00462120` or no-xref `0x004623c0`. B009's later report keeps the `0x004623c0` no-xref state as a confidence cap rather than a method blocker because the live prototype/source-object/out-parameter evidence is strong enough for first-draft formal C++.
- 2026-06-28 B008 MCP session `b001_000241_20260627` resolves `DrawFrameWithBlendMode` as a member method on this class rather than a free helper: LightObjImageLib callers place the destination surface in `ecx`, push four explicit arguments, and the callee returns with `retn 10h`. [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md) now carries first-draft formal C++; [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md) is retained only as a non-emitting support index.
- 2026-07-02 B003 UID00041R support sync records [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md) in the method inventory. UID00041R proves the overlay route uses `AlphaMaskSurface` as the receiver, returns `int`, and passes `RectBounds *dstRect`, `EPFTileContext *sourceContext`, `RectBounds *sourceOrigin`, `alphaEndY`, `alphaEnd`, `alphaStartY`, `alphaStart`, and `blendMode`. UID00041R uses mode `1` add, while the helper supports modes `0` replace, `1` add, and `2` subtract; the caller computes `alphaEnd` as `(unsigned char)(overlayStrength * 32.0f + 0.5f)`. Broader frame-source type names and raw xrefs remain separate caveats.
- 2026-07-09 B001 MCP session `supervisor_nexustk_20260709` reconfirmed UID0000YO's exact `0x332` range, eight explicit arguments, `retn 20h`, AlphaMaskSurface receiver, `EPFTileContext + 0x24` encoded stream, and nine callsites. The source-facing signature is now implementation-ready for documentation without inventing a new payload type. The target is `88/91` and intentionally non-code-emitting because null-stream, valid-mode, and invalid-mode paths expose stale or variant `EAX` results that cannot be normalized safely.
- 2026-07-07 B007 UID0000YL current-session refresh used MCP session `ef57d27f` with `server_health ok`, auto-analysis ready, Hex-Rays ready, and strings cache ready. It normalizes the class method-family inventory under [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md): active constructor `0x00462170-0x00462227`, center accessor `0x004622d0-0x004622f7`, buffer accessor `0x00462300-0x00462317`, clipped-view helper `0x00462320-0x004623b5`, view initializer `0x004623c0-0x00462514`, rectangular fill `0x00462520-0x00462672`, radial gradient `0x00462680-0x0046286b`, and elliptic gradient `0x00462870-0x00462e03`. The same pass records zero raw-default xrefs, the one clipped-view caller at `0x004dd66a`, zero `0x004623c0` xrefs, the fill/gradient caller counts, IntAlphaSurface vtable support, and zero direct VA/RVA pointer-pattern hits for selected raw/live starts. UID0000YL is a comment-only aggregate marker with no monolithic body and no `[[CHILDREN]]`; exact constructor/accessor/fill/gradient bodies still need exact split pages before formal C++.

## Cross-References

- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)
- [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md)
- [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)
- [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md)
- [UID:0000UH][DrawEncodedAlphaFrame_00462F20](by-item/DrawEncodedAlphaFrame_00462F20.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md)

## Changes

- 2026-07-09 B001 UID0000YO source-quality support sync:
  - Score and parent metadata unchanged.
  - Summary/evidence: synchronized the method inventory with UID0000YO's accepted `88/91` member signature, EPFTileContext encoded-stream field, raw-xref boundary disposition, and target-specific return-contract no-code proof.
- 2026-07-07 B007 UID0000YL aggregate implementation support sync:
  - Score and parent metadata unchanged.
  - Summary/evidence: refreshed the method inventory with current half-open ranges, xrefs/caller roles, and the accepted no-code aggregate disposition for UID0000YL. This class remains the AlphaMaskSurface class-level owner/support page, while UID0000YL itself must not emit a monolithic method body.
- 2026-06-28 B009 `InitAlphaSurfaceView` source-quality implementation:
  - Score and parent metadata unchanged.
  - Summary/evidence: the method inventory now routes [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) directly through this class/file rather than only through the old by-item index. MCP session `b001_000241_20260627` proves `ECX` is the source `AlphaMaskSurface`, the destination is an explicit `IntAlphaSurface *` out parameter, and the `off_6112EC` write is destination construction state.
- What existed before: the page had detailed render-surface layout, method, raw-boundary, and cross-reference evidence but still had unevaluated `0/0` metadata.
- What it was changed to: scores were set to `78/84`; no class/file ownership change was made.
- Summary and evidence: completion remains below high because the raw default constructor, `IntAlphaSurface` split, view helpers, and encoded-alpha blitter ownership still need a final source-level split.
- 2026-05-30: Raised completion/confidence from `78/84` to `82/88`. Added current IDA MCP evidence for the raw default-constructor-shaped range and clipped-view output fields; the `IntAlphaSurface` split and some helper names remain provisional.
- 2026-05-30: Raised completion/confidence from `82/88` to `84/89` after current IDA MCP verification of `DrawEncodedAlphaFrame`; remaining class-level gaps are the final frame-source type, three raw image-library xrefs, and the `IntAlphaSurface` split.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE` and attached the class to [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md). Current IDA MCP `lookup_funcs` re-confirmed the method starts at `0x00462170`, `0x004622d0`, `0x00462300`, `0x00462520`, `0x00462680`, and `0x00462870`, and `callers` still shows live constructor call sites from render/client paths; both the class (`84/89`) and file (`82/89`) clear the 80+ attachment gate. Reconstruction C++ remains blank because the raw default constructor, view helpers, and `IntAlphaSurface` split are not final-source quality.
- 2026-06-06 provenance cleanup: replaced stale recovered-output framing with the existing IDA/by-* evidence basis. Scores and parent metadata are unchanged because this pass did not resolve the raw default constructor, view-helper ownership, encoded-alpha frame-source type, or `IntAlphaSurface` split.
- 2026-06-08 A005 Batch124:
  - Score and parent metadata unchanged.
  - Added the vtable-owner audit for [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md). The live recheck strengthens this class as a source-colocation candidate for the vtable-store side, while the later B001 RTTI pass resolved direct class/type ownership to `IntAlphaSurface`.
- 2026-06-08 B001/supervisor RTTI ownership application:
  - Score and parent metadata unchanged.
  - Updated the vtable-owner caveat after [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) was assigned to [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md). This class remains important vtable-store and possible physical source-colocation evidence, but RTTI makes `IntAlphaSurface` the direct type owner.
- 2026-06-16 A001 Goal 2 type/layout parent refresh:
  - Before: `84/89`.
  - Changed to: `85/90`; owner/emitter remain [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md).
  - Evidence: live IDA reconfirmed all core alpha-surface helper boundaries, object-layout writes, vtable-write family, clipped-view caller evidence, current encoded-frame caller spread, and the PE-scan absence of raw/default-constructor and no-xref view-initializer refs. Completion only moves to the direct-parent gate because the final `AlphaMaskSurface` versus `IntAlphaSurface` source split and raw constructor/helper declarations remain unresolved.
- 2026-06-28 B008 `DrawFrameWithBlendMode` member-method update:
  - Score and parent metadata unchanged.
  - Summary/evidence: [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md) now documents the exact member-call proof, formal `AlphaMaskSurface::DrawFrameWithBlendMode` C++, and source ownership through this class/file. The class method inventory was updated accordingly; the by-item duplicate remains non-emitting support only.
- 2026-07-02 B003 UID00041R `DrawEncodedAlphaFrame` support sync:
  - Score and parent metadata unchanged.
  - Summary/evidence: added [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md) to the method inventory with the UID00041R-proven `AlphaMaskSurface` thiscall route, `int` return, `RectBounds *dstRect`, `EPFTileContext *sourceContext`, `RectBounds *sourceOrigin`, alpha ramp arguments, mode meanings `0` replace / `1` add / `2` subtract, and the UID00041R `overlayStrength * 32.0f + 0.5f` transform. This does not settle the generic frame-source type or the three raw image-library xrefs.
