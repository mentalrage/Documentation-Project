# ScrollSpellInventoryPane Whole-File Source-Quality Research
** TARGET-REPORT-UID:0000NJ **
** TARGET-REPORT-ADDITIONAL-UIDS:0000CN,0001GM,0001GN,0001GO,0001W1,0001YS,0003CM,000538,000539,00053A,00053B,00053C,00053D,00053E,00053F,00053G,00053H,00053I,00053J,00053K,00053L,00053M,00053N,00053O **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

Treat `[0x0055f450,0x005608fc)` as the complete authored implementation island for a standalone `NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp` plus `ScrollSpellInventoryPane.h`. The island contains exactly nineteen source methods separated by sixteen alignment spans. Twelve starts are modeled functions and seven are retained code items that IDA has not promoted to functions. The raw starts are ordinary class methods, not unreachable padding: each is an exact same-offset, same-length, byte-identical counterpart of the completed `ScrollInventoryPane` implementation.

The complete spell island is 5,292 bytes, SHA256 `cd32902d15a947bafd796b8db7505be5568d8a73e9b95a5ae82f7e9d6eba1c57`. Direct comparison with `[0x00563260,0x0056470c)` finds 5,130 identical bytes, 162 differing bytes in 77 short runs, and 96.939 percent byte identity. The differences are class identity, owner callback, vtable/RTTI addresses, relocations, and call targets; the method boundary sequence and control structure are identical. This closes the standalone-versus-folded source question in favor of the dedicated file and supplies a complete behavior template without copying decompiler artifacts into source.

The command-`000000024682` generated snapshot was the historical assignment-time defect state: it emitted only `UpdateFromDrag` and `ResetScrollState`, omitted seventeen methods, used invalid `m_bounds`, and declared a false two-argument `UpdateDragScroll`. The accepted callback created and validator-registered all seventeen missing exact children as UIDs 000538 through 00053O, routed all nineteen bodies through UID0000CN/UID0000NJ in positions 10 through 190, installed the complete Section 22 CPP/H contract, and removed false aggregate/layout/vtable emitters. Scoped validation and validator command `000000024812` then generated a complete `.cpp`/`.h`; physical readback proves every formal method body appears exactly once and in order, and the complete H block is present. UID0000NJ is now `90/92` and UID0000CN is `89/91`; score caps remain for inferred private spelling and original file capitalization.

## Supporting Research

- Assignment-time target: `[UID:0000NJ] by-file/ScrollSpellInventoryPane.md`, `86/88`, blank reconstructability in the research tracker, standalone projected path `NexusTK/ui/inventory/`, file owner.
- Assignment-time primary class: `[UID:0000CN] by-class/ScrollSpellInventoryPane.md`, `86/88`, canonical owner/emitter UID0000NJ, source position 10, 0x110-byte class declaration.
- Aggregate and extant children: UID0001GM `[0x0055f450,0x005608fc)`, UID0001GN `[0x00560710,0x0056089d)`, UID0001GO `[0x005608a0,0x005608fc)`.
- Compiler/layout support: UID0001W1 layout, UID0001YS semantic vtables, UID0003CM exact vtable data, UID00026D mixed read-only data.
- Owner consumer: UID0000LU/UID00009A `NewSpellInventoryPane`; its constructor is the sole direct constructor caller and its `OnScrollPositionChanged(unsigned char, short, short)` is the drag callback.
- Shared dependency owner: UID0000NF/UID0003CQ `ScrollBar` owns `kScrollPanePartExtentBySkin`; this unit consumes but does not define it.
- Accepted source template: the completed `InventoryScrollPane.cpp/.h` module has the same 19-method/16-padding topology and exact same-size bodies. It is used as family evidence, not as a substitute for target-specific bytes, xrefs, owners, fields, and names.
- Dated ordinary-file snapshots were read before report writing: target SHA256 `149C922C91A3D26630547052051090166164A8BA4F9D202146D3285327550FDE`; class `C2AA91C228537E1861564812063733665294763B615A4F523B7D79E93BF0A83F`; aggregate `670E2AB80FA22A3DB3284D26CAEC2F35E06CBAD5C1014E409A3B2CE89E16B19D`; UpdateFromDrag `89052655D286E8CB82C4E1349C6089E0DC5F34FBDE63C030158A25E891F78E0D`; Reset `6A3FEF6503D8DF8BF77A48F935735B63465F52574A4660A090515BC2F62D0321`; layout `C6116C1368F98F5C9B1A52EB8B00CE69095AF03228890DBF01B2155BA3246216`; semantic vtables `320BA33A198A17C397372517710685230823336E2AA5FD5C15AA8BF18AD102D3`; vtable data `F69E22BE866108DEFC1F52BD74DB43F11151DA8AF1785A8D0415E4A5CE093C9F`.
- Dated generated snapshot command `000000024682`, refreshed `2026-08-16T01:45:46-04:00`: `ScrollSpellInventoryPane.cpp` SHA256 `F319DC6AD3FD3D4507F6E7F6E37E8F357C63E43CA944596A0BB704F670CDE204`, 4,759 bytes/122 lines; `.h` SHA256 `0B0FF861A6BAF4F7D063E63007DF7C8A121AB3C8E735944CD8FD5B4C1A818E01`, 2,382 bytes/72 lines. These are dated defect evidence, not permanent generated authority.
- Dated completed sibling snapshot at the same command: `InventoryScrollPane.cpp` SHA256 `093CE79B70DE2781CA27B3C05ED8B9DF506F356F8FA3C306771458CDFA660232`, 22,496 bytes/663 lines; `.h` SHA256 `B581F94A7FDFB51BE4680654F4641DBE5BDC57203279BFC87282D1932F5C2DF7`, 2,099 bytes/66 lines.
- Applied ordinary callback: seventeen exact child pages were created through validator UID allocation as 000538..00053O; UID0001GN and UID0001GO were corrected and moved to positions 180/190; UID0001GM, UID0001W1, UID0001YS, and UID0003CM became non-emitting evidence with blank formal channels; UID0000CN received the complete CPP preamble/H contract; UID0000NJ received the complete whole-file inventory and final scores.
- Verified no-change support: UID0000LU/UID00009A already preserve the constructor-consumer, child pointer, friendship, and `OnScrollPositionChanged(unsigned char, short, short)` callback route. UID0000NF/UID0003CQ already preserve sole ScrollBar ownership, one H declaration, values `{38,38,38}`, 22 xrefs including the four ScrollSpell consumers, and no duplicate definition requirement.
- Dated callback generated receipt, validator command `000000024812`, refreshed `2026-08-16T05:08:21-04:00`: `ScrollSpellInventoryPane.cpp` SHA256 `245DC399CA3748C5933CAE28944A1E1465E20160A5C398A774A98AAA9CA507CF`, 22,364 bytes/618 lines; `.h` SHA256 `B2A1EFAF61453E08AE2CFE8E5C9D84EDEC1CC0574C63D8B2BD9B5626844BC21D`, 2,369 bytes/72 lines. Current generated authority remains validator-owned and must be reread dynamically by the supervisor.
- Final callback generated receipt, validator command `000000024821`, refreshed `2026-08-16T05:23:50-04:00`: `ScrollSpellInventoryPane.cpp` SHA256 `E915C98C4096773181701D4A4C3A6A34BAF8B88ED5E65E992851E988C0C1CC10`, 22,366 bytes/618 lines; `.h` SHA256 `CEB38F0FC24FFD3E2ABE97C0C64BC8745F3C637CED2398E8A23B098843BF8700`, 2,371 bytes/72 lines. This is a dated callback receipt; current generated authority remains validator-owned and must be reread dynamically by the supervisor.

## Target

- Primary UID/path: `[UID:0000NJ] by-file/ScrollSpellInventoryPane.md`.
- Inferred source files: `NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp` and `NexusTK/ui/inventory/ScrollSpellInventoryPane.h`.
- Exact code island: `[0x0055f450,0x005608fc)`; successor `0x00560900` is `ScrollNewGroupPane` construction and is excluded.
- Direct source class: `ScrollSpellInventoryPane`, 0x110 bytes, primary `Pane` base plus EventHandler and TimerHandler views inherited through `Pane`.
- Declared additional targets: UID0000CN, UID0001GM, UID0001GN, UID0001GO, UID0001W1, UID0001YS, UID0003CM, and validator-assigned method children UID000538..UID00053O. Each child UID is independently dispositioned by its exact Section 14 inventory row, one target-specific C-NJ-011..C-NJ-027 ledger/checklist twin, its own Section 22 CPP block and blank-H proof, the Section 25 support plan, the Section 26 score/metadata row, and the Section 28 manual-coverage payload; the other declared UIDs retain their separate rows and plans in those same sections.

## Current Target State

At assignment time UID0000NJ documented the correct standalone-file hypothesis but stopped short of source completion. UID0000CN had a mostly complete class header and only a child marker in CPP. UID0001GM incorrectly emitted a broad covered-by comment while only two exact children existed. UID0001GN emitted a partial body with nonexistent `m_bounds`; UID0001GO emitted the reset body. UID0001W1 and UID0001YS emitted explanatory comments that duplicated compiler/layout evidence rather than authored source. UID0003CM recorded exact vtable bytes but lacked a manual by-memory coverage row.

The applied ordinary state closes those defects. UID0000NJ is `90/92`; UID0000CN is `89/91` with the complete include preamble, exact H declaration, no-argument `UpdateDragScroll`, and nineteen child definitions. UID0001GM is a `91/93` non-emitting aggregate. UIDs 000538..00053O are the validator-assigned first seventeen exact children; UID0001GN is corrected to `m_visibleBounds` at position 180 and `91/93`; UID0001GO is the exact enum-shaped reset at position 190 and `93/94`. UID0001W1 is `93/95`, UID0001YS is `94/95`, and UID0003CM is `94/96`; all three are nonreconstructable/no-emitter evidence with blank formals. UID0000LU, UID00009A, UID0000NF, and UID0003CQ required no ordinary change because their accepted support relationships were already present.

The binary state is stronger than those pages: every source method boundary is closed; the seven raw starts are exact retained methods; the class, enum, field layout, three vtable facets, six RTTI objects plus one type descriptor, shared resource strings, shared extent table, direct parent route, all known inbound xrefs, and outbound dependencies are resolved. No authored destructor, file-local global, file-local string, EH metadata object, import declaration, third-party embed, or code spill beyond 0x005608fc belongs in this unit.

During the dated supervisor Gate 2B attempt that followed the accepted Gate 1, Gate 2A, and manual-coverage checks, public `define_func` accepted all seven raw ranges but returned the sparse immediate frames now recorded in Section 21 rather than the previously inferred generic argument/local rows. Independent public `set_type` tests then produced the exact typed post-frames recorded there. Because the old report contract required rows that were absent, the attempt failed closed: no IDB save occurred, both experimental workers were discarded without save, the canonical IDB remained byte-identical to its backup, and a fresh disk session reconfirmed all seven starts as non-functions. This is a dated failed-attempt receipt; current IDB and lifecycle authority remain external and must be reread dynamically.

During the later dated I10 Gate 2B attempt, public `set_type` accepted `bool __thiscall ScrollSpellInventoryPane__HandleKeyOrTextEvent(EventHandler *this, Event *event)` and changed the immediate return-only frame to the exact two-row post-frame in Section 21 by adding only `event@0x4/4:Event *`. The previous I10 transaction row failed because it protected the return-only frame as unchanged. The supervisor stopped without saving, terminated the dirty worker, reopened unchanged canonical SHA256 `54AD03CEE2F8F1BCE310035C940CA0CC66BAF2745534E0C82DF71A648C47787E` from hash-matching backup `E:\NTK\Resources\NexusTK\ida-backups\NexusTK.exe.before-B003-UID0000NJ-20260816T104707.i64`, and verified rollback in session `supervisor_uid0000nj_i10repair_20260816`. This is dated failure evidence only; current IDB authority remains external and dynamically reread.

During the subsequent dated I13 Gate 2B attempt, public function `set_type` accepted `ScrollSpellInventoryPart __thiscall ScrollSpellInventoryPane__HitTestPart(ScrollSpellInventoryPane *this, int localY, int localX)` but retained physical stack rows `row@0x4c/4:int; column@0x50/4:int`; it did not rename them. The old I13 contract therefore failed closed before comments or save. Seven raw definitions, seventeen pure function renames, and sixteen function-type applications existed only in the unsaved worker; no comment endpoint or `idb_save` was called. Dirty worker PID `4068` was terminated, and fresh attested session `supervisor_uid0000nj_gate2b_retry_20260816` reconfirmed canonical disk SHA256 `737E20CA29CFD3CBD972A5E9400A7AF08A6DAF2F09D66C85CC81CE8E1A8E1B58` against backup `E:\NTK\Resources\NexusTK\ida-backups\NexusTK.exe.before-B003-UID0000NJ-final-20260816T113820.i64`, all seven raw starts as non-functions, and I13 restored as `sub_55FF70` with `row`/`column`. This is dated failure evidence only; current IDB authority remains external and dynamically reread.

The generated source/header defect state in Supporting Research is explicitly historical. The dated callback readback at command `000000024812` passed the complete nineteen-body and H-declaration contract. Generated authority remains validator-owned and is reread dynamically during supervisor continuity checks rather than inferred permanently from the dated callback hash.

## Executive Recommendation

1. Preserve the applied standalone source root and complete Section 22 CPP/H contract.
2. Preserve validator-assigned UIDs 000538..00053O and exact positions 10..170, with UID0001GN/UID0001GO at 180/190.
3. Preserve UID0001GM, UID0001W1, UID0001YS, and UID0003CM as non-emitting compiler/index evidence. Authored source comes from the class preamble/header plus exact method children; literal vtables/RTTI/layout comments do not belong in generated C++.
4. Process the deterministic, fail-closed IDA recommendations only through supervisor Gate 2B. Existing `ScrollSpellInventoryPane` and `ScrollSpellInventoryPart` types are protected no-change state; no type redeclaration is proposed.
5. Apply manual coverage text only by the supervisor. Lifecycle state remains authoritative only from the report path and validator-owned status/history metadata.

## Supervisor Active Recheck

The ordinary callback reread the exact report and destinations, validator-registered all children, scoped-validated every changed page, and physically compared generated `.cpp`/`.h` against all nineteen exact formal bodies and the complete declaration. Any supervisor Gate 2B transaction must obtain fresh public runtime attestation and recheck all nineteen starts, seven raw physical inventories, three vtables, protected types/data/resources, exact padding, destination-name collisions, and successor boundary. Process IDA actions strictly in address and stage order. For I02/I03/I07/I08/I15/I16/I19, require the literal sparse post-`define_func` frame and literal post-`set_type` frame in Section 21. For I10, require immediate/pre-type `__return_address@0x0/4:_UNKNOWN *`, then authorize only the post-`set_type` addition `event@0x4/4:Event *`. For I13, require the complete `row`/`column` frame both before and immediately after function typing, then run the exact two-entry public `rename.batch.stack` dry-run and apply sequence with no `pure` member; require the complete final frame to differ only as `row -> localY` and `column -> localX`. Stop and rollback without save on a missing old row, existing destination collision, partial stack rename, any offset/width/type or non-target-row delta, or any frame, byte, item, comment, xref, type, collision, or range fact that differs from Section 21. Current generated, IDB, supervisor-action, and lifecycle authority must be read dynamically rather than inferred from dated receipts in this report.

## Inference Research Guidance Check

- Binary facts control ranges, bytes, xrefs, layouts, vtable identities, resource values, and runtime branches.
- Source-facing names are inferred where original private symbols are absent, but they follow already-established spell-pane documentation and the exact completed inventory-scroll family.
- Exact behavioral replication is higher priority than cosmetic consistency. The formal source preserves signed clamps, transition-only invalidation, timer cadence, orientation branches, thumb math, event payload fields, drawing resources, and parent callback semantics.
- Human-source shape is higher priority than decompiler spelling. No final C++ contains `sub_`, raw `this` integers, manual vtable arrays, RTTI blobs, artificial register variables, or guessed compiler wrappers.
- Stale Wave2/Wave3 references were ignored.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Evidence | Confidence |
| --- | --- | --- | --- |
| Standalone file vs NewSpell fold | Standalone `ScrollSpellInventoryPane.cpp/.h` | Closed 19-method class island, three class vtables, full sibling module, consumer-only NewSpell route | High |
| Seven raw starts | Ordinary source methods | Exact same-offset/same-length byte-identical sibling bodies, clean CC gaps, coherent field effects | Very high |
| Constructor-only direct caller | Normal private child class, not constructor-only artifact | Virtual slots, timer/event methods, parent callbacks, internal call graph | Very high |
| Source names | Keep documented spell family names | Current class docs plus exact generic family mapping; no better original-symbol evidence | High |
| `UpdateDragScroll` signature | No explicit arguments | Function body fetches cursor and computes local coordinates; binary range/type and sibling source agree | Very high |
| `UpdateFromDrag` field | Use inherited `m_visibleBounds` | Current Pane/GrafPort declarations and complete-object offset +0x44 | Very high |
| Header | Full normal class/enum declaration | External constructor/setter callers, virtual contract, 0x110 layout | Very high |
| Vtable/RTTI output | Compiler-generated, no literal source emission | Decorated symbols, constructor stores, shared deleting/adjustor wrappers | Very high |
| Shared table/resources | External dependencies only | Cross-family xrefs and existing owners/types/comments | Very high |
| I10 type/frame feasibility | Return-only immediately before type; `set_type` adds exactly `event@0x4/4:Event *` | Dated public endpoint observation, successful signature parse, fail-closed rollback and unchanged canonical IDB | Very high |
| I13 type/name feasibility | Function `set_type` preserves physical `row`/`column`; explicit non-pure public stack renames produce `localY`/`localX` | Dated successful type parse/readback, current public `rename.batch.stack` schema, exact occupied rows, fail-closed rollback | Very high |
| Destructor | No authored destructor in this island | Closed range, shared scalar-deleting wrapper, no separate body | Very high |
| Third-party import | Not applicable | First-party UI code and project-owned dependencies | Very high |

## Evidence Standards Used

1. Live public IDA MCP read-only queries against the canonical IDB.
2. Exact full-range and per-method byte hashes, item boundaries, padding bytes, and successor exclusion.
3. Direct callers, callees, vtable xrefs, owner allocation/pointer storage, and callback path.
4. Exact class/type/vtable/RTTI/resource/data state.
5. Current by-* documentation and dated validator-generated CPP/H snapshots.
6. Independent same-family byte comparison and accepted generated source declarations.
7. Negative searches for raw-start routes, extra methods, destructors, file-local data, third-party source, and spillover.

## Evidence Checked

