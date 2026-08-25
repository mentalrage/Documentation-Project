** TARGET-REPORT-UID:0002TY **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002TY AttachmentAnchorScreenBoundsNotifyRaw Source-Quality Reanalysis

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality.md`

Target: [UID:0002TY] `source-3/project-documentation/by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md`

Assignment: `B004-goal2-attachment-anchor-screen-bounds-notify-raw-source-quality-0002TY-20260619`

No target/support `by-*` docs, generated files, or `by-memory/-coverage-report.md` were edited during this report pass.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002TY] as an exact raw `AttachmentAnchorResolver` child, keep `CANONICAL_OWNER:00000O`, keep `EMITTER_UIDS:00000O`, and keep the formal C++ block blank with a target-specific no-route/no-code proof.
- Recommended score: `85/87 -> 86/90`.
- Best descriptive source-facing role: `AttachmentAnchorResolver::QueueScreenBoundsForMapMotion()` / `NotifyScreenBoundsChanged()` as a raw no-entry helper. The more precise behavior is: when the active map pane's shadow/day-night overlay gate is active, compute this resolver's screen bounds and dispatch that rectangle to the active `MapPane` primary vtable slot `+0x20`, which resolves to `MapPane::QueueMotionMessage(const Rect *)`.
- Final disposition: source-authored project code-shaped byte island, but currently uncalled/unrouted in the executable's recoverable call graph. Treat it as retained raw evidence under the resolver, not as an independently emitted C++ method.
- Required action: update target/support docs with the resolved `g_activeMapPane`, `g_pConfig`, `MapPane::QueueMotionMessage`, `AttachmentAnchorResolver::ComputeScreenBounds`, and no-route proof. Do not edit `by-memory/-coverage-report.md` from the agent implementation pass; use the replacement row in this report for supervisor-owned coverage.
- Confidence: high for bytes, behavior, dependency names, owner family, range split, and no-route proof; medium for the exact original symbol spelling and why the compiler/linker retained this raw body.

## Target

- Target UID: `0002TY`
- Target path: `source-3/project-documentation/by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md`
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:00000O`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000O`, blank formal C++.
- Current generated coverage row:

```text
| [UID:0002TY][0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw](by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md) | emits | `00000O` | `00000O` |  | no | `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp` | `by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md` |  |
```

- Current supervisor-owned coverage row is stale relative to the target page score and the source-quality reanalysis below.

## Executive Recommendation

Keep the target attached to [UID:00000O] `AttachmentAnchorResolver`. The decisive ownership signal is the receiver: `ecx` is preserved as the resolver `this`, and the only class-local operation is `call 0x0053c810`, now supported by [UID:0001DH] and B015 reanalysis as `AttachmentAnchorResolver::ComputeScreenBounds(RectBounds *outBounds)`. The active map pane is a callee/notification target, not the owner of the helper.

The current target name `AttachmentAnchorScreenBoundsNotifyRaw` is acceptable and should not be churned unless the supervisor explicitly wants a more precise filename. The best source-facing descriptive name would be `AttachmentAnchorResolver::QueueScreenBoundsForMapMotion()` or `AttachmentAnchorResolver::NotifyScreenBoundsChanged()`. I prefer documenting the former as the behavior-specific name and retaining the existing file/title for low churn.

Do not populate target formal C++. The target passes the mechanical emitter/score gate, but the active source-quality gate still requires a defensible source entry route. Fresh PE checks find no function record, no direct rel32 call/jump to `0x0053c930`, no VA/RVA/raw-offset literal route, and no dword pointer/vtable/callback table entry in `.text`, `.rdata`, or `.data`. A formal method body would create an independent source API that the current binary evidence cannot prove. The raw body should remain documented as retained source-authored evidence under the resolver until a caller/table route appears.

## Supervisor Active Recheck

- Supervisor instruction required a report-only B004 source-quality pass. This report only creates the B004 research file.
- The assigned item does not require split repair. The exact body is one complete `0x4b`-byte code-shaped raw island at `0x0053c930-0x0053c97b`, with two bytes of `0xcc` pre-padding and five bytes of `0xcc` post-padding.
- The target is not a mixed aggregate. It should stay separate from the preceding modeled `AttachmentAnchorResolver::ComputeScreenBounds` range and from the following `LightingObjectPane::SetIntensity` method.
- Every source-bearing support child in scope already exists. No new by-memory child pages are needed.

## Evidence Standards Used

Evidence types checked:

- Current target/support documentation: target page, [UID:0001DH] modeled resolver/bounds page, [UID:00000O] resolver class, [UID:0000HL] resolver file, [UID:0000HJ] `AttachedObjectPane`, [UID:0000PR] `g_activeMapPane`, [UID:00028Q] `g_pConfig`, [UID:0002QG] `MapPane::QueueMotionMessage`, MapPane/Pane vtable data, and MapPane numeric constants.
- Prior B-agent report evidence used as leads, not authority: B015's [UID:0001DH] source-quality report and B002/B003 support updates for MapPane/Config/LightObjImageLib.
- Fresh raw PE validation from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Negative route evidence: direct rel32 scan, dword literal/pointer scan across `.text`, `.rdata`, and `.data`, and full-file VA/RVA/raw-offset pattern scan for the target start.
- Positive controls in the same PE scan: direct calls to `0x0053c810`, `0x0050ab40`, `0x0053c700`, `0x0053c9c0`, `0x0050ab70`, `0x004dfb40`, and `0x005386c0` were found, proving the route scan can find ordinary call edges.

No current IDA MCP tool was available in this environment. The report uses current local PE checks plus existing IDA-backed documentation. Where the report says "IDA-backed documentation", that means a by-* page records a prior IDA MCP result; where it says "fresh PE", that means B004 rechecked the bytes locally in this pass.

## Fresh PE Facts

Executable:

- Path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c600`, raw `0x00000400+0x20b600`
- `.rdata`: `0x0060d000-0x0066c200`, raw `0x0020ba00+0x5f200`
- `.data`: `0x0066d000-0x0069ce24`, raw `0x0026ac00+0x0d800`

