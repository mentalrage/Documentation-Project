<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0000YZ-BalloonObjectPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000YZ-BalloonObjectPane-source-quality.md](0000YZ-BalloonObjectPane-source-quality.md)
- Source report SHA256 before cleanup: `7BCCDA1A1ABD618D4823709DB3C64FB9888B5741F46225FD0EA3448E3196CDD8`
- Cleanup generated: `2026-08-11T12:47:08Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `116-118`
- Original language: `text`
- Block SHA256: `C88A4E993699EFB4EC55E2AFE5D4B5A0B91F8A2D4D02018DFD98EEDBFEE4C958`

```text
python .\tools\validator.py --mode file --file by-memory\0x00467b30-0x0046904e.BalloonObjectPane.md --queue-timeout 240
```

## Removed Block R002

- Original source lines: `501-512`
- Original language: `powershell`
- Block SHA256: `4344CAE0E22BB18D89B91EE15F7D38053D69FA4F9DC50579108CE038FD0F46C0`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00467b30-0x0046904e.BalloonObjectPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\BalloonObjectPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\AttachedObjectPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode autogen --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
```
