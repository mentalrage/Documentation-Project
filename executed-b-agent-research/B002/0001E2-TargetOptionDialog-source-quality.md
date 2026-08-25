** TARGET-REPORT-UID:0001E2 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001E2 TargetOptionDialog Ownership / Split Research


## Finalized Report / Current Recommendation

- Completed callback disposition: [UID:0001E2] `by-memory/0x00542270-0x0054259f.TargetOptionDialog.md` is a `92/94` non-emitting semantic split index owned by [UID:0000EE] `TargetOptionDialog`. The registered source children are constructor UID0004QS, ordinary destructor UID0004QT, `OnControlCommand` UID0004QU, and raw `SaveTargetOptions` UID0004QV.
- The aggregate retains exact range and semantic inventory while only those four children emit source. Three internal `0xcc` gaps remain compiler/linker alignment. The successor at `0x0054259f` is outside the target and is an adjustor thunk for `CScrollBarBackPane`; later TargetOptionDialog adjustors, scalar deleting destructor UID00038I, and vtable data UID0003C9 remain non-emitting compiler ABI support.
- Destinations 1-11 are applied. Destinations 12-14 were re-read and verified same-or-greater with no concrete drift, so they remain read-only. UID0000EE/UID0000EF declarations and children emit through [UID:0000OG] `TargetOptionDialog` / `NexusTK/ui/dialogs/TargetOptionDialog.cpp` in positions `0/10/50/60/70/80/90`.
- Confidence: very strong for exact ranges, bytes, owner, source file, class sizes, virtual signature, child/config layout, branch/order behavior, and compiler-only boundaries; strong for the inferred private helper spelling `SaveTargetOptions` and exact original declaration style.
- B002 implementation, scoped validators, generated verification, report reconciliation, and lease release are complete. Current or future report path, count, validation, execution, move, archive, and central lifecycle state are external validator/supervisor-owned and are not asserted.

## Supporting Research

