<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002VN-newhuman-scalar-deleting-destructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002VN-newhuman-scalar-deleting-destructor-source-quality.md](0002VN-newhuman-scalar-deleting-destructor-source-quality.md)
- Source report SHA256 before cleanup: `CCD5BFCB43AFCC1EB4919838BFB0BDF234AB0222744681122B233207A001C0B2`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `235-254`
- Original language: `powershell`
- Block SHA256: `744C481DFC1C23AFA244D3832BC57B95D36208F845D8A6896FDE99101AC8D64B`

```powershell
rg -n "0002VN|0x004e6870|NewHumanImageLibScalarDeletingDestructor" `
  "tools/leaser/Agents" -g "*.md"

# IDA MCP tools via http://127.0.0.1:13337/mcp, session b003_00018a_ime_comp_20260617:
server_health
lookup_funcs 0x004e6870 0x004e68a7 0x004e68a8 0x004e68b0 0x004e0250 0x004f4ac0 0x0041b6a0 0x004f4a90
disasm 0x004e6870
decompile 0x004e6870
analyze_function 0x004e6870
xrefs_to 0x004e6870 0x004e0250 0x0061b76c 0x0067a760
get_bytes 0x004e6860 80; get_bytes 0x004e6870 56; get_bytes 0x004e68a8 16
get_int 0x0061b768/0x0061b76c/0x0061b770/0x0061b774 u32le
make_signature_for_range 0x004e6870 0x004e68a8 wildcard_operands=false
entity_query functions 0x004e6400-0x004e6b00
list_globals *NewHumanImageLib*

# Raw PE scan performed against E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe:
# scanned exact wrapper bytes, VA/RVA pointer hits, vtable pointer stores, RTTI pointer, and rel32 E8/E9 edges.
```

## Removed Block R002

- Original source lines: `258-263`
- Original language: `powershell`
- Block SHA256: `70627E83C1FCE7CFE23B510348F871AFFA16D3DE5D615377F3658BDBBC506A27`

```powershell
Set-Location E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md --apply --queue-timeout 240 --lock-timeout -1
python .\tools\validator.py --mode rescore --apply --queue-timeout 240 --lock-timeout -1
python .\tools\memory_ranges.py -advanced-scan report
```

## Removed Block R003

- Original source lines: `267-270`
- Original language: `powershell`
- Block SHA256: `D3D761EA406AB117BE132FFAA27CD0489096ACEEA6595196A410309B6B556407`

```powershell
Set-Location E:\NTK\GhidraBridge\source-3\project-documentation
python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1
```
