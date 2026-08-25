** TARGET-REPORT-UID:00013W **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00013W ParseEntries Ownership / Split Research


## Finalized Report / Current Recommendation

- Current recommendation: implemented unchanged. UID00013W is the source-authored file-local `DecodeTableValue` helper in `NexusTK/archive/DATFile.cpp`; historical `ParseEntries` remains provenance/search wording only.
- Final disposition: implementation complete. UID00013W decodes one fixed eight-byte scalar unit, and exact typed wrappers are registered as UID0004IY/UID0004IZ. The helper, wrappers, aliases, compiler-pool page, aggregate, and all support docs now carry the accepted dispositions.
- Required action: no B001 implementation work remains. C13W-001 through C13W-027 are applied and verified below. Report validation/execution/count/path/move/archive state is external supervisor/validator-owned and is neither asserted nor directed by this artifact.
- Confidence: very high for binary behavior, range, caller set, constant values, failure contract, and source module; high for typed wrapper roles and local-initializer source shape; medium-high for inferred human names because no original symbols survive.

## Supporting Research

- Agent-B001 report-only research and the supervisor-accepted implementation callback were performed on 2026-07-12 under `ntk-b-agent-workflow`.
- The healthy evidence session was streamable IDA MCP database `bf5519ae`. At `2026-07-12T19:44:50-04:00` and again during later calls, `idb_list` returned one active database and `server_health` returned `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true` for `NexusTK.exe` at image base `0x00400000`.
- Direct MCP calls used `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `insn_query`, `xrefs_to`, `get_bytes`, and wrapper/consumer decompilation. No IDA mutation tool was called.
- A matching-report search used `UID:00013W`, `0x004a5e60`, `ParseEntries`, `ReadAllEntries`, `ReadEncodedTableInt`, and `ReadEncodedTableFloat`. Matching executed reports were treated as leads and rechecked against the live IDB.
- The current read-only resource package was checked only as negative evidence. `LIGHT.TBL` in `E:\2026\Resources\Read_Only\NexusTK\Data\misc.dat` is 3,080 bytes, but none of its 385 eight-byte units validates with this executable's exact decoder/key schedule. This reproduces the prior B003 mismatch and is not used to alter binary-derived behavior.
- Historical report-only boundary: before Gate 1, no by-* file or validator was touched.
- Callback boundary: B001 edited only the eleven by-* pages listed in `Changed Files`, using short leases and scoped validators. Generated files changed only through validator refresh; B001 manually edited no generated/coverage/tracker/supervisor/registry/queue state.
- B001 ran no report lifecycle, `execute_report`, move, or archive command. Current report validation/execution/count/path/move/archive state remains external supervisor/validator-owned.

## Target

- Target UID: `00013W`.
- Target path: `by-memory/0x004a5e60-0x004a609f.ParseEntries.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `by-memory` / `Not-Covered Files - Reconstructable`, row observed at line 1606.
- Current supervisor classification: supervisor-accepted implementation callback completed; artifact prepared for independent Gate 2 review.
- Current scores and parent state: UID00013W is `92/94`, `CANONICAL_OWNER:0000IN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IN`, position `10`, with the accepted formal helper body.
- Historical tracker state observed at evidence time: average `88.0`, reconstructable true, report count `0`. This is timestamped input evidence, not an assertion about later lifecycle state.

## Current Target State

- UID00013W now carries the complete `DecodeTableValue` body, exact range/padding, all 27 initializer values/order, loops, unsigned arithmetic, in-place mutation, big-endian words, validation/payload expressions, failure side effects, lifetime, caller split, ownership, negative evidence, and historical alias text.
- UID0004IY (`0x0049c4a0-0x0049c4ef`) and UID0004IZ (`0x0049c4f0-0x0049c53f`) are registered exact children at `90/93`, owner/emitter UID00003G, positions `10`/`20`, with the accepted typed method bodies and complete caller/type evidence.
- UID0000TH/UID0000V5 carry exactly the two covered-by blocks; UID0003IC is `92/94`, owner UID00013W, reconstructable false, no emitter/code; UID00012D is `88/92`, non-emitting aggregate/index.
- UID00003G is `88/91`, UID0000IN is `89/92`, UID0000UC/UID0001QC carry the accepted scalar-versus-directory/package clarifications, and UID000229 remains unchanged.
- Historical `ParseEntries`, `ReadAllEntries`, `ReadAllEntriesAlt`, standalone-table, outer-record association, and obsolete `95/95` assumptions are preserved as superseded history rather than current blockers.
- At B001's waited verification time, generated output was fresh to validator command `000000008716` / `2026-07-12T20:14:06-04:00` and contained one helper, two wrappers, two alias comments, no UID0003IC declaration, no UID00012D marker, and no duplicate body.

## Executive Recommendation

- UID0000IN `DATFile` remains the direct semantic/source owner and generated root; no separate parser source file was introduced.
- The source concept is now `DecodeTableValue`. Existing Markdown paths and UIDs remain stable for provenance, and `ParseEntries_004A5E60` is explicitly historical alias wording.
- UID00013W emits once as a file-local `static int` helper taking a mutable eight-byte buffer, an unsigned validation key, and an untyped writable output pointer.
- The two direct DATFile wrappers are exact by-memory children UID0004IY/UID0004IZ, named `DATFileReadEncodedTableInt`/`DATFileReadEncodedTableFloat`, attached to UID00003G and emitted through UID00003G into UID0000IN.
- UID0000TH and UID0000V5 remain searchable aliases with formal covered-by comments and do not duplicate the helper body.
- UID0003IC is compiler-materialized initializer-pool data: owner UID00013W, reconstructable false, no emitter, blank C++.
- UID00012D is a non-emitting aggregate/index with registered exact wrapper children and no empty source-body emitter.
- No entry-record type was created for the eight-byte unit. Its only lifetime is the wrappers' local byte array.

## Supervisor Active Recheck

