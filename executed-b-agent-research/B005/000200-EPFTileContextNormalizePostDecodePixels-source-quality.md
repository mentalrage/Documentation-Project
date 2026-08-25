** TARGET-REPORT-UID:000200 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:000200] EPFTileContextNormalizePostDecodePixels Source-Quality Report

Agent: Agent-B005  
Date: 2026-06-19  
Target: `by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md`  
Required report path: `tools/leaser/Agents/Agent-B005/research/000200-EPFTileContextNormalizePostDecodePixels-source-quality.md`  
Assignment type: report-only B-preferred source-quality and heuristic/inference pass

## Final Recommendation

Raise [UID:000200] from `84/90` to `88/91`, keep `RECONSTRUCTABLE:TRUE`, keep canonical owner/emitter [UID:00004I] `EPFTileContext`, keep the generated route `auto-generated/NexusTK/render/EPFTileContext.cpp`, and populate the formal C++ block with a source-authored `EPFTileContext::NormalizePostDecodePixels()` first draft.

The target now has enough evidence to pass the source-entry gate: exact raw bytes and padding are confirmed, the six direct image-loader callers and one callee are accounted for, `byte_69B3D5` can be defensibly named as an RGB565 active-surface/pixel-format flag, `sub_4BB0E0` can be defensibly named as an in-place RGB565-to-RGB555 compatibility transform, and the receiver fields used by the target are already supported by the EPFTileContext layout.

Remaining uncertainty is limited to exact original symbol spellings for the global flag and helper. That should keep the page below final/completion-perfect status, but it should no longer block first-draft source.

## Evidence Reviewed

- Mandate docs: `tools/leaser/Agents/Agent-B005/goal.md`, `notes.md`, `tools/leaser/Agents/Supervisor.md`, `by-structure.md`, and `inference_research.md`.
- Target and direct support pages:
  - `by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md`
  - `by-class/EPFTileContext.md`
  - `by-file/EPFTileContext.md`
  - `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
  - decode callers under `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md` and child decode pages.
- Surface/render support pages:
  - `by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md`
  - `by-global/SurfaceRenderCallbackTable.md`
  - `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
  - `by-memory/0x00558690-0x0055883d.SurfaceRenderCallbackInitializerRaw.md`
  - `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`
  - `by-memory/0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md`
  - `by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md`
  - `by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md`
  - `by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md`
  - `by-meta/client_new_rendering_mode.md`
  - `by-file/Surface.md`
  - `by-file/SoftwareBlend16.md`
  - `by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md`
- Generated/report context:
  - `project-level/-auto-completion-stats.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/NexusTK/render/EPFTileContext.cpp`
  - `project-level/-unresolved.md`
  - `project-level/-resolved.md`
  - `by-memory/-coverage-report.md`
- Exported analysis data:
  - `resources/exported_data/functions/0x00458560.json`
  - `resources/exported_data/functions/0x004bb0e0.json`
  - `resources/exported_data/functions/0x00558690.json`
  - `resources/exported_data/functions/0x00558840.json`
- Raw executable byte audit:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

IDA MCP was probed at `http://127.0.0.1:13337/mcp` and was unavailable (`Unable to connect to the remote server`). I therefore used current exported IDA/Ghidra JSON, raw PE bytes, and current by-* documentation rather than live IDA MCP.

## Boundary / Bytes / Padding

The raw executable audit confirms the current half-open target range exactly:

```text
target+padding VA 0x00458557-0x00458590 raw 0x57957 len 0x39 section .text
SHA1 840d76a832ed6dcebb0daf29ed9c0573db79549d
cc cc cc cc cc cc cc cc cc 80 3d d5 b3 69 00 00 75 1b 8b 51 1c 8b 41 18 2b 51 14 2b 41 10 0f af d0 52 ff 71 04 e8 5f 2b 06 00 83 c4 08 c3 cc cc cc cc cc cc cc cc cc cc cc

target-body VA 0x00458560-0x00458585 raw 0x57960 len 0x25 section .text
SHA1 42c7d50e1d27b8fcec779b299c97b639bb5ab091
80 3d d5 b3 69 00 00 75 1b 8b 51 1c 8b 41 18 2b 51 14 2b 41 10 0f af d0 52 ff 71 04 e8 5f 2b 06 00 83 c4 08 c3
```

Boundary findings:

