** TARGET-REPORT-UID:0003N9 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003N9 **
# 0003N9 ControlPaneDrawActiveFrameHelper Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) should gain [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) as `CANONICAL_OWNER` and `EMITTER_UIDS`.
- Final disposition: assigned raw `ControlPane` helper at `85/86`; no split, merge, rename, reclassification, new owner file, or IDA repair is required.
- Required action: target and directly related docs were updated and validated. Supervisor should apply the manual `by-memory/-coverage-report.md` replacement row below.
- Confidence: medium-high. Ownership is strong enough under the current raw-helper policy, but final C++ remains blocked because the helper still has no IDA function object, caller, table slot, pointer encoding, or recovered indirect-call route.

## Supporting Research

## Target
- Target UID: `0003N9`
- Target path: `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, previously reconstructable `no-owner`; current validator-generated row now lists `emits` through `000038`.
- Current supervisor classification: prior `reviewed-no-85` / no-owner post-migration recheck in `Supervisor_notes.md`; this pass supersedes that for the target metadata.
- Current scores and parent state: changed from `82/84`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` to `85/86`, `CANONICAL_OWNER:000038`, `EMITTER_UIDS:000038`.

## Executive Recommendation
- Assign the raw helper to [UID:000038][ControlPane](../../../../../by-class/ControlPane.md), with [UID:0000IG][ControlPane](../../../../../by-file/ControlPane.md) as the file route through the class.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `RECONSTRUCTION_CPP CODE` blank. The page is below the active `90/90+` code-entry gate because reachability and final source names remain unresolved.
- No split is needed. The exact half-open range is already clean: padding at `0x00494c4a-0x00494c50`, helper at `0x00494c50-0x00494c80`, and `ProgressBarControlPane` constructor starts at `0x00494c80`.

## Supervisor Active Recheck
- Trigger: current Goal 2 no-owner memory pass for `[UID:0003N9]`.
- Prior report read: `Agent-B002/research/executed/0003N9-ControlPaneDrawActiveFrameHelper-post-migration-recheck.md`; treated as background, not authority.
- Split status: no new split needed. The current exact child already exists and covers only this raw helper.
- Source-bearing child status: the single in-scope child has been repaired to owner/emitter routed state.

## Inference Research Guidance Check
- `by-structure.md` separates semantic ownership from output routing. This helper now has both through `ControlPane`: the class is the narrow semantic owner, and the class emitter routes to `ControlPane.cpp`.
- `inference_research.md` cautions against source-file proof from locality alone. The recommendation does not use locality alone; it combines exact bytes, field use, immediate sibling method semantics, negative owner evidence, and current raw-helper comparator policy.
- Existing documentation assumptions treated as uncertain: the prior no-owner conclusion and old coverage row wording. IDA facts were rechecked.

## Evidence Standards Used
- IDA MCP: `server_health`, `lookup_funcs`, `entity_query`, `xref_query`, `get_bytes`, `make_signature_for_range`, `search_text`, and `get_int`.
- Supplementary raw PE scan: VA/RVA pointer counts, vtable dword scan, direct branch/call target scan.
- Documentation evidence: target page, containing `0002PD` aggregate, `ControlPane` class/file, `ControlPane` vtable data/type pages, sibling ControlPane state helper pages, `ProgressBarControlPane` class/file, generated memory coverage, manual memory coverage, and supervisor notes.

