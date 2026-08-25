<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\000299-g_pInputMan-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000299-g_pInputMan-empty-emitter-source-quality.md](000299-g_pInputMan-empty-emitter-source-quality.md)
- Cleanup reason: executable PowerShell is prohibited in B-agent research reports; valid research and reconstructed C++ remain in the original report.
- Preservation: every removed block below is copied verbatim, with its original language and start line recorded.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original start line: `643`
- Language: `powershell`
- Preserved body SHA256: `00ED61F9134BDC0F6F1FF715799523DB237E2AB5FD43D72EAACC559D63B5152D`
- Original fenced-block characters: `522`

~~~~powershell
python .\tools\validator.py --mode file --file by-global\g_pInputMan.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-memory\0x0067ab44-0x0067ab48.g_pInputMan.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-class\InputMan.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-file\InputMan.md --apply --queue-timeout 240 --no-generated-refresh
~~~~

## Removed Block R002 - Literal MCP Requests And Transaction Runbook

The following material was removed from the source report because it contains literal MCP requests and a replayable mutation/save/rollback procedure. It is non-authoritative, must never be executed, and receives no Gate, coverage, score, IDA, validator, or lifecycle credit.

~~~text
## IDA Rename / Type / Comment Recommendations

This section preserves the complete supervisor-only Gate 2B package that was accepted and applied. B002 performed no mutation. Primary supervisor receipts prove P0/backup, disposable unsaved preflight, the exact three canonical mutations, one save, fresh S1 persistence verification, and two stable exclusive probes; the literal package remains below as dated transaction and rollback evidence rather than future work.

Applied receipt: P0 and `NexusTK.exe.i64.bak-UID000299-prestate-20260806_0348` both had SHA `B9D15E933B0FAA504D31F5AE9A20909534AF05A05157168BE072035D93251A46`, size `143197476`. `primary-preflight-uid000299-202608060343` remained an unsaved disposable P0 copy. `primary-transaction-uid000299-202608060348` performed only I001-I003 and one `idb_save`. Persisted S1 SHA/size is `1EE09DC2B6DD0A7F39EB4EE459FF8B785C6E4E6B913CDA6A827BDB4FFE1D741C` / `143197502`; `primary-verify-uid000299-202608060350` and the final exclusive probes proved the complete expected poststate and every protection.

### Dated literal prestate

| ID | Entity | Literal prestate | Proposed action | Required poststate |
| --- | --- | --- | --- | --- |
| I001 | local type InputMan | type_inspect name InputMan: exists false, error Type not found: InputMan | declare_type with typedef struct InputMan InputMan; | InputMan exists as an incomplete/forward type sufficient for a pointer; no members or size are invented |
| I002 | data interval 0x0067ab44-0x0067ab48 | four separate one-byte unknown item heads: 0x0067ab44 head 0x0067ab44/end 0x0067ab45/size 1/name unk_67AB44/type _DWORD */kind unknown/is_code false/is_data false; 0x0067ab45 head 0x0067ab45/end 0x0067ab46/size 1/name absent/type absent/kind unknown/is_code false/is_data false; 0x0067ab46 head 0x0067ab46/end 0x0067ab47/size 1/name absent/type absent/kind unknown/is_code false/is_data false; 0x0067ab47 head 0x0067ab47/end 0x0067ab48/size 1/name absent/type absent/kind unknown/is_code false/is_data false. At each of 0x0067ab44/45/46/47 the regular address comment is absent and the repeatable address comment is absent. Bytes are 00 00 00 00 and exactly 18 xrefs all land at 0x0067ab44. | make_data at 0x0067ab44 with InputMan *g_pInputMan, name g_pInputMan, delete_existing true, consuming exactly the four frozen one-byte heads and no byte outside the half-open interval | every query address 0x0067ab44/45/46/47 resolves to the single containing item head 0x0067ab44, end 0x0067ab48, size 4, name g_pInputMan, canonical displayed type InputMan *, kind data, is_code false, is_data true; 0x0067ab45/46/47 have no independent item head, name, or type; bytes/xrefs unchanged; regular and repeatable comments remain absent at 0x0067ab45/46/47, while 0x0067ab44 comments remain at prestate until I003 |
| I003 | regular address comment 0x0067ab44 | regular absent; repeatable absent | set_address_comments regular text: Process-wide InputMan singleton pointer; published by InputMan construction and cleared by destruction and unwind cleanup. | regular exact text; repeatable still absent |

Literal mutation calls, after dynamic database substitution:

~~~json
{"database":"<transaction-session>","decls":"typedef struct InputMan InputMan;"}
~~~

~~~json
{"database":"<transaction-session>","items":{"addr":"0x0067ab44","type":"InputMan *g_pInputMan","name":"g_pInputMan","delete_existing":true}}
~~~

