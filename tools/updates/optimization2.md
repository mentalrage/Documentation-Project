# Tool Output Guidance Audit

This report audits project tool guidance for commands that can waste agent time
or return excessive command-line output. It focuses on IDA MCP, validator,
`unresolved.py`, `memory_ranges.py`, and small helper tools.

## Summary

The main issue is IDA MCP guidance. The current documentation tells agents to
use MCP for disassembly, decompilation, xrefs, strings, and structure evidence,
but it does not give enough output-shaping rules. The local MCP schema snapshot
also shows that several documented examples are stale relative to the current
tool names and argument shapes.

Validator guidance is already mostly correct and compact. The smaller helper
tools have only minor guidance gaps.

## High-Priority Issues

### 1. IDA MCP docs lack explicit output limits

Affected docs:

- `source-3/project-documentation/by-structure.md`, lines 27-32.
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`, lines 354-390.

`by-structure.md` lists high-output tools such as `list_funcs`,
`list_globals`, `imports`, `decompile`, `disasm`, xref tools, string/search
tools, analysis tools, structure tools, and `py_eval`, but it does not tell
agents when to use filters, limits, offsets, address bounds, or safer compact
tools.

Risk:

- Agents can accidentally request thousands of functions, globals, imports,
  strings, xrefs, disassembly lines, or analysis details.
- Tool calls may time out, make MCP look broken, or dump large output into the
  agent context.
- Broad output does not improve research quality because agents still need
  targeted evidence for the assigned function/range/page.

Recommended fix:

Add an `IDA MCP Output Discipline` subsection near the MCP notes in
`by-structure.md`, and reference it from the B-agent workflow `## Tools`
section.

Required guidance:

- Prefer exact-address workflows first: `lookup_funcs`, then targeted
  `analyze_function`, `decompile`, `disasm`, xrefs, bytes, or type inspection.
- Do not call broad listing/search/query tools without filters and explicit
  limits.
- Use `count` or `limit <= 50` for exploratory calls unless the supervisor
  explicitly asks for broad enumeration.
- Page with `offset` instead of increasing the cap.
- Use address or segment bounds for listing/search tools when available.
- Avoid `count=0`, `limit=0`, or any "all" setting unless explicitly approved.
- For `disasm`, start with `max_instructions <= 200`; page with `offset` if
  the function is larger.
- For `decompile`, set address-line markers off when exact line addresses are
  not needed.
- Avoid `py_eval` for IDB-wide enumeration. If it is used, the expression must
  return a capped summary, not raw lists.

Quality impact:

No quality reduction. This changes how evidence is gathered, not the evidence
bar. Agents still verify exact ranges, xrefs, callers/callees, strings,
globals, data flow, and source placement, but they do it in targeted calls.

### 2. MCP tool examples appear stale versus the local schema snapshot

Affected docs:

- `source-3/project-documentation/by-structure.md`, lines 24 and 28-32.

The docs correctly say to re-run `tools/list` before relying on a schema, but
they still present specific examples that conflict with the local
`.ida_tools_list.json` snapshot:

- `by-structure.md` says current `decompile` uses `addrs`, while the local
  schema shows `decompile` requires singular `addr`.
- `by-structure.md` mentions `callers`, but the local schema snapshot does not
  list `callers`; it lists `callees`, `xref_query`, `analyze_function`, and
  other tools that can supply caller/callee evidence.
- `by-structure.md` mentions `analyze_funcs`, `strings`, and `search`; the
  local snapshot shows newer or different names such as `analyze_function`,
  `analyze_component`, `analyze_batch`, `find_regex`, `search_text`, and
  `find`.

Risk:

- Agents may waste time retrying invalid calls.
- Failed calls can be misdiagnosed as MCP instability.
- Agents may use broad fallback tools when a targeted current-schema tool
  exists.

Recommended fix:

Replace fixed "current" examples with a schema-check pattern and a short
current-schema matrix:

| Need | Preferred current-schema pattern |
| --- | --- |
| Broad triage | `survey_binary detail_level='minimal'` |
| Function lookup | `lookup_funcs` with exact address/name |
| Function summary | `analyze_function` with `include_asm=false` |
| Decompile | `decompile` on one `addr`; disable address markers when not needed |
| Disassemble | `disasm` with low `max_instructions` and `offset` paging |
| Function listing | `func_query` or `list_funcs` with `filter`, `count`, `offset` |
| Globals/imports/strings/names | `entity_query`, `imports_query`, or specific query tools with limits |
| Xrefs/callers/callees | `xref_query`, `xrefs_to`, `callees`, or compact analysis tools with limits |
| Text search | `search_text` with `start`, `end`, and `limit` |
| Byte/immediate search | `find` or `find_bytes` with explicit `limit` and `offset` |
| Type/struct work | `type_query`, `type_inspect`, `search_structs` with filters and member caps |
| Call graph | `callgraph` with low `max_depth`, `max_nodes`, and `max_edges` |

