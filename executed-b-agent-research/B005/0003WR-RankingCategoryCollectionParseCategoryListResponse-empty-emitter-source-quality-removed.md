# Removed Operational Material: UID0003WR

Source report: [0003WR-RankingCategoryCollectionParseCategoryListResponse-empty-emitter-source-quality.md](0003WR-RankingCategoryCollectionParseCategoryListResponse-empty-emitter-source-quality.md)

Rejected source artifact SHA256: `4F08A3195BD649705E5348A160847901BE844575FA4822280E25CE72D5CFD4C8`.

This sibling archive is inert and non-authoritative. It preserves the verbatim pre-repair Section 21 material removed from the live report because it contained session-bound MCP payloads and an operational mutation/readback/recovery/persistence runbook.

- Never execute or operationalize any text in this file.
- This file is not a B-agent report and receives no Gate 1, Gate 2, coverage, score, IDA, validator, or lifecycle credit.
- Current authority comes only from the cleaned source report plus fresh supervisor-owned verification under the current workflow.

## Verbatim Pre-Repair Section 21

All actions are supervisor-owned and unchecked. B005 performed no mutation or save. `AR` means regular address comment, `AP` repeatable address comment, `FR` regular function comment, and `FP` repeatable function comment. The literal pre-state below was reread against session `supervisor-uid0000KZ-rollback2-20260814` and canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; it is evidence, not permission to trust a stale session. Immediately before Gate 2B, the supervisor must re-list sessions and require this exact session/path or replace the session identifier in every payload only with the newly listed active session whose canonical path is exactly the same. No rollback/probe/copy database is an acceptable mutation target.

### Literal current-schema runtime binding and preflight

The current public MCP schemas do not expose a `stop_on_error` member on `set_repeatable_comments` or `set_address_repeatable_comments`. Adding that unsupported field is forbidden. Fail-closed behavior is therefore achieved by one-item write calls, immediate one-item readback, and a procedural stop before the next write. The following are literal public-schema payloads for the current canonical binding:

| Purpose | Literal payload | Required result before any write |
| --- | --- | --- |
| Session discovery | `idb_list {}` | Exactly one active authoritative route selected for the canonical input path; its session is `supervisor-uid0000KZ-rollback2-20260814` for this evidence freeze. Any ambiguity, inactive route, path mismatch, or changed session requires a fresh complete preflight. |
| Runtime attestation | `runtime_attestation {"expected_database":"supervisor-uid0000KZ-rollback2-20260814","expected_canonical_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"}` | Top-level `schema_version:1`, `ok:true`, no errors, and an attested active worker route for the exact session/path. Any missing field, mismatch, or error stops before write/save. |
| Health | `server_health {"database":"supervisor-uid0000KZ-rollback2-20260814"}` | `status:"ok"`, exact canonical input path, and `hexrays_ready:true`. `auto_analysis_ready:false` alone is not a failure when bounded reads below succeed. |
| Function identities/ranges | `lookup_funcs {"database":"supervisor-uid0000KZ-rollback2-20260814","queries":["0x45C2A0","0x5FA290","0x45BF50","0x5FA29B","0x575480"]}` | Target and UInt16 helper are the exact modeled functions below; each cleanup/tail/handler query maps to containing function `sub_45C2A0` at `0x45C2A0` with logical size `0x2B6`, while its queried item retains the separate chunk-head identity below. No query error, independent function definition, or alternate ownership/boundary is accepted. |
| Item identities | `inspect_items {"database":"supervisor-uid0000KZ-rollback2-20260814","addrs":["0x45C2A0","0x5FA290","0x45BF50","0x5FA29B","0x658AE0","0x610BB0","0x575480"]}` | Every head/end/name/type/code/data/size field exactly matches I01-I08. |
| Comment channels | `get_comments {"database":"supervisor-uid0000KZ-rollback2-20260814","addrs":["0x45C2A0","0x5FA290","0x45BF50","0x5FA29B","0x658AE0","0x610BB0","0x575480"]}` | Every AR/AP/FR/FP channel exactly matches I01-I08; empty strings are the schema readback for `absent`. |
| Immutable bytes | `get_bytes {"database":"supervisor-uid0000KZ-rollback2-20260814","regions":[{"addr":"0x45C2A0","size":694},{"addr":"0x5FA290","size":11},{"addr":"0x45BF50","size":11},{"addr":"0x5FA29B","size":40},{"addr":"0x658AE0","size":36},{"addr":"0x610BB0","size":16},{"addr":"0x575480","size":26}]}` | Exact byte counts and SHA256 values below; no unreadable/null/truncated region. |
| Complete protected frames | `stack_frame {"database":"supervisor-uid0000KZ-rollback2-20260814","addrs":["0x45C2A0","0x575480"]}` | Exact complete target and UInt16 frames below, with no added, omitted, renamed, retyped, resized, or shifted row. |
| Xrefs/routes | `xref_query {"database":"supervisor-uid0000KZ-rollback2-20260814","queries":[{"addr":"0x45C2A0","direction":"to","xref_type":"any","offset":0,"count":5000,"dedup":true,"sort_by":"addr"},{"addr":"0x5FA290","direction":"both","xref_type":"any","offset":0,"count":5000,"dedup":true,"sort_by":"addr"},{"addr":"0x45BF50","direction":"both","xref_type":"any","offset":0,"count":5000,"dedup":true,"sort_by":"addr"},{"addr":"0x5FA29B","direction":"both","xref_type":"any","offset":0,"count":5000,"dedup":true,"sort_by":"addr"},{"addr":"0x658AE0","direction":"both","xref_type":"any","offset":0,"count":5000,"dedup":true,"sort_by":"addr"},{"addr":"0x610BB0","direction":"to","xref_type":"any","offset":0,"count":5000,"dedup":true,"sort_by":"addr"},{"addr":"0x575480","direction":"to","xref_type":"any","offset":0,"count":5000,"dedup":true,"sort_by":"addr"}]}` | Exact material routes below, including target total `1`, constructor constant total `2`, and UInt16 helper total `372`; no pagination remainder or error. |

