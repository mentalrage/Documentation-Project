<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\000099-NewSayToUserMessageInputPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000099-NewSayToUserMessageInputPane-source-quality.md](000099-NewSayToUserMessageInputPane-source-quality.md)
- Source report SHA256 before cleanup: `8D57A20D648C622CEF38B7178717F72F76D91B321451C87C9D5F27F7BB7CA8D0`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `280-285`
- Original language: `powershell`
- Block SHA256: `B0C497002FC7B1B50FC613C07AAA65F44A84AEDDDE37FE753A4AF4365466D429`

```powershell
cd source-3/project-documentation
python .\tools\validator.py --mode file --file .\by-class\NewSayToUserMessageInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\SayInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
