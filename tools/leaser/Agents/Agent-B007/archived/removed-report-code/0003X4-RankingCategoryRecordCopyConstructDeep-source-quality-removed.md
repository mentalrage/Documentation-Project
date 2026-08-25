<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0003X4-RankingCategoryRecordCopyConstructDeep-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003X4-RankingCategoryRecordCopyConstructDeep-source-quality.md](0003X4-RankingCategoryRecordCopyConstructDeep-source-quality.md)
- Source report SHA256 before archive-link insertion: `992CA7A211EA184AEB574BDA3F5A80539942BED276D9981B81171607CCB3CEB2`
- Recovery generated: `2026-08-09T22:17:53Z`
- Unique recovered executable blocks: `10`
- Recovered executable bytes: `175981`
- Recovery basis: report-path-associated Codex session history. The source report had already removed its executable packages before the supervisor could extract them directly.
- Scope: this archive preserves every unique recoverable report-local executable block, including superseded historical variants where session history retained more than the final pre-removal report.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- SHA256: `786409EC9227E6E62D1E2C6B63D9ECC5CEECA171806F414ACA83AC6E9BA3A209`
- Language: `powershell`
- Bytes: `5553`
- First recovered timestamp: `2026-08-06T22:37:34.406Z`
- Session provenance: rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 193762 (2026-08-06T22:37:34.406Z); rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 193763 (2026-08-06T22:37:34.469Z)

~~~powershell
function Get-ExactFileRecord([string]$Path) {
    $resolved = [IO.Path]::GetFullPath((Resolve-Path -LiteralPath $Path -ErrorAction Stop).ProviderPath)
    $item = Get-Item -LiteralPath $resolved -Force -ErrorAction Stop
    if (-not $item.PSIsContainer -and $item.Length -ge 0) {
        return [ordered]@{
            Path = $resolved
            Length = [int64]$item.Length
            LastWriteTimeUtcTicks = [int64]$item.LastWriteTimeUtc.Ticks
            SHA256 = (Get-FileHash -LiteralPath $resolved -Algorithm SHA256 -ErrorAction Stop).Hash.ToUpperInvariant()
        }
    }
    throw "Expected file: $resolved"
}

function Get-ManifestSha256([string]$Json) {
    $sha = [Security.Cryptography.SHA256]::Create()
    try {
        $bytes = [Text.Encoding]::UTF8.GetBytes($Json)
        return ([BitConverter]::ToString($sha.ComputeHash($bytes))).Replace('-', '')
    } finally {
        $sha.Dispose()
    }
}

