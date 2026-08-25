** TARGET-REPORT-UID:000305 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID000305 g_pThreadMan Source Quality

## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:000305] as the exact non-duplicating storage child of [UID:0000SH] `g_pThreadMan`, raise the target to `92/94`, and replace the old handwritten constructor/destructor assignment model with explicit `Singleton<ThreadMan>` constructor/destructor specializations in `NexusTK/util/Thread.cpp`.
- Final disposition: the original source shape is a file-static `ThreadMan *g_pThreadMan = NULL;`, a direct empty `Singleton<ThreadMan>` base on `ThreadMan`, and class-specific template specializations that publish and clear the pointer. The five observed stores are compiler lowering of those specializations across normal construction, normal destruction, constructor unwind, and scalar deleting destruction.
- Ownership/emission: target owner/emitter remains UID0000SH; UID0000SH canonical owner remains [UID:0000OR] `Thread`, but its generated emitter moves from UID0000OR to [UID:0000EW] `ThreadMan` at position `1` so the storage and specializations appear after the complete class declaration and before method bodies.
- Required source corrections: add `Singleton<ThreadMan>` to the class bases, add `Singleton.h` to the Thread.cpp root, remove explicit `g_pThreadMan` assignments from the `ThreadMan` constructor and ordinary destructor, retain the EH clear and scalar deleting destructor as compiler-only artifacts, and record the direct Singleton base/PMD evidence in layout and RTTI docs.
- Confidence: very strong for runtime behavior, exact storage/ranges/xrefs, direct base identity, PMD, EBO, source lifetime model, owner/file route, and formal C++; strong for original file-static linkage and inferred human spellings.
- Current saved IDA disposition: the evidence-supported Gate 2B mutations are retained. A305-01/A305-02/A305-04 are exact; A305-03 is exact by function/range/prototype/comment/disassembly/body evidence while remaining persistently non-decompilable; A305-05 has the correct source prototype/comment/decompiler result while retaining an inert legacy physical-frame tail that the MCP rejects as argument members. Neither partial analyzer artifact warrants rollback or further mutation.

## Supporting Research

- Assignment target: [UID:000305] `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md`.
- Dated assignment tracker checkpoint: validator command `000000020493`, timestamp `2026-07-31T10:40:09-04:00`; tracker SHA256 `13F74CBAA11133CF1CE2F061C0A9E27A70E6D18A57C7770A4F800F777AB7EDBE`, `1,690,672` bytes / `6,676` lines. Row `1682` showed `87/89`, reconstructable true, report counts `0/0/0`, owner/emitter UID0000SH. The tracker is validator-owned moving state; this identity is evidence-time history, not durable lifecycle authority.
- Initial live IDA MCP research used healthy session `f608d7c2`, database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; bounded `inspect_items`, `get_bytes`, `xrefs_to`, `get_comments`, `stack_frame`, `analyze_function`, `decompile`, `insn_query`, `entity_query`, and `type_inspect` requests all succeeded.
- Initial evidence-time saved IDB identity was SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, `143,192,751` bytes, last write `2026-07-31T06:21:13.3464834-04:00`. Earlier catalog0376 SHA `4A9360D1E70338D03A5B7C2D6455BE5A5DAED90EDA071FB2DAC4E815A2526C94` is dated history.
- Historical resume freshness recheck at `2026-08-01T03:41:45-04:00`: MCP session `f608d7c2` remained healthy for the same IDB (`status:ok`, Hex-Rays ready), and the physical IDB still matched the then-current SHA256/size/last-write identity above. Its target-item interpretation is superseded by the later mandatory Gate 2B preflight and the current byte-by-byte repair pass; its function, RTTI, xref, source, and ordinary-document evidence remains retained.
- Gate 2B contradiction repair recheck at `2026-08-01T07:08:15-04:00`: healthy session `b3b2bf88` (`status:ok`, Hex-Rays ready, active worker PID `18860`) inspected then-current saved IDB SHA256 `AB59B84F0771AC86D5BD05BE6D1CE9B4738CCC688903EA5887020407C59F59EA`, `143,193,156` bytes, last write `2026-08-01T06:28:02-04:00`. Read-only `get_bytes`, `get_int`, `inspect_items` on every byte from `0x69be00` through `0x69be0f`, `entity_query`, `list_globals`, `get_global_value`, `type_query`, `get_comments`, `xrefs_to`, and current `tools/list` schemas established the historical sparse physical-item state and the guarded four-byte `make_data` repair below. `auto_analysis_ready:false` remained contextual because all bounded calls succeeded.
- Primary-supervisor Gate 2B saved poststate: session `b3b2bf88` saved IDB SHA256 `9393A7D6905B0442345F32F770575CCAA29D5F882115715A7D2C21C0429BFE96`, `143,193,592` bytes, last write `2026-08-01T08:57:14.5891696-04:00`. Save/catalog/audit evidence records A305-01/A305-02/A305-04 exact, A305-03 valid with persistent Hex-Rays failure at `0x596d33`, A305-05 valid with a correct source prototype/decompiler but retained inert legacy physical-frame members, and every protected byte/range/xref/internal comment/neighbor unchanged. This report-only reconciliation accepts that exact saved evidence without opening, mutating, or saving IDA.
- Historical pre-callback ordinary-artifact drift recheck: the target plus all twelve then-planned ordinary support pages retained the evidence-time SHA256/length identities listed under `Changed Files`, so no callback write-set reconciliation was needed at that time. Later accepted B008 UID00026P work and the latest Gate 2A UID000305 sparse-head correction are recorded separately as subsequent drift rather than being rewritten into this historical checkpoint.
- Old-report searches used `UID000305`, `0x0069be08`, `g_pThreadMan`, `ThreadMan singleton`, `Singleton<ThreadMan>`, constructor, destructor, EH clear, scalar deleting destructor, and Thread RTTI terms.
- Relevant executed reports were B003 `0000EW-ThreadMan-class-source-quality`, B003 `00026P-ThreadReadOnlyData-source-quality`, B006 `0001JX-ThreadAndThreadMan-source-quality`, B007 `0000OR-Thread-empty-emitter-family-source-quality`, B008/B009/B012 UID0001K5 scalar reports, B001 UID0002AR mixed-range report, and B004 `0004HM-MiscWorkThreadRttiLocatorPointer-empty-emitter-source-quality`. They were leads only; every target-specific fact was revalidated live.
- The B004 UID0004HM work is the accepted project precedent that resolves the older reports' mistaken lifetime model: the reusable Singleton template has no generic static cell, while each consuming module emits an external/file-static global plus explicit class-specific constructor/destructor specializations.
- Wave2/Wave3 material was ignored. It is not evidence for names, ownership, source placement, scores, or C++.
- Lifecycle wording is durable: this report records evidence and role boundaries; authoritative execution/archive status comes from the physical report path and validator-owned history, not mutable prose here.

## Target

- Target UID: `000305`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:000305] `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md`, exact four-byte `ThreadMan *` singleton storage.
- Target path: `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md`.
- Assignment-time state: `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000SH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000SH`, blank H, and a comment-only CPP covered-by marker.
- Completed ordinary-callback state: `92/94`; owner, emitter, reconstructable state, exact range, and covered-by/no-duplicate formal disposition remain unchanged from the accepted recommendation.

## Current Target State

- The binary/source target remains the exact four-byte pointer-storage span `[0x0069be08,0x0069be0c)`, and its four bytes remain `00 00 00 00`.
- Current saved IDA models one exact four-byte `ThreadMan *` data item `[0x0069be08,0x0069be0c)`. Name/global/entity queries resolve `g_pThreadMan` at size `4`, value and bytes remain zero, and exactly five target xrefs remain. `inspect_items.name` remains blank as a projection detail even though the entity names/global layer resolves the symbol; it is not evidence of a missing name or failed data definition.
- The exact address-regular comment is present: `File-static ThreadMan singleton storage published and cleared by explicit Singleton<ThreadMan> constructor/destructor specializations; adjacent dwords belong to TimerMgr.` Address-repeatable remains absent, and all protected predecessor/successor heads, names, types, bytes, comments, and xrefs are unchanged.
- Exactly five xref instruction starts exist: `0x00596c33`, `0x00596c3a`, `0x00596d5f`, `0x005974e0`, and `0x00597532`. They are distinct from the embedded immediate-operand byte sites `0x00596c34`, `0x00596c3c`, `0x00596d61`, `0x005974e2`, and `0x00597534`; UID000305 now states both lists explicitly and was scoped-validated as command `000000020719` at SHA256 `0BA853B78A15032A529EF162756C4CFF703347244FF3C7805B47C76B65DDED34`.
- Current ordinary docs isolate the exact storage through UID0000SH, emit the file-static definition and explicit `Singleton<ThreadMan>` specializations once through UID0000EW position `1`, declare the direct Singleton base, and attribute publish/clear to compiler lowering rather than handwritten derived-body statements. The accepted callback applied every ordinary edit and scoped validator where applicable across C305-001 through C305-062. The dated `04DD9E...` Gate 2A failure and its four documentary repairs are retained as history; fresh Gate 1 and Gate 2A then passed exact report SHA256 `9328E36CBA82D688BBEAD5E9A767FAFD2D17C18233E43C8579D18D041F6CDA6E` before the saved Gate 2B attempt. The later narrow C305-002/C305-009 callback synchronized UID000305 to the saved IDA poststate under validator command `000000020658`; the final historical-wording correction was revalidated under command `000000020663`.
- Dated generated command20493 `Thread.cpp` has a file-static pointer after the method bodies, a `ThreadMan : public LObject` class, explicit assignments in constructor/destructor, and no `Singleton<ThreadMan>` base/specializations. It is a pre-repair topology checkpoint, not authority for original source.
- Assignment-time score blockers were exact linkage, missing direct-base proof, raw destructor modeling, compiler/EH ownership, and output order. Research and the ordinary callback resolved their source/documentary consequences. Supervisor Gate 2B applied and saved C305-063 through C305-076 with the evidence-backed A305-03/A305-05 analyzer-artifact dispositions recorded here. The authorized narrow callback then implemented and validated C305-002/C305-009 in UID000305 without changing score, owner/emitter, range, formal CPP/H, or any saved IDA action. Manual operations C305-077 through C305-093, generated refresh, and lifecycle handling remain supervisor-owned.
- Later accepted B008 work supersedes B007's historical UID0000EV `91/92` and UID0000OR `91/91` checkpoints: current no-edit UID0000EV is `93/94` at SHA256 `6077B9440753BD1FBDD7A780E81C03AEA5F6212A55E1E7789A091FA6FB3B2360`, and current no-edit UID0000OR is `92/93` at SHA256 `20A9A5E4386316C865B71306DE1FFA5EB4B70755E38133A010586D75F5E9AC30`. The `Singleton.h` CPP dependency, unchanged Thread H content, `Thread.cpp`/`Thread.h` path, `FILE` ownership, and specialization topology from B007 remain current.
- The latest corrective ordinary callback also removed only the extra blank line between UID0001K1's `m_watchList` cleanup brace and destructor closing brace. Its formal CPP is now literal-equal to the accepted 46-line report block at SHA256 `FD60CCEC6D95442F64DABEF9D89C0313167BF401C3060186185988F99201C909`, validated by command `000000020720`; no executable statement or prose changed.

## Executive Recommendation

- Use `static ThreadMan *g_pThreadMan = NULL;` in `Thread.cpp`.
- Define `template <> Singleton<ThreadMan>::Singleton()` and `template <> Singleton<ThreadMan>::~Singleton()` in the same source, publishing and clearing `g_pThreadMan`.
- Declare `class ThreadMan : public LObject, public Singleton<ThreadMan>`.
- Keep the pointer outside the class: a class-static member is contradicted by the distinct file/global storage and explicit Singleton specialization precedent.
- Do not use a generic `Singleton<T>::m_instance`: the accepted reusable template has no field/static cell, and current PMD/constructor lowering matches an empty direct base.
- Do not duplicate the definition in UID000305; its comment-only formal block remains the exact covered-by disposition.
- Do not emit `sub_5974E0` or the scalar deleting destructor as handwritten source methods. Define the raw ordinary destructor as an IDA function for analysis, but source it through `ThreadMan::~ThreadMan()` without an explicit pointer clear because reverse base destruction invokes `Singleton<ThreadMan>::~Singleton()`.

## Supervisor Active Recheck

- The supervisor assignment required direct live revalidation of the four-byte storage, all lifecycle refs, adjacent TimerMgr split, source linkage, owner/emitter chain, compiler wrapper roles, and score/formal disposition. The source/binary questions remain resolved. The saved Gate 2B poststate fixes the physical data-item defect and applies the four function actions; this additive report repair narrows the previously overstrict A305-03/A305-05 readbacks without reopening source research or requesting further IDA mutation.
- Split repair is not needed for UID000305: it is already the exact child `[0x0069be08,0x0069be0c)` of mixed index UID0002AR.
- Source-bearing items in scope all have exact formal dispositions: target covered-by comment, UID0000SH definition/specializations, UID0000EW class replacement, UID0000EV include replacement, UID0001K0 constructor replacement, UID0001K1 destructor/wrapper replacement, UID0001K4 no-code proof, UID0001K5 compiler-marker replacement, and UID00026P no-code proof.
- No score blocker is deferred as "needs investigation."

## Inference Research Guidance Check

- Direct IDA facts: exact four-byte typed target data item, symbolic name/type/value, four zero bytes, five xrefs, exact regular comment, blank `inspect_items.name` projection but resolving entity/global name, and protected predecessor/successor boundaries; exact constructor/destructor/helper/scalar bytes; applied source-facing function names/types/comments; persistent raw-destructor decompile failure; scalar decompiler correctness plus inert retained physical-frame tail; RTTI COL/CHD/base array/PMDs; and vtable references.
- Documentation facts: accepted `Singleton<T>` declaration has no data member or generic body; accepted MiscWorkThread specialization source shows the project pattern; current Thread/ThreadMan docs establish module placement and field/API names.
- Inference: exact retail linkage spelling and local names are unavailable. `static`, `g_pThreadMan`, `ThreadMan__Constructor`, and specialization formatting are the most realistic project-consistent source-facing choices, not symbol-proven spellings.
- Human-source rule: reconstructed C++ must look like plausible mid-2000s developer code, not IDA output. Raw labels, `_DWORD`, fake TimerMgr parameters, manual vtable writes, EH state variables, and scalar flags do not enter normal source.
- Runtime behavior has priority over style; style consistency remains subordinate. The proposal preserves all five lifetime writes through the correct C++ abstraction.

## Heuristic / Inference Reanalysis And Validation

