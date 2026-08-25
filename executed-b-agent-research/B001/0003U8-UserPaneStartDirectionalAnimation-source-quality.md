** TARGET-REPORT-UID:0003U8 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003U8 UserPaneStartDirectionalAnimation Ownership / Source-Quality Research


## Finalized Report / Current Recommendation

- Current implementation: UID0003U8 is one source-authored `UserPane::StartDirectionalAnimation(char direction)` member at `[0x005a3770,0x005a386a)`, emitted by UID0000FQ through UID0000P1 into `NexusTK/ui/panels/UserPane.cpp`.
- Final disposition is applied and validated: reconstructable true, owner/emitter UID0000FQ, blank position, `Nested:0`, no split, no compiler/no-code treatment, and score `92/94`.
- Callback result: Destination 1 is installed; Destinations 2-4 are synchronized; the six-byte successor alignment is present in UID0000VN; all accepted target/support evidence and historical corrections are incorporated.
- Confidence: very strong for range, bytes, CFG, two callers, ABI, receiver fields, branch identity, call targets, side-effect order, timer payload, source route, and exact C++ behavior; strong for stripped private method/field spellings.
- Current artifact state: B001 completed the authorized implementation callback and released every lease. B001 performed no `execute_report`, report lifecycle, count/probe, move, or archive command. Report validation/execution/count/path/archive state remains external supervisor/validator-owned state and is neither asserted nor directed here.

## Supporting Research

- Assignment source: `tools/leaser/Agents/Agent-B001/goal.md`, tracker `auto-generated/-ag-research-tracker.md`, `## by-memory` / `### Not-Covered Files - Reconstructable`. The assignment-time row is UID0003U8 `86/88`, reconstructable true, direct report count zero, immediately after UID0003TC.
- Healthy evidence session: B001 initialized streamable MCP, called `idb_list`, and received the sole NexusTK IDB worker/session `01f84d61`. At the evidence checks on 2026-07-15, `server_health(database=01f84d61)` returned `status:ok`, image base `0x00400000`, and analysis, Hex-Rays, and string cache ready. Bounded `get_bytes`, lookup, decompile, disassembly, xref, callee, and basic function checks succeeded against that session. This is evidence-time health, not an indefinite availability claim.
- Current target documentation read: UID0003U8; owner UID0000FQ UserPane; file UID0000P1 UserPane; aggregate UID0001KM; predecessor UID0003U7; successor UID0003U9; UID00007B LivingObjectPane; UID00009S ObjectStatusBlob; UID0004QG SetMovingState; UID0002R1 LivingObjectPaneAnimationTimer; UID0004DS MapPaneUpdateObjectPaneScreenBounds; UID0002CF/UID00027F movement scale; UID0001CM MonsterImageLibTables; UID0001VC MonsterImageEntry; UID00008N MonsterImageLib; UID0000RR g_pMonsterImageLib; UID0000LK MonsterImageLibTables file; UID0000PR g_activeMapPane; and `by-memory/-ignored.md`.
- Active/current-agent report-root search checked `tools/leaser/Agents/Agent-B001..B015/research` with UID, address, IDA name, target name, source-family, owner, timer, image-table, and movement-scale terms. No active direct UID0003U8 target report was found.
- Executed root checked: `executed-b-agent-research/**`. Exact/direct or material support reports opened and classified:
  - `executed-b-agent-research/B001/0002QY-MotionAnimationTimerTick-empty-emitter-source-quality.md`: direct target owner/route/body integration, but not an independent target reanalysis. Its UID0003U8 `86/88`, `unsigned char`, HumanObject, `g_pObjectImageLib`, merged ordering, and stale frame types are superseded by the direct evidence in this report.
  - `executed-b-agent-research/B004/0003U7-UserPaneInitializeWalkAnimation-source-quality.md`: predecessor boundary and bounded target support. Its `m_displayStatusByte`, signed scale, exact MapPane callee, and UserPane route remain useful. Its statement that UID0003U8 selects a human-image group was independently contradicted by `cmp [this+0x178],1` plus `g_pMonsterImageLib` and is rejected for this target.
  - `executed-b-agent-research/B001/0003U6-UserPaneProcessMovement-source-quality.md`: direct normal-movement caller, exact predecessor/source order, and UserPane layout support; not a target substitute.
  - `executed-b-agent-research/B007/0002R1-LivingObjectPaneAnimationTimer-source-quality.md`: timer, PlayFacingAnimation, frame-step, and adjusted TimerHandler leads. Its old `ImageFrameGroup`/`g_pObjectImageLib`/HumanObject formal vocabulary was contradicted by direct target and PlayAnimation evidence; the accepted callback applied the required bounded synchronization.
  - `executed-b-agent-research/B001/0002CF-g_movementSubstepScale.md`: 23-reader signed-scale lead and exact target reader address; later B004 correction to file-static plain `char` is current.
  - `executed-b-agent-research/B006/0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality.md`: successor boundary and six-byte alignment lead; no target behavior coverage.
  - `executed-b-agent-research/B001/0001KM-livingobject-localplayer-source-split-retry.md` and `...split-audit.md`: historical aggregate/source-family context. Their LivingObjectPane ownership implications are superseded by the executed UserPane rebase.
  - `executed-b-agent-research/B001/00007B-LivingObjectPane-class-source-quality.md`, `.../00024A-UserPaneVirtualDword1340F8Accessor-source-quality.md`, `.../0003Z4-LivingObjectPaneLinkedObjectSetupHelpers-source-quality.md`, and `executed-b-agent-research/B005/0004DS-MapPaneUpdateObjectPaneScreenBounds-source-quality.md`: current layout/helper corroboration, not direct target reports.
- Historical roots explicitly searched: `tools/leaser/Agents/Older-Research/**`, `tools/leaser/Agents/SpecialReports/**`, and `source-3/project-documentation/archived/**`. Older-Research had no direct target match; the incidental TimerMgr/UserPane term match was unrelated. SpecialReports had no match. The archive root contained no direct target report. The explicit no-direct-standalone-report conclusion remains: prior work touched UID0003U8 only as aggregate/support integration.
- Historical generated evidence: `auto-generated/NexusTK/ui/panels/UserPane.cpp`, validator header command `000000012699`, SHA256 `DDE87CCDC7700348665C170FF768C18909CF4636125EF77B46E3152AA3856EEA`. At 2026-07-15T02:52-04:00 it emitted UID0003U8 once but retained the wrong HumanObject branch, `ImageFrameGroup`, `g_pObjectImageLib`, `frame->delay`, one merged `SetMovingState`, and no branch-local second `m_moveFrame` reset. Those defects are superseded by the callback implementation and current generated proof below.

## Target

- Target UID: `0003U8`.
- Target path: `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md`.
- Source queue/report row: by-memory Not-Covered Files - Reconstructable; assignment-time `86/88`, reconstructable true, direct report count zero. This is historical assignment provenance, not current queue/count state.
- Callback classification: supervisor-authorized implementation after exact-artifact Gate 1 acceptance.
- Current scores and parent state: `92/94`, owner/emitter UID0000FQ UserPane, reconstructable true, blank position, `Nested:0`, and exact binary-faithful formal C++.

## Current Target State

- Current metadata: exact UID/range, owner/emitter UID0000FQ, reconstructable true, blank position, and `Nested:0` are preserved; score `92/94` is applied.
- Current owner/emitter/reconstructable state: UserPane is the direct class/file route. LivingObjectPane is documented only as the base and inherited field/helper provider.
- Current C++/emitter state: Destination 1 is installed and binary-faithful. It uses MonsterObject, `g_pMonsterImageLib`, accepted entry/group/frame types, signed duration, branch-specific order, the second non-monster frame reset, signed plain-char parameter, and two branch-local map calls.
- Blockers resolved and implemented: exact status branch, image library/global, entry/group/frame types, frame-duration signedness, direction ABI, event and argument order, duplicate state writes, final MapPane helper, return type, source owner, source file, padding, no-split decision, and score.
- Related target/support docs checked: all pages listed under Supporting Research and Recommended Support Doc Changes.
- Current artifact/lifecycle status: ordinary implementation and validators are complete and recorded below. B001 performed no report execution/lifecycle/count/probe/move/archive action; external validator-owned state is not inferred.

## Executive Recommendation

- Retain one exact UserPane member. Do not split, merge, rename the path, move it to LivingObjectPane/MonsterImageLib/MapPane/TimerMgr, or suppress it as compiler-generated.
- Use `void UserPane::StartDirectionalAnimation(char direction)`. `char` is the strongest ABI type because `0x005a3774` uses `movsx` directly on the one-byte stack parameter and the signed value feeds `direction + 5` and TimerMgr arg0. Valid callers supply direction values in the normal small direction domain; no normalization or unsigned hardening appears.
- The `statusKind == 1` branch is MonsterObject. It reads `g_pMonsterImageLib`, subtracts `0x8000` from `m_appearanceId`, resolves `MonsterImageEntry -> ImageAnimationGroup -> ImageAnimationFrame`, sign-extends `frameDuration`, starts facing animation, cancels box rotation, schedules user event 20, then calls `SetMovingState(true)` and MapPane bounds refresh.
- The non-monster branch calls `SetMovingState(true)` before reading the display-status delay, explicitly clears `m_moveFrame` again, divides `m_displayStatusByte` by signed file-static `g_movementSubstepScale` without a guard, schedules event 20, and refreshes bounds.
- Raise only the target to `92/94`. Preserve all support scores/routes unless explicitly listed; the support pass corrects contracts rather than inflating unrelated pages.

## Supervisor Active Recheck

- The supervisor assigned the next unique tracker row UID0003U8 after UID0003TC and required a fresh target-specific xHigh pass with mandatory MCP.
- No split repair is required inside `[0x005a3770,0x005a386a)`. The six all-`cc` bytes after the function are external successor alignment and belong only in UID0000VN `-ignored` documentation.
- Every source-bearing item triggered by the target has an exact disposition: target body and declaration are formal Destinations 1-2; shared frame type is Destination 3; the contradictory LivingObjectPane animation/timer support is Destination 4; remaining support changes are prose/evidence synchronization with no blank source-bearing body left by this assignment.

## Inference Research Guidance Check

- `by-structure.md` and the workflow evidence ladder were applied: exact function bytes/CFG/calls first, then current type/layout pages, then callers and source-family ordering, then source-facing inference.
- Existing documentation assumptions were treated as challengeable. In particular, nonblank generated C++ was not accepted as proof; the HumanObject branch and object-image API were directly disproven.
- IDA facts: range, bytes, instruction sequence, offsets, calls, xrefs, sign-extension, and padding. Documentation facts: accepted class layouts, enum value 1 = MonsterObject, existing globals/types, and source routes. Inferences: private method spelling `StartDirectionalAnimation`, field/type lexical spellings, and source-header include arrangement.
- Wave2/Wave3 artifacts were searched only as historical leads. No current explicit override authorizes stale Wave conclusions, and none controls this recommendation.

## Heuristic / Inference Reanalysis And Validation