Target and support byte facts:

| Range | File offset | Length | SHA-256 | Meaning |
| --- | ---: | ---: | --- | --- |
| `0x0053c930-0x0053c97b` | `0x0013bd30` | `0x4b` | `ff125bad5cf51aa783c8f7737a7bcc209f7b7bd01404236cd2c90f4b3da37c46` | target raw helper body |
| `0x0053c92e-0x0053c930` | `0x0013bd2e` | `0x02` | `e3966e3275be536a16092ec0cadf1638f718218e616fbbe8ff1c5e67fff4def2` | pre-target `0xcc` padding |
| `0x0053c97b-0x0053c980` | `0x0013bd7b` | `0x05` | `992cf51486f901aa1aa7d1f63e18c150c9156166e08e0b9e59cc3faf98177329` | post-target `0xcc` padding |
| `0x0050ab40-0x0050ab65` | `0x00109f40` | `0x25` | `c2d6ec09af1f91f7e35b09b35e71dab47cf477f5c045c178f0d5b0c694e1e1d5` | active-map shadow/day-night predicate |
| `0x0050ab70-0x0050ab95` | `0x00109f70` | `0x25` | `66b6af2636e04a15211d0707015759fa4bcea6939d805416a92627256f7bed82` | sibling inverse/alternate map-state predicate |
| `0x0053c810-0x0053c92e` | `0x0013bc10` | `0x11e` | `8250b3c1219d922b5fed6756dc495903467d2ce84109b5bec0ee47fc25c5569d` | `AttachmentAnchorResolver::ComputeScreenBounds` |

Target disassembly:

```asm
0053c930  push    ebp
0053c931  mov     ebp, esp
0053c933  sub     esp, 0x14
0053c936  mov     eax, dword ptr [0x672f24]
0053c93b  xor     eax, ebp
0053c93d  mov     dword ptr [ebp - 4], eax
0053c940  push    esi
0053c941  mov     esi, ecx
0053c943  mov     ecx, dword ptr [0x67a764]
0053c949  call    0x50ab40
0053c94e  test    al, al
0053c950  je      0x53c96c
0053c952  lea     eax, [ebp - 0x14]
0053c955  mov     ecx, esi
0053c957  push    eax
0053c958  call    0x53c810
0053c95d  mov     ecx, dword ptr [0x67a764]
0053c963  lea     edx, [ebp - 0x14]
0053c966  push    edx
0053c967  mov     eax, dword ptr [ecx]
0053c969  call    dword ptr [eax + 0x20]
0053c96c  mov     ecx, dword ptr [ebp - 4]
0053c96f  xor     ecx, ebp
0053c971  pop     esi
0053c972  call    0x5c772f
0053c977  mov     esp, ebp
0053c979  pop     ebp
0053c97a  ret
```

Predicate helper `0x0050ab40` disassembly:

```asm
0050ab40  movss   xmm0, dword ptr [0x61eac8]
0050ab48  comiss  xmm0, dword ptr [ecx + 0x3dc]
0050ab4f  jbe     0x50ab62
0050ab51  mov     eax, dword ptr [0x67a7c8]
0050ab56  cmp     byte ptr [eax + 0x28de5e], 0
0050ab5d  je      0x50ab62
0050ab5f  mov     al, 1
0050ab61  ret
0050ab62  xor     al, al
0050ab64  ret
```

