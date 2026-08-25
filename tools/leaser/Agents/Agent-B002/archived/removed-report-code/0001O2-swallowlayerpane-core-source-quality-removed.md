<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001O2-swallowlayerpane-core-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001O2-swallowlayerpane-core-source-quality.md](0001O2-swallowlayerpane-core-source-quality.md)
- Source report SHA256 before cleanup: `2380FB1AFEB3FD7F177A47D06EF3043E139AF08E2B10152D8B9024F27E35E286`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `237-260`
- Original language: `powershell`
- Block SHA256: `D6695291AD40CFB6FB0A6513670CFE394F9C0D12991B41B2211BDEDB0B82140D`

```powershell
# Existing-doc/support search
rg -n "005c29a0|5C29A0|0x005C29A0|0x005c29" source-3/project-documentation/by-memory source-3/project-documentation/by-class source-3/project-documentation/by-file source-3/project-documentation/tools/leaser/Agents -g "*.md"
rg -n "0001O2|SwallowLayerPaneCore|0001O3|SwallowLayerPaneRawFlightHelpers" source-3/project-documentation/by-memory/-coverage-report.md source-3/project-documentation/auto-generated/-ag-memory-coverage.md source-3/project-documentation/auto-generated/-ag-class-coverage.md source-3/project-documentation/tools/leaser/Agents/Agent-B002/notes.md

# IDA MCP calls used through tools/call on http://127.0.0.1:13337/mcp
idb_list
server_health(database="b003_00018a_ime_comp_20260617")
lookup_funcs(database="b003_00018a_ime_comp_20260617", queries=["0x005c2230","0x005c2340","0x005c2360","0x005c2430","0x005c2500","0x005c26b0","0x005c2760","0x005c2840","0x005c2930","0x005c299f","0x005c29a0","0x005c29ec","0x005c2a02","0x005c2a60"])
xrefs_to(database="b003_00018a_ime_comp_20260617", addrs=["0x005c2760","0x005c2840","0x005c2930","0x005c29a0","0x005c2a60","0x00631340","0x00631394","0x006313c4","0x006313cc","0x006313e4"])
analyze_function(database="b003_00018a_ime_comp_20260617", addr="0x005c2230")
analyze_function(database="b003_00018a_ime_comp_20260617", addr="0x005c2500")
analyze_function(database="b003_00018a_ime_comp_20260617", addr="0x005c2930")
disasm(database="b003_00018a_ime_comp_20260617", addr="0x005c2760", max_instructions=180)
disasm(database="b003_00018a_ime_comp_20260617", addr="0x005c29a0", max_instructions=90)

# After supervisor-owned doc edits
cd E:\NTK\GhidraBridge\source-3\project-documentation\tools
python validator.py --mode file --file ..\by-memory\0x005c2230-0x005c299f.SwallowLayerPaneCore.md --apply
python validator.py --mode file --file ..\by-class\SwallowLayerPane.md --apply
python validator.py --mode file --file ..\by-file\SwallowLayerPane.md --apply
python memory_ranges.py report --dry-run
python validator.py --mode autogen --apply
```
