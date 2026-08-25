<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\000173-ImageLibDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000173-ImageLibDestructor-source-quality.md](000173-ImageLibDestructor-source-quality.md)
- Source report SHA256 before cleanup: `3740C0774D860D418092FA4F5A39AED657EC6DCA727638C8FD97487405533C0B`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `205-216`
- Original language: `powershell`
- Block SHA256: `5A7D881274F9E6C384F76C2A6C460CE17F67C98EAD2BB29E351C164F9DA3AB29`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004d0070-0x004d011b.ImageLibDestructor.md --apply --queue-timeout 240 --wait-generated
python .\tools\validator.py --mode file --file by-class\ImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\ImageLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\ImageLibLayout.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-struct\ResourceLayoutNameRecord.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type\by-vtable\ImageLibVtable.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_pEPFLib.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067a744-0x0067a748.g_pEPFLib.md --apply --queue-timeout 240
```
