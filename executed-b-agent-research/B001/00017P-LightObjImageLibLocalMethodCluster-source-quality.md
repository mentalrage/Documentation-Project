** TARGET-REPORT-UID:00017P **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00017P LightObjImageLibLocalMethodCluster Source-Quality Research

Assignment id: `B001-00017P-LightObjImageLibLocalMethodCluster-source-quality`  
Agent: `Agent-B001`  
Target: `[UID:00017P] source-3/project-documentation/by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/00017P-LightObjImageLibLocalMethodCluster-source-quality.md`  
Current target score: `83/89`

## Final Recommendation

Raise the target to `86/92`, keep it non-reconstructable, keep direct owner/emitter blank, and keep formal C++ blank:

```text
COMPLETION:86
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE: blank
```

This target is a local by-memory index over contiguous `LightObjImageLib` method bytes, not a source item that should emit its own code. The exact children now carry the reconstruction work:

- `0x004df7e0-0x004dfaa6` [UID:0002IU] `LightObjImageLibConstructor`: `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000KP] `LightObjImageLib`, first-draft C++ populated.
- `0x004dfab0-0x004dfb36` [UID:00017Q] `LightObjImageLibDestructor`: `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000KP], first-draft C++ populated even though the body is not an IDA-modeled function start.
- `0x004dfb40-0x004dfbb0` [UID:0002IV] `LightObjImageLibGetLightBounds`: `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000KP], first-draft C++ populated.
- `0x004dfbb0-0x004dfc5a` [UID:0002IW] `LightObjImageLibDrawLightMode1`: `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000KP], first-draft C++ populated.
- `0x004dfc60-0x004dfd0a` [UID:0002IX] `LightObjImageLibDrawLightMode2`: `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000KP], first-draft C++ populated.

The related tail pages are outside this target and should remain exact separate pages:

- `0x004e5bb0-0x004e5bbb` [UID:00017Z] `LightObjImageLibSingletonClearHelper`: attached to [UID:0000KP] but formal C++ blank as constructor/static cleanup glue.
- `0x004e65e0-0x004e669d` [UID:0002IY] `LightObjImageLibScalarDeletingDestructor`: attached to [UID:0000KP] but formal C++ blank as compiler scalar deleting destructor output over the ordinary destructor.

Best source placement for all hand-authored source bodies remains [UID:0000KP] `NexusTK/render/LightObjImageLib.cpp`. This parent should name that source file in prose as the covered class/file, but should not use it as `CANONICAL_OWNER` or `EMITTER_UIDS`; assigning the container would create duplicate coverage/emission over exact child pages.

## Report-Only Compliance

No target by-memory doc, support by-* doc, generated source, IDA database, validator state, or `by-memory/-coverage-report.md` file was edited. This report is the only intended changed file for this assignment.

I did not use or coordinate with A/C agents. Existing B001 reports were not modified.

Fresh binary evidence came from a read-only PE/Capstone scan of:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
MD5/SHA already documented by vtable support pages; local path length 2679296 bytes.
```

## Evidence Checked

Primary target and coverage docs:

- `source-3/project-documentation/by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md`
- `source-3/project-documentation/by-memory/-coverage-report.md`
- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
- `source-3/project-documentation/project-level/-auto-completion-stats.md`

Exact child/tail pages:

- `by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md`
- `by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md`
- `by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md`
- `by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md`
- `by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md`
- `by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md`
- `by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md`
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`

Class/file/type/global support:

- `by-file/LightObjImageLib.md`
- `by-class/LightObjImageLib.md`
- `by-type/by-vtable/LightObjImageLibVtable.md`
- `by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md`
- `by-type/by-struct/LightObjImageLibLayout.md`
- `by-type/by-struct/LightInfo.md`
- `by-global/g_pLightObjImageLib.md`
- `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md`
- `by-item/DrawFrameWithBlendMode_00462E10.md`
- `by-file/ProtectedArray.md`

Generated/current source leads:

- `source-3/simroot_v2/class_LightObjImageLib.cpp`
- `source-3/simroot_v2/class_LightObjImageLib.meta_wave3`
- `source-3/simroot_v2/class_Application.cpp`

Fresh local PE checks:

- Parsed PE headers and sections. Target bytes are in `.text` with image base `0x00400000`.
- Disassembled target child/tail ranges with Capstone.
- Extracted exact bytes for all padding spans around the local cluster and tail helpers.
- Read vtable/neighbor dwords at `0x0061b748-0x0061b76c`.
- Scanned the whole file for rel32 calls/jumps to target child starts and related tail starts.
- Scanned the whole file for absolute dword references to child starts, `g_pLightObjImageLib`, `LightObjImageLib` vtable, and adjacent `ProtectedArray<LightInfo>` vtable.
- Disassembled `0x004f4b10` and `0x0041b6c0` to resolve inherited vtable slot roles.

## Fresh Binary Findings

The target's lower-cluster bounds are correct. The previous broad `0x004df7e0-0x004e669d` aggregate would still be wrong because it crosses into NewHumanImageLib at `0x004dfd10`.

| Span | Size | Fresh PE result |
| --- | ---: | --- |
| `0x004df7d2-0x004df7e0` | `0x0e` | All `0xcc` padding after the preceding ItemObj helper; outside this target. |
| `0x004df7e0-0x004dfaa6` | `0x2c6` | Constructor body, 214 decoded instructions. |
| `0x004dfaa6-0x004dfab0` | `0x0a` | All `0xcc` padding. |
| `0x004dfab0-0x004dfb36` | `0x86` | Raw ordinary destructor body, 53 decoded instructions. |
| `0x004dfb36-0x004dfb40` | `0x0a` | All `0xcc` padding. |
| `0x004dfb40-0x004dfbb0` | `0x70` | `GetLightBounds`, 46 decoded instructions. |
| `0x004dfbb0-0x004dfc5a` | `0xaa` | Draw mode 1, 71 decoded instructions. |
| `0x004dfc5a-0x004dfc60` | `0x06` | All `0xcc` padding. |
| `0x004dfc60-0x004dfd0a` | `0xaa` | Draw mode 2, 71 decoded instructions. |
| `0x004dfd0a-0x004dfd10` | `0x06` | All `0xcc` padding before NewHumanImageLib. |
| `0x004dfd10` onward | n/a | NewHumanImageLib constructor prologue begins; not LightObjImageLib. |
| `0x004e5bb0-0x004e5bbb` | `0x0b` | Singleton clear helper: `mov dword ptr [0x69b450], 0; ret`. |
| `0x004e5bbb-0x004e5bc0` | `0x05` | All `0xcc` padding before next singleton-clear helper. |
| `0x004e65e0-0x004e669d` | `0xbd` | Scalar deleting destructor, 76 decoded instructions. |
| `0x004e669d-0x004e66a0` | `0x03` | All `0xcc` padding after scalar deleting destructor. |

Fresh rel32 route scan:

| Target | Rel32 refs found | Interpretation |
| --- | --- | --- |
| `0x004df7e0` | `0x004f6139` call | Startup constructs the singleton. |
| `0x004dfab0` | none | Raw ordinary destructor has no direct start ref; source identity comes from body/vtable/global parity. |
| `0x004dfb40` | `0x0053c82b` call | Attachment/object bounds consumer calls `GetLightBounds`. |
| `0x004dfbb0` | none | Draw mode 1 is reached through vtable data at `0x0061b760`. |
| `0x004dfc60` | none | Draw mode 2 is reached through vtable data at `0x0061b764`. |
| `0x004e5bb0` | `0x006001d0` jump | Constructor-associated cleanup chunk jumps to singleton clear helper. |
| `0x004e65e0` | none | Scalar deleting destructor is reached through vtable data at `0x0061b754`. |
| `0x004dfd10` | `0x004f60a1` call | Startup constructs NewHumanImageLib, proving the next cluster is separate. |

Fresh absolute dword scan:

- `0x004dfbb0` appears only at `0x0061b760`.
- `0x004dfc60` appears only at `0x0061b764`.
- `0x004e65e0` appears only at `0x0061b754`.
- `0x0069b450` appears 19 times, matching the documented singleton lifecycle/consumer set.
- `0x0061b754` appears at constructor/destructor/scalar-dtor vtable writes/restores: `0x004df83e`, `0x004dfabb`, `0x004e65ee`.
- `0x0061b74c` appears five times for the adjacent `ProtectedArray<LightInfo>` vtable: constructor, raw destructor, cleanup chunk, template destructor, and scalar deleting destructor.

Fresh vtable/neighbor dwords:

```text
0x0061b748 -> 0x006490ac  ProtectedArray<LightInfo> COL
0x0061b74c -> 0x004e61b0  ProtectedArray<LightInfo> scalar deleting destructor
0x0061b750 -> 0x0064900c  LightObjImageLib COL
0x0061b754 -> 0x004e65e0  LightObjImageLib scalar deleting destructor
0x0061b758 -> 0x004f4b10  inherited LObject runtime/type helper
0x0061b75c -> 0x0041b6c0  inherited/default no-op virtual
0x0061b760 -> 0x004dfbb0  LightObjImageLib::DrawLightMode1
0x0061b764 -> 0x004dfc60  LightObjImageLib::DrawLightMode2
0x0061b768 -> 0x006490f4  NewHumanImageLib COL, boundary
0x0061b76c -> 0x004e6870  NewHumanImageLib scalar deleting destructor
```

The shared inherited slot at `0x004f4b10` is not unresolved Light-specific code. Fresh bytes are:

```asm
004f4b10  mov eax, 0x61cf44
004f4b15  ret
```

`0x0061cf44` points to a small `LObject` runtime descriptor/name block that contains the wide string `LObject`. Sibling vtable docs already call this an inherited `LObject` runtime/type helper or runtime-class/name accessor. Light's vtable page should use the same wording instead of "currently unnamed."

The `nullsub_18` slot is also resolved enough for source-quality prose:

```asm
0041b6c0  ret 8
```

It is an inherited/default no-op virtual, not a LightObjImageLib method.

## Child Split Completeness

The current split is complete for this target. Every non-padding byte inside `0x004df7e0-0x004dfd0a` belongs to one of the five exact child pages. The only local gaps are the documented `0xcc` padding spans:

- `0x004dfaa6-0x004dfab0`
- `0x004dfb36-0x004dfb40`
- `0x004dfc5a-0x004dfc60`
- `0x004dfd0a-0x004dfd10`

The existing ignored coverage row also includes `0x004e669d-0x004e66a0`, which is tail padding after the separate scalar deleting destructor. That is fine as a shared LightObjImageLib alignment row, but it is not a reason to merge the scalar deleting destructor into the lower local cluster.

No new child page is needed under this target. The raw ordinary destructor already has [UID:00017Q], the bounds helper already has [UID:0002IV], and both virtual draw modes already have exact pages.

## Heuristic And Source-Inference Reanalysis

### Owner/source placement alternatives

1. Recommended: keep `00017P` as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, no emitter. It is a documentation/container index over child functions and padding. This avoids duplicate generated code and matches the current `auto-generated/-ag-memory-coverage.md` `not_reconstructable` route.
2. Rejected: attach the parent itself to [UID:0000KP] `LightObjImageLib`. The covered code is source-owned by that file, but exact child pages already own/emits those bodies. Assigning the aggregate would be a duplicate owner/emitter surface.
3. Rejected: make this a by-class source object. [UID:000076] `LightObjImageLib` already owns the class-level declaration/layout/vtable route. The memory range is an address-layout artifact, not a class declaration.
4. Rejected: merge with `0x004e5bb0` and `0x004e65e0`. Those are separate function islands after intervening NewHumanImageLib, template helpers, and singleton-helper islands. The old broad aggregate was explicitly overbroad.
5. Rejected: emit a parent "all methods" C++ block. That would duplicate child C++ and would mix hand-authored methods with compiler/static cleanup wrappers.

### Best source-facing final shape

The hand-authored source belongs in `NexusTK/render/LightObjImageLib.cpp`, with class/type support in the matching LightObjImageLib declarations. A first-draft declaration direction for support docs is:

```cpp
struct LightInfo {
    int tableId;
    int innerRadius;
    int radiusX;
    int radiusY;
    float brightness;
    float blendScale;
    AlphaMaskSurface *generatedFrame;
};

