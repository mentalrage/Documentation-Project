# UID0003WS RankingCategoryCollection ParseInitialCategoryPageResponse Empty-Emitter Source Quality
** TARGET-REPORT-UID:0003WS **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Current recommendation: accepted and implemented for UID0003WS and the six authorized support documents. UID0003WS now emits `void RankingCategoryCollection::ParseInitialCategoryPageResponse(const unsigned char *packet)` through the existing UID0000BK child-emitter route.
- Final disposition: `[0x0045c560,0x0045cb0a)` remains one source-authored opcode `0x7D`, subcommand `3` parser; target formal CPP is populated, target formal H remains blank, and target metadata is `93/93` with owner/emitter `0000BK`, reconstructable true, and blank child position.
- Implemented support: UID0000BL now contains the narrow `friend class RankingCategoryCollection;` access needed for the proved direct page-metadata stores while its fields remain private. UID0000BK, UID0001ZC, UID0001VN, UID0000Y9, and UID0000MZ carry the accepted source/access/layout/file detail without score changes.
- Collision history and current truth: UID0003WT was not edited by B001 because B003 held the active primary assignment; B003 later independently incorporated and executed the same no-reserved-footer correction. C31 is checked as already-present.
- Corrected target claim: UID0003WS does not write `m_reservedLocalPlayerFooter[0x40]`. Its optional local block writes loaded category id, local rank, local score, and state only. B003 independently incorporated and executed the equivalent sibling correction.
- Confidence: high for behavior, range, ABI return, packet layout, source placement, container abstraction, and first-draft C++; medium-high for retail spelling, friendship as the original access mechanism, and exact retail compiler instrumentation.

## Supporting Research

- The initial Gate 1 report-only snapshot is preserved for provenance: target SHA256 `FF0A2EE1D30CE66E23DD479505858999B0A7BCB449D45C04C81FBBEDCCFC2BFF`, 8,807 bytes, 82 physical lines; generated CPP/H command `000000023592` showed one declaration and one empty marker without a definition.
- Gate 1 passed exact report SHA256 `67740A1A9B9131430197A410485B6AD5076C50439CF93A9DA2C1E09801D2A4BE`; the supervisor then authorized the seven ordinary destinations implemented by this callback.
- Dated ordinary-callback target receipt after scoped validation: SHA256 is recorded in Section 32, metadata `93/93`, complete formal CPP, blank formal H, owner/emitter `0000BK`, reconstructable true, and blank position.
- Dated ordinary-callback generated timeline, captured 2026-08-14: B001-issued scoped wait command `000000023647` completed first; initial validator-owned generated command `000000023648` followed; later validator-owned foreground command `000000023654` produced the callback snapshot. In that dated snapshot, `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp` had SHA256 `D55C7932EA674F89FC30E0BE048C6AE869AEEBD1ED272160E716B990AA4D8D7D`, 64,895 bytes, 1,801 lines, and `RankingDialog.h` had SHA256 `E472F5C6B7853E66D3944A8A1F0E4349586541EE2867612FB3DE219BBF6F5B77`, 2,601 bytes, 86 lines. Both dated headers identified command `000000023654`, refreshed `2026-08-14T19:02:07-04:00`; a five-second callback reread found those identities stable. These command/hash identities are historical receipt data only: the supervisor establishes validator-owned generated authority dynamically at Gate 2A and final verification, and later refreshes may advance without invalidating coherent source content.
- In that dated callback snapshot, B001 physically read one UID0003WS definition, one existing declaration, one friend declaration, record-before-collection order, no duplicate of those entities, and no UID0003WS empty marker. C34 remains unchecked and supervisor-owned because every later gate requires a fresh supervisor readback of validator-owned generated output.
- Relevant accepted support reports were treated as corroboration only: B005 UID0003WR SHA256 `D7F8A56597262A670EEBD07B71435BCD74076A2A627C3A697D7E04865E721F05` and B002 UID0001ZC SHA256 `7DCA17F3178752991C61DEE214535702591AF20B5CFF9E8DF3171233709324A8`.
- Live MCP evidence came from an attested read-only 2026-08-14 snapshot of canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Session identifiers and process identities are deliberately not asserted as permanent current authority.
- Dated 2026-08-15 Gate 2B evidence corrected the report's physical argument-row prediction: public `set_type` changed original `arg_0@0x84C/0x4/_DWORD` to `packet@0x84C/0x4/const unsigned __int8 *` and preserved `arg_4@0x850/0x4/_DWORD`. The supervisor stopped before I03, did not save, terminated only the unsaved stateful worker, proved canonical disk byte-identical to the pre-Gate-2B backup, reopened the canonical IDB, and verified the complete original prestate restored. This reopened-session observation is a dated clue, not permanent current authority.
- No Wave2/Wave3 material was used. Matching-report searches used UID `0003WS`, address `0x0045c560`, target name, raw name `sub_45C560`, owner UID0000BK, and source-family terms.

## Target

- Target UID: `0003WS`.
- Additional target UIDs: none.
- Target path: `by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md`.
- Role: source-authored `RankingCategoryCollection` response method for opcode `0x7D`, subcommand `3`.
- Queue row: current manual by-memory row is `87%`, reconstructable, very-strong, but describes only the broad combined parser and append addresses.
- Direct source owner/emitter: UID0000BK `by-class/RankingCategoryCollection.md`, itself emitted through UID0000MZ `by-file/RankingDialog.md` into `NexusTK/ui/dialogs/RankingDialog.cpp` and `.h`.
- Exact source-authored body: `[0x0045c560,0x0045cb0a)`, 1,450 bytes.

## Current Target State

- Metadata is now completion `93`, confidence `93`, owner `0000BK`, emitter `0000BK`, reconstructable `TRUE`, blank child position.
- Formal CPP contains the complete Section 22 method. Formal H remains blank because UID0000BK owns the one declaration.
- PacketBuffer UInt16BE/UInt32BE and MemoryMan copy names are resolved; the owner preamble supplies Windows, MemoryMan, RankingDialog, and PacketBuffer dependencies; UID0000BL's narrow friendship makes private metadata stores legal.
- Current prose now records category parsing, selected category, rows, total count, outer-vector fast/growth paths, temporary cleanup, partial-success behavior, exact range/hash/xrefs, and complete no-reserved-footer evidence. The old blank-CPP and footer-write assumptions remain only as explicitly superseded history.
- Dated 2026-08-15 rollback readback restored target name `sub_45C560`, type `unsigned int __thiscall(RankingCategoryRecordVectorStorage *this, int)`, the original 28-row frame, and absent AR/AP/FR/FP. The reopened session identity is not asserted as permanently current; Gate 2B must reread this prestate.
- Dated ordinary-callback generated receipt under command `000000023654` found one definition, one declaration, one friend declaration, correct header order, and no UID0003WS empty marker. That receipt is not later-gate authority; the supervisor rereads validator-owned generated output dynamically at Gate 2A and final verification.
- The current report path and validator-owned status/history metadata are authoritative for lifecycle state; this ordinary report body makes no current execute/archive assertion.

## Executive Recommendation

UID0000BK remains the direct class owner and child emitter. Add the exact formal CPP in Section 22 to UID0003WS, leave target H blank because UID0000BK already owns the declaration, and add only the narrow record friendship shown there. Keep source in `NexusTK/ui/dialogs/RankingDialog.cpp`; do not create `RankingCategoryCollection.cpp`, move parsing into PacketBuffer, expose raw vector pointers, or emit compiler growth/EH helpers.

The source method clears and rebuilds category records, commits selection only after a matching category id is found, resets the selected record's rows and local-rank sentinel, conditionally writes four local metadata fields, parses signed-count user rows, and commits total count last. The ignored residual `EAX` is not a source return. The target can therefore emit complete first-draft C++ now.

## Supervisor Active Recheck

- Dated accepted-callback receipt: Gate 1 accepted report SHA256 `67740A1A9B9131430197A410485B6AD5076C50439CF93A9DA2C1E09801D2A4BE`; the supervisor then authorized implementation in exactly seven ordinary destinations.
- Split repair: not required. The body has one dispatcher route, one coherent packet grammar, one class owner, one source method, exact padding fences, and compiler-only external EH chunks.
- Source-bearing child readiness: implemented and scoped-validated. Packet readers, record setters, record declaration, collection declaration, MemoryMan copy route, vector abstractions, formal method, and private-access route are present.
- Neighboring UID0003WT work remained independent under B003. This callback did not edit it; B003 later independently incorporated and executed the correction, and C31 records the already-present state.

## Inference Research Guidance Check

- IDA facts, documentation facts, and inference are kept separate throughout.
- Existing names and fields were treated as hypotheses. `ParseInitialCategoryPageResponse` remains the best descriptive source name because dispatcher case `3` combines initial category-list and first-page data; exact retail spelling is unproved.
- Physical begin/end/capacity fields and calls to `sub_45D1B0` are compiler lowering of standard vectors, not authored APIs.
- The direct private metadata writes need a legal C++ access route. A narrow class friendship is preferred over public fields or invented setters because no accessor calls exist and only the collection parsers require the access.
- Existing footer-tail prose was rechecked rather than copied. Complete target and sibling decompilation disproves any packet write to `+0x26c..+0x2ab`.
- Wave2/Wave3 references were ignored as stale; none contributed evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Disposition |
| --- | --- | --- |
| Raw target name | Dispatcher case 3, complete payload grammar, owner declaration, sibling naming, and no desired-name collision support `RankingCategoryCollection::ParseInitialCategoryPageResponse`. | Descriptive, high probability; retail spelling unproved. |
| Raw unsigned return | The caller at `0x459276` ignores `EAX`; all exits carry residual count/read values; the owner H already declares `void`. | Source return is `void`; current IDA return is stale. |
| Raw packet argument | Every use is a read from the packet and current helpers accept immutable byte pointers. | Source argument is `const unsigned char *packet`. |
| Collection receiver | Current 12-byte `RankingCategoryRecordVectorStorage` UDT exactly models the first three fields; incomplete `RankingCategoryCollection` has no usable members in IDA. | Retain the storage receiver in IDA type; use the source class in C++. |
| Signed counts/cursor | Category and row counts compare 16-bit values with signed `jge/jl`; every packet address sign-extends `SI`. | Use `short` for both counts, loop indexes, and packet cursor. |
| State/presence signedness | State bytes reach setters through `movsx`; the local-player flag uses `test al` then signed `jle`. | Use `char`; only flag values `1..127` are present. |
| Length signedness | Title and row-name lengths are zero-extended from bytes. | Use `unsigned char`. |
| Text encoding | Both text paths call `MultiByteToWideChar` with code page `0`, flags `0`, explicit narrow length, and 256-wide capacity. | Use `CP_ACP`; UTF-8 and locale-independent conversions are rejected. |
| Wide buffers | Title buffer is zero-initialized once; row-name buffer is not. Both receive an indexed terminator after conversion. | Preserve distinct `wideTitle[256]` and `wideName[256]` lifetimes. |
| Row destination width | Converted names use a 256-wide temporary, then `wcscpy_s` into exact `wchar_t[32]`. | Preserve the secure 32-wide copy and its invalid-parameter behavior. |
| Record construction | Shared constant plus scalar stores establish empty vector, total 0, and loaded-id/rank/score `-1`; other spans are not initialized. | Use the existing partial default constructor; reject whole-record zeroing. |
| Private metadata access | No loaded-id/rank/score setter calls exist. Public-field promotion would weaken all consumers; invented methods lack bodies/call evidence. | Add narrow `friend class RankingCategoryCollection;`. |
| Append helpers | Fast copies and slow growth helpers exactly match `std::vector::push_back`; automatic nested-vector cleanup matches local object lifetime. | Emit ordinary `push_back`/existing record methods; no raw helper source. |
| Footer tail | Full target and UID0003WT decompilation write loaded id, rank, score, and state, but never `+0x26c..+0x2ab`. | Correct existing prose; retain the reserved field as copied but unassigned here. |
| Selection semantics | `m_selectedCategoryId` is written only after a matching newly parsed record is found. | Unmatched id returns after refreshing the category list and preserves prior collection selection. |
| Failure model | Clear occurs first; category appends, selection, metadata, and each row append commit incrementally; total commits last. | Preserve successful-prefix and partial-success behavior; reject transactional rollback. |
| Source placement | Existing class/file emitters, sibling method, generated paths, and includes all converge on RankingDialog. | Existing `RankingDialog.cpp/.h` route is unique. |

Rejected alternatives are a separate category-list plus page-parser split, UTF-8 conversion, unsigned/int cursors, packet-bounds hardening, whole-record zeroing, writes to the reserved footer, public metadata fields, new metadata setters, direct `memmove`, hand-authored range-check calls, raw begin/end/capacity operations, standalone generated-helper definitions, `RankingCategoryCollection.cpp`, and a non-void source return.

## Evidence Standards Used

- Primary evidence: live read-only IDA function analysis, decompilation, bounded disassembly, stack frame, comments, exact item boundaries, raw bytes, types, xrefs, callees, caller dispatch, and collision queries.
- Corroboration: implemented target/support docs, the dated callback generated-source receipt, manual coverage rows, and accepted reports for the sibling category parser and collection aggregate.
- Negative evidence: complete CFG and callee review, absent strings, absent alternate callers/data xrefs, zero-xref padding, no reserved-tail stores, no packet-bound checks, and no independent source helper route.
- Evidence ladder: exact binary behavior outranks prose; implemented formal declarations plus the dated callback generated receipt resolve source legality, while later generated authority is established dynamically by supervisor readback; high-probability naming/access inference is explicitly capped below original-source proof.
- Tool limitation: stripped symbols and absent retail build flags prevent exact original spelling and exact compiler-option proof, but do not block behaviorally faithful C++.

## Evidence Checked

| Evidence area | Concrete check/result |
| --- | --- |
| Live target | `sub_45C560`, size `0x5AA`, 381 instructions, 34 CFG blocks including external EH chunks, cyclomatic complexity 13, no strings. |
| Body bytes | 1,450 bytes, SHA256 `B591D9ED33B19C7B1C9E5D7B28705EC6ADE6932AC465656E72E1C4805237968B`. |
| Dispatch | `sub_459210` validates opcode `0x7D`; case 3 calls target at `0x459276`, updates max-page state, and invalidates panes 1 and 2. |
| Xrefs | Exactly one inbound target code xref, `0x459276`; no target data xrefs or callback/table route. |
| Packet grammar | Complete category loop, selected id, signed-positive optional local block, signed row loop, and final total read traced instruction by instruction. |
| Types | `RankingCategoryRecord` size 688 with 15 exact members; `RankingUserEntry` size 76 with four exact members; storage UDT size 12 with begin/end/capacity. |
| Boundary | Ten `CC` bytes before target and six `CC` bytes after target, both single data items with zero xrefs; successor starts at `0x45CB10`. |
| EH | Cleanup `[0x5FA2C3,0x5FA2CE)`, shared tail `[0x45BF50,0x45BF5B)`, handler `[0x5FA2CE,0x5FA2F6)`, and FuncInfo `[0x658ABC,0x658AE0)` verified. |
| Helpers | UInt16/UInt32 readers, MemoryMan wrapper, packed-time setters, copy/growth/destroy helpers, secure wide copy, Win32 conversion, security cookie, and range-check support verified. |
| Docs | Target, UID0000BK, UID0000BL, UID0001VN, UID0000MZ, UID0001ZC, UID0000Y9, UID0003WR, UID0003WT, UID0003X1, reset and append pages read; the seven authorized ordinary destinations were edited, scoped-validated, hashed, and reread. |
| Manual coverage | Current UID0003WS, UID0001ZC, UID0000Y9, UID0000BK, UID0000BL, UID0000MZ, and UID0001VN rows read; UID0003WT row is absent. |
| Generated | Validator-owned command `000000023648` output physically read: one target definition, one declaration, one friend declaration, record before collection, no duplicates, and no UID0003WS empty marker. |
| Reports | Exact UID/address/name/raw-name/owner/source-family searches found no qualifying direct UID0003WS report; relevant B005/B002 support reports were opened. |
| Skipped | No IDA mutation, manual generated/coverage edit, lifecycle command, execute_report, move/archive, UID0003WT edit, or rebuild codegen test was performed. Scoped validators and their validator-owned generated refresh were the only project tooling used. |

## Claim And Incorporation Ledger