## IDA MCP Facts
- Function/range facts: live MCP session `b001_0003gy` is `NexusTK.exe.i64`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready. `lookup_funcs` reports functions at `0x00494c10`, `0x00494c30`, `0x00494c80`, and `0x00494de0`; it reports no function at `0x00494c50`, `0x00494c51`, `0x00494c53`, or `0x00494c7e`.
- Entity inventory: `entity_query` over `0x00494a80-0x00495050` lists `0x00494c30` and then `0x00494c80`; no function starts at `0x00494c50`.
- Data/table/padding facts: `get_bytes` reads six `0xcc` bytes at `0x00494c4a-0x00494c50`, then the raw helper bytes through `0x00494c7f`. `make_signature_for_range 0x00494c50-0x00494c80` reports a unique `0x30`-byte signature (Verified with `int_convert.py`).
- Xref facts: `xref_query` reports zero xrefs to `0x00494c50`; only local fall-through to `0x00494c51`/`0x00494c53`; only local early-exit/control-flow xrefs to `0x00494c7e`. The successor constructor `0x00494c80` has the expected code xref from `0x005472d7`.
- Vtable facts: `get_int` confirms `0x00617ad8 -> 0x00494b80`, `0x00617adc -> 0x00494bb0`, `0x00617ae0 -> 0x00494bd0`, `0x00617ae4 -> 0x00494c00`, `0x00617ae8 -> 0x00494c10`, `0x00617aec -> 0x00494c30`, and `0x00617af0 -> 0x0041d690`; no `ControlPane` or `ProgressBarControlPane` vtable slot in the checked window points to `0x00494c50`.
- Negative IDA facts: no IDA function object, no external xref, no vtable slot, no known caller, and no outgoing callee query because the range is not a modeled function.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00494c4a-0x00494c50` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | alignment padding | FALSE | none | `100/strong` | unchanged |
| `0x00494c50-0x00494c80` | [UID:0003N9][ControlPaneDrawActiveFrameHelper](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) | raw active-frame draw helper | TRUE | [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) | `85/86` | assigned this pass |
| `0x00494c80-0x00494daa` | [UID:000119][ProgressBarControlPaneConstructor](../../../../../by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) | successor constructor | TRUE | [UID:0000AW][ProgressBarControlPane](../../../../../by-class/ProgressBarControlPane.md) | `86/90` | unchanged |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00494c50` | zero xrefs | no external entry evidence |
| `0x00494c51`, `0x00494c53` | local fall-through only | not independent entries |
| `0x00494c7e` | internal branches from `0x00494c5a` and `0x00494c63`, plus local flow from `0x00494c79` | helper early-exit/return target |
| `0x00494c6a -> 0x004b9660` | raw outgoing call from bytes | selects GrafPort color/state `0x80` |
| `0x00494c79 -> 0x004ba450` | raw outgoing call from bytes/search_text | draws rectangle frame for `this+0x44` |
| `0x005472d7 -> 0x00494c80` | successor constructor call | clean boundary after target |

## Documentation Evidence And IDA Status
- Existing docs supporting assignment: sibling [UID:0003N3], [UID:0003N4], [UID:0003N6], and [UID:0003N7] establish `+0x101` and `+0x102` as base `ControlPane` state bytes. The target consumes both fields and draws the base rectangle.
- Existing docs repaired: target page, [UID:0002PD] aggregate, [UID:000038] class page, and [UID:0000IG] file page were updated from below-gate candidate/no-owner wording to assigned raw helper wording.
- Generated state: `auto-generated/-ag-memory-coverage.md` now lists `0003N9` as `emits` through `000038` to `auto-generated/NexusTK/ui/core/ControlPane.cpp`.
- Manual coverage state: `by-memory/-coverage-report.md` still has the old no-owner row because B002 is not to edit it directly. Replacement text is below.

## Ranked Ownership Analysis

### 1. [UID:000038] ControlPane
- Evidence for: uses base `ControlPane` visible/active bytes `+0x101` and `+0x102`; clears base draw-state byte `+0x70`; draws inherited bounds at `this+0x44`; immediately follows assigned `ControlPane` state virtuals; no progress/button/text/radio-specific fields; parent class and file both clear the `85/85` gate.
- Evidence against: no function object, no external xref, no vtable slot, no pointer encoding, and no direct branch/call route.
- Decision: accepted. The missing route blocks final C++ and keeps confidence below sibling state virtuals, but not ownership.

### 2. `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Evidence for: this was the prior conservative state, and the raw helper remains unreachable by current static evidence.
- Evidence against: current Goal 2 inference rules discourage leaving reconstructable source-shaped code ownerless when a best direct owner is well supported; analogous current raw no-xref class helper [UID:0003N8] is assigned when exact bytes, field use, and class-local context are strong.
- Decision: rejected for current metadata.

### 3. [UID:0000AW] ProgressBarControlPane / [UID:0000MT] ProgressBarControlPane.cpp
- Evidence for: physical successor starts at `0x00494c80`.
- Evidence against: target does not touch progress fields `+0xf8`, `+0xfa`, or `+0xfc`; no ProgressBar vtable slot points to the helper; the helper ends before the constructor.
- Decision: rejected.

### 4. ButtonControlPane or ButtonChoiceControlCore
- Evidence for: broad nearby UI-control family and comparator raw helper [UID:0003N8].
- Evidence against: target is before the ButtonControlPane core, uses `+0x102` active state instead of ButtonControlPane selected state `+0x108`, and is already in the ControlPane state-helper band.
- Decision: rejected.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: none.
- Likely full contents: no new standalone source file is justified. The helper belongs in existing `NexusTK/ui/core/ControlPane.cpp`.
- Candidate related items that belong: the existing assigned `ControlPane` constructor/state/vtable children already belong there.
- Candidate related items rejected: `ProgressBarControlPane` helpers and ButtonChoice raw helpers remain separate owner families.
- Standalone, narrow, or broad source-file inference: narrow class-local helper inside the existing broad `ControlPane.cpp` source file.

