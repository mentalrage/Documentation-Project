** TARGET-REPORT-UID:0002R6 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B007 Report: [UID:0002R6] FlyingParcelPaneStartAnimation Source Quality

## Assignment

- Assignment id: `B007-report-0002R6-FlyingParcelPaneStartAnimation-source-quality-20260627`
- Target: [UID:0002R6] `by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md`
- Required mode: report first only. No target/support by-* edits were made.
- MCP requirement: satisfied through live IDA MCP session `398b87c1`.

## Decision

Recommend implementing [UID:0002R6] as a source-ready `FlyingParcelPane::StartAnimation(...)` method.

The old no-direct-route fact is still true, but it is no longer a sufficient no-code proof. Current MCP and PE checks still show no IDA function object, no direct xrefs, and no VA/RVA/rel32 route to `0x00546bc0`; however, the body is exact, bounded, source-shaped, and now sits in a class/file route where adjacent raw/no-route `FlyingParcelPane::~FlyingParcelPane()` already emits first-draft C++ under the accepted B004 precedent. The target already has `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:000058`, a valid direct class owner [UID:000058], and a file route through [UID:0000MF] `ParcelPane.cpp`.

Recommended metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `90` |
| `CONFIDENCE` | `88` | `90` |
| `CANONICAL_OWNER` | `000058` | unchanged |
| `RECONSTRUCTABLE` | `TRUE` | unchanged |
| `EMITTER_UIDS` | `000058` | unchanged |
| `EMITTER_POSITION_OPTIONAL` | blank | unchanged |
| Formal C++ | blank | populate exact block below |

Rationale for `90/90`: first-draft C++ is now justified, the range/body/helper names are current-MCP backed, and the sibling source route is accepted. Confidence should stay below the destructor child `90/92` and the vtable-reached animate/draw children `91/92` because this raw start still has no direct caller, pointer, vtable slot, or recovered original source declaration.

## Current Target State

The target header is currently:

- `UID:0002R6`
- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:000058`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000058`
- blank formal C++

The existing page correctly documents the physical behavior, but its blank-C++ rationale is stale after the recent accepted `FlyingParcelPane` child implementations:

- [UID:0002KJ] constructor now emits `FlyingParcelPane::FlyingParcelPane()`.
- [UID:0002R5] raw cleanup destructor now emits `FlyingParcelPane::~FlyingParcelPane()` despite no direct raw start route.
- [UID:0002KK] timer callback now emits `FlyingParcelPane::AnimateStep(int, int, int)`.
- [UID:0002KL] draw body now emits `FlyingParcelPane::DrawParcelOrLetter()`.

Those pages establish the field names, helper names, file route, and source-family treatment needed for this target.

## Evidence Read

Current by-* and generated inputs reviewed:

- Target [UID:0002R6] `0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation`
- Aggregate [UID:0001EL] `0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart`
- Class [UID:000058] `FlyingParcelPane`
- File [UID:0000MF] `ParcelPane`
- Siblings [UID:0002KJ], [UID:0002R5], [UID:0002KK], [UID:0002KL]
- Layout [UID:0001VI] `ParcelNotificationPaneLayouts`
- Vtable support [UID:0001YE] and exact vtable data [UID:0002OH]
- Globals [UID:0000SW] `g_useEpfAssets`, [UID:0000S7] `g_pScreenPane`, [UID:0000RY] `g_pParcelPane`, and memory [UID:00028R] `g_pSoundManager`
- Generated output `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`

Generated output is current enough to prove the immediate problem: `ParcelPane.cpp` already emits constructor, cleanup destructor, animate step, draw, ParcelPane constructor/setter/mouse/paint bodies, while [UID:0002R6] is still an empty marker. Generated reports still show stale `80/86` rows for this target; those are validator-owned refresh artifacts and should not be manually edited.

## MCP Session

MCP was mandatory for this report and was available.

- JSON-RPC `initialize`: server `ida-pro-mcp`, protocol `2025-06-18`.
- MCP request id `3`, `idb_list`: active session `398b87c1`; input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `is_analyzing:false`; backend `worker`; PID `23700`.
- MCP request id `4`, `server_health`: `status:ok`; module `NexusTK.exe`; input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; imagebase `0x400000`; `auto_analysis_ready:true`; `hexrays_ready:true`; `strings_cache_ready:true`.

No MCP fallback-only evidence is used.

## Boundary And Route Evidence