class LightObjImageLib : public LObject {
public:
    LightObjImageLib();
    virtual ~LightObjImageLib();

    void GetLightBounds(int lightIndex, RectBounds *outBounds);
    virtual void DrawLightMode1(AlphaMaskSurface *targetSurface,
                                int centerX,
                                int centerY,
                                int lightIndex);
    virtual void DrawLightMode2(AlphaMaskSurface *targetSurface,
                                int centerX,
                                int centerY,
                                int lightIndex);

private:
    ProtectedArray<LightInfo> lightInfoArray;
    LightInfo fallbackLightInfo;
};
```

This declaration is support/class direction only. It should not be pasted into the `00017P` parent C++ block. The child method pages already contain first-draft method bodies.

### Field/helper/type/global names

High-confidence current names:

| Binary/raw name | Recommended source-facing name | Confidence | Evidence |
| --- | --- | ---: | --- |
| `this+0x08` | `lightInfoCount` | high | Constructor initializes/counts; bounds/draw/destructors use count. |
| `this+0x0c` | `lightInfoEntries` | high | Constructor allocates `count * 0x1c`; methods index rows through it. |
| `this+0x10` | `lightInfoCapacity` | medium-high | Constructor seeds `10`; layout doc now prefers this over older `initialOrGrowCapacity`. |
| `this+0x14` | `fallbackLightInfo` | high | Out-of-range bounds/draw selection and constructor fallback constants. |
| row `+0x00` | `tableId` | medium-high | Loaded from `LIGHT.TBL`; no recovered runtime consumer, so exact original spelling remains bounded. |
| row `+0x04` | `innerRadius` | high | Passed to `FillEllipticGradient`; rejected old `lightSource`. |
| row `+0x08` | `radiusX` | high | Frame width and local bounds X radius. |
| row `+0x0c` | `radiusY` | high | Frame height and local bounds Y radius. |
| row `+0x10` | `brightness` | high | Converted through `brightness * 32.0f + 0.5f`. |
| row `+0x14` | `blendScale` | high | Passed as radial falloff/blend scale; rejected old `blendValue`. |
| row `+0x18` | `generatedFrame` | high | Created by constructor, consumed by bounds/draw, deleted by destructors. |
| `dword_69B450` / `unk_69B450` | `g_pLightObjImageLib` | high | Constructor publishes, destructors/helpers clear, consumers read. Reject generated `g_pLightObjectImageLib` alias as Application-side pollution unless the address is being discussed. |
| `sub_4DF7E0` | `LightObjImageLib::LightObjImageLib()` | high | Startup-only caller, singleton/vtable writes, `LIGHT.TBL` loader. |
| raw `0x004dfab0` | `LightObjImageLib::~LightObjImageLib()` | high | Vtable restore, generated-frame loop, entry free, singleton clear, LObject tail cleanup. |
| `sub_4DFB40` | `LightObjImageLib::GetLightBounds(int lightIndex, RectBounds *outBounds)` | high | One caller uses local bounds then translates; out-param semantics. |
| `sub_4DFBB0` | `LightObjImageLib::DrawLightMode1(...)` | high | Vtable slot, blend mode `1`, `DrawFrameWithBlendMode`. |
| `sub_4DFC60` | `LightObjImageLib::DrawLightMode2(...)` | high | Vtable slot, blend mode `2`, `DrawFrameWithBlendMode`. |
| `sub_4E5BB0` | `LightObjImageLibSingletonClearHelper` / `LightObjImageLib_ClearSingletonCleanup` | high behavior, medium exact spelling | No `this`, no callees, constructor cleanup jump, only clears singleton. No hand-authored API. |
| `sub_4E65E0` | `LightObjImageLibScalarDeletingDestructor` | high | Vtable slot `+0x00`, delete-flag branch, ordinary destructor parity. |
| `0x004f4b10` | inherited `LObject` runtime/type helper | medium-high | Returns `0x0061cf44` LObject descriptor/name block; shared by many `LObject`-derived vtables. |
| `0x0041b6c0` / `nullsub_18` | inherited/default no-op virtual | high behavior | Bytes are `ret 8`; shared broadly as default slot. |

### Rejected generated-output pollution

The active `source-3/simroot_v2/class_LightObjImageLib.cpp` is stale for this report's purposes:

- It still has only four active methods: constructor, draw mode 1, draw mode 2, scalar deleting destructor.
- It omits the raw ordinary destructor at `0x004dfab0`.
- It omits `GetLightBounds` at `0x004dfb40`.
- It emits scalar deleting destructor source even though the accepted policy is to emit cleanup through `~LightObjImageLib()` and leave the wrapper blank.
- It uses older field names such as `lightSource`, `blendValue`, and `imageFrame`; support docs now prefer `innerRadius`, `blendScale`, and `generatedFrame`.
- Its metadata still reports `vtable_count: 0`; the exact vtable data child and by-vtable page are the stronger evidence.

These are evidence leads, not authoritative source shape.

## Exact No-Code Proof For Parent

The parent should remain blank because:

1. It is not a function, object, table, type, or original source construct. It is an address-range index over exact source children plus padding.
2. Every non-padding byte inside the parent has an exact child page with its own ownership/emitter decision.
3. The five hand-authored local methods already emit through [UID:0000KP] `LightObjImageLib`.
4. The two related tail pages have different source-form policies: singleton clear helper is static/constructor cleanup glue, and scalar deleting destructor is compiler wrapper output.
5. Direct PE evidence finds no hidden aggregate entry point. Code refs target the constructor and bounds helper directly; draw/scalar paths come through vtable data; singleton helper comes through cleanup-jump glue.
6. Emitting aggregate C++ here would duplicate child code, hide the raw-destructor/child split, and risk reintroducing the old overbroad `LightObjImageLib` range crossing NewHumanImageLib.

## Open Questions And Attempted Resolution

| Question | Resolution |
| --- | --- |
| Should `00017P` have `CANONICAL_OWNER:0000KP` even if non-reconstructable? | No. The covered class/file is [UID:000076]/[UID:0000KP] and should be linked in prose, but the target itself should remain unowned/non-emitting as an index. Exact child pages already attach. |
| Are there missing child pages under `0x004df7e0-0x004dfd0a`? | No. Fresh bytes show only five bodies plus `0xcc` padding. The raw ordinary destructor and bounds helper already have exact pages. |
| Should the scalar deleting destructor be pulled into this target? | No. It is a separate function island at `0x004e65e0`, reached by vtable data, with intervening unrelated code. It should stay a related tail page. |
| Should `LightObjImageLibSingletonClearHelper` be emitted as a source helper? | No. It is a one-write cleanup helper reached from a constructor cleanup jump. Attach it for ownership, but leave C++ blank by generated/static cleanup policy. |
| Is `0x004f4b10` still an unresolved placeholder? | Not for this target. It is the shared inherited `LObject` runtime/type helper. Exact original header spelling belongs to the central LObject/vtable pass, not to LightObjImageLib. |
| Is `nullsub_18` still unresolved? | Its behavior is resolved as inherited/default no-op virtual (`ret 8`). Exact final method name is a central base-interface question. |
| Are `tableId`, `innerRadius`, `blendScale`, and `generatedFrame` final original names? | They are the best current source-facing names. `innerRadius`, `blendScale`, and `generatedFrame` are strongly dataflow-supported; `tableId` remains descriptive because no runtime consumer of row `+0x00` was recovered. |
| Should source C++ be first-drafted here? | No for this parent. Yes for exact child methods, and those child pages already have populated first-draft C++. |

## Recommended Target Doc Changes

In `by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md`:

1. Set metadata:

```text
COMPLETION:86
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

