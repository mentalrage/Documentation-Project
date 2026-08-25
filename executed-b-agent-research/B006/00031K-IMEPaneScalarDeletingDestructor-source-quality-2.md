# UID00031K IMEPane Scalar Deleting Destructor Source-Quality Research
** TARGET-REPORT-UID:00031K **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Preserve [UID:00031K] as exact class-owned MSVC scalar-deleting-destructor evidence, not as a handwritten source function.
- Preserve current metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional emitter position, blank formal CPP and H channels, and `Nested:0`.
- Preserve the exact target range `[0x004e8720,0x004e87f9)`, 217 bytes, SHA256 `01FD105D1B35671F9B58C7CD556BD5CE39A481B5C7EA52920DE024C91B4FCFF4`.
- Preserve [UID:0004CB] as the sole human `IMEPane::~IMEPane()` definition and [UID:00006H] as the class declaration/source owner routed through [UID:0000K5].
- Emit no UID00031K marker, wrapper body, proof comment, pseudo-method, raw vtable array, explicit base-destructor call, explicit embedded-`List` destructor call, or hidden deleting-flags source API.
- Preserve the current source-quality IDA state as a no-change recommendation. The report-time MCP evidence includes a dated read-only canonical snapshot plus the earlier persisted-backup snapshot as corroboration; neither ephemeral session is permanent Gate 2B authority. A supervisor must freshly attest the canonical writable IDB before any later Gate 2B verification.
- The assignment-time tracker value `86/91` is superseded. The physical target and current tracker row are `92/94`, combined `93.0`.

## Supporting Research

### Current sources inspected

- Physical target and all directly affected support pages were reread; the target and UID0004CC received the two accepted ordinary repairs while all other support pages remained unchanged:
  - [UID:00031K] target: accepted pre-callback SHA256 `DBF77B65D82E1509211919D342539C7B5E1F60470CE925EF51C89901A18747E3`, 11,160 bytes, 108 lines; callback post-validation SHA256 `30CA332FD441A10BF7D68E844EB6455BC6CE8C685944725AF41802CCA940510E`, 12,506 bytes, 111 lines.
  - [UID:0004CB] ordinary destructor, SHA256 `B64D649DC5801EF12A3986610A872E4E0AEF822B3A812590829F06DCB46866D5`.
  - [UID:00006H] class, SHA256 `544585FF4205BB8C6DE1F73F7950F3A3A868691BFB453BF17336E8A300286655`.
  - [UID:0000K5] source file, SHA256 `112C86475795E35F56D9F484331A60CEB75F8427E0739B813601953E572CEBFF`.
  - [UID:00018C] mixed destructor aggregate, SHA256 `C6802376F4D32AA35F149F2C9004EDFA8F60058BE1ED6567633E45CCD3B9BA37`.
  - [UID:00018D] adjustor aggregate, SHA256 `A40F27BAC822887F691C75C1915F704C9D9175C2AD401CEDBB19A13793CAEB22`.
  - [UID:0000R7] global, SHA256 `5C536A062274538A511DE2743CBA247B2189C5FA26737075D1035B4CAA9A4080`.
  - [UID:0001PS] physical singleton, SHA256 `2C1830C724B3C1EC634C4490B16C36772F9230696B83E7540677D48F58EA4B2D`.
  - [UID:00025J] read-only data, SHA256 `35197EBCBCFAC568F0E45AE180AC386DBD0A38D91AC539775026636B370339ED`.
  - [UID:000192] `List` non-deleting destructor, SHA256 `705B1FF21EB473382ED33D64F7C181138135A1787BAA81EC6763DB7D4A575957`.
  - [UID:0004CC] focus-list mutator: pre-repair SHA256 `73979C8C92075E617C17450EDA25DC6B18859E2D01316DA3659E969A16DAF76D`; post-validation SHA256 `128D88FD73CE623E3FB341881861724D9148E2506E7359DC1E871CD3444341DB`, 9,034 bytes, 84 lines.
  - [UID:00031G] focus-caret helper, SHA256 `CB30D12CD845B9B4E0BF144DB1C055D662C1EB36C84C05812F33414DAD1F78CB`.
  - [UID:0000VN] ignored-range ledger, current SHA256 `B1AD3EA699D5F7F480B4D603D2C2EAB34C058DA4E3FA868F17F9AADC92FC8827`. The older SHA256 `DD29C6E675D7240E1186947A2596E8C607D5C0224D28BE1B977ED88C718FC13D` is retained only as the dated pre-callback snapshot.
- Current generated output was reread without modification under supervisor command `000000022920`:
  - `auto-generated/NexusTK/input/IMEPanes.cpp`, SHA256 `CF1820E928619F2B81F693D6CE43D1FD69F1F22061829487E83C61087C6669B3`, 18,691 bytes, 608 lines.
  - `auto-generated/NexusTK/input/IMEPanes.h`, SHA256 `60BB5D9B5CDD5A59AE001443E29FACFE2B279CF7F2BE9A3811EDF5ACEC78CAB2`, 1,161 bytes, 45 lines.
  - The CPP has exactly one UID0004CB marker and one `IMEPane::~IMEPane()` definition. CPP and H have zero UID00031K marker, name, body, proof-comment, or empty-emitter marker. H has one `class IMEPane`, one `virtual ~IMEPane();`, and one `extern IMEPane *g_pIMEPane;`.
- The current tracker produced by supervisor command `000000022920` is SHA256 `D5D26C9A1F4C1D11CC4AA971B7F0E8D374C09498AAB4136431139B577BBFAC46`, 2,048,170 bytes and 9,628 lines. Its UID00031K row remains `92/94`, combined `93.0`, false/non-emitting, owner-count one, and points to the older centrally executed B006 report.
- Historical generated evidence remains provenance only: command `000000022770` produced IMEPanes.cpp SHA256 `9B882082786624749A348FF6A72CDC04D9A1A3547D5E7CECA64969D5155744BE`, IMEPanes.h SHA256 `156CF84A288A6FF92185BFAF5E04214987FF5887A046847F1DCED8B404F26661`, and tracker SHA256 `3CFE9CFE70F8F8D4F0467CDC85F91173451CAC14D6A95E10C479436BC21068D4`; none is current authority.

### Matching-report reconciliation

- The older centrally executed B006 UID00031K report was read as historical evidence only. Its accepted behavior, ownership, non-emitting disposition, source form, and saved IDA state agree with this independent pass. Its execution/manual/generated receipts do not grant implementation credit to this new report.
- B008's earlier IMEPanes family report correctly identified UID00031K as compiler-generated and source-covered by a virtual destructor. Its former `86/91`, reconstructable/comment-emitting proof route is superseded by the current `92/94`, false, blank-formal, zero-generated-output policy.
- B008's UID0004CA constructor report independently supports the three-view vptr stores, singleton publication, `0x120` layout, and UID00006H to UID0000K5 source route. Accepted.
- B011's UID0004CB ordinary-destructor report independently supports the child-pane cleanup, implicit embedded-`List` teardown, singleton clear, base teardown, and sole human destructor definition. Its older phrase `comment-only` is corrected to false/non-emitting with blank formals and no generated marker.
- B004's UID00031J and UID00031L reports provide sibling compiler-wrapper precedent. Accepted only as analogy; this report independently rechecked UID00031K.
- B007's current UID00031I report uses the same current compiler-wrapper policy and does not conflict with this target.
- No other active direct UID00031K report was found. Log mentions and audit/catalog references are not research reports and are not treated as evidence.

## Target

- UID: `00031K`.
- Path: `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`.
- Title: `0x004e8720-0x004e87f9 IMEPaneScalarDeletingDestructor`.
- Exact binary interval: `[0x004e8720,0x004e87f9)`.
- Semantic entity: compiler-generated scalar deleting destructor for [UID:00006H] `IMEPane`.
- Current physical metadata: `92/94`, owner `00006H`, false, blank emitter/position/CPP/H, `Nested:0`.
- Assignment-time queue description `Not-Covered Files - Reconstructable` and score `86/91` are stale. The target is now covered, false/non-emitting, and at `92/94`.

## Current Target State

- The target page already contains the exact range, body hash, 70-instruction/15-block/complexity-3 identity, complete cleanup and ABI matrix, xrefs, callees, vtable topology, object layout, ordinary-destructor relationship, padding, no-code proof, current score rationale, and superseded history.
- Formal target CPP and H are blank. This is correct: the compiler generates this wrapper from the virtual destructor declaration, class layout, inheritance, and the ordinary destructor source body.
- Independent Gate 2A found and B006 repaired one support-doc contradiction in [UID:0004CC]: complete-object `+0x110` is now documented as embedded `focusPaneList.m_count` (`focusPaneList +0x104` plus `List::m_count +0x0c`), while `focusPaneCount` is only the source local initialized from `focusPaneList.GetCount()`. Command `000000022952` validated the repaired destination at SHA256 `128D88FD73CE623E3FB341881861724D9148E2506E7359DC1E871CD3444341DB`.
- The earlier dated read-only corroborating snapshot at `2026-08-12T18:23:35Z` used database `supervisor-uid00023D-postsave-20260812T154552Z`, path `C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\leaser\Agents\ida-backups\NexusTK.exe.uid00023D-postsave-20260812T154552Z.i64`, worker route `127.0.0.1:62259`, PID `24064`, generation `pid:24064;created:134310233919588087`. Runtime attestation returned top-level and worker `ok:true` with empty errors.
- A fresh dated canonical read-only snapshot at `2026-08-12T18:42:30.719805Z` used database `supervisor-canonical-20260812T-current`, exact path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker route `127.0.0.1:61513`, PID `24304`, generation `pid:24304;created:134310336483788981`. Runtime attestation returned top-level and worker `ok:true` with empty errors; server health returned `status:ok`, Hex-Rays ready, and the exact canonical path.
- Fresh canonical bounded reads reproduced target name `IMEPane__ScalarDeletingDestructor`, type `IMEPane *__thiscall(IMEPane *this, unsigned int deletingFlags)`, range size `0xd9`, exact five-row frame, accepted function-regular comment, blank entry address/function-repeatable channels, 217 target bytes with SHA256 `01FD105D1B35671F9B58C7CD556BD5CE39A481B5C7EA52920DE024C91B4FCFF4`, all three inbound refs, five unique runtime callees, and both adjustor prestates.
- The six formerly stale internal regular comments at `0x004e8739`, `0x004e8745`, `0x004e8775`, `0x004e8784`, `0x004e879e`, and `0x004e87ba` are blank; their repeatable channels are blank.
- Adjustors `0x004e8608` and `0x004e8613` have the source-quality names and function comments previously established. No current IDA mutation is recommended.
- The canonical and backup sessions are dated research snapshots, not reusable permanent authority. A supervisor must freshly discover and attest the canonical writable path before any later no-change Gate 2B readback.

## Executive Recommendation

The blocker is resolved, not deferred. The exact binary wrapper is live through one primary vtable cell and two adjusted vtable entries, but it has no ordinary caller and no independent human source API. Its entire derived cleanup is the same source-level destruction represented by UID0004CB, while the remaining flag, return-this, conditional storage release, complete-size, and one-byte no-op mechanics are MSVC ABI output.