MCP request id `10`, `lookup_funcs`, reports:

| Address | Result |
| --- | --- |
| `0x00546bb5` | not a function |
| `0x00546bc0` | not a function |
| `0x00546d64` | not a function |
| `0x00546d70` | `sub_546D70`, size `0x7e` |
| `0x00546b80` | not a function |
| `0x00546ac0` | `sub_546AC0`, size `0xb4` |
| `0x00546df0` | `sub_546DF0`, size `0x7b` |
| `0x00556ce0` | `sub_556CE0`, size `0x3b` |
| `0x005975e0` | `sub_5975E0`, size `0x1f` |
| `0x0057a5c0` | `sub_57A5C0`, size `0xff` |
| `0x004b7c50` | `sub_4B7C50`, size `0x1f` |

MCP request id `11`, `xrefs_to`, reports:

- `0x00546bc0`: zero xrefs.
- `0x00546d64`: zero xrefs.
- `0x00546d70`: one data xref from `0x00621d4c`.
- `0x00621ccc`, `0x00621d18`, and `0x00621d48`: constructor, raw cleanup, and scalar-wrapper vtable-store refs, matching the established `FlyingParcelPane` lifecycle route.

MCP request id `12`, `get_bytes`, confirms:

- `0x00546bb5-0x00546bc0`: eleven `0xcc` bytes.
- `0x00546bc0-0x00546d64`: exact 420-byte body.
- `0x00546d64-0x00546d70`: twelve `0xcc` bytes.

MCP request id `13`, `insn_query`, returns 126 ownerless instructions for `0x00546bc0-0x00546d64`, all `fn:null`, ending in `retn 10h` at `0x00546d61`.

MCP request id `18`, `decompile 0x00546bc0`, returns `code:null` and `Decompilation failed at 0x546bc0`.

MCP request id `19`, `callees`, returns `No function found` for `0x00546bc0`, while the adjacent modeled siblings return their expected callees.

