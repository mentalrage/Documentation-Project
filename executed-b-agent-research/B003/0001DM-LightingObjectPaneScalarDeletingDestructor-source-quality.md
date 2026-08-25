** TARGET-REPORT-UID:0001DM **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0001DM LightingObjectPaneScalarDeletingDestructor Ownership / Split Research


## Finalized Report / Current Recommendation

- Implemented recommendation: [UID:0001DM] remains the exact `LightingObjectPane` class-owned, source-declared/generated-binary scalar deleting destructor wrapper at `90/94`, with owner/emitter [UID:000075], `RECONSTRUCTABLE:TRUE`, blank position, `Nested:0`, and the exact covered-by comment for ordinary lifecycle [UID:0001DG].
- Final disposition: one unsplit `0x0053d380-0x0053d422` compiler ABI wrapper. Human-authored source belongs in `LightingObjectPane::~LightingObjectPane()` at `0x0053c640`, not in a handwritten scalar-delete method. The two adjusted-view thunks remain compiler output documented by this target and the vtable page rather than new source children.
- Callback result: C01-C20 are incorporated claim by claim, including the exact ordinary constructor/destructor, class declaration, UID-preserved `SetLightImageIndex` rename/body, vtable marker, source-state corrections, support synchronization, scoped validators, and waited generated verification.
- Confidence: very strong for range, owner, vtable routes, ABI role, object size, base teardown, attachment contract, and compiler/source split; strong inferred confidence for original private field spellings and the source-facing setter name.

## Supporting Research

- Report-only evidence was collected on 2026-07-13 after the supervisor restarted IDA MCP. No fallback-only conclusion is used.
- The healthy mandatory IDB session at evidence-collection time was `c81909be`, opened on `NexusTK.exe.i64`. A fresh `idb_list` returned that active worker; `server_health` returned `status:ok`, image base `0x400000`, and ready auto-analysis, Hex-Rays, and strings cache; bounded `lookup_funcs` and `get_bytes` calls for the target then succeeded.
- Historical documentation assumptions that `+0x134` was an owned light-binding interface and `+0x128` was intensity are superseded by current executable behavior and independently accepted attachment-resolver evidence.
- Prior reports were used only as support/precedent and rechecked against current binary evidence. Searches for `0001DM`, `0x0053d380`, `LightingObjectPaneScalarDeletingDestructor`, and `LightingObjectPane` found no prior B-agent report dedicated to this target. Opened related executed reports include B001 UID0002R3 scalar-wrapper precedent, B015 UID0001DH attachment-resolver source shape, B010 UID0001D9 effect-pane context, B001 UID00023D object-list lighting sync, and B003 UID0002IV light-bounds support.

## Target

