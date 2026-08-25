<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\0002NO-ClanInfoListPaneFalseAlternateVirtual-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

> NON-AUTHORITATIVE ARCHIVE. This companion must never be executed and receives no report, evidence, Gate, coverage, score, IDA, validator, or lifecycle credit.

- Source report: [0002NO-ClanInfoListPaneFalseAlternateVirtual-source-quality.md](0002NO-ClanInfoListPaneFalseAlternateVirtual-source-quality.md)
- Source report SHA256 before cleanup: `3B76AB2329B738B46B3700ABF000B938163D182F854ED199CC049604798FBA1C`
- Cleanup generated: `2026-08-11T12:47:15Z`
- Removed executable blocks: `13`
- Follow-up cleanup: `2026-08-12T20:29:53Z`; four transaction-oriented JSON blocks reintroduced into the active report were removed again without changing their substantive research meaning.
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Follow-Up Removed Request Fields (2026-08-13)

The active report later reintroduced the following historical request fields. They were removed again while their prestates, intended state changes, evidence, protections, and expected readbacks remained in structured non-executable form in the source report.

~~~text
declare_type(database="<GATE2B_DATABASE_SESSION_ID>", decls=["struct ClanInfoListPane { TextEditPane base; };"])

rename/type/comment requests for `0x00488620` targeting `ClanInfoListPane__OnMouseEvent`, prototype `bool __thiscall ClanInfoListPane__OnMouseEvent(ClanInfoListPane *this, Event *event)`, and regular function text `ClanInfoListPane primary OnMouseEvent override; intentionally returns false.`

rename/type/comment requests for `0x00488610` targeting `ClanInfoListPane__HandleKeyOrTextEvent`, prototype `bool __thiscall ClanInfoListPane__HandleKeyOrTextEvent(ClanInfoListPane *this, Event *event)`, and regular function text `ClanInfoListPane EventHandler secondary HandleKeyOrTextEvent override; intentionally returns false.`

set_address_comments(database="<GATE2B_DATABASE_SESSION_ID>", items=[{addr:"0x00615658",comment:"ClanInfoListPane primary slot +0x60: bool OnMouseEvent(Event *)."}])

set_address_comments(database="<GATE2B_DATABASE_SESSION_ID>", items=[{addr:"0x00615678",comment:"ClanInfoListPane EventHandler secondary slot +0x08: bool HandleKeyOrTextEvent(Event *)."}])
~~~

## Removed Block R001

- Original source lines: `349-374`
- Original language: `powershell`
- Block SHA256: `48CF1A2BEECBE20DE39CEA40E3D4BA0476E72CE199C6936CD811745C5E078E0A`

```powershell
function Get-WorkerGeneration([int]$Pid) {
    $p = Get-CimInstance Win32_Process -Filter "ProcessId=$Pid"
    if ($null -eq $p) { return $null }
    [pscustomobject]@{
        Pid = [int]$p.ProcessId
        StartUtc = $p.CreationDate.ToUniversalTime().ToString('o')
        ExecutablePath = [string]$p.ExecutablePath
        CommandLine = [string]$p.CommandLine
        ParentPid = [int]$p.ParentProcessId
    }
}
function Retire-ExactWorker($Generation) {
    $now = Get-WorkerGeneration $Generation.Pid
    if ($null -eq $now) { throw 'worker disappeared before controlled retirement' }
    foreach ($k in 'Pid','StartUtc','ExecutablePath','CommandLine','ParentPid') {
        if ($now.$k -ne $Generation.$k) { throw "worker generation mismatch: $k" }
    }
    Stop-Process -Id $Generation.Pid -Force
    try { Wait-Process -Id $Generation.Pid -Timeout 30 -ErrorAction Stop } catch { }
    $after = Get-WorkerGeneration $Generation.Pid
    if ($null -ne $after -and $after.StartUtc -eq $Generation.StartUtc) {
        throw 'original worker generation still present'
    }
}
```

## Removed Block R002

- Original source lines: `378-416`
- Original language: `powershell`
- Block SHA256: `8D7C96F82DEA64A6EE1BD03DA6F4C5C32E3A1944632969F2A36C4E8E5FC1F6B0`

