<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md](0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md)
- Source report SHA256 before cleanup: `4712A7D3231CFD5D0C516594BDA7491B4DE6018487B69656A2EAE3F2CEE15AD1`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `484-486`
- Original language: `powershell`
- Block SHA256: `71B675E42A4155229F85CC12F53E1A3BBD0EB4FCFED2013D91D82BAF3D6E64CC`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `500-505`
- Original language: `powershell`
- Block SHA256: `64C521738B7A599B1143932AB746F580E15D95D8350985EB4D1019DCEEED2C4A`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ButtonControlPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ButtonControlPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00494eb0-0x0049803a.ButtonChoiceControlCore.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `509-513`
- Original language: `powershell`
- Block SHA256: `4B31624D0F1230718FE013DD907C64988E9123A928B5DE2C527402BD441AFFF6`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\GrafPort.md --apply --queue-timeout 240
```