- Previous modeled EPFTileContext body [UID:0000XY] `ReleaseBuffers` ends at `0x00458557`.
- `0x00458557-0x00458560` is nine bytes of `0xcc` padding.
- [UID:000200] body is exactly `0x00458560-0x00458585`, size `0x25`.
- `0x00458585-0x00458590` is eleven bytes of `0xcc` padding.
- Next EPFTileContext function [UID:000201] starts at `0x00458590`.

No split or range repair is needed for the target. The current ignored-padding rows around it are still correct.

## Function Model / Reachability

`resources/exported_data/functions/0x00458560.json` agrees with the page-level function model:

- Ghidra name: `meth_0x458560`
- IDA name: `sub_458560`
- Size: `37` bytes / `0x25`
- Ghidra calling convention: `__thiscall`
- IDA prototype shape: `void __thiscall(int this)`
- Callees: one, `0x004bb0e0`
- No allocation, no local object lifetime, no exception frame, no virtual dispatch.

Direct call/tail-call evidence:

```text
0x004d06f2 CALL from DecodeZpfFpfToTileContext path
0x004d079a JMP  from DecodeFpfToTileContext raw/tail path
0x004d0991 CALL from DecodeJpfImageToTileContext path
0x004d0c42 CALL from DecodeJpegBufferToTileContext path
0x004d0d7d CALL from DecodePngFileToTileContext path
0x004d0f29 CALL from DecodePngResourceToTileContext path
```

The caller set is source-shaped: every call occurs after a tile/image decode path has filled an EPFTileContext primary 16-bit pixel buffer. That supports a receiver method/finalizer on EPFTileContext rather than an image-loader-local helper.

## Behavior And Field Model

The target body is:

```c
if (!byte_69B3D5) {
    sub_4BB0E0(
        *(uint16_t **)(this + 0x04),
        (*(int *)(this + 0x1c) - *(int *)(this + 0x14)) *
        (*(int *)(this + 0x18) - *(int *)(this + 0x10)));
}
```

Source-facing EPFTileContext field inference:

- `this+0x04` is the primary `pixelData` pointer. The six callers fill this buffer with 16-bit post-decode pixels before calling the normalizer.
- `this+0x10` is `bounds.left`.
- `this+0x14` is `bounds.top`.
- `this+0x18` is `bounds.right`.
- `this+0x1c` is `bounds.bottom`.
- Pixel count is `(bounds.right - bounds.left) * (bounds.bottom - bounds.top)`.

These names are already consistent with the EPFTileContext class and aggregate docs. Other EPFTileContext layout questions such as `pixelMode`, `auxiliaryData`, `rowStride`, and encoded-mask fields remain broader class/aggregate quality caveats, but they are not target-specific blockers because [UID:000200] reads only `pixelData` and the rectangle bounds.

## Render-Mode Global Reanalysis

`byte_69B3D5` should no longer be left as a raw byte name in this target. The strongest descriptive source-facing name is:

```cpp
extern bool g_surfaceUsesRgb565Pixels;
```

I do not claim this is the exact original symbol. It is the best defensible source-quality name from current evidence.

Evidence for meaning and polarity:

- `SurfaceRenderCallbackInitializerRaw` and `SurfaceMinimapRenderInitializer` set `byte_69B3D5 = 1` for a 32-bit display path or a 16-bit surface whose green mask is `0x07e0`, and set it to `0` for 24-bit or 16-bit non-`0x07e0` cases.
- The same initializers select the `0x004c...` RGB565-capable callback family when the byte is true and the `0x004bb...` compatibility/RGB555 family when false.
- `SurfaceAlphaLookupTablePointers` uses the flag to choose a 6-bit green channel limit (`0x3f`) for true and a 5-bit middle-channel limit (`0x1f`) for false.
- `JpegScreenshotWriter` has an explicit `is565`-shaped parameter; the nonzero path expands RGB565 (`red = HIBYTE(pixel) & 0xf8`, `green = (pixel >> 3) & 0xfc`, `blue = 8 * pixel`) and the zero path expands RGB555 (`red = (pixel >> 7) & 0xf8`, `green = (pixel >> 2) & 0xf8`, `blue = 8 * pixel`).
- `ScreenshotCaptureAndProof` and `DLPaletteMethodCluster` use the same global to select high-color/compatibility pixel handling.

Rejected names:

- `byte_69B3D5`: useful only as raw address evidence, not a source-quality name.
- `g_newRenderingMode`: too broad. The flag is correlated with the current/new render path but its observed role is pixel-format/RGB565 selection.
- `g_highColorMode`: too broad and ambiguous because both RGB555 and RGB565 are 16-bit high-color formats.
- `g_is32BitMode`: wrong, because the byte is also set for 16-bit `0x07e0` RGB565.
- `g_usesRgb555`: wrong polarity; true selects RGB565-capable formulas and callback families.

Recommended support-doc wording should preserve the raw address:

```text
`byte_69B3D5` / proposed source name `g_surfaceUsesRgb565Pixels` is the active Surface 16-bit pixel-format flag: true for RGB565-capable output paths selected by the DirectDraw/surface initializer, false for RGB555 compatibility paths. Exact original symbol spelling remains unproven.
```

## Compatibility Transform Reanalysis

The target's only callee is `0x004bb0e0`. Current docs call it `sub_4BB0E0`; that is now too weak for this target.

Exported function facts:

- Range: `0x004bb0e0-0x004bb111`
- Size: `0x31`
- IDA name: `sub_4BB0E0`
- Ghidra name: `FUN_004bb0e0`
- Signature shape: `void __cdecl(unsigned short *pixels, int pixelCount)`
- Callers: one, [UID:000200] at `0x0045857c`
- Callees: none
- Leaf: yes

Raw byte audit:

```text
helper+padding VA 0x004bb0db-0x004bb120 raw 0xba4db len 0x45 section .text
SHA1 7bf8e75b8703e8bcd8a2526eaf97cdac4751c4bd
cc cc cc cc cc 55 8b ec 56 8b 75 0c 85 f6 74 23 8b 45 08 66 90 0f b7 08 8d 40 02 8b d1 83 e1 1f d1 ea 81 e2 f0 7f 00 00 0b d1 66 89 50 fe 83 ee 01 75 e2 5e 5d c3 cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc

helper-body VA 0x004bb0e0-0x004bb111 raw 0xba4e0 len 0x31 section .text
SHA1 6b968b637368a4111005d0c0fee28cf2345cd216
55 8b ec 56 8b 75 0c 85 f6 74 23 8b 45 08 66 90 0f b7 08 8d 40 02 8b d1 83 e1 1f d1 ea 81 e2 f0 7f 00 00 0b d1 66 89 50 fe 83 ee 01 75 e2 5e 5d c3
```

Decompiled behavior:

```cpp
void ConvertRgb565ToRgb555Pixels(unsigned short* pixels, int pixelCount)
{
    for (; pixelCount != 0; --pixelCount) {
        const unsigned int pixel = *pixels;
        *pixels++ = static_cast<unsigned short>((pixel & 0x001f) | ((pixel >> 1) & 0x7ff0));
    }
}
```

Recommended descriptive source-facing name:

```cpp
ConvertRgb565ToRgb555Pixels
```

This name is stronger than the current raw label because the formula preserves the low five blue bits and shifts the upper 11 bits down by one, matching the observed RGB565-to-RGB555 compatibility direction. The name should be treated as descriptive rather than proven original spelling.

Rejected helper names:

- `sub_4BB0E0`: current compiler/generated name, not source-quality.
- `NormalizePostDecodePixels`: belongs to the EPFTileContext wrapper method, not to the raw loop helper.
- `Rgb555ToRgb565`: wrong direction for the target. [UID:000200] calls this helper only when RGB565 output is not active, after decoders have produced 16-bit RGB565-like pixels.
- `Swap565ChannelOrder` or `FixGreenChannel`: too narrow. The binary shifts the whole upper 11-bit region while preserving the low five bits.
- `SurfaceRenderCallbackTable` slot name: rejected because this helper is not a callback table slot and has only one direct caller.

Recommended owner for the helper if the supervisor creates a support page:

- Best owner: [UID:0000NT] `SoftwareBlend16`
- Rationale: the helper is stateless 16-bit pixel math, takes only a pixel pointer/count, has no Surface receiver, reads no Surface globals, and matches the file's documented role for RGB555/RGB565 software pixel operations.
- Secondary/context owner: [UID:0000OC] `Surface`, because Surface owns `g_surfaceUsesRgb565Pixels` and callback-family selection.
- Rejected direct owner for helper: [UID:00004I] `EPFTileContext`, because EPFTileContext is only the caller; the helper itself has no EPFTileContext knowledge.

## Owner / Source Placement Ranking

