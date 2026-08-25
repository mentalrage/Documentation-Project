*** UID:000037 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ConnStatusPane.h"

#include "../config/Config.h"
#include "../map/MapPane.h"
#include "../render/ImageLib.h"
#include "../render/Surface.h"
#include "../ui/core/Event.h"
#include "../util/TimerMgr.h"

template <>
Singleton<ConnStatusPane>::Singleton()
{
    g_pConnStatusPane = static_cast<ConnStatusPane *>(this);
}

template <>
Singleton<ConnStatusPane>::~Singleton()
{
    g_pConnStatusPane = 0;
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_NETWORK_CONNSTATUSPANE_H
#define NEXUSTK_NETWORK_CONNSTATUSPANE_H

#include "../ui/core/Pane.h"
#include "../util/Singleton.h"

class Event;

class ConnStatusPane : public Pane, public Singleton<ConnStatusPane>
{
public:
    ConnStatusPane();
    virtual ~ConnStatusPane();

protected:
    virtual void OnPaint();
    virtual bool HandlePacketEvent(Event *event);

private:
    void CaptureLatencyStartTick();
    void UpdateConnectionFrame();

    int m_latencySamples[10];
    int m_pendingLatencyStartTick;
    short m_connectionFrame;
};

extern ConnStatusPane *g_pConnStatusPane;

typedef char ConnStatusPaneSizeMustBe0x128[
    sizeof(ConnStatusPane) == 0x128 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ConnStatusPane

## Accepted UID0000IF Class Closure - 2026-08-22

- Canonical source is [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md), `NexusTK/network/ConnStatusPane.cpp/.h`. This class directly owns/emits the declaration and attached method/compiler-data children; its formal CPP is the include/specialized-Singleton preamble plus `[[CHILDREN]]`, and its formal H is the complete declaration above.
- Child source order is [UID:0002B9][0x0069adf4-0x0069adf8.g_pConnStatusPane](by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md) at position `10`, then [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md) at position `20`. Compiler-data children emit blank fragments.
- Direct bases are `Pane` and EBO-layout `Singleton<ConnStatusPane>`. Pane contributes inherited GrafPort/LObject and EventHandler/TimerHandler facets; RTTI PMDs place EventHandler at `+0xa0`, TimerHandler at `+0xa4`, and Singleton at `+0xf8`.
- Exact size is `0x128`: inherited prefix `[+0,+0xf8)`, `int m_latencySamples[10]` at `+0xf8`, `int m_pendingLatencyStartTick` at `+0x120`, `short m_connectionFrame` at `+0x124`, and two bytes tail padding.
- Authored methods are constructor, ordinary virtual destructor, private `CaptureLatencyStartTick`, `OnPaint`, `HandlePacketEvent(Event *)`, and private `UpdateConnectionFrame`. Two adjusted destructor thunks and the scalar deleting destructor are compiler output only.

## Exact Compiler-Data Children

| Child | Physical content and disposition |
| --- | --- |
| [UID:00035G][0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData](by-memory/0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData.md) | Primary COL pointer plus 18 slots; blank compiler-data formals. |
| [UID:000569][0x00617a34-0x00617a70.ConnStatusPaneAdjustedVtableData](by-memory/0x00617a34-0x00617a70.ConnStatusPaneAdjustedVtableData.md) | Secondary/tertiary COL pointers plus 11 and two slots; independent cross-index sibling linked from UID000251 and UID000252. |
| [UID:00056A][0x00617a70-0x00617a8a.ConnStatusPaneResourceStringData](by-memory/0x00617a70-0x00617a8a.ConnStatusPaneResourceStringData.md) | Exact `CONNSTAT.EPD`; blank formal blocks because OnPaint's source expression emits it. |
| [UID:000567][0x006457f8-0x006458d0.ConnStatusPaneRttiHierarchyData](by-memory/0x006457f8-0x006458d0.ConnStatusPaneRttiHierarchyData.md) | Three COLs, two CHDs, two BCAs, class self BCD, direct Singleton BCD, Singleton self BCD, plus five individually excluded shared-base BCD links. |
| [UID:000568][0x00675738-0x00675784.ConnStatusPaneTypeDescriptorData](by-memory/0x00675738-0x00675784.ConnStatusPaneTypeDescriptorData.md) | Exact adjacent ConnStatusPane and Singleton TypeDescriptors. |

The exhaustive 17-record RTTI inventory is: class TD `[0x675738,0x675758)`, Singleton TD `[0x675758,0x675784)`, primary COL `[0x6457f8,0x64580c)`, class CHD/BCA/self BCD `[0x64580c,0x645858)`, direct Singleton BCD `[0x645858,0x645874)`, Singleton CHD/BCA/self BCD `[0x645874,0x6458a8)`, secondary/tertiary COLs `[0x6458a8,0x6458d0)`, and five external shared BCDs: Pane `[0x640540,0x64055c)`, GrafPort `[0x640584,0x6405a0)`, LObject `[0x640348,0x640364)`, EventHandler `[0x6405bc,0x6405d8)`, TimerHandler `[0x64060c,0x640628)`. The five shared bodies are evidence links, never ConnStatus-owned storage.

## Current Score Rationale

- Completion `94`: exact hierarchy, `0x128` signed layout, complete header, six authored declarations, singleton specialization route, child order, and all compiler-data/external exclusions are closed.
- Confidence `96`: allocation, field accesses, vptr stores, all record-level RTTI, method behavior, global lifecycle, and formal source agree; only stripped private original spellings remain inferred.

## Historical Status

The older draft sections below are retained as provenance. The accepted class/formal/source contract above supersedes old scores, aliases, unsigned alternatives, provisional dependencies, and pre-split compiler-data wording.

- Confidence: strong for local class block, singleton, vtables, event/update behavior, field roles, and first-draft source shape; remaining uncertainty is exact original spelling for a few config/event/render helper names.
- Likely source file: [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md)
- Address range: [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md)

## Historical Class-Purpose Draft

`ConnStatusPane` is the in-game connection-status indicator. It renders `CONNSTAT.EPD`, tracks recent response timings, maps latency to status frames, and reacts to selected server-message opcodes that update connection/status display state. Older "parcel notification" wording is too narrow unless explicitly marked historical.

## Historical Method-Notes Draft

| Method | Address | Role |
| --- | --- | --- |
| `ConnStatusPane` | `0x00494520-0x004945df` | Constructor: calls `Pane(1)`, publishes `g_pConnStatusPane`, installs three vtable views, initializes ten latency samples plus pending tick to `0xffffffff`, and initializes frame to `0xffff`. |
| `~ConnStatusPane` | `0x004945e0-0x00494609` | Ordinary/non-deleting destructor body: restores vtable views, clears `g_pConnStatusPane`, and tails to base Pane teardown. |
| `CaptureLatencyStartTick` / `BeginLatencySample` | `0x00494610-0x0049461f` | No direct xrefs found; stores `g_pTimerMgr->currentTick` (`TimerMgr +0x18`) to `+0x120`, which the frame updater consumes. |
| `OnPaint` | `0x00494620-0x004946b1` | Clears invalid `0xffff` state or renders `CONNSTAT.EPD` frame with shared `NPAL7.PAL`. |
| `HandleConnectionMessage` | `0x004946c0-0x00494765` | Secondary EventHandler override for message opcodes `4`, `11`, `21`, and `38`; updates latency frame or forces frame `4` through the `g_pConfig+0x28de75` plus `MapPane::meth_0x5055d0()` gate. |
| `UpdateConnectionFrame` | `0x004947a0-0x00494964` | Maintains ten-sample latency window and maps average thresholds `<400 => 3`, `<800 => 2`, `<1200 => 1`, else `0`, with `0xffff` invalid/no-data. |
| Destructor adjustor/scalar deleting destructor family | `0x00494964-0x004949df` | Compiler-generated thunks/wrapper from the virtual destructor; document but do not emit as handwritten source. |
| Inherited Pane/EventHandler bridge/default slots | `0x00544db0`, `0x00544dc0`, `0x00544dd0` | Shared base bridge thunks with broad vtable fan-in. Historical labels `Pane::SetConnecting` / `SetDisconnected` / `SetConnected` are aliases, not ConnStatusPane methods. |

## Historical Field-And-Dependency Draft

| Offset / dependency | Recommended source-facing role | Evidence |
| --- | --- | --- |
| `+0xf8..+0x11c` | `m_latencySamples[10]` / `m_responseTimeSamples[10]` | Constructor seeds ten dwords to `0xffffffff`; updater shifts exactly this fixed window, skips sentinel entries, averages valid samples, and classifies latency. |
| `+0x120` | `m_pendingLatencyStartTick` / `m_lastRequestTick` | `0x00494610` stores `g_pTimerMgr->currentTick`; updater consumes current tick minus this field and resets it to `0xffffffff`. |
| `+0x124` | `m_connectionFrame` / `m_statusFrame` | `0xffff` means invalid/no frame, `0..3` are latency frames, and frame `4` is a special map/config-gated status frame. |
| `g_pConfig+0x28de75` | `mapMovementStatusOption` / `sendMovementStatusBit` | OptionPane control index `8` writes this byte; ConnStatusPane, UserStatusPane2, and LivingObjectPane movement/object packet code consume it with the MapPane `+0x40e` predicate. Exact UI label is unresolved. |
| `MapPane::meth_0x5055d0()` | `AllowsMovementStatusFlag()` / `IsNormalMovementStatusClear()` | Leaf predicate around MapPane `+0x40e`; keep descriptive until MapPane field naming is finalized. |

## Historical Evidence Notes

- Live IDA `py_eval` on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms exact local ranges for constructor, ordinary destructor/reset body, TimerMgr latency-start helper, paint, message handler, frame updater, destructor adjustors, and scalar deleting destructor.
- The constructor has one direct caller: `0x004f87ec` inside `0x004f7d10`, matching main UI graph setup.
- Constructor stores `g_pConnStatusPane` at `0x0069adf4`; the vtable reset helper and scalar deleting destructor clear it; `0x00504a32` reads it later.
- Constructor/vtable-reset/destructor stores use primary vtable `0x006179ec`, secondary vtable `0x00617a38`, and tertiary vtable `0x00617a68`.
- Primary vtable slot 17 (`0x00617a30`) points to `OnPaint`; slot 23 (`0x00617a48`) points to `HandleConnectionMessage`; slots `0x00617a38` and `0x00617a68` point to destructor adjustors.
- [UID:00035G][0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData](by-memory/0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData.md) now documents the exact primary vtable child at `87/91` and attaches here after the strict direct gate cleared.
- `HandleConnectionMessage` dispatches packet byte cases 4, 11, 21, and 38 through a jump table, checks global state at `0x0067a7c8`, calls `0x005055d0`, and calls `UpdateConnectionFrame` from two paths.
- `UpdateConnectionFrame` reads `dword_67AB80`, rolls a latency sample window, maps average response times around `0x190`, `0x320`, and `0x4b0` into frame ids, and invalidates the pane only when the frame changes.
- `0x00544db0`, `0x00544dc0`, and `0x00544dd0` are kept as base-pane dependencies. Live IDA reports broad vtable fan-in for these wrappers, including 79/72/120 data refs, even though `ConnStatusPane` uses them in its vtable.

## Cross-References

- [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md)
- [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md)
- [UID:00035G][0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData](by-memory/0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData.md)
- [UID:000569][0x00617a34-0x00617a70.ConnStatusPaneAdjustedVtableData](by-memory/0x00617a34-0x00617a70.ConnStatusPaneAdjustedVtableData.md)
- [UID:00056A][0x00617a70-0x00617a8a.ConnStatusPaneResourceStringData](by-memory/0x00617a70-0x00617a8a.ConnStatusPaneResourceStringData.md)
- [UID:000567][0x006457f8-0x006458d0.ConnStatusPaneRttiHierarchyData](by-memory/0x006457f8-0x006458d0.ConnStatusPaneRttiHierarchyData.md)
- [UID:000568][0x00675738-0x00675784.ConnStatusPaneTypeDescriptorData](by-memory/0x00675738-0x00675784.ConnStatusPaneTypeDescriptorData.md)
- [UID:0000A2][Pane](by-class/Pane.md)

## Changes

- 2026-08-22 B003 UID0000IF accepted implementation callback: raised `88/90 -> 94/96`; installed exact CPP specialization/include/child-order preamble and complete H declaration; added signed `0x128` layout, six authored methods, exhaustive 17-record RTTI with five external exclusions, and all corrected/new compiler-data links while historicalizing the prior draft sections.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: construction, paint, message handling, frame update, destructor family, singleton ownership, and base-state caveat are documented; remaining uncertainty is mostly the base `Pane` setter ownership and exact member names.
- 2026-06-04: Raised from `72/80` to `84/86`, marked reconstructable, and attached to [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md).
  - Before: page had class behavior notes but no reconstructable/parent metadata, stale recovered-file provenance, no exact half-open ranges, and no vtable-slot or singleton-xref details.
  - After: live IDA evidence records executable identity, exact ranges, constructor caller, singleton writes/clear/read, primary/secondary/tertiary vtables, paint/message/destructor slots, message dispatch cases, latency thresholds, and base-wrapper fan-in counts.
  - Reasoning: parent [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md) now has a valid `NexusTK/network/` path and stronger live evidence, so class attachment is justified. Completion remains below final-code range because final member names and exact `network` versus `ui/status` source split are still provisional.
- 2026-06-12 A001 Batch 256: Raised `84/86 -> 85/87`.
  - Evidence: linked exact primary vtable child [UID:00035G][0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData](by-memory/0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData.md), whose dword slots and constructor/destructor store xrefs prove the primary vtable side of the class layout. The file parent [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md) was also raised to `85/85`, so the class/file and vtable/class gates now clear.
- 2026-06-18 B002 source-quality pass: Raised `85/87 -> 88/90` and synchronized the class with [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md) first-draft C++ readiness. The pass resolved the ordinary destructor/source split, TimerMgr latency-start helper, ten-sample latency fields, `CONNSTAT.EPD`/`NPAL7.PAL` paint path, opcodes `4/11/21/38`, `g_pConfig+0x28de75` plus MapPane predicate gate, inherited Pane/EventHandler bridge-slot exclusions, and generated-output alias-pollution caveat.
