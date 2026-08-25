** TARGET-REPORT-UID:0000YN **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000YN DrawFrameWithBlendMode Source-Quality Research


Assignment: `B008-report-0000YN-DrawFrameWithBlendMode-source-quality-20260627`  
Agent: `Agent-B008`  
Mode: report-only research first; accepted implementation callback completed on 2026-06-28. The report-only pass made no by-* edits, generated edits, coverage edits, validator/tool-state edits, IDA database edits, or leases. The implementation callback edited only accepted target/support by-* docs and updated this checklist.  
Target: [UID:0000YN] `by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md`  
Required report path: `tools/leaser/Agents/Agent-B008/research/0000YN-DrawFrameWithBlendMode-source-quality.md`  
Report timestamp: `2026-06-27T23:59:00.4288046-04:00`

## Executive Conclusion

The old blank-C++ blocker is resolved. [UID:0000YN] should emit first-draft C++ through [UID:0000HF] `AlphaMaskSurface` in `NexusTK/render/AlphaMaskSurface.cpp`.

The source-facing prototype should be a member-style `AlphaMaskSurface` operation, not a free helper:

```cpp
void AlphaMaskSurface::DrawFrameWithBlendMode(const RectBounds *destinationRect,
                                              AlphaMaskSurface *sourceFrame,
                                              const RectBounds *sourceRect,
                                              int blendMode)
```

The decisive evidence is current MCP disassembly: the caller loads the destination `AlphaMaskSurface *` into `ecx`, pushes only four explicit arguments, and the callee returns with `retn 10h`. Modeling this as a global `DrawFrameWithBlendMode(targetSurface, ...)` was useful staging vocabulary, but it does not match the call convention as well as a member method.