1. [UID:00004I] `EPFTileContext` / [UID:0000J4] `render/EPFTileContext.cpp`: accepted for [UID:000200]. The body is `__thiscall`, reads EPFTileContext fields, and is called by every relevant decoder as a post-decode context finalizer.
2. [UID:0000NT] `SoftwareBlend16`: accepted only as the best direct support owner for `0x004bb0e0` if split into its own helper page. It should not own [UID:000200].
3. [UID:0000OC] `Surface`: accepted as owner of `g_surfaceUsesRgb565Pixels`, Surface pixel-format flags, and render callback selection. Rejected as [UID:000200] owner because the function has an EPFTileContext receiver and no Surface receiver.
4. [UID:0000K3] `ImageLoaders`: rejected as owner. The decode wrappers are callers/producers; they call a context method after filling the buffer.
5. GrafPort / nearby text or DAT helpers: rejected. Address proximity around `0x004bb0e0` does not outweigh the target receiver and pixel-format evidence.
6. No-owner/non-emitting fallback: rejected. The target is reconstructable, method-shaped, reachable from six direct caller sites, and source placement is strong.

## First-Draft C++ Recommendation

Populate the formal C++ block for [UID:000200]. The following is source-facing and intentionally uses descriptive inferred names where exact originals are not proven.

```cpp
void EPFTileContext::NormalizePostDecodePixels()
{
    if (!g_surfaceUsesRgb565Pixels) {
        ConvertRgb565ToRgb555Pixels(
            static_cast<unsigned short*>(pixelData),
            (bounds.right - bounds.left) * (bounds.bottom - bounds.top));
    }
}
```

If the supervisor prefers not to introduce a global/helper declaration in this target page until support docs are updated, the same draft can be annotated with raw-address aliases in prose:

```cpp
// g_surfaceUsesRgb565Pixels is byte_69B3D5.
// ConvertRgb565ToRgb555Pixels is the leaf helper at 0x004bb0e0.
```

No target-specific no-code proof applies. The wrapper is not compiler-generated, not a thunk, not data-only, and not an aggregate-only range. It is a small source-authored receiver method whose only remaining uncertainty is exact original symbol spelling.

## Heuristic / Inference Reanalysis And Validation

### Current IDA name `sub_458560`

Evidence checked:

- Exported function data confirms a `0x25` byte `__thiscall` body at `0x00458560`.
- Six image decode callers consistently invoke it after writing EPFTileContext pixels.
- EPFTileContext class/file/aggregate docs already include the method as `NormalizePostDecodePixels`.

Rejected alternatives:

- `Decode...` names: rejected because the body does not parse image data and is shared by multiple decoders.
- `ConvertRgb565ToRgb555Pixels`: rejected for the target because conversion is delegated to the callee.
- `FinalizePixels`: plausible but less specific than the current documented name.

Best inference:

- Keep `EPFTileContext::NormalizePostDecodePixels()`.

Impact:

- Supports owner/emitter [UID:00004I], source placement in `render/EPFTileContext.cpp`, score raise, and C++ readiness.

### Current IDA name `sub_4BB0E0`

Evidence checked:

- Exported data gives exact `0x004bb0e0-0x004bb111` leaf helper, one caller, no callees.
- Raw bytes and decompile show the exact in-place formula `(pixel & 0x001f) | ((pixel >> 1) & 0x7ff0)`.
- Caller guard invokes it only when `g_surfaceUsesRgb565Pixels` is false.
- Surface initialization and screenshot paths prove the flag's true path is RGB565-capable.

Rejected alternatives:

- Keeping `sub_4BB0E0`: not source-quality.
- `Rgb555ToRgb565`: wrong direction for the observed call path.
- Surface callback slot name: wrong type, no table-slot evidence.
- EPFTileContext private method: possible source linkage if it was file-local, but no receiver or context fields exist in the helper.

Best inference:

- `ConvertRgb565ToRgb555Pixels(unsigned short* pixels, int pixelCount)`, descriptive not exact-original.

Impact:

- Removes the target's main helper-name blocker.
- Recommends a support page or SoftwareBlend16 entry for the helper.
- Does not block [UID:000200] C++ because a descriptive helper name is sufficient for first draft.

### Current global name `byte_69B3D5`

Evidence checked:

- Surface initializer writes by bit depth and green mask.
- Callback-table selection depends on the byte.
- Screenshot writer's `is565` branch uses RGB565 expansion formulas.
- Alpha lookup table uses 6-bit green when true and 5-bit middle channel when false.
- DLPalette and screenshot docs use the same flag in high-color/compatibility branches.

Rejected alternatives:

- `g_newRenderingMode`: too broad and policy-like.
- `g_highColorMode`: ambiguous.
- `g_rgb555Mode`: wrong polarity.
- `g_surfaceBitDepth32`: wrong because 16-bit RGB565 also sets the byte.

Best inference:

- `g_surfaceUsesRgb565Pixels`.

Impact:

- Supports first-draft C++.
- Surface support docs should carry the canonical alias and raw address.
- Exact original symbol spelling uncertainty caps the score below final but does not block emission.

### EPFTileContext fields used by target

Evidence checked:

- EPFTileContext class/aggregate layout.
- All six decode callers fill the primary 16-bit pixel buffer before calling the normalizer.
- The target uses only `this+0x04` and rectangle bounds at `+0x10/+0x14/+0x18/+0x1c`.

Rejected alternatives:

- `this+0x04` as palette or auxiliary data: rejected because the target casts it as a 16-bit pixel buffer and decode callers write pixels there.
- Width/height stored directly at `+0x18/+0x1c`: rejected because the formula subtracts left/top from right/bottom, matching bounds.

Best inference:

- Use `pixelData` and `bounds.{left,top,right,bottom}` in source-facing C++.

Impact:

- Field names are source-ready for this target. Broader EPFTileContext layout questions should not hold [UID:000200] at 84.

### Helper ownership/source route

Evidence checked:

- Helper has one EPFTileContext caller but no EPFTileContext receiver.
- Surface owns the runtime flag and callback selection.
- SoftwareBlend16 owns stateless RGB555/RGB565 software pixel helpers.
- No existing by-memory page accounts for `0x004bb0e0-0x004bb111`.

Rejected alternatives:

- Direct EPFTileContext helper ownership: callsite-only and structurally weaker.
- Direct Surface ownership: contextually plausible but the helper is stateless pixel math, not Surface state.
- No-owner/raw-helper: rejected because behavior and route are source-reconstructable.

Best inference:

- Keep [UID:000200] owner/emitter on EPFTileContext.
- Create or update support for `ConvertRgb565ToRgb555Pixels` under SoftwareBlend16, with Surface as dependency context.

Impact:

- Does not require splitting [UID:000200].
- Support-doc gap should be fixed by the supervisor, but [UID:000200] can still receive first-draft C++ now.

### Caller/reachability

Evidence checked:

- Exported IDA xrefs and image decode wrapper docs agree on six direct call/tail-call sites.
- There are no vtable, callback-table, or indirect-only routes for [UID:000200].

Rejected alternatives:

- Treating the function as dead/raw support: rejected by six direct caller sites.
- Moving it into one decoder: rejected because all relevant decoder families share it.

Best inference:

- Source-facing method called by the image decode wrappers as a post-decode normalization step.

Impact:

- Supports reconstructable/emitting state and score raise.

### Split/range decisions

Evidence checked:

- Raw bytes confirm target padding before/after.
- Helper raw bytes show an unmodeled independent helper at `0x004bb0e0-0x004bb111`.
- Current coverage has no row for `0x004bb0e0-0x004bb111`.

Rejected alternatives:

- Expanding [UID:000200] to include the helper: impossible by address and ownership.
- Ignoring `0x004bb0e0`: not acceptable long-term because it is a real leaf function with a direct code caller.

Best inference:

- [UID:000200] range stays unchanged.
- Recommend a new helper support page/coverage row for `0x004bb0e0-0x004bb111`.

Impact:

- Target can rise above 85 independently.
- Helper support page would further reduce unresolved names and generated-output gaps.

### Final C++ readiness

Evidence checked:

- Current generated output is only an empty marker for [UID:000200].
- The method is source-authored and not a thunk, scalar deleting destructor, RTTI/vtable data, or aggregate-only page.
- All operands have source-facing names with documented raw aliases.

Rejected alternatives:

- Withholding C++ until exact original names are proven: rejected under B-agent rules; descriptive names are sufficient when evidence-backed.
- Emitting raw decompiler syntax: rejected; source-facing C++ should use EPFTileContext fields and helper/global declarations.

Best inference:

- Populate first-draft `EPFTileContext::NormalizePostDecodePixels()`.

