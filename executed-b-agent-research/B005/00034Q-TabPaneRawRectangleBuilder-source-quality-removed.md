<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\00034Q-TabPaneRawRectangleBuilder-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00034Q-TabPaneRawRectangleBuilder-source-quality.md](00034Q-TabPaneRawRectangleBuilder-source-quality.md)
- Source report SHA256 before cleanup: `73C73CFD213F35F8A5F70A00E29DB57938EEA3B6F189CA14332810E4D2184C8F`
- Cleanup generated: `2026-08-11T12:47:09Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `518-524`
- Original language: `powershell`
- Block SHA256: `5A3D76625A15D55AF76A034918C29C12CCACC58CCD473622FCB217D48A83F155`

```powershell
python tools/validator.py --mode file --file by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-class/TabPane.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-file/TabPane.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `528-530`
- Original language: `powershell`
- Block SHA256: `E9C63887B5083678A1A0001A700775D35BFE40DE90E0B90C64A1002B8BBCF8B1`

```powershell
python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240
```
