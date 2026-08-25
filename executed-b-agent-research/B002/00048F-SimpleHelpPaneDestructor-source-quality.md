** TARGET-REPORT-UID:00048F **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00048F SimpleHelpPane Destructor Ownership / Split Research


## Finalized Report / Current Recommendation

- Current callback-complete recommendation: [UID:00048F] remains the exact ordinary `SimpleHelpPane` destructor child at applied `92/94`, semantic owner/emitter [UID:0000D6], `RECONSTRUCTABLE:TRUE`, source position `20`, and Destination 1 formal body.
- Final disposition: this is source-authored ordinary-destructor material. Its only authored statement releases the copied wide-character array. The derived-vptr stores, Singleton-base clear, `Pane` teardown, SEH frame, stack-cookie checks, adjustor thunks, deleting flags, object-storage free, and guarded-size path are compiler/base effects and are not handwritten in UID00048F.
- Completed callback: Destinations 1-6 and prose/metadata Destinations 7-8 are applied. UID0000D6 now declares `SimpleHelpPane : public Pane, public Singleton<SimpleHelpPane>`; UID00048E initializes the Singleton base; exact methods emit in `10/20/30/40/50/60` order; UID0003YZ is non-emitting compiler coverage; and UID000228 no longer defines duplicate singleton storage.
- Confidence: very strong. Live IDA fixes the complete range, all 40 instructions, the only source conditional, three direct callees, three vtable views, `Singleton<SimpleHelpPane>` at `+0xf8`, `wchar_t *` ownership at the same EBO offset, exact size `0xfc`, singleton-clear order, scalar-wrapper route, and both padding spans. Missing original headers/symbols cap confidence below `95`.

## Supporting Research

- Evidence-time assignment: report-only Rule 26 research from validator command `000000011445`, tracker section `by-memory / Not-Covered Files - Reconstructable`, for exact UID00048F. No direct exact-range report existed when that pass began. The supervisor subsequently accepted exact report SHA `AB6412EB61B6D26C88910A735CD7201A70F7505F75D965CE35A453B8D5F25873` and authorized the bounded implementation callback now recorded here.
- Mandatory MCP recovery: a fresh streamable MCP initialization produced transport session `9bc2d862-9689-4ed0-9d63-e15b92cffab0`; fresh `idb_list` returned active NexusTK database `e98ecbb2`. Evidence-time `server_health` was `ok`, module image base was `0x00400000`, auto-analysis/Hex-Rays/string caches were ready, and a bounded target read at `0x004c7290` succeeded. These are evidence-collection-time observations, not an assertion of future session availability.
- Final evidence recheck at `2026-07-14T11:38:15-04:00`: fresh `idb_list` still returned only active/adopted session `e98ecbb2`, `server_health` returned `ok` with analysis/Hex-Rays/strings ready, and bounded `get_bytes(0x004c7290,16)` returned the target prologue. No stale database ID or offline fallback evidence was used.
- Search terms used verbatim: `UID00048F`, `00048F`, `0x004c7290`, `0x004c7307`, `SimpleHelpPaneDestructor`, `SimpleHelpPane::~SimpleHelpPane`, `UID0003YZ`, `0x004ce560`, `UID00016S`, `SimpleHelpPane`, `m_textBuffer`, `m_copiedTextBuffer`, `g_pSimpleHelpPane`, and `HelpPanes`.
- Central executed root searched: `executed-b-agent-research/`. Exact matches opened were `B007/00016S-SimpleHelpPanes-source-quality.md`, `B011/00048E-SimpleHelpPaneConstructor-source-quality.md`, `B003/00016W-help-tooltip-destructor-thunks-source-quality.md`, `B001/000228-help-pane-singleton-close-source-quality.md`, `B004/0000JU-HelpPanes-empty-emitter-family-source-quality.md`, and `B002/00048I-SimpleHelpPaneOnTimerEvent-source-quality.md`. None is a countable direct UID00048F report. They are family split, constructor, compiler-wrapper, helper, file-emitter, and sibling-handler support/history respectively.
- Legacy executed roots searched: every `archived/b-agent-reports-20260623/Agent-B*/research/executed/` root, including each `executed/older/` subtree. Outcome: no direct UID00048F report and no additional exact-target artifact.
- Archived roots searched: `archived/b-agent-reports-20260623/`, `archived/duplicate-loose-b-agent-reports/`, and `tools/leaser/Agents/Older-Research/`. Outcome: no direct UID00048F report; no stronger exact-target artifact was found.
- Active roots searched: `tools/leaser/Agents/Agent-B001/research/` through `Agent-B015/research/`. Outcome: no active exact UID00048F report or conflicting target assignment. B001-B005 are collision-free for this target; later-agent roots also returned no exact-term match.
- Adopted support finding from B007/B011/B003: the exact ordinary range is a source child, the constructor owns a copied UTF-16 buffer, and UID0003YZ is compiler deleting-destructor glue. Evidence-time live analysis independently revalidated each claim and corrected their source-shape gap: the singleton publish/clear belongs to the explicit empty Singleton base, not handwritten constructor/destructor assignments.
- Comparator finding: current accepted `IdleWatcher` and `BrowserDialog` documentation records the same MSVC pattern: an empty `Singleton<T>` base at a derived-tail offset, constructor publication, ordinary/scalar clears, and source method bodies that do not duplicate singleton lifecycle statements. Live `e98ecbb2` decompilation of `IdleWatcher::~IdleWatcher` at `0x004cfec0` independently reproduced the vptr-store, singleton-clear, base-destructor sequence.
- Lifecycle neutrality: B002 research, ordinary-page edits, scoped validators, waited generated verification, and lease release are complete. Current/future report validation, execution, movement, archiving, and manual coverage state remain external supervisor/validator-owned and are not asserted here.

## Target

- Target UID: `00048F`.
- Target path: `by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md`.
- Source queue/report row: validator command `000000011445`, `auto-generated/-ag-research-tracker.md`, `by-memory`, reconstructable not-covered queue.
- Evidence-time supervisor classification: report-only source-quality research before Gate 1. The accepted implementation callback has since been completed without report execution/lifecycle action.
- Current scores and parent state: `92/94`, `CANONICAL_OWNER:0000D6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D6`, position `20`, `Nested:0`; parent [UID:0000D6] routes to [UID:0000JU] `HelpPanes`.

## Current Target State

- Evidence-time/pre-callback metadata was `86/90`, source owner/emitter UID0000D6, true, blank position, `Nested:0`. Current target metadata is applied `92/94`, the same owner/emitter/reconstructable/nesting, and position `20` over unchanged exact half-open range `0x004c7290-0x004c7307`.
- Evidence-time/pre-callback generated order was `40/50/60/constructor/destructor/paint`; applied positions now generate constructor/destructor/paint/timer/pointer/key in exact `10/20/30/40/50/60` order.
- Evidence-time/pre-callback C++ explicitly nulled the member and cleared the singleton. Current Destination 1 emits only wide-array deletion; the invalid member-null statement is removed and the observed singleton store is represented by `Singleton<SimpleHelpPane>` base destruction.
- Evidence-time/pre-callback blockers were the UID0000D6 no-class marker, UID00048E manual publication, blank UID00048G position, source-emitting/reconstructable UID0003YZ metadata, and duplicate UID000228 globals. All are resolved in Destinations 2-6 and confirmed by scoped validators plus final generated readback.
- Related target/support docs checked: UID00048E, UID00048G, UID00048H, UID00048I, UID00048J, UID0003YZ, UID00016S, UID0000D6, UID0000JU, UID0001PC, UID0000S9, UID000228, Pane, PaneLayout, EventHandler, TimerHandler, MemoryMan allocation/free helpers, generated `HelpPanes.cpp`, and all affected manual coverage rows.
- Current callback state: B002 changed only Destinations 1-8 under serial short leases, validated each ordinary page, released every lease, and completed one waited generated verification. Current/future report path, validation, execution, movement, archive, and manual-coverage state are external and are not asserted; B002 did not run/probe `execute_report` or any lifecycle command.

