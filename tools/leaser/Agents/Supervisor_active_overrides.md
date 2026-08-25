# Supervisor Active Overrides

## Immediate Supervisor Validation Lock

This section is the first rule for any B-agent report validation work.

- Current operational preflight: before explaining, defending, callbacking,
  clearing revalidation, counting, or running `execute_report` for any B-agent
  report, apply
  `.codex/skills/ntk-b-agent-workflow/references/supervisor-b-report-validation-preflight.md`.
  If the exact current artifact lacks a current hash/timestamp-matching Gate 1
  audit with full `##` heading line list and content notes for every
  required/triggered section, the report is `NOT_VALIDATED`. For already
  executed reports, fail closed through documented validator
  `needs-revalidation` or invalidation lifecycle before defending, counting,
  clearing, callbacking, or re-executing.
- Immediate binding correction from the current validation incident: if a user
  says I am breaking B-report validation rules, asks why I validated a named
  report, or identifies a missing-section report, stop that report's lifecycle
  first. Unless a current hash/timestamp-matching Gate 1 audit already proves
  the exact current artifact passes every required/triggered section with
  content notes, the status is `SUSPECT_NOT_VALIDATED`. For already executed
  artifacts, immediately use documented validator lifecycle to mark
  `needs-revalidation` or invalidate before defending, counting, clearing,
  callbacking, or re-executing. Post-hoc audits do not justify earlier bad
  callbacks/executions; useful implementation and validator success are not
  mitigation.
- Literal all-or-fail Gate 1 override: missing, renamed, merged, broad, stale,
  shallow, contradicted, implementation-log-only, or scattered substitutes for
  required template headings fail the report. The correct action is same-report
  repair, or validator revalidation/invalidation for an executed copy.
- Immediate self-correction from validation failures: if the user says I am
  breaking B-report validation rules, or names a report that appears to have
  been accepted/executed while missing required sections, I must stop normal
  lifecycle handling for that report. The next action is not explanation,
  defense, callback, clearance, or another `execute_report`; it is to audit the
  exact current/archived report artifact from disk, record hash/timestamp and
  every `##` heading line in `b-report-validation-audit.md`, apply the literal
  Gate 1 matrix with content notes, and fail closed. If the report is already
  executed and lacks a current matching `GATE1_PASSED` audit or fails any row,
  immediately use documented validator lifecycle to mark it
  `needs-revalidation` or invalidate it before counting or defending it.
- Report-quality validation is artifact-first and pre-action only. A report
  cannot be rescued by later by-* edits, scoped validator success, generated
  output, score changes, archive movement, or `execute_report` success. If I
  did not validate the exact report artifact before the lifecycle action, that
  action was process-invalid and must be repaired through same-report repair or
  validator revalidation/invalidation.
- Mandatory operator preflight: before I call a B report valid, issue a
  callback, clear revalidation, count/defend an executed report, or run
  `execute_report`, I must complete the same four-step check: open the exact
  current artifact path; record SHA256 or last-write timestamp plus all `##`
  headings with line numbers in `b-report-validation-audit.md`; pass every
  required and target-triggered report-template section from report text alone
  with content notes; then separately verify implementation claim by claim as
  Gate 2. If any Gate 1 row is missing, renamed, merged, broad, shallow, stale,
  contradicted, implementation-log-only, or scattered elsewhere, stop. Useful
  edits, score movement, generated output, archive movement, prior signoff, and
  `execute_report` success cannot repair the failure.
- Challenged-report fail-closed rule: if a user names a report and questions
  why it was validated, the report status is `not validated yet` unless a
  current hash/timestamp-matching Gate 1 audit with heading lines and content
  notes already exists. If the named report is already executed and lacks that
  proof or fails any required section, immediately use documented validator
  `needs-revalidation` or invalidation lifecycle before counting, defending,
  clearing, callbacking, or re-executing it.
- Current personal correction: I have been incorrectly validating some B-agent
  reports by outcome or prior lifecycle movement. Effective immediately,
  outcome is irrelevant to Gate 1. If the exact current artifact lacks a
  current matching report-text audit, it is `NOT_VALIDATED`, even if by-* docs
  improved, validators passed, generated files changed, or the report is
  already archived.
- No-audit, no-action override: before callback, revalidation clearance,
  `execute_report`, count/defense, or any answer that a report is valid, open
  the exact current or archived report artifact, record SHA256 or last-write
  timestamp, list every `##` heading with line numbers, compare literal
  template-required and target-triggered sections, and write pass/fail/content
  notes in `b-report-validation-audit.md`. If this cannot be done or any row
  fails, stop that report's lifecycle and use same-report repair or documented
  validator revalidation/invalidation. Do not use `execute_report` as a probe
  or as proof of report quality.