~~~json
{"database":"<transaction-session>","items":{"addr":"0x0067ab44","comment":"Process-wide InputMan singleton pointer; published by InputMan construction and cleared by destruction and unwind cleanup."}}
~~~

- Call mapping: declare_type for I001, make_data for I002, set_address_comments for I003.
- No rename call is used. make_data supplies the item name while hardening its physical boundary. Therefore the rename endpoint's pure:true requirement is not bypassed or needed, and no /vibe/ directory/decompiler-refresh side effect is authorized.
- If the supervisor chooses a separate rename for any reason, it must use rename with pure:true and must first repair this report/package; the current accepted package does not authorize that extra action.
- set_address_comments changes only the regular address-comment channel. Broad set_comments and any Hex-Rays comment endpoint are forbidden.
- Every idb_open in diagnostics, dry-run, transaction, verification, or rollback must set run_auto_analysis:false.

### Complete protections

- P001 target bytes and replaced physical items: 0x0067ab44-0x0067ab48 remain 00 00 00 00. Frozen prestate is exactly four one-byte unknown heads at 0x0067ab44/45/46/47 with the literal bounds, names, types, kinds, and comment-channel absences in I002; the only permitted item delta is their replacement by one four-byte data item headed at 0x0067ab44 with 0x0067ab45/46/47 as interior bytes and no independent names/types/items.
- P002 surrounding bytes: exact 40 zero bytes at 0x0067ab30-0x0067ab58 remain unchanged.
- P003 predecessor item: 0x0067ab40 head/end/size/name/data classification unchanged.
- P004 successor item: 0x0067ab48 head/end/name/type/code/data classification unchanged.
- P005 xrefs: exact 18-address set and data-ref classification remains unchanged.
- P006 target comments: both channels begin absent at each of 0x0067ab44/45/46/47; only the 0x0067ab44 regular channel changes to exact I003. The 0x0067ab44 repeatable channel and both channels at 0x0067ab45/46/47 remain absent through immediate readback, save, reopen, and rollback proof.
- P007 neighbor comments: both channels at 0x0067ab40 and 0x0067ab48 remain absent.
- P008 names: g_pInputMan must have no collision; no other global/function/local/member name changes.
- P009 type library: only the absent InputMan forward typedef may be added; no full UDT, members, size, bases, methods, enums, or unrelated types change.
- P010 functions: no function boundary, function name, signature, frame, local, decompile, or call graph changes.
- P011 analysis side effects: no analyze_function, decompile, function-directory, /vibe/, auto-analysis, or unlisted mutation in the canonical transaction.
- P012 executable bytes and PE image are never patched.

### Deterministic transaction and rollback

