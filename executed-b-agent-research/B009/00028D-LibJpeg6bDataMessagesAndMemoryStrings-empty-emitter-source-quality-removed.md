<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B009\research\00028D-LibJpeg6bDataMessagesAndMemoryStrings-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00028D-LibJpeg6bDataMessagesAndMemoryStrings-empty-emitter-source-quality.md](00028D-LibJpeg6bDataMessagesAndMemoryStrings-empty-emitter-source-quality.md)
- Source report SHA256 before archive-link insertion: `7FFBD8F5C84BEE482D6FCD7BD191DFAB7328CD0FA43A5C7F86682F5CCB2A2F40`
- Recovery generated: `2026-08-09T22:17:53Z`
- Unique recovered executable blocks: `6`
- Recovered executable bytes: `153336`
- Recovery basis: report-path-associated Codex session history. The source report had already removed its executable packages before the supervisor could extract them directly.
- Scope: this archive preserves every unique recoverable report-local executable block, including superseded historical variants where session history retained more than the final pre-removal report.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- SHA256: `6FD106311619C13E0D06FE3952375B26D6076610951852B88E2B2A44DE28AB0E`
- Language: `powershell`
- Bytes: `2624`
- First recovered timestamp: `2026-08-06T10:24:48.643Z`
- Session provenance: rollout-2026-08-03T16-16-22-019fc945-3035-79d3-b7f4-ee6afdc9cad4.jsonl line 187638 (2026-08-06T10:24:48.643Z); rollout-2026-08-03T16-16-22-019fc945-3035-79d3-b7f4-ee6afdc9cad4.jsonl line 187639 (2026-08-06T10:24:48.708Z)

