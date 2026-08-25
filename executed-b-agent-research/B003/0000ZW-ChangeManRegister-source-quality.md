** TARGET-REPORT-UID:0000ZW **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0000ZW ChangeManRegister Source-Quality Research


## Finalized Report / Current Recommendation

- Implemented disposition: UID0000ZW is the one exact reconstructable `ChangeMan` member at `0x0047ed50-0x0047ed80`, retains canonical owner/emitter UID00001K, now has emitter position `20`, score `92/94`, and exact `void ChangeMan::Register(LObject *owner, LObject *listener, MessageType messageType, bool allMessages)` managed C++.
- Final disposition: standalone exact method emitter. UID0000ZX remains a non-emitting pair index and UID0000ZU remains a non-emitting physical-range index; neither aggregate duplicates this body.
- Implemented model: invented `ChangeListener` / `ChangeMessageScope` / explicit padding scaffolding is historicalized in favor of the proven `LObject` primary-vtable callback route, `MessageType`, `bool allMessages`, and natural x86 padding. The `0x004f4b30/50/70` forwarding trio is validator-renamed and emitted as inherited `LObject` methods through UID00007D/UID0000KV.
- Confidence: very strong for range, bytes, ABI, stack-record order, list call, caller/callee set, common-base ownership, and callback slot; high but not symbol-level for exact method/field spellings and the source-level `bool` spelling.

## Supporting Research

- Mandatory live evidence was collected on 2026-07-13 from NexusTK IDB database session `328356ab`. A fresh `idb_list` returned one active, adopted worker for `NexusTK.exe.i64`; `server_health` returned `status:ok`, image base `0x400000`, and ready auto-analysis, Hex-Rays, and strings cache. These are evidence-collection-time facts, not an indefinite assertion about later session availability.
- Current documentation checked includes UID0000ZW, UID0001TV, UID0001TW, UID0000ZX, UID0000ZU, UID0000ZY, UID0000ZZ, UID000100, UID0004I6, UID000101, UID000103, UID00001K, UID0000I2, UID0000DF, UID00037J, UID000198, UID00019A, UID00019B, UID000199, UID000195, UID0000WM, UID00007D, UID0000KV, Application class/file pages, and the confirmed listener consumer pages.
- Matching executed reports were searched with `UID0000ZW`, `0x0047ed50`, `ChangeManRegister`, `ApplicationRegisterChangeListener`, `UID000198`, `ChangeListener`, and `LObject`. Relevant leads were B010 ChangeMan target research, B009 ChangeMan emitter-family research, B004 UID000198 wrapper research, B002 ChangeMan method research, B001 complete ChangeMan range research, and B011 LObject runtime-shell research.
- Historical B004 evidence explicitly considered an `LObject` route but rejected it only because that pass lacked exact proof that every observed receiver shared the same base method. Fresh constructor-chain evidence now supplies that missing proof and supersedes the source-neutral Application-file helper recommendation.
- `auto-generated/NexusTK/app/ChangeMan.cpp`, `auto-generated/NexusTK/app/Application.cpp`, and `auto-generated/NexusTK/util/LObject.cpp` from validator command `000000009304`, refreshed `2026-07-13T06:01:17-04:00`, are retained as explicitly historical pre-callback generated-state evidence. Initial callback generation was command `000000009417`; after the focused R15/R16 literal-block repair, waited validator `000000009463` completed and generated `MapPane.cpp` carries command `000000009464`, refreshed `2026-07-13T07:42:19-04:00`.
- Historical phase boundary: before Gate 1 acceptance this was report-only research with no by-* edits, leases, or validators. During the authorized callback B003 edited only the listed by-* pages under short leases, ran scoped validators, and performed no IDA mutation, report execution, lifecycle, move, or archive command.

## Target

- Target UID: `0000ZW`.
- Target path: `by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md`.
- Source queue/report row: reconstructable exact by-memory method, not currently covered by a direct report when assigned.
- Implemented classification: source-quality repair of an existing exact emitter with signature, return, entry type, helper return, and wrapper ownership resolved.
- Implemented scores and parent state: `92/94`, owner/emitter UID00001K, reconstructable true, `Nested:0`, and `EMITTER_POSITION_OPTIONAL:20`.

## Current Target State

- UID0000ZW now has the consistent owner/emitter/position metadata, exact accepted formal block, range/ABI/helper-return/caller/callee evidence, and `92/94` scores.
- UID0001TV and UID0001TW now use `LObject *`, `MessageType`, and byte-sized `bool allMessages`; natural x86 alignment supplies the three bytes between offsets `+0x09` and `+0x0b` without a source padding member.
- UID000198, UID00019A, UID00019B, and UID000199 retain their UIDs/endpoints and now use validator-managed LObject paths. Exact machine ABI, common-base constructor chains, and wrapper flow replace the stale Application/free-helper routes.
- UID0000WM now documents and emits the base `OnChangeMessage(LObject *, Message *)` body while preserving 517 data xrefs, zero code xrefs, exact bytes, and identical-body-folding history.
- Final waited validator `000000009463` generated fresh output; `MapPane.cpp` carries generated command `000000009464`, retains the exact inherited constructor/destructor expressions, and now preserves report blocks R15/R16 byte-for-byte at their by-memory destinations. Generated ChangeMan.cpp still has one UID0000ZW body, LObject.cpp has four LObject member definitions, and Application.cpp has no wrapper definitions.
- B003 implementation and scoped validation are complete; B003 itself performed no execute/lifecycle/move/archive command. Current report validation, count, path, move, archive, and execution state is external supervisor/validator-owned and is neither asserted nor directed by this artifact.

## Executive Recommendation

- Keep `ChangeMan::Register` as the best source-facing member name. `RegisterListener` and `AddListener` remain possible original spellings, but the paired manager API, current subsystem vocabulary, and wrapper name `RegisterChangeListener` make the shorter manager-local `Register` the most coherent reconstruction.
- Use source return `void`. `SortedList::InsertSorted` genuinely returns an insertion index in EAX, but UID0000ZW performs no source-visible conversion, UID000198 forwards without testing it, and all four wrapper callers discard it. A normal `void` call chain leaves the callee's EAX residue untouched and reproduces the observed machine state.
- Use `LObject *` for both owner and listener. Owner receivers are `BackPane` and `Application`, both proven `LObject`-derived at object offset zero. Dispatch invokes listener primary-vtable slot `+0x08`; that is exactly the third `LObject` slot, with the base no-op and four confirmed derived overrides.
- Use `MessageType` for the 32-bit tag/filter field. Current Message documentation already defines it as `typedef unsigned int MessageType`, and dispatch compares it to `Message::m_type` at `+0x04`.
- Use `bool allMessages` for the one-byte API/record field. The ABI reads only `[ebp+0x14]` low byte, all 11 wrapper call expressions pass `false`, exact `true` means bypass the message-type test, and exact `false` means compare `messageType`. A normal pre-C++11 enum would be four bytes and cannot reproduce the one-byte store without nonstandard packing.
- Reclassify the forwarding trio as `LObject::RegisterChangeListener`, `LObject::UnregisterChangeListener`, and `LObject::ForwardMessage`. Use validator-managed UID-preserving renames for the exact by-memory paths; do not change their exact ranges.

## Supervisor Active Recheck

