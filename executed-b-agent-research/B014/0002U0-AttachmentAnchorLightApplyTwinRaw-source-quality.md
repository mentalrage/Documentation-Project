** TARGET-REPORT-UID:0002U0 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B014 Source-Quality Report: UID 0002U0 AttachmentAnchorLightApplyTwinRaw

## Assignment

- Agent: B014.
- Assignment id: `B014-goal2-attachment-anchor-light-apply-twin-raw-source-quality-0002U0-20260619`.
- Target: [UID:0002U0] `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B014\research\0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md`.
- Mode: report-only. I did not edit any `by-*` target/support document and did not edit `by-memory/-coverage-report.md`.
- Supervisor active rule confirmed: B-agent source-quality reports must reanalyze heuristic/source issues, include exact coverage row text for supervisor-owned coverage work, and leave implementation to a later supervisor checklist.

## Target Summary

[UID:0002U0] covers the raw bytes at `0x0053c9f0-0x0053ca1b`. It is a complete thiscall-shaped helper body, but IDA does not model it as a function start and prior live checks found no code refs, data refs, or raw pointer encodings to the start address.

The helper is a near twin of [UID:0002TZ] `0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight`. The modeled sibling calls `g_pLightObjImageLib` virtual slot `+0x0c`; this target calls the same object virtual slot `+0x10` with the same argument shape:

```asm
0053c9f0  push    ebp
0053c9f1  mov     ebp, esp
0053c9f3  mov     edx, dword_69B450
0053c9f9  mov     eax, [ebp+8]
0053c9fc  push    esi
0053c9fd  push    dword ptr [ecx+128h]
0053ca03  mov     esi, [edx]
0053ca05  mov     ecx, edx
0053ca07  push    dword ptr [ebp+10h]
0053ca0a  push    dword ptr [ebp+0Ch]
0053ca0d  push    dword ptr [eax+3E0h]
0053ca13  call    dword ptr [esi+10h]
0053ca16  pop     esi
0053ca17  pop     ebp
0053ca18  retn    0Ch
```

Best source-quality result: resolve the previously vague `+0x10` "paired operation" as a dispatch to [UID:0002IX] `LightObjImageLib::DrawLightMode2`. The modeled sibling's `+0x0c` dispatch is [UID:0002IW] `LightObjImageLib::DrawLightMode1`. This target is therefore best described as an attachment-anchor light draw/apply mode-2 raw helper, still with raw-start reachability unresolved.

## Supervisor Active Recheck

- The current user explicitly assigned `0002U0`; this overrides the stale B014 notes handoff that still names an older `00010D` task.
- This is not a split-capable repair requiring by-memory child creation. The exact target already covers one raw body and the adjacent spans are documented padding.
- Source-bearing children in scope:
  - `0002U0` itself, raw helper body `0x0053c9f0-0x0053ca1b`.
  - Support sibling `0002TZ`, modeled helper `0x0053c9c0-0x0053c9eb`, needed only for role comparison.
  - Support LightObjImageLib method/type docs, needed to resolve slot names.
- No by-* edit was performed because the assignment is report-only.

## Evidence Sources Used

Direct target and immediate support docs:

- `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`
- `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`
- `by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md`
- `by-class/AttachmentAnchorResolver.md`
- `by-file/AttachmentAnchorResolver.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md`

Light library support docs:

- `by-global/g_pLightObjImageLib.md`
- `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md`
- `by-class/LightObjImageLib.md`
- `by-file/LightObjImageLib.md`
- `by-type/by-vtable/LightObjImageLibVtable.md`
- `by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md`
- `by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md`
- `by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md`
- `by-type/by-struct/LightObjImageLibLayout.md`
- `by-type/by-struct/LightInfo.md`

Ownership and source-placement checks:

- `by-file/AttachedObjectPane.md`
- `by-file/LightingObjectPane.md`
- `by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity.md`
- `by-file/SoundObjectPane.md`
- `by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md`
- `by-project-structure/proposed-source-tree.md`
- `project-level/-auto-completion-stats.md`
- `project-level/-resolved.md`
- `project-level/-unresolved.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp`

IDA MCP status for this report:

- I attempted current JSON-RPC MCP access at `http://127.0.0.1:13337/mcp` on 2026-06-19. Both `tools/list` POST and a TCP probe failed with `Unable to connect to the remote server` / `TcpTestSucceeded: False`.
- Therefore, this report does not claim a fresh live IDA session. It revalidates existing by-* live IDA evidence, previous documented IDA sessions, local generated coverage state, and current support-doc slot/type resolution.
- Prior documented live IDA sessions in the target/support docs are still useful evidence: 2026-06-03, 2026-06-06, 2026-06-14, 2026-06-16, and 2026-06-17 entries record exact function boundaries, raw-start non-function status, xref counts, slot targets, vtable data, and singleton references.

## IDA And Documentation Facts

### Raw Target Facts

- Target half-open range: `0x0053c9f0-0x0053ca1b`.
- Entity kind: raw helper island, not an IDA function object in prior live IDA checks.
- Body starts with a normal frame prologue at `0x0053c9f0`.
- Body reads `dword_69B450` at `0x0053c9f3`.
- Body reads the first explicit argument at `[ebp+8]`.
- Body pushes `[ecx+0x128]`, `[ebp+0x10]`, `[ebp+0x0c]`, and `[[ebp+8]+0x3e0]`.
- Body calls through the `g_pLightObjImageLib` vtable at slot `+0x10`.
- Body returns with `retn 0Ch`, proving three explicit stack arguments plus a `this` receiver in `ecx`.
- Existing target docs record no function object at `0x0053c9f0` or `0x0053ca1a`, no `CodeRefsTo`, no `DataRefsTo`, and no loaded-segment dword pointer hits for `0x0053c9f0`.

### Slot And Type Facts

- `dword_69B450` is resolved by current support docs as [UID:0000RD] `g_pLightObjImageLib`, a `LightObjImageLib*` singleton.
- [UID:0001XY] `LightObjImageLibVtable` maps:
  - `+0x0c -> 0x004dfbb0`, [UID:0002IW] `LightObjImageLib::DrawLightMode1`.
  - `+0x10 -> 0x004dfc60`, [UID:0002IX] `LightObjImageLib::DrawLightMode2`.
- [UID:00031S] exact vtable data confirms:
  - `0x0061b760 -> 0x004dfbb0`.
  - `0x0061b764 -> 0x004dfc60`.
- [UID:0002IW] and [UID:0002IX] first-draft C++ establish the virtual method signature shape:
  - `void LightObjImageLib::DrawLightMode1(AlphaMaskSurface *targetSurface, int centerX, int centerY, int lightIndex)`.
  - `void LightObjImageLib::DrawLightMode2(AlphaMaskSurface *targetSurface, int centerX, int centerY, int lightIndex)`.
- Therefore the raw target's argument order is best read as:
  - `targetSurface = *(arg0 + 0x3e0)`;
  - `centerX = arg1`;
  - `centerY = arg2`;
  - `lightIndex = this->field_128`.

### Boundary Facts

- `0x0053c9eb-0x0053c9f0` is documented as `0xcc` alignment between modeled helper `0002TZ` and this raw target.
- `0x0053ca1b-0x0053ca20` is documented as `0xcc` alignment between this raw target and [UID:0001DJ] `SoundObjectPaneCore`.
- `by-memory/-ignored.md` records both spans, along with related adjacent padding, as AttachmentAnchorResolver/LightingObjectPane/SoundObjectPane alignment padding.
- No split, merge, or range expansion is supported. The raw helper is already isolated exactly.

### Generated Output Facts

- `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp` currently contains an empty emitter marker for `0002U0`:
  - `// UID:0002U0 | by-memory\0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md | Completion:85 | Confidence:87 | Empty Emitter Marker`
