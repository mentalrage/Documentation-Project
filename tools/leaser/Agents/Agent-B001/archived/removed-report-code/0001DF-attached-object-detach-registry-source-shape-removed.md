<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0001DF-attached-object-detach-registry-source-shape.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001DF-attached-object-detach-registry-source-shape.md](0001DF-attached-object-detach-registry-source-shape.md)
- Source report SHA256 before cleanup: `B323616CC6A0CE63A1F400185BC258CCFF3BFB5B3B3F5A95A783CD9B4E4AA140`
- Cleanup generated: `2026-08-11T12:46:57Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `325-339`
- Original language: `powershell`
- Block SHA256: `5B763F1FE69FAF3E25FA9B4951E86C73DF24DCC6F669CFF883FC79A3A1D69048`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\AttachedObjectPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\AttachedObjectPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\AttachedObjectPaneHelper_53AEC0.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\AttachedObjectPaneHelper_53AEC0.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-type\by-struct\AttachedObjectRegistryLayout.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\LivingObjectPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\LivingObjectPane.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0053a110-0x0053d818.LivingObjectPaneCore.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md --apply --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1
python .\tools\memory_ranges.py report
```
