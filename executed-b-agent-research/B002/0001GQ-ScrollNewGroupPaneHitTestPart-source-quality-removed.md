<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001GQ-ScrollNewGroupPaneHitTestPart-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001GQ-ScrollNewGroupPaneHitTestPart-source-quality.md](0001GQ-ScrollNewGroupPaneHitTestPart-source-quality.md)
- Source report SHA256 before cleanup: `18A9CCBE13D4958D060F958968C0FE886A50CE0C28E959E7A0D045C6BD168DB3`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `371-373`
- Original language: `powershell`
- Block SHA256: `E3E2B7A82611471C480FBADDD343B77535052ACAB021AEFFCEEFA0E5BE2B7B98`

```powershell
python .\tools\validator.py execute_report B002 0001GQ-ScrollNewGroupPaneHitTestPart-source-quality.md 0001GQ --apply
```

## Removed Block R002

- Original source lines: `377-380`
- Original language: `powershell`
- Block SHA256: `FE3435DAAEF2DD9372ED15613A2AE85240F4A5B4C4931DE2C110EBC55BDD287C`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ScrollNewGroupPane.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `384-386`
- Original language: `powershell`
- Block SHA256: `1EA74242E5D467732F2C4215E80BA49D838B61FDA09D92B76D97187BBD853CE6`

```powershell
python .\tools\validator.py --mode file --file by-file\Group.md --apply --queue-timeout 240
```
