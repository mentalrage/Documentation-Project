** TARGET-REPORT-UID:00049B **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00049B OldUserStatusPaneApplyLegacyStatusPayload Source Quality


## Finalized Report / Current Recommendation
- Current recommendation: implemented repair for [UID:00049B] as a router-called `OldUserStatusPane::ApplyLegacyStatusPayload` method under the existing OldUserStatusPane/UserStatusPane source route.
- Final disposition: source-authored method body, not padding, not shared destructor/thunk tail, not a movement helper, and not a standalone global/support owner.
- Required action: supervisor execute review only. The accepted target/support by-* details were applied during the Gate 1 implementation callback; no `execute_report`, lifecycle, archive, manual move, generated edit, or coverage edit was run by B004.
- Confidence: high for function/range/caller/packet behavior; medium-high for final field names because several status-row/tail-word names remain descriptive rather than original-name proof.

## Supporting Research
- Assignment: Agent-B004 new report-only source-quality research for [UID:00049B] `by-memory/0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md`.
- Old-report search terms used: `TARGET-REPORT-UID:00049B`, `00049B`, `0x005bf7c0`, `0x005bfbc1`, `OldUserStatusPaneApplyLegacyStatusPayload`, `OldUserStatusPane`, `00009U`, `0001NR`, `000499`, `00049A`, `ApplyLegacyMovementStep`, `ApplyLegacyMovementStepAlt`, `g_activeMapPane`, `g_pConfig`, `0x0067a7c8`, `packet[10]`, `packet[11]`, and `status payload`.
- Old-report search results: no prior direct executed or active report with `TARGET-REPORT-UID:00049B` was found. Relevant support hits were executed B002 `0001NR-OldUserStatusPane-source-quality.md`, executed B007 `000499-OldUserStatusPaneApplyLegacyMovementStep-source-quality.md`, active B011 `00049A-OldUserStatusPaneApplyLegacyMovementStepAlt-source-quality.md`, and executed B005 `0001KC-TotemFrame-source-quality.md`.
- Historical note: B002 created UID00049B with useful owner/split/caller evidence, but its first-draft C++ is superseded for this target by the current MCP recheck below.

## Target
- Target UID: `00049B`.
- Target path: `by-memory/0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md`.
- Report path: `tools/leaser/Agents/Agent-B004/research/00049B-OldUserStatusPaneApplyLegacyStatusPayload-source-quality.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` reports [UID:00049B] at `86/89`, combined `87.5`, reconstructable `true`, direct reports `0`.
- Current supervisor classification: Gate 1 passed and implementation callback applied; stop point is `READY_FOR_SUPERVISOR_EXECUTE`.
- Current scores and parent state after callback: target `90/92`, owner [UID:00009U], emitter [UID:0001NR], reconstructable TRUE; aggregate [UID:0001NR] `89/91`; class [UID:00009U] `89/91`; file [UID:0000P2] `90/87`.

