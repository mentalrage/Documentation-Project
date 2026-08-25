** TARGET-REPORT-UID:00009Y **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00009Y OverlayImageEffecter source-quality report

Agent: B004
Assignment: B004-goal2-overlay-image-effecter-source-quality-00009Y-20260619
Target: `source-3/project-documentation/by-class/OverlayImageEffecter.md`
Report-only status: by-* docs were not edited. `by-memory/-coverage-report.md` was not edited.

## Recommendation

`OverlayImageEffecter` should stay reconstructable under [UID:0000IZ] `Effects` with emitter route to `NexusTK/render/Effects.cpp`. The stale below-95/95 no-code rationale should be removed. Current evidence supports the active 85/85 first-draft gate:

- Target recommendation: `COMPLETION:88`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:0000IZ`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000IZ`.
- Add first-draft C++ for the source constructor and render/apply method.
- Do not emit source C++ for the scalar deleting destructor or vtable views; those are compiler artifacts.

The score should not be raised to final-source territory yet because the direct construction route for `0x0055a4a0` was not found by local xref scans, final source spelling for the copied names and render helper remains heuristic, and the constructor's last two arguments are best interpreted through the base overlay effecter rather than source-symbol evidence. Those are below-95 caveats, not first-draft blockers.

## Evidence checked

Documentation checked:

- `by-class/OverlayImageEffecter.md`
- `by-class/OverlayEffecter.md`
- `by-class/OverlayFrameImageEffecter.md`
- `by-class/OverlayImageOnPointEffecter.md`
- `by-class/OverlayMovingImageEffecter.md`
- `by-class/ScreenEffecter.md`
- `by-file/Effects.md`
- `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`
- `by-type/by-vtable/ScreenEffecterVtableFamily.md`
- `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`
- `by-memory/0x00623480-0x00623d58.ScreenEffecterReadOnlyData.md`
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`
- `by-global/SurfaceRenderCallbackTable.md`
- `by-global/g_activeMapPane.md`
- `by-global/g_pEPFLib.md`
- `by-class/EPFTileContext.md`
- `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
- `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`

Local generated/decompiler evidence checked:

- `source-3/simroot_v2/class_OverlayImageEffecter.cpp`
- `source-3/simroot_v2/class_OverlayEffecter.cpp`
- `source-3/simroot_v2/class_ScreenEffecter.cpp`

Binary evidence checked:

- Local PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- PE identity: size `2679296`, MD5 `4247e04e20b65d6414c7238aa8ff5515`
- Image base `0x00400000`
- Relevant sections: `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, `.data 0x0066d000-0x0069ce24`
- Manual PE mapping plus Capstone 5.0.7 disassembly/xref scans.

IDA MCP status:

- Attempted MCP HTTP connection to `127.0.0.1:13337/mcp`.
- Result: unavailable / unable to connect.
- Local PE disassembly and documentation cross-checks were used instead.

## Exact ranges and split findings

Recommended exact method ranges:

- `0x0055a440-0x0055a499`: `OverlayImageEffecter::ApplyOverlayImage` / render-applying virtual body.
- `0x0055a499-0x0055a4a0`: `int3` padding before constructor.
- `0x0055a4a0-0x0055a55e`: `OverlayImageEffecter` complete-object constructor.
- `0x0055a55e-0x0055a560`: padding before the next sibling destructor.
- `0x0055bd70-0x0055be0d`: scalar deleting destructor.
- `0x0055be0d-0x0055be10`: padding after scalar deleting destructor.

Additional range that should be documented in the runtime cluster/support notes:

- `0x0055a3d0-0x0055a43e`: `OverlayImageEffecter` destructor-shaped EH cleanup / non-deleting cleanup body.

`0x0055a3d0` resets the OverlayEffecter base vtables, calls the embedded pane cleanup/destructor helpers at `0x00544ce0` and `0x00544580` on `this+4`, resets the ScreenEffecter primary base vtable, and returns. Local scans found references from table/EH-like data around the `0x0060759c`, `0x006075da`, `0x00607618`, and `0x00607656` region rather than normal direct call sites or vtable slots. Treat it as compiler/EH cleanup evidence, not a separate source method requiring formal C++.

No split child rows are required for the current class page. If the supervisor later chooses function-level children, the natural children are the apply method, constructor, scalar deleting destructor, and the EH cleanup body above. The current class page can carry the first-draft source because the source-owned constructor and apply body are small, contiguous, and well understood.

## Apply/render method evidence

`0x0055a440-0x0055a499` behavior:

- Uses a stack cookie prologue/epilogue.
- Loads `g_activeMapPane` from `0x0067a764`.
- Calls `0x004b8e00` with `ecx = g_activeMapPane` and an out `RectBounds` local.
- Calls `0x004b9980` with `ecx = g_activeMapPane`.
- Passes the local viewport bounds, an image/context pointer, a source bounds pointer, mode `1`, a copied name pointer, and flags `0`.
- Returns with live `EAX`, but there is no source-level return value consumed by the virtual route. The source method should be documented as `void`.

Critical adjusted-this finding:

- The method is installed in the `+0x04` vtable view at `0x006236fc`.
- That view receives `ecx = complete object + 4`.
- Therefore the offsets used by the method are adjusted-view offsets, not complete-object offsets.

Adjusted-to-complete offset mapping:

- Apply `this+0x11c` == complete object `+0x120`: second copied name, best source name `m_paletteName` / `m_overlayPaletteName`.
- Apply `this+0x140` == complete object `+0x144`: embedded `EPFTileContext`, best source name `m_tileContext`.
- Apply `this+0x150` == complete object `+0x154`: `m_tileContext.bounds`.

This resolves the previous apparent mismatch between the constructor, which initializes complete offsets `+0x100`, `+0x120`, and `+0x144`, and the render method, which uses adjusted-view offsets `+0x11c`, `+0x140`, and `+0x150`.

Recommended source-facing method name:

- Keep `ApplyOverlayImage` unless the supervisor chooses a later family-wide rename.
- Acceptable prose alias: render/apply virtual body.
- Do not call it a FittingRoomDownloadControlPane method. That name came from caller-biased/generated helper provenance.

## Constructor evidence

`0x0055a4a0-0x0055a55e` behavior:

- Calls `0x0055a2e0` (`OverlayEffecter` constructor) with constant `1` and the constructor's last two word-sized arguments.
- Installs four `OverlayImageEffecter` vtable views:
  - complete `+0x00` -> `0x00623694`
  - adjusted view `+0x04` -> `0x006236b8`
  - adjusted view `+0xa4` -> `0x00623704`
  - adjusted view `+0xa8` -> `0x00623734`
- Calls `0x00457a60` with `ecx = complete + 0x144`, initializing an embedded `EPFTileContext`.
- Copies first pointer argument to complete `+0x100` with size/immediate `0x10` through `0x005cd657`.
- Copies second pointer argument to complete `+0x120` with size/immediate `0x10` through `0x005cd657`.
- Loads `g_pEPFLib` from `0x0067a744`.
- Calls `0x004d02f0` (`ResourceLayoutTable::LookupLayoutEntry`) with name `complete+0x100`, frame/index `0`, and output `complete+0x144`.
- Sets byte `complete+0xf9` to `1`.
- Returns `this` and uses `ret 0x10`, confirming four stack arguments.

Best source-facing constructor shape:

```cpp
OverlayImageEffecter::OverlayImageEffecter(const wchar_t *imageName,
                                           const wchar_t *paletteName,
                                           unsigned short overlayX,
                                           unsigned short overlayY)
    : OverlayEffecter(1, overlayX, overlayY)