- Generated method name: `StartDirectionalAnimation` is descriptive rather than symbol-recovered, but it is already synchronized in the UserPane declaration, two live callers, target path, and source family. `BeginMovementAnimation`, `StartMonsterMovementAnimation`, and `ScheduleDirectionalStep` are weaker because the method supports both monster and non-monster delays and is called both from ProcessMovement and animation-step retry.
- Receiver type: `m_mapPane` at `+0x1340f8` and movement token bytes at `+0x13eaf2/+0x13eaf4` are beyond the `0x20c` LivingObjectPane base. This proves UserPane source ownership even though many fields/helpers are inherited.
- Parameter ABI: target `movsx ebx,byte ptr [arg_0]` is direct one-byte signed use. `char` is preferred over `unsigned char`; unlike the predecessor's store-focused use, this method performs signed arithmetic and forwards the sign-extended value. `signed char` is machine-equivalent but less consistent with the project's plain-char signed scalar convention.
- Return type: both callers ignore EAX. The apparent decompiler return of MapPane's call is the residue of a final call in a `void` method, not a meaningful source return.
- Status enum: machine compares dword `+0x178` to 1 and enters the image-table branch only on equality. UID00009S defines 1 as MonsterObject; HumanObject is 0. The global read from `0x0069b440` independently identifies the branch as monster-image logic.
- Image entry: `0x004db330` is `MonsterImageLib::GetEntryByIndex(int)`, returning `m_monsters + 12*index` when index is below count, otherwise fallback row `0x0069b424`.
- Group/frame types: `0x00528af0` selects an 8-byte `ImageAnimationGroup`; `0x00528d00` selects a 10-byte `ImageAnimationFrame` or fallback. Existing neutral shared names are stronger than the stale `ImageFrameGroup`/`ImageFrame` aliases.
- Frame duration: target at `0x005a37dd`, PlayAnimation at `0x0053b78f`, construction/setup callers `0x0053a30b` and `0x0053aaae`, and animation timer at `0x0053ba59` all consume frame word `+2` through signed `__int16`/`movsx`. The canonical declaration should be `short frameDuration`, not `unsigned short`.
- Initial state: machine sets `m_isMoving` directly before either branch, clears the two-byte movement token and direction-delay byte, and clears `m_moveFrame`.
- Monster ordering: frame delay is read, `PlayFacingAnimation` runs, `CancelBoxRotationStep` runs, TimerMgr schedules event 20, then `SetMovingState(true)` runs, then MapPane refreshes. A merged post-branch `SetMovingState` changes this order and is rejected.
- Non-monster ordering: `SetMovingState(true)` runs first, then display status is loaded, then `m_moveFrame` is explicitly cleared a second time, then signed division and scheduling occur. The duplicate clear is retained because `SetMovingState(true)` itself does not clear the frame; only false does.
- Timer contract: scheduler receiver is inherited `TimerHandler` facet `this + 0xa4`; event is decimal 20 / `kUserPaneMovementStep`; delay is signed frame duration or integer division result; arg0 is sign-extended direction; arg1 is zero.
- Scale: `g_movementSubstepScale` is file-static plain `char`, initialized to 1, and loaded with `movsx`; target performs `movzx` status, `movsx` scale, `cdq`, `idiv`. No zero guard, clamp, absolute value, or fallback is allowed.
- Final map call: both branches independently call `0x00506980` through UserPane `m_mapPane`. Current UID0004DS identifies it as `UpdateObjectPaneScreenBounds(ObjectPane *)`; generic `InvalidateObject` is rejected.
- Source placement: exact address order follows ProcessMovement and InitializeWalkAnimation and precedes inventory access. UserPane.cpp is the coherent owner. MonsterImageLibTables is a shared dependency source, not the target owner.
- Range: exact one-function range, no EH, cookie, switch table, vtable, callback table, internal data, or internal padding.
- Rejected alternatives: HumanObject branch, generic nonhuman branch label without enum resolution, `g_pObjectImageLib`, `GetFrameGroup`, `ImageFrameGroup`, `ImageFrame`, `delay`, unsigned frame duration, unsigned target parameter, one merged `frameDelay`, one merged SetMovingState/schedule/map tail, omitted second reset, LivingObjectPane ownership, MonsterImageLib ownership, MapPane ownership, TimerMgr ownership, compiler/no-code disposition, split, and a new standalone source file.
- Unresolved source evidence: original private lexical spellings and include filenames are stripped. They cap confidence below 95 but do not block behavior, declaration, route, or formal C++.

## Evidence Standards Used

- Primary: live MCP exact bytes, function lookup, disassembly, Hex-Rays output, xrefs, callees, and bounded neighboring checks.
- Secondary: current by-* layouts, enums, globals, helper identities, generated readback, tracker/manual coverage, and executed reports used as leads.
- Negative: no data/vtable/callback route to target, no split body, no EH/cookie, no alternate global, no current direct report, and no source-owner evidence for competing modules.
- Strength: all behavior-critical facts are direct binary observations corroborated by current declarations. Only original private names and header organization remain inference.
- Tool limitations: an initial local PowerShell request required `-UseBasicParsing`; no IDB call occurred. One malformed local `server_health` payload omitted `database` because `$args` was used as a PowerShell variable name and was rejected before evidence use. One local byte-hash parser initially ignored one-digit byte tokens; corrected parsing recovered all 250 bytes and the hashes below. No conclusion uses the malformed payload or discarded hash.

## Evidence Checked

