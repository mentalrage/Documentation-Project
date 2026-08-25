<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B012\00013G-EncoderWriteShort-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00013G-EncoderWriteShort-source-quality.md](00013G-EncoderWriteShort-source-quality.md)
- Source report SHA256 before cleanup: `BB5DFAA778F9C9F6DAC8234FF12867EB1EFCCF169153A1D17D276F0FB6E68B4D`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `507-516`
- Original language: `powershell`
- Block SHA256: `0020427CFAACF6773F7EE87F55211ED74A2C38ACE36D930B8FF59B75BC676D4F`

```powershell
python tools\validator.py --mode file --file by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md --apply
python tools\validator.py --mode file --file by-class/Encoder.md --apply
python tools\validator.py --mode file --file by-memory/0x004a4e70-0x004a5621.EncoderCore.md --apply
python tools\validator.py --mode file --file by-type/by-struct/BinaryCodecCursorLayout.md --apply
python tools\validator.py --mode file --file by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md --apply
python tools\validator.py --mode file --file by-item/EncodeTextEditState_0058E490.md --apply
python tools\validator.py --mode autogen --apply
rg -n "00013G|Encoder::WriteShort|WriteShort\\(unsigned short|sub_4A4F00|0x004a4f60" auto-generated/NexusTK/util/Encoder.cpp auto-generated/-ag-memory-coverage.md by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md by-class/Encoder.md by-memory/0x004a4e70-0x004a5621.EncoderCore.md
```