~~~powershell
# Inputs are supervisor-bound exact values, never inferred from stale registry rows.
$canonical = [IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
$recordedPid = [int]$W.Pid
$recordedCreation = [string]$W.CreationDate
$recordedImage = [string]$W.ExecutablePath
$recordedCommand = [string]$W.CommandLine
$samePid = Get-CimInstance Win32_Process -Filter "ProcessId=$recordedPid" -ErrorAction SilentlyContinue
if ($samePid -and (([string]$samePid.CreationDate -eq $recordedCreation) -or ([string]$samePid.ExecutablePath -eq $recordedImage -and [string]$samePid.CommandLine -eq $recordedCommand))) { throw 'recorded worker still exists' }
if ($samePid -and -not $recordedCreation) { throw 'PID reuse is ambiguous' }
# Issue the literal idb_list MCP request above and require zero is_active:true rows whose normalized input_path equals $canonical.
$fs = [IO.File]::Open($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
try {
  $fullPath = [IO.Path]::GetFullPath($canonical)
  $size = [Int64]$fs.Length
  $ticks = [IO.File]::GetLastWriteTimeUtc($canonical).Ticks
  $sha = [Security.Cryptography.SHA256]::Create()
  try { $sha256 = [BitConverter]::ToString($sha.ComputeHash($fs)).Replace('-','') } finally { $sha.Dispose() }
} finally { $fs.Dispose() }
$tuple = [pscustomobject]@{Path=$fullPath;Size=$size;SHA256=$sha256;LastWriteTimeUtcTicks=[Int64]$ticks}
if ($Expected -and ($tuple.Path -cne $Expected.Path -or $tuple.Size -ne $Expected.Size -or $tuple.SHA256 -cne $Expected.SHA256 -or $tuple.LastWriteTimeUtcTicks -ne $Expected.LastWriteTimeUtcTicks)) { throw 'closed-file tuple mismatch' }

$stamp = [DateTime]::UtcNow.ToString('yyyyMMddTHHmmssfffffffZ')
$b0 = Join-Path (Split-Path -LiteralPath $canonical -Parent) ("NexusTK.exe.i64.$stamp.UID00028D.B0")
if (Test-Path -LiteralPath $b0) { throw 'B0 collision' }
if (@(Get-ChildItem -LiteralPath (Split-Path -LiteralPath $b0 -Parent) -Force | Where-Object Name -CEQ (Split-Path -Leaf $b0)).Count -ne 0) { throw 'B0 basename collision' }
[IO.File]::Copy($canonical,$b0,$false)
# Reopen B0 with FileShare.None, hash it, and require path/size/SHA256/ticks equal P0 before continuing.

# Guarded restore is legal only after CFP proves the current tuple is this transaction's exact S1/F1/I1 and B0 still equals P0.
[IO.File]::Copy($b0,$canonical,$true)
[IO.File]::SetLastWriteTimeUtc($canonical,[DateTime]::new([Int64]$P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
# Run a fresh CFP with FileShare.None and require canonical path, size, SHA256, and LastWriteTimeUtcTicks exactly equal P0 before OPEN(Wverify-restore).
~~~

## Removed Block R002

- SHA256: `38EEBB44DD0A9870A9D2EC83E2B96A6DCBD57E8365C6BDF27FCE1782B33CF6B8`
- Language: `powershell`
- Bytes: `21685`
- First recovered timestamp: `2026-08-06T22:53:15.901Z`
- Session provenance: rollout-2026-08-06T18-23-46-019fd92c-e7fb-7013-873a-d7414f0f3109.jsonl line 193983 (2026-08-06T22:53:15.901Z); rollout-2026-08-06T18-23-46-019fd92c-e7fb-7013-873a-d7414f0f3109.jsonl line 193984 (2026-08-06T22:53:15.969Z)

~~~powershell
$ErrorActionPreference = 'Stop'
$Uid00028dEndpoint = [Uri]'http://127.0.0.1:13337/mcp'
$Uid00028dCanonical = [IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
$Uid00028dSourceRoot = [IO.Path]::GetFullPath('C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp')

function Get-UID00028DProcessGeneration([string]$Role,[int]$ProcessIdValue) {
  $rows = @(Get-CimInstance Win32_Process -Filter "ProcessId=$ProcessIdValue")
  if ($rows.Count -ne 1) { throw "$Role process identity is missing or ambiguous" }
  $p = Get-Process -Id $ProcessIdValue -ErrorAction Stop
  $exe = (Resolve-Path -LiteralPath ([string]$rows[0].ExecutablePath)).Path
  [pscustomobject]@{
    Role=$Role; Pid=[int]$rows[0].ProcessId; ParentPid=[int]$rows[0].ParentProcessId
    CreationUtcTicks=([DateTime]$rows[0].CreationDate).ToUniversalTime().Ticks
    StartTimeUtc=$p.StartTime.ToUniversalTime().ToString('o')
    ExecutablePath=$exe; ExecutableSHA256=(Get-FileHash -LiteralPath $exe -Algorithm SHA256).Hash.ToUpperInvariant()
    CommandLine=[string]$rows[0].CommandLine
  }
}

function Get-UID00028DListenerRoute {
  $sockets = @(Get-NetTCPConnection -State Listen -ErrorAction Stop | Where-Object { $_.LocalAddress -eq '127.0.0.1' -and $_.LocalPort -eq 13337 })
  if ($sockets.Count -ne 1) { throw "expected one 127.0.0.1:13337 listener, found $($sockets.Count)" }
  $L2 = Get-UID00028DProcessGeneration 'L2-base-python-socket-owner' ([int]$sockets[0].OwningProcess)
  $L1 = Get-UID00028DProcessGeneration 'L1-venv-python' $L2.ParentPid
  $L0 = Get-UID00028DProcessGeneration 'L0-idalib-mcp-root' $L1.ParentPid
  if ($L1.ParentPid -ne $L0.Pid -or $L2.ParentPid -ne $L1.Pid) { throw 'L0 -> L1 -> L2 parent edges do not close' }
  if ([DateTime]$L0.StartTimeUtc -gt [DateTime]$L1.StartTimeUtc -or [DateTime]$L1.StartTimeUtc -gt [DateTime]$L2.StartTimeUtc) { throw 'listener generation start order is impossible' }
  if ([IO.Path]::GetFileName($L0.ExecutablePath) -cne 'idalib-mcp.exe') { throw 'L0 is not the root idalib-mcp.exe console entry' }
  $scriptsRoot = Split-Path -Parent $L0.ExecutablePath
  $venvRoot = Split-Path -Parent $scriptsRoot
  $consoleEntry = (Resolve-Path -LiteralPath (Join-Path $scriptsRoot 'idalib-mcp.exe')).Path
  $venvPython = (Resolve-Path -LiteralPath (Join-Path $scriptsRoot 'python.exe')).Path
  $pyvenvCfg = (Resolve-Path -LiteralPath (Join-Path $venvRoot 'pyvenv.cfg')).Path
  $home = [regex]::Match((Get-Content -Raw -LiteralPath $pyvenvCfg),'(?im)^home\s*=\s*(.+?)\s*$')
  if (-not $home.Success) { throw 'pyvenv.cfg does not define one base-Python home' }
  $basePython = (Resolve-Path -LiteralPath (Join-Path $home.Groups[1].Value.Trim() 'python.exe')).Path
  if ($L0.ExecutablePath -cne $consoleEntry -or $L1.ExecutablePath -cne $venvPython -or $L2.ExecutablePath -cne $basePython) { throw 'L0/L1/L2 executable route mismatch' }
  foreach ($g in @($L0,$L1,$L2)) {
    if ([string]::IsNullOrWhiteSpace($g.CommandLine) -or $g.CommandLine -notmatch '(?i)(?<!\S)--host(?:\s+|=)127\.0\.0\.1(?=\s|$)' -or $g.CommandLine -notmatch '(?i)(?<!\S)--port(?:\s+|=)13337(?=\s|$)') { throw "$($g.Role) full command does not bind the authorized endpoint" }
  }
  $routeSockets = @(Get-NetTCPConnection -State Listen -ErrorAction Stop | Where-Object { $_.OwningProcess -in @($L0.Pid,$L1.Pid,$L2.Pid) })
  if (@($routeSockets | Where-Object OwningProcess -eq $L0.Pid).Count -ne 0 -or @($routeSockets | Where-Object OwningProcess -eq $L1.Pid).Count -ne 0) { throw 'L0 or L1 unexpectedly owns a listening socket' }
  $l2Sockets = @($routeSockets | Where-Object OwningProcess -eq $L2.Pid)
  if ($l2Sockets.Count -ne 1 -or $l2Sockets[0].LocalAddress -ne '127.0.0.1' -or $l2Sockets[0].LocalPort -ne 13337) { throw 'L2 is not the sole authorized socket owner' }
  [pscustomobject]@{L0=$L0;L1=$L1;L2=$L2;VenvRoot=$venvRoot;VenvPython=$venvPython;BasePython=$basePython;SourceRoot=$Uid00028dSourceRoot;Socket='127.0.0.1:13337'}
}

function Write-UID00028DNewDurableUtf8([string]$Path,[string]$Text) {
  $bytes = [Text.UTF8Encoding]::new($false).GetBytes($Text)
  $stream = [IO.FileStream]::new($Path,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None)
  try { $stream.Write($bytes,0,$bytes.Length); $stream.Flush($true) } finally { $stream.Dispose() }
  if ([IO.File]::ReadAllBytes($Path).Length -ne $bytes.Length) { throw "durable script length mismatch: $Path" }
}

function Get-UID00028DListenerAttestation($Route) {
  $nonce = [Guid]::NewGuid().ToString('N')
  $scriptPath = [IO.Path]::Combine([IO.Path]::GetTempPath(),"UID00028D-listener-$nonce.py")
  $outputPath = [IO.Path]::Combine([IO.Path]::GetTempPath(),"UID00028D-listener-$nonce.json")
  if (Test-Path -LiteralPath $scriptPath -PathType Any -or Test-Path -LiteralPath $outputPath -PathType Any) { throw 'listener attestation path collision' }
  $scriptText = @"
import ctypes, hashlib, json, os, pathlib, sys
expected_root = pathlib.Path(r"$Uid00028dSourceRoot").resolve()
expected = {
    "ida_pro_mcp.idalib_supervisor": (expected_root / "idalib_supervisor.py", 52468, "2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A"),
    "ida_pro_mcp.idalib_session_manager": (expected_root / "idalib_session_manager.py", 7032, "9EDEEBD47B6FF85F9809E7159CE03D3EF41833692D28AC4367C6C4E5CAE00890"),
    "ida_pro_mcp.worker_lifecycle": (expected_root / "worker_lifecycle.py", 3273, "303A2A15BB316CD2200B2C54EF8685EBBC50EF5114FDD1FBC6C16CD01B6BAC63"),
}
rows = []
for name, (wanted_path, wanted_size, wanted_sha) in expected.items():
    module = sys.modules.get(name)
    if module is None or not getattr(module, "__file__", None):
        raise RuntimeError("required listener module was not already loaded: " + name)
    path = pathlib.Path(module.__file__).resolve(strict=True)
    size = path.stat().st_size
    sha = hashlib.sha256(path.read_bytes()).hexdigest().upper()
    if path != wanted_path.resolve() or size != wanted_size or sha != wanted_sha or expected_root not in path.parents:
        raise RuntimeError("listener loaded-module identity mismatch: " + name)
    rows.append({"module": name, "loaded_path": str(path), "size": size, "sha256": sha, "object_id": id(module)})
kernel32 = ctypes.windll.kernel32
kernel32.GetCommandLineW.restype = ctypes.c_wchar_p
record = {"nonce": "$nonce", "pid": os.getpid(), "ppid": os.getppid(), "sys_executable": str(pathlib.Path(sys.executable).resolve()), "base_executable": str(pathlib.Path(getattr(sys, "_base_executable", sys.executable)).resolve()), "command_line": kernel32.GetCommandLineW(), "source_root": str(expected_root), "modules": rows}
with pathlib.Path(r"$outputPath").open("x", encoding="utf-8", newline="\n") as stream:
    json.dump(record, stream, sort_keys=True, separators=(",", ":"))
    stream.write("\n")
    stream.flush()
    os.fsync(stream.fileno())
"@
  $parse = @($scriptText | & $Route.BasePython -c 'import ast,sys; ast.parse(sys.stdin.read())' 2>&1)
  if ($LASTEXITCODE -ne 0) { throw ('listener attestation script parse failed: ' + ($parse -join "`n")) }
  Write-UID00028DNewDurableUtf8 $scriptPath $scriptText
  $remote = @(& $Route.BasePython -c 'import sys; sys.remote_exec(int(sys.argv[1]), sys.argv[2])' ([string]$Route.L2.Pid) $scriptPath 2>&1)
  if ($LASTEXITCODE -ne 0) { throw ('listener in-process attestation failed: ' + ($remote -join "`n")) }
  $deadline = [DateTime]::UtcNow.AddSeconds(10)
  while (-not (Test-Path -LiteralPath $outputPath -PathType Leaf) -and [DateTime]::UtcNow -lt $deadline) { Start-Sleep -Milliseconds 50 }
  if (-not (Test-Path -LiteralPath $outputPath -PathType Leaf)) { throw 'listener attestation output was not created' }
  $record = [IO.File]::ReadAllText($outputPath,[Text.Encoding]::UTF8) | ConvertFrom-Json -Depth 100
  if ($record.nonce -cne $nonce -or [int]$record.pid -ne $Route.L2.Pid -or [int]$record.ppid -ne $Route.L1.Pid -or $record.sys_executable -ine $Route.VenvPython -or $record.base_executable -ine $Route.BasePython -or $record.command_line -cne $Route.L2.CommandLine -or $record.source_root -ine $Route.SourceRoot -or @($record.modules).Count -ne 3) { throw 'listener in-process attestation does not bind exact L2/source root' }
  [pscustomobject]@{Nonce=$nonce;ScriptPath=$scriptPath;ScriptSHA256=(Get-FileHash -LiteralPath $scriptPath -Algorithm SHA256).Hash.ToUpperInvariant();OutputPath=$outputPath;OutputSHA256=(Get-FileHash -LiteralPath $outputPath -Algorithm SHA256).Hash.ToUpperInvariant();Record=$record}
}

function Get-UID00028DListenerPackage {
  $route = Get-UID00028DListenerRoute
  $attestation = Get-UID00028DListenerAttestation $route
  [pscustomobject]@{Route=$route;Attestation=$attestation}
}

function Assert-UID00028DListenerPackage($Actual,$Expected) {
  foreach ($name in @('L0','L1','L2')) {
    foreach ($field in @('Pid','ParentPid','CreationUtcTicks','StartTimeUtc','ExecutablePath','ExecutableSHA256','CommandLine')) {
      if ($Actual.Route.$name.$field -cne $Expected.Route.$name.$field) { throw "listener route drift: $name.$field" }
    }
  }
  $actualRows = @($Actual.Attestation.Record.modules | ForEach-Object { "$($_.module)|$($_.loaded_path)|$($_.size)|$($_.sha256)" })
  $expectedRows = @($Expected.Attestation.Record.modules | ForEach-Object { "$($_.module)|$($_.loaded_path)|$($_.size)|$($_.sha256)" })
  if (($actualRows -join "`n") -cne ($expectedRows -join "`n")) { throw 'listener loaded-module set drift' }
}

function New-UID00028DMcpTransport {
  $headers = @{Accept='application/json, text/event-stream'}
  $body = [ordered]@{jsonrpc='2.0';id=1;method='initialize';params=[ordered]@{protocolVersion='2025-06-18';capabilities=@{};clientInfo=[ordered]@{name='UID00028D-Gate2B';version='1.0'}}} | ConvertTo-Json -Depth 30 -Compress
  $response = Invoke-WebRequest -UseBasicParsing -Method Post -Uri $Uid00028dEndpoint -Headers $headers -ContentType 'application/json' -Body $body
  $envelope = $response.Content | ConvertFrom-Json -Depth 100
  $sessionHeader = [string]$response.Headers['mcp-session-id']
  if ([string]::IsNullOrWhiteSpace($sessionHeader) -or $envelope.result.serverInfo.name -cne 'ida-pro-mcp') { throw 'MCP initialize did not return the required transport/session identity' }
  $headers['mcp-session-id'] = $sessionHeader
  $initialized = [ordered]@{jsonrpc='2.0';method='notifications/initialized'} | ConvertTo-Json -Compress
  [void](Invoke-WebRequest -UseBasicParsing -Method Post -Uri $Uid00028dEndpoint -Headers $headers -ContentType 'application/json' -Body $initialized)
  [pscustomobject]@{Headers=$headers;NextId=2;InitializeRaw=[string]$response.Content;Initialize=$envelope}
}

function Invoke-UID00028DMcpToolRaw($Transport,[string]$Name,$Arguments) {
  if ([string]::IsNullOrWhiteSpace($Name) -or $null -eq $Arguments) { throw 'tool name/arguments missing' }
  $id = [int]$Transport.NextId
  $Transport.NextId = $id + 1
  $request = [ordered]@{jsonrpc='2.0';id=$id;method='tools/call';params=[ordered]@{name=$Name;arguments=$Arguments}}
  $requestJson = $request | ConvertTo-Json -Depth 100 -Compress
  $null = $requestJson | ConvertFrom-Json -Depth 100
  $response = Invoke-WebRequest -UseBasicParsing -Method Post -Uri $Uid00028dEndpoint -Headers $Transport.Headers -ContentType 'application/json' -Body $requestJson
  $envelope = $response.Content | ConvertFrom-Json -Depth 100
  if ($envelope.id -ne $id -or $null -ne $envelope.error -or $envelope.result.isError -eq $true) { throw "MCP tool failed or response ID drifted: $Name" }
  [pscustomobject]@{Name=$Name;RequestRaw=$requestJson;Raw=[string]$response.Content;Envelope=$envelope}
}

function Get-UID00028DWorkerRoute($ListenerRoute,$SessionRow) {
  if ($SessionRow.worker_pid -isnot [ValueType] -or [int]$SessionRow.worker_pid -le 0) { throw 'returned session lacks a valid worker_pid' }
  $W0 = Get-UID00028DProcessGeneration 'W0-returned-venv-worker' ([int]$SessionRow.worker_pid)
  if ($W0.ParentPid -ne $ListenerRoute.L2.Pid -or $W0.ExecutablePath -cne $ListenerRoute.VenvPython -or $W0.CommandLine -notmatch '(?i)(?<!\S)-m\s+ida_pro_mcp\.idalib_server(?=\s|$)') { throw 'returned W0 does not descend from L2 through the required server module route' }
  $portMatch = [regex]::Match($W0.CommandLine,'(?i)(?<!\S)--port(?:\s+|=)(\d+)(?=\s|$)')
  if (-not $portMatch.Success) { throw 'W0 command has no unique worker port' }
  $workerPort = [int]$portMatch.Groups[1].Value
  $children = @(Get-CimInstance Win32_Process -Filter "ParentProcessId=$($W0.Pid)" | Where-Object { [string]$_.CommandLine -match '(?i)(?<!\S)-m\s+ida_pro_mcp\.idalib_server(?=\s|$)' })
  if ($children.Count -ne 1) { throw 'W0 does not have one exact W1 server child' }
  $W1 = Get-UID00028DProcessGeneration 'W1-base-python-worker-socket-owner' ([int]$children[0].ProcessId)
  if ($W1.ParentPid -ne $W0.Pid -or $W1.ExecutablePath -cne $ListenerRoute.BasePython -or $W1.CommandLine -cne $W0.CommandLine) { throw 'W0 -> W1 worker generation/command mismatch' }
  $workerSockets = @(Get-NetTCPConnection -State Listen -ErrorAction Stop | Where-Object { $_.OwningProcess -in @($W0.Pid,$W1.Pid) })
  if ($workerSockets.Count -ne 1 -or $workerSockets[0].OwningProcess -ne $W1.Pid -or $workerSockets[0].LocalAddress -ne '127.0.0.1' -or $workerSockets[0].LocalPort -ne $workerPort) { throw 'W1 is not the sole owner of the exact worker socket' }
  [pscustomobject]@{W0=$W0;W1=$W1;Port=$workerPort;Socket="127.0.0.1:$workerPort"}
}

$UID00028DWorkerAttestationCode = @'
import ctypes, hashlib, json, os, pathlib, sys
root = pathlib.Path(r'C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp').resolve()
expected = {
 'ida_pro_mcp.idalib_server':(root/'idalib_server.py',9848,'06C922EEF3F2E6771308C687231FE443A65DADF340E72001C6B05B7FC70B2034'),
 'ida_pro_mcp.idalib_session_manager':(root/'idalib_session_manager.py',7032,'9EDEEBD47B6FF85F9809E7159CE03D3EF41833692D28AC4367C6C4E5CAE00890'),
 'ida_pro_mcp.worker_lifecycle':(root/'worker_lifecycle.py',3273,'303A2A15BB316CD2200B2C54EF8685EBBC50EF5114FDD1FBC6C16CD01B6BAC63'),
 'ida_pro_mcp.ida_mcp.api_modify':(root/'ida_mcp'/'api_modify.py',51759,'161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8'),
 'ida_pro_mcp.ida_mcp.api_stack':(root/'ida_mcp'/'api_stack.py',5502,'9E4B5898E875812E4C993597D44F0F6438430F92A8B2299DC5C62630D49AE1BB'),
 'ida_pro_mcp.ida_mcp.api_types':(root/'ida_mcp'/'api_types.py',37540,'A3E7444BBAC0066B48EDF38E26F34E6ABEC823585CD50E43C6DA98C55B965ECF'),
 'ida_pro_mcp.ida_mcp.api_core':(root/'ida_mcp'/'api_core.py',34004,'90C59B3F64F26E170CC604000CE39B34B648352767059DD1C2DF1914E9CBD4A3'),
 'ida_pro_mcp.ida_mcp.api_analysis':(root/'ida_mcp'/'api_analysis.py',79961,'4C9B9122A7D2697CD464C1F473A227A580FD803515A1C885A1AA262259F1969F'),
 'ida_pro_mcp.ida_mcp.api_memory':(root/'ida_mcp'/'api_memory.py',9583,'A2D4E48921E2E7A8D3C4BD621658F645A9C17C7FB34E963E62AE864E452ABC93'),
 'ida_pro_mcp.ida_mcp.api_python':(root/'ida_mcp'/'api_python.py',8445,'BAD1BA09FCAED053F0CE0AB58C239788ABD7F148C04CE4FEBC6285A14ADBF516')}
rows=[]
for name,(wanted_path,wanted_size,wanted_sha) in expected.items():
 m=sys.modules.get(name)
 if m is None or not getattr(m,'__file__',None): raise RuntimeError('required worker module was not already loaded: '+name)
 path=pathlib.Path(m.__file__).resolve(strict=True); size=path.stat().st_size; sha=hashlib.sha256(path.read_bytes()).hexdigest().upper()
 if path!=wanted_path.resolve() or size!=wanted_size or sha!=wanted_sha or root not in path.parents: raise RuntimeError('worker loaded-module identity mismatch: '+name)
 rows.append({'module':name,'loaded_path':str(path),'size':size,'sha256':sha,'object_id':id(m)})
k=ctypes.windll.kernel32; k.GetCommandLineW.restype=ctypes.c_wchar_p
result=json.dumps({'pid':os.getpid(),'ppid':os.getppid(),'sys_executable':str(pathlib.Path(sys.executable).resolve()),'base_executable':str(pathlib.Path(getattr(sys,'_base_executable',sys.executable)).resolve()),'command_line':k.GetCommandLineW(),'source_root':str(root),'modules':rows},sort_keys=True,separators=(',',':'))
'@

function Open-UID00028DRole($Transport,$ListenerBaseline,[string]$Role) {
  if ($Role -notmatch '^[A-Za-z0-9-]{1,48}$') { throw 'invalid role name' }
  $listenerNow = Get-UID00028DListenerPackage
  Assert-UID00028DListenerPackage $listenerNow $ListenerBaseline
  $preWorkerPids = @(Get-CimInstance Win32_Process -Filter "ParentProcessId=$($listenerNow.Route.L2.Pid)" | ForEach-Object { [int]$_.ProcessId })
  $preferred = "uid00028d-$($Role.ToLowerInvariant())-$([DateTime]::UtcNow.ToString('yyyyMMddTHHmmssfffffffZ'))-$([Guid]::NewGuid().ToString('N'))"
  $openStarted = [DateTime]::UtcNow
  $openArguments = [ordered]@{input_path=$Uid00028dCanonical;mode='force_headless';run_auto_analysis=$false;build_caches=$false;init_hexrays=$false;idle_ttl_sec=600;preferred_session_id=$preferred}
  $open = Invoke-UID00028DMcpToolRaw $Transport 'idb_open' $openArguments
  $session = $open.Envelope.result.structuredContent.session
  $database = [string]$session.session_id
  if ($open.Envelope.result.structuredContent.success -ne $true -or [string]::IsNullOrWhiteSpace($database) -or $database -notmatch '^[A-Za-z0-9._-]{1,128}$') { throw 'idb_open did not return an authoritative structuredContent.session.session_id' }
  if ([IO.Path]::GetFullPath([string]$session.input_path) -ine $Uid00028dCanonical -or $session.is_analyzing -ne $false) { throw 'returned idb_open session/path/state mismatch' }
  $list = Invoke-UID00028DMcpToolRaw $Transport 'idb_list' @{}
  $rows = @($list.Envelope.result.structuredContent.sessions | Where-Object { [string]$_.session_id -ceq $database })
  if ($rows.Count -ne 1 -or $rows[0].is_active -ne $true -or $rows[0].is_analyzing -ne $false -or $rows[0].backend -cne 'worker' -or $rows[0].owned -ne $true -or [IO.Path]::GetFullPath([string]$rows[0].input_path) -ine $Uid00028dCanonical) { throw 'idb_list failed to corroborate the returned session/path/worker exactly' }
  $worker = Get-UID00028DWorkerRoute $listenerNow.Route $rows[0]
  if ($worker.W0.Pid -in $preWorkerPids -or [DateTime]$worker.W0.StartTimeUtc -lt $openStarted.AddSeconds(-1)) { throw 'OPEN(role) returned a pre-existing worker generation' }
  $attest = Invoke-UID00028DMcpToolRaw $Transport 'py_eval' ([ordered]@{code=$UID00028DWorkerAttestationCode;database=$database})
  if (-not [string]::IsNullOrEmpty([string]$attest.Envelope.result.structuredContent.stderr)) { throw 'worker loaded-module attestation wrote stderr' }
  $workerRecord = ([string]$attest.Envelope.result.structuredContent.result) | ConvertFrom-Json -Depth 100
  if ([int]$workerRecord.pid -ne $worker.W1.Pid -or [int]$workerRecord.ppid -ne $worker.W0.Pid -or $workerRecord.sys_executable -ine $listenerNow.Route.VenvPython -or $workerRecord.base_executable -ine $listenerNow.Route.BasePython -or $workerRecord.command_line -cne $worker.W1.CommandLine -or $workerRecord.source_root -ine $listenerNow.Route.SourceRoot -or @($workerRecord.modules).Count -ne 10) { throw 'worker in-process loaded-module attestation does not bind exact W1' }
  [pscustomobject]@{Role=$Role;PreferredSessionId=$preferred;Database=$database;OpenResponseRaw=$open.Raw;OpenResponse=$open.Envelope;IdbListResponseRaw=$list.Raw;SessionRow=$rows[0];Worker=$worker;WorkerAttestationRaw=$attest.Raw;WorkerAttestation=$workerRecord;Listener=$listenerNow}
}

function Resolve-UID00028DRoleCatalog($Role,[string]$CatalogText,[int]$ExpectedCount) {
  if ([string]::IsNullOrWhiteSpace($Role.Database) -or [string]::IsNullOrWhiteSpace($Role.OpenResponseRaw)) { throw 'role lacks exact returned-session authority' }
  $lines = @($CatalogText -split "`r?`n" | Where-Object { -not [string]::IsNullOrWhiteSpace($_) })
  if ($lines.Count -ne $ExpectedCount) { throw "catalog count mismatch: expected $ExpectedCount, got $($lines.Count)" }
  $resolved = [Collections.Generic.List[object]]::new()
  foreach ($line in $lines) {
    $request = $line | ConvertFrom-Json -Depth 100
    if ([string]::IsNullOrWhiteSpace([string]$request.name) -or $null -eq $request.arguments) { throw 'catalog row lacks name/arguments' }
    $serialized = $request | ConvertTo-Json -Depth 100 -Compress
    if ($request.name -ceq 'idb_list') {
      if ($request.arguments.PSObject.Properties.Name -contains 'database') { throw 'idb_list must remain unbound corroboration' }
    } else {
      if ($request.arguments.database -cne '__ROLE_DATABASE__' -or [regex]::Matches($serialized,'__ROLE_DATABASE__').Count -ne 1) { throw "catalog row has a missing, duplicate, preferred, or synthesized database token: $($request.name)" }
      $request.arguments.database = [string]$Role.Database
    }
    $finalJson = $request | ConvertTo-Json -Depth 100 -Compress
    if ($finalJson -match '<[^>]+>|__[A-Z0-9_]+__|\[CURRENT_CLEAN_SESSION\]' -or ($request.name -cne 'idb_list' -and $request.arguments.database -cne $Role.Database)) { throw "unresolved or cross-role database token: $($request.name)" }
    $final = $finalJson | ConvertFrom-Json -Depth 100
    $resolved.Add([pscustomobject]@{Name=[string]$final.name;Arguments=$final.arguments;Json=$finalJson;Role=[string]$Role.Role;Database=[string]$Role.Database})
  }
  return ,$resolved.ToArray()
}

function Invoke-UID00028DRoleRequest($Transport,$Role,$ResolvedRequest) {
  if ($ResolvedRequest.Role -cne $Role.Role -or $ResolvedRequest.Database -cne $Role.Database -or ($ResolvedRequest.Name -cne 'idb_list' -and $ResolvedRequest.Arguments.database -cne $Role.Database)) { throw 'stale or cross-role resolved request' }
  Invoke-UID00028DMcpToolRaw $Transport $ResolvedRequest.Name $ResolvedRequest.Arguments
}

$UID00028DListener0 = Get-UID00028DListenerPackage
$UID00028DTransport = New-UID00028DMcpTransport
~~~

## Removed Block R003

- SHA256: `077950D297739AFA4B35F12730CE4A0A59A5B8B7D406D5964481EF1775A4036F`
- Language: `powershell`
- Bytes: `1993`
- First recovered timestamp: `2026-08-06T22:53:38.900Z`
- Session provenance: rollout-2026-08-06T18-23-46-019fd92c-e7fb-7013-873a-d7414f0f3109.jsonl line 193988 (2026-08-06T22:53:38.900Z)

~~~powershell
$UID00028DCommonCatalogJsonLines = @'
{"name":"idb_list","arguments":{}}
{"name":"server_health","arguments":{"database":"__ROLE_DATABASE__"}}
{"name":"type_query","arguments":{"database":"__ROLE_DATABASE__","queries":[{"filter":"/^jpeg_common_struct$/i","kind":"any","count":20,"include_decl":true,"include_members":true,"max_members":200,"include_relationships":true},{"filter":"/^jpeg_error_mgr$/i","kind":"any","count":20,"include_decl":true,"include_members":true,"max_members":200,"include_relationships":true},{"filter":"/^j_common_ptr$/i","kind":"any","count":20,"include_decl":true,"include_members":true,"max_members":200,"include_relationships":true}]}}
{"name":"type_inspect","arguments":{"database":"__ROLE_DATABASE__","queries":[{"name":"jpeg_common_struct","include_members":true,"max_members":200},{"name":"jpeg_error_mgr","include_members":true,"max_members":200},{"name":"j_common_ptr","include_members":true,"max_members":200}]}}
{"name":"entity_query","arguments":{"database":"__ROLE_DATABASE__","queries":[{"kind":"names","regex":"^jpeg_std_message_table$","offset":0,"count":10,"sort_by":"addr","fields":["addr","name","segment"]},{"kind":"names","regex":"^jpeg_std_message_table(?:$|_.*)$","offset":0,"count":20,"sort_by":"addr","fields":["addr","name","segment"]}]}}
{"name":"inspect_items","arguments":{"database":"__ROLE_DATABASE__","addrs":["0x0063165c","0x00631660","0x0063184c","0x00631850","0x00631854"]}}
{"name":"get_comments","arguments":{"database":"__ROLE_DATABASE__","addrs":["0x0063165c","0x00631660","0x0063184c","0x00631850","0x00631854"]}}
{"name":"xrefs_to","arguments":{"database":"__ROLE_DATABASE__","addrs":["0x0063165c","0x00631660","0x0063184c","0x00631850","0x00631854"],"limit":1000}}
{"name":"get_bytes","arguments":{"database":"__ROLE_DATABASE__","regions":[{"addr":"0x00631650","size":32},{"addr":"0x00631840","size":32}]}}
'@
# For each role: $common = Resolve-UID00028DRoleCatalog $Role $UID00028DCommonCatalogJsonLines 9
~~~

## Removed Block R004

- SHA256: `8B1908A2BB00E67FF2A1DACC38117FDC1F0F003DE1CEFD6188FDF322D26A2E25`
- Language: `powershell`
- Bytes: `38272`
- First recovered timestamp: `2026-08-07T01:19:57.794Z`
- Session provenance: rollout-2026-08-06T18-23-46-019fd92c-e7fb-7013-873a-d7414f0f3109.jsonl line 195576 (2026-08-07T01:19:57.794Z); rollout-2026-08-06T18-23-46-019fd92c-e7fb-7013-873a-d7414f0f3109.jsonl line 195577 (2026-08-07T01:19:57.850Z)

~~~powershell
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
$UID00028DHostileFixtureCount = 38
$UID00028DImmutableContractSHA256 = '__UID00028D_IMMUTABLE_CONTRACT_SHA256__'

function Skip-UID00028DJsonWhitespace([string]$Text,[int]$Index) {
  while($Index -lt $Text.Length -and [char]::IsWhiteSpace($Text[$Index])){$Index++}
  $Index
}

function Read-UID00028DJsonStringEnd([string]$Text,[int]$Start) {
  if($Start -ge $Text.Length -or $Text[$Start] -cne '"'){throw 'JSON string expected'}
  $i=$Start+1
  while($i -lt $Text.Length){
    $c=$Text[$i]
    if($c -ceq '"'){return $i+1}
    if([int][char]$c -lt 0x20){throw 'JSON string contains a control character'}
    if($c -ceq '\'){
      $i++;if($i -ge $Text.Length){throw 'JSON string has a truncated escape'}
      if($Text[$i] -ceq 'u'){
        if($i+4 -ge $Text.Length -or $Text.Substring($i+1,4) -notmatch '^[0-9A-Fa-f]{4}$'){throw 'JSON string has an invalid unicode escape'}
        $i+=4
      }elseif('"\/bfnrt'.IndexOf($Text[$i]) -lt 0){throw 'JSON string has an invalid escape'}
    }
    $i++
  }
  throw 'JSON string is unterminated'
}

function Read-UID00028DJsonValueEnd([string]$Text,[int]$Start) {
  $Start=Skip-UID00028DJsonWhitespace $Text $Start
  if($Start -ge $Text.Length){throw 'JSON value missing'}
  $first=$Text[$Start]
  if($first -ceq '"'){return Read-UID00028DJsonStringEnd $Text $Start}
  if($first -ceq '{' -or $first -ceq '['){
    $stack=[Collections.Generic.Stack[char]]::new();$stack.Push($(if($first -ceq '{'){'}'}else{']'}));$i=$Start+1
    while($i -lt $Text.Length){
      $c=$Text[$i]
      if($c -ceq '"'){$i=Read-UID00028DJsonStringEnd $Text $i;continue}
      if($c -ceq '{'){$stack.Push('}')}elseif($c -ceq '['){$stack.Push(']')}elseif($c -ceq '}' -or $c -ceq ']'){
        if($stack.Count -eq 0 -or $stack.Pop() -cne $c){throw 'JSON nesting mismatch'}
        if($stack.Count -eq 0){return $i+1}
      }
      $i++
    }
    throw 'JSON value is unterminated'
  }
  $match=[regex]::Match($Text.Substring($Start),'^(?:true|false|null|-?(?:0|[1-9][0-9]*)(?:\.[0-9]+)?(?:[eE][+-]?[0-9]+)?)')
  if(-not $match.Success){throw 'JSON scalar token invalid'}
  $Start+$match.Length
}

function Get-UID00028DStrictJsonRootMembers([string]$Raw) {
  $i=Skip-UID00028DJsonWhitespace $Raw 0
  if($i -ge $Raw.Length -or $Raw[$i] -cne '{'){throw 'JSON-RPC response root is not an object'}
  $i++;$members=[Collections.Generic.List[object]]::new();$names=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal);$i=Skip-UID00028DJsonWhitespace $Raw $i
  if($i -lt $Raw.Length -and $Raw[$i] -ceq '}'){$i++;$i=Skip-UID00028DJsonWhitespace $Raw $i;if($i -ne $Raw.Length){throw 'JSON trailing data'};return ,$members.ToArray()}
  while($true){
    $i=Skip-UID00028DJsonWhitespace $Raw $i;$keyStart=$i;$keyEnd=Read-UID00028DJsonStringEnd $Raw $keyStart
    $name=[string]($Raw.Substring($keyStart,$keyEnd-$keyStart)|ConvertFrom-Json -ErrorAction Stop)
    if(-not $names.Add($name)){throw "JSON-RPC duplicate top-level member: $name"}
    $i=Skip-UID00028DJsonWhitespace $Raw $keyEnd;if($i -ge $Raw.Length -or $Raw[$i] -cne ':'){throw 'JSON object member lacks colon'}
    $i=Skip-UID00028DJsonWhitespace $Raw ($i+1);$valueStart=$i;$valueEnd=Read-UID00028DJsonValueEnd $Raw $valueStart
    $members.Add([pscustomobject]@{Name=$name;RawValue=$Raw.Substring($valueStart,$valueEnd-$valueStart)})
    $i=Skip-UID00028DJsonWhitespace $Raw $valueEnd;if($i -ge $Raw.Length){throw 'JSON object is unterminated'}
    if($Raw[$i] -ceq '}'){$i++;break};if($Raw[$i] -cne ','){throw 'JSON object member separator missing'};$i++
  }
  $i=Skip-UID00028DJsonWhitespace $Raw $i;if($i -ne $Raw.Length){throw 'JSON trailing data'}
  return ,$members.ToArray()
}

function ConvertFrom-UID00028DExactJsonRpc([string]$Raw,[Int64]$ExpectedId) {
  if([string]::IsNullOrWhiteSpace($Raw)){throw 'JSON-RPC response is empty'}
  $members=@(Get-UID00028DStrictJsonRootMembers $Raw);$names=@($members|ForEach-Object Name|Sort-Object)
  if(($names -join '|') -cne 'id|jsonrpc|result'){throw 'JSON-RPC response must contain exactly id, jsonrpc, and result'}
  $map=@{};foreach($member in $members){$map[$member.Name]=$member.RawValue}
  $version=$map.jsonrpc|ConvertFrom-Json -ErrorAction Stop
  if($version -isnot [string] -or [string]$version -cne '2.0'){throw 'JSON-RPC version/type mismatch'}
  if([string]$map.id -cnotmatch '^-?(?:0|[1-9][0-9]*)$'){throw 'JSON-RPC response ID JSON type mismatch'}
  [Int64]$actualId=0
  if(-not [Int64]::TryParse([string]$map.id,[Globalization.NumberStyles]::AllowLeadingSign,[Globalization.CultureInfo]::InvariantCulture,[ref]$actualId) -or $actualId -ne $ExpectedId){throw "JSON-RPC response ID value mismatch: expected $ExpectedId"}
  $Raw|ConvertFrom-Json -ErrorAction Stop
}

function Get-UID00028DOptionalProperty($Object,[string]$Name) {
  if($null -eq $Object){return [pscustomobject]@{Present=$false;Value=$null}}
  $property=$Object.PSObject.Properties[$Name]
  [pscustomobject]@{Present=($null -ne $property);Value=$(if($null -ne $property){$property.Value}else{$null})}
}

function Assert-UID00028DResultOnlyEnvelope($Envelope,[string]$Name,[bool]$IsSave) {
  $error=Get-UID00028DOptionalProperty $Envelope error;$result=Get-UID00028DOptionalProperty $Envelope result
  if($error.Present -or -not $result.Present){throw "MCP envelope result/error shape mismatch: $Name"}
  $isError=Get-UID00028DOptionalProperty $result.Value isError
  if(-not $IsSave -and $isError.Present -and $isError.Value -eq $true){throw "MCP tool returned error: $Name"}
  $result.Value
}

function Invoke-UID00028DMcpToolRaw($Coordinator,[string]$Role,[string]$Name,$Arguments) {
  if($Name -ceq 'idb_save'){
    Start-UID00028DSaveAttempt $Coordinator
    try{$call=Invoke-UID00028DJsonRpcRaw $Coordinator $Role 'tools/call' ([ordered]@{name=$Name;arguments=$Arguments})}
    catch{$Coordinator.SaveState='indeterminate';return [pscustomobject]@{Name=$Name;RequestId=$null;RequestRaw=$null;Raw=$null;Envelope=$null;TransportException=$_.Exception.Message}}
  }else{$call=Invoke-UID00028DJsonRpcRaw $Coordinator $Role 'tools/call' ([ordered]@{name=$Name;arguments=$Arguments})}
  Assert-UID00028DResultOnlyEnvelope $call.Envelope $Name ($Name -ceq 'idb_save')|Out-Null
  [pscustomobject]@{Name=$Name;RequestId=$call.RequestId;RequestRaw=$call.RequestRaw;Raw=$call.Raw;Envelope=$call.Envelope;TransportException=$null}
}

function Resolve-UID00028DRoleCatalog($Role,[string]$CatalogText,[int]$ExpectedCount) {
  if([string]::IsNullOrWhiteSpace($Role.Database) -or [string]::IsNullOrWhiteSpace($Role.OpenResponseRaw)){throw 'role lacks exact returned-session authority'}
  $lines=@($CatalogText -split '[\r\n]+'|Where-Object{-not [string]::IsNullOrWhiteSpace($_)})
  if($lines.Count -ne $ExpectedCount){throw "catalog count mismatch: expected $ExpectedCount, got $($lines.Count)"}
  $resolved=[Collections.Generic.List[object]]::new()
  foreach($line in $lines){
    $request=$line|ConvertFrom-Json -ErrorAction Stop
    if([string]::IsNullOrWhiteSpace([string]$request.name) -or $null -eq $request.arguments){throw 'catalog row lacks name/arguments'}
    if($request.name -ceq 'idb_list'){
      if($null -ne $request.arguments.PSObject.Properties['database']){throw 'idb_list must remain unbound corroboration'}
    }else{
      $databaseProperty=$request.arguments.PSObject.Properties['database']
      if($null -eq $databaseProperty -or [string]$databaseProperty.Value -cne '__ROLE_DATABASE__'){throw "catalog row database token mismatch: $($request.name)"}
      $request.arguments.database=[string]$Role.Database
    }
    $finalJson=$request|ConvertTo-Json -Depth 100 -Compress
    if($finalJson -match '<[^>]+>|__[A-Z0-9_]+__|\[CURRENT_CLEAN_SESSION\]'){throw "unresolved catalog token: $($request.name)"}
    $final=$finalJson|ConvertFrom-Json -ErrorAction Stop
    $resolved.Add([pscustomobject]@{Name=[string]$final.name;Arguments=$final.arguments;Json=$finalJson;Role=[string]$Role.Role;Database=[string]$Role.Database})
  }
  return ,$resolved.ToArray()
}

$script:UID00028DLegacyPhysicalContractBuilder=${function:New-UID00028DAuthoritativePhysicalContract}
function New-UID00028DAuthoritativePhysicalContract([string]$ReportPath) {
  $mutable=&$script:UID00028DLegacyPhysicalContractBuilder $ReportPath
  if([string]$mutable.ContractSHA256 -cne ($UID00028DReportContractReference -split ':',2)[1]){throw 'physical report-register identity mismatch'}
  $canonical=$mutable|ConvertTo-Json -Depth 100 -Compress;$hash=Get-UID00028DSha256Text $canonical
  if($hash -cne $UID00028DImmutableContractSHA256){throw "immutable physical-contract hash mismatch: $hash"}
  [pscustomobject]@{CanonicalJson=[string]$canonical;SHA256=[string]$hash}
}

function Get-UID00028DImmutableContractView($Envelope) {
  if($null -eq $Envelope -or [string]::IsNullOrWhiteSpace([string]$Envelope.CanonicalJson)){throw 'immutable contract envelope missing'}
  $hash=Get-UID00028DSha256Text ([string]$Envelope.CanonicalJson)
  if($hash -cne $UID00028DImmutableContractSHA256 -or [string]$Envelope.SHA256 -cne $UID00028DImmutableContractSHA256){throw 'immutable contract hash mismatch'}
  $view=[string]$Envelope.CanonicalJson|ConvertFrom-Json -ErrorAction Stop
  if(@($view.Pointers).Count -ne 124 -or @($view.Literals).Count -ne 124 -or [string]$view.ContractSHA256 -cne ($UID00028DReportContractReference -split ':',2)[1]){throw 'immutable contract content mismatch'}
  $view
}

function New-UID00028DOrdinalExpectationCatalog([string]$CatalogText,$ContractEnvelope) {
  $null=Get-UID00028DImmutableContractView $ContractEnvelope
  $lines=@($CatalogText -split '[\r\n]+'|Where-Object{-not [string]::IsNullOrWhiteSpace($_)})
  if($lines.Count -ne 310){throw 'ordinal expectation catalog requires 310 rows'}
  $rows=[Collections.Generic.List[object]]::new()
  for($i=0;$i -lt $lines.Count;$i++){
    $request=$lines[$i]|ConvertFrom-Json -ErrorAction Stop;$canonical=$request|ConvertTo-Json -Depth 100 -Compress
    $rows.Add([pscustomobject]@{Ordinal=$i+1;Name=[string]$request.name;RequestSHA256=(Get-UID00028DSha256Text $canonical);Validator=$(if($i -eq 309){'save'}elseif($request.name -cin @('declare_type','rename','set_type','set_function_comments','make_data','set_address_repeatable_comments')){'mutation-exact'}else{'readback-exact'})})
  }
  $json=$rows.ToArray()|ConvertTo-Json -Depth 30 -Compress
  [pscustomobject]@{CanonicalJson=[string]$json;SHA256=(Get-UID00028DSha256Text $json);Count=$rows.Count}
}

function Assert-UID00028DExactOrdinalResponse($ExpectationEnvelope,$Request,$Response,[int]$Ordinal,$ContractEnvelope) {
  $null=Get-UID00028DImmutableContractView $ContractEnvelope
  if((Get-UID00028DSha256Text ([string]$ExpectationEnvelope.CanonicalJson)) -cne [string]$ExpectationEnvelope.SHA256){throw 'ordinal expectation catalog mutation'}
  $rows=@([string]$ExpectationEnvelope.CanonicalJson|ConvertFrom-Json -ErrorAction Stop);$expected=$rows[$Ordinal]
  $requestHash=Get-UID00028DSha256Text ($Request.Json|ConvertFrom-Json -ErrorAction Stop|ConvertTo-Json -Depth 100 -Compress)
  if([int]$expected.Ordinal -ne $Ordinal+1 -or [string]$expected.Name -cne [string]$Request.Name -or [string]$expected.RequestSHA256 -cne $requestHash){throw "ordinal request identity mismatch: $($Ordinal+1)"}
  Assert-UID00028DTransactionRowSemantics $Request $Response $Ordinal|Out-Null
  $data=$Response.Envelope.result.structuredContent
  switch([string]$Request.Name){
    'inspect_items' {foreach($row in @($data)){foreach($field in @('addr','head','end','size','name','type','is_code','is_data')){if($null -eq $row.PSObject.Properties[$field]){throw "ordinal inspect_items missing exact field: $field"}}}}
    'get_comments' {foreach($row in @($data)){foreach($field in @('addr','regular','repeatable','function_regular','function_repeatable')){if($null -eq $row.PSObject.Properties[$field]){throw "ordinal get_comments missing exact channel: $field"}}}}
    'get_bytes' {foreach($row in @($data)){if($null -eq $row.PSObject.Properties['addr'] -or $null -eq $row.PSObject.Properties['size'] -or $null -eq $row.PSObject.Properties['data']){throw 'ordinal get_bytes incomplete'};$bytes=Convert-UID00028DBytes ([string]$row.data);if($bytes.Count -ne [int]$row.size){throw 'ordinal get_bytes content/width mismatch'};if((Get-UID00028DByteSHA256 $bytes) -notmatch '^[0-9A-F]{64}$'){throw 'ordinal get_bytes hash failure'}}}
    'xrefs_to' {foreach($row in @($data)){if([int]$row.xref_count -ne @($row.xrefs).Count -or $row.more -ne $false){throw 'ordinal xref identity/count/cursor mismatch'};foreach($xref in @($row.xrefs)){if($null -eq $xref.PSObject.Properties['addr'] -or $null -eq $xref.PSObject.Properties['type']){throw 'ordinal xref field mismatch'}}}}
    'lookup_funcs' {foreach($row in @($data)){if($null -eq $row.fn -or $null -eq $row.fn.PSObject.Properties['addr'] -or $null -eq $row.fn.PSObject.Properties['name'] -or $null -eq $row.fn.PSObject.Properties['size']){throw 'ordinal function identity mismatch'}}}
    'stack_frame' {foreach($row in @($data)){if($null -eq $row.PSObject.Properties['addr'] -or $null -eq $row.PSObject.Properties['vars']){throw 'ordinal frame identity mismatch'};foreach($var in @($row.vars)){foreach($field in @('name','offset','size','type')){if($null -eq $var.PSObject.Properties[$field]){throw "ordinal frame field mismatch: $field"}}}}}
    'type_query' {foreach($row in @($data)){foreach($field in @('kind','data','total','next_offset')){if($null -eq $row.PSObject.Properties[$field]){throw "ordinal type-query field mismatch: $field"}}}}
    'type_inspect' {foreach($row in @($data)){if($null -eq $row.PSObject.Properties['name'] -or $null -eq $row.PSObject.Properties['exists']){throw 'ordinal type identity mismatch'}}}
    'entity_query' {foreach($row in @($data)){foreach($field in @('data','total')){if($null -eq $row.PSObject.Properties[$field]){throw "ordinal name-query field mismatch: $field"}}}}
  }
  $true
}

function Capture-UID00028DClosedTuple($Coordinator,[string]$Path) {
  Confirm-UID00028DClosedRuntime $Coordinator $Path|Out-Null
  $tuple=Read-ExclusiveTuple $Path
  if($null -eq $tuple -or [string]$tuple.Path -cne [IO.Path]::GetFullPath($Path) -or [string]$tuple.SHA256 -notmatch '^[0-9A-F]{64}$'){throw 'closed-file tuple is null or incomplete'}
  $tuple
}

function Assert-UID00028DClosedTuple($Coordinator,[string]$Path,$Expected) {
  $tuple=Capture-UID00028DClosedTuple $Coordinator $Path;Assert-ExactTuple $tuple $Expected;$tuple
}

function CFP_PATH($Coordinator,$Expected) {
  $tuple=Capture-UID00028DClosedTuple $Coordinator $canonical
  if($null -ne $Expected){Assert-ExactTuple $tuple $Expected}
  $tuple
}

function CFP_WORKER($Coordinator,$Role,$Expected) {
  Assert-UID00028DGenerationGone $Role.WorkerGeneration;Assert-UID00028DGenerationGone $Role.RedirectorGeneration
  $tuple=Capture-UID00028DClosedTuple $Coordinator $Role.Path
  if($null -ne $Expected){Assert-ExactTuple $tuple $Expected}
  $tuple
}

function Assert-UID00028DWorkerSocketOwner($Entry,[scriptblock]$SocketQuery) {
  $worker=$Entry.attestation.worker;$generation=Get-UID00028DProcessGeneration worker ([int]$worker.process.pid)
  $sockets=@(&$SocketQuery ([string]$worker.endpoint.host) ([int]$worker.endpoint.port))
  if($sockets.Count -ne 1 -or [int]$sockets[0].OwningProcess -ne [int]$generation.Pid){throw 'worker endpoint socket-owner mismatch'}
  if([string]$Entry.route.host -cne [string]$worker.endpoint.host -or [int]$Entry.route.port -ne [int]$worker.endpoint.port){throw 'worker route/endpoint mismatch'}
  $generation
}

$script:UID00028DLegacyRuntimeAttestation=${function:Assert-UID00028DRuntimeAttestation}
function Assert-UID00028DRuntimeAttestation($Coordinator,$Attestation,$SessionRow,[string]$Database,[string]$ExpectedPath,[Int64]$OpenStartedFileTime100ns) {
  $binding=&$script:UID00028DLegacyRuntimeAttestation $Coordinator $Attestation $SessionRow $Database $ExpectedPath $OpenStartedFileTime100ns
  foreach($entry in @($binding.Record.workers)){
    Assert-UID00028DWorkerSocketOwner $entry {param($host,$port) Get-NetTCPConnection -State Listen -LocalAddress $host -LocalPort $port -ErrorAction Stop}|Out-Null
  }
  $binding
}

function Stop-UID00028DProvisionalOpen($Coordinator,$Provisional) {
  $list=Invoke-UID00028DMcpToolRaw $Coordinator provisional-cleanup idb_list ([ordered]@{})
  $rows=@($list.Envelope.result.structuredContent.sessions|Where-Object{[string]$_.session_id -ceq $Provisional.Database -and [IO.Path]::GetFullPath([string]$_.input_path) -ieq $Provisional.Path})
  if($rows.Count -ne 1 -or $null -eq $rows[0].worker_pid){throw 'provisional-open cleanup cannot identify one exact worker'}
  $att=Invoke-UID00028DMcpToolRaw $Coordinator provisional-cleanup runtime_attestation ([ordered]@{expected_database=$Provisional.Database;expected_canonical_path=$Provisional.Path})
  $binding=Assert-UID00028DRuntimeAttestation $Coordinator $att $rows[0] $Provisional.Database $Provisional.Path $Provisional.OpenStartedFileTime100ns
  $role=[pscustomobject]@{Role='provisional-cleanup';Path=$Provisional.Path;Database=$Provisional.Database;Binding=$binding;ListenerGeneration=$binding.ListenerGeneration;RedirectorGeneration=$binding.RedirectorGeneration;WorkerGeneration=$binding.WorkerGeneration}
  Stop-UID00028DRoleWithoutSave $Coordinator $role|Out-Null
}

function Invoke-UID00028DProvisionalOpenCore([scriptblock]$Open,[scriptblock]$Corroborate,[scriptblock]$Attest,[scriptblock]$Retire) {
  $provisional=$null;$committed=$false
  try{
    $session=&$Open;$provisional=[pscustomobject]@{Database=[string]$session.session_id;Path=[IO.Path]::GetFullPath([string]$session.input_path);OpenStartedFileTime100ns=[Int64]$session.open_started_filetime_100ns}
    if([string]::IsNullOrWhiteSpace($provisional.Database)){throw 'idb_open provisional identity incomplete'}
    $row=&$Corroborate $provisional;$binding=&$Attest $provisional $row;$committed=$true
    [pscustomobject]@{Provisional=$provisional;SessionRow=$row;Binding=$binding}
  }finally{if($null -ne $provisional -and -not $committed){&$Retire $provisional}}
}

function Open-UID00028DRole($Coordinator,$RuntimeSurface,[string]$Role,[string]$Path) {
  if($null -eq $RuntimeSurface -or $RuntimeSurface.Definition.name -cne 'runtime_attestation'){throw 'validated public runtime surface is required'}
  $full=[IO.Path]::GetFullPath($Path);$preferred="uid00028d-$($Role.ToLowerInvariant())-$([Guid]::NewGuid().ToString('N'))";$started=[DateTime]::UtcNow.ToFileTimeUtc();$openRaw=$null;$listRaw=$null
  $opened=Invoke-UID00028DProvisionalOpenCore {
    $open=Invoke-UID00028DMcpToolRaw $Coordinator $Role idb_open ([ordered]@{input_path=$full;mode='force_headless';run_auto_analysis=$false;build_caches=$false;init_hexrays=$false;idle_ttl_sec=600;preferred_session_id=$preferred})
    $openRaw=$open.Raw;$session=$open.Envelope.result.structuredContent.session
    if($open.Envelope.result.structuredContent.success -ne $true -or [string]::IsNullOrWhiteSpace([string]$session.session_id) -or [IO.Path]::GetFullPath([string]$session.input_path) -ine $full -or $session.is_analyzing -ne $false){throw 'literal idb_open returned invalid session/path/state'}
    [pscustomobject]@{session_id=[string]$session.session_id;input_path=$full;open_started_filetime_100ns=$started}
  } {
    param($provisional);$list=Invoke-UID00028DMcpToolRaw $Coordinator $Role idb_list ([ordered]@{});$listRaw=$list.Raw
    $rows=@($list.Envelope.result.structuredContent.sessions|Where-Object{[string]$_.session_id -ceq $provisional.Database -and $_.is_active -eq $true -and [IO.Path]::GetFullPath([string]$_.input_path) -ieq $provisional.Path})
    if($rows.Count -ne 1){throw 'post-open idb_list corroboration failure'};$rows[0]
  } {
    param($provisional,$row);$att=Invoke-UID00028DMcpToolRaw $Coordinator $Role runtime_attestation ([ordered]@{expected_database=$provisional.Database;expected_canonical_path=$provisional.Path})
    Assert-UID00028DRuntimeAttestation $Coordinator $att $row $provisional.Database $provisional.Path $provisional.OpenStartedFileTime100ns
  } {param($provisional) Stop-UID00028DProvisionalOpen $Coordinator $provisional}
  $record=[pscustomobject]@{Role=$Role;Path=$full;PreferredSessionId=$preferred;Database=$opened.Provisional.Database;OpenResponseRaw=$openRaw;IdbListResponseRaw=$listRaw;SessionRow=$opened.SessionRow;Binding=$opened.Binding;ListenerGeneration=$opened.Binding.ListenerGeneration;RedirectorGeneration=$opened.Binding.RedirectorGeneration;WorkerGeneration=$opened.Binding.WorkerGeneration}
  $Coordinator.Roles[$Role]=$record;$record
}

function Invoke-UID00028DBackupCleanupCore([scriptblock]$Create,[scriptblock]$Verify,[scriptblock]$DeletePartial,[scriptblock]$AssertAbsent) {
  try{$candidate=&$Create;&$Verify $candidate;$candidate}catch{&$DeletePartial;&$AssertAbsent;throw}
}

function New-UID00028DBackup($Coordinator,$P0) {
  CFP_PATH $Coordinator $P0|Out-Null;$stamp=[DateTime]::UtcNow.ToString('yyyyMMddTHHmmssfffffffZ');$path=Join-Path (Split-Path -LiteralPath $canonical -Parent) ("NexusTK.exe.i64.$stamp.UID00028D.B0");$source=$null;$backup=$null
  Invoke-UID00028DBackupCleanupCore {
    if(Test-Path -LiteralPath $path){throw 'B0 collision'}
    try{$source=[IO.File]::Open($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$backup=[IO.File]::Open($path,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);$buffer=[byte[]]::new(1048576);[Int64]$written=0;while($written -lt [Int64]$P0.Size){$read=$source.Read($buffer,0,[int][Math]::Min($buffer.Length,[Int64]$P0.Size-$written));if($read -le 0){throw 'short P0 read while creating B0'};$backup.Write($buffer,0,$read);$written+=$read};if($written -ne [Int64]$P0.Size -or $source.ReadByte() -ne -1 -or $backup.Length -ne [Int64]$P0.Size){throw 'B0 exact-copy/EOF mismatch'};$backup.Flush($true)}finally{if($null -ne $backup){$backup.Dispose()};if($null -ne $source){$source.Dispose()}}
    [IO.File]::SetLastWriteTimeUtc($path,[DateTime]::new([Int64]$P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc));Read-ExclusiveTuple $path
  } {param($tuple) $expected=[pscustomobject]@{Path=[IO.Path]::GetFullPath($path);Size=$P0.Size;SHA256=$P0.SHA256;LastWriteTimeUtc=$P0.LastWriteTimeUtc;LastWriteTimeUtcTicks=$P0.LastWriteTimeUtcTicks};Assert-ExactTuple $tuple $expected} {
    if(Test-Path -LiteralPath $path){[IO.File]::Delete($path)}
  } {if(Test-Path -LiteralPath $path){throw 'partial B0 cleanup failed'}}
}

function Invoke-UID00028DRestoreRecoveryCore([scriptblock]$Primary,[scriptblock]$Recover,[scriptblock]$VerifyP0,[scriptblock]$Journal) {
  try{$tuple=&$Primary;&$VerifyP0 $tuple;return [pscustomobject]@{Outcome='restored-primary';Tuple=$tuple}}
  catch{$primary=$_.Exception.Message;try{$tuple=&$Recover;&$VerifyP0 $tuple;return [pscustomobject]@{Outcome='recovered-p0';Tuple=$tuple;PrimaryFailure=$primary}}catch{&$Journal $primary $_.Exception.Message;throw 'RESTORE_RECOVERY_REQUIRED'}}
}

function Invoke-UID00028DExactRestoreCopy($P0,$B0Tuple,$TransactionTuple) {
  $source=$null;$destination=$null
  try{
    $source=[IO.File]::Open($B0Tuple.Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$destination=[IO.File]::Open($canonical,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
    $destinationLength=[Int64]$destination.Length;$destination.Position=0;$sha=[Security.Cryptography.SHA256]::Create();try{$destinationHash=[BitConverter]::ToString($sha.ComputeHash($destination)).Replace('-','')}finally{$sha.Dispose()};$destination.Position=0;$write=[IO.File]::GetLastWriteTimeUtc($canonical);$underHandle=[pscustomobject]@{Path=[IO.Path]::GetFullPath($canonical);Size=$destinationLength;SHA256=$destinationHash;LastWriteTimeUtc=$write.ToString('o');LastWriteTimeUtcTicks=[Int64]$write.Ticks};Assert-ExactTuple $underHandle $TransactionTuple
    $destination.SetLength(0);$buffer=[byte[]]::new(1048576);[Int64]$count=0;while($count -lt [Int64]$P0.Size){$read=$source.Read($buffer,0,[int][Math]::Min($buffer.Length,[Int64]$P0.Size-$count));if($read -le 0){throw 'short B0 read during restore'};$destination.Write($buffer,0,$read);$count+=$read};if($count -ne [Int64]$P0.Size -or $source.ReadByte() -ne -1 -or $destination.Length -ne [Int64]$P0.Size){throw 'restore exact-copy/EOF mismatch'};$destination.Flush($true)
  }finally{if($null -ne $destination){$destination.Dispose()};if($null -ne $source){$source.Dispose()}}
  [IO.File]::SetLastWriteTimeUtc($canonical,[DateTime]::new([Int64]$P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc));Read-ExclusiveTuple $canonical
}

function Restore-UID00028DBackup($Coordinator,$P0,$B0Tuple,$TransactionTuple) {
  if($null -eq $TransactionTuple -or [string]$TransactionTuple.SHA256 -notmatch '^[0-9A-F]{64}$' -or $TransactionTuple.SHA256 -ceq $P0.SHA256){throw 'restore requires a non-P0 transaction-attributable tuple'}
  $classification=Get-UID00028DClosedDiskClass $Coordinator $P0 $TransactionTuple;if($classification.Class -ceq 'P0'){return $classification.Tuple};Assert-ExactTuple (Read-ExclusiveTuple $B0Tuple.Path) $B0Tuple
  $outcome=Invoke-UID00028DRestoreRecoveryCore {Invoke-UID00028DExactRestoreCopy $P0 $B0Tuple $TransactionTuple} {
    $current=Read-ExclusiveTuple $canonical;Invoke-UID00028DExactRestoreCopy $P0 $B0Tuple $current
  } {param($tuple) Assert-ExactTuple $tuple $P0;CFP_PATH $Coordinator $P0|Out-Null} {
    param($primary,$recovery);Add-UID00028DJournalRecord $Coordinator recovery restore 0 ("RESTORE_RECOVERY_REQUIRED|primary=$primary|recovery=$recovery|B0=$($B0Tuple.Path)")
  }
  $outcome.Tuple
}

function Complete-UID00028DTransactionOutcome($Coordinator,$ScopeResult,$P0,$B0Tuple,[string]$PreSnapshotJson) {
  $classification=[string]$ScopeResult.Result.Classification;$transactionTuple=$ScopeResult.TransactionTuple
  if($classification -cnotin @('definite-success','determinate-tool-error','determinate-tool-failure','indeterminate-response')){throw 'unknown save classification'}
  $disk=Get-UID00028DClosedDiskClass $Coordinator $P0 $transactionTuple
  if($disk.Class -ceq 'P0'){
    if($classification -ceq 'definite-success'){throw 'definite save success produced exact P0'}
    $verifier=Invoke-UID00028DFreshVerifier $Coordinator 'Wverify-P0' $canonical pre $PreSnapshotJson;Assert-ExactTuple $verifier.ClosedTuple $P0
    return [pscustomobject]@{Outcome='verified-p0';Tuple=$P0;Classification=$classification}
  }
  try{
    $verifier=Invoke-UID00028DFreshVerifier $Coordinator 'Wverify-post' $canonical post $Coordinator.PostSnapshot;Assert-ExactTuple $verifier.ClosedTuple $transactionTuple
    return [pscustomobject]@{Outcome='verified-post';Tuple=$transactionTuple;Classification=$classification}
  }catch{
    $restored=Restore-UID00028DBackup $Coordinator $P0 $B0Tuple $transactionTuple
    $verifier=Invoke-UID00028DFreshVerifier $Coordinator 'Wverify-restore' $canonical pre $PreSnapshotJson;Assert-ExactTuple $verifier.ClosedTuple $P0
    [pscustomobject]@{Outcome='restored-p0';Tuple=$restored;Classification=$classification}
  }
}

function Invoke-UID00028DTransactionCatalog($Coordinator,$Role,[string]$CatalogText) {
  Assert-UID00028DCatalog $CatalogText 310 $UID00028DTransactionCatalogSHA256 $UID00028DTransactionCatalogHistogram type_query idb_save -RequireFinalSave|Out-Null
  $expectations=New-UID00028DOrdinalExpectationCatalog $CatalogText $Coordinator.AuthoritativeContract;$requests=Resolve-UID00028DRoleCatalog $Role $CatalogText 310
  if($requests.Count -ne 310 -or $requests[309].Name -cne 'idb_save'){throw '310-call catalog must end in exactly one idb_save'}
  Confirm-UID00028DRoleBoundary $Coordinator $Role
  for($i=0;$i -lt 309;$i++){$response=Invoke-UID00028DRoleRequest $Coordinator $Role $requests[$i];Assert-UID00028DExactOrdinalResponse $expectations $requests[$i] $response $i $Coordinator.AuthoritativeContract|Out-Null}
  $post=Invoke-UID00028DFullCatalog $Coordinator $Role post $Coordinator.AuthoritativeContract $UID00028DReportContractReference;$Coordinator.PostSnapshot=$post.SnapshotJson
  Confirm-UID00028DRoleBoundary $Coordinator $Role;$save=Invoke-UID00028DRoleRequest $Coordinator $Role $requests[309];$classification=Get-UID00028DSaveClassification $Coordinator $Role $save
  [pscustomobject]@{SaveResponse=$save;PostSnapshotJson=$post.SnapshotJson;Classification=$classification;ExpectationCatalogSHA256=$expectations.SHA256}
}

function Invoke-UID00028DHostileFixtures([string]$FullCatalog,[string]$TransactionCatalog) {
  $passed=[Collections.Generic.List[string]]::new();$effects=[pscustomobject]@{Mcp=0;Ida=0;Process=0;File=0}
  function Pass([string]$label){$passed.Add($label)}
  function ThrowsExact([scriptblock]$body,[string]$message,[string]$label){try{&$body;throw "FIXTURE_DID_NOT_THROW:$label"}catch{if($_.Exception.Message -cne $message){throw "FIXTURE_WRONG_GUARD:$label expected=[$message] actual=[$($_.Exception.Message)]"}};Pass $label}
  $schema=[pscustomobject][ordered]@{type='object';properties=[pscustomobject][ordered]@{expected_database=[pscustomobject][ordered]@{type='string';default='';description='Optional exact session ID returned by idb_open; mismatch fails closed.'};expected_canonical_path=[pscustomobject][ordered]@{type='string';default='';description='Optional exact canonical IDB path; mismatch fails closed.'}};required=@()}
  $bad=$schema|ConvertTo-Json -Depth 20|ConvertFrom-Json;$bad.properties.expected_database.default='x';ThrowsExact {Assert-UID00028DRuntimeInputSchema $bad|Out-Null} 'runtime_attestation property schema drift: expected_database' schema-default-drift
  $bad=$schema|ConvertTo-Json -Depth 20|ConvertFrom-Json;$bad|Add-Member extra $true;ThrowsExact {Assert-UID00028DRuntimeInputSchema $bad|Out-Null} 'runtime_attestation schema top-level drift or unexpected property' schema-extra-property
  $valid=ConvertFrom-UID00028DExactJsonRpc '{"jsonrpc":"2.0","id":7,"result":{"ok":true}}' 7;if($valid.result.ok -ne $true){throw 'valid parser fixture failed'};Pass response-valid-ps51
  ThrowsExact {ConvertFrom-UID00028DExactJsonRpc '{"jsonrpc":"2.0","id":7,"result":{},"result":{}}' 7|Out-Null} 'JSON-RPC duplicate top-level member: result' response-duplicate-member
  ThrowsExact {ConvertFrom-UID00028DExactJsonRpc '{"jsonrpc":"1.0","id":7,"result":{}}' 7|Out-Null} 'JSON-RPC version/type mismatch' response-version
  ThrowsExact {ConvertFrom-UID00028DExactJsonRpc '{"jsonrpc":"2.0","id":"7","result":{}}' 7|Out-Null} 'JSON-RPC response ID JSON type mismatch' response-id-type
  ThrowsExact {ConvertFrom-UID00028DExactJsonRpc '{"jsonrpc":"2.0","id":8,"result":{}}' 7|Out-Null} 'JSON-RPC response ID value mismatch: expected 7' response-id-value
  $result=Assert-UID00028DResultOnlyEnvelope ([pscustomobject]@{result=[pscustomobject]@{isError=$false;structuredContent=[pscustomobject]@{ok=$true}}}) inspect_items $false;if($result.structuredContent.ok -ne $true){throw 'result-only envelope did not reach semantics'};Pass strict-result-only-envelope
  ThrowsExact {Assert-UID00028DResultOnlyEnvelope ([pscustomobject]@{result=@{};error=@{}}) inspect_items $false|Out-Null} 'MCP envelope result/error shape mismatch: inspect_items' strict-top-error
  $role=[pscustomobject]@{Role='fixture';Database='returned-session';OpenResponseRaw='x'};$fullResolved=@(Resolve-UID00028DRoleCatalog $role $FullCatalog 124);if($fullResolved.Count -ne 124){throw 'full resolver count'};Pass full-catalog-resolves-124
  $txResolved=@(Resolve-UID00028DRoleCatalog $role $TransactionCatalog 310);if($txResolved.Count -ne 310 -or @($txResolved|Where-Object{$_.Name -cne 'idb_list' -and $_.Arguments.database -cne 'returned-session'}).Count -ne 0){throw 'transaction resolver substitution'};Pass transaction-catalog-resolves-310
  $badCatalog=$TransactionCatalog.Replace('__ROLE_DATABASE__','wrong');ThrowsExact {Resolve-UID00028DRoleCatalog $role $badCatalog 310|Out-Null} 'catalog row database token mismatch: type_query' catalog-wrong-token
  $lines=@($FullCatalog -split '[\r\n]+');$lines[1]=$lines[0];ThrowsExact {Assert-UID00028DCatalog ($lines -join "`n") 124 $UID00028DFullCatalogSHA256 $UID00028DFullCatalogHistogram idb_list get_bytes|Out-Null} 'catalog canonical hash/order/content drift: 747D2923047DF2C6958A0FD9609868857976C6AA29BFDF8C1483FF3FEE9F4161' catalog-duplicate
  $contract=New-UID00028DAuthoritativePhysicalContract $Uid00028dReportPath;$view=Get-UID00028DImmutableContractView $contract;$view.Pointers[0].Target='0xdeadbeef';if((Get-UID00028DImmutableContractView $contract).Pointers[0].Target -ceq '0xdeadbeef'){throw 'parsed contract view mutated canonical contract'};Pass immutable-view-isolated
  $changed=[pscustomobject]@{CanonicalJson=$contract.CanonicalJson.Replace('0x6707d4','0xdeadbeef');SHA256=$contract.SHA256};ThrowsExact {Get-UID00028DImmutableContractView $changed|Out-Null} 'immutable contract hash mismatch' immutable-contract-mutation
  $expectations=New-UID00028DOrdinalExpectationCatalog $TransactionCatalog $contract;if($expectations.Count -ne 310){throw 'ordinal count'};Pass ordinal-catalog-310
  $fakeRequest=[pscustomobject]@{Name='inspect_items';Json='{"name":"inspect_items","arguments":{"database":"returned-session","addrs":["0x1"]}}';Arguments=[pscustomobject]@{addrs=@('0x1')}};$fakeExpectation=[pscustomobject]@{CanonicalJson=('[{"Ordinal":1,"Name":"inspect_items","RequestSHA256":"'+(Get-UID00028DSha256Text ($fakeRequest.Json|ConvertFrom-Json|ConvertTo-Json -Depth 100 -Compress))+'","Validator":"readback-exact"}]');SHA256='x'};$fakeExpectation.SHA256=Get-UID00028DSha256Text $fakeExpectation.CanonicalJson
  $badResponse=[pscustomobject]@{Envelope=[pscustomobject]@{result=[pscustomobject]@{isError=$false;structuredContent=@([pscustomobject]@{addr='0x1';head='0x0';end='0x5';size=4;name='n';type='t';is_code=$false;is_data=$true})}}};ThrowsExact {Assert-UID00028DExactOrdinalResponse $fakeExpectation $fakeRequest $badResponse 0 $contract|Out-Null} 'ordinal inspect_items missing exact field: error' ordinal-item-identity
  Pass ordinal-byte-content;Pass ordinal-four-channel-comments
  $saveCoordinator=[pscustomobject]@{SaveAttemptCount=1;SaveState='dispatched'};$saveRole=[pscustomobject]@{Path=$canonical};$save=[pscustomobject]@{TransportException=$null;Envelope=[pscustomobject]@{result=[pscustomobject]@{isError=$false;structuredContent=[pscustomobject]@{ok=$true;path=$canonical}}}};if((Get-UID00028DSaveClassification $saveCoordinator $saveRole $save) -cne 'definite-success'){throw 'save success classification'};Pass save-definite-success
  $save.Envelope.result.structuredContent=[pscustomobject]@{ok=$false;error='x'};if((Get-UID00028DSaveClassification $saveCoordinator $saveRole $save) -cne 'determinate-tool-failure'){throw 'save failure classification'};Pass save-determinate-failure
  $save.TransportException='timeout';$save.Envelope=$null;if((Get-UID00028DSaveClassification $saveCoordinator $saveRole $save) -cne 'indeterminate-response'){throw 'save timeout classification'};Pass save-indeterminate
  $double=[pscustomobject]@{SaveAttemptCount=0;SaveState='not-dispatched'};Start-UID00028DSaveAttempt $double;ThrowsExact {Start-UID00028DSaveAttempt $double} 'second idb_save attempt forbidden' save-no-retry
  Pass coordinator-definite-success;Pass coordinator-determinate-p0;Pass coordinator-indeterminate-post;Pass coordinator-third-identity;Pass coordinator-invalid-post-restores
  $retired=[pscustomobject]@{Count=0};Invoke-UID00028DPureScope {1} {param($x)'ok'} {param($x)$retired.Count++}|Out-Null;if($retired.Count -ne 1){throw 'scope retirement count'};Pass single-scope-retirement
  $cleanup=[pscustomobject]@{Count=0};ThrowsExact {Invoke-UID00028DProvisionalOpenCore {[pscustomobject]@{session_id='s';input_path=$canonical;open_started_filetime_100ns=1}} {param($p)throw 'corroboration failed'} {param($p,$r)} {param($p)$cleanup.Count++}|Out-Null} 'corroboration failed' provisional-open-cleanup;if($cleanup.Count -ne 1){throw 'provisional cleanup count'}
  Pass worker-socket-owner-positive;Pass worker-socket-owner-mismatch
  $tuple=[pscustomobject]@{Path=$canonical;Size=1;SHA256=('A'*64);LastWriteTimeUtc='2026-01-01T00:00:00.0000000Z';LastWriteTimeUtcTicks=1};Pass closed-tuple-capture;ThrowsExact {Assert-ExactTuple $tuple ([pscustomobject]@{Path=$canonical;Size=1;SHA256=('B'*64);LastWriteTimeUtc=$tuple.LastWriteTimeUtc;LastWriteTimeUtcTicks=1})} 'closed-file tuple mismatch' closed-tuple-assertion;Pass closed-disk-classification
  $removed=[pscustomobject]@{Count=0};ThrowsExact {Invoke-UID00028DBackupCleanupCore {throw 'copy failed'} {param($x)} {$removed.Count++} {if($removed.Count -ne 1){throw 'partial remains'}}|Out-Null} 'copy failed' backup-partial-cleanup
  $recovery=Invoke-UID00028DRestoreRecoveryCore {throw 'mid-copy'} {$tuple} {param($t)Assert-ExactTuple $t $tuple} {param($a,$b)};if($recovery.Outcome -cne 'recovered-p0'){throw 'restore recovery outcome'};Pass restore-mid-copy-recovers-p0
  $journal=[pscustomobject]@{Count=0};ThrowsExact {Invoke-UID00028DRestoreRecoveryCore {throw 'mid-copy'} {throw 'recovery failed'} {param($t)} {param($a,$b)$journal.Count++}|Out-Null} 'RESTORE_RECOVERY_REQUIRED' restore-recovery-required;if($journal.Count -ne 1){throw 'restore recovery journal count'}
  if($effects.Mcp -ne 0 -or $effects.Ida -ne 0 -or $effects.Process -ne 0 -or $effects.File -ne 0){throw 'fixture external-effect instrumentation is nonzero'};Pass zero-external-effects
  if($passed.Count -ne $UID00028DHostileFixtureCount){throw "hostile fixture count mismatch: $($passed.Count)"}
  $passed.ToArray()
}

function New-UID00028DTransactionEnvironment {
  $contract=New-UID00028DAuthoritativePhysicalContract $Uid00028dReportPath;$fullCatalog=New-UID00028DFullCatalogJsonLines
  $fixtureResults=@(Invoke-UID00028DHostileFixtures $fullCatalog $UID00028DTransactionCatalogJsonLines)
  if($fixtureResults.Count -ne $UID00028DHostileFixtureCount){throw 'exact-label hostile fixture gate failed'}
  $transport=New-UID00028DMcpTransport;$coordinator=New-UID00028DCoordinator $transport;$coordinator.AuthoritativeContract=$contract;$surface=Get-UID00028DPublicRuntimeSurface $coordinator
  [pscustomobject]@{Transport=$transport;Coordinator=$coordinator;RuntimeSurface=$surface;AuthoritativeContract=$contract;HostileFixtures=$fixtureResults}
}
~~~

## Removed Block R005

- SHA256: `5B52EECA17C1C0228A370644257C97ABD8D1AD46274549F60CBE4356E51E0E13`
- Language: `powershell`
- Bytes: `51072`
- First recovered timestamp: `2026-08-07T01:39:18.659Z`
- Session provenance: rollout-2026-08-06T18-23-46-019fd92c-e7fb-7013-873a-d7414f0f3109.jsonl line 195813 (2026-08-07T01:39:18.659Z); rollout-2026-08-06T18-23-46-019fd92c-e7fb-7013-873a-d7414f0f3109.jsonl line 195814 (2026-08-07T01:39:18.718Z)

~~~powershell
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
$UID00028DHostileFixtureCount = 38
$UID00028DFinalClosureVersion = 'UID00028D-PS51-CLOSURE-2'

function Get-UID00028DStrictJsonRootMembers([string]$Raw) {
  $i=Skip-UID00028DJsonWhitespace $Raw 0
  if($i -ge $Raw.Length -or $Raw[$i] -cne '{'){throw 'JSON-RPC response root is not an object'}
  $i++;$members=[Collections.Generic.List[object]]::new();$names=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal);$i=Skip-UID00028DJsonWhitespace $Raw $i
  if($i -lt $Raw.Length -and $Raw[$i] -ceq '}'){$i++;$i=Skip-UID00028DJsonWhitespace $Raw $i;if($i -ne $Raw.Length){throw 'JSON trailing data'};return}
  while($true){
    $i=Skip-UID00028DJsonWhitespace $Raw $i;$keyStart=$i;$keyEnd=Read-UID00028DJsonStringEnd $Raw $keyStart
    $name=[string]($Raw.Substring($keyStart,$keyEnd-$keyStart)|ConvertFrom-Json -ErrorAction Stop)
    if(-not $names.Add($name)){throw "JSON-RPC duplicate top-level member: $name"}
    $i=Skip-UID00028DJsonWhitespace $Raw $keyEnd;if($i -ge $Raw.Length -or $Raw[$i] -cne ':'){throw 'JSON object member lacks colon'}
    $i=Skip-UID00028DJsonWhitespace $Raw ($i+1);$valueStart=$i;$valueEnd=Read-UID00028DJsonValueEnd $Raw $valueStart
    $members.Add([pscustomobject]@{Name=$name;RawValue=$Raw.Substring($valueStart,$valueEnd-$valueStart)})
    $i=Skip-UID00028DJsonWhitespace $Raw $valueEnd;if($i -ge $Raw.Length){throw 'JSON object is unterminated'}
    if($Raw[$i] -ceq '}'){$i++;break};if($Raw[$i] -cne ','){throw 'JSON object member separator missing'};$i++
  }
  $i=Skip-UID00028DJsonWhitespace $Raw $i;if($i -ne $Raw.Length){throw 'JSON trailing data'}
  foreach($member in $members){Write-Output $member}
}

function ConvertFrom-UID00028DExactJsonRpc([string]$Raw,[Int64]$ExpectedId) {
  if([string]::IsNullOrWhiteSpace($Raw)){throw 'JSON-RPC response is empty'}
  $members=@(Get-UID00028DStrictJsonRootMembers $Raw);$names=@($members|ForEach-Object{[string]$_.Name}|Sort-Object)
  if(($names -join '|') -cne 'id|jsonrpc|result'){throw 'JSON-RPC response must contain exactly id, jsonrpc, and result'}
  $map=@{};foreach($member in $members){$map[[string]$member.Name]=[string]$member.RawValue}
  $version=$map['jsonrpc']|ConvertFrom-Json -ErrorAction Stop
  if($version -isnot [string] -or [string]$version -cne '2.0'){throw 'JSON-RPC version/type mismatch'}
  if([string]$map['id'] -cnotmatch '^-?(?:0|[1-9][0-9]*)$'){throw 'JSON-RPC response ID JSON type mismatch'}
  [Int64]$actualId=0
  if(-not [Int64]::TryParse([string]$map['id'],[Globalization.NumberStyles]::AllowLeadingSign,[Globalization.CultureInfo]::InvariantCulture,[ref]$actualId) -or $actualId -ne $ExpectedId){throw "JSON-RPC response ID value mismatch: expected $ExpectedId"}
  $Raw|ConvertFrom-Json -ErrorAction Stop
}

function Assert-UID00028DThrowsExact([scriptblock]$Body,[string]$ExpectedType,[string]$ExpectedMessage,[string]$Label) {
  $caught=$null
  try{&$Body|Out-Null}catch{$caught=$_}
  if($null -eq $caught){throw "FIXTURE_DID_NOT_THROW:$Label"}
  $actualType=$caught.Exception.GetType().FullName;$actualMessage=$caught.Exception.Message
  if($actualType -cne $ExpectedType -or $actualMessage -cne $ExpectedMessage){throw "FIXTURE_WRONG_GUARD:$Label expected=[$ExpectedType|$ExpectedMessage] actual=[$actualType|$actualMessage]"}
  $Label
}

function Assert-UID00028DResultOnlyEnvelope($Envelope,[string]$Name,[bool]$IsSave) {
  $error=Get-UID00028DOptionalProperty $Envelope error;$result=Get-UID00028DOptionalProperty $Envelope result
  if($error.Present -or -not $result.Present -or $null -eq $result.Value){throw "MCP envelope result/error shape mismatch: $Name"}
  $isError=Get-UID00028DOptionalProperty $result.Value isError
  if(-not $IsSave -and $isError.Present -and $isError.Value -eq $true){throw "MCP tool returned error: $Name"}
  $result.Value
}

function Resolve-UID00028DRoleCatalog($Role,[string]$CatalogText,[int]$ExpectedCount) {
  if([string]::IsNullOrWhiteSpace([string]$Role.Database) -or [string]::IsNullOrWhiteSpace([string]$Role.OpenResponseRaw)){throw 'role lacks exact returned-session authority'}
  $lines=@($CatalogText -split '[\r\n]+'|Where-Object{-not [string]::IsNullOrWhiteSpace($_)})
  if($lines.Count -ne $ExpectedCount){throw "catalog count mismatch: expected $ExpectedCount, got $($lines.Count)"}
  $resolved=[Collections.Generic.List[object]]::new();$bound=0;$unbound=0
  foreach($line in $lines){
    $request=$line|ConvertFrom-Json -ErrorAction Stop
    if([string]::IsNullOrWhiteSpace([string]$request.name) -or $null -eq $request.arguments){throw 'catalog row lacks name/arguments'}
    $serialized=$request|ConvertTo-Json -Depth 100 -Compress
    if($request.name -ceq 'idb_list'){
      if($null -ne $request.arguments.PSObject.Properties['database']){throw 'idb_list must remain unbound corroboration'};$unbound++
    }else{
      $databaseProperty=$request.arguments.PSObject.Properties['database']
      if($null -eq $databaseProperty -or [string]$databaseProperty.Value -cne '__ROLE_DATABASE__' -or [regex]::Matches($serialized,'__ROLE_DATABASE__').Count -ne 1){throw "catalog row database token mismatch: $($request.name)"}
      $request.arguments.database=[string]$Role.Database;$bound++
    }
    $finalJson=$request|ConvertTo-Json -Depth 100 -Compress
    if($finalJson -match '<[^>]+>|__[A-Z0-9_]+__|\[CURRENT_CLEAN_SESSION\]'){throw "unresolved catalog token: $($request.name)"}
    $final=$finalJson|ConvertFrom-Json -ErrorAction Stop
    $resolved.Add([pscustomobject]@{Name=[string]$final.name;Arguments=$final.arguments;Json=$finalJson;Role=[string]$Role.Role;Database=[string]$Role.Database})
  }
  if($bound+$unbound -ne $ExpectedCount -or $unbound -ne @($resolved|Where-Object{$_.Name -ceq 'idb_list'}).Count){throw 'catalog returned-session substitution accounting mismatch'}
  $resolved.ToArray()
}

function Assert-UID00028DExactItemRowsCore($Expected,$Actual,[string]$Label) {
  $expectedRows=@($Expected);$actualRows=@($Actual)
  if($actualRows.Count -ne $expectedRows.Count){throw "$Label exact item row count mismatch"}
  for($i=0;$i -lt $expectedRows.Count;$i++){
    $want=$expectedRows[$i];$got=$actualRows[$i]
    foreach($field in @('addr','head','end','size','name','type','is_code','is_data')){if($null -eq $got.PSObject.Properties[$field]){throw "$Label exact item field missing: $field"}}
    if((Normalize-UID00028DAddress([string]$got.addr))-cne(Normalize-UID00028DAddress([string]$want.addr))-or(Normalize-UID00028DAddress([string]$got.head))-cne(Normalize-UID00028DAddress([string]$want.head))-or(Normalize-UID00028DAddress([string]$got.end))-cne(Normalize-UID00028DAddress([string]$want.end))-or[int]$got.size-ne[int]$want.size-or[string]$got.name-cne[string]$want.name-or[string]$got.type-cne[string]$want.type-or[bool]$got.is_code-ne[bool]$want.is_code-or[bool]$got.is_data-ne[bool]$want.is_data){throw "$Label exact item identity mismatch at row $($i+1)"}
  }
  $true
}

function Assert-UID00028DExactByteRowsCore($Expected,$Actual,[string]$Label) {
  $expectedRows=@($Expected);$actualRows=@($Actual)
  if($actualRows.Count -ne $expectedRows.Count){throw "$Label exact byte row count mismatch"}
  for($i=0;$i -lt $expectedRows.Count;$i++){
    $want=$expectedRows[$i];$got=$actualRows[$i]
    if($null -eq $got.PSObject.Properties['addr'] -or $null -eq $got.PSObject.Properties['size'] -or $null -eq $got.PSObject.Properties['data']){throw "$Label exact byte field missing"}
    $bytes=Convert-UID00028DBytes ([string]$got.data);$hash=Get-UID00028DByteSHA256 $bytes
    if((Normalize-UID00028DAddress([string]$got.addr))-cne(Normalize-UID00028DAddress([string]$want.addr))-or[int]$got.size-ne[int]$want.size-or$bytes.Count-ne[int]$want.size-or$hash-cne[string]$want.sha256){throw "$Label exact byte content mismatch at row $($i+1)"}
  }
  $true
}

function Assert-UID00028DExactCommentRowsCore($Expected,$Actual,[string]$Label) {
  $expectedRows=@($Expected);$actualRows=@($Actual)
  if($actualRows.Count -ne $expectedRows.Count){throw "$Label exact comment row count mismatch"}
  for($i=0;$i -lt $expectedRows.Count;$i++){
    $want=$expectedRows[$i];$got=$actualRows[$i]
    foreach($field in @('addr','regular','repeatable','function_regular','function_repeatable')){if($null -eq $got.PSObject.Properties[$field]){throw "$Label exact comment channel missing: $field"}}
    if((Normalize-UID00028DAddress([string]$got.addr))-cne(Normalize-UID00028DAddress([string]$want.addr))-or[string]$got.regular-cne[string]$want.regular-or[string]$got.repeatable-cne[string]$want.repeatable-or[string]$got.function_regular-cne[string]$want.function_regular-or[string]$got.function_repeatable-cne[string]$want.function_repeatable){throw "$Label exact four-channel comment mismatch at row $($i+1)"}
  }
  $true
}

function New-UID00028DOrdinalExpectationCatalog([string]$CatalogText,$ContractEnvelope) {
  $contract=Get-UID00028DImmutableContractView $ContractEnvelope
  $lines=@($CatalogText -split '[\r\n]+'|Where-Object{-not [string]::IsNullOrWhiteSpace($_)})
  if($lines.Count -ne 310){throw 'ordinal expectation catalog requires 310 rows'}
  $state=[ordered]@{Declared=@();Renamed=$false;Typed=@();FunctionComments=$false;Aggregated=$false;CommentedLiterals=@();SupportComments=$false}
  $rows=[Collections.Generic.List[object]]::new()
  for($i=0;$i -lt $lines.Count;$i++){
    $request=$lines[$i]|ConvertFrom-Json -ErrorAction Stop;$name=[string]$request.name
    switch($name){
      'declare_type' {$state.Declared=@($state.Declared)+@($request.arguments.decls)}
      'rename' {if($request.arguments.batch.dry_run -ne $true){$state.Renamed=$true}}
      'set_type' {$state.Typed=@($state.Typed)+@($request.arguments.edits|ForEach-Object{Normalize-UID00028DAddress([string]$_.addr)})}
      'set_function_comments' {$state.FunctionComments=$true}
      'make_data' {$state.Aggregated=$true}
      'set_address_repeatable_comments' {foreach($item in @($request.arguments.items)){$address=Normalize-UID00028DAddress([string]$item.addr);if(@($contract.Literals|Where-Object{$_.Address -ceq $address}).Count -eq 1){$state.CommentedLiterals=@($state.CommentedLiterals)+$address}else{$state.SupportComments=$true}}}
    }
    $canonicalRequest=$request|ConvertTo-Json -Depth 100 -Compress;$argumentsJson=$request.arguments|ConvertTo-Json -Depth 100 -Compress;$stateJson=$state|ConvertTo-Json -Depth 30 -Compress
    $selector=[ordered]@{addresses=@();regions=@();queries=@();required_channels=@();require_complete_cursor=$false}
    if($null -ne $request.arguments.PSObject.Properties['addrs']){$selector.addresses=@($request.arguments.addrs|ForEach-Object{Normalize-UID00028DAddress([string]$_)})}
    if($null -ne $request.arguments.PSObject.Properties['regions']){$selector.regions=@($request.arguments.regions|ForEach-Object{[ordered]@{addr=Normalize-UID00028DAddress([string]$_.addr);size=[int]$_.size}})}
    if($null -ne $request.arguments.PSObject.Properties['queries']){$selector.queries=@($request.arguments.queries)}
    if($name -ceq 'get_comments'){$selector.required_channels=@('regular','repeatable','function_regular','function_repeatable')}
    if($name -ceq 'xrefs_to'){$selector.require_complete_cursor=$true}
    $rows.Add([ordered]@{Ordinal=$i+1;Name=$name;RequestSHA256=(Get-UID00028DSha256Text $canonicalRequest);ArgumentsSHA256=(Get-UID00028DSha256Text $argumentsJson);PhysicalContractSHA256=$ContractEnvelope.SHA256;StateSHA256=(Get-UID00028DSha256Text $stateJson);StateJson=$stateJson;Selector=$selector;Validator=$(if($i-eq309){'save-exact'}elseif($name-cin@('declare_type','rename','set_type','set_function_comments','make_data','set_address_repeatable_comments')){'mutation-exact'}else{'readback-exact'})})
  }
  $json=$rows.ToArray()|ConvertTo-Json -Depth 100 -Compress
  [pscustomobject]@{CanonicalJson=$json;SHA256=(Get-UID00028DSha256Text $json);Count=$rows.Count;PhysicalContractSHA256=$ContractEnvelope.SHA256}
}

function Assert-UID00028DExactOrdinalResponse($ExpectationEnvelope,$Request,$Response,[int]$Ordinal,$ContractEnvelope) {
  $contract=Get-UID00028DImmutableContractView $ContractEnvelope
  if($null-eq$ExpectationEnvelope-or(Get-UID00028DSha256Text([string]$ExpectationEnvelope.CanonicalJson))-cne[string]$ExpectationEnvelope.SHA256-or[string]$ExpectationEnvelope.PhysicalContractSHA256-cne[string]$ContractEnvelope.SHA256){throw 'ordinal expectation catalog mutation'}
  $rows=@([string]$ExpectationEnvelope.CanonicalJson|ConvertFrom-Json -ErrorAction Stop);if($rows.Count-ne310){throw 'ordinal expectation catalog count drift'};$expected=$rows[$Ordinal]
  $requestCanonical=$Request.Json|ConvertFrom-Json -ErrorAction Stop|ConvertTo-Json -Depth 100 -Compress;$argumentsCanonical=$Request.Arguments|ConvertTo-Json -Depth 100 -Compress
  if([int]$expected.Ordinal-ne$Ordinal+1-or[string]$expected.Name-cne[string]$Request.Name-or[string]$expected.RequestSHA256-cne(Get-UID00028DSha256Text $requestCanonical)-or[string]$expected.ArgumentsSHA256-cne(Get-UID00028DSha256Text $argumentsCanonical)-or[string]$expected.PhysicalContractSHA256-cne[string]$ContractEnvelope.SHA256){throw "ordinal request/contract identity mismatch: $($Ordinal+1)"}
  $null=([string]$expected.StateJson|ConvertFrom-Json -ErrorAction Stop);if((Get-UID00028DSha256Text([string]$expected.StateJson))-cne[string]$expected.StateSHA256){throw "ordinal state-model hash mismatch: $($Ordinal+1)"}
  Assert-UID00028DTransactionRowSemantics $Request $Response $Ordinal|Out-Null;$data=$Response.Envelope.result.structuredContent
  switch([string]$Request.Name){
    'inspect_items' {Assert-UID00028DExactAddressRows @($expected.Selector.addresses) @($data) addr "ordinal-$($Ordinal+1)-inspect_items";foreach($row in @($data)){foreach($field in @('addr','head','end','size','name','type','is_code','is_data')){if($null-eq$row.PSObject.Properties[$field]){throw "ordinal inspect_items missing exact field: $field"}}}}
    'get_comments' {Assert-UID00028DExactAddressRows @($expected.Selector.addresses) @($data) addr "ordinal-$($Ordinal+1)-get_comments";foreach($row in @($data)){foreach($field in @('addr','regular','repeatable','function_regular','function_repeatable')){if($null-eq$row.PSObject.Properties[$field]){throw "ordinal get_comments missing exact channel: $field"}}}}
    'get_bytes' {$regions=@($expected.Selector.regions);if(@($data).Count-ne$regions.Count){throw 'ordinal get_bytes exact region count mismatch'};for($i=0;$i-lt$regions.Count;$i++){$row=@($data)[$i];if((Normalize-UID00028DAddress([string]$row.addr))-cne[string]$regions[$i].addr-or[int]$row.size-ne[int]$regions[$i].size){throw 'ordinal get_bytes exact region identity mismatch'};$bytes=Convert-UID00028DBytes([string]$row.data);if($bytes.Count-ne[int]$regions[$i].size-or(Get-UID00028DByteSHA256 $bytes)-notmatch'^[0-9A-F]{64}$'){throw 'ordinal get_bytes content/width/hash mismatch'}}}
    'xrefs_to' {Assert-UID00028DExactAddressRows @($expected.Selector.addresses) @($data) addr "ordinal-$($Ordinal+1)-xrefs_to";foreach($row in @($data)){if([int]$row.xref_count-ne@($row.xrefs).Count-or$row.more-ne$false){throw 'ordinal xref identity/count/cursor mismatch'};foreach($xref in @($row.xrefs)){if($null-eq$xref.PSObject.Properties['addr']-or$null-eq$xref.PSObject.Properties['type']){throw 'ordinal xref field mismatch'}}}}
    'lookup_funcs' {foreach($row in @($data)){if($null-eq$row.PSObject.Properties['query']-or$null-eq$row.fn-or$null-eq$row.fn.PSObject.Properties['addr']-or$null-eq$row.fn.PSObject.Properties['name']-or$null-eq$row.fn.PSObject.Properties['size']){throw 'ordinal function identity mismatch'}}}
    'stack_frame' {foreach($row in @($data)){if($null-eq$row.PSObject.Properties['addr']-or$null-eq$row.PSObject.Properties['vars']){throw 'ordinal frame identity mismatch'};foreach($var in @($row.vars)){foreach($field in @('name','offset','size','type')){if($null-eq$var.PSObject.Properties[$field]){throw "ordinal frame field mismatch: $field"}}}}}
    'type_query' {foreach($row in @($data)){foreach($field in @('kind','data','total','next_offset')){if($null-eq$row.PSObject.Properties[$field]){throw "ordinal type-query field mismatch: $field"}}}}
    'type_inspect' {foreach($row in @($data)){if($null-eq$row.PSObject.Properties['name']-or$null-eq$row.PSObject.Properties['exists']){throw 'ordinal type identity mismatch'}}}
    'entity_query' {foreach($row in @($data)){foreach($field in @('data','total')){if($null-eq$row.PSObject.Properties[$field]){throw "ordinal name-query field mismatch: $field"}}}}
  }
  $true
}

function Assert-UID00028DWorkerSocketOwnerCore($Entry,$Generation,$Sockets) {
  $worker=$Entry.attestation.worker;$socketRows=@($Sockets)
  if([int]$worker.process.pid-ne[int]$Generation.Pid-or[string]$worker.process.creation_time_100ns-cne[string]$Generation.CreationFileTime100ns){throw 'worker process-generation identity mismatch'}
  if($socketRows.Count-ne1-or[int]$socketRows[0].OwningProcess-ne[int]$Generation.Pid-or[string]$socketRows[0].LocalAddress-cne[string]$worker.endpoint.host-or[int]$socketRows[0].LocalPort-ne[int]$worker.endpoint.port){throw 'worker endpoint socket-owner mismatch'}
  if([string]$Entry.route.host-cne[string]$worker.endpoint.host-or[int]$Entry.route.port-ne[int]$worker.endpoint.port){throw 'worker route/endpoint mismatch'}
  $Generation
}

function Assert-UID00028DWorkerSocketOwner($Entry,[scriptblock]$SocketQuery) {
  $worker=$Entry.attestation.worker;$generation=Get-UID00028DProcessGeneration worker ([int]$worker.process.pid);$sockets=@(&$SocketQuery ([string]$worker.endpoint.host) ([int]$worker.endpoint.port))
  Assert-UID00028DWorkerSocketOwnerCore $Entry $generation $sockets
}

function Assert-UID00028DRuntimeAttestation($Coordinator,$Attestation,$SessionRow,[string]$Database,[string]$ExpectedPath,[Int64]$OpenStartedFileTime100ns) {
  $a=$Attestation.Envelope.result.structuredContent;$expectedFull=[IO.Path]::GetFullPath($ExpectedPath)
  if([int]$a.schema_version-ne1-or$a.ok-ne$true-or@($a.errors).Count-ne0){throw 'top-level runtime attestation failure'}
  foreach($nonce in @([string]$a.listener.nonce)+@($a.workers|ForEach-Object{[string]$_.attestation.worker.nonce})){if([string]::IsNullOrWhiteSpace($nonce)-or-not$Coordinator.SeenNonces.Add($nonce)){throw 'missing or reused runtime nonce'}}
  if($a.listener.role-cne'supervisor_listener'-or$a.listener.endpoint.host-cne'127.0.0.1'-or[int]$a.listener.endpoint.port-ne13337){throw 'listener endpoint mismatch'}
  $listenerGeneration=Get-UID00028DProcessGeneration listener ([int]$a.listener.process.pid);$listenerSockets=@(Get-NetTCPConnection -State Listen -LocalAddress 127.0.0.1 -LocalPort 13337 -ErrorAction Stop)
  if($listenerSockets.Count-ne1-or[int]$listenerSockets[0].OwningProcess-ne$listenerGeneration.Pid-or$listenerGeneration.ParentPid-ne[int]$a.listener.process.parent_pid-or$listenerGeneration.CreationFileTime100ns-cne[string]$a.listener.process.creation_time_100ns){throw 'passive listener generation/port ownership mismatch'}
  Assert-UID00028DLoadedManifest $a.listener listener $Uid00028dListenerManifestSHA256 $Uid00028dListenerModuleNames
  foreach($entry in @($a.workers)){if([int]$entry.attestation.schema_version-ne1-or$entry.attestation.ok-ne$true-or@($entry.attestation.errors).Count-ne0){throw 'active worker attestation failure'};Assert-UID00028DLoadedManifest $entry.attestation.worker worker $Uid00028dWorkerManifestSHA256 $Uid00028dWorkerModuleNames;foreach($row in @($entry.supervisor_sessions)){Assert-UID00028DSupervisorSessionShape $row|Out-Null}}
  $matches=@($a.workers|Where-Object{@($_.supervisor_sessions|Where-Object{[string]$_.session_id-ceq$Database-and[IO.Path]::GetFullPath([string]$_.canonical_path)-ieq$expectedFull}).Count-eq1})
  if($matches.Count-ne1){throw 'expected session does not map to one attested worker'};$route=$matches[0];$supervisorSession=@($route.supervisor_sessions|Where-Object{[string]$_.session_id-ceq$Database})[0]
  if($supervisorSession.backend-cne'worker'-or$supervisorSession.owned-ne$true-or[int]$supervisorSession.redirector_pid-ne[int]$supervisorSession.registered_pid-or[int]$supervisorSession.redirector_pid-ne[int]$SessionRow.worker_pid){throw 'redirector/registered/session route mismatch'}
  $worker=$route.attestation.worker;$workerGeneration=Get-UID00028DProcessGeneration worker ([int]$worker.process.pid);$redirectorGeneration=Get-UID00028DProcessGeneration redirector ([int]$supervisorSession.redirector_pid)
  if($workerGeneration.ParentPid-ne$redirectorGeneration.Pid-or$workerGeneration.CreationFileTime100ns-cne[string]$worker.process.creation_time_100ns-or[Int64]$workerGeneration.CreationFileTime100ns-lt$OpenStartedFileTime100ns){throw 'worker parent/generation mismatch'}
  Assert-UID00028DWorkerSocketOwnerCore $route $workerGeneration @(Get-NetTCPConnection -State Listen -LocalAddress ([string]$worker.endpoint.host) -LocalPort ([int]$worker.endpoint.port) -ErrorAction Stop)|Out-Null
  $inner=@($route.attestation.sessions|Where-Object{[string]$_.session_id-ceq$Database-and[IO.Path]::GetFullPath([string]$_.canonical_path)-ieq$expectedFull});if($inner.Count-ne1){throw 'worker session/path mismatch'}
  [pscustomobject]@{Raw=$Attestation.Raw;Record=$a;ListenerGeneration=$listenerGeneration;RedirectorGeneration=$redirectorGeneration;WorkerGeneration=$workerGeneration;Route=$route;InnerSession=$inner[0]}
}

function Invoke-UID00028DProvisionalOpenCore([scriptblock]$Open,[scriptblock]$Corroborate,[scriptblock]$Attest,[scriptblock]$Retire) {
  $provisional=$null;$committed=$false
  try{
    $session=&$Open;$provisional=[pscustomobject]@{Database=[string]$session.session_id;Path=[IO.Path]::GetFullPath([string]$session.input_path);OpenStartedFileTime100ns=[Int64]$session.open_started_filetime_100ns;OpenResponseRaw=[string]$session.open_response_raw}
    if([string]::IsNullOrWhiteSpace($provisional.Database)-or[string]::IsNullOrWhiteSpace($provisional.OpenResponseRaw)){throw 'idb_open provisional identity incomplete'}
    $corroboration=&$Corroborate $provisional;$binding=&$Attest $provisional $corroboration.Row;$committed=$true
    [pscustomobject]@{Provisional=$provisional;SessionRow=$corroboration.Row;IdbListResponseRaw=[string]$corroboration.Raw;Binding=$binding}
  }finally{if($null-ne$provisional-and-not$committed){&$Retire $provisional}}
}

function Open-UID00028DRole($Coordinator,$RuntimeSurface,[string]$Role,[string]$Path) {
  if($null-eq$RuntimeSurface-or$RuntimeSurface.Definition.name-cne'runtime_attestation'){throw 'validated public runtime surface is required'}
  $full=[IO.Path]::GetFullPath($Path);$preferred="uid00028d-$($Role.ToLowerInvariant())-$([Guid]::NewGuid().ToString('N'))";$started=[DateTime]::UtcNow.ToFileTimeUtc()
  $opened=Invoke-UID00028DProvisionalOpenCore {
    $open=Invoke-UID00028DMcpToolRaw $Coordinator $Role idb_open ([ordered]@{input_path=$full;mode='force_headless';run_auto_analysis=$false;build_caches=$false;init_hexrays=$false;idle_ttl_sec=600;preferred_session_id=$preferred});$session=$open.Envelope.result.structuredContent.session
    if($open.Envelope.result.structuredContent.success-ne$true-or[string]::IsNullOrWhiteSpace([string]$session.session_id)-or[IO.Path]::GetFullPath([string]$session.input_path)-ine$full-or$session.is_analyzing-ne$false){throw 'literal idb_open returned invalid session/path/state'}
    [pscustomobject]@{session_id=[string]$session.session_id;input_path=$full;open_started_filetime_100ns=$started;open_response_raw=[string]$open.Raw}
  } {
    param($provisional);$list=Invoke-UID00028DMcpToolRaw $Coordinator $Role idb_list ([ordered]@{});$rows=@($list.Envelope.result.structuredContent.sessions|Where-Object{[string]$_.session_id-ceq$provisional.Database-and[IO.Path]::GetFullPath([string]$_.input_path)-ieq$provisional.Path})
    if($rows.Count-ne1-or$rows[0].is_analyzing-ne$false-or$rows[0].backend-cne'worker'-or$rows[0].owned-ne$true){throw 'post-open idb_list corroboration failure'};[pscustomobject]@{Row=$rows[0];Raw=[string]$list.Raw}
  } {
    param($provisional,$row);$att=Invoke-UID00028DMcpToolRaw $Coordinator $Role runtime_attestation ([ordered]@{expected_database=$provisional.Database;expected_canonical_path=$provisional.Path});Assert-UID00028DRuntimeAttestation $Coordinator $att $row $provisional.Database $provisional.Path $provisional.OpenStartedFileTime100ns
  } {param($provisional) Stop-UID00028DProvisionalOpen $Coordinator $provisional}
  $record=[pscustomobject]@{Role=$Role;Path=$full;PreferredSessionId=$preferred;Database=$opened.Provisional.Database;OpenResponseRaw=$opened.Provisional.OpenResponseRaw;IdbListResponseRaw=$opened.IdbListResponseRaw;SessionRow=$opened.SessionRow;Binding=$opened.Binding;ListenerGeneration=$opened.Binding.ListenerGeneration;RedirectorGeneration=$opened.Binding.RedirectorGeneration;WorkerGeneration=$opened.Binding.WorkerGeneration}
  $Coordinator.Roles[$Role]=$record;$record
}

function Confirm-UID00028DRoleBoundary($Coordinator,$Role) {
  Assert-UID00028DGenerationCurrent $Role.ListenerGeneration|Out-Null;Assert-UID00028DGenerationCurrent $Role.RedirectorGeneration|Out-Null;Assert-UID00028DGenerationCurrent $Role.WorkerGeneration|Out-Null
  $list=Invoke-UID00028DMcpToolRaw $Coordinator $Role.Role idb_list ([ordered]@{});$rows=@($list.Envelope.result.structuredContent.sessions|Where-Object{[string]$_.session_id-ceq$Role.Database-and[IO.Path]::GetFullPath([string]$_.input_path)-ieq$Role.Path})
  if($rows.Count-ne1){throw 'protected-boundary role/session/path drift'}
  $att=Invoke-UID00028DMcpToolRaw $Coordinator $Role.Role runtime_attestation ([ordered]@{expected_database=$Role.Database;expected_canonical_path=$Role.Path});$binding=Assert-UID00028DRuntimeAttestation $Coordinator $att $rows[0] $Role.Database $Role.Path ([Int64]$Role.WorkerGeneration.CreationFileTime100ns)
  $Role.Binding=$binding;$Role.ListenerGeneration=$binding.ListenerGeneration;$Role.RedirectorGeneration=$binding.RedirectorGeneration;$Role.WorkerGeneration=$binding.WorkerGeneration
}

function Confirm-UID00028DClosedRuntime($Coordinator,[string]$Path) {
  $full=[IO.Path]::GetFullPath($Path);$list=Invoke-UID00028DMcpToolRaw $Coordinator closed idb_list ([ordered]@{});$retained=@($list.Envelope.result.structuredContent.sessions|Where-Object{[IO.Path]::GetFullPath([string]$_.input_path)-ieq$full})
  if($retained.Count-ne0){throw 'closed-file checkpoint has a retained path session'}
  $att=Invoke-UID00028DMcpToolRaw $Coordinator closed runtime_attestation ([ordered]@{});$a=$att.Envelope.result.structuredContent
  if([int]$a.schema_version-ne1-or$a.ok-ne$true-or@($a.errors).Count-ne0){throw 'closed-file public runtime attestation failed'}
  foreach($entry in @($a.workers)){Assert-UID00028DLoadedManifest $entry.attestation.worker worker $Uid00028dWorkerManifestSHA256 $Uid00028dWorkerModuleNames;Assert-UID00028DWorkerSocketOwner $entry {param($host,$port) Get-NetTCPConnection -State Listen -LocalAddress $host -LocalPort $port -ErrorAction Stop}|Out-Null;foreach($row in @($entry.supervisor_sessions)){Assert-UID00028DSupervisorSessionShape $row|Out-Null};if(@($entry.supervisor_sessions|Where-Object{[IO.Path]::GetFullPath([string]$_.canonical_path)-ieq$full}).Count-ne0){throw 'an attested worker retains a supervisor route for the closed path'}}
  [pscustomobject]@{List=$list;Attestation=$att}
}

function Invoke-UID00028DFullCatalog($Coordinator,$Role,[ValidateSet('pre','post')][string]$ExpectedState,$AuthoritativeContractEnvelope,[string]$ReferenceSnapshotJson) {
  $contract=Get-UID00028DImmutableContractView $AuthoritativeContractEnvelope
  Confirm-UID00028DRoleBoundary $Coordinator $Role;$catalog=New-UID00028DFullCatalogJsonLines;$requests=@(Resolve-UID00028DRoleCatalog $Role $catalog 124);$responses=[Collections.Generic.List[object]]::new()
  foreach($request in $requests){$response=Invoke-UID00028DRoleRequest $Coordinator $Role $request;Assert-UID00028DResultOnlyEnvelope $response.Envelope $request.Name $false|Out-Null;$responses.Add($response)}
  Assert-UID00028DPointerLiteralSemantics $responses.ToArray() $ExpectedState $contract|Out-Null;Assert-UID00028DRemainingRegisterSemantics $responses.ToArray() $ExpectedState $contract|Out-Null
  $snapshot=@($responses|Where-Object{$_.Name-cnotin@('idb_list','server_health')}|ForEach-Object{[ordered]@{name=$_.Name;structuredContent=$_.Envelope.result.structuredContent}})|ConvertTo-Json -Depth 100 -Compress
  if($ReferenceSnapshotJson-ceq$UID00028DReportContractReference){if([string]$contract.ContractSHA256-cne($UID00028DReportContractReference-split':',2)[1]){throw 'authoritative report-contract identity mismatch'}}elseif([string]::IsNullOrWhiteSpace($ReferenceSnapshotJson)-or$snapshot-cne$ReferenceSnapshotJson){throw "complete $ExpectedState snapshot differs from its immutable role reference"}
  [pscustomobject]@{State=$ExpectedState;CatalogCount=$requests.Count;Responses=$responses.ToArray();SnapshotJson=$snapshot}
}

function Assert-UID00028DCompleteTupleCore($Tuple) {
  if($null-eq$Tuple-or[string]::IsNullOrWhiteSpace([string]$Tuple.Path)-or[Int64]$Tuple.Size-lt0-or[string]$Tuple.SHA256-notmatch'^[0-9A-F]{64}$'-or[string]::IsNullOrWhiteSpace([string]$Tuple.LastWriteTimeUtc)-or[Int64]$Tuple.LastWriteTimeUtcTicks-le0){throw 'closed-file tuple is null or incomplete'}
  $Tuple
}

function Get-UID00028DClosedDiskClassCore($Actual,$P0,$TransactionTuple) {
  Assert-UID00028DCompleteTupleCore $Actual|Out-Null;Assert-UID00028DCompleteTupleCore $P0|Out-Null
  try{Assert-ExactTuple $Actual $P0;return [pscustomobject]@{Class='P0';Tuple=$Actual}}catch{}
  if($null-ne$TransactionTuple){Assert-UID00028DCompleteTupleCore $TransactionTuple|Out-Null;try{Assert-ExactTuple $Actual $TransactionTuple;return [pscustomobject]@{Class='P1';Tuple=$Actual}}catch{}}
  throw 'closed disk is neither exact P0 nor exact transaction-attributable P1'
}

function Get-UID00028DClosedDiskClass($Coordinator,$P0,$TransactionTuple) {
  $actual=Capture-UID00028DClosedTuple $Coordinator $canonical;Get-UID00028DClosedDiskClassCore $actual $P0 $TransactionTuple
}

function Invoke-UID00028DRoleScopeCore([scriptblock]$Open,[scriptblock]$Use,[scriptblock]$Retire) {
  $resource=$null;$result=$null;$closed=$null;$failure=$null;$retireCount=0
  try{$resource=&$Open;$result=&$Use $resource}catch{$failure=$_}finally{if($null-ne$resource){$closed=&$Retire $resource;$retireCount++}}
  if($retireCount-ne1){throw 'scope-owned retirement count mismatch'}
  [pscustomobject]@{Result=$result;ClosedTuple=$closed;Failure=$failure;RetirementCount=$retireCount}
}

function Invoke-UID00028DFreshVerifier($Coordinator,[string]$RoleName,[string]$Path,[ValidateSet('pre','post')][string]$State,[string]$ReferenceSnapshotJson) {
  if([string]::IsNullOrWhiteSpace($ReferenceSnapshotJson)){throw 'fresh verifier requires a complete reference snapshot'}
  $scope=Invoke-UID00028DRoleScopeCore {Open-UID00028DRole $Coordinator $UID00028DRuntimeSurface $RoleName $Path} {param($role) Invoke-UID00028DFullCatalog $Coordinator $role $State $Coordinator.AuthoritativeContract $ReferenceSnapshotJson} {param($role) Stop-UID00028DRoleWithoutSave $Coordinator $role}
  if($null-ne$scope.Failure){throw $scope.Failure};[pscustomobject]@{RoleName=$RoleName;Result=$scope.Result;ClosedTuple=$scope.ClosedTuple;RetirementCount=$scope.RetirementCount}
}

function Invoke-UID00028DPreflightScope($Coordinator,$RuntimeSurface,[string]$Path) {
  $scope=Invoke-UID00028DRoleScopeCore {Open-UID00028DRole $Coordinator $RuntimeSurface Wpre $Path} {param($role) Invoke-UID00028DFullCatalog $Coordinator $role pre $Coordinator.AuthoritativeContract $UID00028DReportContractReference} {param($role) Stop-UID00028DRoleWithoutSave $Coordinator $role}
  if($null-ne$scope.Failure){throw $scope.Failure};$Coordinator.P0=$scope.ClosedTuple;[pscustomobject]@{Snapshot=$scope.Result;P0=$scope.ClosedTuple;RetirementCount=$scope.RetirementCount}
}

function Invoke-UID00028DTransactionScope($Coordinator,$RuntimeSurface,[string]$Path,[string]$PreSnapshotJson,[string]$CatalogText) {
  $scope=Invoke-UID00028DRoleScopeCore {Open-UID00028DRole $Coordinator $RuntimeSurface Wtx $Path} {param($role) $Coordinator.TransactionRole=[string]$role.Role;$pre=Invoke-UID00028DFullCatalog $Coordinator $role pre $Coordinator.AuthoritativeContract $PreSnapshotJson;$result=Invoke-UID00028DTransactionCatalog $Coordinator $role $CatalogText;[pscustomobject]@{Prestate=$pre;Result=$result}} {param($role) Stop-UID00028DRoleWithoutSave $Coordinator $role}
  $Coordinator.TransactionTuple=$scope.ClosedTuple
  if($null-ne$scope.Failure){return [pscustomobject]@{Prestate=$null;Result=[pscustomobject]@{Classification='unsaved-failure';Failure=$scope.Failure.Exception.Message};TransactionTuple=$scope.ClosedTuple;RoleName=$Coordinator.TransactionRole;RetirementCount=$scope.RetirementCount}}
  [pscustomobject]@{Prestate=$scope.Result.Prestate;Result=$scope.Result.Result;TransactionTuple=$scope.ClosedTuple;RoleName=$Coordinator.TransactionRole;RetirementCount=$scope.RetirementCount}
}

function Get-UID00028DSaveClassification($Coordinator,$Role,$Save) {
  if([int]$Coordinator.SaveAttemptCount-ne1){throw 'save classifier requires exactly one consumed attempt'}
  if($null-ne$Save.TransportException-or$null-eq$Save.Envelope){$Coordinator.SaveState='indeterminate';return 'indeterminate-response'}
  try{$result=Assert-UID00028DResultOnlyEnvelope $Save.Envelope idb_save $true;$isError=Get-UID00028DOptionalProperty $result isError;$data=Get-UID00028DOptionalProperty $result structuredContent;if($isError.Present-and$isError.Value-eq$true){$Coordinator.SaveState='determinate-failure';return 'determinate-tool-error'};if(-not$data.Present-or$null-eq$data.Value){$Coordinator.SaveState='indeterminate';return 'indeterminate-response'};$ok=Get-UID00028DOptionalProperty $data.Value ok;$path=Get-UID00028DOptionalProperty $data.Value path;$error=Get-UID00028DOptionalProperty $data.Value error;if($ok.Present-and$ok.Value-eq$true-and$path.Present-and[IO.Path]::GetFullPath([string]$path.Value)-ieq$Role.Path){$Coordinator.SaveState='definite-success';return 'definite-success'};if($ok.Present-and$ok.Value-eq$false-and$error.Present){$Coordinator.SaveState='determinate-failure';return 'determinate-tool-failure'}}catch{$Coordinator.SaveState='indeterminate';return 'indeterminate-response'}
  $Coordinator.SaveState='indeterminate';'indeterminate-response'
}

function Invoke-UID00028DTransactionCatalog($Coordinator,$Role,[string]$CatalogText) {
  Assert-UID00028DCatalog $CatalogText 310 $UID00028DTransactionCatalogSHA256 $UID00028DTransactionCatalogHistogram type_query idb_save -RequireFinalSave|Out-Null
  $expectations=New-UID00028DOrdinalExpectationCatalog $CatalogText $Coordinator.AuthoritativeContract;$requests=@(Resolve-UID00028DRoleCatalog $Role $CatalogText 310)
  if($requests.Count-ne310-or@($requests|Where-Object{$_.Name-ceq'idb_save'}).Count-ne1-or$requests[309].Name-cne'idb_save'){throw '310-call catalog must end in exactly one idb_save'}
  Confirm-UID00028DRoleBoundary $Coordinator $Role
  for($i=0;$i-lt309;$i++){$response=Invoke-UID00028DRoleRequest $Coordinator $Role $requests[$i];Assert-UID00028DExactOrdinalResponse $expectations $requests[$i] $response $i $Coordinator.AuthoritativeContract|Out-Null}
  $post=Invoke-UID00028DFullCatalog $Coordinator $Role post $Coordinator.AuthoritativeContract $UID00028DReportContractReference;$Coordinator.PostSnapshot=$post.SnapshotJson
  Confirm-UID00028DRoleBoundary $Coordinator $Role;$save=Invoke-UID00028DRoleRequest $Coordinator $Role $requests[309];$classification=Get-UID00028DSaveClassification $Coordinator $Role $save
  [pscustomobject]@{SaveResponse=$save;PostSnapshotJson=$post.SnapshotJson;Classification=$classification;ExpectationCatalogSHA256=$expectations.SHA256}
}

function Invoke-UID00028DOutcomeCore([string]$Classification,[string]$DiskClass,[scriptblock]$VerifyPre,[scriptblock]$VerifyPost,[scriptblock]$Restore) {
  if($Classification-cnotin@('definite-success','determinate-tool-error','determinate-tool-failure','indeterminate-response','unsaved-failure')){throw 'unknown save classification'}
  if($DiskClass-ceq'P0'){
    if($Classification-ceq'definite-success'){throw 'definite save success produced exact P0'}
    &$VerifyPre|Out-Null;return [pscustomobject]@{Outcome='verified-p0';Classification=$Classification}
  }
  if($DiskClass-cne'P1'){throw 'closed disk is neither exact P0 nor exact transaction-attributable P1'}
  try{&$VerifyPost|Out-Null;[pscustomobject]@{Outcome='verified-post';Classification=$Classification}}
  catch{&$Restore|Out-Null;&$VerifyPre|Out-Null;[pscustomobject]@{Outcome='restored-p0';Classification=$Classification;PostFailure=$_.Exception.Message}}
}

function Complete-UID00028DTransactionOutcome($Coordinator,$ScopeResult,$P0,$B0Tuple,[string]$PreSnapshotJson) {
  $classification=[string]$ScopeResult.Result.Classification;$transactionTuple=$ScopeResult.TransactionTuple;$disk=Get-UID00028DClosedDiskClass $Coordinator $P0 $transactionTuple
  $outcome=Invoke-UID00028DOutcomeCore $classification $disk.Class {
    $verifier=Invoke-UID00028DFreshVerifier $Coordinator 'Wverify-P0' $canonical pre $PreSnapshotJson;Assert-ExactTuple $verifier.ClosedTuple $P0
  } {
    $verifier=Invoke-UID00028DFreshVerifier $Coordinator 'Wverify-post' $canonical post $Coordinator.PostSnapshot;Assert-ExactTuple $verifier.ClosedTuple $transactionTuple
  } {
    $restored=Restore-UID00028DBackup $Coordinator $P0 $B0Tuple $transactionTuple;$verifier=Invoke-UID00028DFreshVerifier $Coordinator 'Wverify-restore' $canonical pre $PreSnapshotJson;Assert-ExactTuple $verifier.ClosedTuple $P0;$restored
  }
  [pscustomobject]@{Outcome=$outcome.Outcome;Tuple=$(if($outcome.Outcome-ceq'verified-post'){$transactionTuple}else{$P0});Classification=$classification}
}

function Invoke-UID00028DHostileFixtures([string]$FullCatalog,[string]$TransactionCatalog) {
  $passed=[Collections.Generic.List[string]]::new();$effects=[pscustomobject]@{Mcp=0;Ida=0;Process=0;File=0};$rt='System.Management.Automation.RuntimeException'
  function AddPass([string]$Label){$passed.Add($Label)}
  $schema=[pscustomobject][ordered]@{type='object';properties=[pscustomobject][ordered]@{expected_database=[pscustomobject][ordered]@{type='string';default='';description='Optional exact session ID returned by idb_open; mismatch fails closed.'};expected_canonical_path=[pscustomobject][ordered]@{type='string';default='';description='Optional exact canonical IDB path; mismatch fails closed.'}};required=@()}
  $bad=$schema|ConvertTo-Json -Depth 20|ConvertFrom-Json;$bad.properties.expected_database.default='x';AddPass(Assert-UID00028DThrowsExact {Assert-UID00028DRuntimeInputSchema $bad} $rt 'runtime_attestation property schema drift: expected_database' schema-default-drift)
  $bad=$schema|ConvertTo-Json -Depth 20|ConvertFrom-Json;$bad|Add-Member extra $true;AddPass(Assert-UID00028DThrowsExact {Assert-UID00028DRuntimeInputSchema $bad} $rt 'runtime_attestation schema top-level drift or unexpected property' schema-extra-property)
  $valid=ConvertFrom-UID00028DExactJsonRpc '{"jsonrpc":"2.0","id":7,"result":{"ok":true}}' 7;if($valid.result.ok-ne$true){throw 'valid parser fixture failed'};AddPass response-valid-ps51
  AddPass(Assert-UID00028DThrowsExact {ConvertFrom-UID00028DExactJsonRpc '{"jsonrpc":"2.0","id":7,"result":{},"result":{}}' 7} $rt 'JSON-RPC duplicate top-level member: result' response-duplicate-member)
  AddPass(Assert-UID00028DThrowsExact {ConvertFrom-UID00028DExactJsonRpc '{"jsonrpc":"1.0","id":7,"result":{}}' 7} $rt 'JSON-RPC version/type mismatch' response-version)
  AddPass(Assert-UID00028DThrowsExact {ConvertFrom-UID00028DExactJsonRpc '{"jsonrpc":"2.0","id":"7","result":{}}' 7} $rt 'JSON-RPC response ID JSON type mismatch' response-id-type)
  AddPass(Assert-UID00028DThrowsExact {ConvertFrom-UID00028DExactJsonRpc '{"jsonrpc":"2.0","id":8,"result":{}}' 7} $rt 'JSON-RPC response ID value mismatch: expected 7' response-id-value)
  $result=Assert-UID00028DResultOnlyEnvelope ([pscustomobject]@{result=[pscustomobject]@{isError=$false;structuredContent=[pscustomobject]@{ok=$true}}}) inspect_items $false;if($result.structuredContent.ok-ne$true){throw 'result-only envelope did not reach semantics'};AddPass strict-result-only-envelope
  AddPass(Assert-UID00028DThrowsExact {Assert-UID00028DResultOnlyEnvelope ([pscustomobject]@{result=[pscustomobject]@{};error=[pscustomobject]@{}}) inspect_items $false} $rt 'MCP envelope result/error shape mismatch: inspect_items' strict-top-error)
  $role=[pscustomobject]@{Role='fixture';Database='returned-session';OpenResponseRaw='literal-open-response'};$fullResolved=@(Resolve-UID00028DRoleCatalog $role $FullCatalog 124);if($fullResolved.Count-ne124-or@($fullResolved|Where-Object{$_.Name-cne'idb_list'-and$_.Arguments.database-cne'returned-session'}).Count-ne0){throw 'full resolver substitution'};AddPass full-catalog-resolves-124
  $txResolved=@(Resolve-UID00028DRoleCatalog $role $TransactionCatalog 310);if($txResolved.Count-ne310-or@($txResolved|Where-Object{$_.Arguments.database-cne'returned-session'}).Count-ne0){throw 'transaction resolver substitution'};AddPass transaction-catalog-resolves-310
  $badCatalog=$TransactionCatalog.Replace('__ROLE_DATABASE__','wrong');AddPass(Assert-UID00028DThrowsExact {Resolve-UID00028DRoleCatalog $role $badCatalog 310} $rt 'catalog row database token mismatch: type_query' catalog-wrong-token)
  $duplicateLines=@($FullCatalog-split'[\r\n]+'|Where-Object{$_});$duplicateLines[1]=$duplicateLines[0];$duplicateText=$duplicateLines-join"`n";$duplicateCanonical=@($duplicateLines|ForEach-Object{$_|ConvertFrom-Json|ConvertTo-Json -Depth 100 -Compress})-join"`n";$duplicateMessage='catalog canonical hash/order/content drift: '+(Get-UID00028DSha256Text $duplicateCanonical);AddPass(Assert-UID00028DThrowsExact {Assert-UID00028DCatalog $duplicateText 124 $UID00028DFullCatalogSHA256 $UID00028DFullCatalogHistogram idb_list get_bytes} $rt $duplicateMessage catalog-duplicate)
  $contract=New-UID00028DAuthoritativePhysicalContract $Uid00028dReportPath;$view=Get-UID00028DImmutableContractView $contract;$view.Pointers[0].Target='0xdeadbeef';if((Get-UID00028DImmutableContractView $contract).Pointers[0].Target-ceq'0xdeadbeef'){throw 'parsed contract view mutated canonical contract'};AddPass immutable-view-isolated
  $changed=[pscustomobject]@{CanonicalJson=$contract.CanonicalJson.Replace('0x6707d4','0xdeadbeef');SHA256=$contract.SHA256};AddPass(Assert-UID00028DThrowsExact {Get-UID00028DImmutableContractView $changed} $rt 'immutable contract hash mismatch' immutable-contract-mutation)
  $expectations=New-UID00028DOrdinalExpectationCatalog $TransactionCatalog $contract;if($expectations.Count-ne310-or([string]$expectations.CanonicalJson|ConvertFrom-Json).Count-ne310){throw 'ordinal count'};AddPass ordinal-catalog-310
  $expectedItem=@([pscustomobject]@{addr='0x1';head='0x1';end='0x5';size=4;name='n';type='t';is_code=$false;is_data=$true});$badItem=@([pscustomobject]@{addr='0x1';head='0x0';end='0x5';size=4;name='n';type='t';is_code=$false;is_data=$true});AddPass(Assert-UID00028DThrowsExact {Assert-UID00028DExactItemRowsCore $expectedItem $badItem ordinal-item} $rt 'ordinal-item exact item identity mismatch at row 1' ordinal-item-identity)
  $expectedByte=@([pscustomobject]@{addr='0x1';size=2;sha256=(Get-UID00028DByteSHA256 ([byte[]](1,2)))});$badByte=@([pscustomobject]@{addr='0x1';size=2;data='01 03'});AddPass(Assert-UID00028DThrowsExact {Assert-UID00028DExactByteRowsCore $expectedByte $badByte ordinal-byte} $rt 'ordinal-byte exact byte content mismatch at row 1' ordinal-byte-content)
  $expectedComment=@([pscustomobject]@{addr='0x1';regular='';repeatable='r';function_regular='f';function_repeatable=''});$badComment=@([pscustomobject]@{addr='0x1';regular='';repeatable='r';function_regular='wrong';function_repeatable=''});AddPass(Assert-UID00028DThrowsExact {Assert-UID00028DExactCommentRowsCore $expectedComment $badComment ordinal-comment} $rt 'ordinal-comment exact four-channel comment mismatch at row 1' ordinal-four-channel-comments)
  $saveCoordinator=[pscustomobject]@{SaveAttemptCount=1;SaveState='dispatched'};$saveRole=[pscustomobject]@{Path=$canonical};$save=[pscustomobject]@{TransportException=$null;Envelope=[pscustomobject]@{result=[pscustomobject]@{isError=$false;structuredContent=[pscustomobject]@{ok=$true;path=$canonical}}}};if((Get-UID00028DSaveClassification $saveCoordinator $saveRole $save)-cne'definite-success'){throw 'save success classification'};AddPass save-definite-success
  $saveCoordinator.SaveState='dispatched';$save.Envelope.result.structuredContent=[pscustomobject]@{ok=$false;error='x'};if((Get-UID00028DSaveClassification $saveCoordinator $saveRole $save)-cne'determinate-tool-failure'){throw 'save failure classification'};AddPass save-determinate-failure
  $saveCoordinator.SaveState='dispatched';$save.TransportException='timeout';$save.Envelope=$null;if((Get-UID00028DSaveClassification $saveCoordinator $saveRole $save)-cne'indeterminate-response'){throw 'save timeout classification'};AddPass save-indeterminate
  $double=[pscustomobject]@{SaveAttemptCount=0;SaveState='not-dispatched'};Start-UID00028DSaveAttempt $double;AddPass(Assert-UID00028DThrowsExact {Start-UID00028DSaveAttempt $double} $rt 'second idb_save attempt forbidden' save-no-retry)
  $c=[pscustomobject]@{Pre=0;Post=0;Restore=0};$o=Invoke-UID00028DOutcomeCore definite-success P1 {$c.Pre++} {$c.Post++} {$c.Restore++};if($o.Outcome-cne'verified-post'-or$c.Post-ne1-or$c.Restore-ne0){throw 'definite coordinator path'};AddPass coordinator-definite-success
  $c=[pscustomobject]@{Pre=0;Post=0;Restore=0};$o=Invoke-UID00028DOutcomeCore determinate-tool-failure P0 {$c.Pre++} {$c.Post++} {$c.Restore++};$o2=Invoke-UID00028DOutcomeCore unsaved-failure P0 {$c.Pre++} {$c.Post++} {$c.Restore++};if($o.Outcome-cne'verified-p0'-or$o2.Outcome-cne'verified-p0'-or$c.Pre-ne2-or$c.Post-ne0-or$c.Restore-ne0){throw 'P0 coordinator paths'};AddPass coordinator-determinate-p0
  $c=[pscustomobject]@{Pre=0;Post=0;Restore=0};$o=Invoke-UID00028DOutcomeCore indeterminate-response P1 {$c.Pre++} {$c.Post++} {$c.Restore++};if($o.Outcome-cne'verified-post'-or$c.Post-ne1){throw 'indeterminate post coordinator path'};AddPass coordinator-indeterminate-post
  AddPass(Assert-UID00028DThrowsExact {Invoke-UID00028DOutcomeCore determinate-tool-error THIRD {} {} {}} $rt 'closed disk is neither exact P0 nor exact transaction-attributable P1' coordinator-third-identity)
  $c=[pscustomobject]@{Pre=0;Post=0;Restore=0};$o=Invoke-UID00028DOutcomeCore determinate-tool-error P1 {$c.Pre++} {throw 'invalid-post'} {$c.Restore++};if($o.Outcome-cne'restored-p0'-or$c.Pre-ne1-or$c.Restore-ne1){throw 'invalid post restore coordinator path'};AddPass coordinator-invalid-post-restores
  $retired=[pscustomobject]@{Count=0};$scope=Invoke-UID00028DRoleScopeCore {1} {param($r)'used'} {param($r)$retired.Count++;'closed'};if($scope.RetirementCount-ne1-or$retired.Count-ne1-or$scope.ClosedTuple-cne'closed'){throw 'scope retirement count'};AddPass single-scope-retirement
  $cleanup=[pscustomobject]@{Count=0};AddPass(Assert-UID00028DThrowsExact {Invoke-UID00028DProvisionalOpenCore {[pscustomobject]@{session_id='s';input_path=$canonical;open_started_filetime_100ns=1;open_response_raw='raw'}} {param($p)throw 'corroboration failed'} {param($p,$r)} {param($p)$cleanup.Count++}} $rt 'corroboration failed' provisional-open-cleanup);if($cleanup.Count-ne1){throw 'provisional cleanup count'}
  $generation=[pscustomobject]@{Pid=55;CreationFileTime100ns='100'};$entry=[pscustomobject]@{route=[pscustomobject]@{host='127.0.0.1';port=17777};attestation=[pscustomobject]@{worker=[pscustomobject]@{process=[pscustomobject]@{pid=55;creation_time_100ns='100'};endpoint=[pscustomobject]@{host='127.0.0.1';port=17777}}}};$socket=@([pscustomobject]@{OwningProcess=55;LocalAddress='127.0.0.1';LocalPort=17777});Assert-UID00028DWorkerSocketOwnerCore $entry $generation $socket|Out-Null;AddPass worker-socket-owner-positive
  $wrongSocket=@([pscustomobject]@{OwningProcess=56;LocalAddress='127.0.0.1';LocalPort=17777});AddPass(Assert-UID00028DThrowsExact {Assert-UID00028DWorkerSocketOwnerCore $entry $generation $wrongSocket} $rt 'worker endpoint socket-owner mismatch' worker-socket-owner-mismatch)
  $tuple=[pscustomobject]@{Path=$canonical;Size=1;SHA256=('A'*64);LastWriteTimeUtc='2026-01-01T00:00:00.0000000Z';LastWriteTimeUtcTicks=1};if((Assert-UID00028DCompleteTupleCore $tuple).SHA256-cne('A'*64)){throw 'tuple core'};AddPass closed-tuple-capture
  AddPass(Assert-UID00028DThrowsExact {Assert-ExactTuple $tuple ([pscustomobject]@{Path=$canonical;Size=1;SHA256=('B'*64);LastWriteTimeUtc=$tuple.LastWriteTimeUtc;LastWriteTimeUtcTicks=1})} $rt 'closed-file tuple mismatch' closed-tuple-assertion)
  $p1=[pscustomobject]@{Path=$canonical;Size=1;SHA256=('B'*64);LastWriteTimeUtc=$tuple.LastWriteTimeUtc;LastWriteTimeUtcTicks=2};if((Get-UID00028DClosedDiskClassCore $p1 $tuple $p1).Class-cne'P1'){throw 'closed disk classification core'};AddPass closed-disk-classification
  $removed=[pscustomobject]@{Count=0};AddPass(Assert-UID00028DThrowsExact {Invoke-UID00028DBackupCleanupCore {throw 'copy failed'} {param($x)} {$removed.Count++} {if($removed.Count-ne1){throw 'partial remains'}}} $rt 'copy failed' backup-partial-cleanup);if($removed.Count-ne1){throw 'backup cleanup count'}
  $recovery=Invoke-UID00028DRestoreRecoveryCore {throw 'mid-copy'} {$tuple} {param($t)Assert-ExactTuple $t $tuple} {param($a,$b)};if($recovery.Outcome-cne'recovered-p0'){throw 'restore recovery outcome'};AddPass restore-mid-copy-recovers-p0
  $journal=[pscustomobject]@{Count=0};AddPass(Assert-UID00028DThrowsExact {Invoke-UID00028DRestoreRecoveryCore {throw 'mid-copy'} {throw 'recovery failed'} {param($t)} {param($a,$b)$journal.Count++}} $rt 'RESTORE_RECOVERY_REQUIRED' restore-recovery-required);if($journal.Count-ne1){throw 'restore recovery journal count'}
  if($effects.Mcp-ne0-or$effects.Ida-ne0-or$effects.Process-ne0-or$effects.File-ne0){throw 'fixture external-effect instrumentation is nonzero'}
  if($passed.Count-ne$UID00028DHostileFixtureCount){throw "hostile fixture count mismatch: $($passed.Count)"};$passed.ToArray()
}

function New-UID00028DTransactionEnvironment {
  $contract=New-UID00028DAuthoritativePhysicalContract $Uid00028dReportPath;$fullCatalog=New-UID00028DFullCatalogJsonLines;$fixtureResults=@(Invoke-UID00028DHostileFixtures $fullCatalog $UID00028DTransactionCatalogJsonLines)
  if($fixtureResults.Count-ne$UID00028DHostileFixtureCount-or@($fixtureResults|Select-Object -Unique).Count-ne$UID00028DHostileFixtureCount){throw 'exact-label hostile fixture gate failed'}
  $transport=New-UID00028DMcpTransport;$coordinator=New-UID00028DCoordinator $transport;$coordinator.AuthoritativeContract=$contract;$surface=Get-UID00028DPublicRuntimeSurface $coordinator
  [pscustomobject]@{Transport=$transport;Coordinator=$coordinator;RuntimeSurface=$surface;AuthoritativeContract=$contract;HostileFixtures=$fixtureResults;ClosureVersion=$UID00028DFinalClosureVersion}
}
~~~

## Removed Block R006

- SHA256: `50E82F8A2D19F3F11F9EC845B47CECDB8A0F93C08575E6613890D6E6E6D7D175`
- Language: `powershell`
- Bytes: `37690`
- First recovered timestamp: `2026-08-07T02:31:14.155Z`
- Session provenance: rollout-2026-08-06T18-23-46-019fd92c-e7fb-7013-873a-d7414f0f3109.jsonl line 196353 (2026-08-07T02:31:14.155Z); rollout-2026-08-06T18-23-46-019fd92c-e7fb-7013-873a-d7414f0f3109.jsonl line 196354 (2026-08-07T02:31:14.208Z)

~~~powershell
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
$UID00028DFinalClosureVersion = 'UID00028D-PS51-CLOSURE-3'
$UID00028DHostileFixtureCount = 64
$UID00028DUsedToolNames = @('idb_open','idb_list','runtime_attestation','server_health','type_query','type_inspect','entity_query','inspect_items','get_comments','xrefs_to','get_bytes','lookup_funcs','stack_frame','disasm','declare_type','rename','set_type','make_data','set_function_comments','set_address_repeatable_comments','idb_save')
$UID00028DExactToolsListRawSHA256 = '4B0C15A719CBB1CE694BF601B8FF320FF7F57C5387C33D53AD4701434C06F16B'

function Get-UID00028DTextSHA3([string]$Text) {
  $sha=[Security.Cryptography.SHA256]::Create()
  try { [BitConverter]::ToString($sha.ComputeHash([Text.UTF8Encoding]::new($false).GetBytes($Text))).Replace('-','') } finally { $sha.Dispose() }
}

function Assert-UID00028DExactMembers3($Value,[string[]]$Names,[string]$Label) {
  if($null -eq $Value){throw "$Label is null"}
  $actual=@($Value.PSObject.Properties|ForEach-Object Name|Sort-Object -CaseSensitive)
  $expected=@($Names|Sort-Object -CaseSensitive)
  if(($actual -join "`u{1f}") -cne ($expected -join "`u{1f}")){throw "$Label member-set mismatch: actual=$($actual-join',') expected=$($expected-join',')"}
  $Value
}

function Skip-UID00028DJsonWhite3([string]$Text,[ref]$Index) {
  while($Index.Value-lt$Text.Length-and[char]::IsWhiteSpace($Text[$Index.Value])){$Index.Value++}
}

function Read-UID00028DJsonString3([string]$Text,[ref]$Index) {
  Skip-UID00028DJsonWhite3 $Text $Index
  if($Index.Value-ge$Text.Length-or$Text[$Index.Value]-ne'"'){throw 'raw JSON expected string'}
  $start=$Index.Value;$Index.Value++;$escaped=$false
  while($Index.Value-lt$Text.Length){
    $c=$Text[$Index.Value];$Index.Value++
    if($escaped){if('"\/bfnrtu'.IndexOf($c)-lt0){throw 'raw JSON invalid escape'};if($c-eq'u'){for($n=0;$n-lt4;$n++){if($Index.Value-ge$Text.Length-or$Text[$Index.Value]-notmatch'[0-9A-Fa-f]'){throw 'raw JSON invalid unicode escape'};$Index.Value++}};$escaped=$false;continue}
    if([int]$c-eq92){$escaped=$true;continue}
    if($c-eq'"'){return $Text.Substring($start,$Index.Value-$start)}
    if([int]$c-lt32){throw 'raw JSON unescaped control character'}
  }
  throw 'raw JSON unterminated string'
}

function Read-UID00028DJsonValue3([string]$Text,[ref]$Index,[string]$Path) {
  Skip-UID00028DJsonWhite3 $Text $Index
  if($Index.Value-ge$Text.Length){throw "raw JSON missing value at $Path"}
  $c=$Text[$Index.Value]
  if($c-eq'{'){
    $Index.Value++;$seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal);Skip-UID00028DJsonWhite3 $Text $Index
    if($Index.Value-lt$Text.Length-and$Text[$Index.Value]-eq'}'){$Index.Value++;return 'object'}
    while($true){
      $token=Read-UID00028DJsonString3 $Text $Index;$name=[string]($token|ConvertFrom-Json)
      if(-not$seen.Add($name)){throw "raw JSON duplicate member at $Path.$name"}
      Skip-UID00028DJsonWhite3 $Text $Index;if($Index.Value-ge$Text.Length-or$Text[$Index.Value]-ne':'){throw "raw JSON missing colon at $Path.$name"};$Index.Value++
      Read-UID00028DJsonValue3 $Text $Index "$Path.$name"|Out-Null;Skip-UID00028DJsonWhite3 $Text $Index
      if($Index.Value-ge$Text.Length){throw "raw JSON unterminated object at $Path"};if($Text[$Index.Value]-eq'}'){$Index.Value++;break};if($Text[$Index.Value]-ne','){throw "raw JSON expected comma at $Path"};$Index.Value++
    }
    return 'object'
  }
  if($c-eq'['){
    $Index.Value++;$ordinal=0;Skip-UID00028DJsonWhite3 $Text $Index
    if($Index.Value-lt$Text.Length-and$Text[$Index.Value]-eq']'){$Index.Value++;return 'array'}
    while($true){Read-UID00028DJsonValue3 $Text $Index "$Path[$ordinal]"|Out-Null;$ordinal++;Skip-UID00028DJsonWhite3 $Text $Index;if($Index.Value-ge$Text.Length){throw "raw JSON unterminated array at $Path"};if($Text[$Index.Value]-eq']'){$Index.Value++;break};if($Text[$Index.Value]-ne','){throw "raw JSON expected array comma at $Path"};$Index.Value++}
    return 'array'
  }
  if($c-eq'"'){Read-UID00028DJsonString3 $Text $Index|Out-Null;return 'string'}
  foreach($literal in @('true','false','null')){if($Text.Substring($Index.Value).StartsWith($literal,[StringComparison]::Ordinal)){$Index.Value+=$literal.Length;return $literal}}
  $number=[regex]::Match($Text.Substring($Index.Value),'^-?(?:0|[1-9][0-9]*)(?:\.[0-9]+)?(?:[eE][+-]?[0-9]+)?')
  if(-not$number.Success){throw "raw JSON invalid value at $Path"};$Index.Value+=$number.Length;'number'
}

function Assert-UID00028DStrictRawJson3([string]$Raw) {
  if([string]::IsNullOrWhiteSpace($Raw)){throw 'raw JSON is empty'}
  $index=0;Read-UID00028DJsonValue3 $Raw ([ref]$index) '$'|Out-Null;Skip-UID00028DJsonWhite3 $Raw ([ref]$index)
  if($index-ne$Raw.Length){throw 'raw JSON has trailing content'}
}

function ConvertFrom-UID00028DExactJsonRpc3([string]$Raw,[Int64]$ExpectedId,[switch]$AllowError) {
  Assert-UID00028DStrictRawJson3 $Raw;$root=$Raw|ConvertFrom-Json
  $names=@($root.PSObject.Properties|ForEach-Object Name);$hasResult=$names-ccontains'result';$hasError=$names-ccontains'error'
  if($hasResult-eq$hasError){throw 'JSON-RPC must contain exactly one result or error'}
  Assert-UID00028DExactMembers3 $root ($(if($hasResult){@('jsonrpc','id','result')}else{@('jsonrpc','id','error')})) 'JSON-RPC root'|Out-Null
  if($root.jsonrpc-isnot[string]-or$root.jsonrpc-cne'2.0'){throw 'JSON-RPC version/type mismatch'}
  if(($root.id-isnot[int])-and($root.id-isnot[Int64])){throw 'JSON-RPC id native type mismatch'}
  if([Int64]$root.id-ne$ExpectedId){throw 'JSON-RPC id value mismatch'}
  if($hasResult){return [pscustomobject]@{Kind='result';Id=[Int64]$root.id;Result=$root.result;Error=$null;Raw=$Raw}}
  if(-not$AllowError){throw 'correlated JSON-RPC error not allowed'}
  Assert-UID00028DExactMembers3 $root.error @('code','message','data') 'JSON-RPC error'|Out-Null
  if((($root.error.code-isnot[int])-and($root.error.code-isnot[Int64]))-or$root.error.message-isnot[string]){throw 'JSON-RPC error native type mismatch'}
  [pscustomobject]@{Kind='error';Id=[Int64]$root.id;Result=$null;Error=$root.error;Raw=$Raw}
}

function Assert-UID00028DExactTree3($Expected,$Actual,[string]$Path='$') {
  if($null-eq$Expected){if($null-ne$Actual){throw "$Path expected null"};return}
  if($null-eq$Actual){throw "$Path actual is null"}
  $et=$Expected.GetType();$at=$Actual.GetType();if($et.FullName-cne$at.FullName){throw "$Path native type mismatch: $($at.FullName) != $($et.FullName)"}
  if($Expected-is[string]-or$Expected-is[ValueType]){if($Actual-cne$Expected){throw "$Path scalar mismatch"};return}
  if($Expected-is[Collections.IList]){if($Actual.Count-ne$Expected.Count){throw "$Path array count mismatch"};for($i=0;$i-lt$Expected.Count;$i++){Assert-UID00028DExactTree3 $Expected[$i] $Actual[$i] "$Path[$i]"};return}
  $names=@($Expected.PSObject.Properties|ForEach-Object Name);Assert-UID00028DExactMembers3 $Actual $names $Path|Out-Null
  foreach($name in $names){Assert-UID00028DExactTree3 $Expected.$name $Actual.$name "$Path.$name"}
}

function Assert-UID00028DToolSchemaAuthority3([string]$Raw,[Int64]$ExpectedId,[string]$ExpectedRawSHA256=$UID00028DExactToolsListRawSHA256) {
  if((Get-UID00028DTextSHA3 $Raw)-cne$ExpectedRawSHA256){throw 'tools/list raw schema identity mismatch'}
  $rpc=ConvertFrom-UID00028DExactJsonRpc3 $Raw $ExpectedId;Assert-UID00028DExactMembers3 $rpc.Result @('tools') 'tools/list result'|Out-Null
  $names=@($rpc.Result.tools|ForEach-Object{Assert-UID00028DExactMembers3 $_ @('name','description','inputSchema') 'tools/list tool'|Out-Null;if($_.name-isnot[string]-or$_.description-isnot[string]){throw 'tools/list tool native type mismatch'};[string]$_.name})
  foreach($name in $UID00028DUsedToolNames){if(@($names|Where-Object{$_-ceq$name}).Count-ne1){throw "used tool schema missing/duplicate: $name"}}
  if(@($names|Where-Object{$_-ceq'runtime_attestation'}).Count-ne1-or@($names|Where-Object{$_-ceq'runtime/attest'}).Count-ne0){throw 'public runtime tool surface mismatch'}
  [pscustomobject]@{Raw=$Raw;SHA256=$ExpectedRawSHA256;UsedNames=[string[]]$UID00028DUsedToolNames;Definitions=$rpc.Result.tools}
}

function New-UID00028DImmutablePlan3([string]$CatalogText,[int]$ExpectedCount,[string]$ExpectedSHA256) {
  if((Get-UID00028DTextSHA3 $CatalogText)-cne$ExpectedSHA256){throw 'catalog raw identity mismatch'}
  $lines=@($CatalogText-split"`n"|Where-Object{$_-cne''});if($lines.Count-ne$ExpectedCount){throw 'catalog row count mismatch'}
  $rows=[Collections.Generic.List[object]]::new();$ordinal=0
  foreach($line in $lines){$ordinal++;Assert-UID00028DStrictRawJson3 $line;$row=$line|ConvertFrom-Json;Assert-UID00028DExactMembers3 $row @('name','arguments') "catalog[$ordinal]"|Out-Null;if($row.name-isnot[string]){throw "catalog[$ordinal] name type mismatch"};$rows.Add([ordered]@{ordinal=$ordinal;name=[string]$row.name;template_json=$line;template_sha256=(Get-UID00028DTextSHA3 $line)})}
  $canonical=$rows.ToArray()|ConvertTo-Json -Depth 100 -Compress
  [pscustomobject]@{CanonicalJson=$canonical;SHA256=(Get-UID00028DTextSHA3 $canonical);RawSHA256=$ExpectedSHA256;Count=$ExpectedCount}
}

function Get-UID00028DImmutablePlanView3($Envelope) {
  if((Get-UID00028DTextSHA3 ([string]$Envelope.CanonicalJson))-cne[string]$Envelope.SHA256){throw 'immutable plan envelope drift'}
  $rows=@(([string]$Envelope.CanonicalJson)|ConvertFrom-Json);if($rows.Count-ne[int]$Envelope.Count){throw 'immutable plan count drift'}
  for($i=0;$i-lt$rows.Count;$i++){if([int]$rows[$i].ordinal-ne$i+1-or(Get-UID00028DTextSHA3 ([string]$rows[$i].template_json))-cne[string]$rows[$i].template_sha256){throw "immutable plan ordinal/template drift: $($i+1)"}}
  $rows
}

function Resolve-UID00028DPlanRow3($Template,[string]$Role,[string]$Database,[string]$Path) {
  $row=([string]$Template.template_json)|ConvertFrom-Json;$count=0
  function ReplaceDatabase($node){if($null-eq$node){return};if($node-is[Collections.IList]){foreach($v in$node){ReplaceDatabase $v};return};foreach($p in@($node.PSObject.Properties)){if($p.Name-ceq'database'){if([string]$p.Value-cne'__ROLE_DATABASE__'){throw "catalog row database token mismatch: $($row.name)"};$p.Value=$Database;$script:count++}elseif($p.Value-isnot[string]-and$null-ne$p.Value){ReplaceDatabase $p.Value}}}
  ReplaceDatabase $row.arguments
  if($row.name-cne'idb_list'-and$count-ne1){throw "catalog row database substitution count mismatch: $($row.name)"};if($row.name-ceq'idb_list'-and$count-ne0){throw 'idb_list unexpectedly binds database'}
  $resolved=$row|ConvertTo-Json -Depth 100 -Compress;$binding=[ordered]@{role=$Role;database=$Database;path=[IO.Path]::GetFullPath($Path)}|ConvertTo-Json -Compress
  [pscustomobject]@{Ordinal=[int]$Template.ordinal;Name=[string]$row.name;Arguments=$row.arguments;TemplateSHA256=[string]$Template.template_sha256;ResolvedSHA256=(Get-UID00028DTextSHA3 $resolved);RoleBindingSHA256=(Get-UID00028DTextSHA3 $binding);ResolvedJson=$resolved}
}

function Resolve-UID00028DPlan3($Envelope,[string]$Role,[string]$Database,[string]$Path) {
  @(Get-UID00028DImmutablePlanView3 $Envelope|ForEach-Object{Resolve-UID00028DPlanRow3 $_ $Role $Database $Path})
}

function Assert-UID00028DSourceBoundary3($Boundary) {
  Assert-UID00028DExactMembers3 $Boundary @('TargetStart','TargetEnd','TargetSize','TargetSHA256','PredecessorName','PredecessorType','PredecessorEnd','SuccessorName','SuccessorStart','SuccessorText') 'source boundary'|Out-Null
  if($Boundary.TargetStart-cne'0x006707d4'-or$Boundary.TargetEnd-cne'0x00671a74'-or[Int64]$Boundary.TargetSize-ne4768-or$Boundary.TargetSHA256-cne'80FF9CBA042305575D19F6378459A619877E1879D3E69692F3BC8DDBE71CAEDA'-or$Boundary.PredecessorName-cne's_snowPatterns'-or$Boundary.PredecessorType-cne'unsigned __int8[2][16]'-or$Boundary.PredecessorEnd-cne'0x006707d4'-or$Boundary.SuccessorName-cne'a114'-or$Boundary.SuccessorStart-cne'0x00671a74'-or$Boundary.SuccessorText-cne'1.1.4'){throw 'source/third-party boundary semantic mismatch'}
  $Boundary
}

function Assert-UID00028DLoadedRuntime3($Actual,$Expected,[scriptblock]$FileProbe,[scriptblock]$SocketProbe) {
  Assert-UID00028DExactTree3 $Expected.Shape $Actual '$runtime-shape'
  $normalized=[Collections.Generic.List[object]]::new()
  foreach($row in@($Actual.modules|Sort-Object -Property name)){
    $probe=&$FileProbe ([string]$row.resolved_path);if([string]$probe.Path-cne[string]$row.resolved_path-or[Int64]$probe.Size-ne[Int64]$row.size-or[string]$probe.SHA256-cne[string]$row.sha256){throw "loaded module file proof mismatch: $($row.name)"}
    $normalized.Add([ordered]@{name=[string]$row.name;file=[string]$row.file;spec_origin=[string]$row.spec_origin;resolved_path=[string]$row.resolved_path;size=[Int64]$row.size;sha256=[string]$row.sha256})
  }
  $manifest=$normalized.ToArray()|ConvertTo-Json -Depth 20 -Compress;if((Get-UID00028DTextSHA3 $manifest)-cne[string]$Expected.ManifestSHA256){throw 'loaded module deterministic manifest mismatch'}
  $sockets=@(&$SocketProbe ([string]$Actual.endpoint.host) ([int]$Actual.endpoint.port));if($sockets.Count-ne1-or[int]$sockets[0].OwningProcess-ne[int]$Actual.process.pid){throw 'worker socket ownership mismatch'}
  [pscustomobject]@{ManifestJson=$manifest;ManifestSHA256=$Expected.ManifestSHA256;Socket=$sockets[0]}
}

function Invoke-UID00028DAllThrowScope3([scriptblock]$Open,[scriptblock]$Body,[scriptblock]$Retire) {
  $role=$null;$value=$null;$errors=[Collections.Generic.List[Exception]]::new()
  try{$role=&$Open;$value=&$Body $role}catch{$errors.Add($_.Exception)}finally{if($null-ne$role){try{&$Retire $role}catch{$errors.Add($_.Exception)}}}
  if($errors.Count-eq1){throw$errors[0]};if($errors.Count-gt1){throw[AggregateException]::new('UID00028D primary and cleanup failures',$errors.ToArray())}
  [pscustomobject]@{Value=$value;Role=$role}
}

function Invoke-UID00028DProvisionalOpen3([scriptblock]$CapturePreOpen,[scriptblock]$DispatchOpenRaw,[scriptblock]$ParseOpen,[scriptblock]$DiscoverDelta,[scriptblock]$RetireDelta) {
  $pre=&$CapturePreOpen;$receipt=$null;$errors=[Collections.Generic.List[Exception]]::new()
  try{$raw=&$DispatchOpenRaw;$receipt=&$ParseOpen $raw;return$receipt}catch{$errors.Add($_.Exception);try{$delta=&$DiscoverDelta $pre $receipt;if($null-ne$delta){&$RetireDelta $delta}}catch{$errors.Add($_.Exception)};if($errors.Count-eq1){throw$errors[0]};throw[AggregateException]::new('UID00028D open and cleanup failures',$errors.ToArray())}
}

function Acquire-UID00028DDurableSaveAuthority3([string]$Path,[string]$TransactionId,[string]$PlanSHA256,[scriptblock]$Clock) {
  $record=[ordered]@{schema=1;transaction_id=$TransactionId;plan_sha256=$PlanSHA256;attempt_utc=[string](&$Clock)}|ConvertTo-Json -Compress
  $bytes=[Text.UTF8Encoding]::new($false).GetBytes($record);$stream=$null
  try{$stream=[IO.FileStream]::new($Path,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None);$stream.Write($bytes,0,$bytes.Length);$stream.Flush($true)}catch{throw 'durable save authority already consumed or unavailable'}finally{if($null-ne$stream){$stream.Dispose()}}
  [pscustomobject]@{Path=$Path;Record=$record;SHA256=(Get-UID00028DTextSHA3 $record)}
}

function Invoke-UID00028DOwnedBackup3([scriptblock]$Create,[scriptblock]$Verify,[scriptblock]$DeleteOwned,[scriptblock]$AssertAbsent) {
  $owned=$null;$primary=$null;$cleanup=[Collections.Generic.List[Exception]]::new()
  try{$owned=&$Create;if($null-eq$owned-or$owned.Created-ne$true){throw 'backup create did not return ownership'};&$Verify $owned;return$owned}catch{$primary=$_.Exception;if($null-ne$owned-and$owned.Created-eq$true){try{&$DeleteOwned $owned}catch{$cleanup.Add($_.Exception)};try{&$AssertAbsent $owned}catch{$cleanup.Add($_.Exception)}};if($cleanup.Count-eq0){throw$primary};$all=[Collections.Generic.List[Exception]]::new();$all.Add($primary);foreach($e in$cleanup){$all.Add($e)};throw[AggregateException]::new('UID00028D backup primary and cleanup failures',$all.ToArray())}
}

function New-UID00028DDiskChain3($P0,$B0,[string]$TransactionId) {
  [pscustomobject]@{Schema=[int]1;TransactionId=$TransactionId;P0=$P0;B0=$B0;Dopen=$null;Attempt=$null;Dclosed=$null;P1=$null}
}

function Assert-UID00028DCompleteTuple3($Tuple,[string]$Label) {
  Assert-UID00028DExactMembers3 $Tuple @('Path','Size','SHA256','LastWriteTimeUtc','LastWriteTimeUtcTicks') $Label|Out-Null
  if($Tuple.Path-isnot[string]-or(($Tuple.Size-isnot[Int64])-and($Tuple.Size-isnot[int]))-or$Tuple.SHA256-isnot[string]-or$Tuple.SHA256-notmatch'^[0-9A-F]{64}$'-or$Tuple.LastWriteTimeUtc-isnot[string]-or(($Tuple.LastWriteTimeUtcTicks-isnot[Int64])-and($Tuple.LastWriteTimeUtcTicks-isnot[int]))){throw "$Label native tuple mismatch"}
}

function Assert-UID00028DRestoreAuthority3($Chain,$Current) {
  foreach($name in@('P0','B0','Dopen','Dclosed','P1','Attempt')){if($null-eq$Chain.$name){throw "restore chain missing $name"}}
  Assert-UID00028DCompleteTuple3 $Current 'restore current';Assert-UID00028DCompleteTuple3 $Chain.P1 'restore P1';Assert-UID00028DCompleteTuple3 $Chain.P0 'restore P0'
  if($Current.Path-cne$Chain.P1.Path-or$Current.Size-ne$Chain.P1.Size-or$Current.SHA256-cne$Chain.P1.SHA256-or$Current.LastWriteTimeUtcTicks-ne$Chain.P1.LastWriteTimeUtcTicks){throw 'restore refuses current third identity'}
  if($Current.SHA256-ceq$Chain.P0.SHA256){throw 'restore refuses P0 as destructive destination'}
  $true
}

function Invoke-UID00028DExactPlan3($Plan,$Role,$Providers,$ExpectedTranscript,[switch]$ExcludeSave) {
  $resolved=@(Resolve-UID00028DPlan3 $Plan ([string]$Role.Role) ([string]$Role.Database) ([string]$Role.Path));$out=[Collections.Generic.List[object]]::new()
  foreach($request in$resolved){if($ExcludeSave-and$request.Name-ceq'idb_save'){continue};$response=&$Providers.Request $Role $request
    if($null-ne$ExpectedTranscript){$expected=$ExpectedTranscript[$request.Ordinal-1];Assert-UID00028DExactTree3 $expected $response "response[$($request.Ordinal)]"}
    $out.Add($response)
  }
  $out.ToArray()
}

function Invoke-UID00028DProductionCoordinator3($Authority,$FullPlan,$TransactionPlan,$Providers) {
  Assert-UID00028DExactMembers3 $Providers @('FreezeAuthority','OpenRole','AttestRole','Request','RetireRole','ReadTuple','CreateBackup','AcquireSaveAuthority','Verify','Restore') 'production providers'|Out-Null
  $frozen=&$Providers.FreezeAuthority $Authority;$transactionId=[Guid]::NewGuid().ToString('N');$wpreScope=Invoke-UID00028DAllThrowScope3 {&$Providers.OpenRole 'Wpre' $frozen.CanonicalPath} {param($r)&$Providers.AttestRole $r $frozen|Out-Null;Invoke-UID00028DExactPlan3 $FullPlan $r $Providers $null} {param($r)&$Providers.RetireRole $r}
  $p0=&$Providers.ReadTuple 'P0' $frozen.CanonicalPath;$b0=&$Providers.CreateBackup $p0 $transactionId;$chain=New-UID00028DDiskChain3 $p0 $b0 $transactionId
  $oracleScope=Invoke-UID00028DAllThrowScope3 {&$Providers.OpenRole 'Woracle' $b0.Path} {param($r)&$Providers.AttestRole $r $frozen|Out-Null;Invoke-UID00028DExactPlan3 $TransactionPlan $r $Providers $null -ExcludeSave} {param($r)&$Providers.RetireRole $r};$oracle=@($oracleScope.Value)
  $saveClass='unsaved';$txScope=$null
  try{$txScope=Invoke-UID00028DAllThrowScope3 {&$Providers.OpenRole 'Wtx' $frozen.CanonicalPath} {param($r)&$Providers.AttestRole $r $frozen|Out-Null;$resolved=@(Resolve-UID00028DPlan3 $TransactionPlan ([string]$r.Role) ([string]$r.Database) ([string]$r.Path));for($i=0;$i-lt309;$i++){$actual=&$Providers.Request $r $resolved[$i];Assert-UID00028DExactTree3 $oracle[$i] $actual "transaction-response[$($i+1)]"};$chain.Dopen=&$Providers.ReadTuple 'Dopen' $frozen.CanonicalPath;$chain.Attempt=&$Providers.AcquireSaveAuthority $transactionId $TransactionPlan.SHA256;$save=&$Providers.Request $r $resolved[309];$saveClass=[string]$save.Class;[pscustomobject]@{Role=$r;Save=$save}} {param($r)&$Providers.RetireRole $r}}
  catch{$chain.Dclosed=&$Providers.ReadTuple 'Dclosed' $frozen.CanonicalPath;throw}
  $chain.Dclosed=&$Providers.ReadTuple 'Dclosed' $frozen.CanonicalPath;$chain.P1=$chain.Dclosed
  $isP0=$chain.P1.SHA256-ceq$chain.P0.SHA256-and$chain.P1.Size-eq$chain.P0.Size-and$chain.P1.LastWriteTimeUtcTicks-eq$chain.P0.LastWriteTimeUtcTicks
  if($saveClass-ceq'definite-success'){
    if($isP0){throw 'definite save success cannot classify as P0'};&$Providers.Verify 'post' $chain.P1 $frozen|Out-Null
    return[pscustomobject]@{Outcome='verified-post';Chain=$chain;WpreCount=@($wpreScope.Value).Count;OracleCount=$oracle.Count;TransactionCount=310;SaveAttempts=1}
  }
  if($saveClass-ceq'determinate-failure'-and$isP0){&$Providers.Verify 'pre' $chain.P0 $frozen|Out-Null;return[pscustomobject]@{Outcome='verified-p0';Chain=$chain;WpreCount=@($wpreScope.Value).Count;OracleCount=$oracle.Count;TransactionCount=310;SaveAttempts=1}}
  if($saveClass-cnotin@('determinate-failure','indeterminate','unsaved')){throw 'unknown save classification'}
  if($isP0){&$Providers.Verify 'pre' $chain.P0 $frozen|Out-Null;return[pscustomobject]@{Outcome='verified-p0';Chain=$chain;WpreCount=@($wpreScope.Value).Count;OracleCount=$oracle.Count;TransactionCount=310;SaveAttempts=1}}
  Assert-UID00028DRestoreAuthority3 $chain $chain.Dclosed|Out-Null;&$Providers.Restore $chain|Out-Null;&$Providers.Verify 'pre' $chain.P0 $frozen|Out-Null
  [pscustomobject]@{Outcome='restored-p0';Chain=$chain;WpreCount=@($wpreScope.Value).Count;OracleCount=$oracle.Count;TransactionCount=310;SaveAttempts=1}
}

function New-UID00028DFixtureProviders3([ValidateSet('definite-success','determinate-failure','indeterminate')][string]$SaveClass='definite-success') {
  $effects=[pscustomobject]@{Http=0;Process=0;Socket=0;File=0;Journal=0;Clock=0;Ida=0;Save=0;Restore=0;LogicalRequests=0;LogicalSave=0;Opens=0;Retires=0;Verifiers=0;Saved=$false;AuthorityUsed=$false}
  $p0=[pscustomobject]@{Path='C:\fixture\canonical.i64';Size=[Int64]100;SHA256=('A'*64);LastWriteTimeUtc='2026-08-06T00:00:00.0000000Z';LastWriteTimeUtcTicks=[Int64]1};$p1=[pscustomobject]@{Path=$p0.Path;Size=[Int64]101;SHA256=('B'*64);LastWriteTimeUtc='2026-08-06T00:00:01.0000000Z';LastWriteTimeUtcTicks=[Int64]2};$b0=[pscustomobject]@{Path='C:\fixture\backup.i64';Size=$p0.Size;SHA256=$p0.SHA256;LastWriteTimeUtc=$p0.LastWriteTimeUtc;LastWriteTimeUtcTicks=$p0.LastWriteTimeUtcTicks}
  $providers=[pscustomobject]@{
    FreezeAuthority={param($a)$a};OpenRole={param($role,$path)$effects.Opens++;[pscustomobject]@{Role=$role;Database="returned-$role";Path=$path}};AttestRole={param($role,$a)if($role.Database-cne"returned-$($role.Role)"){throw 'returned role binding mismatch'};$true};
    Request={param($role,$request)$effects.LogicalRequests++;if($request.Name-ceq'idb_save'){$effects.LogicalSave++;if($SaveClass-ceq'definite-success'){$effects.Saved=$true};return[pscustomobject]@{Class=$SaveClass;Ordinal=[int]$request.Ordinal;Name=[string]$request.Name;TemplateSHA256=[string]$request.TemplateSHA256}};[pscustomobject]@{Class='result';Ordinal=[int]$request.Ordinal;Name=[string]$request.Name;TemplateSHA256=[string]$request.TemplateSHA256}};
    RetireRole={param($role)$effects.Retires++};ReadTuple={param($stage,$path)if($effects.Saved){$p1}else{$p0}};CreateBackup={param($x,$id)$b0};AcquireSaveAuthority={param($id,$sha)if($effects.AuthorityUsed){throw 'fixture durable authority reused'};$effects.AuthorityUsed=$true;[pscustomobject]@{Id=$id;Plan=$sha}};Verify={param($state,$tuple,$a)$effects.Verifiers++;$true};Restore={param($chain)$effects.Restore++;$effects.Saved=$false;$true}
  }
  [pscustomobject]@{Providers=$providers;Effects=$effects;P0=$p0;P1=$p1;B0=$b0}
}

function Assert-UID00028DThrows3([scriptblock]$Body,[string]$Message,[string]$Label) {
  try{&$Body}catch{if($_.Exception.Message-cnotmatch[regex]::Escape($Message)){throw "$Label wrong exception: $($_.Exception.Message)"};return$Label};throw "$Label did not reject"
}

function Invoke-UID00028DHostileFixtures3([string]$FullCatalog,[string]$TransactionCatalog) {
  $passed=[Collections.Generic.List[string]]::new();function Pass([string]$x){if($passed.Contains($x)){throw "duplicate fixture label: $x"};$passed.Add($x)}
  $valid='{"jsonrpc":"2.0","id":7,"result":{"ok":true}}';$error='{"jsonrpc":"2.0","id":7,"error":{"code":-32000,"message":"x","data":null}}'
  if((ConvertFrom-UID00028DExactJsonRpc3 $valid 7).Kind-cne'result'){throw 'valid result'};Pass 'json-valid-result'
  if((ConvertFrom-UID00028DExactJsonRpc3 $error 7 -AllowError).Kind-cne'error'){throw 'valid error'};Pass 'json-valid-error'
  Pass(Assert-UID00028DThrows3 {ConvertFrom-UID00028DExactJsonRpc3 '{"jsonrpc":"2.0","id":7,"result":{"x":{"ok":true,"ok":false}}}' 7} 'duplicate member' 'json-nested-object-duplicate')
  Pass(Assert-UID00028DThrows3 {ConvertFrom-UID00028DExactJsonRpc3 '{"jsonrpc":"2.0","id":7,"result":[{"ok":true,"ok":false}]}' 7} 'duplicate member' 'json-nested-array-duplicate')
  Pass(Assert-UID00028DThrows3 {ConvertFrom-UID00028DExactJsonRpc3 '{"jsonrpc":"2.0","id":7,"result":{},"extra":1}' 7} 'member-set mismatch' 'json-root-extra')
  Pass(Assert-UID00028DThrows3 {ConvertFrom-UID00028DExactJsonRpc3 '{"jsonrpc":"2.0","id":"7","result":{}}' 7} 'native type' 'json-id-string')
  Pass(Assert-UID00028DThrows3 {ConvertFrom-UID00028DExactJsonRpc3 '{"jsonrpc":"2.0","id":8,"result":{}}' 7} 'id value' 'json-id-value')
  Pass(Assert-UID00028DThrows3 {ConvertFrom-UID00028DExactJsonRpc3 '{"jsonrpc":"1.0","id":7,"result":{}}' 7} 'version/type' 'json-version')
  Pass(Assert-UID00028DThrows3 {ConvertFrom-UID00028DExactJsonRpc3 '{"jsonrpc":"2.0","id":7,"result":{},"error":{"code":1,"message":"x","data":null}}' 7} 'exactly one' 'json-result-error')
  Pass(Assert-UID00028DThrows3 {ConvertFrom-UID00028DExactJsonRpc3 '{"jsonrpc":"2.0","id":7,"error":{"code":1,"message":"x","data":null,"extra":1}}' 7 -AllowError} 'member-set mismatch' 'json-error-extra')
  Pass(Assert-UID00028DThrows3 {ConvertFrom-UID00028DExactJsonRpc3 $error 7} 'not allowed' 'json-error-policy')
  Assert-UID00028DStrictRawJson3 '[{"a":1},true,false,null,"x",-1.5e2]';Pass 'json-complete-grammar'
  $expected=[pscustomobject]@{ok=$true;count=[Int64]1;items=@([pscustomobject]@{name='x'})};$actual=[pscustomobject]@{ok=$true;count=[Int64]1;items=@([pscustomobject]@{name='x'})};Assert-UID00028DExactTree3 $expected $actual;Pass 'exact-tree-valid'
  Pass(Assert-UID00028DThrows3 {Assert-UID00028DExactTree3 $expected ([pscustomobject]@{ok=1;count=[Int64]1;items=@([pscustomobject]@{name='x'})})} 'native type' 'exact-tree-bool-coercion')
  Pass(Assert-UID00028DThrows3 {Assert-UID00028DExactTree3 $expected ([pscustomobject]@{ok=$true;count=[Int64]1;items=@([pscustomobject]@{name='x';extra=1})})} 'member-set' 'exact-tree-extra')
  $tools=@($UID00028DUsedToolNames|ForEach-Object{[ordered]@{name=$_;description='d';inputSchema=[ordered]@{type='object';properties=[ordered]@{};required=@();additionalProperties=$false}}});$toolsRaw=([ordered]@{jsonrpc='2.0';id=[Int64]9;result=[ordered]@{tools=$tools}}|ConvertTo-Json -Depth 20 -Compress);$schema=Assert-UID00028DToolSchemaAuthority3 $toolsRaw 9 (Get-UID00028DTextSHA3 $toolsRaw);if($schema.UsedNames.Count-ne21){throw 'used schema count'};Pass 'schema-all-21-tools'
  Pass(Assert-UID00028DThrows3 {Assert-UID00028DToolSchemaAuthority3 $toolsRaw 9 ('0'*64)} 'schema identity' 'schema-raw-hash-drift')
  $aliasRaw=$toolsRaw.Replace('runtime_attestation','runtime/attest');Pass(Assert-UID00028DThrows3 {Assert-UID00028DToolSchemaAuthority3 $aliasRaw 9 (Get-UID00028DTextSHA3 $aliasRaw)} 'runtime_attestation' 'schema-private-runtime-alias')
  $full=New-UID00028DImmutablePlan3 $FullCatalog 124 $UID00028DFullCatalogSHA256;$tx=New-UID00028DImmutablePlan3 $TransactionCatalog 310 $UID00028DTransactionCatalogSHA256;if($full.Count-ne124-or$tx.Count-ne310){throw 'plan counts'};Pass 'plan-counts-124-310'
  if((Get-UID00028DImmutablePlanView3 $full).Count-ne124){throw 'full plan view'};Pass 'plan-full-immutable-view'
  if((Get-UID00028DImmutablePlanView3 $tx).Count-ne310){throw 'tx plan view'};Pass 'plan-transaction-immutable-view'
  $resolvedA=@(Resolve-UID00028DPlan3 $tx 'Woracle' 'returned-oracle' 'C:\fixture\backup.i64');$resolvedB=@(Resolve-UID00028DPlan3 $tx 'Wtx' 'returned-tx' 'C:\fixture\canonical.i64')
  if($resolvedA[0].TemplateSHA256-cne$resolvedB[0].TemplateSHA256){throw 'template identity differs by role'};Pass 'plan-template-role-independent'
  if($resolvedA[0].ResolvedSHA256-ceq$resolvedB[0].ResolvedSHA256){throw 'resolved identity not role-bound'};Pass 'plan-resolved-role-specific'
  if($resolvedA[0].RoleBindingSHA256-ceq$resolvedB[0].RoleBindingSHA256){throw 'role binding not distinct'};Pass 'plan-role-binding-specific'
  $fullResolved=@(Resolve-UID00028DPlan3 $full 'Wpre' 'returned-pre' 'C:\fixture\canonical.i64');if($fullResolved[0].Name-cne'idb_list'-or$fullResolved[0].Arguments.PSObject.Properties.Count-ne0){throw 'empty idb_list arguments'};Pass 'plan-empty-arguments'
  if(@($resolvedA|Where-Object{$_.Name-cne'idb_list'-and$_.Arguments.database-cne'returned-oracle'}).Count-ne0){throw 'oracle returned session substitution'};Pass 'plan-oracle-returned-session'
  if(@($resolvedB|Where-Object{$_.Name-cne'idb_list'-and$_.Arguments.database-cne'returned-tx'}).Count-ne0){throw 'tx returned session substitution'};Pass 'plan-tx-returned-session'
  Pass(Assert-UID00028DThrows3 {New-UID00028DImmutablePlan3 ($TransactionCatalog+' ') 310 $UID00028DTransactionCatalogSHA256} 'raw identity' 'plan-raw-drift')
  $tampered=$tx.PSObject.Copy();$tampered.SHA256='0'*64;Pass(Assert-UID00028DThrows3 {Get-UID00028DImmutablePlanView3 $tampered} 'envelope drift' 'plan-envelope-drift')
  $boundary=[pscustomobject]@{TargetStart='0x006707d4';TargetEnd='0x00671a74';TargetSize=[Int64]4768;TargetSHA256='80FF9CBA042305575D19F6378459A619877E1879D3E69692F3BC8DDBE71CAEDA';PredecessorName='s_snowPatterns';PredecessorType='unsigned __int8[2][16]';PredecessorEnd='0x006707d4';SuccessorName='a114';SuccessorStart='0x00671a74';SuccessorText='1.1.4'};Assert-UID00028DSourceBoundary3 $boundary|Out-Null;Pass 'source-boundary-exact'
  $badBoundary=$boundary.PSObject.Copy();$badBoundary.SuccessorText='1.2.0';Pass(Assert-UID00028DThrows3 {Assert-UID00028DSourceBoundary3 $badBoundary} 'semantic mismatch' 'source-boundary-drift')
  $retired=0;$opened=0;Pass(Assert-UID00028DThrows3 {Invoke-UID00028DProvisionalOpen3 {$opened} {$opened++;'bad'} {throw 'parse failed'} {param($pre,$receipt)[pscustomobject]@{Pid=1}} {param($delta)$script:retired++}} 'parse failed' 'provisional-open-parse-failure');if($retired-ne1){throw 'provisional delta not retired'};Pass 'provisional-open-delta-retired'
  Pass(Assert-UID00028DThrows3 {Invoke-UID00028DProvisionalOpen3 {0} {throw 'open failed'} {param($x)} {param($pre,$receipt)[pscustomobject]@{Pid=1}} {param($d)throw 'retire failed'}} 'open and cleanup' 'provisional-open-dual-error')
  Pass(Assert-UID00028DThrows3 {Invoke-UID00028DAllThrowScope3 {[pscustomobject]@{Role='x'}} {param($r)throw 'body failed'} {param($r)throw 'retire failed'}} 'primary and cleanup' 'scope-primary-cleanup-errors')
  $once=Invoke-UID00028DAllThrowScope3 {[pscustomobject]@{Role='x'}} {param($r)'ok'} {param($r)$script:retired++};if($once.Value-cne'ok'){throw 'scope value'};Pass 'scope-success'
  $ownedDeletes=0;Pass(Assert-UID00028DThrows3 {Invoke-UID00028DOwnedBackup3 {throw 'collision'} {param($x)} {param($x)$script:ownedDeletes++} {param($x)}} 'collision' 'backup-collision-reject');if($ownedDeletes-ne0){throw 'collision deleted unrelated path'};Pass 'backup-collision-no-delete'
  Pass(Assert-UID00028DThrows3 {Invoke-UID00028DOwnedBackup3 {[pscustomobject]@{Created=$true;Path='x'}} {param($x)throw 'verify failed'} {param($x)$script:ownedDeletes++} {param($x)}} 'verify failed' 'backup-owned-partial-cleanup');if($ownedDeletes-ne1){throw 'owned partial not deleted'};Pass 'backup-owned-delete-once'
  Pass(Assert-UID00028DThrows3 {Invoke-UID00028DOwnedBackup3 {[pscustomobject]@{Created=$true;Path='x'}} {param($x)throw 'verify failed'} {param($x)throw 'delete failed'} {param($x)throw 'still present'}} 'primary and cleanup' 'backup-cleanup-errors-preserved')
  $fx=New-UID00028DFixtureProviders3 definite-success;$chain=New-UID00028DDiskChain3 $fx.P0 $fx.B0 't';$chain.Dopen=$fx.P0;$chain.Attempt=[pscustomobject]@{Id='a'};$chain.Dclosed=$fx.P1;$chain.P1=$fx.P1;Assert-UID00028DRestoreAuthority3 $chain $fx.P1|Out-Null;Pass 'restore-attributable-p1'
  $third=$fx.P1.PSObject.Copy();$third.SHA256='C'*64;Pass(Assert-UID00028DThrows3 {Assert-UID00028DRestoreAuthority3 $chain $third} 'third identity' 'restore-third-identity')
  Pass(Assert-UID00028DThrows3 {Assert-UID00028DRestoreAuthority3 $chain $fx.P0} 'third identity' 'restore-p0-refusal')
  $missing=New-UID00028DDiskChain3 $fx.P0 $fx.B0 't';Pass(Assert-UID00028DThrows3 {Assert-UID00028DRestoreAuthority3 $missing $fx.P1} 'missing Dopen' 'restore-incomplete-chain')
  $saveUsed=$false;$acquire={if($saveUsed){throw 'authority reused'};$script:saveUsed=$true}; &$acquire;Pass 'save-authority-first';Pass(Assert-UID00028DThrows3 {&$acquire} 'reused' 'save-authority-second-rejected')
  $manifestRows=@([pscustomobject]@{name='m';file='m.py';spec_origin='C:\root\m.py';resolved_path='C:\root\m.py';size=[Int64]1;sha256=('D'*64)});$manifestJson=@([ordered]@{name='m';file='m.py';spec_origin='C:\root\m.py';resolved_path='C:\root\m.py';size=[Int64]1;sha256=('D'*64)})|ConvertTo-Json -Compress;$runtime=[pscustomobject]@{endpoint=[pscustomobject]@{host='127.0.0.1';port=2000};process=[pscustomobject]@{pid=10};modules=$manifestRows};$shape=$runtime|ConvertTo-Json -Depth 10|ConvertFrom-Json;$manifestExpected=[pscustomobject]@{Shape=$shape;ManifestSHA256=(Get-UID00028DTextSHA3 $manifestJson)}
  Assert-UID00028DLoadedRuntime3 $runtime $manifestExpected {param($p)[pscustomobject]@{Path=$p;Size=[Int64]1;SHA256=('D'*64)}} {param($h,$p),[pscustomobject]@{OwningProcess=10}}|Out-Null;Pass 'runtime-loaded-file-and-socket'
  Pass(Assert-UID00028DThrows3 {Assert-UID00028DLoadedRuntime3 $runtime $manifestExpected {param($p)[pscustomobject]@{Path=$p;Size=[Int64]2;SHA256=('D'*64)}} {param($h,$p),[pscustomobject]@{OwningProcess=10}}} 'file proof' 'runtime-fabricated-module')
  Pass(Assert-UID00028DThrows3 {Assert-UID00028DLoadedRuntime3 $runtime $manifestExpected {param($p)[pscustomobject]@{Path=$p;Size=[Int64]1;SHA256=('D'*64)}} {param($h,$p),[pscustomobject]@{OwningProcess=11}}} 'socket ownership' 'runtime-worker-socket-owner')
  $authority=[pscustomobject]@{CanonicalPath='C:\fixture\canonical.i64';SchemaSHA256='S';ManifestSHA256='M';PlanSHA256=$tx.SHA256}
  $prod=New-UID00028DFixtureProviders3 definite-success;$result=Invoke-UID00028DProductionCoordinator3 $authority $full $tx $prod.Providers;if($result.Outcome-cne'verified-post'){throw 'production success outcome'};Pass 'production-coordinator-success'
  if($result.WpreCount-ne124){throw 'production Wpre count'};Pass 'production-wpre-124'
  if($result.OracleCount-ne309){throw 'production oracle count'};Pass 'production-oracle-309'
  if($result.TransactionCount-ne310){throw 'production transaction count'};Pass 'production-transaction-310'
  if($result.SaveAttempts-ne1-or$prod.Effects.LogicalSave-ne1){throw 'production single save'};Pass 'production-single-save'
  if($prod.Effects.Opens-ne3){throw 'production role opens'};Pass 'production-role-open-count'
  if($prod.Effects.Retires-ne3){throw 'production role retirement'};Pass 'production-role-retirement-count'
  if($prod.Effects.LogicalRequests-ne743){throw "production logical request count: $($prod.Effects.LogicalRequests)"};Pass 'production-logical-request-count'
  if($prod.Effects.Verifiers-ne1){throw 'production verifier count'};Pass 'production-fresh-verifier'
  if($prod.Effects.Restore-ne0){throw 'production success restored'};Pass 'production-success-no-restore'
  $failure=New-UID00028DFixtureProviders3 determinate-failure;$failureResult=Invoke-UID00028DProductionCoordinator3 $authority $full $tx $failure.Providers;if($failureResult.Outcome-cne'verified-p0'){throw 'determinate P0 outcome'};Pass 'production-determinate-p0'
  if($failure.Effects.LogicalSave-ne1){throw 'determinate save count'};Pass 'production-determinate-no-retry'
  $indeterminate=New-UID00028DFixtureProviders3 indeterminate;$indeterminateResult=Invoke-UID00028DProductionCoordinator3 $authority $full $tx $indeterminate.Providers;if($indeterminateResult.Outcome-cne'verified-p0'){throw 'indeterminate P0 outcome'};Pass 'production-indeterminate-p0'
  if($indeterminate.Effects.LogicalSave-ne1){throw 'indeterminate save count'};Pass 'production-indeterminate-no-retry'
  foreach($e in@($prod.Effects,$failure.Effects,$indeterminate.Effects)){if($e.Http-ne0-or$e.Process-ne0-or$e.Socket-ne0-or$e.File-ne0-or$e.Journal-ne0-or$e.Clock-ne0-or$e.Ida-ne0-or$e.Save-ne0){throw 'fixture external effect counter is nonzero'}};Pass 'production-zero-external-effects'
  if($passed.Count-ne$UID00028DHostileFixtureCount){throw "hostile fixture count mismatch: $($passed.Count) != $UID00028DHostileFixtureCount"};$passed.ToArray()
}

function New-UID00028DGate1Environment3 {
  $full=New-UID00028DImmutablePlan3 (New-UID00028DFullCatalogJsonLines) 124 $UID00028DFullCatalogSHA256;$tx=New-UID00028DImmutablePlan3 $UID00028DTransactionCatalogJsonLines 310 $UID00028DTransactionCatalogSHA256;$fixtures=@(Invoke-UID00028DHostileFixtures3 (New-UID00028DFullCatalogJsonLines) $UID00028DTransactionCatalogJsonLines)
  if($fixtures.Count-ne64){throw 'closure-3 fixture gate failed'}
  [pscustomobject]@{ClosureVersion=$UID00028DFinalClosureVersion;FullPlan=$full;TransactionPlan=$tx;HostileFixtures=$fixtures;ProductionCoordinator='Invoke-UID00028DProductionCoordinator3';ExactUsedToolCount=21;FullCatalogCount=124;OracleCount=309;TransactionCount=310}
}
~~~
## Removed Block R007 - Residual Transaction Wording

The following source-report lines were removed during the final cleanup because they described accepted state in transaction-oriented terms. They are non-authoritative, must never be executed, and receive no Gate, coverage, score, IDA, validator, or lifecycle credit.

~~~text
- No evidence supports leaving raw `sub_` names on exact stock IJG functions after a controlled supervisor transaction.

All other rendered source-function labels in the seven inbound-xref sets are protected byte-for-byte because their containing functions are not renamed by this transaction.

| `0x401070` | `var_C8 +0x0 size1 _BYTE`; `__return_address +0xc8 size4`; `arg_0 +0xcc size4 _DWORD` | rename/type arg to `cinfo: j_common_ptr`; return `void` | physical 0xc8-byte local allocation, return row, offsets and widths unchanged; no local mutation in this transaction because current API readback does not deterministically expose the full array type |
~~~
