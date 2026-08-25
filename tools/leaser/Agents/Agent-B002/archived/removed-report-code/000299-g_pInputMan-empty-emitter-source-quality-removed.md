<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\000299-g_pInputMan-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000299-g_pInputMan-empty-emitter-source-quality.md](000299-g_pInputMan-empty-emitter-source-quality.md)
- Cleanup reason: executable PowerShell is prohibited in B-agent research reports; valid research and reconstructed C++ remain in the original report.
- Preservation: every removed block below is copied verbatim, with its original language and start line recorded.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original start line: `643`
- Language: `powershell`
- Preserved body SHA256: `00ED61F9134BDC0F6F1FF715799523DB237E2AB5FD43D72EAACC559D63B5152D`
- Original fenced-block characters: `522`

~~~~powershell
python .\tools\validator.py --mode file --file by-global\g_pInputMan.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory\0x0067ab44-0x0067ab48.g_pInputMan.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-class\InputMan.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-file\InputMan.md --apply --queue-timeout 240 --no-generated-refresh
~~~~