```powershell
Add-Type @"
using System;
using System.Runtime.InteropServices;
using Microsoft.Win32.SafeHandles;
public static class B010FileTime {
  [StructLayout(LayoutKind.Sequential)] public struct FT { public uint Low; public uint High; }
  [DllImport("kernel32.dll", SetLastError=true)] public static extern bool GetFileTime(SafeFileHandle h, out FT c, out FT a, out FT w);
  [DllImport("kernel32.dll", SetLastError=true)] static extern bool SetFileTime(SafeFileHandle h, IntPtr c, IntPtr a, ref FT w);
  public static long ToInt64(FT f) { return ((long)f.High << 32) | f.Low; }
  public static void SetWrite(SafeFileHandle h, long value) {
    FT f; f.Low=(uint)(value & 0xffffffffL); f.High=(uint)((ulong)value >> 32);
    if (!SetFileTime(h, IntPtr.Zero, IntPtr.Zero, ref f)) throw new System.ComponentModel.Win32Exception();
  }
}
"@
function Get-ExclusiveIdentity([string]$Path) {
    $full = [IO.Path]::GetFullPath($Path)
    $fs = [IO.File]::Open($full,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
    try {
        $c=New-Object B010FileTime+FT; $a=New-Object B010FileTime+FT; $w=New-Object B010FileTime+FT
        if (-not [B010FileTime]::GetFileTime($fs.SafeFileHandle,[ref]$c,[ref]$a,[ref]$w)) { throw 'GetFileTime failed' }
        $ticks=[B010FileTime]::ToInt64($w)
        $sha=[Security.Cryptography.SHA256]::Create()
        try { $fs.Position=0; $hex=([BitConverter]::ToString($sha.ComputeHash($fs))).Replace('-','') } finally { $sha.Dispose() }
        [pscustomobject]@{ Path=$full; Length=[int64]$fs.Length; LastWriteFileTimeUtc=[int64]$ticks; LastWriteUtc=[DateTime]::FromFileTimeUtc($ticks).ToString('o'); SHA256=$hex }
    } finally { $fs.Dispose() }
}
function Set-ExclusiveWriteTime([string]$Path,[int64]$Ticks) {
    $fs=[IO.File]::Open([IO.Path]::GetFullPath($Path),[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
    try { [B010FileTime]::SetWrite($fs.SafeFileHandle,$Ticks) } finally { $fs.Dispose() }
}
function Test-SameIdentity($A,$B,[bool]$RequirePath=$true) {
    if ($RequirePath -and $A.Path -ne $B.Path) { return $false }
    return $A.Length -eq $B.Length -and
           $A.LastWriteFileTimeUtc -eq $B.LastWriteFileTimeUtc -and
           $A.SHA256 -eq $B.SHA256
}
```

## Removed Block R003

- Original source lines: `422-431`
- Original language: `powershell`
- Block SHA256: `EE1965B820E67B7A816457A383E74BC147FE298EDF3FFF30596D986C811EC26E`

```powershell
$Canonical='E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$Backup='E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0002NO-prestate-20260806-0830-r1'
if (Test-Path -LiteralPath $Backup) { throw 'concrete backup path collision' }
$P0=Get-ExclusiveIdentity $Canonical
Copy-Item -LiteralPath $Canonical -Destination $Backup -ErrorAction Stop
Set-ExclusiveWriteTime $Backup $P0.LastWriteFileTimeUtc
$B0=Get-ExclusiveIdentity $Backup
if (-not (Test-SameIdentity $P0 $B0 $false)) { throw 'B0 is not byte/time identical to P0' }
```

## Removed Block R004

- Original source lines: `527-541`
- Original language: `powershell`
- Block SHA256: `ABD52DB0F4990F3DB5DDB7EB5681949C9FEEE7E7F66EA0374A8293630E40E3C0`