- MCP calls against evidence-time database `01f84d61`: `idb_list`; `server_health`; `lookup_funcs` for `0x005a36f0`, `0x005a3770`, and `0x005a3870`; target `get_bytes`/`analyze_function`/`decompile`/`disasm`; `xrefs_to(0x005a3770)`; target `callees`; caller-window disassembly at `0x005a3607` and `0x005a8796`; `decompile(0x004db330)`; `xrefs_to(0x00528d00)`; and bounded decompile/disassembly of all five GetFrame callers.
- Exact byte hashes: target 250 bytes SHA256 `5ECA3299C0462C97F9AFF071B6ECD85207BC1D5782F919DDB3C84E39D3E0010D`; predecessor padding 10 bytes SHA256 `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`; successor padding 6 bytes SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`; successor UID0003U9 first 25 bytes SHA256 `3736F957C7035585B89F8B9394F4AF68CDA6BB7B99415B25A2DA8EE7EC91E824`.
- Current ordinary hashes at evidence time: target `2D32082CD06C6EB86349ABC11FF6704BE90C2272DC111CCEE88B6AF31107C237`; UserPane class `4D456A312DF68B1C8E3F24EC7F8066EC20C937B5089E64463DC126AF2147DA0E`; UserPane file `2DD547743B396369F0B1A6ADB7176AEA9DC9C680CB06CE1F24287AF8CEDD480F`; UID0001CM `BE77165EA411C09753639DE3A2FB29E926E35073D06DD3359C04EE75D3BFCB9E`; UID0002R1 `DA7CBCC5F5BE3DF475590708D0F229BEA4877AFB06072D84D42798899A0F803A`; UID0001VC `8B0AA6529920167DF8D6B2A54AD42830DEA0C425ECD713F7869871D7846BEC62`; UID0000LK `929DEA87E24619880BB962BE2B4E0C0256CA32C553863F3CE46FA0ACB66283DC`; UID00008N `D9BC438FD43A79F39A944104E39F0A29DE302AC13C18AB73CA3FE29C55F2BCBD`; UID0000RR `32798A03A3D3202DD53E527E6FCFE7F5A094BFD72E9FC5878F6EE43FCB40E148`; UID0000VN `59D3B77357D6D7B58367A6E26768608E0915B692568B06F64ED6F7599DF49232`.
- Read-only manual coverage checks: by-memory rows UID0003U8, UID0001CM, UID0002R1, UID0003U7, UID0003U9, and UID0000VN placement; by-file rows UID0000P1/UID0000LK; by-class rows UID0000FQ/UID00008N; by-type/by-struct rows UID0001VC/UID0001VV.
- Negative checks: target has exactly two code xrefs and no data/vtable route; target contains no internal padding/table/EH/cookie; no direct historical report; no evidence for HumanObject/object-image route; no use of a target return value.
- Historical report-only boundary: before Gate 1, no IDA mutation, validator, lease, queue, lifecycle, execute_report, generated refresh, or manual coverage edit was allowed. The accepted callback later used only the permitted short leases, scoped validators, and waited generated refresh; B001 made no IDA, queue, manual coverage, execute_report, lifecycle, move, or archive mutation in either phase.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C3U8-001 | Exact target range is `[0x005a3770,0x005a386a)`, 250 bytes. | High | lookup, bytes, return endpoint | UID0003U8 range/evidence | incorporate | applied |
| C3U8-002 | Exact target-byte SHA256 is `5ECA...010D`. | High | corrected 250-byte hash | UID0003U8 evidence | incorporate | applied |
| C3U8-003 | Target is one three-block/two-terminal-return method with one status branch. | High | analyze/disasm | UID0003U8 CFG | incorporate | applied |
| C3U8-004 | No internal split, EH, cookie, table, or compiler-only subrange exists. | High | bytes/disasm/negative scan | UID0003U8 disposition | reject-invalid | excluded-with-reason |
| C3U8-005 | UID0003U7 ends at `0x005a3766`; the ten-byte predecessor alignment is already present. | High | lookup/bytes/current ignored row | UID0003U8 boundary | already-present | already-present |
| C3U8-006 | `[0x005a386a,0x005a3870)` is six all-`cc` successor alignment bytes. | High | bounded bytes/hash | UID0000VN / coverage insertion | incorporate | applied |
| C3U8-007 | Successor UID0003U9 begins exactly at `0x005a3870`. | High | lookup/bytes | UID0003U8 boundary | incorporate | applied |
| C3U8-008 | Source signature uses one signed plain-char direction parameter. | High | `movsx` at `0x005a3774` | UID0003U8 and UID0000FQ formal | reject-stale | applied |
| C3U8-009 | Source return is `void`; callers ignore EAX. | High | two caller windows | UID0003U8 formal/ABI | reject-stale | applied |
| C3U8-010 | Exactly two direct callers exist at `0x005a3607` and `0x005a8796`. | High | xrefs_to | UID0003U8 caller inventory | incorporate | applied |
| C3U8-011 | No data/vtable/callback reference to target exists. | High | xref negative result | UID0003U8 negative evidence | incorporate | applied |
| C3U8-012 | UserPane, not LivingObjectPane, is direct source owner. | High | derived-only offsets/callers | UID0003U8 current/status/history | reject-stale | applied |
| C3U8-013 | UID0000P1 UserPane.cpp is the source route. | High | owner chain/source order | UID0003U8/UID0000P1 | already-present | already-present |
| C3U8-014 | Initial direct write sets `m_isMoving = true`. | High | `0x005a3782` | UID0003U8 behavior/formal | incorporate | applied |
| C3U8-015 | Initial word/byte writes clear movement token and direction-delay state. | High | `0x005a3789/3792` plus UserPane helpers | UID0003U8 behavior/formal | already-present | already-present |
| C3U8-016 | Initial `m_moveFrame = 0` is exact. | High | `0x005a3799` | UID0003U8 behavior/formal | already-present | already-present |
| C3U8-017 | Image-table branch is exactly MonsterObject (`statusKind == 1`). | High | compare/jnz, UID00009S enum, global | UID0003U8 and UID0002R1 | reject-stale | applied |
| C3U8-018 | Monster animation group is signed `direction + 5` and stored at `+0x1cc`. | High | `0x005a37a3-37a6` | UID0003U8 behavior/formal | incorporate | applied |
| C3U8-019 | Global `0x0069b440` is `g_pMonsterImageLib`, not object-image library. | High | operand and UID0000RR | UID0003U8/UID0000RR | reject-stale | applied |
| C3U8-020 | Monster index is zero-extended appearance ID minus `0x8000`. | High | `0x005a37b3-37bf` | UID0003U8 behavior | incorporate | applied |
| C3U8-021 | `0x004db330` is bounds-checked `GetEntryByIndex` with fallback. | High | direct decompile/current class docs | UID0003U8/UID00008N | incorporate | applied |
| C3U8-022 | `0x00528af0` selects `ImageAnimationGroup`. | High | helper decompile/current UID0001CM | UID0003U8/UID0001CM | reject-stale | applied |
| C3U8-023 | `0x00528d00` selects `ImageAnimationFrame` by signed `m_moveFrame`. | High | disasm/helper docs | UID0003U8/UID0001CM | reject-stale | applied |
| C3U8-024 | Frame `+2` is signed `short frameDuration`. | High | five sign-extending consumers | UID0001CM/UID0001VC/support prose | reject-stale | applied |
| C3U8-025 | Monster path calls PlayFacingAnimation after reading delay. | High | `0x005a37dd-37e1` | UID0003U8 behavior/formal | already-present | already-present |
| C3U8-026 | Monster path then cancels box-rotation event. | High | `0x005a37e8`, helper docs | UID0003U8 behavior/formal | already-present | already-present |
| C3U8-027 | Monster TimerMgr call uses handler `this+0xa4`, event 20, frame delay, direction, zero. | High | push sequence `0x37ed-3800` | UID0003U8 behavior/formal | incorporate | applied |
| C3U8-028 | Monster path calls SetMovingState only after scheduling. | High | `0x005a3800-3809` | UID0003U8 behavior/formal | reject-stale | applied |
| C3U8-029 | Non-monster path calls SetMovingState before delay computation. | High | `0x005a3821-3828` | UID0003U8 behavior/formal | reject-stale | applied |
| C3U8-030 | Non-monster delay numerator is ObjectStatusBlob `m_displayStatusByte`. | High | `movzx [this+0x1a0]`, layout | UID0003U8 behavior/formal | already-present | already-present |
| C3U8-031 | Non-monster path explicitly clears `m_moveFrame` a second time. | High | `0x005a382f` | UID0003U8 behavior/formal | incorporate | applied |
| C3U8-032 | Scale read is signed plain `char`; division is unguarded signed IDIV. | High | `movsx/cdq/idiv` | UID0003U8 behavior/negative evidence | already-present | already-present |
| C3U8-033 | Non-monster TimerMgr payload is event 20, quotient, direction, zero. | High | `0x005a3840-3853` | UID0003U8 behavior/formal | incorporate | applied |
| C3U8-034 | Both branches call exact UID0004DS through `m_mapPane`. | High | calls `0x3816/385f` | UID0003U8 behavior/formal | already-present | already-present |
| C3U8-035 | Branch-local map calls and monster return are the strongest exact source shape. | High | duplicated terminal blocks/order | UID0003U8 formal | incorporate | applied |
| C3U8-036 | `StartDirectionalAnimation` remains best source-facing private name. | Medium-high | caller role/sibling naming | UID0003U8 title/declaration | already-present | already-present |
| C3U8-037 | Destination 1 is the exact replacement target block. | High | complete evidence chain | UID0003U8 formal | incorporate | applied |
| C3U8-038 | Destination 2 changes only the UserPane declaration contract for this target. | High | ABI/declaration synchronization | UID0000FQ formal | incorporate | applied |
| C3U8-039 | Destination 3 changes shared frame duration from unsigned to signed short. | High | complete five-reader audit | UID0001CM formal | incorporate | applied |
| C3U8-040 | Destination 4 synchronizes PlayAnimation/OnTimer with MonsterObject and accepted table types. | High | direct supporting disassembly | UID0002R1 formal | reject-stale | applied |
| C3U8-041 | UID0001VC/UID0001VV/UID0000LK/loader prose must use signed 16-bit duration. | High | canonical type synchronization | listed support pages | reject-stale | applied |
| C3U8-042 | UserPane file docs must record MonsterImageLibTables/MonsterImageLib header dependencies. | Medium-high | source-legal include route | UID0000P1 | incorporate | applied |
| C3U8-043 | MonsterImageLib class/global pages gain this exact live consumer and GetEntryByIndex role; no score/formal change. | High | operand/call evidence | UID00008N/UID0000RR | incorporate | applied |
| C3U8-044 | UID0001KM child inventory must carry corrected target behavior, not old Human-object wording. | High | aggregate index consistency | UID0001KM | incorporate | applied |
| C3U8-045 | No target split/new child/source file/position change is justified. | High | one-function/source order evidence | UID0003U8 metadata | reject-invalid | excluded-with-reason |
| C3U8-046 | Target score becomes `92/94`. | High | all named blockers closed | UID0003U8 header/coverage | incorporate | applied |
| C3U8-047 | Owner/emitter UID0000FQ, TRUE, blank position, and `Nested:0` remain. | High | current route/hierarchy | UID0003U8 metadata | already-present | already-present |
| C3U8-048 | Item Summary/current prose must describe exact monster/non-monster paths and remove stale parent/body claims. | High | generated/manual rules | UID0003U8 prose | reject-stale | applied |
| C3U8-049 | Historical UID0002QY/B004 assumptions remain only as dated superseded evidence. | High | independent contradiction | UID0003U8 history | historicalize | applied |
| C3U8-050 | Historical generated UID0003U8 at command 12699 was one routed but behaviorally stale body; current callback output supersedes it. | High | read-only generated snapshots | report/generated proof | historicalize | applied |
| C3U8-051 | Exact manual coverage replacements/insertions are supervisor-owned. | High | read-only row comparison | coverage section | incorporate | applied |
| C3U8-052 | Each changed ordinary page requires scoped validation; target gets final `--wait-generated`. | High | workflow | validator results | incorporate | applied |
| C3U8-053 | Generated verification must prove one target body and absence of all stale tokens/order defects. | High | accepted route/current readback | generated results | incorporate | applied |
| C3U8-054 | No IDA mutation, coverage edit, lifecycle, execute, move, or archive is part of B001 callback work. | High | supervisor restrictions | report/checklist | not-applicable | excluded-with-reason |

## Callback Verification Proof

| Claim ID | Terminal proof |
| --- | --- |
| Proof C3U8-001 | UID0003U8 retains exact filename/range `0x005a3770-0x005a386a`; target callback section records 250-byte extent. |
| Proof C3U8-002 | Target page preserves exact 250-byte SHA256 `5ECA3299C0462C97F9AFF071B6ECD85207BC1D5782F919DDB3C84E39D3E0010D`. |
| Proof C3U8-003 | Target callback section records one method, three CFG regions, one status branch, and two terminal returns; generated output contains one definition. |
| Proof C3U8-004 | Split/EH/cookie/table/compiler-only alternatives are explicitly excluded because bounded bytes and control flow show none; no child or compiler body was created. |
| Proof C3U8-005 | UID0000VN already contained predecessor `[0x005a3766,0x005a3770)`; callback preserved it unchanged. |
| Proof C3U8-006 | UID0000VN now contains exact successor `[0x005a386a,0x005a3870)`, six `cc`, and SHA256 `33CC...E722`. |
| Proof C3U8-007 | Target, UID0001KM, and UID0000VN all record UID0003U9 beginning at `0x005a3870`. |
| Proof C3U8-008 | Destination 1 and UserPane declaration use `char direction`; unsigned target declaration is removed. |
| Proof C3U8-009 | Destination 1 is `void UserPane::StartDirectionalAnimation(char)`; target evidence records both callers ignoring EAX. |
| Proof C3U8-010 | Target callback section records direct callers `0x005a3607` and `0x005a8796`; UserPane file records the two-caller route. |
| Proof C3U8-011 | Target negative-evidence section records no data, vtable, callback, table, or address-taken reference. |
| Proof C3U8-012 | Target current state and UserPane class/file/aggregate pages identify UID0000FQ UserPane as direct owner; LivingObjectPane is inherited support only. |
| Proof C3U8-013 | Existing UID0000P1 route is preserved; UserPane file records exact source order and no new source file. |
| Proof C3U8-014 | Destination 1 begins with `m_isMoving = true`; generated target segment contains it once. |
| Proof C3U8-015 | Destination 1 preserves `ClearMovementHistoryToken()` then `SetDirectionDelayActive(false)`; existing inline helpers remain unchanged. |
| Proof C3U8-016 | Destination 1 preserves the common entry `m_moveFrame = 0`; generated target segment contains both required resets. |
| Proof C3U8-017 | Destinations 1 and 4 use `ObjectStatusBlob::MonsterObject`; former HumanObject support tokens are absent from both generated UID segments. |
| Proof C3U8-018 | Destination 1 stores `direction + 5` in `m_animationGroup`; target prose records signed arithmetic and offset `+0x1cc`. |
| Proof C3U8-019 | Destinations 1/4 and UID0000RR use `g_pMonsterImageLib`; object-image global routing is historicalized. |
| Proof C3U8-020 | Target exact-behavior section and Destination 1 preserve appearance id minus `0x8000`. |
| Proof C3U8-021 | UID00008N and target record bounds-checked `GetEntryByIndex` plus fallback; Destination 1 calls it. |
| Proof C3U8-022 | Destinations 1/3/4 and table support consistently use `ImageAnimationGroup`. |
| Proof C3U8-023 | Destinations 1/3/4 and UID0001VC consistently use `ImageAnimationFrame`; target selects by `m_moveFrame`. |
| Proof C3U8-024 | Destination 3 uses `short frameDuration`; UID0001VC, UID0001VV, UID0000LK, UID0002JN, UID0002LA, and UID00027U record the five signed consumers. |
| Proof C3U8-025 | Destination 1 preserves frame read followed by `PlayFacingAnimation()`; no support rewrite removed this existing behavior. |
| Proof C3U8-026 | Destination 1 preserves `CancelBoxRotationStep()` immediately after facing animation. |
| Proof C3U8-027 | Destination 1 schedules inherited TimerHandler event `kUserPaneMovementStep` with signed frame duration, direction, and zero before moving-state transition. |
| Proof C3U8-028 | Destination 1 and generated UID0003U8 segment place monster `SetMovingState(true)` after scheduling. |
| Proof C3U8-029 | Destination 1 and generated UID0003U8 segment place non-monster `SetMovingState(true)` before delay/reset/schedule. |
| Proof C3U8-030 | Destination 1 uses inherited `m_objectStatus.m_displayStatusByte`; target and UID0002R1 support prose use the same field. |
| Proof C3U8-031 | Destination 1 contains the explicit second non-monster `m_moveFrame = 0`; generated target segment count is two. |
| Proof C3U8-032 | Target negative evidence retains signed plain-char scale, `cdq/idiv`, and no zero guard; no hardening was added. |
| Proof C3U8-033 | Destination 1 schedules event 20 with quotient, direction, and zero in the non-monster branch. |
| Proof C3U8-034 | Destination 1 contains two branch-local `m_mapPane->UpdateObjectPaneScreenBounds(this)` calls; target class/file prose links UID0004DS. |
| Proof C3U8-035 | Destination 1 preserves duplicated terminal map calls and the monster-only return rather than a merged tail. |
| Proof C3U8-036 | Target path/title, UserPane declaration, file source order, and aggregate inventory retain `StartDirectionalAnimation`. |
| Proof C3U8-037 | UID0003U8 managed block matches report Destination 1 byte-for-byte after newline normalization. |
| Proof C3U8-038 | UID0000FQ managed block applies the accepted `char` target declaration; concurrent stronger unrelated inventory-slot field names were preserved and rebased into this report's Destination 2. |
| Proof C3U8-039 | UID0001CM managed block matches report Destination 3 byte-for-byte and changes only duration signedness inside the accepted block. |
| Proof C3U8-040 | UID0002R1 managed block matches report Destination 4 byte-for-byte; current prose additionally removes stale support aliases. |
| Proof C3U8-041 | All bounded type/file/loader/default support pages now use signed 16-bit duration while preserving scores, routes, formal bodies, widths, and default `30000`. |
| Proof C3U8-042 | UID0000P1 records MonsterImageLib and MonsterImageLibTables declaration/include dependencies and exact UserPane source order. |
| Proof C3U8-043 | UID00008N records the live bounds-checked target consumer; UID0000RR records read `0x005a37ac` and exact entry/group/frame chain without score/formal changes. |
| Proof C3U8-044 | UID0001KM current inventory/anchor/timer sections carry signed-char, MonsterObject, branch order, event 20, and exact padding facts. |
| Proof C3U8-045 | No split, new child, source file, class, global, emitter position, or compiler body was created; exclusion is evidence-backed. |
| Proof C3U8-046 | UID0003U8 header is current `COMPLETION:92` / `CONFIDENCE:94`; command 12738 recorded both updates. |
| Proof C3U8-047 | UID0003U8 retains owner/emitter UID0000FQ, true, blank position, and `Nested:0`; validators did not alter these fields. |
| Proof C3U8-048 | Target Item Summary and current state now describe exact signed ABI, monster/non-monster behavior, ordering, callers, boundaries, and route. |
| Proof C3U8-049 | UID0002QY/B004 Human/object-image/merged-tail conclusions remain only in dated Historical/Superseded sections with direct rejection evidence. |
| Proof C3U8-050 | Command 12699 snapshot remains historical; waited callback output supersedes it and current generated proof is recorded below. |
| Proof C3U8-051 | Exact manual coverage text remains in this report; B001 did not edit any `-coverage-report.md` file. |
| Proof C3U8-052 | Every changed ordinary page has an `ok:1`, exit-0 scoped validator; target received waited command 12768 and final freshness command 12773 after concurrent generated-header drift. |
| Proof C3U8-053 | Generated UID0003U8, UID0002R1, and UID0001CM segments satisfy exact uniqueness/body/token assertions; hashes and headers are recorded below. |
| Proof C3U8-054 | Excluded boundary is satisfied: no IDA mutation, coverage edit, execute/probe, lifecycle/count, move, or archive command was run; all ordinary leases were released. |

## Positive Evidence Summary

- The exact function boundary, complete instruction stream, enum value, global operand, helper calls, field offsets, and two callers all agree on one UserPane method.
- The MonsterObject decision is overdetermined by `statusKind == 1`, UID00009S, the `g_pMonsterImageLib` operand, `appearanceId - 0x8000`, and the MonsterImageLib table lookup chain.
- The source route is overdetermined by UserPane-only offsets, ProcessMovement/OnAnimationStep callers, neighboring UserPane methods, and the existing UID0000FQ/UID0000P1 emitter chain.
- The exact formal shape preserves all branch-specific side effects and direct machine behavior without raw `sub_`/`unk_` labels.

## IDA MCP Facts

- Function/range: `lookup_funcs(0x005a3770)` -> `sub_5A3770`, size `0xfa`, exact end `0x005a386a`; 73 instructions; three basic blocks; no EH/cookie.
- Bytes: head `55 8b ec 53 0f be 5d 08 57 8b f9 83 bf 78 01 00`; tail includes final MapPane call and `retn 4`; exact hash recorded above.
- Branch: compare dword `[edi+0x178],1` at `0x005a377b`; `jnz 0x005a3821`; equality path is MonsterObject.
- Fields: `+0x1c4 m_isMoving`, `+0x1c6 m_moveFrame`, `+0x1cc m_animationGroup`, embedded ObjectStatusBlob `+0x178`, display byte `+0x1a0`, UserPane token/delay `+0x13eaf2/+0x13eaf4`, UserPane MapPane pointer `+0x1340f8`.
- Calls: `0x004db330`, `0x00528af0`, `0x00528d00`, `0x0053b7c0`, `0x0053bf80`, `0x00597910`, `0x0053ab20`, and `0x00506980`.
- Xrefs: two code refs, at `0x005a3607` inside ProcessMovement and `0x005a8796` inside OnAnimationStep; no data route reported.
- GetFrame consumers: five callers at `0x0053a30b`, `0x0053aaae`, `0x0053b780`, `0x0053ba59`, and `0x005a37d6`; all timing uses interpret frame word `+2` as signed `__int16`.
- Padding: `[0x005a3766,0x005a3770)` ten `cc`; `[0x005a386a,0x005a3870)` six `cc`.
- Negative IDA facts: no target split, switch table, static data, vtable slot, callback table, exception state, security cookie, alternate image-library global, or meaningful return consumer.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005a2e00-0x005a36f0` | UID0003U6 UserPaneProcessMovement | predecessor source member plus attached switch material | true | UID0000FQ | current `92/94` | verify-only direct caller |
| `0x005a36f0-0x005a3766` | UID0003U7 UserPaneInitializeWalkAnimation | predecessor source member | true | UID0000FQ | current `92/94` | verify-only executed B004 baseline |
| `0x005a3766-0x005a3770` | UID0000VN `-ignored` | ten-byte alignment | source-no-code | none | ignored | already present |
| `0x005a3770-0x005a386a` | UID0003U8 assigned target | directional animation/timer starter | true | UID0000FQ | current `92/94` | corrected metadata, evidence, and formal C++ implemented and validated |
| `0x005a386a-0x005a3870` | UID0000VN `-ignored` | six-byte alignment | source-no-code | none | ignored | exact all-`cc` row present and validated |
| `0x005a3870-0x005a3889` | UID0003U9 UserPaneGetInventorySlotAddress | successor source member | true | UID0000FQ | current `88/91` | verify-only |
| shared helper | UID0001CM MonsterImageLibTables | animation table/group/frame declarations and bodies | true | UID0000LK | current `90/90` | signed-duration support correction implemented and validated |
| `0x0053b700-0x0053baa8` | UID0002R1 LivingObjectPaneAnimationTimer | PlayAnimation/wrappers/timer callback | true | UID00007B | current `88/89` | bounded formal contract correction implemented and validated |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005a3607` | UID0003U6 ProcessMovement -> target | Normal movement success passes the computed direction; return ignored. |
| `0x005a8796` | UserPane OnAnimationStep -> target | Animation-step retry passes EBX direction, ignores return, then sets a UserPane state byte. |
| `0x005a37c0` | target -> MonsterImageLib::GetEntryByIndex | Selects monster table row by appearance ID minus `0x8000`. |
| `0x005a37c7` | target -> ImageAnimationTable/MonsterImageEntry::GetGroup | Selects group `direction + 5`. |
| `0x005a37d6` | target -> ImageAnimationGroup::GetFrame | Selects current signed move-frame entry. |
| `0x005a37e1` | target -> LivingObjectPane::PlayFacingAnimation | Starts monster facing animation after delay capture. |
| `0x005a37e8` | target -> CancelBoxRotationStep | Cancels FBSA timer before scheduling movement step. |
| `0x005a3800`, `0x005a3853` | target -> TimerMgr::ScheduleTimer | Event 20, branch delay, direction, zero. |
| `0x005a3809`, `0x005a3823` | target -> SetMovingState(true) | Branch-specific order is significant. |
| `0x005a3816`, `0x005a385f` | target -> MapPane::UpdateObjectPaneScreenBounds | Final branch-local screen-bounds refresh. |

## Documentation Evidence And IDA Status

- UID0000FQ supplies the complete UserPane layout and declaration route; the callback changed only this method parameter from unsigned to plain char.
- UID00007B supplies inherited ObjectStatusBlob, movement fields, TimerHandler conversion, PlayFacingAnimation, CancelBoxRotationStep, and SetMovingState declarations.
- UID00009S proves HumanObject=0 and MonsterObject=1. At the report-only evidence pass, this directly contradicted the then-current target HumanObject branch; the callback replaced that branch with the validated MonsterObject form.
- UID0000RR proves global `0x0069b440` is `g_pMonsterImageLib`. UID0001VC/UID0001CM supply the accepted MonsterImageEntry/ImageAnimationGroup/ImageAnimationFrame vocabulary.
- At the report-only evidence pass, UID0002R1's then-current formal block used the same HumanObject, object-image, old group/frame, and delay aliases. Leaving it unchanged would have made the rebuilt target's `PlayFacingAnimation()` call a no-op on the exact monster branch; Destination 4 now contains the validated synchronized block.
- UID0004DS proves both final calls are `UpdateObjectPaneScreenBounds`, not generic invalidation.
- Manual by-memory coverage is stale for UID0003U8 and omits the six-byte successor padding. UID0001CM and UID0000LK manual rows also lag their current score/nonblank formal state.
- Historical generated UserPane.cpp at command 12699 was routed once but reproduced the then-current ordinary-doc defects. Current command 12773 supersedes that snapshot; generated output remains readback evidence, not a basis for retaining old defects.

## Ranked Ownership Analysis

### 1. UserPane / UserPane.cpp

- Evidence for: two UserPane caller paths, derived-only `+0x1340f8` and `+0x13eaf2/+0x13eaf4` accesses, exact neighboring UserPane source methods, current owner/emitter route, and class declaration.
- Evidence against: original private method spelling is stripped.
- Decision: direct owner/emitter UID0000FQ through UID0000P1; high confidence.

### 2. LivingObjectPane / LivingObjectPane.cpp

- Evidence for: most low offsets and helper calls are inherited from LivingObjectPane; animation/timer support is implemented there.
- Evidence against: a base member cannot legally access UserPane-only map/token/delay state, and both callers operate on the local UserPane.
- Decision: dependency/base support only, rejected as target owner.

### 3. MonsterImageLib, MapPane, or TimerMgr modules

- Evidence for: target consumes their globals/methods.
- Evidence against: none receives the target `this`; all are called dependencies; source order and derived fields remain UserPane-specific.
- Decision: reject ownership. The callback applied only the bounded support synchronization exposed by the target's direct contract evidence.

### Proposed new file/grouping, if applicable

- Not applicable. No new source file or owner grouping is warranted. Shared table types remain in existing UID0000LK, and target remains in UserPane.cpp.

## Source Placement

- Recommended placement: `NexusTK/ui/panels/UserPane.cpp`, member of UID0000FQ UserPane.
- Header dependencies: UserPane source must see existing `MonsterImageLib`, `MonsterImageEntry`, `ImageAnimationGroup`, `ImageAnimationFrame`, TimerMgr, and MapPane declarations through current project headers; do not duplicate those types inside UserPane.
- Rejected placements: LivingObjectPane.cpp, MonsterImageLib.cpp, MonsterImageLibTables.cpp, MapPane.cpp, TimerMgr.cpp, packet/protocol source, or a new movement-animation file.
- Remaining uncertainty: exact include filenames and original private lexical spelling, with no route/behavior impact.

## Range / Split / Padding / Reclassification Analysis

- Target is exact `[0x005a3770,0x005a386a)`. Both terminal paths end in `retn 4`; no target byte lies beyond `0x005a386a`.
- No child or split is required. The function's three blocks are one method.
- Existing predecessor padding `[0x005a3766,0x005a3770)` is correct and must remain.
- UID0000VN `by-memory/-ignored.md` now contains `[0x005a386a,0x005a3870)`: six all-`cc` bytes, SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`, between target and UID0003U9.
- Parent UID0001KM remains a non-emitting source-family index; no metadata/range/child count changes are needed.