### Per-entity pre-state, action, and expected readback

| ID | Entity and literal current pre-state | Classification and literal current-schema action | Exact expected readback |
| --- | --- | --- | --- |
| I01 | Function `[0x45C2A0,0x45C556)`, 694 bytes; entry item `[0x45C2A0,0x45C2A1)` code; name `sub_45C2A0`; type `void __thiscall(int *this, int)`; AR/AP/FR/FP all absent; SHA256 `95AD30865B5B1B4364CC09BE4D8A789BA0B9ED5526E7429C821436DD12E66533`; first 16 `55 8B EC 6A FF 68 9B A2 5F 00 64 A1 00 00 00 00`; last 16 `E8 E4 B1 16 00 8B E5 5D C2 04 00 E8 FF B0 16 00`; sole inbound code xref `0x459243`; complete frame below. | `no change recommended`; protection-only precondition for I02. No write payload. Rename, type, boundary, frame, byte, AR, AP, or FR changes are forbidden. | Every listed field remains exact before and after all later actions. Any mismatch stops before the first write or before the next write, with no save. |
| I02 | Same exact function state is repeated here as an actionable pre-state: `[0x45C2A0,0x45C556)`, `sub_45C2A0`, `void __thiscall(int *this, int)`, AR/AP/FR/FP absent, SHA256 `95AD30865B5B1B4364CC09BE4D8A789BA0B9ED5526E7429C821436DD12E66533`, inbound `0x459243`, complete frame below. | `apply`; `set_repeatable_comments {"database":"supervisor-uid0000KZ-rollback2-20260814","items":{"addr":"0x45C2A0","comment":"Opcode 0x7D subcommand 1: clears ranking categories, parses signed-count BE category metadata and ANSI titles, appends deep-copied records, and retains only a successful prefix if parsing or append throws."}}` | Write result contains exactly one `addr:"0x45c2a0"` row and no `error`; immediate `get_comments` for only `0x45C2A0` returns FP equal to the literal text and AR/AP/FR empty. I01 identity/range/type/frame/bytes/xrefs remain exact. |
| I03 | Target-owned external cleanup chunk `[0x5FA290,0x5FA29B)`, 11 bytes; `lookup_funcs` maps the head to containing function `sub_45C2A0`; head item `[0x5FA290,0x5FA296)` code; name `loc_5FA290`; item type absent; AR/AP absent; `get_comments` returns no independent FR/FP fields at this nonentry chunk head, while owner-entry FR/FP are absent under I01; bytes `8D 8D 40 FA FF FF E9 B5 1C E6 FF`; SHA256 `93EAFBFF4D72B12D43B283C6812BB8B013D7ED170D925CD709356B7A60D12932`; inbound EH data `0x658AB4`; outbound path `0x5FA296 -> 0x45BF50`. | `apply`; `set_address_repeatable_comments {"database":"supervisor-uid0000KZ-rollback2-20260814","items":{"addr":"0x5FA290","comment":"Compiler-generated UID0003WR temporary-record cleanup: passes stack RankingCategoryRecord::m_userEntries at +0x258 to the shared teardown tail."}}` | Exactly one successful result row; immediate one-address `get_comments` returns AP equal to the literal and AR empty. Containing-function mapping, chunk/head boundaries, name/type, bytes/hash, and both routes remain exact. |
| I04 | Target-owned external shared-tail chunk `[0x45BF50,0x45BF5B)`, 11 bytes; `lookup_funcs` maps the head to containing function `sub_45C2A0`; head item `[0x45BF50,0x45BF56)` code; name `loc_45BF50`; item type absent; AR absent; AP exactly `Shared compiler EH cleanup tail for stack-local RankingCategoryRecord: adjust this to m_userEntries at +0x258, then tail-jump to RankingUserEntryVectorDestroy.`; no independent FR/FP fields at the nonentry head; bytes `81 C1 58 02 00 00 E9 95 16 00 00`; SHA256 `DBD3EB5227E92B186F3502F6E90F91176F26E8248507DABBCB190CD001F41F0A`; inbound code xrefs `0x5FA296`, `0x5FA2C9`. | `already present`; protection-only, no write payload. The AP must never be cleared or rewritten by this report. | Existing AP, containing-function mapping, and every listed entity field remain byte-for-byte exact throughout the sequence. |
| I05 | Target-owned external compiler-EH handler chunk `[0x5FA29B,0x5FA2C3)`, 40 bytes; `lookup_funcs` maps the head to containing function `sub_45C2A0`; head item `[0x5FA29B,0x5FA29F)` code; name `SEH_45C2A0`; item type absent; AR/AP absent; no independent FR/FP fields at the nonentry head, while owner-entry FR/FP are absent under I01; SHA256 `1AACAA2DF3128953E42E260FEE059829DFB1894E69B2638EAE35493132081859`; full bytes below; inbound prologue data ref `0x45C2A5`; FuncInfo route `0x5FA2B9 -> 0x658AE0`. | `apply`; `set_address_repeatable_comments {"database":"supervisor-uid0000KZ-rollback2-20260814","items":{"addr":"0x5FA29B","comment":"Compiler-generated UID0003WR EH handler using FuncInfo stru_658AE0; source uses automatic RankingCategoryRecord and standard vector lifetime."}}` | Exactly one successful result row; immediate one-address `get_comments` returns AP equal to the literal and AR empty. Containing-function mapping, range/head/name/type/bytes/hash/routes remain exact; owner-entry FR remains absent and FP remains exactly the I02 text. |
| I06 | Data item `[0x658AE0,0x658B04)`, width 36; name `stru_658AE0`; type absent; AR/AP absent; FR/FP not applicable; bytes `22 05 93 19 01 00 00 00 B4 8A 65 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00`; SHA256 `D898E13A8D42E333808FAD499D4F6ADD025BC32C10244EF9DB7D1FE97DD4D223`; inbound data ref `0x5FA2B9`; material unwind-map relation `0x658AB4`. | `apply`; `set_address_repeatable_comments {"database":"supervisor-uid0000KZ-rollback2-20260814","items":{"addr":"0x658AE0","comment":"MSVC FuncInfo for UID0003WR ParseCategoryListResponse; unwind map includes the temporary RankingCategoryRecord nested-vector cleanup."}}` | Exactly one successful result row; immediate one-address `get_comments` returns AP equal to the literal and AR empty. Item/data classification, range/name/type/width, bytes/hash, and routes remain exact. |
| I07 | Data item `[0x610BB0,0x610BC0)`, width 16; name `xmmword_610BB0`; type absent; AR/AP absent; FR/FP not applicable; bytes `00 00 00 00 00 00 00 00 00 00 00 00 FF FF FF FF`; SHA256 `34885EA2EF8490886FAE553C8CE7FFB5A27563825E5F6CE02784875D1ACE0E47`; exactly two inbound data xrefs `0x45C43A`, `0x45C710`. | `apply`; `set_address_repeatable_comments {"database":"supervisor-uid0000KZ-rollback2-20260814","items":{"addr":"0x610BB0","comment":"Shared inlined RankingCategoryRecord default-construction constant: null m_userEntries triplet followed by m_loadedRowsCategoryId = -1; used by category-list and initial-page parsers."}}` | Exactly one successful result row; immediate one-address `get_comments` returns AP equal to the literal and AR empty. Data classification, item/name/type/width, bytes/hash, and both xrefs remain exact. |
| I08 | Function `[0x575480,0x57549A)`, 26 bytes; entry item `[0x575480,0x575481)` code; name `PacketBufferReadUInt16BE`; type `unsigned __int16 __cdecl(const unsigned __int8 *packet)`; AR/AP/FP absent; FR exactly `Canonical PacketBufferReadUInt16BE: returns packet[1] + (packet[0] << 8).`; SHA256 `7727388AE664CC923A45C7A48ED615BC2B37978B5939C4B055DFDFD441B9DDCF`; 372 inbound xrefs; complete frame below. | `already present`; protection-only, no write payload. No rename, type, comment, frame, boundary, or byte operation is authorized. | Every listed field remains exact throughout the sequence; total inbound xrefs remains 372 with no pagination remainder. |

