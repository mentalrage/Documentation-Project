*** UID:00007S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ScreenDimmer.h"
#include "ScreenPane.h"

class Event;

class MapRefreshDimmer : public ScreenDimmer
{
public:
    MapRefreshDimmer();

    virtual bool HandlePacketEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MapRefreshDimmer

## UID00037R Ctrl+R Initiation Route - 2026-08-24

- [UID:00037R][0x00506d20-0x00507150.MapPaneResizeCommandInputCore](by-memory/0x00506d20-0x00507150.MapPaneResizeCommandInputCore.md) supplies the exact source initiation: translated key `r` with exact Control is consumed; `g_pTransferServerDialog` at `0x00506f81` suppresses initiation while a transfer dialog is active.
- With the guard clear, ordinary source executes `new MapRefreshDimmer`. The inline construction sequence begins at `0x00506f93`, installs complete/EventHandler/TimerHandler facets at `0x00506fcf`, `0x00506fd5`, and `0x00506fdf`, and schedules timer 0 for 2000 ms, matching the retained constructor definition.
- MapPane then sends one-byte request opcode `0x38`, sets `m_visibleObjectRefreshPending` and `m_refreshWholeVisibleMap`, and on a nonnull ObjectList calls `MarkVisibleObjectsForRefresh()` followed by `PruneMarkedRowObjects()`.
- This route preserves the class as a private MapPane.cpp helper. The existing `0x22` packet callback still deletes the dimmer before `FinishVisibleObjectRefresh()`, and timer id 0 remains the timeout deletion route; no separate MapRefreshDimmer.cpp emitter or public header is introduced.
- Generated readback after UID00037R implementation requires the complete declaration before `new MapRefreshDimmer`. Routing this declaration through UID00007Q at position `0` preserves private MapPane.cpp ownership and UID00037R's blank emitter position; exact method definitions remain direct MapPane.cpp positions 2-4.
- Because those exact definitions intentionally emit directly to MapPane.cpp rather than as UID00007S children, the declaration formal has no `[[CHILDREN]]` marker. This prevents validator fallback text from entering generated C++ while retaining one declaration and three definitions.

## Status

- Confidence: very strong for behavior, ABI layout, class identity, and private MapPane.cpp source placement; exact original access/include spelling remains the only lexical uncertainty.
- Source file: private helper code in [UID:0000L3][MapPane](by-file/MapPane.md), routed through [UID:00007Q][MapPane](by-class/MapPane.md) at emitter position `0` so the complete class declaration precedes unpositioned MapPane method children.
- Address ranges: [UID:0001B1][0x00514920-0x00514a0d.MapRefreshDimmerMethods](by-memory/0x00514920-0x00514a0d.MapRefreshDimmerMethods.md), [UID:0003M5][0x00514d34-0x00514d4a.MapRefreshDimmerDestructorAdjustorThunks](by-memory/0x00514d34-0x00514d4a.MapRefreshDimmerDestructorAdjustorThunks.md), and [UID:0003M6][0x00514e20-0x00514e5b.MapRefreshDimmerScalarDeletingDestructor](by-memory/0x00514e20-0x00514e5b.MapRefreshDimmerScalarDeletingDestructor.md)
- Autogen parent/emitter: [UID:00007Q][MapPane](by-class/MapPane.md), which routes to [UID:0000L3][MapPane](by-file/MapPane.md). [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md) is a non-emitting historical semantic index.

## Class Purpose

`MapRefreshDimmer` is a short-lived timer-based dimming helper used during map refresh or loading transitions. It derives only from [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md), adds no data fields beyond the inherited `0xfc`-byte layout, schedules one two-second timer, accepts map-refresh-completion packet opcode `0x22`, and self-destructs from either completion route.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:0004VY][0x00514920-0x0051499b.MapRefreshDimmerConstructor](by-memory/0x00514920-0x0051499b.MapRefreshDimmerConstructor.md) | `0x00514920-0x0051499b` | Calls `ScreenDimmer(3, g_pScreenPane)` and schedules timer 0 for 2000 ms. |
| [UID:0004VZ][0x005149a0-0x005149e2.MapRefreshDimmerHandlePacketEvent](by-memory/0x005149a0-0x005149e2.MapRefreshDimmerHandlePacketEvent.md) | `0x005149a0-0x005149e2` | EventHandler slot 4; accepts only `event->packet[0] == 0x22`, deletes the dimmer, then calls `g_activeMapPane->FinishVisibleObjectRefresh()`. |
| [UID:0004W0][0x005149f0-0x00514a0d.MapRefreshDimmerOnTimer](by-memory/0x005149f0-0x00514a0d.MapRefreshDimmerOnTimer.md) | `0x005149f0-0x00514a0d` | TimerHandler slot 1; deletes the dimmer only for timer id 0 and returns true for every id. |
| `ScalarDeletingDestructor_vtable2_adjustor` | `0x00514d34-0x00514d3f` | Adjusts from the offset-`0xa0` interface back to object base. |
| `ScalarDeletingDestructor_vtable3_adjustor` | `0x00514d3f-0x00514d4a` | Adjusts from the offset-`0xa4` interface back to object base. |
| `ScalarDeletingDestructor` | `0x00514e20-0x00514e5b` | Destroys the base and optionally frees memory. |

