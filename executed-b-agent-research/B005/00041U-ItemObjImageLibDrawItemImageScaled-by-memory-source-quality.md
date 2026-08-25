** TARGET-REPORT-UID:00041U **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00041U ItemObjImageLibDrawItemImageScaled Source-Quality Report

Lifecycle note: validator history records prior execution, revalidation, and de-execution/rework events for this report, including commands `000000005325`, `000000005338`, and `000000005340`. This report text is written to be archive-safe: it does not depend on its current filesystem location, does not describe Gate 1 as pending current truth, and does not rely on any `REPORT-VALIDATION-STATUS` header being present after validator execution.

## Finalized Report / Current Recommendation

Keep [UID:00041U] routed to [UID:00006W] `ItemObjImageLib` and keep it reconstructable, but do not insert formal C++ yet. This amendment resolves one previously named blocker into an implementation-ready support repair: Surface callback slot `0x0069b3e8` should be documented as `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` with a nullable options-pointer final parameter, not the older `int flags` spelling. The blocker that still prevents source-quality formal C++ is narrower and evidence-backed: the 32-byte draw-options record cannot be safely converted into a concrete source struct from UID00041U because the installed RGB565 slot target reads an option-6 byte at `+0x1c` that UID00041U never initializes.

Recommended target metadata:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | `87` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | keep `00006W` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `EMITTER_UIDS` | keep `00006W` |
| Formal C++ | keep blank with the target-specific no-code proof below |

This was an improvement over the pre-callback `84/88`: helper names, item layout, remap constants, palette slot behavior, callback argument order, slot-2 support repair, `RectBounds` field order, and crop/scale math are resolved enough for documentation and caller use. The remaining blocker is formal source emission, specifically the unsafe current-pass struct/initialization policy for the callback options record.

## Supporting Research

The July 3 report-text repairs preserved the original xHigh research and prior callback evidence while adding the literal Gate 1 section structure and later archive-safe lifecycle wording. Evidence sources remain the by-* target/support pages, matching old B-agent reports, generated-output observations recorded during the historical implementation callback, and live IDA MCP evidence from the original pass. No new by-* edits, generated edits, validators, lifecycle commands, or MCP-heavy refresh were performed during these report-text-only repairs.

## Target

- UID: `00041U`
- Current by-* target path: `by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md`
- Source-facing method: `int ItemObjImageLib::DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags)`
- Direct owner/emitter recommendation: keep [UID:00006W] `ItemObjImageLib`
- Source file route: keep [UID:0000KH] `ItemObjImageLib.cpp` / `NexusTK/render/ItemObjImageLib.cpp`
- Formal C++ disposition: keep blank with the target-specific no-code proof in this report.

## Current Target State

- Target: [UID:00041U] `by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md`.
- Historical pre-callback metadata was `84/88`, `CANONICAL_OWNER:00006W`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006W`, blank formal C++. The accepted callback recorded below raised the target to `87/91` while preserving the same owner/emitter/reconstructable/no-code disposition.
- Current signature in support docs: `int ItemObjImageLib::DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags)`.
- Current class route: [UID:00006W] `ItemObjImageLib` through [UID:0000KH] `ItemObjImageLib.cpp`.
- Historical B005 implementation-callback generated-output check: after scoped validator `000000004270` at `2026-07-02T05:34:02-04:00`, `auto-generated/NexusTK/render/ItemObjImageLib.cpp` had no `00041U` / `DrawItemImageScaled` method body or empty marker, preserving the accepted blank formal C++ disposition. That `000000004270` check is historical B005 evidence only, not a claim about latest generated-output freshness after supervisor reruns.

## Evidence Standards Used

- IDA MCP evidence was treated as authoritative for function boundaries, padding, direct callers, stack cleanup, callee set, global values, local writes, callback argument order, and slot-target option reads.
- Current by-* docs were treated as durable documentation state for owner/emitter/source route, support-page declarations, generated-output route, and already-incorporated callback details.
- Old executed and then-active reports were used only as leads after search-gating; important claims were rechecked against the target's MCP evidence and current support docs.
- Generated output was treated as validator-produced freshness evidence only. This repair does not manually edit generated files.
- For formal C++ readiness, the code-entry gate was considered, but target-specific behavior preservation takes priority over emitting source when the only available representation would be behavior-changing or decompiler-shaped.

## Evidence Checked

Current by-* docs:

- Target page [UID:00041U] `0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled`.
- [UID:00006W] `by-class/ItemObjImageLib.md`.
- [UID:0000KH] `by-file/ItemObjImageLib.md`.
- [UID:0001UU] `by-type/by-struct/ItemObjImageLibLayout.md`.
- [UID:0000B8] `by-type/by-struct/ItemInfo.md`.
- [UID:0001VP]/[UID:0000BU] `RectBoundsLayout` and `RectBounds`.
- [UID:00004I] `EPFTileContext` aggregate page.
- [UID:0003ZN] `0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants`.
- [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md`.
- [UID:0001PI] `0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable`.
- [UID:0002PH] `0x004bc090-0x004bd3e8.SoftwareRenderCompatSpriteBlitCallback`.
- [UID:0002PK] `0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback`.
- [UID:000167] `0x004ba250-0x004ba444.SurfaceSpriteBlitHelper`.
- [UID:00016A] `0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground`.
- `PaletteLib` class/file/helper pages for `sub_543D20` and `sub_543E40`.
- `ResourceLayoutTableLookupLayoutEntry` page for `sub_4D02F0`.
- Sibling draw pages [UID:00041R], [UID:00041S], [UID:00041T], and [UID:0000UQ].

Old report leads searched with the required exact terms: `00041U`, `0x004df2c0`, `0x004df455`, `ItemObjImageLibDrawItemImageScaled`, `DrawItemImageScaled`, `ItemObjImageLib`, `ITEM.EPF`, `ITEM.EPD`, `ItemObjImageLibLegacyItemRemapConstants`, and `unk_69B3E8`. Relevant leads used:

- B005 `00017N-ItemObjImageLibLocalMethodCluster-source-quality.md`: exact split plan and initial no-code rationale for the draw children.
- B004 `0004A0-ExchangeItemListPaneDrawItemEntry-source-quality.md`: direct caller evidence for using `DrawItemImageScaled` as a documented API.
- B003 `000167-SurfaceSpriteBlitHelper-source-quality.md`: slot `0x0069b3e8` receiver/argument-order and `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` alias evidence, plus the existing support-code typedef that still uses `int flags`.
- B002 `00016A-GrafPortDrawTiledBackground-source-quality.md`: zero-final-argument slot-2 caller evidence; useful for argument order but not decisive on whether the final parameter is an integer or a nullable pointer.
- B002 `00016I-GrafPortDrawGlyph-source-quality.md` and B005 `0003XE-SurfaceTileBufferBlitRaw-source-route-recheck.md`: additional slot `0x0069b3e8` argument-order and alias evidence, while preserving caveats that final signature/support integration was still open.
- Then-unexecuted sibling report lead B003 `00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality.md`: reviewed as lead-only, not authority. It independently reaches the same `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` options-pointer repair and provides a source-facing field map for option kinds `1`, `2`, and `3`; UID00041U still needs a separate no-code proof because it uses option kinds `4` and `6`, and kind `6` reaches a `+0x1c` read that UID00041U does not initialize.

## Current MCP Evidence

MCP was mandatory and was available.

- JSON-RPC endpoint: `http://127.0.0.1:13337/mcp`.
- Server: `ida-pro-mcp`, protocol `2025-06-18`.
- Active database: `supervisor_resume_20260629`.
- `server_health`: module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- 2026-07-02 recheck: `idb_list` reported one active `supervisor_resume_20260629` session, not analyzing, worker pid `14860`; `server_health` returned `ok`, Hex-Rays ready, strings cache size `2067`.

Target-specific MCP facts:

- `lookup_funcs 0x004df2c0`: `sub_4DF2C0`, size `0x195`.
- `lookup_funcs 0x004df455`: not a function; `get_bytes 0x004df455 size 11` returned only `0xcc` padding before successor `0x004df460`.
- `get_bytes 0x004df2b7 size 9`: nine `0xcc` bytes before the target.
- `analyze_function 0x004df2c0`: prototype shape `int __thiscall(int *this, int, int, __int16, unsigned __int8)`, size 405 bytes, callees `sub_457A60`, `sub_543D20`, `sub_4D02F0`, `sub_543E40`, `unk_69B3E8`, and security-cookie helper.
- `xrefs_to 0x004df2c0`: direct callers at `0x4ae2ca`, `0x4aedd4`, `0x51b542`, `0x51c7fe`, and `0x51f995` in `sub_4AE1C0`, `sub_4AEC90`, `sub_51B3E0`, `sub_51C6C0`, and `sub_51F840`.
- `get_global_value`: `0x0066dad4 == 0x972`, `0x0066dad8 == 0x0a20`, `0x0066dadc == 0x0a56`, `0x0066da97 == 1`, and `0x0069b3e8 == 0` in the static image.
- `xrefs_to 0x0066dadc`: exactly three data refs, in fixed-slot draw `0x004defc0`, this scaled draw `0x004df2c0`, and glyph helper `0x004df460`.
- `xrefs_to 0x0069b3e8 limit 20`: broad slot fanout, truncated with `more:true`; this matches the Surface callback table page's high-traffic slot-2 classification.

Target disassembly details that matter for source shape:

- `0x004df2e4`: adds `0x4000` to `itemId`.
- `0x004df2f8-0x004df326`: non-EPF legacy remap uses `word_66DAD8`, `word_66DADC`, adds `0xff53` for the remap band, and clamps above `word_66DAD4` to `0x0972`.
- `0x004df329`: calls `sub_457A60` on the stack tile context.
- `0x004df350-0x004df35b`: copies 20 bytes of `ItemInfo`.
- `0x004df35f-0x004df36c`: calls `sub_543D20`; if palette filtering is active and copied `allowPaletteFilter` is false, skips rendering and returns `0`.
- `0x004df372-0x004df392`: chooses `ITEM.EPF` (`off_61C288`) when `byte_66DA97 == 1`, otherwise `ITEM.EPD` (`off_61C29C`), and calls `sub_4D02F0`.
- `0x004df397-0x004df3a6`: calls `sub_543E40` as `GetSlotPalette(10, itemInfo.paletteSlot, paletteFlags >> 5)`.
- `0x004df3b4-0x004df418`: adjusts the local source rectangle around the source center when the source width/height exceed twice the destination width/height.
- `0x004df418-0x004df424`: writes a draw-options byte at stack offset `+0`; default value `4`, changed to `6` when `paletteFlags != 0`, and writes `paletteFlags` at local offset `+8`.
- `0x004df427-0x004df43c`: loads `ecx` from the first explicit argument (`drawOwner`) and calls `dword ptr unk_69B3E8` after pushing options, palette, mode `1`, destination rect, source rect, and source context.
- `0x004df452`: `retn 10h`, confirming four stack arguments after `this`.

Palette helper MCP facts:

- `analyze_function 0x00543d20`: `sub_543D20`, size 4, decompiles to `return this[1];`; callers include Surface/render code and all four ItemObjImageLib draw paths. This matches current support wording `PaletteLib::IsPaletteFilterEnabled`.
- `analyze_function 0x00543e40`: `sub_543E40`, size 156, reads `m_useFilteredPalettes` at `+0x758`, chooses base/runtime slot lists, handles nonzero super-palette index, and returns a palette pointer or fallback palette. This matches current support wording `PaletteLib::GetSlotPalette`.

Callback/options amendment MCP facts:

- `export_funcs` reports `sub_4DF2C0` with return type `int`, while the installed slot-2 targets decompile as large `__userpurge` artifacts. `sub_4BC090` and `sub_4C0F80` both have six stack arguments after the `ecx` receiver; their last stack argument is a pointer in the decompiler output, not a proven integer flags value.
- `decompile 0x004df2c0` shows local `_BYTE v19[32]` at `[ebp-0x5c]`; UID00041U writes `v19[0] = 4`, changes it to `6` when `paletteFlags != 0`, writes `v19[8] = paletteFlags`, and passes `v19` as the sixth stack argument to `unk_69B3E8`.
- Target disassembly confirms those are the only writes to the options region before the callback: `0x004df418 mov [ebp+var_5C], 4`, `0x004df420 mov [ebp+var_5C], 6`, `0x004df424 mov [ebp+var_54], bl`, then `0x004df42a lea eax, [ebp+var_5C]` for the final pushed argument. Bounded `search_text var_40` over `0x004df2c0-0x004df455` returned zero hits, so no write to `v19+0x1c` / `[ebp-0x40]` was found in the target body.
- `search_text` and paged disassembly inside compat slot target `0x004bc090-0x004bd3e8` show final-argument uses at `0x004bc2e6`, `0x004bc327`, and `0x004bcb51`. The compat target tests the pointer, switches on byte `+0`, reads byte `+8` on one option path, and reads dword `+0x0c` on another selected path.
- `search_text` and paged disassembly inside RGB565 slot target `0x004c0f80-0x004c3123` show final-argument uses at `0x004c12ec`, `0x004c12f6`, `0x004c1352`, `0x004c1380`, and `0x004c23bf`. The RGB565 target tests the pointer, switches on byte `+0`, reads byte `+8`, reads dword `+0x0c`, and reads byte `+0x1c`.
- Jump-table checks show UID00041U's default option byte `4` routes to `0x004bc741` in the compat target and `0x004c1c84` in the RGB565 target. Palette option byte `6` routes to `0x004bc8da` and `0x004c1ed3`; the RGB565 option-6 path reads `byte ptr [ebx+0x1c]` at `0x004c1eee`.
- Because UID00041U writes option `6` when `paletteFlags != 0` but never initializes `+0x1c`, a concrete source struct initialized with `{}` would not preserve the observed binary. It would force a zero value where the binary reads stack residue. A concrete source struct that intentionally leaves a field uninitialized would also be unsafe and source-poor without a broader slot-2 options audit.

