** TARGET-REPORT-UID:0002TZ **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B006 Source-Quality Reanalysis: UID 0002TZ - AttachmentAnchorApplyLight

Assignment: `B006-goal2-attachment-anchor-apply-light-source-quality-0002TZ-20260619`

Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`

Output status: report-only. No by-* documentation and no `by-memory/-coverage-report.md` edits were made.

## Executive Recommendation

`UID:0002TZ` is source-ready. The best-supported source-facing reconstruction is a small `AttachmentAnchorResolver` helper that applies/draws the resolved attachment light through `LightObjImageLib::DrawLightMode1`.

Recommended source name:

```cpp
AttachmentAnchorResolver::ApplyLightAtAnchor
```

Recommended first-draft C++:

```cpp
void AttachmentAnchorResolver::ApplyLightAtAnchor(MapPane *mapPane, int centerX, int centerY)
{
    g_pLightObjImageLib->DrawLightMode1(
        mapPane->m_selectionOverlay,
        centerX,
        centerY,
        m_lightImageIndex);
}
```

Recommended target metadata after source-quality update:

- `COMPLETION: 88`
- `CONFIDENCE: 90`
- `RECONSTRUCTABLE: TRUE`
- `CANONICAL_OWNER: 00000O`
- `EMITTER_UIDS: 00000O`
- Source route remains `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp` through `UID:00000O` / `UID:0000HL`.

The target was previously blocked mainly by unresolved light-table method names and by uncertainty around the source-facing wrapper name. Those blockers are now substantially resolved by the current `LightObjImageLib` by-memory/by-type docs and local IDA-export evidence. The exact original symbol spelling is still not available, but the behavior, owner, parameter roles, field roles, callsites, range split, and implementation shape are strong enough for a first-draft source body.

## Evidence Inputs And Limits

Primary evidence used:

- Target by-memory doc: `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`.
- Current supervisor-owned coverage row from `by-memory/-coverage-report.md`.
- Auto-generated route row from `auto-generated/-all-rows-by-uid.md`.
- Owner docs:
  - `by-class/AttachmentAnchorResolver.md`
  - `by-file/AttachmentAnchorResolver.md`
  - `by-file/AttachedObjectPane.md`
  - `by-class/AttachedObjectPane.md`
- Caller docs:
  - `by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md`
  - `by-memory/0x0050a500-0x0050ab95.MapPanePaintLightingCore.md`
  - `by-file/MapPane.md`
  - `by-class/MapPane.md`
- Light system docs:
  - `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md`
  - `by-memory/0x004dfb40-0x004dfbaa.LightObjImageLibGetLightBounds.md`
  - `by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md`
  - `by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md`
  - `by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md`
  - `by-type/by-vtable/LightObjImageLibVtable.md`
  - `by-type/by-struct/LightObjImageLibLayout.md`
  - `by-type/by-struct/LightInfo.md`
  - `by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md`
  - `by-type/by-struct/AlphaMaskSurfaceLayout.md`
- Raw sibling docs:
  - `by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md`
  - `by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md`
  - `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`
- Existing support research:
  - `tools/leaser/Agents/Agent-B015/research/0001DH-AttachmentAnchorResolver-source-quality.md`

Machine-level evidence used:

- Local IDA exports:
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c`
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.map`

Live IDA MCP status:

- A live MCP check was attempted for `http://127.0.0.1:13337/mcp`.
- Result: unable to connect to the remote server.
- Therefore, this pass does not claim fresh live-IDa MCP verification. Where machine evidence is cited, it is cited as local IDA-export evidence.

Numeric conversion verification:

- `0x128` = `296`, verified with `tools/int_convert.py`.
- `0x3e0` = `992`, verified with `tools/int_convert.py`.
- `0x0c` = `12`, verified with `tools/int_convert.py`.
- `0x10` = `16`, verified with `tools/int_convert.py`.
- `0x1c` = `28`, verified with `tools/int_convert.py`.
- `0x14` = `20`, verified with `tools/int_convert.py`.
- `0x18` = `24`, verified with `tools/int_convert.py`.
- `0x2b` = `43`, verified with `tools/int_convert.py`.

