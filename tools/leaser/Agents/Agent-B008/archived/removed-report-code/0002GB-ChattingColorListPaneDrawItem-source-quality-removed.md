<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B008\0002GB-ChattingColorListPaneDrawItem-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

> NON-AUTHORITATIVE ARCHIVE. This companion must never be executed and receives no report, evidence, Gate, coverage, score, IDA, validator, or lifecycle credit.

- Source report: [0002GB-ChattingColorListPaneDrawItem-source-quality.md](0002GB-ChattingColorListPaneDrawItem-source-quality.md)
- Source report SHA256 before archive-link insertion: `C612B7856C39851D4169D60C5E9C3A60B66D0E8FDB6441D5E8FABCAEBEDFA5FD`
- Recovery generated: `2026-08-09T22:17:53Z`
- Unique recovered executable blocks: `16`
- Recovered executable bytes: `98804`
- Recovery basis: report-path-associated Codex session history. The source report had already removed its executable packages before the supervisor could extract them directly.
- Scope: this archive preserves every unique recoverable report-local executable block, including superseded historical variants where session history retained more than the final pre-removal report.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- SHA256: `B2CEFE83823A3AD6224EEE2FC6E2C0C133DB9E47F780F91B711B046B4954CFB8`
- Language: `powershell`
- Bytes: `5748`
- First recovered timestamp: `2026-08-06T22:26:11.377Z`
- Session provenance: rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193738 (2026-08-06T22:26:11.377Z); rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193739 (2026-08-06T22:26:11.426Z)

~~~powershell
$uid0002gbHost = '127.0.0.1'
$uid0002gbPort = 13337
$uid0002gbVenv = 'C:\Users\admin\.idapro\idalib-mcp-venv'
$uid0002gbPython = Join-Path $uid0002gbVenv 'Scripts\python.exe'
$uid0002gbConsole = Join-Path $uid0002gbVenv 'Scripts\idalib-mcp.exe'
$uid0002gbRootExpected = Join-Path $uid0002gbVenv 'Lib\site-packages\ida_pro_mcp'
$uid0002gbExpectedImplementation = [ordered]@{
    'idalib_supervisor.py'='2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A'
    'idalib_server.py'='06C922EEF3F2E6771308C687231FE443A65DADF340E72001C6B05B7FC70B2034'
    'idalib_session_manager.py'='9EDEEBD47B6FF85F9809E7159CE03D3EF41833692D28AC4367C6C4E5CAE00890'
    'worker_lifecycle.py'='303A2A15BB316CD2200B2C54EF8685EBBC50EF5114FDD1FBC6C16CD01B6BAC63'
    'ida_mcp\api_types.py'='A3E7444BBAC0066B48EDF38E26F34E6ABEC823585CD50E43C6DA98C55B965ECF'
    'ida_mcp\api_modify.py'='161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8'
    'ida_mcp\api_stack.py'='9E4B5898E875812E4C993597D44F0F6438430F92A8B2299DC5C62630D49AE1BB'
    'ida_mcp\api_core.py'='90C59B3F64F26E170CC604000CE39B34B648352767059DD1C2DF1914E9CBD4A3'
    'ida_mcp\api_analysis.py'='4C9B9122A7D2697CD464C1F473A227A580FD803515A1C885A1AA262259F1969F'
    'ida_mcp\api_memory.py'='A2D4E48921E2E7A8D3C4BD621658F645A9C17C7FB34E963E62AE864E452ABC93'
    'ida_mcp\framework.py'='518100959115851FAAD98A48D4E0D918B4439C1C6666671C9DA93AA7312414B4'
}
function Get-Uid0002GBRuntimeBinding {
    $listeners = @(Get-NetTCPConnection -State Listen -ErrorAction Stop |
        Where-Object { $_.LocalAddress -eq $uid0002gbHost -and $_.LocalPort -eq $uid0002gbPort })
    if ($listeners.Count -ne 1) { throw "RUNTIME_BIND_LISTENER_COUNT:$($listeners.Count)" }
    $listenerPid = [int]$listeners[0].OwningProcess
    $listener = Get-CimInstance Win32_Process -Filter "ProcessId=$listenerPid" -ErrorAction Stop
    $listenerProcess = Get-Process -Id $listenerPid -ErrorAction Stop
    $listenerTuple = [pscustomobject][ordered]@{
        PID = $listenerPid
        CreationTimeUtcTicks = [long]$listenerProcess.StartTime.ToUniversalTime().Ticks
        ParentProcessId = [int]$listener.ParentProcessId
        ExecutablePath = [string]$listener.ExecutablePath
        CommandLine = [string]$listener.CommandLine
        Endpoint = "http://$uid0002gbHost`:$uid0002gbPort/mcp"
    }
    if ($listenerTuple.CommandLine -notmatch [regex]::Escape($uid0002gbConsole) -or
        $listenerTuple.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1(?:\s|$)' -or
        $listenerTuple.CommandLine -notmatch '(?i)--port\s+13337(?:\s|$)') {
        throw 'RUNTIME_BIND_LISTENER_COMMAND'
    }
    if ((Get-FileHash -Algorithm SHA256 -LiteralPath $uid0002gbConsole).Hash -cne
        '38888EDC3241C00092D5A4F166F70E6AF8DF538D4C81C8DE75E461575E27580E') {
        throw 'RUNTIME_BIND_CONSOLE_HASH'
    }
    $moduleJson = & $uid0002gbPython -I -c "import importlib.util,json,pathlib; s=importlib.util.find_spec('ida_pro_mcp.idalib_supervisor'); p=pathlib.Path(s.origin).resolve(); print(json.dumps({'module':str(p),'root':str(p.parent)}))"
    if ($LASTEXITCODE -ne 0) { throw 'RUNTIME_BIND_IMPORT_SPEC' }
    $moduleIdentity = $moduleJson | ConvertFrom-Json
    $packageRoot = (Resolve-Path -LiteralPath $moduleIdentity.root).Path
    $supervisorModule = (Resolve-Path -LiteralPath $moduleIdentity.module).Path
    if ($packageRoot -cne (Resolve-Path -LiteralPath $uid0002gbRootExpected).Path -or
        $supervisorModule -cne (Join-Path $packageRoot 'idalib_supervisor.py')) {
        throw 'RUNTIME_BIND_PACKAGE_ROOT'
    }
    $dist = @(Get-ChildItem -LiteralPath (Split-Path $packageRoot -Parent) -Directory -Filter 'ida_pro_mcp-*.dist-info' |
        Where-Object { Test-Path -LiteralPath (Join-Path $_.FullName 'entry_points.txt') })
    if ($dist.Count -ne 1) { throw "RUNTIME_BIND_DISTRIBUTION_COUNT:$($dist.Count)" }
    $entryPoints = Join-Path $dist[0].FullName 'entry_points.txt'
    if ((Get-FileHash -Algorithm SHA256 -LiteralPath $entryPoints).Hash -cne
        'DA9A1E575662C419A1180D63884494D38EF22A1A5E8619CE368DA6CD9CD9E2CF' -or
        (Get-Content -Raw -LiteralPath $entryPoints) -notmatch
        '(?m)^idalib-mcp\s*=\s*ida_pro_mcp\.idalib_supervisor:main\s*$') {
        throw 'RUNTIME_BIND_ENTRY_POINT'
    }
    $implementation = @()
    foreach ($relativePath in $uid0002gbExpectedImplementation.Keys) {
        $path = (Resolve-Path -LiteralPath (Join-Path $packageRoot $relativePath)).Path
        $sha = (Get-FileHash -Algorithm SHA256 -LiteralPath $path).Hash
        if ($sha -cne $uid0002gbExpectedImplementation[$relativePath]) {
            throw "RUNTIME_BIND_IMPLEMENTATION_HASH:$relativePath:$sha"
        }
        $implementation += [pscustomobject][ordered]@{ RelativePath=$relativePath; Path=$path; SHA256=$sha }
    }
    [pscustomobject][ordered]@{
        Listener = $listenerTuple
        ConsoleEntryPath = (Resolve-Path -LiteralPath $uid0002gbConsole).Path
        ConsoleEntrySHA256 = '38888EDC3241C00092D5A4F166F70E6AF8DF538D4C81C8DE75E461575E27580E'
        EntryPointsPath = (Resolve-Path -LiteralPath $entryPoints).Path
        EntryPointsSHA256 = 'DA9A1E575662C419A1180D63884494D38EF22A1A5E8619CE368DA6CD9CD9E2CF'
        PackageRoot = $packageRoot
        SupervisorModule = $supervisorModule
        Implementation = $implementation
    }
}
function Assert-Uid0002GBRuntimeBinding($Expected,[string]$Boundary) {
    $actual = Get-Uid0002GBRuntimeBinding
    $expectedJson = $Expected | ConvertTo-Json -Depth 12 -Compress
    $actualJson = $actual | ConvertTo-Json -Depth 12 -Compress
    if ($actualJson -cne $expectedJson) { throw "RUNTIME_BIND_DRIFT:$Boundary" }
    $actual
}
$Uid0002GBRuntimeBinding0 = Get-Uid0002GBRuntimeBinding
~~~

## Removed Block R002

- SHA256: `39D1EE8E157763885263999B9F8A640A38C6AB3A0B192BC0E318647734AAE9F6`
- Language: `powershell`
- Bytes: `4988`
- First recovered timestamp: `2026-08-06T22:48:01.803Z`
- Session provenance: rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193840 (2026-08-06T22:48:01.803Z)

~~~powershell
function Write-Uid0002GBExclusiveUtf8([string]$Path,[string]$Text) {
    $fs = [IO.File]::Open($Path,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None)
    try {
        $bytes = [Text.UTF8Encoding]::new($false).GetBytes($Text)
        $fs.Write($bytes,0,$bytes.Length)
        $fs.Flush($true)
    } finally { $fs.Dispose() }
}
function Invoke-Uid0002GBLoadedModuleAttestation($ProcessTuple,[string]$Role,[string[]]$RequiredModules) {
    $nonce = [Guid]::NewGuid().ToString('N')
    $requestPath = Join-Path $env:TEMP "uid0002gb-$($ProcessTuple.PID)-$nonce.request.json"
    $outputPath = Join-Path $env:TEMP "uid0002gb-$($ProcessTuple.PID)-$nonce.response.json"
    $scriptPath = Join-Path $env:TEMP "uid0002gb-$($ProcessTuple.PID)-$nonce.attest.py"
    foreach ($path in @($requestPath,$outputPath,$scriptPath)) { if (Test-Path -LiteralPath $path) { throw 'ATTEST_PATH_COLLISION' } }
    $request = [ordered]@{ pid=[int]$ProcessTuple.PID; role=$Role; nonce=$nonce; output_path=$outputPath; required_modules=$RequiredModules }
    Write-Uid0002GBExclusiveUtf8 $requestPath ($request | ConvertTo-Json -Depth 8 -Compress)
    $pythonSource = @'
import sys, os, json, hashlib

_REQUEST_PATH = __UID0002GB_REQUEST_PATH__

def _uid0002gb_attest():
    with open(_REQUEST_PATH, "r", encoding="utf-8") as stream:
        request = json.load(stream)
    if int(request["pid"]) != os.getpid():
        raise RuntimeError("ATTEST_PID")
    rows = []
    for name in request["required_modules"]:
        module = sys.modules.get(name)
        if module is None:
            raise RuntimeError("ATTEST_MODULE_MISSING:" + name)
        file_path = os.path.realpath(getattr(module, "__file__", ""))
        spec = getattr(module, "__spec__", None)
        origin = os.path.realpath(getattr(spec, "origin", "") or "")
        if not file_path or file_path != origin or not os.path.isfile(file_path):
            raise RuntimeError("ATTEST_ORIGIN:" + name)
        with open(file_path, "rb") as source:
            digest = hashlib.sha256(source.read()).hexdigest().upper()
        loader = getattr(module, "__loader__", None)
        loader_type = type(loader).__module__ + "." + type(loader).__qualname__
        rows.append({"name":name,"file":file_path,"origin":origin,"loader":loader_type,"sha256":digest})
    response = {"pid":os.getpid(),"role":request["role"],"nonce":request["nonce"],"executable":sys.executable,
                "version":sys.version,"modules":rows}
    flags = os.O_WRONLY | os.O_CREAT | os.O_EXCL
    fd = os.open(request["output_path"], flags, 0o600)
    with os.fdopen(fd, "w", encoding="utf-8", newline="\n") as stream:
        json.dump(response, stream, sort_keys=True, separators=(",", ":"))
        stream.write("\n")
        stream.flush()
        os.fsync(stream.fileno())

_uid0002gb_attest()
del _uid0002gb_attest
'@
    $requestLiteral = $requestPath | ConvertTo-Json -Compress
    $pythonSource = $pythonSource.Replace('__UID0002GB_REQUEST_PATH__',$requestLiteral)
    Write-Uid0002GBExclusiveUtf8 $scriptPath $pythonSource
    $scriptSha = (Get-FileHash -Algorithm SHA256 -LiteralPath $scriptPath).Hash
    $scriptLiteral = $scriptPath | ConvertTo-Json -Compress
    & $uid0002gbPython -I -c "import sys; sys.remote_exec($($ProcessTuple.PID), $scriptLiteral)"
    if ($LASTEXITCODE -ne 0) { throw 'ATTEST_REMOTE_EXEC' }
    $deadline = [DateTime]::UtcNow.AddSeconds(15)
    while (-not (Test-Path -LiteralPath $outputPath -PathType Leaf)) {
        if ([DateTime]::UtcNow -ge $deadline) { throw 'ATTEST_TIMEOUT' }
        Start-Sleep -Milliseconds 100
    }
    $raw = [IO.File]::ReadAllText($outputPath,[Text.Encoding]::UTF8)
    try { $attestation = $raw | ConvertFrom-Json -ErrorAction Stop } catch { throw 'ATTEST_JSON_PARSE' }
    if ([int]$attestation.pid -ne [int]$ProcessTuple.PID -or $attestation.role -cne $Role -or
        $attestation.nonce -cne $nonce -or @($attestation.modules).Count -ne $RequiredModules.Count) {
        throw 'ATTEST_IDENTITY_OR_COUNT'
    }
    for ($i=0;$i -lt $RequiredModules.Count;$i++) {
        $name = $RequiredModules[$i]
        $row = $attestation.modules[$i]
        if ($row.name -cne $name -or $row.file -cne $row.origin) { throw "ATTEST_ROW:$name" }
        $expected = $uid0002gbExpectedImplementation[$name]
        if (-not $expected) { throw "ATTEST_NO_EXPECTED_MODULE:$name" }
        $parts = $expected.Split('|',2)
        $expectedPath = (Resolve-Path -LiteralPath (Join-Path $uid0002gbRootExpected $parts[0])).Path
        if ((Resolve-Path -LiteralPath $row.file).Path -cne $expectedPath -or $row.sha256 -cne $parts[1]) {
            throw "ATTEST_PATH_OR_HASH:$name"
        }
    }
    [pscustomobject][ordered]@{ Process=$ProcessTuple; Role=$Role; Nonce=$nonce; ScriptSHA256=$scriptSha;
        RequestPath=$requestPath; OutputPath=$outputPath; OutputSHA256=(Get-FileHash -Algorithm SHA256 -LiteralPath $outputPath).Hash;
        Attestation=$attestation }
}
~~~

## Removed Block R003

- SHA256: `8038B331F94DC192CB5CED490040A7B50BA49AFCAC21CCF004C852EBCD7A7F6C`
- Language: `powershell`
- Bytes: `5750`
- First recovered timestamp: `2026-08-06T22:48:01.803Z`
- Session provenance: rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193840 (2026-08-06T22:48:01.803Z)

