** TARGET-REPORT-UID:0002I2 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002I2] MapPane Find Active Effect Source-Quality Report

Assignment: `B002-goal2-mappane-find-active-effect-source-quality-0002I2-20260617`  
Primary target: [UID:0002I2](../../../by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md) `0x00503e90-0x00503ecd.MapPaneFindActiveEffect`  
Report path: `tools/leaser/Agents/Agent-B002/research/0002I2-mappane-find-active-effect-source-quality.md`  
Mode: report-only. No by-* docs, generated files, source files, IDA DB, or coverage files were edited.

## Recommendation

Raise [UID:0002I2](../../../by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md) from `82/88` to `87/90`, keep `RECONSTRUCTABLE:TRUE`, keep owner/emitter [UID:00007Q][MapPane](../../../by-class/MapPane.md), and keep source placement through [UID:0000L3][MapPane](../../../by-file/MapPane.md) / `NexusTK/map/MapPane.cpp`.

The source-facing method should be documented as:

```cpp
ScreenEffecter *MapPane::FindActivePixelEffecter();
```

This is stronger than the current `FindActiveEffect` wording. The helper does not find any active screen effecter; it returns the first entry whose primary `ScreenEffecter` category predicate at vtable slot `+0x00` is true. In the currently configured list, that selects `XWaveEffecter` and skips `SolidColorFilterEffecter` / `WaterFilterEffecter`, so the best source-facing name is `FindActivePixelEffecter` or, if the project later rejects the exact `PixelEffecter` terminology, `FindActivePrimaryEffecter`. I recommend `FindActivePixelEffecter` because the [UID:0001YO][ScreenEffecterVtableFamily](../../../by-type/by-vtable/ScreenEffecterVtableFamily.md) and [UID:0000AI][PixelEffecter](../../../by-class/PixelEffecter.md) docs already use that branch name.

Field names should move from generic effect/object wording to:

| Offset | Recommended field | Evidence |
| --- | --- | --- |
| `MapPane +0x0f8` | `m_screenEffecterCount` | Count read by this helper and [UID:0002I1](../../../by-memory/0x00503e80-0x00503e8b.MapPaneHasEffectListEntries.md), written by configure/reset/clear. |
| `MapPane +0x0fc` | `m_screenEffecterCapacity` | Capacity written as `10` by [UID:0002I4](../../../by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md), cleared by reset/clear. |
| `MapPane +0x100` | `m_screenEffecters` | Pointer array read by this helper, allocated/filled by configure, freed by [UID:0002I6](../../../by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md). |

## Evidence Checked

