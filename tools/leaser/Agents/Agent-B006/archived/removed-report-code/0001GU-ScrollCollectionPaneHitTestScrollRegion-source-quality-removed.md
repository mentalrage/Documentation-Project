<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality.md](0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality.md)
- Source report SHA256 before cleanup: `90EC77C9B954B235F4EF5CE68A4536B1A09FDD0DBC6A8D46D8C634ACC4CF7E1D`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `412-414`
- Original language: `powershell`
- Block SHA256: `FC4925DD57A292B4B8182505C798E4D8E3B93AEDB061AE928AC2E8102A2CB9BC`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
```

## Removed Block R002

- Original source lines: `418-424`
- Original language: `powershell`
- Block SHA256: `7E33954342D06C703787DF71B29A3968CF1FA4C97B2D1F24AB6AD2D03B45EBF4`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ScrollCollectionPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ScrollCollectionPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00561db0-0x0056325c.ScrollCollectionPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\ScrollCollectionPaneLayout.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `428-430`
- Original language: `powershell`
- Block SHA256: `72D53EB17394FEC28BA363A5B6F17D4C9B4F36B98DD1AD618F085DF6E355A124`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md --apply --queue-timeout 240
```
