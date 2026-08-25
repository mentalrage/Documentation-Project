** TARGET-REPORT-UID:00041R **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00041R ItemObjImageLibDrawItemImage Source-Quality Report

## Executive Recommendation

Keep [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](../../../../by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md) reconstructable and owned/emitted by [UID:00006W][ItemObjImageLib](../../../../by-class/ItemObjImageLib.md), but do not insert formal C++ for this pass.

Applied target disposition after implementation:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | keep `00006W` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `EMITTER_UIDS` | keep `00006W` |
| Formal C++ | keep blank |

The target is above the code-entry gate, so I rechecked the named blockers rather than treating them as generic future work. Current MCP and support docs resolve several helper names strongly enough for prose:

- `sub_457A60` is `EPFTileContext::InitTileContext`, initializing the 0x28-byte tile/frame context.
- `sub_4D02F0` is `ResourceLayoutTable::LookupLayoutEntry`, already first-draft C++ in its own page.
- `sub_543D20` is `PaletteLib::IsPaletteFilterEnabled`.
- `sub_543E40` is `PaletteLib::GetSlotPalette`.
- `DrawEncodedAlphaFrame` is the optional alpha-mask overlay helper at `0x00462f20`.
- `RectBounds` is a four-int left/top/right/bottom rectangle; this body uses `dstRect[3]` and `dstRect[1]` as overlay ramp end/start Y.
- `ItemInfo` is the 0x14-byte row struct with `paletteSlot`, `alpha`, and `allowPaletteFilter` directly consumed here.

Formal C++ is still unsafe, but the blocker is now exact rather than generic. The slot-2 callback support and the `DrawEncodedAlphaFrame` support declaration can be repaired now and are required support edits in this report. Those repairs are not enough by themselves to emit UID00041R C++: the RGB565 slot-2 implementation reads the option-record secondary byte at `+0x1c` on the option-kind `3` path, while UID00041R's kind-`3` setup writes only kind `+0x00`, alpha `+0x04`, and palette byte `+0x08`. A zero-initialized source struct would change the binary's uninitialized-stack behavior, while a target-local raw/partially initialized byte record would be decompiler-shaped and would bypass shared support ownership.

The required implementation callback is therefore not target-only. It must repair the Surface slot-2 typedef/options support and the `DrawEncodedAlphaFrame` caller-facing declaration, then keep UID00041R formal C++ blank with the exact option-kind `3` no-code proof unless the supervisor separately accepts a behavior-preserving source policy for the shared `SurfaceSpriteBlitOptions` uninitialized secondary field.

Implementation callback status: accepted by supervisor and applied in place. Target/support by-* docs were edited only under the accepted UID00041R scope; generated files and coverage/research reports were refreshed only by scoped validator `--apply --wait-generated` side effects, not manual edits. No by-project-structure docs, archives, queues, locks, IDA DB files, or project-level generated reports were manually edited.

## Current Target State

Current target metadata after callback:

| Field | Current value |
| --- | --- |
| Path | `by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md` |
| UID | `00041R` |
| Score | `88/91` |
| Owner/emitter | `CANONICAL_OWNER:00006W`, `EMITTER_UIDS:00006W` |
| Reconstructable | `TRUE` |
| Formal C++ | blank |

The current page already identifies this as `ItemObjImageLib::DrawItemImage`, the general `ITEM.EPF` item-sprite path with optional alpha-mask overlay output. Its no-code proof is directionally correct, but it should be tightened: several helpers now have accepted source-facing names in current support docs, the slot-2 callback typedef/return and alpha-frame helper declaration require support-page repair, and the RGB565 option-kind `3` `+0x1c` read prevents safe target formal C++ even after those support declarations are repaired.

## Evidence Checked

Current local docs checked:

- [UID:00041R][target draw method](../../../../by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md)
- [UID:00006W][ItemObjImageLib class](../../../../by-class/ItemObjImageLib.md)
- [UID:0000KH][ItemObjImageLib file](../../../../by-file/ItemObjImageLib.md)
- [UID:00017N][ItemObjImageLib local method cluster](../../../../by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md)
- Sibling draw pages [UID:00041S], [UID:00041T], and [UID:00041U]
- [UID:0001UT][ItemInfo](../../../../by-type/by-struct/ItemInfo.md)
- [UID:0001UU][ItemObjImageLibLayout](../../../../by-type/by-struct/ItemObjImageLibLayout.md)
- [UID:0000XY][EPFTileContext](../../../../by-memory/0x00457a60-0x00458610.EPFTileContext.md)
- [UID:0002KP][ResourceLayoutTableLookupLayoutEntry](../../../../by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md)
- [UID:0001E6][PaletteLibMethodCluster](../../../../by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md)
- [UID:0001PI][SurfaceRenderCallbackTable](../../../../by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md)
- [UID:0000YO][DrawEncodedAlphaFrame](../../../../by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md)
- [UID:0001XH][ImageLibraryLoadErrorFlag](../../../../by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md)
- Generated rows in `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-research-tracker.md`, read-only.
- Generated source `auto-generated/NexusTK/render/ItemObjImageLib.cpp`, read-only.

Prior B reports used as leads:

- B005 `00017N-ItemObjImageLibLocalMethodCluster-source-quality.md`
- B008 `00006W-ItemObjImageLib-class-source-quality.md`
- B007 `0000KH-ItemObjImageLib-empty-emitter-family-source-quality.md`

Exact assignment search terms checked with `rg`: `00041R`, `0x004dee50`, `0x004defba`, `ItemObjImageLibDrawItemImage`, `DrawItemImage`, `ItemObjImageLib`, `ITEM.EPF`, `unk_69B3E8`, `DrawEncodedAlphaFrame`, plus the named helper symbols.

## Current MCP Evidence