```powershell
$Current=Get-ExclusiveIdentity $Canonical
if (Test-SameIdentity $Current $P0 $true) {
    $RestoredP0=$Current
} elseif (Test-SameIdentity $Current $LastOwned $true) {
    $B0Now=Get-ExclusiveIdentity $Backup
    if (-not (Test-SameIdentity $B0Now $P0 $false)) { throw 'B0 drift; no overwrite' }
    Copy-Item -LiteralPath $Backup -Destination $Canonical -Force -ErrorAction Stop
    Set-ExclusiveWriteTime $Canonical $P0.LastWriteFileTimeUtc
    $RestoredP0=Get-ExclusiveIdentity $Canonical
    if (-not (Test-SameIdentity $RestoredP0 $P0 $true)) { throw 'timestamp-restoring P0 rollback mismatch' }
} else {
    throw 'canonical identity is neither P0 nor last transaction-owned S1/F1; no overwrite'
}
```

## Removed Block R005

- Original source lines: `289-291`
- Original language: `json`
- Block SHA256: `498F329AE9716FFB7411721FE508FA1F145AFA4678CE4EA285E89680F12CCE29`

```json
{"jsonrpc":"2.0","id":21001,"method":"tools/list","params":{}}
```

## Removed Block R006

- Original source lines: `363-370`
- Original language: `json`
- Block SHA256: `745B5B2788B9C673964FEC079DDB601E208F4C33F70C9CAFA8114BEEA01CB672`

```json
[
  {"tool":"idb_open","arguments":{"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":false,"init_hexrays":false,"idle_ttl_sec":3600,"preferred_session_id":"b010-uid0002no-transaction-20260806-0830-r1"}},
  {"tool":"idb_open","arguments":{"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":false,"init_hexrays":false,"idle_ttl_sec":3600,"preferred_session_id":"b010-uid0002no-s1-verifier-20260806-0830-r1"}},
  {"tool":"idb_open","arguments":{"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":false,"init_hexrays":false,"idle_ttl_sec":3600,"preferred_session_id":"b010-uid0002no-p0-verifier-20260806-0830-r1"}},
  {"tool":"idb_open","arguments":{"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":false,"init_hexrays":false,"idle_ttl_sec":3600,"preferred_session_id":"b010-uid0002no-rollback-verifier-20260806-0830-r1"}}
]
```

## Removed Block R007

- Original source lines: `376-389`
- Original language: `json`
- Block SHA256: `B9DFC29C98AACBE143EC68678CC6176E088A16D9057A9C3EEA63C98F1634F7CD`

```json
[
  {"tool":"server_health","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1"}},
  {"tool":"type_query","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","queries":[{"filter":"ClanInfoListPane","kind":"udt","offset":0,"count":200,"include_decl":true,"include_members":true,"max_members":200}]}},
  {"tool":"type_inspect","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","queries":[{"name":"ClanInfoListPane","include_members":true,"max_members":200},{"name":"TextEditPane","include_members":true,"max_members":200},{"name":"Event","include_members":true,"max_members":200}]}},
  {"tool":"entity_query","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","queries":[{"kind":"functions","regex":"^ClanInfoListPane__OnMouseEvent$","offset":0,"count":200,"sort_by":"addr","descending":false},{"kind":"functions","regex":"^ClanInfoListPane__HandleKeyOrTextEvent$","offset":0,"count":200,"sort_by":"addr","descending":false}]}},
  {"tool":"lookup_funcs","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","queries":["0x00488610","0x00488620","0x00488630"]}},
  {"tool":"stack_frame","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","addrs":["0x00488610","0x00488620"]}},
  {"tool":"get_comments","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","addrs":["0x00488610","0x00488620","0x00615658","0x00615678"]}},
  {"tool":"inspect_items","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","addrs":["0x00488610","0x00488612","0x00488615","0x00488620","0x00488622","0x00488625","0x00488630","0x006155f4","0x006155f8","0x00615654","0x00615658","0x0061565c","0x0061566c","0x00615670","0x00615674","0x00615678","0x0061567c"]}},
  {"tool":"get_bytes","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","regions":[{"addr":"0x00488610","size":32},{"addr":"0x006155f4","size":120},{"addr":"0x0061566c","size":48},{"addr":"0x00615654","size":12},{"addr":"0x00615674","size":12}]}},
  {"tool":"xref_query","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","queries":[{"addr":"0x00488620","direction":"to","xref_type":"code","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00488620","direction":"to","xref_type":"data","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00488620","direction":"from","xref_type":"code","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00488610","direction":"to","xref_type":"code","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00488610","direction":"to","xref_type":"data","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00488610","direction":"from","xref_type":"code","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00615658","direction":"from","xref_type":"data","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00615678","direction":"from","xref_type":"data","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x006155f8","direction":"to","xref_type":"data","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00615670","direction":"to","xref_type":"data","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x006155f4","direction":"from","xref_type":"data","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0061566c","direction":"from","xref_type":"data","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}]}}
]
```