- Assignment source: `tools/leaser/Agents/Agent-B002/goal.md`, target [UID:0001E2], queue `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Workflow sources read and applied: project skill `ntk-b-agent-workflow`, `references/b-agent-research-and-implementation-workflow.md`, `references/b-agent-report-template.md`, `references/score-blocker-audit-standard.md`, and relevant ownership/emission/split/formal-C++ rules in `by-structure.md`.
- Evidence-collection-time MCP database: `0cf42e97`, rediscovered through `idb_list` JSON-RPC id `111` on transport session `61514ca9-e434-439b-8579-4f05611605df`. It was the one active/adopted NexusTK IDB at that observation.
- Evidence-collection-time health: `server_health` id `112` returned `status:ok`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, cache size `2067`, and IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Bounded evidence-time target proof: `get_bytes` id `117` returned the expected constructor prologue at `0x00542270` and raw-helper prologue at `0x00542540`; `lookup_funcs` id `114` returned the three modeled method starts, no function at the raw-helper start, and the successor thunk at `0x0054259f`.
- Final pre-hash MCP recheck at evidence time `2026-07-14T22:31:17-04:00`: `idb_list` id `132` again returned `0cf42e97` as the one active/adopted worker; `server_health` id `133` returned `status:ok`, analysis/Hex-Rays/string cache ready; bounded `get_bytes` id `134` returned the same constructor and raw-helper prologues. No fallback evidence was used.
- Binary identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, size `2,679,296`, SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Exact target bytes: all `815` bytes in `[0x00542270,0x0054259f)` were read through MCP id `131`; SHA-256 `CF593357EC169558AF4F4C3D077D027DA8C165B52518EF6DC2C5924CD41264F5`.
- Target/support docs read before and during callback: UID0001E2, UID0000EE, UID0000EF, UID0000OG, UID00011K, UID00038I, UID0003C9, UID00023J, UID00023K, UID0001AV, UID0001VR, UID00003T `DialogPane`, UID000038 `ControlPane`, UID00004G `EPFImageControlPane`, UID00006D `ImageButtonControlPane`, UID00000W `BlackHole`, UID0000BW `RegistryConfig`, UID0000PR `g_activeMapPane`, UID0000Q8 `g_pApplicationCleanupQueue`, UID00028J `g_pBackPane`, UID00029M `MainUiLayerSlotsHead`, UID0000BU `RectBounds`, UID00015S geometry helpers, and generated `TargetOptionDialog.cpp`.
- Historical B002 UID00011K conclusions were revalidated rather than inherited: direct constructor caller, `0x110` object size, `+0x108/+0x10c/+0x10d` layout, ARROW/SHIFT+ARROW semantics, primary/secondary/tertiary vtables, event slots, destructor/scalar/adjustor split, and shared font-helper exclusion still hold. The old blanket blank-C++ conclusion is superseded for the class declaration needed by this target; UID00011K's broad method aggregate remains a separate source-body inventory.
- Executed B005 UID0001AV was independently checked: the accepted writer is a global `void SaveUserSettings()`, uses `RegistryConfig &config = *static_cast<RegistryConfig *>(g_pConfig)`, serializes `m_targetOptionRows[2]` at `+0x2911dc` as the eighth section, and is gated by `g_activeMapPane` at this caller. No dirty flag or `SaveConfig` alias is valid. Because the current by-file roots are prose-only and do not emit header metadata, Destination 4 carries the exact external declaration immediately before the target method definition.
- Executed B005 UID00049K was checked as the accepted sibling precedent for a 31-byte three-vptr-store/base-tail non-deleting destructor: the correct human source body is an explicit empty destructor, while vptr stores and base teardown remain compiler output.
- Executed B001 UID0001E1 and UID00023K were checked for predecessor/successor padding, thunk-island, and scalar-wrapper policy. The target starts after exact predecessor padding and ends exactly at the thunk island.
- Executed B007 UID0000N4 was checked for current `RegistryConfig` declaration/profile field direction and the comment-only `RegistryConfigUserProfileBlock` layout-slice policy.
- Prior-report roots searched read-only with exact terms `TARGET-REPORT-UID:0001E2`, `UID0001E2`, `UID:0001E2`, `0x00542270`, `0x0054259f`, `TargetOptionDialog`, `SaveTargetOptions`, `OnConfirm`, `OnControlCommand`, `UID00011K`, `TargetOptionEditControlPane`, `UID0001AV`, `SaveUserSettings`, `UID0000EE`, `UID0000OG`, `DLGSETUP.EPF`, and `m_targetOptionRows`:
  - Central executed root `executed-b-agent-research/`: no exact `TARGET-REPORT-UID:0001E2` report. Relevant artifacts opened were `B002/00011K-target-option-edit-control-pane-source-quality.md` SHA-256 `47DF9E0FF69337C25BDB88FF508367EAD09C42A9E729F47044ABE7A7D76AED7E`, `B005/0001AV-SaveUserSettings-empty-emitter-source-quality.md` SHA-256 `2375F3BA183C08E3F303E1E003DAB77E0700403C0D5D1A851791DFF6B124D468`, `B005/00049K-NewMacroDialogNonDeletingDestructor-source-quality.md` SHA-256 `3BF6D9BB67D9F9F9B40DE3CFE19D119C5E0BB23C784507C5A041A76063BF11B6`, `B001/0001E1-IntegrateMacroDialog-source-quality.md` SHA-256 `6226CA65FF6F3A2650380DABC7EC6532BC1837C609B1AE8780A6ABA883622B58`, `B001/00023K-DialogPaneScalarDeletingDestructorIsland.md` SHA-256 `384675E4A4703ABFA02432A9B7D3D84F9BA95CD9C0BD11EFC0D2703CB0301B47`, and `B007/0000N4-RegistryConfig-empty-emitter-family-source-quality.md` SHA-256 `65523BEA80D57588F40A049074233329FD64B0C3B0F3813C459A98E9BCA71AD1`.
  - Legacy executed root `archived/b-agent-reports-20260623/Agent-B001..B015/research/executed/`: no exact UID/range/name report or direct target finding.
  - Archived root `archived/b-agent-reports-20260623/`: no exact UID/range/name report or direct target finding beyond the same empty legacy result.
  - Active roots `tools/leaser/Agents/Agent-B001/research` through `Agent-B005/research`: no exact UID0001E2 report and no active conflicting TargetOptionDialog assignment at search time.
- Historical report findings were treated as leads. Every accepted conclusion below was checked against current by-* state and live MCP.

## Target

- Target UID: `0001E2`.
- Target path: `by-memory/0x00542270-0x0054259f.TargetOptionDialog.md`.
- Source queue/report row: first unreported exact target in the assigned reconstructable queue after excluded active/already-treated rows.
- Accepted callback source: exact report SHA-256 `6B83DFA235E514A9BFE05F68D1CC7FF86DD9FA1F2004B2DF12F47AA2D4DC307C`, mechanical Gate 1 passed at `2026-07-14T22:49:30-04:00`.
- Applied scores and parent state: `92/94`, `CANONICAL_OWNER:0000EE`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, `Nested:0`.

## Current Target State

- UID0001E2 now records the complete four-body/three-gap inventory and cannot emit aggregate source. Owner UID0000EE and source root UID0000OG remain unchanged.
- Registered children: UID0004QS `[0x00542270,0x0054248e)` `92/94` position 60; UID0004QT `[0x00542490,0x005424af)` `90/93` position 70; UID0004QU `[0x005424b0,0x00542534)` `92/94` position 80; UID0004QV `[0x00542540,0x0054259f)` `91/93` position 90. All are owner/emitter UID0000EE, reconstructable true, Nested 1.
- Exact internal padding `[0x0054248e,0x00542490)`, `[0x005424af,0x005424b0)`, and `[0x00542534,0x00542540)` is recorded in UID0000VN `by-memory/-ignored.md`.
- UID0000EF is `90/92` position 0 with the complete `0x110` class/layout/accessor declaration; UID0000EE is `92/94` position 50 with the complete fieldless `0x26c` declaration; UID0000OG is prose-only `90/91`; UID00011K remains `86/90`, position 10, as a separate unsplit method inventory.
- UID00038I and UID0003C9 are `91/93`, semantic owner UID0000EE, reconstructable false, blank emitter/position/formal, with complete no-code proof.
- Evidence-time/pre-callback generated snapshot command `000000012390`, SHA-256 `6FCC057EDDD3A92B44F8BA51EC027238FDEC77898470AAE9BDEC1CB6A52E29A8`, contained four markers and no source. Final waited command `000000012482` generated SHA-256 `59DEFD4D9DAB3A5A7C7DF3996A29BBF5BCFDC36E419B713BBFCBA1C0582CB33F` with both classes and all four methods once in accepted order.
- Final generated target-family marker counts are zero for UID0001E2/UID0000EE/UID0000EF. The one UID00011K marker is intentional separate unsplit support inventory. No scalar/adjustor/vtable/RTTI source appears.
- B002 callback work is complete and all B002 leases are released. External lifecycle/report state is not asserted.

## Executive Recommendation

- Semantic ownership remains UID0000EE and source placement remains UID0000OG.
- UID0001E2, children UID0004QS/0004QT/0004QU/0004QV, class declarations UID0000EF/UID0000EE, file prose UID0000OG, compiler support UID00038I/UID0003C9, UID00011K support position, and three ignored gaps are applied exactly as accepted.
- The edit-control declaration exposes source-safe inline accessors; no field offset arithmetic enters human source. `InitRectBounds` and `SaveUserSettings` declarations are emitted before first use while UID00015S and UID0001AV remain the sole definitions.
- UID00023J/UID00023K, UID0001AV/UID0001VR, and inherited control/global/type dependencies remain same-or-greater read-only support.

## Supervisor Active Recheck

- Gate 1 accepted the exact pre-callback artifact SHA `6B83DFA235E514A9BFE05F68D1CC7FF86DD9FA1F2004B2DF12F47AA2D4DC307C`.
- Every source-bearing interval has an exact registered UID/path, score, owner, emitter, position, signature, and formal body. Every padding/compiler interval has an exact no-source disposition.
- Serial validator registration assigned UID0004QS/0004QT/0004QU/0004QV; no UID was invented or reused.
- This report records completed B002 implementation and verification. Gate 2 and all report lifecycle state remain supervisor-owned.

## Inference Research Guidance Check

- `by-structure.md` was applied as an ownership/emission graph: UID0000EE remains semantic owner, UID0000OG remains source root, the mixed by-memory parent becomes a non-emitting index, and exact children carry code.
- Existing names were hypotheses. Direct facts are bytes, modeled bounds, xrefs, calls, vtable cells, object sizes, offsets, literals, and branch order. Documentation provides accepted API/type vocabulary. `SaveTargetOptions`, member names, and exact class declaration style are source-facing inference.
- Historical `OnConfirm`, `SaveTargetOptionsFromControls`, raw `dword_` names, and polluted `boost::exception` types were not accepted without reanalysis.
- No Wave2/Wave3 artifact was used as authority. Any historical/imported wording encountered was retained only when current binary/support evidence independently confirmed it.

## Heuristic / Inference Reanalysis And Validation

- Mixed aggregate: direct function lookup proves three modeled functions plus a full raw prologue/body/return helper and three alignment gaps. A monolithic source body is invalid; child splitting is mandatory.
- Constructor identity: one ordinary caller allocates `620` bytes and invokes `0x00542270` from menu selection case `5`. Three class vtable stores and the `DialogPane` base constructor establish `TargetOptionDialog::TargetOptionDialog()`.
- Constructor source reduction: explicit vptr writes, allocation-null diamonds, constructor-unwind states, external EH cleanup chunks, security-cookie setup/check, and operator-new calls are compiler lowering. Human source uses base/member/control construction and ordinary `new` expressions.
- Class size: the caller's `620`-byte allocation is `0x26c`, exactly the accepted DialogPane size before derived tails. TargetOptionDialog has no proven data members.
- Destructor identity: the 31-byte body only writes the same three class vtables and tail-jumps to the shared DialogPane teardown. Accepted sibling evidence makes an explicit empty destructor the highest-probability source. A blank/no-code method would fail to declare the source destructor that generates the scalar wrapper/vtable family.
- Virtual command name/signature: primary vtable cell `0x00621214` points to `0x005424b0`; accepted DialogPane declares `virtual void OnControlCommand(int controlIndex, int notifyCode)`. `OnConfirm` is superseded as the accepted source name.
- Command behavior: only `controlIndex == 1` commits. The second argument is not read. The exact order is save both rows, `SlideCloseVertical`, deferred-deletion queue, then `SaveUserSettings()` only if `g_activeMapPane != NULL`.
- Raw helper liveness/source shape: `0x00542540` has a standard frame prologue, two internally aligned loop-entry NOPs, a two-row member walk, and `ret`; it is source-shaped despite no IDA function object or inbound xref. The exact same row-copy operation is inlined in `OnControlCommand`. Highest-probability source is an out-of-line private `SaveTargetOptions()` whose call was inlined while an unused external copy remained in the linked image.
- Raw helper negative route: xrefs to `0x00542540` are zero, and little-endian searches for VA `40 25 54 00` and RVA `40 25 14 00` both return zero. This caps helper-name/original-inline confidence; it does not justify deleting an obvious source-shaped method.
- Child lookup: both command/helper fetch child indices `2` and `3` through DialogPane's `List *m_controlManager` at `+0x1fc` and List virtual slot `+0x10`. Accepted source is `GetChild<TargetOptionEditControlPane>(rowIndex + 2)`.
- Edit-control layout: constructor allocation is `272`/`0x110`; ControlPane base is `0x108`; fields are `int m_targetOptionMode` at `+0x108`, byte `m_userTargetEnabled` at `+0x10c`, byte `m_monsterTargetEnabled` at `+0x10d`, and two bytes implicit tail padding. A synthetic reserve array is rejected.
- Selection access: the binary directly loads `+0x10c/+0x10d`. Inline const accessors in the complete class declaration are source-safe and regenerate direct loads without public raw fields or cross-class offset arithmetic.
- Config layout: accepted `RegistryConfigUserProfileBlock` and SaveUserSettings use `m_targetOptionRows[2]`, stride two, with `userEnabled` then `monsterEnabled`. Constructor reads both rows; helper writes both rows.
- Constructor controls: control list order is background EPF control index `0`, ImageButton control index `1`, and target rows indices `2/3`. Focus, pending, and hover all select control `1`, matching the command selector.
- Resource and geometry: exact literals are `DLGSETUP.EPF`, `DLGSETUP.PAL`, empty title, background bounds `(0,0,338,190)`, action-button bounds `(138,156,201,180)`, row bounds `(19,64,318,84)` and `(19,98,318,118)`, and row step `34`.
- Show/layer route: accepted names are `g_mainUiLayerSlots.overlayPaneLayerContext` at `0x0069b36c` and `g_pBackPane` at `0x0067a740`; constructor calls `OnCreate`, `OnShow`, then `SlideOpenVertical`.
- Save gate: `0x0067a764` is accepted `g_activeMapPane`, not a dirty flag. No SaveUserSettings call occurs when it is null.
- Deferred deletion: `0x0067a74c` is accepted `g_pApplicationCleanupQueue`; `0x00469180` is `BlackHole::QueuePaneForDeferredDeletion(Pane *)`. This is not immediate `delete this`.
- Null/failure behavior: no source null checks exist for `g_pConfig`, fetched controls, cleanup queue, active child list, or allocation results at the semantic level. Compiler allocation-null/EH branches are not handwritten guards.
- Successor boundary: `0x0054259f-0x005425aa` subtracts `0xa0` and jumps to `0x00542680`; its data xref is from CScrollBarBackPane vtable cell `0x00621068`. It is not TargetOptionDialog code.
- Target ABI support: target-specific adjustors are later at `0x00542665/0x00542670` and jump to scalar wrapper `0x00542a60`. UID00038I and UID0003C9 must be covered by the class/destructor, not emitted as handwritten wrapper/table code.
- Source placement: constructor-only caller is MenuVarietySelectPane, but ownership remains TargetOptionDialog.cpp because the class, paired edit control, vtables, resources, config writeback, and destructor family are cohesive.
- Cross-source compile visibility: RectBounds geometry is defined through UID00015S/RectBounds support and SaveUserSettings is defined through UID0001AV/ProfileStorage. The current generator does not synthesize includes from prose-only by-file roots, so Destination 2 declares `InitRectBounds` immediately before the constructor and Destination 4 declares `SaveUserSettings` immediately before the command definition. These are declarations only; UID00015S and UID0001AV remain the sole definitions.
- Rejected source placements: MenuVarietyPanes.cpp is caller-only; ProfileStorage.cpp owns persistence, not UI; RegistryConfig.cpp owns storage/defaults, not dialog methods; DialogPane.cpp owns base infrastructure; OptionPane.cpp is only adjacent family context.
- Rejected method names: `OnConfirm` loses the accepted virtual contract; `SaveTargetOptionsFromControls` is overlong historical description; `WriteTargetOptionConfigBytes` overfits storage; `Commit` conflates save with close/queue/persist. `SaveTargetOptions` best describes the exact private operation.
- Remaining uncertainty: exact original private helper spelling, whether access was via inline getters/friend/public fields, and exact original header/file split. These are confidence caps, not code/owner/split blockers.

## Evidence Standards Used

- Evidence ladder: current IDA MCP bytes/functions/decompile/disassembly/basic blocks/xrefs/callees first; accepted by-* types/layouts/globals and generated state second; executed reports as revalidated support leads third; source-shape inference last.
- Strongest evidence: complete target bytes and hashes, exact modeled boundaries, three class vtable triads, one direct constructor caller with allocation size, virtual-table command route, raw helper instructions, accepted config/global APIs, and exact duplicate row-copy behavior.
- Negative evidence was used narrowly. Zero raw-helper xrefs/pointer bytes limits liveness/original spelling but does not override its complete member-function shape and duplicated inline operation.
- Tool limitations: stripped symbols and no recovered local TargetOptionDialog UDT prevent original spelling proof. Current accepted project declarations provide behavior-identical source-facing names.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: `idb_list` 111/132, `server_health` 112/133, bounded `get_bytes` 117/130/131/134, `lookup_funcs` 114, decompile 120-123, `xrefs_to` 124, `callees` 125, `basic_blocks` 126, raw/successor `disasm` 127-128, pointer/RVA `find_bytes` 129, and exact vtable bytes 130.
- by-* docs checked: target/class/file/edit-control aggregate; DialogPane/ControlPane/EPFImageControlPane/ImageButtonControlPane/BlackHole/RegistryConfig; RectBounds; globals; config profile slice; SaveUserSettings; scalar/vtable/thunk islands; ignored ledger; generated file; all affected manual coverage rows.
- Old-report search terms used: `TARGET-REPORT-UID:0001E2`, `UID0001E2`, `UID:0001E2`, `0x00542270`, `0x0054259f`, `TargetOptionDialog`, `SaveTargetOptions`, `OnConfirm`, `OnControlCommand`, `UID00011K`, `TargetOptionEditControlPane`, `UID0001AV`, `SaveUserSettings`, `UID0000EE`, `UID0000OG`, `DLGSETUP.EPF`, and `m_targetOptionRows`.
- Old-report roots/results: central `executed-b-agent-research/` had no direct target report and yielded the six opened support artifacts/hashes listed under Supporting Research; legacy executed `archived/b-agent-reports-20260623/Agent-B001..B015/research/executed/` had no direct hit; broad archived `archived/b-agent-reports-20260623/` had no direct hit; active `tools/leaser/Agents/Agent-B001/research` through `Agent-B005/research` had no direct or conflicting active hit. No prior `TARGET-REPORT-UID:0001E2` artifact exists.
- Negative checks: no function at `0x00542540`; zero xrefs to raw helper; zero VA/RVA pointer-byte hits; zero direct destructor xrefs; no second constructor caller; no target bytes beyond `0x0054259f`; no target-owned field beyond DialogPane base size; no dirty-state gate; no immediate delete; no target scalar/adjustor/vtable source body.
- Failed checks: fresh bounded `get_bytes` JSON-RPC id `113` used an obsolete single-address parameter shape and id `115` used `address` rather than schema field `addr`; both were client-parameter errors. `tools/list` id `116` refreshed the schema and ids `117/130/131` succeeded. These were not MCP/IDB outages and supplied no evidence.
- Initial report-only pass intentionally skipped IDA mutation, validators, leases, report lifecycle, generated refresh, coverage edits, and tracker/audit writes. The later supervisor-authorized callback used only the scoped leases/validators and waited generation recorded below; all other restrictions remained in force.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0001E2 is a mixed semantic index, not one source body. | very high | ids 114, 120-131; exact interval map | Destination 1 applied to UID0001E2; command 000000012478 final `ok` | incorporate | applied |
| C02 | Constructor is exactly `[0x00542270,0x0054248e)`, 542 bytes. | very high | lookup/decompile/basic blocks/bytes/hash | Destination 2 registered as UID0004QS; command 000000012451 | incorporate | applied |
| C03 | `[0x00542490,0x005424af)` is the ordinary empty source destructor. | very high | ids 114, 121, 124-126; sibling UID00049K | Destination 3 registered as UID0004QT; commands 000000012452/000000012474 | incorporate | applied |
| C04 | `[0x005424b0,0x00542534)` is `OnControlCommand(int,int)`. | very high | vtable `0x00621214`, ids 114/122/124-126, DialogPane declaration | Destination 4 registered as UID0004QU; command 000000012453 | incorporate | applied |
| C05 | `[0x00542540,0x0054259f)` is private `SaveTargetOptions`. | high | ids 117/127/129-131; duplicate row-copy behavior | Destination 5 registered as UID0004QV; command 000000012454 | incorporate | applied |
| C06 | Three internal intervals are alignment padding only. | very high | id 130 exact `0xcc` bytes | UID0000VN updated with all three gaps; command 000000012463 | incorporate | applied |
| C07 | `0x0054259f` is the exclusive boundary and CScrollBarBackPane successor thunk. | very high | ids 114/124/128/130; cell `0x00621068` | UID0001E2 exact successor row applied; UID00023J verified read-only | incorporate | applied |
| C08 | TargetOptionDialog is a fieldless `0x26c` DialogPane-derived class with three methods plus private helper. | high | caller allocation, ctor/vtables, accepted DialogPane size | Destination 7 UID0000EE applied; final command 000000012480 | incorporate | applied |
| C09 | TargetOptionEditControlPane is `0x110` with exact `+0x108/+0x10c/+0x10d` fields and implicit tail padding. | very high | current constructor/layout/vtable evidence; UID00011K recheck | Destination 6 UID0000EF command 000000012467; UID00011K command 000000012473 | incorporate | applied |
| C10 | Constructor creates exact EPF background, action button, and two edit rows. | very high | id 120 literals/callees/bounds | UID0004QS formal/evidence and UID0000OG prose; final generated lines 51-94 | incorporate | applied |
| C11 | Config source is `RegistryConfig::m_targetOptionRows[2]`, user then monster bytes. | very high | constructor/helper, UID0001VR, UID0001AV | UID0004QS/UID0004QV applied; UID0001VR/UID0001AV verified same-or-greater | incorporate | applied |
| C12 | Child indices are background 0, button 1, option rows 2 and 3. | high | construction order, selector, lookup loop | UID0004QS/UID0004QU/UID0004QV formal bodies and file prose | incorporate | applied |
| C13 | Constructor order is hover/focus/pending, resource, create, show, slide-open. | very high | id 120 exact call order | UID0004QS exact body; generated lines 84-94 | incorporate | applied |
| C14 | Sole ordinary constructor caller is MenuVarietySelectPane case 5 with 620-byte allocation. | very high | ids 123/124 | UID0004QS, UID0001E2, UID0000EE, and UID0000OG evidence | incorporate | applied |
| C15 | Command accepts only control index 1 and ignores notify code. | very high | id 122; vtable/base signature | UID0004QU exact body; generated lines 104-116 | incorporate | applied |
| C16 | Commit order is save, slide-close, queue deferred deletion, active-map-gated SaveUserSettings. | very high | id 122 exact branch/calls | UID0004QU and UID0000OG exact current prose; generated lines 109-115 | incorporate | applied |
| C17 | No config/control/queue null guards or alternate save failure branch may be invented. | very high | decompile/disassembly negative behavior | UID0004QS/UID0004QU/UID0004QV negative behavior preserved | incorporate | applied |
| C18 | B005 UID0001AV remains the sole global SaveUserSettings definition; target output emits only a matching external declaration before use. | very high | current page/generated/executed report; by-file no-formal rule | UID0004QU declaration at generated line 102; sole definition `ProfileStorage.cpp:416` | incorporate | applied |
| C19 | UID00038I is compiler scalar-delete support covered by the source destructor/class. | very high | vtable/thunks/wrapper and existing no-code proof | Destination 8 final `91/93` NONE/FALSE; commands 000000012470/000000012477 | incorporate | applied |
| C20 | UID0003C9 is compiler vtable data covered by class declarations. | very high | id 130 vtable bytes, current slot/xref docs | Destination 9 final `91/93` NONE/FALSE; command 000000012471 | incorporate | applied |
| C21 | Direct semantic owner UID0000EE and file UID0000OG remain correct. | very high | vtables, methods, caller, resources, source grouping | Owners retained; UID0000EE/UID0000OG final validators 000000012480/000000012482 | already-present | already-present |
| C22 | `OnConfirm` and `SaveTargetOptionsFromControls` are historical aliases, not competing accepted names. | high | base virtual contract and exact helper role | UID0001E2/UID0000EE/UID0000OG current prose accepts only `OnControlCommand`/`SaveTargetOptions`; history retained | historicalize | applied |
| C23 | UID00011K's old blanket class-C++ blocker is stale; its separate body inventory remains valid. | high | current support declarations plus fresh layout/vtable recheck | UID0000EF emits class/accessors; UID00011K remains blank aggregate at position 10 | reject-stale | applied |
| C24 | Evidence-time generated output's four markers proved missing emission; final output removes three target/class markers and retains only intentional UID00011K. | very high | commands 000000012390/000000012482 and SHA snapshots | Generated readback: target/class marker counts `0/0/0`; UID00011K count `1` | incorporate | applied |
| C25 | Constructor EH/cookie/allocation diamonds are compiler lowering, not handwritten source. | very high | 19-block CFG and cleanup chunks | UID0004QS compiler exclusions; no ABI/EH source in generated output | incorporate | applied |
| C26 | Applied scores materially improve target/class/support while preserving confidence caps. | high | blocker closure and remaining naming limits | Score matrix applied across Destinations 1-11 | incorporate | applied |
| C27 | Manual coverage rows are stale/absent and require exact supervisor-owned updates. | very high | direct row inspection | Exact coverage text synchronized to real UIDs; manual coverage intentionally not edited by B002 | incorporate | excluded-with-reason |
| C28 | No exact prior target report exists; relevant historical reports were independently revalidated. | very high | exact root/term search and opened artifacts | Supporting Research / Evidence Checked preserved unchanged | incorporate | already-present |
| C29 | IDA source-facing names/types are recommendations only; no IDA mutation is authorized. | very high | assignment restriction | No IDA mutation performed; rename/type/comment recommendations remain documentation-only | not-applicable | excluded-with-reason |
| C30 | Callback used serial child registration, exact dependency declarations, short leases, scoped validators, waited generation, and exact count/order/linkage checks. | very high | workflow, command records, generated readback | Commands 000000012451-000000012482; terminal checklist and Validator Results | incorporate | applied |

## Positive Evidence Summary

- The three modeled starts and raw helper consume the target exactly once when the three `0xcc` gaps are excluded.
- Constructor, ordinary destructor, and scalar wrapper all write the same primary/secondary/tertiary TargetOptionDialog vtables.
- Primary vtable cell `0x00621214` selects the exact command body and matches the accepted DialogPane virtual signature.
- The constructor's sole caller allocates exactly the DialogPane-sized `0x26c` object in target-options menu case `5`.
- Constructor and both save bodies agree on two rows, exact config bytes, exact child controls, and exact field order.
- Current support docs close all former type/API/global blockers without raw-offset source.
- The raw helper has full member-function machine shape and exactly duplicates the command's inline row-copy operation.

## IDA MCP Facts

- Function/range facts:
  - `0x00542270` `sub_542270`, size `0x21e`, exact end `0x0054248e`.
  - `0x00542490` `sub_542490`, size `0x1f`, exact end `0x005424af`.
  - `0x005424b0` `sub_5424B0`, size `0x84`, exact end `0x00542534`.
  - `0x00542540`: no IDA function object; raw source-shaped body ends with `ret` at `0x0054259e`.
  - `0x0054259f` `sub_54259F`, size `0x0b`, successor adjustor thunk.
- Exact byte/hash facts:
  - Constructor SHA-256 `57DC4855F4429B0E355A635663722CFB8139A9DE38EFF6CF69AFF787D1C9AA4C`.
  - Padding `[0x0054248e,0x00542490)` SHA-256 `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2`.
  - Destructor SHA-256 `F1B1FBF2B2215002F19A6F39142E737662F0A5EB50CF0BFE619A3692E333346F`.
  - Padding `[0x005424af,0x005424b0)` SHA-256 `1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6`.
  - Command SHA-256 `9A5C1ECAFD1B504973A90BC7992329991ECCB6DA5213703F0AE3E49009355E09`.
  - Padding `[0x00542534,0x00542540)` SHA-256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`.
  - Raw helper SHA-256 `35F7B49274F1700A93E959B9FAEFA39DFFF0FEC3749C38DCE11DC8C68687D938`.
  - Successor thunk SHA-256 `D48EF504C39D9096651C60599C2E08256EF24BD55913A1E7CB494262CD445790`.
