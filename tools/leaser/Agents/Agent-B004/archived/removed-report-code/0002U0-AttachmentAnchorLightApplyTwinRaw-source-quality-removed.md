<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md](0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md)
- Source report SHA256 before cleanup: `C0ACBF4B03E530B787F3E6CBDF3CC41DEFCBCAB9EA3878E275EB1CE4DE18936D`
- Cleanup generated: `2026-08-11T12:47:07Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `379-383`
- Original language: `powershell`
- Block SHA256: `21D7B9B743BCA96EF3B159C0598EB73529B731BDB65A654B2E3F8881234E965E`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\AttachmentAnchorResolver.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\AttachmentAnchorResolver.md --apply --queue-timeout 240
```