## Negative Evidence Summary

- No target data/vtable/callback ref, EH state, cookie, switch table, internal padding, or raw helper island.
- No return-value consumer; decompiler `int` is rejected.
- No HumanObject image-table path: enum, branch value, global, and table index all contradict it.
- The report-only evidence pass found no valid `g_pObjectImageLib`, `GetFrameGroup`, `ImageFrameGroup`, `ImageFrame`, or `delay` declaration outside the then-stale UID0002R1/UID0003U8 blocks. The callback removed those stale tokens from both blocks, and current generated readback confirms zero occurrences in their segments.
- No unsigned target-parameter load; direct `movsx` contradicts `unsigned char` for this exact method.
- No merged source ordering is safe because branch-local SetMovingState/reset/schedule order differs.
- No new owner/source file is justified by dependency calls.

## IDA Rename / Type / Comment Recommendations

- Source-facing target name: retain `UserPane::StartDirectionalAnimation`.
- Source-facing target type: `void (UserPane::*)(char direction)`; this is a documentation/source recommendation only. No IDA type mutation is requested.
- Status type: `ObjectStatusBlob::MonsterObject` for value 1.
- Shared types: `MonsterImageEntry`, `ImageAnimationGroup`, `ImageAnimationFrame`; `short frameDuration` at `+0x02`.
- Helper/global names: `g_pMonsterImageLib`, `GetEntryByIndex`, `GetGroup`, `GetFrame`, `PlayFacingAnimation`, `CancelBoxRotationStep`, `SetMovingState`, `UpdateObjectPaneScreenBounds`.
- Intentionally unchanged: target path/title, owner/emitter, blank position, `Nested:0`, existing TimerMgr event enum, and source route.
- IDA DB edits: not requested and forbidden in this assignment.