Impact:

- Directly resolves the blank-C++ blocker.
- Generated output should change from marker-only to a small source method once supervisor applies the update.

## Score / Metadata Recommendation

Recommended target metadata:

```text
COMPLETION: 88
CONFIDENCE: 91
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00004I
EMITTER_UIDS: 00004I
```

Rationale for `88/91`:

- `+` Exact raw body, SHA1, and padding confirmed.
- `+` Function model and calling convention confirmed by exported analysis.
- `+` Six direct caller/tail-call sites identified and source-shaped.
- `+` Single callee behavior and signature resolved to a descriptive helper.
- `+` `byte_69B3D5` polarity and role resolved strongly enough for a source-facing global name.
- `+` Receiver fields used by the target have defensible names and types.
- `+` Owner/source route and first-draft C++ are ready.
- `-` Exact original symbol spellings for the helper/global remain unproven.
- `-` `0x004bb0e0-0x004bb111` still needs a support page/coverage row outside this report-only target.

Do not reclassify as non-reconstructable, ignored, or coverage-only. The current `RECONSTRUCTABLE:TRUE` state is correct and now under-scored.

## Support-Doc Update Plan

Recommended target page changes:

- Replace current blocker wording around `sub_458560`, `sub_4BB0E0`, and `byte_69B3D5` with the resolved descriptive names:
  - `EPFTileContext::NormalizePostDecodePixels()`
  - `ConvertRgb565ToRgb555Pixels(unsigned short* pixels, int pixelCount)`
  - `g_surfaceUsesRgb565Pixels` / raw `byte_69B3D5`
- Add the raw byte/padding evidence and the exact helper range.
- Add first-draft C++ from this report.
- Update score metadata to `88/91`.

Recommended EPFTileContext class/file/aggregate updates:

- In `by-class/EPFTileContext.md`, note that [UID:000200] validates `pixelData` and `bounds.{left,top,right,bottom}` for the post-decode normalization method.
- In `by-file/EPFTileContext.md`, list `NormalizePostDecodePixels()` as source-ready pending only exact original helper/global spellings.
- In `by-memory/0x00457a60-0x00458610.EPFTileContext.md`, update the child summary for [UID:000200] from blank-C++/source-quality-blocked to first-draft-ready.

Recommended Surface/render docs updates:

- In `by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md`, add `g_surfaceUsesRgb565Pixels` as the preferred descriptive alias for `byte_69B3D5`, with polarity evidence from initializer, callback-family selection, screenshot writer, and alpha lookup.
- In `by-global/SurfaceRenderCallbackTable.md` and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`, add a cross-reference that [UID:000200] consumes the RGB565 flag but `0x004bb0e0` is not a callback-table slot.
- In `by-meta/client_new_rendering_mode.md`, note that [UID:000200] uses the active RGB565 flag as a post-decode compatibility guard; avoid using this target as sole proof of broader "new rendering mode" product semantics.

Recommended SoftwareBlend16 support update:

- Add `ConvertRgb565ToRgb555Pixels` to `by-file/SoftwareBlend16.md` as a stateless RGB565/RGB555 pixel transform helper if the supervisor creates the companion by-memory page.
- Cross-reference [UID:000200] as its only current direct caller.

Recommended project unresolved cleanup after supervisor incorporation:

- Remove or reduce `sub_4BB0E0` unresolved entries by naming the helper in the target/support docs.
- Replace raw-only `byte_69B3D5` target references with `g_surfaceUsesRgb565Pixels` plus raw alias.

## Exact by-memory/-coverage-report.md Replacement Row

Do not edit `by-memory/-coverage-report.md` directly. Replace the existing [UID:000200] row in the [UID:0000XY] EPFTileContext cluster, between the ignored padding rows for `0x00458557-0x00458560` and `0x00458585-0x00458590`, with:

```text
        - [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) 0x00458560-0x00458585 | method | EPFTileContextNormalizePostDecodePixels : reconstructable : 88% : very strong : B005 2026-06-19 source-quality pass confirms the exact 0x25-byte `__thiscall` body at PE raw offset `0x57960` (SHA1 `42c7d50e1d27b8fcec779b299c97b639bb5ab091`), nine-byte prepad and eleven-byte postpad, six direct image-decode caller/tail-call sites, single callee `0x004bb0e0` as `ConvertRgb565ToRgb555Pixels`, `g_surfaceUsesRgb565Pixels` / `byte_69B3D5` polarity from Surface initializer and screenshot/DLPalette consumers, `pixelData` and bounds-derived pixel count, EPFTileContext owner/emitter route, and first-draft `EPFTileContext::NormalizePostDecodePixels()` C++ readiness.