Therefore:

1. Keep UID00031K false, non-emitting, and blank in both formal channels.
2. Keep UID0004CB as the only `IMEPane::~IMEPane()` definition.
3. Keep UID00006H's one virtual destructor declaration and coherent `0x120` layout.
4. Keep generated CPP/H free of UID00031K markers and wrapper code.
5. Preserve the current source-quality IDA state without replaying historical mutations.
6. Keep `92/94`; do not inflate confidence to 100 because original private names, exact compiler build switches, and original source-file spelling are unavailable.

## Supervisor Active Recheck

- The accepted pre-callback artifact SHA256 `AB3A6E68284CC2D1C16467668CEF41211FF231B30A3FA4C437BDC5B6E163DE52` passed supervisor Gate 1 `33/33` with exact `64/64` parity.
- The implementation callback physically reread every ordinary destination. Eleven support destinations and `by-memory/-ignored.md` already carried the accepted facts at same-or-greater detail and remained byte-identical; no artificial edits were made.
- The target alone contained stale active IDA identity/frame/comment wording. B006 historicalized that prestate, recorded the accepted canonical poststate without changing metadata/formals/source disposition, scoped-validated it, and physically reread the resulting artifact.
- Any later Gate 2B work is supervisor-only and begins with fresh `idb_list`, `server_health`, canonical disk identity, and `runtime_attestation`. Both dated report-time sessions are provenance, not reusable authority.
- Manual coverage, generated refresh/readback, and report lifecycle remain supervisor-owned.
- B006 ran only the one required scoped ordinary validator for the changed target. No IDA mutation, generated refresh, coverage edit, tracker edit, or lifecycle command was run.

## Inference Research Guidance Check

- Runtime fidelity: the source cause must regenerate equivalent ordinary destruction, virtual deleting entry points, adjusted subobject entries, hidden deleting flags, and allocation-release behavior.
- Human-source shape: do not reconstruct a pseudo-method named `ScalarDeletingDestructor`. A mid-2000s developer would write a virtual destructor and normal class members, not the compiler's hidden wrapper.
- Naming: `IMEPane`, `statusPane`, `activeChildPane`, `candidatePane`, `focusPaneList`, and `g_pIMEPane` are supported by convergent class/docs/IDA context. Raw `sub_`, `dword_`, `Block`, and offset-name forms do not belong in final source.
- Consistency is subordinate to behavior and plausible human source. Existing IMEPanes style uses `NULL`, direct member names, one declaration in H, and one body in CPP.
- Wave2/Wave3 references, if encountered in history, are ignored as stale.
- Third-party import is not applicable; this is first-party NexusTK UI source.

## Heuristic / Inference Reanalysis And Validation

| Question | Evidence exhausted | Resolution |
| --- | --- | --- |
| Handwritten method or compiler wrapper? | Hidden four-byte flags, return-this, `retn 4`, vtable-only/thunk reachability, optional allocation release, complete-size path, and ordinary-body parity. | Compiler-generated scalar deleting destructor; no handwritten target body. |
| Which source owns the cleanup? | UID0004CB decompile, formal CPP, child calls, embedded List destruction, singleton clear, and Pane base teardown. | UID0004CB is the sole human destructor definition. |
| Which class owns binary evidence? | Three IMEPane vtable views, exact `0x120` size, offsets `+0xf8..+0x11c`, constructor/destructor stores, and RTTI data. | UID00006H semantic owner. |
| Should UID00031K emit a proof comment? | Current false metadata, generated zero-marker state, sibling wrapper policy, and source completeness. | No. Keep formal CPP/H blank and evidence in documentation. |
| Is a separate focusPaneCount source field needed? | IDA `IMEPaneFocusList` projection, accepted `List` layout, `focusPaneList.GetCount()` source, and exact `0x14` embedded size. | No separate source field. Complete `List` at `+0x104`; its internal count projects at `+0x110`. |
| Should child slots be deleted directly? | All three calls target `Pane_MarkForDeletion`; slots are not cleared. | Source keeps `MarkForDeletion()`, not `delete`. |
| Should source explicitly destroy focusPaneList or call Pane destructor? | C++ member/base destruction semantics and existing compiler-lowered call order. | No explicit calls. Compiler performs member/base teardown. |
| Does bit 4 free storage? | Branch at `0x004e87b6`, push `0x120`, one-byte no-op callee, and no delete call on that branch. | No. It carries complete-object size to compiler/runtime glue. |
| Is range splitting required? | Exact modeled extent, predecessor/successor `0xcc`, adjustors separately modeled, and existing exact pages. | No split, merge, rename, or child creation. |
| Does the assignment score remain current? | Target metadata and tracker reread. | No. `86/91` is historical; `92/94` is current. |
| Is any IDA mutation still required? | Current read-only snapshot names, prototype, frame, comments, adjustors, xrefs, bytes, and UDTs. | No mutation recommended; fresh supervisor no-change verification only. |

## Evidence Standards Used

- Direct IDA facts: modeled ranges, names, types, stack frames, disassembly, decompile, block metrics, bytes, comments, xrefs, callees, integer values, and UDT members.
- Documentation facts: physical metadata, formal-channel contents, manual coverage rows, generated CPP/H, and tracker rows.
- Inference: compiler-generated/source-authored classification, original source shape, naming, ownership, source placement, and score caps. Inference is accepted only where multiple direct/document routes agree.
- Historical reports: leads and corroboration only. Every target-specific conclusion was checked against current physical docs, the dated canonical live MCP snapshot, and the independent persisted-backup snapshot.
- Negative evidence is explicit and does not convert absence alone into ownership or no-code proof.

## Evidence Checked

- MCP availability: `idb_list`, exact runtime attestation, server health, lookup, inspect, stack frame, comments, decompile, disassembly, analyze-function metrics, xrefs, callees, bytes, integer reads, entity query, and type query.
- Target: exact 217-byte function, 70 instructions, 15 blocks, complexity 3, five callees, three inbound refs, frame, comments, flags, exits, boundaries.
- Related functions: UID0004CB ordinary destructor, two root adjustors, three cleanup/base/runtime helpers.
- Data: three vtable cells and locators, `g_pIMEPane`, IMEPane/IMEPaneFocusList UDTs.
- Documentation: target, ordinary destructor, class, file, aggregate, adjustor, global, physical singleton, vtable/read-only data, List destructor, focus-list methods, ignored ranges.
- Generated output: current supervisor command `000000022920`, current CPP/H identities, one-definition/zero-wrapper counts, class declaration, and global extern.
- Manual coverage: target, ordinary destructor, aggregate, adjustor, class, file, global, physical singleton rows.
- Matching reports: direct prior UID00031K, IMEPanes family, constructor, ordinary destructor, sibling scalar wrappers.
- The original report-only research phase called no validator, lifecycle, or mutation endpoint. The accepted callback later ran only the scoped ordinary validators recorded in Section 31; no lifecycle or mutation endpoint was called.

## Claim And Incorporation Ledger

