<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality.md](0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality.md)
- Source report SHA256 before cleanup: `62ECFE683AA51BE9570B3A8ECA35FDA80EDF8D528CF9663DF1D87A10F1C8AC20`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `405-407`
- Original language: `powershell`
- Block SHA256: `673628A05B733F9A8F57FAB755678B5DCC53568D91A7A6FE67A7C8D8B71DFA05`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `413-415`
- Original language: `powershell`
- Block SHA256: `392641E97516ACC1EDE02917D1DE60A98414E61E1B090427C74A10DDAFEB832D`

```powershell
python .\tools\validator.py --mode file --file by-class\ChattingVarietySelectPane.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `421-423`
- Original language: `powershell`
- Block SHA256: `6DCC99C44963998492D75BE4DDA31BB3335C59BA3108A82A5DB3CD073E054834`

```powershell
python .\tools\validator.py --mode file --file by-file\Chatting.md --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `431-438`
- Original language: `powershell`
- Block SHA256: `E7D2E8635EF1AB6725DB5992F51C4312D8C7C3A97560A054E8D7CAF0EA643150`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_pChattingVarietySelectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00614cdc-0x00615284.ChattingVtableData.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md --apply --queue-timeout 240
```
