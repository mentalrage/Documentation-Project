** TARGET-REPORT-UID:00009X **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B015 source-quality report: [UID:00009X] OverlayFrameImageEffecter

## Assignment

- Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\OverlayFrameImageEffecter.md`
- Required report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\00009X-OverlayFrameImageEffecter-source-quality.md`
- Task type: B-agent heuristic/source-quality report only.
- Direct edits made by this report: none to by-* documentation or coverage reports.

## Decision summary

`OverlayFrameImageEffecter` is source-authored runtime effecter code under [UID:0000IZ] `Effects` / `render/Effects.cpp`. The current class page is right about ownership and broad behavior, but its field-offset narrative is stale because the render/update body at `0x0055a5e0` is installed in the embedded `+0x04` pane/GrafPort vtable view and therefore receives an adjusted `this` pointer. Normalizing that body to the complete object resolves the apparent palette/resource-field conflict:

| Complete-object offset | Best source-facing role | Evidence |
| --- | --- | --- |
| `+0x100` | `m_frameResourceName` / `m_imageName` | constructor copies first 16-wide-char argument here; adjusted render body passes `this+0xfc`, meaning complete `+0x100`, to `ResourceLayoutTable::LookupLayoutEntry`. |
| `+0x120` | `m_paletteName` | constructor copies second 16-wide-char argument here; adjusted render body passes `this+0x11c`, meaning complete `+0x120`, to `GrafPort::DrawTiledBackground`. |
| `+0x140` | `m_frameTable` / owned `ImageFrameTable` block | constructor stores `LoadImageFrameTable(...)`; ordinary and scalar destructors pass this exact complete-object field to `DestroyOwnedImageBlock`. |
| `+0x144` | `m_frameDrawRecord` / `EPFTileContext`-compatible draw record | constructor initializes it through `InitTileContext`; adjusted render body passes `this+0x140`, meaning complete `+0x144`, as lookup output and tiled-background source record. |
| `+0x16c` | `m_frameIndex` / current frame index | constructor stores the final word argument here; adjusted render body reads `word [this+0x168]`, meaning complete `+0x16c`. |
| `+0xf9` | overlay active/visible byte | constructor writes `1`, matching sibling overlay effecters. |

Recommended metadata for the class page: raise from `84/88` to `88/91`. Keep `CANONICAL_OWNER:0000IZ`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000IZ`.

Recommended C++ policy: source-level method C++ is now first-draft ready for exact method children, but the by-class page should not emit all four method bodies directly. The class target is a non-contiguous class aggregate whose bodies currently live inside the broad `ScreenEffecterRuntimeCluster`, and the scalar deleting destructor is compiler-generated. Preferred implementation is to create exact by-memory children for:

- `0x0055a5e0-0x0055a61b` render/update body.
- `0x0055a620-0x0055a6ea` constructor.
- `0x0055a6f0-0x0055a797` ordinary destructor.
- `0x0055bc90-0x0055bd63` scalar deleting destructor wrapper, no formal source C++.

Until those exact children exist, the class page should carry the field/source-shape evidence and either leave formal C++ blank or use only a comment marker if the supervisor wants to clear no-code trackers. Do not emit the scalar deleting destructor as handwritten source.

## Evidence checked

Instruction and policy files:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B015/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`

Primary and support docs:

- Target: `by-class/OverlayFrameImageEffecter.md`
- Siblings/base: `OverlayEffecter`, `OverlayImageEffecter`, `OverlayImageOnPointEffecter`, `OverlayMovingImageEffecter`, `ScreenEffecter`, `PixelEffecter`
- File/aggregate/vtable: `by-file/Effects.md`, `0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`, `ScreenEffecterVtableFamily.md`
- Resource/render helpers: `ImageFrameTable.md`, `LoadImageFrameTable`, `DestroyOwnedImageBlock`, `ResourceLayoutTableLookupLayoutEntry`, `EPFTileContext`, `g_pEPFLib`, `GrafPort`, `GrafPort::DrawTiledBackground`, `SurfaceRenderCallbackTable`, `g_pPaletteLib`
- Coverage rows: `by-class/-coverage-report.md`, `by-memory/-coverage-report.md`, `auto-generated/-ag-class-coverage.md`, `project-level/-auto-completion-stats.md`