- `auto-generated/-ag-memory-coverage.md` reports `0002U0` as emitting through canonical/emitter UID `00000O` to `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp`, with no code populated.
- The by-memory coverage row is stale at `82%` even though the target metadata and project-level stats now show `85/87`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0053c9f0-0x0053ca1b` | [UID:0002U0] `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md` | Raw thiscall-shaped helper dispatching `LightObjImageLib::DrawLightMode2` at an attachment anchor | TRUE | [UID:00000O] `AttachmentAnchorResolver` | `85/87` | Keep attached, no split, raw reachability remains unproven |
| `0x0053c9c0-0x0053c9eb` | [UID:0002TZ] `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md` | Modeled sibling dispatching `LightObjImageLib::DrawLightMode1` at an attachment anchor | TRUE | [UID:00000O] `AttachmentAnchorResolver` | `85/87` | Caller-backed comparison anchor |
| `0x0053c700-0x0053c92e` | [UID:0001DH] `by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md` | Modeled anchor point and bounds helpers | TRUE | [UID:00000O] `AttachmentAnchorResolver` | `85/87` | Owner/source context |
| `0x0061b750-0x0061b768` | [UID:00031S] `LightObjImageLibVtableData` | Exact vtable data proving `+0x0c/+0x10` draw slots | TRUE | [UID:0001XY] `LightObjImageLibVtable` | `88/92` | Slot-name support |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0053c9f0` | No function object and no start xrefs in recorded live IDA sessions | Raw helper is code-shaped but no live static entry route is known |
| `0x0053c9f3` | Data read of `dword_69B450` | Uses `g_pLightObjImageLib` singleton |
| `0x0053ca13` | Indirect call through `[g_pLightObjImageLib->vtable + 0x10]` | Calls `LightObjImageLib::DrawLightMode2` by current vtable docs |
| `0x0053c9c0` | Two recorded code refs at `0x005096cc` and raw/no-function callsite `0x0050aacf` | Modeled sibling is live and caller-backed |
| `0x0053c82b` | Only direct caller of `LightObjImageLib::GetLightBounds` | Confirms anchor resolver uses `g_pLightObjImageLib` local light-bounds data before draw helpers |
| `0x0061b764` | Vtable data ref to `0x004dfc60` | Confirms slot `+0x10` is `DrawLightMode2`, not an unknown manager operation |

## Heuristic / Inference Reanalysis And Validation

### Issue 1: Raw helper role and best descriptive name

Existing target state:

- Current title: `AttachmentAnchorLightApplyTwinRaw`.
- Existing behavior text called slot `+0x10` a paired light-manager operation, with final paired-operation name open.

Reanalysis:

- The body is not just a generic light-manager operation. Current LightObjImageLib vtable docs resolve the target slot:
  - `+0x0c` is `DrawLightMode1`.
  - `+0x10` is `DrawLightMode2`.
- The raw helper's argument order matches the source-facing draw signature documented by the exact draw-mode child pages.
- The sibling at `0x0053c9c0` has the same wrapper shape and calls `+0x0c`, so the target is the mode-2 twin of a live mode-1 attachment-anchor light draw wrapper.

Best-supported role:

- `AttachmentAnchorResolver` raw helper that draws/applies a light at an already resolved anchor point through `LightObjImageLib::DrawLightMode2`.

Best-supported descriptive names:

- Source-facing method candidate: `AttachmentAnchorResolver::ApplyLightMode2AtAnchor`.
- Alternate candidate if the project standardizes around drawing terminology: `AttachmentAnchorResolver::DrawLightMode2AtAnchor`.
- By-memory filename candidate if a later implementation chooses to rename: `0x0053c9f0-0x0053ca1b.AttachmentAnchorApplyLightMode2Raw.md`.
- Current filename `AttachmentAnchorLightApplyTwinRaw` is not wrong, but it is less source-quality precise because "Twin" hides the resolved `DrawLightMode2` slot.

Rejected alternatives:

- `AttachmentAnchorLightApplyTwinRaw` as final descriptive identity: acceptable as a stable lookup label, but inferior after slot resolution.
- `LightObjImageLibDrawLightMode2`: rejected as owner/filename because the target is only a wrapper/consumer. The actual draw-mode method is [UID:0002IX] at `0x004dfc60`.
- `LightingObjectPane` helper: rejected because `LightingObjectPane::SetIntensity` is separated by padding and has different fields/callers.
- `SoundObjectPane` helper: rejected because `SoundObjectPaneCore` starts after padding at `0x0053ca20` and has unrelated sound/timer state.

Remaining blocker:

- The original source spelling cannot be proven without debug symbols or a callsite. The names above are inferred/descriptive, not original-proof.

### Issue 2: `dword_69B450` placeholder

Existing target state:

- Target text still uses `dword_69B450` in many places.

Reanalysis:

- [UID:0000RD] and [UID:0001PR] resolve this as `g_pLightObjImageLib`, owned by `LightObjImageLib`.
- The global has constructor/destructor/shutdown evidence, 19 documented refs, and exact storage at `0x0069b450`.
- LightObjImageLib class/file docs and vtable docs are now above gate and strongly support the singleton identity.

Best-supported name/type:

- `g_pLightObjImageLib`, type `LightObjImageLib*`.

Rejected alternatives:

- `g_pLightObjectImageLib`: rejected as generated/Application-side alias pollution unless an address-confirmed legacy note is needed.
- Generic `dword_69B450`: keep only as historical IDA label/search alias.

Impact:

- Target and support docs should prefer `g_pLightObjImageLib` and mention `dword_69B450` only as the IDA/historical alias.

### Issue 3: `this+0x128` field meaning

Existing target state:

- Docs call this `this+0x128`, `this[74]`, or a resolver-local image/light table index.

Reanalysis:

- The field is passed as the final `lightIndex` argument to `LightObjImageLib::DrawLightMode1` in the modeled sibling and `DrawLightMode2` in this target.
- `0x0053c810` also passes the same field to `LightObjImageLib::GetLightBounds`, whose source-facing signature is `GetLightBounds(int lightIndex, RectBounds *outBounds)`.
- LightObjImageLib support docs establish that these methods select `LightInfo` rows loaded from `LIGHT.TBL`.

Best-supported field name:

- Within this target and the light draw/bounds context: `lightIndex`.
- If class-level docs need a more cautious field name because the resolver is an attached-overlay helper, use `anchorLightIndex` or `lightInfoIndex`.

Rejected alternatives:

- Plain `imageIndex`: too generic now that the callee is specifically `LightObjImageLib` and `LightInfo`.
- `tableIndex`: true but less source-facing and less tied to the documented `LightInfo` schema.

Remaining blocker:

- Original member spelling is not proven. This should cap final-audit confidence but should not block documenting the field role as `lightIndex`.

### Issue 4: `arg0+0x3e0` type/field

Existing target state:

- Target says the helper passes `*(arg0 + 0x3e0)`.

Reanalysis:

- `LightObjImageLib::DrawLightMode1/2` expects `AlphaMaskSurface *targetSurface` as its first explicit argument.
- Therefore `*(arg0 + 0x3e0)` is the target draw surface or alpha-mask surface pointer extracted from a map/render context object.
- The exact owner/type/name of the context object at `arg0` is not proven from this target alone.

Best-supported interpretation:

- `arg0` is a map/render draw context or pane-like render state object.
- `arg0+0x3e0` is an `AlphaMaskSurface*`/target surface field consumed by the light draw method.

Rejected alternatives:

- Treating `arg0+0x3e0` as a light record or `LightInfo` pointer: rejected because the callee's documented first argument is the target surface, while the light index is passed separately as the last argument.
- Naming the full context type as final source fact: rejected until broader map render context docs prove the type.

Impact:

- First-draft C++ can use a descriptive placeholder such as `drawContext->targetSurface`, but target/support docs should mark the field/type as inferred.

### Issue 5: Reachability and raw function status

Existing target state:

- The target already records no IDA function object, no xrefs, no raw pointer hits, and no modeled caller.

Reanalysis:

- I found no current local documentation contradicting this. The generated memory coverage and generated AttachmentAnchorResolver source only carry an empty emitter marker.
- Prior live sessions also checked `CodeRefsTo`, `DataRefsTo`, and raw pointer encodings.
- The modeled sibling has two callsites, which makes the lack of a parallel callsite for `0002U0` meaningful negative evidence rather than just "IDA did not name it."

Best-supported conclusion:

- The raw helper is source-shaped and probably source-authored or object-file-retained, but no live static entry route is currently proven.
- It should remain a raw child under `AttachmentAnchorResolver`, with reachability open and confidence capped below final.

Rejected alternatives:

- "Not reconstructable": rejected because the body is NexusTK project-code shaped, not padding/runtime/CRT, and it mirrors a live source helper.
- "Definitely dead code": rejected because no-xref static evidence cannot prove runtime impossibility in all callback/indirect/source-retention scenarios.
- "Promote to ordinary modeled method": rejected because IDA still has no function object and no caller route.

Impact:

- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `CANONICAL_OWNER:00000O`.
- Keep `EMITTER_UIDS:00000O` if the project policy intentionally emits empty markers for raw source-shaped children.
- Do not raise above current `85/87` until a live caller, callback slot, or pointer route is proven.

### Issue 6: Source owner and placement

Existing target state:

- Current owner/emitter: [UID:00000O] `AttachmentAnchorResolver`, emitting through [UID:0000HL] `AttachmentAnchorResolver.cpp`.
- `AttachmentAnchorResolver.cpp` may eventually fold into `AttachedObjectPane.cpp`.

Reanalysis:

- The direct callee owner, `LightObjImageLib`, does not own this wrapper. It owns the global singleton, vtable, draw methods, layout, and `LightInfo` records.
- The wrapper's `this+0x128` field and sibling relationship tie it to `AttachmentAnchorResolver`.
- [UID:0000HL] remains a reviewed standalone source root under `NexusTK/map/`, while [UID:0000HJ] `AttachedObjectPane.cpp` explicitly says the resolver may eventually fold there.
- That broader file-layout question does not change the direct semantic owner: the immediate owner is still the resolver class/helper.

Best-supported direct owner:

- `CANONICAL_OWNER:00000O` `AttachmentAnchorResolver`.

Best-supported emitted route for current docs:

- `EMITTER_UIDS:00000O`, then through [UID:0000HL] `AttachmentAnchorResolver` to `NexusTK/map/AttachmentAnchorResolver.cpp`.

Rejected alternatives:

- `LightObjImageLib`: callee/library owner, not wrapper owner.
- `LightingObjectPane`: adjacent earlier in memory, but separated by `0xcc` padding and unrelated caller/field evidence.
- `SoundObjectPane`: adjacent later in memory, but separated by `0xcc` padding and entirely different sound/timer state.
- `AttachedObjectPane` as direct owner: possible eventual source-file container, but not the narrow semantic owner of the method.

### Issue 7: Split/range/container decision

Existing target state:

- Exact raw helper body already split.

Reanalysis:

- Prior byte evidence and ignored ledger document the before/after padding.
- The body has a single prologue, one indirect call, one `retn 0Ch`, and no interior padding/table data.
- `SoundObjectPaneCore` starts at `0x0053ca20` after a five-byte `0xcc` gap.

Decision:

- No split, merge, container conversion, or range adjustment is recommended.
- Keep half-open range `0x0053c9f0-0x0053ca1b`.

### Issue 8: C++ readiness

Gate status:

- `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS:00000O` is nonblank and routes to generated `NexusTK/map/AttachmentAnchorResolver.cpp`.
- Score average is `(85 + 87) / 2 = 86`, greater than the current `>85` minimum gate.

Source-quality status:

- The callee slot is now resolved as `DrawLightMode2`.
- `g_pLightObjImageLib` and the `lightIndex` field role are strong enough for a first-draft recommendation.
- The target surface context at `arg0+0x3e0` remains inferred, and raw-start reachability remains unproven.

Decision:

- Include a first-draft C++ recommendation below because the target is technically eligible and the source body is compact enough to express.
- Do not raise confidence or call it final-source quality until reachability and the context field/type name are proven.
- If the supervisor is strict about raw no-xref helpers, it is also defensible to keep the formal target `RECONSTRUCTION_CPP CODE` block blank and use the draft only as implementation guidance. That is a policy choice; the source-shape evidence no longer blocks a draft by itself.

## Ranked Ownership Analysis

### 1. AttachmentAnchorResolver class/file

Evidence for:

- Same `this+0x128` light index used by `AttachmentAnchorResolver::ComputeScreenBounds` and the modeled light apply sibling.
- Immediate modeled sibling `0002TZ` is already caller-backed under `AttachmentAnchorResolver`.
- Class/file docs list the raw helper as a sibling and both direct parents are above the active assignment gate.
- `NexusTK/map/AttachmentAnchorResolver.cpp` is the current generated route.

Evidence against:

- No live caller to this raw start.
- Original source may have placed the helper privately inside `AttachedObjectPane.cpp` rather than a standalone `AttachmentAnchorResolver.cpp`.

Decision:

- Keep direct owner/emitter `00000O` `AttachmentAnchorResolver`. Treat standalone file placement as a broader source-tree caveat, not a direct-owner blocker.

### 2. LightObjImageLib

Evidence for:

- The raw helper reads `g_pLightObjImageLib`.
- The indirect callee is `LightObjImageLib::DrawLightMode2`.

Evidence against:

- The target does not implement draw-mode internals. It only extracts a target surface and coordinates, then dispatches into the light library.
- Actual LightObjImageLib draw methods have exact bodies at `0x004dfbb0` and `0x004dfc60`, with their own owner/emitter route through `render/LightObjImageLib.cpp`.

Decision:

- Reject as canonical owner. Use LightObjImageLib only as callee/type/global support.

### 3. LightingObjectPane

Evidence for:

- Memory adjacency before the modeled sibling and raw target.
- Related concept of map light objects.

Evidence against:

- `LightingObjectPane::SetIntensity` ends at `0x0053c9b5`; padding separates it from the light-apply sibling.
- `SetIntensity` has different live callers and fields (`+0x128` current intensity, `+0x134` binding pointer).
- The `0x0053c9c0` caller sequence goes through attachment bounds and anchor resolution, not `LightingObjectPane`.

Decision:

- Reject as owner.

### 4. SoundObjectPane

Evidence for:

- Memory adjacency after the target.

Evidence against:

- Five-byte `0xcc` padding separates the target from `0x0053ca20`.
- `SoundObjectPaneCore` owns constructor/destructor/playback/timer state and unrelated globals.
- Target body touches only `g_pLightObjImageLib`, anchor coordinates, and the resolver `+0x128` light index.

Decision:

- Reject as owner.

### 5. AttachedObjectPane

Evidence for:

- Attachment anchor resolver may eventually fold into `AttachedObjectPane.cpp`.
- Attached overlay source family uses anchor placement and screen-position helpers.

Evidence against:

- Existing direct class owner is more precise.
- `AttachedObjectPane.cpp` is broader file/grouping context, not the narrow method owner.

Decision:

- Keep as possible broad source-file container only. Do not replace direct owner with `AttachedObjectPane`.

## Negative Evidence Summary

Checked and rejected:

- Current MCP access: unavailable on 2026-06-19, so no new live xref scan could be added.
- Existing live target evidence: no function object, no `CodeRefsTo`, no `DataRefsTo`, no loaded-segment pointer hits for `0x0053c9f0`.
- Local docs and generated reports: no current caller was found for `0002U0`; generated output contains only an empty marker.
- SoundObjectPane adjacency: rejected by padding and unrelated state.
- LightingObjectPane adjacency: rejected by padding and different caller/field evidence.
- LightObjImageLib ownership: rejected because this target is a wrapper/consumer, while the real draw method is already separately documented.
- Split repair: rejected because the target has a single raw body and both neighboring gaps are documented alignment.

What would change the recommendation:

- A future live IDA pass finding a code ref, callback table entry, vtable/data pointer, or raw function-pointer encoding to `0x0053c9f0`.
- A source-layout pass proving `AttachmentAnchorResolver` should fold into `AttachedObjectPane.cpp`; that would change the by-file route, but not the direct semantic role of this helper.
- A broader map render context pass naming the `arg0+0x3e0` field/type.

## Open-Question Closure

| Prior open question | Closure status | Evidence and impact |
| --- | --- | --- |
| What is the slot `+0x10` operation? | Resolved descriptively | `LightObjImageLibVtable` and exact vtable data map `+0x10` to `LightObjImageLib::DrawLightMode2`. |
| Is `dword_69B450` still a placeholder? | Resolved | Use `g_pLightObjImageLib`; keep `dword_69B450` only as historical IDA alias. |
| What is `this+0x128` in this helper? | Best-inferred | It is the `lightIndex`/`lightInfoIndex` passed to LightObjImageLib bounds and draw methods. Original member spelling remains unknown. |
| Is the raw start reachable? | Still unproven, but reclassified as negative evidence not ownership blocker | Prior live IDA found no function object/xrefs/pointer hits; current generated output has only an empty marker. Cap confidence; do not detach. |
| Should this be owned by SoundObjectPane because it precedes SoundObjectPaneCore? | Closed rejected | `0x0053ca1b-0x0053ca20` is documented `0xcc` padding; SoundObjectPane body and globals are unrelated. |
| Should this be owned by LightObjImageLib? | Closed rejected | It calls the light library but stores/uses resolver-local state and belongs with the anchor wrapper family. |
| Should the range be split or merged? | Closed rejected | Exact raw body plus padding before/after; no interior mixed data. |
| Is first-draft C++ possible? | Yes, with caveats | Compact wrapper body and resolved vtable slot support a draft. Raw no-xref status and `arg0+0x3e0` naming keep it non-final. |

## First-Draft C++ Recommendation

This draft is source-facing and should be treated as inferred/descriptive. It is suitable for a supervisor implementation callback if the team accepts first-draft code for raw no-xref helper islands. It should not be used to raise the score above the current range until a caller/reachability route and context field name are proven.

```cpp
void AttachmentAnchorResolver::ApplyLightMode2AtAnchor(MapDrawContext *drawContext,
                                                       int centerX,
                                                       int centerY)
{
    g_pLightObjImageLib->DrawLightMode2(drawContext->targetSurface,
                                        centerX,
                                        centerY,
                                        lightIndex);
}
```

