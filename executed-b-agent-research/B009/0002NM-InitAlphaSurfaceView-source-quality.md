** TARGET-REPORT-UID:0002NM **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent B009 Research Report: [UID:0002NM] InitAlphaSurfaceView Source Quality

Report status: IMPLEMENTED_PENDING_SUPERVISOR_VERIFICATION
Target: `by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md`
Required output: `tools/leaser/Agents/Agent-B009/research/0002NM-InitAlphaSurfaceView-source-quality.md`
Research timestamp: `2026-06-28T00:09:13-04:00`
Revision timestamp: `2026-06-28T01:33:02-04:00`

Initial report-only pass: no leases were taken. No by-* documentation, generated files, coverage reports, validator/tool state, IDA DB state, or MCP process state were modified during the report-only pass.

Implementation callback pass: B009 edited accepted by-* target/support docs only. B009 took short leases for the immediate edit/validator batch; the first lease batch expired during validation and the still-active AlphaMaskSurface support leases were explicitly released. Final lease report check after release showed no B009 leases remaining.

## Current Target State

The target page currently has:

| Field | Current value |
| --- | --- |
| UID | `0002NM` |
| Completion | `85` |
| Confidence | `89` |
| Canonical owner | `0000HF` |
| Reconstructable | `TRUE` |
| Emitter UIDs | `0000HF` |
| Formal C++ | blank |

Current documentation already has the core behavior: exact function range `0x004623c0-0x00462514`, IDA name `sub_4623C0`, no direct callers, destination `off_6112EC` vtable write, optional clip rectangle, full/clipped non-owning view setup, `InitRectBounds`/`IntersectRects` helpers, and final ownership clear. The unresolved blocker is source shape/source placement, not behavior coverage.

## Evidence Checked

Read and used:

- `tools/leaser/Agents/Agent-B009/goal.md`
- `by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md`
- `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`
- `by-file/AlphaMaskSurface.md`
- `by-class/AlphaMaskSurface.md`
- `by-file/IntAlphaSurface.md`
- `by-class/IntAlphaSurface.md`
- `by-type/by-struct/AlphaMaskSurfaceLayout.md`
- `by-type/by-struct/AlphaSurfaceBufferView.md`
- `by-type/by-vtable/IntAlphaSurfaceVtable.md`
- `by-item/BuildClippedAlphaSurfaceView_00462320.md`
- `by-item/InitAlphaSurfaceView_004623C0.md`
- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` as stale queue leads only.
- Prior B001 vtable/raw-default reports as leads only.

Generated tracker state is stale for this target: the tracker/coverage rows still show older `80/88` style data, while the live target page is already `85/89`. Do not edit generated tracker or coverage files during implementation.

## Live IDA MCP Facts

MCP endpoint: `http://127.0.0.1:13337/mcp`
Active database id: `b001_000241_20260627`
IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
Module: `NexusTK.exe`
Input path reported by server: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
Image base: `0x400000`
Auto-analysis: ready
Hex-Rays: ready

Read-only MCP calls used:

| JSON-RPC id | Tool | Relevant result |
| --- | --- | --- |
| `4` | `server_health` | status `ok`, active IDB above, auto-analysis ready, Hex-Rays ready |
| `5` | `lookup_funcs` | `0x004623c0 -> sub_4623C0`, size `0x154`; `0x00462514` not a function; `0x00462520 -> sub_462520`; `0x00462320 -> sub_462320`; `0x00462230` is a chunk of `sub_4623C0`; `0x00462120` not a function |
| `6` / `7` | `analyze_function` / `decompile` | prototype `int __thiscall sub_4623C0(int this, int a2, int *a3)`, callees `sub_4B7C50`, `sub_4B7CC0`, security cookie; callers empty |
| `9` / `22` | `xrefs_to` / `xref_query` | `0x004623c0` has zero xrefs; `0x00462514` has zero xrefs; `0x006112ec` has five data refs at `0x46212c`, `0x46217b`, `0x462237`, `0x462415`, `0x46327a` |
| `11` | `disasm` | confirms `ECX` saved as source object, `arg_0` saved as destination, `arg_4` as optional clip, `mov dword ptr [edi], offset off_6112EC` at `0x462415`, final `mov byte ptr [edi+24h], 0` at `0x4624f3`, and `retn 8` |
| `12` | `analyze_function 0x00462320` | sibling clipped buffer-view helper has prototype `int __thiscall(_DWORD *this, int, int *)`, one caller `sub_4DD2C0`, same source object/out-parameter/clip pattern without the vtable object wrapper |
| `14` | `analyze_function 0x00462170` | active constructor-like function writes `off_6112EC`, initializes the same layout, allocates owned pixels for positive dimensions, and has live callers |
| `19` | `get_bytes` | `0x00462514-0x00462520` is twelve `0xcc` bytes; `0x006112ec` dwords are `0x00463270`, `0x00462260`, `0`, `0` |
| `20` | `get_int` | confirms vtable slot values `0x00463270`, `0x00462260`, `0`, `0` |
| `21` | `find_bytes` | no direct VA/RVA literal matches for `0x004623c0` or raw `0x00462120` |
| `23` | `entity_query` | RTTI/name evidence names `IntAlphaSurface` only: `??_R4IntAlphaSurface@@6B@`, `??_R0?AVIntAlphaSurface@@@8`, etc.; no AlphaMaskSurface function names |
| `25` / `26` / `27` | rectangle helper analysis/decompile | `0x004b7c50` is `InitRectBounds(RectBounds*, left, top, right, bottom)`; `0x004b7cc0` is `IntersectRects(first, second, out)` and clears output on failed intersections |