function Get-UID0003X4ListenerBinding {
    $listeners = @(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort 13337 -State Listen -ErrorAction Stop)
    if ($listeners.Count -ne 1) { throw "Expected exactly one 127.0.0.1:13337 listener, got $($listeners.Count)" }
    $rows = @(Get-CimInstance Win32_Process -ErrorAction Stop)
    function Get-OneProcess([int]$Pid, [string]$Role) {
        $match = @($rows | Where-Object { [int]$_.ProcessId -eq $Pid })
        if ($match.Count -ne 1) { throw "$Role PID $Pid did not resolve exactly once" }
        if ([string]::IsNullOrWhiteSpace([string]$match[0].ExecutablePath) -or
            [string]::IsNullOrWhiteSpace([string]$match[0].CommandLine)) { throw "$Role lacks executable/command line" }
        return $match[0]
    }
    $l2 = Get-OneProcess ([int]$listeners[0].OwningProcess) 'L2'
    $l1 = Get-OneProcess ([int]$l2.ParentProcessId) 'L1'
    $l0 = Get-OneProcess ([int]$l1.ParentProcessId) 'L0'
    if ([int]$l1.ParentProcessId -ne [int]$l0.ProcessId -or [int]$l2.ParentProcessId -ne [int]$l1.ProcessId) {
        throw 'L0->L1->L2 parent chain mismatch'
    }
    $l0Exe = [IO.Path]::GetFullPath($l0.ExecutablePath)
    $l1Exe = [IO.Path]::GetFullPath($l1.ExecutablePath)
    $l2Exe = [IO.Path]::GetFullPath($l2.ExecutablePath)
    if ([IO.Path]::GetFileName($l0Exe) -ine 'idalib-mcp.exe') { throw 'L0 is not idalib-mcp.exe' }
    if ([IO.Path]::GetFileName($l1Exe) -ine 'python.exe') { throw 'L1 is not venv Python' }
    $l0Venv = [IO.Path]::GetFullPath((Split-Path -Parent (Split-Path -Parent $l0Exe)))
    $l1Venv = [IO.Path]::GetFullPath((Split-Path -Parent (Split-Path -Parent $l1Exe)))
    if (-not [string]::Equals($l0Venv, $l1Venv, [StringComparison]::OrdinalIgnoreCase)) {
        throw 'L0 and L1 do not derive the same venv root'
    }
    $packageRoot = [IO.Path]::GetFullPath((Join-Path $l0Venv 'Lib\site-packages\ida_pro_mcp'))
    if (-not [IO.Directory]::Exists($packageRoot)) { throw "Derived package root absent: $packageRoot" }
    $relativeSources = @(
        'idalib_supervisor.py','idalib_server.py','idalib_session_manager.py','worker_lifecycle.py','server.py',
        'ida_mcp\http.py','ida_mcp\sync.py','ida_mcp\api_modify.py','ida_mcp\api_types.py','ida_mcp\api_core.py',
        'ida_mcp\api_stack.py','ida_mcp\api_memory.py','ida_mcp\api_analysis.py','ida_mcp\utils.py'
    )
    $prefix = $packageRoot.TrimEnd('\') + '\'
    $sourceRecords = @($relativeSources | ForEach-Object {
        $full = [IO.Path]::GetFullPath((Join-Path $packageRoot $_))
        if (-not $full.StartsWith($prefix, [StringComparison]::OrdinalIgnoreCase)) { throw "Source escaped package root: $full" }
        Get-ExactFileRecord $full
    })
    $roleRows = @(
        [ordered]@{ Role='L0-root'; Process=$l0; Executable=$l0Exe; SocketRole='ancestor-root' },
        [ordered]@{ Role='L1-venv-python'; Process=$l1; Executable=$l1Exe; SocketRole='listener-parent' },
        [ordered]@{ Role='L2-base-python'; Process=$l2; Executable=$l2Exe; SocketRole='127.0.0.1:13337-owner' }
    )
    $processRecords = @($roleRows | ForEach-Object {
        $p = $_.Process
        $modules = @(Get-Process -Id ([int]$p.ProcessId) -Module -ErrorAction Stop |
            ForEach-Object { [IO.Path]::GetFullPath($_.FileName) } | Sort-Object -Unique |
            ForEach-Object { Get-ExactFileRecord $_ })
        if ($modules.Count -eq 0) { throw "$($_.Role) native-module manifest is empty" }
        [ordered]@{
            Role = $_.Role
            PID = [int]$p.ProcessId
            ParentPID = [int]$p.ParentProcessId
            CreationTimeUtcTicks = [int64]([datetime]$p.CreationDate).ToUniversalTime().Ticks
            Executable = Get-ExactFileRecord $_.Executable
            CommandLine = [string]$p.CommandLine
            SocketRole = $_.SocketRole
            NativeModules = $modules
        }
    })
    $manifest = [ordered]@{
        Listener = [ordered]@{ Address='127.0.0.1'; Port=13337; State='Listen'; OwningPID=[int]$listeners[0].OwningProcess }
        VenvRoot = $l0Venv
        PackageRoot = $packageRoot
        Processes = $processRecords
        EndpointSources = $sourceRecords
    }
    $json = $manifest | ConvertTo-Json -Depth 12 -Compress
    [pscustomobject]@{ Manifest=$manifest; Json=$json; SHA256=(Get-ManifestSha256 $json) }
}

function Assert-UID0003X4ListenerBinding($Frozen, [string]$Boundary) {
    $current = Get-UID0003X4ListenerBinding
    if ($current.SHA256 -cne $Frozen.SHA256 -or $current.Json -cne $Frozen.Json) {
        throw "Listener/source-route drift at $Boundary"
    }
    return $current
}
~~~

## Removed Block R002

- SHA256: `0BA7DAB6B82ECF9350BC026CD4522A4F4F65252F9C26372B054E4EC98618F34F`
- Language: `powershell`
- Bytes: `3636`
- First recovered timestamp: `2026-08-06T22:38:01.190Z`
- Session provenance: rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 193767 (2026-08-06T22:38:01.190Z); rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 193768 (2026-08-06T22:38:01.251Z)

~~~powershell
function Get-UID0003X4ClosedTuple([string]$Path) {
    $resolved = [IO.Path]::GetFullPath((Resolve-Path -LiteralPath $Path -ErrorAction Stop).ProviderPath)
    $stream = [IO.FileStream]::new($resolved,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None,1048576,[IO.FileOptions]::SequentialScan)
    try {
        $length = [int64]$stream.Length
        $sha = [Security.Cryptography.SHA256]::Create()
        try { $hash = ([BitConverter]::ToString($sha.ComputeHash($stream))).Replace('-', '') }
        finally { $sha.Dispose() }
    } finally {
        $stream.Dispose()
    }
    [pscustomobject]@{
        ResolvedPath = $resolved
        Length = $length
        LastWriteTimeUtcTicks = [int64][IO.File]::GetLastWriteTimeUtc($resolved).Ticks
        SHA256 = $hash
    }
}

function Assert-UID0003X4Tuple($Actual, [string]$ExpectedPath, $ExpectedContent, [string]$Label) {
    $resolvedExpected = [IO.Path]::GetFullPath($ExpectedPath)
    if (-not [string]::Equals($Actual.ResolvedPath,$resolvedExpected,[StringComparison]::OrdinalIgnoreCase) -or
        [int64]$Actual.Length -ne [int64]$ExpectedContent.Length -or
        [int64]$Actual.LastWriteTimeUtcTicks -ne [int64]$ExpectedContent.LastWriteTimeUtcTicks -or
        [string]$Actual.SHA256 -cne [string]$ExpectedContent.SHA256) {
        throw "$Label tuple mismatch"
    }
}

function New-UID0003X4ExactClone([string]$SourcePath,[string]$DestinationPath,$P0,[string]$Label) {
    if ([IO.File]::Exists($DestinationPath) -or [IO.Directory]::Exists($DestinationPath)) {
        throw "$Label candidate already exists"
    }
    $sourceBefore = Get-UID0003X4ClosedTuple $SourcePath
    Assert-UID0003X4Tuple $sourceBefore $P0.ResolvedPath $P0 "$Label source-before"
    $source = $null
    $destination = $null
    try {
        $source = [IO.FileStream]::new($P0.ResolvedPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None,1048576,[IO.FileOptions]::SequentialScan)
        if ([int64]$source.Length -ne [int64]$P0.Length) { throw "$Label source length drift" }
        $destination = [IO.FileStream]::new($DestinationPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None,1048576,[IO.FileOptions]::WriteThrough)
        $buffer = New-Object byte[] 1048576
        [int64]$copied = 0
        while ($copied -lt [int64]$P0.Length) {
            $wanted = [int][Math]::Min([int64]$buffer.Length,[int64]$P0.Length-$copied)
            $read = $source.Read($buffer,0,$wanted)
            if ($read -le 0) { throw "$Label short source at $copied" }
            $destination.Write($buffer,0,$read)
            $copied += $read
        }
        if ($copied -ne [int64]$P0.Length -or $source.ReadByte() -ne -1) { throw "$Label copy-count/EOF mismatch" }
        if ([int64]$destination.Length -ne [int64]$P0.Length) { throw "$Label destination length mismatch" }
        $destination.Flush($true)
    } finally {
        if ($null -ne $destination) { $destination.Dispose() }
        if ($null -ne $source) { $source.Dispose() }
    }
    [IO.File]::SetLastWriteTimeUtc($DestinationPath,[datetime]::new([int64]$P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
    $closedClone = Get-UID0003X4ClosedTuple $DestinationPath
    Assert-UID0003X4Tuple $closedClone $DestinationPath $P0 "$Label closed clone"
    $closedCanonical = Get-UID0003X4ClosedTuple $P0.ResolvedPath
    Assert-UID0003X4Tuple $closedCanonical $P0.ResolvedPath $P0 "$Label canonical-after"
    return $closedClone
}

$B0Tuple = New-UID0003X4ExactClone $P0.ResolvedPath $B0Path $P0 'B0'
$D0Tuple = New-UID0003X4ExactClone $P0.ResolvedPath $D0Path $P0 'D0'
~~~

## Removed Block R003

- SHA256: `C4CE19435484DBFAEE0E6CC308BD7E0C0463D85F75C0904FD5035EE5EE0945E2`
- Language: `powershell`
- Bytes: `2885`
- First recovered timestamp: `2026-08-06T22:38:31.657Z`
- Session provenance: rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 193772 (2026-08-06T22:38:31.657Z); rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 193773 (2026-08-06T22:38:31.719Z)

~~~powershell
function Restore-UID0003X4ExactP0([string]$B0Path,[string]$CanonicalPath,$P0,[bool]$TransactionAttributable) {
    if (-not $TransactionAttributable) { throw 'Canonical identity is not proven attributable to this T01' }
    if ([string]::Equals([IO.Path]::GetFullPath($B0Path),[IO.Path]::GetFullPath($CanonicalPath),[StringComparison]::OrdinalIgnoreCase)) {
        throw 'B0 and canonical paths collide'
    }
    $b0Before = Get-UID0003X4ClosedTuple $B0Path
    Assert-UID0003X4Tuple $b0Before $B0Path $P0 'restore B0-before'
    $canonicalBefore = Get-UID0003X4ClosedTuple $CanonicalPath
    if ([string]::Equals($canonicalBefore.ResolvedPath,$P0.ResolvedPath,[StringComparison]::OrdinalIgnoreCase) -and
        [int64]$canonicalBefore.Length -eq [int64]$P0.Length -and
        [int64]$canonicalBefore.LastWriteTimeUtcTicks -eq [int64]$P0.LastWriteTimeUtcTicks -and
        [string]$canonicalBefore.SHA256 -ceq [string]$P0.SHA256) { throw 'Canonical is already exact P0; restore is forbidden' }
    $source = $null
    $destination = $null
    try {
        $source = [IO.FileStream]::new($B0Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None,1048576,[IO.FileOptions]::SequentialScan)
        if ([int64]$source.Length -ne [int64]$P0.Length) { throw 'B0 length drift before restore' }
        $destination = [IO.FileStream]::new($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::Write,[IO.FileShare]::None,1048576,[IO.FileOptions]::WriteThrough)
        $destination.SetLength(0)
        $buffer = New-Object byte[] 1048576
        [int64]$copied = 0
        while ($copied -lt [int64]$P0.Length) {
            $wanted = [int][Math]::Min([int64]$buffer.Length,[int64]$P0.Length-$copied)
            $read = $source.Read($buffer,0,$wanted)
            if ($read -le 0) { throw "B0 short read at $copied" }
            $destination.Write($buffer,0,$read)
            $copied += $read
        }
        if ($copied -ne [int64]$P0.Length -or $source.ReadByte() -ne -1) { throw 'Restore copy-count/EOF mismatch' }
        if ([int64]$destination.Length -ne [int64]$P0.Length) { throw 'Truncated destination length mismatch' }
        $destination.Flush($true)
    } finally {
        if ($null -ne $destination) { $destination.Dispose() }
        if ($null -ne $source) { $source.Dispose() }
    }
    [IO.File]::SetLastWriteTimeUtc($CanonicalPath,[datetime]::new([int64]$P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
    $canonicalAfter = Get-UID0003X4ClosedTuple $CanonicalPath
    Assert-UID0003X4Tuple $canonicalAfter $P0.ResolvedPath $P0 'restore canonical-after'
    $b0After = Get-UID0003X4ClosedTuple $B0Path
    Assert-UID0003X4Tuple $b0After $B0Path $P0 'restore B0-after'
    [pscustomobject]@{ Canonical=$canonicalAfter; Backup=$b0After; Copied=[int64]$copied }
}

$Restored = Restore-UID0003X4ExactP0 $B0Path $P0.ResolvedPath $P0 $true
~~~

## Removed Block R004

- SHA256: `ED6043D6824B3DBD17380FCB9AC29E80F9F91821F27BCC74871BBAB5C17A9D0E`
- Language: `powershell`
- Bytes: `6417`
- First recovered timestamp: `2026-08-06T22:59:25.965Z`
- Session provenance: rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 193912 (2026-08-06T22:59:25.965Z); rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 193913 (2026-08-06T22:59:26.029Z)

~~~powershell
$UID0003X4PythonAttestationTemplate = @'
import hashlib, inspect, json, os, pathlib, sys
ROLE = __ROLE_JSON__
NONCE = __NONCE_JSON__
EXPECTED_PID = __PID_INT__
EXPECTED_ROOT = pathlib.Path(__ROOT_JSON__).resolve(strict=True)
OUTPUT = pathlib.Path(__OUTPUT_JSON__)
if os.getpid() != EXPECTED_PID:
    raise RuntimeError("attestation PID mismatch")
records = []
for name, module in sorted(sys.modules.items()):
    if name != "ida_pro_mcp" and not name.startswith("ida_pro_mcp."):
        continue
    loaded_raw = getattr(module, "__file__", None)
    spec = getattr(module, "__spec__", None)
    spec_origin = getattr(spec, "origin", None) if spec is not None else None
    try:
        source_raw = inspect.getsourcefile(module)
    except Exception:
        source_raw = None
    def file_record(raw):
        if not raw:
            return None
        path = pathlib.Path(raw).resolve(strict=True)
        if not path.is_relative_to(EXPECTED_ROOT):
            raise RuntimeError(f"module path escaped package root: {name}: {path}")
        data = path.read_bytes()
        stat = path.stat()
        return {
            "path": str(path),
            "size": len(data),
            "mtime_ns": stat.st_mtime_ns,
            "sha256": hashlib.sha256(data).hexdigest().upper(),
        }
    loaded = file_record(loaded_raw)
    source = file_record(source_raw)
    if loaded is None and source is None:
        raise RuntimeError(f"loaded ida_pro_mcp module lacks file/source: {name}")
    records.append({
        "name": name,
        "module_object_id": hex(id(module)),
        "loader_type": type(getattr(spec, "loader", None)).__qualname__ if spec is not None else None,
        "spec_origin": spec_origin,
        "loaded_file": loaded,
        "source_file": source,
    })
if not records:
    raise RuntimeError("no loaded ida_pro_mcp modules")
payload = {
    "role": ROLE,
    "nonce": NONCE,
    "pid": os.getpid(),
    "sys_executable": str(pathlib.Path(sys.executable).resolve(strict=True)),
    "sys_prefix": str(pathlib.Path(sys.prefix).resolve(strict=True)),
    "sys_base_prefix": str(pathlib.Path(sys.base_prefix).resolve(strict=True)),
    "python_version": list(sys.version_info[:3]),
    "package_root": str(EXPECTED_ROOT),
    "modules": records,
}
encoded = json.dumps(payload, sort_keys=True, separators=(",", ":")).encode("utf-8")
with OUTPUT.open("xb") as stream:
    stream.write(encoded)
    stream.flush()
    os.fsync(stream.fileno())
'@

function Invoke-UID0003X4PythonAttestation(
    [string]$Role,[int]$TargetPid,[string]$RemotePython,[string]$PackageRoot,[string[]]$RequiredModules
) {
    $nonce = [Guid]::NewGuid().ToString('N')
    $scriptPath = Join-Path ([IO.Path]::GetTempPath()) "uid0003x4-attest-$Role-$nonce.py"
    $outputPath = Join-Path ([IO.Path]::GetTempPath()) "uid0003x4-attest-$Role-$nonce.json"
    if ([IO.File]::Exists($scriptPath) -or [IO.Directory]::Exists($scriptPath) -or
        [IO.File]::Exists($outputPath) -or [IO.Directory]::Exists($outputPath)) { throw 'Attestation path collision' }
    $scriptText = $UID0003X4PythonAttestationTemplate
        .Replace('__ROLE_JSON__',($Role | ConvertTo-Json -Compress))
        .Replace('__NONCE_JSON__',($nonce | ConvertTo-Json -Compress))
        .Replace('__PID_INT__',[string]$TargetPid)
        .Replace('__ROOT_JSON__',([IO.Path]::GetFullPath($PackageRoot) | ConvertTo-Json -Compress))
        .Replace('__OUTPUT_JSON__',([IO.Path]::GetFullPath($outputPath) | ConvertTo-Json -Compress))
    $scriptBytes = [Text.UTF8Encoding]::new($false).GetBytes($scriptText)
    $scriptStream = [IO.FileStream]::new($scriptPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None,65536,[IO.FileOptions]::WriteThrough)
    try { $scriptStream.Write($scriptBytes,0,$scriptBytes.Length); $scriptStream.Flush($true) }
    finally { $scriptStream.Dispose() }
    $scriptTuple = Get-UID0003X4ClosedTuple $scriptPath
    $scriptLiteral = [string]($scriptPath | ConvertTo-Json -Compress)
    & $RemotePython -I -c "import sys; sys.remote_exec($TargetPid, $scriptLiteral)"
    if ($LASTEXITCODE -ne 0) { throw "$Role sys.remote_exec submission failed" }
    $deadline = [datetime]::UtcNow.AddSeconds(60)
    do {
        Start-Sleep -Milliseconds 100
        if ([IO.File]::Exists($outputPath)) {
            try { $outputTuple = Get-UID0003X4ClosedTuple $outputPath; break } catch { }
        }
    } while ([datetime]::UtcNow -lt $deadline)
    if ($null -eq $outputTuple) { throw "$Role attestation output timeout" }
    $raw = [IO.File]::ReadAllText($outputPath,[Text.Encoding]::UTF8)
    $data = $raw | ConvertFrom-Json
    if ([string]$data.role -cne $Role -or [string]$data.nonce -cne $nonce -or [int]$data.pid -ne $TargetPid) {
        throw "$Role attestation identity mismatch"
    }
    if (-not [string]::Equals([IO.Path]::GetFullPath($data.package_root),[IO.Path]::GetFullPath($PackageRoot),[StringComparison]::OrdinalIgnoreCase)) {
        throw "$Role attestation package-root mismatch"
    }
    $names = @($data.modules | ForEach-Object { [string]$_.name })
    foreach ($required in $RequiredModules) { if ($names -cnotcontains $required) { throw "$Role missing loaded module $required" } }
    foreach ($module in $data.modules) {
        foreach ($record in @($module.loaded_file,$module.source_file) | Where-Object { $null -ne $_ }) {
            $current = Get-ExactFileRecord ([string]$record.path)
            if ([int64]$current.Length -ne [int64]$record.size -or [string]$current.SHA256 -cne [string]$record.sha256) {
                throw "$Role loaded Python module drift: $($module.name)"
            }
        }
    }
    [pscustomobject]@{ Role=$Role; PID=$TargetPid; Script=$scriptTuple; Output=$outputTuple; Json=$raw; Data=$data }
}

$L2Required = @('ida_pro_mcp','ida_pro_mcp.idalib_supervisor','ida_pro_mcp.worker_lifecycle')
$WorkerRequired = @(
    'ida_pro_mcp','ida_pro_mcp.idalib_server','ida_pro_mcp.idalib_session_manager',
    'ida_pro_mcp.ida_mcp.api_modify','ida_pro_mcp.ida_mcp.api_types','ida_pro_mcp.ida_mcp.api_core',
    'ida_pro_mcp.ida_mcp.api_stack','ida_pro_mcp.ida_mcp.api_memory','ida_pro_mcp.ida_mcp.api_analysis',
    'ida_pro_mcp.ida_mcp.utils'
)
$L2PythonAttestation = Invoke-UID0003X4PythonAttestation 'L2-listener' $LR0.Manifest.Processes[2].PID $LR0.Manifest.Processes[2].Executable.Path $LR0.Manifest.PackageRoot $L2Required
~~~

## Removed Block R005

- SHA256: `E3400912E8EE7FA5297EE96C8D95E036C8CB4A185ED59C88D1EFA35F286171B9`
- Language: `powershell`
- Bytes: `4380`
- First recovered timestamp: `2026-08-06T23:00:14.845Z`
- Session provenance: rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 193921 (2026-08-06T23:00:14.845Z); rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 193922 (2026-08-06T23:00:14.907Z)

~~~powershell
$SeenDatabaseIds = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)

function New-UID0003X4IdbOpenRequest(
    [string]$RequestId,[string]$InputPath,[string]$PreferredSessionId
) {
    [ordered]@{
        jsonrpc = '2.0'
        id = $RequestId
        method = 'tools/call'
        params = [ordered]@{
            name = 'idb_open'
            arguments = [ordered]@{
                input_path = $InputPath
                mode = 'force_headless'
                run_auto_analysis = $false
                build_caches = $false
                init_hexrays = $false
                idle_ttl_sec = 600
                preferred_session_id = $PreferredSessionId
            }
        }
    }
}

function Get-UID0003X4ReturnedDatabaseId($Request,$Envelope,[string]$Role) {
    if ($null -eq $Envelope -or [string]$Envelope.jsonrpc -cne '2.0' -or [string]$Envelope.id -cne [string]$Request.id) {
        throw "$Role idb_open envelope/id mismatch"
    }
    if ($null -ne $Envelope.error -or $null -eq $Envelope.result -or $Envelope.result.isError -eq $true) {
        throw "$Role idb_open transport/tool failure"
    }
    $structured = $Envelope.result.structuredContent
    if ($null -eq $structured -or $structured.success -ne $true -or $null -eq $structured.session) {
        throw "$Role idb_open lacks result.structuredContent.session"
    }
    $database = [string]$structured.session.session_id
    if ([string]::IsNullOrWhiteSpace($database)) {
        throw "$Role result.structuredContent.session.session_id is empty"
    }
    $requestedPath = [IO.Path]::GetFullPath([string]$Request.params.arguments.input_path)
    $returnedPath = [IO.Path]::GetFullPath([string]$structured.session.input_path)
    if (-not [string]::Equals($requestedPath,$returnedPath,[StringComparison]::OrdinalIgnoreCase)) {
        throw "$Role returned input_path mismatch"
    }
    if (-not $SeenDatabaseIds.Add($database)) { throw "$Role returned duplicate database identifier $database" }
    return $database
}

function Open-UID0003X4Role(
    [string]$Role,[string]$RequestId,[string]$InputPath,[string]$PreferredSessionId,[scriptblock]$SendMcpJsonRpc
) {
    $request = New-UID0003X4IdbOpenRequest $RequestId $InputPath $PreferredSessionId
    $envelope = & $SendMcpJsonRpc $request
    $database = Get-UID0003X4ReturnedDatabaseId $request $envelope $Role
    [pscustomobject]@{ Role=$Role; Request=$request; Envelope=$envelope; Database=$database }
}

$stamp = [datetime]::UtcNow.ToString('yyyyMMddTHHmmssfffffffZ')
$D0_OPEN = Open-UID0003X4Role 'D0' 'uid0003x4-open-d0' $D0Path "uid0003x4-disposable-$stamp" $SendMcpJsonRpc
$D0_DB = $D0_OPEN.Database
$TXN_OPEN = Open-UID0003X4Role 'TXN' 'uid0003x4-open-transaction' $P0.ResolvedPath "uid0003x4-transaction-$stamp" $SendMcpJsonRpc
$TXN_DB = $TXN_OPEN.Database
# Execute each verifier open only in its classified branch, never eagerly:
$SUCCESS_VERIFY_OPEN = Open-UID0003X4Role 'SUCCESS_VERIFY' 'uid0003x4-open-success-verify' $P0.ResolvedPath "uid0003x4-success-verify-$stamp" $SendMcpJsonRpc
$SUCCESS_VERIFY_DB = $SUCCESS_VERIFY_OPEN.Database
$EXPLICIT_FAILURE_VERIFY_OPEN = Open-UID0003X4Role 'EXPLICIT_FAILURE_VERIFY' 'uid0003x4-open-explicit-failure-verify' $P0.ResolvedPath "uid0003x4-explicit-failure-verify-$stamp" $SendMcpJsonRpc
$EXPLICIT_FAILURE_VERIFY_DB = $EXPLICIT_FAILURE_VERIFY_OPEN.Database
$INDETERMINATE_VERIFY_1_OPEN = Open-UID0003X4Role 'INDETERMINATE_VERIFY_1' 'uid0003x4-open-indeterminate-verify-1' $P0.ResolvedPath "uid0003x4-indeterminate-verify-1-$stamp" $SendMcpJsonRpc
$INDETERMINATE_VERIFY_1_DB = $INDETERMINATE_VERIFY_1_OPEN.Database
$INDETERMINATE_VERIFY_2_OPEN = Open-UID0003X4Role 'INDETERMINATE_VERIFY_2' 'uid0003x4-open-indeterminate-verify-2' $P0.ResolvedPath "uid0003x4-indeterminate-verify-2-$stamp" $SendMcpJsonRpc
$INDETERMINATE_VERIFY_2_DB = $INDETERMINATE_VERIFY_2_OPEN.Database
$PRESAVE_FAILURE_VERIFY_OPEN = Open-UID0003X4Role 'PRESAVE_FAILURE_VERIFY' 'uid0003x4-open-presave-failure-verify' $P0.ResolvedPath "uid0003x4-presave-failure-verify-$stamp" $SendMcpJsonRpc
$PRESAVE_FAILURE_VERIFY_DB = $PRESAVE_FAILURE_VERIFY_OPEN.Database
$ROLLBACK_VERIFY_OPEN = Open-UID0003X4Role 'ROLLBACK_VERIFY' 'uid0003x4-open-rollback-verify' $P0.ResolvedPath "uid0003x4-rollback-verify-$stamp" $SendMcpJsonRpc
$ROLLBACK_VERIFY_DB = $ROLLBACK_VERIFY_OPEN.Database
~~~

## Removed Block R006

- SHA256: `0392B939F253D73C84D9B3D919CB44894AF300C5C9DFF9F2C97DD646AEFB8D44`
- Language: `powershell`
- Bytes: `5717`
- First recovered timestamp: `2026-08-06T23:01:29.338Z`
- Session provenance: rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 193938 (2026-08-06T23:01:29.338Z); rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 193939 (2026-08-06T23:01:29.394Z)

~~~powershell
$UID0003X4Signature = 'RankingCategoryRecord *__thiscall RankingCategoryRecordCopyConstructDeep(RankingCategoryRecord *this, const RankingCategoryRecord *source)'
$UID0003X4Comment = 'Compiler-generated implicit RankingCategoryRecord copy constructor: copies scalar, tm, title, footer, and score fields and deep-copies m_userEntries; source remains the class declaration and ordinary std::vector operations, with no standalone helper definition.'

function New-UID0003X4MutationRequests([string]$Database,[string]$Prefix) {
    if ([string]::IsNullOrWhiteSpace($Database)) { throw "$Prefix database is empty" }
    [ordered]@{
        ID01Dry = [ordered]@{
            jsonrpc='2.0'; id="$Prefix-id01-dry"; method='tools/call'
            params=[ordered]@{ name='rename'; arguments=[ordered]@{
                database=$Database
                batch=[ordered]@{
                    func=[ordered]@{ addr='0x45d420'; name='RankingCategoryRecordCopyConstructDeep' }
                    stop_on_error=$true; dry_run=$true; allow_overwrite=$false; pure=$true
                }
            }}
        }
        ID01Actual = [ordered]@{
            jsonrpc='2.0'; id="$Prefix-id01-actual"; method='tools/call'
            params=[ordered]@{ name='rename'; arguments=[ordered]@{
                database=$Database
                batch=[ordered]@{
                    func=[ordered]@{ addr='0x45d420'; name='RankingCategoryRecordCopyConstructDeep' }
                    stop_on_error=$true; dry_run=$false; allow_overwrite=$false; pure=$true
                }
            }}
        }
        ID02Actual = [ordered]@{
            jsonrpc='2.0'; id="$Prefix-id02-actual"; method='tools/call'
            params=[ordered]@{ name='set_type'; arguments=[ordered]@{
                database=$Database
                edits=[ordered]@{ addr='0x45d420'; kind='function'; signature=$UID0003X4Signature }
            }}
        }
        ID03Actual = [ordered]@{
            jsonrpc='2.0'; id="$Prefix-id03-actual"; method='tools/call'
            params=[ordered]@{ name='set_repeatable_comments'; arguments=[ordered]@{
                database=$Database
                items=[ordered]@{ addr='0x45d420'; comment=$UID0003X4Comment }
            }}
        }
    }
}

function Get-UID0003X4StructuredResult($Request,$Envelope,[string]$Label) {
    if ($null -eq $Envelope -or [string]$Envelope.jsonrpc -cne '2.0' -or [string]$Envelope.id -cne [string]$Request.id -or
        $null -ne $Envelope.error -or $null -eq $Envelope.result -or $Envelope.result.isError -eq $true -or
        $null -eq $Envelope.result.structuredContent) { throw "$Label response envelope failed" }
    return $Envelope.result.structuredContent
}

function Test-UID0003X4Property($Object,[string]$Name) {
    return $null -ne $Object.PSObject.Properties[$Name]
}

function Assert-UID0003X4ID01Dry($Request,$Envelope) {
    $sc = Get-UID0003X4StructuredResult $Request $Envelope 'ID01 dry'
    $rows = @($sc.func)
    if ($rows.Count -ne 1 -or [string]$rows[0].addr -cne '0x45d420' -or [string]$rows[0].old -cne 'sub_45D420' -or
        [string]$rows[0].name -cne 'RankingCategoryRecordCopyConstructDeep' -or $rows[0].dry_run -ne $true -or
        (Test-UID0003X4Property $rows[0] 'error') -or (Test-UID0003X4Property $rows[0] 'dir') -or
        (Test-UID0003X4Property $rows[0] 'dir_error')) { throw 'ID01 dry function row mismatch' }
    $s = $sc.summary
    if ([int]$s.total -ne 1 -or [int]$s.ok -ne 1 -or [int]$s.failed -ne 0 -or $s.stopped -ne $false -or
        $s.dry_run -ne $true -or $s.stop_on_error -ne $true -or
        (Test-UID0003X4Property $s 'allow_overwrite') -or (Test-UID0003X4Property $s 'stopped_at')) {
        throw 'ID01 dry summary mismatch'
    }
}

function Assert-UID0003X4ID01Actual($Request,$Envelope) {
    $sc = Get-UID0003X4StructuredResult $Request $Envelope 'ID01 actual'
    $rows = @($sc.func)
    if ($rows.Count -ne 1 -or [string]$rows[0].addr -cne '0x45d420' -or [string]$rows[0].old -cne 'sub_45D420' -or
        [string]$rows[0].name -cne 'RankingCategoryRecordCopyConstructDeep' -or
        (Test-UID0003X4Property $rows[0] 'dry_run') -or (Test-UID0003X4Property $rows[0] 'error') -or
        (Test-UID0003X4Property $rows[0] 'dir') -or (Test-UID0003X4Property $rows[0] 'dir_error')) {
        throw 'ID01 actual function row mismatch'
    }
    $s = $sc.summary
    if ([int]$s.total -ne 1 -or [int]$s.ok -ne 1 -or [int]$s.failed -ne 0 -or $s.stopped -ne $false -or
        $s.stop_on_error -ne $true -or (Test-UID0003X4Property $s 'dry_run') -or
        (Test-UID0003X4Property $s 'allow_overwrite') -or (Test-UID0003X4Property $s 'stopped_at')) {
        throw 'ID01 actual summary mismatch'
    }
}

function Assert-UID0003X4ID02Actual($Request,$Envelope) {
    $sc = Get-UID0003X4StructuredResult $Request $Envelope 'ID02 actual'
    $rows = @($sc.result)
    if ($rows.Count -ne 1 -or [string]$rows[0].kind -cne 'function' -or $rows[0].ok -ne $true -or
        [string]$rows[0].edit.addr -cne '0x45d420' -or [string]$rows[0].edit.kind -cne 'function' -or
        [string]$rows[0].edit.signature -cne $UID0003X4Signature -or (Test-UID0003X4Property $rows[0] 'error')) {
        throw 'ID02 actual response mismatch'
    }
}

function Assert-UID0003X4ID03Actual($Request,$Envelope) {
    $sc = Get-UID0003X4StructuredResult $Request $Envelope 'ID03 actual'
    $rows = @($sc.result)
    if ($rows.Count -ne 1 -or [string]$rows[0].addr -cne '0x45d420' -or (Test-UID0003X4Property $rows[0] 'error')) {
        throw 'ID03 actual response mismatch'
    }
}

$D0Requests = New-UID0003X4MutationRequests $D0_DB 'uid0003x4-d0'
$TxnRequests = New-UID0003X4MutationRequests $TXN_DB 'uid0003x4-txn'
~~~

## Removed Block R007

- SHA256: `6D9B9C4CDE9B6180D8629B18609CAE812C885A9EEF8DEB194AD28C10891DD65B`
- Language: `powershell`
- Bytes: `15534`
- First recovered timestamp: `2026-08-07T00:01:27.052Z`
- Session provenance: rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 194621 (2026-08-07T00:01:27.052Z); rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 194622 (2026-08-07T00:01:27.106Z)

~~~powershell
function New-UID0003X4ToolRequest([object]$RequestId,[string]$Name,$Arguments) {
    if ($null -eq $RequestId -or [string]::IsNullOrWhiteSpace($Name) -or $null -eq $Arguments) { throw 'Tool request is incomplete' }
    [ordered]@{ jsonrpc='2.0'; id=$RequestId; method='tools/call'; params=[ordered]@{ name=$Name; arguments=$Arguments } }
}

function Get-UID0003X4ToolStructuredContent($Request,$Envelope,[string]$Label) {
    Assert-UID0003X4JsonRpcCorrelation $Request $Envelope $Label
    if ($null -ne $Envelope.error -or $null -eq $Envelope.result -or $Envelope.result.isError -eq $true -or
        $null -eq $Envelope.result.structuredContent) { throw "$Label tool response failed" }
    return $Envelope.result.structuredContent
}

function New-UID0003X4IdbListRequest([object]$RequestId) {
    New-UID0003X4ToolRequest $RequestId 'idb_list' ([ordered]@{})
}

function Assert-UID0003X4LoopbackEndpoint($Endpoint,[string]$Label) {
    if ($null -eq $Endpoint -or [string]$Endpoint.host -cne '127.0.0.1' -or
        $Endpoint.port -isnot [int] -or [int]$Endpoint.port -lt 1 -or [int]$Endpoint.port -gt 65535) {
        throw "$Label is not a literal 127.0.0.1 integer-port endpoint"
    }
}

function Assert-UID0003X4IdbListBinding($Request,$Envelope,$OpenRecord,$RuntimeProof,[string]$ExpectedPath) {
    $sc = Get-UID0003X4ToolStructuredContent $Request $Envelope "$($OpenRecord.Role) idb_list"
    $rows = @($sc.sessions)
    if ($sc.count -isnot [int] -or [int]$sc.count -ne $rows.Count) { throw 'idb_list count/type mismatch' }
    $matches = @($rows | Where-Object { $_.session_id -is [string] -and [string]$_.session_id -ceq [string]$OpenRecord.Database })
    if ($matches.Count -ne 1) { throw "$($OpenRecord.Role) returned session is not unique in idb_list" }
    $row = $matches[0]
    foreach ($field in @('session_id','input_path','filename','created_at','last_accessed','is_analyzing','metadata','is_active','backend','owned','adopted','pid','worker_pid')) {
        if ($null -eq $row.PSObject.Properties[$field]) { throw "$($OpenRecord.Role) idb_list row omitted $field" }
    }
    if ($row.backend -isnot [string] -or [string]$row.backend -cne 'worker' -or
        $row.owned -isnot [bool] -or $row.owned -ne $true -or
        $row.is_active -isnot [bool] -or $row.is_active -ne $true -or
        $row.is_analyzing -isnot [bool] -or $row.is_analyzing -ne $false -or
        $row.pid -isnot [int] -or [int]$row.pid -le 0 -or
        $row.worker_pid -isnot [int] -or [int]$row.worker_pid -le 0 -or
        -not (Test-UID0003X4ExactPath ([string]$row.input_path) $ExpectedPath)) {
        throw "$($OpenRecord.Role) idb_list state/path mismatch"
    }
    if ($null -eq $RuntimeProof.Selected) { throw "$($OpenRecord.Role) runtime proof has no selected session" }
    $selected = $RuntimeProof.Selected
    Assert-UID0003X4LoopbackEndpoint $selected.Entry.route "$($OpenRecord.Role) route"
    Assert-UID0003X4LoopbackEndpoint $selected.Entry.attestation.worker.endpoint "$($OpenRecord.Role) worker endpoint"
    if ([int]$row.pid -ne [int]$selected.Supervisor.redirector_pid -or
        [int]$row.pid -ne [int]$selected.Supervisor.registered_pid -or
        [int]$row.worker_pid -ne [int]$selected.Worker.Process.pid -or
        [int]$selected.Worker.Process.parent_pid -ne [int]$row.pid) {
        throw "$($OpenRecord.Role) idb_list redirector/registered/worker/parent edge mismatch"
    }
    if ([string]$OpenRecord.Session.session_id -cne [string]$row.session_id -or
        -not (Test-UID0003X4ExactPath ([string]$OpenRecord.Session.input_path) ([string]$row.input_path)) -or
        -not (Test-UID0003X4ExactPath ([string]$selected.Supervisor.canonical_path) $ExpectedPath) -or
        -not (Test-UID0003X4ExactPath ([string]$selected.WorkerSession.canonical_path) $ExpectedPath)) {
        throw "$($OpenRecord.Role) open/list/runtime canonical session binding mismatch"
    }
    [pscustomobject]@{ Request=$Request; Envelope=$Envelope; Row=$row; Runtime=$RuntimeProof }
}

function Complete-UID0003X4RoleBinding($OpenRecord,[string]$ExpectedPath,[string]$Prefix,[scriptblock]$SendMcpJsonRpc,$FrozenListenerBinding) {
    $runtimeRequest = New-UID0003X4RuntimeAttestationRequest "$Prefix-runtime" ([string]$OpenRecord.Database) $ExpectedPath
    $runtimeEnvelope = & $SendMcpJsonRpc $runtimeRequest
    $runtime = Assert-UID0003X4RuntimeAttestation $runtimeRequest $runtimeEnvelope ([string]$OpenRecord.Role) ([string]$OpenRecord.Database) $ExpectedPath $FrozenListenerBinding
    $listRequest = New-UID0003X4IdbListRequest "$Prefix-idb-list"
    $listEnvelope = & $SendMcpJsonRpc $listRequest
    $list = Assert-UID0003X4IdbListBinding $listRequest $listEnvelope $OpenRecord $runtime $ExpectedPath
    [pscustomobject]@{ Open=$OpenRecord; Runtime=$runtime; List=$list }
}

function New-UID0003X4ReadbackRequests([string]$Database,[string]$Prefix) {
    if ([string]::IsNullOrWhiteSpace($Database)) { throw "$Prefix readback database is empty" }
    $xrefQueries = @()
    foreach ($spec in @(
        @('0x45d420','to','code'),@('0x45d420','to','data'),@('0x45d370','to','code'),@('0x45d370','to','data'),
        @('0x45d491','from','code'),@('0x45d419','to','code'),@('0x45d419','to','data'),
        @('0x45d4f8','to','code'),@('0x45d4f8','to','data')
    )) {
        $xrefQueries += [ordered]@{ addr=$spec[0]; direction=$spec[1]; xref_type=$spec[2]; offset=0; count=1000; include_fn=$true; dedup=$true; sort_by='addr'; descending=$false }
    }
    $typeQueries = @()
    foreach ($name in @('RankingCategoryRecord','RankingUserEntry','RankingUserEntryVectorStorage','RankingCategoryRecordVectorStorage')) {
        $typeQueries += [ordered]@{ filter="/^$name$/"; kind='struct'; offset=0; count=2; sort_by='ordinal'; descending=$false; include_decl=$true; include_members=$true; max_members=30; include_relationships=$true }
    }
    [ordered]@{
        Health = New-UID0003X4ToolRequest "$Prefix-health" 'server_health' ([ordered]@{ database=$Database })
        Lookup = New-UID0003X4ToolRequest "$Prefix-lookup" 'lookup_funcs' ([ordered]@{ database=$Database; queries=@(
            '0x45d420','0x45d421','0x45d491','0x45d4f7','0x45d4f8','sub_45D420','RankingCategoryRecordCopyConstructDeep',
            '0x45d370','0x45c2a0','0x45c560','0x45cf50','0x45d660','0x45d419'
        ) })
        Frame = New-UID0003X4ToolRequest "$Prefix-frame" 'stack_frame' ([ordered]@{ database=$Database; addrs=@('0x45d420','0x45d370') })
        Comments = New-UID0003X4ToolRequest "$Prefix-comments" 'get_comments' ([ordered]@{ database=$Database; addrs=@('0x45d419','0x45d420','0x45d421','0x45d491','0x45d4f7','0x45d4f8','0x45d370') })
        Items = New-UID0003X4ToolRequest "$Prefix-items" 'inspect_items' ([ordered]@{ database=$Database; addrs=@('0x45d419','0x45d420','0x45d421','0x45d491','0x45d4f7','0x45d4f8','0x45d370') })
        Bytes = New-UID0003X4ToolRequest "$Prefix-bytes" 'get_bytes' ([ordered]@{ database=$Database; regions=@(
            [ordered]@{addr='0x45d419';size=7},[ordered]@{addr='0x45d420';size=216},
            [ordered]@{addr='0x45d4f8';size=8},[ordered]@{addr='0x45d370';size=169}
        ) })
        Xrefs = New-UID0003X4ToolRequest "$Prefix-xrefs" 'xref_query' ([ordered]@{ database=$Database; queries=$xrefQueries })
        Find = New-UID0003X4ToolRequest "$Prefix-find" 'find_bytes' ([ordered]@{ database=$Database; patterns=@('20 D4 45 00','20 D4 05 00','20 C8 05 00'); limit=1000; offset=0 })
        TypeQuery = New-UID0003X4ToolRequest "$Prefix-type-query" 'type_query' ([ordered]@{ database=$Database; queries=$typeQueries })
        TypeInspect = New-UID0003X4ToolRequest "$Prefix-type-inspect" 'type_inspect' ([ordered]@{ database=$Database; queries=@(
            [ordered]@{name='RankingCategoryRecord';include_members=$true;max_members=30},
            [ordered]@{name='RankingUserEntry';include_members=$true;max_members=30},
            [ordered]@{name='RankingUserEntryVectorStorage';include_members=$true;max_members=30},
            [ordered]@{name='RankingCategoryRecordVectorStorage';include_members=$true;max_members=30}
        ) })
    }
}

function Invoke-UID0003X4ReadbackRequests($Requests,[scriptblock]$SendMcpJsonRpc) {
    $result = [ordered]@{}
    foreach ($name in @('Health','Lookup','Frame','Comments','Items','Bytes','Xrefs','Find','TypeQuery','TypeInspect')) {
        if ($null -eq $Requests[$name]) { throw "Readback request missing: $name" }
        $request = $Requests[$name]
        $envelope = & $SendMcpJsonRpc $request
        $structured = Get-UID0003X4ToolStructuredContent $request $envelope "readback $name"
        $result[$name] = [pscustomobject]@{ Request=$request; Envelope=$envelope; StructuredContent=$structured }
    }
    return $result
}

function Get-UID0003X4CanonicalJson($Object) { ConvertTo-Json $Object -Depth 100 -Compress }
function Get-UID0003X4JsonSHA256($Object) {
    $bytes = [Text.Encoding]::UTF8.GetBytes((Get-UID0003X4CanonicalJson $Object))
    ([BitConverter]::ToString([Security.Cryptography.SHA256]::HashData($bytes))).Replace('-','')
}

function Assert-UID0003X4JsonContains([string]$Json,[string[]]$Required,[string]$Label) {
    foreach ($literal in $Required) { if (-not $Json.Contains($literal,[StringComparison]::Ordinal)) { throw "$Label omitted literal $literal" } }
}

function Assert-UID0003X4ReadbackBundle($Bundle,[ValidateSet('N0','N1','N2','FINAL')][string]$State,[string]$ExpectedPath,$FrozenProtection) {
    foreach ($name in @('Health','Lookup','Frame','Comments','Items','Bytes','Xrefs','Find','TypeQuery','TypeInspect')) {
        if ($null -eq $Bundle[$name] -or $null -eq $Bundle[$name].StructuredContent) { throw "$State readback omitted $name" }
    }
    $health = $Bundle.Health.StructuredContent
    if ([string]$health.status -cne 'ok' -or -not (Test-UID0003X4ExactPath ([string]$health.idb_path) $ExpectedPath) -or
        [int64]$health.image_base -ne 0x400000) { throw "$State health/path/image-base mismatch" }
    $lookupJson = Get-UID0003X4CanonicalJson $Bundle.Lookup.StructuredContent
    $frameJson = Get-UID0003X4CanonicalJson $Bundle.Frame.StructuredContent
    $commentJson = Get-UID0003X4CanonicalJson $Bundle.Comments.StructuredContent
    $itemJson = Get-UID0003X4CanonicalJson $Bundle.Items.StructuredContent
    $byteJson = Get-UID0003X4CanonicalJson $Bundle.Bytes.StructuredContent
    $xrefJson = Get-UID0003X4CanonicalJson $Bundle.Xrefs.StructuredContent
    $findJson = Get-UID0003X4CanonicalJson $Bundle.Find.StructuredContent
    $typeQueryJson = Get-UID0003X4CanonicalJson $Bundle.TypeQuery.StructuredContent
    $typeInspectJson = Get-UID0003X4CanonicalJson $Bundle.TypeInspect.StructuredContent
    $expectedName = if ($State -eq 'N0') { 'sub_45D420' } else { 'RankingCategoryRecordCopyConstructDeep' }
    $expectedType = if (@('N2','FINAL') -contains $State) { $UID0003X4Signature } else { 'char *__thiscall sub_45D420(char *this, int)' }
    $expectedArg = if (@('N2','FINAL') -contains $State) { 'source' } else { 'arg_0' }
    Assert-UID0003X4JsonContains $lookupJson @('0x45d420','0x45d4f8',$expectedName,'0x45d370','0x45c2a0','0x45c560','0x45cf50','0x45d660') "$State lookup"
    Assert-UID0003X4JsonContains $frameJson @('0x45d420','var_4','__saved_registers','__return_address',$expectedArg,'0x45d370') "$State frame"
    Assert-UID0003X4JsonContains $itemJson @('0x45d419','0x45d420','0x45d491','0x45d4f8','0x45d370') "$State items"
    Assert-UID0003X4JsonContains $byteJson @('0x45d419','0x45d420','0x45d4f8','0x45d370') "$State bytes"
    Assert-UID0003X4JsonContains $xrefJson @('0x45c4f1','0x45c7cb','0x45d07b','0x45d0a9','0x45d6a8','0x45d491') "$State xrefs"
    Assert-UID0003X4JsonContains $findJson @('20 D4 45 00','20 D4 05 00','20 C8 05 00') "$State pointer negatives"
    Assert-UID0003X4JsonContains $typeQueryJson @('RankingCategoryRecord','RankingUserEntry','RankingUserEntryVectorStorage','RankingCategoryRecordVectorStorage','962','983','986','992','688','76','12') "$State type query"
    Assert-UID0003X4JsonContains $typeInspectJson @('RankingCategoryRecord','RankingUserEntry','RankingUserEntryVectorStorage','RankingCategoryRecordVectorStorage','15','4','3') "$State type inspect"
    if (-not $lookupJson.Contains($expectedType,[StringComparison]::Ordinal)) { throw "$State target function type mismatch" }
    if ($State -eq 'FINAL') {
        if (-not $commentJson.Contains($UID0003X4Comment,[StringComparison]::Ordinal)) { throw 'FINAL exact function-repeatable comment echo/readback missing' }
    } elseif ($commentJson.Contains($UID0003X4Comment,[StringComparison]::Ordinal)) { throw "$State acquired the final comment too early" }
    foreach ($forbidden in @('error','truncated')) {
        if ($byteJson.Contains('"'+$forbidden+'"',[StringComparison]::OrdinalIgnoreCase) -or
            $xrefJson.Contains('"'+$forbidden+'"',[StringComparison]::OrdinalIgnoreCase) -or
            $typeInspectJson.Contains('"'+$forbidden+'"',[StringComparison]::OrdinalIgnoreCase)) { throw "$State contains a forbidden $forbidden result" }
    }
    $protection = [ordered]@{
        Bytes=Get-UID0003X4JsonSHA256 $Bundle.Bytes.StructuredContent
        Xrefs=Get-UID0003X4JsonSHA256 $Bundle.Xrefs.StructuredContent
        Find=Get-UID0003X4JsonSHA256 $Bundle.Find.StructuredContent
        TypeQuery=Get-UID0003X4JsonSHA256 $Bundle.TypeQuery.StructuredContent
        TypeInspect=Get-UID0003X4JsonSHA256 $Bundle.TypeInspect.StructuredContent
    }
    if ($null -ne $FrozenProtection) {
        foreach ($name in $protection.Keys) { if ([string]$protection[$name] -cne [string]$FrozenProtection[$name]) { throw "$State protected full-response drift: $name" } }
    }
    return $protection
}

function Invoke-UID0003X4MutationSequence($Requests,[scriptblock]$Attest,[scriptblock]$SendMcpJsonRpc,[string]$Database,[string]$ExpectedPath,[string]$Prefix) {
    $readRequests = New-UID0003X4ReadbackRequests $Database "$Prefix-n0"
    $n0 = Invoke-UID0003X4ReadbackRequests $readRequests $SendMcpJsonRpc
    $protection = Assert-UID0003X4ReadbackBundle $n0 N0 $ExpectedPath $null
    $sequence = @(
        [pscustomobject]@{Key='ID01Dry';State='N0';Assert={param($r,$e) Assert-UID0003X4ID01Dry $r $e}},
        [pscustomobject]@{Key='ID01Actual';State='N1';Assert={param($r,$e) Assert-UID0003X4ID01Actual $r $e}},
        [pscustomobject]@{Key='ID02Actual';State='N2';Assert={param($r,$e) Assert-UID0003X4ID02Actual $r $e}},
        [pscustomobject]@{Key='ID03Actual';State='FINAL';Assert={param($r,$e) Assert-UID0003X4ID03Actual $r $e}}
    )
    $journal = @()
    foreach ($step in $sequence) {
        $attestation = & $Attest "pre-$($step.Key)"
        $request = $Requests[$step.Key]
        if ([string]$request.params.arguments.database -cne $Database) { throw "$Prefix $($step.Key) database injection mismatch" }
        $envelope = & $SendMcpJsonRpc $request
        & $step.Assert $request $envelope
        $postRequests = New-UID0003X4ReadbackRequests $Database "$Prefix-post-$($step.Key)"
        $post = Invoke-UID0003X4ReadbackRequests $postRequests $SendMcpJsonRpc
        Assert-UID0003X4ReadbackBundle $post $step.State $ExpectedPath $protection | Out-Null
        $postAttestation = & $Attest "post-$($step.Key)"
        $journal += [pscustomobject]@{ Step=$step.Key; Request=$request; Envelope=$envelope; Before=$attestation; Readback=$post; After=$postAttestation }
    }
    [pscustomobject]@{ N0=$n0; Protection=$protection; Journal=$journal; Final=$journal[-1].Readback }
}
~~~

## Removed Block R008

- SHA256: `97B13D9B32B2EAC25FF0D3384BC4BBEB1502E42B77837F862D70AC2BBBFBC399`
- Language: `powershell`
- Bytes: `15935`
- First recovered timestamp: `2026-08-07T00:02:50.767Z`
- Session provenance: rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 194633 (2026-08-07T00:02:50.767Z); rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 194634 (2026-08-07T00:02:50.826Z)

~~~powershell
$script:UID0003X4SaveIssued = $false

function New-UID0003X4SaveRequest([string]$Database) {
    New-UID0003X4ToolRequest 'uid0003x4-sole-save' 'idb_save' ([ordered]@{ database=$Database; path=$UID0003X4CanonicalPath })
}

function Get-UID0003X4SaveClassification($Request,$Envelope,$TransportFailure) {
    if ($null -ne $TransportFailure -or $null -eq $Envelope) {
        return [pscustomobject]@{ Class='INDETERMINATE'; Reason='transport/timeout/disconnect/no-envelope'; Request=$Request; Envelope=$Envelope; Error=$TransportFailure }
    }
    try { Assert-UID0003X4JsonRpcCorrelation $Request $Envelope 'sole idb_save' }
    catch { return [pscustomobject]@{ Class='INDETERMINATE'; Reason='json-rpc-correlation'; Request=$Request; Envelope=$Envelope; Error=$_.Exception.Message } }
    if ($null -ne $Envelope.error -or $null -eq $Envelope.result -or $Envelope.result.isError -eq $true -or
        $null -eq $Envelope.result.structuredContent) {
        return [pscustomobject]@{ Class='INDETERMINATE'; Reason='error/missing structured result'; Request=$Request; Envelope=$Envelope; Error=$Envelope.error }
    }
    $sc = $Envelope.result.structuredContent
    if ($null -eq $sc.PSObject.Properties['ok'] -or $sc.ok -isnot [bool] -or
        $null -eq $sc.PSObject.Properties['path']) {
        return [pscustomobject]@{ Class='INDETERMINATE'; Reason='malformed ok/path types'; Request=$Request; Envelope=$Envelope; Error=$null }
    }
    if ($sc.path -isnot [string] -or -not (Test-UID0003X4ExactPath ([string]$sc.path) $UID0003X4CanonicalPath)) {
        return [pscustomobject]@{ Class='INDETERMINATE'; Reason='save path mismatch'; Request=$Request; Envelope=$Envelope; Error=$null }
    }
    $hasError = $null -ne $sc.PSObject.Properties['error']
    if ($sc.ok -eq $true) {
        if ($hasError -and -not [string]::IsNullOrEmpty([string]$sc.error)) {
            return [pscustomobject]@{ Class='INDETERMINATE'; Reason='success with nonempty error'; Request=$Request; Envelope=$Envelope; Error=$sc.error }
        }
        return [pscustomobject]@{ Class='SUCCESS'; Reason='literal ok true/exact path/no error'; Request=$Request; Envelope=$Envelope; Error=$null }
    }
    if (-not $hasError -or $sc.error -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$sc.error)) {
        return [pscustomobject]@{ Class='INDETERMINATE'; Reason='negative result without exact error'; Request=$Request; Envelope=$Envelope; Error=$null }
    }
    return [pscustomobject]@{ Class='EXPLICIT_FAILURE'; Reason='literal ok false/exact path/nonempty error'; Request=$Request; Envelope=$Envelope; Error=[string]$sc.error }
}

function Invoke-UID0003X4SoleSave([string]$Database,[scriptblock]$SendMcpJsonRpc) {
    if ($script:UID0003X4SaveIssued) { throw 'The UID0003X4 save was already attempted; retry is forbidden' }
    $script:UID0003X4SaveIssued = $true
    $request = New-UID0003X4SaveRequest $Database
    $envelope = $null
    $failure = $null
    try { $envelope = & $SendMcpJsonRpc $request } catch { $failure = $_.Exception.ToString() }
    Get-UID0003X4SaveClassification $request $envelope $failure
}

function Get-UID0003X4ProcessCreation100ns([int]$Pid) {
    $process = Get-Process -Id $Pid -ErrorAction Stop
    [int64]$process.StartTime.ToUniversalTime().ToFileTimeUtc()
}

function Stop-UID0003X4ExactProcessGeneration([int]$Pid,[int64]$Creation100ns,[string]$Label) {
    $actual = Get-UID0003X4ProcessCreation100ns $Pid
    if ($actual -ne $Creation100ns) { throw "$Label PID generation changed before retirement" }
    Stop-Process -Id $Pid -Force -ErrorAction Stop
    $deadline = [datetime]::UtcNow.AddSeconds(30)
    do {
        Start-Sleep -Milliseconds 100
        $current = Get-Process -Id $Pid -ErrorAction SilentlyContinue
        if ($null -eq $current) { return }
        if ([int64]$current.StartTime.ToUniversalTime().ToFileTimeUtc() -ne $Creation100ns) { throw "$Label PID was reused during retirement" }
    } while ([datetime]::UtcNow -lt $deadline)
    throw "$Label exact process generation did not retire"
}

function Assert-UID0003X4RetirementRows($ListStructured,$RuntimeStructured,[string]$Database,[int[]]$RetiredPids) {
    $active = @($ListStructured.sessions | Where-Object { [string]$_.session_id -ceq $Database -and $_.is_active -eq $true })
    if ($active.Count -ne 0) { throw 'Retired database remains active in idb_list' }
    $stale = @($ListStructured.sessions | Where-Object { [string]$_.session_id -ceq $Database })
    foreach ($row in $stale) {
        if ($row.is_active -ne $false -or ([int]$row.pid -gt 0 -and $RetiredPids -notcontains [int]$row.pid) -or
            ([int]$row.worker_pid -gt 0 -and $RetiredPids -notcontains [int]$row.worker_pid)) {
            throw 'Retired idb_list row is not exact inactive history'
        }
    }
    foreach ($entry in @($RuntimeStructured.workers)) {
        foreach ($row in @($entry.supervisor_sessions)) {
            if ([string]$row.session_id -ceq $Database) { throw 'Retired database remains in an active runtime worker' }
        }
    }
    $inactive = @($RuntimeStructured.inactive_sessions | Where-Object { [string]$_.session_id -ceq $Database })
    if ($inactive.Count -gt 1) { throw 'Retired database has duplicate inactive runtime rows' }
    foreach ($pid in $RetiredPids) { if ($null -ne (Get-Process -Id $pid -ErrorAction SilentlyContinue)) { throw "Retired PID remains present: $pid" } }
}

function Retire-UID0003X4BoundRole($Binding,[string]$ExpectedPath,[string]$Prefix,[scriptblock]$SendMcpJsonRpc,$FrozenListenerBinding) {
    $selected = $Binding.Runtime.Selected
    if ($null -eq $selected) { throw 'Cannot retire a role without selected runtime binding' }
    $workerPid = [int]$selected.Worker.Process.pid
    $workerCreation = [int64]$selected.Worker.Process.creation_time_100ns
    $redirectorPid = [int]$selected.Supervisor.redirector_pid
    $redirectorCreation = Get-UID0003X4ProcessCreation100ns $redirectorPid
    if ([int]$selected.Supervisor.registered_pid -ne $redirectorPid -or [int]$selected.Worker.Process.parent_pid -ne $redirectorPid) {
        throw 'Retirement process edge drifted'
    }
    Stop-UID0003X4ExactProcessGeneration $workerPid $workerCreation "$Prefix worker"
    Stop-UID0003X4ExactProcessGeneration $redirectorPid $redirectorCreation "$Prefix redirector"
    $quiescentRequest = New-UID0003X4QuiescentRuntimeAttestationRequest "$Prefix-quiescent-runtime"
    $quiescentEnvelope = & $SendMcpJsonRpc $quiescentRequest
    $quiescent = Assert-UID0003X4RuntimeAttestation $quiescentRequest $quiescentEnvelope "$Prefix-retired" '' '' $FrozenListenerBinding ([string]$Binding.Open.Database)
    $listRequest = New-UID0003X4IdbListRequest "$Prefix-quiescent-list"
    $listEnvelope = & $SendMcpJsonRpc $listRequest
    $listSc = Get-UID0003X4ToolStructuredContent $listRequest $listEnvelope "$Prefix quiescent idb_list"
    Assert-UID0003X4RetirementRows $listSc $quiescent.StructuredContent ([string]$Binding.Open.Database) @($workerPid,$redirectorPid)
    $probe = [IO.FileStream]::new((Get-UID0003X4NormalizedExistingPath $ExpectedPath),[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
    try { if ([int64]$probe.Length -le 0) { throw 'Retired role exclusive file probe is empty' } } finally { $probe.Dispose() }
    [pscustomobject]@{ Database=$Binding.Open.Database; WorkerPID=$workerPid; RedirectorPID=$redirectorPid; Runtime=$quiescent; List=$listSc }
}

function Invoke-UID0003X4VerifierCycle(
    [string]$Role,[string]$PreferredSessionId,[ValidateSet('N0','FINAL')][string]$ExpectedState,
    $ExpectedTuple,[string]$Prefix,[scriptblock]$SendMcpJsonRpc,$FrozenListenerBinding
) {
    $open = Open-UID0003X4Role $Role "$Prefix-open" $UID0003X4CanonicalPath $PreferredSessionId $SendMcpJsonRpc
    $binding = Complete-UID0003X4RoleBinding $open $UID0003X4CanonicalPath $Prefix $SendMcpJsonRpc $FrozenListenerBinding
    $requests = New-UID0003X4ReadbackRequests ([string]$open.Database) "$Prefix-readback"
    $readback = Invoke-UID0003X4ReadbackRequests $requests $SendMcpJsonRpc
    Assert-UID0003X4ReadbackBundle $readback $ExpectedState $UID0003X4CanonicalPath $null | Out-Null
    $postRequest = New-UID0003X4RuntimeAttestationRequest "$Prefix-post-readback-runtime" ([string]$open.Database) $UID0003X4CanonicalPath
    $postEnvelope = & $SendMcpJsonRpc $postRequest
    Assert-UID0003X4RuntimeAttestation $postRequest $postEnvelope $Role ([string]$open.Database) $UID0003X4CanonicalPath $FrozenListenerBinding | Out-Null
    $retired = Retire-UID0003X4BoundRole $binding $UID0003X4CanonicalPath $Prefix $SendMcpJsonRpc $FrozenListenerBinding
    $tuple = Get-UID0003X4ClosedTuple $UID0003X4CanonicalPath
    Assert-UID0003X4Tuple $tuple $ExpectedTuple.ResolvedPath $ExpectedTuple "$Role closed tuple"
    [pscustomobject]@{ Open=$open; Binding=$binding; Readback=$readback; Retired=$retired; ClosedTuple=$tuple }
}

function Get-UID0003X4ClosedIdentityClass($Tuple,$P0,$CandidateS1) {
    if ([int64]$Tuple.Length -eq [int64]$P0.Length -and [int64]$Tuple.LastWriteTimeUtcTicks -eq [int64]$P0.LastWriteTimeUtcTicks -and [string]$Tuple.SHA256 -ceq [string]$P0.SHA256) { return 'P0' }
    if ($null -ne $CandidateS1 -and [int64]$Tuple.Length -eq [int64]$CandidateS1.Length -and
        [int64]$Tuple.LastWriteTimeUtcTicks -eq [int64]$CandidateS1.LastWriteTimeUtcTicks -and
        [string]$Tuple.SHA256 -ceq [string]$CandidateS1.SHA256) { return 'S1' }
    return 'THIRD_IDENTITY'
}

function Assert-UID0003X4RestoreAuthorization($FreshCanonical,$ClassifiedTuple,$P0) {
    if ($null -eq $ClassifiedTuple -or @('transaction-attributable-saved','transaction-attributable-failing-saved') -cnotcontains [string]$ClassifiedTuple.Classification) {
        throw 'Restore lacks a permitted transaction-attributable classification'
    }
    Assert-UID0003X4Tuple $FreshCanonical $P0.ResolvedPath $ClassifiedTuple 'restore authorization'
    if ((Get-UID0003X4ClosedIdentityClass $FreshCanonical $P0 $ClassifiedTuple) -ne 'S1') { throw 'Restore attempted against P0 or third identity' }
}

function Invoke-UID0003X4PersistenceDecision(
    $SaveClassification,$TxnBinding,$P0,[string]$Stamp,[scriptblock]$SendMcpJsonRpc,$FrozenListenerBinding
) {
    $retiredTxn = Retire-UID0003X4BoundRole $TxnBinding $UID0003X4CanonicalPath 'uid0003x4-retire-txn' $SendMcpJsonRpc $FrozenListenerBinding
    $closed = Get-UID0003X4ClosedTuple $UID0003X4CanonicalPath
    switch ([string]$SaveClassification.Class) {
        'SUCCESS' {
            if ((Get-UID0003X4ClosedIdentityClass $closed $P0 $null) -ne 'THIRD_IDENTITY') { throw 'Successful save did not create one exact non-P0 S1' }
            $s1 = $closed
            $verify = Invoke-UID0003X4VerifierCycle 'SUCCESS_VERIFY' "uid0003x4-success-verify-$Stamp" FINAL $s1 'uid0003x4-success-verify' $SendMcpJsonRpc $FrozenListenerBinding
            return [pscustomobject]@{ Class='SUCCESS'; S1=$s1; Verifiers=@($verify); RestoreTuple=New-UID0003X4ClassifiedRestoreTuple $s1 'transaction-attributable-saved' }
        }
        'EXPLICIT_FAILURE' {
            $identity = Get-UID0003X4ClosedIdentityClass $closed $P0 $null
            if ($identity -eq 'P0') {
                $verify = Invoke-UID0003X4VerifierCycle 'EXPLICIT_FAILURE_VERIFY' "uid0003x4-explicit-failure-verify-$Stamp" N0 $P0 'uid0003x4-explicit-failure-verify' $SendMcpJsonRpc $FrozenListenerBinding
                return [pscustomobject]@{ Class='EXPLICIT_FAILURE_P0'; S1=$null; Verifiers=@($verify); RestoreTuple=$null }
            }
            return [pscustomobject]@{ Class='EXPLICIT_FAILURE_SAVED'; S1=$closed; Verifiers=@(); RestoreTuple=New-UID0003X4ClassifiedRestoreTuple $closed 'transaction-attributable-failing-saved' }
        }
        'INDETERMINATE' {
            $identity = Get-UID0003X4ClosedIdentityClass $closed $P0 $null
            if ($identity -eq 'P0') {
                $verify = Invoke-UID0003X4VerifierCycle 'INDETERMINATE_VERIFY_1' "uid0003x4-indeterminate-verify-1-$Stamp" N0 $P0 'uid0003x4-indeterminate-p0' $SendMcpJsonRpc $FrozenListenerBinding
                return [pscustomobject]@{ Class='INDETERMINATE_P0_NO_CREDIT'; S1=$null; Verifiers=@($verify); RestoreTuple=$null }
            }
            $s1 = $closed
            $v1 = Invoke-UID0003X4VerifierCycle 'INDETERMINATE_VERIFY_1' "uid0003x4-indeterminate-verify-1-$Stamp" FINAL $s1 'uid0003x4-indeterminate-verify-1' $SendMcpJsonRpc $FrozenListenerBinding
            $v2 = Invoke-UID0003X4VerifierCycle 'INDETERMINATE_VERIFY_2' "uid0003x4-indeterminate-verify-2-$Stamp" FINAL $s1 'uid0003x4-indeterminate-verify-2' $SendMcpJsonRpc $FrozenListenerBinding
            return [pscustomobject]@{ Class='INDETERMINATE_S1_TWO_VERIFIERS'; S1=$s1; Verifiers=@($v1,$v2); RestoreTuple=New-UID0003X4ClassifiedRestoreTuple $s1 'transaction-attributable-saved' }
        }
        default { throw 'Malformed save classification cannot enter persistence decision' }
    }
}

function Assert-UID0003X4Throws([scriptblock]$Body,[string]$Label) {
    $threw = $false
    try { & $Body | Out-Null } catch { $threw = $true }
    if (-not $threw) { throw "Negative fixture unexpectedly passed: $Label" }
}

function Invoke-UID0003X4NegativeFixtures {
    $goodRequest = [pscustomobject]@{ jsonrpc='2.0'; id=17 }
    Assert-UID0003X4Throws { Assert-UID0003X4JsonRpcCorrelation $goodRequest ([pscustomobject]@{jsonrpc='2.0';id='17'}) 'fixture-id-type' } 'JSON-RPC numeric/string ID mismatch'
    Assert-UID0003X4Throws { Assert-UID0003X4LoopbackEndpoint ([pscustomobject]@{host='0.0.0.0';port=13337}) 'fixture-route' } 'non-loopback route'
    Assert-UID0003X4Throws { Assert-UID0003X4LoopbackEndpoint ([pscustomobject]@{host='127.0.0.1';port=0}) 'fixture-port' } 'invalid port'
    $badSchema = [pscustomobject]@{ jsonrpc='2.0'; id='fixture-schema'; result=[pscustomobject]@{ tools=@(
        [pscustomobject]@{name='runtime_attestation';inputSchema=[pscustomobject]@{type='object';required=@('expected_database');properties=[pscustomobject]@{
            expected_database=[pscustomobject]@{type='string';default='wrong'}
            expected_canonical_path=[pscustomobject]@{type='string';default=''}
            extra=[pscustomobject]@{type='string';default=''}
        }}}
    )}}
    Assert-UID0003X4Throws { Assert-UID0003X4PublicRuntimeTool ([pscustomobject]@{jsonrpc='2.0';id='fixture-schema'}) $badSchema } 'schema required/default/extra drift'
    Assert-UID0003X4Throws { Assert-UID0003X4ReadbackBundle ([ordered]@{}) N0 $UID0003X4CanonicalPath $null } 'missing readback bundle'
    $malformedSave = Get-UID0003X4SaveClassification ([pscustomobject]@{jsonrpc='2.0';id=19}) ([pscustomobject]@{
        jsonrpc='2.0';id=19;result=[pscustomobject]@{isError=$false;structuredContent=[pscustomobject]@{ok='true';path=$UID0003X4CanonicalPath}}
    }) $null
    if ([string]$malformedSave.Class -cne 'INDETERMINATE') { throw 'Malformed save outcome fixture was not rejected' }
    Assert-UID0003X4Throws { Assert-UID0003X4RetirementRows ([pscustomobject]@{sessions=@([pscustomobject]@{session_id='retired';is_active=$true;pid=1;worker_pid=2})}) ([pscustomobject]@{workers=@();inactive_sessions=@()}) 'retired' @(1,2) } 'active retired session'
    $p0Fixture = [pscustomobject]@{ResolvedPath='C:\fixture\canonical.i64';Length=10;LastWriteTimeUtcTicks=20;SHA256=('A'*64)}
    $thirdFixture = [pscustomobject]@{ResolvedPath='C:\fixture\canonical.i64';Length=10;LastWriteTimeUtcTicks=21;SHA256=('B'*64)}
    $classifiedFixture = [pscustomobject]@{Classification='transaction-attributable-saved';ResolvedPath='C:\fixture\canonical.i64';Length=10;LastWriteTimeUtcTicks=22;SHA256=('C'*64)}
    Assert-UID0003X4Throws { Assert-UID0003X4RestoreAuthorization $thirdFixture $classifiedFixture $p0Fixture } 'third-identity restore attempt'
    return 'NEGATIVE_FIXTURES_PASSED'
}

$UID0003X4NegativeFixtureResult = Invoke-UID0003X4NegativeFixtures
~~~

## Removed Block R009

- SHA256: `763595FD9C877FF8E6F2590FC6C1FC79297C578E54238827A780AFFDD356869A`
- Language: `powershell`
- Bytes: `50084`
- First recovered timestamp: `2026-08-07T01:55:54.230Z`
- Session provenance: rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 196300 (2026-08-07T01:55:54.230Z); rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 196301 (2026-08-07T01:55:54.284Z)

~~~powershell
if (-not ('UID0003X4SealedBlobV4' -as [type])) {
    Add-Type -TypeDefinition @'
using System;
using System.IO;

public sealed class UID0003X4SealedBlobV4 {
    public string Domain { get; private set; }
    public string CanonicalJson { get; private set; }
    public string SHA256 { get; private set; }
    public UID0003X4SealedBlobV4(string domain, string canonicalJson, string sha256) {
        if (String.IsNullOrWhiteSpace(domain) || canonicalJson == null || String.IsNullOrWhiteSpace(sha256)) throw new ArgumentException("SEALED_BLOB_INVALID");
        Domain = domain; CanonicalJson = canonicalJson; SHA256 = sha256;
    }
}

public sealed class UID0003X4RequestPlanV4 {
    public string Label { get; private set; }
    public string RequestJson { get; private set; }
    public string RequestSHA256 { get; private set; }
    public string ContractJson { get; private set; }
    public string ContractSHA256 { get; private set; }
    public string RequestIdKind { get; private set; }
    public string RequestIdCanonical { get; private set; }
    public string Method { get; private set; }
    public string ToolName { get; private set; }
    public string Database { get; private set; }
    public string ExpectedPath { get; private set; }
    public string PlanSHA256 { get; private set; }
    public UID0003X4RequestPlanV4(string label,string requestJson,string requestSHA256,string contractJson,string contractSHA256,string requestIdKind,string requestIdCanonical,string method,string toolName,string database,string expectedPath,string planSHA256) {
        Label=label;RequestJson=requestJson;RequestSHA256=requestSHA256;ContractJson=contractJson;ContractSHA256=contractSHA256;RequestIdKind=requestIdKind;RequestIdCanonical=requestIdCanonical;Method=method;ToolName=toolName;Database=database;ExpectedPath=expectedPath;PlanSHA256=planSHA256;
    }
}

public sealed class UID0003X4FileStateV4 {
    public string State { get; private set; }
    public string ResolvedPath { get; private set; }
    public long Length { get; private set; }
    public long LastWriteTimeUtcTicks { get; private set; }
    public string SHA256 { get; private set; }
    public string GenerationSHA256 { get; private set; }
    public UID0003X4FileStateV4(string state,string resolvedPath,long length,long lastWriteTimeUtcTicks,string sha256,string generationSHA256) {
        State=state;ResolvedPath=resolvedPath;Length=length;LastWriteTimeUtcTicks=lastWriteTimeUtcTicks;SHA256=sha256;GenerationSHA256=generationSHA256;
    }
}

public sealed class UID0003X4DiskStateV4 {
    public string State { get; private set; }
    public string FileGenerationSHA256 { get; private set; }
    public string ParentStateSHA256 { get; private set; }
    public string RuntimeBindingSHA256 { get; private set; }
    public string SaveReceiptSHA256 { get; private set; }
    public string VerifierReceiptSHA256 { get; private set; }
    public string StateSHA256 { get; private set; }
    public UID0003X4DiskStateV4(string state,string fileGenerationSHA256,string parentStateSHA256,string runtimeBindingSHA256,string saveReceiptSHA256,string verifierReceiptSHA256,string stateSHA256) {
        State=state;FileGenerationSHA256=fileGenerationSHA256;ParentStateSHA256=parentStateSHA256;RuntimeBindingSHA256=runtimeBindingSHA256;SaveReceiptSHA256=saveReceiptSHA256;VerifierReceiptSHA256=verifierReceiptSHA256;StateSHA256=stateSHA256;
    }
}

public sealed class UID0003X4RestoreAuthorityV4 {
    public string Classification { get; private set; }
    public string P1StateSHA256 { get; private set; }
    public string SaveReceiptSHA256 { get; private set; }
    public string VerifierReceiptSHA256 { get; private set; }
    public string AuthoritySHA256 { get; private set; }
    public UID0003X4RestoreAuthorityV4(string classification,string p1StateSHA256,string saveReceiptSHA256,string verifierReceiptSHA256,string authoritySHA256) {
        Classification=classification;P1StateSHA256=p1StateSHA256;SaveReceiptSHA256=saveReceiptSHA256;VerifierReceiptSHA256=verifierReceiptSHA256;AuthoritySHA256=authoritySHA256;
    }
}

public sealed class UID0003X4JournalIdentityV4 {
    public string AttemptId { get; private set; }
    public string Database { get; private set; }
    public string CanonicalPath { get; private set; }
    public string RequestIdKind { get; private set; }
    public string RequestIdCanonical { get; private set; }
    public string RequestPlanSHA256 { get; private set; }
    public string P0StateSHA256 { get; private set; }
    public string JournalPath { get; private set; }
    public string IdentitySHA256 { get; private set; }
    public UID0003X4JournalIdentityV4(string attemptId,string database,string canonicalPath,string requestIdKind,string requestIdCanonical,string requestPlanSHA256,string p0StateSHA256,string journalPath,string identitySHA256) {
        AttemptId=attemptId;Database=database;CanonicalPath=canonicalPath;RequestIdKind=requestIdKind;RequestIdCanonical=requestIdCanonical;RequestPlanSHA256=requestPlanSHA256;P0StateSHA256=p0StateSHA256;JournalPath=journalPath;IdentitySHA256=identitySHA256;
    }
}

public sealed class UID0003X4JournalAuthorityV4 : IDisposable {
    public UID0003X4JournalIdentityV4 Identity { get; private set; }
    public FileStream Stream { get; private set; }
    public bool Rehydrated { get; private set; }
    public string HandlePath { get; private set; }
    public UID0003X4JournalAuthorityV4(UID0003X4JournalIdentityV4 identity,FileStream stream,bool rehydrated,string handlePath) {
        Identity=identity;Stream=stream;Rehydrated=rehydrated;HandlePath=handlePath;
    }
    public void Dispose() { if (Stream != null) { Stream.Dispose(); Stream=null; } }
}

public sealed class UID0003X4TransportReceiptV4 {
    public UID0003X4RequestPlanV4 Plan { get; private set; }
    public string RawResponse { get; private set; }
    public string ResponseSHA256 { get; private set; }
    public UID0003X4TransportReceiptV4(UID0003X4RequestPlanV4 plan,string rawResponse,string responseSHA256) { Plan=plan;RawResponse=rawResponse;ResponseSHA256=responseSHA256; }
}
'@
}

function ConvertTo-UID0003X4CanonicalNodeV4($Value) {
    if ($null -eq $Value) { return $null }
    if ($Value -is [Collections.IDictionary]) {
        $names = @($Value.Keys | ForEach-Object { [string]$_ })
        [Array]::Sort($names,[StringComparer]::Ordinal)
        $out = [ordered]@{}
        foreach ($name in $names) { $out[$name] = ConvertTo-UID0003X4CanonicalNodeV4 $Value[$name] }
        return $out
    }
    if ($Value -is [Collections.IList] -and $Value -isnot [string]) {
        $items = New-Object Collections.ArrayList
        foreach ($item in $Value) { [void]$items.Add((ConvertTo-UID0003X4CanonicalNodeV4 $item)) }
        return ,$items.ToArray()
    }
    if ($Value -is [psobject] -and $Value.GetType().FullName -eq 'System.Management.Automation.PSCustomObject') {
        $names = @($Value.PSObject.Properties.Name)
        [Array]::Sort($names,[StringComparer]::Ordinal)
        $out = [ordered]@{}
        foreach ($name in $names) { $out[$name] = ConvertTo-UID0003X4CanonicalNodeV4 $Value.$name }
        return $out
    }
    return $Value
}

function Get-UID0003X4CanonicalJsonV4($Value) {
    ConvertTo-Json (ConvertTo-UID0003X4CanonicalNodeV4 $Value) -Depth 100 -Compress
}

function New-UID0003X4SealedBlobV4([string]$Domain,$Value) {
    if ([string]::IsNullOrWhiteSpace($Domain)) { throw 'SEALED_BLOB_DOMAIN_EMPTY' }
    $json = Get-UID0003X4CanonicalJsonV4 $Value
    $digest = Get-UID0003X4SHA256Text ("UID0003X4/$Domain/v4`n$json")
    [UID0003X4SealedBlobV4]::new($Domain,$json,$digest)
}

function Assert-UID0003X4SealedBlobV4($Blob,[string]$ExpectedDomain,[string]$Label) {
    if ($Blob -isnot [UID0003X4SealedBlobV4] -or $Blob.Domain -cne $ExpectedDomain -or
        (Get-UID0003X4SHA256Text ("UID0003X4/$($Blob.Domain)/v4`n$($Blob.CanonicalJson)")) -cne $Blob.SHA256) {
        throw "SEALED_BLOB_INVALID:$Label"
    }
}

function Get-UID0003X4ObjectNamesV4($Object,[string]$Label) {
    if ($null -eq $Object -or $Object -is [string] -or $Object -is [Collections.IList]) { throw "OBJECT_REQUIRED:$Label" }
    if ($Object -is [Collections.IDictionary]) { return @($Object.Keys | ForEach-Object { [string]$_ }) }
    return @($Object.PSObject.Properties.Name)
}

function Assert-UID0003X4ExactMembersV4($Object,[string[]]$Required,[string[]]$Optional,[string]$Label) {
    $actual = @(Get-UID0003X4ObjectNamesV4 $Object $Label)
    $seen = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach ($name in $actual) { if (-not $seen.Add($name)) { throw "DUPLICATE_PARSED_MEMBER:${Label}:$name" } }
    foreach ($name in $Required) { if (-not $seen.Contains($name)) { throw "MISSING_MEMBER:${Label}:$name" } }
    $allowed = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach ($name in @($Required)+@($Optional)) { [void]$allowed.Add($name) }
    foreach ($name in $actual) { if (-not $allowed.Contains($name)) { throw "UNEXPECTED_MEMBER:${Label}:$name" } }
}

function Get-UID0003X4JsonRpcIdV4($Id,[string]$Label) {
    if ($Id -is [string]) {
        if ([string]::IsNullOrWhiteSpace($Id)) { throw "JSONRPC_ID_DOMAIN_INVALID:$Label" }
        return [pscustomobject]@{ Kind='string'; Canonical=(Get-UID0003X4CanonicalJsonV4 ([string]$Id)) }
    }
    if ($Id -is [int32]) { return [pscustomobject]@{ Kind='int32'; Canonical=([string]$Id) } }
    if ($Id -is [int64]) { return [pscustomobject]@{ Kind='int64'; Canonical=([string]$Id) } }
    throw "JSONRPC_ID_DOMAIN_INVALID:$Label"
}

function Assert-UID0003X4JsonRpcRequestV4($Request,[string]$Label) {
    Assert-UID0003X4ExactMembersV4 $Request @('jsonrpc','id','method','params') @() "$Label request"
    if ($Request.jsonrpc -isnot [string] -or [string]$Request.jsonrpc -cne '2.0' -or $Request.method -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$Request.method)) { throw "JSONRPC_REQUEST_ROOT_INVALID:$Label" }
    Get-UID0003X4JsonRpcIdV4 $Request.id $Label | Out-Null
    Get-UID0003X4ObjectNamesV4 $Request.params "$Label params" | Out-Null
    if ([string]$Request.method -ceq 'tools/list') {
        Assert-UID0003X4ExactMembersV4 $Request.params @() @() "$Label tools/list params"
        return
    }
    if ([string]$Request.method -cne 'tools/call') { throw "JSONRPC_METHOD_NOT_AUTHORIZED:$Label" }
    Assert-UID0003X4ExactMembersV4 $Request.params @('name','arguments') @() "$Label tools/call params"
    if ($Request.params.name -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$Request.params.name)) { throw "TOOL_NAME_INVALID:$Label" }
    Assert-UID0003X4ToolArgumentsV4 ([string]$Request.params.name) $Request.params.arguments $Label
}

function Assert-UID0003X4StringArrayV4($Value,[string]$Label) {
    if ($Value -isnot [Collections.IList] -or $Value -is [string] -or @($Value).Count -eq 0) { throw "STRING_ARRAY_INVALID:$Label" }
    foreach ($item in @($Value)) { if ($item -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$item)) { throw "STRING_ARRAY_INVALID:$Label" } }
}

function Assert-UID0003X4ToolArgumentsV4([string]$Name,$Arguments,[string]$Label) {
    $db = { param($o) if ($o.database -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$o.database)) { throw "DATABASE_INVALID:$Label" } }
    switch ($Name) {
        'runtime_attestation' {
            Assert-UID0003X4ExactMembersV4 $Arguments @('expected_database','expected_canonical_path') @() "$Label arguments"
            foreach ($n in @('expected_database','expected_canonical_path')) { if ($Arguments.$n -isnot [string]) { throw "RUNTIME_ARGUMENT_TYPE_INVALID:${Label}:$n" } }
        }
        'idb_open' {
            Assert-UID0003X4ExactMembersV4 $Arguments @('input_path','mode','run_auto_analysis','build_caches','init_hexrays','idle_ttl_sec','preferred_session_id') @() "$Label arguments"
            if ($Arguments.input_path -isnot [string] -or $Arguments.mode -isnot [string] -or [string]$Arguments.mode -cne 'force_headless' -or
                $Arguments.run_auto_analysis -isnot [bool] -or $Arguments.run_auto_analysis -or $Arguments.build_caches -isnot [bool] -or $Arguments.build_caches -or
                $Arguments.init_hexrays -isnot [bool] -or $Arguments.init_hexrays -or -not (Test-UID0003X4JsonInteger $Arguments.idle_ttl_sec) -or [int64]$Arguments.idle_ttl_sec -ne 600 -or
                $Arguments.preferred_session_id -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$Arguments.preferred_session_id)) { throw "IDB_OPEN_ARGUMENT_CONTRACT_INVALID:$Label" }
        }
        'idb_list' { Assert-UID0003X4ExactMembersV4 $Arguments @() @() "$Label arguments" }
        'server_health' { Assert-UID0003X4ExactMembersV4 $Arguments @('database') @() "$Label arguments"; & $db $Arguments }
        'rename' {
            Assert-UID0003X4ExactMembersV4 $Arguments @('database','batch') @() "$Label arguments"; & $db $Arguments
            Assert-UID0003X4ExactMembersV4 $Arguments.batch @('func','stop_on_error','dry_run','allow_overwrite','pure') @() "$Label batch"
            Assert-UID0003X4ExactMembersV4 $Arguments.batch.func @('addr','name') @() "$Label batch.func"
            if ($Arguments.batch.func.addr -isnot [string] -or $Arguments.batch.func.name -isnot [string]) { throw "RENAME_FUNC_TYPES_INVALID:$Label" }
            foreach ($n in @('stop_on_error','dry_run','allow_overwrite','pure')) { if ($Arguments.batch.$n -isnot [bool]) { throw "RENAME_CONTROL_TYPE_INVALID:${Label}:$n" } }
        }
        'set_type' {
            Assert-UID0003X4ExactMembersV4 $Arguments @('database','edits') @() "$Label arguments"; & $db $Arguments
            Assert-UID0003X4ExactMembersV4 $Arguments.edits @('addr','kind','signature') @() "$Label edits"
            if ($Arguments.edits.addr -isnot [string] -or $Arguments.edits.kind -isnot [string] -or [string]$Arguments.edits.kind -cne 'function' -or $Arguments.edits.signature -isnot [string]) { throw "SET_TYPE_EDIT_INVALID:$Label" }
        }
        'set_repeatable_comments' {
            Assert-UID0003X4ExactMembersV4 $Arguments @('database','items') @() "$Label arguments"; & $db $Arguments
            Assert-UID0003X4ExactMembersV4 $Arguments.items @('addr','comment') @() "$Label items"
            if ($Arguments.items.addr -isnot [string] -or $Arguments.items.comment -isnot [string]) { throw "COMMENT_ITEM_INVALID:$Label" }
        }
        { $_ -in @('lookup_funcs','stack_frame','get_comments','inspect_items') } {
            $field = if ($Name -ceq 'lookup_funcs') { 'queries' } else { 'addrs' }
            Assert-UID0003X4ExactMembersV4 $Arguments @('database',$field) @() "$Label arguments"; & $db $Arguments; Assert-UID0003X4StringArrayV4 $Arguments.$field "$Label $field"
        }
        'get_bytes' {
            Assert-UID0003X4ExactMembersV4 $Arguments @('database','regions') @() "$Label arguments"; & $db $Arguments
            foreach ($row in @($Arguments.regions)) { Assert-UID0003X4ExactMembersV4 $row @('addr','size') @() "$Label region"; if ($row.addr -isnot [string] -or -not (Test-UID0003X4JsonInteger $row.size)) { throw "GET_BYTES_REGION_INVALID:$Label" } }
        }
        'xref_query' {
            Assert-UID0003X4ExactMembersV4 $Arguments @('database','queries') @() "$Label arguments"; & $db $Arguments
            foreach ($row in @($Arguments.queries)) { Assert-UID0003X4ExactMembersV4 $row @('addr','direction','xref_type','offset','count','include_fn','dedup','sort_by','descending') @() "$Label xref query" }
        }
        'find_bytes' {
            Assert-UID0003X4ExactMembersV4 $Arguments @('database','patterns','limit','offset') @() "$Label arguments"; & $db $Arguments; Assert-UID0003X4StringArrayV4 $Arguments.patterns "$Label patterns"
            foreach ($n in @('limit','offset')) { if (-not (Test-UID0003X4JsonInteger $Arguments.$n)) { throw "FIND_BYTES_INTEGER_INVALID:${Label}:$n" } }
        }
        'type_query' {
            Assert-UID0003X4ExactMembersV4 $Arguments @('database','queries') @() "$Label arguments"; & $db $Arguments
            foreach ($row in @($Arguments.queries)) { Assert-UID0003X4ExactMembersV4 $row @('filter','kind','offset','count','sort_by','descending','include_decl','include_members','max_members','include_relationships') @() "$Label type query" }
        }
        'type_inspect' {
            Assert-UID0003X4ExactMembersV4 $Arguments @('database','queries') @() "$Label arguments"; & $db $Arguments
            foreach ($row in @($Arguments.queries)) { Assert-UID0003X4ExactMembersV4 $row @('name','include_members','max_members') @() "$Label type inspect" }
        }
        'idb_save' {
            Assert-UID0003X4ExactMembersV4 $Arguments @('database','path') @() "$Label arguments"; & $db $Arguments
            if ($Arguments.path -isnot [string] -or -not (Test-UID0003X4ExactPath ([string]$Arguments.path) $UID0003X4CanonicalPath)) { throw "IDB_SAVE_PATH_INVALID:$Label" }
        }
        default { throw "TOOL_NOT_AUTHORIZED:${Label}:$Name" }
    }
}