- Active incident override: any B-agent report I previously validated,
  callbacked, executed, counted, or defended is immediately suspect and
  non-counting if the exact current artifact is missing any required/triggered
  section, has shallow required-section content, has stale
  lifecycle/current-state text, or lacks a current hash/timestamp-matching
  content audit in `b-report-validation-audit.md`. If the report is already
  executed, the next action is validator lifecycle repair
  (`executed-mark-needs-revalidation` or `invalidate_execute`), not explanation,
  defense, continued callback, or another `execute_report`.
- Current supervisor process-defect correction: do not validate B reports by
  useful by-* edits, scoped validator success, generated-output movement, score
  movement, archive movement, or `execute_report` success. Those are not Gate 1.
  Gate 1 is the exact report artifact text passing the literal template matrix
  before callback/clearance/execution.
- Current literal-template override: required final-report headings are literal.
  `Finalized Report / Current Recommendation` and `Final Recommendation` are
  separate gates; one cannot satisfy the other. Broad, renamed, merged,
  scattered, stale, shallow, or implementation-log substitutes fail Gate 1 even
  if the implementation is useful. The only valid next action is same-report
  repair, or validator revalidation/invalidation lifecycle for already executed
  reports.
- Current first-action rule: when a B report is named, challenged, ready for
  callback, ready for revalidation clearance, or ready for `execute_report`,
  first check for a current exact-artifact Gate 1 audit matching the report path
  and SHA256/last-write timestamp. If that proof is absent, stale, heading-only,
  or path/hash mismatched, the report is `not validated yet`. If already
  executed, mark it `needs-revalidation` or invalidate it through documented
  validator lifecycle before defending, counting, clearing, callbacking, or
  re-executing it.
- Current operational firebreak: before any callback, revalidation clearance,
  `execute_report`, or statement that a report is valid/countable, I must be
  able to cite a current exact-artifact Gate 1 audit in
  `b-report-validation-audit.md` for the same path and file revision. The audit
  must contain the current hash or last-write timestamp, every `##` heading
  with line numbers, and content-note pass/fail rows for all required and
  triggered sections. If I cannot cite that audit, the report is
  `NOT_VALIDATED` and the only valid next action is audit/repair/revalidation.
- Current execute-report firebreak: `execute_report` never validates report
  quality. It is forbidden until the exact artifact has `GATE1_PASSED` and the
  implementation has `GATE2_PASSED` claim-by-claim verification. If I run it
  without those states, that is my supervisor validation defect and must be
  repaired through same-report repair or documented revalidation/invalidation.
- Latest self-correction: do not validate B-agent reports by outcome. If I
  accepted, callbacked, executed, or defended a report because the by-* edits
  looked useful, scores moved, generated output refreshed, or `execute_report`
  accepted it, that was invalid supervisor process unless a pre-action
  exact-artifact Gate 1 audit already existed for that same report revision.
- Current-state/lifecycle hard failure: exact headings are not enough. If a
  current or archived report still describes active-repair state, report-only
  state, pre-execution status, `needs-revalidation`, old `Agent-B###/research`
  paths, pending supervisor validation, or prior lifecycle events as current
  truth inside required sections, Gate 1 fails. Historical repair notes may
  remain only when clearly labeled historical and not used as the current
  artifact state.
- Validation-incident first move: when a user challenges my report validation,
  I must audit the exact report artifact and, if it fails or lacks a current
  content audit, immediately route executed copies through validator
  `executed-mark-needs-revalidation` or `invalidate_execute` before I continue
  defending, clearing, callbacking, counting, or re-executing that report.
- Default state: every B-agent report is `NOT_VALIDATED` until the supervisor has a current, exact-artifact Gate 1 audit in `tools/leaser/Agents/b-report-validation-audit.md`.
- Required proof: the audit must match the exact report path and current SHA256 or last-write timestamp, list every `##` heading with line numbers, and pass every required or target-triggered section with report-body content notes.
- No substitutes: useful by-* edits, score movement, scoped validator success, generated output, archive location, previous callback/execution, agent claims, and `execute_report` success never validate the report.
- Missing-section outcome: if any required section is missing, renamed, merged into a broad section, shallow, stale, contradicted, implementation-log-only, or only scattered elsewhere, the report fails Gate 1. Return the same report for repair, or use validator revalidation/invalidation lifecycle if it is already executed.
- Challenged-report outcome: when the user names a report and challenges its validation, the report is `SUSPECT_NOT_VALIDATED` immediately. If a current hash/timestamp-matching content audit cannot be cited before answering, mark or route the executed record as `needs-revalidation` or invalidate it through documented validator lifecycle before counting, defending, clearing, callbacking, or re-executing it.
- Supervisor command boundary: `execute_report` is only a final archive/registry action after Gate 1 and Gate 2 have already passed. Never run it as a probe, dry run, shortcut, or proof that a report is acceptable.

