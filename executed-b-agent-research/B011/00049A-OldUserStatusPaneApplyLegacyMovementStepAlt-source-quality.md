** TARGET-REPORT-UID:00049A **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID00049A OldUserStatusPaneApplyLegacyMovementStepAlt Source-Quality Report

** Report mode: implementation callback completed after supervisor Gate 1; awaiting supervisor Gate 2 / execute review. **

## Finalized Report / Current Recommendation

- Accepted recommendation implemented: UID00049A is documented as a real retained `OldUserStatusPane` alternate legacy movement-step helper, the formal C++ body is preserved exactly, and target metadata is now `89/91`.
- Primary reason for movement: B007 corrected UID00049A as a support sibling, but UID00049A still lacked its own direct report. This B011 implementation added target-specific MCP proof for the body/table boundary, no-entry/no-pointer route, high-bit active-map/config gate, discarded `packet[10]` read, map-bound clamping, field id `12` invalidation, and constant `false` return.
- Scope applied: updated the UID00049A target page at report-level detail and updated `by-file/UserStatusPane.md` to remove stale current-generated-header wording. No class/aggregate/config/map/packet-helper score change was made.
- Formal C++ disposition: preserved unchanged. It already contains the B007-accepted `g_pConfig` name, active-map/config gate with early false return, `packet[10]` discarded read marker, switch/clamp behavior, field id `12` invalidation, and final `return false`.
- Status after callback: scoped validators ran, final observed generated output is header `000000007819`, leases were released, and the report is ready for supervisor Gate 2 / execute review. No forbidden execute/lifecycle/archive/manual-move/supervisor-ledger actions were taken.

## Supporting Research

### Old-Report Search Results

- Required terms searched: `TARGET-REPORT-UID:00049A`, `00049A`, `0x005bf670`, `0x005bf7c0`, `0x005bf7b0`, `OldUserStatusPaneApplyLegacyMovementStepAlt`, `ApplyLegacyMovementStepAlt`, `OldUserStatusPane`, `00009U`, `0001NR`, `000499`, `00049B`, `g_pConfig`, `g_activeMapPane`, `ShouldMaskLegacyMovementDirection`, `0x0067a7c8`, `0x005bf6cf`, `0x005bf6ea`, and `packet[10]`.
- `TARGET-REPORT-UID:00049A`: no prior executed or active report match was found. The only match was the current Agent-B011 `goal.md` assignment text.
- Relevant prior executed reports found and used:
  - `executed-b-agent-research/B002/0001NR-OldUserStatusPane-source-quality.md`: created UID00049A at `86/89`, body `0x005bf670-0x005bf7b0`, internal table `0x005bf7b0-0x005bf7c0`, owner UID00009U, emitter UID0001NR, and first formal C++ with earlier `g_pGameConfig` naming.
  - `executed-b-agent-research/B007/000499-OldUserStatusPaneApplyLegacyMovementStep-source-quality.md`: accepted UID000499 score lift to `89/91`; updated UID00049A as support with the same high-bit gate and `g_pConfig` fix but explicitly did not raise UID00049A score because it was support-only for that target.
  - `executed-b-agent-research/B009/0000P2-UserStatusPane-empty-emitter-family-source-quality.md` and `executed-b-agent-research/B013/0000P2-UserStatusPane-current-empty-emitter-checkpoint.md`: file-family context only; both preserve the accepted OldUserStatusPane exact-child route.
  - `executed-b-agent-research/B008/0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md`: supporting precedent for `g_pConfig+0x28de75` as a movement/map-status option byte, not a day/night or unrelated config field.
- Active Agent-B011 research folder search: no existing UID00049A report existed before this file was created.

### Current Docs And Generated Context

- Target doc: `by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md`.
  - Current metadata after callback: `COMPLETION:89`, `CONFIDENCE:91`, owner `00009U`, reconstructable `TRUE`, emitter `0001NR`.
  - Current formal C++ already uses `ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pConfig)`, early `false` return for nonnegative signed directions while the gate is active, high-bit mask for negative directions, field id `12` invalidation, and final `return false`.
- Class support: `by-class/OldUserStatusPane.md` already lists `0x005bf670-0x005bf7c0` as `ApplyLegacyMovementStepAlt`, records the internal table, names `g_pConfig`, and documents field id `12` rectangle support through UID000496.
- Aggregate support: `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md` already splits `0x005bf670-0x005bf7b0` body and `0x005bf7b0-0x005bf7c0` table, records the no-entry retained-helper policy, and says `g_activeMapPane` plus `g_pConfig` controls the high-bit gate.
- File support: `by-file/UserStatusPane.md` has the correct source placement and route. Pre-callback, it still contained stale current-generated header wording around `000000007740`; that wording is now historicalized, and current generated freshness is tracked by the final observed generated header.
- Generated context before callback: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` had `validator-command-id: 000000007773`, `validator-refreshed-at: 2026-07-07T01:56:42-04:00`, and contained UID00049A at `Completion:86 | Confidence:89` with the B007-corrected formal body.
- Generated context after callback validators/background refresh: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` has `validator-command-id: 000000007819`, `validator-refreshed-at: 2026-07-07T03:01:14-04:00`, `validator-refresh-source: deferred-generated-refresh`, and contains UID00049A at `Completion:89 | Confidence:91` with the accepted body unchanged.

