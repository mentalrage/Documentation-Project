# NTK Workflow Optimization Change Plan

Date: 2026-06-28

This document is an implementation-grade edit plan for reducing needless agent token use and task latency in the NTK supervisor/B-agent workflow. It is not a general findings report. Each item below names the exact file section to change, the action to take, and the quality guard that must remain.

## Non-Negotiable Quality Guards

Do not weaken these rules while optimizing:

- B-agent reports still require current evidence and IDA MCP when MCP is required.
- Score/source-quality blockers still require same-pass investigation unless explicitly excluded.
- "Needs more investigation" is still not an acceptable final answer for an in-scope blocker.
- Accepted B-report facts must still be incorporated, already present at same-or-greater detail, or explicitly rejected with a reason.
- Generated reports and `auto-generated/NexusTK/**` remain validator-owned.
- `tools/validator.ini`, queue JSON, lock files, and generated reports must not be hand-edited.
- Validator command metadata and generated-header freshness checks remain required when generated output matters.
- Third-party static source imports still use `third_party_embeds/...` validator import directives.

## Rule Preservation And Same-Task Audit

The optimization is allowed to change instruction placement, duplication, read timing, and routing clarity. It must not change the task the agents perform, the evidence threshold, the artifacts they produce, the supervisor acceptance standard, or validator ownership boundaries.

Before deleting any duplicated rule from an existing file, complete this gate:

1. The canonical destination named below exists.
2. The destination contains equivalent or stricter wording.
3. The source location either keeps a short pointer to the destination or is no longer role-relevant.
4. `rg` verification proves the rule still exists in the canonical destination and is not lost.
5. A spot read of one current B-agent `goal.md`, the B-agent workflow reference, and the supervisor Rule 26 reference confirms that the same report -> implementation callback -> verification -> execute-report task is still required.

Do not treat a rule as safe to remove just because it is "covered generally" elsewhere. If the old wording controlled a concrete behavior, the new location must preserve that behavior with concrete language.

| Existing rule that must survive | Same-task requirement after optimization | Canonical destination after refactor | Verification |
| --- | --- | --- | --- |
| B-agent report-only work is followed by supervisor review, same-agent implementation callback, supervisor verification, then `execute_report`. | B reports are not executed merely because the supervisor agrees; the same B agent still implements accepted changes and the supervisor still verifies before executing. | `SKILL.md` -> `Standard Flow`; `b-agent-research-and-implementation-workflow.md` -> `Standard B-Agent Work Lifecycle`; `supervisor-rule26-review-and-incorporation-standard.md` -> `Standard B-Agent Work Lifecycle`. | Search for `execute_report`, `same B agent`, and `Implementation Tracking Checklist` in all three destinations. |
| Rule 26 non-loss incorporation. | Every accepted report fact is still incorporated, already present at same-or-greater detail, or explicitly rejected/stale/duplicate/not applicable with a concrete reason. | `supervisor-rule26-review-and-incorporation-standard.md` -> `How To Merge Report Data Into By-* Docs`; report/callback references to `Claim And Incorporation Ledger`. | Search for `Claim And Incorporation Ledger`, `same-or-greater`, and `explicitly rejected`. |
| B reports require current evidence and IDA MCP under normal standards. | MCP remains mandatory for normal B-agent acceptance; fallback-only reports remain invalid unless a current target-specific override permits them. | `SKILL.md` MCP paragraph; `mcp-incident-playbook.md`; B-agent workflow `Tools`; supervisor Rule 26 `Tool And Validator Review Standard`. | Search for `MCP is mandatory`, `fallback-only`, `redo or update the MCP-backed evidence pass`, and `must not start, stop, restart, or kill`. |
| Score/source-quality blockers require same-pass work. | Agents still investigate named blockers now; "needs more investigation" and similar phrases still reject final in-scope reports unless a rare audited no-improvement proof is met. | `score-blocker-audit-standard.md`; compact pointers in `SKILL.md`, B-agent workflow, and supervisor Rule 26 standard. | Search for `needs more investigation`, `Named Blocker Rule`, `Allowed No-Improvement Exception`, and `same-agent instruction`. |
| First-draft C++ quality and insertion rules. | Eligible emitting targets still require first-draft C++ or target-specific no-code proof; any C++ written by an agent still belongs in the formal `RECONSTRUCTION_CPP CODE` header/block, not a body-only sample. | `by-structure.md` C++/emitter metadata paragraphs; B-agent workflow `Research Output Requirements`; supervisor Rule 26 `Score, Ownership, Emitter, And C++ Rules`. | Search for `RECONSTRUCTION_CPP CODE`, `body-only`, `no-code proof`, and `(COMPLETION + CONFIDENCE) / 2 > 85`. |
| Third-party source import directive. | Vetted static third-party source still uses quoted `third_party_embeds/...` import paths ending in `.c`, `.cpp`, or `.h`, with the multiline C++ block blank and generated output validated current. | `tools/validator_README.txt` as command syntax authority; `by-structure.md`; short pointers in skill/reference docs. | Search for `third_party_embeds`, `<import-from-start>`, `.c`, `.cpp`, `.h`, and `--wait-generated`. |
| Generated reports and `auto-generated/NexusTK/**` ownership. | Agents still do not manually edit validator-owned generated reports or generated C++; they update source by-* metadata and use validator commands. | `SKILL.md` -> `Coverage And Generated Files`; B-agent workflow coverage/generated rules; supervisor Rule 26 coverage/generated rules; `validator_README.txt`. | Search for `auto-generated/NexusTK`, `generated reports`, `do not manually edit`, and `--wait-generated`. |
| Validator state ownership. | Agents still do not repair missing files, stale UID mappings, queues, locks, or executed-report state by editing `tools/validator.ini` or JSON/lock files. | `tools/validator_README.txt`; `by-structure.md` validator sections; compact warnings in `SKILL.md`, B-agent workflow, and supervisor Rule 26 standard. | Search for `validator.ini`, `queue JSON`, `lock files`, `--remove-missing`, `execute-rescan-reports`, `execute-confirm-change`, `executed-reassign`, and `invalidate_execute`. |
| Generated freshness metadata. | If generated output matters after a command, agents still compare returned `command_id`/`command_timestamp` with generated file headers or use `--wait-generated`. | `SKILL.md` coverage/validation; `validator_README.txt` command output sections; B-agent workflow generated-file rules. | Search for `command_id`, `command_timestamp`, `validator-command-id`, `validator-refreshed-at`, and `--wait-generated`. |
| Leases are short edit locks only. | B agents still take leases only for immediate edit/validator batches, release them afterward, and report `PAUSED_LEASE_CONFLICT` instead of editing through conflicts or dropping accepted edits. | B-agent workflow `Leasing`; supervisor Rule 26 `Implementation Callback Requirements`; compact callback text in `Supervisor.md`. | Search for `short edit locks`, `not reservations`, and `PAUSED_LEASE_CONFLICT`. |
| Old report usage. | Agents still search old reports by UID/address/name/source-family before finalizing, but only open relevant matches instead of bulk-reading archives. | B-agent workflow `Search Before Reading Old Reports`; report output requirements. | Search for `Search Before Reading Old Reports`, `UID`, `address range`, `old generated name`, and `source-family`. |
| Assignment queue and active target work. | The preferred B report queue remains current generated research tracker by-memory reconstructable not-covered targets unless a current user/supervisor override names a different queue. | `SKILL.md` target-selection paragraph; B-agent workflow `Target Selection`; `Supervisor_active_overrides.md` active queue. | Search for `-ag-research-tracker.md`, `Not-Covered Files - Reconstructable`, and `secondary context`. |
| Supervisor pool/cap behavior. | Routine supervisor pool management remains in `Supervisor.md`/active overrides; B report quality rules move to the skill/reference docs but are still mandatory. | `Supervisor.md`; `Supervisor_active_overrides.md`; `.codex/AGENTS.md` role routing. | Search for `Active Pool Caps`, `Supervisor_active_overrides.md`, and `B-agent report review`. |
| Agent `goal.md` files remain assignment-specific. | Existing/future goal files keep exact agent ID, assigned target, report path, callback details, and explicit overrides; they stop duplicating global policy but do not lose target-specific work. | Existing/future `tools/leaser/Agents/Agent-B###/goal.md`; global rules in skill/reference docs. | Spot check one report-only goal and one callback goal after migration. |
| Current source-quality mission. | Agents still reconstruct behavior accurately and source shape plausibly; optimization must not turn work into shallow coverage raising or assignment-only edits. | `SKILL.md` project context; B-agent workflow `Heuristic Reconstruction And Source-Quality Mandate`; `by-structure.md` evidence/scoring rules. | Search for `exact executable behavior`, `plausible`, `assignment-only`, and `source-quality`. |