## Active Pool Caps

- Current user correction (2026-07-28): maintain exactly 10 active ChatGPT 5.6
  xHigh B-agent workstreams, limited to `Agent-B001` through `Agent-B010`.
  This supersedes every older four-agent, GPT 5.5, Medium, or broader-pool
  instruction in this file. Keep all ten loaded and working whenever eligible
  queue or unfinished B-report lifecycle work exists. Refilling or resuming an
  idle, completed, stopped, or errored allowed slot is the supervisor's
  immediate priority before lower-priority work.
- A-agent pool: `Agent-A001` through `Agent-A005` active; `Agent-A006` through `Agent-A010` retired until user re-enables.
- Immediate B-agent floor: maintain 10 active ChatGPT 5.6 xHigh B-agent workstreams at all times while eligible B work or unfinished B-report lifecycle work exists during the current run. Before doing lower-priority supervisor work, check whether the active B pool is below 10 and refill an allowed idle slot first, without duplicating active/leased targets or abandoning unfinished reports.
- B-agent pool: only `Agent-B001` through `Agent-B010` are allowed for the current run. Do not rotate to, assign, callback, or keep active `Agent-B011` through `Agent-B015` unless a newer explicit user instruction re-enables them. Treat any eligible idle B001-B010 slot below 10 as the next supervisor priority before lower-priority review, queue grooming, or unrelated documentation work. Only operate below 10 when there is genuinely no eligible current-queue target or unfinished B-agent lifecycle work for B001-B010, or when a hard MCP/process failure requires pausing MCP-dependent work.
- Current user override: the standing requirement is 10 active ChatGPT 5.6 xHigh B-agent workstreams, specifically `Agent-B001` through `Agent-B010`. A B agent that has returned `READY_FOR_SUPERVISOR_EXECUTE`, `READY_FOR_SUPERVISOR_GATE1_REVIEW`, or another waiting-for-supervisor state does not count as an active working slot until the supervisor finishes the required Gate 1/Gate 2/lifecycle action and either sends it back to continue or refills that same allowed slot. Do not let finished-report review sit idle, but also do not treat waiting agents as satisfying the 10-active-worker floor.
- B-agent runtime/spec: current user override requires every newly launched or newly assigned active B-agent workstream to use model `gpt-5.6-sol` with `xhigh` reasoning. Existing report headers retain their actual historical `AUTHOR-AGENT-SPECS`; do not rewrite provenance solely because the continuation runtime changed. New reports use `** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **`.
- Temporary pool state: the current required active B-agent count is 10 xHigh workstreams, limited to B001-B010. Preserve each existing report's original `AUTHOR-AGENT-SPECS` and assignment requirements. Do not start, resume, callback, or execute work through B011-B015 while this override is active. New report-only starts must stay at or below ten and must use only B001-B010 unless a newer explicit user instruction changes the cap or allowed agent list.
- Wait cadence: 3 minutes during active pool-management loops unless reports/callbacks are waiting and a shorter check is needed.

## Active Status Reporting

- The status workflow in `tools/leaser/status/README.md` is mandatory for every
  active A/B/C agent. Before assignment or continuation, the supervisor must
  register the agent and make it online; intentionally retired or unloaded
  agents must be offline.
- Agents report `working` when useful work starts/resumes and every 15 minutes
  during uninterrupted work. A fresh `working` report means no help is needed.
  Agents report `complete` before returning a completed checkpoint and report
  actionable supervisor-management states immediately.
- At the start of every 3-minute supervision cycle and immediately after its
  wait, run `python .\tools\leaser\status\status.py -status`. Triage urgent and
  action states first. Do not individually query a fresh `working` agent.
- Check actual worker state for an online agent with no report within 2 minutes
  of assignment or any latest update older than 15 minutes. Actionable states
  normally receive earlier intervention but are not exempt. Review
  `-history AGENTID` when useful, then send one focused update request or
  continue/restart the same worker and folder under the normal policy.
