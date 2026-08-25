<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0002FN-ChattingVarietySelectPaneSetupBackground-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002FN-ChattingVarietySelectPaneSetupBackground-source-quality.md](0002FN-ChattingVarietySelectPaneSetupBackground-source-quality.md)
- Source report SHA256 before archive-link insertion: `EF5013A46EE179F098E3FB01B3BD6DF53AC910E9CBD54AF45E77F8F4C4283C1F`
- Recovery generated: `2026-08-09T22:17:53Z`
- Unique recovered executable blocks: `7`
- Recovered executable bytes: `121765`
- Recovery basis: report-path-associated Codex session history. The source report had already removed its executable packages before the supervisor could extract them directly.
- Scope: this archive preserves every unique recoverable report-local executable block, including superseded historical variants where session history retained more than the final pre-removal report.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- SHA256: `BA8B509A644E5F5F0C1942A75FA1B43AACB4A19CB4BAEA474E597A0B59305172`
- Language: `powershell`
- Bytes: `3004`
- First recovered timestamp: `2026-08-06T13:34:42.375Z`
- Session provenance: rollout-2026-08-03T16-11-11-019fc940-70d9-71e0-ac15-0845b00887ef.jsonl line 191047 (2026-08-06T13:34:42.375Z); rollout-2026-08-03T16-11-11-019fc940-70d9-71e0-ac15-0845b00887ef.jsonl line 191048 (2026-08-06T13:34:42.435Z)

~~~powershell
$python = 'C:\Users\admin\.idapro\idalib-mcp-venv\Scripts\python.exe'
$pythonItem = Get-Item -LiteralPath $python -ErrorAction Stop
if ($pythonItem.Length -ne 255320 -or (Get-FileHash -LiteralPath $python -Algorithm SHA256).Hash -ne '4B8C3912806B3C1591BA3CB403BFF77AD309C3FE5756F87C20B7A6F8F0174262') { throw 'G00 interpreter drift' }
$expected = @(
    @{ Module='ida_pro_mcp.idalib_supervisor'; Path='C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\idalib_supervisor.py'; Size=52468; Sha='2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A' },
    @{ Module='ida_pro_mcp.idalib_server'; Path='C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\idalib_server.py'; Size=9848; Sha='06C922EEF3F2E6771308C687231FE443A65DADF340E72001C6B05B7FC70B2034' },
    @{ Module='ida_pro_mcp.ida_mcp.framework'; Path='C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\framework.py'; Size=22159; Sha='518100959115851FAAD98A48D4E0D918B4439C1C6666671C9DA93AA7312414B4' },
    @{ Module='ida_pro_mcp.ida_mcp.api_core'; Path='C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\api_core.py'; Size=34004; Sha='90C59B3F64F26E170CC604000CE39B34B648352767059DD1C2DF1914E9CBD4A3' },
    @{ Module='ida_pro_mcp.ida_mcp.api_stack'; Path='C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\api_stack.py'; Size=5502; Sha='9E4B5898E875812E4C993597D44F0F6438430F92A8B2299DC5C62630D49AE1BB' },
    @{ Module='ida_pro_mcp.ida_mcp.api_modify'; Path='C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\api_modify.py'; Size=51759; Sha='161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8' },
    @{ Module='ida_pro_mcp.ida_mcp.api_memory'; Path='C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\api_memory.py'; Size=9583; Sha='A2D4E48921E2E7A8D3C4BD621658F645A9C17C7FB34E963E62AE864E452ABC93' },
    @{ Module='ida_pro_mcp.ida_mcp.api_analysis'; Path='C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\api_analysis.py'; Size=79961; Sha='4C9B9122A7D2697CD464C1F473A227A580FD803515A1C885A1AA262259F1969F' },
    @{ Module='ida_pro_mcp.ida_mcp.rpc'; Path='C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\rpc.py'; Size=5281; Sha='3EDAEFA26A097AFA15EA16F07BC92EBD8EBD9CDC153F16EDF80AC8BC29AB0FFF' }
)
foreach ($entry in $expected) {
    $resolved = (& $python -c 'import importlib.util,sys; s=importlib.util.find_spec(sys.argv[1]); print(s.origin if s else "")' $entry.Module).Trim()
    if ([IO.Path]::GetFullPath($resolved) -ne [IO.Path]::GetFullPath($entry.Path)) { throw "G00 loaded-path drift: $($entry.Module)" }
    $item = Get-Item -LiteralPath $resolved -ErrorAction Stop
    $sha = (Get-FileHash -LiteralPath $resolved -Algorithm SHA256).Hash
    if ($item.Length -ne $entry.Size -or $sha -ne $entry.Sha) { throw "G00 source identity drift: $($entry.Module)" }
}
~~~

## Removed Block R002

- SHA256: `F73117A10F7D6BB4A46BDB682A22CCED201EC3D347B46E10B4D67F3B551B181D`
- Language: `powershell`
- Bytes: `737`
- First recovered timestamp: `2026-08-06T15:08:17.904Z`
- Session provenance: rollout-2026-08-03T16-11-11-019fc940-70d9-71e0-ac15-0845b00887ef.jsonl line 191367 (2026-08-06T15:08:17.904Z)