The docs should still tell agents to trust the active `tools/list` response over
any static example.

Quality impact:

No quality reduction. This makes agents use the active schema and prevents stale
examples from causing retries or invalid evidence gaps.

### 3. High-output MCP tools need specific per-tool caps

The local `.ida_tools_list.json` snapshot shows these risky defaults or "all"
behaviors:

- `list_funcs`, `func_query`, `list_globals`, `entity_query`, `imports_query`,
  and `type_query` support `filter`, `offset`, and `count`; `count=0` means all
  for several of them.
- `imports` accepts `count`, and `count=0` returns all imports.
- `find_regex` defaults to `limit=30`, which is safe.
- `search_text` defaults to `limit=30`, but without `start` and `end` it scans
  the whole image.
- `disasm` defaults to `max_instructions=5000`, which is too large for routine
  evidence gathering.
- `find` and `find_bytes` default to `limit=1000`, which is too high for
  exploratory work.
- `xrefs_to` defaults to `limit=100`, reasonable for exact targets but still
  should be explicit.
- `callees` defaults to `limit=200`, reasonable for exact functions but still
  should be explicit.
- `callgraph` defaults to `max_depth=5`, `max_nodes=1000`, and
  `max_edges=5000`, which is too broad for routine target work.
- `analyze_batch`, `func_profile`, `basic_blocks`, `type_inspect`, and similar
  tools have optional include/cap settings that should be kept narrow.

Recommended fix:

Add default agent caps:

- Exploratory `count` or `limit`: `<= 50`.
- Xrefs per exact address: `<= 100`.
- Disassembly first page: `<= 200` instructions.
- Callgraph: `max_depth <= 2`, `max_nodes <= 100`, `max_edges <= 300` unless
  explicitly approved.
- Batch analysis: only the assigned target and directly relevant support
  functions; disable optional heavy sections unless needed.
- Types/structs: require a filter/name and cap members.

Quality impact:

No quality reduction. Agents can page forward when the first capped response
proves more output is needed.

## Medium-Priority Issues

### 4. `py_eval` needs a hard safety rule

Affected docs:

- `source-3/project-documentation/by-structure.md`, line 32.

The docs list `py_eval` as a possible MCP tool but do not constrain it. The
local `.ida_tools_list.json` snapshot checked for this report does not currently
include `py_eval`, so this is a defensive rule for sessions or server versions
where it appears.

Recommended fix:

Add:

> Use `py_eval` only for read-only targeted checks. It must return a small
> capped summary or scalar values. Do not print IDB-wide function/global/string
> lists, raw large arrays, full decompiler output, or file contents from
> `py_eval`.

Quality impact:

No quality reduction. Anything useful from `py_eval` should be explainable as a
small targeted result.

### 5. MCP incident guidance should mention heavy-call false positives

Affected docs:

- `.codex/skills/ntk-b-agent-workflow/references/mcp-incident-playbook.md`,
  lines 20-25.

The incident playbook says to determine busy versus down, but it does not tell
agents to check whether the previous call was an oversized query.

Recommended fix:

Add a check:

- If the failed call used no limit/count, requested full-image search, large
  disassembly, broad callgraph, `py_eval`, or batch analysis, classify it first
  as a possible heavy-call timeout. Retry with a narrow bounded version before
  treating MCP as unstable.

Quality impact:

No quality reduction. This prevents unnecessary restarts and avoids accepting
fallback-only reports after a self-inflicted timeout.

## Low-Priority Issues

### 6. `unresolved.py --verbose` should be discouraged for normal agent runs

Affected docs:

- `source-3/project-documentation/tools/unresolved_README.txt`, lines 293-297.

The README documents `python unresolved.py --verbose`, which prints matched
token file counts. It does not say agents should avoid it during normal work.

Recommended fix:

Add:

> Use `--verbose` only when debugging scanner behavior. Normal agent work should
> inspect the generated reports or run file-scoped dry scans without verbose
> output.

Quality impact:

No quality reduction. The generated reports contain the durable information.

## Tools Already Acceptable

### Validator

`source-3/project-documentation/tools/validator_README.txt`, lines 42-60,
already gives good output guidance:

- run one file scan after one-file edits;
- do not run repeated full/documented scans for ordinary single-file edits;
- use `--wait-generated` only when generated files must be current before
  returning;
- successful scoped validation should report command metadata, exit code, `ok`
  count, generated-refresh state, relevant warnings, and target-specific side
  effects only;
- full raw stdout should appear only for failures, unusual diagnostics, or
  explicit `--verbose`.

No change required beyond keeping examples concise.

