# Agent-B011 Notes

## Paused UID0000ZL Checkpoint - 2026-07-05

Assignment: xHigh report-only research for `0000ZL`, target `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`, report path `tools/leaser/Agents/Agent-B011/research/0000ZL-NewPredefinedFormArticleDialog-source-quality.md`.

Supervisor/user constraints in force: use `ntk-b-agent-workflow`; report-only; do not edit target/support by-* docs; do not run `execute_report`, dry-run/probing variants, registry lifecycle commands, generated report edits, manual coverage-report edits, or manual report moves; use schema-current narrow IDA MCP calls; pause rather than produce fallback-only research when MCP is unavailable.

Read before pause:
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`.
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`.
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md`.
- `.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md`.
- `.codex/skills/ntk-b-agent-workflow/references/mcp-incident-playbook.md`.
- `goal.md`, `by-structure.md` IDA MCP/scoring/C++ gate sections, and `by-memory/-guidance.md`.
- Target aggregate `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`.

Local evidence checkpoint:
- Target aggregate is currently `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000LT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LT`, blank formal aggregate C++.
- The target page currently keeps aggregate C++ blank despite clearing the minimum code-entry gate because constructor branch/control field names, broader helper/base interfaces, broader alert/helper source visibility, and retained-helper `0x00478aa0` emission policy remain unresolved.
- Child inventory in the target page records resolved source-ready children for `0002EK`, `0002UK`, `0002UM`, `0002UO`, `0002UP`, `0002UQ`, and `0002UL`; `0002UJ` constructor is source-owned but intentionally non-emitting after B005; `0002UR` `0x00478aa0` remains the retained unreferenced helper with no-route caveat; B012 is separately assigned to `0002UN`, so keep any resumed work focused on aggregate/source-placement/final-C++ and support-doc implications.
- Required archived-report search was started with terms including `0000ZL`, `0x004777a0`, `0x00478f8e`, `NewPredefinedFormArticleDialog`, `0002UN`, `0x004777a0-0x004781e5`, `0x00478aa0`, `BoardDialogs`, `DeserializePredefinedFormArticle`, and `PredefinedFormArticle`. Exact matching report leads include B002 `0002EK`, B002 `0002UK`, B005 `0002UJ`/`0002UM`/`0002UO`, B006 `0002UQ`, B014 `0002UP`/`0002UL`, B001 `0002UR`, B011 `0000ZQ`, B012 `0000ZS`, B009 `0000HT`, B001 `0000ZK`, B013 `00030H`, and B011 `0004G6`. These were not fully opened or incorporated before the MCP pause.

MCP checkpoint:
- `initialize` succeeded against `http://127.0.0.1:13337/mcp`; `tools/list` succeeded and showed schema requiring a `database` argument for `server_health`, `lookup_funcs`, and related tools.
- First `idb_list` returned one worker session `b006-0000xu`, input `E:\Desktop\Clone\NexusTK\NexusTK.exe`, `is_analyzing:false`, worker pid `12536`, `is_active:false`.
- Immediate narrow calls `server_health`, `lookup_funcs`, and `analyze_component` with `database=b006-0000xu` all failed with `Session not found: b006-0000xu`.
- A raw retry of `idb_list` then returned `sessions:[]`, `count:0`; raw `server_health` still returned `Session not found: b006-0000xu`.
- Incident read-only checks at `2026-07-05T03:28:15.2923291-04:00`: TCP listener existed on `127.0.0.1:13337` owned by pid `6640`; processes included `idalib-mcp.exe` pid `21212` and Python wrappers pids `21344` and `6640` with command line `idalib-mcp.exe --host 127.0.0.1 --port 13337 E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; final `idb_list` after a 5-second wait still returned `sessions:[]`, `count:0`.
- Failed calls were not broad/unbounded in the sense of output discipline: they were availability/session probes plus exact-address `lookup_funcs` and bounded `analyze_component` over the aggregate child starts. No `idb_open`, restart, kill, lifecycle, validator, or report execution command was run.

Paused state:
- No final report was created.
- No by-* docs, generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers were edited.
- Only this B011-owned notes file was updated with the paused MCP checkpoint.
- Resume by rechecking MCP with `initialize` -> `tools/list` -> `idb_list`/`server_health`; if a valid IDB session is available, redo the MCP-backed evidence pass before drafting the report.

## Paused UID0002PF Checkpoint - 2026-07-04

Assignment: Medium report-only research for `0002PF`, target `by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md`, report path `tools/leaser/Agents/Agent-B011/research/0002PF-SoftwareRenderCompatPixelCallback-source-quality.md`.

Supervisor pause received before final report drafting. Do not continue MCP calls, finalize the report, edit by-* docs, run validators, or execute lifecycle/archive commands until explicitly resumed. Keep Medium provenance when the report is later completed.

Read before pause:
- `goal.md`.
- Project skill `ntk-b-agent-workflow/SKILL.md`.
- `references/b-agent-research-and-implementation-workflow.md`.
- `references/b-agent-report-template.md`.
- `references/score-blocker-audit-standard.md`.
- Target doc and related Surface/render callback docs/generated leads.

Local evidence checked before pause:
- Target currently `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank formal C++.
- Existing target doc says Surface-owned compat/RGB555 pixel write/blend callback selected through `dword_69B3E0`, generated empty marker caused by blank formal C++.
- `by-file/Surface.md`, `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`, `by-global/SurfaceRenderCallbackTable.md`, and `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` align on Surface/render-dispatch ownership and RankingEventListPane as callsite-biased generated pollution.
- `auto-generated/NexusTK/render/Surface.cpp` currently has a UID0002PF empty emitter marker.

