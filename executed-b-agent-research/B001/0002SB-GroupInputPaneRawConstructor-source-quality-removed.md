<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002SB-GroupInputPaneRawConstructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002SB-GroupInputPaneRawConstructor-source-quality.md](0002SB-GroupInputPaneRawConstructor-source-quality.md)
- Source report SHA256 before cleanup: `9D5AA6FBF7D8C0F704D76DB434D6404895250C6C425FE70B37F34329E0D07162`
- Cleanup generated: `2026-08-11T12:46:59Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `346-351`
- Original language: `powershell`
- Block SHA256: `D6EA0E7715CB29BACF499403DD4D19E28EE9E675263A9E21A677C28C262D07FC`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\GroupInputPane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\CommandInputPanes.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-memory\0x005b5440-0x005b5547.GroupInputPane.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `355-357`
- Original language: `powershell`
- Block SHA256: `F6654AE2310ADEA8E21C7E02C4C81D887B44624935D3A4BBBDCFD7755F44C00F`

```powershell
python .\tools\validator.py execute_report B001 0002SB-GroupInputPaneRawConstructor-source-quality.md 0002SB --apply
```