### Same-Task Stop Conditions

Stop the refactor and restore/repair the plan if any of these become true:

- A B-agent can finish a normal report without MCP evidence when no explicit target-specific override exists.
- A B-agent can leave an in-scope named blocker for a future pass without rare no-improvement proof or explicit exclusion.
- A B report can be executed before accepted claims are implemented into by-* docs and supervisor-verified.
- The implementation checklist or Claim And Incorporation Ledger disappears from either the report requirements or supervisor verification requirements.
- A generated report, generated C++ file, `tools/validator.ini`, queue JSON, or lock file becomes a normal manual-edit target.
- First-draft/example/sample C++ is allowed outside the formal `RECONSTRUCTION_CPP CODE` block without a no-code proof.
- Third-party static source can be referenced from `third-party/...`, absolute paths, documentation-root paths, unquoted paths, or copied source when a valid `third_party_embeds/...` import is available.
- Lease conflicts allow agents to skip accepted edits silently, edit through another lease, or hold reservation leases.
- Old executed/archived reports are either ignored entirely or bulk-read without relevance gating.
- The preferred B-agent assignment queue is changed from current generated research tracker targets without an explicit active override.

### No-Deletion Verification Commands

Run these checks after the documentation refactor and before deleting old duplicate text:

```powershell
rg -n "execute_report|Implementation Tracking Checklist|Claim And Incorporation Ledger|Rule 26|same-or-greater|needs more investigation|no defensible improvement|MCP is mandatory|fallback-only|validator.ini|third_party_embeds|RECONSTRUCTION_CPP CODE|--wait-generated|validator-command-id|EMITTER_UIDS|CANONICAL_OWNER|PAUSED_LEASE_CONFLICT" .codex/AGENTS.md .codex/skills/ntk-b-agent-workflow source-3/project-documentation/tools/leaser/Agents/Supervisor.md source-3/project-documentation/by-structure.md source-3/project-documentation/tools/validator_README.txt
```

Then check for obsolete broad wording that should be replaced by exact completion criteria:

```powershell
rg -n "only document you need|Take as long as needed|continue working for as long as possible|fix any associated items as deeply as needed" .codex/AGENTS.md .codex/skills/ntk-b-agent-workflow source-3/project-documentation/tools/leaser/Agents/Supervisor.md
rg -n "only document you need|Take as long as needed|continue working for as long as possible|fix any associated items as deeply as needed" source-3/project-documentation/tools/leaser/Agents -g "Agent-B*/goal.md"
```

If the first command loses any required concept, do not delete the old text yet. If the second command still finds broad wording, replace it with the exact role-specific task criteria named in this plan.

## New Canonical Files To Add

Add these files before deleting duplicated rules from existing docs.

| New file | Purpose | Sections to contain |
| --- | --- | --- |
| `.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md` | Single canonical source for score blocker, "no defensible improvement", and no-unchanged-score loophole rules. | `Purpose`, `B-Agent Burden`, `Supervisor Acceptance Test`, `Allowed No-Improvement Exception`, `Reject Phrases`, `Examples Of Incomplete Results`. |
| `.codex/skills/ntk-b-agent-workflow/references/mcp-incident-playbook.md` | Detailed MCP failure investigation. Only read when MCP fails/repeatedly disappears. | `Trigger`, `B-Agent Status Checks`, `Supervisor Checks`, `Logs To Inspect`, `Restart Rules`, `When To Halt MCP-Dependent Work`. |
| `.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md` | Full report template currently embedded in the workflow reference. | Move the large template from `b-agent-research-and-implementation-workflow.md` here. |
| `source-3/project-documentation/tools/leaser/Agents/Supervisor_active_overrides.md` | Live temporary supervisor overrides only. | `Active Pool Caps`, `Active Target Queue`, `Temporary Assignment Rules`, `Backlog/Overflow Rules`, `Retired Overrides Log`. |

### Exact New File: `score-blocker-audit-standard.md`

Create `.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md` with this section structure and content requirements:

```markdown
# Score Blocker Audit Standard

## Purpose

This file is the canonical rule for score/source-quality blockers, unchanged-score recommendations, named blockers, and the rare no-defensible-improvement exception.

## B-Agent Burden

A B-agent report must actively investigate every in-scope score/source-quality blocker it names. A blocker may end in only one of these states:

- resolved with evidence;
- converted into an implementation-ready repair, split, child-page, source-placement, naming/type/layout, owner/emitter, or C++ plan;
- explicitly excluded by the current supervisor assignment;
- documented as a rare no-improvement exception under this file.

## Named Blocker Rule

If a report says a helper, child page, support file, source owner, type/layout issue, route, missing exact by-memory page, open question, or C++ blocker prevents improvement, that named item is now in scope unless the assignment explicitly excluded it.

## Reject Phrases

Reject these as final rationales when the topic is in scope:

- "needs more investigation";
- "needs focused pass";
- "needs child-specific research first";
- "future pass";
- "lacks exact proof";
- "names remain descriptive rather than proven";
- "source route still unresolved";
- "MCP should check later".

## Allowed No-Improvement Exception

Accept "no defensible improvement is currently safe" only when the report proves all of the following:

- every reasonable current evidence route was attempted;
- related target/support docs were checked;
- split/child-page/source-route repair was considered;
- inferred naming/type/layout/source-shape options were considered;
- score movement and C++ disposition were considered;
- each rejected route has exact evidence and reason;
- further current-pass work would be unsafe, impossible, explicitly excluded, or unsupported, not merely broad or time-consuming.

## Supervisor Acceptance Test

Before accepting unchanged metadata, the supervisor must be able to write the exact same-agent instruction that would otherwise be sent back. If the report does not already prove why that instruction is unsafe/impossible/excluded, reject the report and send that instruction.

## Examples Of Incomplete Results

- "No xrefs were found, so no score change" without byte searches, caller/callee checks, data-route checks, support-doc review, or source-shape analysis.
- "Names remain descriptive" without proposing best inferred names or proving no inferred name is safe.
- "A child page is needed first" without creating/recommending exact child ranges or proving split work is unsafe.
```

