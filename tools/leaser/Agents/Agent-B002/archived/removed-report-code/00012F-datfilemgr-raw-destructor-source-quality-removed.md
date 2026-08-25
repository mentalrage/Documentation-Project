<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00012F-datfilemgr-raw-destructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00012F-datfilemgr-raw-destructor-source-quality.md](00012F-datfilemgr-raw-destructor-source-quality.md)
- Source report SHA256 before cleanup: `EA6691513BC56CC587BD2312A6115C5CBF100A18CC4F9F8CF959E9565D7C1204`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `397-406`
- Original language: `powershell`
- Block SHA256: `99FBCBF6CDD44D6BAA3976B1EBE46D545A703E8D0FABF77A232AE9294EA595DD`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\_DATFileMgr.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\DATFileMgr.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0049bd30-0x0049d6ed.DATManagers.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0049d190-0x0049d26c.DATFileResolverDestroy.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1
python .\tools\memory_ranges.py report
python .\tools\validator.py --mode rescore --apply --lock-timeout -1
```

## Removed Block R002

- Original source lines: `410-414`
- Original language: `powershell`
- Block SHA256: `6DF733D5DA528BF0090AFB5376A62B45786072FB5736541B79A126F674F8CE3D`

```powershell
Select-String -LiteralPath project-level\-auto-completion-stats.md -Pattern '00012F|0049c750'
Select-String -LiteralPath auto-generated\-ag-memory-coverage.md -Pattern '00012F|0049c750'
Select-String -LiteralPath by-memory\-coverage-report.md -Pattern '00012F|0049c750' -Context 1,1
```
