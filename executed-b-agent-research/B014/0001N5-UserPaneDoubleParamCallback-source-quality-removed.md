<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\0001N5-UserPaneDoubleParamCallback-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001N5-UserPaneDoubleParamCallback-source-quality.md](0001N5-UserPaneDoubleParamCallback-source-quality.md)
- Source report SHA256 before cleanup: `806DCE6AD59596DBF53725F880CFD809F9E59274387B9816A514082C80310AF7`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `527-529`
- Original language: `powershell`
- Block SHA256: `05EE40E695CE81F771A7DF631C8A7997124A036FD1AD609CBBB2EAE45765A957`

```powershell
Test-Path source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0001N5-UserPaneDoubleParamCallback-source-quality.md
```

## Removed Block R002

- Original source lines: `533-538`
- Original language: `powershell`
- Block SHA256: `1A7AF73C40D8C3C34E4D9F34B56004E17305D5E193F94DBE56CC786148B9EFF8`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md --apply
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md --apply
python source-3/project-documentation/tools/validator.py --mode autogen --apply
```

## Removed Block R003

- Original source lines: `542-545`
- Original language: `powershell`
- Block SHA256: `5A8E6CA435220353EFCD1B6FD9C27E61950CAFBB2A5C6C265C4112C759D9BCC9`

```powershell
rg -n "0001N5|0x005b77b0|0x00630a84|0x005ad7a0|0x005ad720|CreateUserPaneDoubleParamCallback" source-3/project-documentation/by-memory source-3/project-documentation/by-class source-3/project-documentation/by-file source-3/project-documentation/by-type
rg -n "0001N5" source-3/project-documentation/by-memory/-coverage-report.md source-3/project-documentation/auto-generated/-ag-memory-coverage.md source-3/project-documentation/project-level/-auto-completion-stats.md
```
