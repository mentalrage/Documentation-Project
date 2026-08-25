<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002JW-ApplicationReadProcessorName-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002JW-ApplicationReadProcessorName-source-quality.md](0002JW-ApplicationReadProcessorName-source-quality.md)
- Source report SHA256 before cleanup: `64122E19F25BF99ADE30C49500D4F6522A3170DFED80EAE33E886990FE26F9FE`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `238-243`
- Original language: `powershell`
- Block SHA256: `7AEECEBCC39349BF3344D4E00F0937C442177A9EE996109E3214A22C7158778E`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class/Application.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/Application.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `247-249`
- Original language: `powershell`
- Block SHA256: `6C29E02CCA09DA2FF24AB71DF72A0172D06F33D6D8EB8FF0C942FFD6FED8B543`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00463310-0x0046396e.ApplicationConstructor.md --apply --queue-timeout 240
```