1. Run any analysis-producing diagnostics only in a disposable read-only worker opened with run_auto_analysis:false. Close/terminate it without save, prove its exact PID/process-generation identity absent with PID-reuse checks, require no is_active:true canonical session, treat stale inactive owned/adopted rows as non-authoritative, and pass a disposed read-only Windows FileShare.None probe on the canonical IDB.
2. Capture closed-disk P0 tuple: exact path, size, UTC mtime, SHA256. The research-time 51FFD... tuple is historical only.
3. Select a collision-free timestamped backup path that does not exist. Copy P0 once, then prove backup path/size/SHA byte-identical.
4. Create a byte-identical throwaway preflight copy from the backup. Open it with run_auto_analysis:false, freeze the literal item/name/type/size/kind and regular/repeatable comment prestates separately at 0x0067ab44/45/46/47, execute I001-I003, and use inspection-only tools to prove that all four query addresses resolve to the exact I002 poststate and comment disposition. Retire it without save, prove process absent and exclusive file access, and delete/discard only that throwaway through supervisor-owned safe file handling. If displayed type is not exactly InputMan *, any consumed item differs from the four frozen heads, or any protection changes, stop and repair the report; do not touch canonical.
5. Reprove canonical closed-disk P0 is unchanged and backup is byte-identical. Open one fresh exact-P0 transaction worker with run_auto_analysis:false and record exact session/PID/process identity.
6. Frozen prestate allowlist: idb_list, server_health, type_inspect, list_globals, inspect_items, get_bytes, get_comments, xrefs_to, and bounded instruction/name reads that do not analyze or decompile. Re-read every I/P row literally, including separate inspect_items and both comment-channel reads at 0x0067ab44, 0x0067ab45, 0x0067ab46, and 0x0067ab47. Any delta stops with no mutation.
7. Execute I001, then immediately type_inspect InputMan. Execute I002, then immediately inspect 0x0067ab44/45/46/47 individually and require each query to resolve to the one exact four-byte I002 poststate; separately inspect both neighbors, bytes, all 18 xrefs, names, and both comment channels at all four target addresses. Execute I003, then immediately reread both comment channels at 0x0067ab44/45/46/47 and both neighbors. Stop on first mismatch.
8. Final pre-save readback must prove all I001-I003 and P001-P012, including the single containing item returned for every 0x0067ab44/45/46/47 query and the exact four-address comment disposition. Do not call analyze_function or decompile.
9. Branch A, any pre-save failure: retire transaction worker without save; prove exact PID/process identity absent, no active canonical session, exclusive FileShare.None access, and canonical disk still exact P0. Fresh-open P0 read-only with run_auto_analysis:false, prove the complete four-head prestate and both absent comment channels separately at 0x0067ab44/45/46/47, retire verifier without save, and rehash exact P0.
10. Branch B, all readbacks pass: call idb_save exactly once to the canonical path. Classify the literal response as exactly one of explicit success, explicit failure/tool error, or indeterminate timeout/disconnect/missing response. Freeze the response and never retry or issue another save in any branch.
11. Branch C, standalone explicit failure/tool-error response: freeze the exact returned error and grant no action credit. Identity-check and retire the exact transaction worker with no further save; prove that exact PID/process generation absent with PID-reuse checks, require no is_active:true canonical session while treating stale inactive registry rows as non-authoritative, and pass a disposed exclusive Windows FileShare.None probe. Bind the first closed-disk failure tuple F0 by exact path/size/UTC mtime/SHA. Open one fresh inspection-only verifier with run_auto_analysis:false and classify F0 as follows: (a) exact P0 plus complete reproduction of the four-head/comment/type prestate and failure to reproduce the complete poststate is not persisted, requires no restore, and receives no credit; close the verifier without save, prove its PID generation absent/no active canonical session/FileShare.None, and require a final exact P0 rehash; (b) only a distinct transaction-attributable candidate identity that reproduces every I001-I003/P001-P012 poststate, then survives verifier close/proved absence/FileShare.None and a repeated exact path/size/mtime/SHA rehash, may be classified failing-saved; it receives no credit and may be restored only after re-proving the intact byte-identical P0 backup, exact transaction attribution, all workers absent, no active canonical session, exclusive access, and no possible later accepted work, followed by exact P0 copy-back, fresh inspection-only full-prestate verifier, verifier close/proved absence, FileShare.None, and final exact P0 rehash; (c) partial or mixed state, simultaneous prestate and poststate reproduction, reproduction of neither, a missing tuple or item, an unknown/third identity, non-repeatable candidate identity, PID ambiguity, active worker, or failed exclusive probe is indeterminate and stops without restore, overwrite, retry, or another save. This explicit returned-error branch is separate from Branch A pre-save failure and from Branch D timeout/disconnect/missing-response uncertainty.
12. For explicit success or Branch D indeterminate timeout/disconnect/missing response, identity-check and retire the exact transaction worker with no further save, prove its exact PID/process generation absent before disk classification, require no active canonical session, treat stale inactive registry rows as non-authoritative, and pass exclusive FileShare.None.
13. Explicit save success: capture closed-disk S1 path/size/mtime/SHA. Branch D indeterminate timeout/disconnect/missing response: capture the closed-disk tuple and classify as exact P0/not persisted, distinct repeated transaction-attributable S1/persisted, or unknown/third/partial/mixed identity. No second save call is allowed.
14. For persisted classification after explicit success or Branch D, open one fresh verifier with run_auto_analysis:false and prove all I/P rows, including individual 0x0067ab44/45/46/47 item resolution and both comment channels at all four addresses. Retire verifier without save, prove verifier PID/process absent and no active canonical session, pass FileShare.None, rehash canonical, and require exact repeated S1 path/size/mtime/SHA. Only then grant action credit.
15. For not-persisted exact P0 classification after Branch D, reopen and prove the complete four-head prestate plus both absent comment channels separately at 0x0067ab44/45/46/47 and prove the complete poststate is not reproduced, retire without save, prove absence/FileShare.None, rehash exact P0, and grant no action credit.
16. For failed saved state or verifier mismatch after explicit success or Branch D, restore only if canonical identity is proven repeated exact transaction-attributable S1/failing-saved identity and no later accepted work can exist. Prove all workers absent/no active canonical session/FileShare.None, re-prove the intact byte-identical P0 backup, copy it over canonical, verify exact P0, fresh-open with run_auto_analysis:false, prove the complete four-head prestate and both absent comment channels separately at 0x0067ab44/45/46/47, retire verifier without save, prove absence/FileShare.None, and perform a final exact P0 rehash.
17. A partial/mixed/both/neither/missing state, third/unknown/non-repeatable disk identity, active or ambiguous process, PID reuse ambiguity, failed exclusive probe, or unlisted side effect in any post-save-response branch stops without restore or overwrite. Escalate to the supervisor; do not restore over unknown later work.

Supervisor action count: three literal mutations, I001-I003. Protections and readbacks are not counted as mutations.
~~~
