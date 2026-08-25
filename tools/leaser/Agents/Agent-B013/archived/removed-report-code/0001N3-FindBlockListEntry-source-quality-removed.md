<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\0001N3-FindBlockListEntry-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001N3-FindBlockListEntry-source-quality.md](0001N3-FindBlockListEntry-source-quality.md)
- Source report SHA256 before cleanup: `BD7227F51D7E21F8AAAC0F5A5791E6C8E1E699C29B825398B8C63B5EFCDCD29A`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `112-114`
- Original language: `powershell`
- Block SHA256: `CB0FDE63B601AF094C3DF1177D99196980E6EA57A41AE6609E37A4EF0B9D1771`

```powershell
python tools/validator.py --mode file --file by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md --uid-only
```

## Removed Block R002

- Original source lines: `323-331`
- Original language: `powershell`
- Block SHA256: `2E08019A01869D981A9DA7D4B6A755C035066126C1C352A380C1E33425BBA45E`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools/validator.py --mode file --file by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md --apply
python tools/validator.py --mode file --file by-global/FindBlockListEntry_5B74E0.md --apply
python tools/validator.py --mode file --file by-file/BlockListenInputPanes.md --apply
python tools/validator.py --mode file --file by-class/AddToBlockListenInputPane.md --apply
python tools/validator.py --mode file --file by-class/DeleteFromBlockListenInputPane.md --apply
python tools/validator.py --mode autogen
```