- Linkage blocker: no read/consumer xrefs exist outside the five lifecycle stores. A translation-unit-local pointer is sufficient and matches current docs. `extern` is rejected because no header consumer is evidenced; class-static is rejected because RTTI identifies a separate empty Singleton base and storage is not a class member; generic template static is rejected because UID0004ZL explicitly has no static cell.
- Constructor blocker: at `0x00596c1d` the `LObject` base is constructed; `lea edi,[esi+4]` then conditionally converts the Singleton subobject back to the complete `ThreadMan *` and stores it at `0x0069be08`; only afterward is the ThreadMan vtable installed. This order is exact lowering of direct bases `LObject, Singleton<ThreadMan>`, then the derived body.
- Destructor blocker: `[0x00596d20,0x00596d6f)` performs only derived cleanup, then clears the singleton, then tail-jumps to `LObject::~LObject`. Reverse destruction order explains this as derived body, `Singleton<ThreadMan>::~Singleton()`, then `LObject::~LObject()`. Therefore the explicit clear belongs in the specialization, not the handwritten derived destructor.
- EH helper blocker: `sub_5974E0` has one code xref from constructor unwind action `0x00609ace`, whose adjusted receiver is `this+4`. Its entire body clears the global. It is the retained unwind action for the Singleton base destructor, not `ThreadMan::ClearSingleton()`.
- Scalar wrapper blocker: the historical `sub_5974F0`/TimerMgr signature was contradicted by one vtable data xref, ThreadMan vtable reset, derived cleanup, singleton clear, LObject destruction, and scalar flags. The saved ThreadMan name/type/comment and decompiler now resolve that blocker.
- Raw function blocker: the saved IDB now contains exact function `[0x00596d20,0x00596d6f)`, `ThreadMan__Destructor`, `void __thiscall(ThreadMan *this)`, the exact comment, unchanged 23-item body SHA256 `5D80313F89D3584FC1B6AFFA97416EAE403A863D2ABEA571D49AAA9C6A5928BD`, and zero callers. Hex-Rays still fails at `0x596d33`; exact analyze/disassembly/function/prototype/body evidence resolves the role, so persistent non-decompilability is the accepted protected state rather than deferred investigation or a reason for synthetic mutation.
- Scalar-frame blocker: the saved scalar wrapper has the correct `ThreadMan__ScalarDeletingDestructor` name, `ThreadMan *__thiscall(ThreadMan *this, unsigned int flags)` source prototype, exact comment, and a decompile using only `this`/`flags` with exact behavior. Its physical frame correctly has `flags +0x0c` but retains inert legacy `timerId +0x10`, `delayMs +0x14`, `arg0 +0x18`, and `arg1 +0x1c`; MCP `delete_stack` rejects those rows as argument members. Because they do not affect the source prototype or decompiler, no further mutation is justified and the tail is protected as analyzer metadata.
- Layout blocker: RTTI class hierarchy has three bases: ThreadMan, LObject, and `Singleton<ThreadMan>`. The Singleton base descriptor PMD is `{mdisp=4,pdisp=-1,vdisp=0}`. The complete object is `0x14` bytes; the empty base overlaps the first derived byte at `+4` through MSVC EBO.
- Output-order blocker: emitting UID0000SH directly under file UID0000OR places it after current method children. Emitting it as UID0000EW child at numeric position `1` places definition/specializations after complete class syntax and before unpositioned method children.
- Adjacent-global blocker: `0x0069be0c` and `0x0069be10` are named TimerMgr mirrors with independent refs; physical adjacency does not move them into Thread.cpp.
- IDA item-model blocker: resolved in the saved IDB by one bounded four-byte `ThreadMan *` data item with entity/global name `g_pThreadMan`, size `4`, zero bytes/value, exact comment, five xrefs, and unchanged neighbors. The blank `inspect_items.name` projection does not override the authoritative entity/global name readback.
- Rejected alternatives: a standalone source clear helper, a source-visible scalar deleting destructor, a `ThreadMan::s_instance` static member, an external header global, a generic template instance cell, duplicating code in UID000305, merging adjacent timer globals, or adding only an address comment while leaving the target as four sparse one-byte non-data heads.

## Evidence Standards Used

- Strongest evidence: exact saved data/function/prototype/comment states, bytes, body hash, xrefs, protected neighbor/range/internal-comment readbacks, scalar decompiler use, and RTTI base descriptors, plus normal/EH/scalar lowering convergence.
- Corroborating evidence: accepted Singleton template and MiscWorkThread specializations, current by-* ownership, current generated topology, and old reports used only as leads.
- Negative evidence: zero constructor callers, zero raw-destructor refs, no pointer consumers, no original symbols, no `Singleton<ThreadMan>` IDA UDT, no generic static cell, and no evidence that timer globals share source ownership.
- Tool status: `auto_analysis_ready:false` does not block this report because server health was OK and all bounded target queries returned stable IDB-backed results.
- Confidence remains below absolute original-source certainty because retail linkage/name spelling is unrecoverable; that does not justify reverse-engineered names in final C++.

## Evidence Checked

- IDA evidence history: initial session `f608d7c2`, read-only repair session `b3b2bf88`, current tool schemas, target/function/RTTI evidence, and the primary supervisor's exact saved Gate 2B poststate bound to IDB SHA256 `9393A7D6905B0442345F32F770575CCAA29D5F882115715A7D2C21C0429BFE96`. B007 performed no IDA access or mutation during this reconciliation.
- Functions: exact current prototypes, first items, ranges, frames, Hex-Rays output where available, persistent decompile failure at raw-destructor call `0x596d33`, internal comments, callers/callees, body hash, scalar physical-frame tail, and protected neighbor state.
- Docs: UID000305, UID0000SH, UID0000EW, UID0000EV, UID0000OR, UID0001JX, UID0001K0, UID0001K1, UID0001K4, UID0001K5, UID00026P, UID0001WA, UID0002AR, UID000306, UID000307, UID0004ZK, UID0004ZL, and UID0000RQ.
- Generated: command20493 Thread.cpp/H, memory/global/class/file coverage, and research tracker.
- Manual coverage: current by-memory, by-global, by-class, by-file, by-type/by-struct, and by-type/by-template rows.
- Report-only phase result: no required live query failed, and no IDA mutation/save, ordinary edit, validator, generated refresh, manual coverage edit, or lifecycle command was attempted before Gate 1.
- Accepted ordinary callback result: all applicable edits in C305-001 through C305-062 were implemented without callback-time drift blockers and thirteen ordinary scoped validators passed. The later C305-055-only failure was repaired in the prior artifact. Fresh Gate 2A on exact SHA256 `04DD9EABCC64E184D7676CA4F98D6959730C9CFCDD9CD63409316F621100802C` then passed 58/62 and rejected C305-001/C305-002/C305-009 because UID000305 still presented the earlier physical-item interpretation, plus C305-043 because UID00026P is now literally B008's `90/93`. This additive repair updates and scoped-validates only UID000305, physically re-reads UID00026P without editing it, and preserves the other 58 passing claims. IDA mutation/save, generated refresh, manual coverage, audit/catalog/lifecycle work, `execute_report`, and report movement remain untouched and supervisor-owned.
- Subsequent supervisor evidence: fresh Gate 1 and Gate 2A passed exact report SHA256 `9328E36CBA82D688BBEAD5E9A767FAFD2D17C18233E43C8579D18D041F6CDA6E`, then Gate 2B applied/saved the evidence-supported IDA actions but failed the report's overstrict A305-03 decompile-success and A305-05 frame-deletion expectations. That report-only reconciliation recorded the valid saved state and, at that stage, reopened only C305-002/C305-009 for the narrow ordinary current-state sync now completed; it performed no IDA, validator, manual/generated/audit/catalog/lifecycle, or report-movement action.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C305-001 | 000305 | Exact binary/source storage range is `[0x0069be08,0x0069be0c)` and current saved IDA now models that same range as one four-byte data item. | very strong | bytes/xrefs/aligned boundaries/saved item readback | `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md` Status/Evidence | incorporate | verified |
| C305-002 | 000305 | Current saved target state is one four-byte `ThreadMan *` item whose entity/global name/type/value/size are `g_pThreadMan`/`ThreadMan *`/zero/4; `inspect_items.name` alone remains blank. | very strong | saved item/entity/global/type/value/comment readbacks plus current validated target SHA256 `0BA853B78A15032A529EF162756C4CFF703347244FF3C7805B47C76B65DDED34` | target Status/Evidence post-Gate2B sync | incorporate | verified |
| C305-003 | 000305 | Target bytes are four zeros and remain runtime-initialized storage. | very strong | live get_bytes | target Evidence | incorporate | verified |
| C305-004 | 000305 | Target has exactly five lifecycle xref instruction starts at `0x00596c33`, `0x00596c3a`, `0x00596d5f`, `0x005974e0`, and `0x00597532`, distinct from immediate-operand byte sites `0x00596c34`, `0x00596c3c`, `0x00596d61`, `0x005974e2`, and `0x00597534`. | very strong | live `xrefs_to`, local PE immediate scan, validated target SHA256 `0BA853B78A15032A529EF162756C4CFF703347244FF3C7805B47C76B65DDED34` | target Evidence/Xrefs exact instruction-start/operand-site distinction | incorporate | verified |
| C305-005 | 000305 | Target source declaration is file-static, not external/class-static/generic-static. | strong | negative consumers plus specialization evidence | target Reconstruction Notes | incorporate | verified |
| C305-006 | 000305 | Target remains covered by UID0000SH and must not emit a duplicate definition. | very strong | owner/emitter/source topology | target metadata/formal CPP | already-present | verified |
| C305-007 | 000305 | Raise target from 87/89 to 92/94. | strong | resolved blockers | target metadata/Score Rationale | incorporate | verified |
| C305-008 | 000305 | Replace Item Summary with specialization-based lifetime wording. | very strong | live lifecycle evidence | target Item Summary | incorporate | verified |
| C305-009 | 000305 | Catalog0376/4A9360, callback-time B7CC, and sparse-head AB59 are dated prestates; current saved poststate is IDB SHA256 `9393A7D6905B0442345F32F770575CCAA29D5F882115715A7D2C21C0429BFE96`. | very strong | saved IDB identities, supervisor Gate 2B readback, and current validated target history SHA256 `0BA853B78A15032A529EF162756C4CFF703347244FF3C7805B47C76B65DDED34` | target historical Evidence plus report current poststate | historicalize | verified |
| C305-010 | 000305 | Target CPP remains exact covered-by comment and H remains blank. | very strong | single-definition/source ownership | target formal CPP/H | incorporate | verified |
| C305-011 | 0000SH | Emit `static ThreadMan *g_pThreadMan = NULL;`. | strong | zero consumers and current source precedent | `by-global/g_pThreadMan.md` formal CPP | incorporate | verified |
| C305-012 | 0000SH | Emit explicit `Singleton<ThreadMan>` constructor specialization that publishes complete object pointer. | very strong | constructor lowering/PMD | by-global formal CPP | incorporate | verified |
| C305-013 | 0000SH | Emit explicit `Singleton<ThreadMan>` destructor specialization that clears the pointer. | very strong | ordinary/EH/scalar lowering | by-global formal CPP | incorporate | verified |
| C305-014 | 0000SH | Canonical owner remains UID0000OR Thread.cpp. | very strong | source module evidence | by-global metadata/Ownership | already-present | verified |
| C305-015 | 0000SH | Change generated emitter from UID0000OR to UID0000EW with position 1. | very strong | output-order analysis | by-global metadata | incorporate | verified |
| C305-016 | 0000SH | Raise by-global from 88/89 to 92/94. | strong | full source/lifetime closure | by-global metadata/Score | incorporate | verified |
| C305-017 | 0000SH | Keep by-global H blank because storage/specializations are Thread.cpp-only. | very strong | zero consumers/header need | by-global formal H | already-present | verified |
| C305-018 | 0000SH | Historicalize handwritten derived publish/clear model. | very strong | direct Singleton base lowering | by-global Evidence/Ownership/Changes | historicalize | verified |
| C305-019 | 0000EW | Add direct public base `Singleton<ThreadMan>` after LObject. | very strong | RTTI CHD/BCD PMD and ctor order | `by-class/ThreadMan.md` formal CPP | incorporate | verified |
| C305-020 | 0000EW | Preserve complete class fields/method declarations and child stream. | very strong | current accepted class docs | by-class formal CPP | already-present | verified |
| C305-021 | 0000EW | Raise ThreadMan class from 88/89 to 92/94. | strong | resolved base/lifetime/formal blockers | by-class metadata/Score | incorporate | verified |
| C305-022 | 0000EW | Class owner/emitter remain UID0000OR and H remains blank. | very strong | existing source topology | by-class metadata/formal H | already-present | verified |
| C305-023 | 0000EW | Historicalize explicit derived constructor/destructor global assignments. | very strong | direct-base specializations | by-class Evidence/Reconstruction | historicalize | verified |
| C305-024 | 0000EV | Add `#include "Singleton.h"` after `#include "Thread.h"` in Thread.cpp root. | very strong | complete-base dependency | `by-class/Thread.md` formal CPP | incorporate | verified |
| C305-025 | 0000EV | B007's `91/92` Thread-class checkpoint is historical; later accepted B008 work superseded current UID0000EV to `93/94` at SHA256 `6077B9440753BD1FBDD7A780E81C03AEA5F6212A55E1E7789A091FA6FB3B2360`, while B007's `Singleton.h` CPP dependency and unchanged Thread H content remain current. | very strong | current metadata/formal CPP/H physical readback | by-class Thread current metadata/formal CPP/H inspection | not-applicable | verified |
| C305-026 | 0001K0 | Remove only explicit `g_pThreadMan = this;` from constructor body. | very strong | base specialization lowering | constructor formal CPP | incorporate | verified |
| C305-027 | 0001K0 | Preserve debugger probe, List(20,16), CreateThread, and Win32Error behavior verbatim. | very strong | live decompile/bytes | constructor formal CPP/prose | already-present | verified |
| C305-028 | 0001K0 | Raise constructor from 89/89 to 91/94. | strong | exact behavior plus base source closure | constructor metadata/Score | incorporate | verified |
| C305-029 | 0001K0 | Owner/emitter remain UID0000EW; H remains blank. | very strong | class method body | constructor metadata/formal H | already-present | verified |
| C305-030 | 0001K0 | Reframe publish writes as inlined Singleton constructor specialization. | very strong | `this+4` adjusted-base conversion | constructor Evidence/History | historicalize | verified |
| C305-031 | 0001K1 | Remove only explicit `g_pThreadMan = NULL;` from ordinary destructor source. | very strong | reverse base destruction | raw-wrapper formal CPP | incorporate | verified |
| C305-032 | 0001K1 | Preserve exact worker handle/list cleanup and all five PostThreadMessageW wrappers. | very strong | raw bytes/current formal | raw-wrapper formal CPP/prose | already-present | verified |
| C305-033 | 0001K1 | Raise raw-wrapper page from 89/89 to 90/93. | strong | exact destructor boundary/source closure | raw-wrapper metadata/Score | incorporate | verified |
| C305-034 | 0001K1 | Record `[0x596d20,0x596d6f)` as the ordinary destructor and 596d6f one-byte fence. | very strong | 23 items/pads | raw-wrapper Evidence/Inventory | incorporate | verified |
| C305-035 | 0001K4 | Keep clear helper reconstructable false, owner none, no emitter, blank CPP/H. | very strong | compiler unwind role | clear-helper metadata/formals | already-present | verified |
| C305-036 | 0001K4 | Replace derived-clear wording with Singleton destructor unwind-action wording. | very strong | xref from constructor EH adjusted base | clear-helper Summary/Evidence | incorporate | verified |
| C305-037 | 0001K4 | Keep clear-helper score 88/92. | strong | behavior exact; compiler artifact | clear-helper metadata | already-present | verified |
| C305-038 | 0001K5 | Keep scalar wrapper comment-only CPP and blank H. | very strong | vtable-only compiler wrapper | scalar formal CPP/H | already-present | verified |
| C305-039 | 0001K5 | Update marker/prose to attribute clear to Singleton base destruction. | very strong | scalar bytes/base order | scalar formal CPP/Evidence | incorporate | verified |
| C305-040 | 0001K5 | Keep scalar metadata 86/91 and class emitter UID0000EW. | strong | exact wrapper but compiler-only/IDA stale | scalar metadata | already-present | verified |
| C305-041 | 00026P | Add exact ThreadMan CHD three-entry base array and Singleton PMD `{4,-1,0}`. | very strong | live RTTI bytes/names | ThreadReadOnlyData RTTI/Evidence | incorporate | verified |
| C305-042 | 00026P | Record EBO overlap and direct-base order. | very strong | PMD plus constructor order | ThreadReadOnlyData Reconstruction | incorporate | verified |
| C305-043 | 00026P | B007 originally raised the read-only page from 87/91 to 89/94; later accepted B008 work superseded it to current 90/93 while preserving ThreadMan CHD/PMD/EBO and no-code evidence. Current disposition is no-edit. | very strong | current SHA256 `F152CD0A724908BB54C4E5E8D7A434B45CF90C9BD54EE13EBA522B7030D4A705`, literal 90/93 metadata, B008 score/history readback | ThreadReadOnlyData metadata/score/history inspection | not-applicable | verified |
| C305-044 | 0001WA | Record direct Singleton base at PMD +4 and EBO overlap with debugger byte. | very strong | RTTI plus exact 0x14 size | `by-type/by-struct/ThreadManLayout.md` Layout/Notes | incorporate | verified |
| C305-045 | 0001WA | Raise layout from 86/90 to 90/94; keep covered-by formal. | strong | complete base/layout closure | ThreadManLayout metadata/formal | incorporate | verified |
| C305-046 | 0001JX | Reframe singleton publish/clear rows as specialization-generated source behavior. | very strong | full source model | ThreadAndThreadMan Inventory/Evidence | incorporate | verified |
| C305-047 | 0001JX | Keep aggregate 88/89 and blank formal due broader raw helper caveats. | strong | scope beyond target remains | ThreadAndThreadMan metadata/formal | already-present | verified |
| C305-048 | 0002AR | Keep mixed index owner none, reconstructable false, emitter blank, score 86/88. | very strong | split ownership | mixed-index metadata/Rebuild Notes | already-present | verified |
| C305-049 | 0002AR | Correct stale prose/manual classification from reconstructable to reviewed non-reconstructable index. | very strong | physical metadata | mixed-index prose/manual row | incorporate | verified |
| C305-050 | 000306 | Timer baseline child remains TimerMgr-owned 88/91 with no content change. | very strong | live adjacent name/type and existing docs | baseline child inspection | not-applicable | verified |
| C305-051 | 000307 | Timer current-tick child remains TimerMgr-owned 88/91 with no content change. | very strong | live adjacent name/type and existing docs | current-tick child inspection | not-applicable | verified |
| C305-052 | 0000OR | B007's `91/91` Thread-file checkpoint is historical; current UID0000OR is `92/93` at SHA256 `20A9A5E4386316C865B71306DE1FFA5EB4B70755E38133A010586D75F5E9AC30`, with `Thread.cpp`/`Thread.h` path, `FILE` ownership, and B007's specialization topology preserved. | very strong | current metadata/Status/topology physical readback | by-file Thread current Status/metadata/topology inspection | not-applicable | verified |
| C305-053 | 0000OR | Add Singleton include/base/specialization emission topology and historical correction. | very strong | resolved source ordering | by-file Thread Contents/Evidence | incorporate | verified |
| C305-054 | 0004ZL | Singleton template remains complete, empty, fieldless, and 92/94 with no generic body/storage. | very strong | current formal H and precedent | SingletonTemplate inspection | already-present | verified |
| C305-055 | 0004ZK | Singleton source file is exactly 90/92 and needs no edit. | very strong | literal metadata in SHA256 `9B16D9AA46FAC29A54BAC833ADD68B258A747DC8831B96B35CD0ED241B521D30` | Singleton file inspection | not-applicable | verified |
| C305-056 | 000305 | Formal target CPP replacement is the exact covered-by marker in this report. | very strong | single-definition route | target formal CPP | incorporate | verified |
| C305-057 | 0000SH | Formal global CPP replacement is the exact definition/specialization block in this report. | very strong | source model | by-global formal CPP | incorporate | verified |
| C305-058 | 0000EW | Formal class CPP replacement is the exact dual-base class block in this report. | very strong | direct-base proof | by-class ThreadMan formal CPP | incorporate | verified |
| C305-059 | 0000EV | Formal Thread root CPP replacement is the exact two-include child-stream block. | very strong | dependency/order proof | by-class Thread formal CPP | incorporate | verified |
| C305-060 | 0001K0 | Formal constructor CPP replacement is the exact no-explicit-publish block. | very strong | specialization lowering | constructor formal CPP | incorporate | verified |
| C305-061 | 0001K1 | Formal raw-wrapper CPP is literal-equal to the report's accepted 46-line no-explicit-clear block after removal of one extra blank line only. | very strong | exact formal-block comparison, validator `000000020720`, SHA256 `FD60CCEC6D95442F64DABEF9D89C0313167BF401C3060186185988F99201C909` | raw-wrapper formal CPP exact 46-line block | incorporate | verified |
| C305-062 | 0001K5 | Formal scalar marker replacement names Singleton base destruction. | very strong | compiler lowering | scalar formal CPP | incorporate | verified |
| C305-063 | 000305 | Saved A305-01 is one exact four-byte typed item `[0x69be08,0x69be0c)`, entity/global `g_pThreadMan` size 4, exact regular comment, zero bytes/value, and five xrefs; blank `inspect_items.name` projection is accepted. | very strong | saved data/entity/global/comment/xref readback | Supervisor Gate 2B `0x0069be08` | incorporate | verified |
| C305-064 | 0001K0 | Saved constructor name is `ThreadMan__Constructor`. | strong | supervisor saved name/range readback | Supervisor Gate 2B `0x00596bf0` | incorporate | verified |
| C305-065 | 0001K0 | Saved constructor type is `ThreadMan *__thiscall(ThreadMan *this)`. | very strong | supervisor saved prototype/decompiler readback | Supervisor Gate 2B `0x00596bf0` | incorporate | verified |
| C305-066 | 0001K0 | Saved constructor function-regular comment is exact. | strong | supervisor saved comment/protected-state readback | Supervisor Gate 2B `0x00596bf0` | incorporate | verified |
| C305-067 | 0001K1 | Saved ordinary destructor is exact function `[0x596d20,0x596d6f)` named `ThreadMan__Destructor`, with unchanged 23-item body hash and zero callers. | very strong | saved analyze/disassembly/function/body readback | Supervisor Gate 2B `0x00596d20` | incorporate | verified |
| C305-068 | 0001K1 | Saved ordinary destructor type is `void __thiscall(ThreadMan *this)`; persistent Hex-Rays failure at `0x596d33` is accepted and protected. | very strong | saved prototype plus exact disassembly/body evidence | Supervisor Gate 2B `0x00596d20` | incorporate | verified |
| C305-069 | 0001K1 | Saved ordinary destructor function-regular comment is exact; no decompile-success claim is required. | strong | saved comment/range/body readback | Supervisor Gate 2B `0x00596d20` | incorporate | verified |
| C305-070 | 0001K4 | Saved clear-helper name is `ThreadMan__SingletonDestructorUnwindAction`. | strong | saved name/EH/xref readback | Supervisor Gate 2B `0x005974e0` | incorporate | verified |
| C305-071 | 0001K4 | Saved clear-helper type is `void __cdecl ThreadMan__SingletonDestructorUnwindAction(void)`. | very strong | saved type/two-instruction readback | Supervisor Gate 2B `0x005974e0` | incorporate | verified |
| C305-072 | 0001K4 | Saved compiler-unwind function-regular comment is exact. | strong | saved comment/EH role readback | Supervisor Gate 2B `0x005974e0` | incorporate | verified |
| C305-073 | 0001K5 | Saved scalar-wrapper name is `ThreadMan__ScalarDeletingDestructor`. | strong | saved name/vtable readback | Supervisor Gate 2B `0x005974f0` | incorporate | verified |
| C305-074 | 0001K5 | Saved scalar-wrapper type is `ThreadMan *__thiscall(ThreadMan *this, unsigned int flags)` and Hex-Rays uses only `this`/`flags`; physical frame retains inert legacy tail members rejected by `delete_stack`, with no further mutation warranted. | very strong | saved prototype/decompile/frame/tool-rejection evidence | Supervisor Gate 2B `0x005974f0` | incorporate | verified |
| C305-075 | 0001K5 | Saved scalar-wrapper function-regular comment is exact. | strong | saved comment/behavior readback | Supervisor Gate 2B `0x005974f0` | incorporate | verified |
| C305-076 | 000305 | All protected bytes/ranges/xrefs/internal comments/neighbors remained unchanged across the saved Gate 2B action set. | very strong | supervisor protected pre/post readbacks and saved evidence | Supervisor Gate 2B protected set | already-present | verified |
| C305-077 | 0001JX | Replace stale by-memory manual row with exact 88% source-topology row. | very strong | current page/manual mismatch | `by-memory/-coverage-report.md` UID0001JX | incorporate | proposed |
| C305-078 | 0001K0 | Replace by-memory manual row with exact 91% constructor row. | very strong | score/formal change | by-memory manual UID0001K0 | incorporate | proposed |
| C305-079 | 0001K1 | Replace by-memory manual row with exact 90% wrapper row. | very strong | score/source change | by-memory manual UID0001K1 | incorporate | proposed |
| C305-080 | 0001K4 | Replace by-memory manual row with exact ignored 88% specialization-unwind row. | very strong | source-role change | by-memory manual UID0001K4 | incorporate | proposed |
| C305-081 | 0001K5 | Replace by-memory manual row with exact 86% scalar-specialization row. | very strong | description change | by-memory manual UID0001K5 | incorporate | proposed |
| C305-082 | 00026P | Replace by-memory manual row with corrected range and current 90% broader Thread/ThreadMan RTTI-vtable row; retain CHD/PMD/EBO/no-code evidence and the remaining scalar-run/private-name caveat. | very strong | current 90/93 metadata, corrected range, B008 vtable/source expansion, preserved B007 hierarchy evidence | by-memory manual UID00026P | incorporate | proposed |
| C305-083 | 0002AR | Replace by-memory manual row with ignored 86% mixed-index row. | very strong | current metadata mismatch | by-memory manual UID0002AR | incorporate | proposed |
| C305-084 | 000305 | Replace by-memory manual target row with 92% specialization-storage row. | very strong | target score/source change | by-memory manual UID000305 | incorporate | proposed |
| C305-085 | 0000SH | Replace by-global manual row with 92% file-static specialization row. | very strong | global score/source change | `by-global/-coverage-report.md` UID0000SH | incorporate | proposed |
| C305-086 | 0000EV | Replace by-class Thread row text to include Singleton dependency while retaining current 93%. | very strong | source topology/current ordinary score | `by-class/-coverage-report.md` UID0000EV | incorporate | proposed |
| C305-087 | 0000EW | Replace by-class ThreadMan row with 92% dual-base/specialization row. | very strong | class score/source change | by-class manual UID0000EW | incorporate | proposed |
| C305-088 | 0000OR | Replace by-file Thread row text to include specialization topology while retaining current 92%. | very strong | source topology/current ordinary score | `by-file/-coverage-report.md` UID0000OR | incorporate | proposed |
| C305-089 | 0001WA | Replace by-struct manual row with 90% PMD/EBO layout row. | very strong | layout score/source change | `by-type/by-struct/-coverage-report.md` UID0001WA | incorporate | proposed |
| C305-090 | 0004ZL | Singleton template manual row is already exact and requires no change. | very strong | current row readback | `by-type/by-template/-coverage-report.md` UID0004ZL | already-present | proposed |
| C305-091 | 0004ZK | Singleton file manual row is already exact and requires no change. | very strong | current row readback | `by-file/-coverage-report.md` UID0004ZK | already-present | proposed |
| C305-092 | 000306 | TimerMgr baseline-mirror manual row is already exact at 88% and requires no change. | very strong | current row readback | `by-memory/-coverage-report.md` UID000306 | already-present | proposed |
| C305-093 | 000307 | TimerMgr current-tick-mirror manual row is already exact at 88% and requires no change. | very strong | current row readback | `by-memory/-coverage-report.md` UID000307 | already-present | proposed |