Important decompiler facts from `0x004623c0`:

- `this`/`ECX` is the source alpha surface object, not the destination object.
- `a2`/`EDI` is the destination full object/view storage.
- `a3` is an optional `RectBounds *` clip rectangle.
- The destination is initialized as an `IntAlphaSurface` object: `off_6112EC` store at destination `+0x00`, zero bounds through `InitRectBounds(destination + 0x04, 0, 0, 0, 0)`, payload fields at `+0x14/+0x18/+0x1c/+0x20`, and ownership byte at `+0x24`.
- The no-clip branch copies the source payload block from `source + 0x14` to `dest + 0x14`, then the final byte clear forces the destination to non-owning.
- The clipped branch builds source bounds `(0, 0, source->width, source->height)`, intersects with the supplied clip, and on success computes `pixels + clipped.left + clipped.top * stride`, width `right - left`, height `bottom - top`, and copied stride.
- The final `dest->ownsBuffer = false` is unconditional.

## Resolution

This assignment should not defer the target as "no direct callers" or "source split provisional." The correct disposition is:

- Keep [UID:0002NM] source-owned/emitted by [UID:0000HF] `AlphaMaskSurface`.
- Treat the destination type as `IntAlphaSurface`, because the destination receives the RTTI-backed `IntAlphaSurface` vtable at `0x006112ec`.
- Do not move the target to `IntAlphaSurface` as a member method. The live prototype and disassembly prove `ECX` is the source alpha surface and the destination `IntAlphaSurface *` is an explicit out parameter.
- Keep the no-direct-caller fact as a liveness/confidence caveat only. It does not block source-quality C++ because the exact body, dependencies, route, source object, destination object type, and sibling pattern are all resolved.
- Do not emit explicit vtable-assignment C++. Model the vtable write as placement construction of the destination `IntAlphaSurface`.

The source-facing signature should be documented as:

```cpp
IntAlphaSurface *AlphaMaskSurface::InitAlphaSurfaceView(IntAlphaSurface *view, const RectBounds *clipBounds) const
```

The exact original helper spelling is still inferred, so final-audit confidence remains capped. The current provisional name `InitAlphaSurfaceView` is acceptable because it describes the function and is already the page identity.

## Score And Metadata Recommendation

Update the target to:

| Field | Recommended value |
| --- | --- |
| `COMPLETION` | `90` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | keep `0000HF` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `EMITTER_UIDS` | keep `0000HF` |

Rationale:

- Completion can rise to `90` because live IDA resolves the exact range, typed calling convention, out-object shape, helper callees, source object fields, destination non-owning lifetime, vtable/type role, sibling helper relationship, no-xref state, and first-draft C++ route.
- Confidence can rise to `91` because `ECX`/out-parameter evidence rejects the previous source-split blocker for this exact helper. It should not rise higher because the function still has no direct callers or direct pointer literals and the original source spelling remains inferred.

## Formal C++ Recommendation

Set the target page's formal `RECONSTRUCTION_CPP CODE` body between `BEGIN` and `END` exactly to:

```cpp
IntAlphaSurface *AlphaMaskSurface::InitAlphaSurfaceView(IntAlphaSurface *view, const RectBounds *clipBounds) const
{
    view = new (view) IntAlphaSurface();

    if (clipBounds == NULL) {
        view->m_pixels = m_pixels;
        view->m_width = m_width;
        view->m_height = m_height;
        view->m_stride = m_stride;
    } else if (m_pixels != NULL) {
        RectBounds sourceBounds;
        RectBounds clippedBounds;

        InitRectBounds(&sourceBounds, 0, 0, m_width, m_height);
        if (IntersectRects(&sourceBounds, clipBounds, &clippedBounds)) {
            view->m_pixels = m_pixels + clippedBounds.left + clippedBounds.top * m_stride;
            view->m_width = clippedBounds.right - clippedBounds.left;
            view->m_height = clippedBounds.bottom - clippedBounds.top;
            view->m_stride = m_stride;
        } else {
            view->m_pixels = NULL;
        }
    } else {
        view->m_pixels = NULL;
    }

    view->m_ownsBuffer = false;
    return view;
}
```

Notes for implementation:

- Leave the `RECONSTRUCTION_CPP CODE:[[[...]]]` metadata value as the normal empty wrapper unless the validator requires otherwise; insert the function between `BEGIN`/`END`.
- The placement construction represents the binary vtable write and zero-bounds/empty-payload initialization. Do not add a decompiler-style `view->vtable = &off_6112EC` line.
- The failed clip/no-pixels cases should be described as null-pixel/non-owning empty views. The only semantically reliable liveness signal is `m_pixels == NULL`; do not overstate width/height/stride as an API contract in prose.
- Source-shape recheck: `NULL` is used instead of the C++11 null pointer keyword to match the late-1990s/mid-2000s Windows C++ source-shape standard. No other modernized constructs were found in the proposed formal C++ block; placement `new`, `const` pointer parameters, and `false` are compatible with the intended Visual C++ 6/7-era style and preserve the observed runtime behavior.

## Recommended Documentation Changes

### Target Page

`by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md`

- Update header scores to `COMPLETION:90`, `CONFIDENCE:91`.
- Keep owner/emitter/reconstructable fields unchanged: `CANONICAL_OWNER:0000HF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HF`.
- Insert the formal C++ block above.
- Replace "final C++ blank" and "source split provisional blocker" wording with the resolved source shape: AlphaMaskSurface file helper, destination `IntAlphaSurface *`, optional `RectBounds *` clip.
- Preserve the no-direct-caller/no-pointer-hit evidence as a confidence cap.
- Record current MCP provenance from session `b001_000241_20260627`.

### AlphaMaskSurface Support

`by-file/AlphaMaskSurface.md`

- Update the `0x004623c0` row from "provisional" to "AlphaMaskSurface file helper that placement-initializes a caller-supplied non-owning `IntAlphaSurface` view."
- Replace the old "leaving final IntAlphaSurface source split unresolved" text for this target. The broader raw default constructor / `IntAlphaSurface` file split caveat can remain for other family items.
- Keep the file-level owner/emitter route for [UID:0002NM].

`by-class/AlphaMaskSurface.md`

- Update the method inventory to use [UID:0002NM] directly, not only the old by-item index.
- State that `ECX` is the source alpha surface and the destination `IntAlphaSurface *` is an out parameter.
- Narrow the existing "view helper ownership remains provisional" language: it remains true for some family/raw items, but not for [UID:0002NM].

`by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`

- Update the function table and evidence notes to reflect that [UID:0002NM] now has resolved AlphaMaskSurface helper ownership and first-draft C++.
- Preserve the aggregate's broader unresolved items, especially raw `0x00462120` and the family source split where still applicable.

`by-type/by-struct/AlphaMaskSurfaceLayout.md`

- Update the old "do not emit a final header-level type until raw default constructor and no-xref view initializer are resolved" wording. The no-xref view initializer part is resolved for [UID:0002NM]; the raw default constructor and final header-level naming split can remain caveats.

### IntAlphaSurface Support

`by-file/IntAlphaSurface.md`

- Keep `IntAlphaSurface.cpp` as the provisional class/vtable/destructor research anchor.
- Change any wording that implies [UID:0002NM] is an `IntAlphaSurface` member/source-owned method. It should be cross-referenced as an AlphaMaskSurface helper that constructs/initializes a caller-supplied `IntAlphaSurface` view.
- Keep the `IntAlphaSurface` vtable/class owner caveat: RTTI owns the type artifact; AlphaMaskSurface code contains construction/use sites.

