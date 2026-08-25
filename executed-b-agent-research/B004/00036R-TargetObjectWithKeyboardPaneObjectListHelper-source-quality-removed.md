<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality.md](00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality.md)
- Source report SHA256 before cleanup: `D5BCC7D91A2F73CBB3760567AC35DB7AF8688A2810D68CF238FD1BE6A833426F`
- Cleanup generated: `2026-08-11T12:47:07Z`
- Removed executable blocks: `5`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `455-457`
- Original language: `powershell`
- Block SHA256: `EEE95C56BB718735AB4BCA2C7E3990A0DA14B09630522F4B93B6E5A1901E6111`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `461-463`
- Original language: `powershell`
- Block SHA256: `CCFAF3C921291B35CFAF06657B641CCA6F09EF112C868008360ED12705E594AF`

```powershell
python .\tools\validator.py --mode file --file by-class/TargetObjectWithKeyboardPane.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `467-469`
- Original language: `powershell`
- Block SHA256: `BCA5EFB489BD5E391B8478A28E34B3A3B908F4C0A9D381E06C1EB4CBFECE2A94`

```powershell
python .\tools\validator.py --mode file --file by-file/TargetSelectionInputPanes.md --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `473-475`
- Original language: `powershell`
- Block SHA256: `AC2F13BA28A6D83B7062A23BEBFC8F021A4E53E9092882F359F02A027A2CA59B`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md --apply --queue-timeout 240
```

## Removed Block R005

- Original source lines: `479-482`
- Original language: `powershell`
- Block SHA256: `AEAE878A09CA6F79D3991A4108D9F8B2ED34A7BC62794107546C3A2F7B496CB9`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/SelectObjectWithKeyboardPane.md --apply --queue-timeout 240
```