- CFG facts: constructor has 19 reported blocks including external EH/cleanup nodes and 12 ordinary in-body blocks; destructor has one local block plus external base tail; command has 6 blocks and complexity consistent with selector, loop, and save gate.
- Xref facts: constructor has one code xref at `0x005bd17c`; destructor has zero direct xrefs; command has one data xref from primary vtable cell `0x00621214`; raw helper has zero xrefs; successor has one CScrollBarBackPane vtable data xref.
- Callee facts: constructor has 14 ordinary internal callees plus security-cookie support; command calls `SlideCloseVertical`, `QueuePaneForDeferredDeletion`, and `SaveUserSettings`; ordinary destructor tail-jumps to shared base teardown.
- Vtable facts: TargetOptionDialog primary `0x006211cc`, secondary `0x0062122c`, tertiary `0x0062125c`; class command slot `0x00621214`; target scalar wrapper `0x00542a60`; target adjustors `0x00542665/0x00542670`.
- Global/type facts: `g_pConfig` `0x0067a7c8`; `g_pBackPane` `0x0067a740`; cleanup queue `0x0067a74c`; `g_activeMapPane` `0x0067a764`; overlay layer context `0x0069b36c`.
- Negative IDA facts: no raw helper function/xref/pointer bytes, no destructor direct xref, no extra target object tail, no target bytes at successor, no dirty-state gate, and no source call after a null active-map pointer.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00542270-0x0054259f` | UID0001E2 / `by-memory/0x00542270-0x0054259f.TargetOptionDialog.md` | semantic split index | no | UID0000EE | `92/94` | applied non-emitting index; blank emitter/position/formal C++ |
| `0x00542270-0x0054248e` | UID0004QS / `by-memory/0x00542270-0x0054248e.TargetOptionDialogConstructor.md` | source constructor | yes | UID0000EE | `92/94` | registered and emitted at position 60 |
| `0x0054248e-0x00542490` | UID0000VN `-ignored` | two-byte alignment | no | physical interval | `100` | exact internal padding row applied |
| `0x00542490-0x005424af` | UID0004QT / `by-memory/0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor.md` | empty source destructor | yes | UID0000EE | `90/93` | registered and emitted at position 70 |
| `0x005424af-0x005424b0` | UID0000VN `-ignored` | one-byte alignment | no | physical interval | `100` | exact internal padding row applied |
| `0x005424b0-0x00542534` | UID0004QU / `by-memory/0x005424b0-0x00542534.TargetOptionDialogOnControlCommand.md` | virtual command/apply method | yes | UID0000EE | `92/94` | registered and emitted at position 80 |
| `0x00542534-0x00542540` | UID0000VN `-ignored` | twelve-byte alignment | no | physical interval | `100` | existing row retained and corrected |
| `0x00542540-0x0054259f` | UID0004QV / `by-memory/0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw.md` | retained private source helper | yes | UID0000EE | `91/93` | registered and emitted at position 90 |
| `0x0054259f-0x005425aa` | UID00023J contained successor | CScrollBarBackPane adjustor thunk | no | compiler/linker island | existing | verify-only, outside target |
| `0x00542665-0x0054267b` | UID00023J contained support | TargetOptionDialog adjustor pair | no | compiler ABI | existing | verify-only |
| `0x00542a60-0x00542ab5` | UID00038I | scalar deleting destructor | no | UID0000EE | `91/93` | applied non-emitting covered support |
| `0x006211c8-0x00621264` | UID0003C9 | vtable/RTTI data | no | UID0000EE | `91/93` | applied non-emitting covered support |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005bd17c` | call from modeled `0x005bd000` | only ordinary TargetOptionDialog constructor caller; menu case 5 |
| `0x005bd160` | allocation size `620` | exact class size `0x26c` |
| `0x005423dc` | call to `0x004993b0` | creates each TargetOptionEditControlPane row |
| `0x006211cc` | refs from ctor `0x005422ca`, dtor `0x00542490`, scalar `0x00542a66` | primary class identity triad |
| `0x0062122c` / `0x0062125c` | ctor/dtor/scalar triad refs | secondary/tertiary class identity |
| `0x00621214` | points to `0x005424b0` | virtual `OnControlCommand` slot |
| `0x00542540` | zero xrefs and zero VA/RVA pointer hits | retained raw helper with no live direct route |
| `0x0054259f` | data ref from `0x00621068` | successor belongs CScrollBarBackPane, not target |
| `0x00542665/0x00542670` | jumps to `0x00542a60` | target compiler adjustor pair |
| `0x0054252a` | call to `0x0050aba0` | SaveUserSettings only under active-map branch |