Every row is independently actionable. Section 33 repeats the same eight fields verbatim and adds only `Done`. Final allocation is exactly 35 checked claims and 13 unchecked supervisor-owned proposed claims.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 0003WS | The exact source-authored target is opcode 0x7D subcommand 3 method range [0x45C560,0x45CB0A), owned and emitted by UID0000BK. | High | Live function, dispatcher, owner declaration, one inbound call | UID0003WS Status/Evidence/formal CPP | incorporate | applied |
| C02 | 0003WS | The parser clears m_records first, destroying nested row vectors while retaining outer capacity. | High | Entry destruction loop and end=begin store | UID0003WS clear/failure sections | incorporate | applied |
| C03 | 0003WS | Category count and packet cursor are signed short; zero or negative narrowed counts append no categories. | High | 16-bit signed comparisons and MOVSX SI packet addressing | UID0003WS wire contract/formal CPP | incorporate | applied |
| C04 | 0003WS | Each category record reads BE32 id, start date/time, end date/time, signed state byte, unsigned title length, and title bytes in that order. | High | Complete category-loop call and offset trace | UID0003WS category wire table | incorporate | applied |
| C05 | 0003WS | Category titles use MemoryMan copy, a narrow terminator, CP_ACP conversion into a zero-initialized wchar_t[256], indexed wide terminator, and secure record-title copy. | High | Calls and local-array instrumentation at 0x45C6D0-0x45C7AC | UID0003WS text behavior/formal CPP | incorporate | applied |
| C06 | 0000BL | Each stack category uses the partial default constructor: empty row vector, total 0, loaded id/rank/score -1, with other spans intentionally uninitialized until assigned. | High | Shared constant 0x610BB0 and adjacent scalar stores | UID0000BL/UID0001VN constructor evidence | incorporate | applied |
| C07 | 0003WS | Category fields are populated through the existing record setter surface before one ordinary m_records.push_back. | High | Setter calls/direct inlining and owner H surface | UID0003WS construction/formal CPP | incorporate | applied |
| C08 | 0003WS | Category push_back uses fast deep copy at 0x45C7CB or UID0003X0 growth at 0x45C7DC, then destroys the temporary nested vector at 0x45C7EE. | High | Branch, calls, end advance, EH cleanup | UID0003WS append/lifetime sections | incorporate | applied |
| C09 | 0003WS | The parser reads BE32 selectedCategoryId after the category list and searches only the newly rebuilt records. | High | 0x45C80D read and 0x2B0-stride lookup | UID0003WS selection section/formal CPP | incorporate | applied |
| C10 | 0003WS | If no category id matches, the refreshed list remains but m_selectedCategoryId and row/total state are not newly committed. | High | Early return before collection +0x0C store | UID0003WS partial-success section | incorporate | applied |
| C11 | 0003WS | On a match, collection selection is committed, selected rows are cleared without freeing capacity, and local rank becomes -1. | High | Stores at 0x45C887, 0x45C8A2, 0x45C8AD | UID0003WS selected-record transition/formal CPP | incorporate | applied |
| C12 | 0003WS | The optional-local flag is signed char; only values 1 through 127 enter the metadata block. | High | TEST AL followed by signed JLE | UID0003WS local metadata contract | incorporate | applied |
| C13 | 0003WS | Present local metadata writes loadedRowsCategoryId, localPlayerScore, localPlayerRank, and state; it never writes the reserved 0x40 footer tail. | High | Exact stores at 0x45C90B/17/23/29 and complete negative store scan | UID0003WS and UID0001VN field mapping | incorporate | applied |
| C14 | 0003WS | Row count is a signed short; negative narrowed counts skip rows and still read the total at the current cursor. | High | UInt16 read and signed 16-bit loop comparisons | UID0003WS row contract/formal CPP | incorporate | applied |
| C15 | 0003WS | Each row uses unsigned byte name length, MemoryMan copy, CP_ACP conversion into wchar_t[256], then wcscpy_s into the exact wchar_t[32] row field. | High | 0x45C960-0x45CA36 trace and row UDT | UID0003WS row-text section/formal CPP | incorporate | applied |
| C16 | 0003WS | Each 0x4C row contains selected category id, BE32 rank, name[32], and BE32 score; score is set to -1 before secure name copy and then replaced. | High | Stack layout and stores at 0x45CA10-0x45CA4A | UID0003WS row layout/formal CPP | incorporate | applied |
| C17 | 0003WS | Row append is ordinary RankingCategoryRecord::AppendUserEntry/std::vector push_back; sub_45D1B0 is compiler growth plumbing and must not enter authored source. | High | Fast 0x4C copy, growth call 0x45CAA9, shared helper xrefs | UID0003WS helper/source boundary | incorporate | applied |
| C18 | 0003WS | Total rank count is the final BE32 field and commits only after all requested rows append successfully. | High | Final read/store at 0x45CAD4/0x45CAE2 | UID0003WS total/failure sections | incorporate | applied |
| C19 | 0003WS | The target performs no packet null/length check, count sanity check, encoding validation, explicit conversion-error branch, or transactional rollback. | High | Complete CFG/callee/branch negative review | UID0003WS negative evidence | incorporate | applied |
| C20 | 0003WS | Failures preserve incremental state: old list is already gone, successful category/row prefixes remain, selection/metadata may be committed, and total may remain uncommitted. | High | Operation ordering plus EH map and vector guarantees | UID0003WS failure/lifetime section | incorporate | applied |
| C21 | 0003WS | Source return type is void; all binary return values are residual and the sole caller ignores EAX. | High | Caller at 0x459276 and all exits | UID0003WS signature/formal CPP | incorporate | applied |
| C22 | 0000MZ | The unique source route is RankingDialog.cpp with declarations in RankingDialog.h; PacketBuffer and new-file placements are rejected. | High | Owner/file docs, sibling source, generated paths | UID0000MZ source placement | incorporate | applied |
| C23 | 0003WS | The exact formal CPP is the complete method in Section 22 and contains no IDA/compiler-generated names. | High | Full live behavior plus resolved dependencies | UID0003WS RECONSTRUCTION_CPP | incorporate | applied |
| C24 | 0003WS | Target formal H remains blank because UID0000BK already owns the one declaration. | High | Current owner H and generated H readback | UID0003WS RECONSTRUCTION_H | already-present | already-present |
| C25 | 0000BL | Add only friend class RankingCategoryCollection to legalize the proved direct private page-metadata access; retain private fields and existing layout. | Medium-high | Direct stores, absent setter calls, narrow caller family | UID0000BL formal H/access notes | incorporate | applied |
| C26 | 0003WS | Raise target metadata from 87/90 to 93/93 while retaining owner/emitter 0000BK, reconstructable true, and blank child position. | Medium-high | Source closure with bounded retail spelling/compiler caps | UID0003WS metadata | incorporate | applied |
| C27 | 0003WS | Preserve all valid target history but historicalize the blank-CPP blocker and reserved-footer-write claim as superseded by current evidence. | High | Current doc comparison against live MCP and support declarations | UID0003WS Status/Evidence/Changes | reject-stale | excluded-with-reason |
| C28 | 0000BK | Update the collection class and UID0001ZC aggregate with complete source-ready subcommand-3 behavior while retaining their scores and nonduplicate emitter roles. | High | Exact child/parent/source route | UID0000BK and UID0001ZC | incorporate | applied |
| C29 | 0000BL | Update record class, UID0001VN layout, and UID0000Y9 aggregate with friendship, exact local-field writes, and no reserved-tail write while retaining scores. | High | UDT, parser stores, paint/layout evidence | UID0000BL/UID0001VN/UID0000Y9 | incorporate | applied |
| C30 | 0000MZ | Update RankingDialog by-file source contract with the complete combined parser and narrow friendship while retaining 88/91. | High | Existing compilation-unit route and generated output | UID0000MZ source contract/Changes | incorporate | applied |
| C31 | 0003WT | B003 independently incorporated and executed the UID0003WT no-reserved-footer correction; the sibling now records that its parser does not write the reserved 0x40 footer tail. | High | Independent B003 implementation/execution completion plus complete 0x45CB10 decompilation | UID0003WT metadata/page transition/history | already-present | already-present |
| C32 | 0003WS | Replace the stale manual UID0003WS and UID0001ZC coverage rows with the exact Section 28 text after callback verification. | High | Current rows omit source closure and corrected local behavior | Manual by-memory coverage | incorporate | proposed |
| C33 | 0000BK | Replace or insert the exact affected class/file/type/aggregate/support coverage rows listed in Section 28; B001 must not edit them. | High | Read-only manual coverage comparison | Manual coverage files | incorporate | proposed |
| C34 | 0003WS | The dated B001 ordinary-callback readback for validator-owned command 000000023654 showed one method definition, one existing declaration, one friend declaration, required includes/order, and no UID0003WS empty marker; at every later gate the supervisor rereads validator-owned generated output dynamically because command/hash identities may advance. | High | Dated callback generated CPP/H hashes and physical B001 readback | Supervisor generated readback | already-present | proposed |
| C35 | 0003WS | The body hash and exact ten-byte predecessor/six-byte successor CC fences define the target without split or range extension. | High | Raw MCP bytes, hashes, zero-xref item checks | UID0003WS range section | incorporate | applied |
| C36 | 0003WS | One caller and the complete sixteen-callee material set exhaust target reachability; external EH chunks are compiler-owned, not source children. | High | Bounded xrefs, callees, CFG chunks | UID0003WS inventories | incorporate | applied |
| C37 | 0003WS | The dated restored IDA type/frame/comments and support UDTs are exactly recorded in Section 21; dynamic state must be reread before Gate 2B. | High | Live stack/type/comment/item queries plus verified fail-closed rollback | Supervisor Gate 2B handoff | already-present | proposed |
| C38 | 0003WS | I01 is target-chain stage 1: pure rename from the original literal state to the exact post-I01 name while preserving the old type, all 28 frame rows, AR/AP/FR/FP, range/size/body hash/bytes, and exact code/data xrefs. | High | Unique behavior, collision-free desired name, complete I01 pre/post contract | Supervisor Gate 2B target chain I01 stage 1 | incorporate | proposed |
| C39 | 0003WS | I02 is target-chain stage 2 and may start only from the complete I01 poststate; set_type retains the post-I01 name/storage receiver, changes only `arg_0@0x84C/0x4/_DWORD` to `packet@0x84C/0x4/const unsigned __int8 *`, preserves `arg_4@0x850/0x4/_DWORD`, the other 26 rows, and all non-type state, and produces the complete required I03 prestate. | High | Observed public set_type readback, ignored return, immutable packet reads, usable storage UDT, complete staged frame/type contract | Supervisor Gate 2B target chain I02 stage 2 | incorporate | proposed |
| C40 | 0003WS | I03 is target-chain stage 3 and may start only from the complete I02 poststate; it changes only FP from absent to the exact behavior text while preserving the post-I02 name/type/all 28 rows, including `packet@0x84C/0x4/const unsigned __int8 *` and unchanged `arg_4@0x850/0x4/_DWORD`, plus AR/AP/FR, range/size/body hash/bytes, and exact code/data xrefs. | High | Complete packet semantics and complete corrected staged comment contract | Supervisor Gate 2B target chain I03 stage 3 | incorporate | proposed |
| C41 | 0003WS | I04 applies only the exact cleanup-chunk repeatable address comment through public semantic channel set_address_repeatable_comments; deterministic channels are independently AR absent, AP equal to the exact I04 proposed text, FR not independently applicable, and FP not independently applicable. | High | EH map, stack offset, shared-tail route | Supervisor Gate 2B I04 | incorporate | proposed |
| C42 | 0003WS | I05 preserves without mutation the already-present shared-tail channels and routes: AR absent, AP equal to the exact existing text, FR not independently applicable, and FP not independently applicable. | High | Current literal AP and two inbound cleanup jumps | Supervisor Gate 2B I05 | already-present | proposed |
| C43 | 0003WS | I06 and I07 apply only exact repeatable address comments: I06 independently protects AR absent, AP equal to the exact I06 proposed text, FR not independently applicable, and FP not independently applicable; I07 independently protects AR absent, AP equal to the exact I07 proposed text, FR not applicable, and FP not applicable. | High | Prologue handler ref, FuncInfo pointer, unwind map | Supervisor Gate 2B I06/I07 | incorporate | proposed |
| C44 | 0000BL | I08 preserves without mutation the constructor-constant channels, 16 bytes, and two parser xrefs: AR absent, AP equal to the exact existing text, FR not applicable, and FP not applicable. | High | Current item/comment/raw bytes/xrefs | Supervisor Gate 2B I08 | already-present | proposed |
| C45 | 0003WS | No target-local string, global, resource, vtable, RTTI, alternate owner, source-authored helper, new split, or independent source file exists. | High | Complete negative scans and boundary/owner analysis | UID0003WS negative/range/ownership sections | incorporate | applied |
| C46 | 0003WS | Remaining uncertainty is limited to retail spellings, exact original friendship syntax, packet-size metadata, and compiler instrumentation; it caps 93/93 but does not block source emission. | Medium-high | Exhausted current binary/docs/generated/report routes | UID0003WS score/open questions | incorporate | applied |
| C47 | 0003WS | The accepted callback changed only the seven authorized ordinary docs and this report, used scoped validators without manual generated/coverage edits, made no IDA mutation, and did not run execute_report or lifecycle commands. | High | Authorized destination audit, scoped receipts, lease and prohibited-action checks | Validator Results/Changed Files | already-present | proposed |
| C48 | 0003WS | This report contains no executable scripting or operational runbook; only formal C++ insertion text appears in typed fences. | High | Final literal fence and scripting-token audit | Report hygiene/Validator Results | already-present | proposed |

## Positive Evidence Summary

- The dispatcher uniquely maps opcode `0x7D` subcommand `3` to `0x45C560`, then refreshes both ranking panes.
- Full decompilation and disassembly agree on every packet field, signed comparison, append path, commit point, and early return.
- Existing source declarations already provide `RankingCategoryCollection`, `RankingCategoryRecord`, `RankingUserEntry`, PacketBuffer readers, record methods, and the correct source file.
- The sibling subcommand-1 parser establishes the exact category construction/text pattern; the sibling subcommand-2 parser independently confirms row layout and optional-local field stores.
- Compiler helpers and EH chunks map cleanly to ordinary C++03 vector and automatic-object behavior.
- The strongest inference chain is dispatcher role plus exact payload grammar plus existing class declaration plus generated path. It supports a complete method even though retail symbols are stripped.

## IDA MCP Facts