~~~powershell
$uid0002gbHost = '127.0.0.1'
$uid0002gbPort = 13337
$uid0002gbVenv = 'C:\Users\admin\.idapro\idalib-mcp-venv'
$uid0002gbPython = Join-Path $uid0002gbVenv 'Scripts\python.exe'
$uid0002gbConsole = Join-Path $uid0002gbVenv 'Scripts\idalib-mcp.exe'
$uid0002gbRootExpected = Join-Path $uid0002gbVenv 'Lib\site-packages\ida_pro_mcp'
$uid0002gbExpectedImplementation = [ordered]@{
    'idalib_supervisor.py'='2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A'
    'idalib_server.py'='06C922EEF3F2E6771308C687231FE443A65DADF340E72001C6B05B7FC70B2034'
    'idalib_session_manager.py'='9EDEEBD47B6FF85F9809E7159CE03D3EF41833692D28AC4367C6C4E5CAE00890'
    'worker_lifecycle.py'='303A2A15BB316CD2200B2C54EF8685EBBC50EF5114FDD1FBC6C16CD01B6BAC63'
    'ida_mcp\api_types.py'='A3E7444BBAC0066B48EDF38E26F34E6ABEC823585CD50E43C6DA98C55B965ECF'
    'ida_mcp\api_modify.py'='161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8'
    'ida_mcp\api_stack.py'='9E4B5898E875812E4C993597D44F0F6438430F92A8B2299DC5C62630D49AE1BB'
    'ida_mcp\api_core.py'='90C59B3F64F26E170CC604000CE39B34B648352767059DD1C2DF1914E9CBD4A3'
    'ida_mcp\api_analysis.py'='4C9B9122A7D2697CD464C1F473A227A580FD803515A1C885A1AA262259F1969F'
    'ida_mcp\api_memory.py'='A2D4E48921E2E7A8D3C4BD621658F645A9C17C7FB34E963E62AE864E452ABC93'
    'ida_mcp\framework.py'='518100959115851FAAD98A48D4E0D918B4439C1C6666671C9DA93AA7312414B4'
}
function Get-Uid0002GBRuntimeBinding {
    $listeners = @(Get-NetTCPConnection -State Listen -ErrorAction Stop |
        Where-Object { $_.LocalAddress -eq $uid0002gbHost -and $_.LocalPort -eq $uid0002gbPort })
    if ($listeners.Count -ne 1) { throw "RUNTIME_BIND_LISTENER_COUNT:$($listeners.Count)" }
    $listenerPid = [int]$listeners[0].OwningProcess
    $listener = Get-CimInstance Win32_Process -Filter "ProcessId=$listenerPid" -ErrorAction Stop
    $listenerProcess = Get-Process -Id $listenerPid -ErrorAction Stop
    $listenerTuple = [pscustomobject][ordered]@{
        PID = $listenerPid
        CreationTimeUtcTicks = [long]$listenerProcess.StartTime.ToUniversalTime().Ticks
        ParentProcessId = [int]$listener.ParentProcessId
        ExecutablePath = [string]$listener.ExecutablePath
        CommandLine = [string]$listener.CommandLine
        Endpoint = "http://$uid0002gbHost`:$uid0002gbPort/mcp"
    }
    if ($listenerTuple.CommandLine -notmatch [regex]::Escape($uid0002gbConsole) -or
        $listenerTuple.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1(?:\s|$)' -or
        $listenerTuple.CommandLine -notmatch '(?i)--port\s+13337(?:\s|$)') {
        throw 'RUNTIME_BIND_LISTENER_COMMAND'
    }
    if ((Get-FileHash -Algorithm SHA256 -LiteralPath $uid0002gbConsole).Hash -cne
        '38888EDC3241C00092D5A4F166F70E6AF8DF538D4C81C8DE75E461575E27580E') {
        throw 'RUNTIME_BIND_CONSOLE_HASH'
    }
    $moduleJson = & $uid0002gbPython -I -c "import importlib.util,json,pathlib; s=importlib.util.find_spec('ida_pro_mcp.idalib_supervisor'); p=pathlib.Path(s.origin).resolve(); print(json.dumps({'module':str(p),'root':str(p.parent)}))"
    if ($LASTEXITCODE -ne 0) { throw 'RUNTIME_BIND_IMPORT_SPEC' }
    $moduleIdentity = $moduleJson | ConvertFrom-Json
    $packageRoot = (Resolve-Path -LiteralPath $moduleIdentity.root).Path
    $supervisorModule = (Resolve-Path -LiteralPath $moduleIdentity.module).Path
    if ($packageRoot -cne (Resolve-Path -LiteralPath $uid0002gbRootExpected).Path -or
        $supervisorModule -cne (Join-Path $packageRoot 'idalib_supervisor.py')) {
        throw 'RUNTIME_BIND_PACKAGE_ROOT'
    }
    $dist = @(Get-ChildItem -LiteralPath (Split-Path $packageRoot -Parent) -Directory -Filter 'ida_pro_mcp-*.dist-info' |
        Where-Object { Test-Path -LiteralPath (Join-Path $_.FullName 'entry_points.txt') })
    if ($dist.Count -ne 1) { throw "RUNTIME_BIND_DISTRIBUTION_COUNT:$($dist.Count)" }
    $entryPoints = Join-Path $dist[0].FullName 'entry_points.txt'
    if ((Get-FileHash -Algorithm SHA256 -LiteralPath $entryPoints).Hash -cne
        'DA9A1E575662C419A1180D63884494D38EF22A1A5E8619CE368DA6CD9CD9E2CF' -or
        (Get-Content -Raw -LiteralPath $entryPoints) -notmatch
        '(?m)^idalib-mcp\s*=\s*ida_pro_mcp\.idalib_supervisor:main\s*$') {
        throw 'RUNTIME_BIND_ENTRY_POINT'
    }
    $implementation = @()
    foreach ($relativePath in $uid0002gbExpectedImplementation.Keys) {
        $path = (Resolve-Path -LiteralPath (Join-Path $packageRoot $relativePath)).Path
        $sha = (Get-FileHash -Algorithm SHA256 -LiteralPath $path).Hash
        if ($sha -cne $uid0002gbExpectedImplementation[$relativePath]) {
            throw "RUNTIME_BIND_IMPLEMENTATION_HASH:${relativePath}:$sha"
        }
        $implementation += [pscustomobject][ordered]@{ RelativePath=$relativePath; Path=$path; SHA256=$sha }
    }
    [pscustomobject][ordered]@{
        Listener = $listenerTuple
        ConsoleEntryPath = (Resolve-Path -LiteralPath $uid0002gbConsole).Path
        ConsoleEntrySHA256 = '38888EDC3241C00092D5A4F166F70E6AF8DF538D4C81C8DE75E461575E27580E'
        EntryPointsPath = (Resolve-Path -LiteralPath $entryPoints).Path
        EntryPointsSHA256 = 'DA9A1E575662C419A1180D63884494D38EF22A1A5E8619CE368DA6CD9CD9E2CF'
        PackageRoot = $packageRoot
        SupervisorModule = $supervisorModule
        Implementation = $implementation
    }
}
function Assert-Uid0002GBRuntimeBinding($Expected,[string]$Boundary) {
    $actual = Get-Uid0002GBRuntimeBinding
    $expectedJson = $Expected | ConvertTo-Json -Depth 12 -Compress
    $actualJson = $actual | ConvertTo-Json -Depth 12 -Compress
    if ($actualJson -cne $expectedJson) { throw "RUNTIME_BIND_DRIFT:$Boundary" }
    $actual
}
$Uid0002GBRuntimeBinding0 = Get-Uid0002GBRuntimeBinding
~~~

## Removed Block R004

- SHA256: `93B1309431DF6945B0BD01B7144C5216F7261B7FF1F24606000B9C348FB9415A`
- Language: `powershell`
- Bytes: `2505`
- First recovered timestamp: `2026-08-06T22:48:01.803Z`
- Session provenance: rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193840 (2026-08-06T22:48:01.803Z)

~~~powershell
function Get-Uid0002GBReturnedSessionId([string]$ResponseText,[string]$ExpectedResponseId) {
    try { $response = $ResponseText | ConvertFrom-Json -ErrorAction Stop } catch { throw "OPEN_JSON_PARSE:$ExpectedResponseId" }
    if ($response.jsonrpc -cne '2.0' -or [string]$response.id -cne $ExpectedResponseId -or
        $null -ne $response.error -or $null -eq $response.result -or
        $null -eq $response.result.structuredContent -or $null -eq $response.result.structuredContent.session) {
        throw "OPEN_RESPONSE_SHAPE:$ExpectedResponseId"
    }
    $sessionId = [string]$response.result.structuredContent.session.session_id
    if ([string]::IsNullOrWhiteSpace($sessionId)) { throw "OPEN_SESSION_ID_EMPTY:$ExpectedResponseId" }
    $sessionId
}
function Get-Uid0002GBWorkerRoute([string]$ReturnedSessionId,$IdbListStructuredContent,$ServiceRoute) {
    $rows = @($IdbListStructuredContent.sessions | Where-Object { $_.session_id -ceq $ReturnedSessionId })
    if ($rows.Count -ne 1) { throw "WORKER_SESSION_ROW_COUNT:$($rows.Count)" }
    $row = $rows[0]
    if (-not $row.is_active -or $row.backend -cne 'worker' -or -not $row.owned -or
        (Resolve-Path -LiteralPath ([string]$row.input_path)).Path -cne $uid0002gbCanonical) {
        throw 'WORKER_SESSION_ROW_STATE'
    }
    $w0 = Get-Uid0002GBProcessTuple ([int]$row.worker_pid) 'W0'
    if ($w0.PID -ne [int]$row.pid -or $w0.ParentProcessId -ne $ServiceRoute.L2.PID -or
        $w0.ExecutablePath -cne $uid0002gbPython -or $w0.ListenSockets.Count -ne 0 -or
        $w0.CommandLine -notmatch '(?i)-m\s+ida_pro_mcp\.idalib_server(?:\s|$)') {
        throw 'WORKER_LAUNCHER_ROUTE'
    }
    $children = @(Get-CimInstance Win32_Process -Filter "ParentProcessId=$($w0.PID)" -ErrorAction Stop)
    $serving = @()
    foreach ($child in $children) {
        $candidate = Get-Uid0002GBProcessTuple ([int]$child.ProcessId) 'W1'
        if ($candidate.ListenSockets.Count -eq 1 -and $candidate.ListenSockets[0].Address -ceq '127.0.0.1') { $serving += $candidate }
    }
    if ($serving.Count -ne 1) { throw "WORKER_SOCKET_OWNER_COUNT:$($serving.Count)" }
    $w1 = $serving[0]
    if ($w1.ParentProcessId -ne $w0.PID -or $w1.CommandLine -notmatch '(?i)-m\s+ida_pro_mcp\.idalib_server(?:\s|$)' -or
        $w1.ListenSockets[0].PID -ne $w1.PID -or $w1.ListenSockets[0].Port -eq 13337) { throw 'WORKER_SERVING_ROUTE' }
    [pscustomobject][ordered]@{ ReturnedSessionId=$ReturnedSessionId; RegistryRow=$row; W0=$w0; W1=$w1 }
}
~~~

## Removed Block R005

- SHA256: `F42A5BEFF431E782D5E0AFD031E5200154527FED7ECFF2BC69119C0C073F956E`
- Language: `powershell`
- Bytes: `4706`
- First recovered timestamp: `2026-08-06T22:48:01.803Z`
- Session provenance: rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193840 (2026-08-06T22:48:01.803Z)