Supplemental read-only PE scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`:

- Image base: `0x400000`
- Target VA/RVA: `0x00546bc0` / `0x00146bc0`
- Sections: `.text` executable; `.rdata`, `.data`, `.rsrc` non-executable.
- Absolute VA dword hits for `0x00546bc0`: `0`
- RVA dword hits for `0x00146bc0`: `0`
- Direct executable `E8`/`E9` branch hits to `0x00546bc0`: `0`

Conclusion: no direct route has appeared. This remains a confidence cap, not a current no-code proof.

## Raw Behavior Evidence

MCP request id `13` proves the body shape:

- `0x00546bc0-0x00546bcd`: security-cookie frame setup.
- `0x00546bd0`: `cmp byte_66DA97, 1`; `jnz 0x00546ca7` selects legacy/non-EPF path.
- `0x00546bd8`: first stack byte argument is loaded into `bl`.
- `0x00546bdc`: `esi = ecx`, preserving the `FlyingParcelPane *this`.
- `0x00546be4-0x00546bf1`: current/EPF branch calls `sub_57A5C0` on `dword_67A7D0` with sample id `0xc8` / 200 and volume `0x64` / 100.
- `0x00546bf6-0x00546c04` and `0x00546ca7-0x00546cb5`: both branches call `sub_556CE0` on `dword_67A7CC` with `this+0x100` and frame/index `0`.
- `0x00546c14-0x00546c36` and `0x00546cbd-0x00546cdb`: store payload fields:
  - `+0xfb` = second arg, accepted `m_leftSlot`
  - `+0xfa` = third arg, accepted `m_rightSlot`
  - `+0xf9` = first arg, accepted `m_parcelCountOrState`
  - `+0xfc` = fourth arg, accepted `m_isParcel`
  - `+0xf8` = `0`, accepted `m_animationFrame`
- `0x00546c67` and `0x00546d0c`: call `sub_4B7C50`, the rectangle setter.
- `0x00546c73` and `0x00546d18`: call vtable slot `+0x38`, accepted `Pane::RemoveFromLayer`.
- `0x00546c88` and `0x00546d2d`: call vtable slot `+0x30`, accepted `Pane::AddToLayer`.
- `0x00546c90`: current/EPF branch adds `0x1e` / 30 to inherited owner `+0xac`, accepted `m_origin.x`.
- `0x00546c9a` and `0x00546d38`: call vtable slot `+0x20`, accepted `Pane::InvalidateRect`.
- `0x00546d47-0x00546d4d`: schedules `this+0xa4` through `sub_5975E0`; current/EPF delay is `100`, legacy delay is `10`.
- `0x00546d59-0x00546d61`: security cookie check and `retn 10h`.

Rectangle evidence from the instruction sequence:

| Branch | Condition | Rect |
| --- | --- | --- |
| current/EPF | `m_isParcel != 0` | `(630, 730, 659, 755)` |
| current/EPF | `m_isParcel == 0` | `(667, 730, 698, 747)` |
| legacy/non-EPF | `m_parcelCountOrState <= 4` | `left = 397 + count * 11`, `top = 4`, `right = 419 + count * 11`, `bottom = 26` |
| legacy/non-EPF | `m_parcelCountOrState > 4` | same as count `4`: `(441, 4, 463, 26)` |

MCP request id `21`, `make_signature_for_range 0x00546bc0-0x00546d64`, returns a unique full-range IDA signature. This is useful implementation evidence but too long for target prose unless the supervisor wants exact signature text added.

## Helper Name Evidence

MCP helper checks support the current source-facing names:

- Request id `14`, `analyze_function 0x00556ce0`: `sub_556CE0`, size `59`, takes `this`, a pointer-like argument, and an index/frame argument, reaches `sub_559360` when the third argument is nonzero, and dispatches to a root screen/layer vslot. Existing docs name this source-facing operation `ScreenPane::SetLayerFrame`.
- Request id `15`, `analyze_function 0x0057a5c0`: `sub_57A5C0`, size `255`, operates on `SoundManager`, rotates/reuses sample slots, sets sample file/volume, and starts the sample through Miles. Existing docs name this `SoundManager::PlaySample`.
- Request id `16`, `analyze_function 0x004b7c50`: `sub_4B7C50`, size `31`, writes four dwords into a rectangle in left/top/right/bottom layout. Existing generated C++ already uses `SetRect`.
- Request id `17`, `analyze_function 0x005975e0`: `sub_5975E0`, size `31`, wraps `sub_597910(unk_67AB80, this, a2, a3, a4, a5)`. Existing docs and generated C++ use `m_timerHandler.ScheduleTimer(...)`.
- `PaneVtables.md` and `PaneCore.md` resolve slots `+0x20`, `+0x30`, and `+0x38` as `Pane::InvalidateRect`, `Pane::AddToLayer`, and `Pane::RemoveFromLayer`.

MCP request id `20`, `get_int`, confirms related values:

- `0x00621ccc -> 0x00546ed0` primary scalar deleting destructor
- `0x00621d10 -> 0x00546df0` draw slot
- `0x00621d18 -> 0x00546e8b` secondary destructor adjustor
- `0x00621d48 -> 0x00546e96` tertiary destructor adjustor
- `0x00621d4c -> 0x00546d70` timer/animate slot
- `0x0067a7cc` and `0x0067a7d0` are zero-initialized singleton storage slots
- `0x0066da97` is initialized to `1`

## Rejected Alternatives

- Keep formal C++ blank only because `0x00546bc0` has no function/xref/direct-route: rejected. The same class now has an accepted raw no-route destructor child that emits source when the ordinary source body is proven by exact bytes, ownership, and source-family context. This target now clears the current code-entry gate too.
- Split the range: rejected. MCP confirms exact padding before and after, one coherent `thiscall` body, one `retn 10h`, and no internal padding/dead island.
- Move ownership to `ScreenPane`, `SoundManager`, `TimerHandler`, `Layer`, `g_useEpfAssets`, or a new `FlyingParcelPane.cpp`: rejected. Those are dependencies. The body mutates `FlyingParcelPane` fields and uses the accepted [UID:000058] class route through [UID:0000MF] `ParcelPane.cpp`.
- Emit source from [UID:0001EL] aggregate: rejected. The aggregate remains a non-emitting split inventory.
- Use raw labels such as `sub_556CE0`, `sub_57A5C0`, `dword_67A7CC`, `dword_67A7D0`, or `byte_66DA97` in formal C++: rejected. Current support docs have accepted source-facing names.
- Treat `+0xac` as a derived `FlyingParcelPane` payload field: rejected. Layout and animate-step pages identify it as inherited `Pane::m_origin.x`.
- Treat the fourth argument as an animation-state byte rather than parcel/letter selector: rejected. Draw child [UID:0002KL] uses `m_isParcel` to choose parcel versus letter art.

## Exact C++ Recommendation

Set the target formal code block to:

```cpp
void FlyingParcelPane::StartAnimation(unsigned char parcelCountOrState,
                                      unsigned char leftSlot,
                                      unsigned char rightSlot,
                                      bool isParcel)
{
    RectBounds animationRect;

    if (g_useEpfAssets == 1) {
        g_pSoundManager->PlaySample(200, 100);
        g_pScreenPane->SetLayerFrame(m_animationLayer, 0);

        m_leftSlot = leftSlot;
        m_rightSlot = rightSlot;
        m_parcelCountOrState = parcelCountOrState;
        m_isParcel = isParcel;
        m_animationFrame = 0;

        if (isParcel) {
            SetRect(&animationRect, 630, 730, 659, 755);
        } else {
            SetRect(&animationRect, 667, 730, 698, 747);
        }

        RemoveFromLayer();
        AddToLayer(&animationRect, 0, nullptr, m_animationLayer);
        m_origin.x += 30;
        InvalidateRect(&m_bounds);
        m_timerHandler.ScheduleTimer(0, 100, 0, 0);
        return;
    }

    g_pScreenPane->SetLayerFrame(m_animationLayer, 0);

    m_leftSlot = leftSlot;
    m_rightSlot = rightSlot;
    m_parcelCountOrState = parcelCountOrState;
    m_isParcel = isParcel;
    m_animationFrame = 0;

    const int displaySlot =
        parcelCountOrState <= 4 ? parcelCountOrState : 4;
    SetRect(&animationRect,
            397 + displaySlot * 11,
            4,
            419 + displaySlot * 11,
            26);

    RemoveFromLayer();
    AddToLayer(&animationRect, 0, nullptr, m_animationLayer);
    InvalidateRect(&m_bounds);
    m_timerHandler.ScheduleTimer(0, 10, 0, 0);
}
```

Notes on this block:

- It intentionally compares `g_useEpfAssets == 1`, matching the raw `cmp byte_66DA97, 1`.
- It keeps the current/EPF branch's `PlaySample(200, 100)` and `m_origin.x += 30`.
- It preserves both branch delays: `100` ms for current/EPF and `10` ms for legacy/non-EPF.
- It clamps only the legacy display rectangle slot to `4`; the stored `m_parcelCountOrState` remains the raw first argument.
- It uses the existing accepted generated names `RectBounds`, `SetRect`, `RemoveFromLayer`, `AddToLayer`, `InvalidateRect`, `m_timerHandler.ScheduleTimer`, and `m_animationLayer`.

## Required Implementation Edits If Accepted

Target [UID:0002R6]:

1. Raise metadata to `COMPLETION:90`, `CONFIDENCE:90`.
2. Preserve `CANONICAL_OWNER:000058`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000058`, and blank `EMITTER_POSITION_OPTIONAL`.
3. Replace the blank `RECONSTRUCTION_CPP CODE` block with the exact `FlyingParcelPane::StartAnimation(...)` body above.
4. Update Status/Rebuild handling to say this target is source-ready first-draft C++ through [UID:000058] and [UID:0000MF].
5. Replace the old blank-C++/no-direct-route rationale with current MCP evidence: request ids `3`, `4`, `10-21`, plus the supplemental PE scan.
6. Update rectangle evidence to include both EPF `m_isParcel` coordinate sets and the legacy count clamp.
7. Keep no-direct-route evidence as a confidence cap, not a no-code blocker.
8. Add a Changes entry for this accepted report and later implementation.