Required C++ caveats before formal insertion:

- `MapDrawContext` is a descriptive placeholder for the first explicit argument. The raw code only proves that the first draw argument is loaded from `arg0 + 0x3e0`.
- `targetSurface` is a high-probability field name because `DrawLightMode2` takes `AlphaMaskSurface *targetSurface`; the actual containing type/field name is not proven here.
- `lightIndex` is a high-probability field name for `this+0x128` in this target. If class-level naming stays cautious, use `lightInfoIndex` or `anchorLightIndex`.
- The helper has no proven caller, so the formal source should either be a private member/helper retained for binary parity or remain an empty marker until a caller route is found.

Lower-level draft if implementation policy requires no unproven struct field name:

```cpp
void AttachmentAnchorResolver::ApplyLightMode2AtAnchor(void *drawContext,
                                                       int centerX,
                                                       int centerY)
{
    AlphaMaskSurface *targetSurface =
        *reinterpret_cast<AlphaMaskSurface **>(
            static_cast<unsigned char *>(drawContext) + 0x3e0);

    g_pLightObjImageLib->DrawLightMode2(targetSurface, centerX, centerY, lightIndex);
}
```

I do not recommend the lower-level draft for final output because it is decompiler-shaped. It is included only to show the exact binary correspondence while the map draw context field name remains unresolved.

## Score And Metadata Recommendation

Current target metadata:

- `COMPLETION:85`
- `CONFIDENCE:87`
- `CANONICAL_OWNER:00000O`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000O`

Recommendation:

- Keep `COMPLETION:85`.
- Keep `CONFIDENCE:87`.
- Keep `CANONICAL_OWNER:00000O`.
- Keep `EMITTER_UIDS:00000O`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Do not raise above current scores until one of the following is proven:
  - a live caller/callback/data pointer route to `0x0053c9f0`;
  - exact map draw context type/field name for `arg0+0x3e0`;
  - final source-file layout for standalone `AttachmentAnchorResolver.cpp` versus private helper inside `AttachedObjectPane.cpp`.

Rationale:

- The source-quality pass improves naming and C++ readiness, but it does not add fresh live reachability or prove original source spelling. Current `85/87` is appropriate.

## Split / Range Decision

- Keep range `0x0053c9f0-0x0053ca1b`.
- Keep as a raw helper island.
- Do not merge with `0002TZ`; the `0x0053c9eb-0x0053c9f0` `0xcc` gap is real alignment.
- Do not merge with `0001DJ` SoundObjectPaneCore; the `0x0053ca1b-0x0053ca20` `0xcc` gap is real alignment.
- Do not create child pages.
- Do not create a container page.

## Exact Supervisor-Owned Coverage Row Text

Current exact row in `by-memory/-coverage-report.md`:

```text
    - [UID:0002U0][0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw](by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md) 0x0053c9f0-0x0053ca1b | raw helper method | AttachmentAnchorLightApplyTwinRaw : reconstructable : 82% : strong : Attached under `AttachmentAnchorResolver`; live raw disassembly confirms `dword_69B450`, virtual slot `+0x10`, `retn 0Ch`, paired argument shape with the modeled light-apply sibling, no incoming refs/pointer hits, SoundObjectPane separation, and blank final C++ while reachability/name remain open.
```

Recommended replacement row for supervisor-owned coverage update after implementation:

```text
    - [UID:0002U0][0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw](by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md) 0x0053c9f0-0x0053ca1b | raw helper method | AttachmentAnchorLightApplyTwinRaw : reconstructable : 85% : strong : Attached under `AttachmentAnchorResolver`; source-quality reanalysis resolves `dword_69B450` as `g_pLightObjImageLib`, virtual slot `+0x10` as `LightObjImageLib::DrawLightMode2`, and `this+0x128` as the resolver light index; keeps the exact raw no-function/no-xref helper range with `0xcc` padding before SoundObjectPane, rejects LightObjImageLib/LightingObjectPane/SoundObjectPane ownership, and preserves current confidence caps for raw reachability, draw-context `+0x3e0` field naming, and final source-file folding.
