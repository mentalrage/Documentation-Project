<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\00032C-PlainMemberFunctionObject0ApplicationGetObjectSize-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00032C-PlainMemberFunctionObject0ApplicationGetObjectSize-empty-emitter-source-quality.md](00032C-PlainMemberFunctionObject0ApplicationGetObjectSize-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `8765FA9106FD98AADE46EEBD406EB0FC6A27BB8CD96330AB140F02BEE97B8270`
- Cleanup generated: `2026-08-11T12:47:13Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `321-323`
- Original language: `powershell`
- Block SHA256: `490B8CA459B1806AD8161955914B65E1570540BF9E69EA702EB40C4D0F54A743`

```powershell
Select-String -Path auto-generated\NexusTK\util\FunctionObjects.cpp -Pattern "00032C|PlainMemberFunctionObject0<Application>|object-size virtual|Empty Emitter Marker" -Context 2,4
```