Rows now record the accepted callback disposition. Checked ordinary rows were physically verified; `applied` identifies the target or UID0004CC edit and validator receipt, while `already-present` identifies byte-preserved destinations whose accepted detail was confirmed. Unchecked `proposed` rows remain supervisor-owned generated, coverage, IDA, independent-gate, tracker, or lifecycle work.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C31K-001 | 00031K | Preserve exact target range, 217-byte size, and SHA256 `01FD105D1B35671F9B58C7CD556BD5CE39A481B5C7EA52920DE024C91B4FCFF4`. | direct | bytes/function/docs | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Status and Binary Identity | already-present | already-present |
| C31K-002 | 00031K | Preserve 70 instructions, 15 blocks, complexity 3, and exact five-callee inventory. | direct | disasm/analyze/callees | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Binary Identity and Behavior | already-present | already-present |
| C31K-003 | 00031K | Record dated canonical report-time IDA target name/type/five-row frame and all four entry comment channels without treating either observed session as permanent Gate 2B authority. | direct | canonical inspect/frame/comments/attestation plus corroborating backup snapshot | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Status and Binary Identity | incorporate | applied |
| C31K-004 | 00031K | Preserve vptr restores at complete offsets 0, `+0xa0`, and `+0xa4`. | direct | disasm/data refs | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Behavior and Vtable Evidence | already-present | already-present |
| C31K-005 | 00031K | Preserve non-null deferred deletion of `statusPane +0xf8`, `activeChildPane +0xfc`, and `candidatePane +0x100` without slot clears. | direct | decompile/disasm | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Behavior | already-present | already-present |
| C31K-006 | 00031K | Preserve implicit cleanup of embedded `focusPaneList +0x104` through UID000192. | very high | callee/layout/ordinary parity | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Behavior and Reconstruction Notes | already-present | already-present |
| C31K-007 | 00031K | Preserve singleton clear at `0x004e87a0`, zero value, and exact 17-xref context. | direct | disasm/get_int/xrefs | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Behavior and Cross-References | already-present | already-present |
| C31K-008 | 00031K | Preserve Pane base teardown as compiler lowering, not explicit developer source. | very high | call order/C++ semantics | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Reconstruction Notes | already-present | already-present |
| C31K-009 | 00031K | Preserve bit-1-clear teardown-without-free behavior. | direct | branch audit | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / ABI Flag Matrix | already-present | already-present |
| C31K-010 | 00031K | Preserve bit-1-set/bit-4-clear operator-delete behavior. | direct | branch/callee audit | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / ABI Flag Matrix | already-present | already-present |
| C31K-011 | 00031K | Preserve bit-4 complete-size `0x120` one-byte no-op path and no-free conclusion. | direct | disasm/callee/size | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / ABI Flag Matrix and Negative Evidence | already-present | already-present |
| C31K-012 | 00031K | Preserve return-this in EAX, `retn 4`, and four-byte hidden deleting-flags ABI. | direct | exits/frame | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / ABI | already-present | already-present |
| C31K-013 | 00031K | Preserve exact callee identities `0x544690`, `0x4f30e0`, `0x544580`, `0x4f4ac0`, and `0x41b6a0`. | direct | callees | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Callee Inventory | already-present | already-present |
| C31K-014 | 00031K | Preserve inbound refs code `0x4e860e`, code `0x4e8619`, data `0x61c4fc`, and zero ordinary callers. | direct | xref query/analyze | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Xref Inventory | already-present | already-present |
| C31K-015 | 00031K | Preserve exact two adjustors, `0xa0/0xa4` deltas, target jumps, ranges, and hashes. | direct | disasm/bytes/docs | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Adjustor Evidence | already-present | already-present |
| C31K-016 | 00031K | Preserve complete nine-store constructor/ordinary/target three-view restoration topology. | direct | xrefs/disasm | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Vtable Evidence | already-present | already-present |
| C31K-017 | 00031K | Preserve exact `0x120` class layout with one complete `0x14` List at `+0x104`; reject a separate source `focusPaneCount` member. | very high | UDT/formals/helper source | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Object Layout | already-present | already-present |
| C31K-018 | 00031K | Preserve UID0004CB as sole human destructor definition and UID00031K as compiler-only allocation-selection glue. | very high | body parity/formals/generated | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Source Disposition | already-present | already-present |
| C31K-019 | 00031K | Preserve exact padding, title/path/range, and `Nested:0`; no split or merge. | direct | bytes/ignored ledger | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Range and Padding | already-present | already-present |
| C31K-020 | 00031K | Preserve metadata `92/94`, owner 00006H, false, blank emitter/position/CPP/H, `Nested:0`. | very high | current page/source proof | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / metadata and formal channels | already-present | already-present |
| C31K-021 | 00031K | Preserve score rationale: all source-form blockers closed; cap only unavailable original symbols/build provenance. | high | complete evidence matrix | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Score Rationale | already-present | already-present |
| C31K-022 | 00031K | Preserve former `85/90`, `86/91`, reconstructable, emitter, and proof-comment routes only as superseded history. | very high | history/current state | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Reconstruction Notes and Changes | historicalize | already-present |
| C31K-023 | 0000K5 | Supervisor generated readback must verify one UID0004CB body/declaration route and zero UID00031K marker/name/body/proof/empty output. | very high | supervisor command `000000022920`; current CPP `CF1820E928619F2B81F693D6CE43D1FD69F1F22061829487E83C61087C6669B3` and H `60BB5D9B5CDD5A59AE001443E29FACFE2B279CF7F2BE9A3811EDF5ACEC78CAB2` | generated `NexusTK/input/IMEPanes.cpp` and `IMEPanes.h` / supervisor readback | incorporate | proposed |
| C31K-024 | 0004CB | Preserve UID0004CB `91/94`, owner/emitter 00006H, exact formal destructor, wrapper parity, and sole-source rationale. | very high | ordinary body/formals | `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md` / all substantive sections | already-present | already-present |
| C31K-025 | 00006H | Preserve UID00006H `91/94`, owner/emitter 0000K5, exact CPP/H split, coherent List layout, virtual destructor, and UID00031K false route. | very high | class formals/UDTs | `by-class/IMEPane.md` / formals, Method Notes, Evidence, Score | already-present | already-present |
| C31K-026 | 0000K5 | Preserve UID0000K5 `91/90`, IMEPanes CPP/H route, one ordinary root destructor, and zero root scalar-wrapper output. | high | file/generated/formals | `by-file/IMEPanes.md` / Proposed Contents, Evidence, Generated Expectations | already-present | already-present |
| C31K-027 | 00018C | Preserve aggregate `86/91`, false, exact UID00031K `92/94` compiler-wrapper inventory, and source route via UID0004CB/00006H. | high | aggregate reread | `by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md` / Item Summary and inventory | already-present | already-present |
| C31K-028 | 00018D | Preserve aggregate `85/90`, false, root adjustor ranges/deltas/hashes/names/vtable routes, and no-source disposition. | very high | adjustor disasm/docs | `by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md` / inventory and Evidence | already-present | already-present |
| C31K-029 | 0000R7 | Preserve `IMEPane *g_pIMEPane = NULL;`, 17-xref lifecycle, and raw-name history. | very high | entity/value/xrefs/formal CPP | `by-global/g_pIMEPane.md` / Status, Evidence, Reconstruction Notes | already-present | already-present |
| C31K-030 | 0001PS | Preserve zero/null four-byte storage, parent 0000R7 route, covered-by formal, and 17-xref lifecycle. | very high | bytes/value/xrefs/docs | `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md` / Status, Data, Evidence | already-present | already-present |
| C31K-031 | 00025J | Preserve IMEPane primary/secondary/tertiary vtable cells and three restoration sets without raw table emission. | high | data bytes/ints/xrefs/docs | `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` / Observed Contents and Reconstruction Notes | already-present | already-present |
| C31K-032 | 000192 | Preserve UID000192 as implicit embedded-member teardown support, not target-owned explicit source. | high | callee/List formals | `by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md` / Behavior and Source Shape | already-present | already-present |
| C31K-033 | 0000VN | Preserve exact ignored predecessor and successor `0xcc` runs and hashes. | direct | bytes/ignored ledger | `by-memory/-ignored.md` / exact `0x004e8715` and `0x004e87f9` rows | already-present | already-present |
| C31K-034 | 00031K | Supervisor must verify the manual by-memory target row remains exact `92%` false/non-emitting wrapper text. | high | manual row reread | `by-memory/-coverage-report.md` / UID00031K row | already-present | proposed |
| C31K-035 | 0004CB | Supervisor must verify the manual ordinary-destructor row remains exact `91%` sole-source text. | high | manual row reread | `by-memory/-coverage-report.md` / UID0004CB row | already-present | proposed |
| C31K-036 | 00018C | Supervisor must verify the manual aggregate row retains all four wrapper/source relationships. | high | manual row reread | `by-memory/-coverage-report.md` / UID00018C row | already-present | proposed |
| C31K-037 | 00018D | Supervisor must verify the manual adjustor row retains all eight non-emitting routes. | high | manual row reread | `by-memory/-coverage-report.md` / UID00018D row | already-present | proposed |
| C31K-038 | 00006H | Supervisor must verify the manual class row retains complete layout/lifecycle and UID00031K distinction. | high | manual row reread | `by-class/-coverage-report.md` / UID00006H row | already-present | proposed |
| C31K-039 | 0000K5 | Supervisor must verify the manual file row retains four human destructors and four non-emitting wrappers. | high | manual row reread | `by-file/-coverage-report.md` / UID0000K5 row | already-present | proposed |
| C31K-040 | 0000R7 | Supervisor must verify the manual global row retains source definition, zero value, type, and 17 xrefs. | high | manual row reread | `by-global/-coverage-report.md` / UID0000R7 row | already-present | proposed |
| C31K-041 | 0001PS | Supervisor must verify the manual singleton row retains zero/null storage and 17-xref lifecycle. | high | manual row reread | `by-memory/-coverage-report.md` / UID0001PS row | already-present | proposed |
| C31K-042 | IDA:N01 | Fresh canonical Gate 2B must verify target name/type/range/body/frame and comments exactly as N01, with no mutation. | direct | dated live snapshot | canonical IDB `0x004e8720` / N01 | already-present | proposed |
| C31K-043 | IDA:N02 | Fresh canonical Gate 2B must verify six internal address comment pairs remain blank. | direct | dated comments snapshot | canonical IDB six target instruction addresses / N02 | already-present | proposed |
| C31K-044 | IDA:N03 | Fresh canonical Gate 2B must verify A0 adjustor name/type/frame/comment/body/xref exactly, with no mutation. | direct | dated live snapshot | canonical IDB `0x004e8608` / N03 | already-present | proposed |
| C31K-045 | IDA:N04 | Fresh canonical Gate 2B must verify A4 adjustor name/type/frame/comment/body/xref exactly, with no mutation. | direct | dated live snapshot | canonical IDB `0x004e8613` / N04 | already-present | proposed |
| C31K-046 | IDA:P01 | Fresh canonical Gate 2B must protect target bytes/CFG/xrefs/callees/vtables/UDTs/global/value and padding. | direct | complete MCP inventory | canonical IDB / P01 | already-present | proposed |
| C31K-047 | IDA:G2B | Supervisor must freshly discover/attest canonical authority and fail closed on any drift; no save is authorized by this report. | procedural | runtime identity rules | canonical IDB / supervisor Gate 2B | incorporate | proposed |
| C31K-048 | 00031K | If callback discovers target drift and edits it, run its scoped no-generated-refresh validator and retain exact receipt; otherwise document verified no-change. | procedural | workflow | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / validator receipt | incorporate | applied |
| C31K-049 | 0004CB | If callback edits UID0004CB, run its scoped validator; otherwise document verified no-change. | procedural | workflow | UID0004CB / validator receipt | incorporate | already-present |
| C31K-050 | 00006H | If callback edits UID00006H, run its scoped validator; otherwise document verified no-change. | procedural | workflow | `by-class/IMEPane.md` / validator receipt | incorporate | already-present |
| C31K-051 | 0000K5 | If callback edits UID0000K5, run its scoped validator; otherwise document verified no-change. | procedural | workflow | `by-file/IMEPanes.md` / validator receipt | incorporate | already-present |
| C31K-052 | 00018C | If callback edits UID00018C, run its scoped validator; otherwise document verified no-change. | procedural | workflow | UID00018C / validator receipt | incorporate | already-present |
| C31K-053 | 00018D | If callback edits UID00018D, run its scoped validator; otherwise document verified no-change. | procedural | workflow | UID00018D / validator receipt | incorporate | already-present |
| C31K-054 | 0000R7 | If callback edits UID0000R7, run its scoped validator; otherwise document verified no-change. | procedural | workflow | `by-global/g_pIMEPane.md` / validator receipt | incorporate | already-present |
| C31K-055 | 0001PS | If callback edits UID0001PS, run its scoped validator; otherwise document verified no-change. | procedural | workflow | UID0001PS / validator receipt | incorporate | already-present |
| C31K-056 | GATE2A | Supervisor must independently verify every accepted ordinary claim against physical destinations after any callback. | procedural | Rule 26 | all named ordinary by-* destinations / Gate 2A | incorporate | proposed |
| C31K-057 | GATE2B | Supervisor must independently verify N01-N04/P01 under fresh canonical attestation; no-change means no save. | procedural | IDA gate | canonical IDB / Gate 2B | incorporate | proposed |
| C31K-058 | COVERAGE | Supervisor must verify manual rows and apply only exact drift corrections; B006 never edits coverage reports. | procedural | coverage boundary | four manual `-coverage-report.md` files / named rows | incorporate | proposed |
| C31K-059 | GENERATED | Supervisor-generated closure must physically verify CPP/H one-definition/zero-wrapper state after any coherent refresh. | procedural | current supervisor command `000000022920`; CPP `CF1820E928619F2B81F693D6CE43D1FD69F1F22061829487E83C61087C6669B3`, H `60BB5D9B5CDD5A59AE001443E29FACFE2B279CF7F2BE9A3811EDF5ACEC78CAB2` | generated IMEPanes CPP/H / supervisor readback | incorporate | proposed |
| C31K-060 | 00006H | Preserve exact class CPP/H source: self-header plus children in CPP; full declaration, one List, one virtual destructor, extern, size guard, children in H. | very high | physical formals/generated H | `by-class/IMEPane.md` / formal CPP and H channels | already-present | already-present |
| C31K-061 | 0004CC | Preserve `focusPaneList.GetCount()` local source expression and reject a separate `focusPaneCount` member. | high | formal CPP plus repaired Behavior/Evidence; command `000000022952`; SHA256 `128D88FD73CE623E3FB341881861724D9148E2506E7359DC1E871CD3444341DB` | `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md` / formal CPP, Behavior, Evidence, and Changes | incorporate | applied |
| C31K-062 | 00031G | Preserve `focusPaneList.GetCount()` caret-helper expression and human method source. | high | formal CPP/layout | `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md` / formal CPP | already-present | already-present |
| C31K-063 | TRACKER | Preserve current command-`000000022920` tracker interpretation `92/94`, combined `93.0`, false/non-emitting, with SHA256 `D5D26C9A1F4C1D11CC4AA971B7F0E8D374C09498AAB4136431139B577BBFAC46`; retain older tracker identities only as dated history. | direct | current tracker reread; 2,048,170 bytes/9,628 lines | `auto-generated/-ag-research-tracker.md` / UID00031K row | already-present | proposed |
| C31K-064 | LIFECYCLE | Report execution/archive authority remains supervisor-only and comes from current path plus validator-owned metadata/history. | procedural | role boundary | validator-owned report lifecycle / current report path and footer | not-applicable | proposed |