- Dated restored function prestate: `sub_45C560`, `[0x45C560,0x45CB0A)`, size `0x5AA`, 381 instructions, 34 blocks including external chunks, complexity 13.
- Dated restored prototype: `unsigned int __thiscall(RankingCategoryRecordVectorStorage *this, int)`.
- Body SHA256: `B591D9ED33B19C7B1C9E5D7B28705EC6ADE6932AC465656E72E1C4805237968B`.
- First 16 bytes: `55 8B EC 6A FF 68 CE A2 5F 00 64 A1 00 00 00 00`.
- Last 16 bytes: `E8 30 AC 16 00 8B E5 5D C2 04 00 E8 4B AB 16 00`.
- Sole inbound code xref: `0x459276` in `sub_459210`; no data xref.
- Complete material-callee set: exactly 16 unique identities, M01-M16 in Sections 14-15: `RankingUserEntryVectorDestroy`, `PacketBufferReadUInt16BE`, `_memset`, `PacketBufferReadUInt32BE`, narrow-character access lowering, `GetMemoryMan`, `MemoryMan_MemmoveWrapper`, `MultiByteToWideChar`, `RankingCategoryRecord_SetStartTimeFromPackedDateTime`, `RankingCategoryRecord_SetEndTimeFromPackedDateTime`, `_wcscpy_s`, `RankingCategoryRecordCopyConstructDeep`, `RankingCategoryRecordVectorInsertWithGrowth`, `sub_45D1B0`, security-cookie check, and range-check failure. Read-only MCP accounts for 36 target-body call instructions plus two external-handler cookie checks across those identities.
- `RankingCategoryRecord`: size `0x2B0`, exact scalar/tm/title/vector/loaded-id/rank/reserved/score layout.
- `RankingUserEntry`: size `0x4C`, `categoryId +0`, `rank +4`, `name[32] +8`, `score +0x48`.
- `RankingCategoryRecordVectorStorage`: size `0x0C`, typed begin/end/capacity pointers. `RankingCategoryCollection` remains an incomplete BADSIZE type in IDA.
- Desired names `RankingCategoryCollection__ParseInitialCategoryPageResponse` and `RankingCategoryCollectionParseInitialCategoryPageResponse` are collision-free in the live catalog.
- No target string, target-local global, vtable, RTTI, resource, import ownership, callback registration, jump table entry, or pointer-table route was found.
- Gate 2B observed behavior on 2026-08-15: after successful G01-G06 readbacks, public `set_type` at G07 accepted the proposed signature and changed exactly one physical frame row, original `arg_0@0x84C/0x4/_DWORD` to `packet@0x84C/0x4/const unsigned __int8 *`; `arg_4@0x850/0x4/_DWORD` and the other 26 rows remained exact. The prior opposite-row prediction was an extraction/contract error corrected by this report.
- Fail-closed transaction and rollback evidence, dated 2026-08-15: canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` and backup `E:\NTK\Resources\NexusTK\NexusTK.exe.uid0003WS-pre-gate2b-20260815T031116Z.i64` were each 143,207,794 bytes with SHA256 `61FBD1CA765796F70F0C4BC9D44251761BE86836C827F7FE6AB770F4C9DA3E82`. The failed mutation remained unsaved; the supervisor stopped before G08/I03, terminated only the unsaved stateful worker, reopened the canonical IDB, and verified the complete original prestate restored.
- Exact reopened rollback readback: target name `sub_45C560`; desired target name absent; original type and all 28 original frame rows restored, including `arg_0@0x84C/0x4/_DWORD` and `arg_4@0x850/0x4/_DWORD`; target AR absent; target AP absent; target FR absent; target FP absent. I04 AR absent; I04 AP absent; I04 FR not independently applicable; I04 FP not independently applicable. I06 AR absent; I06 AP absent; I06 FR not independently applicable; I06 FP not independently applicable. I07 AR absent; I07 AP absent; I07 FR not applicable; I07 FP not applicable. I05 AR absent; I05 AP exactly `Shared compiler EH cleanup tail for stack-local RankingCategoryRecord: adjust this to m_userEntries at +0x258, then tail-jump to RankingUserEntryVectorDestroy.`; I05 FR not independently applicable; I05 FP not independently applicable. I08 AR absent; I08 AP exactly `Shared inlined RankingCategoryRecord default-construction constant: null m_userEntries triplet followed by m_loadedRowsCategoryId = -1; used by category-list and initial-page parsers.`; I08 FR not applicable; I08 FP not applicable. This session identity is dated evidence only and must be reread before execution.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x45C560,0x45CB0A)` | UID0003WS target | Source-authored combined initial category/page parser | true | UID0000BK | historical pre-callback 87/90 -> current implemented 93/93 | formal CPP implemented; target H intentionally blank because UID0000BK owns the declaration |
| `[0x5FA2C3,0x5FA2CE)` | target external chunk | Automatic category-record cleanup to shared tail | compiler-covered | UID0003WS EH graph | not separate | no source body |
| `[0x45BF50,0x45BF5B)` | shared external chunk | Adjusts to record `m_userEntries` and tail-jumps to destroy | compiler-covered | shared UID0003WR/UID0003WS EH | not separate | existing comment protected |
| `[0x5FA2CE,0x5FA2F6)` | `SEH_45C560` | MSVC handler/security-cookie/CxxFrameHandler route | compiler-covered | UID0003WS EH graph | not separate | no source body |
| `[0x658ABC,0x658AE0)` | `stru_658ABC` | Target MSVC FuncInfo referencing unwind map `0x658AAC` | compiler data | UID0003WS EH graph | not separate | no source declaration |
| `[0x610BB0,0x610BC0)` | `xmmword_610BB0` | Shared partial record-constructor constant | compiler-folded data | UID0000BL | not separate | existing comment protected |
| `0x45D5F0` | UID0003YT | M01 `RankingUserEntryVectorDestroy`: user-row vector storage teardown | false/non-emitting | UID0000BL | reviewed support | compiler-covered; ordinary vector lifetime regenerates it, so no authored helper body |
| `0x575480` | UID0003YK family | M02 `PacketBufferReadUInt16BE`: shared BE16 packet reader | true | PacketBuffer | reviewed source | existing authored dependency |
| `0x5CA0B0` | CRT/runtime | M03 `_memset`: fixed wide-title zero fill | runtime/intrinsic | CRT/compiler runtime | not separate | source uses a zero-initialized local array; no authored helper body |
| `0x5754C0` | UID0003YK family | M04 `PacketBufferReadUInt32BE`: shared BE32 packet reader | true | PacketBuffer | reviewed source | existing authored dependency |
| `0x575470` | standard-library lowering | M05 narrow-character access lowering: `std::_Narrow_char_traits<char,int>::to_char_type` | compiler/library lowering | standard library | not separate | direct narrow-byte access regenerates it; exclude from authored source |
| `0x516030` | MemoryMan route | M06 `GetMemoryMan`: obtains the existing memory-manager singleton | true/shared | MemoryMan | reviewed source | existing authored dependency |
| `0x516220` | MemoryMan route | M07 `MemoryMan_MemmoveWrapper`: copies packet title/name bytes | true/shared | MemoryMan | reviewed source | existing authored dependency through `GetMemoryMan()->MemmoveWrapper` |
| `0x60D120` | Win32 import | M08 `MultiByteToWideChar`: CP_ACP title/name conversion | external API | Windows | not separate | retain direct Win32 API call; no project helper body |
| `0x45C050` | UID0002K7 | M09 `RankingCategoryRecord_SetStartTimeFromPackedDateTime` | true | UID0000BL | 91/94 | existing source method |
| `0x45C100` | UID0002K8 | M10 `RankingCategoryRecord_SetEndTimeFromPackedDateTime` | true | UID0000BL | 91/94 | existing source method |
| `0x5CD657` | secure CRT | M11 `_wcscpy_s`: bounded copy into record title and row name | runtime API | CRT | not separate | retain source-level `wcscpy_s`; no project helper body |
| `0x45D420` | UID0003X4 | M12 `RankingCategoryRecordCopyConstructDeep`: implicit record deep copy | false/non-emitting | UID0000BL | 94/95 | compiler-covered; ordinary record/vector copy regenerates it |
| `0x45CF50` | UID0003X0 | M13 `RankingCategoryRecordVectorInsertWithGrowth`: outer record-vector growth | false/non-emitting | UID0000BK | 94/95 | compiler-covered; ordinary `m_records.push_back` regenerates it |
| `0x45D1B0` | UID0003X1 | M14 user-row vector full-capacity growth specialization | source-regenerated/non-standalone | UID0000BL | 86/90 | ordinary `AppendUserEntry`/vector append regenerates it; no authored helper body here |
| `0x5C772F` | compiler runtime | M15 `@__security_check_cookie@4`: target/handler cookie validation | compiler runtime | MSVC runtime | not separate | compiler instrumentation only; exclude from authored source |
| `0x5C7655` | compiler runtime | M16 `___report_rangecheckfailure`: fixed-array bounds failure route | compiler runtime | MSVC runtime | not separate | compiler instrumentation from indexed fixed arrays; exclude explicit authored call |
| Generated RankingDialog.cpp/.h | UID0000MZ route | Physical method definition/declaration output | generated | UID0000MZ | dated 2026-08-14 callback snapshot | The dated callback receipt found exactly one definition and the required declaration/friend route, with no UID0003WS empty-emitter marker; the absent definition and retained empty marker belong only to the historical pre-callback state, and later generated authority requires fresh supervisor readback. |

Inventory totals: one source-authored target body, three compiler code chunks, two compiler data/support items, exactly 16 material callee dependencies with explicit M01-M16 dispositions, one generated CPP route, and one generated H route. No additional source-bearing child, global, table, string, vtable, RTTI, resource, or import belongs to UID0003WS.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x459276` | dispatcher calls target | Opcode `0x7D`, case `3`; only inbound target call |
| target return | caller does not consume EAX | Proves source `void` together with owner declaration |
| `0x45C5B6`, `0x45C7EE` | M01 `RankingUserEntryVectorDestroy` (`0x45D5F0`) | Two calls: clear old nested vectors, then destroy the stack temporary after category append; compiler-covered vector lifetime |
| `0x45C5DA`, `0x45C932` | M02 `PacketBufferReadUInt16BE` (`0x575480`) | Two calls: category count and row count |
| `0x45C5FB` | M03 `_memset` (`0x5CA0B0`) | One call: zero-initialize the fixed wide-title buffer; source-level zero initialization, not an authored helper |
| `0x45C62C`, `0x45C640`, `0x45C654`, `0x45C668`, `0x45C67C`, `0x45C817`, `0x45C8CB`, `0x45C8DF`, `0x45C9E8`, `0x45C9FC`, `0x45CAD4` | M04 `PacketBufferReadUInt32BE` (`0x5754C0`) | Eleven calls: category id, start/end date/time, selected category id, local rank/score, row rank/score, and total rank count |
| `0x45C690`, `0x45C6A2`, `0x45C8B8`, `0x45C8F3`, `0x45C966` | M05 narrow-character access lowering (`0x575470`) | Five calls to `std::_Narrow_char_traits<char,int>::to_char_type`; compiler/library lowering of signed-state, length, optional-local flag, and row-name length byte access |
| `0x45C6C9`, `0x45C98D` | M06 `GetMemoryMan` (`0x516030`) | Two calls: obtain the shared manager for title and row-name byte copies |
| `0x45C6D0`, `0x45C994` | M07 `MemoryMan_MemmoveWrapper` (`0x516220`) | Two calls: exact title and row-name byte copy routes |
| `0x45C6FD`, `0x45C9C1` | M08 `MultiByteToWideChar` (`0x60D120`) | Two calls: CP_ACP title and row-name conversions |
| `0x45C770` | M09 `RankingCategoryRecord_SetStartTimeFromPackedDateTime` (`0x45C050`) | One call: apply packed start date/time in source argument order |
| `0x45C787` | M10 `RankingCategoryRecord_SetEndTimeFromPackedDateTime` (`0x45C100`) | One call: apply packed end date/time in source argument order |
| `0x45C7AC`, `0x45CA36` | M11 `_wcscpy_s` (`0x5CD657`) | Two calls: bounded copy into the record title and exact `wchar_t[32]` row-name field |
| `0x45C7CB` | M12 `RankingCategoryRecordCopyConstructDeep` (`0x45D420`) | One call: fast-capacity record append path; compiler-covered implicit deep copy |
| `0x45C7DC` | M13 `RankingCategoryRecordVectorInsertWithGrowth` (`0x45CF50`) | One call: full-capacity outer record-vector append path; compiler-covered growth |
| `0x45CAA9` | M14 `sub_45D1B0` (`0x45D1B0`) | One call: full-capacity user-row vector growth; regenerated by `AppendUserEntry`/ordinary vector append |
| `0x45CAFA`, `0x5FA2DD`, `0x5FA2E7` | M15 `@__security_check_cookie@4` (`0x5C772F`) | Three calls: target epilogue plus two external-handler checks; compiler instrumentation only |
| `0x45CB05` | M16 `___report_rangecheckfailure` (`0x5C7655`) | One call: fixed-array bounds failure at the final target code item; compiler instrumentation, not authored source |
| `0x658AAC -> 0x5FA2C3` | unwind map to cleanup | Automatic local record cleanup |
| `0x5FA2C9 -> 0x45BF50` | cleanup to shared tail | Nested vector teardown route |
| `0x45C565 -> 0x5FA2CE` | prologue handler reference | Target compiler handler |
| `0x5FA2EC -> 0x658ABC` | handler to FuncInfo | Target MSVC EH metadata |
| `0x45C710 -> 0x610BB0` | constructor constant data xref | Inlined partial default construction |

Material-callee inventory: exactly 16 unique callees (M01-M16) and all 38 direct call instructions returned for the target function graph are individually assigned above: 36 calls in `[0x45C560,0x45CB0A)` plus the two external-handler cookie checks at `0x5FA2DD` and `0x5FA2E7`.

## Documentation Evidence And IDA Status

- Supporting current docs correctly establish owner/emitter placement, exact record/row layouts, packed-time setters, vector append abstractions, reset semantics, and the source-ready sibling category parser.
- Current UID0003WS formal CPP is populated with the complete accepted method source; the blank formal source and unresolved PacketBuffer/MemoryMan/class-support blocker belong only to historical pre-callback evidence.
- Initial research found stale reserved-footer-write wording in UID0003WS and UID0003WT. UID0003WS was corrected in this callback, and B003 independently incorporated and executed the equivalent UID0003WT correction; UID0001VN and UID0000BL already state that checked parsers do not write that tail.
- The dated ordinary-callback generated receipt found the required H declaration/friend route and exactly one CPP method definition with no UID0003WS empty-emitter marker; the declaration-only H and empty-marker/no-definition CPP state belong only to historical pre-callback evidence. At later gates the supervisor rereads validator-owned generated output dynamically.
- IDA's target name, return type, packet argument type, and absent comments are source-quality opportunities; support helper names/types/comments are otherwise sufficient for source reconstruction.

## Ranked Ownership Analysis

### 1. UID0000BK RankingCategoryCollection

- Evidence for: method receiver is the collection's leading vector storage; it writes collection selected id at `+0x0C`; owner H already declares the exact method; sibling methods and dispatcher use the same object facet.
- Evidence against: original class/method spelling is stripped.
- Decision: direct owner and emitter; overwhelmingly strongest.

### 2. UID0000MZ RankingDialog compilation unit

- Evidence for: dispatcher, category/record classes, sibling definitions, includes, generated path, and all UI consumers are colocated.
- Evidence against: file ownership is broader than method ownership.
- Decision: physical source file owner, not direct semantic owner.

### 3. PacketBuffer or RankingCategoryRecord

- Evidence for: PacketBuffer supplies endian readers; RankingCategoryRecord stores parsed fields.
- Evidence against: neither owns selection, the outer category vector, dispatcher case, or combined workflow.
- Decision: dependencies only; rejected as target owners.

### Proposed new file/grouping, if applicable

- Not applicable. A new file would break the established class-child emitter and sibling locality without binary or documentation support.

## Source Placement

- Definition: existing `NexusTK/ui/dialogs/RankingDialog.cpp` through UID0000BK `[[CHILDREN]]`.
- Declaration: existing `NexusTK/ui/dialogs/RankingDialog.h` through UID0000BK; target H remains blank.
- Required supporting declaration: add `friend class RankingCategoryCollection;` inside UID0000BL's class declaration, before its private metadata is used by the collection parser.
- Existing owner CPP includes already provide `<windows.h>`, `MemoryMan.h`, `RankingDialog.h`, and `PacketBuffer.h`; no new include is required.
- Rejected placements: PacketBuffer, a new collection source file, record child CPP, generated files, raw helper files, and a report-only sample source.
- Remaining uncertainty: exact original source filename is inferred from the reconstructed route, but there is no competing route.

## Range / Split / Padding / Reclassification Analysis

- Exact target body: `[0x45C560,0x45CB0A)`, 1,450 bytes, SHA256 `B591D9ED33B19C7B1C9E5D7B28705EC6ADE6932AC465656E72E1C4805237968B`.
- Predecessor padding `[0x45C556,0x45C560)` is exactly ten `CC` bytes, SHA256 `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`, one data item, zero xrefs.
- Successor padding `[0x45CB0A,0x45CB10)` is exactly six `CC` bytes, SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`, one data item, zero xrefs.
- The last target code item is `[0x45CB05,0x45CB0A)`, the range-check failure call; it is not padding.
- Successor `sub_45CB10` starts exactly at `0x45CB10` and has its own dispatcher call at `0x4592CA`.
- External cleanup, handler, and FuncInfo entities are target EH evidence but do not extend the source-authored by-memory range.
- No split, merge, range extension, reclassification, child creation, or filename change is recommended.

## Negative Evidence Summary

- No second caller, data xref, callback, vtable slot, pointer table, jump-table item, custom import, or indirect route reaches the target.
- No target-local strings, globals, resources, RTTI, vtables, or independent constants besides the shared constructor constant were found.
- No packet length, null, conversion-error, or count-sanity checks exist; adding them would alter release behavior.
- No store touches record `+0x26C..+0x2AB` in this target or UID0003WT.
- No dedicated loaded-id/rank/score setter calls exist. Public fields and invented setter bodies are weaker than narrow friendship.
- No binary evidence supports UTF-8, normalized `tm`, unsigned loops, transactional rollback, whole-record zeroing, or a non-void source API.
- Adjacent parser/helper ranges remain separate ownership items; proximity does not make them UID0003WS children.

## IDA Rename / Type / Comment Recommendations

B001 performed no IDA mutation during research, implementation, or this report-only repair. `AR` is regular address comment, `AP` repeatable address comment, `FR` regular function comment, and `FP` repeatable function comment. The one deterministic global execution order is exactly G01/I04 -> G02/I06 -> G03/I07 -> G04/I05 -> G05/I08 -> G06/I01 -> G07/I02 -> G08/I03. G01-G05 must finish while the target function name is literally `sub_45C560`; each stage requires every preceding stage's expected readback to remain exact. G06 then performs the pure target rename, so only I04/I06's containing-function label advances to `RankingCategoryCollection__ParseInitialCategoryPageResponse`; their own entity names, types, comments, ranges, bytes, hashes, xrefs, and routes remain protected. G07 and G08 require that renamed containing-function readback plus all accumulated G01-G06 readbacks. The supervisor must stop before any stage whose complete literal precondition does not match. C35-C36 are checked because their ordinary target range/inventory incorporation is implemented; C37-C44 remain unchecked and supervisor-owned, and ordinary-document implementation does not assert Gate 2B completion. Public semantic channel names identify only the supervisor-owned endpoint class; this report contains no invocation payload, transaction, persistence step, or operational runbook.

