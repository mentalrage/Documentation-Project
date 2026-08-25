<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality.md](0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality.md)
- Cleanup reason: executable PowerShell is prohibited in B-agent research reports; valid research and reconstructed C++ remain in the original report.
- Preservation: every removed block below is copied verbatim, with its original language and start line recorded.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original start line: `302`
- Language: `powershell`
- Preserved body SHA256: `E9486B94D20A8CC970943B0CA61047C5819754C2C9658C467038434BF6AEF017`
- Original fenced-block characters: `3055`

~~~~powershell
function Get-UID0003YSWorkerIdentity([int]$WorkerPid) {
    $p = Get-CimInstance Win32_Process -Filter "ProcessId = $WorkerPid"
    if ($null -eq $p) { return $null }
    [pscustomobject]@{
        Pid = [int]$p.ProcessId
        CreationDate = [string]$p.CreationDate
        ExecutablePath = [string]$p.ExecutablePath
        CommandLine = [string]$p.CommandLine
    }
}

function Test-UID0003YSSameWorker($Left, $Right) {
    return ($null -ne $Left -and $null -ne $Right -and
        $Left.Pid -eq $Right.Pid -and
        $Left.CreationDate -ceq $Right.CreationDate -and
        $Left.ExecutablePath -ceq $Right.ExecutablePath -and
        $Left.CommandLine -ceq $Right.CommandLine)
}

function Get-UID0003YSExclusiveReadIdentity([string]$Path) {
    $stream = [System.IO.File]::Open(
        $Path,
        [System.IO.FileMode]::Open,
        [System.IO.FileAccess]::Read,
        [System.IO.FileShare]::None)
    try {
        $sha = [System.Security.Cryptography.SHA256]::Create()
        try {
            $stream.Position = 0
            $digest = [BitConverter]::ToString($sha.ComputeHash($stream)).Replace('-', '')
            [pscustomobject]@{ Length = $stream.Length; SHA256 = $digest }
        } finally {
            $sha.Dispose()
        }
    } finally {
        $stream.Dispose()
    }
}

# Values captured immediately after this exact worker opened.
$expectedWorker = Get-UID0003YSWorkerIdentity -WorkerPid $workerPid
if ($null -eq $expectedWorker -or [string]::IsNullOrWhiteSpace($expectedWorker.CreationDate) -or
    [string]::IsNullOrWhiteSpace($expectedWorker.ExecutablePath) -or
    [string]::IsNullOrWhiteSpace($expectedWorker.CommandLine)) {
    throw 'UID0003YS worker identity is incomplete; stop.'
}
$recordedEndpoints = @(Get-NetTCPConnection -State Listen -OwningProcess $workerPid -ErrorAction SilentlyContinue |
    Select-Object LocalAddress, LocalPort)

# WD0: no save call occurs here.
$currentWorker = Get-UID0003YSWorkerIdentity -WorkerPid $workerPid
if (Test-UID0003YSSameWorker $expectedWorker $currentWorker) {
    Stop-Process -Id $workerPid -Force -ErrorAction Stop
    Wait-Process -Id $workerPid -Timeout 30 -ErrorAction SilentlyContinue
} elseif ($null -ne $currentWorker) {
    $pidReuseProven = -not (Test-UID0003YSSameWorker $expectedWorker $currentWorker)
    if (-not $pidReuseProven) { throw 'UID0003YS PID identity is ambiguous; stop.' }
    # Never terminate a different process that reused the PID.
}
Start-Sleep -Milliseconds 500
$afterWorker = Get-UID0003YSWorkerIdentity -WorkerPid $workerPid
if (Test-UID0003YSSameWorker $expectedWorker $afterWorker) {
    throw 'UID0003YS exact worker process is still alive; stop.'
}
foreach ($endpoint in $recordedEndpoints) {
    $liveEndpoint = Get-NetTCPConnection -State Listen -ErrorAction SilentlyContinue |
        Where-Object { $_.LocalAddress -eq $endpoint.LocalAddress -and $_.LocalPort -eq $endpoint.LocalPort }
    if ($liveEndpoint) { throw 'UID0003YS recorded worker endpoint is still live or has ambiguous reuse; stop.' }
}
~~~~