## Executive Recommendation

- Best direct semantic owner: [UID:0000D6] `SimpleHelpPane`; best source emitter: [UID:0000JU] `HelpPanes`, projected as `NexusTK/ui/controls/HelpPanes.cpp`.
- Keep UID00048F as an exact ordinary destructor source child. Do not merge it into UID00016S, UID0003YZ, UID000228, the global page, or the Pane base.
- Source class shape: `SimpleHelpPane` derives first from `Pane` and second from empty `Singleton<SimpleHelpPane>`. RTTI PMD places the Singleton base at `+0xf8`; EBO lets `wchar_t *m_textBuffer` share that offset. The complete object is `0xfc` bytes.
- Source destructor shape: release the copied wide array only. Reverse base destruction then clears the Singleton before `Pane::~Pane`; that ordering exactly matches the binary.
- Compiler disposition: UID0003YZ and adjustors `0x004ce38d/0x004ce398` are non-emitting ABI evidence generated by the virtual destructor declaration.
- Applied gate condition: all six managed blocks and support prose/metadata were applied together, keeping the constructor, class declaration, ordinary destructor, scalar-wrapper disposition, helper definitions, and source order synchronized.

## Supervisor Active Recheck

- Evidence-time supervisor assignment was a report-only investigation of UID00048F after the prior UID0002AF lifecycle completed; mandatory IDA MCP was recovered for that research pass.
- The item did not require a new range split: B007 already created exact children. It required source-shape repair within that split, especially ordinary-versus-scalar destructor separation and Singleton/EBO reconstruction.
- Every source-bearing child in the directly affected `SimpleHelpPane` method island has its applied formal body: constructor, destructor, paint, timer, pointer/mouse, and key/text. The scalar wrapper has applied exact no-code compiler proof. No child was created.

## Inference Research Guidance Check

- `by-structure.md` and current by-memory/by-class/by-file guidance were applied: semantic owner is independent of emission, by-file roots receive prose only, exact method bodies belong to by-memory children, compiler wrappers must not emit handwritten ABI code, and class declarations may carry a post-class `[[CHILDREN]]` insertion point.
- Existing documentation was treated as evidence, not authority. Specifically, the current explicit singleton assignments, explicit buffer nulling, class no-code marker, blank source positions, scalar-wrapper reconstructability, and generated duplicate globals were re-tested.
- IDA facts: exact bytes/instructions, PMDs, vtable cells, xrefs, callee bodies, and padding. Documentation facts: accepted family split, Pane layout, method signatures, global identity, and source-file route. Inferences: historical private/access spellings and helper names below the surviving-symbol threshold.
- No Wave2/Wave3 artifact or instruction was adopted. Searches found no current explicit override; stale wave labels, if encountered in broad docs, are irrelevant to this target.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Evidence class | Disposition |
| --- | --- | --- | --- |
| Raw `sub_4C7290` name | `SimpleHelpPane::~SimpleHelpPane()` | exact class vtables, ordinary/scalar family, current child split | source-facing, very strong |
| `this[62]` / `Block[62]` | `wchar_t *m_textBuffer` at `+0xf8` | constructor allocates `2 * length + 2`, copies 16-bit units, writes wide NUL; paint consumes wide units; both destructors free it | inferred spelling, exact type/role |
| Singleton clear at `0x004c72e8` | implicit `Singleton<SimpleHelpPane>` base destructor | RTTI base PMD `+0xf8`, reverse destruction order, IdleWatcher/BrowserDialog comparators | original source-shape inference, very strong |
| Constructor publish at `0x004c6ff1/0x004c6ff8` | `Singleton<SimpleHelpPane>()` base initialization | adjusted empty-base pointer pattern and RTTI | original source-shape inference, very strong |
| Buffer clear in current formal body | reject | target has no write to `[this+0xf8]` after load/free | invalid current source statement |
| Direct MemoryMan calls | source array allocation/deallocation lowering | paired constructor allocation/copy and destructor null-guard/free; no element destructor for `wchar_t` | compiler/library lowering |
| Three vptr stores | compiler destructor prologue for primary/EventHandler/TimerHandler views | addresses `0x0061abe4/0x0061ac30/0x0061ac60`; same stores in constructor/scalar path | compiler-only |
| Base teardown call | implicit `Pane::~Pane()` | exact `0x00544580` body and source hierarchy | compiler/base effect |
| Zero direct target xrefs | live ordinary destructor retained for source/ABI completeness | deleting wrapper duplicates the ordinary semantics and is reached from all three vtable views | not dead raw code |
| Scalar wrapper source | no standalone C++ | delete flags, object-storage free, size-guard path, adjustor thunks | compiler-only, non-emitting |
| Class no-code marker | replace with complete declaration | RTTI, base PMDs, exact methods, complete size, field | current declaration blocker resolved |
| Generated duplicate global definitions | remove duplicates from UID000228 helper block | by-global pages already define both pointers; generated HelpPanes.cpp has duplicate `g_pSimpleHelpPane` | support C++ blocker resolved |
| Source order | child positions `10/20/30/40/50/60` | exact address order and already accepted `40/50/60` | deterministic |

- Rejected alternatives: a free helper, a raw MemoryMan call in source, an explicit field-null store, an explicit singleton clear, direct `Pane::~Pane()` invocation, a handwritten scalar deleting destructor, direct EventHandler/TimerHandler inheritance in addition to Pane, a separate member for Singleton storage, a `char *` buffer, parent UID00016S emission, global-page method ownership, and source from the generated `class_SimpleHelpPane.cpp` split.
- Remaining uncertainty: exact original access labels and private field spelling do not survive. Current project vocabulary and full dataflow make the declaration defensible; this is only a confidence cap and does not block C++.

## Evidence Standards Used