2. Keep `RECONSTRUCTION_CPP CODE` blank.

3. In Status, replace the confidence bullet with:

```text
- Confidence: very strong for exact child function boundaries, padding, vtable/global anchors, child-owned source routing, and the no-code aggregate policy; medium-high only for final original spelling of a few child/support field names that do not affect this parent container.
```

4. Add a short source-placement/no-code bullet:

```text
- Source-placement decision: [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) owns the source-authored constructor, ordinary destructor, bounds helper, and draw methods through exact child pages. This local cluster remains ownerless/non-emitting because it is an address-layout index, not a source declaration or function body.
```

5. In Evidence Notes, add a dated B001 local PE evidence subsection with these facts:

```text
2026-06-19 B001 local PE/Capstone recheck:
- Parsed `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` at image base `0x00400000`.
- Reconfirmed constructor `0x004df7e0-0x004dfaa6`, raw ordinary destructor `0x004dfab0-0x004dfb36`, `GetLightBounds` `0x004dfb40-0x004dfbb0`, draw mode 1 `0x004dfbb0-0x004dfc5a`, draw mode 2 `0x004dfc60-0x004dfd0a`, singleton clear helper `0x004e5bb0-0x004e5bbb`, and scalar deleting destructor `0x004e65e0-0x004e669d`.
- Reconfirmed `0x004dfaa6-0x004dfab0`, `0x004dfb36-0x004dfb40`, `0x004dfc5a-0x004dfc60`, `0x004dfd0a-0x004dfd10`, and `0x004e669d-0x004e66a0` as `0xcc` padding.
- Whole-file rel32 scan found only startup call `0x004f6139 -> 0x004df7e0`, bounds caller `0x0053c82b -> 0x004dfb40`, constructor-cleanup jump `0x006001d0 -> 0x004e5bb0`, and NewHuman startup call `0x004f60a1 -> 0x004dfd10`; draw/scalar routes are vtable-only.
- Vtable dwords remain `0x0061b754 -> 0x004e65e0`, `0x0061b758 -> 0x004f4b10`, `0x0061b75c -> 0x0041b6c0`, `0x0061b760 -> 0x004dfbb0`, and `0x0061b764 -> 0x004dfc60`, with `0x0061b768` starting NewHumanImageLib RTTI.
- `0x004f4b10` is the inherited `LObject` runtime/type helper returning `0x0061cf44`, and `0x0041b6c0` is an inherited/default no-op virtual (`ret 8`), not Light-specific unresolved code.
```

