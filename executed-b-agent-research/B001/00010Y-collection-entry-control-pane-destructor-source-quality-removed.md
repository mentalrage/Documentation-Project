<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\00010Y-collection-entry-control-pane-destructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00010Y-collection-entry-control-pane-destructor-source-quality.md](00010Y-collection-entry-control-pane-destructor-source-quality.md)
- Source report SHA256 before cleanup: `5D493FE7F6D1DE36AFC157EC5C9DCF0954EF53EC0A80AF2C043C4E30EE2A6D83`
- Cleanup generated: `2026-08-11T12:46:56Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `396-405`
- Original language: `powershell`
- Block SHA256: `B0E74B543DE5041B76DD6F19574B228398BA1087B9D0CEF4278ACB2C0507A0B0`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-class\CollectionEntryControlPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-file\CollectionDialogPane.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x0048c640-0x0048e305.CollectionDialogControls.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\0x006164f0-0x006168d0.CollectionReadOnlyData.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
python .\tools\memory_ranges.py report
```

## Removed Block R002

- Original source lines: `409-433`
- Original language: `powershell`
- Block SHA256: `6C979DC009708D3917D7FA35ECCD025BE96F3B75B27B7C9D03F2F33F2D9E6C1F`

```powershell
@'
from pathlib import Path
import struct

path = Path(r"E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe")
data = path.read_bytes()
target_va = 0x0048d480
target_rva = target_va - 0x00400000
scalar_va = 0x0048e2b0
scalar_rva = scalar_va - 0x00400000

for name, value in [("target_va", target_va), ("target_rva", target_rva), ("scalar_va", scalar_va), ("scalar_rva", scalar_rva)]:
    needle = struct.pack("<I", value)
    hits = []
    start = 0
    while True:
        off = data.find(needle, start)
        if off < 0:
            break
        hits.append(off)
        start = off + 1
    print(f"{name}=0x{value:08x} hits:", [f"0x{x:x}" for x in hits])
'@ | python -
```
