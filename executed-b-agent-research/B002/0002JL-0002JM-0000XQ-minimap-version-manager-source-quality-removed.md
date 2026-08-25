<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0002JL-0002JM-0000XQ-minimap-version-manager-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002JL-0002JM-0000XQ-minimap-version-manager-source-quality.md](0002JL-0002JM-0000XQ-minimap-version-manager-source-quality.md)
- Source report SHA256 before cleanup: `4AF60EFF9457AFE3D3403E5FEC78DD882F3032553DAE2B52C6FEF024D72E3D7C`
- Cleanup generated: `2026-08-11T12:47:02Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `326-338`
- Original language: `powershell`
- Block SHA256: `7423CE08998F168B64B309573A7928B0BC85B0DBA80B9C4D08FB902CB6A51705`

```powershell
python tools/validator.py --mode file --file by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md --apply
python tools/validator.py --mode file --file by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md --apply
python tools/validator.py --mode file --file by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md --apply
python tools/validator.py --mode file --file by-class/MiniMapVersionManager.md --apply
python tools/validator.py --mode file --file by-file/MiniMapVersionManager.md --apply
python tools/validator.py --mode file --file by-memory/0x004563c0-0x00457547.MiniMapVersionManager.md --apply
python tools/validator.py --mode file --file by-type/by-struct/MiniMapVersionNode.md --apply
python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply
python tools/memory_ranges.py report
python tools/validator.py --mode autogen --apply --lock-timeout -1
python tools/validator.py --mode rescore --apply --lock-timeout -1
```