The 2026-08-15 supervisor attempt established G01-G06 exactly, then failed closed at G07 when public `set_type` exposed the report's wrong physical-row prediction. G08/I03 was not attempted, no IDB save occurred, and the stateful worker containing those unsaved changes was terminated. Canonical and backup files were each 143,207,794 bytes with SHA256 `61FBD1CA765796F70F0C4BC9D44251761BE86836C827F7FE6AB770F4C9DA3E82`; backup path was `E:\NTK\Resources\NexusTK\NexusTK.exe.uid0003WS-pre-gate2b-20260815T031116Z.i64`. Reopening canonical restored the complete original I01 prestate, so a future Gate 2B attempt begins again at G01 after fresh readback; the reopened session is dated evidence, not permanent current state.

### I01 Target chain stage 1 - pure rename

- Global stage G06 literal accumulated precondition after G05: target name remains `sub_45C560`; I04 AP is exactly `Compiler-generated UID0003WS temporary-record cleanup: passes stack RankingCategoryRecord::m_userEntries at +0x258 to the shared teardown tail.`; I06 AP is exactly `Compiler-generated UID0003WS EH handler using FuncInfo stru_658ABC; source uses automatic RankingCategoryRecord and standard vector lifetime.`; I07 AP is exactly `MSVC FuncInfo for UID0003WS ParseInitialCategoryPageResponse; unwind map includes the temporary RankingCategoryRecord nested-vector cleanup.`; I05 AP remains exactly `Shared compiler EH cleanup tail for stack-local RankingCategoryRecord: adjust this to m_userEntries at +0x258, then tail-jump to RankingUserEntryVectorDestroy.`; I08 AP remains exactly `Shared inlined RankingCategoryRecord default-construction constant: null m_userEntries triplet followed by m_loadedRowsCategoryId = -1; used by category-list and initial-page parsers.`; every G01-G05 AR/FR/FP and noncomment field has the exact expected readback stated in its complete row below.
- Complete literal I01 prestate: function `[0x45C560,0x45CB0A)`, size 1,450 bytes; entry item `[0x45C560,0x45C561)` code; name `sub_45C560`; type `unsigned int __thiscall(RankingCategoryRecordVectorStorage *this, int)`; AR absent; AP absent; FR absent; FP absent; body SHA256 `B591D9ED33B19C7B1C9E5D7B28705EC6ADE6932AC465656E72E1C4805237968B`; first 16 bytes `55 8B EC 6A FF 68 CE A2 5F 00 64 A1 00 00 00 00`; last 16 bytes `E8 30 AC 16 00 8B E5 5D C2 04 00 E8 4B AB 16 00`; exact inbound code xrefs `{0x459276}`; exact inbound data xrefs `{}`; no callback/table xref; desired name collision-free.
- Complete literal I01 prestate frame, 28 rows:

| Name | Offset | Size | Type |
| --- | ---: | ---: | --- |
| `packedTime` | `0xC` | `0x4` | `int` |
| `var_834` | `0x10` | `0x4` | `_DWORD` |
| `cbMultiByte` | `0x14` | `0x4` | `int` |
| `var_82C` | `0x18` | `0x4` | `int` |
| `packedDate` | `0x1C` | `0x4` | `int` |
| `var_824` | `0x20` | `0x4` | `RankingCategoryRecordVectorStorage *` |
| `var_820` | `0x24` | `0x4` | `_DWORD` |
| `var_819` | `0x2B` | `0x1` | `_BYTE` |
| `var_818` | `0x2C` | `0x4` | `_DWORD` |
| `var_814` | `0x30` | `0x4` | `int` |
| `var_810` | `0x34` | `0x4` | `_DWORD` |
| `value` | `0x38` | `0x2B0` | `RankingCategoryRecord` |
| `var_55C` | `0x2E8` | `0x10` | `wchar_t[8]` |
| `var_54C` | `0x2F8` | `0x10` | `_OWORD` |
| `var_53C` | `0x308` | `0x10` | `_OWORD` |
| `var_52C` | `0x318` | `0x10` | `_OWORD` |
| `var_51C` | `0x328` | `0x8` | `_QWORD` |
| `var_514` | `0x330` | `0x4` | `_DWORD` |
| `Source` | `0x334` | `0x2` | `WCHAR` |
| `WideCharStr` | `0x534` | `0x2` | `WCHAR` |
| `MultiByteStr` | `0x734` | `0x100` | `CHAR[256]` |
| `var_10` | `0x834` | `0x4` | `_DWORD` |
| `var_C` | `0x838` | `0x4` | `_DWORD` |
| `var_4` | `0x840` | `0x4` | `_DWORD` |
| `__saved_registers` | `0x844` | `0x4` | `_DWORD` |
| `__return_address` | `0x848` | `0x4` | `_UNKNOWN *` |
| `arg_0` | `0x84C` | `0x4` | `_DWORD` |
| `arg_4` | `0x850` | `0x4` | `_DWORD` |

- Complete expected I01 poststate: function `[0x45C560,0x45CB0A)`, size 1,450 bytes; entry item `[0x45C560,0x45C561)` code; name `RankingCategoryCollection__ParseInitialCategoryPageResponse`; type `unsigned int __thiscall(RankingCategoryRecordVectorStorage *this, int)`; AR absent; AP absent; FR absent; FP absent; body SHA256 `B591D9ED33B19C7B1C9E5D7B28705EC6ADE6932AC465656E72E1C4805237968B`; first 16 bytes `55 8B EC 6A FF 68 CE A2 5F 00 64 A1 00 00 00 00`; last 16 bytes `E8 30 AC 16 00 8B E5 5D C2 04 00 E8 4B AB 16 00`; exact inbound code xrefs `{0x459276}`; exact inbound data xrefs `{}`; no callback/table xref.
- Complete expected I01 poststate frame, 28 rows:

| Name | Offset | Size | Type |
| --- | ---: | ---: | --- |
| `packedTime` | `0xC` | `0x4` | `int` |
| `var_834` | `0x10` | `0x4` | `_DWORD` |
| `cbMultiByte` | `0x14` | `0x4` | `int` |
| `var_82C` | `0x18` | `0x4` | `int` |
| `packedDate` | `0x1C` | `0x4` | `int` |
| `var_824` | `0x20` | `0x4` | `RankingCategoryRecordVectorStorage *` |
| `var_820` | `0x24` | `0x4` | `_DWORD` |
| `var_819` | `0x2B` | `0x1` | `_BYTE` |
| `var_818` | `0x2C` | `0x4` | `_DWORD` |
| `var_814` | `0x30` | `0x4` | `int` |
| `var_810` | `0x34` | `0x4` | `_DWORD` |
| `value` | `0x38` | `0x2B0` | `RankingCategoryRecord` |
| `var_55C` | `0x2E8` | `0x10` | `wchar_t[8]` |
| `var_54C` | `0x2F8` | `0x10` | `_OWORD` |
| `var_53C` | `0x308` | `0x10` | `_OWORD` |
| `var_52C` | `0x318` | `0x10` | `_OWORD` |
| `var_51C` | `0x328` | `0x8` | `_QWORD` |
| `var_514` | `0x330` | `0x4` | `_DWORD` |
| `Source` | `0x334` | `0x2` | `WCHAR` |
| `WideCharStr` | `0x534` | `0x2` | `WCHAR` |
| `MultiByteStr` | `0x734` | `0x100` | `CHAR[256]` |
| `var_10` | `0x834` | `0x4` | `_DWORD` |
| `var_C` | `0x838` | `0x4` | `_DWORD` |
| `var_4` | `0x840` | `0x4` | `_DWORD` |
| `__saved_registers` | `0x844` | `0x4` | `_DWORD` |
| `__return_address` | `0x848` | `0x4` | `_UNKNOWN *` |
| `arg_0` | `0x84C` | `0x4` | `_DWORD` |
| `arg_4` | `0x850` | `0x4` | `_DWORD` |

- Global stage G06 expected side-entity readback: I04 and I06 now report containing function `RankingCategoryCollection__ParseInitialCategoryPageResponse`; I04/I06/I07 AP remain exactly the G06 precondition texts, I05/I08 AP remain exactly their existing G06 precondition texts, every AR/FR/FP remains as stated, and no side-entity name/type/range/byte/hash/xref/route changes.
- Classification, dependency, and public semantic endpoint: `apply`; global stage G06 and target-chain stage 1 after exact G01-G05 readbacks; `rename` with `pure:true`.
- Semantic action: `rename` with `pure:true`, changing only the function name to `RankingCategoryCollection__ParseInitialCategoryPageResponse`.
- Evidence: unique dispatcher/payload/class identity and collision-free name.
- Safety: no overwrite, thunk rename, local rename, type, frame, boundary, byte, xref, or comment mutation belongs to I01.
- Deterministic stage transition: the complete I01 expected poststate stated above must be established before I02 is considered. No type, frame, comment, range, size, body hash/byte, or xref delta is permitted in I01.
- Affected claim: C38.

### I02 Target chain stage 2 - set_type

- Global stage G07 literal accumulated precondition after G06: I04 and I06 containing function is `RankingCategoryCollection__ParseInitialCategoryPageResponse`; I04 AP is exactly `Compiler-generated UID0003WS temporary-record cleanup: passes stack RankingCategoryRecord::m_userEntries at +0x258 to the shared teardown tail.`; I06 AP is exactly `Compiler-generated UID0003WS EH handler using FuncInfo stru_658ABC; source uses automatic RankingCategoryRecord and standard vector lifetime.`; I07 AP is exactly `MSVC FuncInfo for UID0003WS ParseInitialCategoryPageResponse; unwind map includes the temporary RankingCategoryRecord nested-vector cleanup.`; I05 AP remains exactly `Shared compiler EH cleanup tail for stack-local RankingCategoryRecord: adjust this to m_userEntries at +0x258, then tail-jump to RankingUserEntryVectorDestroy.`; I08 AP remains exactly `Shared inlined RankingCategoryRecord default-construction constant: null m_userEntries triplet followed by m_loadedRowsCategoryId = -1; used by category-list and initial-page parsers.`; every other G01-G06 side-entity field remains at its exact expected readback.
- Complete literal I02 prestate produced by I01: function `[0x45C560,0x45CB0A)`, size 1,450 bytes; entry item `[0x45C560,0x45C561)` code; name `RankingCategoryCollection__ParseInitialCategoryPageResponse`; type `unsigned int __thiscall(RankingCategoryRecordVectorStorage *this, int)`; AR absent; AP absent; FR absent; FP absent; body SHA256 `B591D9ED33B19C7B1C9E5D7B28705EC6ADE6932AC465656E72E1C4805237968B`; first 16 bytes `55 8B EC 6A FF 68 CE A2 5F 00 64 A1 00 00 00 00`; last 16 bytes `E8 30 AC 16 00 8B E5 5D C2 04 00 E8 4B AB 16 00`; exact inbound code xrefs `{0x459276}`; exact inbound data xrefs `{}`; no callback/table xref.
- Complete literal I02 prestate frame, 28 rows:

| Name | Offset | Size | Type |
| --- | ---: | ---: | --- |
| `packedTime` | `0xC` | `0x4` | `int` |
| `var_834` | `0x10` | `0x4` | `_DWORD` |
| `cbMultiByte` | `0x14` | `0x4` | `int` |
| `var_82C` | `0x18` | `0x4` | `int` |
| `packedDate` | `0x1C` | `0x4` | `int` |
| `var_824` | `0x20` | `0x4` | `RankingCategoryRecordVectorStorage *` |
| `var_820` | `0x24` | `0x4` | `_DWORD` |
| `var_819` | `0x2B` | `0x1` | `_BYTE` |
| `var_818` | `0x2C` | `0x4` | `_DWORD` |
| `var_814` | `0x30` | `0x4` | `int` |
| `var_810` | `0x34` | `0x4` | `_DWORD` |
| `value` | `0x38` | `0x2B0` | `RankingCategoryRecord` |
| `var_55C` | `0x2E8` | `0x10` | `wchar_t[8]` |
| `var_54C` | `0x2F8` | `0x10` | `_OWORD` |
| `var_53C` | `0x308` | `0x10` | `_OWORD` |
| `var_52C` | `0x318` | `0x10` | `_OWORD` |
| `var_51C` | `0x328` | `0x8` | `_QWORD` |
| `var_514` | `0x330` | `0x4` | `_DWORD` |
| `Source` | `0x334` | `0x2` | `WCHAR` |
| `WideCharStr` | `0x534` | `0x2` | `WCHAR` |
| `MultiByteStr` | `0x734` | `0x100` | `CHAR[256]` |
| `var_10` | `0x834` | `0x4` | `_DWORD` |
| `var_C` | `0x838` | `0x4` | `_DWORD` |
| `var_4` | `0x840` | `0x4` | `_DWORD` |
| `__saved_registers` | `0x844` | `0x4` | `_DWORD` |
| `__return_address` | `0x848` | `0x4` | `_UNKNOWN *` |
| `arg_0` | `0x84C` | `0x4` | `_DWORD` |
| `arg_4` | `0x850` | `0x4` | `_DWORD` |

- Complete expected I02 poststate: function `[0x45C560,0x45CB0A)`, size 1,450 bytes; entry item `[0x45C560,0x45C561)` code; name `RankingCategoryCollection__ParseInitialCategoryPageResponse`; type `void __thiscall RankingCategoryCollection__ParseInitialCategoryPageResponse(RankingCategoryRecordVectorStorage *this, const unsigned __int8 *packet)`; AR absent; AP absent; FR absent; FP absent; body SHA256 `B591D9ED33B19C7B1C9E5D7B28705EC6ADE6932AC465656E72E1C4805237968B`; first 16 bytes `55 8B EC 6A FF 68 CE A2 5F 00 64 A1 00 00 00 00`; last 16 bytes `E8 30 AC 16 00 8B E5 5D C2 04 00 E8 4B AB 16 00`; exact inbound code xrefs `{0x459276}`; exact inbound data xrefs `{}`; no callback/table xref.
- Complete expected I02 poststate frame, 28 rows:

| Name | Offset | Size | Type |
| --- | ---: | ---: | --- |
| `packedTime` | `0xC` | `0x4` | `int` |
| `var_834` | `0x10` | `0x4` | `_DWORD` |
| `cbMultiByte` | `0x14` | `0x4` | `int` |
| `var_82C` | `0x18` | `0x4` | `int` |
| `packedDate` | `0x1C` | `0x4` | `int` |
| `var_824` | `0x20` | `0x4` | `RankingCategoryRecordVectorStorage *` |
| `var_820` | `0x24` | `0x4` | `_DWORD` |
| `var_819` | `0x2B` | `0x1` | `_BYTE` |
| `var_818` | `0x2C` | `0x4` | `_DWORD` |
| `var_814` | `0x30` | `0x4` | `int` |
| `var_810` | `0x34` | `0x4` | `_DWORD` |
| `value` | `0x38` | `0x2B0` | `RankingCategoryRecord` |
| `var_55C` | `0x2E8` | `0x10` | `wchar_t[8]` |
| `var_54C` | `0x2F8` | `0x10` | `_OWORD` |
| `var_53C` | `0x308` | `0x10` | `_OWORD` |
| `var_52C` | `0x318` | `0x10` | `_OWORD` |
| `var_51C` | `0x328` | `0x8` | `_QWORD` |
| `var_514` | `0x330` | `0x4` | `_DWORD` |
| `Source` | `0x334` | `0x2` | `WCHAR` |
| `WideCharStr` | `0x534` | `0x2` | `WCHAR` |
| `MultiByteStr` | `0x734` | `0x100` | `CHAR[256]` |
| `var_10` | `0x834` | `0x4` | `_DWORD` |
| `var_C` | `0x838` | `0x4` | `_DWORD` |
| `var_4` | `0x840` | `0x4` | `_DWORD` |
| `__saved_registers` | `0x844` | `0x4` | `_DWORD` |
| `__return_address` | `0x848` | `0x4` | `_UNKNOWN *` |
| `packet` | `0x84C` | `0x4` | `const unsigned __int8 *` |
| `arg_4` | `0x850` | `0x4` | `_DWORD` |