## Positive Evidence Summary

- Exact four-byte binary/source storage identity, symbolic global/type/value, zero bytes, and five writes remain current saved IDA facts. Historical AB59 had four one-byte non-data heads across `[0x69be08,0x69be0c)`; current saved IDA instead has one exact four-byte `ThreadMan *` data item at `0x69be08`, with entity/global `g_pThreadMan` size `4`, exact regular comment, and only the `inspect_items.name` projection blank.
- Historical AB59 had no interior names or xrefs at `0x69be09`, `0x69be0a`, or `0x69be0b`, and the next named/two-xref item began exactly at `0x69be0c`; that evidence justified the bounded data creation already applied. Current saved readback confirms the four-byte item, zero bytes/value, five target xrefs, and unchanged protected successor at `0x69be0c`.
- Constructor lowering converts the `this+4` Singleton base pointer back to the complete object before publishing.
- RTTI independently proves `Singleton<ThreadMan>` is a direct base at PMD +4.
- Normal destructor, constructor unwind helper, and scalar deleting destructor each clear at the precise point where the Singleton base destructor runs.
- The accepted fieldless Singleton template and MiscWorkThread specialization source provide a project-local source precedent.
- Zero non-lifecycle reads make file-static linkage sufficient.
- The full inference chain explains all bytes and compiler artifacts without invented APIs or duplicated source.

## IDA MCP Facts