- Dated MCP snapshot at `2026-08-16T03:29:10-04:00`: database/session `supervisor_uid0000li_i37rollback3_20260816`, canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; health `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, strings ready, analysis flag false. Public schema-1 runtime attestation passed. Session and process identities are dated evidence only; Gate 2B must re-attest dynamically.
- All nineteen starts: `lookup_funcs`, `inspect_items`, `get_comments`, `stack_frame` where modeled, `xref_query` inbound/outbound, and bounded `get_bytes`.
- Complete range `[0x0055f450,0x005608fc)`, all method hashes, all CC padding spans, and successor bytes at 0x00560900.
- `type_inspect` for `ScrollSpellInventoryPane`, `ScrollSpellInventoryPart`, `Point`, and `RectBounds`.
- Vtable/RTTI objects at 0x00623e90-0x00623f18, 0x0064f98c, 0x0064f9a0, 0x0064f9b0, 0x0064f9cc, 0x0064f9e8, 0x0064f9fc, and 0x00678f98.
- Shared dependencies at 0x00624144, 0x0060ddb0, 0x0060ddc8, 0x0060dde0, and 0x0060ddf8.
- Current target/class/aggregate/two child/layout/vtable/vtable-data/mixed-data/NewSpell/ScrollBar docs and all five relevant manual coverage reports.
- Generated spell module and complete inventory sibling module from dated command 000000024682.
- Existing B-report searches: UID0000NJ, ScrollSpellInventoryPane, 0x0055f450, 0x005608fc, UID0001GN, UID0001GO, `UpdateFromDrag`, `ResetScrollState`, and the completed UID0000KB InventoryScrollPane report. Historical reports were leads only and target claims were independently rechecked.
- Dated supervisor Gate 2B observation: all seven exact raw `define_func` calls succeeded, immediate public `stack_frame` returned only the literal sparse saved-register/return rows in Section 21, and independently tested public `set_type` calls returned the literal typed post-frames there. The mismatch against the prior inferred contract caused fail-closed rollback without save; discarded workers did not change the canonical backup-identical IDB, and a fresh disk session again reported all seven starts absent as functions.
- Dated supervisor I10 observation: public `set_type` parsed the required EventHandler signature and changed `__return_address@0x0/4:_UNKNOWN *` to exactly `__return_address@0x0/4:_UNKNOWN *; event@0x4/4:Event *`, adding only the typed event row. The contradictory unchanged-frame protection caused a stop without save; the dirty worker was terminated and canonical SHA256 `54AD03CEE2F8F1BCE310035C940CA0CC66BAF2745534E0C82DF71A648C47787E` was reopened and verified against the hash-matching dated backup.
- Dated supervisor I13 observation: the accepted source-facing function signature parsed but complete post-type `stack_frame` retained `row@0x4c/4:int; column@0x50/4:int` and every other row unchanged. The supervisor made no comments and no save, terminated PID `4068`, and reopened backup-identical canonical SHA256 `737E20CA29CFD3CBD972A5E9400A7AF08A6DAF2F09D66C85CC81CE8E1A8E1B58`; fresh readback restored I13 and all seven raw starts to pristine prestate.

## Claim And Incorporation Ledger

The accepted ordinary callback checks 52 agent-owned documentation/generated claims. C-NJ-052 through C-NJ-055 stay unchecked in this agent-authored twin solely as supervisor-owned IDA/protected-state/manual-coverage allocation rows; current supervisor dispositions are authoritative from supervisor audit and validator metadata rather than inferred from those unchecked boxes. Report execution/archive state is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C-NJ-001 | 0000NJ | The complete authored code island is [0x0055f450,0x005608fc), 5,292 bytes, SHA256 cd32902d15a947bafd796b8db7505be5568d8a73e9b95a5ae82f7e9d6eba1c57. | Very high | Exact bounded byte read and hash. | UID0000NJ Target State and inventory | incorporate | APPLIED_VERIFIED |
| C-NJ-002 | 0000NJ | Standalone ScrollSpellInventoryPane.cpp/.h is the best source placement; the historical NewSpell fold is rejected. | High | Closed class island, three vtables, sibling module, consumer-only owner route. | UID0000NJ Source Placement; UID0000LU relationship | historicalize | APPLIED_VERIFIED |
| C-NJ-003 | 0000NJ | The spell island and completed generic inventory-scroll island have identical length and method topology, with 5,130/5,292 identical bytes. | Very high | Direct byte comparison, 162 differing bytes in 77 runs. | UID0000NJ clone proof; UID0000CN source basis | incorporate | APPLIED_VERIFIED |
| C-NJ-004 | 0001GM | Sixteen exact CC alignment spans separate nineteen methods and exclude successor 0x00560900. | Very high | Bounded bytes and item/function boundaries. | UID0001GM range/padding inventory | incorporate | APPLIED_VERIFIED |
| C-NJ-005 | 0000CN | ScrollSpellInventoryPane is exactly 0x110 bytes with the documented enum and thirteen-member physical layout. | Very high | Live type_inspect, allocation, constructor stores, field accesses. | UID0000CN H/layout; UID0001W1 | incorporate | APPLIED_VERIFIED |
| C-NJ-006 | 0001YS | Three vtable facets and seven RTTI/type objects are compiler products of the class declaration. | Very high | Decorated names, COL/type objects, constructor and slot xrefs. | UID0001YS; UID0003CM | incorporate | APPLIED_VERIFIED |
| C-NJ-007 | 0001YS | Shared scalar-deleting and adjustor wrappers are compiler products shared by eight scroll-pane families and are excluded from this file's authored source. | Very high | Wrapper xrefs and existing source-quality identities. | UID0001YS compiler consequences | reject-invalid | REJECT_INVALID_VERIFIED |
| C-NJ-008 | 0000NJ | kScrollPanePartExtentBySkin and four EPF/PAL literals are shared external dependencies, not file-owned definitions. | Very high | Types, values, comments, and cross-family xrefs. | UID0000NJ dependencies; UID0000NF no-change | already-present | ALREADY_PRESENT_VERIFIED |
| C-NJ-009 | 0000NJ | No authored destructor, EH object, file-local global/string/table, import definition, third-party source, or code after 0x005608fc belongs to the unit. | Very high | Closed range, symbol/object search, shared wrapper route, successor identity. | UID0000NJ exclusions | incorporate | APPLIED_VERIFIED |
| C-NJ-010 | 0000NJ | Dated command-000000024682 generated CPP/H were incomplete: seventeen bodies were absent, UpdateFromDrag used invalid m_bounds, and UpdateDragScroll had two false parameters; the callback replaced that historical state. | Very high | Physical generated readback at command 000000024682. | UID0000NJ/UID0000CN formal-source replacement | incorporate | APPLIED_VERIFIED |
| C-NJ-011 | 000538 | UID000538 covers constructor 0x0055f450-0x0055f4f1, is reconstructable 93/95, owned/emitted by UID0000CN at position 10, owns the exact Section 22 constructor CPP, and keeps H blank because UID0000CN declares it. | Very high | SHA256 40613436b6c5f0fe7f5b8e156fbf05de9ef8bcbd80e0fda85f03b5aaee3d09a1; caller 0x0057d013; validator 000000024780. | UID000538 exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-012 | 000539 | UID000539 covers raw SetSizeIndex 0x0055f500-0x0055f527, is reconstructable 89/91, owned/emitted by UID0000CN at position 20, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | High | SHA256 48679840081c330a7852b3e68ce164e8e650e230fb07769968a9f84c4790758a; exact raw clone; zero xrefs; validator 000000024781. | UID000539 exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-013 | 00053A | UID00053A covers raw SetScrollStyle 0x0055f530-0x0055f554, is reconstructable 89/91, owned/emitted by UID0000CN at position 30, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | High | SHA256 4ea6ca081e50c45c9d819c4df934434c95707a445f8f06cac86a1c8b5afad5c4; exact raw clone; zero xrefs; validator 000000024782. | UID00053A exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-014 | 00053B | UID00053B covers SetMaxRange 0x0055f560-0x0055f5bb, is reconstructable 93/95, owned/emitted by UID0000CN at position 40, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | Very high | SHA256 c504a31bd1577b41537ae91425c5d2575483ed073207193c545b615792be1f23; caller 0x0057d2b9; validator 000000024783. | UID00053B exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-015 | 00053C | UID00053C covers SetScrollPosition 0x0055f5c0-0x0055f5e7, is reconstructable 93/95, owned/emitted by UID0000CN at position 50, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | Very high | SHA256 c823be0b3a17b1411aac7d79c9052da8122a7e32f5b2a7c23fcbfb6c1aeee940; four callers; validator 000000024784. | UID00053C exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-016 | 00053D | UID00053D covers Activate 0x0055f5f0-0x0055f60a, is reconstructable 90/92, owned/emitted by UID0000CN at position 60, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | Very high | SHA256 cc2001d3751e1f7d5535f9e6c63305f9cebda99fe58184945e9cfccab9451847; caller 0x0057d028; validator 000000024785. | UID00053D exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-017 | 00053E | UID00053E covers raw Deactivate 0x0055f610-0x0055f62a, is reconstructable 89/91, owned/emitted by UID0000CN at position 70, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | High | SHA256 c97d8f364beb37dcf10c6177a75485635a57c70d4e389ace3a7bbae35761f322; exact raw clone; validator 000000024786. | UID00053E exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-018 | 00053F | UID00053F covers raw CanScroll 0x0055f630-0x0055f64a, is reconstructable 92/94, owned/emitted by UID0000CN at position 80, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | High | SHA256 e5e73329a48d7f7236650f40361f4a4464b6b6d5777fde7a286d05ed94f5af19; exact raw clone; validator 000000024787. | UID00053F exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-019 | 00053G | UID00053G covers HandlePointerOrMouseEvent 0x0055f650-0x0055f831, is reconstructable 90/92, owned/emitted by UID0000CN at position 90, owns the exact Section 22 CPP, and keeps H blank under the parent virtual declaration. | Very high | SHA256 77b5a319bd719d1068101f3471b9d86458f00158936c6456488e324c044fd581; vtable xref 0x00623ee4; validator 000000024788. | UID00053G exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-020 | 00053H | UID00053H covers HandleKeyOrTextEvent 0x0055f840-0x0055f845, is reconstructable 93/95, owned/emitted by UID0000CN at position 100, owns the exact Section 22 CPP, and keeps H blank under the parent virtual declaration. | Very high | SHA256 cc0e3cb106eb0fdec984d44a563d98c3da80700bbb8d2be4e66ebd54a9919626; vtable xref 0x00623ee8; validator 000000024789. | UID00053H exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-021 | 00053I | UID00053I covers OnTimer 0x0055f850-0x0055f883, is reconstructable 93/95, owned/emitted by UID0000CN at position 110, owns the exact Section 22 CPP, and keeps H blank under the parent virtual declaration. | Very high | SHA256 85653f517fb94d695cc08eb66cfdb6714129374b64d0d7ac7a4f782a489e4e91; vtable xref 0x00623f14; validator 000000024790. | UID00053I exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-022 | 00053J | UID00053J covers OnPaint 0x0055f890-0x0055ff70, is reconstructable 90/92, owned/emitted by UID0000CN at position 120, owns the exact Section 22 CPP, and keeps H blank under the parent virtual declaration. | Very high | SHA256 57abec85e56067fb5ea52643ecaeeb3af504c904e1dd7c6859a8ca0ae8e71cdd; vtable/callee evidence; validator 000000024791. | UID00053J exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-023 | 00053K | UID00053K covers HitTestPart 0x0055ff70-0x0056028d, is reconstructable 90/92, owned/emitted by UID0000CN at position 130, owns the exact Section 22 CPP, and keeps H blank under the parent private declaration. | Very high | SHA256 17b1dfb9cb93b73473af0d43a3aeb044dbeb4497e9d14d6946d1d1cb76a22f4e; two callers; validator 000000024792. | UID00053K exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-024 | 00053L | UID00053L covers GetPartRect 0x00560290-0x00560517, is reconstructable 90/92, owned/emitted by UID0000CN at position 140, owns the exact Section 22 CPP, and keeps H blank under the parent private declaration. | Very high | SHA256 177b3c96275f2428d35b58f81bbad6a624b92294b5f17be702c9989e64f964be; thirteen callers; validator 000000024793. | UID00053L exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-025 | 00053M | UID00053M covers raw SetHoverPart 0x00560520-0x00560590, is reconstructable 91/93, owned/emitted by UID0000CN at position 150, owns the exact Section 22 CPP, and keeps H blank under the parent private declaration. | High | SHA256 6022e9b09a62d700988ba63a729a9657c81345fb13d7afabdc21803bfb95b668; exact raw clone; validator 000000024794. | UID00053M exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-026 | 00053N | UID00053N covers raw BeginInteraction 0x00560590-0x0056064f, is reconstructable 91/93, owned/emitted by UID0000CN at position 160, owns the exact Section 22 CPP, and keeps H blank under the parent private declaration. | High | SHA256 f16fe1664be8fe9a1b6460a1a01998710460c89f8579a4e253a42e863f81cef5; exact raw clone; validator 000000024795. | UID00053N exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-027 | 00053O | UID00053O covers UpdateDragScroll 0x00560650-0x00560710, is reconstructable 90/92, owned/emitted by UID0000CN at position 170, owns the exact no-argument Section 22 CPP, and keeps H blank under the parent private declaration. | Very high | SHA256 76693d5645830bd3d04923b1524370af5c1998373fcf157929bdc9c23daf3fe2; three callers; validator 000000024796. | UID00053O exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-028 | 0001GN | UpdateFromDrag 0x00560710-0x0056089d maps cursor geometry to range and calls the NewSpell owner callback only on change. | Very high | SHA256 09733ac52ea007586c04d5429f87094fa3f0d75481f0e801beabc55dda5320eb; two callers. | UID0001GN CPP position 180 | incorporate | APPLIED_VERIFIED |
| C-NJ-029 | 0001GO | ResetScrollState 0x005608a0-0x005608fc removes timers, clears active/hover state, and invalidates the former hover part. | Very high | SHA256 3d64e239e2e318d9f95a42ef76be91240a9ae8afbb1279629730d308ea6e6132; exact raw clone. | UID0001GO CPP position 190 | incorporate | APPLIED_VERIFIED |
| C-NJ-030 | 0000CN | UID0000CN is the direct class owner and emits the CPP include/children preamble and complete normal H declaration through UID0000NJ. | Very high | Current owner graph, class layout, method family, source split. | UID0000CN formal CPP/H and metadata | incorporate | APPLIED_VERIFIED |
| C-NJ-031 | 0000NJ | All nineteen exact methods are child-routed in address/source order 10..190 under validator-assigned UIDs 000538..00053O plus 0001GN/0001GO; no UID was guessed. | Very high | Complete inventory and by-structure child routing. | UID0000NJ/UID0000CN child graph | incorporate | APPLIED_VERIFIED |
| C-NJ-032 | 0001GM | The broad aggregate is nonreconstructable marker/index evidence with no emitter and blank formal CPP/H. | Very high | Exact children own every body; aggregate source would duplicate them. | UID0001GM metadata/formals | incorporate | APPLIED_VERIFIED |
| C-NJ-033 | 0001W1 | The layout page is nonreconstructable evidence with no emitter and blank formals because UID0000CN H owns the declaration. | Very high | Exact class H and by-structure ownership rule. | UID0001W1 metadata/formals | incorporate | APPLIED_VERIFIED |
| C-NJ-034 | 0001YS | Semantic vtables are nonreconstructable compiler evidence with no emitter and blank formals. | Very high | Compiler-generated multiple-inheritance tables. | UID0001YS metadata/formals | incorporate | APPLIED_VERIFIED |
| C-NJ-035 | 0003CM | Exact vtable-data bytes are nonreconstructable compiler evidence with no emitter and blank formals. | Very high | Exact 136-byte decorated data range. | UID0003CM metadata/formals | incorporate | APPLIED_VERIFIED |
| C-NJ-036 | 0000NJ | The by-file page contains the complete inventory, standalone decision, dependencies, historical generated-defect closure, source order, exclusions, and formal ownership contract. | Very high | Whole-file audit. | UID0000NJ all relevant sections | incorporate | APPLIED_VERIFIED |
| C-NJ-037 | 0000CN | The class page contains the no-argument UpdateDragScroll declaration, complete method inventory, exact field/layout/vtable evidence, and final CPP/H. | Very high | Binary and header audit. | UID0000CN | incorporate | APPLIED_VERIFIED |
| C-NJ-038 | 0001GM | The aggregate page contains all nineteen ranges/hashes, sixteen gaps, successor boundary, and non-emitting index disposition. | Very high | Exact range audit. | UID0001GM | incorporate | APPLIED_VERIFIED |
| C-NJ-039 | 0001GN | UID0001GN uses m_visibleBounds, retains UpdateFromDrag naming, and emits at source position 180. | Very high | Binary offset +0x44, current type declarations, source order. | UID0001GN | incorporate | APPLIED_VERIFIED |
| C-NJ-040 | 0001GO | UID0001GO retains the exact ResetScrollState body and emits at source position 190. | Very high | Exact clone/hash and source order. | UID0001GO | incorporate | APPLIED_VERIFIED |
| C-NJ-041 | 0001W1 | UID0001W1 preserves physical layout/history and has no duplicate code emission. | Very high | Class H is authoritative source declaration. | UID0001W1 | incorporate | APPLIED_VERIFIED |
| C-NJ-042 | 0001YS | UID0001YS preserves facet/slot/wrapper/RTTI evidence and has no duplicate code emission. | Very high | Compiler-product analysis. | UID0001YS | incorporate | APPLIED_VERIFIED |
| C-NJ-043 | 0003CM | UID0003CM preserves exact bytes/names/xrefs and has complete non-emitting ordinary metadata; manual coverage remains supervisor-owned. | Very high | Live item/vtable readback. | UID0003CM | incorporate | APPLIED_VERIFIED |
| C-NJ-044 | 0000LU | NewSpellInventoryPane remains consumer/parent only; its complete callback header is already present and ownership does not change. | Very high | Constructor/pointer/callback xrefs and current header. | UID0000LU support relationship | already-present | ALREADY_PRESENT_VERIFIED |
| C-NJ-045 | 00009A | NewSpellInventoryPane friendship/callback declaration remains the exact owner interaction route; no reduced local class is introduced. | Very high | Existing complete H and callback function. | UID00009A support relationship | already-present | ALREADY_PRESENT_VERIFIED |
| C-NJ-046 | 0000NF | ScrollBar retains sole definition/header ownership of kScrollPanePartExtentBySkin; no ordinary support edit is required. | Very high | Existing exact extern/definition and 22 xrefs. | UID0000NF/UID0003CQ protected no-change | already-present | ALREADY_PRESENT_VERIFIED |
| C-NJ-047 | 0000NJ | UID0000NJ is 90/92, not above 95 because exact private spellings/file capitalization are inferred. | High | Complete behavior/source closure and residual source-history uncertainty. | UID0000NJ metadata/coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-048 | 0000CN | UID0000CN is 89/91 after the complete ordinary callback. | High | Exact layout/API/owner/source closure with inferred private names. | UID0000CN metadata/coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-049 | 0001GM | UID0001GM is 91/93 as non-emitting aggregate evidence after the exact child split. | Very high | Complete exact range/child/padding inventory. | UID0001GM metadata/coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-050 | 0000NJ | Exact method children receive the score matrix in Section 26, with source emitters remaining at or below 93/95. | High | Per-method evidence strength and source-quality gate. | Seventeen new children; UID0001GN/UID0001GO | incorporate | APPLIED_VERIFIED |
| C-NJ-051 | 0001W1 | Layout/vtable support scores are UID0001W1 93/95, UID0001YS 94/95, and UID0003CM 94/96 without source emission. | Very high | Exact layout and compiler-data closure. | Support metadata/coverage | incorporate | APPLIED_VERIFIED |
| C-NJ-052 | 0000NJ | Supervisor Gate 2B processes the twelve already-modeled functions under their literal staged-frame contracts. I10 may gain only `event@0x4/4:Event *` after its exact function `set_type`. I13 function `set_type` must retain `row@0x4c/4:int; column@0x50/4:int`; only the subsequent non-pure two-entry `rename.batch.stack` dry-run/apply sequence may rename those occupied rows to `localY`/`localX`, with every other frame fact protected. Any missing old row, destination collision, partial result, or unlisted frame/protected-state delta is a rollback/no-save stop. | High | Literal modeled prestates/post-types, dated public I10/I13 readbacks, current stack-rename schema, collision checks, exact hashes/xrefs. | Section 21 supervisor IDA handoff | incorporate | proposed |
| C-NJ-053 | 0000NJ | Supervisor Gate 2B defines the seven exact raw ranges, requires each literal sparse immediate post-define frame, collision-checks and pure-renames, applies the exact type, requires each literal post-type frame with only the documented typed-argument delta, then applies the repeatable comment; any extra, missing, shifted, resized, or retyped row is a rollback/no-save stop. | High | Dated public define_func/set_type frame readbacks, raw bytes/hashes/heads, zero-xref sets, and clean gaps. | Section 21 supervisor IDA handoff | incorporate | proposed |
| C-NJ-054 | 0000CN | Existing ScrollSpellInventoryPane/Part types, vtables/RTTI, shared table, resources, padding, wrappers, and successor are protected no-change state. | Very high | Live type/item/comment/xref/byte reads. | Section 21 protected-state rows | already-present | proposed |
| C-NJ-055 | 0000NJ | Supervisor-owned manual coverage replacements/insertions are exactly specified in Section 28 and remain outside agent write scope. | High | Current row reread and recommended scores. | Five manual coverage reports | incorporate | proposed |
| C-NJ-056 | 0000NJ | The accepted callback scoped-validated every changed ordinary page, waited for generated refresh, and physically verified complete generated CPP/H against all nineteen methods. | Very high | Whole-file completion contract and dated generated defects. | Validator Results/Follow-Up | incorporate | APPLIED_VERIFIED |

## Positive Evidence Summary

- Nineteen method boundaries and sixteen gaps close the entire 5,292-byte island without overlap or unexplained executable bytes.
- All seven raw starts are exact byte-identical counterparts of accepted ordinary methods in the completed generic module.
- The whole-island 96.939 percent identity preserves branch topology and local structure while relocations identify the spell owner and compiler objects.
- The constructor has one direct NewSpell caller and installs all three class-specific vtable views.
- Virtual slots directly anchor mouse, key, timer, and paint methods; internal calls anchor hit-test, geometry, drag, and update methods.
- The 0x110 UDT and enum already exist in IDA with exact fields; current by-class H matches except for the false UpdateDragScroll arguments.
- Four shared resources and one shared extent table have source-quality names/types/comments and cross-family routes.
- The complete human-shaped source already compiles conceptually against current project APIs through the completed sibling contract; no decompiler-only type or symbol is needed.

## IDA MCP Facts

The dated live snapshot used canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` and passed public runtime attestation. The target UDT exists at size 272 with thirteen members: Pane base 0x0/248; `m_sizeIndex` +0xf8 u16; `m_scrollStyle` +0xfa u8; `m_thumbDragActive` +0xfb bool; `m_orientation` +0xfc u8; padding +0xfd; `m_scrollPosition` +0xfe i16; `m_scrollRange` +0x100 i16; `m_enabled` +0x102 bool; `m_hoverPart` +0x103 signed i8; `m_activePart` +0x104 signed i8; padding +0x105[3]; `m_thumbDragOffset` +0x108 Point. `ScrollSpellInventoryPart` exists as a four-byte enum; the public endpoint reports no member array, so branch constants and existing formal H remain the semantic-member evidence.

Modeled starts are 0x55f450, 0x55f560, 0x55f5c0, 0x55f5f0, 0x55f650, 0x55f840, 0x55f850, 0x55f890, 0x55ff70, 0x560290, 0x560650, and 0x560710. Raw code starts with no function/name/type/comment channels are 0x55f500, 0x55f530, 0x55f610, 0x55f630, 0x560520, 0x560590, and 0x5608a0; all have zero direct inbound xrefs.

A later dated supervisor Gate 2B experiment confirmed that public `define_func` accepted every one of those seven exact raw ranges but produced only the sparse saved-register/return-address frames listed in Section 21. Independent public `set_type` tests accepted all seven signatures and produced exactly the Section 21 typed post-frames. The earlier inferred generic/local-row contract therefore failed closed; no save occurred, both workers were discarded without save, the canonical IDB stayed backup-identical, and fresh disk-session readback again found all seven starts absent as functions.

The later dated I10 public `set_type` observation is independently bounded: immediate/pre-type frame `__return_address@0x0/4:_UNKNOWN *`; successful signature parse; post-type frame `__return_address@0x0/4:_UNKNOWN *; event@0x4/4:Event *`; no other row delta. Because the prior report protected the first frame as unchanged, the supervisor stopped without save and reopened the unchanged canonical IDB from the exact backup named in Current Target State.

The subsequent dated I13 public function `set_type` observation is independently bounded: the requested source signature parsed, but the complete physical frame retained `row@0x4c/4:int; column@0x50/4:int` and all other rows unchanged. Public occupied-row renaming is a separate `rename.batch.stack` operation using exact `func_addr`, `old`, and `new` fields, `allow_overwrite:false`, `stop_on_error:true`, dry-run before apply, and no `pure` member. The corrected final frame therefore comes from explicit stack renames after successful type readback, not from function typing.

Fresh read-only continuity evidence on 2026-08-16 re-read I01 through the public `stack_frame` and `disasm` endpoints. The target returns with `retn 4`, and its sole caller at 0x0057d013 pushes only the zero-valued orientation argument before the call. The detached SEH handler at 0x00607866 is the only code that names IDA's residual `arg_4`; it is compiler-analysis metadata rather than a second source argument. I01 therefore preserves `arg_4@0x24/4:_DWORD` byte-for-byte and performs no stack rename, retype, creation, or deletion on that row. The session identity is dated evidence only; supervisor Gate 2B must establish current authority dynamically.

The three decorated vtable names are at 0x00623e94, 0x00623ee0, and 0x00623f10, with COL words immediately before each facet. Primary deleting slot routes to shared `ScrollPaneFamily__ScalarDeletingDestructor`; EventHandler and TimerHandler views use shared adjustors. The shared wrappers have eight-family xrefs and remain excluded compiler products.

## Function / Child Inventory

| Order | Exact range | Applied/current state | Source role / evidence | Owner/emitter and CPP/H disposition | Score disposition |
| --- | --- | --- | --- | --- | --- |
| 10 | 55f450-55f4f1 | UID000538 created/validated | Constructor; 161 bytes; hash 40613436...; one NewSpell caller | exact child -> UID0000CN; CPP body; H declaration in class | 93/95 applied |
| 20 | 55f500-55f527 | UID000539 created/validated | SetSizeIndex; 39 bytes; 13 heads; exact clone; no xrefs | exact child -> UID0000CN; CPP body; H declaration in class | 89/91 applied |
| 30 | 55f530-55f554 | UID00053A created/validated | SetScrollStyle; 36 bytes; 13 heads; exact clone; no xrefs | exact child -> UID0000CN; CPP body; H declaration in class | 89/91 applied |
| 40 | 55f560-55f5bb | UID00053B created/validated | SetMaxRange; 91 bytes; one caller | exact child -> UID0000CN; CPP body; H declaration in class | 93/95 applied |
| 50 | 55f5c0-55f5e7 | UID00053C created/validated | SetScrollPosition; 39 bytes; four callers | exact child -> UID0000CN; CPP body; H declaration in class | 93/95 applied |
| 60 | 55f5f0-55f60a | UID00053D created/validated | Activate; 26 bytes; one caller | exact child -> UID0000CN; CPP body; H declaration in class | 90/92 applied |
| 70 | 55f610-55f62a | UID00053E created/validated | Deactivate; 26 bytes; 8 heads; exact clone | exact child -> UID0000CN; CPP body; H declaration in class | 89/91 applied |
| 80 | 55f630-55f64a | UID00053F created/validated | CanScroll; 26 bytes; 9 heads; exact clone | exact child -> UID0000CN; CPP body; H declaration in class | 92/94 applied |
| 90 | 55f650-55f831 | UID00053G created/validated | Pointer/mouse handler; 481 bytes; EventHandler slot | exact child -> UID0000CN; CPP body; virtual H declaration | 90/92 applied |
| 100 | 55f840-55f845 | UID00053H created/validated | Key/text handler; 5 bytes; EventHandler slot | exact child -> UID0000CN; CPP body; virtual H declaration | 93/95 applied |
| 110 | 55f850-55f883 | UID00053I created/validated | Timer handler; 51 bytes; TimerHandler slot | exact child -> UID0000CN; CPP body; virtual H declaration | 93/95 applied |
| 120 | 55f890-55ff70 | UID00053J created/validated | Paint; 1,760 bytes; primary slot; exact resources | exact child -> UID0000CN; CPP body; virtual H declaration | 90/92 applied |
| 130 | 55ff70-56028d | UID00053K created/validated | HitTestPart; 797 bytes; two callers | exact child -> UID0000CN; CPP body; private H declaration | 90/92 applied |
| 140 | 560290-560517 | UID00053L created/validated | GetPartRect; 647 bytes; thirteen callers | exact child -> UID0000CN; CPP body; private H declaration | 90/92 applied |
| 150 | 560520-560590 | UID00053M created/validated | SetHoverPart; 112 bytes; 46 heads; exact clone | exact child -> UID0000CN; CPP body; private H declaration | 91/93 applied |
| 160 | 560590-56064f | UID00053N created/validated | BeginInteraction; 191 bytes; 70 heads; exact clone | exact child -> UID0000CN; CPP body; private H declaration | 91/93 applied |
| 170 | 560650-560710 | UID00053O created/validated | UpdateDragScroll; 192 bytes; three callers; no explicit args | exact child -> UID0000CN; CPP body; private H declaration | 90/92 applied |
| 180 | 560710-56089d | UID0001GN corrected/validated | UpdateFromDrag; 397 bytes; two callers | corrected `m_visibleBounds` CPP; private H declaration on class | 91/93 applied |
| 190 | 5608a0-5608fc | UID0001GO corrected/validated | ResetScrollState; 92 bytes; 32 heads; exact clone | enum-shaped CPP body; private H declaration on class | 93/94 applied |
| index | 55f450-5608fc | UID0001GM reclassified/validated | nineteen exact children plus sixteen gaps | nonreconstructable/no emitter/blank formals | 91/93 applied |
| declaration | class size 0x110 | UID0000CN completed/validated | enum, API, fields, friend, method source preamble | emits CPP preamble and complete H through UID0000NJ | 89/91 applied |
| layout | 0x110 physical | UID0001W1 reclassified/validated | exact class layout evidence | nonreconstructable/no emitter/blank formals | 93/95 applied |
| compiler | three facets | UID0001YS reclassified/validated | slot/adjustor/RTTI semantics | nonreconstructable/no emitter/blank formals | 94/95 applied |
| compiler data | 623e90-623f18 | UID0003CM registered/reclassified/validated | exact vtable bytes/COL prefixes | nonreconstructable/no emitter/blank formals | 94/96 applied |

No separate file-owned destructor, helper thunk, EH FuncInfo, RTTI source body, global/data initializer, static string, import wrapper, or third-party embed is missing from this inventory. Compiler objects are represented above and source dependencies are represented separately below.

## Direct Xref / Caller Inventory