```

Parameter caveats:

- `imageName` is high-confidence because it is copied to `+0x100` and then used as the `ResourceLayoutTable::LookupLayoutEntry` name.
- `paletteName` / `overlayPaletteName` is high-probability because it is copied to `+0x120` and later passed as the name argument to the shared render helper.
- `overlayX` / `overlayY` are descriptive. The base constructor stores these inherited overlay words at complete `+0xfc/+0xfe`, but final source names could be variant/index/placement names.
- `wchar_t` is high-probability because the surrounding resource-layout and string-copy ecosystem uses UTF-16/wide names. The exact CRT/helper identity of `0x005cd657` is not symbol-proven locally; document it as bounded wide copy / likely `wcscpy_s`, not as a hard import name if the docs avoid CRT naming.

## Destructor and vtable evidence

`0x0055bd70-0x0055be0d` is a scalar deleting destructor:

- Resets the four OverlayEffecter base vtable views:
  - `0x006235e8`
  - `0x0062360c`
  - `0x00623658`
  - `0x00623688`
- Calls the embedded pane cleanup/destructor helpers `0x00544ce0` and `0x00544580` on `this+4`.
- Resets the ScreenEffecter primary base vtable to `0x006235a4`.
- Checks scalar-delete flags and calls either `0x004f4ac0` or `0x0041b6a0(this, 0x16c)` depending on delete-mode bits.
- Confirms complete object size `0x16c` on the deleting path.

Adjusted scalar deleting destructor thunks:

- `0x0055ba7c-0x0055ba84`: subtracts `4`, jumps to `0x0055bd70`.
- `0x0055ba84-0x0055ba8f`: subtracts `0xa4`, jumps to `0x0055bd70`.
- `0x0055ba8f-0x0055ba9a`: subtracts `0xa8`, jumps to `0x0055bd70`.

Vtable views:

- Primary view `0x00623694-0x006236b4`.
- `+0x04` view `0x006236b8-0x00623700`.
- `+0xa4` view `0x00623704-0x00623730`.
- `+0xa8` view `0x00623734-0x0062373c`.

`ApplyOverlayImage` appears as a vtable-only entry at `0x006236fc`. Constructor vtable store refs are at `0x0055a4e7`, `0x0055a4ed`, `0x0055a4f4`, and `0x0055a4fe`. The constructor has no direct call or data reference found by local rel32/absolute/RVA scans.

Source recommendation:

- Emit source for constructor and apply/render method.
- Do not emit source for scalar deleting destructor, adjusted thunks, or vtable data.
- Mention that the destructor relationship is compiler-generated and reset-heavy because of multiple inheritance / adjusted views.

## Field and helper recommendations

Best field layout names for `OverlayImageEffecter`:

- complete `+0x100`: `m_imageName[16]`, likely `wchar_t`.
- complete `+0x120`: `m_paletteName[16]` or `m_overlayPaletteName[16]`, likely `wchar_t`.
- complete `+0x144`: `m_tileContext`, type `EPFTileContext`.
- complete `+0x154`: `m_tileContext.bounds` / `m_tileContext.m_bounds`.
- complete `+0xf9`: inherited active/visible byte, best source name `m_isVisible` until the base field is named.
- complete `+0xfc/+0xfe`: inherited OverlayEffecter word parameters set by `OverlayEffecter(1, overlayX, overlayY)`.

Helper/global names:

- `0x0067a764`: `g_activeMapPane`.
- `0x0067a744`: `g_pEPFLib`.
- `0x004b8e00`: Map/BackPane/GrafPort bounds getter used to produce the viewport `RectBounds`.
- `0x004b9980`: shared Surface/GrafPort tile-frame render helper. Existing docs prefer `RenderTileFrame`; keep that spelling unless a later canonical helper rename is accepted.
- `0x004d02f0`: `ResourceLayoutTable::LookupLayoutEntry`.
- `0x00457a60`: `EPFTileContext::Init`.
- `0x005cd657`: bounded wide-string copy helper / likely CRT `wcscpy_s`; final helper name remains below-95.

Reject `FittingRoomDownloadControlPane::ApplyOverlayByName` as a source owner/name for `0x004b9980`. `0x004b9980` has 311 local call references, is documented in the Surface/GrafPort paint helpers, and dispatches through the shared Surface render callback table slot `dword_69B3E8`. Fitting-room/download names in generated output are caller-biased helper provenance, not class ownership for `OverlayImageEffecter`.

## Owner, emitter, and source placement ranking

1. `Effects` / `NexusTK/render/Effects.cpp` is the best owner/emitter. The target belongs to the runtime ScreenEffecter family, shares source placement with `OverlayEffecter` and sibling overlay effecters, and has vtable/source-family evidence under the Effects file parent.
2. `OverlayEffecter` is the direct semantic base and should be used as support context, but not as the canonical source owner for the subclass.
3. `ScreenEffecterRuntimeCluster`, `ScreenEffecterVtableFamily`, and vtable/read-only-data memory pages are aggregate/type support docs. They should document evidence but not replace the source owner.
4. Fitting-room/download-pane ownership should be rejected. The only path to that interpretation is through stale helper naming around `0x004b9980`; current helper/global docs show it is a shared Surface/GrafPort render path.
5. A no-owner/non-emitting placement is not warranted. The constructor and apply method are source-authored and the parent `Effects` route clears the current 85/85 threshold.
6. Split child rows are optional future cleanup, not required to make the class source-ready.

## First-draft C++ recommendation

Recommended first-draft C++ for the target page:

```cpp
OverlayImageEffecter::OverlayImageEffecter(const wchar_t *imageName,
                                           const wchar_t *paletteName,
                                           unsigned short overlayX,
                                           unsigned short overlayY)
    : OverlayEffecter(1, overlayX, overlayY)
{
    m_tileContext.Init();
    wcscpy_s(m_imageName, 16, imageName);
    wcscpy_s(m_paletteName, 16, paletteName);

    g_pEPFLib->LookupLayoutEntry(m_imageName, 0, &m_tileContext);
    m_isVisible = true;
}

