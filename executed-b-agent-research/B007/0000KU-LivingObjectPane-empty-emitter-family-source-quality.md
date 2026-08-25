** TARGET-REPORT-UID:0000KU **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000KU LivingObjectPane Empty-Emitter Family Source-Quality Report

Assignment: `B007-report-0000KU-LivingObjectPane-empty-emitter-family-20260701`

Target: [UID:0000KU] `by-file/LivingObjectPane.md` / generated `auto-generated/NexusTK/map/LivingObjectPane.cpp`

Mode: report-only research. No by-* docs, generated files, project-level generated reports, validator/tool state, queue files, archives, supervisor ledgers, coverage reports, or IDA database state were edited.

## Executive Recommendation

Keep [UID:0000KU] as the `NexusTK/map/LivingObjectPane.cpp` file root and keep it non-emitting at the broad by-file level. Exact child pages remain the correct place for source C++.

Recommended [UID:0000KU] metadata after incorporation: raise from `COMPLETION:88` / `CONFIDENCE:85` to `COMPLETION:89` / `CONFIDENCE:88`. Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"` and `CANONICAL_OWNER:FILE`.

Reason for the modest score increase: this pass ties the current generated-output state to fresh MCP evidence, inventories all 14 empty markers, identifies one safe first implementation target, and proves that most remaining empty markers are intentional broad-class/data/raw-helper markers rather than missing obvious file-level C++. Do not raise higher yet: broad class declarations remain blank, constructor and inventory-dispatch child bodies still have source-name/layout blockers, and several raw helpers have no live route.

Highest-value first implementation batch:

1. Update `by-file/LivingObjectPane.md` with a 2026-07-01 generated-output audit section: current generated header proof, 11 populated/non-empty outputs, 14 empty markers, and the triage below.
2. Update [UID:0003UE] `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md`: raise from `86/88` to `88/90`, keep owner/emitter [UID:00007B], and populate first-draft formal C++ for `LivingObjectPane::WarpToPosition`. Current MCP now resolves the remaining blocker enough for a child-scoped first draft.
3. Do not populate broad by-file/class C++. Do not emit C++ for raw no-route helpers [UID:0003UV], [UID:0003UX], [UID:0003UY], data/type/global markers [UID:000357], [UID:000358], [UID:0002WL], [UID:0001TR], [UID:00030B], or broad class/lifetime pages [UID:00007B], [UID:00007C], [UID:0002R0] in this batch.

## MCP Status

IDA MCP was available and used. Active database session `supervisor_resume_20260629` was reported by `idb_list`; `server_health` request `4` returned `status: ok`, module `NexusTK.exe`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.

MCP calls used for this report:

| Request | Tool | Evidence used |
| ---: | --- | --- |
| `4` | `server_health` | MCP/IDA availability and active database health. |
| `5` | `lookup_funcs` | Representative generated/empty marker function facts: `0x0053a110`, `0x0053a360`, `0x0053b700`, `0x0053bb20`, `0x0053bd20`, `0x0053bdc0`, `0x0053d030`, `0x0053d7c0`, `0x005a2de0`, `0x005a3e30`, `0x005a4530`, `0x005a58c0`, `0x005a8810`, `0x005a88d0`, `0x005ac070`, `0x005acc30`; no function at raw starts `0x005a87b0`, `0x005aaff0`, `0x005ac1b0`, `0x005ac7e0`, `0x005ac9a0`, `0x005acae0`. |
| `6` | `entity_query` | Decorated vtable names `??_7BoxRotator@LivingObjectPane@@6B@`, `??_7LivingObjectPane@@6B@`, and adjusted `LivingObjectPane` vtable views. |
| `7` | `analyze_function 0x0053b700` | Reconfirmed [UID:0002R1] timer source body, timer id `FWdA`, frame animation setup, and generated output consistency. |
| `8` | `analyze_function 0x0053d7c0` | Reconfirmed [UID:0003Z9] `BoxRotator::Advance` owner-pointer callback and vtable data route. |
| `9` | `analyze_function 0x005a3e30` | Reconfirmed [UID:0001KN] inventory dispatch as a real 451-byte function with selector `1..52`, slot table, direct send, and ItemWho fallback, but still broad/local-name blocked. |
| `10` | `analyze_function 0x005ac070` | Reconfirmed [UID:0003UU] message-show handler is a static/file-local packet helper with one stack packet argument, not a `LivingObjectPane` instance method. |
| `11` | `xrefs_to` | Reconfirmed raw no-route status for `0x005a87b0`, `0x005aaff0`, `0x005ac1b0`, `0x005ac7e0`, `0x005ac9a0`, `0x005acae0`; vtable and constructor/destructor data refs for BoxRotator/LivingObjectPane vtables. |
| `12` | `disasm 0x005ac1b0` | Reconfirmed raw [UID:0003UV] body shape, packet reads, `m_isMoving` gate, call to `0x005a5a90`, and no modeled function object. |
| `24` | `analyze_function 0x005a5a90` | Fresh proof that [UID:0003UE] is a real 233-byte `thiscall` helper with four explicit args, twelve code xrefs, `ValidateMapAndViewportCoords`, `ReindexObjectPanePosition`, viewport stores, timer cancels, `ClearAllEffects`, movement-state clears, and final invalidation. |
| `25` | `analyze_function 0x0053aec0` | Reconfirmed [UID:0001DF] detach helper sole caller, registry switch, and blank-C++ blocker on names/types rather than owner. |
| `26` | `xrefs_to 0x005a5a90` | Reconfirmed twelve code xrefs into `WarpToPosition`, including live dispatcher paths, movement handlers, retained raw duplicate call `0x005ab047`, and raw position-sync call `0x005ac221`. |
| `27` | `xrefs_to 0x0053aec0` | Reconfirmed the sole code xref from `AttachedObjectPane` destructor at `0x005382b0`. |