| Entry | Exact inbound route |
| --- | --- |
| 0x55f450 Constructor | 0x57d013 in NewSpellInventoryPane construction |
| 0x55f500 SetSizeIndex | none; retained raw method |
| 0x55f530 SetScrollStyle | none; retained raw method |
| 0x55f560 SetMaxRange | 0x57d2b9 in NewSpell rebuild |
| 0x55f5c0 SetScrollPosition | 0x57d34e, 0x57d37c, 0x57e23a, 0x57e292 |
| 0x55f5f0 Activate | 0x57d028 in NewSpell construction |
| 0x55f610 Deactivate | none; retained raw method |
| 0x55f630 CanScroll | none at entry; internal source calls can be inlined/direct branch-shaped |
| 0x55f650 mouse | vtable slot 0x623ee4 |
| 0x55f840 key | vtable slot 0x623ee8 |
| 0x55f850 timer | vtable slot 0x623f14 |
| 0x55f890 paint | vtable slot 0x623ed8 |
| 0x55ff70 HitTestPart | 0x55f731, 0x5606bf |
| 0x560290 GetPartRect | 0x55f6c7, 0x55f762, 0x55f77a, 0x55f799, 0x55fee6, 0x56054c, 0x560568, 0x5605c1, 0x5605d9, 0x5605f8, 0x5606ea, 0x560735, 0x5608d6 |
| 0x560520 SetHoverPart | none; retained raw private helper |
| 0x560590 BeginInteraction | none at entry; called within mouse control flow in sibling/source reconstruction |
| 0x560650 UpdateDragScroll | 0x55f7c3, 0x55f868, 0x560622 |
| 0x560710 UpdateFromDrag | 0x5606ab, 0x5606d4 |
| 0x5608a0 ResetScrollState | none; retained raw private helper |

Outbound dependency closure:
- constructor: `Pane` constructor and `InitPointPair`;
- setters/activation: inherited virtual `InvalidateRect` where state changes;
- mouse/timer/interaction/reset: capture/release, timer schedule/removal, part geometry, point initialization, hit test and drag updates;
- paint: `EPFTileContext::Initialize`, clipping/intersection/offset helpers, fill callback, EPF layout lookup, `RenderTileFrame`;
- geometry/drag: `EventMan::GetCursorPosition`, screen offset, rect initialization/point test, shared extent table;
- UpdateFromDrag: NewSpell parent callback `OnScrollPositionChanged`.

## Documentation Evidence And IDA Status

Documentation already established the spell family, standalone path, fields, enum, owner callback, shared table, layout, vtable facets, and two late method bodies. The accepted callback completed the missing routing and source: all nineteen exact children, complete CPP/H, corrected `UpdateDragScroll()`, corrected inherited `m_visibleBounds`, exact scores, and non-emitting compiler/index pages are now present and validator-confirmed.

IDA remains read-only during this report. The existing UDT/enum, decorated vtables/RTTI, shared wrapper names, shared table, and resource names/types/comments are protected. Section 21 proposes only evidence-backed function creation/names/types/repeatable address comments for the nineteen method starts. Gate 2B actor state and save/archive state are external current authority.

## Ranked Ownership Analysis

1. `ScrollSpellInventoryPane.cpp/.h` through UID0000NJ/UID0000CN: direct owner. It has the complete unique class island, vtables, layout, behavior, source order, and header surface.
2. `NewSpellInventoryPane.cpp/.h`: consumer and callback parent. One allocation/construction route and owner callback do not absorb a full independent 19-method class.
3. `ScrollBar.cpp/.h`: shared dependency owner only. It owns the part-extent table and generic scroll types, not this spell class.
4. `Pane.cpp/.h`, `Event.cpp/.h`, and rendering units: base/API dependencies only.
5. no owner/non-emitting: rejected for authored methods by the exact completed clone and coherent class behavior; retained only for compiler/layout aggregate artifacts.

## Source Placement

The source root is `NexusTK/ui/inventory/ScrollSpellInventoryPane`. The `.h` owns the enum and complete class declaration. The `.cpp` owns includes followed by nineteen method definitions in address order. The class by-* page emits the include/child preamble and H; each exact method child emits exactly one CPP body. UID0001GM is an index over the island, not a source-bearing body. NewSpell includes the normal header and remains parent/consumer. Shared `ScrollBar.h`, Event, EPFTileContext, ImageLib, and Surface declarations are included rather than locally redeclared.

## Range / Split / Padding / Reclassification Analysis

Exact alignment spans are `[55f4f1,55f500)` 15, `[55f527,55f530)` 9, `[55f554,55f560)` 12, `[55f5bb,55f5c0)` 5, `[55f5e7,55f5f0)` 9, `[55f60a,55f610)` 6, `[55f62a,55f630)` 6, `[55f64a,55f650)` 6, `[55f831,55f840)` 15, `[55f845,55f850)` 11, `[55f883,55f890)` 13, `[56028d,560290)` 3, `[560517,560520)` 9, `[56064f,560650)` 1, `[56089d,5608a0)` 3, and successor alignment `[5608fc,560900)` 4. Every byte is `CC`.

The split is applied as nineteen exact method children. Validator-assigned UIDs 000538..00053O cover positions 10..170, while existing UID0001GN and UID0001GO cover positions 180/190. No child absorbs padding or crosses the 0x560900 successor. The aggregate, layout, semantic vtable, and physical vtable-data pages are reclassified to non-emitting evidence rather than deleted.

## Negative Evidence Summary

- No direct xrefs to the seven raw starts, but exact byte-identical live sibling methods, coherent internal state, clean boundaries, and authored method ordering disprove padding/unowned interpretations.
- No separate destructor body in the closed island; only shared compiler deleting/adjustor wrappers exist.
- No file-owned EH/FuncInfo object or unique RTTI source declaration was found; RTTI/vtables are compiler products of the normal class H.
- No source symbol proves every private spelling. The selected names are the strongest subsystem-consistent human names; leaving `sub_` or raw offsets would be less faithful.
- No evidence supports folding into NewSpell, literal vtable emission, duplicate shared constants/resources, or extension into ScrollNewGroupPane.
- No third-party import directive applies.

## IDA Rename / Type / Comment Recommendations

Classification: `apply` for the nineteen method transactions; `no change recommended` for existing UDT/enum, compiler objects, shared data/resources, wrappers, padding, and successor. Only the supervisor may execute these during Gate 2B.

Public endpoint contract: establish `DB` from fresh `runtime_attestation`, then use `lookup_funcs({database:DB,queries:[...]})`, `inspect_items({database:DB,addrs:[...]})`, `get_comments({database:DB,addrs:[...]})`, `stack_frame({database:DB,addrs:[...]})`, `xref_query({database:DB,queries:[{addr,direction:"to",xref_type:"any",include_fn:true,count:5000}]})`, and `get_bytes({database:DB,regions:[{addr,size}]})`. Existing functions use ordered `rename` with `batch.func:[{addr,name}]`, `pure:true`, no overwrite, stop-on-error; `set_type` with `edits:[{addr,kind:"function",signature}]`; and `set_address_repeatable_comments` with `items:[{addr,comment}]`. I13 additionally uses public `rename` with `batch.stack:[{func_addr,old,new}]`, `allow_overwrite:false`, `stop_on_error:true`, an identical `dry_run:true` preflight followed by `dry_run:false` apply, and no `pure` member. Raw starts first use `define_func` with `items:[{addr,end}]`, then the same function rename/type/comment stages. Each stage is followed by the complete readback set; no stage adapts by discovery.

Complete modeled-function frame contracts from the dated live readback. A type stage may make only the stated delta; all unlisted rows, types and offsets remain byte-for-byte equal:

| ID | Literal S0 frame | Exact post-type/final stack-name frame and permitted delta |
| --- | --- | --- |
| I01 55f450 | `var_10@8/4:Pane *; var_C@c/4:_DWORD; var_4@14/4:_DWORD; __saved_registers@18/4:_DWORD; __return_address@1c/4:_UNKNOWN *; arg_0@20/1:_BYTE; arg_4@24/4:_DWORD` | exact complete post-frame: `var_10@8/4:Pane *; var_C@c/4:_DWORD; var_4@14/4:_DWORD; __saved_registers@18/4:_DWORD; __return_address@1c/4:_UNKNOWN *; orientation@20/1:unsigned __int8; arg_4@24/4:_DWORD`; replace only `arg_0` with `orientation`; preserve residual analysis-only `arg_4` unchanged; add/delete/shift/resize zero rows |
| I04 55f560 | `__saved_registers@8/4:_DWORD; __return_address@c/4:_UNKNOWN *; arg_0@10/4:_DWORD` | replace only arg_0 with `maxRange@10/2:__int16` |
| I05 55f5c0 | `__saved_registers@0/4:_DWORD; __return_address@4/4:_UNKNOWN *; arg_0@8/4:_DWORD` | replace only arg_0 with `position@8/2:__int16` |
| I06 55f5f0 | `__return_address@0/4:_UNKNOWN *` | identical; no delta |
| I09 55f650 | `var_2C@c/4:_DWORD; var_28@10/4:_DWORD; var_24@14/10:RectBounds; bounds@24/10:RectBounds; var_4@34/4:_DWORD; __saved_registers@38/4:_DWORD; __return_address@3c/4:_UNKNOWN *; arg_0@40/4:_DWORD` | replace only arg_0 with `event@40/4:Event *` |
| I10 55f840 | `__return_address@0x0/4:_UNKNOWN *` | `__return_address@0x0/4:_UNKNOWN *; event@0x4/4:Event *`; add only the typed event row |
| I11 55f850 | `__saved_registers@4/4:_DWORD; __return_address@8/4:_UNKNOWN *; arg_0@c/4:_DWORD` | replace arg_0 with `timerId@c/4:int`; append only `arg0@10/4:int; arg1@14/4:int` |
| I12 55f890 | `var_84@c/4:_DWORD; offset@10/8:Point; position@18/8:Point; var_70@20/4:_DWORD; outBounds@24/10:struct RectBounds; outContext@34/28:EPFTileContext; destinationBounds@5c/10:RectBounds; bounds@6c/10:struct RectBounds; var_14@7c/10:RectBounds; var_4@8c/4:_DWORD; __saved_registers@90/4:_DWORD; __return_address@94/4:_UNKNOWN *` | identical; no delta |
| I13 55ff70 | `offset@0xc/8:Point; position@0x14/8:Point; var_28@0x1c/0x10:_OWORD; var_18@0x2c/4:_DWORD; bounds@0x30/0x10:struct RectBounds; var_4@0x40/4:_DWORD; __saved_registers@0x44/4:_DWORD; __return_address@0x48/4:_UNKNOWN *; row@0x4c/4:int; column@0x50/4:int` | Immediate post-function-type frame is byte-for-byte identical and retains `row`/`column`. After the explicit two-entry stack rename, final frame is `offset@0xc/8:Point; position@0x14/8:Point; var_28@0x1c/0x10:_OWORD; var_18@0x2c/4:_DWORD; bounds@0x30/0x10:struct RectBounds; var_4@0x40/4:_DWORD; __saved_registers@0x44/4:_DWORD; __return_address@0x48/4:_UNKNOWN *; localY@0x4c/4:int; localX@0x50/4:int`; only the two names change |
| I14 560290 | `var_20@4/10:_OWORD; position@14/8:Point; offset@1c/8:Point; __saved_registers@24/4:_DWORD; __return_address@28/4:_UNKNOWN *; part@2c/4:ScrollSpellInventoryPart; bounds@30/4:struct RectBounds *` | identical; type/name no change |
| I17 560650 | `position@4/8:Point; bounds@c/10:RectBounds; var_4@1c/4:_DWORD; __saved_registers@20/4:_DWORD; __return_address@24/4:_UNKNOWN *` | identical; only function name changes |
| I18 560710 | `offset@c/8:Point; position@14/8:Point; oldPosition@1c/4:__int16[2]; bounds@20/10:RectBounds; var_24@30/10:_OWORD; var_14@40/4:_DWORD; var_10@44/4:_DWORD; var_4@50/4:_DWORD; __saved_registers@54/4:_DWORD; __return_address@58/4:_UNKNOWN *; localY@5c/4:int; localX@60/4:int` | identical; type/name no change |

Complete raw physical-byte prestates, independently reread live before report finalization. In addition to the range/hash/head/xref facts elsewhere, the immutable byte sequences are:

- I02: `55 8b ec 66 8b 45 08 66 39 81 f8 00 00 00 74 13 8b 11 66 89 81 f8 00 00 00 8d 41 44 89 45 08 5d ff 62 20 5d c2 04 00`.
- I03: `55 8b ec 8a 45 08 38 81 fa 00 00 00 74 12 8b 11 88 81 fa 00 00 00 8d 41 44 89 45 08 5d ff 62 20 5d c2 04 00`.
- I07: `80 b9 02 01 00 00 01 75 10 8b 11 8d 41 44 50 c6 81 02 01 00 00 00 ff 52 20 c3`.
- I08: `80 b9 02 01 00 00 00 74 0e 33 c0 66 3b 81 00 01 00 00 7d 03 b0 01 c3 32 c0 c3`.
- I15: `55 8b ec 83 ec 14 a1 24 2f 67 00 33 c5 89 45 fc 53 8b 5d 08 56 8b f1 8a 86 03 01 00 00 3a c3 74 3d 3c ff 74 17 8d 4d ec 51 50 8b ce e8 3f fd ff ff 8b 06 8d 4d ec 51 8b ce ff 50 20 80 fb ff 74 17 8d 45 ec 8b ce 50 53 e8 23 fd ff ff 8b 06 8d 4d ec 51 8b ce ff 50 20 88 9e 03 01 00 00 8b 4d fc 5e 33 cd 5b e8 a5 71 06 00 8b e5 5d c2 04 00`.
- I16: `55 8b ec 83 ec 24 a1 24 2f 67 00 33 c5 89 45 fc 53 8a 5d 08 56 8b f1 80 fb 02 75 6e 8a 86 03 01 00 00 3a c3 74 3a 3c ff 74 17 8d 4d ec 51 50 8b ce e8 ca fc ff ff 8b 06 8d 4d ec 51 8b ce ff 50 20 8d 45 ec 8b ce 50 6a 02 e8 b2 fc ff ff 8b 06 8d 4d ec 51 8b ce ff 50 20 c6 86 03 01 00 00 02 8d 45 dc 8b ce 50 6a 02 e8 93 fc ff ff 8b 45 10 2b 45 dc 50 8b 45 0c 2b 45 e0 50 8d 86 08 01 00 00 50 e8 19 76 f5 ff 83 c4 0c 8b ce 88 9e 04 01 00 00 e8 29 00 00 00 6a 00 6a 00 68 c8 00 00 00 6a 00 8d 8e a4 00 00 00 e8 a3 6f 03 00 8b 4d fc 5e 33 cd 5b e8 e6 70 06 00 8b e5 5d c2 0c 00`.
- I19: `55 8b ec 83 ec 14 a1 24 2f 67 00 33 c5 89 45 fc 56 8b f1 8d 8e a4 00 00 00 e8 42 6d 03 00 8a 86 03 01 00 00 c6 86 04 01 00 00 ff 3c ff 74 1e 8d 4d ec 51 50 8b ce e8 b5 f9 ff ff 8b 06 8d 4d ec 51 8b ce ff 50 20 c6 86 03 01 00 00 ff 8b 4d fc 33 cd 5e e8 37 6e 06 00 8b e5 5d c3`.

Raw immediate/post-type frame contracts below are literal dated public-endpoint observations from the supervisor's failed-unsaved Gate 2B experiment, not sibling-frame inference. Each `define_func` accepted the exact range and produced the listed sparse immediate frame; each independently tested `set_type` accepted the requested signature and produced the listed post-frame:

| ID / entry | Exact immediate post-define frame | Exact post-type frame | Allowed delta |
| --- | --- | --- | --- |
| I02 0x55f500 | `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *` | `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; sizeIndex@0x8/2:unsigned __int16` | add exactly the typed `sizeIndex` row; no generic argument row exists before typing |
| I03 0x55f530 | `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *` | `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; scrollStyle@0x8/1:unsigned __int8` | add exactly the typed `scrollStyle` row; no generic argument row exists before typing |
| I07 0x55f610 | `__return_address@0x0/4:_UNKNOWN *` | `__return_address@0x0/4:_UNKNOWN *` | none |
| I08 0x55f630 | `__return_address@0x0/4:_UNKNOWN *` | `__return_address@0x0/4:_UNKNOWN *` | none |
| I15 0x560520 | `__saved_registers@0x1c/4:_DWORD; __return_address@0x20/4:_UNKNOWN *` | `__saved_registers@0x1c/4:_DWORD; __return_address@0x20/4:_UNKNOWN *; part@0x24/4:ScrollSpellInventoryPart` | add exactly the typed `part` row; no local or generic argument row exists before typing |
| I16 0x560590 | `__saved_registers@0x2c/4:_DWORD; __return_address@0x30/4:_UNKNOWN *` | `__saved_registers@0x2c/4:_DWORD; __return_address@0x30/4:_UNKNOWN *; part@0x34/4:ScrollSpellInventoryPart; mouseY@0x38/4:int; mouseX@0x3c/4:int` | add exactly the three typed argument rows; no local or generic argument row exists before typing |
| I19 0x5608a0 | `__saved_registers@0x18/4:_DWORD; __return_address@0x1c/4:_UNKNOWN *` | `__saved_registers@0x18/4:_DWORD; __return_address@0x1c/4:_UNKNOWN *` | none |

Transaction catalog. `S0` includes the exact range/hash/xref set in Sections 14-15, immutable bytes/items, independent `AR absent; AP absent; FR absent; FP absent` for modeled unnamed functions, and `AR absent; AP absent; FR not applicable; FP not applicable` before raw definition. Existing function-regular comments at I14 and I18 are protected and remain present. Every destination-name collision lookup must return not found before function rename. For each raw row, D must produce exactly the sparse immediate frame above, R must preserve it byte-for-byte, and T must produce exactly the listed post-type frame. A generic `arg_0`/`arg_4`/`arg_8` or decompiler local such as `var_14`/`var_4`/`var_24` at the raw D or R stage is an unexpected row and requires rollback/no-save; a typed row may appear only where and after T as listed. For modeled I10, R preserves the immediate return-only frame; T alone is authorized to add exactly `event@0x4/4:Event *`, and no other frame delta is permitted. For modeled I13, T must preserve the complete `row`/`column` frame exactly; the separate stack-rename preflight must prove both old names present and both destination names absent, and only the subsequent stack-rename apply may change those two names.