This implements `return mapPane->dayNightOrOverlayScalar < 0.6f && g_pConfig->shadowEnabled != 0;` at the descriptive level. The exact source field name at `MapPane +0x3dc` remains provisional, but the role is day/night/overlay state and not an attachment-local field.

Route scan:

| Target | Direct rel32 E8/E9 hits in `.text` | Dword VA/RVA/raw pointer hits in `.text/.rdata/.data` |
| --- | --- | --- |
| `0x0053c6b0` raw sibling | 0 | 0 |
| `0x0053c700` resolver point method | 2: `0x005096be`, `0x0050aabf` | 0 |
| `0x0053c810` compute bounds | 10: `0x0050969d`, `0x0050aa9f`, `0x00537458`, `0x005375af`, `0x0053767c`, `0x0053784c`, `0x005381c6`, `0x005383b1`, `0x005384ec`, `0x0053c958` | 0 |
| `0x0053c930` target raw start | 0 | 0 |
| `0x0053c9c0` modeled light apply | 2: `0x005096cc`, `0x0050aacf` | 0 |
| `0x0053c9f0` raw sibling | 0 | 0 |
| `0x0050ab40` predicate | 10, including target call `0x0053c949` | 0 |
| `0x0050ab70` sibling predicate | 4 | 0 |
| `0x004dfb40` LightObjImageLib bounds | 1: `0x0053c82b` | 0 |
| `0x005386c0` attached-position helper | 7, including `0x0053c7d3` and `0x0053c8f9` | 0 |

Full-file 4-byte scans for target start route values:

- VA literal `0x0053c930`: 0 hits.
- RVA literal `0x0013c930`: 0 hits.
- raw-offset literal `0x0013bd30`: 0 hits.

These negatives are the basis for the formal no-code proof.

## Heuristic / Inference Reanalysis And Validation

### COM Method / Interface Names

No COM method/interface issue is present in this target. The body has a normal MSVC `thiscall` shape with a C++ virtual call through `g_activeMapPane`, not COM/IUnknown dispatch. No `QueryInterface`/`AddRef`/`Release`, GUID, interface vtable, or Browser COM helper is referenced. Any assignment wording that mentions COM is not applicable to [UID:0002TY].

### Raw Helper Role

Best inference: raw helper that queues/invalidates this resolver's screen rectangle on the active map pane when shadow/day-night overlay rendering is active.

Evidence:

- `esi = ecx` preserves the incoming receiver as the resolver.
- The body only performs the expensive rectangle calculation after `0x0050ab40(g_activeMapPane)` returns true.
- `0x0053c958` calls `AttachmentAnchorResolver::ComputeScreenBounds(RectBounds *outBounds)` with a local 16-byte rectangle at `[ebp-0x14]`.
- `0x0053c969` sends that same rectangle to `(*g_activeMapPane->vtable + 0x20)`.
- Fresh vtable parsing shows `MapPane` primary vtable base `0x0061e71c`, slot `+0x20` at `0x0061e73c`, target `0x005046d0`.
- [UID:0002QG] resolves `0x005046d0` as `MapPane::QueueMotionMessage(const Rect *)`, with first-draft C++ and vtable route evidence.

Rejected alternatives:

- Generic `Pane::InvalidateRect` as the direct target: rejected for a concrete `MapPane` receiver. The base `Pane` vtable slot `+0x20` is `0x00544800 Pane::InvalidateRect`, but `MapPane` overrides the same primary slot with `0x005046d0 MapPane::QueueMotionMessage`. The queue method may fall back to `InvalidateRect`, but the raw target dispatches to the MapPane override.
- Lighting method: rejected. The target neither reads `LightingObjectPane` fields nor calls `SetIntensity`; it calls the resolver bounds method and is separated from `0x0053c980` by `0xcc` padding.
- MapPane-owned helper: rejected. MapPane is the notification receiver and guard owner, but the source receiver and computed rectangle belong to the attachment anchor resolver.

### Placeholder Names And Best Descriptive Names

