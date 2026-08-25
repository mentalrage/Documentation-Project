<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B012\00015L-FpsPaneScalarDeletingDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00015L-FpsPaneScalarDeletingDestructor-source-quality.md](00015L-FpsPaneScalarDeletingDestructor-source-quality.md)
- Source report SHA256 before cleanup: `BA4732AEA0D799B6AA476ECCDDB2AD88A0B0F9B1C8AE534CECEFDCC3CA57173D`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `207-211`
- Original language: `powershell`
- Block SHA256: `ECE5F125805DCB1EBAAAFF32F7E80344FFBC8E0045604312F6B10E903FA8DB6D`

```powershell
cd source-3/project-documentation
python tools/validator.py --mode file --file by-memory\0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory\0x004b6470-0x004b6499.FpsPaneDestructor.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `215-218`
- Original language: `powershell`
- Block SHA256: `4EB7589B1B09B2A781F12B19EEA605F7DA663B5DB550B2211352717423DB44A2`

```powershell
python tools/validator.py --mode file --file by-class\FpsPane.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-file\FpsPane.md --apply --queue-timeout 240
```