MCP checkpoint before pause:
- Supervisor-restored active session from `idb_list`: `73c77998`, `NexusTK.exe.i64`, active, `is_analyzing:false`, worker pid `12416`.
- `server_health` with `database=73c77998`: `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, image base `0x400000`.
- `lookup_funcs` using current schema `queries`: `0x004bb8d0` is `sub_4BB8D0` size `0xd5`; `0x004bb9a5` is not a function; `0x004bb9b0` is `sub_4BB9B0` size `0x6da`; `0x00558b80` is inside `sub_558840` size `0x723`.
- `xrefs_to`: target `0x004bb8d0` has two data xrefs at `0x00558745` and `0x00558b80`; no xrefs to end `0x004bb9a5`; slot `0x0069b3e0` has 15 refs including initializer refs and later weather/render consumers.
- Current MCP tool list did not include a `callers` tool despite older docs; `func_profile` for `0x004bb8d0` reported `caller_count:0`, `callee_count:7`, prototype `void __thiscall(int this, int, int, unsigned int)`.
- `callees` for `0x004bb8d0`: `0x004b96c0`, `0x004b7e80`, `0x00543d40`, `0x00542ac0`, `0x005c772f` security cookie, `0x004c0710`.
- `get_bytes` at `0x004bb9a0` showed the function tail `... 5d c2 0c 00` followed by `0xcc` padding until next prologue at `0x004bb9b0`; start bytes at `0x004bb8d0` show normal prologue/security-cookie setup.
- `decompile 0x004bb8d0` confirms draw-enabled byte `this+113`, clip rect via `0x004b96c0`, point-in-rect via `0x004b7e80`, palette/color resolve through `dword_67A7E0`, `0x00543d40`, `0x00542ac0`, mode byte `this+112`, direct/transparent/blend/transparent-blend paths, destination formula using fields `+32/+40/+44/+48`, and RGB555 blend helper `0x004c0710` with alpha `0x10`.
- `xref_query` attempts with `op_any` were made but failed with `addr is required`; if resumed, use the current schema correctly or rely on `func_profile`/`xrefs_to` for no-ordinary-caller proof.

No report was finalized. No by-* docs, generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers were edited during this pause checkpoint.