- Trigger: Gate 1 passed exact SHA `7FC89B633853B84BB1F7D02222BD8E1546030BB36FE1B4D865C9026AB7FC7115`, followed by the accepted C13W-001 through C13W-027 callback.
- Split-first result: exact children UID0004IY and UID0004IZ were created and validator-registered before any support page received their real UID references.
- Source-bearing result: exactly five managed blocks were applied: UID00013W, UID0004IY, UID0004IZ, UID0000TH, and UID0000V5. UID0003IC/UID00012D remain blank by their accepted no-code proofs.
- No accepted item is deferred or unapplied. Remaining uncertainty is limited to original spelling/access declarations and package equivalence, which are documented confidence caps.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest true semantic owner, a valid emitter route, no duplicate body emission, and exact managed insertion shape for any proposed C++. Those rules drive the target/body, wrapper-child, alias, constant-pool, and aggregate dispositions.
- Existing docs were treated as hypotheses, especially `ParseEntries`, `ReadAllEntries`, `ReadAllEntriesAlt`, "entry header", separate constant-table declaration, and the old `95/95` blocker.
- Direct IDA facts are separated below from documentation evidence and source inference. Inferred names are labeled inferred rather than original-symbol proven.
- Historical Wave2 names were encountered in old reports/traces and ignored as stale evidence. They remain useful search aliases only.
- Consumer xrefs establish API use but do not independently establish owner. Ownership is supported by the two direct DATFile callers, wrapper behavior, broad DATFile consumer API, existing source tree, and absence of any competing direct caller/source route.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Evidence | Disposition |
| --- | --- | --- | --- |
| Function name | The function decodes one scalar bit pattern and returns one success value; it never parses an entry array. | Complete decompile/disassembly and both wrappers. | Use inferred `DecodeTableValue`; preserve `ParseEntries` only as historical documentation alias. |
| Return type | Both helper and wrappers return exact full-register `0`/`1`; consumers add results and compare totals. | Target success/failure paths write `EAX`; wrappers directly return target result; Effect loader sums results. | Use `int`, not source `bool`, to preserve the observed ABI and arithmetic use. |
| Third argument | Integer and float wrappers pass storage with different source types; target writes four raw bits. | Six `0x0049c4f0` calls land in float fields; 87 `0x0049c4a0` calls land in integer/count/flag fields. | Use `void *outValue` in the shared helper; typed pointers in wrappers. |
| Input/container type | Only eight bytes are read and mutated. No count, vector, array, or record pointer is accepted. | Wrapper local `_BYTE[8]`; target accesses offsets `0..7` only. | Use `unsigned char *encodedBytes`; no container/type page. |
| Entry-record layout | The eight-byte unit is unrelated to outer archive `DATEntryRecord { uint32 offset; char name[13]; }`. | No 17-byte stride/name/next-record access in target or wrappers. | Add explicit negative clarification to UID0000UC/UID0001QC; do not invent an eight-byte record class. |
| Table source shape | Six XMM loads plus three immediate stores exactly fill 27 local dwords, then the same stack array is mutated. | Disassembly `0x4a5e82-0x4a5ee6`; constant bytes/xrefs. | One local 27-element initializer in target; UID0003IC becomes compiler pool, not standalone source data. |
| Loop/bounds | Mix loop uses `1,3,...,25`; decode processes exactly eight bytes; index is always modulo 27. | Branch at `0x4a5f06`; unrolled byte sequence through `0x4a601f`. | Fixed bounded loops, no sentinel. |
| Key arithmetic | Initial remainder uses unsigned `div` after `0xFEDCBA98 - validationKey`. | `xor edx,edx`, `div ecx` at `0x4a5e8c`. | Preserve unsigned wraparound and modulo 27. |
| Conversion | Both decoded words are assembled big-endian and deinterleaved with mask `0x55555555`. | Shift/add sequence `0x4a6022-0x4a6057`, compare/output expressions. | Preserve explicit unsigned shifts and mask operations. |
| Failure behavior | Validation failure returns zero after all eight input bytes are mutated and leaves output untouched. | Output store occurs only at `0x4a6077`; failure branch at `0x4a6067`; all mutations precede compare. | Document and preserve partial side effect exactly. |
| Allocation/lifetime | Target uses only a 27-dword stack array and compiler cookie. Wrappers use only an eight-byte stack buffer. | Stack frames and callee inventory. | No allocation, ownership transfer, cleanup, or persistent storage. |
| Wrapper distinction | Bodies are binary-identical except address, but call-site destination types differ consistently. | 87 versus six xrefs and representative Effect/Item/Light decompilation. | Source overload-like methods `ReadEncodedTableInt(int *)` and `ReadEncodedTableFloat(float *)`. |
| Source placement | Only direct callers are DATFile methods; higher-level image/resource code calls those methods, not the helper. | Target xrefs and source-root docs. | File-local helper in `archive/DATFile.cpp`. |
| Adjacent runtime helpers | `0x004a60a0-0x004a60cb` is already UID000229, non-reconstructable runtime support with no refs. | Evidence-time MCP `insn_query`, `lookup_funcs`, `xrefs_to`, pointer-pattern search, existing exact page. | Already present; no source merge or support edit. |
| Resource-package validation | Current `misc.dat` LIGHT.TBL does not validate under this exact executable algorithm. | 385/385 units failed expected-key validation. | Treat as package/version/path mismatch; do not weaken direct binary facts or claim decoded values. |

Rejected alternatives:

- Keep `ParseEntries`: rejected because it materially misstates one-scalar behavior and propagates the false entry-array model.
- Use `bool`: rejected because the full `EAX` result is consumed arithmetically without caller-side boolean normalization.
- Use `int *` for every layer: rejected because the float wrapper writes IEEE-754 bit patterns directly into float storage.
- Use `float *` in the shared helper: rejected because the integer wrapper is the dominant use and the helper performs no numeric float conversion.
- Return the decoded value directly: rejected because zero is a valid payload bit pattern and success/failure is a separate observed result.
- Leave the constant pool as separately emitted source data: rejected because the final three immediate stores and mutable stack use are characteristic of a local initializer.
- Move the helper to BinaryCodec/Decoder because of address adjacency: rejected. The preceding range is separated by 12 bytes of `0xcc`, the parser has independent DATFile-only callers, and BinaryCodec reports already establish that boundary. Address adjacency alone is not source ownership.
- Move the helper to Effect/Item/Light image libraries: rejected because those are indirect consumers through DATFile methods.
- Hand-port UID000229 bit helpers: rejected because that exact page is runtime/non-source, has no incoming refs, and lies outside UID00013W.

## Evidence Standards Used

