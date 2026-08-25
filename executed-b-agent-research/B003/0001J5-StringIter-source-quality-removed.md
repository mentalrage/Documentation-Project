<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0001J5-StringIter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001J5-StringIter-source-quality.md](0001J5-StringIter-source-quality.md)
- Source report SHA256 before cleanup: `80E1BA7F55E5E4F7267B9E035AE7C2F6285E22B77C3B72721642BEC6FDA3B610`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `398-404`
- Original language: `powershell`
- Block SHA256: `4B30F5B8ED6CC1E4EF61B33A2B78F8730D27DBC58B363A370557996EA9D63EDA`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00584d80-0x00584e9e.StringIter.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\StringIter.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\StringUtil.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-meta\client_string_handling.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `408-412`
- Original language: `powershell`
- Block SHA256: `C5F197A5E25F3266B23EB5C4861BE27B03E8568A257CED610DF07126D215F378`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `416-418`
- Original language: `powershell`
- Block SHA256: `8F3B0B95CD8246F1135B89B6F5A4C8D8A5D30CFEDA230A184A2B1EEC24660A0C`

```powershell
python .\tools\memory_ranges.py report
```
