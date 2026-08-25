<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0003XF-GrafPortPatternPackRaw-current-reanalysis.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003XF-GrafPortPatternPackRaw-current-reanalysis.md](0003XF-GrafPortPatternPackRaw-current-reanalysis.md)
- Source report SHA256 before cleanup: `85BCD9C5F5372702096D539EC6B869566D1A3C3AB214BBA0DE7EA0AC16E375B0`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `515-519`
- Original language: `powershell`
- Block SHA256: `7825E22840B6BD9B8B152A558C82572449BFA8CC37F44DAB915C18A211ACEA12`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md --apply
rg -n "0003XF|004bb5b0|PackTwoColorSixPixelPattern|short-branch|ModRM|004bb604" by-memory\0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md by-memory\0x004b8bf0-0x004bb8c4.GrafPort.md by-file\GrafPort.md by-class\GrafPort.md
```

## Removed Block R002

- Original source lines: `523-527`
- Original language: `powershell`
- Block SHA256: `825D6E8900AC36129B9D4D26DA246A00FE1A7A35C465249C2D90058B82DB0121`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-file\GrafPort.md --apply
python tools\validator.py --mode file --file by-class\GrafPort.md --apply
```

## Removed Block R003

- Original source lines: `531-535`
- Original language: `powershell`
- Block SHA256: `E0A7A112333CB3490AEC5E166883341AEA0447CE1AD7A7C5A4C51EEFC1779800`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply
rg -n "0003XF|004bb5b0|84%" by-memory\-coverage-report.md auto-generated\-ag-memory-coverage.md project-level\-auto-completion-stats.md
```

## Removed Block R004

- Original source lines: `539-543`
- Original language: `powershell`
- Block SHA256: `F35BE2ED90BA2F5B50474EBCE8C5B65B1FC0F08C40AD042DE5159CBE3542E0D4`

```powershell
# Use the current by-structure.md MCP initialize -> tools/list -> tools/call flow.
# Required checks: lookup_funcs for 0x004bb5b0/0x004bb5e0, xrefs_to 0x004bb5b0,
# disasm for 0x004bb5a5-0x004bb5e0, and callers/callees for 0x004bb5e0.
```