## Documentation And Prior Reports Checked

Current docs checked:

- `by-file/LivingObjectPane.md`
- `auto-generated/NexusTK/map/LivingObjectPane.cpp`
- `auto-generated/-ag-research-tracker.md` row for [UID:0000KU]
- `project-level/-auto-completion-stats.md` row for [UID:0000KU]
- `by-class/LivingObjectPane.md`
- `by-class/LivingObjectPane__BoxRotator.md`
- Empty-marker target/support pages for [UID:000357], [UID:000358], [UID:0002WL], [UID:0001TR], [UID:00030B], [UID:0002R0], [UID:0001DF], [UID:0001KN], [UID:0003UE], [UID:0003UV], [UID:0003UX], and [UID:0003UY].

Prior executed reports were searched with UID/name/path terms. Relevant reports used as leads include:

- `executed-b-agent-research/B001/00007B-LivingObjectPane-class-source-quality.md`
- `executed-b-agent-research/B001/0001DE-LivingObjectPaneCore-source-quality.md`
- `executed-b-agent-research/B001/0002R2-LivingObjectPaneRenderFrameMethods-report.md`
- `executed-b-agent-research/B001/0002R3-LivingObjectPaneScalarDeletingDestructor-report.md`
- `executed-b-agent-research/B001/00030B-g_lastFunctionKeyTick.md`
- `executed-b-agent-research/B007/0002R1-LivingObjectPaneAnimationTimer-source-quality.md`
- `executed-b-agent-research/B006/0002RW-LivingObjectPaneGetViewportPosition-source-quality.md`
- `executed-b-agent-research/B006/0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality.md`
- `executed-b-agent-research/B009/0002T6-LivingObjectPaneBoxRotatorScalarDeletingDestructor-source-quality.md`
- `executed-b-agent-research/B010/0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality.md`
- `executed-b-agent-research/B003/0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality.md`
- `executed-b-agent-research/B008/0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md`
- `executed-b-agent-research/B011/0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md`
- `executed-b-agent-research/B010/0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md`
- `executed-b-agent-research/B013/0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality.md`
- `executed-b-agent-research/B015/0003UJ-LivingObjectPaneRawFunctionKeyDebounceHelper-source-quality.md`

## Generated Output Inventory

Tracker row `auto-generated/-ag-research-tracker.md` currently lists [UID:0000KU] under `Files With Empty Emitters`: 25 total emitters, 11 filled, 14 empty, 44.0% complete, generated file `auto-generated/NexusTK/map/LivingObjectPane.cpp`, by-file report coverage `0`.

Generated file freshness proof:

- `validator-command-id: 000000003224`
- `validator-refreshed-at: 2026-07-01T03:54:15-04:00`
- `validator-refresh-source: foreground-generated-refresh`
- source by-file UID `0000KU`