Current-session tool evidence:

- IDA MCP endpoint `127.0.0.1:13337` timed out / was unreachable in this session. I did not claim new live IDA state.
- Raw PE checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Hashes:
  - MD5 `4247E04E20B65D6414C7238AA8FF5515`
  - SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
- Local raw PE/capstone audit verified exact disassembly, immediate references, padding, vtable data, and direct rel32/pointer scans.
- `int_convert.py` verified sizes:
  - `0x3b` / 59 bytes for render/update body.
  - `0xca` / 202 bytes for constructor.
  - `0xa7` / 167 bytes for ordinary destructor.
  - `0xd3` / 211 bytes for scalar deleting destructor.
  - `0x16c` / 364, `0x168` / 360, `0x140` / 320, `0x120` / 288, `0x100` / 256, `0xfc` / 252, `0xf9` / 249, `0x44` / 68, `0x70` / 112, `0x90` / 144, `0x28` / 40.

## Raw range findings

### `0x0055a5e0-0x0055a61b` render/update body

Exact size is `0x3b` / 59 bytes. The body:

- Saves `esi`/`edi`.
- Treats incoming `ecx` as the embedded pane/GrafPort subobject pointer, not the complete object pointer.
- Calls `ResourceLayoutTable::LookupLayoutEntry` at `0x004d02f0` with:
  - receiver `g_pEPFLib` / `0x0067a744`,
  - resource name at adjusted `this+0xfc` = complete `+0x100`,
  - frame index `word [adjusted this+0x168]` = complete `+0x16c`,
  - output draw record at adjusted `this+0x140` = complete `+0x144`.
- Calls [UID:00016A] `GrafPort::DrawTiledBackground` at `0x004ba6b0` with:
  - receiver still adjusted pane/GrafPort subobject,
  - clip/visible bounds at adjusted `this+0x44`,
  - frame draw record at adjusted `this+0x140`,
  - palette name at adjusted `this+0x11c` = complete `+0x120`.

The vtable slot evidence is decisive: `0x006237a8` points to `0x0055a5e0` inside the `+0x04` view table that starts at `0x00623764`. This is why a complete-object offset reading was producing stale `this+0x11c`/`this+0x140` confusion.

Recommended source-facing name: `RenderOverlayFrame` for documentation and IDA if a descriptive name is needed. `OnPaint` / `Draw` remains possible original spelling because it is a pane/GrafPort draw virtual. Avoid `UpdateFrameAndRender` as the primary source-facing name unless keeping historical compatibility, because the body only resolves the already-stored frame index and renders it; it does not advance the index.

### `0x0055a620-0x0055a6ea` constructor

Exact size is `0xca` / 202 bytes. The body:

- Emits SEH/security-cookie setup.
- Calls `OverlayEffecter` at `0x0055a2e0` with fixed first argument `1` and the two coordinate/placement word arguments from stack offsets `+0x10` and `+0x14`.
- Installs four `OverlayFrameImageEffecter` vtable views:
  - primary `0x00623740`
  - embedded pane/GrafPort view `0x00623764`
  - secondary view `0x006237b0`
  - secondary view `0x006237e0`
- Calls `InitTileContext` / `sub_457A60` on complete `this+0x144`.
- Calls `LoadImageFrameTable(g_pEPFLib, frameResourceName, 0)` and stores the returned owned block at complete `this+0x140`.
- Copies two 16-wide-character strings through secure wide-copy helper `0x005cd657`:
  - first stack argument to complete `this+0x100`;
  - second stack argument to complete `this+0x120`.
- Stores the final word argument at complete `this+0x16c`.
- Writes byte `1` to complete `this+0xf9`.
- Returns with `ret 0x14`, proving five explicit stack arguments.

Best source-facing signature:

```cpp
OverlayFrameImageEffecter::OverlayFrameImageEffecter(
    const wchar_t *frameResourceName,
    const wchar_t *paletteName,
    int overlayX,
    int overlayY,
    int frameIndex);
```