`by-class/IntAlphaSurface.md`

- Document [UID:0002NM] as external construction/use-site evidence for `IntAlphaSurface` layout and vtable, not a direct method.
- Preserve direct class ownership for destructor/release/vtable slots.

`by-type/by-vtable/IntAlphaSurfaceVtable.md`

- Add a current evidence note that `0x00462415` remains a construction/use-site store from [UID:0002NM], whose owning helper is AlphaMaskSurface while the vtable artifact remains class-owned by `IntAlphaSurface`.

### Index Page

`by-item/InitAlphaSurfaceView_004623C0.md`

- Keep this as a non-emitting index to canonical [UID:0002NM].
- Update stale wording that says source module is provisional between AlphaMaskSurface and IntAlphaSurface; the canonical target is AlphaMaskSurface-owned/emitted, with `IntAlphaSurface` as destination type.

### No Change Recommended

- `by-item/BuildClippedAlphaSurfaceView_00462320.md`: keep its separate status. It is the 0x14-byte buffer-view sibling with a real caller, not the full `IntAlphaSurface` object initializer.
- `by-type/by-struct/AlphaSurfaceBufferView.md`: keep as the POD buffer-view layout. [UID:0002NM] uses the same payload fields inside a full object, but it does not require changing the POD page.
- Generated tracker/coverage and generated C++ files: do not edit.

## Implementation Tracking Checklist

- [x] Update `by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md` to `COMPLETION:90`, `CONFIDENCE:91`, same owner/reconstructable/emitter fields, and insert the exact formal C++ block from this report with era-appropriate `NULL` null checks/null assignments.
  - Proof: target header now has `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000HF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HF`, and formal `AlphaMaskSurface::InitAlphaSurfaceView(...)` code between `RECONSTRUCTION_CPP CODE:BEGIN/END` using `NULL`.
- [x] Update the target page's status/evidence/score rationale to state the resolved source shape: `AlphaMaskSurface::InitAlphaSurfaceView(IntAlphaSurface *view, const RectBounds *clipBounds) const`, with no direct callers retained as a confidence cap.
  - Proof: target `Status`, `Score Rationale`, `IDA MCP Evidence`, `Ownership Notes`, `Open Questions`, and `Changes` now record AlphaMaskSurface ownership, explicit destination `IntAlphaSurface *`, `off_6112EC` as construction/use-site, no-direct-caller confidence cap, and MCP session `b001_000241_20260627`.
- [x] Update `by-file/AlphaMaskSurface.md` at report-level detail for the resolved helper role and remove the [UID:0002NM]-specific source-split blocker while preserving broader family caveats.
  - Proof: file page now describes [UID:0002NM] as an AlphaMaskSurface helper, updates the proposed contents row, and keeps broader raw/default constructor, encoded-frame, and physical `IntAlphaSurface` colocation caveats.
- [x] Update `by-class/AlphaMaskSurface.md` to route the method inventory through [UID:0002NM] and record the `ECX` source object/out-parameter destination proof.
  - Proof: class method inventory now links [UID:0002NM] directly and evidence notes record `ECX` as source `AlphaMaskSurface`, `arg_0` as destination `IntAlphaSurface *`, and `arg_4` as optional `RectBounds *`.
- [x] Update `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md` so the aggregate no longer treats [UID:0002NM] as a final-source blocker.
  - Proof: aggregate item summary, function row, evidence notes, score rationale, and changes now state [UID:0002NM] has resolved AlphaMaskSurface ownership and formal C++; remaining caveats are broader raw/default constructor and encoded-frame/source-type issues.
- [x] Update `by-type/by-struct/AlphaMaskSurfaceLayout.md` so the layout caveat no longer names the no-xref view initializer as unresolved; preserve the raw constructor/header-name caveat.
  - Proof: layout evidence and naming notes now state [UID:0002NM] is resolved for layout/source-shape purposes, while raw default constructor and final header/type-name split remain caveats.
- [x] Update `by-file/IntAlphaSurface.md` to describe [UID:0002NM] as AlphaMaskSurface-owned construction/use-site evidence for an `IntAlphaSurface` destination, not as an `IntAlphaSurface` source-owned method.
  - Proof: file role/proposed contents/evidence/changes now label [UID:0002NM] as external use-site evidence and explicitly reject treating it as an `IntAlphaSurface` source-owned method.