## First-Draft C++ Recommendation

- Eligible: yes. The target is live, bounded, source-authored, routed, and all behavior-critical types/helpers are resolved.
- Exactly four managed destination blocks follow. They are complete insertion shapes, not prose-only snippets.

- Destination 1: `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserPane::StartDirectionalAnimation(char direction)
{
    m_isMoving = true;
    ClearMovementHistoryToken();
    SetDirectionDelayActive(false);
    m_moveFrame = 0;

    if (m_objectStatus.m_statusKind == ObjectStatusBlob::MonsterObject)
    {
        m_animationGroup = direction + 5;
        MonsterImageEntry *entry =
            g_pMonsterImageLib->GetEntryByIndex(
                m_objectStatus.m_appearanceId - 0x8000);
        ImageAnimationGroup *group = entry->GetGroup(m_animationGroup);
        const ImageAnimationFrame *frame = group->GetFrame(m_moveFrame);

        PlayFacingAnimation();
        CancelBoxRotationStep();
        g_pTimerMgr->ScheduleTimer(
            static_cast<TimerHandler *>(this), kUserPaneMovementStep,
            frame->frameDuration, direction, 0);
        SetMovingState(true);
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        return;
    }

    SetMovingState(true);
    m_moveFrame = 0;
    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(this), kUserPaneMovementStep,
        m_objectStatus.m_displayStatusByte / g_movementSubstepScale,
        direction, 0);
    m_mapPane->UpdateObjectPaneScreenBounds(this);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 2: `by-class/UserPane.md`. Preserve the current complete declaration verbatim except for `StartDirectionalAnimation(char direction)` as shown.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MapPane;
struct MapPoint;
struct PaneKeyEvent;
struct ServerMessageEvent;

MapPoint *DirectionToTileOffset(
    MapPoint *outOffset, unsigned char direction);
void __stdcall DispatchCopiedEventPayload(
    const void *data, size_t size);

static bool __stdcall HandleUIPanelSwitchPacket(
    const unsigned char *packet);
static void SendDirectionPacket(unsigned char direction);

struct LinkedPlayerRecord
{
    unsigned int objectId;                // +0x000
    wchar_t name[128];                    // +0x004
    bool active;                          // +0x104
    unsigned char reserved105;
    unsigned short field106;
    unsigned char state108[7];
    unsigned char reserved10f;
    unsigned short field110;
    unsigned char field112;
    unsigned char reserved113;
    unsigned short field114;
    unsigned char field116;
    unsigned char reserved117;
    unsigned short field118;
    unsigned char field11a;
    unsigned char reserved11b;
    unsigned int value11c;
    unsigned int value120;
    unsigned int value124;
    unsigned int value128;
};

struct LocalInventorySlotRecord
{
    unsigned char active;                 // +0x000
    unsigned char reserved001;
    unsigned short itemId;                // +0x002
    unsigned char iconStyle;              // +0x004
    unsigned char reserved005;
    wchar_t displayName[80];              // +0x006
    wchar_t itemMetaKey[80];              // +0x0a6
    wchar_t ownerName[80];                // +0x146
    unsigned char reserved1e6[2];
    unsigned int quantityOrCount;         // +0x1e8
    unsigned char quantityPromptFlag;     // +0x1ec
    unsigned char reserved1ed[3];
    unsigned int currentDurability;       // +0x1f0
    unsigned int protectionCount;         // +0x1f4
    unsigned char targetMode;             // +0x1f8
    unsigned char reserved1f9[3];
};

struct MovementWaypointSegment
{
    int startX;
    int startY;
    int endX;
    int endY;
};

struct SpellCommandSlotRecord
{
    unsigned char active;                 // +0x000
    unsigned char reserved001[3];
    int inputKind;                        // +0x004
    unsigned char reserved008[0xa0];
    wchar_t prompt[80];                   // +0x0a8
};

struct LocalMovementHistoryRecord
{
    unsigned char active;
    unsigned char reserved01[3];
    int tileY;
    int tileX;
    unsigned char direction;
    unsigned char reserved0d[3];
};

class UserPane : public LivingObjectPane
{
public:
    enum UserTimerMessage
    {
        kUserPaneMovementStep = 20
    };

    UserPane();
    virtual ~UserPane();

    virtual void OnBoundsChanged(const RectBounds *bounds);
    virtual void OnClipBounds(RectBounds *clip, RectBounds *out);
    virtual void ShowNameLabel();
    virtual void HideNameLabel();
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
    virtual bool OnServerMessage(const ServerMessageEvent *event);
    virtual bool OnAnimationStep(int message, int frameOrDirection, int aux);
    virtual MapPane *GetMapPane();

    void SendGiveItemPacket(signed char slot, bool allItems);
    void SendDropItemPacket(signed char slot, bool allItems);
    CollectionPlayerDataView &GetCollectionData();
    const CollectionPlayerDataView &GetCollectionData() const;

    MapPoint *GetViewportPosition(MapPoint *outPosition) const;
    void ProcessMovement(unsigned char direction);
    void InitializeWalkAnimation(unsigned char direction);
    void StartDirectionalAnimation(char direction);
    LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot);
    void DispatchConfiguredShortcutHotkey(short hotkeyNumber, int unused);
    void ExecuteHotkeyAction(short hotkey);
    void UseInventorySlot(unsigned char slot);
    void UseCommandSlot(unsigned char slot);
    void TryPerformAction();
    bool WarpToPosition(int x, int y, int viewportColumn, int viewportRow);
    LocalMovementHistoryRecord *GetActiveMovementHistoryRecordByIndex(
        unsigned char recordIndex);
    void ClearAllMovementHistoryRecords();
    void ClearMovementHistoryRecordByIndex(int recordIndex);
    void UpdateScreenPosition();
    void SendMovementPacket(unsigned char direction);
    void TryDispatchFunctionKeyShortcut(
        unsigned short functionKeyOrdinal, unsigned int currentTick);
    void CopyDeferredUserListPacket(
        const unsigned char *packetData, size_t packetSize);
    bool ParsePlayerSettingsPacket(const unsigned char *packet);
    bool ParseInventorySlotUpdatePacket(const unsigned char *packet);
    bool HandleServerEntryPacket(const unsigned char *packet);
    bool HandleWarpPacket(const unsigned char *packet);
    bool HandleMovementReplyPacket(const unsigned char *packet);
    bool HandleExtendedMovementReplyPacket(const unsigned char *packet);
    bool HandleChatMessagePacket(const unsigned char *packet);
    bool HandleUserListPacket(const ServerMessageEvent *event);
    bool HandlePositionSyncPacket(const unsigned char *packet);
    bool ParseLinkedObjectsPacket(const unsigned char *packet);
    void SendMovementWaypointPacket(
        unsigned char direction, unsigned short token,
        const MovementWaypointSegment *segment);
    void SendFaceDirectionPacket(unsigned char direction);
    void SendAutoFaceDirectionPacket();
    void SendActionPacketWithAutoFace();
    void SendAttackTargetPacket(unsigned char action);

private:
    friend class MapPane;

    SpellCommandSlotRecord *GetSpellCommandSlotRecord(unsigned char slot)
    {
        return &m_spellCommandSlots[slot - 1];
    }

    void ClearMovementHistoryToken()
    {
        m_movementState[2] = 0;
        m_movementState[3] = 0;
    }

    void SetMovementReplyState()
    {
        m_movementState[1] = 1;
        m_movementState[2] = 1;
    }

    bool IsDirectionDelayActive() const
    {
        return m_movementState[4] != 0;
    }

    void SetDirectionDelayActive(bool active)
    {
        m_movementState[4] = active ? 1 : 0;
    }

    unsigned char m_userPaneBaseTail[0x0c];       // 0x20c
    LinkedPlayerRecord m_linkedPlayers[50];       // 0x218
    signed char m_linkedPlayerCount;              // 0x3cb0
    unsigned char m_preCollectionState[0x213];    // 0x3cb1
    int m_localPlayerHitRadius;                   // 0x3ec4
    CollectionPlayerDataView m_collectionData;   // 0x3ec8
    int m_screenX;                                // 0x1340cc
    int m_screenY;                                // 0x1340d0
    unsigned int m_screenState;                   // 0x1340d4
    RectBounds m_screenHitBounds;                 // 0x1340d8
    RectBounds m_screenLowerHitBounds;            // 0x1340e8
    MapPane *m_mapPane;                           // 0x1340f8
    unsigned char m_playerSettingsState[8];       // 0x1340fc
    LocalInventorySlotRecord m_inventorySlots[52];// 0x134104
    SpellCommandSlotRecord m_spellCommandSlots[52];// 0x13a834
    bool m_spellCommandSlotsReady;                // 0x13ead4
    unsigned char m_preViewportState[3];          // 0x13ead5
    int m_viewportColumn;                         // 0x13ead8
    int m_viewportRow;                            // 0x13eadc
    int m_viewportHalfColumns;                    // 0x13eae0
    int m_viewportHalfRows;                       // 0x13eae4
    int m_viewportRemainingColumns;               // 0x13eae8
    int m_viewportRemainingRows;                  // 0x13eaec
    unsigned char m_movementState[5];             // 0x13eaf0
    unsigned char m_preActionTickState[3];        // 0x13eaf5
    unsigned int m_lastActionTick;                // 0x13eaf8
    unsigned char m_preWhisperHistory[8];         // 0x13eafc
    List *m_whisperHistoryOther;                  // 0x13eb04
    List *m_outgoingWhisperRecipientHistory;      // 0x13eb08
    List *m_incomingWhisperSenderHistory;         // 0x13eb0c
    unsigned char m_whisperHistorySource;         // 0x13eb10
    unsigned char m_preMovementHistory[3];        // 0x13eb11
    LocalMovementHistoryRecord *m_movementHistoryRecords; // 0x13eb14
    int m_movementHistoryCapacity;                // 0x13eb18
    unsigned char m_movementHistoryWriteIndex;    // 0x13eb1c
    unsigned char m_movementHistoryState[3];      // 0x13eb1d
    unsigned char *m_deferredUserListPacket;      // 0x13eb20
    size_t m_deferredUserListPacketSize;          // 0x13eb24
    int m_deferredUserListCount;                  // 0x13eb28
    unsigned int m_deferredUserListDeadline;      // 0x13eb2c
    bool m_deferredUserListActive;                // 0x13eb30
    unsigned char m_preMovementTicks[3];          // 0x13eb31
    unsigned int m_lastMovementSendTick;          // 0x13eb34
    unsigned int m_lastMovementInputTick;         // 0x13eb38
    unsigned char m_actionMode;                   // 0x13eb3c
    unsigned char m_userPaneTrailingState0;       // 0x13eb3d
    bool m_includeAdjacentMovementTargets;        // 0x13eb3e
    unsigned char m_userPaneTrailingState2[0x45]; // 0x13eb3f
};

typedef char LinkedPlayerRecordSizeMustBe300[
    sizeof(LinkedPlayerRecord) == 0x12c ? 1 : -1];
typedef char LocalInventorySlotRecordSizeMustBe508[
    sizeof(LocalInventorySlotRecord) == 0x1fc ? 1 : -1];
typedef char SpellCommandSlotRecordSizeMustBe328[
    sizeof(SpellCommandSlotRecord) == 0x148 ? 1 : -1];
typedef char LocalMovementHistoryRecordSizeMustBe16[
    sizeof(LocalMovementHistoryRecord) == 0x10 ? 1 : -1];
typedef char UserPaneSizeMustBe1305476[
    sizeof(UserPane) == 0x13eb84 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 3: `by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md`. Preserve the complete current block except for signed `short frameDuration` as shown.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ImageAnimationFrame
{
    short frameOffset;
    short frameDuration;
    unsigned char blendAlpha;
    unsigned char reserved;
    short auxFrameId;
    unsigned char paletteIndex;
    unsigned char effectIndex;

    ImageAnimationFrame();
};

struct ImageAnimationGroup
{
    ImageAnimationFrame *frames;
    unsigned short frameCount;

    ImageAnimationGroup();
    ~ImageAnimationGroup();

    void AllocateFrames(unsigned int count);
    ImageAnimationFrame *GetFrame(unsigned int frameIndex);
};

struct ImageAnimationTable
{
    int baseValue;
    unsigned char groupCount;
    unsigned char flags;
    unsigned short tableId;
    ImageAnimationGroup *groups;

    ImageAnimationTable();
    ~ImageAnimationTable();

    void AllocateGroups(unsigned int count);
    ImageAnimationGroup *GetGroup(unsigned int groupIndex);
    ImageAnimationFrame *GetFrame(unsigned int groupIndex, unsigned int frameIndex);
};

extern ImageAnimationFrame g_defaultImageAnimationFrame;

ImageAnimationTable::ImageAnimationTable()
{
    baseValue = 0;
    groupCount = 0;
    flags = 0;
    tableId = 0;
    groups = NULL;
}

ImageAnimationTable::~ImageAnimationTable()
{
    delete[] groups;
    groupCount = 0;
    groups = NULL;
}

void ImageAnimationTable::AllocateGroups(unsigned int count)
{
    groups = new ImageAnimationGroup[count];
    groupCount = (unsigned char)count;
}

ImageAnimationGroup *ImageAnimationTable::GetGroup(unsigned int groupIndex)
{
    ImageAnimationGroup *group = groups;
    if (groupIndex < groupCount)
        group += groupIndex;
    return group;
}

ImageAnimationFrame *ImageAnimationTable::GetFrame(unsigned int groupIndex, unsigned int frameIndex)
{
    ImageAnimationGroup *group = groups;
    if (groupIndex < groupCount)
        group += groupIndex;

    if (frameIndex < group->frameCount)
        return group->frames + frameIndex;

    return &g_defaultImageAnimationFrame;
}

ImageAnimationGroup::ImageAnimationGroup()
{
    frames = NULL;
    frameCount = 0;
}

ImageAnimationGroup::~ImageAnimationGroup()
{
    delete[] frames;
    frames = NULL;
    frameCount = 0;
}

void ImageAnimationGroup::AllocateFrames(unsigned int count)
{
    frames = new ImageAnimationFrame[count];
    frameCount = (unsigned short)(unsigned char)count;
}

ImageAnimationFrame *ImageAnimationGroup::GetFrame(unsigned int frameIndex)
{
    if (frameIndex < frameCount)
        return frames + frameIndex;

    return &g_defaultImageAnimationFrame;
}

ImageAnimationFrame::ImageAnimationFrame()
{
    frameOffset = 0;
    frameDuration = 0;
    blendAlpha = 0xff;
    auxFrameId = -1;
    paletteIndex = 0;
    effectIndex = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 4: `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md`. Preserve all four current methods while synchronizing the exact monster/table/frame/map contracts.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LivingObjectPane::PlayAnimation(unsigned int animationGroup)
{
    if (m_objectStatus.m_statusKind != ObjectStatusBlob::MonsterObject)
        return;

    CancelTimer(kLivingTimerFrameAnimation);

    MonsterImageEntry *entry =
        g_pMonsterImageLib->GetEntryByIndex(
            m_objectStatus.m_appearanceId - 0x8000);
    ImageAnimationGroup *frameGroup = entry->GetGroup(animationGroup);
    if (frameGroup->frameCount == 0)
    {
        if (animationGroup == 0)
            g_activeMapPane->RemoveObjectPaneById(m_objectId);
        return;
    }

    m_animationFrame = 0;
    m_animationGroup = animationGroup;

    const ImageAnimationFrame *frame = frameGroup->GetFrame(0);
    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(this),
        kLivingTimerFrameAnimation,
        frame->frameDuration,
        0,
        0);
    g_activeMapPane->UpdateObjectPaneScreenBounds(this);
}

void LivingObjectPane::PlayFacingAnimation()
{
    PlayAnimation(m_facing + 1);
}

void LivingObjectPane::PlayDeathAnimation()
{
    m_terminalAnimation = true;
    PlayAnimation(0);
    g_activeMapPane->ClearLivingObjectReferences(this);
}

bool LivingObjectPane::OnTimer(int timerId, int arg0, int arg1)
{
    switch (timerId)
    {
    case kLivingTimerForwardStep:
        m_moveFrame = (m_moveFrame + 1) % 4;
        if (m_moveFrame != 0)
        {
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kLivingTimerForwardStep,
                arg1,
                arg0,
                arg1);
            PropagateLinkedObjectMode(m_facing);
            return true;
        }

        TryStepForward();
        return true;

    case kLivingTimerBoxStep:
        m_boxRotationStep = (m_boxRotationStep + 1) % 6;
        g_pTimerMgr->ScheduleTimer(
            static_cast<TimerHandler *>(this),
            kLivingTimerBoxStep,
            200,
            0,
            0);
        g_activeMapPane->UpdateObjectPaneScreenBounds(this);
        return true;

    case kLivingTimerDirectionDelay:
        if (m_isMoving)
        {
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kLivingTimerDirectionDelay,
                m_objectStatus.m_displayStatusByte,
                arg0,
                0);
            return true;
        }

        m_facing = static_cast<unsigned char>(arg0);
        if (m_objectStatus.m_statusKind == ObjectStatusBlob::MonsterObject)
            PlayAnimation(static_cast<unsigned char>(arg0) + 1);
        g_activeMapPane->UpdateObjectPaneScreenBounds(this);
        return true;

    case kLivingTimerFrameAnimation:
    {
        MonsterImageEntry *entry =
            g_pMonsterImageLib->GetEntryByIndex(
                m_objectStatus.m_appearanceId - 0x8000);
        ImageAnimationGroup *frameGroup =
            entry->GetGroup(m_animationGroup);
        ++m_animationFrame;

        if (m_animationFrame == frameGroup->frameCount)
        {
            if (m_terminalAnimation)
                g_activeMapPane->RemoveObjectPaneById(m_objectId);
            else
            {
                m_animationFrame = 0;
                PlayAnimation(m_facing + 1);
            }
            return true;
        }

        const ImageAnimationFrame *frame =
            frameGroup->GetFrame(m_animationFrame);
        g_pTimerMgr->ScheduleTimer(
            static_cast<TimerHandler *>(this),
            kLivingTimerFrameAnimation,
            frame->frameDuration,
            0,
            0);
        Invalidate(false);
        g_activeMapPane->UpdateObjectPaneScreenBounds(this);
        return true;
    }

    case kLivingTimerRefresh:
        if (m_renderEffectState != 0)
        {
            m_renderEffectState = 0;
            Invalidate(&m_bounds);
        }
        return true;

    default:
        return false;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation: Destination 1 preserves both terminal paths, direct state writes, signed parameter promotion, exact helper order, unguarded division, and branch-local map calls. Destination 4 prevents the target's monster call from entering a contradictory Human-only support implementation.
- Era/source shape: simple private member, existing globals, pointers, enums, and explicit branch-local return fit the observed optimized MSVC code and project style. No modern container, exception, guard, lambda, or invented wrapper is introduced.

## Final Recommendation

- C3U8-001 through C3U8-054 are implemented at accepted report-level detail.
- Target is current `92/94`, owner/emitter UID0000FQ unchanged, true, blank position, `Nested:0`, with Destination 1 and exact complete evidence/current/history reconciliation.
- Support is current: Destination 2 on UID0000FQ, Destination 3 on UID0001CM, Destination 4 on UID0002R1, bounded prose/evidence synchronization, and the exact six-byte UID0000VN padding row.
- No item was left no-owner/non-emitting by this assignment. No child, source file, class, global, duplicate table declaration, or compiler body was created.
- No B-agent future research remains for this target. Stripped lexical names remain confidence caps only.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md`.
- Applied score `92/94`; UID, owner/emitter UID0000FQ, reconstructable true, blank position, and `Nested:0` are preserved.
- Destination 1 is installed exactly.
- Item Summary and current prose now carry target-specific signed ABI, MonsterObject frame-duration path, non-monster display-status/signed-scale path, branch order, event 20, callers, and map refresh.
- Exact bytes/hash, CFG, fields, callers, callees, enum, timer payload, signedness, source order, padding, ownership, rejected alternatives, negative evidence, and score rationale are incorporated.
- Current owner text is UserPane; LivingObjectPane remains inherited support. UID0002QY/B004 Human/object-image/merged-order/old-type assumptions are dated and historicalized with rejection reasons.