`overlayX`/`overlayY` are high-probability names only. They route to `OverlayEffecter`, which stores them at complete offsets `+0xfc/+0xfe` and registers the pane against active map bounds. If the broader Effects pass chooses `originX/originY`, only the parameter spelling should change.

### `0x0055a6f0-0x0055a797` ordinary destructor

Exact size is `0xa7` / 167 bytes. The body:

- Emits SEH/security-cookie setup.
- Reinstalls the four `OverlayFrameImageEffecter` vtable views during the derived-destructor phase.
- Calls `DestroyOwnedImageBlock` at `0x004d15d0` on complete `this+0x140`.
- Reinstalls the four `OverlayEffecter` base vtable views:
  - `0x006235e8`
  - `0x0062360c`
  - `0x00623658`
  - `0x00623688`
- Calls pane teardown helpers `0x00544ce0` and `0x00544580` on complete `this+0x04`.
- Resets the primary base to `ScreenEffecter` vtable `0x006235a4`.

Source-facing body should be ordinary `OverlayFrameImageEffecter::~OverlayFrameImageEffecter()` releasing the owned frame table and relying on base destructors for pane/base teardown. Vtable restores and SEH cleanup are compiler-generated.

### `0x0055bc90-0x0055bd63` scalar deleting destructor

Exact size is `0xd3` / 211 bytes. This is compiler-generated scalar/vector-delete wrapper code. It repeats the derived/base teardown and then:

- returns `this`;
- when `(flags & 1) == 0`, performs no storage delete;
- when `(flags & 1) != 0 && (flags & 4) == 0`, calls project delete helper `0x004f4ac0`;
- when `(flags & 4) != 0`, calls `0x0041b6a0(this, 0x170)` for the guarded sized/vector-delete path.

The wrapper is reached from destructor jump strip `0x0055ba22` via direct branches at `0x0055ba61`, `0x0055ba6c`, and `0x0055ba77`, and from primary vtable slot `0x00623758`. Do not emit this as handwritten C++.

## Vtable findings

Raw `.rdata` dump around `0x0062373c-0x00623800` confirms:

- RTTI/COL pointer at `0x0062373c`.
- Primary table `0x00623740`.
- Scalar deleting destructor slot `0x00623758 -> 0x0055bc90`.
- Embedded pane/GrafPort view table `0x00623764`.
- Render/update slot `0x006237a8 -> 0x0055a5e0`.
- Secondary table `0x006237b0`.
- Secondary table `0x006237e0`.
- Next sibling `OverlayImageOnPointEffecter` starts at `0x006237ec`.

Raw pointer scans:

- `0x0055a5e0` has one VA pointer hit, at the vtable cell corresponding to `0x006237a8`.
- `0x0055bc90` has one VA pointer hit, at the vtable cell corresponding to `0x00623758`.
- Constructor `0x0055a620` and ordinary destructor `0x0055a6f0` have zero VA/RVA/raw-offset pointer hits.

Raw rel32 branch scan:

- No direct rel32 calls/jumps to `0x0055a5e0`, `0x0055a620`, or `0x0055a6f0`.
- Three direct branch hits to `0x0055bc90` from the destructor jump strip: `0x0055ba61`, `0x0055ba6c`, `0x0055ba77`.

This means constructor and ordinary destructor reachability is still not statically proven by direct call/pointer refs in the current executable scan. That should cap final audit but not block class ownership or first-draft source shape because constructor/destructor bytes, sibling patterns, and vtable installation are strong.

## Helper and global names

Recommended source-facing names/roles:

- `sub_4D02F0`: `ResourceLayoutTable::LookupLayoutEntry`.
- `sub_4D0F50`: `LoadImageFrameTable`.
- `sub_4D15D0`: `DestroyOwnedImageBlock`; alternate final noun `DestroyFrameImageBlock` remains possible but current ImageFrameTable docs favor `DestroyOwnedImageBlock`.
- `sub_457A60`: `EPFTileContext::InitTileContext` / `InitTileContext`.
- `sub_4BA6B0`: `GrafPort::DrawTiledBackground`.
- `sub_5CD657`: secure 16-wide-character copy helper; use source-level `wcsncpy_s` / `CopyWideString16` wording rather than raw function name.
- `g_pEPFLib`: current IDA/global canonical name for the ImageLib/ResourceLayout singleton at `0x0067a744`.
- `g_pPaletteLib`: palette singleton used indirectly by `GrafPort::DrawTiledBackground`.