- Target UID: `0001DM`.
- Target path: `by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md`.
- Historical assignment source row before implementation: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`; later tracker state is validator-owned and is not asserted here.
- Historical assignment classification: report-only source-quality research before the accepted implementation callback.
- Implemented scores and parent state: `90/94`, direct owner/emitter [UID:000075] `LightingObjectPane`, `RECONSTRUCTABLE:TRUE`, blank position, exact managed covered-by marker, `Nested:0`.

## Current Target State

- Implemented metadata: exact UID/range/class-file route are preserved and the target is now `90/94` under the accepted source-declared/generated-wrapper policy.
- Implemented owner/emitter/reconstructable state: [UID:000075] owner/emitter and `RECONSTRUCTABLE:TRUE` remain unchanged under the established class-owned generated-wrapper policy.
- Existing C++/emitter state: the blank formal block is incorrect for a reviewed special emitter. The generated source observed before this callback was `auto-generated/NexusTK/map/LightingObjectPane.cpp`, validator command `000000009484`, refreshed `2026-07-13T08:24:41-04:00`, and showed Empty Emitter Markers for UID000075, UID0001DG, UID0001DI, UID0001DM, and UID000359. This is explicitly historical pre-callback evidence, not a prediction of later generated state.
- Existing open questions and stale assumptions: the page calls `+0x134` an attached-object/light-binding interface and describes virtual slot `+0x4c` as a generic release. Current evidence resolves it to `ObjectPane *m_anchorSource` and `ObjectPane::DetachObject()`. The page also overstates the bit-4 branch as placement delete without recording that its target is a one-byte no-op in this executable.
- Related target/support docs checked: UID000075, UID0000KO, UID0001DG, UID0001DI, UID000359, UID0001DL, UID00023D, UID0001D9, UID0000IZ, UID0001DH, UID00000O, UID0002TY, UID0002TZ, UID0002U0, UID0003XQ, UID0003XR, UID000197, predecessor UID000385, and successor UID0002R3.
- Artifact/lifecycle boundary: this path identifies the historical B003 research and implementation-callback artifact before external supervisor lifecycle. B003 ran only the scoped/waited implementation validators recorded below and performed no `execute_report`, lifecycle, report-move, or archive command. External validation/execution/count/path/move/archive state is supervisor/validator-owned and is not asserted by this artifact.

## Executive Recommendation

The direct semantic owner and emitter remain [UID:000075] `LightingObjectPane`, routed to [UID:0000KO] `NexusTK/map/LightingObjectPane.cpp`. UID0001DM is compiler-generated deleting-destructor ABI output that is reconstructable through the virtual ordinary destructor declaration and normal allocation policy. It must not emit a hand-authored `ScalarDeletingDestructor(flags)` body.

Keep the exact target unsplit and insert a comment-only formal marker covered by [UID:0001DG]. Upgrade the source-bearing family at report-level detail: emit the ordinary constructor/destructor on UID0001DG, emit a complete class declaration followed by `[[CHILDREN]]` on UID000075, and validator-preserving rename UID0001DI from `LightingObjectPaneSetIntensity` to `LightingObjectPaneSetLightImageIndex` with a `void` first-draft body. The setter rename is required because all current consumers treat the value as a LightObjImageLib/table row index, including negative sentinel values; no evidence supports photometric intensity.

## Supervisor Active Recheck

- Historical Gate 1 state: the supervisor accepted exact report SHA `6E09C4F2E08B5AD07713D0E67699405463CB69F79C2A7D270619EE15FD72AE65` and authorized the implementation callback after the live-MCP source-quality pass.
- Gate 2 C02 repair state: the target page now states the exact half-open target size as `0xa2` (`162`) bytes and passed scoped command `000000009554`. This report mutation means the historical Gate 1 SHA above does not cover this artifact revision; external validation/execution state for the new revision is not asserted here.
- The item does not require a split repair. The target is one modeled function, and both neighboring padding dispositions are proven.
- Every source-bearing item required to resolve the target was implementation-ready at Gate 1 and is now implemented: target wrapper marker, ordinary lifecycle body, class declaration, setter body/rename, and vtable no-hand-authored-data marker. Compiler-only thunks and ABI tails retain exact no-standalone-source dispositions.

## Inference Research Guidance Check

- `by-structure.md` requires separating human-authored source from source-declared/generated-binary artifacts. That rule makes the ordinary destructor the source-bearing body and the scalar wrapper/vtable/thunks compiler output generated from the class declaration.
- Existing labels and types were treated as hypotheses. In particular, IDA's `float *Block`, `char a2`, and `int` setter return are decompiler/type-propagation artifacts; documentation's `SetIntensity`, owned light interface, and release-slot wording were independently rechecked.
- IDA fact: ranges, bytes, vtable addresses, xrefs, calls, offsets, flags, and allocation size. Documentation evidence: accepted ObjectPane Attach/Detach names and AttachmentAnchorResolver field roles. Inference: original private member spellings and `SetLightImageIndex` source spelling.
- No current explicit Wave2/Wave3 override applies. Historical Wave2 naming that called `0x0053c980` `SetIntensity` was treated as stale and did not override current evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best defensible resolution | Status / rejected alternative |
| --- | --- | --- | --- |
| Target identity and range | Fresh lookup, 58-instruction disassembly, exact bytes, neighboring functions | `LightingObjectPane` scalar deleting destructor at exact half-open `0x0053d380-0x0053d422` | Original-proof from RTTI/vtable and code; reject range extension into padding |
| ABI signature | `this` in `ECX`, one four-byte stack flag, original pointer in `EAX`, `retn 4` | compiler deleting-destructor shape `LightingObjectPane *(this, unsigned int flags)` for documentation only | Do not expose as source method; reject IDA `float *(float *, char)` |
| Delete flags | `test al,1`; `test al,4`; normal delete helper; size/no-op branch | bit 1 requests storage deallocation; bit 4 selects compiler/runtime guarded size-delete/no-free branch in this executable | Reject source-visible flags and reject claim that `0x41b6a0` frees memory |
| Ordinary destructor responsibility | `0x0053c640` restores same vptrs, detaches anchor, calls ObjectPane dtor; target duplicates it before flags | source is `LightingObjectPane::~LightingObjectPane(){ m_anchorSource->DetachObject(); }` | Reject handwritten vptr/base/delete calls |
| `+0x134` type and ownership | constructor first arg, creators pass source ObjectPane, calls exact ObjectPane slots +0x48/+0x4c, no delete/release of source | borrowed `ObjectPane *m_anchorSource`; destructor calls `DetachObject()` | Reject owned light manager/interface and COM-style release |
| `+0x128` role | constructor final arg, LightObjImageLib bounds lookup, light-table draw row, effect frame `+0x0c`, static metadata negative sentinel | signed `int m_lightImageIndex` | Reject intensity, radius, color, and unsigned-only type |
| `+0x12c/+0x130` roles | resolver applies them in Y then X order; creation callers pass corresponding offsets | `int m_localOffsetY`, `int m_localOffsetX` | Inferred spellings; reject generic light parameter array |
| Setter name and return | compares/writes `+0x128`, DetachObject, write, AttachObject(this); no-change path leaves EAX undefined; callers ignore result | `void SetLightImageIndex(int lightImageIndex)` | Reject `int SetIntensity`, return-tail inference, and direct private-field consumers |
| Constructor signature | base call uses `(10,0,mapX,mapY)`; helper gets source map pair and passes offsets/index; stores exact four fields | constructor form in the formal block below | Parameter spellings inferred but behavior complete; reject decompiler `a2..a7` |
| Object size | both creation contexts call operator new wrapper with `312`; deleting wrapper pushes `0x138` | exact complete-object size `0x138` | Original binary fact; no explicit size assertion added to source block |
| Vtable views | primary `0x00620a3c`; adjusted `0x00620aac/+0x00620adc`; stores at object `+0/+0xa0/+0xa4` | three compiler-generated views of LightingObjectPane | Reject three independent source objects |
| Adjustor thunks | exact 11-byte bodies subtract `0xa0` or `0xa4` then jump target; vtable-only refs | compiler this-adjusting destructor thunks, no separate source/body/page needed | Reject direct callers and manual thunk C++ |
| Source placement | class/file chain, constructor callers in map/effect paths, existing map layout | `NexusTK/map/LightingObjectPane.cpp` | Reject Effects.cpp, LightObjImageLib.cpp, AttachmentAnchorResolver.cpp, ObjectPane.cpp |
| IDA local types | `type_query` for `*LightingObjectPane*` and `*ObjectPane*` returned zero rows | use behavior-backed project declarations, record original spelling caveat | Reject polluted IDA prototype as type proof |
| EH/security glue | security cookie, SEH frame, CxxFrameHandler3, terminate target | compiler/runtime lowering only | Reject source-level try/catch or cookie code |

The remaining uncertainty is limited to exact original private spelling/access and the runtime's internal name for flag bit 4. It does not block source-quality C++, ownership, range, or score movement because the recommended code avoids exposing either ABI artifact.

## Evidence Standards Used

- Evidence types: live IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `decompile`, `disasm`, `xrefs_to`, and `type_query`; RTTI/vtable data; constructor/destructor parity; callers; allocator/deallocator flows; accepted by-* docs; executed-report precedent; generated-output observation; negative xref/type checks.
- The evidence is strong because independent routes agree: RTTI names and three vtable slots identify the class; constructor writes and destructor restores identify layout; ObjectPane slot docs identify Attach/Detach semantics; both creator paths prove size and borrowed source pointer; resolver consumers prove field roles.
- Binary context was treated as authoritative for ranges and mechanics. Documentation was accepted only where it already had independent live evidence. Original symbol absence caps source-name confidence but does not justify carrying known-wrong names.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: fresh session/health probe; target lookup/decompile/disassembly; predecessor/successor lookups; target and boundary bytes; two thunk disassemblies/bytes/xrefs; ordinary lifecycle and setter decompiles; creation helper/effect updater decompiles; allocator/delete/no-op helper checks; relevant xrefs; type queries.
- by-* docs checked: target, LightingObjectPane class/file/lifecycle/setter/vtable, ObjectPane constructor/map-position/AttachObject/DetachObject, attachment resolver family, ObjectList static-light sync, EffectObjectPane/Effects, operator new/delete family context, broad companion-destructor index, predecessor/successor scalar wrappers.
- Old reports checked: B001 UID0002R3 wrapper policy, B015 UID0001DH field/source analysis, B010 UID0001D9 effect context, B001 UID00023D static-light sync, B003 UID0002IV bounds method, plus target/address/name searches across executed and agent research.
- Negative checks: no direct ordinary code caller to the target; no direct xref to ordinary dtor; thunks have vtable-only incoming refs; no local IDA UDT rows; no source/PDB path evidence; no null check or owned-pointer free at `+0x134`; no explicit EAX result on setter no-change path; no memory free on bit-4 branch.
- Failed/unavailable checks: an initial local PowerShell `Invoke-WebRequest` omitted `-UseBasicParsing` and failed before any MCP tool call; the corrected client call immediately succeeded. No IDB-backed evidence route failed, and no fallback was substituted.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Mandatory evidence session `c81909be` was healthy at collection time and bounded calls succeeded | 1.00 | fresh idb_list/health/lookup/get_bytes | UID0001DM IDA MCP Evidence; family support change notes | Record durable evidence-time wording | Applied; UID0001DM/UID0001DG/UID0000KO and report retain evidence-time wording; validated by 9490/9489/9493 and final 9517 |
| C02 | Exact target range is `0x0053d380-0x0053d422`, size `0xa2` | 1.00 | lookup/disasm/bytes | UID0001DM Range/Boundary | Replace stale generic range prose with exact proof | Applied and Gate 2-repaired; UID0001DM Boundary Notes explicitly state exact half-open range, function size `0xa2` (`162`) bytes, endpoint subtraction `0x0053d422 - 0x0053d380`, and exclusive endpoint; scoped command 9554 exited `0`, `ok:1` |
| C03 | Nine predecessor and fourteen successor `0xCC` bytes are parent-only alignment | 1.00 | bytes; predecessor/successor lookups | UID0001DM; UID0001DL support note | Preserve padding and no split | Applied; target and UID0001DL retain both parent-only pads; commands 9490/9498 `ok:1` |
| C04 | Target is a compiler scalar deleting destructor, not a source method | 0.99 | ABI, vtable refs, ordinary dtor duplication | UID0001DM status/source policy | Keep true/class route; comment-only code | Applied; exact UID0001DG marker and generated comment verified by 9517 |
| C05 | Bit 1 requests free; bit 4 uses guarded size/no-free runtime branch | 0.99 | disasm; `0x41b6a0` one-byte ret; operator delete | UID0001DM behavior; UID000197 caller note | Correct placement/free wording | Applied; target plus UID000197 record both branches and non-transfer; commands 9490/9513 `ok:1` |
| C06 | Ordinary destructor at `0x0053c640` owns source semantics | 0.99 | direct body parity | UID0001DG, UID0001DM, class/file | Emit exact ordinary destructor; wrapper points to it | Applied; exact destructor block validated 9489 and emitted by 9517 |
| C07 | `+0x134` is borrowed `ObjectPane *m_anchorSource`; slot +0x4c is DetachObject | 0.98 | ctor args, creation callers, ObjectPane slots | UID0001DM, UID0001DG, UID000075, UID0000KO | Replace interface/release wording | Applied at all four destinations; 9490/9489/9488/9493 and repair 9515 all `ok:1` |
| C08 | Complete object size is `0x138`; allocation uses operator new and normal free uses UID000197 | 1.00 | two allocation sites; wrapper size constant/callee | UID0001DM/lifecycle/class/file | Add lifecycle/allocation proof | Applied across target/family and UID000197 support; validated 9490/9489/9488/9493/9513 |
| C09 | Target has only two thunk code refs and one primary vtable data ref | 1.00 | xrefs_to | UID0001DM, UID000359 | Record exact reachability/negative caller fact | Applied with exact xrefs and no-direct-caller fact; commands 9490/9496 `ok:1` |
| C10 | Thunks `0x0053cf28` and `0x0053cf33` subtract `0xa0`/`0xa4` and jump target | 1.00 | bytes/disasm/xrefs | UID0001DM, UID000359, UID0001DL | Preserve as compiler output; no new child | Applied at all three destinations; commands 9490/9496/9498 `ok:1`; no child created |
| C11 | Three vtable bases/restores are `0x00620a3c`, `0x00620aac`, `0x00620adc` at object `+0/+0xa0/+0xa4` | 1.00 | ctor/dtors/vtable data | UID0001DM, UID0001DG, UID000075, UID000359 | Synchronize exact routes | Applied with exact three-view tables/stores; validated 9490/9489/9488/9496 |
| C12 | Tail fields are index, Y offset, X offset, anchor pointer | 0.97 | ctor stores, resolver, consumers | UID000075, UID0001DG, UID0000KO, UID0001DI | Replace stale light type/radius/intensity/color model | Applied at all destinations; exact layout emitted by 9517; commands 9488/9489/9493/9487/9515 `ok:1` |
| C13 | Constructor source shape is exact enough for first draft | 0.96 | base call and both creators | UID0001DG; declaration UID000075 | Insert exact managed blocks | Applied byte-for-byte; 9489/9488 `ok:1`; 9517 emitted declaration before definitions |
| C14 | UID0001DI is `void SetLightImageIndex(int)`, not `int SetIntensity(int)` | 0.96 | field consumers, no-change EAX, Attach/Detach slots | UID0001DI rename/body; all current by-* links | Validator-preserving rename and semantic sync | Applied with UID preserved by 9487; 23 UID links and seven source-path refs updated; support docs 9501/9503/9504/9506/9507/9509/9511 and file repair 9515 passed; 9517 has no old name |
| C15 | EH/cookies/vptr writes/base destruction/delete flags are compiler lowering | 0.99 | disasm and compiler precedent | UID0001DM/UID0001DG source notes | Preserve negatives; exclude from C++ | Applied; prose retains exclusions and 9517 contains no ABI/EH/vptr lowering |
| C16 | Canonical route remains class UID000075 -> file UID0000KO | 0.98 | RTTI, methods, source tree | target/class/file/vtable | Preserve owner/emitter/path | Applied unchanged; validators 9488/9493/9490/9496 and generated source UID0000KO confirm route |
| C17 | Accepted score outcome is target 90/94; lifecycle/class/setter 90/93; vtable 90/94; file 89/91 | 0.94 | blocker closure and score standard | respective metadata/rationales | Apply accepted scores | Applied exactly; 9487/9488/9489/9490/9493/9496 and 9517 headers verify scores |
| C18 | Exact formal blocks are target marker, lifecycle definitions, class declaration/children, setter definition, vtable marker | 0.97 | source/compiler split | five managed destinations | Insert byte-for-byte blocks below | Applied at all five destinations; target/vtable validator link normalization was restored to the accepted literal after scoped validation; 9517 emits both exact literal markers and all source blocks |
| C19 | Stale names/history and support references require report-level synchronization without unrelated score/route changes | 0.96 | full by-* search | UID0001DL, UID00023D, UID0001D9, UID0000IZ, UID0001DH, UID0002TY/TZ/U0, UID000197 | Apply exact support wording/link updates | Applied at report depth; commands 9498/9501/9503/9504/9506/9507/9509/9511/9513 passed; verify-only UID00000O/UID0003XQ/UID0003XR unchanged |
| C20 | Pre-callback generated source had five empty markers; later output must be validator-generated and checked, never edited manually | 1.00 | generated command 9484 read-only observation | report; changed docs' history/results | Historicalize old state and define callback checks | Applied; 9484 remains explicit history; B003 waited command 9517 generated the corrected source; newer external command 9534 was observed with the same five UID traces and clean body; generated files were never edited manually |

## Positive Evidence Summary

- RTTI-named primary and adjusted vtables route directly to the target and its two adjustor thunks.
- Constructor, ordinary destructor, and scalar wrapper install/restore the same three vtable bases at identical complete-object offsets.
- The target exactly duplicates the ordinary destructor's detach/base-teardown sequence and adds only delete-ABI handling.
- Constructor callers allocate 312 bytes, pass a source `ObjectPane *`, obtain source map coordinates, pass local offsets and a light-image index, insert the new pane, and call source `AttachObject(newPane)`.
- Destructor and setter invoke the documented inverse slot, source `DetachObject()`, through the same borrowed source pointer.
- AttachmentResolver and LightObjImageLib evidence independently resolve all four derived tail fields and disprove the current intensity/interface wording.

## IDA MCP Facts

- Function/range facts: `sub_53D380` is size `0xa2`; predecessor `sub_53D2E0` is `0x0053d2e0-0x0053d377`; successor `sub_53D430` starts at `0x0053d430`. `0x0053d422` is not a function.
- Data/table/padding facts: bytes `0x0053d377-0x0053d380` are nine `0xCC`; bytes `0x0053d422-0x0053d430` are fourteen `0xCC`. Thunk bytes are `81 e9 a0 00 00 00 e9 4d 04 00 00` and `81 e9 a4 00 00 00 e9 42 04 00 00`.
- Xref facts: target refs are code `0x0053cf2e`, code `0x0053cf39`, and data `0x00620a3c`. Each thunk has one data ref, respectively `0x00620aac` and `0x00620adc`. There is no ordinary direct call to the target.
- Vtable/global/type facts: target writes LightingObjectPane vtables at complete-object offsets `+0`, `+0xa0`, `+0xa4`; type queries returned no loaded LightingObjectPane/ObjectPane UDT rows.
- Negative IDA facts: no string refs in target, no ordinary destructor xrefs, no memory free on bit-4 branch, and no explicit setter return value on unchanged input.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0053c5e0-0x0053c640` | UID0001DG lifecycle | ordinary constructor | true | UID000075 | `86/90 -> 90/93` | exact first-draft source |
| `0x0053c640-0x0053c6a1` | UID0001DG lifecycle | ordinary destructor | true | UID000075 | shared above | exact first-draft source |
| `0x0053c980-0x0053c9b5` | UID0001DI rename to `LightingObjectPaneSetLightImageIndex` | ordinary method | true | UID000075 | `86/90 -> 90/93` | exact first-draft source |
| `0x0053cf28-0x0053cf33` | no new page | `this-0xa0` deleting-dtor thunk | generated via class | UID0001DM/UID000359 docs | n/a | no standalone source |
| `0x0053cf33-0x0053cf3e` | no new page | `this-0xa4` deleting-dtor thunk | generated via class | UID0001DM/UID000359 docs | n/a | no standalone source |
| `0x0053d380-0x0053d422` | UID0001DM target | scalar deleting destructor | true generated-binary | UID000075 | `86/90 -> 90/94` | comment-only marker |
| `0x00620a38-0x00620ae4` | UID000359 | RTTI/vtable data | true generated-binary | UID000075 | `88/92 -> 90/94` | comment-only marker |
| class declaration | UID000075 | class shell/tail fields | true | UID0000KO | `86/90 -> 90/93` | exact first-draft source |
| source root | UID0000KO | `NexusTK/map/LightingObjectPane.cpp` | route | FILE | `85/88 -> 89/91` | wording/source-state sync |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00620a3c` | primary vtable slot -> target | primary complete-object deleting-destructor route |
| `0x00620aac` | adjusted vtable slot -> `0x0053cf28` | secondary `this-0xa0` route |
| `0x00620adc` | adjusted vtable slot -> `0x0053cf33` | tertiary `this-0xa4` route |
| `0x0053d3ce` | indirect call through anchor slot `+0x4c` | `m_anchorSource->DetachObject()` |
| `0x0053d3d3` | call `0x005373a0` | compiler-emitted `ObjectPane::~ObjectPane()` teardown |
| `0x0053d3e4` | call UID000197 `0x004f4ac0` | normal storage free when bit 1 set and bit 4 clear |
| `0x0053d406` | call one-byte `0x0041b6a0` after pushing this/`0x138` | guarded size/no-free compiler/runtime branch |
| `0x0050a9a5`, `0x00530e79` | calls ordinary constructor | two creation contexts |
| `0x00530dbe`, `0x00538a90` | calls setter | static-object metadata and effect-frame update contexts |
| `0x0053c640` | no direct incoming xref | normal for separately emitted complete-object destructor duplicated by wrapper |

## Documentation Evidence And IDA Status

- Supporting current docs: UID0003XQ/UID0003XR provide exact `ObjectPane::AttachObject(ObjectPane *)` and `ObjectPane::DetachObject()` directions; UID0001DH/UID00000O prove `m_lightImageIndex`, local offsets, and `ObjectPane *m_anchorSource`; UID000197 proves MemoryMan-backed global operator delete; UID0002R3 supplies accepted wrapper policy precedent.
- Stale/incomplete docs: UID0001DM, UID0001DG, UID000075, and UID0000KO retain interface/release and generic light-state wording. UID0001DI and its support links retain `SetIntensity` and an unsafe integer-return direction. UID00023D and UID0000IZ likewise describe intensity rather than index selection.
- Generated/coverage report state: command 9484's five Empty Emitter Markers are historical pre-callback evidence. Generated/tracker/coverage files are validator-owned and must not be manually edited.

## Ranked Ownership Analysis

### 1. LightingObjectPane / LightingObjectPane.cpp

- Evidence for: RTTI and three vtables name the class; all constructor/destructor field/vptr operations are complete-object LightingObjectPane operations; direct class/file chain already exists; map/effect creation contexts construct this type.
- Evidence against: exact original private member spellings and header split are not symbol-proven.
- Decision: retain [UID000075] direct owner/emitter and [UID0000KO] file route. The remaining spelling caveat affects confidence only.

### 2. ObjectPane / ObjectPane.cpp

- Evidence for: ObjectPane supplies the base destructor and Attach/Detach methods; `m_anchorSource` has ObjectPane type.
- Evidence against: target restores LightingObjectPane RTTI/vtables and operates on derived tail fields; ObjectPane is a base/dependency.
- Decision: reject as target owner. Keep exact base-method support unchanged.

### 3. AttachmentAnchorResolver, LightObjImageLib, or Effects

- Evidence for: resolver and image library consume the index/layout; Effects calls the setter and creates lights.
- Evidence against: none owns the target vtables, object lifetime, or derived class layout. AttachmentAnchorResolver's accepted source placement is separately documented; EffectObjectPane is a consumer.
- Decision: reject all as target owner/file placement. Synchronize only factual references.

### Proposed new file/grouping, if applicable

- Not applicable. Keep the existing [UID0000KO] `NexusTK/map/LightingObjectPane.cpp` route.
- Likely full contents: LightingObjectPane declaration, ordinary constructor/destructor, `SetLightImageIndex`, and compiler-generated RTTI/vtable/deleting-destructor artifacts.
- Rejected related items: AttachmentAnchorResolver modeled methods and sibling raw helpers remain outside this source owner under their accepted policy.

## Source Placement

- Recommended placement: class UID000075 and exact method children emit through `NexusTK/map/LightingObjectPane.cpp` under file UID0000KO.
- Fit: the object is an ObjectPane subclass inserted into ObjectList/map scene state; render/image libraries provide data and drawing services but do not own object lifetime.
- Rejected placements: `Effects.cpp` is a caller; `LightObjImageLib.cpp` owns image records/bounds; `ObjectPane.cpp` owns the base; `AttachedObjectPane.cpp`/AttachmentAnchorResolver own separate shared resolver documentation.
- Remaining placement uncertainty: no embedded original source path distinguishes `.cpp`/header split, but no evidence supports moving the current route.

## Range / Split / Padding / Reclassification Analysis

- Exact target: one IDA function `0x0053d380-0x0053d422`, 162 bytes, with final `retn 4` at `0x0053d41f` and endpoint padding beginning at `0x0053d422`.
- Predecessor: UID000385 ends exactly at `0x0053d377`; nine `0xCC` bytes `0x0053d377-0x0053d380` remain alignment under the broad destructor-island/container disposition.
- Successor: UID0002R3 starts exactly at `0x0053d430`; fourteen `0xCC` bytes `0x0053d422-0x0053d430` remain alignment under that same parent/container disposition.
- No child split: SEH handler/cookie references are out-of-line runtime glue, not in-range child bodies. Internal delete branches are basic blocks of one ABI wrapper.
- The two thunks are separate exact functions before this range, but they are source-less adjusted entries and do not need new by-memory source pages. Their exact facts remain in UID0001DM and UID000359.
- Reclassification: retain reconstructable/class-emitted generated-binary status; reject `RECONSTRUCTABLE:FALSE`, ignored/padding classification, raw helper, or ordinary source method classification.

## Negative Evidence Summary

- No direct source caller reaches the target; only two compiler thunks and the primary vtable reference it.
- The ordinary destructor has no direct xref, so lack of callers does not imply dead code or no source destructor.
- `+0x134` is never freed by LightingObjectPane; creator and inverse Attach/Detach flows prove a borrowed source relationship.
- The setter's unchanged branch does not define EAX, disproving an intentional `int` return contract.
- No current use treats `+0x128` as a continuous intensity; consumers use it as an index and accept `-1` as absence.
- Proximity to AttachmentAnchorResolver and Effects does not transfer ownership.
- IDA's lack of loaded UDTs prevents original declaration recovery but does not contradict behavior-backed types.

## IDA Rename / Type / Comment Recommendations

- UID0001DI validator-preserving page rename: `by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity.md` -> `by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetLightImageIndex.md`; preserve UID0001DI and update all current by-* links.
- Source-facing function names: ordinary destructor `LightingObjectPane::~LightingObjectPane`, setter `LightingObjectPane::SetLightImageIndex`.
- Source-facing fields: `int m_lightImageIndex`, `int m_localOffsetY`, `int m_localOffsetX`, `ObjectPane *m_anchorSource`.
- Documentation-only ABI type: deleting wrapper takes an unsigned integral flags word and returns original `LightingObjectPane *`; do not put that signature in source C++.
- Keep IDA function names/types unchanged. This assignment does not authorize IDB mutation, and original names are not symbol-proven.
- Preserve `SetIntensity`, `float *Block`, `char a2`, and attached light-binding interface only as rejected/superseded aliases in history, not current source names.

## First-Draft C++ Recommendation

- Eligible for draft C++: ordinary lifecycle UID0001DG, renamed setter UID0001DI, and class UID000075. UID0001DM and UID000359 are eligible only for generated-artifact covered-by markers.
- Target UID0001DM exact formal insertion:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:0001DG].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0001DG exact formal insertion:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
LightingObjectPane::LightingObjectPane(
    ObjectPane *anchorSource,
    int mapY,
    int mapX,
    int localOffsetX,
    int localOffsetY,
    int lightImageIndex)
    : ObjectPane(10, 0, mapX, mapY),
      m_lightImageIndex(lightImageIndex),
      m_localOffsetY(localOffsetY),
      m_localOffsetX(localOffsetX),
      m_anchorSource(anchorSource)
{
}

LightingObjectPane::~LightingObjectPane()
{
    m_anchorSource->DetachObject();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0001DI exact formal insertion after validator-preserving rename:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LightingObjectPane::SetLightImageIndex(int lightImageIndex)
{
    if (m_lightImageIndex == lightImageIndex)
        return;

    m_anchorSource->DetachObject();
    m_lightImageIndex = lightImageIndex;
    m_anchorSource->AttachObject(this);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID000075 exact formal insertion; `[[CHILDREN]]` is deliberately after the complete class closing `};` so method definitions emit at namespace scope:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class LightingObjectPane : public ObjectPane
{
public:
    LightingObjectPane(
        ObjectPane *anchorSource,
        int mapY,
        int mapX,
        int localOffsetX,
        int localOffsetY,
        int lightImageIndex);
    virtual ~LightingObjectPane();

    void SetLightImageIndex(int lightImageIndex);

private:
    int m_lightImageIndex;
    int m_localOffsetY;
    int m_localOffsetX;
    ObjectPane *m_anchorSource;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID000359 exact formal insertion:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:000075].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason behavior is preserved: the destructor performs exactly the one human-authored detach action; C++ supplies base teardown, vptr transitions, thunks, delete flags, and storage release. The setter preserves no-change behavior and exact Detach -> write -> Attach ordering.
- Plausible mid-2000s source shape: plain `int`, pointer style, initializer list, explicit `virtual` destructor, and no modern-only syntax.
- Third-party import directive: not applicable; this is NexusTK project C++.
- Exact no-code proof for target/thunks/vtable: vtable-only reachability, duplicated ordinary body, adjusted `this` thunks, ABI flags, manual vptr stores, and generated RTTI/data are all compiler artifacts regenerated from the class declaration and normal destructor.

## Final Recommendation

- C01-C20 were implemented exactly after acceptance.
- UID0001DM retains its exact range, UID, direct owner/emitter, reconstructable state, blank position, and `Nested:0`; its implemented score is `90/94` and its formal body is the accepted UID0001DG marker.
- Source-bearing UID0001DG/UID000075/UID0001DI and generated-data UID000359 contain the exact managed blocks above.
- UID0001DI was validator-renamed with UID preservation, and current by-* links/references were synchronized without changing unrelated support ownership/routes.
- Both thunks remain unpaged compiler-only evidence and both padding spans remain parent/container-only.
- No B003 research or implementation item remains. Original spelling uncertainty is represented as a score cap, not a blocker.

## Recommended Target Doc Changes

- Implemented target path: `by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md`.
- Implemented metadata: `86/90 -> 90/94`; owner `000075`, emitter `000075`, reconstructable true, position blank, `Nested:0`, exact range unchanged.
- Implemented C++ is the exact UID0001DG covered-by block.
- Current behavior records borrowed `m_anchorSource->DetachObject()`, ObjectPane teardown, bit-1 normal delete, and bit-4 guarded size/no-free runtime branch with one-byte `0x0041b6a0` target.
- Exact xrefs, two thunk bodies, three vtable routes/restores, object size/allocation/free evidence, boundary padding, no-direct-caller negative, and compiler/source distinction are incorporated.
- Implemented Item Summary: `Compiler-generated LightingObjectPane scalar deleting destructor ABI wrapper with exact primary/adjusted vtable routes, borrowed anchor DetachObject teardown, ObjectPane base destruction, delete-flag branches, 0x138-byte object size, closed padding, and comment-only source coverage by UID0001DG.`
- Historical `SetIntensity`/interface/placement wording remains only as superseded assumptions with rejection evidence.

## Recommended Support Doc Changes

- UID0001DG lifecycle moved `86/90 -> 90/93`, received the exact constructor/destructor block, and now records field mapping, borrowed anchor, Attach/Detach contract, `0x138` allocation, base call order, and compiler-lowering exclusions.
- UID000075 class moved `86/90 -> 90/93`, received the exact class block with `[[CHILDREN]]` after `};`, and now records the four-field layout plus source/generated inventory.
- UID0001DI was validator-preservingly renamed to `0x0053c980-0x0053c9b5.LightingObjectPaneSetLightImageIndex.md`, moved `86/90 -> 90/93`, and received the exact `void` block with two callers, no-change behavior, Detach/write/Attach order, signed sentinel, and rejected return/intensity history.
- UID0000KO moved `85/88 -> 89/91`, retained `NexusTK/map/`, and now records the index/local-offset/anchor model, ordinary source responsibilities, and generated-wrapper policy; a post-callback sweep corrected two stale current setter references.
- UID000359 moved `88/92 -> 90/94`, received the exact UID000075 covered-by marker, and retains exact range/table addresses, three deleting-destructor routes, and generated-binary status.
- UID0001DL retained score/owner/route and now records the exact UID0001DM wrapper/thunk/padding disposition while remaining the broad non-owner index.
- UID00023D retained score/owner/route and now uses `SetLightImageIndex(lightImageIndex)` with signed negative-sentinel/index semantics and the current UID0001DI link.
- UID0001D9 and UID0000IZ retained scores/routes and now record exact `0x00538a90`, effect-frame record `+0x0c`, `-1` sentinel behavior, and caller-versus-owner separation.
- UID0001DH, UID0002TY, UID0002TZ, and UID0002U0 retained scores/routes/source dispositions, use the current UID0001DI path/name, and preserve independent AttachmentAnchorResolver ownership and no-route decisions.
- UID00000O was verified as requiring no edit; its field/type and independent ownership analysis already corroborate this result.
- UID000197 retained score/owner/emitter/code and now records UID0001DM's normal-delete predicate and separate bit-4 no-free branch without ownership transfer.
- UID0003XQ/UID0003XR were verified as requiring no edit; their current Attach/Detach method directions remain the accepted support contract.
- Generated, tracker, coverage, validator-owned, supervisor, and lifecycle files received no manual edit.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/90`, owner/emitter UID000075, reconstructable true, blank position, blank C++, `Nested:0`.
- Implemented target: `90/94`, same UID/range/owner/emitter/reconstructable/position/nesting, comment-only covered-by block.
- Target completion reaches 90 because range, padding, ABI, flags, thunks, vtables, field contract, object size, allocation/free, ordinary source responsibility, source placement, and formal disposition are closed. Confidence 94 reflects direct RTTI/bytes/xrefs while reserving 95+ because original symbols and exact bit-4 runtime label are absent.
- Lifecycle/class/setter at `90/93` reflect complete first-draft source with inferred private spellings/access. Vtable `90/94` reflects exact generated data and routes. File `89/91` reflects strong module placement but no embedded original path.
- Score-improvement attempts: queried missing UDTs (none); traced all constructor/setter callers; resolved each tail field through independent consumers; mapped virtual slots to accepted ObjectPane methods; checked allocator/free/no-op helper; compared ordinary/wrapper bodies; checked prior reports and all current support links. Every prior blocker is resolved or represented as a nonblocking confidence cap.