- Target saved poststate: `[0x0069be08,0x0069be0c)` is one four-byte `ThreadMan *` data item; entity/global/name queries resolve `g_pThreadMan` with size `4`; value/bytes are zero; the exact address-regular comment is present; address-repeatable remains absent; five xrefs remain. `inspect_items.name` alone projects blank, which does not contradict the resolving entity/global name.
- Target historical prestate: sparse IDB AB59 had independent one-byte non-data heads `[08,09)`, `[09,0a)`, `[0a,0b)`, and `[0b,0c)`, symbolic size `1`, no comment, and no interior names/xrefs. This is retained to explain A305-01, not presented as current.
- Boundary saved poststate: predecessor `s_mouseSelectionAnchor`, successors `g_timerTickBaselineMirror`/`g_timerCurrentTickMirror`, and `g_pfnWideOpenFile` retain their exact physical/symbolic states; bytes remain zero and xref counts remain predecessor `04=8`, target `08=5`, successor `0c=2`.
- Constructor saved poststate: `ThreadMan__Constructor`, `[0x596bf0,0x596d13)`, size `0x123`, `ThreadMan *__thiscall(ThreadMan *this)`, exact function-regular comment, zero callers, and preserved body/EH/comments.
- Constructor frame: `Block +0x14 void *`, `var_14 +0x18 LObject *`, `pExceptionObject +0x1c _DWORD`, `var_C +0x20 _DWORD`, `var_4 +0x28 _DWORD`, saved registers `+0x2c`, return address `+0x30`, `arg_4 +0x38 int`. These EH/chunk members are protected, not source parameters.
- Constructor Hex-Rays locals: `lpParameter DWORD *`, `v2 bool *`, `v3/v4 HMODULE`, `IsDebuggerPresent BOOL (__stdcall *)()`, `v6/v7/v10/v11 _DWORD *`, `pExceptionObject _DWORD *`, `v13 int`.
- Pre-destructor pad: `[0x596d13,0x596d20)` is 13 `0xcc` bytes.
- Raw destructor saved poststate: exact function `[0x596d20,0x596d6f)`, `ThreadMan__Destructor`, `void __thiscall(ThreadMan *this)`, exact function-regular comment, 23-item body SHA256 `5D80313F89D3584FC1B6AFFA97416EAE403A863D2ABEA571D49AAA9C6A5928BD`, zero callers, and unchanged pads. Hex-Rays persistently fails at `0x596d33`; analyze/disassembly/function/prototype/body evidence is the accepted deterministic readback.
- Clear helper saved poststate: `ThreadMan__SingletonDestructorUnwindAction`, `[0x5974e0,0x5974eb)`, `void __cdecl ThreadMan__SingletonDestructorUnwindAction(void)`, exact function-regular comment, unchanged return-only frame/two instructions, one EH code xref, and one target data xref.
- Scalar wrapper saved poststate: `ThreadMan__ScalarDeletingDestructor`, `[0x5974f0,0x59756e)`, `ThreadMan *__thiscall ThreadMan__ScalarDeletingDestructor(ThreadMan *this, unsigned int flags)`, exact function-regular comment, one vtable xref, and a decompile using only `this`/`flags` with exact behavior.
- Scalar physical-frame saved poststate: saved registers `+0x4`, return `+0x8`, `flags +0x0c`, then inert legacy `timerId +0x10`, `delayMs +0x14`, `arg0 +0x18`, and `arg1 +0x1c`. MCP `delete_stack` rejects the tail as argument members. The correct source prototype/decompiler is authoritative; the inert tail is protected and requires no further mutation.
- RTTI: ThreadMan COL at `0x651650`; CHD at `0x651664`, attributes `1`, three base entries. Singleton BCD at `0x6516a0` names `.?AV?$Singleton@VThreadMan@@@@` and has PMD `{4,-1,0}`.
- Current IDA type `ThreadMan` exists only as an incomplete no-member type; `Singleton<ThreadMan>` is absent from the type catalog. No full UDT is proposed because source docs, not guessed IDA members, own the class layout.
- Historical session `f608d7c2` readback remains evidence for constructor/destructor/helper/scalar/RTTI facts, but its four-byte physical-item statement is superseded rather than silently discarded.
- Session `b3b2bf88` now has saved IDB SHA256 `9393A7D6905B0442345F32F770575CCAA29D5F882115715A7D2C21C0429BFE96`. The current type catalog still contains only incomplete `ThreadMan`; no guessed UDT was created. A305-01 through A305-05 are retained exactly as applied, with A305-03 persistent non-decompilability and A305-05 inert frame-tail metadata accepted as protected outcomes.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00596bf0-0x00596d13` | UID0001K0 constructor | source method plus inlined bases | true | UID0000EW | current 91/94 | ordinary formal installed/validated; saved IDA name/type/comment exact |
| `0x00596d13-0x00596d20` | no UID | 13-byte `0xcc` fence | no | none | N/A | preserve |
| `0x00596d20-0x00596d6f` | inside UID0001K1 | ordinary destructor body | true | UID0000EW | current page 90/93 | saved exact IDA function/name/type/comment/body; persistent decompile failure accepted |
| `0x00596d6f-0x00596d70` | inside UID0001K1 | one-byte `0xcc` fence | no | none | N/A | preserve |
| `0x00596d70-0x00596e0b` | inside UID0001K1 | five raw message wrappers | true | UID0000EW | current page 90/93 | source wrappers preserved; formal CPP literal-equal to the accepted 46-line block and validated as command `000000020720` |
| `0x005974e0-0x005974eb` | UID0001K4 | Singleton destructor unwind action | false | none | 88/92 | no source body; saved IDA name/type/comment exact |
| `0x005974eb-0x005974f0` | no UID | five-byte `0xcc` fence | no | none | N/A | preserve |
| `0x005974f0-0x0059756e` | UID0001K5 | scalar deleting destructor | true/compiler-only | UID0000EW | 86/91 | comment-only source marker; saved IDA prototype/decompiler exact, inert physical-frame tail retained |
| `0x0062e2c0-0x0062e2d0` | inside UID00026P | ThreadMan RTTI locator/vtable | generated | UID0000OR | current page 90/93 | B007's 89/94 hierarchy pass is preserved; later B008 broader-rdata work added the complete Thread table/roles and superseded the aggregate score; exact CHD/PMD/EBO remains documented with no source data body |
| `0x0069be08-0x0069be0c` | UID000305 | singleton pointer storage | true | UID0000SH | current 92/94 | covered-by marker and saved-IDB four-byte item/comment/current-history prose installed and validated |
| `0x0069be0c-0x0069be10` | UID000306 | TimerMgr baseline mirror | true | TimerMgr global owner | 88/91 | no change |
| `0x0069be10-0x0069be14` | UID000307 | TimerMgr current mirror | true | TimerMgr global owner | 88/91 | no change |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x596c33` | target data ref in constructor | non-null adjusted Singleton base publishes complete ThreadMan pointer |
| `0x596c3a` | target data ref in constructor | null-preserving cast fallback generated by specialization |
| `0x596d5f` | target data ref in raw destructor | normal Singleton base destructor clear |
| `0x5974e0` | target data ref in clear helper | constructor-unwind Singleton destructor clear |
| `0x597532` | target data ref in scalar wrapper | deleting-destructor Singleton base clear |
| `0x609ace` | code xref to clear helper from constructor EH chunk | cleanup action receives adjusted `this+4` base facet |
| `0x62e2c4` | data xref to scalar wrapper | ThreadMan virtual deleting-destructor slot |
| `0x596c4d`, `0x596d26`, `0x5974f9` | refs to ThreadMan vtable | constructor, ordinary destructor, and scalar wrapper convergence |
| constructor `0x596bf0` | zero incoming refs | source reachability unresolved but body/source role exact |
| raw destructor `0x596d20` | zero callers; exact saved function; persistent Hex-Rays failure at `0x596d33` | analyze/disassembly/prototype/body evidence establishes the ordinary destructor without synthetic decompiler repair |

## Documentation Evidence And IDA Status

- UID000305 and UID0000SH now carry the correct exact storage, single-definition route, file-static linkage decision, specialization-generated lifetime explanation, and accepted formal CPP/H dispositions at `92/94`.
- UID000305 ordinary documentation now records current saved IDA as one exact four-byte `ThreadMan *` data item, entity/global `g_pThreadMan` size `4`, exact regular comment, zero bytes/value, five xrefs, blank `inspect_items.name` projection, and unchanged protected neighbors. Catalog0376/4A9360, B7CC, and AB59 remain explicit dated prestates, and the AB59 change-log entry says `then-current` rather than presenting the sparse heads as current. It now also distinguishes the exact five xref instruction starts from their five immediate-operand byte sites; C305-002/C305-004/C305-009 are scoped-validated in target SHA256 `0BA853B78A15032A529EF162756C4CFF703347244FF3C7805B47C76B65DDED34`.
- UID0000EW now declares `ThreadMan : public LObject, public Singleton<ThreadMan>`, preserves the complete class body/child stream, and records PMD/EBO plus the superseded explicit-derived-assignment model at `92/94`.
- UID0001K0 and UID0001K1 now contain the accepted behavior-complete formal C++ with only the two derived assignments removed; their prose preserves the specialization lowering and exact constructor/destructor evidence at `91/94` and `90/93`. UID0001K1's one extra blank line was removed, making its current 46-line formal CPP literal-equal to the accepted report block at SHA256 `FD60CCEC6D95442F64DABEF9D89C0313167BF401C3060186185988F99201C909`.
- UID0001K4 now identifies the exact compiler-retained `Singleton<ThreadMan>` destructor unwind action while retaining no owner/emitter/code and `88/92`.
- UID0001K5 has the accepted Singleton-base-aware compiler-wrapper marker/prose at `86/91`. Saved IDA now has the correct ThreadMan scalar-deleting-destructor name/type/comment and decompiler behavior; the inert physical-frame tail is analyzer metadata, not a source signature and not an ordinary-doc blocker.
- UID00026P and UID0001WA contain exact ThreadMan CHD/base-array, Singleton PMD `{4,-1,0}`, direct-base order, EBO overlap, and covered-by/no-code dispositions. B007 originally installed UID00026P `89/94`; accepted B008 broader-rdata work later superseded the current page to `90/93` while preserving those hierarchy facts and adding the complete fourteen-cell Thread vtable/role assessment. Completion rose with broader coverage, while confidence fell one point because the broader current assessment retains inferred private virtual spellings and unresolved separate Thread-side scalar-run/broader raw-helper names; this is not a simple linear score improvement. UID0001WA remains `90/94`.
- UID0004ZL is already exact at `92/94`; UID0004ZK is literally `90/92` at report-recorded SHA256 `9B16D9AA46FAC29A54BAC833ADD68B258A747DC8831B96B35CD0ED241B521D30`. Both remain protected no-edit supports.
- UID0000EV's B007 `91/92` checkpoint and UID0000OR's B007 `91/91` checkpoint are dated history. Later accepted B008 work makes their current no-edit states UID0000EV `93/94` at SHA256 `6077B9440753BD1FBDD7A780E81C03AEA5F6212A55E1E7789A091FA6FB3B2360` and UID0000OR `92/93` at SHA256 `20A9A5E4386316C865B71306DE1FFA5EB4B70755E38133A010586D75F5E9AC30`; B007's Singleton include, Thread H, source path, `FILE` ownership, and specialization-topology conclusions remain present.
- Dated command20493 generated `Thread.cpp` SHA `1C0179E5099E00BFDBB5B7D1776878DD9EADE0D6DEF23AA62E9DBF25B53EFE93`, `13,096` bytes / `410` lines; `Thread.h` SHA `0F632951B2547EF183578B48310B5EC15C71731EEE909876A2DBC9D100C5C287`, `1,972` bytes / `76` lines.
- The same dated command20493 generated checkpoints are: `-ag-memory-coverage.md` SHA `AA9079AB934EE980C004BB3A767E2E453F290345BE957FD0EE973C157FDA8C36`, `1,430,860` bytes / `4,985` lines; `-ag-global-coverage.md` SHA `2A86C07052557F9E68FC4E00C149133086D06D3280623553568DD22048998F02`, `43,026` / `253`; `-ag-class-coverage.md` SHA `78DBE2444838747FE2C7A467D522CDA74FF1A4B1BA0A8EA2FF6763530705AD7A`, `128,418` / `653`; and `-ag-file-coverage.md` SHA `B3C72511A90424D2E021662866CE87B9ED652B459E1BBFD0CD615FD18FAD6B00`, `66,132` / `355`.
- Generated command20493 topology remains assignment-time evidence only. The ordinary callback intentionally used `--no-generated-refresh`; supervisor lifecycle-time generated readback remains authoritative after IDA/manual closure.

## Ranked Ownership Analysis

### 1. File-static global under Thread.cpp, emitted through ThreadMan

- Evidence for: zero consumers, exact ThreadMan-only lifetime writes, current module ownership, direct Singleton base, accepted specialization precedent, and no header need.
- Evidence against: `static` is not symbol-proven.
- Decision: selected. It is the narrowest sufficient linkage and most plausible historical source.

### 2. External file global under Thread.cpp

- Evidence for: current MiscWorkThread precedent uses an external global where consumers exist.
- Evidence against: no `g_pThreadMan` read/consumer exists, so external linkage adds unsupported API surface.
- Decision: rejected.

### 3. ThreadMan class-static member

- Evidence for: conceptual singleton ownership.
- Evidence against: distinct global storage, current `g_` project naming, no member access pattern, direct fieldless Singleton base.
- Decision: rejected.

### 4. Generic Singleton template static cell

- Evidence for: common modern singleton pattern in other codebases.
- Evidence against: project Singleton template is fieldless; binary has class-specific global and explicit adjusted-base publish/clear lowering.
- Decision: rejected as incompatible.

### Proposed new file/grouping, if applicable

- No new file. `Thread.cpp` remains the source unit and `Singleton.h` the reusable template dependency.
- UID0000SH emitter routing changes only generated ordering; canonical documentation ownership remains UID0000OR.

## Source Placement

- Source declaration and specializations: `NexusTK/util/Thread.cpp`.
- Reusable base declaration: existing `NexusTK/util/Singleton.h`.
- ThreadMan class source block: current UID0000EW under Thread.cpp, not a new public ThreadMan header.
- Pointer is not declared in Thread.h because no external consumer exists.
- Adjacent TimerMgr globals stay with TimerMgr source.
- Remaining uncertainty is exact original include order and lexical spacing only; neither affects placement or runtime behavior.

## Range / Split / Padding / Reclassification Analysis

- UID000305 is already the exact four-byte binary/source child and needs no documentation split. Saved IDA now models the same four-byte item; the former four sparse one-byte heads remain historical prestate, not source children.
- UID0002AR remains a non-reconstructable mixed index over three exact children.
- Predecessor `s_mouseSelectionAnchor` ends at 0x69be06; two unclassified bytes 06/07 are outside the target; UID000305 starts exactly at 08.
- UID000306 begins exactly at 0x69be0c and UID000307 at 0x69be10. `g_pfnWideOpenFile` begins at 0x69be14.
- Constructor ends at 0x596d13, followed by 13 CC bytes. Ordinary destructor is `[0x596d20,0x596d6f)`, followed by one CC byte and next wrapper at 0x596d70.
- Clear helper is `[0x5974e0,0x5974eb)`, followed by five CC bytes and scalar wrapper at 0x5974f0.
- No target range, neighbor, timer child, vtable, RTTI, or pad was absorbed. A305-01 replaced only historical heads `0x69be08-0b`; predecessor `0x69be04`, successor `0x69be0c`, and every protected range retained exact prestate.

## Negative Evidence Summary

- No consumer reads support an exported/global-header declaration.
- No class member, accessor, or generic template static storage supports class-static/generic-static forms.
- No source call targets the EH helper or scalar wrapper.
- No incoming xref reaches the constructor or raw ordinary destructor, but exact bytes/RTTI/vtable/base-order evidence resolves their roles.
- No original debug symbol proves `static`, method spellings, or local names.
- No IDA `Singleton<ThreadMan>` UDT exists; a full UDT must not be invented merely to improve decompile cosmetics.
- The historical TimerMgr scalar signature is contradicted by bytes, vtable, object size, and field offsets and has been replaced by the saved ThreadMan source prototype.
- Physical adjacency to TimerMgr globals does not prove common source ownership.
- `inspect_items.name` remains blank on the saved four-byte head, but independent entity/name/global queries resolve `g_pThreadMan` size `4`; projection blankness is not evidence that the name or data item is missing.
- Historical comment-only or `set_type`-only A305-01 alternatives would not have corrected the sparse size-1/non-data record. The saved bounded data creation did correct it without changing bytes, xrefs, or neighbors.
- Current generated source is a reconstruction checkpoint, not evidence that explicit derived assignments were original.

## IDA Rename / Type / Comment Recommendations

| Action ID | Entity | Action classification | Literal pre-action state | Applied action / current disposition | Saved current readback / acceptance | Negative constraints |
| --- | --- | --- | --- | --- | --- | --- |
| A305-01 | Logical data `[0x0069be08,0x0069be0c)`, historical sparse heads | applied / verified | AB59 names/global resolved `g_pThreadMan` with attached `ThreadMan *`, zero value/bytes, symbolic size `1`, four size-1 non-data heads, no comment, five xrefs, and no interior names/xrefs. | Supervisor created only `[08,0c)` as `ThreadMan *g_pThreadMan` with delete-existing semantics and set address-regular comment `File-static ThreadMan singleton storage published and cleared by explicit Singleton<ThreadMan> constructor/destructor specializations; adjacent dwords belong to TimerMgr.` | One exact four-byte `ThreadMan *` data item; entity/global/name queries resolve `g_pThreadMan` size `4`; zero bytes/value and five xrefs remain; exact regular comment present; repeatable absent; protected neighbors unchanged. `inspect_items.name` remains blank as an accepted projection discrepancy. | No rerun or further mutation. Preserve `[08,0c)`, predecessor/successor states, bytes, xrefs, names, comments, TimerMgr ownership, and all function state. |
| A305-02 | Function `[0x00596bf0,0x00596d13)`, size 0x123 | applied / verified | `sub_596BF0`; stale `DWORD *__thiscall(DWORD *lpParameter)`; comments absent; zero incoming xrefs. | Supervisor renamed `ThreadMan__Constructor`, applied `ThreadMan *__thiscall ThreadMan__Constructor(ThreadMan *this)`, and set exact function-regular comment `Constructs the LObject and Singleton<ThreadMan> bases, initializes debugger/watch-list state, starts the worker thread, and throws Win32Error if CreateThread fails.` | Exact range/body/no callers/name/type/comment; other channels absent; source parameter is `ThreadMan *this`; existing EH frame/comments preserved. | No rerun. Preserve internal comments, EH chunks/frame, vtable, calls, writes, bytes, and incomplete-only ThreadMan type policy. |
| A305-03 | Ordinary body `[0x00596d20,0x00596d6f)`, 0x4f bytes | applied / accepted partial analyzer state | No function/type/frame/decompile; exact 23-item body SHA256 `5D80313F89D3584FC1B6AFFA97416EAE403A863D2ABEA571D49AAA9C6A5928BD`, internal labels, zero xrefs, and protected CC fences. | Supervisor created exact function, renamed `ThreadMan__Destructor`, applied `void __thiscall ThreadMan__Destructor(ThreadMan *this)`, and set exact function-regular comment `Destroys ThreadMan-owned worker/list state; compiler-generated base teardown then clears the Singleton<ThreadMan> pointer and tail-calls LObject::~LObject.` | Exact function/range/name/type/comment, 23 items/body hash, zero callers, labels/pads/bytes protected. Hex-Rays persistently fails at `0x596d33`; analyze/disassembly/prototype/body evidence is sufficient and decompile success is not required. | Do not rerun creation, widen range, alter CC fences/wrappers/body, synthesize a frame, or pursue decompiler cosmetics. Preserve the non-decompilable state as current analyzer behavior. |
| A305-04 | Function `[0x005974e0,0x005974eb)`, size 0x0b | applied / verified | `sub_5974E0`; `void()`; comments absent; return-only frame; one EH code xref. | Supervisor renamed `ThreadMan__SingletonDestructorUnwindAction`, applied `void __cdecl ThreadMan__SingletonDestructorUnwindAction(void)`, and set exact function-regular comment `Compiler-retained constructor-unwind action for Singleton<ThreadMan>::~Singleton(); clears g_pThreadMan and is not a source helper.` | Same range/two instructions/xrefs/frame; exact name/type/comment; other channels absent; protected EH state unchanged. | No rerun. Do not assign source ownership, absorb padding, or alter constructor EH state. |
| A305-05 | Function `[0x005974f0,0x0059756e)`, size 0x7e | applied / accepted partial physical-frame state | `sub_5974F0`; stale TimerMgr declaration/frame; comments absent; one vtable xref. | Supervisor renamed `ThreadMan__ScalarDeletingDestructor`, applied `ThreadMan *__thiscall ThreadMan__ScalarDeletingDestructor(ThreadMan *this, unsigned int flags)`, renamed `+0x0c` to `flags`, and set exact function-regular comment `Compiler scalar deleting destructor generated from virtual ThreadMan::~ThreadMan(); performs ThreadMan cleanup, Singleton<ThreadMan> clear, LObject teardown, and conditional project delete.` | Exact name/type/comment/range/bytes/vtable xref; decompiler uses only `this`/`flags` and behavior is exact. Physical frame retains inert legacy `timerId +0x10`, `delayMs +0x14`, `arg0 +0x18`, `arg1 +0x1c`; `delete_stack` rejects them as argument members. | No rerun or further frame mutation. Preserve source prototype/decompiler, inert tail, internal comments, vtable, calls, flag tests, return-this behavior, bytes, and padding; do not expose as handwritten C++. |

