<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0002KA-RankingCategoryRecordResetUserEntries-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002KA-RankingCategoryRecordResetUserEntries-source-quality.md](0002KA-RankingCategoryRecordResetUserEntries-source-quality.md)
- Cleanup reason: executable PowerShell is prohibited in B-agent research reports; valid research and reconstructed C++ remain in the original report.
- Preservation: every removed block below is copied verbatim, with its original language and start line recorded.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original start line: `422`
- Language: `powershell`
- Preserved body SHA256: `50D989B2F6573D8C8444D28DB588C4A2AECD326111E168CC14F552901149916C`
- Original fenced-block characters: `853`

~~~~powershell
$idb = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$expectedSha = '74720635DA2BED8F69DFFDBE8E7ED345C6F6ECB44F38FF03A8E8FACC9539FC46'
$expectedSize = 143196412
$item = Get-Item -LiteralPath $idb
$actualSha = (Get-FileHash -LiteralPath $idb -Algorithm SHA256).Hash
if ($item.Length -ne $expectedSize -or $actualSha -ne $expectedSha) { throw 'UID0002KA canonical IDB prestate mismatch; stop before mutation and reconcile the report.' }
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$backup = "$idb.bak-UID0002KA-prestate-$stamp"
Copy-Item -LiteralPath $idb -Destination $backup
$backupItem = Get-Item -LiteralPath $backup
$backupSha = (Get-FileHash -LiteralPath $backup -Algorithm SHA256).Hash
if ($backupItem.Length -ne $expectedSize -or $backupSha -ne $expectedSha) { throw 'UID0002KA backup is not byte-identical; stop before mutation.' }
~~~~

## Removed Block CLEANUP-20260813-0002KA-SECTION21

Source: [0002KA-RankingCategoryRecordResetUserEntries-source-quality.md](0002KA-RankingCategoryRecordResetUserEntries-source-quality.md)

This archive is non-authoritative and must never be executed. It preserves the exact report text removed during supervisor cleanup.

<!-- BEGIN CLEANUP-20260813-0002KA-SECTION21 -->
## IDA Rename / Type / Comment Recommendations

The transaction in this section was supervisor-owned and is complete. Agent-B005 performed no IDA mutation. The literal request, protection, save, and rollback package is retained as the exact historical transaction specification consumed by the supervisor and as evidence for the completed result below; it is not future current transaction authority.

Completed historical transaction specification and evidence:

- All requests below were literal MCP tool calls in tool {complete-object} form.
- The consumed transaction replaced only the quoted database placeholder <active-session-id-from-current-idb_list> with the exact active session_id returned by its immediately preceding idb_list call.
- The consumed transaction did not substitute an old report-time session name, PID, or transport client ID.
- The completed transaction used the report-time canonical disk baseline of 143196412 bytes at SHA256 74720635DA2BED8F69DFFDBE8E7ED345C6F6ECB44F38FF03A8E8FACC9539FC46. Under the consumed contract, any different disk identity would have stopped mutation for fresh reconciliation; the rejected mixed historical hash was never backup or comparison authority.
- The supervisor created and verified the byte-identical backup before the first mutation. Under the consumed contract, no save was permitted until every pre-save readback and P1-P11 check passed.

Literal disk and backup precondition consumed by the completed transaction:

> Removed executable PowerShell block R001; preserved verbatim in [0002KA-RankingCategoryRecordResetUserEntries-source-quality-removed.md](0002KA-RankingCategoryRecordResetUserEntries-source-quality-removed.md).

Literal session and health preconditions consumed by the completed transaction:

~~~text
idb_list {}
server_health {"database":"<active-session-id-from-current-idb_list>"}
~~~

The idb_list result must contain exactly one active, owned, adopted worker for E:\NTK\Resources\NexusTK\NexusTK.exe.i64. server_health must return status ok, that exact IDB path, imagebase 0x400000, and hexrays_ready true. auto_analysis_ready false is acceptable only because every bounded request below must succeed.

Literal complete prestate/readback bundle RB0:

~~~text
func_profile {"queries":[{"addr":"0x0045c240","offset":0,"count":1,"sort_by":"addr","descending":false,"include_lists":true,"max_items":100,"include_prototype":true},{"addr":"0x004594d0","offset":0,"count":1,"sort_by":"addr","descending":false,"include_lists":true,"max_items":100,"include_prototype":true},{"addr":"0x0045c260","offset":0,"count":1,"sort_by":"addr","descending":false,"include_lists":true,"max_items":100,"include_prototype":true}],"database":"<active-session-id-from-current-idb_list>"}
decompile {"addr":"0x0045c240","include_addresses":true,"database":"<active-session-id-from-current-idb_list>"}
decompile {"addr":"0x004594d0","include_addresses":true,"database":"<active-session-id-from-current-idb_list>"}
disasm {"addr":"0x0045c240","max_instructions":20,"offset":0,"include_total":true,"database":"<active-session-id-from-current-idb_list>"}
disasm {"addr":"0x004594d0","max_instructions":500,"offset":0,"include_total":true,"database":"<active-session-id-from-current-idb_list>"}
disasm {"addr":"0x0045c260","max_instructions":100,"offset":0,"include_total":true,"database":"<active-session-id-from-current-idb_list>"}
stack_frame {"addrs":"0x0045c240","database":"<active-session-id-from-current-idb_list>"}
get_comments {"addrs":["0x0045c240","0x0045c246","0x0045c24c","0x0045c256"],"database":"<active-session-id-from-current-idb_list>"}
xrefs_to {"addrs":"0x0045c240","limit":1000,"database":"<active-session-id-from-current-idb_list>"}
xref_query {"queries":[{"addr":"0x0045c240","direction":"to","xref_type":"code","offset":0,"count":5000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0045c240","direction":"to","xref_type":"data","offset":0,"count":5000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x004594d0","direction":"both","xref_type":"any","offset":0,"count":5000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0045c260","direction":"both","xref_type":"any","offset":0,"count":5000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<active-session-id-from-current-idb_list>"}
get_bytes {"regions":[{"addr":"0x0045c239","size":7},{"addr":"0x0045c240","size":23},{"addr":"0x0045c257","size":9}],"database":"<active-session-id-from-current-idb_list>"}
inspect_items {"addrs":["0x0045c239","0x0045c240","0x0045c246","0x0045c24c","0x0045c256","0x0045c257","0x0045c260"],"database":"<active-session-id-from-current-idb_list>"}
type_inspect {"queries":{"name":"RankingCategoryRecord","include_members":true,"max_members":100},"database":"<active-session-id-from-current-idb_list>"}
~~~

The consumed RB0 precondition had to prove `sub_45C240`, `int __thiscall(_DWORD *this)`, exact four instructions and 23-byte body, one block, one caller, zero callees, one return-address frame row, four blank function/entry regular/repeatable channels and blank internal instruction comments, exact code xref from `0x004594f7` with no data xrefs, exact body/padding bytes and hashes, exact caller/successor boundaries, and the exact `0x2b0` `RankingCategoryRecord` UDT. The supervisor proved that prestate before mutation.

Per-item executable transaction contract:

| Item | Exact fresh prestate | Exact action and order | Required immediate/persisted readback | Stop/rollback protection |
|---|---|---|---|---|
| F0 rename dry-run | RB0 exact; desired name collision-free | Literal rename dry-run request below | Rerun complete RB0; every result remains raw prestate | Stop before mutation on count other than 1/1, overwrite need, collision, or any RB0 delta |
| T1 function type | sub_45C240; int __thiscall(_DWORD *this); one return-address frame row | Literal set_type request with mandatory kind function | Rerun complete RB0 calls; name remains raw, prototype becomes exact void thiscall, decompilation has no return, all P1-P11 physical evidence remains exact | Stop unsaved on parse failure, added frame row, comment/xref/byte/range/UDT drift, or any non-type delta |
| F1 function name | T1 exact | Literal actual rename, then literal target-only force_recompile | Rerun complete RB0 calls; exact desired name and T1 prototype persist with no other delta | Stop unsaved on count other than 1/1 or any non-name/recompile-cache delta |
| C1 function comment | F1 exact; four target comment channels blank | Literal set_function_comments request | Rerun complete RB0 calls; only function-regular channel equals exact text | Stop unsaved on channel mismatch, duplicate text, or any other delta |
| V1 persistence | T1/F1/C1 and P1-P11 pass in a final complete RB0 rerun; backup is exact | Literal idb_save, supervisor stops saved worker, literal fresh idb_open, idb_list, server_health, and full readback | Exact T1/F1/C1 and P1-P11 survive fresh reopen | Restore exact backup and prove raw fresh rollback on save error or any persistence delta |

Literal mutation calls consumed in exact order:

~~~text
rename {"batch":{"func":{"addr":"0x0045c240","name":"RankingCategoryRecord_ResetUserEntries"},"stop_on_error":true,"dry_run":true,"allow_overwrite":false},"database":"<active-session-id-from-current-idb_list>"}
set_type {"edits":{"addr":"0x0045c240","kind":"function","signature":"void __thiscall sub_45C240(RankingCategoryRecord *this)"},"database":"<active-session-id-from-current-idb_list>"}
rename {"batch":{"func":{"addr":"0x0045c240","name":"RankingCategoryRecord_ResetUserEntries"},"stop_on_error":true,"dry_run":false,"allow_overwrite":false},"database":"<active-session-id-from-current-idb_list>"}
force_recompile {"items":{"addr":"0x0045c240"},"database":"<active-session-id-from-current-idb_list>"}
set_function_comments {"items":{"addr":"0x0045c240","comment":"Clears the record's user-entry vector without releasing capacity and resets m_localPlayerRank to -1 before requesting ranking rows."},"database":"<active-session-id-from-current-idb_list>"}
~~~

Mandatory immediate readback ordering used by the completed transaction:

1. Run the rename dry-run, then rerun every literal RB0 call. It must be byte-for-byte/field-for-field raw prestate.
2. Run set_type, then rerun every literal RB0 call before actual rename. Expected only semantic delta: void __thiscall sub_45C240(RankingCategoryRecord *this), with no return in decompilation.
3. Run actual rename and force_recompile, then rerun every literal RB0 call. Expected only additional semantic delta: exact name RankingCategoryRecord_ResetUserEntries.
4. Run set_function_comments, then rerun every literal RB0 call. Expected only additional metadata delta: exact function-regular comment text.
5. Rerun every literal RB0 call once more as the complete pre-save verification. No partial or sampled inventory is sufficient.

P1-P11 exact pre/post protections:

- P1: body remains 8B 81 58 02 00 00 89 81 5C 02 00 00 C7 81 68 02 00 00 FF FF FF FF C3, 23 bytes, SHA256 1B79E28803B9FEDD079B4D54D1FA4F991F40AD7D4039CC438CC5B6F41CD0A37D.
- P2: [0x0045c239,0x0045c240) remains seven CC bytes, SHA256 F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D; [0x0045c257,0x0045c260) remains nine CC bytes, SHA256 57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE.
- P3: target remains [0x0045c240,0x0045c257), size 0x17, four instructions, one block, one caller, zero callees.
- P4: target xrefs remain exactly one code xref from 0x004594f7 and zero data xrefs, with no truncation.
- P5: target frame remains exactly one __return_address row at +0x0, width 4, type _UNKNOWN *; this is an ECX this parameter and no physical stack row may be added.
- P6: entry regular, entry repeatable, function repeatable, and all internal instruction comments remain blank.
- P7: only function-regular comment changes, and it equals the exact C1 text.
- P8: RankingCategoryRecord remains size 0x2b0 with all 15 members and exact +0x258/+0x25c/+0x260/+0x264/+0x268/+0x26c/+0x2ac identities and types unchanged.
- P9: RankingDialog__RequestRankingPage at [0x004594d0,0x0045957e), its prototype, body, xrefs, and call at 0x004594f7 remain prestate-identical.
- P10: successor at 0x0045c260 remains the same size-0x21 function with its complete profile/body/xrefs/items unchanged.
- P11: no other function name/type, stack row, UDT, comment, item boundary, byte, xref, caller/callee inventory, or function boundary changes.

Literal save and fresh-persistence calls consumed after the final pre-save RB0 pass:

~~~text
idb_save {"path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","database":"<active-session-id-from-current-idb_list>"}
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":true,"init_hexrays":true,"idle_ttl_sec":3600,"preferred_session_id":"b005-uid0002ka-persist-verify"}
idb_list {}
server_health {"database":"<fresh-session-id-returned-by-idb_open-or-idb_list>"}
~~~

The consumed contract required the supervisor to stop the saved worker before `idb_open` so the reopened session was genuinely fresh, substitute the returned session ID into every RB0 database field, rerun the full bundle, and hash/size the saved canonical disk. That persistence verification passed with saved SHA256 `85582A483733EC1F54725DBC305E16219A4C6E86B0D948563AF87E59C035AF5D` at `143196420` bytes.

Literal rollback specification retained as historical protection evidence; this branch was not entered:

> Removed executable PowerShell block R002; preserved verbatim in [0002KA-RankingCategoryRecordResetUserEntries-source-quality-removed.md](0002KA-RankingCategoryRecordResetUserEntries-source-quality-removed.md).

The not-entered rollback branch would have required the supervisor to stop every worker bound to the restored path and perform:

~~~text
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":true,"init_hexrays":true,"idle_ttl_sec":3600,"preferred_session_id":"b005-uid0002ka-rollback-verify"}
idb_list {}
server_health {"database":"<fresh-rollback-session-id-returned-by-idb_open-or-idb_list>"}
~~~

The not-entered rollback specification required every RB0 call to be rerun with a fresh rollback session ID and prove the exact raw prestate: `sub_45C240`, `int __thiscall(_DWORD *this)`, blank four target comment channels, exact one-row frame, exact P1-P11 state, and canonical disk SHA256 `74720635DA2BED8F69DFFDBE8E7ED345C6F6ECB44F38FF03A8E8FACC9539FC46` at `143196412` bytes. This retained branch documents the fail-closed contract; the successful transaction required no rollback.

### Supervisor Gate 2B Applied And Persisted Result

The primary supervisor executed and audited the literal transaction above. This is dated external evidence, not a claim that B005 performed IDA work:

1. C2KA-037 prestate passed against canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` at `143196412` bytes and SHA256 `74720635DA2BED8F69DFFDBE8E7ED345C6F6ECB44F38FF03A8E8FACC9539FC46`. The verified byte-identical backup was `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0002KA-prestate-20260804-134142`.
2. C2KA-044 rename dry-run and actual rename passed the exact 1/1, no-overwrite, collision-free contract. The persisted name is `RankingCategoryRecord_ResetUserEntries`.
3. C2KA-045 applied the exact `void __thiscall` `RankingCategoryRecord *this` function type. Immediate type/decompile/frame readback passed.
4. C2KA-046 applied only the exact function-regular comment `Clears the record's user-entry vector without releasing capacity and resets m_localPlayerRank to -1 before requesting ranking rows.` Other comment channels remained protected.
5. C2KA-047 reran every immediate/full RB0 stage and P1-P11 protection. Exact bytes, pads, range, frame, xrefs, caller, successor, UDT, item boundaries, and unrelated names/types/comments remained unchanged.
6. C2KA-048 completed save and fresh persistence. The saved canonical file is `143196420` bytes with SHA256 `85582A483733EC1F54725DBC305E16219A4C6E86B0D948563AF87E59C035AF5D`. Fresh session `b005-uid0002ka-persist-verify`, PID `15224`, passed full persisted RB0. No rollback path was entered.

The full post-save identity above is the completed supervisor persistence evidence. Current live-session truth must still be rebound dynamically if a later supervisor action needs IDA access; this completed transaction package is historical, not reusable current authority.
<!-- END CLEANUP-20260813-0002KA-SECTION21 -->

## Removed Block R002

- Original start line: `521`
- Language: `powershell`
- Preserved body SHA256: `0DABC0EE5A2DA9BE11EB9F4F5E1E4AF6F0AD244466A17D09CB69B50C349C12DD`
- Original fenced-block characters: `539`

~~~~powershell
# Before-save failure: do not call idb_save. Stop the unsaved worker, verify
# the canonical disk remains at the prestate SHA/size, reopen it fresh, and
# rerun the raw-prestate RB0 bundle.

# Save/persistence failure:
Copy-Item -LiteralPath $backup -Destination $idb -Force
$restoredItem = Get-Item -LiteralPath $idb
$restoredSha = (Get-FileHash -LiteralPath $idb -Algorithm SHA256).Hash
if ($restoredItem.Length -ne $expectedSize -or $restoredSha -ne $expectedSha) { throw 'UID0002KA rollback restore mismatch; halt.' }
~~~~