Non-empty generated outputs currently present:

| UID | Output disposition |
| --- | --- |
| `0002T6` | Formal covered-by marker for `LivingObjectPane::BoxRotator` scalar deleting destructor, covered by [UID:00007C]. |
| `0002R1` | First-draft `PlayAnimation`, `PlayFacingAnimation`, `PlayDeathAnimation`, and adjusted `HandleTimerMessage`. |
| `0003NU` | First-draft `LivingObjectPane::RenderFrame`. |
| `0003NV` | First-draft `LivingObjectPane::DrawSpriteFrame`. |
| `0003NW` | First-draft `LivingObjectPane::ComputeRenderBounds`. |
| `0002R3` | Formal covered-by marker for main scalar deleting destructor, covered by [UID:0002R0]. |
| `0003UH` | First-draft `LivingObjectPane::UpdateScreenPosition`. |
| `0003UO` | First-draft retained duplicate `LivingObjectPane::HandleWarpPacket`. |
| `000233` | First-draft `LivingObjectPane::HasGMNameSuffix`. |
| `0003Z3` | First-draft sprite/config helper cluster. |
| `0002RW` | First-draft `LivingObjectPane::GetViewportPosition`. |

Empty markers currently present:

| UID | Current marker | Decision |
| --- | --- | --- |
| `00007B` | `by-class/LivingObjectPane.md` | Keep blank. Broad class declaration would freeze base/subobject layout, adjusted local-player/UserPane fields, packet structs, and full virtual prototype list. |
| `00007C` | `by-class/LivingObjectPane__BoxRotator.md` | Keep blank. Nested helper source placement is resolved, but full helper declaration remains class-level work; exact child [UID:0003Z9] and marker [UID:0002T6] carry source output. |
| `000357` | `LivingObjectPaneBoxRotatorVtableData` | Keep blank. Source-declared/generated-binary vtable data, regenerated from eventual nested class declaration. |
| `0002R0` | `LivingObjectPaneConstructionAndCleanup` | Keep blank for now. Exact constructors/destructor are source-authored but field names, constructor parameter names, and final class declaration shape remain open. |
| `0001DF` | `AttachedObjectDetachRegistry` | Keep blank for now. Owner is resolved to `LivingObjectPane`, but exact method spelling, registry field names, and attachment-type enum names remain source-quality blockers. |
| `0001KN` | `UseInventorySlotDispatch` | Keep blank for now. Behavior and route are strong, but final helper spelling, constructor/local names, and target-selection construction surface need a child-specific C++ audit. |
| `0003UE` | `LivingObjectPaneWarpToPosition` | Populate first-draft C++ in the first implementation batch. Fresh MCP closes the main blocker enough for child output. |
| `0003UV` | `RawPositionSyncPacketHelper` | Keep blank. Raw no-function/no-route body; behavior is documented, but no caller/table/pointer route. |
| `0003UX` | `RawWaypointPacketHelper` | Keep blank. Raw no-function/no-route body with source-shaped packet logic but no live route. |
| `0003UY` | `RawFacingPacketHelper` | Keep blank. Raw no-function/no-route body with source-shaped packet logic but no live route. |
| `000358` | `LivingObjectPaneVtableData` | Keep blank. Source-declared/generated-binary RTTI/vtable data. |
| `0002WL` | `LivingObjectPanePoolStaticStorage` | Keep blank. Source-declared/generated-binary static pool storage, no hand-authored byte block. |
| `0001TR` | `AttachedObjectRegistryLayout` | Keep blank. Layout/type support, final field/type names unresolved; no standalone source body. |
| `00030B` | `g_lastFunctionKeyTick` | Keep blank. File-level orphan debounce global with no known writer/update site and raw no-route consumer only. |

## Source Placement And Ownership Reanalysis

Accepted source route remains:

- File root: [UID:0000KU] `by-file/LivingObjectPane.md`
- Main class: [UID:00007B] `by-class/LivingObjectPane.md`
- Nested helper: [UID:00007C] `by-class/LivingObjectPane__BoxRotator.md`, source-facing `LivingObjectPane::BoxRotator`
- Generated path: `NexusTK/map/LivingObjectPane.cpp`

Rejected alternatives:

- `UserPane`: owns surrounding UI/local-player aggregate and server dispatch, but current generated source children mutate `LivingObjectPane` state and route through [UID:00007B]. Large `+0x13...` offsets remain adjusted local-player/UserPane-view fields and should not be frozen into a compact `LivingObjectPane` declaration.
- `MapPane`: spatial service/callee for validation, reindexing, invalidation, recentering, and rendering context. It does not own living-object animation, sprite, movement-history, or attached-object registry state.
- `ObjectPane`: base class only. Object coordinates and base fields are dependencies, not the source owner of living-object methods.
- `TimerHandler` / `TimerMgr`: scheduler services. Timer callback [UID:0002R1] recovers the `LivingObjectPane` owner via the embedded `+0xa4` handler and mutates actor state.
- Standalone `LivingObjectPane__BoxRotator.cpp`: generated artifact only. Decorated vtable names and constructor subobject stores prove nested `LivingObjectPane::BoxRotator` placement under `LivingObjectPane.cpp`.
- PacketBuffer/Socket/global packet sender: packet serialization dependencies, not feature-source owners.

## First Implementation Candidate: UID0003UE

[UID:0003UE] `0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition` is the only empty marker that is currently both high-impact and safe enough for first-draft formal C++ from this by-file family audit.

Fresh MCP proof:

- `analyze_function` request `24`: `sub_5A5A90`, prototype `char __thiscall(int this, int, int, int, int)`, size `0xe9` / 233 bytes.
- It calls `MapPane::ValidateMapAndViewportCoords` at `0x00505230` through `m_mapPane` with `x`, `y`, `viewportColumn`, `viewportRow`.
- If validation fails, it returns false.
- If `m_tileX` or `m_tileY` changes, it builds old/new point pairs through `0x004b7c30`, calls `0x00505940` / `MapPane::ReindexObjectPanePosition`, then stores new `m_tileX` and `m_tileY`.
- It stores third and fourth arguments to adjusted viewport fields `+0x13ead8` and `+0x13eadc`, now resolved by [UID:0002RW] as `m_viewportColumn` and `m_viewportRow`.
- It cancels timer ids `1097094982` / `kLivingTimerForwardStep` and `20`, calls `ClearAllEffects`, clears movement-related fields at `+0x1c4`, `+0x13eb32`, `+0x13eb34`, and `+0x1c6`, then invalidates the object through `0x00506980`.
- `xrefs_to` request `26` finds twelve code xrefs, including live dispatcher/movement paths and raw position-sync call `0x005ac221`; this is not a no-route raw helper.

