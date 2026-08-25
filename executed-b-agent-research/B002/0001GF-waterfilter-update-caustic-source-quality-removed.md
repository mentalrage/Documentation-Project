<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0001GF-waterfilter-update-caustic-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001GF-waterfilter-update-caustic-source-quality.md](0001GF-waterfilter-update-caustic-source-quality.md)
- Source report SHA256 before cleanup: `797A69E5D0C14F5C409F26ACF66BA9F3E9D0077D2E2EAC6A033EAA7413396E87`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `256-263`
- Original language: `powershell`
- Block SHA256: `3EEFBEE8FBB3791A130BDA2EEB67CBCE1378C1410ACEB0C637102CBF6BFEF815`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md --apply
python .\tools\validator.py --mode file --file by-class\WaterFilterEffecter.md --apply
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply
python .\tools\memory_ranges.py report
python .\tools\memory_ranges.py -advanced-scan report
rg -n "0001GF|0x0055b5d0|WaterFilterEffecter::OnPaint|0x00623cb4|CAUST\\.PAL|DrawPictureObjectPane" by-memory by-class by-file by-type by-item
```

## Removed Block R002

- Original source lines: `267-270`
- Original language: `powershell`
- Block SHA256: `1C3FB1EC6249EB5E1BEB1DD30098FAD6313479E8A28C160C8D79CBC06F274FF2`

```powershell
# Reconfirm target bytes with section-aware VA->file mapping before any source-quality challenge.
# Expected: 0x0055b5d0 maps to file offset 0x0015a9d0 in NexusTK.exe, and 0x0055b698-0x0055b69f are CC bytes.
```
