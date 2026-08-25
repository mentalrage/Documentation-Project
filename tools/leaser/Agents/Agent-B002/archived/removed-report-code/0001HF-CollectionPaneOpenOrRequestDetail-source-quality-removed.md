<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001HF-CollectionPaneOpenOrRequestDetail-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001HF-CollectionPaneOpenOrRequestDetail-source-quality.md](0001HF-CollectionPaneOpenOrRequestDetail-source-quality.md)
- Source report SHA256 before cleanup: `FD6C4E7F6CCDA159AC8857DBBFC810A3B25125F41C2BFBC55D7539BB0CC43BD8`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `292-298`
- Original language: `powershell`
- Block SHA256: `0DB304AC73789E53C9033EF5654F1C3FD383C1D1D46A1C26058BACEB604A85AD`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md --apply --wait-generated --queue-timeout 240
python tools\validator.py --mode file --file by-class\CollectionPane.md --apply --wait-generated --queue-timeout 240
python tools\validator.py --mode file --file by-file\CollectionPane.md --apply --wait-generated --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x0056e940-0x0056fe75.CollectionPane.md --apply --wait-generated --queue-timeout 240
```

## Removed Block R002

- Original source lines: `304-307`
- Original language: `powershell`
- Block SHA256: `8B5D5F6437EE02E2816C0C6DBBD60ECE92460071330BA784370360D1D2907E7D`

```powershell
rg -n "0001HF|OpenOrRequestGroupDetail|0x27|QueueAndSendPacket|CollectionDialogPane" auto-generated\NexusTK\ui\panels\CollectionPane.cpp
rg -n "0001HF|0x0056fc80" auto-generated\-ag-memory-coverage.md auto-generated\-ag-coverage-report-by-memory.md
```