## Current Target State
- Existing metadata after callback: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR`.
- Existing owner/emitter/reconstructable state: correct; retain [UID:00009U] `OldUserStatusPane` as canonical owner and [UID:0001NR] OldUserStatusPane aggregate as emitter.
- Existing C++/emitter state after callback: target formal C++ now has the accepted `bool` signature/body and `return false`; generated `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` refreshed through validator command `000000007819` and emits UID00049B at `90/92`.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims after callback:
  - Resolved: stale `void` return type replaced by `bool ...` returning `false`, matching router case `0x08` and target `xor al, al; retn 4`.
  - Resolved: stale fixed-offset `0x20`/`0x10` reads replaced by moving cursor behavior: initial `2`, changed to `31` after the `0x40` section, advanced by `8` after the `0x20` section.
  - Resolved: `packet+26` and `packet+28` stores to object offsets `+0x164` and `+0x166` added as `m_legacyStatusTailWord0/1`.
  - Resolved: class/field wording now models `m_nationId` as word-width storage while preserving low-byte accessor semantics.
  - Resolved: spirit invalidation now compares raw packet spirit before clamp.
  - Resolved: TotemFrame path now models `new TotemFrame();` and leaves singleton publication to the constructor.
  - Still inferred: original source spellings for status-row fields, skipped full-payload bytes, and tail-word fields remain unresolved and are documented as descriptive/inferred.
- Related target/support docs checked: target page, [UID:0001NR] aggregate, [UID:00009U] class, [UID:0000P2] UserStatusPane file, [UID:000499]/[UID:00049A] movement siblings, [UID:0003YK] PacketBuffer scalar readers, [UID:0000SK] `g_pTotemFrame`, [UID:00028Q] `g_pConfig`, generated `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp`, tracker and coverage rows, executed B002/B007/B005 reports, active B011 report.
- Current artifact/lifecycle status: implementation callback applied, report ledger/checklist updated, scoped file validators run for edited by-* docs, leases released, and no lifecycle/archive/execute/manual move command was run.

## Executive Recommendation
- Keep the target as `OldUserStatusPane::ApplyLegacyStatusPayload` under `UserStatusPane.cpp`.
- Update target formal C++ to a `bool` method returning `false`, with exact dynamic cursor behavior, word-width nation storage, `+0x164/+0x166` tail-word stores, raw-spirit comparison before clamp, and constructor-side `TotemFrame` singleton publication.
- Update support docs to correct the class signature and field map. The row/tail field names should be explicitly marked descriptive/inferred.
- No split, merge, rename, owner change, emitter change, or no-owner/non-emitting reclassification is recommended.

## Supervisor Active Recheck
- Triggering instruction: supervisor Gate 1 passed for [UID:00049B] and current Agent-B004 goal assigns the implementation callback.
- Split repair needed before final report: no new child split is needed; the existing child range is correct.
- Source-bearing children in scope: UID00049B is the only target. UID000499/UID00049A are support siblings only; no implementation change is recommended for them from this target.

## Inference Research Guidance Check
- IDA facts were treated as primary for function boundaries, callers, return type, packet offsets, field offsets, and padding.
- Existing B002 documentation was treated as useful but not authoritative where current MCP contradicted the formal C++.
- Generated `UserStatusPane.cpp` was used only as current emitted-state evidence, not source proof.
- Wave2/Wave3 material was not used as proof. No current override requires using stale generated aliases for this target.

## Heuristic / Inference Reanalysis And Validation
- Return type: `bool` is the best source-facing signature because router `0x005bdcb0` case `8` returns `sub_5BF7C0(...)`, and UID00049B ends with `xor al, al; retn 4`. Existing `void` wording is stale.
- Packet cursor: the `0x20`/`0x10` blocks are cursor-based, not fixed-offset. This matters when `0x40` coexists with either later flag.
- Full `0x40` section: binary reads fields at `packet+2`, `+4`, `+6`, `+7`, `+11`, `+15`, `+16`, `+19`, `+26`, and `+28`, then sets the next cursor to `31`. Bytes not named by this pass remain skipped/reserved payload bytes, not safe field names.
- Status dword layout: `0x20` updates object `+0x144` and `+0x14c`; `0x40` updates `+0x148` and `+0x150`; `0x10` updates `+0x154` and `+0x158`. Existing generic primary/secondary ordering is stale.
- Nation width: `0x005bdc30` returns byte `[ecx+0x13c]`, but UID00049B compares/stores word `[esi+0x13c]`; model storage as an unsigned 16-bit field and keep getter semantics as low-byte return.
- Tail words: `+0x164/+0x166` have no existing by-* source-facing names and no constructor/paint read found in the targeted filter. Use descriptive `m_legacyStatusTailWord0` and `m_legacyStatusTailWord1` until a wider packet/paint pass proves original names.
- TotemFrame path: `g_pTotemFrame` is checked; existing frame invalidates through vslot `+0x20`; otherwise `new TotemFrame()` is called. The constructor stores the singleton, so the call site should not claim a proven assignment store.

## Evidence Standards Used
- Evidence types used: live IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, `find_bytes`, `int_convert`, `decompile`, and `disasm`; generated tracker/output reads; existing by-* documentation; executed report comparison; negative xref/padding checks.
- Evidence is strong enough for implementation because the target is a modeled function with a direct router caller, current decompiler/disassembly agrees on packet offsets and stores, and byte checks prove the trailing range is alignment.
- Confidence stays below final-audit level because several source-facing field names remain descriptive and the skipped bytes inside the full status payload are not semantically named.

## Evidence Checked
- IDA MCP checks performed:
  - `idb_list` found active session `supervisor-nexustk-20260707`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
  - `server_health` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
  - `lookup_funcs` confirmed `0x005bf7c0` as `sub_5BF7C0`, size `0x401`; `0x005bfbc1` is not a function; `0x005bfbd0` is `sub_5BFBD0`, size `0xb`; router `0x005bdcb0` is `sub_5BDCB0`, size `0x28c`.
  - `xrefs_to` found exactly one code xref to `0x005bf7c0` from `0x005bdf24` inside router `0x005bdcb0`; no xrefs to `0x005bfbc1`; one xref to `0x005bfbd0` from shared tail context.
  - `get_bytes` showed `0x005bfbc1-0x005bfbd0` is fifteen `0xcc` bytes; `0x005bfbd0` begins the separate clear/helper function bytes.
  - `callees 0x005bf7c0` returned narrow byte reader `0x575470`, `PacketBufferReadUInt16BE`/`sub_575480`, `PacketBufferReadUInt32BE`/`sub_5754C0`, `InitRectBounds`/`sub_4B7C50`, allocator `0x4f4aa0`, `TotemFrame` constructor `0x598cc0`, and security cookie helper.
  - `find_bytes` for direct VA/RVA pointer patterns to `0x005bf7c0` found no matches; direct reachability is the router call.
  - `int_convert` verified `0x401` as decimal `1025` and field offsets such as `0x13c`/`316`, `0x164`/`356`, and `0x166`/`358`.
- by-* docs, support docs, old reports, generated reports, and trackers checked: listed in Current Target State.
- Negative checks performed: no direct old UID00049B report; no function at `0x005bfbc1`; no xrefs to `0x005bfbc1`; no pointer-byte route to target entry; no existing support name found for `+0x164/+0x166`; constructor/paint/hover/router field-filter did not show other uses of `+0x164/+0x166`.
- Failed, unavailable, or intentionally skipped checks: no execute/lifecycle/archive/manual move commands were run. Validators were skipped in the report-only phase and then run only as scoped file validators during the implementation callback.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| B004-49B-C01 | UID00049B is a modeled method at `0x005bf7c0`, size `0x401`, called by router `0x005bdf24`. | High | MCP `lookup_funcs`, `xrefs_to`, router decompile. | Target Evidence; aggregate Covered Ranges; class Method Map. | incorporate | applied in target Evidence/Behavior, aggregate Covered Ranges, and class Method Map |
| B004-49B-C02 | Existing `void` signature is stale; method returns `false` as a bool/char result. | High | Router returns `sub_5BF7C0`; target tail `xor al, al; retn 4`. | Target formal C++; class declaration. | replace | applied in target formal C++ and class declaration |
| B004-49B-C03 | `0x20`/`0x10` payload sections use a moving cursor, not fixed `packet+2/+6`. | High | Decompile and disasm around `0x5bfa80-0x5bfb39`. | Target Behavior and formal C++. | replace | applied in target formal C++, target Behavior, aggregate packet disposition, and by-file summary |
| B004-49B-C04 | `flags & 0x40` stores two 16-bit words from `packet+26/+28` to `this+0x164/+0x166`. | High | Decompile `this[178]/this[179]`; disasm `0x5bf86b-0x5bf887`. | Target formal C++; class and aggregate field tables. | add | applied in target formal C++, class fields, and aggregate field table/packet disposition |
| B004-49B-C05 | `m_nationId` storage is word-width even though `GetNationId()` returns the low byte. | High | UID00049B word compare/store; accessor disasm `mov al,[ecx+13Ch]`. | Class declaration and field evidence. | correct | applied in class declaration/field table and aggregate field table |
| B004-49B-C06 | Spirit change compares raw packet spirit before clamp and invalidates if raw packet byte differs. | High | Decompile/disasm `0x5bf8cb-0x5bf8e6`. | Target formal C++; Behavior. | replace | applied in target formal C++ and Behavior |
| B004-49B-C07 | TotemFrame creation should be modeled as `new TotemFrame();` with constructor-side singleton publication, not a proven call-site global assignment. | Medium-high | Decompile/disasm `0x5bf90c-0x5bf945`; TotemFrame/global docs. | Target formal C++; Behavior. | replace | applied in target formal C++ and Behavior |
| B004-49B-C08 | `0x005bfbc1-0x005bfbd0` remains padding/alignment before shared tail. | High | `get_bytes` all `0xcc`; `lookup_funcs` successor at `0x005bfbd0`. | Target Negative Evidence; aggregate range table. | preserve | applied/preserved in target Negative Evidence and aggregate range/padding notes |

## Positive Evidence Summary
- Direct facts supporting the recommendation: current MCP proves the modeled target function, exact range, one router caller, callee set, packet-field offsets, target return value, and padding boundary.
- Corroborating documentation/generated-report evidence: B002 and current by-* docs correctly place UID00049B under OldUserStatusPane/UserStatusPane; B007 reconfirms this target is separate from movement helpers; B005/TotemFrame docs corroborate the constructor callsite and singleton behavior; generated `UserStatusPane.cpp` emitted the stale body under validator command `000000007773` before callback and now emits the repaired UID00049B body under validator command `000000007819`.
- Strongest inference chain: direct router call plus target body disassembly proves this is the old status payload applicator; support docs prove the owner/source route; field names are descriptive where direct original names are not recoverable.

## IDA MCP Facts
- Function/range facts: `0x005bf7c0` is `sub_5BF7C0`, size `0x401`; `0x005bfbc1` is not a function; `0x005bfbd0` is `sub_5BFBD0`, size `0xb`; router `0x005bdcb0` is size `0x28c`.
- Data/table/padding facts: `0x005bfbc1-0x005bfbd0` is all `0xcc`; no separate table or source body starts there.
- Xref facts: exactly one code xref to target from `0x005bdf24`; no xrefs to `0x005bfbc1`; `g_pTotemFrame` has one target-local data ref at `0x005bf90c`.
- Vtable/global/type facts: invalidation calls use Pane vslot `+0x20`; TotemFrame constructor callsite is `0x005bf933`; `g_pTotemFrame` storage is `0x0069b35c`.
- Negative IDA facts: no direct VA/RVA pointer pattern to target entry found; no external evidence makes the movement helpers owners of UID00049B.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005bdcb0-0x005bdf3c` | aggregate row in [UID:0001NR] | Legacy packet/movement router; case `8` calls UID00049B. | TRUE | [UID:00009U] | aggregate `89/91` | support |
| `0x005bf520-0x005bf670` | [UID:000499] | Retained no-entry movement helper with internal table. | TRUE | [UID:00009U] | `89/91` | support only |
| `0x005bf670-0x005bf7c0` | [UID:00049A] | Retained no-entry movement helper alternate. | TRUE | [UID:00009U] | current docs `86/89` | support only |
| `0x005bf7c0-0x005bfbc1` | [UID:00049B] target | Router-called status payload applicator. | TRUE | [UID:00009U] | `86/89` -> recommend `90/92` | repair C++/details |
| `0x005bfbc1-0x005bfbd0` | aggregate padding row | Alignment before shared tail. | FALSE/no source body | [UID:0001NR] documentation only | n/a | preserve |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005bdf24 -> 0x005bf7c0` | router case `8` returns `sub_5BF7C0((_WORD *)this - 80, packet)` | Direct route from legacy router to status payload applicator. |
| `0x005bf810`, `0x005bf872`, `0x005bf882` | calls `sub_575480` | Big-endian 16-bit packet reads for nation and two full-payload tail words. |
| `0x005bf836`, `0x005bf842`, `0x005bfa8f`, `0x005bfaa0`, `0x005bfb23`, `0x005bfb34` | calls `sub_5754C0` | Big-endian 32-bit packet reads for status rows. |
| `0x005bf90c` | reads `g_pTotemFrame` | Existing frame invalidation versus constructor path. |
| `0x005bf933` | calls `sub_598CC0` | TotemFrame constructor when singleton absent. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: UID0001NR range map, UID00009U method map, UID0000P2 file grouping, UID0003YK PacketBuffer helper names, UID0000SK/UID0002VR TotemFrame singleton lifecycle.
- Existing docs that are stale, incomplete, or contradicted: target formal C++ return type, fixed-offset `0x20`/`0x10` reads, missing `+0x164/+0x166` stores, byte-width `m_nationId`, pre-clamp spirit comparison, and call-site assignment to `g_pTotemFrame`.
- Generated/coverage report state: generated `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` was stale at `validator-command-id: 000000007773`, refreshed `2026-07-07T01:56:42-04:00`, before callback. Scoped validation refreshed it to `validator-command-id: 000000007819`, refreshed `2026-07-07T03:01:14-04:00`, with UID00049B at `90/92` and the bool body.

## Ranked Ownership Analysis

### 1. OldUserStatusPane / UserStatusPane.cpp
- Evidence for: target is inside the OldUserStatusPane executable island, called by the OldUserStatusPane router, uses OldUserStatusPane fields, and uses OldUserStatusPane rectangle invalidation/status assets.
- Evidence against: exact original field names for several rows/tail words are not recovered.
- Decision: keep owner [UID:00009U], emitter [UID:0001NR], source file [UID:0000P2].

### 2. TotemFrame
- Evidence for: target creates/invalidates `g_pTotemFrame` when spirit changes.
- Evidence against: TotemFrame is a dependency/singleton target, not the owner of the status payload parser.
- Decision: reject owner change; preserve as support dependency.

### 3. Movement helpers / MapPane / Config
- Evidence for: sibling movement helpers use `g_activeMapPane` and `g_pConfig`; old-report search terms overlap this neighborhood.
- Evidence against: UID00049B has a distinct modeled function and direct router call; this body does not own movement helper gate logic.
- Decision: reject as owners; mention only as support context.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file; use existing `UserStatusPane.cpp` / `OldUserStatusPane`.
- Likely full contents: status pane classes and child OldUserStatusPane methods already grouped under [UID:0000P2].
- Candidate related items rejected: no new child for `0x005bfbc1-0x005bfbd0`; no separate packet-layout owner for the target body.
- Standalone, narrow, or broad source-file inference: narrow method repair inside existing source file.

## Source Placement
- Recommended source file/class/global/module placement: `OldUserStatusPane::ApplyLegacyStatusPayload` in `NexusTK/ui/panels/UserStatusPane.cpp` under class [UID:00009U].
- Why this placement fits: constructor/router/paint/status helpers and generated file grouping already place OldUserStatusPane in UserStatusPane source.
- Rejected placements: TotemFrame, PacketBuffer, MapPane, Config, generic packet router, and no-owner/non-emitting.
- Remaining placement uncertainty: none that affects owner/emitter; only final field/member names remain inferred.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: target begins at modeled function `0x005bf7c0`, size `0x401`, ends at `0x005bfbc1`; `0x005bfbc1-0x005bfbd0` is `0xcc` alignment; shared tail begins at `0x005bfbd0`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new child; repair existing UID00049B body and support text only after Gate 1.
- Padding/table/data/code distinctions: target is code; successor gap is padding; movement helper internal table remains owned by UID00049A and is not part of this target.
- Parent/container impact: update aggregate field notes and range evidence; keep aggregate formal C++ as `[[CHILDREN]]`.

## Negative Evidence Summary
- No direct old UID00049B report exists to incorporate beyond B002 support context.
- `0x005bfbc1` is not a function and has no xrefs; do not extend the target into padding.
- No pointer-byte hits to `0x005bf7c0` were found; the direct route is the router call.
- Constructor/paint/hover field filters did not find other reads of `+0x164/+0x166`; do not invent original names or display semantics for the tail words.
- Movement-helper `g_activeMapPane`/`g_pConfig` evidence does not transfer ownership or behavior into UID00049B.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments:
  - Change method signature to `bool ApplyLegacyStatusPayload(const unsigned char *packet)`.
  - Change `m_nationId` storage to `unsigned short`; keep `GetNationId()` low-byte return semantics.
  - Use descriptive status row fields: `m_statusRow8PartialValue`, `m_statusRow8FullValue`, `m_statusRow9PartialValue`, `m_statusRow9FullValue`, `m_statusRow10Value`, `m_statusRow11Value`.
  - Add descriptive tail fields: `m_legacyStatusTailWord0` at `+0x164`, `m_legacyStatusTailWord1` at `+0x166`.
  - Prefer `PacketBufferReadUInt16BE`/`PacketBufferReadUInt32BE` for unsigned packet scalar reads in this target; signed coordinate aliases can remain in movement/position helpers.
- Evidence for each proposed name/type/comment: direct disassembly offsets and PacketBuffer helper docs; original names not proven for row/tail fields, so mark them inferred.
- Items intentionally left unchanged and why: owner/emitter/source file, target range, and target name are already well supported.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested in this report.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text for the target page:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool OldUserStatusPane::ApplyLegacyStatusPayload(const unsigned char *packet)
{
    const unsigned char flags = packet[1];
    unsigned char cursor = 2;

    if ((flags & 0x40) != 0)
    {
        const unsigned short nationId = PacketBufferReadUInt16BE(packet + 2);
        const signed char packetSpiritId = static_cast<signed char>(packet[4]);
        const unsigned char classId = packet[6];
        const unsigned int statusRow8FullValue = PacketBufferReadUInt32BE(packet + 7);
        const unsigned int statusRow9FullValue = PacketBufferReadUInt32BE(packet + 11);
        const unsigned char attributeLeft = packet[15];
        const unsigned char attributeRight = packet[16];
        const unsigned char attributeCenter = packet[19];

        m_legacyStatusTailWord0 = PacketBufferReadUInt16BE(packet + 26);
        m_legacyStatusTailWord1 = PacketBufferReadUInt16BE(packet + 28);
        cursor = 31;

        if (m_nationId != nationId)
        {
            m_nationId = nationId;
            InvalidateStatusFieldRect(1);
        }

        if (m_spiritId != packetSpiritId)
        {
            signed char spiritId = packetSpiritId;
            if (spiritId < -1)
                spiritId = -1;
            if (spiritId > 3)
                spiritId = 3;

            m_spiritId = spiritId;
            InvalidateStatusFieldRect(2);

            if (g_pTotemFrame != NULL)
                g_pTotemFrame->InvalidateFrame();
            else
                new TotemFrame();
        }

        if (m_classId != classId)
        {
            m_classId = classId;
            InvalidateStatusFieldRect(4);
        }

        if (m_statusRow8FullValue != statusRow8FullValue)
        {
            m_statusRow8FullValue = statusRow8FullValue;
            InvalidateStatusFieldRect(8);
        }
        if (m_statusRow9FullValue != statusRow9FullValue)
        {
            m_statusRow9FullValue = statusRow9FullValue;
            InvalidateStatusFieldRect(9);
        }

        if (m_attributeLeft != attributeLeft)
        {
            m_attributeLeft = attributeLeft;
            InvalidateStatusFieldRect(5);
        }
        if (m_attributeRight != attributeRight)
        {
            m_attributeRight = attributeRight;
            InvalidateStatusFieldRect(7);
        }
        if (m_attributeCenter != attributeCenter)
        {
            m_attributeCenter = attributeCenter;
            InvalidateStatusFieldRect(6);
        }
    }

    if ((flags & 0x20) != 0)
    {
        const unsigned int statusRow8PartialValue = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;
        const unsigned int statusRow9PartialValue = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;

        if (m_statusRow8PartialValue != statusRow8PartialValue)
        {
            m_statusRow8PartialValue = statusRow8PartialValue;
            InvalidateStatusFieldRect(8);
        }
        if (m_statusRow9PartialValue != statusRow9PartialValue)
        {
            m_statusRow9PartialValue = statusRow9PartialValue;
            InvalidateStatusFieldRect(9);
        }
    }

    if ((flags & 0x10) != 0)
    {
        const unsigned int statusRow10Value = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;
        const unsigned int statusRow11Value = PacketBufferReadUInt32BE(packet + cursor);

        if (m_statusRow10Value != statusRow10Value)
        {
            m_statusRow10Value = statusRow10Value;
            InvalidateStatusFieldRect(10);
        }
        if (m_statusRow11Value != statusRow11Value)
        {
            m_statusRow11Value = statusRow11Value;
            InvalidateStatusFieldRect(11);
        }
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: preserves bool false return, dynamic cursor advancement, exact 16/32-bit packet reads, raw-spirit compare before clamp, all observed field stores, dirty rectangle invalidations, TotemFrame create/invalidate path, and padding boundary exclusion.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: source-level helper calls replace raw decompiler labels; status rows use descriptive members; `new TotemFrame();` relies on the constructor singleton publication already documented for the class.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: status-row and tail-word member names are descriptive/inferred; PacketBuffer helper names are canonical support names from UID0003YK.
- Naming/coding style convention used and evidence for consistency: follows existing OldUserStatusPane child C++ style with `InvalidateStatusFieldRect`, class members, and packet helper calls, while correcting the stale helper and field names.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes recommended/applied: repair UID00049B formal C++, behavior/evidence text, stale assumptions, and score; update support field/signature docs at report-level detail.
- Exact parent assignments recommended: keep `CANONICAL_OWNER:00009U`, `EMITTER_UIDS:0001NR`, reconstructable TRUE.
- Exact items left no-owner/non-emitting and why: `0x005bfbc1-0x005bfbd0` remains alignment/padding, not a source item.
- Exact future work outside this assignment scope: a broader OldUserStatusPane paint/resource pass may recover original names for skipped full-payload bytes and the `+0x164/+0x166` tail words; this is not required to repair UID00049B behavior.

## Recommended Target Doc Changes
- Target path: `by-memory/0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md`.
- Exact report facts incorporated during callback:
  - Current MCP session and function/caller/range facts.
  - Method returns bool false and router case `8` returns the method result.
  - `0x40` section exact reads/stores, including `packet+26/+28 -> +0x164/+0x166` and `cursor = 31`.
  - `0x20` and `0x10` use cursor-based offsets.
  - Spirit invalidation compares raw packet spirit before clamp.
  - TotemFrame creation uses constructor-side singleton publication.
  - Preserve tail padding and shared-tail negative evidence.
- Metadata/score/owner/emitter/reconstructable/C++ changes: applied `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter unchanged, reconstructable TRUE, and replaced formal C++ with the block above.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: B002 owner/split/router facts remain accepted; B002 formal C++ is superseded only for UID00049B body details.

