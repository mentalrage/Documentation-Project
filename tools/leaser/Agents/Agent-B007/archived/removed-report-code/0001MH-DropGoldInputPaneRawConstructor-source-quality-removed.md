<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0001MH-DropGoldInputPaneRawConstructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001MH-DropGoldInputPaneRawConstructor-source-quality.md](0001MH-DropGoldInputPaneRawConstructor-source-quality.md)
- Source report SHA256 before cleanup: `CC35CA92A110681867D3D5F9244FC5547B5437D0740334F5B290437BF6DE2C19`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `371-373`
- Original language: `powershell`
- Block SHA256: `CA0F38DC8C99E3B5B2CE56CA22422182FF99E1142868CEE98A17508ECB01FD1A`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `377-383`
- Original language: `powershell`
- Block SHA256: `391EEFD5E3A7BCB7E24D31A52E5E7E60BE89EA9D33257A39A1699C34EE979BA9`

```powershell
python .\tools\validator.py --mode file --file by-class\DropGoldInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ItemActionInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x005b44b0-0x005b538a.DropGiveInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\DropInputPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\ItemActionInputPaneVtableFamily.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `443-445`
- Original language: `powershell`
- Block SHA256: `CA0F38DC8C99E3B5B2CE56CA22422182FF99E1142868CEE98A17508ECB01FD1A`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R004

- Original source lines: `483-485`
- Original language: `powershell`
- Block SHA256: `ECBFC6A6F6E2EDC73829AE799D000FE55589BA6BDA8D215777D3206ACF1B0B77`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md --uid-only --apply --no-generated-refresh --queue-timeout 240
```