## Recommended Support Doc Changes

- Applied UID0000FQ Destination 2 and target ABI/branch/source evidence while preserving score, route, layout, stronger concurrent inventory-slot names, and unrelated content.
- Applied UID0000P1 source order, two-caller route, and MonsterImageLib/MonsterImageLibTables dependencies with no file-root metadata change.
- Applied UID0001KM exact target inventory/history while preserving non-emitting index metadata and blank C++.
- Applied UID0001CM Destination 3 and five signed timing consumers while preserving all 13 bodies, score, and route.
- Applied UID0000LK, UID0001VC, UID0001VV, UID0002JN, UID0002LA, and UID00027U signed-duration synchronization without unrelated score/formal/layout changes.
- Applied UID0002R1 Destination 4 plus complete current support terminology; owner/emitter/score/position/Nested and unrelated behavior remain.
- Applied UID00008N live GetEntryByIndex consumer and UID0000RR target-read chain with no score/formal change or invented class shell.
- Applied UID0000VN exact successor alignment row while preserving every existing row including predecessor alignment.
- Verify-only pages remained unchanged: UID0003U6, UID0003U7, UID0003U9, UID00007B, UID00009S, UID0004QG, UID0004DS, UID0002CF, UID00027F, UID0000PR, TimerMgr pages, and unrelated UserPane siblings.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/88`, owner/emitter UID0000FQ, true, blank position, `Nested:0`.
- Current applied target: `92/94`; all metadata except scores remains unchanged.
- Completion 92: exact method body, route, ABI, branch behavior, types, support contracts, callers, range, padding, and generated plan are complete. It does not claim original private spelling or original include filenames.
- Confidence 94: every behavior-critical fact is direct binary evidence and current layout/global support. It remains below 95 because stripped lexical spellings and exact source header organization are inferred.
- Score-improvement attempts:
  - Branch blocker: direct compare plus enum/global resolved Human vs Monster.
  - Type blocker: direct helper chain and all five frame consumers resolved stale frame types and signed duration.
  - ABI blocker: target prologue resolved signed plain-char parameter; callers resolved void return.
  - Order blocker: full disassembly resolved branch-specific SetMovingState/reset/schedule/map ordering.
  - Source blocker: derived offsets, callers, class declaration, and source order resolved owner/file.
  - Range blocker: exact bytes/lookups and both padding spans resolved no-split boundaries.
  - C++ blocker: four complete managed blocks resolve target and direct support contradictions.
- Support scores: preserve all current support scores. This target pass supplies bounded corrections, not full unrelated family rescoring.

## Open Questions With Attempted Resolution

- Is status 1 Human or Monster? Resolved: MonsterObject by enum, global, appearance offset, and helper chain.
- Which image global/API? Resolved: `g_pMonsterImageLib -> GetEntryByIndex -> GetGroup -> GetFrame`.
- What is frame word +2? Resolved: signed `short frameDuration` by five independent sign-extending scheduler consumers.
- Is direction unsigned? Resolved for this target: direct parameter `movsx` and signed arithmetic make plain `char` strongest.
- Is return meaningful? Resolved: no; both callers ignore it, so `void`.
- Can state/scheduling be merged? Resolved: no; exact branch order differs and non-monster repeats frame clear.
- Is target a LivingObjectPane method? Resolved: no; derived-only fields make UserPane mandatory.
- Is a split/new file needed? Resolved: no; one exact function and existing source route.
- Remaining question: exact original private spelling/include file names cannot be recovered from stripped binary. This has no score below 92/94, C++ blanking, ownership, or implementation blocker effect.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Read-only rows inspected: by-memory UID0003U8, UID0001CM, UID0002R1, UID0003U7, UID0003U9, UID0000VN location; by-file UID0000P1 and UID0000LK; by-class UID0000FQ and UID00008N; by-type/by-struct UID0001VC and UID0001VV.
- Rows genuinely requiring synchronization are listed below. UID0000P1, UID0000FQ, UID00008N, UID0001VC, and UID0001VV rows remain accurate at their current abstraction level and require no replacement.
- File: `by-memory/-coverage-report.md`. Replace the current UID0003U8 row exactly with:

```text
        - [UID:0003U8][0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation](by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md) 0x005a3770-0x005a386a | UserPane member | UserPaneStartDirectionalAnimation : reconstructable : 92% : very-strong : Exact 250-byte two-caller UserPane directional-animation starter with signed-char direction ABI, MonsterObject frame-duration path, non-monster display-status/signed-scale path, branch-specific moving-state/frame-reset/timer order, event 20 payload, and final MapPane screen-bounds refresh.
