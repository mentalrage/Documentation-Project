** TARGET-REPORT-UID:00023S **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID00023S SurfaceDirectDrawCopyHelper Source-Quality Report

## Finalized Report / Current Recommendation

UID00023S remains attached to [UID:0000OC][Surface](../../../../../by-file/Surface.md) and is treated as a source-ready retained raw DirectDraw surface-copy helper rather than a blank-C++ empty marker. The accepted target metadata is `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank `EMITTER_POSITION_OPTIONAL`.

The current MCP pass against live IDB session `aa3930bd` confirms the exact half-open raw-body range `0x00559a10-0x00559aef`, a `0xdf` / 223-byte body, no modeled IDA function at the start, zero direct xrefs to the start/end, one-byte `0xcc` boundaries, a unique full-range signature, and source-shaped DirectDraw work: stack `DDSURFACEDESC` setup, `g_pApplication` dimension reads, `g_pDirectX->m_pDirectDraw->CreateSurface`, a retained receiver surface at `this+0x100`, `IDirectDrawSurface::Blt(DDBLT_WAIT)`, and temporary-surface `Release`.

The no-function/no-direct-xref evidence is still a confidence cap, not a reason to keep the target non-emitting. The body is real source-authored code with a normal prologue, security cookie, DirectDraw calls, and a complete `ret`; the remaining cap is exact original helper spelling and receiver declaration. The accepted formal C++ is intentionally source-like, conservative, and file-local under `NexusTK/render/Surface.cpp`.

## Supporting Research

Sources reviewed:

- Target doc [by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md](../../../../../by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md).
- Support docs [by-file/Surface.md](../../../../../by-file/Surface.md), [by-memory/0x00557140-0x00559aef.SurfacePresentation.md](../../../../../by-memory/0x00557140-0x00559aef.SurfacePresentation.md), [by-file/DirectX.md](../../../../../by-file/DirectX.md), [by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md](../../../../../by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md), [by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md](../../../../../by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md), [by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md](../../../../../by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md), [by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md](../../../../../by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md), and [by-global/g_pDirectX.md](../../../../../by-global/g_pDirectX.md).
- Prior B-agent research found by `rg`: B001 SurfacePresentation split, B005 Surface empty-emitter family, B002 SurfaceDirectDrawRestoreMaintenance, and B001 g_pApplication reports. Those prior reports support Surface-family placement but do not supersede the current MCP pass.
- Current MCP endpoint `http://127.0.0.1:13337/mcp` was checked with read-only `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `xref_query`, `make_signature_for_range`, and `lookup_funcs` for direct callees. No IDA process-management command was used.

## Target

- UID: `00023S`
- Target path: `by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md`
- Current owner/emitter: [UID:0000OC][Surface](../../../../../by-file/Surface.md)
- Current score at assignment: `85/89`
- Required report path: `tools/leaser/Agents/Agent-B003/research/00023S-SurfaceDirectDrawCopyHelper-source-quality.md`
- Queue context: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> Not-Covered Files - Reconstructable.

## Current Target State

At report intake, the target was reconstructable and Surface-owned but kept the formal `RECONSTRUCTION_CPP CODE` block blank. Its blocker text said IDA did not model the body as a function, no direct caller had been recovered, and final helper/class names were not source quality.

That blocker was too strong and has been replaced during the implementation callback. The no-function/no-xref state remains true and is preserved, but the current MCP pass proves a stable, source-shaped, complete raw helper with exact behavior and enough conservative naming to emit a first-draft file-local helper through UID0000OC. The target no longer says C++ must remain blank solely because the raw entry lacks an IDA function object.

## Heuristic / Inference Reanalysis And Validation

The heuristic issue was whether a raw unmodeled DirectDraw helper with no direct start xrefs should remain a blank empty-emitter marker or can emit source-quality C++ through the Surface file. I rechecked the target with the restored IDB session rather than relying on stale reports.

Validation result:

