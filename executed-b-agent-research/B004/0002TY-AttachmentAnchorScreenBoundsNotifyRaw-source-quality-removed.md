<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality.md](0002TY-AttachmentAnchorScreenBoundsNotifyRaw-source-quality.md)
- Source report SHA256 before cleanup: `A73078E53AAD0D381E4E3B1AAC189454D45127D25D7466A75CFDCCD2521F2E74`
- Cleanup generated: `2026-08-11T12:47:07Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `523-527`
- Original language: `powershell`
- Block SHA256: `9CBF07DC368A4C91BE3A0ED09C759D1BD4B0657FE20048279791673FDA2F4F03`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\AttachmentAnchorResolver.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\AttachmentAnchorResolver.md --apply --queue-timeout 240 --lock-timeout -1
```

## Removed Block R002

- Original source lines: `531-533`
- Original language: `powershell`
- Block SHA256: `87C48DB9F6A61D8BBE1DE62E15D2D17D8FA35B3505E07E0CDB8CDDF97932ABBA`

```powershell
python .\tools\validator.py --mode file --file .\by-file\AttachedObjectPane.md --apply --queue-timeout 240 --lock-timeout -1
```

## Removed Block R003

- Original source lines: `537-541`
- Original language: `powershell`
- Block SHA256: `2634B989AF6C75B216D7E832A8F86598D545732824920269F03BA6E75B99BDD4`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode autogen --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
```