### `memory_ranges.py`

`memory_ranges.py` writes reports rather than dumping large stdout by default.
The README describes dry-run outputs and states that advanced scan reads
Markdown only and does not query IDA/MCP. No immediate output guidance issue was
found.

### `int_convert.py`

The helper documentation already says agents should omit `--pretty` unless a
person will read the output. No change required.

## Recommended Documentation Patch Set

### Exact Insert Locations

Use these locations as the intended patch anchors. Line numbers are from the
current files at the time of this report; if the files shift, use the quoted
anchor text.

1. `source-3/project-documentation/by-structure.md`

   Location A, MCP output discipline:

   - Current anchor: line 41, the bullet beginning `- PowerShell trap: do not
     name a helper function parameter`.
   - Insert after that bullet and before line 43, `## Directory Roles`.
   - Add a new short subsection named `#### IDA MCP Output Discipline`.
   - Content should cover: exact-address-first workflow, explicit
     `count`/`limit`, no `count=0`/`limit=0`/all-output calls without approval,
     `search_text` `start`/`end`, low first-page `disasm max_instructions`,
     disabling decompile line addresses when not needed, bounded callgraph, and
     `py_eval` capped-summary-only rules.

   Location B, stale MCP examples:

   - Current anchors: lines 28-32, the bullets beginning `- Current
     tools/call request shape`, `- For current decompile`, `- lookup_funcs uses`,
     and `- MCP has previously returned`.
   - Replace these bullets or rewrite them in place.
   - New text should avoid presenting durable hard-coded argument shapes. It
     should say `tools/list` from the active session is authoritative and then
     give schema-checked examples only, including the local snapshot caveat:
     local `.ida_tools_list.json` currently shows `decompile` with singular
     `addr`, not `addrs`.

2. `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`

   Location A, `## Tools` tool list:

   - Current anchor: line 360, `- IDA MCP as documented in
     by-structure.md;`.
   - Replace with wording that says IDA MCP must follow `by-structure.md` and
     its `IDA MCP Output Discipline` subsection.

   Location B, MCP schema/output sentence:

   - Current anchor: line 365, `IDA MCP endpoint:
     http://127.0.0.1:13337/mcp`.
   - Insert one sentence after this line, before the B-agent process-management
     paragraph at line 367.
   - Sentence should say agents must prefer narrow, paged, schema-current MCP
     calls and must not use broad list/search/disassembly/analysis calls without
     filters and explicit caps.

   Location C, timeout handling:

   - Current anchor: line 369, `If an MCP call times out while listener/process
     state still exists`.
   - Add a sentence after this paragraph, before line 371.
   - Sentence should say oversized unbounded MCP calls must be retried in a
     narrowed bounded form before being treated as MCP instability.

3. `.codex/skills/ntk-b-agent-workflow/references/mcp-incident-playbook.md`

   Location A, B-agent failed-call capture:

   - Current anchor: line 14, `record exact failed call, time,
     listener/process state, and whether failure looked busy or down`.
   - Add a following bullet requiring agents to record whether the failed call
     was unbounded or broad: no `limit`/`count`, full-image search, large
     disassembly, broad callgraph, batch analysis, or `py_eval`.

   Location B, supervisor busy-versus-down checks:

   - Current anchor: line 24, `retry briefly if listener/process exists and a
     heavy request may be running`.
   - Add a following bullet requiring a narrowed retry when the failed request
     was broad or unbounded.
   - Keep the existing restart rule at line 25 after the new bullet.

4. `source-3/project-documentation/tools/unresolved_README.txt`

   Location:

   - Current anchor: lines 293-297, the `Show verbose token file counts`
     section and command `python unresolved.py --verbose`.
   - Insert after line 297 and before line 299, `Configuration`.
   - Add: use `--verbose` only for debugging scanner behavior; normal agent
     work should inspect generated reports or file-scoped dry scans without
     verbose stdout.

## Second-Pass Accuracy Review

I rechecked the report against these current local sources:

- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/mcp-incident-playbook.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/tools/validator_README.txt`
- `source-3/project-documentation/tools/unresolved_README.txt`
- `source-3/project-documentation/tools/memory_ranges_README.md`
- `source-3/project-documentation/tools/int_convert_readme.md`
- `.ida_tools_list.json`

The findings above are accurate against those files. I found no material flaw
in the recommendations after the second pass.

The one caveat is that `.ida_tools_list.json` is a local schema snapshot, not a
live `tools/list` response from a currently running MCP server. The docs should
still require agents to run `tools/list` in the active session and treat that
response as authoritative for exact argument shapes.

These recommendations should not reduce output quality or change the overall
B-agent task. They only add guardrails so agents collect the same required
evidence with narrower, paged, schema-correct tool calls.
