*** UID:0000HF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# AlphaMaskSurface And Mask Blitters

## Accepted Current Source Resolution

`NexusTK/render/AlphaMaskSurface.cpp` and `AlphaMaskSurface.h` are the sole physical source unit for the complete byte-alpha surface family `[0x00462120,0x004632b1)`. The concrete dynamic class is [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md), recovered directly from RTTI `.?AVIntAlphaSurface@@`, its one-class hierarchy, vtable `0x006112ec`, and the constructor/view/destructor vptr-write family. No second `AlphaMaskSurface` RTTI, hierarchy, vtable, or constructor family exists. The source filename preserves the historical subsystem name; [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md) and [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md) now retain the superseded two-class/two-file model only as historical evidence.

The source module owns thirteen ordinary methods in physical order:

| Order | Exact child | Range | Body SHA256 | Source disposition |
| --- | --- | --- | --- | --- |
| 1 | [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md) | `0x00462120-0x00462161` | `F807ABECDF355DAADAEF20FC0379C762AC16930F11BB0B500D8A59271230F15B` | `IntAlphaSurface::IntAlphaSurface()`; retained source despite zero static routes |
| 2 | [UID:00054W][0x00462170-0x00462227.IntAlphaSurfaceConstructor](by-memory/0x00462170-0x00462227.IntAlphaSurfaceConstructor.md) | `0x00462170-0x00462227` | `3C53CF0401D392140A5835B239B2EB06AFFCB47BFE3C215739C68E6F3A564003` | allocating constructor |
| 3 | [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md) | `0x00462260-0x00462282` | `6E644D9BD79CCFC819A15B939238C00457E57BAD19E17ED9A845E49D75598308` | virtual owned-buffer release |
| 4 | [UID:00054X][0x004622d0-0x004622f7.IntAlphaSurfaceGetCenterPoint](by-memory/0x004622d0-0x004622f7.IntAlphaSurfaceGetCenterPoint.md) | `0x004622d0-0x004622f7` | `4ABEED77DDAEB624306345898192DEC79CF1679A6A2F26B5A02A04E23AF0ED73` | logical-void center accessor |
| 5 | [UID:00054Y][0x00462300-0x00462317.IntAlphaSurfaceGetBufferInfo](by-memory/0x00462300-0x00462317.IntAlphaSurfaceGetBufferInfo.md) | `0x00462300-0x00462317` | `580C7557AA8D137C3E8AB8C7AC4C823AE4A76E1460C4FD88B9B3799F733E5501` | logical-void 0x14-byte view copy |
| 6 | [UID:00054Z][0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo](by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md) | `0x00462320-0x004623b5` | `807B0AB335E4751A6547BDB0976D03C8BD8470F30D3B7135F46AC7FABB22AF4E` | clipped non-owning view builder |
| 7 | [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) | `0x004623c0-0x00462514` | `8E372F722154AF328D0E3B8114C1EEE587C9296EA3616A40472306498DC0833E` | placement-initialized full/clipped view |
| 8 | [UID:000550][0x00462520-0x00462672.IntAlphaSurfaceApplyRectAlpha](by-memory/0x00462520-0x00462672.IntAlphaSurfaceApplyRectAlpha.md) | `0x00462520-0x00462672` | `D80CB5B6167ED7C8202345CC20F5068E787D7267D6CB6BE84F7ABC5B761FE839` | clipped copy/wrapping-add/wrapping-subtract fill |
| 9 | [UID:000551][0x00462680-0x0046286b.IntAlphaSurfaceFillRadialGradient](by-memory/0x00462680-0x0046286b.IntAlphaSurfaceFillRadialGradient.md) | `0x00462680-0x0046286b` | `E035240F2BBE224212EF4F139AD90F244632EC60D79895A95B268F216CF6C7B6` | circular powered-distance gradient |
| 10 | [UID:000552][0x00462870-0x00462e03.IntAlphaSurfaceFillEllipticGradient](by-memory/0x00462870-0x00462e03.IntAlphaSurfaceFillEllipticGradient.md) | `0x00462870-0x00462e03` | `3632B81BE3ADCDF10C7646D4EE94F1C2DF3CB62E5053DD6FD2B05D9E4665FBB1` | anisotropic gradient with inner flat radius |
| 11 | [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md) | `0x00462e10-0x00462f1e` | `BB736A106E71EF150DC9C2A3008AA084A3D382F60D589AC27EEEB34A9D9CF16C` | ByteSpan-backed frame blit |
| 12 | [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md) | `0x00462f20-0x00463252` | `BEF926A303F0BF258873A39F3B01DB64D415C41E458270DBF369D20B5B5A0344` | logical-void encoded-row blit |
| 13 | [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md) | `0x00463270-0x004632b1` | `22D614DFF266C09C7572C4BF129370C74DFD9218B8BABC79E77BF61C8FC56470` | ordinary destructor; scalar-delete mechanics remain compiler generated |