## Open Questions With Attempted Resolution

- Exact original field spellings/access: no PDB/source strings or IDA UDTs exist. All four roles are independently proven, and the proposed names match accepted project vocabulary. Cap class/lifecycle/setter confidence at 93; do not leave blank code.
- Setter name: historical `SetIntensity` conflicted with image-library/table-index use and the `-1` sentinel. Implemented `SetLightImageIndex` is the strongest descriptive source name; the old name remains only as search history.
- Setter return: undefined EAX on unchanged path and ignored caller results rule out a dependable non-void contract. Exact AttachObject/DetachObject directions support `void`.
- Flag bit 4 label: the branch pushes this and `0x138` to a one-byte return stub. It is safely classified as compiler/runtime guarded size/no-free behavior; exact runtime symbol spelling is unnecessary and excluded from source.
- Secondary facet names: offsets and thunk routes are exact, but inherited interface names are not symbol-proven. Document as adjusted inherited views; do not invent base-class names or lower owner confidence.
- Source file: no original path string exists, but the current map route is supported by class role and creators. Keep route and confidence cap rather than create a speculative file.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No explicit manual supervisor-owned coverage row requires a change.
- Validator-owned generated reports must derive from by-* metadata and Item Summary changes; this report supplies no manual generated-row text.

## Follow-Up Actions