Raw destructor item inventory for deterministic creation:

| Item | Size | Current classification / identity / comments | Instruction |
| --- | --- | --- | --- |
| `[596d20,596d21)` | 1 | code; name absent; type N/A; address-regular absent; address-repeatable absent | `push esi` |
| `[596d21,596d23)` | 2 | code; name absent; type N/A; address-regular absent; address-repeatable absent | `mov esi, ecx` |
| `[596d23,596d26)` | 3 | code; name absent; type N/A; address-regular absent; address-repeatable absent | `mov eax, [esi+8]` |
| `[596d26,596d2c)` | 6 | code; name absent; type N/A; address-regular absent; address-repeatable absent | install ThreadMan vtable |
| `[596d2c,596d2e)` | 2 | code; name absent; type N/A; address-regular absent; address-repeatable absent | `test eax, eax` |
| `[596d2e,596d30)` | 2 | code; name absent; type N/A; address-regular absent; address-repeatable absent | branch to 596d49 |
| `[596d30,596d32)` | 2 | code; name absent; type N/A; address-regular absent; address-repeatable absent | `push 0` |
| `[596d32,596d33)` | 1 | code; name absent; type N/A; address-regular absent; address-repeatable absent | `push eax` |
| `[596d33,596d39)` | 6 | code; name absent; type N/A; address-regular absent; address-repeatable absent | call `TerminateThread` |
| `[596d39,596d3c)` | 3 | code; name absent; type N/A; address-regular absent; address-repeatable absent | push handle |
| `[596d3c,596d42)` | 6 | code; name absent; type N/A; address-regular absent; address-repeatable absent | call `CloseHandle` |
| `[596d42,596d49)` | 7 | code; name absent; type N/A; address-regular absent; address-repeatable absent | clear handle |
| `[596d49,596d4c)` | 3 | code; name `loc_596D49`; type N/A; address-regular absent; address-repeatable absent | load list |
| `[596d4c,596d4e)` | 2 | code; name absent; type N/A; address-regular absent; address-repeatable absent | test list |
| `[596d4e,596d50)` | 2 | code; name absent; type N/A; address-regular absent; address-repeatable absent | branch to 596d5d |
| `[596d50,596d52)` | 2 | code; name absent; type N/A; address-regular absent; address-repeatable absent | load list vtable |
| `[596d52,596d54)` | 2 | code; name absent; type N/A; address-regular absent; address-repeatable absent | `push 1` |
| `[596d54,596d56)` | 2 | code; name absent; type N/A; address-regular absent; address-repeatable absent | call deleting destructor |
| `[596d56,596d5d)` | 7 | code; name absent; type N/A; address-regular absent; address-repeatable absent | clear list |
| `[596d5d,596d5f)` | 2 | code; name `loc_596D5D`; type N/A; address-regular absent; address-repeatable absent | `mov ecx, esi` |
| `[596d5f,596d69)` | 10 | code; name absent; type N/A; address-regular absent; address-repeatable absent | clear `g_pThreadMan` |
| `[596d69,596d6a)` | 1 | code; name absent; type N/A; address-regular absent; address-repeatable absent | `pop esi` |
| `[596d6a,596d6f)` | 5 | code; name absent; type N/A; address-regular absent; address-repeatable absent | tail jump `LObject_destructor` |

Protected readbacks outside the action table:

- Saved protected readback confirms target neighbors `s_mouseSelectionAnchor`, `g_timerTickBaselineMirror`, `g_timerCurrentTickMirror`, `g_pfnWideOpenFile`, their heads/types/names/comments/bytes/xrefs, all function ranges/pads, and every protected internal comment remained unchanged.
- A305-01 changed only historical target heads `0x69be08-0b`; saved readback confirms one containing four-byte item, entity/global name/type/size, zero bytes/value, exact comments, five target xrefs, and exact predecessor/successor states. Blank `inspect_items.name` projection is recorded rather than "fixed" by another mutation.
- Preserve vtable slot 62e2c4 and RTTI COL/CHD/base descriptors/type strings.
- Preserve constructor internal regular comments at 596c44, 596c67, 596c7b, 596cac-596cb7, 596d04, 596d09 and EH-chunk comments; preserve scalar internal comments at 5974f3, 597503, 597505, 59750c, 597530, 59754c.
- Collision queries returned zero for every proposed function name.
- A305-03 decompile failure and A305-05 retained physical-frame tail are now explicit protected poststates. Neither is an unresolved source question, and neither authorizes another IDA action.

## First-Draft C++ Recommendation

Every code block below is exact formal block insertion/replacement text, not a report-only example.

Target UID000305 CPP:

```cpp
// Exact storage and lifetime source for g_pThreadMan are emitted once by
// UID0000SH through the ThreadMan source stream; this address-only page does
// not emit a duplicate definition.
```

Target UID000305 H: blank. The target is storage evidence, not a header declaration.

UID0000EV Thread root CPP:

```cpp
#include "Thread.h"
#include "Singleton.h"

[[CHILDREN]]
```

UID0000EW ThreadMan CPP:

```cpp
class Thread;
class List;
struct ThreadManWatchRecord;

class ThreadMan : public LObject, public Singleton<ThreadMan>
{
public:
    ThreadMan();
    virtual ~ThreadMan();

    void RegisterThread(Thread *thread, void *context);
    void UnregisterThread(Thread *thread);
    void ClearThreadProbe(Thread *thread);
    void MarkCurrentThreadBlocked();
    void ClearCurrentThreadBlocked();

private:
    void RunMessagePump();

    int  FindWatchRecordByThread(Thread *thread) const;
    int  FindWatchRecordByThreadId(DWORD threadId) const;
    void ScanWatchList();
    void CheckWatchRecordTimeout(ThreadManWatchRecord *record);
    void AddWatchRecord(Thread *thread, void *context);
    void RemoveWatchRecord(Thread *thread);
    void ClearWatchRecordProbe(Thread *thread);
    void MarkThreadIdBlocked(DWORD threadId);
    void ClearThreadIdBlocked(DWORD threadId);

    bool   m_isDebuggerPresent;
    HANDLE m_workerThreadHandle;
    DWORD  m_workerThreadId;
    List  *m_watchList;
};

[[CHILDREN]]
```

UID0000EW H: blank; current ThreadMan source is translation-unit-local in the CPP stream.

UID0000SH CPP:

```cpp
static ThreadMan *g_pThreadMan = NULL;

template <>
Singleton<ThreadMan>::Singleton()
{
    g_pThreadMan = static_cast<ThreadMan *>(this);
}

template <>
Singleton<ThreadMan>::~Singleton()
{
    g_pThreadMan = NULL;
}

[[CHILDREN]]
```

UID0000SH H: blank; no external declaration is evidenced.

UID0001K0 constructor CPP:

```cpp
ThreadMan::ThreadMan()
    : m_isDebuggerPresent(false),
      m_workerThreadHandle(NULL),
      m_workerThreadId(0),
      m_watchList(NULL)
{
    HMODULE kernel32 = LoadLibraryW(L"KERNEL32.DLL");
    if (kernel32 != NULL)
    {
        typedef BOOL (WINAPI *IsDebuggerPresentProc)();
        IsDebuggerPresentProc isDebuggerPresent =
            reinterpret_cast<IsDebuggerPresentProc>(GetProcAddress(kernel32, "IsDebuggerPresent"));
        if (isDebuggerPresent != NULL)
            m_isDebuggerPresent = (isDebuggerPresent() != FALSE);
        FreeLibrary(kernel32);
    }

    m_watchList = new List(sizeof(ThreadManWatchRecord), 16);
    m_workerThreadHandle = CreateThread(NULL, 0, ThreadManWorkerEntry, this, 0, &m_workerThreadId);
    if (m_workerThreadHandle == NULL)
        throw Win32Error();
}
```

UID0001K0 H: blank; declaration remains in UID0000EW.

UID0001K1 CPP:

```cpp
ThreadMan::~ThreadMan()
{
    if (m_workerThreadHandle != NULL)
    {
        TerminateThread(m_workerThreadHandle, 0);
        CloseHandle(m_workerThreadHandle);
        m_workerThreadHandle = NULL;
    }

    if (m_watchList != NULL)
    {
        delete m_watchList;
        m_watchList = NULL;
    }
}

void ThreadMan::RegisterThread(Thread *thread, void *context)
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_REGISTER_THREAD,
                       reinterpret_cast<WPARAM>(thread),
                       reinterpret_cast<LPARAM>(context));
}

void ThreadMan::UnregisterThread(Thread *thread)
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_UNREGISTER_THREAD,
                       reinterpret_cast<WPARAM>(thread), 0);
}

void ThreadMan::ClearThreadProbe(Thread *thread)
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_CLEAR_THREAD_PROBE,
                       reinterpret_cast<WPARAM>(thread), 0);
}

void ThreadMan::MarkCurrentThreadBlocked()
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_MARK_THREAD_ID_BLOCKED,
                       GetCurrentThreadId(), 0);
}

void ThreadMan::ClearCurrentThreadBlocked()
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_CLEAR_THREAD_ID_BLOCKED,
                       GetCurrentThreadId(), 0);
}
```

UID0001K1 H: blank; declarations remain in UID0000EW.

UID0001K4 CPP/H: both blank. Exact no-code proof: the two-instruction body is referenced only by constructor EH and is generated from the Singleton base destructor specialization.

UID0001K5 CPP:

```cpp
// Compiler-emitted scalar deleting destructor for ThreadMan; generated from
// virtual ~ThreadMan(), Singleton<ThreadMan> base destruction, and the ordinary
// destructor source, so no standalone handwritten body is emitted here.
```

UID0001K5 H: blank.

UID00026P and UID0001WA formal dispositions remain covered-by/no-code comments because RTTI/layout regenerate from the class declaration.

The code is C++98-era, uses project-consistent `NULL`, explicit template specializations, Win32 types, and human class/member names. It reproduces exact execution while removing decompiler artifacts.

## Final Recommendation

- Preserve the completed ordinary callback and prior Gate 2A history. The primary supervisor later applied/saved the evidence-supported IDA actions in session `b3b2bf88`; current IDB SHA256 is `9393A7D6905B0442345F32F770575CCAA29D5F882115715A7D2C21C0429BFE96`. C305-063 through C305-076 are verified against that saved evidence under the revised A305-03/A305-05 acceptance rules.
- Do not repeat or roll back A305-01 through A305-05. Fresh Gate 2B should verify the saved poststate: accept A305-03's exact function/prototype/comment/disassembly/body with persistent Hex-Rays failure, and accept A305-05's correct source prototype/decompiler with inert physical-frame tail rejected by `delete_stack`.
- C305-002/C305-009 remain implemented and scoped-validated. The latest Gate 2A corrective callback also closes C305-004 with the exact instruction-start versus immediate-operand address distinction, historicalizes C305-025/C305-052 to the current no-edit B008 support identities, and makes C305-061 literal-equal to the accepted 46-line formal block. Fresh Gate 2A should verify only those four corrected claims while preserving prior passing ordinary work.
- Supervisor applies/verifies C305-077 through C305-093 against then-current manual files.
- Run one final supervisor-owned generated refresh only after ordinary/manual/IDA closure, then verify Thread.cpp/H topology and target coverage.
- Preserve source path `NexusTK/util/Thread.cpp`, exact storage child, mixed-index split, adjacent TimerMgr ownership, compiler-only helper/wrapper status, and all negative evidence.
- No new UID or source file is required.

## Recommended Target Doc Changes

- Ordinary callback disposition: completed and physically verified; the bullets below are retained as the exact accepted implementation record, not pending work.
- Path: `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md`.
- Score changed `87/89` to `92/94`; owner/emitter/reconstructable/range were preserved.
- Formal CPP now contains the exact covered-by marker above; H remains blank.
- Item Summary now reads: `Four-byte zero-initialized ThreadMan singleton storage with five normal-construction, normal-destruction, unwind, and deleting-destructor writes generated by explicit Singleton<ThreadMan> specializations and emitted once through UID0000SH.`
- Narrow post-save synchronization completed: target now records one four-byte `ThreadMan *` data item `[08,0c)`, entity/global `g_pThreadMan` size `4`, exact regular comment, zero bytes/value, five xrefs, blank `inspect_items.name` projection, and unchanged neighbors. Catalog0376/4A9360, B7CC, and AB59 remain dated history; current saved IDB is `9393A7D6905B0442345F32F770575CCAA29D5F882115715A7D2C21C0429BFE96`. Score, owner, emitter, formal CPP/H, range, and Item Summary remain unchanged.
- C305-004 corrective readback: ordinary Evidence/Xrefs now lists exact xref instruction starts `0x00596c33`, `0x00596c3a`, `0x00596d5f`, `0x005974e0`, and `0x00597532` separately from immediate-operand byte sites `0x00596c34`, `0x00596c3c`, `0x00596d61`, `0x005974e2`, and `0x00597534`; validator `000000020719` produced current SHA256 `0BA853B78A15032A529EF162756C4CFF703347244FF3C7805B47C76B65DDED34`.
- Claims that the derived constructor/destructor explicitly own publication/clear were retained as superseded history.

## Recommended Support Doc Changes