- Evidence types: fresh MCP health/session checks, function lookup/profile/decompile/analysis, exact bytes and SHA256, basic-block/branch inspection, direct callee analysis, target/global/vtable/RTTI xrefs, integer/table reads, absolute pointer scans, adjacent padding reads, constructor/scalar/base comparator analysis, generated output, by-* docs, executed support reports, and manual coverage rows.
- Evidence ladder: exact target instructions and RTTI PMDs control behavior/layout; constructor/paint/scalar/base consumers corroborate types/lifecycle; current docs and reports supply naming/source-tree context; generated output is used only to detect emission defects.
- Strength limit: no PDB/header survives, so spelling/access sections and global linkage remain below original-proof. There is no behavior, range, type, ownership, or formal-body blocker.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: fresh `idb_list`; `server_health`; bounded target `get_bytes`; `lookup_funcs` for target, adjacent methods, adjustors, and scalar wrapper; `analyze_function` with full target/scalar assembly; `decompile` for constructor, target, scalar, MemoryMan getter/free, Pane destructor, object free, IdleWatcher destructor, and BrowserDialog destructor; `xrefs_to` for target, constructor, scalar, all three vtable bases, Singleton global, comparator globals, allocator/free/base calls, and RTTI records; `get_int` for vtable cells/PMDs; `find_bytes` for target/scalar/global pointer patterns; and bounded bytes around both target and scalar boundaries.
- Exact target body: 119 bytes, SHA256 `7FE4399BBF0F078EC0C4866A2DAE2FCF7E686AF7BD0E14DDB7D4FB1032E7FD8`.
- by-* docs checked: the target; UIDs 00048E/48G/48H/48I/48J/3YZ/16S/0D6/0JU/1PC/0S9/228; Pane and relevant layout/interface docs; MemoryMan helpers; `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-global/-coverage-report.md`.
- Report roots and exact terms checked: all roots and terms listed under Supporting Research. Six central executed support reports were opened; no direct target report exists.
- Generated checks: evidence-time `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` SHA256 `095E9E9A35CCE34D364D542C58FA85858DC046779FB4702B582DBAC798B5DC45`, command `000000011445`, has exactly one target method, no actual `SimpleHelpPane` class declaration, wrong child order, the stale two extra destructor statements, and duplicate `g_pSimpleHelpPane` definitions from UID0000S9/UID000228.
- Negative checks: no xref or absolute VA/RVA pointer to the ordinary target; no target string; no field-null write; no separate source branch around singleton clear; no direct object free/delete flags in the ordinary target; no evidence for `char *`, separate Singleton storage, direct helper ownership, or handwritten wrapper glue.
- Failed/unavailable checks: the server advertised no callable named `callers` or `disassemble`; valid `xrefs_to`, `analyze_function(include_asm=true)`, and `callees` supplied the same bounded evidence. Two early PowerShell helper calls omitted `database` because `$args` is a reserved automatic variable; the server rejected those malformed local payloads. Correct calls with explicit `database:e98ecbb2` immediately succeeded, so this was not an MCP outage and no fallback evidence was substituted.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00048F remains the exact ordinary destructor at `0x004c7290-0x004c7307`. | very high | lookup/bytes/adjacent functions | Destination 1 target retained exact range; validator `000000011490` and generated UID readback | already-present | already-present |
| C02 | Target score is applied `92/94`; owner/emitter UID0000D6 and reconstructable true remain. | high | complete blocker audit | Destination 1 metadata; validator `000000011490` | incorporate | applied |
| C03 | Target source position is `20`, `Nested:0`. | very high | exact method order | Destination 1 metadata; validator `000000011490`; generated lines `120-124` | incorporate | applied |
| C04 | Target is 119 bytes with SHA256 `7FE439...FD8A`. | exact | bounded bytes/hash | Destination 1 Evidence And Behavior | incorporate | applied |
| C05 | Target has one source conditional and three target-local blocks; SEH/cookie blocks are compiler support. | very high | full assembly/CFG | Destination 1 Evidence And Behavior/Source-Quality Notes | incorporate | applied |
| C06 | Primary/EventHandler/TimerHandler vptr stores are compiler destructor prologue. | exact | stores and table xrefs | Destination 1 evidence; generated ABI-pattern count zero | incorporate | applied |
| C07 | `+0xf8` is a constructor-owned `wchar_t *` overlapping the empty Singleton base through EBO. | very high | RTTI PMD plus ctor/paint/free | Destinations 1-3/7 applied; validators `000000011490/11494/11496/11506` | incorporate | applied |
| C08 | Null-guarded MemoryMan free is the lowered wide-array deletion. | high | ctor allocation pair/free wrappers | Destination 1 exact source/evidence | incorporate | applied |
| C09 | No source/member null assignment follows deletion. | exact | no `+0xf8` write | Destination 1 removes statement and preserves superseded history; generated destructor lines `121-124` | reject-invalid | applied |
| C10 | Global clear is implicit Singleton-base destruction, not authored target body. | very high | RTTI/order/comparators | Destinations 1-3/7 historicalize direct assignments and apply base lifecycle | historicalize | applied |
| C11 | Exact teardown order is owned array, Singleton clear, Pane base. | exact plus source inference | target instruction order/base hierarchy | Destinations 1/7/8 applied | incorporate | applied |
| C12 | `Pane::~Pane()` and its dispatcher/layer/region/GrafPort cleanup stay implicit. | exact | callee `0x00544580` | Destination 1 compiler/base exclusion | incorporate | applied |
| C13 | Zero direct target xrefs do not make the source destructor dead; scalar/vtable route proves family liveness. | high | xref negatives plus scalar tables | Destination 1 exact liveness proof | incorporate | applied |
| C14 | UID0003YZ duplicates ordinary semantics and adds deleting flags/free/size guard only. | exact | scalar full assembly | Destination 5 Behavior/Evidence; validator `000000011500` | incorporate | applied |
| C15 | Adjustors `0x004ce38d/398` subtract `0xa0/0xa4` and route secondary/tertiary vtables to UID0003YZ. | exact | lookup/xrefs/table reads | Destinations 5/7 applied; generated adjustor count zero | incorporate | applied |
| C16 | UID0003YZ is applied `91/94`, owner `NONE`, reconstructable false, blank emitter/position/C++, and compiler nesting `-8`. | high | compiler-only proof and accepted comparator policy | Destination 5 metadata/formal block; validator `000000011500`; generated UID count zero | incorporate | applied |
| C17 | Pads are exactly `0x004c7287-7290` and `0x004c7307-7310`; neither belongs to target. | exact | bounded bytes | Destinations 1/7/8 evidence | incorporate | applied |
| C18 | Class declaration is `Pane` plus `Singleton<SimpleHelpPane>`, one pointer field, size `0xfc`. | very high | RTTI PMDs/guard size | Destination 2 declaration/layout; validator `000000011494`; generated lines `7-27` | incorporate | applied |
| C19 | UID0000D6 is a complete applied `92/94` declaration with post-class child marker and position `10`. | high | full method/layout inventory | Destination 2 metadata/block; validator `000000011494`; generated class count one | incorporate | applied |
| C20 | UID00048E initializes the Singleton base, removes manual publication, keeps `88/90`, and takes position `10`. | very high | ctor lowering/RTTI | Destination 3 block; validator `000000011496`; generated lines `29-118` | incorporate | applied |
| C21 | UID00048G body/score remain accepted and position `30` is applied. | exact | address/source order | Destination 4 metadata/evidence; validator `000000011499`; generated lines `126-161` | incorporate | applied |
| C22 | UID00048H/48I/48J remain unchanged at positions `40/50/60`. | exact | current metadata | Direct readback unchanged; generated lines `163-191` | already-present | already-present |
| C23 | UID00016S remains non-emitting and gains corrected Singleton/EBO/destructor inventory prose. | high | split and current family evidence | Destination 7 prose; validator `000000011506` | incorporate | applied |
| C24 | UID0000JU remains the HelpPanes source owner and gains corrected class/lifecycle/emission-order prose only. | high | family/source route | Destination 8 prose only; validator `000000011509`; no by-file reconstruction metadata | incorporate | applied |
| C25 | UID0000S9/UID0001PC remain the one definition/covered-storage pair; 23 refs do not move method ownership. | very high | global xrefs/docs | Direct readback unchanged; generated global definition count one | already-present | already-present |
| C26 | UID000228 no longer defines either singleton global and retains only declarations/helper bodies. | exact | generated duplicate readback | Destination 6 formal block; validator `000000011502`; generated helper declaration/definition counts one each | incorporate | applied |
| C27 | Global/helper/aggregate/scalar/free-helper ownership alternatives are rejected. | high | ranked ownership/negative evidence | Target/support history and rejected-alternative sections retained | reject-stale | applied |
| C28 | Source names/types are recommendations only; no IDA mutation is requested. | high | assignment restriction | Report rename/type section retained; no IDA writes performed | not-applicable | excluded-with-reason |
| C29 | Final generated verification must prove one class, six methods in order, one global definition, one helper pair, no target Empty Marker, and no handwritten scalar/adjustor ABI. | high | current generated defects | Final waited validator/header command `000000011515`, SHA `F340DD9A...C7FC`, exact counts recorded below | incorporate | applied |
| C30 | Exact supervisor-owned manual coverage replacement/addition text is supplied for every affected row. | exact | direct row inspection | Coverage section preserved; manual coverage files intentionally untouched under supervisor ownership | incorporate | excluded-with-reason |

## Positive Evidence Summary