| Binary placeholder | Best current source-facing interpretation | Evidence and status |
| --- | --- | --- |
| `dword_67A764` | `g_activeMapPane` | [UID:0000PR] resolves this as the process-wide active `MapPane *`. Constructor/teardown and high-fanout xrefs support MapPane ownership. |
| `sub_50AB40` / `0x0050ab40` | `MapPane::IsShadowOverlayActive()` / `MapPane::ShouldUseShadowOverlay()` descriptive predicate | Reads `MapPane +0x3dc`, compares it against `0.6f` at `0x0061eac8`, and requires `g_pConfig +0x28de5e` `Shadow`/`showShadow`. Exact original name unproven, but the day/night shadow overlay role is strong. |
| `dword_67A7C8` | `g_pConfig` | [UID:00028Q] and project-level aliases resolve this global. Offset `+0x28de5e` is the `Shadow` graphics option byte. |
| `sub_53C810` / `0x0053c810` | `AttachmentAnchorResolver::ComputeScreenBounds(RectBounds *outBounds)` | [UID:0001DH] and B015 resolve the method. Fresh PE confirms the target call at `0x0053c958`. |
| `dword ptr [eax+0x20]` on `g_activeMapPane` | `MapPane::QueueMotionMessage(const Rect *)` | Fresh vtable dword parse: `0x0061e73c -> 0x005046d0`; [UID:0002QG] documents the method body and first-draft C++. |
| `[ebp-0x14]` | local `RectBounds` / `Rect` | 16-byte stack slot passed first to `ComputeScreenBounds`, then to `MapPane::QueueMotionMessage`. |
| `0x0061eac8` | MapPane numeric constant `0.6f` | [UID:0003J0] documents `0x0061eac8` among MapPane numeric constants. |
| `0x00672f24` and `0x005c772f` | MSVC security cookie and `__security_check_cookie` | Compiler-generated prologue/epilogue support; not source logic. |

### Field And Type Meanings

The target body itself directly touches no resolver fields, but its callee `0x0053c810` gives the dataflow meaning:

- `AttachmentAnchorResolver +0x128`: `m_lightImageIndex` / `m_lightIndex`, used by `LightObjImageLib::GetLightBounds` and light-table application.
- `AttachmentAnchorResolver +0x12c`: `m_localOffsetY`.
- `AttachmentAnchorResolver +0x130`: `m_localOffsetX`.
- `AttachmentAnchorResolver +0x134`: `m_anchorSource`, an `ObjectPane *`.
- Local rectangle: `RectBounds` with the conventional 16-byte `left, top, right, bottom` layout used by the rectangle helpers and `MapPane::QueueMotionMessage`.
- `MapPane +0x3dc`: day/night or overlay scalar checked by the shadow predicate. Existing MapPane docs group this with day/night lighting fields. Do not invent a final field name in the target; use descriptive wording such as `m_dayNightOverlayScalar` or `m_shadowOverlayScalar` until the MapPane field page finalizes the exact name.
- `g_pConfig +0x28de5e`: `Shadow` option, descriptive aliases `shadowEnabled` / `showShadow`.

### Caller / Reachability

The current reachability answer is not "unknown" in a passive sense. It is actively negative for known route types:

- no IDA function object recorded by existing docs;
- no direct code callers/xrefs recorded by existing docs;
- fresh PE finds zero `E8`/`E9` rel32 branches to `0x0053c930`;
- fresh PE finds zero VA/RVA/raw-offset literals for `0x0053c930`;
- fresh PE finds zero dword pointer hits to `0x0053c930` across `.text`, `.rdata`, and `.data`;
- no vtable/table/callback route is evident because pointer scans of `.rdata` are also zero.

That closes the current C++ readiness question: the body is reconstructable project code evidence, but formal output should stay blank until a future route is found.

### Owner / Source Placement

Direct owner remains `AttachmentAnchorResolver`:

- The method receiver is the resolver.
- The only class-local behavior is `ComputeScreenBounds` on that receiver.
- The active `MapPane` is a global receiver for the resulting rectangle, not the owner of the resolver's rectangle computation.

Source file placement:

- Current low-churn route: [UID:00000O] -> [UID:0000HL] `AttachmentAnchorResolver`, projected `NexusTK/map/AttachmentAnchorResolver.cpp`. Keep this route in metadata for now because it is already valid and avoids forcing a broad class/file migration during a report-only source-quality pass.
- Higher-probability original source placement: private helper/class inside [UID:0000HJ] `map/AttachedObjectPane.cpp`. B015's modeled resolver report and the `AttachedObjectPane` file page both support this: the resolver is a compact attached-overlay helper, has ObjectPane/AttachedObjectPane consumers, and lacks independent constructor/destructor/vtable evidence.
- Rejected owners: `MapPane`, `LightingObjectPane`, `ObjectPane`, `LightObjImageLib`, and generic global utility. Each is either a callee/consumer/dependency or memory neighbor, not the receiver/owner.

### Split / Range Decisions

Keep the target as the exact half-open range `0x0053c930-0x0053c97b`.

