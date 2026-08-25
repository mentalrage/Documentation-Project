<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md](000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md)
- Source report SHA256 before cleanup: `C9C691CD6937CFEF96301853F2802CFF7857A8690927BCDAF360B37492F73908`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `291-299`
- Original language: `powershell`
- Block SHA256: `C02FDD046F93654393D2565CF31ABD6A8BCBB08DC07FF816EAB86393E7841038`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/MapPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type/by-struct/EffectInfo.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md --apply --queue-timeout 240
```