~~~powershell
$uid0002gbHost = '127.0.0.1'
$uid0002gbPort = 13337
$uid0002gbCanonical = (Resolve-Path -LiteralPath 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64').Path
$uid0002gbVenv = 'C:\Users\admin\.idapro\idalib-mcp-venv'
$uid0002gbPython = (Resolve-Path -LiteralPath (Join-Path $uid0002gbVenv 'Scripts\python.exe')).Path
$uid0002gbConsole = (Resolve-Path -LiteralPath (Join-Path $uid0002gbVenv 'Scripts\idalib-mcp.exe')).Path
$uid0002gbRootExpected = (Resolve-Path -LiteralPath (Join-Path $uid0002gbVenv 'Lib\site-packages\ida_pro_mcp')).Path
$uid0002gbExpectedImplementation = [ordered]@{
    'ida_pro_mcp.idalib_supervisor'='idalib_supervisor.py|2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A'
    'ida_pro_mcp.idalib_server'='idalib_server.py|06C922EEF3F2E6771308C687231FE443A65DADF340E72001C6B05B7FC70B2034'
    'ida_pro_mcp.idalib_session_manager'='idalib_session_manager.py|9EDEEBD47B6FF85F9809E7159CE03D3EF41833692D28AC4367C6C4E5CAE00890'
    'ida_pro_mcp.worker_lifecycle'='worker_lifecycle.py|303A2A15BB316CD2200B2C54EF8685EBBC50EF5114FDD1FBC6C16CD01B6BAC63'
    'ida_pro_mcp.ida_mcp.api_types'='ida_mcp\api_types.py|A3E7444BBAC0066B48EDF38E26F34E6ABEC823585CD50E43C6DA98C55B965ECF'
    'ida_pro_mcp.ida_mcp.api_modify'='ida_mcp\api_modify.py|161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8'
    'ida_pro_mcp.ida_mcp.api_stack'='ida_mcp\api_stack.py|9E4B5898E875812E4C993597D44F0F6438430F92A8B2299DC5C62630D49AE1BB'
    'ida_pro_mcp.ida_mcp.api_core'='ida_mcp\api_core.py|90C59B3F64F26E170CC604000CE39B34B648352767059DD1C2DF1914E9CBD4A3'
    'ida_pro_mcp.ida_mcp.api_analysis'='ida_mcp\api_analysis.py|4C9B9122A7D2697CD464C1F473A227A580FD803515A1C885A1AA262259F1969F'
    'ida_pro_mcp.ida_mcp.api_memory'='ida_mcp\api_memory.py|A2D4E48921E2E7A8D3C4BD621658F645A9C17C7FB34E963E62AE864E452ABC93'
    'ida_pro_mcp.ida_mcp.framework'='ida_mcp\framework.py|518100959115851FAAD98A48D4E0D918B4439C1C6666671C9DA93AA7312414B4'
}
function Get-Uid0002GBProcessTuple([int]$PID,[string]$Level) {
    $cim = Get-CimInstance Win32_Process -Filter "ProcessId=$PID" -ErrorAction Stop
    $process = Get-Process -Id $PID -ErrorAction Stop
    $sockets = @(Get-NetTCPConnection -State Listen -OwningProcess $PID -ErrorAction SilentlyContinue |
        Sort-Object LocalAddress,LocalPort |
        ForEach-Object { [pscustomobject][ordered]@{ Address=$_.LocalAddress; Port=[int]$_.LocalPort; PID=[int]$_.OwningProcess } })
    [pscustomobject][ordered]@{
        Level = $Level
        PID = $PID
        ParentProcessId = [int]$cim.ParentProcessId
        CimCreationUtcTicks = [long]$cim.CreationDate.ToUniversalTime().Ticks
        StartTimeUtcTicks = [long]$process.StartTime.ToUniversalTime().Ticks
        ExecutablePath = (Resolve-Path -LiteralPath ([string]$cim.ExecutablePath)).Path
        CommandLine = [string]$cim.CommandLine
        ListenSockets = $sockets
    }
}
function Get-Uid0002GBServiceRoute {
    $owners = @(Get-NetTCPConnection -State Listen -ErrorAction Stop |
        Where-Object { $_.LocalAddress -eq $uid0002gbHost -and $_.LocalPort -eq $uid0002gbPort })
    if ($owners.Count -ne 1) { throw "SERVICE_ROUTE_SOCKET_COUNT:$($owners.Count)" }
    $l2 = Get-Uid0002GBProcessTuple ([int]$owners[0].OwningProcess) 'L2'
    $l1 = Get-Uid0002GBProcessTuple $l2.ParentProcessId 'L1'
    $l0 = Get-Uid0002GBProcessTuple $l1.ParentProcessId 'L0'
    if ($l2.ParentProcessId -ne $l1.PID -or $l1.ParentProcessId -ne $l0.PID) { throw 'SERVICE_ROUTE_PARENT_EDGE' }
    if ($l0.ExecutablePath -cne $uid0002gbConsole) { throw 'SERVICE_ROUTE_L0_IMAGE' }
    if ($l1.ExecutablePath -cne $uid0002gbPython) { throw 'SERVICE_ROUTE_L1_IMAGE' }
    if ($l0.ListenSockets.Count -ne 0 -or $l1.ListenSockets.Count -ne 0) { throw 'SERVICE_ROUTE_ROOT_OR_VENV_SOCKET' }
    if ($l2.ListenSockets.Count -ne 1 -or $l2.ListenSockets[0].Address -cne $uid0002gbHost -or
        $l2.ListenSockets[0].Port -ne $uid0002gbPort -or $l2.ListenSockets[0].PID -ne $l2.PID) {
        throw 'SERVICE_ROUTE_L2_SOCKET'
    }
    if ($l0.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1(?:\s|$)' -or
        $l0.CommandLine -notmatch '(?i)--port\s+13337(?:\s|$)' -or
        $l1.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1(?:\s|$)' -or
        $l1.CommandLine -notmatch '(?i)--port\s+13337(?:\s|$)') { throw 'SERVICE_ROUTE_L0_L1_COMMAND' }
    [pscustomobject][ordered]@{ L0=$l0; L1=$l1; L2=$l2; Endpoint="http://$uid0002gbHost`:$uid0002gbPort/mcp" }
}
function Assert-Uid0002GBExactObject($Expected,$Actual,[string]$Boundary) {
    if (($Expected | ConvertTo-Json -Depth 20 -Compress) -cne ($Actual | ConvertTo-Json -Depth 20 -Compress)) {
        throw "BINDING_DRIFT:$Boundary"
    }
}
~~~

## Removed Block R006

- SHA256: `454A61BF5ACB0D0668830CE0740389CC87E1CFA6316E91FE4AECAD9215A87862`
- Language: `powershell`
- Bytes: `271`
- First recovered timestamp: `2026-08-06T22:48:31.905Z`
- Session provenance: rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193850 (2026-08-06T22:48:31.905Z); rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193858 (2026-08-06T22:48:51.849Z); rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193859 (2026-08-06T22:48:51.902Z)

~~~powershell
$RB = Get-Uid0002GBReturnedSessionId $O03ResponseText 'O03'
$RBRoute = Get-Uid0002GBWorkerRoute $RB $O03IdbListStructuredContent $Uid0002GBServiceRoute0
$RBLoadedModules = Invoke-Uid0002GBLoadedModuleAttestation $RBRoute.W1 'RB' $uid0002gbWorkerModules
~~~

## Removed Block R007

- SHA256: `6F8F2FB960EA1439B10C0FBFE3D30856329A5E3281714DDBC1D8FFF4173AF64B`
- Language: `powershell`
- Bytes: `265`
- First recovered timestamp: `2026-08-06T22:48:31.905Z`
- Session provenance: rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193850 (2026-08-06T22:48:31.905Z); rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193858 (2026-08-06T22:48:51.849Z); rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193859 (2026-08-06T22:48:51.902Z)

~~~powershell
$V = Get-Uid0002GBReturnedSessionId $O02ResponseText 'O02'
$VRoute = Get-Uid0002GBWorkerRoute $V $O02IdbListStructuredContent $Uid0002GBServiceRoute0
$VLoadedModules = Invoke-Uid0002GBLoadedModuleAttestation $VRoute.W1 'V' $uid0002gbWorkerModules
~~~

## Removed Block R008

- SHA256: `9D2299D382EE300ADEAFF298D57203E6666F7DD864C38E2D31B75DEA4691B173`
- Language: `powershell`
- Bytes: `271`
- First recovered timestamp: `2026-08-06T22:48:31.905Z`
- Session provenance: rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193850 (2026-08-06T22:48:31.905Z); rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193858 (2026-08-06T22:48:51.849Z); rollout-2026-08-06T18-22-25-019fd92b-ac6f-7260-9e40-31d5b84a2f30.jsonl line 193859 (2026-08-06T22:48:51.902Z)

~~~powershell
$TX = Get-Uid0002GBReturnedSessionId $O01ResponseText 'O01'
$TXRoute = Get-Uid0002GBWorkerRoute $TX $O01IdbListStructuredContent $Uid0002GBServiceRoute0
$TXLoadedModules = Invoke-Uid0002GBLoadedModuleAttestation $TXRoute.W1 'TX' $uid0002gbWorkerModules
~~~

## Removed Block R009

- SHA256: `95AF6795F753E88F7127600A0F7FBBD557DBAEFE0C25067EF4CD74792450BF25`
- Language: `powershell`
- Bytes: `6104`
- First recovered timestamp: `2026-08-06T23:29:50.694Z`
- Session provenance: rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 194081 (2026-08-06T23:29:50.694Z)

~~~powershell
function Get-Uid0002GBSoleTextPayload([string]$ResponseText,[string]$ExpectedResponseId) {
    try { $rpc=$ResponseText|ConvertFrom-Json -ErrorAction Stop } catch { throw "RPC_JSON_PARSE:$ExpectedResponseId" }
    if($rpc.jsonrpc-cne'2.0' -or [string]$rpc.id-cne$ExpectedResponseId -or $rpc.error -or $null-eq$rpc.result){throw "RPC_ENVELOPE:$ExpectedResponseId"}
    $content=@($rpc.result.content)
    if($content.Count-ne 1 -or $content[0].type-cne'text' -or [string]::IsNullOrWhiteSpace([string]$content[0].text)){throw "RPC_TEXT_PAYLOAD:$ExpectedResponseId"}
    try {$payload=$content[0].text|ConvertFrom-Json -ErrorAction Stop} catch {throw "RPC_PAYLOAD_JSON:$ExpectedResponseId"}
    if($null-eq$payload){throw "RPC_PAYLOAD_NULL:$ExpectedResponseId"}
    $payload
}
function Assert-Uid0002GBToolsListSurface([string]$ResponseText) {
    $rpc=$ResponseText|ConvertFrom-Json -ErrorAction Stop
    if($rpc.error -or $null-eq$rpc.result){throw 'TOOLS_LIST_ENVELOPE'}
    $public=@($rpc.result.tools|Where-Object name -ceq 'runtime_attestation')
    $internal=@($rpc.result.tools|Where-Object name -ceq 'runtime/attest')
    if($public.Count-ne 1 -or $internal.Count-ne 0){throw "ATTEST_SURFACE:$($public.Count):$($internal.Count)"}
    $schema=$public[0].inputSchema|ConvertTo-Json -Depth 100 -Compress
    $sha=[Security.Cryptography.SHA256]::Create()
    try {$digest=(-join($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($schema))|ForEach-Object{$_.ToString('x2')})).ToUpper()}finally{$sha.Dispose()}
    if($digest-cne'775C991F67ACC7ABEDCB71ED7381E728E6AF7FC55EE56947682976BA40B8E200'){throw "ATTEST_SCHEMA:$digest"}
}
function Get-Uid0002GBModuleIdentityProjection($Owner,[string[]]$RequiredNames,[string]$Label) {
    $root=(Resolve-Path -LiteralPath ([string]$Owner.source_root)).Path
    if($root-cne$uid0002gbRootExpected -or [string]::IsNullOrWhiteSpace([string]$Owner.implementation_manifest_sha256)){throw "ATTEST_ROOT_OR_MANIFEST:$Label"}
    $rows=@($Owner.modules)
    if($rows.Count-lt$RequiredNames.Count){throw "ATTEST_MODULE_COUNT:$Label:$($rows.Count)"}
    foreach($name in $RequiredNames){if(@($rows|Where-Object sys_modules_name -ceq $name).Count-ne 1){throw "ATTEST_REQUIRED_MODULE:$Label:$name"}}
    $projection=[Collections.Generic.List[object]]::new()
    foreach($row in $rows|Sort-Object sys_modules_name){
        $resolved=(Resolve-Path -LiteralPath ([string]$row.resolved_path)).Path
        if($resolved-cne(Resolve-Path -LiteralPath ([string]$row.file)).Path -or $resolved-cne(Resolve-Path -LiteralPath ([string]$row.spec_origin)).Path -or
           -not $resolved.StartsWith($root+[IO.Path]::DirectorySeparatorChar,[StringComparison]::OrdinalIgnoreCase) -or
           [string]::IsNullOrWhiteSpace([string]$row.module_id) -or [string]::IsNullOrWhiteSpace([string]$row.sha256) -or [long]$row.size-lt 0){throw "ATTEST_MODULE_ROW:$Label:$($row.sys_modules_name)"}
        $item=Get-Item -LiteralPath $resolved -ErrorAction Stop
        if($item.Length-ne[long]$row.size -or (Get-FileHash -Algorithm SHA256 -LiteralPath $resolved).Hash-cne[string]$row.sha256){throw "ATTEST_MODULE_DISK:$Label:$($row.sys_modules_name)"}
        $projection.Add([ordered]@{name=[string]$row.sys_modules_name;module_id=[string]$row.module_id;path=$resolved;size=[long]$row.size;mtime_ns=[string]$row.mtime_ns;sha256=[string]$row.sha256})
    }
    [ordered]@{source_root=$root;manifest=[string]$Owner.implementation_manifest_sha256;modules=@($projection)}
}
function Assert-Uid0002GBRuntimeAttestation($Payload,[string]$ExpectedDatabase,$ServiceRoute,[string]$Boundary) {
    if([int]$Payload.schema_version-ne 1 -or $Payload.ok-ne$true -or @($Payload.errors).Count-ne 0){throw "ATTEST_TOP:$Boundary"}
    $listener=$Payload.listener
    if($listener.role-cne'supervisor_listener' -or $listener.endpoint.host-cne$uid0002gbHost -or [int]$listener.endpoint.port-ne$uid0002gbPort -or
       [int]$listener.process.pid-ne[int]$ServiceRoute.L2.PID -or [int]$listener.process.parent_pid-ne[int]$ServiceRoute.L1.PID -or
       [string]$listener.process.generation-cne("pid:$($ServiceRoute.L2.PID);created:$([DateTime]::new($ServiceRoute.L2.StartTimeUtcTicks,[DateTimeKind]::Utc).ToFileTimeUtc())")){throw "ATTEST_LISTENER_ROUTE:$Boundary"}
    $socket=@(Get-NetTCPConnection -State Listen -LocalAddress $uid0002gbHost -LocalPort $uid0002gbPort -ErrorAction Stop)
    if($socket.Count-ne 1 -or [int]$socket[0].OwningProcess-ne[int]$listener.process.pid){throw "ATTEST_LISTENER_SOCKET:$Boundary"}
    $listenerIdentity=Get-Uid0002GBModuleIdentityProjection $listener $uid0002gbListenerRequiredModules "$Boundary:L2"
    $selected=@()
    if(-not [string]::IsNullOrWhiteSpace($ExpectedDatabase)){
        foreach($entry in @($Payload.workers)){
            foreach($session in @($entry.supervisor_sessions)){
                if([string]$session.session_id-ceq$ExpectedDatabase){$selected+=,[ordered]@{entry=$entry;session=$session}}
            }
        }
        if($selected.Count-ne 1){throw "ATTEST_SESSION_COUNT:$Boundary:$($selected.Count)"}
        $entry=$selected[0].entry;$session=$selected[0].session;$wa=$entry.attestation
        if($wa.schema_version-ne 1 -or $wa.ok-ne$true -or @($wa.errors).Count-ne 0 -or $wa.worker.role-cne'stateful_worker'){throw "ATTEST_WORKER_TOP:$Boundary"}
        if(([IO.Path]::GetFullPath([string]$session.canonical_path)).Equals($uid0002gbCanonical,[StringComparison]::OrdinalIgnoreCase)-ne$true -or
           [int]$wa.worker.process.parent_pid-ne[int]$session.redirector_pid -or [int]$entry.route.port-ne[int]$wa.worker.endpoint.port -or
           [int]$entry.route.port-eq$uid0002gbPort){throw "ATTEST_WORKER_ROUTE:$Boundary"}
        $workerIdentity=Get-Uid0002GBModuleIdentityProjection $wa.worker $uid0002gbWorkerRequiredModules "$Boundary:W1"
    } else {$workerIdentity=$null}
    [ordered]@{listener_process=$listener.process;listener_modules=$listenerIdentity;worker_process=if($workerIdentity){$wa.worker.process}else{$null};worker_modules=$workerIdentity;session=if($selected.Count){$selected[0].session}else{$null}}
}
~~~

## Removed Block R010

- SHA256: `E6CC224F720BE2F65BE007C04922690BF74272C78FF7C4FAD1DCE4C63F2D8549`
- Language: `powershell`
- Bytes: `5687`
- First recovered timestamp: `2026-08-06T23:29:50.694Z`
- Session provenance: rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 194081 (2026-08-06T23:29:50.694Z)

~~~powershell
function Write-Uid0002GBExclusiveUtf8([string]$Path,[string]$Text) {
    $fs = [IO.File]::Open($Path,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None)
    try {
        $bytes = [Text.UTF8Encoding]::new($false).GetBytes($Text)
        $fs.Write($bytes,0,$bytes.Length)
        $fs.Flush($true)
    } finally { $fs.Dispose() }
}
function Invoke-Uid0002GBLoadedModuleAttestation($ProcessTuple,[string]$Role,[string[]]$RequiredModules) {
    $nonce = [Guid]::NewGuid().ToString('N')
    $requestPath = Join-Path $env:TEMP "uid0002gb-$($ProcessTuple.PID)-$nonce.request.json"
    $outputPath = Join-Path $env:TEMP "uid0002gb-$($ProcessTuple.PID)-$nonce.response.json"
    $scriptPath = Join-Path $env:TEMP "uid0002gb-$($ProcessTuple.PID)-$nonce.attest.py"
    foreach ($path in @($requestPath,$outputPath,$scriptPath)) { if (Test-Path -LiteralPath $path) { throw 'ATTEST_PATH_COLLISION' } }
    $request = [ordered]@{ pid=[int]$ProcessTuple.PID; role=$Role; nonce=$nonce; output_path=$outputPath; required_modules=$RequiredModules }
    Write-Uid0002GBExclusiveUtf8 $requestPath ($request | ConvertTo-Json -Depth 8 -Compress)
    $pythonSource = @'
import sys, os, json, hashlib

_REQUEST_PATH = __UID0002GB_REQUEST_PATH__

def _uid0002gb_attest():
    with open(_REQUEST_PATH, "r", encoding="utf-8") as stream:
        request = json.load(stream)
    if int(request["pid"]) != os.getpid():
        raise RuntimeError("ATTEST_PID")
    rows = []
    for name in request["required_modules"]:
        module = sys.modules.get(name)
        if module is None:
            raise RuntimeError("ATTEST_MODULE_MISSING:" + name)
        file_path = os.path.realpath(getattr(module, "__file__", ""))
        spec = getattr(module, "__spec__", None)
        origin = os.path.realpath(getattr(spec, "origin", "") or "")
        if not file_path or file_path != origin or not os.path.isfile(file_path):
            raise RuntimeError("ATTEST_ORIGIN:" + name)
        source_stat = os.stat(file_path)
        with open(file_path, "rb") as source:
            digest = hashlib.sha256(source.read()).hexdigest().upper()
        loader = getattr(module, "__loader__", None)
        loader_type = type(loader).__module__ + "." + type(loader).__qualname__
        rows.append({"name":name,"file":file_path,"origin":origin,"loader":loader_type,"sha256":digest,
                     "size":source_stat.st_size,"mtime_ns":str(source_stat.st_mtime_ns)})
    response = {"pid":os.getpid(),"role":request["role"],"nonce":request["nonce"],"executable":sys.executable,
                "version":sys.version,"modules":rows}
    flags = os.O_WRONLY | os.O_CREAT | os.O_EXCL
    fd = os.open(request["output_path"], flags, 0o600)
    with os.fdopen(fd, "w", encoding="utf-8", newline="\n") as stream:
        json.dump(response, stream, sort_keys=True, separators=(",", ":"))
        stream.write("\n")
        stream.flush()
        os.fsync(stream.fileno())

_uid0002gb_attest()
del _uid0002gb_attest
'@
    $requestLiteral = $requestPath | ConvertTo-Json -Compress
    $pythonSource = $pythonSource.Replace('__UID0002GB_REQUEST_PATH__',$requestLiteral)
    Write-Uid0002GBExclusiveUtf8 $scriptPath $pythonSource
    $scriptSha = (Get-FileHash -Algorithm SHA256 -LiteralPath $scriptPath).Hash
    $scriptLiteral = $scriptPath | ConvertTo-Json -Compress
    & $uid0002gbPython -I -c "import sys; sys.remote_exec($($ProcessTuple.PID), $scriptLiteral)"
    if ($LASTEXITCODE -ne 0) { throw 'ATTEST_REMOTE_EXEC' }
    $deadline = [DateTime]::UtcNow.AddSeconds(15)
    while (-not (Test-Path -LiteralPath $outputPath -PathType Leaf)) {
        if ([DateTime]::UtcNow -ge $deadline) { throw 'ATTEST_TIMEOUT' }
        Start-Sleep -Milliseconds 100
    }
    $raw = [IO.File]::ReadAllText($outputPath,[Text.Encoding]::UTF8)
    try { $attestation = $raw | ConvertFrom-Json -ErrorAction Stop } catch { throw 'ATTEST_JSON_PARSE' }
    if ([int]$attestation.pid -ne [int]$ProcessTuple.PID -or $attestation.role -cne $Role -or
        $attestation.nonce -cne $nonce -or @($attestation.modules).Count -ne $RequiredModules.Count) {
        throw 'ATTEST_IDENTITY_OR_COUNT'
    }
    for ($i=0;$i -lt $RequiredModules.Count;$i++) {
        $name = $RequiredModules[$i]
        $row = $attestation.modules[$i]
        if ($row.name -cne $name -or $row.file -cne $row.origin) { throw "ATTEST_ROW:$name" }
        $expected = $uid0002gbExpectedImplementation[$name]
        if (-not $expected) { throw "ATTEST_NO_EXPECTED_MODULE:$name" }
        $parts = $expected.Split('|',2)
        $expectedPath = (Resolve-Path -LiteralPath (Join-Path $uid0002gbRootExpected $parts[0])).Path
        $sourceItem = Get-Item -LiteralPath $expectedPath -ErrorAction Stop
        $sourceMtimeNs = ([decimal]($sourceItem.LastWriteTimeUtc.Ticks - 621355968000000000) * 100).ToString('0')
        if ((Resolve-Path -LiteralPath $row.file).Path -cne $expectedPath -or $row.sha256 -cne $parts[1] -or
            [long]$row.size -ne [long]$sourceItem.Length -or [string]$row.mtime_ns -cne $sourceMtimeNs -or
            $sourceItem.LastWriteTimeUtc.Ticks -gt [long]$ProcessTuple.StartTimeUtcTicks) {
            throw "ATTEST_PATH_OR_HASH:$name"
        }
    }
    [pscustomobject][ordered]@{ Process=$ProcessTuple; Role=$Role; Nonce=$nonce; ScriptSHA256=$scriptSha;
        RequestPath=$requestPath; OutputPath=$outputPath; OutputSHA256=(Get-FileHash -Algorithm SHA256 -LiteralPath $outputPath).Hash;
        Attestation=$attestation }
}
$Uid0002GBServiceRoute0 = Get-Uid0002GBServiceRoute
$Uid0002GBL2LoadedModules0 = Invoke-Uid0002GBLoadedModuleAttestation $Uid0002GBServiceRoute0.L2 'L2' $uid0002gbListenerModules
~~~