- Global stage G07 expected side-entity readback: the complete G06 side-entity readback remains exact; G07 changes only the target type and its one permitted physical argument row.
- Classification, dependency, and public semantic channel: `apply`; global stage G07 and target-chain stage 2 requiring exact G06/I01 poststate; `set_type`.
- Semantic action: set the function declaration to `void __thiscall RankingCategoryCollection__ParseInitialCategoryPageResponse(RankingCategoryRecordVectorStorage *this, const unsigned __int8 *packet)` while retaining the current 12-byte receiver UDT.
- Evidence: sole caller ignores EAX, every packet access is read-only, owner H returns void, and the storage UDT is exact while the class UDT is incomplete.
- Current public MCP schema/behavior basis: `set_type` accepts one function edit selected by `addr`, `kind:"function"`, and `signature`; the current implementation parses that declaration as a function `tinfo_t` and applies it at the function start. The function-signature application may reconcile generic physical argument rows with named typed arguments, so that induced frame change is part of I02 rather than a protected no-change field.
- Gate 1 correction history: report SHA256 `F91179AD8A65E21D87E3942986D29000DF87E712830103F7D4185D93FEA873D0` incorrectly treated the complete generic frame as protected after I02. That expected-readback contract is superseded by the single permitted argument-row delta below. The 28-row table above is now the exact required I02 prestate produced by I01; its physical rows match the original dated frame because I01 changes only the function name.
- Gate 2B correction history: rejected report SHA256 `C0E873B423481C2AA0DF9937FBBC479B2B65B055223007ED86109A297AB9F1EF` predicted that the generic row at `0x850` would become `packet`. Dated public `set_type` readback disproved that prediction: IDA maps the explicit packet parameter to the original physical `arg_0` row at `0x84C` and leaves `arg_4` at `0x850` unchanged. The failed action was not saved, and verified rollback restored the original prestate; the corrected tables and transition below supersede only that wrong-row contract.
- Permitted physical-frame delta: exactly one row changes, from `arg_0` at offset `0x84C`, width `0x4`, type `_DWORD`, to `packet` at offset `0x84C`, width `0x4`, type `const unsigned __int8 *`. The offset and width do not change, and no row is inserted, deleted, moved, split, or merged.
- Protected locals, each unchanged in name/offset/width/type: `packedTime@0xC/0x4/int`; `var_834@0x10/0x4/_DWORD`; `cbMultiByte@0x14/0x4/int`; `var_82C@0x18/0x4/int`; `packedDate@0x1C/0x4/int`; `var_824@0x20/0x4/RankingCategoryRecordVectorStorage *`; `var_820@0x24/0x4/_DWORD`; `var_819@0x2B/0x1/_BYTE`; `var_818@0x2C/0x4/_DWORD`; `var_814@0x30/0x4/int`; `var_810@0x34/0x4/_DWORD`; `value@0x38/0x2B0/RankingCategoryRecord`; `var_55C@0x2E8/0x10/wchar_t[8]`; `var_54C@0x2F8/0x10/_OWORD`; `var_53C@0x308/0x10/_OWORD`; `var_52C@0x318/0x10/_OWORD`; `var_51C@0x328/0x8/_QWORD`; `var_514@0x330/0x4/_DWORD`; `Source@0x334/0x2/WCHAR`; `WideCharStr@0x534/0x2/WCHAR`; `MultiByteStr@0x734/0x100/CHAR[256]`; `var_10@0x834/0x4/_DWORD`; `var_C@0x838/0x4/_DWORD`; `var_4@0x840/0x4/_DWORD`.
- Protected linkage rows, each unchanged in name/offset/width/type: `__saved_registers@0x844/0x4/_DWORD` and `__return_address@0x848/0x4/_UNKNOWN *`.
- Protected unaffected argument/receiver state: physical row `arg_4@0x850/0x4/_DWORD` remains exact; the implicit receiver remains `RankingCategoryRecordVectorStorage *this`. Do not define/replace `RankingCategoryCollection`, change the calling convention or argument count, or type the receiver as the incomplete class.
- Protected frame count: exactly 27 rows remain unchanged: all 24 listed locals, both listed linkage rows, and `arg_4@0x850/0x4/_DWORD`. Equivalently, after the one `arg_0`-to-`packet` delta, `arg_4` plus the other 26 physical rows retain their exact names, offsets, widths, and types.
- Protected non-frame state: post-I01 name `RankingCategoryCollection__ParseInitialCategoryPageResponse`; function and entry boundaries; 1,450-byte body and SHA256; literal first/last bytes; exact inbound code xrefs `{0x459276}` and inbound data xrefs `{}`; AR/AP/FR/FP absence; and every byte, item classification, callee, and control-flow edge remain exact.
- Deterministic stage transition: the complete I02 expected poststate stated above must be established before I03 is considered. The sole permitted I02 frame delta is `arg_0@0x84C/0x4/_DWORD` to `packet@0x84C/0x4/const unsigned __int8 *`; `arg_4@0x850/0x4/_DWORD` and the other 26 rows are protected, for 27 unchanged rows and 28 total rows. All non-frame state is protected as stated above.
- Affected claim: C39.

### I03 Target chain stage 3 - function-repeatable comment

- Global stage G08 literal accumulated precondition after G07: I04 and I06 containing function is `RankingCategoryCollection__ParseInitialCategoryPageResponse`; I04 AP is exactly `Compiler-generated UID0003WS temporary-record cleanup: passes stack RankingCategoryRecord::m_userEntries at +0x258 to the shared teardown tail.`; I06 AP is exactly `Compiler-generated UID0003WS EH handler using FuncInfo stru_658ABC; source uses automatic RankingCategoryRecord and standard vector lifetime.`; I07 AP is exactly `MSVC FuncInfo for UID0003WS ParseInitialCategoryPageResponse; unwind map includes the temporary RankingCategoryRecord nested-vector cleanup.`; I05 AP remains exactly `Shared compiler EH cleanup tail for stack-local RankingCategoryRecord: adjust this to m_userEntries at +0x258, then tail-jump to RankingUserEntryVectorDestroy.`; I08 AP remains exactly `Shared inlined RankingCategoryRecord default-construction constant: null m_userEntries triplet followed by m_loadedRowsCategoryId = -1; used by category-list and initial-page parsers.`; every other G01-G07 side-entity field remains at its exact expected readback.
- Complete literal I03 prestate produced by I02: function `[0x45C560,0x45CB0A)`, size 1,450 bytes; entry item `[0x45C560,0x45C561)` code; name `RankingCategoryCollection__ParseInitialCategoryPageResponse`; type `void __thiscall RankingCategoryCollection__ParseInitialCategoryPageResponse(RankingCategoryRecordVectorStorage *this, const unsigned __int8 *packet)`; AR absent; AP absent; FR absent; FP absent; body SHA256 `B591D9ED33B19C7B1C9E5D7B28705EC6ADE6932AC465656E72E1C4805237968B`; first 16 bytes `55 8B EC 6A FF 68 CE A2 5F 00 64 A1 00 00 00 00`; last 16 bytes `E8 30 AC 16 00 8B E5 5D C2 04 00 E8 4B AB 16 00`; exact inbound code xrefs `{0x459276}`; exact inbound data xrefs `{}`; no callback/table xref.
- Complete literal I03 prestate frame, 28 rows:

| Name | Offset | Size | Type |
| --- | ---: | ---: | --- |
| `packedTime` | `0xC` | `0x4` | `int` |
| `var_834` | `0x10` | `0x4` | `_DWORD` |
| `cbMultiByte` | `0x14` | `0x4` | `int` |
| `var_82C` | `0x18` | `0x4` | `int` |
| `packedDate` | `0x1C` | `0x4` | `int` |
| `var_824` | `0x20` | `0x4` | `RankingCategoryRecordVectorStorage *` |
| `var_820` | `0x24` | `0x4` | `_DWORD` |
| `var_819` | `0x2B` | `0x1` | `_BYTE` |
| `var_818` | `0x2C` | `0x4` | `_DWORD` |
| `var_814` | `0x30` | `0x4` | `int` |
| `var_810` | `0x34` | `0x4` | `_DWORD` |
| `value` | `0x38` | `0x2B0` | `RankingCategoryRecord` |
| `var_55C` | `0x2E8` | `0x10` | `wchar_t[8]` |
| `var_54C` | `0x2F8` | `0x10` | `_OWORD` |
| `var_53C` | `0x308` | `0x10` | `_OWORD` |
| `var_52C` | `0x318` | `0x10` | `_OWORD` |
| `var_51C` | `0x328` | `0x8` | `_QWORD` |
| `var_514` | `0x330` | `0x4` | `_DWORD` |
| `Source` | `0x334` | `0x2` | `WCHAR` |
| `WideCharStr` | `0x534` | `0x2` | `WCHAR` |
| `MultiByteStr` | `0x734` | `0x100` | `CHAR[256]` |
| `var_10` | `0x834` | `0x4` | `_DWORD` |
| `var_C` | `0x838` | `0x4` | `_DWORD` |
| `var_4` | `0x840` | `0x4` | `_DWORD` |
| `__saved_registers` | `0x844` | `0x4` | `_DWORD` |
| `__return_address` | `0x848` | `0x4` | `_UNKNOWN *` |
| `packet` | `0x84C` | `0x4` | `const unsigned __int8 *` |
| `arg_4` | `0x850` | `0x4` | `_DWORD` |

- Complete expected I03 poststate: function `[0x45C560,0x45CB0A)`, size 1,450 bytes; entry item `[0x45C560,0x45C561)` code; name `RankingCategoryCollection__ParseInitialCategoryPageResponse`; type `void __thiscall RankingCategoryCollection__ParseInitialCategoryPageResponse(RankingCategoryRecordVectorStorage *this, const unsigned __int8 *packet)`; AR absent; AP absent; FR absent; FP exactly `Opcode 0x7D subcommand 3: rebuilds ranking categories, commits a matching selection, applies optional local rank/score/state metadata, appends initial ranking rows, and stores total count; an unmatched selection leaves the refreshed list but preserves the prior selected id.`; body SHA256 `B591D9ED33B19C7B1C9E5D7B28705EC6ADE6932AC465656E72E1C4805237968B`; first 16 bytes `55 8B EC 6A FF 68 CE A2 5F 00 64 A1 00 00 00 00`; last 16 bytes `E8 30 AC 16 00 8B E5 5D C2 04 00 E8 4B AB 16 00`; exact inbound code xrefs `{0x459276}`; exact inbound data xrefs `{}`; no callback/table xref.
- Complete expected I03 poststate frame, 28 rows:

| Name | Offset | Size | Type |
| --- | ---: | ---: | --- |
| `packedTime` | `0xC` | `0x4` | `int` |
| `var_834` | `0x10` | `0x4` | `_DWORD` |
| `cbMultiByte` | `0x14` | `0x4` | `int` |
| `var_82C` | `0x18` | `0x4` | `int` |
| `packedDate` | `0x1C` | `0x4` | `int` |
| `var_824` | `0x20` | `0x4` | `RankingCategoryRecordVectorStorage *` |
| `var_820` | `0x24` | `0x4` | `_DWORD` |
| `var_819` | `0x2B` | `0x1` | `_BYTE` |
| `var_818` | `0x2C` | `0x4` | `_DWORD` |
| `var_814` | `0x30` | `0x4` | `int` |
| `var_810` | `0x34` | `0x4` | `_DWORD` |
| `value` | `0x38` | `0x2B0` | `RankingCategoryRecord` |
| `var_55C` | `0x2E8` | `0x10` | `wchar_t[8]` |
| `var_54C` | `0x2F8` | `0x10` | `_OWORD` |
| `var_53C` | `0x308` | `0x10` | `_OWORD` |
| `var_52C` | `0x318` | `0x10` | `_OWORD` |
| `var_51C` | `0x328` | `0x8` | `_QWORD` |
| `var_514` | `0x330` | `0x4` | `_DWORD` |
| `Source` | `0x334` | `0x2` | `WCHAR` |
| `WideCharStr` | `0x534` | `0x2` | `WCHAR` |
| `MultiByteStr` | `0x734` | `0x100` | `CHAR[256]` |
| `var_10` | `0x834` | `0x4` | `_DWORD` |
| `var_C` | `0x838` | `0x4` | `_DWORD` |
| `var_4` | `0x840` | `0x4` | `_DWORD` |
| `__saved_registers` | `0x844` | `0x4` | `_DWORD` |
| `__return_address` | `0x848` | `0x4` | `_UNKNOWN *` |
| `packet` | `0x84C` | `0x4` | `const unsigned __int8 *` |
| `arg_4` | `0x850` | `0x4` | `_DWORD` |

- Global stage G08 expected side-entity readback: the complete G07 side-entity readback remains exact; G08 changes only target FP from absent to the exact proposed text.
- Classification, dependency, and public semantic channel: `apply`; global stage G08 and target-chain stage 3 requiring exact G07/I02 poststate; `set_repeatable_comments`.
- Semantic action: set FP exactly `Opcode 0x7D subcommand 3: rebuilds ranking categories, commits a matching selection, applies optional local rank/score/state metadata, appends initial ranking rows, and stores total count; an unmatched selection leaves the refreshed list but preserves the prior selected id.`
- Evidence: complete dispatcher and packet/state trace.
- Safety: AR absent; AP absent; FR absent. No rename/type/frame/boundary/byte/xref change belongs to I03.
- Deterministic stage transition: the complete I03 expected poststate stated above is the target-chain end state. The sole permitted I03 delta is FP from absent to the exact proposed text; name, type, all 28 rows, including `packet@0x84C/0x4/const unsigned __int8 *`, unchanged `arg_4@0x850/0x4/_DWORD`, and the other 26 rows, plus AR/AP/FR, range, size, body hash/bytes, and exact code/data xrefs are protected.
- Affected claim: C40.

### Other exact entities

| ID | Entity and literal current prestate | Classification and public semantic channel | Semantic action or protection | Safety and deterministic expected readback | Claim |
| --- | --- | --- | --- | --- | --- |
| I04 | Target cleanup chunk `[0x5FA2C3,0x5FA2CE)`, 11 bytes; containing function `sub_45C560`; head item `[0x5FA2C3,0x5FA2C9)` code; name `loc_5FA2C3`; type absent; AR absent; AP absent; FR not independently applicable; FP not independently applicable; bytes `8D 8D F4 F7 FF FF E9 82 1C E6 FF`; SHA256 `6F76945917107D63DA4DA8180B7C8D89C95A8BC71B0EB23FB3AFE3407D7408B9`; inbound EH data xref `0x658AAC`; outbound jump `0x5FA2C9 -> 0x45BF50`. | Global stage G01 with no prior stage; `apply`; `set_address_repeatable_comments`. | Set AP exactly `Compiler-generated UID0003WS temporary-record cleanup: passes stack RankingCategoryRecord::m_userEntries at +0x258 to the shared teardown tail.` | Immediate G01 readback: AR absent; AP equals exactly the literal proposed text; FR not independently applicable; FP not independently applicable. Range/head/name/type/bytes/hash/containing-function `sub_45C560`/xrefs/routes remain exact through G05; G06 changes only the containing-function label as explicitly staged. | C41 |
| I05 | Shared tail `[0x45BF50,0x45BF5B)`, 11 bytes; containing function mapping `sub_45C2A0`; head item `[0x45BF50,0x45BF56)` code; name `loc_45BF50`; type absent; AR absent; AP exactly `Shared compiler EH cleanup tail for stack-local RankingCategoryRecord: adjust this to m_userEntries at +0x258, then tail-jump to RankingUserEntryVectorDestroy.`; FR not independently applicable; FP not independently applicable; bytes `81 C1 58 02 00 00 E9 95 16 00 00`; SHA256 `DBD3EB5227E92B186F3502F6E90F91176F26E8248507DABBCB190CD001F41F0A`; inbound code xrefs `0x5FA296`, `0x5FA2C9`. | Global stage G04 after exact G01-G03 readbacks; `already present`; no mutation channel. | Protection only. | Immediate G04 readback: AR absent; AP remains exactly the literal existing text; FR not independently applicable; FP not independently applicable. Every listed range/head/name/type/byte/hash/xref/route field remains exact, and exact G01-G03 readbacks remain protected. | C42 |
| I06 | Target handler `[0x5FA2CE,0x5FA2F6)`, 40 bytes; containing function `sub_45C560`; head item `[0x5FA2CE,0x5FA2D2)` code; name `SEH_45C560`; type absent; AR absent; AP absent; FR not independently applicable; FP not independently applicable; bytes `8B 54 24 08 8D 42 0C 8B 8A C8 F7 FF FF 33 C8 E8 4D D4 FC FF 8B 4A FC 33 C8 E8 43 D4 FC FF B8 BC 8A 65 00 E9 76 F2 FC FF`; SHA256 `255EA96E0D03A9F656FE7A3E3D0C01B1599DC788392B2917F7DF511D63B3D8F9`; inbound prologue data xref `0x45C565`; FuncInfo route `0x5FA2EC -> 0x658ABC`. | Global stage G02 after exact G01 readback; `apply`; `set_address_repeatable_comments`. | Set AP exactly `Compiler-generated UID0003WS EH handler using FuncInfo stru_658ABC; source uses automatic RankingCategoryRecord and standard vector lifetime.` | Immediate G02 readback: AR absent; AP equals exactly the literal proposed text; FR not independently applicable; FP not independently applicable. Range/head/name/type/bytes/hash/routes, containing function `sub_45C560`, owner entry channels, and exact G01 readback remain protected through G05; G06 changes only the containing-function label as explicitly staged. | C43 |
| I07 | FuncInfo data item `[0x658ABC,0x658AE0)`, width 36; name `stru_658ABC`; type absent; AR absent; AP absent; FR not applicable; FP not applicable; bytes `22 05 93 19 01 00 00 00 AC 8A 65 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00`; SHA256 `A2F08A02F5736BCA45B5FF9AA20B982FAD089772BC0F39838B3C6232C8B1242A`; inbound data xref `0x5FA2EC`; unwind-map pointer `0x658AAC`. | Global stage G03 after exact G01-G02 readbacks; `apply`; `set_address_repeatable_comments`. | Set AP exactly `MSVC FuncInfo for UID0003WS ParseInitialCategoryPageResponse; unwind map includes the temporary RankingCategoryRecord nested-vector cleanup.` | Immediate G03 readback: AR absent; AP equals exactly the literal proposed text; FR not applicable; FP not applicable. Item/data classification, range/name/type/width/bytes/hash/xref/map and exact G01-G02 readbacks remain protected. | C43 |
| I08 | Constructor constant `[0x610BB0,0x610BC0)`, width 16; name `xmmword_610BB0`; type absent; AR absent; AP exactly `Shared inlined RankingCategoryRecord default-construction constant: null m_userEntries triplet followed by m_loadedRowsCategoryId = -1; used by category-list and initial-page parsers.`; FR not applicable; FP not applicable; bytes `00 00 00 00 00 00 00 00 00 00 00 00 FF FF FF FF`; SHA256 `34885EA2EF8490886FAE553C8CE7FFB5A27563825E5F6CE02784875D1ACE0E47`; inbound data xrefs `0x45C43A`, `0x45C710`. | Global stage G05 after exact G01-G04 readbacks; `already present`; no mutation channel. | Protection only. | Immediate G05 readback: AR absent; AP remains exactly the literal existing text; FR not applicable; FP not applicable. Bytes/hash/item/name/type, both xrefs, and exact G01-G04 readbacks remain protected. | C44 |