Support pages that should be synchronized:

1. [UID:0001EL] `0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart`
   - Change the summary/status wording from "0002R6 retains independent raw-start caveats" to "0002R6 is now source-ready but retains no-direct-route confidence caps."
   - Keep the aggregate `RECONSTRUCTABLE:FALSE`, blank emitters, and blank C++.
2. [UID:000058] `FlyingParcelPane`
   - Update the method table/notes to mark [UID:0002R6] source-ready with first-draft C++.
   - Remove raw `StartAnimation` as a class-level blank-C++ blocker.
   - Preserve the class-level blank formal block for declaration visibility, private/file-local helper exposure, and shared helper signatures.
3. [UID:0000MF] `ParcelPane`
   - Add a file-role paragraph recording that [UID:0002R6] now emits `FlyingParcelPane::StartAnimation(...)` through `ParcelPane.cpp`.
   - Remove raw `StartAnimation` from remaining file-level C++ blockers.
   - Preserve final folder/private-helper/shared-helper caveats.
4. [UID:0002R5] cleanup destructor
   - No metadata or C++ change.
   - Adjust score/confidence rationale wording that currently treats sibling [UID:0002R6] as an unresolved source-shape caveat. It should become a no-direct-route/original-declaration confidence cap only.
5. [UID:0002KJ] constructor
   - No metadata or C++ change.
   - If retaining the class-level caveat paragraph, remove stale "raw cleanup/start bodies" wording and replace it with declaration/shared-helper caveats plus raw no-direct-route confidence caps.