- `0x0053c92e-0x0053c930` is exactly two bytes of `0xcc`; this separates it from the preceding modeled `0x0053c810-0x0053c92e`.
- `0x0053c97b-0x0053c980` is exactly five bytes of `0xcc`; this separates it from [UID:0001DI] `LightingObjectPaneSetIntensity` at `0x0053c980`.
- The body has a complete prologue, security-cookie setup, conditional branch, callee sequence, cookie check, and `ret`.
- No split is needed inside the body. The guard, compute-bounds call, virtual dispatch, and epilogue form one helper.
- Do not merge this range into [UID:0001DH]. It calls `ComputeScreenBounds` but is separated by padding and has independent raw no-route status.
- Do not merge this range into [UID:0001DI]. The successor is a lighting method and has no dataflow into this helper.

### C++ Readiness

Formal C++ should remain blank. This is not due to an obsolete score threshold. It is a target-specific source-shape decision:

- The target's receiver and behavior are reconstructable enough to document.
- The body lacks any proven source entry route.
- Emitting a method such as `AttachmentAnchorResolver::NotifyScreenBoundsChanged()` would invent a callable source API not proven by the binary.
- The closest source behavior may already be duplicated/inlined in live ObjectPane/AttachedObjectPane call paths that call `0x0050ab40`, `0x0053c810`, and map invalidation/queue helpers directly.

Source-shape pseudocode for documentation only, not for the target's formal `RECONSTRUCTION_CPP CODE` block:

```cpp
// Do not emit for UID:0002TY until a route to 0x0053c930 is proven.
void AttachmentAnchorResolver::QueueScreenBoundsForMapMotion()
{
    if (!g_activeMapPane->IsShadowOverlayActive())
        return;

    RectBounds bounds;
    ComputeScreenBounds(&bounds);
    g_activeMapPane->QueueMotionMessage(&bounds);
}
```

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0053c700-0x0053c802` | part of [UID:0001DH] | `AttachmentAnchorResolver::ResolveAnchorPoint` | TRUE | `00000O` | `85/87`, B015 recommends `88/90` | modeled and caller-backed |
| `0x0053c810-0x0053c92e` | part of [UID:0001DH] | `AttachmentAnchorResolver::ComputeScreenBounds` | TRUE | `00000O` | `85/87`, B015 recommends `88/90` | modeled and caller-backed; callee of target |
| `0x0053c930-0x0053c97b` | [UID:0002TY] target | raw screen-bounds queue/notify helper | TRUE | `00000O` | recommend `86/90` | raw no-entry; no formal C++ |
| `0x005046d0-0x005047e8` | [UID:0002QG] | `MapPane::QueueMotionMessage(const Rect *)` | TRUE | `00007Q` | `87/90` | concrete vtable slot target called by [UID:0002TY] |
| `0x0050ab40-0x0050ab65` | part of [UID:00037W] | shadow/day-night overlay predicate | TRUE | `00007Q` via MapPane paint/lighting core | `86/90` aggregate | descriptive name only; callee of target |
| `0x0067a764-0x0067a768` | [UID:0001OW] / [UID:0000PR] | `g_activeMapPane` | TRUE | `0000L3` | global page `89/86` | global receiver for guard and queue call |
| `0x0067a7c8-0x0067a7cc` | [UID:00028Q] | `g_pConfig` | TRUE | `0000IE` | `86/90` | config pointer used by predicate |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0053c949` | target calls `0x0050ab40` | active map shadow/day-night predicate |
| `0x0053c958` | target calls `0x0053c810` | compute this resolver's screen bounds |
| `0x0053c969` | target calls `[g_activeMapPane->vtable +0x20]` | concrete `MapPane::QueueMotionMessage(const Rect *)` on current active map pane |
| `0x0061e73c` | MapPane primary vtable dword `0x005046d0` | proves concrete slot target for the target's virtual call |
| `0x0053c930` | zero rel32/pointer/VA/RVA/raw hits | no current route to raw helper start |
| `0x0053c810` | ten rel32 hits, including target `0x0053c958` | positive control and live compute-bounds use |
| `0x0050ab40` | ten rel32 hits, including target `0x0053c949` | positive control and shared MapPane overlay predicate |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page [UID:0002TY] already records no function object, no incoming refs, direct calls to `sub_50AB40` and `sub_53C810`, security-cookie handling, and virtual slot `+0x20`.
- [UID:0001DH] records `0x0053c810` as `ComputeScreenBounds` and caller spread, including the target call at `0x0053c958`.
- [UID:00000O] and [UID:0000HL] keep the raw target in the AttachmentAnchorResolver family and reject `LightingObjectPane`.
- [UID:0000PR] resolves `dword_67A764` to `g_activeMapPane`.
- [UID:00028Q] resolves `dword_67A7C8` to `g_pConfig` and names offset `+0x28de5e` as the `Shadow` option.
- [UID:0002QG] resolves MapPane primary vtable slot `0x0061e73c -> 0x005046d0` as `MapPane::QueueMotionMessage(const Rect *)`.
- [UID:0002SQ] `MapPaneVtableData` confirms the primary vtable layout containing `0x005046d0`.
- [UID:0003J0] documents the `0.6f` constant at `0x0061eac8`.

