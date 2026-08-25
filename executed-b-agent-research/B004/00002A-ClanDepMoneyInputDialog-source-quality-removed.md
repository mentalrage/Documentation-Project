<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\00002A-ClanDepMoneyInputDialog-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00002A-ClanDepMoneyInputDialog-source-quality.md](00002A-ClanDepMoneyInputDialog-source-quality.md)
- Source report SHA256 before cleanup: `E3987625BA3C7177B60EA0C1A2185CA02CADCCD17670B0E8340A66DF59D10F44`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `342-345`
- Original language: `powershell`
- Block SHA256: `3FFF030D06BF7B793C94BB8A099B1BCC376DEA56040F85CB1C08C33B458618EB`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file .\by-class\ClanDepMoneyInputDialog.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `349-356`
- Original language: `powershell`
- Block SHA256: `F208CA2276F3766B536FA597163A7DAFAF58BEB79B95AA5FC8275EEC073D2D3B`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\Clan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\ClanDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\ClanInputDialogLayouts.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-vtable\ClanModalDialogVtables.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `360-362`
- Original language: `powershell`
- Block SHA256: `726F8E3D2ED2DD1596CCEE1959EBEB2DDCC252197072F85D0058A6671D66BF77`

```powershell
python .\tools\validator.py --mode file --file .\by-class\-coverage-report.md --apply --queue-timeout 240
```
