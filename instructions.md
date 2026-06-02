

# Task at hand #
- Continue completing documentation in E:\NTK\GhidraBridge\source-3\project-documentation fully, validating info, and accuracy. Seeking full binary coverage and complete documentation.
- Remember to cross reference between files, and keeping data updated and accurate between them.
- Remember to update by-meta files, and create new meta documents when needed for uncovered topics.
- Remember that files prefixed with `-` are meta/additional files on that topic. Please check those as they have additional information and instructions.
- Consider this task efectively never complete. You can always create more detailed documentation once full binary documentation has been completed.
- Git is only a backup/sync tool for this documentation work. Do not interrupt small documentation edits for commits; commit/push after roughly 30 minutes of work or after a large batch of about 50+ meaningful edits.

## Detailed Info ##
Please read `E:\NTK\GhidraBridge\source-3\project-documentation\by-structure.md` for more information about documentation structure and how data is structured and written. This is required.

# Tools #
- Please remember some of the data in wave3.py/wave2.py is wip and may not be accurate, be draft code, incomplete or inccorectly attributed. Always use IDA MCP as a secondary source and do manual memory inspection when needed as even IDA MCP may not correctly interpret binary info.

## Wave3.py ##
- `E:\NTK\GhidraBridge\source-3\wave3.py`
## Wave2.py ##
- `E:\NTK\GhidraBridge\source-2\core\wave2\wave2.py` | Older Version, may have outdated info but useful if Wave3 is not working optimally as its currently a WIP
## IDA MCP ##

- Avoid making changes through ida mcp, please be aware data from wave2/3 is locked and changes in ida mcp will not be reflected in wave2/3. This may cause conflicting info between the tools, which is why manual inspection / confirmation is always required

- You may additional use ida mcp at this address
  Streamable HTTP: http://127.0.0.1:13337/mcp
  SSE: http://127.0.0.1:13337/sse
  Config: http://127.0.0.1:13337/config.html
- You will have to MANUALLY figure out how to send commands to this tool as its not exposed directly. This should not be a problem as you have done this before. Please add any notes directly below this line with instructions on how to do this if needed for future reference.
- Manual note: direct JSON-RPC `POST` requests to `http://127.0.0.1:13337/mcp` work from PowerShell. A safe flow is `initialize` -> `tools/list` -> `tools/call`.
- Working PowerShell pattern:
  `$body = @{jsonrpc='2.0'; id=1; method='tools/call'; params=@{name='lookup_funcs'; arguments=@{queries='0x00576660'}}} | ConvertTo-Json -Depth 8`
  `Invoke-RestMethod -Uri http://127.0.0.1:13337/mcp -Method Post -ContentType 'application/json' -Body $body | ConvertTo-Json -Depth 10`
- Multiple `lookup_funcs` queries should be passed as an array, not one space-separated string:
  `$body = @{jsonrpc='2.0'; id=2; method='tools/call'; params=@{name='lookup_funcs'; arguments=@{queries=@('0x0048a100','0x0048a120')}}} | ConvertTo-Json -Depth 8`
- Useful methods:
  `initialize` with `@{protocolVersion='2025-03-26'; capabilities=@{}; clientInfo=@{name='codex-manual'; version='1.0'}}`
  `tools/list` with empty params
  `tools/call` with `params.name='<tool>'` and `params.arguments=@{...}`
- 2026-05-24 MCP schema note: `decompile`, `callers`, `callees`, and `xrefs_to` require an `addrs` array, for example `arguments=@{addrs=@('0x00597610','0x00597630')}`. Do not use `address='0x...'` for these tools.
- Confirmed locally in this repo: `lookup_funcs`, `tools/list`, and `initialize` all responded successfully through `/mcp`.
- 2026-05-22 recheck during DAT/audio research: `/mcp` `tools/list` was still reachable and returned tools including `idb_meta`, `lookup_funcs`, `cursor_addr`, `cursor_func`, `int_convert`, `list_funcs`, `list_globals`, and `imports`.
- 2026-05-22 verification: `/mcp` is available. `initialize` returned server `ida-pro-mcp` version `1.0.0` with protocol `2025-06-18`; `tools/list` returned IDA tools including `idb_meta`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callers`, `callees`, `analyze_funcs`, `strings`, `search`, `struct_info`, and `py_eval`.
- Current PowerShell note: use `Invoke-WebRequest -UseBasicParsing` when inspecting status/content. Without `-UseBasicParsing`, Windows PowerShell may fail because the Internet Explorer engine is unavailable. For `/mcp`, include `-Headers @{Accept='application/json, text/event-stream'}` when using streamable HTTP.
- Compact verified status pattern:
  `$body = @{jsonrpc='2.0'; id=1; method='tools/list'; params=@{}} | ConvertTo-Json -Depth 8`
  `$r = Invoke-WebRequest -UseBasicParsing -Uri http://127.0.0.1:13337/mcp -Method Post -ContentType 'application/json' -Headers @{Accept='application/json, text/event-stream'} -Body $body`
  `$r.StatusCode; $r.Content`


# Issues #
- If encountering issues on the program level with Wave3.py itself (Not issues with data from wave3.py) please report them to `E:\NTK\GhidraBridge\source-3\project-documentation\wave3_noticed_problems.md`
- If encountering issues with data FROM wave3.py such as incorrect information, missing info, etc please report it to `E:\NTK\GhidraBridge\source-3\project-documentation\wave3_data_issues.md`