## Removed Block R008

- Original source lines: `405-419`
- Original language: `json`
- Block SHA256: `227898D5B052806E576444F9F3252C3B39623360F460DDF44F9AF144AA17DB52`

```json
[
  {"tool":"declare_type","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","decls":["struct ClanInfoListPane { TextEditPane base; };"]}},
  {"tool":"rename","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","batch":{"func":{"addr":"0x00488620","name":"ClanInfoListPane__OnMouseEvent"},"stop_on_error":true,"dry_run":true,"allow_overwrite":false,"pure":true}}},
  {"tool":"rename","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","batch":{"func":{"addr":"0x00488620","name":"ClanInfoListPane__OnMouseEvent"},"stop_on_error":true,"dry_run":false,"allow_overwrite":false,"pure":true}}},
  {"tool":"set_type","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","edits":{"addr":"0x00488620","kind":"function","signature":"bool __thiscall ClanInfoListPane__OnMouseEvent(ClanInfoListPane *this, Event *event)"}}},
  {"tool":"set_function_comments","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","items":{"addr":"0x00488620","comment":"ClanInfoListPane mouse-event override; intentionally returns false without consuming the event."}}},
  {"tool":"rename","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","batch":{"func":{"addr":"0x00488610","name":"ClanInfoListPane__HandleKeyOrTextEvent"},"stop_on_error":true,"dry_run":true,"allow_overwrite":false,"pure":true}}},
  {"tool":"rename","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","batch":{"func":{"addr":"0x00488610","name":"ClanInfoListPane__HandleKeyOrTextEvent"},"stop_on_error":true,"dry_run":false,"allow_overwrite":false,"pure":true}}},
  {"tool":"set_type","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","edits":{"addr":"0x00488610","kind":"function","signature":"bool __thiscall ClanInfoListPane__HandleKeyOrTextEvent(ClanInfoListPane *this, Event *event)"}}},
  {"tool":"set_function_comments","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","items":{"addr":"0x00488610","comment":"ClanInfoListPane key/text-event override; intentionally returns false without consuming the event."}}},
  {"tool":"set_address_comments","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","items":{"addr":"0x00615658","comment":"ClanInfoListPane primary slot +0x60: bool OnMouseEvent(Event *)."}}},
  {"tool":"set_address_comments","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","items":{"addr":"0x00615678","comment":"ClanInfoListPane EventHandler secondary slot +0x08: bool HandleKeyOrTextEvent(Event *)."}}}
]
```

## Removed Block R009

- Original source lines: `437-439`
- Original language: `json`
- Block SHA256: `FD973C328406502849A41B7263EEC2EF5B9D69A3CF64FCF9E2E7F3601F5CA48C`

```json
{"tool":"idb_save","arguments":{"database":"b010-uid0002no-transaction-20260806-0830-r1","path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"}}
```

## Removed Block R010

- Original source lines: `275-285`
- Original language: `json`
- Block SHA256: `5E10324A3734011A639E69F362279BB5079AAA4A56F2E48731AAFEA208174F65`

