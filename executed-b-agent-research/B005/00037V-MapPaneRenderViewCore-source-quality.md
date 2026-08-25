** TARGET-REPORT-UID:00037V **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00037V MapPaneRenderViewCore Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation, applied and verified: UID00037V's mixed convenience range is now a non-emitting split index with three exact address-ordered children: live `MapPane::GetCurrentMapId() const`, a non-source shared compiler tail used by MusicControlDialog and SoundManager contexts, and live `MapPane::RenderMapView()`.
- Applied parent disposition: `92/94`, owner `NONE`, reconstructable `FALSE`, blank emitter/position/formal body, and `Nested:-4`. Mixed MapPane source, compiler alignment, and cross-owner tail sharing make a single owner or body invalid.
- Registered children: UID0004QW `[0x00509470,0x00509478)` getter at `92/94`; UID0004QX `[0x00509480,0x005094ae)` shared tail at `92/94`, non-reconstructable and non-emitting; UID0004QY `[0x005094b0,0x0050a4fd)` render method at `92/93` with complete human source. Internal `0xcc` spans are ignored.
- Applied source route: UID00007Q MapPane / UID0000L3 `NexusTK/map/MapPane.cpp` for the getter and render body. The shared tail has no independent source route because the source statements remain in the two full caller-context methods that the compiler folded to one suffix.
- Confidence: very strong for boundaries, hashes, function/tail/padding classification, receiver, caller/callee contracts, render order, field offsets, source ownership, nesting, and compiler exclusions; strong rather than final for stripped private field/helper spellings and effect-byte lexical names.
- Lifecycle/status: the separately authorized implementation callback and supervisor-owned manual coverage application are complete. This same standalone research artifact is reconciled after the bounded manual-application state rebase; fresh exact-artifact Gate 1, independent Gate 2, report execution, movement, and archival remain pending external supervisor-owned lifecycle work.
- First Gate 2 rebase history: rejected SHA `721476F2DBBB1B1BB3ACB3D332125B222F658B285AE3B59E8F417E5B60115204` was repaired in place. That reread proved the accepted B005 facts remained present after B001's MapPane/UserPane rebases, so that repair required no ordinary edit; it refreshed the manual matrix, support hashes, and generated readback.
- Current bounded C11 repair: subsequent SHA `F1A4B3A8FE07236CC70B9588FC0B8B68437A7A803B693111FA4DE6D8E72D6790` failed Gate 2 because `by-file/MapPane.md` lacked the full accepted `+0x3f0` lifecycle. The file now carries the exact inferred name, constructor/transition set routes, local-status clear route, render/weather not-ready consumers, early-out/suppressed-bounds behavior, and stripped-symbol confidence cap; scoped validator `000000012622` passed and the lease was released.
- Historical first Gate 1 hash rebase: report SHA `123AE27EE3FDE9EBB63C15D44A80DFB673EAD8AC7B3CD029A85FD8AC1F3B2380` became stale when B004 added unrelated UID000373 compiler-support evidence to `by-memory/-ignored.md`; that revision rebased the page without ordinary edits.
- Historical second bounded Gate 1 state rebase: subsequent report SHA `DB637985529D63B9F08E0D26025829FBEEF64F73FA3449B675508542ADFC80E5` became stale when B003 added unrelated UID0004R1 `[0x004f66b0,0x004f66b5)` WinMain/BaramApp EH cleanup-thunk evidence to the same ignored page. Read-only reread confirmed both UID00037V MapPane alignment entries remained complete and unchanged; that revision rebased the ignored/generated state without ordinary edits or validator reruns.
- Current bounded generated-state Gate 1 rebase: exact report SHA `F76F56D768B508CAD04B81F638422A76A548F067D8C3AF6C13F8BB251D276A8E` became stale only because a later supervisor validator refreshed generated output as external command `000000012692` at `2026-07-15T01:41:46-04:00`. That supervisor-supplied snapshot, earlier external command `000000012664`, and transient per-file commands `000000012695`/`000000012696` remain historical evidence. A later full external foreground refresh settled MapPane, UserPane, MusicControlDialog, and SoundManager on command `000000012699` at `2026-07-15T01:54:32-04:00`; every accepted target and blindness assertion remains unchanged. The same concurrent work appended unrelated B004 UID0002Q3 NewUserDialogPane alignment/compiler-support/vtable evidence to `by-memory/-ignored.md`; read-only reread confirms both UID00037V MapPane alignment entries and successor padding remain exact. This rebase changes only this report and runs no validator, lease, ordinary edit, generated edit, or lifecycle operation.
- Historical bounded Rule 26 manual-handoff repair: exact report SHA `18DC9E6B61DBA776A917A45494C7EBE1610A7EE5136307F9B6ED8DB4F048ED76` failed Gate 1 because three proposed manual replacements predated richer supervisor-applied B001 rows. The repaired revision reread and classified all 18 proposed manual rows, preserved all six absent insertion rows, and supplied full no-loss unions for UID0000FQ, UID0000L3, and UID0000P1 without changing research, ordinary/formal/generated proof, or any project file other than this report.
- Historical bounded manual-application state rebase: exact report SHA `1920BE9767B0D0D31E5803BF3CAFA2F43736DEC88EF36DFD6D6B9B90948963D6` passed supervisor Gate 1 at `2026-07-15T02:10:14-04:00`. The supervisor then applied all six insertions and 12 no-loss replacements and validated the four manual coverage files through commands `000000012700`-`000000012703`; the prior matrix, exact handoff rows, commands, and then-current hashes remain below as historical application-time evidence.
- Current bounded concurrent manual-coverage hash rebase: exact report SHA `189F367529BA3E49D482B4282499AF737804DC99CC33F68323D1B67160A0F8A7` failed Gate 1 at `2026-07-15T02:37:00-04:00` solely because later unrelated supervisor-owned B003 UID00019H and B004 UID0003U7 coverage additions advanced the whole-file hashes for `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md`. Read-only current comparison confirms all 18 B005 rows remain present exactly at accepted same-or-greater detail; the by-struct hash is unchanged. This rebase changes only the report's current hashes and proof attribution.

## Supporting Research

### Mandatory current MCP evidence