- `idb_list` returned one active worker session `aa3930bd` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, pid/worker_pid `13724`.
- `server_health(database=aa3930bd)` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs` reports the predecessor `0x005595d0` as `sub_5595D0` size `0x43f`, target addresses `0x00559a0f`, `0x00559a10`, and `0x00559aef` as not functions, and successor `0x00559af0` as `sub_559AF0` size `0x2d`.
- `get_bytes` confirms `0x00559a0f` is `0xcc`, target start bytes are `55 8b`, the target tail ends `8b e5 5d c3`, and `0x00559aef` is the successor boundary `0xcc`.
- `xref_query` confirms zero xrefs to `0x00559a10` and zero xrefs to `0x00559aef`.
- `make_signature_for_range(0x00559a10,0x00559aef,wildcard_operands=false)` returned a unique exact byte signature for the 223-byte range.

The inference that this is not padding follows from the normal MSVC prologue/epilogue, stack frame, `_memset`, security cookie check, global refs, and three coherent DirectDraw vtable calls. The inference that it can emit conservatively follows from the complete semantics, existing UID0000OC Surface owner/emitter assignment, and sibling Surface docs that already map `this+0x100` to a primary/display DirectDraw surface.

## Evidence Standards Used

- Live MCP evidence is required for range, function/non-function, bytes, xrefs, and direct callee identity.
- Support docs are used for owner/emitter conventions, not as a substitute for live evidence.
- `tools/int_convert.py` is used for decimal/hex conversions used in the report: `0xdf` = 223, `0x94` = 148, `0x58` = 88, `0x6c` = 108, `0x840` = 2112, `0x7d0` = 2000, `0x100` = 256, `0x1000000` = 16777216, `0xa68` = 2664, and `0xa6c` = 2668.
- Source-facing names must avoid raw IDA labels (`sub_`, `dword_`, `xmmword_`) in the formal C++.
- During the original report-only pass, no generated output or by-* docs were edited. The implementation callback changed only the by-* docs listed in `## Changed Files`, plus this report ledger/checklist.

## Evidence Checked

MCP session and health:

- HTTP MCP initialization succeeded, and the active IDB returned by `idb_list` is `aa3930bd`.
- `server_health(database=aa3930bd)` returned `status ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

Function and boundary checks:

- `lookup_funcs(['0x005595d0','0x00559a0f','0x00559a10','0x00559aef','0x00559af0'])` returned `sub_5595D0` at `0x005595d0` size `0x43f`, not-functions at `0x00559a0f`, `0x00559a10`, and `0x00559aef`, and `sub_559AF0` at `0x00559af0` size `0x2d`.
- `get_bytes(0x00559a0e,4)` returned `0x00 0xcc 0x55 0x8b`, proving the predecessor function ends before a one-byte padding byte and the raw helper starts at `0x00559a10`.
- `get_bytes(0x00559aef,8)` returned `0xcc 0x55 0x8b 0xec 0x8d 0x45 0x10 0x50`, proving a one-byte post-helper `0xcc` before the successor function prologue.
- `get_bytes(0x00623470,16)` returned `00 00 00 00 00 00 00 00 d0 07 00 00 d0 07 00 00`, the source-rectangle seed `{0,0,2000,2000}`.

Target byte/signature checks:

- `get_bytes(0x00559a10,223)` returned the full target body:

```text
55 8b ec 81 ec 94 00 00 00 a1 24 2f 67 00 33 c5
89 45 fc a1 1c ab 67 00 0f 28 05 70 34 62 00 56
6a 58 8b 90 68 0a 00 00 8b f1 8b 80 6c 0a 00 00
89 45 f4 8d 45 80 6a 00 50 c7 45 ec 00 00 00 00
c7 45 f0 00 00 00 00 89 55 f8 0f 11 45 dc e8 4d
06 07 00 a1 20 ab 67 00 8d 95 6c ff ff ff 83 c4
0c c7 85 70 ff ff ff 6c 00 00 00 c7 85 74 ff ff
ff 07 00 00 00 c7 45 d8 40 08 00 00 c7 85 7c ff
ff ff d0 07 00 00 c7 85 78 ff ff ff d0 07 00 00
8b 40 04 6a 00 52 8d 95 70 ff ff ff 8b 08 52 50
ff 51 18 8b 86 00 01 00 00 8d 55 dc 6a 00 68 00
00 00 01 52 ff b5 6c ff ff ff 8b 08 8d 55 ec 52
50 ff 51 14 8b 85 6c ff ff ff 50 8b 08 ff 51 08
8b 4d fc 33 cd 5e e8 44 dc 06 00 8b e5 5d c3
```

- `make_signature_for_range(0x00559a10,0x00559aef,wildcard_operands=false)` returned the same 223-byte signature and marked it `unique:true`.

References and callee checks:

- `xref_query(to 0x00559a10)` returned total `0`.
- `xref_query(to 0x00559aef)` returned total `0`.
- `xref_query(to 0x00623470)` returned one data ref at `0x00559a28`, `fn:null`.
- `xref_query(to 0x0067ab20)` returned total `19`, including target ref `0x00559a63`, `fn:null`, to `g_pDirectX`.
- Paged `xref_query(to 0x0067ab1c)` returned total `140`, including target ref `0x00559a23`, `fn:null`, to `g_pApplication`.
- `lookup_funcs(['_memset','@__security_check_cookie@4','0x005ca0b0','0x005c772f'])` resolved `_memset` at `0x005ca0b0` size `0x15a` and `@__security_check_cookie@4` at `0x005c772f` size `0x11`.

Decoded body facts:

- Stack frame reserves `0x94` / 148 bytes.
- The body reads `g_pApplication` at `0x00559a23`, then reads `+0xa68` / 2664 and `+0xa6c` / 2668 into a destination rectangle/dimension local.
- The body copies the `0x00623470` seed into a source rectangle local.
- `_memset` is called after pushing `0x58` / 88 bytes, consistent with zeroing the middle/tail of a stack `DDSURFACEDESC`.
- Descriptor stores include `dwSize = 0x6c` / 108, `dwFlags = 7`, `ddsCaps.dwCaps = 0x840` / 2112, `dwHeight = 0x7d0` / 2000, and `dwWidth = 0x7d0` / 2000.
- The body reads `g_pDirectX` at `0x00559a63`, loads a DirectDraw interface from offset `+4`, and calls vtable slot `+0x18`, consistent with `IDirectDraw::CreateSurface`.
- The body reads the receiver field at `this+0x100` / 256 and calls vtable slot `+0x14`, consistent with `IDirectDrawSurface::Blt`.
- The blit flags immediate `0x1000000` / 16777216 matches `DDBLT_WAIT`.
- The body calls vtable slot `+0x8` on the temporary surface, consistent with COM `Release`.

## Positive Evidence Summary

- The target body is a real source-authored helper, not padding: normal prologue, stack allocation, `___security_cookie` use, `_memset`, DirectDraw interface dispatch, security-cookie check, and `ret`.
- The range is exact: predecessor modeled function ends before `0x00559a0f`, one-byte `0xcc` before target, target starts `0x00559a10`, target ends with `ret` before `0x00559aef`, and one-byte `0xcc` precedes modeled successor `0x00559af0`.
- The behavior is source-ready: create a 2000x2000 system-memory offscreen surface, blit it to the receiver's primary/display surface using application display dimensions, then release the temporary surface.
- Current `g_pApplication` and `g_pDirectX` refs are target-local refs outside an IDA function object, matching the raw-helper model.
- UID0000OC already owns the Surface presentation/copy bucket and currently emits `Surface.cpp`; the target already has `EMITTER_UIDS:0000OC`.
- Sibling docs support field naming: `this+0x100` is the same primary/display DirectDraw surface family used by `BlitSurfaceToDisplay` and ScreenPane restore/initializer evidence.

## Negative Evidence Summary

- There is no modeled IDA function at `0x00559a10`; the formal C++ must not use `sub_559A10`.
- There are zero direct xrefs to `0x00559a10` and `0x00559aef`; the report cannot claim a recovered caller route.
- DirectX is a dependency only. It owns `g_pDirectX` and DirectDraw lifetime/setup, not this Surface copy helper.
- ScreenPane is a receiver/field family context, not the accepted canonical owner for this exact raw target. Other siblings moved to ScreenPane only when direct callers/field lifecycle made that stronger; this target has no recovered caller.
- The mixed parent `0x00557140-0x00559aef.SurfacePresentation` remains non-emitting and mixed-owner; it should not absorb or emit this exact child.
- The body is not a blank no-code marker or padding span. The one-byte `0xcc` boundaries are adjacent alignment only.
- The body should not be named from raw IDA labels such as `dword_67AB1C`, `dword_67AB20`, `xmmword_623470`, `this[64]`, or `_DWORD *`.

## IDA Rename / Type / Comment Recommendations

IDA database edits were not requested in the report-only pass or this implementation callback. These recommendations remain documentation-level source-facing names, not mandatory IDB mutations:

| Item | Recommendation | Evidence | Safety |
| --- | --- | --- | --- |
| Helper name | Use conservative source-facing name `CopySurfaceToPrimarySurface` or `CopyDirectDrawSurfaceToPrimary`. | Body creates a scratch DirectDraw surface, blits through receiver `+0x100`, and releases the scratch surface. | Safe for by-* prose/C++; exact original spelling remains confidence cap. |
| Receiver type | Use `ScreenPane *screenPane` only as an inferred receiver/field-family type in first-draft C++. | Sibling UID00039W and UID0003A4 document `+0x100` as primary/display surface in the ScreenPane presentation receiver family. | Safe with explicit confidence cap; not enough to reroute canonical owner. |
| `this+0x100` field | Use `m_primarySurface` with alternate note `m_displaySurface`. | UID00039Z/UID0003A4 support maps the same field to the display/presentation DirectDraw surface restored and blitted by siblings. | Safe in source-facing prose with alternate preserved. |
| `g_pApplication +0xa68/+0xa6c` fields | Use provisional display destination names such as `m_presentationHeight` / `m_presentationWidth` or `m_displayHeight` / `m_displayWidth`. | Target reads these fields immediately before building the blit destination rectangle. | Safe only with confidence cap; exact member spelling/order remains unresolved. |
| DirectDraw types | Use `DDSURFACEDESC`, `IDirectDrawSurface`, `IDirectDraw`, `DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH`, `DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY`, and `DDBLT_WAIT`. | Descriptor size `0x6c`, flags `7`, caps `0x840`, 2000x2000 dimensions, DirectDraw slot `+0x18`, surface slot `+0x14`, and release slot `+0x8`. | Safe for source-facing draft; header typedef spelling remains a cap. |
| Raw labels | Leave `sub_559A10`, raw `dword_`, `xmmword_`, and `_DWORD *` out of final source prose/C++. | They are decompiler/IDA artifacts and not source names. | Required. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00023S-001 | Target metadata should move from `85/89` to `88/91`. | 91 | Current MCP proves exact range, body bytes, unique signature, boundary padding, globals, DirectDraw behavior, and existing UID0000OC owner/emitter. No modeled function, no direct caller/xref route, original helper spelling, receiver declaration, and application-dimension member names remain confidence caps, but they do not block the `88/91` source-ready recommendation. | Target metadata header. | Set `COMPLETION:88`, `CONFIDENCE:91`. | applied: `by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md` header now has `COMPLETION:88` / `CONFIDENCE:91`; validator `000000006063` confirmed both updates. |
| C-00023S-002 | Keep `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank optional position. | 91 | Surface file already lists UID00023S; behavior is Surface presentation/copy helper; DirectX/ScreenPane are dependencies/receiver context. | Target metadata header. | Preserve owner/reconstructable/emitter, no optional position. | applied: target header keeps `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank `EMITTER_POSITION_OPTIONAL`. |
| C-00023S-003 | Insert first-draft formal C++ into the target formal block. | 88 | Complete source-shaped body now supports conservative file-local helper despite no IDA function/xrefs. | Target `RECONSTRUCTION_CPP CODE`. | Insert exact formal block from this report. | applied: target formal block now contains `static void CopyDirectDrawSurfaceToPrimary(ScreenPane *screenPane)` with descriptor setup, `CreateSurface`, `Blt(DDBLT_WAIT)`, and `Release`. |
| C-00023S-004 | Replace stale blank-C++ blocker with current no-function/no-xref confidence cap. | 91 | `lookup_funcs` not-function and `xref_query` zeroes are still true, but body is not padding and has full semantics. | Target Status/Rebuild/Score sections. | Update wording. | applied: target Status/Behavior/Score/Changes now describe no-function/no-xref/original-name as confidence caps, not blank-emitter blockers. Historical blank-C++ entries are explicitly superseded. |
| C-00023S-005 | Add current MCP session evidence. | 91 | Session `aa3930bd`, `server_health ok`, lookup/get_bytes/xref/signature evidence. | Target evidence section. | Incorporate current evidence at report-level detail. | applied: target `2026-07-04 B003 Current MCP Source-Ready Pass` records session `aa3930bd`, health, exact range/size, boundary bytes, not-function state, zero xrefs, unique signature, descriptor/global refs, `_memset`, security cookie, and vtable calls. Surface and SurfacePresentation support docs also cite the same session evidence. |
| C-00023S-006 | Add exact body semantics: descriptor setup, globals, DirectDraw vtable calls, `this+0x100`, constants. | 90 | Bytes and decoded instruction facts listed above. | Target behavior/evidence sections. | Incorporate source-ready behavior. | applied: target behavior/evidence sections document the stack frame, source/destination rectangles, `g_pApplication` dimensions, `DDSURFACEDESC` fields, `g_pDirectX`, `this+0x100`, DirectDraw `CreateSurface`, surface `Blt(DDBLT_WAIT)`, and COM `Release`. |
| C-00023S-007 | Preserve negative evidence rejecting DirectX ownership, ScreenPane reroute, parent aggregate emission, padding/no-code, and raw names. | 91 | Support docs and live MCP reject those routes. | Target ownership/negative evidence sections. | Add/refresh negative evidence. | applied: target `Source Placement And Rejected Alternatives` preserves DirectX, ScreenPane, mixed aggregate, padding/no-code, raw-label, and no-owner/non-emitting rejections. |
| C-00023S-008 | Update `by-file/Surface.md` UID00023S row from blank-C++ blocker to source-ready retained file-local helper. | 89 | Existing row names old blocker; current evidence resolves enough for first draft while preserving no-entry cap. | `by-file/Surface.md` Proposed Contents/evidence notes. | Update support doc if accepted. | applied: `by-file/Surface.md` Proposed Contents row, evidence note, and 2026-07-04 change-log entry now describe UID00023S as source-ready retained file-local Surface helper with no-entry/original-name caps preserved; validator `000000006064` passed. |
| C-00023S-009 | Update mixed parent `SurfacePresentation` UID00023S row to `88/91` and source-ready helper while keeping parent non-emitting. | 89 | Parent row currently says existing raw helper `85/89`; parent remains mixed/non-emitting. | `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` child inventory/evidence notes. | Update support doc if accepted. | applied: `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` child row now shows `88/91` and source-ready UID00023S detail; evidence and change-log preserve parent `RECONSTRUCTABLE:FALSE`, blank owner/emitter/C++; validator `000000006065` passed. |
| C-00023S-010 | Mark sibling/global docs already-present unless stale detail is found during callback. | 87 | UID0003A4/UID00039W already support `+0x100`; g_pApplication/g_pDirectX docs already establish global roles. | UID0003A4, UID00039W, UID000294, UID000295, DirectX docs. | Review only; edit only stale contradictions. | already-present: no stale contradiction was found requiring edits; target/support text cites UID0003A4/UID00039W for `+0x100` context and UID000294/UID000295/g_pDirectX as dependencies rather than owners. |
| C-00023S-011 | Scoped validators should run only for changed by-* docs during implementation callback. | 90 | The callback changed exactly the target, `by-file/Surface.md`, and the mixed `SurfacePresentation` parent. | Report `Validator Results` and callback checklist. | Run scoped validators for changed by-* docs and record results. | applied: scoped validators only were run for the three changed by-* docs: command IDs `000000006063`, `000000006064`, and `000000006065`, all exit 0 / `ok: 1`. |

## Ranked Ownership Analysis

| Rank | Candidate | Decision | Evidence |
| --- | --- | --- | --- |
| 1 | [UID:0000OC][Surface](../../../../../by-file/Surface.md) / `NexusTK/render/Surface.cpp` | Accepted. | Current target already assigns owner/emitter to UID0000OC. The body is DirectDraw surface presentation/copy work, uses Surface presentation fields and sibling primary/display surface naming, and belongs with the UID0003A4/UID00039W Surface presentation neighborhood. |
| 2 | [UID:0000CB][ScreenPane](../../../../../by-class/ScreenPane.md) / [UID:0000NB][ScreenPane](../../../../../by-file/ScreenPane.md) | Rejected as canonical owner for this exact target. | The receiver field family is ScreenPane-shaped, but no direct caller, vtable slot, or lifecycle proof routes this raw target to ScreenPane. Sibling reroutes to ScreenPane had stronger caller/field-lifecycle evidence. |
| 3 | [UID:0000IW][DirectX](../../../../../by-file/DirectX.md) | Rejected. | `g_pDirectX` and DirectDraw vtable calls are service dependencies; DirectX docs own singleton/lifetime, not Surface copy policy. |
| 4 | [UID:0001G6][SurfacePresentation aggregate](../../../../../by-memory/0x00557140-0x00559aef.SurfacePresentation.md) | Rejected as emitter. | The aggregate is a mixed-owner non-emitting index; exact child pages carry source ownership. |
| 5 | No-owner/non-emitting padding/raw marker | Rejected. | Normal prologue/body/epilogue, unique 223-byte signature, DirectDraw semantics, and current UID0000OC owner/emitter assignment prove source-authored code. |

## Source Placement

Recommended source placement remains `NexusTK/render/Surface.cpp` through [UID:0000OC][Surface](../../../../../by-file/Surface.md). The exact C++ should be emitted as a file-local helper or equivalent local Surface presentation helper because original symbol spelling and caller route are not recovered.

Do not migrate the target to `DirectX.cpp`, `ScreenPane.cpp`, or the mixed parent aggregate without new caller or type evidence. ScreenPane field names are useful for readable C++ and should be treated as receiver-family support rather than canonical owner proof.

## First-Draft C++ Recommendation

The following formal block was accepted and inserted into the target during the implementation callback. This draft deliberately avoids `sub_559A10`, raw `_DWORD *`, `this[64]`, and IDA global labels. Exact helper name, receiver type, application dimension member names, and DirectDraw typedef/header spelling remain confidence caps.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void CopyDirectDrawSurfaceToPrimary(ScreenPane *screenPane)
{
    RECT sourceRect = { 0, 0, 2000, 2000 };
    RECT destinationRect = {
        0,
        0,
        g_pApplication->m_presentationWidth,
        g_pApplication->m_presentationHeight
    };

    DDSURFACEDESC surfaceDesc;
    IDirectDrawSurface *scratchSurface = NULL;

    memset(&surfaceDesc, 0, sizeof(surfaceDesc));
    surfaceDesc.dwSize = sizeof(surfaceDesc);
    surfaceDesc.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
    surfaceDesc.dwHeight = 2000;
    surfaceDesc.dwWidth = 2000;
    surfaceDesc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    g_pDirectX->m_pDirectDraw->CreateSurface(&surfaceDesc, &scratchSurface, NULL);
    screenPane->m_primarySurface->Blt(&destinationRect,
                                      scratchSurface,
                                      &sourceRect,
                                      DDBLT_WAIT,
                                      NULL);
    scratchSurface->Release();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Notes:

- `m_presentationWidth` / `m_presentationHeight` are provisional names for reads at `g_pApplication+0xa6c` and `g_pApplication+0xa68`; exact member spelling/order remains capped.
- `m_primarySurface` preserves the stronger sibling support for receiver `+0x100`, with `m_displaySurface` as documented alternate wording.
- A callback may choose `CopySurfaceToPrimarySurface` instead of `CopyDirectDrawSurfaceToPrimary` if the local style favors shorter helper names; the exact original spelling is not recovered.

## Final Recommendation

Implement UID00023S as a source-ready retained Surface helper:

- Raise score to `88/91`.
- Keep owner/emitter as UID0000OC.
- Insert the formal first-draft C++ block.
- Replace stale "C++ remains blank until source-facing helper name and inbound route are recovered" wording with a precise cap: no modeled function/no direct xref/original helper spelling unresolved, but body semantics are source-ready.
- Update support docs so Surface and the mixed SurfacePresentation parent no longer describe UID00023S as a blank-C++ unresolved empty marker.

## Recommended Target Doc Changes

For `by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md`:

- Set `COMPLETION:88` and `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank `EMITTER_POSITION_OPTIONAL`.
- Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report.
- Add current MCP session `aa3930bd` evidence: active NexusTK IDB, health OK, exact range `0x00559a10-0x00559aef`, size `0xdf` / 223, not-functions at target start/end, predecessor/successor modeled functions, one-byte `0xcc` boundaries, unique signature, zero xrefs to `0x00559a10` and `0x00559aef`, descriptor-seed ref at `0x00559a28`, `g_pApplication` ref at `0x00559a23`, `g_pDirectX` ref at `0x00559a63`, `_memset`, security-cookie check, and DirectDraw vtable call semantics.
- Preserve no-route confidence caps: no modeled function, no recovered direct caller, exact helper name unknown, receiver type/member names inferred, and DirectDraw typedef/header spelling inferred.
- Preserve rejected alternatives: DirectX owner, ScreenPane owner, mixed parent aggregate emitter, padding/no-code treatment, raw IDA labels, and no-owner/non-emitting treatment.