## Positive Evidence Summary

- Range/function proof is strong: MCP identifies `sub_4DF2C0` at `0x004df2c0`, size `0x195`, with `0xcc` padding before `0x004df2c0` and after `0x004df455`.
- Liveness is strong: five direct callers reach the method, including exchange/item-list and item-menu draw paths that use this as a scaled item rendering API.
- Owner evidence is strong: the method is `thiscall`, consumes `ItemObjImageLib` row storage/fallback row state, shares item-remap constants and item asset names with sibling draw/glyph paths, and routes through [UID:00006W] / [UID:0000KH].
- Source-facing helper naming is supported: MCP and current support docs align `sub_457A60`, `sub_4D02F0`, `sub_543D20`, and `sub_543E40` with `EPFTileContext::Initialize`, `ResourceLayoutTable::LookupLayoutEntry`, `PaletteLib::IsPaletteFilterEnabled`, and `PaletteLib::GetSlotPalette`.
- Callback repair is supported: UID00041U passes a nonzero final pointer to slot `0x0069b3e8`, and installed slot targets dereference that final argument, so `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` with nullable `SurfaceSpriteBlitOptions *` is better supported than the old scalar `int flags` model.
- Crop/scale behavior is supported: the target centers a source crop when source width/height exceed twice the destination width/height, using the current `RectBounds` left/top/right/bottom field order.

## Negative Evidence Summary

- No evidence supports moving ownership to a UI caller: direct callers are consumers that request item image drawing; they do not own item rows, remap constants, resource lookup, palette-slot policy, or Surface callback setup.
- No evidence supports treating [UID:0000KH] `ItemObjImageLib.cpp` as a direct owner instead of the class owner; it is the source-file route for [UID:00006W], not an alternate semantic owner.
- No evidence supports a concrete `SurfaceSpriteBlitOptions` field-bearing struct from UID00041U alone: the target writes only selector `+0` and conditionally byte `+8`, while callback targets also read `+0x0c` and RGB565 option `6` reads `+0x1c`.
- No evidence supports zero-initializing the options record in formal C++: that would force `+0x1c == 0` where the binary reads an unwritten stack byte on RGB565 option `6`.
- No evidence supports preserving the old `int flags` final callback argument for nonzero UID00041U callsites: installed targets test and dereference the pointer.
- No evidence supports formal C++ in this pass using a raw byte array or partially initialized struct; those would either be decompiler-shaped or encode undefined stack dependence without accepted source-level meaning.

## Resolved Names And Semantics

| Binary item | Source-facing disposition |
| --- | --- |
| `sub_457A60` | `EPFTileContext::Initialize` / `InitTileContext`; initializes a 0x28-byte context whose `bounds` are `left, top, right, bottom` at context offsets `+0x10..+0x1c`. |
| `sub_4D02F0` | `ResourceLayoutTable::LookupLayoutEntry(const wchar_t *resourceName, int frameIndex, EPFTileContext *outContext)`. |
| `sub_543D20` | `PaletteLib::IsPaletteFilterEnabled() const`; returns the palette filter/mode flag at object slot `this[1]`. |
| `sub_543E40` | `PaletteLib::GetSlotPalette(int slot, int paletteIndex, int superPaletteIndex)`, here called with slot `10`, `ItemInfo::paletteSlot`, and `paletteFlags >> 5`. |
| `unk_69B3E8` | Surface callback-table slot 2. Implementation-ready support repair: standardize `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` and type the final argument as nullable `const SurfaceSpriteBlitOptions *options`, not `int flags`. |
| stack options block at `ebp-0x5c` | Pointer argument to slot 2. Best support-level type name is `SurfaceSpriteBlitOptions`, but UID00041U should only use an opaque pointer in the shared typedef for now. A field-bearing declaration is unsafe from this target because UID00041U writes byte `+0` as option `4` or `6` and byte `+8` as `paletteFlags`, while installed targets also read `+0x0c` and RGB565 option `6` reads `+0x1c`, which UID00041U leaves unwritten. |
| `RectBounds` | 16-byte POD with fields `left`, `top`, `right`, `bottom`; width is `right - left`, height is `bottom - top`. |
| `ItemInfo` | 20-byte row: `itemTableId`, `paletteSlot`, `alpha`, `renderFlagsOrMode`, `allowPaletteFilter`, plus padding. |
| legacy constants | ItemObjImageLib-owned data: max entry `0x0972`, current remap first `0x0a20`, current remap last `0x0a56`; target adds `0xff53` in the in-band remap path. |
| `ITEM.EPF` / `ITEM.EPD` | Resource names selected by `byte_66DA97`; EPF/current mode uses `ITEM.EPF`, legacy mode uses `ITEM.EPD`. |
| `drawOwner` | First explicit stack argument. The target does not read it except to load `ecx` for the callback. Formal declaration should keep `void *drawOwner` to match the accepted `ItemObjImageLibLayout` declaration; prose may mention a pane/GrafPort-like draw receiver only as an inference. |

Callback argument order is now documented, not generic future work. The target callsite and Surface support agree on:

```text
ecx: drawOwner / destination draw receiver
arg1: EPFTileContext *sourceContext
arg2: RectBounds *sourceRect
arg3: RectBounds *destinationRect
arg4: mode value, here 1
arg5: palette pointer returned by GetSlotPalette
arg6: pointer to draw options / flags block
```

## Surface Slot 2 And Draw Options Repair Audit