MCP was mandatory and available.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Server: `ida-pro-mcp`, protocol `2025-06-18`
- Active IDB: `supervisor_resume_20260629`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` input image: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`, imagebase `0x400000`
- Health: `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready
- 2026-07-02 resume health probe: `idb_list` reports active session `supervisor_resume_20260629`, not analyzing, worker pid `14860`; `server_health` reports `ok`, Hex-Rays ready, strings cache size `2067`.

Narrow MCP calls used: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `stack_frame`, `xrefs_to`, `xref_query`, `search_text`, `get_bytes`, `export_funcs`, `entity_query`, and `int_convert`.

Important target facts:

| Fact | MCP evidence |
| --- | --- |
| Function boundary | `lookup_funcs 0x004dee50` -> `sub_4DEE50`, size `0x16a` / 362 bytes. `0x004defba` is not a function. |
| ABI shape | Decompile and disassembly show `int __thiscall sub_4DEE50(_DWORD *this, int a2, int *a3, __int16 a4, unsigned __int8 a5, int *a6, float a7)` and `ret 18h`, six stack args after `this`. |
| Caller reachability | `xrefs_to 0x004dee50` reports 29 code xrefs from item/UI consumers, including `sub_5205C0`, `sub_537C30`, `sub_570FC0`, and `sub_5A0640`. |
| Guard | Body exits around `unk_69B420`; `ImageLibraryLoadErrorFlag` support lists this exact target as an ItemObjImageLib draw guard consumer. |
| Resource index | Computes `(unsigned short)(itemId + 0x4000)`; MCP `int_convert` confirms `0x4000` is 16384. |
| Item row | Uses `this+8` as count, `this+0xc` as the `ItemInfo` entry buffer, and `this+0x14` as the fallback/default `ItemInfo` row. |
| Resource layout | Calls `sub_4D02F0(dword_67A744, off_61C288, entryIndex, tileContext)`, i.e. `ResourceLayoutTable::LookupLayoutEntry(g_pEPFLib, L"ITEM.EPF", ...)`. |
| Palette logic | Calls `sub_543D20(dword_67A7E0)` and `sub_543E40(dword_67A7E0, 10, itemInfo.paletteSlot, paletteFlags >> 5)`. |
| Draw dispatch | Calls callback slot `dword_69B3E8` / `unk_69B3E8` with `tileContext`, source/destination rectangles, mode `1`, palette pointer, and optional stack render-option record. |
| Overlay dispatch | If `overlayMask` is non-null, calls `sub_462F20(overlayMask, dstRect, tileContext, frameRect, dstRect[3], round(overlayStrength * 32.0f + 0.5f), dstRect[1], 0, 1)`. |
| Option stack layout | Local option base uses kind at +0x00, float alpha at +0x04, palette/tint byte at +0x08, and a secondary byte at +0x1c only for the non-alpha palette/tint path. The alpha-plus-palette kind-3 path does not write +0x1c. |

Helper MCP facts:

| Address/global | Current role | Evidence |
| --- | --- | --- |
| `0x00457a60` / `sub_457A60` | `EPFTileContext::InitTileContext` | Decompile clears the 0x28-byte context, sets first dword to `1`, zeroes pointers/stride/mask fields, and calls `sub_4B7C50` to zero the embedded rectangle. EPFTileContext support names the helper and layout. |
| `0x004d02f0` / `sub_4D02F0` | `ResourceLayoutTable::LookupLayoutEntry` | Existing support page has first-draft C++; MCP decompile matches lazy resource lookup, bounds check, and tile-context output field mapping. |
| `0x00543d20` / `sub_543D20` | `PaletteLib::IsPaletteFilterEnabled` | MCP decompile returns `this[1]`; PaletteLib support names the tiny accessor. |
| `0x00543e40` / `sub_543E40` | `PaletteLib::GetSlotPalette` | MCP decompile selects source/runtime palette banks, super-palette variants, category `10`, and slot modulo table count. PaletteLib support names this method. |
| `0x0069b3e8` / `dword_69B3E8` | shared Surface render callback slot 2 | SurfaceRenderCallbackTable support records the slot as primary tile/frame blit callback with 114 direct xrefs, installed by compat/RGB565 callback families. It also warns generated callsite aliases/signatures are provisional. |
| `0x00462f20` / `sub_462F20` | `DrawEncodedAlphaFrame` | Support page records the target caller at `0x004defa2` and a candidate signature, but keeps formal C++ blank because `EncodedFrame`/alpha helper signatures are still provisional. |

Slot-2 implementation facts checked after the supervisor rejection:

| Address | Physical call shape | Option-record evidence |
| --- | --- | --- |
| `0x004bc090` (`SoftwareRenderCompatSpriteBlitCallback`) | `ecx` receiver plus six stack args, `retn 18h`; Hex-Rays/exported prototype models return through `al`; stack frame has `arg_0`..`arg_14`. | Final argument is a pointer: `0x004bc2e6` loads `arg_14`, `0x004bc2f1` reads kind `+0x00`, and the jump table at `0x004bd400` routes option tags. Tag 1 routes to `0x004bc461`, tag 2 to `0x004bc316`, and tag 3 to `0x004bc5c8`. It reads +0x08 at `0x004bc32a` / `0x004bc5d5`; bounded `search_text '+1Ch'` over this function returned zero hits. |
| `0x004c0f80` (`SoftwareRenderRgb565SpriteBlitCallback`) | `ecx` receiver plus six stack args, `retn 18h`; Hex-Rays/exported prototype models return through `al`; stack frame has `arg_0`..`arg_14`. | Final argument is a pointer: `0x004c12ec` tests `arg_14`, `0x004c12f6` loads it, `0x004c12f9` reads kind `+0x00`, and the jump table at `0x004c313c` routes option tags. Tag 1 routes to `0x004c165a`, tag 2 to `0x004c1327`, and tag 3 to `0x004c1882`. RGB565 reads +0x04 at `0x004c165f` / `0x004c19af`, +0x08 at `0x004c1355` / `0x004c188b` / `0x004c1edc`, and +0x1c at `0x004c138a`, `0x004c189d`, and `0x004c1eee`. |

`entity_query` around `0x0069b3e8` did not produce a final source symbol beyond current raw/table names. Current support pages do, however, provide enough evidence to name the slot as `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` and to repair its declaration. The accepted support typedef is still not usable for UID00041R because its return and final argument type are wrong for this caller.

## Behavior Reanalysis

The source-facing behavior is now specific enough for target prose:

1. If the shared image-library load/error guard is set, return the incoming result/default state without drawing.
2. Initialize a stack `EPFTileContext`.
3. Compute the `ITEM.EPF` frame index as `static_cast<unsigned short>(itemId + 0x4000)`.
4. Select `m_itemInfos[index]` when in range, otherwise use the protected-array default row at object `+0x14`.
5. When palette filtering is active and `ItemInfo::allowPaletteFilter` is false, skip the color draw but still allow the optional overlay helper to run.
6. Resolve the `ITEM.EPF` frame through `ResourceLayoutTable::LookupLayoutEntry`.
7. Resolve the palette with `PaletteLib::GetSlotPalette(10, itemInfo.paletteSlot, paletteFlags >> 5)`.
8. Select a local render-option record:
   - no alpha and no palette flags: pass null options and draw into caller `dstRect`;
   - no alpha and palette flags: kind `2`, palette/tint byte at +0x08, secondary byte zero at +0x1c, draw into caller `dstRect`;
   - alpha and no palette flags: kind `1`, float alpha at +0x04, draw from the resolved frame rect;
  - alpha and palette flags: kind `3`, float alpha at +0x04, palette/tint byte at +0x08, and no write to secondary byte +0x1c, draw from the resolved frame rect.
9. Dispatch the actual image blit through `dword_69B3E8`.
10. If `overlayMask` is non-null, draw encoded alpha data into it with `DrawEncodedAlphaFrame`, using `overlayStrength * 32 + 0.5` rounded/truncated to the byte-like alpha parameter.

The original `drawOwner` parameter is not dereferenced by this body, but it is not dead: UID00041R reloads it into `ecx` before the slot-2 callback. Representative callers pass different render-owner objects, and the slot implementations dereference the receiver as a destination render surface. Support docs should keep `void *drawOwner` for formal prototypes and describe it as the render owner/context forwarded to the blit callback.

## Callback, Option Record, And Overlay Resolution

### Slot 2 Plan

The callback table investigation was incorporated into the approved support docs with this applied slot-2 plan:

| Element | Applied plan | Evidence |
| --- | --- | --- |
| Global slot | `g_pfnBlitSprite` at `0x0069b3e8`, slot 2 of `SurfaceRenderCallbackTable` | Target xrefs, SurfaceRenderCallbackTable docs, and installed compat/RGB565 callback targets. |
| Callback type | `SurfaceSpriteBlitProc` | Existing `SurfaceSpriteBlitHelper` support page already uses this source-facing name. |
| Receiver | `void *destination` / render owner in `ecx` | UID00041R loads `ecx` from `drawOwner`; both slot children read destination surface state through the receiver. |
| Stack arg 0 | `EPFTileContext *sourceContext` | UID00041R passes the local context at `[ebp-0x2c]`; EPFTileContext docs accept the 0x28-byte layout. |
| Stack arg 1 | `const RectBounds *sourceRect` | UID00041R passes `[ebp-0x1c]`, the embedded bounds field at context +0x10. |
| Stack arg 2 | `const RectBounds *destinationRect` | UID00041R passes either caller `dstRect` or the frame bounds depending on alpha handling. |
| Stack arg 3 | draw mode byte/int | UID00041R passes constant `1`; slot decompilation models the physical stack slot as a byte argument. |
| Stack arg 4 | palette pointer | UID00041R passes `PaletteLib::GetSlotPalette(...)`; helper support docs already use the palette role. |
| Stack arg 5 | optional `SurfaceSpriteBlitOptions` pointer | UID00041R passes null or a pointer to the stack option record; both slot children dereference it as a pointer. |
| Return | source-facing `int` status; document the slot implementations' current `al` inference as a physical/decompiler caveat, not as the shared typedef | UID00041R consumes the full callback result as `int`; callers that ignore the return remain compatible with an `int` return. Both installed implementations currently decompile as `char`/`al`, but narrowing the shared typedef to byte status would make UID00041R's existing call semantics harder to preserve. |

The accepted report rejected the stale `void`/scalar-`int flags` support typedef for UID00041R. The applied support state is:

| Support destination | Applied/validated repair |
| --- | --- |
| `by-global/SurfaceRenderCallbackTable.md` | Slot 2 uses an `options` pointer route; `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` is the accepted source-facing alias for slot 2, with `int` status return for source callers and physical `al` return caveats kept as implementation evidence. |
| `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` | The memory-table page mirrors the slot-2 signature: receiver in `ecx`, `EPFTileContext *`, source/destination `RectBounds *`, draw mode, palette pointer, optional options pointer, compat target `0x004bc090`, RGB565 target `0x004c0f80`, and the option offsets listed below. |
| `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md` | The formal typedef and existing calls are repaired: the typedef returns `int`, takes a `void *`/render-owner receiver, uses `EPFTileContext *`, `const RectBounds *` source/destination rects, draw mode, palette pointer, and `const SurfaceSpriteBlitOptions *options`; the two existing helper calls pass null options. Local Win32 `RECT` variables remain limited to DirectDraw `BltFast` calls. |

No new by-type page is required for UID00041R acceptance if the option enum/record is declared in the shared surface blit support block. A later by-type split can be considered after the shared callback typedef validates, but it is not a blocker for this report.

### Target Stack Option Records

The target option records can be described as a shared `SurfaceSpriteBlitOptions` record, but UID00041R cannot safely instantiate that record in formal C++ yet because one observed source path leaves a callback-read field unwritten:

| Kind | UID00041R writes | Slot reads | Source-facing interpretation |
| --- | --- | --- | --- |
| null | No option record | Slot skips option handling | Default blit. |
| `1` | kind +0x00, float alpha +0x04 | +0x00 and +0x04 | Alpha-only blit option. |
| `2` | kind +0x00, palette/tint byte +0x08, zero byte +0x1c | +0x00, +0x08; RGB565 also reads +0x1c at `0x004c138a` | Palette/tint or shift option with secondary shift/bias byte initialized to zero by this target. |
| `3` | kind +0x00, float alpha +0x04, palette/tint byte +0x08; no +0x1c write | +0x00, +0x04, +0x08; RGB565 also reads +0x1c at `0x004c189d` | Combined alpha plus palette/tint option, but target formal C++ is unsafe because the secondary byte is callback-read and target-unwritten. |

Applied support type plan:

| Field | Offset | Type interpretation | Evidence |
| --- | ---: | --- | --- |
| `kind` | +0x00 | unsigned byte enum: alpha = 1, palette/tint = 2, alpha plus palette/tint = 3 | UID00041R writes the tag; both slot children switch on it. |
| `alpha` | +0x04 | float | UID00041R copies `ItemInfo::alpha`; both slot children load scalar float from this offset. |
| `paletteShift` | +0x08 | byte, signedness unresolved but source name should stay neutral | UID00041R writes `paletteFlags`; compat reads the byte and RGB565 sign-extends it before a left shift. |
| `secondaryShift` | +0x1c | signed byte in RGB565 paths; name remains descriptive | UID00041R zeroes this only for kind 2. RGB565 reads it for tag 2 at `0x004c138a`, tag 3 at `0x004c189d`, and later option-family path at `0x004c1eee`; compat does not read it in the checked implementation. |

No defensible route remains for modeling the final callback argument as a scalar flag. The implementations dereference it as a pointer and consume multiple offsets. The applied support docs preserve the `+0x1c` field even though UID00041R only writes it in the kind-2 path, because the RGB565 target reads it in multiple option blocks. That same fact is the final UID00041R formal-C++ blocker: the kind-3 branch cannot be expressed as a normal initialized source struct without changing the observed binary behavior.

### `DrawEncodedAlphaFrame` Disposition

`DrawEncodedAlphaFrame` no longer blocks UID00041R as an unknown helper. Its caller shape is known and the required support edit is applied/validated. The exact caller contract is:

| Argument | UID00041R value | Meaning |
| --- | --- | --- |
| `ecx` | `overlayMask` | Destination alpha mask surface. |
| arg 0 | caller destination rect | Destination clip/draw rect. |
| arg 1 | local `EPFTileContext *` | Source context; helper reads encoded mask bytes from context +0x24. |
| arg 2 | `&tileContext.bounds` | Source origin/bounds pointer. |
| arg 3 | `dstRect->bottom` | End Y for alpha ramp. |
| arg 4 | `overlayStrength * 32.0f + 0.5f`, converted to byte | End alpha. |
| arg 5 | `dstRect->top` | Start Y for alpha ramp. |
| arg 6 | `0` | Start alpha. |
| arg 7 | `1` | Blend mode 1, the helper's additive path. |

The support repair has been applied. The old generic `EncodedFrame`/point candidate is historicalized for this route with the following source-facing declaration plan:

| Element | Applied/validated repair |
| --- | --- |
| Owner/receiver | Treat the helper as an `AlphaMaskSurface` thiscall; `ecx` is the destination alpha mask surface. |
| Return | Keep `int`, matching current decompile, stack/disasm return, and UID00041R's return-consuming overlay path. |
| Source payload | Use `EPFTileContext *sourceContext` for callers like UID00041R because `a3[9]` is `EPFTileContext::encodedMaskBytes` at +0x24. The UID00041R path is no longer blocked on a generic `EncodedFrame` name. |
| Source origin | Use `const RectBounds *sourceOrigin` / `&sourceContext->bounds`, not a separate `Point` type, because the helper reads both origin coordinates from the four-int bounds record passed by UID00041R. |
| Blend mode | Document modes 0 replace, 1 add, and 2 subtract; UID00041R passes mode 1. |
| Call-site transform | Record the UID00041R transform `overlayStrength * 32.0f + 0.5f` into the end-alpha byte, with `dstRect->top`/`dstRect->bottom` as the ramp start/end Y values. |

Support destinations `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md`, `by-class/AlphaMaskSurface.md`, and `by-file/AlphaMaskSurface.md` were updated or verified. The class page now records the helper in its method inventory, and the file page records the UID00041R caller-facing declaration route in the Proposed Contents/file-role support text. The helper body remains blank, but the old generic `EncodedFrame`/`Point` sketch is no longer the active blocker for this target.

### `drawOwner` Disposition

Keep `void *drawOwner`.

Evidence checked and rejected alternatives:

| Candidate | Decision | Evidence |
| --- | --- | --- |
| `void *drawOwner` | Keep | Matches `ItemObjImageLibLayout`; UID00041R only forwards the value as slot receiver; callers pass different render-owner registers/arguments. |
| `GrafPort *` | Reject for UID00041R target signature | Slot support uses GrafPort-like destination semantics, but representative UID00041R callers do not prove all static caller objects are exactly `GrafPort`. |
| Pane/control class pointer | Reject | Callers are UI/control-like, but the target does not dereference pane fields and slot implementations need render-surface state, not pane-specific behavior. |

## Positive Evidence

- The target is a real source-authored `ItemObjImageLib` method: it is a `__thiscall` body, uses `m_itemInfos`, consumes `ITEM.EPF`, calls central resource/palette/render infrastructure, and has 29 direct code xrefs from item-image UI consumers.
- Owner/emitter [UID:00006W] remains correct. UI callers are consumers; ResourceLayoutTable, PaletteLib, EPFTileContext, AlphaMaskSurface, and SurfaceRenderCallbackTable are dependencies.
- The target does not use the legacy item remap constants; those are specific to fixed-slot/scaled/glyph paths. General `DrawItemImage` uses direct `ITEM.EPF` frame index `itemId + 0x4000`.
- `ItemInfo` field usage is better resolved than the current target page suggests: `paletteSlot`, `alpha`, and `allowPaletteFilter` are directly read here; `itemTableId` and `renderFlagsOrMode` remain broader row fields but do not block this behavior description.
- `RectBounds` semantics are sufficient for this target's prose: the draw rectangle is the caller rect, and the overlay helper uses top/bottom Y values from that same rect.

## Negative Evidence / No-Code Proof

Formal C++ should remain blank for UID00041R after this repair pass, but not because the callback, option records, or alpha helper are unknowable. The support-repair path was exhausted far enough to identify a narrower target-specific no-code proof:

1. The current accepted `SurfaceSpriteBlitProc` support declaration is incompatible with UID00041R. It returns `void` and treats the final argument as scalar `int flags`; UID00041R consumes the callback result as an `int` and passes null or a pointer to a structured option record. This support repair is safe and required.
2. The shared `SurfaceSpriteBlitOptions` support repair is also safe and required: both installed slot-2 implementations dereference the final argument as a pointer, switch on kind `+0x00`, and read structured offsets. The option record must include at least kind `+0x00`, alpha `+0x04`, palette/tint `+0x08`, and secondary shift `+0x1c`.
3. The `DrawEncodedAlphaFrame` support repair is safe and required: UID00041R's callsite proves an `AlphaMaskSurface` receiver, `EPFTileContext *sourceContext`, `RectBounds *sourceOrigin`, alpha ramp endpoints, and blend mode `1`.
4. Even after those support declarations are repaired, UID00041R formal C++ is unsafe because the target's option-kind `3` path writes kind `+0x00`, alpha `+0x04`, and palette/tint `+0x08`, but does not write secondary `+0x1c`. The RGB565 slot implementation routes tag `3` to `0x004c1882` and reads `byte ptr [ebx+0x1c]` at `0x004c189d`.
5. A normal source struct such as `SurfaceSpriteBlitOptions options = {};` would force `secondaryShift == 0` for kind `3`, changing the binary's observed uninitialized-stack dependency. An intentionally partially initialized local struct would knowingly encode undefined/uninitialized behavior without an accepted shared support policy. A raw byte array or target-local cast would be decompiler-shaped and would hide a shared ABI issue in one ItemObjImageLib method.
6. `drawOwner` has a defensible target signature as `void *`, but no checked route proves a narrower static class. Using `GrafPort *` or a pane/control type in formal C++ would overclaim representative caller evidence.

Evidence routes checked and rejected:

| Route | Checked evidence | Rejection reason |
| --- | --- | --- |
| Use existing `SurfaceSpriteBlitProc` unchanged | `SurfaceSpriteBlitHelper` formal typedef and UID00041R callsites | Wrong return and wrong final-argument model for this target. |
| Treat final callback argument as flags | UID00041R stack writes, compat slot reads +0x00/+0x08, RGB565 slot reads +0x00/+0x04/+0x08/+0x1c | Implementations dereference a pointer to a record; scalar flags are disproven. |
| Emit a zero-initialized `SurfaceSpriteBlitOptions` local | UID00041R kind-3 write set and RGB565 tag-3 `+0x1c` read at `0x004c189d` | Changes observed behavior by forcing the unwritten secondary byte to zero. |
| Emit an intentionally partially initialized struct or local option bytes | Target disasm and both slot children | The type is shared callback ABI; target-local raw/UB source would be decompiler-shaped and unsupported without a shared options policy. |
| Leave `DrawEncodedAlphaFrame` as an unknown helper | Helper decompile, stack frame, disasm, and target callsite | Caller-specific signature is now known; required support repair replaces the old generic sketch. |
| Narrow `drawOwner` to a class | Representative caller windows and slot child receiver reads | Callers vary and target only forwards receiver; `void *` is the current safe source-facing type. |

These blockers do not prevent improving the target score, prose, helper table, and support repair queue. They do prevent exact `RECONSTRUCTION_CPP CODE` insertion text for UID00041R now. The implementation callback must not leave the support repairs as optional, but after applying them it should preserve UID00041R's blank formal block with this kind-3 `+0x1c` proof unless the supervisor explicitly accepts a shared behavior-preserving representation for the partially initialized options record.

## Heuristic / Inference Reanalysis

| Question | Evidence checked | Decision |
| --- | --- | --- |
| Is this owner really ItemObjImageLib? | `this`-based access to `m_itemInfos`, file/class support docs, 29 caller xrefs, generated route | Yes. Keep [UID:00006W] owner/emitter. |
| Is this general EPF draw or legacy remap draw? | Target decompile/disasm and xrefs to `ITEM.EPF`; no target xrefs to legacy remap constants | General `ITEM.EPF` path only. |
| Can `sub_457A60` remain unresolved? | Current MCP plus EPFTileContext page | No. Document as `EPFTileContext::InitTileContext`. |
| Can `sub_4D02F0` remain unresolved? | Current MCP plus first-draft C++ support page | No. Document as `ResourceLayoutTable::LookupLayoutEntry`. |
| Can palette helpers remain unresolved? | Current MCP plus PaletteLib cluster | No. Document as `IsPaletteFilterEnabled` and `GetSlotPalette`. |
| Is `unk_69B3E8` resolved enough for a support repair plan? | Current target MCP, slot-2 child disasm/stack frames, SurfaceRenderCallbackTable, and SurfaceSpriteBlitHelper | Yes. Use `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, repair return to physical `al`/status behavior, and repair final argument to an options pointer. |
| Is `unk_69B3E8` resolved enough for UID00041R formal C++ before support repair? | Current support typedef plus UID00041R return/options use | No. The accepted typedef is incompatible with this caller. |
| Is `unk_69B3E8` resolved enough for UID00041R formal C++ after support repair? | UID00041R kind-3 write set, RGB565 jump-table mapping, and RGB565 `+0x1c` read at `0x004c189d` | No. Support can declare the shared option record, but target code cannot safely initialize the kind-3 record without changing or intentionally encoding uninitialized-stack behavior. |
| Is overlay helper resolved enough for this caller? | Current target callsite plus DrawEncodedAlphaFrame decompile/disasm/stack frame | Yes for caller-specific signature; no for target formal C++ until the support page declaration is repaired. |
| Should `drawOwner` be `Pane *`? | Caller setup, ItemObjImageLibLayout, and slot receiver reads | No. Use `void *drawOwner`; describe it as a render owner/context forwarded to slot 2. |

