# UID 0000MQ - PrimeNumberGenerator Whole-File Source-Quality Research
** TARGET-REPORT-UID:0000MQ **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


Assignment: whole-file source-quality research plus accepted ordinary-document implementation callback  
Canonical target: `source-3/project-documentation/by-file/PrimeNumberGenerator.md`  
Proposed source root: `NexusTK/util/`  
Research disposition: reconstructable file with a header, one source module, three source-bearing methods, and non-emitting compiler/STL consequences

## Finalized Report / Current Recommendation

Retain UID0000MQ as the canonical file owner for `NexusTK/util/PrimeNumberGenerator.cpp` and add `NexusTK/util/PrimeNumberGenerator.h`. The whole-file reconstruction is viable. The source-bearing surface is the `PrimeNumberGenerator` declaration, `GetPrimeAt(int) const`, the sieve constructor, and an empty virtual destructor. The in-range deque address helper, deque clear/storage teardown helper, scalar deleting destructor, exception-cleanup fragments, vtable/RTTI records, and alignment bytes are compiler or standard-library consequences and must not be emitted as project-authored source.

The file page's blank reconstructability field in generated tracker views is not evidence of a non-reconstructable file. The by-file schema intentionally has no `RECONSTRUCTABLE` metadata key. The accepted callback resolves the ordinary-document disposition through explicit body text, complete score rationale, source disposition, coherent class/header formal blocks, and the reconstructability state of direct child pages without adding an invalid metadata field to UID0000MQ.

Implemented file score: completion `94`, confidence `93`. Confidence remains below `95` because no direct runtime construction/use site is present in the current IDB and exact original private/local identifiers are not symbol-proven. Those gaps do not prevent faithful source reconstruction.

The accepted ordinary-document callback implemented every permitted target/support/source-tree claim, validated and physically reread each changed destination, and preserved the two settled non-emitting Deque support pages unchanged. Manual coverage, all 18 IDA actions, and generated/tracker refresh/readback remain supervisor-owned and are explicitly left unchecked and `proposed`.

Gate 2B repair disposition: C29E/I05 is narrowed to one function-repeatable comment at unchanged `sub_54C0C0`; no I05 rename or type action is authorized. The other three modeled-function renames and every I01-I04/I06-I18 action remain unchanged.

## Supporting Research

This report consolidates the canonical file and class pages, all direct memory/type children, relevant Deque support pages, generated output, generated coverage/tracker snapshots, manual coverage tables, the proposed source tree, current-session read-only IDA MCP evidence, source-remnant searches, and prior executed reports used only as research leads.

The research was whole-file rather than constructor-only. It audited the contiguous code island from the end of the preceding `PrettyButton` destructor through the first `PursuitMessageDialogPane` routine, the detached constructor EH chunks, the exact vtable island, the complete auxiliary RTTI graph, the temporary sieve state, the embedded deque state, and every direct inbound reference exposed by bounded IDA queries.

No source remnants were found outside documentation and validator-owned generated output. The historical path `source-3/simroot_v2/class_PrimeNumberGenerator.cpp` named by current docs is absent. No matching archived Agent report was found. Earlier B-agent reports for UID0001FA, UID0001FB, UID0001FC, UID0002OK, and UID000149 were treated as leads and independently rechecked against current docs and IDA.

Historical repair context: supervisor Gate 1 audited exact artifact `260DDF6C123F79134068975FC2773B4AD393F33D8C0979E6984D25D68A861A6A` at `63,117` bytes / `763` physical lines and returned it at `29/33`. This additive revision preserves every passing research section while repairing only claim granularity, xref granularity, the structured IDA handoff, the canonical checklist mirror, and directly dependent self-check text.

Callback context: supervisor Gate 1 then passed exact artifact SHA256 `13A99E1A8C5FF87FC4BBF685292536D91752E0163F0CFE977868C351CF72D270`. The callback changed ordinary documentation only under short-lived leases and scoped validators; it did not mutate IDA or edit manual coverage, generated output, tracker, audit, validator lifecycle, or report lifecycle state.

Historical Gate 2B repair context: the supervisor captured I05 pre-action name/type `sub_54C0C0` / `int __thiscall(int ******this, int)`. The report-authorized `pure:true` rename to `std_deque_int_element_address` returned success but immediate readback rendered `unsigned int __thiscall(int ******this, int)`, so Gate 2B failed closed and no save was authorized. The supervisor discarded that worker, restored backup SHA256 `35A5E6AB17C9001F6C77ED25546094515C5312C736AE77085ECAE89A6767B506`, reopened dated session `supervisor-uid0000MQ-rollback-20260814`, and reported exact restoration of all 18 item/comment/byte/xref views, seven frame views, and four function name/type/disassembly/CFG views with no partial action remaining.

Fresh B005 read-only repair re-attestation found `ok:true`, exact canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, and the same on-disk SHA256 `35A5E6AB17C9001F6C77ED25546094515C5312C736AE77085ECAE89A6767B506`. I02/I06/I07 still have their exact original names, prototypes, empty comment channels, and frames. I05 has the restored name, empty channels, exact 80 bytes/hash, sole inbound xref, and exact frame, but current `inspect_items`, disassembly, function profile, and prototype export consistently render `unsigned int __thiscall(int ******this, int)`. This differs from the supervisor's earlier literal pre-action rendering without evidence of a persisted rename. The deterministic repair therefore forbids both rename and `set_type`, uses only the FP comment endpoint, and requires the immediate post-comment type string to equal the immediate pre-comment type string byte-for-byte.

## Target

| Field | Value |
| --- | --- |
| Assigned UID | `0000MQ` |
| Assigned document | `by-file/PrimeNumberGenerator.md` |
| Canonical owner kind | `FILE` |
| Current proposed reconstruction path | `NexusTK/util/` |
| Current proposed source | `NexusTK/util/PrimeNumberGenerator.cpp` |
| Required companion header | `NexusTK/util/PrimeNumberGenerator.h` |
| Direct class owner | UID0000AT `PrimeNumberGenerator` |
| Primary address children | UID0001FA, UID0001FB, UID0002OK |
| Direct layout/vtable children | UID0001VL, UID0001YG |
| Current target score | `94/93` after ordinary-document callback |
| Recommended target score | `94/93` |
| Work mode | Accepted ordinary-document implementation callback completed; supervisor-owned closure remains |

The assigned target is the file-level source route. Support UIDs are inventoried to make the whole-file conclusion complete; this report does not claim their assignment coverage or authorize unrelated edits.

## Current Target State

The file page already identifies a standalone algorithm/container utility, the `util/` route, the class, layout, vtable, accessor, constructor/destructor aggregate, and the non-emitting Deque helpers. It correctly records the `100..10000000` clamp, seeds `2` and `3`, wheel-factored candidate handling, temporary sieve storage, one-slot vtable, repeated no-direct-caller result, and native `std::deque<int>` ownership.

The Gate 1 artifact recorded these concrete pre-callback defects, retained here as historical implementation inputs:

- UID0001FB emits only an aggregate marker instead of constructor and destructor source.
- The generated `.cpp` contains the class declaration because there is no generated header.
- UID0001VL and UID0001YG are marked reconstructable/emitting despite having no appropriate hand-authored source payload, producing empty-emitter markers.
- The generated target therefore reports six total children, four coded children, two empty children, and no header.
- The file page still names an absent `simroot_v2` recovered file and contains historical text that treats the UID0001FB marker as an acceptable endpoint.
- Manual coverage tables and proposed-source-tree text contain stale scores and a retired standalone `Deque.cpp` route.
- Current IDA names/types/comments are uneven: three source identities remain raw or generic, while compiler-generated artifacts need descriptive separation rather than source emission.

The validator-owned generated snapshot inspected for this report was command `000000023186`, refreshed `2026-08-13T15:06:39-04:00`. That timestamp is evidence for this research pass, not a permanent statement of current tracker state.

Current artifact/lifecycle state: report execution/archive state is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

Ordinary-document callback state: UID0000MQ, UID0000AT, UID0001FA, UID0001FB, UID0001VL, UID0001YG, UID0002OK, and `by-project-structure/proposed-source-tree.md` now carry the accepted dispositions. UID0001FC and UID0001FD were reread unchanged at their already-present non-emitting state. All scoped validators returned exit `0` / `ok: 1`; every generated refresh was reported `deferred`, so generated CPP/H/tracker readback is not claimed here.

## Executive Recommendation

Implement one coherent source unit:

1. Emit a real `PrimeNumberGenerator.h` from UID0000AT, declaring the virtual destructor, exact `GetPrimeAt(int) const` signature, temporary `unsigned int *m_sieveBits`, and native `std::deque<int> m_primes`.
2. Make the class CPP block include that header and `<string.h>`, then attach children.
3. Keep UID0001FA's verified accessor source and place it first.
4. Replace UID0001FB's marker with exact constructor and empty destructor source and place it second.
5. Keep UID0002OK as the third, comment-only compiler-generated vtable marker.
6. Reclassify UID0001VL and UID0001YG as non-reconstructable/non-emitting documentation views because the declaration already represents their source cause.
7. Keep UID0001FC and UID0001FD non-emitting under the Deque/STL documentation route.
8. Record the exact raw/modeled boundaries and negative caller result without converting compiler artifacts into project source.

This resolves the tracker queue's blank reconstructability concern through valid schema and explicit source disposition. It also removes the two empty generated children without inventing a separate Deque source or hand-written RTTI/vtable definitions.

Items 1-8 above are implemented in ordinary documentation. The statement about generated children is an expected consequence, not callback readback: final generated output and tracker confirmation remain supervisor-owned because the scoped validators reported deferred refresh.

For the separate IDA gate, retain only the three pure renames I02/I06/I07. I05 remains `sub_54C0C0` and receives only its exact compiler/STL FP classification; no collision query, rename, type declaration, or `set_type` belongs to I05.

## Supervisor Active Recheck

At Gate 1 and again immediately before any callback, the supervisor should re-read:

- UID0000MQ, UID0000AT, UID0001FA, UID0001FB, UID0001FC, UID0001FD, UID0001VL, UID0001YG, and UID0002OK metadata/formal blocks.
- `auto-generated/NexusTK/util/PrimeNumberGenerator.cpp` and the corresponding generated file-coverage row.
- The current tracker row for UID0000MQ and the command/timestamp at the top of that tracker.
- Manual by-file, by-class, by-memory, by-struct, and by-vtable coverage rows.
- `by-project-structure/proposed-source-tree.md` around the `util/` entries.
- The accepted live IDB health, function boundaries, xrefs, bytes, comments, frame members, and types at the exact addresses listed below.

Generated output and tracker files are dynamic supervisor-owned evidence. If a newer command has already changed child counts, header state, or queue placement, use the newer snapshot and preserve the source conclusions unless binary evidence has changed. If metadata changed concurrently, reconcile rather than overwrite it.

## Inference Research Guidance Check

The inference guidance permits descriptive source naming and source-level recovery when behavior, ownership, and boundaries are strongly established but symbols are absent. This target meets that standard:

- `PrimeNumberGenerator` identity is RTTI-proven, not inferred only from behavior.
- File ownership is supported by active imported metadata, canonical file/class relationships, and the isolated utility role.
- `GetPrimeAt` is descriptive rather than symbol-proven, but its behavior is exact and already consistently adopted by the canonical docs.
- Constructor and destructor identity follows vtable writes, object layout, EH cleanup, and scalar deleting-destructor linkage.
- `m_sieveBits` and `m_primes` are source-facing field names. Their offsets/types are strong; exact original spelling is not proven.
- Local names such as `upperCandidate`, `sieveWordCount`, and `multiple` are readability choices and must not be represented as recovered symbols.

Inference must stop at the evidence boundary. There is no support for a feature-local owner, a persistent sieve member after construction, a custom project Deque implementation, a hand-authored scalar deleting destructor, custom RTTI arrays, an accessor exception path, or active runtime use.

## Heuristic / Inference Reanalysis And Validation

The prior heuristic interpretation was reanalyzed against raw bytes, modeled functions, decompilation, xrefs, RTTI, EH metadata, generated output, and current documentation.

| Question | Reanalysis | Result |
| --- | --- | --- |
| Is the file non-reconstructable because the tracker field is blank? | By-file pages do not carry the child-page `RECONSTRUCTABLE` key; body/source/score disposition is the valid mechanism. | Reject the blank-field heuristic. |
| Is UID0001FB only an aggregate marker? | The constructor's algorithm is recoverable in full, and the destructor source cause is an empty virtual destructor. | Replace marker with source. |
| Is `0x0054c0c0` project Deque code? | It performs compiler/STL block-map element address arithmetic and has one call from the raw accessor. | Keep non-emitting. |
| Is `0x0054c160` a project method? | It is shared `std::deque<int>` clear/storage teardown called from compiler-expanded ctor/dtor paths. | Keep non-emitting. |
| Should the scalar deleting destructor be emitted? | Its flag-controlled object deletion and member teardown are compiler-generated from the virtual destructor. | Document only. |
| Should vtable/layout pages emit code? | Their complete source cause is the class declaration; independent formal code would duplicate or fabricate compiler output. | Reclassify non-emitting. |
| Does no direct caller invalidate source recovery? | No. It supports retained/legacy utility status but does not contradict the complete local implementation. | Retain with confidence cap. |
| Does the sieve iterate all candidates through `limit` conventionally? | The binary pairs `upper-2` and `upper` only while `upper <= limit`; a terminal `6k-1` can be omitted. | Preserve the exact quirk. |

The final recommendation therefore distinguishes exact behavior from naming inference and rejects stale routing assumptions without using absence of callers as absence of source.

## Evidence Standards Used

Evidence was ranked as follows:

1. Current-session read-only IDA MCP facts from the accepted NexusTK IDB: exact bytes, function/chunk boundaries, decompilation, xrefs, names, types, frames, RTTI, and comments.
2. Canonical current by-* metadata and body text.
3. Validator-owned generated output and coverage snapshots, read as dated/dynamic state.
4. Current manual coverage and project-structure pages.
5. Repository-wide source/remnant searches.
6. Prior executed B-agent reports as leads only, followed by independent verification.

Positive claims require direct evidence or convergent independent evidence. Negative claims are bounded to the searched IDB/repository surface and are phrased as current-session results. Compiler/toolchain interpretation is based on instruction semantics, call shape, RTTI/EH structure, and existing confirmed Deque pages rather than naming alone.

## Evidence Checked

| Evidence surface | Checked result |
| --- | --- |
| Goal and project workflow | Agent-B005 assignment, report-only restrictions, exact report template, score/blocker rules, lease rules |
| Canonical file/class docs | UID0000MQ and UID0000AT read in full |
| Direct memory docs | UID0001FA, UID0001FB, UID0001FC, UID0001FD, UID0002OK read in full |
| Direct type docs | UID0001VL layout and UID0001YG vtable read in full |
| Related file docs | UID0000IR Deque confirms no standalone project source |
| Related evidence docs | UID000149 seed push-back evidence and relevant client-container references |
| Generated source | Current `PrimeNumberGenerator.cpp`; no generated `PrimeNumberGenerator.h` exists |
| Generated audit state | File coverage and tracker command/timestamp/row inspected |
| Manual audit state | Relevant by-file, by-class, by-memory, by-struct, and by-vtable rows inspected |
| Project placement | Proposed source tree `util/` entries and stale `Deque.cpp` text inspected |
| Repository search | No actual source remnant outside generated/docs; stale `simroot_v2` source path absent; no matching archived report |
| IDA health | Status OK, exact NexusTK IDB path, image base `0x00400000`, Hex-Rays ready; bounded read-only queries succeeded |
| IDA code island | `0x0054bcbd-0x0054c200`, detached EH chunks, calls, frames, types, comments, and xrefs |
| IDA data island | Vtable `0x0062241c-0x00622424`, auxiliary RTTI, TypeDescriptor, and EH records |

The IDA health response reported `auto_analysis_ready:false`. Under the project workflow this is not independently blocking because server health was OK and all bounded queries needed for this report returned coherent results.

## Claim And Incorporation Ledger

