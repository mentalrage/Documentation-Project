<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0001ZT-MsvcStlIostreamTemplateSupport-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001ZT-MsvcStlIostreamTemplateSupport-source-routing.md](0001ZT-MsvcStlIostreamTemplateSupport-source-routing.md)
- Source report SHA256 before cleanup: `B7A06D3387B76DF779A55928C28B2B16A52E95694E66A20E4503463929C279E5`
- Cleanup generated: `2026-08-11T12:47:09Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `257-263`
- Original language: `powershell`
- Block SHA256: `D78390CBE5C07E5F4F4D451C5E6A04FEE064D665B2F775A282237F469F4E8B5C`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
python tools/validator.py --mode file --file by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-meta/client_libraries.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-file/JsonCpp.md --apply --queue-timeout 240
```
