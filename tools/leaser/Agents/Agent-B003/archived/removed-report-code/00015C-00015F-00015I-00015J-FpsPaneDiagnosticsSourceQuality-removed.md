<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality.md](00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality.md)
- Source report SHA256 before cleanup: `78F2AC40E431AF669F6FDBF8B2BA9007F5AE15A5C69C923A85C54CCBAC0F242E`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `4`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `66-69`
- Original language: `powershell`
- Block SHA256: `3F256D3E64FE0D6E99ADE1C11C4B6B590F546FE093C328CB2697F8D33BD5F7E6`

```powershell
$body = @{jsonrpc='2.0'; id=1; method='tools/list'; params=@{}} | ConvertTo-Json -Depth 8
Invoke-WebRequest -UseBasicParsing -Uri 'http://127.0.0.1:13337/mcp' -Method Post -ContentType 'application/json' -Headers @{Accept='application/json, text/event-stream'} -Body $body -TimeoutSec 10
```

## Removed Block R002

- Original source lines: `74-77`
- Original language: `powershell`
- Block SHA256: `33AE3611345F8E464708EE8722469D2F75019753EE3232907EE0CA00FBEA8F00`

```powershell
rg --files 'C:\Users\admin\Desktop\CTools' | rg -i 'NexusTK\.exe$|client.*\.exe$|baram.*\.exe$'
rg --files 'E:\NTK\GhidraBridge' | rg -i 'NexusTK\.exe$|client.*\.exe$|baram.*\.exe$'
```

## Removed Block R003

- Original source lines: `193-197`
- Original language: `powershell`
- Block SHA256: `D60BEF6687BA576F6DDF2BE9FB29C677372FEA135FE23D4BCDEC2CCB84F958BE`

```powershell
$enc = [System.Text.Encoding]::GetEncoding(949)
$enc.GetString($bytes1)
$enc.GetString($bytes2)
```

## Removed Block R004

- Original source lines: `517-521`
- Original language: `powershell`
- Block SHA256: `73C1AB7BA5B41E6DF6CDA22566EF33719B9481D78B7A3D6970ACAE1536E3D44E`

```powershell
rg -n "4B6410|4B64A0|4B69B0|4B6AE0|004B6410|004B64A0|004B69B0|004B6AE0" "C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst"
rg -n "0069B334|0069B338|69B334|69B338|dword_69B334|byte_69B338|0066DA90|66DA90|dword_66DA90" "C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst"
Select-String -LiteralPath "C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst" -Pattern ".data:0066DA90",".data:0069B334",".data:0069B338" -SimpleMatch -Context 2,2
```
