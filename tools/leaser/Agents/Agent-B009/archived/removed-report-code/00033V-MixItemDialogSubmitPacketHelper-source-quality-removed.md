<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\00033V-MixItemDialogSubmitPacketHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00033V-MixItemDialogSubmitPacketHelper-source-quality.md](00033V-MixItemDialogSubmitPacketHelper-source-quality.md)
- Source report SHA256 before cleanup: `8F5B62FEEDA4975AC800D6500C20D1F4E2A6B5EC293622E35A342DF7FAA9AE9B`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `382-388`
- Original language: `powershell`
- Block SHA256: `8E69B1BAFE3C6380C1DE9DBA6CF57ECE0962946F3C63DD5B96CAC4415F304954`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file "by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md" --apply --queue-timeout 240
python .\tools\validator.py --mode file --file "by-class/MixItemDialog.md" --apply --queue-timeout 240
python .\tools\validator.py --mode file --file "by-memory/0x004af570-0x004afb80.MixItemDialogCore.md" --apply --queue-timeout 240
python .\tools\validator.py --mode file --file "by-file/ItemDialogs.md" --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `392-394`
- Original language: `powershell`
- Block SHA256: `DE37EA9B79715249B4DA7411F6F006C2C8E1D2B97AA33F461426890E771D1686`

```powershell
python .\tools\validator.py --mode file --file "by-type/by-vtable/MixItemDialogVtables.md" --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `398-401`
- Original language: `powershell`
- Block SHA256: `37EB72F5A4B15A1211DA24A04D7AA11F952FA80A3F0E6821062DEF02FEA3B21C`

```powershell
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
rg -n "00033V|SubmitMixPacket|0x004afb80" by-memory/-coverage-report.md auto-generated/-ag-memory-coverage.md project-level/-auto-completion-stats.md auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp
```
