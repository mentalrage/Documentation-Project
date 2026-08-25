<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B012\0001KQ-SelfSaveInputPaneFactory-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001KQ-SelfSaveInputPaneFactory-source-quality.md](0001KQ-SelfSaveInputPaneFactory-source-quality.md)
- Source report SHA256 before cleanup: `D9498E941C4459D25DDA53827655AF243114BD74947B2B232C54550424333C56`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `431-439`
- Original language: `powershell`
- Block SHA256: `593A01E62A88B5E1B39AB87A22788ECD29D533C6E8883036C409E918C7C40FE5`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-memory\0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-file\SelfSaveInputPane.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-class\SelfSaveInputPane.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-file\CommandInputPanes.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-memory\0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-memory\0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-memory\0x005b6870-0x005b68b0.SelfSaveInputPaneSendSelfSavePacketRaw.md --apply
```

## Removed Block R002

- Original source lines: `443-446`
- Original language: `powershell`
- Block SHA256: `638500EAC3019E8B858983827D6F53A7BD5F126D2F41AE838C54ACC9EF7F89FE`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-resource\str-res-localized-strings.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file by-global\g_pLanguageMan.md --apply
```

## Removed Block R003

- Original source lines: `450-452`
- Original language: `powershell`
- Block SHA256: `33EF4324EE2ACBD01BF88E27101D8387D97F414AFD2D75DCE96B4EBED868A455`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-memory\-coverage-report.md --apply
```