## Evidence Notes

- 2026-06-04 live IDA MCP identity: `NexusTK.exe` at base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Function lookup confirms starts and sparse boundaries: `0x00514920` size `0x7b`, `0x005149f0` size `0x1d`, `0x00514d34` size `0xb`, `0x00514d3f` size `0xb`, and `0x00514e20` size `0x3b`; `0x00514e5b` is not a function start.
- The constructor delegates to `ScreenDimmer` at `0x00559b90` with dim level `3` and `dword_67A7CC`, writes MapRefreshDimmer vtables at object offsets `0`, `0xa0`, and `0xa4`, then starts a timer through `0x005975e0` with a `2000` ms interval.
- The timer callback at `0x005149f0` is referenced from vtable data at `0x0061e8d8`; on timer id `0`, it adjusts from the timer/interface subobject back by `0xa4` and invokes the deleting virtual.
- The scalar deleting destructor at `0x00514e20` calls `ScreenDimmer` teardown at `0x00559cf0` and frees storage through `0x004f4ac0` only when the delete flags require it.
- Vtable data confirms the primary table `??_7MapRefreshDimmer@@6B@` at `0x0061e858`, secondary table `??_7MapRefreshDimmer@@6B@_0` at `0x0061e8a4`, and tertiary table `??_7MapRefreshDimmer@@6B@_1` at `0x0061e8d4`; the constructor writes all three and the adjustor thunks target the deleting destructor.
- `sub_506DF0`, a MapPane-side input handler, has an inline construction branch that allocates `0xfc` bytes, calls the `ScreenDimmer` constructor, installs the same MapRefreshDimmer vtables, starts the `2000` ms timer, and continues map refresh work. This keeps the class in the map transition family rather than the generic dimmer module.
- 2026-06-07 A008 IDA `py_eval` enumerated the exact [UID:0002SR][0x0061e854-0x0061e8dc.MapRefreshDimmerVtableData](by-memory/0x0061e854-0x0061e8dc.MapRefreshDimmerVtableData.md) child: primary/secondary/tertiary RTTI words, all three vtable view starts, deleting-destructor target `0x00514e20`, adjustor targets `0x00514d34` and `0x00514d3f`, timer callback slot `0x0061e8d8 -> 0x005149f0`, and store xrefs from both the standalone constructor and the MapPane inline construction branch.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md)
- [UID:0001B1][0x00514920-0x00514a0d.MapRefreshDimmerMethods](by-memory/0x00514920-0x00514a0d.MapRefreshDimmerMethods.md)
- [UID:0003M5][0x00514d34-0x00514d4a.MapRefreshDimmerDestructorAdjustorThunks](by-memory/0x00514d34-0x00514d4a.MapRefreshDimmerDestructorAdjustorThunks.md)
- [UID:0003M6][0x00514e20-0x00514e5b.MapRefreshDimmerScalarDeletingDestructor](by-memory/0x00514e20-0x00514e5b.MapRefreshDimmerScalarDeletingDestructor.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:0004W1][MapRefreshDimmerVtables](by-type/by-vtable/MapRefreshDimmerVtables.md)

## Layout, Inheritance, And Source Contract

- RTTI gives ScreenDimmer as the sole direct source base. EventHandler and TimerHandler are Pane facets at complete-object offsets `+0xa0` and `+0xa4`; they are not additional explicit bases in this declaration.
- Complete-object, EventHandler, and TimerHandler vptrs are written at offsets 0, `+0xa0`, and `+0xa4` by both the retained out-of-line constructor and the exact MapPane inline construction route.
- The class adds no directly observed field. Allocation size `0xfc` equals the inherited ScreenDimmer layout used by both construction routes.
- The destructor is intentionally implicit. That source shape generates UID0003M5 adjustors, UID0003M6 scalar deleting wrapper, UID0002SR physical vtables/RTTI, and UID0004W1 semantic ABI evidence without explicit source-level vptrs, cookies, flags, or adjustor arithmetic.
- The accepted private source order is MapPane class position 0, this class position 1, UID0004VY position 2, UID0004VZ position 3, UID0004W0 position 4, and existing MapPoint support at position 5.

## Liveness, Placement, And Rejected Alternatives