```json
[
  {"path":"C:\\Users\\admin\\.idapro\\idalib-mcp-venv\\Lib\\site-packages\\ida_pro_mcp\\ida_mcp\\api_modify.py","sha256":"161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8"},
  {"path":"C:\\Users\\admin\\.idapro\\idalib-mcp-venv\\Lib\\site-packages\\ida_pro_mcp\\ida_mcp\\api_types.py","bytes":37540,"sha256":"A3E7444BBAC0066B48EDF38E26F34E6ABEC823585CD50E43C6DA98C55B965ECF"},
  {"path":"C:\\Users\\admin\\.idapro\\idalib-mcp-venv\\Lib\\site-packages\\ida_pro_mcp\\ida_mcp\\utils.py","sha256":"5139910EA7496549A31EDD6F9EEE7B033DA16504E4F0D19C8052EC9ED1C62069"},
  {"path":"C:\\Users\\admin\\.idapro\\idalib-mcp-venv\\Lib\\site-packages\\ida_pro_mcp\\idalib_server.py","sha256":"06C922EEF3F2E6771308C687231FE443A65DADF340E72001C6B05B7FC70B2034"},
  {"path":"C:\\Users\\admin\\.idapro\\idalib-mcp-venv\\Lib\\site-packages\\ida_pro_mcp\\idalib_supervisor.py","sha256":"2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A"},
  {"path":"C:\\Users\\admin\\.idapro\\idalib-mcp-venv\\Lib\\site-packages\\ida_pro_mcp\\idalib_session_manager.py","sha256":"9EDEEBD47B6FF85F9809E7159CE03D3EF41833692D28AC4367C6C4E5CAE00890"},
  {"path":"C:\\Users\\admin\\.idapro\\idalib-mcp-venv\\Lib\\site-packages\\ida_pro_mcp\\ida_mcp\\api_core.py","sha256":"90C59B3F64F26E170CC604000CE39B34B648352767059DD1C2DF1914E9CBD4A3"}
]
```

## Removed Block R011

- Original source lines: `295-303`
- Original language: `json`
- Block SHA256: `6E13F4074F5C1B48576C1A21D8A3EA21882BE25F843272647FB16F672437A6DD`

```json
{
  "database_routing":{"accepted_field":"database","required_by_this_transaction":true,"type":"string"},
  "declare_type":{"tool_required":["decls"],"decls":"string-or-list-of-strings"},
  "set_type":{"tool_required":["edits"],"edits":"TypeEdit-or-list-of-TypeEdit","TypeEdit":{"schema_required":["addr"],"schema_optional":["ty","name","kind","signature","variable"],"transaction_required":["addr","kind","signature"],"transaction_kind":"function"}},
  "type_query":{"tool_required":["queries"],"queries":"TypeQuery-or-list-of-TypeQuery","TypeQuery":{"schema_optional":["filter","kind","offset","count","sort_by","descending","include_decl","include_members","max_members","include_relationships"],"kind_values":["any","struct","union","enum","typedef","func","ptr","udt"]}},
  "type_inspect":{"tool_required":["queries"],"queries":"TypeInspectQuery-or-list-of-TypeInspectQuery","TypeInspectQuery":{"schema_required":["name"],"schema_optional":["include_members","max_members"]}}
}
```

## Removed Block R012

- Original source lines: `314-322`
- Original language: `json`
- Block SHA256: `8FF9704C4137E0F3727F21821B4F65FFE461B2066A1AAB20CC39C60072C94885`

```json
{
  "P07_pre_type_query_absent":[{"kind":"udt","data":[],"next_offset":null,"total":0}],
  "P07_pre_type_inspect_absent":[{"name":"ClanInfoListPane","exists":false,"error":"Type not found: ClanInfoListPane"}],
  "I01_declare_type_success":[{"decl":"struct ClanInfoListPane { TextEditPane base; };"}],
  "I02_set_type_success":[{"edit":{"addr":"0x00488620","kind":"function","signature":"bool __thiscall ClanInfoListPane__OnMouseEvent(ClanInfoListPane *this, Event *event)"},"kind":"function","ok":true}],
  "I03_set_type_success":[{"edit":{"addr":"0x00488610","kind":"function","signature":"bool __thiscall ClanInfoListPane__HandleKeyOrTextEvent(ClanInfoListPane *this, Event *event)"},"kind":"function","ok":true}]
}
```

## Removed Block R013

- Original source lines: `330-339`
- Original language: `json`
- Block SHA256: `DD2BF2944577D13C5F589EF9ADD60DC6D2CB7798F703AA556240E19925A8B600`

```json
{
  "canonical_idb":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64",
  "backup":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64.bak-UID0002NO-prestate-20260806-0830-r1",
  "transaction_session":"b010-uid0002no-transaction-20260806-0830-r1",
  "s1_verifier_session":"b010-uid0002no-s1-verifier-20260806-0830-r1",
  "p0_verifier_session":"b010-uid0002no-p0-verifier-20260806-0830-r1",
  "rollback_verifier_session":"b010-uid0002no-rollback-verifier-20260806-0830-r1"
}
```
