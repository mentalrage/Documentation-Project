<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\00018Z-InputPaneBaseAdjustorThunks-source-routing.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00018Z-InputPaneBaseAdjustorThunks-source-routing.md](00018Z-InputPaneBaseAdjustorThunks-source-routing.md)
- Source report SHA256 before cleanup: `7EB0FF59476DCD311184DEDBA49171954E97A5A64072D9F9ED4EE0983E80D01B`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `246-259`
- Original language: `powershell`
- Block SHA256: `E26C40AB944362719ED1273C0331E07A8357D661F6D7D0B15A5DCA6CC5E5A3B4`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md --apply --lock-timeout 180
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004f1c00-0x004f3017.InputPaneBases.md --apply --lock-timeout 180
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-type/by-vtable/InputPaneBaseVtableFamily.md --apply --lock-timeout 180
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md --apply --lock-timeout 180
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-file/InputPanes.md --apply --lock-timeout 180
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/LineInputPane.md --apply --lock-timeout 180
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/NumberInputPane.md --apply --lock-timeout 180
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/CharInputPane.md --apply --lock-timeout 180
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/ConfirmInputPane.md --apply --lock-timeout 180
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/CharArgsInputPane.md --apply --lock-timeout 180
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/NumberArgsInputPane.md --apply --lock-timeout 180
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/MultiLineInputPane.md --apply --lock-timeout 180
```

## Removed Block R002

- Original source lines: `263-265`
- Original language: `powershell`
- Block SHA256: `A56141C5F9F9A8E890F71DA2A1DF0B251FB56CB541285963F3C8780241E0C346`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/-coverage-report.md --apply --lock-timeout 180
```

## Removed Block R003

- Original source lines: `269-272`
- Original language: `powershell`
- Block SHA256: `16907AE110706F681200F876B4E6202AA3A7BC2AF7097BF45B12A3739523BBAF`

```powershell
rg -n "0x004f2e59-0x004f2e9a|0x004f2e9a-0x004f2ea0|virt_meth_0x4f2e59|virt_meth_0x4f2e64|virt_meth_0x4f2e6f|virt_meth_0x4f2e7a|virt_meth_0x4f2e85|virt_meth_0x4f2e90" source-3/project-documentation/by-memory source-3/project-documentation/by-class source-3/project-documentation/by-file source-3/project-documentation/by-type
rg -n "00018Z|0x004f2e59-0x004f2e9b" source-3/project-documentation/by-memory source-3/project-documentation/by-class source-3/project-documentation/by-file source-3/project-documentation/by-type
```