```

Placement context:

- Replace only the `UID:0002U0` row between the existing `0x0053c9eb-0x0053c9f0` ignored-padding row and the existing `0x0053ca1b-0x0053ca20` ignored-padding row.
- Do not edit `by-memory/-coverage-report.md` from this B014 report-only pass.

## Target / Support Implementation Checklist

For a later supervisor implementation callback, apply claim-by-claim rather than compressing this report.

Target doc `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`:

- Update behavior text so `dword_69B450` is identified as `g_pLightObjImageLib` / `LightObjImageLib*`.
- Update the slot description from generic `+0x10` paired operation to `LightObjImageLib::DrawLightMode2`.
- Preserve the raw disassembly and no-function/no-xref/pointer-hit evidence.
- Add or update source-quality wording:
  - best descriptive role `ApplyLightMode2AtAnchor` or `DrawLightMode2AtAnchor`;
  - `this+0x128` as inferred `lightIndex` / `lightInfoIndex`;
  - `arg0+0x3e0` as inferred `AlphaMaskSurface* targetSurface` field from a map/draw context;
  - reachability remains unproven and caps confidence.
- Add first-draft C++ only if the supervisor accepts raw no-xref helper emission. Use the source-facing draft above, not the lower-level `reinterpret_cast` form unless no named context field is acceptable.
- If formal C++ remains blank, document the exact reason: raw no-xref helper plus unresolved draw-context field/type naming, not obsolete score-gate wording.
- Keep metadata `85/87`, `CANONICAL_OWNER:00000O`, `EMITTER_UIDS:00000O`, `RECONSTRUCTABLE:TRUE`.

Support doc `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`:

- Update the modeled sibling description to identify virtual slot `+0x0c` as `LightObjImageLib::DrawLightMode1`.
- Clarify that `0002U0` is the slot `+0x10` / `DrawLightMode2` raw twin.
- Keep live caller evidence unchanged.
- Consider a future paired naming cleanup only if the supervisor accepts it:
  - `AttachmentAnchorApplyLight` -> mode-1 helper role in prose;
  - raw target -> mode-2 helper role in prose.

Support doc `by-class/AttachmentAnchorResolver.md`:

- In the method table, change "raw light-table twin helper" prose to "raw light-table mode-2 draw/apply helper" and mention `LightObjImageLib::DrawLightMode2`.
- In layout notes, strengthen `+0x128` from generic image/table index to `lightIndex` or `lightInfoIndex` for light-bounds/draw contexts, while preserving original spelling caveat.
- Preserve no-function/no-xref raw-start caveats.

Support doc `by-file/AttachmentAnchorResolver.md`:

- Same method-table update as the class page.
- Preserve standalone file versus possible `AttachedObjectPane.cpp` fold caveat.
- Do not move the direct owner to `AttachedObjectPane`; only mention it as possible broad source-file placement.

Support docs that likely do not need edits unless a supervisor wants extra cross-links:

- `by-type/by-vtable/LightObjImageLibVtable.md`
- `by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md`
- `by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md`
- `by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md`
- `by-global/g_pLightObjImageLib.md`

Supervisor-owned coverage:

- Apply the recommended replacement row above after the target/support implementation pass, if the accepted implementation matches this report.

Validation expected after implementation:

- Run scoped validator on each edited by-* file, for example:
  - `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md --apply`
  - Repeat for any edited sibling/class/file support docs.
- If a formal C++ block is inserted, check generated `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp` output after validator/autogen refresh.
- Do not ask B014 to edit `by-memory/-coverage-report.md`; supervisor owns that row.

## Final Recommendation

- Keep `0002U0` under [UID:00000O] `AttachmentAnchorResolver`.
- Keep the current exact range and raw helper classification.
- Update source-quality docs to resolve the callee slot as `LightObjImageLib::DrawLightMode2`.
- Prefer descriptive role/name `ApplyLightMode2AtAnchor` or `DrawLightMode2AtAnchor`; mark it inferred, not original-proof.
- Keep current score `85/87`; do not raise until raw reachability and draw-context field/type naming are proven.
- Include the first-draft source wrapper only after supervisor accepts the raw no-xref helper emission policy. Otherwise keep the formal block blank with the exact no-code reason above.
- Replace the stale coverage row `82%` with the `85%` row text in this report during supervisor-owned coverage maintenance.

## Validator Results

- No by-* files were edited, so I did not run target validators.
- I verified the report path did not already exist before creating it.
- IDA MCP was unavailable on `127.0.0.1:13337`; this is recorded as a current evidence limitation, not a target blocker.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B014\research\0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md`
- Modified: none outside this B014 research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"0002U0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
