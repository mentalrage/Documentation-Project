*** UID:00000U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BalloonObjectPane

## UID0003Z4 Owner-Slot Synchronization - 2026-07-14

- Concrete type-6 construction callers at `0x0050e1df` and `0x0051192c` register the newly constructed BalloonObjectPane through [UID:0004QJ][0x0053ada0-0x0053adb0.LivingObjectPaneSetBalloonObjectPane](by-memory/0x0053ada0-0x0053adb0.LivingObjectPaneSetBalloonObjectPane.md), exact owner slot `+0x1d8`.
- UID0004QJ is a borrowed one-store setter; it does not delete or compare the previous value. [UID:0004QH][0x0053ab40-0x0053ad03.LivingObjectPaneDestroyAllLinkedObjects](by-memory/0x0053ab40-0x0053ad03.LivingObjectPaneDestroyAllLinkedObjects.md) deletes and nulls this exact Balloon slot. UID0001DF type 6 clears the same slot during attached-pane destruction.
- The former claim that Balloon cleanup identifies owner `+0x1e4` as a Balloon/nameplate slot is historical and rejected. `+0x1e4` is the distinct ObjectInfoObjectPane slot proven by type-9 construction, setter, packet caller, and unregister behavior.
- Preserve all Balloon rendering, text, attachment, destructor, vtable, source-route, and score evidence unrelated to this corrected owner link.

## Status

- Confidence: strong for behavior, vtable ownership, constructor callers, IDA-modeled methods, static masks, and static pool support; medium-high for raw source-shaped helpers at `0x00468250` and `0x00468e00` because no direct callers are recovered for either raw entry.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Static PaintBubble mask table: [UID:000276][0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks](by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md), source-facing `s_balloonFrameMasks` with formal writable byte-row C++ in the child page.
- Static pool storage: [UID:0002WU][0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage](by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md)

## Class Purpose

`BalloonObjectPane` renders and positions speech balloons attached to map objects. It wraps chat text into lines, creates a cached GrafPort, draws the balloon frame/tail/text, and moves the balloon relative to the speaking object's screen position.

## Class Shape

