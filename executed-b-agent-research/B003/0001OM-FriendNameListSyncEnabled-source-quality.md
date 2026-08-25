** TARGET-REPORT-UID:0001OM **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001OM FriendNameListSyncEnabled Ownership / Source-Quality Research


## Finalized Report / Current Recommendation

- Implemented recommendation: exact storage [UID:0001OM] is the sole external-linkage definition of source-facing one-byte `bool g_friendNameListSyncEnabled`, initialized `true`, in `NexusTK/social/FriendListDialog.cpp` through semantic global UID0000PG.
- Implemented target disposition: exact `0x0066dee0-0x0066dee1` range, owner/emitter UID0000PG, reconstructable true, blank optional position, `Nested:0`, score `92/94`, exact Item Summary, and byte-exact R1.
- Implemented support disposition: validator command 15432 preserved UID0000PG while moving `by-global/byte_66DEE0.md` to `by-global/g_friendNameListSyncEnabled.md`, updated the registered path and reference union, retained owner/emitter UID0000JN, set position `0`, raised it to `92/94`, and installed container-only R2. The cross-TU `extern bool g_friendNameListSyncEnabled;` remains a separately documented shared-header requirement and is absent from the generated `.cpp`.
- Implemented associated closure: UID00005J is `90/93` with byte-exact no-field R3 at position `10`; UID0001DS is `92/93` with byte-exact C++03 R4; UID0000JN is `91/93`. Exact virtuals are `OnControlCommand(int,int)` at primary slot `+0x48` and protected `SetHoverControl(int)` at `+0x58`; the optional send is the Socket member call.
- Implemented protocol support: non-emitting routing item UID0000UP is `90/93` with its false/no-owner/blank-emitter/blank-formal disposition preserved and complete paired protocol/source-boundary evidence.
- Raw duplicate: retain UID0001AZ at `86/90`, owner/emitter UID0000L3, reconstructable true, with its existing no-standalone-body formal. Fresh live evidence proves exact source equivalence but still proves no independent entry route.
- Confidence: very strong for exact storage, initialization, type, refs, packet/UI behavior, owner/emitter route, linkage, class size, virtual slots, boundaries, and formal source shape. Exact original lexical spelling remains unavailable and caps confidence below `95`.

## Supporting Research

- This is a fresh target-specific pass. Existing reports were used as search leads and were revalidated against current ordinary docs, current generated output, the input image, and live IDA MCP database `9b0396a3`.
- Exact search terms: `UID:0001OM`, `0001OM`, `0x0066dee0`, `FriendNameListSyncEnabled`, `byte_66DEE0`, `g_friendNameListSyncEnabled`, and `0x00514380`.
- Exact searched roots and outcomes:
  - `executed-b-agent-research/**`: twelve matching historical reports. Direct target/support matches were B004 UID0001AZ raw-handler research, B001 UID0001DS FriendListDialog research, B001 UID0001AW MapPane split research, B004 UID0000L3 MapPane source-family research, B015 UID00037T dispatcher research, and B005 UID0001AV SaveUserSettings research. B007 UID0000M7 and B001 UID0001DW/UID00027W supplied adjacency context. B001 UID0001KM, B004 UID0001AY, and B009 UID0002A9 were incidental family/global mentions. None was accepted without current revalidation.
  - `tools/leaser/Agents/Agent-B001/research/**` through `Agent-B005/research/**`: no current active report match.
  - `tools/leaser/Agents/Older-Research/**`: no match.
  - `tools/leaser/Agents/SpecialReports/**`: no match.
  - `archived/**`: no match.
- Direct historical artifact checks:
  - executed B004 UID0001AZ report SHA256 `055AA28F5FE80C51A90D6F10AD7084035CAD7FA64AA99847FACBC46A7CB5480A`, 34,607 bytes / 441 lines: its exact raw range and covered-by disposition remain valid after fresh MCP comparison.
  - executed B001 UID0001DS report SHA256 `92A54269BF45655EF06B28624A7D7A8EF46CD0971C17AD70DAD1E5FF814985B9`, 25,608 / 481: its range, resource layouts, 20-slot behavior, and save ordering remain valid; its source-facing virtual names and free-style Socket call are superseded by current vtable/class/helper evidence.
  - executed B001 UID0001AW report SHA256 `76E905B12F791497870ED35D4DCABB7EAA06379B1FE84C6E76A8BD38A7C7A42A`, 49,783 / 649: the live dispatcher ownership and raw sibling distinction remain valid.
  - executed B004 UID0000L3 report SHA256 `010AA02E28B522238A77E890D631F9EA670B69D38D85CCE64A24224DC5508ACE`, 46,582 / 505: MapPane source ownership remains valid.
  - executed B015 UID00037T report SHA256 `BA37D273FC831EE08F3FBFEADFCE7288452C666D08454F3DA984ECEB47B7A448`, 61,652 / 392: the opcode `0x6a` branch remains inside the live dispatcher rather than a standalone function.
  - executed B005 UID0001AV report SHA256 `2375F3BA183C08E3F303E1E003DAB77E0700403C0D5D1A851791DFF6B124D468`, 106,598 / 1,267: optional friend sync precedes unconditional `SaveUserSettings`, then close/remove.
- Historical report-only lease checkpoint `2026-07-20T20:04:02Z` contained no active leases. During the callback B003 used one short ordinary lease at a time and released each immediately after scoped validation. Final readback contains no active lease; other-agent lease state remains externally mutable and is not asserted indefinitely.
- No Wave2/Wave3 current authority was found or used. Any such wording in old material is stale under the project skill.

## Target

- Target UID: `0001OM`.
- Target path: `by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md`.
- Implemented target hash: `A575C474FE585FF07A69C0A06AC95AFE75E8935D37B1CC9606088698A620D045`.
- Current metadata: `92/94`, `CANONICAL_OWNER:0000PG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000PG`, blank `EMITTER_POSITION_OPTIONAL`, byte-exact R1, and `Nested:0`.
- Historical pre-callback tracker command/header 15419 recorded the old `86/90` blank-formal state. Current read-only validator-owned tracker header is external command `000000015456`, refreshed `2026-07-20T16:49:16-04:00`, SHA256 `19625F36DED092FF386B2DE22B37A2BB6F811080B17BDAD2CF789834BBB6E19E`, 1,532,009 bytes / 6,206 lines. Command 15448 is an intermediate external deferred-refresh epoch. Exact tracker path/count/status remains validator-owned mutable state.
- Manual by-memory coverage at the callback evidence epoch still records the stale pre-callback `86%` row; its application state is external supervisor-owned and the exact no-loss replacement remains supplied below. B003 did not edit manual coverage.

## Current Target State

- UID0001OM now documents the initialized byte, exact hashes and three refs, opcode/UI flows, external bool/type/initializer/linkage, owner/emitter route, raw duplicate, negative alternatives, exact boundary/padding, score rationale, history, exact Item Summary, and R1 at `92/94`.
- UID0000PG now exists only at `by-global/g_friendNameListSyncEnabled.md`, SHA256 `3D13221DDCB9A66C8BA4C250B692106B42CB19A44BEF98EA2B4A15EF336ECD3A`, at `92/94`, position `0`, with R2 and source/header/one-definition evidence. The old path is absent and the full ordinary union has zero stale old-path links.
- UID00005J is `90/93` with complete R3 before `[[CHILDREN]]`; UID0001DS is `92/93` with exact R4; UID0000JN is `91/93`; UID0000UP is `90/93` and remains non-emitting.
- B003 waited generated command/header 15447 produced SHA256 `653C058AB8DADB9388C787EAB57A963F6C525FD860B7B77F122183739E385B29`. A later read-only external refresh advanced the current header to command `000000015456`, refreshed `2026-07-20T16:49:16-04:00`, SHA256 `12250035A816A2E6B8FD6210D6539E4A81D687616AA1CE3AD95AF357C62D4FF5`, 5,047 bytes / 155 lines, with identical B003 semantics. It contains the sole flag definition once, same-TU extern zero, class at line 12 closed at line 22 before methods, one constructor/destructor/OnControlCommand/SetHoverControl each, direct left-ten then right-ten loops, canonical controls, `ReadText`, one Socket member call, and zero rejected layout/C++11/old-name/free-style/compiler forms.
- Empty Emitter Markers for UID0000PG, UID0001OM, and UID00005J are zero. The sole remaining marker is accepted compiler-only UID00038A at line 155; no wrapper body is handwritten.
- Commands 15346/15372/15379/15419 are explicitly historical pre-callback generated epochs. Commands 15448 and 15456 are later external refresh epochs; command 15456 retains the command-15447 FriendListDialog semantic result byte-for-byte below its mutable header.
- B003 performed the authorized ordinary implementation and validators listed below. B003 manually edited no coverage/generated/tracker/audit/supervisor/validator-state/IDA file and ran no report execution, probe, move, archive, or lifecycle command.

## Executive Recommendation

1. Exact storage is preserved on the renamed semantic global page with one external definition initialized `true`.
2. UID0000PG now carries container-only `[[CHILDREN]]`; exact child UID0001OM emits the sole `.cpp` definition. External linkage is required because accepted `MapPane.cpp` and `FriendListDialog.cpp` routes access the same storage directly, while the corresponding `extern` declaration remains a shared-header requirement and is not emitted beside the definition in `FriendListDialog.cpp`.
3. The validator-aware UID-preserving rename for UID0000PG is complete. All ordinary references use the current path without changing UID or semantic ownership.
4. The associated FriendListDialog class emitter is closed with the complete no-added-field declaration. Allocation size `620` / `0x26c` equals current `DialogPane` size, so no derived fields are present.
5. UID0001DS is corrected where fresh evidence superseded the prior first draft: canonical `EPFImageControlPane`, `ImageButtonControlPane`, and `TextEditControlPane` constructors; the binary's complete left-column-then-right-column insertion order; `ReadText`; current inherited dialog APIs; exact virtual method names; exact Socket member call; exact close/remove form; and exact DialogPane create/show/slide calls. Both asset layouts, all 20 config slots, all constants, trim/store order, save order, destructor exclusions, and range evidence are preserved.
6. The live dispatcher and raw duplicate distinction is preserved. The opcode branch remains an inline part of UID00037T's monolithic dispatcher, while UID0001AZ has no function object, caller, pointer occurrence, or entry xref. Neither is represented as a second standalone source function.

## Supervisor Active Recheck

- Supervisor accepted exact pre-callback SHA `36DB93BFC61CEF50AA137BB657E927361C62ED8F198DDE9397012A8586C1992E`; the bounded implementation callback is complete.
- No split-first repair is needed for the one-byte target. Its exact predecessor, three-byte successor pad, and next static data item already have separate pages.
- Every direct route remains resolved and implemented: live MapPane writer, raw duplicate writer, FriendListDialog reader, Socket sender helper, source owner, external linkage, sole `.cpp` definition placement, separate shared-header declaration requirement, and generated ordering.
- No source-bearing child was created. The UID-preserving UID0000PG move completed through normal validator mapping/reference propagation without a duplicate.
- C01-C20 and every checklist row are terminal with destination, validator, generated, manual-handoff, and lease proof below.

## Inference Research Guidance Check