## Recommended Support Doc Changes
- Support path: `by-class/OldUserStatusPane.md`.
  - Exact facts incorporated: changed method declaration to `bool ApplyLegacyStatusPayload(const unsigned char *packet)`; changed `m_nationId` storage to `unsigned short`; updated status row fields to the offset/order in this report; added `unsigned short m_legacyStatusTailWord0` and `m_legacyStatusTailWord1` after `m_positionY`; marked row/tail names inferred.
  - Metadata/link/score/coverage/source-placement changes: applied raise `88/90 -> 89/91`; owner/emitter unchanged.
- Support path: `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md`.
  - Exact facts incorporated: updated field table and packet disposition for cursor-based UID00049B behavior; added the `+0x164/+0x166` tail-word caveat; kept aggregate formal C++ as `[[CHILDREN]]`.
  - Metadata/link/score/coverage/source-placement changes: no required score change; optional confidence wording can mention UID00049B repair.
- Support path: `by-file/UserStatusPane.md`.
  - Exact facts incorporated: recorded that generated output `000000007773` contained stale UID00049B body before callback and that scoped validators refreshed generated output through `000000007819`; source route remains `ui/panels/UserStatusPane.cpp`.
  - Metadata/link/score/coverage/source-placement changes: no score change required.
- Support path: `by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md`, `by-global/g_pTotemFrame.md`, and exact TotemFrame storage/global docs.
  - Exact facts to incorporate: no required edits; cite as existing support for helper names and constructor-side singleton publication if implementation callback needs cross-reference wording.

