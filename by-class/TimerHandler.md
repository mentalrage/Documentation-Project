*** UID:0000F0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0004ZO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0004ZO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "TimerHandler.h"
#include "TimerMgr.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_TIMERHANDLER_H
#define NEXUSTK_UTIL_TIMERHANDLER_H

class TimerHandler
{
public:
    TimerHandler();
    virtual ~TimerHandler();
    virtual bool OnTimer(int timerId, int arg0, int arg1) = 0;

    void ScheduleTimer(int timerId, unsigned int delayMs, int arg0, int arg1);
    void RemovePendingTimers();
    void CancelTimer(int timerId);
    void CancelPendingTimersExceptEvent(int timerId);
};

typedef char TimerHandlerSizeMustBe4[sizeof(TimerHandler) == 4 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TimerHandler

## C134 Header Assembly Closure

The complete four-byte abstract interface is emitted once under `NEXUSTK_UTIL_TIMERHANDLER_H`. Exact constructor/destructor/wrapper bodies remain CPP children; removing the empty declaration-channel child token prevents the validator from materializing `[[No Children Attached]]` as invalid C++ while preserving every method declaration and the exact size assertion.

## Status

- Likely original source: [UID:0000OT][TimerMgr](by-file/TimerMgr.md), with possible tiny companion `TimerHandler.cpp`.
- Confidence: very strong for behavior, live boundaries, vtable/global anchors, destructor/wrapper caller evidence, source-ready callback body, and parent placement; capped below final-audit because exact original file split and disk spelling remain stripped-binary inferences.
- Parent attachment: [UID:0000OT][TimerMgr](by-file/TimerMgr.md) has a documented `NexusTK/util/` reconstruction path and owns the scheduler used by every `TimerHandler` wrapper.

## Responsibility

`TimerHandler` is the base class for objects that register timer callbacks with [UID:0000F1][TimerMgr](by-class/TimerMgr.md). Derived objects schedule events through thin helpers that forward to [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md), and destruction unregisters all pending events for the handler.

## UID000090 Separate Header And Source Closure - 2026-07-31

- Direct owner/emitter is now [UID:0004ZO][TimerHandler](by-file/TimerHandler.md), the explicit `NexusTK/util/TimerHandler.h/.cpp` source owner. Historical direct routing through UID0000OT remains superseded provenance.
- The complete H formal retains the abstract three-argument callback and four concrete wrappers and adds `TimerHandlerSizeMustBe4` for the exact fieldless one-vptr layout.
- The CPP formal includes both `TimerHandler.h` and complete `TimerMgr.h` before `[[CHILDREN]]`, making singleton manager calls source-legal without a partial manager declaration.
- This source split does not change any exact body range, vtable consequence, derived consumer, callback behavior, or manager scheduler/container ownership.

## MapPane Event-7 Consumer - 2026-07-28

- [UID:00042I][0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll](by-memory/0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll.md) demonstrates the intended inherited API shape. Complete `MapPane *` is accepted at the derived method boundary; the method converts to the TimerHandler facet at `+0xa4` only for the qualified `TimerHandler::CancelTimer(7)` call.
- This is dependency evidence, not ownership evidence. MapPane retains its own action-poll field, five direct callers, class declaration, and method definition, while TimerHandler retains the generic cancellation wrapper and scheduler ownership.
- The consumer does not change TimerHandler metadata (`89/91`), vtable shape, source-file uncertainty, wrapper signatures, or formal source disposition. It rejects only the decompiler-shaped alternative of inventing an embedded `m_timerHandler` member in MapPane.

## Callback Contract

The best-supported source-facing callback contract is a pure virtual bool-returning `OnTimer` method on `TimerHandler` with `timerId`, `arg0`, and `arg1` payload arguments. [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md) stores the timer id plus two payload dwords, dispatch copies the full record before virtual dispatch, and derived timer owners use the same three-explicit-argument callback shape. Keep `arg0` and `arg1` descriptive until caller-family semantics are recovered.

`by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md` is now settled as the retained out-of-line body for that pure virtual callback. Current MCP session `80de0a67` confirms the body bytes `b0 01 c2 0c 00`, the thirteen/eleven-byte padding fences, zero xrefs, zero VA/RVA/raw-offset pointer route, and `0x0062e33c -> __purecall`. Those facts are consistent: the base class remains abstract and the body is not vtable-installed, so the route absence means no live base dispatch path rather than no source ownership. Older [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) annotations that display `NewHumanImageLibGetHeadCount` are stale UID-collision annotations and are historicalized here.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00597570-0x00597579` | constructor | Installs the `TimerHandler` vtable. |
| `0x00597580-0x005975c3` | non-deleting destructor | Reinstalls vtable and unregisters this handler from `g_pTimerMgr`; IDA currently mislabels type as `boost::exception`. |
| `0x005975d0-0x005975d5` | `TimerHandlerOnTimerPureVirtualBody` (`by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md`) | Out-of-line body for the pure virtual TimerHandler callback; returns true, has no live xref/pointer route, and is consistent with the `__purecall` vtable slot because pure virtual definitions are not vtable-installed. |
| `0x005975e0-0x005975ff` | schedule wrapper | Forwards to `TimerMgr::ScheduleTimer` through `g_pTimerMgr`. |
| `0x00597600-0x0059760d` | unregister wrapper | Forwards to the same unregister-all path used by the destructor. |
| `0x00597610-0x00597626` | cancel event wrapper | Forwards targeted timer cancellation through `g_pTimerMgr`. |
| `0x00597630-0x00597646` | cancel-except wrapper | Forwards the alternate targeted removal helper through `g_pTimerMgr`. |
| `0x00597650-0x005976b3` | scalar deleting destructor | Unregisters and optionally deletes the object. |

## Evidence Notes

- 2026-06-04 live IDA MCP reports exact function ranges for constructor, destructor, callback-shaped helper, four wrappers, and scalar deleting destructor: `0x00597570-0x00597579`, `0x00597580-0x005975c3`, `0x005975d0-0x005975d5`, `0x005975e0-0x005975ff`, `0x00597600-0x0059760d`, `0x00597610-0x00597626`, `0x00597630-0x00597646`, and `0x00597650-0x005976b3`.
- 2026-06-30 B009 implementation of the accepted TimerMgr report raises this class route to `89/91`, adds the formal class marker plus `[[CHILDREN]]`, and corrects the local pure-callback reference to the current TimerHandler raw range/path. The `TimerHandler.cpp` versus `TimerMgr.cpp` disk split remains stripped-binary inference; this class still emits through [UID:0000OT][TimerMgr](by-file/TimerMgr.md) and exact child pages.
- Live IDA names the `TimerHandler` vtable at `0x0062e338`, with stores/xrefs at `0x00597570`, `0x005975a2`, and `0x00597675`; the first slot points to `0x00597650`, and the second slot is `__purecall`.
- 2026-06-23 B002 accepted implementation for [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) supersedes the older no-owner framing. Current MCP session `80de0a67` confirms `sub_5975D0` size `0x5`, bytes `b0 01 c2 0c 00`, disassembly `mov al, 1; retn 0Ch`, a three-explicit-argument true-return decompile, zero xrefs/callers/callees, zero data/code/immediate refs, no VA/RVA/raw pointer pattern, and no local PE direct branch/call route. The same pass confirms `0x0062e33c -> __purecall`, which now supports the pure virtual declaration plus out-of-line body model instead of contradicting ownership.
- 2026-06-23 B004 MCP session `ff68e691` remains valid as supporting evidence for the same bytes, padding, zero-route result, and pointer-search positive controls, but its no-owner/no-code conclusion is superseded by the B002 `80de0a67` source-quality repair.
- B004 positive controls for the pointer scan reached the expected data routes: `0x00597650` is present at `0x0062e338`, `0x00598090` is present at `0x0062e344`, static `TimerMgr` storage `0x0069b3ac` is present from startup/destruction references, and [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) has the expected broad hits. The negative `0x005975d0` result is therefore a real route absence, not a broken scan.
- [UID:0003E0][0x0062e334-0x0062e340.TimerHandlerVtableData](by-memory/0x0062e334-0x0062e340.TimerHandlerVtableData.md) now documents the exact `0x0062e334-0x0062e340` RTTI-adjacent vtable-data child with the same first-slot and constructor/destructor-store evidence.
- Constructor has seven direct call sites. The non-deleting destructor has 15 direct callers. The schedule wrapper at `0x005975e0` has 163 direct callers, the unregister wrapper at `0x00597600` has 45, the targeted cancel wrapper at `0x00597610` has 47, and the alternate cancel wrapper at `0x00597630` has one.
- Live decompilation shows every wrapper loads [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) at `0x0067ab80` and forwards to the scheduler helper family (`0x00597910`, `0x00597a10`, `0x00597b80`, or `0x00597ca0`).
- 2026-06-23 B004 MCP session `ff68e691` rechecked [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) specifically. `lookup_funcs` confirms `sub_5975E0` size `0x1f` / 31 and `sub_597600` size `0x0d` / 13 (Verified with int_convert.py), with no functions at the `0x005975ff` separator or `0x0059760d` end fence. Bytes confirm eleven `0xcc` bytes before the schedule wrapper, the 31-byte schedule forwarder, one `0xcc` separator, the 13-byte remove-owner forwarder, and three `0xcc` bytes before the next wrapper page. The schedule wrapper pushes four explicit arguments plus `this`, loads `g_pTimerMgr` from `0x0067ab80`, calls current manager helper `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md`, and returns with `retn 10h`; the remove wrapper pushes `this`, loads the same singleton, and calls current owner-removal helper `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`. Current profiles show 163/122 schedule callers and 45/30 remove callers, while data-xref checks and VA/RVA/raw-offset pointer-pattern searches find no table, vtable, or pointer route to either wrapper entry. Older [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md)/[UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md) NewHumanImageLib/VectorGrow display names are stale UID-collision annotations.
- Keep the [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) wrapper C++ source-shaped as `void TimerHandler::ScheduleTimer(...)` and `void TimerHandler::RemovePendingTimers()` even though Hex-Rays prints raw `int __thiscall` signatures. The raw `int` is caused by manager-return propagation in `EAX`; the wrapper methods perform schedule/remove side effects and do not compute a wrapper status. Exact original public names, return-type proof, and the final `TimerHandler.cpp` versus `TimerMgr.cpp` split remain documented caveats, so [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) stays capped at `87/89`.
- The IDA name on `0x00597580` still carries a stale `boost::exception` label, but the body writes the `TimerHandler` vtable and unregisters the handler from `g_pTimerMgr`, matching the TimerHandler destructor role.

## BrowserPane Inherited-Facet Consumer - 2026-07-26

- [UID:0004Y0][0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer](by-memory/0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer.md) and [UID:000217][0x004710d0-0x004710df.BrowserPaneCancelTimer](by-memory/0x004710d0-0x004710df.BrowserPaneCancelTimer.md) are paired BrowserPane primary-vtable adapters into this base API.
- BrowserPane inherits the TimerHandler facet through Pane/DialogPane at complete-object offset `+0xa4`; it does not own an embedded `m_timerHandler` field or add a second direct TimerHandler base.
- Source uses explicit base qualification: `TimerHandler::ScheduleTimer(timerId, delayMs, 0, 0)` and `TimerHandler::CancelTimer(timerId)`. This lets the compiler generate the observed complete-object adjustment while avoiding recursive calls to the BrowserPane virtuals.
- The adapters are BrowserPane-owned because their entries occupy BrowserPane-family primary slots `+0x60/+0x64`. This backlink does not transfer their ownership here, and it does not transfer the generic `0x005975e0` / `0x00597610` wrappers to Browser or SoundManager.
- Exact schedule/cancel names, `timerId`, `delayMs`, and zero payload semantics strengthen the accepted TimerHandler API vocabulary without changing this class's score, source route, formal class marker, callback contract, or TimerHandler.cpp-versus-TimerMgr.cpp caveat.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `89` | The class page maps the TimerHandler lifecycle, vtable, destructor/wrapper families, callback contract, current `by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md` out-of-line body, exact zero-route/vtable evidence, accepted class marker with `[[CHILDREN]]`, and source-family emitter route through [UID:0000OT][TimerMgr](by-file/TimerMgr.md). |
| Confidence | `91` | Current MCP session `80de0a67`, B004 wrapper proof, and B009 current-path reconciliation resolve the former `0x005975d0` ownership/source-model blocker and the stale UID display issue. Confidence remains below final-audit only because the executable has no PDB/source-path string proving the exact disk split between `TimerMgr.cpp` and a tiny companion TimerHandler unit. |

## Current Caveats

- Final source placement remains an inference between folding `TimerHandler` into `TimerMgr.cpp` and keeping a tiny companion source/header unit. The accepted current evidence checked `RSDS`, `NB10`, `.pdb`, `TimerHandler.cpp`, `TimerMgr.cpp`, and `OnTimer` strings and found no authoritative source-path proof.
- Exact caller-family semantics for `arg0` and `arg1` remain with derived timer owner pages; the base callback contract and `by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md` out-of-line body are settled for this class.

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md)
- `by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md`
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md)
- [UID:0003E0][0x0062e334-0x0062e340.TimerHandlerVtableData](by-memory/0x0062e334-0x0062e340.TimerHandlerVtableData.md)
- [UID:0004Y0][0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer](by-memory/0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer.md)
- [UID:000217][0x004710d0-0x004710df.BrowserPaneCancelTimer](by-memory/0x004710d0-0x004710df.BrowserPaneCancelTimer.md)

## Changes

- 2026-07-26 B001 UID000217 bounded BrowserPane backlink:
  - Preserved `89/91`, owner/emitter UID0000OT, reconstructable true, existing class-level marker/children route, callback contract, and all TimerHandler lifecycle/wrapper evidence.
  - Added only the exact UID0004Y0/UID000217 consumer pair, inherited Pane facet at `+0xa4`, qualified-base source shape, zero schedule payloads, and ownership boundary between BrowserPane adapters and generic TimerHandler wrappers.
- 2026-06-30 B009 implementation callback for `0000OT`:
  - Score/metadata changed to `89/91`, owner/emitter remains [UID:0000OT][TimerMgr](by-file/TimerMgr.md), and class-level C++ is the accepted marker with `[[CHILDREN]]`.
  - Summary/evidence: added the accepted class route marker, normalized callback and wrapper callees to current TimerHandler/TimerMgr child paths, historicalized older UID000418/UID00041D/UID00041E NewHumanImageLib/VectorGrow display names as stale UID-collision annotations, and preserved the final `TimerHandler.cpp` versus `TimerMgr.cpp` split caveat.
- 2026-06-23 B002 implementation callback for [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md):
  - Raised score/metadata from `85/86` to `87/89`; owner/emitter stay [UID:0000OT][TimerMgr](by-file/TimerMgr.md), reconstructable true, and class-level C++ remains blank.
  - Summary/evidence: replaced stale no-owner/vtable-contradiction wording with the accepted pure virtual `TimerHandler` callback contract plus [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) as the out-of-line true-return body. Preserved current MCP `80de0a67` evidence: exact bytes/padding, zero xrefs/callers/callees, no VA/RVA/raw pointer route, local PE route absence, positive controls, `0x0062e33c -> __purecall`, and exhausted source-breadcrumb cap.
- 2026-06-23 B004 implementation callback for `0001K8`:
  - Score/metadata unchanged at `85/86`, owner/emitter [UID:0000OT][TimerMgr](by-file/TimerMgr.md), reconstructable true, and blank class C++.
  - Summary/evidence: added current [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) wrapper evidence from MCP session `ff68e691`: exact `0x005975e0-0x005975ff` and `0x00597600-0x0059760d` ranges, byte/padding fences, `g_pTimerMgr` forwarding to `0x00597910` and `0x00597a10`, 163/45 caller fan-in, zero data/pointer route, source `void` versus raw `int` rationale, and the unresolved final source-file split/name/return-type caveats.
- 2026-06-23 B004 implementation callback for `0001K6`:
  - Score/metadata unchanged at `85/86`, owner/emitter [UID:0000OT][TimerMgr](by-file/TimerMgr.md), reconstructable true, and blank class C++.
  - Summary/evidence: historical B004 conclusion superseded for [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md). The `ff68e691` bytes/disassembly/decompile, zero xrefs, no VA/RVA/raw-offset pointer route, positive controls, and `0x0062e33c -> __purecall` evidence remain valid, but the old no-code conclusion is replaced by the current pure-virtual out-of-line body model.
- 2026-06-22 Rule 26 incorporation of B014 TimerMgrAndTimerQueue report:
  - Score unchanged at `85/86`.
  - Summary/evidence: documented the best-supported callback signature while preserving the then-current `0x005975d0` caveat. That caveat is superseded by the B002 [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) implementation above.
- 2026-06-23 B002 MCP-backed implementation sync for `0001K6`:
  - Score/metadata unchanged.
  - Summary/evidence: historical no-owner/non-emitting conclusion superseded by the current [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) repair; its `lookup_funcs` size `0x5`, return-true decompile, zero `xrefs_to`, no VA/RVA pointer hits, and `0x0062e33c -> __purecall` evidence remains preserved as support for the pure-virtual out-of-line body model.
- 2026-06-11 A003 Batch 226 vtable-data gate repair:
  - Before: `COMPLETION:84`, which kept the exact `TimerHandler` vtable child from clearing the strict child/direct-parent gate.
  - Changed to: `COMPLETION:85`, with the exact [UID:0003E0][0x0062e334-0x0062e340.TimerHandlerVtableData](by-memory/0x0062e334-0x0062e340.TimerHandlerVtableData.md) RTTI-adjacent vtable-data child linked.
  - Evidence: live IDA MCP reconfirmed the `0x0062e338` vtable first slot `0x00597650` and store xrefs at `0x00597570`, `0x005975a2`, and `0x00597675`; remaining final-source caveats are still documented, so confidence stays `86`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the timer-handler method family, wrapper/destructor memory links, and global timer-manager ownership; confidence remained limited by possible file-placement split and missing wrapper coverage in earlier documentation.
- 2026-06-04 live IDA refresh:
  - Changed to: `COMPLETION:84`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OT`.
  - Evidence: live IDA MCP confirmed exact boundaries for all TimerHandler lifecycle/wrapper functions, vtable data at `0x0062e338`, constructor/destructor/wrapper caller counts, `g_pTimerMgr` forwarding behavior, scalar destructor vtable slot, and the parent scheduler relationship under [UID:0000OT][TimerMgr](by-file/TimerMgr.md).
  - Remaining limits: superseded. The current score cap is exact source-file split/source-path proof, not [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) ownership.
## FolderSelectDialog Shared RTTI Dependencies R13/R19

These existing TimerHandler-owned compiler RTTI records are reached through FolderSelectDialog's inherited DialogPane facet. The records remain external and do not authorize handwritten RTTI storage.

| ID | Exact record and fields | Exact xrefs | Ownership boundary |
| --- | --- | --- | --- |
| R13 | `0x64060c-0x640628` BCD: TD `0x6739e8`, contained `0`, PMD `0xa4/-1/0`, attrs `0x40`, CHD `0x640628` | `xref_query.total=373`; FolderSelectDialog graph edge `0x647848`; outgoing TD `0x6739e8` and CHD `0x640628` | TimerHandler-owned compiler RTTI; FolderSelectDialog only references the inherited facet. |
| R19 | `0x6739e8-0x673a04` TypeDescriptor `??_R0?AVTimerHandler@@@8`: vfptr `0x635078`, spare `0`, decorated `.?AVTimerHandler@@` | `xref_query.total=5`, including BCD edge `0x64060c`; outgoing vfptr `0x635078` | TimerHandler-owned shared TypeDescriptor; no FolderSelectDialog CPP/H storage. |