Callback typedef/name repair is safe and should be mandatory support work if this report is accepted. [UID:0000TN] already identifies slot `0x0069b3e8` as the primary EPF/tile/frame/sprite blit callback with best descriptive names `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`. The missing repair is the source-facing typedef, because the existing [UID:000167] formal code and zero-argument callers use `int flags`; UID00041U proves a nonzero final argument is a pointer to an options record.

Implementation-ready support declaration plan:

```cpp
struct SurfaceSpriteBlitOptions;

typedef int (__thiscall *SurfaceSpriteBlitProc)(
    void *destination,
    EPFTileContext *sourceContext,
    const RectBounds *sourceRect,
    const RectBounds *destinationRect,
    int mode,
    void *palette,
    const SurfaceSpriteBlitOptions *options);

extern SurfaceSpriteBlitProc g_pfnBlitSprite;
```

Use `void *destination` as the support-level receiver until `Pane`/`GrafPort` draw-receiver inheritance is standardized across all slot-2 consumers. Consumer pages with stronger local receiver evidence may still say "destination GrafPort" in prose. Zero-final-argument callers such as [UID:000167] and [UID:00016A] should be documented as passing `NULL` options, not as proving an integer flags argument. The callback targets at `0x004bc090` and `0x004c0f80` should keep their large-body formal C++ blank until their own branch/signature pass, but their stack-argument evidence supports this typedef route.

Concrete draw-options struct repair is not safe in this pass. A faithful source-facing struct would need at least an option selector at `+0`, an option-6 palette/tint byte at `+8`, a dword at `+0x0c` used by other selected paths, and a byte at `+0x1c` used by the RGB565 option-6 path. UID00041U initializes only `+0` and conditionally `+8`. The missing `+0x1c` write is not a documentation gap in the target body; the target disassembly was checked for the corresponding stack offset and no write was found before the dispatch.

Best current options model:

| Offset | Minimum observed role | UID00041U state | Current documentation disposition |
| ---: | --- | --- | --- |
| `+0x00` | option selector / kind byte | writes `4` by default, writes `6` when `paletteFlags != 0` | safe to document as selector evidence. |
| `+0x04` | alpha float in sibling UID00041R option kinds `1` and `3` | not initialized or used by UID00041U before dispatch | safe only as sibling-report/support evidence, not as a UID00041U field use. |
| `+0x08` | palette/tint/shift byte | writes `paletteFlags` only for option `6` | safe to document as the target's palette option byte. |
| `+0x0c` | dword consumed by compat/RGB565 option paths | not initialized by UID00041U | unsafe to name from UID00041U. |
| `+0x1c` | secondary byte consumed by RGB565 option paths, including option `6` at `0x004c1eee` | not initialized by UID00041U | blocks a field-bearing `SurfaceSpriteBlitOptions` declaration for this target. |

Therefore the best implementation-ready support declaration is a forward-declared opaque `struct SurfaceSpriteBlitOptions` in the `SurfaceSpriteBlitProc` typedef. A concrete field-bearing struct can be accepted only after a shared slot-2 options pass reconciles sibling option kinds `1`/`2`/`3` with UID00041U kinds `4`/`6` and decides how to document the observed uninitialized `+0x1c` dependency.

Rejected current-pass routes:

- `unsigned char options[32]` with sparse writes: rejects because it is decompiler-shaped and would encode stack layout rather than a source abstraction.
- Two-field `SurfaceSpriteBlitOptions { mode, paletteFlags }`: rejects because installed slot targets read `+0x0c` and `+0x1c`, so the type would be false outside this one caller.
- Zero-initialized `SurfaceSpriteBlitOptions options = {};`: rejects because it changes UID00041U behavior on RGB565 option `6` by forcing `+0x1c == 0` where the binary reads an unwritten stack byte.
- Intentionally partially initialized struct: rejects because it would preserve undefined/uninitialized-stack dependence as source and still lacks accepted field meaning for `+0x1c`.
- Keeping the old `int flags` typedef: rejects because UID00041U passes a pointer and the installed targets dereference the final argument when non-null.

## Crop / Scale Rectangle Semantics

The target copies the tile context's `bounds` into a local source rectangle, then crops that source rectangle around its center when it is too large for the destination scale relationship.

Source-facing equivalent of the width path:

```cpp
const int dstWidth = dstRect->right - dstRect->left;
const int sourceWidth = sourceRect.right - sourceRect.left;
if (sourceWidth > dstWidth * 2) {
    const int centeredLeft = ((sourceRect.left + sourceRect.right) / 2) - dstWidth;
    sourceRect.left = centeredLeft;
    sourceRect.right = centeredLeft + dstWidth * 2;
}
```

Height is the same pattern with `top`, `bottom`, and `dstHeight`. The disassembly implements the divide-by-two with `cdq; sub eax, edx; sar eax, 1`, matching signed truncation-toward-zero behavior for the midpoint expression.

## First-Draft C++ Recommendation

Do not insert formal C++ into [UID:00041U] yet.

Exact formal block disposition for this target remains blank:

```md
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The rare no-code proof is target-specific and route-complete:

1. The code-entry gate was considered. UID00041U is reconstructable, has an emitter route through [UID:00006W] to [UID:0000KH], and its combined score remains above the formal-code eligibility threshold.
2. The item remap, resource lookup, palette lookup, `ItemInfo`, `RectBounds`, and crop/scale behavior are not blocking source emission; they are resolved enough for a formal body.
3. The Surface callback typedef/name blocker was investigated and converted into a support repair plan: slot `0x0069b3e8` should be `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, returning `int`, using the draw receiver in `ecx`, and taking a nullable `const SurfaceSpriteBlitOptions *options` final parameter. This removes the old "typedef not accepted" rationale as a standalone blocker.
4. Formal C++ is still unsafe because the target-local 32-byte options block cannot be represented as source-quality C++ without either changing behavior or writing decompiler-shaped source. UID00041U writes only `+0` and `+8`, then the installed RGB565 option-6 path reads `+0x1c`.
5. Support docs were checked. [UID:000167] and [UID:00016A] use or describe the final argument as zero/flags, but those are null-options callers and do not override UID00041U's nonzero pointer evidence. [UID:0002PH] and [UID:0002PK] keep callback formal C++ blank and warn that final signatures/branch labels remain open.
6. Inferred type/layout options were considered and rejected with exact evidence: a raw byte array is decompiler-shaped; a two-field struct is false because slot targets read additional fields; a zero-initialized struct changes RGB565 option-6 behavior; and a deliberately uninitialized struct member is not source-quality reconstruction.
7. Further current-pass repair would require a cross-target audit of all slot-2 option codes and callers to recover the source-level options record and initialization policy. That work is not merely "more investigation" for UID00041U; the exact unsafe byte is already identified, and any target-only struct would be unsupported by the observed callback targets.