```

## Optional Helper Support / Coverage Rows

The target can be accepted independently, but the direct callee is a real unmodeled helper and should receive supervisor-owned support coverage.

Recommended new helper page path, using a supervisor-assigned UID:

```text
by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md
```

Recommended helper metadata if created:

```text
COMPLETION: 86
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 0000NT
EMITTER_UIDS: 0000NT
```

Recommended helper first-draft C++:

```cpp
void ConvertRgb565ToRgb555Pixels(unsigned short* pixels, int pixelCount)
{
    for (; pixelCount != 0; --pixelCount) {
        const unsigned int pixel = *pixels;
        *pixels++ = static_cast<unsigned short>((pixel & 0x001f) | ((pixel >> 1) & 0x7ff0));
    }
}
```

If the helper page is created, insert a coverage row after [UID:00016F] `ConstantLineCountHelper` and before [UID:00016G] `LoadDatFileBuffer`, replacing `UID:TBD` with the supervisor-assigned UID:

```text
        - [UID:TBD][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) 0x004bb0e0-0x004bb111 | function | ConvertRgb565ToRgb555Pixels : reconstructable : 86% : strong : Exact 0x31-byte `__cdecl` leaf pixel-format helper at PE raw offset `0xba4e0` (SHA1 `6b968b637368a4111005d0c0fee28cf2345cd216`), five-byte prepad after the GrafPort/text-effect cluster and fifteen-byte postpad before LoadDatFileBuffer, one direct caller [UID:000200] at `0x0045857c`, no callees/data refs, in-place `(pixel & 0x001f) | ((pixel >> 1) & 0x7ff0)` transform over an unsigned-short pixel buffer, and best direct owner [UID:0000NT] `SoftwareBlend16` as stateless RGB565/RGB555 render math while Surface owns the format flag that gates the call.
```

Recommended ignored-padding rows if the helper support page is created and the surrounding gaps are not already represented by the supervisor:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004bb0db-0x004bb0e0 | padding | TextEffect/ConvertRgb565ToRgb555Pixels alignment : ignored : 100% : strong : Confirmed five `0xcc` alignment bytes after the preceding modeled text-effect range and before `ConvertRgb565ToRgb555Pixels`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004bb111-0x004bb120 | padding | ConvertRgb565ToRgb555Pixels/LoadDatFileBuffer alignment : ignored : 100% : strong : Confirmed fifteen `0xcc` alignment bytes after `ConvertRgb565ToRgb555Pixels` and before [UID:00016G] `LoadDatFileBuffer`.
```

## Generated-Output Expectation

Current generated output at `auto-generated/NexusTK/render/EPFTileContext.cpp` contains an empty marker for [UID:000200]. After supervisor incorporation, this target should emit the first-draft method body above in that file. If the helper support page is also created under SoftwareBlend16, `auto-generated/NexusTK/render/SoftwareBlend16.cpp` should receive the helper body or declaration according to the project's helper-emission policy.

## Validation / Commands

Validation performed:

- `rg` searches for `00458560`, `sub_458560`, `004bb0e0`, `sub_4BB0E0`, `byte_69B3D5`, `SurfaceRenderCallbackTable`, `client_new_rendering_mode`, and relevant caller/global names across `project-documentation`, `auto-generated`, and exported function data.
- `Get-Content` / `Select-String` reads of the mandate docs, target page, EPFTileContext class/file/aggregate, image decode callers, Surface pixel-format/callback docs, SoftwareBlend16 docs, generated output, stats, unresolved/resolved reports, and coverage report.
- Raw PE byte audit against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for `0x00458557-0x00458590` and `0x004bb0db-0x004bb120`.
- IDA MCP probe attempted and failed because the local server was unavailable.

No by-* validator was run because this assignment is report-only and no target/support/coverage docs were directly edited.

## Changed Files

Created:

```text
tools/leaser/Agents/Agent-B005/research/000200-EPFTileContextNormalizePostDecodePixels-source-quality.md
```

No target, support, generated, or supervisor-owned coverage files were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/000200-EPFTileContextNormalizePostDecodePixels-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"000200"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