## Positive Evidence Summary

- Exact modeled target bounds and bytes agree with the physical page.
- Hidden flags, return-this ABI, `retn 4`, allocation branch, and complete-size no-op branch are canonical scalar-deleting-destructor mechanics.
- Three vptr restores and three view-specific vtable entries tie the wrapper to IMEPane.
- Two adjusted entries subtract exactly the class's `+0xa0` and `+0xa4` subobject offsets.
- UID0004CB performs the same derived cleanup without hidden allocation selection.
- The class declaration and ordinary body are complete enough to express the human source cause.
- Generated CPP/H currently show exactly one ordinary destructor and zero wrapper output.
- Target, support, manual coverage, and current tracker all agree on false/non-emitting `92/94`.
- Current canonical read-only IDA state is already source-quality for the target and adjustors, with the independent backup snapshot in exact material agreement.

## IDA MCP Facts

### Dated runtime identity

- Canonical listener/worker attestation at `2026-08-12T18:42:30.370752Z` / `2026-08-12T18:42:30.719805Z` returned `ok:true` with empty errors.
- Canonical database: `supervisor-canonical-20260812T-current`.
- Canonical IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Canonical worker route `127.0.0.1:61513`; PID `24304`; creation `134310336483788981`; generation `pid:24304;created:134310336483788981`.
- Canonical health: `status:ok`, Hex-Rays ready, strings cache ready. `auto_analysis_ready:false` was context only because every bounded IDB-backed query succeeded.
- The earlier persisted-backup snapshot at `2026-08-12T18:23:35Z` used database `supervisor-uid00023D-postsave-20260812T154552Z`, path `C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\leaser\Agents\ida-backups\NexusTK.exe.uid00023D-postsave-20260812T154552Z.i64`, route `127.0.0.1:62259`, and generation `pid:24064;created:134310233919588087`. It independently reproduced every material target/adjustor prestate. Both identities are dated research provenance only.

### Target

- `lookup_funcs`: `0x004e8720`, name `IMEPane__ScalarDeletingDestructor`, size `0xd9`.
- `inspect_items`: code head `0x4e8720`, first item `[0x4e8720,0x4e8721)`, type `IMEPane *__thiscall(IMEPane *this, unsigned int deletingFlags)`.
- Frame:
  - `var_C +0x8`, size 4, `_DWORD`.
  - `var_4 +0x10`, size 4, `_DWORD`.
  - `__saved_registers +0x14`, size 4, `_DWORD`.
  - `__return_address +0x18`, size 4, `_UNKNOWN *`.
  - `deletingFlags +0x1c`, size 4, `unsigned int`.
- Function regular comment exactly: `Compiler-generated IMEPane scalar deleting destructor: repeats UID0004CB child-pane, focus-list, singleton, and Pane teardown; frees storage only when deletingFlags mask 0x1 is set and mask 0x4 is clear; carries complete-object size 0x120 on the mask-0x4 one-byte runtime no-op path. Human source is virtual IMEPane::~IMEPane(); do not hand-author this wrapper.`
- Function repeatable, address regular, and address repeatable comments are blank.
- Six internal regular/repeatable comment pairs are blank at `0x004e8739`, `0x004e8745`, `0x004e8775`, `0x004e8784`, `0x004e879e`, and `0x004e87ba`.
- Analyze-function: 217 bytes, 15 blocks, complexity 3, zero callers, five unique callees.
- Disassembly: 70 instructions; exact `test al,1`, `test al,4`, operator-delete branch, `push 0x120` no-op branch, and two `retn 4` exits.

### Adjustors, vtables, global, and UDTs

- `0x004e8608`: `IMEPane__ScalarDeletingDestructorAdjustorA0`, size 11, type `_DWORD *__thiscall(_DWORD *this, char)`, frame only return address `+0x0/4 _UNKNOWN *`, exact `sub ecx,0xa0; jmp 0x004e8720`, sole data ref `0x0061c548`, accepted function comment, other comment channels blank.
- `0x004e8613`: `IMEPane__ScalarDeletingDestructorAdjustorA4`, size 11, same projected type/frame, exact `sub ecx,0xa4; jmp 0x004e8720`, sole data ref `0x0061c578`, accepted function comment, other channels blank.
- Primary/secondary/tertiary cells read `0x004e8720`, `0x004e8608`, `0x004e8613`. Their names are `??_7IMEPane@@6B@`, `??_7IMEPane@@6B@_0`, `??_7IMEPane@@6B@_1`.
- Cell refs are exactly constructor `0x004e7f87/8d/97`, ordinary destructor `0x004e802b/31/3b`, and target `0x004e8752/58/62`.
- `g_pIMEPane` value is zero. `entity_query` resolves global/name `g_pIMEPane`; `inspect_items` projects a blank item name and type `IMEPane *`. This tool-projection difference is documented, not a mutation request. Xref query returns 17 exact data refs.
- IMEPane ordinal 674 is size 288 with `_paneBase 0/248`, `statusPane +0xf8/4`, `activeChildPane +0xfc/4`, `candidatePane +0x100/4`, `focusPaneList +0x104/20`, `focusCaretAnchorY +0x118/4`, `focusCaretAnchorX +0x11c/4`.
- IMEPaneFocusList ordinal 673 is size 20 with opaque 12-byte head, count projection `+0xc/4`, and four-byte tail. It corroborates binary layout; source uses the established `List` type.

## Function / Child Inventory

| Range/entity | Role | Source-bearing | Owner/route | Disposition |
| --- | --- | --- | --- | --- |
| `[0x004e8720,0x004e87f9)` | Root IMEPane scalar deleting wrapper | No | UID00006H semantic owner | False, blank, compiler-generated |
| `[0x004e8608,0x004e8613)` | Secondary-view deleting adjustor | No | UID00031K/UID00018D evidence | Compiler-generated no-source |
| `[0x004e8613,0x004e861e)` | Tertiary-view deleting adjustor | No | UID00031K/UID00018D evidence | Compiler-generated no-source |
| `[0x004e8000,0x004e8098)` | Ordinary `IMEPane::~IMEPane()` | Yes | UID0004CB -> UID00006H -> UID0000K5 | Sole human destructor body |
| `0x00544690` | Deferred child-pane deletion helper | Existing support | Pane source | Callee evidence only |
| `[0x004f30e0,0x004f3139)` | `List::~List()` non-deleting body | Yes | UID000192 -> UID000079 | Implicit member teardown |
| `0x00544580` | Pane non-deleting destructor | Existing support | Pane source | Implicit base teardown |
| `0x004f4ac0` | Project operator-delete wrapper | Existing runtime support | Memory manager/runtime | Compiler wrapper callee |
| `0x0041b6a0` | One-byte guard no-op | No target source | Runtime/compiler | Size-carrying no-free path |
| `0x0061c4fc` | Primary vtable cell | No raw source array | UID00006H/UID00025J | Compiler-emitted data |
| `0x0061c548` | Secondary vtable cell | No raw source array | UID00006H/UID00025J | Compiler-emitted data |
| `0x0061c578` | Tertiary vtable cell | No raw source array | UID00006H/UID00025J | Compiler-emitted data |
| `0x0069b458` | `g_pIMEPane` storage | Covered source | UID0001PS -> UID0000R7 -> UID0000K5 | One global definition |
| `[0x004e8715,0x004e8720)` | Predecessor alignment | No | UID0000VN | Ignored `0xcc` |
| `[0x004e87f9,0x004e8800)` | Successor alignment | No | UID0000VN | Ignored `0xcc` |

No ordinary/raw/compiler-generated target child is omitted. The wrapper, both adjusted entries, source destructor, cleanup dependencies, singleton, vtables, and both padding runs all have explicit dispositions.

## Direct Xref / Caller Inventory

### Target and adjustors

- Target `0x004e8720`: exactly three inbound references:
  - code `0x004e860e` from A0 adjustor;
  - code `0x004e8619` from A4 adjustor;
  - data `0x0061c4fc` from primary vtable.
- A0 adjustor `0x004e8608`: exactly one data reference, `0x0061c548`.
- A4 adjustor `0x004e8613`: exactly one data reference, `0x0061c578`.
- Analyze-function reports zero ordinary target callers. This is expected vtable/thunk reachability, not dead-code proof.

### Vtable cells

- Primary cell refs: `0x004e7f87`, `0x004e802b`, `0x004e8752`.
- Secondary cell refs: `0x004e7f8d`, `0x004e8031`, `0x004e8758`.
- Tertiary cell refs: `0x004e7f97`, `0x004e803b`, `0x004e8762`.

### Singleton

Exact data refs to `0x0069b458`: `0x004e74b0`, `0x004e7689`, `0x004e77c2`, `0x004e77d3`, `0x004e7a83`, `0x004e7c46`, `0x004e7f68`, `0x004e7f6f`, `0x004e8079`, `0x004e8391`, `0x004e85b0`, `0x004e87a0`, `0x004f64ac`, `0x0058e0d0`, `0x0058e1ff`, `0x0058ead2`, and `0x0059545a`.

## Documentation Evidence And IDA Status

- Current ordinary documentation is coherent and incorporates the target behavior, ownership, no-source route, scores, source form, and one-complete-List layout. The callback repaired the target's stale active IDA identity/frame/comment wording; the Gate 2A repair then corrected UID0004CC so `+0x110` is active `focusPaneList.m_count` evidence and the separate-IMEPane-field interpretation remains only superseded history.
- Historical stale states remain clearly dated:
  - target `85/90` or `86/91`;
  - reconstructable true;
  - emitter UID00006H;
  - proof-comment formal CPP;
  - raw target name/type and stale interior comments;
  - separate source `focusPaneCount`.
- Current physical target state is `92/94`, false, blank emitter/formals, `Nested:0`.
- Current canonical IDA report-time snapshot is source-quality and requires no mutation; the earlier backup snapshot independently corroborates it. Neither dated session can be cited as permanent Gate 2B authority.
- Current supervisor command `000000022920` shows the desired source consequence in IMEPanes.cpp SHA256 `CF1820E928619F2B81F693D6CE43D1FD69F1F22061829487E83C61087C6669B3` and IMEPanes.h SHA256 `60BB5D9B5CDD5A59AE001443E29FACFE2B279CF7F2BE9A3811EDF5ACEC78CAB2`: one ordinary destructor route and no target wrapper output.
- The current command-`000000022920` tracker is SHA256 `D5D26C9A1F4C1D11CC4AA971B7F0E8D374C09498AAB4136431139B577BBFAC46`, 2,048,170 bytes/9,628 lines, and retains UID00031K at `92/94`, combined `93.0`, false/non-emitting. Command `000000022770` and tracker SHA256 `3CFE9CFE70F8F8D4F0467CDC85F91173451CAC14D6A95E10C479436BC21068D4` are dated historical evidence only.
- Manual coverage rows are current at report time. Exact generated/manual hashes are snapshots and may drift after unrelated coherent refreshes; semantic requirements remain authoritative.