### MCP Evidence / Session Summary

- MCP endpoint was responsive through IDA MCP JSON-RPC.
- `idb_list` session: `supervisor-nexustk-20260707`, active `true`, adopted worker session, database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, created `2026-07-07T01:20:19.134835`.
- `server_health`: `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Read-only tools used: `lookup_funcs`, `xrefs_to`, `find_bytes`, `get_bytes`, `insn_query`, and `int_convert`.
- No MCP edit tools, IDA patch/rename/type tools, validator tools, or lifecycle/execute commands were used.

## Target

- UID: `00049A`
- Path: `by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md`
- Pre-callback queue row: `86/89`, reconstructable `true`, direct report count `0`.
- Current post-callback metadata: `89/91`, reconstructable `TRUE`, owner `00009U`, emitter `0001NR`.
- Current source-facing role: retained no-entry `OldUserStatusPane::ApplyLegacyMovementStepAlt(const unsigned char *packet)` helper for the sibling legacy movement opcode.
- Current owner/emitter route: canonical owner UID00009U `OldUserStatusPane`; emitter UID0001NR `0x005bda40-0x005bfbc1.OldUserStatusPane`.

## Current Target State

- The page is not blank and was not rewritten from scratch.
- It still contains the corrected formal C++ body from B007 support work, unchanged.
- It now records direct B011 evidence for the range, body/table split, no-entry state, pointer-byte negative searches, table bytes/xref, sibling/successor relationship, `g_pConfig` gate, packet offsets, boundary sizing, generated freshness, and support/no-change disposition.
- The former current-state gap is closed: target metadata is now `89/91`, matching UID000499's evidence tier while preserving the no-entry/no-pointer confidence cap.

## Heuristic / Inference Reanalysis And Validation

### Body/Table Boundary

- Accepted boundary remains correct:
  - Full UID00049A range: `0x005bf670-0x005bf7c0` = `0x150` bytes / decimal `336`.
  - Code body: `0x005bf670-0x005bf7b0` = `0x140` bytes / decimal `320`.
  - Internal table: `0x005bf7b0-0x005bf7c0` = `0x10` bytes / decimal `16`.
- MCP `lookup_funcs` reports `0x005bf670` and `0x005bf7b0` are not functions, while successor `0x005bf7c0` is modeled `sub_5BF7C0` size `0x401`.
- MCP `xrefs_to 0x005bf7b0` reports one data xref from `0x5bf723`; MCP `insn_query` at `0x5bf723` shows `jmp ds:jpt_5BF723[eax*4]`, so the table is internal to the switch in this body.
- MCP `get_bytes 0x005bf7b0,16` returns `2a f7 5b 00 36 f7 5b 00 43 f7 5b 00 50 f7 5b 00`, four little-endian targets inside the `0x005bf670-0x005bf7b0` body. No separate table page should be created.

### No-Entry / No-Xref / No-Pointer Route

- MCP `xrefs_to 0x005bf670`: zero refs.
- MCP `find_bytes` for target entry pointer bytes found no matches for VA `70 F6 5B 00` or RVA `70 F6 1B 00`.
- MCP `find_bytes` for `B0 F7 5B 00` found only the internal switch-table operand at `0x5bf726`; the full table byte sequence was found at `0x5bf7b0`.
- MCP `find_bytes` for successor `0x005bf7c0` pointer bytes found no VA/RVA matches, while `xrefs_to 0x005bf7c0` reports the modeled status-payload function is called by the router at `0x5bdf24`.
- Interpretation: no-entry/no-pointer state remains a confidence cap and liveness caveat. It is not a reason to blank the source because the body is coherent, security-cookie-protected, table-owned, generated-emitted, and accepted under the OldUserStatusPane retained-helper policy.

### Relationship To UID000499 And UID00049B

- UID000499 is the immediate sibling movement helper at `0x005bf520-0x005bf670`, now scored `89/91` after B007 direct report.
- UID00049A has the same source role and same current blockers as UID000499: retained no-entry helper, internal table, no external entry refs, inferred helper/config field names, and an unresolved discarded `packet[10]` role.
- UID00049B begins at `0x005bf7c0`, is a modeled function, and has a real router code xref at `0x5bdf24`. That proves the end boundary for UID00049A and confirms UID00049A is not the router-called status payload.
- The direct UID00049A score should therefore align with UID000499 at `89/91`, not stay at the lower support-only `86/89` state.

### Instruction-Level Behavior

- Packet reads:
  - `0x5bf691-0x5bf69d`: reads `packet[1]` through the narrow-character helper into signed direction storage.
  - `0x5bf69a-0x5bf6ad`: calls `sub_575480` for `packet+2` and `packet+4`, accepted as `ReadPacketInt16BE`.
  - `0x5bf6b5-0x5bf6b9`: reads `packet+10` through the narrow-character helper; no later use was found in the body, matching `(void)packet[10];`.
- Active-map/config high-bit gate:
  - `0x5bf6c6`: calls `sub_5055D0` using `g_activeMapPane` context.
  - `0x5bf6cf`: loads `dword_67A7C8`, documented as `g_pConfig`.
  - `0x5bf6d4`: compares byte `[g_pConfig+0x28de75]` with `1`.
  - `0x5bf6e0-0x5bf6e2`: tests signed direction and jumps to the common false-return path for nonnegative values.
  - `0x5bf6e8-0x5bf6ea`: masks negative directions with `0x7f` and stores the masked byte.
- Direction and map-bound handling:
  - `0x5bf6f2-0x5bf6f4`: rejects direction `4` with the common false-return path.
  - `0x5bf6fa-0x5bf712`: reads active-map dimensions at `+0x3f4/+0x3f6` and builds movement bounds through `sub_4B7C50`.
  - `0x5bf71e-0x5bf723`: switch for directions `0..3`.
  - Cases at `0x5bf72a`, `0x5bf736`, `0x5bf743`, and `0x5bf750` adjust y/x and clamp to top/right/bottom/left bounds.
  - `0x5bf778` and `0x5bf781`: update `m_positionX`/`m_positionY` equivalents only when changed.
  - `0x5bf787-0x5bf797`: builds the field rectangle `(101,82,192,94)` and invalidates through the vtable path, equivalent to `InvalidateStatusFieldRect(12)` per UID000496.
  - `0x5bf79d`: `xor al, al`, so all paths return `false`.

## Evidence Standards Used

- Live MCP evidence was required and obtained; no fallback-only conclusion is used.
- Current by-* docs were treated as prior accepted project evidence, not as standalone proof when current MCP could verify the target.
- Generated output was used as context/freshness evidence only, not as source-final proof.
- Scores were compared against a directly analogous sibling only after confirming UID00049A has the same evidence strengths and blockers as UID000499.
- Negative evidence was explicitly separated from positive evidence. No-entry/no-pointer status caps confidence but does not erase source-shaped body evidence.

## Evidence Checked

| Evidence item | Result |
| --- | --- |
| `goal.md` and project B-agent workflow | Read and followed; report-only mode confirmed. |
| Target doc UID00049A | Pre-callback `86/89`; post-callback `89/91`; formal C++ corrected by B007 and preserved unchanged; direct B011 evidence now incorporated. |
| UID000499 sibling | Direct B007 report raised to `89/91`; behavior and blockers match UID00049A. |
| UID00049B successor | Modeled `sub_5BF7C0` starts at `0x005bf7c0` and has router code xref from `0x5bdf24`. |
| UID00009U class support | Already names UID00049A and support helpers; no score change needed. |
| UID0001NR aggregate support | Already owns body/table split and no-entry retained-helper policy; no score change needed. |
| UID0000P2 file support | Source placement is correct; generated-header caveat is stale relative to current `000000007773`. |
| `g_activeMapPane` support | Confirms active map dependency; not owner. |
| `g_pConfig` support | Confirms `0x0067a7c8` as `g_pConfig` and `+0x28de75` movement/map-status option byte. |
| Field id 12 support | UID000496 maps id `12` to `(101,82,192,94)`, matching movement position invalidation. |
| Packet read helper support | UID0003YK documents `sub_575480` as big-endian 16-bit scalar read helper. |
| Current generated output | Post-callback final observed header `000000007819` / `2026-07-07T03:01:14-04:00`; UID00049A now `89/91` and body matches current target C++. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| B011-49A-C01 | UID00049A is a retained source-shaped `OldUserStatusPane` alternate movement-step helper, not padding. | High | Valid security-cookie body, coherent packet reads, switch/table, generated body, accepted B002/B007 support. | Target Status/Behavior/Evidence | Incorporate direct B011 proof. | applied: target Behavior/Evidence now carries direct B011 proof. |
| B011-49A-C02 | Body/table boundary is `0x005bf670-0x005bf7b0` plus internal table `0x005bf7b0-0x005bf7c0`; no standalone table page is needed. | High | `lookup_funcs`, `xrefs_to`, `get_bytes`, `insn_query`, `int_convert`. | Target Status/Evidence; aggregate already sufficient | Add direct target-specific evidence; no aggregate score change. | applied: target Status/Evidence records boundary, table xref/bytes, and `int_convert` sizes; aggregate unchanged as already sufficient. |
| B011-49A-C03 | Target entry has no external xrefs or pointer-byte route. | High | `xrefs_to 0x005bf670` zero; `find_bytes` VA/RVA entry patterns zero. | Target Negative Evidence / Score Rationale | Add as confidence cap, not blank-source reason. | applied: target Evidence/Negative Evidence/Score Rationale record no-entry/no-pointer cap. |
| B011-49A-C04 | Successor UID00049B starts at `0x005bf7c0`, is modeled, and has router code xref at `0x5bdf24`; UID00049A is not the router-called status payload. | High | `lookup_funcs 0x005bf7c0`; `xrefs_to 0x005bf7c0`; UID00049B page. | Target Evidence / Negative Evidence | Add boundary and sibling-context note. | applied: target Evidence/Negative Evidence records successor/router distinction. |
| B011-49A-C05 | High-bit gate uses `g_activeMapPane` plus `g_pConfig+0x28de75`, returns `false` for nonnegative directions when active, and masks negative directions with `0x7f`. | High | `insn_query 0x5bf6c6-0x5bf6ea`; config docs. | Target Behavior/Evidence | Add direct instruction evidence; preserve formal C++. | applied: target Behavior/Evidence records gate, early false return, and mask. |
| B011-49A-C06 | `packet[10]` is read and discarded; no safe source name is proven. | Medium-high | `insn_query 0x5bf6b5-0x5bf6b9`; no later use in scoped instruction listing. | Target Behavior / Open Questions | Add unresolved role caveat; keep `(void)packet[10];`. | applied: target Behavior/Evidence/Negative Evidence records discarded byte and unresolved role; C++ unchanged. |
| B011-49A-C07 | Movement bounds and field id `12` invalidation are behavior-correct source factoring. | High | `insn_query` map-bound clamp/update path; UID000496 field id `12` rectangle `(101,82,192,94)`. | Target Behavior/Evidence | Add direct B011 proof. | applied: target Evidence records map-bound clamp, position update, and field id `12` invalidation. |
| B011-49A-C08 | Formal C++ should be preserved exactly. | High | Target current C++ matches MCP behavior and B007 accepted correction. | Target formal block | No C++ body edit. | already-present: formal block was preserved byte-for-byte in the target and generated output remains behavior-consistent. |
| B011-49A-C09 | Target score should move from `86/89` to `89/91`; owner/emitter/reconstructable metadata remain unchanged. | Medium-high | UID000499 sibling at `89/91`; current direct MCP closes same evidence classes for UID00049A; same remaining blockers. | Target metadata / Score Rationale | Raise score; preserve UID00009U, UID0001NR, reconstructable TRUE. | applied: target metadata now `89/91`; owner/emitter/reconstructable unchanged; validator `000000007811` confirmed. |
| B011-49A-C10 | Class and aggregate support docs already contain enough B007-level facts; no score movement is needed there. | Medium-high | Current UID00009U and UID0001NR pages list UID00049A, `g_pConfig`, high-bit gate, table refs, field id `12`. | Support docs | No required edit except optional breadcrumb if supervisor wants direct-report mention. | already-present: class/aggregate support docs were re-read and left unchanged; no contradiction found. |
| B011-49A-C11 | `by-file/UserStatusPane.md` had stale current generated-header wording. | High | Pre-callback file page cited `000000007740` as current; pre-callback generated recheck found `000000007773` / `2026-07-07T01:56:42-04:00`. | `by-file/UserStatusPane.md` generated-output caveat | Replace current header wording during callback if support edits are authorized; recheck after validators. | applied: file caveat and B007 change note now historicalize `000000007740` and record `000000007773` pre-callback context; final observed generated header is `000000007819`. |
| B011-49A-C12 | Generated output should become claim-consistent after scoped target validation. | Medium-high | Pre-callback generated UID00049A row was still `86/89`; target score recommendation required generated refresh. | Generated freshness note only | Do not edit generated manually; run scoped validator after callback and record header. | applied: generated `UserStatusPane.cpp` final observed header `000000007819` / `2026-07-07T03:01:14-04:00` and UID00049A `89/91` with accepted body. |

## Positive Evidence Summary

- UID00049A contains a valid `thiscall`-style raw body beginning with a normal prolog/security-cookie setup at `0x005bf670`.
- The code reads direction and big-endian x/y fields, consumes a discarded packet byte at offset `10`, checks active map/config state, masks signed high-bit directions, rejects direction `4`, clamps one-step movement to current map bounds, updates OldUserStatusPane position fields, invalidates the position field rectangle, and returns `false`.
- The internal table at `0x005bf7b0` has one internal data xref from the target switch site and four case targets inside the target body.
- Current support docs already route this body to `OldUserStatusPane` and `UserStatusPane.cpp`, and current generated output emits the corrected method body.
- UID000499 provides a strong direct sibling precedent at `89/91`; this direct UID00049A evidence now reaches the same quality tier.

## Negative Evidence Summary

- No code/data xref or pointer-byte route to entry `0x005bf670` was found. This remains the main confidence cap.
- IDA does not model `0x005bf670` or `0x005bf7b0` as functions; the helper is retained source-shaped raw code, not a normal externally reached method.
- Exact original spelling for `ShouldMaskLegacyMovementDirection`, the config field at `g_pConfig+0x28de75`, and the semantic role of `packet[10]` remain unproven.
- UID00049A should not be merged into UID00049B because UID00049B starts at `0x005bf7c0`, is modeled, and has the router code xref.
- `g_activeMapPane` and `g_pConfig` are dependencies only, not owner routes.

## Ranked Ownership Analysis

| Rank | Candidate | Assessment |
| ---: | --- | --- |
| 1 | UID00009U `OldUserStatusPane` / UID0001NR aggregate | Best owner. Body operates on OldUserStatusPane position fields and old status invalidation, sits inside the accepted OldUserStatusPane aggregate, and matches sibling helpers. |
| 2 | UID0000P2 `UserStatusPane.cpp` file | Correct file-level source route, but not the direct owner of the exact method page. |
| 3 | UID000499 sibling movement helper | Behavior precedent only. It should not absorb UID00049A because UID00049A has its own body/table range and method name. |
| 4 | UID00049B status payload | Rejected. It starts at successor `0x005bf7c0`, is modeled, and is router-called separately. |
| 5 | `g_activeMapPane` / `g_pConfig` support docs | Rejected as owners. They are dependencies used by the high-bit gate and map bounds. |
| 6 | Standalone table/data page | Rejected. Table is internal to target switch and has no separate source identity. |

## Source Placement

- Keep source placement under `NexusTK/ui/panels/UserStatusPane.cpp`, exact method on `OldUserStatusPane`.
- Keep canonical owner `00009U` and emitter `0001NR`.
- Keep range `0x005bf670-0x005bf7c0`, with the table tail owned by this child.
- Do not move this helper to `MenuVarietyPanes`, shared destructor/thunk tail, `MapPane`, Config, PacketBuffer, or UID00049B.

## First-Draft C++ Recommendation

Recommendation: preserve this exact formal `RECONSTRUCTION_CPP CODE` block unchanged. The insertion text below includes the required formal header, `BEGIN`, and `END` markers and is already present on the target:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool OldUserStatusPane::ApplyLegacyMovementStepAlt(const unsigned char *packet)
{
    signed char direction = static_cast<signed char>(packet[1]);
    int x = ReadPacketInt16BE(packet + 2);
    int y = ReadPacketInt16BE(packet + 4);
    (void)packet[10];

    if (ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pConfig))
    {
        if (direction >= 0)
            return false;

        direction &= 0x7f;
    }

    if (direction == 4)
        return false;

    RectBounds movementBounds;
    GetLegacyMovementBounds(g_activeMapPane, &movementBounds);

    switch (direction)
    {
    case 0:
        --y;
        if (y < movementBounds.top)
            y = movementBounds.top;
        break;
    case 1:
        ++x;
        if (x >= movementBounds.right)
            x = movementBounds.right - 1;
        break;
    case 2:
        ++y;
        if (y >= movementBounds.bottom)
            y = movementBounds.bottom - 1;
        break;
    case 3:
        --x;
        if (x < movementBounds.left)
            x = movementBounds.left;
        break;
    default:
        break;
    }

    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(12);
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why unchanged:

- `g_pConfig` is the current accepted source-facing name for `0x0067a7c8`.
- The helper predicate is source-shaped but direction handling remains explicit in the method, matching raw early return and mask behavior.
- `(void)packet[10];` accurately preserves the observed read without inventing a field name.
- The field id `12` call is supported by rectangle equivalence with UID000496.
- No MCP evidence suggests a semantic body change beyond the already-applied B007 correction.

## Final Recommendation

- Implementation callback completed after Gate 1:
  - UID00049A is now `COMPLETION:89`, `CONFIDENCE:91`.
  - `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR`, range, and formal C++ body were preserved.
  - Direct B011 evidence and score rationale were added to the target.
  - `by-file/UserStatusPane.md` stale current generated-header wording was historicalized and updated with UID00049A pre-callback generated context.
  - Scoped validators ran for both edited by-* files, generated output refreshed, and leases were released.
- Stop state: `READY_FOR_SUPERVISOR_EXECUTE`; supervisor Gate 2 verification and any `execute_report` lifecycle action remain supervisor-only.

## Recommended Target Doc Changes

Target: `by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md`

- Metadata:
  - `COMPLETION:86` -> `COMPLETION:89`
  - `CONFIDENCE:89` -> `CONFIDENCE:91`
  - Keep UID, owner, reconstructable, emitter, item summary, and formal C++ body unchanged.
- Add or expand target evidence with:
  - B011 MCP session `supervisor-nexustk-20260707`.
  - `lookup_funcs`: target/table not functions; successor `0x005bf7c0` modeled `sub_5BF7C0` size `0x401`.
  - `xrefs_to`: entry `0x005bf670` has zero refs; table `0x005bf7b0` has one data ref from `0x5bf723`; successor has router code ref from `0x5bdf24`.
  - `find_bytes`: no VA/RVA pointer-byte route to target entry; full table byte sequence located at `0x5bf7b0`; table-address bytes only internal to the switch operand.
  - Body/table sizes from `int_convert`: `0x150`/336 total, `0x140`/320 code body, `0x10`/16 table.
  - Instruction evidence for packet offsets, `g_pConfig+0x28de75`, early false return, `direction &= 0x7f`, map-bound clamp, position update, and field id `12` invalidation.
  - Generated freshness: current pre-callback generated header `000000007773` / `2026-07-07T01:56:42-04:00`, still showing UID00049A at `86/89`.
- Add score rationale:
  - Completion `89`: direct target MCP now documents boundary, table ownership, no-entry/pointer searches, gate behavior, packet fields, clamp/update/invalidation, generated context, and sibling placement.
  - Confidence `91`: aligned with UID000499 direct sibling; capped by no-entry/no-pointer route and unresolved exact source names for helper/config field/`packet[10]`.
- Add negative evidence:
  - No route to entry was found.
  - Not a separate table page.
  - Not UID00049B.
  - `g_activeMapPane` and `g_pConfig` are dependencies, not owners.

## Recommended Support Doc Changes

- `by-file/UserStatusPane.md`:
  - Replace stale current generated-header wording that cites `validator-command-id: 000000007740` with current or post-validator generated state.
  - Report-only current truth before implementation callback: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` has `validator-command-id: 000000007773`, `validator-refreshed-at: 2026-07-07T01:56:42-04:00`, and contains UID00049A at `86/89` with the accepted B007-corrected body.
  - During callback, recheck after scoped validator refresh. If a newer generated header exists, record that newer header and state UID00049A is generated-output claim-consistent at the implemented score.