6. Replace Score Rationale with:

```text
Completion is `86` because the parent now records every local child body, every local padding span, the related tail pages, vtable/global anchors, the raw destructor status, constructor cleanup jump, direct caller routes, the NewHuman boundary, and the explicit no-code aggregate policy. Confidence is `92` because current support docs and a fresh local PE/Capstone scan agree on the split, source-owner route through exact children, no hidden aggregate entry point, and no remaining parent-level source blocker. Scores stay below final only because this page is intentionally an index and final original spellings for a few child/support names remain outside this target.
```

7. Add a `2026-06-19 B001 source-quality/no-code recheck` entry to Changes:

```text
- 2026-06-19 B001 source-quality/no-code recheck:
  - Recommended change: `83/89 -> 86/92`, keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank C++.
  - Summary/evidence: B001 rechecked target, exact child/tail docs, class/file/layout/LightInfo/vtable/global support, generated Wave3 output, current coverage rows, and a local PE/Capstone byte/xref scan. The lower cluster is complete and Light-only, exact child pages now carry source C++, related singleton/deleting tails stay separate, `0x004f4b10`/`nullsub_18` are inherited base slots, and the parent remains a non-emitting address-layout index.
```

## Recommended Support-Doc Updates

These are not required to change owner/emitter routing, but they should be folded into the later implementation pass if the supervisor accepts this report.