## Current Target State

Current target header says:

- `UID: 0002TZ`
- `STATUS: Documented`
- `COMPLETION: 85`
- `CONFIDENCE: 87`
- `CANONICAL_OWNER: 00000O`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS: 00000O`
- Current C++ block is blank.

Current target role:

- A modeled helper/method under `AttachmentAnchorResolver`.
- It follows the `LightingObjectPaneSetIntensity` region plus padding.
- It precedes the raw no-function twin at `0x0053c9f0-0x0053ca1b`.
- It reads `dword_69B450`, now resolved as `g_pLightObjImageLib`.
- It calls virtual slot `+0x0c` from that object.
- It passes:
  - `*(arg0 + 0x3e0)` as the target surface/context field.
  - Two caller-provided anchor coordinates.
  - Resolver field `this[74]` / `this + 0x128`.

Current auto-generated route row:

```text
| [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) | emits | `00000O` | `00000O` |  | no | `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp` | `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md` |  |
```

`auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp` currently contains only empty emitter markers for the class and children, including `0002TZ`; no source body has been emitted for this target yet.

## Local IDA-Export Body Evidence

The local `.map` export contains `sub_53C9C0`, and the local `.lst` export identifies the target body exactly:

```asm
.text:0053C9C0 sub_53C9C0 proc near
.text:0053C9C0 arg_0= dword ptr  8
.text:0053C9C0 arg_4= dword ptr  0Ch
.text:0053C9C0 arg_8= dword ptr  10h
.text:0053C9C0 push ebp
.text:0053C9C1 mov ebp, esp
.text:0053C9C3 mov edx, dword_69B450
.text:0053C9C9 mov eax, [ebp+arg_0]
.text:0053C9CC push esi
.text:0053C9CD push dword ptr [ecx+128h]
.text:0053C9D3 mov esi, [edx]
.text:0053C9D5 mov ecx, edx
.text:0053C9D7 push [ebp+arg_8]
.text:0053C9DA push [ebp+arg_4]
.text:0053C9DD push dword ptr [eax+3E0h]
.text:0053C9E3 call dword ptr [esi+0Ch]
.text:0053C9E6 pop esi
.text:0053C9E7 pop ebp
.text:0053C9E8 retn 0Ch
.text:0053C9E8 sub_53C9C0 endp
.text:0053C9EB align 10h
```

The local `.c` export decompiles it as:

```c
int __thiscall sub_53C9C0(_DWORD *this, int a2, int a3, int a4)
{
  return (*(int (__thiscall **)(int, _DWORD, int, int, _DWORD))(*(_DWORD *)dword_69B450 + 12))(
           dword_69B450,
           *(_DWORD *)(a2 + 992),
           a3,
           a4,
           this[74]);
}
```

Source-quality interpretation:

- `this` is an `AttachmentAnchorResolver *`.
- `a2` is the caller's map/render owner object, best supported as `MapPane *`.
- `a2 + 0x3e0` is the target surface field documented by MapPane docs as current `m_selectionOverlay`; the callee type is best supported as `AlphaMaskSurface *`.
- `a3` is `centerX`.
- `a4` is `centerY`.
- `this[74]` is field `0x128` / decimal `296`, best supported as `m_lightImageIndex`.
- `dword_69B450` is `g_pLightObjImageLib`.
- Vtable slot `+0x0c` / decimal `12` is `LightObjImageLib::DrawLightMode1`.

The decompiler's `int` return is not source-significant. The downstream light draw docs model the actual method as `void`, and both direct callers ignore the result. The source body should be emitted as `void`.

## Caller And Reachability Analysis

There are two supported direct callers. Both are MapPane render/paint paths and both call this helper only after the anchor bounds and anchor point have been resolved.

### Caller 1: MapPaneRenderViewCore

Documented owner:

- `by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md`
- File/class context: `MapPane`

Local `.lst` sequence:

```asm
.text:0050969D call sub_53C810
.text:005096A8 call sub_4B7CC0
.text:005096AB test al, al
.text:005096BE call sub_53C700
.text:005096C3 push [ebp+var_60]
.text:005096C8 push [ebp+var_5C]
.text:005096CB push ebx
.text:005096CC call sub_53C9C0
```

Interpretation:

- `sub_53C810` is the bounds helper in the same resolver family.
- `sub_4B7CC0` performs the visibility/intersection gate.
- `sub_53C700` resolves the final anchor point.
- The two coordinate pushes are the resolved anchor coordinates.
- `ebx` is the MapPane/render owner pointer passed as target helper argument.

This establishes that `0002TZ` is not an isolated raw fragment. It is part of a live MapPane render workflow.

### Caller 2: MapPanePaintLightingCore

Documented owner:

- `by-memory/0x0050a500-0x0050ab95.MapPanePaintLightingCore.md`
- File/class context: `MapPane`

Local `.lst` sequence:

```asm
.text:0050AA9F call sub_53C810
.text:0050AAAD call sub_4B7CC0
.text:0050AAB5 test al, al
.text:0050AABF call sub_53C700
.text:0050AAC4 push dword ptr [ebp-0Ch]
.text:0050AAC9 push dword ptr [ebp-8]
.text:0050AACC push dword ptr [ebp-2Ch]
.text:0050AACF call sub_53C9C0
```

The local `.c` export also shows a matching high-level call shape in the paint-lighting path:

```c
sub_53C9C0(v9, this, v161, v160);
```

Interpretation:

- The same sequence repeats: compute bounds, test intersection, resolve point, then apply light.
- The helper has two known direct callers.
- Both callers are MapPane-owned workflows.
- The helper is owned by the resolver class, not by MapPane itself, because the `this` pointer and `+0x128` light index field belong to `AttachmentAnchorResolver`.

### Reachability Conclusion

Reachability is strong:

- The target is a real function in local exports.
- It has two live direct code references.
- Its callers are already documented by-memory pages.
- Its callers are semantically aligned with attachment anchor rendering.
- The callsite ordering matches `AttachmentAnchorResolver` docs and B015's source-quality analysis of the neighboring resolver core.

No pointer-table-only or speculative reachability claim is required for this target.

## Raw / Helper Role Resolution

`0002TZ` should remain classified as a helper method, not as a raw thunk and not as an anonymous compiler helper.

Reasons:

- It has a modeled function start at `0x0053c9c0`.
- It has a normal `__thiscall` body and returns with `retn 0Ch`, matching three stack arguments plus `this`.
- It has two direct callers.
- The body is a compact source-shaped wrapper around a resolved virtual draw call.
- It reads an `AttachmentAnchorResolver` field, so it is not merely a global trampoline.

Best source role:

```text
Apply the already-resolved attachment anchor light to the MapPane's light/overlay target by delegating to LightObjImageLib::DrawLightMode1.
```

Rejected role: `LightingObjectPane` helper.

- The nearby preceding region is `LightingObjectPaneSetIntensity`, but this helper's field use and callers bind it to `AttachmentAnchorResolver`.
- The target is called from MapPane workflows after resolver bounds/point helpers.
- The target uses resolver field `+0x128`, not the LightingObjectPane state pattern.

Rejected role: MapPane method.

- Both callers are MapPane-owned, but `this` at the target is the resolver object.
- MapPane supplies only the draw target pointer source through argument `a2`.
- Source placement as a MapPane member would hide the resolver-owned light index field and would not match current owner/emitter routing.

Rejected role: LightObjImageLib method.

- The actual light library method is the virtual callee at slot `+0x0c`.
- This target is a caller/wrapper of the library, not the library implementation.

## Heuristic / Inference Reanalysis And Validation

This section revisits each previously weak inference and separates resolved evidence from remaining best-effort naming choices.

### Method Name

Candidates considered:

- `AttachmentAnchorResolver::ApplyLightAtAnchor`
- `AttachmentAnchorResolver::DrawLightAtAnchor`
- `AttachmentAnchorResolver::DrawLightMode1AtAnchor`
- `AttachmentAnchorResolver::ApplyLight`
- `AttachmentAnchorResolver::RenderLight`

Best-supported choice:

```cpp
void AttachmentAnchorResolver::ApplyLightAtAnchor(MapPane *mapPane, int centerX, int centerY);
```

Reasoning:

- Existing target title is `AttachmentAnchorApplyLight`.
- Existing class docs already describe the child as `ApplyLightAtAnchor` / light-table apply helper.
- The caller sequence computes bounds and anchor point first, so the helper does not resolve the anchor. It applies/draws at a resolved anchor.
- `ApplyLightAtAnchor` preserves the source role without overfitting to the virtual callee's internal draw-mode name.
- `DrawLightMode1AtAnchor` is mechanically precise but too implementation-specific for a resolver-level wrapper; mode 1 is a library detail.
- `RenderLight` is too broad and does not preserve the anchor role.

Remaining uncertainty:

- The exact original C++ symbol spelling is not available.
- This is not a blocker because all behavioral inputs and the callee target are resolved.

### Light Interface Meaning

Previously weak point:

- The target doc named only a generic light table slot `+0x0c`.

Resolved evidence:

- `dword_69B450` is documented as `g_pLightObjImageLib`.
- `LightObjImageLibVtable` maps slot `+0x0c` to `LightObjImageLib::DrawLightMode1`.
- `LightObjImageLibVtableData` provides the concrete vtable slot data at `0x0061b750-0x0061b768`.
- `LightObjImageLibDrawLightMode1` has first-draft C++ and calls `DrawFrameWithBlendMode(..., 1)`.
- `LightObjImageLibDrawLightMode2` maps the adjacent slot `+0x10` to blend mode 2, matching the adjacent raw twin.

Conclusion:

- Target `0002TZ` calls `g_pLightObjImageLib->DrawLightMode1(...)`.
- Adjacent raw twin `0002U0` calls `g_pLightObjImageLib->DrawLightMode2(...)`, but it is not caller-backed and should not be merged into this target.

### Compiler / Generated Name Assessment

The local IDA name `sub_53C9C0` is compiler/export-generated by the reverse-engineering tool and should not be preserved in source.

The source-facing name should be semantic:

```cpp
ApplyLightAtAnchor
```

No evidence supports a C runtime helper, STL helper, compiler thunk, or artificial wrapper classification. The function is a hand-written style game helper: it forwards resolver and MapPane state to the light renderer.

### Parameter Roles

Target function signature at the binary level:

```text
thiscall sub_53C9C0(this, a2, a3, a4)
```

Best source parameter roles:

```cpp
void AttachmentAnchorResolver::ApplyLightAtAnchor(MapPane *mapPane, int centerX, int centerY)
```

Mapping:

- `this`: `AttachmentAnchorResolver *`
- `a2`: `MapPane *mapPane`
- `a3`: `int centerX`
- `a4`: `int centerY`

Coordinate order:

- The helper pushes `arg_8` first, then `arg_4`, then the target surface, matching x86 right-to-left calling convention for the virtual call.
- The callee receives target surface, `arg_4`, `arg_8`, and light index.
- Therefore `arg_4` is the callee's first coordinate parameter and `arg_8` is the second coordinate parameter.
- Current `LightObjImageLibDrawLightMode1` docs name those `centerX` and `centerY`.
- The recommended wrapper signature therefore uses `(MapPane *mapPane, int centerX, int centerY)`.

### Field Names And Types

Resolved and best-supported fields:

| Binary storage | Decimal | Recommended source name | Type | Support |
| --- | ---: | --- | --- | --- |
| `this + 0x128` / `this[74]` | 296 | `m_lightImageIndex` | `int` | Used by target and by bounds helper as light-table/image index; B015 recommends this name. |
| `mapPane + 0x3e0` | 992 | `m_selectionOverlay` | `AlphaMaskSurface *` | Current MapPane docs name this field; target passes it to `LightObjImageLib::DrawLightMode1`. |
| `dword_69B450` | n/a | `g_pLightObjImageLib` | `LightObjImageLib *` | Dedicated singleton/global doc and LightObjImageLib file docs. |

Adjacent resolver fields from owner docs, relevant but not directly read by this target:

| Binary storage | Recommended source name | Role |
| --- | --- | --- |
| `this + 0x12c` | `m_localOffsetY` | Local Y offset used by resolver core. |
| `this + 0x130` | `m_localOffsetX` | Local X offset used by resolver core. |
| `this + 0x134` | `m_anchorSource` | Attachment/source mode used by resolver core. |

Light library support layout:

- `LightObjImageLib` owns the `LIGHT.TBL` derived light data.
- `LightInfo` row size is `0x1c` / decimal `28`.
- `LightInfo::generatedFrame` is at `+0x18` / decimal `24`.
- `LightObjImageLib` fallback/default entry is at `+0x14` / decimal `20`.
- `DrawLightMode1` and `DrawLightMode2` choose a light entry/fallback and draw a generated frame with blend mode 1 or 2.

MapPane `+0x3e0` caveat:

- The current documented source name is `m_selectionOverlay`.
- This target's use shows that the field is a valid `AlphaMaskSurface *` draw target for lighting.
- If future MapPane field review renames the member to a more light-specific overlay name, only the member spelling in the C++ draft should change. The target behavior and method body shape do not change.

### Global Names

Best-supported global:

```cpp
extern LightObjImageLib *g_pLightObjImageLib;
```

Support:

- `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md` resolves `dword_69B450` as the LightObjImageLib singleton/global pointer.
- The target reads exactly that global.
- LightObjImageLib constructor/destructor/singleton-clear docs cover lifecycle and reinforce the global's identity.

No additional new global is needed for this target.

### Caller / Reachability Inference

Resolved:

- Direct call at `0x005096cc` from `MapPaneRenderViewCore`.
- Direct call at `0x0050aacf` from `MapPanePaintLightingCore`.
- Both callers call `sub_53C810` and `sub_53C700` in the same sequence before the light apply helper.

Inference validation:

- The call sequence is consistent with attachment anchor rendering:
  - compute screen bounds,
  - test visibility/intersection,
  - compute anchor point,
  - apply light at anchor.
- The helper should not be promoted to the caller's owner because its `this` pointer is still the resolver object.

### Owner And Source Placement

Recommended canonical owner remains:

```text
UID:00000O AttachmentAnchorResolver
```

Recommended source route remains:

```text
auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp
```

Support:

- Current target owner/emitter is `00000O`.
- Current auto-generated row emits through `00000O`.
- `by-class/AttachmentAnchorResolver.md` already includes this helper in its method inventory.
- `by-file/AttachmentAnchorResolver.md` is the current root for the resolver helper family.
- The target's direct field read is an `AttachmentAnchorResolver` field.

Source-placement caveat:

- There remains a plausible original-source layout where the resolver was a private helper class or local support implementation inside `AttachedObjectPane.cpp`.
- That caveat belongs to file/source-tree placement, not to this target's implementation readiness.
- For current auto-generation, `AttachmentAnchorResolver.cpp` is the valid route and should be used unless the supervisor performs a wider file-root migration.

Rejected owner placements:

- `LightObjImageLib.cpp`: owns the virtual callee, not this wrapper.
- `MapPane.cpp`: owns callers and the target surface field, not this wrapper's state.
- `LightingObjectPane`: nearby memory only; field/caller semantics reject it.

### Split / Range Decisions

Current target range:

```text
0x0053c9c0-0x0053c9eb
```

Range length:

- `0x2b` bytes / decimal `43`, verified with `tools/int_convert.py`.

Boundary evidence:

- Function start at `0x0053c9c0`.
- Function epilogue and `retn 0Ch` at `0x0053c9e8`.
- Function end at `0x0053c9eb`.
- `0x0053c9eb-0x0053c9f0` is alignment padding before the adjacent raw twin.
- The adjacent twin at `0x0053c9f0` calls vtable slot `+0x10`, not slot `+0x0c`.

Decision:

- Keep `0002TZ` as its own exact helper method.
- Do not merge it with the preceding `LightingObjectPaneSetIntensity` region.
- Do not merge it with adjacent `0002U0`.
- Do not split it further.

Adjacent raw twin:

- `0002U0` is behaviorally related but remains raw/no-code because it lacks a modeled function object and direct xrefs in current docs.
- It may be described as a `DrawLightMode2` twin after light-library resolution, but this does not make it eligible for source emission.

### C++ Readiness Recheck

Current code-entry gate:

- Target `RECONSTRUCTABLE: TRUE`.
- Target has a nonblank emitter route to source through `UID:00000O`.
- Combined score average from current target header is `(85 + 87) / 2 = 86`, above the gate.
- The source route exists in auto-generated rows.
- The implementation body is a direct wrapper with resolved callee and resolved fields.

Conclusion:

- First-draft C++ is eligible.
- No exact no-code proof applies to `0002TZ`.
- No-code proof still applies to adjacent raw siblings where reachability/function-start evidence is missing.

## Recommended First-Draft C++

Recommended source body for `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp`:

```cpp
void AttachmentAnchorResolver::ApplyLightAtAnchor(MapPane *mapPane, int centerX, int centerY)
{
    g_pLightObjImageLib->DrawLightMode1(
        mapPane->m_selectionOverlay,
        centerX,
        centerY,
        m_lightImageIndex);
}
```

Required declarations/types, if not already present in the emitted source shard:

```cpp
class MapPane;
class LightObjImageLib;
class AlphaMaskSurface;