Therefore the accepted callback should update support declarations, but UID00041U itself should remain blank until `SurfaceSpriteBlitOptions` has a defensible source declaration or the target receives an explicitly accepted behavior-preserving low-level representation.

## Final Recommendation

The final recommendation remains: keep UID00041U as an [UID:00006W] `ItemObjImageLib` method routed through [UID:0000KH] `ItemObjImageLib.cpp`, keep it reconstructable with emitter UID00006W, keep formal C++ blank, and retain the support-level `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` options-pointer repair. Historical implementation/validator results below are preserved as implementation history, not as substitutes for the research sections above.

## Heuristic / Inference Reanalysis And Validation

Direct facts used: MCP confirms the exact function range, padding, stack cleanup, direct callers, callees, global values, final callback call sequence, target-local options writes, and slot-target option reads. Current by-* docs confirm `ItemObjImageLib`, `ItemInfo`, `RectBounds`, `EPFTileContext`, `PaletteLib`, `ResourceLayoutTable`, and `SurfaceRenderCallbackTable` context.

Inferences accepted: `DrawItemImageScaled` is an ItemObjImageLib method because it reads ItemObjImageLib rows and constants and is consumed by UI/menu callers as an item-rendering API. Slot 2 should use `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` because the Surface table and multiple accepted callers show shared sprite/tile/frame blit semantics, not a caller-specific image-library routine. The final slot argument is a nullable options pointer because zero callers behave as null-options calls and UID00041U passes a nonzero pointer that both installed targets dereference.

Inferences rejected: a caller-specific Surface alias, an over-specific `Pane *` or `GrafPort *` receiver in UID00041U formal support, raw `sub_` helper names, a byte-array options local, and a target-local two-field options struct. Each rejection is validated against either caller breadth, current support declarations, or exact target/callback disassembly.

## Ranked Ownership Analysis

1. [UID:00006W] `ItemObjImageLib`: recommended direct owner/emitter. The method is `thiscall`, consumes `ItemObjImageLib` row storage at `this+0x08` and `this+0x0c`, falls back to the embedded row at `this+0x14`, uses item remap/resource/palette policy shared with sibling ItemObjImageLib draw paths, and is called as an item image rendering API.
2. [UID:0000KH] `ItemObjImageLib.cpp`: correct source-file route, but not a separate semantic owner. It should receive generated output through the [UID:00006W] class route.
3. UI/menu/list caller pages: rejected as owners. They call into item rendering but do not own item row storage, legacy constants, resource selection, or palette-slot policy.
4. [UID:0000TN] / [UID:0001PI] Surface callback table: rejected as direct owner. Slot `0x0069b3e8` is a dependency used to blit the resolved item image; it does not own item lookup/remap/crop policy.
5. Palette/resource/layout support pages: rejected as direct owner. `PaletteLib`, `ResourceLayoutTable`, `EPFTileContext`, `RectBounds`, and `ItemInfo` provide dependencies and type context only.

Keep owner/emitter [UID:00006W] `ItemObjImageLib`.

- The method is `thiscall`, consumes `ItemObjImageLib` row storage at `this+0x08` and `this+0x0c`, and falls back to the embedded row at `this+0x14`.
- It shares ItemObjImageLib-owned legacy constants and item asset names with sibling fixed-slot/glyph paths.
- Callers are UI/menu/list consumers, but they delegate item rendering; they do not own item row storage, resource selection, remap policy, or palette-slot policy.
- `PaletteLib`, `ResourceLayoutTable`, `EPFTileContext`, `RectBounds`, and Surface callbacks are dependencies only.

## Source Placement

Keep source placement under [UID:0000KH] `NexusTK/render/ItemObjImageLib.cpp`.

## Caller Reachability

The target is live and directly called at five sites:

| Callsite | Function | Current source-facing evidence |
| --- | --- | --- |
| `0x004ae2ca` | `sub_4AE1C0` | B004 resolves this as `ExchangeItemListPaneDrawItemEntry`; it calls `DrawItemImageScaled` in the current/EPF branch for centered list-row item icons. |
| `0x004aedd4` | `sub_4AEC90` | MyItemListPane row draw analogue in the exchange/item-dialog family. |
| `0x0051b542` | `sub_51B3E0` | Server item-menu row draw path per existing menu-dialog reports. |
| `0x0051c7fe` | `sub_51C6C0` | Client item-menu row draw path per existing menu-dialog reports. |
| `0x0051f995` | `sub_51F840` | Argumented menu item-list draw path per existing split reports. |

This reachability supports a real source method, not padding, a dead helper, or compiler glue.

## Score And Metadata Recommendation

Recommend `87/91`.

- Completion `87`: exact range, owner/emitter, signature, live callers, helper names, constants, `ItemInfo`, `RectBounds`, palette semantics, callback order, callback typedef repair plan, and crop/scale behavior are now documented. Completion stays below code-entry implementation because the options record cannot yet receive a safe concrete source declaration.
- Confidence `91`: current MCP independently verifies bytes, boundaries, function size, direct callers, callee set, global values, remap xrefs, disassembly call sequence, target-local options writes, slot-target option reads, and palette helper behavior. Confidence stays below final-audit levels because the original options-record field meanings and initialization policy are not fully recoverable from UID00041U alone.

Recommended metadata:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | `87` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | keep `00006W` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `EMITTER_UIDS` | keep `00006W` |
| Formal C++ | keep blank |

## Open Questions With Attempted Resolution

- Can the final slot-2 argument stay `int flags`? Resolved no for nonzero UID00041U: the target passes a pointer and installed callback targets dereference it.
- Can UID00041U safely emit formal C++ using a concrete options struct? Resolved no for this pass: RGB565 option `6` reads `+0x1c`, but UID00041U does not initialize that byte.
- Can the options record be zero-initialized to make source pleasant? Resolved no: zero-initialization changes the observed unwritten-stack dependency for RGB565 option `6`.
- Is `void *drawOwner` too weak? Resolved as the safest current formal type because UID00041U forwards the first explicit argument as the callback receiver but does not prove a single final `Pane`/`GrafPort` receiver type across all slot-2 users.
- Are [UID:00016A], [UID:0002PH], and [UID:0002PK] required broad rewrites? Resolved no for this report: they are support evidence for option semantics, while broad body/signature passes remain separate work.