## Recommended Support Doc Changes

For `by-file/Surface.md`:

- Update the UID00023S Proposed Contents row so it says this exact child is source-ready as a retained file-local Surface DirectDraw copy helper emitted through UID0000OC.
- Preserve the no-direct-entry caveat and exact original name cap.
- Replace wording that says C++ remains blank until source-facing helper name/inbound route are recovered.

For `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`:

- Update the UID00023S child row from `85/89` "Existing raw DirectDraw copy helper" to `88/91`, source-ready retained Surface helper with current MCP `aa3930bd` evidence.
- Keep the parent metadata unchanged: `RECONSTRUCTABLE:FALSE`, blank owner/emitter/C++ for the mixed aggregate.

For `by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md` and `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`:

- Review only. They already provide the important `this+0x100` primary/display surface context; edit only if stale text directly contradicts the UID00023S recommendation.

For `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md`, `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md`, and `by-global/g_pDirectX.md`:

- Mark already-present unless a callback review finds stale wording. They already document the global dependencies and should not become owners of UID00023S.

## Score And Metadata Recommendation

Before:

- `COMPLETION:85`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000OC`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OC`
- `EMITTER_POSITION_OPTIONAL:` blank
- Formal C++ blank

After:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000OC`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OC`
- `EMITTER_POSITION_OPTIONAL:` blank
- Formal C++ populated with conservative source-ready helper