- IDA fact, documentation evidence, and inference are separated throughout this report.
- IDA facts: exact bytes, function objects, three target xrefs, three helper refs, branch instructions, one-byte packet read, vtable refs/slots, constructor allocations, and no raw entry route.
- Documentation facts: current ownership graph, source paths, accepted class contracts, current support scores/formals, historical corrections, generated state, tracker row, and manual coverage rows.
- Inference: best source spelling, separate shared-header declaration placement, feature-file ownership, and natural human source expression. Each inference is constrained by exact binary behavior and current project conventions.
- Generated labels `byte_66DEE0`, `g_isCashShopEnabled`, cash-shop/inventory helper names, `OnOkCommand`, and `OnFocusStateChanged` were treated as suspect rather than authority.
- Physical `.data` adjacency to OptionPane/Palette data was not treated as source ownership.
- Absence of a raw duplicate entry route was not used to erase source semantics; it establishes covered-by status against the live dispatcher branch.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Resolution |
| --- | --- | --- |
| One-byte type | Both writers use byte `setnz`; the reader uses a byte condition; the initial image value is exactly `01`; no neighboring byte is referenced as part of a wider scalar. | Source type is `bool`, size one under the accepted 32-bit MSVC model. `char`, `unsigned char`, bitfield, and wider integer are rejected. |
| Initialization | The target is file-backed `.data`, raw byte `01`; there is no dynamic initializer xref and only the three behavior refs exist. | Emit explicit `= true`. Omitted initialization would produce zero and is wrong; runtime-only initialization is unsupported. |
| Name | All refs participate in friend-name-list enable/update behavior. | `g_friendNameListSyncEnabled` is the best project-consistent descriptive name. Raw and cash-shop aliases are historical only. |
| Linkage | MapPane and FriendListDialog are separate accepted TUs and both use the same storage directly; no accessor exists. | External namespace-scope linkage: UID0001OM emits the one `.cpp` definition. A shared declaration header must expose `extern bool g_friendNameListSyncEnabled;` to consuming TUs, but the current `.cpp` emitter must not repeat that declaration beside the definition. `static`, anonymous-namespace storage, function-local static, duplicate definitions, and same-TU redundant `extern` emission are rejected. |
| Owner | MapPane writes server state; Socket serializes; FriendListDialog owns the only source UI reader and current feature definition route. | UID0000JN / `NexusTK/social/FriendListDialog.cpp` remains the definition owner. MapPane and Socket remain consumers/support. |
| Global page identity | Heading and source name are semantic, but the historical raw by-global filename was inconsistent with the source-ready symbol. | UID-preserving rename to `by-global/g_friendNameListSyncEnabled.md` is complete; all ordinary links are updated, and exact manual-link handoff remains supervisor-owned. |
| Live opcode semantics | Cursor starts at one, byte helper reads one payload byte and increments cursor, `setnz` stores the flag, true immediately sends, false skips send, both paths return true. | Preserve exact inbound opcode `0x6a` behavior; no packet-width or return ambiguity remains. |
| Raw duplicate | Exact 58-byte body repeats read/store/conditional-send and ends with `ret 4`, but IDA has no function object, xref, caller, absolute pointer, or RVA pointer to its start. | Retain source-shaped raw page covered by live dispatcher. Do not emit a second function and do not classify it as padding. |
| FriendListDialog controls/read | Constructor decompile proves `EPFImageControlPane` at `0x4991f0`, image-id-14 `ImageButtonControlPane` at `0x495bf0`, then ten left-column and ten right-column `TextEditControlPane` constructions at `0x498920`; config offsets advance `0..36` then `40..76`, so insertion ids `2..11` and `12..21` map exactly to config slots `0..9` and `10..19`. Handler then reads controls `2..21` through `TextEditControlPane::ReadText(...,64)`, stores the matching four-byte config entries, trims left/right, conditionally sends, and always saves/closes/removes. | R4 uses the canonical classes/signatures and two consecutive ten-entry loops. Generic control names, `GetText`, and interleaved left/right insertion are rejected decompiler-era/source-draft artifacts. |
| Socket helper | Call site loads `g_packetSender` into ECX and performs a no-explicit-argument thiscall. Socket class already declares the method. | Use member expression on `g_packetSender`; reject free function and CashShopRequest ownership. |
| Dialog virtual names | Primary vtable data refs place UID0001DS handlers at `+0x48` and `+0x58`; DialogPane defines those slots as `OnControlCommand(int,int)` and `SetHoverControl(int)`. | Replace historical callback aliases in class and method definitions. |
| Dialog layout | All three constructor sites allocate 620 bytes; current DialogPane layout is exactly `0x26c` / 620. | FriendListDialog adds no fields. The class declaration contains methods only. |
| Constructor helper source shape | Current DialogPane documentation resolves `AddControl`, hover/focused/pending setters, background setter, OnCreate, OnShow, and vertical slide calls. Canonical control pages resolve the five-argument EPF image, two-argument image button, and eleven-argument text-edit constructors; `sub_584540` is the established `WideString::c_str()` accessor. Fresh live decompile shows two physically duplicated asset branches whose rectangle dimensions, row starts/steps, resources, and final bounds are instruction immediates/direct literal references; no constructor load or xref identifies a `FriendListLayout` object or either proposed namespace-scope layout instance. | R4 uses those accepted APIs and stack-local `RectBounds` values, expresses each observed branch directly in C++03, and removes the unsupported aggregate/table objects. Raw allocation sizes, helper addresses, invented explicit child ids, C++11 `constexpr`, and unproved namespace-scope layout storage are absent. |
| Boundary | Predecessor ends at `0x0066dee0`; target is one byte; `0x0066dee1-0x0066dee4` is unreferenced zero padding; next data starts at `0x0066dee4`. | No split, merge, widening, or padding reassignment. |
| Source spelling certainty | No PDB/source symbol proves the exact original lexical token. | Use the strongest descriptive project spelling and cap confidence at 94 rather than leaving code blank. |
| Dispatcher source body | The live write is an inline switch case inside a `0x1176`-byte dispatcher; splitting that basic block into a standalone method would falsify source shape. | UID00037T remains verify-only at `88/90`; this report documents the exact case but does not create a false function child. |

Rejected alternatives:

- `g_isCashShopEnabled`, `g_cashShopEnabled`, and CashShopRequest ownership: no cash-shop object, request, opcode, resource, or caller exists in the target route.
- `g_friendListEnabled`: too broad because the flag controls synchronization, not dialog availability.
- `g_sendFriendNameList`: action-shaped name for persistent state; the flag is both server-written and later UI-read.
- MapPane ownership: writer context does not transfer feature ownership; FriendListDialog and MapPane are separate TUs.
- Socket ownership: serializer ownership does not transfer flag ownership; Socket never owns or writes the flag.
- OptionPane/Palette ownership: physical adjacency is linker layout only; their words/data have separate xrefs and pages.
- A standalone raw-handler function: contradicted by zero entry refs and live dispatcher equivalence.
- File-local `static`: contradicted by direct cross-TU consumers under accepted source placement.
- Wider integer or packed field: contradicted by exact one-byte references and separate successor padding.
- Blank target/global C++: contradicted by exact storage, source linkage, initializer, owner, sole-definition route, and semantic child-container route.

## Evidence Standards Used

- Mandatory evidence ladder: live IDA MCP health, bounded bytes, function lookup, xrefs, decompilation, disassembly, vtable/data refs, callers, current ordinary docs, current generated C++, current tracker/manual rows, historical reports as leads, PE raw mapping, and negative pointer/route searches.
- Binary identity: input image SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, MD5 `4247E04E20B65D6414C7238AA8FF5515`, file size 2,679,296 bytes, imagebase `0x00400000`.
- Target byte and xrefs are direct facts. Name and source file are evidence-backed inference because original symbols are absent.
- Confidence remains below final-original-source certainty only for exact lexical spelling and explicit stylistic token choices, not behavior, type, range, route, or first-draft C++ eligibility.

## Evidence Checked