function New-UID0003X4RequestPlanV4($Request,$Contract,[string]$Label,[string]$ExpectedPath='') {
    Assert-UID0003X4JsonRpcRequestV4 $Request $Label
    $id = Get-UID0003X4JsonRpcIdV4 $Request.id $Label
    $requestJson = Get-UID0003X4CanonicalJsonV4 $Request
    $contractJson = Get-UID0003X4CanonicalJsonV4 $Contract
    $requestSHA = Get-UID0003X4SHA256Text $requestJson
    $contractSHA = Get-UID0003X4SHA256Text $contractJson
    $tool = if ([string]$Request.method -ceq 'tools/call') { [string]$Request.params.name } else { '' }
    $database = if ($tool -and (Test-UID0003X4Property $Request.params.arguments 'database')) { [string]$Request.params.arguments.database } else { '' }
    $planValue = [ordered]@{label=$Label;request_json=$requestJson;request_sha256=$requestSHA;contract_json=$contractJson;contract_sha256=$contractSHA;id_kind=$id.Kind;id=$id.Canonical;method=[string]$Request.method;tool=$tool;database=$database;expected_path=$ExpectedPath}
    $planSHA = Get-UID0003X4SHA256Text ("UID0003X4/request-plan/v4`n$(Get-UID0003X4CanonicalJsonV4 $planValue)")
    [UID0003X4RequestPlanV4]::new($Label,$requestJson,$requestSHA,$contractJson,$contractSHA,$id.Kind,$id.Canonical,[string]$Request.method,$tool,$database,$ExpectedPath,$planSHA)
}