extern LightObjImageLib *g_pLightObjImageLib;

class AttachmentAnchorResolver {
public:
    void ApplyLightAtAnchor(MapPane *mapPane, int centerX, int centerY);

private:
    int m_lightImageIndex; // offset +0x128 in the recovered layout
};
```

Expected support signatures from existing docs:

```cpp
class LightObjImageLib {
public:
    void DrawLightMode1(AlphaMaskSurface *targetSurface, int centerX, int centerY, int lightIndex);
    void DrawLightMode2(AlphaMaskSurface *targetSurface, int centerX, int centerY, int lightIndex);
};

class MapPane {
    AlphaMaskSurface *m_selectionOverlay; // offset +0x3e0 in current docs
};
```

Notes for eventual implementation:

- Do not add null checks unless a wider source-style pass shows they existed elsewhere. The binary body does not branch.
- Do not return the callee result. The resolved light draw methods are source-modeled as `void`, and callers ignore any decompiler-propagated return value.
- Do not inline `DrawLightMode1` into this helper. The binary uses a virtual call through the global library object.
- Keep this method near the resolver anchor/bounds helpers in the same source shard.

## Exact Supervisor-Owned Coverage Row Text

Current exact row in `by-memory/-coverage-report.md`:

```text
    - [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) 0x0053c9c0-0x0053c9eb | helper method | AttachmentAnchorApplyLight : reconstructable : 82% : strong : Attached under `AttachmentAnchorResolver`; existing caller/decompile evidence keeps the light-table slot `+0x0c` helper with the anchor resolver family, documents the two live callers, `0x0053c810`/`0x0053c700` caller sequence, `this[74]`/`+0x128` table index, and blank final C++ while final method name/light table type remain open.