## Score And Metadata Recommendation
- Starting score/metadata: target `86/89`, owner [UID:00009U], emitter [UID:0001NR], reconstructable TRUE.
- Applied score/metadata: target `90/92`, owner/emitter/reconstructable unchanged; class [UID:00009U] raised to `89/91`; aggregate/file scores unchanged.
- Score rationale and reason not higher/lower: increase because direct MCP resolves behavior-significant stale C++ and field/cursor details; do not exceed low 90s because final original names for the status rows, skipped full-payload bytes, and tail words remain unresolved.
- Score-improvement attempt:
  - Return-type blocker: resolved by router and tail disassembly.
  - Cursor blocker: resolved by decompile/disasm.
  - Missing tail-word blocker: resolved as stores, not named semantics.
  - Field-name blocker: partially resolved to descriptive names; original proof unavailable in current docs/MCP pass.
  - Helper-name blocker: use canonical PacketBuffer support names for unsigned status fields.
- Metadata fields changed or left unchanged: changed only target/class completion-confidence and target/class C++/field details after supervisor approval; kept owner, emitter, reconstructable, split, rename, and source placement unchanged.

## Open Questions With Attempted Resolution
- Open questions found:
  - Original names and semantic display role for `+0x164/+0x166`.
  - Exact source names for the `+0x144/+0x148/+0x14c/+0x150/+0x154/+0x158` status rows.
  - Meaning of skipped full-payload bytes between named packet offsets.
