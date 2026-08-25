<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001JP-0001JS-texteditpane-format-nav-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001JP-0001JS-texteditpane-format-nav-source-quality.md](0001JP-0001JS-texteditpane-format-nav-source-quality.md)
- Source report SHA256 before cleanup: `3209BD30117E74137D752E65254076960D8CA4B061294CD394E4DDE23D028F43`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `138-141`
- Original language: `powershell`
- Block SHA256: `0AA9E526E74B36B172FC3F1D636AEB1FA8D7C31DD3ED83037C795D90E12F746C`

```powershell
git mv by-memory\0x00591d60-0x00593a10.TextEditPaneFormattingRuns.md by-memory\0x00591d60-0x00593c1c.TextEditPaneFormattingRuns.md
git mv by-memory\0x00594040-0x00594e11.TextEditPaneInputNavigationAndWrap.md by-memory\0x00594040-0x00594e5f.TextEditPaneInputNavigationAndWrap.md
```

## Removed Block R002

- Original source lines: `239-248`
- Original language: `powershell`
- Block SHA256: `EDCDC7D6C0DA87E6A8A8F5862692BC3250A2203DD2D3AADFBB5D922DBCE678EF`

```powershell
python validator.py --mode file --file ..\by-memory\0x00591d60-0x00593c1c.TextEditPaneFormattingRuns.md --apply
python validator.py --mode file --file ..\by-memory\0x00594040-0x00594e5f.TextEditPaneInputNavigationAndWrap.md --apply
python validator.py --mode file --file ..\by-class\TextEditPane.md --apply
python validator.py --mode file --file ..\by-file\TextEditPane.md --apply
python validator.py --mode file --file ..\by-memory\-ignored.md --apply
python validator.py --mode file --file ..\by-memory\-coverage-report.md --apply
python validator.py --mode documented --remove-missing --apply
python validator.py --mode autogen --apply
```