- `by-class/OldUserStatusPane.md`:
  - No score change recommended.
  - No required edit; current support already lists UID00049A, internal table ownership, `g_pConfig`, high-bit gate, and field id `12` evidence. Optional callback breadcrumb may mention B011 direct target report if supervisor wants report provenance reflected in class support.
- `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md`:
  - No score change recommended.
  - No required edit; current aggregate already contains the body/table split, retained no-entry helper policy, `g_pConfig`, and B007 movement-helper evidence. Optional callback breadcrumb may mention B011 direct target report.
- `by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md`:
  - No edit recommended; sibling precedent already direct-reported and scored `89/91`.
- `by-memory/0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md`:
  - No edit recommended; only used as boundary/router negative evidence.
- `by-global/g_activeMapPane.md`, `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`, UID000496 field-rect support, and UID0003YK packet-read support:
  - No edit recommended. They already provide sufficient support for this target.

## Score And Metadata Recommendation

| Field | Current | Recommended | Reason |
| --- | --- | --- | --- |
| `COMPLETION` | `86` | `89` | Direct B011 evidence now covers exact body/table boundary, no-entry searches, instruction behavior, sibling/boundary context, formal C++ preservation, and generated freshness. |
| `CONFIDENCE` | `89` | `91` | Matches direct sibling UID000499 after equivalent evidence; capped by no-entry/no-pointer status and inferred names. |
| `CANONICAL_OWNER` | `00009U` | `00009U` | OldUserStatusPane remains the direct owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Body remains reconstructable and emitted. |
| `EMITTER_UIDS` | `0001NR` | `0001NR` | Aggregate route remains correct. |
| Formal C++ | Present | Preserve unchanged | Current body matches MCP behavior. |