## Ranked Ownership Analysis

### 1. UID00006H IMEPane

- Evidence for: exact three-view IMEPane vtables, `0x120` layout, constructor/ordinary/target vptr stores, IMEPane fields, singleton, UID0004CB parity, class declaration, and source route.
- Evidence against: the target is not an independently handwritten method.
- Decision: semantic binary owner and compiler source cause. Keep `CANONICAL_OWNER:00006H`, false, no emitter.

### 2. UID0004CB IMEPane ordinary destructor

- Evidence for: byte-for-behavior derived cleanup parity and the exact human `IMEPane::~IMEPane()` body.
- Evidence against: it is a source-bearing sibling, not the target's metadata owner.
- Decision: sole source definition and covered behavior, not target owner.

### 3. UID0000K5 IMEPanes source file

- Evidence for: source container for UID00006H, UID0004CB, `g_pIMEPane`, and generated CPP/H.
- Evidence against: by-memory target ownership should remain class-specific rather than direct FILE ownership.
- Decision: indirect source container through UID00006H.

### Rejected alternatives

- UID00018C and UID00018D are broad binary indexes, not source owners.
- UID00025J is compiler-emitted read-only data support, not source owner.
- UID0000R7 owns the singleton definition, not the destructor.
- UID000192 owns List destruction, not IMEPane.
- Pane source owns base teardown only.
- A standalone wrapper source file or explicit deleting-wrapper method would reproduce decompiler structure, not plausible developer source.

### Proposed new file/grouping, if applicable

- None. Existing `NexusTK/input/IMEPanes.cpp` and `IMEPanes.h` are coherent.

## Source Placement

- Class declaration: [UID:00006H] formal H -> `NexusTK/input/IMEPanes.h`.
- Class source shell and children: [UID:00006H] formal CPP -> `NexusTK/input/IMEPanes.cpp`.
- Human destructor definition: [UID:0004CB] under UID00006H.
- Singleton definition: [UID:0000R7] under UID0000K5.
- UID00031K, its adjustors, and raw vtable data: no handwritten source placement; regenerated by the compiler from class/destructor/inheritance layout.
- Rejected: direct raw wrapper body, source-level hidden flags, explicit vtable arrays, separate ABI helper file, or direct file ownership bypassing the class.
- Remaining uncertainty is only historical original filename/capitalization and private naming, already bounded by current project conventions.

## Range / Split / Padding / Reclassification Analysis

- Target range is exact and already split: `[0x004e8720,0x004e87f9)`.
- Predecessor `[0x004e8715,0x004e8720)`: eleven `0xcc`, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.
- Successor `[0x004e87f9,0x004e8800)`: seven `0xcc`, SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`.
- Both adjustors are separate modeled functions inside UID00018D.
- No nested child, merge, range expansion, title change, path change, or `Nested` change is warranted.
- Reclassification from reconstructable/proof-emitting to false/non-emitting/blank already occurred and is correct.
- Parent/container impact is documentation-only: UID00018C/00018D/00025J index compiler artifacts while UID00006H/0004CB carry source.

## Negative Evidence Summary

- No ordinary caller to UID00031K exists; only two adjusted jumps and one primary vtable data ref. This supports compiler-wrapper liveness, not dead code.
- No target-specific source behavior remains after subtracting UID0004CB cleanup and standard member/base teardown.
- No evidence supports a source `ScalarDeletingDestructor` method or hidden flags parameter.
- No evidence supports direct `delete` of child panes; calls are `MarkForDeletion`.
- No evidence supports clearing child slots in this destructor.
- No evidence supports explicit `focusPaneList.~List()` or `Pane::~Pane()` calls in human source.
- No evidence supports a separate source `focusPaneCount`; the binary count lies inside the complete `List`.
- No evidence supports hand-authored primary/secondary/tertiary vtable arrays or adjustor functions.
- No evidence supports storage release on the bit-4 branch.
- No evidence supports changing bounds, padding, title, path, owner, emitter, or `Nested`.
- The old proof-comment approach is rejected because false compiler artifacts should not emit marker text into reconstructed source.
- The assignment-time tracker state is rejected as stale by current physical metadata and tracker readback.

## IDA Rename / Type / Comment Recommendations

### Runtime binding

The dated report-time canonical and backup sessions are evidence only. Before any later Gate 2B, the supervisor must issue a fresh `idb_list {}`, select the active database whose normalized path is exactly `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, record its literal returned session identifier, call `server_health` with that identifier, record canonical disk path/hash/size, and call `runtime_attestation` with both `expected_database` and `expected_canonical_path`. Every following readback must use that same literal returned database identifier. Any identity, worker-generation, path, module, error, or prestate mismatch fails closed. This report authorizes no mutation and no save.

| ID | Entity and literal dated prestate | Disposition | Protection and expected fresh readback |
| --- | --- | --- | --- |
| N01 | Function `0x004e8720`; `[0x004e8720,0x004e87f9)`; 217 bytes; SHA `01FD105D1B35671F9B58C7CD556BD5CE39A481B5C7EA52920DE024C91B4FCFF4`; name `IMEPane__ScalarDeletingDestructor`; type `IMEPane *__thiscall(IMEPane *this, unsigned int deletingFlags)`; frame exactly `var_C +0x8/4 _DWORD`, `var_4 +0x10/4 _DWORD`, saved `+0x14/4 _DWORD`, return `+0x18/4 _UNKNOWN *`, `deletingFlags +0x1c/4 unsigned int`; address regular/repeatable blank; function repeatable blank; function regular exact text recorded in IDA MCP Facts. | Already present; no change recommended. | Fresh inspect/frame/comments/analyze/disasm must reproduce every literal field, 70 instructions, 15 blocks, complexity 3, five callees, and three inbound refs. No rename, type, comment, local, boundary, byte, or save action. |
| N02 | Instruction items `0x004e8739`, `0x004e8745`, `0x004e8775`, `0x004e8784`, `0x004e879e`, `0x004e87ba`; each current regular and repeatable channel blank. Items remain code within N01; labels at `0x4e8775` and `0x4e8784` are protected. | Already present; no change recommended. | Fresh comments must return twelve blank channels. Preserve exact instruction heads/ends, labels, bytes, target function state, and every unrelated comment. |
| N03 | Function `0x004e8608`; `[0x004e8608,0x004e8613)`; 11 bytes; SHA `702705A90951161A7FFC21F6E48D17984FBE49A12CD7A37B27B262F64D722EDC`; name `IMEPane__ScalarDeletingDestructorAdjustorA0`; type `_DWORD *__thiscall(_DWORD *this, char)`; frame only return `+0x0/4 _UNKNOWN *`; exact accepted function-regular comment; other three entry channels blank; sole data ref `0x0061c548`; exact `sub ecx,0xa0; jmp 0x004e8720`. | Already present; no change recommended. | Fresh readback must reproduce all fields. Do not normalize its compiler-ABI type because no stable argument frame row identifies a safer poststate. |
| N04 | Function `0x004e8613`; `[0x004e8613,0x004e861e)`; 11 bytes; SHA `6531CE528E8ED8EF8B291BD45BFC7100177444F946717FDAC45139DF08BC405A`; name `IMEPane__ScalarDeletingDestructorAdjustorA4`; same current type/frame; exact accepted function-regular comment; other channels blank; sole data ref `0x0061c578`; exact `sub ecx,0xa4; jmp 0x004e8720`. | Already present; no change recommended. | Fresh readback must reproduce all fields. No rename, type, comment, function-boundary, byte, xref, or save action. |
| P01 | Primary/secondary/tertiary cells `0x0061c4fc/0x0061c548/0x0061c578` with names `??_7IMEPane@@6B@`, `??_7IMEPane@@6B@_0`, `??_7IMEPane@@6B@_1`, values target/A0/A4; exact nine store refs; `g_pIMEPane` value zero and 17 refs; IMEPane ordinals 674/673 and exact members; both padding runs. | Protected no-change set. | Fresh integer/entity/type/xref/byte reads must match. No data definition, vtable rename/type/comment, global mutation, UDT mutation, padding change, or save. |

Expected read-only request shapes are literal MCP calls with the freshly returned database value:

- `inspect_items` for `0x004e8720`, six internal addresses, both adjustors, UID0004CB, three vtable cells, and `0x0069b458`.
- `stack_frame` for target and both adjustors.
- `get_comments` for target entry, six internal addresses, and both adjustors.
- `get_bytes` for target, adjustors, UID0004CB, and both padding runs.
- `analyze_function` and `disasm` for target; `disasm` for both adjustors.
- `xref_query` for target, adjustors, three vtable cells, and global.
- `callees` for target and UID0004CB.
- `get_int` for three vtable cells, their locator cells, and global value.
- `entity_query` for the global at `0x0069b458`.
- `type_query` for `IMEPane` and `IMEPaneFocusList`.

No current row proposes `rename`, `set_type`, `set_function_comments`, `set_address_comments`, function creation, UDT change, or save. Historical mutations recorded by the older executed report must not be replayed.

## First-Draft C++ Recommendation

- Target eligibility: not eligible for independent source C++.
- Target CPP disposition: remain exactly blank.
- Target H disposition: remain exactly blank.
- Exact no-code proof: UID00031K has hidden deleting flags, return-this/`retn 4` ABI, vtable/thunk-only reachability, optional allocation release, complete-size runtime path, and complete cleanup parity with UID0004CB. These are compiler-generated consequences of the normal virtual destructor and layout.
- Third-party import: not applicable.

The existing owner source is the required formal shape and must be preserved, not duplicated in the target.

Formal UID0004CB CPP:

```cpp
IMEPane::~IMEPane()
{
    if (statusPane != NULL) {
        statusPane->MarkForDeletion();
    }

    if (activeChildPane != NULL) {
        activeChildPane->MarkForDeletion();
    }

    if (candidatePane != NULL) {
        candidatePane->MarkForDeletion();
    }

    g_pIMEPane = NULL;
}
```

Formal UID00006H CPP:

```cpp
#include "IMEPanes.h"

[[CHILDREN]]
```

Formal UID00006H H:

```cpp
#include "../ui/core/Pane.h"
#include "../util/List.h"

class Event;
class IMECandidatePane;
class IMECompositionPane;
class IMEStatusPane;

class IMEPane : public Pane
{
    friend class IMECandidatePane;
    friend class IMECompositionPane;

public:
    IMEPane();
    virtual ~IMEPane();

    void SetFocusPane(Pane *pane, bool focused);
    bool IsIMESupported(const Event *event);
    bool HandleIMEMessage(const Event *event);

private:
    void UpdateFocusCaretAnchor();

    IMEStatusPane *statusPane;
    Pane *activeChildPane;
    IMECandidatePane *candidatePane;
    List focusPaneList;
    int focusCaretAnchorY;
    int focusCaretAnchorX;
};

extern IMEPane *g_pIMEPane;

typedef char IMEPaneSizeMustBe288[
    sizeof(IMEPane) == 0x120 ? 1 : -1];

[[CHILDREN]]
```