- Exact behavior: load `+0xf8`; restore three derived vtable views; conditionally free the loaded pointer; clear `0x0069ae00`; call `Pane::~Pane`; return.
- Exact type: constructor computes a 16-bit string length, allocates `2 * length + 2`, copies `2 * length`, and stores a wide NUL; paint walks 16-bit characters; teardown frees the same pointer.
- Exact class shape: RTTI hierarchy has seven entries and includes Pane/GrafPort/LObject/EventHandler/TimerHandler plus `Singleton<SimpleHelpPane>` at PMD `mdisp=0xf8`, `pdisp=-1`, `vdisp=0`.
- Exact compiler route: primary vtable `0x0061abe4` points to scalar wrapper `0x004ce560`; secondary/tertiary cells point through `-0xa0/-0xa4` adjustors. The scalar size-guard path uses `0xfc`.
- Strongest inference chain: authored pointer deletion plus reverse destruction of the explicit Singleton and Pane bases generates the exact free/clear/base order without any raw helper, field clear, global clear, vptr, or ABI source statement.

## IDA MCP Facts

- Function/range facts: `sub_4C7290` starts at `0x004c7290`, size `0x77`, exclusive end `0x004c7307`; 40 instructions; no direct caller/xref; direct callees only `0x00516030`, `0x00516170`, and `0x00544580`.
- Data/table/padding facts: target bytes hash to `7FE4399B...FD8A`; preceding `0x004c7287-7290` and following `0x004c7307-7310` are nine `0xcc` bytes each.
- Xref facts: target has zero xrefs and zero VA/RVA pointer-pattern hits. Constructor has 18 direct code xrefs. Singleton storage has 23 data xrefs. Scalar wrapper has two adjustor code xrefs plus primary-vtable data xref.
- Vtable facts: `0x0061abe4 -> 0x004ce560`; `0x0061ac30 -> 0x004ce38d`; `0x0061ac34 -> 0x004c7450`; `0x0061ac38 -> 0x004c74a0`; `0x0061ac60 -> 0x004ce398`; `0x0061ac64 -> 0x004c7440`; primary paint cell `0x0061ac28 -> 0x004c7310`.
- RTTI facts: COLs are `0x00647f3c`, `0x00647fec`, and `0x00648000`; the secondary/tertiary COL offsets are `0xa0/0xa4`; Singleton base descriptor `0x00647f9c` has `mdisp=0xf8` and nonvirtual PMD fields.
- Allocator facts: `0x00516030` returns the MemoryMan singleton, `0x00516170` calls the CRT free base and returns zero, and `0x004f4ac0` is object-storage delete lowering. Target does not call `0x004f4ac0`; scalar wrapper does when deleting flag bit 0 is set and bit 2 is clear.
- Negative IDA facts: no target string, no target field-null store, no direct target storage free, no target deleting-flag argument, no target size guard, no call from UID0003YZ to UID00048F, and no additional source-visible branch.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004c6f90-0x004c7287` | UID00048E constructor | source constructor | true | UID0000D6 | retained `88/90` | Singleton-base correction applied, position `10` |
| `0x004c7287-0x004c7290` | UID0000VN ignored | alignment | false | none | `100` | unchanged |
| `0x004c7290-0x004c7307` | UID00048F target | ordinary virtual destructor | true | UID0000D6 | applied `92/94` | Destination 1 applied, position `20` |
| `0x004c7307-0x004c7310` | UID0000VN ignored | alignment | false | none | `100` | unchanged |
| `0x004c7310-0x004c743e` | UID00048G | paint override | true | UID0000D6 | retained `89/91` | body unchanged, position `30` applied |
| `0x004c743e-0x004c7440` | UID0000VN ignored | alignment | false | none | `100` | unchanged |
| `0x004c7440-0x004c7450` | UID00048H | TimerHandler callback | true | UID0000D6 | `91/94` | already position `40` |
| `0x004c7450-0x004c7491` | UID00048I | pointer/mouse callback | true | UID0000D6 | `92/94` | already position `50` |
| `0x004c7491-0x004c74a0` | UID0000VN ignored | alignment | false | none | `100` | unchanged |
| `0x004c74a0-0x004c74b0` | UID00048J | key/text callback | true | UID0000D6 | `91/94` | already position `60` |
| `0x004ce38d-0x004ce398` | UID0000VN ignored | EventHandler dtor adjustor | false | none | compiler | unchanged |
| `0x004ce398-0x004ce3a3` | UID0000VN ignored | TimerHandler dtor adjustor | false | none | compiler | unchanged |
| `0x004ce560-0x004ce618` | UID0003YZ | scalar deleting destructor | false | none | applied `91/94` | blank C++, blank emitter/position, Nested `-8` |
| class declaration/layout | UID0000D6 | source class | true | UID0000JU | applied `92/94` | Destination 2 applied, position `10` |
| `0x004c6f90-0x004c7680` | UID00016S | split index | false | UID0000JU | retain `88/90` | prose sync only |
| `0x0069ae00-0x0069ae04` | UID0001PC | singleton storage evidence | true/covered | UID0000S9 | `87/90` | verify-only |
| `0x004a0d40-0x004a0d71` | UID000228 | two close helpers | true | UID0000JU | applied `88/93` | duplicate definitions removed; helper pair retained |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| UID00048F | zero direct xrefs | ordinary body is retained source/ABI material but deleting routes use compiler wrapper |
| UID00048F `0x004c72da` | `GetMemoryMan` | allocator policy lowering |
| UID00048F `0x004c72e1` | `FreeBufferMemory` | conditional owned-array release |
| UID00048F `0x004c72f2` | `Pane::~Pane` | implicit base teardown |
| UID0003YZ `0x004ce560` | primary vtable `0x0061abe4` | live deleting-destructor route |
| UID0003YZ | adjustors `0x004ce38d/398` | secondary/tertiary deleting routes |
| UID00048E | 18 constructor call xrefs | broad tooltip creation liveness |
| `g_pSimpleHelpPane` | 23 data xrefs | constructor publish, ordinary/support/scalar clears, helper read, feature consumers |
| UID000228 `0x004a0d60` | caller `0x00568e1c` | deletes active simple-help singleton through primary slot 0 |

## Documentation Evidence And IDA Status

- Evidence-time/pre-callback target documentation correctly identified ordinary-destructor ownership, copied-text cleanup, singleton-clear occurrence, Pane teardown, scalar separation, and exact padding, but was incomplete on instructions/xrefs/RTTI/order and stale on authored null/global assignments. Current UID00048F is `92/94`, position `20`, contains Destination 1, and carries the full report-level evidence plus superseded history; validator `000000011490` returned `ok:1`.
- Evidence-time UID00048E already recovered the wide copy and full constructor behavior but manually published the singleton. Current UID00048E retains `88/90`, is position `10`, initializes `Singleton<SimpleHelpPane>()`, and historicalizes the direct store; validator `000000011496` returned `ok:1`.
- UIDs 00048G/48H/48I/48J retain complete sibling behavior. Current UID00048G is position `30` after validator `000000011499`; verify-only UIDs 00048H/I/J remain unchanged at `40/50/60`.
- Evidence-time UID0003YZ had true/emitter metadata despite blank wrapper C++. Current UID0003YZ is `91/94`, owner `NONE`, false, blank emitter/position/formal C++, and `Nested:-8`, with complete ABI no-code proof; validator `000000011500` returned `ok:1`.
- Evidence-time UID0000D6 had a no-class marker. Current UID0000D6 is `92/94`, position `10`, and emits the complete Pane/Singleton/EBO declaration plus post-class children; validator `000000011494` returned `ok:1`.
- Current UID00016S remains the `88/90` non-emitting index with corrected child/layout/lifecycle/padding prose after validator `000000011506`. Current UID0000JU remains the `90/86` prose-only file route, has no reconstruction metadata, and carries the corrected class/lifecycle/emission-order/compiler-exclusion text after validator `000000011509`.
- UID0000S9/UID0001PC correctly identify one zero-filled four-byte singleton slot and 23 refs. Their source-linkage spelling remains a separate cap and is unchanged.
- Evidence-time/pre-callback generated `HelpPanes.cpp` had order `48H/48I/48J/48E/48F/48G`, no class declaration, two false target statements, and UID000228 duplicate globals. Final waited generated file is validator-owned SHA256 `F340DD9AA3A23EB3CBAEBF82CB2A4C4810AC1E453896C033DE5F41440032C7FC`; it contains one complete class, exact six-method order, one singleton definition, one helper pair, no target Empty Marker, and no scalar/adjustor/vtable ABI source.

## Ranked Ownership Analysis

### 1. UID0000D6 SimpleHelpPane through UID0000JU HelpPanes

- Evidence for: decorated RTTI/vtables, exact constructor/paint/event siblings, `this` layout, virtual deleting route, global lifecycle, and established source family all converge.
- Evidence against: no surviving source header fixes private/access spelling.
- Decision: accepted semantic owner and class emitter; confidence cap only.

### 2. Singleton<SimpleHelpPane> base

- Evidence for: RTTI names and PMD `+0xf8`, constructor adjusted publish, ordinary/scalar clear order, and comparator classes.
- Evidence against: it owns only singleton lifecycle, not the ordinary destructor method or copied buffer.
- Decision: required source base/dependency, not target owner.

### 3. UID0003YZ / UID00016S / UID000228 / MemoryMan alternatives

- Evidence for: each contains related deletion, aggregate, close, or free behavior.
- Evidence against: UID0003YZ is compiler ABI; UID00016S is a mixed non-emitting index; UID000228 is a caller helper; MemoryMan is shared allocator infrastructure.
- Decision: rejected as direct owner/source body.

### Proposed new file/grouping, if applicable

- Not applicable. Keep the accepted `NexusTK/ui/controls/HelpPanes.cpp` grouping and existing UIDs; no new class, file, child, or report is warranted.

## Source Placement

- Recommended placement: declaration in the HelpPanes header/source declaration region represented by UID0000D6, with qualified constructor/destructor/paint/event definitions emitted in UID order through UID0000JU.
- Exact child order: constructor `10`, destructor `20`, paint `30`, timer `40`, pointer/mouse `50`, key/text `60`.
- Why it fits: all three class vtables, RTTI, singleton, helper, constructor, and six exact methods belong to the established HelpPanes family.
- Rejected placements: Pane source, MemoryMan source, feature-caller files, the compiler-thunk island, by-global storage, and broad aggregate emission.
- Remaining uncertainty: whether the original project split declarations into a separate `HelpPanes.h`; by-file guidance forbids formal C++ on the by-file root, so the valid current emitter remains the class page plus method children.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is unchanged: `0x004c7290-0x004c7307`, 119 bytes. `0x004c7307` is not a function; `0x004c7310` begins paint.
- Previous constructor ends `0x004c7287`; nine `0xcc` bytes end at target start. Nine more `0xcc` bytes follow target to paint.
- No new source child is required. UID00016S remains the non-emitting split index; exact children remain the sole source-body route.
- UID0003YZ is reclassified from reconstructable/source-emitting metadata to compiler-generated non-emitting evidence. Its exact range/page remains useful and must not be deleted or merged.
- Adjustors remain in ignored compiler coverage; no raw vtable/RTTI/table bytes are source.

## Negative Evidence Summary

- No direct xref or absolute pointer points to UID00048F; no caller invokes it directly.
- No target instruction clears `m_textBuffer`, performs object-storage delete, reads deleting flags, uses size `0xfc`, or manually tears down EventHandler/TimerHandler.
- No evidence supports a source-authored scalar deleting destructor or adjustor function.
- No evidence supports direct multiple inheritance from EventHandler/TimerHandler; Pane already owns those bases at `+0xa0/+0xa4`.
- No evidence supports a second storage field at `+0xf8`; Singleton EBO and `m_textBuffer` overlap there.
- Consumer/global xrefs do not transfer method ownership. Generated order, duplicate globals, and old generated split names are not original-source evidence.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing function name/type: ordinary virtual destructor for `SimpleHelpPane`, no explicit parameters, no source return value.
- Proposed member: `wchar_t *m_textBuffer` at `+0xf8`, overlapping empty `Singleton<SimpleHelpPane>` through EBO.
- Proposed class type: `SimpleHelpPane : public Pane, public Singleton<SimpleHelpPane>`, size `0xfc`.
- Proposed evidence comments: mark `0x004ce560` as scalar deleting wrapper generated from UID00048F and `0x004ce38d/398` as `-0xa0/-0xa4` adjustors; mark the clear at `0x004c72e8` as inlined Singleton-base destruction.
- Items intentionally unchanged: raw IDA labels, global/type database, helper names, and source linkage, because this assignment forbids IDA mutation and no original symbols prove exact spellings.
- IDA DB edits: not requested or performed; the callback explicitly excluded IDA mutation.

## First-Draft C++ Recommendation

- Applied formal C++ destinations: UID00048F, UID0000D6, UID00048E, UID00048G, and UID000228 carry the exact accepted managed blocks below. UID0003YZ carries only the exact blank managed block/no-code disposition.
- Destination 1, `by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md`, exact replacement formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SimpleHelpPane::~SimpleHelpPane()
{
    delete [] m_textBuffer;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 2, `by-class/SimpleHelpPane.md`, exact replacement formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SimpleHelpPane : public Pane,
                       public Singleton<SimpleHelpPane>
{
public:
    SimpleHelpPane(const wchar_t *text,
                   Pane *owner,
                   int x,
                   int y,
                   int timeoutMs);
    virtual ~SimpleHelpPane();

protected:
    virtual void OnPaintFrame();
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    wchar_t *m_textBuffer;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 3, `by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md`, exact replacement formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SimpleHelpPane::SimpleHelpPane(const wchar_t *text,
                               Pane *owner,
                               int x,
                               int y,
                               int timeoutMs)
    : Pane(2),
      Singleton<SimpleHelpPane>(),
      m_textBuffer(0)
{
    const int textLength = static_cast<int>(wcslen(text));
    m_textBuffer = new wchar_t[textLength + 1];
    wmemcpy(m_textBuffer, text, textLength);
    m_textBuffer[textLength] = L'\0';

    int lineCount = 1;
    int maxLineWidth = -1;
    int lineStart = 0;

    for (int index = 0; index < textLength; ++index)
    {
        const wchar_t ch = m_textBuffer[index];
        if (ch == L'\r' || ch == L'\n' || ch == L'\t')
        {
            ++lineCount;

            const int lineWidth = GetTextWidth(m_textBuffer + lineStart,
                                               index - lineStart);
            if (lineWidth > maxLineWidth)
                maxLineWidth = lineWidth;

            lineStart = index + 1;
        }
    }

    const int tailWidth = GetTextWidth(m_textBuffer + lineStart,
                                       textLength - lineStart);
    if (tailWidth > maxLineWidth)
        maxLineWidth = tailWidth;

    const int width = maxLineWidth + 10;
    const int height = lineCount * (GetLineHeight() + 1) + 9;

    RectBounds ownerBounds;
    owner->GetBounds(&ownerBounds);

    RectBounds bounds;
    bounds.left = x - width / 2;
    bounds.top = y - height / 2;
    bounds.right = bounds.left + width;
    bounds.bottom = bounds.top + height;

    if (bounds.left < ownerBounds.left)
        OffsetRect(&bounds, ownerBounds.left - bounds.left, 0);
    else if (bounds.right > ownerBounds.right)
        OffsetRect(&bounds, ownerBounds.right - bounds.right, 0);

    if (bounds.top < ownerBounds.top)
        OffsetRect(&bounds, 0, ownerBounds.top - bounds.top);
    else if (bounds.bottom > ownerBounds.bottom)
        OffsetRect(&bounds, 0, ownerBounds.bottom - bounds.bottom);

    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();

    Point ownerOffset;
    owner->GetScreenOffset(&ownerOffset);

    RectBounds screenBounds = bounds;
    OffsetRect(&screenBounds, ownerOffset.x, ownerOffset.y);

    if (screenBounds.left < 0)
        OffsetRect(&bounds, -screenBounds.left, 0);
    else if (screenBounds.right >= screenWidth)
        OffsetRect(&bounds, screenWidth - screenBounds.right, 0);

    if (screenBounds.top < 0)
        OffsetRect(&bounds, 0, -screenBounds.top);
    else if (screenBounds.bottom >= screenHeight)
        OffsetRect(&bounds, 0, screenHeight - screenBounds.bottom);

    owner->GetScreenOffset(&ownerOffset);
    OffsetRect(&bounds, ownerOffset.x, ownerOffset.y);

    AddToLayer(&bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    SetPaneOrder(0, 0);

    SetTimer(timeoutMs);
    m_initialOpacity = 0.2f;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 4, `by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md`, exact retained formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SimpleHelpPane::OnPaintFrame()
{
    RectBounds bounds = m_bounds;

    SetDrawColor(1);
    FillPaneRect(bounds);

    SetDrawColor(0x80);
    DrawRectFrame(bounds);

    SetTextColor(0x8f);

    const int margin = 5;
    const wchar_t *text = m_textBuffer;
    const int textLength = static_cast<int>(wcslen(text));
    const int drawX = margin;
    int drawY = GetTextLineHeight() + margin;
    int lineStart = 0;

    for (int index = 0; index < textLength; ++index)
    {
        const wchar_t ch = text[index];
        if (ch == L'\r' || ch == L'\n' || ch == L'\t')
        {
            MoveTo(drawX, drawY);
            DrawTextRun(text + lineStart, index - lineStart);

            drawY += GetTextLineHeight() + 1;
            lineStart = index + 1;
        }
    }

    MoveTo(drawX, drawY);
    DrawTextRun(text + lineStart, textLength - lineStart);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 5, `by-memory/0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor.md`, exact blank formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 6, `by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md`, exact replacement formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void CloseItemHelpPaneSingleton();
static void CloseSimpleHelpPaneSingleton();

static void CloseItemHelpPaneSingleton()
{
    delete g_pItemHelpPane;
}

static void CloseSimpleHelpPaneSingleton()
{
    delete g_pSimpleHelpPane;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason the blocks preserve behavior: the constructor/destructor pair delegates singleton lifecycle to the exact RTTI-proven base, the target retains only the observed owned-array release, all accepted paint/event semantics remain, deleting wrapper C++ stays blank, and close helpers still dispatch normal virtual deletion without redefining storage.
- Period plausibility: MSVC 2005-era multiple inheritance/EBO, virtual destructor generation, explicit empty-base initializer, zero literal, wide array allocation/deallocation, and out-of-line qualified definitions all match the executable and current project source style.
- Third-party import directive: not applicable; this is NexusTK project source, not a vetted third-party static embed.

## Final Recommendation

- Exact callback result: target `92/94`, position `20`, complete evidence, and Destination 1 are applied; class `92/94`, position `10`, full inheritance/layout/method declaration, and Destination 2 are applied; constructor base initialization/position `10`, paint position `30`, scalar non-emitting `91/94`, helper one-definition `88/93`, and aggregate/file prose are synchronized.
- Exact parent assignments: target/constructor/paint/event methods remain semantic children of UID0000D6 and emit through it; UID0000D6 remains child of UID0000JU. UID0003YZ changes to owner `NONE` because it is compiler-only ABI evidence, not semantic source material.
- Exact items left no-owner/non-emitting: both adjustors and all alignment remain ignored/compiler; UID00016S remains a non-emitting index; UID0003YZ is non-emitting compiler coverage.
- Exact future work outside scope: original private/access/global-linkage spelling may be polished if headers/symbols appear. No current investigable target blocker is deferred.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md`.
- Applied report facts: MCP provenance, exact bytes/hash/range/instructions/CFG, all three vptr stores, `+0xf8` pointer type/EBO, allocator lowering, no field write, implicit Singleton clear, Pane teardown, zero target xrefs, scalar/vtable liveness, both padding spans, rejected alternatives, and generated verification contract.
- Applied metadata/score/owner/emitter/reconstructable/C++: `92/94`, owner/emitter unchanged UID0000D6, true unchanged, position `20`, Nested `0`, Destination 1.
- Preserved historical/stale assumptions: prior explicit field-null and global-clear statements remain labeled superseded with exact reasons; earlier B007 provenance remains intact.