Compiler/no-code children are [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md), the zero-reference [UID:000553][0x00463260-0x00463263.IntAlphaSurfaceEncodedBlitNoOpStub](by-memory/0x00463260-0x00463263.IntAlphaSurfaceEncodedBlitNoOpStub.md), [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md), and [UID:0003OX][0x006112e8-0x006112fc.IntAlphaSurfaceVtableData](by-memory/0x006112e8-0x006112fc.IntAlphaSurfaceVtableData.md). [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md) is a non-emitting audit map after exact splitting.

Direct-call inventory is complete: zero routes to `0x00462120`; four to `0x00462170`; EH-only `0x005fa593` to cleanup; vtable-only `0x006112f0` to release; four to center; two to buffer info; one to clipped view; zero direct to view initialization; five to rectangle fill; two to radial; one to elliptic; two to DrawFrame; nine to DrawEncoded; zero to the stub; and vtable-only `0x006112ec` to the destructor. The three raw DrawEncoded callsites belong to complete bodies `0x004d4f70-0x004d5edc`, `0x004d5f80-0x004d6b4c`, and `0x004dcaa0-0x004dccba`; all nine callers ignore EAX, proving logical `void`.

DrawEncoded preserves the exact stream contract: `encodedMaskBytes == NULL` is a no-op; `IntersectRects` is called without an invented result-based early return; zero terminates each row; `token & 0x80` selects a filled run; `token & 0x7f` gives its unsigned length; and the vertical alpha ramp plus copy/add/subtract behavior is retained. No signed-magnitude decode, saturation, speculative vtable array, explicit scalar-delete wrapper, or decompiler name belongs in final source.

Exact padding/non-source spans are `[0x462114,0x462120)`, `[0x462161,0x462170)`, `[0x462227,0x462230)`, `[0x462258,0x462260)`, `[0x462282,0x4622d0)`, `[0x4622f7,0x462300)`, `[0x462317,0x462320)`, `[0x4623b5,0x4623c0)`, `[0x462514,0x462520)`, `[0x462672,0x462680)`, `[0x46286b,0x462870)`, `[0x462e03,0x462e10)`, `[0x462f1e,0x462f20)`, `[0x463252,0x463260)`, `[0x463263,0x463270)`, and `[0x4632b1,0x4632c0)`. Address `0x004632c0` starts unrelated Application error-state cleanup and is excluded. This is first-party NexusTK render source; no third-party embed/import applies.

The dated validator command `000000025040` snapshot with six empty emitters and a separate `IntAlphaSurface.cpp` records the pre-callback deficit only. Current generated authority must be established by the implementation callback's coherent waited refresh and physical CPP/H reread.

## Historical Pre-Callback Status

The sections below preserve prior research, changing hypotheses, and rejected alternatives. Any statement below that treats `AlphaMaskSurface` as a concrete class, keeps `IntAlphaSurface.cpp` independently active, assigns methods to two source classes, leaves exact children missing, or blocks DrawEncoded source on EAX residue is a superseded historical checkpoint. The accepted current source resolution above is authoritative for reconstruction.

- Confidence: strong for imported `AlphaMaskSurface` methods, `DrawFrameWithBlendMode`, adjacent alpha view/helper boundaries, and shared layout; medium-high for raw default-constructor callability and final `IntAlphaSurface` source split.
- Proposed module: `NexusTK/render/AlphaMaskSurface.cpp`, with the broader `Surface.cpp` and provisional `IntAlphaSurface.cpp` split kept visible until constructor/source ownership is fully resolved.
- Current recovered labels: `AlphaMaskSurface`, `DrawFrameWithBlendMode`, `DrawEncodedAlphaFrame`, and related provisional `IntAlphaSurface`.
- Main address ranges: [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md), [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md), [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md), and related [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md).

