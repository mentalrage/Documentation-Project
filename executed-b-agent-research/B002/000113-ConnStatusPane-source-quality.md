** TARGET-REPORT-UID:000113 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002-goal2-connstatuspane-source-quality-000113-20260618

Report-only pass for [UID:000113][0x00494520-0x004949df.ConnStatusPane](../../../../../by-memory/0x00494520-0x004949df.ConnStatusPane.md).

Changed-files / no-direct-edit statement: this pass creates only this report. I did not edit any `by-*` documentation, generated reports/source, IDA database files, or `by-memory/-coverage-report.md`.

MCP note: the local MCP endpoint was not reachable in this session (`127.0.0.1:13337` refused connection). This report therefore uses the current IDA-backed project docs, exported function/global/vtable JSON, old Wave2 recovery notes, and current generated-output files as evidence; no new live IDA mutation is claimed.

## Evidence Checked

- Primary target [UID:000113] currently records `84/88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:000037`, `EMITTER_UIDS:000037`, blank formal C++.
- Support docs checked: [UID:000037][ConnStatusPane class](../../../../../by-class/ConnStatusPane.md), [UID:0000IF][ConnStatusPane file](../../../../../by-file/ConnStatusPane.md), [UID:0002B9][g_pConnStatusPane](../../../../../by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md), [UID:00035G][ConnStatusPane primary vtable data](../../../../../by-memory/0x006179ec-0x00617a38.ConnStatusPanePrimaryVtableData.md), [UID:000252][ControlPaneReadOnlyData](../../../../../by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md), [UID:00028Q][g_pConfig](../../../../../by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md), [UID:0000QU][g_pEPFLib](../../../../../by-global/g_pEPFLib.md), [UID:0000SI][g_pTimerMgr](../../../../../by-global/g_pTimerMgr.md), [UID:0001WD][TimerMgrLayout](../../../../../by-type/by-struct/TimerMgrLayout.md), [UID:0000TN][SurfaceRenderCallbackTable](../../../../../by-global/SurfaceRenderCallbackTable.md), [UID:0002KP][ResourceLayoutTableLookupLayoutEntry](../../../../../by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md), [UID:0000XY][EPFTileContext](../../../../../by-memory/0x00457a60-0x00458610.EPFTileContext.md), Config class/file support, and current coverage/stats rows.
- Export/generated evidence checked: `resources/exported_data/master_function_list.json`, `master_globals.json`, `master_vtables.json`, `detection_differences.json`, `re-agent/re-agent-progress.json`, `re-agent/reports/code/0x00494520_ConnStatusPane_ctor_0x494520.cpp`, `0x00494620_ConnStatusPane_virt_meth_0x494620.cpp`, `0x004946c0_ConnStatusPane_FUN_004946c0.cpp`, `0x00494964_ConnStatusPane_virt_meth_0x494964.cpp`, `0x00494980_ConnStatusPane_virt_deldtor_0x494980.cpp`, and the existing zero-byte `auto-generated/NexusTK/network/ConnStatusPane.cpp`.

## Heuristic / Inference Reanalysis And Validation

### Ownership, source split, and generated-output policy

Current owner/emitter route through [UID:000037] `ConnStatusPane` is validated. The range is a coherent class-owned source island: constructor, ordinary destructor/reset helper, private timing helper, paint override, event/message override, private frame updater, destructor adjustors, and scalar deleting destructor all share the ConnStatusPane vtable triplet and object fields. The only constructor caller remains the main UI graph (`0x004f87ec` in `0x004f7d10`), and singleton publication/clear/read evidence ties the range to `g_pConnStatusPane`.

The proposed source placement should be `NexusTK/network/ConnStatusPane.cpp`, not a new generic `ui/status` module for this pass. Reasons: the class paints a UI status icon, but its distinctive authored behavior is connection/message handling and latency sampling over server-message opcodes, `g_pTimerMgr`, `g_pConfig +0x28de75`, and `MapPane::meth_0x5055d0`. The proposed source tree already lists `network/ConnStatusPane.cpp`. `ui/status/ConnStatusPane.cpp` remains a possible future tree-cleanup if the project later separates all network-status UI from transport code, but it is not an active blocker.

The generated output policy should reject current generated `ConnStatusPane.cpp` as source evidence: `project-documentation/auto-generated/NexusTK/network/ConnStatusPane.cpp` exists but is zero bytes. Re-agent generated snippets are useful as decompilation/export evidence only; they contain alias pollution such as `FittingRoomListPane::meth_0x4b9660` and `FittingRoomDownloadControlPane::meth_0x4b9980` for generic GrafPort/render helpers, and should not be copied as final source names.

### Constructor `0x00494520-0x004945df`

Validated as `ConnStatusPane::ConnStatusPane()`. Old Wave2 and current generated decompilation agree that it calls `Pane::Pane(this, 1)`, stores `this` to `g_pConnStatusPane` at `0x0069adf4`, installs the primary/secondary/tertiary ConnStatusPane vtable views at `+0`, `+0xa0`, and `+0xa4`, initializes ten dword timing slots `+0xf8..+0x11c` to `0xffffffff`, initializes `+0x120` to `0xffffffff`, and initializes `+0x124` to `0xffff`.

