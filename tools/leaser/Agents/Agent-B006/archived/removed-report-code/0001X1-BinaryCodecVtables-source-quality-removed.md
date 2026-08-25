<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\0001X1-BinaryCodecVtables-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001X1-BinaryCodecVtables-source-quality.md](0001X1-BinaryCodecVtables-source-quality.md)
- Source report SHA256 before cleanup: `AFBD97642326A34E87714E6923384067E9AF050285E08DC3D18BD04DBB8673A1`
- Cleanup generated: `2026-08-11T12:47:11Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `388-396`
- Original language: `powershell`
- Block SHA256: `17952DA2F9E09EB3FB335181198BF67962CC34F3F4BA3B53144B8A962847C388`

```powershell
python source-3/project-documentation/tools/validator.py --path source-3/project-documentation/by-type/by-vtable/BinaryCodecVtables.md
python source-3/project-documentation/tools/validator.py --path source-3/project-documentation/by-file/BinaryCodec.md
python source-3/project-documentation/tools/validator.py --path source-3/project-documentation/by-type/by-struct/BinaryCodecCursorLayout.md
python source-3/project-documentation/tools/validator.py --path source-3/project-documentation/by-class/Encoder.md
python source-3/project-documentation/tools/validator.py --path source-3/project-documentation/by-class/Decoder.md
python source-3/project-documentation/tools/validator.py --path source-3/project-documentation/by-file/Encoder.md
python source-3/project-documentation/tools/validator.py --path source-3/project-documentation/by-file/Decoder.md
```

## Removed Block R002

- Original source lines: `400-402`
- Original language: `powershell`
- Block SHA256: `2EEF5D5BDF4189EF8CA9CED1C2F1CB10E5969871A3170586B0F54CB02994C11C`

```powershell
rg -n "0001X1|BinaryCodecVtables|006192e0|EncoderNoopVirtual|DecoderNoopVirtual" source-3/project-documentation/auto-generated source-3/project-documentation/project-level source-3/project-documentation/by-type source-3/project-documentation/by-memory
```
