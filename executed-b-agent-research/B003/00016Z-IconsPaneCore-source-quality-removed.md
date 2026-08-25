<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\00016Z-IconsPaneCore-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00016Z-IconsPaneCore-source-quality.md](00016Z-IconsPaneCore-source-quality.md)
- Source report SHA256 before cleanup: `ACAE94DEAE476E5BE2FC2F2732D42DC93E1D337362078A53890A72A58960CA72`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `501-506`
- Original language: `powershell`
- Block SHA256: `512ABCC03D48EDC3CA935F21501150E74C45D81BADF4749D3520BCB7F4D2D81B`

```powershell
rg -n "00016Z|004cf74b|004cf7a0|004cf8e0|28de32|IconsPaneCore" source-3/project-documentation
Get-Content -Raw -LiteralPath "source-3/project-documentation/by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md"
Get-Content -Raw -LiteralPath "source-3/project-documentation/by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md"
Get-Content -Raw -LiteralPath "source-3/project-documentation/auto-generated/NexusTK/ui/panels/IconsPane.cpp"
```

## Removed Block R002

- Original source lines: `510-523`
- Original language: `powershell`
- Block SHA256: `98AA3254E9D7307CA84D4C9984A323067590E5277DC6E025AE630333A2898335`

```powershell
# Use Python + capstone to parse PE sections, disassemble:
# 0x004cf3e0-0x004cf7d0, 0x004cf870-0x004cf974,
# and scan targets 0x004cf7a0 / 0x004cf8e0 for direct branch, VA pointer, and RVA pointer hits.
@'
import struct, hashlib
from pathlib import Path
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
path = Path(r"E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe")
data = path.read_bytes()
print(hashlib.md5(data).hexdigest())
# Parse PE sections, map VA to file offsets, disassemble/check ranges.
'@ | python -
```

## Removed Block R003

- Original source lines: `527-530`
- Original language: `powershell`
- Block SHA256: `412CDFBAA23A8FE8D637A2D2101BF8353AE03CD20E96F4BB30E0D272ACD19111`

```powershell
rg -n "00016Z|0x004cf74b|0x004cf7a0|IconsPaneBuildIconRect" source-3/project-documentation/by-memory source-3/project-documentation/auto-generated
rg -n "00016Z" source-3/project-documentation/by-memory/-coverage-report.md source-3/project-documentation/auto-generated/-ag-memory-coverage.md
```