### `by-file/LightObjImageLib.md`

Score can stay `87/85` unless the implementer wants a confidence-only sync after the target update. Add a short dated note:

```text
2026-06-19 B001 local-cluster source-quality recheck confirms [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md) should remain a non-emitting ownerless index. The source-authored constructor, ordinary destructor, `GetLightBounds`, `DrawLightMode1`, and `DrawLightMode2` are already exact children emitted through this file; the singleton clear helper and scalar deleting destructor remain attached behavior evidence with blank formal C++ by cleanup-glue/compiler-wrapper policy.
```

### `by-class/LightObjImageLib.md`

Score can stay `86/86`. Update the Method Notes destructor row to link the exact child page instead of showing only bare `0x004dfab0`:

```markdown
| `LightObjImageLib::~LightObjImageLib` | [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md) | Raw ordinary destructor body; releases generated frames, frees the record array, clears the singleton, and tail-calls `LObject` cleanup. |
```

Add a dated note mirroring the parent no-code decision:

```text
2026-06-19 B001 recheck confirms the local method-cluster parent is not a source item. This class and [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) remain the semantic owners, while exact by-memory children carry method emission.
```

### `by-type/by-vtable/LightObjImageLibVtable.md`

Score can stay `88/92`. Replace the two inherited slot labels:

```markdown
| `+0x04` | `0x004f4b10` | inherited `LObject` runtime/type helper |
| `+0x08` | `0x0041b6c0` | inherited/default no-op virtual / `nullsub_18` |
```

Add evidence:

```text
2026-06-19 B001 local PE scan disassembled `0x004f4b10` as `mov eax, 0x61cf44; ret`; the returned descriptor points at the `LObject` name block. The same scan disassembled `0x0041b6c0` as `ret 8`. These are inherited base-interface slots, not LightObjImageLib-specific unresolved methods.
```

### `by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md`

Score can stay `88/92`. Update observed-content wording for `0x0061b758` and `0x0061b75c` to match the by-vtable page:

```markdown
| `0x0061b758` | slot `+0x04` | Points to inherited `LObject` runtime/type helper `0x004f4b10`. |
| `0x0061b75c` | slot `+0x08` | Points to inherited/default no-op virtual `0x0041b6c0` / `nullsub_18`. |
```

### `by-type/by-struct/LightObjImageLibLayout.md` and `by-type/by-struct/LightInfo.md`

No required metadata change. If touched, add no new uncertainty; keep the B003 names:

- `lightInfoCount`
- `lightInfoEntries`
- `lightInfoCapacity`
- `fallbackLightInfo`
- `tableId`
- `innerRadius`
- `radiusX`
- `radiusY`
- `brightness`
- `blendScale`
- `generatedFrame`

### `by-global/g_pLightObjImageLib.md` and `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md`

No required metadata change. If touched, add a short cross-check that the 2026-06-19 PE scan again found 19 absolute references to `0x0069b450` and preserves `g_pLightObjImageLib` over the generated `g_pLightObjectImageLib` alias.

## Exact Coverage Row Text

Do not edit `by-memory/-coverage-report.md` in this report-only pass. If the target metadata/prose is accepted, replace the current `00017P` parent row at line around 1859 with:

```markdown
    - [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md) 0x004df7e0-0x004dfd0a | class-method-cluster/index | LightObjImageLib local method cluster : not_reconstructable : 86% : very-strong : Non-emitting local split/index for the LightObjImageLib constructor, raw ordinary destructor, GetLightBounds, and two virtual draw-mode methods before NewHumanImageLib begins at 0x004dfd10; B001 2026-06-19 PE/Capstone recheck confirms exact child boundaries, `0xcc` padding, startup/bounds direct callers, vtable-only draw/scalar routes, constructor-cleanup jump to the singleton-clear helper, inherited `LObject` vtable slots, and that exact child pages and separate tail pages carry source ownership/emission while this cluster only records boundaries, padding, vtable/global anchors, and aggregate no-code policy.
```

Child rows under this parent already reflect B003 source-quality execution and do not need replacement for this assignment.

## Validation Commands Needed After Implementation

Run from `source-3/project-documentation` after the supervisor sends an implementation callback and the accepted by-* doc changes are applied:

> Executable block R001 was removed from this report and preserved verbatim in [00017P-LightObjImageLibLocalMethodCluster-source-quality-removed.md](00017P-LightObjImageLibLocalMethodCluster-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only after the supervisor applies or authorizes the coverage-row replacement:

> Executable block R002 was removed from this report and preserved verbatim in [00017P-LightObjImageLibLocalMethodCluster-source-quality-removed.md](00017P-LightObjImageLibLocalMethodCluster-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementer does not touch a support doc, skip that support-doc file-mode validator.

## IDA Rename/Type/Comment Recommendations

High confidence, already partly reflected in current docs/IDB:

- `0x004df7e0`: `LightObjImageLibConstructor` / source view `LightObjImageLib::LightObjImageLib()`.
- `0x004dfb40`: `LightObjImageLibGetLightBounds`; prototype `void __thiscall LightObjImageLib::GetLightBounds(int lightIndex, RectBounds *outBounds)`.
- `0x004dfbb0`: `LightObjImageLibDrawLightMode1`; prototype `void __thiscall LightObjImageLib::DrawLightMode1(AlphaMaskSurface *targetSurface, int centerX, int centerY, int lightIndex)`.
- `0x004dfc60`: `LightObjImageLibDrawLightMode2`; same prototype with mode 2.
- `0x004e65e0`: `LightObjImageLibScalarDeletingDestructor`; keep as compiler wrapper.
- `0x0069b450`: `g_pLightObjImageLib`.

Recommended if an IDA cleanup pass is allowed:

- Create/name a function at `0x004dfab0-0x004dfb36` as `LightObjImageLibDestructor` if IDA can do so without corrupting existing function-tail ownership. If not, add an anterior comment at `0x004dfab0` stating `raw LightObjImageLib::~LightObjImageLib body; no direct function-start xref; source body emitted through UID 00017Q`.
- Name/comment `0x004e5bb0` as `LightObjImageLibSingletonClearHelper` or `LightObjImageLib_ClearSingletonCleanup`; comment that it is constructor cleanup/static-lifetime glue, not a hand-authored public helper.
- Do not rename `0x004f4b10` to a Light-specific method. If a central LObject pass renames it, use a base name like `LObjectRuntimeTypeHelper` or `LObjectGetRuntimeClassDescriptor` only after confirming the wider vtable contract. Current bytes return the `LObject` descriptor/name block at `0x0061cf44`.
- Do not rename `0x0041b6c0` to a Light-specific callback. A central name like `LObjectDefaultNoOpVirtual` is behavior-accurate, but exact original name remains a base-interface question.
- Apply/keep `LightInfo` row fields: `tableId`, `innerRadius`, `radiusX`, `radiusY`, `brightness`, `blendScale`, `generatedFrame`.
- Apply/keep `LightObjImageLib` fields: `lightInfoCount`, `lightInfoEntries`, `lightInfoCapacity`, `fallbackLightInfo`.

## Implementation Readiness

The implementation callback is low risk:

- Update only the target metadata/prose and optionally the small support wording updates listed above.
- Do not add C++ to the parent.
- Do not change child C++ in this target's implementation unless the supervisor expands scope.
- Do not edit `by-memory/-coverage-report.md` directly; use the exact replacement row above.

The report resolves the parent-level blockers. Remaining non-final items are central/support questions, not blockers for `00017P`:

- exact original spelling of `tableId`;
- exact central base name for the inherited `0x004f4b10` runtime/type helper;
- exact central base name for the `ret 8` no-op virtual;
- future source-tree/header split between class declaration and `render/LightObjImageLib.cpp`.

## Changed Files

Only this report should be changed:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/00017P-LightObjImageLibLocalMethodCluster-source-quality.md
```

No by-* docs, coverage report, generated files, source files, validator files, or IDA database files were edited.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00017P-LightObjImageLibLocalMethodCluster-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"00017P"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00017P-LightObjImageLibLocalMethodCluster-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00017P-LightObjImageLibLocalMethodCluster-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00017P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