- Status never substitutes for runtime liveness, artifact inspection, Gate 1,
  Gate 2, validator execution, or any other required supervisor verification.

## Active Target Queue

- Current user queue correction (2026-08-06): future new B-agent report-only targets must come from `auto-generated/-ag-research-tracker.md` -> `## by-file`, not `## by-memory`. Scan `### Not-Covered Files - Reconstructable` first, then `### Not-Covered Files - Not Reconstructable`. The latter contains both blank and explicitly non-true reconstructable values; blank by-file metadata is research scope and must not make the supervisor skip the row. Existing active by-memory assignments finish under their current goals, but every next new-target refill uses the by-file queue unless a newer explicit user instruction overrides it.
- Immediate priority before new queue assignments: inventory every root-level `tools/leaser/Agents/Agent-B001` through `Agent-B010` `research/*.md` report that is not already executed, validate/reject/implement/verify it under the normal B-report lifecycle, and execute accepted reports through the validator. Do not assign unrelated new B-agent reports until this allowed-agent backlog is cleared unless an idle B001-B010 slot has no unfinished lifecycle work ready and assigning the next current-queue xHigh report is needed to maintain the 10-active-B-agent requirement.
- Before each assignment batch, read or refresh the research tracker as needed and verify generated freshness before relying on it. Generated refresh can be deferred; use validator `command_id` / timestamp, generated file headers, `python .\tools\validator.py --queue-status`, or `--wait-generated` when freshness matters.
- Heavily prioritize the next rows in the primary queue. Let already-running agents finish before retargeting them, skip duplicate active/leased/already-covered/already-executed targets, and prefer the next unassigned uncovered by-file row. Do not fall back to by-memory merely because the by-file reconstructable bucket is empty; continue into the by-file not-reconstructable bucket and require the report to resolve blank/false metadata.
- Use `project-level/-auto-completion-stats.md` only as secondary score/context data, not as the primary assignment queue.
- Occasionally assign a few B agents to by-memory or another research-tracker category, or urgent source-quality, ownership, split/range, missing coverage, or structural problems, only when a current explicit override selects them or they are clearly higher priority than the next current by-file row.
- Secondary queue context only: the tracker `## by-memory` section, `auto-generated/-ag-memory-coverage.md`, other `auto-generated/-ag-*-coverage.md`, `project-level/-auto-completion-stats.md`, and manual `by-*/-coverage-report.md` files.
- Fallback/idle B work: use the next suitable uncovered by-file target from the primary queue before any by-memory or broad fallback scan.
- Whole-file assignment requirement: every by-file target is a complete compilation-unit research pass. The assignment prompt must require an exhaustive inventory and deep research of every reasonably discoverable file-owned function/method/helper/thunk/compiler-generated or compiler-covered code item; every global/static/constant/string/table/data item; every type/layout/enum/vtable/RTTI/resource/import; exact ranges, children, gaps/padding, xrefs/callers/callees, initialization/destruction and source order; and every affected by-memory/by-class/by-global/by-item/by-type/by-resource/support page. A sampled subset, one-function report, or by-file-page-only refresh is incomplete.
- Whole-file Gate 1 requirement: by-file reports must contain substantive complete-file content under `Function / Child Inventory`, `Direct Xref / Caller Inventory`, `Ranked Ownership Analysis`, `Source Placement`, `Range / Split / Padding / Reclassification Analysis`, `Recommended Target Doc Changes`, and `Recommended Support Doc Changes`, plus per-item ledger/checklist rows and separate CPP/H or no-code dispositions. Reject a by-file report if any known or reasonably discoverable file-owned item lacks evidence, a disposition, an implementation destination, or an evidence-backed exclusion. Related UIDs count as report coverage only when declared and independently validated under the normal additional-target rules.
- Whole-file completion requirement: by-file work is not complete at documentation coverage. The report and callback must find and resolve every missing function/code fragment, stub/TODO/placeholder/empty-emitter body, behaviorally incomplete path, missing data initializer/table content, missing declaration/type/include/forward declaration, broken or duplicated child/emitter route, source-order defect, and required-but-missing/stale sibling `.h`. Repairs must be made only through owning formal CPP/H channels. Gate 2 must run a coherent generated refresh and physically compare the validator-owned generated `.cpp` and required `.h` to the full inventory. A missing `.h` blocks completion when the module needs one; when no header is appropriate, require a file-specific evidence-backed no-header disposition rather than an invented empty header.
- Maintain `tools/leaser/Agents/no_owner_b-agent-tracker.md` when refreshed reports produce reconstructable 85/85 no-owner candidates and supervisor-owned tracker maintenance is in scope.

