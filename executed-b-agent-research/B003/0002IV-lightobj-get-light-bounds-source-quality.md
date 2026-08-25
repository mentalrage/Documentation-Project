** TARGET-REPORT-UID:0002IV **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002IV LightObjImageLib GetLightBounds Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:0002IV] `LightObjImageLibGetLightBounds` from `82/88` to `88/92`.
- Final disposition: keep `RECONSTRUCTABLE:TRUE`, keep `CANONICAL_OWNER:0000KP`, keep `EMITTER_UIDS:0000KP`, and populate the formal `RECONSTRUCTION_CPP CODE` block with the first-draft method body below.
- Required action: update the target doc to close the stale method-name/caller-ownership caveat, apply the support text recommendations, and replace the stale [UID:00017P] and [UID:0002IV] coverage rows with the pasteable block in this report.
- Confidence: high. The method is a small exact `thiscall` body with one caller, one callee, stable LightInfo layout support, current IDA labels, and a fully bounded source role.

This was report-only work. I did not edit by-* docs, generated reports, source files, IDA DB, generated source, or `by-memory/-coverage-report.md`. No split exception was needed.

## Supporting Research

## Target

- Target UID: [UID:0002IV]
- Target path: `by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md`
- Current documented score: `82/88`
- Current owner/emitter: [UID:0000KP] `LightObjImageLib` file
- Current source route: `NexusTK/render/LightObjImageLib.cpp`
- Target issue in current doc: final source-level method name and caller-side ownership at `0x0053c810` were still listed as unresolved caveats.

## Executive Recommendation

The source-facing method should be:

```cpp
void LightObjImageLib::GetLightBounds(int lightIndex, RectBounds *outBounds)
```

The method belongs to `LightObjImageLib` and should emit through [UID:0000KP] `NexusTK/render/LightObjImageLib.cpp`. The caller at `0x0053c810` is an `AttachmentAnchorResolver::ComputeScreenBounds` consumer. It validates the local-bounds role but does not change ownership or source placement.