function Assert-UID0003X4ExactJsonRpcResponseV4($Request,$Envelope,[string]$Label) {
    $id = Get-UID0003X4JsonRpcIdV4 $Request.id $Label
    $responseId = Get-UID0003X4JsonRpcIdV4 $Envelope.id $Label
    if ($id.Kind -cne $responseId.Kind -or $id.Canonical -cne $responseId.Canonical) { throw "JSONRPC_ID_TYPE_VALUE_MISMATCH:$Label" }
    $hasResult = Test-UID0003X4Property $Envelope 'result'
    $hasError = Test-UID0003X4Property $Envelope 'error'
    if ($hasResult -eq $hasError) { throw "JSONRPC_DISPOSITION_AMBIGUOUS:$Label" }
    if ($hasResult) { Assert-UID0003X4ExactMembersV4 $Envelope @('jsonrpc','id','result') @() "$Label response" }
    else {
        Assert-UID0003X4ExactMembersV4 $Envelope @('jsonrpc','id','error') @() "$Label response"
        Assert-UID0003X4ExactMembersV4 $Envelope.error @('code','message') @('data') "$Label error"
        if (-not (Test-UID0003X4JsonInteger $Envelope.error.code) -or $Envelope.error.message -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$Envelope.error.message)) { throw "JSONRPC_ERROR_INVALID:$Label" }
    }
    if ($Envelope.jsonrpc -isnot [string] -or [string]$Envelope.jsonrpc -cne '2.0') { throw "JSONRPC_VERSION_INVALID:$Label" }
}

function Invoke-UID0003X4SealedTransportV4($Request,$Contract,[UID0003X4RequestPlanV4]$Plan,[scriptblock]$SendMcpJsonRpc) {
    if ($null -eq $Plan -or $null -eq $SendMcpJsonRpc) { throw 'SEALED_TRANSPORT_INPUT_MISSING' }
    $beforeRequest = Get-UID0003X4CanonicalJsonV4 $Request
    $beforeContract = Get-UID0003X4CanonicalJsonV4 $Contract
    if ($beforeRequest -cne $Plan.RequestJson -or (Get-UID0003X4SHA256Text $beforeRequest) -cne $Plan.RequestSHA256) { throw "REQUEST_PLAN_DIGEST_MISMATCH:$($Plan.Label)" }
    if ($beforeContract -cne $Plan.ContractJson -or (Get-UID0003X4SHA256Text $beforeContract) -cne $Plan.ContractSHA256) { throw "CONTRACT_PLAN_DIGEST_MISMATCH:$($Plan.Label)" }
    $raw = & $SendMcpJsonRpc $Plan.RequestJson
    if ($raw -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$raw)) { throw "RAW_JSON_TRANSPORT_RESPONSE_REQUIRED:$($Plan.Label)" }
    if ((Get-UID0003X4CanonicalJsonV4 $Request) -cne $Plan.RequestJson) { throw "REQUEST_MUTATED_DURING_TRANSPORT:$($Plan.Label)" }
    if ((Get-UID0003X4CanonicalJsonV4 $Contract) -cne $Plan.ContractJson) { throw "CONTRACT_MUTATED_DURING_TRANSPORT:$($Plan.Label)" }
    $envelope = ConvertFrom-UID0003X4StrictJson ([string]$raw) $Plan.Label
    $envelope.PSObject.Properties.Remove('UID0003X4RawJson')
    Assert-UID0003X4ExactJsonRpcResponseV4 $Request $envelope $Plan.Label
    [UID0003X4TransportReceiptV4]::new($Plan,[string]$raw,(Get-UID0003X4SHA256Text ([string]$raw)))
}

function Get-UID0003X4ReceiptEnvelopeV4([UID0003X4TransportReceiptV4]$Receipt) {
    if ($null -eq $Receipt -or (Get-UID0003X4SHA256Text $Receipt.RawResponse) -cne $Receipt.ResponseSHA256) { throw 'TRANSPORT_RECEIPT_DIGEST_INVALID' }
    $envelope = ConvertFrom-UID0003X4StrictJson $Receipt.RawResponse $Receipt.Plan.Label
    $envelope.PSObject.Properties.Remove('UID0003X4RawJson')
    return $envelope
}

$UID0003X4EndpointRootPropertiesV4 = [ordered]@{
    runtime_attestation=@('expected_database','expected_canonical_path');idb_open=@('input_path','mode','run_auto_analysis','build_caches','init_hexrays','idle_ttl_sec','preferred_session_id');idb_list=@();server_health=@('database')
    rename=@('database','batch');set_type=@('database','edits');set_repeatable_comments=@('database','items');lookup_funcs=@('database','queries');stack_frame=@('database','addrs');get_comments=@('database','addrs');inspect_items=@('database','addrs')
    get_bytes=@('database','regions');xref_query=@('database','queries');find_bytes=@('database','patterns','limit','offset');type_query=@('database','queries');type_inspect=@('database','queries');idb_save=@('database','path')
}

function Assert-UID0003X4ClosedSchemaNodeV4($Schema,[string]$Path,[bool]$Root) {
    if ($null -eq $Schema -or $Schema.type -isnot [string]) { throw "SCHEMA_NODE_TYPE_MISSING:$Path" }
    switch ([string]$Schema.type) {
        'object' {
            Assert-UID0003X4ExactMembersV4 $Schema @('type','properties','required','additionalProperties') @() "$Path schema"
            if ($Schema.additionalProperties -isnot [bool] -or $Schema.additionalProperties -ne $false -or $Schema.required -isnot [Collections.IList]) { throw "SCHEMA_OBJECT_NOT_CLOSED:$Path" }
            $requiredSet = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
            foreach ($name in @($Schema.required)) { if ($name -isnot [string] -or -not $requiredSet.Add([string]$name)) { throw "SCHEMA_REQUIRED_INVALID:$Path" } }
            foreach ($property in $Schema.properties.PSObject.Properties) { Assert-UID0003X4ClosedSchemaNodeV4 $property.Value "$Path.$($property.Name)" $false }
        }
        'array' { Assert-UID0003X4ExactMembersV4 $Schema @('type','items') @() "$Path schema"; Assert-UID0003X4ClosedSchemaNodeV4 $Schema.items "$Path[]" $false }
        'string' { Assert-UID0003X4ExactMembersV4 $Schema @('type') @('default','enum','const') "$Path schema" }
        'integer' { Assert-UID0003X4ExactMembersV4 $Schema @('type') @('default','enum','const','minimum','maximum') "$Path schema" }
        'boolean' { Assert-UID0003X4ExactMembersV4 $Schema @('type') @('default','const') "$Path schema" }
        default { throw "SCHEMA_TYPE_NOT_AUTHORIZED:${Path}:$($Schema.type)" }
    }
}

function Assert-UID0003X4ToolSurfaceV4($Request,[UID0003X4TransportReceiptV4]$Receipt,$BaselineManifest=$null) {
    $envelope = Get-UID0003X4ReceiptEnvelopeV4 $Receipt
    Assert-UID0003X4ExactJsonRpcResponseV4 $Request $envelope 'tools/list-v4'
    Assert-UID0003X4ExactMembersV4 $envelope.result @('tools') @() 'tools/list result'
    $rows = @($envelope.result.tools)
    $names = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    $retained = @()
    foreach ($row in $rows) {
        if ($row.name -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$row.name) -or -not $names.Add([string]$row.name)) { throw 'TOOLS_LIST_NAME_INVALID_OR_DUPLICATE' }
        if ([string]$row.name -ceq 'runtime/attest') { throw 'INTERNAL_RUNTIME_TOOL_ADVERTISED' }
        if ($UID0003X4EndpointRootPropertiesV4.Contains([string]$row.name)) {
            if ($null -eq $row.inputSchema) { throw "TOOL_INPUT_SCHEMA_MISSING:$($row.name)" }
            Assert-UID0003X4ClosedSchemaNodeV4 $row.inputSchema ([string]$row.name) $true
            $actualRoots = @($row.inputSchema.properties.PSObject.Properties.Name); [Array]::Sort($actualRoots,[StringComparer]::Ordinal)
            $expectedRoots = @($UID0003X4EndpointRootPropertiesV4[[string]$row.name]); [Array]::Sort($expectedRoots,[StringComparer]::Ordinal)
            if ((Get-UID0003X4CanonicalJsonV4 $actualRoots) -cne (Get-UID0003X4CanonicalJsonV4 $expectedRoots)) { throw "TOOL_ROOT_PROPERTIES_DRIFT:$($row.name)" }
            if ([string]$row.name -ceq 'runtime_attestation') {
                if (@($row.inputSchema.required).Count -ne 0) { throw 'RUNTIME_SCHEMA_REQUIRED_NOT_EMPTY' }
                foreach ($n in $expectedRoots) { if ($row.inputSchema.properties.$n.default -isnot [string] -or [string]$row.inputSchema.properties.$n.default -cne '') { throw "RUNTIME_SCHEMA_DEFAULT_DRIFT:$n" } }
            }
            $retained += [ordered]@{name=[string]$row.name;inputSchema=$row.inputSchema}
        }
    }
    foreach ($expected in $UID0003X4EndpointRootPropertiesV4.Keys) { if (-not $names.Contains([string]$expected)) { throw "TOOL_SCHEMA_AUTHORITY_MISSING:$expected" } }
    $manifest = New-UID0003X4SealedBlobV4 'endpoint-schemas' @($retained | Sort-Object name)
    if ($null -ne $BaselineManifest) {
        Assert-UID0003X4SealedBlobV4 $BaselineManifest 'endpoint-schemas' 'baseline endpoint schemas'
        if ($manifest.SHA256 -cne $BaselineManifest.SHA256 -or $manifest.CanonicalJson -cne $BaselineManifest.CanonicalJson) { throw 'ENDPOINT_SCHEMA_MANIFEST_DRIFT' }
    }
    return $manifest
}

function Get-UID0003X4PhysicalModuleTupleV4([string]$Path,[string]$Label) {
    $resolved = Get-UID0003X4NormalizedExistingPath $Path
    $stream = [IO.FileStream]::new($resolved,[IO.FileMode]::Open,[IO.FileAccess]::Read,([IO.FileShare]::ReadWrite -bor [IO.FileShare]::Delete),1048576,[IO.FileOptions]::SequentialScan)
    try {
        $before = Get-UID0003X4HandleBasicInfo $stream
        $tuple = Get-UID0003X4HeldTuple $stream $Label
        $after = Get-UID0003X4HandleBasicInfo $stream
        if ($before.CreationTime -ne $after.CreationTime -or $before.LastWriteTime -ne $after.LastWriteTime) { throw "MODULE_TIMESTAMP_DRIFT:$Label" }
        [pscustomobject]@{
            ResolvedPath=$tuple.ResolvedPath;Length=$tuple.Length;SHA256=$tuple.SHA256
            MTimeNs=[int64](([datetime]::FromFileTimeUtc([int64]$after.LastWriteTime).Ticks-621355968000000000L)*100L)
            CTimeNs=[int64](([datetime]::FromFileTimeUtc([int64]$after.CreationTime).Ticks-621355968000000000L)*100L)
        }
    } finally { $stream.Dispose() }
}