This form preserves runtime behavior while looking like plausible human-authored VC-era source. It avoids IDA names, addresses, offsets, hidden ABI parameters, raw vtables, explicit member/base destruction, and compiler-wrapper pseudo-methods.

## Final Recommendation

- Ordinary implementation is complete. The target's stale active IDA prestate was historicalized and replaced with the exact canonical read-only poststate; UID0004CC's contradictory separate-member prose was corrected to the accepted one-List layout; every other support destination was verified at same-or-greater detail without churn.
- Independent supervisor Gate 2A must verify the checked ordinary claims against the current destination identities. This callback does not pre-credit that gate.
- Preserve target `92/94`, owner 00006H, false, blank emitter/position/formals, and `Nested:0`.
- Preserve UID0004CB as the sole source definition and UID00006H/0000K5 as class/file source route.
- Preserve all compiler artifacts as non-emitting evidence.
- Preserve manual/generated state if unchanged; supervisor applies/refreshes only when required by verified drift.
- Preserve current IDA state; supervisor performs fresh canonical no-change verification only.
- Report execution/archive remains supervisor-owned.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`.
- Callback result: one exact ordinary repair applied. The stale active raw name/type/frame/internal-comment prestate is now historical, while the canonical source-quality name/prototype/frame/function comment and blank internal channels are current.
- Current target identity after command `000000022831`: SHA256 `30CA332FD441A10BF7D68E844EB6455BC6CE8C685944725AF41802CCA940510E`, 12,506 bytes, 111 lines.
- Exact facts to preserve: all C31K-001 through C31K-022 details, especially current dated IDA poststate, exact ABI matrix, three-view topology, source/no-source distinction, and superseded history.
- Metadata: preserve `92/94`, owner 00006H, false, blank emitter/position/CPP/H, `Nested:0`.
- Reject regression to `86/91`, reconstructable true, proof-comment output, raw IDA source, or an explicit wrapper body.

## Recommended Support Doc Changes

The callback physically verified these exact states. UID0004CC required the later Gate 2A contradiction repair; every other support destination already met the accepted requirement and remained byte-identical:

| Support path | Required current state |
| --- | --- |
| `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md` | `91/94`, sole human body, exact CPP, wrapper parity |
| `by-class/IMEPane.md` | `91/94`, coherent CPP/H, one List, virtual destructor, UID00031K false route |
| `by-file/IMEPanes.md` | `91/90`, CPP/H source root, one ordinary root destructor, zero root wrapper output |
| `by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md` | Complete four-wrapper/source inventory |
| `by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md` | Complete eight-adjustor inventory including exact root pair |
| `by-global/g_pIMEPane.md` | One `IMEPane *g_pIMEPane = NULL;` definition and lifecycle |
| `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md` | Zero/null physical storage covered by UID0000R7 |
| `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` | Three root vtable views and no raw source arrays |
| `by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md` | Implicit member teardown support |
| `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md` | `GetCount()` source local; complete-object `+0x110` is embedded `focusPaneList.m_count`, not a separate IMEPane field; command `000000022952` applied/validated |
| `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md` | `GetCount()` source and retained human helper |
| `by-memory/-ignored.md` | Both exact padding runs |

No missing support UID or source-bearing dependency was found. UID0004CC was the sole support file edited and validated after independent Gate 2A exposed its contradictory active layout prose; all other support files remained unchanged. Generated/tracker/manual coverage files remain supervisor-owned.

## Score And Metadata Recommendation

- Historical assignment state: `86/91`, combined `88.5`, reconstructable queue.
- Current physical state: `92/94`, combined `93.0`, owner 00006H, false, blank emitter/position/CPP/H, `Nested:0`.
- Recommendation: preserve current state.

Blocker closure:

| Former blocker | Research performed | Result |
| --- | --- | --- |
| Final target name/type | Fresh lookup/inspect/frame/comments | Source-quality target name/type/frame/comment already present |
| Wrapper liveness | Xrefs to target/adjustors/vtables | Exactly one primary and two adjusted vtable routes |
| Source ownership | Ordinary-body comparison, class/formals/generated | UID0004CB/00006H sole human route |
| Hidden flags and storage release | Full disassembly/callees | Exact bit-1/bit-4 outcomes closed |
| Object layout/list count | UDT query and formal/helper audit | One `0x14` List; no separate source count |
| Boundaries/padding | Bytes/items/ignored ledger | Exact, no split |
| Emitter/duplicate policy | Formal channels and generated CPP/H | Blank target; one ordinary body; zero wrapper output |
| Support consistency | Twelve support pages and manual rows | Current and mutually consistent |
| IDA recommendation | Full current prestate reread | No mutation remains |

Reason not higher: unavailable original PDB/source, exact compiler build options, and exact original private/file spellings prevent 100% source-history certainty. Reason not lower: every runtime behavior, ownership route, binary extent, source cause, no-duplicate rule, formal source shape, and current analysis state is independently corroborated.

## Open Questions With Attempted Resolution

- Original private member spellings: no symbols survive. Existing descriptive names are consistent across class, ordinary body, helpers, and generated source. This does not block source-quality representation.
- Exact original source filename/capitalization: current project route `input/IMEPanes.cpp/.h` is subsystem-consistent and complete. No evidence supports a separate wrapper file.
- Compiler build switches that selected the bit-4 no-op path: binary behavior is exact; original switch provenance is unavailable. No source pseudo-code should be invented.
- Adjustor prototype rendering: current IDA projects `_DWORD *__thiscall(_DWORD *this, char)` with no stable argument frame row. The safe disposition is no type mutation; the function names/comments and exact behavior are sufficient.
- `g_pIMEPane` inspect projection: entity query names the global while item inspection shows blank item name plus type. This is a tool projection distinction, not an ownership or source blocker and not a mutation request.
- No unresolved question justifies lower metadata, code duplication, or further target research. Future original source/PDB evidence could refine spellings only.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current manual rows were inspected and require no change at report time:

- By-memory UID00031K: exact `92%` not-reconstructable compiler-wrapper row with body hash, adjustor/vtable reachability, duplicated UID0004CB cleanup, bit-1 delete, bit-4 size/no-free path, and blank-source conclusion.
- By-memory UID0004CB: exact `91%` sole human destructor row.
- By-memory UID00018C: exact `86%` mixed aggregate row with four compiler wrappers and four human source anchors.
- By-memory UID00018D: exact `85%` ignored eight-adjustor row.
- By-memory UID0001PS: exact `88%` zero/null storage and 17-xref row.
- By-class UID00006H: exact `91%` complete class/layout/lifecycle row.
- By-file UID0000K5: exact `91%` source-root row with four human destructors and four non-emitting wrappers.
- By-global UID0000R7: exact `90%` one-definition, zero value, type, and 17-xref row.

No replacement/insert/delete text is recommended. If a supervisor later finds drift, it must apply the exact report-supported correction; B006 must never edit `-coverage-report.md` files. The generated tracker row is not manually edited.

## Follow-Up Actions

- Supervisor Gate 1: independently re-audit this exact post-callback artifact against all 33 sections and table parity.
- B006 ordinary callback and Gate 2A repair: complete; target and UID0004CC repaired and validated, all other support destinations physically verified without artificial edits.
- Supervisor Gate 2A: independently verify all accepted ordinary claims after callback disposition.
- Supervisor Gate 2B: freshly attest canonical IDB and perform N01-N04/P01 no-change readback. Any drift requires a new exact report repair before mutation.
- Supervisor manual/generated closure: verify rows and the current command-`000000022920` coherent generated CPP/H/tracker state only after ordinary/IDA gates; this report repair does not grant supervisor-generated completion credit.
- B006: no further ordinary edit is required unless independent Gate 2A finds exact drift.
- No A-agent action is required.
- No further B-agent research is required unless canonical drift or new source/PDB evidence appears.

## Confidence

- Recommendation confidence: very high, 94.
- Score confidence: very high for preserving `92/94`.
- Binary confidence: exact for range, body hash, metrics, ABI branches, xrefs, callees, vtable topology, layout, and padding.
- Source-shape confidence: very high for normal virtual destructor, sole ordinary body, implicit member/base teardown, no wrapper emission, and one coherent class header.
- Remaining uncertainty is lexical/build provenance only and does not affect runtime or source disposition.
- Ordinary implementation confidence is high: all 43 B006-owned ordinary/no-drift claims were physically verified, and both changed destinations passed scoped validation. Supervisor-owned closure remains intentionally uncredited.

## Validator Results

- Pre-callback report-only commands: none.
- Callback command: `python .\tools\validator.py --mode file --file by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md --apply --queue-timeout 240 --no-generated-refresh`.
- Receipt: command `000000022831`, timestamp `2026-08-12T15:21:45-04:00`, exit `0`, scanned `1`, `ok:1`, generated refresh skipped, no validator warning or error. Result summary: UID/reference phases passed and the only projected-stats note was a no-op because UID00031K is absent from generated stats lists.
- Stable target readback: SHA256 `30CA332FD441A10BF7D68E844EB6455BC6CE8C685944725AF41802CCA940510E`, 12,506 bytes, 111 lines.
- Gate 2A repair command: `python .\tools\validator.py --mode file --file by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md --apply --queue-timeout 240 --no-generated-refresh`.
- Gate 2A repair receipt: command `000000022952`, timestamp `2026-08-12T19:51:04-04:00`, exit `0`, scanned `1`, `ok:1`, generated refresh skipped, no validator warning or error. Result summary: UID/reference phases passed; the projected-stats update was a no-op because UID0004CC is absent from generated stats lists.
- Stable UID0004CC readback: SHA256 `128D88FD73CE623E3FB341881861724D9148E2506E7359DC1E871CD3444341DB`, 9,034 bytes, 84 lines.
- Unchanged support destinations required no scoped validator because the callback made no edits to them.
- Generated closure is supervisor-owned. The current read-only snapshot from supervisor command `000000022920` is evidence, not B006 validator credit: IMEPanes.cpp SHA256 `CF1820E928619F2B81F693D6CE43D1FD69F1F22061829487E83C61087C6669B3`, 18,691 bytes/608 lines; IMEPanes.h SHA256 `60BB5D9B5CDD5A59AE001443E29FACFE2B279CF7F2BE9A3811EDF5ACEC78CAB2`, 1,161 bytes/45 lines; tracker SHA256 `D5D26C9A1F4C1D11CC4AA971B7F0E8D374C09498AAB4136431139B577BBFAC46`, 2,048,170 bytes/9,628 lines. Historical command `000000022770` and its older hashes are superseded snapshots, not current authority.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B006/research/00031K-IMEPaneScalarDeletingDestructor-source-quality.md`.
- Modified ordinary destination: `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`, SHA256 `30CA332FD441A10BF7D68E844EB6455BC6CE8C685944725AF41802CCA940510E`, 12,506 bytes, 111 lines.
- Modified support destination: `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`, SHA256 `128D88FD73CE623E3FB341881861724D9148E2506E7359DC1E871CD3444341DB`, 9,034 bytes, 84 lines; command `000000022952`.
- Physically verified without edits: UID0004CB `B64D649DC5801EF12A3986610A872E4E0AEF822B3A812590829F06DCB46866D5`; UID00006H `544585FF4205BB8C6DE1F73F7950F3A3A868691BFB453BF17336E8A300286655`; UID0000K5 `112C86475795E35F56D9F484331A60CEB75F8427E0739B813601953E572CEBFF`; UID00018C `C6802376F4D32AA35F149F2C9004EDFA8F60058BE1ED6567633E45CCD3B9BA37`; UID00018D `A40F27BAC822887F691C75C1915F704C9D9175C2AD401CEDBB19A13793CAEB22`; UID0000R7 `5C536A062274538A511DE2743CBA247B2189C5FA26737075D1035B4CAA9A4080`; UID0001PS `2C1830C724B3C1EC634C4490B16C36772F9230696B83E7540677D48F58EA4B2D`; UID00025J `35197EBCBCFAC568F0E45AE180AC386DBD0A38D91AC539775026636B370339ED`; UID000192 `705B1FF21EB473382ED33D64F7C181138135A1787BAA81EC6763DB7D4A575957`; UID00031G `CB30D12CD845B9B4E0BF144DB1C055D662C1EB36C84C05812F33414DAD1F78CB`; current ignored ledger `B1AD3EA699D5F7F480B4D603D2C2EAB34C058DA4E3FA868F17F9AADC92FC8827` (older `DD29C6E675D7240E1186947A2596E8C607D5C0224D28BE1B977ED88C718FC13D` is dated history only).
- Current read-only generated/tracker identities: supervisor command `000000022920`; IMEPanes.cpp `CF1820E928619F2B81F693D6CE43D1FD69F1F22061829487E83C61087C6669B3`; IMEPanes.h `60BB5D9B5CDD5A59AE001443E29FACFE2B279CF7F2BE9A3811EDF5ACEC78CAB2`; tracker `D5D26C9A1F4C1D11CC4AA971B7F0E8D374C09498AAB4136431139B577BBFAC46`. These files were not edited by B006.
- Renamed: none.
- Frozen UID0000N3 report: untouched.
- No other support, manual coverage, generated/tracker, audit/catalog, goal/notes, validator/lifecycle, or IDA file was edited.
- Report execution/archive status is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata. B006 did not run any report lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation completed before implementation: accepted SHA256 `AB3A6E68284CC2D1C16467668CEF41211FF231B30A3FA4C437BDC5B6E163DE52`, Gate 1 `33/33`.
- [x] By-file exhaustive inventory: not applicable because the primary target is by-memory; the complete target/dependency inventory is nevertheless explicit in Function / Child Inventory.
- [x] By-file per-item behavior/ownership/emitter/source-placement/CPP-H/metadata/destination coverage: target-specifically not applicable; every target-related function/data/range dependency is instead enumerated for this by-memory assignment.
- [x] By-file generated CPP/H completeness audit: target-specifically not applicable as a whole-file gate; the affected IMEPanes CPP/H one-definition/zero-wrapper consequence was still audited read-only.
- [x] Additional-UID disposition: no additional target UID is declared; every support UID has target-specific evidence, recommendation, physical destination, ledger row, and callback verification.
- [x] Target/support docs disposition: the target's one stale active-IDB block was repaired; every support destination was verified without churn.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger contains every accepted claim with physical destination and current callback state.
- [x] Metadata/score disposition recorded and preserved: current `92/94`, false, owner 00006H, blank emitter/formals, `Nested:0`.
- [x] Score-limiting blockers researched to closure rather than deferred.
- [x] Owner/emitter/reconstructable disposition recorded.
- [x] Split/rename/new-child disposition recorded as no change.
- [x] Source placement, range/padding/reclassification, and IDA no-change dispositions are complete.
- [x] Supervisor Gate 2B handoff lists every exact entity, prestate, protection, and expected readback.
- [x] Formal target CPP/H blank proof and exact owner CPP/H source are supplied.
- [x] Third-party import is target-specifically not applicable.
- [x] Exact target/support facts to preserve or verify are listed at report-level detail.
- [x] Historical/stale assumptions and rejected alternatives are preserved with superseding reasons.
- [x] Wave2/Wave3 material is ignored as stale if encountered.
- [x] Open questions are resolved or bounded by exact unavailable evidence.
- [x] Validator execution was scoped to the two changed ordinary destinations and generated refresh was disabled.
- [x] Manual coverage and generated/tracker dispositions are explicit and supervisor-owned.