Rejected raw/generated names:

- `sub_55A5E0`, `sub_55A620`, `sub_55A6F0`, `sub_55BC90` should not remain as passive blockers. Use class-method descriptive names and note scalar wrapper generation.
- Helper provenance names from fitting-room/download panes are caller-biased render-helper pollution and do not change ownership.
- `this+0x11c` and `this+0x140` in the render body must not be copied into complete-object field docs without the `+0x04` receiver adjustment.

## First-draft source shape

Preferred C++ draft for exact future method children:

```cpp
OverlayFrameImageEffecter::OverlayFrameImageEffecter(
    const wchar_t *frameResourceName,
    const wchar_t *paletteName,
    int overlayX,
    int overlayY,
    int frameIndex)
    : OverlayEffecter(1, overlayX, overlayY),
      m_frameTable(nullptr),
      m_frameIndex(static_cast<int16_t>(frameIndex))
{
    InitTileContext(&m_frameDrawRecord);
    m_frameTable = LoadImageFrameTable(frameResourceName, 0);
    wcsncpy_s(m_frameResourceName, 16, frameResourceName, _TRUNCATE);
    wcsncpy_s(m_paletteName, 16, paletteName, _TRUNCATE);
    m_active = true;
}

void OverlayFrameImageEffecter::RenderOverlayFrame()
{
    g_pEPFLib->LookupLayoutEntry(m_frameResourceName,
                                 m_frameIndex,
                                 &m_frameDrawRecord);
    DrawTiledBackground(&m_visibleBounds, &m_frameDrawRecord, m_paletteName);
}

OverlayFrameImageEffecter::~OverlayFrameImageEffecter()
{
    DestroyOwnedImageBlock(m_frameTable);
}
```

Notes on the draft:

- `RenderOverlayFrame` may become `OnPaint`/`Draw` after a broader pane-vtable naming pass.
- `m_active`, `m_visibleBounds`, and exact `OverlayEffecter` constructor parameter names remain high-confidence descriptive names, not recovered source symbols.
- The render body is compiled for the embedded pane/GrafPort view. A source-level member draft should use complete-object field names, not the adjusted offsets.
- The scalar deleting destructor should be recorded as compiler-generated and no-code.

## Recommended target doc changes

For `by-class/OverlayFrameImageEffecter.md`:

1. Raise metadata to `COMPLETION:88`, `CONFIDENCE:91`; keep owner/emitter [UID:0000IZ] `Effects`.
2. Replace stale below-95/no-code wording with the current policy:
   - The class clears the active `85/85` gate.
   - Source bodies are first-draft ready after exact child splits.
   - The class page should not emit all method bodies directly because the method ranges are non-contiguous inside `ScreenEffecterRuntimeCluster`, and the scalar deleting destructor is compiler-generated.
3. Update method table:
   - `0x0055a5e0-0x0055a61b`: `RenderOverlayFrame` / pane draw virtual; adjusted receiver; calls `ResourceLayoutTable::LookupLayoutEntry` then `GrafPort::DrawTiledBackground`.
   - `0x0055a620-0x0055a6ea`: constructor; five explicit args; copies 16-wide-char resource/palette names; initializes frame draw record; loads owned frame table; stores frame index; sets active byte.
   - `0x0055a6f0-0x0055a797`: ordinary destructor; destroys owned frame table; base/pane teardown is compiler/base codegen.
   - `0x0055bc90-0x0055bd63`: scalar deleting destructor; compiler-generated wrapper, no formal C++.