## Recommended Support Doc Changes

- Destination 2 `by-class/SimpleHelpPane.md`: applied `92/94`, position `10`, complete Pane/Singleton declaration, EBO field/size, exact six-method order, implicit singleton lifecycle, scalar exclusions, and report-level evidence/history.
- Destination 3 UID00048E constructor: retained `88/90` and all accepted constructor details, applied position `10` and exact corrected block, and historicalized manual singleton publication as inlined base construction.
- Destination 4 UID00048G paint: retained `89/91` and exact body, applied position `30`, and preserved all accepted CR/LF/tab/tail-draw evidence.
- Destination 5 UID0003YZ scalar: applied `91/94`, owner `NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, `Nested:-8`, populated summary, and exact wrapper/adjustor/size-guard proof. Old class owner/emitter remains superseded B003-era policy.
- Destination 6 UID000228 helper: applied `88/93` exact block without duplicate global definitions while preserving helper behavior/callers/padding/name caps.
- Destination 7 UID00016S aggregate: retained `88/90`, false/blank C++, and applied exact child order, Singleton/EBO layout, implicit clear, ordinary/scalar separation, and padding inventory.
- Destination 8 `by-file/HelpPanes.md`: applied prose only, preserved `90/86`, file route, and all unrelated family details, and added corrected SimpleHelpPane declaration/lifecycle/source-order/compiler exclusions. No by-file reconstruction metadata was added.
- Verify-only readback: UID00048H/48I/48J, UID0000S9, UID0001PC, Pane, MemoryMan, EventHandler, TimerHandler, and unrelated HelpPanes pages required no change.

## Score And Metadata Recommendation

| Page | Evidence-time / pre-callback | Current applied | Metadata disposition |
| --- | --- | --- | --- |
| UID00048F target | `86/90` | `92/94` | owner/emitter/true retained; position `20`; Nested `0` |
| UID0000D6 class | `86/88` | `92/94` | owner/emitter retained; position `10`; declaration populated |
| UID00048E constructor | `88/90`, blank position | `88/90` | position `10`; formal source correction |
| UID00048G paint | `89/91`, blank position | `89/91` | position `30`; body retained |
| UID0003YZ scalar | `87/92`, class owner/emitter/true | `91/94` | owner `NONE`; false; blank emitter/position/C++; Nested `-8` |
| UID000228 helpers | `86/91` | `88/93` | owner/emitter/true retained; duplicate definitions removed |
| UID00016S aggregate | `88/90` | `88/90` | false/index retained; prose synchronized |
| UID0000JU file | `90/86` | `90/86` | by-file prose only; no reconstruction metadata |

- Target rationale: every instruction, branch, side effect, callee, vtable, RTTI base, field type, singleton/base order, liveness route, compiler exclusion, padding span, source position, and exact C++ body is resolved. The missing original header and exact private spelling cap below 95.
- Score-improvement attempt: zero-xref liveness was closed through scalar/vtable routes; raw helper names were reduced through allocator/base docs; global clear was resolved through RTTI and comparators; class shape through PMDs/EBO/guard size; C++ compile shape through declaration and helper de-duplication. No investigable blocker remains.

## Open Questions With Attempted Resolution

- Was the singleton clear handwritten? Resolved no: RTTI proves the base, constructor/ordinary/scalar ordering matches base lifetime, and accepted comparator classes produce the same lowering.
- Is `+0xf8` a base or member? Resolved both through EBO: the empty Singleton base PMD and first derived pointer overlap; constructor/paint/free prove pointer type.
- Should the buffer be nulled? Resolved no: no write exists, object destruction follows immediately, and source nulling would generate an extra store.
- Is the direct MemoryMan call authored? Resolved as array-delete lowering: allocation/deallocation symmetry and `wchar_t` trivial element destruction support the period-plausible expression.
- Is UID00048F dead because it has zero xrefs? Resolved no: the virtual deleting wrapper is live from all three vtable views and duplicates the ordinary semantics; the ordinary symbol is source/ABI output.
- Should global linkage or exact Singleton static-member spelling change? Not required for target behavior and not safely resolvable from stripped binary. Existing UID0000S9/UID0001PC route remains; this caps global spelling only, not target score/C++.
- Remaining unresolved questions: exact historical access labels and private field name. Exhaustive RTTI/vtable/caller/docs checks cannot recover spelling; accepted descriptive names are sufficient and the scores stay below 95.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected manual rows: `by-memory/-coverage-report.md` rows for UID000228, UID00016S, UID00016W, and UID0001PC; exact child rows UID00048E/48F/48G/3YZ are absent. Inspected `by-class/-coverage-report.md` UID0000D6, `by-file/-coverage-report.md` UID0000JU, and `by-global/-coverage-report.md` UID0000S9.
- `by-memory/-coverage-report.md`: replace the UID000228 row with:

```text
    - [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md) : reconstructable : 88% : strong : Exact HelpPanes singleton-close helper pair with two 0x11 null-safe virtual-delete wrappers, item/simple singleton reads, scalar-destructor slot-0 routes, caller sets, internal/post-range padding, and one-definition source shape; duplicate singleton definitions are excluded from this helper block.