- Fresh repair-pass MCP `idb_list` returned the active NexusTK database `9b0396a3`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID 15732.
- Fresh repair-pass `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, 2,067 cached strings. The earlier `2026-07-20T15:06:26-04:00` health result is preserved as historical evidence from the original report pass.
- Bounded `get_bytes`, `lookup_funcs`, `xrefs_to`, `decompile`, `disasm`, and `func_profile` calls succeeded for the target, live dispatcher branch, raw duplicate neighborhood, packet reader, FriendListDialog constructor/handler/class support, Socket helper, and vtable/callers. A fresh repair-pass `lookup_funcs(0x0053f2c0)` returned `sub_53F2C0`, size `0x541`, and a bounded decompile reconfirmed the exact control classes/arguments, distinct left-then-right ten-entry loops, separate immediate modern/classic rectangle flows, and absence of any referenced layout aggregate/table.
- PE section mapping and raw image hashes were checked independently from IDA naming.
- Current target/global/class/file/aggregate/raw/helper/item/MapPane/adjacency pages were read; intended destination hashes are recorded below.
- Canonical control/source dependencies were independently reread: `DialogPane`, `TextEditControlPane` plus its full constructors, `EPFImageControlPane` plus its constructor, `ImageButtonControlPane`, `g_useEpfAssets`, and `MainUiLayerSlots`. They resolve every R4 control/API/type call without requiring edits to those verify-only pages.
- Current generated `FriendListDialog.cpp` and `MapPane.cpp`, current tracker, all applicable manual coverage files, and current lease ledger were read.
- Historical reports were searched under every required root using the exact term set above.
- Negative checks: no refs to `0x0066dee1-0x0066dee3`, no function at target/raw start, no raw-start xrefs, no raw-start absolute/RVA pointer occurrences, no wider access, no competing writer/reader, no initializer function, no second storage, no cash-shop route, no independent raw emitter, and no target-local vtable/RTTI source.
- No evidence route failed. IDA MCP remained healthy; no fallback-only conclusion was used.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Evidence-time IDB `9b0396a3` was healthy in both the original pass and final repair pass; bounded target/function calls, including fresh constructor lookup/decompile, succeeded. | very strong | `idb_list`, `server_health`, bounded `get_bytes`/lookup/decompile | UID0001OM Evidence; support provenance | incorporate | applied |
| C02 | Exact target is one byte at `0x0066dee0`, image value `01`, byte SHA256 `4BF5122F344554C53BDE2EBB8CD2B7E3D1600AD631C385A5D7CCE23C7785459A`. | very strong | PE mapping and MCP bytes | UID0001OM Layout/Evidence/Item Summary | incorporate | applied |
| C03 | Source type/initializer are `bool` and `true`; no wider field or runtime-only initializer exists. | very strong | byte-width writers/reader, xrefs, PE value | UID0001OM; UID0000PG | incorporate | applied |
| C04 | Exactly three direct refs exist: live write `0x508aff`, raw write `0x51439c`, UI read `0x53f8dc`; neighbors `dee1-dee3` have zero refs. | very strong | fresh `xrefs_to` | UID0001OM; UID0000PG | incorporate | applied |
| C05 | Live opcode `0x6a` reads one byte from cursor 1, stores nonzero state, sends immediately only when true, and returns true in both states. | very strong | dispatcher disassembly, byte-reader decompile | UID0001OM; UID0000PG; UID0000UP | incorporate | applied |
| C06 | UID0001AZ is a 58-byte no-entry raw duplicate covered by the live branch, not padding and not standalone source. | very strong | raw hash, no function/xrefs/pointers, semantic comparison | UID0001AZ verify-only/current formal | already-present | already-present |
| C07 | FriendListDialog constructs canonical EPF image/image-button controls and twenty text edits in left-ten then right-ten config order; its handler reads matching ids `2..21`, trims, optionally sends, always saves, closes, and removes in exact order. | very strong | fresh `sub_53F2C0` and `sub_53F830` decompiles; canonical control formals | UID0001DS; UID00005J; UID0000JN | incorporate | applied |
| C08 | `0x574e50` is `Socket::BuildAndSendFriendNameListSync()` and the dialog uses a member call on `g_packetSender`. | very strong | thiscall ECX, helper/class formal, caller set | UID0001DS R4 and prose | incorporate | applied |
| C09 | Definition owner remains UID0000JN `NexusTK/social/FriendListDialog.cpp`; MapPane/Socket are consumers. | strong | cross-TU use, feature behavior, current tree | UID0001OM; UID0000PG; UID0000JN | incorporate | applied |
| C10 | External linkage requires one definition and a cross-TU declaration, but only UID0001OM R1 emits the `.cpp` definition; UID0000PG R2 is child-container-only and the `extern` belongs in a separately documented shared header, not redundantly in the same generated TU. | very strong | separate accepted TUs, direct storage refs, no accessor, generated same-TU route | UID0000PG R2/source prose; UID0001OM R1 | incorporate | applied |
| C11 | Best source name is `g_friendNameListSyncEnabled`; raw/cash-shop alternatives are historical or rejected. | strong | complete use semantics and negative routes | UID0000PG rename; all ordinary links | incorporate | applied |
| C12 | Target boundaries stay exact; UID00027X remains the separate three-byte zero pad and UID00027Y begins at `0x0066dee4`. | very strong | bytes/xrefs/current pages | UID0001OM; verify-only UID27W/27X/27Y | incorporate | applied |
| C13 | UID0001OM becomes `92/94`, same owner/emitter/true/blank position/Nested0, with R1 and exact summary. | very strong | C01-C12 | target metadata/formal | incorporate | applied |
| C14 | UID0000PG receives the validator-managed UID-preserving semantic path rename, `92/94`, position 0, container-only R2, separate-header/sole-definition source-history evidence, and default-validator mapping/reference propagation followed by a no-loss link-union reread. | strong | name/linkage/owner/generated ordering and documented validator rename contract | renamed by-global target | incorporate | applied |
| C15 | UID00005J is exactly DialogPane-sized `0x26c`, has no fields, and overrides `OnControlCommand` and protected `SetHoverControl`; install R3 and `90/93`. | very strong | three 620-byte allocations, vtable slots, DialogPane contract | by-class/FriendListDialog.md | incorporate | applied |
| C16 | UID0001DS installs exact C++03 R4 with direct observed modern/classic branches, canonical control types/signatures, left-ten/right-ten insertion, `ReadText`, virtual/helper/source corrections, and becomes `92/93` without losing layout facts, 20-slot behavior, ranges, destructor exclusions, or history; unsupported `FriendListLayout` objects and all post-era syntax are rejected. | strong | current body plus fresh constructor/handler/virtual/helper evidence and no layout-object refs | aggregate by-memory page | incorporate | applied |
| C17 | UID0000JN becomes `91/93` and records complete file ordering, global/class/method inventory, exact source route, and compiler exclusions. | strong | R1-R4 route and current source tree | by-file/FriendListDialog.md | incorporate | applied |
| C18 | UID0000UP becomes `90/93`, remains NONE/FALSE/blank formal, and records the exact paired protocol and source/compiler boundary. | very strong | complete inbound/outbound/UI/raw evidence | by-item/FriendNameListSyncOpcodes.md | incorporate | applied |
| C19 | UID00037T, UID0001AZ, UID0001HX, MapPane class/file, Socket, DialogPane/control-class/global dependencies, adjacency pages, and unrelated dependencies retain routes/formals/scores except rename-managed links and exact bounded prose. | very strong | current readback and scope analysis | named verify-only/support pages | already-present | already-present |
| C20 | Exact supervisor-owned manual coverage replacements and expected generated sole-definition/zero-same-TU-extern/no-marker assertions are supplied; R4 generated checks exclude `constexpr` and `FriendListLayout`; B003 does not edit those files. | very strong | current manual rows, B003 waited command 15447, current external command 15456, exact R1-R4 parity | manual handoff/generated verification | incorporate | applied |



### Callback Implementation Proof

| Claim | Implementation proof |
| --- | --- |
| C01 | Evidence-time MCP session `9b0396a3` health and bounded byte/function/decompile facts remain incorporated in UID0001OM and support prose; callback did not mutate IDA. |
| C02 | UID0001OM current hash `A575C474FE585FF07A69C0A06AC95AFE75E8935D37B1CC9606088698A620D045` records exact one-byte range/value and target SHA; validator 15436 exit 0 / ok 1. |
| C03 | UID0001OM R1 and UID0000PG source-closure prose state exact `bool`/`true`, reject wider/runtime initialization, and generate the one definition once. |
| C04 | UID0001OM and UID0000PG retain the exact two writes/one read and zero neighbor refs; no range or padding route changed. |
| C05 | UID0001OM and UID0000UP record cursor-1 byte read, nonzero assignment, true-only immediate send, and containing-dispatch success behavior; validators 15436/15445 passed. |
| C06 | UID0001AZ remained `86/90` with its existing covered-by formal/no-entry evidence; command 15432 changed only its registered UID0000PG link. |
| C07 | UID0001DS hash `4C2468D52C5DCB394E1A18B4C4EB91F639E9261FD3F594E6DFF789E065E29C77` contains exact R4 and full control/order behavior; validator 15440 passed. UID00005J/UID0000JN carry matching declarations/inventory. |
| C08 | R4 contains exactly one `g_packetSender->BuildAndSendFriendNameListSync()`; generated command 15447 contains it once and the free-style expression zero times. |
| C09 | UID0001OM, renamed UID0000PG, and UID0000JN preserve `NexusTK/social/FriendListDialog.cpp` ownership; MapPane and Socket remain consumers/support. |
| C10 | R1 body hash `131E50D38437393FAD3E63EF00155CAB9BEB68D08F7275E7475F52A6D262D57E` is the sole definition; R2 body hash `19FEC47C0DE54A582B7297C6EF81D03DF3219387E6591E86B64D9C0CFD2C81DD` is only `[[CHILDREN]]`; generated same-TU extern count is zero. |
| C11 | Validator 15432 preserved UID0000PG while moving to `by-global/g_friendNameListSyncEnabled.md`; old path is absent and ordinary stale-link count is zero. |
| C12 | UID0001OM retains exact end `0x0066dee1`; verify-only UID00027X/UID00027Y padding/successor pages and metadata remain unchanged. |
| C13 | UID0001OM is `92/94`, same owner/emitter/true/blank position/`Nested:0`, exact Item Summary and R1; validator 15436 exit 0 / ok 1. |
| C14 | Renamed UID0000PG hash `3D13221DDCB9A66C8BA4C250B692106B42CB19A44BEF98EA2B4A15EF336ECD3A` is `92/94`, position 0, exact R2; validator 15432 reports path_update 1, uid_link_update 39, reference_source_path_update 7, exit 0 / ok 1. |
| C15 | UID00005J hash `8CF62C1363A72DC37E1302047AB032D0219B085F2D177A025F9B2647122CCF44` is `90/93`, position 10, exact no-field R3; validator 15437 passed and generated class closes before children. |
| C16 | UID0001DS is `92/93`; R4 body hash `F446469FB3C81B493B0709A562C98175F9E0F0156B96524C854F388EA9125B2E` exactly matches the report, while generated rejected-layout/post-era/old-name counts are zero. |
| C17 | UID0000JN hash `25AD47135DE7AD65EC5EC478B9CDE3DCB0C2566B7DE215D967ED057EBD171498` is `91/93` with complete ordering/route/compiler evidence; validators 15442 and waited 15447 passed. |
| C18 | UID0000UP hash `43F2180863C49E40DFD06D3E20EAB91348DE14958E8756A1B2CB28852E657AC4` is `90/93`, still NONE/FALSE/blank formal, with exact protocol/source-boundary evidence; validator 15445 passed. |
| C19 | Verify-only scores/routes/formals remain unchanged; normal command 15432 propagated only the semantic UID0000PG path across the complete fifteen-page ordinary union, and final search finds zero stale old paths. |
| C20 | Exact supervisor-owned manual rows remain supplied and unapplied by B003 against the current external coverage union. Waited generated command 15447 proves the sole-definition, zero same-TU extern, zero target/global/class markers, exact R1-R4 structure, and rejected-form counts; only compiler-only UID00038A marker remains. |
## Positive Evidence Summary

- Raw image and MCP both show exact initialized byte `01` at the one-byte target.
- Three and only three xrefs form a coherent state lifecycle: two equivalent server-packet writes and one social-dialog read.
- Both write routes call the same Socket helper only when the new value is true.
- The UI read occurs only after all 20 names are copied and trimmed and before unconditional profile save/close/remove.
- Helper `0x574e50` independently serializes the same 20 config slots into opcode `0x77`, deduplicated into count plus 13-byte records.
- Separate accepted source routes prove external linkage: MapPane writes, FriendListDialog defines/reads, Socket sends. They require a shared-header declaration but only one `.cpp` definition.
- Three FriendListDialog callers each allocate exactly 620 bytes, matching DialogPane's complete `0x26c` layout and proving no derived fields.
- Vtable refs exactly match DialogPane primary slots `+0x48` and `+0x58`, closing source method names/access.
- Constructor control calls resolve to the current canonical EPF image, image button, and text-edit classes; two separate ten-iteration loops preserve exact config-slot/control-id identity instead of interleaving columns.
- The fresh repair-pass constructor body carries all modern/classic dimensions as instruction immediates and all resources as direct literal refs; no data ref/load/xref supports the rejected `FriendListLayout` instances.
- Current project names, source tree, and generated structure support one sole-definition/container/class/body route with a separately documented header declaration and no raw address syntax, compiler artifacts, C++11 syntax, or unbacked layout-data objects.

## IDA MCP Facts

- Evidence-time database: `9b0396a3`; original and final repair-pass health `ok`; auto-analysis, Hex-Rays, and strings cache ready.
- `lookup_funcs(0x0066dee0)`: not a function.
- `get_bytes(0x0066dedc,16)`: `28 00 28 00 01 00 00 00 64 12 62 00 53 00 55 00`.
- Target byte SHA256: `4BF5122F344554C53BDE2EBB8CD2B7E3D1600AD631C385A5D7CCE23C7785459A`.
- Successor three zero bytes SHA256: `709E80C88487A2411E1EE4DFB9F22A861492D20C4765150C0C794ABD70F8147C`.
- Live branch range `0x00508ae3-0x00508b20`: 61 bytes, raw offset `0x00107ee3`, SHA256 `4AABB1EC390B593A8EC4F31A2D090C447E8FBE410808D262510C0E2BE670164B`.
- Raw duplicate `0x00514380-0x005143ba`: 58 bytes, SHA256 `85D29FFC817B1143FDCA4F3D14358BCFCCD18E9248A0F2F04BD5596FB32B0E3F`; six-byte following `0xcc` pad SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`.
- Function objects: live dispatcher `sub_507C90` size `0x1176`; packet byte reader `sub_575710` size `0x13`; FriendListDialog handler `sub_53F830` size `0xf1`; Socket helper `sub_574E50` size `0x51b`; next raw-neighbor function `sub_5143C0` size `0xbc`.
- No function exists at raw start `0x00514380`.
- Exact target xrefs: `0x00508aff` write in live dispatcher, `0x0051439c` raw write with no function owner, `0x0053f8dc` read in FriendListDialog.
- Exact helper refs: `0x00508b14`, `0x005143ad`, and `0x0053f8ed`.
- No refs exist to `0x0066dee1`, `0x0066dee2`, or `0x0066dee3`; `0x0066dee4` has its own three OptionPane data refs.
- Packet byte reader returns byte at `packet + cursor`, increments cursor once, and returns the byte.
- Live branch uses `setnz byte_66DEE0`; false joins shared true return at `0x00507dca`, true calls Socket helper then returns true.
- FriendListDialog primary vtable begins at `0x00620ee4`; its handler refs are `0x00620f2c` (`+0x48`) and `0x00620f3c` (`+0x58`). Secondary/tertiary tables begin at `0x00620f44` and `0x00620f74`.
- `sub_53F930` is a four-instruction tail jump to DialogPane `SetHoverControl` at `0x0049fc00`.
- Constructor refs at `0x0053e115`, `0x005a7112`, and `0x005bd151` are each preceded by allocation size decimal `620` / `0x26c`.
- Fresh `sub_53F2C0` decompile resolves the constructor's control calls as `sub_4991F0` (`EPFImageControlPane`), `sub_495BF0` (`ImageButtonControlPane`, image id `14`), and `sub_498920` (`TextEditControlPane` with arguments `initialText,true,128,143,bounds,false,false,false,false,1.0,false`). In each asset branch, the first text loop consumes config byte offsets `0..36` and the second consumes `40..76`; `AddControl` after each construction therefore assigns the exact control-id order `2..11` then `12..21`.
- Final repair-pass `lookup_funcs(0x0053f2c0)` returned `sub_53F2C0`, size `0x541`; bounded decompile again showed two direct branches with immediate bounds/steps and no ref/load for a layout table or aggregate object.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0066decc-0x0066dee0` | UID00027W `OptionPaneLegacySizeWordTable_66DECC` | exact predecessor | true | UID0000M7 | `87/88` | verify-only, unchanged |
| `0x0066dee0-0x0066dee1` | UID0001OM `FriendNameListSyncEnabled` | one-byte external bool definition | true | UID0000PG | `86/90 -> 92/94` | implemented R1 at `92/94` |
| `0x0066dee1-0x0066dee4` | UID00027X `FriendNameOptionPalettePadding` | three-byte zero padding | false | none | `100/85` | verify-only, unchanged |
| `0x0066dee4-0x0066df00` | UID00027Y `OptionPaletteStaticResourceData` | next mixed static data | false | none | `88/93` | verify-only, unchanged |
| semantic global | UID0000PG `by-global/g_friendNameListSyncEnabled.md` | child container for sole `.cpp` definition; shared-header declaration documented separately | true | UID0000JN | `87/87 -> 92/94` | UID-preserving rename complete; container-only R2 implemented |
| `0x0053f2c0-0x0053f939` | UID0001DS `FriendListDialog` | constructor/destructor/handler/focus aggregate | true | UID00005J | `90/91 -> 92/93` | corrected R4 implemented |
| class | UID00005J `FriendListDialog` | complete no-field declaration | true | UID0000JN | `85/90 -> 90/93` | R3 implemented at position 10 |
| file | UID0000JN `FriendListDialog` | social source route | n/a | FILE | `86/88 -> 91/93` | source inventory/prose implemented |
| `0x00514380-0x005143ba` | UID0001AZ raw handler | no-entry duplicate covered by live case | true | UID0000L3 | `86/90` | verify-only, existing no-code formal |
| `0x00507c90-0x00508f60` | UID00037T dispatcher | live inline opcode `0x6a` owner | true | UID00007Q | `88/90` | verify-only, no false child split |
| `0x00574e50-0x0057536b` | UID0001HX sender helper | Socket member serializer | true | UID0000DD | `90/91` | verify-only formal; manual row stale |
| protocol item | UID0000UP `FriendNameListSyncOpcodes` | non-emitting routing contract | false | none | `86/89 -> 90/93` | prose/score/link update implemented |

No new by-memory child is required. The exact one-byte target already exists, and both instruction regions are inside existing live/raw pages.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00508aff` | data write from `sub_507C90` | live opcode `0x6a` sets target from packet byte nonzero test |
| `0x00508b14` | call to `sub_574E50` | live branch immediately syncs when true |
| `0x0051439c` | data write, no function owner | raw duplicate sets the same target |
| `0x005143ad` | raw call to `sub_574E50` | raw duplicate conditionally syncs |
| `0x0053f8dc` | data read from `sub_53F830` | FriendListDialog tests the target after writing/trimming 20 names |
| `0x0053f8ed` | call to `sub_574E50` | dialog member call on global Socket receiver |
| `0x0053f8f8` | call `sub_50ABA0` | unconditional `SaveUserSettings` after optional sync |
| `0x0053f8ff` | call `sub_49EB90` | close current dialog |
| `0x0053f90b` | call `sub_469180` | remove dialog from general-purpose panel |
| `0x00620f2c` | vtable data ref to `0x0053f830` | primary `+0x48` `OnControlCommand(int,int)` |
| `0x00620f3c` | vtable data ref to `0x0053f930` | primary `+0x58` `SetHoverControl(int)` |
| `0x0053e115` | constructor caller in `sub_53DDB0` | allocates 620 bytes then constructs FriendListDialog |
| `0x005a7112` | constructor caller in `sub_5A5BD0` | allocates 620 bytes then constructs FriendListDialog |
| `0x005bd151` | constructor caller in `sub_5BD000` | allocates 620 bytes then constructs FriendListDialog |

