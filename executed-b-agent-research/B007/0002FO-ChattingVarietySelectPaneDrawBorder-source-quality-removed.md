<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B007\0002FO-ChattingVarietySelectPaneDrawBorder-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002FO-ChattingVarietySelectPaneDrawBorder-source-quality.md](0002FO-ChattingVarietySelectPaneDrawBorder-source-quality.md)
- Cleanup generated: `2026-08-12`
- Removed executable blocks: `3`
- Scope: exact JSON-RPC transaction payloads removed from the source report by supervisor housekeeping. Research facts, structured IDA recommendations, and reconstructed C++ remain in the source report.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `233-237`
- Original language: `json`
- Block SHA256: `DCEBD2330C0DF2F3E3D8CB0F622F5FD8C1407E4197E86954AACC509017088693`

~~~json
{"jsonrpc":"2.0","id":"S00-schema","method":"tools/list","params":{}}
{"jsonrpc":"2.0","id":"S01-list","method":"tools/call","params":{"name":"idb_list","arguments":{}}}
{"jsonrpc":"2.0","id":"S02-health","method":"tools/call","params":{"name":"server_health","arguments":{"database":"<EXACT-AUTHORIZED-SESSION>"}}}
~~~

## Removed Block R002

- Original source lines: `299-304`
- Original language: `json`
- Block SHA256: `5F48A9457E4CA31B6A858A1DD0258D84C11EE963D76C7106977EEDCC01E87EAF`

~~~json
{"jsonrpc":"2.0","id":"R01-functions","method":"tools/call","params":{"name":"lookup_funcs","arguments":{"queries":["0x00481750","0x00457a60","0x004b7c50","0x004b7e10","0x004d02f0","0x004b9980"],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R02-frame","method":"tools/call","params":{"name":"stack_frame","arguments":{"addrs":["0x00481750"],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R03-items","method":"tools/call","params":{"name":"inspect_items","arguments":{"addrs":["0x00481741","0x00481750","0x00481a72","0x0067a744","0x00457a60","0x004b7c50","0x004b7e10","0x004d02f0","0x004b9980","0x00610b74","0x00610b8c","0x00614f70","0x00614f74","0x00614f78","0x00614f7c","0x00614f80","0x00614f84","0x00614f88"],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R04-comments","method":"tools/call","params":{"name":"get_comments","arguments":{"addrs":["0x00481741","0x00481750","0x00481a72","0x0067a744","0x00457a60","0x004b7c50","0x004b7e10","0x004d02f0","0x004b9980","0x00610b74","0x00610b8c","0x00614f70","0x00614f74","0x00614f78","0x00614f7c","0x00614f80","0x00614f84","0x00614f88"],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
~~~

## Removed Block R003

- Original source lines: `306-330`
- Original language: `json`
- Block SHA256: `831A688054812C79F8386E750648EA508CEDBD766AE93CA21710ABA06F3DA32F`

~~~json
{"jsonrpc":"2.0","id":"R05-bytes","method":"tools/call","params":{"name":"get_bytes","arguments":{"regions":[{"addr":"0x00481741","size":15},{"addr":"0x00481750","size":802},{"addr":"0x00481a72","size":14},{"addr":"0x0067a744","size":4},{"addr":"0x00457a60","size":68},{"addr":"0x004b7c50","size":31},{"addr":"0x004b7e10","size":25},{"addr":"0x004d02f0","size":174},{"addr":"0x004b9980","size":49},{"addr":"0x00610b74","size":22},{"addr":"0x00610b8c","size":22},{"addr":"0x00614f70","size":28}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R06-profile","method":"tools/call","params":{"name":"func_profile","arguments":{"queries":[{"addr":"0x00481750","offset":0,"count":1,"sort_by":"addr","descending":false,"include_lists":true,"max_items":32,"include_prototype":true}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R06b-disasm","method":"tools/call","params":{"name":"disasm","arguments":{"addr":"0x00481750","max_instructions":400,"offset":0,"include_total":true,"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R07-names","method":"tools/call","params":{"name":"entity_query","arguments":{"queries":[{"kind":"names","regex":"^ChattingVarietySelectPane__DrawBorder$"},{"kind":"names","regex":"^g_pEPFLib$"},{"kind":"names","regex":"^EPFTileContext_Initialize$"},{"kind":"names","regex":"^InitRectBounds$"},{"kind":"names","regex":"^NexusTK_OffsetRect$"},{"kind":"names","regex":"^ResourceLayoutTable_LookupLayoutEntry$"},{"kind":"names","regex":"^GrafPort_RenderTileFrame$"},{"kind":"names","regex":"^aSu$"},{"kind":"names","regex":"^aSu_0$"},{"kind":"names","regex":"^\\?\\?_7ChattingVarietySelectPane@@6B@_0$"}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08a-to-00481741","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00481741","direction":"to","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08b-to-00481750","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00481750","direction":"to","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08c-to-00481a72","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00481a72","direction":"to","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08d-to-0067a744","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x0067a744","direction":"to","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08e-to-00457a60","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00457a60","direction":"to","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08f-to-004b7c50","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x004b7c50","direction":"to","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08g-to-004b7e10","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x004b7e10","direction":"to","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08h-to-004d02f0","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x004d02f0","direction":"to","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08i-to-004b9980","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x004b9980","direction":"to","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08j-to-00610b74","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00610b74","direction":"to","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08k-to-00610b8c","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00610b8c","direction":"to","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08l-from-00614f70","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00614f70","direction":"from","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08m-from-00614f74","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00614f74","direction":"from","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08n-from-00614f78","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00614f78","direction":"from","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08o-from-00614f7c","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00614f7c","direction":"from","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08p-from-00614f80","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00614f80","direction":"from","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08p2-to-00614f80","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00614f80","direction":"to","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08q-from-00614f84","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00614f84","direction":"from","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
{"jsonrpc":"2.0","id":"R08r-from-00614f88","method":"tools/call","params":{"name":"xref_query","arguments":{"queries":[{"addr":"0x00614f88","direction":"from","xref_type":"any","offset":0,"count":200,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<EXACT-AUTHORIZED-SESSION>"}}}
~~~