## Temporary Assignment Rules

- Assignment prompts must name one target or one small explicit batch, define whether the expected return is report-only, implementation callback, or checkpoint, and state exact allowed support scope.
- Score delta tracking remains active: agents report score before/after when they change scores.
- Temporary MCP stability throttle: when the IDA MCP endpoint has recently lost its session, refused connections, or shown saturation under multi-agent load, keep assigned B agents loaded but resume MCP-heavy research in small waves instead of letting all agents issue MCP calls at once. Agents not in the active MCP wave may do local doc/archive prep only and must not finalize fallback-only reports. Resume full parallel MCP use only after the endpoint stays stable through bounded probes and a completed wave.

## Backlog/Overflow Rules

- Current validation-defect override: when the user challenges a named
  B-agent report, says it is missing required sections, or I discover that I
  accepted/callbacked/executed a report without a complete current Gate 1 audit,
  the report is `SUSPECT_NOT_VALIDATED` until proven otherwise. The next action
  must be exact-artifact audit in `b-report-validation-audit.md`, not
  explanation or continued lifecycle work. If the report is already executed and
  the audit is absent, stale, heading-only, content-light, or failing, use
  documented validator lifecycle to mark it `needs-revalidation` or invalidate
  it before counting, defending, clearing, callbacking, or re-executing it.
- Current audit-format override: Gate 1 audit entries must include state,
  intended action, exact report path, agent, target UID, current hash or
  last-write time, full `##` heading list with line numbers, and a required /
  target-triggered section matrix. Every `PASS` row needs the exact heading line
  and a report-body content note; every `FAIL` row needs the exact defect.
  Missing, renamed, merged, broad, shallow, stale-current-state, contradicted,
  implementation-log-only, or scattered substitute sections fail. Useful by-*
  edits, validator success, generated output, score movement, archive location,
  prior callback/execution, and memory are not evidence of Gate 1.
- Current mandatory supervisor self-lock: before I issue a B-agent
  implementation callback, clear revalidation, run `execute_report`, or answer
  that a report is valid/countable, I must first complete this exact pre-action
  check for the report artifact on disk:
  1. open the exact current or archived report path;
  2. record SHA256 or last-write timestamp;
  3. list every `##` heading with line numbers;
  4. compare the report to the fixed Gate 1 required-section matrix;
  5. write pass/fail rows with target-specific content notes in
     `b-report-validation-audit.md`;
  6. fail the report if any required/triggered section is missing, renamed,
     merged, broad, shallow, contradicted, stale-current-state,
     implementation-log-only, or only scattered elsewhere.
  This check is not optional when agents are waiting, the implementation looks
  correct, validators passed, scores moved, or the report was already archived.
  If the report is already executed and this current proof is missing or
  failing, mark it `needs-revalidation` or invalidate it through documented
  validator lifecycle before counting or defending it.
- Current active validation correction: B-report lifecycle states must be
  explicit and ordered: `NOT_AUDITED`, `GATE1_FAILED`, `GATE1_PASSED`,
  `CALLBACK_SENT`, `GATE2_FAILED`, `GATE2_PASSED`, `EXECUTED`. A report cannot
  receive a callback without a current exact-artifact `GATE1_PASSED` audit in
  `b-report-validation-audit.md`, and it cannot be executed without a current
  claim-by-claim `GATE2_PASSED` verification. Heading-only, stale,
  path/hash-mismatched, post-hoc-only, implementation-dependent, or
  content-light audits fail. If a user challenges a report or a defect is found,
  stop that report's normal lifecycle and repair/revalidate/invalidate before
  counting, defending, clearing, callbacking, or executing it.
- Current report lifecycle state-machine override: every B report is
  `NOT_AUDITED` until the supervisor audits the exact current artifact and
  writes either `GATE1_FAILED` or `GATE1_PASSED` in
  `b-report-validation-audit.md`. `execute_report` is forbidden until that
  exact artifact also has supervisor verification recorded as `GATE2_PASSED`.
  Partial passes, heading-only audits, implementation-dependent passes,
  post-hoc-only audits, stale path/hash evidence, or useful by-* edits do not
  create an executable report. Repair/revalidate instead.
