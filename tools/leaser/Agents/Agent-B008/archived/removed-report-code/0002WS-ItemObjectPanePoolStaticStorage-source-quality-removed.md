<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0002WS-ItemObjectPanePoolStaticStorage-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002WS-ItemObjectPanePoolStaticStorage-source-quality.md](0002WS-ItemObjectPanePoolStaticStorage-source-quality.md)
- Source report SHA256 before cleanup: `E6FA736D870356F9C04A9F4A018724865508BBC26B248424C878192C126FB657`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `787-791`
- Original language: `powershell`
- Block SHA256: `6CBE65657DCF51F179CE999CE1AF1CD5CBD1092A0D4F26223778B04809F0007C`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\ItemObjectPane.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-file\ItemObjectPane.md --apply --queue-timeout 240 --wait-generated
```

## Removed Block R002

- Original source lines: `802-810`
- Original language: `powershell`
- Block SHA256: `779682EBBE9D477D1A32AF958FC69B733B3761A3CA38014FD932D2482BC563A7`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\ItemObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ItemObjectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\PoolAllocatorStaticInstances.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\PoolAllocator.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\PoolAllocator.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\PoolAllocatorLayout.md --apply --queue-timeout 240
```