| ID | Range and literal prestate | Ordered public actions and deterministic expected poststate |
| --- | --- | --- |
| I01 | 55f450-55f4f1; modeled `sub_55F450`; type `int __thiscall(int this, char)`; literal frame `var_10@0x8/4:Pane *; var_C@0xc/4:_DWORD; var_4@0x14/4:_DWORD; __saved_registers@0x18/4:_DWORD; __return_address@0x1c/4:_UNKNOWN *; arg_0@0x20/1:_BYTE; arg_4@0x24/4:_DWORD`; one xref; target `retn 4`; sole caller pushes one orientation value; detached SEH handler is the only `arg_4` reference | R `ScrollSpellInventoryPane__Constructor`; T via public `set_type({database:DB,edits:[{addr:"0x0055f450",kind:"function",signature:"ScrollSpellInventoryPane *__thiscall ScrollSpellInventoryPane__Constructor(ScrollSpellInventoryPane *this, unsigned __int8 orientation)"}]})`; immediately require exact complete post-frame `var_10@0x8/4:Pane *; var_C@0xc/4:_DWORD; var_4@0x14/4:_DWORD; __saved_registers@0x18/4:_DWORD; __return_address@0x1c/4:_UNKNOWN *; orientation@0x20/1:unsigned __int8; arg_4@0x24/4:_DWORD`; `arg_4` remains unchanged analysis-only SEH metadata and receives no rename/type/delete/create action; C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055f450",comment:"Constructs a 0x110-byte ScrollSpellInventoryPane and installs primary, EventHandler, and TimerHandler vtables."}]})`; expected AP exactly `Constructs a 0x110-byte ScrollSpellInventoryPane and installs primary, EventHandler, and TimerHandler vtables.`; preserve AR, FR, FP, bytes, range, hash, xrefs, items and every non-`arg_0` frame fact exactly; stop and rollback/no-save if T adds/deletes/shifts/resizes any row, changes `arg_4`, or any protected fact drifts. |
| I02 | 55f500-55f527; function/name/type absent; zero xrefs; 13 heads | D exact range -> exactly `sub_55F500`, absent persisted type, frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; stop if any other row exists. R `ScrollSpellInventoryPane__SetSizeIndex`; require the same two-row frame unchanged. T `void __thiscall ScrollSpellInventoryPane__SetSizeIndex(ScrollSpellInventoryPane *this, unsigned __int16 sizeIndex)`; require exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; sizeIndex@0x8/2:unsigned __int16`, with only the documented typed-row addition. C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055f500",comment:"Sets the size-index word at +0xf8 and invalidates the pane when the value changes."}]})`; expected AP exactly `Sets the size-index word at +0xf8 and invalidates the pane when the value changes.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, zero-xref set, items, and every name/type/frame fact except the authorized D/R/T deltas; stop and rollback/no-save if AP is not absent before C, AP readback differs, a generic argument/local row appears, the typed row is absent or differs, or any protected fact drifts. |
| I03 | 55f530-55f554; function/name/type absent; zero xrefs; 13 heads | D exact range -> exactly `sub_55F530`, absent persisted type, frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; stop if any other row exists. R `ScrollSpellInventoryPane__SetScrollStyle`; require the same two-row frame unchanged. T `void __thiscall ScrollSpellInventoryPane__SetScrollStyle(ScrollSpellInventoryPane *this, unsigned __int8 scrollStyle)`; require exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; scrollStyle@0x8/1:unsigned __int8`, with only the documented typed-row addition. C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055f530",comment:"Sets the scroll-style byte at +0xfa and invalidates the pane when the value changes."}]})`; expected AP exactly `Sets the scroll-style byte at +0xfa and invalidates the pane when the value changes.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, zero-xref set, items, and every name/type/frame fact except the authorized D/R/T deltas; stop and rollback/no-save if AP is not absent before C, AP readback differs, a generic argument/local row appears, the typed row is absent or differs, or any protected fact drifts. |
| I04 | 55f560-55f5bb; modeled `sub_55F560`; type `int __thiscall(_WORD *this, __int16)`; 1 xref | R `ScrollSpellInventoryPane__SetMaxRange`; T `void __thiscall ScrollSpellInventoryPane__SetMaxRange(ScrollSpellInventoryPane *this, __int16 maxRange)` changing only arg_0 to maxRange@0x10/2; C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055f560",comment:"Clamps the scroll range to 0..30000, clamps the current position when necessary, and invalidates the pane after a range change."}]})`; expected AP exactly `Clamps the scroll range to 0..30000, clamps the current position when necessary, and invalidates the pane after a range change.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, xrefs, items, frame, and every name/type fact except the authorized R/T deltas; stop if AP is not absent before C, if AP readback differs, or if any protected fact drifts. |
| I05 | 55f5c0-55f5e7; modeled `sub_55F5C0`; type `__int16 __thiscall(_WORD *this, __int16)`; 4 xrefs | R `ScrollSpellInventoryPane__SetScrollPosition`; T `void __thiscall ScrollSpellInventoryPane__SetScrollPosition(ScrollSpellInventoryPane *this, __int16 position)` changing only arg_0 to position@0x8/2; C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055f5c0",comment:"Stores a changed scroll position and invalidates the pane."}]})`; expected AP exactly `Stores a changed scroll position and invalidates the pane.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, xrefs, items, frame, and every name/type fact except the authorized R/T deltas; stop if AP is not absent before C, if AP readback differs, or if any protected fact drifts. |
| I06 | 55f5f0-55f60a; modeled `sub_55F5F0`; type `int __thiscall(_BYTE *this)`; 1 xref | R `ScrollSpellInventoryPane__Activate`; T `void __thiscall ScrollSpellInventoryPane__Activate(ScrollSpellInventoryPane *this)` with frame unchanged; C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055f5f0",comment:"Enables the pane and invalidates it only on the disabled-to-enabled transition."}]})`; expected AP exactly `Enables the pane and invalidates it only on the disabled-to-enabled transition.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, xrefs, items, frame, and every name/type fact except the authorized R/T deltas; stop if AP is not absent before C, if AP readback differs, or if any protected fact drifts. |
| I07 | 55f610-55f62a; raw absent; zero xrefs; 8 heads | D exact range -> exactly `sub_55F610`, absent persisted type, frame exactly `__return_address@0x0/4:_UNKNOWN *`; stop if any other row exists. R `ScrollSpellInventoryPane__Deactivate`; require the same return-only frame unchanged. T `void __thiscall ScrollSpellInventoryPane__Deactivate(ScrollSpellInventoryPane *this)`; require the same return-only frame unchanged. C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055f610",comment:"Disables the pane and invalidates it only on the enabled-to-disabled transition."}]})`; expected AP exactly `Disables the pane and invalidates it only on the enabled-to-disabled transition.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, zero-xref set, items, and every name/type/frame fact except the authorized D/R/T deltas; stop and rollback/no-save if AP is not absent before C, AP readback differs, any row appears/disappears, or any protected fact drifts. |
| I08 | 55f630-55f64a; raw absent; zero xrefs; 9 heads | D exact range -> exactly `sub_55F630`, absent persisted type, frame exactly `__return_address@0x0/4:_UNKNOWN *`; stop if any other row exists. R `ScrollSpellInventoryPane__CanScroll`; require the same return-only frame unchanged. T `bool __thiscall ScrollSpellInventoryPane__CanScroll(const ScrollSpellInventoryPane *this)`; require the same return-only frame unchanged. C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055f630",comment:"Returns true only while the pane is enabled and its signed scroll range is positive."}]})`; expected AP exactly `Returns true only while the pane is enabled and its signed scroll range is positive.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, zero-xref set, items, and every name/type/frame fact except the authorized D/R/T deltas; stop and rollback/no-save if AP is not absent before C, AP readback differs, any row appears/disappears, or any protected fact drifts. |
| I09 | 55f650-55f831; modeled `sub_55F650`; type `char __thiscall(int,int)`; vtable xref | R `ScrollSpellInventoryPane__HandlePointerOrMouseEvent`; T `bool __thiscall ScrollSpellInventoryPane__HandlePointerOrMouseEvent(EventHandler *this, Event *event)` preserving all existing locals; C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055f650",comment:"Handles cursor movement and left-button press or release, including hit testing, capture, interaction state, timer cleanup, and invalidation."}]})`; expected AP exactly `Handles cursor movement and left-button press or release, including hit testing, capture, interaction state, timer cleanup, and invalidation.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, xrefs, items, complete frame, and every name/type fact except the authorized R/T deltas; stop if AP is not absent before C, if AP readback differs, or if any protected fact drifts. |
| I10 | 55f840-55f845; modeled `sub_55F840`; type `char __stdcall(int)`; immediate/pre-type frame exactly `__return_address@0x0/4:_UNKNOWN *`; vtable xref | R `ScrollSpellInventoryPane__HandleKeyOrTextEvent`; require the same return-only frame unchanged. T `bool __thiscall ScrollSpellInventoryPane__HandleKeyOrTextEvent(EventHandler *this, Event *event)`; require post-type frame exactly `__return_address@0x0/4:_UNKNOWN *; event@0x4/4:Event *`, authorizing only the addition of the typed event row. C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055f840",comment:"Returns false because this pane handles no key or text event."}]})`; expected AP exactly `Returns false because this pane handles no key or text event.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, xrefs, items, and every name/type/frame fact except the authorized R/T deltas; stop and rollback/no-save if AP is not absent before C, AP readback differs, the event row appears before T, is absent or differs after T, any other frame row changes, or any protected fact drifts. |
| I11 | 55f850-55f883; modeled `sub_55F850`; type `char __thiscall(TimerHandler *,int,int,int)`; vtable xref | R `ScrollSpellInventoryPane__OnTimer`; T `bool __thiscall ScrollSpellInventoryPane__OnTimer(TimerHandler *this, int timerId, int arg0, int arg1)` changing only argument names/types; C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055f850",comment:"Repeats the active scroll interaction every 30 milliseconds while an active part is present and always reports the timer event handled."}]})`; expected AP exactly `Repeats the active scroll interaction every 30 milliseconds while an active part is present and always reports the timer event handled.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, xrefs, items, frame, and every name/type fact except the authorized R/T deltas; stop if AP is not absent before C, if AP readback differs, or if any protected fact drifts. |
| I12 | 55f890-55ff70; modeled `sub_55F890`; type `void __thiscall(int)`; vtable xref | R `ScrollSpellInventoryPane__OnPaint`; T `void __thiscall ScrollSpellInventoryPane__OnPaint(ScrollSpellInventoryPane *this)` preserving complete frame; C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055f890",comment:"Draws the scroll-page backgrounds, caps, and thumb with SLIDEBG.EPF/SLIDEBG.PAL and SCRBUTT.EPF/BUTTON.PAL resources."}]})`; expected AP exactly `Draws the scroll-page backgrounds, caps, and thumb with SLIDEBG.EPF/SLIDEBG.PAL and SCRBUTT.EPF/BUTTON.PAL resources.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, xrefs, items, complete frame, and every name/type fact except the authorized R/T deltas; stop if AP is not absent before C, if AP readback differs, or if any protected fact drifts. |
| I13 | 55ff70-56028d; modeled `sub_55FF70`; type `char __thiscall(int,int,int)`; two xrefs; complete pre-type frame `offset@0xc/8:Point; position@0x14/8:Point; var_28@0x1c/0x10:_OWORD; var_18@0x2c/4:_DWORD; bounds@0x30/0x10:struct RectBounds; var_4@0x40/4:_DWORD; __saved_registers@0x44/4:_DWORD; __return_address@0x48/4:_UNKNOWN *; row@0x4c/4:int; column@0x50/4:int` | R `ScrollSpellInventoryPane__HitTestPart`; require the complete pre-type frame unchanged. T `ScrollSpellInventoryPart __thiscall ScrollSpellInventoryPane__HitTestPart(ScrollSpellInventoryPane *this, int localY, int localX)`; require successful parsed type but the complete physical frame still exactly `offset@0xc/8:Point; position@0x14/8:Point; var_28@0x1c/0x10:_OWORD; var_18@0x2c/4:_DWORD; bounds@0x30/0x10:struct RectBounds; var_4@0x40/4:_DWORD; __saved_registers@0x44/4:_DWORD; __return_address@0x48/4:_UNKNOWN *; row@0x4c/4:int; column@0x50/4:int`. SR-D uses public `rename({database:DB,batch:{stack:[{func_addr:"0x0055ff70",old:"row",new:"localY"},{func_addr:"0x0055ff70",old:"column",new:"localX"}],allow_overwrite:false,dry_run:true,stop_on_error:true}})` with no `pure` member; require success, both old rows still present, both destination names absent, and no state change. SR-A repeats the identical call with `dry_run:false`; require final complete frame `offset@0xc/8:Point; position@0x14/8:Point; var_28@0x1c/0x10:_OWORD; var_18@0x2c/4:_DWORD; bounds@0x30/0x10:struct RectBounds; var_4@0x40/4:_DWORD; __saved_registers@0x44/4:_DWORD; __return_address@0x48/4:_UNKNOWN *; localY@0x4c/4:int; localX@0x50/4:int`, with both old names absent and only those two name deltas. C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x0055ff70",comment:"Hit-tests the five scroll parts with orientation-, range-, hover-, active-, and thumb-drag-sensitive geometry."}]})`; expected AP exactly `Hit-tests the five scroll parts with orientation-, range-, hover-, active-, and thumb-drag-sensitive geometry.`; preserve AR, FR, FP, bytes, range, hash, both xrefs, items, function type and all non-target frame facts. Stop and rollback/no-save on a missing old row, existing destination collision, overwrite request, endpoint error, partial rename, old name remaining, destination missing, any row addition/removal, offset/width/type change, any non-target name change, AP mismatch, or any protected-state drift. |
| I14 | 560290-560517; current name `ScrollSpellInventoryPane__GetPartRect`; exact current signature `void __thiscall(ScrollSpellInventoryPane *this, ScrollSpellInventoryPart part, RectBounds *bounds)`; comment channels independently read as AR absent; AP absent; FR exactly `Source-authored ScrollSpellInventoryPane::GetPartRect; part 2 is kScrollSpellInventoryPartThumb.`; FP absent; 13 xrefs | `apply`: no rename or type action; because the literal AP prestate is absent, call public `set_address_repeatable_comments({database:DB,items:[{addr:"0x00560290",comment:"Computes the requested scroll-part rectangle from visible bounds, orientation, range, position, and thumb-drag state."}]})` once; expected poststate is AP exactly `Computes the requested scroll-part rectangle from visible bounds, orientation, range, position, and thumb-drag state.`, with AR absent, the exact FR unchanged, and FP absent; preserve exact bytes, range, hash, 13-xref set, items, complete frame, name, and signature; stop before mutation if any quoted prestate differs, and rollback/no-save if AP readback differs or any protected fact drifts. |
| I15 | 560520-560590; raw absent; zero xrefs; 46 heads | D exact range -> exactly `sub_560520`, absent persisted type, frame exactly `__saved_registers@0x1c/4:_DWORD; __return_address@0x20/4:_UNKNOWN *`; stop if any other row exists. R `ScrollSpellInventoryPane__SetHoverPart`; require the same two-row frame unchanged. T `void __thiscall ScrollSpellInventoryPane__SetHoverPart(ScrollSpellInventoryPane *this, ScrollSpellInventoryPart part)`; require exactly `__saved_registers@0x1c/4:_DWORD; __return_address@0x20/4:_UNKNOWN *; part@0x24/4:ScrollSpellInventoryPart`, with only the documented typed-row addition. C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x00560520",comment:"Invalidates the old and new hover-part rectangles before storing a changed hover part."}]})`; expected AP exactly `Invalidates the old and new hover-part rectangles before storing a changed hover part.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, zero-xref set, items, and every name/type/frame fact except the authorized D/R/T deltas; stop and rollback/no-save if AP is not absent before C, AP readback differs, a local/generic argument row appears, the typed row is absent or differs, or any protected fact drifts. |
| I16 | 560590-56064f; raw absent; zero xrefs; 70 heads | D exact range -> exactly `sub_560590`, absent persisted type, frame exactly `__saved_registers@0x2c/4:_DWORD; __return_address@0x30/4:_UNKNOWN *`; stop if any other row exists. R `ScrollSpellInventoryPane__BeginInteraction`; require the same two-row frame unchanged. T `void __thiscall ScrollSpellInventoryPane__BeginInteraction(ScrollSpellInventoryPane *this, ScrollSpellInventoryPart part, int mouseY, int mouseX)`; require exactly `__saved_registers@0x2c/4:_DWORD; __return_address@0x30/4:_UNKNOWN *; part@0x34/4:ScrollSpellInventoryPart; mouseY@0x38/4:int; mouseX@0x3c/4:int`, with only the documented three typed-row additions. C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x00560590",comment:"Begins thumb or page interaction, captures the thumb offset when required, performs the initial scroll update, and schedules the 200 millisecond repeat timer."}]})`; expected AP exactly `Begins thumb or page interaction, captures the thumb offset when required, performs the initial scroll update, and schedules the 200 millisecond repeat timer.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, zero-xref set, items, and every name/type/frame fact except the authorized D/R/T deltas; stop and rollback/no-save if AP is not absent before C, AP readback differs, a local/generic argument row appears, any typed row is absent or differs, or any protected fact drifts. |
| I17 | 560650-560710; modeled `sub_560650`; correct `void __thiscall(ScrollSpellInventoryPane *)`; 3 xrefs | R `ScrollSpellInventoryPane__UpdateDragScroll`; type no-change verified; C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x00560650",comment:"Reads the cursor and updates the active thumb drag or page interaction, including hover-part transitions and invalidation."}]})`; expected AP exactly `Reads the cursor and updates the active thumb drag or page interaction, including hover-part transitions and invalidation.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, xrefs, items, complete frame, and type, with only the authorized rename delta; stop if AP is not absent before C, if AP readback differs, or if any protected fact drifts. |
| I18 | 560710-56089d; current name `ScrollSpellInventoryPane__UpdateFromDrag`; exact current signature `void __thiscall(ScrollSpellInventoryPane *this, int localY, int localX)`; comment channels independently read as AR absent; AP absent; FR exactly `Source-authored ScrollSpellInventoryPane::UpdateFromDrag(localY,localX). Preserves orientation-specific formulas, signed short range/positions, Point y/x drag offsets, and parent NewSpell callback without adding guards.`; FP absent; 2 xrefs | `apply`: no rename or type action; because the literal AP prestate is absent, call public `set_address_repeatable_comments({database:DB,items:[{addr:"0x00560710",comment:"Maps local cursor coordinates to a clamped scroll position and notifies NewSpellInventoryPane only when the position changes."}]})` once; expected poststate is AP exactly `Maps local cursor coordinates to a clamped scroll position and notifies NewSpellInventoryPane only when the position changes.`, with AR absent, the exact FR unchanged, and FP absent; preserve exact bytes, range, hash, 2-xref set, items, complete frame, name, and signature; stop before mutation if any quoted prestate differs, and rollback/no-save if AP readback differs or any protected fact drifts. |
| I19 | 5608a0-5608fc; raw absent; zero xrefs; 32 heads | D exact range -> exactly `sub_5608A0`, absent persisted type, frame exactly `__saved_registers@0x18/4:_DWORD; __return_address@0x1c/4:_UNKNOWN *`; stop if any other row exists. R `ScrollSpellInventoryPane__ResetScrollState`; require the same two-row frame unchanged. T `void __thiscall ScrollSpellInventoryPane__ResetScrollState(ScrollSpellInventoryPane *this)`; require the same two-row frame unchanged. C requires AP absent, then public `set_address_repeatable_comments({database:DB,items:[{addr:"0x005608a0",comment:"Removes pending timers, clears active interaction state, and invalidates and clears the previous hover part."}]})`; expected AP exactly `Removes pending timers, clears active interaction state, and invalidates and clears the previous hover part.`; preserve AR, FR, and FP exactly; preserve exact bytes, range, hash, zero-xref set, items, and every name/type/frame fact except the authorized D/R/T deltas; stop and rollback/no-save if AP is not absent before C, AP readback differs, any row appears/disappears, or any protected fact drifts. |

Fresh protected-state evidence below was read through the canonical read-only MCP session `supervisor_uid0000n1_hashrepair_20260816` at `2026-08-16T09:30:14.8873445-04:00`; health was `status:ok`, canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready. That session identity is dated evidence only; supervisor Gate 2B must establish current authority dynamically. P01 remains the exact protected 0x110-byte UDT and P02 remains the exact protected four-byte enum identity/formal member semantics. P03-P07 are independently itemized below; every row is `no change recommended`.

**P03 protected vtable and RTTI objects**

| ID | Literal current prestate | Required unchanged readback |
| --- | --- | --- |
| P03-01 | `0x00623e90-0x00623e94`, primary COL word; name absent; type absent; one 4-byte data item; AR absent; AP absent; FR/FP not applicable; bytes encode `0x0064f98c`, SHA256 `13147AD3AE8D3460F227D2095136EBB995EE1186159B4EA139A03CE2697AC029`; zero xrefs; bounded immediately by the primary vtable at 0x00623e94. | Preserve exact range, item state, absent name/type/channels, four bytes/hash, zero-xref set, and 0x00623e94 boundary. |
| P03-02 | `0x00623e94-0x00623edc`, primary vtable; head name `??_7ScrollSpellInventoryPane@@6B@`; type absent; eighteen consecutive 4-byte data slots; AR absent; AP absent; FR/FP not applicable; SHA256 `ED32F2C53BD462F819CF77105A1A6644302C2D82EFB27193F7855896755F388F`; slots exactly `421480 ScrollPaneFamily__ScalarDeletingDestructor, 4f4b10 LObject__GetRuntimeClass, 41b6c0 LObject__OnChangeMessage, 4b8e20 sub_4B8E20, 41d680 Pane_DrawOnTarget, 544730 sub_544730, 544750 sub_544750, 5447a0 Pane_GetParentPane, 544800 Pane_InvalidateRect, 544a20 Pane_GetDescription, 544b80 sub_544B80, 544bd0 sub_544BD0, 544c70 Pane_AddToLayer, 544cb0 sub_544CB0, 544ce0 Pane_RemoveFromLayer, 544d30 Pane_SetPaneOrder, 544d70 Pane_UnregisterEventHandler, 55f890 sub_55F890`; exact xref set `{55f4a1:data from sub_55F450}`; next boundary 0x00623edc. | Preserve exact decorated name, item/type/channel state, 72-byte hash, all eighteen slot addresses/current names in order, sole xref, and boundaries. |
| P03-03 | `0x00623edc-0x00623ee0`, EventHandler-view COL word; name absent; type absent; one 4-byte data item; AR absent; AP absent; FR/FP not applicable; bytes encode `0x0064f9e8`, SHA256 `E6F8EF1B9B0ACF851CB4CE9E16FF971B07F341FE720E3B01B746E962DE2B6881`; zero xrefs; bounded by EventHandler vtable at 0x00623ee0. | Preserve exact range, item state, absent name/type/channels, bytes/hash, zero-xref set, and boundary. |
| P03-04 | `0x00623ee0-0x00623f0c`, EventHandler-view vtable; head name `??_7ScrollSpellInventoryPane@@6B@_0`; type absent; eleven 4-byte data slots; AR absent; AP absent; FR/FP not applicable; SHA256 `0153A4C673B4B4270EA59E75A0FDCDAD3C7367B029EF75A15EC9FBEFF722130B`; slots exactly `4213f8 ScrollPaneFamily__EventHandlerScalarDeletingDestructorAdjustor, 55f650 sub_55F650, 55f840 sub_55F840, 544dd0 sub_544DD0, 544de0 sub_544DE0, 544df0 sub_544DF0, 544e00 sub_544E00, 4a89f0 sub_4A89F0, 544e10 sub_544E10, 544e30 sub_544E30, 544e70 sub_544E70`; exact xref set `{55f4a7:data from sub_55F450}`; next boundary 0x00623f0c. | Preserve exact decorated name, item/type/channel state, 44-byte hash, all eleven slot addresses/current names in order, sole xref, and boundaries. |
| P03-05 | `0x00623f0c-0x00623f10`, TimerHandler-view COL word; name absent; type absent; one 4-byte data item; AR absent; AP absent; FR/FP not applicable; bytes encode `0x0064f9fc`, SHA256 `E5C25F45710C7B4E938F60F3A8FC7752681BB97E98924444E97BE712672DC3F6`; zero xrefs; bounded by TimerHandler vtable at 0x00623f10. | Preserve exact range, item state, absent name/type/channels, bytes/hash, zero-xref set, and boundary. |
| P03-06 | `0x00623f10-0x00623f18`, TimerHandler-view vtable; head name `??_7ScrollSpellInventoryPane@@6B@_1`; type absent; two 4-byte data slots; AR absent; AP absent; FR/FP not applicable; SHA256 `86C6C267C7B6D28BC66DC3FDFC14CC37FCF956D31A6BD0C7E7DAD5731451027E`; slots exactly `421403 ScrollPaneFamily__TimerHandlerScalarDeletingDestructorAdjustor, 55f850 sub_55F850`; exact xref set `{55f4b1:data from sub_55F450}`; terminal vtable-data boundary 0x00623f18. | Preserve exact decorated name, item/type/channel state, eight-byte hash, both slots/current names in order, sole xref, and boundaries. |
| P03-07 | `0x0064f98c-0x0064f9a0`, name `??_R4ScrollSpellInventoryPane@@6B@`; type absent; data; AR exactly `signature`; AP absent; FR/FP not applicable; SHA256 `BCE01AFA35D86421DD165F45E83E54DA591F4F0766604FCB90E82F2DD3CAADCA`; exact xref set `{623e90:data}`; next boundary 0x0064f9a0. | Preserve exact name/range/data state/channels/hash/xref/boundary. |
| P03-08 | `0x0064f9a0-0x0064f9b0`, name `??_R3ScrollSpellInventoryPane@@8`; type absent; data; AR exactly `signature`; AP absent; FR/FP not applicable; SHA256 `7B92B8705A3052760D965B4F94B6E9F148CEFF09BBB076F2D5AFCC9AA9E172FF`; exact xrefs `{64f99c:data,64f9e4:data,64f9f8:data,64fa0c:data}`; next boundary 0x0064f9b0. | Preserve exact name/range/data state/channels/hash/four-xref set/boundary. |
| P03-09 | `0x0064f9b0-0x0064f9cc`, name `??_R2ScrollSpellInventoryPane@@8`; type absent; data; AR exactly `reference to base class decription 1`; AP absent; FR/FP not applicable; SHA256 `D6394CB23C69B957B85548A65355535BF011AB42026603D2C1CF7C77A34BF116`; exact xref `{64f9ac:data}`; next boundary 0x0064f9cc. | Preserve the literal misspelled AR text, exact name/range/data state/AP/hash/xref/boundary. |
| P03-10 | `0x0064f9cc-0x0064f9e8`, name `??_R1A@?0A@EA@ScrollSpellInventoryPane@@8`; type absent; data; AR exactly `reference to type description`; AP absent; FR/FP not applicable; SHA256 `B06571CA6B2A6A390BBD608D1D321D67906AFC86BE4C50375AD096379EA0F597`; exact xref `{64f9b0:data}`; next boundary 0x0064f9e8. | Preserve exact name/range/data state/channels/hash/xref/boundary. |
| P03-11 | `0x0064f9e8-0x0064f9fc`, name `??_R4ScrollSpellInventoryPane@@6B@_0`; type absent; data; AR exactly `signature`; AP absent; FR/FP not applicable; SHA256 `13026332722B2549ABF46F1845317CE961A798A01FB2CE670FDE337CD764CB80`; exact xref `{623edc:data}`; next boundary 0x0064f9fc. | Preserve exact name/range/data state/channels/hash/xref/boundary. |
| P03-12 | `0x0064f9fc-0x0064fa10`, name `??_R4ScrollSpellInventoryPane@@6B@_1`; type absent; data; AR exactly `signature`; AP absent; FR/FP not applicable; SHA256 `8E47B2C4FA7B5A7638A85EE756604CE8243A7624540E6EE6A3CEECE51DE65EF8`; exact xref `{623f0c:data}`; next object boundary 0x0064fa10. | Preserve exact name/range/data state/channels/hash/xref/boundary. |
| P03-13 | `0x00678f98-0x00678fc0`, type descriptor name `??_R0?AVScrollSpellInventoryPane@@@8`; persisted type absent; data; AR exactly `reference to RTTI's vftable`; AP absent; FR/FP not applicable; exact bytes include the decorated ASCII descriptor and SHA256 `F66D6328923A389F09B1351D983277D8CDD78A0D097D14483C00515761664A7B`; exact xrefs `{64f998:data,64f9cc:data,64f9f4:data,64fa08:data}`; next descriptor boundary 0x00678fc0. | Preserve exact name/range/data state/channels/40-byte hash/four-xref set/boundary. |

**P04 protected shared deleting wrappers**

| ID | Literal current prestate | Required unchanged readback |
| --- | --- | --- |
| P04-01 | Function `0x00421480-0x004214bb`, name `ScrollPaneFamily__ScalarDeletingDestructor`, signature `Pane *__thiscall(Pane *object, unsigned __int8 flags)`; AR absent; AP absent; FR absent; FP exactly `Shared MSVC scalar deleting destructor for Pane-derived scrollbar classes; invokes Pane teardown and conditionally frees storage. Compiler-generated and reused by eight primary vtables.`; 59-byte SHA256 `74C84FE42E021379683679528FC9CCE833CF7D8F3BBC7ABA7735AF977F0FAC1C`; exact xrefs `{4213fe:code,421409:code,60dc88:data,610a4c:data,623d5c:data,623e94:data,623f1c:data,623fa4:data,62402c:data,6240b4:data}`. | Preserve exact function range/name/signature, all four channels, bytes/hash, ten-xref set, item boundaries, and compiler-product disposition. |
| P04-02 | Function `0x004213f8-0x00421403`, name `ScrollPaneFamily__EventHandlerScalarDeletingDestructorAdjustor`, signature `Pane *__thiscall(EventHandler *eventView, unsigned __int8 flags)`; AR exactly `object`; AP absent; FR absent; FP exactly `Compiler-generated EventHandler-view deleting-destructor adjustor: subtracts 0xA0 from ECX and tail-jumps to 0x00421480.`; exact bytes SHA256 `3EC230186B0D77FD48BBE1AFB96EEEEE6075AFE81BB8F715E21F86E5E26EBE7A`; exact xrefs `{60dcd4,610a98,623da8,623ee0,623f68,623ff0,624078,624100}:data`. | Preserve exact range/name/signature, all channels, 11-byte hash, eight-xref set, boundary at 0x00421403, and compiler-product disposition. |
| P04-03 | Function `0x00421403-0x0042140e`, name `ScrollPaneFamily__TimerHandlerScalarDeletingDestructorAdjustor`, signature `Pane *__thiscall(TimerHandler *timerView, unsigned __int8 flags)`; AR exactly `object`; AP absent; FR absent; FP exactly `Compiler-generated TimerHandler-view deleting-destructor adjustor: subtracts 0xA4 from ECX and tail-jumps to 0x00421480.`; exact bytes SHA256 `F669DF77574D0B123DA0E2606D18659C1CADF5DDB45DEAD74971B7482B3A34D4`; exact xrefs `{60dd04,610ac8,623dd8,623f10,623f98,624020,6240a8,624130}:data`. | Preserve exact range/name/signature, all channels, 11-byte hash, eight-xref set, boundaries, and compiler-product disposition. |

**P05 protected shared extent table**

