<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00018B-ime-candidate-show-candidate-list-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00018B-ime-candidate-show-candidate-list-source-quality.md](00018B-ime-candidate-show-candidate-list-source-quality.md)
- Source report SHA256 before cleanup: `861A217B10FC0FB0CCFCC6B170F4A5EC8F0F782B9A9631C19576972DCD4AA1FF`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `418-428`
- Original language: `powershell`
- Block SHA256: `8FF6E88E166AFE36CA913CA3C4CCF5DBAC9C14D12BA59F67326DA6845121D3D3`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation

python .\tools\validator.py --mode file --file .\by-memory\0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\IMECandidatePane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\IMEPanes.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode autogen --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
```

## Removed Block R002

- Original source lines: `432-437`
- Original language: `powershell`
- Block SHA256: `DC29D31F29840B4A9C1E26B1A2B138A40F93C27569013807F9F3B828A9503F09`

```powershell
python .\tools\validator.py --mode file --file .\by-file\InputMan.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x004e8af0-0x004e970d.InputMan.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\Event.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md --apply --queue-timeout 240 --lock-timeout -1
```