## Ranked Owner And Source Placement

1. [UID:00006W] `ItemObjImageLib` class: accepted direct owner/emitter for UID00041R.
2. [UID:0000KH] `NexusTK/render/ItemObjImageLib.cpp`: accepted file root through the class.
3. [UID:0000TN]/[UID:0000OC] Surface callback table / Surface: dependency only for `dword_69B3E8`.
4. [UID:0000BY] ResourceLayoutTable, [UID:00004I] EPFTileContext, [UID:0000A1] PaletteLib, [UID:0000HF] AlphaMaskSurface: dependencies only.
5. UI pane/control callers: rejected as owners; they pass item ids, rectangles, palette flags, and optional masks but do not own item-image policy or storage.

Recommended source placement remains `NexusTK/render/ItemObjImageLib.cpp`, through the class-owned method body once callback/local record declarations become source-quality.

## Claim And Incorporation Ledger

| Claim ID | Claim | Evidence | Action | Destination(s) | Verification state |
| --- | --- | --- | --- | --- | --- |
| C-00041R-001 | `sub_457A60` is not an unresolved generic helper; it is `EPFTileContext::InitTileContext`. | MCP decompile and EPFTileContext page. | applied | Target helper table plus `by-class/ItemObjImageLib.md`, `by-file/ItemObjImageLib.md`, and the local method cluster note. | applied: target/class/file/cluster validators `000000004285`, `000000004287`, `000000004289`, and revalidator `000000004302` all exited `0` / `ok: 1`. |
| C-00041R-002 | `sub_4D02F0` is `ResourceLayoutTable::LookupLayoutEntry`. | Existing first-draft C++ page plus current MCP. | applied | Target helper table/prose; preserve support link to the existing ResourceLayoutTable page. | applied: same target/class/file/cluster validators exited `0` / `ok: 1`. |
| C-00041R-003 | `sub_543D20` and `sub_543E40` are PaletteLib helpers. | PaletteLibMethodCluster rows and current MCP decompile. | applied | Target behavior/helper table plus ItemObjImageLib class/file support notes. | applied: target/class/file validators `000000004285`, `000000004287`, and `000000004289` exited `0` / `ok: 1`. |
| C-00041R-004 | `dword_69B3E8` is slot 2 `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, not an unnamed opaque callback. | SurfaceRenderCallbackTable docs, SurfaceSpriteBlitHelper docs, UID00041R xref, and installed slot targets `0x004bc090`/`0x004c0f80`. | applied | UID00041R target prose, `by-global/SurfaceRenderCallbackTable.md`, `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`, and `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`. | applied: target Touched State and C++ Readiness cite `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`; Surface revalidators `000000004303`, `000000004304`, and `000000004305` exited `0` / `ok: 1`. |
| C-00041R-005 | The accepted `SurfaceSpriteBlitProc` typedef blocks UID00041R only until repaired; the repair is safe and required. | B005 had already repaired the typedef to `int` return and options pointer; UID00041R consumes a return and passes an options pointer; helper callers that ignore return remain compatible with `int`. | already-present | `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`, `by-global/SurfaceRenderCallbackTable.md`, and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`. | already-present: B005 had already applied the shared `int` return plus nullable `const SurfaceSpriteBlitOptions *options` repair; B003 kept it and added UID00041R proof in revalidated Surface docs `000000004303`/`000000004304`/`000000004305`. |
| C-00041R-006 | Target stack options are a discriminated `SurfaceSpriteBlitOptions`-style record, but UID00041R cannot safely emit a source local for option kind `3`. | UID00041R writes kind +0x00, alpha +0x04, palette/tint +0x08, and secondary +0x1c only for kind 2; RGB565 reads +0x1c for tag 3 at `0x004c189d`; compat has no +0x1c hits. | applied | Add the option enum/record offset map to `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`, `by-global/SurfaceRenderCallbackTable.md`, and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`; preserve UID00041R no-code proof on the target page. | applied: target and Surface docs record `+0x00/+0x04/+0x08/+0x1c`, kind `1`/`2`/`3`, RGB565 `+0x1c` reads, and UID00041R kind-3 no-code proof; validators `000000004285`, `000000004303`, `000000004304`, and `000000004305` passed. |
| C-00041R-007 | Overlay argument order and caller-specific types are known for UID00041R; the repair is safe and required. | Target decompile/disasm plus `DrawEncodedAlphaFrame` stack frame/disasm show `AlphaMaskSurface` receiver, `EPFTileContext`, `RectBounds`, alpha ramp, and mode 1. | applied | Repair `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md`, `by-class/AlphaMaskSurface.md`, and `by-file/AlphaMaskSurface.md` with the caller-facing `AlphaMaskSurface` thiscall declaration route. | applied: validators `000000004299`, `000000004300`, and `000000004301` exited `0` / `ok: 1`; by-memory/class/file AlphaMaskSurface docs record the UID00041R route and mode meanings. |
| C-00041R-008 | Formal prototypes should keep `void *drawOwner`. | Target forwards it as callback receiver; representative callers vary; ItemObjImageLibLayout already uses `void *`; slot children read render-surface receiver state. | applied | UID00041R target signature/prose, ItemObjImageLib class/file support notes, and local method cluster; mark `by-type/by-struct/ItemObjImageLibLayout.md` already compatible unless the callback explicitly requests a short citation. | applied: target/class/file/cluster use `void *drawOwner`; `by-type/by-struct/ItemObjImageLibLayout.md` was verified already-present with all four draw prototypes using `void *drawOwner`, so no layout edit was made. |
| C-00041R-009 | Score can rise despite no formal C++. | Current MCP recheck resolves the named blockers into exact support-repair tasks and a route-specific no-code proof. | applied | Raise UID00041R target recommendation to `COMPLETION:88`, `CONFIDENCE:91`; no support score changes are required by this report. | applied: target metadata is `COMPLETION:88`, `CONFIDENCE:91`; validator `000000004285` exited `0` / `ok: 1`. |
| C-00041R-010 | Formal C++ must remain blank after this report because the option-kind `3` record has a callback-read, target-unwritten secondary byte. | UID00041R disasm writes kind `3`, alpha, and palette byte but not +0x1c; RGB565 jump table routes tag `3` to `0x004c1882` and reads +0x1c at `0x004c189d`. | applied | Update `by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md` no-code proof and ensure no checklist item promises target C++ after support repair alone. | applied: target formal C++ remains blank with exact kind-3 `+0x1c` proof; validator `000000004285` passed; generated `auto-generated/NexusTK/render/ItemObjImageLib.cpp` has no UID00041R/`DrawItemImage` body. |

## Implemented Target Changes

Implemented during the accepted supervisor callback on 2026-07-02.

1. Update target metadata to `COMPLETION:88`, `CONFIDENCE:91`; keep owner/emitter/reconstructable unchanged.
2. Change the source-facing signature description to use these argument types/names without adding formal C++: return `int`; receiver `ItemObjImageLib`; arguments `void *drawOwner`, `RectBounds *dstRect`, `short itemId`, `unsigned char paletteFlags`, `AlphaMaskSurface *overlayMask`, and `float overlayStrength`.
3. Add a 2026-07-02 B003 current-MCP evidence subsection with:
   - active MCP session `supervisor_resume_20260629`;
   - `sub_4DEE50` size `0x16a` / 362 and `ret 18h`;
   - 29 direct code xrefs;
   - helper mapping table for `EPFTileContext::InitTileContext`, `ResourceLayoutTable::LookupLayoutEntry`, `PaletteLib::IsPaletteFilterEnabled`, `PaletteLib::GetSlotPalette`, `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, and `DrawEncodedAlphaFrame`.