| ID | Literal current prestate | Required unchanged readback |
| --- | --- | --- |
| P05-01 | Logical table `0x00624144-0x00624150`, name `kScrollPanePartExtentBySkin`; persisted type `const int[3]` on the 4-byte data head at 0x00624144, with the trailing eight bytes physically undefined/untyped; values exactly `{38,38,38}`, little-endian SHA256 `8B0275C7658FB3FEE3E0A992EDB0D77BCFFBD6B3E3ECAD70C84E8D40A853FD25`; base AR absent; base AP exactly `Scrollbar fixed part/thumb extent indexed by skin.`; FR/FP not applicable; interior AR/AP absent and FR/FP not applicable; exact 22-xref base set `{55c76c,55cb28,55d1b4,55d46e,55db61,55ec5c,55f997,55fc96,5600fc,5603eb,560e47,561146,5615ac,56189b,5622f7,5625f6,562a5c,562d4b,5637a7,563aa6,563f0c,5641fb}:data`; zero interior xrefs; next named boundary `0x00624150 kClassicScrollPaneWidthBySkin`. | Preserve exact logical range, physical item partition, name/type, three values/hash, all comment channels, 22-xref base set, zero interior xrefs, and successor boundary. |

**P06 protected wide resource constants**

| ID | Literal current prestate | Required unchanged readback |
| --- | --- | --- |
| P06-01 | Logical `0x0060ddb0-0x0060ddc8`, UTF-16LE `SLIDEBG.EPF\0`, SHA256 `A0EF023E0C2F376093826024002F0230D447F77FC59C4FEF45C2A0620BFD4760`; base 4-byte data item name `kScrollBackgroundImageName`, type `const wchar_t[]`, followed by data continuation `aIdebgEpf` at 0x0060ddb4 with type absent; base AR absent; base AP exactly `Scrollbar track EPF resource name.`; continuation AR/AP absent; FR/FP not applicable throughout; exact base xrefs `{41dcbc,41dd52,41ddc1,41dfbf,41e05e,41e0d6,459ee6,459f7f,459fee,45a1ec,45a28b,45a306,55c92f,55c9cb,55ca40,55cd3f,55cde4,55ce5f,55fa9c,55fb32,55fba1,55fd9f,55fe3e,55feb6,560f4c,560fe2,561051,56124f,5612ee,561366,5623fc,562492,562501,5626ff,56279e,562816,5638ac,563942,5639b1,563baf,563c4e,563cc6}:data`; continuation xrefs zero; next boundary 0x0060ddc8. | Preserve exact range/value/hash, split item names/types, all applicable channels, exact 42-xref base set, zero continuation xrefs, and boundary. |
| P06-02 | Logical `0x0060ddc8-0x0060dde0`, UTF-16LE `SLIDEBG.PAL\0`, SHA256 `29F313230170CE25E45CC1F52AD4C960E53CEB13A0DC1F5F842FF0432B03361B`; base name `kScrollBackgroundPaletteName`, type `const wchar_t[]`, continuation `aIdebgPal` at 0x0060ddcc with type absent; base AR absent; base AP exactly `Scrollbar track palette resource name.`; continuation AR/AP absent; FR/FP not applicable; exact base xrefs `{41dce5,41dd76,41ddcf,41dfe8,41e082,41e0e4,459f12,459fa3,459ffc,45a215,45a2b2,45a314,55c958,55c9f2,55ca4e,55cd68,55ce08,55ce6d,55fac5,55fb56,55fbaf,55fdc8,55fe62,55fec4,560f75,561006,56105f,561278,561312,561374,562425,5624b6,56250f,562728,5627c2,562824,5638d5,563966,5639bf,563bd8,563c72,563cd4}:data`; continuation xrefs zero; next boundary 0x0060dde0. | Preserve exact range/value/hash, split item names/types, all applicable channels, exact 42-xref base set, zero continuation xrefs, and boundary. |
| P06-03 | Logical `0x0060dde0-0x0060ddf8`, UTF-16LE `SCRBUTT.EPF\0`, SHA256 `E0B62D910EB46FC061FE55DC649658E390076C120FEB590CD7FABD34EA1B0589`; base name `kScrollButtonImageName`, type `const wchar_t[]`, continuation `aRbuttEpf` at 0x0060dde4 with type absent; base AR absent; base AP exactly `Scrollbar thumb EPF resource name.`; continuation AR/AP absent; FR/FP not applicable; exact base xrefs `{41e15e,45a38e,55cee6,55ff3a,5613ea,56289a,563d4a}:data`; continuation xrefs zero; next boundary 0x0060ddf8. | Preserve exact range/value/hash, split item names/types, all applicable channels, exact seven-xref base set, zero continuation xrefs, and boundary. |
| P06-04 | Logical `0x0060ddf8-0x0060de0e`, UTF-16LE `BUTTON.PAL\0`, SHA256 `431D18F8A4B52D49C87FBC3083E2F4A6D9DAB620100491CFEB489C827024F750`; base name `kButtonPaletteName`, type `const wchar_t[]`, continuation `aTtonPal` at 0x0060ddfc with type absent; base AR absent; base AP exactly `Button palette resource name used by scrollbar thumb rendering.`; continuation AR/AP absent; FR/FP not applicable; exact base xrefs `{41e16a,450f50,450ffd,45a39a,47d3a4,4995dc,499623,4eedd1,4eee28,541769,55cef2,55ff46,5613f6,5628a6,563d56,564df8,567884,5678d8,567a1f,567a9c,571595,5715e8,571665,5716e2,571b7e,571bd1,59e07b,5a0c7f,5a0ced}:data`; continuation xrefs zero; next named item is `0x0060de10 aS`. | Preserve exact range/value/hash, split item names/types, all applicable channels, exact 29-xref base set, zero continuation xrefs, and boundary. |

**P07 protected alignment spans and excluded successor**

| ID | Literal current prestate | Required unchanged readback |
| --- | --- | --- |
| P07-01 | `0x0055f4f1-0x0055f500`; one 15-byte data item; name absent; type absent; AR absent; AP absent; FR/FP not applicable; all bytes `CC`, SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`; zero xrefs. | Preserve exact range/item/name/type/channels, 15 CC bytes/hash, zero xrefs, and both method boundaries. |
| P07-02 | `0x0055f527-0x0055f530`; one 9-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; zero xrefs. | Preserve exact range/state/channels, nine CC bytes/hash, zero xrefs, and boundaries. |
| P07-03 | `0x0055f554-0x0055f560`; one 12-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`; zero xrefs. | Preserve exact range/state/channels, twelve CC bytes/hash, zero xrefs, and boundaries. |
| P07-04 | `0x0055f5bb-0x0055f5c0`; one 5-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`; zero xrefs. | Preserve exact range/state/channels, five CC bytes/hash, zero xrefs, and boundaries. |
| P07-05 | `0x0055f5e7-0x0055f5f0`; one 9-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; zero xrefs. | Preserve exact range/state/channels, nine CC bytes/hash, zero xrefs, and boundaries. |
| P07-06 | `0x0055f60a-0x0055f610`; one 6-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`; zero xrefs. | Preserve exact range/state/channels, six CC bytes/hash, zero xrefs, and boundaries. |
| P07-07 | `0x0055f62a-0x0055f630`; one 6-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`; zero xrefs. | Preserve exact range/state/channels, six CC bytes/hash, zero xrefs, and boundaries. |
| P07-08 | `0x0055f64a-0x0055f650`; one 6-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`; zero xrefs. | Preserve exact range/state/channels, six CC bytes/hash, zero xrefs, and boundaries. |
| P07-09 | `0x0055f831-0x0055f840`; one 15-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`; zero xrefs. | Preserve exact range/state/channels, fifteen CC bytes/hash, zero xrefs, and boundaries. |
| P07-10 | `0x0055f845-0x0055f850`; one 11-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`; zero xrefs. | Preserve exact range/state/channels, eleven CC bytes/hash, zero xrefs, and boundaries. |
| P07-11 | `0x0055f883-0x0055f890`; one 13-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`; zero xrefs. | Preserve exact range/state/channels, thirteen CC bytes/hash, zero xrefs, and boundaries. |
| P07-12 | `0x0056028d-0x00560290`; one 3-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`; zero xrefs. | Preserve exact range/state/channels, three CC bytes/hash, zero xrefs, and boundaries. |
| P07-13 | `0x00560517-0x00560520`; one 9-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; zero xrefs. | Preserve exact range/state/channels, nine CC bytes/hash, zero xrefs, and boundaries. |
| P07-14 | `0x0056064f-0x00560650`; one 1-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; byte `CC`, SHA256 `1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6`; zero xrefs. | Preserve exact range/state/channels, one CC byte/hash, zero xrefs, and boundaries. |
| P07-15 | `0x0056089d-0x005608a0`; one 3-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`; zero xrefs. | Preserve exact range/state/channels, three CC bytes/hash, zero xrefs, and boundaries. |
| P07-16 | `0x005608fc-0x00560900`; one 4-byte data item; name/type absent; AR/AP absent; FR/FP not applicable; all `CC`, SHA256 `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`; zero xrefs; exact boundary to excluded successor at 0x00560900. | Preserve exact range/state/channels, four CC bytes/hash, zero xrefs, and 0x00560900 boundary. |
| P07-17 | Excluded successor function `0x00560900-0x005609a1`; current name `sub_560900`; exact current signature `int __thiscall(int this, char)`; current code item head `0x00560900-0x00560901`; AR absent; AP absent; FR absent; FP absent; 161-byte SHA256 `1EDF092B76FA832F5ACD79A2CF4412240C95BA134D29659EE4AB4309B44ADBAB`; exact xref `{56caae:code from NewGroupPane__Constructor}`; exact frame `var_10@8/4:Pane *; var_C@c/4:_DWORD; var_4@14/4:_DWORD; __saved_registers@18/4:_DWORD; __return_address@1c/4:_UNKNOWN *; arg_0@20/1:_BYTE; arg_4@24/4:_DWORD`. | Preserve exact successor range/name/signature/item state, all four absent channels, full-byte hash, sole xref, complete frame, and exclusion from UID0000NJ. |

Any P03-P07 drift stops the transaction before save. Save is permitted only after all applied and protected readbacks pass; backup/save mechanics are supervisor-owned and are not encoded as an executable package here.

## First-Draft C++ Recommendation

Applied exact formal insertion channels follow. UID0000CN owns only the source preamble/child marker and the complete declaration header. Each exact by-memory child owns exactly one method definition in its CPP channel and has a deliberately blank H channel because UID0000CN owns the declaration. These are owning-channel payloads, not one aggregate substitute.

**UID0000CN `RECONSTRUCTION_CPP CODE` parent/preamble:**

```cpp
#include "ScrollSpellInventoryPane.h"

#include "NewSpellInventoryPane.h"
#include "../core/Event.h"
#include "../core/ScrollBar.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/Surface.h"

[[CHILDREN]]
```

**UID000538 `by-memory/0x0055f450-0x0055f4f1.ScrollSpellInventoryPaneConstructor.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
ScrollSpellInventoryPane::ScrollSpellInventoryPane(unsigned char orientation)
    : Pane(1),
      m_sizeIndex(0),
      m_scrollStyle(1),
      m_thumbDragActive(false),
      m_orientation(orientation),
      m_scrollPosition(0),
      m_scrollRange(0),
      m_enabled(true),
      m_hoverPart(kScrollSpellInventoryPartNone),
      m_activePart(kScrollSpellInventoryPartNone)
{
    InitPointPair(&m_thumbDragOffset, 0, 0);
}
```

**UID000538 `RECONSTRUCTION_H CODE`:** blank; the constructor declaration is owned by UID0000CN.

**UID000539 `by-memory/0x0055f500-0x0055f527.ScrollSpellInventoryPaneSetSizeIndexRaw.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::SetSizeIndex(unsigned short sizeIndex)
{
    if (m_sizeIndex != sizeIndex) {
        m_sizeIndex = sizeIndex;
        InvalidateRect(&m_visibleBounds);
    }
}
```

**UID000539 `RECONSTRUCTION_H CODE`:** blank; the method declaration is owned by UID0000CN.

**UID00053A `by-memory/0x0055f530-0x0055f554.ScrollSpellInventoryPaneSetScrollStyleRaw.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::SetScrollStyle(unsigned char scrollStyle)
{
    if (m_scrollStyle != scrollStyle) {
        m_scrollStyle = scrollStyle;
        InvalidateRect(&m_visibleBounds);
    }
}
```

**UID00053A `RECONSTRUCTION_H CODE`:** blank; the method declaration is owned by UID0000CN.

**UID00053B `by-memory/0x0055f560-0x0055f5bb.ScrollSpellInventoryPaneSetMaxRange.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::SetMaxRange(short maxRange)
{
    if (maxRange < 0) {
        maxRange = 0;
    }
    if (maxRange > 30000) {
        maxRange = 30000;
    }
    if (m_scrollRange == maxRange) {
        return;
    }
    if (m_scrollPosition > maxRange) {
        m_scrollPosition = maxRange;
        InvalidateRect(&m_visibleBounds);
    }
    m_scrollRange = maxRange;
    InvalidateRect(&m_visibleBounds);
}
```

**UID00053B `RECONSTRUCTION_H CODE`:** blank; the method declaration is owned by UID0000CN.

**UID00053C `by-memory/0x0055f5c0-0x0055f5e7.ScrollSpellInventoryPaneSetScrollPosition.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::SetScrollPosition(short position)
{
    if (m_scrollPosition == position) {
        return;
    }
    m_scrollPosition = position;
    InvalidateRect(&m_visibleBounds);
}
```

**UID00053C `RECONSTRUCTION_H CODE`:** blank; the method declaration is owned by UID0000CN.

**UID00053D `by-memory/0x0055f5f0-0x0055f60a.ScrollSpellInventoryPaneActivate.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::Activate()
{
    if (!m_enabled) {
        m_enabled = true;
        InvalidateRect(&m_visibleBounds);
    }
}
```

**UID00053D `RECONSTRUCTION_H CODE`:** blank; the method declaration is owned by UID0000CN.

**UID00053E `by-memory/0x0055f610-0x0055f62a.ScrollSpellInventoryPaneDeactivateRaw.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::Deactivate()
{
    if (m_enabled) {
        m_enabled = false;
        InvalidateRect(&m_visibleBounds);
    }
}
```

**UID00053E `RECONSTRUCTION_H CODE`:** blank; the method declaration is owned by UID0000CN.

**UID00053F `by-memory/0x0055f630-0x0055f64a.ScrollSpellInventoryPaneCanScrollRaw.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
bool ScrollSpellInventoryPane::CanScroll() const
{
    return m_enabled && m_scrollRange > 0;
}
```

**UID00053F `RECONSTRUCTION_H CODE`:** blank; the method declaration is owned by UID0000CN.

**UID00053G `by-memory/0x0055f650-0x0055f831.ScrollSpellInventoryPaneHandlePointerOrMouseEvent.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
bool ScrollSpellInventoryPane::HandlePointerOrMouseEvent(Event *event)
{
    bool handled = false;
    RectBounds partRect;
    const int mouseY = event->m_payload.m_pointer.m_y;
    const int mouseX = event->m_payload.m_pointer.m_x;

    switch (event->m_type) {
    case kEventCursorMove:
        if (m_activePart != kScrollSpellInventoryPartNone) {
            InvalidateRect(&m_visibleBounds);
            handled = true;
        }
        break;

    case kEventLeftButtonDown:
        if (!PointInRect(mouseY, mouseX, &m_visibleBounds) || !CanScroll()) {
            return false;
        }
        if (m_activePart == kScrollSpellInventoryPartNone) {
            const ScrollSpellInventoryPart part = HitTestPart(mouseY, mouseX);
            if (part != kScrollSpellInventoryPartNone) {
                CaptureMouse();
                BeginInteraction(part, mouseY, mouseX);
                InvalidateRect(&m_visibleBounds);
            }
        }
        m_thumbDragActive = true;
        handled = true;
        break;

    case kEventLeftButtonUp:
        if (m_activePart != kScrollSpellInventoryPartNone) {
            ReleaseMouseCapture();
            RemovePendingTimers();
            const ScrollSpellInventoryPart oldPart =
                static_cast<ScrollSpellInventoryPart>(m_hoverPart);
            m_activePart = kScrollSpellInventoryPartNone;
            if (oldPart != kScrollSpellInventoryPartNone) {
                GetPartRect(oldPart, &partRect);
                InvalidateRect(&partRect);
                m_hoverPart = kScrollSpellInventoryPartNone;
            }
            handled = true;
        }
        m_thumbDragActive = false;
        InvalidateRect(&m_visibleBounds);
        break;

    default:
        break;
    }
    return handled;
}
```

**UID00053G `RECONSTRUCTION_H CODE`:** blank; the virtual declaration is owned by UID0000CN.

**UID00053H `by-memory/0x0055f840-0x0055f845.ScrollSpellInventoryPaneHandleKeyOrTextEvent.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
bool ScrollSpellInventoryPane::HandleKeyOrTextEvent(Event *)
{
    return false;
}
```

**UID00053H `RECONSTRUCTION_H CODE`:** blank; the virtual declaration is owned by UID0000CN.

**UID00053I `by-memory/0x0055f850-0x0055f883.ScrollSpellInventoryPaneOnTimer.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
bool ScrollSpellInventoryPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0 && m_activePart != kScrollSpellInventoryPartNone) {
        UpdateDragScroll();
        ScheduleTimer(0, 30, 0, 0);
    }
    return true;
}
```

**UID00053I `RECONSTRUCTION_H CODE`:** blank; the virtual declaration is owned by UID0000CN.

**UID00053J `by-memory/0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::OnPaint()
{
    EPFTileContext tile;
    RectBounds clipRect;
    RectBounds partRect;
    RectBounds drawRect;
    RectBounds stripRect;

    tile.Initialize();
    GetClipRect(&clipRect);
    if (!CanScroll()) {
        return;
    }

    const bool horizontal = (m_orientation != 0);
    for (int pass = 0; pass < 2; ++pass) {
        const ScrollSpellInventoryPart part = pass == 0
            ? kScrollSpellInventoryPartPageBeforeThumb
            : kScrollSpellInventoryPartPageAfterThumb;
        GetPartRect(part, &partRect);
        if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
            continue;
        }

        SetDrawColor(0);
        g_pfnFillRect(this, &drawRect);
        SetDrawColor(128);

        const int fillFrame = horizontal ? 4 : 1;
        const int capFrame = horizontal
            ? (pass == 0 ? 3 : 5)
            : (pass == 0 ? 0 : 2);
        g_pEPFLib->LookupLayoutEntry(L"SLIDEBG.EPF", fillFrame, &tile);

        stripRect = drawRect;
        if (horizontal) {
            stripRect.right = stripRect.left + 1;
            while (stripRect.left < drawRect.right) {
                RenderTileFrame(&tile, &tile.bounds, &stripRect,
                                1, L"SLIDEBG.PAL", 0);
                OffsetRect(&stripRect, 1, 0);
            }
        } else {
            stripRect.bottom = stripRect.top + 1;
            while (stripRect.top < drawRect.bottom) {
                RenderTileFrame(&tile, &tile.bounds, &stripRect,
                                1, L"SLIDEBG.PAL", 0);
                OffsetRect(&stripRect, 0, 1);
            }
        }

        g_pEPFLib->LookupLayoutEntry(L"SLIDEBG.EPF", capFrame, &tile);
        RenderTileFrame(&tile, &tile.bounds, &drawRect,
                        1, L"SLIDEBG.PAL", 0);
    }

    GetPartRect(kScrollSpellInventoryPartThumb, &partRect);
    if (IntersectRects(&drawRect, &partRect, &clipRect)) {
        SetDrawColor(0);
        g_pfnFillRect(this, &drawRect);
        SetDrawColor(128);
        g_pEPFLib->LookupLayoutEntry(
            L"SCRBUTT.EPF",
            m_hoverPart == kScrollSpellInventoryPartThumb ? 1 : 0,
            &tile);
        RenderTileFrame(&tile, &tile.bounds, &drawRect,
                        1, L"BUTTON.PAL", 0);
    }
}
```

**UID00053J `RECONSTRUCTION_H CODE`:** blank; the virtual declaration is owned by UID0000CN.

**UID00053K `by-memory/0x0055ff70-0x0056028d.ScrollSpellInventoryPaneHitTestPart.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
ScrollSpellInventoryPart ScrollSpellInventoryPane::HitTestPart(int localY,
                                                               int localX)
{
    for (int value = kScrollSpellInventoryPartLeading;
         value <= kScrollSpellInventoryPartTrailing;
         ++value) {
        const ScrollSpellInventoryPart part =
            static_cast<ScrollSpellInventoryPart>(value);
        Point cursor;
        Point origin;
        RectBounds rect;

        g_pEventMan->GetCursorPosition(&cursor);
        GetScreenOffset(&origin);
        if (origin.x == -1000 && origin.y == -1000) {
            InitRectBounds(&rect, 0, 0, 0, 0);
        } else {
            cursor.x -= origin.x;
            cursor.y -= origin.y;
            rect = m_visibleBounds;

            if (m_orientation == 0) {
                const int thumbSpan = kScrollPanePartExtentBySkin[m_sizeIndex];
                if (part == kScrollSpellInventoryPartLeading) {
                    rect.bottom = rect.top;
                } else if (part == kScrollSpellInventoryPartTrailing) {
                    rect.top = rect.bottom;
                } else if (m_enabled && m_scrollRange > 0) {
                    const int trackTop = m_visibleBounds.top;
                    const int thumbLimit = m_visibleBounds.bottom - thumbSpan;
                    int thumbTop;
                    if (m_thumbDragActive) {
                        thumbTop = m_visibleBounds.top + cursor.y -
                                   m_thumbDragOffset.y;
                        if (thumbTop < trackTop) {
                            thumbTop = trackTop;
                        }
                        if (thumbTop > thumbLimit) {
                            thumbTop = thumbLimit;
                        }
                    } else {
                        thumbTop = trackTop +
                            ((thumbLimit - trackTop) * m_scrollPosition) /
                                m_scrollRange;
                    }
                    const int thumbBottom = thumbTop + thumbSpan;
                    if (part == kScrollSpellInventoryPartThumb) {
                        rect.top = thumbTop;
                        rect.bottom = thumbBottom;
                    } else if (part == kScrollSpellInventoryPartPageBeforeThumb) {
                        rect.bottom = thumbTop;
                    } else if (part == kScrollSpellInventoryPartPageAfterThumb) {
                        rect.top = thumbBottom;
                    }
                } else if (part == kScrollSpellInventoryPartThumb) {
                    rect.top += thumbSpan;
                    rect.bottom -= thumbSpan;
                } else {
                    InitRectBounds(&rect, 0, 0, 0, 0);
                }
            } else {
                const int thumbSpan =
                    m_visibleBounds.bottom - m_visibleBounds.top;
                if (part == kScrollSpellInventoryPartLeading) {
                    rect.right = rect.left;
                } else if (part == kScrollSpellInventoryPartTrailing) {
                    rect.left = rect.right;
                } else if (m_enabled && m_scrollRange > 0) {
                    const int trackLeft = m_visibleBounds.left;
                    const int thumbLimit = m_visibleBounds.right - thumbSpan;
                    const int thumbLeft = trackLeft +
                        ((thumbLimit - trackLeft) * m_scrollPosition) /
                            m_scrollRange;
                    const int thumbRight = thumbLeft + thumbSpan;
                    if (part == kScrollSpellInventoryPartThumb) {
                        rect.left = thumbLeft;
                        rect.right = thumbRight;
                    } else if (part == kScrollSpellInventoryPartPageBeforeThumb) {
                        rect.right = thumbLeft;
                    } else if (part == kScrollSpellInventoryPartPageAfterThumb) {
                        rect.left = thumbRight;
                    }
                } else if (part == kScrollSpellInventoryPartThumb) {
                    rect.left += thumbSpan;
                    rect.right -= thumbSpan;
                } else {
                    InitRectBounds(&rect, 0, 0, 0, 0);
                }
            }
        }
        if (PointInRect(localY, localX, &rect)) {
            return part;
        }
    }
    return kScrollSpellInventoryPartNone;
}
```

**UID00053K `RECONSTRUCTION_H CODE`:** blank; the private declaration is owned by UID0000CN.

**UID00053L `by-memory/0x00560290-0x00560517.ScrollSpellInventoryPaneGetPartRect.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::GetPartRect(ScrollSpellInventoryPart part,
                                           RectBounds *bounds)
{
    Point cursor;
    Point origin;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.x == -1000 && origin.y == -1000) {
        return;
    }
    cursor.x -= origin.x;
    cursor.y -= origin.y;

    *bounds = m_visibleBounds;
    const bool horizontal = (m_orientation != 0);
    const int thumbSpan = horizontal
        ? m_visibleBounds.bottom - m_visibleBounds.top
        : kScrollPanePartExtentBySkin[m_sizeIndex];

    if (part == kScrollSpellInventoryPartLeading) {
        if (horizontal) {
            bounds->right = bounds->left;
        } else {
            bounds->bottom = bounds->top;
        }
        return;
    }
    if (part == kScrollSpellInventoryPartTrailing) {
        if (horizontal) {
            bounds->left = bounds->right;
        } else {
            bounds->top = bounds->bottom;
        }
        return;
    }

    if (!CanScroll()) {
        if (part == kScrollSpellInventoryPartThumb) {
            if (horizontal) {
                bounds->left += thumbSpan;
                bounds->right -= thumbSpan;
            } else {
                bounds->top += thumbSpan;
                bounds->bottom -= thumbSpan;
            }
        } else {
            InitRectBounds(bounds, 0, 0, 0, 0);
        }
        return;
    }

    if (horizontal) {
        const int trackStart = m_visibleBounds.left;
        const int thumbLimit = m_visibleBounds.right - thumbSpan;
        const int thumbStart = trackStart +
            (m_scrollPosition * (thumbLimit - trackStart)) / m_scrollRange;
        const int thumbEnd = thumbStart + thumbSpan;
        if (part == kScrollSpellInventoryPartThumb) {
            bounds->left = thumbStart;
            bounds->right = thumbEnd;
        } else if (part == kScrollSpellInventoryPartPageBeforeThumb) {
            bounds->right = thumbStart;
        } else if (part == kScrollSpellInventoryPartPageAfterThumb) {
            bounds->left = thumbEnd;
        }
    } else {
        const int trackStart = m_visibleBounds.top;
        const int thumbLimit = m_visibleBounds.bottom - thumbSpan;
        int thumbStart;
        if (m_thumbDragActive) {
            thumbStart = m_visibleBounds.top + cursor.y - m_thumbDragOffset.y;
            if (thumbStart < trackStart) {
                thumbStart = trackStart;
            }
            if (thumbStart > thumbLimit) {
                thumbStart = thumbLimit;
            }
        } else {
            thumbStart = trackStart +
                (m_scrollPosition * (thumbLimit - trackStart)) / m_scrollRange;
        }
        const int thumbEnd = thumbStart + thumbSpan;
        if (part == kScrollSpellInventoryPartThumb) {
            bounds->top = thumbStart;
            bounds->bottom = thumbEnd;
        } else if (part == kScrollSpellInventoryPartPageBeforeThumb) {
            bounds->bottom = thumbStart;
        } else if (part == kScrollSpellInventoryPartPageAfterThumb) {
            bounds->top = thumbEnd;
        }
    }
}
```

**UID00053L `RECONSTRUCTION_H CODE`:** blank; the private declaration is owned by UID0000CN.

**UID00053M `by-memory/0x00560520-0x00560590.ScrollSpellInventoryPaneSetHoverPartRaw.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::SetHoverPart(ScrollSpellInventoryPart part)
{
    RectBounds rect;
    const ScrollSpellInventoryPart oldPart =
        static_cast<ScrollSpellInventoryPart>(m_hoverPart);
    if (oldPart == part) {
        return;
    }
    if (oldPart != kScrollSpellInventoryPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }
    if (part != kScrollSpellInventoryPartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }
    m_hoverPart = static_cast<signed char>(part);
}
```

**UID00053M `RECONSTRUCTION_H CODE`:** blank; the private declaration is owned by UID0000CN.

**UID00053N `by-memory/0x00560590-0x0056064f.ScrollSpellInventoryPaneBeginInteractionRaw.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::BeginInteraction(ScrollSpellInventoryPart part,
                                                int mouseY,
                                                int mouseX)
{
    RectBounds rect;
    if (part == kScrollSpellInventoryPartThumb) {
        if (m_hoverPart != kScrollSpellInventoryPartThumb) {
            if (m_hoverPart != kScrollSpellInventoryPartNone) {
                GetPartRect(
                    static_cast<ScrollSpellInventoryPart>(m_hoverPart),
                    &rect);
                InvalidateRect(&rect);
            }
            GetPartRect(kScrollSpellInventoryPartThumb, &rect);
            InvalidateRect(&rect);
            m_hoverPart = kScrollSpellInventoryPartThumb;
        }
        GetPartRect(kScrollSpellInventoryPartThumb, &rect);
        InitPointPair(&m_thumbDragOffset,
                      mouseY - rect.top,
                      mouseX - rect.left);
    }
    m_activePart = static_cast<signed char>(part);
    UpdateDragScroll();
    ScheduleTimer(0, 200, 0, 0);
}
```

**UID00053N `RECONSTRUCTION_H CODE`:** blank; the private declaration is owned by UID0000CN.

**UID00053O `by-memory/0x00560650-0x00560710.ScrollSpellInventoryPaneUpdateDragScroll.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::UpdateDragScroll()
{
    Point cursor;
    Point origin;
    RectBounds rect;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y == -1000 && origin.x == -1000) {
        return;
    }

    const int localY = cursor.y - origin.y;
    const int localX = cursor.x - origin.x;
    const ScrollSpellInventoryPart activePart =
        static_cast<ScrollSpellInventoryPart>(m_activePart);
    if (activePart == kScrollSpellInventoryPartThumb) {
        UpdateFromDrag(localY, localX);
        return;
    }

    if (HitTestPart(localY, localX) == activePart) {
        UpdateFromDrag(localY, localX);
    }

    const ScrollSpellInventoryPart hoverPart =
        static_cast<ScrollSpellInventoryPart>(m_hoverPart);
    if (hoverPart != kScrollSpellInventoryPartNone) {
        GetPartRect(hoverPart, &rect);
        InvalidateRect(&rect);
        m_hoverPart = kScrollSpellInventoryPartNone;
    }
}
```

**UID00053O `RECONSTRUCTION_H CODE`:** blank; the private declaration is owned by UID0000CN.

**UID0001GN `by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::UpdateFromDrag(int localY, int localX)
{
    Point cursor;
    Point origin;
    RectBounds thumbRect;
    RectBounds leadingRect;
    RectBounds trailingRect;
    const short oldPosition = m_scrollPosition;
    short newPosition;
    GetPartRect(kScrollSpellInventoryPartThumb, &thumbRect);

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        leadingRect = m_visibleBounds;
        if (m_orientation != 0) {
            leadingRect.right = leadingRect.left;
        } else {
            leadingRect.bottom = leadingRect.top;
        }
    }

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        trailingRect = m_visibleBounds;
        if (m_orientation != 0) {
            trailingRect.left = trailingRect.right;
        } else {
            trailingRect.top = trailingRect.bottom;
        }
    }

    if (m_orientation != 0) {
        int thumbStart = localX - m_thumbDragOffset.x + 1;
        if (thumbStart < leadingRect.right) {
            thumbStart = leadingRect.right;
        }
        const int maxThumbStart =
            trailingRect.left + thumbRect.left - thumbRect.right;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        const int trackSpan =
            trailingRect.left + thumbRect.left -
            thumbRect.right - leadingRect.right;
        newPosition = static_cast<short>(
            (m_scrollRange * (thumbStart - leadingRect.right)) / trackSpan);
    } else {
        int thumbStart = localY - m_thumbDragOffset.y + 1;
        if (thumbStart < leadingRect.bottom) {
            thumbStart = leadingRect.bottom;
        }
        const int maxThumbStart =
            trailingRect.top + thumbRect.top - thumbRect.bottom;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        const int trackSpan =
            trailingRect.top + thumbRect.top -
            thumbRect.bottom - leadingRect.bottom;
        newPosition = static_cast<short>(
            ((m_scrollRange + 1) *
             (thumbStart - leadingRect.bottom)) / trackSpan);

        if (newPosition > m_scrollRange) {
            newPosition = m_scrollRange;
        }
    }

    if (oldPosition != newPosition) {
        static_cast<NewSpellInventoryPane *>(GetParentPane())
            ->OnScrollPositionChanged(m_orientation,
                                      oldPosition,
                                      newPosition);
    }
}
```

**UID0001GN `RECONSTRUCTION_H CODE`:** blank; the private declaration is owned by UID0000CN.

**UID0001GO `by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md` `RECONSTRUCTION_CPP CODE`:**

```cpp
void ScrollSpellInventoryPane::ResetScrollState()
{
    RectBounds rect;
    RemovePendingTimers();
    const ScrollSpellInventoryPart oldPart =
        static_cast<ScrollSpellInventoryPart>(m_hoverPart);
    m_activePart = kScrollSpellInventoryPartNone;
    if (oldPart != kScrollSpellInventoryPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_hoverPart = kScrollSpellInventoryPartNone;
    }
}
```

**UID0001GO `RECONSTRUCTION_H CODE`:** blank; the private declaration is owned by UID0000CN.

**UID0000CN `RECONSTRUCTION_H CODE` declaration channel, emitted through UID0000NJ:**

```cpp
#ifndef NEXUSTK_UI_INVENTORY_SCROLLSPELLINVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_SCROLLSPELLINVENTORYPANE_H