Callback verification states are final for the B-agent write role and are mirrored byte-for-byte in the checklist. Concrete path/hash/validator/reread proof for every row group appears under `Validator Results`. The 21 remaining `proposed` rows are intentionally supervisor-owned: C28 manual coverage, C29A-C29R IDA, and C30-C31 generated/tracker refresh/readback.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 0000MQ | UID0000MQ is a reconstructable retained utility at `NexusTK/util/`; no invalid by-file reconstructability key is needed. | High | Canonical schema, file/class ownership, imported metadata, current tracker analysis | UID0000MQ Status/File Role/Score Rationale | incorporate | applied |
| C02 | 0001FA | Raw `0x0054bcc0-0x0054bcec` is the exact source accessor `GetPrimeAt(int) const`. | High | Raw listing, helper call, object offsets, current formal source | UID0001FA and UID0000AT method/source sections | already-present | already-present |
| C03 | 0001FB | `0x0054bcf0-0x0054c062` reconstructs the complete clamp, seed, wheel-sieve, append, and temporary-buffer cleanup constructor. | High | Hex-Rays, disassembly, call fanout, constants, layout | UID0001FB formal CPP and evidence | incorporate | applied |
| C04 | 0001FB | The source loop must preserve `upperCandidate <= limit` and the paired `upper-2`/`upper` boundary quirk. | High | Constructor control flow and trip-count arithmetic | UID0001FB behavior caveat | incorporate | applied |
| C05 | 0001FB | The source destructor is empty and virtual; member cleanup and deleting-wrapper behavior are compiler consequences. | High | Raw destructor body, scalar deleting destructor, vtable, class layout | UID0001FB formal CPP and split analysis | incorporate | applied |
| C06 | 0001FB | Raw `0x0054c070-0x0054c09c` is a function-shaped destructor/cleanup clone, not another hand-authored method. | High | Bytes, vtable store, repeated deque teardown, no inbound xrefs | UID0001FB inventory/boundaries | incorporate | applied |
| C07A | 0001FB | `0x0054c0a0-0x0054c0bc` is the constructor-owned local EH cleanup chunk for the embedded deque. | High | Constructor CFG ownership, inbound jump `0x00606276`, calls `0x0054c160` and `0x005c7526`, exact 28-byte hash | UID0001FB EH analysis | incorporate | applied |
| C07B | 0001FB | `0x00606270-0x0060627b` is the constructor unwind-dispatch tail chunk that adjusts to `this+0x08` and jumps to `0x0054c0a0`. | High | Constructor CFG, inbound UnwindMap data xref, exact 11 bytes and hash | UID0001FB EH analysis | incorporate | applied |
| C07C | 0001FB | `0x0060627b-0x00606296` is the constructor SEH handler tail chunk that checks the cookie, loads `FuncInfo`, and jumps to `__CxxFrameHandler3`. | High | Constructor CFG/disassembly, inbound `0x0054bcf5` data ref, exact 27 bytes and hash | UID0001FB EH analysis | incorporate | applied |
| C07D | 0001FB | `0x0066392c-0x00663934` is the exact two-field MSVC `UnwindMapEntry` for cleanup tail `0x00606270`. | High | Eight-byte data item `stru_66392C`, bytes, hash, inbound `FuncInfo`, outbound cleanup-tail xref | UID0001FB EH analysis | incorporate | applied |
| C07E | 0001FB | `0x00663934-0x00663958` is the exact MSVC constructor `FuncInfo` item referencing the one-entry unwind map. | High | 36-byte data item `stru_663934`, bytes, hash, inbound handler ref, outbound unwind-map xref | UID0001FB EH analysis | incorporate | applied |
| C08 | 0001FC | `0x0054c0c0-0x0054c110` is non-emitting `std::deque<int>` element-address support. | High | Decompilation, sole accessor xref, Deque docs | UID0001FC; UID0000MQ dependency text | already-present | already-present |
| C09 | 0001FD | `0x0054c160-0x0054c1f1` is non-emitting deque clear/storage teardown support. | High | Decompilation and six ctor/dtor family xrefs | UID0001FD; UID0000MQ dependency text | already-present | already-present |
| C10 | 0000MQ | Exact CC padding and predecessor/successor boundaries prevent range absorption. | High | Raw bytes and function boundaries | UID0000MQ/UID0001FB boundary tables | incorporate | applied |
| C11 | 0002OK | `0x0062241c-0x00622424` is exactly one RTTI pointer plus one deleting-destructor slot. | High | Exact dwords, names, xrefs, neighboring RTTI pointer | UID0002OK and parent evidence | already-present | already-present |
| C12A | 0001YG | `0x0064e318-0x0064e32c` is the compiler-generated PrimeNumberGenerator Complete Object Locator. | High | Decorated name, exact 20 bytes/hash, vtable-prefix inbound xref, TypeDescriptor/CHD outbound fields | UID0001YG COL evidence/non-emitting rationale | incorporate | applied |
| C12B | 0001YG | `0x0064e32c-0x0064e33c` is the compiler-generated one-base Class Hierarchy Descriptor. | High | Decorated name, exact 16 bytes/hash, COL/BCD inbound refs, BCA outbound field | UID0001YG CHD evidence/non-emitting rationale | incorporate | applied |
| C12C | 0001YG | `0x0064e33c-0x0064e344` is the compiler-generated Base Class Array cell plus protected zero padding. | High | Decorated name, exact eight bytes/hash, CHD inbound ref, BCD outbound pointer, undefined trailing dword | UID0001YG BCA evidence/non-emitting rationale | incorporate | applied |
| C12D | 0001YG | `0x0064e344-0x0064e360` is the compiler-generated Base Class Descriptor with PMD `{0,-1,0}` and attributes `0x40`. | High | Decorated name, exact 28 bytes/hash, BCA inbound ref, TypeDescriptor/CHD outbound fields | UID0001YG BCD evidence/non-emitting rationale | incorporate | applied |
| C12E | 0001YG | `0x006788e8-0x0067890c` is the compiler-generated TypeDescriptor for `.?AVPrimeNumberGenerator@@`. | High | Decorated name/string, exact 36 bytes/hash, COL/BCD inbound refs, RTTI-vftable outbound ref | UID0001YG TypeDescriptor evidence/non-emitting rationale | incorporate | applied |
| C13 | 0000MQ | No file-owned global/static table, string, resource, or custom import dependency was found. | Medium-high | String/import/global scan and constructor fanout | UID0000MQ negative evidence | incorporate | applied |
| C14 | 0000MQ | Current IDB has no direct callers for accessor, constructor, or raw destructor; this supports retained/legacy status only. | High | Current bounded xref queries | UID0000MQ active-use caveat | incorporate | applied |
| C15 | 0000MQ | File ownership remains `NexusTK/util/PrimeNumberGenerator`, not Deque or feature code. | High | Canonical ownership, isolated role, negative caller result | UID0000MQ placement | already-present | already-present |
| C16 | 0000AT | A real `PrimeNumberGenerator.h` is required for a reusable class declaration and source include. | High | Current class/formal state and missing generated header | UID0000AT formal H/CPP; UID0000MQ caveats | incorporate | applied |
| C17 | 0000MQ | Current generated output is incomplete: aggregate marker, two empty emitters, and no header. | High | Generated command `000000023186` and file coverage | UID0000MQ Generated Output Caveats | incorporate | applied |
| C18 | 0000AT | Class formal blocks should emit the header declaration and a CPP include/child scaffold. | High | Layout, methods, vtable identity, generated composition | UID0000AT formal blocks | incorporate | applied |
| C19 | 0001FA | Keep accessor CPP source, blank H block, and assign class-child CPP position `10`. | High | Existing exact formal source and binary address order | UID0001FA metadata/formal blocks | incorporate | applied |
| C20 | 0001FB | Replace the marker with constructor/destructor CPP source, blank H block, position `20`. | High | Complete constructor and destructor analysis | UID0001FB metadata/formal blocks | incorporate | applied |
| C21 | 0001VL | Layout is documentation-only and should be `RECONSTRUCTABLE:FALSE` with blank emitters. | High | Header fully represents source cause; current empty marker | UID0001VL metadata/formal blocks | incorporate | applied |
| C22 | 0001YG | Vtable type is documentation-only and should be `RECONSTRUCTABLE:FALSE` with blank emitters. | High | Virtual declaration represents source cause; current empty marker | UID0001YG metadata/formal blocks | incorporate | applied |
| C23 | 0002OK | Preserve the compiler-generated vtable marker and assign CPP position `30`; do not emit arrays. | High | Exact one-slot vtable evidence and existing formal marker | UID0002OK metadata/formal CPP | incorporate | applied |
| C24 | 0000MQ | Apply bounded post-callback score updates, led by target `94/93`, with no score at or above `95`. | Medium-high | Resolved source gaps plus remaining active-use/name limits | Target/support score blocks | incorporate | applied |
| C25 | 0000MQ | Rewrite target status, contents, evidence, caveats, placement, score, and changes around the complete source disposition. | High | Whole-file synthesis | UID0000MQ body | incorporate | applied |
| C26 | 0000AT | Synchronize class, aggregate, layout, vtable, and vtable-data support docs without changing unrelated Deque pages. | High | Direct dependency graph | Listed support pages | incorporate | applied |
| C27 | 0000MQ | Retire stale `Deque.cpp` and incomplete Prime source-tree text in the supervisor-owned structure page. | High | UID0000IR current NONE route and full source analysis | Proposed source tree exact replacements | reject-stale | applied |
| C28 | 0000MQ | Replace stale manual coverage rows with the exact callback scores/dispositions. | High | Current manual rows versus canonical docs | Supervisor-owned coverage text | reject-stale | proposed |
| C29A | 0001FA | At raw accessor `0x0054bcc0`, add only the exact address-repeatable behavior comment; preserve unmodeled code, absent name/type/function frame, bytes, and xrefs. | High | Current item/comment state, exact 44-byte hash, bounded zero inbound xrefs | Supervisor Gate 2B IDA handoff I01 | incorporate | proposed |
| C29B | 0001FB | Pure-rename modeled constructor `0x0054bcf0` to `PrimeNumberGenerator_Constructor` and add only the exact function-repeatable behavior comment; preserve prototype and complete frame. | High | Current function/type/comments/frame, collision-free name, exact main-body/chunk hashes and xrefs | Supervisor Gate 2B IDA handoff I02 | incorporate | proposed |
| C29C | 0001FB | At raw destructor clone `0x0054c070`, add only the exact address-repeatable compiler-consequence comment; preserve unmodeled code, absent name/type/function frame, bytes, and xrefs. | High | Current item/comment state, exact 44-byte hash, bounded zero inbound xrefs | Supervisor Gate 2B IDA handoff I03 | incorporate | proposed |
| C29D | 0001FB | At constructor cleanup chunk `0x0054c0a0`, add only the exact address-repeatable EH comment and preserve its parent-function membership, label, frame, bytes, and xrefs. | High | Current chunk/item/comments, parent frame, exact 28-byte hash and routes | Supervisor Gate 2B IDA handoff I04 | incorporate | proposed |
| C29E | 0001FC | At modeled helper `0x0054c0c0`, add only the exact function-repeatable compiler/STL comment; preserve name `sub_54C0C0`, the exact immediate pre-action prototype, frame, bytes, and xrefs; do not rename or set type. | High | Failed-closed pure-rename type drift, exact restored IDB hash, fresh function/type/comments/frame readback, exact 80-byte hash and sole raw caller | Supervisor Gate 2B IDA handoff I05 | incorporate | proposed |
| C29F | 0001FB | Pure-rename `0x0054c110` to `PrimeNumberGenerator_ScalarDeletingDestructor` and add only the exact function-repeatable compiler comment; preserve prototype and frame. | High | Current function/type/comments/frame, collision-free name, exact 74-byte hash and vtable xref | Supervisor Gate 2B IDA handoff I06 | incorporate | proposed |
| C29G | 0001FD | Pure-rename `0x0054c160` to `std_deque_int_clear_storage` and add only the exact function-repeatable compiler/STL comment; preserve prototype and frame. | High | Current function/type/comments/frame, collision-free name, exact 145-byte hash and six inbound calls | Supervisor Gate 2B IDA handoff I07 | incorporate | proposed |
| C29H | 0001FB | At unwind-dispatch tail `0x00606270`, add only the exact address-repeatable comment; preserve constructor chunk membership, label, frame, bytes, and xrefs. | High | Current chunk/item/comments, exact 11 bytes/hash and UnwindMap/cleanup routes | Supervisor Gate 2B IDA handoff I08 | incorporate | proposed |
| C29I | 0001FB | At SEH handler tail `0x0060627b`, add only the exact address-repeatable comment; preserve constructor chunk membership, label, frame, bytes, and xrefs. | High | Current chunk/item/comments, exact 27 bytes/hash and cookie/FuncInfo/handler routes | Supervisor Gate 2B IDA handoff I09 | incorporate | proposed |
| C29J | 0001FB | At UnwindMap item `0x0066392c`, add only the exact address-repeatable comment; preserve the eight-byte data item, name, absent type, bytes, and xrefs. | High | Current physical item/comments, exact bytes/hash and EH graph refs | Supervisor Gate 2B IDA handoff I10 | incorporate | proposed |
| C29K | 0001FB | At `FuncInfo` item `0x00663934`, add only the exact address-repeatable comment; preserve the 36-byte data item, name, absent type, bytes, and xrefs. | High | Current physical item/comments, exact bytes/hash and EH graph refs | Supervisor Gate 2B IDA handoff I11 | incorporate | proposed |
| C29L | 0002OK | At vtable-prefix cell `0x0062241c`, add only the exact address-repeatable comment; preserve the four-byte data item, absent name/type, bytes, and COL xref. | High | Current physical item/comments, exact dword/hash and outbound COL ref | Supervisor Gate 2B IDA handoff I12 | incorporate | proposed |
| C29M | 0002OK | At vtable slot `0x00622420`, add only the exact address-repeatable comment; preserve decorated name, four-byte item, absent type, bytes, and all four refs. | High | Current physical item/comments, exact dword/hash, three inbound stores and destructor target | Supervisor Gate 2B IDA handoff I13 | incorporate | proposed |
| C29N | 0001YG | At COL `0x0064e318`, add only the exact address-repeatable comment; preserve decorated name, physical dword topology, generic AR text, bytes, and RTTI graph xrefs. | High | Current physical items/comments, exact 20-byte hash and graph refs | Supervisor Gate 2B IDA handoff I14 | incorporate | proposed |
| C29O | 0001YG | At CHD `0x0064e32c`, add only the exact address-repeatable comment; preserve decorated name, four-dword topology, generic AR text, bytes, and RTTI graph xrefs. | High | Current physical items/comments, exact 16-byte hash and graph refs | Supervisor Gate 2B IDA handoff I15 | incorporate | proposed |
| C29P | 0001YG | At BCA `0x0064e33c`, add only the exact address-repeatable comment; preserve decorated name, pointer dword, undefined zero tail, generic AR text, bytes, and graph xrefs. | High | Current physical item/undefined-tail/comments, exact eight-byte hash and graph refs | Supervisor Gate 2B IDA handoff I16 | incorporate | proposed |
| C29Q | 0001YG | At BCD `0x0064e344`, add only the exact address-repeatable comment; preserve decorated name, seven-dword topology, generic AR text, bytes, and graph xrefs. | High | Current physical items/comments, exact 28-byte hash and graph refs | Supervisor Gate 2B IDA handoff I17 | incorporate | proposed |
| C29R | 0001YG | At TypeDescriptor `0x006788e8`, add only the exact address-repeatable comment; preserve decorated name, dword/string/pad topology, generic AR text, bytes, and graph xrefs. | High | Current physical items/comments, exact 36-byte hash and graph refs | Supervisor Gate 2B IDA handoff I18 | incorporate | proposed |
| C30 | 0000MQ | Callback validation must regenerate output and verify a header, zero empty emitters, child order, and score consistency. | High | Current generated defects and formal composition rules | Validator/follow-up actions | incorporate | proposed |
| C31 | 0000MQ | Tracker and generated snapshots are dated/dynamic and must be freshly read at each gate. | High | Workflow lifecycle ownership and current command timestamp | Supervisor recheck/tracker text | incorporate | proposed |
| C32 | 0000MQ | The absent historical `simroot_v2` source path is a lead, not active source truth. | High | Repository search and current canonical/generated state | UID0000MQ history/evidence | historicalize | applied |
| C33 | 0000MQ | Remaining unknowns are exact original names/toolset and active use; none blocks reconstruction. | Medium-high | Symbol absence, no-caller result, complete local behavior | Open questions/confidence | incorporate | applied |

## Positive Evidence Summary

- RTTI names the class exactly as `PrimeNumberGenerator` and links one vtable slot to the scalar deleting destructor.
- The object layout is coherent at `0x1c` bytes: vptr at `+0x00`, sieve pointer at `+0x04`, and old-MSVC `std::deque<int>` state at `+0x08..+0x18`.
- The accessor's complete instruction body is available and already has source that preserves signed-negative fallback and high-index clamping.
- The constructor decompiles coherently from vtable/member initialization through clamp, seed insertion, sieve allocation/zeroing, wheel loop, append, and release.
- Constants `100`, `10000000`, `2`, `3`, and modulus `6` are directly visible in the constructor logic.
- UID000149 independently resolves the first two push sites as `m_primes.push_back(2)` and `m_primes.push_back(3)` and later insertions as the same native deque operation.
- Destructor-family bodies consistently write the same vtable and tear down the same embedded deque.
- Exact alignment bytes and the next `PursuitMessageDialogPane` routine bound the file-owned code island.
- Generated routing already places all current emitters under `NexusTK/util/PrimeNumberGenerator.cpp`; the remaining work is content quality and header composition.

