<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\0001JB-TerminalPaneAndSetup-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001JB-TerminalPaneAndSetup-source-quality.md](0001JB-TerminalPaneAndSetup-source-quality.md)
- Source report SHA256 before cleanup: `DD2823C7AA7FCA8F050B248C5A9CB2CFBEA058EF2E7B19A12FBB46C897A94832`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `1069-1082`
- Original language: `powershell`
- Block SHA256: `28D6305207B5A5C81ACA16EFE90AF9EC6DDB82F1422B377C3D3659872A6B0438`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools/validator.py --file by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md --apply --queue-timeout 240
python tools/validator.py --file by-file/TerminalPane.md --apply --queue-timeout 240
python tools/validator.py --file by-class/TerminalPane.md --apply --queue-timeout 240
python tools/validator.py --file by-class/TerminalSetupPane.md --apply --queue-timeout 240
python tools/validator.py --file by-global/g_pTerminalPane.md --apply --queue-timeout 240
python tools/validator.py --file by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md --apply --queue-timeout 240
python tools/validator.py --file by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md --apply --queue-timeout 240
python tools/validator.py --file by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --queue-timeout 240
python tools/validator.py --file by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md --apply --queue-timeout 240
python tools/validator.py --file by-memory/0x0062de34-0x0062dee8.TerminalSetupPaneResourceStrings.md --apply --queue-timeout 240
python tools/validator.py --file by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md --apply --queue-timeout 240
```