```

This row is stale relative to the current target header, which already says `COMPLETION: 85` and `CONFIDENCE: 87`.

Recommended replacement row after documentation/source update:

```text
    - [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) 0x0053c9c0-0x0053c9eb | helper method | AttachmentAnchorApplyLight : reconstructable : 88% : very-strong : B006 source-quality pass resolves the modeled helper as `AttachmentAnchorResolver::ApplyLightAtAnchor(MapPane *mapPane, int centerX, int centerY)`, called from MapPane render and paint-lighting paths only after `ComputeScreenBounds`/intersection and `ResolveAnchorPoint`; local IDA exports confirm the 43-byte `0x0053c9c0-0x0053c9eb` body loads `g_pLightObjImageLib`, passes `MapPane+0x3e0` / current `m_selectionOverlay`, the resolved anchor X/Y, and resolver `+0x128` `m_lightImageIndex` into LightObjImageLib vtable slot `+0x0c` / `DrawLightMode1`, while the adjacent raw `+0x10` twin remains separate/no-code due no function object/xrefs/pointer hits; owner/emitter stay `AttachmentAnchorResolver`, `LightingObjectPane` and MapPane caller ownership are rejected, and first-draft C++ is ready through `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp`.
```

## Target / Support Implementation Checklist

Target by-memory page `0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`:

- Update `COMPLETION` from `85` to `88`.
- Update `CONFIDENCE` from `87` to `90`.
- Keep `CANONICAL_OWNER: 00000O`.
- Keep `RECONSTRUCTABLE: TRUE`.
- Keep `EMITTER_UIDS: 00000O`.
- Fill the C++ section with the `ApplyLightAtAnchor` first-draft body.
- Replace generic "light-table slot +0x0c" wording with `LightObjImageLib::DrawLightMode1`.
- Name `dword_69B450` as `g_pLightObjImageLib`.
- Name `this[74]` / `+0x128` as `m_lightImageIndex`.
- Name the first stack argument as `MapPane *mapPane`.
- Use current MapPane field name `m_selectionOverlay` for `mapPane + 0x3e0`, with a small caveat if the MapPane field later receives a more light-specific name.
- Document the two direct callers and the `ComputeScreenBounds` / intersection / `ResolveAnchorPoint` / `ApplyLightAtAnchor` sequence.
- Document that the decompiler's `int` return is not source-significant and the source method should be `void`.
- Document the split decision that adjacent `0002U0` remains a separate raw no-code twin.

Coverage report:

- Replace the stale current `82%` row with the recommended `88%` row above.
- Keep indentation and link format exactly consistent with neighboring rows.

Auto-generated source:

- Emit the method in `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp` under the `UID:0002TZ` marker.
- Do not emit code for `0002U0` as part of this target.
- Include or forward-declare `MapPane`, `LightObjImageLib`, and `AlphaMaskSurface` only if the local generated shard does not already provide them.
- Use existing project naming style if a later pass has already introduced equivalent names. The behavioral mapping should remain unchanged.

AttachmentAnchorResolver class support:

- Update the method inventory entry to the exact recommended signature:
  - `void ApplyLightAtAnchor(MapPane *mapPane, int centerX, int centerY);`
- Keep neighboring resolver methods separate:
  - `ResolveAnchorPoint` for `0x0053c700-0x0053c92e`.
  - Bounds helper around `0x0053c810`.
  - Light apply helper at `0x0053c9c0-0x0053c9eb`.
- Prefer field name `m_lightImageIndex` over generic `m_lightIndex` because the same value indexes the light image/table data used by bounds and draw helpers.
- Preserve `m_localOffsetY`, `m_localOffsetX`, and `m_anchorSource` names from the current owner docs/B015 report.

AttachmentAnchorResolver file support:

- Keep current route under `NexusTK/map/AttachmentAnchorResolver.cpp` unless the supervisor performs a broader fold into `AttachedObjectPane.cpp`.
- If folded later, the method implementation remains the same; only source-file placement changes.
- Update file-level notes that the `+0x0c` light-table method is no longer unresolved.
- Keep the raw sibling caveat for `0002U0` and other raw starts.

LightObjImageLib support:

- No immediate LightObjImageLib doc/code change is required for this target.
- Existing support already resolves:
  - `g_pLightObjImageLib`
  - `LightObjImageLib::DrawLightMode1`
  - `LightObjImageLib::DrawLightMode2`
  - `LightObjImageLib::GetLightBounds`
  - `LightInfo`
  - `LightObjImageLib` vtable slots.
- If source emission order requires declarations, expose `DrawLightMode1` before compiling the resolver source.

MapPane support:

- No immediate MapPane code change is required for this target.
- `MapPane + 0x3e0` should remain documented as current `m_selectionOverlay` unless a dedicated MapPane field reanalysis renames it.
- The caller docs should cross-reference this helper as the final light-apply step after bounds/intersection/point resolution.

Raw sibling support:

- Keep `0002U0` no-code for now.
- It may be annotated as the `DrawLightMode2` twin of this helper, but it should not be emitted until function-start/reachability evidence improves.
- Keep `0002TX` and `0002TY` no-code unless direct xrefs/function starts are later established.

Validation checklist after eventual implementation:

- Confirm the generated source has exactly one `UID:0002TZ` body.
- Confirm no by-memory range merge occurred with `0002U0`.
- Confirm coverage row score and header score are no longer contradictory.
- Confirm no synthetic null check or return value was introduced.
- Confirm the caller-facing parameter order is `MapPane *mapPane, int centerX, int centerY`.
- Confirm the emitted body calls `DrawLightMode1`, not `DrawLightMode2`.

## Open Questions And Closure

Closed:

- The light-table global is resolved as `g_pLightObjImageLib`.
- The virtual slot `+0x0c` is resolved as `LightObjImageLib::DrawLightMode1`.
- The adjacent virtual slot `+0x10` is resolved as `LightObjImageLib::DrawLightMode2`.
- The resolver field `+0x128` is best named `m_lightImageIndex`.
- The first stack argument is best modeled as `MapPane *`.
- The `MapPane + 0x3e0` field is a valid `AlphaMaskSurface *` draw target for the light call.
- The owner is `AttachmentAnchorResolver`, not `LightingObjectPane`, MapPane, or LightObjImageLib.
- The target is source-eligible and does not require a no-code proof.

Still open but non-blocking:

- Exact original source spelling of `ApplyLightAtAnchor` is not symbol-proven.
- Exact final name for `MapPane + 0x3e0` remains owned by MapPane field review; current docs support `m_selectionOverlay`.
- Exact original file placement may have been a private helper inside `AttachedObjectPane.cpp`, but current project route is `AttachmentAnchorResolver.cpp`.
- Adjacent raw twin `0002U0` remains unresolved for reachability/source emission.

Open-question closure recommendation:

- Treat all non-blocking questions as naming/source-layout caveats, not as blockers for target C++ emission.
- Emit `0002TZ` now with the recommended first-draft body.
- Leave raw siblings untouched until they get direct function/reachability proof.

## Final Assessment

`UID:0002TZ` should move from "blank final C++ while light table type/name remain open" to "first-draft C++ ready." The current evidence supports a concise source wrapper:

```cpp
void AttachmentAnchorResolver::ApplyLightAtAnchor(MapPane *mapPane, int centerX, int centerY)
{
    g_pLightObjImageLib->DrawLightMode1(
        mapPane->m_selectionOverlay,
        centerX,
        centerY,
        m_lightImageIndex);
}
```

Recommended target score: `88/90`.

Recommended status: reconstructable, source-ready, owner/emitter unchanged.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002TZ-AttachmentAnchorApplyLight-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0002TZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