```

- `by-memory/-coverage-report.md`: replace UID00016S and insert the three affected source children immediately after it with:

```text
    - [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) 0x004c6f90-0x004c7680 | class-method-cluster | SimpleHelpPanes : not_reconstructable : 88% : strong : Non-emitting HelpPanes split index over exact SimpleHelpPane/SimpleHelpPane2 children; SimpleHelpPane uses Pane plus empty Singleton EBO at +0xf8, deterministic constructor/destructor/paint/timer/pointer/key order, implicit singleton lifetime, exact padding, and compiler-wrapper separation; exact child pages alone emit source.
        - [UID:00048E][0x004c6f90-0x004c7287.SimpleHelpPaneConstructor](by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md) 0x004c6f90-0x004c7287 | constructor | SimpleHelpPaneConstructor : reconstructable : 88% : strong : Exact SimpleHelpPane constructor with Pane(2), Singleton-base publication, UTF-16 copied-buffer allocation, line measurement, owner/screen clamping, overlay attachment, timer setup, opacity seed, exact callers/vtables/padding, and position 10.
        - [UID:00048F][0x004c7290-0x004c7307.SimpleHelpPaneDestructor](by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md) 0x004c7290-0x004c7307 | destructor | SimpleHelpPaneDestructor : reconstructable : 92% : very-strong : Exact 119-byte ordinary virtual destructor; authored source releases the constructor-owned wchar_t array, then implicit Singleton-base destruction clears g_pSimpleHelpPane before Pane teardown; three vptr stores, SEH/cookie scaffolding, scalar wrapper/delete flags, and adjacent padding are compiler/excluded.
        - [UID:00048G][0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame](by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md) 0x004c7310-0x004c743e | method | SimpleHelpPaneOnPaintFrame : reconstructable : 89% : strong : Exact paint override with bounds fill/frame, copied UTF-16 text, CR/LF/tab delimiters, final trailing draw, vtable-only liveness, exact padding, and position 30.