## Open Questions With Attempted Resolution

- Exact original helper name `ShouldMaskLegacyMovementDirection`:
  - Attempted resolution: checked current target, UID000499, class/aggregate support, generated output, and instruction behavior. The helper name remains source-facing inferred but is acceptable because raw direction handling stays explicit in the method.
- Exact config field name at `g_pConfig+0x28de75`:
  - Attempted resolution: checked UID00028Q and B008. Best evidence supports a movement/map-status option byte; exact product/UI field spelling remains unresolved. Keep the field hidden behind the helper predicate.
- Semantic purpose of `packet[10]`:
  - Attempted resolution: instruction scan confirmed it is read and discarded; no later use or safe field name was found. Preserve `(void)packet[10];`.
- No-entry route:
  - Attempted resolution: `xrefs_to` and pointer-byte searches found no route. This caps confidence but does not defeat source reconstruction because the body is coherent and accepted as a retained OldUserStatusPane helper island.

## Validator Results

- Scoped target validator, first run:
  - Command: `python .\tools\validator.py --mode file --file by-memory\0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md --apply --queue-timeout 240 --wait-generated`
  - `command_id: 000000007810`
  - `command_timestamp: 2026-07-07T02:59:12-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Result: applied target score updates and generated refresh completed. It also reported `missing_ref_uid 0003YK` for a newly added UID-form packet-helper cross-reference.
- Scoped target validator, final run after removing the invalid UID-form packet-helper reference:
  - Command: `python .\tools\validator.py --mode file --file by-memory\0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md --apply --queue-timeout 240 --wait-generated`
  - `command_id: 000000007811`
  - `command_timestamp: 2026-07-07T02:59:45-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Result: generated refresh completed; no target-specific missing UID warning remained.
