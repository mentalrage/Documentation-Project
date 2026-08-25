<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\00032G-RegistryConfigTypeProbeRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00032G-RegistryConfigTypeProbeRaw-source-quality.md](00032G-RegistryConfigTypeProbeRaw-source-quality.md)
- Source report SHA256 before cleanup: `CABA59C5BFF3F06F9CFFA57C48F7F1672CDC79188F6CF855AD749C56D4F45550`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `482-489`
- Original language: `powershell`
- Block SHA256: `E9DD8877297F0AD410E836E7A93CEDBF58E0EAFB74697C06A524E1EA9CF224CB`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-file/RegistryConfig.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/RegistryConfig.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md --apply
python source-3/project-documentation/tools/validator.py --mode autogen --apply
```
