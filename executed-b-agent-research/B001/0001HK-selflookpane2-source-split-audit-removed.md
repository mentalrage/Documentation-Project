<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001HK-selflookpane2-source-split-audit.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001HK-selflookpane2-source-split-audit.md](0001HK-selflookpane2-source-split-audit.md)
- Source report SHA256 before cleanup: `C57C00E4E3E942A88062FF1EB6B29E60F46D6EAC0C8BAE52628B6172970D2FB1`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `312-318`
- Original language: `powershell`
- Block SHA256: `B333D4875A04C2E375C6DAE5CEBB7A0C8B0F8601A2B8F5942D769C731D0986B7`

```powershell
python tools/validator.py --mode file --file by-memory/<new-child-page>.md --apply
python tools/validator.py --mode file --file by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md --apply
python tools/validator.py --mode file --file by-class/SelfLookPane2.md --apply
python tools/validator.py --mode file --file by-file/SelfLookPane.md --apply
python tools/validator.py --mode file --file by-memory/-ignored.md --apply
```

## Removed Block R002

- Original source lines: `322-324`
- Original language: `powershell`
- Block SHA256: `CEEC4B58A89D4891B2A6857C8D19B5C2ED8E65E7ACDDCF1827BE09BE6DD53E24`

```powershell
python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply
```
