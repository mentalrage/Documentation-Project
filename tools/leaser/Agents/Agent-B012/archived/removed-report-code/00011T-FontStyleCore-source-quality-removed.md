<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\00011T-FontStyleCore-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00011T-FontStyleCore-source-quality.md](00011T-FontStyleCore-source-quality.md)
- Source report SHA256 before cleanup: `A7010669B1B8373141B7867940749D4F2143DC0769097E47624474F77D36F82B`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `343-353`
- Original language: `powershell`
- Block SHA256: `B65B7F29086EEB52A1E40991F217BCBE106750E5E6D9664EC7943D2FDBCE73EA`

```powershell
cd E:\NTK\GhidraBridge
python source-3/project-documentation/tools/validator.py --file source-3/project-documentation/by-memory/0x00499f10-0x00499fda.FontStyleCore.md
python source-3/project-documentation/tools/validator.py --file source-3/project-documentation/by-class/FontStyle.md
python source-3/project-documentation/tools/validator.py --file source-3/project-documentation/by-type/by-struct/FontStyleLayout.md
python source-3/project-documentation/tools/validator.py --file source-3/project-documentation/by-file/FontStyle.md
python source-3/project-documentation/tools/validator.py --file source-3/project-documentation/by-memory/-coverage-report.md
python source-3/project-documentation/tools/validator.py --file source-3/project-documentation/by-class/-coverage-report.md
python source-3/project-documentation/tools/validator.py --file source-3/project-documentation/by-file/-coverage-report.md
python source-3/project-documentation/tools/validator.py --file source-3/project-documentation/by-type/by-struct/-coverage-report.md
```

## Removed Block R002

- Original source lines: `359-361`
- Original language: `powershell`
- Block SHA256: `A65109AEAC16E2E7766132B5E6E400781B318A2EF8FA52F0BFCE7F8E9BF8DF94`

```powershell
rg -n "FontStyle::FontStyle|FontStyle::GetRule|FontStyle::Configure|sub_499F|sub_49AC60" source-3/project-documentation/auto-generated/NexusTK/ui/controls/FontStyle.cpp
```