Together these facts support source reconstruction independently of active runtime use.

## IDA MCP Facts

The mandatory IDA MCP passes were read-only. The accepted research session was `supervisor-canonical-uid0002PR-retry2-20260813`; the repair re-attestation used dated restored session `supervisor-uid0000MQ-rollback-20260814`, backed by `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` at exact on-disk SHA256 `35A5E6AB17C9001F6C77ED25546094515C5312C736AE77085ECAE89A6767B506`. These are dated evidence, not permanent claims that either session remains active or canonical.

| Item | Current-session fact |
| --- | --- |
| Health | `ok`; module `NexusTK.exe`; image base `0x00400000`; Hex-Rays ready |
| Accessor | Raw function-shaped bytes `0x0054bcc0-0x0054bcec`; not currently modeled as a function |
| Constructor | `sub_54BCF0`, entry `0x0054bcf0`, modeled size `0x372`; multiple chunks include EH tails |
| Raw destructor clone | Function-shaped bytes `0x0054c070-0x0054c09c`; not currently modeled |
| Constructor cleanup | `0x0054c0a0-0x0054c0bc`, attached to constructor; inbound jump from `0x00606276` |
| Deque element helper | `sub_54C0C0`, `0x0054c0c0-0x0054c110`, size `0x50` |
| Scalar deleting destructor | `sub_54C110`, `0x0054c110-0x0054c15a`, size `0x4a` |
| Deque clear/storage helper | `sub_54C160`, `0x0054c160-0x0054c1f1`, size `0x91` |
| Vtable | Decorated `??_7PrimeNumberGenerator@@6B@` at `0x00622420` |
| RTTI | COL `0x0064e318`, CHD `0x0064e32c`, BCA `0x0064e33c`, BCD `0x0064e344`, TypeDescriptor `0x006788e8` |
| EH metadata | Unwind map and `FuncInfo` at `0x0066392c-0x00663958` |
| Prime UDT | No `PrimeNumberGenerator` UDT currently defined |
| Deque UDT | `DequeInt` exists with size `0x14` and fields at `+0x00,+0x04,+0x08,+0x0c,+0x10` |
| Existing comments | No regular/repeatable comments on the audited code entries; RTTI cells carry only generic auto-analysis comments |

Current repair-session constructor prototype is `char *__thiscall(char *this, int)`. Current helper prototypes are weak/generic: `unsigned int __thiscall(int ******this, int)` at `0x0054c0c0`, `void *__thiscall(void *Block, char)` at `0x0054c110`, and `void __thiscall(_DWORD *this)` at `0x0054c160`. The failed Gate 2B attempt's earlier pre-action I05 readback was literal `int __thiscall(int ******this, int)`; the bounded temporal discrepancy is protected by no rename/no type action and exact immediate pre/post equality rather than by forcing either rendering.

## Function / Child Inventory

| Item/range | IDA state | Source-level role | Canonical owner | Emission disposition | Destination |
| --- | --- | --- | --- | --- | --- |
| UID0000AT class declaration | Documentation/formal block | Reusable polymorphic utility type | UID0000AT | Header | `PrimeNumberGenerator.h` |
| `0x0054bc40-0x0054bcbd` | Modeled predecessor | `PrettyButton` destructor family | Other owner | Exclude | Predecessor docs |
| `0x0054bcbd-0x0054bcc0` | Raw `CC` bytes | Alignment after predecessor | Compiler | No code | Boundary note |
| UID0001FA `0x0054bcc0-0x0054bcec` | Raw function-shaped code | `GetPrimeAt(int) const` | UID0000AT | CPP body | Position 10 |
| `0x0054bcec-0x0054bcf0` | Raw `CC` bytes | Alignment | Compiler | No code | Boundary note |
| UID0001FB `0x0054bcf0-0x0054c062` | Modeled constructor | Complete sieve constructor | UID0000AT | CPP body | Position 20 |
| `0x0054c062-0x0054c070` | Raw `CC` bytes | Alignment | Compiler | No code | UID0001FB boundary note |
| `0x0054c070-0x0054c09c` | Raw function-shaped code | Destructor/cleanup clone | UID0000AT compiler consequence | Empty source destructor covers cause | UID0001FB analysis |
| `0x0054c09c-0x0054c0a0` | Raw `CC` bytes | Alignment | Compiler | No code | UID0001FB boundary note |
| `0x0054c0a0-0x0054c0bc` | Constructor chunk | EH cleanup for embedded deque | Compiler | No code | UID0001FB analysis |
| `0x0054c0bc-0x0054c0c0` | Raw `CC` bytes | Alignment | Compiler | No code | Boundary note |
| UID0001FC `0x0054c0c0-0x0054c110` | Modeled function | `std::deque<int>` element address | UID00003P/Deque support | Non-emitting | UID0001FC |
| UID0001FB child `0x0054c110-0x0054c15a` | Modeled function | Scalar deleting destructor | Compiler for UID0000AT | No hand-authored code | UID0001FB analysis |
| `0x0054c15a-0x0054c160` | Raw `CC` bytes | Alignment | Compiler | No code | Boundary note |
| UID0001FD `0x0054c160-0x0054c1f1` | Modeled function | Deque clear/storage teardown | UID00003P/Deque support | Non-emitting | UID0001FD |
| `0x0054c1f1-0x0054c200` | Raw `CC` bytes | Alignment before successor | Compiler | No code | Boundary note |
| `0x0054c200...` | Modeled successor | `PursuitMessageDialogPane` code | Other owner | Exclude | Successor docs |
| `0x00606270-0x0060627b` | Constructor tail chunk | Move `this+8`; jump to cleanup | Compiler | No code | UID0001FB EH note |
| `0x0060627b-0x00606296` | Constructor tail chunk | `__CxxFrameHandler3` path | Compiler | No code | UID0001FB EH note |
| `0x0066392c-0x00663958` | Data records | Unwind map and constructor `FuncInfo` | Compiler | No code | UID0001FB EH note |
| UID0002OK `0x0062241c-0x00622424` | Data cells | COL pointer and one deleting-destructor slot | UID0000AT compiler consequence | Comment marker only | Position 30 |
| `0x0064e318-0x0064e32c` | RTTI COL | Complete Object Locator | Compiler | No code | UID0001YG evidence |
| `0x0064e32c-0x0064e33c` | RTTI CHD | One-base hierarchy descriptor | Compiler | No code | UID0001YG evidence |
| `0x0064e33c-0x0064e344` | RTTI BCA cell/padding | Base-class array | Compiler | No code | UID0001YG evidence |
| `0x0064e344-0x0064e360` | RTTI BCD | Base-class descriptor | Compiler | No code | UID0001YG evidence |
| `0x006788e8-0x0067890c` | RTTI TypeDescriptor | `.?AVPrimeNumberGenerator@@` | Compiler | No code | UID0001YG evidence |
| UID0001VL layout | Type documentation | vptr, sieve pointer, embedded deque | UID0000AT | Non-emitting | Class/header evidence |
| UID0001YG vtable type | Type documentation | One virtual deleting-destructor slot | UID0000AT | Non-emitting | Class/header evidence |
| `m_sieveBits` | Object member at `+0x04` | Temporary constructor-owned bit words | UID0000AT | Header field | Private declaration |
| `m_primes` | Object member at `+0x08` | Native `std::deque<int>` | UID0000AT | Header field | Private declaration |
| `0x005a88e0` family | Shared called dependency | Native deque push-back implementation | Compiler/STL | Non-emitting | Deque evidence only |
| `0x0043e0b0` family | Shared called dependency | Native deque map growth | Compiler/STL | Non-emitting | Deque evidence only |
| Allocation/zero/free wrappers | Imported/runtime calls | `new[]`, `memset`, `delete[]` consequences | Runtime | Express as source operations | Constructor source |

No additional project-authored method, free function, global, static table, resource, or initialization routine belongs to this file on current evidence.

## Direct Xref / Caller Inventory

| Target | Exact inbound xrefs/callers | Exact outbound refs/callees | Interpretation |
| --- | --- | --- | --- |
| `0x0054bcc0-0x0054bcec` accessor | Bounded query to entry: zero inbound refs/callers | Body call `0x0054bce1 -> 0x0054c0c0`; entry has ordinary code-flow xref to `0x0054bcc1` | Retained/unreferenced in current IDB; not a source blocker |
| `0x0054bcf0-0x0054c062` constructor | Bounded function profile: zero callers | Eleven profiled dependencies: `0x005c74f6`, `0x0054c160`, `0x004a88e0`, `0x005c7790`, `0x005ca0b0`, self/EH association, `0x0043e0b0`, `0x005c7799`, `0x005c7526`, `0x005c772f`, `0x005c956c` | No active construction site proven; complete internal/source route remains coherent |
| `0x0054c070-0x0054c09c` raw destructor clone | Bounded query to entry: zero inbound refs/callers | Vtable store at `0x0054c074`; calls `0x0054c160` at `0x0054c07c` and `0x0054c083`; free wrapper call follows | Compiler-retained cleanup/destructor form |
| `0x0054c0a0-0x0054c0bc` local EH cleanup chunk | Code xref `0x00606276 -> 0x0054c0a0` | Calls `0x0054c0a3 -> 0x0054c160` and `0x0054c0ac -> 0x005c7526`; then zeros deque proxy | Constructor-owned cleanup, not a separate source method |
| `0x0054c0c0-0x0054c110` deque element helper | One code xref `0x0054bce1 -> 0x0054c0c0`; modeled caller count is zero because the accessor is unmodeled | No external callee; function-profile self entry is an analysis artifact | Accessor's compiled `m_primes[index]` support |
| `0x0054c110-0x0054c15a` deleting destructor | One data xref `0x00622420 -> 0x0054c110` | Vtable store `0x0054c11a -> 0x00622420`; calls `0x0054c160` at `0x0054c120`/`0x0054c128` and delete wrapper `0x005c7526` | Compiler virtual deletion entry |
| `0x0054c160-0x0054c1f1` deque clear/storage helper | Six code xrefs: `0x0054bd8a`, `0x0054c07c`, `0x0054c083`, `0x0054c0a3`, `0x0054c120`, `0x0054c128` | Calls free wrapper `0x005c7526`; invalid-parameter branch reaches `0x005cd607` | Explicit constructor clear plus compiler cleanup/destructor paths |
| `0x00606270-0x0060627b` unwind-dispatch tail chunk | Data xref `0x00663930 -> 0x00606270`; no code caller enters its head | Final instruction `0x00606276 -> 0x0054c0a0` | One independent constructor tail chunk with exact EH ownership |
| `0x0060627b-0x00606296` SEH-handler tail chunk | Data ref `0x0054bcf5 -> 0x0060627b`; no ordinary code caller | `0x00606287 -> 0x005c772f`; `0x0060628c -> 0x00663934`; `0x00606291 -> 0x005c956c` | Cookie-check/`FuncInfo`/frame-handler tail, not source code |
| `0x0066392c-0x00663934` UnwindMap item | Inbound data xref `0x0066393c -> 0x0066392c` | Outbound data xref `0x00663930 -> 0x00606270`; IDA also reports one out-of-image auto-analysis pseudo-target `0xff000000000081b3` | Exact one-entry constructor unwind map; pseudo-target supplies no ownership |
| `0x00663934-0x00663958` `FuncInfo` item | Inbound data xref `0x0060628c -> 0x00663934` | Outbound data xref `0x0066393c -> 0x0066392c`; IDA also reports one out-of-image auto-analysis pseudo-target `0xff000000000081a8` | Exact constructor `FuncInfo`; pseudo-target supplies no ownership |
| Vtable-prefix cell `0x0062241c-0x00622420` | Bounded query: zero inbound xrefs | Data pointer `0x0062241c -> 0x0064e318` | Complete-object-locator prefix immediately before the one-slot table |
| Vtable slot `0x00622420-0x00622424` | Stores/refs `0x0054bd20`, `0x0054c074`, `0x0054c11a` -> `0x00622420` | Data pointer `0x00622420 -> 0x0054c110` | Constructor/destructor family and deleting slot agree on class identity |
| COL `0x0064e318-0x0064e32c` | Inbound data xref `0x0062241c -> 0x0064e318` | Interior fields `0x0064e324 -> 0x006788e8` and `0x0064e328 -> 0x0064e32c` | Exact compiler RTTI root for this vtable |
| CHD `0x0064e32c-0x0064e33c` | Inbound data xrefs `0x0064e328` and `0x0064e35c` -> `0x0064e32c` | Interior field `0x0064e338 -> 0x0064e33c` | One-base class hierarchy descriptor |
| BCA `0x0064e33c-0x0064e344` | Inbound data xref `0x0064e338 -> 0x0064e33c` | Pointer `0x0064e33c -> 0x0064e344`; trailing `0x0064e340-0x0064e344` has bounded zero xrefs | One base descriptor pointer plus protected undefined zero padding |
| BCD `0x0064e344-0x0064e360` | Inbound data xref `0x0064e33c -> 0x0064e344` | Head pointer `0x0064e344 -> 0x006788e8`; interior field `0x0064e35c -> 0x0064e32c` | Base-class descriptor closes the CHD/TypeDescriptor graph |
| TypeDescriptor `0x006788e8-0x0067890c` | Inbound data xrefs `0x0064e324` and `0x0064e344` -> `0x006788e8` | Head pointer `0x006788e8 -> 0x00635078`; class-name bytes have no independent caller/xref | Exact `.?AVPrimeNumberGenerator@@` compiler descriptor |

Negative results are bounded to the current IDB and current analysis state. They do not prove that no historical source consumer existed, only that no direct active route is represented by present xrefs.

## Documentation Evidence And IDA Status

The canonical documentation and IDA agree on the material facts: isolated utility ownership, polymorphic `0x1c`-byte class, temporary sieve pointer, embedded deque, exact accessor semantics, clamped sieve constructor, one-slot vtable, and current lack of direct construction/accessor callers.

The important documentation corrections are representation quality rather than a reversal of ownership:

- Current docs call UID0001FB an aggregate marker because the range mixes custom code and compiler support. That range mixing is real, but it does not require marker-only source; a broad range can emit the two source methods that explain its custom and compiler-expanded bodies.
- Current layout/vtable pages carry reconstructable true while their formal source blocks are blank. Their source causes belong in the class header, so independent emission is invalid duplication.
- UID0001FC/UID0001FD are already correctly classified as non-reconstructable/non-emitting Deque support and should remain so.
- UID0002OK already has the correct comment-only generated-binary marker and exact data-boundary evidence.
- The absent historical `simroot_v2` file should be described as historical, not as current recovered source.

IDA status is adequate for research but can be improved by a separate authorized mutation pass. No mutation is necessary to accept the source conclusion.

## Ranked Ownership Analysis

| Rank | Candidate owner | Assessment |
| ---: | --- | --- |
| 1 | UID0000MQ file route plus UID0000AT class | Direct canonical relationship, exact RTTI identity, self-contained algorithm, existing generated route; accept |
| 2 | Generic `util/` module without class ownership | Correct directory but loses the class-centered declaration/child structure; reject as incomplete |
| 3 | UID0000IR/Deque or a standalone `Deque.cpp` | Helpers are compiler/STL support and Deque page explicitly resolves to `NONE`; reject stale |
| 4 | A feature-local gameplay/UI module | No direct callers, feature strings, resources, or feature-specific state; reject unsupported |
| 5 | No-owner/non-reconstructable bucket | Complete local behavior and coherent source declaration contradict this; reject invalid |

The canonical ownership should remain file UID0000MQ -> class UID0000AT -> source-bearing memory children. Compiler/STL artifacts may retain documentation owners but must not become emitted project dependencies.

## Source Placement

Place the class at:

- `NexusTK/util/PrimeNumberGenerator.h`
- `NexusTK/util/PrimeNumberGenerator.cpp`

The header is not optional. A class with a virtual destructor, public constructor/accessor, and private native container state is a reusable type definition, and current class metadata already serves both CPP and H roles. Keeping the declaration inside only the `.cpp` causes the generated header gap and weakens downstream compilability.

Recommended child order follows source/binary order and is stable:

| Position | UID | CPP contribution |
| ---: | --- | --- |
| 10 | 0001FA | `GetPrimeAt(int) const` |
| 20 | 0001FB | Constructor and empty virtual destructor |
| 30 | 0002OK | Comment-only compiler-generated vtable marker |