## Removed Block R011

- SHA256: `04E1A6A134FB3D37E1A300E5ED326F84FBD004DA3826879E86A6F47145ED610C`
- Language: `powershell`
- Bytes: `4490`
- First recovered timestamp: `2026-08-06T23:31:27.445Z`
- Session provenance: rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 194092 (2026-08-06T23:31:27.445Z); rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 194093 (2026-08-06T23:31:27.513Z)

~~~powershell
$script:Uid0002GBSaveDispatchCount=0
function Resolve-Uid0002GBLiteralRequest([string]$Literal,[hashtable]$Bindings) {
    $text=$Literal.Trim()
    foreach($token in @('TX','V','RB')){
        $needle='"<'+$token+'>"'
        $count=([regex]::Matches($text,[regex]::Escape($needle))).Count
        if($count-gt 0){
            if(-not $Bindings.ContainsKey($token) -or [string]::IsNullOrWhiteSpace([string]$Bindings[$token])){throw "REQUEST_BINDING_MISSING:$token"}
            $replacement=([string]$Bindings[$token]|ConvertTo-Json -Compress)
            $text=$text.Replace($needle,$replacement)
        }
    }
    if($text-match'"<(TX|V|RB)>"'){throw 'REQUEST_BINDING_REMAINS'}
    try {$request=$text|ConvertFrom-Json -ErrorAction Stop}catch{throw 'REQUEST_LITERAL_JSON'}
    if($request.jsonrpc-cne'2.0' -or [string]::IsNullOrWhiteSpace([string]$request.id) -or [string]::IsNullOrWhiteSpace([string]$request.method)){throw 'REQUEST_ENVELOPE'}
    $request
}
function Write-Uid0002GBCounted([IO.Stream]$Stream,[byte[]]$Bytes) {
    $written=0
    while($written-lt$Bytes.Length){$count=[Math]::Min(65536,$Bytes.Length-$written);$Stream.Write($Bytes,$written,$count);$written+=$count}
    if($written-ne$Bytes.Length){throw "COUNTED_WRITE:$written:$($Bytes.Length)"}
    $written
}
function Invoke-Uid0002GBJournaledMcp($Request,[string]$JournalPath,$AuthorizedSaveRequest,[switch]$AuthorizeSoleSave) {
    $requestJson=$Request|ConvertTo-Json -Depth 100 -Compress
    $requestRoundTrip=$requestJson|ConvertFrom-Json -ErrorAction Stop
    if(($requestRoundTrip|ConvertTo-Json -Depth 100 -Compress)-cne$requestJson){throw "REQUEST_ROUNDTRIP:$($Request.id)"}
    $tool=if($Request.method-ceq'tools/call'){[string]$Request.params.name}else{[string]$Request.method}
    if($tool-ceq'idb_save'){
        if(-not$AuthorizeSoleSave -or $null-eq$AuthorizedSaveRequest){throw 'UNAUTHORIZED_SAVE_REQUEST'}
        $authorizedJson=$AuthorizedSaveRequest|ConvertTo-Json -Depth 100 -Compress
        if($requestJson-cne$authorizedJson){throw 'SAVE_REQUEST_NOT_EXACT_AUTHORIZED_OBJECT'}
        if($script:Uid0002GBSaveDispatchCount-ne 0){throw 'SAVE_ALREADY_DISPATCHED'}
        $script:Uid0002GBSaveDispatchCount=1
    } elseif($AuthorizeSoleSave){throw 'SAVE_AUTHORIZATION_ON_NON_SAVE'}
    $body=[Text.UTF8Encoding]::new($false).GetBytes($requestJson)
    try {
        $response=(Invoke-WebRequest -UseBasicParsing -Uri 'http://127.0.0.1:13337/mcp' -Method Post -ContentType 'application/json' -Headers @{Accept='application/json, text/event-stream'} -Body $body -TimeoutSec 30 -ErrorAction Stop).Content
    } catch {throw "MCP_HTTP:$($Request.id):$($_.Exception.Message)"}
    try {$rpc=$response|ConvertFrom-Json -ErrorAction Stop}catch{throw "MCP_RESPONSE_JSON:$($Request.id)"}
    if($rpc.jsonrpc-cne'2.0' -or [string]$rpc.id-cne[string]$Request.id -or $rpc.error){throw "MCP_RESPONSE_ENVELOPE:$($Request.id)"}
    $sequence=if(Test-Path -LiteralPath $JournalPath){@(Get-Content -LiteralPath $JournalPath).Count}else{0}
    $row=[ordered]@{sequence=$sequence;request=$requestRoundTrip;requestText=$requestJson;responseText=[string]$response;responseComplete=$true;responseError=$false}
    $rowJson=$row|ConvertTo-Json -Depth 100 -Compress
    $bytes=[Text.UTF8Encoding]::new($false).GetBytes($rowJson+"`n")
    $fs=[IO.File]::Open($JournalPath,[IO.FileMode]::OpenOrCreate,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
    try {$before=$fs.Length;$fs.Position=$before;$count=Write-Uid0002GBCounted $fs $bytes;$fs.Flush($true);if($count-ne$bytes.Length -or $fs.Position-ne$before+$bytes.Length -or $fs.Length-ne$before+$bytes.Length){throw "JOURNAL_APPEND:$($Request.id)"}}finally{$fs.Dispose()}
    $verify=[IO.File]::Open($JournalPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
    try {$reader=[IO.StreamReader]::new($verify,[Text.UTF8Encoding]::new($false),$true,65536,$true);try{$all=$reader.ReadToEnd()}finally{$reader.Dispose()}}finally{$verify.Dispose()}
    $lines=@($all-split"`n"|Where-Object{$_-cne''})
    if($lines.Count-ne$sequence+1){throw "JOURNAL_ROW_COUNT:$($Request.id)"}
    foreach($line in $lines){[void]($line|ConvertFrom-Json -ErrorAction Stop)}
    $last=$lines[-1]|ConvertFrom-Json -ErrorAction Stop
    if([int]$last.sequence-ne$sequence -or $last.requestText-cne$requestJson -or $last.responseText-cne$response -or -not$last.responseComplete -or $last.responseError){throw "JOURNAL_READBACK:$($Request.id)"}
    $rpc
}
~~~

## Removed Block R012

- SHA256: `B78A316F4062876AEDE133C683C210BC63E432A1E7BDFDF87A375AB564E40FB3`
- Language: `powershell`
- Bytes: `1695`
- First recovered timestamp: `2026-08-06T23:57:13.672Z`
- Session provenance: rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 194486 (2026-08-06T23:57:13.672Z); rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 194487 (2026-08-06T23:57:13.739Z)

~~~powershell
Stop-ExactWorker $VRoute.W1
$vProcessAbsent=($null-eq(Get-CimInstance Win32_Process -Filter "ProcessId=$($VRoute.W1.PID)" -ErrorAction SilentlyContinue))
$PostVerifierER00Request=Resolve-Uid0002GBLiteralRequest '{"jsonrpc":"2.0","id":"ER00-post-verifier","method":"tools/call","params":{"name":"idb_list","arguments":{}}}' @{}
$PostVerifierER00Rpc=Invoke-Uid0002GBJournaledMcp $PostVerifierER00Request $ExactProcessJournal $null
$PostVerifierER00Receipt=Assert-Uid0002GBNoActiveCanonical (Get-Uid0002GBStructuredContent ($PostVerifierER00Rpc|ConvertTo-Json -Depth 100 -Compress) 'ER00-post-verifier') 'POST_VERIFIER_ER00'
$PostVRetireBoundary=Invoke-Uid0002GBBoundary 'POST-V-RETIRE' '' $ExactBindingJournal $ListenerRuntimeBinding
$SuccessBoundaryChainReceipt=Get-Uid0002GBBoundaryChainReceipt $ExactBindingJournal @('PREOPEN','PRE-O01','POST-O01','PRE-A01','PRE-SAVE','POST-TX-RETIRE','PRE-O02','POST-O02','POST-V-RETIRE')
if(-not$vProcessAbsent -or -not$SuccessBoundaryChainReceipt.Ok -or [int]$PostVerifierER00Receipt.ActiveCanonicalCount-ne 0){throw 'VERIFIER_RETIREMENT_CHAIN'}
$p1Verify=[IO.File]::Open($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
try{$p1VerifySha=Get-OpenStreamSha256 $p1Verify;$p1VerifySize=$p1Verify.Length;$p1VerifyTicks=[IO.File]::GetLastWriteTimeUtc($canonical).Ticks}finally{$p1Verify.Dispose()}
if($p1VerifySha-cne$P1.Sha256 -or $p1VerifySize-ne$P1.Size -or $p1VerifyTicks-ne$P1.LastWriteUtcTicks){throw 'FINAL_CLOSED_P1_DRIFT'}
$FinalP1Receipt=[ordered]@{Receipt='FINAL_CLOSED_P1_OK';Path=$P1.Path;Sha256=$p1VerifySha;Size=$p1VerifySize;LastWriteUtcTicks=$p1VerifyTicks;BoundaryChain=$SuccessBoundaryChainReceipt}
~~~

## Removed Block R013

- SHA256: `E2E3985FAF405DAA8E0BE14979190DD14996F3DE69E6C4789B84A18335FF777F`
- Language: `powershell`
- Bytes: `1705`
- First recovered timestamp: `2026-08-06T23:57:37.845Z`
- Session provenance: rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 194496 (2026-08-06T23:57:37.845Z); rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 194497 (2026-08-06T23:57:37.914Z)

~~~powershell
Stop-ExactWorker $RBRoute.W1
$rbProcessAbsent=($null-eq(Get-CimInstance Win32_Process -Filter "ProcessId=$($RBRoute.W1.PID)" -ErrorAction SilentlyContinue))
$PostRollbackER00Request=Resolve-Uid0002GBLiteralRequest '{"jsonrpc":"2.0","id":"ER00-post-rollback","method":"tools/call","params":{"name":"idb_list","arguments":{}}}' @{}
$PostRollbackER00Rpc=Invoke-Uid0002GBJournaledMcp $PostRollbackER00Request $ExactProcessJournal $null
$PostRollbackER00Receipt=Assert-Uid0002GBNoActiveCanonical (Get-Uid0002GBStructuredContent ($PostRollbackER00Rpc|ConvertTo-Json -Depth 100 -Compress) 'ER00-post-rollback') 'POST_ROLLBACK_ER00'
$PostRBRetireBoundary=Invoke-Uid0002GBBoundary 'POST-RB-RETIRE' '' $ExactBindingJournal $ListenerRuntimeBinding
$RollbackBoundaryChainReceipt=Get-Uid0002GBBoundaryChainReceipt $ExactBindingJournal @('PREOPEN','PRE-O01','POST-O01','PRE-A01','PRE-SAVE','POST-TX-RETIRE','PRE-RESTORE','POST-RESTORE','PRE-O03','POST-O03','POST-RB-RETIRE')
if(-not$rbProcessAbsent -or -not$RollbackBoundaryChainReceipt.Ok -or [int]$PostRollbackER00Receipt.ActiveCanonicalCount-ne 0){throw 'ROLLBACK_RETIREMENT_CHAIN'}
$finalP0=[IO.File]::Open($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
try{$finalP0Sha=Get-OpenStreamSha256 $finalP0;$finalP0Size=$finalP0.Length;$finalP0Ticks=[IO.File]::GetLastWriteTimeUtc($canonical).Ticks}finally{$finalP0.Dispose()}
if($finalP0Sha-cne$p0Sha -or $finalP0Size-ne$p0Size -or $finalP0Ticks-ne$p0Ticks){throw 'FINAL_CLOSED_P0_DRIFT'}
$FinalP0Receipt=[ordered]@{Receipt='FINAL_CLOSED_P0_OK';Path=$canonical;Sha256=$finalP0Sha;Size=$finalP0Size;LastWriteUtcTicks=$finalP0Ticks;BoundaryChain=$RollbackBoundaryChainReceipt}
~~~

## Removed Block R014

- SHA256: `26F534B4CBC9AD08C4440F20BF8F2F1421F60FA0D6607303CDCEEB5869147306`
- Language: `powershell`
- Bytes: `500`
- First recovered timestamp: `2026-08-07T00:13:08.521Z`
- Session provenance: rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 194853 (2026-08-07T00:13:08.521Z); rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 194854 (2026-08-07T00:13:08.585Z)

~~~powershell
$H02Request=Resolve-Uid0002GBLiteralRequest '{"jsonrpc":"2.0","id":"H02","method":"tools/call","params":{"name":"server_health","arguments":{"database":"<TX>"}}}' @{TX=$TX}
$H02Rpc=Invoke-Uid0002GBJournaledMcp $H02Request $ExactTransactionJournal $null
$HealthAfterF=Get-Uid0002GBSoleTextPayload ($H02Rpc|ConvertTo-Json -Depth 100 -Compress) 'H02'
if($HealthAfterF.status-cne'ok' -or [string]$HealthAfterF.database-cne$TX -or $HealthAfterF.is_analyzing){throw 'H02_HEALTH_BINDING'}
~~~

## Removed Block R015

- SHA256: `CE4A8D85AEFC637F7132C3CBB3D2B893DE442B4050AB2CE7412AB88DF22224B9`
- Language: `powershell`
- Bytes: `40488`
- First recovered timestamp: `2026-08-07T00:55:05.593Z`
- Session provenance: rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 195393 (2026-08-07T00:55:05.593Z)

~~~powershell
# UID0002GB_GATE1_CONTROLLER_BEGIN
$script:Uid0002GBCanonicalPath = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$script:Uid0002GBCommonOrder = @(
    'TL00','AT00','ER00-list','O01','L01','AT01','H01',
    'I01','I02','I03','I04','I05','I06','I07','I08','I09',
    'A01','J01',
    'D02','D02V','A02','J02','J02B',
    'D03-ROW','D03-ROWV','A03-ROW','J03-ROW',
    'D03-ITEM','D03-ITEMV','A03-ITEM','J03-ITEM',
    'D03-BOUNDS','D03-BOUNDSV','A03-BOUNDS','J03-BOUNDS',
    'A04-ROW','J04-ROW','A04-ITEM','J04-ITEM','A04-BOUNDS','J04-BOUNDS',
    'A05','J05','J05B','J05C','A06','J06',
    'D07','D07V','A07','J07','J07B','J07C','J07D','J07E',
    'A08-CB','J08-CB','J08-CBB','J08-CBC','J08-CBD',
    'A08-VTABLE','J08-VTABLE','J08-VTABLEB','J08-VTABLEC','J08-VTABLED',
    'A09','J09','J09B','J09C','J09D',
    'F01','F02','F03','F04','F05','F06','F07','F08','F09','H02','A10-SAVE-ONCE'
)
$script:Uid0002GBVerifierOrder = @('O02','L02','AT02','VH01','R01','R02','R03','R04','R05','R06','R07','R08','R09')
$script:Uid0002GBRollbackOrder = @('O03','L03','AT03','RBH01','RB01','RB02','RB03','RB04','RB05','RB06','RB07','RB08','RB09')
$script:Uid0002GBImmutablePrestate = [ordered]@{
    TargetAddress='0x004832c0'; TargetName='sub_4832C0'; TargetSize='0x154'
    NewFunctionName='ChattingColorListPane_DrawItem'; NewTypeName='ChattingColorSwatchItem'
    OldGlobalName='dword_69B3FC'; NewGlobalName='g_pfnFillRect'; GlobalAddress='0x69b3fc'
    FrameNames=@('bounds','var_4','__saved_registers','__return_address','index','a3','a4')
    FrameTypes=@('struct RectBounds','_DWORD','_DWORD','_UNKNOWN *','int','int','int *')
    TargetBytesSha256='C9AFE1EFFF38BF2C570E789781598F8EEA90A9CDF51AAF374B97FDC99822CDEB'
    PaddingHex='CCCCCCCCCCCCCCCCCCCCCCCC'
    VtableHex='2034480000000000C0324800'; CallbackHex='0000000000000000'
    VtableValues=@('0x00483420','0x004832c0'); CallbackValues=@('0x00000000','0x00000000')
    XrefDigests=[ordered]@{
        target='C1ACC796488788C9EE5A1FFF7B87E9C5648A1047B9D7F5C7D12578FA7669EF7D'
        rect='968A0ED56DF1BFC9F01B78FD51DA58FDB7D100B7B95B1ACB34B4E6523C9BC9FE'
        selected='E35637BCCE2387F40FE06F994B145A0DCCD482F86FE57414EF9593432A1C2CDB'
        mode='804957363DE8C5B858111A7281D9C44A25A8ED74E8931348CD0E1BA539C62AF5'
        color='88F775E103935E9609CCBB758EDB4FC08E80BF4F26431ECEE7D2CE81A437058C'
        select_cell='94295B5814917B20EDBEE98A230790FD03E3407D89D7755E535295C1C293E30F'
        draw_cell='BDAE63D291A681712A8CA3DE665BD803DDFDE2E88C49BF87C653B44C583098C1'
        callback_neighbor='00052A60C06F15605069E8459985B4F7BD139B4423CE58DFF5D86EEABAC54202'
        fill_callback='FFFFCFE1491C42D0677AAF654A8E5BC19208FCDB46102C6B67AE55E74A406DCC'
    }
}

function ConvertTo-Uid0002GBCanonicalJson($Value) {
    $Value | ConvertTo-Json -Depth 100 -Compress
}
function Get-Uid0002GBTextSha256([string]$Text) {
    $sha=[Security.Cryptography.SHA256]::Create()
    try { (-join($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text))|ForEach-Object{$_.ToString('x2')})).ToUpper() }
    finally { $sha.Dispose() }
}
function Assert-Uid0002GBNativeId($Expected,$Actual,[string]$Label) {
    if($null-eq$Expected -or $null-eq$Actual){throw "RPC_ID_NULL:$Label"}
    if($Expected.GetType().FullName-cne$Actual.GetType().FullName){throw "RPC_ID_NATIVE_TYPE:$Label:$($Expected.GetType().FullName):$($Actual.GetType().FullName)"}
    if($Expected-is[string]){if($Actual-cne$Expected){throw "RPC_ID_NATIVE_VALUE:$Label"}}
    elseif($Actual-ne$Expected){throw "RPC_ID_NATIVE_VALUE:$Label"}
}
function Test-Uid0002GBExactPath([string]$Actual,[string]$Expected,[string]$Label) {
    if([string]::IsNullOrWhiteSpace($Actual)-or[string]::IsNullOrWhiteSpace($Expected)){throw "PATH_EMPTY:$Label"}
    $a=[IO.Path]::GetFullPath($Actual);$e=[IO.Path]::GetFullPath($Expected)
    if(-not$a.Equals($e,[StringComparison]::OrdinalIgnoreCase)){throw "PATH_DRIFT:$Label:$a:$e"}
    $a
}
function Read-Uid0002GBRpcEnvelope([string]$ResponseText,$Request,[switch]$AllowExplicitFailure) {
    try{$rpc=$ResponseText|ConvertFrom-Json -ErrorAction Stop}catch{throw "RPC_JSON_PARSE:$($Request.id)"}
    if($rpc.jsonrpc-cne'2.0'){throw "RPC_VERSION:$($Request.id)"}
    Assert-Uid0002GBNativeId $Request.id $rpc.id ([string]$Request.id)
    if($null-ne$rpc.error){
        if($AllowExplicitFailure){return [ordered]@{Class='EXPLICIT_FAILURE';Rpc=$rpc;Payload=$null;ResponseText=$ResponseText}}
        throw "RPC_ERROR:$($Request.id)"
    }
    if($null-eq$rpc.result){throw "RPC_RESULT_MISSING:$($Request.id)"}
    $content=@($rpc.result.content)
    if($content.Count-ne 1-or$content[0].type-cne'text'-or[string]::IsNullOrWhiteSpace([string]$content[0].text)){throw "RPC_CONTENT_SHAPE:$($Request.id)"}
    try{$payload=$content[0].text|ConvertFrom-Json -ErrorAction Stop}catch{throw "RPC_PAYLOAD_JSON:$($Request.id)"}
    if($null-eq$rpc.result.structuredContent){throw "RPC_STRUCTURED_MISSING:$($Request.id)"}
    if((ConvertTo-Uid0002GBCanonicalJson $payload)-cne(ConvertTo-Uid0002GBCanonicalJson $rpc.result.structuredContent)){throw "RPC_TEXT_STRUCTURED_PARITY:$($Request.id)"}
    if($rpc.result.isError-eq$true){
        if($AllowExplicitFailure){return [ordered]@{Class='EXPLICIT_FAILURE';Rpc=$rpc;Payload=$payload;ResponseText=$ResponseText}}
        throw "RPC_TOOL_FAILURE:$($Request.id)"
    }
    [ordered]@{Class='EXPLICIT_SUCCESS';Rpc=$rpc;Payload=$payload;ResponseText=$ResponseText}
}
function Get-Uid0002GBOpenAuthority([string]$ResponseText,$Request,[string]$ExpectedCanonicalPath) {
    $envelope=Read-Uid0002GBRpcEnvelope $ResponseText $Request
    $root=$envelope.Payload
    $rootNames=@($root.PSObject.Properties.Name|Sort-Object)
    $requiredRoot=@('message','session','success','warmup'|Sort-Object)
    if((ConvertTo-Uid0002GBCanonicalJson $rootNames)-cne(ConvertTo-Uid0002GBCanonicalJson $requiredRoot)-or$root.success-ne$true){throw "OPEN_ROOT_SHAPE:$($Request.id)"}
    $session=$root.session
    $actualNames=@($session.PSObject.Properties.Name|Sort-Object)
    $requiredNames=@('created_at','filename','input_path','is_analyzing','last_accessed','metadata','session_id'|Sort-Object)
    if((ConvertTo-Uid0002GBCanonicalJson $actualNames)-cne(ConvertTo-Uid0002GBCanonicalJson $requiredNames)){throw "OPEN_SESSION_SHAPE:$($Request.id)"}
    if([string]::IsNullOrWhiteSpace([string]$session.session_id)-or$session.session_id.GetType().FullName-cne[string].FullName){throw "OPEN_SESSION_ID:$($Request.id)"}
    $canonical=Test-Uid0002GBExactPath ([string]$session.input_path) $ExpectedCanonicalPath ([string]$Request.id)
    if([string]$session.filename-cne[IO.Path]::GetFileName($canonical)-or$session.is_analyzing-ne$false-or$null-eq$session.metadata){throw "OPEN_SESSION_STATE:$($Request.id)"}
    foreach($stampName in @('created_at','last_accessed')){try{[void][DateTimeOffset]::Parse([string]$session.$stampName,[Globalization.CultureInfo]::InvariantCulture,[Globalization.DateTimeStyles]::RoundtripKind)}catch{throw "OPEN_SESSION_TIME:$($Request.id):$stampName"}}
    [ordered]@{SessionId=[string]$session.session_id;CanonicalPath=$canonical;Session=$session;Envelope=$envelope}
}
function Assert-Uid0002GBRuntimeShape($Payload,[string]$ExpectedSession,[string]$ExpectedCanonicalPath) {
    if([int]$Payload.schema_version-ne 1-or$Payload.ok-ne$true-or@($Payload.errors).Count-ne 0-or$null-eq$Payload.listener){throw 'RUNTIME_TOP'}
    $workers=@($Payload.workers);$matches=@()
    $moduleIds=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach($entry in $workers){
        if($null-eq$entry.attestation-or$entry.attestation.ok-ne$true-or@($entry.attestation.errors).Count-ne 0){throw 'RUNTIME_WORKER'}
        $supervisorSessions=@($entry.supervisor_sessions);$workerSessions=@($entry.attestation.sessions)
        foreach($s in $supervisorSessions){
            $peer=@($workerSessions|Where-Object{[string]$_.session_id-ceq[string]$s.session_id})
            if($peer.Count-ne 1){throw "RUNTIME_SESSION_PARITY:$($s.session_id)"}
            [void](Test-Uid0002GBExactPath ([string]$peer[0].canonical_path) ([string]$s.canonical_path) 'RUNTIME_SESSION')
            if([string]$s.session_id-ceq$ExpectedSession){$matches+=,$s}
        }
        foreach($m in @($entry.attestation.worker.modules)){
            if([string]::IsNullOrWhiteSpace([string]$m.sys_modules_name)-or[string]::IsNullOrWhiteSpace([string]$m.module_id)-or-not$moduleIds.Add([string]$m.module_id)){throw 'RUNTIME_MODULE_DUPLICATE_OR_EMPTY'}
            foreach($p in @('file','spec_origin','resolved_path','sha256','size','mtime_ns','ctime_ns')){if($null-eq$m.$p-or[string]::IsNullOrWhiteSpace([string]$m.$p)){throw "RUNTIME_MODULE_FIELD:$p"}}
        }
    }
    if($matches.Count-ne 1){throw "RUNTIME_EXPECTED_SESSION_COUNT:$($matches.Count)"}
    [void](Test-Uid0002GBExactPath ([string]$matches[0].canonical_path) $ExpectedCanonicalPath 'RUNTIME_EXPECTED_PATH')
    [ordered]@{Receipt='RUNTIME_SHAPE_OK';Workers=$workers.Count;Session=$ExpectedSession;ModuleIds=$moduleIds.Count}
}
function Assert-Uid0002GBSchemaSurface($Tools,[hashtable]$ExpectedDigests) {
    foreach($name in $ExpectedDigests.Keys){
        $rows=@($Tools|Where-Object name -ceq $name)
        if($rows.Count-ne 1){throw "SCHEMA_TOOL_COUNT:$name:$($rows.Count)"}
        $digest=Get-Uid0002GBTextSha256 (ConvertTo-Uid0002GBCanonicalJson $rows[0].inputSchema)
        if($digest-cne$ExpectedDigests[$name]){throw "SCHEMA_DIGEST:$name:$digest"}
    }
    [ordered]@{Receipt='SCHEMA_SURFACE_OK';Count=$ExpectedDigests.Count}
}
function Get-Uid0002GBLiteralCatalog([string]$ReportPath) {
    $map=[ordered]@{};$raw=[ordered]@{};$physical=0
    foreach($line in Get-Content -LiteralPath $ReportPath -ErrorAction Stop){
        if($line-notmatch'^\{"jsonrpc":"2\.0","id":'){continue}
        $physical++
        try{$request=$line|ConvertFrom-Json -ErrorAction Stop}catch{throw "CATALOG_JSON:$physical"}
        if($request.id.GetType().FullName-cne[string].FullName-or[string]::IsNullOrWhiteSpace([string]$request.id)){throw "CATALOG_ID_TYPE:$physical"}
        $id=[string]$request.id;$compact=ConvertTo-Uid0002GBCanonicalJson $request
        if($map.Contains($id)){if($id-cne'A10-SAVE-ONCE'-or$raw[$id]-cne$compact){throw "CATALOG_DUPLICATE:$id"};continue}
        $map[$id]=$request;$raw[$id]=$compact
    }
    if($physical-ne 108-or$map.Count-ne 107){throw "CATALOG_CARDINALITY:$physical:$($map.Count)"}
    [ordered]@{Requests=$map;Raw=$raw;Physical=$physical;Unique=$map.Count}
}
function Assert-Uid0002GBControllerCoverage($Catalog) {
    $all=@($script:Uid0002GBCommonOrder+$script:Uid0002GBVerifierOrder+$script:Uid0002GBRollbackOrder)
    $seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach($id in $all){if(-not$seen.Add($id)){throw "PLAN_DUPLICATE:$id"};if(-not$Catalog.Requests.Contains($id)){throw "PLAN_MISSING_LITERAL:$id"}}
    foreach($id in $Catalog.Requests.Keys){if(-not$seen.Contains([string]$id)){throw "PLAN_UNREACHABLE_LITERAL:$id"}}
    if($all.Count-ne 107-or$script:Uid0002GBCommonOrder.Count-ne 81-or$script:Uid0002GBVerifierOrder.Count-ne 13-or$script:Uid0002GBRollbackOrder.Count-ne 13){throw "PLAN_CARDINALITY:$($all.Count)"}
    [ordered]@{Receipt='CONTROLLER_COVERAGE_OK';Materialized=107;Mapped=107;Common=81;Verifier=13;Rollback=13}
}
function Resolve-Uid0002GBControllerRequest($Template,[hashtable]$Bindings) {
    $text=ConvertTo-Uid0002GBCanonicalJson $Template
    foreach($role in @('TX','V','RB')){
        $needle='"<'+$role+'>"'
        if($text.Contains($needle)){
            if(-not$Bindings.ContainsKey($role)-or[string]::IsNullOrWhiteSpace([string]$Bindings[$role])){throw "REQUEST_BINDING_MISSING:$role"}
            $text=$text.Replace($needle,(ConvertTo-Uid0002GBCanonicalJson ([string]$Bindings[$role])))
        }
    }
    if($text-match'"<(TX|V|RB)>"'){throw 'REQUEST_BINDING_REMAINS'}
    $text|ConvertFrom-Json -ErrorAction Stop
}
function Get-Uid0002GBBoundArgumentHash($Arguments,[string]$Role,[hashtable]$Bindings) {
    $clone=(ConvertTo-Uid0002GBCanonicalJson $Arguments)|ConvertFrom-Json
    foreach($property in @('database','expected_database')){
        if($clone.PSObject.Properties.Name-contains$property){
            if([string]::IsNullOrWhiteSpace($Role)-or-not$Bindings.ContainsKey($Role)){throw "ARGUMENT_ROLE_MISSING:$property"}
            $actual=$clone.$property;$expected=[string]$Bindings[$Role]
            if($actual.GetType().FullName-cne[string].FullName-or$actual-cne$expected){throw "ARGUMENT_DATABASE_BINDING:$property:$Role"}
            $clone.$property="<$Role>"
        }
    }
    Get-Uid0002GBTextSha256 (ConvertTo-Uid0002GBCanonicalJson $clone)
}
function Write-Uid0002GBDurableJsonLine([string]$Path,$Value) {
    $directory=Split-Path -Parent $Path
    if(-not(Test-Path -LiteralPath $directory)){[void][IO.Directory]::CreateDirectory($directory)}
    $line=(ConvertTo-Uid0002GBCanonicalJson $Value)+"`n";$bytes=[Text.UTF8Encoding]::new($false).GetBytes($line)
    $stream=[IO.File]::Open($Path,[IO.FileMode]::OpenOrCreate,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
    try{$before=$stream.Length;$stream.Position=$before;$offset=0;while($offset-lt$bytes.Length){$n=[Math]::Min(65536,$bytes.Length-$offset);$stream.Write($bytes,$offset,$n);$offset+=$n};$stream.Flush($true);if($stream.Length-ne$before+$bytes.Length){throw 'JOURNAL_COUNTED_APPEND'}}finally{$stream.Dispose()}
    foreach($row in Get-Content -LiteralPath $Path){[void]($row|ConvertFrom-Json -ErrorAction Stop)}
}
function Get-Uid0002GBSaveGuardPath([string]$CanonicalPath,[string]$OverrideRoot='') {
    $root=if([string]::IsNullOrWhiteSpace($OverrideRoot)){Join-Path $env:ProgramData 'NexusTK-Gate2B-Irreversible'}else{$OverrideRoot}
    $canonical=[IO.Path]::GetFullPath($CanonicalPath).ToUpperInvariant()
    Join-Path (Join-Path $root 'UID0002GB') ((Get-Uid0002GBTextSha256 $canonical)+'.save-attempt.json')
}
function Set-Uid0002GBIrreversibleSaveAttempt([string]$CanonicalPath,$Request,[string]$OverrideRoot='') {
    $path=Get-Uid0002GBSaveGuardPath $CanonicalPath $OverrideRoot
    $directory=Split-Path -Parent $path;if(-not(Test-Path -LiteralPath $directory)){[void][IO.Directory]::CreateDirectory($directory)}
    $record=[ordered]@{uid='0002GB';canonical_path=[IO.Path]::GetFullPath($CanonicalPath);request_id=[string]$Request.id;request_sha256=Get-Uid0002GBTextSha256 (ConvertTo-Uid0002GBCanonicalJson $Request);state='SAVE_ATTEMPT_RECORDED_BEFORE_TRANSPORT'}
    $bytes=[Text.UTF8Encoding]::new($false).GetBytes(ConvertTo-Uid0002GBCanonicalJson $record)
    try{$stream=[IO.File]::Open($path,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None)}catch{throw "SAVE_ATTEMPT_ALREADY_EXISTS:$path"}
    try{$stream.Write($bytes,0,$bytes.Length);$stream.Flush($true);if($stream.Length-ne$bytes.Length){throw 'SAVE_GUARD_WRITE'}}finally{$stream.Dispose()}
    $readback=Get-Content -Raw -LiteralPath $path|ConvertFrom-Json -ErrorAction Stop
    if((ConvertTo-Uid0002GBCanonicalJson $readback)-cne(ConvertTo-Uid0002GBCanonicalJson $record)){throw 'SAVE_GUARD_READBACK'}
    [ordered]@{Path=$path;Record=$record}
}
function Invoke-Uid0002GBControllerDispatch($Context,[string]$Id,[string]$Role='') {
    if(-not$Context.Catalog.Requests.Contains($Id)){throw "DISPATCH_UNKNOWN:$Id"}
    if(-not$Context.Dispatched.Add($Id)){throw "DISPATCH_DUPLICATE:$Id"}
    $request=Resolve-Uid0002GBControllerRequest $Context.Catalog.Requests[$Id] $Context.Bindings
    $requestText=ConvertTo-Uid0002GBCanonicalJson $request
    $tool=if($request.method-ceq'tools/call'){[string]$request.params.name}else{[string]$request.method}
    $argumentHash=if($request.method-ceq'tools/call'){Get-Uid0002GBBoundArgumentHash $request.params.arguments $Role $Context.Bindings}else{Get-Uid0002GBTextSha256 (ConvertTo-Uid0002GBCanonicalJson $request.params)}
    Write-Uid0002GBDurableJsonLine $Context.AttemptJournal ([ordered]@{sequence=$Context.Dispatched.Count-1;id=$Id;tool=$tool;argument_sha256=$argumentHash;request_sha256=Get-Uid0002GBTextSha256 $requestText;state='DISPATCH_INTENT'})
    $saveGuard=$null
    if($tool-ceq'idb_save'){$saveGuard=Set-Uid0002GBIrreversibleSaveAttempt $Context.CanonicalPath $request $Context.SaveGuardRoot}
    $responseText=$null;$transportError=$null
    try{$responseText=[string](& $Context.Transport $requestText $request)}catch{$transportError=$_.Exception.Message}
    $classification='INDETERMINATE';$envelope=$null
    if($null-eq$transportError){
        try{$envelope=Read-Uid0002GBRpcEnvelope $responseText $request -AllowExplicitFailure;$classification=$envelope.Class}catch{$transportError=$_.Exception.Message}
    }
    Write-Uid0002GBDurableJsonLine $Context.ResponseJournal ([ordered]@{sequence=$Context.Dispatched.Count-1;id=$Id;tool=$tool;response_text=$responseText;transport_error=$transportError;class=$classification;save_guard=if($saveGuard){$saveGuard.Path}else{$null}})
    $receipt=[ordered]@{Id=$Id;Role=$Role;Tool=$tool;Request=$request;RequestText=$requestText;ResponseText=$responseText;Envelope=$envelope;Class=$classification;TransportError=$transportError;SaveGuard=$saveGuard}
    $Context.Responses[$Id]=$receipt
    if($tool-cne'idb_save'-and$classification-cne'EXPLICIT_SUCCESS'){throw "DISPATCH_FAILED:$Id:$transportError"}
    if($null-ne$Context.AssertImmediate){& $Context.AssertImmediate $receipt $Context}
    $receipt
}
function Assert-Uid0002GBReportOwnedPrestate($Context) {
    foreach($id in @('I01','I02','I03','I04','I05','I06','I07','I08','I09')){if(-not$Context.Responses.Contains($id)){throw "PRESTATE_MISSING:$id"}}
    $i01=$Context.Responses['I01'].Envelope.Payload;$types=@($i01.result)
    if($types.Count-ne 4-or$types[0].name-cne$script:Uid0002GBImmutablePrestate.NewTypeName-or$types[0].exists-ne$false){throw 'PRESTATE_I01_NEW_TYPE'}
    if((@($types|ForEach-Object{[string]$_.name})[1..3]|ConvertTo-Json -Compress)-cne(@('RectBounds','ChattingColorListPane','SurfaceFillRectProc')|ConvertTo-Json -Compress)){throw 'PRESTATE_I01_PROTECTED_TYPES'}
    $i02=@($Context.Responses['I02'].Envelope.Payload.result)
    if($i02.Count-ne 7-or$i02[0].fn.name-cne$script:Uid0002GBImmutablePrestate.TargetName-or$i02[0].fn.addr-cne'0x4832c0'-or$i02[0].fn.size-cne$script:Uid0002GBImmutablePrestate.TargetSize-or$null-ne$i02[1].fn){throw 'PRESTATE_I02_FUNCTIONS'}
    $i03=@($Context.Responses['I03'].Envelope.Payload.result);$old=@($i03[0].data);$new=@($i03[1].data)
    if($old.Count-ne 1-or$old[0].addr-cne$script:Uid0002GBImmutablePrestate.GlobalAddress-or$old[0].name-cne$script:Uid0002GBImmutablePrestate.OldGlobalName-or$new.Count-ne 0){throw 'PRESTATE_I03_NAMES'}
    $frame=@($Context.Responses['I04'].Envelope.Payload.result);if($frame.Count-ne 1){throw 'PRESTATE_I04_COUNT'}
    if((@($frame[0].vars|ForEach-Object{[string]$_.name})|ConvertTo-Json -Compress)-cne($script:Uid0002GBImmutablePrestate.FrameNames|ConvertTo-Json -Compress)-or(@($frame[0].vars|ForEach-Object{[string]$_.type})|ConvertTo-Json -Compress)-cne($script:Uid0002GBImmutablePrestate.FrameTypes|ConvertTo-Json -Compress)){throw 'PRESTATE_I04_FRAME'}
    $comments=@($Context.Responses['I05'].Envelope.Payload.result)
    foreach($address in @('0x004832c0','0x00483414','0x00615228','0x0069b3fc')){$row=@($comments|Where-Object addr -ceq$address);if($row.Count-ne 1){throw "PRESTATE_I05_ROW:$address"};foreach($channel in @('regular','repeatable','function_regular','function_repeatable')){if($row[0].PSObject.Properties.Name-contains$channel){if(-not[string]::IsNullOrEmpty([string]$row[0].$channel)){throw "PRESTATE_I05_COMMENT:$address:$channel"}}}}
    $items=@($Context.Responses['I06'].Envelope.Payload.result)
    foreach($pair in @(@('0x004832c0','0x483414'),@('0x00483414','0x483420'),@('0x00483420','0x483487'),@('0x00615220','0x615224'),@('0x00615228','0x61522c'),@('0x0069b3f8','0x69b3f9'),@('0x0069b3fc','0x69b3fd'))){$row=@($items|Where-Object addr -ceq$pair[0]);if($row.Count-ne 1-or[string]$row[0].end-cne$pair[1]){throw "PRESTATE_I06_ITEM:$($pair[0])"}}
    $bytes=@($Context.Responses['I07'].Envelope.Payload.result)
    if($bytes.Count-ne 4){throw 'PRESTATE_I07_COUNT'}
    $target=@($bytes|Where-Object addr -ceq'0x004832c0');if($target.Count-ne 1-or(Get-Uid0002GBTextSha256 ([string]$target[0].data)-cne$script:Uid0002GBImmutablePrestate.TargetBytesSha256){throw 'PRESTATE_I07_TARGET_BYTES'}
    $globals=@($Context.Responses['I08'].Envelope.Payload.result);if($globals.Count-ne 4){throw 'PRESTATE_I08_COUNT'}
    if($null-eq$Context.AssertXrefs){throw 'PRESTATE_XREF_ASSERTION_MISSING'}
    & $Context.AssertXrefs 'I' $Context.Bindings.TX $Context
    $Context.PrestateComplete=$true
    [ordered]@{Receipt='IMMUTABLE_PRESTATE_OK';Rows=9;BeforeA01=$true}
}
function Assert-Uid0002GBImmediateResponse($Receipt,$Context) {
    $id=[string]$Receipt.Id
    if($id-ceq'A01'-and-not$Context.PrestateComplete){throw 'A01_BEFORE_COMPLETE_PRESTATE'}
    if($id-like'D*'){
        if($Receipt.Envelope.Payload.success-ne$true-or@($Receipt.Envelope.Payload.failed).Count-ne 0){throw "DRY_RUN_SEMANTICS:$id"}
    }
    if($id-like'A*'-and$id-cne'A10-SAVE-ONCE'){
        if($Receipt.Envelope.Payload.PSObject.Properties.Name-contains'success'){if($Receipt.Envelope.Payload.success-ne$true){throw "MUTATION_SEMANTICS:$id"}}
        if($Receipt.Envelope.Payload.PSObject.Properties.Name-contains'failed'){if(@($Receipt.Envelope.Payload.failed).Count-ne 0){throw "MUTATION_FAILURES:$id"}}
    }
    if($id-ceq'I09'){[void](Assert-Uid0002GBReportOwnedPrestate $Context)}
    if($id-like'J07*'){if($id-ceq'J07E'){& $Context.AssertXrefs 'J07' $Context.Bindings.TX $Context}}
    elseif($id-like'J08-CB*'){if($id-ceq'J08-CBD'){& $Context.AssertXrefs 'J08-CB' $Context.Bindings.TX $Context}}
    elseif($id-like'J08-VTABLE*'){if($id-ceq'J08-VTABLED'){& $Context.AssertXrefs 'J08-VTABLE' $Context.Bindings.TX $Context}}
    elseif($id-like'J09*'){if($id-ceq'J09D'){& $Context.AssertXrefs 'J09' $Context.Bindings.TX $Context}}
    elseif($id-ceq'F09'){& $Context.AssertXrefs 'F' $Context.Bindings.TX $Context}
    elseif($id-ceq'R09'){& $Context.AssertXrefs 'R' $Context.Bindings.V $Context}
    elseif($id-ceq'RB09'){& $Context.AssertXrefs 'RB' $Context.Bindings.RB $Context}
    if($id-match'^R(0[1-9])$'){$source='F'+$Matches[1];if((ConvertTo-Uid0002GBCanonicalJson $Receipt.Envelope.Payload)-cne(ConvertTo-Uid0002GBCanonicalJson $Context.Responses[$source].Envelope.Payload)){throw "R_TO_F_MISMATCH:$id:$source"}}
    if($id-match'^RB(0[1-9])$'){$source='I'+$Matches[1];if((ConvertTo-Uid0002GBCanonicalJson $Receipt.Envelope.Payload)-cne(ConvertTo-Uid0002GBCanonicalJson $Context.Responses[$source].Envelope.Payload)){throw "RB_TO_I_MISMATCH:$id:$source"}}
    if($id-like'J*'-or$id-like'F*'){
        if($null-eq$Context.AssertObjectSet){throw "OBJECT_SET_ASSERTION_MISSING:$id"}
        & $Context.AssertObjectSet $id $Receipt.Envelope.Payload $Context
    }
}
function Assert-Uid0002GBExactDispatchOrder($Context,[string[]]$Expected) {
    $actual=@($Context.DispatchedOrder)
    if((ConvertTo-Uid0002GBCanonicalJson $actual)-cne(ConvertTo-Uid0002GBCanonicalJson $Expected)){throw 'DISPATCH_ORDER'}
    [ordered]@{Receipt='DISPATCH_ORDER_OK';Count=$actual.Count}
}
function Invoke-Uid0002GBRetireRole($Role,$RoleOps,[string]$Label) {
    if($null-eq$Role){return [ordered]@{Receipt="${Label}_NOT_OPEN"}}
    foreach($generation in @('W1','W0')){
        $tuple=$Role.$generation;if($null-eq$tuple){& $RoleOps.StopExact $tuple $generation $Label;if(-not(& $RoleOps.IsAbsent $tuple $generation $Label)){throw "ROLE_LINGERING:${Label}:$generation"}}
    }
    if(-not(& $RoleOps.SessionAbsent ([string]$Role.SessionId) $Label)){throw "SESSION_LINGERING:$Label"}
    [ordered]@{Receipt="${Label}_RETIRED";Session=[string]$Role.SessionId;W1=$true;W0=$true}
}
function Get-Uid0002GBBranchDecision([string]$SaveClass,[string]$DiskClass,[bool]$VerifierOk=$true) {
    if($SaveClass-notin@('EXPLICIT_SUCCESS','EXPLICIT_FAILURE','INDETERMINATE')){throw "SAVE_CLASS:$SaveClass"}
    if($DiskClass-ceq'THIRD_IDENTITY'){return 'REFUSE_THIRD_IDENTITY'}
    if($DiskClass-ceq'P0'){
        if($SaveClass-ceq'EXPLICIT_SUCCESS'){return 'INCONSISTENT_SUCCESS_WITH_P0'}
        return 'NO_COPY_P0_FAILURE'
    }
    if($DiskClass-cne'ATTRIBUTABLE_P1'){throw "DISK_CLASS:$DiskClass"}
    if($VerifierOk){'VERIFY_ATTRIBUTABLE_P1'}else{'RESTORE_AND_ROLLBACK_VERIFY'}
}
function Get-Uid0002GBFileTuple([string]$Path) {
    $tuples=@()
    for($pass=0;$pass-lt 2;$pass++){
        $stream=[IO.File]::Open($Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
        try{$sha=[Security.Cryptography.SHA256]::Create();try{$hash=(-join($sha.ComputeHash($stream)|ForEach-Object{$_.ToString('x2')})).ToUpper()}finally{$sha.Dispose()};$tuples+=,[ordered]@{Path=[IO.Path]::GetFullPath($Path);Sha256=$hash;Size=[long]$stream.Length;LastWriteUtcTicks=[long][IO.File]::GetLastWriteTimeUtc($Path).Ticks}}finally{$stream.Dispose()}
    }
    if((ConvertTo-Uid0002GBCanonicalJson $tuples[0])-cne(ConvertTo-Uid0002GBCanonicalJson $tuples[1])){throw "FILE_TUPLE_REOPEN_DRIFT:$Path"}
    $tuples[1]
}
function Copy-Uid0002GBCounted([IO.FileStream]$Source,[IO.FileStream]$Destination) {
    $buffer=New-Object byte[] 1048576;$count=0L
    while(($read=$Source.Read($buffer,0,$buffer.Length))-gt 0){$Destination.Write($buffer,0,$read);$count+=$read}
    if($count-ne$Source.Length-or$Source.Position-ne$Source.Length-or$Source.ReadByte()-ne-1){throw 'COPY_SOURCE_COUNT_OR_EOF'}
    $Destination.SetLength($count);$Destination.Flush($true)
    if($Destination.Position-ne$count-or$Destination.Length-ne$count){throw 'COPY_DESTINATION_COUNT'}
    $count
}
function New-Uid0002GBExactBackup([string]$CanonicalPath,[string]$BackupPath) {
    if(Test-Path -LiteralPath $BackupPath){throw 'B0_ALREADY_EXISTS'}
    $p0=Get-Uid0002GBFileTuple $CanonicalPath
    $source=[IO.File]::Open($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
    try{$destination=[IO.File]::Open($BackupPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);try{[void](Copy-Uid0002GBCounted $source $destination)}finally{$destination.Dispose()}}finally{$source.Dispose()}
    [IO.File]::SetLastWriteTimeUtc($BackupPath,[DateTime]::new([long]$p0.LastWriteUtcTicks,[DateTimeKind]::Utc))
    $b0=Get-Uid0002GBFileTuple $BackupPath;$p0Again=Get-Uid0002GBFileTuple $CanonicalPath
    if((ConvertTo-Uid0002GBCanonicalJson $p0)-cne(ConvertTo-Uid0002GBCanonicalJson $p0Again)-or$b0.Sha256-cne$p0.Sha256-or$b0.Size-ne$p0.Size-or$b0.LastWriteUtcTicks-ne$p0.LastWriteUtcTicks){throw 'P0_B0_TUPLE'}
    [ordered]@{P0=$p0;B0=$b0}
}
function Assert-Uid0002GBExactBackup($BackupReceipt) {
    $actual=Get-Uid0002GBFileTuple ([string]$BackupReceipt.B0.Path)
    if((ConvertTo-Uid0002GBCanonicalJson $actual)-cne(ConvertTo-Uid0002GBCanonicalJson $BackupReceipt.B0)){throw 'B0_CORRUPT'}
    $actual
}
function Get-Uid0002GBDiskClass([string]$CanonicalPath,$P0,$Attribution) {
    $current=Get-Uid0002GBFileTuple $CanonicalPath
    if((ConvertTo-Uid0002GBCanonicalJson $current)-ceq(ConvertTo-Uid0002GBCanonicalJson $P0)){return [ordered]@{Class='P0';Tuple=$current}}
    if($Attribution.SaveAttemptRecorded-ne$true-or$Attribution.SaveAttempts-ne 1-or$Attribution.CanonicalPath-cne[IO.Path]::GetFullPath($CanonicalPath)-or$Attribution.RolesRetired-ne$true-or$Attribution.NoOtherCanonicalSessions-ne$true){return [ordered]@{Class='THIRD_IDENTITY';Tuple=$current}}
    [ordered]@{Class='ATTRIBUTABLE_P1';Tuple=$current}
}
function Restore-Uid0002GBExactBackup([string]$CanonicalPath,$P0,$B0,$FailureTuple) {
    $current=Get-Uid0002GBFileTuple $CanonicalPath;$backup=Get-Uid0002GBFileTuple ([string]$B0.Path)
    if((ConvertTo-Uid0002GBCanonicalJson $current)-cne(ConvertTo-Uid0002GBCanonicalJson $FailureTuple)){throw 'RESTORE_THIRD_IDENTITY'}
    if((ConvertTo-Uid0002GBCanonicalJson $backup)-cne(ConvertTo-Uid0002GBCanonicalJson $B0)-or$backup.Sha256-cne$P0.Sha256-or$backup.Size-ne$P0.Size-or$backup.LastWriteUtcTicks-ne$P0.LastWriteUtcTicks){throw 'RESTORE_B0_CORRUPT'}
    $source=[IO.File]::Open([string]$B0.Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
    try{$destination=[IO.File]::Open($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);try{$destination.SetLength(0);[void](Copy-Uid0002GBCounted $source $destination)}finally{$destination.Dispose()}}finally{$source.Dispose()}
    [IO.File]::SetLastWriteTimeUtc($CanonicalPath,[DateTime]::new([long]$P0.LastWriteUtcTicks,[DateTimeKind]::Utc))
    $restored=Get-Uid0002GBFileTuple $CanonicalPath
    if((ConvertTo-Uid0002GBCanonicalJson $restored)-cne(ConvertTo-Uid0002GBCanonicalJson $P0)){throw 'RESTORE_P0_MISMATCH'}
    [ordered]@{Receipt='RESTORE_P0_OK';Tuple=$restored}
}
function Invoke-Uid0002GBOrderedPhase($Context,[string[]]$Order,[string]$Role) {
    foreach($id in $Order){
        $receipt=Invoke-Uid0002GBControllerDispatch $Context $id $Role
        $Context.DispatchedOrder.Add($id)
        if($id-in@('O01','O02','O03')){
            $authority=Get-Uid0002GBOpenAuthority $receipt.ResponseText $receipt.Request $Context.CanonicalPath
            $boundRole=switch($id){'O01'{'TX'};'O02'{'V'};'O03'{'RB'}}
            $Context.Bindings[$boundRole]=$authority.SessionId
            $Context.Roles[$boundRole]=& $Context.BindRole $boundRole $authority $Context
        }
    }
}
function Invoke-Uid0002GBAuthoritativeController($Context) {
    $Context.Catalog=Get-Uid0002GBLiteralCatalog $Context.ReportPath
    $Context.CoverageReceipt=Assert-Uid0002GBControllerCoverage $Context.Catalog
    $Context.Dispatched=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    $Context.DispatchedOrder=[Collections.Generic.List[string]]::new()
    $Context.Responses=[ordered]@{};$Context.Bindings=@{};$Context.Roles=@{};$Context.PrestateComplete=$false
    $Context.AssertImmediate=${function:Assert-Uid0002GBImmediateResponse}
    $backup=& $Context.CreateBackup $Context
    $saveReceipt=$null;$diskReceipt=$null;$verifierFailure=$null;$rollbackOrigin=$null
    try{
        try{Invoke-Uid0002GBOrderedPhase $Context $script:Uid0002GBCommonOrder 'TX';$saveReceipt=$Context.Responses['A10-SAVE-ONCE']}
        finally{if($Context.Roles.Contains('TX')){[void](Invoke-Uid0002GBRetireRole $Context.Roles.TX $Context.RoleOps 'TX');$Context.Roles.Remove('TX')}}
        if(-not(& $Context.AssertNoCanonical $Context)){throw 'POST_TX_CANONICAL_SESSION'}
        $diskReceipt=& $Context.ClassifyDisk $backup $saveReceipt $Context
        $decision=Get-Uid0002GBBranchDecision $saveReceipt.Class $diskReceipt.Class $true
        switch($decision){
            'NO_COPY_P0_FAILURE'{return [ordered]@{Receipt='GATE2B_NOT_PERSISTED';SaveClass=$saveReceipt.Class;DiskClass=$diskReceipt.Class;Backup=$backup}}
            'INCONSISTENT_SUCCESS_WITH_P0'{throw 'SAVE_SUCCESS_BUT_DISK_P0'}
            'REFUSE_THIRD_IDENTITY'{throw 'DISK_THIRD_IDENTITY_REFUSAL'}
            'VERIFY_ATTRIBUTABLE_P1'{
                try{Invoke-Uid0002GBOrderedPhase $Context $script:Uid0002GBVerifierOrder 'V';& $Context.VerifyP1 $backup $diskReceipt $Context}
                catch{$verifierFailure=$_;$rollbackOrigin='VERIFIER_FAILURE'}
                finally{if($Context.Roles.Contains('V')){[void](Invoke-Uid0002GBRetireRole $Context.Roles.V $Context.RoleOps 'V');$Context.Roles.Remove('V')}}
                if($null-eq$verifierFailure){if(-not(& $Context.AssertNoCanonical $Context)){throw 'POST_V_CANONICAL_SESSION'};return [ordered]@{Receipt='GATE2B_P1_VERIFIED';SaveClass=$saveReceipt.Class;DiskClass=$diskReceipt.Class;Backup=$backup}}
                [void](& $Context.Restore $backup $diskReceipt $rollbackOrigin $Context)
                try{Invoke-Uid0002GBOrderedPhase $Context $script:Uid0002GBRollbackOrder 'RB';& $Context.VerifyP0 $backup $Context}
                finally{if($Context.Roles.Contains('RB')){[void](Invoke-Uid0002GBRetireRole $Context.Roles.RB $Context.RoleOps 'RB');$Context.Roles.Remove('RB')}}
                if(-not(& $Context.AssertNoCanonical $Context)){throw 'POST_RB_CANONICAL_SESSION'}
                throw "VERIFIER_FAILED_RESTORED:$($verifierFailure.Exception.Message)"
            }
            default{throw "UNREACHABLE_BRANCH:$decision"}
        }
    }finally{
        foreach($role in @('RB','V','TX')){if($Context.Roles.Contains($role)){try{[void](Invoke-Uid0002GBRetireRole $Context.Roles[$role] $Context.RoleOps $role)}finally{$Context.Roles.Remove($role)}}}
        if($null-ne$Context.AssertNoCanonical-and-not(& $Context.AssertNoCanonical $Context)){throw 'OUTER_FINALLY_CANONICAL_SESSION'}
    }
}
function Invoke-Uid0002GBHostileFixtures([string]$ReportPath) {
    $results=[Collections.Generic.List[object]]::new()
    function Add-Rejection([string]$Name,[string]$Token,[scriptblock]$Action){try{&$Action;$results.Add([ordered]@{Fixture=$Name;Result='FAIL_NO_REJECTION';Token=$Token})}catch{$ok=$_.Exception.Message-like("*"+$Token+"*");$results.Add([ordered]@{Fixture=$Name;Result=if($ok){'PASS'}else{'FAIL_WRONG_REJECTION'};Token=$Token;Observed=$_.Exception.Message})}}
    function New-Response($Id,$Payload){$text=ConvertTo-Uid0002GBCanonicalJson $Payload;$rpc=[ordered]@{jsonrpc='2.0';result=[ordered]@{content=@([ordered]@{type='text';text=$text});isError=$false;structuredContent=$Payload};id=$Id};ConvertTo-Uid0002GBCanonicalJson $rpc}
    $request=[ordered]@{jsonrpc='2.0';id='FIX-ID';method='tools/call';params=[ordered]@{name='idb_list';arguments=[ordered]@{}}}
    Add-Rejection 'native-id-type' 'RPC_ID_NATIVE_TYPE' { [void](Read-Uid0002GBRpcEnvelope (New-Response @('FIX-ID') ([ordered]@{ok=$true})) $request) }
    Add-Rejection 'native-id-value' 'RPC_ID_NATIVE_VALUE' { [void](Read-Uid0002GBRpcEnvelope (New-Response 'FIX-OTHER' ([ordered]@{ok=$true})) $request) }
    $schema=[ordered]@{type='object';properties=[ordered]@{};required=@();additionalProperties=$false};$schemaDigest=Get-Uid0002GBTextSha256 (ConvertTo-Uid0002GBCanonicalJson $schema)
    Add-Rejection 'schema-drift' 'SCHEMA_DIGEST' { [void](Assert-Uid0002GBSchemaSurface @([ordered]@{name='x';inputSchema=[ordered]@{type='object'}}) @{x=$schemaDigest}) }
    $session=[ordered]@{session_id='returned-session';input_path='E:\wrong\other.i64';filename='other.i64';created_at='2026-08-06T00:00:00Z';last_accessed='2026-08-06T00:00:01Z';is_analyzing=$false;metadata=[ordered]@{}}
    $openPayload=[ordered]@{success=$true;session=$session;warmup=$null;message='opened'};$openRequest=[ordered]@{jsonrpc='2.0';id='O01';method='tools/call';params=[ordered]@{name='idb_open';arguments=[ordered]@{}}}
    Add-Rejection 'open-path-drift' 'PATH_DRIFT' { [void](Get-Uid0002GBOpenAuthority (New-Response 'O01' $openPayload) $openRequest $script:Uid0002GBCanonicalPath) }
    $runtime=[ordered]@{schema_version=1;ok=$true;errors=@();listener=[ordered]@{ok=$true};workers=@()}
    Add-Rejection 'runtime-missing-session' 'RUNTIME_EXPECTED_SESSION_COUNT' { [void](Assert-Uid0002GBRuntimeShape $runtime 'returned-session' $script:Uid0002GBCanonicalPath) }
    $module=[ordered]@{sys_modules_name='m';module_id='same';file='f';spec_origin='f';resolved_path='f';sha256='a';size=1;mtime_ns='1';ctime_ns='1'}
    $workerSession=[ordered]@{session_id='returned-session';canonical_path=$script:Uid0002GBCanonicalPath};$attestedSession=[ordered]@{session_id='returned-session';canonical_path=$script:Uid0002GBCanonicalPath}
    $runtime.workers=@([ordered]@{supervisor_sessions=@($workerSession);attestation=[ordered]@{ok=$true;errors=@();sessions=@($attestedSession);worker=[ordered]@{modules=@($module,$module)}}})
    Add-Rejection 'runtime-duplicate-module' 'RUNTIME_MODULE_DUPLICATE_OR_EMPTY' { [void](Assert-Uid0002GBRuntimeShape $runtime 'returned-session' $script:Uid0002GBCanonicalPath) }
    $catalog=Get-Uid0002GBLiteralCatalog $ReportPath
    $saved=$catalog.Requests['RB09'];$catalog.Requests.Remove('RB09')
    Add-Rejection 'controller-skipped-row' 'PLAN_MISSING_LITERAL' { [void](Assert-Uid0002GBControllerCoverage $catalog) }
    $catalog.Requests['RB09']=$saved
    $old=$script:Uid0002GBRollbackOrder;$script:Uid0002GBRollbackOrder=@($old+'RB09')
    Add-Rejection 'controller-duplicate-row' 'PLAN_DUPLICATE' { [void](Assert-Uid0002GBControllerCoverage $catalog) }
    $script:Uid0002GBRollbackOrder=$old
    $temp=Join-Path ([IO.Path]::GetTempPath()) ('uid0002gb-fixtures-'+[Guid]::NewGuid().ToString('N'));[void][IO.Directory]::CreateDirectory($temp)
    try{
        $canonical=Join-Path $temp 'canonical.i64';[IO.File]::WriteAllText($canonical,'P0-CONTENT',[Text.UTF8Encoding]::new($false))
        $saveRequest=[ordered]@{jsonrpc='2.0';id='A10-SAVE-ONCE';method='tools/call';params=[ordered]@{name='idb_save';arguments=[ordered]@{database='tx'}}}
        [void](Set-Uid0002GBIrreversibleSaveAttempt $canonical $saveRequest $temp)
        Add-Rejection 'duplicate-save' 'SAVE_ATTEMPT_ALREADY_EXISTS' { [void](Set-Uid0002GBIrreversibleSaveAttempt $canonical $saveRequest $temp) }
        $alternate=[ordered]@{jsonrpc='2.0';id='DIFFERENT-ID';method='tools/call';params=[ordered]@{name='idb_save';arguments=[ordered]@{database='other'}}}
        Add-Rejection 'restart-alternate-save' 'SAVE_ATTEMPT_ALREADY_EXISTS' { [void](Set-Uid0002GBIrreversibleSaveAttempt $canonical $alternate $temp) }
        $backupPath=Join-Path $temp 'backup.i64';$backupReceipt=New-Uid0002GBExactBackup $canonical $backupPath
        [IO.File]::AppendAllText($backupPath,'CORRUPT')
        Add-Rejection 'corrupt-b0' 'B0_CORRUPT' { [void](Assert-Uid0002GBExactBackup $backupReceipt) }
        [IO.File]::WriteAllText($backupPath,'P0-CONTENT',[Text.UTF8Encoding]::new($false));[IO.File]::SetLastWriteTimeUtc($backupPath,[DateTime]::new([long]$backupReceipt.P0.LastWriteUtcTicks,[DateTimeKind]::Utc))
        [IO.File]::WriteAllText($canonical,'THIRD-IDENTITY',[Text.UTF8Encoding]::new($false));$third=Get-Uid0002GBFileTuple $canonical
        Add-Rejection 'third-identity-restore' 'RESTORE_THIRD_IDENTITY' { [void](Restore-Uid0002GBExactBackup $canonical $backupReceipt.P0 $backupReceipt.B0 ([ordered]@{Path=$third.Path;Sha256='NOT-'+$third.Sha256;Size=$third.Size;LastWriteUtcTicks=$third.LastWriteUtcTicks})) }
        $disk=Get-Uid0002GBDiskClass $canonical $backupReceipt.P0 ([ordered]@{SaveAttemptRecorded=$false;SaveAttempts=0;CanonicalPath=$canonical;RolesRetired=$true;NoOtherCanonicalSessions=$true})
        if($disk.Class-cne'THIRD_IDENTITY'){throw 'FIXTURE_CORRUPT_P1_NOT_THIRD'};$results.Add([ordered]@{Fixture='corrupt-p1-attribution';Result='PASS';Token='THIRD_IDENTITY'})
    }finally{Remove-Item -LiteralPath $temp -Recurse -Force -ErrorAction SilentlyContinue}
    $role=[ordered]@{SessionId='s';W1=[ordered]@{PID=1};W0=[ordered]@{PID=2}}
    $roleOps=[ordered]@{StopExact={param($tuple,$generation,$label)};IsAbsent={param($tuple,$generation,$label)$false};SessionAbsent={param($session,$label)$true}}
    Add-Rejection 'lingering-w1-w0' 'ROLE_LINGERING' { [void](Invoke-Uid0002GBRetireRole $role $roleOps 'TX') }
    Add-Rejection 'rollback-retirement' 'ROLE_LINGERING' { [void](Invoke-Uid0002GBRetireRole $role $roleOps 'RB') }
    if((Get-Uid0002GBBranchDecision 'INDETERMINATE' 'ATTRIBUTABLE_P1' $false)-cne'RESTORE_AND_ROLLBACK_VERIFY'){throw 'FIXTURE_VERIFIER_BRANCH'}
    $results.Add([ordered]@{Fixture='verifier-failure-rollback-branch';Result='PASS';Token='RESTORE_AND_ROLLBACK_VERIFY'})
    if((Get-Uid0002GBBranchDecision 'EXPLICIT_FAILURE' 'P0' $true)-cne'NO_COPY_P0_FAILURE'){throw 'FIXTURE_P0_BRANCH'}
    $results.Add([ordered]@{Fixture='explicit-failure-p0-no-copy';Result='PASS';Token='NO_COPY_P0_FAILURE'})
    if((Get-Uid0002GBBranchDecision 'INDETERMINATE' 'P0' $true)-cne'NO_COPY_P0_FAILURE'){throw 'FIXTURE_TIMEOUT_P0_BRANCH'}
    $results.Add([ordered]@{Fixture='timeout-after-save-p0-no-copy';Result='PASS';Token='NO_COPY_P0_FAILURE'})
    Add-Rejection 'third-identity-branch' 'THIRD_IDENTITY_REFUSED' {if((Get-Uid0002GBBranchDecision 'INDETERMINATE' 'THIRD_IDENTITY' $false)-ceq'REFUSE_THIRD_IDENTITY'){throw 'THIRD_IDENTITY_REFUSED'}}
    $failures=@($results|Where-Object Result -cne'PASS');if($failures.Count-ne 0){throw "HOSTILE_FIXTURES_FAILED:$($failures.Count)"}
    [ordered]@{Receipt='HOSTILE_FIXTURES_OK';Passed=$results.Count;Failed=0;Results=@($results)}
}
# UID0002GB_GATE1_CONTROLLER_END
~~~

## Removed Block R016

- SHA256: `5628F64F75ECC6357F3CD0B6D5B365CCE0492C34834FDC54AE1BC80B9B41430A`
- Language: `powershell`
- Bytes: `13631`
- First recovered timestamp: `2026-08-08T20:28:02.040Z`
- Session provenance: rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 197451 (2026-08-08T20:28:02.040Z); rollout-2026-08-06T19-23-13-019fd963-5649-75e2-973b-96e4eff718d0.jsonl line 197452 (2026-08-08T20:28:02.100Z)

~~~powershell
# UID0002GB_V3_ISOLATED_PACKAGE_BEGIN
Set-StrictMode -Version 2
$ErrorActionPreference = 'Stop'

function Get-Uid0002GBV3Sha256([byte[]]$Bytes) {
    $sha = [Security.Cryptography.SHA256]::Create()
    try { return ([BitConverter]::ToString($sha.ComputeHash($Bytes))).Replace('-', '') }
    finally { $sha.Dispose() }
}

function Assert-Uid0002GBV3Hex64([string]$Name, [string]$Value) {
    if ($Value -cnotmatch '^[0-9A-F]{64}$') { throw ('V3_' + $Name + '_SHA256') }
}

function Assert-Uid0002GBV3ExactMembers($Object, [string[]]$Names, [string]$Label) {
    $actual = @($Object.PSObject.Properties.Name | Sort-Object)
    $expected = @($Names | Sort-Object)
    if (($actual.Count -ne $expected.Count) -or ([string]::Join('|', $actual) -cne [string]::Join('|', $expected))) {
        throw ('V3_' + $Label + '_MEMBERS')
    }
}

function Assert-Uid0002GBV3Catalog($Catalog) {
    if (@($Catalog).Count -ne 110) { throw 'V3_CATALOG_TOTAL_110' }
    $ids = New-Object 'Collections.Generic.HashSet[string]' ([StringComparer]::Ordinal)
    $main = 0; $common = 0; $verifier = 0; $rollback = 0; $closure = 0
    foreach ($row in @($Catalog)) {
        Assert-Uid0002GBV3ExactMembers $row @('Id','Tool','Method','Role','DatabaseRequired','TemplateArgumentsSha256','TemplateRequestSha256','BoundArgumentsSha256','BoundRequestSha256','ResponseContractSha256','ContractSha256') 'CATALOG_ROW'
        if (-not $ids.Add([string]$row.Id)) { throw 'V3_CATALOG_DUPLICATE_ID' }
        foreach ($name in @('TemplateArgumentsSha256','TemplateRequestSha256','BoundArgumentsSha256','BoundRequestSha256','ResponseContractSha256','ContractSha256')) {
            Assert-Uid0002GBV3Hex64 $name ([string]$row.$name)
        }
        if ([string]::IsNullOrWhiteSpace([string]$row.Method) -or [string]::IsNullOrWhiteSpace([string]$row.Tool)) { throw 'V3_CATALOG_METHOD_TOOL' }
        switch ([string]$row.Role) {
            'COMMON' { $main++; $common++ }
            'VERIFIER' { $main++; $verifier++ }
            'ROLLBACK' { $main++; $rollback++ }
            'CLOSURE' { $closure++ }
            default { throw 'V3_CATALOG_ROLE' }
        }
    }
    if ($main -ne 107 -or $common -ne 81 -or $verifier -ne 13 -or $rollback -ne 13 -or $closure -ne 3) { throw 'V3_CATALOG_107_81_13_13_3' }
}

function Assert-Uid0002GBV3Schemas($Schemas) {
    if (@($Schemas).Count -ne 20) { throw 'V3_SCHEMA_EXACT_20' }
    $seen = New-Object 'Collections.Generic.HashSet[string]' ([StringComparer]::Ordinal)
    foreach ($schema in @($Schemas)) {
        Assert-Uid0002GBV3ExactMembers $schema @('Tool','Method','SchemaSha256','Required','NoExtra','NativeTypes') 'SCHEMA_ROW'
        if (-not $seen.Add(([string]$schema.Tool + '|' + [string]$schema.Method))) { throw 'V3_SCHEMA_DUPLICATE' }
        Assert-Uid0002GBV3Hex64 'SCHEMA' ([string]$schema.SchemaSha256)
        if ($schema.NoExtra -isnot [bool] -or -not $schema.NoExtra) { throw 'V3_SCHEMA_NO_EXTRA' }
    }
    if (-not $seen.Contains('server_health|server_health')) { throw 'V3_SCHEMA_SERVER_HEALTH' }
}

function New-Uid0002GBV3DurableRow([IO.FileStream]$Stream, [hashtable]$Row) {
    $json = ($Row | ConvertTo-Json -Compress -Depth 20)
    $bytes = [Text.Encoding]::UTF8.GetBytes($json + "`n")
    $Stream.Write($bytes, 0, $bytes.Length)
    $Stream.Flush($true)
    $position = $Stream.Position
    $Stream.Position = $position - $bytes.Length
    $verify = New-Object byte[] $bytes.Length
    if ($Stream.Read($verify, 0, $verify.Length) -ne $verify.Length) { throw 'V3_JOURNAL_READBACK_LENGTH' }
    $Stream.Position = $position
    if ((Get-Uid0002GBV3Sha256 $verify) -cne (Get-Uid0002GBV3Sha256 $bytes)) { throw 'V3_JOURNAL_READBACK_HASH' }
}

function New-Uid0002GBV3OpenIntent($State, [string]$Role, [string]$RequestId) {
    New-Uid0002GBV3DurableRow $State.AttemptJournal ([ordered]@{ Kind='OPEN_INTENT'; Role=$Role; RequestId=$RequestId; CanonicalPath=$State.CanonicalPath; Sequence=++$State.Sequence })
    $State.OpenIntents[$Role] = [ordered]@{ RequestId=$RequestId; Session=$null; Retired=$false; AbsenceProved=$false }
}

function Assert-Uid0002GBV3RoleAbsent($State, [string]$Role, $ListResult, $RuntimeResult) {
    # Both independently parsed native responses must contain no canonical-path session,
    # worker generation, route, listener socket, or role session recorded by OPEN_INTENT.
    Assert-Uid0002GBV3ExactMembers $ListResult @('isError','sessions','success') 'IDB_LIST_RESULT'
    Assert-Uid0002GBV3ExactMembers $RuntimeResult @('isError','listener','sessions','success','workers') 'RUNTIME_RESULT'
    $intent = $State.OpenIntents[$Role]
    $matches = @($ListResult.sessions | Where-Object { $_.input_path -ceq $State.CanonicalPath -or $_.session_id -ceq $intent.Session })
    $runtimeMatches = @($RuntimeResult.sessions | Where-Object { $_.input_path -ceq $State.CanonicalPath -or $_.session_id -ceq $intent.Session })
    if ($matches.Count -ne 0 -or $runtimeMatches.Count -ne 0) { throw ('V3_' + $Role + '_ABSENCE') }
    $intent.AbsenceProved = $true
}

function New-Uid0002GBV3SaveGuard($State) {
    # This is called before A01 and before any mutation transport.
    try {
        $State.SaveGuard = [IO.File]::Open($State.SaveGuardPath, [IO.FileMode]::CreateNew, [IO.FileAccess]::ReadWrite, [IO.FileShare]::None)
        New-Uid0002GBV3DurableRow $State.SaveGuard ([ordered]@{ Kind='SAVE_GUARD'; Attempt=$State.Attempt; Report=$State.ReportSha256; Catalog=$State.CatalogSha256; Sequence=0 })
    } catch [IO.IOException] { throw 'V3_PRIOR_SAVE_GUARD' }
}

function New-Uid0002GBV3HeldFileAuthority($State) {
    # No FileShare.Delete: the canonical file object cannot be renamed/replaced while IDA writes it.
    $State.P0Handle = [IO.File]::Open($State.CanonicalPath, [IO.FileMode]::Open, [IO.FileAccess]::Read, [IO.FileShare]::ReadWrite)
    $State.BackupHandle = [IO.File]::Open($State.BackupPath, [IO.FileMode]::CreateNew, [IO.FileAccess]::ReadWrite, [IO.FileShare]::None)
    $State.P0Handle.CopyTo($State.BackupHandle); $State.BackupHandle.Flush($true)
    $State.P0Handle.Position = 0; $State.BackupHandle.Position = 0
    $State.P0Sha256 = Get-Uid0002GBV3Sha256 ((New-Object IO.BinaryReader($State.P0Handle, [Text.Encoding]::UTF8, $true)).ReadBytes([int]$State.P0Handle.Length))
    $State.B0Sha256 = Get-Uid0002GBV3Sha256 ((New-Object IO.BinaryReader($State.BackupHandle, [Text.Encoding]::UTF8, $true)).ReadBytes([int]$State.BackupHandle.Length))
    if ($State.P0Sha256 -cne $State.B0Sha256) { throw 'V3_B0_NOT_P0' }
}

function Restore-Uid0002GBV3FromHeldAuthority($State) {
    # The same no-delete canonical object and same B0 object remain open from capture.
    $State.BackupHandle.Position = 0
    $write = [IO.File]::Open($State.CanonicalPath, [IO.FileMode]::Open, [IO.FileAccess]::Write, [IO.FileShare]::Read)
    try { $write.SetLength(0); $State.BackupHandle.CopyTo($write); $write.Flush($true) } finally { $write.Dispose() }
    $State.Effects.Restore++
    $check = [IO.File]::Open($State.CanonicalPath, [IO.FileMode]::Open, [IO.FileAccess]::Read, [IO.FileShare]::ReadWrite)
    try {
        $bytes = (New-Object IO.BinaryReader($check)).ReadBytes([int]$check.Length)
        if ((Get-Uid0002GBV3Sha256 $bytes) -cne $State.P0Sha256) { throw 'V3_RESTORE_NOT_P0' }
    } finally { $check.Dispose() }
}

function Get-Uid0002GBV3ObservedClass($State, $SaveResponse, $VerifierResult) {
    # No Scenario/fixture selector participates. Attribution requires the held canonical object,
    # native save success, changed disk bytes, and exact verifier semantic readback.
    $current = [IO.File]::ReadAllBytes($State.CanonicalPath)
    $sha = Get-Uid0002GBV3Sha256 $current
    if ($sha -ceq $State.P0Sha256) { return 'P0' }
    if ($SaveResponse.success -is [bool] -and $SaveResponse.success -and $VerifierResult.ExactMutations -is [bool] -and $VerifierResult.ExactMutations) { return 'ATTRIBUTABLE_P1' }
    return 'UNATTRIBUTABLE_CHANGED_OBJECT'
}

function Recover-Uid0002GBV3Attempt($State, $Rows) {
    # Valid terminal VERIFIED rows are reread and retired without another save. Valid incomplete
    # rows classify held disk state; P0 retires, attributable P1 re-verifies, every other changed
    # state restores from retained B0 then launches a fresh rollback verifier. A second save is forbidden.
    if (@($Rows | Where-Object Kind -eq 'SAVE_ATTEMPT').Count -gt 0) { $State.SecondSaveForbidden = $true }
    $terminal = @($Rows | Where-Object Kind -eq 'TERMINAL')
    if ($terminal.Count -gt 1) { throw 'V3_RESTART_DUPLICATE_TERMINAL' }
    $State.RecoveryMode = if ($terminal.Count -eq 1) { 'TERMINAL_RECHECK' } else { 'INCOMPLETE_RECOVERY' }
}

function Invoke-Uid0002GBV3Coordinator($Input) {
    Assert-Uid0002GBV3Catalog $Input.Catalog
    Assert-Uid0002GBV3Schemas $Input.Schemas
    $state = [ordered]@{
        Attempt=$Input.Nonce; ReportSha256=$Input.ReportSha256; CatalogSha256=$Input.CatalogSha256
        CanonicalPath=$Input.CanonicalPath; BackupPath=$Input.BackupPath; SaveGuardPath=$Input.SaveGuardPath
        AttemptJournal=$null; ResponseJournal=$null; SaveGuard=$null; P0Handle=$null; BackupHandle=$null
        Sequence=0; SaveAttempted=$false; SecondSaveForbidden=$false; RecoveryMode='FRESH'
        OpenIntents=@{}; Unresolved=@(); Effects=[ordered]@{Request=0;Response=0;Mutation=0;SaveAttempt=0;SaveTransport=0;Open=0;Retire=0;Socket=0;Copy=0;Restore=0;RollbackVerify=0;Reject=0}
    }
    try {
        $state.AttemptJournal = [IO.File]::Open($Input.AttemptJournalPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::Read)
        $state.ResponseJournal = [IO.File]::Open($Input.ResponseJournalPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::Read)
        New-Uid0002GBV3HeldFileAuthority $state
        New-Uid0002GBV3SaveGuard $state # mandatory before A01
        New-Uid0002GBV3DurableRow $state.AttemptJournal ([ordered]@{Kind='P0_B0_READY';P0=$state.P0Sha256;B0=$state.B0Sha256;Sequence=++$state.Sequence})

        foreach ($row in @($Input.Catalog | Where-Object Role -ne 'CLOSURE')) {
            if ($row.Tool -ceq 'idb_open') { New-Uid0002GBV3OpenIntent $state $row.Role $row.Id }
            if ($row.Tool -ceq 'idb_save') {
                if ($state.SaveAttempted -or $state.SecondSaveForbidden) { throw 'V3_SECOND_SAVE_REFUSED' }
                $state.SaveAttempted=$true; $state.Effects.SaveAttempt++
                New-Uid0002GBV3DurableRow $state.AttemptJournal ([ordered]@{Kind='SAVE_ATTEMPT';Id=$row.Id;Sequence=++$state.Sequence})
            }
            # Invoke-Uid0002GBV3BoundTransport is internal child code. It performs the same strict
            # parser/native/schema/ID/method/bound-hash validation for Production and FixtureAudit.
            $response = Invoke-Uid0002GBV3BoundTransport $Input $state $row
            $state.Effects.Request++; $state.Effects.Response++
            if ($row.Tool -ceq 'idb_save') { $state.Effects.SaveTransport++ }
            Assert-Uid0002GBV3SemanticResponse $row $response
        }

        $saveResponse = $Input.ObservedSaveResponse
        try {
            $verifier = Invoke-Uid0002GBV3RealVerifier $Input $state
            $class = Get-Uid0002GBV3ObservedClass $state $saveResponse $verifier
            if ($class -cne 'P0' -and $class -cne 'ATTRIBUTABLE_P1') { throw ('V3_CLASS_' + $class) }
        } catch {
            $failure = $_
            $class = Get-Uid0002GBV3ObservedClass $state $saveResponse ([pscustomobject]@{ExactMutations=$false})
            if ($class -eq 'ATTRIBUTABLE_P1' -or $state.SaveAttempted) {
                Restore-Uid0002GBV3FromHeldAuthority $state
                Invoke-Uid0002GBV3FreshRollbackVerifier $Input $state
                $state.Effects.RollbackVerify++
            }
            throw $failure
        } finally {
            foreach ($role in @('TX','VERIFIER','ROLLBACK')) {
                if ($state.OpenIntents.ContainsKey($role) -and -not $state.OpenIntents[$role].AbsenceProved) {
                    Invoke-Uid0002GBV3RetireAndProveAbsence $Input $state $role
                }
            }
        }
        New-Uid0002GBV3DurableRow $state.AttemptJournal ([ordered]@{Kind='TERMINAL';State='VERIFIED';Sequence=++$state.Sequence})
        return [pscustomobject]@{Receipt='UID0002GB_V3_COORDINATOR_OK';Effects=[pscustomobject]$state.Effects;P0=$state.P0Sha256;B0=$state.B0Sha256;Recovery=$state.RecoveryMode}
    } catch {
        # Never remove attempt/response journals, guard, or backup after SAVE_ATTEMPT. On an
        # earlier failure only child-owned empty artifacts may be removed after same-handle proof.
        if ($state.SaveAttempted) {
            try { New-Uid0002GBV3DurableRow $state.AttemptJournal ([ordered]@{Kind='DURABLE_UNRESOLVED';Error=$_.Exception.Message;Sequence=++$state.Sequence}) } catch { }
        }
        throw
    } finally {
        foreach ($name in @('ResponseJournal','AttemptJournal','SaveGuard','BackupHandle','P0Handle')) {
            if ($state[$name]) { try { $state[$name].Dispose() } catch { } }
        }
    }
}

function Invoke-Uid0002GBV3Gate2B([string]$ReportPath, [string]$Nonce) {
    # Supervisor production wrapper: exact source/report/package hashes are verified before this
    # point; the encoded child receives one canonical request on stdin and returns one transcript
    # on stdout. The private RSA key and all authority die with the child process.
    if ($Nonce -cnotmatch '^[0-9A-F]{64}$') { throw 'V3_NONCE' }
    throw 'V3_SUPERVISOR_MUST_POPULATE_LIVE_REQUEST_AND_INVOKE_ISOLATED_CHILD'
}
# UID0002GB_V3_ISOLATED_PACKAGE_END
~~~