## Documentation Evidence And IDA Status

- Historical pre-callback state: UID0001OM and UID0000PG had correct behavior/name direction but blank formals and lower scores. Implemented state: both are `92/94`; R1 supplies one child-emitted definition, R2 supplies the semantic container, and the generated same-TU extern count is zero.
- Historical pre-callback state: UID0001DS contained useful complete behavior/ranges but stale control types, interleaved insertion, old virtual names, and free-style send. Implemented state: it is `92/93` with byte-exact R4, canonical controls, separate left-ten/right-ten loops, `ReadText`, current DialogPane APIs, exact virtuals, one Socket member call, and exact create/show/slide/save/close/remove forms.
- Historical pre-callback state: UID00005J was an `85/90` blank-formal class index. Implemented state: it is `90/93`, position `10`, with the complete no-field R3 declaration and exact allocation/vtable/access/compiler evidence.
- UID0000JN retains `NexusTK/social/` and is now `91/93` with complete source ordering, linkage, header separation, raw/live boundary, and compiler exclusions; no route change occurred.
- UID0001AZ remains `86/90` with the exact covered-by comment and no-route proof at report-level depth. Fresh MCP and final readback agree; no body or score change was made.
- UID0001HX retains complete formal Socket source at `90/91`. Its manual by-memory coverage row remains stale at `84%` and falsely says it is unassigned; the exact supervisor-owned replacement is supplied below without an ordinary-page change.
- Historical pre-callback state: UID0000UP accurately recorded the protocol at `86/89`. Implemented state: it is `90/93`, still NONE/FALSE/blank formal, with all listed evidence classes closed and no conceptual-item emission.
- Final repair-pass generated `FriendListDialog.cpp` command 15419 is explicitly the read-only pre-callback checkpoint. Its class/global/target markers and stale method/helper/control expressions are historical pre-callback facts, not a durable post-callback expectation; command 15379 and earlier command 15372 are historical same-semantics mutable-header epochs.
- Final repair-pass generated `MapPane.cpp` command 15419, SHA256 `AFC44E3B55EE64DFAB37DAA1F6E72A9D308BCBE7A4F7D51B924CC8B1C0DD03DC`, 148,064 bytes / 4,433 lines, retains UID0001AZ's covered-by comment once, contains no UID0001AZ Empty Emitter Marker, and contains no independent friend flag body. That is correct because the live opcode branch remains inline in the broader dispatcher source; command 15379 and command 15372 are historical.
- Final repair-pass tracker checkpoint is external command/header `000000015419`, refreshed `2026-07-20T16:00:18-04:00`, SHA256 `45FD1B3E9582E71DAA052A046E88AAD6ED51B92BDC19159B65E600A5F589E831`, 1,531,696 bytes / 6,206 lines; its sole UID0001OM row remains `86/90` at line 1570 before callback. Command 15401, commands 15376/15383/15388, and earlier header/hash/line positions are historical mutable-state epochs only.

## Ranked Ownership Analysis

### 1. FriendListDialog / `NexusTK/social/FriendListDialog.cpp`

- Evidence for: current semantic global owner; sole source UI reader; 20-slot friend config writes; exact optional sync; feature assets; existing source tree; complete sole-definition/container route; direct cross-TU use and separately required shared-header declaration.
- Evidence against: MapPane performs both server writes, so the flag is not dialog-private behavior.
- Decision: strongest definition owner. External linkage addresses the cross-TU writer without transferring ownership.

### 2. MapPane / `NexusTK/map/MapPane.cpp`

- Evidence for: live and raw opcode `0x6a` writers are MapPane-family code; live true path immediately sends.
- Evidence against: MapPane never provides the only source UI read or the 20-slot editor; Socket owns serialization; current file route already treats the flag as an external dependency.
- Decision: writer/consumer only. UID00037T/UID0001AZ and MapPane support are retained without transferring storage ownership.

### 3. Socket / network support

- Evidence for: helper `0x574e50` is a Socket member and queues outbound opcode `0x77`.
- Evidence against: Socket has no target write or read and does not own the 20 config-edit UI.
- Decision: serializer dependency only.

### 4. OptionPane/Palette or CashShopRequest

- Evidence for: Option/Palette data is physically adjacent; stale names associated the helper with inventory/cash-shop code.
- Evidence against: separate ranges/xrefs; no target ref from these families; complete friend-list packet/UI chain; no cash-shop opcode/resource/object in any route.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- No new source file was created; `NexusTK/social/FriendListDialog.cpp` remains the source route.
- Only the semantic by-global page path was renamed, preserving UID0000PG.
- The Socket helper remains in Socket source, and inline dispatcher logic remains in MapPane source.

## Source Placement

- Definition: `NexusTK/social/FriendListDialog.cpp`, emitted exactly once by storage UID0001OM through semantic child container UID0000PG and file UID0000JN.
- Declaration: consuming TUs require `extern bool g_friendNameListSyncEnabled;` in a shared declaration header. The exact original header filename is not recovered, so the declaration is documented as source-placement evidence and is not emitted into `FriendListDialog.cpp` by R2.
- Dialog declaration/body: UID00005J and UID0001DS are emitted in the same `.cpp`, ordered after the sole global definition. R2 contributes only `[[CHILDREN]]`, so generated source cannot contain a redundant same-TU `extern`.
- Writer: live `MapPane::HandlePacket` opcode `0x6a` logic remains in `NexusTK/map/MapPane.cpp`.
- Serializer: `Socket::BuildAndSendFriendNameListSync()` remains in the Socket source route.
- Rejected placements: cash-shop, inventory, OptionPane, Palette, file-local dialog anonymous namespace, duplicate MapPane definition, and a new friend-sync-only TU.
- Remaining uncertainty: exact original header placement and lexical spelling are unavailable; they do not block a coherent one-definition source model.

## Range / Split / Padding / Reclassification Analysis