Best source-facing fields:

| Offset | Recommendation | Evidence |
| --- | --- | --- |
| `+0xf8..+0x11c` | `m_latencySamples[10]` / `m_responseTimeSamples[10]` | Constructor seeds all ten dwords to `-1`; `UpdateConnectionFrame` shifts the ten slots, skips `-1` entries, averages valid samples, and classifies latency. |
| `+0x120` | `m_pendingLatencyStartTick` / `m_lastRequestTick` | Constructor seeds `-1`; helper `0x00494610` stores `g_pTimerMgr->currentTick`; updater consumes current tick minus this field and then resets it to `-1`. |
| `+0x124` | `m_connectionFrame` / `m_statusFrame` | Constructor seeds `0xffff`; OnPaint treats `0xffff` as invalid/no frame; updater writes `0..3` or `0xffff`; handler may force value `4`. Use `uint16_t` or `int` in draft with explicit sentinel. |

Rejected alternatives:

- A heap/vector sample buffer: rejected because the constructor writes ten contiguous dwords in-object and the updater shifts exactly that fixed window.
- A status-only field at `+0x120`: rejected because `0x00494610` and `UpdateConnectionFrame` both use `TimerMgr +0x18`, so this is a tick baseline, not a status enum.

### Ordinary destructor/reset helper `0x004945e0-0x00494609`

Current target label "vtable reset helper" should be promoted to source-facing ordinary/non-deleting destructor body: `ConnStatusPane::~ConnStatusPane()`. Evidence: it restores the same three ConnStatusPane vtable views, clears `g_pConnStatusPane`, and tail-jumps to base teardown at `0x00544580`. Old Wave2 described it as an unresolved non-deleting destructor-style helper and recommended folding it into the destructor family. That is now strong enough for the source report.

The scalar deleting destructor at `0x00494980` duplicates the vtable restoration/singleton clear before base teardown and conditional free because of MSVC ABI emission. Source C++ should contain only `~ConnStatusPane()`, not a handwritten `ScalarDeletingDestructor`.

Rejected alternatives:

- Independent cleanup helper: rejected because there are no product-specific fields beyond vtables and singleton clear, and the tail-call is base teardown.
- Leave as no-source compiler helper: rejected because this is the ordinary destructor shape. The adjusted thunks and scalar deleting wrapper are compiler helpers; the `0x004945e0` body is the source destructor body.

### No-direct-xref helper `0x00494610-0x0049461f`

This helper is source-bearing private timing code, despite no direct xrefs/vtable slot found. Best source-facing name: `ConnStatusPane::BeginLatencySample()` or `ConnStatusPane::CaptureLatencyStartTick()`. It reads `g_pTimerMgr->currentTick` (`dword_67AB80 +0x18`, documented by TimerMgrLayout as `currentTick`) and writes it to `this+0x120`, returning the same value.

Reachability interpretation: current exported metadata and old report both show no surviving direct caller and no vtable slot. That does not justify a new owner or deletion. The helper sits between destructor and paint method in the ConnStatusPane island, writes a field consumed by `UpdateConnectionFrame`, and uses the same TimerMgr tick source. Treat it as an unreferenced or address-hidden private method retained in the binary, not as dead padding. This should not block first-draft C++; include it as a private helper with a no-direct-xref note.

Rejected alternatives:

- "Application state snapshot": rejected because `dword_67AB80 +0x18` is `TimerMgr::currentTick`, not an Application field.
- "Set connected/disconnected status": rejected because it writes only the tick baseline and no frame/status field.
- Separate helper class: rejected because field use and placement are ConnStatusPane-local.

### OnPaint `0x00494620-0x004946b1`

Validated as `void ConnStatusPane::OnPaint()`. The primary vtable `0x006179ec` slot 17 (`0x00617a30`) points to `0x00494620`.

Current source-facing behavior:

- Construct a stack `EPFTileContext` (`0x00457a60` initializes a 0x28-byte context).
- Compute the pane draw target as the GrafPort/Pane rectangle area around `this +0x44` / `GrafPort.mbr_0x3c + 8`.
- If `m_connectionFrame == 0xffff`, clear the target area: set the display field around `GrafPort +0x70` to zero, call the generic GrafPort/reset helper at `0x004b9660`, then dispatch through shared Surface callback slot `dword_69B3FC`. The generated `FittingRoomListPane` alias for `0x004b9660` is stale; [SurfaceRenderCallbackTable] shows `dword_69B3FC` is a shared render callback slot with broad fanout.
- Otherwise, call `ResourceLayoutTable::LookupLayoutEntry(g_pEPFLib, L"CONNSTAT.EPD", frame, &tileContext)` and draw via the generic tile-frame blit helper `0x004b9980` with palette `L"NPAL7.PAL"`.

Resource/global resolution:

- `0x00617a70` is exported as UTF-16 `CONNSTAT.EPD`, one xref from `0x00494620`. It currently lives in mixed [UID:000252] read-only data after the adjusted vtables.
- `0x006152ec` is UTF-16 `NPAL7.PAL`, with ten known xrefs including ConnStatusPane, IconsPane, TotemFrame, UserStatusPane, OldUserStatusPane, and ColorStringChattingMessage. It is a shared old-HUD palette literal, not ConnStatusPane-private data.
- `0x0067a744` is `g_pEPFLib`, an ImageLib/ResourceLayout singleton exposing `LookupLayoutEntry`.

Rejected alternatives:

- `FittingRoomListPane` / `FittingRoomDownloadControlPane` ownership: rejected as generated alias pollution. The helpers are generic GrafPort/render resource helpers used by many panes.
- `NNSTAT.EPD`: rejected as stale/truncated aggregate string sample. Current exported globals and ConnStatusPane docs identify `0x00617a70` as `CONNSTAT.EPD`.

### HandleConnectionMessage `0x004946c0-0x00494765`

Validated as ConnStatusPane's secondary EventHandler-style override. The secondary vtable `0x00617a38` slot 4 points to `0x004946c0`. Raw receiver is the adjusted secondary subobject at `ConnStatusPane +0xa0`; the full object is `this -0xa0`. Source C++ should declare this as a normal `ConnStatusPane` member/override and let the compiler synthesize the receiver adjustment.

Signature recommendation: `uint32_t ConnStatusPane::HandleConnectionMessage(ConnectionMessageEvent *event)` or `bool ConnStatusPane::HandleConnectionMessage(ConnectionMessageEvent *event)` depending on the established EventHandler return type. Existing Wave2 used `uint32_t ConnStatusPane::HandleConnectionMessage(int param_1)`; the generated body returns `uVar2 & 0xffffff00`, so a `uint32_t` draft is safest unless EventHandler support finalizes a bool-return convention. The event payload pointer is read at `event +0x0c`, then the first byte is switched.

Handled opcodes/cases:

- Current generated code and old report show `0x04`, `0x0b`, `0x15`, and `0x26` (decimal 4, 11, 21, and 38). A separate exported summary at a neighboring address includes case `8`, but the ConnStatusPane target-specific generated code and target docs list only the four required cases. Keep [UID:000113] at cases `4`, `11`, `21`, and `38`; do not add case `8` without live disassembly.

Branch behavior:

- If `g_pConfig +0x28de75` is nonzero and `MapPane::meth_0x5055d0(g_pMapPane)` returns true, the handler optionally updates the latency frame if `m_pendingLatencyStartTick != -1`, then forces `m_connectionFrame` / `m_statusFrame` to `4` if it was not already `4`, and invalidates via the Pane virtual at offset `+0x20`.
- Otherwise, if `m_pendingLatencyStartTick != -1`, it calls `UpdateConnectionFrame()`.
- All paths return with the low byte cleared (`& 0xffffff00`) in current decompilation. Preserve that in first draft until EventHandler return policy is unified.

Config/global interpretation:

- `g_pConfig +0x28de75` is a RegistryConfig option byte. `OptionPane` writes it from option control index `8` as `(control->stateAt10C == 0)`. `LivingObjectPane`/movement code uses it together with `MapPane::meth_0x5055d0` to set/clear a high bit in movement/object packet state. Source-facing descriptive names can be `m_mapMovementStatusOption`, `m_enableMapMovementHighBit`, or `m_sendMapPositionStatusBit`; do not claim a final UI label.
- `MapPane::meth_0x5055d0()` is a leaf returning `this->mbr_0x40e == 0` with 24 callers in re-agent logs. Best descriptive name for support docs: `MapPane::IsNormalMovementStatusClear()` / `MapPane::AllowsMovementStatusFlag()`. It is not a parcel notification helper.
- The older "parcel-notification logic" phrase is too narrow. This handler's special frame-4 branch is better described as a map/config-gated connection/status-display override used by movement/object packet state. If "parcel" is retained in prose, mark it as historical/unproven.

Rejected alternatives:

- Direct packet-buffer parser: rejected because the handler switches on the byte pointed to by `event +0x0c`, not on a local packet buffer it owns.
- Source split into generic EventHandler code: rejected because only one vtable slot for ConnStatusPane points here, and the body updates ConnStatusPane latency/status fields.

### UpdateConnectionFrame `0x004947a0-0x00494964`

Validated as private `ConnStatusPane::UpdateConnectionFrame()`. Existing old Wave2 recovery and current exported summaries agree:

- If `m_pendingLatencyStartTick` is not `-1`, compute `elapsed = g_pTimerMgr->currentTick - m_pendingLatencyStartTick`.
- Shift the ten dword samples at `+0xf8..+0x11c`, discard the oldest, append the new elapsed sample, and reset `m_pendingLatencyStartTick` to `-1`.
- Average only valid entries (`sample != 0xffffffff`).
- If no valid entries exist, set result frame to `0xffff`.
- Else classify average latency: `<400` (`0x190`) => frame `3`; `<800` (`0x320`) => frame `2`; `<1200` (`0x4b0`) => frame `1`; otherwise frame `0`. This inverts the naive "low frame is fast" guess: `3` is fastest/best, `0` is slowest/worst, and `0xffff` is invalid/no-data.
- If the computed frame differs from `+0x124`, write it and invalidate/repaint through the Pane virtual. The handler may separately force frame `4`; treat frame `4` as a special map/config-gated status frame outside the latency `0..3` range.

Return type recommendation: current Wave2 signature was `int ConnStatusPane::UpdateConnectionFrame()`, and generated summaries imply the invalidation call's return value may flow through. For formal C++ draft, use `uint32_t` if preserving return value from invalidate is important, or `void` if the caller ignores it. Since `HandleConnectionMessage` assigns `uVar2 = UpdateConnectionFrame()` in generated code, recommend `uint32_t UpdateConnectionFrame()` for first-draft parity.

### Vtables `0x006179ec`, `0x00617a38`, `0x00617a68`

Primary vtable `0x006179ec` is already exact child [UID:00035G], with 18 entries and `OnPaint` at slot 17. Current [UID:00035G] coverage row is stale because it still says `AUTOGEN_PARENT_UID` is blank due to the class parent being `84/86`; class [UID:000037] is now `85/87` and [UID:00035G] itself records owner/emitter [UID:000037]. Replace the coverage row.

Secondary vtable `0x00617a38` and tertiary vtable `0x00617a68` are currently contained in mixed [UID:000252] ControlPaneReadOnlyData. Exported vtable evidence:

- `0x00617a38`: 11 entries. Slot 0 -> adjustor thunk `0x00494964`; slots 1-3 -> inherited Pane/EventHandler bridge thunks `0x00544db0`, `0x00544dc0`, `0x00544dd0`; slot 4 -> `HandleConnectionMessage`; remaining slots are inherited/default EventHandler/Pane slots.
- `0x00617a68`: 2 entries. Slot 0 -> adjustor thunk `0x0049496f`; slot 1 -> inherited `0x00544e90`.

Recommendation: create an exact support child for `0x00617a38-0x00617a70.ConnStatusPaneAdjustedVtableData.md` or equivalent, parent [UID:000037]. The half-open end `0x00617a70` is supported by exported globals: `0x00617a70` starts the UTF-16 `CONNSTAT.EPD` literal. If the supervisor prefers the RTTI-locator-inclusive convention used by some vtable pages, include the locator dwords immediately before each view in the child text but keep the half-open child range ending before `0x00617a70` to avoid swallowing the string literal. This split is support quality, not a blocker to [UID:000113] C++.

### Shared wrappers `0x00544db0` / `0x00544dc0` / `0x00544dd0`

Current ConnStatusPane class/file docs already correctly avoid class-local ownership, but the source-facing description should be updated from "SetConnecting/SetDisconnected/SetConnected" where that wording implies ConnStatusPane methods. Current EventHandlerBase and PaneCore docs show these as Pane/EventHandler default bridge thunks to source-defined default false bodies, with broad vtable fan-in. Old Wave2 labels `Pane::SetConnecting`, `Pane::SetDisconnected`, and `Pane::SetConnected` are historical names for the same shared base slots; they are not ConnStatusPane source.

Recommendation: in ConnStatusPane docs, call them "inherited Pane/EventHandler bridge/default status-event slots" and note the historical Wave2 names only as aliases.

### Singleton `0x0069adf4`

[UID:0002B9] is validated. Exact xrefs remain constructor store `0x00494545`, ordinary destructor/reset clear `0x004945fa`, scalar deleting destructor clear `0x004949a0`, and MapPane exit cleanup read `0x00504a32`. Neighboring singleton slots bound the range. The source declaration can be:

```cpp
static ConnStatusPane* g_pConnStatusPane;
```

No ownership change is needed. The by-memory coverage row is stale (`84%` while the page is `85/90`); replace it.

### Score and metadata impact

Recommended [UID:000113] metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:000037`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000037`
- formal C++ should be populated with first-draft method code below.

Rationale: this pass resolves the stale 95/95 code-gate blocker, source placement, destructor family, no-xref timing helper role, exact field families, resource globals, vtable views, wrapper/helper ownership, generated-output policy, and first-draft C++ readiness. Completion should not go higher than `88` yet because the exact original field spellings for `+0x28de75`, `MapPane::mbr_0x40e`, event type struct, and generic render helper names are still descriptive rather than source symbols. Confidence can rise to `90` because behavior/ownership are strongly cross-confirmed; lack of fresh live MCP in this session keeps it below final-audit.

Recommended support metadata:

- [UID:000037] class: raise `85/87` to `88/90`.
- [UID:0000IF] file: raise `87/88` to `88/90`, and remove "network-versus-UI-status placement caveat" as an active blocker; retain it only as a future tree-organization note.
- [UID:00035G] primary vtable: keep page metadata `87/91`, but replace stale memory coverage row.
- [UID:0002B9] singleton: keep page metadata `85/90`, but replace stale memory coverage row.
- [UID:000252] ControlPaneReadOnlyData: no score change required, but add the ConnStatusPane adjusted-vtable split opportunity.