## Negative Evidence Summary
- Checked and rejected a ProgressBar owner because IDA and docs tie ProgressBar to `0x00494c80+` and progress fields, not this helper.
- Checked and rejected Button/choice owners because their class-specific field patterns start later and use different state fields.
- Checked and rejected no-owner/no-emitter as the final state because the current docs now have an assigned raw no-xref comparator and this helper has enough base-class field/context evidence to clear `85/85`.
- Consumer/read xrefs do not drive the decision because there are none. The decision is from exact code semantics and class-local context, with the missing xref recorded as a final-source blocker.

## Final Recommendation
- Exact changes applied:
  - `0003N9`: `COMPLETION 82 -> 85`, `CONFIDENCE 84 -> 86`, `CANONICAL_OWNER NONE -> 000038`, `EMITTER_UIDS blank -> 000038`.
  - `0002PD`, `ControlPane` class, and `ControlPane` file docs updated to stop treating `0003N9` as current no-owner.
- Exact parent assignments applied: [UID:000038][ControlPane](../../../../../by-class/ControlPane.md).
- Exact items left no-owner/non-emitting and why: only the aggregate [UID:0002PD] remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS` because it is a mixed physical coverage container, not source output.
- Future work outside this assignment: find a real caller/table slot/source breadcrumb for the raw helper and settle final source helper/field names before adding C++.

## Required Manual Coverage Report Replacement
Replace the existing row under the `0x00494c4a-0x00494c50` padding row in `by-memory/-coverage-report.md` with:

```markdown
        - [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) 0x00494c50-0x00494c80 | raw-helper | ControlPaneDrawActiveFrameHelper : reconstructable : 85% : strong : B002 current Goal 2 pass assigns this unique raw helper to [UID:000038][ControlPane](by-class/ControlPane.md): exact source-shaped bytes check base `ControlPane` state bytes `this+0x101` and `this+0x102`, select color `0x80`, clear `this+0x70`, and call the GrafPort frame drawer for `this+0x44`. Current live IDA MCP and raw PE checks still find no IDA function object, no external xrefs to `0x00494c50`, no ControlPane/ProgressBar vtable slot, no VA/RVA pointer encoding, and no direct branch/call route, so final C++ remains blank below the `90/90+` code-entry gate; owner/emitter route through `ControlPane` is now strong enough under current raw-helper policy.
```

## Follow-Up Actions
- Supervisor actions: apply and validate the manual coverage replacement row above; update Supervisor_notes status if desired.
- A-agent actions: do not add reconstruction C++ until helper reachability and source names are much stronger.
- B002 future research actions: none for this target unless new xref/table/source evidence appears.

## Confidence
- Recommendation confidence: medium-high.
- Score confidence: `85/86` is justified but intentionally not higher because reachability is still unproven.
- Remaining uncertainty: whether the original source called this helper directly, kept it as an unused out-of-line member, or reached it through an unmodeled mechanism not recovered by current IDA/raw scans.

## Validator Results
- `python ...\validator.py --mode file --file ...\0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md --apply`: `ok: 1`; updated completion/confidence/canonical owner/emitter registry; refreshed `auto-generated/-ag-memory-coverage.md`.
- `python ...\validator.py --mode file --file ...\0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md --apply`: `ok: 1`.
- `python ...\validator.py --mode file --file ...\by-class\ControlPane.md --apply`: `ok: 1`.
- `python ...\validator.py --mode file --file ...\by-file\ControlPane.md --apply`: `ok: 1`.
- Unresolved validator warnings/errors: none reported for the changed files. Validator emitted expected project-wide `autogen_cpp_noop` and `autogen_emitter_has_no_code` notices.

## Changed Files
- Created:
  - `tools/leaser/Agents/Agent-B002/research/0003N9-ControlPaneDrawActiveFrameHelper-current-goal2-pass.md`
- Modified:
  - `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`
  - `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`
  - `by-class/ControlPane.md`
  - `by-file/ControlPane.md`
  - validator-owned generated/state files reported by validator: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and an autogen backup folder.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003N9","source_path":"executed-b-agent-research/B002/0003N9-ControlPaneDrawActiveFrameHelper-current-goal2-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