## Recommended Target Doc Changes

Target recommendation:

- Target [UID:00041U]: update score to `87/91`; preserve owner/emitter and reconstructable metadata; keep formal C++ blank; add current MCP evidence, helper-name table, callback argument order, callback/options repair audit, crop/scale semantics, caller reachability, and no-code proof.

## Recommended Support Doc Changes

- [UID:00006W] `ItemObjImageLib`: update the draw-method notes for `DrawItemImageScaled` from generic helper/callback blockers to the exact no-code proof above. Keep `void *drawOwner` in formal declaration support.
- [UID:0000KH] `ItemObjImageLib.cpp`: record that UID00041U remains intentionally non-emitting pending a defensible concrete `SurfaceSpriteBlitOptions` declaration/initialization policy, while generated output is fresh and currently contains no UID00041U body.
- [UID:0001UU] `ItemObjImageLibLayout`: no mandatory change; it already uses the conservative `void *drawOwner` signature.
- [UID:0000TN] `SurfaceRenderCallbackTable`: mandatory support update. Replace the open slot-2 final-argument caveat with a support plan that standardizes `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, return `int`, receiver in `ecx`, six stack arguments, and nullable `const SurfaceSpriteBlitOptions *options` final parameter. Add the caveat that existing zero callers pass `NULL` options and that old `int flags` wording is insufficient after UID00041U.
- [UID:0001PI] `0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable`: if the implementation callback edits the memory storage page alongside the global page, synchronize slot-2 wording with [UID:0000TN].
- [UID:000167] `SurfaceSpriteBlitHelper`: mandatory support update because this page currently carries the stale formal typedef with `int flags`. Repair the formal typedef to return `int`, use a `void *`/render-owner receiver, `EPFTileContext *`, `const RectBounds *` source/destination rects, draw mode, palette pointer, and `const SurfaceSpriteBlitOptions *options`; update the two existing helper calls to pass `NULL` options. Do not attempt a full slot-target branch rewrite here.
- [UID:00016A] `GrafPortDrawTiledBackground`: no mandatory formal-code change if the callback scope is limited, but any touched wording should say its final zero argument is `NULL` options, not proof of integer flags.
- [UID:0002PH] and [UID:0002PK] slot-2 implementation pages: no formal C++ insertion from this report. If the Surface support callback edits them, add only the evidence-backed option-read caveat (`+0`, `+8`, `+0x0c`, RGB565 `+0x1c`) and preserve their large-body signature/branch-pass blockers.
- [UID:0003ZN] legacy constants: no mandatory score change; optional link cleanup may replace stale by-item glyph-helper links with the current by-memory [UID:0000UQ] path if the supervisor includes that support cleanup.

Suggested scoped validators for a future implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality-removed.md](00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validators, verify `auto-generated/NexusTK/render/ItemObjImageLib.cpp` freshness and confirm UID00041U still has no generated method body unless a later accepted concrete options type enables formal C++.

## Claim And Incorporation Ledger

| Claim ID | Claim | Evidence | Action | Destination / details | Verification state |
| --- | --- | --- | --- | --- | --- |
| C-00041U-001 | Target range is exact `0x004df2c0-0x004df455`, size `0x195`, with padding before and after. | MCP `lookup_funcs`, `get_bytes`, `disasm`; `retn 10h` at `0x004df452`; `0xcc` padding at `0x004df2b7-0x004df2c0` and `0x004df455+`. | incorporate | Applied to `by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md` Current IDA MCP Evidence / Changes. | applied |
| C-00041U-002 | Signature should remain `int ItemObjImageLib::DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags)`. | MCP stack cleanup `retn 10h`, target disassembly, current `ItemObjImageLibLayout`, and caller use. | incorporate | Applied to target Source-Facing Signature, `by-class/ItemObjImageLib.md` method notes, and `by-file/ItemObjImageLib.md` draw API table. [UID:0001UU] was verified already-present. | applied |
| C-00041U-003 | Legacy remap uses `+0x4000`, in-band `+0xff53`, and clamp `0x0972` against constants at `0x0066dad4/8/c`. | MCP disassembly and global values; constants page. | incorporate | Applied to target Helper Names And Legacy Remap Constants and evidence sections. | applied |
| C-00041U-004 | `ItemInfo` row fields used here are `paletteSlot` and `allowPaletteFilter`. | MCP copy from `this` row/fallback row; `ItemInfo` layout support; palette call at `0x004df397-0x004df3a6`; filter gate at `0x004df35f-0x004df36c`. | incorporate | Applied to target Touched State And Dependencies and palette behavior prose. | applied |
| C-00041U-005 | Resource lookup helper is `ResourceLayoutTable::LookupLayoutEntry` and resource selection is `ITEM.EPF` versus `ITEM.EPD`. | MCP disassembly `0x004df372-0x004df392`; ResourceLayoutTable support page. | incorporate | Applied to target helper table and current MCP evidence. | applied |
| C-00041U-006 | Palette helpers are `IsPaletteFilterEnabled` and `GetSlotPalette`. | MCP `analyze_function` for `0x00543d20` and `0x00543e40`; PaletteLib support pages. | incorporate | Applied to target helper table, target palette behavior, class support, and file support. | applied |
| C-00041U-007 | Slot `0x0069b3e8` should be support-repaired as `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` with nullable options pointer, not `int flags`. | UID00041U nonzero pointer pass; compat/RGB565 target final-arg dereferences; [UID:0000TN], [UID:000167], [UID:00016A] support evidence. | incorporate | Applied to `by-global/SurfaceRenderCallbackTable.md`, `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`, and `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`; older scalar wording historicalized/rejected for nonzero UID00041U. | applied |
| C-00041U-008 | UID00041U's options block writes only byte `+0` and conditionally byte `+8`; installed targets also read `+0x0c` and RGB565 option `6` reads `+0x1c`. | MCP target disassembly writes at `0x004df418`, `0x004df420`, `0x004df424`; compat reads at `0x004bc327`/`0x004bcb54`; RGB565 reads at `0x004c1355`, `0x004c138a`, `0x004c23c2`. | incorporate | Applied to target Callback Order And Options Evidence / no-code proof and to Surface global/storage/helper support caveats. | applied |
| C-00041U-009 | Crop/scale math centers a source crop when source width/height exceed twice destination width/height. | MCP disassembly `0x004df3b4-0x004df418`; RectBounds layout support. | incorporate | Applied to target Crop / Scale Rectangle Semantics and by-file/class UID00041U notes. | applied |
| C-00041U-010 | The target is live through five direct callers. | MCP `xrefs_to 0x004df2c0`; old caller reports for Exchange/Menu draw methods. | incorporate | Applied to target Caller Reachability and current MCP evidence. | applied |
| C-00041U-011 | Formal C++ should remain blank for now, despite callback typedef repair, because a concrete options struct would be unsafe or decompiler-shaped. | Exact no-code proof: target lacks `+0x1c` initialization while RGB565 option `6` reads it; raw byte array, two-field struct, zero-init struct, partial-init struct, and old `int flags` routes rejected. | incorporate | Applied to target formal C++ / no-code proof, class/file support, and Surface support caveats; formal UID00041U block remains blank. | applied |
| C-00041U-012 | [UID:000167] `SurfaceSpriteBlitHelper` is a required support edit because its formal typedef currently preserves the stale `int flags` route. | Current [UID:000167] formal C++ typedef, UID00041U pointer pass, and slot-target dereferences. | incorporate | Applied to `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md` formal typedef and two callsites; generated `auto-generated/NexusTK/render/GrafPort.cpp` now contains the repaired typedef. | applied |
| C-00041U-013 | [UID:0001UU] `ItemObjImageLibLayout` already carries the safe `void *drawOwner` prototypes and needs no code-shape change for UID00041U. | Current layout formal block and UID00041U target receiver forwarding only. | already-present | Verified in `by-type/by-struct/ItemObjImageLibLayout.md`; not edited and no validator needed because the accepted prototype was already present. | already-present |
| C-00041U-014 | [UID:00016A], [UID:0002PH], and [UID:0002PK] are support evidence for slot-2 semantics but do not require broad body rewrites from this report. | [UID:00016A] zero-options caller; [UID:0002PH]/[UID:0002PK] large callback target pages and current MCP option-read checks. | not-applicable | Excluded with reason: no body/signature-pass edits were accepted for [UID:00016A], [UID:0002PH], or [UID:0002PK]. The callback's `GrafPortDrawGlyph` path is UID00016I in live docs, not UID00016A; it was reviewed as mismatch/read-only and not a touched zero-options support note. Zero-final-argument support was incorporated through [UID:0000TN], [UID:0001PI], and [UID:000167]. | excluded-with-reason |

## Validator Results

No validator was run during the July 3 report-text repairs, per supervisor instruction.

Historical implementation-callback validator results are retained below because they are part of the report artifact and prove the earlier by-* incorporation state. They are historical evidence only; they were not newly produced by the July 3 report-text repairs.

Historical lease batch:

- Initial B005 edit leases were active for the six changed by-* files at `2026-07-02T09:21:27Z` and for the already-present layout page at `2026-07-02T09:22:20Z`; that first window expired before validation.
- Reacquired the seven required scoped files for validation with `python .\tools\leaser\leaser.py B005 lease ...`; all seven returned `Success`.
- Post-validator `unlease` returned `Rejected[No active lease]` for all seven paths because the short validation lease window had already expired. Final read of `tools/leaser/Agents/current_leases.md` showed `No active leases.`

Historical scoped validator results, all from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240 --wait-generated`:

| File | command_id | command_timestamp | exit | ok | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory\0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md` | `000000004264` | `2026-07-02T05:32:22-04:00` | `0` | `1` | Updated target score to `87/91`; warning was `missing_ref_uid 0003ZN` plus validator-owned autogen/projected-stats side effects. |
| `by-class\ItemObjImageLib.md` | `000000004265` | `2026-07-02T05:32:44-04:00` | `0` | `1` | Warnings were pre-existing missing-ref UID registry entries for `0003LZ`/`0003ND`. |
| `by-file\ItemObjImageLib.md` | `000000004266` | `2026-07-02T05:32:59-04:00` | `0` | `1` | Warnings were missing-ref UID entries for `0003LZ`/`0003ND`/`0003ZN`. |
| `by-type\by-struct\ItemObjImageLibLayout.md` | `000000004267` | `2026-07-02T05:33:16-04:00` | `0` | `1` | Already-present `void *drawOwner` formal prototype verified; no missing-ref warnings. |
| `by-global\SurfaceRenderCallbackTable.md` | `000000004268` | `2026-07-02T05:33:31-04:00` | `0` | `1` | Warnings were older missing-ref UID entries for `0003ZP`/`0003XE`/`00039T`. |
| `by-memory\0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` | `000000004269` | `2026-07-02T05:33:46-04:00` | `0` | `1` | Warnings were older missing-ref UID entries for `0003ZP`/`0003XE`/`0003PN`. |
| `by-memory\0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md` | `000000004270` | `2026-07-02T05:34:02-04:00` | `0` | `1` | Repaired typedef generated through GrafPort route; no missing-ref warnings. |

Historical B005 generated freshness from the implementation callback:

- During the B005 implementation callback, `auto-generated/NexusTK/render/ItemObjImageLib.cpp` reported `validator-command-id: 000000004270`, `validator-refreshed-at: 2026-07-02T05:34:02-04:00`, and `validator-refresh-source: foreground-generated-refresh`, equal to the final B005 scoped validator and newer than the prior six B005 validator timestamps.
- During that same historical B005 check, `rg` found no `00041U` / `DrawItemImageScaled` body in `auto-generated/NexusTK/render/ItemObjImageLib.cpp`, preserving the accepted blank formal C++ disposition at that time.
- During that same historical B005 check, `auto-generated/NexusTK/render/GrafPort.cpp` also reported `validator-command-id: 000000004270`, `validator-refreshed-at: 2026-07-02T05:34:02-04:00`; `rg` found the repaired `SurfaceSpriteBlitOptions` / `SurfaceSpriteBlitProc` typedef and `NULL` options calls generated from [UID:000167].
- `python .\tools\validator.py --queue-status` returned command `000000004273` at `2026-07-02T05:35:05-04:00` with `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, and `processing generated refresh jobs: 0`.

## Changed Files

July 3 report-text repairs changed only:

- `tools/leaser/Agents/Agent-B005/research/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md`

No by-* docs, generated files, project-level generated files, coverage reports, validator state, report lifecycle state, archives, supervisor ledgers, or `tools/validator.ini` were edited during the July 3 report-text repairs. No validators or lifecycle commands were run by B005 for these repairs.