## Removed Block R002

- Original start line: `382`
- Language: `powershell`
- Preserved body SHA256: `B099B3F702000B7256F4376DA2D50AF7B707357CFA95957938CC74CD9D97FFFA`
- Original fenced-block characters: `645`

~~~~powershell
$idb = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$p0Identity = Get-UID0003YSExclusiveReadIdentity -Path $idb
$p0Size = $p0Identity.Length
$p0Sha = $p0Identity.SHA256
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$b0 = "$idb.bak-UID0003YS-prestate-$stamp"
if (Test-Path -LiteralPath $b0) { throw 'UID0003YS B0 path collision; stop before transaction-worker open.' }
Copy-Item -LiteralPath $idb -Destination $b0 -ErrorAction Stop
$b0Identity = Get-UID0003YSExclusiveReadIdentity -Path $b0
if ($b0Identity.Length -ne $p0Size -or $b0Identity.SHA256 -ne $p0Sha) { throw 'UID0003YS B0 mismatch; stop before transaction-worker open.' }
~~~~

## Removed Block R003

- Original start line: `403`
- Language: `powershell`
- Preserved body SHA256: `0C5482B066D5D9C830D8C07CA82704B9CBD8FABB7311D780D66689DDD60A5FAC`
- Original fenced-block characters: `577`

~~~~powershell
$transactionOpenItem = Get-Item -LiteralPath $idb
$transactionOpenSha = (Get-FileHash -LiteralPath $idb -Algorithm SHA256).Hash
$b0Item = Get-Item -LiteralPath $b0
$b0Sha = (Get-FileHash -LiteralPath $b0 -Algorithm SHA256).Hash
if ($transactionOpenItem.Length -ne $p0Size -or $transactionOpenSha -ne $p0Sha) { throw 'UID0003YS transaction worker did not open over exact P0; dispose without save under WD0.' }
if ($b0Item.Length -ne $p0Size -or $b0Sha -ne $p0Sha) { throw 'UID0003YS B0 no longer equals P0; dispose transaction worker without save under WD0.' }
~~~~

## Removed Block R004

- Original start line: `418`
- Language: `powershell`
- Preserved body SHA256: `0D3D825A8713AE428FCD380A6A91207D5264023FC13BA82BD0DD49573D7148E8`
- Original fenced-block characters: `194`

~~~~powershell
$closedObservedIdentity = Get-UID0003YSExclusiveReadIdentity -Path $idb
$closedObservedSize = $closedObservedIdentity.Length
$closedObservedSha = $closedObservedIdentity.SHA256
~~~~

## Removed Block R005

- Original start line: `428`
- Language: `powershell`
- Preserved body SHA256: `5203DC651C3FC2B3E11DF42DDA057A1E893A9AFDB43BE20832F47D505954428F`
- Original fenced-block characters: `941`

~~~~powershell
$b0Identity = Get-UID0003YSExclusiveReadIdentity -Path $b0
if ($b0Identity.Length -ne $p0Size -or $b0Identity.SHA256 -ne $p0Sha) { throw 'UID0003YS B0 no longer equals P0; stop without restore.' }
$currentIdentity = Get-UID0003YSExclusiveReadIdentity -Path $idb
$currentIsP0 = ($currentIdentity.Length -eq $p0Size -and $currentIdentity.SHA256 -eq $p0Sha)
$currentIsAttributedD1 = ($d1AttributionComplete -and $currentIdentity.Length -eq $d1Size -and $currentIdentity.SHA256 -eq $d1Sha)
if (-not $currentIsP0 -and -not $currentIsAttributedD1) { throw 'UID0003YS unknown/third canonical identity detected; stop without restore.' }
if (-not $currentIsP0) { Copy-Item -LiteralPath $b0 -Destination $idb -Force -ErrorAction Stop }
$restoredIdentity = Get-UID0003YSExclusiveReadIdentity -Path $idb
if ($restoredIdentity.Length -ne $p0Size -or $restoredIdentity.SHA256 -ne $p0Sha) { throw 'UID0003YS canonical restore mismatch.' }
~~~~