## Documentation Evidence And IDA Status

- Evidence-time / pre-callback UID0001E2 recorded the two config rows and active-map-gated persistence but retained stale half-open endpoints, `OnConfirm`, reconstructable parent emission, and blank-body rationale. The applied page is now `92/94`, owner UID0000EE, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, and an exact eight-interval child/padding index with real children UID0004QS/UID0004QT/UID0004QU/UID0004QV; validator commands 000000012458, 000000012475, and final wording command 000000012478 passed.
- Evidence-time / pre-callback UID0000EE/UID0000EF/UID0000OG lacked complete declarations and deterministic positions. UID0000EF now emits the complete `0x110` edit-control declaration at position 0 under command 000000012467; UID0000EE now emits the complete fieldless `0x26c` dialog declaration at position 50 under commands 000000012468, 000000012476, and 000000012480; UID0000OG now records the complete prose-only source contract at `90/91` under commands 000000012472 and 000000012481 and has no reconstruction metadata.
- UID00011K remains a separate source-bearing aggregate at `86/90` with blank formal C++; command 000000012473 applied position 10 and preserved its same-or-greater binary behavior/layout evidence. Its historical 2026-06-16 blanket class-C++ blocker is superseded only by UID0000EF's declaration/accessors; its unsplit method bodies are not claimed complete.
- UID0001VR and UID0001AV remain read-only same-or-greater dependencies for `m_targetOptionRows`, byte order, SaveUserSettings ABI, and serialization. No callback drift required an edit.
- Evidence-time / pre-callback UID00038I and UID0003C9 paired strong no-handwritten-source prose with contradictory reconstructable/emitter metadata. UID00038I is now `91/93`, owner UID0000EE, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++ after commands 000000012470 and 000000012477; UID0003C9 has the same final disposition after command 000000012471.
- Final waited generation command 000000012482 produced `auto-generated/NexusTK/ui/dialogs/TargetOptionDialog.cpp` SHA256 `59DEFD4D9DAB3A5A7C7DF3996A29BBF5BCFDC36E419B713BBFCBA1C0582CB33F`. Readback proves exactly one declaration for each class, one constructor, one ordinary destructor, one `OnControlCommand`, one `SaveTargetOptions`, matching external declarations before first use, zero UID0001E2/UID0000EE/UID0000EF empty markers, zero handwritten scalar/adjustor/vtable/RTTI ABI source, and one intentional UID00011K marker for its separate unsplit inventory.
- Manual coverage was inspected read-only and remains supervisor-owned. Its evidence-time rows are stale relative to the applied ordinary pages; the exact replacement/addition text below now uses the real registered child UIDs. B002 did not edit manual coverage.

## Ranked Ownership Analysis

### 1. TargetOptionDialog class UID0000EE

- Evidence for: constructor/destructor/scalar vtable triad, virtual command slot, DialogPane receiver/layout, target-specific resources, two-row controls, and target-specific config/save behavior.
- Evidence against: stripped symbols leave exact private-helper spelling inferred.
- Decision: direct semantic owner and emitter parent for all four exact source children.

### 2. TargetOptionDialog file UID0000OG

- Evidence for: current source tree groups both TargetOptionDialog and TargetOptionEditControlPane; the dialog allocates the edit control; resources/config flow are cohesive; generated route already exists.
- Evidence against: exact original file basename cannot be proven from the binary.
- Decision: retain file root and `NexusTK/ui/dialogs/TargetOptionDialog.cpp`; no new file.

### 3. MenuVarietyPanes / RegistryConfig / ProfileStorage / DialogPane alternatives

- Evidence for: MenuVariety launches the dialog; RegistryConfig owns bytes; ProfileStorage persists them; DialogPane owns base APIs.
- Evidence against: none owns the target class vtables, target resources, constructor/destructor, or complete command flow.
- Decision: dependencies/caller only; reject as target source owners.

### Proposed new file/grouping, if applicable

- Applied owner/name/path: no new by-file page was created; UID0000OG and `NexusTK/ui/dialogs/TargetOptionDialog.cpp` were retained.
- Current generated contents: TargetOptionEditControlPane declaration, TargetOptionDialog declaration, the four exact TargetOptionDialog methods, and no handwritten compiler vtable/destructor ABI products.
- Candidate related items that belong: UID00011K edit-control family as existing sibling inventory; UID00038I/UID0003C9 as covered compiler support.
- Candidate related items rejected: MenuVariety caller methods, ProfileStorage writer body, RegistryConfig defaults/serialization, generic DialogPane/ControlPane implementations, broad thunk/scalar islands.
- Standalone, narrow, or broad source-file inference: narrow two-class dialog source, not a generic options or menu file.

## Source Placement

- Applied source file/class/module: the two class declarations and four method definitions emit in `NexusTK/ui/dialogs/TargetOptionDialog.cpp` through UID0000OG.
- Applied compile-visible dependency route: one matching `InitRectBounds` declaration appears directly before the constructor and one matching `SaveUserSettings` declaration directly before `OnControlCommand`. UID00015S and UID0001AV remain the sole definitions; by-file roots retain no reconstruction metadata.
- Applied deterministic order: TargetOptionEditControlPane class position `0`; UID00011K support inventory position `10`; TargetOptionDialog class position `50`; constructor/destructor/command/helper positions `60/70/80/90`.
- Why it fits: the target constructor is the sole edit-control constructor caller, both classes share config semantics/resources, the command reads the edit-control fields, and current project source-tree docs already choose this route.
- Rejected placements: MenuVarietyPanes.cpp, OptionPane.cpp, DialogPane.cpp, ControlPane.cpp, RegistryConfig.cpp, ProfileStorage.cpp, or a new one-helper file.
- Remaining uncertainty: original header filename and whether both class declarations lived in a private header or the source file. Current by-file emission models the source unit, and this uncertainty does not affect behavior.

