<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B015\0003H4-LivingObjectPaneSendDirectionPacketRawHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003H4-LivingObjectPaneSendDirectionPacketRawHelper-source-quality.md](0003H4-LivingObjectPaneSendDirectionPacketRawHelper-source-quality.md)
- Source report SHA256 before cleanup: `217A8856CE05B9697E3108307D75A7645E4CE8AC6F1F435625081DC08DB5E8C5`
- Cleanup generated: `2026-08-11T12:47:19Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `581-590`
- Original language: `powershell`
- Block SHA256: `1F03439972A999F9042021406D25ABD6489DA02881F1151A983F9D69E923A791`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/LivingObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/LivingObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005acc30-0x005acd85.LivingObjectPaneSendActionPacketWithAutoFace.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `594-596`
- Original language: `powershell`
- Block SHA256: `E1E0EABBDCBC70DF5931C9EDBBB4103CDCBFD6EC80121A6F0C88F7F1591A6119`

```powershell
python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240
```