- Ordinary callback disposition: all report-listed support changes below are completed, scoped-validated, and physically read back.
- `by-global/g_pThreadMan.md`: now `92/94`, with exact CPP definition/specializations, blank H, owner UID0000OR unchanged, emitter UID0000EW position `1`, and full lifetime/linkage/history.
- `by-class/ThreadMan.md`: now `92/94`, with `public Singleton<ThreadMan>`, preserved methods/fields, PMD/EBO evidence, and derived-assignment correction.
- `by-class/Thread.md`: B007's `91/92` post-callback checkpoint is historical. Later accepted B008 work superseded the current no-edit page to `93/94` at SHA256 `6077B9440753BD1FBDD7A780E81C03AEA5F6212A55E1E7789A091FA6FB3B2360`; B007's `Singleton.h` CPP dependency remains present and H remains unchanged by this callback.
- `by-file/Thread.md`: B007's `91/91` post-callback checkpoint is historical. Current no-edit state is `92/93` at SHA256 `20A9A5E4386316C865B71306DE1FFA5EB4B70755E38133A010586D75F5E9AC30`, preserving `Thread.cpp`/`Thread.h`, `FILE` ownership, exact emission order, and specialization ownership.
- `by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md`: now `91/94`; only explicit publication was removed, with base-lowering/IDA-action evidence incorporated.
- `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md`: remains `90/93`; only the extra blank line between the `m_watchList` cleanup closing brace and destructor closing brace was removed in this corrective callback. The resulting 46-line formal CPP is literal-equal to the accepted report block, all executable statements/prose remain unchanged, and validator `000000020720` produced SHA256 `FD60CCEC6D95442F64DABEF9D89C0313167BF401C3060186185988F99201C909`.
- `by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md`: remains `88/92`, no owner/emitter/code, and now identifies the Singleton destructor unwind action.
- `by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`: remains `86/91` with the accepted marker/prose/IDA handoff.
- `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`: B007 originally changed `87/91` to `89/94`; later accepted B008 work superseded the current page to `90/93` while preserving exact ThreadMan CHD/base descriptors/PMD/EBO and the formal no-code marker and adding the complete Thread vtable/role assessment. Current callback disposition is no-edit at SHA256 `F152CD0A724908BB54C4E5E8D7A434B45CF90C9BD54EE13EBA522B7030D4A705`.
- `by-type/by-struct/ThreadManLayout.md`: now `90/94` with direct base at `+4`/EBO and unchanged covered-by formal marker.
- `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`: remains `88/89`; inventory/source model is updated and formal CPP/H remain blank.
- `by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md`: remains `86/88`, owner none, reconstructable false, with corrected specialization-generated lifetime wording.
- Inspect-only/no-edit UID000306, UID000307, UID0004ZK, and UID0004ZL were re-read unchanged; UID0004ZK's exact report-recorded artifact is `90/92`, not the superseded `90/94` report assertion.

## Score And Metadata Recommendation

- Completed ordinary metadata transitions, retained as assignment-to-current history:
- UID000305: `87/89` -> `92/94`; owner/emitter/reconstructable unchanged.
- UID0000SH: `88/89` -> `92/94`; canonical owner unchanged; emitter `0000OR` -> `0000EW`; position blank -> `1`.
- UID0000EW: `88/89` -> `92/94`; owner/emitter/reconstructable unchanged.
- UID0001K0: `89/89` -> `91/94`; owner/emitter unchanged.
- UID0001K1: `89/89` -> `90/93`; owner/emitter unchanged.
- UID00026P: B007 history `87/91` -> `89/94`; later B008 current state `90/93`; owner/emitter unchanged. The completion increase reflects the broader complete Thread-vtable/source assessment; the confidence decrease reflects that broader assessment's inferred private virtual spellings and unresolved separate Thread-side scalar run/broader raw-helper names, while B007's ThreadMan CHD/PMD/EBO/no-code evidence remains intact.
- UID0001WA: `86/90` -> `90/94`; owner/emitter unchanged.
- UID0000EV: B007 historical checkpoint `91/92`; later B008 current state `93/94`; no edit in this callback. The Singleton include dependency and unchanged Thread H conclusion remain current.
- UID0000OR: B007 historical checkpoint `91/91`; later accepted current state `92/93`; no edit in this callback. Thread.cpp/Thread.h path, `FILE` ownership, and specialization topology remain current.
- UID0001JX, UID0001K4, UID0001K5, UID0002AR, UID000306, UID000307, UID0004ZK, and UID0004ZL retain current metadata.
- Reason not higher: no retail symbols prove linkage/private spellings; constructor and ordinary destructor have zero callers; raw-destructor Hex-Rays remains unavailable; current IDA lacks a defensible full Singleton UDT; scalar physical frame retains inert legacy tail metadata; broader ThreadMan raw-helper names remain outside target scope.
- Reason not lower: exact four-byte binary/source and saved IDA boundaries, entity/global name/type/value/size, exact comment, zero bytes, five refs, protected neighbors, exact saved function names/types/comments/body, RTTI PMD, constructor base order, three destructor routes, object size, accepted template precedent, and generated-order solution close every assigned functional/source blocker. Persistent decompile failure and inert frame rows are documented analyzer artifacts with no runtime/source effect.
- Score-improvement work was exhaustive: linkage, base identity, raw function, EH/helper role, scalar role, adjacency, owner/emitter chain, CPP/H placement, and output order were each investigated and resolved.

## Open Questions With Attempted Resolution

- Exact original linkage: no symbol survives. Zero consumers and module-local lifetime make `static` the best defensible choice; external remains unsupported. This lexical uncertainty caps confidence but does not block source.
- Exact retail method names: no symbols survive. Project convention and class behavior support the saved IDA names; human source uses constructor/destructor syntax.
- Constructor reachability: xref/pointer/caller searches found none. RTTI/vtable/destructor convergence and exact constructor semantics still establish source role; no caller is needed to define the storage model.
- Raw destructor function model: resolved in saved IDA as exact `[0x596d20,0x596d6f)` function/name/type/comment/body. Persistent Hex-Rays failure at `0x596d33` is accepted because disassembly/analyze/prototype/body evidence is exact; no further mutation or investigation is needed.
- Singleton UDT in IDA: absent. A full type would require guessed inheritance/layout encoding, so this report intentionally does not invent it. Ordinary docs hold the source declaration.
- Physical target data item: resolved in saved IDA as one exact four-byte typed item with entity/global name size `4`, comment, zero bytes/value, and five xrefs. Blank `inspect_items.name` projection is accepted because independent name/global queries resolve correctly.
- Scalar physical frame: source prototype/decompiler are resolved to `this`/`flags`. Inert legacy tail members remain because `delete_stack` rejects them as argument members; protecting them is safer than repeated metadata mutation.
- Original header split: ThreadMan is currently emitted in Thread.cpp and has no external consumer. Moving it to Thread.h would create unsupported public surface; no split is recommended.
- Questions remaining unresolved: only original lexical spellings/include ordering. No unresolved issue affects runtime behavior, owner/emitter, source placement, formal CPP/H, or recommended scores.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Evidence-time manual identities:

- `by-memory/-coverage-report.md`: SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`, `2,134,111` bytes / `4,803` lines.
- `by-global/-coverage-report.md`: SHA256 `D54B0FBFC043E7822860CB9828896C898BA65EC66B32854CE7F9D191FA066CA1`, `100,876` bytes / `218` lines.
- `by-class/-coverage-report.md`: SHA256 `0A2F8F0BF6EF28ECB9633E504A0C2B59BCBF022B31201B33A1AAAB319B15D272`, `275,060` bytes / `625` lines.
- `by-file/-coverage-report.md`: SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66`, `166,582` bytes / `319` lines.
- `by-type/by-struct/-coverage-report.md`: SHA256 `4D576B5F0F6DE62841F0588BCA9BB710AAF023F6A2C5D68E8C423A10FFF0F7C5`, `59,348` bytes / `137` lines.
- `by-type/by-template/-coverage-report.md`: SHA256 `1A62AD2DD4F3C6F7BF94CF3BFC2AA3181B0F95601CD9062426402934FC2A1AA9`, `4,721` bytes / `30` lines.

Exact current row/anchor applicability at those evidence-time identities:

| Operation | File / line | Exact current UID anchor and disposition |
| --- | --- | --- |
| M305-01 / C305-077 | by-memory line 3687 | UID0001JX exists once at 84%; exact C305-077 replacement remains applicable. |
| M305-02 / C305-078 | by-memory line 3690 | UID0001K0 exists once at 88%; exact C305-078 replacement remains applicable. |
| M305-03 / C305-079 | by-memory line 3691 | UID0001K1 exists once at 86%; exact C305-079 replacement remains applicable. |
| M305-04 / C305-080 | by-memory line 3694 | UID0001K4 exists once as ignored 88% with generic clear-thunk wording; exact C305-080 replacement remains applicable. |
| M305-05 / C305-081 | by-memory line 3695 | UID0001K5 exists once at 84%; exact C305-081 replacement remains applicable. |
| M305-06 / C305-082 | by-memory line 4443 | UID00026P exists once with stale displayed range `0x0062e26c-0x0062e338` and 82%; exact current 90% C305-082 replacement remains applicable and must reflect B008's broader Thread-vtable assessment while preserving B007's ThreadMan CHD/PMD/EBO/no-code evidence. |
| M305-07 / C305-083 | by-memory line 4776 | UID0002AR exists once as reconstructable 80%; exact ignored 86% C305-083 replacement remains applicable. |
| M305-08 / C305-084 | by-memory line 4777 | UID000305 exists once as the child immediately after parent UID0002AR and before sibling UID000306, at 87%; exact nested replacement remains applicable. |
| M305-09 / C305-092 | by-memory line 4778 | UID000306 exists once at 88% and already matches; no mutation. |
| M305-10 / C305-093 | by-memory line 4779 | UID000307 exists once at 88% and already matches; no mutation. |
| M305-11 / C305-085 | by-global line 151 | UID0000SH exists once at 86%; exact C305-085 replacement remains applicable. |
| M305-12 / C305-086 | by-class line 559 | UID0000EV now exists once at 93%; its current row still omits the Singleton dependency, so the exact current-score text-only C305-086 replacement remains applicable. |
| M305-13 / C305-087 | by-class line 560 | UID0000EW exists once at 86%; exact C305-087 replacement remains applicable. |
| M305-14 / C305-088 | by-file line 290 | UID0000OR now exists once at 92%; its current row still omits the specialization topology, so the exact current-score text-only C305-088 replacement remains applicable. |
| M305-15 / C305-089 | by-type/by-struct line 118 | UID0001WA exists once at 85%; exact C305-089 replacement remains applicable. |
| M305-16 / C305-090 | by-type/by-template line 21 | UID0004ZL exists once at 92% and already matches; no mutation. |
| M305-17 / C305-091 | by-file line 253 | UID0004ZK exists once at 90% and already matches; no mutation. |

Line numbers are evidence-time locators only. The exact UID row text and sibling/parent anchors, not absolute line numbers, govern supervisor application after shared-file drift.

Exact supervisor replacements:

```markdown
    - [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md) 0x00596250-0x0059756e | aggregate | ThreadAndThreadMan : reconstructable : 88% : strong : Thread/ThreadMan utility-threading island attached to Thread.cpp; exact direct Singleton<ThreadMan> base and specialization lifetime model now explain singleton publication/clear, while broader raw-helper source names keep the aggregate below final-audit range.
    - [UID:0001K0][0x00596bf0-0x00596d13.ThreadManConstructor](by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md) 0x00596bf0-0x00596d13 | method | ThreadManConstructor : reconstructable : 91% : very-strong : Exact ThreadMan constructor with LObject then Singleton<ThreadMan> base lowering, debugger probe, List(20,16), worker-thread start, Win32Error failure path, and source body that relies on the Singleton specialization for pointer publication.
    - [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md) 0x00596d20-0x00596e0b | raw helpers | ThreadManRawMessageWrappers : reconstructable : 90% : very-strong : Exact ordinary ThreadMan destructor plus five PostThreadMessageW wrappers; destructor cleanup is source-authored while g_pThreadMan clear is generated by reverse Singleton<ThreadMan> base destruction.
    - [UID:0001K4][0x005974e0-0x005974eb.ClearThreadManSingleton](by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md) 0x005974e0-0x005974eb | compiler cleanup thunk | ClearThreadManSingleton : ignored : 88% : very-strong : Two-instruction constructor-unwind action generated from Singleton<ThreadMan>::~Singleton(); exact EH xref and global clear are documented with no handwritten source helper.
    - [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) 0x005974f0-0x0059756e | scalar deleting destructor | ThreadManScalarDeletingDestructor : reconstructable : 86% : very-strong : Vtable-only compiler scalar deleting destructor generated from ThreadMan::~ThreadMan(), Singleton<ThreadMan> base destruction, LObject teardown, and project delete flags; no handwritten wrapper body.
    - [UID:00026P][0x0062e268-0x0062e334.ThreadReadOnlyData](by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md) 0x0062e268-0x0062e334 | vtable/string-data | ThreadReadOnlyData : reconstructable : 90% : very-strong : Thread/ThreadMan RTTI, all fourteen exact Thread vtable cells and roles, source literals, exact ThreadMan CHD base array, Singleton<ThreadMan> PMD +4, EBO/source-base order, corrected boundaries, and compiler-emitted no-code disposition; inferred private virtual spellings and the separate Thread-side scalar run remain broader final-audit caveats.
    - [UID:0002AR][0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals](by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md) 0x0069be08-0x0069be14 | global-data cluster | ThreadTimerSingletonAndTickGlobals : ignored : 86% : strong : Reviewed non-reconstructable mixed index split into exact ThreadMan singleton storage and two TimerMgr tick-mirror children; no single source owner/emitter applies to the aggregate.
        - [UID:000305][0x0069be08-0x0069be0c.g_pThreadMan](by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md) 0x0069be08-0x0069be0c | global-data pointer storage | g_pThreadMan storage : reconstructable : 92% : very-strong : Exact file-static ThreadMan singleton storage with five specialization-generated lifecycle writes, direct Singleton<ThreadMan> PMD/base proof, and one covered-by definition through UID0000SH.
```

```markdown
- [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md) : reconstructable : 92% : very-strong : File-static Thread.cpp singleton storage emitted with explicit Singleton<ThreadMan> constructor/destructor specializations; exact four-byte child, five lifecycle writes, PMD +4 direct-base lowering, and no external/class-static/generic-static duplication.
```

```markdown
- [UID:0000EV][Thread](by-class/Thread.md) : reconstructable : 93% : very-strong : Shared worker-thread base and Thread.cpp source root with complete Thread.h declaration, Thread.cpp self-include plus Singleton.h dependency, accepted virtual/thread API and layout, and unchanged broader helper caveats.
- [UID:0000EW][ThreadMan](by-class/ThreadMan.md) : reconstructable : 92% : very-strong : Process thread manager declared as LObject plus direct empty Singleton<ThreadMan> base, with exact 0x14 layout, file-static singleton specializations, constructor/worker/destructor/wrapper behavior, and source-shaped class/method formal code under Thread.cpp.
```

```markdown
- [UID:0000OR][Thread](by-file/Thread.md) : reconstructable : 92% : very-strong : NexusTK/util/Thread.cpp plus Thread.h source root for Thread/ThreadMan, now with Singleton.h dependency, direct Singleton<ThreadMan> base, file-static g_pThreadMan definition and explicit class-specific lifetime specializations emitted before ThreadMan methods, while adjacent TimerMgr globals remain separate.
```

```markdown
- [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md) : reconstructable : 90% : very-strong : Exact 0x14 ThreadMan layout with LObject base at +0, direct empty Singleton<ThreadMan> base PMD +4 overlapping m_isDebuggerPresent through EBO, worker handle/id/list fields, constructor/destructor proof, and covered-by class emission.
```

No-change readbacks:

- UID000306 and UID000307 by-memory rows remain exact at `88%`.
- UID0004ZL template row remains exact at `92%`.
- UID0004ZK file row remains exact at `90%`.

B007 must not edit these shared manual files. The supervisor applies/rechecks the exact rows after ordinary and IDA gates.

## Follow-Up Actions

