<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality.md](0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality.md)
- Source report SHA256 before cleanup: `DEAE733945FA8460FE2ACA98462F2CCEEA5B28DA3379DA9A32937597AA7E1047`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `620-628`
- Original language: `powershell`
- Block SHA256: `3F8ECCB8EBFEDA8330AD3D1477CAE727BB571761F5D8F9C56F8A1F1701DD1CF0`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00552110-0x005534a0.TextDialogCore.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\TextDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\TextDialog.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x00553180-0x00553338.TextDialogHandleDialogAction.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `632-634`
- Original language: `powershell`
- Block SHA256: `EDBAAF6E1143005DA085ABE613272DF1C35A91FA9DE1C71B9DD2A2893045AD3F`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240
```
