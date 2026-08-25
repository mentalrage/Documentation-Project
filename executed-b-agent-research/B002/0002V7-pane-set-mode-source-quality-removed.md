<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002V7-pane-set-mode-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002V7-pane-set-mode-source-quality.md](0002V7-pane-set-mode-source-quality.md)
- Source report SHA256 before cleanup: `EE07D01EE622D1548900AD606F409A04666A7A5806F9E3B6C85A1E3684ED3818`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `237-248`
- Original language: `powershell`
- Block SHA256: `1656FF72B914A3AD3FE22744D11A29D9F6F70A76E2B06581F1987823738823DD`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005446b0-0x005446d4.PaneSetMode.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00544460-0x00545086.PaneCore.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-class\Pane.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-file\Pane.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-struct\PaneLayout.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-vtable\PaneVtables.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x006219e8-0x00621a6c.PaneVtableData.md --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode autogen --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode rescore --apply
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\memory_ranges.py -advanced-scan report
```
