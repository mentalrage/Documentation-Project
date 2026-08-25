<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\0001KS-QuitInputPaneCore-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001KS-QuitInputPaneCore-source-quality.md](0001KS-QuitInputPaneCore-source-quality.md)
- Source report SHA256 before cleanup: `AF77448B28FFB7DDF9423838BBE06AF006436343526629F4451DBFFF72E0D54A`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `776-778`
- Original language: `powershell`
- Block SHA256: `9CBE8251511ECF278EB8A93E9C952B9F4854063EACB2ED784741568916A58B5B`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md"
```

## Removed Block R002

- Original source lines: `782-790`
- Original language: `powershell`
- Block SHA256: `95DAB2E8FBC0484778F8F589E33D99A75F62C23E4BC6E73E31AC2BCF7AA6D48F`

```powershell
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md" --apply
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md" --apply
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md" --apply
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-class/QuitInputPane.md" --apply
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-file/QuitDialogs.md" --apply
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-global/g_pQuitInputPane.md" --apply
python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md" --apply
```