## First-Draft C++ Recommendation

[UID:000113] meets the active code-entry gate: `RECONSTRUCTABLE:TRUE`, nonblank valid `EMITTER_UIDS:000037`, and average score `(84 + 88) / 2 = 86`, with recommended score `(88 + 90) / 2 = 89`. The formal C++ block should not remain blank because of stale "below 95/95" wording.

Populate a first-draft C++ block for source-bearing methods and document compiler glue separately. Do not include handwritten implementations for `0x00494964`, `0x0049496f`, or `0x00494980`; those are generated from the virtual destructor.

```cpp
// Draft source shape for UID 000113. Helper/type names are descriptive where
// the original header spelling is not yet recovered.

namespace {
constexpr uint32_t kInvalidLatencySample = 0xffffffffu;
constexpr uint16_t kInvalidConnectionFrame = 0xffffu;
constexpr uint16_t kMapStatusConnectionFrame = 4u;

constexpr uint32_t kLatencyFastThresholdMs = 0x190; // 400
constexpr uint32_t kLatencyMidThresholdMs = 0x320;  // 800
constexpr uint32_t kLatencySlowThresholdMs = 0x4b0; // 1200
}

ConnStatusPane::ConnStatusPane()
    : Pane(1)
{
    g_pConnStatusPane = this;

    for (uint32_t &sample : m_latencySamples) {
        sample = kInvalidLatencySample;
    }

    m_pendingLatencyStartTick = kInvalidLatencySample;
    m_connectionFrame = kInvalidConnectionFrame;
}

ConnStatusPane::~ConnStatusPane()
{
    if (g_pConnStatusPane == this) {
        g_pConnStatusPane = nullptr;
    }
}

uint32_t ConnStatusPane::CaptureLatencyStartTick()
{
    m_pendingLatencyStartTick = g_pTimerMgr->currentTick;
    return m_pendingLatencyStartTick;
}

void ConnStatusPane::OnPaint()
{
    EPFTileContext tile;
    const Rect &paneRect = GetScreenBounds();

    if (m_connectionFrame == kInvalidConnectionFrame) {
        ClearConnectionStatusArea(paneRect);
        return;
    }

    g_pEPFLib->LookupLayoutEntry(L"CONNSTAT.EPD",
                                 static_cast<int16_t>(m_connectionFrame),
                                 &tile);
    DrawTileFrame(tile, tile.bounds, paneRect, nullptr, L"NPAL7.PAL");
}

uint32_t ConnStatusPane::HandleConnectionMessage(ConnectionMessageEvent *event)
{
    uint32_t result = 0;
    const uint8_t opcode = event->packetBytes[0];

    switch (opcode) {
    case 0x04:
    case 0x0b:
    case 0x15:
    case 0x26:
        if (g_pConfig->mapMovementStatusOption &&
            g_pMapPane != nullptr &&
            g_pMapPane->AllowsMovementStatusFlag()) {
            if (m_pendingLatencyStartTick != kInvalidLatencySample) {
                result = UpdateConnectionFrame();
            }

            if (m_connectionFrame != kMapStatusConnectionFrame) {
                m_connectionFrame = kMapStatusConnectionFrame;
                result = Invalidate();
            }
        } else if (m_pendingLatencyStartTick != kInvalidLatencySample) {
            result = UpdateConnectionFrame();
        }
        break;

    default:
        break;
    }

    return result & 0xffffff00u;
}

uint32_t ConnStatusPane::UpdateConnectionFrame()
{
    if (m_pendingLatencyStartTick != kInvalidLatencySample) {
        const uint32_t elapsed = g_pTimerMgr->currentTick - m_pendingLatencyStartTick;

        for (size_t i = 0; i != 9; ++i) {
            m_latencySamples[i] = m_latencySamples[i + 1];
        }
        m_latencySamples[9] = elapsed;
        m_pendingLatencyStartTick = kInvalidLatencySample;
    }

    uint32_t sum = 0;
    uint32_t count = 0;
    for (const uint32_t sample : m_latencySamples) {
        if (sample != kInvalidLatencySample) {
            sum += sample;
            ++count;
        }
    }

    uint16_t nextFrame = kInvalidConnectionFrame;
    if (count != 0) {
        const uint32_t average = sum / count;
        if (average < kLatencyFastThresholdMs) {
            nextFrame = 3;
        } else if (average < kLatencyMidThresholdMs) {
            nextFrame = 2;
        } else if (average < kLatencySlowThresholdMs) {
            nextFrame = 1;
        } else {
            nextFrame = 0;
        }
    }

    if (m_connectionFrame != nextFrame) {
        m_connectionFrame = nextFrame;
        return Invalidate() & 0xffffff00u;
    }

    return 0;
}
```

Draft notes for supervisor:

- Replace `ConnectionMessageEvent`, `packetBytes`, `ClearConnectionStatusArea`, `DrawTileFrame`, `Invalidate`, `mapMovementStatusOption`, and `AllowsMovementStatusFlag` with existing project declarations if already standardized. These names are descriptive placeholders, not generated owner claims.
- If the EventHandler family standardizes a bool return, `HandleConnectionMessage` can be changed to that type after preserving the observed low-byte-masked return behavior.
- The binary's scalar deleting destructor and two adjusted destructor thunks are generated from the virtual destructor and should be documented, not emitted as handwritten C++.

## Exact Supervisor Edits

### Primary target [UID:000113]

Header replacement:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000037 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000037 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the current stale score rationale with:

```md
## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `88` | The page now records the complete ConnStatusPane method island, constructor/destructor family, no-direct-xref latency-start helper, paint/event/frame-update behavior, singleton lifecycle, vtable views, field layout at `+0xf8..+0x124`, resource strings, config/map gate dependencies, generated-output caveats, and first-draft source C++. Completion remains below final-audit because exact original spellings for the config option byte, EventHandler event type, MapPane `+0x40e` predicate, and generic render helper names remain descriptive. |
| Confidence | `90` | Current IDA-backed docs, exported function/global/vtable data, old Wave2 recovery notes, and support docs agree on ownership, boundaries, vtable slots, field behavior, latency thresholds, resource literals, and singleton xrefs. Confidence is capped below final because this pass did not have live MCP access and a few source-facing names remain inferred. |
```

Replace/insert method inventory with:

```md
| Range | Source-facing role | Notes |
| --- | --- | --- |
| `0x00494520-0x004945df` | `ConnStatusPane::ConnStatusPane()` | Calls `Pane(1)`, publishes `g_pConnStatusPane`, installs primary/secondary/tertiary vtable views, seeds `m_latencySamples[10]` and `m_pendingLatencyStartTick` to `0xffffffff`, and seeds `m_connectionFrame` to `0xffff`. |
| `0x004945e0-0x00494609` | `ConnStatusPane::~ConnStatusPane()` ordinary/non-deleting destructor | Restores vtable views, clears `g_pConnStatusPane`, and tail-calls base Pane teardown. Source C++ should represent this as the destructor body. |
| `0x00494610-0x0049461f` | `CaptureLatencyStartTick` / `BeginLatencySample` | No direct xrefs or vtable slot found, but the body is real ConnStatusPane private timing code: reads `g_pTimerMgr->currentTick` (`+0x18`) and stores it to `+0x120`, which `UpdateConnectionFrame` consumes. |
| `0x00494620-0x004946b1` | `ConnStatusPane::OnPaint()` | If `+0x124 == 0xffff`, clears the connection-status area through generic GrafPort/render helpers. Otherwise loads `CONNSTAT.EPD` through `g_pEPFLib`/`ResourceLayoutTable::LookupLayoutEntry` and draws with shared palette `NPAL7.PAL`. |
| `0x004946c0-0x00494765` | `ConnStatusPane::HandleConnectionMessage(...)` | Secondary EventHandler adjusted receiver. Switches on byte at `event+0x0c` for opcodes `0x04`, `0x0b`, `0x15`, `0x26`; updates latency frame or forces frame `4` when `g_pConfig+0x28de75` and `MapPane::meth_0x5055d0()` allow the map/status branch. |
| `0x004947a0-0x00494964` | `ConnStatusPane::UpdateConnectionFrame()` | Shifts ten-sample latency window, appends current elapsed tick delta, clears pending tick, averages valid samples, maps `<400 => 3`, `<800 => 2`, `<1200 => 1`, otherwise `0`, and invalidates on frame change. |
| `0x00494964-0x0049497a` | Destructor adjustor thunks | Compiler-generated adjusted-view thunks into the scalar deleting destructor; no handwritten C++ body. |
| `0x00494980-0x004949df` | Scalar deleting destructor | MSVC generated wrapper over the source destructor/base teardown plus conditional delete. Document but do not emit as source C++. |
```

Add field table:

```md
## ConnStatusPane Field Layout Notes

| Offset | Recommended source-facing name/type | Evidence |
| --- | --- | --- |
| `+0xf8..+0x11c` | `uint32_t m_latencySamples[10]` | Constructor seeds ten dwords to `0xffffffff`; updater shifts, filters sentinel values, and averages valid entries. |
| `+0x120` | `uint32_t m_pendingLatencyStartTick` / `m_lastRequestTick` | Constructor seeds `0xffffffff`; `0x00494610` stores `g_pTimerMgr->currentTick`; updater computes elapsed and resets sentinel. |
| `+0x124` | `uint16_t` or `int m_connectionFrame` | Constructor seeds `0xffff`; paint treats `0xffff` as invalid; updater writes `0..3` or `0xffff`; handler can force special frame `4`. |
```

Replace stale reconstruction note with:

```md
## Reconstruction Recommendation

This target clears the active first-draft C++ gate (`RECONSTRUCTABLE:TRUE`, owner/emitter [UID:000037], and average score above 85). Populate formal C++ for the constructor, ordinary destructor, `CaptureLatencyStartTick`, `OnPaint`, `HandleConnectionMessage`, and `UpdateConnectionFrame`. Do not hand-emit the two destructor adjustor thunks or the scalar deleting destructor; document them as compiler-generated ABI output from the virtual destructor.
```

### Support doc [UID:000037] `by-class/ConnStatusPane.md`

Header replacement:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace method rows:

```md
| `ConnStatusPane` | `0x00494520-0x004945df` | Constructor: calls `Pane(1)`, publishes `g_pConnStatusPane`, installs three vtable views, initializes ten latency samples plus pending tick to `0xffffffff`, and initializes frame to `0xffff`. |
| `~ConnStatusPane` | `0x004945e0-0x00494609` | Ordinary/non-deleting destructor body: restores vtable views, clears `g_pConnStatusPane`, and tails to base Pane teardown. |
| `CaptureLatencyStartTick` / `BeginLatencySample` | `0x00494610-0x0049461f` | No direct xrefs found; stores `g_pTimerMgr->currentTick` (`TimerMgr +0x18`) to `+0x120`, which the frame updater consumes. |
| `OnPaint` | `0x00494620-0x004946b1` | Clears invalid `0xffff` state or renders `CONNSTAT.EPD` frame with shared `NPAL7.PAL`. |
| `HandleConnectionMessage` | `0x004946c0-0x00494765` | Secondary EventHandler override for message opcodes `4`, `11`, `21`, `38`; updates latency frame or forces frame `4` through the `g_pConfig+0x28de75` plus `MapPane::meth_0x5055d0()` gate. |
| `UpdateConnectionFrame` | `0x004947a0-0x00494964` | Maintains ten-sample latency window and maps average thresholds `<400 => 3`, `<800 => 2`, `<1200 => 1`, else `0`, with `0xffff` invalid/no-data. |
| Destructor adjustor/scalar deleting destructor family | `0x00494964-0x004949df` | Compiler-generated thunks/wrapper from the virtual destructor; document but do not emit as handwritten source. |
| Inherited Pane/EventHandler bridge/default slots | `0x00544db0`, `0x00544dc0`, `0x00544dd0` | Shared base bridge thunks with broad vtable fan-in. Historical labels `Pane::SetConnecting` / `SetDisconnected` / `SetConnected` are aliases, not ConnStatusPane methods. |
```

Add support note:

```md
The config byte at `g_pConfig +0x28de75` is an option byte written by OptionPane control index `8` and consumed by movement/map-status packet code. Its exact UI label is not recovered here; use a descriptive alias such as `mapMovementStatusOption` until Config layout naming is finalized.
```

### Support doc [UID:0000IF] `by-file/ConnStatusPane.md`

Header replacement:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
```

Replace source placement caveat with:

```md
The active source placement is `NexusTK/network/ConnStatusPane.cpp`. Although the class paints a UI indicator, its class-local behavior is connection-message handling, latency sampling, map/config-gated status display, and the `g_pConnStatusPane` network/status singleton. A future tree-level `ui/status` split is possible, but it is no longer a blocker for this target or its first-draft C++.
```

Add generated-output note:

```md
Current `project-documentation/auto-generated/NexusTK/network/ConnStatusPane.cpp` is a zero-byte/stale generated file and must not be treated as source evidence. Re-agent generated snippets are decompilation aids only and contain generic-render helper alias pollution (`FittingRoomListPane` / `FittingRoomDownloadControlPane` names for shared GrafPort/tile-frame helpers).
```

### Support doc [UID:000252] `ControlPaneReadOnlyData`

Insert after observed ConnStatusPane vtable bullet:

```md
- ConnStatusPane adjusted vtable split opportunity: the secondary vtable at `0x00617a38` has 11 slots, including destructor adjustor `0x00494964`, inherited Pane/EventHandler bridge slots `0x00544db0`/`0x00544dc0`/`0x00544dd0`, and `ConnStatusPane::HandleConnectionMessage` at slot 4. The tertiary vtable at `0x00617a68` has two slots, `0x0049496f` and inherited `0x00544e90`. The UTF-16 `CONNSTAT.EPD` literal starts at `0x00617a70`, so an exact child `0x00617a38-0x00617a70.ConnStatusPaneAdjustedVtableData.md` can be split under [UID:000037] without absorbing the string literal.
```

### Support doc [UID:00028Q] `g_pConfig`

Append to Known Field Clusters:

```md
| `+0x28de75` | Map/movement status option byte | Written by OptionPane control index `8` as the inverse checked state; consumed by `ConnStatusPane::HandleConnectionMessage`, `UserStatusPane2`, and LivingObjectPane movement/object packet code together with `MapPane::meth_0x5055d0()`. Exact original UI label is unresolved; use descriptive aliases such as `mapMovementStatusOption` / `sendMovementStatusBit` until final Config naming is recovered. |
```

### Support doc [UID:0002B9] `g_pConnStatusPane`

No metadata change required. Optional support note:

```md
The source declaration is ready for first-draft file-level C++ as `static ConnStatusPane *g_pConnStatusPane;`; the remaining caveat is linkage/header spelling, not ownership or storage identity.
```

### Project stats

Replace both duplicate lines in `project-level/-auto-completion-stats.md`:

```md
| `000113` | 88 | 90 | 89.0 | `by-memory/0x00494520-0x004949df.ConnStatusPane.md` |
```

Validator commands after supervisor application:

> Executable block R001 was removed from this report and preserved verbatim in [000113-ConnStatusPane-source-quality-removed.md](000113-ConnStatusPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Coverage Row Recommendation

### `by-memory/-coverage-report.md`

Replace current [UID:000113] row with:

```md
    - [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md) : reconstructable : 88% : very strong : B002 2026-06-18 source-quality pass resolves ConnStatusPane as a coherent class-owned `network/ConnStatusPane.cpp` source island: constructor, ordinary destructor, no-direct-xref latency-start helper, OnPaint, EventHandler message override, UpdateConnectionFrame, destructor thunks/scalar wrapper policy, singleton lifecycle, vtable views, `+0xf8..+0x11c` latency samples, `+0x120` pending tick, `+0x124` frame, `CONNSTAT.EPD`/`NPAL7.PAL` draw path, opcodes `0x04/0x0b/0x15/0x26`, config/map gate, stale generated-output caveat, and first-draft C++ readiness are documented.