- Scoped support validator:
  - Command: `python .\tools\validator.py --mode file --file by-file\UserStatusPane.md --apply --queue-timeout 240 --wait-generated`
  - `command_id: 000000007812`
  - `command_timestamp: 2026-07-07T03:00:00-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Result: generated refresh completed. Existing support-file warnings `missing_ref_uid 0003A8` and `missing_ref_uid 0003AF` remain unrelated to UID00049A and were not introduced by this callback.
- Generated-output freshness after final callback validator/background refresh:
  - `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp`
  - `validator-command-id: 000000007819`
  - `validator-refreshed-at: 2026-07-07T03:01:14-04:00`
  - `validator-refresh-source: deferred-generated-refresh`
  - This header is newer than the final scoped support validator `000000007812` / `2026-07-07T03:00:00-04:00`.
  - UID00049A row now shows `Completion:89 | Confidence:91`.
  - `OldUserStatusPane::ApplyLegacyMovementStepAlt(const unsigned char *packet)` body remains the accepted body with `g_pConfig`, early false return, `packet[10]` discarded read, field id `12`, and final `return false`.
- Validator-owned side effects observed: generated metadata/report refreshes, `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` refresh, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-research-tracker.md`, `project-level/-auto-completion-stats.md`, `tools/validator.ini` registry rebuild, and validator autogen backups. These were scoped-validator side effects, not manual edits.
- Forbidden lifecycle actions not run: no `execute_report`, dry-run/probing execute variant, lifecycle/archive command, manual report move, registry lifecycle command, generated manual edit, coverage manual edit, supervisor-ledger edit, queue/lock edit, or validator-state manual edit.