4. Add a field-offset table using complete-object offsets and explicitly mention the adjusted-render-body offset normalization.
5. Preserve no direct constructor/non-scalar-destructor caller caveat from raw PE scan.
6. Add rejected alternatives:
   - no fitting-room/download ownership;
   - no direct `Surface` ownership for the frame-effect class;
   - no separate `OverlayFrameImageEffecter.cpp` split in this pass;
   - no handwritten SEH/security-cookie/vtable/scalar-delete C++.

## Recommended support-doc changes

For `by-file/Effects.md`:

Add or update the `OverlayFrameImageEffecter` proposed-content note:

> B015 reanalysis resolves the adjusted pane/GrafPort render receiver for `OverlayFrameImageEffecter`: the render slot at `0x006237a8` uses adjusted offsets that normalize to complete-object `m_frameResourceName` at `+0x100`, `m_paletteName` at `+0x120`, `m_frameTable` at `+0x140`, frame draw record at `+0x144`, and current frame index at `+0x16c`. Constructor/destructor/update bodies are source-authored Effects code; scalar deleting destructor remains compiler-generated. Preferred C++ emission is through exact method children after split, not through the broad class page.

For `0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`:

Add a B015 overlay-frame bullet:

> B015 source-quality pass corrects `OverlayFrameImageEffecter` field mapping by accounting for the `+0x04` pane/GrafPort view receiver. `0x0055a5e0` resolves the complete-object frame resource name at `+0x100`, frame index at `+0x16c`, frame draw record at `+0x144`, and palette name at `+0x120`, then calls `ResourceLayoutTable::LookupLayoutEntry` and `GrafPort::DrawTiledBackground`. Constructor `0x0055a620-0x0055a6ea` stores the owned `LoadImageFrameTable` block at complete `+0x140`; destructor `0x0055a6f0-0x0055a797` and scalar wrapper `0x0055bc90-0x0055bd63` release that same field through `DestroyOwnedImageBlock`.

For `ScreenEffecterVtableFamily.md`:

Add to the `OverlayFrameImageEffecter` row/notes:

> The render slot `0x006237a8 -> 0x0055a5e0` is in the embedded `+0x04` pane/GrafPort view, so the body receives an adjusted receiver. The scalar deleting destructor slot `0x00623758 -> 0x0055bc90` is the primary-view compiler wrapper.

For `ImageFrameTable.md` or `DestroyOwnedImageBlock.md`:

Add a consumer clarification:

> `OverlayFrameImageEffecter` constructor stores the `LoadImageFrameTable` result at complete-object `+0x140`; B015 confirms the render output record starts at complete `+0x144` after accounting for the pane-view receiver adjustment. Destructor/scalar destructor free only the owned `+0x140` table block.

For sibling overlay class pages:

Low-risk sibling consistency note only if editing those pages later:

> Overlay render bodies installed in `+0x04` view tables may use adjusted receiver offsets. Normalize to complete-object offsets before naming resource/palette/frame fields.

## Coverage row text

Do not edit `by-memory/-coverage-report.md` directly. Pending supervisor-owned text:

For `by-class/-coverage-report.md`, replace the current stale row with:

```text
- [UID:00009X][OverlayFrameImageEffecter](by-class/OverlayFrameImageEffecter.md) : reconstructable : 88% : very strong : Frame-indexed overlay image effecter attached to [UID:0000IZ][Effects](by-file/Effects.md); B015 source-quality pass resolves constructor/destructor/update/scalar ranges, four-view vtables, adjusted `+0x04` pane/GrafPort render receiver, complete-object resource fields `+0x100/+0x120`, owned frame table `+0x140`, draw record `+0x144`, frame index `+0x16c`, `g_pEPFLib` lookup and `GrafPort::DrawTiledBackground` route, no direct constructor/non-scalar-destructor caller proof, source-child C++ readiness, and compiler-generated scalar-deleting destructor policy.
```

For `by-memory/-coverage-report.md`, if the supervisor chooses to refresh the broad aggregate row after this report, use:

```text
    - [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) 0x0055a260-0x0055c1ff | class/helper cluster | ScreenEffecterRuntimeCluster : reconstructable : 86% : strong : Attached runtime effecter aggregate with live IDA-confirmed overlay-image subclass endpoints, vtable stores, render helper data flow, resource load/free ownership, raw constructor islands, boundary padding, and B015's corrected OverlayFrameImageEffecter adjusted-receiver mapping for resource name, palette name, frame table, frame draw record, and frame index fields.
```

If no aggregate refresh is desired, no by-memory coverage row change is required for the class-only implementation.

## IDA rename/type/comment recommendations

Function names:

- `sub_55A5E0 -> OverlayFrameImageEffecter_RenderOverlayFrame` or `OverlayFrameImageEffecter_OnPaint` with a comment that `ecx` is adjusted to the embedded `+0x04` pane/GrafPort view.
- `sub_55A620 -> OverlayFrameImageEffecter_ctor`.
- `sub_55A6F0 -> OverlayFrameImageEffecter_dtor`.
- `sub_55BC90 -> OverlayFrameImageEffecter_scalar_deleting_destructor` and mark compiler-generated.

Vtable/data labels:

- `0x00623740 -> OverlayFrameImageEffecter_vftable_primary`.
- `0x00623764 -> OverlayFrameImageEffecter_vftable_paneView`.
- `0x006237b0 -> OverlayFrameImageEffecter_vftable_viewA`.
- `0x006237e0 -> OverlayFrameImageEffecter_vftable_viewB`.
- Comment `0x006237a8`: `pane-view render slot; adjusted this`.
- Comment `0x00623758`: `scalar deleting destructor wrapper`.

Structure fields:

- complete `+0x100`: `m_frameResourceName` / `m_imageName`.
- complete `+0x120`: `m_paletteName`.
- complete `+0x140`: `m_frameTable`.
- complete `+0x144`: `m_frameDrawRecord` / `m_frameTileContext`.
- complete `+0x16c`: `m_frameIndex`.
- complete `+0xf9`: `m_active` / `m_visible`.

Helper names:

- Preserve existing support names `ResourceLayoutTable::LookupLayoutEntry`, `LoadImageFrameTable`, `DestroyOwnedImageBlock`, `InitTileContext`, and `GrafPort::DrawTiledBackground`.

## Open questions and attempted resolution

- Final original render method name: unresolved. Evidence supports a pane draw virtual; best descriptive name is `RenderOverlayFrame`, with `OnPaint`/`Draw` possible in final source.
- Final constructor parameter names: unresolved. `frameResourceName`, `paletteName`, `overlayX`, `overlayY`, and `frameIndex` are best-supported descriptive names from constructor uses and `OverlayEffecter` base flow.
- Direct constructor/non-scalar-destructor reachability: unresolved after raw PE scans found zero direct rel32 calls/jumps and zero VA/RVA/raw-offset pointer hits to `0x0055a620` and `0x0055a6f0`. Do not invent callers.
- Exact source split: `render/Effects.cpp` remains the best current owner. A later `render/effects/OverlayEffecters.cpp` split is possible but unsupported by current docs; do not route to a standalone `OverlayFrameImageEffecter.cpp` now.
- Exact final type spelling for frame draw record: `FrameDrawRecord` is supported by `GrafPort::DrawTiledBackground` and `LoadFrameDrawRecord` docs; `EPFTileContext`-compatible scratch/draw record wording should remain until a whole ImageFrameTable/GrafPort type pass finalizes the declaration.

## Validator needs

Report-only phase: no validators required because no by-* docs were edited.

If accepted for implementation, run scoped validators from `source-3/project-documentation` on every edited doc, for example:

> Executable block R001 was removed from this report and preserved verbatim in [00009X-OverlayFrameImageEffecter-source-quality-removed.md](00009X-OverlayFrameImageEffecter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Implementation readiness

Ready for supervisor implementation review. The target should receive a source-quality field/source-shape update and score increase now. Formal method C++ should be emitted only after exact method child pages are created, except for the scalar deleting destructor, which should stay no-code/compiler-generated.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00009X-OverlayFrameImageEffecter-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00009X"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00009X-OverlayFrameImageEffecter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00009X-OverlayFrameImageEffecter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00009X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