I05 exact bytes are `8B 54 24 08 8D 42 0C 8B 8A 14 FA FF FF 33 C8 E8 80 D4 FC FF 8B 4A FC 33 C8 E8 76 D4 FC FF B8 E0 8A 65 00 E9 A9 F2 FC FF`.

**Current and expected target frame, identical after I01-I07:**

| Name | Offset | Size | Type |
| --- | ---: | ---: | --- |
| `var_5E8` | `0x10` | `0x4` | `_DWORD` |
| `var_5E4` | `0x14` | `0x4` | `int` |
| `var_5E0` | `0x18` | `0x4` | `int` |
| `packedDate` | `0x1C` | `0x4` | `int` |
| `packedTime` | `0x20` | `0x4` | `int` |
| `var_5D4` | `0x24` | `0x4` | `_DWORD` |
| `var_5D0` | `0x28` | `0x4` | `_DWORD` |
| `var_5CC` | `0x2C` | `0x4` | `_DWORD` |
| `var_5C8` | `0x30` | `0x4` | `_DWORD` |
| `var_5C1` | `0x37` | `0x1` | `_BYTE` |
| `value` | `0x38` | `0x2B0` | `RankingCategoryRecord` |
| `WideCharStr` | `0x2E8` | `0x2` | `WCHAR` |
| `MultiByteStr` | `0x4E8` | `0x100` | `CHAR[256]` |
| `var_10` | `0x5E8` | `0x4` | `_DWORD` |
| `var_C` | `0x5EC` | `0x4` | `_DWORD` |
| `var_4` | `0x5F4` | `0x4` | `_DWORD` |
| `__saved_registers` | `0x5F8` | `0x4` | `_DWORD` |
| `__return_address` | `0x5FC` | `0x4` | `_UNKNOWN *` |
| `arg_0` | `0x600` | `0x4` | `_DWORD` |
| `arg_4` | `0x604` | `0x4` | `_DWORD` |

