<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0000E2-StaticObjImageLib-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000E2-StaticObjImageLib-class-source-quality.md](0000E2-StaticObjImageLib-class-source-quality.md)
- Source report SHA256 before cleanup: `FE75BE41E5096186558D79AF5A7E4169EDB58B9EEF090757DE9510D8542DBB6E`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `592-602`
- Original language: `powershell`
- Block SHA256: `B8D5FE29CE90402326E384E9FC5FF2A7F620B03240B6686ADFB177EF1518C720`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-class/StaticObjImageLib.md --apply --lock-timeout -1
python source-3/project-documentation/tools/validator.py --mode file --file by-file/StaticObjImageLib.md --apply --lock-timeout -1
python source-3/project-documentation/tools/validator.py --mode file --file by-type/by-struct/StaticObjImageLibLayout.md --apply --lock-timeout -1
python source-3/project-documentation/tools/validator.py --mode file --file by-type/by-struct/StaticObjEntry.md --apply --lock-timeout -1
python source-3/project-documentation/tools/validator.py --mode file --file by-type/by-struct/TileClassEntry.md --apply --lock-timeout -1
python source-3/project-documentation/tools/validator.py --mode file --file by-resource/sobj-tbl.md --apply --lock-timeout -1
python source-3/project-documentation/tools/validator.py --mode file --file by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md --apply --lock-timeout -1
python source-3/project-documentation/tools/validator.py --mode file --file by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md --apply --lock-timeout -1
python source-3/project-documentation/tools/validator.py --mode file --file by-class/-coverage-report.md --apply --lock-timeout -1
```

## Removed Block R002

- Original source lines: `606-608`
- Original language: `powershell`
- Block SHA256: `D1E7B47A542BF530B22C0770A84757CA12E31E0BBB35C7DDB91DA25293A0A1E8`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1
```