Existing docs that are stale or incomplete:

- The target behavior says "virtual slot `+0x20` on `dword_67A764`" but should now resolve the concrete slot as `MapPane::QueueMotionMessage`, with a note that base `Pane::InvalidateRect` is not the direct dispatch target for a `MapPane` object.
- The target still uses placeholders `dword_67A764`, `dword_67A7C8`, `sub_50AB40`, and `sub_53C810` in places where source-quality names are now available.
- The current coverage row still says `82%`, while the target metadata is `85/87` and this reanalysis recommends `86/90`.
- The target's old C++ blocker references the obsolete `90/90+` code-entry gate. Replace it with the target-specific no-route/no-code proof.

## Ranked Ownership Analysis

### 1. [UID:00000O] AttachmentAnchorResolver

Evidence for:

- Target receiver is `this` in `ecx`, preserved in `esi`.
- Only local class operation is `ComputeScreenBounds` on that receiver.
- The callee and sibling docs show shared resolver fields and behavior.
- Parent class/file already clear the assignment gate.

Evidence against:

- No direct caller proves an original method declaration.
- Original source may have folded the helper into `AttachedObjectPane.cpp`.

Decision: accept as direct semantic owner and current metadata route. The no-route issue blocks formal C++, not owner assignment.

### 2. [UID:0000HJ] AttachedObjectPane source file placement

Evidence for:

- `AttachedObjectPane.cpp` already groups attached overlay helpers and documents `AttachmentAnchorResolver` as shared attached-position/bounds support.
- ObjectPane/AttachedObjectPane call sites use the resolver in attachment lifecycle and map invalidation contexts.
- B015 found private `AttachedObjectPane.cpp` placement more probable than standalone original source.

Evidence against:

- Current route through [UID:0000HL] is already valid, has generated output, and avoids a multi-doc migration.
- No constructor/destructor/vtable proves an independent original class/file boundary either way.

Decision: document as the higher-probability original source placement, but do not change metadata in this target pass. Keep [UID:0000HL] as synthetic/current autogen root unless the supervisor chooses a later route migration.

### 3. [UID:00007Q]/[UID:0000L3] MapPane

Evidence for:

- `g_activeMapPane` is loaded twice.
- Guard and queue method are MapPane methods.
- MapPane owns the shadow/day-night predicate and `QueueMotionMessage`.

Evidence against:

- The method receiver is not MapPane.
- MapPane only consumes a computed rectangle supplied by the resolver.
- Moving this target to MapPane would split the resolver's screen-bounds behavior across callee/receiver ownership.

Decision: reject as direct owner. MapPane is a dependency/receiver and should be cross-linked.

### 4. [UID:0000KO] LightingObjectPane

Evidence for:

- Physical successor is `LightingObjectPane::SetIntensity` at `0x0053c980`.

Evidence against:

- There is five-byte padding before the successor.
- Target calls resolver bounds, not lighting intensity.
- The light/image dependency is through `ComputeScreenBounds` and `LightObjImageLib`, not `LightingObjectPane`.

Decision: reject. The adjacency is linker/source-layout noise.

### 5. ObjectPane / LightObjImageLib / generic utility

Evidence for:

- ObjectPane/AttachedObjectPane are consumers.
- `ComputeScreenBounds` depends on `LightObjImageLib::GetLightBounds`.

Evidence against:

- Target does not have an ObjectPane receiver.
- LightObjImageLib computes local bounds only; it does not own anchor translation or map queueing.
- Generic utility ownership is too broad and contradicted by the `this` receiver.

Decision: reject as direct owners.

## Negative Evidence Summary

Checked and rejected:

- Direct `E8`/`E9` call or jump route to `0x0053c930`: none.
- Dword pointer/table route in `.text`, `.rdata`, `.data`: none.
- Full-file VA literal `0x0053c930`: none.
- Full-file RVA literal `0x0013c930`: none.
- Full-file raw-offset literal `0x0013bd30`: none.
- Vtable route: none, because no pointer to the target start appears in `.rdata`.
- Merge with previous range: rejected by two-byte padding and independent no-route raw body.
- Merge with next range: rejected by five-byte padding and unrelated `LightingObjectPane` semantics.
- Formal C++: rejected because all known route types are negative and no source-level API shape is proven.