4. Replaced broad no-code wording with the exact no-code proof above: support repairs for the slot-2 typedef/options record and `DrawEncodedAlphaFrame` declaration are applied/validated, but formal C++ remains blank because option kind `3` leaves callback-read secondary byte `+0x1c` unwritten. Kept `drawOwner` as `void *`.
5. Clarify that this target does not use legacy item remap constants; those belong to UID00041S/UID00041U/glyph helper paths.
6. Keep formal C++ blank with the exact post-support no-code proof: even after the required Surface and AlphaMaskSurface declaration repairs, UID00041R's option-kind `3` path leaves secondary byte `+0x1c` unwritten while the RGB565 slot target reads it at `0x004c189d`. Do not cite the old typedef/declaration mismatch as the final blocker after support repair; cite the kind-3 options initialization issue unless a later accepted shared policy resolves it.

## Implemented Support Changes

Implemented or verified during the accepted supervisor callback on 2026-07-02.

| Support page | Applied/validated state |
| --- | --- |
| `by-class/ItemObjImageLib.md` | Contains the B003 current-MCP UID00041R note: helper names resolved, `drawOwner` remains `void *`, Surface slot-2 and `DrawEncodedAlphaFrame` support repairs are applied/validated, and formal body remains blank because option kind `3` leaves callback-read `+0x1c` unwritten. |
| `by-file/ItemObjImageLib.md` | Contains the same UID00041R support note under generated-output/draw-method audit and preserves the kind-3 options no-code proof. |
| `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md` | UID00041R row/support note records current MCP proof, `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, and the kind-3 `+0x1c` no-code blocker. |
| `by-type/by-struct/ItemObjImageLibLayout.md` | Already compatible: formal draw prototypes use `void *drawOwner`; no content edit was required by this callback. |
| `by-global/SurfaceRenderCallbackTable.md` | Slot 2 evidence records `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, `int` status return, render-owner receiver in `ecx`, `EPFTileContext *`, source/destination `RectBounds *`, draw mode, palette pointer, and `const SurfaceSpriteBlitOptions *options`; stale scalar flags wording is rejected for nonzero UID00041R/UID00041U callers. |
| `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` | Mirrors the global slot-2 repair and records option offsets kind +0x00, alpha +0x04, palette/tint byte +0x08, secondary byte +0x1c; compat target `0x004bc090` lacks +0x1c reads, and RGB565 target `0x004c0f80` reads +0x1c at `0x004c138a`, `0x004c189d`, and `0x004c1eee`. |
| `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md` | Formal typedef support is repaired: `SurfaceSpriteBlitProc` returns `int`, takes a `void *` render-owner receiver, uses `EPFTileContext *`, `const RectBounds *` source/destination rects, draw mode, palette pointer, and `const SurfaceSpriteBlitOptions *options`; existing helper calls pass null options, and the UID00041R kind-3 initialized-struct blocker is recorded. |
| `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md` | Generic `EncodedFrame`/`Point` wording is historicalized for UID00041R's route; the page records the `AlphaMaskSurface` thiscall declaration plan with `dstRect`, `EPFTileContext *sourceContext`, `RectBounds *sourceOrigin`, alpha ramp endpoints, blend modes 0/1/2, and UID00041R's `overlayStrength * 32.0f + 0.5f` transform. |
| `by-class/AlphaMaskSurface.md` | Method Notes/evidence now includes [UID:0000YO] and records the UID00041R-proven caller-facing `AlphaMaskSurface` route while preserving broader frame-source and source-split caveats. |
| `by-file/AlphaMaskSurface.md` | Proposed Contents/file-role support text records the same UID00041R caller-facing declaration route, mode meanings, and the fact that UID00041R no longer depends on a generic free-helper or `EncodedFrame`/`Point` sketch for this call. |