- `0x00514920` has no recovered inbound call; the source constructor nevertheless survives out of line while the live MapPane route at `0x00506df0` contains an exact inline lowering. This is retained-source/inlining evidence, not dead-code proof.
- UID0004VZ is live through vtable slot `0x0061e8b4`; UID0004W0 is live through `0x0061e8d8`. Their delete-before-completion and timer-zero behavior are source-significant and preserved exactly.
- The packet callback's post-delete body is an exact inline lowering of public [UID:0004QA][0x0050b190-0x0050b1a7.MapPaneFinishVisibleObjectRefresh](by-memory/0x0050b190-0x0050b1a7.MapPaneFinishVisibleObjectRefresh.md), fixing the private MapPane.cpp route.
- A standalone MapRefreshDimmer.cpp emitter is rejected by zero constructor callers plus exact MapPane-side construction and completion inlining. UID0000L4 is retained for historical searchability only.
- Explicit EventHandler/TimerHandler bases, an authored destructor, raw vtable arrays, handwritten deleting wrappers, duplicate `0x004b0ba0` overrides, and extra state fields are rejected by RTTI, folded-slot, and layout evidence.

## Historical Corrections

- Historical `OnTimerExpired` wording is superseded by the TimerHandler-family `OnTimer(int,int,int)` contract.
- Historical secondary-interface ambiguity is superseded by the EventHandler slot-family `HandlePacketEvent(Event *)` contract and direct opcode/payload behavior.
- Historical ownership by UID0000L4 and unresolved standalone/private placement are superseded by UID0000L3 ownership and positions 1-4.
- Historical prose implying an authored destructor is superseded by the implicit-destructor/compiler-glue disposition.

## Changes

- 2026-05-28: Corrected the scalar deleting destructor endpoint from `0x00514e5a` to `0x00514e5b`. Evidence: IDA MCP reports `sub_514e20` as `0x00514e20-0x00514e5b`.
- Completion/confidence score update: existed before as `0/0`; changed to `74/78`. Summary: the map-specific dimmer timer wrapper has clear purpose, method boundaries, base relationship, and file-split caveat, but it is still a small partial class page rather than exhaustive source reconstruction. Evidence: linked `MapRefreshDimmer` memory page, IDA-confirmed constructor/destructor bounds, `ScreenDimmer` relationship, and map-transition ownership note.
- 2026-06-04:
  - Before: scored as `74/78`, with no reconstructable flag, no autogen parent, stale source-output wording, and only partial constructor/destructor evidence.
  - After: scored as `84/88`, marked `RECONSTRUCTABLE:TRUE`, and parented to [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md).
  - Summary/evidence: live IDA MCP rechecked the executable identity, method starts/sizes, constructor delegation to `ScreenDimmer`, three vtable writes, `2000` ms timer setup, timer callback behavior, scalar deleting destructor flags, vtable/RTTI anchors, adjustor thunks, and the MapPane-side inline construction branch at `sub_506DF0`; final source split and private method names remain below the `95/95` reconstruction bar.
- 2026-06-07 A008 Batch 013 parent-gate refresh:
  - Before: `84/88`; the class was just below the corrected 85/85 gate for direct vtable-data attachment.
  - Changed to: `86/90`.
  - Evidence: live IDA enumerated the exact MapRefreshDimmer vtable-data child, all three table views, deleting-destructor/adjustor/timer slot targets, and both standalone-constructor and MapPane-inline store xrefs. Standalone file versus private `MapPane.cpp` placement remains open, but direct class ownership of the vtable-data child is now justified.
- 2026-06-12 Agent-C001 Goal 2:
  - Score unchanged at `86/90`.
  - Updated method inventory after [UID:0001B1][0x00514920-0x00514a0d.MapRefreshDimmerMethods](by-memory/0x00514920-0x00514a0d.MapRefreshDimmerMethods.md) was narrowed and the old sparse range was split. Added exact destructor glue pages [UID:0003M5][0x00514d34-0x00514d4a.MapRefreshDimmerDestructorAdjustorThunks](by-memory/0x00514d34-0x00514d4a.MapRefreshDimmerDestructorAdjustorThunks.md) and [UID:0003M6][0x00514e20-0x00514e5b.MapRefreshDimmerScalarDeletingDestructor](by-memory/0x00514e20-0x00514e5b.MapRefreshDimmerScalarDeletingDestructor.md). Evidence: live IDA MCP proved the old `0x00514920-0x00514e5b` span crossed unrelated vector, object-pane unwind, GameServerConfig, and MapPane destructor code.
- 2026-07-22 B004 UID0002SR callback: Raised to `93/94`, moved ownership/emission from the standalone historical index to UID0000L3 position 1, installed the complete source declaration, linked the three registered authored children, fixed source names/contracts and implicit-destructor handling, and preserved the complete RTTI, layout, ABI, liveness, negative, and rejected-alternative evidence.