- Historical Gate 1 state: the supervisor accepted exact report SHA `CE73BEADF377C982188BBB519A581A7F8E4BAC1853C7398799756E590DD7E532` and authorized implementation of C01-C20.
- Split repair was not required for UID0000ZW. The exact function remains a clean standalone child; the completed structural repair is source reclassification of the external forwarding trio without endpoint changes.
- Every accepted source-bearing item is implemented below. Compiler wrappers and physical indexes remain explicit non-emitting support.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest true semantic owner and separates owner from emitter route. UID0000ZW remains directly owned by ChangeMan; the forwarding wrappers move to the narrower LObject class rather than an incidental Application file consumer.
- Existing names/types were treated as hypotheses. `ChangeListener`, `ChangeMessageScope`, explicit source padding, Application-file free helpers, and decompiler `int` returns were re-tested rather than copied.
- Direct IDA facts are stated as addresses, bytes, stack offsets, xrefs, calls, vtable slots, and constructor chains. Documentation evidence is used for UID/path routing and established `MessageType`. Source-facing names and access are marked inferred where no symbol survives.
- Stale Wave2/Wave3/simroot references found in broader Application/Map documentation were ignored as evidence. Current IDA and current by-* facts control this report.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Resolution |
| --- | --- | --- |
| Target return | Hex-Rays propagates the `int` from UID00037J, but no caller tests or stores EAX. Sibling unregister/dispatch paths also retain arbitrary last-call values while serving side effects. | Source return is `void`; document EAX as residue from `InsertSorted`, not an API result. |
| Helper return | UID00037J scans into EBX, copies the element, executes `mov eax, ebx`, and returns with `retn 4`. | `int SortedList::InsertSorted(const void *element)` is the best helper signature. UID0000ZW deliberately ignores the index. |
| Owner type | Register callers use `g_pBackPane` three times and `g_pApplication` once. Application constructor calls LObject construction at offset zero. BackPane -> Pane -> GrafPort, and GrafPort constructor calls LObject construction at offset zero. | `LObject *owner`, not `void *`, Application-only, or BackPane-only. |
| Listener type | Dispatch calls primary vtable slot `+0x08` on record `+0x04`. LObject vtable slot `+0x08` is UID0000WM; AboveFrame, FramePartPane, MapPane, and VideoPlayerPane replace the same slot. | `LObject *listener`; reject a separate `ChangeListener` interface/subobject. |
| Callback name | UID0000WM previously used generic `VirtualNoop` because parameters were unknown. Dispatch passes `(owner, Message*)`; overrides read `Message+4`. | Infer common virtual `LObject::OnChangeMessage(LObject *owner, Message *message)` and normalize confirmed overrides. |
| Message type | Record `+0x0c` and `Message+0x04` are compared as dwords; Message docs already define open-ended `MessageType`. | Use `MessageType`, not a closed enum or raw decompiler `int`. |
| Scope type | Target and wrappers read one byte from a four-byte argument slot. All 11 calls pass zero. Dispatch/unregister distinguish exact 1 and 0. | Use `bool allMessages`; reject ordinary `ChangeMessageScope` enum because it would be four-byte source storage. Retain invalid 2..255 behavior only as binary negative evidence outside valid bool states. |
| Record padding | Target writes `+0`, `+4`, one byte at `+8`, then dword at `+0xc`; bytes `+9..+b` remain unwritten. Constructor sets SortedList element size 16. | Omit source padding member. Natural x86 alignment provides the three bytes and preserves size 16. |
| Wrapper source | Existing free-helper source requires a nonstandard explicit `__thiscall` declaration and contradicts the implicit ECX owner. The trio is adjacent to LObject constructor/runtime methods and all receivers share LObject. | Implemented all three wrappers as LObject members with output route UID00007D -> UID0000KV. |
| Target split | Exact function has one block, one caller, one callee, clean predecessor/successor boundaries, and no internal padding. | Keep one exact child. Do not emit UID0000ZX or UID0000ZU. |
| Access | Unrelated pane/application methods invoke registration through owner objects; ChangeMan invokes the callback through an LObject pointer. | Registration/unregistration/forwarding and callback virtual must be callable through the base API; public is the best source-facing access absent friend evidence. |

Rejected alternatives:

- `int ChangeMan::Register(...)`: rejected because no caller consumes the helper index and no source-visible return conversion exists.
- `bool ChangeMan::Register(...)`: rejected because there is no boolean normalization/test and the helper returns arbitrary nonnegative indexes.
- `ChangeMessageScope`: rejected as an ordinary C++ enum because its source size is four bytes while the target stores one byte.
- `unsigned char scope`: ABI-compatible but weaker source shape than `bool allMessages`; only two source states are observed, all calls pass false, and exact true/false semantics are direct.
- `ChangeListener *`: rejected because the callback dispatches through the primary LObject vtable at object offset zero and no listener-interface adjustment or second vptr exists.
- Application member: rejected by three BackPane register receivers and five BackPane unregister receivers.
- Application-file free helper: rejected by `__thiscall`/`retn 0x0c`, implicit ECX owner, common-base proof, and physical LObject clustering.
- ChangeMan-owned wrapper: rejected because the wrapper receiver is the owner object, not ChangeMan; it only loads the global manager internally.
- Aggregate emission: rejected because it would duplicate exact child methods.

## Evidence Standards Used

