<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0000XJ-LodePngLowerBoundHelper-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000XJ-LodePngLowerBoundHelper-source-quality.md](0000XJ-LodePngLowerBoundHelper-source-quality.md)
- Source report SHA256 before cleanup: `DA9CC748D5921A352644D1296370D848B24F318B6D14F20C148B35E3A0CF7D36`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `146-150`
- Original language: `powershell`
- Block SHA256: `977DBC40949F2A9F4AD8016459919E2924F7223221A2A8E1BC7F4674F2343F91`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00450030-0x0045007c.LodePngLowerBoundHelper.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\LodePNG.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md --apply --wait-generated --queue-timeout 240
```

## Removed Block R002

- Original source lines: `154-157`
- Original language: `powershell`
- Block SHA256: `E577F27F3EAE5EF399ADA27D2F13159BE91E0888E39F16A1525D84E60F35C595`

```powershell
rg -n "UID:0000XJ|0x00450030|searchCodeIndex|third_party_embeds/lodepng|Imported source" auto-generated\NexusTK\third_party\LodePNG.cpp
rg -n "0000XJ|0x00450030-0x0045007b|0x00450030-0x0045007c" auto-generated\-ag-research-tracker.md auto-generated\-ag-coverage-report-by-memory.md
```