- Supervisor: perform fresh strict Gate 1 on this final ordinary-callback artifact against all 33 headings, 93 contiguous atomic claims, five IDA action entities, exact formal blocks, manual payloads, and checklist.
- Supervisor Gate 2A should verify corrected C305-004 against UID000305 SHA256 `0BA853B78A15032A529EF162756C4CFF703347244FF3C7805B47C76B65DDED34` / validator `000000020719`, C305-025 against no-edit UID0000EV `93/94` SHA256 `6077B9440753BD1FBDD7A780E81C03AEA5F6212A55E1E7789A091FA6FB3B2360`, C305-052 against no-edit UID0000OR `92/93` SHA256 `20A9A5E4386316C865B71306DE1FFA5EB4B70755E38133A010586D75F5E9AC30`, and C305-061 against UID0001K1 SHA256 `FD60CCEC6D95442F64DABEF9D89C0313167BF401C3060186185988F99201C909` / validator `000000020720`. Prior ordinary Gate 2A results remain preserved for unaffected claims.
- Supervisor Gate 2B should perform read-only saved-poststate verification against IDB SHA256 `9393A7D6905B0442345F32F770575CCAA29D5F882115715A7D2C21C0429BFE96`; do not rerun A305-01 through A305-05. Apply the revised acceptance rules for A305-03 persistent non-decompilability and A305-05 inert physical-frame tail.
- Supervisor: apply/recheck manual rows, run final generated refresh, verify Thread.cpp/H order/topology and coverage, then perform final exact gates and lifecycle action.
- No A-agent or new B-agent research is required for the resolved target. Future broader raw-helper naming is outside this report.

## Confidence

- Runtime storage/range/xref and symbolic/physical global-type confidence: very strong. The saved four-byte item, entity/global size-4 name/type, exact comment, bytes/value, five xrefs, and protected boundaries agree; blank `inspect_items.name` projection is isolated and non-authoritative.
- Saved function-action confidence: very strong. A305-02/A305-04 are exact; A305-03 is exact by function/prototype/comment/disassembly/body despite persistent Hex-Rays failure; A305-05 is exact at source prototype/comment/decompiler level despite inert physical-frame tail metadata.
- Direct base/PMD/EBO/source lifetime confidence: very strong.
- Owner/file/emitter/CPP-H confidence: very strong.
- File-static linkage and exact historical spellings: strong, evidence-backed inference.
- Scores: strong. They intentionally remain below perfect because original symbols/linkage and broader raw helper names are unavailable.

## Validator Results

- Latest Gate 2A corrective callback ran only the two authorized ordinary scoped validators, serially from `source-3/project-documentation` with `--apply --no-generated-refresh --queue-timeout 240`. UID000305 command `000000020719`, timestamp `2026-08-02T20:01:28-04:00`, exited `0` with `ok: 1` and produced SHA256 `0BA853B78A15032A529EF162756C4CFF703347244FF3C7805B47C76B65DDED34`. UID0001K1 command `000000020720`, timestamp `2026-08-02T20:01:59-04:00`, exited `0` with `ok: 1` and produced SHA256 `FD60CCEC6D95442F64DABEF9D89C0313167BF401C3060186185988F99201C909`. Both skipped generated refresh and reported normal tool-owned projected-stats update/incremental-no-op; command `000000020720` also updated UID0001K1's validator registry content hash. B007 made no manual generated/tracker/registry edit.
- The authorized C305-002/C305-009 callback ran two serial scoped UID000305 validators with `--apply --no-generated-refresh --queue-timeout 240`. Command `000000020658`, timestamp `2026-08-01T09:27:40-04:00`, exited `0` with `ok: 1` after the saved-poststate synchronization. A final readback found one dated AB59 change-log sentence still using unqualified `current`; B007 changed it to explicit `then-current` historical wording and reran command `000000020663`, timestamp `2026-08-01T09:32:31-04:00`, exit `0`, `ok: 1`, generated refresh skipped, final SHA256 `D0830DFFC6BF036F3E0521B6CC27AF4657230D272E38965061CFC1638B114407`. Both validator runs reported the normal tool-owned `projected_stats_update: 1` and `stats_incremental_noop: 1`; B007 did not manually edit or inspect the projected stats file. Historical commands remain exact evidence.
- Initial report-only phase: no validator was run, as required.
- Accepted ordinary callback: all commands ran serially from `source-3/project-documentation` with `--apply --no-generated-refresh --queue-timeout 240`; every command exited `0`, reported `ok: 1`, and reported `generated_refresh: skipped`.

| Command ID | Timestamp | Scoped file | Result | Post-validation SHA256 |
| --- | --- | --- | --- | --- |
| `000000020512` | `2026-08-01T04:31:45-04:00` | `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md` | exit 0; ok 1 | `1D2BD8D9F6D5EE0155D7C14300579B85C73A808F48379FDF81E146D496EED7AE` |
| `000000020513` | `2026-08-01T04:33:03-04:00` | `by-global/g_pThreadMan.md` | exit 0; ok 1 | `82C774125464BE1AEAB025860947941F3BB1322D3725F1A8DDD342A8115D2941` |
| `000000020514` | `2026-08-01T04:34:28-04:00` | `by-class/ThreadMan.md` | exit 0; ok 1; five pre-existing UID0003V7 reference warnings | `0CA2A8861A38F3EFEE65A3DB9876189DA20DC8B3A5D33EDC25B765A97DB58B71` |
| `000000020515` | `2026-08-01T04:35:09-04:00` | `by-class/Thread.md` | exit 0; ok 1; two pre-existing UID0003GY reference warnings | `7644037E0F4FB0BCC3FFD25392FD72727C8642AB1AB1234CC79D06EC0A11D52F` |
| `000000020516` | `2026-08-01T04:35:57-04:00` | `by-file/Thread.md` | exit 0; ok 1; six pre-existing UID0003V7/UID0003GY reference warnings | `C37D373B94C2F44DE1DBE53A78C561D2066F0E8C190040E9FFCA653EF239EDF5` |
| `000000020517` | `2026-08-01T04:37:10-04:00` | `by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md` | exit 0; ok 1 | `540C50C962844DE88C0E0CEBA78B34EC6815945F93B982C677936CB67F1EF00F` |
| `000000020518` | `2026-08-01T04:38:35-04:00` | `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md` | exit 0; ok 1 | `6DD6D814479195AF8847F88FC4BDF9E07A093EB0675C3AF824EA4FFE1BA49248` |
| `000000020519` | `2026-08-01T04:39:40-04:00` | `by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md` | exit 0; ok 1 | `69B649D939DE0D270BCE19262C8B5860655E140BC01E0F4AD76255E7C9FF7F6E` |
| `000000020520` | `2026-08-01T04:43:04-04:00` | `by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md` | exit 0; ok 1 | `A58ACE8A5E91B35D6E2053AEE337C3F6D1856AA92567D2F750F8B6010DC2028F` |
| `000000020521` | `2026-08-01T04:45:08-04:00` | `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md` | exit 0; ok 1 | `7B18D27C965C37A0250BD546BC4DAAC3D900061CD0B08483AB7C72F7E65314F2` |
| `000000020522` | `2026-08-01T04:46:04-04:00` | `by-type/by-struct/ThreadManLayout.md` | exit 0; ok 1; stats rescore recommendation only | `26DF2964DEA244B1A54E6387ED0799CC9A676C26ADA092CF56499067DF9C51E3` |
| `000000020523` | `2026-08-01T04:47:26-04:00` | `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md` | exit 0; ok 1; five pre-existing UID0003V7 reference warnings | `A893DECE5A058DDF5BED73415D58862D514C29E7382678B7BBBDB325EF982B63` |
| `000000020524` | `2026-08-01T04:48:19-04:00` | `by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md` | exit 0; ok 1; canonical UID link normalized | `D7AEDE18DC14E655FA1365CFCBB87F787FE1A4965057E3631728281F399B3C8F` |
| `000000020618` | `2026-08-01T08:27:06-04:00` | `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md` | Gate 2A repair; exit 0; ok 1; generated refresh skipped | `A5A91EB147F66FC594EFEDCEC5D2D1726100059486D10763043CA54C2B2779CF` |
| `000000020658` | `2026-08-01T09:27:40-04:00` | `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md` | post-Gate2B C305-002/C305-009 sync; exit 0; ok 1; generated refresh skipped | `14D515EE5DD91A91625AEE3D885C2B16C1FADFFA76F50BB2E665706D16D86D30` |
| `000000020663` | `2026-08-01T09:32:31-04:00` | `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md` | final C305-009 historical-currentness wording; exit 0; ok 1; generated refresh skipped | `D0830DFFC6BF036F3E0521B6CC27AF4657230D272E38965061CFC1638B114407` |
| `000000020719` | `2026-08-02T20:01:28-04:00` | `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md` | C305-004 exact xref-start/immediate-site distinction; exit 0; ok 1; generated refresh skipped | `0BA853B78A15032A529EF162756C4CFF703347244FF3C7805B47C76B65DDED34` |
| `000000020720` | `2026-08-02T20:01:59-04:00` | `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md` | C305-061 extra blank-line removal; exact 46-line formal CPP; exit 0; ok 1; generated refresh skipped | `FD60CCEC6D95442F64DABEF9D89C0313167BF401C3060186185988F99201C909` |

- UID00026P was physically re-read during this repair as no-edit/current `90/93`, SHA256 `F152CD0A724908BB54C4E5E8D7A434B45CF90C9BD54EE13EBA522B7030D4A705`, `26,942` bytes / `177` lines. Latest no-edit support readback also confirms UID0000EV `93/94`, SHA256 `6077B9440753BD1FBDD7A780E81C03AEA5F6212A55E1E7789A091FA6FB3B2360`, `31,749` bytes / `337` lines, and UID0000OR `92/93`, SHA256 `20A9A5E4386316C865B71306DE1FFA5EB4B70755E38133A010586D75F5E9AC30`, `46,114` / `264`. UID000306, UID000307, UID0004ZK, and UID0004ZL remain inspect-only/no-edit supports; UID0004ZK's recorded hash is literal `90/92`, and the earlier report-only `90/94` reading is superseded.
- Generated refresh remains supervisor-owned after Gate 2/manual closure.

## Changed Files

- Latest Gate 2A corrective callback directly changed only UID000305, UID0001K1, and this same report. UID000305 changed from SHA256 `D0830DFFC6BF036F3E0521B6CC27AF4657230D272E38965061CFC1638B114407` (`13,990` bytes / `102` lines) to scoped-validated SHA256 `0BA853B78A15032A529EF162756C4CFF703347244FF3C7805B47C76B65DDED34` (`14,342` / `103`) by adding the exact instruction-start/immediate-site distinction. UID0001K1 changed from SHA256 `6DD6D814479195AF8847F88FC4BDF9E07A093EB0675C3AF824EA4FFE1BA49248` (`21,494` / `185`) to scoped-validated SHA256 `FD60CCEC6D95442F64DABEF9D89C0313167BF401C3060186185988F99201C909` (`21,493` / `184`) by removing one extra formal-CPP blank line. No executable statement or other ordinary prose changed.
- UID0000EV and UID0000OR were read only and not edited. Their current later-B008 identities are UID0000EV `93/94`, SHA256 `6077B9440753BD1FBDD7A780E81C03AEA5F6212A55E1E7789A091FA6FB3B2360`, `31,749` bytes / `337` lines, and UID0000OR `92/93`, SHA256 `20A9A5E4386316C865B71306DE1FFA5EB4B70755E38133A010586D75F5E9AC30`, `46,114` / `264`. B007's earlier `91/92` and `91/91` identities below remain dated callback history only.
- The latest scoped validators reported normal tool-owned registry/projected-stats side effects and skipped generated refresh. B007 made no manual coverage/generated/tracker/registry/audit/catalog/lifecycle/goal/notes edit, did not access or mutate IDA, and did not run/probe `execute_report`.
- Prior C305-002/C305-009 callback directly changed only UID000305 and this same report. UID000305 changed from SHA256 `A5A91EB147F66FC594EFEDCEC5D2D1726100059486D10763043CA54C2B2779CF` (`12,623` bytes / `97` lines) through initial synchronization SHA256 `14D515EE5DD91A91625AEE3D885C2B16C1FADFFA76F50BB2E665706D16D86D30` (`13,893` / `102`) to scoped-validated SHA256 `D0830DFFC6BF036F3E0521B6CC27AF4657230D272E38965061CFC1638B114407` (`13,990` / `102`) after the historical-currentness wording correction. This is dated history, not the current target identity.
- This Gate 2B reconciliation changed only this same report. B007 did not access or mutate IDA and did not edit any ordinary/manual/generated/audit/catalog/lifecycle/goal/notes file or run any validator. The supervisor-provided external saved evidence is IDB SHA256 `9393A7D6905B0442345F32F770575CCAA29D5F882115715A7D2C21C0429BFE96`, `143,193,592` bytes, last write `2026-08-01T08:57:14.5891696-04:00`; it is evidence, not a file changed by this repair.
- Latest Gate 2A repair from failed exact report SHA256 `04DD9EABCC64E184D7676CA4F98D6959730C9CFCDD9CD63409316F621100802C` modified only UID000305 and this same report, additively. UID000305 changed from SHA256 `1D2BD8D9F6D5EE0155D7C14300579B85C73A808F48379FDF81E146D496EED7AE` (`10,522` bytes / `90` lines) to validated SHA256 `A5A91EB147F66FC594EFEDCEC5D2D1726100059486D10763043CA54C2B2779CF` (`12,623` / `97`). UID00026P was not edited and is currently SHA256 `F152CD0A724908BB54C4E5E8D7A434B45CF90C9BD54EE13EBA522B7030D4A705` (`26,942` / `177`) after later accepted B008 work.
- Earlier Gate 1 repair from failed SHA256 `05A03F3B7C2E38074915BD86B96117E883DA938BB5D991BADFF2ABBB8329666E` modified only this same report, additively; its then-current ordinary identities below are retained as dated callback history.
- Initial report-only phase created `tools/leaser/Agents/Agent-B007/research/000305-g_pThreadMan-source-quality.md`; the accepted callback updated that same report additively rather than replacing its research.
- Ordinary callback manually modified exactly the thirteen report-listed by-* documents below. No manual generated/tracker/stats/coverage, IDA/audit/catalog/lifecycle, goal, or notes edit was made by B007. Scoped validator operation produced its normal validator-owned registry/projected-stats side effects while every command explicitly skipped generated refresh; those tool-owned side effects are not claimed as ordinary callback destinations.
- Evidence-time ordinary identities:
  - UID000305 `8A5E67AF4BF42F2A8F92F6458E6BCA39D563B3A694ECF55BD43AD8C6AA3E3CC3`, `7,119` bytes / `75` lines.
  - UID0000SH `C1D72757A61FF1100C352534D5FBD4E569E1298C4B330DAEF67E6E0875A51DEF`, `11,647` / `102`.
  - UID0000EW `BC8086FE451AA13387B73EFFA40209C4594BE723DDB4FFD3A367F67401D4B62D`, `23,727` / `200`.
  - UID0000EV `8FEA276F90FD1E23B4075CE68F0B2ABA42EA677DB4DCDA8E0B45F50F3882B383`, `26,432` / `290`.
  - UID0000OR `0B8735BD156F4DD2A352E2C47A772E202EDB97F2898884F5FC4E8015BD341BBC`, `40,633` / `240`.
  - UID0001JX `80EE03275F3F74A85508460316A97D5ED82E1AF8376E58C0BD057DD586F43DC0`, `35,058` / `194`.
  - UID0001K0 `4F493D631568060C4A2AF6496F87297278A30602D70E0FDF540ECA6428EB1D6F`, `14,196` / `143`.
  - UID0001K1 `0DD5497B15E928430157779E448590F43F1250CEC29D6799785A9F31F8D60472`, `19,835` / `177`.
  - UID0001K4 `5907B9B084FDCC2D00EE26DD2266BD0680229DD5AFD7B5969EE029A550AA472D`, `7,592` / `75`.
  - UID0001K5 `74FF2D0E7E75B66538C42EAAB11E82F056E15C876EFBDCE8CC43567D9EC9EE94`, `23,140` / `199`.
  - UID00026P `A586EB88FF147B75FA5D7ACA920A6283B8A176C9661BBF681CDD2A9D4ADAA36E`, `21,156` / `152`.
  - UID0001WA `01F6C99CC2F2FA751C23CE20AADFDA0C19956BB47681A910422DF302E9C34B1B`, `10,906` / `87`.
  - UID0002AR `5C1A536F5058064B83D3FCA0825F3EFABDCE7B1238F8D595DB2431E75218F6A3`, `8,700` / `83`.
  - UID000306 `403B1212EE5B8A56F0B0C4EC9F08F05A11D507882687EDBC4BC020D3EF4B4A66`, `5,484` / `67`.
  - UID000307 `48CEB9B21E0F5177618FF7EEBC0B2E09929EE6B2B4AA89BAD25C1BE6FF8F9297`, `5,554` / `67`.
  - UID0004ZL `09490F6719F2DDDC8FB22D6F73EB1DBE28FC68410DF03F144DD93CBC47966FCF`, `5,456` / `84`.
  - UID0004ZK `9B16D9AA46FAC29A54BAC833ADD68B258A747DC8831B96B35CD0ED241B521D30`, `5,531` / `65`.