## First-Draft C++ / Exact No-Code Proof

[UID:0002TY] is mechanically eligible by `RECONSTRUCTABLE:TRUE`, nonblank emitter route, and average score above `85`, but should not receive formal C++ yet.

Exact no-code proof:

1. Existing IDA-backed docs report no function object at `0x0053c930`.
2. Existing IDA-backed docs report no `CodeRefsTo`, no `DataRefsTo`, and no loaded-segment dword pointer hits for `0x0053c930`.
3. Fresh B004 PE scan found zero direct `E8`/`E9` rel32 calls/jumps to `0x0053c930`.
4. Fresh B004 PE scan found zero dword VA/RVA/raw-offset hits for the target start in `.text`, `.rdata`, and `.data`.
5. Fresh B004 full-file scan found zero 4-byte literal hits for VA `0x0053c930`, RVA `0x0013c930`, and raw offset `0x0013bd30`.
6. Positive controls in the same scan found expected live rel32 calls to neighboring/support functions, including ten calls to `0x0053c810`, ten calls to `0x0050ab40`, and two calls to `0x0053c9c0`.
7. The target body has no vtable/table address route, so a formal source method would invent a callable API.

Recommended formal C++ state:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The target doc may include the pseudocode from the heuristic section as explanatory text, but not inside the formal reconstruction block.

## Open-Question Closure

| Prior/open issue | Closure |
| --- | --- |
| Final helper role | Resolved descriptively: compute resolver bounds and queue/notify them through active `MapPane::QueueMotionMessage` when shadow/day-night overlay predicate is true. |
| `dword_67A764` meaning | Resolved: `g_activeMapPane`, [UID:0000PR]. |
| `dword_67A7C8` meaning | Resolved: `g_pConfig`, [UID:00028Q]. |
| `sub_50AB40` meaning | Resolved descriptively as a MapPane shadow/day-night overlay predicate: `MapPane +0x3dc < 0.6f && g_pConfig->Shadow`. Exact original method name remains unproven but no longer blocks behavior docs. |
| Virtual slot `+0x20` | Resolved for concrete `MapPane`: `0x0061e73c -> 0x005046d0 MapPane::QueueMotionMessage(const Rect *)`. Base `Pane::InvalidateRect` is a fallback/callee of that method, not the direct target. |
| Caller/reachability | Closed as active no-route evidence for current scans. Future route evidence can reopen formal C++ readiness. |
| Owner/source placement | Direct owner remains `AttachmentAnchorResolver`; original file likely private `AttachedObjectPane.cpp`, while current synthetic [UID:0000HL] route remains acceptable for low-churn generated output. |
| Split/range | Exact range is correct; no split/merge needed. |
| First-draft C++ | No formal C++. Pseudocode is safe as explanatory text only. |

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly from B004.

Current supervisor-owned row at `by-memory/-coverage-report.md` line 2684:

```text
    - [UID:0002TY][0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw](by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md) 0x0053c930-0x0053c97b | raw helper method | AttachmentAnchorScreenBoundsNotifyRaw : reconstructable : 82% : strong : Attached under `AttachmentAnchorResolver`; live raw disassembly confirms `dword_67A764`, `sub_50AB40` guard, `sub_53C810` bounds producer, security-cookie handling, virtual slot `+0x20`, no incoming refs/pointer hits, boundary separation from LightingObjectPane, and blank final C++ while reachability/name remain open.
```

Recommended replacement row:

```text
    - [UID:0002TY][0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw](by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md) 0x0053c930-0x0053c97b | raw helper method | AttachmentAnchorScreenBoundsNotifyRaw : reconstructable : 86% : very strong : B004 2026-06-19 source-quality reanalysis keeps the raw child under `AttachmentAnchorResolver` but resolves the behavior as an unreferenced helper that computes `AttachmentAnchorResolver::ComputeScreenBounds(RectBounds *outBounds)` and dispatches the resulting rectangle through active `MapPane` vtable slot `+0x20`, which the concrete `MapPane` vtable maps to [UID:0002QG] `MapPane::QueueMotionMessage(const Rect *)`; fresh PE checks confirm exact `0x0053c930-0x0053c97b` body, two-byte prepad, five-byte postpad, `sub_50AB40` guard on `MapPane+0x3dc < 0.6f` plus `g_pConfig+0x28de5e` Shadow option, direct call to `0x0053c810`, security-cookie epilogue, zero rel32/VA/RVA/raw pointer routes to the raw start, and separation from `LightingObjectPane::SetIntensity`; formal C++ remains blank by target-specific no-route proof.
```