- Highest-weight evidence: live function boundaries, complete target disassembly/decompilation, exact direct xrefs, exact wrapper bodies, exact consumer destination types, raw bytes, constant xrefs, and stack/output-store ordering.
- Corroborating evidence: current by-* docs, generated emitter state, accepted consumer pages, source-tree placement, and matching executed reports after live recheck.
- Negative evidence: no other target callers, no allocation/helper calls beyond security-cookie code, no output store on failure, no sentinel loop, no 17-byte record access, no target references to UID000229, and no current-package validation.
- Binary facts control behavior and ranges. Source names, `void *` abstraction, local initializer spelling, and wrapper names are evidence-backed inference.
- Confidence is capped below final-audit scores because original symbols/header declarations and an exact matching resource package are unavailable.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list` and `server_health` for database `bf5519ae`.
  - `lookup_funcs` for `0x004a5e60`, both wrappers, target boundaries, UID000229 boundaries, and successor `0x004a60d0`.
  - `analyze_function`, `decompile`, and full 188-instruction `disasm` for `0x004a5e60`.
  - `decompile` for `0x0049c4a0`, `0x0049c4f0`, `0x004de7d0`, `0x004dec30`, `0x004df500`, and `0x004df7e0`.
  - `xrefs_to` for target, wrappers, all six constant blocks, and UID000229 starts.
  - `get_bytes` for `0x006192e0-0x00619340`, predecessor/target start, target end/successor, and DATFile vtable slots.
  - `insn_query` for `0x004a60a0-0x004a60d0`; VA pointer-pattern searches for both runtime helper starts.
- by-* docs/support checked: UID00013W, UID0000TH, UID0000V5, UID0003IC, UID00012D, UID00003G, UID0000IN, UID0000UC, UID0001QC, UID000229, BinaryCodec boundary docs, Effect/Item/Light consumer children, current generated DATFile.cpp, generated memory coverage, tracker, and completion stats.
- Old-report searches checked matching B003/B005 consumer reports, B006/B009 codec-boundary reports, and B015 DATFile empty-emitter report. No prior exact UID00013W B report existed.
- Negative checks performed: no additional target caller, no target allocation/callee family, no output write before validation, no sentinel, no outer-record access, no UID000229 target reference, no pointer route to runtime starts, and no matching current-package scalar validation.
- Historical pre-Gate-1 boundary: IDA renames/types/comments and all project mutations were intentionally skipped during report-only research; validators were prohibited before Gate 1.
- Accepted callback work: the eleven by-* pages in `Changed Files` were then created or updated under short leases and scoped validation. IDA mutation remained out of scope.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C13W-001 | Exact target is `0x004a5e60-0x004a609f`, size `0x23f`; last instruction is `retn` at `0x004a609e`. | Very high | MCP lookup/disasm/bytes. | UID00013W range/evidence. | Applied. | UID00013W exact range/final instruction recorded; validator `000000008716` ok. |
| C13W-002 | Predecessor padding is `0x004a5e54-0x004a5e60`; successor byte `0x004a609f` is one `0xcc`. | Very high | Raw bytes and existing coverage. | UID00013W range section. | Applied. | Both boundaries and UID000229 successor split recorded. |
| C13W-003 | Source ABI is full-register `int __cdecl`; inputs are mutable eight-byte data, unsigned key, and writable four-byte output storage. | High | Disassembly, wrappers, typed consumers. | UID00013W signature/type section. | Applied. | UID00013W body/status uses `int`, unsigned key, and `void *`; wrappers are typed. |
| C13W-004 | Direct caller set is exactly wrapper starts `0x0049c4a0` and `0x0049c4f0`, calls at `0x0049c4d4`/`0x0049c524`. | Very high | Target xrefs/callers. | Target/global/item/class/file/aggregate. | Applied. | Real children UID0004IY/UID0004IZ linked in every accepted destination. |
| C13W-005 | Each wrapper computes `GetSize() >> 1`, reads exactly eight bytes, and immediately returns decoder result. | Very high | Wrapper decompilation/disassembly. | UID0004IY/UID0004IZ and DATFile support. | Applied. | Exact managed bodies plus behavior/failure prose on both children. |
| C13W-006 | `0x0049c4a0` is the integer/scalar wrapper; 87 call sites use counts, IDs, flags, and integer fields. | High | Xrefs and consumer decompiles. | UID0004IY/class/file/aggregate/meta. | Applied. | UID0004IY `90/93`; 87-call/seven-function inventory documented. |
| C13W-007 | `0x0049c4f0` is the float wrapper; six call sites in four functions write float fields. | Very high | Six xrefs and downstream float arithmetic. | UID0004IZ/class/file/aggregate/meta. | Applied. | UID0004IZ `90/93`; all six call addresses/destinations documented. |
| C13W-008 | Target processes one eight-byte scalar unit; no array, vector, outer entry record, or sentinel exists. | Very high | Fixed offsets/loops and no container accesses. | UID00013W/UID0000UC/UID0001QC. | Applied. | Scalar/17-byte-record distinction and negatives present in all three docs. |
| C13W-009 | Local initializer order is `75,25,31,29,26,9,12,12,83,73,19,17,29,23,6,29,9,6,8,27,28,1,30,29,3,5,9`. | Very high | XMM load order, bytes, immediate stores. | UID00013W/UID0003IC. | Applied. | Exact 27 values/order in target body and constant-pool source-order section. |
| C13W-010 | Mix loop cumulatively XORs indices `1..26` in pairs. | Very high | `0x004a5ef0-0x004a5f06`. | UID00013W behavior/C++. | Applied. | Exact loop appears once in source and generated output. |
| C13W-011 | Start index is unsigned `(0xFEDCBA98u - validationKey) % 27`; decode steps backward modulo 27. | Very high | Unsigned `div`; unrolled modulo sequence. | UID00013W behavior/C++. | Applied. | Exact unsigned expression and backward step in target/generated body. |
| C13W-012 | All eight input bytes are XOR-mutated with low bytes of mixed dwords. | Very high | `0x004a5f08-0x004a601f`. | UID00013W behavior/C++. | Applied. | Fixed eight-iteration mutation loop and failure-side-effect prose present. |
| C13W-013 | Decoded halves are read as big-endian 32-bit words. | Very high | `0x004a6022-0x004a6057`. | UID00013W behavior/C++. | Applied. | Exact unsigned big-endian assembly present. |
| C13W-014 | Validation result is `second ^ ((first ^ second) & 0x55555555)` and must equal the key. | Very high | `0x004a6059-0x004a6067`. | UID00013W behavior/C++. | Applied. | Exact validation expression present. |
| C13W-015 | Successful payload is `first ^ ((first ^ second) & 0x55555555)`. | Very high | `0x004a6069-0x004a6077`. | UID00013W behavior/C++. | Applied. | Exact output expression present. |
| C13W-016 | Failure returns `0`, leaves output untouched, but leaves all eight input bytes decoded/mutated; success writes output and returns `1`. | Very high | Store/branch ordering. | Target/wrapper contracts. | Applied. | Target, both children, aliases, class/file/meta preserve conditional store and no rollback. |
| C13W-017 | Target allocates nothing and transfers no ownership; target and wrappers use stack locals only. | Very high | Callee/stack inventory. | UID00013W lifetime section. | Applied. | Lifetime/no-allocation facts present on target and wrappers/support. |
| C13W-018 | `DecodeTableValue` is the best descriptive source-facing name; original spelling remains unproved. | High | One-scalar behavior and accepted wrapper vocabulary. | Target/global/item/class/file/meta. | Applied. | Emitted name corrected; historical aliases retained as evidence-backed confidence cap. |
| C13W-019 | UID0000IN remains direct source owner/emitter root. | Very high | Exact caller restriction and subsystem API. | Target/global/item/file. | Applied. | UID00013W/aliases retain UID0000IN route; file remains `NexusTK/archive/`. |
| C13W-020 | UID0003IC is compiler-materialized local-initializer pool data, not a standalone source declaration. | High | Six pooled blocks plus final immediates and in-place stack mutation. | UID0003IC. | Applied. | UID0003IC `92/94`, owner UID00013W, false, blank emitter/C++; generated count zero. |
| C13W-021 | Create exact integer wrapper child at `0x0049c4a0-0x0049c4ef`. | Very high | Function size `0x4f`, exact body/xrefs. | UID0004IY. | Applied. | Registered by validator `000000008670`; exact body/metadata/evidence present. |
| C13W-022 | Create exact float wrapper child at `0x0049c4f0-0x0049c53f`. | Very high | Function size `0x4f`, exact body/xrefs. | UID0004IZ. | Applied. | Registered by validator `000000008672`; exact body/metadata/evidence present. |
| C13W-023 | UID0000TH and UID0000V5 are aliases and must emit covered-by comments only. | Very high | Same address/body and existing LoadDatFileBuffer precedent. | Global/item formal blocks. | Applied. | Exactly two alias comments in generated DATFile.cpp; no duplicate alias body. |
| C13W-024 | UID00012D is an aggregate/index, not a standalone source body. | High | Mixed broad range and exact-child model. | UID00012D metadata/body. | Applied. | `88/92`, false, blank emitter/C++; generated UID00012D count zero. |
| C13W-025 | Current-package LIGHT.TBL mismatch is negative evidence only. | High | 0/385 validation result; prior B003 mismatch. | Target/meta negative evidence. | Applied. | Preserved without payload-value claims in target and UID0001QC. |
| C13W-026 | UID000229 runtime pair is already correctly split/non-reconstructable and is not part of target C++. | Very high | Evidence-time MCP plus exact page. | Report and target boundary note. | Already present; no edit. | UID000229 unchanged; target records boundary/no-merge/no-xref proof. |
| C13W-027 | Generated order should place helper before wrapper definitions and remove duplicate/empty target-family markers. | High | C++ dependency and generated DATFile.cpp. | Target/wrapper positions and generated verification. | Applied. | Command `000000008716`: helper lines 8+, wrappers lines 57/68; UID0003IC/UID00012D absent; counts 1/1/1/2. |

## Positive Evidence Summary

- Direct facts supporting the recommendation: exact 575-byte function, two callers, one compiler-only callee, fixed local table, fixed eight-byte mutation, big-endian reads, exact mask expressions, exact output/failure ordering, and full-register `0`/`1` return.
- Wrapper evidence resolves the API split without changing the type-neutral helper: 87 integer-like calls versus six float-storage calls, with float values subsequently consumed as floats.
- Constant layout strongly supports a single local initializer because 24 dwords are loaded from pooled read-only blocks and the remaining three dwords are written as immediates into the same contiguous stack array.
- Existing DATFile ownership is corroborated by both direct callers being DATFile methods and by all higher-level consumers calling those wrappers rather than UID00013W directly.
- The strongest inference chain is: exact one-scalar target behavior plus typed wrapper destinations plus accepted consumer vocabulary yields `DecodeTableValue`, `ReadEncodedTableInt`, and `ReadEncodedTableFloat` as coherent source-facing names.

## IDA MCP Facts

- Function/range facts: `sub_4A5E60`, start `0x004a5e60`, size `0x23f`, end `0x004a609f`, 188 instructions, five basic blocks, cyclomatic complexity two.
- Prototype fact: current IDA type is `int __cdecl(unsigned __int8 *, int, int *)`; unsigned arithmetic and heterogeneous consumers justify source refinements described above.
- Callee fact: only `@__security_check_cookie@4`; cookie code is compiler-generated and not source logic.
- Data/table facts: six 16-byte blocks at `0x006192e0-0x00619340`, one xref per block, all from target; final three local values are immediate `3`, `5`, `9`.
- Padding facts: 12 `0xcc` bytes before target, one `0xcc` byte after target, then UID000229.
- Xref facts: target calls only from `0x0049c4d4` and `0x0049c524`; integer wrapper has 87 calls; float wrapper has six.
- Negative IDA facts: no allocation, no external helper logic, no alternate target caller, no sentinel access, no 17-byte record access, and no target edge to adjacent UID000229.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0049c4a0-0x0049c4ef` | UID0004IY / `by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md` | DATFile integer scalar wrapper | true | UID00003G | `90/93` | Created and validator-registered before support references. |
| `0x0049c4f0-0x0049c53f` | UID0004IZ / `by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md` | DATFile float scalar wrapper | true | UID00003G | `90/93` | Created and validator-registered before support references. |
| `0x004a5e60-0x004a609f` | UID00013W | Type-neutral table-value decoder | true | UID0000IN | `92/94` | Exact target with formal body. |
| `0x006192e0-0x00619340` | UID0003IC | Compiler-pooled local initializer bytes | false | UID00013W | `92/94` | Reclassified; no C++. |
| `0x0049c130-0x0049d2cc` | UID00012D | DATFile method aggregate/index | false | UID0000IN | `88/92` | Non-emitting with exact child links. |
| `0x004a60a0-0x004a60cb` | UID000229 | MSVC runtime helper pair | false | none | current `85/88` | Already correctly excluded; no edit. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0049c4d4` | `sub_49C4A0 -> sub_4A5E60` | Integer-scalar wrapper is direct target caller. |
| `0x0049c524` | `sub_49C4F0 -> sub_4A5E60` | Float-scalar wrapper is direct target caller. |
| `0x0049c4a0` | 87 calls in seven functions | Dominant integer/count/ID/flag scalar API. |
| `0x0049c4f0` | Six calls in `0x004de7d0`, `0x004dec30`, `0x004df500`, `0x004df7e0` | Float-storage API; fields later participate in float operations. |
| `0x006192e0` | data xref from `0x004a5e9e` | Initializer block copied into target local array. |
| `0x006192f0` | data xref from `0x004a5eaa` | Initializer block copied into target local array. |
| `0x00619300` | data xref from `0x004a5ecd` | Initializer block copied into target local array. |
| `0x00619310` | data xref from `0x004a5eb8` | Initializer block copied into target local array. |
| `0x00619320` | data xref from `0x004a5edf` | Initializer block copied into target local array. |
| `0x00619330` | data xref from `0x004a5e82` | First initializer block in source-local order. |
| Target callee | `@__security_check_cookie@4` only | Compiler stack protection; no source helper dependency. |

## Documentation Evidence And IDA Status

- Evidence-time support state: UID00013W/UID0000TH/UID0000V5 recorded the core algorithm and DATFile-only caller set; UID00012D/UID00003G carried integer/float consumer aliases as a deferred DATFile-owner question; UID0000IN already owned the source module.
- Evidence-time stale/incomplete state: `ParseEntries`, `ReadAllEntries`, `ReadAllEntriesAlt`, entry-header/entry-record wording, old `95/95` blocker, standalone constant-table source claim, blank target/alias emitters, and aggregate-only wrapper coverage.
- Evidence-time generated state: `auto-generated/NexusTK/archive/DATFile.cpp` contained empty markers for UID00003G, UID0000TH, UID0000V5, UID00012D, and UID00013W; only LoadDatFileBuffer emitted real source in that file.
- Applied state: those deferred questions and stale claims are resolved in the named support pages. Waited generated output now contains one helper, two wrappers, and two alias comments, with no UID0003IC declaration, UID00012D marker, or duplicate body.

## Ranked Ownership Analysis

### 1. UID0000IN DATFile

- Evidence for: both and only direct callers are DATFile methods; wrappers use DATFile virtual `GetSize` and `Read`; all higher-level users consume the wrappers; existing source root is `NexusTK/archive/DATFile.cpp`.
- Evidence against: target address is not adjacent to the DATFile method cluster, and exact original file boundaries are not symbol-proven.
- Decision: accepted. Caller ownership and API cohesion outweigh linker address order.

### 2. UID0000HQ BinaryCodec / Decoder family

- Evidence for: target follows Encoder/Decoder glue in `.text`, and its constants follow Decoder vtable data in `.rdata`.
- Evidence against: 12-byte padding separates code families; target has independent DATFile-only callers; its data begins exactly where codec vtable reports end; it uses no Encoder/Decoder object or method.
- Decision: rejected. Address/data adjacency is linker-layout evidence, not semantic ownership.

### 3. Image/resource consumer modules

- Evidence for: Effect, ItemObj, LightObj, Human image, and other table loaders account for wrapper fan-in.
- Evidence against: none calls UID00013W directly; the helper is format/access-layer logic shared across consumers.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- No new source file. The two implemented documentation children are exact DATFile methods routed to the existing class/file chain.
- Likely full source grouping: file-local `DecodeTableValue`, `DATFile::ReadEncodedTableInt`, `DATFile::ReadEncodedTableFloat`, existing DATFile methods, and existing `LoadDatFileBuffer` helper in `archive/DATFile.cpp`.
- Rejected grouping: separate `ParseEntries.cpp`, BinaryCodec utility, image-library helper, or source declaration for the pooled constant bytes.

## Source Placement

- Applied placement: file-local helper and DATFile methods in `NexusTK/archive/DATFile.cpp`; declarations for the two public/member wrappers belong with the DATFile class interface when that header is reconstructed.
- Helper sorts before wrapper definitions in generated source, so no artificial forward declaration is required.
- Wrapper child ownership is UID00003G because they are class methods; emission routes through UID00003G to UID0000IN.
- Target remains directly owned/emitted by UID0000IN because it is a file-local free/static helper, not a DATFile member.
- Rejected placements: `util/BinaryCodec.cpp`, `util/Decoder.cpp`, render consumer files, DATFileMgr, or a new module.
- Remaining uncertainty: exact original header exposure and spelling are not recovered; this does not affect body behavior or current `.cpp` placement.

## Range / Split / Padding / Reclassification Analysis

- Target range remains exact and unchanged: `[0x004a5e60,0x004a609f)`.
- Predecessor `[0x004a5e54,0x004a5e60)` and successor `[0x004a609f,0x004a60a0)` remain padding outside the target.
- UID000229 begins at `0x004a60a0` and remains separate runtime/non-source coverage through `0x004a60cb`; no merge with target.
- Exact wrapper children now cover `[0x0049c4a0,0x0049c4ef)` and `[0x0049c4f0,0x0049c53f)`. Each is followed by one `0xcc` alignment byte, respectively `[0x0049c4ef,0x0049c4f0)` and `[0x0049c53f,0x0049c540)`; support code starts at `0x0049c540`.
- UID00012D remains the broad method inventory and is now non-reconstructable/non-emitting because source-bearing methods live on exact children.
- UID0003IC retains its exact `.rdata` range as evidence and is now non-reconstructable compiler materialization owned by UID00013W.
- No target path was renamed. Stable UIDs/paths retain provenance; source-facing names in titles/body/C++ are corrected.

## Negative Evidence Summary

- No alternate direct caller or callback/table pointer reaches UID00013W.
- No entry count, vector, allocation, ownership transfer, sentinel, 17-byte stride, archive name, or next-record offset appears in target.
- No output write occurs on failure; therefore callers cannot rely on a reset/default value from a failed read.
- No rollback restores the input bytes on failure; therefore documenting a side-effect-free validator would be wrong.
- No float instruction occurs in target or either wrapper; float meaning is a caller storage interpretation, not conversion behavior.
- No evidence supports a separately named global constant array. The binary pool omits the last three initializer values and the function mutates only a stack copy.
- No evidence supports BinaryCodec ownership beyond address adjacency.
- No xref or pointer route connects target to UID000229.
- Current package bytes do not validate and therefore cannot establish field values, counts, or original names for this executable.

## IDA Rename / Type / Comment Recommendations

- IDA database mutation was outside both the report-only research and accepted callback scope; none was performed.
- If a later explicitly authorized IDA pass is performed, recommended descriptive names are `DecodeTableValue` at `0x004a5e60`, `DATFile::ReadEncodedTableInt` at `0x0049c4a0`, and `DATFile::ReadEncodedTableFloat` at `0x0049c4f0`.
- Recommended descriptive target type for analysis is full-register integer return, mutable byte pointer, unsigned key, and writable untyped output storage. This is descriptive/inferred, not original debug-type proof.
- Recommended function comment: decodes one eight-byte table scalar in place, validates complementary interleaved bits against `GetSize() >> 1`, writes four payload bytes only on success, returns `1`/`0`.
- Leave UID000229 names/types unchanged in this scope; its runtime classification is already documented.

## First-Draft C++ Recommendation

- Applied formal C++: UID00013W and exact wrapper children UID0004IY/UID0004IZ contain the accepted bodies; UID0000TH and UID0000V5 contain the accepted covered-by comments. UID0003IC and UID00012D contain no C++.
- Whole-report managed-block count: exactly five nonblank destination-specific blocks follow and were applied unchanged. No other C++ body/declaration/sample is proposed or applied anywhere in this report.

Destination: `by-memory/0x004a5e60-0x004a609f.ParseEntries.md` (UID00013W).

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static int DecodeTableValue(unsigned char *encodedBytes,
                            unsigned int validationKey,
                            void *outValue)
{
    unsigned int decodeTable[27] = {
        75, 25, 31, 29,
        26, 9, 12, 12,
        83, 73, 19, 17,
        29, 23, 6, 29,
        9, 6, 8, 27,
        28, 1, 30, 29,
        3, 5, 9
    };

    for (int tableIndex = 1; tableIndex < 27; tableIndex += 2) {
        decodeTable[tableIndex] ^= decodeTable[tableIndex - 1];
        decodeTable[tableIndex + 1] ^= decodeTable[tableIndex];
    }

    unsigned int decodeIndex = (0xFEDCBA98u - validationKey) % 27u;
    for (int byteIndex = 0; byteIndex < 8; ++byteIndex) {
        encodedBytes[byteIndex] ^=
            static_cast<unsigned char>(decodeTable[decodeIndex]);
        decodeIndex = (decodeIndex + 26u) % 27u;
    }

    const unsigned int firstWord =
        (static_cast<unsigned int>(encodedBytes[0]) << 24) |
        (static_cast<unsigned int>(encodedBytes[1]) << 16) |
        (static_cast<unsigned int>(encodedBytes[2]) << 8) |
        static_cast<unsigned int>(encodedBytes[3]);
    const unsigned int secondWord =
        (static_cast<unsigned int>(encodedBytes[4]) << 24) |
        (static_cast<unsigned int>(encodedBytes[5]) << 16) |
        (static_cast<unsigned int>(encodedBytes[6]) << 8) |
        static_cast<unsigned int>(encodedBytes[7]);
    const unsigned int interleavedBits =
        (firstWord ^ secondWord) & 0x55555555u;

    if ((secondWord ^ interleavedBits) != validationKey) {
        return 0;
    }

    *static_cast<unsigned int *>(outValue) = firstWord ^ interleavedBits;
    return 1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md` (UID0004IY).

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int DATFile::ReadEncodedTableInt(int *outValue)
{
    unsigned char encodedBytes[8];
    const unsigned int validationKey =
        static_cast<unsigned int>(GetSize()) >> 1;

    Read(encodedBytes, sizeof(encodedBytes));
    return DecodeTableValue(encodedBytes, validationKey, outValue);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md` (UID0004IZ).

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int DATFile::ReadEncodedTableFloat(float *outValue)
{
    unsigned char encodedBytes[8];
    const unsigned int validationKey =
        static_cast<unsigned int>(GetSize()) >> 1;

    Read(encodedBytes, sizeof(encodedBytes));
    return DecodeTableValue(encodedBytes, validationKey, outValue);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-global/ParseEntries_004A5E60.md` (UID0000TH).

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted implementation for this historical ParseEntries alias is covered by [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md) DecodeTableValue.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-item/ParseEntries_004A5E60.md` (UID0000V5).

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted implementation for this historical ParseEntries item alias is covered by [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md) DecodeTableValue.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact behavior preservation: loops have the proven bounds, unsigned wrap/modulo semantics, in-place mutation, big-endian reconstruction, validation expression, output-store ordering, and integer return contract.
- Plausible source shape: a small file-local helper, local initialized array, ordinary C++98 loops, and two typed DATFile methods match the existing mid-2000s codebase better than decompiler temporaries or explicit XMM constants.
- Inferred names/types: `DecodeTableValue`, `ReadEncodedTableInt`, `ReadEncodedTableFloat`, `validationKey`, `decodeTable`, and `interleavedBits` are descriptive and consistent with already accepted consumer source.
- Naming style: PascalCase method/helper names and descriptive lower-camel locals match current DATFile/consumer reconstruction conventions.
- Third-party import directive: not applicable; this is project source, not a staged third-party embed.
- UID0003IC no-code proof: its bytes are compiler pooling for the target local initializer; a second declaration would duplicate source semantics and may alter output layout.
- UID00012D no-code proof: it is a mixed aggregate/index over exact methods and support spans; source bodies belong on exact children.

## Final Recommendation

- C13W-001 through C13W-027 were applied without compression.
- UID00013W retains owner/emitter UID0000IN, now has position `10` and score `92/94`, and contains the exact helper block.
- Exact children UID0004IY/UID0004IZ were validator-registered before real-UID references were inserted; both attach/emit through UID00003G at positions `10`/`20`, score `90/93`, and contain the exact accepted blocks.
- UID0000TH/UID0000V5 retain owner/emitter UID0000IN and reconstructable true, have scores `90/93` and `89/92`, and emit only their exact covered-by blocks.
- UID0003IC now has owner UID00013W, reconstructable false, blank emitter/position/C++, and complete compiler-pooling evidence.
- UID00012D is reconstructable false with blank emitter/position/C++; UID0000IN remains its semantic owner and its wrapper inventory uses the exact child links.
- UID00003G, UID0000IN, UID0000UC, and UID0001QC contain the accepted prose at report-level detail; no partial DATFile class block was added.
- UID000229 was unchanged. Generated files changed only through authorized validator refresh; tracker, coverage, and manual supervisor files were not manually edited.
- No unrelated source-family work is required by this report.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004a5e60-0x004a609f.ParseEntries.md`.
- Applied metadata: `86/90 -> 92/94`; owner UID0000IN unchanged; reconstructable true unchanged; emitter UID0000IN unchanged; position blank -> `10`.
- Formal C++: blank block replaced with the exact UID00013W managed block above.
- Title/status now identifies source-facing `DecodeTableValue` and retains `ParseEntries` as historical alias/path only.
- Incorporated exact signature/ABI reasoning, callers, typed wrapper distinction, eight-byte scalar unit, local table values/order, loops, unsigned index arithmetic, in-place mutation, big-endian conversion, validation/output expressions, failure side effects, no allocation/ownership, full-register return, source placement, range/padding, constant-pool relationship, current-package negative evidence, and rejected alternatives.
- Stale `95/95` and original-name blocker text replaced with the combined-score/emitter rule and resolved source-ready disposition.
- Prior valid research and historical provenance preserved; superseded assumptions are explicitly historicalized.

## Recommended Support Doc Changes

- UID0004IY `by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md`:
  - Created and registered by scoped validator `000000008670` before real-UID support references were inserted.
  - Applied `90/93`, owner/emitter UID00003G, reconstructable true, position `10`.
  - Contains the exact wrapper body, 87-call inventory summary, integer/count/ID/flag destinations, no conversion, and target relationship.
  - Contains the exact integer wrapper managed block above.
- UID0004IZ `by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md`:
  - Created and registered by scoped validator `000000008672` before real-UID support references were inserted.
  - Applied `90/93`, owner/emitter UID00003G, reconstructable true, position `20`.
  - Contains the exact wrapper body, all six call sites/four containing functions, float destinations and downstream float use, no numeric conversion, and target relationship.
  - Contains the exact float wrapper managed block above.
- `by-global/ParseEntries_004A5E60.md` UID0000TH:
  - Applied `87/91 -> 90/93`; owner/emitter/reconstructable unchanged.
  - Reframed as historical alias for source-facing `DecodeTableValue`; complete contract and constant-pool correction incorporated.
  - Contains the exact covered-by managed block above.
- `by-item/ParseEntries_004A5E60.md` UID0000V5:
  - Applied `86/90 -> 89/92`; owner/emitter/reconstructable unchanged.
  - Reframed as searchable item alias; false implication that it parses UID0000UC records removed and historicalized.
  - Contains the exact covered-by managed block above.
- `by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md` UID0003IC:
  - Applied `89/92 -> 92/94`; owner UID0000TH -> UID00013W; reconstructable true -> false; emitter UID0000TH -> blank; position/code remain blank.
  - All values/xrefs/boundaries preserved; standalone-table claim historicalized and replaced by compiler-pooled first 24 values of the target's 27-element local initializer plus immediate final values `3,5,9`.
- `by-memory/0x0049c130-0x0049d2cc.DATFile.md` UID00012D:
  - Applied `86/90 -> 88/92`; owner UID0000IN unchanged; reconstructable true -> false; emitter UID0000IN -> blank; position/code blank.
  - Exact wrapper children linked only after UID registration; method names/roles corrected, output-type question closed, and aggregate/index no-code disposition explained.
- `by-class/DATFile.md` UID00003G:
  - Applied `86/88 -> 88/91`; owner/emitter/reconstructable unchanged; own formal C++ remains blank.
  - Stale wrapper names/unknown output question replaced with typed signatures/roles; exact children, full-register return, and shared type-neutral decoder documented.
- `by-file/DATFile.md` UID0000IN:
  - Applied `87/89 -> 89/92`; path/FILE ownership unchanged.
  - Contents and file rationale now include the helper and exact wrapper children, source ordering, constant-pool/no-duplicate handling, and generated verification evidence.
- `by-item/DATEntryRecord.md` UID0000UC:
  - Score/metadata/C++ unchanged.
  - Added the negative clarification that the outer packed 17-byte archive directory row is unrelated to the eight-byte encoded scalar consumed inside TBL payloads.
- `by-meta/client_dat_specifications.md` UID0001QC:
  - Score remains excluded.
  - Corrected one-entry-header/bulk-reader wording to one scalar unit, typed wrappers, shared decoder, failure contract, and package-mismatch caveat.
- UID000229 `MsvcInt64RuntimeHelpers`: no edit; current evidence and non-reconstructable disposition already meet or exceed this report.
- Generated/tracker/coverage files: no manual edits. Scoped callback validators refreshed validator-owned generated state.

## Score And Metadata Recommendation

The table preserves the accepted pre-callback values and records the applied values.

| Item | Before callback | Applied | Metadata disposition |
| --- | --- | --- | --- |
| UID00013W | `86/90` | `92/94` | Owner/emitter UID0000IN; true; position `10`; exact body. |
| UID0004IY int wrapper | none | `90/93` | Owner/emitter UID00003G; true; position `10`; exact body. |
| UID0004IZ float wrapper | none | `90/93` | Owner/emitter UID00003G; true; position `20`; exact body. |
| UID0000TH | `87/91` | `90/93` | Owner/emitter UID0000IN; true; covered alias. |
| UID0000V5 | `86/90` | `89/92` | Owner/emitter UID0000IN; true; covered alias. |
| UID0003IC | `89/92` | `92/94` | Owner UID00013W; false; no emitter/code. |
| UID00012D | `86/90` | `88/92` | Owner UID0000IN; false; no emitter/code. |
| UID00003G | `86/88` | `88/91` | Existing class route retained; receives exact wrapper children. |
| UID0000IN | `87/89` | `89/92` | FILE root/path retained. |
| UID0000UC | `88/91` | unchanged | Prose clarification only. |
| UID0001QC | `-1/-1` | unchanged | Meta prose only. |
| UID000229 | `85/88` | unchanged | Already correct runtime exclusion. |

- Reason not higher: no original symbols, no recovered DATFile header declaration, no exact matching package sample, and no compile-to-binary equivalence check. Those are confidence/final-audit limits, not implementation blockers.
- Score-improvement attempts completed: exact caller/callee inventory, full disassembly, constant-byte/order recovery, wrapper consumer typing, failure/side-effect analysis, range/padding recheck, runtime-neighbor liveness check, source placement ranking, old-report search, generated route review, and physical-package negative test.
- All in-scope score blockers now have a resolved recommendation or explicit evidence-backed cap.

## Open Questions With Attempted Resolution

- Exact original helper/method spelling:
  - Checked current IDA names/types, unresolved/resolved alias reports, old reports/traces, generated source, caller vocabulary, and subsystem conventions.
  - Resolution: original spelling is unrecoverable from current artifacts; use descriptive `DecodeTableValue`, `ReadEncodedTableInt`, and `ReadEncodedTableFloat`. This caps confidence but does not block C++.
- Exact third-argument source type:
  - Checked target IDA type, integer and float destinations, wrapper bodies, and lack of conversion instructions.
  - Resolution: `void *` is the safest source-level shared abstraction that preserves direct four-byte stores for both wrapper types.
- Exact current-package mismatch cause:
  - Checked physical archive row/offset, member size, exact recovered seed order, and all 385 LIGHT.TBL units.
  - Resolution: the package is not reliable proof for this executable's scalar encoding path, likely due version/distribution or extraction-path mismatch. No field values are claimed. This does not affect binary-derived code; an exact matching installation/package would be required to close it.
- Whether the constant pool was explicitly declared globally:
  - Checked all six xrefs, local stack layout, final immediate stores, and mutation behavior.
  - Resolution: standalone declaration is less plausible than a local initializer and would duplicate semantics. Reclassify as compiler materialization.
- Whether wrappers belong in public or private DATFile interface:
  - Checked 93 direct call sites across resource loaders. They are broadly consumed member APIs, not file-local functions.
  - Resolution: document as DATFile methods; exact access specifier remains a header-level original-spelling uncertainty and does not affect emitted definitions.
- No unresolved question remains that blocks target/wrapper formal C++, owner/emitter route, split, or score movement.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. The active tracker and generated memory coverage are validator-owned and must not be edited manually.
- No manual `by-memory/-coverage-report.md` text is required by this report. If a supervisor later chooses to synchronize that manual ledger, it should derive the row from the implemented target/new children rather than use report-only text as a direct mutation instruction.

## Follow-Up Actions

- Implementation state: the accepted callback is complete and no B001 work remains for UID00013W.
- External state boundary: report validation, execution, count, path, move, and archive state is supervisor/validator-owned and is neither asserted nor directed by this artifact.
- A-agent actions: none.
- B001 research actions: none. An exact matching resource package could improve final-audit confidence but is not required for the completed implementation.

## Confidence

- Recommendation confidence: `94/100` for behavior and source placement; `88/100` for exact source spelling.
- Score confidence: high. The applied values deliberately remain below `95` because original names/header/package equivalence are unproved.
- Remaining uncertainty: original identifiers/access specifiers and resource-version equivalence only; no binary behavior, ownership, split, or formal-code blocker remains.

## Validator Results

- Command form from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`; the final UID00013W run additionally used `--wait-generated`.

| Scoped file | Command ID | Command timestamp | Exit | ok | Generated result |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md` | `000000008670` | `2026-07-12T20:04:11-04:00` | `0` | Registration output did not print an `ok` count; UID0004IY inserted with no error. | Deferred. |
| `by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md` | `000000008672` | `2026-07-12T20:04:59-04:00` | `0` | Registration output did not print an `ok` count; UID0004IZ inserted with no error. | Deferred. |
| `by-memory/0x004a5e60-0x004a609f.ParseEntries.md` | `000000008689` | `2026-07-12T20:06:13-04:00` | `0` | `1` | Deferred; exposed two temporary UID0003IC registry-mapping warnings resolved by UID0003IC scoped validation. |
| `by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md` | `000000008695` | `2026-07-12T20:07:09-04:00` | `0` | `1` | Deferred; UID0003IC path mapping restored by validator. |
| `by-global/ParseEntries_004A5E60.md` | `000000008698` | `2026-07-12T20:08:18-04:00` | `0` | `1` | Deferred. |
| `by-item/ParseEntries_004A5E60.md` | `000000008703` | `2026-07-12T20:09:03-04:00` | `0` | `1` | Deferred. |
| `by-memory/0x0049c130-0x0049d2cc.DATFile.md` | `000000008705` | `2026-07-12T20:10:07-04:00` | `0` | `1` | Deferred. |
| `by-class/DATFile.md` | `000000008711` | `2026-07-12T20:11:29-04:00` | `0` | `1` | Deferred; nine unrelated/pre-existing `missing_ref_uid` warnings for UID0003I0/UID0003B7. |
| `by-file/DATFile.md` | `000000008713` | `2026-07-12T20:12:21-04:00` | `0` | `1` | Deferred; eight unrelated/pre-existing `missing_ref_uid` warnings for UID0003I0/UID0003B7. |
| `by-item/DATEntryRecord.md` | `000000008714` | `2026-07-12T20:12:54-04:00` | `0` | `1` | Deferred. |
| `by-meta/client_dat_specifications.md` | `000000008715` | `2026-07-12T20:13:38-04:00` | `0` | `1` | Deferred. |
| Final `by-memory/0x004a5e60-0x004a609f.ParseEntries.md --wait-generated` | `000000008716` | `2026-07-12T20:14:06-04:00` | `0` | `1` | `generated_refresh: completed`; no target-specific warning. |

- Waited freshness proof: at B001 verification time, `auto-generated/NexusTK/archive/DATFile.cpp` recorded `validator-command-id: 000000008716` and `validator-refreshed-at: 2026-07-12T20:14:06-04:00`, exactly matching the final command.
- Later external-refresh observation: a read-only audit at `2026-07-12T20:19:15-04:00` found the generated header advanced by validator-owned command `000000008728`. This was not a B001 validator rerun; the generated target-family content/order remained unchanged.
- Generated content/order proof: one `DecodeTableValue` definition starts at line 8, one UID0004IY integer-wrapper definition starts at line 57, one UID0004IZ float-wrapper definition starts at line 68, and exactly two historical-alias comments follow. Counts are helper/int/float/alias `1/1/1/2`; UID0003IC and UID00012D counts are zero; no duplicate target body exists.
- Validator side effects were limited to validator-owned registry/state/generated refresh. B001 manually edited no generated, coverage, tracker, supervisor, registry, or queue file.

## Changed Files

- Created: `by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md` (UID0004IY), `by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md` (UID0004IZ), and this report `tools/leaser/Agents/Agent-B001/research/00013W-ParseEntries-source-quality.md`.
- Modified: `by-memory/0x004a5e60-0x004a609f.ParseEntries.md`, `by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md`, `by-global/ParseEntries_004A5E60.md`, `by-item/ParseEntries_004A5E60.md`, `by-memory/0x0049c130-0x0049d2cc.DATFile.md`, `by-class/DATFile.md`, `by-file/DATFile.md`, `by-item/DATEntryRecord.md`, and `by-meta/client_dat_specifications.md`.
- Renamed: none.
- Project documentation implementation: complete for every accepted destination; UID000229 remained a verified no-edit support page.
- Lifecycle boundary: B001 ran no report validator lifecycle, `execute_report`, move, or archive command. Current report validation/execution/count/path/move/archive state remains external supervisor/validator-owned.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 passed exact report SHA `7FC89B633853B84BB1F7D02222BD8E1546030BB36FE1B4D865C9026AB7FC7115` before implementation.
- [x] Target/support docs updated: UID00013W, exact children UID0004IY/UID0004IZ, UID0000TH, UID0000V5, UID0003IC, UID00012D, UID00003G, UID0000IN, UID0000UC, and UID0001QC; UID000229 was checked and correctly left unchanged.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger contains C13W-001 through C13W-027 with applied destinations and verification proof.
- [x] Metadata/score changes applied exactly as listed in `Score And Metadata Recommendation`.
- [x] Score-limiting blockers researched to resolution or evidence-backed confidence cap.
- [x] Owner/emitter/reconstructable changes applied: target route retained; wrappers route through UID00003G; UID0003IC false/owner target/no emitter; UID00012D false/no emitter; aliases retained as covered emitters.
- [x] Split/rename/new-child changes applied: two exact wrapper children registered; no target path renamed; source-facing names corrected in body/C++.
- [x] Source placement, exact range, padding, constant-pool reclassification, and runtime-neighbor boundary resolved.
- [x] First-draft C++ applied as exactly five destination-specific managed blocks; no other C++.
- [x] Third-party import directive confirmed not applicable; no import path or external payload is used.
- [x] Exact target/support facts incorporated at report-level detail: all C13W claims and support-path instructions.
- [x] Historical/stale assumptions and negative evidence preserved: old names, `95/95` blocker, entry-record confusion, standalone-table claim, package mismatch, rejected owner alternatives, and failure side effect.
- [x] Wave2/Wave3 artifacts encountered and rejected as stale evidence; historical names retained only as aliases.
- [x] Open questions closed or capped with evidence and explicit score/C++ impact.
- [x] Validators ran only during the accepted callback: one scoped validator per changed/new by-* page plus final authorized `--wait-generated` check.
- [x] Generated refresh occurred only through validator; no manual generated/tracker/coverage edit.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation at exact Gate 1 SHA recorded above.
- [x] Re-read exact current paths immediately before each lease/edit.
- [x] Used short one-file leases only immediately before each by-* edit and released each immediately after its scoped validator.
- [x] Created and registered integer wrapper UID0004IY before inserting its real UID references.
- [x] Created and registered float wrapper UID0004IZ before inserting its real UID references.
- [x] Applied C13W-001 through C13W-027 without compression or loss.
- [x] Applied exactly five managed blocks and verified no body/declaration exists outside formal headers.
- [x] Applied all accepted score/metadata/owner/emitter/reconstructable/position changes; no exclusion was needed.
- [x] Preserved valid prior research, historical provenance, rejected alternatives, and negative evidence.
- [x] Updated Claim And Incorporation Ledger with real wrapper UIDs, applied destinations, and proof.
- [x] Resolved all new-child references through scoped validators; no UID was guessed.
- [x] Ran and recorded every scoped validator file, command ID, command timestamp, exit code, ok count/result, and generated-refresh state.
- [x] Ran final authorized `--wait-generated` verification and recorded exact freshness/content proof for `archive/DATFile.cpp`.
- [x] Confirmed generated output has one helper, two wrappers, two alias comments, no constant declaration, no aggregate empty marker, and no duplicate source body.
- [x] Updated `Validator Results`, `Changed Files`, current-state wording, ledger, and both checklist phases claim by claim.
- [x] Confirmed no generated/coverage/tracker/supervisor file was manually edited and no lifecycle/execute/move/archive command was run by B001.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000008742","destination_path":"executed-b-agent-research/B001/00013W-ParseEntries-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00013W-ParseEntries-source-quality.md","timestamp":"2026-07-12T20:27:04-04:00","uid":"00013W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