The output rectangle is a local, center-relative bounds rectangle for the generated light mask. It is not a draw rectangle, screen rectangle, allocation rectangle, or global bounds rectangle until caller-side code offsets it through `RectBounds` translation.

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:0000KP
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000KP
```

## Supervisor Active Recheck

- The assigned target is an exact function page, not a mixed aggregate.
- Current IDA reports `LightObjImageLibGetLightBounds` at `0x004dfb40` with size `0x70`, ending exactly at `0x004dfbb0`.
- The next function at `0x004dfbb0` is `LightObjImageLibDrawLightMode1`.
- The containing [UID:00017P] page is already a non-emitting local cluster page. The supervisor-owned coverage report is stale and still calls that cluster reconstructable with broad end `0x004e669d`; this report includes an exact row replacement.
- No by-structure split or child creation is required.

## Inference Research Guidance Check

Following `by-structure.md`, the target should keep a direct file owner because the existing target metadata already uses [UID:0000KP], the file root clears the gate at `87/85`, and the method is a file/class-local image-library method. The narrower class page [UID:000076] supports the semantic class role, but current target metadata consistently routes LightObjImageLib methods through the file page. This report does not recommend changing that established owner/emitter route.

Generated output and recovered source were treated as leads only. The active generated file `auto-generated/NexusTK/render/LightObjImageLib.cpp` is currently zero bytes because formal C++ blocks are blank, not because the emitter route is invalid.

## Heuristic / Inference Reanalysis And Validation

Best defensible source names and types:

- Method name: `LightObjImageLib::GetLightBounds`.
- Signature: `void GetLightBounds(int lightIndex, RectBounds *outBounds)`.
- Output type: `RectBounds *` using the shared four-int `{left, top, right, bottom}` layout from [UID:0001VP].
- Selected record type: `LightInfo`.
- Field names used by this method: `radiusX`, `radiusY`, and `generatedFrame`.
- Fallback/default record: the embedded `fallbackLightInfo` at object offset `+0x14`.

Evidence checked:

- Current target page and support docs for [UID:00017P], [UID:0002IU], [UID:00017Q], [UID:0002IW], [UID:0002IX], [UID:0002IY], [UID:000076], [UID:0000KP], [UID:0001UX], [UID:0001UW], [UID:0000RD], [UID:0001PR], and [UID:0001VP].
- Caller-side docs for [UID:0001DH], [UID:00000O], and [UID:0000HL] `AttachmentAnchorResolver`.
- Existing executed B reports. The only relevant old B003 report was the adjacent `0003LZ` correction, which rejected stale LightObj ownership for pre-`0x004df7e0` ItemObj helpers and confirms the LightObj cluster starts at the constructor.
- Current `by-memory/-coverage-report.md` rows.
- Active generated memory coverage and `auto-generated/NexusTK/render/LightObjImageLib.cpp`.
- Fresh IDA MCP session `b002_00017m_effectobj_render_20260617` against `NexusTK.exe`.

Best inferences and validations:

- `GetLightBounds` is a strong source-facing name. The method returns bounds from a selected light record and does no drawing or allocation. The current IDA label already uses `LightObjImageLibGetLightBounds`, and the sole caller uses it to initialize a rectangle before translating to an attachment anchor.
- The return type should be `void` in source. The binary tail-calls the rectangle initializer and returns the helper's incidental integer result, but the caller ignores it and all semantic output is through the rectangle pointer.
- The rectangle is local and center-relative because the method writes `-radiusX`, `-radiusY`, `radiusX + 1`, `radiusY + 1`, and the caller immediately offsets it by anchor/local positions through `sub_4B7E10`.
- The fallback record is intentional. Constructor evidence copies four `-1` integers into `fallbackLightInfo`, zeros the float/frame fields, and this method returns a zero rectangle because `generatedFrame` is null.
- Caller `0x0053c810` is `AttachmentAnchorResolver::ComputeScreenBounds` context. Its ownership remains with [UID:00000O]/[UID:0000HL], but it loads `g_pLightObjImageLib` into `ecx`, pushes output rect and light index, and calls the LightObj method. Consumer-side ownership does not override the image-library method owner.
- [UID:00017P] should stay non-emitting. The exact children own the source bodies; the cluster row in coverage should be fixed to match the current doc state.

Rejected alternatives:

- `int GetLightBounds(...)`: rejected as decompiler artifact. The returned value is the rectangle setter's incidental `right`/`dy`-style return and is unused by the only caller.
- `RectBounds *GetLightBounds(...)`: rejected for the same reason; the helper does not return the rectangle pointer in the observed binary.
- `GetFrameBounds`: rejected because the method does not read frame width/height; it uses the `LightInfo` radii and only tests `generatedFrame` for availability.
- `GetScreenBounds`: rejected because screen conversion happens in `0x0053c810` after this method returns local bounds.
- `DrawLightBounds` or draw-mode ownership: rejected because the method has no frame blitter call and is not a vtable target.
- Move ownership to `AttachmentAnchorResolver`, `ObjectPane`, `EffectObjectPane`, or `LightingObjectPane`: rejected. Those are callers/consumers. The method reads LightObj layout fields, uses `LightInfo`, and is physically in the LightObj local method cluster between destructor and draw modes.
- Keep the name/caller caveat open: rejected. Current docs and fresh IDA resolve caller-side ownership enough to remove it as a target blocker.

Remaining blockers:

- Original spelling of the method and member names is not proven by debug symbols. The descriptive names are strong enough for source-quality documentation and C++ draft entry.
- The first two `LightInfo` integer field names remain provisional in [UID:0001UW], but they are not read by this target and should not cap this target below 85.
- The global class/file C++ rewrite is still incomplete; however, this method body is self-contained enough to emit a first draft without duplicating unrelated constructor/destructor/draw logic.

Score/source-placement/final-C++ impact:

- The target can safely clear the 85/85 gate at `88/92`.
- Source placement stays `NexusTK/render/LightObjImageLib.cpp`.
- Formal C++ should be populated for this target.
- Support pages should remove old `90/90+` or `95+` code-gate wording where touched by this update and reference the active combined-score/emitter rule.

## Evidence Standards Used

- IDA MCP function lookup, decompilation, disassembly, xrefs, callees, function analysis, and raw bytes.
- Existing by-* documentation, treated as leads until confirmed.
- Generated reports and generated source only as routing/omission evidence.
- Negative evidence from rejected consumers and non-target roles.
- Current source-tree proposal for `render/LightObjImageLib.cpp` and map-side `AttachmentAnchorResolver` placement.

The evidence is strong because the target is a compact exact function with one direct caller, one modeled callee, no data refs, no indirect dispatch, no raw island ambiguity, and field-layout agreement across constructor, destructor, draw modes, layout/type docs, and caller use.

## IDA MCP Facts

Active session:

- Session id: `b002_00017m_effectobj_render_20260617`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Health: `ok`, auto-analysis ready, Hex-Rays ready.

Function/range facts:

- `lookup_funcs 0x004dfb40`: `LightObjImageLibGetLightBounds`, size `0x70`.
- `lookup_funcs 0x004dfbb0`: `LightObjImageLibDrawLightMode1`, size `0xaa`.
- `lookup_funcs 0x0053c810`: `sub_53C810`, size `0x11e`.
- `lookup_funcs 0x0053c92e`: not a function.
- `lookup_funcs 0x004b7c50`: `sub_4B7C50`, size `0x1f`, the rectangle initializer.
- `lookup_funcs 0x004b7e10`: `sub_4B7E10`, size `0x19`, the rectangle offset helper.

Target disassembly facts:

- `ecx` is `this`.
- Stack arg 0 is `lightIndex`.
- Stack arg 1 is `outBounds`.
- Negative index or `index >= this[2]` selects `this + 0x14`.
- In-range index selects `this[3] + 28 * index`.
- `generatedFrame` at row `+0x18` gates bounds generation.
- When available, fields at row `+0x08/+0x0c` are negated/incremented as radii.
- The method calls `sub_4B7C50(outBounds, left, top, right, bottom)` and returns with `retn 8`.

Target decompile:

```text
int __thiscall sub_4DFB40(_DWORD *this, int a2, _DWORD *a3)
{
  if (a2 < 0 || a2 >= this[2])
    v3 = (int)(this + 5);
  else
    v3 = this[3] + 28 * a2;
  if (*(_DWORD *)(v3 + 24))
    sub_4B7C50(a3, -radiusX, -radiusY, radiusX + 1, radiusY + 1);
  else
    sub_4B7C50(a3, 0, 0, 0, 0);
}
```

Caller facts:

- `xrefs_to 0x004dfb40`: one code xref at `0x0053c82b` from `0x0053c810`.
- `0x0053c810` has ten code xrefs from map/attached-object render/update paths, matching existing `AttachmentAnchorResolver` docs.
- Disassembly at `0x0053c810`:
  - loads `ecx` from `0x0069b450` (`g_pLightObjImageLib`);
  - pushes output rect argument;
  - pushes `[ebx + 0x128]` as the light index;
  - calls `LightObjImageLibGetLightBounds`;
  - computes anchor/world coordinates;
  - applies local offsets at `+0x12c/+0x130`;
  - calls `sub_4B7E10` to offset the rectangle.

Rectangle helper facts:

- `sub_4B7C50` writes `[left, top, right, bottom]`.
- `sub_4B7E10` adds `dx` to left/right and `dy` to top/bottom.
- [UID:0001VP] confirms the same `RectBounds` layout and half-open rectangle semantics.

Fallback facts:

- Constructor copies four `-1` integer fields from `0x00619660` into the embedded fallback record and then zeros the two float fields plus generated-frame pointer.
- Therefore fallback/out-of-range bounds are empty because `generatedFrame == 0`, not because `radiusX/radiusY` are used.

Padding facts:

- `0x004dfb36-0x004dfb40`: ten `0xcc` bytes before the target.
- `0x004dfbb0`: next function prolog begins immediately after the target.
- `0x0053c802-0x0053c810`: fourteen `0xcc` bytes before the caller.
- `0x0053c92e-0x0053c930`: two `0xcc` bytes before the next raw/modeled sibling.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004df7e0-0x004dfd0a` | [UID:00017P] `LightObjImageLibLocalMethodCluster` | Non-emitting local cluster/index | FALSE | NONE | `83/89` | Keep non-emitting; coverage row stale. |
| `0x004dfb40-0x004dfbb0` | [UID:0002IV] `LightObjImageLibGetLightBounds` | Exact method | TRUE | [UID:0000KP] | recommend `88/92` | Emit formal C++. |
| `0x0053c810-0x0053c92e` | [UID:0001DH] `AttachmentAnchorResolver` contained helper | Caller/source context | TRUE | [UID:00000O] | `85/87` | Consumer only; no target owner change. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0053c82b` | code xref to `0x004dfb40` | Sole direct call to `GetLightBounds`; validates local bounds output. |
| `0x0053c81d` | reads `0x0069b450` | Loads `g_pLightObjImageLib` as the method `this` pointer. |
| `0x0053c824` | pushes output rect pointer | Caller supplies mutable rectangle. |
| `0x0053c825` | pushes `[this + 0x128]` | Caller-side light index for the LightObj table. |
| `0x0053c91b` | calls `0x004b7e10` | Caller offsets local bounds into screen/anchor coordinates. |
| `0x004dfba1` | calls `0x004b7c50` | Target initializes the four-int output bounds. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0000KP] places `LightObjImageLib.cpp` under `NexusTK/render/`.
- [UID:000076] defines `LightObjImageLib` as the `LIGHT.TBL` procedural light-frame singleton.
- [UID:0001UX] documents `lightInfoCount`, `lightInfoEntries`, and `fallbackLightInfo` at the offsets used by this method.
- [UID:0001UW] documents `LightInfo` `radiusX`, `radiusY`, and `generatedFrame`.
- [UID:0001VP] documents the four-int rectangle layout used by the target and caller.
- [UID:0001DH]/[UID:00000O]/[UID:0000HL] now identify `0x0053c810` as `AttachmentAnchorResolver::ComputeScreenBounds`.

Existing docs that are stale or incomplete:

- [UID:0002IV] still says final method name and caller ownership are unresolved. This report resolves them enough to remove that caveat.
- [UID:00017P] coverage row is stale: it says broad `0x004df7e0-0x004e669d` and `reconstructable`, while the page and generated report now say local `0x004df7e0-0x004dfd0a` and `RECONSTRUCTABLE:FALSE`.
- Some support pages still mention obsolete `90/90+` or `95+` code-entry gates. When touched, they should be aligned to the active combined-score/emitter gate.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` routes [UID:0002IV] as `emits` to `auto-generated/NexusTK/render/LightObjImageLib.cpp`.
- The active generated `LightObjImageLib.cpp` file currently has length `0` because formal C++ blocks remain blank.