Recommended metadata for [UID:0003UE]: raise to `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank `EMITTER_POSITION_OPTIONAL`.

Recommended formal C++ insertion for [UID:0003UE]:

```cpp
bool LivingObjectPane::WarpToPosition(int x, int y, int viewportColumn, int viewportRow)
{
    if (!m_mapPane->ValidateMapAndViewportCoords(x, y, viewportColumn, viewportRow))
        return false;

    if (m_tileX != x || m_tileY != y)
    {
        MapPoint oldPosition;
        MapPoint newPosition;

        InitMapPoint(&oldPosition, m_tileY, m_tileX);
        InitMapPoint(&newPosition, y, x);
        m_mapPane->ReindexObjectPanePosition(
            this,
            oldPosition.y,
            oldPosition.x,
            newPosition.y,
            newPosition.x);

        m_tileX = x;
        m_tileY = y;
    }

    m_viewportColumn = viewportColumn;
    m_viewportRow = viewportRow;

    m_timerHandler.CancelTimer(kLivingTimerForwardStep);
    m_timerHandler.CancelTimer(kUserPaneMovementStep);
    ClearAllEffects();

    m_isMoving = false;
    m_movementHistoryToken = 0;
    m_movementHistoryActive = false;
    m_directionDelayActive = false;

    return m_mapPane->InvalidateObject(this);
}
```

Name caveats for implementation:

- `kUserPaneMovementStep`, `m_movementHistoryToken`, `m_movementHistoryActive`, and `m_directionDelayActive` are first-draft source-facing aliases for timer id `20` and fields `+0x13eb32`, `+0x13eb34`, and `+0x1c6`; preserve caveats in prose unless stronger names already exist in a support page at implementation time.
- If the local style prefers the already-emitted `g_pActiveMapPane->MoveObject` surface over `m_mapPane->ReindexObjectPanePosition`, the implementation may use the local accepted MapPane name, but it must preserve the exact old/new coordinate ordering proved by request `24`.
- The return type should become `bool`, not `void`: MCP returns a `char` result and the helper returns both validation failure and final invalidation result. Existing callers may ignore the return value.

## No-Code Proofs For Remaining Empty Markers

### Broad Class And Class-Lifetime Pages

[UID:00007B] and [UID:00007C] should stay blank because class-level C++ would be declarations, not method bodies. Current class declaration blockers remain real: base/subobject layout, adjusted local-player/UserPane offsets, packet-tail structs, full vtable prototypes, and final field names. Exact child method pages already carry source C++ where safe.

[UID:0002R0] should stay blank in this batch. Constructors and ordinary destructor are source-authored, but their source-quality output depends on the final class declaration, constructor parameters, sprite/config field names, attached registry field names, and nested helper declaration shape. MCP request `5` confirms constructor function boundaries; current docs already preserve that evidence. This by-file audit did not close the final declaration blocker.

### Data, Type, And Global Markers

[UID:000357] and [UID:000358] are source-declared/generated-binary RTTI/vtable data. MCP request `6` and request `11` confirm decorated names and constructor/destructor refs. Do not hand-author vtable arrays in `LivingObjectPane.cpp`; they should regenerate from declarations and virtual methods.

[UID:0002WL] is static pool storage. It should remain blank until a final static declaration spelling is known; do not emit raw storage bytes.

[UID:0001TR] is a layout/type support page for attached-object registry fields. It has strong offset evidence but unresolved final field, helper, and enum names. No standalone by-file method body belongs here.

[UID:00030B] is a file-level orphan debounce global. Current docs prove two raw read operands and no writer/update site. Do not invent a source assignment or initializer beyond the current generated-binary storage handling.

### Source-Authored But Still Name/Layout Blocked

[UID:0001DF] owner/emitter is correctly [UID:00007B]. MCP request `25` reconfirms the sole destructor caller, registry switch, type byte, and registry fields; request `27` reconfirms exactly one code xref. The remaining blockers are exact method spelling, registry list/singleton field names, and attachment-type enum names. Keep blank until a child-specific source-name pass closes those.

[UID:0001KN] is a real source helper, not raw. MCP request `9` reconfirms `sub_5A3E30` as a 451-byte dispatch with slot range `1..52`, slot table, direct packet send, and ItemWho fallback. It is a plausible later C++ target, but this by-file audit should not populate it without a dedicated child C++ pass over the target-selection constructor/local names and exact helper spelling.

### Raw No-Route Helpers

[UID:0003UV], [UID:0003UX], and [UID:0003UY] should stay blank. They are source-shaped retained raw packet bodies, but route/liveness is negative:

- Request `11` reports no xrefs to raw starts `0x005ac1b0`, `0x005ac7e0`, and `0x005ac9a0`.
- Request `12` reconfirms [UID:0003UV] has a real packet body but no IDA function object and no entry route.
- Existing executed reports for [UID:0003UX] and [UID:0003UY] document no rel32 caller, no VA/RVA pointer, no vtable route, and no fallthrough route.

Behavior documentation and reference drafts are appropriate on those child pages. Formal C++ would invent a source call surface unless the project adopts an explicit retained-dead-helper emission policy.

## Score And Metadata Rationale

[UID:0000KU] after implementation should be `89/88`.

- Completion `89`: current file doc already has strong incorporated child history. The missing piece is a current generated-output audit that accounts for all empty markers and identifies the first safe removal candidate. One child C++ marker removal, [UID:0003UE], can improve generated completeness without broad unsafe C++.
- Confidence `88`: fresh MCP independently rechecked the representative emitted children, vtable names, raw no-route starts, route-positive helpers, and the best first-batch candidate. Confidence should rise above the stale file-root `85` but stay below final-audit levels because broad class/lifetime/type/raw-helper blockers remain.

Do not change [UID:00007B] or [UID:00007C] scores from this report alone. Their current score caps are class-declaration blockers, not file-generated inventory blockers.

## Claim And Incorporation Ledger

| Claim | Destination | Action if accepted | Verification state |
| --- | --- | --- | --- |
| Generated `LivingObjectPane.cpp` is current to validator command `000000003224`, refreshed `2026-07-01T03:54:15-04:00`. | `by-file/LivingObjectPane.md` | Add generated-output audit section. | applied: `by-file/LivingObjectPane.md` now records the `000000003224` / `2026-07-01T03:54:15-04:00` generated header proof; post-validation generated file refreshed to command `000000003233` at `2026-07-01T04:16:48-04:00`. |
| Tracker row has 25 total emitters, 11 filled, 14 empty, by-file report coverage `0`. | `by-file/LivingObjectPane.md` | Add queue/generator context. | applied: generated-output audit records 25 total emitters, 11 filled, 14 empty, 44.0%, and no by-file report coverage at report time. |
| Broad file/class C++ should stay blank; exact child pages carry output. | `by-file/LivingObjectPane.md`, optionally `by-class/LivingObjectPane.md` only if supervisor wants support sync | Preserve no broad C++ policy. | applied: `by-file/LivingObjectPane.md` audit states broad by-file/class C++ remains blank and exact child pages carry output; no class docs were edited per callback scope. |
| [UID:0003UE] is the best first empty-marker removal candidate. | `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md` | Raise to `88/90`, populate formal C++, document request `24`/`26` evidence and name caveats. | applied: target page metadata is `88/90`, formal C++ block contains `bool LivingObjectPane::WarpToPosition(...)`, and prose records requests `24`/`26`, exact size, direct xrefs, validation/reindex calls, viewport stores, timer cancels, `ClearAllEffects`, movement clears, final invalidation, and caveats. |
| [UID:0001DF] remains blank despite resolved owner. | `by-file/LivingObjectPane.md`, existing target page already mostly contains detail | Add/confirm one-line empty-marker triage only; no child edit needed unless supervisor wants caveat refreshed. | applied: by-file audit triages [UID:0001DF] as blank due method spelling, registry field names, and attachment-type enum blockers; no child edit was made per callback scope. |
| [UID:0001KN] remains blank pending dedicated child C++ audit. | `by-file/LivingObjectPane.md` | Add/confirm empty-marker triage. | applied: by-file audit triages [UID:0001KN] as blank pending dedicated helper spelling, constructor/local naming, and target-selection construction audit. |
| [UID:0003UV]/[UID:0003UX]/[UID:0003UY] remain blank because route proof is negative. | `by-file/LivingObjectPane.md` | Add/confirm raw no-route triage. | applied: by-file audit preserves raw no-route/no-function/no-pointer/no-fallthrough dispositions for [UID:0003UV], [UID:0003UX], and [UID:0003UY]. |
| Data/type/global markers [UID:000357], [UID:000358], [UID:0002WL], [UID:0001TR], [UID:00030B] remain blank with source-declared/generated-binary or no-writer/no-route proof. | `by-file/LivingObjectPane.md` | Add/confirm generated empty-marker triage. | applied: by-file audit records source-declared/generated-binary or no-writer/no-route no-code dispositions for [UID:000357], [UID:000358], [UID:0002WL], [UID:0001TR], and [UID:00030B]. |
| [UID:0000KU] score should become `89/88`. | `by-file/LivingObjectPane.md` | Update metadata. | applied: `by-file/LivingObjectPane.md` metadata is `COMPLETION:89`, `CONFIDENCE:88`; validator command `000000003232` reported both updates and `ok: 1`. |

## Implementation Tracking Checklist

Implementation callback status, 2026-07-01:

- [x] `by-file/LivingObjectPane.md`: update metadata to `COMPLETION:89`, `CONFIDENCE:88`; keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"` and `CANONICAL_OWNER:FILE`.
  - Proof: metadata updated in `by-file/LivingObjectPane.md`; validator command `000000003232` reported `completion_update 0000KU ... 89`, `confidence_update 0000KU ... 88`, exit code `0`, `ok: 1`.