Rationale:

- Completion rises because the current MCP pass resolves the old source-quality blocker enough for a formal first-draft helper.
- Confidence rises because exact byte/range/signature/global/callee evidence is direct and current.
- Score remains below mid-90s because no modeled function, caller route, original helper spelling, exact receiver declaration, and exact application-dimension member names remain unresolved.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Result |
| --- | --- | --- |
| Is `0x00559a10` a modeled function now? | Current `lookup_funcs` on session `aa3930bd`. | No. It is still not an IDA function. |
| Is there a direct caller/xref to the raw start? | Current `xref_query(to 0x00559a10)` and `xref_query(to 0x00559aef)`. | No direct xrefs. This remains a confidence cap. |
| Could this be padding or compiler-only dead bytes? | Checked prologue/body/epilogue, calls, globals, descriptor constants, unique signature, and boundary bytes. | Rejected. It is coherent source-authored code. |
| Should ScreenPane own it because the receiver has `+0x100` primary/display surface semantics? | Compared sibling ScreenPane reroutes and checked available evidence. | Not enough for owner migration; retain Surface owner and document receiver-field cap. |
| What are `g_pApplication+0xa68/+0xa6c` names? | Checked current bytes and support docs; no exact source field spelling recovered. | Use provisional destination width/height names with cap. |
| Is `0x00623470` an external source symbol? | Current `get_bytes` and `xref_query` show one target-local data ref and `{0,0,2000,2000}` seed bytes. | Treat as source rectangle seed in C++; do not expose raw label. |

