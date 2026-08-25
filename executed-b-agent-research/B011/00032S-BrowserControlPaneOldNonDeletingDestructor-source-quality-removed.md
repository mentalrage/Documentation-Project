<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\00032S-BrowserControlPaneOldNonDeletingDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00032S-BrowserControlPaneOldNonDeletingDestructor-source-quality.md](00032S-BrowserControlPaneOldNonDeletingDestructor-source-quality.md)
- Source report SHA256 before cleanup: `6778934674DCE9FACF5A99CDCBFDB3F96A01673127B6579C046823C4DE8A09A4`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `484-493`
- Original language: `powershell`
- Block SHA256: `B93CB51DC564EF7AC2ABE66D087BB1DEE073240F48FCF34419FF56FA4A0878CA`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\BrowserControlPaneOld.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\Browser.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x006131b4-0x006139df.BrowserVtablesAndStrings.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `497-499`
- Original language: `powershell`
- Block SHA256: `EDBAAF6E1143005DA085ABE613272DF1C35A91FA9DE1C71B9DD2A2893045AD3F`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240
```
