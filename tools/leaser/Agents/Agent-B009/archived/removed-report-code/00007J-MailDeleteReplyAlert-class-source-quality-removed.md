<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\00007J-MailDeleteReplyAlert-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00007J-MailDeleteReplyAlert-class-source-quality.md](00007J-MailDeleteReplyAlert-class-source-quality.md)
- Source report SHA256 before cleanup: `E2E438099EA6A00AE2D44E76CD524B14F8457865D9265FB3A2FD85DB9C3E88F5`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `710-729`
- Original language: `powershell`
- Block SHA256: `AF2A078414233D3FAFBC83341510DA040D5FB898981C14E603EC57D5F60FB531`

```powershell
python .\tools\validator.py --mode file --file .\by-class\MailDeleteReplyAlert.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\BulletinReplyAlerts.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\MailDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\MailDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\DeleteReplyAlert.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\MailListPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-global\g_pMailDeleteReplyAlert.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0067adbc-0x0067adc0.g_pMailDeleteReplyAlert.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-vtable\MailAlertCompanionVtables.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-vtable\MailDialogVtableFamily.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00479110-0x0047ec2b.MailDialogs.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-type\by-struct\AlertPaneLayout.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `737-739`
- Original language: `powershell`
- Block SHA256: `FF1878A6B2035980E39DA557D442D3C2D2E62DB88EF024A8F9FE78D8068E19E7`

```powershell
python .\tools\validator.py --mode file --file .\by-class\MailDeleteReplyAlert.md --queue-timeout 240
```