## File Role

This cluster owns byte alpha-mask surfaces and helper blitters used by light rendering, overlay shading, and sprite-frame masking. `AlphaMaskSurface` allocates a byte buffer, exposes clipped buffer views, fills rectangles, and rasterizes circular/elliptical gradients. `AlphaMaskSurface::DrawFrameWithBlendMode` copies/adds/subtracts byte mask frames into the destination surface; the two LightObjImageLib draw modes are consumers, not owners, of this member blitter.

The observed object and view layouts are now tracked separately as [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md) and [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md). The vtable anchor [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) is class-owned by [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md) on RTTI evidence; the physical source-file split remains provisional because IDA shows that vtable written by the `AlphaMaskSurface` constructor/helper region.

The exact callback-facing accessor at `0x00462300-0x00462317` is source-facing `void AlphaMaskSurface::GetBufferInfo(AlphaSurfaceBufferView *outView) const`. It copies object bytes `+0x14..+0x27` into the exact 0x14-byte view and has only two callers: compat/RGB555 Surface slot-5 provider `0x004bdf40` at `0x004bdfb5` and RGB565 provider [UID:0002TH][0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback](by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md) at `0x004c3d65`. Both providers receive `const AlphaMaskSurface *`, then use the copied pixels/width/height/stride/ownership view for clipped source-row translation.

This callback-facing decision does not erase the `IntAlphaSurface` history. RTTI/vtable evidence still supports a related view/sibling type and possible physical source colocation, but MapPane allocation/deletion and the actual slot call establish `AlphaMaskSurface *m_selectionOverlay` as the passed object. `GetBufferInfo` reads AlphaMaskSurface state and is not reclassified as an IntAlphaSurface member. UID0001TQ owns the POD declaration, UID0000TN owns the callback typedef/global, and Surface owns the provider bodies.

The raw `0x00462120-0x00462161` body initializes an empty owning surface with the same vtable/layout as the confirmed width/height constructor, but IDA does not currently model it as a function and no xrefs target its start. Keep it as default-constructor-shaped evidence, not a clean source-map boundary.

The `0x00462230-0x00462258` body is now documented as an [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md). It restores `off_6112EC` and releases owned pixels, but its only observed caller is a C++ EH funclet at `0x005fa593`; do not migrate it as a handwritten source method.

The adjacent `0x00462320` and `0x004623c0` helpers are real IDA functions that build non-owning clipped/full buffer views over the same `{pixels,width,height,stride,ownsBuffer}` layout. `0x00462320` has a live caller in `StaticObjImageLib`; [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) has no direct code callers in the current IDA database, but B009's current MCP pass resolves it as an AlphaMaskSurface helper that placement-initializes a caller-supplied `IntAlphaSurface` view. Its `off_6112EC` store is a destination construction/use-site, not an `IntAlphaSurface` source-owner signal.

The adjacent [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md) is an exact AlphaMaskSurface member helper that rasterizes encoded frame rows with replace/add/subtract modes and a vertical alpha ramp. IDA MCP reports nine code xrefs. Six modeled callers are established image-library render methods: `MonsterImageLib::RenderMonsterImage`, `StaticObjImageLib::RenderStaticObject`, `EffectObjImageLib::RenderEffectFrame`, `ItemObjImageLib::DrawItemImage`, `ItemObjImageLib::DrawItemImageIn43x43Slot`, and `NewHumanImageLib::RenderPreparedComposition`. The three raw callsites at `0x004d5ea6`, `0x004d6b16`, and `0x004dcca5` still need caller function-boundary recovery, but their matching member-call setup makes them boundary evidence rather than owner, source-placement, or target-split blockers.

2026-05-30 IDA MCP recheck preserves the same nine xrefs and confirms `DrawEncodedAlphaFrame` reads encoded row data from the source payload, computes a vertical alpha ramp from the caller's row/alpha endpoints, and writes through the `AlphaMaskSurface` pixel/stride fields.