- Current challenged-report override: when a user challenges B-report
  validation or says a report is missing required sections, the supervisor's
  first action is exact-artifact audit, not explanation. Open the current or
  archived report, record SHA256 or last-write timestamp, list every `##`
  heading with line numbers, compare it to the fixed Gate 1 matrix, and write
  content notes to `b-report-validation-audit.md`. If no current matching
  content audit proves the report passes, the report is `not validated yet`;
  executed reports must be marked `needs-revalidation` or invalidated through
  validator lifecycle before counting, defending, clearing, callbacking, or
  re-executing. Useful implementation and `execute_report` success are not
  defenses.
- Current supervisor validation lock: every B-agent report is `not validated
  yet` until the exact current report artifact passes Gate 1 from its own text.
  The supervisor must have a matching `b-report-validation-audit.md` entry with
  current hash/timestamp, exact path, complete heading list, and content notes
  for every required and triggered section. Implementation quality, score
  movement, generated output, scoped validators, archive location, previous
  callback/execution, agent claims, or memory are not report validation. If that
  proof is missing or stale for an executed report, immediately use documented
  validator `needs-revalidation` or invalidation lifecycle before counting,
  clearing, defending, or re-executing it.
- Current supervisor self-correction protocol: if I discover that I accepted,
  callbacked, cleared, executed, or defended a B report without a current
  exact-artifact Gate 1 pass, that prior signoff is invalid process. Stop normal
  lifecycle work for that report, audit the exact current or archived artifact,
  record the failed/missing audit in `b-report-validation-audit.md`, and if it
  is already executed use documented validator lifecycle to mark it
  `needs-revalidation` or invalidate it for repair. Do not defend the report or
  count it because by-* edits were useful; require same-report repair and fresh
  Gate 1/Gate 2 before any later callback, clearance, or `execute_report`.
- Current personal red-line override: B-report validation is all-or-fail. If a
  required or target-triggered section is missing, renamed, merged, broad,
  shallow, stale, contradicted, implementation-log-only, or only scattered in
  another section, the report is not validated. Do not callback, clear
  revalidation, execute, defend, or count it because implementation was useful,
  validators passed, generated output moved, the score improved, or the report
  is already archived. Repair the same report text or use documented validator
  revalidation/invalidation lifecycle before any further lifecycle action.
- Current validation-incident first action: if the user names a B-agent report and asks why it was validated, says it is missing required sections, or otherwise challenges report quality, stop normal lifecycle handling for that report immediately. Before explanation, callback, revalidation clearance, or `execute_report`, open the exact current or archived artifact, record current SHA256 or last-write timestamp, list every `##` heading with line numbers, compare it to the fixed Gate 1 matrix, and write the pass/fail result with content notes to `b-report-validation-audit.md`. If there is no current hash/timestamp-matching content audit or any required section fails, mark the executed artifact `needs-revalidation` or invalidate it through validator lifecycle and send it back for report-text repair before counting it again.
- Current no-excuse validation rule: implementation quality, useful by-* edits, score movement, scoped validator success, generated output freshness, archive location, prior callback, prior execution, or `execute_report` success are never evidence that a report passed Gate 1. A challenged or suspect report must pass from the report text itself under exact headings with target-specific content notes, or it is not validated.
- Maintain the active B-agent cap, but do not starve finished-report review. During the current backlog-clearance phase, first use available B001-B010 capacity to continue, fix, implement, or verify existing unexecuted reports. Only fill an idle B001-B010 slot with a new current-queue xHigh assignment when no unfinished lifecycle work is ready for that slot and doing so is needed to maintain 10 active B-agent workstreams.
- Current mandatory pre-action checklist: before callback, revalidation clearance, or `execute_report`, open the exact report artifact, record SHA256 or last-write timestamp, list every `##` heading with line numbers in `b-report-validation-audit.md`, compare exact template-required headings and target-triggered sections, and record content-sufficiency notes for each pass. Missing, renamed, merged, broad, shallow, contradicted, scattered, heading-only, or implementation-log-only sections fail immediately and block the action.
- Current fixed Gate 1 matrix: final B reports must pass provenance headers; `Finalized Report / Current Recommendation`; `Supporting Research`; `Target`; `Current Target State`; `Heuristic / Inference Reanalysis And Validation`; `Evidence Standards Used`; `Evidence Checked`; `Claim And Incorporation Ledger`; `Positive Evidence Summary`; `Negative Evidence Summary`; `Ranked Ownership Analysis` when ownership is in scope or exact applicable `Source Placement`/source-disposition content when ownership is not the decision point; `First-Draft C++ Recommendation`; `Final Recommendation`; `Recommended Target Doc Changes`; `Recommended Support Doc Changes` when support docs are touched, triggered, or deliberately unchanged; `Score And Metadata Recommendation`; `Open Questions With Attempted Resolution`; `Validator Results`; `Changed Files`; and `Implementation Tracking Checklist`. Each pass must cite the exact heading line and target-specific content note. Missing/renamed/merged/broad/scattered equivalents are automatic failures. `Finalized Report / Current Recommendation` and `Final Recommendation` are not interchangeable.
- Current hard supervisor self-check: before I say a B report is valid, issue an implementation callback, clear revalidation, or run `execute_report`, I must personally audit the exact report artifact from disk and write a current Gate 1 entry to `b-report-validation-audit.md`. That entry must include the report path, agent, target UID, intended action, current SHA256 or last-write timestamp, the complete `##` heading list with line numbers, and a pass/fail matrix for every required core and target-triggered section from the B-agent template/workflow. If that audit is absent, stale, missing heading-line evidence, or cannot pass from the report text alone, the report is not validated.
- Current validation chronology override: callback, revalidation clearance, and
  `execute_report` require a pre-action Gate 1 audit for the exact report path
  and exact file revision. A post-hoc audit can diagnose an incident or repair
  state, but it cannot be used to justify an earlier callback or execution. If
  the only audit is post-hoc, stale, heading-only, missing content notes,
  path-mismatched, or created after the action it is being used to defend, the
  report is `not validated yet`; already executed reports must be marked
  `needs-revalidation` or invalidated/repaired through validator lifecycle
  before counting.
