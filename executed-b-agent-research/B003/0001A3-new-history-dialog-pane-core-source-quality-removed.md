<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0001A3-new-history-dialog-pane-core-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001A3-new-history-dialog-pane-core-source-quality.md](0001A3-new-history-dialog-pane-core-source-quality.md)
- Source report SHA256 before cleanup: `B5876B49D98A1D0A64869E8956617192A05E390079B656CB6A735CB490373E93`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `317-321`
- Original language: `powershell`
- Block SHA256: `4A97EDD5163B22370699CA908E38BE7B0F3E6DB74562074C0CBE4195CECE4795`

```powershell
rg -n "UID:0001A3|UID:0001PV" source-3/project-documentation/by-memory/-coverage-report.md
rg -n "g_pMainMenuPane|mouse down/up|0x00500410|dword_69B36C|g_pMainUiGraph" source-3/project-documentation/by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md source-3/project-documentation/by-class/NewHistoryDialogPane.md source-3/project-documentation/by-file/NewHistoryDialogPane.md
Get-Item source-3/project-documentation/auto-generated/NexusTK/login/NewHistoryDialogPane.cpp | Select-Object FullName,Length
```

## Removed Block R002

- Original source lines: `334-349`
- Original language: `powershell`
- Block SHA256: `FDA737A4E587C2BA5003DA581B3FD3C3F68E171304769B8C8C90953309DA8545`

```powershell
$path='E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe'
$bytes=[IO.File]::ReadAllBytes($path)
foreach($addr in 0x00500410,0x005005c0,0x00500610,0x005023e0,0x00502920){
  $pat=[BitConverter]::GetBytes([uint32]$addr)
  $hits=New-Object System.Collections.Generic.List[int]
  $start=0
  while($true){
    $i=[Array]::IndexOf($bytes,$pat[0],$start)
    if($i -lt 0 -or $i -gt $bytes.Length-4){break}
    if($bytes[$i+1] -eq $pat[1] -and $bytes[$i+2] -eq $pat[2] -and $bytes[$i+3] -eq $pat[3]){[void]$hits.Add($i)}
    $start=$i+1
  }
  [pscustomobject]@{Address=('0x{0:x8}' -f $addr); Count=$hits.Count; RawOffsets=(($hits | ForEach-Object { '0x{0:x}' -f $_ }) -join ',')}
}
```