Implementation callback pass:

- [ ] Supervisor-owned IDA verification remains unapplied by this report and must use fresh canonical attestation.
- [x] By-file accepted whole-file inventory incorporation: target-specifically not applicable; no sampled by-file claim is made.
- [ ] By-file formal repair and coherent generated completeness closure: target-specifically not applicable as a whole-file callback; supervisor-generated IMEPanes one-definition/zero-wrapper readback remains required.
- [x] Report accepted by supervisor for implementation/no-change callback.
- [x] All accepted target/support details physically verified after callback.
- [x] The declared primary UID and every support UID were independently verified against destination docs; no additional target UID is declared.
- [x] Ledger and checklist updated claim by claim after physical verification.
- [x] Metadata/score/owner/emitter/split/CPP/H dispositions confirmed.
- [x] Historical evidence and negative evidence preserved.
- [x] Open questions rechecked for drift.
- [x] Scoped validator commands `000000022831` and `000000022952` passed for the two changed ordinary destinations; unchanged files were not validated artificially.
- [ ] Manual coverage/generated closure independently completed or confirmed by supervisor.
- [x] Remaining unapplied accepted items are exactly the supervisor-owned IDA, independent Gate, manual coverage, generated/tracker, and lifecycle rows.
- [x] Report body remains lifecycle-neutral.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C31K-001 | 00031K | Preserve exact target range, 217-byte size, and SHA256 `01FD105D1B35671F9B58C7CD556BD5CE39A481B5C7EA52920DE024C91B4FCFF4`. | direct | bytes/function/docs | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Status and Binary Identity | already-present | already-present |
| [x] | C31K-002 | 00031K | Preserve 70 instructions, 15 blocks, complexity 3, and exact five-callee inventory. | direct | disasm/analyze/callees | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Binary Identity and Behavior | already-present | already-present |
| [x] | C31K-003 | 00031K | Record dated canonical report-time IDA target name/type/five-row frame and all four entry comment channels without treating either observed session as permanent Gate 2B authority. | direct | canonical inspect/frame/comments/attestation plus corroborating backup snapshot | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Status and Binary Identity | incorporate | applied |
| [x] | C31K-004 | 00031K | Preserve vptr restores at complete offsets 0, `+0xa0`, and `+0xa4`. | direct | disasm/data refs | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Behavior and Vtable Evidence | already-present | already-present |
| [x] | C31K-005 | 00031K | Preserve non-null deferred deletion of `statusPane +0xf8`, `activeChildPane +0xfc`, and `candidatePane +0x100` without slot clears. | direct | decompile/disasm | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Behavior | already-present | already-present |
| [x] | C31K-006 | 00031K | Preserve implicit cleanup of embedded `focusPaneList +0x104` through UID000192. | very high | callee/layout/ordinary parity | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Behavior and Reconstruction Notes | already-present | already-present |
| [x] | C31K-007 | 00031K | Preserve singleton clear at `0x004e87a0`, zero value, and exact 17-xref context. | direct | disasm/get_int/xrefs | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Behavior and Cross-References | already-present | already-present |
| [x] | C31K-008 | 00031K | Preserve Pane base teardown as compiler lowering, not explicit developer source. | very high | call order/C++ semantics | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Reconstruction Notes | already-present | already-present |
| [x] | C31K-009 | 00031K | Preserve bit-1-clear teardown-without-free behavior. | direct | branch audit | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / ABI Flag Matrix | already-present | already-present |
| [x] | C31K-010 | 00031K | Preserve bit-1-set/bit-4-clear operator-delete behavior. | direct | branch/callee audit | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / ABI Flag Matrix | already-present | already-present |
| [x] | C31K-011 | 00031K | Preserve bit-4 complete-size `0x120` one-byte no-op path and no-free conclusion. | direct | disasm/callee/size | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / ABI Flag Matrix and Negative Evidence | already-present | already-present |
| [x] | C31K-012 | 00031K | Preserve return-this in EAX, `retn 4`, and four-byte hidden deleting-flags ABI. | direct | exits/frame | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / ABI | already-present | already-present |
| [x] | C31K-013 | 00031K | Preserve exact callee identities `0x544690`, `0x4f30e0`, `0x544580`, `0x4f4ac0`, and `0x41b6a0`. | direct | callees | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Callee Inventory | already-present | already-present |
| [x] | C31K-014 | 00031K | Preserve inbound refs code `0x4e860e`, code `0x4e8619`, data `0x61c4fc`, and zero ordinary callers. | direct | xref query/analyze | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Xref Inventory | already-present | already-present |
| [x] | C31K-015 | 00031K | Preserve exact two adjustors, `0xa0/0xa4` deltas, target jumps, ranges, and hashes. | direct | disasm/bytes/docs | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Adjustor Evidence | already-present | already-present |
| [x] | C31K-016 | 00031K | Preserve complete nine-store constructor/ordinary/target three-view restoration topology. | direct | xrefs/disasm | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Vtable Evidence | already-present | already-present |
| [x] | C31K-017 | 00031K | Preserve exact `0x120` class layout with one complete `0x14` List at `+0x104`; reject a separate source `focusPaneCount` member. | very high | UDT/formals/helper source | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Object Layout | already-present | already-present |
| [x] | C31K-018 | 00031K | Preserve UID0004CB as sole human destructor definition and UID00031K as compiler-only allocation-selection glue. | very high | body parity/formals/generated | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Source Disposition | already-present | already-present |
| [x] | C31K-019 | 00031K | Preserve exact padding, title/path/range, and `Nested:0`; no split or merge. | direct | bytes/ignored ledger | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Range and Padding | already-present | already-present |
| [x] | C31K-020 | 00031K | Preserve metadata `92/94`, owner 00006H, false, blank emitter/position/CPP/H, `Nested:0`. | very high | current page/source proof | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / metadata and formal channels | already-present | already-present |
| [x] | C31K-021 | 00031K | Preserve score rationale: all source-form blockers closed; cap only unavailable original symbols/build provenance. | high | complete evidence matrix | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Score Rationale | already-present | already-present |
| [x] | C31K-022 | 00031K | Preserve former `85/90`, `86/91`, reconstructable, emitter, and proof-comment routes only as superseded history. | very high | history/current state | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / Reconstruction Notes and Changes | historicalize | already-present |
| [ ] | C31K-023 | 0000K5 | Supervisor generated readback must verify one UID0004CB body/declaration route and zero UID00031K marker/name/body/proof/empty output. | very high | supervisor command `000000022920`; current CPP `CF1820E928619F2B81F693D6CE43D1FD69F1F22061829487E83C61087C6669B3` and H `60BB5D9B5CDD5A59AE001443E29FACFE2B279CF7F2BE9A3811EDF5ACEC78CAB2` | generated `NexusTK/input/IMEPanes.cpp` and `IMEPanes.h` / supervisor readback | incorporate | proposed |
| [x] | C31K-024 | 0004CB | Preserve UID0004CB `91/94`, owner/emitter 00006H, exact formal destructor, wrapper parity, and sole-source rationale. | very high | ordinary body/formals | `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md` / all substantive sections | already-present | already-present |
| [x] | C31K-025 | 00006H | Preserve UID00006H `91/94`, owner/emitter 0000K5, exact CPP/H split, coherent List layout, virtual destructor, and UID00031K false route. | very high | class formals/UDTs | `by-class/IMEPane.md` / formals, Method Notes, Evidence, Score | already-present | already-present |
| [x] | C31K-026 | 0000K5 | Preserve UID0000K5 `91/90`, IMEPanes CPP/H route, one ordinary root destructor, and zero root scalar-wrapper output. | high | file/generated/formals | `by-file/IMEPanes.md` / Proposed Contents, Evidence, Generated Expectations | already-present | already-present |
| [x] | C31K-027 | 00018C | Preserve aggregate `86/91`, false, exact UID00031K `92/94` compiler-wrapper inventory, and source route via UID0004CB/00006H. | high | aggregate reread | `by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md` / Item Summary and inventory | already-present | already-present |
| [x] | C31K-028 | 00018D | Preserve aggregate `85/90`, false, root adjustor ranges/deltas/hashes/names/vtable routes, and no-source disposition. | very high | adjustor disasm/docs | `by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md` / inventory and Evidence | already-present | already-present |
| [x] | C31K-029 | 0000R7 | Preserve `IMEPane *g_pIMEPane = NULL;`, 17-xref lifecycle, and raw-name history. | very high | entity/value/xrefs/formal CPP | `by-global/g_pIMEPane.md` / Status, Evidence, Reconstruction Notes | already-present | already-present |
| [x] | C31K-030 | 0001PS | Preserve zero/null four-byte storage, parent 0000R7 route, covered-by formal, and 17-xref lifecycle. | very high | bytes/value/xrefs/docs | `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md` / Status, Data, Evidence | already-present | already-present |
| [x] | C31K-031 | 00025J | Preserve IMEPane primary/secondary/tertiary vtable cells and three restoration sets without raw table emission. | high | data bytes/ints/xrefs/docs | `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` / Observed Contents and Reconstruction Notes | already-present | already-present |
| [x] | C31K-032 | 000192 | Preserve UID000192 as implicit embedded-member teardown support, not target-owned explicit source. | high | callee/List formals | `by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md` / Behavior and Source Shape | already-present | already-present |
| [x] | C31K-033 | 0000VN | Preserve exact ignored predecessor and successor `0xcc` runs and hashes. | direct | bytes/ignored ledger | `by-memory/-ignored.md` / exact `0x004e8715` and `0x004e87f9` rows | already-present | already-present |
| [ ] | C31K-034 | 00031K | Supervisor must verify the manual by-memory target row remains exact `92%` false/non-emitting wrapper text. | high | manual row reread | `by-memory/-coverage-report.md` / UID00031K row | already-present | proposed |
| [ ] | C31K-035 | 0004CB | Supervisor must verify the manual ordinary-destructor row remains exact `91%` sole-source text. | high | manual row reread | `by-memory/-coverage-report.md` / UID0004CB row | already-present | proposed |
| [ ] | C31K-036 | 00018C | Supervisor must verify the manual aggregate row retains all four wrapper/source relationships. | high | manual row reread | `by-memory/-coverage-report.md` / UID00018C row | already-present | proposed |
| [ ] | C31K-037 | 00018D | Supervisor must verify the manual adjustor row retains all eight non-emitting routes. | high | manual row reread | `by-memory/-coverage-report.md` / UID00018D row | already-present | proposed |
| [ ] | C31K-038 | 00006H | Supervisor must verify the manual class row retains complete layout/lifecycle and UID00031K distinction. | high | manual row reread | `by-class/-coverage-report.md` / UID00006H row | already-present | proposed |
| [ ] | C31K-039 | 0000K5 | Supervisor must verify the manual file row retains four human destructors and four non-emitting wrappers. | high | manual row reread | `by-file/-coverage-report.md` / UID0000K5 row | already-present | proposed |
| [ ] | C31K-040 | 0000R7 | Supervisor must verify the manual global row retains source definition, zero value, type, and 17 xrefs. | high | manual row reread | `by-global/-coverage-report.md` / UID0000R7 row | already-present | proposed |
| [ ] | C31K-041 | 0001PS | Supervisor must verify the manual singleton row retains zero/null storage and 17-xref lifecycle. | high | manual row reread | `by-memory/-coverage-report.md` / UID0001PS row | already-present | proposed |
| [ ] | C31K-042 | IDA:N01 | Fresh canonical Gate 2B must verify target name/type/range/body/frame and comments exactly as N01, with no mutation. | direct | dated live snapshot | canonical IDB `0x004e8720` / N01 | already-present | proposed |
| [ ] | C31K-043 | IDA:N02 | Fresh canonical Gate 2B must verify six internal address comment pairs remain blank. | direct | dated comments snapshot | canonical IDB six target instruction addresses / N02 | already-present | proposed |
| [ ] | C31K-044 | IDA:N03 | Fresh canonical Gate 2B must verify A0 adjustor name/type/frame/comment/body/xref exactly, with no mutation. | direct | dated live snapshot | canonical IDB `0x004e8608` / N03 | already-present | proposed |
| [ ] | C31K-045 | IDA:N04 | Fresh canonical Gate 2B must verify A4 adjustor name/type/frame/comment/body/xref exactly, with no mutation. | direct | dated live snapshot | canonical IDB `0x004e8613` / N04 | already-present | proposed |
| [ ] | C31K-046 | IDA:P01 | Fresh canonical Gate 2B must protect target bytes/CFG/xrefs/callees/vtables/UDTs/global/value and padding. | direct | complete MCP inventory | canonical IDB / P01 | already-present | proposed |
| [ ] | C31K-047 | IDA:G2B | Supervisor must freshly discover/attest canonical authority and fail closed on any drift; no save is authorized by this report. | procedural | runtime identity rules | canonical IDB / supervisor Gate 2B | incorporate | proposed |
| [x] | C31K-048 | 00031K | If callback discovers target drift and edits it, run its scoped no-generated-refresh validator and retain exact receipt; otherwise document verified no-change. | procedural | workflow | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` / validator receipt | incorporate | applied |
| [x] | C31K-049 | 0004CB | If callback edits UID0004CB, run its scoped validator; otherwise document verified no-change. | procedural | workflow | UID0004CB / validator receipt | incorporate | already-present |
| [x] | C31K-050 | 00006H | If callback edits UID00006H, run its scoped validator; otherwise document verified no-change. | procedural | workflow | `by-class/IMEPane.md` / validator receipt | incorporate | already-present |
| [x] | C31K-051 | 0000K5 | If callback edits UID0000K5, run its scoped validator; otherwise document verified no-change. | procedural | workflow | `by-file/IMEPanes.md` / validator receipt | incorporate | already-present |
| [x] | C31K-052 | 00018C | If callback edits UID00018C, run its scoped validator; otherwise document verified no-change. | procedural | workflow | UID00018C / validator receipt | incorporate | already-present |
| [x] | C31K-053 | 00018D | If callback edits UID00018D, run its scoped validator; otherwise document verified no-change. | procedural | workflow | UID00018D / validator receipt | incorporate | already-present |
| [x] | C31K-054 | 0000R7 | If callback edits UID0000R7, run its scoped validator; otherwise document verified no-change. | procedural | workflow | `by-global/g_pIMEPane.md` / validator receipt | incorporate | already-present |
| [x] | C31K-055 | 0001PS | If callback edits UID0001PS, run its scoped validator; otherwise document verified no-change. | procedural | workflow | UID0001PS / validator receipt | incorporate | already-present |
| [ ] | C31K-056 | GATE2A | Supervisor must independently verify every accepted ordinary claim against physical destinations after any callback. | procedural | Rule 26 | all named ordinary by-* destinations / Gate 2A | incorporate | proposed |
| [ ] | C31K-057 | GATE2B | Supervisor must independently verify N01-N04/P01 under fresh canonical attestation; no-change means no save. | procedural | IDA gate | canonical IDB / Gate 2B | incorporate | proposed |
| [ ] | C31K-058 | COVERAGE | Supervisor must verify manual rows and apply only exact drift corrections; B006 never edits coverage reports. | procedural | coverage boundary | four manual `-coverage-report.md` files / named rows | incorporate | proposed |
| [ ] | C31K-059 | GENERATED | Supervisor-generated closure must physically verify CPP/H one-definition/zero-wrapper state after any coherent refresh. | procedural | current supervisor command `000000022920`; CPP `CF1820E928619F2B81F693D6CE43D1FD69F1F22061829487E83C61087C6669B3`, H `60BB5D9B5CDD5A59AE001443E29FACFE2B279CF7F2BE9A3811EDF5ACEC78CAB2` | generated IMEPanes CPP/H / supervisor readback | incorporate | proposed |
| [x] | C31K-060 | 00006H | Preserve exact class CPP/H source: self-header plus children in CPP; full declaration, one List, one virtual destructor, extern, size guard, children in H. | very high | physical formals/generated H | `by-class/IMEPane.md` / formal CPP and H channels | already-present | already-present |
| [x] | C31K-061 | 0004CC | Preserve `focusPaneList.GetCount()` local source expression and reject a separate `focusPaneCount` member. | high | formal CPP plus repaired Behavior/Evidence; command `000000022952`; SHA256 `128D88FD73CE623E3FB341881861724D9148E2506E7359DC1E871CD3444341DB` | `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md` / formal CPP, Behavior, Evidence, and Changes | incorporate | applied |
| [x] | C31K-062 | 00031G | Preserve `focusPaneList.GetCount()` caret-helper expression and human method source. | high | formal CPP/layout | `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md` / formal CPP | already-present | already-present |
| [ ] | C31K-063 | TRACKER | Preserve current command-`000000022920` tracker interpretation `92/94`, combined `93.0`, false/non-emitting, with SHA256 `D5D26C9A1F4C1D11CC4AA971B7F0E8D374C09498AAB4136431139B577BBFAC46`; retain older tracker identities only as dated history. | direct | current tracker reread; 2,048,170 bytes/9,628 lines | `auto-generated/-ag-research-tracker.md` / UID00031K row | already-present | proposed |
| [ ] | C31K-064 | LIFECYCLE | Report execution/archive authority remains supervisor-only and comes from current path plus validator-owned metadata/history. | procedural | role boundary | validator-owned report lifecycle / current report path and footer | not-applicable | proposed |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000022982","destination_path":"executed-b-agent-research/B006/00031K-IMEPaneScalarDeletingDestructor-source-quality-2.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/00031K-IMEPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-12T20:53:40-04:00","uid":"00031K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