- Base family: [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)-derived overlay pane.
- Render state: cached bubble surface/GrafPort, wrapped text lines, frame/tail dimensions, color state, and current bounds.
- Placement role: repositions relative to attached object screen coordinates and direction-specific offsets.
- Source placement: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), near other attached-object overlay panes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PaintBubble` | `0x00467b30-0x00468241` | Draws balloon frame pieces, optional tail, colors, and text lines. |
| `RefreshBubbleSurface` | `0x00468250-0x004682bc` | Repaints cached GrafPort if bounds are non-empty; source-shaped raw body, but exported records and PE scan found no direct caller. |
| constructor | `0x004682c0-0x0046849c` | Builds the attached-object base, stores text/color state, and initializes layout/surface state. |
| constructor cleanup helper | `0x004684a0-0x0046851d` | Resets vtables, releases owner/cached GrafPort state, and tears down the attached base. |
| `UpdatePositionForDirection` | `0x00468520-0x004687fc` | Repositions balloon for a direction-relative owner offset. |
| `UpdatePosition` | `0x00468800-0x00468aab` | Repositions the balloon based on current attached screen position. |
| provisional `ClearOutputRects` | `0x00468ab0-0x00468ada` | Clears two caller-supplied Rect-like output bounds; older `ClearRenderBounds` wording is a behavioral alias only. |
| `BlitBubbleSurface` | `0x00468ae0-0x00468b81` | Locks and blits the cached bubble GrafPort to the target position; older `MoveBubbleSurface` wording under-describes the copy/draw behavior. |
| `CalculateLayout` | `0x00468b90-0x00468df1` | Wraps text, computes balloon dimensions, and updates tail placement. |
| `MeasureWrappedTextWidthRaw` / `WrapTextLines` | `0x00468e00-0x00468f65` | Source-shaped raw helper that writes wrapped line offsets/count and returns measured width plus one; no direct caller recovered. |
| adjustor thunks | `0x00468f65-0x00468f7b` | Secondary and tertiary this-adjustors for the deleting destructor. |
| destructor | `0x00468f80-0x0046904e` | Releases cached surface and attached base state. |
| `GetAttachedScreenPos` | `0x005386c0-0x005387a3` | Shared attached-screen-position helper used by multiple overlays. |

## Field Notes

| Offset | Recommended name | Evidence |
| --- | --- | --- |
| `+0x128` | `m_attachedObject` | Constructor/base route stores the living/object pane this balloon is attached to. |
| `+0x12c` | `m_text[70]` | Constructor copies text with capacity `0x46` wide chars and clamps `textLength` to `0x45`. |
| `+0x1b8` | `m_textPaletteIndex` | Constructor stores the palette index produced by MapPane creation helpers from subtype/style constants `143`, `14`, `9`, `200`, and `253`; older `m_balloonStyle` wording describes the upstream packet style, not the stored field. |
| `+0x1bc` | `m_customTextRgb` / `m_customPrimaryTextRgb` | Paint consumes this as optional custom primary text RGB state; exact historical identifier remains inferred. |
| `+0x1c0` | `m_customSecondaryTextRgb` | Paint writes this into the next palette entry for custom speech style; exact historical identifier remains inferred, and outline semantics are not yet proven. |
| `+0x1c4` | `m_lineCount` | `CalculateLayout` and raw `MeasureWrappedTextWidthRaw` / `WrapTextLines` write wrapped line count. |
| `+0x1c6` | `m_lineOffsets[]` / `m_lineBreakIndexes[]` | Layout/wrap helpers write per-line UTF-16 text offsets. |
| `+0x1d8` | `m_tailSide` / `m_tailDirection` | Layout chooses balloon tail side; exact source name remains inferred. |
| `+0x1da` | `m_tailOffset` | Tail placement field used by paint/layout; exact source name remains inferred. |
| `+0x1dc` | `m_bubbleGrafPort` | Constructor allocates/configures cached software-backed `GrafPort`; destructor deletes it. |

Constructor parameter correction: the old `a6` decompiler argument is `textLength`, not a style or custom-color mode. The constructor signature should be documented as `(attachedObject, anchorX, anchorY, text, textLength, textPaletteIndex, customTextRgb, customSecondaryTextRgb)`. Packet/style names are caller-side concepts; the stored class fields are palette/custom-RGB state.

## Evidence Notes

- Live IDA MCP on 2026-06-04 confirms function objects at every method entry listed above except the raw `0x00468250` helper. That helper is still code bytes with a prologue, security cookie, cached GrafPort check, bounds check, `PaintBubble` call, and unlock/return sequence.
- B005's 2026-06-19 accepted source-quality pass revalidated exported records and a local PE branch scan: `0x00468250` and `0x00468e00` have no direct E8/E9 branch hits; `PaintBubble`, the constructor, `CalculateLayout`, and the deleting destructor wrapper have the expected direct internal branches/calls. The pass therefore keeps both raw helpers documented with source-facing names and explicit liveness caveats.
- MapPane speech packet handlers at `0x0050e100` and `0x00511710` construct the balloon at call sites `0x0050e1b9` and `0x00511906`, then register the overlay through `0x0053ada0`.
- Constructor decompilation installs BalloonObjectPane vtables at `0x00613064`, `0x006130dc`, and `0x0061310c`, clamps copied text to `0x45` wide characters, stores layout/color fields, allocates a cached GrafPort at `+0x1dc`, runs `CalculateLayout`, and performs an initial `PaintBubble`.
- Vtable data places the clear-output-rects helper, cached-surface blit helper, the shared ObjectPane empty-rect helper, and the two update-position methods in the primary BalloonObjectPane vtable, with secondary destructor adjustors in the two secondary slices.
- `PaintBubble` references the six [UID:000276][0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks](by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md) entries and uses `g_useEpfAssets`, `g_pPaletteLib`, `g_pConfig + 0x28de5c` as a weak speech-balloon fill/background option, GrafPort, palette, and text draw helpers. `CalculateLayout` and raw `MeasureWrappedTextWidthRaw` / `WrapTextLines` call [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md); `CalculateLayout` also calls [UID:0002QQ][0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect](by-memory/0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect.md).
- A004 live IDA MCP on 2026-06-12 verifies that [UID:000276][0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks](by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md) is an exact six-dword class-owned static table: every xref is inside `sub_467B30`/`PaintBubble`, and the table is bounded by the padding child at `0x0066d412-0x0066d414` and the AutoInit vptr child at `0x0066d42c`.
- B004 live IDA MCP on 2026-06-25 reconfirms [UID:000276][0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks](by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md) as source-ready class-owned static data named `s_balloonFrameMasks`: exact bytes, unique signature, all nine xrefs inside `PaintBubble`, and formal writable byte-row C++ now live in the child page. This class page keeps score `85/90` and blank formal C++ because it is still an aggregate class page.
- UID0002TE source-quality closure resolves all nine `PaintBubble` mask xrefs as calls through [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) `SurfaceBitmaskBlitProc g_pfnBlitBitmask`. Calls at `0x00467c29`, `0x00467c5e`, `0x00467c92`, `0x00467cd3`, `0x00467d08`, `0x00467d39`, `0x00467d6b`, `0x00467e5d`, and `0x00467efb` pass the cached destination `GrafPort` in `ECX`, a raw MSB-first packed 1bpp mask row, a destination `RectBounds`, and mode `1`; the slot returns `void`, so no call consumes a result. Mode `1` writes the primary draw color only for set mask bits. BalloonObjectPane owns the mask rows and placement rectangles, while Surface owns the shared slot, pixel-format selection, and the [UID:0002TE][0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback](by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md) / [UID:0002TI][0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback](by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md) providers. This rejects historical `dword_69B3F8`, return-byte, and Balloon-owned callback interpretations without changing class ownership or aggregate formal C++.
- [UID:0002WU][0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage](by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md) now records the exact `0x28`-byte static `PoolAllocator` storage, current zero-filled bytes, block size `480` / `0x1e0`, chunk count `16` / `0x10`, startup wrapper `0x0041a040`, cleanup wrapper `0x0060c320`, constructor allocation/free paths, destructor free through `0x00468f80`, and first-draft declaration `static PoolAllocator g_balloonObjectPanePool(0x1e0, 0x10);`. The name is best-inferred from [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md); exact original spelling/linkage remains inferred, so numeric constants stay until a final class-layout pass can safely use `sizeof(BalloonObjectPane)`.
- `PaintBubble` uses [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md) as typed GrafPort palette accessors. At `0x00467fc2` it saves the current borrowed `DLPalette *`; after mutating the PaletteLib embedded palette through `DLPalette::SetColor`, `0x0046801f` installs that palette for custom-color drawing; after restoring packed entries through `DLPalette::SetPackedColor`, `0x00468229` restores the saved pointer. This save/install/restore use rejects BalloonObjectPane and `UserHairColorSelectListPane` ownership of the GrafPort methods.

## Score Rationale

Score remains `85/90`. The accepted B005/B008 [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md) implementation improves the executable aggregate to `88/91` and reroutes that aggregate's direct owner/emitter to this class, but this class page still keeps blank formal C++ and file parent [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md). The page now records the full method split, `MeasureWrappedTextWidthRaw` / `WrapTextLines`, field names, constructor `textLength`, static masks/pool, and raw-helper liveness caveats. It remains below final-source level because method child pages have not been split and exact custom-color/tail/base virtual names remain inferred.

## Assignment Gate

`AUTOGEN_PARENT_UID` remains [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md). The child class clears `85/90`, the direct file parent clears the strict gate, and the exact static-data children now route here: [UID:0002WU][0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage](by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md) at `88/93` with formal `g_balloonObjectPanePool` declaration and [UID:000276][0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks](by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md) at `89/93` with formal source-ready static data.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md)
- [UID:000276][0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks](by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md)
- [UID:0002WU][0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage](by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md)
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md)

## Changes

- 2026-07-28 B002 UID0002TE callback-consumer closure:
  - Score, ownership, and blank aggregate class formal C++ remain unchanged.
  - Added the exact nine `PaintBubble` calls, void `SurfaceBitmaskBlitProc` ABI, packed-mask/destination-bounds/mode-1 contract, provider pair, and consumer-only Surface ownership boundary.
- 2026-07-12 B004 UID000163 consumer sync:
  - Score, metadata, and aggregate class formal C++ remain unchanged.
  - Added exact PaintBubble palette save/install/restore call sites and borrowed `DLPalette *` semantics; UID000163 remains owned/emitted by GrafPort, with no BalloonObjectPane ownership or lifetime transfer.
- 2026-06-25 B004 accepted [UID:000276][0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks](by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md) source-quality implementation:
  - Score unchanged at `85/90`; formal C++ remains blank for the aggregate class page.
  - Updated the static mask status/evidence to name `s_balloonFrameMasks` and record that the child page now contains formal writable byte-row C++ at `89/93`.
  - Summary/evidence: current 2026-06-25 live IDA MCP reconfirmed exact bytes, unique signature, PaintBubble-only xrefs, and adjacent boundaries for the child static data.
- 2026-07-01 B009 accepted AttachedObjectPane empty-emitter first batch:
  - Score unchanged at `85/90`; formal class C++ remains blank because unsplit methods, inferred custom-color/tail/base-virtual names, and raw helper liveness caveats still block class-declaration emission.
  - Updated [UID:0002WU][0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage](by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md) support to `88/93` with current zero-filled byte evidence and first-draft `static PoolAllocator g_balloonObjectPanePool(0x1e0, 0x10);`.
- 2026-06-21 B008 [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md) source-quality incorporation:
  - Score unchanged at `85/90`; formal C++ remains blank.
  - Refined the class-facing names to `ClearOutputRects`, `BlitBubbleSurface`, and `MeasureWrappedTextWidthRaw` / `WrapTextLines`, reclassified `+0x1b8/+0x1bc/+0x1c0` as text palette/custom-RGB fields, and added the `g_pConfig + 0x28de5c` speech-balloon fill/background dependency.
  - Summary/evidence: B008 independently reviewed the same method island and accepted the existing direct class owner/source-route decision while tightening heuristic names and preserving the no-aggregate-C++ policy.
- What existed before: the page documented the render/layout/positioning methods and IDA boundary caveat but had unevaluated scores.
- What it was changed to: scores were set to `76/86`, and class-shape notes were added for base family, render state, placement role, and source placement.
- Summary and evidence: most anchors are IDA-confirmed and the map speech packet constructors are known; completion remains below full because one imported method lacks an IDA function record and final text/layout fields need fuller reconstruction.

- 2026-06-04 live IDA aggregate pass:
  - What existed before: the class page was scored `76/86`, reconstructable/parent metadata was blank, and it retained stale generated-file and non-IDA boundary wording.
  - What it was changed to: raised to `84/90`, marked reconstructable under [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), replaced the boundary basis with live IDA evidence, added the constructor cleanup helper and destructor adjustor thunks, and recorded constructor/vtable/static-mask evidence.
  - Summary/evidence: live IDA verifies the modeled methods, raw `0x00468250` repaint body, two constructor callers, vtable slices at `0x00613064/0x006130dc/0x0061310c`, `PaintBubble` mask/data refs, and destructor cleanup through the cached GrafPort and attached base.
- 2026-06-11 A004 Batch 234 parent-gate repair:
  - Before: `84/90`, already assigned to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) but one completion point below the corrected direct-parent gate.
  - After: `85/90`, same direct file parent.
  - Summary/evidence: the associated exact pool-storage page now records current IDA evidence for the `0x0069b9fc` pool, including startup/cleanup wrappers, allocation/free xrefs, and scalar deleting destructor free through `0x00468f80`. That makes the class and direct file parent both clear the strict `85/85` gate.
- 2026-06-12 A004 Goal 2 static-mask parent evidence:
  - Before: class page referenced the PaintBubble mask table only generally.
  - After: score unchanged at `85/90`, with explicit static-mask child status, evidence, cross-reference, and assignment-gate wording for [UID:000276][0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks](by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md).
  - Summary/evidence: live IDA MCP confirms all `0x0066d414-0x0066d42c` xrefs are confined to `sub_467B30`/`PaintBubble`, making the class the closest routable parent once both child and class clear `85/85`.
- 2026-06-20 B005 accepted [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md) source-quality implementation:
  - Score unchanged at `85/90`; formal C++ remains blank.
  - Added the full aggregate split map including raw `WrapTextLines`, field recommendations, constructor `textLength` correction, resolved collaborator names, and explicit no-direct-caller evidence for `RefreshBubbleSurface` and `WrapTextLines`.
  - Summary/evidence: B005 revalidated the current target/support docs, exported function records, generated rows, and PE branch scan. The executable aggregate now routes directly to this class while still generating through [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