## Ranked Ownership Analysis

### 1. [UID:0000KP] LightObjImageLib file

- Evidence for: target is in the LightObjImageLib method cluster; reads LightObj layout fields; consumes `LightInfo`; uses the singleton caller as `this`; file root already owns constructor, destructor, draw modes, vtable/global route, and `LIGHT.TBL` behavior; source tree places `LightObjImageLib.cpp` under `render/`.
- Evidence against: direct semantic class owner [UID:000076] also exists and is strong.
- Decision: accepted as current target owner/emitter, matching existing metadata and generated route. No change recommended.

### 2. [UID:000076] LightObjImageLib class

- Evidence for: the method is a class method and uses class layout.
- Evidence against: current by-memory method pages in this family route directly to file [UID:0000KP]; changing only this target to class ownership would be inconsistent and not needed for source output.
- Decision: use as support/semantic class context; no target metadata change.

### 3. [UID:00000O]/[UID:0000HL] AttachmentAnchorResolver

- Evidence for: sole direct caller is `AttachmentAnchorResolver::ComputeScreenBounds`, and caller field `+0x128` supplies the index.
- Evidence against: it is a consumer; the target body reads no AttachmentAnchorResolver fields and belongs to the LightObjImageLib code cluster.
- Decision: rejected as owner/emitter. Use caller evidence to validate name and local-bounds semantics only.