- Supervisor actions: external report validation/execution/count/path/move/archive state is supervisor/validator-owned and is neither asserted nor directed by this artifact.
- A-agent actions: none asserted or directed by this artifact.
- B003 research/implementation actions: none remain; all C01-C20 destinations are complete and verified at report level.

## Confidence

- Recommendation confidence: `0.98` for wrapper/source disposition and ownership.
- Score confidence: `0.94` for target `90/94`; `0.92` for support score movements.
- Remaining uncertainty: exact original private spellings/access and internal runtime label for bit 4 only; neither changes behavior, ownership, range, or formal source shape.

## Validator Results

- Every manually changed by-* destination received a scoped validator under its one-file lease. All commands exited `0` with `ok:1`; each lease was released immediately afterward.

| Command ID | Timestamp | Scoped destination | Exit / ok | Material result and side effects |
| --- | --- | --- | --- | --- |
| `000000009487` | `2026-07-13T08:48:20-04:00` | UID0001DI validator-preserving old-path -> new-path rename | `0 / 1` | UID preserved; `path_update:1`, `uid_link_update:23`, `reference_source_path_update:7`, `autogen_registry_update:2`, score updates; generated refresh skipped. Validator-owned `by-memory/-ignored.md` and coverage/reference state changed as side effects, never manually. |
| `000000009488` | `2026-07-13T08:49:25-04:00` | `by-class/LightingObjectPane.md` | `0 / 1` | Exact class block and `90/93`; registry and score metadata updated; generated refresh skipped. |
| `000000009489` | `2026-07-13T08:51:05-04:00` | UID0001DG lifecycle | `0 / 1` | Exact constructor/destructor and `90/93`; registry and score metadata updated; generated refresh skipped. |
| `000000009490` | `2026-07-13T08:52:22-04:00` | UID0001DM target | `0 / 1` | Target `90/94`, exact evidence and marker destination validated; registry/score/reference-index side effects; generated refresh skipped. Validator normalized the bare UID marker, so B003 restored the accepted literal marker after validation; waited command 9517 later emitted that exact literal. |
| `000000009493` | `2026-07-13T08:53:38-04:00` | `by-file/LightingObjectPane.md` | `0 / 1` | File `89/91` and current role/source state validated; generated refresh skipped. |
| `000000009496` | `2026-07-13T08:55:15-04:00` | UID000359 vtable | `0 / 1` | Vtable `90/94`, tables/routes and marker destination validated; registry/score/reference side effects; generated refresh skipped. Validator normalized the marker, so B003 restored the accepted literal; 9517 emitted it exactly. |
| `000000009498` | `2026-07-13T08:56:06-04:00` | UID0001DL broad index | `0 / 1` | Wrapper/thunk/padding support validated; 17 pre-existing unrelated missing-reference UID diagnostics remained; generated refresh skipped. |
| `000000009501` | `2026-07-13T08:59:14-04:00` | UID00023D ObjectList lighting sync | `0 / 1` | Signed image-index/sentinel and UID0001DI caller semantics validated; projected stats updated; generated refresh skipped. |
| `000000009503` | `2026-07-13T09:00:07-04:00` | UID0001D9 EffectObjectPaneCore | `0 / 1` | Exact `0x00538a90`/frame `+0x0c` support validated; two pre-existing missing UID000382 diagnostics; UID0001DI label normalized; generated refresh skipped. |
| `000000009504` | `2026-07-13T09:00:48-04:00` | UID0000IZ Effects | `0 / 1` | Caller/owner and sentinel source-state wording validated; eight pre-existing UID0003HA/HC/HB/HD diagnostics; UID0001DI reference index/label updated; generated refresh skipped. |
| `000000009506` | `2026-07-13T09:01:40-04:00` | UID0001DH resolver | `0 / 1` | Rename/owner-separation support validated cleanly; generated refresh skipped. |
| `000000009507` | `2026-07-13T09:02:10-04:00` | UID0002TY raw notifier | `0 / 1` | Successor-name and no-route separation validated; two pre-existing missing UID0003J0 diagnostics; link label normalized; generated refresh skipped. |
| `000000009509` | `2026-07-13T09:02:55-04:00` | UID0002TZ mode-1 wrapper | `0 / 1` | Current predecessor/rejected-owner name validated; four pre-existing UID00037V/37W diagnostics; link label normalized; generated refresh skipped. |
| `000000009511` | `2026-07-13T09:03:32-04:00` | UID0002U0 mode-2 raw twin | `0 / 1` | Current neighborhood/rejected-owner name validated; four projected stats rows updated; link label normalized; generated refresh skipped. |
| `000000009513` | `2026-07-13T09:03:57-04:00` | UID000197 operator delete | `0 / 1` | UID0001DM normal-delete/bit-4 caller note validated; UID0001DM reference-index entry added; generated refresh skipped. |
| `000000009515` | `2026-07-13T09:05:01-04:00` | UID0000KO stale-current-state repair | `0 / 1` | Two residual current `SetIntensity` sentences corrected; clean `ok:1`; generated refresh skipped. |
| `000000009517` | `2026-07-13T09:05:27-04:00` | final UID0000KO `--wait-generated` verification | `0 / 1` | `generated_refresh:completed`; registry rebuilt with 4,620 nodes/3,761 edges; 279 generated metadata files refreshed; LightingObjectPane C++ and memory auto-coverage updated. Broad generator warnings (`children_marker_missing`, fallback insertion, no-code emitters) are unrelated; UID0000KO C++ updated successfully. |
| `000000009554` | `2026-07-13T09:22:04-04:00` | UID0001DM Gate 2 C02 size repair | `0 / 1` | Explicit `0xa2` (`162`) function-size boundary evidence validated; projected stats update reported; generated refresh deferred. Validator inserted a Markdown UID link into the already accepted marker, so B003 restored the exact accepted literal `// Emitted code for this range is covered by [UID:0001DG].` before releasing the lease. No generated/coverage file was edited manually. |