- A fresh streamable-MCP initialization on 2026-07-14 discovered transport session `60c7d719-2d81-490b-93c8-a8b5004dad37` and one active/adopted IDB database, `0cf42e97`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `8808`, `is_analyzing:false`.
- Evidence-time `server_health` returned `status:ok`, image base `0x00400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and string-cache size `2067`.
- A final bounded `lookup_funcs` recheck returned `sub_509470` size `0x8`, mapped `0x00509480` into `sub_52A120` size `0x5f`, returned `sub_5094B0` size `0x104d`, and returned successor `sub_50A500` size `0x337`.
- The complete evidence pass also used bounded bytes, hashes, function analysis, decompilation, instruction/basic-block profiles, callers/callees, xrefs, signatures, adjacent lookups, and localized field-reference searches. No broad whole-image expensive query was required.
- IDA remained read-only. No rename, type, comment, function, database, process, or cache mutation was requested.

### Prior-report search provenance

- Exact terms searched were `00037V`, `UID:00037V`, `0x00509470`, `0x00509478`, `0x00509480`, `0x005094ae`, `0x005094b0`, `0x0050a4fd`, `MapPaneRenderViewCore`, `MapPane::RenderMapView`, `MapPane::GetCurrentMapId`, `sub_509470`, `sub_5094B0`, `sub_52A120`, `MapPane`, `MusicControlDialog`, `SoundManager`, `ApplyPlaybackState`, `MapPaneRenderScratchFlag`, and `NexusTK/map/MapPane.cpp`.
- Roots actually searched were central `executed-b-agent-research`, all active `tools/leaser/Agents/Agent-B001/research` through `Agent-B015/research`, `tools/leaser/Agents/Older-Research`, and legacy executed/archived roots under `archived/b-agent-reports-20260623`.
- Every relevant report match was opened and classified:
  - `executed-b-agent-research/B001/B001-MEMTOOL-00506970-MapPaneInputPacketRenderCore.md`: incidental broad-parent inventory; confirms the getter/render starts but does not resolve UID00037V.
  - `executed-b-agent-research/B002/0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md`: incidental attachment-light caller evidence.
  - `executed-b-agent-research/B003/0001DM-LightingObjectPaneScalarDeletingDestructor-source-quality.md`: incidental validator diagnostic only.
  - `executed-b-agent-research/B003/0003ME-0003MR-MusicControlDialogHelperFamily-source-quality.md`: useful shared-music-tail lead; its older standalone/fallback-helper language is superseded by the direct two-context compiler-tail proof here.
  - `executed-b-agent-research/B004/0000L3-MapPane-empty-emitter-family-source-quality.md`: useful MapPane source and render-scratch-global evidence, not direct target coverage.
  - `executed-b-agent-research/B004/0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md`: incidental attachment caller evidence.
  - `executed-b-agent-research/B005/00037X-MapPaneInteractionMapChangeCore-source-quality.md`: useful current MapPane field, nesting, class/file, and render-consumer support, not a direct UID00037V report.
  - `executed-b-agent-research/B006/0002TZ-AttachmentAnchorApplyLight-source-quality.md`: useful final light-application contract.
  - `executed-b-agent-research/B006/00041X-MapPaneMapToScreenCoords-source-quality.md`: incidental coordinate-helper and former missing-reference context.
  - `executed-b-agent-research/B008/0002TD-SoftwareRenderCompatAlphaLookupBlitCallback-source-quality.md`: useful alpha-lookup callback contract.
  - `executed-b-agent-research/B008/0003UH-LivingObjectPaneUpdateScreenPosition-source-quality.md`: useful sole-caller and cached-screen-position contract.
  - `executed-b-agent-research/B011/0001CP-MusicControlDialog-source-quality.md`: useful current `ApplyPlaybackState` source and shared-tail evidence.
  - `executed-b-agent-research/B011/0001KF-UrlAlertPane-source-quality.md`: incidental predecessor-family mention only.
  - `executed-b-agent-research/B012/0001D2-MapPaneSpatialIndex-source-quality.md`: useful ObjectList accessor taxonomy.
  - `executed-b-agent-research/B012/0001E9-PaletteLibPaletteFilterHelpers-source-quality.md`: useful palette filter behavior.
  - `executed-b-agent-research/B013/00037U-MapPaneNotifyTimerCore-source-quality.md`: useful predecessor boundary and getter-start evidence.
  - `executed-b-agent-research/B014/0001E9-PaletteLibPaletteFilterHelpers-source-quality.md`: useful current palette helper contract.
- No active B-agent report, Older-Research report, or legacy archived report directly resolves UID00037V. Evidence-based conclusion: no prior direct source-quality report exists for this target; every match is incidental support or broad-parent inventory.

### Historical report-only documentation and generated baseline

- At evidence-collection time UID00037V was `85/88`, owner/emitter UID00007Q MapPane, reconstructable `TRUE`, blank optional position, blank Item Summary, blank formal body, and `Nested:8`. That historical prose treated a mixed range as one render convenience aggregate and left raw-range/source-body blockers open; the callback superseded it.
- The historical target prose overstated the main body as having 124 callees. Fresh MCP resolved 39 direct callee targets and 191 basic blocks, including compiler cleanup/EH funclets; the current target/child pages carry the corrected facts.
- Historical report-only baseline: generated `auto-generated/NexusTK/map/MapPane.cpp` carried the expected UID00037V empty-emitter consequence rather than source. The completed callback superseded that baseline through validator-owned generation; generated output was never edited manually.
- Predecessor UID00037U ends exactly at `0x00509470`. Successor UID00037W begins at `0x0050a500`. Ignored documentation now covers both internal spans and the preexisting `[0x0050a4fd,0x0050a500)` postpad.
- Historical cumulative nesting was wrong for this split: UID00037U closed its own children, UID00037V then added `+8`, UID00037W stayed at that depth, and UID0001AV later subtracted four. The completed exact address-order repair is documented below.

## Target

- Target UID: `00037V`.
- Target path: `by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md`.
- Required report path: `tools/leaser/Agents/Agent-B005/research/00037V-MapPaneRenderViewCore-source-quality.md`.
- Queue source: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, assignment-time row `85/88`, reports `0`.
- Exact half-open target: `[0x00509470,0x0050a4fd)`, 4237 bytes / `0x108d`.

## Current Target State

- Historical report-only baseline metadata was `85/88`, owner/emitter UID00007Q, reconstructable true, blank position/formal/summary, and `Nested:8`.
- Current useful facts: MapPane class/file route, getter at the first eight bytes, main modeled render body at `0x005094b0`, successor paint at `0x0050a500`, ObjectList and GrafPort rendering dependencies, and an established `m_mapId` field at `+0x3f2`.
- Resolved blockers: every raw interval is classified, exact children exist, the main method has a complete source body, readiness/blindness/render-state fields are separated, effect/static ordering is complete, the music suffix is documented as compiler-shared rather than MapPane-owned, and cumulative nesting validates. The historical exact manual handoff remains below, and all accepted rows are now present through the supervisor-owned application.
- Current applied state: non-emitting split parent plus one getter, one shared-tail no-source child, and one complete render child. No source-shaped interval remains deferred or blank without exact compiler/no-source proof.
- Current file-level support state: UID0000L3 now records `MapPane+0x3f0` as inferred `m_waitingForLocalPlayerStatus`, set by constructor and map/effect transitions, cleared by `CreateOrUpdateObjectPane` after local-player status, and consumed by render/weather refresh as a not-ready early-out/visible-bounds-suppression gate.

## Executive Recommendation

Convert UID00037V into a mixed, non-emitting split index. Register the exact getter, shared compiler tail, and render method serially in address order. Emit only the getter and render method through UID00007Q MapPane / UID0000L3 MapPane.cpp. Keep the shared tail documented but non-emitting because it is a compiler-folded suffix of two full source contexts, not a third source helper.

The render source must preserve all observed gates and ordering: flash-fill early return; automatic Region lifetime; local-player blindness state; map-transition readiness suppression; shadow-option cache transition; tile-cache refresh; day/night shadow overlay and attachment lights; cached-surface transfer; living prepass; item/flying/effect/static/living order; secondary-effect split; alpha lookup or palette-filter cleanup; object-info/balloon/hit-bar/damage overlays; and the final apparently unused clip query.

## Supervisor Active Recheck

- The target is the current lowest assignment-time unassigned reconstructable tracker row selected by the supervisor.
- Fresh session `0cf42e97` replaced all stale-session assumptions. All target-dependent conclusions below are tied to successful bounded calls from that current evidence pass.
- Historical Gate 1 state: the report-only artifact proposed C01-C35 and six managed blocks, intentionally performed no ordinary edit/lease/validator/generated refresh, and used placeholders rather than guessed child UIDs.
- Completed callback state: validators serially issued UID0004QW, UID0004QX, and UID0004QY; each placeholder was replaced before the next registration/reference, all six accepted blocks were applied exactly, 20 ordinary pages were scoped-validated under short leases, and final waited command `000000012518` refreshed generated output. No report execution/lifecycle/move/archive action or manual restricted-file edit occurred.
- Historical Gate 2 rebase: `by-file/MapPane.md`, `by-class/UserPane.md`, and `by-file/UserPane.md` were reread after their relevant leases were clear. Their newer B001 unions preserved every accepted UID00037V source-order and blindness fact; report hashes were rebased without ordinary edits. The resulting manual handoff preserved every newer score/detail, including EffectObjectPane `85%`, Effects file `90%`, and UID0002AZ `87%`; those unions are now applied.

## Inference Research Guidance Check

- Binary facts and source-facing inferences are separated. Addresses, bytes, hashes, block/callee counts, xrefs, field offsets, branch order, constants, and call order are direct evidence. Private names such as `m_waitingForLocalPlayerStatus` and `m_renderAfterLivingObjects` are descriptive inferences.
- Physical adjacency is not ownership. The `[0x00509480,0x005094ae)` interval is assigned no independent source only after proving two incoming contexts and matching complete source-bearing methods, not because it lacks a modeled start.
- Missing original symbols cap lexical confidence but do not block human source when receiver, ABI, fields, branch behavior, caller route, and sibling APIs are resolved.
- Compiler artifacts remain excluded: EH states, security-cookie checks, stack Region cleanup, tail folding, alignment, vtable dispatch lowering, and callback pointer mechanics are represented through ordinary source constructs.
- No third-party source import applies; this is NexusTK-owned MapPane/MusicControl/SoundManager behavior.

## Heuristic / Inference Reanalysis And Validation

### `0x00509470-0x00509478`: retained getter source

- Eight bytes decode as `movzx eax, word ptr [ecx+0x3f2]; ret`. One basic block, no callees, and six live code xrefs disprove data/padding/compiler-only alternatives.
- Established MapPane class/file/layout docs identify `+0x3f2` as `m_mapId`. Getter consumers include MiniMapDialog setup/render and UserPane paths.
- Best source name is `MapPane::GetCurrentMapId() const`; historical `GetMapId` is a viable alias but current source-family vocabulary uses “current” for active-map state. Missing symbols cap spelling only.

### `0x00509480-0x005094ae`: shared compiler tail, not source helper

- The interval has nontrivial executable bytes and must not be labeled padding. IDA maps it as a tail chunk of `sub_52A120` / MusicControlDialog `ApplyPlaybackState`.
- Exactly two incoming branches reach the suffix: the modeled MusicControlDialog path at `0x0052a17a` and an unmodeled SoundManager audio-reinitialization path at `0x0057b00c`.
- The suffix checks the config music-source byte; when zero it calls `g_pSoundManager->PlayMusicByZone` with the active MapPane's three music/zone fields and zero. Both source contexts already contain this policy as their common final suffix.
- Independent helper alternatives are rejected: no call instruction targets the start, no address materialization/table/vtable route exists, both predecessors branch into the same suffix, and the sequence ends in the shared return. It is compiler tail merging of duplicated source statements.
- Canonical source placement stays in the complete MusicControlDialog and SoundManager methods. A third handwritten helper would invent a source abstraction and duplicate behavior.

### `0x005094b0-0x0050a4fd`: retained MapPane render source

- IDA models one `0x104d`-byte `__thiscall` method with 191 basic blocks, 39 direct callee targets, no strings, no switch/jump table, and one source caller function: successor `MapPane::OnPaint` / paint entry `0x0050a500`, which invokes it at three sites depending on dirty-region handling.
- The method has a security/EH prologue, one automatic Region, and compiler cleanup paths. Those are normal lowering, not separate source children.
- The body directly uses MapPane fields, inherited GrafPort drawing state, ObjectList storage, local UserPane/LivingObjectPane state, palette/shadow globals, render callbacks, and pane overlay lists. No competing owner matches the complete receiver and call surface.

### State and field resolutions

- `MapPane+0x3f0` is best `m_waitingForLocalPlayerStatus`, not current `m_hasRenderableMap`. Constructor initialization sets it, map/effect transition paths set it, `CreateOrUpdateObjectPane` clears it after local-player status arrives, and render/weather paths early-out while it is set.
- `UserPane::m_playerSettingsState[4]` is a blindness level/gate. The player-settings parser invalidates map bounds when it changes; render switches to a solid fill plus local-player-only rendering when nonzero. Historical `oldSpeed` is disproved.
- `MapPane+0x3e0`, retained as `m_selectionOverlay`, is an `AlphaMaskSurface` used here as the day/night shadow/light overlay. The accepted spelling remains for bounded compatibility, and current support prose records its actual render role.
- `MapPane+0x3dc` is the day/night target brightness. `+0x4c8` is `m_mapFlashColor`; `+0x418` is the local/active UserPane; `+0x424` is ObjectList; `+0x428` is embedded viewport GrafPort.
- `EffectObjectPane+0x14d` selects the late secondary-effect pass. Best source-facing role is `m_renderAfterLivingObjects`; the original spelling is stripped, so this remains a lexical confidence cap.
- `StaticObjectPane+0x128` is the static-object resource id. The first static pass selects two special IDs per asset mode and the later pass renders the remaining static entries.

## Evidence Standards Used

- Current-session MCP function, byte, hash, xref, caller/callee, decompile, block, signature, and bounded listing evidence.
- Current ordinary by-class/by-file/by-memory/by-type docs reread as hypotheses and cross-checked against current binary facts.
- Evidence-time generated source read-only inspection for existing declaration/method vocabulary and the historical empty-emitter baseline, followed by post-callback waited generated readback.
- Historical pre-application tracker/manual-coverage inspection plus current post-application read-only verification of all 18 rows and commands `000000012700`-`000000012703`.
- Prior-report search across central executed, active, Older-Research, and legacy archived roots with every relevant match classified.
- Source reconstruction preserves exact runtime ordering and malformed/unusual behavior; no modernization or speculative safety guard is inserted.

## Evidence Checked

- Exact target, child, padding, postpadding, and successor bytes plus SHA-256 hashes.
- Function lookup at all starts/boundaries; bounded analysis/decompile for getter, shared-tail owner, main render, successor paint, and key support helpers.
- Getter callers; shared-tail branch xrefs; main caller sites; render scratch/global refs; support field producers/consumers.
- Complete 39-callee inventory and 191-block profile for the main body.
- MapPane, ObjectList, ObjectPane, LivingObjectPane, EffectObjectPane, StaticObjectPane, GrafPort, PaletteLib, RegistryConfig, callback-global, and UserPane docs.
- UID0003UL and UID0003TL complete managed blocks were reread before applying their accepted one-token semantic corrections.
- Historical pre-application manual coverage rows for all existing affected class/file/global/memory/type pages, including the then-confirmed absence of direct UID00037V/new-child rows; current readback confirms those rows are now present through supervisor application.
- Historical report-only evidence collection ran no validator, as required then. The later authorized callback validator evidence is recorded under `Validator Results` and reconciled claim by claim below.

## Claim And Incorporation Ledger

| ID | Claim | Evidence | Action | Destination | Verification state |
| --- | --- | --- | --- | --- | --- |
| C01 | Parent is a mixed split index, not one method. | Three distinct source/compile dispositions inside exact target. | incorporate | UID00037V metadata/formal/summary | applied |
| C02 | Parent score becomes `92/94`, owner NONE, false, blank emitter/position/formal, `Nested:-4`. | Exhaustive split, ownership, and nesting proof. | incorporate | UID00037V | applied |
| C03 | Getter child is exact live MapPane source. | Eight bytes, six xrefs, `+0x3f2` field. | incorporate | `UID0004QW` | applied |
| C04 | Shared-tail child is compiler-folded, cross-owner, and non-emitting. | Two predecessor contexts, no independent call route, shared return. | incorporate | `UID0004QX` | applied |
| C05 | Main child is `MapPane::RenderMapView()`. | Paint caller, receiver fields, 39 callees, 191 blocks. | incorporate | `UID0004QY` | applied |
| C06 | Preserve exact bytes and half-open boundaries. | MCP raw-byte pass. | incorporate | parent and three children | applied |
| C07 | Preserve exact range hashes. | MCP byte hashes listed below. | incorporate | parent and children | applied |
| C08 | Preserve CFG/EH/security-cookie facts as compiler lowering. | Function profile and cleanup paths. | incorporate | render child | applied |
| C09 | Preserve caller/xref/ABI contracts. | Getter six refs, tail two refs, paint three calls. | incorporate | children/support prose | applied |
| C10 | Resolve MapPane render fields and retained lexical caps. | Direct offsets plus producers/consumers. | incorporate | parent/render/class/file/layout | applied |
| C11 | Correct `+0x3f0` to waiting-for-local-status semantics. | constructor/set/clear/render/weather lifecycle. | incorporate | MapPane supports, UID0003TL/3TK | applied |
| C12 | Correct player-settings byte `[4]` to blindness. | parser invalidation and render branch. | incorporate | UID0003UL/UserPane supports | applied |
| C13 | Preserve flash and readiness early exits. | top-level branch order. | incorporate | render child | applied |
| C14 | Preserve shadow cache, palette, overlay, and lighting order. | config/global refs and exact callees. | incorporate | render child/supports | applied |
| C15 | Preserve cached surface transfer and visible-bounds setup. | GetClipRect/Blit/Begin/End and bounds callees. | incorporate | render child/supports | applied |
| C16 | Preserve living prepass and item/flying/row render order. | ObjectList accessor sequence. | incorporate | render child/ObjectList verify | applied |
| C17 | Preserve special static-id two-pass behavior. | direct constants and asset-mode branch. | incorporate | render child/StaticObjectPane prose | applied |
| C18 | Preserve secondary effects split by `+0x14d`. | two row-pass predicates. | incorporate | render child/EffectObjectPane supports | applied |
| C19 | Preserve blind mode local-player/effect-only path. | fill color 128 and local lists. | incorporate | render child/UserPane supports | applied |
| C20 | Preserve object-info, balloon, hit-bar, and conditional damage tail. | global-list accessor order and config byte. | incorporate | render child | applied |
| C21 | Preserve final unused clip query and Region cleanup. | terminal call and EH cleanup. | incorporate | render child | applied |
| C22 | Internal `cc` spans are ignored, not children. | exact bytes at two spans. | incorporate | by-memory/-ignored.md | applied |
| C23 | Successor postpad is already correct. | current ignored page and bytes. | already-present | `[0x0050a4fd,0x0050a500)` | already-present |
| C24 | Apply exact cumulative nesting plan. | address-order generated indentation and delta math. | incorporate | parent, children, UID37W, UID1AV | applied |
| C25 | MapPane class support gets render/getter/state inventory, score unchanged. | established owner/layout and direct evidence. | incorporate | UID00007Q | applied |
| C26 | MapPane file support gets exact source order/split/compiler exclusions, score unchanged. | source route and child order. | incorporate | UID0000L3 | applied |
| C27 | MapPaneLayout support gets corrected field roles, score/formal unchanged. | producer/consumer lifecycle. | incorporate | UID00042K | applied |
| C28 | Correct UserPane parser local name only; preserve full body. | `[4]` blindness proof. | incorporate | UID0003UL and UserPane class/file prose | applied |
| C29 | Correct map-info body field token only; synchronize effect-state producer prose. | `+0x3f0` lifecycle. | incorporate | UID0003TL/UID0003TK | applied |
| C30 | Resolve EffectObjectPane `+0x14d` render role without score/formal change. | target's two exact predicates. | incorporate | EffectObjectPane class/file | applied |
| C31 | Add GrafPort exposed-region getter contract without score/formal change. | live 0x004b8dd0 body and 30 refs. | incorporate | GrafPort class/file | applied |
| C32 | Preserve global/callback/dependency ownership and score. | scratch, palette, alpha, ObjectList, attachment docs. | already-present | named support dependencies | already-present |
| C33 | Preserve negative evidence and supersede stale assumptions explicitly. | no strings/table, shared-tail proof, old field names. | historicalize | target/support history | applied |
| C34 | Supply exact supervisor-owned manual coverage text; never edit coverage. | read-only coverage matrix. | incorporate | report coverage section | applied |
| C35 | Register children serially, validate every changed page, refresh generated output, and prove no parent/tail emission. | completed callback workflow and generated readback. | incorporate | checklist/validator proof | applied |

Callback verification proof, claim by claim:

| Claim | Applied/already-present proof |
| --- | --- |
| C01 | UID00037V now has a blank managed block and links the three exact source/compiler dispositions; scoped validator `000000012499` passed. |
| C02 | UID00037V headers read `92/94`, `NONE`, false, blank emitter/position, and `Nested:-4`; command `000000012499` passed and waited recheck `000000012518` remained clean. |
| C03 | Serial registration issued UID0004QW for `[0x00509470,0x00509478)`; Destination 2 matches the installed formal byte-for-byte and command `000000012479` passed. |
| C04 | Serial registration issued UID0004QX for `[0x00509480,0x005094ae)`; the blank Destination 3 and complete two-context no-source proof passed commands `000000012483` and `000000012485`. |
| C05 | Serial registration issued UID0004QY for `[0x005094b0,0x0050a4fd)`; Destination 4 matches byte-for-byte and command `000000012494` passed. |
| C06 | Parent and child pages retain exact half-open starts/ends and all boundary bytes; commands `000000012479`, `000000012485`, `000000012494`, and `000000012499` passed. |
| C07 | Parent/child evidence preserves the accepted SHA-256 range hashes; scoped validation accepted all four pages. |
| C08 | UID0004QY records the 191-block CFG plus EH/cookie/Region cleanup as excluded compiler lowering while its formal remains ordinary human C++; `000000012494` passed. |
| C09 | Getter six-xref, shared-tail two-branch, and paint three-call contracts remain in the exact child/parent/support evidence; child and parent validators passed. |
| C10 | UID00037V, UID0004QY, MapPane class/file, and MapPaneLayout carry the accepted offsets, roles, ordering, and lexical caps; commands `000000012499`, `000000012494`, and `000000012505`-`000000012507` passed. |
| C11 | MapPane class/layout, UID0003TL, and UID0003TK already carried waiting-for-local-player-status semantics under commands `000000012505`, `000000012507`, `000000012511`, and `000000012512`; bounded repair command `000000012622` now proves UID0000L3 also preserves exact `+0x3f0` naming, constructor/transition sets, `CreateOrUpdateObjectPane` clear, render/weather early-out and bounds suppression, and stripped-name cap. |
| C12 | UID0003UL and UserPane class/file now describe byte `[4]` as blindness while preserving B001's concurrent class/file union; commands `000000012508`-`000000012510` passed. |
| C13 | UID0004QY Destination 4 and prose preserve flash-fill then readiness early exits; generated `RenderMapView` contains the accepted gate. |
| C14 | UID0004QY preserves shadow-cache transition, palette work, overlay, day/night shadow, and attachment-light order; UID0002AZ linkage passed `000000012517`. |
| C15 | UID0004QY preserves clip copy, cached-surface transfer, viewport begin/end, and visible bounds; GrafPort copy-out support passed `000000012515` and `000000012516`. |
| C16 | UID0004QY preserves living prepass and ObjectList item/flying/row order; ObjectList-family pages remained verify-only because their authoritative accessor inventory already matched. |
| C17 | UID0004QY preserves both special-static-ID and remaining-static passes; StaticObjectPane remained verify-only because no existing contradiction required an edit. |
| C18 | UID0004QY preserves both secondary-effect predicates; EffectObjectPane class/file `+0x14d` support passed `000000012513` and `000000012514`. |
| C19 | UID0004QY retains fill color 128 and local-player/effect-only blind rendering; UserPane synchronization passed `000000012508`-`000000012510`. |
| C20 | UID0004QY retains object-info, balloon, hit-bar, and option-gated damage overlays in observed order; `000000012494` passed. |
| C21 | UID0004QY retains the final unused exposed-region query and automatic Region lifetime without handwritten cleanup; `000000012494` and generated readback passed. |
| C22 | `by-memory/-ignored.md` retains exact all-`cc` spans `[0x00509478,0x00509480)` and `[0x005094ae,0x005094b0)`; validator `000000012501` originally passed them. Current hash `59D3B77357D6D7B58367A6E26768608E0915B692568B06F64ED6F7599DF49232` preserves historical unrelated UID000373 LObject support and B003 UID0004R1 WinMain/BaramApp EH cleanup-thunk evidence, and adds unrelated B004 UID0002Q3 NewUserDialogPane alignment/compiler-support/vtable entries; none alters either MapPane range, byte hash, alignment/no-source disposition, replacement, owner link, or successor padding. |
| C23 | Existing `[0x0050a4fd,0x0050a500)` postpad remained unchanged and was verified in the ignored-page reread/validation. |
| C24 | Deltas are parent `-4`, UID0004QW `+4`, UID0004QX/UID0004QY `0`, UID00037W `-4`, UID0001AV `0`; commands `000000012499`, `000000012479`, `000000012485`, `000000012494`, `000000012503`, and `000000012504` passed. |
| C25 | MapPane class has the accepted getter/render/state inventory at unchanged `89/89` and unchanged formal policy; `000000012505` passed. |
| C26 | MapPane file retains exact child source order, shared-tail exclusion, padding/nesting, compiler-history detail, and unchanged `89/85` score/route; validator `000000012622` additionally proves the complete accepted `+0x3f0` field lifecycle after preserving all concurrent content. |
| C27 | MapPaneLayout now records the accepted `+0x3dc/+0x3e0/+0x3f0/+0x3f2/+0x418/+0x424/+0x428/+0x4c8` roles without score/formal change; `000000012507` passed. |
| C28 | Destination 5 changed only `oldSpeed` to `oldBlindnessLevel`; its installed block is byte-for-byte equal to the report, and B001's UserPane content was preserved under `000000012508`-`000000012510`. |
| C29 | Destination 6 changed only `m_hasRenderableMap` to `m_waitingForLocalPlayerStatus`; UID0003TK prose records producer lifecycle, and `000000012511`-`000000012512` passed. |
| C30 | EffectObjectPane class/file preserve unresolved `+0x14c/+0x14e` and resolve only `+0x14d` as late/after-living secondary-effect selection; `000000012513`-`000000012514` passed. |
| C31 | GrafPort class/file now document the exact `0x004b8dd0` 19-byte one-block `GetExposedRegion` copy-out and 30 xrefs/nine functions while rejecting stale SaveClipRegion naming; `000000012515`-`000000012516` passed. |
| C32 | MusicControlDialog, SoundManager, ObjectList/ObjectPane/LivingObjectPane/StaticObjectPane/AttachmentAnchor/PaletteLib/RegistryConfig/callback pages remained verify-only at their existing ownership/scores; UID0002AZ alone received the accepted direct render linkage under `000000012517`. |
| C33 | Parent/children/support pages retain no-string/table negatives, shared-tail non-helper proof, compiler exclusions, lexical caps, and explicit superseded old field/name assumptions. |
| C34 | Exact supervisor-owned manual coverage handoff text remains below with real UIDs as historical no-loss evidence. After exact report SHA `1920BE9767B0D0D31E5803BF3CAFA2F43736DEC88EF36DFD6D6B9B90948963D6` passed Gate 1, the supervisor applied all six insertions and 12 replacements and validated them through commands `000000012700`-`000000012703`; those commands and hashes are application-time evidence. Current readback at memory/class/file/type hashes `96546FE73C04070B835DA2C2656092D3E40E77B3CBAE29A7C803C23B0BEF8990` / `A16263EA62D0FC4C663E81E1027B60CA69E18A9B8D05D9960C334950884C0B4E` / `943D7A88E156A5FE1EEEC2C3AC0A305B961C0DF40F9814A5BF8B284096D93BF1` / `1414B291EE244470D06E623DA8D7C43C4F5FA47339C0991AB8FC3C2059AF2F56` proves all 18 rows present exactly at accepted same-or-greater detail after unrelated B003 UID00019H and B004 UID0003U7 additions. |
| C35 | All three registrations were serial, every changed ordinary page received scoped validation, and waited command `000000012518` completed the accepted callback refresh. Current read-only external full-refresh command `000000012699` proves one getter/one render definition, no parent/tail output, and no handwritten compiler mechanics; commands `000000012664`, `000000012692`, `000000012695`, and `000000012696` are retained as historical external snapshot evidence. |

## Positive Evidence Summary

- Exact bytes cleanly separate getter, internal padding, shared tail, internal padding, main render, postpadding, and paint successor.
- The getter has six live uses and an established `m_mapId` field.
- The shared suffix has two concrete source contexts and a compiler tail-chunk model.
- The main body is a large ordinary MapPane method called by successor paint and uses coherent MapPane/ObjectList/GrafPort state.
- Every major branch has current support evidence: flash, waiting state, blindness, shadow option, palette cache, day/night alpha, attachment lights, object-list passes, overlay tails, and final cleanup.
- Complete first-draft source is feasible without assembly-shaped ABI mechanics.

## IDA MCP Facts

| Range | Size | SHA-256 | Classification |
| --- | ---: | --- | --- |
| `0x00509470-0x0050a4fd` | `0x108d` / 4237 | `4757B916110CAC9D09C1E95DF01489E39543657B9E6BFE135225433095C6F9F6` | mixed parent |
| `0x00509470-0x00509478` | `0x8` | `CB2D23915E74303A2D1267CED1D91A4729F88299BAB51DBAFA421A2C983A2277` | live getter |
| `0x00509478-0x00509480` | `0x8` | `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3` | `cc` alignment |
| `0x00509480-0x005094ae` | `0x2e` | `BBC94AA53B1945FC1584DC52DCF6D4B815C400D2DA25DCC6258369949C1CEB1D` | shared compiler tail |
| `0x005094ae-0x005094b0` | `0x2` | `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2` | `cc` alignment |
| `0x005094b0-0x0050a4fd` | `0x104d` / 4173 | `E2327E1C2E3515673DFD0B9313C5C63F3A8B74BFABD419FAEF32315805DA6C88` | live render method |
| `0x0050a4fd-0x0050a500` | `0x3` | `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE` | existing ignored postpad |
| `0x0050a500-0x0050a510` | `0x10` | `449ACA26E6A891CD19B7FA7A83660FF56AD6429685199FF30113C76165D524C6` | paint successor prefix |

- Getter bytes: `0f b7 81 f2 03 00 00 c3`.
- Shared-tail first 16 bytes: `a1 c8 a7 67 00 83 b8 08 19 29 00 00 75 1f 6a 00`; final 16 bytes end in the SoundManager call and `c3`.
- Main prefix is the EH/security prologue keyed by handler data at `0x00602634`; main suffix performs security-cookie validation and ordinary epilogue.
- Main unique signature begins `55 8B EC 6A FF 68 34 26 60 00`; successor signature begins `55 8B EC 6A FF 68 89 26 60 00`.

## Function / Child Inventory

| Address | Modeled state | Accepted/applied source role |
| --- | --- | --- |
| `0x00509470-0x00509478` | `sub_509470`, one block, no callees | `MapPane::GetCurrentMapId() const` |
| `0x00509478-0x00509480` | no function, all `cc` | ignored alignment |
| `0x00509480-0x005094ae` | tail chunk of `sub_52A120` | non-emitting shared MusicControl/SoundManager suffix |
| `0x005094ae-0x005094b0` | no function, all `cc` | ignored alignment |
| `0x005094b0-0x0050a4fd` | `sub_5094B0`, 191 blocks, 39 callees | `MapPane::RenderMapView()` |
| `0x0050a4fd-0x0050a500` | no function, all `cc` | existing ignored alignment |
| `0x0050a500-0x0050a837` | `sub_50A500`, successor, vtable-only entry | MapPane paint/dirty-region caller, excluded |

## Direct Xref / Caller Inventory

- Getter has exactly six current code xrefs: `0x00450e4d`, `0x00452a4f`, `0x00452eb2`, `0x005a59b0`, `0x005a608c`, and `0x005ad326`. Modeled caller contexts include MiniMapDialog setup/render and UserPane key/input paths.
- Shared tail has exactly two incoming contexts: `0x0052a17a` from MusicControlDialog `ApplyPlaybackState` and `0x0057b00c` from the SoundManager audio-reinitialization bridge.
- Main render has three direct call sites, `0x0050a7cb`, `0x0050a7fc`, and `0x0050a805`, all inside successor paint. Paint calls once for a whole dirty region or per dirty rectangle according to its branch.
- `LivingObjectPane::UpdateScreenPosition` at `0x005a88d0` has exactly one direct caller, target site `0x00509563`, proving the local-player pre-render update.
- `g_mapRenderScratchFlag` at `0x0069b4f8` has the target compare at `0x00509579` and store at `0x005095b0`.
- Main's direct callee families include GrafPort bounds/clip/paint/blit/color APIs, Rect/Region operations, ObjectList accessors, ObjectPane map/data/render APIs, tile rendering, PaletteLib filters, UserPane/LivingObjectPane screen update, attachment-light resolution, alpha-mask application, alpha-lookup callback, and security-cookie support.

## Documentation Evidence And IDA Status

- UID00007Q and UID0000L3 already established MapPane and MapPane.cpp as the correct source route. At evidence time their render inventory was summary-only and omitted this split/body; the completed callback added the accepted detail without changing their route or formal policy.
- UID00009Q ObjectList supplies exact flat/global/row accessor names. UID00009R ObjectPane supplies GetMapPosition, GetObjectData, RenderFrame, GetEmptyRect, and DrawSpriteFrame contracts plus MapPane friendship.
- UID00007B LivingObjectPane supplies primary/secondary attached-effect lists and UpdateScreenPosition/RenderFrame/DrawSpriteFrame behavior.
- Historical UID000049 left `+0x14d` unresolved; the target's direct two-pass consumer evidence now supports the bounded after-living/late-effect role in current class/file prose.
- At evidence time UID00005V/UID0000JR covered exposed/clip Region state but omitted compact `0x004b8dd0`; current class/file prose now includes that copy-out accessor.
- Historical UID0003UL named the saved byte `oldSpeed`; this target and parser invalidation path disproved that meaning, and current formal/support text uses `oldBlindnessLevel`/blindness semantics.
- Historical UID0003TL tested `m_hasRenderableMap`; producer/clear/consumer lifecycle proved a waiting/not-ready flag with opposite semantic wording, and current formal/support text uses `m_waitingForLocalPlayerStatus`.
- UID0002AZ already identified the one-byte shadow-option cache; current prose now includes exact UID0004QY linkage and transition semantics without score or ownership change.

## Ranked Ownership Analysis

1. **Split parent with MapPane source children and no-owner compiler tail**: best. Receiver fields, successor paint, class/file route, and two cross-owner tail contexts all agree.
2. **Whole range owned by MapPane**: rejected. It would misattribute MusicControlDialog/SoundManager source and emit a physically mixed monolith.
3. **Whole range owned by MusicControlDialog or SoundManager**: rejected. Getter and 4173-byte main body are unambiguously MapPane.
4. **Raw interval as standalone helper**: rejected. It is a shared tail reached by two predecessor methods and has no independent call contract.
5. **Main render as GrafPort/ObjectList/LivingObjectPane owner**: rejected. Those are dependencies; the receiver and paint caller are MapPane.
6. **Compiler-generated/no-source main render**: rejected. It is a live vtable-driven ordinary source method with extensive product policy.

## Source Placement

- Getter and render definitions belong to UID0000L3 `NexusTK/map/MapPane.cpp` through class UID00007Q.
- Getter precedes render in exact address/source order. The shared tail receives no source emission and no by-file owner.
- Current optional emitter positions remain blank; address order under MapPane is sufficient.
- Music playback policy remains in UID0003MK MusicControlDialog `ApplyPlaybackState` and the SoundManager audio-reinitialization source context; no third source helper is created.
- UserPane parser correction remains in `NexusTK/ui/panels/UserPane.cpp`; map-info field-token correction remains in MapPane.cpp.

## Range / Split / Padding / Reclassification Analysis

- Parent exact range stays `[0x00509470,0x0050a4fd)`; only its source disposition changes.
- New children are exact and non-overlapping: getter `[0x00509470,0x00509478)`, shared tail `[0x00509480,0x005094ae)`, render `[0x005094b0,0x0050a4fd)`.
- Internal gaps `[0x00509478,0x00509480)` and `[0x005094ae,0x005094b0)` are all-`cc` alignment and belong in `by-memory/-ignored.md`, not child pages.
- Existing `[0x0050a4fd,0x0050a500)` ignored row remains correct and is verify-only.
- Cumulative nesting plan in address order: parent UID00037V `Nested:-4`; getter child `Nested:+4`; shared-tail child `Nested:0`; render child `Nested:0`; successor UID00037W `Nested:-4`; following UID0001AV changes `Nested:-4` to `Nested:0`; UID00037X remains `Nested:0`. This yields direct children under the parent and restores the following siblings to their prior direct level.

## Negative Evidence Summary

- No strings and no switch/jump table occur in the main render body.
- Getter is not inline-only, padding, data, thunk, or compiler wrapper: six live code refs target its exact entry.
- Shared tail is not padding and not dead bytes, but it is also not an independently called helper. Both facts must coexist.
- Shared tail has no independent address materialization, pointer-table, vtable, source declaration, or generated helper route.
- Main is not a tail of paint; it has an independent prologue/epilogue and paint calls it normally.
- No evidence supports adding null checks around the local player/ObjectList after readiness passes; source must preserve the observed dereferences.
- No evidence supports collapsing the two static passes, secondary-effect passes, final clip query, or malformed/odd ordering as optimization noise.
- No evidence supports handwritten vptr, EH, security-cookie, callback-indirection lowering, or Region destructor calls.
- Historical `m_hasRenderableMap`, `oldSpeed`, generic embedded selection overlay, and standalone shared music helper interpretations are superseded, not silently deleted.

## IDA Rename / Type / Comment Recommendations

- Rename `sub_509470` to `MapPane__GetCurrentMapId` with type `unsigned short __thiscall MapPane::GetCurrentMapId() const`.
- Comment `[0x00509480,0x005094ae)` as a compiler tail shared by MusicControlDialog playback-state and SoundManager audio reinitialization; do not create a function or source symbol.
- Rename `sub_5094B0` to `MapPane__RenderMapView` with type `void __thiscall MapPane::RenderMapView()`.
- Comment MapPane `+0x3f0` as waiting for local-player status/map render readiness; comment UserPane state byte `[4]` as blindness level; comment EffectObjectPane `+0x14d` as late/after-living render selection.
- These are recommendations only. B005 did not mutate IDA.

## First-Draft C++ Recommendation

The following six accepted destination blocks are the only applied C++ changes. Each block remains independently destination-specific, complete, and byte-for-byte equal to its installed managed block. No C++ was added to class/file/layout/global prose-only support pages.

### Destination 1 - UID00037V parent

`by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - exact getter child

