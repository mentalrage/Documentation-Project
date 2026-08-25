<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md](0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md)
- Source report SHA256 before cleanup: `11E913269A4E7E968B094E492BBB3368FB698CE2B533C63477DFD524DC6C1F47`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `434-444`
- Original language: `powershell`
- Block SHA256: `AB63D0A3ECC9C5860EC259BD9573CAEA849B01E892D02ED01004317681EAC76B`

```powershell
python tools/validator.py --mode file --file by-memory\0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory\0x005b67c0-0x005b68b1.SelfSaveInputPane.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-class\SelfSaveInputPane.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-file\SelfSaveInputPane.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-file\CommandInputPanes.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory\0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory\0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory\0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `448-451`
- Original language: `powershell`
- Block SHA256: `A2EB6E340990CB55351D819F4959BA3315C1AAE41DBDE73179581966B31B06EA`

```powershell
python tools/validator.py --mode file --file by-memory\0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-type\by-vtable\SelfSaveInputPaneVtables.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `455-457`
- Original language: `powershell`
- Block SHA256: `A0DBE3EAA7D7194AB79093B54E6A873CF014257AEB4A8BF3D07E163B1B1BA434`

```powershell
python tools/validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
```