## Target / Support Implementation Checklist

### Target [UID:0002TY]

Apply these changes if the supervisor accepts the report:

- Metadata:
  - `COMPLETION:85 -> 86`
  - `CONFIDENCE:87 -> 90`
  - Keep `CANONICAL_OWNER:00000O`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:00000O`
  - Keep formal `RECONSTRUCTION_CPP` blank.
- Status/behavior:
  - Replace placeholder wording with `g_activeMapPane`, `g_pConfig`, `AttachmentAnchorResolver::ComputeScreenBounds`, and `MapPane::QueueMotionMessage`.
  - State that `0x0050ab40` is best described as a MapPane shadow/day-night overlay predicate using `MapPane +0x3dc`, constant `0.6f`, and `g_pConfig+0x28de5e` `Shadow`.
  - State that the concrete `MapPane` slot `+0x20` is not base `Pane::InvalidateRect`; it is `MapPane::QueueMotionMessage` at `0x005046d0`, which may itself call/invalidate through Pane infrastructure.
- Raw evidence:
  - Add fresh PE hash, file offset `0x0013bd30`, target SHA-256, pre/post padding bytes, and route-scan summary.
  - Preserve prior IDA-backed no-function/no-xref notes.
- Source-quality/no-code:
  - Replace obsolete `90/90+` gate wording with the target-specific no-route proof from this report.
  - Include pseudocode only outside the formal C++ block, clearly marked non-emitting.
- Range/split:
  - Keep filename and range unless the supervisor explicitly requests a rename.
  - Do not merge into [UID:0001DH] or [UID:0001DI].
- Changes section:
  - Add a `2026-06-19 B004 source-quality reanalysis` entry summarizing before/after score, resolved names, slot target, PE route scan, and blank C++ decision.

### Support [UID:00000O] `by-class/AttachmentAnchorResolver.md`

- Recommended score after synchronization: `86/90` or `87/90` depending on how much of B015's modeled-method report is also incorporated. Do not jump to `88/90` solely from this raw target.
- Update the raw screen-bounds helper method note to say it computes bounds and calls active `MapPane::QueueMotionMessage`, guarded by the shadow/day-night predicate.
- Add/refresh field wording for `m_lightImageIndex`, `m_localOffsetY`, `m_localOffsetX`, `m_anchorSource`, and local `RectBounds`.
- Document that raw helper reachability is actively negative, so the raw sibling remains no-code even though the modeled methods may be first-draft C++ ready through B015.

### Support [UID:0000HL] `by-file/AttachmentAnchorResolver.md`

- Keep the current synthetic route unless the supervisor chooses a broader migration.
- Update the proposed contents row for [UID:0002TY] to mention `MapPane::QueueMotionMessage` and the `g_pConfig` `Shadow` gate.
- Replace passive "raw reachability remains open" wording with "current PE/IDA route scans are negative; formal C++ remains blank until a route appears."
- Document that higher-probability original placement is private `AttachedObjectPane.cpp`, but current route remains valid for generated output.

### Support [UID:0000HJ] `by-file/AttachedObjectPane.md`

- Optional, not mandatory for this target-only implementation: add a small source-placement note that [UID:0002TY] strengthens the interpretation of `AttachmentAnchorResolver` as an attached-overlay helper that likely lived privately in `AttachedObjectPane.cpp`.
- Do not migrate metadata in the same pass unless the supervisor explicitly requests the route migration.

### Support MapPane / Config Docs

- [UID:0002QG] `MapPaneQueuedMotionMessage`, [UID:0002SQ] `MapPaneVtableData`, [UID:0000PR] `g_activeMapPane`, [UID:00028Q] `g_pConfig`, and [UID:0003J0] `MapPaneNumericConstants` already contain the necessary support facts. No required edits.
- If touched for cross-link polish, validate each individually, but this target can be implemented without modifying them.

### Supervisor-Owned Coverage

- Replace the exact [UID:0002TY] row in `by-memory/-coverage-report.md` with the replacement row in this report.
- Do not ask B004 to edit `by-memory/-coverage-report.md` while the ban remains active.

### Suggested Validation After Implementation

Run from `source-3/project-documentation` after by-* implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality-removed.md](0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `AttachedObjectPane.md` is touched:

> Executable block R002 was removed from this report and preserved verbatim in [0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality-removed.md](0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the coverage row:

> Executable block R003 was removed from this report and preserved verbatim in [0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality-removed.md](0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Validator Results

No validators were run because this was a report-only pass and no by-* documentation or coverage files were edited. The only intended changed file is this B004 research report.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality.md`
- Modified: none outside the B004 research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0002TY"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002TY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