6. [UID:0002KK] animate step
   - No metadata or C++ change.
   - Update the 2026-06-26 caveat wording so it no longer names raw `StartAnimation` source-entry policy as unresolved after this implementation.
7. [UID:0002KL] draw body
   - No metadata or C++ change.
   - Optional wording sync only if it still frames raw-start absence as a source-shape blocker. Keep it as a raw-sibling confidence cap.

Support pages that do not need content changes unless the supervisor wants broader changelog propagation:

- [UID:0001VI] `ParcelNotificationPaneLayouts`: already has the accepted field names and correctly says `StartAnimation` attaches/configures `m_animationLayer`.
- [UID:0001YE] and [UID:0002OH] vtable pages: no StartAnimation slot exists; current lifecycle/vtable evidence remains accurate.
- [UID:0000SW] `g_useEpfAssets`, [UID:0000S7] `g_pScreenPane`, [UID:0000RY] `g_pParcelPane`, and [UID:00028R] `g_pSoundManager`: they are dependency/global evidence only and do not need route changes.

Generated/manual report handling:

- Do not manually edit `auto-generated/` reports or `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`.
- After validator refresh, generated `ParcelPane.cpp` should replace the [UID:0002R6] empty marker with the new `FlyingParcelPane::StartAnimation(...)` body, ideally ordered after the destructor and before `AnimateStep`.
- Do not manually edit `by-memory/-coverage-report.md` or any manual `-coverage-report.md`. It currently has stale target text, but that is outside B007's edit scope under the current instructions.

## Validators To Run During Implementation Callback

Run scoped validators only after leasing and editing the accepted by-* files. Suggested sequence:

> Executable block R001 was removed from this report and preserved verbatim in [0002R6-FlyingParcelPaneStartAnimation-source-quality-removed.md](0002R6-FlyingParcelPaneStartAnimation-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If generated output is deferred, run:

> Executable block R002 was removed from this report and preserved verbatim in [0002R6-FlyingParcelPaneStartAnimation-source-quality-removed.md](0002R6-FlyingParcelPaneStartAnimation-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Then confirm `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` contains the [UID:0002R6] body and no stale empty marker for the target. Generated files remain validator-owned.

## Implementation Tracking Checklist

Implementation callback status: accepted by supervisor and applied by B007 on 2026-06-27.

- [x] Target [UID:0002R6] metadata raised to `90/90`; owner/emitter/reconstructable route preserved. Proof: `by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md` now has `COMPLETION:90`, `CONFIDENCE:90`, `CANONICAL_OWNER:000058`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000058`, and blank emitter position.
- [x] Target [UID:0002R6] formal C++ populated exactly from this report. Proof: the target formal `RECONSTRUCTION_CPP CODE` block now contains `void FlyingParcelPane::StartAnimation(unsigned char parcelCountOrState, unsigned char leftSlot, unsigned char rightSlot, bool isParcel)` with the accepted EPF/current branch, legacy branch, rectangle selection, field stores, layer calls, and 100/10 ms timer scheduling.
- [x] Target [UID:0002R6] status, raw evidence, rectangle table, no-direct-route proof, score rationale, generated expectation, and Changes entry updated. Proof: target page now documents MCP session `398b87c1`, request ids `3`, `4`, `10-21`, supplemental PE no-route scan, rectangle/delay table, helper/source-name decisions, rejected alternatives, score `90/90` rationale, and a 2026-06-27 change entry.
- [x] [UID:0001EL] aggregate updated to record [UID:0002R6] source-ready while remaining non-emitting. Proof: `by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md` keeps aggregate `RECONSTRUCTABLE:FALSE`, blank emitters/C++, and now states [UID:0002R6] emits source-ready `StartAnimation(...)` while raw no-direct-route facts remain confidence caps.
- [x] [UID:000058] class page updated to remove raw `StartAnimation` as a class-level C++ blocker while preserving declaration/helper caveats. Proof: `by-class/FlyingParcelPane.md` method table and no-code/defer proof now list [UID:0002R6] as accepted method-level C++ and keep class-level blank C++ only for declaration/source-placement and shared helper signature issues.
- [x] [UID:0000MF] file page updated to record [UID:0002R6] emission through `ParcelPane.cpp` and remove raw `StartAnimation` from file-level blockers. Proof: `by-file/ParcelPane.md` now has a 2026-06-27 B007 `StartAnimation(...)` paragraph, narrows older B012/B007/B003 caveats, and states remaining file-level caveats are private declaration visibility and shared helper signatures, not raw StartAnimation source entry.
- [x] [UID:0002R5] no-score support wording synchronized. Proof: `by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md` now states the sibling [UID:0002R6] is source-ready and no longer an unresolved source-shape caveat for the destructor child.
- [x] [UID:0002KJ] no-score support wording synchronized where stale raw cleanup/start caveat remained. Proof: `by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md` now narrows the class-level blocker to declaration visibility/shared helper declarations while noting raw cleanup/start children carry method-level source C++.
- [x] [UID:0002KK] no-score support wording synchronized. Proof: `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md` now says raw `StartAnimation` is a caller/declaration confidence cap after [UID:0002R6] became source-ready.
- [x] [UID:0002KL] no-score support wording synchronized if needed. Proof: `by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md` was reviewed and already framed raw sibling absence as a class-level confidence caveat rather than a method C++ blocker, so no edit or validator run was needed.
- [x] Scoped validators run for every changed by-* file. Proof:
  - `python .\tools\validator.py --mode file --file .\by-memory\0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md --apply --queue-timeout 240 --wait-generated`: `command_id:000000004459`, `command_timestamp:2026-06-27T20:54:27-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
  - `python .\tools\validator.py --mode file --file .\by-memory\0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md --apply --queue-timeout 240`: `command_id:000000004460`, `command_timestamp:2026-06-27T20:54:59-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file .\by-class\FlyingParcelPane.md --apply --queue-timeout 240`: `command_id:000000004462`, `command_timestamp:2026-06-27T20:55:06-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file .\by-file\ParcelPane.md --apply --queue-timeout 240`: `command_id:000000004463`, `command_timestamp:2026-06-27T20:55:16-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file .\by-memory\0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md --apply --queue-timeout 240`: `command_id:000000004466`, `command_timestamp:2026-06-27T20:55:24-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file .\by-memory\0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md --apply --queue-timeout 240`: `command_id:000000004470`, `command_timestamp:2026-06-27T20:55:39-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file .\by-memory\0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md --apply --queue-timeout 240`: `command_id:000000004474`, `command_timestamp:2026-06-27T20:55:53-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Validator-owned generated output checked after refresh; [UID:0002R6] no longer appears as an empty marker in generated `ParcelPane.cpp`. Proof: `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` header showed `validator-command-id: 000000004487`, `validator-refreshed-at: 2026-06-27T20:57:19-04:00`, `validator-refresh-source: foreground-generated-refresh`; `rg` found [UID:0002R6] at line 25 followed by `FlyingParcelPane::StartAnimation(...)` at line 26 and found no `UID:0002R6 ... Empty Emitter Marker`.
- [x] No generated reports, generated C++ files, project-level generated reports, manual coverage reports, validator/tool state, or IDA DB files manually edited. Proof: only by-* support docs and this report were edited manually. Validator-owned side effects occurred through scoped validator commands, including generated C++/coverage/tracker/projected stats/`tools/validator.ini` refreshes.
- [x] All edit leases taken during the implementation callback are released immediately after the edit/validator batch. Proof: B007 leased the seven changed by-* docs plus this report before final patch/validation; `python .\tools\leaser\leaser.py B007 unlease ...` returned `Success` for all eight paths, and the final lease scan returned no B007 entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002R6-FlyingParcelPaneStartAnimation-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002R6-FlyingParcelPaneStartAnimation-source-quality.md","timestamp":"2026-06-27T20:59:54","uid":"0002R6"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002R6-FlyingParcelPaneStartAnimation-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0002R6-FlyingParcelPaneStartAnimation-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002R6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