### Exact New File: `mcp-incident-playbook.md`

Create `.codex/skills/ntk-b-agent-workflow/references/mcp-incident-playbook.md` with this section structure and content requirements:

```markdown
# MCP Incident Playbook

## Trigger

Use this playbook only when IDA MCP is unavailable, repeatedly times out, disappears after a restart, or a report claims MCP evidence was skipped.

## B-Agent Status Checks

B agents may run read-only checks only:

- listener check for `127.0.0.1:13337`;
- process check for IDA/MCP/Python worker presence;
- one lightweight JSON-RPC probe when safe;
- record exact failed call, time, listener/process state, and whether failure looked busy or down.

B agents must not start, stop, restart, or kill MCP/IDA/Python processes.

## Supervisor Checks

The supervisor determines busy versus down before restarting:

- check listener/process state;
- inspect the active session/tool list when reachable;
- retry briefly if listener/process exists and a heavy request may be running;
- restart only when checks show stale/down state.

## Logs To Inspect

- `source-3/project-documentation/tools/idalib-mcp-logs/idalib-mcp-supervisor-events.log`
- active `idalib-mcp-*.err.log`
- active `idalib-mcp-*.out.log`
- recent failed JSON-RPC call shape
- process command lines for launcher, PowerShell monitor, `idalib-mcp.exe`, Python wrapper, and IDA worker

## Restart Rules

Use the project launcher only when restart is required. Confirm a real IDB-backed request works after restart. Do not repeatedly restart a live-but-busy listener.

## Report Handling

Do not accept fallback-only B reports unless a current explicit instruction allows it for that target. After MCP recovers, the same agent must redo or update the MCP-backed evidence pass.

## Halt Condition

If MCP repeatedly fails and the cause cannot be identified or stabilized, halt MCP-dependent B-agent work and report the operational blocker.
```

### Exact New File: `b-agent-report-template.md`

Create `.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md` by moving the full template currently under `b-agent-research-and-implementation-workflow.md` -> `## Final Report Template`.

Add this header before the moved template:

```markdown
# B-Agent Report Template

Use this full template when drafting final B-agent reports. The main workflow reference owns the required-section matrix; this file owns the full expandable template text.
```

No template sections should remain embedded in the main workflow reference after the move except the required-section matrix.

### Exact New File: `Supervisor_active_overrides.md`

Create `source-3/project-documentation/tools/leaser/Agents/Supervisor_active_overrides.md` with this shape:

```markdown
# Supervisor Active Overrides

## Active Pool Caps

- A-agent pool: `Agent-A001` through `Agent-A005` active; `Agent-A006` through `Agent-A010` retired until user re-enables.
- B-agent pool: up to 10 active B agents from `Agent-B001` through `Agent-B015`.
- Wait cadence: 3 minutes during active pool-management loops unless reports/callbacks are waiting and a shorter check is needed.

## Active Target Queue

- Primary B-agent report-only queue: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Secondary queue context only: `auto-generated/-ag-memory-coverage.md`, other `auto-generated/-ag-*-coverage.md`, `project-level/-auto-completion-stats.md`, and legacy `by-memory/-coverage-report.md`.
- Fallback/idle B work: use the next suitable B-preferred source-quality/ownership/split target from the primary queue before broad fallback scans.

## Temporary Assignment Rules

- Assignment prompts must name one target or one small explicit batch, define whether the expected return is report-only, implementation callback, or checkpoint, and state exact allowed support scope.
- Score delta tracking remains active: agents report score before/after when they change scores.

## Backlog/Overflow Rules

- Maintain the active B-agent cap, but do not starve finished-report review. If two or more completed B reports or implementation callbacks are waiting, review or dispatch callbacks before filling every idle B slot.
- One overflow supervisor may be used only while B-report review, implementation verification, executed-report lifecycle work, or callback preparation is backlogged.
- Completed B-agent subagents stay loaded and idle for rotation reuse unless stale, broken, duplicated, identity-mismatched, cap-conflicting, or explicitly closed by the user.

## Retired Overrides Log

- Legacy primary queue based on `Total_Reconstructable_NoOwner / Total_Reconstructable_NonEmits` in `auto-generated/-ag-memory-coverage.md` is retired as the default B-agent queue. It remains secondary context only.
- Legacy instruction to complete all files in `Supervisor_notes.md` and then rebuild a list from `-ag-memory-coverage.md` is retired unless a current user instruction restores it.
- Legacy broad "fix any associated item as deeply as needed" wording is retired; assignments now require explicit support scope and blocker handling.
```

## `.codex/AGENTS.md`

### `## Role Routing`

Change the supervisor bullet.

Current problem:

- The supervisor bullet points only to `Supervisor.md`, while B-report review actually requires the NTK skill and supervisor Rule 26 reference.

Replace the supervisor bullet with:

```markdown
- Supervisor role: for routine pool management, follow `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`. For B-agent report review, implementation callbacks, implementation verification, or executed-report lifecycle work, also use `.codex/skills/ntk-b-agent-workflow/SKILL.md` and its supervisor Rule 26 reference.
```

Quality guard:

- Routine pool management stays lightweight.
- B-report signoff still loads the full review standard.

### `## Project-Level Skill Routing`

Add one sentence after the two reference bullets:

```markdown
Routine supervisor pool-management loops do not need to load the B-agent references unless the loop is assigning, reviewing, verifying, or executing B-agent work.
```

Quality guard:

- Prevents unnecessary skill/reference loading during simple pool status checks.

### `## Common Rules`

Keep these current bullets:

- do not edit `auto-generated/-ag-*` manually;
- compare validator command metadata with generated headers when generated output matters;
- do not hand-edit validator/tool state;
- use validator lifecycle commands for missing/stale registry entries.

Do not add more detailed Rule 26, B-agent, or validator command syntax here.

Quality guard:

- `.codex/AGENTS.md` remains a routing and safety file, not another workflow manual.

### `## Canonical Supervisor Location`

Replace the section with:

```markdown
## Canonical Supervisor Locations

Routine supervisor orchestration lives in:

`source-3/project-documentation/tools/leaser/Agents/Supervisor.md`

B-agent report review, implementation callbacks, and Rule 26 verification live in:

`.codex/skills/ntk-b-agent-workflow/SKILL.md`
`.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`

Do not duplicate those policies here.
```

Quality guard:

- Resolves the current "Supervisor.md only" conflict without losing either role path.

## `.codex/skills/ntk-b-agent-workflow/SKILL.md`

### Project Context Paragraph Under `# NTK B-Agent Workflow`

Replace the long project context paragraph with a short summary plus pointer:

```markdown
Project context: NexusTK documentation reconstructs a native Windows C++ game client. The rebuilt executable must preserve original behavior, and emitted source should look like plausible late-1999 through mid-2000s human-written C++, not decompiler output. Detailed inference and source-shape rules live in `references/b-agent-research-and-implementation-workflow.md`.
```

Move no facts out permanently; the full version already exists in the B-agent and supervisor references.

Quality guard:

- Agents still see the mission, but detailed context is read once from the role-specific reference.

### "The repo instructions remain authoritative. Read the relevant local files first:"

Replace the current broad bullet list with a read-gated list:

```markdown
Read gates:

- Routine supervisor pool management: `tools/leaser/Agents/Supervisor.md`.
- B-agent report-only or implementation callback: assigned `Agent-B###/goal.md` plus `references/b-agent-research-and-implementation-workflow.md`.
- Supervisor B-report review, callback, verification, or execution: `tools/leaser/Agents/Supervisor.md` plus `references/supervisor-rule26-review-and-incorporation-standard.md`.
- Validator command syntax or lifecycle repair: `tools/validator_README.txt` only when the command is unfamiliar, failed, or explicitly needed.
- MCP failure investigation: `references/mcp-incident-playbook.md` only when MCP fails, repeatedly times out, or disappears.
- Archived B reports: search first with target UID/address/name/source-family; open only matching reports.
```

Quality guard:

- Required role documents are still loaded.
- Generated/archive reading becomes search-triggered instead of default.

### IDA MCP Availability Paragraphs

Keep a short normal-operation rule in `SKILL.md`; move the detailed incident text to `mcp-incident-playbook.md`.

Replacement text:

```markdown
IDA MCP is mandatory for normal B-agent research/report acceptance unless a current explicit supervisor/user instruction says otherwise for the specific target. B agents may perform read-only availability checks but must not start, stop, restart, or kill MCP/IDA/Python processes. If MCP is unavailable, repeatedly times out, or disappears, pause MCP-dependent work and use `references/mcp-incident-playbook.md`. Do not accept fallback-only B reports unless the current explicit instruction permits that exception.
```

Quality guard:

- MCP requirement remains strict.
- Normal tasks stop paying the token cost of the full incident checklist.

### Missing/Stale Validator Registry Paragraph

Replace the detailed command list with a pointer:

```markdown
Missing by-* files, stale UID mappings, and executed-report registry repairs are validator-owned. Do not edit `tools/validator.ini`, queue JSON, lock files, or generated Markdown. Use `tools/validator_README.txt` for `--remove-missing`, `execute-rescan-reports`, `execute-confirm-change`, `executed-reassign`, and `invalidate_execute`.
```

Quality guard:

- No manual registry edits.
- Command details remain in the validator README.

### `## Roles` -> `### B-Agent Research Pass`

Delete the repeated long score-blocker/no-defensible-improvement paragraphs from this section after creating `score-blocker-audit-standard.md`.

Replace them with:

```markdown
Score/source-quality blockers are part of the assignment. Follow `references/score-blocker-audit-standard.md`. A report that leaves an in-scope blocker as "needs more investigation" or recommends unchanged metadata because a named blocker still needs work is incomplete unless the blocker was explicitly excluded or the report proves the rare no-improvement exception.
```

Quality guard:

- The strict rule remains, but one canonical file owns the full proof burden.

### `### B-Agent Implementation Callback`

Replace the long lease-discipline paragraph with a short pointer:

```markdown
Use short edit leases only for the immediate edit/validator batch. Do not hold leases while researching, waiting, or working elsewhere. Full lease rules live in `references/b-agent-research-and-implementation-workflow.md` -> `## Leasing`.
```

Keep these rules in this section:

- B agents apply accepted report details themselves during callbacks.
- Generated reports and manual `-coverage-report.md` files remain excluded unless explicitly overridden.
- Implementation is incomplete if accepted claims are missing.

Quality guard:

- Lease policy remains enforceable from the canonical B-agent reference.

### `## Coverage And Generated Files`

Replace the section body with:

```markdown
Generated project-state files are inputs unless validator/project tools update them. Do not manually edit files under `auto-generated/` or generated `project-level/` reports.

Validator-generated reports and `auto-generated/NexusTK/**` C++ may refresh in the background after file/full/documented validator commands return. Validator output includes `command_id` and `command_timestamp`; generated files include `validator-command-id` and `validator-refreshed-at` headers. When generated output matters, compare those values or run the validator with `--wait-generated`.

The validator must not clear valid by-* `Item Summary` text during normal scoped validation. Treat summary loss as a tool/state/edit problem to investigate, not expected behavior.

B agents must not edit generated reports or manual `-coverage-report.md` files unless a current assignment explicitly names the file and grants permission. For generated by-memory coverage, update source by-memory metadata and run the validator.
```

After adding this replacement, delete the old duplicated lists/examples for:

- full generated-report ownership explanation;
- full manual coverage-report exception wording;
- repeated by-memory `Item Summary` details;
- repeated generated-refresh metadata examples.

Keep those details only in:

- B-agent reference `## Required Reading And Evidence Sources`;
- B-agent reference coverage/generated-file rules;
- supervisor reference `## Coverage And Generated File Rules`;
- `validator_README.txt` command metadata/generated refresh sections.

Quality guard:

- Critical generated-file safety remains visible in the skill overview.

### `## Validation`

Keep the normal scoped command example.

Replace the full third-party import directive section with:

```markdown
For third-party static source imports, use the validator import directive documented in `tools/validator_README.txt` and `by-structure.md`: paths must start with `third_party_embeds/`, resolve under `source-3/third_party_embeds`, and leave the multiline C++ block blank. Validate with generated output current, normally `--wait-generated`.
```

Quality guard:

- Agents still know the rule.
- Syntax details live in one validator/source-structure location.

## `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`

### `## Table Of Contents`

After creating the new reference files, update the TOC:

- remove `Final Report Template` if the full template moves out;
- add `Read Gates`;
- add `Score Blocker Audit Standard`;
- add `Report Template Pointer`;
- keep `Implementation Tracking Checklist`.

### `## Required Reading And Evidence Sources`

Replace the numbered 1-15 source list with four gated subsections:

```markdown
### Always Read
- Assigned `Agent-B###/goal.md`.
- `notes.md` only when it exists and contains current assignment state.
- Assigned target by-* doc.
- Direct owner/emitter/support docs named by the assignment or target.
- `by-structure.md` sections relevant to the target type and validator UID workflow.

### Read When Triggered
- `auto-generated/-ag-research-tracker.md` when selecting a new B target or verifying executed-report coverage.
- `auto-generated/-ag-coverage-report-by-memory.md` when by-memory generated coverage, `Item Summary`, `Nested`, or generated freshness matters.
- Other `auto-generated/-ag-*-coverage.md` reports only when the target belongs to that folder/category.
- `project-level/-auto-completion-stats.md` only for secondary score context.
- `project-level/-resolved*.md` and `project-level/-unresolved.md` only when the target has alias/unresolved-name questions.
- `tools/validator_README.txt` only for unfamiliar validator modes, cleanup, generated refresh, queueing, UID/reference repair, executed-report lifecycle, or third-party import syntax.

### Search Before Reading Old Reports
- Search central executed reports, legacy executed reports, and archived reports with `rg` using target UID, address range, current name, old generated name, owner candidate, and source-family terms.
- Open only matching reports.
- Record the search terms in the report's `Evidence Checked`.

### Incident-Gated Reading
- Read MCP logs only when MCP fails, repeatedly times out, or disappears.
- Read tool internals only when explicitly debugging validator/tool code under supervisor/user instruction.
```

Quality guard:

- Agents still gather old-report evidence when relevant.
- Token cost drops because archives are search-gated.

### `## Target Selection`

Add a top-level "Current Queue Precedence" paragraph:

```markdown
For B-agent report-only assignments, use `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable` as the active primary queue unless the current supervisor/user instruction names a different queue. Treat `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, and `project-level/-auto-completion-stats.md` as secondary context unless the current goal explicitly says they are the queue.
```

Remove or mark as secondary any text that implies the legacy manual coverage report is still the default B-agent queue.

Quality guard:

- Prevents agents from selecting stale queues while still allowing explicit supervisor overrides.

### `## General Research Mission`

Replace "Take as long as needed" with bounded completion criteria:

```markdown
Research until every in-scope target question has one of these outcomes: resolved with evidence, converted into an implementation-ready repair/split/source-quality plan, explicitly excluded by supervisor scope, or documented under the rare no-improvement exception in `score-blocker-audit-standard.md`. Do not expand into unrelated adjacent work; record nonblocking adjacent findings as follow-up.
```

Quality guard:

- The agent cannot stop early, but also cannot chase unrelated work indefinitely.

### `## Heuristic Reconstruction And Source-Quality Mandate`

Move the long repeated no-defensible-improvement proof burden into `score-blocker-audit-standard.md`.

Keep in this section:

- list of heuristic issue types;
- evidence sources to use;
- requirement to include `Heuristic / Inference Reanalysis And Validation`;
- one pointer to the score-blocker standard.

Quality guard:

- Source-quality requirements remain in this role reference.
- The repeated rejection language becomes canonical elsewhere.

### `## Research Output Requirements`

Replace "Take as long as needed. A checkpoint can be short..." with:

```markdown
A checkpoint may be short. A final report must satisfy the required-section matrix and the implementation checklist. Use `references/b-agent-report-template.md` when drafting the final report.
```

Quality guard:

- Prevents broad time language while preserving final report depth.

### `## Final Report Template`

Move the full template from this section into `references/b-agent-report-template.md`.

Replace the section with a required-section matrix:

| Trigger | Required sections |
| --- | --- |
| Every final report | Target, Current Target State, Evidence Checked, Positive Evidence, Negative Evidence, Heuristic/Reanalysis, Score And Metadata, First-Draft C++ or No-Code Proof, Implementation Tracking Checklist |
| Ownership/source-placement decision | Ranked Ownership Analysis, Source Placement, Recommended Target/Support Doc Changes |
| Split/range/container issue | Range/Split/Padding/Reclassification, Function/Child Inventory |
| C++/emitter decision | First-Draft C++ Recommendation, emitter-route evidence, generated-output freshness expectations |
| Third-party import | Third-party import directive, staged source path/provenance, `--wait-generated` validation expectation |
| Manual supervisor-owned tracker/coverage update | Exact Manual Supervisor-Owned Coverage Or Tracker Text |

Quality guard:

- Agents still use the full template when drafting, but early evidence gathering is not burdened by every heading.

### `## Inference Claim Ledger`

Rename this template section to `## Claim And Incorporation Ledger`.

Replace the table with:

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |

Allowed `Action` values:

- `incorporate`;
- `already-present`;
- `historicalize`;
- `reject-stale`;
- `reject-invalid`;
- `not-applicable`.

Allowed `Verification state` values:

- report-only: `proposed`;
- callback: `applied`;
- callback: `already-present`;
- callback: `excluded-with-reason`;
- callback: `blocked`.

Quality guard:

- The existing inference ledger becomes useful for supervisor Rule 26 verification.

### `## Implementation Tracking Checklist`

Keep the checklist, but add one required item under both report-only and implementation callback:

```markdown
- [ ] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim:
```

Quality guard:

- Supervisors can audit incorporation without re-reading the full report repeatedly.

### `## Tools`

Delete the detailed MCP repeated-failure and log-inspection bullets from this section after creating `mcp-incident-playbook.md`.

Keep this exact compact MCP block in `## Tools`:

```markdown
IDA MCP endpoint: `http://127.0.0.1:13337/mcp`. Recheck `tools/list` in the active session before relying on a schema.

B agents may use read-only availability checks and MCP inspection calls. B agents must not start, stop, restart, kill, or otherwise manage MCP/IDA/Python process state.

If an MCP call times out while listener/process state still exists, treat it as possibly busy, wait briefly, and retry. If MCP remains unavailable, return a paused checkpoint with exact listener/process state and failed call. Use `mcp-incident-playbook.md` for repeated failure or disappearing-session diagnosis.

After MCP is restored, redo or update the MCP-backed evidence pass before returning a final report. Use the safe JSON-RPC flow: `initialize` -> `tools/list` -> `tools/call`.
```

Quality guard:

- Normal tool rules remain compact.
- Incident playbook retains detail.

### `## Rules`

Replace rule 9 with a search-gated version:

```markdown
9. Search existing B reports before finalizing with target UID, address range, target name, old generated names, owner candidates, and source-family terms. Open only matching central executed, legacy executed, archived, or active reports. Record search terms and relevant matches in `Evidence Checked`. Non-executed historical reports are unverified leads only.
```

Replace rule 12 with:

```markdown
12. For long-running B-agent goals, continue only within the assigned target queue or current supervisor scope. Do not expand into unrelated work merely because the overall project is ongoing.
```

Quality guard:

- Search still happens.
- Agents stop using "project never complete" as a reason for uncontrolled scope expansion.

## `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`

### `## Mission`

Replace the long project-objective paragraph with:

```markdown
This file defines supervisor review, acceptance, rejection, implementation-callback, verification, and executed-report lifecycle behavior for B-agent reports. The source-reconstruction objective is behavior-identical NexusTK rebuild output and plausible late-1999 through mid-2000s human-written C++ source shape. For detailed source-shape and inference baseline, use `b-agent-research-and-implementation-workflow.md`.
```

Quality guard:

- Supervisor review still knows the objective without duplicating the full B-agent context.

### `## Required Evidence Sources`

Convert to the same read gates as the B-agent reference, but supervisor-specific:

```markdown
Always read for B-report review:
- current user/supervisor instruction;
- `Supervisor.md`;
- assigned B report;
- target by-* doc;
- support docs named by report/checklist;
- implementation checklist.

Read when triggered:
- generated reports when queue selection or generated output is under review;
- validator README when validator lifecycle/cleanup/import/freshness matters;
- old reports only after `rg` matches target UID/address/name/source-family;
- MCP playbook only when MCP failed or report claims MCP was unavailable.
```

Quality guard:

- Supervisor still reads what is needed for the review decision.

### `## Heuristic And Inference Requirements`

Remove the repeated full no-defensible-improvement proof burden after creating `score-blocker-audit-standard.md`.

Replace with:

```markdown
For score/source-quality blockers and unchanged-score recommendations, apply `score-blocker-audit-standard.md`. Reject by default when the report names a blocker that can be turned into a same-agent instruction and does not prove the blocker was resolved, repair-planned, explicitly excluded, or qualifies for the rare no-improvement exception.
```

Quality guard:

- Same strict rejection behavior, less duplicate text.

### `## Implementation Tracking Checklist Validation`

Add a required check:

```markdown
- the Claim And Incorporation Ledger maps every accepted claim to a target/support doc section or explicit exclusion reason.
```

Add post-implementation verification:

```markdown
For each ledger row, confirm the verification state is accurate before executing the report.
```

Quality guard:

- Strengthens Rule 26 verification.

### `## Implementation Callback Requirements`

For this refactor, keep the full callback quality standard but centralize it in this supervisor reference.

Add this subsection immediately after `## Implementation Callback Requirements`:

```markdown
### Standard B Implementation Callback Block

Implementation quality standard:
- Incorporate every valid report claim into the relevant target/support by-* docs at report-level factual detail. Do not compress the report into a short summary.
- Preserve behavior, call flow, data flow, field/type/global/helper naming decisions, source-placement reasoning, owner/emitter decisions, split/range decisions, score rationale, rejected alternatives, negative evidence, and historical/stale assumptions that were corrected.
- Resolve every accepted row in the report's Claim And Incorporation Ledger as incorporated, already present, historicalized, rejected stale/invalid, not applicable, or blocked with exact reason.
- For every compiler/generated placeholder or other heuristic issue covered by the report, either apply the accepted source-facing name/interpretation or document exactly why the placeholder must remain.
- Resolve targeted open questions when the report provides a high-probability answer. If an open question remains, document evidence checked, rejected alternatives, why no defensible inference is possible, and score/C++ impact.
- If the target is an eligible emitter and the accepted report provides first-draft/example/sample/illustrative C++, insert it as exact formal `RECONSTRUCTION_CPP CODE` header/block content or require a target-specific no-code proof.
- For vetted static third-party source, use the validator inline import directive with paths starting `third_party_embeds/`, keep the multiline block blank, and validate with generated output current.
- Do not edit generated reports or manual `-coverage-report.md` files unless this callback explicitly names the file and permission.
- Do not manually edit `tools/validator.ini`, queue/state files, lock files, or generated reports.
- Run scoped validators and report command, `command_id`, `command_timestamp`, exit code, `ok` count, warnings, generated-refresh state, and target-specific side effects.
```

Replace `Supervisor.md` -> `## Standard B Implementation Handoff Text` with a pointer to this subsection.

Add:

```markdown
Callback prompts must reference the report's Claim And Incorporation Ledger and require the B agent to update each row's verification state.
```

Quality guard:

- Existing callback rigor remains.
- Duplicate callback text is centralized.

### `## How To Merge Report Data Into By-* Docs`

Change "Build a mental or written ledger" to:

```markdown
Use the report's Claim And Incorporation Ledger. If the report lacks one, build it before accepting the report for implementation.
```

Quality guard:

- Makes the ledger mandatory for verification, not optional.

### `## Tool And Validator Review Standard`

Delete the detailed MCP repeated-failure investigation prose from this section after creating `mcp-incident-playbook.md`. Specifically remove the inline lists of logs/processes/listeners/request-shape checks from this supervisor reference; those details belong only in the playbook.

Keep this exact short MCP/validator block in the section:

```markdown
B agents may perform read-only MCP availability checks but must not manage MCP process state. If MCP is unavailable, busy, or repeatedly failing, use `mcp-incident-playbook.md`.

Do not accept fallback-only B reports unless a current explicit instruction permits that target-specific exception. After MCP recovers, the same B agent must redo or update the MCP-backed evidence pass before acceptance.

For validator-backed implementation, verify working directory, command, `command_id`, `command_timestamp`, exit code, `ok` count, generated-refresh state, and side effects. When generated output is used, compare generated headers with returned command metadata or require `--wait-generated`.
```

Quality guard:

- Supervisor still handles MCP safely.
- Incident details become triggered.

### `## Supervisor Acceptance And Rejection Rules`

Replace repeated "needs more investigation" and no-defensible-improvement language with a pointer to `score-blocker-audit-standard.md`.

Keep this exact rejection block:

```markdown
Reject or return a B report when it:

- only summarizes existing docs;
- skips required heuristic/source-quality work;
- omits ranked alternatives, negative evidence, or target/support docs;
- lacks implementation-ready target/support changes;
- lacks a complete Implementation Tracking Checklist or Claim And Incorporation Ledger;
- finalizes fallback-only evidence when MCP was required;
- leaves generated names/tool labels in final source-facing code without target-specific proof;
- omits first-draft C++ or no-code proof for an eligible emitter;
- skips the third-party import directive when vetted importable source exists;
- reports unchanged score/metadata for an in-scope named blocker without satisfying `score-blocker-audit-standard.md`;
- omits validator command metadata or generated-refresh verification when generated output matters.
```

Quality guard:

- Rejection behavior remains strict.

## `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`

### `## Supervisor Role`

Replace the "only document you need" paragraph with:

```markdown
For routine pool management, this `Supervisor.md` file is the supervisor entry point. For B-agent report review, implementation callbacks, implementation verification, or executed-report lifecycle work, also use the project-level `ntk-b-agent-workflow` skill and its supervisor Rule 26 reference. Do not perform documentation work yourself except where supervisor verification or supervisor-owned ledgers require it.
```

Quality guard:

- Fixes routing conflict.
- Keeps supervisor from doing agent work.

### Agent List Under `## Supervisor Role`

Replace the explicit A001-A010 and B001-B015 repeated lines with:

```markdown
Agent pools:

- `Agent-A001` through `Agent-A010`: general documentation agents. Active cap is controlled by `Supervisor_active_overrides.md`.
- `Agent-B001` through `Agent-B015`: B-preferred source-quality, ownership, split/range, heuristic, and implementation-callback agents. Active cap is controlled by `Supervisor_active_overrides.md`.

Each assigned folder contains that agent's `goal.md` and may contain `notes.md`.
```

Quality guard:

- Active caps remain controlled by current overrides.
- Removes repeated model text.

### `## Supervisor Task Overrides ##`

Replace the entire section with:

```markdown
## Active Overrides

Read `Supervisor_active_overrides.md` for temporary pool caps, active target queues, and temporary assignment rules. If that file is empty or absent, use the stable rules in this document and the NTK skill references.
```

Then migrate existing override items as follows. Do not leave any item only in the removed override list.

| Current override | Final status | Exact destination and action |
| ---: | --- | --- |
| 1 | Retire broad wording; keep scoped replacement | Add to `Supervisor_active_overrides.md` -> `Temporary Assignment Rules`: "Assignment prompts must name one target or one small explicit batch, define expected return type, and state allowed support scope." Do not carry forward "as deeply as needed." |
| 2 | Retire as primary queue | Add to `Supervisor_active_overrides.md` -> `Retired Overrides Log`: "`auto-generated/-ag-memory-coverage.md` no-owner/non-emits is secondary context, not the default B queue." |
| 3 | Active | Add to `Supervisor_active_overrides.md` -> `Active Pool Caps`: "Wait cadence: 3 minutes during active pool loops unless reports/callbacks are waiting." |
| 4 | Stable | Add the assignment-only prohibition to `b-agent-research-and-implementation-workflow.md` -> `Target Selection`; put the score/no-improvement burden in `score-blocker-audit-standard.md`. |
| 5 | Active | Add to `Supervisor_active_overrides.md` -> `Temporary Assignment Rules`: "Score delta tracking remains active: agents report before/after scores when changed." |
| 6 | Retire | Add to `Retired Overrides Log`: "Do not rebuild default worklists from `-ag-memory-coverage.md` after notes complete; use current queue precedence." |
| 7 | Stable secondary queue rule | Add to B-agent reference `Target Selection`: "Other `-ag-*-coverage.md` categories are occasional secondary queues only." |
| 8 | Stable | Add parent-support gate to B-agent reference `Target Selection`; add named parent blocker handling to `score-blocker-audit-standard.md`. |
| 9 | Stable | Add to B-agent reference `Split-First Execution Workflow`: split/rename mixed or overbroad memory ranges before final assignment recommendations. |
| 10 | Stable | Add to B-agent reference `Leasing`: new child files cannot be leased before creation; lease existing parent/support only during immediate split edit/validation. |
| 11 | Split | Add "assigned target is entry point, not hard boundary" to B-agent reference `Role Boundaries And Write Scope`; put broad batch wording in `Retired Overrides Log`. |
| 12 | Stable | Add to B-agent reference `Target Selection`: coverage `Total_Error` rows are valid repair candidates when repair requires documentation/range/ownership/source-placement work. |
| 13 | Active | Add to `Supervisor_active_overrides.md` -> `Active Pool Caps`: A001-A005 active, A006-A010 retired until user re-enables. |
| 14 | Split | Add B cap "up to 10 active B agents" to `Supervisor_active_overrides.md`; keep B-preferred target definitions in B-agent reference `B-Preferred Target Types`. |
| 15 | Stable | Keep the B-report flow in `SKILL.md` -> `Standard Flow` and B-agent reference `Standard B-Agent Work Lifecycle`; remove duplicate from `Supervisor.md`. |
| 16 | Stable | Keep generated-file summary in `SKILL.md` -> `Coverage And Generated Files`; keep detailed agent/supervisor rules in both references' coverage sections; remove duplicate from `Supervisor.md`. |
| 17 | Active, rewritten | Add to `Supervisor_active_overrides.md` -> `Active Target Queue`: idle B agents take next primary-queue B-preferred target before broad fallback scans. |
| 18 | Stable | Keep in `by-structure.md` `CANONICAL_OWNER`/`EMITTER_UIDS`; remove duplicate from `Supervisor.md`. |
| 19 | Active maintenance | Add to `Supervisor_active_overrides.md` -> `Active Target Queue`: maintain `no_owner_b-agent-tracker.md` when refreshed reports produce 85/85 no-owner candidates. |
| 20 | Stable | Keep code-entry gate in `by-structure.md` and short summaries in B-agent/supervisor references; remove duplicate from `Supervisor.md`. |
| 21 | Stable | Move to `score-blocker-audit-standard.md`; leave only a one-line pointer in supervisor reference. |
| 21a | Stable | Move to `score-blocker-audit-standard.md` -> `Named Blocker Rule`. |
| 21b | Stable | Move to `score-blocker-audit-standard.md` -> `Supervisor Acceptance Test`. |
| 22 | Stable | Add to supervisor reference `Supervisor Acceptance And Rejection Rules`: heuristic/inference assignments require supervisor review of that inference content. |
| 23 | Stable | Keep in B-agent reference `Heuristic Reconstruction And Source-Quality Mandate`; remove duplicate from `Supervisor.md`. |
| 24 | Stable | Split between `by-structure.md` C++ metadata/range rules and supervisor reference `Score, Ownership, Emitter, And C++ Rules`; remove duplicate from `Supervisor.md`. |
| 25 | Stable | Keep 95+ gate in `by-structure.md` `95+ Scoring Gate`; add supervisor enforcement in supervisor reference C++ rules; remove duplicate from `Supervisor.md`. |
| 26 | Stable | Keep in supervisor reference `How To Merge Report Data Into By-* Docs`; replace duplicate with callback pointer in `Supervisor.md`. |
| 27 | Stable | Keep in supervisor reference `Open Question Closure`; add B-agent output requirement in B-agent reference; remove duplicate from `Supervisor.md`. |
| 28 | Stable | Add covered-by emitter comment rule to `by-structure.md` C++/emitter metadata section. |
| 29 | Stable | Keep B-report lifecycle in `SKILL.md` `Standard Flow` and supervisor reference `Standard B-Agent Work Lifecycle`; remove duplicate from `Supervisor.md`. |
| 30 | Stable | Keep canonical callback contract in supervisor reference `Implementation Callback Requirements`; replace `Supervisor.md` section with pointer. |
| 31 | Active, modified | Add to `Supervisor_active_overrides.md` -> `Backlog/Overflow Rules`: maintain cap but review/dispatch when two or more completed reports/callbacks wait. |
| 32 | Active, modified | Add to `Supervisor_active_overrides.md` -> `Backlog/Overflow Rules`: overflow supervisor is backlog-triggered only; keep stable constraints in supervisor reference mission. |
| 33 | Active efficiency rule | Add to `Supervisor_active_overrides.md` -> `Backlog/Overflow Rules`: keep completed B-agent subagents loaded for rotation reuse unless stale/broken/duplicated/identity-mismatched/cap-conflicting/user-closed. |
| 34 | Stable | Keep full syntax in `tools/validator_README.txt` and `by-structure.md`; keep short references in B-agent/supervisor references; remove duplicate from `Supervisor.md`. |

Quality guard:

- No rule is deleted without a canonical destination.
- Temporary operational state becomes visible and easier to retire.

### `## Standard B Implementation Handoff Text`

Replace this section with a pointer after the supervisor reference owns the reusable callback block:

```markdown
## B Implementation Callback

Use `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md` -> `Implementation Callback Requirements` for the canonical callback block. Fill in target-specific report path, target/support docs, accepted disposition, exact metadata/C++/owner/emitter changes, validators, generated-refresh expectations, and Claim And Incorporation Ledger requirements.
```

Quality guard:

- Callback text remains canonical and full-detail.
- `Supervisor.md` stops duplicating it.

### `## Agent Assignment Rules`

Replace "continue working for as long as possible" and "massive task" bullets with:

```markdown
- The current assignment scope and completion criteria.
- Whether the agent should return after one report, one implementation callback, or a checkpoint.
- The queue or target list to use if the assignment is ongoing.
- What to do when blocked: retry/wait if transient, record exact blocker, then continue only with non-conflicting in-scope work.
```

Quality guard:

- Agents still continue useful work.
- Prevents uncontrolled scope expansion.

### `## Supervision Loop`

Replace fixed "sleep or wait for 5 minutes" with:

```markdown
Wait cadence is controlled by `Supervisor_active_overrides.md`. If no active override exists, use 5 minutes for broad pool management and shorter checks only when reports/callbacks are waiting.
```

Quality guard:

- Current active 3-minute override can remain without living in the stable doc.

### `## Restart Prompt Template`

Remove "continue improving ... for as long as possible" and "massive and cannot be fully completed" wording.

Replace with:

```text
Read and follow your goal.md. Resume the current assignment until its stated checkpoint or completion criteria are met. If a file is leased or blocked, record the exact blocker and continue only with non-conflicting work inside the same assignment scope.
```

Quality guard:

- Restarts remain durable.
- Scope stays controlled.

## `source-3/project-documentation/by-structure.md`

### `## Current Research Priority`

Change this section title to:

```markdown
## General Research Priority
```

Add this first paragraph:

```markdown
This section is general documentation priority. It does not override current supervisor goals, B-agent assignment queues, or validator-generated research tracker priority. For B-agent report-only assignment queues, follow the NTK B-agent workflow and active supervisor overrides.
```

Quality guard:

- Existing broad documentation priority remains useful.
- B-agent queue conflict is resolved.

### `### Validator UID Workflow`

Keep UID/TMP/validator rules here.

Do not duplicate executed-report lifecycle details beyond a pointer to `validator_README.txt`.

Quality guard:

- by-structure remains the core page-structure rule file.

### C++/Emitter Metadata Paragraphs Around `CANONICAL_OWNER`, `EMITTER_UIDS`, And `RECONSTRUCTION_CPP CODE`

Keep these stable rules here:

- `CANONICAL_OWNER` direct semantic owner;
- `EMITTER_UIDS` output routing;
- multiple emitters with `CANONICAL_OWNER:NONE` when no single owner is defensible;
- code-entry gate `(COMPLETION + CONFIDENCE) / 2 > 85`;
- range-limited C++;
- third-party import directive;
- covered-by comment marker for marker-only emitters.

Add the covered-by marker rule from Supervisor override 28 here:

```markdown
If a reconstructable item is intentionally covered by another emitter and should not emit its own body, use a minimal formal C++ comment such as `// Emitted code for this range is covered by [UID:xxxx].` rather than leaving the item looking like an empty emitter.
```

Quality guard:

- Emitter behavior stays with the metadata rules that validators and agents already consult.

## `source-3/project-documentation/tools/validator_README.txt`

### Command Output Sections

Add one agent-facing output rule near the command metadata/generation refresh section:

```markdown
For successful scoped validation, agents should report only command, `command_id`, `command_timestamp`, exit code, `ok` count, generated-refresh state, relevant warnings, and target-specific side effects. Full raw stdout should be included only for failures, unusual diagnostics, or when `--verbose` was explicitly requested.
```

Quality guard:

- Agents still report auditable validator metadata.
- Routine success output stays short.

### Third-Party Import Directive Section

Keep this as the canonical syntax source.

Make the skill and workflow references point here instead of repeating full syntax multiple times.

Quality guard:

- Validator behavior and error rules remain documented where users expect command syntax.

### Missing File / Registry Repair Sections

Keep detailed command syntax here:

- `--remove-missing`;
- `execute-rescan-reports`;
- `execute-confirm-change`;
- `executed-reassign`;
- `invalidate_execute`.

Remove only duplicated lifecycle prose from other docs after they point here.

Quality guard:

- Agents still know not to hand-edit state.
- Exact command help stays in the validator README.

## Existing Agent `goal.md` Files

Do not bulk-edit active goals immediately. Some contain target-specific implementation details that should stay intact.

For future goals:

### Report-Only Goal Shape

Keep:

- agent folder;
- assignment id;
- mode;
- target UID/path;
- report path;
- selection reason;
- required target-specific focus;
- explicit exclusions.

Do not paste:

- full Rule 26 standard;
- full validator/generated rules;
- full score-blocker standard;
- full MCP incident rules.

### Implementation Callback Goal Shape

Keep:

- accepted report path;
- target UID/path;
- accepted disposition;
- exact target/support files to edit;
- exact C++ insertion text or import directive;
- exact validator commands;
- exact generated-output checks;
- target-specific stale claims to remove/historicalize.

For future implementation callbacks, reference these canonical standards by file/section instead of pasting them:

- Rule 26 incorporation: `supervisor-rule26-review-and-incorporation-standard.md` -> `How To Merge Report Data Into By-* Docs`.
- Callback quality block: `supervisor-rule26-review-and-incorporation-standard.md` -> `Standard B Implementation Callback Block`.
- Lease discipline: `b-agent-research-and-implementation-workflow.md` -> `Leasing`.
- Generated-file exclusion: `b-agent-research-and-implementation-workflow.md` -> `Role Boundaries And Write Scope` and supervisor reference `Coverage And Generated File Rules`.
- Score blockers: `score-blocker-audit-standard.md`.

Quality guard:

- Current callbacks remain self-contained enough for exact target work.
- Future callbacks stop repeating global policy.

## Refactor Execution Order

Perform the edits in this order to avoid dropping rules:

1. Add `score-blocker-audit-standard.md`.
2. Add `mcp-incident-playbook.md`.
3. Add `b-agent-report-template.md` and move the full report template there.
4. Add `Supervisor_active_overrides.md` and migrate current override items using the table above.
5. Fix `.codex/AGENTS.md` supervisor routing.
6. Thin `Supervisor.md`.
7. Thin `SKILL.md`.
8. Update the B-agent reference read gates, template pointer, claim ledger, and score-blocker pointer.
9. Update the supervisor Rule 26 reference to use the canonical score-blocker standard and incorporation ledger.
10. Update `by-structure.md` queue-priority clarification and covered-by emitter marker rule.
11. Update `validator_README.txt` command-output reporting guidance.
12. Only then remove duplicated permanent rules from old locations.

## Verification Checklist

After implementing the documentation refactor:

- Complete the `Rule Preservation And Same-Task Audit` gate before deleting any duplicated rule text.
- Confirm none of the `Same-Task Stop Conditions` are true.
- Run the `No-Deletion Verification Commands`; any missing required concept blocks deletion until repaired.
- Search for `only document you need`; it should no longer conflict with skill routing.
- Search for `needs more investigation`; only the canonical score-blocker standard and concise rejection bullets should contain it.
- Search for `third_party_embeds`; full syntax should be canonical in `validator_README.txt` and `by-structure.md`, with shorter pointers elsewhere.
- Search for `validator.ini`; only safety warnings and validator README command details should remain.
- Search for `Take as long as needed` and `continue working for as long as possible`; replace with explicit completion/checkpoint criteria.
- Confirm `Supervisor.md` has no 34-item permanent override dump.
- Confirm B-agent report template is not embedded in the main workflow reference.
- Confirm the B-agent reference has search-gated old-report reading.
- Confirm the Claim And Incorporation Ledger appears in both report requirements and supervisor verification requirements.
- Confirm `by-structure.md` no longer appears to override current B-agent queue priority.