- Current complete-section override: Gate 1 is all-or-fail. Passing most rows is
  still failure if any required or target-triggered section is missing, renamed,
  merged, broad, shallow, stale, contradicted, implementation-log-only, or only
  scattered elsewhere. Every pass must cite the exact heading line and
  report-body content note.
- Current hard rejection rule: missing, renamed, merged, broad, shallow, contradicted, or scattered substitutes for required report sections fail Gate 1 even if the B agent made useful by-* edits, scoped validators passed, generated output refreshed, scores improved, or the report was already archived. The correct action is to return the same report to the same B agent for repair, or use validator revalidation/invalidation lifecycle if the report was already executed.
- Current suspect-report stop rule: if a B report is challenged by the user, lacks a current exact-artifact Gate 1 audit, has stale/path-mismatched audit evidence, carries `REPORT-VALIDATION-STATUS: needs-revalidation`, or is missing/renaming/merging/shallowing required sections, stop that report's normal lifecycle immediately. The only allowed next actions are artifact audit, audit-ledger entry, return to the same B agent for repair, or documented validator revalidation/invalidation lifecycle. Do not callback, clear status, run `execute_report`, count the report, or justify the prior validation from useful implementation or validator/archive success.
- Current lifecycle guard: never use `execute_report`, dry-run/probing variants, archive location, validator registry acceptance, or generated tracker movement to decide report quality. `execute_report` is allowed only after Gate 1 artifact audit and Gate 2 claim-by-claim implementation verification have both passed.
- During backlog and executed-report review, apply the two-gate supervisor signoff strictly: Gate 1 required-section/report-quality audit before callback, Gate 2 claim-by-claim implementation verification before `execute_report`. If a current or already-executed report is missing required sections, uses renamed/merged/broad headings instead of exact core headings, or has only scattered/shallow substitutes, return/invalidate it for repair instead of accepting it based on useful edits or validator movement.
- Every callback, revalidation clearance, or `execute_report` must have a current
  Gate 1 audit row in `b-report-validation-audit.md` for the exact report/action.
  Missing, stale, implementation-dependent, or heading/line-evidence-free audit
  rows block supervisor action.
- Current validation-incident override: when the user challenges a report
  validation or identifies missing required sections, fail closed. Audit the
  exact current or archived report artifact from disk, record hash/timestamp and
  heading-line evidence, and treat the report as not validated unless the report
  text itself passes Gate 1. Useful by-* edits, generated output, scoped
  validator success, and prior execution do not count. Route failed executed
  reports through validator `needs-revalidation` or invalidation/repair before
  counting or executing them again.
- Current validation-incident action override: if the user asks why a report was
  validated or points to missing sections, the supervisor's next action must be
  artifact handling, not explanation or continued normal execution. Open the
  exact current/archived report, check for a current hash/timestamp-matching
  Gate 1 audit with content notes, and either cite that audit or immediately
  mark/invalidate the report for revalidation. Until that is done, the report's
  status is `not validated yet`.