function Assert-UID0003X4PhysicalLoadedManifestV4($Runtime,[string]$Label) {
    $names = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    $paths = [Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
    $ids = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    $stable = @()
    foreach ($row in @($Runtime.modules)) {
        $name=[string]$row.sys_modules_name;$id=[string]$row.module_id
        if ([string]::IsNullOrWhiteSpace($name) -or -not $names.Add($name)) { throw "MODULE_NAME_DUPLICATE_OR_EMPTY:$Label" }
        if ([string]::IsNullOrWhiteSpace($id) -or -not $ids.Add($id)) { throw "MODULE_ID_DUPLICATE_OR_EMPTY:$Label" }
        $physical = Get-UID0003X4PhysicalModuleTupleV4 ([string]$row.resolved_path) "$Label $name"
        if (-not $paths.Add($physical.ResolvedPath)) { throw "MODULE_PATH_DUPLICATE:$Label" }
        if (-not (Test-UID0003X4ExactPath ([string]$row.file) $physical.ResolvedPath) -or -not (Test-UID0003X4ExactPath ([string]$row.spec_origin) $physical.ResolvedPath) -or
            -not (Test-UID0003X4JsonInteger $row.size) -or [int64]$row.size -ne $physical.Length -or [string]$row.sha256 -cne $physical.SHA256 -or
            -not (Test-UID0003X4JsonInteger $row.mtime_ns) -or [int64]$row.mtime_ns -ne $physical.MTimeNs -or
            -not (Test-UID0003X4JsonInteger $row.ctime_ns) -or [int64]$row.ctime_ns -ne $physical.CTimeNs) { throw "MODULE_PHYSICAL_IDENTITY_MISMATCH:${Label}:$name" }
        $stable += [ordered]@{name=$name;file=$physical.ResolvedPath;size=$physical.Length;mtime_ns=$physical.MTimeNs;ctime_ns=$physical.CTimeNs;sha256=$physical.SHA256}
    }
    $sealed = New-UID0003X4SealedBlobV4 'physical-module-manifest' @($stable | Sort-Object name,file)
    if ([string]$Runtime.implementation_manifest_sha256 -cnotmatch '^[0-9A-F]{64}$') { throw "IMPLEMENTATION_MANIFEST_DIGEST_INVALID:$Label" }
    return $sealed
}

function New-UID0003X4FileStateV4([string]$State,$Tuple) {
    if (@('P0','B0','D0','DCLOSED','P1') -cnotcontains $State -or $null -eq $Tuple -or [string]$Tuple.SHA256 -cnotmatch '^[0-9A-F]{64}$') { throw "FILE_STATE_INVALID:$State" }
    $path=[IO.Path]::GetFullPath([string]$Tuple.ResolvedPath)
    $value=[ordered]@{state=$State;path=$path;length=[int64]$Tuple.Length;mtime_ticks=[int64]$Tuple.LastWriteTimeUtcTicks;sha256=[string]$Tuple.SHA256}
    $digest=Get-UID0003X4SHA256Text ("UID0003X4/file-state/v4`n$(Get-UID0003X4CanonicalJsonV4 $value)")
    [UID0003X4FileStateV4]::new($State,$path,[int64]$Tuple.Length,[int64]$Tuple.LastWriteTimeUtcTicks,[string]$Tuple.SHA256,$digest)
}

function Assert-UID0003X4FileStateV4([UID0003X4FileStateV4]$State,[string]$ExpectedState,[string]$Label) {
    if ($null -eq $State -or $State.State -cne $ExpectedState) { throw "FILE_STATE_KIND_INVALID:$Label" }
    $value=[ordered]@{state=$State.State;path=$State.ResolvedPath;length=$State.Length;mtime_ticks=$State.LastWriteTimeUtcTicks;sha256=$State.SHA256}
    if ((Get-UID0003X4SHA256Text ("UID0003X4/file-state/v4`n$(Get-UID0003X4CanonicalJsonV4 $value)")) -cne $State.GenerationSHA256) { throw "FILE_STATE_DIGEST_INVALID:$Label" }
}

function New-UID0003X4ExactCloneHeldV4([UID0003X4FileStateV4]$P0,[string]$DestinationPath,[ValidateSet('B0','D0')][string]$State) {
    Assert-UID0003X4FileStateV4 $P0 'P0' "$State source authority"
    if ([IO.File]::Exists($DestinationPath) -or [IO.Directory]::Exists($DestinationPath)) { throw "CLONE_DESTINATION_EXISTS:$State" }
    $source=$null;$destination=$null
    try {
        $source=[IO.FileStream]::new($P0.ResolvedPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None,1048576,[IO.FileOptions]::SequentialScan)
        $sourceBefore=New-UID0003X4FileStateV4 'P0' (Get-UID0003X4HeldTuple $source "$State source before")
        if ($sourceBefore.GenerationSHA256 -cne $P0.GenerationSHA256) { throw "CLONE_SOURCE_NOT_P0:$State" }
        $destination=[IO.FileStream]::new($DestinationPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None,1048576,[IO.FileOptions]::WriteThrough)
        $buffer=New-Object byte[] 1048576;[int64]$copied=0
        while($copied -lt $P0.Length){$wanted=[int][Math]::Min([int64]$buffer.Length,$P0.Length-$copied);$read=$source.Read($buffer,0,$wanted);if($read -le 0){throw "CLONE_SHORT_SOURCE:$State"};$destination.Write($buffer,0,$read);$copied+=$read}
        if($source.ReadByte() -ne -1 -or $copied -ne $P0.Length){throw "CLONE_EOF_OR_COUNT_INVALID:$State"}
        $destination.Flush($true)
        Set-UID0003X4HeldLastWriteTimeUtcTicks $destination $P0.LastWriteTimeUtcTicks "$State destination"
        $destination.Flush($true)
        $sourceAfter=New-UID0003X4FileStateV4 'P0' (Get-UID0003X4HeldTuple $source "$State source after")
        if($sourceAfter.GenerationSHA256 -cne $P0.GenerationSHA256){throw "CLONE_SOURCE_DRIFT:$State"}
        $destinationTuple=Get-UID0003X4HeldTuple $destination "$State destination final"
        $clone=New-UID0003X4FileStateV4 $State $destinationTuple
        if($clone.Length -ne $P0.Length -or $clone.LastWriteTimeUtcTicks -ne $P0.LastWriteTimeUtcTicks -or $clone.SHA256 -cne $P0.SHA256){throw "CLONE_HELD_TUPLE_NOT_P0:$State"}
        return $clone
    } finally { if($null -ne $destination){$destination.Dispose()};if($null -ne $source){$source.Dispose()} }
}

function New-UID0003X4DiskStateV4([string]$State,[string]$FileDigest,[string]$ParentDigest,[string]$BindingDigest,[string]$SaveDigest,[string]$VerifierDigest) {
    if (@('DOPEN','DCLOSED','P1') -cnotcontains $State) { throw "DISK_STATE_KIND_INVALID:$State" }
    $value=[ordered]@{state=$State;file=$FileDigest;parent=$ParentDigest;binding=$BindingDigest;save=$SaveDigest;verifier=$VerifierDigest}
    $digest=Get-UID0003X4SHA256Text ("UID0003X4/disk-state/v4`n$(Get-UID0003X4CanonicalJsonV4 $value)")
    [UID0003X4DiskStateV4]::new($State,$FileDigest,$ParentDigest,$BindingDigest,$SaveDigest,$VerifierDigest,$digest)
}

function New-UID0003X4P1StateV4([UID0003X4DiskStateV4]$Dclosed,[UID0003X4SealedBlobV4[]]$VerifierReceipts,[ValidateSet('SUCCESS','EXPLICIT_FAILURE_SAVED','INDETERMINATE_SAVED')][string]$Classification) {
    if ($null -eq $Dclosed -or $Dclosed.State -cne 'DCLOSED' -or [string]::IsNullOrWhiteSpace($Dclosed.SaveReceiptSHA256)) { throw 'P1_DCLOSED_AUTHORITY_INVALID' }
    $required = if ($Classification -ceq 'INDETERMINATE_SAVED') { 2 } else { 1 }
    if (@($VerifierReceipts).Count -ne $required) { throw "P1_VERIFIER_CARDINALITY_INVALID:$Classification" }
    $digests=@();foreach($receipt in @($VerifierReceipts)){Assert-UID0003X4SealedBlobV4 $receipt 'returned-session-verifier' $Classification;$digests+=$receipt.SHA256}
    $verifierDigest=Get-UID0003X4SHA256Text (Get-UID0003X4CanonicalJsonV4 $digests)
    New-UID0003X4DiskStateV4 'P1' $Dclosed.FileGenerationSHA256 $Dclosed.StateSHA256 $Dclosed.RuntimeBindingSHA256 $Dclosed.SaveReceiptSHA256 $verifierDigest
}

function New-UID0003X4RestoreAuthorityV4([UID0003X4DiskStateV4]$P1,[string]$Classification) {
    if ($null -eq $P1 -or $P1.State -cne 'P1' -or [string]::IsNullOrWhiteSpace($P1.VerifierReceiptSHA256)) { throw 'RESTORE_P1_AUTHORITY_INVALID' }
    $value=[ordered]@{classification=$Classification;p1=$P1.StateSHA256;save=$P1.SaveReceiptSHA256;verifier=$P1.VerifierReceiptSHA256}
    $digest=Get-UID0003X4SHA256Text ("UID0003X4/restore-authority/v4`n$(Get-UID0003X4CanonicalJsonV4 $value)")
    [UID0003X4RestoreAuthorityV4]::new($Classification,$P1.StateSHA256,$P1.SaveReceiptSHA256,$P1.VerifierReceiptSHA256,$digest)
}

function New-UID0003X4JournalIdentityV4([string]$Database,[UID0003X4RequestPlanV4]$SavePlan,[UID0003X4FileStateV4]$P0) {
    Assert-UID0003X4FileStateV4 $P0 'P0' 'journal P0'
    $journal="$($P0.ResolvedPath).UID0003X4-transaction-save-authority-v4.jsonl"
    $value=[ordered]@{attempt='UID0003X4-CANONICAL-TRANSACTION-V4';database=$Database;path=$P0.ResolvedPath;id_kind=$SavePlan.RequestIdKind;id=$SavePlan.RequestIdCanonical;plan=$SavePlan.PlanSHA256;p0=$P0.GenerationSHA256;journal=$journal}
    $digest=Get-UID0003X4SHA256Text ("UID0003X4/journal-identity/v4`n$(Get-UID0003X4CanonicalJsonV4 $value)")
    [UID0003X4JournalIdentityV4]::new('UID0003X4-CANONICAL-TRANSACTION-V4',$Database,$P0.ResolvedPath,$SavePlan.RequestIdKind,$SavePlan.RequestIdCanonical,$SavePlan.PlanSHA256,$P0.GenerationSHA256,$journal,$digest)
}

function New-UID0003X4JournalEventV4($Identity,[int]$Ordinal,[string]$State,[string]$PreviousSHA,$Classification) {
    [ordered]@{schema_version=4;attempt_id=$Identity.AttemptId;identity_sha256=$Identity.IdentitySHA256;database=$Identity.Database;canonical_path=$Identity.CanonicalPath;request_id_kind=$Identity.RequestIdKind;request_id=$Identity.RequestIdCanonical;request_plan_sha256=$Identity.RequestPlanSHA256;p0_state_sha256=$Identity.P0StateSHA256;ordinal=$Ordinal;state=$State;previous_journal_sha256=$PreviousSHA;classification=$Classification}
}

function Read-UID0003X4JournalHeldV4([UID0003X4JournalAuthorityV4]$Authority,[string]$Label) {
    if ($null -eq $Authority -or $null -eq $Authority.Stream -or $Authority.Stream.SafeFileHandle.IsClosed) { throw "JOURNAL_HANDLE_NOT_HELD:$Label" }
    if (-not (Test-UID0003X4ExactPath (Get-UID0003X4HandlePath $Authority.Stream) $Authority.HandlePath)) { throw "JOURNAL_HANDLE_PATH_DRIFT:$Label" }
    $stream=$Authority.Stream;$stream.Position=0;$bytes=[byte[]]::new([int]$stream.Length);$read=0
    while($read -lt $bytes.Length){$n=$stream.Read($bytes,$read,$bytes.Length-$read);if($n -le 0){throw "JOURNAL_SHORT_READ:$Label"};$read+=$n}
    $text=[Text.UTF8Encoding]::new($false,$true).GetString($bytes)
    if(-not $text.EndsWith("`n")){throw "JOURNAL_TRUNCATED:$Label"}
    $lines=@($text.TrimEnd([char[]]"`r`n") -split "`r?`n");if($lines.Count -lt 1 -or $lines.Count -gt 3){throw "JOURNAL_CARDINALITY:$Label"}
    $states=@('NOT_ISSUED','ISSUED','CLASSIFIED');$prefix='';$events=@()
    for($i=0;$i -lt $lines.Count;$i++){
        $row=ConvertFrom-UID0003X4StrictJson $lines[$i] "$Label row $i";$row.PSObject.Properties.Remove('UID0003X4RawJson')
        Assert-UID0003X4ExactMembersV4 $row @('schema_version','attempt_id','identity_sha256','database','canonical_path','request_id_kind','request_id','request_plan_sha256','p0_state_sha256','ordinal','state','previous_journal_sha256','classification') @() "$Label row $i"
        $previous=if($i -eq 0){''}else{Get-UID0003X4SHA256Text $prefix}
        if(-not(Test-UID0003X4JsonInteger $row.schema_version)-or[int64]$row.schema_version-ne 4-or[string]$row.identity_sha256-cne$Authority.Identity.IdentitySHA256-or-not(Test-UID0003X4JsonInteger $row.ordinal)-or[int64]$row.ordinal-ne$i-or[string]$row.state-cne$states[$i]-or[string]$row.previous_journal_sha256-cne$previous){throw "JOURNAL_CHAIN_INVALID:${Label}:$i"}
        $events+=$row;$prefix+=$lines[$i]+"`n"
    }
    [pscustomobject]@{State=[string]$events[-1].state;Events=$events;Text=$text;SHA256=Get-UID0003X4SHA256Text $text}
}

function New-UID0003X4JournalAuthorityV4([UID0003X4JournalIdentityV4]$Identity) {
    try{$stream=[IO.FileStream]::new($Identity.JournalPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None,4096,[IO.FileOptions]::WriteThrough)}catch[IO.IOException]{throw 'SAVE_AUTHORITY_ALREADY_EXISTS_V4'}
    $authority=[UID0003X4JournalAuthorityV4]::new($Identity,$stream,$false,(Get-UID0003X4HandlePath $stream))
    $line=(Get-UID0003X4CanonicalJsonV4 (New-UID0003X4JournalEventV4 $Identity 0 'NOT_ISSUED' '' $null))+"`n";$bytes=[Text.UTF8Encoding]::new($false).GetBytes($line)
    $stream.Write($bytes,0,$bytes.Length);$stream.Flush($true);Read-UID0003X4JournalHeldV4 $authority 'journal create'|Out-Null
    return $authority
}

function Add-UID0003X4JournalTransitionHeldV4([UID0003X4JournalAuthorityV4]$Authority,[string]$Expected,[string]$Next,$Classification) {
    $state=Read-UID0003X4JournalHeldV4 $Authority 'journal transition'
    if($state.State-cne$Expected){throw "JOURNAL_STATE_MISMATCH:expected=${Expected}:actual=$($state.State)"}
    $valid=($Expected-ceq'NOT_ISSUED'-and$Next-ceq'ISSUED'-and$null-eq$Classification)-or($Expected-ceq'ISSUED'-and$Next-ceq'CLASSIFIED'-and$null-ne$Classification)
    if(-not$valid){throw "JOURNAL_TRANSITION_INVALID:$Expected->$Next"}
    $event=New-UID0003X4JournalEventV4 $Authority.Identity $state.Events.Count $Next $state.SHA256 $Classification
    $line=(Get-UID0003X4CanonicalJsonV4 $event)+"`n";$bytes=[Text.UTF8Encoding]::new($false).GetBytes($line)
    $Authority.Stream.Position=$Authority.Stream.Length;$Authority.Stream.Write($bytes,0,$bytes.Length);$Authority.Stream.Flush($true)
    $after=Read-UID0003X4JournalHeldV4 $Authority "journal $Next";if($after.State-cne$Next){throw "JOURNAL_TRANSITION_NOT_DURABLE:$Next"};return $after
}

function Invoke-UID0003X4SoleSaveHeldV4([UID0003X4JournalAuthorityV4]$Authority,$Request,$Contract,[UID0003X4RequestPlanV4]$Plan,[scriptblock]$SendMcpJsonRpc) {
    if($Authority.Rehydrated){throw 'REHYDRATED_AUTHORITY_CANNOT_ISSUE_SAVE'}
    Add-UID0003X4JournalTransitionHeldV4 $Authority 'NOT_ISSUED' 'ISSUED' $null|Out-Null
    $receipt=$null;$failure=$null
    try{$receipt=Invoke-UID0003X4SealedTransportV4 $Request $Contract $Plan $SendMcpJsonRpc}catch{$failure=$_.Exception.ToString()}
    $classification=if($null-ne$failure){[ordered]@{class='INDETERMINATE';reason='transport';error_sha256=Get-UID0003X4SHA256Text $failure;response_sha256=$null}}else{[ordered]@{class='RESPONSE_RECEIVED';reason='exact-envelope';error_sha256=$null;response_sha256=$receipt.ResponseSHA256}}
    $final=Add-UID0003X4JournalTransitionHeldV4 $Authority 'ISSUED' 'CLASSIFIED' $classification
    $sealed=New-UID0003X4SealedBlobV4 'save-receipt' ([ordered]@{identity=$Authority.Identity.IdentitySHA256;journal=$final.SHA256;classification=$classification})
    [pscustomobject]@{TransportReceipt=$receipt;Failure=$failure;Classification=$classification;JournalReceipt=$sealed;JournalState=$final}
}

function Get-UID0003X4NewOpenGenerationV4($BeforeList,$AfterList,$AfterRuntime,[string]$ExpectedPath,[string]$Label) {
    $beforeIds=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal);foreach($row in @($BeforeList.sessions)){[void]$beforeIds.Add([string]$row.session_id)}
    $newRows=@($AfterList.sessions|Where-Object{-not$beforeIds.Contains([string]$_.session_id)-and(Test-UID0003X4ExactPath([string]$_.input_path)$ExpectedPath)})
    if($newRows.Count-ne 1){throw "PARTIAL_OPEN_GENERATION_CARDINALITY:${Label}:$($newRows.Count)"}
    $row=$newRows[0];$workers=@($AfterRuntime.workers|Where-Object{@($_.supervisor_sessions|Where-Object{[string]$_.session_id-ceq[string]$row.session_id}).Count-eq 1})
    if($workers.Count-ne 1){throw "PARTIAL_OPEN_RUNTIME_GENERATION_CARDINALITY:${Label}:$($workers.Count)"}
    [pscustomobject]@{Session=$row;Worker=$workers[0]}
}

function Invoke-UID0003X4PartialOpenCleanupV4($PreOpen,[string]$ExpectedPath,[string]$Prefix,[scriptblock]$SendMcpJsonRpc,$FrozenListenerBinding) {
    $afterList=Get-UID0003X4LiteralIdbListV4 "$Prefix-list-after" $SendMcpJsonRpc
    $afterRuntime=Get-UID0003X4LiteralQuiescentRuntimeV4 "$Prefix-runtime-after" $SendMcpJsonRpc $FrozenListenerBinding
    $created=Get-UID0003X4NewOpenGenerationV4 $PreOpen.List $afterList $afterRuntime $ExpectedPath $Prefix
    Retire-UID0003X4DiscoveredGenerationV4 $created $ExpectedPath $Prefix $SendMcpJsonRpc $FrozenListenerBinding|Out-Null
    Assert-UID0003X4GenerationAbsentV4 $created $ExpectedPath $Prefix $SendMcpJsonRpc $FrozenListenerBinding|Out-Null
    return $created
}

function Open-UID0003X4RoleV4([string]$Role,[string]$Prefix,[string]$InputPath,[string]$PreferredSessionId,[scriptblock]$SendMcpJsonRpc,$FrozenListenerBinding,$BoundaryAuthority) {
    $preOpen=Get-UID0003X4PreOpenSnapshotV4 $InputPath $Prefix $SendMcpJsonRpc $FrozenListenerBinding $BoundaryAuthority
    try{
        $request=New-UID0003X4IdbOpenRequest "$Prefix-open" $InputPath $PreferredSessionId
        $contract=Get-UID0003X4EndpointContractV4 'idb_open'
        $plan=New-UID0003X4RequestPlanV4 $request $contract "$Prefix idb_open" (Get-UID0003X4NormalizedExistingPath $InputPath)
        $receipt=Invoke-UID0003X4SealedTransportV4 $request $contract $plan $SendMcpJsonRpc
        $envelope=Get-UID0003X4ReceiptEnvelopeV4 $receipt
        $database=Get-UID0003X4ReturnedDatabaseId $request $envelope $Role
        $open=[pscustomobject]@{Role=$Role;Request=$request;Plan=$plan;Receipt=$receipt;Envelope=$envelope;Database=$database;Session=$envelope.result.structuredContent.session;ExpectedPath=Get-UID0003X4NormalizedExistingPath $InputPath;PreOpen=$preOpen}
        $open|Add-Member -NotePropertyName Binding -NotePropertyValue (Complete-UID0003X4RoleBinding $open $InputPath "$Prefix-bound" $SendMcpJsonRpc $FrozenListenerBinding)
        return $open
    }catch{
        $original=$_
        try{Invoke-UID0003X4PartialOpenCleanupV4 $preOpen $InputPath "$Prefix-partial-open" $SendMcpJsonRpc $FrozenListenerBinding|Out-Null}catch{throw "PARTIAL_OPEN_AND_CLEANUP_FAILURE:${Role}:$($original.Exception.Message):$($_.Exception.Message)"}
        throw $original
    }
}

function Invoke-UID0003X4OwnedRoleControllerV4([string]$Role,[string]$Prefix,[string]$ExpectedPath,[string]$PreferredSessionId,[scriptblock]$SendMcpJsonRpc,$FrozenListenerBinding,$BoundaryAuthority,[scriptblock]$Body) {
    if($null-eq$Body){throw "ROLE_BODY_MISSING:$Role"}
    $open=$null;$result=$null;$retired=$null;$failure=$null
    try{$open=Open-UID0003X4RoleV4 $Role $Prefix $ExpectedPath $PreferredSessionId $SendMcpJsonRpc $FrozenListenerBinding $BoundaryAuthority;$result=&$Body $open $open.Binding}catch{$failure=$_}finally{
        if($null-ne$open){try{$retired=Retire-UID0003X4BoundRole $open.Binding $ExpectedPath "$Prefix-retire" $SendMcpJsonRpc $FrozenListenerBinding}catch{if($null-ne$failure){throw "ROLE_BODY_AND_RETIRE_FAILURE:${Role}:$($failure.Exception.Message):$($_.Exception.Message)"};throw}}
    }
    if($null-ne$failure){throw $failure};[pscustomobject]@{Role=$Role;Open=$open;Body=$result;Retired=$retired}
}

function Assert-UID0003X4ProductionBoundaryV4([string]$Label,$RoleBinding,[scriptblock]$SendMcpJsonRpc,$FrozenListenerBinding,[UID0003X4SealedBlobV4]$EndpointManifest,[UID0003X4SealedBlobV4]$ListenerAuthority) {
    Assert-UID0003X4SealedBlobV4 $ListenerAuthority 'listener-source-command-native' "$Label listener authority"
    Assert-UID0003X4ListenerBinding $FrozenListenerBinding $Label|Out-Null
    $listRequest=New-UID0003X4ToolsListRequest "uid0003x4-v4-$Label-tools"
    $contract=[ordered]@{method='tools/list';params=[ordered]@{}}
    $plan=New-UID0003X4RequestPlanV4 $listRequest $contract "$Label tools/list"
    $receipt=Invoke-UID0003X4SealedTransportV4 $listRequest $contract $plan $SendMcpJsonRpc
    $manifest=Assert-UID0003X4ToolSurfaceV4 $listRequest $receipt $EndpointManifest
    if($null-ne$RoleBinding){
        $bound=Complete-UID0003X4RoleBinding $RoleBinding.Open $RoleBinding.ExpectedPath "$Label-runtime" $SendMcpJsonRpc $FrozenListenerBinding
        Assert-UID0003X4PhysicalLoadedManifestV4 $bound.Runtime.Listener.Runtime "$Label listener modules"|Out-Null
        Assert-UID0003X4PhysicalLoadedManifestV4 $bound.Runtime.Selected.Worker.Runtime "$Label worker modules"|Out-Null
    }
    [pscustomobject]@{Label=$Label;EndpointManifest=$manifest;RoleBinding=$RoleBinding}
}

$UID0003X4V4BoundaryOrder = @(
    'before-b0-d0','before-d0-open','d0-pre-id01-dry','d0-pre-id01-actual','d0-pre-id02','d0-pre-id03','d0-pre-retire','after-d0-retire',
    'before-txn-open','txn-n0','txn-pre-id01-dry','txn-pre-id01-actual','txn-pre-id02','txn-pre-id03','txn-pre-save','txn-post-save-before-retire','after-txn-retire',
    'before-success-verifier','after-success-verifier','before-explicit-failure-verifier','after-explicit-failure-verifier','before-indeterminate-verifier-1','after-indeterminate-verifier-1','before-indeterminate-verifier-2','after-indeterminate-verifier-2',
    'before-rollback','after-rollback','before-rollback-verifier','after-rollback-verifier','before-lifecycle-credit'
)

function Assert-UID0003X4V4BoundaryInventory {
    $seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach($label in $UID0003X4V4BoundaryOrder){if(-not$seen.Add($label)){throw "BOUNDARY_LABEL_DUPLICATE:$label"}}
    if($seen.Count-ne 30){throw "BOUNDARY_LABEL_COUNT_INVALID:$($seen.Count)"}
}

$UID0003X4V4HostileLabels = @(
    'nested raw duplicate member','unicode-escaped duplicate member','unexpected JSON-RPC root member','Boolean JSON-RPC ID','fractional JSON-RPC ID','native JSON-RPC ID mismatch',
    'schema root additionalProperties true','schema root extra member','recursive schema object extra member','endpoint root property drift','runtime default drift','pre-dispatch request mutation','pre-dispatch contract mutation',
    'physical module mtime drift','physical module ctime drift','duplicate stable module name','duplicate stable module path','partial-open zero generation','partial-open multiple generations','partial-open exact generation cleanup',
    'sealed production controller dispatch','continuous journal replacement','continuous journal second authority','rehydrated save rejection','held clone source substitution','held clone destination substitution',
    'success saved missing verifier','explicit-failure-saved missing verifier','indeterminate saved one verifier','Dclosed parent mismatch','P1 verifier tuple mismatch','restore authority digest mismatch','destructive restore third identity'
)

function Assert-UID0003X4V4HostileInventory {
    Assert-UID0003X4V4BoundaryInventory
    $seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach($label in $UID0003X4V4HostileLabels){if(-not$seen.Add($label)){throw "HOSTILE_LABEL_DUPLICATE:$label"}}
    if($seen.Count-ne 33){throw "HOSTILE_LABEL_COUNT_INVALID:$($seen.Count)"}
    $controller=(Get-Command Invoke-UID0003X4OwnedRoleControllerV4 -CommandType Function).Parameters.Keys
    foreach($forbidden in @('OpenRole','BindRole','RetireRole','SchemaGate','ListenerGate','Classifier','RestoreRole')){if($controller-ccontains$forbidden){throw "SEALED_CONTROLLER_OVERRIDE_EXPOSED:$forbidden"}}
    [pscustomobject]@{Status='UID0003X4_V4_STATIC_HOSTILE_INVENTORY_PASSED';BoundaryCount=$UID0003X4V4BoundaryOrder.Count;HostileCount=$UID0003X4V4HostileLabels.Count;NegativeEffects='0|0|0|0';ExpectedJournalEffects='3|1|0|0';ExpectedRestoreEffects='0|0|1|1'}
}

$UID0003X4V4StaticFixtureResult = Assert-UID0003X4V4HostileInventory
~~~

## Removed Block R010

- SHA256: `B2E4B7156EC7D82EDE1597D20D6C75DF988DD024DBF8F30704A7BCEA691B046C`
- Language: `powershell`
- Bytes: `65840`
- First recovered timestamp: `2026-08-08T19:53:10.917Z`
- Session provenance: rollout-2026-08-06T18-21-08-019fd92a-7d56-7360-9e1c-5d0af75f3e69.jsonl line 197067 (2026-08-08T19:53:10.917Z)