2026-07-02 B003 UID00041R support sync resolves the caller-facing route for the `ItemObjImageLib::DrawItemImage` overlay call. UID0000YO is an `int`-returning `AlphaMaskSurface` thiscall helper for that route: receiver is the overlay mask, and the explicit arguments are `RectBounds *dstRect`, `EPFTileContext *sourceContext`, `RectBounds *sourceOrigin`, `alphaEndY`, `alphaEnd`, `alphaStartY`, `alphaStart`, and `blendMode`. UID00041R uses the `EPFTileContext` encoded row stream at `+0x24`, passes mode `1` for additive overlay, sets `alphaStart` to zero, and computes `alphaEnd` as `(unsigned char)(overlayStrength * 32.0f + 0.5f)`; mode `0` is replace and mode `2` is subtract. Existing EPFTileContext support is sufficient for this source-facing signature, so a new encoded payload type is not justified.

2026-07-09 B001 MCP session `supervisor_nexustk_20260709` reconfirmed the exact `0x332` body, eight explicit stack arguments, `retn 20h`, AlphaMaskSurface receiver fields, source stream at `EPFTileContext + 0x24`, and all nine callsites. UID0000YO is now documented at `88/91` with the member signature `int AlphaMaskSurface::DrawEncodedAlphaFrame(RectBounds *dstRect, EPFTileContext *sourceContext, RectBounds *sourceOrigin, int alphaEndY, unsigned char alphaEnd, int alphaStartY, unsigned char alphaStart, int blendMode)`. Its formal body remains blank under a target-specific no-code proof: null-stream, valid-mode, and invalid-mode paths expose stale or variant `EAX` values that cannot be normalized without an unsupported behavioral claim.

2026-05-31 IDA MCP placement recheck reconfirmed the key boundaries used for the source-file decision: `0x00462120` is still raw constructor-shaped code with no IDA function object, `sub_462170` is `0x00462170-0x00462227`, `sub_462320` is `0x00462320-0x004623b5`, `sub_4623C0` is `0x004623c0-0x00462514`, `sub_462E10` is `0x00462e10-0x00462f1e`, `sub_462F20` is `0x00462f20-0x00463252`, and `sub_463270` is `0x00463270-0x004632b1`. `xrefs_to 0x00462f20` still reports nine code xrefs, `xrefs_to 0x00462e10` reports the two LightObjImageLib-style callers, and `xrefs_to 0x006112ec` ties the `IntAlphaSurface` vtable writes back to the adjacent alpha-surface constructor/helper/destructor region. `xrefs_to 0x004632c0` remains vtable-only through `0x00612574`, preserving the exclusion of the following application error-state cleanup.

2026-06-14 C001 IDA MCP refresh reconfirmed the same source split limits with current IDA 9.1 data. `lookup_funcs` reports no function at raw `0x00462120`, modeled helpers at `0x00462170` size `0xb7`, `0x00462260` size `0x22`, `0x00462320` size `0x95`, `0x004623c0` size `0x154`, `0x00462e10` size `0x10e`, `0x00462f20` size `0x332`, and `0x00463270` size `0x41`. `xrefs_to 0x00462120` is still empty; `xrefs_to 0x00462320` still has the single `StaticObjImageLib` caller at `0x004dd66a`; `xrefs_to 0x004623c0` is still empty; `xrefs_to 0x00462f20` still has nine code xrefs with the three raw image-library call sites at `0x004d5ea6`, `0x004d6b16`, and `0x004dcca5`; and `xrefs_to 0x006112ec` still ties the `IntAlphaSurface` vtable writes to the raw default-constructor bytes, active constructor, view initializer, and destructor. The same pass reconfirmed `0x004632c0` as the excluded application error-state cleanup successor through its separate vtable data xref.

2026-06-15 A001 Wave2/IDA support refresh adds a cross-check from the Wave2 method set. Wave2 has no method/global record at `0x004623c0`; `filter --class AlphaMaskSurface --all-methods` includes the constructor, `GetBufferInfo`, `ApplyRectAlpha`, `FillRadialGradient`, and `FillEllipticGradient` but not this helper, while `filter --class IntAlphaSurface --all-methods` only recovers the scalar deleting destructor. Live IDA still models `0x004623c0-0x00462514` as `sub_4623C0`, still finds no incoming xrefs, and still shows the `off_6112EC` vtable write. B009's 2026-06-28 pass resolves the final disposition for this exact helper: it remains physically documented/emitted in this file as `AlphaMaskSurface::InitAlphaSurfaceView(IntAlphaSurface *view, const RectBounds *clipBounds) const`, with `IntAlphaSurface` as the destination type.

