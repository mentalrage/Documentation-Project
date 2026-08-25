<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002B7-widechar-buffer-source-linkage.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002B7-widechar-buffer-source-linkage.md](0002B7-widechar-buffer-source-linkage.md)
- Source report SHA256 before cleanup: `264C9C6EEA8AE2C458789724B5047FD10288BCBF27A97D6BC09256486F27E426`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `388-393`
- Original language: `powershell`
- Block SHA256: `923F66419025E90F7C07C5B8DE4FC831A57B49A6DD41CC7042732F102037F66B`

```powershell
python .\tools\validator.py --mode file --file .\by-memory\0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x0067adec-0x0067adf0.UnreferencedInitializedDword_67ADEC.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md --apply --lock-timeout -1
python .\tools\memory_ranges.py report
```
