<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\00025M-KeySpeedStringResourceReadOnlyData-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00025M-KeySpeedStringResourceReadOnlyData-source-routing.md](00025M-KeySpeedStringResourceReadOnlyData-source-routing.md)
- Source report SHA256 before cleanup: `030BA796D7507F3E6045389B7CB7A5DD190C4B6A8FC5291B9448D65B1BD207AE`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `229-240`
- Original language: `powershell`
- Block SHA256: `671EF2121067EC5D939A926B60F8DB1635357FC8318F090209BDBE5151F6C7E8`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0061c9c4-0x0061c9d4.KeySpeedMgrVtableData.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-type/by-vtable/KeySpeedMgrVtable.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-file/LanguageMan.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/LanguageMan.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-resource/str-res-localized-strings.md --apply
python source-3/project-documentation/tools/validator.py --mode autogen --apply
```