UID0001VL and UID0001YG remain documentary children of the class, but they should have no CPP/H emitter. UID0001FC and UID0001FD remain documentary Deque/STL children and do not create `Deque.cpp`.

## Range / Split / Padding / Reclassification Analysis

The current broad UID0001FB range `0x0054bcf0-0x0054c15a` intentionally spans source methods, alignment, an EH cleanup, a generic deque helper, and a deleting destructor. It should remain a documentation aggregate, but its formal CPP can represent the constructor and destructor source causes. No new address UID is required merely to write first-draft source.

Exact local partition:

| Range | Length | Classification |
| --- | ---: | --- |
| `0x0054bcbd-0x0054bcc0` | `0x3` | `CC` alignment after predecessor |
| `0x0054bcc0-0x0054bcec` | `0x2c` | Raw accessor source method |
| `0x0054bcec-0x0054bcf0` | `0x4` | `CC` alignment |
| `0x0054bcf0-0x0054c062` | `0x372` | Modeled constructor, including detached chunks in IDA's size accounting |
| `0x0054c062-0x0054c070` | `0xe` | `CC` alignment |
| `0x0054c070-0x0054c09c` | `0x2c` | Raw destructor/cleanup clone |
| `0x0054c09c-0x0054c0a0` | `0x4` | `CC` alignment |
| `0x0054c0a0-0x0054c0bc` | `0x1c` | Constructor EH cleanup chunk |
| `0x0054c0bc-0x0054c0c0` | `0x4` | `CC` alignment |
| `0x0054c0c0-0x0054c110` | `0x50` | Generic deque element-address helper |
| `0x0054c110-0x0054c15a` | `0x4a` | Scalar deleting destructor |
| `0x0054c15a-0x0054c160` | `0x6` | `CC` alignment |
| `0x0054c160-0x0054c1f1` | `0x91` | Generic deque clear/storage teardown |
| `0x0054c1f1-0x0054c200` | `0xf` | `CC` alignment before successor |

Reclassification recommendations:

- UID0001VL: reconstructable true -> false; clear emitter UID/positions; preserve owner UID0000AT and layout evidence.
- UID0001YG: reconstructable true -> false; clear emitter UID/positions; preserve owner UID0000AT and vtable evidence.
- UID0001FB: keep reconstructable true and owner/emitter UID0000AT; replace marker source rather than splitting solely for emission.
- UID0002OK: keep reconstructable true only because it intentionally emits a compiler-generated marker through the class; it must not emit actual vtable data definitions.
- UID0001FC/UID0001FD: preserve false/blank emitter state.

## Negative Evidence Summary

The following were not found in the bounded research surface:

- No direct accessor caller, constructor caller, or raw-destructor caller in the current IDB.
- No additional PrimeNumberGenerator method body after `0x0054c1f1` or before `0x0054bcc0`.
- No file-owned global/static prime table, registration record, singleton, factory, or initializer.
- No Prime-specific string literal, resource, import, UI route, network route, or gameplay owner.
- No source remnant at the currently documented `source-3/simroot_v2/class_PrimeNumberGenerator.cpp` path.
- No standalone `PrimeNumberGenerator.h` in current generated output.
- No project-authored Deque API requirement; helper bodies match compiler/STL support.
- No evidence that the scalar deleting destructor, RTTI graph, EH tables, or alignment were hand-authored.
- No evidence for nulling `m_sieveBits` after deletion or guarding an empty deque in the accessor.
- No evidence that a final candidate of form `6k-1` was handled outside the observed paired loop.

These negatives cap active-use and exact-original-source confidence. They do not justify a no-owner or non-reconstructable disposition.

## IDA Rename / Type / Comment Recommendations

This is a non-executable, item-by-item supervisor Gate 2B handoff. `AR` means address-regular, `AP` address-repeatable, `FR` function-regular, and `FP` function-repeatable. `absent` is the literal empty-string MCP readback. `N/A` means that channel cannot exist because the item is not a function entry. I01-I04/I06-I18 preserve the previously accepted healthy read-only prestate. I05 is updated from the restored exact-hash repair session and the failed-closed readback chronology described above.

The deterministic declaration strategy is final: do not declare a `PrimeNumberGenerator` UDT, do not define either raw stream as a function, and do not call `set_type` anywhere in this report. Current type search proves `PrimeNumberGenerator` absent; `DequeInt` alone exists at exact size `0x14` with five fields, which is insufficient to type the enclosing polymorphic object without creating new class state. The safe complete action is therefore pure function rename plus one FP comment on three already-modeled functions I02/I06/I07, FP comment-only classification on unchanged I05, and AP comment-only classification on unmodeled code/chunks/data. This is a resolved no-type/no-define disposition, not deferred investigation.

**Exact current item, channel, byte, and route prestate**

| ID | Exact current kind/head/logical range/physical width | Exact current name and type | Literal current channels | Exact bytes/hash | Material xrefs |
| --- | --- | --- | --- | --- | --- |
| I01 | Unmodeled instruction stream `[0x0054bcc0,0x0054bcec)`; physical head `[0x0054bcc0,0x0054bcc1)`, width `1`, code | name absent; type absent; no function/frame | AR absent; AP absent; FR N/A; FP N/A | 44 bytes; SHA256 `6F3714872A01A6EF0CFFF80BD2875B82FEF33FD01ACC0372C76B4FCAA2AD9CC6`; first `55 8B EC 8B 45 08 85 C0 79 09 B8 02 00 00 00 5D`; last `03 8D 42 FF 50 E8 DA 03 00 00 8B 00 5D C2 04 00` | zero inbound; body call `0x0054bce1 -> 0x0054c0c0` |
| I02 | Modeled function entry head `[0x0054bcf0,0x0054bcf1)`, width `1`, code; main `[0x0054bcf0,0x0054c062)`, IDA size `0x372`; chunks I04/I08/I09 | `sub_54BCF0`; `char *__thiscall(char *this, int)` | AR absent; AP absent; FR absent; FP absent | Main 882 bytes; SHA256 `6A8FD49127201530CF146CF4D50D09D10E16150BA9C9E229A0329C4A88EDB883`; first `55 8B EC 6A FF 68 7B 62 60 00 64 A1 00 00 00 00`; last `89 0D 00 00 00 00 59 5F 5E 5B 8B E5 5D C2 04 00` | zero callers; exact eleven-dependency profile retained |
| I03 | Unmodeled instruction stream `[0x0054c070,0x0054c09c)`; physical head `[0x0054c070,0x0054c071)`, width `1`, code | name absent; type absent; no function/frame | AR absent; AP absent; FR N/A; FP N/A | 44 bytes; SHA256 `7EBD45FC0E439F39B65F01FA815ED8993AA9754F695E471520D13D28D7B5D3FB`; first `56 8D 71 08 C7 01 20 24 62 00 8B CE E8 DF 00 00`; last `E8 95 B4 07 00 83 C4 08 C7 06 00 00 00 00 5E C3` | zero inbound; vtable store and two `0x0054c160` calls retained |
| I04 | Constructor CFG chunk `[0x0054c0a0,0x0054c0bc)`; physical head `[0x0054c0a0,0x0054c0a1)`, width `1`, code | `loc_54C0A0`; type absent; containing function I02 | AR absent; AP absent; FR N/A at chunk head; FP N/A at chunk head | Exact `56 8B F1 E8 B8 00 00 00 6A 08 FF 36 E8 75 B4 07 00 83 C4 08 C7 06 00 00 00 00 5E C3`; SHA256 `638A2E31B5819477B3FE295F0EE43172D3B450546EEF50807A85356C2D42642A` | inbound `0x00606276`; outbound `0x0054c160`, `0x005c7526` |
| I05 | Modeled function entry head `[0x0054c0c0,0x0054c0c1)`, width `1`, code; function `[0x0054c0c0,0x0054c110)`, size `0x50` | `sub_54C0C0`; fresh live `unsigned int __thiscall(int ******this, int)`; failed-attempt pre-action rendering was `int __thiscall(int ******this, int)` | AR absent; AP absent; FR absent; FP absent | 80 bytes; SHA256 `0BCE4F6509AB8F3B0565FC3D4C7FF788D819AB45F3278B42A734185DDF9475E0`; first `55 8B EC 8B 01 8B 51 0C 33 C9 85 C0 74 08 8B 00`; last `42 04 83 E6 03 8B 04 88 8D 04 B0 5E 5D C2 04 00` | inbound `0x0054bce1`; no external callee |
| I06 | Modeled function entry head `[0x0054c110,0x0054c111)`, width `1`, code; function `[0x0054c110,0x0054c15a)`, size `0x4a` | `sub_54C110`; `void *__thiscall(void *Block, char)` | AR absent; AP absent; FR absent; FP absent | 74 bytes; SHA256 `7D8DFC13EB521D82E138CF9D8C30B4DC8C012F2FE70DDB19517C4886E8464958`; first `55 8B EC 56 57 8B F9 8D 4F 08 C7 07 20 24 62 00`; last `E8 D7 B3 07 00 83 C4 08 8B C7 5F 5E 5D C2 04 00` | inbound vtable `0x00622420`; outbound vtable store, two I07 calls, delete wrapper |
| I07 | Modeled function entry head `[0x0054c160,0x0054c161)`, width `1`, code; function `[0x0054c160,0x0054c1f1)`, size `0x91` | `sub_54C160`; `void __thiscall(_DWORD *this)` | AR absent; AP absent; FR absent; FP absent | 145 bytes; SHA256 `2E5321AE6F31F6D1D95D01584D5B9ADB69425B1450C7DDF0B90141F85F4D5ABD`; first `56 8B F1 8B 46 10 85 C0 74 19 66 0F 1F 44 00 00`; last `00 00 C7 46 04 00 00 00 00 5E C3 E8 16 14 08 00` | inbound `0x0054bd8a`, `0x0054c07c`, `0x0054c083`, `0x0054c0a3`, `0x0054c120`, `0x0054c128`; outbound free/invalid-parameter paths |
| I08 | Constructor CFG tail chunk `[0x00606270,0x0060627b)`; physical head `[0x00606270,0x00606273)`, width `3`, code | `loc_606270`; type absent; containing function I02 | AR absent; AP absent; FR N/A at chunk head; FP N/A at chunk head | Exact `8B 4D F0 83 C1 08 E9 25 5E F4 FF`; SHA256 `4538E04758C263685A60CCCAEE59109360BF4AAAF10C7F20C7394C6979EE8A02` | inbound `0x00663930`; outbound `0x00606276 -> 0x0054c0a0` |
| I09 | Constructor CFG tail chunk `[0x0060627b,0x00606296)`; physical head `[0x0060627b,0x0060627f)`, width `4`, code | `SEH_54BCF0`; type absent; containing function I02 | AR absent; AP absent; FR N/A at chunk head; FP N/A at chunk head | Exact `8B 54 24 08 8D 42 0C 8B 4A D0 33 C8 E8 A3 14 FC FF B8 34 39 66 00 E9 D6 32 FC FF`; SHA256 `1D378520A5E340C55918FB4578F40AB131EE7CEB7FE503EC13AB013304C6F5E1` | inbound `0x0054bcf5`; outbound `0x005c772f`, `0x00663934`, `0x005c956c` |
| I10 | Data item `[0x0066392c,0x00663934)`, head `0x0066392c`, width `8` | `stru_66392C`; type absent | AR absent; AP absent; FR N/A; FP N/A | Exact `FF FF FF FF 70 62 60 00`; SHA256 `0CB59ACA1700A260A51EF1085A74808FDB23F287C8C99AFAF8C879F75E164F67` | inbound `0x0066393c`; outbound `0x00606270` plus recorded out-of-image pseudo-target |
| I11 | Data item `[0x00663934,0x00663958)`, head `0x00663934`, width `36` | `stru_663934`; type absent | AR absent; AP absent; FR N/A; FP N/A | Exact `22 05 93 19 01 00 00 00 2C 39 66 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00`; SHA256 `5DDBDB84FE0B02D372CD0497D0F7E459CB35E7323EB7D3613A52D1FC11F98DBE` | inbound `0x0060628c`; outbound `0x0066392c` plus recorded out-of-image pseudo-target |
| I12 | Data item `[0x0062241c,0x00622420)`, head `0x0062241c`, width `4` | name absent; type absent | AR absent; AP absent; FR N/A; FP N/A | Exact `18 E3 64 00`; SHA256 `46301757AC96AC5EADAEC13111751F22587E4EBE48A0405EF9088E146E37216F` | zero inbound; outbound `0x0064e318` |
| I13 | Data item `[0x00622420,0x00622424)`, head `0x00622420`, width `4` | `??_7PrimeNumberGenerator@@6B@`; type absent | AR absent; AP absent; FR N/A; FP N/A | Exact `10 C1 54 00`; SHA256 `80AABAD462EAF4C3FF3FBF46EEAB7E2410D4D71259A89F80F8435A6D22E92572` | inbound stores `0x0054bd20`, `0x0054c074`, `0x0054c11a`; outbound `0x0054c110` |
| I14 | COL logical `[0x0064e318,0x0064e32c)`; five physical data dwords, each width `4`, head `0x0064e318` | `??_R4PrimeNumberGenerator@@6B@`; type absent | AR exact `signature`; AP absent; FR N/A; FP N/A | Exact `00 00 00 00 00 00 00 00 00 00 00 00 E8 88 67 00 2C E3 64 00`; SHA256 `4E82F79CFD48DA3883D8E9F46C05689756EF5DD3CAF346C6CAC97496830684D5` | inbound `0x0062241c`; outbound fields `0x006788e8`, `0x0064e32c` |
| I15 | CHD logical `[0x0064e32c,0x0064e33c)`; four physical data dwords, each width `4`, head `0x0064e32c` | `??_R3PrimeNumberGenerator@@8`; type absent | AR exact `signature`; AP absent; FR N/A; FP N/A | Exact `00 00 00 00 00 00 00 00 01 00 00 00 3C E3 64 00`; SHA256 `74C098F11063BBFC7B0DE37E97290C7ABA86D1438E6A22B62D4A22EE3D7A02D4` | inbound `0x0064e328`, `0x0064e35c`; outbound field `0x0064e33c` |
| I16 | BCA logical `[0x0064e33c,0x0064e344)`; data dword `[0x0064e33c,0x0064e340)` plus undefined width-4 zero tail | `??_R2PrimeNumberGenerator@@8` on head; type absent | AR exact `reference to base class decription 1`; AP absent; FR N/A; FP N/A | Exact `44 E3 64 00 00 00 00 00`; SHA256 `7A2965862ECED0E441090FD6EA2BE37ABA29F32AFA9F281844316AC8A76FFC46` | inbound `0x0064e338`; outbound `0x0064e344`; tail has zero xrefs |
| I17 | BCD logical `[0x0064e344,0x0064e360)`; seven physical data dwords, each width `4`, head `0x0064e344` | `??_R1A@?0A@EA@PrimeNumberGenerator@@8`; type absent | AR exact `reference to type description`; AP absent; FR N/A; FP N/A | Exact `E8 88 67 00 00 00 00 00 00 00 00 00 FF FF FF FF 00 00 00 00 40 00 00 00 2C E3 64 00`; SHA256 `45FF97B873DF29802C7519A8CDF0DD0C39E19FCFCE150DE93D5320F3B868E052` | inbound `0x0064e33c`; outbound `0x006788e8`, `0x0064e32c` |
| I18 | TypeDescriptor logical `[0x006788e8,0x0067890c)`; two data dwords, 27-byte string item at `0x006788f0`, one undefined pad byte | `??_R0?AVPrimeNumberGenerator@@@8`; head type absent; string name `aAvprimenumberg` | AR exact `reference to RTTI's vftable`; AP absent; FR N/A; FP N/A | Exact `78 50 63 00 00 00 00 00 2E 3F 41 56 50 72 69 6D 65 4E 75 6D 62 65 72 47 65 6E 65 72 61 74 6F 72 40 40 00 00`; SHA256 `CC647DF2969BCFE1E9A86EA3268FBE2B46A7FD5BDBF1F3F8254230DD76B4485D` | inbound `0x0064e324`, `0x0064e344`; outbound `0x00635078` |

**Exact deterministic actions and expected readback**

For I02/I06/I07, the schema-valid rename is a collision query followed by `rename` dry-run and actual with `batch.func` containing only that row's address/name, `pure:true`, `allow_overwrite:false`, `stop_on_error:true`, and `dry_run:true` then `dry_run:false`. After each pure rename succeeds, `set_repeatable_comments` sets only FP. I05 performs no collision query and no rename; its only mutation is schema-valid `set_repeatable_comments` with `items` containing only address `0x0054c0c0` and the exact FP text below. Every other item uses `set_address_repeatable_comments` to set only AP. No row calls `define_func`, `set_type`, any local/stack rename, any data rename, or any regular-comment endpoint.

