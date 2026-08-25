<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00005P-GenderButtonControlPane-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00005P-GenderButtonControlPane-class-source-quality.md](00005P-GenderButtonControlPane-class-source-quality.md)
- Source report SHA256 before cleanup: `22619C0595DDF8BAEF57D4DF86664F99DA095111DD2BA60AA1E05C52BFB57458`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `77-80`
- Original language: `powershell`
- Block SHA256: `F4049FBB8C4D410C8535A6AAB7D936E51B51973573A34D0C57BA3C52B80704D1`

```powershell
$body = @{jsonrpc='2.0'; id=1; method='tools/list'; params=@{}} | ConvertTo-Json -Depth 8
$r = Invoke-WebRequest -UseBasicParsing -Uri 'http://127.0.0.1:13337/mcp' -Method Post -ContentType 'application/json' -Headers @{Accept='application/json, text/event-stream'} -Body $body
```

## Removed Block R002

- Original source lines: `601-609`
- Original language: `powershell`
- Block SHA256: `92682EB53E2F52E318CAB2E46F8252E7D839CA57048079D83E7D650120AFD5B3`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-class\GenderButtonControlPane.md --apply --queue-timeout 240
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods.md --apply --queue-timeout 240
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor.md --apply --queue-timeout 240
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md --apply --queue-timeout 240
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-struct\SpecializedButtonPaneLayouts.md --apply --queue-timeout 240
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-vtable\SpecializedButtonPaneVtables.md --apply --queue-timeout 240
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-file\SpecializedButtonPanes.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `613-616`
- Original language: `powershell`
- Block SHA256: `703A876CE9D1905D7C78A321A8F06A6D1162808CA814793D3947E424357157AC`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-class\-coverage-report.md --apply --queue-timeout 240
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md --apply --queue-timeout 240
```