## Range / Split / Padding / Reclassification Analysis

- Exact parent range: `[0x00542270,0x0054259f)`, 815 bytes. No byte is uncovered or doubly assigned by the applied split.
- Exact child routes: UID0004QS, UID0004QT, UID0004QU, and UID0004QV cover the four source ranges in Function / Child Inventory.
- Padding: two bytes at `0x0054248e`, one byte at `0x005424af`, and twelve bytes at `0x00542534` are all `0xcc`; all three exact rows are present in `by-memory/-ignored.md` after command 000000012463.
- Constructor EH: cleanup chunks reported outside the linear target interval are compiler exception metadata/codegen associated with constructor failure, not separate source children.
- Parent impact: UID0001E2 is `RECONSTRUCTABLE:FALSE`, has blank emitter/position/formal C++, and retains owner UID0000EE and `Nested:0`.
- Child nesting: each new exact method child uses `Nested:1`; the cumulative nesting value records split depth, not child count.
- Compiler products: UID00038I and UID0003C9 are non-emitting. UID00023J/UID00023K remain broad compiler-support inventories and are not folded into the target.

## Negative Evidence Summary

- No exact prior UID0001E2 report exists in central executed, legacy archived, archived, or active B001-B005 roots.
- No raw-helper function object, xref, VA pointer, or RVA pointer exists. This rejects a live externally called API but not the retained source helper inference.
- No direct ordinary destructor xref exists. Vtable-store identity and accepted compiler-destructor precedent establish the source destructor.
- No derived field beyond DialogPane's `0x26c` size is read or written. Reject invented TargetOptionDialog state/reserve fields.
- No command behavior for selector values other than `1`; reject base fallback call or alternate action.
- No read of notifyCode; reject notification-specific branches.
- No null/failure guards for config, controls, queue, or SaveUserSettings; reject safety additions.
- No dirty flag at `0x0067a764`; reject historical dirty-state language.
- No immediate object delete; reject `delete this` in the command.
- No handwritten source shape for scalar deleting wrapper, adjustors, vtable bytes, RTTI, vptr stores, EH cleanup, cookie, or allocation diamonds.
- No evidence that MenuVariety, RegistryConfig, ProfileStorage, or generic pane classes directly own these methods.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names for future optional IDA cleanup only:
  - `0x00542270` -> `TargetOptionDialog::TargetOptionDialog`.
  - `0x00542490` -> `TargetOptionDialog::~TargetOptionDialog` ordinary non-deleting body.
  - `0x005424b0` -> `TargetOptionDialog::OnControlCommand`.
  - raw `0x00542540` -> `TargetOptionDialog::SaveTargetOptions` if a function object is ever deliberately created by the supervisor.
  - `0x004993b0` remains `TargetOptionEditControlPane::TargetOptionEditControlPane`.
- Type directions: TargetOptionDialog derives DialogPane with no added fields; TargetOptionEditControlPane derives ControlPane and has exact 32-bit mode plus two byte flags; command return is void with two 32-bit parameters; helper/destructor return void.
- Global names: preserve accepted `g_pConfig`, `g_pBackPane`, `g_pApplicationCleanupQueue`, `g_activeMapPane`, and `g_mainUiLayerSlots.overlayPaneLayerContext` rather than raw labels.
- Comment directions: note raw-helper zero-route retained-copy status, constructor EH/compiler lowering, active-map persistence gate, and successor CScrollBar thunk boundary.
- Rejected IDA/decompiler names: `sub_542270`, `sub_542490`, `sub_5424B0`, `boost::exception`, `dword_67A7C8`, `dword_67A764`, `dword_67A74C`, and `unk_69B36C` as source-facing labels.
- IDA DB edits are not requested or authorized. No IDA mutation occurred.

## First-Draft C++ Recommendation

- Eligible: the two class declarations and all four source-bearing target children.
- Ineligible: mixed parent UID0001E2, scalar wrapper UID00038I, vtable data UID0003C9, internal padding, successor/broad adjustor thunks, constructor EH/cookie/allocation lowering.
- All C++ below is destination-specific exact formal insertion text. No body-only/example C++ exists elsewhere in this report.

### Destination 1 - UID0001E2 semantic split index

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact metadata with this blank block: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000EE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, `Nested:0`.

### Destination 2 - UID0004QS constructor child

Applied path: `by-memory/0x00542270-0x0054248e.TargetOptionDialogConstructor.md`; validator registration assigned UID0004QS. Metadata is `92/94`, owner/emitter UID0000EE, position `60`, `Nested:1`.

Exact Item Summary: `Source-ready TargetOptionDialog constructor with exact DialogPane base arguments, DLGSETUP resources, background/button/two-row control order, RegistryConfig row seeds, geometry, focus/pending/hover state, create/show/layer/slide lifecycle, sole menu caller, fieldless 0x26c layout, and compiler-only allocation/EH/cookie lowering.`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void InitRectBounds(RectBounds *bounds,
                    int left,
                    int top,
                    int right,
                    int bottom);