Protected dependencies outside the action set: `PacketBufferReadUInt16BE`, `PacketBufferReadUInt32BE`, `GetMemoryMan`, `MemoryMan_MemmoveWrapper`, both packed-time setters, `RankingCategoryRecordVectorInsertWithGrowth`, `RankingCategoryRecordCopyConstructDeep`, and `RankingUserEntryVectorDestroy` already have source-quality identities/comments. `sub_45D1B0` remains a separately documented compiler vector-growth specialization; no target-owned rename/type/comment action or authored-source dependency is proposed here.

Semantic safety constraints:

- The public endpoint set evidenced by the live catalog is exactly `rename` with `pure:true` for I01, `set_type` for I02, `set_repeatable_comments` for I03, and `set_address_repeatable_comments` for I04/I06-I07. I05/I08 are protection-only.
- A fresh supervisor Gate 2B readback must re-establish canonical IDB identity and every prestate because this report records only a dated snapshot.
- Any collision, type drift, boundary drift, byte/hash drift, xref drift, comment drift, or inability to protect unaffected channels converts the affected action to no change until separately resolved.
- No local/frame rename or retype outside I02's exact `arg_0@0x84C/0x4/_DWORD` to `packet@0x84C/0x4/const unsigned __int8 *` name/type delta, UDT definition, class-layout change, function creation, item reclassification, byte patch, decompiler-only comment, helper mutation, or IDB persistence action is authorized by this report.
- Deterministic combined target end state exists only after strict I01 -> I02 -> I03 continuity: each prior complete poststate must equal the next complete prestate before that endpoint is considered. The final name is `RankingCategoryCollection__ParseInitialCategoryPageResponse`; type is `void __thiscall RankingCategoryCollection__ParseInitialCategoryPageResponse(RankingCategoryRecordVectorStorage *this, const unsigned __int8 *packet)`; AR absent; AP absent; FR absent; FP exactly the I03 literal; exactly 28 physical frame rows, with `packet@0x84C/0x4/const unsigned __int8 *` replacing original `arg_0@0x84C/0x4/_DWORD`, `arg_4@0x850/0x4/_DWORD` unchanged, and the other 26 rows unchanged; range/size/body hash/bytes and exact code/data xrefs unchanged.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Target CPP block disposition: replace the blank UID0003WS formal CPP block with exactly the following method.

```cpp
void RankingCategoryCollection::ParseInitialCategoryPageResponse(
    const unsigned char *packet)
{
    m_records.clear();

    short packetOffset = 4;
    const short categoryCount =
        static_cast<short>(PacketBufferReadUInt16BE(packet + 2));
    wchar_t wideTitle[256] = { 0 };
    wchar_t wideName[256];
    char narrowText[256];

    for (short categoryIndex = 0;
         categoryIndex < categoryCount;
         ++categoryIndex)
    {
        const int categoryId =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;

        const int startDate =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int startTime =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int endDate =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int endTime =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;

        const char stateCode =
            static_cast<char>(packet[packetOffset++]);
        const unsigned char titleLength = packet[packetOffset++];

        GetMemoryMan()->MemmoveWrapper(
            narrowText,
            packet + packetOffset,
            titleLength);
        narrowText[titleLength] = '\0';
        packetOffset =
            static_cast<short>(packetOffset + titleLength);

        const int wideTitleLength =
            MultiByteToWideChar(
                CP_ACP,
                0,
                narrowText,
                titleLength,
                wideTitle,
                256);
        wideTitle[wideTitleLength] = L'\0';

        RankingCategoryRecord category;
        category.SetListIndex(categoryIndex);
        category.SetCategoryId(categoryId);
        category.SetStartTimeFromPackedDateTime(startDate, startTime);
        category.SetEndTimeFromPackedDateTime(endDate, endTime);
        category.SetStateCode(stateCode);
        category.SetTitleText(wideTitle);
        m_records.push_back(category);
    }

    const int selectedCategoryId =
        static_cast<int>(
            PacketBufferReadUInt32BE(packet + packetOffset));
    packetOffset += 4;

    RankingCategoryRecord *selectedRecord = 0;
    for (unsigned int categoryIndex = 0;
         categoryIndex < m_records.size();
         ++categoryIndex)
    {
        if (m_records[categoryIndex].GetCategoryId() == selectedCategoryId)
        {
            selectedRecord = &m_records[categoryIndex];
            break;
        }
    }

    if (selectedRecord == 0)
        return;

    m_selectedCategoryId = selectedCategoryId;
    selectedRecord->ResetUserEntries();

    const char hasLocalPlayer =
        static_cast<char>(packet[packetOffset++]);
    if (hasLocalPlayer > 0)
    {
        const int localPlayerRank =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int localPlayerScore =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const char localStateCode =
            static_cast<char>(packet[packetOffset++]);

        selectedRecord->m_loadedRowsCategoryId = selectedCategoryId;
        selectedRecord->m_localPlayerScore = localPlayerScore;
        selectedRecord->m_localPlayerRank = localPlayerRank;
        selectedRecord->SetStateCode(localStateCode);
    }

    const short rowCount =
        static_cast<short>(
            PacketBufferReadUInt16BE(packet + packetOffset));
    packetOffset += 2;

    for (short rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        const unsigned char nameLength = packet[packetOffset++];
        GetMemoryMan()->MemmoveWrapper(
            narrowText,
            packet + packetOffset,
            nameLength);
        narrowText[nameLength] = '\0';
        packetOffset =
            static_cast<short>(packetOffset + nameLength);

        const int wideNameLength =
            MultiByteToWideChar(
                CP_ACP,
                0,
                narrowText,
                nameLength,
                wideName,
                256);
        wideName[wideNameLength] = L'\0';

        const int rank =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;
        const int score =
            static_cast<int>(
                PacketBufferReadUInt32BE(packet + packetOffset));
        packetOffset += 4;

        RankingUserEntry entry;
        entry.categoryId = selectedCategoryId;
        entry.score = -1;
        entry.rank = rank;
        wcscpy_s(entry.name, 32, wideName);
        entry.score = score;
        selectedRecord->AppendUserEntry(entry);
    }

    selectedRecord->SetTotalRankCount(
        static_cast<int>(
            PacketBufferReadUInt32BE(packet + packetOffset)));
}
```

- Target H block disposition: remain exactly blank; UID0000BK already contains `void ParseInitialCategoryPageResponse(const unsigned char *packet);`.
- Required UID0000BL formal H insertion: add exactly this class member to the existing `RankingCategoryRecord` declaration without moving or exposing fields.

```cpp
    friend class RankingCategoryCollection;
```

- Behavior preservation: source ordering matches every commit point, signed comparison, text conversion, sentinel store, early return, append path, and final total store. Ordinary automatic objects and vectors regenerate the EH/growth/copy/destroy code.
- Mid-2000s source shape: C++03-compatible loops, null literal `0`, fixed arrays, Win32 conversion, secure CRT copy, existing class methods, and existing MemoryMan/PacketBuffer APIs match the sibling accepted source.
- No IDA/compiler names appear in the formal source. The source uses established field and method names only.
- Third-party import: not applicable.

## Final Recommendation

- Implemented: UID0003WS formal CPP contains the exact Section 22 method and target H remains blank.
- Implemented: UID0003WS is `93/93` with owner/emitter UID0000BK, reconstructable true, and blank child position preserved.
- Implemented: narrow UID0000BL friendship and report-level synchronization of UID0000BK, UID0001ZC, UID0000BL, UID0001VN, UID0000Y9, and UID0000MZ without score changes.
- Implemented for UID0003WS: reserved-footer-write prose is superseded while history is retained. UID0003WT remained outside B001's callback under the collision boundary; B003 independently incorporated and executed the equivalent correction, so C31 is checked as already-present.
- Keep compiler vector/EH helpers non-emitting and outside authored C++.
- Gate 2B must restart at G01 after fresh dynamic prestate checks. At G07/I02, require the corrected sole frame delta `arg_0@0x84C/0x4/_DWORD` to `packet@0x84C/0x4/const unsigned __int8 *`, with unchanged `arg_4@0x850/0x4/_DWORD`, 26 additional unchanged rows, and exact I03 continuity; the prior attempt was unsaved and verified rolled back.
- Future work outside this assignment: full source closure of neighboring UID0003WT and exact rebuild-codegen comparison under the intended retail compiler settings.

## Recommended Target Doc Changes

- Implementation status: completed and scoped-validated under command `000000023638`.
- Path: `by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md`.
- Metadata: `COMPLETION:93`, `CONFIDENCE:93`; owner/emitter/reconstructable/position unchanged.
- Formal CPP: exact Section 22 method. Formal H: blank.
- Replace the blocker status with source-ready disposition and exact owner/file/declaration support.
- Add complete dispatch, signed count/cursor, category wire layout, title conversion, constructor baseline, selected-id match/early-return, optional-local signed flag and exact fields, row layout/text conversion, total commit, exception/partial-success, helper/source boundary, range/hash/xref, and negative evidence.
- Preserve prior append/setter/history facts. Historicalize the prior blank-CPP blocker and reserved-footer-write claim rather than deleting their provenance.
- Item Summary should describe the source-ready combined parser without repeating generated metadata fields.

## Recommended Support Doc Changes

| Support path | Exact incorporation | Metadata |
| --- | --- | --- |
| `by-class/RankingCategoryCollection.md` | Mark method source-ready; add exact selected-match, local metadata, rows, total, partial-success, and child-emitter facts. | Retain 93/95, UID0000MZ owner/emitter, position 10. |
| `by-class/RankingCategoryRecord.md` | Add narrow friendship in formal H; document direct loaded-id/rank/score access, state setter, no reserved-tail write, and retained private layout. | Retain 94/95 and existing route. |
| `by-type/by-struct/RankingCategoryRecordLayout.md` | Add exact subcommand-3 wire-to-field writes and absent-local baseline; explicitly reject reserved-tail packet copy. | Retain 93/95 and blank formal channels. |
| `by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md` | Synchronize friendship and page-metadata access as class-covered source behavior. | Retain 92/94 ignored/non-emitting index. |
| `by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md` | Mark UID0003WS source-ready and add complete behavior/helper/failure route. | Retain 92/94 aggregate state. |
| `by-file/RankingDialog.md` | Add complete definition/header friendship/source route and record that validator-generated output closed the historical empty-marker state with exactly one definition. | Retain 88/91. |
| `by-memory/0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse.md` | Not edited by B001 under the collision boundary; B003 independently incorporated and executed the same no-reserved-footer correction. | Retain 87/90 and separate blank formal state; C31 checked/already-present. |

The first six support rows and the target row were implemented and scoped-validated. No manual generated, coverage, audit, catalog, assignment, tracker, lifecycle, or UID0003WT edit was made; generated CPP/H changes came only from the validator-owned refresh.

## Score And Metadata Recommendation

- Historical pre-callback target: `87/90`, owner/emitter `0000BK`, reconstructable true, blank child position, blank CPP/H.
- Current implemented target: `93/93`, same owner/emitter/reconstructable/position, nonblank CPP, blank H.
- Completion rises because every current source blocker is resolved: packet helpers, includes, types, legal private access, source placement, full behavior, exception model, and formal code.
- Confidence rises because all behavior and boundaries were independently revalidated live. It remains below 94/95 because retail method/field spellings, original friendship syntax, packet-size metadata, exact compiler range-instrumentation option, and rebuild-codegen equivalence are unavailable.
- Support scores remain unchanged: their broader remaining work is outside this target and this method does not justify parent-wide promotion.
- Reconstructable remains true because this is authored behavior, unlike its generated vector/EH support.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution and impact |
| --- | --- | --- |
| Exact original method name? | Dispatcher role, sibling names, owner H, collision search, report search | `ParseInitialCategoryPageResponse` is best descriptive name; retail spelling unproved, confidence cap only. |
| Was friendship original? | Direct private stores, absent setter calls, current private class, alternative access models | Narrow friendship is the least-inventive legal route. Public fields and invented methods rejected; confidence cap only. |
| Does reserved tail hold a name? | Both parsers, deep copy, layout, paint consumer | It may be historical/reserved storage, but these parsers never write it and paint gets the displayed name globally. No target code impact. |
| Why set row score to -1 before final score? | Exact store order in both row parsers | Preserve the source-visible ordering because it may reflect original defensive initialization/compiler scheduling; no constructor is invented. |
| Why not return the found index? | Caller data flow and owner declaration | Residual EAX is ignored; source is void. Resolved. |
| Which physical stack row does public set_type assign to packet? | Dated 2026-08-15 G07 public set_type and immediate stack_frame readback, followed by unsaved rollback verification | It changes original `arg_0@0x84C/0x4/_DWORD` to `packet@0x84C/0x4/const unsigned __int8 *`; `arg_4@0x850/0x4/_DWORD` and the other 26 rows remain exact. Resolved and incorporated into I02/I03. |
| Exact packet maximum size? | Complete target/caller/helper/docs scan | No size parameter or bound metadata is present. Do not add checks; this limits safety documentation, not source readiness. |
| Exact compiler instrumentation? | Range-check blocks, sibling accepted source, generated environment | Ordinary fixed-array indexing is the source cause; exact retail switch/pragma needs rebuild evidence and caps score. |

No unresolved question blocks formal CPP/H placement.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The current manual rows were read without modification. Apply these only after accepted ordinary-doc implementation and verification.

File `by-memory/-coverage-report.md`, replace current UID0003WS row at its existing child position with:

    - [UID:0003WS][0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse](by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md) 0x0045c560-0x0045cb0a | method | RankingCategoryCollectionParseInitialCategoryPageResponse : reconstructable : 93% : very-strong : Source-ready opcode 0x7d subcommand 3 parser in RankingDialog.cpp: clears and rebuilds categories with signed-short counts/cursor, exact BE metadata, CP_ACP title conversion, partial default construction and ordinary vector append; commits selection only for a matching id, resets selected rows/rank, applies signed-positive optional metadata to loaded id/rank/score/state without writing the reserved footer, parses signed-count 0x4c rows through ANSI-to-wide names and ordinary AppendUserEntry, commits total last, and preserves refreshed-list/successful-prefix state on early return or failure.

In the same file, replace current UID0001ZC row with:

    - [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md) 0x0045c260-0x0045d4f8 | class | RankingCategoryCollection : reconstructable : 92% : very-strong : Source-authored ranking category parser/accessor cluster with exact opcode 0x7d contracts, selected-category state, signed-short accessors, source-ready category-list, combined initial-category/page, reward-claim, GetCount, and GetByIndex methods, and RankingDialog.cpp/.h routing; UID0003WS preserves signed counts/cursor, CP_ACP title/name conversion, match-only selection commit, signed-positive local rank/score/state metadata with no reserved-tail write, ordinary category/row vector operations, final total commit, and partial-success behavior, while reviewed growth/copy/destruction/EH helpers remain non-emitting compiler consequences.

