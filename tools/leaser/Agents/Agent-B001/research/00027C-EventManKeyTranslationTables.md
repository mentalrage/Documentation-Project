# 00027C EventManKeyTranslationTables Ownership / Split Research

## Active Checkpoint - 2026-06-11 02:56:29 -04:00

- Assignment: B001-041, UID `00027C`, `by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md`.
- Scope: audit whether the two `0x100` key translation tables are a coherent source-bearing child or require split children, then repair the true direct parent gate if IDA/documentation evidence justifies it.
- Lease state read: `Agent-B001/current_leases.md` reported no active leases at the start of this run.
- Files read so far: `Agent-B001/goal.md`, `Agent-B001/inference_research.md`, `by-structure.md`, target page `00027C`, generated memory coverage row, manual memory coverage row, and supervisor row for `00027C`.
- Current hypothesis: the memory range is probably a coherent EventMan-owned table pair rather than a mixed split, but the assignment hinges on repairing the direct EventMan/Event parent gate before assigning the child.
- IDA MCP status: not checked yet in this run. Next live checks are `tools/list`, target bytes at `0x0066d888`, `0x0066d988`, successor `0x0066da88`, xrefs to both table starts, and the constructor/function context around `0x004a8b40`.
- Next steps: read `EventMan` class/file/memory parent docs, candidate Event docs, nearby predecessor/successor pages, then run focused IDA MCP calls and decide whether shared docs need leased edits.
