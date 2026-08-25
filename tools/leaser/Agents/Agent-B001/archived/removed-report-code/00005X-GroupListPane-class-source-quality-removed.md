<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00005X-GroupListPane-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00005X-GroupListPane-class-source-quality.md](00005X-GroupListPane-class-source-quality.md)
- Source report SHA256 before cleanup: `EF5A36C48EAF070F76E44CA9A8D4630046D1C8BC54F6E8935114444EF63C6C9C`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `468-478`
- Original language: `powershell`
- Block SHA256: `56FAB6B7EB07688BD56A6F6C949C46EAA5F17FF3CCD74CD7E017E05A0E495F47`

```powershell
python tools\validator.py --mode file --file "by-class\GroupListPane.md" --apply --queue-timeout 240
python tools\validator.py --mode file --file "by-memory\0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md" --apply --queue-timeout 240
python tools\validator.py --mode file --file "by-memory\0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md" --apply --queue-timeout 240
python tools\validator.py --mode file --file "by-memory\0x00624210-0x006242c4.GroupListPaneVtableData.md" --apply --queue-timeout 240
python tools\validator.py --mode file --file "by-type\by-vtable\GroupPaneFamilyVtables.md" --apply --queue-timeout 240
python tools\validator.py --mode file --file "by-file\Group.md" --apply --queue-timeout 240
python tools\validator.py --mode file --file "by-class\GroupPane.md" --apply --queue-timeout 240
python tools\validator.py --mode file --file "by-class\GroupPane2.md" --apply --queue-timeout 240
python tools\validator.py --mode file --file "by-memory\0x0056c4c0-0x0056e939.GroupPanes.md" --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `496-498`
- Original language: `powershell`
- Block SHA256: `1FD6DCF418A3285A2E8BD0C260EFB5160BB45BD740826C43E091984869894376`

```powershell
python tools\validator.py --mode file --file "by-class\GroupListPane.md" --queue-timeout 240
```
