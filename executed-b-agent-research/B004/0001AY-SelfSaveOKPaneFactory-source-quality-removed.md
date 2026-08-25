<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0001AY-SelfSaveOKPaneFactory-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001AY-SelfSaveOKPaneFactory-source-quality.md](0001AY-SelfSaveOKPaneFactory-source-quality.md)
- Source report SHA256 before cleanup: `C34E9E187FEBD6015BAB8F0182BAF5EABB522CD1E68859D9FEAD7584E2B4AA3D`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `537-539`
- Original language: `powershell`
- Block SHA256: `6EEB683C12488B565049EB567D8E69B0B55A1B194AAD19DFFE8A173A7C1F0BF6`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00513800-0x00513920.SelfSaveOKPaneFactory.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `543-548`
- Original language: `powershell`
- Block SHA256: `3804F68794C4F62E1427BB7B5125B62D6D6CC139100E6D4E7B7A38CE9C8C550A`

```powershell
python .\tools\validator.py --mode file --file by-file\SelfSaveOKPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\SelfSaveOKPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005147d0-0x00514914.SelfSaveOKPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0050e4c0-0x00514920.MapPanePacketHandlers.md --apply --queue-timeout 240
```
