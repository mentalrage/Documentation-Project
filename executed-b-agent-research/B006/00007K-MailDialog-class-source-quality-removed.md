<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\00007K-MailDialog-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00007K-MailDialog-class-source-quality.md](00007K-MailDialog-class-source-quality.md)
- Source report SHA256 before cleanup: `1658AAA88EB36B3543B3339A54FE81BAACF9DA8F957880EA91199CBAC07E8FCC`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `342-344`
- Original language: `powershell`
- Block SHA256: `49BC55CA1F1A161DA0BFFDB8EE64BCCD1AB4F8B16719BCB589C5405D8BB1D0B6`

```powershell
python .\tools\validator.py --mode file --file .\by-class\MailDialog.md --queue-timeout 240
```

## Removed Block R002

- Original source lines: `364-370`
- Original language: `powershell`
- Block SHA256: `416D975F2BA52C13C6608DEA2B7970926B95EA0EDC71FBE10B39CB024AA8FC45`

```powershell
python .\tools\validator.py --mode file --file .\by-class\MailDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\MailDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0047b220-0x0047cc74.MailDialogCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0047ebf0-0x0047ec2b.MailDialogScalarDeletingDestructor.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `374-380`
- Original language: `powershell`
- Block SHA256: `DAAA504E7F02DCFC02CA78F95A824D137256EC37C2435637E5C93F92B6110044`

```powershell
python .\tools\validator.py --mode file --file .\by-file\BulletinReplyAlerts.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\MailDeleteReplyAlert.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-vtable\MailDialogCoreVtables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-vtable\MailDialogVtableFamily.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `384-386`
- Original language: `powershell`
- Block SHA256: `726F8E3D2ED2DD1596CCEE1959EBEB2DDCC252197072F85D0058A6671D66BF77`

```powershell
python .\tools\validator.py --mode file --file .\by-class\-coverage-report.md --apply --queue-timeout 240
```