| ID | Exact action/order | Exact expected readback and protected state |
| --- | --- | --- |
| I01 | Set AP exactly to `Raw PrimeNumberGenerator::GetPrimeAt(int) const body; negative indexes return 2 and high indexes clamp to the last std::deque<int> element.` | AP equals text; AR remains absent; no function/name/type/frame appears; item stream, 44-byte hash, zero inbound and helper call remain exact. |
| I02 | Collision count for `PrimeNumberGenerator_Constructor` must be zero; pure rename dry-run/apply; then set FP exactly to `PrimeNumberGenerator constructor; clamps the limit to 100..10000000, seeds 2 and 3, runs the paired 6k sieve, and frees the temporary bitfield.` | Name exact; prototype remains `char *__thiscall(char *this, int)`; FP exact; AR/AP/FR absent; all main/chunk bytes, 35 CFG blocks, zero callers, eleven dependencies, and every I02 frame tuple exact. |
| I03 | Set AP exactly to `Raw PrimeNumberGenerator destructor/cleanup body generated from the empty virtual destructor and embedded std::deque<int>.` | AP exact; AR absent; no function/name/type/frame appears; 44-byte hash, zero inbound, stores/calls remain exact. |
| I04 | Set AP exactly to `PrimeNumberGenerator constructor EH cleanup for m_primes at this+0x08.` | AP exact; AR absent; label `loc_54C0A0`, parent I02 membership, bytes, xrefs, and every I04 parent-frame tuple exact. |
| I05 | Require name `sub_54C0C0`, empty AR/AP/FR/FP, exact item/range/bytes/hash/xref/frame prestate, and record the literal immediate pre-action type string. It must be one of the two bounded attested renderings: `int __thiscall(int ******this, int)` or fresh live `unsigned int __thiscall(int ******this, int)`; any other string is a hard stop. Call only `set_repeatable_comments` with address `0x0054c0c0` and FP exactly `Compiler/STL std::deque<int> element-address support used by PrimeNumberGenerator::GetPrimeAt; non-emitting.`; then immediately perform complete readback. Never query the retired target name, call `rename`, or call `set_type` for I05. | Name remains `sub_54C0C0`; FP equals exact text; the post-action prototype equals the recorded immediate pre-action string byte-for-byte; AR/AP/FR remain absent; bytes, sole raw inbound, and every I05 frame tuple remain exact. Any mismatch fails Gate 2B, forbids save, and requires supervisor rollback from the verified backup rather than compensating in place. |
| I06 | Collision count for `PrimeNumberGenerator_ScalarDeletingDestructor` must be zero; pure rename dry-run/apply; set FP exactly to `Compiler-generated PrimeNumberGenerator scalar deleting destructor; source cause is virtual ~PrimeNumberGenerator().` | Name and FP exact; prototype remains `void *__thiscall(void *Block, char)`; AR/AP/FR absent; bytes, vtable/callee refs, and every I06 frame tuple exact. |
| I07 | Collision count for `std_deque_int_clear_storage` must be zero; pure rename dry-run/apply; set FP exactly to `Compiler/STL std::deque<int> clear and storage teardown support; non-emitting.` | Name and FP exact; prototype remains `void __thiscall(_DWORD *this)`; AR/AP/FR absent; bytes, six inbound refs, outbound dependencies, and the I07 frame tuple exact. |
| I08 | Set AP exactly to `PrimeNumberGenerator constructor unwind dispatch; adjusts this to m_primes and jumps to 0x0054c0a0.` | AP exact; AR absent; `loc_606270`, I02 membership, bytes, xrefs, and every I08 parent-frame tuple exact. |
| I09 | Set AP exactly to `PrimeNumberGenerator constructor SEH handler; checks the cookie, loads FuncInfo 0x00663934, and jumps to __CxxFrameHandler3.` | AP exact; AR absent; `SEH_54BCF0`, I02 membership, bytes, xrefs, and every I09 parent-frame tuple exact. |
| I10 | Set AP exactly to `MSVC UnwindMapEntry for PrimeNumberGenerator constructor: state -1, cleanup target 0x00606270.` | AP exact; AR absent; name/type/item range/width, exact bytes/hash, meaningful refs and recorded pseudo-ref unchanged. |
| I11 | Set AP exactly to `MSVC FuncInfo for PrimeNumberGenerator constructor; magic 0x19930522, one unwind state, UnwindMap 0x0066392c.` | AP exact; AR absent; name/type/item range/width, exact bytes/hash, meaningful refs and recorded pseudo-ref unchanged. |
| I12 | Set AP exactly to `PrimeNumberGenerator complete-object-locator pointer; one-slot vtable begins at 0x00622420.` | AP exact; AR absent; absent name/type, exact dword/hash, zero inbound and COL outbound unchanged. |
| I13 | Set AP exactly to `PrimeNumberGenerator one-slot vtable; entry points to scalar deleting destructor 0x0054c110.` | AP exact; AR absent; decorated name/type/item, exact dword/hash, three inbound stores and destructor target unchanged. |
| I14 | Set AP exactly to `PrimeNumberGenerator RTTI CompleteObjectLocator; TypeDescriptor 0x006788e8, ClassHierarchyDescriptor 0x0064e32c.` | AP exact; AR remains exact `signature`; decorated name, five-dword topology, bytes/hash and graph refs unchanged. |
| I15 | Set AP exactly to `PrimeNumberGenerator RTTI ClassHierarchyDescriptor; one base descriptor via 0x0064e33c.` | AP exact; AR remains exact `signature`; decorated name, four-dword topology, bytes/hash and graph refs unchanged. |
| I16 | Set AP exactly to `PrimeNumberGenerator RTTI BaseClassArray; first entry 0x0064e344, trailing dword remains undefined zero padding.` | AP exact; AR typo text remains byte-for-byte; decorated name, one dword plus undefined tail, bytes/hash and refs unchanged. |
| I17 | Set AP exactly to `PrimeNumberGenerator RTTI BaseClassDescriptor; TypeDescriptor 0x006788e8, PMD {0,-1,0}, attributes 0x40, CHD 0x0064e32c.` | AP exact; AR remains exact `reference to type description`; decorated name, seven-dword topology, bytes/hash and refs unchanged. |
| I18 | Set AP exactly to `PrimeNumberGenerator RTTI TypeDescriptor for .?AVPrimeNumberGenerator@@.` | AP exact; AR remains exact `reference to RTTI's vftable`; decorated/string names, dword/string/pad topology, bytes/hash and refs unchanged. |

**Complete current and expected frame rows**

No type or stack/local rename is authorized, so every expected tuple is byte-for-byte identical to the current tuple. I04, I08, and I09 are chunks of I02 and MCP returns the same parent frame for each; each entity is nevertheless enumerated independently.

| Entity | Current row: name / offset / size / type | Expected row after action | Permitted delta |
| --- | --- | --- | --- |
| I02 | `var_2C / 0x10 / 0x4 / _DWORD` | `var_2C / 0x10 / 0x4 / _DWORD` | none |
| I02 | `var_28 / 0x14 / 0x4 / _DWORD` | `var_28 / 0x14 / 0x4 / _DWORD` | none |
| I02 | `var_24 / 0x18 / 0x4 / _DWORD` | `var_24 / 0x18 / 0x4 / _DWORD` | none |
| I02 | `var_20 / 0x1c / 0x4 / _DWORD` | `var_20 / 0x1c / 0x4 / _DWORD` | none |
| I02 | `var_1C / 0x20 / 0x4 / _DWORD` | `var_1C / 0x20 / 0x4 / _DWORD` | none |
| I02 | `var_18 / 0x24 / 0x4 / _DWORD` | `var_18 / 0x24 / 0x4 / _DWORD` | none |
| I02 | `var_14 / 0x28 / 0x4 / _DWORD` | `var_14 / 0x28 / 0x4 / _DWORD` | none |
| I02 | `var_10 / 0x2c / 0x4 / _DWORD` | `var_10 / 0x2c / 0x4 / _DWORD` | none |
| I02 | `var_C / 0x30 / 0x4 / _DWORD` | `var_C / 0x30 / 0x4 / _DWORD` | none |
| I02 | `var_4 / 0x38 / 0x4 / _DWORD` | `var_4 / 0x38 / 0x4 / _DWORD` | none |
| I02 | `__saved_registers / 0x3c / 0x4 / _DWORD` | `__saved_registers / 0x3c / 0x4 / _DWORD` | none |
| I02 | `__return_address / 0x40 / 0x4 / _UNKNOWN *` | `__return_address / 0x40 / 0x4 / _UNKNOWN *` | none |
| I02 | `value / 0x44 / 0x4 / int` | `value / 0x44 / 0x4 / int` | none |
| I02 | `arg_4 / 0x48 / 0x4 / _DWORD` | `arg_4 / 0x48 / 0x4 / _DWORD` | none |
| I04 | `var_2C / 0x10 / 0x4 / _DWORD` | `var_2C / 0x10 / 0x4 / _DWORD` | none |
| I04 | `var_28 / 0x14 / 0x4 / _DWORD` | `var_28 / 0x14 / 0x4 / _DWORD` | none |
| I04 | `var_24 / 0x18 / 0x4 / _DWORD` | `var_24 / 0x18 / 0x4 / _DWORD` | none |
| I04 | `var_20 / 0x1c / 0x4 / _DWORD` | `var_20 / 0x1c / 0x4 / _DWORD` | none |
| I04 | `var_1C / 0x20 / 0x4 / _DWORD` | `var_1C / 0x20 / 0x4 / _DWORD` | none |
| I04 | `var_18 / 0x24 / 0x4 / _DWORD` | `var_18 / 0x24 / 0x4 / _DWORD` | none |
| I04 | `var_14 / 0x28 / 0x4 / _DWORD` | `var_14 / 0x28 / 0x4 / _DWORD` | none |
| I04 | `var_10 / 0x2c / 0x4 / _DWORD` | `var_10 / 0x2c / 0x4 / _DWORD` | none |
| I04 | `var_C / 0x30 / 0x4 / _DWORD` | `var_C / 0x30 / 0x4 / _DWORD` | none |
| I04 | `var_4 / 0x38 / 0x4 / _DWORD` | `var_4 / 0x38 / 0x4 / _DWORD` | none |
| I04 | `__saved_registers / 0x3c / 0x4 / _DWORD` | `__saved_registers / 0x3c / 0x4 / _DWORD` | none |
| I04 | `__return_address / 0x40 / 0x4 / _UNKNOWN *` | `__return_address / 0x40 / 0x4 / _UNKNOWN *` | none |
| I04 | `value / 0x44 / 0x4 / int` | `value / 0x44 / 0x4 / int` | none |
| I04 | `arg_4 / 0x48 / 0x4 / _DWORD` | `arg_4 / 0x48 / 0x4 / _DWORD` | none |
| I08 | `var_2C / 0x10 / 0x4 / _DWORD` | `var_2C / 0x10 / 0x4 / _DWORD` | none |
| I08 | `var_28 / 0x14 / 0x4 / _DWORD` | `var_28 / 0x14 / 0x4 / _DWORD` | none |
| I08 | `var_24 / 0x18 / 0x4 / _DWORD` | `var_24 / 0x18 / 0x4 / _DWORD` | none |
| I08 | `var_20 / 0x1c / 0x4 / _DWORD` | `var_20 / 0x1c / 0x4 / _DWORD` | none |
| I08 | `var_1C / 0x20 / 0x4 / _DWORD` | `var_1C / 0x20 / 0x4 / _DWORD` | none |
| I08 | `var_18 / 0x24 / 0x4 / _DWORD` | `var_18 / 0x24 / 0x4 / _DWORD` | none |
| I08 | `var_14 / 0x28 / 0x4 / _DWORD` | `var_14 / 0x28 / 0x4 / _DWORD` | none |
| I08 | `var_10 / 0x2c / 0x4 / _DWORD` | `var_10 / 0x2c / 0x4 / _DWORD` | none |
| I08 | `var_C / 0x30 / 0x4 / _DWORD` | `var_C / 0x30 / 0x4 / _DWORD` | none |
| I08 | `var_4 / 0x38 / 0x4 / _DWORD` | `var_4 / 0x38 / 0x4 / _DWORD` | none |
| I08 | `__saved_registers / 0x3c / 0x4 / _DWORD` | `__saved_registers / 0x3c / 0x4 / _DWORD` | none |
| I08 | `__return_address / 0x40 / 0x4 / _UNKNOWN *` | `__return_address / 0x40 / 0x4 / _UNKNOWN *` | none |
| I08 | `value / 0x44 / 0x4 / int` | `value / 0x44 / 0x4 / int` | none |
| I08 | `arg_4 / 0x48 / 0x4 / _DWORD` | `arg_4 / 0x48 / 0x4 / _DWORD` | none |
| I09 | `var_2C / 0x10 / 0x4 / _DWORD` | `var_2C / 0x10 / 0x4 / _DWORD` | none |
| I09 | `var_28 / 0x14 / 0x4 / _DWORD` | `var_28 / 0x14 / 0x4 / _DWORD` | none |
| I09 | `var_24 / 0x18 / 0x4 / _DWORD` | `var_24 / 0x18 / 0x4 / _DWORD` | none |
| I09 | `var_20 / 0x1c / 0x4 / _DWORD` | `var_20 / 0x1c / 0x4 / _DWORD` | none |
| I09 | `var_1C / 0x20 / 0x4 / _DWORD` | `var_1C / 0x20 / 0x4 / _DWORD` | none |
| I09 | `var_18 / 0x24 / 0x4 / _DWORD` | `var_18 / 0x24 / 0x4 / _DWORD` | none |
| I09 | `var_14 / 0x28 / 0x4 / _DWORD` | `var_14 / 0x28 / 0x4 / _DWORD` | none |
| I09 | `var_10 / 0x2c / 0x4 / _DWORD` | `var_10 / 0x2c / 0x4 / _DWORD` | none |
| I09 | `var_C / 0x30 / 0x4 / _DWORD` | `var_C / 0x30 / 0x4 / _DWORD` | none |
| I09 | `var_4 / 0x38 / 0x4 / _DWORD` | `var_4 / 0x38 / 0x4 / _DWORD` | none |
| I09 | `__saved_registers / 0x3c / 0x4 / _DWORD` | `__saved_registers / 0x3c / 0x4 / _DWORD` | none |
| I09 | `__return_address / 0x40 / 0x4 / _UNKNOWN *` | `__return_address / 0x40 / 0x4 / _UNKNOWN *` | none |
| I09 | `value / 0x44 / 0x4 / int` | `value / 0x44 / 0x4 / int` | none |
| I09 | `arg_4 / 0x48 / 0x4 / _DWORD` | `arg_4 / 0x48 / 0x4 / _DWORD` | none |
| I05 | `__saved_registers / 0x0 / 0x4 / _DWORD` | `__saved_registers / 0x0 / 0x4 / _DWORD` | none |
| I05 | `__return_address / 0x4 / 0x4 / _UNKNOWN *` | `__return_address / 0x4 / 0x4 / _UNKNOWN *` | none |
| I05 | `arg_0 / 0x8 / 0x4 / _DWORD` | `arg_0 / 0x8 / 0x4 / _DWORD` | none |
| I06 | `__saved_registers / 0x8 / 0x4 / _DWORD` | `__saved_registers / 0x8 / 0x4 / _DWORD` | none |
| I06 | `__return_address / 0xc / 0x4 / _UNKNOWN *` | `__return_address / 0xc / 0x4 / _UNKNOWN *` | none |
| I06 | `arg_0 / 0x10 / 0x1 / char` | `arg_0 / 0x10 / 0x1 / char` | none |
| I07 | `__return_address / 0x4 / 0x4 / _UNKNOWN *` | `__return_address / 0x4 / 0x4 / _UNKNOWN *` | none |

I01/I03 have no modeled function and must still have no frame after comment-only action. I10-I18 are data and must have no frame. No current or expected frame row is omitted for any modeled function or constructor chunk.

**Collision, dependency, ordering, readback, and stop rules**

