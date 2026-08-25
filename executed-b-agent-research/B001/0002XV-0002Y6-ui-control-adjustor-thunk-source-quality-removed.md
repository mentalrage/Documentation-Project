<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002XV-0002Y6-ui-control-adjustor-thunk-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002XV-0002Y6-ui-control-adjustor-thunk-source-quality.md](0002XV-0002Y6-ui-control-adjustor-thunk-source-quality.md)
- Source report SHA256 before cleanup: `F1D968FBEF361E34699D62074DAB139361B77B82062AE5996CA127C37ADBA3A2`
- Cleanup generated: `2026-08-11T12:46:59Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `317-322`
- Original language: `powershell`
- Block SHA256: `D6287BD954BBEFFF3C914752BE254962A61C5BC4641AD1ADD2E24CE6B781A9FB`

```powershell
$body = @{jsonrpc='2.0'; id=1; method='tools/call'; params=@{name='lookup_funcs'; arguments=@{database='b002_00011G_scrollable_control_20260616'; queries=@('0x0049af11','0x0049af1c','0x0049af69','0x0049af74','0x0049af95','0x0049afa0','0x0049afab','0x0049afb6','0x0049b003','0x0049b00e','0x0049b05b','0x0049b066','0x0049b071','0x0049b07c')}}} | ConvertTo-Json -Depth 20
$body = @{jsonrpc='2.0'; id=1; method='tools/call'; params=@{name='disasm'; arguments=@{database='b002_00011G_scrollable_control_20260616'; addr='0x0049af11'; max_instructions=8; include_total=$true}}} | ConvertTo-Json -Depth 20
$body = @{jsonrpc='2.0'; id=1; method='tools/call'; params=@{name='xrefs_to'; arguments=@{database='b002_00011G_scrollable_control_20260616'; addrs=@('0x0049af11')}}} | ConvertTo-Json -Depth 20
$body = @{jsonrpc='2.0'; id=1; method='tools/call'; params=@{name='make_signature_for_range'; arguments=@{database='b002_00011G_scrollable_control_20260616'; start='0x0049af11'; end='0x0049af27'; wildcard_operands=$false}}} | ConvertTo-Json -Depth 20
```

## Removed Block R002

- Original source lines: `326-329`
- Original language: `powershell`
- Block SHA256: `847AA083406B3077B14F51B95953E6D84F0655D55C51BF6FEB9ED1B4BD468CDA`

```powershell
python .\tools\validator.py --mode file --file tools\leaser\Agents\Agent-B001\research\0002XV-0002Y6-ui-control-adjustor-thunk-source-quality.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0002XV-0002Y6-ui-control-adjustor-thunk-source-quality.md' --apply --lock-timeout -1
```
