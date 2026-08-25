<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0001AX-MapPaneDayNightPacketRawBody-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001AX-MapPaneDayNightPacketRawBody-source-quality.md](0001AX-MapPaneDayNightPacketRawBody-source-quality.md)
- Source report SHA256 before cleanup: `66ECDEE062F22A7AECB8D1DD725AB0CF7FF68B5E93959986D534BFE2F01ED234`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `649-656`
- Original language: `powershell`
- Block SHA256: `26103DF6E238BA4FD60C0E0128DB12CAF4958FD8B07A823DE56ED7B051F80014`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\int_convert.py 0x18
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\int_convert.py 0x3c
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\int_convert.py 0xe10
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\int_convert.py 0x20
rg -n "0001AX|0x00510400-0x005104c7|MapPaneDayNightPacketRawBody" E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-auto-completion-stats.md
rg -n "HandleWeatherPacket|s_dayNightBrightnessByHour|m_dayNightHour|SetDayNightFadeTarget|0x00510400" E:\NTK\GhidraBridge\source-3\project-documentation\by-file\MapPane.md E:\NTK\GhidraBridge\source-3\project-documentation\by-class\MapPane.md E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md
```

## Removed Block R002

- Original source lines: `660-668`
- Original language: `powershell`
- Block SHA256: `867668C424064058A43623A7AEB5451C04E7A352100AC9E933AEA72D318A8FAC`

```powershell
@'
import struct, hashlib
from pathlib import Path
exe = Path(r"E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe")
data = exe.read_bytes()
print(hashlib.sha256(data).hexdigest())
'@ | python -
```
