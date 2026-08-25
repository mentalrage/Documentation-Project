<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality.md](0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality.md)
- Source report SHA256 before cleanup: `5D40DD53AE2B57D9E61F939A1C86B3B2FDF944D2FE3D68B1F9D63314EE664D07`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `610-618`
- Original language: `powershell`
- Block SHA256: `0871FDFCB05FF7F6FD19AF4EAE35ADAE514CFEE1D97AEC3764957C4BA7332D51`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00561b00-0x00561bc0.ScrollNewGroupPaneUpdateActiveInteraction.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00561bc0-0x00561d4d.ScrollNewGroupPaneUpdateScrollPositionFromCursor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00561d50-0x00561dac.ScrollNewGroupPaneResetInteractionStateRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ScrollNewGroupPane.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `622-624`
- Original language: `powershell`
- Block SHA256: `1EA74242E5D467732F2C4215E80BA49D838B61FDA09D92B76D97187BBD853CE6`

```powershell
python .\tools\validator.py --mode file --file by-file\Group.md --apply --queue-timeout 240
```