Historical implementation-callback changed files from the prior accepted callback are preserved in the ledger/checklist and validator results above: target UID00041U, [UID:00006W] `ItemObjImageLib`, [UID:0000KH] `ItemObjImageLib.cpp`, [UID:0000TN] `SurfaceRenderCallbackTable`, [UID:0001PI] Surface callback storage, and [UID:000167] `SurfaceSpriteBlitHelper`; [UID:0001UU] was verified already-present.

## Implementation Tracking Checklist

- [x] [UID:00041U] target metadata set to `87/91`, owner/emitter unchanged. Proof: `by-memory\0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md`; validator `000000004264`, exit `0`, `ok:1`.
- [x] [UID:00041U] target evidence updated with current MCP session `supervisor_resume_20260629`, exact range/padding, direct callers, helper names, remap constants, palette behavior, callback order, target-local options writes, slot-target option reads, and crop/scale math. Proof: target Current IDA MCP Evidence, Helper Names, Callback Order, Crop / Scale, and Caller Reachability sections.
- [x] [UID:00041U] formal C++ block intentionally left blank with the exact no-code proof from this report and the blank `RECONSTRUCTION_CPP CODE` header/block preserved. Historical B005 proof: generated `ItemObjImageLib.cpp` at command `000000004270` had no UID00041U body during the implementation callback.
- [x] [UID:00006W] `ItemObjImageLib` support notes synchronized for `DrawItemImageScaled`, using `void *drawOwner` as formal-safe type. Proof: `by-class\ItemObjImageLib.md`; validator `000000004265`.
- [x] [UID:0000KH] `ItemObjImageLib.cpp` support notes synchronized with the generated-output disposition. Proof: `by-file\ItemObjImageLib.md`; validator `000000004266`.
- [x] [UID:0001UU] `ItemObjImageLibLayout` verified as already-present for the `void *drawOwner` prototype; no edit made. Proof: current layout formal block already declares `DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags)`; validator `000000004267`.
- [x] [UID:0000TN] `SurfaceRenderCallbackTable` support updated for slot 2: `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, `int` return, `ecx` draw receiver, nullable `const SurfaceSpriteBlitOptions *options` final parameter, zero callers as `NULL` options, and old `int flags` wording rejected for nonzero UID00041U. Proof: `by-global\SurfaceRenderCallbackTable.md`; validator `000000004268`.
- [x] [UID:0001PI] `0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable` synchronized with the slot-2 support repair. Proof: `by-memory\0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`; validator `000000004269`.
- [x] [UID:000167] `SurfaceSpriteBlitHelper` formal typedef repaired from stale `int flags` to nullable `const SurfaceSpriteBlitOptions *options`, with `int` return and existing zero calls expressed as `NULL` options. Historical B005 proof: `by-memory\0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`; validator `000000004270`; generated `GrafPort.cpp` contained the repaired typedef during the implementation callback.
- [x] Surface support docs preserve the unsafe-now options struct proof: UID00041U writes `+0` and `+8`; installed targets read `+0x0c`; RGB565 option `6` reads uninitialized `+0x1c`; raw byte array, two-field struct, zero-init struct, partial-init struct, and `int flags` routes rejected. Proof: target, Surface global, Surface storage, and helper pages all include the caveat.
- [x] [UID:00016A] `GrafPortDrawTiledBackground` reviewed but not edited. Reason: accepted callback did not require touching that page; zero-final-argument support was corrected in [UID:0000TN]/[UID:0001PI], and body/formal C++ remains out of scope. The callback's `GrafPortDrawGlyph` path is UID00016I in live docs, not UID00016A; it was not edited for the same out-of-scope reason.
- [x] [UID:0002PH] and [UID:0002PK] slot-2 implementation pages left formal-C++ blank and not edited. Reason: their large-body branch/signature pass was not accepted in this callback; option-read evidence was incorporated into target and Surface support pages.
- [x] Claim And Incorporation Ledger reviewed claim-by-claim and verification states updated.
- [x] Scoped validators run for every required target/support by-* file with `--wait-generated`; command IDs/timestamps/exits/ok counts recorded above.
- [x] Historical B005 implementation-callback autogen was refreshed and `auto-generated/NexusTK/render/ItemObjImageLib.cpp` freshness was verified at `validator-command-id: 000000004270`; this is not presented as latest generated freshness after supervisor reruns.
- [x] No generated files, coverage reports, project-level generated files, validator/tool state, archives, queues, locks, IDA DB, or by-project-structure files were manually edited. Validator-owned generated/tool-state side effects occurred only through scoped validator commands.
- [x] July 3 report-text repairs normalized exact Gate 1 headings, added standalone `Positive Evidence Summary` and `Negative Evidence Summary`, split ownership/source placement and target/support recommendations, and historicalized prior callback/validator wording without editing validator-owned lifecycle data.
- [x] July 3 report-text repairs touched only this report artifact and ran no validators, `execute_report`, invalidation, revalidation, archive/move, registry, or `tools/validator.ini` commands.

## Historical Boundary Note

Historical note: the earlier report-only boundary applied to the original research pass. During the accepted implementation callback recorded above, only the listed by-* docs and this B005 report were manually edited. Generated/project-level/tool-state changes were validator-owned side effects from scoped validator runs. During the July 3 report-text repairs, no by-* docs or validator-owned files were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004275","destination_path":"executed-b-agent-research/B005/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md","timestamp":"2026-07-02T05:36:17-04:00","uid":"00041U"} -->
<!-- {"agent":"B005","command_id":"000000004539","details":"report marked for revalidation","event":"needs-revalidation","issue":"Supervisor hard required-section audit after rule update: report lacks explicit Positive Evidence Summary and Negative Evidence Summary; under-spec reports cannot remain silently counted without revalidation.","source_path":"executed-b-agent-research/B005/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md","timestamp":"2026-07-02T14:13:35-04:00","uid":"00041U"} -->
<!-- {"agent":"B005","command_id":"000000005325","destination_path":"tools/leaser/Agents/Agent-B005/research/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B005/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md","timestamp":"2026-07-03T10:55:00-04:00","uid":"00041U"} -->
<!-- {"agent":"B005","command_id":"000000005338","destination_path":"executed-b-agent-research/B005/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md","timestamp":"2026-07-03T11:07:48-04:00","uid":"00041U"} -->
<!-- {"agent":"B005","command_id":"000000005340","destination_path":"tools/leaser/Agents/Agent-B005/research/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B005/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md","timestamp":"2026-07-03T11:08:37-04:00","uid":"00041U"} -->
<!-- {"agent":"B005","command_id":"000000005343","destination_path":"executed-b-agent-research/B005/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md","timestamp":"2026-07-03T11:12:36-04:00","uid":"00041U"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00041U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