#include "../core/Pane.h"

class Event;
class NewSpellInventoryPane;

enum ScrollSpellInventoryPart {
    kScrollSpellInventoryPartLeading = 0,
    kScrollSpellInventoryPartPageBeforeThumb = 1,
    kScrollSpellInventoryPartThumb = 2,
    kScrollSpellInventoryPartPageAfterThumb = 3,
    kScrollSpellInventoryPartTrailing = 4,
    kScrollSpellInventoryPartNone = -1
};

class ScrollSpellInventoryPane : public Pane
{
public:
    explicit ScrollSpellInventoryPane(unsigned char orientation);

    void SetSizeIndex(unsigned short sizeIndex);
    void SetScrollStyle(unsigned char scrollStyle);
    void SetMaxRange(short maxRange);
    void SetScrollPosition(short position);
    void Activate();
    void Deactivate();
    bool CanScroll() const;

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    friend class NewSpellInventoryPane;

    ScrollSpellInventoryPart HitTestPart(int localY, int localX);
    void GetPartRect(ScrollSpellInventoryPart part, RectBounds *bounds);
    void SetHoverPart(ScrollSpellInventoryPart part);
    void BeginInteraction(ScrollSpellInventoryPart part,
                          int mouseY,
                          int mouseX);
    void UpdateDragScroll();
    void UpdateFromDrag(int localY, int localX);
    void ResetScrollState();

