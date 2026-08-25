<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\0001KF-UrlAlertPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001KF-UrlAlertPane-source-quality.md](0001KF-UrlAlertPane-source-quality.md)
- Source report SHA256 before cleanup: `1FAA2E34DBB35B7F3FCBB81DF09F40EC08CA1B7EB4B72B6048F3F0307DFF221C`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `576-585`
- Original language: `powershell`
- Block SHA256: `19C767309337794C9C22215B8CE20993D6E82861F421F3667E56D70519345D52`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x00599a40-0x00599cb3.UrlAlertPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\UrlAlertPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\AlertPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-global\g_pUrlAlertPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\AlertPaneLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-vtable\UrlAlertPaneVtables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0062e580-0x0062e624.UrlAlertPaneVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `589-591`
- Original language: `powershell`
- Block SHA256: `EDBAAF6E1143005DA085ABE613272DF1C35A91FA9DE1C71B9DD2A2893045AD3F`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `595-598`
- Original language: `powershell`
- Block SHA256: `38E81440079A8EAD0CD0E9F967B938774EBB305DD06F578F8379C312AECB999A`

```powershell
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
python .\tools\validator.py --mode rescore --apply --queue-timeout 240
```
