<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\0002K3-RankingCategoryRecordCopyStartTimeParts-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002K3-RankingCategoryRecordCopyStartTimeParts-source-quality.md](0002K3-RankingCategoryRecordCopyStartTimeParts-source-quality.md)
- Cleanup generated: `2026-08-12`
- Removed executable blocks: `2`
- Scope: exact JSON-RPC transaction payloads removed from the source report by supervisor housekeeping. Research facts, structured IDA recommendations, and reconstructed C++ remain in the source report.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `456-458`
- Original language: `json`
- Block SHA256: `C7AF63DFF333F970F5D22E364491959D5D04A986A813A243E8EED3416554AA50`

~~~json
{"jsonrpc":"2.0","id":101,"method":"tools/call","params":{"name":"declare_type","arguments":{"database":"<fresh-idb-session>","decls":"struct RankingCategoryRecord { short m_listIndex; char _idaAlignmentAfterListIndex[2]; int m_categoryId; int m_stateCode; tm m_startTime; tm m_endTime; wchar_t m_title[256]; int m_totalRankCount; void *m_userEntriesBegin; void *m_userEntriesEnd; void *m_userEntriesCapacityEnd; int m_loadedRowsCategoryId; int m_localPlayerRank; unsigned char m_reservedLocalPlayerFooter[0x40]; int m_localPlayerScore; };"}}}
~~~

## Removed Block R002

- Original source lines: `462-464`
- Original language: `json`
- Block SHA256: `E5448440BFE94CF67D0E3E6BF9A9D9FEC301ECCA716920EB07D4750A3B535A7C`

~~~json
{"jsonrpc":"2.0","id":102,"method":"tools/call","params":{"name":"type_query","arguments":{"database":"<fresh-idb-session>","queries":{"filter":"RankingCategoryRecord","kind":"udt","offset":0,"count":20,"sort_by":"name","descending":false,"include_decl":true,"include_members":true,"max_members":64,"include_relationships":true}}}}
~~~
