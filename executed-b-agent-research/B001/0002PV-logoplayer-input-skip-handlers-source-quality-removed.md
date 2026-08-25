<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002PV-logoplayer-input-skip-handlers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002PV-logoplayer-input-skip-handlers-source-quality.md](0002PV-logoplayer-input-skip-handlers-source-quality.md)
- Source report SHA256 before cleanup: `9EF3CE27AD4C518237548663078AD59998274CA01172DFBEF03C5615D88D78CA`
- Cleanup generated: `2026-08-11T12:46:58Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `537-547`
- Original language: `powershell`
- Block SHA256: `CBDD2A7F18A13238F6E22DECE96579239CA6775856F8BCA4A5366956952B80F3`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation

python .\tools\validator.py --mode file --file .\by-memory\0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\LogoPlayerPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x004f53b0-0x004f570c.LogoPlayerPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-file\StartupLogoPanes.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode autogen --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
```

## Removed Block R002

- Original source lines: `551-556`
- Original language: `powershell`
- Block SHA256: `C83CEF23D49B0430AB2082E5B0DA77F25BE9CFA7656A870D40F98DAE8E644818`

```powershell
python .\tools\validator.py --mode file --file .\by-file\Event.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-memory\0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-class\EventHandler.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file .\by-type\by-struct\PaneLayout.md --apply --queue-timeout 240 --lock-timeout -1
```