## Changed Files

- Direct by-* edits:
  - `by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md`
  - `by-file/UserStatusPane.md`
- Report artifact updated:
  - `tools/leaser/Agents/Agent-B011/research/00049A-OldUserStatusPaneApplyLegacyMovementStepAlt-source-quality.md`
- Validator-owned generated/state side effects were produced only by the scoped validators listed above; no generated, coverage, validator-state, supervisor-ledger, lifecycle, archive, queue, or lock file was edited manually.
- Leases:
  - Acquired: `python .\tools\leaser\leaser.py B011 lease by-memory\0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md by-file\UserStatusPane.md`
  - Result: both paths `Success`.
  - Released: `python .\tools\leaser\leaser.py B011 unlease by-memory\0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md by-file\UserStatusPane.md`
  - Result: both paths `Success`.
  - Post-release lease check: no active B011 leases remained; only unrelated B006 leases were listed.

## Implementation Tracking Checklist

### Report-Only Checklist

- [x] Read Agent-B011 `goal.md` and project-level `ntk-b-agent-workflow` instructions.
- [x] Confirmed report-only mode and hard boundaries.
- [x] Searched required old-report terms, including `TARGET-REPORT-UID:00049A`, `00049A`, `0x005bf670`, `0x005bf7c0`, `0x005bf7b0`, `ApplyLegacyMovementStepAlt`, `OldUserStatusPane`, `00009U`, `0001NR`, `000499`, `00049B`, `g_pConfig`, `g_activeMapPane`, `ShouldMaskLegacyMovementDirection`, `0x0067a7c8`, `0x005bf6cf`, `0x005bf6ea`, and `packet[10]`.
- [x] Read current target, class, aggregate, file, sibling, successor, active-map/config, field-rect, packet-helper, generated-output, and research-tracker context.
- [x] Collected live MCP evidence from active session `supervisor-nexustk-20260707`.
- [x] Verified boundary/table, no-entry/no-pointer route, successor boundary, high-bit gate, `g_pConfig`, `packet[10]`, map-bound clamp, field id `12`, and return behavior.
- [x] Recommended score/metadata movement to `89/91` with owner/emitter/reconstructable unchanged.
- [x] Recommended formal C++ preservation unchanged with exact insertion text.
- [x] Did not edit by-* docs, generated files, coverage files, validator state, lifecycle/archive files, queue/lock files, or supervisor ledgers.
- [x] Did not run validators, `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry commands, manual report moves, or broad validation.

### Implementation-Callback Checklist

- [x] Acquire leases only after supervisor Gate 1 callback for the exact files to edit: UID00049A target and, if authorized, `by-file/UserStatusPane.md`. Proof: B011 lease command returned `Success` for both paths; no class/aggregate/support extras were leased.
- [x] Update UID00049A metadata: `COMPLETION:89`, `CONFIDENCE:91`; preserve UID, owner `00009U`, `RECONSTRUCTABLE:TRUE`, emitter `0001NR`, range, item summary unless wording is strictly improved, and formal C++ body unchanged. Proof: target header now `89/91`; owner/emitter/reconstructable unchanged; formal C++ untouched; validator `000000007811` `ok: 1`.
- [x] Add target evidence from B011-C01 through B011-C07: body/table boundary, internal table bytes/xref, no entry refs, no pointer-byte route, UID00049B successor boundary/router xref, packet offsets, `g_pConfig+0x28de75`, early false return, direction mask, map-bound clamp, position update, and field id `12` invalidation. Proof: target `Behavior`, `Evidence`, and `Negative Evidence` sections now carry these facts at report-level detail.
- [x] Add target negative evidence from B011-C03/C04/C06: no-entry route caps confidence, table is not standalone, target is not UID00049B, globals are dependencies, and `packet[10]` role remains unresolved. Proof: target `Negative Evidence` section records all listed exclusions/caps.
- [x] Add target score rationale from B011-C09 explaining `89/91` and remaining confidence caps. Proof: target `Score Rationale` section added with completion/confidence rows.
- [x] Preserve the formal `RECONSTRUCTION_CPP CODE` body exactly; do not change helper names, packet offsets, return behavior, or field id `12` call. Proof: final observed generated `UserStatusPane.cpp` header `000000007819` still emits the accepted `ApplyLegacyMovementStepAlt` body unchanged.
- [x] Support doc disposition: update `by-file/UserStatusPane.md` stale generated-header wording if authorized; otherwise record no support doc edit needed because B007 already covered class/aggregate support facts. Proof: `by-file/UserStatusPane.md` Data Caveats and B007 Changes note now historicalize `000000007740` and record `000000007773` pre-callback context; class/aggregate were not edited because they already contain same-or-greater B007 support facts.
- [x] No-change dispositions: leave UID000499, UID00049B, `g_activeMapPane`, `g_pConfig`, UID000496 field-rect support, and UID0003YK packet-helper support unchanged unless a direct contradiction appears during callback re-read. Proof: no direct contradiction found; those docs were not edited. The target cross-reference to packet-helper support was kept by path without an invalid UID-form reference after validator warning `000000007810`.
- [x] Run only the scoped validators listed in `Validator Results` after edits; do not run broad validators. Proof: ran file validators only for UID00049A target and `by-file\UserStatusPane.md`; no broad validators were run.
- [x] Confirm generated output freshness after scoped validator completion; record generated header command id/timestamp and UID00049A row/body consistency. Proof: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` final observed header `000000007819`, refreshed `2026-07-07T03:01:14-04:00`, deferred refresh; UID00049A row is `89/91` and body is accepted.
- [x] Release leases immediately after the edit/validator batch. Proof: B011 unlease command returned `Success` for both paths; post-release lease report showed no active B011 leases.
- [x] Update this report's ledger/checklist with callback-applied status, validator command IDs/timestamps/results, generated freshness, leases used/released, and changed files. Proof: `Claim And Incorporation Ledger`, `Validator Results`, `Changed Files`, and this checklist now record callback state.
- [x] Confirm no manual generated/coverage edits, supervisor-ledger edits, validator-state edits, lifecycle/archive/registry commands, manual report/archive moves, `execute_report`, or dry-run/probing execute variants were performed. Proof: only manual edits were the two accepted by-* docs and this report; generated/state changes were scoped-validator side effects only; no forbidden commands were run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000007822","destination_path":"executed-b-agent-research/B011/00049A-OldUserStatusPaneApplyLegacyMovementStepAlt-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/00049A-OldUserStatusPaneApplyLegacyMovementStepAlt-source-quality.md","timestamp":"2026-07-07T03:16:01-04:00","uid":"00049A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