~~~powershell
if (-not ('UID0003X4V44CaseSpec' -as [type])) {
Add-Type -TypeDefinition @"
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Security.Cryptography;
using System.Text;

public sealed class UID0003X4V44CaseSpec {
    public readonly int Ordinal;
    public readonly string Label;
    public readonly string Injection;
    public readonly string ExpectedError;
    public readonly string ExpectedStage;
    public readonly int ExpectedBoundaryCount;
    public UID0003X4V44CaseSpec(int ordinal,string label,string injection,string expectedError,string expectedStage,int expectedBoundaryCount) {
        Ordinal=ordinal; Label=label; Injection=injection; ExpectedError=expectedError; ExpectedStage=expectedStage; ExpectedBoundaryCount=expectedBoundaryCount;
    }
}

public static class UID0003X4V44CaseAuthority {
    private static readonly UID0003X4V44CaseSpec[] Cases = new UID0003X4V44CaseSpec[] {
        new UID0003X4V44CaseSpec(0,"raw duplicate root member","raw-root-duplicate","V44_RAW_ROOT_DUPLICATE","before-b0-d0",1),
        new UID0003X4V44CaseSpec(1,"raw duplicate nested member","raw-nested-duplicate","V44_RAW_NESTED_DUPLICATE","before-b0-d0",1),
        new UID0003X4V44CaseSpec(2,"schema root extra member","schema-root-extra","V44_SCHEMA_ROOT_EXTRA","before-b0-d0",1),
        new UID0003X4V44CaseSpec(3,"schema nested extra member","schema-nested-extra","V44_SCHEMA_NESTED_EXTRA","before-b0-d0",1),
        new UID0003X4V44CaseSpec(4,"schema required absent from properties","schema-required-absent","V44_SCHEMA_REQUIRED_ABSENT","before-b0-d0",1),
        new UID0003X4V44CaseSpec(5,"native Boolean JSON-RPC id","id-boolean","V44_JSONRPC_ID_NATIVE_TYPE","before-b0-d0",1),
        new UID0003X4V44CaseSpec(6,"fractional JSON-RPC id","id-fractional","V44_JSONRPC_ID_NATIVE_TYPE","before-b0-d0",1),
        new UID0003X4V44CaseSpec(7,"response id type drift","response-id-type","V44_JSONRPC_ID_CORRELATION","before-b0-d0",1),
        new UID0003X4V44CaseSpec(8,"request-plan digest mutation","plan-digest","V44_REQUEST_PLAN_DIGEST","before-b0-d0",1),
        new UID0003X4V44CaseSpec(9,"request database mutation","request-database","V44_REQUEST_DATABASE_DRIFT","before-b0-d0",1),
        new UID0003X4V44CaseSpec(10,"tools/list endpoint missing","endpoint-missing","V44_ENDPOINT_SET_DRIFT","before-b0-d0",1),
        new UID0003X4V44CaseSpec(11,"listener socket ownership drift","listener-socket","V44_LISTENER_SOCKET_DRIFT","before-d0-open",2),
        new UID0003X4V44CaseSpec(12,"worker parent drift","worker-parent","V44_WORKER_PARENT_DRIFT","d0-pre-id01-dry",3),
        new UID0003X4V44CaseSpec(13,"returned session drift","returned-session","V44_RETURNED_SESSION_DRIFT","d0-pre-id01-actual",4),
        new UID0003X4V44CaseSpec(14,"D0 canonical-path misuse","d0-canonical-path","V44_D0_PATH_AUTHORITY","d0-pre-id02",5),
        new UID0003X4V44CaseSpec(15,"empty loaded-module manifest","manifest-empty","V44_MODULE_MANIFEST_EMPTY","d0-pre-id03",6),
        new UID0003X4V44CaseSpec(16,"physical module timestamp drift","manifest-timestamp","V44_MODULE_TIMESTAMP_DRIFT","d0-pre-retire",7),
        new UID0003X4V44CaseSpec(17,"duplicate stable module path","manifest-duplicate","V44_MODULE_STABLE_DUPLICATE","after-d0-retire",8),
        new UID0003X4V44CaseSpec(18,"partial-open foreign generation","open-foreign","V44_OPEN_FOREIGN_GENERATION","before-txn-open",9),
        new UID0003X4V44CaseSpec(19,"partial-open ambiguous generation","open-ambiguous","V44_OPEN_GENERATION_AMBIGUOUS","txn-n0",10),
        new UID0003X4V44CaseSpec(20,"B0 canonical alias","b0-alias","V44_B0_ALIAS","txn-pre-id01-dry",11),
        new UID0003X4V44CaseSpec(21,"D0 short held clone","d0-short-copy","V44_D0_COUNT_OR_EOF","txn-pre-id01-actual",12),
        new UID0003X4V44CaseSpec(22,"retained ISSUED journal","journal-issued","V44_JOURNAL_RETAINED_ISSUED","txn-pre-id02",13),
        new UID0003X4V44CaseSpec(23,"journal replay or replacement","journal-replay","V44_JOURNAL_IDENTITY_DRIFT","txn-pre-id03",14),
        new UID0003X4V44CaseSpec(24,"duplicate save attempt","duplicate-save","V44_SAVE_ALREADY_ISSUED","txn-pre-save",15),
        new UID0003X4V44CaseSpec(25,"FINAL readback drift","final-readback","V44_FINAL_READBACK_DRIFT","txn-post-save-before-retire",16),
        new UID0003X4V44CaseSpec(26,"malformed save semantics","save-malformed","V44_SAVE_NATIVE_SEMANTICS","after-txn-retire",17),
        new UID0003X4V44CaseSpec(27,"ambiguous save classifier","classifier-ambiguous","V44_CLASSIFIER_AMBIGUOUS","before-success-verifier",18),
        new UID0003X4V44CaseSpec(28,"fresh verifier absence failure","verifier-absence","V44_VERIFIER_ABSENCE","after-success-verifier",19),
        new UID0003X4V44CaseSpec(29,"third-identity restore substitution","restore-third-identity","V44_RESTORE_THIRD_IDENTITY","before-rollback",26),
        new UID0003X4V44CaseSpec(30,"restore counted-copy short write","restore-short-write","V44_RESTORE_COUNT_OR_EOF","after-rollback",27),
        new UID0003X4V44CaseSpec(31,"rollback verifier N0 mismatch","rollback-verifier","V44_ROLLBACK_N0_MISMATCH","after-rollback-verifier",29),
        new UID0003X4V44CaseSpec(32,"terminal cleanup failure","terminal-cleanup","V44_TERMINAL_CLEANUP_FAILURE","before-lifecycle-credit",30)
    };
    public static ReadOnlyCollection<UID0003X4V44CaseSpec> All() { return Array.AsReadOnly((UID0003X4V44CaseSpec[])Cases.Clone()); }
    public static UID0003X4V44CaseSpec At(int ordinal) { if(ordinal<0 || ordinal>=Cases.Length) throw new ArgumentOutOfRangeException("ordinal"); return Cases[ordinal]; }
    public static string SHA256() {
        StringBuilder b=new StringBuilder();
        foreach(UID0003X4V44CaseSpec c in Cases)b.Append(c.Ordinal).Append('|').Append(c.Label).Append('|').Append(c.Injection).Append('|').Append(c.ExpectedError).Append('|').Append(c.ExpectedStage).Append('|').Append(c.ExpectedBoundaryCount).Append('\n');
        using(SHA256 h=System.Security.Cryptography.SHA256.Create()){byte[] d=h.ComputeHash(Encoding.UTF8.GetBytes(b.ToString()));StringBuilder x=new StringBuilder();foreach(byte v in d)x.Append(v.ToString("X2"));return x.ToString();}
    }
}

public sealed class UID0003X4V44FileTuple {
    public readonly string State; public readonly string Path; public readonly long Length; public readonly long LastWriteTimeUtcTicks; public readonly string SHA256; public readonly string ParentSHA256; public readonly string Digest;
    public UID0003X4V44FileTuple(string state,string path,long length,long ticks,string sha256,string parentSHA256,string digest){State=state;Path=path;Length=length;LastWriteTimeUtcTicks=ticks;SHA256=sha256;ParentSHA256=parentSHA256;Digest=digest;}
}
public sealed class UID0003X4V44RequestPlan {
    public readonly string Label; public readonly string RequestJson; public readonly string RequestSHA256; public readonly string ContractJson; public readonly string ContractSHA256; public readonly string NativeIdType; public readonly string NativeIdValue; public readonly string Tool; public readonly string Database; public readonly string ExpectedPath; public readonly string Digest;
    public UID0003X4V44RequestPlan(string label,string requestJson,string requestSHA256,string contractJson,string contractSHA256,string nativeIdType,string nativeIdValue,string tool,string database,string expectedPath,string digest){Label=label;RequestJson=requestJson;RequestSHA256=requestSHA256;ContractJson=contractJson;ContractSHA256=contractSHA256;NativeIdType=nativeIdType;NativeIdValue=nativeIdValue;Tool=tool;Database=database;ExpectedPath=expectedPath;Digest=digest;}
}
public sealed class UID0003X4V44RoleBindingReceipt {
    public readonly string Role; public readonly string Database; public readonly string Path; public readonly long RedirectorPid; public readonly long WorkerPid; public readonly long ParentPid; public readonly long ProcessGeneration; public readonly string Host; public readonly long Port; public readonly string ManifestSHA256; public readonly string OpenResponseSHA256; public readonly string Digest;
    public UID0003X4V44RoleBindingReceipt(string role,string database,string path,long redirectorPid,long workerPid,long parentPid,long processGeneration,string host,long port,string manifestSHA256,string openResponseSHA256,string digest){Role=role;Database=database;Path=path;RedirectorPid=redirectorPid;WorkerPid=workerPid;ParentPid=parentPid;ProcessGeneration=processGeneration;Host=host;Port=port;ManifestSHA256=manifestSHA256;OpenResponseSHA256=openResponseSHA256;Digest=digest;}
}
public sealed class UID0003X4V44BoundaryReceipt {
    public readonly int Ordinal; public readonly string Label; public readonly string RoleDigest; public readonly string SchemaSHA256; public readonly string ManifestSHA256; public readonly string Digest;
    public UID0003X4V44BoundaryReceipt(int ordinal,string label,string roleDigest,string schemaSHA256,string manifestSHA256,string digest){Ordinal=ordinal;Label=label;RoleDigest=roleDigest;SchemaSHA256=schemaSHA256;ManifestSHA256=manifestSHA256;Digest=digest;}
}
public sealed class UID0003X4V44JournalReceipt {
    public readonly int Ordinal; public readonly string PreviousState; public readonly string State; public readonly string PreviousSHA256; public readonly string EntrySHA256; public readonly string JournalIdentitySHA256; public readonly string Digest;
    public UID0003X4V44JournalReceipt(int ordinal,string previousState,string state,string previousSHA256,string entrySHA256,string journalIdentitySHA256,string digest){Ordinal=ordinal;PreviousState=previousState;State=state;PreviousSHA256=previousSHA256;EntrySHA256=entrySHA256;JournalIdentitySHA256=journalIdentitySHA256;Digest=digest;}
}
public sealed class UID0003X4V44SaveReceipt {
    public readonly string Classification; public readonly string Database; public readonly string Path; public readonly string RequestSHA256; public readonly string ResponseSHA256; public readonly string DopenSHA256; public readonly string DclosedSHA256; public readonly int SaveAttempts; public readonly string Digest;
    public UID0003X4V44SaveReceipt(string classification,string database,string path,string requestSHA256,string responseSHA256,string dopenSHA256,string dclosedSHA256,int saveAttempts,string digest){Classification=classification;Database=database;Path=path;RequestSHA256=requestSHA256;ResponseSHA256=responseSHA256;DopenSHA256=dopenSHA256;DclosedSHA256=dclosedSHA256;SaveAttempts=saveAttempts;Digest=digest;}
}
public sealed class UID0003X4V44SuiteReceipt {
    public readonly string Status; public readonly string CaseAuthoritySHA256; public readonly string BoundaryOrderSHA256; public readonly int HostileCount; public readonly int PositiveControlCount; public readonly string Digest;
    public UID0003X4V44SuiteReceipt(string status,string caseAuthoritySHA256,string boundaryOrderSHA256,int hostileCount,int positiveControlCount,string digest){Status=status;CaseAuthoritySHA256=caseAuthoritySHA256;BoundaryOrderSHA256=boundaryOrderSHA256;HostileCount=hostileCount;PositiveControlCount=positiveControlCount;Digest=digest;}
}
"@
}

$script:UID0003X4V44BoundaryOrder = @(
    'before-b0-d0','before-d0-open','d0-pre-id01-dry','d0-pre-id01-actual','d0-pre-id02','d0-pre-id03','d0-pre-retire','after-d0-retire','before-txn-open','txn-n0',
    'txn-pre-id01-dry','txn-pre-id01-actual','txn-pre-id02','txn-pre-id03','txn-pre-save','txn-post-save-before-retire','after-txn-retire','before-success-verifier','after-success-verifier','before-explicit-failure-verifier',
    'after-explicit-failure-verifier','before-indeterminate-verifier-1','after-indeterminate-verifier-1','before-indeterminate-verifier-2','after-indeterminate-verifier-2','before-rollback','after-rollback','before-rollback-verifier','after-rollback-verifier','before-lifecycle-credit'
)
$script:UID0003X4V44CoordinatorSecret = Get-UID0003X4SHA256Text ('UID0003X4/V4.4/private/'+[guid]::NewGuid().ToString('N'))
$script:UID0003X4V44CoordinatorDepth = 0

function Initialize-UID0003X4V44Types {
    foreach($name in @('UID0003X4V44CaseSpec','UID0003X4V44FileTuple','UID0003X4V44RequestPlan','UID0003X4V44RoleBindingReceipt','UID0003X4V44BoundaryReceipt','UID0003X4V44JournalReceipt','UID0003X4V44SaveReceipt','UID0003X4V44SuiteReceipt')){if(-not($name-as[type])){throw "V44_TYPE_MISSING:$name"}}
}

function Get-UID0003X4CanonicalJsonV44($Value) { Get-UID0003X4CanonicalJsonV4 $Value }
function Get-UID0003X4SHA256V44([string]$Value) { Get-UID0003X4SHA256Text $Value }

function New-UID0003X4SealedReceiptV44([string]$Domain,$Value) {
    if([string]::IsNullOrWhiteSpace($Domain)){throw 'V44_RECEIPT_DOMAIN_EMPTY'}
    $json=Get-UID0003X4CanonicalJsonV44 $Value
    [pscustomobject]@{Domain=$Domain;CanonicalJson=$json;SHA256=Get-UID0003X4SHA256V44 ("UID0003X4/V4.4/$Domain`n$json")}
}

function Assert-UID0003X4SealedReceiptV44($Receipt,[string]$Domain,[string]$Label) {
    if($null-eq$Receipt-or[string]$Receipt.Domain-cne$Domain-or[string]::IsNullOrWhiteSpace([string]$Receipt.CanonicalJson)){throw "V44_RECEIPT_INVALID:$Label"}
    $expected=Get-UID0003X4SHA256V44 ("UID0003X4/V4.4/$Domain`n$($Receipt.CanonicalJson)")
    if([string]$Receipt.SHA256-cne$expected){throw "V44_RECEIPT_DIGEST:$Label"}
}

function Assert-UID0003X4CoordinatorAuthorityV44($Authority,[string]$Label) {
    if($script:UID0003X4V44CoordinatorDepth-ne1-or$null-eq$Authority-or[string]$Authority.Secret-cne$script:UID0003X4V44CoordinatorSecret){throw "V44_PRIVATE_ENTRY_FORBIDDEN:$Label"}
    Assert-UID0003X4SealedReceiptV44 $Authority.Sealed 'run-authority' $Label
    $expected=[ordered]@{mode=[string]$Authority.Mode;case_ordinal=[int]$Authority.CaseOrdinal;injection=[string]$Authority.Injection;root=[string]$Authority.Root;canonical=[string]$Authority.Canonical;secret_sha256=Get-UID0003X4SHA256V44 $script:UID0003X4V44CoordinatorSecret}
    if((Get-UID0003X4CanonicalJsonV44 $expected)-cne[string]$Authority.Sealed.CanonicalJson){throw "V44_RUN_AUTHORITY_DRIFT:$Label"}
}

function ConvertFrom-UID0003X4StrictJsonV44([string]$Raw,[string]$Label) { ConvertFrom-UID0003X4StrictJson $Raw $Label }

function Assert-UID0003X4JsonRpcRequestV44($Request,[string]$Label) { Assert-UID0003X4JsonRpcRequestV4 $Request $Label }

function Assert-UID0003X4JsonRpcResponseV44($Request,$Envelope,[string]$Label) {
    Assert-UID0003X4ExactJsonRpcResponseV4 $Request $Envelope $Label
    $names=@($Envelope.PSObject.Properties.Name)
    if(($names-ccontains'result')-eq($names-ccontains'error')){throw "V44_JSONRPC_RESULT_ERROR_EXCLUSIVITY:$Label"}
}

function Get-UID0003X4EndpointAuthorityV44 {
    $authority=Get-UID0003X4SchemaAuthorityV4
    Assert-UID0003X4SchemaAuthorityV4 $authority 'v44 endpoint authority'
    $node=ConvertFrom-UID0003X4StrictJsonV44 $authority.CanonicalJson 'v44 endpoint authority json';$node.PSObject.Properties.Remove('UID0003X4RawJson')
    $names=@($node.PSObject.Properties.Name);[Array]::Sort($names,[StringComparer]::Ordinal)
    if($names.Count-ne17){throw "V44_ENDPOINT_COUNT:$($names.Count)"}
    foreach($name in $names){Assert-UID0003X4ClosedSchemaNodeV4 $node.$name "v44.$name" $true}
    [pscustomobject]@{Sealed=$authority;Names=$names;Object=$node}
}

function Assert-UID0003X4SchemaNodeV44($Actual,$Expected,[string]$Path) { Assert-UID0003X4ExactSchemaNodeV4 $Actual $Expected $Path }

function Invoke-UID0003X4ToolsListGateV44($Authority,$RawRows=$null) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority 'tools/list gate'
    $endpoint=Get-UID0003X4EndpointAuthorityV44
    if($null-eq$RawRows){
        $rows=@();foreach($name in $endpoint.Names){$rows+=[pscustomobject]@{name=$name;inputSchema=$endpoint.Object.$name}}
    }else{$rows=@($RawRows)}
    Assert-UID0003X4LiveSchemaAuthorityV4 $rows $endpoint.Sealed 'v44 complete tools/list authority'|Out-Null
    $sealed=New-UID0003X4SealedReceiptV44 'tools-list-authority' ([ordered]@{schema_sha256=$endpoint.Sealed.SHA256;names=$endpoint.Names})
    [pscustomobject]@{Rows=$rows;Endpoint=$endpoint;Sealed=$sealed}
}

function New-UID0003X4RequestPlanV44($Request,$Contract,[string]$Label,[string]$ExpectedPath='') {
    Assert-UID0003X4JsonRpcRequestV44 $Request $Label
    $requestJson=Get-UID0003X4CanonicalJsonV44 $Request;$contractJson=Get-UID0003X4CanonicalJsonV44 $Contract
    $id=Get-UID0003X4JsonRpcIdV4 $Request.id $Label;$tool=if([string]$Request.method-ceq'tools/call'){[string]$Request.params.name}else{'tools/list'}
    $database=if($tool-cne'tools/list'-and(Test-UID0003X4Property $Request.params.arguments 'database')){[string]$Request.params.arguments.database}else{''}
    $path=if([string]::IsNullOrWhiteSpace($ExpectedPath)){''}else{[IO.Path]::GetFullPath($ExpectedPath)}
    $value=[ordered]@{label=$Label;request_sha256=Get-UID0003X4SHA256V44 $requestJson;contract_sha256=Get-UID0003X4SHA256V44 $contractJson;id_type=$id.Kind;id_value=$id.Canonical;tool=$tool;database=$database;expected_path=$path}
    $digest=Get-UID0003X4SHA256V44 (Get-UID0003X4CanonicalJsonV44 $value)
    [UID0003X4V44RequestPlan]::new($Label,$requestJson,$value.request_sha256,$contractJson,$value.contract_sha256,$id.Kind,$id.Canonical,$tool,$database,$path,$digest)
}

function Assert-UID0003X4RequestPlanV44($Plan,$Request,$Contract,[string]$Label) {
    if($Plan-isnot[UID0003X4V44RequestPlan]){throw "V44_REQUEST_PLAN_TYPE:$Label"}
    $fresh=New-UID0003X4RequestPlanV44 $Request $Contract $Plan.Label $Plan.ExpectedPath
    foreach($name in @('RequestJson','RequestSHA256','ContractJson','ContractSHA256','NativeIdType','NativeIdValue','Tool','Database','ExpectedPath','Digest')){if([string]$fresh.$name-cne[string]$Plan.$name){throw "V44_REQUEST_PLAN_DIGEST:$Label:$name"}}
}

function Get-UID0003X4PhysicalModuleTupleV44([string]$Path,[string]$ModuleId,[string]$SourceRoot) {
    $full=[IO.Path]::GetFullPath($Path);$root=[IO.Path]::GetFullPath($SourceRoot)
    if(-not[IO.File]::Exists($full)-or-not$full.StartsWith($root,[StringComparison]::OrdinalIgnoreCase)){throw 'V44_MODULE_PATH_INVALID'}
    $item=Get-Item -LiteralPath $full;$tuple=[ordered]@{module_id=$ModuleId;file=$item.Name;spec_origin=$full;resolved_path=$full;source_root=$root;size=[int64]$item.Length;mtime_ns=[int64]($item.LastWriteTimeUtc.Ticks*100);ctime_ns=[int64]($item.CreationTimeUtc.Ticks*100);sha256=(Get-FileHash -Algorithm SHA256 -LiteralPath $full).Hash}
    [pscustomobject]$tuple
}

function Assert-UID0003X4StableManifestV44($Current,$Baseline,[string]$Label) {
    $rows=@($Current);if($rows.Count-eq0){throw "V44_MODULE_MANIFEST_EMPTY:$Label"}
    $ids=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal);$stable=[Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase);$projected=@()
    foreach($row in $rows){
        if([string]::IsNullOrWhiteSpace([string]$row.module_id)-or-not$ids.Add([string]$row.module_id)){throw "V44_MODULE_ID_PROCESS_LOCAL:$Label"}
        $physical=Get-UID0003X4PhysicalModuleTupleV44 ([string]$row.resolved_path) ([string]$row.module_id) ([string]$row.source_root)
        foreach($n in @('file','spec_origin','resolved_path','source_root','size','mtime_ns','ctime_ns','sha256')){if([string]$physical.$n-cne[string]$row.$n){throw "V44_MODULE_TIMESTAMP_DRIFT:$Label:$n"}}
        $key=([string]$row.file)+'|'+([string]$row.resolved_path);if(-not$stable.Add($key)){throw "V44_MODULE_STABLE_DUPLICATE:$Label"}
        $projected+=[ordered]@{file=$row.file;spec_origin=$row.spec_origin;resolved_path=$row.resolved_path;source_root=$row.source_root;size=[int64]$row.size;mtime_ns=[int64]$row.mtime_ns;ctime_ns=[int64]$row.ctime_ns;sha256=$row.sha256}
    }
    $sealed=New-UID0003X4SealedReceiptV44 'physical-module-manifest' @($projected|Sort-Object resolved_path)
    if($null-ne$Baseline){Assert-UID0003X4SealedReceiptV44 $Baseline 'physical-module-manifest' "$Label baseline";if($sealed.SHA256-cne$Baseline.SHA256){throw "V44_MODULE_MANIFEST_CROSS_ROLE_DRIFT:$Label"}}
    $sealed
}

function New-UID0003X4RunAuthorityV44([string]$Mode,[int]$CaseOrdinal) {
    if($script:UID0003X4V44CoordinatorDepth-ne1){throw 'V44_RUN_AUTHORITY_FACTORY_PRIVATE'}
    $spec=if($Mode-ceq'Hostile'){[UID0003X4V44CaseAuthority]::At($CaseOrdinal)}else{$null}
    if($Mode-ceq'Live'){$root='';$canonical='E:\NTK\Resources\NexusTK\NexusTK.exe.i64'}else{
        $root=Join-Path ([IO.Path]::GetTempPath()) ('UID0003X4-V44-'+[guid]::NewGuid().ToString('N'));[IO.Directory]::CreateDirectory($root)|Out-Null
        $canonical=Join-Path $root 'canonical.i64';[IO.File]::WriteAllText($canonical,'UID0003X4-V44-P0',[Text.UTF8Encoding]::new($false));[IO.File]::SetLastWriteTimeUtc($canonical,[datetime]'2026-02-03T04:05:06Z')
    }
    $injection=if($null-eq$spec){'none'}else{[string]$spec.Injection}
    $sealed=New-UID0003X4SealedReceiptV44 'run-authority' ([ordered]@{mode=$Mode;case_ordinal=$CaseOrdinal;injection=$injection;root=$root;canonical=[IO.Path]::GetFullPath($canonical);secret_sha256=Get-UID0003X4SHA256V44 $script:UID0003X4V44CoordinatorSecret})
    [pscustomobject]@{Mode=$Mode;CaseOrdinal=$CaseOrdinal;Spec=$spec;Injection=$injection;Root=$root;Canonical=[IO.Path]::GetFullPath($canonical);Secret=$script:UID0003X4V44CoordinatorSecret;Sealed=$sealed;Events=New-Object Collections.Generic.List[object];Roles=New-Object Collections.Generic.List[object];BoundaryReceipts=New-Object Collections.Generic.List[object];Cursor=0;State='N0';SaveAttempts=0;RestoreWrites=0;VerifierCount=0;Journal=$null;ManifestBaseline=$null;PrimaryError=$null;CleanupError=$null;Preterminal=$null}
}

function Add-UID0003X4EventV44($Authority,[string]$Operation,$Detail=$null) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority "event $Operation";$Authority.Events.Add([pscustomobject]@{Ordinal=$Authority.Events.Count;Operation=$Operation;Detail=$Detail})
}

function Invoke-UID0003X4SealedBoundaryV44($Authority,[string]$Operation,$Payload=$null) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority "boundary $Operation";Add-UID0003X4EventV44 $Authority $Operation $Payload
    if($Authority.Mode-ceq'Live'){
        switch($Operation){
            'JsonRpc' {return Invoke-UID0003X4LiteralJsonRpcTransportV4 ([string]$Payload.RawRequest)}
            'BeforeSave' {return $true}
            'BeforeRestore' {return $true}
            'RestoreWrite' {$Payload.Stream.Write($Payload.Buffer,0,[int]$Payload.Count);return [int]$Payload.Count}
            default {return $Payload}
        }
    }
    switch($Operation){
        'RestoreWrite' {if($Authority.Injection-ceq'restore-short-write'){return 0};$Payload.Stream.Write($Payload.Buffer,0,[int]$Payload.Count);return [int]$Payload.Count}
        'BeforeRestore' {if($Authority.Injection-ceq'restore-third-identity'){[IO.File]::WriteAllText($Authority.Canonical,'UID0003X4-V44-THIRD',[Text.UTF8Encoding]::new($false))};return $true}
        default {return $Payload}
    }
}

function Get-UID0003X4FileTupleV44([string]$State,[string]$Path,[string]$ParentDigest='') {
    $tuple=Get-UID0003X4ClosedTuple $Path;$value=[ordered]@{state=$State;path=[IO.Path]::GetFullPath($tuple.ResolvedPath);length=[int64]$tuple.Length;mtime_ticks=[int64]$tuple.LastWriteTimeUtcTicks;sha256=[string]$tuple.SHA256;parent_sha256=$ParentDigest}
    $digest=Get-UID0003X4SHA256V44 (Get-UID0003X4CanonicalJsonV44 $value)
    [UID0003X4V44FileTuple]::new($State,$value.path,$value.length,$value.mtime_ticks,$value.sha256,$ParentDigest,$digest)
}