- Evidence checked for each: target decompile/disasm, constructor/paint/hover/router field filters, existing class/aggregate/file docs, generated output, PacketBuffer/TotemFrame support docs, executed B002/B007/B005 reports.
- Best supported resolution or inference: use descriptive row/tail names and document unresolved original spelling; do not omit behavior or invent skipped-byte semantics.
- Questions remaining unresolved: original field names and skipped-byte semantics remain unresolved; this caps score but does not block first-draft C++ because exact reads/stores and side effects are proven.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Applicable only when an explicit manual `-coverage-report.md` or supervisor-owned tracker row needs a change: not applicable.
- Do not write row text for validator-owned `auto-generated/-ag-*` reports: no generated/coverage edits are recommended for B-agent application.
- File/placement: n/a.
- Exact replacement/insert/delete text: n/a.
- Reason B agent must not apply it directly: assignment forbids generated/coverage edits.

## Follow-Up Actions
- Supervisor actions: review this implementation callback and run supervisor-owned execute/lifecycle step if accepted.
- A-agent actions: none.
- B004 future implementation actions: none pending for accepted UID00049B items.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: source-original field names for status rows, skipped full-payload bytes, and tail words.

## Validator Results
- Scoped validators run during implementation callback:
  - `000000007800`, `2026-07-07T02:54:37-04:00`, `python .\tools\validator.py --mode file --file by-memory\0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md --apply --queue-timeout 240`; exit 0, `ok: 1`; side effects included target completion/confidence update to `90/92`, autogen registry update, UID link insertions for `00009U` and `0001NR`, projected stats update, and deferred generated refresh.
  - `000000007802`, `2026-07-07T02:54:47-04:00`, `python .\tools\validator.py --mode file --file by-class\OldUserStatusPane.md --apply --queue-timeout 240`; exit 0, `ok: 1`; side effects included class completion/confidence update to `89/91`, autogen registry update, projected stats update, and deferred generated refresh.
  - `000000007803`, `2026-07-07T02:54:55-04:00`, `python .\tools\validator.py --mode file --file by-memory\0x005bda40-0x005bfbc1.OldUserStatusPane.md --apply --queue-timeout 240`; exit 0, `ok: 1`; side effects included UID link insertion for `0001NS`, projected stats update, and deferred generated refresh.
  - `000000007805`, `2026-07-07T02:55:07-04:00`, `python .\tools\validator.py --mode file --file by-file\UserStatusPane.md --apply --queue-timeout 240`; exit 0, `ok: 1`; side effects included projected stats update, deferred generated refresh, and pre-existing/unrelated `missing_ref_uid` warnings for `0003A8` and `0003AF`.
  - `000000007809`, `2026-07-07T02:59:06-04:00`, `python .\tools\validator.py --mode file --file by-class\OldUserStatusPane.md --apply --queue-timeout 240`; exit 0, `ok: 1`; follow-up stale generated-caveat wording repair in the class doc; side effects included projected stats update and deferred generated refresh.
  - `000000007819`, `2026-07-07T03:01:14-04:00`, `python .\tools\validator.py --mode file --file by-file\UserStatusPane.md --apply --queue-timeout 240`; exit 0, `ok: 1`; follow-up stale generated-caveat wording repair in the file doc; side effects included projected stats update, deferred generated refresh, and pre-existing/unrelated `missing_ref_uid` warnings for `0003A8` and `0003AF`.
