<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0001C0-SharedDialogDefaultScalarDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001C0-SharedDialogDefaultScalarDestructor-source-quality.md](0001C0-SharedDialogDefaultScalarDestructor-source-quality.md)
- Source report SHA256 before cleanup: `758474F4BE53A9D8F5A3E2C463F1B5AEAFBA4A7C7DA67BED6B117840A0DA629D`
- Cleanup generated: `2026-08-11T12:47:12Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `300-304`
- Original language: `powershell`
- Block SHA256: `87909BFE264148B4412F67C43C1E0C5BA9DAE90449517337B31E7FED4A320B40`

```powershell
rg -n "sub_520B70|00520B70|00520aa5|005539c3|\\?\\?_7(MerchantDialogPane|ServerItemMenuDialog|ClientItemMenuDialog|ServerSpellMenuDialog|ClientSpellMenuDialog|ArgumentedMenuMenuDialog|PursuitMessageDialogPane|MessageDialog|MessageDialogLarger|MenuQuestionDialog|MenuQuestionDialogLarger|TextDialog|.*NexonclubProxyDialog)" C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS -g "*.lst" -g "*.map" -g "*.c"
rg -n "0x0049d9f0|OperatorDeleteWrapper|0x004f4ac0|0x00520b70|SharedDialogDefault" source-3/project-documentation/by-memory source-3/project-documentation/by-file source-3/project-documentation/by-type -g "*.md"
rg -n "0001C0|SharedDialogDefaultScalarDestructor" source-3/project-documentation/by-memory/-coverage-report.md source-3/project-documentation/auto-generated/-ag-memory-coverage.md
```