void OverlayImageEffecter::ApplyOverlayImage()
{
    RectBounds viewportBounds;
    g_activeMapPane->GetBounds(&viewportBounds);

    g_activeMapPane->RenderTileFrame(&m_tileContext,
                                     &m_tileContext.bounds,
                                     &viewportBounds,
                                     1,
                                     m_paletteName,
                                     0);
}
```

Adapt spelling during implementation if support docs already prefer another canonical name:

- `m_overlayPaletteName` may be better than `m_paletteName` if the overlay family uses that wording.
- `RenderTileFrame(g_activeMapPane, ...)` may be used instead of member-call syntax if helper docs keep it as a free helper.
- `LookupLayoutEntry` may be spelled with the existing `ResourceLayoutTable` helper style.
- `m_isVisible` should be replaced by the base-field canonical name if one is established before implementation.

No target-specific no-code proof remains. The only no-code proof applies to compiler-generated scalar destructor, adjusted thunks, and vtable data.

## Recommended target doc changes

For `by-class/OverlayImageEffecter.md`:

- Change metadata to `COMPLETION:88`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:0000IZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IZ`.
- Replace the stale below-95/95 final-source gate with the current combined-score gate:
  - target is reconstructable at 88/91;
  - parent `Effects` is an 85+ emitter route;
  - first-draft C++ is now eligible;
  - unresolved naming/call-route caveats keep it below final-source confidence, not below draft readiness.
- Add exact ranges and padding:
  - `0x0055a440-0x0055a499` apply/render method;
  - `0x0055a4a0-0x0055a55e` constructor;
  - `0x0055bd70-0x0055be0d` scalar deleting destructor;
  - predecessor/successor padding where useful.
- Add `0x0055a3d0-0x0055a43e` as EH cleanup/non-deleting-destructor-shaped evidence.
- Add adjusted-this explanation for the `+0x04` vtable view so `this+0x11c/+0x140/+0x150` map to complete `+0x120/+0x144/+0x154`.
- Add constructor details:
  - base call `OverlayEffecter(1, overlayX, overlayY)`;
  - four vtable installs;
  - `EPFTileContext::Init`;
  - bounded wide copies to `m_imageName` and `m_paletteName`;
  - `g_pEPFLib->LookupLayoutEntry`;
  - active/visible byte set.
- Add apply/render details:
  - `g_activeMapPane` viewport bounds;
  - shared Surface/GrafPort `RenderTileFrame`;
  - tile context, tile bounds, viewport bounds, mode `1`, palette/name, flags `0`;
  - source method is `void` despite live `EAX`.
- Add first-draft C++ from this report.
- Keep the unresolved-caveat wording specific:
  - no direct constructor call/data route found;
  - final source spellings for name fields/helper are heuristic;
  - final last-argument names are inherited-base semantics.

## Recommended support-doc changes