```

Replace current [UID:00035G] row with:

```md
        - [UID:00035G][0x006179ec-0x00617a38.ConnStatusPanePrimaryVtableData](by-memory/0x006179ec-0x00617a38.ConnStatusPanePrimaryVtableData.md) 0x006179ec-0x00617a38 | vtable-data | ConnStatusPanePrimaryVtableData : reconstructable : 87% : very strong : Exact primary ConnStatusPane vtable tail before the adjusted secondary vtable at `0x00617a38`; current exported vtable data confirms 18 entries with scalar deleting destructor at slot 0 and `ConnStatusPane::OnPaint` at slot 17, and constructor/reset/destructor stores from `0x00494520`, `0x004945e0`, and `0x00494980`. Owner/emitter [UID:000037][ConnStatusPane] now clears the active gate; adjusted vtable views at `0x00617a38`/`0x00617a68` remain a recommended exact split from [UID:000252].
```

Replace current [UID:0002B9] row with:

```md
      - [UID:0002B9][0x0069adf4-0x0069adf8.g_pConnStatusPane](by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md) 0x0069adf4-0x0069adf8 | global-data pointer | g_pConnStatusPane : reconstructable : 85% : very strong : ConnStatusPane-owned singleton pointer emitted through [UID:0000IF]; live IDA-backed docs confirm the exact four-byte slot, constructor publish at `0x00494545`, ordinary destructor/reset clear at `0x004945fa`, scalar deleting destructor clear at `0x004949a0`, MapPane exit cleanup read at `0x00504a32`, and neighboring singleton-slot boundaries.
```

Replace current [UID:000252] row with:

```md
    - [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md) 0x00617a38-0x00618858 | vtable/string-data | ControlPaneReadOnlyData : ignored : 85% : very strong : Non-emitting mixed `.rdata` index with exact child pages for source-owned vtable/resource units; current docs record ConnStatusPane adjusted vtables at `0x00617a38` and `0x00617a68`, ControlPane/ProgressBar/NumericString/Rectangle/CheckBox child splits, resource-string samples including `CONNSTAT.EPD`, and successor Crasher boundary. Keep the aggregate unassigned; split `0x00617a38-0x00617a70.ConnStatusPaneAdjustedVtableData` under [UID:000037] if exact vtable coverage is desired.
```

### `by-class/-coverage-report.md`

Replace [UID:000037] row with:

```md
- [UID:000037][ConnStatusPane](by-class/ConnStatusPane.md) : reconstructable : 88% : very strong : ConnStatusPane class with constructor/destructor family, singleton lifecycle, primary/adjusted vtables, no-direct-xref latency-start helper, OnPaint resource draw, EventHandler message override, rolling latency frame updater, `+0xf8..+0x124` field layout, config/map gate, inherited Pane/EventHandler bridge-slot exclusions, generated-output caveat, and first-draft C++ readiness documented.
```

### `by-file/-coverage-report.md`

Replace [UID:0000IF] row with:

```md
- [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md) : reconstructable : 88% : very strong : `NexusTK/network/ConnStatusPane.cpp` source root for the in-game connection-status indicator, latency sampling, connection-message handling, `CONNSTAT.EPD`/`NPAL7.PAL` draw path, `g_pConnStatusPane` singleton, exact local method/vtable/support rows, config/map status gate, stale zero-byte generated output warning, and first-draft C++ readiness; `ui/status` remains only a future tree-organization alternative, not an active blocker.
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/000113-ConnStatusPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"000113"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000113-ConnStatusPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/000113-ConnStatusPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000113"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