| Range | Size | Current page | Disposition |
| --- | ---: | --- | --- |
| `0x0066decc-0x0066dee0` | `0x14` / 20 | UID00027W | predecessor table, unchanged |
| `0x0066dee0-0x0066dee1` | `0x1` / 1 | UID0001OM | exact bool definition, no split |
| `0x0066dee1-0x0066dee4` | `0x3` / 3 | UID00027X | successor-only alignment padding, unchanged |
| `0x0066dee4-0x0066df00` | `0x1c` / 28 | UID00027Y | next mixed static data, unchanged |

- `.data` begins at RVA `0x0026d000`, raw size `0x0d800`, virtual size `0x2fe24`; target RVA is `0x0026dee0`, raw offset `0x0026bae0`, so the initializer is file-backed rather than loader-zero-only.
- The one-byte target must not absorb the three successor zeros. No xref reaches those bytes, and the next referenced entity begins exactly at `0x0066dee4`.
- No child page, parent split, ignored-span insertion, range rename, or nesting change is needed.
- UID0001AZ is code, not padding, but is source-covered by the live dispatcher. Its following six `0xcc` bytes remain alignment before `sub_5143C0`.
- Relative nesting remains target `Nested:0`; predecessor/padding/successor levels remain unchanged.

## Negative Evidence Summary

- No function exists at target or raw duplicate start.
- No target ref uses a word/dword access; no neighbor byte participates in the flag.
- No ref exists to target successor padding.
- No raw duplicate caller, xref, absolute-address occurrence, RVA occurrence, function pointer, jump-table entry, relocation, or callback table entry exists.
- No second flag storage or runtime initializer exists in the checked image.
- No cash-shop request, inventory record, item dialog, payment opcode, or cash-shop resource is in the target call/data chain.
- No Socket method reads/writes the flag; helper ownership is not storage ownership.
- No OptionPane/Palette ref overlaps the target; adjacency is not ownership.
- No evidence supports a file-local definition because MapPane and FriendListDialog source routes both directly reference storage.
- No evidence supports a standalone function for the inline opcode case or raw duplicate.
- No evidence supports handwritten vtable/RTTI arrays, scalar-delete flags, EH/cookie code, raw addresses, or explicit vptr work in human C++.
- No code/data xref, constructor load, relocation, or named data item supports the rejected `FriendListLayout`, `kFriendListModernLayout`, or `kFriendListClassicLayout` objects; their prior report-draft use was source invention, not recovered storage.

## IDA Rename / Type / Comment Recommendations

- Source/documentation name: `g_friendNameListSyncEnabled`.
- Documentation path rename: validator-preserving UID0000PG rename from `by-global/byte_66DEE0.md` to `by-global/g_friendNameListSyncEnabled.md`.
- Source type: `bool`; exact definition initializer: `true`; linkage: external.
- Historical aliases to retain only in prose/search history: `byte_66DEE0`, `g_isCashShopEnabled`, cash-shop/inventory helper aliases.
- Callback command 15432 updated every ordinary path link listed under Recommended Support Doc Changes; final search found zero stale old-path links. Manual coverage score/description replacements remain supplied separately as supervisor-owned state.
- No IDA database rename/type/comment mutation is requested or permitted by this assignment. The recommendation is for project documentation/source reconstruction only.

## First-Draft C++ Recommendation

Eligible: yes. Exact storage, linkage, initializer, class declaration, virtual contracts, and source route are resolved. The following are the only destination C++ blocks.