For `by-file/Effects.md`:

- Update the `OverlayImageEffecter` inventory row from the current abbreviated range to exact half-open method coverage:
  - `0x0055a440-0x0055a499`
  - `0x0055a4a0-0x0055a55e`
  - `0x0055bd70-0x0055be0d`
  - optionally mention cleanup `0x0055a3d0-0x0055a43e`
- Replace the "fitting-room/download overlay" wording with a source-neutral role:
  - static overlay-image effecter using `g_activeMapPane`, `g_pEPFLib`, `EPFTileContext`, copied image/palette names, and the shared Surface/GrafPort `RenderTileFrame` path.
- Keep source root `NexusTK/render/Effects.cpp`.

For `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`:

- Add the exact `OverlayImageEffecter` method ranges listed above.
- Add the adjusted-view field mapping for the apply method.
- Add vtable-only reachability for `0x0055a440` through `0x006236fc`.
- Add no-direct-constructor-route caveat for `0x0055a4a0`.
- Add `0x0055a3d0-0x0055a43e` as EH cleanup/non-deleting destructor-shaped evidence.
- Keep the aggregate reconstructable; no split is required.

For `by-type/by-vtable/ScreenEffecterVtableFamily.md`:

- Preserve the four `OverlayImageEffecter` vtable views and store evidence.
- Add that `0x006236fc -> 0x0055a440` is the adjusted `+0x04` view's render/apply method and receives `ecx = complete+4`.
- Document the method as source-facing `void OverlayImageEffecter::ApplyOverlayImage()` unless a family-wide virtual naming update is made.

For `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`:

- Preserve compiler-output status.
- Add exact OverlayImageEffecter vtable view ranges:
  - `0x00623694-0x006236b4`
  - `0x006236b8-0x00623700`
  - `0x00623704-0x00623730`
  - `0x00623734-0x0062373c`
- Keep scalar-deleting destructor/thunks as compiler-generated.

For `by-memory/0x00623480-0x00623d58.ScreenEffecterReadOnlyData.md`:

- No mandatory change is required if the vtable child docs carry the above details.
- Optional cross-reference: note that the OverlayImageEffecter COL/vtable block under this aggregate supports [UID:00009Y].

For helper/global docs:

- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md` and `by-global/SurfaceRenderCallbackTable.md` already contain the important correction that `0x004b9980`/`dword_69B3E8` are shared Surface/GrafPort render paths. No mandatory edit is needed unless implementation wording wants a consumer cross-link.
- `by-global/g_activeMapPane.md`, `by-global/g_pEPFLib.md`, `by-class/EPFTileContext.md`, and `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md` are sufficient for this target; optional consumer cross-links only.

## Exact coverage text

Do not edit `by-memory/-coverage-report.md` during B-agent implementation unless the supervisor explicitly owns that step. If accepted, the class row should become:

```text
- [UID:00009Y][OverlayImageEffecter](by-class/OverlayImageEffecter.md) : reconstructable : 88% : strong : Source-ready static overlay-image effecter under Effects; local PE reanalysis confirms exact apply/constructor/scalar-destructor ranges, EH cleanup body, four-view vtables, adjusted-view field mapping (`+0x120/+0x144/+0x154`), `g_activeMapPane` viewport render route, `g_pEPFLib` resource lookup, copied image/palette names, rejected fitting-room/download helper ownership, no direct constructor route caveat, and first-draft C++ readiness.
```

The stale `by-memory` aggregate coverage row for [UID:0001GE] currently reports `82%` even though the page metadata is `86/88`. If the implementation updates the runtime-cluster notes, the exact replacement row should be:

```text
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) 0x0055a260-0x0055c1ff | class/helper cluster | ScreenEffecterRuntimeCluster : reconstructable : 86% : strong : Runtime effecter aggregate under Effects with local PE-confirmed ScreenEffecter/overlay/filter/pixel/lake method inventory, raw constructor islands, boundary padding, current OverlayImageEffecter source-quality evidence including exact apply/constructor/scalar-destructor ranges, adjusted-view render field mapping, vtable-only Apply reachability, no direct constructor-route caveat, shared Surface/GrafPort render-helper dependency, and exact child pages for selected source-ready methods.
```

No coverage row change is required for `ScreenEffecterVtableData` or `ScreenEffecterReadOnlyData` unless their prose/metadata are changed during implementation.

## Validation commands needed after implementation

Run scoped validators from `source-3/project-documentation` for each touched by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [00009Y-OverlayImageEffecter-source-quality-removed.md](00009Y-OverlayImageEffecter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run helper/global validators only if those docs are touched for optional cross-links.

If formal C++ generation changes generated output or projected stats, run the repository's normal autogen/rescore workflow and report generated/stat file changes. Do not hand-edit generated output unless the project workflow requires it.

## IDA rename, type, and comment recommendations

High confidence:

- Rename/comment `0x0055a440` as `OverlayImageEffecter::ApplyOverlayImage`.
- Type `0x0055a440` as `void __thiscall OverlayImageEffecter::ApplyOverlayImage(...)`, with a comment that `ecx` is the `+0x04` adjusted view and the complete object is `ecx - 4`.
- Rename `0x0055a4a0` as `OverlayImageEffecter::OverlayImageEffecter`.
- Type `0x0055a4a0` as `OverlayImageEffecter *__thiscall OverlayImageEffecter::OverlayImageEffecter(const wchar_t *imageName, const wchar_t *paletteName, unsigned short overlayX, unsigned short overlayY)`.
- Rename/comment `0x0055bd70` as `OverlayImageEffecter::scalar_deleting_destructor`.
- Rename/comment `0x0055ba7c`, `0x0055ba84`, and `0x0055ba8f` as adjusted scalar deleting destructor thunks.
- Comment `0x0055a3d0-0x0055a43e` as `OverlayImageEffecter` EH cleanup / non-deleting destructor-shaped cleanup.

Medium/high confidence:

- Add struct fields:
  - complete `+0x100`: `m_imageName[16]`
  - complete `+0x120`: `m_paletteName[16]` / `m_overlayPaletteName[16]`
  - complete `+0x144`: `m_tileContext`
  - complete `+0x154`: `m_tileContext.bounds`
  - complete `+0xf9`: `m_isVisible` or inherited active byte
- Comment inherited base fields complete `+0xfc/+0xfe` as the last two constructor arguments passed to `OverlayEffecter(1, ..., ...)`.
- Rename/comment `0x004b9980` as shared `RenderTileFrame` / Surface-GrafPort tile-frame render helper, not FittingRoomDownload ownership.
- Rename/comment `0x00457a60` as `EPFTileContext::Init`.
- Keep `0x004d02f0` as `ResourceLayoutTable::LookupLayoutEntry`.

Medium confidence / caveat:

- Comment `0x005cd657` as bounded wide-string copy / likely `wcscpy_s`; avoid hard import-style naming unless an import or CRT-match pass confirms it.

## Remaining issues and impact

Direct construction site:

- Evidence checked: rel32 code refs, absolute dword refs, RVA-style dword refs, vtable stores, sibling constructor callers, base-constructor callers, and generated class metadata.
- Result: no direct construction route for `0x0055a4a0` found in the local PE.
- Best interpretation: retained/dead or metadata-gap class path inside the Effects runtime family. This is a confidence limiter, not a source-readiness blocker, because the constructor body, vtables, apply route, and sibling family context are all coherent.

Final source names:

- `m_imageName`, `m_paletteName`, `RenderTileFrame`, `LookupLayoutEntry`, `m_isVisible`, and `overlayX/overlayY` are source-quality descriptive names, not symbol-proven final names.
- Impact: keep confidence below final-source level and preserve caveats in target/support docs.

Compiler-generated artifacts:

- Scalar deleting destructor, adjusted thunks, vtable views, and the `0x0055a3d0` cleanup body should be documented as evidence but not emitted as hand-written source C++.

Implementation readiness:

- Ready after supervisor acceptance.
- Required implementation scope: target class doc plus support docs listed above.
- Coverage application remains supervisor-owned; exact row text is included here.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00009Y-OverlayImageEffecter-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"00009Y"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00009Y-OverlayImageEffecter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00009Y-OverlayImageEffecter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00009Y"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