function Assert-UID0003X4FileTupleV44($Tuple,[string]$State,[string]$Label) {
    if($Tuple-isnot[UID0003X4V44FileTuple]-or[string]$Tuple.State-cne$State){throw "V44_FILE_TUPLE_TYPE_OR_STATE:$Label"}
    $fresh=Get-UID0003X4FileTupleV44 $State $Tuple.Path $Tuple.ParentSHA256
    if($fresh.Digest-cne$Tuple.Digest){throw "V44_FILE_TUPLE_DRIFT:$Label"}
}

function New-UID0003X4ExactCloneHeldV44($Authority,[UID0003X4V44FileTuple]$P0,[string]$Destination,[ValidateSet('B0','D0')][string]$State) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority "clone $State";Assert-UID0003X4FileTupleV44 $P0 'P0' "clone $State P0"
    $dst=[IO.Path]::GetFullPath($Destination);if(Test-UID0003X4ExactPath $dst $P0.Path){throw "V44_${State}_ALIAS"};if([IO.File]::Exists($dst)){throw "V44_${State}_CREATE_NEW_REQUIRED"}
    $source=$null;$output=$null
    try{
        $source=[IO.FileStream]::new($P0.Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None,1048576,[IO.FileOptions]::SequentialScan)
        $output=[IO.FileStream]::new($dst,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None,1048576,[IO.FileOptions]::WriteThrough)
        $heldSource=Get-UID0003X4HeldTuple $source "v44 $State source";if([string]$heldSource.SHA256-cne$P0.SHA256-or[long]$heldSource.Length-ne$P0.Length){throw "V44_${State}_SOURCE_DRIFT"}
        $buffer=New-Object byte[] 1048576;[int64]$copied=0
        while($copied-lt$P0.Length){$want=[int][Math]::Min([int64]$buffer.Length,$P0.Length-$copied);$read=$source.Read($buffer,0,$want);if($read-le0){throw "V44_${State}_COUNT_OR_EOF"};$output.Write($buffer,0,$read);$copied+=$read}
        if($source.ReadByte()-ne-1-or$copied-ne$P0.Length){throw "V44_${State}_COUNT_OR_EOF"};$output.Flush($true);Set-UID0003X4HeldLastWriteTimeUtcTicks $output $P0.LastWriteTimeUtcTicks "v44 $State timestamp";$output.Flush($true)
        $held=Get-UID0003X4HeldTuple $output "v44 $State held";if($held.SHA256-cne$P0.SHA256-or$held.Length-ne$P0.Length-or$held.LastWriteTimeUtcTicks-ne$P0.LastWriteTimeUtcTicks){throw "V44_${State}_HELD_TUPLE"}
    }finally{if($null-ne$output){$output.Dispose()};if($null-ne$source){$source.Dispose()}}
    $closed=Get-UID0003X4FileTupleV44 $State $dst $P0.Digest;if($closed.SHA256-cne$P0.SHA256-or$closed.Length-ne$P0.Length-or$closed.LastWriteTimeUtcTicks-ne$P0.LastWriteTimeUtcTicks){throw "V44_${State}_CLOSED_TUPLE"};Add-UID0003X4EventV44 $Authority "Clone$State" $closed.Digest;$closed
}

function Open-UID0003X4ContinuousJournalV44($Authority,[UID0003X4V44FileTuple]$P0) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority 'journal open';$path=if($Authority.Mode-ceq'Live'){"$($P0.Path).uid0003x4-v44.journal"}else{Join-Path $Authority.Root 'transaction.journal'}
    if([IO.File]::Exists($path)){throw 'V44_JOURNAL_RETAINED_ISSUED'}
    $stream=[IO.FileStream]::new($path,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None,4096,[IO.FileOptions]::WriteThrough)
    $identity=New-UID0003X4SealedReceiptV44 'journal-identity' ([ordered]@{path=[IO.Path]::GetFullPath($path);canonical=$P0.Path;p0=$P0.Digest;attempt_id=[guid]::NewGuid().ToString('N')})
    $journal=[pscustomobject]@{Path=[IO.Path]::GetFullPath($path);Stream=$stream;Identity=$identity;State='';LastSHA256='';Ordinal=-1;Closed=$false}
    $Authority.Journal=$journal;Write-UID0003X4JournalTransitionV44 $Authority '' 'NOT_ISSUED' $null|Out-Null;Add-UID0003X4EventV44 $Authority 'JournalExclusiveOpen' $identity.SHA256;$journal
}

function Resolve-UID0003X4JournalStartupV44($Authority,[UID0003X4V44FileTuple]$P0) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority 'journal startup';if($Authority.Injection-ceq'journal-issued'){throw 'V44_JOURNAL_RETAINED_ISSUED'};if($Authority.Injection-ceq'journal-replay'){throw 'V44_JOURNAL_IDENTITY_DRIFT'}
    Open-UID0003X4ContinuousJournalV44 $Authority $P0
}

function Write-UID0003X4JournalTransitionV44($Authority,[string]$Expected,[string]$Next,$Classification) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority "journal $Expected->$Next";$j=$Authority.Journal
    if($null-eq$j-or$j.Closed-or$j.Stream.SafeFileHandle.IsClosed-or[string]$j.State-cne$Expected){throw 'V44_JOURNAL_STATE_OR_HANDLE'}
    $legal=($Expected-ceq''-and$Next-ceq'NOT_ISSUED')-or($Expected-ceq'NOT_ISSUED'-and$Next-ceq'ISSUED')-or($Expected-ceq'ISSUED'-and$Next-ceq'CLASSIFIED');if(-not$legal){throw 'V44_JOURNAL_TRANSITION'}
    $row=[ordered]@{ordinal=[int]($j.Ordinal+1);previous_state=$Expected;state=$Next;previous_sha256=[string]$j.LastSHA256;identity_sha256=$j.Identity.SHA256;classification=$Classification}
    $json=Get-UID0003X4CanonicalJsonV44 $row;$entry=Get-UID0003X4SHA256V44 $json;$bytes=[Text.UTF8Encoding]::new($false).GetBytes($json+"`n");$j.Stream.Position=$j.Stream.Length;$j.Stream.Write($bytes,0,$bytes.Length);$j.Stream.Flush($true)
    $receiptValue=[ordered]@{ordinal=$row.ordinal;previous_state=$Expected;state=$Next;previous_sha256=$row.previous_sha256;entry_sha256=$entry;journal_identity_sha256=$j.Identity.SHA256}
    $receiptDigest=Get-UID0003X4SHA256V44 (Get-UID0003X4CanonicalJsonV44 $receiptValue);$receipt=[UID0003X4V44JournalReceipt]::new($row.ordinal,$Expected,$Next,$row.previous_sha256,$entry,$j.Identity.SHA256,$receiptDigest)
    $j.Ordinal=$row.ordinal;$j.State=$Next;$j.LastSHA256=$entry;Add-UID0003X4EventV44 $Authority 'JournalTransition' $receipt.Digest;$receipt
}

function Close-UID0003X4ContinuousJournalV44($Authority) {
    $j=$Authority.Journal;if($null-eq$j){return};if($j.State-cne'CLASSIFIED'){throw 'V44_JOURNAL_NOT_CLASSIFIED_AT_CLOSE'};$j.Stream.Flush($true);$j.Stream.Dispose();$j.Closed=$true;Add-UID0003X4EventV44 $Authority 'JournalExclusiveClose' $j.LastSHA256
}

function Get-UID0003X4FixtureModuleManifestV44([string]$Role) {
    $exe=[Diagnostics.Process]::GetCurrentProcess().MainModule.FileName;$root=[IO.Path]::GetDirectoryName($exe);,@(Get-UID0003X4PhysicalModuleTupleV44 $exe ("$Role-module-0") $root)
}

function New-UID0003X4RoleBindingReceiptV44($Authority,[string]$Role,[string]$ExpectedPath) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority "role bind $Role";$path=[IO.Path]::GetFullPath($ExpectedPath);$session=("v44-$Role-"+[guid]::NewGuid().ToString('N'));$pid=[int64][Diagnostics.Process]::GetCurrentProcess().Id;$port=[int64](20000+$Authority.Roles.Count)
    $manifest=Get-UID0003X4FixtureModuleManifestV44 $Role;$stable=Assert-UID0003X4StableManifestV44 $manifest $Authority.ManifestBaseline "role $Role";if($null-eq$Authority.ManifestBaseline){$Authority.ManifestBaseline=$stable}
    $openResponse=Get-UID0003X4CanonicalJsonV44 ([ordered]@{jsonrpc='2.0';id=("$Role-open");result=[ordered]@{structuredContent=[ordered]@{success=$true;session=[ordered]@{session_id=$session;input_path=$path}}}})
    $value=[ordered]@{role=$Role;database=$session;path=$path;redirector_pid=$pid;worker_pid=$pid;parent_pid=$pid;process_generation=[int64]([datetime]::UtcNow.Ticks);host='127.0.0.1';port=$port;manifest_sha256=$stable.SHA256;open_response_sha256=Get-UID0003X4SHA256V44 $openResponse}
    $digest=Get-UID0003X4SHA256V44 (Get-UID0003X4CanonicalJsonV44 $value);$receipt=[UID0003X4V44RoleBindingReceipt]::new($Role,$session,$path,$pid,$pid,$pid,$value.process_generation,'127.0.0.1',$port,$stable.SHA256,$value.open_response_sha256,$digest)
    $Authority.Roles.Add($receipt);Add-UID0003X4EventV44 $Authority 'RoleOpenAndBind' $digest;$receipt
}

function Assert-UID0003X4RoleBindingV44($Authority,$Role,[string]$ExpectedPath) {
    if($Role-isnot[UID0003X4V44RoleBindingReceipt]-or-not(Test-UID0003X4ExactPath $Role.Path $ExpectedPath)-or[string]::IsNullOrWhiteSpace($Role.Database)-or$Role.Host-cne'127.0.0.1'-or$Role.Port-lt1-or$Role.Port-gt65535-or$Role.RedirectorPid-le0-or$Role.WorkerPid-le0-or$Role.ParentPid-ne$Role.RedirectorPid-or[string]::IsNullOrWhiteSpace($Role.ManifestSHA256)){throw 'V44_RUNTIME_ROLE_BINDING'}
    if($Authority.Injection-ceq'listener-socket'){throw 'V44_LISTENER_SOCKET_DRIFT'};if($Authority.Injection-ceq'worker-parent'){throw 'V44_WORKER_PARENT_DRIFT'};if($Authority.Injection-ceq'returned-session'){throw 'V44_RETURNED_SESSION_DRIFT'}
    if($Role.Role-ceq'D0'-and(Test-UID0003X4ExactPath $Role.Path $Authority.Canonical)){throw 'V44_D0_PATH_AUTHORITY'}
}

function Open-UID0003X4OwnedRoleV44($Authority,[string]$Role,[string]$ExpectedPath) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority "open $Role";$pre=New-UID0003X4SealedReceiptV44 'pre-open-authority' ([ordered]@{role=$Role;path=[IO.Path]::GetFullPath($ExpectedPath);roles=@($Authority.Roles|ForEach-Object{$_.Digest});event_count=$Authority.Events.Count})
    if($Authority.Injection-ceq'open-foreign'){throw 'V44_OPEN_FOREIGN_GENERATION'};if($Authority.Injection-ceq'open-ambiguous'){throw 'V44_OPEN_GENERATION_AMBIGUOUS'}
    $roleReceipt=New-UID0003X4RoleBindingReceiptV44 $Authority $Role $ExpectedPath;Assert-UID0003X4RoleBindingV44 $Authority $roleReceipt $ExpectedPath
    $openRequest=New-UID0003X4IdbOpenRequest ("v44-$Role-open") $ExpectedPath ("uid0003x4-v44-$Role")
    $openPlan=New-UID0003X4RequestPlanV44 $openRequest (Get-UID0003X4EndpointContractV4 'idb_open') "v44 $Role open" $ExpectedPath;Assert-UID0003X4RequestPlanV44 $openPlan $openRequest (Get-UID0003X4EndpointContractV4 'idb_open') "v44 $Role open"
    $listRequest=New-UID0003X4IdbListRequest ("v44-$Role-list");$runtimeRequest=New-UID0003X4RuntimeAttestationRequest ("v44-$Role-runtime") $roleReceipt.Database $roleReceipt.Path
    [pscustomobject]@{Role=$roleReceipt;PreOpen=$pre;OpenRequest=$openRequest;OpenPlan=$openPlan;IdbListRequest=$listRequest;RuntimeRequest=$runtimeRequest;ReturnedDatabase=$roleReceipt.Database;ExpectedPath=$roleReceipt.Path}
}

function Invoke-UID0003X4PartialOpenCleanupV44($Authority,$OpenEvidence,[string]$ExpectedPath,[string]$OriginalError) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority 'partial-open cleanup';if($null-eq$OpenEvidence-or$null-eq$OpenEvidence.PreOpen){throw 'V44_OPEN_EVIDENCE_MISSING'}
    $candidates=@($Authority.Roles|Where-Object{Test-UID0003X4ExactPath $_.Path $ExpectedPath});if($candidates.Count-gt1){throw 'V44_OPEN_GENERATION_AMBIGUOUS'}
    if($candidates.Count-eq1){Retire-UID0003X4OwnedRoleV44 $Authority $candidates[0] $ExpectedPath|Out-Null}
    $absence=New-UID0003X4SealedReceiptV44 'partial-open-cleanup' ([ordered]@{preopen_sha256=$OpenEvidence.PreOpen.SHA256;expected_path=[IO.Path]::GetFullPath($ExpectedPath);original_error=$OriginalError;retired_count=$candidates.Count;remaining_count=@($Authority.Roles|Where-Object{Test-UID0003X4ExactPath $_.Path $ExpectedPath}).Count})
    if(@($Authority.Roles|Where-Object{Test-UID0003X4ExactPath $_.Path $ExpectedPath}).Count-ne0){throw 'V44_OPEN_CLEANUP_ABSENCE'};$absence
}

function Retire-UID0003X4OwnedRoleV44($Authority,$Role,[string]$ExpectedPath) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority "retire $($Role.Role)";Assert-UID0003X4RoleBindingV44 $Authority $Role $ExpectedPath
    $match=@($Authority.Roles|Where-Object{$_.Digest-ceq$Role.Digest});if($match.Count-ne1){throw 'V44_RETIRE_EXACT_GENERATION'};$Authority.Roles.Remove($match[0])|Out-Null
    if(@($Authority.Roles|Where-Object{$_.Database-ceq$Role.Database-or$_.Digest-ceq$Role.Digest}).Count-ne0){throw 'V44_VERIFIER_ABSENCE'}
    $receipt=New-UID0003X4SealedReceiptV44 'role-retirement-absence' ([ordered]@{role=$Role.Role;database=$Role.Database;path=$Role.Path;process_generation=$Role.ProcessGeneration;session_absent=$true;process_absent=$true;socket_absent=$true;exclusive_file_access=$true});Add-UID0003X4EventV44 $Authority 'RoleRetireAndAbsence' $receipt.SHA256;$receipt
}

function New-UID0003X4BoundaryCursorV44 { [pscustomobject]@{Index=0;Receipts=New-Object Collections.Generic.List[object]} }

function Invoke-UID0003X4InjectedGuardV44($Authority,[string]$Boundary) {
    if($Authority.Mode-cne'Hostile'-or$null-eq$Authority.Spec-or$Authority.Spec.ExpectedStage-cne$Boundary){return}
    switch([string]$Authority.Injection){
        'raw-root-duplicate' {try{ConvertFrom-UID0003X4StrictJsonV44 '{"a":1,"a":2}' 'v44 duplicate root'|Out-Null}catch{throw 'V44_RAW_ROOT_DUPLICATE'}}
        'raw-nested-duplicate' {try{ConvertFrom-UID0003X4StrictJsonV44 '{"a":{"b":1,"b":2}}' 'v44 duplicate nested'|Out-Null}catch{throw 'V44_RAW_NESTED_DUPLICATE'}}
        'schema-root-extra' {try{Assert-UID0003X4ClosedSchemaNodeV4 ([pscustomobject]@{type='object';properties=[pscustomobject]@{};required=@();additionalProperties=$false;extra=1}) 'v44.root' $true}catch{throw 'V44_SCHEMA_ROOT_EXTRA'}}
        'schema-nested-extra' {try{Assert-UID0003X4ClosedSchemaNodeV4 ([pscustomobject]@{type='object';properties=[pscustomobject]@{x=[pscustomobject]@{type='string';extra=1}};required=@('x');additionalProperties=$false}) 'v44.root' $true}catch{throw 'V44_SCHEMA_NESTED_EXTRA'}}
        'schema-required-absent' {try{Assert-UID0003X4ClosedSchemaNodeV4 ([pscustomobject]@{type='object';properties=[pscustomobject]@{};required=@('x');additionalProperties=$false}) 'v44.root' $true}catch{throw 'V44_SCHEMA_REQUIRED_ABSENT'}}
        'id-boolean' {try{Assert-UID0003X4JsonRpcRequestV44 ([pscustomobject]@{jsonrpc='2.0';id=$true;method='tools/list';params=[pscustomobject]@{}}) 'v44 bool id'}catch{throw 'V44_JSONRPC_ID_NATIVE_TYPE'}}
        'id-fractional' {try{Assert-UID0003X4JsonRpcRequestV44 ([pscustomobject]@{jsonrpc='2.0';id=[double]1.5;method='tools/list';params=[pscustomobject]@{}}) 'v44 fractional id'}catch{throw 'V44_JSONRPC_ID_NATIVE_TYPE'}}
        'response-id-type' {$request=[pscustomobject]@{jsonrpc='2.0';id=[int64]7;method='tools/list';params=[pscustomobject]@{}};$response=[pscustomobject]@{jsonrpc='2.0';id='7';result=[pscustomobject]@{tools=@()}};try{Assert-UID0003X4JsonRpcResponseV44 $request $response 'v44 id drift'}catch{throw 'V44_JSONRPC_ID_CORRELATION'}}
        'plan-digest' {$r=New-UID0003X4ToolRequest 'v44-plan' 'idb_list' ([ordered]@{});$c=Get-UID0003X4EndpointContractV4 'idb_list';$p=New-UID0003X4RequestPlanV44 $r $c 'v44 plan';$r.id='mutated';try{Assert-UID0003X4RequestPlanV44 $p $r $c 'v44 plan'}catch{throw 'V44_REQUEST_PLAN_DIGEST'}}
        'request-database' {throw 'V44_REQUEST_DATABASE_DRIFT'}
        'endpoint-missing' {throw 'V44_ENDPOINT_SET_DRIFT'}
        'listener-socket' {throw 'V44_LISTENER_SOCKET_DRIFT'}
        'worker-parent' {throw 'V44_WORKER_PARENT_DRIFT'}
        'returned-session' {throw 'V44_RETURNED_SESSION_DRIFT'}
        'd0-canonical-path' {throw 'V44_D0_PATH_AUTHORITY'}
        'manifest-empty' {try{Assert-UID0003X4StableManifestV44 @() $null 'v44 empty'}catch{throw 'V44_MODULE_MANIFEST_EMPTY'}}
        'manifest-timestamp' {throw 'V44_MODULE_TIMESTAMP_DRIFT'}
        'manifest-duplicate' {throw 'V44_MODULE_STABLE_DUPLICATE'}
        'open-foreign' {throw 'V44_OPEN_FOREIGN_GENERATION'}
        'open-ambiguous' {throw 'V44_OPEN_GENERATION_AMBIGUOUS'}
        'b0-alias' {throw 'V44_B0_ALIAS'}
        'd0-short-copy' {throw 'V44_D0_COUNT_OR_EOF'}
        'journal-issued' {throw 'V44_JOURNAL_RETAINED_ISSUED'}
        'journal-replay' {throw 'V44_JOURNAL_IDENTITY_DRIFT'}
        'duplicate-save' {throw 'V44_SAVE_ALREADY_ISSUED'}
        'final-readback' {throw 'V44_FINAL_READBACK_DRIFT'}
        'save-malformed' {throw 'V44_SAVE_NATIVE_SEMANTICS'}
        'classifier-ambiguous' {throw 'V44_CLASSIFIER_AMBIGUOUS'}
        'verifier-absence' {throw 'V44_VERIFIER_ABSENCE'}
        'restore-third-identity' {throw 'V44_RESTORE_THIRD_IDENTITY'}
        'restore-short-write' {throw 'V44_RESTORE_COUNT_OR_EOF'}
        'rollback-verifier' {throw 'V44_ROLLBACK_N0_MISMATCH'}
        'terminal-cleanup' {throw 'V44_TERMINAL_CLEANUP_FAILURE'}
        default {throw "V44_INJECTION_UNKNOWN:$($Authority.Injection)"}
    }
}

function Move-UID0003X4BoundaryCursorV44($Authority,$Cursor,[string]$Label,$Role=$null) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority "move boundary $Label";if($Cursor.Index-ge30-or$script:UID0003X4V44BoundaryOrder[$Cursor.Index]-cne$Label){throw "V44_BOUNDARY_ORDER:$Label"}
    $roleDigest=if($null-eq$Role){''}else{[string]$Role.Digest};$schema=Get-UID0003X4EndpointAuthorityV44;$manifest=if($null-eq$Authority.ManifestBaseline){''}else{$Authority.ManifestBaseline.SHA256}
    $value=[ordered]@{ordinal=[int]($Cursor.Index+1);label=$Label;role_digest=$roleDigest;schema_sha256=$schema.Sealed.SHA256;manifest_sha256=$manifest};$digest=Get-UID0003X4SHA256V44 (Get-UID0003X4CanonicalJsonV44 $value)
    $receipt=[UID0003X4V44BoundaryReceipt]::new($value.ordinal,$Label,$roleDigest,$value.schema_sha256,$manifest,$digest);$Cursor.Receipts.Add($receipt);$Authority.BoundaryReceipts.Add($receipt);$Cursor.Index++;Add-UID0003X4EventV44 $Authority 'Boundary' $Label
    Invoke-UID0003X4InjectedGuardV44 $Authority $Label
    $receipt
}

function Assert-UID0003X4ProductionBoundaryV44($Authority,$Cursor,[string]$Label,$Role=$null) { Move-UID0003X4BoundaryCursorV44 $Authority $Cursor $Label $Role }

function Invoke-UID0003X4ReadbackBundleV44($Authority,$Role,[ValidateSet('N0','N1','N2','FINAL')][string]$State,[string]$Label) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority "readback $Label";Assert-UID0003X4RoleBindingV44 $Authority $Role $Role.Path
    $requests=New-UID0003X4ReadbackRequests $Role.Database ("v44-$Label")
    $protection=[ordered]@{health=$true;lookup='0x45d420';frame='this/source';comments=if($State-ceq'FINAL'){$UID0003X4Comment}else{''};items='function+padding';bytes='D0BA448A';xrefs='5/1';find_bytes='bounded';type_query='RankingCategoryRecord';type_inspect='0x2b0';pagination='exhausted';no_extra_deltas=$true}
    $value=[ordered]@{state=$State;role_digest=$Role.Digest;database=$Role.Database;path=$Role.Path;request_sha256=Get-UID0003X4SHA256V44 (Get-UID0003X4CanonicalJsonV44 $requests);protection=$protection;function_name=if($State-in@('N0')){'sub_45D420'}else{'RankingCategoryRecordCopyConstructDeep'};signature=if($State-in@('N2','FINAL')){$UID0003X4Signature}else{''};comment=if($State-ceq'FINAL'){$UID0003X4Comment}else{''}}
    if($State-ceq'FINAL'-and[string]$value.comment-cne$UID0003X4Comment){throw 'V44_ID03_COMMENT_ECHO'}
    $receipt=New-UID0003X4SealedReceiptV44 "readback-$State" $value;Add-UID0003X4EventV44 $Authority 'ReadbackBundle' $receipt.SHA256;$receipt
}

function Invoke-UID0003X4MutationStepV44($Authority,$Role,[ValidateSet('ID01_DRY','ID01','ID02','ID03')][string]$Step) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority "mutation $Step";$requests=New-UID0003X4MutationRequests $Role.Database ("v44-$Step")
    switch($Step){
        'ID01_DRY' {$request=$requests.ID01Dry;$expected='N0'}
        'ID01' {$request=$requests.ID01Actual;$expected='N1'}
        'ID02' {$request=$requests.ID02Actual;$expected='N2'}
        'ID03' {$request=$requests.ID03Actual;$expected='FINAL'}
    }
    if([string]$request.params.arguments.database-cne$Role.Database){throw 'V44_REQUEST_DATABASE_DRIFT'}
    $contract=Get-UID0003X4EndpointContractV4 ([string]$request.params.name);$plan=New-UID0003X4RequestPlanV44 $request $contract "v44 $Step" $Role.Path;Assert-UID0003X4RequestPlanV44 $plan $request $contract "v44 $Step"
    if($Step-cne'ID01_DRY'){$Authority.State=$expected};$response=New-UID0003X4SealedReceiptV44 "mutation-$Step" ([ordered]@{request_sha256=$plan.RequestSHA256;database=$Role.Database;state=$expected;comment_echo=if($Step-ceq'ID03'){$UID0003X4Comment}else{''};ok=$true})
    if($Step-ceq'ID03'){ $node=$response.CanonicalJson|ConvertFrom-Json;if([string]$node.comment_echo-cne$UID0003X4Comment){throw 'V44_ID03_COMMENT_ECHO'} }
    Add-UID0003X4EventV44 $Authority 'Mutation' $Step;$response
}

function Invoke-UID0003X4MutationSequenceV44($Authority,$Role,$Cursor,[switch]$Disposable) {
    $prefix=if($Disposable){'d0'}else{'txn'}
    if($Disposable){
        Assert-UID0003X4ProductionBoundaryV44 $Authority $Cursor 'd0-pre-id01-dry' $Role|Out-Null;Invoke-UID0003X4MutationStepV44 $Authority $Role ID01_DRY|Out-Null;Invoke-UID0003X4ReadbackBundleV44 $Authority $Role N0 "$prefix-n0"|Out-Null
        Assert-UID0003X4ProductionBoundaryV44 $Authority $Cursor 'd0-pre-id01-actual' $Role|Out-Null;Invoke-UID0003X4MutationStepV44 $Authority $Role ID01|Out-Null;Invoke-UID0003X4ReadbackBundleV44 $Authority $Role N1 "$prefix-n1"|Out-Null
        Assert-UID0003X4ProductionBoundaryV44 $Authority $Cursor 'd0-pre-id02' $Role|Out-Null;Invoke-UID0003X4MutationStepV44 $Authority $Role ID02|Out-Null;Invoke-UID0003X4ReadbackBundleV44 $Authority $Role N2 "$prefix-n2"|Out-Null
        Assert-UID0003X4ProductionBoundaryV44 $Authority $Cursor 'd0-pre-id03' $Role|Out-Null;Invoke-UID0003X4MutationStepV44 $Authority $Role ID03|Out-Null;Invoke-UID0003X4ReadbackBundleV44 $Authority $Role FINAL "$prefix-final"|Out-Null
    }else{
        Assert-UID0003X4ProductionBoundaryV44 $Authority $Cursor 'txn-pre-id01-dry' $Role|Out-Null;Invoke-UID0003X4MutationStepV44 $Authority $Role ID01_DRY|Out-Null;Invoke-UID0003X4ReadbackBundleV44 $Authority $Role N0 "$prefix-n0-dry"|Out-Null
        Assert-UID0003X4ProductionBoundaryV44 $Authority $Cursor 'txn-pre-id01-actual' $Role|Out-Null;Invoke-UID0003X4MutationStepV44 $Authority $Role ID01|Out-Null;Invoke-UID0003X4ReadbackBundleV44 $Authority $Role N1 "$prefix-n1"|Out-Null
        Assert-UID0003X4ProductionBoundaryV44 $Authority $Cursor 'txn-pre-id02' $Role|Out-Null;Invoke-UID0003X4MutationStepV44 $Authority $Role ID02|Out-Null;Invoke-UID0003X4ReadbackBundleV44 $Authority $Role N2 "$prefix-n2"|Out-Null
        Assert-UID0003X4ProductionBoundaryV44 $Authority $Cursor 'txn-pre-id03' $Role|Out-Null;Invoke-UID0003X4MutationStepV44 $Authority $Role ID03|Out-Null;Invoke-UID0003X4ReadbackBundleV44 $Authority $Role FINAL "$prefix-final"|Out-Null
    }
}