- Generated freshness check:
  - `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` header is `validator-command-id: 000000007819`, `validator-refreshed-at: 2026-07-07T03:01:14-04:00`, `validator-refresh-source: deferred-generated-refresh`; read-only grep confirmed UID00049B emits `bool ApplyLegacyStatusPayload`, `m_legacyStatusTailWord0/1`, `PacketBufferReadUInt16BE`, and `return false`.
  - Queue-status check `000000007807`, `2026-07-07T02:55:21-04:00`, observed generated refresh work in progress before the final header recheck; no lifecycle or execute command was run.
- Lease use: leased the four initial by-* edit targets as B004 before editing/validation and released them immediately after the validator batch. Follow-up leases were taken only for `by-class/OldUserStatusPane.md` and then `by-file/UserStatusPane.md` to repair stale generated-caveat wording, each released immediately after its scoped validator. Final post-release lease grep found no active `B004`/UID00049B matches.
- Any unresolved validator warnings/errors: only the by-file validator's pre-existing/unrelated `missing_ref_uid` warnings for `0003A8` and `0003AF`; no UID00049B validator blocker.

## Changed Files
- Created/updated report: `tools/leaser/Agents/Agent-B004/research/00049B-OldUserStatusPaneApplyLegacyStatusPayload-source-quality.md`.
- Modified by-* docs: `by-memory/0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md`, `by-class/OldUserStatusPane.md`, `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md`, `by-file/UserStatusPane.md`.
- Validator-owned side effects observed: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` and `project-level/-auto-completion-stats.md`; no manual generated or coverage edits were made.
- Renamed: none.
- Report execution: not run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update: target UID00049B; support UID00009U, UID0001NR, UID0000P2; helper/TotemFrame docs as references only unless callback requires wording.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply: target `86/89 -> 90/92`; optional class `88/90 -> 89/91`.
- [x] Score-limiting blockers researched to resolution or evidence-backed unresolved state.
- [x] Owner/emitter/reconstructable changes to apply: none.
- [x] Split/rename/new-child changes to apply: none.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable.
- [x] First-draft C++ or no-code proof to apply: first-draft formal block supplied.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail recorded.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve recorded.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable.
- [x] Open questions to close or document as evidence-backed unresolved.
- [x] Validators to run: none in report-only pass; scoped validators only after implementation callback.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated refresh expected only through validator after implementation; no manual generated/coverage edit.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: Gate 1 passed for UID00049B, implementation callback assigned in `goal.md`.
- [x] All accepted target/support doc details incorporated at report-level detail: target UID00049B, class UID00009U, aggregate UID0001NR, and file UID0000P2 updated.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target `90/92`, class `89/91`, owner/emitter/reconstructable/split/rename unchanged, target formal C++ replaced.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: original row/tail names and skipped-byte semantics remain descriptive/inferred.
- [x] Validators run and results recorded: scoped file validators `000000007800`, `000000007802`, `000000007803`, `000000007805`, `000000007809`, and `000000007819`.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: generated source refreshed through validator command `000000007819`.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000007820","destination_path":"executed-b-agent-research/B004/00049B-OldUserStatusPaneApplyLegacyStatusPayload-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00049B-OldUserStatusPaneApplyLegacyStatusPayload-source-quality.md","timestamp":"2026-07-07T03:06:06-04:00","uid":"00049B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