TargetOptionDialog::TargetOptionDialog()
    : DialogPane(L"", 3, 1)
{
    RegistryConfig &config =
        *static_cast<RegistryConfig *>(g_pConfig);
    RectBounds bounds;

    InitRectBounds(&bounds, 0, 0, 338, 190);
    AddControl(new EPFImageControlPane(
        L"DLGSETUP.EPF", 0, 1, &bounds, L"DLGSETUP.PAL"));

    InitRectBounds(&bounds, 138, 156, 201, 180);
    AddControl(new ImageButtonControlPane(14, &bounds));

    for (int rowIndex = 0; rowIndex < 2; ++rowIndex)
    {
        const int top = 64 + rowIndex * 34;
        InitRectBounds(&bounds, 19, top, 318, top + 20);
        AddControl(new TargetOptionEditControlPane(
            rowIndex,
            config.m_targetOptionRows[rowIndex].userEnabled,
            config.m_targetOptionRows[rowIndex].monsterEnabled,
            &bounds));
    }

    SetHoverControl(1);
    SetFocusedControl(1);
    SetPendingControl(1);
    SetBackgroundResource(L"DLGSETUP.EPF", NULL);

    InitRectBounds(&bounds, 0, 0, 338, 190);
    OnCreate(&bounds,
             0,
             NULL,
             g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - UID0004QT ordinary non-deleting destructor child

Applied path: `by-memory/0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor.md`; validator registration assigned UID0004QT. Metadata is `90/93`, owner/emitter UID0000EE, position `70`, `Nested:1`.

Exact Item Summary: `Source-ready empty ordinary TargetOptionDialog destructor with exact 31-byte vptr/base-teardown lowering, zero direct xrefs, three-vtable class identity, accepted empty-destructor sibling precedent, and separate compiler scalar-wrapper/adjustor/vtable dispositions.`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TargetOptionDialog::~TargetOptionDialog()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - UID0004QU OnControlCommand child

Applied path: `by-memory/0x005424b0-0x00542534.TargetOptionDialogOnControlCommand.md`; validator registration assigned UID0004QU. Metadata is `92/94`, owner/emitter UID0000EE, position `80`, `Nested:1`.

Exact Item Summary: `Source-ready TargetOptionDialog OnControlCommand accepting only control 1, ignoring notify code, saving two option rows, sliding closed, queuing deferred deletion, and calling the sole global SaveUserSettings definition only when g_activeMapPane is non-null, with exact declaration/linkage and no-null/no-failure behavior.`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SaveUserSettings();

void TargetOptionDialog::OnControlCommand(int controlIndex, int)
{
    if (controlIndex != 1)
        return;

    SaveTargetOptions();
    SlideCloseVertical();
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);

    if (g_activeMapPane != NULL)
        SaveUserSettings();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - UID0004QV raw SaveTargetOptions child

Applied path: `by-memory/0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw.md`; validator registration assigned UID0004QV. Metadata is `91/93`, owner/emitter UID0000EE, position `90`, `Nested:1`.

Exact Item Summary: `Source-ready retained private SaveTargetOptions helper copying user/monster bytes from child controls 2/3 into RegistryConfig rows 0/1, with full prologue/loop/return shape, duplicated inlined command behavior, zero modeled function/xrefs/VA-or-RVA pointers, exact no-null behavior, and helper-name/liveness confidence cap.`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TargetOptionDialog::SaveTargetOptions()
{
    RegistryConfig &config =
        *static_cast<RegistryConfig *>(g_pConfig);

    for (int rowIndex = 0; rowIndex < 2; ++rowIndex)
    {
        TargetOptionEditControlPane *control =
            GetChild<TargetOptionEditControlPane>(rowIndex + 2);

        config.m_targetOptionRows[rowIndex].userEnabled =
            control->GetUserTargetEnabled();
        config.m_targetOptionRows[rowIndex].monsterEnabled =
            control->GetMonsterTargetEnabled();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - UID0000EF TargetOptionEditControlPane class

Exact metadata: `90/92`, owner/emitter UID0000OG, position `0`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TargetOptionEditControlPane : public ControlPane
{
public:
    TargetOptionEditControlPane(int optionMode,
                                unsigned char userTargetEnabled,
                                unsigned char monsterTargetEnabled,
                                const RectBounds *bounds);
    virtual ~TargetOptionEditControlPane();

    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual char HitTestPart(int mouseY, int mouseX);

    unsigned char GetUserTargetEnabled() const
    {
        return m_userTargetEnabled;
    }

    unsigned char GetMonsterTargetEnabled() const
    {
        return m_monsterTargetEnabled;
    }

private:
    int m_targetOptionMode;
    unsigned char m_userTargetEnabled;
    unsigned char m_monsterTargetEnabled;
};
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7 - UID0000EE TargetOptionDialog class

Exact metadata: `92/94`, owner/emitter UID0000OG, position `50`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TargetOptionDialog : public DialogPane
{
public:
    TargetOptionDialog();
    virtual ~TargetOptionDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    void SaveTargetOptions();
};
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8 - UID00038I scalar deleting destructor no-code block

Exact metadata: `91/93`, `CANONICAL_OWNER:0000EE`, `RECONSTRUCTABLE:FALSE`, blank emitter/position, `Nested:0`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: primary vtable and both adjustors target the wrapper; it duplicates destructor vptr/base-teardown behavior, interprets scalar delete flags, conditionally invokes storage free, and carries compiler-specific size/placement-delete behavior. Destination 3 and Destination 7 are the only human source needed to regenerate it.

### Destination 9 - UID0003C9 vtable-data no-code block

Exact metadata: `91/93`, `CANONICAL_OWNER:0000EE`, `RECONSTRUCTABLE:FALSE`, blank emitter/position, `Nested:0`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: all 156 bytes are RTTI/vtable cells, including compiler pointers to inherited methods, scalar wrapper, command body, and adjustors. Destinations 6/7 plus source virtual methods regenerate the table; handwritten table bytes would be ABI-specific duplicate source.

### Destination 10 - UID0000OG TargetOptionDialog by-file prose

- Applied prose-only at `90/91` with exact two-class source order, exact four target method children, resource/config/control/lifecycle/compiler exclusions, and UID00011K separate-inventory status.
- Do not add `RECONSTRUCTION_CPP` metadata or blocks to the by-file root.

### Destination 11 - UID00011K paired edit-control aggregate support

- Applied while preserving `86/90`, owner/emitter UID0000EF, reconstructable true, and blank formal body; stable position is `10`.
- The page now records the revalidated `0x110` layout, exact field/accessor contract, and that UID0000EF supplies the class declaration without claiming implementation of the broad aggregate's method bodies.

### Destination 12 - UID0001VR RegistryConfigUserProfileBlock verify-only

- Verified read-only with no concrete drift. The `88/88` comment-only layout slice records `m_targetOptionRows[2]`, stride 2, user/monster byte order, defaults/load/save/UI consumers, and no duplicate standalone struct.

### Destination 13 - UID0001AV SaveUserSettings verify-only

- Verified read-only. The `92/93` global SaveUserSettings body and target-option section are same-or-greater; the definition was neither duplicated nor relocated.
- Destination 4 emits only the exact matching declaration needed by generated TargetOptionDialog.cpp.

### Destination 14 - inherited control/global/compiler support verify-only

- DialogPane, ControlPane, EPFImageControlPane, ImageButtonControlPane, RectBounds, BlackHole, accepted globals, UID00023J, and UID00023K were verified read-only with no concrete drift.
- Existing declarations provide the exact calls/types; UID00023J/UID00023K remain compiler-support owners.

- Behavior preservation: the constructor formal preserves exact control creation and setup order; command/helper preserve exact row loop, branch, close/queue/save order, no guards, and ignored notify argument; empty destructor preserves compiler-generated vptr/base teardown.
- Period plausibility: ordinary classes, constructors, virtual override, private helper, typed child lookup, `new`, inline byte accessors, `NULL`, and simple loops match the accepted late-1999 to mid-2000s project style. No modern library, lambda, range-for, smart pointer, or decompiler offset arithmetic is introduced.
- Naming style: current project class/member/global vocabulary and accepted support pages are used. Exact private helper/accessor spellings remain inferred and cap confidence.

## Final Recommendation

- Destinations 1-11 are applied at full accepted detail. Destinations 12-14 were re-read and remain same-or-greater read-only dependencies with no concrete drift.
- The declaration/definition distinction is preserved: the target constructor block declares but does not define `InitRectBounds`; the command block declares but does not define `SaveUserSettings`; UID00015S and UID0001AV remain the sole definitions.
- The four children were registered serially as UID0004QS, UID0004QT, UID0004QU, and UID0004QV. No duplicate UID00011K or UID0001AV report/page was created.
- UID0001E2 retains semantic owner UID0000EE and is a non-emitting, non-reconstructable split index. UID0000OG retains the source file route and deterministic declaration/method order.
- Padding, scalar wrapper, adjustors, vtable/RTTI, EH/cookie/allocation mechanics remain non-emitting.
- No investigable target blocker or unapplied B002 callback item remains. Remaining uncertainty is exact original private spelling/header arrangement and only caps confidence.

## Recommended Target Doc Changes

- Applied target path: `by-memory/0x00542270-0x0054259f.TargetOptionDialog.md`.
- Applied metadata: `92/94`, owner UID0000EE retained, reconstructable false, emitter blank, position blank, formal blank, `Nested:0` retained.
- Item Summary: `Non-emitting TargetOptionDialog split index for exact constructor, empty ordinary destructor, OnControlCommand, and retained raw SaveTargetOptions children; records three internal alignment gaps, two target-option rows, DialogPane/control/config/global dependencies, active-map-gated persistence order, and compiler-only thunk/scalar/vtable/EH exclusions without duplicate aggregate source.`
- The stale range table was replaced by all eight half-open intervals, exact sizes/hashes, successor boundary, and real child UID links.
- Complete caller/callee/xref/CFG/vtable/object-size/control/config/resource/lifecycle/no-guard/raw-liveness evidence was incorporated.
- Inclusive-looking endpoints, `OnConfirm`, `SaveTargetOptionsFromControls`, dirty-state language, 95/95 blank-code rationale, and polluted base type are retained only as explicit superseded history.
- Exact real child links and positions are UID0004QS/60, UID0004QT/70, UID0004QU/80, and UID0004QV/90; no placeholder remains.

## Recommended Support Doc Changes

- `by-class/TargetOptionEditControlPane.md`: Destination 6 is applied at `90/92`, position 0, with the complete class declaration, exact size/layout/method/vtable/accessor/implicit-padding evidence, and historicalized old blanket no-C++ statement.
- `by-class/TargetOptionDialog.md`: Destination 7 is applied at `92/94`, position 50, with the complete fieldless class declaration and exact child inventory while preserving scalar/vtable/compiler distinctions.
- `by-file/TargetOptionDialog.md`: Destination 10 is applied at `90/91` as prose only, with exact source grouping/order and no by-file reconstruction metadata.
- `by-file/RectBounds.md` and `by-file/ProfileStorage.md`: read-only source/header placement evidence. Their prose-only roots must not receive reconstruction metadata; current generated compile visibility is supplied by the exact declarations in Destinations 2/4.
- `by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md`: Destination 11 bounded support sync is applied with existing research/body inventory/history preserved, exact class-contract link, and position `10`.
- `by-memory/0x00542a60-0x00542ab5.TargetOptionDialogScalarDeletingDestructor.md`: Destination 8 metadata/no-code reconciliation and covered-by class/destructor proof are applied.
- `by-memory/0x006211c8-0x00621264.TargetOptionDialogVtableData.md`: Destination 9 metadata/no-code reconciliation and complete slot/class coverage proof are applied.
- `by-memory/-ignored.md`: exact internal gaps `0x0054248e-0x00542490` and `0x005424af-0x005424b0` were added; `0x00542534-0x00542540` was retained/corrected; all are exact `0xcc` intervals in UID0001E2 context.
- UID0001VR, UID0001AV, DialogPane, EPFImageControlPane, ImageButtonControlPane, RectBounds, BlackHole, globals, UID00023J, and UID00023K were verified same-or-greater and left unchanged.

## Score And Metadata Recommendation

- UID0001E2 is applied at `92/94`; owner UID0000EE and Nested 0 are retained, reconstructable is false, and emitter/position/formal C++ are blank. Historical score was `86/90`.
- UID0004QS constructor is applied at `92/94`, true, owner/emitter UID0000EE, position 60, Nested 1.
- UID0004QT destructor is applied at `90/93`, true, owner/emitter UID0000EE, position 70, Nested 1.
- UID0004QU command is applied at `92/94`, true, owner/emitter UID0000EE, position 80, Nested 1.
- UID0004QV raw helper is applied at `91/93`, true, owner/emitter UID0000EE, position 90, Nested 1.
- UID0000EF class is applied at `90/92`, owner/emitter UID0000OG retained, position 0, complete declaration. Historical score was `86/90`.
- UID0000EE class is applied at `92/94`, owner/emitter UID0000OG retained, position 50, complete declaration. Historical score was `86/88`.
- UID0000OG file is applied at `90/91`, path retained, prose only, and contains no reconstruction metadata. Historical score was `86/86`.
- UID00011K remains `86/90` and source-bearing aggregate status with position `10`; no unearned body-completion score change was made.
- UID00038I is applied at `91/93`, owner UID0000EE retained, reconstructable false, emitter/position/formal C++ blank. Historical score was `86/91`.
- UID0003C9 is applied at `91/93`, owner UID0000EE retained, reconstructable false, emitter/position/formal C++ blank. Historical score was `85/91`.
- Score-improvement blockers resolved:
  - split/range blocker -> exact children and padding map;
  - inherited API blocker -> accepted DialogPane/control/RectBounds declarations;
  - config layout blocker -> accepted m_targetOptionRows contract;
  - command-name blocker -> OnControlCommand vtable/base proof;
  - helper-liveness blocker -> raw body, duplicated inline operation, zero-route cap;
  - destructor blocker -> accepted empty-source-destructor precedent;
  - compiler ABI contradiction -> non-emitting scalar/vtable dispositions;
  - generated-marker blocker -> final waited output contains both declarations/four methods and zero target/class markers;
  - cross-source declaration blocker -> exact matching declarations in valid child emitters while retaining sole definitions in RectBounds/ProfileStorage.
- Scores remain below 95 because stripped symbols do not prove original private helper/accessor spelling or original header/file declaration arrangement.

## Open Questions With Attempted Resolution

- Exact raw helper spelling: checked raw bytes, xrefs, pointer searches, caller duplication, current docs, and old reports. Best defensible name is `SaveTargetOptions`; original spelling remains unknown but does not affect behavior.
- Raw helper liveness: checked function metadata, direct xrefs, VA/RVA pointers, inlined duplicate body, and successor. Best resolution is retained out-of-line private helper with an inlined command call; no live external route is claimed.
- Edit-control field access style: binary cannot distinguish public fields, friendship, or inline accessors. Inline const accessors are source-safe, ABI-neutral, and regenerate exact loads. This is a confidence cap only.
- Exact `HitTestPart` return/type spelling on the paired control: vtable result uses AL and values 0/1/-1; accepted source direction is `char`. It is declaration support here, not a new body claim.
- Original file/header split: source family and generated path are strong; exact original header basename is unrecoverable from current evidence. Retain current by-file route.
- External declaration placement: current by-file guidance forbids formal reconstruction metadata on by-file roots, so include/header prose alone would not make generated TargetOptionDialog.cpp see the two free helpers. Exact matching declarations are therefore placed in Destinations 2/4 before first use; no second definition is introduced.
- UID allocation: resolved by serial validator registration as UID0004QS, UID0004QT, UID0004QU, and UID0004QV. No placeholder remains in current recommendations, ordinary docs, or exact coverage text.
- No question remains that blocks target split, owner, emitter, score, or formal C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected manual rows read-only:
  - `by-memory/-coverage-report.md`: UID0001E2 line 2556; UID0000VN target padding line 2557; UID00023J line 2558; UID00011K line 1150; UID0001AV line 2224. UID00038I and UID0003C9 are absent.
  - `by-class/-coverage-report.md`: UID0000EE line 539 and UID0000EF line 540.
  - `by-file/-coverage-report.md`: UID0000OG line 277.
  - `by-type/by-struct/-coverage-report.md`: UID0001VR line 97.
- UID0001AV and UID0001VR rows already match the verify-only recommendation; no change.
- Supervisor-owned exact replacement for the UID0001E2 row and its evidence-time one-padding child block, synchronized to the four real validator-assigned child UIDs:

```text
    - [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md) 0x00542270-0x0054259f | non-emitting class-method split index | TargetOptionDialog : not_reconstructable : 92% : very strong : Exact TargetOptionDialog constructor, empty ordinary destructor, OnControlCommand, and retained raw SaveTargetOptions child inventory with three internal alignment gaps, fieldless DialogPane-derived layout, two config rows, child-control/resource/lifecycle behavior, active-map-gated persistence, and compiler-only EH/thunk/scalar/vtable exclusions; source emits only through exact children.
        - [UID:0004QS][0x00542270-0x0054248e.TargetOptionDialogConstructor](by-memory/0x00542270-0x0054248e.TargetOptionDialogConstructor.md) 0x00542270-0x0054248e | constructor | TargetOptionDialogConstructor : reconstructable : 92% : very strong : Source-ready TargetOptionDialog constructor with exact DialogPane base arguments, DLGSETUP resources, background/button/two-row controls, RegistryConfig row seeds, bounds, focus/pending/hover, create/show/layer route, slide-open order, sole menu caller, 0x26c class size, and compiler-only allocation/EH/cookie exclusions.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0054248e-0x00542490 | padding | TargetOptionDialog constructor to destructor alignment : ignored : 100% : strong : Exact two 0xcc bytes after the constructor's corrected half-open endpoint.
        - [UID:0004QT][0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor](by-memory/0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor.md) 0x00542490-0x005424af | destructor | TargetOptionDialogNonDeletingDestructor : reconstructable : 90% : very strong : Source-ready empty ordinary TargetOptionDialog destructor; exact 31-byte compiler lowering writes three class vtables and tail-calls DialogPane teardown, while scalar wrapper/adjustors remain compiler-only.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005424af-0x005424b0 | padding | TargetOptionDialog destructor to command alignment : ignored : 100% : strong : Exact one 0xcc byte after the destructor's corrected half-open endpoint.
        - [UID:0004QU][0x005424b0-0x00542534.TargetOptionDialogOnControlCommand](by-memory/0x005424b0-0x00542534.TargetOptionDialogOnControlCommand.md) 0x005424b0-0x00542534 | method | TargetOptionDialogOnControlCommand : reconstructable : 92% : very strong : Source-ready virtual OnControlCommand accepts control 1, ignores notify code, saves two option rows, slides closed, queues deferred deletion, and calls global SaveUserSettings only when g_activeMapPane is non-null, with exact no-null/no-failure behavior.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00542534-0x00542540 | padding | TargetOptionDialog command to raw save helper alignment : ignored : 100% : strong : Exact twelve 0xcc bytes after the corrected OnControlCommand endpoint.
        - [UID:0004QV][0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw](by-memory/0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw.md) 0x00542540-0x0054259f | retained raw private method | TargetOptionDialogSaveTargetOptionsRaw : reconstructable : 91% : very strong : Source-ready private SaveTargetOptions loops child controls 2/3, copies user/monster bytes into RegistryConfig m_targetOptionRows[0/1], preserves no-null behavior, and records zero modeled function/xref/pointer route plus duplicated inline OnControlCommand behavior as a confidence cap rather than a no-code excuse.
```

- Replace UID00011K row with its already-current page score/detail; no new body claim:

```text
    - [UID:00011K][0x004993b0-0x0049980c.TargetOptionEditControlPane](by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md) : reconstructable : 86% : strong : TargetOptionEditControlPane source-bearing method inventory with exact 0x110 layout, mode dword at +0x108, user/monster bytes at +0x10c/+0x10d, implicit tail padding, dialog constructor caller, ARROW/SHIFT+ARROW labels, paint/input/hit-test/destructor/scalar/adjustor evidence, and TargetOptionDialog.cpp route; its complete class declaration is emitted by UID0000EF while method-body splitting remains a separate inventory concern.
```

- Add absent UID00038I near its exact range:

```text
        - [UID:00038I][0x00542a60-0x00542ab5.TargetOptionDialogScalarDeletingDestructor](by-memory/0x00542a60-0x00542ab5.TargetOptionDialogScalarDeletingDestructor.md) 0x00542a60-0x00542ab5 | scalar deleting destructor | TargetOptionDialogScalarDeletingDestructor : not_reconstructable : 91% : very strong : Compiler-generated TargetOptionDialog scalar deleting destructor covered by the source class/empty ordinary destructor; exact primary-vtable target, two adjustors, three vptr stores, DialogPane teardown, delete flags, size guard, and storage-free route are documented without handwritten ABI source.
```

- Add absent UID0003C9 near the `0x006211c8` range:

```text
    - [UID:0003C9][0x006211c8-0x00621264.TargetOptionDialogVtableData](by-memory/0x006211c8-0x00621264.TargetOptionDialogVtableData.md) 0x006211c8-0x00621264 | vtable data | TargetOptionDialogVtableData : not_reconstructable : 91% : very strong : Compiler-generated primary/secondary/tertiary TargetOptionDialog RTTI/vtable views covered by complete class declarations and source methods; exact scalar/command/adjustor/inherited slots and DLGOPT string successor boundary are documented without handwritten ABI tables.
```

- Replace class rows:

```text
- [UID:0000EE][TargetOptionDialog](by-class/TargetOptionDialog.md) : reconstructable : 92% : very strong : Complete fieldless DialogPane-derived TargetOptionDialog declaration with constructor, empty virtual destructor, OnControlCommand, private SaveTargetOptions, exact four-child split, 0x26c size, three-vtable/scalar/adjustor compiler policy, resources/config/control/lifecycle behavior, and deterministic TargetOptionDialog.cpp source order.
- [UID:0000EF][TargetOptionEditControlPane](by-class/TargetOptionEditControlPane.md) : reconstructable : 90% : very strong : Complete 0x110 ControlPane-derived TargetOptionEditControlPane declaration with constructor/destructor/paint/pointer/key/hit-test methods, mode and user/monster fields, inline accessors, implicit tail padding, exact vtable/layout/row semantics, and paired TargetOptionDialog source route.
```

- Replace file row:

```text
- [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md) : reconstructable : 90% : very strong : NexusTK/ui/dialogs/TargetOptionDialog.cpp source root with complete TargetOptionEditControlPane and TargetOptionDialog declarations, exact target constructor/destructor/OnControlCommand/SaveTargetOptions children, two config rows, DLGSETUP resources, menu caller, control/lifecycle/save ordering, deterministic positions, and compiler-only scalar/thunk/vtable/EH exclusions; by-file root remains prose-only with no reconstruction metadata.
```

- Reason B agent did not apply coverage text directly: manual coverage is supervisor-owned. The real child UIDs now exist and are reflected above, but no manual coverage file was edited by B002.

## Follow-Up Actions

- B002's accepted implementation scope, validators, generated readback, report reconciliation, and lease releases are complete. There is no remaining B002 target/support action or new target in this callback.
- Manual coverage remains supervisor-owned and unapplied by B002; exact synchronized replacement/addition text with real child UIDs is retained above. No A-agent action is requested.
- Current or future Gate 2, manual coverage, report validation, execution, move, archive, count, and lifecycle state are external supervisor/validator-owned and are not asserted or directed by this report.

## Confidence

- Recommendation confidence: very strong (`94`) for target split/behavior/owner; strong for original helper/declaration spelling.
- Score confidence: high. Every named source-quality blocker was resolved and every accepted callback destination was applied or verified same-or-greater; remaining uncertainty is naming/header arrangement only.
- Remaining uncertainty: original spelling of the private helper/accessors, exact private/public/friend arrangement, exact header basename, and why the linker retained the zero-route out-of-line helper copy. None changes the behavior-identical source or metadata route.

## Validator Results

- Scoped command form was `python tools/validator.py --mode file --file <project-relative-path> --apply`; command 000000012482 added `--wait-generated`. Every listed command exited `0` with `ok: 1`.

| Command | Timestamp (`-04:00`) | Scoped file / purpose | Result, warnings, and side effects |
| --- | --- | --- | --- |
| 000000012451 | 2026-07-14T22:54:52 | `by-memory/0x00542270-0x0054248e.TargetOptionDialogConstructor.md`; serial registration | `exit 0`, `ok:1`; assigned UID0004QS, normalized metadata/references, deferred generated refresh; no target-specific warning. |
| 000000012452 | 2026-07-14T22:55:35 | `by-memory/0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor.md`; serial registration | `exit 0`, `ok:1`; assigned UID0004QT; initially warned that UID00038I/UID0003C9 mappings were not registered; later resolved by commands 000000012470/000000012471/000000012474. |
| 000000012453 | 2026-07-14T22:56:27 | `by-memory/0x005424b0-0x00542534.TargetOptionDialogOnControlCommand.md`; serial registration | `exit 0`, `ok:1`; assigned UID0004QU, normalized metadata/references, deferred generated refresh; no target-specific warning. |
| 000000012454 | 2026-07-14T22:57:14 | `by-memory/0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw.md`; serial registration | `exit 0`, `ok:1`; assigned UID0004QV, normalized metadata/references, deferred generated refresh; no target-specific warning. |
| 000000012458 | 2026-07-14T22:59:03 | `by-memory/0x00542270-0x0054259f.TargetOptionDialog.md`; parent split/index | `exit 0`, `ok:1`; applied index/children; initially warned on unregistered UID00038I, later resolved by commands 000000012470/000000012475. |
| 000000012463 | 2026-07-14T22:59:48 | `by-memory/-ignored.md`; three target gaps | `exit 0`, `ok:1`; target rows applied; broad shared-file output reported 285 pre-existing missing-reference warnings with 275 suppressed, no UID0001E2-specific error; generated refresh deferred. |
| 000000012467 | 2026-07-14T23:00:40 | `by-class/TargetOptionEditControlPane.md`; Destination 6 | `exit 0`, `ok:1`; exact class block/metadata applied; generated refresh deferred; no target-specific warning. |
| 000000012468 | 2026-07-14T23:01:38 | `by-class/TargetOptionDialog.md`; Destination 7 initial pass | `exit 0`, `ok:1`; exact class block/metadata applied; initially warned on unregistered UID00038I/UID0003C9, later resolved by commands 000000012470/000000012471/000000012476. |
| 000000012470 | 2026-07-14T23:02:31 | `by-memory/0x00542a60-0x00542ab5.TargetOptionDialogScalarDeletingDestructor.md`; Destination 8 | `exit 0`, `ok:1`; registered existing UID00038I path and applied non-emitting metadata/no-code proof; initial UID0003C9 warning later resolved. |
| 000000012471 | 2026-07-14T23:03:39 | `by-memory/0x006211c8-0x00621264.TargetOptionDialogVtableData.md`; Destination 9 | `exit 0`, `ok:1`; registered existing UID0003C9 path and applied non-emitting metadata/no-code proof; no target-specific warning. |
| 000000012472 | 2026-07-14T23:05:14 | `by-file/TargetOptionDialog.md`; Destination 10 initial pass | `exit 0`, `ok:1`; prose-only `90/91` update, no reconstruction metadata; ordinary generated-stat row/remove side effect, deferred generated refresh. |
| 000000012473 | 2026-07-14T23:06:00 | `by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md`; Destination 11 | `exit 0`, `ok:1`; position 10 and bounded class-contract support applied; blank broad-aggregate formal C++ preserved. |
| 000000012474 | 2026-07-14T23:07:10 | UID0004QT destructor child final reference pass | `exit 0`, `ok:1`; prior UID00038I/UID0003C9 missing-reference warnings resolved; no target-specific warning remains. |
| 000000012475 | 2026-07-14T23:07:31 | UID0001E2 parent final reference pass | `exit 0`, `ok:1`; UID00038I reference resolved; no target-specific warning remains. |
| 000000012476 | 2026-07-14T23:07:48 | UID0000EE class final reference pass | `exit 0`, `ok:1`; UID00038I/UID0003C9 references resolved; no target-specific warning remains. |
| 000000012477 | 2026-07-14T23:08:05 | UID00038I scalar support final reference pass | `exit 0`, `ok:1`; UID0003C9 reference resolved; no target-specific warning remains. |
| 000000012478 | 2026-07-14T23:08:47 | UID0001E2 final wording/readback pass | `exit 0`, `ok:1`; final index wording and real child links accepted; generated refresh deferred. |
| 000000012480 | 2026-07-14T23:09:17 | UID0000EE final wording/readback pass | `exit 0`, `ok:1`; final declaration/inventory wording accepted; generated refresh deferred. |
| 000000012481 | 2026-07-14T23:09:45 | UID0000OG by-file final wording/readback pass | `exit 0`, `ok:1`; final prose-only source contract accepted; no reconstruction metadata introduced. |
| 000000012482 | 2026-07-14T23:10:18 | UID0000OG final `--wait-generated` pass | `exit 0`, `ok:1`; waited generation completed and refreshed 281 generated metadata entries. Global summary retained 14 fallback-insert, 86 marker-missing, and 173 emitter-no-code warnings from broad pre-existing project state; no TargetOptionDialog-specific error or unresolved reference remained. |

- Generated readback: `auto-generated/NexusTK/ui/dialogs/TargetOptionDialog.cpp`, command 000000012482, SHA256 `59DEFD4D9DAB3A5A7C7DF3996A29BBF5BCFDC36E419B713BBFCBA1C0582CB33F`. Exact order is TargetOptionEditControlPane class line 8, TargetOptionDialog class line 39, `InitRectBounds` declaration line 51, constructor line 57, ordinary destructor line 97, `SaveUserSettings` declaration line 102, `OnControlCommand` line 104, and `SaveTargetOptions` line 118.
- Exact uniqueness/absence proof: both classes and all four methods count 1; both external declarations count 1 and precede first use; UID0001E2/UID0000EE/UID0000EF Empty Emitter Marker counts are 0; UID00011K Empty Emitter Marker count is 1 and is the intentional separate unsplit support inventory at line 135; scalar-deleting/adjustor/vtable/RTTI handwritten-source counts are 0. Project-wide readback finds the sole `SaveUserSettings` definition in `auto-generated/NexusTK/profile/ProfileStorage.cpp` lines 416-417; the TargetOptionDialog occurrence is declaration-only.
- MCP client-parameter mistakes ids 113/115 remain documented under Evidence Checked and were corrected with successful bounded calls; they are not validator results or infrastructure failures.

## Changed Files

- Created ordinary children: UID0004QS `by-memory/0x00542270-0x0054248e.TargetOptionDialogConstructor.md` (`58E5DFED227AD15D9C99AF42A55DD34A183C4B0A9C654DFB4C5899EF0686C79A`); UID0004QT `by-memory/0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor.md` (`FB446329BEB07F10035E9898AC3901DBDABA2644CA76759E20CDEEFD729F650D`); UID0004QU `by-memory/0x005424b0-0x00542534.TargetOptionDialogOnControlCommand.md` (`DFD998236283608CCEC1DC7FAEECA57E473DC034DE60E1A00348A370005CD7EA`); UID0004QV `by-memory/0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw.md` (`ED8B6AE65C77C6E33C7D62C7F0E8B55FEDE17E4CA2B2285D99773FFF6D5B95C7`).
- Modified existing ordinary pages: UID0001E2 target (`2BBFC746DCA114A002AEDD05285761C1AEB9E715571296351346A8091E120781`); UID0000EF class (`DB96F9B9904BADC451584066206EA23B2D78277F94A343CFDAA621E17CC96E5F`); UID0000EE class (`43D575B0E9637AD2A62235E584DAEDFAC38F75D80432DAF3E01EA1F3D901F051`); UID00038I scalar support (`82EE33D10BCABC6BBB3C96DCC83FBA6D21CFD2ADF6FC60B4012FC8B18AB0D190`); UID0003C9 vtable support (`F78C214C4AD227D20DA6DED4A5CEC5E1C3D80FB67FFD0980B07DABEC04E6876F`); UID0000OG by-file prose (`737452100F260CE0FC2085CB7250D324627A790CE1E2B3DD0A48A851C0DEA8C2`); UID00011K aggregate support (`578D3B8AA4B681E90FB25E3EED926A36908275874FCBF4162CC9A07F0BDD3BBB`); and shared `by-memory/-ignored.md` current readback (`9D9EC5C0D156C66522845F07F0679FC09AFD45A35B55CE6BDE54C11037445D7C`), whose three target intervals remain exact after unrelated concurrent additions.
- Modified agent-local artifact: this same report. Renamed ordinary/report files: none.
- Verify-only, unchanged after readback: UID0001VR, UID0001AV, DialogPane, ControlPane, EPFImageControlPane, ImageButtonControlPane, RectBounds/UID00015S, BlackHole, accepted globals, UID00023J, and UID00023K.
- Leases: existing ordinary pages were leased one at a time only for their immediate edit/scoped-validator batch; new children were created/registered under the parent split lease because they did not yet exist. Every lease was released immediately. Final read-only `tools/leaser/Agents/current_leases.md` contains no B002 entry.
- Generated output was changed only by authorized validator command 000000012482, never manually. IDA was not mutated.
- Restricted/manual/generated/coverage/tracker/audit/supervisor/validator-state/lifecycle files were not manually edited. No execute_report, report lifecycle/probe/count, move, or archive command was run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact pre-callback SHA `6B83DFA235E514A9BFE05F68D1CC7FF86DD9FA1F2004B2DF12F47AA2D4DC307C` before implementation.
- [x] Destinations 1-11 were identified as edit scope; Destinations 12-14 were identified as verify-only unless concrete drift.
- [x] Evidence-time target/support/generated/manual-coverage state and live IDA evidence were recorded at full research depth.
- [x] Initial report-only ledger used only permitted Action values and `proposed` states; this callback artifact now carries legal terminal states and destination proof for all C01-C30.
- [x] Exact metadata/score/owner/emitter/split/position/formal-C++ matrix and all score blockers were resolved before callback.
- [x] Four child ranges, three padding rows, source placement, range/reclassification, IDA recommendations, nine managed blocks, cross-source declarations, and no-code proofs were complete before callback.
- [x] Third-party import was correctly excluded; no third-party static embed is involved.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, and non-authoritative Wave2/Wave3 exclusions were preserved.
- [x] Open questions were resolved or retained only as explicit confidence caps.
- [x] Exact supervisor-owned manual coverage text and callback validator/generated expectations were recorded.
- [x] Initial fixed-matrix self-review passed: required headings, C01-C30 atomic ledger, legal Action vocabulary, nine balanced managed blocks, complete split inventory, exact coverage text, and unchecked callback items.

Implementation callback pass:
- [x] Exact Gate-1-passed report was used for this authorized implementation callback.
- [x] Four children were registered serially as UID0004QS/UID0004QT/UID0004QU/UID0004QV; no placeholder remains in current report text or ordinary docs.
- [x] Destinations 1-11 and C01-C30 were applied at report-level detail; Destinations 12-14 were re-read and verified same-or-greater without edits.
- [x] Ledger contains 30 legal terminal rows with claim-specific destination/validator/generated proof; metadata, score, ownership, emitter, split, position, and formal C++ are applied or explicitly excluded with reason.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, provenance, and evidence-time snapshots are preserved and labeled.
- [x] Open questions are resolved or retained only with evidence-backed confidence impact; no implementation blocker remains.
- [x] One short lease covered only the ordinary page under immediate edit/validation; new children used the parent split lease; each lease was immediately released and final lease readback has zero B002 entries.
- [x] Scoped validators 000000012451-000000012481 all exited 0 with `ok:1`; warnings and side effects are recorded above, including resolved temporary reference warnings and shared-file pre-existing warnings.
- [x] Final waited command 000000012482 exited 0 with `ok:1`; SHA/order/count/declaration/definition/marker/ABI assertions are recorded above.
- [x] Manual supervisor-owned coverage remained unapplied by B002 and its exact report text is synchronized to real child UIDs.
- [x] No accepted B002 callback item remains unapplied; C27/C29 are excluded-with-reason because manual coverage and lifecycle are supervisor-owned.
- [x] No execute_report, lifecycle/probe/count, move, archive, manual generated/coverage/tracker/audit/supervisor/validator-state edit, or IDA mutation occurred.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000012535","destination_path":"executed-b-agent-research/B002/0001E2-TargetOptionDialog-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001E2-TargetOptionDialog-source-quality.md","timestamp":"2026-07-14T23:38:01-04:00","uid":"0001E2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