- Exact name-collision queries returned zero rows for the three remaining proposed names I02/I06/I07. Any nonzero fresh Gate 2B result is a hard stop; `allow_overwrite` remains false. I05 has no proposed name and no collision step.
- Action order for I02/I06/I07 is fixed: fresh item/comment/frame/xref/byte readback; collision check; one-row pure rename dry-run; matching one-row pure rename apply; immediate name/type/frame/byte/xref readback; then one comment-channel action; then complete readback. I05 and all other comment-only rows omit every rename step; I05 additionally records its bounded literal pre-action type and requires exact post-comment equality. No later row may be attempted after a mismatch.
- Protect `DequeInt` as the already-present size-`0x14` five-field UDT. Keep `PrimeNumberGenerator` UDT absent. Protect helper/runtime identities `0x005c7526`, `0x005c772f`, `0x005c956c`, `0x005cd607`, all decorated vtable/RTTI names, every listed physical item boundary, every byte hash, and every xref set. Do not rename dependencies or create aliases.
- Expected deltas are exactly three function names, four FP strings, and fourteen AP strings. AR and FR never change; AP changes only I01/I03/I04/I08-I18; FP changes only I02/I05/I06/I07. Function names change only I02/I06/I07; I05 remains `sub_54C0C0`. No byte, item, range, CFG, function membership, prototype, frame, UDT, xref, string item, undefined pad, or other symbol may change.
- Any prestate drift, collision, endpoint failure, unlisted comment-channel write, unexpected function-directory/decompiler side effect, type/frame normalization, item redefinition, byte/hash/xref delta, or expected-readback mismatch is an immediate no-save stop. The supervisor must not continue the batch or save the IDB.
- If a mutation occurred before a failed readback, classify Gate 2B failed and use the supervisor-owned verified backup/rollback procedure outside this report. Restore and reread the complete frozen state before any later attempt; do not save a partial or repaired-in-place transaction. This rule was exercised for the failed I05 rename described above. The report contains no transaction program and delegates runtime attestation, backup, save, and rollback mechanics to the supervisor.

## First-Draft C++ Recommendation

Recommended UID0000AT formal CPP block:

```cpp
#include "PrimeNumberGenerator.h"

#include <string.h>

[[CHILDREN]]
```

Recommended UID0000AT formal H block:

```cpp
#ifndef NEXUSTK_UTIL_PRIMENUMBERGENERATOR_H
#define NEXUSTK_UTIL_PRIMENUMBERGENERATOR_H

#include <deque>

class PrimeNumberGenerator
{
public:
    explicit PrimeNumberGenerator(int limit);
    virtual ~PrimeNumberGenerator();

    int GetPrimeAt(int index) const;

private:
    unsigned int *m_sieveBits;
    std::deque<int> m_primes;
};

#endif
```

Keep UID0001FA's current exact CPP body:

```cpp
int PrimeNumberGenerator::GetPrimeAt(int index) const
{
    if (index < 0)
        return 2;

    if (index >= static_cast<int>(m_primes.size()))
        index = static_cast<int>(m_primes.size()) - 1;

    return m_primes[index];
}
```

Replace UID0001FB's marker with:

```cpp
PrimeNumberGenerator::PrimeNumberGenerator(int limit)
{
    if (limit < 100)
        limit = 100;
    if (limit > 10000000)
        limit = 10000000;

    m_primes.clear();
    m_primes.push_back(2);
    m_primes.push_back(3);

    unsigned int sieveWordCount =
        static_cast<unsigned int>(limit / 3 + 1);
    m_sieveBits = new unsigned int[sieveWordCount];
    memset(m_sieveBits, 0, sieveWordCount * sizeof(unsigned int));

    for (int upperCandidate = 7;
         upperCandidate <= limit;
         upperCandidate += 6)
    {
        int lowerCandidate = upperCandidate - 2;
        unsigned int lowerIndex =
            static_cast<unsigned int>(lowerCandidate / 3);

        if ((m_sieveBits[lowerIndex >> 5] &
             (1U << (lowerIndex & 31))) == 0)
        {
            m_primes.push_back(lowerCandidate);

            for (int multiple = lowerCandidate;
                 multiple < limit;
                 multiple += lowerCandidate)
            {
                if (multiple % 6 == 1 || multiple % 6 == 5)
                {
                    unsigned int sieveIndex =
                        static_cast<unsigned int>(multiple / 3);
                    m_sieveBits[sieveIndex >> 5] |=
                        1U << (sieveIndex & 31);
                }
            }
        }

        unsigned int upperIndex =
            static_cast<unsigned int>(upperCandidate / 3);

        if ((m_sieveBits[upperIndex >> 5] &
             (1U << (upperIndex & 31))) == 0)
        {
            m_primes.push_back(upperCandidate);

            for (int multiple = upperCandidate;
                 multiple < limit;
                 multiple += upperCandidate)
            {
                if (multiple % 6 == 1 || multiple % 6 == 5)
                {
                    unsigned int sieveIndex =
                        static_cast<unsigned int>(multiple / 3);
                    m_sieveBits[sieveIndex >> 5] |=
                        1U << (sieveIndex & 31);
                }
            }
        }
    }

    delete [] m_sieveBits;
}

PrimeNumberGenerator::~PrimeNumberGenerator()
{
}
```

This draft intentionally preserves the observed paired-loop boundary, marking from the prime itself, `< limit` multiple bound, wheel residue filter, allocation word count, explicit deque clear, and no post-delete null assignment. It intentionally does not hand-write the scalar deleting destructor, deque internals, EH cleanup, vtable, RTTI, or layout assertions.

## Final Recommendation

Approve the file as reconstructable retained utility source and authorize a scoped callback that:

- Completes UID0000MQ's body/score/disposition without adding invalid by-file metadata.
- Adds the header-oriented UID0000AT formal block and CPP scaffold.
- Emits UID0001FA, UID0001FB, and UID0002OK in positions `10/20/30`.
- Uses the exact first-draft constructor/destructor source above.
- Reclassifies UID0001VL and UID0001YG as non-emitting documentation views.
- Preserves UID0001FC and UID0001FD as non-emitting compiler/STL support.
- Synchronizes only directly implicated support docs, applies the proposed-source-tree correction under explicit callback permission, and leaves stale manual coverage text for separate supervisor-owned handling.
- Leaves IDA unchanged unless a distinct mutation authorization is issued.

Do not route this file to Deque, a feature module, or no-owner status. Do not generate a custom Deque implementation, deleting-destructor method, RTTI array, EH table, or manual vtable definition.

Callback disposition: the listed ordinary-document actions are applied and validated. The IDA handoff, manual coverage replacements, and generated/tracker refresh/readback are intentionally untouched and remain pending for their supervisor-owned gates.

Gate 2B repair recommendation: reject the C29E/I05 rename permanently for this report. Keep `sub_54C0C0`, perform no I05 type action, and apply only the exact FP compiler/STL classification with immediate pre/post type equality. Retain the accepted three-rename plan for I02/I06/I07 and every other I01-I04/I06-I18 action without change.

## Recommended Target Doc Changes

For UID0000MQ `by-file/PrimeNumberGenerator.md`:

Implementation receipt: every ordinary target-page item below is applied in the physically reread post-validator page. The generated command reference remains dated historical evidence rather than a claim of generated readback.

- Preserve UID, canonical owner `FILE`, and reconstruction path `NexusTK/util/`.
- Replace the absent `simroot_v2` path claim with a historical-remnant note.
- State explicitly that the file is reconstructable by valid by-file body/score disposition and that no `RECONSTRUCTABLE` metadata key belongs on this schema.
- Expand Proposed Contents to list the header declaration, accessor, constructor/destructor source, vtable marker, and non-emitting support boundaries.
- Add the exact constructor loop and boundary quirk to Evidence Notes.
- Replace aggregate-marker endpoint language with the formal constructor/destructor recommendation.
- Record the generated command `000000023186` snapshot as dated evidence: no header, UID0001FB marker, two empty emitters.
- Clarify that source-level virtual destructor syntax explains raw destructor/deleting-wrapper bodies.
- Add complete RTTI/EH/padding boundaries and bounded negative caller/global/string/resource evidence.
- Update Source Placement to the CPP/H pair and remove any implied `Deque.cpp` dependency.
- Replace score rationale with `94/93` and the explicit below-95 confidence cap.
- Add a dated callback Changes entry only when implementation actually occurs.

No unrelated historical narrative should be deleted merely to shorten the page; stale claims should be corrected or explicitly historicalized.

## Recommended Support Doc Changes

Implementation receipt: all permitted support-page actions below are applied or physically verified already present. UID0001FC/UID0001FD remained byte-for-byte unchanged, UID0000IR/UID000149 required no edit, and manual coverage remained supervisor-owned.

| Support UID/page | Recommended callback action |
| --- | --- |
| UID0000AT class | Score `93/92`; emit header declaration and CPP scaffold; update method notes from marker-only to full constructor/destructor source; preserve active-use cap |
| UID0001FA accessor | Keep score `88/90` and exact formal source; set CPP position `10`; keep H blank; preserve class owner/emitter |
| UID0001FB aggregate | Score `93/92`; replace formal marker with constructor/destructor source; set CPP position `20`; keep H blank; preserve broad-range analysis |
| UID0001FC element helper | No metadata/source change; remain `91/95`, false, blank emitter; optionally synchronize parent prose only |
| UID0001FD clear helper | No metadata/source change; remain `90/94`, false, blank emitter; optionally synchronize parent prose only |
| UID0001VL layout | Score `91/93`; set reconstructable false; clear emitter/positions; leave formal blocks blank; preserve class owner and exact layout |
| UID0001YG vtable | Score `91/94`; set reconstructable false; clear emitter/positions; leave formal blocks blank; preserve class owner and exact RTTI/vtable inventory |
| UID0002OK vtable data | Keep score `88/93` and marker; set CPP position `30`; keep H blank; preserve exact island |
| UID0000IR Deque | No edit required; it already records `NONE` source placement and compiler/STL support disposition |
| UID000149 push evidence | No edit required; use as corroboration for seed and later native `push_back` operations |
| Proposed source tree | Explicitly permitted exact stale-route corrections applied and validated in this callback |
| Manual coverage pages | Supervisor-owned exact replacement rows listed below |

Do not edit client-container meta docs unless a supervisor recheck finds a direct stale Prime claim. The present whole-file result does not require broad meta synchronization.

## Score And Metadata Recommendation

| UID | Gate 1 baseline | Implemented | Metadata/source reason |
| --- | ---: | ---: | --- |
| 0000MQ file | `86/87` | `94/93` | Full whole-file source disposition, exact constructor draft, header route, exhaustive boundaries; no by-file reconstructability field |
| 0000AT class | `86/87` | `93/92` | Complete declaration and source-bearing method set; active-use and original-name cap |
| 0001FA accessor | `88/90` | `88/90` | Already exact enough; position-only callback change |
| 0001FB aggregate | `88/90` | `93/92` | Marker replaced by complete source and compiler split analysis |
| 0001FC deque element helper | `91/95` | `91/95` | Already correctly non-emitting |
| 0001FD deque clear | `90/94` | `90/94` | Already correctly non-emitting |
| 0001VL layout | `85/89` | `91/93` | Exact layout retained; emitter invalidity resolved through false classification |
| 0001YG vtable | `85/91` | `91/94` | Exact RTTI/vtable graph retained; emitter invalidity resolved through false classification |
| 0002OK vtable data | `88/93` | `88/93` | Existing exact marker and island evidence remain sufficient |

No recommended score reaches `95`. For UID0001FC, the existing confidence `95` is preserved because this report does not own or reopen that settled support classification; no new score is being awarded. The target/class/source-bearing updates stay below `95` under the score-blocker standard.

Metadata constraints:

- UID0000MQ: do not add `RECONSTRUCTABLE`; preserve `CANONICAL_OWNER:FILE` and path `NexusTK/util/`.
- UID0000AT/UID0001FA/UID0001FB/UID0002OK: preserve class/file owner relationships and use positions `10/20/30` only for CPP.
- UID0001VL/UID0001YG: false, blank emitter UID, blank CPP/H positions.
- UID0001FC/UID0001FD: preserve existing false/blank emitter state.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Disposition |
| --- | --- | --- |
| Was the utility actively constructed in the shipped client? | Queried direct xrefs to accessor, constructor, raw destructor, helper, vtable, and RTTI; searched canonical docs/routes. No direct construction path found. | Open historical-use question; not a source blocker. |
| Is `GetPrimeAt` the original method name? | Searched RTTI/symbol/docs/remnants and inspected behavior. No method symbol survives; canonical docs consistently use this descriptive name. | Use descriptive name with confidence caveat. |
| Are private/local identifiers original? | Checked symbols, frames, prior remnants, and generated metadata. Offsets and roles are proven; spelling is not. | Use readable source-facing names, never claim symbol provenance. |
| Which exact MSVC/Dinkumware version produced the helpers? | Inspected EH/RTTI form and old deque layout; no decisive compiler-version artifact was located in the bounded pass. | Leave toolset version unspecified. |
| Should UID0001FB be split into new address pages? | Audited every subrange. Source emission can be complete through the existing broad aggregate while children remain documented. | No split required for this callback. |
| Should `m_sieveBits` remain dangling after construction? | Constructor bytes show delete/free and no null store. | Preserve no null assignment in faithful draft. |
| Should the terminal `6k-1` candidate be included? | Reconstructed loop trip count/control flow. Pair executes only while upper candidate is at most `limit`. | Preserve observed quirk; do not normalize. |
| Is a separate `Deque.cpp` required? | Read UID0000IR and helper bodies/callers. All relevant bodies are standard-library/compiler support. | No; retire stale tree route. |
| Should I05 retain the descriptive function rename after its failed-closed type drift? | Re-attested the exact restored IDB hash and read name, prototype channels, comments, bytes, xref, frame, disassembly, and profile without mutation. The descriptive identity is already preserved in documentation and the exact FP text. | Resolved: reject the rename and all I05 type actions; exact FP comment-only classification is sufficient and deterministic. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The manual coverage and tracker blocks are literal supervisor-owned recommendations. Those rows were reread and remain stale, but were not applied because every manual `-coverage-report.md` file and tracker update is outside the B-agent write role. The proposed-source-tree blocks are retained here as exact accepted text and were applied under the callback's explicit permission.

**by-file coverage row**

```text
| [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md) | Reconstructable retained `NexusTK/util/PrimeNumberGenerator.cpp` plus `.h`; emits class declaration, exact accessor, sieve constructor, empty virtual destructor, and compiler-vtable marker while keeping Deque/EH/RTTI/layout support non-emitting. | 94 | 93 |
```

**by-class coverage row**

```text
| [UID:0000AT][PrimeNumberGenerator](by-class/PrimeNumberGenerator.md) | Complete reusable class declaration and three source-bearing methods under UID0000MQ; active runtime construction and exact original identifiers remain unproven. | 93 | 92 |
```

**by-memory coverage block**

```text
| [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md) | Reconstructable exact accessor; emits through UID0000AT at CPP position 10. | 88 | 90 |
| [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md) | Reconstructable constructor/destructor aggregate; emits the exact sieve constructor and empty virtual destructor through UID0000AT at CPP position 20. | 93 | 92 |
| - `0x0054bcf0-0x0054c062` | Source-bearing constructor: clamp, seed, paired wheel sieve, append, and temporary-buffer release. | - | - |
| - `0x0054c070-0x0054c09c` | Raw destructor/cleanup clone generated from the empty virtual destructor and embedded deque. | - | - |
| - `0x0054c0a0-0x0054c0bc` | Constructor EH cleanup chunk; non-emitting. | - | - |
| [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md) | Non-reconstructable compiler/STL `std::deque<int>` element-address support; no emitter. | 91 | 95 |
| - `0x0054c110-0x0054c15a` | Compiler scalar deleting destructor; source cause is `virtual ~PrimeNumberGenerator()`. | - | - |
| [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md) | Non-reconstructable compiler/STL deque clear/storage teardown; no emitter. | 90 | 94 |
| [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md) | Exact one-slot RTTI/vtable island; emits only the compiler-generated marker through UID0000AT at CPP position 30. | 88 | 93 |
```

**by-struct coverage row**

```text
| [UID:0001VL][PrimeNumberGeneratorLayout](by-type/by-struct/PrimeNumberGeneratorLayout.md) | Documentation-only `0x1c` class layout; source cause is fully represented by UID0000AT header, so no independent emitter. | 91 | 93 |
```

**by-vtable coverage row**

```text
| [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md) | Documentation-only one-slot virtual table and RTTI graph; source cause is the virtual class declaration, so no independent emitter. | 91 | 94 |
```

**proposed-source-tree replacements**

```text
    # Deque helper bodies are compiler/STL support; no standalone Deque.cpp.
```

```text
- The historical `Deque.cpp` route is retired: UID0000IR is a documentation index with `NONE` source placement, and UID0001FC/UID0001FD remain non-emitting compiler/STL support.
- `PrimeNumberGenerator.h` owns the polymorphic class declaration, temporary sieve pointer, native `std::deque<int>`, constructor/destructor declarations, and accessor declaration. `PrimeNumberGenerator.cpp` owns the exact accessor and sieve constructor, empty virtual destructor, plus a comment-only compiler vtable marker.
- `PrimeNumberGenerator` remains a retained utility/legacy source route because current IDA has no direct constructor or accessor caller; that negative-use result does not make the complete local source non-reconstructable.
```

