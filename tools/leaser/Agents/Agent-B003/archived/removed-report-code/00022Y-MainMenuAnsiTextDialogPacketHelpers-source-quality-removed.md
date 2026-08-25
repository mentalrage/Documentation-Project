<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\00022Y-MainMenuAnsiTextDialogPacketHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00022Y-MainMenuAnsiTextDialogPacketHelpers-source-quality.md](00022Y-MainMenuAnsiTextDialogPacketHelpers-source-quality.md)
- Source report SHA256 before cleanup: `BD398B99BDD9319C40966894EF63BEA87FB5068A53BD6C0575CC9E985C70EBB0`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `617-619`
- Original language: `powershell`
- Block SHA256: `82EFC2AD11E1702E7BEE4474E7E9D742351AE1EAE301F4640277BCEA3D9A3E81`

```powershell
python tools/validator.py --mode file --file by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md
```

## Removed Block R002

- Original source lines: `627-633`
- Original language: `powershell`
- Block SHA256: `4D48AB1F84BF9476A45CEF471673C76F727B8F8F3F5A149BC7028C9768F77743`

```powershell
python tools/validator.py --mode file --file by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md
python tools/validator.py --mode file --file by-file/MainMenuPane.md
python tools/validator.py --mode file --file by-class/MainMenuPane.md
python tools/validator.py --mode file --file by-memory/-coverage-report.md
python tools/validator.py --mode all
```

## Removed Block R003

- Original source lines: `637-640`
- Original language: `powershell`
- Block SHA256: `77A943B6F2D9FC9651039B963C96074CFACF0D14AC4C92943211ABABCEB95877`

```powershell
rg -n "PreparePatchLaunch_502E10|HandleAnsiTextDialogPacket_502E30|MainMenuTextUrlStaticString|0x00502e10|0x00502e30" source-3/project-documentation
rg -n "00022Y|0x00502e10-0x0050305c" source-3/project-documentation/by-memory/-coverage-report.md source-3/project-documentation/project-level/-auto-completion-stats.md
```