### R1 - UID0001OM exact storage definition

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool g_friendNameListSyncEnabled = true;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R2 - UID0000PG semantic global child container

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R3 - UID00005J complete FriendListDialog declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FriendListDialog : public DialogPane
{
public:
    FriendListDialog();
    virtual ~FriendListDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

protected:
    virtual void SetHoverControl(int controlId);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R4 - UID0001DS complete corrected FriendListDialog source

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FriendListDialog::FriendListDialog()
    : DialogPane(L"Friend List", 11, true)
{
    RectBounds bounds;
    RectBounds dialogBounds;
    int row;
    int y;
    int slot;
    int left;
    int top;

    if (g_useEpfAssets) {
        InitRectBounds(&bounds, 0, 0, 332, 399);
        AddControl(new EPFImageControlPane(
            L"FRIEND.EPF", 0, 1, &bounds, L"FRIEND.PAL"));

        InitRectBounds(&bounds, 138, 363, 201, 387);
        AddControl(new ImageButtonControlPane(14, &bounds));

        for (row = 0; row < 10; ++row) {
            y = 60 + row * 29;
            InitRectBounds(&bounds, 49, y, 133, y + 12);
            AddControl(new TextEditControlPane(
                g_pConfig->m_friendNames[row].c_str(),
                true, 128, 143, &bounds,
                false, false, false, false, 1.0f, false));
        }

        for (row = 0; row < 10; ++row) {
            slot = 10 + row;
            y = 60 + row * 29;
            InitRectBounds(&bounds, 199, y, 283, y + 12);
            AddControl(new TextEditControlPane(
                g_pConfig->m_friendNames[slot].c_str(),
                true, 128, 143, &bounds,
                false, false, false, false, 1.0f, false));
        }

        SetHoverControl(2);
        SetFocusedControl(1);
        SetPendingControl(1);
        SetBackgroundResource(L"FRIEND.EPF", 0);

        left = (g_screenWidth - 332) / 2;
        top = (g_screenHeight - 399) / 2;
        InitRectBounds(&dialogBounds, left, top, left + 332, top + 399);
    } else {
        InitRectBounds(&bounds, 0, 0, 407, 391);
        AddControl(new EPFImageControlPane(
            L"FRIEND.EPD", 0, 1, &bounds, L"NPAL8.PAL"));

        InitRectBounds(&bounds, 168, 341, 240, 357);
        AddControl(new ImageButtonControlPane(14, &bounds));

        for (row = 0; row < 10; ++row) {
            y = 94 + row * 21;
            InitRectBounds(&bounds, 104, y, 182, y + 12);
            AddControl(new TextEditControlPane(
                g_pConfig->m_friendNames[row].c_str(),
                true, 128, 143, &bounds,
                false, false, false, false, 1.0f, false));
        }

        for (row = 0; row < 10; ++row) {
            slot = 10 + row;
            y = 94 + row * 21;
            InitRectBounds(&bounds, 246, y, 324, y + 12);
            AddControl(new TextEditControlPane(
                g_pConfig->m_friendNames[slot].c_str(),
                true, 128, 143, &bounds,
                false, false, false, false, 1.0f, false));
        }

        SetHoverControl(2);
        SetFocusedControl(1);
        SetPendingControl(1);
        SetBackgroundResource(L"FRIEND.EPD", 0);

        InitRectBounds(&dialogBounds, 130, 10, 537, 401);
    }

    OnCreate(&dialogBounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}

FriendListDialog::~FriendListDialog()
{
}

void FriendListDialog::OnControlCommand(int controlIndex, int notifyCode)
{
    enum {
        kFriendNameSlotCount = 20,
        kFriendNameFirstControlId = 2,
        kFriendNameTextCapacity = 64
    };
    int slot;

    if (controlIndex != 1) {
        return;
    }

    wchar_t text[kFriendNameTextCapacity];

    for (slot = 0; slot < kFriendNameSlotCount; ++slot) {
        TextEditControlPane *edit =
            GetChild<TextEditControlPane>(kFriendNameFirstControlId + slot);
        WideString &friendName = g_pConfig->m_friendNames[slot];

        edit->ReadText(text, kFriendNameTextCapacity);
        friendName.Assign(text);
        friendName.TrimLeft(L" \t\n\r");
        friendName.TrimRight(L" \t\n\r");
    }

    if (g_friendNameListSyncEnabled) {
        g_packetSender->BuildAndSendFriendNameListSync();
    }

    SaveUserSettings();
    CloseDialog();
    g_pGeneralPurposePanel->RemoveDialog(this);
}

void FriendListDialog::SetHoverControl(int controlId)
{
    DialogPane::SetHoverControl(controlId);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R1 is the sole emitted `.cpp` definition and preserves the exact initialized byte without raw-address syntax. R2 is only the semantic child insertion point; the required cross-TU `extern` is a separately documented shared-header declaration and is deliberately absent from the generated `.cpp`. R3 naturally produces the three derived vtables from a human class declaration while adding no storage. R4 is C++03-era source that follows the two observed immediate modern/classic branches directly, uses canonical control types/signatures and stack-local `RectBounds`, preserves the exact left-ten/right-ten insertion sequence, `WideString::c_str()`, and `TextEditControlPane::ReadText`, and introduces no unsupported `FriendListLayout` storage. No C++11 construct, compiler wrapper, vptr store, RTTI object, adjustor thunk, cookie/EH code, raw duplicate, or handwritten table is emitted.

## Final Recommendation

- C01-C20 are incorporated at report-level detail with twenty terminal ledger states and twenty claim-specific implementation-proof rows.
- UID0001OM retained its exact range and hierarchy and now carries R1 at `92/94`.
- UID0000PG was renamed through the documented validator-aware UID-preserving workflow to `by-global/g_friendNameListSyncEnabled.md`; it now carries container-only R2, position 0, and `92/94`. The shared-header `extern` remains documentation evidence and is absent from same-TU emitted text.
- UID00005J now carries R3 at position 10 and `90/93`; the class closes before `[[CHILDREN]]` and contains no fields.
- UID0001DS now carries exact C++03 R4 at `92/93`; its direct modern/classic branches retain left slots `0..9` before right slots `10..19`, creating handler control ids `2..21`. Generated readback contains zero `FriendListLayout`, layout-instance, `constexpr`, or other rejected post-era forms.
- UID0000JN is `91/93` with complete file inventory/source ordering and retained compiler exclusions.
- UID0000UP is `90/93` and remains non-reconstructable/no-owner/non-emitting.
- Rename-managed links and bounded current prose were updated without changing unrelated support scores, routes, or formals.
- UID0001AZ, UID00037T, UID0001HX, Socket, MapPane class/file, predecessor/padding/successor, and compiler destructor/thunk pages were otherwise left unchanged.
- No new page, split, merge, owner transfer, raw-helper promotion, IDA mutation, or third-party import was performed or remains part of the implemented disposition.

## Recommended Target Doc Changes

Callback status: all accepted target changes below are implemented and validator-read back; wording remains as the durable destination specification.

- Path: `by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md`.
- Metadata: exact `92/94`; owner/emitter UID0000PG; reconstructable true; blank optional position; `Nested:0`; exact range unchanged.
- Formal: R1 exactly.
- Item Summary: `Source-ready one-byte external bool definition initialized true; exactly two MapPane-family writes and one FriendListDialog read gate immediate and save-time opcode 0x77 friend-name-list synchronization, with separate successor padding and no competing storage or initializer.`
- Incorporate exact PE/raw identity, byte/hash, three xrefs, packet/UI/helper call flow, external linkage, name/type/source-placement reasoning, boundary/padding facts, raw duplicate relationship, rejected alternatives, generated expectations, score rationale, and historical aliases at report-level depth.
- Implemented: historicalized the pre-callback `bool or equivalent`, possible runtime-initializer, and unresolved-linkage wording as prior cautious state rather than current uncertainty.

## Recommended Support Doc Changes

Callback status: all accepted support changes below are implemented. Imperative wording inside the recorded validator sequence preserves the accepted procedural contract as completed history and does not describe pending work.

### UID0000PG semantic global

- Validator-preserving rename:
  - from `by-global/byte_66DEE0.md`
  - to `by-global/g_friendNameListSyncEnabled.md`
- Historical pre-callback path state: old path SHA256 `D5ADA03B224493852968ACEA7B61B21ADEBB3F7F9491564F44DE582C0C00B6E0`, 6,838 bytes / 71 lines; new path absent.
- Implemented path state: the old path is absent; current `by-global/g_friendNameListSyncEnabled.md` SHA256 is `3D13221DDCB9A66C8BA4C250B692106B42CB19A44BEF98EA2B4A15EF336ECD3A`. Normal validator command 15432 preserved UID0000PG, updated the mapping, and propagated the registered reference union.
- Exact callback sequence completed under the validator-managed rename contract; the steps below record that accepted completed procedure:
  1. Re-read the current lease ledger; only when the old page is free and the edit is ready, acquire one short B003 lease for `by-global/byte_66DEE0.md` and reread/rebase the complete page.
  2. Rename that one page to `by-global/g_friendNameListSyncEnabled.md` while preserving UID0000PG and its full no-loss content; the old mapped path must cease to exist, and no duplicate/copy may remain.
  3. Run the default scoped validator on the new path, not `--uid-only`: `python .\tools\validator.py --mode file --file by-global/g_friendNameListSyncEnabled.md --apply --queue-timeout 240`. The validator, not B003, updates the UID-to-path mapping and propagates registered references through its normal `[references]` handling.
  4. Read back the validator result, mapping-visible current path, and every propagated ordinary reference. Release the rename-page lease immediately after that scoped validation; never retain it while editing support pages.
  5. Reread the full listed ordinary-link union. For any old-path link not validator-propagated, acquire one short lease for only that page, rebase all concurrent content, replace only the stale path while preserving UID0000PG and every unrelated fact, scoped-validate that page, and immediately release before the next page.
  6. After all link pages are current, run the separately authorized waited `by-file/FriendListDialog.md` validation and verify the sole-definition/container/generated assertions. Never hand-edit `tools/validator.ini`, `[files]`, `[references]`, queue/lock state, generated files, or coverage.
- Preserve UID0000PG and owner/emitter UID0000JN; true; set position `0`; install container-only R2; set `92/94`.
- Incorporate sole-definition/linkage, exact child definition, separately documented shared-header declaration requirement, PE initializer, xrefs, packet/UI behavior, source owner, aliases/rejections, and score rationale.

### UID00005J class

- Path: `by-class/FriendListDialog.md`.
- Set `90/93`, preserve owner/emitter UID0000JN and true; set position `10`; install R3.
- Add exact `0x26c` no-added-field layout proof, primary/secondary/tertiary vtable addresses, `+0x48/+0x58` method contracts, public/protected access, compiler destructor exclusions, and class-before-children generated requirement.

### UID0001DS aggregate

- Path: `by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md`.
- Set `92/93`, preserve owner/emitter UID00005J, true, blank position, `Nested:0`, exact ranges/padding and all destructor support.
- Replace formal with R4 exactly. Preserve both observed branch layouts as direct C++03 control flow, canonical EPF image/image-button/text-edit types and argument order, immediate bounds/resources, left-ten/right-ten insertion and config/control identity, `ReadText`, trim behavior, optional-sync then unconditional-save/close/remove order, callers, boundaries, historical corrections, and rejected compiler code. Record that no binary storage/xref supports `FriendListLayout` or namespace-scope modern/classic layout instances, so those report-draft objects and all `constexpr` syntax are rejected rather than emitted.

### UID0000JN file

- Path: `by-file/FriendListDialog.md`.
- Set `91/93`, preserve `NexusTK/social/` and FILE owner.
- Add complete sole-global-definition/container/class/method source ordering, separate shared-header declaration requirement, exact cross-TU linkage, current method names, Socket boundary, raw/live distinction, compiler exclusions, generated assertions, and historicalized stale aliases.

### UID0000UP protocol item

- Path: `by-item/FriendNameListSyncOpcodes.md`.
- Set `90/93`; preserve NONE/FALSE/blank emitter/position/formal.
- Update renamed global link and add exact cursor/start/return semantics, target initializer/storage, UI ordering, Socket member call, raw no-entry relation, and rejected owner routes.

### Rename-managed ordinary links, no score/formal/route changes

The UID0000PG validator-aware rename updated the old link in these ordinary pages while preserving every unrelated fact. The hashes below are historical pre-callback evidence checkpoints; current post-callback hashes are recorded in Changed Files:

| Path | Evidence-checkpoint SHA256 |
| --- | --- |
| `by-meta/client_network.md` | `F62529DD75958911E26C28231F39F5D93D63BD6B7FCFD2429EE96119BB504B44` |
| `by-meta/client_opcodes.md` | `3A058C7D1F7C7C3A81DDB835EC0F8C0DC352D61996A4A93F5E66B9C91D619DCF` |
| `by-type/by-enum/MapServerPacketOpcode.md` | `C77CC92D330AD41F66DB5F32384155549D7EE099E9E064331AB106EDD234A4B4` |
| `by-item/FriendNameListSyncOpcodes.md` | `E626E87520A60872FAAE199542CACD66928411592C0449F4714517685ADF0B78` |
| `by-file/CashShopRequest.md` | `9DF8FD3E7B5A4BF1AF468D52E0856FE4514528AB6DE35659B8A1A12B05857A8F` |
| `by-file/FriendListDialog.md` | `7FAEBD00F96BC7CEF591A0B83D206F1DE0F752F7BE04D45AD58415624E2BC234` |
| `by-file/MapPane.md` | `3F579A40A8B267383593A172E0329100C6D0151122D66455B72E1895A1BBC634` |
| `by-class/CashShopRequest.md` | `0AD3B7F90249EA16F49C0564CBB626EDCB95419BFA26CFF586A9324D0C0AD4DC` |
| `by-class/FriendListDialog.md` | `3846E513F8A73B9B3B563BF72722184D32A1091A85671CCD21B8B3F606A40E3C` |
| `by-class/MapPane.md` | `FC683223A88EA34314384188896C6E9E149469C43079BEBC4B426CAA3497F22E` |
| `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` | `A103ED27C172AF4703B83CCE61B89601FC6ECA527B7AF839EDD70B6383F59068` |
| `by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md` | `126D2C38F93E2276D592CAA984FDC5A463374093E0734322D7094202E8EF3319` |
| `by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md` | `99DDC2546F386DC703D0795E3B72A2E99D93F351875A5CEF5423B70C4996F1EC` |
| `by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md` | `FC349922132648D327E0489B508B674028990C6F3F9B9AC521AD32B1E88A66B1` |
| `by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md` | `A3A07B7E67F10A92E89C204D5E8124EAC48654415CAECE01C983E99016B1F72F` |

Coverage links were changed only as validator command 15432 reference-propagation side effects; B003 did not manually edit coverage. Their stale scores/descriptions remain supervisor-owned, and exact replacement text appears below.

### Verify-only support

- UID0001AZ raw page remains `86/90` with its exact existing covered-by formal and no-entry proof.
- UID00037T dispatcher remains `88/90`; its inline case is not split into false standalone source.
- UID0001HX helper remains `90/91`, Socket-owned, exact formal unchanged.
- MapPane UID00007Q/UID0000L3 remain current `93/94` and `92/92`; only rename-managed links change.
- UID00027W/UID00027X/UID00027Y boundaries and metadata remain unchanged.
- UID00038A scalar wrapper and adjustor/vtable/compiler support remain no-code/verify-only.
- Control/API dependencies remain unchanged: `by-class/DialogPane.md` SHA256 `7101A93A4EF53CFA1F11529AEF111AA94B13EBC76222ADE546D7B59D6D521DBE`; `by-class/TextEditControlPane.md` `D925F7CEF9B14810A68929EB4D230BD665767E1798FCF3482A6B56008B55FA4F`; constructor page UID0004K1 `F4F0FB8D0AF5740C095049D27CC518CF20A1C2C82F26C8406C2A4F4B10A09C52`; `by-class/EPFImageControlPane.md` `430C9AFEC07F3565442FB77C9A8A7B5A318F1C73B52D0FB94E41DA03679D2B13`; constructor page UID0004JN `AA27C06DD7119A1CFFB4B84E1B601AFDF106ABD79A54E891D63DF4E4BB516B62`; and `by-class/ImageButtonControlPane.md` `52D347F2A9DFE73775A1CDBF8551A7AE6D2A396CB01B1A1FA44D6BCD000ED01E`.
- Global dependencies remain unchanged: `by-global/g_useEpfAssets.md` SHA256 `63105269A3F90B2E11AAD2B457D4A35DA4EC8FEAEBC4B8A3E86120882DA21E10` and `by-global/MainUiLayerSlots.md` `456FBAC29345E49637A144B2552FE63C083F9F2AE250090C59780DDF30A3E42C` support the source-facing asset-mode and overlay-layer expressions in R4.

## Score And Metadata Recommendation

| Destination | Pre-callback | Implemented | Metadata disposition | Reason |
| --- | --- | --- | --- | --- |
| UID0001OM target | `86/90` | `92/94` | same owner/emitter UID0000PG, true, blank position, Nested0 | exact storage/type/init/refs/route/formal closed |
| UID0000PG global | `87/87` | `92/94` | validator-managed UID-preserving rename; owner/emitter UID0000JN; true; position0; container-only R2 | exact semantic identity, child-emitted sole definition, separately documented shared-header declaration, and no same-TU redundancy |
| UID00005J class | `85/90` | `90/93` | owner/emitter UID0000JN; true; position10 | exact no-field layout, virtuals/access, complete declaration |
| UID0001DS aggregate | `90/91` | `92/93` | owner/emitter UID00005J; true; blank position/Nested0 | exact canonical control types/signatures, direct C++03 modern/classic branches, two-loop config/control identity, no unsupported layout objects, and preserved complete behavior |
| UID0000JN file | `86/88` | `91/93` | FILE owner and `NexusTK/social/` unchanged | complete sole-definition/container/class/body inventory, separate-header requirement, owner/linkage/compiler boundary |
| UID0000UP item | `86/89` | `90/93` | NONE/FALSE/blank formal unchanged | exact paired packet/UI/raw/global/helper route and negative ownership closure |

Score-improvement attempt and remaining caps:

- Type blocker removed through exact one-byte accesses and MSVC bool representation.
- Initializer blocker removed through file-backed `01` plus no initializer route.
- Linkage blocker removed through separate accepted source TUs and no accessor: one child-emitted `.cpp` definition plus one separately documented shared-header declaration, with no redundant same-TU `extern`.
- Name blocker converted to best descriptive project spelling plus UID-preserving semantic path rename.
- Owner/source placement blocker removed through complete reader/writer/helper separation.
- C++ blocker removed with R1-R4 and exact ordering: R4 is valid C++03-era source, mirrors the duplicated immediate branch flow, and contains no unsupported layout aggregate/table or post-era syntax.
- Class marker blocker removed with exact size/vtable/method declaration evidence.
- Raw-helper liveness was exhaustively checked. Its unchanged score is a bounded no-improvement result: exact role/source coverage is proved, but zero entry/caller/pointer evidence prevents stronger liveness confidence and forbids a standalone body.
- Confidence remains below 95 only because exact original symbol/header spellings are not PDB-proven. Canonical control constructors, argument order, control insertion order, and read API are now resolved; the remaining cap is lexical, not a behavior, route, or code-entry blocker.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution | Score/C++ impact |
| --- | --- | --- | --- |
| bool or byte? | all direct accesses, initial byte, neighbors | bool | closed; R1/R2 safe |
| true initializer or runtime set? | PE raw mapping, xrefs, initializer absence | explicit true | closed |
| external or static? | accepted source TUs, direct refs, no accessor | external: one UID0001OM `.cpp` definition; shared-header `extern` documented separately and not emitted by R2 | closed without same-TU redundancy |
| exact owner? | all readers/writers/helper, source tree, docs | FriendListDialog file | closed |
| source name? | all semantics and rejected aliases | descriptive `g_friendNameListSyncEnabled` | closed for first draft; lexical confidence cap only |
| raw duplicate live? | function/xref/pointer/address searches | no entry route; covered by live case | no standalone code |
| target split/padding? | bytes and neighbor xrefs/pages | exact one byte plus separate 3-byte pad | closed |
| handler source method? | vtable offsets and base contract | `OnControlCommand` | closed |
| focus helper source method? | tail jump, vtable offset, base contract | `SetHoverControl` | closed |
| helper free or member? | ECX receiver, Socket declaration/body | Socket member call | closed |
| derived fields? | all three 620-byte allocations, DialogPane 0x26c | none | complete class safe |
| source file? | accepted tree, feature behavior, owner graph | `NexusTK/social/FriendListDialog.cpp` | closed |
| one layout object/table or direct branches? | fresh constructor decompile, direct immediates/literals, refs list, no storage/xref/load for proposed objects | direct modern/classic C++03 branches; no `FriendListLayout` or layout instances | closed; unsupported aggregate objects removed from R4 |
| C++ source era? | project baseline and accepted constructor semantics | C++03-compatible declarations, loops, literals, `NULL`, no `constexpr`/`auto`/`nullptr`/initializer lists | closed |

No in-scope question remains at a future-investigation-only state. Exact original lexical spelling is unavailable but does not prevent the strongest project-consistent source form.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B003 reread every applicable manual row after ordinary validation. The following external snapshots are the callback evidence epoch; later lifecycle/coverage state remains supervisor-owned:

| Manual file | SHA256 | Bytes / lines | Relevant current rows |
| --- | --- | ---: | --- |
| `by-memory/-coverage-report.md` | `3A973DF5CDA032AA04EB3A1B3C18F207A5A475CA9E0A92A2575E5F1070A0F65E` | 1,864,341 / 4,415 | UID0001DS line 2668; UID0001HX line 3125; UID0001OM line 4161 |
| `by-global/-coverage-report.md` | `F5DB17EA8D145825B0B64FDB550180EB2150C14410AADF8D26D338C22BF80EAF` | 90,666 / 213 | UID0000PG line 19; semantic path propagated, stale `87%` score remains |
| `by-class/-coverage-report.md` | `7300D965E1A9E2DECDAB0515784DAEF79E970E3360EB3793DC9DD34BF24BEEFC` | 241,643 / 623 | UID00005J line 224 |
| `by-file/-coverage-report.md` | `4AA835711FC1DBC8FEE994DB2E7C62293A5779588B49BDAE898C480B0FD6B651` | 138,772 / 316 | UID0000JN line 104 |
| `by-item/-coverage-report.md` | `32DB12AC3A1EE6258AF623D495B82D712B3817E94EB690FC36F332CBF4CC5818` | 28,995 / 87 | UID0000UP line 48; semantic path propagated, stale `86%` score remains |

Concurrent external coverage activity advanced the historical report-only hashes and moved the by-memory anchors to lines 2668/3125/4161. Validator command 15432 also propagated the UID0000PG path through registered references, including coverage links, without a manual B003 coverage edit. Relevant score/description rows remain stale and every exact replacement below remains a no-loss overlay on this callback evidence union.

Exact replacement rows after ordinary callback implementation:

`by-memory/-coverage-report.md`, replace UID0001DS in place:

    - [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md) 0x0053f2c0-0x0053f939 | class-method cluster | FriendListDialog : reconstructable : 92% : very strong : Complete C++03-era source-ready 20-slot friend editor with direct observed EPF/EPD branches and immediate bounds/resources rather than unsupported layout objects, canonical EPFImageControlPane/ImageButtonControlPane/TextEditControlPane construction, left-ten then right-ten insertion matching control ids 2..21 to config slots 0..19, ReadText capacity 64, boundaries, 620-byte DialogPane-sized no-field class relation, OnControlCommand and SetHoverControl virtual contracts, config trim/store behavior, optional opcode 0x77 Socket member sync, unconditional SaveUserSettings, close/remove ordering, and compiler destructor support kept out of human source.

`by-memory/-coverage-report.md`, replace stale UID0001HX in place without changing its ordinary page:

    - [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md) 0x00574e50-0x0057536b | request-sender helper | BuildAndSendFriendNameListSync : reconstructable : 90% : very strong : Socket-owned outbound opcode 0x77 friend-name-list member helper over 20 config slots with unique-name deduplication, count byte, fixed 13-byte records, request-code 8 queueing, defined callers at 0x00508b14 and 0x0053f8ed, raw code ref 0x005143ad, paired [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) raw write at 0x0051439c, exact formal C++, and 0x0057536b-0x00575370 padding.

`by-memory/-coverage-report.md`, replace UID0001OM in place between unchanged UID00027W and UID00027X rows:

    - [UID:0001OM][0x0066dee0-0x0066dee1.FriendNameListSyncEnabled](by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md) 0x0066dee0-0x0066dee1 | friend-name sync flag | FriendNameListSyncEnabled : reconstructable : 92% : very strong : Source-ready one-byte external bool definition initialized true; exactly two MapPane-family writes and one FriendListDialog read gate immediate and save-time opcode 0x77 friend-name-list synchronization, with separate successor padding and no competing storage or initializer.

`by-global/-coverage-report.md`, replace UID0000PG in place:

- [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) : reconstructable : 92% : very strong : Source-ready semantic child container whose exact UID0001OM child emits the sole external-linkage friend-name-list synchronization bool definition initialized true; cross-TU extern declaration is documented for a shared header and is not redundantly emitted in FriendListDialog.cpp; exactly two MapPane-family writes, one FriendListDialog read, Socket opcode 0x77 linkage, UID0000JN social source ownership, raw/cash-shop alias history, and one-definition handling.

`by-class/-coverage-report.md`, replace UID00005J in place:

- [UID:00005J][FriendListDialog](by-class/FriendListDialog.md) : reconstructable : 90% : very strong : Complete DialogPane-derived friend-list dialog declaration with exact 0x26c no-added-field layout, primary OnControlCommand and protected SetHoverControl overrides, class closure before children, 20 config-backed rows, dual assets, optional friend sync, unconditional SaveUserSettings, close/remove ordering, and compiler destructor/vtable support excluded from human source.

`by-file/-coverage-report.md`, replace UID0000JN in place:

- [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md) : reconstructable : 91% : very strong : Complete NexusTK/social/FriendListDialog.cpp route with one child-emitted external g_friendNameListSyncEnabled definition and zero redundant same-TU extern declaration, separately documented shared-header declaration requirement, DialogPane-sized no-field class declaration, direct C++03 EPF/EPD constructor branches without unsupported layout objects, canonical control constructors, left-ten/right-ten editor insertion matching ids 2..21 to config slots 0..19, destructor/OnControlCommand/SetHoverControl bodies, exact optional Socket sync then unconditional save/close/remove ordering, and compiler wrappers/thunks/vtables kept non-handwritten.

`by-item/-coverage-report.md`, replace UID0000UP in place:

- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md) : routing : 90% : very strong : Exact non-emitting protocol contract for inbound MapPane opcode 0x6a / 106, external bool [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md), outbound Socket opcode 0x77 / 119, one-byte cursor/read/return behavior, no-entry raw duplicate, FriendListDialog 20-slot save-path sender, unique 13-byte records, and rejected cash-shop/OptionPane ownership.

These files are manual supervisor-owned state. B003 did not apply the rows. `auto-generated/-ag-research-tracker.md` is validator-owned; no manual tracker text is supplied.

## Follow-Up Actions

- Implementation and scoped/waited validator work are complete; no B003 callback item remains.
- B003 generated command 15447 and current external command 15456 readbacks prove the sole UID0001OM definition, zero same-TU extern, child-before-class-before-method ordering, one constructor/destructor/OnControlCommand/SetHoverControl each, canonical direct branches and controls, one Socket member call, zero rejected forms/target markers, and the retained compiler-only UID00038A marker.
- Exact report validation, manual coverage application, current path/count/status, report execution, move, and archive state are external supervisor/validator-owned and are neither asserted nor directed by this artifact. B003 itself ran no report lifecycle command.

## Confidence

- Recommendation confidence: `94/100` for target storage/type/init/range/xrefs/behavior/route and one-definition model.
- Score confidence: strong for all implemented changes. Target/global are `92/94`; support scores reflect exact class/source/protocol closure while retaining lexical caps.
- Remaining uncertainty: exact original symbol/header spelling is unavailable without source/PDB. Canonical control APIs and constructor arguments are resolved and do not remain blockers; the lexical cap does not alter binary behavior, object layout, owner/emitter, source placement, or formal completeness.

## Validator Results

- This narrow post-callback Gate 1 report repair ran no validator; the implementation validator results below remain the exact callback proof.
- UID0000PG rename/new path: command `000000015432`, timestamp `2026-07-20T16:32:20-04:00`, exit `0`, `ok:1`; path update 1, completion update 1, confidence update 1, UID link updates 39, reference-source-path updates 7, generated deferred. Broad `missing_ref_uid` warnings were 124 unrelated existing project references; no target failure. The old leased path was released immediately after validation.
- UID0001OM target: command `000000015436`, timestamp `2026-07-20T16:35:36-04:00`, exit `0`, `ok:1`; completion/confidence updates and blank-to-block autogen registration succeeded; generated deferred; lease released immediately.
- UID00005J class: command `000000015437`, timestamp `2026-07-20T16:36:50-04:00`, exit `0`, `ok:1`; position, score, and blank-to-block registration updates succeeded; generated deferred; lease released immediately.
- UID0001DS aggregate: command `000000015440`, timestamp `2026-07-20T16:39:26-04:00`, exit `0`, `ok:1`; score/formal registry updates succeeded; generated deferred; lease released immediately.
- UID0000JN file: command `000000015442`, timestamp `2026-07-20T16:40:58-04:00`, exit `0`, `ok:1`; score updates, two canonical link-label updates, and one reference-index addition succeeded; generated deferred; lease released immediately.
- UID0000UP item: command `000000015445`, timestamp `2026-07-20T16:42:15-04:00`, exit `0`, `ok:1`; score updates succeeded, and validator-owned projected stats removed its now-90% non-reconstructable row/recommended later rescore; generated deferred; lease released immediately.
- Final waited file refresh: command `000000015447`, timestamp `2026-07-20T16:42:32-04:00`, exit `0`, `ok:1`, `generated_refresh:completed`. It rebuilt registry metadata and refreshed generated outputs; broad marker/fallback/emitter warnings are unrelated existing project debt. Its one `autogen_cpp_update` for `ItemObjImageLib.cpp` reflects concurrent B002 work, not B003 scope.
- B003 waited FriendListDialog checkpoint: command/header 15447, SHA256 `653C058AB8DADB9388C787EAB57A963F6C525FD860B7B77F122183739E385B29`. Current stable read-only external checkpoint: command/header 15456, SHA256 `12250035A816A2E6B8FD6210D6539E4A81D687616AA1CE3AD95AF357C62D4FF5`, 5,047 bytes / 155 lines, with the same source payload. Semantic counts: R1 definition 1; same-TU extern 0; class 1; constructor/destructor/OnControlCommand/SetHoverControl 1 each; Socket member call 1; UID0000PG/UID0001OM/UID00005J markers 0; accepted compiler-only UID00038A marker 1; rejected layout/post-era/old-name/free-style/vtable/RTTI forms 0.
- R1/R2/R3/R4 destination parity is exact. Normalized body hashes are respectively `131E50D38437393FAD3E63EF00155CAB9BEB68D08F7275E7475F52A6D262D57E`, `19FEC47C0DE54A582B7297C6EF81D03DF3219387E6591E86B64D9C0CFD2C81DD`, `45C78DB198BBE6CEF44A890665992395EF37A80E5F2A14CF3947A78C8806188F`, and `F446469FB3C81B493B0709A562C98175F9E0F0156B96524C854F388EA9125B2E`.
- Current external validator-owned tracker command/header 15456 at `2026-07-20T16:49:16-04:00` has SHA256 `19625F36DED092FF386B2DE22B37A2BB6F811080B17BDAD2CF789834BBB6E19E`, 1,532,009 bytes / 6,206 lines. Intermediate command 15448 and current 15456 are not B003-issued lifecycle actions and do not change FriendListDialog command-15447 semantics.
- MCP evidence remained the captured healthy evidence-time session `9b0396a3`; callback mutated no IDA state. All B003 leases were released immediately, current ledger shows zero B003 leases, and no unresolved callback validator error remains.

## Changed Files

- B003 content destinations, current hashes: renamed `by-global/g_friendNameListSyncEnabled.md` `3D13221DDCB9A66C8BA4C250B692106B42CB19A44BEF98EA2B4A15EF336ECD3A`; UID0001OM `A575C474FE585FF07A69C0A06AC95AFE75E8935D37B1CC9606088698A620D045`; UID00005J `8CF62C1363A72DC37E1302047AB032D0219B085F2D177A025F9B2647122CCF44`; UID0001DS `4C2468D52C5DCB394E1A18B4C4EB91F639E9261FD3F594E6DFF789E065E29C77`; UID0000JN `25AD47135DE7AD65EC5EC478B9CDE3DCB0C2566B7DE215D967ED057EBD171498`; UID0000UP `43F2180863C49E40DFD06D3E20EAB91348DE14958E8756A1B2CB28852E657AC4`.
- Validator-propagated ordinary link-union current hashes: `by-meta/client_network.md` `8F25B06BBFF942C060828BB1920F01B5BD8E1993BA271392614AAC10EDF631C7`; `by-meta/client_opcodes.md` `00FAD69CE05E3BCD43B2618C4E33B2E13E4555D0A879376B2B5F8A61CC0E5000`; `by-type/by-enum/MapServerPacketOpcode.md` `EFC3B0A6E78C9DD0A9856F8D0FFB8864FE2C6623F2F3059E5636D009F8F19060`; `by-file/CashShopRequest.md` `C7CE3575B71B84303E3210E81DE5F6A84A328B1A13EA56D9006C4EE4FA2A0C56`; `by-file/MapPane.md` `DA14D6EF77DF7BE4D43952E0742B1D86536870943B2BB6FAB4903D54E9DF8C47`; `by-class/CashShopRequest.md` `E3B7ACE071474756FE766E5C008B32165D0DF80DCEF3397F9965434849F3E91F`; `by-class/MapPane.md` `566646D99BAA12E7F201E68BF4754B9FA288A176ADDE548481296E3BC7D216C3`; packet aggregate `671BAB7673718C42497E9AB397047E4CD540B520F9BFC414C7794F7FA5C36C35`; raw handler `6AD59B38B5228C379C2E8107B710200D235F8E9AF50ABE1967B5296C9B7372FB`; Socket helper `819572B11E3FEF40ED693813D4B9AD95EDEF53120405BF33E56CFBBE2E36F8BB`. Overlapping target/class/aggregate/file/item hashes are listed above. Zero ordinary stale old-path links remain.
- Removed path: `by-global/byte_66DEE0.md`; validator-aware move preserved UID0000PG and no duplicate remains.
- Validator-owned side effects, not manual B003 edits: generated/tracker refreshes, registry/reference/stat metadata, and registered path propagation into manual coverage links. B003 manually edited no `-coverage-report.md`, generated, tracker, audit, supervisor, validator-state, IDA, or legacy-tree file.
- Modified in place for reconciliation: `tools/leaser/Agents/Agent-B003/research/0001OM-FriendNameListSyncEnabled-source-quality.md`.
- Post-callback Gate 1 report-only repair: corrected the current UID0000PG inventory path, converted Final Recommendation and equivalent current recommendation wording to durable implemented truth, and made no ordinary, validator, coverage, generated, tracker, IDA, or lifecycle change.
- Lease history: one ordinary destination at a time; each released immediately after its validator. Current B003 lease count is zero.
- B003 ran no report execution/probe/count/move/archive/lifecycle command. Exact report lifecycle state remains external.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation.
- [x] Reread target UID0001OM under a short lease and preserve concurrent content before editing.
- [x] Apply C01-C13 to UID0001OM at report-level detail.
- [x] Set UID0001OM metadata exactly to `92/94`, UID0000PG owner/emitter, true, blank position, Nested0.
- [x] Install R1 exactly and update the exact target Item Summary.
- [x] Preserve exact range, byte/hash, PE mapping, refs, successor padding, negatives, aliases, and score rationale on UID0001OM.
- [x] Perform the documented validator-aware UID-preserving rename: acquire one short lease only when editing the old page, preserve UID0000PG/full content, rename so the old path ceases to exist, and never leave a duplicate or hand-edit validator state.
- [x] Run the default scoped validator on `by-global/g_friendNameListSyncEnabled.md` without `--uid-only`; verify validator-managed UID mapping and registered-reference propagation, then immediately release the rename-page lease.
- [x] Reread/rebase renamed UID0000PG, preserve UID/owner/emitter, set `92/94`, true, position0, install container-only R2, and document the shared-header `extern` without emitting it into `FriendListDialog.cpp`.
- [x] Reread the complete ordinary link union after propagation; update any remaining old-path link one page/lease/validator/release at a time without losing unrelated content.
- [x] Reread/rebase UID00005J, set `90/93`, position10, and install R3 exactly.
- [x] Record exact `0x26c` no-field layout, three vtables, `+0x48/+0x58` methods, access, and compiler exclusions on UID00005J.
- [x] Reread/rebase UID0001DS, set `92/93`, and install exact C++03 R4 with direct observed modern/classic branches.
- [x] Preserve both branch layouts, immediate bounds/resources, canonical control signatures, left-ten/right-ten insertion matching ids `2..21` to config slots `0..19`, `ReadText(...,64)`, trim behavior, optional send, unconditional save, close/remove, ranges/padding/callers/destructor history on UID0001DS; verify no `constexpr`, `FriendListLayout`, or layout-instance object is introduced.
- [x] Reread/rebase UID0000JN, set `91/93`, and add complete source ordering/ownership/linkage/compiler evidence.
- [x] Reread/rebase UID0000UP, set `90/93`, retain NONE/FALSE/blank formal, and add exact protocol/source-boundary evidence.
- [x] Verify UID0001AZ exact current formal/no-entry proof and leave score/route/body unchanged except rename-managed link.
- [x] Verify UID00037T exact live inline-case disposition and leave score/route/formal unchanged.
- [x] Verify UID0001HX exact Socket formal/route/score and leave ordinary page unchanged except rename-managed link.
- [x] Verify MapPane class/file and packet aggregate current union; apply only rename-managed path links.
- [x] Verify CashShopRequest class/file stale-alias history; apply only rename-managed path links.
- [x] Verify client_network/client_opcodes/MapServerPacketOpcode current union; apply only rename-managed path links.
- [x] Verify UID00027W/UID00027X/UID00027Y boundaries/metadata remain unchanged.
- [x] Preserve UID00038A scalar wrapper and all vtable/thunk/compiler no-code dispositions.
- [x] Preserve all historical reports as historical evidence and all rejected alternatives/negative evidence.
- [x] Confirm IDA rename/type/comment mutation remains not requested and not performed.
- [x] Confirm no third-party import directive applies.
- [x] Run one scoped validator per changed/renamed ordinary page after its edit.
- [x] Release each ordinary lease immediately after its scoped validator before acquiring another.
- [x] Run final waited validation through `by-file/FriendListDialog.md`.
- [x] Verify generated UID0001OM definition appears exactly once before class/method use, R2 is child-container-only, and same-TU `extern bool g_friendNameListSyncEnabled;` appears zero times; separately retain the shared-header declaration requirement in prose.
- [x] Verify generated class closes before all qualified definitions.
- [x] Verify constructor, destructor, OnControlCommand, and SetHoverControl each appear exactly once; verify canonical control names/signatures, direct modern/classic branches, left-ten then right-ten loop order, `ReadText(...,64)`, and zero `constexpr`/`FriendListLayout`/layout-instance identifiers.
- [x] Verify `g_packetSender->BuildAndSendFriendNameListSync()` appears exactly once and old free-style call appears zero times.
- [x] Verify UID00005J, UID0000PG, and UID0001OM Empty Emitter Markers are zero.
- [x] Verify UID00038A compiler-only Empty Emitter Marker remains exactly once and no wrapper body is handwritten.
- [x] Verify old `OnOkCommand` and `OnFocusStateChanged` qualified definitions are zero.
- [x] Verify no generic `ImagePane`/`ButtonPane`/`TextEditPane` constructor expression, interleaved editor insertion, duplicate/wrong-range target, raw duplicate body, vtable/RTTI arrays, scalar flags, raw addresses, cookie, or EH code emits.
- [x] Record validator command IDs, timestamps, exits, ok counts, warnings, side effects, and generated header freshness.
- [x] Re-read current manual coverage rows and preserve external concurrent union; B003 must not edit coverage.
- [x] Update C01-C20 to legal callback terminal states with claim-specific destination/validator/generated proof.
- [x] Update Current Target State, Validator Results, Changed Files, hashes, and lifecycle wording to callback-time truth.
- [x] Check every callback item only after exact readback proves it.
- [x] Confirm all NEW/provisional tokens are absent; no new UID is expected.
- [x] Confirm zero B003 leases remain.
- [x] Confirm B003 did not run/probe execute_report or any lifecycle/move/archive command.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support details incorporated at report-level depth.
- [x] Claim ledger terminal with exact destination and proof for every C01-C20 row.
- [x] R1-R4 installed byte-for-byte at their exact destinations.
- [x] UID0000PG rename and all ordinary/manual link handoff facts verified.
- [x] Scores, metadata, source placement, history, negatives, and no-code distinctions verified.
- [x] Every changed ordinary page scoped-validates and all leases are released.
- [x] Final waited generated assertions pass.
- [x] Exact manual supervisor-owned coverage handoff remains current or is rebased without B003 editing coverage.
- [x] No accepted implementation item remains blocked or unapplied.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000015482","destination_path":"executed-b-agent-research/B003/0001OM-FriendNameListSyncEnabled-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001OM-FriendNameListSyncEnabled-source-quality.md","timestamp":"2026-07-20T17:25:18-04:00","uid":"0001OM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