**tracker disposition text**

```text
UID0000MQ is reconstructable under the by-file schema through explicit source/body/score disposition. Do not add a RECONSTRUCTABLE metadata key to the file page. After callback validation, expect a CPP/H pair, three coded CPP children in positions 10/20/30, zero empty emitter children, and no Deque source dependency. Re-read the current generated command and tracker row before applying this text.
```

## Follow-Up Actions

The original Gate 1 sequence below is retained as historical callback planning. The earlier Gate 1, callback authorization, leases, ordinary target/support/tree edits, scoped validation, and Gate 2A verification completed before the failed-closed Gate 2B attempt; proposed-source-tree synchronization was explicitly permitted and applied, while manual coverage was not. This repaired exact report revision requires a fresh Gate 1 audit before any second Gate 2B attempt.

1. Supervisor Gate 1: verify this report against a fresh canonical-doc, generated-output, tracker, and read-only IDA snapshot.
2. Issue an explicit implementation callback naming the exact by-* pages permitted for edits.
3. During callback, lease each editable report/document according to project rules and avoid unrelated metadata churn.
4. Apply target and direct-support formal/metadata/body changes, preserving user/supervisor concurrent edits.
5. Request supervisor-owned manual coverage and proposed-source-tree synchronization using the literal text above.
6. Run the project validators only in the authorized implementation lifecycle.
7. Inspect regenerated CPP and H output for exact method order, includes, no duplicated class declaration, no empty emitter markers, and no custom Deque/vtable/RTTI code.
8. Re-read scores, emitter relationships, tracker row, and generated command after validation.
9. Treat the IDA recommendation table as a separate authorization package; do not mutate IDA as part of this report.

Current supervisor-owned follow-up is exact and bounded:

1. Perform a fresh exact-hash Gate 1 audit of this repaired report; do not begin a second Gate 2B attempt from the prior report hash.
2. If Gate 1 passes, perform supervisor-owned Gate 2B handling for C29A-C29R: collision-safe pure renames only for I02/I06/I07, exact FP comment-only I05 with unchanged `sub_54C0C0` and immediate pre/post type equality, and the unchanged I01/I03/I04/I08-I18 comment actions. No B-agent IDA action is pre-credited.
3. Apply or explicitly disposition C28 manual coverage replacements.
4. Complete C30-C31 generated CPP/H and tracker refresh/readback from current validator metadata; verify header presence, positions `10/20/30`, zero empty emitters, and no custom Deque/vtable/RTTI output.
5. Keep report execution/archive handling under validator/supervisor lifecycle authority.

## Confidence

Overall source reconstruction confidence is `93/100`.

High-confidence facts are class/file ownership, object layout, accessor behavior, constructor algorithm, clamp/constants, temporary bitfield lifecycle, native deque use, destructor source cause, exact local code boundaries, vtable/RTTI identity, and non-emitting compiler/STL split.

Confidence is capped by the current lack of direct callers, absence of original C++ symbols for method/private/local names, unknown exact compiler library revision, and the possibility that the historical source used different formatting or equivalent source expressions. The source recommendation prioritizes behavioral and structural fidelity and marks inferred spelling as inferred.

The C29E compiler/STL classification remains high confidence, but the exact rendered I05 return type is not stable across the two attested read epochs even though the restored IDB file hash, symbol, comments, bytes, xref, and frame are exact. That evidence lowers confidence in any I05 rename/type mutation to zero for this report and supports the exact comment-only disposition; it does not change the `93/100` source-reconstruction confidence.

## Validator Results

The earlier Gate 1 report-only self-check is retained as historical pre-callback proof. This same-report Gate 2B repair requires a fresh exact-hash Gate 1 audit. Callback allocation remains `32 applied`, `5 already-present`, and `21 proposed` with `37` checked / `21` unchecked Done cells; C29E stays unchecked/`proposed` and is narrowed identically in both parity tables.

| Check | Result |
| --- | --- |
| Literal H2 section count | PASS: exactly 33 |
| Literal H2 heading order | PASS: exact project template order |
| Section content | PASS: all 33 sections non-empty and substantive |
| Claim ledger schema | PASS: exactly eight fields in every claim row |
| Ledger/checklist parity | PASS: 58 unique ledger rows and the same 58 byte-for-byte eight-field rows in the canonical Done-plus-eight-field checklist |
| Checklist allocation | PASS after callback: 37 checked (`32 applied`, `5 already-present`) and 21 unchecked/`proposed`; manual coverage C28, IDA C29A-C29R, and generated/tracker readback C30-C31 remain supervisor-owned |
| First-draft parity | PASS: header, accessor, constructor, destructor, bounds, bit indexing, marking condition, and cleanup recommendations are present in prose and formal blocks |
| Restored IDB re-attestation | PASS read-only: exact session/path accepted, on-disk SHA256 equals restored backup `35A5E6AB17C9001F6C77ED25546094515C5312C736AE77085ECAE89A6767B506`, and no mutation endpoint was called |
| C29E/I05 repair | PASS: rename rejected, no type action, exact FP comment-only operation, bounded literal type precondition, mandatory byte-for-byte pre/post equality, no-save/rollback stop; remaining rename count exactly three |
| Script-content scan | PASS: report contains only `cpp` and `text` fenced artifacts; no executable shell, PowerShell, Python, batch, IDAPython, or validator script |
| Removed-material scan | PASS: no executable material was encountered, so no inert `-removed.md` companion was required or created |
| Readiness marker count | PASS target: exactly one terminal `READY_FOR_SUPERVISOR_GATE1_REVIEW` marker |
| Lease state after publication | Verified after report release; no Agent-B005 active lease may remain |
| Stable reread | Verified by two post-release SHA256 reads |

**Scoped callback validator receipts**

All commands ran from `source-3/project-documentation`. Validator-owned registry/projected-stat/generated-refresh side effects are receipts, not manual edits. Every generated refresh was `deferred`; no generated CPP/H/tracker readback is claimed.

| Command | Command ID / timestamp | Result and scoped side effects |
| --- | --- | --- |
| `python .\tools\validator.py --mode file --file by-file/PrimeNumberGenerator.md --apply --queue-timeout 240` | `000000023210` / `2026-08-13T17:15:22-04:00` | exit `0`, `ok: 1`; score `94/93`, projected-stat row updates; generated refresh deferred |
| `python .\tools\validator.py --mode file --file by-class/PrimeNumberGenerator.md --apply --queue-timeout 240` | `000000023211` / `2026-08-13T17:16:50-04:00` | exit `0`, `ok: 1`; score `93/92`, CPP/H registry updates, projected-stat row updates; generated refresh deferred |
| `python .\tools\validator.py --mode file --file by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md --apply --queue-timeout 240` | `000000023212` / `2026-08-13T17:17:43-04:00` | exit `0`, `ok: 1`; CPP position `10` registry update; generated refresh deferred |
| `python .\tools\validator.py --mode file --file by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md --apply --queue-timeout 240` | `000000023213` / `2026-08-13T17:19:45-04:00` | exit `0`, `ok: 1`; score `93/92`, CPP position `20` and formal-source registry updates; generated refresh deferred |
| `python .\tools\validator.py --mode file --file by-type/by-struct/PrimeNumberGeneratorLayout.md --apply --queue-timeout 240` | `000000023214` / `2026-08-13T17:21:06-04:00` | exit `0`, `ok: 1`; score `91/93`, reconstructable true -> false, emitter cleared; generated refresh deferred |
| `python .\tools\validator.py --mode file --file by-type/by-vtable/PrimeNumberGeneratorVtable.md --apply --queue-timeout 240` | `000000023215` / `2026-08-13T17:22:21-04:00` | exit `0`, `ok: 1`; score `91/94`, reconstructable true -> false, emitter cleared; generated refresh deferred |
| `python .\tools\validator.py --mode file --file by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md --apply --queue-timeout 240` | `000000023216` / `2026-08-13T17:23:12-04:00` | exit `0`, `ok: 1`; CPP position `30` registry update; generated refresh deferred |
| `python .\tools\validator.py --mode file --file by-project-structure/proposed-source-tree.md --apply --queue-timeout 240` | `000000023217` / `2026-08-13T17:24:21-04:00` | exit `0`, `ok: 1`; exposed one relevant dropped UID0001YG link plus five unrelated pre-existing missing-UID warnings; link restored before release; generated refresh deferred |
| `python .\tools\validator.py --mode file --file by-project-structure/proposed-source-tree.md --apply --queue-timeout 240` rerun after restoring direct vtable links | `000000023218` / `2026-08-13T17:24:43-04:00` | exit `0`, `ok: 1`; UID0001YG/UID0002OK references indexed, UID0002OK label normalized by validator; same five unrelated missing-UID warnings; generated refresh deferred |

**Claim-by-claim callback proof map**

| Claim rows | Concrete proof after physical reread |
| --- | --- |
| C01, C10, C13-C15, C17, C25, C32-C33 | `by-file/PrimeNumberGenerator.md` command `000000023210`, SHA256 `5EEE042C0796B0958E8B47CD37226F8FA49AE31B6AB13FAE071593C75965CDCD`; exact whole-file inventory, negative evidence, source pair, historical remnant/generated snapshot, scores, and active-use cap reread |
| C02, C19 | UID0001FA command `000000023212`, SHA256 `7AC74181186772C9CBB5005E4FDD25794532A8196792CCB072007EEE793E177E`; accepted CPP remained exact, H blank, position `10`; matching UID0000AT declaration reread |
| C03-C07E, C20 | UID0001FB command `000000023213`, SHA256 `376F7B4E3829745832F1930B6131312767A3C97DE63AFA7A41272D887CF98D00`; exact constructor/destructor formal source, seven compiler-record hashes, independent local/tail/EH xrefs, H blank, position `20` reread |
| C08 | UID0001FC physically reread unchanged at SHA256 `4B1BA69C004E7E94CE4CEC38B882B2DB932609DF977BD7BC9AF79CB3BD995930`, score `91/95`, false/blank emitter, sole `0x0054bce1` caller evidence |
| C09 | UID0001FD physically reread unchanged at SHA256 `684365F72CA5D80FC26A989DAA91A08FADD25EC20B225281B3379C3E36A966E7`, score `90/94`, false/blank emitter, six constructor/cleanup/destructor refs |
| C11, C23 | UID0002OK command `000000023216`, SHA256 `867B9C960D3B5676614B5B98E63F732B6A4330C42276888AAD2A587EFB49343B`; exact island/marker preserved, H blank, position `30`, old generated state historicalized |
| C12A-C12E, C22 | UID0001YG command `000000023215`, SHA256 `F3C8B6707667FC7D5C3230C34A1C9FEC6DE12FA37433762CC6B58BE5D61AA4DD`; five independent RTTI entity rows plus vtable cells, seven hashes/xref sets, false/blank emitter reread |
| C16, C18 | UID0000AT command `000000023211`, SHA256 `EDDCAE34BA5C4D1A738ACA968BFB0CD683CE483FAAD556E8E7E58A51D7BA00C0`; exact header guard/class declaration and exact CPP include/children scaffold reread |
| C21 | UID0001VL command `000000023214`, SHA256 `1075AECB76CE795489F5420087125DA50D0D881F65D927C64CB665DE8C91AD42`; score `91/93`, false/blank emitter, blank CPP/H, class-header source cause reread |
| C24, C26 | Commands `000000023210`-`000000023216`; all seven changed by-* destinations returned exit `0` / `ok: 1`; scores/owner/emitter/source state and unchanged Deque support hashes physically reconciled |
| C27 | Proposed source tree command `000000023218`; current stable whole-file SHA256 `BB3912A306AB133F52314FB5A6EA8901DB6CB8084FAE17CDD4DD0CAB106E80A5` after later unrelated file additions; physical `Deque.cpp` entry absent, historical route retained, Prime `.h`/`.cpp` entries and direct vtable links reread |
| C28 | Unchecked/proposed: current manual by-file/class/memory/struct/vtable rows were reread and remain stale; B-agent callback is prohibited from editing manual `-coverage-report.md` files |
| C29A-C29R | Unchecked/proposed: IDA state and Gate 2B actions are supervisor-owned; the callback performed no MCP/IDA mutation, and this report repair used read-only MCP only. C29E is exact FP comment-only with no rename/type action; I01-I04/I06-I18 remain unchanged. No action is pre-credited. |
| C30-C31 | Unchecked/proposed: every scoped validator reported generated refresh `deferred`; generated CPP/H/tracker refresh and physical readback are supervisor-owned and were not claimed |

## Changed Files

Agent-edited ordinary destinations and stable post-validator hashes:

| Path | Before SHA256 | After SHA256 |
| --- | --- | --- |
| `by-file/PrimeNumberGenerator.md` | `841F429E577DCB7BB763AD824595E6D0D27449DAA13157B36F89F4D246F7F4EB` | `5EEE042C0796B0958E8B47CD37226F8FA49AE31B6AB13FAE071593C75965CDCD` |
| `by-class/PrimeNumberGenerator.md` | `F77B635EF525151EF93AF190F4CCA285106BC0C8974AD44DC0BA41B76A6421DD` | `EDDCAE34BA5C4D1A738ACA968BFB0CD683CE483FAAD556E8E7E58A51D7BA00C0` |
| `by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md` | `0FF9CCE6F3DE542573CBC336E98498154E1744B6100BF346F0793C93FD172A2A` | `7AC74181186772C9CBB5005E4FDD25794532A8196792CCB072007EEE793E177E` |
| `by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md` | `7A4C91CFA9DFE97D9E53915DA96821A6BFFAE6E598A26435E876C91E5EBDAFBF` | `376F7B4E3829745832F1930B6131312767A3C97DE63AFA7A41272D887CF98D00` |
| `by-type/by-struct/PrimeNumberGeneratorLayout.md` | `88486A141DA637CB2FF2646413123A52C5E924621716400F4D9E53E555A6B4C4` | `1075AECB76CE795489F5420087125DA50D0D881F65D927C64CB665DE8C91AD42` |
| `by-type/by-vtable/PrimeNumberGeneratorVtable.md` | `2EA3E20CE7686C8E089E5D6ACDFD932D2844CF231891D590ACA37D603491AE6B` | `F3C8B6707667FC7D5C3230C34A1C9FEC6DE12FA37433762CC6B58BE5D61AA4DD` |
| `by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md` | `A405D7B07A16C650B52532AF64F81326BE5428334E5358538154DE798428CB6B` | `867B9C960D3B5676614B5B98E63F732B6A4330C42276888AAD2A587EFB49343B` |
| `by-project-structure/proposed-source-tree.md` | `DB2D8CFF63012E6DB50D45C1E94E1B1997979CEC02B7CA83A1B0526D3D98C2BB` | `BB3912A306AB133F52314FB5A6EA8901DB6CB8084FAE17CDD4DD0CAB106E80A5` |

This same report was updated from passed Gate 1 SHA256 `13A99E1A8C5FF87FC4BBF685292536D91752E0163F0CFE977868C351CF72D270`; the stable ordinary-callback artifact before this repair was SHA256 `78EBD99C064D8A607040EF8E74473E8FC7F312F9E4625F7E4ED914122BD38AF9`. This additive Gate 2B repair changes only this report and computes its new hash after lease release. Validator-owned registry/projected-stat/generated-refresh metadata changed only through the historical scoped commands above. No manual coverage, generated Markdown/source, tracker, audit ledger, IDA database, goal/notes, validator lifecycle/queue/lock, report lifecycle/archive, removed-material companion, ordinary document, or other report was agent-edited or moved during this repair. Report execution/archive state remains supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

