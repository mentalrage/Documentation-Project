<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality.md](00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality.md)
- Source report SHA256 before cleanup: `7155D30AA34E23BC1418BB44BFD573CDA0B1EF6AA144C5B91EBD82D381AC4F64`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `489-495`
- Original language: `powershell`
- Block SHA256: `FD917A332B0D2C6B15DD676A9D95642A4C2AEFD235C516120B3F4B8400EDACF1`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-class\TargetObjectWithKeyboardPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-file\TargetSelectionInputPanes.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `499-505`
- Original language: `powershell`
- Block SHA256: `394F0B9332D7375586CC334F37511AF82BEAE1FD9FE14ED745066F0EC09DF677`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x005b05d0-0x005b0638.TargetObjectWithKeyboardPaneSelectPreviousTargetRawHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file .\by-memory\-ignored.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