In the same file, insert this absent UID0003WT row immediately after UID0003WS and before UID0003WU:

    - [UID:0003WT][0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse](by-memory/0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse.md) 0x0045cb10-0x0045cdb4 | method | RankingCategoryCollectionParseRankingRowsResponse : reconstructable : 87% : very-strong : Source-authored opcode 0x7d subcommand 2 selected-category row parser; validates the selected id, clears rows and resets local rank, conditionally writes loaded category id/local rank/local score/state without writing the reserved footer tail, appends exact 0x4c rows, and stores total count, while complete formal source remains separate UID0003WT work.

In the same file, replace current UID0000Y9 row with:

    - [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md) 0x0045bf60-0x0045c257 | split-index | RankingCategoryRecord : ignored/non-emitting : 92% : very-strong : Non-emitting sixteen-child index for the source-authored 0x2b0-byte RankingCategoryRecord family; exact accessors/setters, standard 36-byte tm members, 76-byte std::vector user rows, ResetUserEntries clear-without-free semantics, local-player rank sentinel, narrow RankingCategoryCollection friendship for direct loaded-id/rank/score access, no parser write to the reserved footer tail, padding fences, live callers, and class/header route are documented while exact child pages own source emission.

File `by-class/-coverage-report.md`, replace UID0000BK row with:

- [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md) : reconstructable : 93% : very-strong : Ranking category parser/accessor collection with exact four-field layout, opcode 0x7d subcommands 1/2/3/6, selected-category state, source-ready category-list/combined-initial-page/reward-claim/GetCount/GetByIndex methods, signed-short counts/cursors, MemoryMan ANSI copying, CP_ACP conversion through fixed wide arrays, match-only selection commit, local rank/score/state metadata without reserved-tail writes, exact row/total parsing, partial-success semantics, RankingDialog.cpp/.h routing, and ordinary std::vector regeneration of reviewed non-emitting growth, deep-copy, nested-vector lifetime, and EH support.

In the same file, replace UID0000BL row with:

- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) : reconstructable : 94% : very-strong : Complete naturally aligned 0x2b0 RankingCategoryRecord declaration with standard tm members, exact accessors/setters, source-facing std::vector<RankingUserEntry> at +0x258, inline partial default construction, and narrow RankingCategoryCollection friendship for proved direct loaded-id/rank/score page metadata access while fields remain private; checked parsers never write the 0x40 reserved footer tail, and implicit memberwise copy/nested-vector deep copy remain compiler-generated under one RankingDialog header/source emitter route.

File `by-file/-coverage-report.md`, replace UID0000MZ row with:

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) : reconstructable : 88% : very-strong : Ranking UI source-placement root with dialog, event/list/user panes, category collection and naturally aligned RankingCategoryRecord declarations; source-ready opcode 0x7d subcommands 1 and 3 clear/rebuild categories with signed counts/cursors, exact BE metadata, MemoryMan copy, CP_ACP fixed-array conversion, partial-sentinel construction, match-only selection, local rank/score/state metadata without reserved-tail writes, exact initial rows/total, ordinary vector operations and partial-success behavior, using shared PacketBuffer readers plus narrow record/collection friendship; compiler growth/copy/destruction/EH/range helpers remain non-emitting without generated empty-marker pollution after coherent refresh.

File `by-type/by-struct/-coverage-report.md`, replace UID0001VN row with:

- [UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md) : reconstructable : 93% : very-strong : Exact naturally aligned 688-byte record layout with standard 36-byte tm members, 512-byte title, state/scalar/footer/rank/score fields, 76-byte user rows, source std::vector at +0x258, partial default baseline of total 0 and loaded-id/rank/score -1, and exact parser wire mapping; subcommands 2/3 reset rows/rank and conditionally write loaded id/rank/score/state but never the 0x40 reserved footer tail, while other primitive, tm-tail, title-tail, and reserved bytes remain intentionally uninitialized until assigned and implicit copy/teardown remains compiler-generated.

Reason B001 must not apply these rows: all listed files are manual supervisor-owned coverage artifacts and the active assignment forbids coverage edits. Validator-owned auto-generated tracker text is not supplied here.

## Follow-Up Actions

- Historical preimplementation Gate 1 passed exact report SHA256 `67740A1A9B9131430197A410485B6AD5076C50439CF93A9DA2C1E09801D2A4BE`; later same-report repairs preserved the accepted ordinary implementation. Exact report SHA256 `C0E873B423481C2AA0DF9937FBBC479B2B65B055223007ED86109A297AB9F1EF` passed fresh Gate 1 and ordinary-document Gate 2A, then Gate 2B failed closed at G07/I02 solely because its expected physical argument row was wrong.
- Timeless gate boundary: before any later gate, the supervisor performs a fresh exact-artifact Gate 1 audit of the report at its then-authoritative path and revision. This report body carries no mutable review-state assertion; no ordinary-document or validator rerun is implied by this text correction, while manual coverage, final execution, and archival remain supervisor-owned.
- Supervisor verification boundary: at the relevant later gate, independently check the seven implemented ordinary destinations and dynamically reread the generated definition/declaration/friend/marker state; C34 deliberately remains unchecked and supervisor-owned.
- Supervisor coverage: apply and verify the Section 28 manual coverage text; C32-C33 remain unchecked and supervisor-owned.
- Supervisor Gate 2B: independently re-establish canonical IDB prestate, restart the complete G01-G08 order, and at G07 require only `arg_0@0x84C/0x4/_DWORD` to become `packet@0x84C/0x4/const unsigned __int8 *` while `arg_4@0x850/0x4/_DWORD` and the other 26 rows remain exact. The 2026-08-15 failed attempt was unsaved and the original prestate was verified restored before this repair.
- UID0003WT status: B003 independently incorporated and executed the no-reserved-footer correction; C31 is already-present and this report assigns no further B001 action.
- Lifecycle: the current report path and validator-owned status/history metadata are authoritative; this ordinary report body makes no current execute/archive assertion.

## Confidence

- Recommendation confidence: high.
- Behavior/range/ownership/source-placement confidence: high.
- Formal source confidence: high for semantics and dependencies; medium-high for exact original local naming/access syntax.
- Score confidence: medium-high at `93/93`.
- Remaining uncertainty is explicitly bounded to stripped spellings, friendship syntax, packet-size metadata, compiler flags, and unperformed rebuild-codegen comparison.

## Validator Results

- Historical receipt scope only: commands `000000023638` through `000000023647` were run during the accepted ordinary-document callback, not during this report-only repair. Every B001 command used exact cwd `E:\NTK\GhidraBridge\source-3\project-documentation`, exited `0`, and reported `ok: 1`.

| B001 command ID | Exact cwd | Exact single-line command | Command timestamp | Exit / ok |
| --- | --- | --- | --- | --- |
| `000000023638` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory\0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md' --apply --queue-timeout 240` | `2026-08-14T18:52:25-04:00` | `0 / 1` |
| `000000023639` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-class\RankingCategoryCollection.md' --apply --queue-timeout 240` | `2026-08-14T18:54:11-04:00` | `0 / 1` |
| `000000023640` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-class\RankingCategoryRecord.md' --apply --queue-timeout 240` | `2026-08-14T18:54:53-04:00` | `0 / 1` |
| `000000023641` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-type\by-struct\RankingCategoryRecordLayout.md' --apply --queue-timeout 240` | `2026-08-14T18:55:33-04:00` | `0 / 1` |
| `000000023643` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory\0x0045bf60-0x0045c257.RankingCategoryRecord.md' --apply --queue-timeout 240` | `2026-08-14T18:56:14-04:00` | `0 / 1` |
| `000000023645` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-memory\0x0045c260-0x0045d4f8.RankingCategoryCollection.md' --apply --queue-timeout 240` | `2026-08-14T18:57:25-04:00` | `0 / 1` |
| `000000023646` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-file\RankingDialog.md' --apply --queue-timeout 240` | `2026-08-14T18:59:59-04:00` | `0 / 1` |
| `000000023647` | `E:\NTK\GhidraBridge\source-3\project-documentation` | `python .\tools\validator.py --mode file --file 'by-file\RankingDialog.md' --apply --wait-generated --queue-timeout 240` | `2026-08-14T19:00:07-04:00` | `0 / 1` |

| B001 command ID | Literal warnings/errors | Generated-refresh state and exact reported side effects | Final physical reread/hash |
| --- | --- | --- | --- |
| `000000023638` | Warnings: none. Errors: none. | `generated_refresh: deferred`; `autogen_registry_update: 2`, `completion_update: 1`, `confidence_update: 1`, `reference_index_add: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`; target formal CPP registry changed blank to block. | UID0003WS reread `19,974` bytes / `277` lines; SHA256 `C2C42AE9F22E018DEE0DA284FA2510C12B9A4FF482EBB42F79549D21E76093A3`. |
| `000000023639` | Warnings: none. Errors: none. | `generated_refresh: deferred`; `projected_stats_update: 1`, `stats_incremental_noop: 1`. | UID0000BK reread `49,083` bytes / `341` lines; SHA256 `90D240194AF93D969FB08EC3DF43160B48D87B6F3C84422DAF0F415235006CB2`. |
| `000000023640` | Warning literal `missing_ref_uid 0003X1 by-class/RankingCategoryRecord.md UID reference is not present in validator.ini` occurred three times; literal `missing_ref_uid 0003X3 by-class/RankingCategoryRecord.md UID reference is not present in validator.ini` occurred twice; literal `missing_ref_uid 0003YV by-class/RankingCategoryRecord.md UID reference is not present in validator.ini` occurred twice. Errors: none. | `generated_refresh: deferred`; `autogen_registry_update: 1`, `reference_index_add: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`; formal-H registry hash updated. | UID0000BL reread `57,681` bytes / `378` lines; SHA256 `77D968A060D4375F6A6C6F18B6113C5BCF1395D2EF227AA38D62EA255AF89B5B`. |
| `000000023641` | Warning literal `missing_ref_uid 0003X3 by-type/by-struct/RankingCategoryRecordLayout.md UID reference is not present in validator.ini` occurred once; literal `missing_ref_uid 0003YV by-type/by-struct/RankingCategoryRecordLayout.md UID reference is not present in validator.ini` occurred twice. Errors: none. | `generated_refresh: deferred`; `reference_index_add: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`. | UID0001VN reread `43,933` bytes / `348` lines; SHA256 `70E7E7B202CC222D01B9419E4313E583355EC1B7AA416F4FA0D1CA16F77AEEF4`. |
| `000000023643` | Warning literal `missing_ref_uid 0003X1 by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md UID reference is not present in validator.ini` occurred four times. Errors: none. | `generated_refresh: deferred`; `reference_index_add: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`. | UID0000Y9 reread `44,146` bytes / `263` lines; SHA256 `3971AA109C47898243C3B8CE8935F69156EC4F90299DD5F92C393EB0CF59794B`. |
| `000000023645` | Warning literal `missing_ref_uid 0003WP by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md UID reference is not present in validator.ini` occurred twice; literal `missing_ref_uid 0003WV by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md UID reference is not present in validator.ini` occurred once; literal `missing_ref_uid 0003WX by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md UID reference is not present in validator.ini` occurred once; literal `missing_ref_uid 0003X1 by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md UID reference is not present in validator.ini` occurred once; literal `missing_ref_uid 0003X2 by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md UID reference is not present in validator.ini` occurred once; literal `missing_ref_uid 0003X3 by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md UID reference is not present in validator.ini` occurred once. Errors: none. | `generated_refresh: deferred`; `projected_stats_update: 1`, `stats_incremental_noop: 1`. | UID0001ZC reread `50,093` bytes / `301` lines; SHA256 `39A358ACEC7E97BC0B05CED9491BA46AC4A8EF049648E06F4B23366F905544B7`. |
| `000000023646` | Warnings: none. Errors: none. | `generated_refresh: deferred`; `reference_index_add: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`. | UID0000MZ reread `121,859` bytes / `648` lines; SHA256 `0F76DB64BDFAC850B06DD4B99F1A058C983B9D2587D0D025011E3991890FAD9B`. |
| `000000023647` | Warnings: none. Errors: none. Informational generated diagnostics were reported separately from warnings/errors. | `generated_refresh: completed`; exact counters: `autogen_children_fallback_insert: 9`, `autogen_children_marker_missing: 72`, `autogen_emitter_has_no_code: 74`, `autogen_header_metadata_refresh: 121`, `autogen_header_noop: 148`, `autogen_registry_rebuild: 1`, `generated_metadata_refresh: 277`, `memory_auto_coverage_update: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`; registry rebuild reported `5535` metadata nodes and `4292` edges; validator-owned memory auto coverage and generated metadata refreshed. | During the dated ordinary callback, B001 reread UID0000MZ at the recorded hash and physically read generated RankingDialog CPP/H. Initial deferred output used validator-owned command `000000023648`; the later callback snapshot used validator-owned command `000000023654`. |

- Receipt-ID ownership boundary: B001-issued receipts in the numeric span `000000023638` through `000000023647` are exactly `000000023638`, `000000023639`, `000000023640`, `000000023641`, `000000023643`, `000000023645`, `000000023646`, and `000000023647`. IDs `000000023642` and `000000023644` were not returned by any B001-issued command, so this report does not invent a B001 cwd, command, diagnostics, or result for them.
- Dated callback generated-command ownership distinction: `000000023647` is the B001-issued scoped wait command above. Initial generated output identified validator-owned command `000000023648`; the later 2026-08-14 callback snapshot identified validator-owned foreground command `000000023654`. B001 did not issue, invoke, or own command `000000023648` or `000000023654`; later generated authority is established by fresh supervisor readback.

- Dated ordinary-callback generated CPP receipt: SHA256 `D55C7932EA674F89FC30E0BE048C6AE869AEEBD1ED272160E716B990AA4D8D7D`, 64,895 bytes, 1,801 lines, command `000000023654`, refreshed `2026-08-14T19:02:07-04:00`.
- Dated ordinary-callback generated H receipt: SHA256 `E472F5C6B7853E66D3944A8A1F0E4349586541EE2867612FB3DE219BBF6F5B77`, 2,601 bytes, 86 lines, command `000000023654`, refreshed `2026-08-14T19:02:07-04:00`.
- The dated callback physical readback found exactly one `RankingCategoryCollection::ParseInitialCategoryPageResponse` definition, one `void ParseInitialCategoryPageResponse(const unsigned char *packet);` declaration, one `friend class RankingCategoryCollection;` declaration, `RankingCategoryRecord` before `RankingCategoryCollection`, no duplicates of those entities, and no UID0003WS empty marker. At every later gate the supervisor dynamically rereads validator-owned generated output; C34 remains unchecked as a supervisor-owned verification row.
- Historical callback boundary: no broad/manual validator mode, manual generated edit, manual coverage edit, IDA mutation, execute_report, lifecycle command, or move/archive operation was run by B001. This report-only repair ran no validator and makes no current lifecycle-state assertion.
- Gate 2B is not a validator receipt: on 2026-08-15 the supervisor reached G07 after successful immediate G01-G06 readbacks, observed the corrected `arg_0@0x84C` packet-row mapping, stopped before G08, did not save, and discarded only the unsaved worker. Canonical and backup were both 143,207,794 bytes with SHA256 `61FBD1CA765796F70F0C4BC9D44251761BE86836C827F7FE6AB770F4C9DA3E82`; reopening canonical restored the original prestate. No validator command was run for this report-text correction.
- Report audit remains content-only: 33 required headings, exact 48-row ledger/checklist twin, formal C++ only in Section 22 fences, and one terminal readiness marker.

## Changed Files

- B001-authored ordinary destinations, all leased only for edit/validator and then released:

| UID | Path | SHA256 | Bytes / lines |
| --- | --- | --- | --- |
| 0003WS | `by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md` | `C2C42AE9F22E018DEE0DA284FA2510C12B9A4FF482EBB42F79549D21E76093A3` | `19,974 / 277` |
| 0000BK | `by-class/RankingCategoryCollection.md` | `90D240194AF93D969FB08EC3DF43160B48D87B6F3C84422DAF0F415235006CB2` | `49,083 / 341` |
| 0000BL | `by-class/RankingCategoryRecord.md` | `77D968A060D4375F6A6C6F18B6113C5BCF1395D2EF227AA38D62EA255AF89B5B` | `57,681 / 378` |
| 0001VN | `by-type/by-struct/RankingCategoryRecordLayout.md` | `70E7E7B202CC222D01B9419E4313E583355EC1B7AA416F4FA0D1CA16F77AEEF4` | `43,933 / 348` |
| 0000Y9 | `by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md` | `3971AA109C47898243C3B8CE8935F69156EC4F90299DD5F92C393EB0CF59794B` | `44,146 / 263` |
| 0001ZC | `by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md` | `39A358ACEC7E97BC0B05CED9491BA46AC4A8EF049648E06F4B23366F905544B7` | `50,093 / 301` |
| 0000MZ | `by-file/RankingDialog.md` | `0F76DB64BDFAC850B06DD4B99F1A058C983B9D2587D0D025011E3991890FAD9B` | `121,859 / 648` |