**Current and expected UInt16 helper frame, identical:**

| Name | Offset | Size | Type |
| --- | ---: | ---: | --- |
| `__saved_registers` | `0x0` | `0x4` | `_DWORD` |
| `__return_address` | `0x4` | `0x4` | `_UNKNOWN *` |
| `packet` | `0x8` | `0x4` | `const unsigned __int8 *` |

**Ordering, collision, dependency, rollback, and stop rules:**

1. Before I02, re-list sessions, run the exact attestation/health/read payloads above, reproduce all I01-I08 pre-state and both complete frames, and create/verify the supervisor-owned collision-safe backup. A stale session, alternate IDB, omitted response field, endpoint error, incomplete xref page, or any mismatch stops with zero writes and no save.
2. No `define_code`, `define_func`, `make_data`, `declare_type`, `set_type`, `rename`, stack/local/frame, byte patch, ordinary address comment, or function-regular comment operation is authorized. There is no rename collision or type dependency to resolve. Any attempted substitution is outside this report and fails Gate 2B.
3. Apply only I02, I03, I05, I06, and I07, in that order. Each write is a separate singleton payload exactly as printed. I04 and I08 are protection-only and receive no write.
4. Because the current comment endpoints have no `stop_on_error` argument, require the singleton result row and immediate same-address `get_comments` readback before proceeding. After each successful write, rerun all preflight reads for every entity whose graph could be affected; after I07, rerun the complete seven-entity item/comment/byte/xref set plus both frames.
5. Any write error, missing result row, wrong address, wrong comment channel/text, pre-state drift, unexpected entity/frame/xref/byte delta, or readback omission stops all later writes and prohibits save. Clear only comments introduced by successful I02/I03/I05/I06/I07 calls, in reverse successful-write order, using the same singleton endpoint with `comment:""`; immediately prove the restored channel is absent and all protected state is exact. Never clear or rewrite I04 AP or I08 FR.
6. If reverse clearing fails or any protected state cannot be restored exactly, abandon the dirty worker and use the supervisor-owned verified backup/rollback procedure; do not save the dirty IDB. B005 supplies no operational rollback program.
7. On full success, B005 still performs and authorizes no save. The supervisor may perform the single lifecycle save only under separate Gate 2B authority after final all-entity readback succeeds, then must independently re-attest and read back the saved canonical IDB.