- [x] `by-file/LivingObjectPane.md`: add a 2026-07-01 B007 generated-output audit section with generated header proof `000000003224` / `2026-07-01T03:54:15-04:00`, tracker row counts, populated-output list, and 14-empty-marker triage.
  - Proof: section `## 2026-07-01 B007 Generated-Output Audit` added with generated header proof, 25/11/14/44.0% tracker context, all 11 populated outputs, and all 14 empty marker dispositions. The unchanged empty markers are incorporated there as no-code/blank dispositions, not forgotten future work.
- [x] `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md`: update metadata to `COMPLETION:88`, `CONFIDENCE:90`; keep owner/emitter [UID:00007B].
  - Proof: metadata updated; validator command `000000003233` reported `completion_update 0003UE ... 88`, `confidence_update 0003UE ... 90`, exit code `0`, `ok: 1`. Owner/emitter lines remain `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank `EMITTER_POSITION_OPTIONAL`.
- [x] `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md`: populate the formal `RECONSTRUCTION_CPP CODE` block with the `bool LivingObjectPane::WarpToPosition(int x, int y, int viewportColumn, int viewportRow)` first-draft code from this report, preserving name caveats in prose.
  - Proof: formal block now contains the first-draft C++ body. Prose records timer id `20` alias `kUserPaneMovementStep`, movement-history field aliases, viewport column/row order from [UID:0002RW], MapPane reindex helper naming caveat, exact old/new coordinate ordering, and bool return rationale.
- [x] Do not edit `by-class/LivingObjectPane.md`, `by-class/LivingObjectPane__BoxRotator.md`, vtable/static/type/global marker pages, or raw helper pages unless the supervisor callback explicitly asks for support sync beyond the by-file audit and [UID:0003UE].
  - Proof: implementation scope changed only `by-file/LivingObjectPane.md`, `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md`, and this report checklist. No other by-* docs were edited by this callback.
- [x] Run scoped validators with generated wait after accepted implementation, at minimum:
  - `python .\tools\validator.py --mode file --file by-file\LivingObjectPane.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-memory\0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md --apply --queue-timeout 240 --wait-generated`
  - Proof: first command exit code `0`, `command_id: 000000003232`, `command_timestamp: 2026-07-01T04:16:31-04:00`, `ok: 1`, `generated_refresh: completed`; second command exit code `0`, `command_id: 000000003233`, `command_timestamp: 2026-07-01T04:16:48-04:00`, `ok: 1`, `generated_refresh: completed`.
- [x] Verify `auto-generated/NexusTK/map/LivingObjectPane.cpp` refreshed at or after the validator command metadata and no longer has an empty marker for [UID:0003UE].
  - Proof: generated header is `validator-command-id: 000000003233`, `validator-refreshed-at: 2026-07-01T04:16:48-04:00`, equal to the second validator command metadata. The generated file now contains `// UID:0003UE ... Completion:88 | Confidence:90` followed by `bool LivingObjectPane::WarpToPosition(...)`; UID0003UE no longer appears in the empty-marker list.