- Direct evidence: fresh MCP `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `func_profile`, `basic_blocks`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, and `callees` calls, always with database `328356ab`.
- Structural evidence: exact constructor chains, vtable slot bytes, derived override bodies, object allocation sizes, list constructor arguments, and adjacent function/padding boundaries.
- Documentation evidence: current by-* UID routing, formal blocks, MessageType declaration, generated command metadata, and matching executed reports as historical leads.
- Negative evidence: no second listener-interface vptr/adjustment, no target strings, no additional target callers/callees, no return use, no valid nonzero caller argument, no source-level aggregate, and no symbol proof for exact spellings.
- The evidence is sufficient for a high-confidence first draft because every machine-level field, call, and ABI decision is direct. Confidence remains below 95 because original identifiers/access headers and the exact original `bool` member spelling do not survive.

## Evidence Checked

- IDA availability at evidence collection: fresh `idb_list` and `server_health` returned NexusTK database session `328356ab` healthy with analysis/Hex-Rays/strings ready.
- Target boundary/bytes: `lookup_funcs(0x0047ed50)`, `get_bytes(0x0047ed4f, 50)`, `disasm`, `decompile`, `func_profile`, `basic_blocks`, `xrefs_to`, and `callees`.
- Callee: complete `0x004f3690` decompile/disassembly and profile, including final returned insertion index.
- Wrapper trio: exact bytes, decompiles, disassembly, direct caller sets, callee sets, and all four register/seven unregister call expressions.
- Base ownership: Application constructor `0x00463310`, GrafPort constructor `0x004b8bf0`, Pane constructor `0x00544460`, and current `BackPane : public Pane` declaration.
- Callback typing: LObject vtable bytes at `0x0061cf68`; 517 data xrefs and zero code xrefs to UID0000WM; representative vtable triplets at `0x00610edc`, `0x0061a7fc`, `0x0061e71c`, `0x0063104c`; override decompiles at `0x004616b0`, `0x004b73b0`, `0x00504b70`, `0x005c0260`.
- Numeric tags: `int_convert.py` verified decimal `1735356263` as `0x676f6f67` and decimal `1952805485` as `0x7465726d` (Verified with `int_convert.py`).
- ChangeMan family: constructor, filtered unregister, dispatch, comparator, scalar deleting destructor, complete physical range/index pages, class/file/type support, and generated ChangeMan.cpp.
- Negative checks: no target-local padding, no extra target xrefs, no target strings, no return consumers, no listener secondary-base adjustment, no caller passing true or noncanonical values, no evidence for a source enum or explicit padding member.
- Historical report-only phase: B003 intentionally performed no IDA mutation, validator, lease, generated-file edit, or lifecycle command before Gate 1. The authorized callback later used short leases and scoped validators while preserving the no-IDA/no-manual-generated/no-lifecycle boundaries.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | IDB session `328356ab` was healthy at evidence collection; all IDB calls named the database. | Direct | fresh idb_list/server_health and successful tools/call results | UID0000ZW Evidence; report provenance | incorporated | Applied as durable evidence-time provenance; no indefinite session-availability claim. |
| C02 | UID0000ZW is exactly `0x0047ed50-0x0047ed80`, 48 bytes, one basic block, with `retn 0x10`. | Direct | lookup/get_bytes/disasm/basic_blocks | UID0000ZW Range/Raw Evidence | incorporated | Applied with exact predecessor/successor and no-owned-padding evidence; validators `9373` and final `9417` passed. |
| C03 | UID0000ZW has one direct caller UID000198 and one direct callee UID00037J; no strings or extra route. | Direct | func_profile/xrefs/callees | UID0000ZW callers/callees/negative evidence | incorporated | Applied to target caller/callee, source-route, and negative-evidence sections. |
| C04 | SortedList insert returns the insertion index, while Register and its wrapper have source return `void` because all callers discard EAX. | Direct + inference | UID00037J final `mov eax,ebx`; four caller decompiles | UID0000ZW, UID00037J, UID0000DF | incorporated | Applied; UID00037J registered/validated by `9390`, SortedList class validated by `9392`, target emits `void`. |
| C05 | ChangeMan is 8 bytes: LObject at `+0`, `SortedList *m_changeList` at `+4`; list uses element size 16, comparator, page 100. | Direct | constructor decompile/allocation arguments | UID0001TW, UID00001K, UID0000I2 | incorporated | Applied to exact layout/class/file pages; `9376`, `9387`, and `9389` passed. |
| C06 | ChangeManEntry is `{LObject *owner; LObject *listener; bool allMessages; MessageType messageType;}` with natural 3-byte padding and size 16. | Direct + source inference | target stores, dispatch, vtables, MessageType docs | UID0001TV and family users | incorporated | Applied exactly; UID0001TV validator `9375` passed and generated struct has four fields with no explicit padding member. |
| C07 | `ChangeMessageScope` and explicit padding are stale; ordinary enum ABI contradicts the one-byte store. | Direct + language ABI | byte load/store and standard enum width | UID0000ZW, UID0001TV, UID0001TW, family docs | stale model rejected | Applied throughout family/history; generated command `9417` finds no `ChangeListener`, `ChangeMessageScope`, or explicit padding scaffold in ChangeMan.cpp. |
| C08 | Target formal signature/body uses LObject/MessageType/bool, retains name Register, owner/emitter UID00001K, position 20, Nested 0, score 92/94. | Direct + inferred spelling | complete target/caller/callee pass | UID0000ZW | incorporated | Applied exactly with every preserved metadata field; generated lines 16-28 contain the one accepted body. |
| C09 | Four register calls and seven unregister calls all pass false; receivers are 3/5 BackPane and 1/2 Application respectively. | Direct | wrapper xrefs and all containing-function decompiles | UID000198, UID00019A, UID000199 | incorporated | Applied to wrapper/derived support with all counts and source expressions retained; no caller was removed or reinterpreted as a different runtime edge. |
| C10 | Register/unregister/forward wrappers are LObject members; Application/free-helper ownership is stale. | Direct + strong source inference | common-base constructor chains, thiscall ABI, address clustering | UID000198/19A/19B/199/195, LObject/Application docs | historicalized and incorporated | Validator-preserving renames `9393/9394/9395/9397`; runtime shell `9399`; LObject `9401/9402`; Application `9403/9405`. |
| C11 | LObject slot `+8` is `OnChangeMessage(LObject*,Message*)`; UID0000WM and four overrides prove it. | Direct + inferred name | vtable bytes/xrefs/dispatch/override decompiles | UID0000WM, UID00007D, UID0000KV, listener support | incorporated | Base callback `9400`, LObject declaration/file `9401/9402`, and derived support `9406-9416` passed. |
| C12 | Confirmed derived callback docs/call expressions must use the common LObject API. | Direct + source synchronization | exact register callers and vtable overrides | AboveFrame, FramePartPane, MapPane, VideoPlayerPane support | incorporated | Applied at report-level detail; FrameChrome and MapPane generated output use inherited calls and `OnChangeMessage`; Video aggregate/class stay intentionally blank. Focused commands `9458/9459/9463` restore exact report R15/R16 formatting, and literal comparison reports both destination blocks equal. |
| C13 | Filtered unregister and dispatch must use LObject/MessageType/bool names without changing exact behavior. | Direct | 0x47ed80/0x47ee20 decompiles | UID0000ZY, UID0000ZZ, UID0000ZX | incorporated | Exact branch ordering/null wildcard/removal compensation/callback preserved; validators `9378`, `9379`, and `9384` passed. |
| C14 | Broad unregister/predicate use `LObject *object`; comparator remains owner-only and scalar wrapper remains generated/no-code. | Direct + type propagation | 0x47eea0/0x47eee0/0x47ef20/0x47ef50 evidence | UID000100, UID0004I6, UID000101, UID000103 | incorporated | Applied with validators `9380-9383`; scalar wrapper retains NONE/FALSE/blank formal and comparator body remains owner-only. |
| C15 | Exact target stays standalone; parent indexes stay non-emitting; all adjacent pads remain parent-only. | Direct | bytes/boundaries and current child inventory | UID0000ZW, UID0000ZX, UID0000ZU | preserved | UID0000ZX/UID0000ZU validators `9384/9386`; final generated output has one UID0000ZW body and no index duplicate. |
| C16 | ChangeMan source remains `NexusTK/app/ChangeMan.cpp`; wrapper trio moves to `NexusTK/util/LObject.cpp`. | Strong inference | direct class owners and file routes | UID0000I2, UID0000KV, UID000195 | incorporated | Initial full refresh `9417` emitted target/family in app/ChangeMan.cpp and all three wrappers plus callback in util/LObject.cpp; final waited repair refresh `9463`/generated command `9464` preserves that result, and Application.cpp still has calls only. |
| C17 | SortedList support records `int InsertSorted(const void*)`, fixed-width copy, and ignored return at UID0000ZW. | Direct | full callee decompile/disasm | UID00037J, UID0000DF | incorporated | Applied to helper/class pages with validators `9390/9392`; target formal intentionally ignores the return. |
| C18 | Scores rise only where the new pass closes documented type/ownership/source blockers; no page is promoted to 95. | Evidence-backed assessment | blocker audit and support matrix | all listed target/support pages | incorporated | Every accepted before/after score applied exactly; highest result is 94 and all inferred-name/access caps remain explicit. |
| C19 | Historical B004/B009/B010 assumptions and command-9304 generated state remain searchable but are labeled superseded where contradicted. | Documentation comparison | executed reports/current generated output | target/support Changes and history | historicalized | Applied across target, wrappers, LObject/Application, and derived support; command `9304` is explicitly pre-callback history, superseded first by `9417` and finally by post-repair generated command `9464`. |
| C20 | Callback requires UID-preserving renames, one scoped validator per changed by-* page, and final waited generated checks. | Workflow | by-structure/skill/goal | report checklist and validator section | incorporated | All 35 changed/renamed by-* pages have scoped `ok:1` validators, focused MapPane repairs passed `9458/9459/9463`, all short leases were released, waited `9463` completed fresh generation, and generated MapPane command `9464` verifies the exact R15/R16 result. |

## Positive Evidence Summary

- The target's complete 18-instruction body performs only four record stores and one list call; no branch or return conversion complicates reconstruction.
- The one-byte load/store at `+0x08`, dword at `+0x0c`, and 16-byte list element size jointly prove layout and natural padding.
- The wrapper's exact `push scope; push messageType; push listener; push ecx; mov ecx,g_pChangeMan; call; retn 0x0c` is exactly the shape of an inherited three-argument LObject member forwarding its `this` pointer as owner.
- Application and BackPane both call LObject construction at object offset zero through direct constructor chains, closing the only blocker cited by the previous B004 wrapper report.
- The LObject and four representative derived vtables all place the callback at slot `+0x08`; the callback bodies consume a `Message *` at their second explicit argument.
- UID00037J's explicit `mov eax, ebx` proves its return; the total absence of Register return use proves the source API need not expose it.

## IDA MCP Facts

- Target bytes: `55 8b ec 83 ec 10 8b 45 08 8b 49 04 89 45 f0 8b 45 0c 89 45 f4 8a 45 14 88 45 f8 8b 45 10 89 45 fc 8d 45 f0 50 e8 16 49 07 00 8b e5 5d c2 10 00`.
- Target stack record: owner `[ebp+8] -> local+0`, listener `[ebp+0xc] -> local+4`, low byte `[ebp+0x14] -> local+8`, message type `[ebp+0x10] -> local+0xc`.
- Target predecessor byte `0x0047ed4f` is `cc`; successor UID0000ZY begins at `0x0047ed80`. UID0000ZW owns no padding. Eight `cc` bytes at `0x0047ee18-0x0047ee20` belong after the unregister child and remain parent-index alignment.
- UID00037J is `0x004f3690-0x004f377b`, 96 instructions/15 blocks, scans with comparator at `+0x14`, grows/copies fixed-width storage, increments count at `+0x0c`, returns EBX insertion index, and executes `retn 4`.
- Wrapper exact ranges: register `0x004f4b30-0x004f4b4c`, four `cc`; unregister `0x004f4b50-0x004f4b6c`, four `cc`; forward `0x004f4b70-0x004f4b86`, ten `cc` through `0x004f4b90`.
- LObject vtable bytes at `0x0061cf68`: `0x004f4b90`, `0x004f4b10`, `0x0041b6c0`. UID0000WM has 517 data xrefs and zero code xrefs.
- Representative third-slot overrides: AboveFrame `0x004616b0`, FramePartPane `0x004b73b0`, MapPane `0x00504b70`, VideoPlayerPane `0x005c0260`.
- Comparator `0x0047ef20-0x0047ef3f` compares only first dwords and has one constructor data xref at `0x0047ece4`.
- Scalar deleting destructor `0x0047ef50-0x0047efae` has one vtable data xref, destroys `m_changeList`, clears the singleton, invokes LObject cleanup, and conditionally frees storage. It remains compiler-generated/no-code.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0047ec70-0x0047ed20` | UID0000ZT ChangeManConstructor | constructor | true | UID00001K | unchanged by this target | existing exact child |
| `0x0047ed20-0x0047ed50` | UID0000ZV cleanup | compiler cleanup | false | none | unchanged | existing exact child |
| `0x0047ed50-0x0047ed80` | UID0000ZW ChangeManRegister | target method | true | UID00001K | `86/90 -> 92/94` | corrected formal/source types |
| `0x0047ed80-0x0047ee18` | UID0000ZY filtered unregister | paired method | true | UID00001K | `86/90 -> 91/94` | synchronize types |
| `0x0047ee18-0x0047ee20` | parent-only padding | alignment | false | UID0000ZU index | n/a | preserve |
| `0x0047ee20-0x0047ee95` | UID0000ZZ dispatch | callback method | true | UID00001K | `88/91 -> 92/94` | synchronize callback/types |
| `0x0047eea0-0x0047eedf` | UID000100 broad unregister | cleanup method | true | UID00001K | `88/92 -> 90/94` | use LObject pointer |
| `0x0047eee0-0x0047ef1f` | UID0004I6 predicate | retained method | true | UID00001K | `88/91 -> 90/93` | use LObject pointer |
| `0x0047ef20-0x0047ef3f` | UID000101 comparator | file helper | true | UID0000I2 | `86/91 -> 90/94` | type sync, body unchanged |
| `0x0047ef50-0x0047efae` | UID000103 scalar deleting destructor | compiler output | false | none | `86/91 -> 88/93` | blank formal preserved |
| `0x004f3690-0x004f377b` | UID00037J SortedListInsertSorted | list helper | true | UID0000DF | `88/91 -> 91/94` | exact int return documented |
| `0x004f4b30-0x004f4b4c` | UID000198 | LObject register wrapper | true | UID00007D | `88/90 -> 92/94` | UID-preserving rename/reclassify |
| `0x004f4b50-0x004f4b6c` | UID00019A | LObject unregister wrapper | true | UID00007D | `88/90 -> 92/94` | UID-preserving rename/reclassify |
| `0x004f4b70-0x004f4b86` | UID00019B | LObject forward wrapper | true | UID00007D | `86/92 -> 91/94` | UID-preserving rename/reclassify |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f4b43` | UID000198 -> UID0000ZW | sole direct target caller |
| `0x0047ed75` | UID0000ZW -> UID00037J | sole target callee |
| `0x00461275` | AboveFrame constructor | `g_pBackPane->RegisterChangeListener(this, 0x676f6f67, false)` source shape |
| `0x004b74fc` | FramePartPane constructor | same BackPane owner/tag/false shape |
| `0x005043bb` | MapPane constructor | same BackPane owner/tag/false shape |
| `0x005c0151` | VideoPlayerPane open path | `g_pApplication->RegisterChangeListener(this, 0x7465726d, false)` source shape |
| `0x004612ed`, `0x00461734` | AboveFrame destructor/deleting wrapper | BackPane unregister, same listener/tag/false |
| `0x004b756d`, `0x004b7604` | FramePartPane destructor/deleting wrapper | BackPane unregister, same listener/tag/false |
| `0x00504584` | MapPane cleanup | BackPane unregister, same listener/tag/false |
| `0x005c00dd`, `0x005c03f4` | VideoPlayerPane destructor/deleting wrapper | Application unregister, listener/tag/false |
| `0x00464ac2`, `0x004679a2` | Application cleanup/shutdown message paths | call inherited LObject forward wrapper with Message pointer |

## Documentation Evidence And IDA Status

- UID0001TV/UID0001TW already record correct offsets and size but use source-incompatible enum/interface/padding names.
- UID0000DF/UID00037J already document most insert behavior; the missing source-quality point is that the helper's real `int` return is intentionally discarded by a `void` manager API.
- UID000198's executed B004 report correctly rejected Application class ownership and explicitly left LObject unresolved for lack of common-base proof. The new constructor-chain evidence closes that exact historical blocker.
- UID0000WM explicitly left callback semantics unresolved until a caller proved them. UID0000ZZ supplies that proof through the primary vtable slot and two explicit pointer arguments.
- Historical generated command 9304 reproduced the pre-callback docs, including stale free helpers, `ChangeListener`, `ChangeMessageScope`, and explicit padding. It is retained only as a read-only baseline; completed command 9417 verifies those choices were replaced.

## Ranked Ownership Analysis

### 1. ChangeMan class UID00001K for UID0000ZW

- Evidence for: target reads `this+4` as the registration list, is adjacent to the constructor/unregister/dispatch family, and is inserted through the ChangeMan class emitter.
- Evidence against: none. Exact original source filename/header spelling remains inferred but does not weaken direct class ownership.
- Decision: retain canonical owner/emitter UID00001K and source route UID0000I2.

### 2. LObject class UID00007D for the forwarding trio

- Evidence for: all receiver objects share LObject at offset zero; exact `__thiscall` ABIs use ECX as owner; the trio is physically between LObject runtime methods; dispatch uses LObject's third virtual slot.
- Evidence against: no surviving symbol names these three members and UID00019B currently has only Application callers.
- Decision: source ownership is still strongest at LObject. UID00019B's identical forwarding shape and physical adjacency outweigh its narrower observed caller set.

### 3. Application class/file

- Evidence for: one register owner, two unregister owners, and both forward callers are Application objects; historical generated output routes the wrappers through Application.cpp.
- Evidence against: most register/unregister owners are BackPane; Application-only membership cannot explain those calls; free-helper source cannot naturally reproduce `__thiscall`/`retn 0x0c` without nonstandard declarations.
- Decision: reject as direct wrapper owner. Application retains only inherited use and support wording.

### 4. ChangeMan file/class for the wrappers

- Evidence for: wrappers load `g_pChangeMan` and call ChangeMan methods.
- Evidence against: their receiver is the owner LObject, not ChangeMan, and they sit outside the ChangeMan range/source island.
- Decision: reject direct ownership; ChangeMan remains the routed subsystem.

## Source Placement

- UID0000ZW and all ChangeMan data/method synchronization remain in `NexusTK/app/ChangeMan.cpp` through UID00001K -> UID0000I2.
- UID000198, UID00019A, UID00019B, UID000199 wording, and UID0000WM semantic callback belong to `NexusTK/util/LObject.cpp` / `LObject.h` through UID00007D -> UID0000KV.
- Application.cpp remains a consumer route. Unqualified calls inside Application methods are valid inherited LObject member calls; they do not justify duplicate Application definitions.
- FrameChrome/MapPane/VideoPlayerPane retain their existing source-file ownership. Only call expressions and callback override names/types synchronize with the common LObject API.
- Rejected placements: a new ChangeListener source file/interface, an Application helper island, duplicate wrappers in ChangeMan.cpp, and a broad combined registration source child.

## Range / Split / Padding / Reclassification Analysis

- UID0000ZW exact half-open range remains `0x0047ed50-0x0047ed80`. It contains the prologue, 16-byte local record, one call, epilogue, and `retn 0x10` with no internal or trailing padding.
- Byte `0x0047ed4f` is predecessor alignment. UID0000ZY starts exactly at `0x0047ed80`. No boundary change is recommended.
- UID0000ZX remains the exact pair index over UID0000ZW/UID0000ZY, `RECONSTRUCTABLE:FALSE`, owner none, emitter blank, formal blank.
- UID0000ZU remains the complete physical ChangeMan index with exact child/padding inventory, `RECONSTRUCTABLE:FALSE`, owner none, emitter blank, formal blank.
- The four-byte pads at `0x004f4b4c-0x004f4b50` and `0x004f4b6c-0x004f4b70`, and ten-byte pad at `0x004f4b86-0x004f4b90`, remain parent-only alignment in UID000195/UID000199 inventories.
- Reclassification, not split, is required for the three exact wrapper pages and the wrapper-pair aggregate title/path. Preserve all UIDs and exact endpoints through validator-managed rename workflow.

## Negative Evidence Summary

- No target string, data xref, second caller, second callee, exception path, branch, or internal pad suggests a broader body.
- No caller stores/tests EAX from register; no evidence supports an API return even though the sorted-list helper returns an index.
- No caller passes true or any noncanonical byte. Invalid byte behavior remains binary defensive/undefined-state evidence, not proof of a wider source enum.
- No separate listener vptr or `this` adjustment appears. A second `ChangeListener` base/interface would require evidence that is absent and conflicts with primary-slot dispatch.
- Application consumer xrefs do not prove Application ownership. Nearby ChangeMan access does not prove wrapper ownership either; receiver and class construction evidence control.
- Physical adjacency alone is not the ownership proof. It corroborates the independent common-base/ABI proof.
- No symbol proves `Register`, `allMessages`, or `OnChangeMessage`; those are best source-facing inferred names and remain a confidence cap.

## IDA Rename / Type / Comment Recommendations

- Source-facing target prototype: `void ChangeMan::Register(LObject *owner, LObject *listener, MessageType messageType, bool allMessages)`.
- Source-facing record fields: `owner`, `listener`, `allMessages`, `messageType`; omit explicit padding member.
- Source-facing LObject API: `RegisterChangeListener`, `UnregisterChangeListener`, `ForwardMessage`, and virtual `OnChangeMessage`.
- Preserve current IDA `sub_` names in this report as search aliases. No IDA DB rename/type/comment mutation was requested or performed.
- If a later supervised IDA mutation pass is authorized, apply semantic prototypes only after the documentation callback; do not encode the rejected `ChangeListener` or enum types.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. UID0000ZW is project source with a confirmed route and combined score above the code gate.
- Exact target formal block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ChangeMan::Register(LObject *owner,
                         LObject *listener,
                         MessageType messageType,
                         bool allMessages)
{
    ChangeManEntry entry;
    entry.owner = owner;
    entry.listener = listener;
    entry.allMessages = allMessages;
    entry.messageType = messageType;

    m_changeList->InsertSorted(&entry);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact UID0001TV formal block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ChangeManEntry {
    LObject *owner;
    LObject *listener;
    bool allMessages;
    MessageType messageType;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact UID0001TW formal block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChangeMan : public LObject {
public:
    ChangeMan();
    virtual ~ChangeMan();

    void Register(LObject *owner,
                  LObject *listener,
                  MessageType messageType,
                  bool allMessages);
    void Unregister(LObject *owner,
                    LObject *listener,
                    MessageType messageType,
                    bool allMessages);
    void DispatchMessage(LObject *owner, Message *message);
    void UnregisterObject(LObject *object);
    bool HasRegistrationForObject(LObject *object);

private:
    SortedList *m_changeList;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact UID000198 formal block after UID-preserving rename to `LObjectRegisterChangeListener`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LObject::RegisterChangeListener(LObject *listener,
                                     MessageType messageType,
                                     bool allMessages)
{
    g_pChangeMan->Register(this, listener, messageType, allMessages);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact UID00019A formal block after UID-preserving rename to `LObjectUnregisterChangeListener`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LObject::UnregisterChangeListener(LObject *listener,
                                       MessageType messageType,
                                       bool allMessages)
{
    g_pChangeMan->Unregister(this, listener, messageType, allMessages);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact UID00019B formal block after UID-preserving rename to `LObjectForwardMessage`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LObject::ForwardMessage(Message *message)
{
    g_pChangeMan->DispatchMessage(this, message);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact UID0000WM formal block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LObject::OnChangeMessage(LObject *, Message *)
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact UID00007D LObject declaration/emitter block. `RuntimeClass` is a descriptive forward declaration for the already-documented slot-`+0x04` accessor, not a new claim about the unresolved runtime-class record's original type name. Placing `[[CHILDREN]]` after the closed class keeps all method definitions at namespace scope:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct RuntimeClass;
class Message;

class LObject {
public:
    LObject();
    virtual ~LObject();
    virtual RuntimeClass *GetRuntimeClass();
    virtual void OnChangeMessage(LObject *owner, Message *message);

    void RegisterChangeListener(LObject *listener,
                                MessageType messageType,
                                bool allMessages);
    void UnregisterChangeListener(LObject *listener,
                                  MessageType messageType,
                                  bool allMessages);
    void ForwardMessage(Message *message);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact UID0000ZY and UID0000ZZ coordinated blocks:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ChangeMan::Unregister(LObject *owner,
                           LObject *listener,
                           MessageType messageType,
                           bool allMessages)
{
    ChangeManEntry key;
    key.owner = owner;

    int index = m_changeList->FindFirstEqual(&key);
    if (index < 0)
        return;

    int count = m_changeList->GetCount();
    for (; index < count; ++index) {
        ChangeManEntry *entry =
            static_cast<ChangeManEntry *>(m_changeList->GetElementAt(index));
        if (entry == NULL || entry->owner != owner)
            break;

        const bool listenerMatches =
            (listener == NULL || entry->listener == listener);
        const bool messageMatches =
            (allMessages == true) ||
            (allMessages == false && entry->messageType == messageType);

        if (listenerMatches && messageMatches) {
            m_changeList->RemoveRange(index, 1);
            --index;
            --count;
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ChangeMan::DispatchMessage(LObject *owner, Message *message)
{
    ChangeManEntry key;
    key.owner = owner;

    int index = m_changeList->FindFirstEqual(&key);
    if (index < 0)
        return;

    int count = m_changeList->GetCount();
    for (; index < count; ++index) {
        ChangeManEntry *entry =
            static_cast<ChangeManEntry *>(m_changeList->GetElementAt(index));
        if (entry->owner != owner)
            break;

        if (entry->allMessages == true ||
            (entry->allMessages == false &&
             entry->messageType == message->m_type)) {
            entry->listener->OnChangeMessage(owner, message);
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact UID000100 and UID0004I6 coordinated blocks:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ChangeMan::UnregisterObject(LObject *object)
{
    for (int index = m_changeList->GetCount() - 1; index >= 0; --index) {
        ChangeManEntry *entry =
            static_cast<ChangeManEntry *>(m_changeList->GetElementAt(index));
        if (entry->owner == object || entry->listener == object)
            m_changeList->RemoveRange(index, 1);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ChangeMan::HasRegistrationForObject(LObject *object)
{
    for (int index = m_changeList->GetCount() - 1; index >= 0; --index) {
        ChangeManEntry *entry =
            static_cast<ChangeManEntry *>(m_changeList->GetElementAt(index));
        if (entry->owner == object || entry->listener == object)
            return true;
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact confirmed listener/caller formal changes are listed under `Recommended Support Doc Changes`; each listed C++ destination receives a complete managed block during callback, not a body-only snippet.
- Behavior fidelity: the target retains exact field-store order and ignores only the helper return that source callers do not use. Natural padding preserves size and leaves bytes `+9..+0xb` unwritten.
- Human source shape: a small manager record, base-object notification API, typedef'd message key, and bool all-message selector are plausible mid-2000s C++ and eliminate decompiler/interface scaffolding.
- Third-party import directive: not applicable; this is NexusTK project code.

## Final Recommendation

- C01-C20 are applied without changing UID0000ZW's range, owner, emitter, reconstructable state, nesting, or standalone disposition.
- UID0000ZW now has position `20`, target score `92/94`, and the exact formal block above.
- ChangeMan entry/layout/method/class/file/index/compiler/list support is synchronized at report-level detail with exact boundaries, invalid-byte negative evidence, no-code compiler output, and rejected aggregate emission preserved.
- UID000198, UID00019A, UID00019B, and UID000199 are validator-renamed to LObject paths with UIDs/endpoints preserved; UID000195, LObject, and Application inventories/history are synchronized.
- The proven LObject callback and all confirmed source call expressions/override pages are normalized; unrelated class behavior and scores remain unchanged except for the accepted movements below.
- No new source file, target split, new UID, IDA mutation, or manual generated/tracker/coverage edit occurred.

## Recommended Target Doc Changes

- Implemented target path: `by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md`.
- Applied `COMPLETION:92`, `CONFIDENCE:94`, `EMITTER_POSITION_OPTIONAL:20`; preserved UID0000ZW, owner/emitter UID00001K, `RECONSTRUCTABLE:TRUE`, `Nested:0`, exact range, and source module UID0000I2.
- Inserted the exact managed target block above.
- Replaced field table/source signature/return rationale with LObject/MessageType/bool/natural-padding facts, exact helper `int` return and ignored-use proof, all caller/callee facts, ABI explanation, source name inference, and negative alternatives.
- Applied Item Summary: `Exact ChangeMan registration method; live IDA proves the 0x30-byte/retn-0x10 body, 16-byte naturally padded LObject/LObject/bool/MessageType record, sole LObject register-wrapper caller, sole int-returning SortedList insert callee, ignored result, exact boundaries, and class emitter position 20.`
- Historicalized B010/pre-callback `ChangeListener`, `ChangeMessageScope`, explicit padding, and Application-helper claims; retained them only as superseded searchable history.

## Recommended Support Doc Changes

All rows in this accepted matrix are implemented exactly; the table retains the Gate-1 recommendation wording as the destination-specific audit baseline.

| Support path / UID | Exact incorporation | Metadata / formal disposition |
| --- | --- | --- |
| `by-type/by-struct/ChangeManEntry.md` UID0001TV | Replace enum/interface/padding with exact LObject/LObject/bool/MessageType layout; preserve offset/size/invalid-byte evidence. | `88/91 -> 92/94`; exact block above. |
| `by-type/by-struct/ChangeManLayout.md` UID0001TW | Synchronize full method surface and object/list layout. | `89/92 -> 92/94`; exact block above. |
| UID0000ZY filtered unregister | Synchronize types/names, preserve null-listener wildcard, exact true/false branch ordering, same-owner scan, removal compensation. | `86/90 -> 91/94`; exact block above. |
| UID0000ZZ dispatch | Synchronize LObject callback and bool field, preserve owner lower-bound, Message+4 comparison, slot+8 behavior. | `88/91 -> 92/94`; exact block above. |
| UID000100 / UID0004I6 | Use `LObject *object`; preserve reverse scans, mutation/predicate distinction, retained/no-route history. | `88/92 -> 90/94`; `88/91 -> 90/93`; exact blocks above. |
| UID000101 comparator | Keep body exactly owner-only; remove void-owner wording and tie to new record type. | `86/91 -> 90/94`; formal body unchanged. |
| UID000103 scalar deleting destructor | Preserve no-owner, false, blank emitter/formal and compiler-generation proof; add current exact destructor/list/type evidence. | `86/91 -> 88/93`; no code. |
| UID0000ZX / UID0000ZU | Preserve non-emitting index roles and all padding/child inventory; synchronize source types and wrapper route. | `89/92 -> 92/94`; `92/93 -> 94/94`; blank formal preserved. |
| UID00001K / UID0000I2 | Synchronize class/file responsibility, type declarations, method map, wrapper consumer route, and stale assumptions. | `90/92 -> 93/94`; `90/91 -> 93/94`; existing destructor/children/comparator blocks otherwise unchanged. |
| UID00037J / UID0000DF | Add exact `int InsertSorted(const void *element)` return contract, copy behavior, and ignored target use; preserve list layout/source split caveat. | `88/91 -> 91/94`; `89/89 -> 91/90`; no new helper body required by this target. |
| UID000198 | Validator-rename path to `by-memory/0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener.md`; preserve UID/range/Nested 0, change owner/emitter to UID00007D, use exact block. | `88/90 -> 92/94`. |
| UID00019A | Validator-rename path to `by-memory/0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md`; same ownership/type policy. | `88/90 -> 92/94`. |
| UID00019B | Validator-rename path to `by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md`; preserve exact range and Application caller evidence as inherited use. | `86/92 -> 91/94`. |
| UID000199 | Validator-rename path/title to `by-memory/0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers.md`; preserve no-owner/false/blank formal and exact padding. | `86/92 -> 90/94`. |
| UID000195 runtime shell | Correct source table from Application helpers to LObject members; preserve MemoryMan/CRT mixed ownership and all pads. | `86/91 -> 90/93`; no emission. |
| UID0000WM | Rename semantic method from `VirtualNoop` to `OnChangeMessage`, add dispatch/override proof, retain 517 data/0 code refs and exact 3-byte body. | `88/91 -> 92/94`; exact block above. |
| UID00007D / UID0000KV | Add register/unregister/forward public API and common callback responsibility; preserve runtime-class and string-family exclusions. | each `86/87 -> 90/92`; apply the exact class/emitter block above while keeping the runtime record type name explicitly descriptive. |
| Application class UID00000D / file UID0000HG | Remove direct/free-helper ownership; record inherited LObject use and retain Application-specific callers/constructor facts. | `87/90 -> 88/92`; `88/91 -> 89/92`; do not move unrelated Application children. |
| UID0000YH / AboveFrame class UID000005 | Preserve aggregate blank formal and frame behavior; normalize class declaration callback to `OnChangeMessage(LObject*, Message*)`; document BackPane inherited registration expression. | aggregate `88/91 -> 89/93`; class `87/91 -> 88/92`. |
| UID00015O / FramePartPane class UID00005I | In the existing complete aggregate block, use `g_pBackPane->RegisterChangeListener(this, tag, false)`, matching unregister call, and `OnChangeMessage(LObject*,Message*)`; preserve paint/lifecycle. | aggregate `87/91 -> 89/93`; class `86/90 -> 87/92`. |
| Map UID0002I7 / UID0002QF / UID0002QI / class UID00007Q | Correct constructor/destructor owner-call expressions and replace fake TaggedPaneMessage callback with common Message/LObject override; preserve all unrelated map behavior. | `88/89 -> 89/91`; `88/90 -> 89/92`; `88/91 -> 91/94`; class `88/87 -> 89/89`. |
| Video UID0001NT / class UID0000FV | Document inherited Application-owner calls and normalize `OnMessage` to the common LObject override; preserve Bink behavior and blank aggregate formal. | `87/91 -> 89/93`; `88/88 -> 89/90`. |

Exact managed formal text for the three directly emitting confirmed listener/caller support repairs:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class AboveFrame : public Pane
{
public:
    AboveFrame(int frameIndex, int top, int left);
    virtual ~AboveFrame();

protected:
    virtual void OnPaint();
    virtual void OnChangeMessage(LObject *owner, Message *message);

private:
    EPFTileContext m_tileContext;
    RectBounds m_tileBounds;
    RectBounds m_positionedBounds;
    unsigned char m_framePaletteMode;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FramePartPane::FramePartPane(int partIndex, const Rect& bounds)
    : Pane(1),
      m_partIndex(partIndex)
{
    AddToLayer(bounds, 0, 0, g_pMainLayer);
    g_pBackPane->RegisterChangeListener(
        this, kFramePartNotificationTag, false);
}

FramePartPane::~FramePartPane()
{
    g_pBackPane->UnregisterChangeListener(
        this, kFramePartNotificationTag, false);
    RemoveFromLayer();
}

void FramePartPane::OnChangeMessage(LObject *, Message *message)
{
    if (message->m_type != kFramePartNotificationTag)
        return;

    g_pBlackHole->QueuePaneForDeferredDeletion(this);

    for (int index = 0; index < 5; ++index)
        g_framePartPanes[index] = NULL;
}

int FramePartPane::OnPaintFrame()
{
    EPFTileContext tile;
    tile.Init();

    const wchar_t* resourceName =
        g_useEpfAssets ? L"FRMPART.EPF" : L"FRMPART.EPD";
    g_pEPFLib->LookupLayoutEntry(resourceName, m_partIndex, &tile);

    return RenderTileFrame(&tile, GetPaintBounds(), 0, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const MessageType kPaneTagGoog = 0x676f6f67;

void MapPane::OnChangeMessage(LObject *, Message *message)
{
    if (message->m_type == kPaneTagGoog)
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact UID0002I7 formal block, preserving its accepted constructor content while correcting only the inherited registration expression:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapPane::MapPane(int visibleTileColumns, int visibleTileRows)
    : Pane(0),
      m_layerStates(),
      m_viewportGrafPort(),
      m_screenEffecters(NULL),
      m_screenEffecterCount(0),
      m_screenEffecterCapacity(0),
      m_selectionOverlay(NULL),
      m_tileBuffer(NULL),
      m_visibleTileColumns(visibleTileColumns),
      m_visibleTileRows(visibleTileRows),
      m_objectListDetachPreserve(NULL),
      m_auxiliaryPane(NULL),
      m_activeScreenLayer(NULL),
      m_objectList(NULL)
{
    g_activeMapPane = this;

    m_mapId = 0;
    m_mapWidth = 0;
    m_mapHeight = 0;
    m_mapRuntimeState.Clear();
    m_runtimeFlags = 0;
    m_movementGate = 0;

    Rect mapBounds;
    mapBounds.left = 0;
    mapBounds.top = 0;
    mapBounds.right = g_mapTilePixelWidth * (visibleTileColumns + 2);
    mapBounds.bottom = g_mapTilePixelHeight * (visibleTileRows + 2);
    SetBounds(mapBounds);

    if (g_objectNationMap == NULL) {
        DataFile objectTable;
        if (objectTable.Open("SOBJ.TBL")) {
            std::uint16_t tableHeader = 0;

            objectTable.Read(&g_objectRecordCount, sizeof(g_objectRecordCount));
            objectTable.Read(&tableHeader, sizeof(tableHeader));

            g_objectNationMap = new std::uint8_t[g_objectRecordCount + 1];
            g_objectNationMap[0] = 0;

            for (std::uint32_t index = 1; index < g_objectRecordCount; ++index) {
                std::uint32_t objectId = 0;
                std::uint8_t sourceNationOrClass = 0;
                std::uint8_t objectNation = 0;
                std::uint8_t extraWordCount = 0;

                objectTable.Read(&objectId, sizeof(objectId));
                objectTable.Read(&sourceNationOrClass, sizeof(sourceNationOrClass));
                objectTable.Read(&objectNation, sizeof(objectNation));
                objectTable.Read(&extraWordCount, sizeof(extraWordCount));

                g_objectNationMap[index] = objectNation;

                for (std::uint8_t extraIndex = 0;
                     extraIndex < extraWordCount;
                     ++extraIndex) {
                    std::uint16_t ignoredWord = 0;
                    objectTable.Read(&ignoredWord, sizeof(ignoredWord));
                }
            }
        }
    }

    BackPane *backPane = BackPane::GetActive();
    if (backPane != NULL) {
        Rect backBounds;
        backPane->GetBounds(&backBounds);
        backPane->RegisterChangeListener(this, kMapPaneChangeTag, false);
        m_selectionOverlay = new AlphaMaskSurface(backBounds);
    }

    if (g_gameServerNationTable == NULL) {
        g_gameServerNationTable = new GameServerConfig;
    }

    m_screenEffecterCount = 0;
    m_screenEffecterCapacity = 0;
    m_screenEffecters = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact UID0002QF formal block, preserving its accepted destructor content while correcting only the inherited unregister expression:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapPane::~MapPane()
{
    ClearScreenEffecterList();
    g_pBackPane->UnregisterChangeListener(this, kMapPaneChangeTag, false);
    SaveCompressedMapFile();

    if (m_auxiliaryPane != NULL) {
        delete m_auxiliaryPane;
        m_auxiliaryPane = NULL;
    }

    if (m_activeScreenLayer != NULL) {
        if (g_pScreenPane != NULL) {
            g_pScreenPane->RemoveLayer(m_activeScreenLayer);
        }
        delete m_activeScreenLayer;
        m_activeScreenLayer = NULL;
    }

    if (m_objectList != NULL) {
        m_objectList->DetachAll(m_objectListDetachPreserve);
        m_objectList->DestroyOwnedObjects();
        delete m_objectList;
        m_objectList = NULL;
        m_objectListDetachPreserve = NULL;
    }

    FreeBufferMemory(g_objectNationMap);
    g_objectNationMap = NULL;
    g_objectRecordCount = 0;

    delete m_selectionOverlay;
    m_selectionOverlay = NULL;

    delete g_gameServerNationTable;
    g_gameServerNationTable = NULL;

    if (g_pSoundManager != NULL) {
        g_pSoundManager->CloseRedbookDevice();
    }

    if (g_activeMapPane == this) {
        g_activeMapPane = NULL;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Score And Metadata Recommendation

- Historical pre-callback target: `86/90`, UID00001K owner/emitter, true, blank position, Nested 0.
- Implemented target: `92/94`, UID00001K owner/emitter, true, position `20`, Nested 0.
- Score rationale: completion rises because signature, helper return, record types, common-base wrapper source, callback interface, formal body, caller/callee inventory, and boundary/padding questions are closed. Confidence rises because all machine claims are live-IDB direct and the previous wrapper-owner blocker is resolved.
- Reason not higher: no PDB/header/source symbol proves exact `Register`, `allMessages`, `OnChangeMessage`, access specifiers, or original typedef spelling. The bool choice is the strongest ABI/source inference but is not source-text recovery.
- Score-improvement attempt: every named blocker in goal.md was exercised through exact target bytes/ABI, all callers, all callees, sorted helper body, ChangeMan constructor/layout, wrapper ownership, common-base construction, vtable callback proof, existing formal blocks, generated state, and matching reports. No blocker remains as an unresearched future task.
- Metadata preserved: exact target UID/path/range, owner UID00001K, emitter UID00001K, reconstructable true, Nested 0.
- Metadata changed: target position to 20; wrapper owner/emitter/path/title corrections and score movements listed in the support matrix are applied.

## Open Questions With Attempted Resolution

- Exact original manager method spelling: checked symbols, neighboring API, wrapper names, old reports, and generated docs. No symbol survives. `Register` is retained as the best coherent inferred name; this limits confidence only.
- `bool` versus `unsigned char`: checked ABI width, all 11 caller values, dispatch/unregister branches, standard enum width, record alignment, and source semantics. `bool allMessages` is the best human source representation; invalid bytes remain negative binary evidence outside valid source states.
- Listener interface: checked primary LObject and four derived vtables, callback bodies, object inheritance, and pointer adjustments. Resolved as LObject virtual; a separate interface is rejected.
- Wrapper source placement: checked exact ABI, every receiver, both constructor chains, physical island, sibling forwarder, and prior B004 rationale. Resolved as LObject members.
- Register return: checked helper return assembly, wrapper assembly, all four callers, and sibling stale-return patterns. Resolved as source `void`.
- Exact access qualifiers/header split: no symbol survives. Public LObject notification API and public ChangeMan registration surface are the only call-compatible ordinary C++ shape without unproved friendship. This remains inferred and is reflected in scores, not a code blocker.
- No unresolved in-scope question prevents the exact formal blocks or ownership/range recommendation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. UID0000ZW's tracker/coverage state is validator-owned auto-generated output.
- The callback updated source page metadata/Item Summary through by-* edits and validator flow. B003 did not hand-edit `auto-generated/-ag-*`, manual coverage, or supervisor tracker files.

## Follow-Up Actions

- Report validation, implementation acceptance, execution, count, path, move, and archive state are external supervisor/validator-owned and are neither asserted nor directed by this artifact.
- A-agent actions: none required for UID0000ZW.
- B003 implementation/research items remaining: none for the assigned blockers. The broader LObject runtime-class declaration remains independent of this target and is not used to defer the proven notification API.

## Confidence

- Recommendation confidence: `94/100` for target behavior/ABI/ownership and `92/100` for exact human source spelling.
- Score confidence: high; all score movements are tied to specific closed blockers and no 95-level source-symbol claim is made.
- Remaining uncertainty: exact original identifiers/access/header organization only. None changes runtime behavior, range, owner, emitter, or the first-draft body.

## Validator Results

- Invocation policy: every command used `--mode file --file <one-by-*-page> --apply --queue-timeout 240`; commands `000000009417`, `000000009459`, and `000000009463` additionally used `--wait-generated`. Every command exited `0` with `ok:1`.

| Command ID | Timestamp (`-04:00`) | Scoped page / result | Exit / ok | Generated state |
| --- | --- | --- | --- | --- |
| `000000009373` | `2026-07-13T06:46:30` | UID0000ZW target `86/90 -> 92/94`, position/code/evidence | `0 / 1` | deferred; initial missing UID00037J warning before its registration |
| `000000009375` | `2026-07-13T06:47:28` | UID0001TV ChangeManEntry `88/91 -> 92/94` | `0 / 1` | deferred |
| `000000009376` | `2026-07-13T06:48:18` | UID0001TW ChangeManLayout `89/92 -> 92/94` | `0 / 1` | deferred |
| `000000009378` | `2026-07-13T06:49:00` | UID0000ZY filtered unregister `86/90 -> 91/94` | `0 / 1` | deferred |
| `000000009379` | `2026-07-13T06:49:30` | UID0000ZZ dispatch `88/91 -> 92/94` | `0 / 1` | deferred |
| `000000009380` | `2026-07-13T06:49:59` | UID000100 broad unregister `88/92 -> 90/94` | `0 / 1` | deferred |
| `000000009381` | `2026-07-13T06:50:28` | UID0004I6 predicate `88/91 -> 90/93` | `0 / 1` | deferred |
| `000000009382` | `2026-07-13T06:51:11` | UID000101 comparator `86/91 -> 90/94` | `0 / 1` | deferred |
| `000000009383` | `2026-07-13T06:51:41` | UID000103 scalar wrapper `86/91 -> 88/93` | `0 / 1` | deferred |
| `000000009384` | `2026-07-13T06:52:35` | UID0000ZX pair index `89/92 -> 92/94` | `0 / 1` | deferred |
| `000000009386` | `2026-07-13T06:53:41` | UID0000ZU physical index `92/93 -> 94/94` | `0 / 1` | deferred |
| `000000009387` | `2026-07-13T06:54:36` | UID00001K ChangeMan class `90/92 -> 93/94` | `0 / 1` | deferred |
| `000000009389` | `2026-07-13T06:55:44` | UID0000I2 ChangeMan file `90/91 -> 93/94` | `0 / 1` | deferred |
| `000000009390` | `2026-07-13T06:56:28` | UID00037J InsertSorted `88/91 -> 91/94`; fresh UID registration completed | `0 / 1` | deferred |
| `000000009392` | `2026-07-13T06:57:09` | UID0000DF SortedList class `89/89 -> 91/90` | `0 / 1` | deferred; 18 pre-existing sibling missing-ref warnings |
| `000000009393` | `2026-07-13T06:58:43` | UID000198 validator path update to LObject register; 26 propagated links | `0 / 1` | deferred |
| `000000009394` | `2026-07-13T06:59:58` | UID00019A validator path update to LObject unregister; 25 propagated links | `0 / 1` | deferred |
| `000000009395` | `2026-07-13T07:01:11` | UID00019B validator path update to LObject forward; 45 propagated links | `0 / 1` | deferred |
| `000000009397` | `2026-07-13T07:03:33` | UID000199 validator path update to LObject wrapper index; 23 propagated links | `0 / 1` | deferred |
| `000000009399` | `2026-07-13T07:04:51` | UID000195 runtime shell `86/91 -> 90/93` | `0 / 1` | deferred |
| `000000009400` | `2026-07-13T07:06:01` | UID0000WM callback `88/91 -> 92/94` | `0 / 1` | deferred |
| `000000009401` | `2026-07-13T07:09:23` | UID00007D LObject class `86/87 -> 90/92`; validator normalized wrapper links | `0 / 1` | deferred |
| `000000009402` | `2026-07-13T07:10:27` | UID0000KV LObject file `86/87 -> 90/92` | `0 / 1` | deferred |
| `000000009403` | `2026-07-13T07:12:25` | UID00000D Application class `87/90 -> 88/92` | `0 / 1` | deferred |
| `000000009405` | `2026-07-13T07:13:54` | UID0000HG Application file `88/91 -> 89/92` | `0 / 1` | deferred; two pre-existing UID0003OY warnings |
| `000000009406` | `2026-07-13T07:14:54` | UID0000YH AboveFrame aggregate `88/91 -> 89/93` | `0 / 1` | deferred; two pre-existing UID0003I2 warnings |
| `000000009407` | `2026-07-13T07:15:40` | UID000005 AboveFrame class `87/91 -> 88/92` and managed block | `0 / 1` | deferred; five pre-existing UID0003I2 warnings |
| `000000009408` | `2026-07-13T07:16:39` | UID00015O FramePartPane aggregate `87/91 -> 89/93` and managed block | `0 / 1` | deferred |
| `000000009410` | `2026-07-13T07:17:28` | UID00005I FramePartPane class `86/90 -> 87/92` | `0 / 1` | deferred; five pre-existing UID0003I3 warnings |
| `000000009411` | `2026-07-13T07:18:14` | UID0002I7 MapPane constructor `88/89 -> 89/91` | `0 / 1` | deferred |
| `000000009412` | `2026-07-13T07:19:01` | UID0002QF MapPane destructor `88/90 -> 89/92` | `0 / 1` | deferred; three pre-existing UID0003M3/0003M4 warnings |
| `000000009413` | `2026-07-13T07:19:59` | UID0002QI Map callback `88/91 -> 91/94` | `0 / 1` | deferred |
| `000000009414` | `2026-07-13T07:21:02` | UID00007Q MapPane class `88/87 -> 89/89` | `0 / 1` | deferred; 87 pre-existing unregistered-child warnings |
| `000000009415` | `2026-07-13T07:21:56` | UID0001NT Video aggregate `87/91 -> 89/93` | `0 / 1` | deferred |
| `000000009416` | `2026-07-13T07:22:41` | UID0000FV VideoPlayerPane class `88/88 -> 89/90` | `0 / 1` | deferred |
| `000000009417` | `2026-07-13T07:23:09` | Final UID0000ZW revalidation and waited global refresh | `0 / 1` | completed in 18.2 s; fresh command/timestamp headers |
| `000000009432` | `2026-07-13T07:33:48` | UID0001TV historical-source wording revalidation; managed block/scores unchanged | `0 / 1` | deferred |
| `000000009434` | `2026-07-13T07:34:17` | UID0000ZY historical candidate wording revalidation; managed block/scores unchanged | `0 / 1` | deferred |
| `000000009439` | `2026-07-13T07:35:13` | UID0000ZZ historical wording intermediate validation | `0 / 1` | deferred; two reverse references temporarily removed by wording compression |
| `000000009441` | `2026-07-13T07:35:42` | UID0000ZZ full evidence/link detail restored and revalidated | `0 / 1` | deferred; both reverse references restored |
| `000000009448` | `2026-07-13T07:37:07` | UID000198 evidence-time/history wording revalidation; managed block/scores unchanged | `0 / 1` | deferred |
| `000000009458` | `2026-07-13T07:40:34` | UID0002I7 R15 three-line `for` header restored | `0 / 1` | deferred; literal check then exposed one pre-existing extra newline before END |
| `000000009459` | `2026-07-13T07:40:58` | UID0002QF R16 extra newline before END removed | `0 / 1` | waited refresh completed; three pre-existing UID0003M3/0003M4 warnings |
| `000000009463` | `2026-07-13T07:42:16` | UID0002I7 R15 final extra newline removed and exact block revalidated | `0 / 1` | waited refresh completed; generated MapPane header command `9464` at `07:42:19-04:00` |

- Rename proof: commands `9393`, `9394`, `9395`, and `9397` each reported `path_update` from the Application-named path to the exact LObject-named path while preserving UID and propagating reverse links. No validator registry file was manually edited.
- Warning disposition: all reported `missing_ref_uid` rows are pre-existing unregistered support references outside the accepted scope. The initial UID00037J warning was resolved by command `9390`; focused cleanup command `9459` repeated only the three pre-existing UID0003M3/0003M4 warnings, while final waited command `9463` reported no page-specific missing-reference warning. No validator error remains.
- Final global warnings from `9463` (`207` emitter-has-no-code, `83` children-marker-missing, `14` fallback-insert) are repository-wide advisory rows unrelated to this callback; generation completed.
- Generated freshness: final waited validator `9463` completed at `2026-07-13T07:42:16-04:00`; `auto-generated/NexusTK/map/MapPane.cpp` carries generated command `000000009464` and refresh timestamp `2026-07-13T07:42:19-04:00`.
- Generated proof: a literal managed-block comparison found `17` report blocks and exact equality for R15 (`2970` characters) against UID0002I7 and R16 (`1358` characters) against UID0002QF. MapPane.cpp lines 147-149 preserve the accepted three-line loop header, line 175 starts `MapPane::~MapPane()`, and line 178 uses `g_pBackPane->UnregisterChangeListener(this, kMapPaneChangeTag, false)`. ChangeMan.cpp retains exactly one `void ChangeMan::Register(` body with LObject/MessageType/bool/natural padding; LObject.cpp retains the callback and three wrappers; Application.cpp has zero wrapper definitions; no generated MapPane raw-offset comment was introduced.

## Changed Files

- Target/family modified: `by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md`, `by-type/by-struct/ChangeManEntry.md`, `by-type/by-struct/ChangeManLayout.md`, `by-memory/0x0047ed80-0x0047ee18.ChangeManUnregisterFiltered.md`, `by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md`, `by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md`, `by-memory/0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject.md`, `by-memory/0x0047ef20-0x0047ef3f.CompareChangeEntries.md`, `by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md`, `by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md`, `by-memory/0x0047ec70-0x0047efae.ChangeMan.md`, `by-class/ChangeMan.md`, and `by-file/ChangeMan.md`.
- SortedList support modified: `by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md` and `by-class/SortedList.md`.
- UID-preserving validator renames: UID000198 `by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md` -> `by-memory/0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener.md`; UID00019A `by-memory/0x004f4b50-0x004f4b6c.ApplicationUnregisterChangeListener.md` -> `by-memory/0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md`; UID00019B `by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md` -> `by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md`; UID000199 `by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md` -> `by-memory/0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers.md`.
- LObject/Application support modified: `by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md`, `by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md`, `by-class/LObject.md`, `by-file/LObject.md`, `by-class/Application.md`, and `by-file/Application.md`.
- Derived support modified: `by-memory/0x004610f0-0x0046178a.AboveFrame.md`, `by-class/AboveFrame.md`, `by-memory/0x004b73b0-0x004b7661.FramePartPane.md`, `by-class/FramePartPane.md`, `by-memory/0x00504110-0x00504521.MapPaneInitialize.md`, `by-memory/0x00504530-0x005046c6.MapPaneCleanup.md`, `by-memory/0x00504b70-0x00504b8f.MapPaneTagDetachMessage.md`, `by-class/MapPane.md`, `by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md`, and `by-class/VideoPlayerPane.md`.
- Focused Gate 2 literal repair: UID0002I7 restored the accepted three-line R15 loop header and removed its extra pre-END newline; UID0002QF removed its extra pre-END newline. Commands `9458/9459/9463` validate only those two pages for this focused repair, both destination blocks now compare byte-for-byte to report R15/R16, and both repair leases were released immediately.
- Report modified: `tools/leaser/Agents/Agent-B003/research/0000ZW-ChangeManRegister-source-quality.md`.
- Validator-managed side effects: rename validation propagated UID links/reverse references and validator-owned registry/coverage/projected-stat/generated state. B003 did not manually edit any validator registry, generated, coverage, tracker, supervisor, or lifecycle file.
- Leases: one-file leases were acquired only immediately before each manual by-* edit and released after its scoped validator. The UID000195 release state mutation succeeded despite a transient `WinError 5` while regenerating the lease report; retry and `current_leases.md` confirmed no active B003 lease. All other releases succeeded directly.
- Boundary: B003 performed scoped validators and the waited refresh only; B003 performed no report execution, lifecycle, registry-lifecycle, move, archive, generated-file, coverage, tracker, supervisor-file, or IDA mutation command.

## Implementation Tracking Checklist

- [x] Supervisor Gate 1 accepted exact pre-callback SHA `CE73BEADF377C982188BBB519A581A7F8E4BAC1853C7398799756E590DD7E532` before implementation.
- [x] Applied C01-C20 at report-level detail and recorded exact applied/preserved/historicalized proof in every ledger row.
- [x] Updated UID0000ZW metadata `86/90 -> 92/94`, position `20`, exact managed block, Item Summary, behavior, ABI, caller/callee, helper-return, source-name, and negative evidence; preserved UID/range/owner/emitter/true/Nested 0.
- [x] Updated UID0001TV and UID0001TW to LObject/LObject/bool/MessageType with natural padding and exact managed blocks; removed only stale enum/interface/explicit-padding source claims.
- [x] Synchronized UID0000ZY, UID0000ZZ, UID000100, UID0004I6, UID000101, and UID000103 exactly as listed, preserving behavior, routes, no-code compiler state, and negatives.
- [x] Synchronized UID0000ZX, UID0000ZU, UID00001K, and UID0000I2 with complete source-type/wrapper-route evidence and score changes while preserving aggregate non-emission and all child/padding inventory.
- [x] Updated UID00037J and UID0000DF with exact int-return helper contract and ignored target use; validator registered UID00037J without manual registry edits.
- [x] Validator-renamed UID000198, UID00019A, UID00019B, and UID000199 to exact LObject paths/titles with UIDs/ranges preserved, then applied owner/emitter/formal/score changes.
- [x] Updated UID000195, UID0000WM, UID00007D, UID0000KV, Application class/file, and confirmed derived callback/caller support with exact common-base evidence and stale-history dispositions.
- [x] Applied complete managed blocks for AboveFrame class, FramePartPane aggregate, and MapPane callback; preserved the full accepted MapPane constructor/destructor blocks while changing only the inherited call expressions, then repaired R15/R16 formatting so both destination blocks compare byte-for-byte to the report; updated VideoPlayerPane prose without inventing an aggregate body.
- [x] Preserved all four register and seven unregister call expressions, callback vtable triplets, constructor-chain proof, invalid-byte negative evidence, no return consumers, exact bytes/ranges/pads, and rejected alternatives.
- [x] Preserved stale B004/B009/B010/command-9304 assumptions only as explicitly historical/superseded evidence.
- [x] Confirmed no third-party import directive applies.
- [x] Used short one-file leases, ran one scoped validator per changed/renamed by-* page, and released each lease immediately after its validator or verified expiry/release state.
- [x] Scoped-validated the focused R15/R16 repair with `9458/9459/9463`, released each one-file lease immediately, and proved literal equality for report R15 (`2970` characters) and R16 (`1358` characters).
- [x] Ran final waited generated verification `000000009463` and recorded command IDs, timestamps, exit codes, ok counts, warnings, and generated-header freshness (`MapPane.cpp` command `9464`, `2026-07-13T07:42:19-04:00`).
- [x] Verified generated ChangeMan.cpp has exactly one UID0000ZW body with LObject/MessageType/bool/natural padding and no stale enum/interface; LObject.cpp has three wrapper members plus OnChangeMessage; Application.cpp has no duplicate wrapper definitions; MapPane.cpp preserves the exact three-line loop header and inherited constructor/destructor expressions.
- [x] Did not manually edit generated, coverage, tracker, supervisor, validator-owned, lifecycle, registry, or IDA state and did not run any report execution/move/archive command. No B003 implementation item remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000009474","destination_path":"executed-b-agent-research/B003/0000ZW-ChangeManRegister-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0000ZW-ChangeManRegister-source-quality.md","timestamp":"2026-07-13T07:50:07-04:00","uid":"0000ZW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
