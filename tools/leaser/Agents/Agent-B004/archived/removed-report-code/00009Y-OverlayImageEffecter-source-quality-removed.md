<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\00009Y-OverlayImageEffecter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00009Y-OverlayImageEffecter-source-quality.md](00009Y-OverlayImageEffecter-source-quality.md)
- Source report SHA256 before cleanup: `4C849EA1C56A48099C949DB75A1CA6463D2BF3EA09AAA9A12A84864630A8DA25`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `365-372`
- Original language: `powershell`
- Block SHA256: `20A15DEDF87F63B46FF5C3A4740A2C194CD87388A0C3CCBCAF64E99146F8B968`

```powershell
python .\tools\validator.py --mode file --file .\by-class\OverlayImageEffecter.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\Effects.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-vtable\ScreenEffecterVtableFamily.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x006235a0-0x00623d18.ScreenEffecterVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00623480-0x00623d58.ScreenEffecterReadOnlyData.md --apply --queue-timeout 240
```
