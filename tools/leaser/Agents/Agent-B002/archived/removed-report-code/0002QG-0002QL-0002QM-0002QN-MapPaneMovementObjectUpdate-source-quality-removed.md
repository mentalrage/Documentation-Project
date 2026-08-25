<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality.md](0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality.md)
- Source report SHA256 before cleanup: `7D449915FB90A58EE8899CD2AFD9731EF98F2B839A6B417C29EC4740B1B4867E`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `609-619`
- Original language: `powershell`
- Block SHA256: `A5E1FFC0E73DC397EEBE5EDDFEE5E090DDE2CD6C3E9858DE563055AAA8FAC01F`

```powershell
Set-Location 'E:\NTK\GhidraBridge\source-3\project-documentation'
python .\tools\validator.py --target by-memory\0x005046d0-0x005047e8.MapPaneQueuedMotionMessage.md
python .\tools\validator.py --target by-memory\0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md
python .\tools\validator.py --target by-memory\0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md
python .\tools\validator.py --target by-memory\0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md
python .\tools\validator.py --target by-class\MapPane.md
python .\tools\validator.py --target by-class\ObjectStatusBlob.md
python .\tools\validator.py --target by-type\by-enum\MapServerPacketOpcode.md
python .\tools\validate_generated_coverage.py
```