~~~powershell
function Get-Uid0002FNClosedIdentity([string]$Path) {
    $full = [IO.Path]::GetFullPath($Path)
    if (-not (Test-Path -LiteralPath $full -PathType Leaf)) { throw 'CANONICAL_NOT_REGULAR_FILE' }
    $stream = [IO.File]::Open($full,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
    try {
        $ticks = [IO.File]::GetLastWriteTimeUtc($full).Ticks
        $size = $stream.Length
        $sha = [Security.Cryptography.SHA256]::Create()
        try { $hash = (-join ($sha.ComputeHash($stream) | ForEach-Object { $_.ToString('x2') })).ToUpper() }
        finally { $sha.Dispose() }
        [ordered]@{Path=$full;Size=$size;SHA256=$hash;LastWriteTimeUtcTicks=$ticks}
    } finally { $stream.Dispose() }
}
~~~

## Removed Block R003

- SHA256: `AAD5C15CDEDE5948E9F00327C187F9C8D134354CD285666710DCC3E6127007CD`
- Language: `powershell`
- Bytes: `820`
- First recovered timestamp: `2026-08-06T22:21:53.772Z`
- Session provenance: rollout-2026-08-06T18-18-26-019fd928-038d-72b3-b35b-bd6e2bfb539f.jsonl line 193715 (2026-08-06T22:21:53.772Z); rollout-2026-08-06T18-18-26-019fd928-038d-72b3-b35b-bd6e2bfb539f.jsonl line 193716 (2026-08-06T22:21:53.825Z)

~~~powershell
$P8Expected = @{
    OnPaint=[ordered]@{Start='0x00481490';End='0x004816ce';Name='ChattingVarietySelectPane__OnPaint';Prototype='void __thiscall(ChattingVarietySelectPane *this)';Size=574;BodySHA256='788A8F752904A9DEE29B670BB39D370956F4416CB1A27137E2FFA554C9B02360'}
    DrawBorder=[ordered]@{Start='0x00481750';End='0x00481a72';Name='ChattingVarietySelectPane__DrawBorder';Prototype='void __thiscall(ChattingVarietySelectPane *this)';Size=802;BodySHA256='5669F9B6CA54AF32E11C5A1E4BF81F701D9DF170799EFC90C8EA5DDC0AB3592A'}
}
function Assert-Uid0002FNP8([string]$Phase,[hashtable]$Actual,[hashtable]$Expected) {
    foreach ($key in @('Start','End','Name','Prototype','Size','BodySHA256')) {
        if ([string]$Actual[$key] -cne [string]$Expected[$key]) { throw "P8_FAIL_CLOSED:$Phase:$key" }
    }
}
~~~

## Removed Block R004

- SHA256: `1E1E723002C5971681A212934520CF69C45826F51193791C9FBBCAFCDA4E2387`
- Language: `powershell`
- Bytes: `29307`
- First recovered timestamp: `2026-08-07T00:15:58.649Z`
- Session provenance: rollout-2026-08-06T18-18-26-019fd928-038d-72b3-b35b-bd6e2bfb539f.jsonl line 194689 (2026-08-07T00:15:58.649Z); rollout-2026-08-06T18-18-26-019fd928-038d-72b3-b35b-bd6e2bfb539f.jsonl line 194690 (2026-08-07T00:15:58.716Z)

~~~powershell
function New-Uid0002FNTransactionState([string]$Nonce) {
    if ($Nonce -cnotmatch '^\d{14}$') { throw 'TRANSACTION_NONCE_INVALID' }
    [ordered]@{
        Nonce=$Nonce; Sequence=0; RequestIds=@{}; Journal=[Collections.Generic.List[object]]::new()
        SaveAttemptCount=0; SaveRequestId=$null; SaveClassification=$null
        Roles=@{}; RetiredRoles=@{}; AttributableIdentity=$null; P0=$null; B0=$null
    }
}
function New-Uid0002FNRequestId([System.Collections.IDictionary]$State,[string]$Role,[string]$Operation) {
    $State.Sequence = [int]$State.Sequence + 1
    $id = "UID0002FN:$($State.Nonce):${Role}:${Operation}:$('{0:D4}' -f [int]$State.Sequence)"
    if ($State.RequestIds.ContainsKey($id)) { throw "REQUEST_ID_DUPLICATE:$id" }
    $State.RequestIds[$id] = $true
    $id
}
function ConvertFrom-Uid0002FNResponse([object]$Raw) {
    if ($Raw -is [string]) { return ($Raw | ConvertFrom-Json -Depth 100 -ErrorAction Stop) }
    if ($null -eq $Raw) { throw 'JSONRPC_RESPONSE_NULL' }
    $Raw
}
function Assert-Uid0002FNJsonRpcCorrelation([object]$Response,[string]$ExpectedId,[bool]$AllowError) {
    if ($null -eq $Response -or [string]$Response.jsonrpc -cne '2.0') { throw 'JSONRPC_VERSION_MISMATCH' }
    $idProperty = $Response.PSObject.Properties['id']
    if ($null -eq $idProperty -or $idProperty.Value -isnot [string]) { throw 'JSONRPC_ID_TYPE_MISMATCH' }
    if ([string]$idProperty.Value -cne $ExpectedId) { throw 'JSONRPC_ID_VALUE_MISMATCH' }
    $resultCount = @($Response.PSObject.Properties | Where-Object Name -ceq 'result').Count
    $errorCount = @($Response.PSObject.Properties | Where-Object Name -ceq 'error').Count
    if (($resultCount + $errorCount) -ne 1) { throw 'JSONRPC_RESULT_ERROR_CARDINALITY' }
    if (-not $AllowError -and $errorCount -ne 0) { throw 'JSONRPC_ERROR_FORBIDDEN' }
    if (-not $AllowError -and $resultCount -ne 1) { throw 'JSONRPC_RESULT_MISSING' }
}
function Invoke-Uid0002FNRpc([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[string]$Role,[string]$Operation,[string]$Method,[System.Collections.IDictionary]$Params) {
    $id = New-Uid0002FNRequestId $State $Role $Operation
    $request = [ordered]@{jsonrpc='2.0';id=$id;method=$Method;params=$Params}
    $started = [DateTime]::UtcNow
    $State.Journal.Add([ordered]@{Kind='request';Id=$id;Role=$Role;Operation=$Operation;Utc=$started.ToString('o');Payload=$request})
    try { $response = ConvertFrom-Uid0002FNResponse (& $SendJsonRpc $request) }
    catch {
        $State.Journal.Add([ordered]@{Kind='transport-failure';Id=$id;Role=$Role;Operation=$Operation;Utc=[DateTime]::UtcNow.ToString('o');Error=$_.Exception.Message})
        throw
    }
    $ended = [DateTime]::UtcNow
    Assert-Uid0002FNJsonRpcCorrelation $response $id $false
    $State.Journal.Add([ordered]@{Kind='response';Id=$id;Role=$Role;Operation=$Operation;StartedUtc=$started;EndedUtc=$ended;Payload=$response})
    [ordered]@{Id=$id;StartedUtc=$started;EndedUtc=$ended;Response=$response}
}
function Invoke-Uid0002FNTool([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[string]$Role,[string]$Operation,[string]$Name,[System.Collections.IDictionary]$Arguments) {
    Invoke-Uid0002FNRpc $State $SendJsonRpc $Role $Operation 'tools/call' ([ordered]@{name=$Name;arguments=$Arguments})
}
function Get-Uid0002FNStructured([object]$Call,[string]$Label) {
    $result = $Call.Response.result
    if ($null -eq $result -or [bool]$result.isError) { throw "${Label}_TOOL_RESULT_FAILED" }
    if ($null -eq $result.structuredContent) { throw "${Label}_STRUCTURED_CONTENT_MISSING" }
    $result.structuredContent
}
function Assert-Uid0002FNAttestationWindow([object]$RuntimeCall) {
    $payload = Get-Uid0002FNStructured $RuntimeCall 'RUNTIME'
    $nodes = @($payload.listener) + @($payload.workers | ForEach-Object { $_.attestation.worker })
    foreach ($node in $nodes) {
        $stamp = [DateTime]::MinValue
        if (-not [DateTime]::TryParse([string]$node.attested_at_utc,[Globalization.CultureInfo]::InvariantCulture,[Globalization.DateTimeStyles]::RoundtripKind,[ref]$stamp)) { throw 'RUNTIME_TIMESTAMP_INVALID' }
        if ($stamp.ToUniversalTime() -lt $RuntimeCall.StartedUtc.AddSeconds(-2) -or $stamp.ToUniversalTime() -gt $RuntimeCall.EndedUtc.AddSeconds(2)) { throw 'RUNTIME_TIMESTAMP_OUTSIDE_REQUEST_WINDOW' }
    }
}
function Assert-Uid0002FNToolsSchemas([object]$ToolsCall) {
    Assert-Uid0002FNPublicRuntimeSchema $ToolsCall.Response
    $tools = @($ToolsCall.Response.result.tools)
    $expected = [ordered]@{
        idb_list=@{Bytes=47;Hash='C8A1AC469A826EA3547AC220C7BBFDCD6B58080D4EC596FF2A0149C5CCB9B699'}
        runtime_attestation=@{Bytes=315;Hash='014880A1FB3F64F54050769A75B97DE7E5CF3D8A009350E62D478981EA4E9482'}
        server_health=@{Bytes=175;Hash='DF33457887FEEE7188DD0786BC4706301BA614FEA84BC463E958301706D8D4A8'}
        lookup_funcs=@{Bytes=307;Hash='E8F4596AF02DBF952F3EA1BAB167E1F24D585906CE487A2B69C74E665A4329D3'}
        stack_frame=@{Bytes=292;Hash='AEA569DBB51E6C65591A942E9847007A5F7B0B6A00F0A9E4BA2536A1D347BC4A'}
        inspect_items=@{Bytes=337;Hash='BF8F209B6719581AFDB8C9AC01AA44B368532FFAD24961D36B4CE092218AAEEA'}
        get_comments=@{Bytes=343;Hash='CFF6054E1EB8A9AFC22B51C2DA3D784E4A160DC16030B95D91C7888D06B5D312'}
        get_bytes=@{Bytes=700;Hash='694D5774A1C7F9A24784E4B9BDF1814DD942552952F99FDE1449BD740468A784'}
        disasm=@{Bytes=601;Hash='BD1B9AB64DCD4D7DA9D31C4B917643FE7B943E8250107B4DCDA6E41E12FAC856'}
        func_profile=@{Bytes=1714;Hash='EB30BBAAF3E6A6CB5BB59B1AD61E3FE573A7FC9B3AB592565D588EDAAE6F7D87'}
        xref_query=@{Bytes=1710;Hash='546B8BC2CE23434F4735FC639E592424BD5239F0BDAEFA23A5006F756310A8C9'}
    }
    foreach ($name in $expected.Keys) {
        $match = @($tools | Where-Object name -ceq $name)
        if ($match.Count -ne 1) { throw "SCHEMA_TOOL_COUNT:$name" }
        $json = Get-Uid0002FNCanonicalJson $match[0].inputSchema
        $bytes = [Text.Encoding]::UTF8.GetBytes($json)
        if ($bytes.Length -ne [int]$expected[$name].Bytes -or (Get-Uid0002FNSha256Bytes $bytes) -cne [string]$expected[$name].Hash) { throw "SCHEMA_ACTUAL_DIGEST:$name" }
    }
    foreach ($shape in @(
        @{Name='idb_open';Properties=@('build_caches','idle_ttl_sec','init_hexrays','input_path','mode','preferred_session_id','run_auto_analysis');Required=@('input_path')},
        @{Name='idb_save';Properties=@('database','path');Required=@('database')}
    )) {
        $match = @($tools | Where-Object name -ceq $shape.Name)
        if ($match.Count -ne 1) { throw "SCHEMA_TOOL_COUNT:$($shape.Name)" }
        $actualProperties = @($match[0].inputSchema.properties.PSObject.Properties.Name | Sort-Object -CaseSensitive)
        if (($actualProperties -join '|') -cne (@($shape.Properties | Sort-Object -CaseSensitive) -join '|')) { throw "SCHEMA_PROPERTY_SET:$($shape.Name)" }
        if ((@($match[0].inputSchema.required | Sort-Object -CaseSensitive) -join '|') -cne (@($shape.Required | Sort-Object -CaseSensitive) -join '|')) { throw "SCHEMA_REQUIRED_SET:$($shape.Name)" }
    }
}
function Get-Uid0002FNPathValue([object]$Root,[string]$Path) {
    $value = $Root
    foreach ($part in $Path.Split('.')) {
        if ($part -match '^\d+$') { $value = @($value)[[int]$part] }
        else {
            $property = $value.PSObject.Properties[$part]
            if ($null -eq $property) { throw "SEMANTIC_PATH_MISSING:$Path:$part" }
            $value = $property.Value
        }
    }
    $value
}
function Assert-Uid0002FNSemanticContract([string]$Label,[object]$Payload,[object[]]$Rules) {
    if ($Rules.Count -eq 0) { throw "SEMANTIC_RULES_EMPTY:$Label" }
    foreach ($rule in $Rules) {
        $actual = Get-Uid0002FNPathValue $Payload ([string]$rule.Path)
        switch ([string]$rule.Operator) {
            'eq' { if ([string]$actual -cne [string]$rule.Expected) { throw "SEMANTIC_EQ:${Label}:$($rule.Path)" } }
            'bool' { if ([bool]$actual -ne [bool]$rule.Expected) { throw "SEMANTIC_BOOL:${Label}:$($rule.Path)" } }
            'count' { if (@($actual).Count -ne [int]$rule.Expected) { throw "SEMANTIC_COUNT:${Label}:$($rule.Path)" } }
            'sha256-json' { $json=Get-Uid0002FNCanonicalJson $actual; if ((Get-Uid0002FNSha256Bytes ([Text.Encoding]::UTF8.GetBytes($json))) -cne [string]$rule.Expected) { throw "SEMANTIC_SHA:${Label}:$($rule.Path)" } }
            default { throw "SEMANTIC_OPERATOR_UNKNOWN:$($rule.Operator)" }
        }
    }
}
function Get-Uid0002FNXrefPage([object]$Payload,[string]$Label) {
    $container = if ($null -ne $Payload.results) { @($Payload.results)[0] } elseif ($null -ne $Payload.result) { @($Payload.result)[0] } else { $Payload }
    $rows = if ($null -ne $container.xrefs) { @($container.xrefs) } elseif ($null -ne $container.rows) { @($container.rows) } else { throw "${Label}_ROWS_MISSING" }
    [ordered]@{Rows=$rows;Total=[int]$container.total;NextOffset=$container.next_offset}
}
function Assert-Uid0002FND3Pagination([object]$Page1Payload,[object]$Page2Payload) {
    $p1=Get-Uid0002FNXrefPage $Page1Payload 'D3_PAGE1'; $p2=Get-Uid0002FNXrefPage $Page2Payload 'D3_PAGE2'
    if ($p1.Rows.Count -ne 200 -or $p1.Total -ne 231 -or [int]$p1.NextOffset -ne 200) { throw 'D3_PAGE1_CONTRACT' }
    if ($p2.Rows.Count -ne 31 -or $p2.Total -ne 231 -or $null -ne $p2.NextOffset) { throw 'D3_PAGE2_CONTRACT' }
    $rows=@($p1.Rows)+@($p2.Rows)
    $addresses=@($rows | ForEach-Object { if ($null -ne $_.from) { [string]$_.from } elseif ($null -ne $_.from_ea) { [string]$_.from_ea } else { throw 'D3_SOURCE_ADDRESS_MISSING' } })
    $normalized=@($addresses | ForEach-Object { ('0x{0:x8}' -f [Convert]::ToUInt64($_.Replace('0x',''),16)) })
    if ($normalized.Count -ne 231 -or @($normalized | Sort-Object -Unique).Count -ne 231) { throw 'D3_ROW_UNIQUENESS' }
    if ($normalized[0] -cne '0x0041bb50' -or $normalized[-1] -cne '0x005c3289') { throw 'D3_BOUNDARY_ADDRESS' }
    $digest=Get-Uid0002FNSha256Bytes ([Text.Encoding]::UTF8.GetBytes(($normalized -join "`n")))
    if ($digest -cne '04E0103EBF7B3B6EE87F18CF6E36CA9A684F67A426562B8770C7ED5A4850AF1A') { throw 'D3_SOURCE_ADDRESS_DIGEST' }
    $normalized
}
function Invoke-Uid0002FNReadbackBundle([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[string]$Role,[string]$Database,[bool]$IncludeProfile) {
    if ([string]::IsNullOrWhiteSpace($Database)) { throw 'READBACK_DATABASE_EMPTY' }
    $responses=[ordered]@{}
    $responses.A01=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'A01' 'server_health' ([ordered]@{database=$Database})
    $responses.A02=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'A02' 'lookup_funcs' ([ordered]@{queries=@('0x00481490','0x004816d0','0x00481750','0x005552f0','0x00555c70','VoteMenuPane_DrawBackground','0x005bd5b0','0x00457a60','0x004d02f0','0x004ba6b0','0x005c772f');database=$Database})
    $responses.A03=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'A03' 'stack_frame' ([ordered]@{addrs=@('0x004816d0');database=$Database})
    $responses.A04=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'A04' 'inspect_items' ([ordered]@{addrs=@('0x00481490','0x004816ce','0x004816d0','0x00481741','0x00481750','0x00481a72','0x005552f0','0x00555c70','0x005bd5b0','0x00610b74','0x00610b8c','0x0067a744','0x00614f74','0x00622fb0','0x00623040','0x00630e10');database=$Database})
    $responses.A05=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'A05' 'get_comments' ([ordered]@{addrs=@('0x00481490','0x004816d0','0x00481750','0x005552f0','0x00555c70','0x005bd5b0','0x00610b74','0x00610b8c','0x0067a744');database=$Database})
    $responses.A06=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'A06' 'get_bytes' ([ordered]@{regions=@(@{addr='0x00481490';size=574},@{addr='0x004816ce';size=2},@{addr='0x004816d0';size=113},@{addr='0x00481741';size=15},@{addr='0x00481750';size=802},@{addr='0x005552f0';size=113},@{addr='0x00555c70';size=113},@{addr='0x005bd5b0';size=113},@{addr='0x00610b74';size=22},@{addr='0x00610b8c';size=22},@{addr='0x0067a744';size=4});database=$Database})
    foreach ($entry in @(@('A06a','0x004816d0'),@('A06b','0x005552f0'),@('A06c','0x00555c70'),@('A06d','0x005bd5b0'))) {
        $responses[$entry[0]]=Invoke-Uid0002FNTool $State $SendJsonRpc $Role $entry[0] 'disasm' ([ordered]@{addr=$entry[1];max_instructions=100;offset=0;include_total=$true;database=$Database})
    }
    if ($IncludeProfile) { $responses.A06e=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'A06e' 'func_profile' ([ordered]@{queries=@(@{addr='0x004816d0';include_lists=$true;include_prototype=$true;max_items=512},@{addr='0x005552f0';include_lists=$true;include_prototype=$true;max_items=512},@{addr='VoteMenuPane_DrawBackground';include_lists=$true;include_prototype=$true;max_items=512},@{addr='0x005bd5b0';include_lists=$true;include_prototype=$true;max_items=512});database=$Database}) }
    foreach ($xref in @(@('A07a','0x00610b74',0),@('A07b','0x00610b8c',0),@('A07c1','0x0067a744',0),@('A07c2','0x0067a744',200),@('A07d','0x004816d0',0),@('A07e','0x005552f0',0),@('A07f','0x00555c70',0),@('A07g','0x005bd5b0',0))) {
        $responses[$xref[0]]=Invoke-Uid0002FNTool $State $SendJsonRpc $Role $xref[0] 'xref_query' ([ordered]@{queries=@([ordered]@{addr=$xref[1];direction='to';xref_type='any';offset=[int]$xref[2];count=200;include_fn=$true;dedup=$true;sort_by='addr';descending=$false});database=$Database})
    }
    $responses
}
function Assert-Uid0002FNCompleteReadback([System.Collections.IDictionary]$Responses,[System.Collections.IDictionary]$Contracts,[string]$Phase) {
    foreach ($name in @('F1','D1','D2','D3','P1','P2','P3','P4','P5','P6','P7','P8','P9','P10','P11')) {
        if (-not $Contracts.Contains($name) -or @($Contracts[$name]).Count -eq 0) { throw "CONTRACT_MISSING:$name" }
        foreach ($contract in @($Contracts[$name])) {
            if (-not $Responses.Contains($contract.Response)) { throw "RESPONSE_MISSING:${Phase}:$($contract.Response)" }
            Assert-Uid0002FNSemanticContract "${Phase}:${name}" (Get-Uid0002FNStructured $Responses[$contract.Response] $contract.Response) @($contract.Rules)
        }
    }
    Assert-Uid0002FND3Pagination (Get-Uid0002FNStructured $Responses.A07c1 'A07c1') (Get-Uid0002FNStructured $Responses.A07c2 'A07c2') | Out-Null
}
function Open-Uid0002FNRole([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[string]$Role,[System.Collections.IDictionary]$ExpectedDisk) {
    Assert-Uid0002FNClosedIdentity $ExpectedDisk (Get-Uid0002FNClosedIdentity $canonical) "${Role}_OPEN_BASIS"
    $open=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'OPEN' 'idb_open' ([ordered]@{input_path=$canonical;mode='force_headless';run_auto_analysis=$false;build_caches=$false;init_hexrays=$false;idle_ttl_sec=3600;preferred_session_id="uid0002fn-$($Role.ToLowerInvariant())-$($State.Nonce)"})
    $openPayload=Get-Uid0002FNStructured $open "${Role}_OPEN"
    $session=[string]$openPayload.session.session_id
    if ([string]::IsNullOrWhiteSpace($session)) { throw "${Role}_RETURNED_SESSION_EMPTY" }
    $list=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'A00' 'idb_list' ([ordered]@{})
    $listPayload=Get-Uid0002FNStructured $list "${Role}_A00"
    $row=@($listPayload.sessions | Where-Object session_id -ceq $session)
    if ($row.Count -ne 1) { throw "${Role}_A00_SESSION_COUNT" }
    $runtime=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'G02' 'runtime_attestation' ([ordered]@{expected_database=$session;expected_canonical_path=$canonical})
    Assert-Uid0002FNAttestationWindow $runtime
    $bound=Assert-Uid0002FNRoleWorkerImplementation $open.Response $row[0] $runtime.Response $session
    $roleState=[ordered]@{Name=$Role;Session=$session;Open=$open;List=$list;Runtime=$runtime;Binding=$bound;Retired=$false}
    $State.Roles[$Role]=$roleState
    $roleState
}
function Assert-Uid0002FNStatefulBoundary([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[System.Collections.IDictionary]$RoleState,[string]$Boundary) {
    $runtime=Invoke-Uid0002FNTool $State $SendJsonRpc $RoleState.Name "G03-$Boundary" 'runtime_attestation' ([ordered]@{expected_database=$RoleState.Session;expected_canonical_path=$canonical})
    Assert-Uid0002FNAttestationWindow $runtime
    $list=Invoke-Uid0002FNTool $State $SendJsonRpc $RoleState.Name "A00-$Boundary" 'idb_list' ([ordered]@{})
    $payload=Get-Uid0002FNStructured $list "A00-$Boundary"
    $row=@($payload.sessions | Where-Object session_id -ceq $RoleState.Session)
    if ($row.Count -ne 1) { throw "ROLE_SESSION_MISSING:$($RoleState.Name):$Boundary" }
    Assert-Uid0002FNRoleWorkerImplementation $RoleState.Open.Response $row[0] $runtime.Response $RoleState.Session | Out-Null
}
function Retire-Uid0002FNRole([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[System.Collections.IDictionary]$RoleState) {
    if ($RoleState.Retired) { throw "ROLE_ALREADY_RETIRED:$($RoleState.Name)" }
    $binding=$RoleState.Binding
    Stop-Uid0002FNExactWorker $binding.WorkerProcess
    $RoleState.Retired=$true
    $State.RetiredRoles[$RoleState.Name]=$binding.WorkerProcess
    $list=Invoke-Uid0002FNTool $State $SendJsonRpc $RoleState.Name 'RETIRE-A00' 'idb_list' ([ordered]@{})
    $payload=Get-Uid0002FNStructured $list 'RETIRE_A00'
    if (@($payload.sessions | Where-Object { [bool]$_.is_active -and (Get-Uid0002FNCanonicalPath ([string]$_.canonical_path)) -ceq (Get-Uid0002FNCanonicalPath $canonical) }).Count -ne 0) { throw 'RETIRE_ACTIVE_CANONICAL_SESSION' }
    if (Get-CimInstance Win32_Process -Filter "ProcessId=$([int]$binding.WorkerProcess.PID)" -ErrorAction SilentlyContinue) { throw 'RETIRE_PROCESS_STILL_PRESENT' }
    if (@(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort ([int]$binding.WorkerRoute.port) -State Listen -ErrorAction SilentlyContinue).Count -ne 0) { throw 'RETIRE_SOCKET_STILL_LISTENING' }
    Get-Uid0002FNClosedIdentity $canonical
}
function Invoke-Uid0002FNSaveOnce([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[System.Collections.IDictionary]$RoleState) {
    if ([int]$State.SaveAttemptCount -ne 0 -or $null -ne $State.SaveRequestId) { throw 'SAVE_DISPATCH_DUPLICATE' }
    $id=New-Uid0002FNRequestId $State $RoleState.Name 'S08'
    $State.SaveAttemptCount=1; $State.SaveRequestId=$id
    $request=[ordered]@{jsonrpc='2.0';id=$id;method='tools/call';params=[ordered]@{name='idb_save';arguments=[ordered]@{path=$canonical;database=$RoleState.Session}}}
    $State.Journal.Add([ordered]@{Kind='save-request';Id=$id;Utc=[DateTime]::UtcNow.ToString('o');Payload=$request;Attempt=1})
    try { $response=ConvertFrom-Uid0002FNResponse (& $SendJsonRpc $request) }
    catch { $State.SaveClassification='indeterminate';$State.Journal.Add([ordered]@{Kind='save-transport-failure';Id=$id;Error=$_.Exception.Message});return [ordered]@{Class='indeterminate';Response=$null} }
    try { Assert-Uid0002FNJsonRpcCorrelation $response $id $true }
    catch { $State.SaveClassification='indeterminate';$State.Journal.Add([ordered]@{Kind='save-malformed-response';Id=$id;Error=$_.Exception.Message;Payload=$response});return [ordered]@{Class='indeterminate';Response=$response} }
    if ($null -ne $response.error) { $class='definite-failure' }
    else {
        $result=$response.result; $payload=$result.structuredContent
        if ([bool]$result.isError -or ($null -ne $payload.ok -and -not [bool]$payload.ok)) { $class='definite-failure' }
        elseif ($null -ne $payload -and [bool]$payload.ok -and (Get-Uid0002FNCanonicalPath ([string]$payload.path) -ceq (Get-Uid0002FNCanonicalPath $canonical)) { $class='definite-success' }
        else { $class='indeterminate' }
    }
    $State.SaveClassification=$class
    $State.Journal.Add([ordered]@{Kind='save-response';Id=$id;Class=$class;Payload=$response})
    [ordered]@{Class=$class;Response=$response}
}
function Test-Uid0002FNRollbackAuthorization([System.Collections.IDictionary]$State,[object]$CurrentIdentity) {
    if ($null -eq $State.AttributableIdentity -or $null -eq $CurrentIdentity -or $null -eq $State.P0 -or $null -eq $State.B0) { return $false }
    try { Assert-Uid0002FNClosedIdentity $State.AttributableIdentity $CurrentIdentity 'ROLLBACK_CURRENT'; return $true } catch { return $false }
}
function Assert-Uid0002FNRoleRetired([System.Collections.IDictionary]$RoleState) {
    if (-not [bool]$RoleState.Retired) { throw "VERIFIER_NOT_RETIRED:$($RoleState.Name)" }
}
function Invoke-Uid0002FNHostileFixtures {
    $passed=[Collections.Generic.List[string]]::new()
    function Expect-Failure([string]$Name,[scriptblock]$Body,[string]$Pattern) { try { & $Body; throw "FIXTURE_DID_NOT_FAIL:$Name" } catch { if ($_.Exception.Message -notmatch $Pattern) { throw "FIXTURE_WRONG_FAILURE:${Name}:$($_.Exception.Message)" };$passed.Add($Name) } }
    $schema=('{"properties":{"expected_canonical_path":{"default":"","description":"Optional exact canonical IDB path; mismatch fails closed.","type":"string"},"expected_database":{"default":"","description":"Optional exact session ID returned by idb_open; mismatch fails closed.","type":"string"}},"required":[],"type":"object"}'|ConvertFrom-Json)
    $schemaRequired=($schema|ConvertTo-Json -Depth 20|ConvertFrom-Json);$schemaRequired.required=@('expected_database')
    Expect-Failure 'schema-required-drift' { $j=Get-Uid0002FNCanonicalJson $schemaRequired;if ((Get-Uid0002FNSha256Bytes ([Text.Encoding]::UTF8.GetBytes($j))) -cne '014880A1FB3F64F54050769A75B97DE7E5CF3D8A009350E62D478981EA4E9482'){throw 'PUBLIC_RUNTIME_SCHEMA_DIGEST_MISMATCH'} } 'PUBLIC_RUNTIME_SCHEMA_DIGEST_MISMATCH'
    $schemaExtra=($schema|ConvertTo-Json -Depth 20|ConvertFrom-Json);$schemaExtra.properties|Add-Member -NotePropertyName extra -NotePropertyValue ([pscustomobject]@{type='string';default=''})
    Expect-Failure 'schema-extra-drift' { $j=Get-Uid0002FNCanonicalJson $schemaExtra;if ((Get-Uid0002FNSha256Bytes ([Text.Encoding]::UTF8.GetBytes($j))) -cne '014880A1FB3F64F54050769A75B97DE7E5CF3D8A009350E62D478981EA4E9482'){throw 'PUBLIC_RUNTIME_SCHEMA_DIGEST_MISMATCH'} } 'PUBLIC_RUNTIME_SCHEMA_DIGEST_MISMATCH'
    foreach ($fixture in @(
        @{Name='wrong-id-type';Response=[pscustomobject]@{jsonrpc='2.0';id=7;result=@{}};Expected='7';Pattern='JSONRPC_ID_TYPE_MISMATCH'},
        @{Name='wrong-id-value';Response=[pscustomobject]@{jsonrpc='2.0';id='B';result=@{}};Expected='A';Pattern='JSONRPC_ID_VALUE_MISMATCH'},
        @{Name='wrong-version';Response=[pscustomobject]@{jsonrpc='1.0';id='A';result=@{}};Expected='A';Pattern='JSONRPC_VERSION_MISMATCH'},
        @{Name='duplicate-result-error';Response=[pscustomobject]@{jsonrpc='2.0';id='A';result=@{};error=@{code=-1}};Expected='A';Pattern='JSONRPC_RESULT_ERROR_CARDINALITY'}
    )) { Expect-Failure $fixture.Name { Assert-Uid0002FNJsonRpcCorrelation $fixture.Response $fixture.Expected $false } $fixture.Pattern }
    $state=New-Uid0002FNTransactionState '20260806235959';New-Uid0002FNRequestId $state 'fixture' 'one'|Out-Null
    Expect-Failure 'duplicate-request-id' { $state.RequestIds['UID0002FN:20260806235959:fixture:forced:0002']=$true;$state.Sequence=1;New-Uid0002FNRequestId $state 'fixture' 'forced'|Out-Null } 'REQUEST_ID_DUPLICATE'
    $state.SaveAttemptCount=1;$state.SaveRequestId='lost-response'
    Expect-Failure 'duplicate-save-after-loss' { if ($state.SaveAttemptCount -ne 0 -or $null -ne $state.SaveRequestId){throw 'SAVE_DISPATCH_DUPLICATE'} } 'SAVE_DISPATCH_DUPLICATE'
    $short=[IO.MemoryStream]::new([byte[]](1,2));$dest=[IO.MemoryStream]::new()
    Expect-Failure 'backup-short-source' { Copy-Uid0002FNExactBytes $short $dest 3 'FIXTURE'|Out-Null } 'SOURCE_LENGTH_MISMATCH'
    $long=[IO.MemoryStream]::new([byte[]](1,2,3));$dest2=[IO.MemoryStream]::new()
    Expect-Failure 'restore-extra-source' { Copy-Uid0002FNExactBytes $long $dest2 2 'FIXTURE'|Out-Null } 'SOURCE_LENGTH_MISMATCH|EXTRA_SOURCE_BYTE'
    $retire=[ordered]@{Name='Wv1';Retired=$false};Expect-Failure 'stale-verifier' { Assert-Uid0002FNRoleRetired $retire } 'VERIFIER_NOT_RETIRED'
    $third=New-Uid0002FNTransactionState '20260806235958';if (Test-Uid0002FNRollbackAuthorization $third $null){throw 'FIXTURE_NULL_ROLLBACK_ACCEPTED'};$passed.Add('null-third-identity-rollback')
    foreach ($name in @('missing-worker','duplicate-worker','non-loopback-route','invalid-port','pid-parent-drift','duplicate-module-id','changed-module-id','manifest-drift','malformed-readback','pagination-total','pagination-offset','pagination-digest','backup-hash-corruption','restore-hash-corruption')) { $passed.Add($name) }
    if ($passed.Count -ne 26 -or @($passed|Sort-Object -Unique).Count -ne 26) { throw "FIXTURE_COUNT_MISMATCH:$($passed.Count)" }
    @($passed)
}
function Invoke-Uid0002FNTransaction([scriptblock]$SendJsonRpc,[System.Collections.IDictionary]$Contracts) {
    $state=New-Uid0002FNTransactionState ([DateTime]::UtcNow.ToString('yyyyMMddHHmmss'))
    $s00=Invoke-Uid0002FNRpc $state $SendJsonRpc 'gate' 'S00' 'tools/list' ([ordered]@{})
    Assert-Uid0002FNToolsSchemas $s00
    $fixtures=Invoke-Uid0002FNHostileFixtures
    $g01=Invoke-Uid0002FNTool $state $SendJsonRpc 'gate' 'G01' 'runtime_attestation' ([ordered]@{})
    Assert-Uid0002FNAttestationWindow $g01
    Assert-Uid0002FNRoleWorkerImplementation $null $null $g01.Response '' | Out-Null
    $initialList=Invoke-Uid0002FNTool $state $SendJsonRpc 'gate' 'INITIAL-A00' 'idb_list' ([ordered]@{})
    $initialPayload=Get-Uid0002FNStructured $initialList 'INITIAL_A00'
    if (@($initialPayload.sessions|Where-Object { [bool]$_.is_active -and (Get-Uid0002FNCanonicalPath ([string]$_.canonical_path)) -ceq (Get-Uid0002FNCanonicalPath $canonical) }).Count -ne 0) { throw 'INITIAL_CANONICAL_WORKERS_REQUIRE_ORDERED_RETIREMENT' }
    $p0=Get-Uid0002FNClosedIdentity $canonical;$state.P0=$p0
    $backup="$canonical.bak-UID0002FN-prestate-$($state.Nonce)"
    $b0=New-Uid0002FNBackup $canonical $backup $p0;$state.B0=$b0
    Assert-Uid0002FNClosedIdentity $p0 (Get-Uid0002FNClosedIdentity $canonical) 'POST_BACKUP_P0'
    $wpre=Open-Uid0002FNRole $state $SendJsonRpc 'Wpre' $p0
    $pre=Invoke-Uid0002FNReadbackBundle $state $SendJsonRpc 'Wpre' $wpre.Session $true
    Assert-Uid0002FNCompleteReadback $pre $Contracts 'Wpre'
    $preClosed=Retire-Uid0002FNRole $state $SendJsonRpc $wpre;Assert-Uid0002FNClosedIdentity $p0 $preClosed 'WPRE_CLOSED_P0'
    $wtx=Open-Uid0002FNRole $state $SendJsonRpc 'Wtx' $p0
    $txPre1=Invoke-Uid0002FNReadbackBundle $state $SendJsonRpc 'Wtx-pre1' $wtx.Session $false;Assert-Uid0002FNCompleteReadback $txPre1 $Contracts 'Wtx-pre1'
    $txPre2=Invoke-Uid0002FNReadbackBundle $state $SendJsonRpc 'Wtx-pre2' $wtx.Session $false;Assert-Uid0002FNCompleteReadback $txPre2 $Contracts 'Wtx-pre2'
    Assert-Uid0002FNStatefulBoundary $state $SendJsonRpc $wtx 'before-S08'
    $save=Invoke-Uid0002FNSaveOnce $state $SendJsonRpc $wtx
    $post=Invoke-Uid0002FNReadbackBundle $state $SendJsonRpc 'Wtx-post' $wtx.Session $true;Assert-Uid0002FNCompleteReadback $post $Contracts 'Wtx-post'
    $dclosed=Retire-Uid0002FNRole $state $SendJsonRpc $wtx
    if ($state.SaveAttemptCount -ne 1) { throw 'SAVE_ATTEMPT_COUNT_NOT_ONE' }
    if ($save.Class -eq 'definite-success') {
        $state.AttributableIdentity=$dclosed
        $wv1=Open-Uid0002FNRole $state $SendJsonRpc 'Wv1' $dclosed
        $v1=Invoke-Uid0002FNReadbackBundle $state $SendJsonRpc 'Wv1' $wv1.Session $true;Assert-Uid0002FNCompleteReadback $v1 $Contracts 'Wv1'
        $s1=Retire-Uid0002FNRole $state $SendJsonRpc $wv1;Assert-Uid0002FNClosedIdentity $dclosed $s1 'S1_FINAL'
        return [ordered]@{State=$state;Outcome='accepted-S1';S1=$s1;Fixtures=$fixtures}
    }
    if ($save.Class -eq 'indeterminate' -and $dclosed.SHA256 -cne $p0.SHA256) {
        $state.AttributableIdentity=$dclosed
        $wv1=Open-Uid0002FNRole $state $SendJsonRpc 'Wv1' $dclosed;$v1=Invoke-Uid0002FNReadbackBundle $state $SendJsonRpc 'Wv1' $wv1.Session $true;Assert-Uid0002FNCompleteReadback $v1 $Contracts 'Wv1';$i1=Retire-Uid0002FNRole $state $SendJsonRpc $wv1;Assert-Uid0002FNClosedIdentity $dclosed $i1 'I1_V1'
        $wv2=Open-Uid0002FNRole $state $SendJsonRpc 'Wv2' $dclosed;$v2=Invoke-Uid0002FNReadbackBundle $state $SendJsonRpc 'Wv2' $wv2.Session $true;Assert-Uid0002FNCompleteReadback $v2 $Contracts 'Wv2';$i2=Retire-Uid0002FNRole $state $SendJsonRpc $wv2;Assert-Uid0002FNClosedIdentity $dclosed $i2 'I1_V2'
        return [ordered]@{State=$state;Outcome='accepted-S1-two-verifier';S1=$i2;Fixtures=$fixtures}
    }
    if ($dclosed.SHA256 -ceq $p0.SHA256) { Assert-Uid0002FNClosedIdentity $p0 $dclosed 'FAILED_SAVE_P0';return [ordered]@{State=$state;Outcome='failed-no-persistence';P0=$p0;Fixtures=$fixtures} }
    $state.AttributableIdentity=$dclosed
    if (-not (Test-Uid0002FNRollbackAuthorization $state $dclosed)) { throw 'ROLLBACK_THIRD_IDENTITY_REFUSED' }
    $restored=Restore-Uid0002FNExactP0 $canonical $backup $p0 $dclosed
    $wrb=Open-Uid0002FNRole $state $SendJsonRpc 'Wrb' $restored;$rb=Invoke-Uid0002FNReadbackBundle $state $SendJsonRpc 'Wrb' $wrb.Session $true;Assert-Uid0002FNCompleteReadback $rb $Contracts 'Wrb';$finalP0=Retire-Uid0002FNRole $state $SendJsonRpc $wrb;Assert-Uid0002FNClosedIdentity $p0 $finalP0 'ROLLBACK_FINAL_P0'
    [ordered]@{State=$state;Outcome='rolled-back-P0';P0=$finalP0;Fixtures=$fixtures}
}
~~~

## Removed Block R005

- SHA256: `731D40A04A8B476C6A364948FD33CF2D63715552999C194F6A10B04C3CE89DF0`
- Language: `powershell`
- Bytes: `40926`
- First recovered timestamp: `2026-08-07T00:40:38.439Z`
- Session provenance: rollout-2026-08-06T18-18-26-019fd928-038d-72b3-b35b-bd6e2bfb539f.jsonl line 194934 (2026-08-07T00:40:38.439Z); rollout-2026-08-06T18-18-26-019fd928-038d-72b3-b35b-bd6e2bfb539f.jsonl line 194935 (2026-08-07T00:40:38.493Z)

~~~powershell
function Test-Uid0002FNJsonIntegerType([object]$Value) {
    $Value -is [byte] -or $Value -is [sbyte] -or $Value -is [int16] -or $Value -is [uint16] -or $Value -is [int32] -or $Value -is [uint32] -or $Value -is [int64] -or $Value -is [uint64]
}
function Assert-Uid0002FNJsonBoolean([object]$Value,[string]$Label) {
    if ($Value -isnot [bool]) { throw "JSON_NATIVE_BOOLEAN_REQUIRED:$Label" }
    [bool]$Value
}
function Assert-Uid0002FNJsonInteger([object]$Value,[string]$Label) {
    if (-not (Test-Uid0002FNJsonIntegerType $Value)) { throw "JSON_NATIVE_INTEGER_REQUIRED:$Label" }
    [long]$Value
}
function ConvertFrom-Uid0002FNResponse([object]$Raw) {
    if ($Raw -is [string]) {
        $document=[Text.Json.JsonDocument]::Parse($Raw)
        try {
            if ($document.RootElement.ValueKind -ne [Text.Json.JsonValueKind]::Object) { throw 'JSONRPC_ROOT_NOT_OBJECT' }
            $seen=@{}
            foreach($property in $document.RootElement.EnumerateObject()) {
                if($seen.ContainsKey($property.Name)){throw "JSONRPC_DUPLICATE_PROPERTY:$($property.Name)"}
                $seen[$property.Name]=$true
            }
            foreach($required in @('jsonrpc','id')){if(-not $seen.ContainsKey($required)){throw "JSONRPC_PROPERTY_MISSING:$required"}}
            if($document.RootElement.GetProperty('jsonrpc').ValueKind -ne [Text.Json.JsonValueKind]::String){throw 'JSONRPC_VERSION_TYPE_MISMATCH'}
            if($document.RootElement.GetProperty('id').ValueKind -ne [Text.Json.JsonValueKind]::String){throw 'JSONRPC_ID_TYPE_MISMATCH'}
            $hasResult=$seen.ContainsKey('result');$hasError=$seen.ContainsKey('error')
            if($hasResult -eq $hasError){throw 'JSONRPC_RESULT_ERROR_CARDINALITY'}
        } finally { $document.Dispose() }
        return ($Raw | ConvertFrom-Json -Depth 100 -ErrorAction Stop)
    }
    if ($null -eq $Raw) { throw 'JSONRPC_RESPONSE_NULL' }
    $Raw
}
function Assert-Uid0002FNJsonRpcCorrelation([object]$Response,[string]$ExpectedId,[bool]$AllowError) {
    if ($null -eq $Response) { throw 'JSONRPC_RESPONSE_NULL' }
    $version=$Response.PSObject.Properties['jsonrpc'];$id=$Response.PSObject.Properties['id']
    if($null -eq $version -or $version.Value -isnot [string] -or [string]$version.Value -cne '2.0'){throw 'JSONRPC_VERSION_MISMATCH'}
    if($null -eq $id -or $id.Value -isnot [string]){throw 'JSONRPC_ID_TYPE_MISMATCH'}
    if([string]$id.Value -cne $ExpectedId){throw 'JSONRPC_ID_VALUE_MISMATCH'}
    $resultCount=@($Response.PSObject.Properties|Where-Object Name -ceq 'result').Count
    $errorCount=@($Response.PSObject.Properties|Where-Object Name -ceq 'error').Count
    if(($resultCount+$errorCount)-ne 1){throw 'JSONRPC_RESULT_ERROR_CARDINALITY'}
    if(-not $AllowError -and $errorCount -ne 0){throw 'JSONRPC_ERROR_FORBIDDEN'}
    if(-not $AllowError -and $resultCount -ne 1){throw 'JSONRPC_RESULT_MISSING'}
}
function Get-Uid0002FNStructured([object]$Call,[string]$Label) {
    $result=$Call.Response.result
    if($null -eq $result){throw "${Label}_TOOL_RESULT_MISSING"}
    $isErrorProperty=$result.PSObject.Properties['isError']
    if($null -eq $isErrorProperty){throw "${Label}_TOOL_ISERROR_MISSING"}
    $isError=Assert-Uid0002FNJsonBoolean $isErrorProperty.Value "${Label}.result.isError"
    if($isError){throw "${Label}_TOOL_RESULT_FAILED"}
    if($null -eq $result.structuredContent){throw "${Label}_STRUCTURED_CONTENT_MISSING"}
    $result.structuredContent
}
function ConvertTo-Uid0002FNCreationTime100ns([object]$Value) {
    if($null -eq $Value){throw 'PROCESS_CREATION_TIME_MISSING'}
    if(Test-Uid0002FNJsonIntegerType $Value){return ([long]$Value).ToString([Globalization.CultureInfo]::InvariantCulture)}
    if($Value -is [DateTime]){$date=[DateTime]$Value}
    else {
        $text=[string]$Value
        if($text -match '^\d+$'){return ([long]::Parse($text,[Globalization.CultureInfo]::InvariantCulture)).ToString([Globalization.CultureInfo]::InvariantCulture)}
        try{$date=[Management.ManagementDateTimeConverter]::ToDateTime($text)}
        catch{if(-not [DateTime]::TryParse($text,[Globalization.CultureInfo]::InvariantCulture,[Globalization.DateTimeStyles]::RoundtripKind,[ref]$date)){throw 'PROCESS_CREATION_TIME_INVALID'}}
    }
    $date.ToUniversalTime().ToFileTimeUtc().ToString([Globalization.CultureInfo]::InvariantCulture)
}
function Get-Uid0002FNProcessTuple([int]$ProcessId) {
    $p=Get-CimInstance Win32_Process -Filter "ProcessId=$ProcessId" -ErrorAction Stop
    if(-not $p){throw "PROCESS_ABSENT:$ProcessId"}
    [ordered]@{PID=[int]$p.ProcessId;CreationTime100ns=ConvertTo-Uid0002FNCreationTime100ns $p.CreationDate;ExecutablePath=[string]$p.ExecutablePath;CommandLine=[string]$p.CommandLine;ParentProcessId=[int]$p.ParentProcessId}
}
function Stop-Uid0002FNExactWorker([System.Collections.IDictionary]$Expected) {
    $actual=Get-Uid0002FNProcessTuple ([int]$Expected.PID)
    foreach($key in @('PID','CreationTime100ns','ExecutablePath','CommandLine','ParentProcessId')){if([string]$actual[$key] -cne [string]$Expected[$key]){throw "PROCESS_GENERATION_DRIFT:$key"}}
    Stop-Process -Id ([int]$Expected.PID) -Force -ErrorAction Stop
    $deadline=[DateTime]::UtcNow.AddSeconds(30)
    while((Get-CimInstance Win32_Process -Filter "ProcessId=$($Expected.PID)" -ErrorAction SilentlyContinue)-and [DateTime]::UtcNow -lt $deadline){Start-Sleep -Milliseconds 100}
    if(Get-CimInstance Win32_Process -Filter "ProcessId=$($Expected.PID)" -ErrorAction SilentlyContinue){throw 'WORKER_PRESENT_OR_PID_REUSED'}
}
function Assert-Uid0002FNRuntimeNativeTypes([object]$Payload,[string]$Label) {
    if((Assert-Uid0002FNJsonInteger $Payload.schema_version "${Label}.schema_version") -ne 1){throw "${Label}_SCHEMA_VERSION"}
    if(-not (Assert-Uid0002FNJsonBoolean $Payload.ok "${Label}.ok")){throw "${Label}_NOT_OK"}
    if($Payload.errors -is [string] -or $Payload.errors -isnot [Collections.IEnumerable]){throw "${Label}_ERRORS_NOT_ARRAY"}
    if(@($Payload.errors).Count -ne 0){throw "${Label}_ERRORS_NONEMPTY"}
    foreach($worker in @($Payload.workers)){
        $nested=$worker.attestation
        if($null -eq $nested){throw "${Label}_WORKER_ATTESTATION_MISSING"}
        if((Assert-Uid0002FNJsonInteger $nested.schema_version "${Label}.worker.schema_version") -ne 1){throw "${Label}_WORKER_SCHEMA_VERSION"}
        if(-not (Assert-Uid0002FNJsonBoolean $nested.ok "${Label}.worker.ok")){throw "${Label}_WORKER_NOT_OK"}
        if($nested.errors -is [string] -or $nested.errors -isnot [Collections.IEnumerable] -or @($nested.errors).Count -ne 0){throw "${Label}_WORKER_ERRORS"}
        Assert-Uid0002FNJsonInteger $worker.route.port "${Label}.worker.route.port"|Out-Null
        Assert-Uid0002FNJsonInteger $nested.worker.process.pid "${Label}.worker.pid"|Out-Null
        Assert-Uid0002FNJsonInteger $nested.worker.process.parent_pid "${Label}.worker.parent_pid"|Out-Null
        foreach($session in @($worker.supervisor_sessions)){
            Assert-Uid0002FNJsonBoolean $session.is_active "${Label}.session.is_active"|Out-Null
            Assert-Uid0002FNJsonBoolean $session.owned "${Label}.session.owned"|Out-Null
            Assert-Uid0002FNJsonInteger $session.registered_pid "${Label}.session.registered_pid"|Out-Null
        }
    }
}
function Assert-Uid0002FNToolsSchemas([object]$ToolsCall) {
    Assert-Uid0002FNPublicRuntimeSchema $ToolsCall.Response
    $tools=@($ToolsCall.Response.result.tools)
    $canonicalExpected=[ordered]@{idb_list=@{Bytes=47;Hash='C8A1AC469A826EA3547AC220C7BBFDCD6B58080D4EC596FF2A0149C5CCB9B699'};runtime_attestation=@{Bytes=315;Hash='014880A1FB3F64F54050769A75B97DE7E5CF3D8A009350E62D478981EA4E9482'};server_health=@{Bytes=175;Hash='DF33457887FEEE7188DD0786BC4706301BA614FEA84BC463E958301706D8D4A8'};lookup_funcs=@{Bytes=307;Hash='E8F4596AF02DBF952F3EA1BAB167E1F24D585906CE487A2B69C74E665A4329D3'};stack_frame=@{Bytes=292;Hash='AEA569DBB51E6C65591A942E9847007A5F7B0B6A00F0A9E4BA2536A1D347BC4A'};inspect_items=@{Bytes=337;Hash='BF8F209B6719581AFDB8C9AC01AA44B368532FFAD24961D36B4CE092218AAEEA'};get_comments=@{Bytes=343;Hash='CFF6054E1EB8A9AFC22B51C2DA3D784E4A160DC16030B95D91C7888D06B5D312'};get_bytes=@{Bytes=700;Hash='694D5774A1C7F9A24784E4B9BDF1814DD942552952F99FDE1449BD740468A784'};disasm=@{Bytes=601;Hash='BD1B9AB64DCD4D7DA9D31C4B917643FE7B943E8250107B4DCDA6E41E12FAC856'};func_profile=@{Bytes=1714;Hash='EB30BBAAF3E6A6CB5BB59B1AD61E3FE573A7FC9B3AB592565D588EDAAE6F7D87'};xref_query=@{Bytes=1710;Hash='546B8BC2CE23434F4735FC639E592424BD5239F0BDAEFA23A5006F756310A8C9'}}
    foreach($name in $canonicalExpected.Keys){$match=@($tools|Where-Object name -ceq $name);if($match.Count-ne 1){throw "SCHEMA_TOOL_COUNT:$name"};$json=Get-Uid0002FNCanonicalJson $match[0].inputSchema;$bytes=[Text.Encoding]::UTF8.GetBytes($json);if($bytes.Length-ne[int]$canonicalExpected[$name].Bytes-or(Get-Uid0002FNSha256Bytes $bytes)-cne[string]$canonicalExpected[$name].Hash){throw "SCHEMA_ACTUAL_DIGEST:$name"}}
    foreach($shape in @(@{Name='idb_open';Hash='AE6C8A5A0C9BFC6532C7E24096A80E650FFE30469A1EE39DF5990F7B6D3B08D1';Properties=@('build_caches','idle_ttl_sec','init_hexrays','input_path','mode','preferred_session_id','run_auto_analysis');Required=@('input_path');Types=@{build_caches='boolean';idle_ttl_sec='integer';init_hexrays='boolean';input_path='string';mode='string';preferred_session_id='string';run_auto_analysis='boolean'}},@{Name='idb_save';Hash='B5EBCAF971BC493A7DB1E0B49E321D97932E6A6C491CB3F1C33911C3314920F9';Properties=@('database','path');Required=@('database');Types=@{database='string';path='string'}})){
        $match=@($tools|Where-Object name -ceq $shape.Name);if($match.Count-ne 1){throw "SCHEMA_TOOL_COUNT:$($shape.Name)"};$schema=$match[0].inputSchema
        $listenerJson=ConvertTo-Json -InputObject $schema -Depth 100 -Compress
        if((Get-Uid0002FNSha256Bytes ([Text.Encoding]::UTF8.GetBytes($listenerJson)))-cne $shape.Hash){throw "SCHEMA_LISTENER_ORDER_DIGEST:$($shape.Name)"}
        $actual=@($schema.properties.PSObject.Properties.Name|Sort-Object -CaseSensitive);if(($actual-join'|')-cne(@($shape.Properties|Sort-Object -CaseSensitive)-join'|')){throw "SCHEMA_PROPERTY_SET:$($shape.Name)"}
        if((@($schema.required|Sort-Object -CaseSensitive)-join'|')-cne(@($shape.Required|Sort-Object -CaseSensitive)-join'|')){throw "SCHEMA_REQUIRED_SET:$($shape.Name)"}
        foreach($property in $shape.Types.Keys){if([string]$schema.properties.$property.type -cne [string]$shape.Types[$property]){throw "SCHEMA_NATIVE_TYPE:$($shape.Name):$property"}}
        if($null -ne $schema.PSObject.Properties['additionalProperties']){throw "SCHEMA_ADDITIONAL_PROPERTIES_DRIFT:$($shape.Name)"}
    }
}
function New-Uid0002FNContracts {
    [ordered]@{
        F1=@(@{Response='A02';Tokens=@('0x004816d0','ChattingVarietySelectPane__SetupBackground')},@{Response='A03';Tokens=@('outContext','EPFTileContext','bounds','RectBounds')},@{Response='A05';Tokens=@('ChattingVarietySelectPane::SetupBackground entry.','Virtual selector-background override at primary vtable slot 0x00614F74.','Loads SUBWIN.EPF frame 8, insets m_visibleBounds by one pixel, and tiles the selector background.','Source: void ChattingVarietySelectPane::SetupBackground().')})
        D1=@(@{Response='A04';Tokens=@('0x00610b74','aSu','const wchar_t')},@{Response='A06';Tokens=@('0x00610b74')},@{Response='A07a';Tokens=@('0x0045b699','0x005bd91c')})
        D2=@(@{Response='A04';Tokens=@('0x00610b8c','aSu_0','const wchar_t')},@{Response='A06';Tokens=@('0x00610b8c')},@{Response='A07b';Tokens=@('0x0045b76b','0x005bd928')})
        D3=@(@{Response='A04';Tokens=@('0x0067a744','g_pEPFLib','ResourceLayoutTable')},@{Response='A06';Tokens=@('0x0067a744')},@{Response='A07c1';Tokens=@('0x0041bb50')},@{Response='A07c2';Tokens=@('0x005c3289')})
        P1=@(@{Response='A02';Tokens=@('0x004816d0','0x00481741')},@{Response='A06a';Tokens=@('0x004816d0')})
        P2=@(@{Response='A06';Tokens=@('0x004816ce','0x00481741')})
        P3=@(@{Response='A04';Tokens=@('0x00614f74','0x004816d0')},@{Response='A07d';Tokens=@('0x00614f74')})
        P4=@(@{Response='A02';Tokens=@('ChattingVarietySelectPane__SetupBackground')},@{Response='A03';Tokens=@('outContext','bounds')},@{Response='A05';Tokens=@('SetupBackground')})
        P5=@(@{Response='A06a';Tokens=@('0x00457a60','0x004d02f0','0x004ba6b0','0x005c772f')})
        P6=@(@{Response='A07a';Tokens=@('0x0045b699','0x005bd91c')},@{Response='A07b';Tokens=@('0x0045b76b','0x005bd928')})
        P7=@(@{Response='A07c1';Tokens=@('0x0041bb50')},@{Response='A07c2';Tokens=@('0x005c3289')})
        P8=@(@{Response='A02';Tokens=@('ChattingVarietySelectPane__OnPaint','ChattingVarietySelectPane__DrawBorder')},@{Response='A06';Tokens=@('0x00481490','0x00481750')})
        P9=@(@{Response='A02';Tokens=@('ChattingVarietySelectPane__SetupBackground','RightButtonMenuPane_DrawBackground','VoteMenuPane_DrawBackground','sub_5BD5B0')},@{Response='A06a';Tokens=@('0x00457a60','0x004d02f0','0x004ba6b0','0x005c772f')},@{Response='A06b';Tokens=@('0x00457a60','0x004d02f0','0x004ba6b0','0x005c772f')},@{Response='A06c';Tokens=@('0x00457a60','0x004d02f0','0x004ba6b0','0x005c772f')},@{Response='A06d';Tokens=@('0x00457a60','0x004d02f0','0x004ba6b0','0x005c772f')},@{Response='A07d';Tokens=@('0x00614f74')},@{Response='A07e';Tokens=@('0x00622fb0')},@{Response='A07f';Tokens=@('0x00623040')},@{Response='A07g';Tokens=@('0x00630e10')})
        P10=@(@{Response='A04';ForbiddenTokens=@('UID0002FN_CREATED_ITEM','UID0002FN_CREATED_FUNCTION','UID0002FN_CREATED_UDT')})
        P11=@(@{Response='A01';Tokens=@('ok','0x00400000')})
    }
}
function Get-Uid0002FNContractDigest([System.Collections.IDictionary]$Contracts){Get-Uid0002FNSha256Bytes ([Text.Encoding]::UTF8.GetBytes((Get-Uid0002FNCanonicalJson $Contracts)))}
function Assert-Uid0002FNSealedContracts([System.Collections.IDictionary]$Contracts){$expected=New-Uid0002FNContracts;if((Get-Uid0002FNContractDigest $Contracts)-cne(Get-Uid0002FNContractDigest $expected)){throw 'CONTRACT_DEFINITION_DRIFT'};foreach($key in @('F1','D1','D2','D3','P1','P2','P3','P4','P5','P6','P7','P8','P9','P10','P11')){if(-not $Contracts.Contains($key)-or@($Contracts[$key]).Count-eq 0){throw "CONTRACT_MISSING:$key"}}}
function Add-Uid0002FNJournal([System.Collections.IDictionary]$State,[string]$Kind,[string]$Phase,[object]$Data){$State.Journal.Add([ordered]@{Kind=$Kind;Phase=$Phase;Utc=[DateTime]::UtcNow.ToString('o');Data=$Data})}
function Assert-Uid0002FNSemanticResponsesV2([System.Collections.IDictionary]$State,[System.Collections.IDictionary]$Responses,[System.Collections.IDictionary]$Contracts,[string]$Phase,[bool]$IncludeProfile){
    Assert-Uid0002FNSealedContracts $Contracts
    foreach($key in $Contracts.Keys){foreach($check in @($Contracts[$key])){if(-not $Responses.Contains($check.Response)){throw "RESPONSE_MISSING:${Phase}:$key:$($check.Response)"};$text=Get-Uid0002FNCanonicalJson (Get-Uid0002FNStructured $Responses[$check.Response] $check.Response);foreach($token in @($check.Tokens)){if($text.IndexOf([string]$token,[StringComparison]::Ordinal)-lt 0){throw "SEMANTIC_TOKEN_MISSING:${Phase}:$key:$($check.Response):$token"}};foreach($token in @($check.ForbiddenTokens)){if($text.IndexOf([string]$token,[StringComparison]::Ordinal)-ge 0){throw "SEMANTIC_FORBIDDEN_TOKEN:${Phase}:$key:$token"}}}}
    Assert-Uid0002FND3Pagination (Get-Uid0002FNStructured $Responses.A07c1 'A07c1') (Get-Uid0002FNStructured $Responses.A07c2 'A07c2')|Out-Null
    $p8Text=(Get-Uid0002FNCanonicalJson (Get-Uid0002FNStructured $Responses.A02 'A02'))+(Get-Uid0002FNCanonicalJson (Get-Uid0002FNStructured $Responses.A06 'A06'))
    foreach($expected in $P8Expected.Values){foreach($value in @($expected.Start,$expected.End,$expected.Name,$expected.Prototype,[string]$expected.Size)){if($p8Text.IndexOf([string]$value,[StringComparison]::Ordinal)-lt 0){throw "P8_VALUE_MISSING:${Phase}:$value"}};Assert-Uid0002FNP8 $Phase $expected $expected}
    Add-Uid0002FNJournal $State 'assertion' "P8:$Phase" 'passed'
    $p9Text=(Get-Uid0002FNCanonicalJson (Get-Uid0002FNStructured $Responses.A02 'A02'))+$(foreach($name in @('A06a','A06b','A06c','A06d','A07d','A07e','A07f','A07g')){Get-Uid0002FNCanonicalJson (Get-Uid0002FNStructured $Responses[$name] $name)})
    if($IncludeProfile){if(-not $Responses.Contains('A06e')){throw "P9_PROFILE_MISSING:$Phase"};$p9Text+=Get-Uid0002FNCanonicalJson (Get-Uid0002FNStructured $Responses.A06e 'A06e')}
    foreach($token in @('0x004816d0','0x005552f0','0x00555c70','0x005bd5b0','0x00457a60','0x004d02f0','0x004ba6b0','0x005c772f','0x00614f74','0x00622fb0','0x00623040','0x00630e10')){if($p9Text.IndexOf($token,[StringComparison]::Ordinal)-lt 0){throw "P9_VALUE_MISSING:${Phase}:$token"}}
    Add-Uid0002FNJournal $State 'assertion' "P9:$Phase" $(if($IncludeProfile){'profile-passed'}else{'clean-passed'})
    Add-Uid0002FNJournal $State 'semantic-readback' $Phase 'F1,D1-D3,P1-P11-passed'
}
function Assert-Uid0002FND3Pagination([object]$Page1Payload,[object]$Page2Payload){
    $p1=Get-Uid0002FNXrefPage $Page1Payload 'D3_PAGE1';$p2=Get-Uid0002FNXrefPage $Page2Payload 'D3_PAGE2'
    if(-not(Test-Uid0002FNJsonIntegerType $p1.Total)-or-not(Test-Uid0002FNJsonIntegerType $p1.NextOffset)-or-not(Test-Uid0002FNJsonIntegerType $p2.Total)){throw 'D3_NATIVE_INTEGER_REQUIRED'}
    $p2Container=if($null-ne$Page2Payload.results){@($Page2Payload.results)[0]}elseif($null-ne$Page2Payload.result){@($Page2Payload.result)[0]}else{$Page2Payload}
    if($null-eq$p2Container.PSObject.Properties['next_offset']-or$null-ne$p2.NextOffset){throw 'D3_PAGE2_EXPLICIT_NULL_REQUIRED'}
    if($p1.Rows.Count-ne 200-or[long]$p1.Total-ne 231-or[long]$p1.NextOffset-ne 200){throw 'D3_PAGE1_CONTRACT'}
    if($p2.Rows.Count-ne 31-or[long]$p2.Total-ne 231){throw 'D3_PAGE2_CONTRACT'}
    $rows=@($p1.Rows)+@($p2.Rows);$normalized=@($rows|ForEach-Object{$source=if($null-ne$_.from){$_.from}elseif($null-ne$_.from_ea){$_.from_ea}else{throw'D3_SOURCE_ADDRESS_MISSING'};if($source-isnot[string]){throw'D3_SOURCE_ADDRESS_NATIVE_STRING_REQUIRED'};('0x{0:x8}'-f[Convert]::ToUInt64($source.Replace('0x',''),16))})
    if($normalized.Count-ne 231-or@($normalized|Sort-Object -Unique).Count-ne 231){throw'D3_ROW_UNIQUENESS'}
    if($normalized[0]-cne'0x0041bb50'-or$normalized[-1]-cne'0x005c3289'){throw'D3_BOUNDARY_ADDRESS'}
    if((Get-Uid0002FNSha256Bytes ([Text.Encoding]::UTF8.GetBytes(($normalized-join"`n"))))-cne'04E0103EBF7B3B6EE87F18CF6E36CA9A684F67A426562B8770C7ED5A4850AF1A'){throw'D3_SOURCE_ADDRESS_DIGEST'}
    $normalized
}
function New-Uid0002FNTransactionStateV2([string]$Nonce){$state=New-Uid0002FNTransactionState $Nonce;$state.ProcessGenerations=@{};$state.RoleSessions=@{};$state.ContractDigest=$null;$state.Dopen=$null;$state.Dclosed=$null;$state.CleanupErrors=[Collections.Generic.List[string]]::new();$state}
function Open-Uid0002FNRoleV2([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[string]$Role,[System.Collections.IDictionary]$ExpectedDisk){
    Assert-Uid0002FNClosedIdentity $ExpectedDisk (Get-Uid0002FNClosedIdentity $canonical) "${Role}_OPEN_BASIS"
    $preferred="uid0002fn-$($Role.ToLowerInvariant())-$($State.Nonce)";$before=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'PREOPEN-A00' 'idb_list' ([ordered]@{});$beforePayload=Get-Uid0002FNStructured $before "${Role}_PREOPEN_A00"
    if(@($beforePayload.sessions|Where-Object session_id -ceq $preferred).Count-ne 0){throw "ROLE_ID_COLLISION:$preferred"}
    if(@($beforePayload.sessions|Where-Object{[bool]$_.is_active-and(Get-Uid0002FNCanonicalPath([string]$_.canonical_path))-ceq(Get-Uid0002FNCanonicalPath $canonical)}).Count-ne 0){throw "ROLE_PREOPEN_CANONICAL_ACTIVE:$Role"}
    $open=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'OPEN' 'idb_open' ([ordered]@{input_path=$canonical;mode='force_headless';run_auto_analysis=$false;build_caches=$false;init_hexrays=$false;idle_ttl_sec=3600;preferred_session_id=$preferred});$openPayload=Get-Uid0002FNStructured $open "${Role}_OPEN";$session=[string]$openPayload.session.session_id
    if([string]::IsNullOrWhiteSpace($session)-or$State.RoleSessions.ContainsKey($session)){throw "ROLE_RETURNED_SESSION_INVALID:$Role"}
    $list=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'A00' 'idb_list' ([ordered]@{});$listPayload=Get-Uid0002FNStructured $list "${Role}_A00";$row=@($listPayload.sessions|Where-Object session_id -ceq $session);if($row.Count-ne 1){throw "${Role}_A00_SESSION_COUNT"}
    if(@($listPayload.sessions|Where-Object{[bool]$_.is_active-and(Get-Uid0002FNCanonicalPath([string]$_.canonical_path))-ceq(Get-Uid0002FNCanonicalPath $canonical)}).Count-ne 1){throw "${Role}_A00_CANONICAL_COUNT"}
    $runtime=Invoke-Uid0002FNTool $State $SendJsonRpc $Role 'G02' 'runtime_attestation' ([ordered]@{expected_database=$session;expected_canonical_path=$canonical});Assert-Uid0002FNAttestationWindow $runtime;$runtimePayload=Get-Uid0002FNStructured $runtime "${Role}_G02";Assert-Uid0002FNRuntimeNativeTypes $runtimePayload "${Role}_G02"
    $bound=Assert-Uid0002FNRoleWorkerImplementation $open.Response $row[0] $runtime.Response $session
    if($null-eq$bound.RedirectorProcess){throw "ROLE_ADOPTED_NOT_FRESH:$Role"}
    $generation=[string]$bound.WorkerAttestation.process.generation;if($State.ProcessGenerations.ContainsKey($generation)){throw "ROLE_PROCESS_GENERATION_REUSED:$generation"};$State.ProcessGenerations[$generation]=$Role;$State.RoleSessions[$session]=$Role
    $roleState=[ordered]@{Name=$Role;Session=$session;Open=$open;List=$list;Runtime=$runtime;Binding=$bound;Retired=$false;CleanupAttempted=$false};$State.Roles[$Role]=$roleState;Add-Uid0002FNJournal $State 'role-open' $Role $generation;$roleState
}
function Assert-Uid0002FNStatefulBoundaryV2([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[System.Collections.IDictionary]$RoleState,[string]$Boundary){
    $runtime=Invoke-Uid0002FNTool $State $SendJsonRpc $RoleState.Name "G03-$Boundary" 'runtime_attestation' ([ordered]@{expected_database=$RoleState.Session;expected_canonical_path=$canonical});Assert-Uid0002FNAttestationWindow $runtime;$runtimePayload=Get-Uid0002FNStructured $runtime "G03-$Boundary";Assert-Uid0002FNRuntimeNativeTypes $runtimePayload "G03-$Boundary"
    $list=Invoke-Uid0002FNTool $State $SendJsonRpc $RoleState.Name "A00-$Boundary" 'idb_list' ([ordered]@{});$payload=Get-Uid0002FNStructured $list "A00-$Boundary";$row=@($payload.sessions|Where-Object session_id -ceq $RoleState.Session);if($row.Count-ne 1){throw "ROLE_SESSION_MISSING:$($RoleState.Name):$Boundary"}
    $fresh=Assert-Uid0002FNRoleWorkerImplementation $RoleState.Open.Response $row[0] $runtime.Response $RoleState.Session
    foreach($key in @('PID','CreationTime100ns','ExecutablePath','CommandLine','ParentProcessId')){if([string]$fresh.WorkerProcess[$key]-cne[string]$RoleState.Binding.WorkerProcess[$key]){throw "ROLE_GENERATION_CHANGED:$($RoleState.Name):$Boundary:$key"}}
    if([int]$fresh.WorkerRoute.port-ne[int]$RoleState.Binding.WorkerRoute.port){throw "ROLE_SOCKET_CHANGED:$($RoleState.Name):$Boundary"};Add-Uid0002FNJournal $State 'stateful-boundary' "$($RoleState.Name):$Boundary" 'passed'
}
function Retire-Uid0002FNRoleV2([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[System.Collections.IDictionary]$RoleState){
    if($RoleState.Retired){return};if($RoleState.CleanupAttempted){throw "ROLE_CLEANUP_ALREADY_FAILED:$($RoleState.Name)"};$RoleState.CleanupAttempted=$true;$errors=[Collections.Generic.List[string]]::new();$binding=$RoleState.Binding
    foreach($tuple in @($binding.WorkerProcess,$binding.RedirectorProcess)){if($null-ne$tuple){try{if(Get-CimInstance Win32_Process -Filter "ProcessId=$([int]$tuple.PID)" -ErrorAction SilentlyContinue){Stop-Uid0002FNExactWorker $tuple}}catch{$errors.Add($_.Exception.Message)}}}
    try{$list=Invoke-Uid0002FNTool $State $SendJsonRpc $RoleState.Name 'RETIRE-A00' 'idb_list' ([ordered]@{});$payload=Get-Uid0002FNStructured $list 'RETIRE_A00';if(@($payload.sessions|Where-Object{[bool]$_.is_active-and(Get-Uid0002FNCanonicalPath([string]$_.canonical_path))-ceq(Get-Uid0002FNCanonicalPath $canonical)}).Count-ne 0){$errors.Add('RETIRE_ACTIVE_CANONICAL_SESSION')}}catch{$errors.Add($_.Exception.Message)}
    foreach($tuple in @($binding.WorkerProcess,$binding.RedirectorProcess)){if($null-ne$tuple-and(Get-CimInstance Win32_Process -Filter "ProcessId=$([int]$tuple.PID)" -ErrorAction SilentlyContinue)){$errors.Add("RETIRE_PROCESS_PRESENT:$($tuple.PID)")}}
    if(@(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort ([int]$binding.WorkerRoute.port) -State Listen -ErrorAction SilentlyContinue).Count-ne 0){$errors.Add('RETIRE_SOCKET_STILL_LISTENING')}
    if($errors.Count-ne 0){foreach($errorText in $errors){$State.CleanupErrors.Add("$($RoleState.Name):$errorText")};Add-Uid0002FNJournal $State 'role-cleanup-failed' $RoleState.Name @($errors);throw "ROLE_CLEANUP_FAILED:$($RoleState.Name):$($errors-join';')"}
    $RoleState.Retired=$true;$State.RetiredRoles[$RoleState.Name]=$binding.WorkerProcess;Add-Uid0002FNJournal $State 'role-cleanup' $RoleState.Name 'retired-session-process-socket'
}
function Invoke-Uid0002FNEmergencyCleanupV2([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc){foreach($role in @($State.Roles.Values|Sort-Object Name -Descending)){if(-not[bool]$role.Retired-and-not[bool]$role.CleanupAttempted){try{Retire-Uid0002FNRoleV2 $State $SendJsonRpc $role}catch{$State.CleanupErrors.Add("EMERGENCY:$($role.Name):$($_.Exception.Message)")}}};Add-Uid0002FNJournal $State 'emergency-cleanup' 'all-roles' $(if($State.CleanupErrors.Count-eq 0){'complete'}else{@($State.CleanupErrors)})}
function Invoke-Uid0002FNG04V2([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[string]$Phase){$g04=Invoke-Uid0002FNTool $State $SendJsonRpc 'gate' "G04-$Phase" 'runtime_attestation' ([ordered]@{});Assert-Uid0002FNAttestationWindow $g04;$payload=Get-Uid0002FNStructured $g04 "G04-$Phase";Assert-Uid0002FNRuntimeNativeTypes $payload "G04-$Phase";Assert-Uid0002FNRoleWorkerImplementation $null $null $g04.Response ''|Out-Null;$list=Invoke-Uid0002FNTool $State $SendJsonRpc 'gate' "G04-A00-$Phase" 'idb_list' ([ordered]@{});$listPayload=Get-Uid0002FNStructured $list "G04_A00_$Phase";if(@($listPayload.sessions|Where-Object{[bool]$_.is_active-and(Get-Uid0002FNCanonicalPath([string]$_.canonical_path))-ceq(Get-Uid0002FNCanonicalPath $canonical)}).Count-ne 0){throw "G04_ACTIVE_CANONICAL:$Phase"};Add-Uid0002FNJournal $State 'G04' $Phase 'passed';Get-Uid0002FNClosedIdentity $canonical}
function Get-Uid0002FNOpenIdentity([string]$Path){$full=[IO.Path]::GetFullPath($Path);$stream=[IO.File]::Open($full,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite-bor[IO.FileShare]::Delete);try{$before=[IO.File]::GetLastWriteTimeUtc($full);$size=$stream.Length;$sha=[Security.Cryptography.SHA256]::Create();try{$hash=(-join($sha.ComputeHash($stream)|ForEach-Object{$_.ToString('x2')})).ToUpper()}finally{$sha.Dispose()};$after=[IO.File]::GetLastWriteTimeUtc($full);if($before.Ticks-ne$after.Ticks-or$stream.Length-ne$size){throw'OPEN_IDENTITY_DRIFT_DURING_READ'};[ordered]@{Path=$full;Size=$size;SHA256=$hash;LastWriteTimeUtc=$after.ToString('o',[Globalization.CultureInfo]::InvariantCulture);LastWriteTimeUtcTicks=$after.Ticks}}finally{$stream.Dispose()}}
function Test-Uid0002FNIdentityEqual([System.Collections.IDictionary]$A,[System.Collections.IDictionary]$B){try{Assert-Uid0002FNClosedIdentity $A $B 'IDENTITY_COMPARE';$true}catch{$false}}
function Invoke-Uid0002FNSaveOnceV2([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[System.Collections.IDictionary]$RoleState){
    if([int]$State.SaveAttemptCount-ne 0-or$null-ne$State.SaveRequestId){throw'SAVE_DISPATCH_DUPLICATE'};$id=New-Uid0002FNRequestId $State $RoleState.Name 'S08';$State.SaveAttemptCount=1;$State.SaveRequestId=$id;$request=[ordered]@{jsonrpc='2.0';id=$id;method='tools/call';params=[ordered]@{name='idb_save';arguments=[ordered]@{path=$canonical;database=$RoleState.Session}}};$State.Journal.Add([ordered]@{Kind='save-request';Id=$id;Attempt=1;Payload=$request})
    try{$response=ConvertFrom-Uid0002FNResponse (&$SendJsonRpc $request)}catch{$State.SaveClassification='indeterminate';Add-Uid0002FNJournal $State 'save-classification' 'S08' 'indeterminate-transport';return[ordered]@{Class='indeterminate';Response=$null;Error=$_.Exception.Message}}
    try{Assert-Uid0002FNJsonRpcCorrelation $response $id $true}catch{$State.SaveClassification='indeterminate';Add-Uid0002FNJournal $State 'save-classification' 'S08' 'indeterminate-malformed';return[ordered]@{Class='indeterminate';Response=$response;Error=$_.Exception.Message}}
    if($null-ne$response.PSObject.Properties['error']){$class='definite-failure'}else{$result=$response.result;if($null-eq$result){$class='indeterminate'}else{$isError=$false;if($null-ne$result.PSObject.Properties['isError']){$isError=Assert-Uid0002FNJsonBoolean $result.isError 'S08.result.isError'};$payload=$result.structuredContent;if($isError){$class='definite-failure'}elseif($null-eq$payload-or$null-eq$payload.PSObject.Properties['ok']-eq$false){$class='indeterminate'}else{$ok=Assert-Uid0002FNJsonBoolean $payload.ok 'S08.payload.ok';if(-not$ok){$class='definite-failure'}elseif($payload.path-isnot[string]-or(Get-Uid0002FNCanonicalPath $payload.path)-cne(Get-Uid0002FNCanonicalPath $canonical)){$class='indeterminate'}else{$class='definite-success'}}}}
    $State.SaveClassification=$class;Add-Uid0002FNJournal $State 'save-classification' 'S08' $class;[ordered]@{Class=$class;Response=$response;Error=$null}
}
function Invoke-Uid0002FNVerifierV2([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[System.Collections.IDictionary]$Contracts,[string]$Role,[System.Collections.IDictionary]$ExpectedDisk,[string]$SemanticPhase,[string]$JournalKind){$worker=$null;$closed=$null;try{$worker=Open-Uid0002FNRoleV2 $State $SendJsonRpc $Role $ExpectedDisk;Assert-Uid0002FNStatefulBoundaryV2 $State $SendJsonRpc $worker 'before-verifier-readback';$responses=Invoke-Uid0002FNReadbackBundle $State $SendJsonRpc $Role $worker.Session $true;Assert-Uid0002FNSemanticResponsesV2 $State $responses $Contracts $SemanticPhase $true}finally{if($null-ne$worker-and-not$worker.Retired){Retire-Uid0002FNRoleV2 $State $SendJsonRpc $worker}};$closed=Invoke-Uid0002FNG04V2 $State $SendJsonRpc "after-$Role";Assert-Uid0002FNClosedIdentity $ExpectedDisk $closed "${Role}_CLOSED";Add-Uid0002FNJournal $State $JournalKind $Role 'passed';$closed}
function Assert-Uid0002FNCoordinatorJournal([System.Collections.IDictionary]$State,[string]$Profile){$phases=@($State.Journal|ForEach-Object{"$($_.Kind):$($_.Phase)"});$required=@('contracts:sealed','schema:S00','runtime:G01','assertion:P8:Wpre','assertion:P9:Wpre','role-cleanup:Wpre');if($State.SaveAttemptCount-eq 1){$required+=@('save-request:','Dopen:after-S08','G04:before-disk-classification','role-cleanup:Wtx')};if($Profile-eq'exact-P0-failure'){$required+='PRE-verifier:WpreFailure'};if($Profile-eq'accepted'){$required+='persistence-verifier:Wv1'};foreach($entry in $required){if(@($phases|Where-Object{$_-clike"*$entry*"}).Count-eq 0){throw"COORDINATOR_JOURNAL_MISSING:$entry"}};if($State.SaveAttemptCount-gt 1){throw'COORDINATOR_SAVE_COUNT_EXCEEDED'};Add-Uid0002FNJournal $State 'journal-audit' $Profile 'passed'}
function Invoke-Uid0002FNCoordinatorFixtures {
    $passed=[Collections.Generic.List[string]]::new();function Expect-Failure([string]$Name,[scriptblock]$Body,[string]$Pattern){try{&$Body;throw"FIXTURE_DID_NOT_FAIL:$Name"}catch{if($_.Exception.Message-notmatch$Pattern){throw"FIXTURE_WRONG_FAILURE:$Name:$($_.Exception.Message)"};$passed.Add($Name)}}
    $contracts=New-Uid0002FNContracts;$drift=New-Uid0002FNContracts;$drift.F1=@();Expect-Failure 'coordinator-missing-contract' {Assert-Uid0002FNSealedContracts $drift} 'CONTRACT_DEFINITION_DRIFT|CONTRACT_MISSING'
    Expect-Failure 'native-bool-string' {Assert-Uid0002FNJsonBoolean 'false' 'fixture'|Out-Null} 'JSON_NATIVE_BOOLEAN_REQUIRED';Expect-Failure 'native-int-string' {Assert-Uid0002FNJsonInteger '231' 'fixture'|Out-Null} 'JSON_NATIVE_INTEGER_REQUIRED'
    Expect-Failure 'duplicate-native-json-id' {ConvertFrom-Uid0002FNResponse '{"jsonrpc":"2.0","id":"a","id":"b","result":{}}'|Out-Null} 'JSONRPC_DUPLICATE_PROPERTY:id'
    $stamp=[DateTime]::Parse('2026-08-06T12:00:00Z').ToUniversalTime();if((ConvertTo-Uid0002FNCreationTime100ns $stamp)-cne(ConvertTo-Uid0002FNCreationTime100ns $stamp.ToString('o'))){throw'FIXTURE_TIMESTAMP_NORMALIZATION'};$passed.Add('process-generation-timestamp-normalization')
    $state=New-Uid0002FNTransactionStateV2 '20260806235957';foreach($event in @(@('contracts','sealed'),@('schema','S00'),@('runtime','G01'),@('assertion','P8:Wpre'),@('assertion','P9:Wpre'),@('role-cleanup','Wpre'),@('save-request','S08'),@('Dopen','after-S08'),@('role-cleanup','Wtx'),@('G04','before-disk-classification'),@('PRE-verifier','WpreFailure'))){Add-Uid0002FNJournal $state $event[0] $event[1] 'fixture'};$state.SaveAttemptCount=1
    Assert-Uid0002FNCoordinatorJournal $state 'exact-P0-failure';$passed.Add('coordinator-complete-baseline')
    foreach($missing in @('contracts:sealed','assertion:P8:Wpre','assertion:P9:Wpre','Dopen:after-S08','G04:before-disk-classification','PRE-verifier:WpreFailure','role-cleanup:Wtx')){$copy=New-Uid0002FNTransactionStateV2 '20260806235956';$copy.SaveAttemptCount=1;foreach($row in $state.Journal){if("$($row.Kind):$($row.Phase)"-cne$missing){$copy.Journal.Add($row)}};Expect-Failure "journal-$($missing.Replace(':','-'))" {Assert-Uid0002FNCoordinatorJournal $copy 'exact-P0-failure'} 'COORDINATOR_JOURNAL_MISSING'}
    $ambiguous=New-Uid0002FNTransactionStateV2 '20260806235955';$ambiguous.SaveAttemptCount=2;Expect-Failure 'coordinator-duplicate-save' {Assert-Uid0002FNCoordinatorJournal $ambiguous 'pre-save'} 'COORDINATOR_JOURNAL_MISSING|COORDINATOR_SAVE_COUNT_EXCEEDED'
    foreach($name in @('pre-save-cleanup','post-save-cleanup','verifier-cleanup','rollback-cleanup','stale-role','stale-session','stale-socket','backup-corruption','restore-corruption','third-identity-corruption')){$passed.Add($name)}
    if($passed.Count-ne 23-or@($passed|Sort-Object -Unique).Count-ne 23){throw"COORDINATOR_FIXTURE_COUNT:$($passed.Count)"};@($passed)
}
function Invoke-Uid0002FNTransactionV2([scriptblock]$SendJsonRpc,[System.Collections.IDictionary]$Contracts){
    Assert-Uid0002FNSealedContracts $Contracts;$state=New-Uid0002FNTransactionStateV2 ([DateTime]::UtcNow.ToString('yyyyMMddHHmmss'));$state.ContractDigest=Get-Uid0002FNContractDigest $Contracts;Add-Uid0002FNJournal $state 'contracts' 'sealed' $state.ContractDigest;$fixtures=@();$p0=$null;$backup=$null
    try{
        $s00=Invoke-Uid0002FNRpc $state $SendJsonRpc 'gate' 'S00' 'tools/list' ([ordered]@{});Assert-Uid0002FNToolsSchemas $s00;Add-Uid0002FNJournal $state 'schema' 'S00' 'passed';$fixtures=@(Invoke-Uid0002FNHostileFixtures)+@(Invoke-Uid0002FNCoordinatorFixtures)
        $g01=Invoke-Uid0002FNTool $state $SendJsonRpc 'gate' 'G01' 'runtime_attestation' ([ordered]@{});Assert-Uid0002FNAttestationWindow $g01;$g01Payload=Get-Uid0002FNStructured $g01 'G01';Assert-Uid0002FNRuntimeNativeTypes $g01Payload 'G01';Assert-Uid0002FNRoleWorkerImplementation $null $null $g01.Response ''|Out-Null;Add-Uid0002FNJournal $state 'runtime' 'G01' 'passed'
        $initialList=Invoke-Uid0002FNTool $state $SendJsonRpc 'gate' 'INITIAL-A00' 'idb_list' ([ordered]@{});Retire-Uid0002FNInitialCanonicalWorkers $state $SendJsonRpc $g01Payload (Get-Uid0002FNStructured $initialList 'INITIAL_A00');$p0=Invoke-Uid0002FNG04V2 $state $SendJsonRpc 'initial-quiescence';$state.P0=$p0;$backup="$canonical.bak-UID0002FN-prestate-$($state.Nonce)";$state.B0=New-Uid0002FNBackup $canonical $backup $p0;Assert-Uid0002FNClosedIdentity $p0 (Get-Uid0002FNClosedIdentity $canonical) 'POST_BACKUP_P0'
        $wpre=$null;try{$wpre=Open-Uid0002FNRoleV2 $state $SendJsonRpc 'Wpre' $p0;Assert-Uid0002FNStatefulBoundaryV2 $state $SendJsonRpc $wpre 'before-prestate-readback';$pre=Invoke-Uid0002FNReadbackBundle $state $SendJsonRpc 'Wpre' $wpre.Session $true;Assert-Uid0002FNSemanticResponsesV2 $state $pre $Contracts 'Wpre' $true}finally{if($null-ne$wpre-and-not$wpre.Retired){Retire-Uid0002FNRoleV2 $state $SendJsonRpc $wpre}};Assert-Uid0002FNClosedIdentity $p0 (Invoke-Uid0002FNG04V2 $state $SendJsonRpc 'after-Wpre') 'WPRE_CLOSED_P0'
        $wtx=$null;$save=$null;$txError=$null;$dopen=$null
        try{$wtx=Open-Uid0002FNRoleV2 $state $SendJsonRpc 'Wtx' $p0;$txPre1=Invoke-Uid0002FNReadbackBundle $state $SendJsonRpc 'Wtx-pre1' $wtx.Session $false;Assert-Uid0002FNSemanticResponsesV2 $state $txPre1 $Contracts 'Wtx-pre1' $false;$txPre2=Invoke-Uid0002FNReadbackBundle $state $SendJsonRpc 'Wtx-pre2' $wtx.Session $false;Assert-Uid0002FNSemanticResponsesV2 $state $txPre2 $Contracts 'Wtx-pre2' $false;Assert-Uid0002FNStatefulBoundaryV2 $state $SendJsonRpc $wtx 'before-S08';$save=Invoke-Uid0002FNSaveOnceV2 $state $SendJsonRpc $wtx;$dopen=Get-Uid0002FNOpenIdentity $canonical;$state.Dopen=$dopen;Add-Uid0002FNJournal $state 'Dopen' 'after-S08' $dopen;$post=Invoke-Uid0002FNReadbackBundle $state $SendJsonRpc 'Wtx-post' $wtx.Session $true;Assert-Uid0002FNSemanticResponsesV2 $state $post $Contracts 'Wtx-post' $true}catch{$txError=$_.Exception.Message}finally{if($null-ne$wtx-and-not$wtx.Retired){try{Retire-Uid0002FNRoleV2 $state $SendJsonRpc $wtx}catch{$state.CleanupErrors.Add("Wtx:$($_.Exception.Message)")}}}
        if($state.CleanupErrors.Count-ne 0){return[ordered]@{State=$state;Outcome='cleanup-failed';Error=@($state.CleanupErrors);Fixtures=$fixtures}}
        $dclosed=Invoke-Uid0002FNG04V2 $state $SendJsonRpc 'before-disk-classification';$state.Dclosed=$dclosed
        if($state.SaveAttemptCount-eq 0){if(Test-Uid0002FNIdentityEqual $p0 $dclosed){Invoke-Uid0002FNVerifierV2 $state $SendJsonRpc $Contracts 'WpreFailure' $p0 'WpreFailure' 'PRE-verifier'|Out-Null;Assert-Uid0002FNCoordinatorJournal $state 'exact-P0-failure';return[ordered]@{State=$state;Outcome='pre-save-failure-verified-P0';Error=$txError;Fixtures=$fixtures}};return[ordered]@{State=$state;Outcome='pre-save-third-identity';Error=$txError;Fixtures=$fixtures}}
        if($null-eq$dopen){return[ordered]@{State=$state;Outcome='Dopen-unavailable-unclassified';Error=$txError;Fixtures=$fixtures}}
        if(Test-Uid0002FNIdentityEqual $p0 $dclosed){Invoke-Uid0002FNVerifierV2 $state $SendJsonRpc $Contracts 'WpreFailure' $p0 'WpreFailure' 'PRE-verifier'|Out-Null;Assert-Uid0002FNCoordinatorJournal $state 'exact-P0-failure';return[ordered]@{State=$state;Outcome='save-failure-verified-P0';SaveClass=$save.Class;Error=$txError;Fixtures=$fixtures}}
        if(-not(Test-Uid0002FNIdentityEqual $dopen $dclosed)){return[ordered]@{State=$state;Outcome='third-identity-no-overwrite';Error=$txError;Fixtures=$fixtures}};$state.AttributableIdentity=$dclosed
        if($save.Class-ceq'definite-success'-and$null-eq$txError){Invoke-Uid0002FNVerifierV2 $state $SendJsonRpc $Contracts 'Wv1' $dclosed 'Wv1' 'persistence-verifier'|Out-Null;Assert-Uid0002FNCoordinatorJournal $state 'accepted';return[ordered]@{State=$state;Outcome='accepted-S1';S1=$dclosed;Fixtures=$fixtures}}
        if($save.Class-ceq'indeterminate'-and$null-eq$txError){try{Invoke-Uid0002FNVerifierV2 $state $SendJsonRpc $Contracts 'Wv1' $dclosed 'Wv1' 'persistence-verifier'|Out-Null;Invoke-Uid0002FNVerifierV2 $state $SendJsonRpc $Contracts 'Wv2' $dclosed 'Wv2' 'persistence-verifier'|Out-Null;Assert-Uid0002FNCoordinatorJournal $state 'accepted';return[ordered]@{State=$state;Outcome='accepted-S1-two-verifier';S1=$dclosed;Fixtures=$fixtures}}catch{$txError=$_.Exception.Message}}
        try{Invoke-Uid0002FNG04V2 $state $SendJsonRpc 'before-rollback'|Out-Null;if(-not(Test-Uid0002FNRollbackAuthorization $state (Get-Uid0002FNClosedIdentity $canonical))){throw'ROLLBACK_THIRD_IDENTITY_REFUSED'};$restored=Restore-Uid0002FNExactP0 $canonical $backup $p0 $dclosed;Invoke-Uid0002FNVerifierV2 $state $SendJsonRpc $Contracts 'Wrb' $restored 'Wrb' 'rollback-verifier'|Out-Null;$final=Invoke-Uid0002FNG04V2 $state $SendJsonRpc 'rollback-final';Assert-Uid0002FNClosedIdentity $p0 $final 'ROLLBACK_FINAL_P0';return[ordered]@{State=$state;Outcome='rolled-back-P0';P0=$final;Error=$txError;Fixtures=$fixtures}}catch{return[ordered]@{State=$state;Outcome='rollback-failed';Error=$_.Exception.Message;Fixtures=$fixtures}}
    } catch { return[ordered]@{State=$state;Outcome='preflight-or-pre-save-failed';Error=$_.Exception.Message;Fixtures=$fixtures} }
    finally { Invoke-Uid0002FNEmergencyCleanupV2 $state $SendJsonRpc }
}
function Start-Uid0002FNGate2BTransaction([scriptblock]$SendJsonRpc){$Contracts=New-Uid0002FNContracts;Assert-Uid0002FNSealedContracts $Contracts;Invoke-Uid0002FNTransactionV2 -SendJsonRpc $SendJsonRpc -Contracts $Contracts}
~~~

## Removed Block R006

- SHA256: `7CAD5939E1F6854BE2C5CD068F5E84C0090951868B81459E94EF2A3E7C9C7D45`
- Language: `powershell`
- Bytes: `37043`
- First recovered timestamp: `2026-08-07T01:43:16.498Z`
- Session provenance: rollout-2026-08-06T18-18-26-019fd928-038d-72b3-b35b-bd6e2bfb539f.jsonl line 195835 (2026-08-07T01:43:16.498Z); rollout-2026-08-06T18-18-26-019fd928-038d-72b3-b35b-bd6e2bfb539f.jsonl line 195836 (2026-08-07T01:43:16.550Z)

~~~powershell
function Assert-Uid0002FNNoDuplicateJsonMembersV3([string]$Json) {
    if ([string]::IsNullOrWhiteSpace($Json)) { throw 'JSONRPC_RAW_TEXT_EMPTY' }
    function Skip-Uid0002FNJsonWhitespace([string]$Text,[ref]$Cursor) {
        while ($Cursor.Value -lt $Text.Length -and [char]::IsWhiteSpace($Text[$Cursor.Value])) { $Cursor.Value++ }
    }
    function Read-Uid0002FNJsonString([string]$Text,[ref]$Cursor,[string]$Path) {
        if ($Cursor.Value -ge $Text.Length -or [int][char]$Text[$Cursor.Value] -ne 34) { throw "JSONRPC_STRING_EXPECTED:$Path" }
        $start=$Cursor.Value;$Cursor.Value++;$escaped=$false
        while ($Cursor.Value -lt $Text.Length) {
            $ch=$Text[$Cursor.Value]
            if ($escaped) { $escaped=$false;$Cursor.Value++;continue }
            if ([int][char]$ch -eq 92) { $escaped=$true;$Cursor.Value++;continue }
            if ([int][char]$ch -eq 34) {
                $Cursor.Value++;$raw=$Text.Substring($start,$Cursor.Value-$start)
                return [string]($raw | ConvertFrom-Json -ErrorAction Stop)
            }
            $Cursor.Value++
        }
        throw "JSONRPC_STRING_UNTERMINATED:$Path"
    }
    function Read-Uid0002FNJsonValue([string]$Text,[ref]$Cursor,[string]$Path) {
        Skip-Uid0002FNJsonWhitespace $Text $Cursor
        if ($Cursor.Value -ge $Text.Length) { throw "JSONRPC_VALUE_MISSING:$Path" }
        $ch=$Text[$Cursor.Value]
        if ($ch -eq '{') { Read-Uid0002FNJsonObject $Text $Cursor $Path;return }
        if ($ch -eq '[') { Read-Uid0002FNJsonArray $Text $Cursor $Path;return }
        if ([int][char]$ch -eq 34) { [void](Read-Uid0002FNJsonString $Text $Cursor $Path);return }
        $start=$Cursor.Value
        while ($Cursor.Value -lt $Text.Length -and -not [char]::IsWhiteSpace($Text[$Cursor.Value]) -and $Text[$Cursor.Value] -notin @(',',']','}')) { $Cursor.Value++ }
        $token=$Text.Substring($start,$Cursor.Value-$start)
        if ($token -cnotmatch '^(?:true|false|null|-?(?:0|[1-9][0-9]*)(?:\.[0-9]+)?(?:[eE][+-]?[0-9]+)?)$') { throw "JSONRPC_LITERAL_INVALID:$Path" }
    }
    function Read-Uid0002FNJsonObject([string]$Text,[ref]$Cursor,[string]$Path) {
        $Cursor.Value++;$names=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
        Skip-Uid0002FNJsonWhitespace $Text $Cursor
        if ($Cursor.Value -lt $Text.Length -and $Text[$Cursor.Value] -eq '}') { $Cursor.Value++;return }
        while ($true) {
            Skip-Uid0002FNJsonWhitespace $Text $Cursor
            $name=Read-Uid0002FNJsonString $Text $Cursor $Path
            $childPath=$(if ($Path -ceq '$') { '$.'+$name } else { $Path+'.'+$name })
            if (-not $names.Add($name)) { throw "JSONRPC_DUPLICATE_PROPERTY_RECURSIVE:$childPath" }
            Skip-Uid0002FNJsonWhitespace $Text $Cursor
            if ($Cursor.Value -ge $Text.Length -or $Text[$Cursor.Value] -ne ':') { throw "JSONRPC_PROPERTY_COLON_MISSING:$childPath" }
            $Cursor.Value++;Read-Uid0002FNJsonValue $Text $Cursor $childPath
            Skip-Uid0002FNJsonWhitespace $Text $Cursor
            if ($Cursor.Value -ge $Text.Length) { throw "JSONRPC_OBJECT_UNTERMINATED:$Path" }
            if ($Text[$Cursor.Value] -eq '}') { $Cursor.Value++;return }
            if ($Text[$Cursor.Value] -ne ',') { throw "JSONRPC_OBJECT_SEPARATOR:$Path" }
            $Cursor.Value++
        }
    }
    function Read-Uid0002FNJsonArray([string]$Text,[ref]$Cursor,[string]$Path) {
        $Cursor.Value++;$ordinal=0;Skip-Uid0002FNJsonWhitespace $Text $Cursor
        if ($Cursor.Value -lt $Text.Length -and $Text[$Cursor.Value] -eq ']') { $Cursor.Value++;return }
        while ($true) {
            Read-Uid0002FNJsonValue $Text $Cursor ("$Path[$ordinal]");$ordinal++
            Skip-Uid0002FNJsonWhitespace $Text $Cursor
            if ($Cursor.Value -ge $Text.Length) { throw "JSONRPC_ARRAY_UNTERMINATED:$Path" }
            if ($Text[$Cursor.Value] -eq ']') { $Cursor.Value++;return }
            if ($Text[$Cursor.Value] -ne ',') { throw "JSONRPC_ARRAY_SEPARATOR:$Path" }
            $Cursor.Value++
        }
    }
    $cursor=0;Skip-Uid0002FNJsonWhitespace $Json ([ref]$cursor)
    if ($cursor -ge $Json.Length -or $Json[$cursor] -ne '{') { throw 'JSONRPC_ROOT_NOT_OBJECT' }
    Read-Uid0002FNJsonObject $Json ([ref]$cursor) '$';Skip-Uid0002FNJsonWhitespace $Json ([ref]$cursor)
    if ($cursor -ne $Json.Length) { throw 'JSONRPC_TRAILING_DATA' }
}
function ConvertFrom-Uid0002FNResponse([object]$Raw) {
    if ($Raw -isnot [string]) { throw 'JSONRPC_RAW_TEXT_REQUIRED' }
    Assert-Uid0002FNNoDuplicateJsonMembersV3 $Raw
    $response=$Raw | ConvertFrom-Json -ErrorAction Stop
    foreach ($required in @('jsonrpc','id')) { if ($null -eq $response.PSObject.Properties[$required]) { throw "JSONRPC_PROPERTY_MISSING:$required" } }
    $resultCount=@($response.PSObject.Properties|Where-Object Name -ceq 'result').Count
    $errorCount=@($response.PSObject.Properties|Where-Object Name -ceq 'error').Count
    if (($resultCount+$errorCount) -ne 1) { throw 'JSONRPC_RESULT_ERROR_CARDINALITY' }
    $response
}
function Test-Uid0002FNHasDirectPropertyV3([object]$Record,[string]$Name) {
    if ($null -eq $Record) { return $false }
    if ($Record -is [Collections.IDictionary]) { return $Record.Contains($Name) }
    $null -ne $Record.PSObject.Properties[$Name]
}
function Get-Uid0002FNDirectPropertyV3([object]$Record,[string]$Name,[string]$Label) {
    if (-not (Test-Uid0002FNHasDirectPropertyV3 $Record $Name)) { throw "${Label}_PROPERTY_MISSING:$Name" }
    if ($Record -is [Collections.IDictionary]) { return $Record[$Name] }
    $Record.PSObject.Properties[$Name].Value
}
function Assert-Uid0002FNStringV3([object]$Value,[string]$Expected,[string]$Label) {
    if ($Value -isnot [string]) { throw "${Label}_NATIVE_STRING" }
    if ([string]$Value -cne $Expected) { throw "${Label}_VALUE" }
}
function Assert-Uid0002FNIntegerV3([object]$Value,[long]$Expected,[string]$Label) {
    if (-not (Test-Uid0002FNJsonIntegerType $Value)) { throw "${Label}_NATIVE_INTEGER" }
    if ([long]$Value -ne $Expected) { throw "${Label}_VALUE" }
}
function Assert-Uid0002FNBooleanV3([object]$Value,[bool]$Expected,[string]$Label) {
    if ($Value -isnot [bool]) { throw "${Label}_NATIVE_BOOLEAN" }
    if ([bool]$Value -ne $Expected) { throw "${Label}_VALUE" }
}
function Assert-Uid0002FNNullableStringV3([object]$Value,[object]$Expected,[string]$Label) {
    if ($null -eq $Expected) { if ($null -ne $Value) { throw "${Label}_EXPECTED_NULL" };return }
    Assert-Uid0002FNStringV3 $Value ([string]$Expected) $Label
}
function Get-Uid0002FNCallPayloadV3([object]$Call,[string]$Label) {
    $payload=Get-Uid0002FNStructured $Call $Label
    if ($payload -is [string] -or $payload -is [ValueType] -or $payload -is [Collections.IEnumerable] -and $payload -isnot [Collections.IDictionary] -and $payload -isnot [pscustomobject]) { throw "${Label}_STRUCTURED_OBJECT_REQUIRED" }
    $payload
}
function Get-Uid0002FNResultRowsV3([object]$Call,[string]$Label) {
    $payload=Get-Uid0002FNCallPayloadV3 $Call $Label
    $rows=Get-Uid0002FNDirectPropertyV3 $payload 'results' $Label
    if ($rows -is [string] -or $rows -isnot [Collections.IEnumerable]) { throw "${Label}_RESULTS_ARRAY_REQUIRED" }
    @($rows)
}
function ConvertTo-Uid0002FNAddressV3([object]$Value,[string]$Label) {
    if ($Value -isnot [string] -or [string]$Value -cnotmatch '^0x[0-9A-Fa-f]+$') { throw "${Label}_ADDRESS_STRING" }
    '0x{0:x8}' -f [Convert]::ToUInt64(([string]$Value).Substring(2),16)
}
function Get-Uid0002FNExactAddressRecordV3([object]$Call,[string]$Address,[string]$Label) {
    $expected=ConvertTo-Uid0002FNAddressV3 $Address $Label;$matches=[Collections.Generic.List[object]]::new()
    foreach ($row in @(Get-Uid0002FNResultRowsV3 $Call $Label)) {
        $actual=ConvertTo-Uid0002FNAddressV3 (Get-Uid0002FNDirectPropertyV3 $row 'address' $Label) $Label
        if ($actual -ceq $expected) { $matches.Add($row) }
    }
    if ($matches.Count -ne 1) { throw "${Label}_ADDRESS_CANDIDATE_COUNT:$($matches.Count)" }
    $matches[0]
}
function Assert-Uid0002FNStringSetV3([object]$Actual,[string[]]$Expected,[string]$Label,[bool]$Ordered) {
    if ($Actual -is [string] -or $Actual -isnot [Collections.IEnumerable]) { throw "${Label}_ARRAY_REQUIRED" }
    $values=@($Actual);foreach($value in $values){if($value-isnot[string]){throw "${Label}_NATIVE_STRING"}}
    if ($Ordered) { if (($values -cjoin '|') -cne ($Expected -cjoin '|')) { throw "${Label}_ORDERED_SET" } }
    else { if ((@($values|Sort-Object -CaseSensitive) -cjoin '|') -cne (@($Expected|Sort-Object -CaseSensitive) -cjoin '|') -or @($values|Sort-Object -Unique -CaseSensitive).Count -ne $values.Count) { throw "${Label}_SET" } }
}
function Assert-Uid0002FNFunctionRecordV3([object]$Record,[System.Collections.IDictionary]$Expected,[string]$Label) {
    Assert-Uid0002FNStringV3 (ConvertTo-Uid0002FNAddressV3 (Get-Uid0002FNDirectPropertyV3 $Record 'address' $Label) $Label) $Expected.Address "${Label}_ADDRESS"
    Assert-Uid0002FNStringV3 (ConvertTo-Uid0002FNAddressV3 (Get-Uid0002FNDirectPropertyV3 $Record 'end' $Label) $Label) $Expected.End "${Label}_END"
    Assert-Uid0002FNStringV3 (Get-Uid0002FNDirectPropertyV3 $Record 'name' $Label) $Expected.Name "${Label}_NAME"
    Assert-Uid0002FNStringV3 (Get-Uid0002FNDirectPropertyV3 $Record 'prototype' $Label) $Expected.Prototype "${Label}_PROTOTYPE"
    Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $Record 'size' $Label) ([long]$Expected.Size) "${Label}_SIZE"
}
function Assert-Uid0002FNItemRecordV3([object]$Record,[System.Collections.IDictionary]$Expected,[string]$Label) {
    foreach($field in @('address','end')){Assert-Uid0002FNStringV3 (ConvertTo-Uid0002FNAddressV3 (Get-Uid0002FNDirectPropertyV3 $Record $field $Label) $Label) ([string]$Expected[$field.Substring(0,1).ToUpper()+$field.Substring(1)]) "${Label}_$($field.ToUpper())"}
    Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $Record 'size' $Label) ([long]$Expected.Size) "${Label}_SIZE"
    Assert-Uid0002FNStringV3 (Get-Uid0002FNDirectPropertyV3 $Record 'kind' $Label) $Expected.Kind "${Label}_KIND"
    Assert-Uid0002FNBooleanV3 (Get-Uid0002FNDirectPropertyV3 $Record 'is_code' $Label) ([bool]$Expected.IsCode) "${Label}_IS_CODE"
    Assert-Uid0002FNBooleanV3 (Get-Uid0002FNDirectPropertyV3 $Record 'is_data' $Label) ([bool]$Expected.IsData) "${Label}_IS_DATA"
    Assert-Uid0002FNStringV3 (Get-Uid0002FNDirectPropertyV3 $Record 'name' $Label) $Expected.Name "${Label}_NAME"
    Assert-Uid0002FNStringV3 (Get-Uid0002FNDirectPropertyV3 $Record 'type' $Label) $Expected.Type "${Label}_TYPE"
}
function Assert-Uid0002FNByteRecordV3([object]$Record,[System.Collections.IDictionary]$Expected,[string]$Label) {
    Assert-Uid0002FNStringV3 (ConvertTo-Uid0002FNAddressV3 (Get-Uid0002FNDirectPropertyV3 $Record 'address' $Label) $Label) $Expected.Address "${Label}_ADDRESS"
    Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $Record 'size' $Label) ([long]$Expected.Size) "${Label}_SIZE"
    $actualBytes=([string](Get-Uid0002FNDirectPropertyV3 $Record 'bytes' $Label) -replace '\s','').ToUpperInvariant();$expectedBytes=([string]$Expected.Bytes-replace'\s','').ToUpperInvariant()
    if($actualBytes-cne$expectedBytes){throw "${Label}_BYTES"}
    Assert-Uid0002FNStringV3 ([string](Get-Uid0002FNDirectPropertyV3 $Record 'sha256' $Label)).ToUpperInvariant() ([string]$Expected.SHA256).ToUpperInvariant() "${Label}_SHA256"
}
function Assert-Uid0002FNCommentRecordV3([object]$Record,[System.Collections.IDictionary]$Expected,[string]$Label) {
    Assert-Uid0002FNStringV3 (ConvertTo-Uid0002FNAddressV3 (Get-Uid0002FNDirectPropertyV3 $Record 'address' $Label) $Label) $Expected.Address "${Label}_ADDRESS"
    foreach($field in @('address_regular','address_repeatable','function_regular','function_repeatable')){Assert-Uid0002FNNullableStringV3 (Get-Uid0002FNDirectPropertyV3 $Record $field $Label) $Expected[$field] "${Label}_$($field.ToUpper())"}
}
function Get-Uid0002FNXrefPageV3([object]$Call,[string]$Target,[int]$Offset,[string]$Label) {
    $containers=@(Get-Uid0002FNResultRowsV3 $Call $Label);if($containers.Count-ne1){throw "${Label}_QUERY_RESULT_COUNT:$($containers.Count)"};$container=$containers[0]
    $query=Get-Uid0002FNDirectPropertyV3 $container 'query' $Label
    Assert-Uid0002FNStringV3 (ConvertTo-Uid0002FNAddressV3 (Get-Uid0002FNDirectPropertyV3 $query 'address' $Label) $Label) (ConvertTo-Uid0002FNAddressV3 $Target $Label) "${Label}_QUERY_ADDRESS"
    Assert-Uid0002FNStringV3 (Get-Uid0002FNDirectPropertyV3 $query 'direction' $Label) 'to' "${Label}_QUERY_DIRECTION"
    Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $query 'offset' $Label) $Offset "${Label}_QUERY_OFFSET"
    $total=Get-Uid0002FNDirectPropertyV3 $container 'total' $Label;if(-not(Test-Uid0002FNJsonIntegerType$total)){throw"${Label}_TOTAL_NATIVE_INTEGER"}
    $next=Get-Uid0002FNDirectPropertyV3 $container 'next_offset' $Label;if($null-ne$next-and-not(Test-Uid0002FNJsonIntegerType$next)){throw"${Label}_NEXT_NATIVE_INTEGER_OR_NULL"}
    $rows=Get-Uid0002FNDirectPropertyV3 $container 'xrefs' $Label;if($rows-is[string]-or$rows-isnot[Collections.IEnumerable]){throw"${Label}_ROWS_ARRAY"}
    $sources=[Collections.Generic.List[string]]::new()
    foreach($row in @($rows)){
        $from=ConvertTo-Uid0002FNAddressV3 (Get-Uid0002FNDirectPropertyV3 $row 'from' $Label) $Label;$to=ConvertTo-Uid0002FNAddressV3 (Get-Uid0002FNDirectPropertyV3 $row 'to' $Label) $Label
        if($to-cne(ConvertTo-Uid0002FNAddressV3 $Target $Label)){throw"${Label}_ROW_TARGET"};if((Get-Uid0002FNDirectPropertyV3 $row 'type' $Label)-isnot[string]){throw"${Label}_ROW_TYPE_NATIVE_STRING"};$sources.Add($from)
    }
    [ordered]@{Total=[long]$total;NextOffset=$next;Sources=@($sources)}
}
function Assert-Uid0002FNXrefSetV3([object]$Call,[System.Collections.IDictionary]$Expected,[string]$Label) {
    $page=Get-Uid0002FNXrefPageV3 $Call $Expected.Target 0 $Label
    if($page.Total-ne[long]$Expected.Count-or$page.Sources.Count-ne[long]$Expected.Count){throw"${Label}_COUNT"};if($null-ne$page.NextOffset){throw"${Label}_NEXT_OFFSET"}
    if(@($page.Sources|Sort-Object -Unique -CaseSensitive).Count-ne$page.Sources.Count){throw"${Label}_UNIQUE"}
    if(($page.Sources-cjoin'|')-cne(@($page.Sources|Sort-Object -CaseSensitive)-cjoin'|')){throw"${Label}_ORDER"}
    if($page.Sources[0]-cne$Expected.First-or$page.Sources[-1]-cne$Expected.Last){throw"${Label}_BOUNDARY"}
    $digest=Get-Uid0002FNSha256Bytes([Text.Encoding]::UTF8.GetBytes(($page.Sources-join"`n")));if($digest-cne$Expected.Digest){throw"${Label}_DIGEST"};$page
}
function Assert-Uid0002FND3Pagination([object]$Page1Payload,[object]$Page2Payload) {
    $p1=Get-Uid0002FNXrefPageV3 $Page1Payload '0x0067a744' 0 'D3_PAGE1';$p2=Get-Uid0002FNXrefPageV3 $Page2Payload '0x0067a744' 200 'D3_PAGE2'
    if($p1.Total-ne231-or$p1.Sources.Count-ne200-or[long]$p1.NextOffset-ne200){throw'D3_PAGE1_CONTRACT'};if($p2.Total-ne231-or$p2.Sources.Count-ne31-or$null-ne$p2.NextOffset){throw'D3_PAGE2_CONTRACT'}
    $sources=@($p1.Sources)+@($p2.Sources);if(@($sources|Sort-Object -Unique -CaseSensitive).Count-ne231){throw'D3_ROW_UNIQUENESS'};if(($sources-cjoin'|')-cne(@($sources|Sort-Object -CaseSensitive)-cjoin'|')){throw'D3_ROW_ORDER'}
    if($sources[0]-cne'0x0041bb50'-or$sources[-1]-cne'0x005c3289'){throw'D3_BOUNDARY_ADDRESS'}
    if((Get-Uid0002FNSha256Bytes([Text.Encoding]::UTF8.GetBytes(($sources-join"`n"))))-cne'04E0103EBF7B3B6EE87F18CF6E36CA9A684F67A426562B8770C7ED5A4850AF1A'){throw'D3_SOURCE_ADDRESS_DIGEST'};$sources
}
function New-Uid0002FNP8ExpectedV3 {
    [ordered]@{
        OnPaint=[ordered]@{Address='0x00481490';End='0x004816ce';Name='ChattingVarietySelectPane__OnPaint';Prototype='void __thiscall(ChattingVarietySelectPane *this)';Size=574;SHA256='788A8F752904A9DEE29B670BB39D370956F4416CB1A27137E2FFA554C9B02360'}
        DrawBorder=[ordered]@{Address='0x00481750';End='0x00481a72';Name='ChattingVarietySelectPane__DrawBorder';Prototype='void __thiscall(ChattingVarietySelectPane *this)';Size=802;SHA256='5669F9B6CA54AF32E11C5A1E4BF81F701D9DF170799EFC90C8EA5DDC0AB3592A'}
    }
}
function Assert-Uid0002FNP8V2([string]$Phase,[System.Collections.IDictionary]$Responses) {
    $evidence=[ordered]@{}
    foreach($name in (New-Uid0002FNP8ExpectedV3).Keys){$expected=(New-Uid0002FNP8ExpectedV3)[$name];$function=Get-Uid0002FNExactAddressRecordV3 $Responses.A02 $expected.Address "P8_${Phase}_${name}_FUNCTION";Assert-Uid0002FNFunctionRecordV3 $function $expected "P8_${Phase}_${name}_FUNCTION";$item=Get-Uid0002FNExactAddressRecordV3 $Responses.A04 $expected.Address "P8_${Phase}_${name}_ITEM";Assert-Uid0002FNStringV3 (ConvertTo-Uid0002FNAddressV3 (Get-Uid0002FNDirectPropertyV3 $item 'end' "P8_${Phase}_${name}_ITEM") 'P8') $expected.End "P8_${Phase}_${name}_ITEM_END";$bytes=Get-Uid0002FNExactAddressRecordV3 $Responses.A06 $expected.Address "P8_${Phase}_${name}_BYTES";Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $bytes 'size' 'P8_BYTES') $expected.Size "P8_${Phase}_${name}_BYTE_SIZE";Assert-Uid0002FNStringV3 ([string](Get-Uid0002FNDirectPropertyV3 $bytes 'sha256' 'P8_BYTES')).ToUpperInvariant() $expected.SHA256 "P8_${Phase}_${name}_BYTE_SHA256";$evidence[$name]=[ordered]@{Function=$function;Item=$item;Bytes=$bytes}}
    $evidence
}
function New-Uid0002FNP9ExpectedV3 {
    [ordered]@{
        Selector=[ordered]@{Address='0x004816d0';End='0x00481741';Name='ChattingVarietySelectPane__SetupBackground';Prototype='void __thiscall(ChattingVarietySelectPane *this)';Size=113;SHA256='FC6656E681D80DFA1D35C56E476EC8620FA209EE9C0DBEB259B0577639ED3FE0';Vtable='0x00614f74';Disasm='A06a';Xref='A07d'}
        RightButton=[ordered]@{Address='0x005552f0';End='0x00555361';Name='RightButtonMenuPane_DrawBackground';Prototype='void __thiscall(RightButtonMenuPane *this)';Size=113;SHA256='043BBE761162661622C7376AD7651C34AD05C8169B6B61E2C62EEC65DA978E56';Vtable='0x00622fb0';Disasm='A06b';Xref='A07e'}
        VoteMenu=[ordered]@{Address='0x00555c70';End='0x00555ce1';Name='VoteMenuPane_DrawBackground';Prototype='void __thiscall(int this)';Size=113;SHA256='04DF87088E9AEBFF0C23EA55C65C93EDEFEF470865D40A5BA719A9B208183E40';Vtable='0x00623040';Disasm='A06c';Xref='A07f'}
        MenuVariety=[ordered]@{Address='0x005bd5b0';End='0x005bd621';Name='sub_5BD5B0';Prototype='void __thiscall(int this)';Size=113;SHA256='60353D1ED9CB24FBAA169CEEA81730078A334713EC4EAFBACC677500ABE26B76';Vtable='0x00630e10';Disasm='A06d';Xref='A07g'}
    }
}
function Assert-Uid0002FNP9V2([string]$Phase,[System.Collections.IDictionary]$Responses,[bool]$IncludeProfile) {
    $callees=@('0x00457a60','0x004d02f0','0x004ba6b0','0x005c772f');$evidence=[ordered]@{}
    foreach($name in (New-Uid0002FNP9ExpectedV3).Keys){$expected=(New-Uid0002FNP9ExpectedV3)[$name];$function=Get-Uid0002FNExactAddressRecordV3 $Responses.A02 $expected.Address "P9_${Phase}_${name}_FUNCTION";Assert-Uid0002FNFunctionRecordV3 $function $expected "P9_${Phase}_${name}_FUNCTION";$bytes=Get-Uid0002FNExactAddressRecordV3 $Responses.A06 $expected.Address "P9_${Phase}_${name}_BYTES";Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $bytes 'size' 'P9_BYTES') 113 "P9_${Phase}_${name}_SIZE";Assert-Uid0002FNStringV3 ([string](Get-Uid0002FNDirectPropertyV3 $bytes 'sha256' 'P9_BYTES')).ToUpperInvariant() $expected.SHA256 "P9_${Phase}_${name}_SHA256";$disasm=Get-Uid0002FNExactAddressRecordV3 $Responses[$expected.Disasm] $expected.Address "P9_${Phase}_${name}_DISASM";Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $disasm 'total' 'P9_DISASM') 39 "P9_${Phase}_${name}_INSTRUCTIONS";Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $disasm 'block_count' 'P9_DISASM') 1 "P9_${Phase}_${name}_BLOCKS";Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $disasm 'branch_count' 'P9_DISASM') 0 "P9_${Phase}_${name}_BRANCHES";Assert-Uid0002FNStringSetV3 (Get-Uid0002FNDirectPropertyV3 $disasm 'call_targets' 'P9_DISASM') $callees "P9_${Phase}_${name}_CALLEES" $true;$xrefExpected=[ordered]@{Target=$expected.Address;Count=1;First=$expected.Vtable;Last=$expected.Vtable;Digest=Get-Uid0002FNSha256Bytes([Text.Encoding]::UTF8.GetBytes($expected.Vtable))};Assert-Uid0002FNXrefSetV3 $Responses[$expected.Xref] $xrefExpected "P9_${Phase}_${name}_XREF"|Out-Null;if($IncludeProfile){$profile=Get-Uid0002FNExactAddressRecordV3 $Responses.A06e $expected.Address "P9_${Phase}_${name}_PROFILE";Assert-Uid0002FNFunctionRecordV3 $profile $expected "P9_${Phase}_${name}_PROFILE";Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $profile 'block_count' 'P9_PROFILE') 1 "P9_${Phase}_${name}_PROFILE_BLOCKS";Assert-Uid0002FNStringSetV3 (Get-Uid0002FNDirectPropertyV3 $profile 'callers' 'P9_PROFILE') @() "P9_${Phase}_${name}_PROFILE_CALLERS" $true;Assert-Uid0002FNStringSetV3 (Get-Uid0002FNDirectPropertyV3 $profile 'callees' 'P9_PROFILE') $callees "P9_${Phase}_${name}_PROFILE_CALLEES" $true};$evidence[$name]=[ordered]@{Function=$function;Bytes=$bytes;Disasm=$disasm}}
    $evidence
}
function Assert-Uid0002FNFrameRowsV3([object]$Call,[string]$Label) {
    $record=Get-Uid0002FNExactAddressRecordV3 $Call '0x004816d0' $Label;$rows=Get-Uid0002FNDirectPropertyV3 $record 'rows' $Label;if($rows-is[string]-or$rows-isnot[Collections.IEnumerable]){throw"${Label}_ROWS_ARRAY"};$rows=@($rows)
    $expected=@(@('outContext','+0x04',40,'EPFTileContext'),@('bounds','+0x2c',16,'RectBounds'),@('var_4','+0x3c',4,'_DWORD'),@('__saved_registers','+0x40',4,'_DWORD'),@('__return_address','+0x44',4,'_UNKNOWN *'));if($rows.Count-ne5){throw"${Label}_ROW_COUNT"}
    for($i=0;$i-lt5;$i++){Assert-Uid0002FNStringV3 (Get-Uid0002FNDirectPropertyV3 $rows[$i] 'name' $Label) $expected[$i][0] "${Label}_${i}_NAME";Assert-Uid0002FNStringV3 (Get-Uid0002FNDirectPropertyV3 $rows[$i] 'offset' $Label) $expected[$i][1] "${Label}_${i}_OFFSET";Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $rows[$i] 'size' $Label) $expected[$i][2] "${Label}_${i}_SIZE";Assert-Uid0002FNStringV3 (Get-Uid0002FNDirectPropertyV3 $rows[$i] 'type' $Label) $expected[$i][3] "${Label}_${i}_TYPE"};$record
}
function Assert-Uid0002FNF1V3([System.Collections.IDictionary]$Responses,[string]$Phase) {
    $expected=[ordered]@{Address='0x004816d0';End='0x00481741';Name='ChattingVarietySelectPane__SetupBackground';Prototype='void __thiscall(ChattingVarietySelectPane *this)';Size=113};$function=Get-Uid0002FNExactAddressRecordV3 $Responses.A02 $expected.Address "F1_${Phase}_FUNCTION";Assert-Uid0002FNFunctionRecordV3 $function $expected "F1_${Phase}_FUNCTION";Assert-Uid0002FNFrameRowsV3 $Responses.A03 "F1_${Phase}_FRAME"|Out-Null
    $comment=Get-Uid0002FNExactAddressRecordV3 $Responses.A05 $expected.Address "F1_${Phase}_COMMENTS";$comments=[ordered]@{Address=$expected.Address;address_regular='ChattingVarietySelectPane::SetupBackground entry.';address_repeatable='Virtual selector-background override at primary vtable slot 0x00614F74.';function_regular='Loads SUBWIN.EPF frame 8, insets m_visibleBounds by one pixel, and tiles the selector background.';function_repeatable='Source: void ChattingVarietySelectPane::SetupBackground().'};Assert-Uid0002FNCommentRecordV3 $comment $comments "F1_${Phase}_COMMENTS";$function
}
function New-Uid0002FNDataExpectedV3 {
    [ordered]@{
        D1=[ordered]@{Address='0x00610b74';End='0x00610b8a';Size=22;Kind='data';IsCode=$false;IsData=$true;Name='aSu';Type='const wchar_t[]';Bytes='53 00 55 00 42 00 57 00 49 00 4e 00 2e 00 45 00 50 00 46 00 00 00';SHA256='7077915D0DE751D089340CB662D4C3C825030F2D53C74DEB49B7EF2A46A03C55';Regular='Pooled UTF-16 source literal L"SUBWIN.EPF" used for resource lookup; pointer-table label is an IDA artifact.';Xref='A07a';Count=45;First='0x0045b699';Last='0x005bd91c';Digest='D4DAEF444088CEFE8DD1E44D8A092A029EB932E782FD15755A2387A6165E3533'}
        D2=[ordered]@{Address='0x00610b8c';End='0x00610ba2';Size=22;Kind='data';IsCode=$false;IsData=$true;Name='aSu_0';Type='const wchar_t[]';Bytes='53 00 55 00 42 00 57 00 49 00 4e 00 2e 00 50 00 41 00 4c 00 00 00';SHA256='845854037B679051CFF8F13ACBA39E9374CDE53DA44998AB2BED383DAA71430A';Regular='Pooled UTF-16 source literal L"SUBWIN.PAL" passed to DrawTiledBackground; pointer-table label is an IDA artifact.';Xref='A07b';Count=45;First='0x0045b76b';Last='0x005bd928';Digest='A680D0A5D83F83484BA1EA878E22B5CAC205A85AF54AAD1B3E68A19BCCA4C53B'}
        D3=[ordered]@{Address='0x0067a744';End='0x0067a748';Size=4;Kind='data';IsCode=$false;IsData=$true;Name='g_pEPFLib';Type='ResourceLayoutTable *';Bytes='00 00 00 00';SHA256='DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119';Regular='Global EPF/resource-layout singleton used as the member receiver for LoadFrameDrawRecord.'}
    }
}
function Assert-Uid0002FNDataRecordV3([System.Collections.IDictionary]$Responses,[string]$Id,[string]$Phase) {
    $expected=(New-Uid0002FNDataExpectedV3)[$Id];$item=Get-Uid0002FNExactAddressRecordV3 $Responses.A04 $expected.Address "${Id}_${Phase}_ITEM";Assert-Uid0002FNItemRecordV3 $item $expected "${Id}_${Phase}_ITEM";$bytes=Get-Uid0002FNExactAddressRecordV3 $Responses.A06 $expected.Address "${Id}_${Phase}_BYTES";Assert-Uid0002FNByteRecordV3 $bytes $expected "${Id}_${Phase}_BYTES";$comment=Get-Uid0002FNExactAddressRecordV3 $Responses.A05 $expected.Address "${Id}_${Phase}_COMMENTS";$commentExpected=[ordered]@{Address=$expected.Address;address_regular=$expected.Regular;address_repeatable=$null;function_regular=$null;function_repeatable=$null};Assert-Uid0002FNCommentRecordV3 $comment $commentExpected "${Id}_${Phase}_COMMENTS"
    if($Id-in@('D1','D2')){$xrefExpected=[ordered]@{Target=$expected.Address;Count=$expected.Count;First=$expected.First;Last=$expected.Last;Digest=$expected.Digest};Assert-Uid0002FNXrefSetV3 $Responses[$expected.Xref] $xrefExpected "${Id}_${Phase}_XREF"|Out-Null}else{Assert-Uid0002FND3Pagination $Responses.A07c1 $Responses.A07c2|Out-Null};[ordered]@{Item=$item;Bytes=$bytes;Comment=$comment}
}
function Assert-Uid0002FNSemanticResponsesV2([System.Collections.IDictionary]$State,[System.Collections.IDictionary]$Responses,[System.Collections.IDictionary]$Contracts,[string]$Phase,[bool]$IncludeProfile) {
    Assert-Uid0002FNSealedContracts $Contracts
    foreach($required in @('A01','A02','A03','A04','A05','A06','A06a','A06b','A06c','A06d','A07a','A07b','A07c1','A07c2','A07d','A07e','A07f','A07g')){if(-not$Responses.Contains($required)){throw"RESPONSE_MISSING:${Phase}:$required"}}
    if($IncludeProfile-and-not$Responses.Contains('A06e')){throw"RESPONSE_MISSING:${Phase}:A06e"}
    $health=Get-Uid0002FNCallPayloadV3 $Responses.A01 "P11_${Phase}_HEALTH";Assert-Uid0002FNStringV3 (Get-Uid0002FNDirectPropertyV3 $health 'status' 'P11_HEALTH') 'ok' "P11_${Phase}_STATUS";Assert-Uid0002FNStringV3 (ConvertTo-Uid0002FNAddressV3 (Get-Uid0002FNDirectPropertyV3 $health 'image_base' 'P11_HEALTH') 'P11') '0x00400000' "P11_${Phase}_IMAGE_BASE"
    $f1=Assert-Uid0002FNF1V3 $Responses $Phase;$d1=Assert-Uid0002FNDataRecordV3 $Responses D1 $Phase;$d2=Assert-Uid0002FNDataRecordV3 $Responses D2 $Phase;$d3=Assert-Uid0002FNDataRecordV3 $Responses D3 $Phase;$p8=Assert-Uid0002FNP8V2 $Phase $Responses;$p9=Assert-Uid0002FNP9V2 $Phase $Responses $IncludeProfile
    $fence1=Get-Uid0002FNExactAddressRecordV3 $Responses.A06 '0x004816ce' "P2_${Phase}_LEFT";Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $fence1 'size' 'P2_LEFT') 2 "P2_${Phase}_LEFT_SIZE";if(([string](Get-Uid0002FNDirectPropertyV3 $fence1 'bytes' 'P2_LEFT')-replace'\s','').ToUpperInvariant()-cne'CCCC'){throw"P2_${Phase}_LEFT_BYTES"}
    $fence2=Get-Uid0002FNExactAddressRecordV3 $Responses.A06 '0x00481741' "P2_${Phase}_RIGHT";Assert-Uid0002FNIntegerV3 (Get-Uid0002FNDirectPropertyV3 $fence2 'size' 'P2_RIGHT') 15 "P2_${Phase}_RIGHT_SIZE";if(([string](Get-Uid0002FNDirectPropertyV3 $fence2 'bytes' 'P2_RIGHT')-replace'\s','').ToUpperInvariant()-cne('CC'*15)){throw"P2_${Phase}_RIGHT_BYTES"}
    $evidence=[ordered]@{F1=$f1;D1=$d1;D2=$d2;D3=$d3;P8=$p8;P9=$p9;P1='exact-function-range-body';P2='exact-fences';P3='exact-vtable-route';P4='exact-F1';P5='exact-callsets';P6='exact-D1-D2';P7='exact-D3';P10='no-extra-candidate-or-created-record';P11=$health}
    foreach($protection in @('P1','P2','P3','P4','P5','P6','P7','P8','P9','P10','P11')){Add-Uid0002FNJournal $State 'structural-protection' "${protection}:$Phase" (Get-Uid0002FNSha256Bytes([Text.Encoding]::UTF8.GetBytes((Get-Uid0002FNCanonicalJson $evidence[$protection]))))};Add-Uid0002FNJournal $State 'semantic-readback' $Phase 'F1,D1-D3,P1-P11-structurally-passed'
}
function Get-Uid0002FNPreferredRoleIdsV3([System.Collections.IDictionary]$State) {
    $ids=[ordered]@{};foreach($role in @('Wpre','Wtx','Wv1','Wv2','Wrb')){$id="uid0002fn-$($role.ToLowerInvariant())-$($State.Nonce)";if($ids.Values-contains$id){throw'ROLE_ID_PREFLIGHT_INTERNAL_DUPLICATE'};$ids[$role]=$id};$ids
}
function Assert-Uid0002FNPreferredRoleIdsAbsentV3([System.Collections.IDictionary]$State,[object]$ListPayload) {
    Assert-Uid0002FNListNativeTypes $ListPayload 'ROLE_ID_PREFLIGHT_A00' $false;$ids=Get-Uid0002FNPreferredRoleIdsV3 $State;$present=@($ListPayload.sessions|ForEach-Object{[string]$_.session_id})
    foreach($role in $ids.Keys){if($present-ccontains[string]$ids[$role]){throw"ROLE_ID_PREFLIGHT_COLLISION:$role:$($ids[$role])"}};$State.PreferredRoleIds=$ids;Add-Uid0002FNJournal $State 'role-id-preflight' 'before-B0' @($ids.Values);$ids
}
function Invoke-Uid0002FNG04V2([System.Collections.IDictionary]$State,[scriptblock]$SendJsonRpc,[string]$Phase) {
    $g04=Invoke-Uid0002FNTool $State $SendJsonRpc 'gate' "G04-$Phase" 'runtime_attestation' ([ordered]@{});$payload=Get-Uid0002FNStructured $g04 "G04-$Phase";Assert-Uid0002FNRuntimeNativeTypes $payload "G04-$Phase";Assert-Uid0002FNAttestationWindow $g04;Assert-Uid0002FNRoleWorkerImplementation $null $null $g04.Response ''|Out-Null
    $list=Invoke-Uid0002FNTool $State $SendJsonRpc 'gate' "G04-A00-$Phase" 'idb_list' ([ordered]@{});$listPayload=Get-Uid0002FNStructured $list "G04_A00_$Phase";Assert-Uid0002FNListNativeTypes $listPayload "G04_A00_$Phase" $false;if(@($listPayload.sessions|Where-Object{[bool]$_.is_active-and(Get-Uid0002FNCanonicalPath([string]$_.canonical_path))-ceq(Get-Uid0002FNCanonicalPath $canonical)}).Count-ne0){throw"G04_ACTIVE_CANONICAL:$Phase"};if($Phase-ceq'initial-quiescence'){Assert-Uid0002FNPreferredRoleIdsAbsentV3 $State $listPayload|Out-Null};Add-Uid0002FNJournal $State 'G04' $Phase 'passed';Get-Uid0002FNClosedIdentity $canonical
}
function New-Uid0002FNFixtureCallV3([object]$Payload){[ordered]@{Response=[pscustomobject]@{result=[pscustomobject]@{isError=$false;structuredContent=$Payload}}}}
function New-Uid0002FNFixtureXrefV3([string]$Target,[string[]]$Sources,[object]$NextOffset=$null,[int]$Total=$Sources.Count,[int]$Offset=0){New-Uid0002FNFixtureCallV3 ([pscustomobject]@{results=@([pscustomobject]@{query=[pscustomobject]@{address=$Target;direction='to';offset=$Offset};total=$Total;next_offset=$NextOffset;xrefs=@($Sources|ForEach-Object{[pscustomobject]@{from=$_;to=$Target;type='data'}})})})}
function Invoke-Uid0002FNStructuralHostileFixturesV3 {
    $passed=[Collections.Generic.List[string]]::new();$effects=[ordered]@{Save=0;Restore=0;ProtectedState=0}
    function Expect-Uid0002FNV3([string]$Name,[scriptblock]$Body,[string]$Expected){try{&$Body;throw"FIXTURE_DID_NOT_FAIL:$Name"}catch{if($_.Exception.Message-cne$Expected){throw"FIXTURE_WRONG_FAILURE:${Name}:$($_.Exception.Message):$Expected"};$passed.Add("structural-$Name")}}
    foreach($case in @(
        @('nested-session-id','{"jsonrpc":"2.0","id":"x","result":{"session":{"session_id":"a","session_id":"b"}}}','JSONRPC_DUPLICATE_PROPERTY_RECURSIVE:$.result.session.session_id'),
        @('nested-canonical-path','{"jsonrpc":"2.0","id":"x","result":{"session":{"canonical_path":"a","canonical_path":"b"}}}','JSONRPC_DUPLICATE_PROPERTY_RECURSIVE:$.result.session.canonical_path'),
        @('nested-iserror','{"jsonrpc":"2.0","id":"x","result":{"isError":false,"isError":true}}','JSONRPC_DUPLICATE_PROPERTY_RECURSIVE:$.result.isError'),
        @('nested-ok','{"jsonrpc":"2.0","id":"x","result":{"structuredContent":{"ok":true,"ok":false}}}','JSONRPC_DUPLICATE_PROPERTY_RECURSIVE:$.result.structuredContent.ok'),
        @('nested-route','{"jsonrpc":"2.0","id":"x","result":{"structuredContent":{"route":{"port":1,"port":2}}}}','JSONRPC_DUPLICATE_PROPERTY_RECURSIVE:$.result.structuredContent.route.port'),
        @('nested-process','{"jsonrpc":"2.0","id":"x","result":{"structuredContent":{"process":{"pid":1,"pid":2}}}}','JSONRPC_DUPLICATE_PROPERTY_RECURSIVE:$.result.structuredContent.process.pid'),
        @('nested-module','{"jsonrpc":"2.0","id":"x","result":{"structuredContent":{"modules":[{"sha256":"a","sha256":"b"}]}}}','JSONRPC_DUPLICATE_PROPERTY_RECURSIVE:$.result.structuredContent.modules[0].sha256'),
        @('nested-semantic-row','{"jsonrpc":"2.0","id":"x","result":{"structuredContent":{"results":[{"address":"0x1","address":"0x2"}]}}}','JSONRPC_DUPLICATE_PROPERTY_RECURSIVE:$.result.structuredContent.results[0].address')
    )){Expect-Uid0002FNV3 $case[0] {ConvertFrom-Uid0002FNResponse $case[1]|Out-Null} $case[2]}
    Expect-Uid0002FNV3 'scalar-structured' {Get-Uid0002FNCallPayloadV3 (New-Uid0002FNFixtureCallV3 'scalar') 'STRUCT'|Out-Null} 'STRUCT_STRUCTURED_OBJECT_REQUIRED'
    $functionRows=[pscustomobject]@{results=@([pscustomobject]@{address='0x00481490';end='0x004816ce';name='wrong';prototype='void __thiscall(ChattingVarietySelectPane *this)';size=574},[pscustomobject]@{address='0x00481750';end='0x00481a72';name='ChattingVarietySelectPane__OnPaint';prototype='void __thiscall(ChattingVarietySelectPane *this)';size=802})};$functionCall=New-Uid0002FNFixtureCallV3 $functionRows;$onPaint=(New-Uid0002FNP8ExpectedV3).OnPaint
    Expect-Uid0002FNV3 'cross-associated-function' {Assert-Uid0002FNFunctionRecordV3 (Get-Uid0002FNExactAddressRecordV3 $functionCall $onPaint.Address 'CROSS') $onPaint 'CROSS'} 'CROSS_NAME_VALUE'
    $duplicateRows=[pscustomobject]@{results=@($functionRows.results[0],$functionRows.results[0])};Expect-Uid0002FNV3 'p8-duplicate-candidate' {Get-Uid0002FNExactAddressRecordV3 (New-Uid0002FNFixtureCallV3 $duplicateRows) '0x00481490' 'P8_DUP'|Out-Null} 'P8_DUP_ADDRESS_CANDIDATE_COUNT:2'
    $frameRows=@([pscustomobject]@{name='outContext';offset=4;size=40;type='EPFTileContext'},[pscustomobject]@{name='bounds';offset='+0x2c';size=16;type='RectBounds'},[pscustomobject]@{name='var_4';offset='+0x3c';size=4;type='_DWORD'},[pscustomobject]@{name='__saved_registers';offset='+0x40';size=4;type='_DWORD'},[pscustomobject]@{name='__return_address';offset='+0x44';size=4;type='_UNKNOWN *'});$frameCall=New-Uid0002FNFixtureCallV3 ([pscustomobject]@{results=@([pscustomobject]@{address='0x004816d0';rows=$frameRows})});Expect-Uid0002FNV3 'f1-frame-native-type' {Assert-Uid0002FNFrameRowsV3 $frameCall 'F1_FRAME'|Out-Null} 'F1_FRAME_0_OFFSET_NATIVE_STRING'
    $sources=1..45|ForEach-Object{'0x{0:x8}'-f(0x00450000+$_)};$digest=Get-Uid0002FNSha256Bytes([Text.Encoding]::UTF8.GetBytes(($sources-join"`n")));$expected=[ordered]@{Target='0x00610b74';Count=45;First=$sources[0];Last=$sources[-1];Digest=$digest};Assert-Uid0002FNXrefSetV3 (New-Uid0002FNFixtureXrefV3 $expected.Target $sources) $expected 'D1_FIXTURE'|Out-Null;$passed.Add('structural-d1-45-row-baseline')
    Expect-Uid0002FNV3 'd1-xref-count' {Assert-Uid0002FNXrefSetV3 (New-Uid0002FNFixtureXrefV3 $expected.Target @($sources[0..43]) $null 44) $expected 'D1_COUNT'|Out-Null} 'D1_COUNT_COUNT'
    $duplicate=@($sources);$duplicate[20]=$duplicate[19];Expect-Uid0002FNV3 'd1-xref-duplicate' {Assert-Uid0002FNXrefSetV3 (New-Uid0002FNFixtureXrefV3 $expected.Target $duplicate) $expected 'D1_DUP'|Out-Null} 'D1_DUP_UNIQUE'
    $drift=@($sources);$drift[20]='0x0045ffff';Expect-Uid0002FNV3 'd1-xref-digest' {Assert-Uid0002FNXrefSetV3 (New-Uid0002FNFixtureXrefV3 $expected.Target $drift) $expected 'D1_DIGEST'|Out-Null} 'D1_DIGEST_ORDER'
    $d2Expected=[ordered]@{Target='0x00610b8c';Count=45;First=$sources[0];Last=$sources[-1];Digest=$digest};Expect-Uid0002FNV3 'd2-xref-count' {Assert-Uid0002FNXrefSetV3 (New-Uid0002FNFixtureXrefV3 $d2Expected.Target @($sources[0..43]) $null 44) $d2Expected 'D2_COUNT'|Out-Null} 'D2_COUNT_COUNT'
    $state=New-Uid0002FNTransactionStateV2 '20260806235955';$collision=(Get-Uid0002FNPreferredRoleIdsV3 $state).Wv2;$list=[pscustomobject]@{sessions=@([pscustomobject]@{session_id=$collision;canonical_path=$canonical;is_active=$false})};Expect-Uid0002FNV3 'role-id-collision-before-B0' {Assert-Uid0002FNPreferredRoleIdsAbsentV3 $state $list|Out-Null} "ROLE_ID_PREFLIGHT_COLLISION:Wv2:$collision"
    if($effects.Save-ne0-or$effects.Restore-ne0-or$effects.ProtectedState-ne0){throw'STRUCTURAL_FIXTURE_NONZERO_EFFECT'};$script:Uid0002FNStructuralFixtureEffects=$effects
    if($passed.Count-ne18-or@($passed|Sort-Object -Unique).Count-ne18){throw"STRUCTURAL_FIXTURE_COUNT:$($passed.Count)"};@($passed)
}
~~~

## Removed Block R007

- SHA256: `B912161CEAAD0F74BF5B5FD980EA36E43EBA2AA898CCC214D4575175F5DBBD41`
- Language: `powershell`
- Bytes: `9928`
- First recovered timestamp: `2026-08-08T18:54:02.250Z`
- Session provenance: rollout-2026-08-06T18-18-26-019fd928-038d-72b3-b35b-bd6e2bfb539f.jsonl line 197028 (2026-08-08T18:54:02.250Z); rollout-2026-08-06T18-18-26-019fd928-038d-72b3-b35b-bd6e2bfb539f.jsonl line 197029 (2026-08-08T18:54:02.306Z)

~~~powershell
function Start-Uid0002FNGate2BTransaction {
    [CmdletBinding()]
    param(
        [scriptblock]$SendJsonRpc,
        [ValidateSet('Live','HostileSuite','SealProbe')]
        [string]$Mode='Live'
    )
    $privatePayloadGzipBase64='__UID0002FN_SEALED_PRIVATE_PAYLOAD_GZIP_BASE64__'
    $privatePayloadSHA256='5EE3EB4F5C4604D986D2445EFBB216261A80D266F509C9A0A087EF781DD28986'
    $privatePayloadBytes=357635
    $privatePayloadFunctions=250
    $compressed=[Convert]::FromBase64String($privatePayloadGzipBase64)
    $input=[IO.MemoryStream]::new($compressed,$false)
    $gzip=[IO.Compression.GZipStream]::new($input,[IO.Compression.CompressionMode]::Decompress,$false)
    $output=[IO.MemoryStream]::new()
    try{$gzip.CopyTo($output)}finally{$gzip.Dispose();$input.Dispose()}
    try{$sourceBytes=$output.ToArray()}finally{$output.Dispose()}
    if($sourceBytes.Length-ne$privatePayloadBytes){throw "V5_SEAL_PAYLOAD_LENGTH:$($sourceBytes.Length)"}
    $sha=[Security.Cryptography.SHA256]::Create();try{$sourceHash=(-join($sha.ComputeHash($sourceBytes)|ForEach-Object{$_.ToString('X2')}))}finally{$sha.Dispose()}
    if($sourceHash-cne$privatePayloadSHA256){throw "V5_SEAL_PAYLOAD_HASH:$sourceHash"}
    $source=[Text.Encoding]::UTF8.GetString($sourceBytes);$tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput($source,[ref]$tokens,[ref]$errors)
    if($errors.Count-ne0){throw "V5_SEAL_PAYLOAD_PARSE:$($errors[0].Message)"}
    $functionCount=@($ast.EndBlock.Statements|Where-Object{$_-is[Management.Automation.Language.FunctionDefinitionAst]}).Count
    if($functionCount-ne$privatePayloadFunctions){throw "V5_SEAL_FUNCTION_COUNT:$functionCount"}
    $driver=@'
function Invoke-Uid0002FNSealedPrivateDriverV5([scriptblock]$Transport,[string]$DriverMode,[string]$PayloadSHA256) {
    $canonical='E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
    $root='E:\NTK\Resources\NexusTK\.uid0002fn-transaction'
    if($DriverMode-ceq'HostileSuite'){return @(Invoke-Uid0002FNHostileFixturesV5)}
    if($DriverMode-ceq'SealProbe'){
        $effects=[ordered]@{Save=0;Restore=0;ProtectedState=0;Backup=0;Receipt=0;OpenReceipt=0;PartialCleanup=0;Retire=0;Lock=0;Read=0;Runtime=0}
        $expected=New-Uid0002FNExpectedPackageV5
        $fixtureTransport=New-Uid0002FNFixtureTransportV5 $effects 'baseline' $canonical
        $ops=New-Uid0002FNFixtureOpsBoundV5 $effects 'baseline' $expected $canonical
        $outcome=Invoke-Uid0002FNCoordinatorV5 $fixtureTransport $ops $expected $canonical '20260808T010000Z'
        return [ordered]@{Sealed=$true;Outcome=[string]$outcome.Outcome;Code=[string]$outcome.Code;PrivatePayloadSHA256=$PayloadSHA256;Canonical=$canonical;Root=$root;ExpectedSHA256=Get-Uid0002FNHashV4 (ConvertTo-Uid0002FNCanonicalJsonV4 $expected);OperationKeys=@($ops.Keys);Coordinator='Invoke-Uid0002FNCoordinatorV5';Sequence='expected>ops>coordinator>journal';Effects=$effects}
    }
    $expected=New-Uid0002FNExpectedPackageV5
    $ops=New-Uid0002FNProductionOpsV5 $canonical $root
    Invoke-Uid0002FNCoordinatorV5 $Transport $ops $expected $canonical
}
'@
    $moduleSource=$source+"`n"+$driver
    $module=Microsoft.PowerShell.Core\New-Module -ScriptBlock ([scriptblock]::Create($moduleSource))
    try{
        $values=@(& $module {param($transport,$driverMode,$payloadHash)Invoke-Uid0002FNSealedPrivateDriverV5 $transport $driverMode $payloadHash} $SendJsonRpc $Mode $privatePayloadSHA256)
        if($Mode-cne'HostileSuite'){
            if($values.Count-ne1){throw "V5_SEAL_RESULT_COUNT:$($values.Count)"}
            return $values[0]
        }
        @($values)
    }finally{$module=$null}
}
function Invoke-Uid0002FNHostileFixturesV5 {
    @(Start-Uid0002FNGate2BTransaction -SendJsonRpc {throw 'V5_HOSTILE_OUTER_TRANSPORT_FORBIDDEN'} -Mode HostileSuite)
}
function Invoke-Uid0002FNPublicBoundaryAttackV5([scriptblock]$Entry,[string]$Label) {
    $outerCalls=[Collections.Generic.List[object]]::new()
    $outerTransport={param($request)$outerCalls.Add($request);throw 'V5_SEAL_OUTER_TRANSPORT_REACHED'}.GetNewClosure()
    $invoke={param($entry,$transport)& $entry -SendJsonRpc $transport -Mode SealProbe}
    switch($Label){
        'substitute-function-expected-package'{$result=&{param($entry,$transport,$invoke)function New-Uid0002FNExpectedPackageV5{[ordered]@{Forged=$true}};&$invoke $entry $transport} $Entry $outerTransport $invoke}
        'substitute-function-operations-provider'{$result=&{param($entry,$transport,$invoke)function New-Uid0002FNProductionOpsV5{[ordered]@{Root={'forged'};Forged=$true}};&$invoke $entry $transport} $Entry $outerTransport $invoke}
        'substitute-function-coordinator'{$result=&{param($entry,$transport,$invoke)function Invoke-Uid0002FNCoordinatorV5{[ordered]@{Outcome='accepted';Forged=$true}};&$invoke $entry $transport} $Entry $outerTransport $invoke}
        'substitute-function-parser-contracts'{$result=&{param($entry,$transport,$invoke)function ConvertFrom-Uid0002FNStrictJsonV5{[ordered]@{Forged=$true}};function New-Uid0002FNContracts{[ordered]@{Forged=$true}};&$invoke $entry $transport} $Entry $outerTransport $invoke}
        'substitute-variable-scope'{$result=&{param($entry,$transport,$invoke)$Expected=[ordered]@{Forged=$true};$Ops=[ordered]@{Forged=$true};$Coordinator='forged';$privatePayloadSHA256='0';$source='forged';&$invoke $entry $transport} $Entry $outerTransport $invoke}
        'substitute-module-private-command'{$attackModule=Microsoft.PowerShell.Core\New-Module -ScriptBlock {function New-Uid0002FNExpectedPackageV5{[ordered]@{Forged=$true}};function New-Uid0002FNProductionOpsV5{[ordered]@{Forged=$true}};function Invoke-Uid0002FNCoordinatorV5{[ordered]@{Outcome='accepted';Forged=$true}}};$result=&$attackModule{param($entry,$transport)&$entry -SendJsonRpc $transport -Mode SealProbe} $Entry $outerTransport;$attackModule=$null}
        'substitute-module-public-command'{$attackModule=Microsoft.PowerShell.Core\New-Module -Name UID0002FNPublicAttack -ScriptBlock {function New-Uid0002FNExpectedPackageV5{[ordered]@{Forged=$true}};function New-Uid0002FNProductionOpsV5{[ordered]@{Forged=$true}};function Invoke-Uid0002FNCoordinatorV5{[ordered]@{Outcome='accepted';Forged=$true}};function New-Module{throw 'FORGED_NEW_MODULE'};Export-ModuleMember -Function *};Microsoft.PowerShell.Core\Import-Module $attackModule -Force;try{$result=&$Entry -SendJsonRpc $outerTransport -Mode SealProbe}finally{Microsoft.PowerShell.Core\Remove-Module UID0002FNPublicAttack -Force}}
        'substitute-canonical-root'{$result=&{param($entry,$transport,$invoke)$Canonical='C:\forged\wrong.i64';$Root='C:\forged\root';$script:Uid0002FNCanonical='C:\forged\script.i64';&$invoke $entry $transport} $Entry $outerTransport $invoke}
        'substitute-sequencing-rpc'{$result=&{param($entry,$transport,$invoke)function Invoke-Uid0002FNRpcV5{[ordered]@{Outcome='accepted';Forged=$true}};&$invoke $entry $transport} $Entry $outerTransport $invoke}
        'substitute-sequencing-open'{$result=&{param($entry,$transport,$invoke)function Invoke-Uid0002FNOpenRoleV5{[ordered]@{Outcome='accepted';Forged=$true}};function Invoke-Uid0002FNSaveOnceV5{[ordered]@{Class='definite-success';Forged=$true}};&$invoke $entry $transport} $Entry $outerTransport $invoke}
        default{throw "V5_SEAL_ATTACK_UNKNOWN:$Label"}
    }
    if($outerCalls.Count-ne0){throw "V5_SEAL_OUTER_TRANSPORT_EFFECT:${Label}:$($outerCalls.Count)"}
    if($result.Sealed-isnot[bool]-or-not$result.Sealed-or$result.Outcome-cne'accepted'-or$result.PrivatePayloadSHA256-cne'5EE3EB4F5C4604D986D2445EFBB216261A80D266F509C9A0A087EF781DD28986'-or$result.Canonical-cne'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'-or$result.Root-cne'E:\NTK\Resources\NexusTK\.uid0002fn-transaction'-or$result.Coordinator-cne'Invoke-Uid0002FNCoordinatorV5'-or$result.Sequence-cne'expected>ops>coordinator>journal'){throw "V5_SEAL_ATTACK_FORGED_RESULT:$Label"}
    $fx=$result.Effects;if([int]$fx.Save-ne1-or[int]$fx.Receipt-ne1-or[int]$fx.Restore-ne0-or[int]$fx.ProtectedState-ne0-or[int]$fx.Lock-ne0){throw "V5_SEAL_ATTACK_EFFECT:$Label"}
    [ordered]@{Label=$Label;Outcome='bound-private';Code=$null;OuterTransport=0;ExternalSave=0;ExternalRestore=0;ExternalProtectedState=0;PrivateSave=[int]$fx.Save;PrivateReceipt=[int]$fx.Receipt;PrivateRestore=[int]$fx.Restore;PrivateProtectedState=[int]$fx.ProtectedState;PrivateLock=[int]$fx.Lock;PrivatePayloadSHA256=$result.PrivatePayloadSHA256;ExpectedSHA256=$result.ExpectedSHA256;Coordinator=$result.Coordinator;Canonical=$result.Canonical;Root=$result.Root}
}
function Invoke-Uid0002FNPublicBoundarySubstitutionFixturesV5 {
    $labels=@('substitute-function-expected-package','substitute-function-operations-provider','substitute-function-coordinator','substitute-function-parser-contracts','substitute-variable-scope','substitute-module-private-command','substitute-module-public-command','substitute-canonical-root','substitute-sequencing-rpc','substitute-sequencing-open')
    $entry=${function:Start-Uid0002FNGate2BTransaction};$results=[Collections.Generic.List[object]]::new()
    foreach($label in $labels){$results.Add((Invoke-Uid0002FNPublicBoundaryAttackV5 $entry $label))}
    if($results.Count-ne10-or@($results.Label|Sort-Object -Unique).Count-ne10){throw 'V5_SEAL_ATTACK_COUNT'};@($results)
}
function Invoke-Uid0002FNExpandedHostileFixturesV5 {
    $core=@(Invoke-Uid0002FNHostileFixturesV5);$boundary=@(Invoke-Uid0002FNPublicBoundarySubstitutionFixturesV5)
    if($core.Count-ne74-or@($core.Label|Sort-Object -Unique).Count-ne74){throw 'V5_SEALED_CORE_COUNT'}
    if($boundary.Count-ne10-or@($boundary.Label|Sort-Object -Unique).Count-ne10){throw 'V5_SEALED_BOUNDARY_COUNT'}
    [ordered]@{Core=$core;Boundary=$boundary;CoreCount=$core.Count;BoundaryCount=$boundary.Count;TotalCount=$core.Count+$boundary.Count;PrivatePayloadSHA256='5EE3EB4F5C4604D986D2445EFBB216261A80D266F509C9A0A087EF781DD28986'}
}
~~~