### 4. RectBounds / AlphaMaskSurface / draw-mode owners

- Evidence for: target depends on rectangle helper and tests generated-frame pointer.
- Evidence against: no RectBounds ownership of the method body; no draw call; no AlphaMaskSurface size/field use in this target.
- Decision: dependencies only.

## Negative Evidence Summary

- No evidence that `0x004dfb40` is a draw routine: no frame blitter call, no vtable slot, no target surface.
- No evidence that `0x004dfb40` computes screen/world bounds: caller performs the offset after this method.
- No evidence that caller ownership changes source placement: callsite loads `g_pLightObjImageLib` and invokes a normal class method.
- No split evidence: target start/end, surrounding padding, and next function are all exact.
- No evidence that the active zero-byte generated file means route failure: generated coverage reports an emitter route; source is empty because code blocks are blank.

## First-Draft C++ Recommendation

Populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:0002IV] with this method body.

```cpp
void LightObjImageLib::GetLightBounds(int lightIndex, RectBounds *outBounds)
{
    const LightInfo *lightInfo = &fallbackLightInfo;

    if (lightIndex >= 0 && lightIndex < lightInfoCount) {
        lightInfo = &lightInfoEntries[lightIndex];
    }

    if (lightInfo->generatedFrame != 0) {
        InitRectBounds(outBounds,
            -lightInfo->radiusX,
            -lightInfo->radiusY,
            lightInfo->radiusX + 1,
            lightInfo->radiusY + 1);
        return;
    }

    InitRectBounds(outBounds, 0, 0, 0, 0);
}
```