- Dated verified post-callback ordinary identities from B007's initial callback:
  - UID000305 `1D2BD8D9F6D5EE0155D7C14300579B85C73A808F48379FDF81E146D496EED7AE`, `10,522` bytes / `90` lines.
  - UID0000SH `82C774125464BE1AEAB025860947941F3BB1322D3725F1A8DDD342A8115D2941`, `15,563` / `144`.
  - UID0000EW `0CA2A8861A38F3EFEE65A3DB9876189DA20DC8B3A5D33EDC25B765A97DB58B71`, `26,496` / `210`.
  - UID0000EV `7644037E0F4FB0BCC3FFD25392FD72727C8642AB1AB1234CC79D06EC0A11D52F`, `27,219` / `297`.
  - UID0000OR `C37D373B94C2F44DE1DBE53A78C561D2066F0E8C190040E9FFCA653EF239EDF5`, `42,654` / `248`.
  - UID0001JX `A893DECE5A058DDF5BED73415D58862D514C29E7382678B7BBBDB325EF982B63`, `37,073` / `198`.
  - UID0001K0 `540C50C962844DE88C0E0CEBA78B34EC6815945F93B982C677936CB67F1EF00F`, `16,846` / `150`.
  - UID0001K1 `6DD6D814479195AF8847F88FC4BDF9E07A093EB0675C3AF824EA4FFE1BA49248`, `21,494` / `185`.
  - UID0001K4 `69B649D939DE0D270BCE19262C8B5860655E140BC01E0F4AD76255E7C9FF7F6E`, `9,193` / `82`.
  - UID0001K5 `A58ACE8A5E91B35D6E2053AEE337C3F6D1856AA92567D2F750F8B6010DC2028F`, `25,540` / `208`.
  - UID00026P `7B18D27C965C37A0250BD546BC4DAAC3D900061CD0B08483AB7C72F7E65314F2`, `23,178` / `162` (B007's then-current `89/94` post-callback artifact; later superseded by accepted B008 work).
  - UID0001WA `26DF2964DEA244B1A54E6387ED0799CC9A676C26ADA092CF56499067DF9C51E3`, `12,526` / `92`.
  - UID0002AR `D7AEDE18DC14E655FA1365CFCBB87F787FE1A4965057E3631728281F399B3C8F`, `9,842` / `85`.
- Verified unchanged inspect-only identities: UID000306 `403B1212EE5B8A56F0B0C4EC9F08F05A11D507882687EDBC4BC020D3EF4B4A66`, `5,484` / `67`; UID000307 `48CEB9B21E0F5177618FF7EEBC0B2E09929EE6B2B4AA89BAD25C1BE6FF8F9297`, `5,554` / `67`; UID0004ZL `09490F6719F2DDDC8FB22D6F73EB1DBE28FC68410DF03F144DD93CBC47966FCF`, `5,456` / `84`; UID0004ZK `9B16D9AA46FAC29A54BAC833ADD68B258A747DC8831B96B35CD0ED241B521D30`, `5,531` / `65`.
- The report's exact post-reconciliation identity is returned with the callback handoff because embedding its own SHA256 would change that identity.
- Report lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the current report path and validator-owned status/history. B007 must never run/probe `execute_report`, move/archive the report, or perform equivalent lifecycle work.

## Implementation Tracking Checklist

This claim-isomorphic checklist supersedes only the earlier grouped checklist. All research, callback, validator, Gate 1/Gate 2, IDA, and historical evidence remains preserved in the corresponding report sections above. Each entry copies its destination, action, and state from the Claim And Incorporation Ledger; checked state means `verified`, while unchecked state remains supervisor-owned `proposed` work.

1. [x] `C305-001` | Destination: `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md` Status/Evidence | Action: `incorporate` | State: `verified`.
2. [x] `C305-002` | Destination: target Status/Evidence post-Gate2B sync | Action: `incorporate` | State: `verified`.
3. [x] `C305-003` | Destination: target Evidence | Action: `incorporate` | State: `verified`.
4. [x] `C305-004` | Destination: target Evidence/Xrefs exact instruction-start/operand-site distinction | Action: `incorporate` | State: `verified`.
5. [x] `C305-005` | Destination: target Reconstruction Notes | Action: `incorporate` | State: `verified`.
6. [x] `C305-006` | Destination: target metadata/formal CPP | Action: `already-present` | State: `verified`.
7. [x] `C305-007` | Destination: target metadata/Score Rationale | Action: `incorporate` | State: `verified`.
8. [x] `C305-008` | Destination: target Item Summary | Action: `incorporate` | State: `verified`.
9. [x] `C305-009` | Destination: target historical Evidence plus report current poststate | Action: `historicalize` | State: `verified`.
10. [x] `C305-010` | Destination: target formal CPP/H | Action: `incorporate` | State: `verified`.
11. [x] `C305-011` | Destination: `by-global/g_pThreadMan.md` formal CPP | Action: `incorporate` | State: `verified`.
12. [x] `C305-012` | Destination: by-global formal CPP | Action: `incorporate` | State: `verified`.
13. [x] `C305-013` | Destination: by-global formal CPP | Action: `incorporate` | State: `verified`.
14. [x] `C305-014` | Destination: by-global metadata/Ownership | Action: `already-present` | State: `verified`.
15. [x] `C305-015` | Destination: by-global metadata | Action: `incorporate` | State: `verified`.
16. [x] `C305-016` | Destination: by-global metadata/Score | Action: `incorporate` | State: `verified`.
17. [x] `C305-017` | Destination: by-global formal H | Action: `already-present` | State: `verified`.
18. [x] `C305-018` | Destination: by-global Evidence/Ownership/Changes | Action: `historicalize` | State: `verified`.
19. [x] `C305-019` | Destination: `by-class/ThreadMan.md` formal CPP | Action: `incorporate` | State: `verified`.
20. [x] `C305-020` | Destination: by-class formal CPP | Action: `already-present` | State: `verified`.
21. [x] `C305-021` | Destination: by-class metadata/Score | Action: `incorporate` | State: `verified`.
22. [x] `C305-022` | Destination: by-class metadata/formal H | Action: `already-present` | State: `verified`.
23. [x] `C305-023` | Destination: by-class Evidence/Reconstruction | Action: `historicalize` | State: `verified`.
24. [x] `C305-024` | Destination: `by-class/Thread.md` formal CPP | Action: `incorporate` | State: `verified`.
25. [x] `C305-025` | Destination: by-class Thread current metadata/formal CPP/H inspection | Action: `not-applicable` | State: `verified`.
26. [x] `C305-026` | Destination: constructor formal CPP | Action: `incorporate` | State: `verified`.
27. [x] `C305-027` | Destination: constructor formal CPP/prose | Action: `already-present` | State: `verified`.
28. [x] `C305-028` | Destination: constructor metadata/Score | Action: `incorporate` | State: `verified`.
29. [x] `C305-029` | Destination: constructor metadata/formal H | Action: `already-present` | State: `verified`.
30. [x] `C305-030` | Destination: constructor Evidence/History | Action: `historicalize` | State: `verified`.
31. [x] `C305-031` | Destination: raw-wrapper formal CPP | Action: `incorporate` | State: `verified`.
32. [x] `C305-032` | Destination: raw-wrapper formal CPP/prose | Action: `already-present` | State: `verified`.
33. [x] `C305-033` | Destination: raw-wrapper metadata/Score | Action: `incorporate` | State: `verified`.
34. [x] `C305-034` | Destination: raw-wrapper Evidence/Inventory | Action: `incorporate` | State: `verified`.
35. [x] `C305-035` | Destination: clear-helper metadata/formals | Action: `already-present` | State: `verified`.
36. [x] `C305-036` | Destination: clear-helper Summary/Evidence | Action: `incorporate` | State: `verified`.
37. [x] `C305-037` | Destination: clear-helper metadata | Action: `already-present` | State: `verified`.
38. [x] `C305-038` | Destination: scalar formal CPP/H | Action: `already-present` | State: `verified`.
39. [x] `C305-039` | Destination: scalar formal CPP/Evidence | Action: `incorporate` | State: `verified`.
40. [x] `C305-040` | Destination: scalar metadata | Action: `already-present` | State: `verified`.
41. [x] `C305-041` | Destination: ThreadReadOnlyData RTTI/Evidence | Action: `incorporate` | State: `verified`.
42. [x] `C305-042` | Destination: ThreadReadOnlyData Reconstruction | Action: `incorporate` | State: `verified`.
43. [x] `C305-043` | Destination: ThreadReadOnlyData metadata/score/history inspection | Action: `not-applicable` | State: `verified`.
44. [x] `C305-044` | Destination: `by-type/by-struct/ThreadManLayout.md` Layout/Notes | Action: `incorporate` | State: `verified`.
45. [x] `C305-045` | Destination: ThreadManLayout metadata/formal | Action: `incorporate` | State: `verified`.
46. [x] `C305-046` | Destination: ThreadAndThreadMan Inventory/Evidence | Action: `incorporate` | State: `verified`.
47. [x] `C305-047` | Destination: ThreadAndThreadMan metadata/formal | Action: `already-present` | State: `verified`.
48. [x] `C305-048` | Destination: mixed-index metadata/Rebuild Notes | Action: `already-present` | State: `verified`.
49. [x] `C305-049` | Destination: mixed-index prose/manual row | Action: `incorporate` | State: `verified`.
50. [x] `C305-050` | Destination: baseline child inspection | Action: `not-applicable` | State: `verified`.
51. [x] `C305-051` | Destination: current-tick child inspection | Action: `not-applicable` | State: `verified`.
52. [x] `C305-052` | Destination: by-file Thread current Status/metadata/topology inspection | Action: `not-applicable` | State: `verified`.
53. [x] `C305-053` | Destination: by-file Thread Contents/Evidence | Action: `incorporate` | State: `verified`.
54. [x] `C305-054` | Destination: SingletonTemplate inspection | Action: `already-present` | State: `verified`.
55. [x] `C305-055` | Destination: Singleton file inspection | Action: `not-applicable` | State: `verified`.
56. [x] `C305-056` | Destination: target formal CPP | Action: `incorporate` | State: `verified`.
57. [x] `C305-057` | Destination: by-global formal CPP | Action: `incorporate` | State: `verified`.
58. [x] `C305-058` | Destination: by-class ThreadMan formal CPP | Action: `incorporate` | State: `verified`.
59. [x] `C305-059` | Destination: by-class Thread formal CPP | Action: `incorporate` | State: `verified`.
60. [x] `C305-060` | Destination: constructor formal CPP | Action: `incorporate` | State: `verified`.
61. [x] `C305-061` | Destination: raw-wrapper formal CPP exact 46-line block | Action: `incorporate` | State: `verified`.
62. [x] `C305-062` | Destination: scalar formal CPP | Action: `incorporate` | State: `verified`.
63. [x] `C305-063` | Destination: Supervisor Gate 2B `0x0069be08` | Action: `incorporate` | State: `verified`.
64. [x] `C305-064` | Destination: Supervisor Gate 2B `0x00596bf0` | Action: `incorporate` | State: `verified`.
65. [x] `C305-065` | Destination: Supervisor Gate 2B `0x00596bf0` | Action: `incorporate` | State: `verified`.
66. [x] `C305-066` | Destination: Supervisor Gate 2B `0x00596bf0` | Action: `incorporate` | State: `verified`.
67. [x] `C305-067` | Destination: Supervisor Gate 2B `0x00596d20` | Action: `incorporate` | State: `verified`.
68. [x] `C305-068` | Destination: Supervisor Gate 2B `0x00596d20` | Action: `incorporate` | State: `verified`.
69. [x] `C305-069` | Destination: Supervisor Gate 2B `0x00596d20` | Action: `incorporate` | State: `verified`.
70. [x] `C305-070` | Destination: Supervisor Gate 2B `0x005974e0` | Action: `incorporate` | State: `verified`.
71. [x] `C305-071` | Destination: Supervisor Gate 2B `0x005974e0` | Action: `incorporate` | State: `verified`.
72. [x] `C305-072` | Destination: Supervisor Gate 2B `0x005974e0` | Action: `incorporate` | State: `verified`.
73. [x] `C305-073` | Destination: Supervisor Gate 2B `0x005974f0` | Action: `incorporate` | State: `verified`.
74. [x] `C305-074` | Destination: Supervisor Gate 2B `0x005974f0` | Action: `incorporate` | State: `verified`.
75. [x] `C305-075` | Destination: Supervisor Gate 2B `0x005974f0` | Action: `incorporate` | State: `verified`.
76. [x] `C305-076` | Destination: Supervisor Gate 2B protected set | Action: `already-present` | State: `verified`.
77. [ ] `C305-077` | Destination: `by-memory/-coverage-report.md` UID0001JX | Action: `incorporate` | State: `proposed`.
78. [ ] `C305-078` | Destination: by-memory manual UID0001K0 | Action: `incorporate` | State: `proposed`.
79. [ ] `C305-079` | Destination: by-memory manual UID0001K1 | Action: `incorporate` | State: `proposed`.
80. [ ] `C305-080` | Destination: by-memory manual UID0001K4 | Action: `incorporate` | State: `proposed`.
81. [ ] `C305-081` | Destination: by-memory manual UID0001K5 | Action: `incorporate` | State: `proposed`.
82. [ ] `C305-082` | Destination: by-memory manual UID00026P | Action: `incorporate` | State: `proposed`.
83. [ ] `C305-083` | Destination: by-memory manual UID0002AR | Action: `incorporate` | State: `proposed`.
84. [ ] `C305-084` | Destination: by-memory manual UID000305 | Action: `incorporate` | State: `proposed`.
85. [ ] `C305-085` | Destination: `by-global/-coverage-report.md` UID0000SH | Action: `incorporate` | State: `proposed`.
86. [ ] `C305-086` | Destination: `by-class/-coverage-report.md` UID0000EV | Action: `incorporate` | State: `proposed`.
87. [ ] `C305-087` | Destination: by-class manual UID0000EW | Action: `incorporate` | State: `proposed`.
88. [ ] `C305-088` | Destination: `by-file/-coverage-report.md` UID0000OR | Action: `incorporate` | State: `proposed`.
89. [ ] `C305-089` | Destination: `by-type/by-struct/-coverage-report.md` UID0001WA | Action: `incorporate` | State: `proposed`.
90. [ ] `C305-090` | Destination: `by-type/by-template/-coverage-report.md` UID0004ZL | Action: `already-present` | State: `proposed`.
91. [ ] `C305-091` | Destination: `by-file/-coverage-report.md` UID0004ZK | Action: `already-present` | State: `proposed`.
92. [ ] `C305-092` | Destination: `by-memory/-coverage-report.md` UID000306 | Action: `already-present` | State: `proposed`.
93. [ ] `C305-093` | Destination: `by-memory/-coverage-report.md` UID000307 | Action: `already-present` | State: `proposed`.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000020735","destination_path":"executed-b-agent-research/B007/000305-g_pThreadMan-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/000305-g_pThreadMan-source-quality.md","timestamp":"2026-08-02T20:48:26-04:00","uid":"000305"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