```

- Insert immediately after UID0003U8 and before UID0003U9:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005a386a-0x005a3870 | compiler/linker alignment | UserPane StartDirectionalAnimation to GetInventorySlotAddress alignment : ignored : 100% : strong : Six all-0xcc bytes, SHA256 33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722; no function, data, xref, or source-body role.
```

- Replace the stale UID0001CM row exactly with:

```text
    - [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) 0x00528930-0x00528d51 | shared animation table helper island | MonsterImageLibTables : reconstructable : 90% : very-strong : Source-ready 13-helper ImageAnimationTable/ImageAnimationGroup/ImageAnimationFrame island with complete formal C++, exact allocation/cleanup/lookup/fallback behavior, parser/render/timer callers, signed short frameDuration from five scheduler consumers, callback wiring, and internal padding evidence.
```

- Replace the UID0002R1 row exactly with:

```text
        - [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md) 0x0053b700-0x0053baa8 | animation/timer method cluster | LivingObjectPaneAnimationTimer : reconstructable : 88% : strong : Complete PlayAnimation/PlayFacingAnimation/PlayDeathAnimation and inherited OnTimer source with exact MonsterObject gating, g_pMonsterImageLib entry/group/frame access, signed frameDuration scheduling, five timer constants, adjusted TimerHandler ABI, movement/box/direction/refresh behavior, padding, callers, and LivingObjectPane declaration integration.
```

- File: `by-file/-coverage-report.md`. Replace UID0000LK exactly with:

```text
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) : reconstructable : 87% : strong : Shared render/MonsterImageLibTables.cpp source root for the complete UID0001CM 13-helper ImageAnimationTable/ImageAnimationGroup/ImageAnimationFrame implementation, signed short frameDuration contract, monster/riding parser callers, fallback/default frame records, callback wiring, and source-placement caveats; final original filename/private placement remains inferred.
```

- B001 did not apply the exact text below because all `-coverage-report.md` files are manual supervisor-owned state. Any coverage application and validation remain external supervisor work and are not asserted by this artifact.

## Follow-Up Actions

- Supervisor-owned boundary: manual coverage application and all report validation/execution/count/path/move/archive state are external supervisor/validator-owned state. This artifact neither asserts nor directs a future lifecycle result.
- A-agent actions: none.
- B001 future research actions: none for UID0003U8. The accepted callback, scoped validators, waited generated readback, report reconciliation, and lease release are complete.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: high for `92/94` under the project rubric.
- Remaining uncertainty: only stripped private lexical spelling and exact include organization. No behavior, ABI, owner, source, C++, range, or support-contract blocker remains.

## Validator Results

- Scoped invocation for each ordinary page: `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`. Waited target invocation adds `--wait-generated`.
- Every listed command exited `0` and reported `ok:1`. Validator-owned projected stats, reference indexes, registry metadata, generated files, and tracker side effects were not manually edited by B001.