Recommended metadata after implementation:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `86` | `89` |
| `CONFIDENCE` | `89` | `92` |
| `CANONICAL_OWNER` | `0000HF` | `0000HF` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000HF` | `0000HF` |
| C++ block | blank | populate with the exact formal block below |

Confidence remains below final-audit quality because `AlphaMaskBlend*` enum spelling and exact original helper declaration placement are inferred/descriptive, not symbol-proven. That is a confidence cap only, not a no-code blocker.

## Files And Evidence Read

Direct target and support docs:

| Item | Use |
| --- | --- |
| `tools/leaser/Agents/Agent-B008/goal.md` | Assignment, target, report path, current blockers, and no-edit/no-lease rules. |
| `by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md` | Current target metadata, old blank-C++ rationale, caller/callee notes, range/padding evidence. |
| `by-item/DrawFrameWithBlendMode_00462E10.md` | Duplicate/support item for the same function; currently also marked as an emitter and must be made non-duplicating in implementation. |
| `by-file/AlphaMaskSurface.md` | Source file route `NexusTK/render/AlphaMaskSurface.cpp`; confirms LightObjImageLib is a consumer and AlphaMaskSurface owns the surface/blitter support route. |
| `by-class/AlphaMaskSurface.md` | Layout offsets: `bounds` at `+0x04`, `pixels` at `+0x14`, `width/height/stride` at `+0x18/+0x1c/+0x20`. |
| `by-type/by-struct/AlphaMaskSurfaceLayout.md` | Confirms object layout used by target pointer arithmetic. |
| `by-type/by-struct/AlphaSurfaceBufferView.md` | Confirms the 0x14-byte view record is separate from full `AlphaMaskSurface`; target uses the full source-frame object, not only a view record. |
| `by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md` | Caller passes mode `1`, currently in free-helper syntax. |
| `by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md` | Caller passes mode `2`, currently in free-helper syntax. |
| `by-file/LightObjImageLib.md` | Confirms LightObjImageLib consumes generated alpha frames but does not own the alpha-frame blitter. |
| `by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md` | Row helper for mode `0`; source-facing dependency name and argument order. |
| `by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md` | Row helper for mode `1`; source-facing dependency name and argument order. |
| `by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md` | Row helper for mode `2`; source-facing dependency name and argument order. |
| `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` | Confirms `0x004b7cc0` as `IntersectRects`, a free `RectBounds.cpp` helper. |
| `by-type/by-struct/RectBoundsLayout.md` | Confirms four-int `left`, `top`, `right`, `bottom` layout. |
| `by-file/RectBounds.md` and `by-class/RectBounds.md` | Confirms `RectBounds.cpp` helper route and accepted helper names. |
| `executed-b-agent-research/B003/0002IU-00017Q-0002IW-0002IX-0002IY-lightobjimagelib-source-quality.md` | Prior staging prototype and LightObjImageLib caller C++; useful evidence but superseded by current call-convention analysis for member-vs-free syntax. |

Generated files were read only to identify stale output/duplicate markers. They were not edited.

## Current IDA MCP Session

IDA MCP was available and used. This is not fallback-only evidence.

| Evidence | Result |
| --- | --- |
| MCP endpoint | `http://127.0.0.1:13337/mcp` |
| Server | `ida-pro-mcp` 1.0.0 |
| Active database | session `b001_000241_20260627`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Module/input | `NexusTK.exe`, imagebase `0x400000`; input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| Health | `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, worker PID `23132`, not analyzing |

Main MCP tools used: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `xref_query`, `callees`, `analyze_batch`, `decompile`, `disasm`, `get_bytes`, `make_signature_for_range`, and `find_bytes`.

## Live MCP Findings

`lookup_funcs` confirms the relevant function starts and sizes:

| Address | IDA name | Size | Source-facing role |
| --- | --- | ---: | --- |
| `0x00462e10` | `sub_462E10` | `0x10e` | `AlphaMaskSurface::DrawFrameWithBlendMode` |
| `0x004b7cc0` | `sub_4B7CC0` | `0xa9` | `IntersectRects` |
| `0x004dfbb0` | `sub_4DFBB0` | `0xaa` | `LightObjImageLib::DrawLightMode1` |
| `0x004dfc60` | `sub_4DFC60` | `0xaa` | `LightObjImageLib::DrawLightMode2` |
| `0x00460df0` | `sub_460DF0` | `0x89` | `ByteSpanCopyRows` |
| `0x00460e80` | `sub_460E80` | `0x89` | `ByteSpanAddRows` |
| `0x00460f10` | `sub_460F10` | `0x89` | `ByteSpanSubtractRows` |

`xrefs_to` / `xref_query` report exactly two incoming code refs to `0x00462e10`:

| Xref | Caller | Meaning |
| --- | --- | --- |
| `0x004dfc42` | `0x004dfbb0` | Light draw mode 1 calls target with mode `1`. |
| `0x004dfcf2` | `0x004dfc60` | Light draw mode 2 calls target with mode `2`. |

`callees 0x00462e10` reports only:

- `0x004b7cc0` / `IntersectRects`
- `0x00460df0` / `ByteSpanCopyRows`
- `0x00460e80` / `ByteSpanAddRows`
- `0x00460f10` / `ByteSpanSubtractRows`
- `@__security_check_cookie@4`

`decompile 0x00462e10` reports IDA prototype `int __thiscall(int *this, int *, int, _DWORD *, int)`, with the receiver in `ecx`, stack args for destination rect, source frame, source rect, and mode. Return type is a decompiler artifact: callers ignore `eax`, row helpers are side-effect row writers, and the source-facing body should be `void`.

Key target instructions:

```text
462e20: mov eax, ecx
462e2a: cmp dword ptr [eax+14h], 0
462e3d: test edi, edi
462e45: test esi, esi
462e4d: test ecx, ecx
462e5f: call sub_4B7CC0
462edb: call sub_460F10
462eef: call sub_460E80
462f03: call sub_460DF0
462f1b: retn 10h
```

The caller traces prove member syntax:

```text
4dfc28: mov ecx, [ebp+var_28]
4dfc2e: push 1
4dfc3c: push eax        ; sourceRect
4dfc3d: push ebx        ; sourceFrame
4dfc41: push eax        ; destinationRect
4dfc42: call sub_462E10

