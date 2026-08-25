<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\00005A-FolderTreePane-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00005A-FolderTreePane-class-source-quality.md](00005A-FolderTreePane-class-source-quality.md)
- Source report SHA256 before cleanup: `DDB1D9AC77B232B270A9A971176B660C67F638DEDC7387CEAE7C9BF84FD85129`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `75-77`
- Original language: `powershell`
- Block SHA256: `D06AEFA87A2315E51FCF53C9CF27A8BC1EDA910BA8134AF2395166744B9AE7AA`

```powershell
python .\tools\validator.py --mode file --file by-class\FolderTreePane.md --queue-timeout 240
```

## Removed Block R002

- Original source lines: `580-590`
- Original language: `powershell`
- Block SHA256: `187C3106EB4FD51704C5DF4C936696676E27B59814D02BE6E41C255091096851`

```powershell
python .\tools\validator.py --mode file --file by-class\FolderTreePane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\FolderTreePane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b1b90-0x004b32c9.FolderTreePaneCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\FolderTreePane__TreeElem.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-template\FolderTreePaneTreeTemplates.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\Tree_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\TreeItor_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\TreeStorage_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `608-610`
- Original language: `powershell`
- Block SHA256: `D06AEFA87A2315E51FCF53C9CF27A8BC1EDA910BA8134AF2395166744B9AE7AA`

```powershell
python .\tools\validator.py --mode file --file by-class\FolderTreePane.md --queue-timeout 240
```