Scoped validator commands run from `source-3/project-documentation` during this accepted implementation batch:

> Executable block R001 was removed from this report and preserved verbatim in [00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality-removed.md](00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated output freshness was checked after validators for `auto-generated/NexusTK/render/ItemObjImageLib.cpp`, `auto-generated/NexusTK/render/AlphaMaskSurface.cpp`, `auto-generated/NexusTK/render/Surface.cpp`, and `auto-generated/NexusTK/render/GrafPort.cpp`. These were validator refreshed only; no generated or coverage files were manually edited.

## Score And Metadata Rationale

Completion `88`: the method behavior, owner route, call signature shape, resource/palette/overlay helper roles, slot-2 support repair, option-record model, `DrawEncodedAlphaFrame` caller route, and target-specific no-code proof are now current-MCP-backed and incorporated into the approved by-* docs. It should not go higher until the supervisor accepts either the current blank-C++ proof as final for this target or a shared behavior-preserving policy for UID00041R's partially initialized kind-`3` option record.

Confidence `91`: current MCP agrees with class/file/support docs and resolves the named helper identities, slot-2 call shape, option offsets, and alpha-helper caller signature. Confidence remains below final-audit level because UID00041R still has a behavior-preserving source-expression blocker for the partially initialized kind-`3` options record.

## Unresolved Issues

| Issue | Evidence-backed rationale |
| --- | --- |
| Surface callback slot 2 signature | Applied and validated in the approved Surface support pages: `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, `int` status return, render-owner receiver in `ecx`, `EPFTileContext *`, source/destination `RectBounds *`, draw mode, palette pointer, and options pointer. |
| Render-option stack record | Applied and validated at ABI/support level as an opaque `SurfaceSpriteBlitOptions`-style record with kind +0x00, alpha +0x04, palette/tint +0x08, and secondary +0x1c. UID00041R formal C++ remains blocked because kind `3` leaves +0x1c unwritten while RGB565 reads it at `0x004c189d`. |
| Overlay helper source type | Applied and validated for UID00041R as an `AlphaMaskSurface` thiscall taking `EPFTileContext *` and `RectBounds *` source origin. Broader frame-source names and three raw xrefs remain open but do not block this caller route. |
| `drawOwner` static type | Caller objects are pane/control-like, but this body does not read the parameter. Formal code should use `void *` until a project-wide base type is settled. |

## Validator Results

All authorized scoped validators were run with `--wait-generated` from `source-3/project-documentation`. No `execute_report` or equivalent archive/execution command was run.

| Scope | Command id | Timestamp | Exit/result | Notes |
| --- | --- | --- | --- | --- |
| `by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md` | `000000004285` | `2026-07-02T05:53:56-04:00` | exit `0`, `ok: 1` | Applied `COMPLETION:88`, `CONFIDENCE:91`; generated refresh completed. |
| `by-class/ItemObjImageLib.md` | `000000004287` | `2026-07-02T05:54:13-04:00` | exit `0`, `ok: 1` | Existing missing UID warnings for `0003LZ`/`0003ND`; generated refresh completed. |
| `by-file/ItemObjImageLib.md` | `000000004289` | `2026-07-02T05:54:32-04:00` | exit `0`, `ok: 1` | Existing missing UID warnings for `0003LZ`/`0003ND`/`0003ZN`; generated refresh completed. |
| `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md` | `000000004302` | `2026-07-02T05:57:55-04:00` | exit `0`, `ok: 1` | Revalidation after truncated stdout; existing missing UID count `13`; generated refresh completed. |
| `by-global/SurfaceRenderCallbackTable.md` | `000000004303` | `2026-07-02T05:58:06-04:00` | exit `0`, `ok: 1` | Revalidation after truncated stdout; existing missing UID count `9`; generated refresh completed. |
| `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` | `000000004304` | `2026-07-02T05:58:17-04:00` | exit `0`, `ok: 1` | Revalidation after truncated stdout; existing missing UID count `8`; generated refresh completed. |
| `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md` | `000000004305` | `2026-07-02T05:58:28-04:00` | exit `0`, `ok: 1` | Revalidation after truncated stdout; research tracker update and generated refresh completed. |
| `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md` | `000000004299` | `2026-07-02T05:56:13-04:00` | exit `0`, `ok: 1` | Generated refresh completed. |
| `by-class/AlphaMaskSurface.md` | `000000004300` | `2026-07-02T05:56:23-04:00` | exit `0`, `ok: 1` | Generated refresh completed. |
| `by-file/AlphaMaskSurface.md` | `000000004301` | `2026-07-02T05:56:34-04:00` | exit `0`, `ok: 1` | Generated refresh completed. |

Generated freshness proof observed after final revalidation: `auto-generated/NexusTK/render/ItemObjImageLib.cpp`, `auto-generated/NexusTK/render/AlphaMaskSurface.cpp`, `auto-generated/NexusTK/render/Surface.cpp`, and `auto-generated/NexusTK/render/GrafPort.cpp` all showed validator header `validator-command-id: 000000004305` and `validator-refreshed-at: 2026-07-02T05:58:28-04:00`. `auto-generated/NexusTK/render/ItemObjImageLib.cpp` contains no emitted UID00041R/`DrawItemImage` body; `auto-generated/NexusTK/render/AlphaMaskSurface.cpp` keeps [UID:0000YO] as an empty emitter marker.

## Changed Files

Manual/report and approved by-* edits:

- `tools/leaser/Agents/Agent-B003/research/00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality.md`
- `by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md`
- `by-class/ItemObjImageLib.md`
- `by-file/ItemObjImageLib.md`
- `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`
- `by-global/SurfaceRenderCallbackTable.md`
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
- `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`
- `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md`
- `by-class/AlphaMaskSurface.md`
- `by-file/AlphaMaskSurface.md`

Generated/tool-state side effects were produced only by the scoped validators. They include generated coverage/C++ refreshes, `project-level/-auto-completion-stats.md`, reference/research tracker updates, `tools/validator.ini`, validator cache/state, and validator autogen backups. No generated, coverage, validator-state, project-level, or IDA database file was manually edited.

## Lease Results

Leases were acquired before edits for these ten by-* files: UID00041R target, ItemObjImageLib class/file/local cluster, three Surface slot-2 support pages, DrawEncodedAlphaFrame, AlphaMaskSurface class, and AlphaMaskSurface file. The final `tools/leaser/Agents/current_leases.md` check after validators reported `No active leases`. An explicit unlease attempt for the same ten paths returned `Rejected[No active lease]` for each path, confirming B003 held no active leases at completion.

## Implementation Tracking Checklist

- [x] Supervisor accepted this report for implementation.
- [x] [UID:00041R] `by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md` metadata updated to `COMPLETION:88`, `CONFIDENCE:91`; owner/emitter/reconstructable unchanged. Validator proof: `000000004285`, exit `0`, `ok: 1`.
- [x] [UID:00041R] target helper table/prose updated with current MCP session `supervisor_resume_20260629`, function size `0x16a`, 29 xrefs, resolved helper names, slot-2 `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` route, `DrawEncodedAlphaFrame` caller contract, and no legacy-remap use.
- [x] [UID:00041R] formal C++ block left blank with the exact no-code proof: option kind `3` writes kind/alpha/palette only, while RGB565 tag `3` reads secondary byte `+0x1c` at `0x004c189d`.
- [x] [UID:00006W] `by-class/ItemObjImageLib.md` synchronized for UID00041R, keeping `void *drawOwner`, replacing generic helper blockers with the support-repair plan plus kind-3 no-code proof. Validator proof: `000000004287`, exit `0`, `ok: 1`.
- [x] [UID:0000KH] `by-file/ItemObjImageLib.md` synchronized under generated-output/draw-method audit with the same UID00041R support-repair and no-code disposition. Validator proof: `000000004289`, exit `0`, `ok: 1`.
- [x] [UID:00017N] `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md` UID00041R row updated with current MCP proof, support-repair dependency, and kind-3 `+0x1c` no-code blocker. Validator proof: `000000004302`, exit `0`, `ok: 1`.
- [x] [UID:0001UU] `by-type/by-struct/ItemObjImageLibLayout.md` checked and recorded as already compatible with `void *drawOwner`; no content edit required by this report.
- [x] [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md` slot-2 support repaired to `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` with `int` status return, render-owner receiver in `ecx`, `EPFTileContext *`, source/destination `RectBounds *`, draw mode, palette pointer, and `const SurfaceSpriteBlitOptions *options`. Validator proof: `000000004303`, exit `0`, `ok: 1`.
- [x] [UID:0001PI] `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` mirrored slot-2 repair and option-offset evidence, including RGB565 +0x1c reads at `0x004c138a`, `0x004c189d`, and `0x004c1eee`. Validator proof: `000000004304`, exit `0`, `ok: 1`.
- [x] [UID:000167] `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md` formal typedef and callsites repaired: return `int`, final argument `const SurfaceSpriteBlitOptions *options`, existing calls pass null options, and option-record offset map/caveats recorded. Validator proof: `000000004305`, exit `0`, `ok: 1`.
- [x] [UID:0000YO] `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md` caller-facing declaration repaired to the `AlphaMaskSurface` thiscall route with `EPFTileContext *sourceContext`, `RectBounds *sourceOrigin`, alpha ramp endpoints, and blend modes 0/1/2; generic `EncodedFrame`/`Point` route historicalized for UID00041R. Validator proof: `000000004299`, exit `0`, `ok: 1`.
- [x] [UID:00000C] `by-class/AlphaMaskSurface.md` Method Notes/evidence synchronized with [UID:0000YO] so the class inventory records the UID00041R-proven `DrawEncodedAlphaFrame` caller-facing route while preserving broader frame-source and source-split caveats. Validator proof: `000000004300`, exit `0`, `ok: 1`.
- [x] [UID:0000HF] `by-file/AlphaMaskSurface.md` Proposed Contents/file-role note synchronized with [UID:0000YO], including the same caller-facing declaration route, mode meanings, and UID00041R overlay-strength transform. Validator proof: `000000004301`, exit `0`, `ok: 1`.
- [x] Claim And Incorporation Ledger rows C-00041R-001 through C-00041R-010 updated to `applied` or `already-present` with concrete destination/validator proof.
- [x] Scoped validators run for each authorized by-* file listed above, including `by-class/AlphaMaskSurface.md` and `by-file/AlphaMaskSurface.md`, with command id/timestamp/exit/ok recorded in this report.
- [x] Generated output freshness checked after validators for `auto-generated/NexusTK/render/ItemObjImageLib.cpp`, `auto-generated/NexusTK/render/AlphaMaskSurface.cpp`, `auto-generated/NexusTK/render/Surface.cpp`, and `auto-generated/NexusTK/render/GrafPort.cpp`; no manual generated/coverage/tool-state/project-level edits made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004309","destination_path":"executed-b-agent-research/B003/00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality.md","timestamp":"2026-07-02T06:05:13-04:00","uid":"00041R"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00041R"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