`by-memory/0x00509470-0x00509478.MapPaneGetCurrentMapId.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned short MapPane::GetCurrentMapId() const
{
    return m_mapId;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - shared compiler-tail child

`by-memory/0x00509480-0x005094ae.SharedMusicPlaybackTail.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - exact render child

`by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace
{
    ObjectPane *GetObjectPaneAt(List *objects, int index)
    {
        return *static_cast<ObjectPane **>(objects->GetElementAt(index));
    }

    bool GetVisibleObjectBounds(MapPane *mapPane,
                                ObjectPane *objectPane,
                                RectBounds *objectBounds)
    {
        Region exposedRegion;
        objectPane->GetObjectData(objectBounds);
        mapPane->GetExposedRegion(&exposedRegion);
        return exposedRegion.IntersectWithRect(objectBounds);
    }

    void RenderObjectList(MapPane *mapPane, List *objects)
    {
        for (int index = 0; index < objects->GetCount(); ++index)
        {
            ObjectPane *objectPane = GetObjectPaneAt(objects, index);
            RectBounds objectBounds;
            if (GetVisibleObjectBounds(mapPane, objectPane, &objectBounds))
                objectPane->RenderFrame(mapPane, &objectBounds);
        }
    }

    void RenderEffectList(MapPane *mapPane, List *effects)
    {
        RenderObjectList(mapPane, effects);
    }
}

void MapPane::RenderMapView()
{
    if (m_mapFlashColor != 0)
    {
        RectBounds mapBounds;
        SetDrawColor(m_mapFlashColor);
        GetBounds(&mapBounds);
        g_pfnFillRect(this, &mapBounds);
        return;
    }

    Region exposedRegion;

    const unsigned char blindnessLevel =
        m_localPlayerObjectPane->m_playerSettingsState[4];
    if (m_waitingForLocalPlayerStatus)
        return;

    m_localPlayerObjectPane->UpdateScreenPosition();

    const bool shadowEnabled = g_pConfig->m_shadowEnabled != 0;
    if (g_mapRenderScratchFlag != static_cast<unsigned char>(shadowEnabled))
    {
        g_pPaletteLib->UpdatePaletteFilterTables(m_dayNightTargetBrightness);
        DrawVisibleTiles();
        QueueMotionMessage(NULL);
        g_mapRenderScratchFlag = static_cast<unsigned char>(shadowEnabled);
    }

    if (shadowEnabled && m_dayNightTargetBrightness != 1.0f)
    {
        RectBounds shadowBounds;
        GetClipRect(&shadowBounds);
        m_selectionOverlay.ApplyRectAlpha(
            NULL,
            static_cast<int>(m_dayNightTargetBrightness * 32.0f + 0.5f),
            0);

        if (m_dayNightTargetBrightness < 0.60000002f)
        {
            List *lights = m_objectList->GetQuaternaryGlobalList();
            for (int index = 0; index < lights->GetCount(); ++index)
            {
                LightingObjectPane *light = static_cast<LightingObjectPane *>(
                    GetObjectPaneAt(lights, index));
                RectBounds lightBounds;
                Point lightCenter;
                light->ComputeScreenBounds(&lightBounds);
                if (IntersectRects(&lightBounds, &shadowBounds, &lightBounds))
                {
                    light->ResolveAnchorPoint(&lightCenter);
                    light->ApplyLightAtAnchor(this, lightCenter.x, lightCenter.y);
                }
            }
        }
    }
    else if (!shadowEnabled)
    {
        g_pPaletteLib->SetPaletteFilterActive(true);
    }

    MapRect visibleTiles;
    GetClampedVisibleTileBounds(&visibleTiles);
    InflateRect(&visibleTiles, -1, -1);
    if (visibleTiles.left < 0)
        visibleTiles.left = 0;
    if (visibleTiles.top < 0)
        visibleTiles.top = 0;
    if (visibleTiles.right > m_mapWidth)
        visibleTiles.right = m_mapWidth;
    if (visibleTiles.bottom > m_mapHeight)
        visibleTiles.bottom = m_mapHeight;

    RectBounds clipBounds;
    GetClipRect(&clipBounds);
    if (!IsRectEmpty(&clipBounds))
    {
        EndPaint();
        BlitSurface(&m_viewportGrafPort, &clipBounds, &clipBounds, 0);
        BeginPaint();
    }

    if (blindnessLevel == 0)
    {
        if (shadowEnabled)
        {
            for (int row = visibleTiles.top; row < visibleTiles.bottom; ++row)
            {
                List *livingObjects = m_objectList->GetFrontRowBucket(row);
                for (int index = 0; index < livingObjects->GetCount(); ++index)
                {
                    ObjectPane *objectPane = GetObjectPaneAt(livingObjects, index);
                    RectBounds emptyBounds;
                    RectBounds objectBounds;
                    objectPane->GetEmptyRect(&emptyBounds);
                    GetExposedRegion(&exposedRegion);
                    if (exposedRegion.IntersectWithRect(&emptyBounds))
                    {
                        objectPane->GetObjectData(&objectBounds);
                        objectPane->DrawSpriteFrame(this, &objectBounds);
                    }
                }
            }
        }

        RenderObjectList(this, m_objectList->GetPrimaryCellList());
        RenderObjectList(this, m_objectList->GetSecondaryCellList());

        const unsigned short firstStaticId = g_useEpfAssets ? 14347 : 13968;
        const unsigned short secondStaticId = g_useEpfAssets ? 14349 : 13970;

        for (int row = visibleTiles.top; row < visibleTiles.bottom; ++row)
        {
            RenderEffectList(this, m_objectList->GetPrimaryRowBucket(row));

            List *staticObjects = m_objectList->GetBackRowBucket(row);
            for (int index = 0; index < staticObjects->GetCount(); ++index)
            {
                StaticObjectPane *objectPane = static_cast<StaticObjectPane *>(
                    GetObjectPaneAt(staticObjects, index));
                if (objectPane->m_staticObjectId == firstStaticId ||
                    objectPane->m_staticObjectId == secondStaticId)
                {
                    RectBounds objectBounds;
                    if (GetVisibleObjectBounds(this, objectPane, &objectBounds))
                        objectPane->RenderFrame(this, &objectBounds);
                }
            }

            RenderObjectList(this, m_objectList->GetFrontRowBucket(row));

            for (int index = 0; index < staticObjects->GetCount(); ++index)
            {
                StaticObjectPane *objectPane = static_cast<StaticObjectPane *>(
                    GetObjectPaneAt(staticObjects, index));
                if (objectPane->m_staticObjectId != firstStaticId &&
                    objectPane->m_staticObjectId != secondStaticId)
                {
                    RectBounds objectBounds;
                    if (GetVisibleObjectBounds(this, objectPane, &objectBounds))
                        objectPane->RenderFrame(this, &objectBounds);
                }
            }

            List *secondaryEffects = m_objectList->GetSecondaryRowBucket(row);
            for (int index = 0; index < secondaryEffects->GetCount(); ++index)
            {
                EffectObjectPane *effect = static_cast<EffectObjectPane *>(
                    GetObjectPaneAt(secondaryEffects, index));
                if (!effect->m_renderAfterLivingObjects)
                {
                    RectBounds effectBounds;
                    if (GetVisibleObjectBounds(this, effect, &effectBounds))
                        effect->RenderFrame(this, &effectBounds);
                }
            }
        }

        const int lastBackRow = Min(
            static_cast<int>(m_mapHeight),
            static_cast<int>(m_tileOriginY + m_visibleTileRows + 9));
        for (int row = visibleTiles.bottom; row < lastBackRow; ++row)
            RenderObjectList(this, m_objectList->GetBackRowBucket(row));

        for (int row = visibleTiles.top; row < visibleTiles.bottom; ++row)
        {
            List *secondaryEffects = m_objectList->GetSecondaryRowBucket(row);
            for (int index = 0; index < secondaryEffects->GetCount(); ++index)
            {
                EffectObjectPane *effect = static_cast<EffectObjectPane *>(
                    GetObjectPaneAt(secondaryEffects, index));
                if (effect->m_renderAfterLivingObjects)
                {
                    RectBounds effectBounds;
                    if (GetVisibleObjectBounds(this, effect, &effectBounds))
                        effect->RenderFrame(this, &effectBounds);
                }
            }
        }
    }
    else
    {
        RectBounds mapBounds;
        SetDrawColor(128);
        GetBounds(&mapBounds);
        g_pfnFillRect(this, &mapBounds);

        MapPoint playerPosition;
        m_localPlayerObjectPane->GetMapPosition(&playerPosition);
        if (playerPosition.x >= visibleTiles.left &&
            playerPosition.x < visibleTiles.right &&
            playerPosition.y >= visibleTiles.top &&
            playerPosition.y < visibleTiles.bottom)
        {
            RenderEffectList(
                this, m_localPlayerObjectPane->m_primaryEffectObjectPanes);

            RectBounds playerBounds;
            if (GetVisibleObjectBounds(
                    this, m_localPlayerObjectPane, &playerBounds))
            {
                m_localPlayerObjectPane->RenderFrame(this, &playerBounds);
            }

            RenderEffectList(
                this, m_localPlayerObjectPane->m_secondaryEffectObjectPanes);
        }
    }

    if (shadowEnabled && m_dayNightTargetBrightness != 1.0f)
    {
        RectBounds alphaBounds;
        GetClipRect(&alphaBounds);
        g_pfnBlitAlphaLookup(
            this, &m_selectionOverlay, &alphaBounds, &alphaBounds);
    }
    else if (!shadowEnabled)
    {
        g_pPaletteLib->SetPaletteFilterActive(false);
    }

    if (blindnessLevel == 0)
    {
        List *objectInfoObjects = m_objectList->GetTertiaryGlobalList();
        for (int index = 0; index < objectInfoObjects->GetCount(); ++index)
        {
            ObjectInfoObjectPane *objectInfo =
                static_cast<ObjectInfoObjectPane *>(
                    GetObjectPaneAt(objectInfoObjects, index));
            objectInfo->UpdatePosition();
            RectBounds objectBounds;
            if (GetVisibleObjectBounds(this, objectInfo, &objectBounds))
                objectInfo->RenderFrame(this, &objectBounds);
        }

        RenderObjectList(this, m_objectList->GetVisibleObjectList());
        RenderObjectList(this, m_objectList->GetSecondaryGlobalList());
        if (g_pConfig->m_showDamage)
            RenderObjectList(this, m_objectList->GetAlternateGlobalList());
    }

    RectBounds unusedFinalClipBounds;
    GetClipRect(&unusedFinalClipBounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5 - UserPane blindness correction

`by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserPane::ParsePlayerSettingsPacket(const unsigned char *packet)
{
    const unsigned char flags = packet[1];
    m_playerSettingsState[0] = static_cast<unsigned char>(flags >> 7);
    if (flags & 0x04)
        m_objectStatus.m_actionState = 3;
    m_playerSettingsState[2] = (flags & 0x02) == 0;

    unsigned int offset = (flags & 0x40) ? 39 : 10;
    if (flags & 0x20)
        offset += 8;
    if (flags & 0x10)
        offset += 9;
    if (flags & 0x08)
    {
        const unsigned char oldBlindnessLevel = m_playerSettingsState[4];
        m_playerSettingsState[3] = packet[offset++];
        m_playerSettingsState[4] = packet[offset++];
        m_playerSettingsState[5] = packet[offset++];
        m_playerSettingsState[6] = packet[offset++];
        ++offset;
        if (oldBlindnessLevel != m_playerSettingsState[4])
            m_mapPane->RefreshMovementBounds();
    }

    g_pConfig->m_sendMovementStatusBit = packet[++offset];
    if (g_pConfig->m_sendMovementStatusBit && IsDirectionDelayActive())
    {
        RemovePendingTimers();
        SetDirectionDelayActive(false);
        m_isMoving = false;
    }

    const unsigned short options =
        PacketBufferReadUInt16BE(packet + offset + 1);
    g_pConfig->ApplyServerOptionBits(options);
    if (g_pConfig->m_soundEnabled)
        g_pSoundManager->EnableSound();
    else
        g_pSoundManager->DisableSound();
    g_pMainWindow->RefreshSettingsPaneIfVisible();
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 6 - MapPane waiting-state correction

`by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace
{
    enum MapInfoTileRegionPacketFlags
    {
        kMapInfoTileRegionHasMapName = 0x01,
        kMapInfoTileRegionHasResourceName = 0x02,
        kMapInfoTileRegionHasResourceMode = 0x04
    };

    struct MapInfoTileRegionPacketView
    {
        explicit MapInfoTileRegionPacketView(const unsigned char *packetBytes)
            : bytes(packetBytes), cursor(1)
        {
        }

        unsigned char ReadByte()
        {
            return bytes[cursor++];
        }

        unsigned short ReadUInt16()
        {
            unsigned short value = PacketBufferReadUInt16BE(bytes + cursor);
            cursor += 2;
            return value;
        }

        unsigned short ReadTileWord()
        {
            return PacketBufferReadUInt16BE(bytes, &cursor);
        }

        int ReadAnsiString(char *buffer, int bufferCount)
        {
            int byteCount = ReadByte();
            int copyCount = byteCount;
            if (copyCount >= bufferCount)
                copyCount = bufferCount - 1;

            GetMemoryMan()->MemmoveWrapper(buffer, bytes + cursor, copyCount);
            buffer[copyCount] = '\0';
            cursor += byteCount;
            return copyCount;
        }

        const unsigned char *bytes;
        int cursor;
    };
}

bool MapPane::HandleMapInfoTileRegionPacket(const unsigned char *packet)
{
    char mapNameBytes[256];
    char resourceNameBytes[256];
    wchar_t epfResourceName[260];
    wchar_t palResourceName[260];

    MapInfoTileRegionPacketView packetView(packet);
    unsigned char oldResourceMode = m_mapResourceMode;
    unsigned char flags = packetView.ReadByte();

    m_mapNameLength = 0;
    m_mapResourceNameLength = 0;
    m_mapResourceMode = 0;

    if ((flags & kMapInfoTileRegionHasMapName) != 0)
    {
        int mapNameLength = packetView.ReadAnsiString(mapNameBytes, sizeof(mapNameBytes));
        m_mapNameLength = static_cast<unsigned char>(
            MultiByteToWideChar(CP_ACP, 0, mapNameBytes, mapNameLength, m_mapName, 256));
        m_mapName[m_mapNameLength] = L'\0';
    }

    if ((flags & kMapInfoTileRegionHasResourceName) != 0)
    {
        int resourceNameLength = packetView.ReadAnsiString(resourceNameBytes, sizeof(resourceNameBytes));
        m_mapResourceNameLength = static_cast<unsigned char>(
            MultiByteToWideChar(CP_ACP, 0, resourceNameBytes, resourceNameLength, m_mapResourceName, 256));
        m_mapResourceName[m_mapResourceNameLength] = L'\0';

        wcscpy_s(epfResourceName, _countof(epfResourceName), m_mapResourceName);
        wcscat_s(epfResourceName, _countof(epfResourceName), L".EPF");
        wcscpy_s(palResourceName, _countof(palResourceName), m_mapResourceName);
        wcscat_s(palResourceName, _countof(palResourceName), L".PAL");
    }

    if ((flags & kMapInfoTileRegionHasResourceMode) != 0)
        m_mapResourceMode = packetView.ReadByte();

    if (m_mapResourceMode != oldResourceMode)
        ResetMapResourceStateForModeChange();

    int originTileX = packetView.ReadUInt16();
    int originTileY = packetView.ReadUInt16();
    int tileWidth = packetView.ReadByte();
    int tileHeight = packetView.ReadByte();

    MapRect packetBounds;
    SetRectBounds(&packetBounds, originTileX, originTileY,
        originTileX + tileWidth, originTileY + tileHeight);

    MapRect mapBounds;
    SetRectBounds(&mapBounds, 0, 0, m_mapWidth, m_mapHeight);

    MapRect clippedBounds = packetBounds;
    IntersectRectBounds(&clippedBounds, &mapBounds);

    for (int tileY = clippedBounds.top; tileY < clippedBounds.bottom; ++tileY)
    {
        for (int tileX = clippedBounds.left; tileX < clippedBounds.right; ++tileX)
        {
            MapPaneTileRecord &tile = m_tileBuffer[tileX + tileY * m_mapWidth];
            unsigned short oldGroundTileId = tile.groundTileId;

            tile.groundTileId = packetView.ReadTileWord();
            unsigned short tileFlags = packetView.ReadTileWord();
            tile.flags = static_cast<unsigned short>((tile.flags & ~1) | (tileFlags & 1));
            tile.staticObjectId = packetView.ReadTileWord();

            if (tile.groundTileId != oldGroundTileId)
                DrawTileAt(tileX, tileY, true);
        }
    }

    MapRect refreshBounds;
    if (m_refreshWholeVisibleMap)
    {
        m_refreshWholeVisibleMap = false;
        GetExtendedVisibleTileBounds(&refreshBounds);
    }
    else if (m_waitingForLocalPlayerStatus)
    {
        SetRectBounds(&refreshBounds, 0, 0, 0, 0);
    }
    else
    {
        GetExtendedVisibleTileBounds(&refreshBounds);
        IntersectRectBounds(&refreshBounds, &clippedBounds);
    }

    RefreshStaticObjectTileRegion(refreshBounds);

    if (g_useEpfAssets)
        RefreshDeferredMapSurfacesForTileRegion();

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

## Final Recommendation

- C01-C35 are implemented and verified under the accepted Gate 1 scope.
- Completed serial-registration evidence: the getter registered first as UID0004QW and its placeholder was replaced everywhere before the shared-tail child was created; the shared tail then registered as UID0004QX and its placeholder was replaced everywhere before render child UID0004QY was created. The UID0004QY token was then replaced everywhere. No placeholder remains, and no UID was guessed or pre-referenced.
- All six managed blocks are applied byte-for-byte. Parent and shared-tail bodies stay blank by design; getter and render emit through MapPane; two existing support formals received only the proven token correction while preserving every other line.
- Keep all support scores/routes/formals unchanged unless explicitly listed. Preserve every negative, rejected, historical, caller/callee, raw-liveness, compiler-artifact, and lexical-cap fact.
- First Gate 2 rebase verification found all then-audited B005 facts present on the three concurrent support pages and therefore performed only report/manual-row/hash/generated reconciliation. The later independent C11 audit identified one separate file-level Rule 26 omission; the bounded UID0000L3 repair above closes it without changing any other destination.

## Recommended Target Doc Changes

- Applied and verified on UID00037V: `92/94`, owner NONE, reconstructable false, blank emitter/position/formal, exact mixed split Item Summary, `Nested:-4`, complete bytes/hashes/function/xref/render/tail/compiler/history evidence, and links to all three real children.
- Applied and verified on getter child UID0004QW: exact `92/94`, owner/emitter UID00007Q, reconstructable true, blank position, `Nested:+4`, exact Item Summary, and Destination 2.
- Applied and verified on shared-tail child UID0004QX: exact `92/94`, owner NONE, reconstructable false, blank emitter/position/formal, `Nested:0`, exact Item Summary, two-context tail proof, canonical source links, and Destination 3.
- Applied and verified on render child UID0004QY: exact `92/93`, owner/emitter UID00007Q, reconstructable true, blank position, `Nested:0`, exact Item Summary, full behavior/evidence, and Destination 4.
- No child was created for either internal padding span; both are exact ignored entries.

Exact applied target metadata and Item Summaries:

- UID00037V: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, Destination 1, and `Nested:-4`.
  - Item Summary: `Non-emitting mixed split index over exact MapPane GetCurrentMapId and RenderMapView source children, one proven MusicControlDialog/SoundManager compiler-shared playback tail, internal alignment, exact bytes/hashes/callers/callees/field and render-order evidence, cumulative nesting, source placement, rejected alternatives, and complete source/no-source dispositions.`
- UID0004QW: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, Destination 2, and `Nested:4`.
  - Item Summary: `Exact eight-byte MapPane::GetCurrentMapId() const leaf over m_mapId at +0x3f2; one block, six direct code consumers, exact bytes/hash/signature, established field/class/file route, rejected padding/data/thunk alternatives, and complete human C++.`
- UID0004QX: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, Destination 3, and `Nested:0`.
  - Item Summary: `Exact non-emitting compiler-folded playback suffix shared by MusicControlDialog::ApplyPlaybackState and the SoundManager audio-reinitialization source context; two incoming branches, config music-source gate, active-MapPane PlayMusicByZone arguments, shared return, canonical complete-method source placement, and rejection of an invented standalone helper.`
- `UID0004QY`: `COMPLETION:92`, `CONFIDENCE:93`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, Destination 4, and `Nested:0`.
  - Item Summary: `Exact source-ready MapPane::RenderMapView() method called three times from successor paint; 0x104d bytes, 191 blocks, 39 direct callee targets, flash/readiness/blindness gates, shadow/palette/light overlay, cached surface, LivingObjectPane/ObjectList render order, static/effect passes, object-info/balloon/hit-bar/damage tail, final clip query, EH/compiler exclusions, negative evidence, and complete human C++.`

## Recommended Support Doc Changes

- Applied to UID00037W: only `Nested:0` to `Nested:-4` plus exact closure/predecessor-split history; `86/90`, owner/emitter, true, blank formal, title/range, and all paint/lighting evidence remain preserved.
- Applied to UID0001AV: only `Nested:-4` to `Nested:0` plus exact cumulative-nesting history; complete source-ready writer content, `92/93`, metadata, and formal body remain preserved.
- Applied to `by-memory/-ignored.md`: `[0x00509478,0x00509480)` and `[0x005094ae,0x005094b0)` exact all-`cc` alignment entries; existing `[0x0050a4fd,0x0050a500)` remains unduplicated.
- Applied to UID00007Q MapPane, UID0000L3 MapPane file, and UID00042K MapPaneLayout: exact split/render/getter/source-order/field-role/nesting/compiler/history evidence at unchanged scores and formal routes.
- Applied to UID0003UL plus UserPane class/file: Destination 5 only on the child, `oldSpeed` historicalized, and `[4]` documented as blindness level at unchanged scores/routes. B001's concurrent UserPane union was reread and preserved.
- Applied to UID0003TL/UID0003TK: Destination 6 byte-for-byte with only the field token changed, plus prose-only producer/state-lifecycle synchronization; metadata/formals remain unchanged.
- Applied to EffectObjectPane class/file: `+0x14d` is the after-living/late secondary-effect render selector with the original-spelling caveat; scores and current class covered/exclusion formal remain unchanged.
- Applied to GrafPort class/file: `GetExposedRegion(Region *out) const` copy-out role at `0x004b8dd0`, exact 19-byte one-block body, 30 xrefs across nine functions, and rejection of historical caller-biased SaveClipRegion naming; scores/formals remain unchanged.
- Applied to UID0002AZ scratch global: exact new render-child linkage and config transition semantics at preserved score/owner/emitter/formal.
- MusicControlDialog UID0003MK and SoundManager audio-reinit pages were verify-only: current text already explains the shared source policy, so source bodies/scores remained unchanged.
- ObjectList/ObjectPane/LivingObjectPane/StaticObjectPane/AttachmentAnchor/PaletteLib/RegistryConfig/callback-global pages were verify-only; their existing APIs and ownership remain authoritative without an exact contradiction.

## Score And Metadata Recommendation

| Destination | Baseline | Applied | Owner/emitter | Reconstructable | Nested |
| --- | --- | --- | --- | --- | ---: |
| UID00037V parent | `85/88` | `92/94` | `NONE` / blank | false | `-4` |
| getter child | new | `92/94` | UID00007Q / UID00007Q | true | `+4` |
| shared-tail child | new | `92/94` | `NONE` / blank | false | `0` |
| render child | new | `92/93` | UID00007Q / UID00007Q | true | `0` |
| UID00037W | `86/90` | unchanged | unchanged | true | `-4` |
| UID0001AV | `92/93` | unchanged | unchanged | true | `0` |

- Parent completion improves because every byte is classified and linked; confidence reaches 94 because boundaries/source/no-source dispositions are exact.
- Getter confidence reaches 94 from exact leaf body, field, and six xrefs.
- Shared-tail confidence reaches 94 because both source contexts and compiler sharing are proved; non-emitting does not imply low confidence.
- Render confidence remains 93 because stripped private helper/field spellings, especially EffectObjectPane `+0x14d`, remain inferred despite exact behavior.
- No support score change was applied.

## Open Questions With Attempted Resolution

- Original getter spelling could be `GetMapId` rather than `GetCurrentMapId`. Current family vocabulary and six consumers support the applied name; impact is lexical confidence only.
- Original render spelling could omit “Map”. Existing file inventory already uses `RenderMapView`, and paint caller semantics agree; source body is not blocked.
- Original names for waiting state, shadow overlay, and late-effect byte are stripped. Producer/consumer lifecycles resolve types and semantics; descriptive names are implementation-ready and explicitly capped.
- The shared tail's two source contexts may have duplicated an inline helper in the original header. No independent symbol/call/table route supports emitting that hypothetical helper; preserving statements in both complete methods is the least-inventive source model.
- `GetExposedRegion` original spelling is not symbol-proven. Exact copy-out behavior and broad caller fan-in resolve the API shape; name remains a confidence cap.
- No unresolved question blocks split, ownership, child metadata, formal C++, source placement, nesting, coverage text, or material score improvement.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

### Historical Pre-Application Handoff Matrix

- Before supervisor application, the bounded Rule 26 handoff recheck read `by-memory/-coverage-report.md` SHA-256 `41E7CE452F2E4676C668D1886589592564A2B27302FB951542B5454F9A82590D`, `by-class/-coverage-report.md` SHA-256 `E1638CFF87659B03D4D9E56A9F33A219A76F0FCEB4857E6892E4CAA59E9625D0`, `by-file/-coverage-report.md` SHA-256 `85077966A0F36FD83B6E00B67FF573AC363544D33CCFA9C6978251E0A4DD1CEB`, and `by-type/by-struct/-coverage-report.md` SHA-256 `583F115F703900CEE542EB34B97CAC12BCBC74CB54FFEB17D2CC9155B1E82062`. The historical matrix covered all 18 handoff rows: six then-absent UID00037V/UID0004QW/UID0004QX/UID0004QY/padding insertions and 12 existing rows requiring no-loss replacement. UID00037W remained absent and needed no standalone insertion; UID0001AV already had a complete source-ready SaveUserSettings row and was verify-only.
- Historical score/no-regression audit; quoted summaries below are the exact pre-application manual row text that the accepted unions had to preserve:

| Historical manual destination | Ordinary completion/confidence | Pre-application manual state | Accepted handoff disposition |
| --- | --- | --- | --- |
| UID00037V / UID0004QW / UID0004QX / UID0004QY / two ignored spans | `92/94`, `92/94`, `92/94`, `92/93`, ignored | No dedicated rows for any of the six exact insertions. | Keep the six exact insertions below. |
| UID00007Q MapPane class | `89/89` | `89%`: "Live game-world pane class with blank broad class formal and child-only source emission; UID00037X is now a non-emitting seven-child interaction/map-change split with seven source-ready methods, exact packet/object-list/target/global/weather/flash/refresh fields, switch-table/padding evidence, missing-route liveness caps, and load/save/draw ordering." | Preserve that complete UID00037X state and add UID00037V split/render facts at `89%`. |
| UID0000FQ UserPane class | `92/93` | `92%`: "Complete 0x13eb84 local-player UserPane declaration with exact movement/packet/server inventory, external movement/event helper declarations, corrected viewport half/remaining column/row fields, movement-history records, corrected opcode-0x13 movement-target sender, MapPane friendship, action mode, exact +0x13eb3e adjacent-target bool split, and preserved full field/record/size-guard surface." | Use the full no-loss B001+B005 union below; add blindness without dropping ProcessMovement, viewport, helper, history, or layout facts. |
| UID000049 EffectObjectPane class | `85/86` | `85%`: "EffectObjectPane class support with exact public m_effectId at +0x148, looping/timer behavior, primary/secondary LivingObjectPane list registration and duplicate-key evidence, while its broader class declaration remains intentionally withheld pending independent constructor/layout closure." | Preserve every current fact and add only the `+0x14d` late-pass role at `85%`. |
| UID00005V GrafPort class | `88/90` | `88%`: "Core graphics-port class with exact surface/clip/draw/text children; UID00016E is now a non-emitting mixed physical index whose exact rect-based outlined and duplicate-offset methods emit through GrafPort, while UID00016F remains an independently owned callback." | Preserve every current fact and add the `0x004b8dd0` exposed-region copy-out at `88%`. |
| UID0000L3 MapPane file | `89/85` | `89%`: "Major NexusTK/map/MapPane.cpp source root with source-ready compressed-map load/save, interaction/map-change/coordinate/movement families, shared MapPoint declaration ownership, external DirectionToTileOffset linkage and cross-source consumers, and UID00037X's seven exact definitions including route-negative FlashMapColor and FinishVisibleObjectRefresh; also preserves the selected-target external declaration, ObjectList lifecycle, packet/timer/global/weather/render dependencies, exact switch-table handling and source order, and compiler-artifact exclusions." | Use the full no-loss B001+B005 union below; add UID00037V without dropping MapPoint, external-helper, coordinate, movement, source-order, or compiler-exclusion facts. |
| UID0000P1 UserPane file | `91/92` | `91%`: "NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families, exact ProcessMovement direction/effect/packet/history/event behavior, retained waypoint/facing inline-equivalent helpers, corrected helper declarations, and corrected opcode-0x13 movement-target sender using MapPane collect/sort with exact count-versus-nine cap/local terminator behavior; preserves action/adjacent-target fields, packet ABI, movement-history, server, target, and caller evidence." | Use the full no-loss B001+B005 union below; add blindness without dropping ProcessMovement, helpers, opcode behavior, ABI, history, server, target, or callers. |
| UID0000IZ Effects file | `90/88` | `88%`: "Runtime effecter module with class inventory, vtable family, small-constructor caveats, EffectObjectPane relationship, asset-library separation, global alias correction, open split questions, and endpoint/range changes documented." | Raise only the stale manual completion to current `90%`, retain every quoted fact, and add the `+0x14d` role. |
| UID0000JR GrafPort file | `89/88` | `89%`: "Render source family for GrafPort surface, clipping, drawing, glyph, wrapped-text, and exact rect text-effect methods; mixed UID00016E emits only through its two GrafPort children and excludes UID00016F and UID0003ZP source ownership." | Preserve every current fact and add the exposed-region contract at `89%`. |
| UID0003UL | `86/88` | `86%`: "Complete source-ready OnServerMessage child over UserPane flags/map state." | Replace at `86%` with the complete current parser/blindness summary below. |
| UID0003TL | `90/90` | `90%`: "Complete source-ready opcode-0x06 map-info/tile-region parser with exact flags, strings, resource mode, rectangle clipping, canonical m_mapWidth/m_mapHeight/m_tileBuffer fields, six-byte MapPaneTileRecord updates, redraw/static-object/deferred-surface refresh behavior, and preserved malformed-packet trust semantics." | Preserve the complete quoted row and append only the corrected waiting gate. |
| UID0002AZ | `87/90` | `84%`: "One-byte MapPane render cache flag initialized to 0xff; live IDA confirms the compare/store refs, config-byte dependency, refresh/invalidation path, ignored tail bytes, and MessageShowPane/MemoryMan boundaries." | Raise only the stale manual completion to current `87%`, preserve every quoted fact, and add exact UID0004QY cache-transition linkage. |
| UID00042K MapPaneLayout | `84/87` | `84%`: "Focused MapPane layout support with canonical dimensions/tile/origin/object-list fields plus exact interaction timer +0x3f1, transition/weather +0x40c/+0x40d/+0x410/+0x414, map-flash color +0x4c8, and visible-object-refresh-pending +0x4cd roles; broader field ledger and no standalone class emission remain preserved." | Preserve every current UID00037X field-role fact and union the accepted UID00037V fields at `84%`. |
- Historical exact supervisor-owned parent and child insertion handoff text, now applied:
        - [UID:00037V][0x00509470-0x0050a4fd.MapPaneRenderViewCore](by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md) 0x00509470-0x0050a4fd | split index | MapPaneRenderViewCore : not reconstructable : 92% : very strong : Non-emitting mixed MapPane render index over exact GetCurrentMapId and RenderMapView source children, one proven cross-owner compiler-shared music tail, two internal alignment spans, exact successor boundary, cumulative nesting, and complete source/no-source disposition.
            - [UID:0004QW][0x00509470-0x00509478.MapPaneGetCurrentMapId](by-memory/0x00509470-0x00509478.MapPaneGetCurrentMapId.md) 0x00509470-0x00509478 | method | MapPaneGetCurrentMapId : reconstructable : 92% : very strong : Source-ready eight-byte MapPane current-map-id getter over m_mapId +0x3f2 with six direct consumers, exact bytes/hash, one-block ABI, source route, and complete formal body.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00509478-0x00509480 | padding | MapPane getter alignment : ignored : 100% : strong : Eight 0xcc compiler/linker alignment bytes between GetCurrentMapId and the shared music playback tail.
            - [UID:0004QX][0x00509480-0x005094ae.SharedMusicPlaybackTail](by-memory/0x00509480-0x005094ae.SharedMusicPlaybackTail.md) 0x00509480-0x005094ae | compiler-shared tail | SharedMusicPlaybackTail : not reconstructable : 92% : very strong : Non-emitting compiler-folded suffix shared by MusicControlDialog ApplyPlaybackState and SoundManager audio reinitialization; exact two incoming contexts, config gate, PlayMusicByZone arguments, shared return, and canonical complete-method source placement reject an invented standalone helper.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005094ae-0x005094b0 | padding | MapPane render alignment : ignored : 100% : strong : Two 0xcc compiler/linker alignment bytes between the shared music tail and RenderMapView.
            - [UID:0004QY][0x005094b0-0x0050a4fd.MapPaneRenderMapView](by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md) 0x005094b0-0x0050a4fd | method | MapPaneRenderMapView : reconstructable : 92% : very strong : Source-ready MapPane render method with exact paint callers, 191-block/39-callee profile, flash/waiting/blindness gates, shadow/palette/light overlay, cached surface, ObjectList pass ordering, static/effect split, overlays, final clip query, compiler exclusions, and complete human C++.
- Historical exact class replacement handoff text, now applied:
  - [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 89% : very-strong : Live game-world pane class with blank broad class formal and child-only source emission; UID00037X is a non-emitting seven-child interaction/map-change split with seven source-ready methods, exact packet/object-list/target/global/weather/flash/refresh fields, switch-table/padding evidence, missing-route liveness caps, and load/save/draw ordering; UID00037V is a non-emitting mixed render split with source-ready GetCurrentMapId and RenderMapView children, a proven compiler-shared cross-owner music tail, corrected waiting/local-status and overlay semantics, exact ObjectList pass order, cumulative nesting, and compiler exclusions.
  - [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 92% : very-strong : Complete 0x13eb84 local-player UserPane declaration with exact movement/packet/server inventory, external ProcessMovement and event helper declarations, corrected viewport half/remaining column/row fields, movement-history records, corrected opcode-0x13 movement-target sender, MapPane friendship, action mode, exact +0x13eb3e adjacent-target bool split, m_playerSettingsState[4] as the MapPane-render-consumed blindness level whose change invalidates movement bounds, and preserved full field/record/size-guard layout surface.
  - [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md) : reconstructable : 85% : strong : EffectObjectPane class support with exact public m_effectId at +0x148, looping/timer behavior, primary/secondary LivingObjectPane list registration and duplicate-key evidence, and +0x14d resolved as the MapPane late/after-living secondary-effect render selector; the broader class declaration remains intentionally withheld pending independent constructor/layout closure.
  - [UID:00005V][GrafPort](by-class/GrafPort.md) : reconstructable : 88% : very strong : Core graphics-port class with exact surface/clip/draw/text children; UID00016E is a non-emitting mixed physical index whose exact rect-based outlined and duplicate-offset methods emit through GrafPort while UID00016F remains independently owned; the 0x004b8dd0 exposed-region copy-out contract is used by MapPane render, and historical caller-biased SaveClipRegion naming is rejected without changing class formal policy.
- Historical exact file replacement handoff text, now applied:
  - [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 89% : very-strong : Major NexusTK/map/MapPane.cpp source root with source-ready compressed-map load/save, interaction/map-change/coordinate/movement families, shared MapPoint declaration ownership, external DirectionToTileOffset linkage and cross-source consumers, and UID00037X's seven exact definitions including route-negative FlashMapColor and FinishVisibleObjectRefresh; preserves the selected-target external declaration, ObjectList lifecycle, packet/timer/global/weather/render dependencies, exact switch-table handling and source order, and compiler-artifact exclusions. UID00037V adds exact GetCurrentMapId/RenderMapView source order, `+0x3f0` inferred m_waitingForLocalPlayerStatus constructor/transition-set, local-status-clear, and render/weather not-ready lifecycle, exact ObjectList pass order, cross-owner compiler-tail exclusion, internal padding, and cumulative nesting.
  - [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 91% : very-strong : NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families, exact ProcessMovement direction/effect/packet/history/event behavior, retained waypoint/facing inline-equivalent helpers, corrected helper declarations, and corrected opcode-0x13 movement-target sender using MapPane collect/sort with exact count-versus-nine cap/local terminator behavior; preserves action/adjacent-target fields, packet ABI, movement-history, server, target, and caller evidence, and adds m_playerSettingsState[4] as the MapPane-render blindness level whose change invalidates movement bounds.
  - [UID:0000IZ][Effects](by-file/Effects.md) : reconstructable : 90% : strong : Runtime effecter module with class inventory, vtable family, small-constructor caveats, EffectObjectPane relationship, asset-library separation, global alias correction, open split questions, endpoint/range changes, effect-id/looping evidence, and +0x14d resolved as the MapPane late/after-living secondary-effect render selector.
  - [UID:0000JR][GrafPort](by-file/GrafPort.md) : reconstructable : 89% : strong : Render source family for GrafPort surface, clipping, drawing, glyph, wrapped-text, and exact rect text-effect methods; mixed UID00016E emits only through its two GrafPort children and excludes UID00016F/UID0003ZP source ownership; the 0x004b8dd0 exposed-region copy-out contract and MapPane render consumers preserve existing child/source ownership.
- Historical exact UID0003UL replacement handoff text, now applied:
        - [UID:0003UL][0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket](by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md) 0x005aa480-0x005aa702 | UserPane member | UserPaneParsePlayerSettingsPacket : reconstructable : 86% : strong : Complete source-ready UserPane settings parser with exact optional offsets, action/movement/config behavior, and m_playerSettingsState[4] corrected from superseded speed wording to the MapPane-render blindness level whose change invalidates map bounds.
- Historical exact UID0003TL replacement handoff text, now applied:
        - [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md) 0x00510960-0x00511347 | packet method | MapPaneHandleMapInfoTileRegionPacket : reconstructable : 90% : very strong : Complete source-ready opcode-0x06 map-info/tile-region parser with exact flags, strings, resource mode, rectangle clipping, canonical m_mapWidth/m_mapHeight/m_tileBuffer fields, six-byte MapPaneTileRecord updates, redraw/static-object/deferred-surface refresh behavior, preserved malformed-packet trust semantics, and corrected m_waitingForLocalPlayerStatus gate semantics.
- Historical exact UID0002AZ replacement handoff text, now applied:
    - [UID:0002AZ][0x0069b4f8-0x0069b4f9.MapPaneRenderScratchFlag](by-memory/0x0069b4f8-0x0069b4f9.MapPaneRenderScratchFlag.md) 0x0069b4f8-0x0069b4f9 | global-data flag | MapPaneRenderScratchFlag : reconstructable : 87% : strong : One-byte MapPane render cache flag initialized to 0xff; exact UID0004QY RenderMapView compare/store synchronizes the RegistryConfig shadow option with palette-filter-table and visible-tile refresh, while live IDA refs, ignored tail bytes, and neighboring MessageShowPane/MemoryMan boundaries remain preserved.
- Historical exact UID00042K replacement handoff text, now applied:
  - [UID:00042K][MapPaneLayout](by-type/by-struct/MapPaneLayout.md) : reconstructable : 84% : strong : Focused MapPane layout support with canonical dimensions/tile/origin/object-list fields plus interaction timer +0x3f1, day/night target brightness +0x3dc, AlphaMaskSurface shadow/light overlay +0x3e0, waiting-for-local-player-status gate +0x3f0, map id +0x3f2, local player +0x418, ObjectList +0x424, viewport GrafPort +0x428, transition/weather +0x40c/+0x40d/+0x410/+0x414, map-flash color +0x4c8, and visible-object-refresh-pending +0x4cd; the broader field ledger and no-standalone-class-emission status remain preserved.
### Current Applied Manual State

- Exact report SHA `1920BE9767B0D0D31E5803BF3CAFA2F43736DEC88EF36DFD6D6B9B90948963D6` passed supervisor Gate 1 at `2026-07-15T02:10:14-04:00`. The supervisor then applied the historical handoff above and validated each coverage file. These command results and hashes record application-time state:

| Supervisor command | Timestamp (America/New_York) | Manual coverage path | Exit / ok | Application-time SHA-256 |
| --- | --- | --- | --- | --- |
| `000000012700` | `2026-07-15T02:13:14-04:00` | `by-memory/-coverage-report.md` | `0 / 1` | `77F4D8E8F739E57DC1C77A07BDB1B74E7B59048D818BDD5CAAA55B586DA4CCCF` |
| `000000012701` | `2026-07-15T02:13:25-04:00` | `by-class/-coverage-report.md` | `0 / 1` | `1CB76096DB7DB060E24D850651191266E6A8416AB52DE512E0E904143B851546` |
| `000000012702` | `2026-07-15T02:13:31-04:00` | `by-file/-coverage-report.md` | `0 / 1` | `D147BED6B6EDDC99893CF6237A57412C9A60059B48160017B393F7C25D070DAB` |
| `000000012703` | `2026-07-15T02:13:39-04:00` | `by-type/by-struct/-coverage-report.md` | `0 / 1` | `1414B291EE244470D06E623DA8D7C43C4F5FA47339C0991AB8FC3C2059AF2F56` |

Later unrelated supervisor-owned B003 UID00019H and B004 UID0003U7 coverage work added no-loss content to the manual corpus after commands `000000012700`-`000000012703`. The direct UID00019H and UID0003U7 rows are present in the current memory coverage file; associated concurrent coverage work advanced the memory/class/file whole-file hashes without altering any B005 row. The following hashes are current:

| Current manual coverage path | Current SHA-256 | B005 row status |
| --- | --- | --- |
| `by-memory/-coverage-report.md` | `96546FE73C04070B835DA2C2656092D3E40E77B3CBAE29A7C803C23B0BEF8990` | Nine B005 rows exact; later UID00019H/UID0003U7 content preserved as unrelated supervisor-owned additions. |
| `by-class/-coverage-report.md` | `A16263EA62D0FC4C663E81E1027B60CA69E18A9B8D05D9960C334950884C0B4E` | Four B005 no-loss unions exact; later unrelated supervisor-owned additions preserved. |
| `by-file/-coverage-report.md` | `943D7A88E156A5FE1EEEC2C3AC0A305B961C0DF40F9814A5BF8B284096D93BF1` | Four B005 no-loss unions exact; later unrelated supervisor-owned additions preserved. |
| `by-type/by-struct/-coverage-report.md` | `1414B291EE244470D06E623DA8D7C43C4F5FA47339C0991AB8FC3C2059AF2F56` | One B005 no-loss union exact; whole-file hash unchanged from command `000000012703`. |

- Current `by-memory/-coverage-report.md` lines 2236-2241 contain all six exact parent/getter/padding/shared-tail/padding/render insertions. Lines 2258, 3242, and 3974 contain the accepted UID0003TL, UID0003UL, and UID0002AZ replacements.
- Current `by-class/-coverage-report.md` lines 178, 236, 302, and 586 contain the accepted UID000049, UID00005V, UID00007Q, and UID0000FQ no-loss unions.
- Current `by-file/-coverage-report.md` lines 80, 108, 156, and 297 contain the accepted UID0000IZ, UID0000JR, UID0000L3, and UID0000P1 no-loss unions.
- Current `by-type/by-struct/-coverage-report.md` line 70 contains the accepted UID00042K union. A read-only line-normalized comparison finds all 18 historical handoff rows present exactly, so all six insertions and 12 replacements are present at accepted same-or-greater detail, including the complete B001+B005 UID0000FQ/UID0000L3/UID0000P1 unions.
- UID00037W still has no manual row and needs no standalone insertion from this callback. Existing UID0001AV, UID0003TK, MusicControlDialog, SoundManager, ObjectList, ObjectPane, LivingObjectPane, StaticObjectPane, PaletteLib, AttachmentAnchor, RegistryConfig, and callback-global rows remain verify-only because this callback changed no score/state/path and their current summaries do not assert the stale token corrected in ordinary prose.
- Manual application is complete and supervisor-owned. B005 neither edited these coverage files nor ran commands `000000012700`-`000000012703`; this report records their externally completed results.

## Follow-Up Actions

- Completed B005 callback work: serial child registration, C01-C35, Destinations 1-6, shared-support rebasing, one-file lease/validation/release, and final waited generated refresh are all recorded in this artifact.
- Completed generated proof: no UID00037V parent marker/body, no UID0004QX shared-tail marker/body, exactly one getter and one `RenderMapView` definition in address/source order, no invented standalone shared helper, and no handwritten EH/cookie/vptr/callback lowering.
- No B005 implementation item remains, and supervisor-owned manual coverage application is complete. Fresh exact-artifact Gate 1, independent Gate 2, report execution, movement, and archival remain pending external supervisor-owned lifecycle work.

## Confidence

- Boundaries/hashes/padding: very strong (`94`).
- Getter owner/ABI/body/callers: very strong (`94`).
- Shared-tail compiler/no-independent-source disposition: very strong (`94`).
- Main receiver/caller/behavior/order/source route: very strong (`93`).
- Exact private original field/helper spellings: strong; inferred names are documented and cap confidence.
- Overall recommendation: material and implementation-ready.

## Validator Results

- Historical Gate 1 fact: the report-only research pass ran no validator and acquired no ordinary-file lease. The separately authorized callback then used one short lease per active ordinary page, reread after acquisition, scoped-validated, and immediately released it.

| Command ID | Timestamp (America/New_York) | Scoped path / purpose | Exit / ok | Result, warnings, and validator-owned side effects |
| --- | --- | --- | --- | --- |
| `000000012479` | `2026-07-14T23:08:51-04:00` | `by-memory/0x00509470-0x00509478.MapPaneGetCurrentMapId.md` serial registration | `0 / 1` | Passed; issued real UID0004QW and refreshed validator-owned registry/generated metadata. |
| `000000012483` | `2026-07-14T23:10:46-04:00` | `by-memory/0x00509480-0x005094ae.SharedMusicPlaybackTail.md` serial registration | `0 / 1` | Passed; issued real UID0004QX and normalized supplied support references. |
| `000000012485` | `2026-07-14T23:12:11-04:00` | UID0004QX final support-reference correction | `0 / 1` | Passed with final references UID0001IA/UID0000LN/UID0000DG; blank formal and no-source disposition unchanged. |
| `000000012494` | `2026-07-14T23:16:45-04:00` | `by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md` serial registration | `0 / 1` | Passed; issued real UID0004QY. Warning that then-unregistered existing UID00037W was absent from validator state was resolved by command `000000012503`. |
| `000000012499` | `2026-07-14T23:19:01-04:00` | UID00037V split parent | `0 / 1` | Passed exact `92/94`, owner-none, non-emitting, blank-formal, `Nested:-4` state. |
| `000000012501` | `2026-07-14T23:19:45-04:00` | `by-memory/-ignored.md` | `0 / 1` | Passed both exact internal `cc` spans; reported 285 unrelated/preexisting missing-reference warnings without target failure. |
| `000000012503` | `2026-07-14T23:20:14-04:00` | UID00037W nesting closure | `0 / 1` | Passed and registered the existing page in validator state; metadata/formal stayed unchanged. |
| `000000012504` | `2026-07-14T23:21:04-04:00` | UID0001AV cumulative nesting | `0 / 1` | Passed; complete existing SaveUserSettings source remained unchanged. |
| `000000012505` | `2026-07-14T23:22:12-04:00` | `by-class/MapPane.md` | `0 / 1` | Passed accepted render/state inventory; unrelated existing missing-reference warnings were non-target and the class formal/score stayed unchanged. |
| `000000012506` | `2026-07-14T23:23:11-04:00` | `by-file/MapPane.md` | `0 / 1` | Passed exact source order/shared-tail exclusion/history; unrelated existing missing-reference warning only. |
| `000000012507` | `2026-07-14T23:23:58-04:00` | `by-type/by-struct/MapPaneLayout.md` | `0 / 1` | Passed exact field-role synchronization with score/formal unchanged. |
| `000000012508` | `2026-07-14T23:24:56-04:00` | UID0003UL Destination 5 | `0 / 1` | Passed exact two-token `oldBlindnessLevel` correction with every other formal line preserved. |
| `000000012509` | `2026-07-14T23:25:53-04:00` | `by-class/UserPane.md` | `0 / 1` | Passed blindness support after reread/rebase; B001's complete class/concurrent union was preserved. Existing missing-reference warnings were unrelated. |
| `000000012510` | `2026-07-14T23:26:26-04:00` | `by-file/UserPane.md` | `0 / 1` | Passed blindness source support after reread/rebase; B001's concurrent content was preserved. Existing missing-reference warnings were unrelated. |
| `000000012511` | `2026-07-14T23:27:09-04:00` | UID0003TL Destination 6 | `0 / 1` | Passed exact field-token correction with all other formal content preserved. |
| `000000012512` | `2026-07-14T23:27:41-04:00` | UID0003TK producer/state prose | `0 / 1` | Passed; metadata and formal remained unchanged. |
| `000000012513` | `2026-07-14T23:28:21-04:00` | `by-class/EffectObjectPane.md` | `0 / 1` | Passed bounded `+0x14d` role; unresolved adjacent bytes and formal/score remained unchanged. |
| `000000012514` | `2026-07-14T23:29:04-04:00` | `by-file/Effects.md` | `0 / 1` | Passed bounded source-route/history support; score/formal policy unchanged. |
| `000000012515` | `2026-07-14T23:29:45-04:00` | `by-class/GrafPort.md` | `0 / 1` | Passed exposed-region copy-out contract and rejected-name history; no new class formal or score change. |
| `000000012516` | `2026-07-14T23:30:25-04:00` | `by-file/GrafPort.md` | `0 / 1` | Passed exact 19-byte/30-xref/nine-function source inventory; path/score unchanged. |
| `000000012517` | `2026-07-14T23:31:04-04:00` | UID0002AZ scratch global | `0 / 1` | Passed exact UID0004QY linkage and shadow-option cache-transition order; score/formal unchanged. |
| `000000012518` | `2026-07-14T23:31:39-04:00` | UID00037V final authorized `--wait-generated` refresh | `0 / 1` | Passed; foreground generated refresh completed. Validator-owned side effects rebuilt 4,949 registry nodes/3,991 edges and refreshed 281 generated metadata artifacts; global diagnostics were 14 fallback children, 86 missing markers, and 171 emitter-no-code entries, with no target-specific failure. |
| `000000012622` | `2026-07-15T00:44:23-04:00` | `by-file/MapPane.md` bounded C11 repair | `0 / 1` | Passed complete `+0x3f0` file-level lifecycle at preserved `89/85`; 67 existing missing-reference diagnostics were non-target, projected stats refreshed, and validator-owned generated refresh completed after initial deferral. |
| `000000012700` | `2026-07-15T02:13:14-04:00` | Supervisor-owned `by-memory/-coverage-report.md` application validation | `0 / 1` | Passed all six exact insertions plus UID0003TL/UID0003UL/UID0002AZ replacements; B005 did not run this command. Application-time SHA-256 was `77F4D8E8F739E57DC1C77A07BDB1B74E7B59048D818BDD5CAAA55B586DA4CCCF`. |
| `000000012701` | `2026-07-15T02:13:25-04:00` | Supervisor-owned `by-class/-coverage-report.md` application validation | `0 / 1` | Passed all four no-loss class unions; B005 did not run this command. Application-time SHA-256 was `1CB76096DB7DB060E24D850651191266E6A8416AB52DE512E0E904143B851546`. |
| `000000012702` | `2026-07-15T02:13:31-04:00` | Supervisor-owned `by-file/-coverage-report.md` application validation | `0 / 1` | Passed all four no-loss file unions; B005 did not run this command. Application-time SHA-256 was `D147BED6B6EDDC99893CF6237A57412C9A60059B48160017B393F7C25D070DAB`. |
| `000000012703` | `2026-07-15T02:13:39-04:00` | Supervisor-owned `by-type/by-struct/-coverage-report.md` application validation | `0 / 1` | Passed the UID00042K no-loss union; B005 did not run this command. Application-time SHA-256 was `1414B291EE244470D06E623DA8D7C43C4F5FA47339C0991AB8FC3C2059AF2F56`. |

- B005's original waited readback used command `000000012518`, and bounded C11 repair command `000000012622` refreshed MapPane output. Later external command `000000012664`, refresh `2026-07-15T01:25:07-04:00`, MapPane SHA-256 `1620222603EC9E9BCF4097C4EDD1E93242F6BFF1E0E8990C28A30E8F906637FF`; supervisor-supplied external command `000000012692`, refresh `2026-07-15T01:41:46-04:00`, MapPane SHA-256 `9A7F2FFE961E315FB4BB6719F55C7180769CD4222245F78253BB9AE36107497A`; and transient external command `000000012696`, refresh `2026-07-15T01:51:51-04:00`, MapPane SHA-256 `87729DF4FDB19D1EC19CEF9EAA0F3D7D3CB83EBAFB04F75A5DE66660F7AF4620`, are retained as historical external snapshot evidence. Current validator-owned `auto-generated/NexusTK/map/MapPane.cpp` is full external refresh command `000000012699`, refresh `2026-07-15T01:54:32-04:00`, SHA-256 `1DBEA0BAAEA313EE54737C5D9D75AAB18BFCE2680DB9CEE8D9F7D08D0C783B94`; every target assertion remains retained.
- Exact current MapPane.cpp assertions after external command `000000012699`: one `UID:0004QW` marker and one `MapPane::GetCurrentMapId() const` definition; one `UID:0004QY` marker and one `MapPane::RenderMapView()` definition; getter precedes render; zero `UID:00037V` and `UID:0004QX` markers; zero `m_hasRenderableMap`; two `m_waitingForLocalPlayerStatus` uses; zero `__thiscall`, `__cdecl`, `security_cookie`, `CxxFrame`, `vptr`, or placeholder spellings.
- Historical external command `000000012664` support hashes were UserPane `4165B1D63EB9BE7C96327B0397C675AD69E2D00FF563EE839E88179389885402`, MusicControlDialog `4EF6BDD8BBEDC6F9940A8AEADADB49BA9A51E28335B6340C970E29E50C11B10C`, and SoundManager `831A3CC2C3636D20DF33BD91BECB3448D3A480423526111550D3D81515F35FF2`. Supervisor-supplied external command `000000012692` then produced UserPane SHA-256 `4483C82041930CB3DD56FEAFF06BC19C54113ABA4170F9E0443ADC548CA3E30C`; transient unrelated commands `000000012694` and `000000012695` produced UserPane SHA-256 values `E1EEF30F837E3022B50DBDBE78903CDFCCBCDEF3BEF0A0177562A70C4176CE0D` and `10B58891BBE362EA8E01456503F13617C6740C31462CA53328CEC4E269F47E8B`. Current external full-refresh command `000000012699`, refresh `2026-07-15T01:54:32-04:00`, produces UserPane SHA-256 `DDE87CCDC7700348665C170FF768C18909CF4636125EF77B46E3152AA3856EEA` with two `oldBlindnessLevel` uses and zero `oldSpeed`; MusicControlDialog SHA-256 `AFDCD7341393E715DEDBA78ED8B13BE8D4EB9675B148346DC964678E25588FB8` with independent `ApplyPlaybackState`/`PlayMusicByZone`; and SoundManager SHA-256 `EE2CDC46896B0EA3D33685C22BFF63C33755E17B0E47A564F38EC3F28A940908` with no invented UID0004QX helper.
- All six report destination blocks were mechanically compared with their installed managed blocks after generation: six of six were byte-for-byte equal. No brace UID token remains.
- `tools/leaser/Agents/current_leases.md` contained no B005 row after the final release. B005 manually edited no coverage, generated C++, tracker, audit, supervisor, or lifecycle file and ran no `execute_report`/probe/move/archive command. The supervisor separately applied manual coverage and ran commands `000000012700`-`000000012703` after Gate 1.
- Historical first Gate 2 rebase required no ordinary mutation. The later bounded C11 repair changed only `by-file/MapPane.md`, under one short lease, passed scoped validator `000000012622`, and released the lease immediately before report reconciliation.
- Successive B005 Gate 1 state rebases ran no validator and acquired no lease. Historical generated-state passes recorded unrelated UID000373, UID0004R1, and B004 UID0002Q3 NewUserDialogPane additions while confirming both accepted MapPane alignment entries and successor padding remained exact. The pre-application Rule 26 handoff pass reread all four manual coverage files and all 18 proposed rows without mutation. After that artifact passed Gate 1, the supervisor applied and validated all rows through commands `000000012700`-`000000012703`; those commands and hashes remain application-time evidence. The current B005 read-only rebase records current memory/class/file/type hashes `96546FE73C04070B835DA2C2656092D3E40E77B3CBAE29A7C803C23B0BEF8990` / `A16263EA62D0FC4C663E81E1027B60CA69E18A9B8D05D9960C334950884C0B4E` / `943D7A88E156A5FE1EEEC2C3AC0A305B961C0DF40F9814A5BF8B284096D93BF1` / `1414B291EE244470D06E623DA8D7C43C4F5FA47339C0991AB8FC3C2059AF2F56`, classifies later B003 UID00019H and B004 UID0003U7 additions as unrelated supervisor-owned no-loss content, and verifies all 18 B005 rows exactly. All 20 recorded ordinary hashes match; mechanical recheck also passes all six formal equalities, C01-C35 terminal states with zero blocked claims, the existing 39 checked/zero unchecked checklist rows, all 33 literal headings, zero brace UID placeholders, preserved external-command-`000000012699` target/support generated assertions, and zero B005 leases.

## Changed Files

- Callback artifact updated in place: `tools/leaser/Agents/Agent-B005/research/00037V-MapPaneRenderViewCore-source-quality.md`; its exact current SHA-256 is reported externally after the final write because a file cannot contain its own stable hash.
- Exact current ordinary-file hashes from the bounded Gate 1 read-only comparison. These are revision evidence, not a claim that unrelated concurrent pages can never change:

| Changed ordinary path | Current read-only SHA-256 |
| --- | --- |
| `by-memory/0x00509470-0x00509478.MapPaneGetCurrentMapId.md` | `179E3FD9D1E2400DD3011437C33FD8D4430CA6CFBAF2D771D445D9E64299F98E` |
| `by-memory/0x00509480-0x005094ae.SharedMusicPlaybackTail.md` | `580B1A330B7BEFA24E7D771372319DA77DE5850947F2779EC6D67552FB45156E` |
| `by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md` | `CB3AB04B2CB9719C2346753940A3E41847D84ECA270D89B37A6F18C417293A99` |
| `by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md` | `2552BC2C93557A37CEC214DE8395C40946E22EF0D2AAAFA574DBC4B6D80F98E2` |
| `by-memory/-ignored.md` | `59D3B77357D6D7B58367A6E26768608E0915B692568B06F64ED6F7599DF49232` |
| `by-memory/0x0050a500-0x0050ab95.MapPanePaintLightingCore.md` | `B7F4A15485A9EB413EC84B4C8FD139539DD840381EB73A4AE74F287602C4FBE1` |
| `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | `4ECF7E8491D6209A2190BEA66C81A8C9FD8ADF0A4C3070DC728F501859B45C98` |
| `by-class/MapPane.md` | `3F148E8D208D8E49BC0AC29A4E09A2A5C7708F7308F80EB529E145B79E5218F9` |
| `by-file/MapPane.md` | `2E7908E81F5B4B411C55EE17403EE434AA964DE503C3A1180F21722B70C0C1B8` |
| `by-type/by-struct/MapPaneLayout.md` | `488E268D0F04C1B18D33EC384C1EB9725EC9629A225EEAFD911A807162CE1F09` |
| `by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md` | `72F729F6F586F6334B313DD3D71F0D28754C0893968D764801A188C8D2654997` |
| `by-class/UserPane.md` | `4D456A312DF68B1C8E3F24EC7F8066EC20C937B5089E64463DC126AF2147DA0E` |
| `by-file/UserPane.md` | `2DD547743B396369F0B1A6ADB7176AEA9DC9C680CB06CE1F24287AF8CEDD480F` |
| `by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md` | `A4DC4C2FB52FEBF4E52B9204C27625F7F64B815B6127561ED8410E1D394D0E9E` |
| `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md` | `CE1FDBA949E84DFBE66FDB6616104F02E751A1C71B1B499894B7B0D2C1AACF9F` |
| `by-class/EffectObjectPane.md` | `9B2E69B6F62F4F52B19F7585D37644F2CC753A7716C883B308F8D7691827435E` |
| `by-file/Effects.md` | `C2E3CA055A9F63FE423D39333EC5337AC6C49F25BF4F97453429565EF38BD71C` |
| `by-class/GrafPort.md` | `0893FC10F8334191D36971E16E5A8007AE4C37FAC0F1E5305CC299B99DD00ABF` |
| `by-file/GrafPort.md` | `023D925CE53BC73EEDEF5470E530C15D3DC688CCD165A156ECF5AB01EDBB2CF0` |
| `by-memory/0x0069b4f8-0x0069b4f9.MapPaneRenderScratchFlag.md` | `0B49693786C51004451A22EDD32DEFDA3851D8F1202094D8D11491D2DC0B3EC5` |

- Verify-only/no ordinary edit: MusicControlDialog UID0003MK/class/file; SoundManager scan/class/file and audio-reinit context; ObjectList/ObjectPane/LivingObjectPane/StaticObjectPane; AttachmentAnchor; PaletteLib; RegistryConfig; callback globals; the preexisting successor postpad.
- Validator-owned side effects from B005's callback were child UID registry entries, generated metadata/C++, and validator state refreshed through the listed callback commands. The supervisor later applied the 18 B005 manual rows and validated their application through `000000012700`-`000000012703`; those command hashes are application-time evidence. Still later unrelated supervisor-owned B003 UID00019H and B004 UID0003U7 coverage additions advanced the current memory/class/file whole-file hashes while preserving all B005 rows. B005 did not edit those files or any tracker/audit/supervisor/lifecycle state.
- IDA changed: none. Report executed/moved/archived: no.
- First Gate 2 rebase changed no ordinary page. This subsequent C11 repair changed only `by-file/MapPane.md` plus this same report; `by-class/UserPane.md` and `by-file/UserPane.md` remain the accepted concurrent rebases, and no other ordinary destination changed.
- B005's Gate 1 report-text rebases changed no ordinary or restricted file. UID000373, UID0004R1, and B004 UID0002Q3 NewUserDialogPane ignored-page additions remain preserved historical unrelated drift, both MapPane entries remain exact, and all 20 current recorded ordinary hashes match. The historical generated-state rebase recorded external full-refresh command `000000012699` and its four generated hashes/assertions. The supervisor-owned manual application changed `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-type/by-struct/-coverage-report.md` to the application-time hashes recorded with commands `000000012700`-`000000012703`; later B003 UID00019H and B004 UID0003U7 additions advanced only the current manual corpus state and remain unrelated no-loss content. Current hashes are memory `96546FE73C04070B835DA2C2656092D3E40E77B3CBAE29A7C803C23B0BEF8990`, class `A16263EA62D0FC4C663E81E1027B60CA69E18A9B8D05D9960C334950884C0B4E`, file `943D7A88E156A5FE1EEEC2C3AC0A305B961C0DF40F9814A5BF8B284096D93BF1`, and type `1414B291EE244470D06E623DA8D7C43C4F5FA47339C0991AB8FC3C2059AF2F56`. This latest B005 bounded state rebase changes only this report; B005 did not edit coverage/generated output, edit/validate/lease an ordinary page, or run a lifecycle operation.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact report SHA `6C1DF9BF6C811906FC0F2F4D1C5D0040167C27D5EAC8C21A9B56B3DB1277542C` before implementation.
- [x] C01-C02 applied to UID00037V with exact `92/94`, owner-none false/blank split index, Item Summary, evidence, and `Nested:-4`.
- [x] Getter child registered first as UID0004QW; the real validator UID replaced its placeholder everywhere before later references.
- [x] Shared-tail child registered second as UID0004QX; the real validator UID replaced its placeholder everywhere before later references.
- [x] Render child registered third as UID0004QY; its validator-issued UID replaced the final placeholder everywhere before later references.
- [x] Destinations 1-4 applied exactly with parent/tail blank and getter/render source-bearing.
- [x] Complete bytes/hashes/CFG/EH/xref/caller/callee/field/render-order/compiler/history evidence preserved without compression.
- [x] UID00037W and UID0001AV cumulative nesting corrections applied with all unrelated source content preserved.
- [x] Two internal ignored spans added without duplicating the existing postpad.
- [x] UID00007Q, UID0000L3, and UID00042K synchronized at unchanged scores/formal routes.
- [x] Destination 5 applied to UID0003UL; UserPane class/file prose historicalizes old speed wording.
- [x] Destination 6 applied to UID0003TL; UID0003TK producer/state prose synchronized.
- [x] EffectObjectPane class/file `+0x14d` role synchronized at unchanged scores/formals.
- [x] GrafPort class/file exposed-region getter contract synchronized at unchanged scores/formals.
- [x] UID0002AZ and named stable dependencies verified or bounded-synchronized exactly as recommended.
- [x] All negative evidence, rejected alternatives, raw-liveness, shared-tail, source-placement, and lexical caps preserved.
- [x] Exactly six managed destination blocks remain and all draft/example C++ is confined to them.
- [x] Exact supervisor-owned coverage handoff text remains as historical evidence; the supervisor applied all 18 rows through commands `000000012700`-`000000012703`, those hashes are classified as application-time evidence, current memory/class/file/type hashes are rebased, later B003 UID00019H and B004 UID0003U7 additions are preserved as unrelated no-loss content, all 18 B005 rows remain exact, and B005 edited no coverage/tracker file.

Implementation callback pass:
- [x] Explicit supervisor implementation callback received for exact Gate 1 SHA `6C1DF9BF6C811906FC0F2F4D1C5D0040167C27D5EAC8C21A9B56B3DB1277542C`.
- [x] Each changed ordinary page was leased alone, reread after acquisition, scoped-validated, and released immediately.
- [x] Every C01-C35 row uses a legal callback state with destination-specific proof.
- [x] All three real child UIDs are recorded and no brace token remains.
- [x] One scoped validator result per changed ordinary page is recorded with command ID, timestamp, exit/ok, warnings, and side effects; UID0004QX and the parent also have explicit final rechecks.
- [x] Final authorized waited generated refresh `000000012518` is recorded.
- [x] Generated MapPane.cpp has no parent/tail body or marker and exactly one getter and RenderMapView definition in order.
- [x] Generated output preserves the accepted MusicControlDialog/SoundManager source disposition and contains no handwritten ABI/compiler mechanics.
- [x] Changed/verify-only paths, hashes, generated assertions, and every lease release are recorded.
- [x] No B005 manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle edit and no execute_report/probe/move/archive operation occurred; supervisor-owned coverage application is recorded separately.
- [x] Report is reconciled to durable callback and manual-application truth for fresh exact-artifact Gate 1; independent Gate 2 remains pending.

Gate 2 rebase repair:
- [x] Rejected SHA `721476F2DBBB1B1BB3ACB3D332125B222F658B285AE3B59E8F417E5B60115204` was repaired in this same report rather than rewritten.
- [x] `by-file/MapPane.md`, `by-class/UserPane.md`, and `by-file/UserPane.md` were reread after relevant leases were clear; all accepted B005 facts remain at same-or-greater detail, so no ordinary edit/validator was needed.
- [x] Historical pre-application audit covered all 18 manual rows: six absent insertions and 12 existing replacements; the supervisor applied and validated all 18 at commands `000000012700`-`000000012703`, and current readback at the rebased four hashes finds them exact at accepted same-or-greater detail after unrelated B003 UID00019H and B004 UID0003U7 additions.
- [x] Current UID0000FQ, UID0000L3, and UID0000P1 manual rows retain complete ProcessMovement/viewport/helper/history/MapPoint/DirectionToTileOffset/coordinate/movement/source-order evidence plus accepted blindness/render/split/shared-tail/waiting-state facts; UID000049 is `85%`, Effects is `90%`, and UID0002AZ is `87%` without detail loss.
- [x] Current generated hashes/assertions are refreshed read-only for all four outputs at external full-refresh command `000000012699`; commands `000000012664`, the supervisor-supplied `000000012692` snapshot, and transient per-file commands remain historical evidence.
- [x] All six destination blocks remain byte-for-byte equal, no placeholder exists, and no B005 lease remains.

Bounded C11 Gate 2 repair:
- [x] Added exact UID0000L3 `MapPane+0x3f0` inferred name, constructor/map-effect transition set routes, `CreateOrUpdateObjectPane` clear route, render/weather early-out and visible-bounds suppression semantics, and stripped-symbol confidence cap.
- [x] Preserved all concurrent MapPane file content, score `89/85`, source route, UID00037V/UID00037X inventories, and unrelated evidence.
- [x] Scoped validator `000000012622` passed at `2026-07-15T00:44:23-04:00` with exit `0`, `ok:1`; lease was released immediately.
- [x] Generated MapPane.cpp current external command `000000012699` header/hash/assertions, C11/C26 proof, 20/20 ordinary hashes, current state, and checklist were refreshed; all six formal blocks remain exact.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000012713","destination_path":"executed-b-agent-research/B005/00037V-MapPaneRenderViewCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00037V-MapPaneRenderViewCore-source-quality.md","timestamp":"2026-07-15T02:57:28-04:00","uid":"00037V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