## Validator Results

Implementation callback validators were run only for changed by-* docs from `E:\NTK\GhidraBridge\source-3\project-documentation`.

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / side effects |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md` | `python .\tools\validator.py --mode file --file by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md --apply --queue-timeout 240` | `000000006063` | `2026-07-04T04:15:48-04:00` | 0 | 1 | `missing_ref_uid:3` for UID00039Z references; `completion_update:1`, `confidence_update:1`, `autogen_registry_update:2`, `reference_index_add:1`, `projected_stats_update:1`, `stats_row_remove:1`, `stats_rescore_recommended:1`; `generated_refresh: deferred`. |
| `by-file/Surface.md` | `python .\tools\validator.py --mode file --file by-file/Surface.md --apply --queue-timeout 240` | `000000006064` | `2026-07-04T04:15:57-04:00` | 0 | 1 | `missing_ref_uid:30` for existing Surface-family UID references; `stats_row_update:1`, `projected_stats_update:1`; `generated_refresh: deferred`. |
| `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` | `python .\tools\validator.py --mode file --file by-memory/0x00557140-0x00559aef.SurfacePresentation.md --apply --queue-timeout 240` | `000000006065` | `2026-07-04T04:16:05-04:00` | 0 | 1 | `missing_ref_uid:58` for existing SurfacePresentation child UID references; `stats_incremental_noop:1`, `projected_stats_update:1`; `generated_refresh: deferred`. |

Generated refresh state: all three scoped validators reported `generated_refresh: deferred`; no generated files or coverage reports were manually edited by B003.

## Changed Files

Implementation callback changed:

- `by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md`
- `by-file/Surface.md`
- `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`
- `tools/leaser/Agents/Agent-B003/research/00023S-SurfaceDirectDrawCopyHelper-source-quality.md`

Review-only support docs left unedited as already-present/no stale contradiction found: `by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md`, `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`, `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md`, `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md`, and `by-global/g_pDirectX.md`.

Lease status: B003 leased the three edited by-* docs for the edit/validator batch. The release command after validation returned `Rejected[No active lease]` for all three paths, and `tools/leaser/Agents/current_leases.md` had no B003 entries afterward, so no B003 lease remains active.

No `execute_report`, dry-run/probing execute, lifecycle/archive/registry command, manual report move, generated-file manual edit, coverage-report edit, validator-state manual edit, or supervisor-ledger edit was run by B003.

## Implementation Tracking Checklist

Implementation callback checklist:

- [x] Lease `by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md`, `by-file/Surface.md`, and `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` immediately before editing.
- [x] Set target metadata to `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank optional position.
- [x] Insert the exact formal C++ block from `## First-Draft C++ Recommendation` into the target formal `RECONSTRUCTION_CPP CODE` block.
- [x] Add current MCP session `aa3930bd` range/function/byte/xref/signature/global/callee evidence to the target.
- [x] Replace stale target wording that requires blank C++ solely because no function/caller was recovered.
- [x] Preserve confidence caps for no modeled function, no direct xrefs, exact helper name, receiver type, application member names, DirectDraw typedef/header spelling, and `m_primarySurface` alternate naming.
- [x] Preserve rejected alternatives: DirectX ownership, ScreenPane ownership, mixed parent emission, padding/no-code, raw IDA names, and no-owner/non-emitting treatment.
- [x] Update `by-file/Surface.md` UID00023S row/source-output notes with source-ready retained Surface helper evidence and no-entry/original-name caps.
- [x] Update `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` UID00023S child row to `88/91` while keeping parent non-emitting.
- [x] Review sibling/global support docs (`UID0003A4`, `UID00039W`, `UID000294`, `UID000295`, `g_pDirectX`) and mark already-present: no stale contradiction required edits.
- [x] Run scoped validator for every changed by-* doc from `source-3/project-documentation` with `--apply --queue-timeout 240`: `000000006063`, `000000006064`, and `000000006065`, all exit 0 / `ok: 1`.
- [x] Release/verify leases immediately after the edit/validator batch: release command found no active leases, and lease report grep found no B003 entries.
- [x] Update this report's ledger/checklist with `applied`, `already-present`, validator command_id/timestamp/exit/ok/warnings, generated-refresh state, changed files, and lease status.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000006105","destination_path":"executed-b-agent-research/B003/00023S-SurfaceDirectDrawCopyHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00023S-SurfaceDirectDrawCopyHelper-source-quality.md","timestamp":"2026-07-04T04:40:41-04:00","uid":"00023S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