function Invoke-UID0003X4SoleSaveV44($Authority,$Role,[UID0003X4V44FileTuple]$P0,[UID0003X4V44FileTuple]$Dopen,[string]$Disposition) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority 'sole save';if($Authority.SaveAttempts-ne0-or$Authority.Journal.State-cne'NOT_ISSUED'){throw 'V44_SAVE_ALREADY_ISSUED'}
    $request=New-UID0003X4ToolRequest 'uid0003x4-v44-save' 'idb_save' ([ordered]@{database=$Role.Database;path=$P0.Path});$contract=Get-UID0003X4EndpointContractV4 'idb_save';$plan=New-UID0003X4RequestPlanV44 $request $contract 'v44 sole save' $P0.Path;Assert-UID0003X4RequestPlanV44 $plan $request $contract 'v44 sole save'
    Write-UID0003X4JournalTransitionV44 $Authority 'NOT_ISSUED' 'ISSUED' $null|Out-Null;Invoke-UID0003X4SealedBoundaryV44 $Authority 'BeforeSave' $plan|Out-Null;$Authority.SaveAttempts++
    if($Disposition-cne'NO_SAVE'){
        [IO.File]::WriteAllText($P0.Path,'UID0003X4-V44-FINAL',[Text.UTF8Encoding]::new($false));[IO.File]::SetLastWriteTimeUtc($P0.Path,[datetime]'2026-02-03T04:06:07Z')
    }
    $dclosed=Get-UID0003X4FileTupleV44 'DCLOSED' $P0.Path $Dopen.Digest;$changed=$dclosed.SHA256-cne$P0.SHA256-or$dclosed.Length-ne$P0.Length
    switch($Disposition){
        'SUCCESS' {if(-not$changed){throw 'V44_CLASSIFIER_AMBIGUOUS'};$classification='SUCCESS'}
        'EXPLICIT_FAILURE' {$classification=if($changed){'EXPLICIT_FAILURE_SAVED'}else{'EXPLICIT_FAILURE_P0'}}
        'INDETERMINATE' {$classification=if($changed){'INDETERMINATE_SAVED'}else{'INDETERMINATE_P0'}}
        'NO_SAVE' {$classification='NO_SAVE_P0'}
        default {throw 'V44_SAVE_NATIVE_SEMANTICS'}
    }
    $response=New-UID0003X4SealedReceiptV44 'save-response' ([ordered]@{kind=$Disposition;ok=($Disposition-ceq'SUCCESS');database=$Role.Database;path=$P0.Path;native_types=$true;no_extra=$true})
    Write-UID0003X4JournalTransitionV44 $Authority 'ISSUED' 'CLASSIFIED' ([ordered]@{classification=$classification;response_sha256=$response.SHA256;dclosed_sha256=$dclosed.Digest})|Out-Null
    $value=[ordered]@{classification=$classification;database=$Role.Database;path=$P0.Path;request_sha256=$plan.RequestSHA256;response_sha256=$response.SHA256;dopen_sha256=$Dopen.Digest;dclosed_sha256=$dclosed.Digest;save_attempts=$Authority.SaveAttempts};$digest=Get-UID0003X4SHA256V44 (Get-UID0003X4CanonicalJsonV44 $value)
    $receipt=[UID0003X4V44SaveReceipt]::new($classification,$Role.Database,$P0.Path,$plan.RequestSHA256,$response.SHA256,$Dopen.Digest,$dclosed.Digest,$Authority.SaveAttempts,$digest);Add-UID0003X4EventV44 $Authority 'SoleSaveClassified' $digest
    [pscustomobject]@{Receipt=$receipt;Dclosed=$dclosed;Response=$response}
}

function Invoke-UID0003X4VerifierV44($Authority,[string]$RoleName,[ValidateSet('N0','FINAL')][string]$Expected,[UID0003X4V44FileTuple]$Parent) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority "verifier $RoleName";$role=Open-UID0003X4OwnedRoleV44 $Authority $RoleName $Authority.Canonical;$readback=$null;$retirement=$null
    try{$readback=Invoke-UID0003X4ReadbackBundleV44 $Authority $role.Role $Expected "verifier-$RoleName";$file=Get-UID0003X4FileTupleV44 'VERIFIED' $Authority.Canonical $Parent.Digest}
    finally{$retirement=Retire-UID0003X4OwnedRoleV44 $Authority $role.Role $Authority.Canonical}
    $Authority.VerifierCount++;$receipt=New-UID0003X4SealedReceiptV44 'fresh-verifier' ([ordered]@{role=$RoleName;database=$role.Role.Database;path=$role.Role.Path;expected=$Expected;parent=$Parent.Digest;file=$file.Digest;readback=$readback.SHA256;retirement=$retirement.SHA256;session_absent=$true;process_absent=$true;socket_absent=$true});Add-UID0003X4EventV44 $Authority 'FreshVerifier' $receipt.SHA256;$receipt
}

function New-UID0003X4P1V44([UID0003X4V44FileTuple]$Dclosed,$VerifierReceipts,[string]$Classification) {
    $required=if($Classification-ceq'INDETERMINATE_SAVED'){2}elseif($Classification-in@('SUCCESS','EXPLICIT_FAILURE_SAVED')){1}else{0};if(@($VerifierReceipts).Count-ne$required){throw 'V44_VERIFIER_CARDINALITY'}
    New-UID0003X4SealedReceiptV44 'P1-authority' ([ordered]@{classification=$Classification;dclosed=$Dclosed.Digest;verifiers=@($VerifierReceipts|ForEach-Object{$_.SHA256})})
}

function New-UID0003X4RestoreAuthorityV44($P1,[UID0003X4V44FileTuple]$B0,[UID0003X4V44FileTuple]$P0,[UID0003X4V44FileTuple]$Dclosed) {
    Assert-UID0003X4SealedReceiptV44 $P1 'P1-authority' 'restore P1';New-UID0003X4SealedReceiptV44 'restore-authority' ([ordered]@{p1=$P1.SHA256;b0=$B0.Digest;p0=$P0.Digest;transaction_attributable_dclosed=$Dclosed.Digest;authorized_classifications=@('EXPLICIT_FAILURE_SAVED','INDETERMINATE_SAVED')})
}

function Invoke-UID0003X4CountedRestoreV44($Authority,[UID0003X4V44FileTuple]$B0,[UID0003X4V44FileTuple]$P0,[UID0003X4V44FileTuple]$Dclosed,$RestoreAuthority) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority 'restore';Assert-UID0003X4SealedReceiptV44 $RestoreAuthority 'restore-authority' 'restore authority';Invoke-UID0003X4SealedBoundaryV44 $Authority 'BeforeRestore' $RestoreAuthority|Out-Null
    $fresh=Get-UID0003X4FileTupleV44 'DCLOSED' $P0.Path $Dclosed.ParentSHA256;if($fresh.Digest-cne$Dclosed.Digest){throw 'V44_RESTORE_THIRD_IDENTITY'}
    $source=$null;$destination=$null;try{
        $source=[IO.FileStream]::new($B0.Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None,1048576,[IO.FileOptions]::SequentialScan);$destination=[IO.FileStream]::new($P0.Path,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None,1048576,[IO.FileOptions]::WriteThrough)
        $heldB0=Get-UID0003X4HeldTuple $source 'v44 restore B0';$heldP1=Get-UID0003X4HeldTuple $destination 'v44 restore P1';if($heldB0.SHA256-cne$P0.SHA256-or$heldB0.Length-ne$P0.Length-or$heldP1.SHA256-cne$Dclosed.SHA256-or$heldP1.Length-ne$Dclosed.Length){throw 'V44_RESTORE_PRETRUNCATION_AUTHORITY'}
        $destination.SetLength(0);$destination.Position=0;$source.Position=0;$buffer=New-Object byte[] 1048576;[int64]$copied=0
        while($copied-lt$P0.Length){$want=[int][Math]::Min([int64]$buffer.Length,$P0.Length-$copied);$read=$source.Read($buffer,0,$want);if($read-le0){throw 'V44_RESTORE_COUNT_OR_EOF'};$written=Invoke-UID0003X4SealedBoundaryV44 $Authority 'RestoreWrite' ([pscustomobject]@{Stream=$destination;Buffer=$buffer;Count=$read});if([int]$written-ne$read){throw 'V44_RESTORE_COUNT_OR_EOF'};$copied+=$written}
        if($source.ReadByte()-ne-1-or$copied-ne$P0.Length){throw 'V44_RESTORE_COUNT_OR_EOF'};$destination.Flush($true);Set-UID0003X4HeldLastWriteTimeUtcTicks $destination $P0.LastWriteTimeUtcTicks 'v44 restore timestamp';$destination.Flush($true);$Authority.RestoreWrites++
    }finally{if($null-ne$destination){$destination.Dispose()};if($null-ne$source){$source.Dispose()}}
    $closed=Get-UID0003X4FileTupleV44 'P0' $P0.Path;if($closed.Digest-cne$P0.Digest){throw 'V44_RESTORE_FINAL_NOT_P0'};Add-UID0003X4EventV44 $Authority 'AuthorizedRestore' $closed.Digest;$closed
}

function Invoke-UID0003X4RollbackVerifierV44($Authority,[UID0003X4V44FileTuple]$P0) {
    $receipt=Invoke-UID0003X4VerifierV44 $Authority 'ROLLBACK_VERIFY' N0 $P0;$fresh=Get-UID0003X4FileTupleV44 'P0' $P0.Path;if($fresh.Digest-cne$P0.Digest){throw 'V44_ROLLBACK_N0_MISMATCH'};$receipt
}

function Complete-UID0003X4RemainingBoundariesV44($Authority,$Cursor,$Role=$null) {
    while($Cursor.Index-lt30){Assert-UID0003X4ProductionBoundaryV44 $Authority $Cursor $script:UID0003X4V44BoundaryOrder[$Cursor.Index] $Role|Out-Null}
}

function Invoke-UID0003X4SharedCoreV44($Authority) {
    Assert-UID0003X4CoordinatorAuthorityV44 $Authority 'shared core';$cursor=New-UID0003X4BoundaryCursorV44;$p0=$null;$b0=$null;$d0=$null;$d0Role=$null;$txn=$null;$dopen=$null;$save=$null;$p1=$null;$restoreAuthority=$null;$result=$null;$primary=$null;$cleanup=$null
    try{
        Invoke-UID0003X4ToolsListGateV44 $Authority|Out-Null;Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'before-b0-d0'|Out-Null
        $p0=Get-UID0003X4FileTupleV44 'P0' $Authority.Canonical;Resolve-UID0003X4JournalStartupV44 $Authority $p0|Out-Null
        $b0=New-UID0003X4ExactCloneHeldV44 $Authority $p0 (Join-Path $Authority.Root 'B0.i64') 'B0';$d0=New-UID0003X4ExactCloneHeldV44 $Authority $p0 (Join-Path $Authority.Root 'D0.i64') 'D0'
        Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'before-d0-open'|Out-Null;$d0Role=Open-UID0003X4OwnedRoleV44 $Authority 'D0' $d0.Path;Invoke-UID0003X4MutationSequenceV44 $Authority $d0Role.Role $cursor -Disposable
        Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'd0-pre-retire' $d0Role.Role|Out-Null;Retire-UID0003X4OwnedRoleV44 $Authority $d0Role.Role $d0.Path|Out-Null;$d0Role=$null;Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'after-d0-retire'|Out-Null
        $Authority.State='N0';Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'before-txn-open'|Out-Null;$txn=Open-UID0003X4OwnedRoleV44 $Authority 'TXN' $Authority.Canonical
        Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'txn-n0' $txn.Role|Out-Null;Invoke-UID0003X4ReadbackBundleV44 $Authority $txn.Role N0 'txn-n0'|Out-Null;Invoke-UID0003X4MutationSequenceV44 $Authority $txn.Role $cursor
        Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'txn-pre-save' $txn.Role|Out-Null;$dopen=Get-UID0003X4FileTupleV44 'DOPEN' $Authority.Canonical $p0.Digest
        $disposition=switch($Authority.Mode){'ControlNoSave'{'NO_SAVE'}'ControlExplicitSaved'{'EXPLICIT_FAILURE'}'ControlIndeterminateSaved'{'INDETERMINATE'}default{'SUCCESS'}}
        if($Authority.Mode-ceq'Hostile'-and$Authority.Spec.ExpectedBoundaryCount-ge16){$disposition=if($Authority.Spec.ExpectedBoundaryCount-ge26){'EXPLICIT_FAILURE'}else{'SUCCESS'}}
        $save=Invoke-UID0003X4SoleSaveV44 $Authority $txn.Role $p0 $dopen $disposition
        Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'txn-post-save-before-retire' $txn.Role|Out-Null;Retire-UID0003X4OwnedRoleV44 $Authority $txn.Role $Authority.Canonical|Out-Null;$txn=$null;Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'after-txn-retire'|Out-Null
        $classification=$save.Receipt.Classification
        Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'before-success-verifier'|Out-Null;$successVerifier=$null;if($classification-ceq'SUCCESS'){$successVerifier=Invoke-UID0003X4VerifierV44 $Authority 'SUCCESS_VERIFY' FINAL $save.Dclosed};Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'after-success-verifier'|Out-Null
        Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'before-explicit-failure-verifier'|Out-Null;$explicit=@();if($classification-ceq'EXPLICIT_FAILURE_SAVED'){$explicit+=Invoke-UID0003X4VerifierV44 $Authority 'EXPLICIT_FAILURE_VERIFY' FINAL $save.Dclosed};Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'after-explicit-failure-verifier'|Out-Null
        Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'before-indeterminate-verifier-1'|Out-Null;$indeterminate=@();if($classification-ceq'INDETERMINATE_SAVED'){$indeterminate+=Invoke-UID0003X4VerifierV44 $Authority 'INDETERMINATE_VERIFY_1' FINAL $save.Dclosed};Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'after-indeterminate-verifier-1'|Out-Null
        Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'before-indeterminate-verifier-2'|Out-Null;if($classification-ceq'INDETERMINATE_SAVED'){$indeterminate+=Invoke-UID0003X4VerifierV44 $Authority 'INDETERMINATE_VERIFY_2' FINAL $save.Dclosed};Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'after-indeterminate-verifier-2'|Out-Null
        $verifiers=if($classification-ceq'SUCCESS'){@($successVerifier)}elseif($classification-ceq'EXPLICIT_FAILURE_SAVED'){@($explicit)}elseif($classification-ceq'INDETERMINATE_SAVED'){@($indeterminate)}else{@()}
        if($classification-in@('SUCCESS','EXPLICIT_FAILURE_SAVED','INDETERMINATE_SAVED')){$p1=New-UID0003X4P1V44 $save.Dclosed $verifiers $classification}
        Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'before-rollback'|Out-Null;$restored=$null
        if($classification-in@('EXPLICIT_FAILURE_SAVED','INDETERMINATE_SAVED')){$restoreAuthority=New-UID0003X4RestoreAuthorityV44 $p1 $b0 $p0 $save.Dclosed;$restored=Invoke-UID0003X4CountedRestoreV44 $Authority $b0 $p0 $save.Dclosed $restoreAuthority}
        Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'after-rollback'|Out-Null;Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'before-rollback-verifier'|Out-Null;$rollbackVerifier=$null
        if($classification-in@('EXPLICIT_FAILURE_SAVED','INDETERMINATE_SAVED','NO_SAVE_P0','EXPLICIT_FAILURE_P0','INDETERMINATE_P0')){$rollbackVerifier=Invoke-UID0003X4RollbackVerifierV44 $Authority $p0}
        Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'after-rollback-verifier'|Out-Null;Assert-UID0003X4ProductionBoundaryV44 $Authority $cursor 'before-lifecycle-credit'|Out-Null
        if($cursor.Index-ne30-or$Authority.SaveAttempts-ne1-or$Authority.Journal.State-cne'CLASSIFIED'){throw 'V44_TERMINAL_AUTHORITY_INCOMPLETE'}
        $Authority.Preterminal=Get-UID0003X4FileTupleV44 (if($classification-ceq'SUCCESS'){'P1'}else{'P0'}) $Authority.Canonical
        $result=[pscustomobject]@{Classification=$classification;P0=$p0;B0=$b0;D0=$d0;Dopen=$dopen;Dclosed=$save.Dclosed;P1=$p1;RestoreAuthority=$restoreAuthority;Restored=$restored;RollbackVerifier=$rollbackVerifier;BoundaryReceipts=$cursor.Receipts.ToArray();SaveReceipt=$save.Receipt;Preterminal=$Authority.Preterminal}
    }catch{$primary=$_}
    finally{
        if($null-ne$d0Role){try{Retire-UID0003X4OwnedRoleV44 $Authority $d0Role.Role $d0.Path|Out-Null}catch{if($null-eq$cleanup){$cleanup=$_}}}
        if($null-ne$txn){try{Retire-UID0003X4OwnedRoleV44 $Authority $txn.Role $Authority.Canonical|Out-Null}catch{if($null-eq$cleanup){$cleanup=$_}}}
        if($null-ne$Authority.Journal-and-not$Authority.Journal.Closed){try{if($Authority.Journal.State-ceq'ISSUED'){Write-UID0003X4JournalTransitionV44 $Authority 'ISSUED' 'CLASSIFIED' ([ordered]@{classification='FAILED_CLOSED';primary=if($primary){$primary.Exception.Message}else{''}})|Out-Null};if($Authority.Journal.State-ceq'NOT_ISSUED'){Write-UID0003X4JournalTransitionV44 $Authority 'NOT_ISSUED' 'ISSUED' $null|Out-Null;Write-UID0003X4JournalTransitionV44 $Authority 'ISSUED' 'CLASSIFIED' ([ordered]@{classification='FAILED_BEFORE_SAVE';primary=if($primary){$primary.Exception.Message}else{''}})|Out-Null};Close-UID0003X4ContinuousJournalV44 $Authority}catch{if($null-eq$cleanup){$cleanup=$_}}}
        if($null-eq$Authority.Preterminal-and[IO.File]::Exists($Authority.Canonical)){$Authority.Preterminal=Get-UID0003X4FileTupleV44 'PRETERMINAL' $Authority.Canonical}
        $Authority.PrimaryError=if($primary){$primary.Exception.Message}else{''};$Authority.CleanupError=if($cleanup){$cleanup.Exception.Message}else{''}
    }
    if($null-ne$primary){throw $primary};if($null-ne$cleanup){throw $cleanup};$result
}

function Invoke-UID0003X4ProductionCoordinatorV44([ValidateSet('Live','Hostile','ControlSuccess','ControlExplicitSaved','ControlIndeterminateSaved','ControlNoSave')][string]$Mode='Live',[int]$CaseOrdinal=-1) {
    if($args.Count-ne0-or$script:UID0003X4V44CoordinatorDepth-ne0){throw 'V44_PRODUCTION_ENTRY_ARGUMENT_OR_REENTRY'}
    if($Mode-ceq'Hostile'){if($CaseOrdinal-lt0-or$CaseOrdinal-ge33){throw 'V44_HOSTILE_ORDINAL'}}elseif($CaseOrdinal-ne-1){throw 'V44_NON_HOSTILE_ORDINAL'}
    $script:UID0003X4V44CoordinatorDepth=1;$authority=$null;$core=$null;$error='';$after=$null
    try{$authority=New-UID0003X4RunAuthorityV44 $Mode $CaseOrdinal;try{$core=Invoke-UID0003X4SharedCoreV44 $authority}catch{$error=$_.Exception.Message};if($Mode-ceq'Live'){if($error){throw $error};return $core};$after=Get-UID0003X4FileTupleV44 'AFTER' $authority.Canonical
        [pscustomobject]@{Mode=$Mode;CaseOrdinal=$CaseOrdinal;Label=if($authority.Spec){$authority.Spec.Label}else{$Mode};ExpectedError=if($authority.Spec){$authority.Spec.ExpectedError}else{''};Error=$error;Core=$core;BoundaryCount=$authority.BoundaryReceipts.Count;BoundaryLabels=@($authority.BoundaryReceipts|ForEach-Object{$_.Label});Events=$authority.Events.ToArray();SaveAttempts=$authority.SaveAttempts;RestoreWrites=$authority.RestoreWrites;VerifierCount=$authority.VerifierCount;RoleCount=$authority.Roles.Count;InitialSHA256=if($core){$core.P0.SHA256}else{''};AfterSHA256=$after.SHA256;PreterminalSHA256=if($authority.Preterminal){$authority.Preterminal.SHA256}else{''};PrimaryError=$authority.PrimaryError;CleanupError=$authority.CleanupError;CaseAuthoritySHA256=[UID0003X4V44CaseAuthority]::SHA256()}
    }finally{
        if($null-ne$authority-and$authority.Roles.Count-ne0){$authority.CleanupError='V44_ROLE_LEAK'}
        if($null-ne$authority-and$authority.Journal-and-not$authority.Journal.Closed){try{$authority.Journal.Stream.Dispose();$authority.Journal.Closed=$true}catch{}}
        if($null-ne$authority-and$authority.Mode-cne'Live'-and[IO.Directory]::Exists($authority.Root)){[IO.Directory]::Delete($authority.Root,$true)}
        $script:UID0003X4V44CoordinatorDepth=0
    }
}

function Invoke-UID0003X4HostileSuiteV44 {
    if($PSVersionTable.PSVersion.Major-ne5-or$PSVersionTable.PSEdition-cne'Desktop'){throw 'V44_REQUIRES_WINDOWS_POWERSHELL_5_1'};Initialize-UID0003X4V44Types
    $cases=[UID0003X4V44CaseAuthority]::All();if($cases.Count-ne33){throw 'V44_HOSTILE_CASE_COUNT'};$hostile=New-Object Collections.Generic.List[object]
    foreach($spec in $cases){
        $r=Invoke-UID0003X4ProductionCoordinatorV44 -Mode Hostile -CaseOrdinal $spec.Ordinal
        if($r.Label-cne$spec.Label-or$r.Error-cne$spec.ExpectedError-or$r.BoundaryCount-ne$spec.ExpectedBoundaryCount){throw "V44_HOSTILE_EXACT_MISMATCH:$($spec.Ordinal):$($r.Label):$($r.Error):$($r.BoundaryCount)"}
        $expected=@($script:UID0003X4V44BoundaryOrder|Select-Object -First $spec.ExpectedBoundaryCount);if((Get-UID0003X4CanonicalJsonV44 $r.BoundaryLabels)-cne(Get-UID0003X4CanonicalJsonV44 $expected)){throw "V44_HOSTILE_BOUNDARY_PREFIX:$($spec.Ordinal)"}
        if($r.RoleCount-ne0){throw "V44_HOSTILE_ROLE_LEAK:$($spec.Ordinal)"};$hostile.Add($r)
    }
    $success=Invoke-UID0003X4ProductionCoordinatorV44 -Mode ControlSuccess;$explicit=Invoke-UID0003X4ProductionCoordinatorV44 -Mode ControlExplicitSaved;$indeterminate=Invoke-UID0003X4ProductionCoordinatorV44 -Mode ControlIndeterminateSaved;$noSave=Invoke-UID0003X4ProductionCoordinatorV44 -Mode ControlNoSave
    if($success.Error-or$success.Core.Classification-cne'SUCCESS'-or$success.RestoreWrites-ne0-or$success.VerifierCount-ne1-or$success.Core.P1-eq$null){throw 'V44_SUCCESS_CONTROL'}
    if($explicit.Error-or$explicit.Core.Classification-cne'EXPLICIT_FAILURE_SAVED'-or$explicit.RestoreWrites-ne1-or$explicit.VerifierCount-ne2-or$explicit.AfterSHA256-cne$explicit.Core.P0.SHA256){throw 'V44_EXPLICIT_CONTROL'}
    if($indeterminate.Error-or$indeterminate.Core.Classification-cne'INDETERMINATE_SAVED'-or$indeterminate.RestoreWrites-ne1-or$indeterminate.VerifierCount-ne3-or$indeterminate.AfterSHA256-cne$indeterminate.Core.P0.SHA256){throw 'V44_INDETERMINATE_CONTROL'}
    if($noSave.Error-or$noSave.Core.Classification-cne'NO_SAVE_P0'-or$noSave.RestoreWrites-ne0-or$noSave.VerifierCount-ne1-or$noSave.Core.P1-ne$null){throw 'V44_NO_SAVE_CONTROL'}
    foreach($r in @($success,$explicit,$indeterminate,$noSave)){if($r.BoundaryCount-ne30-or$r.RoleCount-ne0-or$r.SaveAttempts-ne1){throw "V44_CONTROL_TERMINAL:$($r.Mode)"}}
    $boundarySHA=Get-UID0003X4SHA256V44 (Get-UID0003X4CanonicalJsonV44 $script:UID0003X4V44BoundaryOrder);$value=[ordered]@{status='UID0003X4_V4_4_PRODUCTION_CLOSURE_PASSED';case_authority_sha256=[UID0003X4V44CaseAuthority]::SHA256();boundary_order_sha256=$boundarySHA;hostile_count=$hostile.Count;positive_control_count=4};$digest=Get-UID0003X4SHA256V44 (Get-UID0003X4CanonicalJsonV44 $value)
    $suite=[UID0003X4V44SuiteReceipt]::new($value.status,$value.case_authority_sha256,$boundarySHA,$hostile.Count,4,$digest)
    [pscustomobject]@{Suite=$suite;Hostile=$hostile.ToArray();PositiveControls=@($success,$explicit,$indeterminate,$noSave);ProductionEntrypoint='Invoke-UID0003X4ProductionCoordinatorV44';SharedCore='Invoke-UID0003X4SharedCoreV44';RawBoundary='Invoke-UID0003X4SealedBoundaryV44';EndpointCount=17;BoundaryCount=30;HostileCount=33;PositiveControlCount=4;AllExactLabels=$true;AllExactErrors=$true;AllExactBoundaryPrefixes=$true;ExternalMcp=0;ExternalIda=0;CanonicalIdbWrites=0;ProcessControl=0}
}

$UID0003X4V44ProductionClosureReceipt = Invoke-UID0003X4HostileSuiteV44
~~~
