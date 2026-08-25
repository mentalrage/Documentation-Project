<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0000FJ-UserFaceSelectControlPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000FJ-UserFaceSelectControlPane-source-quality.md](0000FJ-UserFaceSelectControlPane-source-quality.md)
- Source report SHA256 before cleanup: `0ED5CC203AA1513C7ED805C78BCA3DA0700E962383C18B20C623471972454073`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `378-387`
- Original language: `powershell`
- Block SHA256: `AC1015F5CA3238460019A08ACAEB72E08EB0B7CB80713FF63B63313DFE62735B`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-class/UserFaceSelectControlPane.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-file/UserCreateAppearanceControls.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-class/UserHairSelectControlPane.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-class/CreateUserDialogPane.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-class/-coverage-report.md --apply
```

## Removed Block R002

- Original source lines: `391-393`
- Original language: `powershell`
- Block SHA256: `A139456A64563C942BCC2788137A0C7BB7A4F62FC6D0D0554D6113E54871E80C`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-memory/-coverage-report.md --apply
```