Why this is safe under the active code gate:

- Target is `RECONSTRUCTABLE:TRUE`.
- Target has nonblank `EMITTER_UIDS:0000KP`.
- Emitter route reaches valid source file root [UID:0000KP] with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
- Recommended score `88/92` gives average `90`, above the active `>85` gate.
- The method body is exact-scope only and does not include constructor, destructor, draw-mode, caller, or support-source code.
- Names used in the body are already supported by [UID:0001UX], [UID:0001UW], and [UID:0001VP]; the first two provisional `LightInfo` fields are not referenced here.

## Exact Target Doc Changes Recommended

For [UID:0002IV]:

- Change metadata to:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:0000KP
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000KP
```

- Replace the source-name/caller caveat with:

```text
2026-06-17 B003 reanalysis resolves the prior method-name and caller-context caveat. Fresh IDA MCP disassembly shows `0x0053c810` loads `g_pLightObjImageLib` into `ecx`, pushes the output `RectBounds*`, pushes the caller's light index at `+0x128`, and calls this method at `0x0053c82b`. The caller then translates the returned local rectangle through `sub_4B7E10`, confirming the source-facing name `LightObjImageLib::GetLightBounds(int lightIndex, RectBounds *outBounds)` and confirming that `0x0053c810` is only consumer context under AttachmentAnchorResolver, not the owner/emitter for this method.
```

- Add source-signature text:

```text
Best source-facing signature: `void LightObjImageLib::GetLightBounds(int lightIndex, RectBounds *outBounds)`. IDA's incidental `int` return comes from tail-returning the shared rectangle initializer result; the only caller ignores the return and all semantic output is through `outBounds`.
```

- Populate the formal C++ block with the first-draft code above.

## Support Docs To Update

- [UID:00017P] `LightObjImageLibLocalMethodCluster`: keep non-emitting `RECONSTRUCTABLE:FALSE`. Update coverage only if not changing body; current by-memory page already has the correct local range and non-emitting state.
- [UID:000076] `LightObjImageLib`: update method table to show `GetLightBounds(int lightIndex, RectBounds *outBounds)` and remove "medium for final field names" as a blocker for this method specifically. Keep broader class score unchanged unless a full class pass is done.
- [UID:0000KP] `LightObjImageLib`: note that [UID:0002IV] now has formal C++ and that the active generated file was zero-length only because method blocks were blank.
- [UID:0001UX] `LightObjImageLibLayout`: no ownership change. Optionally add that the fallback record default is four `-1` integer fields plus zeroed float/frame fields, producing empty bounds in `GetLightBounds`.
- [UID:0001UW] `LightInfo`: no score change required. Existing `radiusX`, `radiusY`, and `generatedFrame` names are sufficient for this target.
- [UID:0001DH]/[UID:00000O]/[UID:0000HL] `AttachmentAnchorResolver`: optionally add that `ComputeScreenBounds` calls `LightObjImageLib::GetLightBounds` through `g_pLightObjImageLib` and then offsets the local bounds; this is consumer evidence only.

## Exact Coverage Row Replacement

Placement context: replace the current [UID:00017P] LightObjImageLib block in `by-memory/-coverage-report.md` beginning at line `1725` and ending at line `1732`. This preserves unchanged sibling rows while updating [UID:00017P] and [UID:0002IV].

```markdown
    - [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md) 0x004df7e0-0x004dfd0a | class-method-cluster/index | LightObjImageLib local method cluster : not_reconstructable : 83% : strong : Non-emitting local split/index for the LightObjImageLib constructor, raw ordinary destructor, GetLightBounds, and two virtual draw-mode methods before NewHumanImageLib begins at 0x004dfd10; exact child pages and separate tail pages carry source ownership/emission, while this cluster only records boundaries, padding, vtable/global anchors, and aggregate policy.
        - [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md) 0x004df7e0-0x004dfaa6 | constructor | LightObjImageLib::LightObjImageLib : reconstructable : 82% : strong : Loads LIGHT.TBL, allocates 0x1c-byte LightInfo rows, seeds fallback state, and creates radial light frames; live IDA confirms exact 0x2c6 primary body, one startup caller at 0x004f6139, singleton/vtable writes, DAT/frame/memory callees, constructor cleanup chunks, and ten-byte cc padding before the raw destructor.
        - [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md) 0x004dfab0-0x004dfb36 | destructor | LightObjImageLib::~LightObjImageLib : reconstructable : 82% : strong : Raw ordinary destructor; live IDA confirms non-modeled 0x86-byte body, no direct refs to the raw start, frame-delete loop over 0x1c LightInfo rows, vtable/global writes, record-buffer free, base tail-call, and ten-byte cc padding.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004dfaa6-0x004dfab0, 0x004dfb36-0x004dfb40, 0x004dfc5a-0x004dfc60, 0x004dfd0a-0x004dfd10, 0x004e669d-0x004e66a0 | padding | LightObjImageLib internal alignment : ignored : 100% : strong : Confirmed `0xcc`/alignment bytes around exact LightObjImageLib child functions.
        - [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) 0x004dfb40-0x004dfbb0 | method | LightObjImageLib::GetLightBounds : reconstructable : 88% : very-strong : Fresh 2026-06-17 IDA MCP evidence validates the exact 0x70 `thiscall` body, source-facing `void GetLightBounds(int lightIndex, RectBounds *outBounds)` signature, one `AttachmentAnchorResolver::ComputeScreenBounds` caller at 0x0053c82b, singleton `this` load from g_pLightObjImageLib, LightInfo/fallback selection, generated-frame gate, local `[-radiusX,-radiusY,radiusX+1,radiusY+1]` bounds semantics, empty fallback/default behavior, RectBounds initializer dependency, and LightObjImageLib.cpp emission readiness with formal C++ populated.
        - [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md) 0x004dfbb0-0x004dfc5a | virtual method | LightObjImageLib::DrawLightMode1 : reconstructable : 82% : strong : Centers a generated light frame and calls the shared frame blitter with blend mode 1; live IDA confirms exact 0xaa body, vtable-only ref at 0x0061b760, no direct callers, rectangle setter/frame blitter/security-cookie callees, and six-byte cc padding before mode 2.
        - [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md) 0x004dfc60-0x004dfd0a | virtual method | LightObjImageLib::DrawLightMode2 : reconstructable : 82% : strong : Centers a generated light frame and calls the shared frame blitter with blend mode 2; live IDA confirms exact 0xaa body, vtable-only ref at 0x0061b764, no direct callers, rectangle setter/frame blitter/security-cookie callees, and six-byte cc padding before NewHumanImageLib.
        - [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) 0x004e65e0-0x004e669d | deleting destructor | LightObjImageLib scalar deleting destructor : reconstructable : 82% : strong : Virtual deleting wrapper over generated-frame cleanup; live IDA confirms exact 0xbd body, vtable-only ref at 0x0061b754, no direct callers, base/free/delete/guard callees, delete-flag branch, singleton clear, and three-byte cc padding.
```

## Validation Commands

Commands run for this report:

> Executable block R001 was removed from this report and preserved verbatim in [0002IV-lightobj-get-light-bounds-source-quality-removed.md](0002IV-lightobj-get-light-bounds-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Fresh IDA MCP checks were run through `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, `analyze_function`, and `get_bytes` against session `b002_00017m_effectobj_render_20260617`.

Recommended supervisor validation after applying target/support edits:

> Executable block R002 was removed from this report and preserved verbatim in [0002IV-lightobj-get-light-bounds-source-quality-removed.md](0002IV-lightobj-get-light-bounds-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0002IV-lightobj-get-light-bounds-source-quality.md`
- Modified: none outside this report.
- Leases used: none.
- Blockers: none. The remaining work is supervisor application of the report's exact target/support/coverage changes.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002IV-lightobj-get-light-bounds-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002IV"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002IV-lightobj-get-light-bounds-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002IV-lightobj-get-light-bounds-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002IV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
