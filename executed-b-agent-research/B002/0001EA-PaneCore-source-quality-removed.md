<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001EA-PaneCore-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001EA-PaneCore-source-quality.md](0001EA-PaneCore-source-quality.md)
- Source report SHA256 before cleanup: `E23C2908FD0FA292EF1BE929FBB46C0877131636D2AEDC1A8CB3B3DAC326CB4F`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `375-383`
- Original language: `powershell`
- Block SHA256: `27A8C122B34B14A37922067D6387CA2F1FE5DF7176B57467651C169CF9338516`

```powershell
rg -n "0001EA|0x00544460-0x00545086|PaneCore|0002V7|0001EB" source-3/project-documentation/by-memory/-coverage-report.md
rg -n "004b8d20|0x004b8d20|00544580|0x00544580|Pane::~Pane|GrafPort" source-3/project-documentation/by-memory source-3/project-documentation/by-class source-3/project-documentation/by-file source-3/project-documentation/by-type
rg -n "00544e90|0x00544e90|default event-update|tertiary" source-3/project-documentation/by-memory source-3/project-documentation/by-type
Get-Content -Raw source-3/project-documentation/by-memory/0x00544460-0x00545086.PaneCore.md
Get-Content -Raw source-3/project-documentation/by-type/by-struct/PaneLayout.md
Get-Content -Raw source-3/project-documentation/by-type/by-vtable/PaneVtables.md
Get-Content -Raw source-3/project-documentation/auto-generated/NexusTK/ui/core/Pane.cpp
```

## Removed Block R002

- Original source lines: `387-393`
- Original language: `powershell`
- Block SHA256: `65E61F8487D9E8206B205FA8EA6AD36BC45BAA3B27D6A0DF97B4FBC74B8D0B63`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00544460-0x00545086.PaneCore.md --apply --queue-timeout 240
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-class\Pane.md --apply --queue-timeout 240
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-file\Pane.md --apply --queue-timeout 240
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-struct\PaneLayout.md --apply --queue-timeout 240
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-vtable\PaneVtables.md --apply --queue-timeout 240
```