- B003 waited generated proof: command `000000009517`, refreshed `2026-07-13T09:05:27-04:00`, completed successfully. A later external validator refresh advanced the observed header to command `000000009534` at `2026-07-13T09:11:38-04:00`; read-only SHA256 was `E202041A86FFECB55FFA1064E6AF6C31871B83C2261497095CED8EFFC0779989`. That newer output still contains UID traces `000075`, `0001DG`, `0001DI`, `0001DM`, and `000359`; closes the class at line 27 before definitions beginning at line 30; emits the exact constructor/destructor/setter and two literal covered-by markers; and contains no Empty Emitter Marker, `SetIntensity`, `[[CHILDREN]]`, raw `+0x` audit comment, inferred/provisional comment, or `sub_` label.
- Known warnings were pre-existing/unrelated and did not make any scoped command fail. B003 did not manually edit validator state, generated files, coverage, tracker, supervisor, or lifecycle artifacts.

## Changed Files

- Historical B003 research/implementation-callback artifact before external lifecycle: `tools/leaser/Agents/Agent-B003/research/0001DM-LightingObjectPaneScalarDeletingDestructor-source-quality.md`.
- Validator-preserving rename: `by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity.md` -> `by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetLightImageIndex.md`, UID0001DI preserved by command 9487.
- Manually modified by-* destinations: `by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md`; `by-memory/0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle.md`; `by-class/LightingObjectPane.md`; renamed UID0001DI destination; `by-file/LightingObjectPane.md`; `by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md`; `by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md`; `by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md`; `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md`; `by-file/Effects.md`; `by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md`; `by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md`; `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`; `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`; and `by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`.
- Gate 2 C02 repair changed only `by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md` plus this same report: the target Boundary Notes now state `0xa2` (`162`) explicitly; no score, route, formal block, Item Summary, support page, generated file, or coverage file was changed manually.
- Verified unchanged: `by-class/AttachmentAnchorResolver.md` UID00000O, `by-memory/0x005374f0-0x005375e1.ObjectPaneAttachObject.md` UID0003XQ, and `by-memory/0x005375f0-0x005376b5.ObjectPaneDetachObject.md` UID0003XR. No verify-only edit or validator was needed.
- Validator-owned side effects only: command 9487 updated current UID/path links, reference-source paths, registry data, `by-memory/-ignored.md`, and coverage/reference state; command 9517 rebuilt registry/generated metadata and refreshed `auto-generated/NexusTK/map/LightingObjectPane.cpp` plus generated coverage. Later command 9534 was external validator-owned refresh state observed read-only. B003 made no manual edit to those owned artifacts.
- B003 ran no `execute_report`, report lifecycle, report-move, or archive command. External report path/count/status is supervisor/validator-owned and not asserted here.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact SHA `6E09C4F2E08B5AD07713D0E67699405463CB69F79C2A7D270619EE15FD72AE65` before implementation.
- [x] Target/support docs updated: UID0001DM, UID0001DG, UID000075, UID0001DI rename, UID0000KO, UID000359, UID0001DL, UID00023D, UID0001D9, UID0000IZ, UID0001DH, UID0002TY, UID0002TZ, UID0002U0, UID000197.
- [x] Historical pre-callback and implemented target states plus actual evidence are recorded.
- [x] Claim And Incorporation Ledger records applied destination and validator/generated proof for C01-C20.
- [x] Scores applied exactly: target `90/94`; lifecycle/class/setter `90/93`; vtable `90/94`; file `89/91`; named support scores unchanged.
- [x] Score-limiting blockers were resolved or represented by evidence-backed confidence caps after all reasonable routes were exhausted.
- [x] Owner/emitter/reconstructable state preserved: UID0001DM/UID0001DG/UID0001DI/UID000359 owner/emitter UID000075 and true state; class -> file route preserved.
- [x] No target split/new child; UID0001DI rename completed through validator-preserving workflow.
- [x] Source placement, exact range, both padding dispositions, generated-wrapper reclassification, and rename/type/comment recommendations applied.
- [x] Five exact managed blocks applied and emitted; compiler-only wrapper/thunk/vtable no-handwritten-source proof retained.
- [x] Third-party import directive confirmed not applicable; this is NexusTK project source.
- [x] Target/support facts incorporated at report-level detail without compressing history, negatives, or score rationale.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved explicitly.
- [x] Historical Wave2 naming was retained only as rejected search provenance and did not override current evidence.
- [x] Open questions closed or documented as evidence-backed nonblocking confidence caps.
- [x] Every changed/new/renamed by-* destination received a scoped validator under a short lease; final command 9517 completed waited generated verification and exact structure/name/marker checks.
- [x] Generated refresh was validator-owned; no manual generated/tracker/coverage edit occurred.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation at the exact Gate 1 SHA above.
- [x] All accepted target/support details incorporated at report-level depth.
- [x] C01-C20 ledger reconciled claim by claim with exact destinations and proof.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied exactly or verified unchanged where specified.
- [x] Historical assumptions, rejected alternatives, wrapper/source distinction, padding/thunks, borrowed-anchor semantics, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed nonblocking rationale.
- [x] Scoped validators and exact command metadata/results recorded.
- [x] Waited validator-owned generated refresh completed as B003 command 9517; newer external command 9534 was also verified read-only with the same correct structure/content.
- [x] Remaining unapplied accepted items: none.
- [x] No B003 lease remains; current shared lease table contains no B003 row.
- [x] Gate 2 C02 repair: UID0001DM Boundary Notes explicitly include `0xa2` (`162`) and endpoint subtraction; scoped command 9554 returned `exit 0`, `ok:1`; target lease released immediately; report ledger/validator/changed-file records synchronized.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000009582","destination_path":"executed-b-agent-research/B003/0001DM-LightingObjectPaneScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001DM-LightingObjectPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-07-13T09:41:58-04:00","uid":"0001DM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