4dfcd8: mov ecx, [ebp+var_28]
4dfcde: push 2
4dfcec: push eax        ; sourceRect
4dfced: push ebx        ; sourceFrame
4dfcf1: push eax        ; destinationRect
4dfcf2: call sub_462E10
```

The current body byte fence is exact:

```text
0x00462e00: c2 24 00 cc ... cc 55 8b ec ...
0x00462f18: 8b e5 5d c2 10 00 cc cc 55 8b ec ...
```

So the half-open range remains `0x00462e10-0x00462f1e`, with `0x00462f1e-0x00462f20` padding before the successor prologue. `make_signature_for_range 0x00462e10-0x00462f1e` returned a unique wildcarded IDA signature. `find_bytes` found zero matches for direct VA/RVA literal pointer forms `10 2e 46 00` and `10 2e 06 00`; current xref evidence remains only the two rel32 call sites above.

## Helper And Argument Resolution

Use these source-facing names during implementation:

| Binary evidence | Source-facing name | Reason |
| --- | --- | --- |
| `ecx` receiver, reads `+0x04/+0x14/+0x20` | `AlphaMaskSurface *this` | Member call convention and AlphaMaskSurface layout offsets. |
| `[ebp+arg_0]`, first stack arg | `const RectBounds *destinationRect` | Caller builds destination bounds around the light center and target surface clips against it. |
| `[ebp+arg_4]`, second stack arg | `AlphaMaskSurface *sourceFrame` | Caller passes `lightInfo->generatedFrame`; target reads `pixels` and `stride` from offsets `+0x14/+0x20`. |
| `[ebp+arg_8]`, third stack arg | `const RectBounds *sourceRect` | Caller passes local frame bounds `(0,0,width,height)`, and target maps clipped destination deltas into this source rectangle. |
| `[ebp+arg_C]`, fourth stack arg | `int blendMode` | Existing callers pass literals `1` and `2`; keeping `int` avoids forcing enum conversions at caller docs. |
| `0x004b7cc0` | `IntersectRects` | RectGeometryHelpers documents this exact cdecl helper; target ignores the boolean return and consumes the cleared-output rectangle on empty intersections. |
| `0x00460df0` | `ByteSpanCopyRows` | Mode `0`; copies source bytes into destination. |
| `0x00460e80` | `ByteSpanAddRows` | Mode `1`; byte add/wrapping semantics per helper page. |
| `0x00460f10` | `ByteSpanSubtractRows` | Mode `2`; byte subtract/wrapping semantics per helper page. |

Mode names are implementation-ready as file-level/source vocabulary:

| Value | Recommended name | Callee |
| ---: | --- | --- |
| `0` | `kAlphaMaskBlendCopy` | `ByteSpanCopyRows` |
| `1` | `kAlphaMaskBlendAdd` | `ByteSpanAddRows` |
| `2` | `kAlphaMaskBlendSubtract` | `ByteSpanSubtractRows` |

Unsupported modes intentionally fall through without drawing. The decompiler's `result = a5 - 2` is an `eax` artifact; no caller observes a return value.

## Owner And Source Placement

Keep source ownership and emission under [UID:0000HF] `AlphaMaskSurface` in `NexusTK/render/AlphaMaskSurface.cpp`.

Rejected alternatives:

| Alternative | Reason rejected |
| --- | --- |
| `LightObjImageLib` owner | It has the only two current direct callers, but both are consumers that pass `generatedFrame` surfaces to the alpha-mask blitter. They do not own the target, mode `0` is not exercised there, and the target operates on `AlphaMaskSurface` fields. |
| Free helper prototype | Prior docs used `DrawFrameWithBlendMode(targetSurface, ...)`, but live disassembly proves `thiscall`: target in `ecx`, four pushed args, `retn 10h`. Member syntax is the source-facing match. |
| Row-helper owner | The target calls byte-span row primitives, but it computes AlphaMaskSurface clipping and source/destination pointers. Row helpers remain lower-level dependencies, not owners. |
| `AlphaSurfaceBufferView` source type for `sourceFrame` | The target reads full `AlphaMaskSurface` offsets `+0x14` and `+0x20`, and callers pass generated `AlphaMaskSurface` objects. The 0x14-byte view record is a separate helper type. |
| No-code/compiler artifact | The body is a normal source-shaped blitter with project callers, source-level rectangle clipping, and mode dispatch. It is not a thunk, destructor wrapper, runtime helper, padding, or generated glue. |

No target split is required. [UID:0000YN] is one exact, contiguous function. The by-item duplicate [UID:0000UI] should not also emit a second copy of the same code.

## Formal C++ Disposition

Populate [UID:0000YN] with this exact first-draft formal block during the implementation callback:

```cpp
enum AlphaMaskBlendMode
{
    kAlphaMaskBlendCopy = 0,
    kAlphaMaskBlendAdd = 1,
    kAlphaMaskBlendSubtract = 2
};

