<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00011K-target-option-edit-control-pane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00011K-target-option-edit-control-pane-source-quality.md](00011K-target-option-edit-control-pane-source-quality.md)
- Source report SHA256 before cleanup: `47DF9E0FF69337C25BDB88FF508367EAD09C42A9E729F47044ABE7A7D76AED7E`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `420-429`
- Original language: `powershell`
- Block SHA256: `8163E6D0884BD290C06D3697D91214DFA483C381328DADFE5145E90116272A73`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004993b0-0x0049980c.TargetOptionEditControlPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\TargetOptionEditControlPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x00542270-0x0054259f.TargetOptionDialog.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\TargetOptionDialog.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1
python .\tools\memory_ranges.py report
python .\tools\validator.py --mode rescore --apply --lock-timeout -1
```