- Existing docs checked: target page, sibling [UID:0002I1], [UID:0002I3], [UID:0002I4], [UID:0002I6], aggregate [UID:0001AP], [UID:00007Q][MapPane](../../../by-class/MapPane.md), [UID:0000L3][MapPane](../../../by-file/MapPane.md), [UID:0000PR][g_activeMapPane](../../../by-global/g_activeMapPane.md), [UID:00018W][Layer aggregate](../../../by-memory/0x004f0480-0x004f1bf6.Layer.md), [UID:0000KL][Layer](../../../by-file/Layer.md), [UID:0000IZ][Effects](../../../by-file/Effects.md), [UID:0000C9][ScreenEffecter](../../../by-class/ScreenEffecter.md), [UID:0001YO][ScreenEffecterVtableFamily](../../../by-type/by-vtable/ScreenEffecterVtableFamily.md), [UID:0002OR](../../../by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md), [UID:0001GE](../../../by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), [UID:0000GC][XWaveEffecter](../../../by-class/XWaveEffecter.md), [UID:0000DE][SolidColorFilterEffecter](../../../by-class/SolidColorFilterEffecter.md), and [UID:0000FZ][WaterFilterEffecter](../../../by-class/WaterFilterEffecter.md).
- Existing B reports searched in B001/B002/B003 research and executed folders for `0002I2`, `0x00503e90`, `MapPaneFindActiveEffect`, `FindActiveEffect`, `0x004f1286`, and `g_activeMapPane`. I found no executed report for this UID. Hits were contextual only, primarily `g_activeMapPane` usage in prior ScreenDimmer, EffectObj, and IconsPane reports.
- IDA MCP health: active IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready.
- IDA MCP `lookup_funcs` confirms `0x00503e90` is `sub_503E90`, size `0x3d`, and `0x004f1286` is inside `sub_4F0FF0`, size `0x39b`.
- IDA MCP decompilation of `0x00503e90` shows a signed loop over `this[62]`, pointer-array loads from `this[64]`, indirect call through vtable slot `+0x00`, return of the first matching pointer, and `0` on empty/no-match.
- IDA MCP `xrefs_to` confirms the only direct code xref to `0x00503e90` is `0x004f1286`, and the only direct code xref to [UID:0002I1] `0x00503e80` is `0x004f1277`.
- IDA MCP decompilation of `0x004f0ff0` confirms the Layer render traversal branch: after dirty-region checks, it checks `dword_67A764`, verifies the current pane pointer equals the active MapPane, calls `sub_503E80`, calls `sub_503E90(dword_67A764)`, and if non-null calls returned effecter vtable slot `+0x1c` instead of the normal `sub_4BA250` sprite/blit path.
- IDA MCP decompilation of `0x0055c1d0` confirms the `ScreenEffecter` aggregate predicate calls vtable slots `+0x00`, `+0x04`, and `+0x08` and returns true only when all three are false.
- IDA MCP decompilation of shared boolean virtual stubs confirms `0x0055c1b0` returns `1` and `0x0055c1c0` returns `0`.
- PE-aware scan confirms exactly one direct `E8` edge to `0x00503e90` at `0x004f1286`, exactly one direct `E8` edge to `0x00503e80` at `0x004f1277`, and no absolute-VA or RVA pointer hits for `0x00503e90` or `0x00503e80`.
- PE byte scan confirms `0x00503e8b-0x00503e90` is five `0xcc` bytes and `0x00503ecd-0x00503ed0` is three `0xcc` bytes. The target body bytes match the IDA-modeled `0x3d` range and the unique IDA signature produced by `make_signature_for_range`.

## Vtable / Type Resolution

The pointed object type is best resolved as `ScreenEffecter *`, not `EffectObjectPane *` or a generic object pane. The decisive evidence is the configure helper, which writes instances of [UID:0000GC][XWaveEffecter](../../../by-class/XWaveEffecter.md), [UID:0000DE][SolidColorFilterEffecter](../../../by-class/SolidColorFilterEffecter.md), and [UID:0000FZ][WaterFilterEffecter](../../../by-class/WaterFilterEffecter.md) into the same array.

The first virtual slot is a `ScreenEffecter` category predicate. PE slot parsing against `NexusTK.exe` gives:

| Class/table | Slot `+0x00` | Slot `+0x04` | Slot `+0x08` | Slot `+0x0c` | Slot `+0x1c` |
| --- | --- | --- | --- | --- | --- |
| `ScreenEffecter` `0x006235a4` | `false` | `false` | `false` | `0x0055c1d0` aggregate predicate | not an apply body |
| `PixelEffecter` `0x006235c4` | `true` | `false` | `false` | `0x0055c1d0` | base/no-op effect body |
| `XWaveEffecter` `0x00623c08` | `true` | `false` | `false` | `0x0055c1d0` | `0x0055b2d0` wave apply body |
| `SolidColorFilterEffecter` `0x006239ec` | `false` | `false` | `true` | `0x0055c1d0` | not the Layer branch target |
| `WaterFilterEffecter` `0x00623c50` | `false` | `false` | `true` | `0x0055c1d0` | not the Layer branch target |

Therefore [UID:0002I2] is not a generic active-effect scan. It is the MapPane-side finder for the first screen effecter that participates in the primary/pixel-effect render pass. The Layer caller then invokes slot `+0x1c` on that result to draw through the effecter-specific apply body. Filters are active screen effecters, but their first slot is false, so this helper intentionally skips them.

## Heuristic / Inference Reanalysis And Validation

Best defensible pointed type: `ScreenEffecter *`.

Evidence checked: sibling configure constructs `XWaveEffecter`, `SolidColorFilterEffecter`, and `WaterFilterEffecter`; sibling clear deletes stored entries through screen-effecter-family virtual cleanup; Effects and vtable docs tie those classes to `render/Effects.cpp`; PE slot parsing shows the exact slot-category values.

Rejected alternatives:

- `EffectObjectPane *`: rejected because `EffectObjectPane` is the animated sprite object pane at `0x005387b0-0x00538baa`, has separate vtable data around `0x006205f8`, and is created by MapPane packet/effect-object paths, not by [UID:0002I4].
- `ObjectPane *` or map object list entry: rejected because MapPane's object list is a separate subsystem around `MapPane +0x424`; this helper only touches `+0x0f8/+0x100` and the configure helper fills those slots with runtime effecters.
- `void *` / raw object wording: rejected because the vtable family and constructor call sites now identify the class family strongly enough for source-facing typing.

Best defensible first virtual predicate name: `ScreenEffecter::IsPixelEffecter()` as a descriptive category predicate. If a later whole-family Effects pass chooses a different naming scheme, `UsesPrimaryEffectPass()` is the best neutral fallback. Do not name it `IsActive()` in final docs: slot values are type/category constants, not per-instance liveness. Do not name it `IsComplete()`: the completion-style helper is slot `+0x0c` at `0x0055c1d0`, and it derives its result from slots `+0x00/+0x04/+0x08`.

Best defensible method name: `MapPane::FindActivePixelEffecter()`.

Rejected method-name alternatives:

- `FindActiveEffect`: too broad; it implies filters can be returned, but slot `+0x00` skips `SolidColorFilterEffecter` and `WaterFilterEffecter`.
- `FindActiveMapEffect`: still too broad and does not distinguish runtime `ScreenEffecter` objects from `EffectObjectPane` sprite effects.
- `FindActiveObject`: wrong subsystem; no object-list fields or `ObjectPane` vtables are used.

Best defensible field names: `m_screenEffecterCount`, `m_screenEffecterCapacity`, and `m_screenEffecters`. These are inferred source names, not original-name proof, but they are better than the current `effect/object` wording because the stored family is now identified.

Source placement: keep [UID:0002I2] under `MapPane`, not `Layer` and not `Effects`. Layer is the sole render-time consumer, but it does not own the fields or lifecycle. Effects owns the effecter class declarations and virtual methods, but MapPane owns the array and the policy for selecting which active map effecter replaces normal map blitting. The final source dependency direction should be `MapPane.cpp` including/using `ScreenEffecter` declarations from `render/Effects.h`.

Validation of existing docs:

- The target page's range, caller, fields, and padding were validated as correct.
- The target page's open question "pointed object type is not yet named" should be closed.
- The sibling configure/clear pages already contain the key object-family evidence and should be cross-updated to use `ScreenEffecter`/`m_screenEffecters` wording.
- The existing generated route in `auto-generated/-ag-memory-coverage.md` says this target emits to `auto-generated/NexusTK/map/MapPane.cpp`, but that file is currently zero bytes. Treat that as a generated-output caveat only; it does not change source placement or owner/emitter metadata.

Score/source-placement/final-C++ impact: resolving the type, vtable predicate, and method name justifies raising the target to `87/90`. It also clears the previous final-C++ blocker for this exact helper. The remaining uncertainty is original spelling of member/virtual names, not behavior, owner, range, or source placement.

## First-Draft C++ Recommendation

Populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:0002I2] with this draft after supervisor review. The previous blocker was the unresolved pointed type/predicate; that blocker is now resolved enough for source-quality C++.

```cpp
ScreenEffecter *MapPane::FindActivePixelEffecter()
{
    for (int index = 0; index < m_screenEffecterCount; ++index) {
        ScreenEffecter *effecter = m_screenEffecters[index];
        if (effecter->IsPixelEffecter()) {
            return effecter;
        }
    }

    return nullptr;
}
```

Notes for the supervisor:

- Do not add a null guard unless a broader source pass intentionally chooses safer source over binary shape. The binary dereferences each stored pointer before testing the predicate.
- `IsPixelEffecter()` is a descriptive source-facing name for vtable slot `+0x00`; it is not original-name proof.
- If the Effects-family pass later chooses `UsesPrimaryEffectPass()` or a similar name for slot `+0x00`, update this helper accordingly without changing its behavior.

## Support Docs To Update

Recommended supervisor-owned updates:

- [UID:0002I2](../../../by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md): raise to `87/90`; replace generic effect/object wording with `ScreenEffecter *` and `FindActivePixelEffecter`; add the Layer caller branch detail, PE edge/no-pointer evidence, vtable slot table, and first-draft C++ above.
- [UID:0002I1](../../../by-memory/0x00503e80-0x00503e8b.MapPaneHasEffectListEntries.md): replace "pointed object type unresolved" wording with "screen-effecter list count"; no score change required.
- [UID:0002I3](../../../by-memory/0x00503ed0-0x00503eef.MapPaneResetEffectListFields.md), [UID:0002I4](../../../by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md), and [UID:0002I6](../../../by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md): update field names to `m_screenEffecterCount`, `m_screenEffecterCapacity`, and `m_screenEffecters`; clarify that clear uses `ScreenEffecter` virtual deletion while configure stores the specific runtime effecter subclasses. No required score change unless the supervisor wants to lift [UID:0002I1] or [UID:0002I6] after applying the shared terminology cleanup.
- [UID:00007Q][MapPane](../../../by-class/MapPane.md) and [UID:0000L3][MapPane](../../../by-file/MapPane.md): add a short note in the weather/effects family that MapPane owns a runtime `ScreenEffecter` pointer array used by the Layer render traversal to find an active pixel-effecter.
- [UID:00018W][Layer aggregate](../../../by-memory/0x004f0480-0x004f1bf6.Layer.md): refine the `0x004f0ff0` render-traversal row to say the special branch calls `MapPane::FindActivePixelEffecter()` and then invokes the returned effecter's apply slot, rather than leaving it as a generic global-render branch.
- [UID:0000C9][ScreenEffecter](../../../by-class/ScreenEffecter.md) / [UID:0001YO][ScreenEffecterVtableFamily](../../../by-type/by-vtable/ScreenEffecterVtableFamily.md): optional note that MapPane consumes slot `+0x00` as the pixel/primary effecter predicate.

## Coverage Row

Replace the current [UID:0002I2] row in `by-memory/-coverage-report.md`, between the `0x00503e8b-0x00503e90` padding row and the `0x00503ecd-0x00503ed0` padding row, with:

```text
        - [UID:0002I2][0x00503e90-0x00503ecd.MapPaneFindActiveEffect](by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md) 0x00503e90-0x00503ecd | method | MapPaneFindActivePixelEffecter : reconstructable : 87% : strong : B002 2026-06-17 source-quality pass confirms exact finder boundary, sole Layer render-traversal caller at `0x004f1286`, unique PE direct edge/no pointer-table hits, MapPane screen-effecter list fields `+0x0f8/+0x0fc/+0x100`, and `ScreenEffecter` first-category/pixel-effecter predicate semantics from vtable slots; recommend source-facing `MapPane::FindActivePixelEffecter()` and formal C++ population.
```

No other coverage row change is required for this report unless the supervisor chooses to rescore sibling text-only cleanup.

## Validation Commands

Commands I used or recommend:

> Executable block R001 was removed from this report and preserved verbatim in [0002I2-mappane-find-active-effect-source-quality-removed.md](0002I2-mappane-find-active-effect-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA MCP checks used:

```text
server_health
lookup_funcs: 0x00503e90, 0x004f0ff0, 0x004f1286, 0x0055c1d0, 0x0055c1b0, 0x0055c1c0
decompile: 0x00503e90, 0x004f0ff0, 0x0055c1d0, 0x0055c1b0, 0x0055c1c0
xrefs_to: 0x00503e90, 0x00503e80, 0x0067a764, 0x0055c1b0, 0x0055c1c0, 0x0055c1d0
callees: 0x00503e90
make_signature_for_range: 0x00503e90-0x00503ecd
```

After applying supervisor-owned doc/coverage edits:

> Executable block R002 was removed from this report and preserved verbatim in [0002I2-mappane-find-active-effect-source-quality-removed.md](0002I2-mappane-find-active-effect-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Blockers And Follow-Up

No blocker prevents this target from clearing the `85/85` gate. The only remaining uncertainty is exact original spelling of `ScreenEffecter::IsPixelEffecter()` and the MapPane member names; the behavior, type family, owner/emitter route, and caller path are now strong enough for the recommended score and formal C++.

Useful follow-up work is a broader `ScreenEffecter` virtual-name pass that names the three category predicates at slots `+0x00/+0x04/+0x08` consistently across `PixelEffecter`, overlay effecters, and filter effecters.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002I2-mappane-find-active-effect-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002I2"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002I2-mappane-find-active-effect-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002I2-mappane-find-active-effect-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002I2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