void AlphaMaskSurface::DrawFrameWithBlendMode(const RectBounds *destinationRect,
                                              AlphaMaskSurface *sourceFrame,
                                              const RectBounds *sourceRect,
                                              int blendMode)
{
    if (pixels == NULL || destinationRect == NULL || sourceFrame == NULL || sourceRect == NULL) {
        return;
    }

    RectBounds clippedDestination;
    IntersectRects(&bounds, destinationRect, &clippedDestination);

    const int rowCount = clippedDestination.bottom - clippedDestination.top;
    const int sourceStride = sourceFrame->stride;
    const int widthBytes = clippedDestination.right - clippedDestination.left;

    const int sourceX = clippedDestination.left + sourceRect->left - destinationRect->left;
    const int sourceY = clippedDestination.top + sourceRect->top - destinationRect->top;

    const uint8_t *sourceBytes = sourceFrame->pixels + sourceX + sourceStride * sourceY;
    uint8_t *destinationBytes = pixels + clippedDestination.left + clippedDestination.top * stride;

    switch (blendMode) {
    case kAlphaMaskBlendCopy:
        ByteSpanCopyRows(sourceBytes, sourceStride, destinationBytes, stride, widthBytes, rowCount);
        break;

    case kAlphaMaskBlendAdd:
        ByteSpanAddRows(sourceBytes, sourceStride, destinationBytes, stride, widthBytes, rowCount);
        break;

    case kAlphaMaskBlendSubtract:
        ByteSpanSubtractRows(sourceBytes, sourceStride, destinationBytes, stride, widthBytes, rowCount);
        break;

    default:
        break;
    }
}
```

Implementation notes for this C++:

- Do not add a `sourceFrame->pixels != NULL` guard. The binary checks destination `pixels`, `destinationRect`, `sourceFrame`, and `sourceRect`, but not the source pixel pointer.
- Do not branch on `IntersectRects` returning false. The binary ignores the return value; the helper clears `clippedDestination`, making `rowCount` and `widthBytes` zero for the row helpers.
- Keep `blendMode` as `int` because current caller docs pass literal `1` and `2`. The enum constants are source-facing names for the switch cases, not a required parameter type change.
- Keep the body `void`; the apparent decompiler integer return is unobserved `eax` state after side-effect row helpers.
- Keep the enum/file helper names local to the `AlphaMaskSurface` support docs unless a later broader alpha-mask pass creates a shared header-level enum.

## Support Update Requirements

An accepted implementation callback should update these support docs without editing generated or coverage files by hand:

| File | Required update |
| --- | --- |
| [UID:0000YN] target by-memory page | Raise to `89/92`, populate formal C++, replace "prototype/helper names provisional" with this report's member-method resolution, and record the current MCP session evidence. |
| [UID:0000UI] by-item duplicate | Convert to a non-emitting support/alias page for [UID:0000YN] or otherwise clear its emitter route so generated `AlphaMaskSurface.cpp` does not contain duplicate code/empty marker for the same function. Preserve evidence and point to [UID:0000YN] as the source-bearing page. |
| [UID:0000HF] `by-file/AlphaMaskSurface.md` | Change the DrawFrameWithBlendMode row/notes from free helper wording to `AlphaMaskSurface::DrawFrameWithBlendMode(...)`; record mode names and owner-vs-caller conclusion. |
| [UID:00000C] `by-class/AlphaMaskSurface.md` | Add method inventory/support note for `DrawFrameWithBlendMode(...)`, keeping broader class C++ caveats separate. |
| LightObjImageLib draw-mode caller pages [UID:0002IW] and [UID:0002IX] | Change formal call syntax from `DrawFrameWithBlendMode(targetSurface, ...)` to `targetSurface->DrawFrameWithBlendMode(...)`; optionally replace literal comments with `kAlphaMaskBlendAdd` and `kAlphaMaskBlendSubtract` if the enum is recorded in AlphaMaskSurface support docs. |
| [UID:0000KP] `by-file/LightObjImageLib.md` | Note that the draw helpers consume the member method and do not own the blitter. |
| Row helper pages [UID:00020C]/[UID:00020D]/[UID:00020E] | No required C++ change; optionally add a short reverse-reference that this target uses their accepted argument order. |
| Generated tracker/output/coverage | Do not hand-edit. Run scoped validators with `--wait-generated` so stale `82/86` empty markers for [UID:0000YN] and [UID:0000UI] refresh. |

## Implementation Checklist

- [x] Lease only the files that will be edited immediately; do not lease during report-only review. Proof: B008 leased exactly the seven edited by-* docs for the implementation/validator batch: [UID:0000YN], [UID:0000UI], `by-file/AlphaMaskSurface.md`, `by-class/AlphaMaskSurface.md`, [UID:0002IW], [UID:0002IX], and `by-file/LightObjImageLib.md`.
- [x] Update [UID:0000YN] `by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md` with the exact formal C++ block, `89/92`, member-method prototype, current MCP evidence, helper/mode names, and rejected alternatives. Proof: target metadata is `COMPLETION:89`, `CONFIDENCE:92`, owner/emitter [UID:0000HF], formal `AlphaMaskSurface::DrawFrameWithBlendMode` block populated, and the page now records B008 MCP session `b001_000241_20260627`, thiscall proof, helper/mode resolution, and rejected owner/prototype alternatives.
- [x] Update [UID:0000UI] `by-item/DrawFrameWithBlendMode_00462E10.md` as a non-emitting support/alias for [UID:0000YN], or otherwise remove duplicate emission while preserving evidence. Proof: by-item metadata is `COMPLETION:-1`, `CONFIDENCE:-1`, `CANONICAL_OWNER:0000YN`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, and prose points to [UID:0000YN] as the canonical source-bearing emitter.
- [x] Update `by-file/AlphaMaskSurface.md` and `by-class/AlphaMaskSurface.md` with the member-method source route and mode/helper name resolution. Proof: both support docs now describe `AlphaMaskSurface::DrawFrameWithBlendMode`, record the B008 thiscall/member-method proof, and identify [UID:0000UI] as non-emitting support.
- [x] Update LightObjImageLib caller support docs so first-draft C++ calls `targetSurface->DrawFrameWithBlendMode(...)`, not the old free helper spelling. Proof: [UID:0002IW] and [UID:0002IX] formal C++ now use `targetSurface->DrawFrameWithBlendMode(&destinationRect, sourceFrame, &sourceRect, 1/2)`, and `by-file/LightObjImageLib.md` now documents LightObjImageLib as a consumer of the AlphaMaskSurface member blitter.
- [x] Leave generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, and IDA DB untouched by hand. Proof: no manual edits were made to generated/project/coverage/tool/IDA files; validator-owned generated refresh side effects were produced only through scoped validator commands.
- [x] Release leases immediately after the edit batch. Proof: B008 ran `python .\source-3\project-documentation\tools\leaser\leaser.py B008 unlease ...` for all seven leased by-* docs and each returned `Success`.
- [x] Run scoped validators with `--wait-generated` for every edited by-* file, including [UID:0000YN], [UID:0000UI], `AlphaMaskSurface` file/class docs, and any LightObjImageLib caller docs touched. Proof: all commands ran from `source-3/project-documentation`, exited `0`, and reported `ok: 1`: `000000004871` for `by-memory\0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md` at `2026-06-28T01:35:15-04:00`; `000000004872` for `by-item\DrawFrameWithBlendMode_00462E10.md`; `000000004873` for `by-file\AlphaMaskSurface.md`; `000000004874` for `by-class\AlphaMaskSurface.md`; `000000004875` for `by-memory\0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md`; `000000004876` for `by-memory\0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md`; and `000000004877` for `by-file\LightObjImageLib.md` at `2026-06-28T01:36:19-04:00`.
- [x] Confirm generated `auto-generated/NexusTK/render/AlphaMaskSurface.cpp` reflects current [UID:0000YN] C++ and does not retain stale duplicate empty markers for [UID:0000UI]. Proof: generated file header is `validator-command-id: 000000004877`, `validator-refreshed-at: 2026-06-28T01:36:19-04:00`; it contains [UID:0000YN] `Completion:89 | Confidence:92` and the formal `AlphaMaskSurface::DrawFrameWithBlendMode` body, and no [UID:0000UI] stale duplicate marker/body appears.
- [x] Check off this checklist with command ids/timestamps/proof only during the implementation callback, not during report-only work. Proof: checklist updated after accepted implementation and validators completed.

## Final Disposition

Report-only conclusion: implementation-ready formal C++ for [UID:0000YN], no split needed, no target no-code disposition, owner/emitter remains [UID:0000HF] `AlphaMaskSurface`, source placement remains `NexusTK/render/AlphaMaskSurface.cpp`, and by-item [UID:0000UI] should become non-duplicating support for the source-bearing by-memory page.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000YN-DrawFrameWithBlendMode-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000YN-DrawFrameWithBlendMode-source-quality.md","timestamp":"2026-06-28T02:45:04","uid":"0000YN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
