<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\00010T-ClanDestructorBand-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00010T-ClanDestructorBand-source-routing.md](00010T-ClanDestructorBand-source-routing.md)
- Source report SHA256 before cleanup: `D7BAD5D84D330040C3625FD6A4742368F57CADCBDCEB77F8D2BF24AAFB348977`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `319-334`
- Original language: `powershell`
- Block SHA256: `9855B4C1002D276769A9F7A06189F214CA784F146D78F66FB77E6288EB6D6EFE`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0048c260-0x0048c63f.ClanDestructorBand.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0048c27b-0x0048c291.DialogPaneAdjustorThunks.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\DialogPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ClanAttrInputDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ClanBankItemListPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ClanBankPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ClanItemDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ClanItemListPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ClanStatusPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\TextEditPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\Clan.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ClanBank.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\ClanDialogVtableFamily.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `338-340`
- Original language: `powershell`
- Block SHA256: `DE5227A1107DC55C84EB00517AB3282A3799A2C661B2059082F319BAFA468D95`

```powershell
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `344-346`
- Original language: `powershell`
- Block SHA256: `80AA9C6C3DDE137200FAC407C3C7D2314D311D995236E431A8B26BE9C56934AC`

```powershell
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
```
