# Agent-B015 Current Assignment

- Use the project-level `ntk-b-agent-workflow` skill for all general B-agent instructions. This file contains only the current assignment and overrides.
- Agent identity: `B015`.
- Required runtime/provenance for this assignment: `** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **`.
- Current supervisor cap/spec override: maintain 5 active B-agent workstreams using GPT 5.5 xHigh whenever eligible current-queue work or unfinished B-agent lifecycle work exists.
- You are not alone in the codebase. Do not revert edits made by others.

Project context: this is a local old-game preservation effort for an unsupported NexusTK client, intended to keep the game runnable through archival compatibility research and faithful source reconstruction.

## Current Assignment

- Mode: report-only source-quality research first.
- Target: [UID:00011O] `by-memory/0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md`.
- Expected report path: `tools/leaser/Agents/Agent-B015/research/00011O-NumericStringControlPaneRenderNumericString-source-quality.md`.
- Selection source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Reason selected: clean current-queue reconstructable by-memory target with no active root report and no obvious executed B-report mention in the current duplicate check.
- Required return: create/update the report only, then stop with `READY_FOR_SUPERVISOR_GATE1_REVIEW`.

## Report Scope

Investigate UID00011O deeply under the B-agent workflow:

- current owner/emitter/source-file route for `NumericStringControlPane::RenderNumericString`;
- whether the formal C++ block should remain blank or receive first-draft source-like render C++;
- exact behavior for bounds clearing/fill, text length/width, alignment mode, glyph-rect advance, minus/space/slash handling, `FONTSYMB.EPF` / `FONTSYMB.PAL`, `9X11FONT.BIN`, draw callback, and font/color fields;
- field/helper/global/type names that currently block final-source C++;
- direct callers, vtable reachability, resource/literal evidence, padding, adjacent destructor/core boundaries, and source placement under `NumericStringControlPane`;
- all score-limiting blockers, including whether they can be resolved now rather than left as generic future work.

Use current IDA MCP evidence unless MCP is unavailable. If MCP is unavailable, busy, or repeatedly fails, stop and report the exact supervisor-needed MCP issue; do not finalize a fallback-only report.

Treat existing by-* docs and old reports as leads only. Revalidate target-critical claims against current evidence where possible.

## Report Requirements

- Use the current B-agent report template and exact required headings.
- Include exact provenance headers:
  - `** TARGET-REPORT-UID:00011O **`
  - `** AUTHOR-AGENT-ID:B015 **`
  - `** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **`
- Include positive and negative evidence, heuristic/inference reanalysis, score/metadata rationale, first-draft C++ or no-code proof, recommended target/support doc changes, and an implementation tracking checklist.
- If any C++ is recommended, provide exact formal `RECONSTRUCTION_CPP CODE` insertion text, not a side example.
- Do not say a blocker "needs investigation" as a final answer. Either resolve it, convert it into an implementation-ready repair/split/source-quality plan, explicitly exclude it by scope, or prove the rare no-improvement exception with exact evidence.

## Boundaries

- Do not edit by-* docs, generated files, coverage reports, supervisor ledgers, validator state, queues, locks, archives, lifecycle files, or any `-coverage-report.md` file during this report-only pass.
- Do not run validators during report-only work unless the supervisor explicitly sends an implementation callback.
- Do not run `execute_report`, dry-run/probing execute variants, registry lifecycle/archive commands, manual report moves, archive moves, or equivalent lifecycle commands.
- Do not start, stop, restart, or kill IDA/MCP.
- Report-only research normally does not require leases. Take leases only if a later implementation callback authorizes edits.

## Return Condition

Return only when the report-only pass is complete with:

- `READY_FOR_SUPERVISOR_GATE1_REVIEW`
- report path and SHA256
- evidence sources used, including MCP session/status
- files read
- confirmation that only the report file was changed
- confirmation that no by-* docs, generated files, coverage reports, supervisor ledgers, validator state, lifecycle/archive files, manual report moves, or `execute_report` variants were touched