```

- `by-memory/-coverage-report.md`: insert UID0003YZ immediately after UID00016W and before its ignored-summary row:

```text
        - [UID:0003YZ][0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor](by-memory/0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor.md) 0x004ce560-0x004ce618 | scalar deleting destructor | SimpleHelpPaneScalarDeletingDestructor : ignored : 91% : very-strong : Compiler wrapper duplicates ordinary SimpleHelpPane member/Singleton/Pane teardown, adds deleting-flag object free and 0xfc guarded-size paths, and is reached from primary plus -0xa0/-0xa4 adjustor vtables; no handwritten C++ or emitter.
```

- `by-memory/-coverage-report.md`: replace UID0001PC with:

```text
    - [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) 0x0069ae00-0x0069ae04 | global pointer | g_pSimpleHelpPane : reconstructable : 87% : strong : Exact four-byte zero-initialized singleton slot with 23 refs, Singleton-base constructor publication and ordinary/scalar clears, close-helper read, tooltip consumers, and covered-by UID0000S9 one-definition route.
```

- `by-class/-coverage-report.md`: replace UID0000D6 with:

```text
- [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md) : reconstructable : 92% : very strong : Complete 0xfc-byte HelpPanes tooltip declaration with Pane and empty Singleton<SimpleHelpPane> bases, wchar_t buffer EBO at +0xf8, exact constructor/destructor/paint/timer/pointer/key children in positions 10-60, three vtable views, implicit singleton lifecycle, and compiler deleting-wrapper/adjustor exclusion.
```

- `by-file/-coverage-report.md`: replace UID0000JU with:

```text
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md) : reconstructable : 90% : strong : `NexusTK/ui/controls/HelpPanes.cpp` tooltip/help-pane family with complete SimpleHelpPane Pane/Singleton declaration and ordered exact child source, SimpleHelpPane2 and item/change-preview families, TimerHandler/EventHandler routes, copied-text ownership, singleton helpers/globals, factories, padding, and compiler wrapper/vtable/RTTI separation.
```

- `by-global/-coverage-report.md`: replace UID0000S9 with:

```text
- [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md) : reconstructable : 87% : strong : Exact zero-filled four-byte SimpleHelpPane singleton slot with covered storage UID0001PC, 23 refs, inlined Singleton<SimpleHelpPane> constructor/ordinary/scalar lifecycle, close-helper and tooltip consumers, one-definition HelpPanes route, and remaining original linkage/static-member spelling cap.
```

- Reason B agent must not apply directly: all manual coverage files are supervisor-owned. Validator-generated coverage refreshes do not satisfy these manual replacements.

## Follow-Up Actions

- B002 actions are complete: Destinations 1-8, C01-C30 disposition, scoped validators, final waited generated readback, and lease release are recorded in this artifact.
- External ownership: any current/future report validation, manual coverage decision, execution, movement, archive, or lifecycle state remains supervisor/validator-owned and is not asserted or directed by B002.
- A-agent actions: none requested. Manual coverage remains supervisor-owned, not an A-agent instruction.

## Confidence

- Recommendation confidence: very high.
- Score confidence: high; `92/94` reflects complete current technical closure while respecting missing original symbols/header.
- Remaining uncertainty: exact historical private/access/global linkage spellings only; none affects behavior, ownership, range, source order, or formal C++ eligibility.

## Validator Results

- Scoped validators, all run from `source-3/project-documentation` with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` and all exit `0`, `ok:1`:

| Command ID / timestamp | Ordinary destination | Result / warnings / side effects |
| --- | --- | --- |
| `000000011490` / `2026-07-14T11:49:10-04:00` | UID00048F target | Applied `92/94`, position `20`, formal hash update; two `missing_ref_uid 0003YZ` warnings reflected pre-UID0003YZ registry state; projected stats updated; generated refresh deferred. |
| `000000011494` / `2026-07-14T11:50:19-04:00` | UID0000D6 class | Applied `92/94`, position `10`, declaration hash; four pre-refresh `missing_ref_uid 0003YZ` warnings; projected stats updated; generated refresh deferred. |
| `000000011496` / `2026-07-14T11:51:12-04:00` | UID00048E constructor | Applied position `10` and formal hash; no target warning; projected stats updated; generated refresh deferred. |
| `000000011499` / `2026-07-14T11:51:45-04:00` | UID00048G paint | Applied position `30`; no target warning; projected stats updated; generated refresh deferred. |
| `000000011500` / `2026-07-14T11:53:01-04:00` | UID0003YZ scalar | Applied `91/94`, owner `NONE`, false/blank metadata, `Nested:-8`; no warning; validator inserted its standard metadata-header separator and refreshed UID/reference/autogen registry state; projected stats updated; generated refresh deferred. |
| `000000011502` / `2026-07-14T11:53:49-04:00` | UID000228 helpers | Applied `88/93` and formal hash; no target warning; projected stats updated; generated refresh deferred. |
| `000000011506` / `2026-07-14T11:54:59-04:00` | UID00016S aggregate | No metadata drift; prose validated with no target warning; projected stats updated; generated refresh deferred. |
| `000000011509` / `2026-07-14T11:56:48-04:00` | UID0000JU HelpPanes | Prose-only page validated with no reconstruction metadata; 77 pre-existing missing-reference warnings in this broad family page (10 printed, 67 suppressed), plus UID0003YZ reference-index add; projected stats updated; generated refresh deferred. |
| `000000011514` / `2026-07-14T12:04:30-04:00` | UID0000JU HelpPanes final prose repair | Replaced the stale old-per-class “current generated sources” sentence with the actual `HelpPanes.cpp` route; same 77 pre-existing broad-family missing-reference warnings; projected stats updated; generated refresh deferred. |

- Interim waited command `000000011511` at `2026-07-14T11:57:19-04:00` first proved the exact counts. A subsequent stale-route prose scan required the bounded UID0000JU repair above, so B002 repeated the authorized waited verification rather than treating that interim artifact as final.
- Final authorized waited command: `python .\tools\validator.py --mode file --file by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md --apply --wait-generated --queue-timeout 240`, command `000000011515`, timestamp `2026-07-14T12:04:45-04:00`, exit `0`, `ok:1`, `generated_refresh:completed`. Its global registry rebuild reported 14 fallback-child insertions, 84 missing-child-marker warnings, and 191 emitter-no-code warnings on unrelated project pages; it refreshed 281 generated metadata outputs and did not identify a UID00048F-family failure.
- Final generated readback: `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`, generated header command `000000011515`, refreshed `2026-07-14T12:04:45-04:00`, SHA256 `F340DD9AA3A23EB3CBAEBF82CB2A4C4810AC1E453896C033DE5F41440032C7FC`.
- Exact generated proof: `class SimpleHelpPane :` count `1`; exact constructor/destructor/paint/timer/pointer/key definition counts `1/1/1/1/1/1` in lines `29/120/126/163/170/186`; exact `g_pSimpleHelpPane` definition count `1`; each close-helper declaration and definition count `1`; UID00048F Empty Emitter Marker count `0`; UID0003YZ/scalar-wrapper text count `0`; adjustor ABI count `0`; target vtable-ABI literal count `0`.
- IDA writes: none. MCP database `e98ecbb2` remains evidence-collection provenance only, not a current availability assertion.

## Changed Files

- Modified ordinary pages:
  - `by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md`
  - `by-class/SimpleHelpPane.md`
  - `by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md`
  - `by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md`
  - `by-memory/0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor.md`
  - `by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md`
  - `by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md`
  - `by-file/HelpPanes.md`
- Modified report: `tools/leaser/Agents/Agent-B002/research/00048F-SimpleHelpPaneDestructor-source-quality.md`.
- Validator-owned side effects only: registry/reference/projected-stat refreshes from the scoped commands and waited generated refresh; B002 did not manually edit generated, projected-stat, tracker, coverage, audit, supervisor, validator-state, or lifecycle files.
- Renamed: none.
- Leases, all successful and released immediately after the corresponding scoped validator: UID00048F `11:48:27-11:49:17-04:00`; UID0000D6 `11:49:27-11:50:24`; UID00048E `11:50:34-11:51:18`; UID00048G `11:51:31-11:52:02`; UID0003YZ `11:52:21-11:53:09`; UID000228 `11:53:20-11:53:56`; UID00016S `11:54:06-11:55:07`; UID0000JU `11:55:29-11:56:55`, then final stale-route prose repair `12:04:17-12:04:36`. Final lease-table readback showed no B002 lease; an unrelated supervisor audit-file lease was present and did not overlap this callback.
- Report execution: not run. B002 did not run/probe `execute_report`, validation lifecycle, move, archive, or registry lifecycle commands.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Exact report SHA `AB6412...5873` passed supervisor Gate 1 before implementation.
- [x] Destination 1 applied to UID00048F with `92/94`, position `20`, exact formal body, and full evidence/history.
- [x] Destination 2 applied to UID0000D6 with `92/94`, position `10`, full Pane/Singleton/EBO declaration and post-class children.
- [x] Destination 3 applied to UID00048E with position `10`, explicit Singleton base initializer, no manual singleton publish, and all accepted constructor detail preserved.
- [x] Destination 4 position `30` applied to UID00048G while retaining its exact accepted body/detail.
- [x] Destination 5 applied to UID0003YZ as `91/94`, owner `NONE`, false/blank emitter/position/C++, Nested `-8`, and complete compiler proof.
- [x] Destination 6 applied to UID000228 without duplicate globals and with helper behavior/callers/padding preserved.
- [x] Destinations 7-8 prose applied to UID00016S and HelpPanes without by-file reconstruction metadata.
- [x] Verify-only UIDs 00048H/48I/48J/0S9/1PC re-read and left unchanged because no concrete contradiction was present.
- [x] Ledger Actions remain restricted to the accepted enum; report-only `proposed` states were converted to legal final `applied`, `already-present`, or `excluded-with-reason` states.
- [x] Exact range/bytes/hash/instruction/CFG/vtable/RTTI/EBO/allocator/global/caller/padding/compiler/history/negative evidence preserved at report-level detail.
- [x] Owner/emitter/reconstructable distinctions and exact child positions `10/20/30/40/50/60` preserved.
- [x] Scalar/adjustor/vtable/SEH/cookie/object-free exclusions preserved; no handwritten ABI glue added.
- [x] One short lease used only for each ordinary page being edited; each scoped validator ran before immediate release.
- [x] One final authorized waited generated refresh completed after all ordinary pages validated.
- [x] Generated HelpPanes.cpp verified for exactly one complete SimpleHelpPane class, one each constructor/destructor/paint/timer/pointer/key definition in order, one singleton definition, one helper pair, no UID00048F Empty Emitter Marker, no duplicate global, and no scalar/adjustor/vtable ABI source.
- [x] Exact supervisor-owned manual coverage text retained; manual coverage was not edited by B002.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation at exact Gate-1 SHA.
- [x] All accepted target/support doc details incorporated without compression.
- [x] Claim ledger updated to legal final states with destination proof outside state cells.
- [x] Metadata/score/owner/emitter/position/C++ changes applied or explicitly excluded with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions remain closed; no weaker inference replaced accepted evidence.
- [x] Scoped validators and command IDs/timestamps/results/warnings/side effects recorded.
- [x] Every lease released and release proof recorded.
- [x] Final waited generated refresh/readback recorded with SHA and exact counts.
- [x] Remaining unapplied accepted items: none; manual coverage and report lifecycle are external ownership, not callback blockers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000011543","destination_path":"executed-b-agent-research/B002/00048F-SimpleHelpPaneDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00048F-SimpleHelpPaneDestructor-source-quality.md","timestamp":"2026-07-14T12:41:56-04:00","uid":"00048F"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
