<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B012\00019N-MainMenuHitTest-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00019N-MainMenuHitTest-source-quality.md](00019N-MainMenuHitTest-source-quality.md)
- Source report SHA256 before cleanup: `385D10F97A1DA11020AD2F2B51CBEC6F55C83E21FFB795FEB938DF5E1963541E`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `322-324`
- Original language: `powershell`
- Block SHA256: `EFDC56903DCC46F0D40A70D77C7C88ADC3367C8B4E2996DE33112CA2A2D6A432`

```powershell
python tools/validator.py --mode file --file by-memory\0x004f8c10-0x004f8cfa.MainMenuHitTest.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `328-334`
- Original language: `powershell`
- Block SHA256: `B31C141DC6F0A5AAA7AE9D7BD3906450C99629D377EB53817054B8D99897D607`

```powershell
python tools/validator.py --mode file --file by-global\HitTestMenuItem_4F8C10.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory\0x004f8b90-0x004f8c07.ComputeMenuItemRect.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-global\ComputeMenuItemRect_4F8B90.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-class\MainMenuPane.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-file\MainMenuPane.md --apply --queue-timeout 240
```