| Command | Timestamp | Scope | Exit / ok | Reported side effects |
| --- | --- | --- | --- | --- |
| `000000012738` | `2026-07-15T03:18:35-04:00` | UID0003U8 target | `0 / 1` | completion/confidence updates, registry update, 3 UID-link changes, 3 reference adds, projected stats; generated deferred |
| `000000012740` | `2026-07-15T03:19:07-04:00` | UID0000FQ UserPane class | `0 / 1` | registry update, 1 UID-link update, 3 reference adds, 7 retained missing-ref notices, projected stats; generated deferred |
| `000000012743` | `2026-07-15T03:19:38-04:00` | UID0000P1 UserPane file | `0 / 1` | 3 UID-link inserts, 4 reference adds, 22 retained missing-ref notices, projected stats; generated deferred |
| `000000012745` | `2026-07-15T03:20:19-04:00` | UID0001KM aggregate | `0 / 1` | 11 retained missing-ref notices, projected stats; generated deferred |
| `000000012747` | `2026-07-15T03:20:56-04:00` | UID0001CM table helpers | `0 / 1` | registry update, UID0003U8 link/reference add, projected stats; generated deferred |
| `000000012749` | `2026-07-15T03:21:26-04:00` | UID0000LK table file | `0 / 1` | UID0003U8 reference add, projected stats; generated deferred |
| `000000012751` | `2026-07-15T03:21:57-04:00` | UID0001VC MonsterImageEntry | `0 / 1` | UID0003U8 reference add, one stats-row update, projected stats; generated deferred |
| `000000012752` | `2026-07-15T03:22:28-04:00` | UID0001VV RidingDefinition | `0 / 1` | UID0003U8 reference add, projected stats; generated deferred |
| `000000012753` | `2026-07-15T03:23:03-04:00` | UID0002JN monster loader | `0 / 1` | UID0003U8 reference add, projected stats; generated deferred |
| `000000012756` | `2026-07-15T03:23:44-04:00` | UID0002LA riding loader | `0 / 1` | UID0003U8 reference add, projected stats; generated deferred |
| `000000012757` | `2026-07-15T03:24:36-04:00` | UID00027U fallback frame | `0 / 1` | UID0003U8 reference add, 3 stats-row updates, projected stats; generated deferred |
| `000000012758` | `2026-07-15T03:25:43-04:00` | UID0002R1 animation timer | `0 / 1` | registry update, 3 reference adds, 3 retained missing-ref notices, projected stats; generated deferred |
| `000000012760` | `2026-07-15T03:26:19-04:00` | UID00008N MonsterImageLib | `0 / 1` | 2 reference adds, projected stats; generated deferred |
| `000000012762` | `2026-07-15T03:26:52-04:00` | UID0000RR global | `0 / 1` | 2 reference adds, 1 stats-row update, projected stats; generated deferred |
| `000000012764` | `2026-07-15T03:27:35-04:00` | UID0000VN ignored | `0 / 1` | UID0003U9 reference add, 279 retained legacy missing-ref notices, projected stats; generated deferred |
| `000000012766` | `2026-07-15T03:29:14-04:00` | UID0002R1 prose self-review correction | `0 / 1` | 3 retained missing-ref notices, projected stats; generated deferred |
| `000000012768` | `2026-07-15T03:29:56-04:00` | UID0003U8 first waited refresh | `0 / 1` | registry rebuild, 281 generated metadata refreshes, projected stats; generated completed |
| `000000012773` | `2026-07-15T03:35:46-04:00` | UID0003U8 second waited freshness refresh | `0 / 1` | registry rebuild, 280 generated metadata refreshes, validator-owned tracker refresh, projected stats; generated completed |
| `000000012784` | `2026-07-15T03:48:44-04:00` | UID0003U8 final B001 waited refresh after concurrent generated drift | `0 / 1` | registry rebuild, 281 generated metadata refreshes, projected stats; generated completed; B001 target lease released in `finally` |
| `000000012786` | `2026-07-15T03:49:16-04:00` | external supervisor-owned post-callback refresh observed in all three generated headers | `not a B001 invocation` | current common generated command/timestamp only; B001 does not claim its unobserved exit/ok or side-effect details |

### Generated Readback

- Current generated headers on all three relevant files are external supervisor-owned command `000000012786`, timestamp `2026-07-15T03:49:16-04:00`. B001 did not run that command; it is current read-only header evidence after B001's successful waited command `000000012784`.
- `auto-generated/NexusTK/ui/panels/UserPane.cpp`: SHA256 `10B6797B0726CEAE45A8353A8D144887B381FE50D0D55DDDEE580348E4941C87`, 1776 lines. The UID0003U8 segment has one UID marker and one `void UserPane::StartDirectionalAnimation(char direction)`; one MonsterObject branch; one monster global/entry chain; one signed frame-duration schedule; one non-monster display-status/scale expression; exactly two `SetMovingState(true)`, two `m_moveFrame = 0`, and two map-refresh calls. Its stale-token counts are zero for HumanObject, `g_pObjectImageLib`, `ImageFrameGroup`, `const ImageFrame *`, `->delay`, `int frameDelay`, and Empty Emitter Marker.
- `auto-generated/NexusTK/map/LivingObjectPane.cpp`: SHA256 `7B96ADD0754F4745FECFC600927EDA3AFD8F755A4AFA71BA7556C7BFED26EA4C`, 1154 lines. The UID0002R1 segment has one marker; two MonsterObject tests, two global entry lookups, two group declarations, two frame declarations, two signed-duration uses, and four map-bound refreshes. Its stale-token counts are zero for HumanObject, object-image global/types, delay member, old active-map spelling, `InvalidateObject(this)`, and Empty Emitter Marker.
- `auto-generated/NexusTK/render/MonsterImageLibTables.cpp`: SHA256 `3D1D85FAA5CB0FD963F9896C2C10B75C7982E94233F985FA8F405B1B5BE62BD9`, 134 lines. The UID0001CM segment has one marker, one `struct ImageAnimationFrame`, one `short frameDuration;`, zero `unsigned short frameDuration;`, one frame constructor, and no Empty Emitter Marker.
- Waited commands `000000012768`, `000000012773`, and `000000012784` are retained as B001 callback history. Concurrent commands 12769 and 12775 caused intervening generated-header drift; B001's command 12784 completed with `exit 0 / ok 1` and released its target lease. External supervisor-owned command 12786 then refreshed all three files to the common current header without changing the verified UID0003U8, UID0002R1, or UID0001CM segment assertions.

## Changed Files

- Same report updated in place: `tools/leaser/Agents/Agent-B001/research/0003U8-UserPaneStartDirectionalAnimation-source-quality.md`.

| Ordinary path | Current SHA256 | Lines |
| --- | --- | ---: |
| `by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md` | `39BCE7504B3C8CD6070C7C537374035195B8C6E104FA4AAD2CFCAC1E9E9DDDFB` | 136 |
| `by-class/UserPane.md` | `A036468084585D6FCB6689686C3086A635A789F05F8908493B2C7D081B950B6B` | 494 |
| `by-file/UserPane.md` | `B1CDF3C93302004E50FC938009FF820B5CBAF73852F5C56B9D98E408D86BD957` | 283 |
| `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | `F866B1B8E9A4F692D1445331C10E31469E149EA1EBA1EC8329541FF22CCB0629` | 479 |
| `by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md` | `E95F5CCF85FE2127349D49A525EC342074EBAC398FFDAB4A12BEB38DE3DDC215` | 251 |
| `by-file/MonsterImageLibTables.md` | `AF535D5D4CB4B9F898476E18F27BE7ECD1D839D75D5E8CB8D8610211186E209C` | 151 |
| `by-type/by-struct/MonsterImageEntry.md` | `3AACDCFF6C46F047716E35DC29721B7A3370FCD29593F0CB816EC2425767F5F5` | 148 |
| `by-type/by-struct/RidingDefinition.md` | `5C96F657858BFA9F31ADA74920CC2B8BDBDCA167F5555F7193536FF8091F19F4` | 155 |
| `by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md` | `2B9359E4D30A1D43D79241BBC585BA079F2E84FBA36641EAA5454B283C0E3947` | 233 |
| `by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md` | `B1837D58DFEDB089C184DE04CE2A734002632F849E1D1D98E6482DAC2F443341` | 181 |
| `by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md` | `4665B40305E395999BC1A9ED0FACAB1FB5D18558A328E9438832B655424221A2` | 155 |
| `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md` | `CBFE4C3DFB35C7BFABA1F5EC43FACB6054953C8CF0FBCC85904C6A84CBB05EEE` | 316 |
| `by-class/MonsterImageLib.md` | `3C7DF8B4BF08EE9E6576E36FAB5832237C65ACD73CC2FBC3D4C12E0D1B98F633` | 195 |
| `by-global/g_pMonsterImageLib.md` | `2BE8A659B73077321AC83D7F66DFCC5C541B336D95FCA9E2498BC8AD0E781B76` | 127 |
| `by-memory/-ignored.md` | `65777F2601D8802263B584EF5974ADBCDFE85D3BF2AF7EBB8E4EC9A4BFD5A2DE` | 5003 |

- Formal block proof after newline normalization: Destination 1 SHA256 `A0CAA9F8B856F6C0515A491010657008A554E9FBD620EA562C8ED43EF125F81C`; Destination 2 `611D31B5EA0C30C6EF9EF5B155CA7703D9BED9C229FD066C5A359D07793150DB`; Destination 3 `4269B8FED86FBF7185B340CC2B8C8F3FF2BB3A79649CD0F719DC9C6289AEEF7A`; Destination 4 `FC65E6A2CC501E01897A1AA20C6552016206F1BF171B02AAA4EF4528EE17E25B`. All four report blocks equal their destination blocks.
- No file was renamed or created during callback. No manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle file was manually edited. Report execution was not run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Exact report SHA `C451005A4017837F2576424A48968610A4B0EF40A7C42D500862E5A16740AB1C` passed supervisor Gate 1 before implementation.
- [x] Target/support scope confirmed: UID0003U8; UID0000FQ; UID0000P1; UID0001KM; UID0001CM; UID0000LK; UID0001VC; UID0001VV; UID0002JN; UID0002LA; UID00027U; UID0002R1; UID00008N; UID0000RR; UID0000VN.
- [x] Current target state and actual evidence recorded before implementation.
- [x] Claim ledger originally used allowed Actions and `proposed` report-only verification for C3U8-001 through C3U8-054.
- [x] Target score change `86/88 -> 92/94` and support-score preservation defined.
- [x] Branch, image API/types, duration signedness, ABI, return, order, owner/source, range/padding, C++, and generated blockers resolved.
- [x] Owner/emitter/reconstructable route retained UID0000FQ/UID0000FQ/TRUE.
- [x] No split/rename/new child; only exact UID0000VN successor padding defined.
- [x] Source placement, range, padding, reclassification, and IDA recommendations resolved.
- [x] Four complete managed C++ destinations defined.
- [x] Third-party import directive not applicable.
- [x] Target/support facts specified at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 material used only as historical leads without override.
- [x] Open questions closed except lexical/include confidence caps.
- [x] Scoped validator required for every changed ordinary page under short lease.
- [x] Final target waited generation and exact three-file assertions specified.
- [x] Exact supervisor-owned manual coverage text supplied; B001 did not edit coverage.

Implementation callback pass:
- [x] Exact accepted report used; no second target or rewrite.
- [x] All accepted target/support details incorporated at report-level factual detail.
- [x] All 54 ledger rows use legal terminal states with claim-specific proof.
- [x] Metadata, score, routes, no-split disposition, padding, and four C++ destinations applied or excluded with evidence.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions remain resolved; no implementation blocker remains.
- [x] Scoped validators recorded with exact commands, timestamps, exits, ok values, and side effects.
- [x] Final command 12773 generated refresh and exact hashes/header/segment assertions recorded.
- [x] All 15 ordinary hashes, four formal hashes, and zero remaining leases recorded.
- [x] Remaining unapplied accepted claims: none. Blocked ledger count: zero.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000012843","destination_path":"executed-b-agent-research/B001/0003U8-UserPaneStartDirectionalAnimation-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0003U8-UserPaneStartDirectionalAnimation-source-quality.md","timestamp":"2026-07-15T04:19:37-04:00","uid":"0003U8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