- This same report was updated in place with dated callback receipts, exact historical receipts, dependency-ordered I01-I03 prestates/poststates, exact claim allocation, C31's independently completed B003 status, generated readback, and final proofs. Its repaired identity is established after all edits in the closing audit.
- This Gate 2B contract repair changed only this report: it corrected I02/I03 to the observed `arg_0@0x84C` packet-row mapping and recorded the verified unsaved rollback. It did not alter any accepted ordinary destination, generated output, coverage artifact, IDA database, validator state, tracker, audit, catalog, assignment, or lifecycle file.
- Dated ordinary-callback generated timeline: B001 issued scoped wait command `000000023647`; initial validator-owned generated command `000000023648` produced the immediate output; later validator-owned foreground command `000000023654` produced the callback snapshot. That dated snapshot recorded RankingDialog.cpp SHA256 `D55C7932EA674F89FC30E0BE048C6AE869AEEBD1ED272160E716B990AA4D8D7D` and RankingDialog.h SHA256 `E472F5C6B7853E66D3944A8A1F0E4349586541EE2867612FB3DE219BBF6F5B77`; B001 did not edit generated files by hand. These identities are receipt history, not later-gate authority; the supervisor rereads validator-owned generated output dynamically and later refreshes may advance without invalidating coherent source content.
- UID0003WT was not edited. No manual `-coverage-report.md`, audit, catalog, tracker, assignment, lifecycle, IDA database, or generated file was edited by B001.
- This report-only repair renamed, moved, and archived nothing, issued no lifecycle command, and makes no current execution/archive-state assertion; current lifecycle truth remains supervisor/validator-owned.
- This report was leased only for the bounded text edit and released immediately afterward. All seven ordinary-document leases remain released; final lease state is reported from the post-release `current_leases.md` readback.

## Implementation Tracking Checklist

Rows verified as applied, already-present, or excluded-with-reason are checked. C32-C34, C37-C44, and C47-C48 remain unchecked with verification state `proposed`.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C01 | 0003WS | The exact source-authored target is opcode 0x7D subcommand 3 method range [0x45C560,0x45CB0A), owned and emitted by UID0000BK. | High | Live function, dispatcher, owner declaration, one inbound call | UID0003WS Status/Evidence/formal CPP | incorporate | applied |
| [x] | C02 | 0003WS | The parser clears m_records first, destroying nested row vectors while retaining outer capacity. | High | Entry destruction loop and end=begin store | UID0003WS clear/failure sections | incorporate | applied |
| [x] | C03 | 0003WS | Category count and packet cursor are signed short; zero or negative narrowed counts append no categories. | High | 16-bit signed comparisons and MOVSX SI packet addressing | UID0003WS wire contract/formal CPP | incorporate | applied |
| [x] | C04 | 0003WS | Each category record reads BE32 id, start date/time, end date/time, signed state byte, unsigned title length, and title bytes in that order. | High | Complete category-loop call and offset trace | UID0003WS category wire table | incorporate | applied |
| [x] | C05 | 0003WS | Category titles use MemoryMan copy, a narrow terminator, CP_ACP conversion into a zero-initialized wchar_t[256], indexed wide terminator, and secure record-title copy. | High | Calls and local-array instrumentation at 0x45C6D0-0x45C7AC | UID0003WS text behavior/formal CPP | incorporate | applied |
| [x] | C06 | 0000BL | Each stack category uses the partial default constructor: empty row vector, total 0, loaded id/rank/score -1, with other spans intentionally uninitialized until assigned. | High | Shared constant 0x610BB0 and adjacent scalar stores | UID0000BL/UID0001VN constructor evidence | incorporate | applied |
| [x] | C07 | 0003WS | Category fields are populated through the existing record setter surface before one ordinary m_records.push_back. | High | Setter calls/direct inlining and owner H surface | UID0003WS construction/formal CPP | incorporate | applied |
| [x] | C08 | 0003WS | Category push_back uses fast deep copy at 0x45C7CB or UID0003X0 growth at 0x45C7DC, then destroys the temporary nested vector at 0x45C7EE. | High | Branch, calls, end advance, EH cleanup | UID0003WS append/lifetime sections | incorporate | applied |
| [x] | C09 | 0003WS | The parser reads BE32 selectedCategoryId after the category list and searches only the newly rebuilt records. | High | 0x45C80D read and 0x2B0-stride lookup | UID0003WS selection section/formal CPP | incorporate | applied |
| [x] | C10 | 0003WS | If no category id matches, the refreshed list remains but m_selectedCategoryId and row/total state are not newly committed. | High | Early return before collection +0x0C store | UID0003WS partial-success section | incorporate | applied |
| [x] | C11 | 0003WS | On a match, collection selection is committed, selected rows are cleared without freeing capacity, and local rank becomes -1. | High | Stores at 0x45C887, 0x45C8A2, 0x45C8AD | UID0003WS selected-record transition/formal CPP | incorporate | applied |
| [x] | C12 | 0003WS | The optional-local flag is signed char; only values 1 through 127 enter the metadata block. | High | TEST AL followed by signed JLE | UID0003WS local metadata contract | incorporate | applied |
| [x] | C13 | 0003WS | Present local metadata writes loadedRowsCategoryId, localPlayerScore, localPlayerRank, and state; it never writes the reserved 0x40 footer tail. | High | Exact stores at 0x45C90B/17/23/29 and complete negative store scan | UID0003WS and UID0001VN field mapping | incorporate | applied |
| [x] | C14 | 0003WS | Row count is a signed short; negative narrowed counts skip rows and still read the total at the current cursor. | High | UInt16 read and signed 16-bit loop comparisons | UID0003WS row contract/formal CPP | incorporate | applied |
| [x] | C15 | 0003WS | Each row uses unsigned byte name length, MemoryMan copy, CP_ACP conversion into wchar_t[256], then wcscpy_s into the exact wchar_t[32] row field. | High | 0x45C960-0x45CA36 trace and row UDT | UID0003WS row-text section/formal CPP | incorporate | applied |
| [x] | C16 | 0003WS | Each 0x4C row contains selected category id, BE32 rank, name[32], and BE32 score; score is set to -1 before secure name copy and then replaced. | High | Stack layout and stores at 0x45CA10-0x45CA4A | UID0003WS row layout/formal CPP | incorporate | applied |
| [x] | C17 | 0003WS | Row append is ordinary RankingCategoryRecord::AppendUserEntry/std::vector push_back; sub_45D1B0 is compiler growth plumbing and must not enter authored source. | High | Fast 0x4C copy, growth call 0x45CAA9, shared helper xrefs | UID0003WS helper/source boundary | incorporate | applied |
| [x] | C18 | 0003WS | Total rank count is the final BE32 field and commits only after all requested rows append successfully. | High | Final read/store at 0x45CAD4/0x45CAE2 | UID0003WS total/failure sections | incorporate | applied |
| [x] | C19 | 0003WS | The target performs no packet null/length check, count sanity check, encoding validation, explicit conversion-error branch, or transactional rollback. | High | Complete CFG/callee/branch negative review | UID0003WS negative evidence | incorporate | applied |
| [x] | C20 | 0003WS | Failures preserve incremental state: old list is already gone, successful category/row prefixes remain, selection/metadata may be committed, and total may remain uncommitted. | High | Operation ordering plus EH map and vector guarantees | UID0003WS failure/lifetime section | incorporate | applied |
| [x] | C21 | 0003WS | Source return type is void; all binary return values are residual and the sole caller ignores EAX. | High | Caller at 0x459276 and all exits | UID0003WS signature/formal CPP | incorporate | applied |
| [x] | C22 | 0000MZ | The unique source route is RankingDialog.cpp with declarations in RankingDialog.h; PacketBuffer and new-file placements are rejected. | High | Owner/file docs, sibling source, generated paths | UID0000MZ source placement | incorporate | applied |
| [x] | C23 | 0003WS | The exact formal CPP is the complete method in Section 22 and contains no IDA/compiler-generated names. | High | Full live behavior plus resolved dependencies | UID0003WS RECONSTRUCTION_CPP | incorporate | applied |
| [x] | C24 | 0003WS | Target formal H remains blank because UID0000BK already owns the one declaration. | High | Current owner H and generated H readback | UID0003WS RECONSTRUCTION_H | already-present | already-present |
| [x] | C25 | 0000BL | Add only friend class RankingCategoryCollection to legalize the proved direct private page-metadata access; retain private fields and existing layout. | Medium-high | Direct stores, absent setter calls, narrow caller family | UID0000BL formal H/access notes | incorporate | applied |
| [x] | C26 | 0003WS | Raise target metadata from 87/90 to 93/93 while retaining owner/emitter 0000BK, reconstructable true, and blank child position. | Medium-high | Source closure with bounded retail spelling/compiler caps | UID0003WS metadata | incorporate | applied |
| [x] | C27 | 0003WS | Preserve all valid target history but historicalize the blank-CPP blocker and reserved-footer-write claim as superseded by current evidence. | High | Current doc comparison against live MCP and support declarations | UID0003WS Status/Evidence/Changes | reject-stale | excluded-with-reason |
| [x] | C28 | 0000BK | Update the collection class and UID0001ZC aggregate with complete source-ready subcommand-3 behavior while retaining their scores and nonduplicate emitter roles. | High | Exact child/parent/source route | UID0000BK and UID0001ZC | incorporate | applied |
| [x] | C29 | 0000BL | Update record class, UID0001VN layout, and UID0000Y9 aggregate with friendship, exact local-field writes, and no reserved-tail write while retaining scores. | High | UDT, parser stores, paint/layout evidence | UID0000BL/UID0001VN/UID0000Y9 | incorporate | applied |
| [x] | C30 | 0000MZ | Update RankingDialog by-file source contract with the complete combined parser and narrow friendship while retaining 88/91. | High | Existing compilation-unit route and generated output | UID0000MZ source contract/Changes | incorporate | applied |
| [x] | C31 | 0003WT | B003 independently incorporated and executed the UID0003WT no-reserved-footer correction; the sibling now records that its parser does not write the reserved 0x40 footer tail. | High | Independent B003 implementation/execution completion plus complete 0x45CB10 decompilation | UID0003WT metadata/page transition/history | already-present | already-present |
| [ ] | C32 | 0003WS | Replace the stale manual UID0003WS and UID0001ZC coverage rows with the exact Section 28 text after callback verification. | High | Current rows omit source closure and corrected local behavior | Manual by-memory coverage | incorporate | proposed |
| [ ] | C33 | 0000BK | Replace or insert the exact affected class/file/type/aggregate/support coverage rows listed in Section 28; B001 must not edit them. | High | Read-only manual coverage comparison | Manual coverage files | incorporate | proposed |
| [ ] | C34 | 0003WS | The dated B001 ordinary-callback readback for validator-owned command 000000023654 showed one method definition, one existing declaration, one friend declaration, required includes/order, and no UID0003WS empty marker; at every later gate the supervisor rereads validator-owned generated output dynamically because command/hash identities may advance. | High | Dated callback generated CPP/H hashes and physical B001 readback | Supervisor generated readback | already-present | proposed |
| [x] | C35 | 0003WS | The body hash and exact ten-byte predecessor/six-byte successor CC fences define the target without split or range extension. | High | Raw MCP bytes, hashes, zero-xref item checks | UID0003WS range section | incorporate | applied |
| [x] | C36 | 0003WS | One caller and the complete sixteen-callee material set exhaust target reachability; external EH chunks are compiler-owned, not source children. | High | Bounded xrefs, callees, CFG chunks | UID0003WS inventories | incorporate | applied |
| [ ] | C37 | 0003WS | The dated restored IDA type/frame/comments and support UDTs are exactly recorded in Section 21; dynamic state must be reread before Gate 2B. | High | Live stack/type/comment/item queries plus verified fail-closed rollback | Supervisor Gate 2B handoff | already-present | proposed |
| [ ] | C38 | 0003WS | I01 is target-chain stage 1: pure rename from the original literal state to the exact post-I01 name while preserving the old type, all 28 frame rows, AR/AP/FR/FP, range/size/body hash/bytes, and exact code/data xrefs. | High | Unique behavior, collision-free desired name, complete I01 pre/post contract | Supervisor Gate 2B target chain I01 stage 1 | incorporate | proposed |
| [ ] | C39 | 0003WS | I02 is target-chain stage 2 and may start only from the complete I01 poststate; set_type retains the post-I01 name/storage receiver, changes only `arg_0@0x84C/0x4/_DWORD` to `packet@0x84C/0x4/const unsigned __int8 *`, preserves `arg_4@0x850/0x4/_DWORD`, the other 26 rows, and all non-type state, and produces the complete required I03 prestate. | High | Observed public set_type readback, ignored return, immutable packet reads, usable storage UDT, complete staged frame/type contract | Supervisor Gate 2B target chain I02 stage 2 | incorporate | proposed |
| [ ] | C40 | 0003WS | I03 is target-chain stage 3 and may start only from the complete I02 poststate; it changes only FP from absent to the exact behavior text while preserving the post-I02 name/type/all 28 rows, including `packet@0x84C/0x4/const unsigned __int8 *` and unchanged `arg_4@0x850/0x4/_DWORD`, plus AR/AP/FR, range/size/body hash/bytes, and exact code/data xrefs. | High | Complete packet semantics and complete corrected staged comment contract | Supervisor Gate 2B target chain I03 stage 3 | incorporate | proposed |
| [ ] | C41 | 0003WS | I04 applies only the exact cleanup-chunk repeatable address comment through public semantic channel set_address_repeatable_comments; deterministic channels are independently AR absent, AP equal to the exact I04 proposed text, FR not independently applicable, and FP not independently applicable. | High | EH map, stack offset, shared-tail route | Supervisor Gate 2B I04 | incorporate | proposed |
| [ ] | C42 | 0003WS | I05 preserves without mutation the already-present shared-tail channels and routes: AR absent, AP equal to the exact existing text, FR not independently applicable, and FP not independently applicable. | High | Current literal AP and two inbound cleanup jumps | Supervisor Gate 2B I05 | already-present | proposed |
| [ ] | C43 | 0003WS | I06 and I07 apply only exact repeatable address comments: I06 independently protects AR absent, AP equal to the exact I06 proposed text, FR not independently applicable, and FP not independently applicable; I07 independently protects AR absent, AP equal to the exact I07 proposed text, FR not applicable, and FP not applicable. | High | Prologue handler ref, FuncInfo pointer, unwind map | Supervisor Gate 2B I06/I07 | incorporate | proposed |
| [ ] | C44 | 0000BL | I08 preserves without mutation the constructor-constant channels, 16 bytes, and two parser xrefs: AR absent, AP equal to the exact existing text, FR not applicable, and FP not applicable. | High | Current item/comment/raw bytes/xrefs | Supervisor Gate 2B I08 | already-present | proposed |
| [x] | C45 | 0003WS | No target-local string, global, resource, vtable, RTTI, alternate owner, source-authored helper, new split, or independent source file exists. | High | Complete negative scans and boundary/owner analysis | UID0003WS negative/range/ownership sections | incorporate | applied |
| [x] | C46 | 0003WS | Remaining uncertainty is limited to retail spellings, exact original friendship syntax, packet-size metadata, and compiler instrumentation; it caps 93/93 but does not block source emission. | Medium-high | Exhausted current binary/docs/generated/report routes | UID0003WS score/open questions | incorporate | applied |
| [ ] | C47 | 0003WS | The accepted callback changed only the seven authorized ordinary docs and this report, used scoped validators without manual generated/coverage edits, made no IDA mutation, and did not run execute_report or lifecycle commands. | High | Authorized destination audit, scoped receipts, lease and prohibited-action checks | Validator Results/Changed Files | already-present | proposed |
| [ ] | C48 | 0003WS | This report contains no executable scripting or operational runbook; only formal C++ insertion text appears in typed fences. | High | Final literal fence and scripting-token audit | Report hygiene/Validator Results | already-present | proposed |

Phase status: exact parity is `48/48`; allocation is exactly `35` checked and `13` unchecked. Ordinary target/support implementation, C35-C36 range/inventory incorporation, scoped validation, C24/C31 already-present states, and C27 exclusion are reflected as checked. Unchecked supervisor-owned proposed rows are C32-C34, C37-C44, and C47-C48.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000023812","destination_path":"executed-b-agent-research/B001/0003WS-RankingCategoryCollectionParseInitialCategoryPageResponse-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0003WS-RankingCategoryCollectionParseInitialCategoryPageResponse-empty-emitter-source-quality.md","timestamp":"2026-08-15T00:35:30-04:00","uid":"0003WS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