    unsigned short m_sizeIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_enabled;
    signed char m_hoverPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

typedef char ScrollSpellInventoryPaneSizeMustBe272[
    sizeof(ScrollSpellInventoryPane) == 0x110 ? 1 : -1];

#endif
```

Formal channel inventory: UID0000CN owns the exact include plus `[[CHILDREN]]` CPP preamble and the complete H declaration. UIDs 000538..00053O plus 0001GN/0001GO each own the exact individually labeled CPP definition above and an explicitly blank H channel because their declarations are present in UID0000CN H. UID0001GM (aggregate/index), UID0001W1 (layout evidence), UID0001YS (semantic vtable/RTTI evidence), and UID0003CM (literal compiler data) are supported compiler/no-code dispositions with blank formal CPP and blank formal H; emitting any of them would duplicate authored source or serialize compiler products. UID0000NJ is the source root/assembly owner and does not duplicate child source. The source intentionally contains no literal vtable, RTTI, padding, raw byte array, or compiler wrapper.

## Final Recommendation

The standalone whole-file ordinary reconstruction is applied and validated at report depth. All seventeen missing exact children were validator-created, the two existing children were corrected/preserved, the complete source/header is installed, false aggregate/compiler emitters are removed, every changed ordinary page passed scoped validation, and generated `.cpp/.h` passed exhaustive physical comparison. The supervisor-provided manual-coverage cycle passed as dated external evidence. Supervisor-owned IDA work remains externally gated and now has deterministic I10 and I13 contracts: I10 authorizes only its observed typed event-row addition, while I13 preserves `row`/`column` through function typing and uses explicit non-pure occupied-row renames to reach `localY`/`localX`.

## Recommended Target Doc Changes

UID0000NJ now contains all nineteen ranges/hashes, sixteen gaps, clone proof, ownership/caller/callee/dependency/exclusion inventory, the selected standalone source path, rejected historical NewSpell fold, `90/92` metadata, exact positions 10..190, and historicalized generated defects. UID0000CN is now `89/91`, retains owner/emitter UID0000NJ at position 10, emits the complete include/children CPP preamble and H declaration, uses no-argument `UpdateDragScroll()`, and preserves NewSpell friendship, enum, `0x110` size guard, fields, virtual surface, and compiler consequences. The seventeen validator-assigned additional targets are not represented by this root paragraph alone: each has its own C-NJ-011..C-NJ-027 twin, exact Section 22 owning-channel payload, and the literal per-UID support/change plan immediately below.

## Recommended Support Doc Changes

- UID0001GM now has exact complete inventory/padding/hash/clone/exclusion evidence and is `91/93`, `RECONSTRUCTABLE:FALSE`, with no emitter and blank formals.
- Validator-assigned method-child dispositions are independently complete rather than aggregate-only:

| UID / exact page | Applied target-specific plan | Formal channel and metadata disposition |
| --- | --- | --- |
| 000538 `0x0055f450-0x0055f4f1.ScrollSpellInventoryPaneConstructor.md` | Preserve constructor bytes/hash/caller/object/vtable/init evidence and I01 frame distinction. | UID0000CN owner/emitter, position 10, 93/95; exact constructor CPP in Section 22; H blank under parent declaration. |
| 000539 `0x0055f500-0x0055f527.ScrollSpellInventoryPaneSetSizeIndexRaw.md` | Preserve raw clone/no-xref and changed-only size/invalidation behavior. | UID0000CN owner/emitter, position 20, 89/91; exact CPP; H blank under parent declaration. |
| 00053A `0x0055f530-0x0055f554.ScrollSpellInventoryPaneSetScrollStyleRaw.md` | Preserve raw clone/no-xref and changed-only style/invalidation behavior. | UID0000CN owner/emitter, position 30, 89/91; exact CPP; H blank under parent declaration. |
| 00053B `0x0055f560-0x0055f5bb.ScrollSpellInventoryPaneSetMaxRange.md` | Preserve signed 0..30000 clamp, position clamp and two-stage invalidation. | UID0000CN owner/emitter, position 40, 93/95; exact CPP; H blank under parent declaration. |
| 00053C `0x0055f5c0-0x0055f5e7.ScrollSpellInventoryPaneSetScrollPosition.md` | Preserve changed-only signed-position store and invalidation. | UID0000CN owner/emitter, position 50, 93/95; exact CPP; H blank under parent declaration. |
| 00053D `0x0055f5f0-0x0055f60a.ScrollSpellInventoryPaneActivate.md` | Preserve transition-only enable and invalidation. | UID0000CN owner/emitter, position 60, 90/92; exact CPP; H blank under parent declaration. |
| 00053E `0x0055f610-0x0055f62a.ScrollSpellInventoryPaneDeactivateRaw.md` | Preserve raw clone and transition-only disable/invalidation. | UID0000CN owner/emitter, position 70, 89/91; exact CPP; H blank under parent declaration. |
| 00053F `0x0055f630-0x0055f64a.ScrollSpellInventoryPaneCanScrollRaw.md` | Preserve raw clone and enabled-plus-positive-signed-range predicate. | UID0000CN owner/emitter, position 80, 92/94; exact CPP; H blank under parent declaration. |
| 00053G `0x0055f650-0x0055f831.ScrollSpellInventoryPaneHandlePointerOrMouseEvent.md` | Preserve exact event/capture/timer/state/invalidation control flow and vtable route. | UID0000CN owner/emitter, position 90, 90/92; exact CPP; H blank under parent virtual declaration. |
| 00053H `0x0055f840-0x0055f845.ScrollSpellInventoryPaneHandleKeyOrTextEvent.md` | Preserve exact false-return virtual body and slot evidence. | UID0000CN owner/emitter, position 100, 93/95; exact CPP; H blank under parent virtual declaration. |
| 00053I `0x0055f850-0x0055f883.ScrollSpellInventoryPaneOnTimer.md` | Preserve timer-ID gate, active update and true return. | UID0000CN owner/emitter, position 110, 93/95; exact CPP; H blank under parent virtual declaration. |
| 00053J `0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md` | Preserve exact orientation/page/cap/thumb drawing and EPF/PAL dependency behavior. | UID0000CN owner/emitter, position 120, 90/92; exact CPP; H blank under parent virtual declaration. |
| 00053K `0x0055ff70-0x0056028d.ScrollSpellInventoryPaneHitTestPart.md` | Preserve exact five-part hit-test geometry/order; IDA handoff preserves physical `row`/`column` through function typing and renames those occupied rows separately to `localY`/`localX`. | UID0000CN owner/emitter, position 130, 90/92; exact CPP; H blank under parent private declaration. |
| 00053L `0x00560290-0x00560517.ScrollSpellInventoryPaneGetPartRect.md` | Preserve exact orientation/range/drag-dependent rectangle formulas. | UID0000CN owner/emitter, position 140, 90/92; exact CPP; H blank under parent private declaration. |
| 00053M `0x00560520-0x00560590.ScrollSpellInventoryPaneSetHoverPartRaw.md` | Preserve raw clone, old/new-part invalidation and signed hover state. | UID0000CN owner/emitter, position 150, 91/93; exact CPP; H blank under parent private declaration. |
| 00053N `0x00560590-0x0056064f.ScrollSpellInventoryPaneBeginInteractionRaw.md` | Preserve raw clone, thumb/page interaction, immediate update and repeat timer. | UID0000CN owner/emitter, position 160, 91/93; exact CPP; H blank under parent private declaration. |
| 00053O `0x00560650-0x00560710.ScrollSpellInventoryPaneUpdateDragScroll.md` | Preserve no-argument cursor route, active update and hover cleanup. | UID0000CN owner/emitter, position 170, 90/92; exact CPP; H blank under parent private declaration. |
- UID0001GN uses `m_visibleBounds`, retains exact formulas/callback evidence, and is `91/93` at source position 180.
- UID0001GO preserves exact raw/no-route evidence and the enum-shaped body at `93/94`, source position 190.
- UID0001W1 is `93/95`, UID0001YS is `94/95`, and UID0003CM is `94/96`; all are nonreconstructable/no-emitter/blank-formal evidence with historical detail retained.
- UID00026D already related the spell vtable subset to UID0003CM and required no edit.
- UID0000LU/UID00009A already preserve source ownership, callback, child pointer, friendship, complete H, and standalone companion relationship; no edit was required.
- UID0000NF/UID0003CQ already preserve the spell consumer xrefs and sole extent-table ownership; no edit was required.

## Score And Metadata Recommendation

| UID/item | Assignment-time | Applied/current ordinary state | Metadata/source disposition |
| --- | --- | --- | --- |
| 0000NJ file | 86/88 | 90/92 applied | reconstructable true; standalone source root |
| 0000CN class | 86/88 | 89/91 applied | owner/emitter 0000NJ; position 10; CPP preamble + full H |
| 0001GM aggregate | 86/88 | 91/93 applied | reconstructable false; no emitter; blank CPP/H |
| 000538 constructor child | absent | 93/95 applied | UID0000CN owner/emitter; exact CPP position 10; H blank under parent declaration |
| 000539 SetSizeIndex child | absent | 89/91 applied | UID0000CN owner/emitter; exact CPP position 20; H blank under parent declaration |
| 00053A SetScrollStyle child | absent | 89/91 applied | UID0000CN owner/emitter; exact CPP position 30; H blank under parent declaration |
| 00053B SetMaxRange child | absent | 93/95 applied | UID0000CN owner/emitter; exact CPP position 40; H blank under parent declaration |
| 00053C SetScrollPosition child | absent | 93/95 applied | UID0000CN owner/emitter; exact CPP position 50; H blank under parent declaration |
| 00053D Activate child | absent | 90/92 applied | UID0000CN owner/emitter; exact CPP position 60; H blank under parent declaration |
| 00053E Deactivate child | absent | 89/91 applied | UID0000CN owner/emitter; exact CPP position 70; H blank under parent declaration |
| 00053F CanScroll child | absent | 92/94 applied | UID0000CN owner/emitter; exact CPP position 80; H blank under parent declaration |
| 00053G mouse child | absent | 90/92 applied | UID0000CN owner/emitter; exact CPP position 90; H blank under parent virtual declaration |
| 00053H key child | absent | 93/95 applied | UID0000CN owner/emitter; exact CPP position 100; H blank under parent virtual declaration |
| 00053I timer child | absent | 93/95 applied | UID0000CN owner/emitter; exact CPP position 110; H blank under parent virtual declaration |
| 00053J paint child | absent | 90/92 applied | UID0000CN owner/emitter; exact CPP position 120; H blank under parent virtual declaration |
| 00053K hit-test child | absent | 90/92 applied | UID0000CN owner/emitter; exact CPP position 130; H blank under parent private declaration |
| 00053L part-rect child | absent | 90/92 applied | UID0000CN owner/emitter; exact CPP position 140; H blank under parent private declaration |
| 00053M hover child | absent | 91/93 applied | UID0000CN owner/emitter; exact CPP position 150; H blank under parent private declaration |
| 00053N interaction child | absent | 91/93 applied | UID0000CN owner/emitter; exact CPP position 160; H blank under parent private declaration |
| 00053O drag-scroll child | absent | 90/92 applied | UID0000CN owner/emitter; exact no-argument CPP position 170; H blank under parent private declaration |
| 0001GN | 90/92 | 91/93 applied | class owner/emitter; CPP 180; H blank |
| 0001GO | 87/89 | 93/94 applied | class owner/emitter; CPP 190; H blank |
| 0001W1 | 85/88 | 93/95 applied | nonreconstructable/no emitter/blank formals |
| 0001YS | 85/90 | 94/95 applied | nonreconstructable/no emitter/blank formals |
| 0003CM | 86/90 | 94/96 applied | nonreconstructable/no emitter/blank formals |

No code-emitting row is recommended above 95. The I10 and I13 frame corrections change no score: they confirm the accepted source signatures while making the Gate 2B contracts match public endpoint behavior, including I13's separate physical stack-name step. The remaining caps are exact original private spellings, original header guard/file capitalization, and lack of original source/debug symbols, not unresolved runtime behavior.

## Open Questions With Attempted Resolution

| Question | Investigation | Resolution |
| --- | --- | --- |
| Standalone or folded? | Compared full island, class/vtables, consumer route and sibling file convention. | Closed: standalone file/header. |
| What are the seven raw starts? | Exact bytes, boundaries, heads, no-xrefs, and sibling methods compared. | Closed: SetSizeIndex, SetScrollStyle, Deactivate, CanScroll, SetHoverPart, BeginInteraction, ResetScrollState. |
| Is a destructor missing? | Closed range, wrappers, sibling source, successor checked. | Closed: no authored destructor; compiler deleting wrapper only. |
| What is UpdateDragScroll's signature? | Body, current type, callers and sibling source checked. | Closed: no explicit arguments. |
| What is I10's physical frame contract? | Supervisor tested the exact public type endpoint, read the immediate and post-type frames, stopped on the old contradiction, discarded the dirty worker and verified rollback. | Closed: return-address row only before type; add exactly `event@0x4/4:Event *` after type; no other frame delta. |
| How are I13 source argument names installed? | Supervisor tested function typing, read the complete unchanged `row`/`column` post-frame, checked the public occupied-row rename schema, stopped without comments/save, discarded the worker and verified rollback. | Closed: function `set_type` does not rename physical rows; dry-run then apply the exact non-pure two-entry `rename.batch.stack`, yielding only `localY`/`localX` name deltas. |
| Which bounds field is correct? | Pane/GrafPort H and binary offset checked. | Closed: inherited `m_visibleBounds`. |
| Who owns shared table/resources? | Names/types/comments/xrefs and support docs checked. | Closed: ScrollBar/render dependencies; no duplicate ownership. |
| Should vtables/layout emit comments? | by-structure source ownership and compiler consequences checked. | Closed: blank formal channels; class declaration generates compiler products. |
| Are exact private names original? | Symbol searches and subsystem conventions checked. | Best high-probability names selected; unavoidable historical spelling uncertainty only. |
| Can all scores rise? | Every assignment-time blocker was investigated and source closure supplied. | Yes after implementation/validation; caps remain below 95 where appropriate. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current row identities were reread before report writing. Manual coverage files are supervisor-only; B003 must not edit them. The snapshots below are dated and later line numbers/hashes are dynamic.

Replace UID0000NJ in `by-file/-coverage-report.md` with:

> - [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) : reconstructable : 90% : very-strong : Standalone spell-inventory scrollbar source root with exact 19-method/16-padding inventory, 0x110 class/header, three compiler vtable facets, complete parent/dependency/source-order routing, full CPP/H reconstruction and generated-output closure; NewSpellInventoryPane remains consumer/callback parent rather than file owner.

Replace UID0000CN in `by-class/-coverage-report.md` with:

> - [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) : reconstructable : 89% : very-strong : Exact 0x110 ScrollSpellInventoryPane declaration and nineteen-method implementation with EventHandler/TimerHandler virtual surfaces, spell-owner callback, range/drag/paint geometry, exact fields/enum, compiler-vtable consequences, complete CPP/H routing and no-argument UpdateDragScroll contract.

Replace UID0001GM, UID0001GN and UID0001GO in `by-memory/-coverage-report.md` with:

>     - [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) 0x0055f450-0x005608fc | class aggregate | ScrollSpellInventoryPane : not-reconstructable : 91% : very-strong : Marker-only aggregate indexes nineteen exact source methods, sixteen CC alignment spans, complete range/hash/clone/ownership/order and compiler exclusions; all authored bodies emit from exact class-owned children.
>
>     - [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) 0x00560710-0x0056089d | method | ScrollSpellInventoryPaneUpdateFromDrag : reconstructable : 91% : very-strong : Exact UpdateFromDrag(int localY, int localX) geometry and NewSpell owner callback with 397-byte hash, two callers, inherited m_visibleBounds, Y/X drag offset, horizontal/vertical formulas, class/file route and source position 180.
>
>     - [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) 0x005608a0-0x005608fc | raw retained method | ScrollSpellInventoryPaneResetScrollState : reconstructable : 93% : very-strong : Exact retained ResetScrollState removes timers, clears active/hover state and invalidates the old part; exact raw body/hash/no-route/padding evidence, class/file ownership, formal CPP and source position 190 documented.

Insert UID0003CM in `by-memory/-coverage-report.md` near UID0001YS/UID0001GM support rows:

>     - [UID:0003CM][0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData](by-memory/0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData.md) 0x00623e90-0x00623f18 | compiler vtable data | ScrollSpellInventoryPaneVtableData : not-reconstructable : 94% : very-strong : Exact primary, EventHandler and TimerHandler vtable facets with COL prefixes, decorated names, slot targets, constructor stores, xrefs, shared deleting/adjustor wrappers and compiler-generated no-code disposition.

Replace UID0001W1 in `by-type/by-struct/-coverage-report.md` with:

> - [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md) : not-reconstructable : 93% : very-strong : Exact 0x110 ScrollSpellInventoryPane physical layout with Pane base, size/style/drag/orientation/range/position/enabled/hover/active fields and Point offset; normal UID0000CN header owns the declaration, so this evidence page emits no duplicate source.

Replace UID0001YS in `by-type/by-vtable/-coverage-report.md` with:

> - [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md) : not-reconstructable : 94% : very-strong : Exact primary/EventHandler/TimerHandler vtable semantics, decorated identities, slots, constructor stores, COL/RTTI objects and shared deleting/adjustor wrappers; normal class declaration regenerates all compiler products and this page emits no literal arrays.

For the seventeen validator-created method pages, insert the following complete literal rows in `by-memory/-coverage-report.md` immediately after the four-space-indented UID0001GM `0x0055f450-0x005608fc.ScrollSpellInventoryPane` row and immediately before the four-space-indented UID0001GN `0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag` row. Preserve the four leading spaces on every line and insert the rows in this exact source order:

>     - [UID:000538][0x0055f450-0x0055f4f1.ScrollSpellInventoryPaneConstructor](by-memory/0x0055f450-0x0055f4f1.ScrollSpellInventoryPaneConstructor.md) 0x0055f450-0x0055f4f1 | constructor | ScrollSpellInventoryPane::ScrollSpellInventoryPane : reconstructable : 93% : very-strong : Exact 0x110-byte ScrollSpellInventoryPane constructor with primary, EventHandler and TimerHandler vtable stores, zero/default field initialization, one NewSpellInventoryPane caller, exact 161-byte body/hash, trailing alignment, UID0000CN/UID0000NJ ownership, formal CPP and source position 10.
>
>     - [UID:000539][0x0055f500-0x0055f527.ScrollSpellInventoryPaneSetSizeIndexRaw](by-memory/0x0055f500-0x0055f527.ScrollSpellInventoryPaneSetSizeIndexRaw.md) 0x0055f500-0x0055f527 | retained raw method | ScrollSpellInventoryPane::SetSizeIndex : reconstructable : 89% : strong : Exact changed-only 16-bit size-index setter with 39-byte raw body/hash, zero static xrefs, inherited m_visibleBounds invalidation, UID0000CN/UID0000NJ ownership, formal CPP and source position 20.
>
>     - [UID:00053A][0x0055f530-0x0055f554.ScrollSpellInventoryPaneSetScrollStyleRaw](by-memory/0x0055f530-0x0055f554.ScrollSpellInventoryPaneSetScrollStyleRaw.md) 0x0055f530-0x0055f554 | retained raw method | ScrollSpellInventoryPane::SetScrollStyle : reconstructable : 89% : strong : Exact changed-only 8-bit scroll-style setter with 36-byte raw body/hash, zero static xrefs, inherited m_visibleBounds invalidation, UID0000CN/UID0000NJ ownership, formal CPP and source position 30.
>
>     - [UID:00053B][0x0055f560-0x0055f5bb.ScrollSpellInventoryPaneSetMaxRange](by-memory/0x0055f560-0x0055f5bb.ScrollSpellInventoryPaneSetMaxRange.md) 0x0055f560-0x0055f5bb | method | ScrollSpellInventoryPane::SetMaxRange : reconstructable : 93% : very-strong : Exact signed 0..30000 range clamp with current-position correction, changed-only behavior, one/two invalidation paths, one caller, exact 91-byte body/hash, UID0000CN/UID0000NJ ownership, formal CPP and source position 40.
>
>     - [UID:00053C][0x0055f5c0-0x0055f5e7.ScrollSpellInventoryPaneSetScrollPosition](by-memory/0x0055f5c0-0x0055f5e7.ScrollSpellInventoryPaneSetScrollPosition.md) 0x0055f5c0-0x0055f5e7 | method | ScrollSpellInventoryPane::SetScrollPosition : reconstructable : 93% : very-strong : Exact changed-only signed scroll-position update with four callers, exact 39-byte body/hash, inherited m_visibleBounds invalidation, UID0000CN/UID0000NJ ownership, formal CPP and source position 50.
>
>     - [UID:00053D][0x0055f5f0-0x0055f60a.ScrollSpellInventoryPaneActivate](by-memory/0x0055f5f0-0x0055f60a.ScrollSpellInventoryPaneActivate.md) 0x0055f5f0-0x0055f60a | method | ScrollSpellInventoryPane::Activate : reconstructable : 90% : very-strong : Exact disabled-to-enabled transition-only activation and invalidation with one caller, exact 26-byte body/hash, UID0000CN/UID0000NJ ownership, formal CPP and source position 60.
>
>     - [UID:00053E][0x0055f610-0x0055f62a.ScrollSpellInventoryPaneDeactivateRaw](by-memory/0x0055f610-0x0055f62a.ScrollSpellInventoryPaneDeactivateRaw.md) 0x0055f610-0x0055f62a | retained raw method | ScrollSpellInventoryPane::Deactivate : reconstructable : 89% : strong : Exact enabled-to-disabled transition-only deactivation and invalidation with 26-byte raw body/hash, zero static xrefs, UID0000CN/UID0000NJ ownership, formal CPP and source position 70.
>
>     - [UID:00053F][0x0055f630-0x0055f64a.ScrollSpellInventoryPaneCanScrollRaw](by-memory/0x0055f630-0x0055f64a.ScrollSpellInventoryPaneCanScrollRaw.md) 0x0055f630-0x0055f64a | retained raw method | ScrollSpellInventoryPane::CanScroll : reconstructable : 92% : very-strong : Exact enabled-and-positive-signed-range predicate with 26-byte raw body/hash, zero static xrefs, UID0000CN/UID0000NJ ownership, formal CPP and source position 80.
>
>     - [UID:00053G][0x0055f650-0x0055f831.ScrollSpellInventoryPaneHandlePointerOrMouseEvent](by-memory/0x0055f650-0x0055f831.ScrollSpellInventoryPaneHandlePointerOrMouseEvent.md) 0x0055f650-0x0055f831 | method | ScrollSpellInventoryPane::HandlePointerOrMouseEvent : reconstructable : 90% : very-strong : Exact EventHandler cursor movement and left-button press/release handling with hit testing, capture, interaction state, timer cleanup and invalidation, exact 481-byte body/hash, vtable/callee evidence, UID0000CN/UID0000NJ ownership, formal CPP and source position 90.
>
>     - [UID:00053H][0x0055f840-0x0055f845.ScrollSpellInventoryPaneHandleKeyOrTextEvent](by-memory/0x0055f840-0x0055f845.ScrollSpellInventoryPaneHandleKeyOrTextEvent.md) 0x0055f840-0x0055f845 | method | ScrollSpellInventoryPane::HandleKeyOrTextEvent : reconstructable : 93% : very-strong : Exact five-byte false-return EventHandler override with sole vtable route and exact body/hash evidence, UID0000CN/UID0000NJ ownership, formal CPP and source position 100.
>
>     - [UID:00053I][0x0055f850-0x0055f883.ScrollSpellInventoryPaneOnTimer](by-memory/0x0055f850-0x0055f883.ScrollSpellInventoryPaneOnTimer.md) 0x0055f850-0x0055f883 | method | ScrollSpellInventoryPane::OnTimer : reconstructable : 93% : very-strong : Exact TimerHandler active-part repeat callback with 30 millisecond rescheduling and always-handled return, exact 51-byte body/hash and vtable evidence, UID0000CN/UID0000NJ ownership, formal CPP and source position 110.
>
>     - [UID:00053J][0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint](by-memory/0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md) 0x0055f890-0x0055ff70 | method | ScrollSpellInventoryPane::OnPaint : reconstructable : 90% : very-strong : Exact page, cap and thumb drawing with clipping, tile-context initialization, SLIDEBG.EPF/SLIDEBG.PAL and SCRBUTT.EPF/BUTTON.PAL resources, exact 1760-byte body/hash, vtable/callee evidence, UID0000CN/UID0000NJ ownership, formal CPP and source position 120.
>
>     - [UID:00053K][0x0055ff70-0x0056028d.ScrollSpellInventoryPaneHitTestPart](by-memory/0x0055ff70-0x0056028d.ScrollSpellInventoryPaneHitTestPart.md) 0x0055ff70-0x0056028d | method | ScrollSpellInventoryPane::HitTestPart : reconstructable : 90% : very-strong : Exact five-part orientation-, range-, hover-, active- and thumb-drag-sensitive hit test with two callers and exact 797-byte body/hash, UID0000CN/UID0000NJ ownership, formal CPP and source position 130.
>
>     - [UID:00053L][0x00560290-0x00560517.ScrollSpellInventoryPaneGetPartRect](by-memory/0x00560290-0x00560517.ScrollSpellInventoryPaneGetPartRect.md) 0x00560290-0x00560517 | method | ScrollSpellInventoryPane::GetPartRect : reconstructable : 90% : very-strong : Exact orientation-, range-, position- and drag-dependent five-part rectangle geometry with thirteen callers, exact 647-byte body/hash and frame evidence, UID0000CN/UID0000NJ ownership, formal CPP and source position 140.
>
>     - [UID:00053M][0x00560520-0x00560590.ScrollSpellInventoryPaneSetHoverPartRaw](by-memory/0x00560520-0x00560590.ScrollSpellInventoryPaneSetHoverPartRaw.md) 0x00560520-0x00560590 | retained raw method | ScrollSpellInventoryPane::SetHoverPart : reconstructable : 91% : very-strong : Exact old/new non-none part-rectangle invalidation and signed hover-part update with 112-byte raw body/hash and zero static xrefs, UID0000CN/UID0000NJ ownership, formal CPP and source position 150.
>
>     - [UID:00053N][0x00560590-0x0056064f.ScrollSpellInventoryPaneBeginInteractionRaw](by-memory/0x00560590-0x0056064f.ScrollSpellInventoryPaneBeginInteractionRaw.md) 0x00560590-0x0056064f | retained raw method | ScrollSpellInventoryPane::BeginInteraction : reconstructable : 91% : very-strong : Exact thumb-offset capture or page interaction, immediate active-part update and 200 millisecond repeat scheduling with 191-byte raw body/hash and zero static xrefs, UID0000CN/UID0000NJ ownership, formal CPP and source position 160.
>
>     - [UID:00053O][0x00560650-0x00560710.ScrollSpellInventoryPaneUpdateDragScroll](by-memory/0x00560650-0x00560710.ScrollSpellInventoryPaneUpdateDragScroll.md) 0x00560650-0x00560710 | method | ScrollSpellInventoryPane::UpdateDragScroll : reconstructable : 90% : very-strong : Exact no-argument cursor-driven active thumb/page update with local-coordinate conversion, hover cleanup and invalidation, three callers, exact 192-byte body/hash and frame evidence, UID0000CN/UID0000NJ ownership, formal CPP and source position 170.

## Follow-Up Actions

1. Ordinary callback C-NJ-001..051 and the ordinary/validator/generated portion of C-NJ-056 are applied and verified.
2. Exact-artifact Gate 1 and Gate 2A continuity is supervisor-owned and must be established against the report revision and destination hashes used for any dependent action.
3. The supervisor-provided manual-coverage cycle passed before the dated failed Gate 2B experiment; current manual-coverage authority remains external and must be read from supervisor audit/validator evidence rather than inferred from the agent-owned checklist allocation.
4. Any supervisor Gate 2B transaction must use the corrected fail-closed Section 21 contracts: fresh runtime attestation, literal sparse raw post-define/post-type frames, the I10 transition from return-only pre-type to exactly one typed `event` row after `set_type`, and I13's unchanged `row`/`column` post-type frame followed by exact non-pure stack-rename preflight/apply and final `localY`/`localX` frame. Any missing old row, collision, partial rename, or unlisted frame/protected-state delta requires rollback/no-save. All dated failed experiments were unsaved and left their canonical IDB backup-identical.
5. Report execution/archive state is supervisor-owned and authoritative only from the report's path and validator-owned status/history metadata.

## Confidence

- Applied completion: `90` for the file because the whole source unit, all children, and full CPP/H are resolved and validator-confirmed.
- Applied confidence: `92` because behavior, ranges, layout, ownership, and compiler products are exact while original private spellings and file capitalization remain inferred.
- Binary/behavior confidence: very high.
- Source placement/name confidence: high.
- The I10 endpoint contradiction is closed by its literal observed pre/post frame pair, and I13's naming contradiction is closed by separating function typing from explicit occupied-row renames; no unresolved question blocks ordinary implementation, the corrected IDA handoff, or manual coverage.

## Validator Results

All commands below ran from exact working directory `E:\NTK\GhidraBridge\source-3\project-documentation`. No lifecycle command or `execute_report` was run.

| Command ID / timestamp | Exact scoped command | Result, diagnostics, side effects, and generated state |
| --- | --- | --- |
| `000000024780` / `2026-08-16T04:59:38-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f450-0x0055f4f1.ScrollSpellInventoryPaneConstructor.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID000538, registered canonical/score/emitter/formal metadata and references; no errors; `stats_incremental_noop` because the new file was not in generated stats lists; generated refresh deferred. |
| `000000024781` / `2026-08-16T04:59:40-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f500-0x0055f527.ScrollSpellInventoryPaneSetSizeIndexRaw.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID000539 and registered canonical/score/emitter/formal metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024782` / `2026-08-16T04:59:43-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f530-0x0055f554.ScrollSpellInventoryPaneSetScrollStyleRaw.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053A and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024783` / `2026-08-16T04:59:45-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f560-0x0055f5bb.ScrollSpellInventoryPaneSetMaxRange.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053B and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024784` / `2026-08-16T04:59:48-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f5c0-0x0055f5e7.ScrollSpellInventoryPaneSetScrollPosition.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053C and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024785` / `2026-08-16T04:59:50-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f5f0-0x0055f60a.ScrollSpellInventoryPaneActivate.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053D and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024786` / `2026-08-16T04:59:53-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f610-0x0055f62a.ScrollSpellInventoryPaneDeactivateRaw.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053E and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024787` / `2026-08-16T04:59:56-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f630-0x0055f64a.ScrollSpellInventoryPaneCanScrollRaw.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053F and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024788` / `2026-08-16T04:59:59-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f650-0x0055f831.ScrollSpellInventoryPaneHandlePointerOrMouseEvent.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053G and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024789` / `2026-08-16T05:00:01-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f840-0x0055f845.ScrollSpellInventoryPaneHandleKeyOrTextEvent.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053H and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024790` / `2026-08-16T05:00:04-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f850-0x0055f883.ScrollSpellInventoryPaneOnTimer.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053I and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024791` / `2026-08-16T05:00:07-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053J and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024792` / `2026-08-16T05:00:09-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055ff70-0x0056028d.ScrollSpellInventoryPaneHitTestPart.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053K and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024793` / `2026-08-16T05:00:12-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x00560290-0x00560517.ScrollSpellInventoryPaneGetPartRect.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053L and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024794` / `2026-08-16T05:00:15-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x00560520-0x00560590.ScrollSpellInventoryPaneSetHoverPartRaw.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053M and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024795` / `2026-08-16T05:00:18-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x00560590-0x0056064f.ScrollSpellInventoryPaneBeginInteractionRaw.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053N and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024796` / `2026-08-16T05:00:20-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x00560650-0x00560710.ScrollSpellInventoryPaneUpdateDragScroll.md" --apply --queue-timeout 240` | exit 0, ok 1; allocated UID00053O and registered metadata/references; no errors; same literal stats no-op; generated refresh deferred. |
| `000000024805` / `2026-08-16T05:08:03-04:00` | `python .\tools\validator.py --mode file --file "by-class/ScrollSpellInventoryPane.md" --apply --queue-timeout 240` | exit 0, ok 1; updated 89/91, CPP/H registry hashes, nineteen canonical UID links, reference index, projected stats; no errors; generated refresh deferred. |
| `000000024806` / `2026-08-16T05:08:05-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md" --apply --queue-timeout 240` | exit 0, ok 1; applied 91/93, false/no-emitter/blank-formal registry state and normalized one UID link; no errors; generated refresh deferred. |
| `000000024807` / `2026-08-16T05:08:08-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md" --apply --queue-timeout 240` | exit 0, ok 1; applied 91/93, position 180 and corrected CPP hash; no errors; literal stats no-op; generated refresh deferred. |
| `000000024808` / `2026-08-16T05:08:10-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md" --apply --queue-timeout 240` | exit 0, ok 1; applied 93/94, position 190 and exact CPP hash; no errors; literal stats no-op; generated refresh deferred. |
| `000000024809` / `2026-08-16T05:08:13-04:00` | `python .\tools\validator.py --mode file --file "by-type/by-struct/ScrollSpellInventoryPaneLayout.md" --apply --queue-timeout 240` | exit 0, ok 1; applied 93/95 and false/no-emitter/blank-formal registry state; no errors; generated refresh deferred. |
| `000000024810` / `2026-08-16T05:08:15-04:00` | `python .\tools\validator.py --mode file --file "by-type/by-vtable/ScrollSpellInventoryPaneVtables.md" --apply --queue-timeout 240` | exit 0, ok 1; applied 94/95 and false/no-emitter/blank-formal state; transient literal diagnostic `missing_ref_uid 0003CM` occurred three times because UID0003CM had not yet been registered; generated refresh deferred. |
| `000000024811` / `2026-08-16T05:08:18-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData.md" --apply --queue-timeout 240` | exit 0, ok 1; registered UID0003CM, owner, path, 94/96, false/no-emitter/blank-formal state and five references; no errors; generated refresh deferred. |
| `000000024812` / `2026-08-16T05:08:21-04:00` | `python .\tools\validator.py --mode file --file "by-file/ScrollSpellInventoryPane.md" --apply --queue-timeout 240 --wait-generated` | exit 0, ok 1; applied 90/92 and canonical links; rebuilt 5,670-node/4,392-edge emitter registry; validator-owned side effects refreshed generated coverage/research-tracker/metadata and updated `ScrollSpellInventoryPane.cpp/.h`; diagnostics included project-wide counters `autogen_children_fallback_insert:7`, `autogen_children_marker_missing:72`, `autogen_emitter_has_no_code:63`, `autogen_header_children_marker_missing:1`, `autogen_header_noop:127`, with no target error; generated refresh completed. |
| `000000024813` / `2026-08-16T05:08:59-04:00` | `python .\tools\validator.py --mode file --file "by-type/by-vtable/ScrollSpellInventoryPaneVtables.md" --apply --queue-timeout 240` | exit 0, ok 1; added the now-registered UID0003CM reference, no missing-reference/error diagnostic, literal stats no-op; generated refresh deferred. |
| `000000024814` / `2026-08-16T05:22:40-04:00` | `python .\tools\validator.py --mode file --file "by-class/ScrollSpellInventoryPane.md" --apply --queue-timeout 240` | exit 0, ok 1; validated current-state prose reconciliation; no errors; literal stats no-op; generated refresh deferred. |
| `000000024815` / `2026-08-16T05:22:43-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md" --apply --queue-timeout 240` | exit 0, ok 1; validated non-emitting aggregate current-state reconciliation; no errors; literal stats no-op; generated refresh deferred. |
| `000000024816` / `2026-08-16T05:22:55-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md" --apply --queue-timeout 240` | exit 0, ok 1; validated 91/93/position-180 current-state reconciliation; no errors; literal stats no-op; generated refresh deferred. |
| `000000024817` / `2026-08-16T05:23:10-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md" --apply --queue-timeout 240` | exit 0, ok 1; validated 93/94/position-190 current state; removed stale reference-index edge to UID0001H1 after prose became line-neutral/plain corroboration; no errors; literal stats no-op; generated refresh deferred. |
| `000000024818` / `2026-08-16T05:23:23-04:00` | `python .\tools\validator.py --mode file --file "by-type/by-struct/ScrollSpellInventoryPaneLayout.md" --apply --queue-timeout 240` | exit 0, ok 1; validated 93/95 non-emitting layout current-state reconciliation; no errors; literal stats no-op; generated refresh deferred. |
| `000000024819` / `2026-08-16T05:23:26-04:00` | `python .\tools\validator.py --mode file --file "by-type/by-vtable/ScrollSpellInventoryPaneVtables.md" --apply --queue-timeout 240` | exit 0, ok 1; validated 94/95 non-emitting vtable current-state reconciliation with UID0003CM resolved; no errors; literal stats no-op; generated refresh deferred. |
| `000000024820` / `2026-08-16T05:23:39-04:00` | `python .\tools\validator.py --mode file --file "by-memory/0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData.md" --apply --queue-timeout 240` | exit 0, ok 1; validated exact nonreconstructable compiler-data disposition; no errors; literal stats no-op; generated refresh deferred. |
| `000000024821` / `2026-08-16T05:23:50-04:00` | `python .\tools\validator.py --mode file --file "by-file/ScrollSpellInventoryPane.md" --apply --queue-timeout 240 --wait-generated` | exit 0, ok 1; validated final 90/92 source-root reconciliation, rebuilt the 5,670-node/4,392-edge registry, refreshed validator-owned generated metadata/reports and completed foreground generated refresh; project-wide diagnostics were `autogen_children_fallback_insert:7`, `autogen_children_marker_missing:72`, `autogen_emitter_has_no_code:63`, `autogen_header_children_marker_missing:1`, `autogen_header_noop:127`, with no target error. |

The first physical generated readback after command `000000024812` was `.cpp` SHA256 `245DC399CA3748C5933CAE28944A1E1465E20160A5C398A774A98AAA9CA507CF`, 22,364 bytes/618 lines and `.h` SHA256 `B2A1EFAF61453E08AE2CFE8E5C9D84EDEC1CC0574C63D8B2BD9B5626844BC21D`, 2,369 bytes/72 lines. That is dated first-pass evidence.

Final callback readback after foreground command `000000024821` is `.cpp` SHA256 `E915C98C4096773181701D4A4C3A6A34BAF8B88ED5E65E992851E988C0C1CC10`, 22,366 bytes/618 lines and `.h` SHA256 `CEB38F0FC24FFD3E2ABE97C0C64BC8745F3C637CED2398E8A23B098843BF8700`, 2,371 bytes/72 lines. Both generated headers identify command `000000024821`, timestamp `2026-08-16T05:23:50-04:00`, and `foreground-generated-refresh`. At that dated callback readback, all nineteen owning child CPP blocks were exact generated substrings, appeared once each, and occurred in source order 10..190. The complete UID0000CN H block was an exact substring. Declaration began at H line 28; child definitions began at CPP lines 18, 34, 43, 52, 72, 82, 91, 100, 106, 162, 168, 178, 249, 347, 442, 462, 490, 525, and 606. Searches found zero empty-emitter markers, stubs, placeholders, `m_bounds`, partial-source markers, or parameterized `UpdateDragScroll` signatures.

A read-only Gate 2A repair reconciliation on 2026-08-16 compared the repaired Section 22 UID0001GN payload character-for-character after newline normalization with the current owning formal payload in `by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md` and the current generated method in `ScrollSpellInventoryPane.cpp`. At that readback the owner file was SHA256 `4EDAF77818F54835878358EED8EFEED9A44A8C96550C7BAF571FD3D2F615F793`; the generated CPP was SHA256 `4C517368A9ECCBA1E75493D2B966986FCD0F2608A86DF688EF7386E14E1FEC06`, 22,366 bytes, with header command `000000024889` refreshed `2026-08-16T06:59:47-04:00`. The report, owner, and generated UID0001GN payloads are the same 79 lines with normalized payload SHA256 `90210237E667587D10DFB27F6AA919CA7A5B8672B60A1FE350919A6E1890F873`; exact blank lines occur after payload lines 10, 21, 32, 43, 59, 66, and 71. Exact-substring checks against both current read-only authorities returned true. These are dated repair-readback facts; current generated authority remains validator-owned and must be reread dynamically rather than permanently inferred from any recorded hash.

## Changed Files

The callback changed the following ordinary documentation. Hashes are post-validator physical readbacks:

| Ordinary file | SHA256 | Bytes / lines |
| --- | --- | --- |
| `by-file/ScrollSpellInventoryPane.md` | `4E233CA898DCA35F2747E2CCA92649CB23BBDA055A51D564E4F1152861EAFADB` | 27,757 / 169 |
| `by-class/ScrollSpellInventoryPane.md` | `7599FB9087E7222F8505E35AF9C3ADD62A64ED7AD88D8D40BDD528E5C6316AAC` | 32,343 / 256 |
| `by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md` | `93437E5333EE8F00D53102D2211919313B4447ECA8EAB21CBA3B2C199A1A7146` | 35,263 / 227 |
| `by-memory/0x0055f450-0x0055f4f1.ScrollSpellInventoryPaneConstructor.md` | `C0B3A154D24578CE61560A8730BDE30006D67310535E41FE099A6811AD544E8B` | 6,601 / 103 |
| `by-memory/0x0055f500-0x0055f527.ScrollSpellInventoryPaneSetSizeIndexRaw.md` | `6B49716B6E5040CEA6FB7C5B73056AACE71A7FE0F8697F6446C79933D3234A89` | 6,467 / 97 |
| `by-memory/0x0055f530-0x0055f554.ScrollSpellInventoryPaneSetScrollStyleRaw.md` | `894CFBF1A88B5774C885CC3EDE53A6761CFA2A2A65BBB9BE85D0E633465DA675` | 6,443 / 97 |
| `by-memory/0x0055f560-0x0055f5bb.ScrollSpellInventoryPaneSetMaxRange.md` | `79D56187229896CF261DD3E05BFF20DA973DDBA11200ABBBAE91DA84FB85DA85` | 6,514 / 107 |
| `by-memory/0x0055f5c0-0x0055f5e7.ScrollSpellInventoryPaneSetScrollPosition.md` | `F54339D88AC492737EB3BA9F16D8DAD629C1FCCE8DC36D719662830498B01569` | 6,172 / 97 |
| `by-memory/0x0055f5f0-0x0055f60a.ScrollSpellInventoryPaneActivate.md` | `7775080C30A8B093D03A83E6186E3381C6EF95976B9CE66A5C010BB00920F190` | 6,077 / 96 |
| `by-memory/0x0055f610-0x0055f62a.ScrollSpellInventoryPaneDeactivateRaw.md` | `E8CA11DA099EC69AC20FCEAB1AA2EED9B38B4AB1BFC87AEE7C994D59C5909B59` | 6,341 / 97 |
| `by-memory/0x0055f630-0x0055f64a.ScrollSpellInventoryPaneCanScrollRaw.md` | `2179282D926F2ADE420DA107293BF6C7704FBF4C5F9F5A49383C11C80D576D85` | 6,244 / 94 |
| `by-memory/0x0055f650-0x0055f831.ScrollSpellInventoryPaneHandlePointerOrMouseEvent.md` | `BE6B864AD082E41AF764686ADE8112BD23001870697B7E96FC869C86683CDCBD` | 7,991 / 143 |
| `by-memory/0x0055f840-0x0055f845.ScrollSpellInventoryPaneHandleKeyOrTextEvent.md` | `6F5FC955225D2BE9159884C9D6854BA3033519EEC96B29AA9265ED6AB6DA8E26` | 5,946 / 93 |
| `by-memory/0x0055f850-0x0055f883.ScrollSpellInventoryPaneOnTimer.md` | `485E37FDD6A018A80FB68BA56D183F5A35B6C1F914337492878901445817F587` | 6,196 / 97 |
| `by-memory/0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md` | `E7A3FFFCDC78B232BBA8B0C2F1A16C50D9C34707CF474E4581CCBE4A08B75981` | 8,527 / 158 |
| `by-memory/0x0055ff70-0x0056028d.ScrollSpellInventoryPaneHitTestPart.md` | `665B324DA01D7E09E602440A4BD3B3191850CCF44D6309D398050E498B6C4785` | 10,518 / 185 |
| `by-memory/0x00560290-0x00560517.ScrollSpellInventoryPaneGetPartRect.md` | `6A50B5A46BFD8E7A717A46963B33D8CFFEF8336B879A0E055291DFA71447AA0A` | 9,584 / 182 |
| `by-memory/0x00560520-0x00560590.ScrollSpellInventoryPaneSetHoverPartRaw.md` | `7B1A349A037CDA61C5352FFE2D2BB0DE81C78462B472B7C800AED084EED5B375` | 7,028 / 108 |
| `by-memory/0x00560590-0x0056064f.ScrollSpellInventoryPaneBeginInteractionRaw.md` | `73FB69D560A6640B992371B84D6BAFE0E4BF35E3CE2936548B81743765512659` | 7,955 / 116 |
| `by-memory/0x00560650-0x00560710.ScrollSpellInventoryPaneUpdateDragScroll.md` | `69326EB87AD56DB84F9A700640BCC33087EDAC546B2E97694FEA6D45C18316EE` | 7,130 / 122 |
| `by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md` | `4EDAF77818F54835878358EED8EFEED9A44A8C96550C7BAF571FD3D2F615F793` | 18,649 / 200 |
| `by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md` | `EBA5FE05354453E0803F0BD9B88DADB86A6E59FD886A4BF93FD2762B884B381F` | 17,831 / 146 |
| `by-type/by-struct/ScrollSpellInventoryPaneLayout.md` | `84079FDEAC805C2DD37399F9C098FE8710A1E418F3DC149EA3BAC36BE8591994` | 14,589 / 119 |
| `by-type/by-vtable/ScrollSpellInventoryPaneVtables.md` | `845FBC754B4995E3B162644D177B72AD647CE84E07794BC876C94813AEE20218` | 14,949 / 128 |
| `by-memory/0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData.md` | `FF7A90D15722A8ACCFE42FE7537AA0AABE72121E47F5AF4AE3A07F48D63D0E35` | 4,744 / 64 |

This report was reconciled in place. Validator-owned generation updated the target `.cpp`/`.h` and shared generated metadata/reports under commands `000000024812` and final foreground command `000000024821`; B003 did not edit those files directly. No manual `-coverage-report.md`, IDA database, tracker/audit/catalog/lifecycle file, goal, or notes file was edited directly. No `-removed.md` companion is required because the report contains no executable automation or transaction package. All B003 leases were released and the shared lease report contains no active lease.

This narrow Gate 2B contract repair changes only this report. The dated supervisor experiment changed no persisted ordinary/generated/coverage artifact or IDB: both workers were discarded without save, the canonical IDB remained backup-identical, and fresh disk readback restored the seven raw starts to non-function prestate. Current IDB, supervisor-action, coverage, and lifecycle authority remain external and dynamically reread.

This subsequent narrow I10 repair also changes only this report. The dated I10 type test changed no persisted ordinary/generated/coverage artifact or IDB: the supervisor stopped without save, terminated the dirty worker, reopened canonical SHA256 `54AD03CEE2F8F1BCE310035C940CA0CC66BAF2745534E0C82DF71A648C47787E`, and verified rollback against the hash-matching backup. Current IDB and lifecycle authority remain external and dynamically reread.

This subsequent narrow I13 repair also changes only this report. The dated I13 type test changed no persisted ordinary/generated/coverage artifact or IDB: no comment or save occurred, dirty PID `4068` was terminated, and fresh attested readback reconfirmed backup-identical canonical SHA256 `737E20CA29CFD3CBD972A5E9400A7AF08A6DAF2F09D66C85CC81CE8E1A8E1B58`, pristine I13 `row`/`column`, and all seven raw starts as non-functions. Current IDB and lifecycle authority remain external and dynamically reread.

## Implementation Tracking Checklist

The accepted ordinary callback leaves 52 claims checked and four supervisor-owned claims unchecked. Fields after the checkbox are exact twins of the Claim And Incorporation Ledger.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C-NJ-001 | 0000NJ | The complete authored code island is [0x0055f450,0x005608fc), 5,292 bytes, SHA256 cd32902d15a947bafd796b8db7505be5568d8a73e9b95a5ae82f7e9d6eba1c57. | Very high | Exact bounded byte read and hash. | UID0000NJ Target State and inventory | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-002 | 0000NJ | Standalone ScrollSpellInventoryPane.cpp/.h is the best source placement; the historical NewSpell fold is rejected. | High | Closed class island, three vtables, sibling module, consumer-only owner route. | UID0000NJ Source Placement; UID0000LU relationship | historicalize | APPLIED_VERIFIED |
| [x] | C-NJ-003 | 0000NJ | The spell island and completed generic inventory-scroll island have identical length and method topology, with 5,130/5,292 identical bytes. | Very high | Direct byte comparison, 162 differing bytes in 77 runs. | UID0000NJ clone proof; UID0000CN source basis | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-004 | 0001GM | Sixteen exact CC alignment spans separate nineteen methods and exclude successor 0x00560900. | Very high | Bounded bytes and item/function boundaries. | UID0001GM range/padding inventory | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-005 | 0000CN | ScrollSpellInventoryPane is exactly 0x110 bytes with the documented enum and thirteen-member physical layout. | Very high | Live type_inspect, allocation, constructor stores, field accesses. | UID0000CN H/layout; UID0001W1 | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-006 | 0001YS | Three vtable facets and seven RTTI/type objects are compiler products of the class declaration. | Very high | Decorated names, COL/type objects, constructor and slot xrefs. | UID0001YS; UID0003CM | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-007 | 0001YS | Shared scalar-deleting and adjustor wrappers are compiler products shared by eight scroll-pane families and are excluded from this file's authored source. | Very high | Wrapper xrefs and existing source-quality identities. | UID0001YS compiler consequences | reject-invalid | REJECT_INVALID_VERIFIED |
| [x] | C-NJ-008 | 0000NJ | kScrollPanePartExtentBySkin and four EPF/PAL literals are shared external dependencies, not file-owned definitions. | Very high | Types, values, comments, and cross-family xrefs. | UID0000NJ dependencies; UID0000NF no-change | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C-NJ-009 | 0000NJ | No authored destructor, EH object, file-local global/string/table, import definition, third-party source, or code after 0x005608fc belongs to the unit. | Very high | Closed range, symbol/object search, shared wrapper route, successor identity. | UID0000NJ exclusions | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-010 | 0000NJ | Dated command-000000024682 generated CPP/H were incomplete: seventeen bodies were absent, UpdateFromDrag used invalid m_bounds, and UpdateDragScroll had two false parameters; the callback replaced that historical state. | Very high | Physical generated readback at command 000000024682. | UID0000NJ/UID0000CN formal-source replacement | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-011 | 000538 | UID000538 covers constructor 0x0055f450-0x0055f4f1, is reconstructable 93/95, owned/emitted by UID0000CN at position 10, owns the exact Section 22 constructor CPP, and keeps H blank because UID0000CN declares it. | Very high | SHA256 40613436b6c5f0fe7f5b8e156fbf05de9ef8bcbd80e0fda85f03b5aaee3d09a1; caller 0x0057d013; validator 000000024780. | UID000538 exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-012 | 000539 | UID000539 covers raw SetSizeIndex 0x0055f500-0x0055f527, is reconstructable 89/91, owned/emitted by UID0000CN at position 20, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | High | SHA256 48679840081c330a7852b3e68ce164e8e650e230fb07769968a9f84c4790758a; exact raw clone; zero xrefs; validator 000000024781. | UID000539 exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-013 | 00053A | UID00053A covers raw SetScrollStyle 0x0055f530-0x0055f554, is reconstructable 89/91, owned/emitted by UID0000CN at position 30, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | High | SHA256 4ea6ca081e50c45c9d819c4df934434c95707a445f8f06cac86a1c8b5afad5c4; exact raw clone; zero xrefs; validator 000000024782. | UID00053A exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-014 | 00053B | UID00053B covers SetMaxRange 0x0055f560-0x0055f5bb, is reconstructable 93/95, owned/emitted by UID0000CN at position 40, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | Very high | SHA256 c504a31bd1577b41537ae91425c5d2575483ed073207193c545b615792be1f23; caller 0x0057d2b9; validator 000000024783. | UID00053B exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-015 | 00053C | UID00053C covers SetScrollPosition 0x0055f5c0-0x0055f5e7, is reconstructable 93/95, owned/emitted by UID0000CN at position 50, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | Very high | SHA256 c823be0b3a17b1411aac7d79c9052da8122a7e32f5b2a7c23fcbfb6c1aeee940; four callers; validator 000000024784. | UID00053C exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-016 | 00053D | UID00053D covers Activate 0x0055f5f0-0x0055f60a, is reconstructable 90/92, owned/emitted by UID0000CN at position 60, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | Very high | SHA256 cc2001d3751e1f7d5535f9e6c63305f9cebda99fe58184945e9cfccab9451847; caller 0x0057d028; validator 000000024785. | UID00053D exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-017 | 00053E | UID00053E covers raw Deactivate 0x0055f610-0x0055f62a, is reconstructable 89/91, owned/emitted by UID0000CN at position 70, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | High | SHA256 c97d8f364beb37dcf10c6177a75485635a57c70d4e389ace3a7bbae35761f322; exact raw clone; validator 000000024786. | UID00053E exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-018 | 00053F | UID00053F covers raw CanScroll 0x0055f630-0x0055f64a, is reconstructable 92/94, owned/emitted by UID0000CN at position 80, owns the exact Section 22 CPP, and keeps H blank under the parent declaration. | High | SHA256 e5e73329a48d7f7236650f40361f4a4464b6b6d5777fde7a286d05ed94f5af19; exact raw clone; validator 000000024787. | UID00053F exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-019 | 00053G | UID00053G covers HandlePointerOrMouseEvent 0x0055f650-0x0055f831, is reconstructable 90/92, owned/emitted by UID0000CN at position 90, owns the exact Section 22 CPP, and keeps H blank under the parent virtual declaration. | Very high | SHA256 77b5a319bd719d1068101f3471b9d86458f00158936c6456488e324c044fd581; vtable xref 0x00623ee4; validator 000000024788. | UID00053G exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-020 | 00053H | UID00053H covers HandleKeyOrTextEvent 0x0055f840-0x0055f845, is reconstructable 93/95, owned/emitted by UID0000CN at position 100, owns the exact Section 22 CPP, and keeps H blank under the parent virtual declaration. | Very high | SHA256 cc0e3cb106eb0fdec984d44a563d98c3da80700bbb8d2be4e66ebd54a9919626; vtable xref 0x00623ee8; validator 000000024789. | UID00053H exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-021 | 00053I | UID00053I covers OnTimer 0x0055f850-0x0055f883, is reconstructable 93/95, owned/emitted by UID0000CN at position 110, owns the exact Section 22 CPP, and keeps H blank under the parent virtual declaration. | Very high | SHA256 85653f517fb94d695cc08eb66cfdb6714129374b64d0d7ac7a4f782a489e4e91; vtable xref 0x00623f14; validator 000000024790. | UID00053I exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-022 | 00053J | UID00053J covers OnPaint 0x0055f890-0x0055ff70, is reconstructable 90/92, owned/emitted by UID0000CN at position 120, owns the exact Section 22 CPP, and keeps H blank under the parent virtual declaration. | Very high | SHA256 57abec85e56067fb5ea52643ecaeeb3af504c904e1dd7c6859a8ca0ae8e71cdd; vtable/callee evidence; validator 000000024791. | UID00053J exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-023 | 00053K | UID00053K covers HitTestPart 0x0055ff70-0x0056028d, is reconstructable 90/92, owned/emitted by UID0000CN at position 130, owns the exact Section 22 CPP, and keeps H blank under the parent private declaration. | Very high | SHA256 17b1dfb9cb93b73473af0d43a3aeb044dbeb4497e9d14d6946d1d1cb76a22f4e; two callers; validator 000000024792. | UID00053K exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-024 | 00053L | UID00053L covers GetPartRect 0x00560290-0x00560517, is reconstructable 90/92, owned/emitted by UID0000CN at position 140, owns the exact Section 22 CPP, and keeps H blank under the parent private declaration. | Very high | SHA256 177b3c96275f2428d35b58f81bbad6a624b92294b5f17be702c9989e64f964be; thirteen callers; validator 000000024793. | UID00053L exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-025 | 00053M | UID00053M covers raw SetHoverPart 0x00560520-0x00560590, is reconstructable 91/93, owned/emitted by UID0000CN at position 150, owns the exact Section 22 CPP, and keeps H blank under the parent private declaration. | High | SHA256 6022e9b09a62d700988ba63a729a9657c81345fb13d7afabdc21803bfb95b668; exact raw clone; validator 000000024794. | UID00053M exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-026 | 00053N | UID00053N covers raw BeginInteraction 0x00560590-0x0056064f, is reconstructable 91/93, owned/emitted by UID0000CN at position 160, owns the exact Section 22 CPP, and keeps H blank under the parent private declaration. | High | SHA256 f16fe1664be8fe9a1b6460a1a01998710460c89f8579a4e253a42e863f81cef5; exact raw clone; validator 000000024795. | UID00053N exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-027 | 00053O | UID00053O covers UpdateDragScroll 0x00560650-0x00560710, is reconstructable 90/92, owned/emitted by UID0000CN at position 170, owns the exact no-argument Section 22 CPP, and keeps H blank under the parent private declaration. | Very high | SHA256 76693d5645830bd3d04923b1524370af5c1998373fcf157929bdc9c23daf3fe2; three callers; validator 000000024796. | UID00053O exact page, formal CPP/H disposition, metadata and coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-028 | 0001GN | UpdateFromDrag 0x00560710-0x0056089d maps cursor geometry to range and calls the NewSpell owner callback only on change. | Very high | SHA256 09733ac52ea007586c04d5429f87094fa3f0d75481f0e801beabc55dda5320eb; two callers. | UID0001GN CPP position 180 | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-029 | 0001GO | ResetScrollState 0x005608a0-0x005608fc removes timers, clears active/hover state, and invalidates the former hover part. | Very high | SHA256 3d64e239e2e318d9f95a42ef76be91240a9ae8afbb1279629730d308ea6e6132; exact raw clone. | UID0001GO CPP position 190 | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-030 | 0000CN | UID0000CN is the direct class owner and emits the CPP include/children preamble and complete normal H declaration through UID0000NJ. | Very high | Current owner graph, class layout, method family, source split. | UID0000CN formal CPP/H and metadata | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-031 | 0000NJ | All nineteen exact methods are child-routed in address/source order 10..190 under validator-assigned UIDs 000538..00053O plus 0001GN/0001GO; no UID was guessed. | Very high | Complete inventory and by-structure child routing. | UID0000NJ/UID0000CN child graph | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-032 | 0001GM | The broad aggregate is nonreconstructable marker/index evidence with no emitter and blank formal CPP/H. | Very high | Exact children own every body; aggregate source would duplicate them. | UID0001GM metadata/formals | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-033 | 0001W1 | The layout page is nonreconstructable evidence with no emitter and blank formals because UID0000CN H owns the declaration. | Very high | Exact class H and by-structure ownership rule. | UID0001W1 metadata/formals | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-034 | 0001YS | Semantic vtables are nonreconstructable compiler evidence with no emitter and blank formals. | Very high | Compiler-generated multiple-inheritance tables. | UID0001YS metadata/formals | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-035 | 0003CM | Exact vtable-data bytes are nonreconstructable compiler evidence with no emitter and blank formals. | Very high | Exact 136-byte decorated data range. | UID0003CM metadata/formals | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-036 | 0000NJ | The by-file page contains the complete inventory, standalone decision, dependencies, historical generated-defect closure, source order, exclusions, and formal ownership contract. | Very high | Whole-file audit. | UID0000NJ all relevant sections | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-037 | 0000CN | The class page contains the no-argument UpdateDragScroll declaration, complete method inventory, exact field/layout/vtable evidence, and final CPP/H. | Very high | Binary and header audit. | UID0000CN | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-038 | 0001GM | The aggregate page contains all nineteen ranges/hashes, sixteen gaps, successor boundary, and non-emitting index disposition. | Very high | Exact range audit. | UID0001GM | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-039 | 0001GN | UID0001GN uses m_visibleBounds, retains UpdateFromDrag naming, and emits at source position 180. | Very high | Binary offset +0x44, current type declarations, source order. | UID0001GN | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-040 | 0001GO | UID0001GO retains the exact ResetScrollState body and emits at source position 190. | Very high | Exact clone/hash and source order. | UID0001GO | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-041 | 0001W1 | UID0001W1 preserves physical layout/history and has no duplicate code emission. | Very high | Class H is authoritative source declaration. | UID0001W1 | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-042 | 0001YS | UID0001YS preserves facet/slot/wrapper/RTTI evidence and has no duplicate code emission. | Very high | Compiler-product analysis. | UID0001YS | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-043 | 0003CM | UID0003CM preserves exact bytes/names/xrefs and has complete non-emitting ordinary metadata; manual coverage remains supervisor-owned. | Very high | Live item/vtable readback. | UID0003CM | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-044 | 0000LU | NewSpellInventoryPane remains consumer/parent only; its complete callback header is already present and ownership does not change. | Very high | Constructor/pointer/callback xrefs and current header. | UID0000LU support relationship | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C-NJ-045 | 00009A | NewSpellInventoryPane friendship/callback declaration remains the exact owner interaction route; no reduced local class is introduced. | Very high | Existing complete H and callback function. | UID00009A support relationship | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C-NJ-046 | 0000NF | ScrollBar retains sole definition/header ownership of kScrollPanePartExtentBySkin; no ordinary support edit is required. | Very high | Existing exact extern/definition and 22 xrefs. | UID0000NF/UID0003CQ protected no-change | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C-NJ-047 | 0000NJ | UID0000NJ is 90/92, not above 95 because exact private spellings/file capitalization are inferred. | High | Complete behavior/source closure and residual source-history uncertainty. | UID0000NJ metadata/coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-048 | 0000CN | UID0000CN is 89/91 after the complete ordinary callback. | High | Exact layout/API/owner/source closure with inferred private names. | UID0000CN metadata/coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-049 | 0001GM | UID0001GM is 91/93 as non-emitting aggregate evidence after the exact child split. | Very high | Complete exact range/child/padding inventory. | UID0001GM metadata/coverage | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-050 | 0000NJ | Exact method children receive the score matrix in Section 26, with source emitters remaining at or below 93/95. | High | Per-method evidence strength and source-quality gate. | Seventeen new children; UID0001GN/UID0001GO | incorporate | APPLIED_VERIFIED |
| [x] | C-NJ-051 | 0001W1 | Layout/vtable support scores are UID0001W1 93/95, UID0001YS 94/95, and UID0003CM 94/96 without source emission. | Very high | Exact layout and compiler-data closure. | Support metadata/coverage | incorporate | APPLIED_VERIFIED |
| [ ] | C-NJ-052 | 0000NJ | Supervisor Gate 2B processes the twelve already-modeled functions under their literal staged-frame contracts. I10 may gain only `event@0x4/4:Event *` after its exact function `set_type`. I13 function `set_type` must retain `row@0x4c/4:int; column@0x50/4:int`; only the subsequent non-pure two-entry `rename.batch.stack` dry-run/apply sequence may rename those occupied rows to `localY`/`localX`, with every other frame fact protected. Any missing old row, destination collision, partial result, or unlisted frame/protected-state delta is a rollback/no-save stop. | High | Literal modeled prestates/post-types, dated public I10/I13 readbacks, current stack-rename schema, collision checks, exact hashes/xrefs. | Section 21 supervisor IDA handoff | incorporate | proposed |
| [ ] | C-NJ-053 | 0000NJ | Supervisor Gate 2B defines the seven exact raw ranges, requires each literal sparse immediate post-define frame, collision-checks and pure-renames, applies the exact type, requires each literal post-type frame with only the documented typed-argument delta, then applies the repeatable comment; any extra, missing, shifted, resized, or retyped row is a rollback/no-save stop. | High | Dated public define_func/set_type frame readbacks, raw bytes/hashes/heads, zero-xref sets, and clean gaps. | Section 21 supervisor IDA handoff | incorporate | proposed |
| [ ] | C-NJ-054 | 0000CN | Existing ScrollSpellInventoryPane/Part types, vtables/RTTI, shared table, resources, padding, wrappers, and successor are protected no-change state. | Very high | Live type/item/comment/xref/byte reads. | Section 21 protected-state rows | already-present | proposed |
| [ ] | C-NJ-055 | 0000NJ | Supervisor-owned manual coverage replacements/insertions are exactly specified in Section 28 and remain outside agent write scope. | High | Current row reread and recommended scores. | Five manual coverage reports | incorporate | proposed |
| [x] | C-NJ-056 | 0000NJ | The accepted callback scoped-validated every changed ordinary page, waited for generated refresh, and physically verified complete generated CPP/H against all nineteen methods. | Very high | Whole-file completion contract and dated generated defects. | Validator Results/Follow-Up | incorporate | APPLIED_VERIFIED |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"additional_uids":["0000CN","0001GM","0001GN","0001GO","0001W1","0001YS","0003CM","000538","000539","00053A","00053B","00053C","00053D","00053E","00053F","00053G","00053H","00053I","00053J","00053K","00053L","00053M","00053N","00053O"],"agent":"B003","command_id":"000000025302","destination_path":"executed-b-agent-research/B003/0000NJ-ScrollSpellInventoryPane-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0000NJ-ScrollSpellInventoryPane-file-source-quality.md","timestamp":"2026-08-16T12:40:53-04:00","uid":"0000NJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