2026-06-28 B008 source-quality implementation resolves the `DrawFrameWithBlendMode` free-helper blocker. Current MCP session `b001_000241_20260627` proves the call shape is a member method: the LightObjImageLib callers load the target surface into `ecx`, push only `destinationRect`, `sourceFrame`, `sourceRect`, and `blendMode`, and the callee returns with `retn 10h`. [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md) now emits the formal `AlphaMaskSurface::DrawFrameWithBlendMode` C++ with local `AlphaMaskBlendMode` constants for copy/add/subtract. [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md) is only a non-emitting support index for that source-bearing by-memory page.

2026-07-07 B007 UID0000YL current-session refresh confirms [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md) is aggregate-only source-family documentation, not a monolithic source body. IDA MCP session `ef57d27f` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` reported `server_health ok`, auto-analysis ready, Hex-Rays ready, and strings cache ready. Current function inventory is: active constructor `0x00462170-0x00462227`, EH cleanup `0x00462230-0x00462258`, release helper `0x00462260-0x00462282`, center accessor `0x004622d0-0x004622f7`, buffer accessor `0x00462300-0x00462317`, clipped-view helper `0x00462320-0x004623b5`, view initializer `0x004623c0-0x00462514`, rectangular fill `0x00462520-0x00462672`, radial gradient `0x00462680-0x0046286b`, and elliptic gradient `0x00462870-0x00462e03`, followed by sibling `DrawFrameWithBlendMode` and `DrawEncodedAlphaFrame`. Current generated output `auto-generated/NexusTK/render/AlphaMaskSurface.cpp` had header `validator-command-id: 000000007832` / `validator-refreshed-at: 2026-07-07T03:37:36-04:00` before this callback and emitted exact child/sibling bodies separately while UID0000YL was marker-only. Keep the aggregate formal C++ as a comment-only no-code marker with no `[[CHILDREN]]`; future exact splits are still needed before the constructor, accessors, clipped-view helper, rectangular fill, and gradient fillers emit their own formal bodies.

`IntAlphaSurface` currently has only a scalar deleting destructor recovered at `0x00463270`, plus vtable evidence for the buffer-release slot at `0x00462260`. Its vtable artifact is now assigned to the `IntAlphaSurface` class because RTTI names that class, but keep the source-file colocation caveat near this module until constructor and family ownership are fully identified. IDA vtable refs still tie `off_6112EC` back into the adjacent `AlphaMaskSurface` constructor/helper region; [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) is now one resolved AlphaMaskSurface-owned construction/use-site rather than an unresolved `IntAlphaSurface` method candidate.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `AlphaMaskSurface` raw/default constructor | `0x00462120-0x00462161` | Raw constructor-shaped empty-surface initializer; IDA has no function object or xrefs at the start. |
| `AlphaMaskSurface` | `0x00462170-0x00462e03` | Aggregate-only method family for temporary byte mask buffer construction, clipped/full views, rect fill, radial/elliptic alpha gradients; no monolithic body should emit from the aggregate. |
| `AlphaMaskSurfaceLayout` | object offsets `0x00-0x24` | Shared alpha-surface object layout: vtable, bounds, pixels, width, height, stride, ownership flag. |
| `AlphaSurfaceBufferView` | 0x14-byte POD record | Clipped/non-owning buffer view returned by `GetBufferInfo` and `BuildClippedAlphaSurfaceView`. |
| `IntAlphaSurface` unwind cleanup | [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) | Compiler-generated EH cleanup target; restores the vtable and frees owned pixels during partial construction/unwind. |
| `IntAlphaSurface::ReleaseOwnedPixels` provisional | [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md) | Vtable slot helper that frees owned pixel storage and clears the pointer. |
| `BuildClippedAlphaSurfaceView` provisional | [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md) | Builds a non-owning clipped pixel-buffer view for render/image-library callers. |
| `InitAlphaSurfaceView` | [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) | AlphaMaskSurface helper that placement-initializes a caller-supplied full or clipped non-owning `IntAlphaSurface` view object and assigns `off_6112EC` as destination construction state. |
| `AlphaMaskSurface::DrawFrameWithBlendMode` | `0x00462e10-0x00462f1e` | Member blitter that clips source/destination rectangles and applies copy/add/subtract byte-row modes into this surface. |
| `AlphaMaskSurface::DrawEncodedAlphaFrame` | [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md) | `int` member with `RectBounds *dstRect`, `EPFTileContext *sourceContext`, `RectBounds *sourceOrigin`, alpha ramp endpoints, and modes `0` replace / `1` add / `2` subtract. It consumes `encodedMaskBytes` at `+0x24`; the `88/91` source-bearing page keeps formal C++ blank because its variant return-register contract cannot be normalized safely. |
| `IntAlphaSurface` provisional | `0x00463270-0x004632b1` | Integer/per-pixel alpha surface destructor and vtable evidence; exact class boundary still open. |

## Ownership Decision

Keep this code under render surface/blitter support. `LightObjImageLib` and other asset libraries consume these helpers, but the surface buffers and blend loops are shared infrastructure. Do not fold them into `LightObjImageLib` just because the light constructor is a prominent caller.

Do not keep `0x004632c0` in this alpha-surface family. A 2026-05-25 IDA MCP recheck ties it to vtable `0x00612574`, static initializer `0x00419e80`, atexit cleanup `0x0060c0b0`, and application error-state globals around `0x0067a998-0x0067a9a0`.

For the broader generic surface helper bucket, see [UID:0000OC][Surface](by-file/Surface.md). This file remains the specialized byte-mask/alpha-frame side of the same render layer.

## Cross-References

- [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md)
- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)
- [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)
- [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md)
- [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md)
- [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md)
- [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000UH][DrawEncodedAlphaFrame_00462F20](by-item/DrawEncodedAlphaFrame_00462F20.md)
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md)
- [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md)
- [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)
- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-07-09 B001 UID0000YO source-quality support sync:
  - Score and projected path unchanged.
  - Summary/evidence: recorded UID0000YO at `88/91` as the exact AlphaMaskSurface member helper, preserved its `NexusTK/render/AlphaMaskSurface.cpp` route, added the full EPFTileContext-based signature, classified the three raw xrefs as caller-boundary evidence, and preserved the blank formal body under the accepted return-contract no-code proof.
- 2026-07-07 B007 UID0000YL aggregate implementation support sync:
  - Score and projected path unchanged.
  - Summary/evidence: added current-session `ef57d27f` confirmation that UID0000YL is aggregate-only/no-monolithic-body, records the normalized half-open inventory, and should remain a comment-only marker while exact child/sibling pages emit separately through this file. Generated `auto-generated/NexusTK/render/AlphaMaskSurface.cpp` was checked read-only before callback and had UID0000YL marker-only output with exact child/sibling bodies emitted separately; future exact split pages are still needed before constructor/accessor/fill/gradient bodies can emit.
- 2026-06-28 B009 `InitAlphaSurfaceView` source-quality implementation:
  - Score and projected path unchanged.
  - Summary/evidence: [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) now records formal C++ and source ownership through this file. MCP session `b001_000241_20260627` proves `ECX` is the source `AlphaMaskSurface`, `arg_0` is a caller-supplied `IntAlphaSurface *` destination, `arg_4` is an optional `RectBounds *`, and `0x00462415` is destination vtable construction. No direct callers remain a confidence cap on the child, not a reason to leave this helper as a source-split blocker.
- What existed before: the page documented the alpha-mask surface/blitter cluster, helper boundaries, and split caveats but had unevaluated scores.
- What it was changed to: scores were set to `72/82`.
- Summary and evidence: imported methods, buffer-view helpers, and image-library call sites make the module role strong; completion/confidence stay below higher levels because the raw default constructor and `IntAlphaSurface` split remain provisional.
- 2026-05-30: Raised completion/confidence from `72/82` to `76/86` and replaced stale range-end text with canonical by-memory UID links. Added current evidence from the raw default-constructor and clipped-view verification; source split versus `IntAlphaSurface` and encoded-alpha helper ownership remains provisional.
- 2026-05-30: Raised completion/confidence from `76/86` to `80/88` after current IDA MCP verification of `DrawEncodedAlphaFrame` behavior and caller set. The file/module split remains below high completion because the frame-source type, three raw image-library xrefs, and `IntAlphaSurface` relationship are still open.
- 2026-05-31: Filled validator projected path and refreshed placement evidence.
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the status line kept `render/AlphaMaskSurface.cpp` as one of several possible placements.
  - Changed to: projected path `NexusTK/render/`, proposed module `NexusTK/render/AlphaMaskSurface.cpp`, and scores `82/89`.
  - Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already lists `render/AlphaMaskSurface.cpp`, and the 2026-05-31 IDA MCP recheck reconfirmed the alpha-surface function boundaries, caller set, vtable-write neighborhood, and `0x004632c0` exclusion. The score increase is intentionally small because the raw default constructor, frame-source type, and final `IntAlphaSurface` split remain open.
- 2026-05-31: Promoted `InitAlphaSurfaceView` from by-item-only tracking to exact by-memory tracking.
  - What existed before: the file page linked [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md) as the only durable page for the `0x004623c0` helper.
  - Changed to: the contents table and cross-references now point to [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md), with the old item retained as an index.
  - Summary/evidence: IDA MCP confirms `0x004623c0-0x00462514` as an exact modeled function; `by-memory` is the canonical home for full function/range documentation.
- 2026-06-06: Replaced stale recovered-source provenance wording without changing score or path.
  - What existed before: status and helper caveats named old recovered source containers directly.
  - Changed to: the page now uses recovered labels and the existing IDA-backed by-memory/type docs as the evidence basis for the same `NexusTK/render/AlphaMaskSurface.cpp` placement.
  - Summary/evidence: the existing IDA boundary, caller, vtable-write neighborhood, and `0x004632c0` exclusion evidence still supports the same render surface/blitter source assignment while leaving the raw default constructor, frame-source type, and `IntAlphaSurface` split open.
- 2026-06-08 B001/supervisor RTTI ownership application:
  - Scores and parent metadata unchanged.
  - Summary/evidence: updated the `IntAlphaSurface` caveat after [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) was assigned to [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md) on RTTI evidence. This file remains a plausible physical source colocation candidate because constructor/view helpers write the vtable, but it is not the direct class/type owner.
- 2026-06-14 C001 Goal 2 file refresh:
  - Before: `82/89`; the page had strong previous IDA evidence but no current pass tying the raw/default constructor, active helper family, encoded-frame xrefs, and successor exclusion together.
  - After: `84/90`; owner/emitter routing and projected path unchanged.
  - Summary/evidence: live IDA MCP session `a001_goal2_class_batch` reconfirmed raw `0x00462120` non-function/no-xref status, modeled helper sizes, single `0x00462320` caller, no direct `0x004623c0` callers, nine `0x00462f20` xrefs with three raw image-library call sites, `off_6112EC` vtable-write family, and `0x004632c0` exclusion. Completion stays below high because final frame-source type and the `IntAlphaSurface` physical source split remain open.
- 2026-06-15 A001 Goal 2 Wave2 support refresh:
  - Before: `84/90`.
  - After: `85/90`; owner/emitter routing and projected path unchanged.
  - Summary/evidence: Wave2 method filters omit `0x004623c0` from both `AlphaMaskSurface` and `IntAlphaSurface` method sets while live IDA continues to model the body at `0x004623c0-0x00462514`, with no incoming xrefs and the `off_6112EC` view-vtable write. This clears the direct support gate for [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) without pretending the final `IntAlphaSurface` physical source split is solved.
- 2026-06-28 B008 `DrawFrameWithBlendMode` source-quality implementation:
  - Score and projected path unchanged.
  - Summary/evidence: [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md) now records the exact `thiscall` proof, caller set, byte-span helper dispatch, rejected free-helper/LightObjImageLib ownership alternatives, and formal `AlphaMaskSurface::DrawFrameWithBlendMode` C++. This file remains the source owner for the member blitter, while LightObjImageLib remains only a consumer.
- 2026-07-02 B003 UID00041R `DrawEncodedAlphaFrame` support sync:
  - Score and projected path unchanged.
  - Summary/evidence: recorded the UID00041R-proven `AlphaMaskSurface` thiscall route for [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md), including return `int`, `RectBounds *dstRect`, `EPFTileContext *sourceContext`, `RectBounds *sourceOrigin`, alpha ramp endpoints, blend mode `1`, mode meanings `0/1/2` as replace/add/subtract, and the `overlayStrength * 32.0f + 0.5f` transform. Broader frame-source names and raw xrefs remain provisional.
