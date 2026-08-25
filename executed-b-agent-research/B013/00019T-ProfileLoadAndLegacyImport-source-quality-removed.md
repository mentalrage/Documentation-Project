<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\00019T-ProfileLoadAndLegacyImport-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00019T-ProfileLoadAndLegacyImport-source-quality.md](00019T-ProfileLoadAndLegacyImport-source-quality.md)
- Source report SHA256 before cleanup: `D9FA93641748A425CA5C008F5984150ABB365081C67282FC9D1B6631CD0EEC82`
- Cleanup generated: `2026-08-11T14:26:07Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.


## Removed Block R001

- Source report SHA256 before this cleanup pass: `D9FA93641748A425CA5C008F5984150ABB365081C67282FC9D1B6631CD0EEC82`
- Original source lines: `114-116`
- Original language: `text`
- Block SHA256: `BE6114F6A868141A4ECF5B41AF21B080A579FA240E9C88DE75A3F22D2FCD1526`

```text
Push-Location 'source-3/project-documentation'; python tools/validator.py --mode file --file by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md --uid-only; Pop-Location
```


## Removed Block R002

- Source report SHA256 before this cleanup pass: `D9FA93641748A425CA5C008F5984150ABB365081C67282FC9D1B6631CD0EEC82`
- Original source lines: `669-677`
- Original language: `text`
- Block SHA256: `00204CAEA7D3AB50EF6A8E1A43DF452D146977237844C9E62FBA7B938E348CD1`

```text
Push-Location 'source-3/project-documentation'
python tools/validator.py --mode file --file by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md --uid-only
python tools/validator.py --mode file --file by-file/ProfileStorage.md --uid-only
python tools/validator.py --mode file --file by-type/by-struct/RegistryConfigUserProfileBlock.md --uid-only
python tools/validator.py --mode file --file by-global/WideApiDispatchTable.md --uid-only
python tools/validator.py --mode file --file by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md --uid-only
Pop-Location
```
