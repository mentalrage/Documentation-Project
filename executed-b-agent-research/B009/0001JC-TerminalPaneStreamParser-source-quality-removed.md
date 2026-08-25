<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\0001JC-TerminalPaneStreamParser-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001JC-TerminalPaneStreamParser-source-quality.md](0001JC-TerminalPaneStreamParser-source-quality.md)
- Source report SHA256 before cleanup: `2B21FCCCD646C93F5AAC94D0D6D7515F892BE89BF181B4FDB71A7DF348898BCE`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `449-455`
- Original language: `text`
- Block SHA256: `020D2A7D2B8E5058D8BF50E1561B118BDD86993DD48815521CF37F0DE305E9BA`

```text
python .\tools\validator.py --mode file --file by-memory\0x0058b130-0x0058b44b.TerminalPaneStreamParser.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\TerminalPane.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\TerminalPane.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0058af50-0x0058c350.TerminalPaneAndSetup.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md --apply --wait-generated --queue-timeout 240
```