The canonical checklist adds only `Done` to the exact eight ledger fields. Callback allocation is `37` checked (`32 applied`, `5 already-present`) and `21` unchecked/`proposed`. No C28 manual coverage, C29A-C29R IDA, or C30-C31 generated/tracker refresh/readback action is pre-credited; exact reasons and proof are recorded under `Validator Results`.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C01 | 0000MQ | UID0000MQ is a reconstructable retained utility at `NexusTK/util/`; no invalid by-file reconstructability key is needed. | High | Canonical schema, file/class ownership, imported metadata, current tracker analysis | UID0000MQ Status/File Role/Score Rationale | incorporate | applied |
| [x] | C02 | 0001FA | Raw `0x0054bcc0-0x0054bcec` is the exact source accessor `GetPrimeAt(int) const`. | High | Raw listing, helper call, object offsets, current formal source | UID0001FA and UID0000AT method/source sections | already-present | already-present |
| [x] | C03 | 0001FB | `0x0054bcf0-0x0054c062` reconstructs the complete clamp, seed, wheel-sieve, append, and temporary-buffer cleanup constructor. | High | Hex-Rays, disassembly, call fanout, constants, layout | UID0001FB formal CPP and evidence | incorporate | applied |
| [x] | C04 | 0001FB | The source loop must preserve `upperCandidate <= limit` and the paired `upper-2`/`upper` boundary quirk. | High | Constructor control flow and trip-count arithmetic | UID0001FB behavior caveat | incorporate | applied |
| [x] | C05 | 0001FB | The source destructor is empty and virtual; member cleanup and deleting-wrapper behavior are compiler consequences. | High | Raw destructor body, scalar deleting destructor, vtable, class layout | UID0001FB formal CPP and split analysis | incorporate | applied |
| [x] | C06 | 0001FB | Raw `0x0054c070-0x0054c09c` is a function-shaped destructor/cleanup clone, not another hand-authored method. | High | Bytes, vtable store, repeated deque teardown, no inbound xrefs | UID0001FB inventory/boundaries | incorporate | applied |
| [x] | C07A | 0001FB | `0x0054c0a0-0x0054c0bc` is the constructor-owned local EH cleanup chunk for the embedded deque. | High | Constructor CFG ownership, inbound jump `0x00606276`, calls `0x0054c160` and `0x005c7526`, exact 28-byte hash | UID0001FB EH analysis | incorporate | applied |
| [x] | C07B | 0001FB | `0x00606270-0x0060627b` is the constructor unwind-dispatch tail chunk that adjusts to `this+0x08` and jumps to `0x0054c0a0`. | High | Constructor CFG, inbound UnwindMap data xref, exact 11 bytes and hash | UID0001FB EH analysis | incorporate | applied |
| [x] | C07C | 0001FB | `0x0060627b-0x00606296` is the constructor SEH handler tail chunk that checks the cookie, loads `FuncInfo`, and jumps to `__CxxFrameHandler3`. | High | Constructor CFG/disassembly, inbound `0x0054bcf5` data ref, exact 27 bytes and hash | UID0001FB EH analysis | incorporate | applied |
| [x] | C07D | 0001FB | `0x0066392c-0x00663934` is the exact two-field MSVC `UnwindMapEntry` for cleanup tail `0x00606270`. | High | Eight-byte data item `stru_66392C`, bytes, hash, inbound `FuncInfo`, outbound cleanup-tail xref | UID0001FB EH analysis | incorporate | applied |
| [x] | C07E | 0001FB | `0x00663934-0x00663958` is the exact MSVC constructor `FuncInfo` item referencing the one-entry unwind map. | High | 36-byte data item `stru_663934`, bytes, hash, inbound handler ref, outbound unwind-map xref | UID0001FB EH analysis | incorporate | applied |
| [x] | C08 | 0001FC | `0x0054c0c0-0x0054c110` is non-emitting `std::deque<int>` element-address support. | High | Decompilation, sole accessor xref, Deque docs | UID0001FC; UID0000MQ dependency text | already-present | already-present |
| [x] | C09 | 0001FD | `0x0054c160-0x0054c1f1` is non-emitting deque clear/storage teardown support. | High | Decompilation and six ctor/dtor family xrefs | UID0001FD; UID0000MQ dependency text | already-present | already-present |
| [x] | C10 | 0000MQ | Exact CC padding and predecessor/successor boundaries prevent range absorption. | High | Raw bytes and function boundaries | UID0000MQ/UID0001FB boundary tables | incorporate | applied |
| [x] | C11 | 0002OK | `0x0062241c-0x00622424` is exactly one RTTI pointer plus one deleting-destructor slot. | High | Exact dwords, names, xrefs, neighboring RTTI pointer | UID0002OK and parent evidence | already-present | already-present |
| [x] | C12A | 0001YG | `0x0064e318-0x0064e32c` is the compiler-generated PrimeNumberGenerator Complete Object Locator. | High | Decorated name, exact 20 bytes/hash, vtable-prefix inbound xref, TypeDescriptor/CHD outbound fields | UID0001YG COL evidence/non-emitting rationale | incorporate | applied |
| [x] | C12B | 0001YG | `0x0064e32c-0x0064e33c` is the compiler-generated one-base Class Hierarchy Descriptor. | High | Decorated name, exact 16 bytes/hash, COL/BCD inbound refs, BCA outbound field | UID0001YG CHD evidence/non-emitting rationale | incorporate | applied |
| [x] | C12C | 0001YG | `0x0064e33c-0x0064e344` is the compiler-generated Base Class Array cell plus protected zero padding. | High | Decorated name, exact eight bytes/hash, CHD inbound ref, BCD outbound pointer, undefined trailing dword | UID0001YG BCA evidence/non-emitting rationale | incorporate | applied |
| [x] | C12D | 0001YG | `0x0064e344-0x0064e360` is the compiler-generated Base Class Descriptor with PMD `{0,-1,0}` and attributes `0x40`. | High | Decorated name, exact 28 bytes/hash, BCA inbound ref, TypeDescriptor/CHD outbound fields | UID0001YG BCD evidence/non-emitting rationale | incorporate | applied |
| [x] | C12E | 0001YG | `0x006788e8-0x0067890c` is the compiler-generated TypeDescriptor for `.?AVPrimeNumberGenerator@@`. | High | Decorated name/string, exact 36 bytes/hash, COL/BCD inbound refs, RTTI-vftable outbound ref | UID0001YG TypeDescriptor evidence/non-emitting rationale | incorporate | applied |
| [x] | C13 | 0000MQ | No file-owned global/static table, string, resource, or custom import dependency was found. | Medium-high | String/import/global scan and constructor fanout | UID0000MQ negative evidence | incorporate | applied |
| [x] | C14 | 0000MQ | Current IDB has no direct callers for accessor, constructor, or raw destructor; this supports retained/legacy status only. | High | Current bounded xref queries | UID0000MQ active-use caveat | incorporate | applied |
| [x] | C15 | 0000MQ | File ownership remains `NexusTK/util/PrimeNumberGenerator`, not Deque or feature code. | High | Canonical ownership, isolated role, negative caller result | UID0000MQ placement | already-present | already-present |
| [x] | C16 | 0000AT | A real `PrimeNumberGenerator.h` is required for a reusable class declaration and source include. | High | Current class/formal state and missing generated header | UID0000AT formal H/CPP; UID0000MQ caveats | incorporate | applied |
| [x] | C17 | 0000MQ | Current generated output is incomplete: aggregate marker, two empty emitters, and no header. | High | Generated command `000000023186` and file coverage | UID0000MQ Generated Output Caveats | incorporate | applied |
| [x] | C18 | 0000AT | Class formal blocks should emit the header declaration and a CPP include/child scaffold. | High | Layout, methods, vtable identity, generated composition | UID0000AT formal blocks | incorporate | applied |
| [x] | C19 | 0001FA | Keep accessor CPP source, blank H block, and assign class-child CPP position `10`. | High | Existing exact formal source and binary address order | UID0001FA metadata/formal blocks | incorporate | applied |
| [x] | C20 | 0001FB | Replace the marker with constructor/destructor CPP source, blank H block, position `20`. | High | Complete constructor and destructor analysis | UID0001FB metadata/formal blocks | incorporate | applied |
| [x] | C21 | 0001VL | Layout is documentation-only and should be `RECONSTRUCTABLE:FALSE` with blank emitters. | High | Header fully represents source cause; current empty marker | UID0001VL metadata/formal blocks | incorporate | applied |
| [x] | C22 | 0001YG | Vtable type is documentation-only and should be `RECONSTRUCTABLE:FALSE` with blank emitters. | High | Virtual declaration represents source cause; current empty marker | UID0001YG metadata/formal blocks | incorporate | applied |
| [x] | C23 | 0002OK | Preserve the compiler-generated vtable marker and assign CPP position `30`; do not emit arrays. | High | Exact one-slot vtable evidence and existing formal marker | UID0002OK metadata/formal CPP | incorporate | applied |
| [x] | C24 | 0000MQ | Apply bounded post-callback score updates, led by target `94/93`, with no score at or above `95`. | Medium-high | Resolved source gaps plus remaining active-use/name limits | Target/support score blocks | incorporate | applied |
| [x] | C25 | 0000MQ | Rewrite target status, contents, evidence, caveats, placement, score, and changes around the complete source disposition. | High | Whole-file synthesis | UID0000MQ body | incorporate | applied |
| [x] | C26 | 0000AT | Synchronize class, aggregate, layout, vtable, and vtable-data support docs without changing unrelated Deque pages. | High | Direct dependency graph | Listed support pages | incorporate | applied |
| [x] | C27 | 0000MQ | Retire stale `Deque.cpp` and incomplete Prime source-tree text in the supervisor-owned structure page. | High | UID0000IR current NONE route and full source analysis | Proposed source tree exact replacements | reject-stale | applied |
| [ ] | C28 | 0000MQ | Replace stale manual coverage rows with the exact callback scores/dispositions. | High | Current manual rows versus canonical docs | Supervisor-owned coverage text | reject-stale | proposed |
| [ ] | C29A | 0001FA | At raw accessor `0x0054bcc0`, add only the exact address-repeatable behavior comment; preserve unmodeled code, absent name/type/function frame, bytes, and xrefs. | High | Current item/comment state, exact 44-byte hash, bounded zero inbound xrefs | Supervisor Gate 2B IDA handoff I01 | incorporate | proposed |
| [ ] | C29B | 0001FB | Pure-rename modeled constructor `0x0054bcf0` to `PrimeNumberGenerator_Constructor` and add only the exact function-repeatable behavior comment; preserve prototype and complete frame. | High | Current function/type/comments/frame, collision-free name, exact main-body/chunk hashes and xrefs | Supervisor Gate 2B IDA handoff I02 | incorporate | proposed |
| [ ] | C29C | 0001FB | At raw destructor clone `0x0054c070`, add only the exact address-repeatable compiler-consequence comment; preserve unmodeled code, absent name/type/function frame, bytes, and xrefs. | High | Current item/comment state, exact 44-byte hash, bounded zero inbound xrefs | Supervisor Gate 2B IDA handoff I03 | incorporate | proposed |
| [ ] | C29D | 0001FB | At constructor cleanup chunk `0x0054c0a0`, add only the exact address-repeatable EH comment and preserve its parent-function membership, label, frame, bytes, and xrefs. | High | Current chunk/item/comments, parent frame, exact 28-byte hash and routes | Supervisor Gate 2B IDA handoff I04 | incorporate | proposed |
| [ ] | C29E | 0001FC | At modeled helper `0x0054c0c0`, add only the exact function-repeatable compiler/STL comment; preserve name `sub_54C0C0`, the exact immediate pre-action prototype, frame, bytes, and xrefs; do not rename or set type. | High | Failed-closed pure-rename type drift, exact restored IDB hash, fresh function/type/comments/frame readback, exact 80-byte hash and sole raw caller | Supervisor Gate 2B IDA handoff I05 | incorporate | proposed |
| [ ] | C29F | 0001FB | Pure-rename `0x0054c110` to `PrimeNumberGenerator_ScalarDeletingDestructor` and add only the exact function-repeatable compiler comment; preserve prototype and frame. | High | Current function/type/comments/frame, collision-free name, exact 74-byte hash and vtable xref | Supervisor Gate 2B IDA handoff I06 | incorporate | proposed |
| [ ] | C29G | 0001FD | Pure-rename `0x0054c160` to `std_deque_int_clear_storage` and add only the exact function-repeatable compiler/STL comment; preserve prototype and frame. | High | Current function/type/comments/frame, collision-free name, exact 145-byte hash and six inbound calls | Supervisor Gate 2B IDA handoff I07 | incorporate | proposed |
| [ ] | C29H | 0001FB | At unwind-dispatch tail `0x00606270`, add only the exact address-repeatable comment; preserve constructor chunk membership, label, frame, bytes, and xrefs. | High | Current chunk/item/comments, exact 11 bytes/hash and UnwindMap/cleanup routes | Supervisor Gate 2B IDA handoff I08 | incorporate | proposed |
| [ ] | C29I | 0001FB | At SEH handler tail `0x0060627b`, add only the exact address-repeatable comment; preserve constructor chunk membership, label, frame, bytes, and xrefs. | High | Current chunk/item/comments, exact 27 bytes/hash and cookie/FuncInfo/handler routes | Supervisor Gate 2B IDA handoff I09 | incorporate | proposed |
| [ ] | C29J | 0001FB | At UnwindMap item `0x0066392c`, add only the exact address-repeatable comment; preserve the eight-byte data item, name, absent type, bytes, and xrefs. | High | Current physical item/comments, exact bytes/hash and EH graph refs | Supervisor Gate 2B IDA handoff I10 | incorporate | proposed |
| [ ] | C29K | 0001FB | At `FuncInfo` item `0x00663934`, add only the exact address-repeatable comment; preserve the 36-byte data item, name, absent type, bytes, and xrefs. | High | Current physical item/comments, exact bytes/hash and EH graph refs | Supervisor Gate 2B IDA handoff I11 | incorporate | proposed |
| [ ] | C29L | 0002OK | At vtable-prefix cell `0x0062241c`, add only the exact address-repeatable comment; preserve the four-byte data item, absent name/type, bytes, and COL xref. | High | Current physical item/comments, exact dword/hash and outbound COL ref | Supervisor Gate 2B IDA handoff I12 | incorporate | proposed |
| [ ] | C29M | 0002OK | At vtable slot `0x00622420`, add only the exact address-repeatable comment; preserve decorated name, four-byte item, absent type, bytes, and all four refs. | High | Current physical item/comments, exact dword/hash, three inbound stores and destructor target | Supervisor Gate 2B IDA handoff I13 | incorporate | proposed |
| [ ] | C29N | 0001YG | At COL `0x0064e318`, add only the exact address-repeatable comment; preserve decorated name, physical dword topology, generic AR text, bytes, and RTTI graph xrefs. | High | Current physical items/comments, exact 20-byte hash and graph refs | Supervisor Gate 2B IDA handoff I14 | incorporate | proposed |
| [ ] | C29O | 0001YG | At CHD `0x0064e32c`, add only the exact address-repeatable comment; preserve decorated name, four-dword topology, generic AR text, bytes, and RTTI graph xrefs. | High | Current physical items/comments, exact 16-byte hash and graph refs | Supervisor Gate 2B IDA handoff I15 | incorporate | proposed |
| [ ] | C29P | 0001YG | At BCA `0x0064e33c`, add only the exact address-repeatable comment; preserve decorated name, pointer dword, undefined zero tail, generic AR text, bytes, and graph xrefs. | High | Current physical item/undefined-tail/comments, exact eight-byte hash and graph refs | Supervisor Gate 2B IDA handoff I16 | incorporate | proposed |
| [ ] | C29Q | 0001YG | At BCD `0x0064e344`, add only the exact address-repeatable comment; preserve decorated name, seven-dword topology, generic AR text, bytes, and graph xrefs. | High | Current physical items/comments, exact 28-byte hash and graph refs | Supervisor Gate 2B IDA handoff I17 | incorporate | proposed |
| [ ] | C29R | 0001YG | At TypeDescriptor `0x006788e8`, add only the exact address-repeatable comment; preserve decorated name, dword/string/pad topology, generic AR text, bytes, and graph xrefs. | High | Current physical items/comments, exact 36-byte hash and graph refs | Supervisor Gate 2B IDA handoff I18 | incorporate | proposed |
| [ ] | C30 | 0000MQ | Callback validation must regenerate output and verify a header, zero empty emitters, child order, and score consistency. | High | Current generated defects and formal composition rules | Validator/follow-up actions | incorporate | proposed |
| [ ] | C31 | 0000MQ | Tracker and generated snapshots are dated/dynamic and must be freshly read at each gate. | High | Workflow lifecycle ownership and current command timestamp | Supervisor recheck/tracker text | incorporate | proposed |
| [x] | C32 | 0000MQ | The absent historical `simroot_v2` source path is a lead, not active source truth. | High | Repository search and current canonical/generated state | UID0000MQ history/evidence | historicalize | applied |
| [x] | C33 | 0000MQ | Remaining unknowns are exact original names/toolset and active use; none blocks reconstruction. | Medium-high | Symbol absence, no-caller result, complete local behavior | Open questions/confidence | incorporate | applied |

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000023264","destination_path":"executed-b-agent-research/B005/0000MQ-PrimeNumberGenerator-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0000MQ-PrimeNumberGenerator-file-source-quality.md","timestamp":"2026-08-14T02:32:27-04:00","uid":"0000MQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
