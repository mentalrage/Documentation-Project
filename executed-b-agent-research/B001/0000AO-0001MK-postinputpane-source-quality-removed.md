<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0000AO-0001MK-postinputpane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000AO-0001MK-postinputpane-source-quality.md](0000AO-0001MK-postinputpane-source-quality.md)
- Source report SHA256 before cleanup: `86F70C32DFFCC8276B1243D23AF0CB99D893D4293B255FFE5C8FBCBBA3F14DFC`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `446-461`
- Original language: `powershell`
- Block SHA256: `EDD13E89C959449CC370271CC7D088AFF17CD660FE8643375DD3DF3504161F0C`

```powershell
$root = 'E:\NTK\GhidraBridge\source-3\project-documentation'

python "$root\tools\validator.py" --mode file --file "by-class\PostInputPane.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-memory\0x005b5630-0x005b5890.PostInputPane.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-file\CommandInputPanes.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-type\by-vtable\GroupPostInputPaneVtables.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-memory\0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-class\-coverage-report.md" --apply --lock-timeout -1
python "$root\tools\validator.py" --mode file --file "by-memory\-coverage-report.md" --apply --lock-timeout -1

python "$root\tools\validator.py" --mode documented --remove-missing --apply --lock-timeout -1
python "$root\tools\validator.py" --mode autogen --apply --lock-timeout -1
python "$root\tools\validator.py" --mode rescore --apply --lock-timeout -1
python "$root\tools\memory_ranges.py" report
```