- [x] Update `by-class/IntAlphaSurface.md` with the same external helper/destination-object distinction.
  - Proof: class purpose/vtable evidence/changes now describe [UID:0002NM] as AlphaMaskSurface-owned construction/use-site evidence and not a direct class method.
- [x] Update `by-type/by-vtable/IntAlphaSurfaceVtable.md` with the current [UID:0002NM] construction/use-site store distinction while keeping direct vtable ownership on `IntAlphaSurface`.
  - Proof: vtable evidence and changes now identify `0x00462415` as an AlphaMaskSurface-owned helper's destination construction/use-site store; canonical owner remains [UID:00006K].
- [x] Update `by-item/InitAlphaSurfaceView_004623C0.md` as a non-emitting index to the now-resolved canonical target.
  - Proof: index status/reconstruction notes/changes now point to [UID:0002NM]'s resolved source shape and keep `-1/-1`, `RECONSTRUCTABLE:FALSE`, and no emitter.
- [x] Do not edit `by-item/BuildClippedAlphaSurfaceView_00462320.md` or `by-type/by-struct/AlphaSurfaceBufferView.md` unless supervisor explicitly accepts a broader support cleanup.
  - Proof: neither file was edited during this implementation callback.
- [x] During implementation, lease only files ready for immediate editing and release leases immediately after edits.
  - Proof: B009 leased only the edited target/support by-* files. First lease batch expired during validation and the two still-active AlphaMaskSurface support leases were released with `python .\tools\leaser\leaser.py B009 unlease ...`; final lease report check showed no B009 rows.
- [x] Run scoped validators from `source-3/project-documentation` for each changed by-* file and record command id/timestamp, exit code, ok count, generated-refresh state, changed files, and lease release state in the implementation callback.
  - Proof:
    - `python .\tools\validator.py --mode file --file by-memory\0x004623c0-0x00462514.InitAlphaSurfaceView.md --apply --queue-timeout 240 --wait-generated` -> command `000000004897`, timestamp `2026-06-28T01:40:01-04:00`, exit `0`, `ok: 1`, generated refresh completed.
    - `python .\tools\validator.py --mode file --file by-memory\0x00462170-0x00462e03.AlphaMaskSurface.md --apply --queue-timeout 240` -> command `000000004898`, timestamp `2026-06-28T01:40:27-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-type\by-struct\AlphaMaskSurfaceLayout.md --apply --queue-timeout 240` -> command `000000004899`, timestamp `2026-06-28T01:40:29-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-file\IntAlphaSurface.md --apply --queue-timeout 240` -> command `000000004900`, timestamp `2026-06-28T01:40:30-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-class\IntAlphaSurface.md --apply --queue-timeout 240` -> command `000000004901`, timestamp `2026-06-28T01:40:32-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-type\by-vtable\IntAlphaSurfaceVtable.md --apply --queue-timeout 240` -> command `000000004902`, timestamp `2026-06-28T01:40:34-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-item\InitAlphaSurfaceView_004623C0.md --apply --queue-timeout 240` -> command `000000004903`, timestamp `2026-06-28T01:40:35-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-file\AlphaMaskSurface.md --apply --queue-timeout 240` -> command `000000004904`, timestamp `2026-06-28T01:40:37-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-class\AlphaMaskSurface.md --apply --queue-timeout 240` -> command `000000004905`, timestamp `2026-06-28T01:40:47-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - Generated output check: `auto-generated/NexusTK/render/AlphaMaskSurface.cpp` header shows `validator-command-id: 000000004905`, `validator-refreshed-at: 2026-06-28T01:40:47-04:00`, and includes [UID:0002NM] with the revised `NULL` formal C++. Queue-status command `000000004915` reported `queued generated refresh jobs: 0` and `processing generated refresh jobs: 0`.
- [x] Do not edit generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, the IDA DB, or MCP process state.
  - Proof: no generated/project/manual coverage/tool/IDA/MCP process files were manually edited. Validator-owned side effects occurred through scoped validator commands only: projected stats updates, research tracker/auto-coverage refresh on the target command, registry rebuild/update, and generated C++ refresh.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0002NM-InitAlphaSurfaceView-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0002NM-InitAlphaSurfaceView-source-quality.md","timestamp":"2026-06-28T02:50:23","uid":"0002NM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
