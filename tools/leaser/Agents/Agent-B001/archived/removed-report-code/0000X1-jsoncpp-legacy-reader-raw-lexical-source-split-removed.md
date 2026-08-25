<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0000X1-jsoncpp-legacy-reader-raw-lexical-source-split.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000X1-jsoncpp-legacy-reader-raw-lexical-source-split.md](0000X1-jsoncpp-legacy-reader-raw-lexical-source-split.md)
- Source report SHA256 before cleanup: `5FA1B9ECB275ECC371E5250675F9669C904D0F05EE15EC1965201341A6637AC6`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `354-367`
- Original language: `powershell`
- Block SHA256: `880CC1987A08EC8B372B9A46413D5EB81D93F27D5F22ECC11F5B8DC0C1251924`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file .\by-memory\0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x0042ace0-0x0042ad27.JsonCppLegacyReaderReadCStyleComment.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x0042ad30-0x0042ad66.JsonCppLegacyReaderReadCppStyleComment.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x0042ad70-0x0042ada3.JsonCppLegacyReaderReadString.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x0042adb0-0x0042ae88.JsonCppLegacyReaderReadNumber.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\JsonCpp.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-ignored.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --lock-timeout -1
python .\tools\validator.py --mode autogen --apply --lock-timeout -1
python .\tools\memory_ranges.py report
python .\tools\validator.py --mode rescore --apply --lock-timeout -1
```