- Current validation-incident repair override: when the challenged report fails
  the fixed Gate 1 matrix, mark the executed artifact `needs-revalidation` or
  invalidate it through documented validator lifecycle before normal work for
  that report resumes. The same B agent or assigned replacement should repair
  the existing report text by adding the missing sections/content; do not
  replace the defect with a defense based on useful by-* edits, validators,
  generated output, score movement, or previous execution.
- Current validation-claim override: do not say a B report is validated,
  accepted, or executable unless `b-report-validation-audit.md` has the exact
  report path, target UID, current hash or last-write timestamp, full `##`
  heading list with line numbers, required-section pass/fail matrix, and
  content-sufficiency notes for every pass. Missing audit fields block callback,
  revalidation clearance, and `execute_report`.
- Current stale-audit override: for a challenged report, a previous Gate 1 audit
  is valid only if its hash or last-write timestamp matches the exact current or
  archived report artifact and it contains content-sufficiency notes, not just a
  heading list. Missing, stale, heading-only, or implementation-dependent audits
  are failures. Mark/rework the report through validator lifecycle before any
  callback clearance or later `execute_report`.
- Current artifact-path override: a Gate 1 audit is scoped to the exact report
  path and file revision. If a report moved from `Agent-B###/research/` into
  `executed-b-agent-research/B###/`, or validator added/changed
  `REPORT-VALIDATION-STATUS` or `VALIDATOR-REPORT-HISTORY`, the old audit is
  stale for the current artifact until the supervisor re-audits the archived
  path and matching hash/timestamp.
- Current revalidation-status override: any report with
  `REPORT-VALIDATION-STATUS: needs-revalidation` is not validated, accepted, or
  countable. Do not clear it in prose, do not manually edit it, and do not rely
  on by-* implementation quality. The supervisor must use documented validator
  lifecycle after a fresh artifact-level Gate 1/Gate 2 pass.
- Current no-heading-only override: a Gate 1 audit that only lists headings is
  insufficient. Every `pass` must be based on target-specific content under that
  heading and should record a short content-sufficiency note or representative
  line range. Reports that mostly read as implementation completion logs,
  changed-file summaries, or accepted-evidence lists fail unless they still
  preserve complete research-quality analysis. User-flagged executed reports
  should be marked `needs-revalidation` immediately unless a current
  content-audited Gate 1 entry already proves compliance.
- Current supervisor self-correction override: if a report was accepted,
  callbacked, cleared, or executed under a bad Gate 1 audit, pause that report's
  lifecycle and repair the process defect first. Mark already-executed records
  `needs-revalidation` or invalidate them through validator lifecycle, require
  exact-heading report repair, then rerun Gate 1 and Gate 2 before any new
  execution. Do not rely on useful implementation, score movement, generated
  output, or validator archive success as evidence that the report was valid.
- Current exact-heading override: reject reports with broad/merged substitutes
  for required core sections. In particular, `Recommended Target/Support Doc
  Changes` does not satisfy separate target and support recommendation gates
  when both are triggered. Required content must appear under the exact template
  heading or under that exact heading with a concrete target-specific
  not-applicable disposition.
- One or two overflow supervisors may be used while B-report review, implementation verification, executed-report lifecycle work, or callback preparation is backlogged, scaled to the actual queue. Give them disjoint exact-report assignments and the same active goal/rules/skill context; they may not spawn subagents, duplicate reviews, close/unload B agents, or make final `execute_report` decisions. Keep completed overflow supervisors loaded and idle when future backlog is likely unless a current explicit override requires closing them.
- Completed B-agent subagents stay loaded and idle for rotation reuse unless stale, broken, duplicated, identity-mismatched, cap-conflicting, or explicitly closed by the user.

## Retired Overrides Log

- The previous primary queue `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable` is retired for future new-target selection as of 2026-08-06. By-memory is now secondary unless a newer explicit user instruction selects it. Existing active by-memory goals are not canceled and should finish normally.
- Legacy primary queue based on `Total_Reconstructable_NoOwner / Total_Reconstructable_NonEmits` in `auto-generated/-ag-memory-coverage.md` is retired as the default B-agent queue. It remains secondary context only.
- Legacy instruction to complete all files in `Supervisor_notes.md` and then rebuild a list from `-ag-memory-coverage.md` is retired unless a current user instruction restores it.
- Legacy broad "fix any associated item as deeply as needed" wording is retired; assignments now require explicit support scope and blocker handling.