- [x] Record validator `command_id`, `command_timestamp`, exit code, `ok` count, generated freshness header, and any unrelated diagnostics in the implementation callback report checklist.
  - Proof: command metadata and generated header are recorded above. Diagnostics were nonblocking/pre-existing: by-file validation reported missing historical UID refs such as `0003Z4`-`0003ZA`/`0003UA`/`0003VE` plus broad autogen children/no-code warnings; by-memory validation reported one missing historical UID ref `0003Z5` plus broad autogen warnings. Validator-owned generated files/reports and `validator.ini` refreshed as side effects of the scoped commands.
- [x] Supervisor-owned after validation: execute/archive this report with the normal `execute_report` lifecycle only after Rule 26 verification succeeds.
  - Proof: not performed by B007; left for supervisor as required. No archive/move was attempted.

## Blockers

No MCP blocker. IDA MCP was available and used.

Implementation callback completed for the accepted scoped first batch. Validators were run as recorded above, and no accepted scoped item remains unapplied.

Remaining source-quality blockers after this report:

- Full `LivingObjectPane` class declaration and broad constructor/destructor C++ still require final base/subobject layout, local-player adjusted field treatment, full virtual prototypes, and final field names.
- [UID:0001DF] needs exact method/field/type names before C++.
- [UID:0001KN] needs a dedicated child C++ pass over helper spelling, ItemWho construction surface, and locals.
- Raw helpers [UID:0003UV], [UID:0003UX], and [UID:0003UY] need a live route/table/pointer proof or explicit retained-dead-helper emission policy before formal C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000KU-LivingObjectPane-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000KU-LivingObjectPane-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T04:25:34","uid":"0000KU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
