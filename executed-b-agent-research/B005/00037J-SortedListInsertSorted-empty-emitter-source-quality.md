** TARGET-REPORT-UID:00037J **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00037J SortedListInsertSorted Empty Emitter Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: keep UID00037J as a reconstructable SortedList method owned and emitted by UID0000DF, place its source in the existing UID0000NU NexusTK/util/SortedList.cpp route, and populate its formal CPP channel with the exact human-source reconstruction in this report.
- Final disposition: the empty emitter is a documentation/source-channel omission, not dead code, compiler glue, a no-code duplicate, or an ownership problem. The function is an ordinary non-virtual int SortedList::InsertSorted(const void *element) body at 0x004f3690-0x004f377b.
- Accepted ordinary callback disposition: the target, SortedList class/file pages, mixed SortedList index, and combined List/SortedList vtable-data page contain the literal accepted ledger payloads. Class-owned CPP/H now makes `SortedList.cpp` include both `SortedList.h` and `MemoryMan.h`, giving the inserted method legal declarations for `MemoryMan`, `GetMemoryMan`, `size_t`, and the MemoryMan member calls, while `SortedList.h` owns only the public class declaration and child insertion route.
- Stable supervisor disposition: ordinary implementation and same-or-greater/no-edit support claims C37J-001 through C37J-032, supervisor-owned IDA Gate 2B claims C37J-033 through C37J-050, and manual/generated claims C37J-051 through C37J-077 are applied and read back. Commands `000000020960` through `000000020962` are bounded evidence-time validations of the three manual coverage files, and coherent full autogen command `000000020963` is the bounded evidence-time generated CPP/H/routing/score snapshot. C37J-078 records the lifecycle-neutral invariant that report execution/archive registration is always determined from the artifact's current path plus validator-owned status/history/registry; this report body does not encode a current transition, report count, or archive path.
- Current IDA handoff disposition: the earlier exact artifact SHA256 `65AE7225834057257148C2488B135EB256EA94F75583E9DD5346B1826F6D2E56` passed Gate 1 `33/33` and ordinary Gate 2A `29/29`, then failed closed during the first historical Gate 2B attempt because successful F1 semantic `set_type` did not mutate physical `Src`/`void *`; canonical/backup SHA256 `4E6757...`, discarded PID `13484`, and `b005-rollback-clean` remain preserved no-save rollback evidence and receive no completion credit. The completed supervisor transaction instead started from canonical IDB size `143,196,257`, SHA256 `400BFA5A1AE2E6C16906DB75060D2A1FDE30BB8DE8DDAB22758FDDC557A84948`, with fresh byte-identical backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID00037J-prestate-20260803-225322`, bound sole session `b002-persist-reopen` PID `11812`, re-read every T1/F1/F2/P1-P11 prestate, executed the repaired literal semantic-plus-physical contracts, verified every poststate/protection, and saved once. The saved canonical IDB is size `143,196,412`, SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0`; fresh sole session `b005-persist-reopen` PID `2652` is healthy with Hex-Rays ready and proves exact persistence of T1/F1/F2 and every P1-P11 protection. No `execute_report` or lifecycle action is implied.
- Confidence: very strong for behavior, range, ABI, layout, ownership, emitter route, callers, equal-key insertion order, allocation/move/copy behavior, and formal source. Exact original spelling and access text do not survive, but InsertSorted, public access, m_compare, and standalone SortedList.cpp are the highest-probability source reconstruction and are adopted rather than deferred.

## Supporting Research

- Report authorship state: this artifact was initially prepared as B005's report-only Gate 1 deliverable and was later additively reconciled with the accepted ordinary callback. Report execution/archive state is supervisor-owned and authoritative only from the artifact's current path plus validator-owned status/history metadata.
- Live read-only IDA MCP evidence came from HTTP MCP session 0c9917fc-e375-45fc-9617-934bda8de805 against E:\NTK\Resources\NexusTK\NexusTK.exe.i64. The detailed bounded pass used evidence-time IDB session b3b2bf88; after the adopted worker rolled over without any B005 process-control action, evidence-time session 32a23a83 revalidated status ok, image base 0x00400000, auto_analysis_ready true, hexrays_ready true, strings_cache_ready true, target/reallocator names and bounds, target disassembly/frame, both actionable comment prestates, both exact xref inventories, and the absent SortedList/opaque List/MemoryMan type state. Later evidence-time session 2ee51d9a independently reconfirmed that SortedListCompareFunction is absent and both proposed function names have zero collisions. Session IDs are bounded evidence snapshots, not claims about a worker's later lifecycle state.
- Historical Gate2B-repair evidence came from read-only IDB session `b899a907` against then-current IDB SHA256 `39DDCCB79488103D6DA43B910AE616CB507F5666B6722754881F1C7CFEEC20D2` (`143,195,880` bytes). It remains useful provenance for the F2/P3 correction but is not current authority.
- Fresh pre-transaction authority came from evidence-time worker `b004-gate2b-current` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. `server_health` returned `status:ok`, image base `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and ready string/Hex-Rays caches. The saved IDB was SHA256 `4E6757FAA6234898FF8303944146E646F06395F09B1292E9389DB0020D6B1CE6`, `143,196,194` bytes, last saved `2026-08-03T01:54:21-04:00`. This bounded pass re-read T1/F1/F2/P1-P11 and all report-promised protections; B005 did not start, stop, restart, mutate, or save IDA/MCP.
- Historical supervisor Gate 2B transaction and rollback: canonical prestate SHA256 `4E6757FAA6234898FF8303944146E646F06395F09B1292E9389DB0020D6B1CE6` and backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID00037J-prestate-20260803-202459` matched exactly. T1 succeeded after `declare_type` used a one-element `decls` array and read back the exact typedef/0x18 UDT. F1 rename and semantic function `set_type` succeeded, and `func_profile` read back `int __thiscall SortedList_InsertSorted(SortedList *this, const void *element)`, but `stack_frame` still read physical `Src` at `+0x1c`, width 4, `void *`. The supervisor stopped before F1 comment, F2, manual/generated work, validation, or save; killed unsaved PID `13484`; verified the disk hash unchanged; reopened `b005-rollback-clean`; and read back exact restored T1 absence plus original F1/F2 names, prototypes, frames, and comments. This empirically disproves prototype-propagation-only handling and motivates the explicit stack operations below.
- Historical pre-transaction read-only rebase: `idb_list` returned sole worker `b002-persist-reopen` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. `server_health` returned `status:ok`, image base `0x400000`, `auto_analysis_ready:false`, `hexrays_ready:true`, and ready caches; the false analysis flag did not impair bounded queries. The canonical prestate was SHA256 `400BFA5A1AE2E6C16906DB75060D2A1FDE30BB8DE8DDAB22758FDDC557A84948`, `143,196,257` bytes. Fresh reads proved both proposed types absent, List/MemoryMan opaque, original F1/F2 names/prototypes/physical rows/four absent comment channels, and exact P1-P11 profiles, frames, comments, xref totals `2/14/1/1/1/1/612/132/604/19/1`, separate vtable items, and byte hashes. This paragraph is preserved as the successful transaction's immediate prestate, not current post-save authority. B005 performed no IDA/MCP mutation, save, or process control.
- Completed supervisor Gate 2B transaction: before mutation the supervisor verified canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` at `143,196,257` bytes/SHA256 `400BFA5A1AE2E6C16906DB75060D2A1FDE30BB8DE8DDAB22758FDDC557A84948` and created byte-identical backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID00037J-prestate-20260803-225322`. Sole session `b002-persist-reopen` PID `11812` matched all immediate T1/F1/F2 and P1-P11 prestates. T1, F1, and F2 then applied in the literal order below, including direct physical stack-row dry-run/actual/type operations and exact repeatable comments. Full pre-save verification passed every actionable and protected surface. A first verifier's exact-inventory assertion was inconclusive only because the MCP batch result truncated; individual F1/F2 xref queries immediately proved the exact inventories, and no entity drift occurred.
- Saved and reopened authority: `idb_save` returned `ok:true` to the canonical path. The saved IDB is `143,196,412` bytes with SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0`. After the saved worker stopped, the supervisor reopened the canonical IDB as sole session `b005-persist-reopen` PID `2652`; health is `ok` and Hex-Rays is ready. Fresh-session readback proved exact T1 types, F1/F2 names/prototypes/physical frames/repeatable comments/decompilation, F1's 96 instructions/13 exact xrefs/11 internal comments, F2's 52 instructions/10 exact xrefs/EH, and every P1-P11 byte/xref/item/comment/frame protection. These are supervisor-owned C37J-033 through C37J-050 completion facts; B005 performed no IDA mutation, save, or process control.
- Initial pre-callback documentation snapshots used by the exact Gate 1 artifact:
  - target by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md: SHA256 CE2C278ABF74E2F8F87CD709E325F8774F2B1C7603EB1839CD4527AA6055CEF3, 6,326 bytes, 83 lines
  - class by-class/SortedList.md: SHA256 E0E4768AE9FD9E049E92939D6320C044477CD6EC12154B1BF1A538160FEF5301, 11,696 bytes, 109 lines
  - file by-file/SortedList.md: SHA256 DE3C701AAFFE01BB0B81F30BC222AB52931A285C33D2CA616B2B408171E37E9B, 9,048 bytes, 83 lines
  - mixed index by-memory/0x004f3600-0x004f3a43.SortedList.md: SHA256 32494307F0F1A22508CDA6DAAB2AA2790D4E30C5DB00CAF8C3901994F072E6C7, 14,890 bytes, 104 lines
- Matching executed-report leads were searched by 00037J, 0x004f3690, SortedListInsertSorted, and InsertSorted. B003 UID0000ZW and B015 UID000084 were relevant leads and were rechecked against the live IDB/current docs.
- Stale Wave2/Wave3 material was not used.

## Target

- Target UID: 00037J.
- Additional target UIDs: none. Support pages are implementation destinations, not additional report targets.
- Target path: by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md.
- Pre-callback source queue snapshot: auto-generated/-ag-research-tracker.md SHA256 C6AF39CD402388A78C5267E085668C4756448F23C1EC836032CF5A18A3B7AAE5, 1,698,562 bytes, 6,698 lines, validator command 000000020824, refreshed 2026-08-02T23:21:34-04:00. Literal row 2977 then recorded UID00037J, 91/94, reconstructable true, and zero direct/additional/total reports.
- Pre-callback generated symptom snapshot: auto-generated/NexusTK/util/SortedList.cpp SHA256 20FCE1D47448576172C3D6BEF700A1E795499393DCE712BF53276953C2BC1AAA, 533 bytes, 9 lines, command 000000020822, refreshed 2026-08-02T23:04:37-04:00. Line 9 was the UID00037J Empty Emitter Marker; line 7 was the separate UID0000DF class empty marker.
- Pre-callback generated header symptom at command 000000020822: auto-generated/NexusTK/util/SortedList.h was absent because UID0000DF and UID00037J both had blank H channels. The ordinary callback populated the accepted class H payload while target H remained blank; generated readback is still supervisor-owned.
- Pre-callback generated route snapshot: auto-generated/-ag-memory-coverage.md SHA256 FAAC3877D2BF405538B0961699BF221D5FD3176EE3D07DD499405E98249A762E, 1,437,725 bytes, 5,006 lines, command 000000020822. Literal row 3173 then routed UID00037J through owner/emitter UID0000DF to auto-generated/NexusTK/util/SortedList.cpp and recorded no CPP/H contribution.
- Stable supervisor classification: source-quality research plus accepted ordinary callback evidence for UID00037J. Supervisor Gate 2 and report execution/archive status remain external audit/validator lifecycle truth rather than mutable body text.
- Accepted ordinary target state: completion 96, confidence 96, owner/emitter UID0000DF, reconstructable true, blank position, exact nonblank formal CPP, and blank formal H.

## Current Target State

- Accepted ordinary callback state: B005 applied and read back C37J-001 through C37J-023, ran and read back C37J-056 through C37J-060, and reconciled this same report under C37J-079. These facts are documentary callback evidence; supervisor Gate 2 and report execution/archive state remain authoritative only from supervisor audit/validator lifecycle records.
- Supervisor evidence state: the historical failed/no-save F1 attempt and `b005-rollback-clean` restoration remain evidence only. The supervisor directly verified same-or-greater/no-edit C37J-024 through C37J-032 at the exact support identities recorded below, closed IDA C37J-033 through C37J-050 at canonical SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0`, applied/validated M01-M05, completed coherent autogen `000000020963`, and read back C37J-051 through C37J-077. All target-research, ordinary-document, IDA, manual, and generated-evidence claims are closed; report lifecycle state is external path/history/registry authority rather than an unchecked body claim.
- Target UID00037J is `96/96`, owned/emitted by UID0000DF, reconstructable true, with the exact report CPP payload and blank H channel. It now records complete behavior/failure semantics, all thirteen direct callers, all twelve Message index-normalizer pairs, after-equals insertion, adopted human source naming/access, and standalone source placement.
- Class UID0000DF is `94/94`, owned/emitted by UID0000NU, with the exact two-include CPP shell and exact complete H declaration. It records `RemoveAt`/`RemoveAll`, public sorted helpers, private `m_compare`, the `0x18` layout, ten-slot vtable, caller/invariant/failure evidence, and standalone CPP/H route; `List.cpp` folding is historical only.
- File UID0000NU is `92/92` and selects `NexusTK/util/SortedList.cpp` plus `SortedList.h`. It inventories the class, exact source children, generated vtable route, dependencies, consumers, and explicit UID00037L base-List exclusion.
- Mixed UID000193 is `91/93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, with blank emitter and CPP/H channels. Its current item/status/score text explains completed exact-child ownership and preserves old below-`85/85` wording only as superseded history.
- Vtable UID0003OL is `90/94`, owned/emitted by UID0000KS, with its declaration-generated CPP marker and blank H unchanged. It records locator `0x00649d78`, all ten ordered `SortedList` slots, successor locator, constructor-only xref `0x004f3669`, and the List scalar-wrapper route.
- Post-validator destination identities:
  - `by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md`: SHA256 `5190C47498F158A2B084F7892ECE6533D81233BD973F2EF9DE4AC3A37D4825F8`, 13,170 bytes, 167 lines.
  - `by-class/SortedList.md`: SHA256 `311745D5D8826C5096F7F55D7AEFE006D33DBC8F3AE416E7D5C3857799F85BD3`, 17,525 bytes, 177 lines.
  - `by-file/SortedList.md`: SHA256 `CD5F763D50E93C2CF607117EA94FCE5BA6FDBBBB5EB8D0A0636D83344E6C8C4F`, 11,824 bytes, 99 lines.
  - `by-memory/0x004f3600-0x004f3a43.SortedList.md`: SHA256 `4906E29A134EB264AB4515BA6B1230B5BAF0EF876C4B12A259F51BB201CDF03C`, 17,201 bytes, 120 lines.
  - `by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md`: SHA256 `7F2B7219589B8A1ACFCA237AA14D701A5FA72A4E812D561F2FB3F9CEE1375A2A`, 11,081 bytes, 95 lines.
- Evidence-time supervisor-verified generated readback:
  - coherent command `000000020963` produced `auto-generated/NexusTK/util/SortedList.cpp` SHA256 `3A53E5B0273780257B285015567E2149455559B3E51E75CDD828FDBD45DC4E19`, 1,871 bytes, 61 lines. It contains UID0000DF's exact `SortedList.h`/`MemoryMan.h` include shell and UID00037J's exact accepted method body; neither former Empty Emitter Marker remains.
  - the same command produced `auto-generated/NexusTK/util/SortedList.h` SHA256 `81467431B89434E01BCCD8FA0475417A2B7A5E84D4C51392DA3AB7BFD4762319`, 929 bytes, 30 lines. It contains UID0000DF's accepted class declaration, exactly one `InsertSorted` declaration, and no UID00037J-specific duplicate contribution.
  - At evidence time, command 20963 produced `auto-generated/-ag-memory-coverage.md` SHA256 `CEAFBEFFB6782C2D19C272B59809B53303AE565047EF4016E88A198527D3D2E8`, `auto-generated/-ag-class-coverage.md` SHA256 `DB6E59E30D40A5EBDBD49EAFB95739C7A8D28DAC202CA0B880D4C97B89CDC58A`, `auto-generated/-ag-file-coverage.md` SHA256 `0208F2A995375DC0F25FA013A943870A5C30DC6A1B9A66FEBDDDD9E55E1CD4C7`, and `auto-generated/-ag-global-coverage.md` SHA256 `58EB72E4B78721D123CE6C56627705F3556C77AED93446AAC13C39B636E02E2A`. The bounded snapshot routes UID00037J as coded through UID0000DF to `SortedList.cpp` with CPP yes/H no, UID0000DF as coded through UID0000NU to CPP/H, UID0000NU as the coded FILE root, UID000193 as NONE/false/no output, and UID0003OL through UID0000KS to generated `List.cpp` data output.
  - At evidence time, command 20963 produced `auto-generated/-ag-research-tracker.md` SHA256 `EA0B1EFBDD60C9EC3587C24D7770CC2A7A7D6C28269204CA1DDB407CA016BD58`, 1,700,106 bytes, 6,703 lines. Its bounded snapshot rows read UID00037J `96/96` true, UID0000DF `94/94` true, UID0000NU `92/92`, UID000193 `91/93` false, and UID0003OL `90/94` true, with zero direct/additional/total report coverage at that evidence time. Tracker report-registration counts and paths are dynamic external validator truth and are never asserted here as current lifecycle state.
  - Earlier generated identities retained as history only: commands `000000020957`, `20946`, `20906`, and `20892` established the same substantive SortedList result at their historical times; command 20963 likewise remains an evidence-time snapshot rather than dynamic lifecycle authority.
- Related literal paths checked:
  - by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md
  - by-class/SortedList.md
  - by-file/SortedList.md
  - by-memory/0x004f3600-0x004f3a43.SortedList.md
  - by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md
  - by-memory/0x00520e30-0x00521d94.MessageCore.md
  - by-class/Message.md
  - by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md
  - by-memory/0x00516190-0x00516210.ReallocateOrThrow.md
  - by-class/List.md
  - by-file/List.md
  - by-class/MemoryMan.md
  - by-file/MemoryMan.md
  - by-memory/-ignored.md
  - by-project-structure/proposed-source-tree.md
- Artifact/lifecycle boundary: this report records stable evidence, accepted ordinary callback facts, completed supervisor-owned IDA/save/fresh-reopen state, verbatim M01-M05 application and scoped validation, and the bounded command-20963 generated readback. Gate/audit evidence and report execution/archive registration remain external and authoritative only from supervisor audit plus the artifact's current path and validator-managed status/history/registry metadata.

## Executive Recommendation

- Direct owner/emitter UID0000DF is retained; the body is not moved to ChangeMan, Message, List, MemoryMan, the mixed index, or a new helper file.
- UID00037J carries the exact accepted method body for `NexusTK/util/SortedList.cpp`. UID0000DF carries `#include "SortedList.h"`, `#include "MemoryMan.h"`, and the children marker in CPP plus the complete `SortedList : public List` declaration, public constructor/destructor/overrides/non-virtual methods, private `ListCompareFunction m_compare`, size guard, and children marker in H. `MemoryMan.h` remains CPP-only because the public declaration exposes no MemoryMan type.
- Source contract is public `int InsertSorted(const void *element)`, with after-equals insertion because only a negative comparator result breaks the scan. Twelve Message helpers consume the returned index; ChangeMan intentionally ignores it.
- All exact ranges remain unchanged. No split, merge, child creation, reclassification, or padding change was required by the ordinary callback.

## Supervisor Active Recheck

- Trigger: investigate UID00037J as an actual reconstructable empty emitter and resolve all source-quality blockers now.
- Split-first check: exact modeled child already exists. Padding 0x004f3681-0x004f3690 and 0x004f377b-0x004f3780 is correctly ignored.
- Source-child check: UID00037J itself is the source-bearing child; no missing child blocks CPP.
- Parent gate snapshot before callback was target 91/94, class 91/90, file 86/86. Accepted ordinary state is target 96/96, class 94/94, and file 92/92 with the same route.
- Duplicate check: UID000193 is non-emitting; UID0003OL emits only generated-data disposition. Target CPP creates no duplicate body.

## Inference Research Guidance Check

- by-structure requires exact child ownership, separate CPP/H channels, no aggregate duplication, and supervisor-only manual coverage edits. The recommendation follows those constraints.
- Rechecked uncertain assumptions: source name/access, comparator argument order, equal placement, page arithmetic, helper names/types, file split, Message return use, and vtable naming.
- Direct IDA facts are bytes/ranges/prototypes/xrefs/frames/vtable dwords/calls/branches/decompilation.
- Documentation evidence is current metadata, source tree, generated route, List declaration, Message inventory, and coverage rows.
- Inferences supply lost source spelling/access only and are explicitly marked.
- Wave2/Wave3 evidence was ignored.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence | Resolution | Status |
| --- | --- | --- | --- |
| Raw target name | exact body/class/callers; no collision | SortedList::InsertSorted, IDA SortedList_InsertSorted | inferred name, direct role |
| Return | mov eax,ebx; retn 4; twelve EAX consumers | int | direct |
| Parameter | one pointer; only reads copied bytes | const void *element | direct plus const inference |
| Comparator | call at +0x14 gets new then current | ListCompareFunction m_compare | direct |
| Equal ordering | zero continues, negative breaks | insert after all equals | direct |
| Message duplicate use | insert call followed by normalizer; initial sequence INT_MAX | returned index locates newly appended equal entry | direct/documented |
| Layout | constructor/target use +04/+08/+0c/+10/+14 | elementSize/pageSize/count/data/compare, size 0x18 | direct |
| Page arithmetic | exact signed branches and page formulas | preserve minimum-one-page arithmetic | direct |
| Failure | allocate/reallocate throw Win32Error pointer | no null-return branch | direct |
| Raw helper | 0x516190 source doc exact, IDA stale | MemoryMan::ReallocateBufferMemory | direct/accepted |
| Access | unrelated direct consumers | public InsertSorted | strong inference |
| Field access | no external direct use/derived class | private m_compare | strong inference |
| Source file | source tree/by-file/generator/RTTI | standalone SortedList.cpp/.h | reconstruction decision |
| Override names | base slot order | GetElementAt, RemoveAt, RemoveAll | direct |
| Aggregate | contains List-owned destructor | nonreconstructable/no emitter | direct |
| Translation-unit dependencies | target body uses MemoryMan, GetMemoryMan, size_t, and four MemoryMan methods; accepted MemoryMan class/file docs own their declarations | class CPP shell includes MemoryMan.h after SortedList.h; no MemoryMan declaration leaks into SortedList.h | resolved |
| C++ readiness | exact body/declaration and legal dependency route are explicit | populate formal channels now | resolved |

Rejected alternatives:

- void/bool return: conflicts with twelve index consumers.
- insert-before-equals: conflicts with zero-result loop advance.
- qsort/std::vector/template rewrite: loses fixed-width storage, page growth, MemoryMan calls, and era shape.
- current List.cpp fold: weaker historical possibility, contrary to current explicit route.
- handwritten vtable initializer: compiler-generated.
- modern guards: absent in binary and behavior-changing.

No source-quality blocker remains that prevents formal source or score movement. The earlier one-header CPP shell was incomplete; adding `MemoryMan.h` closes that concrete declaration dependency without changing the reconstructed body or public header.

## Evidence Standards Used

- Hard evidence: live MCP boundaries, decompilation, stack frames, exact xrefs, instruction query, bytes, vtable dwords, current names/types/comments, type existence, and collision checks.
- Corroboration: target/class/file/index/vtable docs, exact List H, MemoryMan source, Message inventory, ChangeMan source, proposed tree, generated output, and manual rows.
- Negative evidence: no alternative function/name/type, no extra xrefs, no source bytes in padding, no aggregate emitter, no missing child.
- Binary facts control behavior/ABI; accepted docs control shared vocabulary; project structure controls output route; inference restores lost human spelling/access.
- The initial worker's `auto_analysis_ready:false` did not impair any bounded query. Evidence-time sessions `5e9a7a86`, `b899a907`, `b004-gate2b-current`, and failed/no-save rollback sessions remain historical provenance. Pre-transaction session `b002-persist-reopen` PID `11812` successfully served every bounded query and mutation checkpoint despite its earlier false analysis-ready flag. Current saved authority is fresh sole session `b005-persist-reopen` PID `2652`, `status:ok`, Hex-Rays ready, against canonical SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0`.

## Evidence Checked

- MCP: idb_list, server_health, lookup_funcs, analyze_function, decompile, xrefs_to, xref_query pagination, insn_query, stack_frame, get_comments, get_bytes, inspect_items, type_inspect, entity_query.
- Functions checked: 0x4f3600, 0x4f3690, 0x4f3780, 0x4f38b0, 0x4f3950, 0x4f3980, 0x4f3990, 0x516030, 0x516050, 0x516190, 0x516220, 0x516240.
- Data checked: target boundaries, SortedList vtable bytes, locator, ten slots, constructor vtable xref.
- Docs/old reports/generated/manual sources: all Current Target State paths plus B003 UID0000ZW and B015 UID000084 reports as leads.
- Negative checks: exact xref count 13; SortedList UDT absent; desired names collision-free; padding exact; broad parent non-emitting.
- Exact pre-transaction checks in evidence-time IDB session `b004-gate2b-current`: `server_health`, `func_profile`, `stack_frame`, `get_comments`, `type_inspect`, `lookup_funcs`, fully paginated `xref_query`, `get_bytes`, `inspect_items`, and `get_global_value` rechecked all eighteen C37J-033 through C37J-050 rows. All names/ranges/prototypes/comments/frames/xrefs/items/values/bytes matched the T1/F1/F2/P1-P11 contracts below. Desired function names were collision-free; `SortedList` and `SortedListCompareFunction` were absent; `List` and `MemoryMan` were opaque non-UDT types. Clean rollback session `b005-rollback-clean` later reconfirmed those actionable prestates after the failed unsaved transaction.
- Pre-transaction checks in `b002-persist-reopen` repeated `server_health`, `type_inspect`, `lookup_funcs`, `func_profile`, `stack_frame`, `get_comments`, `xref_query`, `get_bytes`, and `inspect_items` against canonical SHA256 `400BFA5A1AE2E6C16906DB75060D2A1FDE30BB8DE8DDAB22758FDDC557A84948`, `143,196,257` bytes. They proved the exact T1/F1/F2 prestates and all P1-P11 protections immediately before mutation.
- Completed transaction/readback checks used the literal `declare_type`, rename, semantic `set_type`, physical stack dry-run/actual/type, function-repeatable-comment, protection, and save order recorded below. Before save, all T1/F1/F2 poststates and P1-P11 protections passed; the only verifier anomaly was MCP batch-result truncation for one exact-inventory assertion, resolved by individual exact F1/F2 xref queries with no entity drift. `idb_save` returned `ok:true`.
- Fresh-persistence checks in `b005-persist-reopen` PID `2652` repeated health, type inspection, profiles, complete physical frames, all four comment channels, decompilation/EH, exact F1/F2 xref inventories, F1's eleven internal comments, P1-P11 xref totals/items, and every listed byte SHA256. Current saved authority is SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0`, `143,196,412` bytes.
- Exact baseline detail: all thirteen protected byte SHA256 values are unchanged. Full pagination returned P7 `612/612` unique xrefs with normalized inventory SHA256 `0C756CF243C102471CFC4A7D25BAB6D6AC3A8FB156D26BE381074104D0BC9178`, P8 `132/132` with SHA256 `98C59AE04B8C12B813484245F0D9542D77B105B74C027B3C73FDE2974BAE79AD`, P9 `604/604` with SHA256 `A6474EA94839EB47A0BF9EE2B1852D2DA3B375852484A3B16EDAAB6EF3FA4F61`, and P10 `19/19` with SHA256 `7A26A5D0CCBF4AE98A13950ACC942F3717D8A81F97E9D98A2288DCB6D3A94EC5`. F1/F2 remain `13`/`10`; P11 retains the sole constructor data xref `0x004f3669`, ten separate blank-typed four-byte items, locator `0x00649d78`, the ten recorded slots, and successor locator `0x00649dc8`.
- Evidence-time non-IDA supervisor evidence was independently re-read: all three manual coverage files contain exact M01-M05 at their anchors and match the post-validation hashes under the manual-text section; bounded command-20963 generated CPP/H, memory/class/file/global coverage, and research-tracker snapshot identities/rows match C37J-066 through C37J-077. B005 did not edit, validate, or refresh those supervisor/validator-owned artifacts; commands 20957/20946/20906/20892 remain historical only, and dynamic tracker lifecycle fields remain external authority.
- C37J-024 no-edit readback: `by-memory/0x00520e30-0x00521d94.MessageCore.md` SHA256 `E808EF5CF74920B8ACBDA79604E3822E213553E0DA95BB60850D95CF551B28AD` contains the exact 24-helper band, InsertSorted calls, duplicate-sequence normalizer, and comparator detail.
- C37J-025 no-edit readback: `by-class/Message.md` SHA256 `C2FDCA40E3026B3A1AAB4A6EC8DE6B9555A45A0A9ED215A3EC16ABA626E393D2` contains the owned SortedList, 0x98 MessageEntry schema, comparator, and duplicateOrdinal behavior.
- C37J-026 no-edit readback: `by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md` SHA256 `93DA1DA022C55C144D1136AC4EB2B2C08C2263F02FF3CBBEB2CC97C02244C75A` states the exact ignored InsertSorted return and ChangeManEntry route.
- C37J-027 no-edit readback: `by-memory/0x00516190-0x00516210.ReallocateOrThrow.md` SHA256 `D2256B28E9607DE22E8BAE846DE8539A0DB62F4FA1218B98FD420C6B4D1C559F` contains formal `MemoryMan::ReallocateBufferMemory(void *, size_t)`, realloc-or-throw-new-Win32Error behavior, and source route.
- C37J-028 no-edit readback: `by-class/List.md` SHA256 `9C69E4F370A64A0F15217DB58D2A8BC74D62691DC088E6811EB6888421FD2011` contains `ListCompareFunction`, the exact 0x14 declaration, virtual vocabulary, and four state fields.
- C37J-029 no-edit readback: `by-file/List.md` SHA256 `61A1347B4FB168105E191239D6EDAD585752FFE8530FCC24FDB087DF5E98E68E` contains the `NexusTK/util/List.cpp`/`List.h` route and sibling ownership.
- C37J-030 no-edit readback: `by-class/MemoryMan.md` SHA256 `9D18E2E0FBAD341A2273A016F7C9C042A60A21935514A6FAA3B7AC773D1605A5` owns the required MemoryMan member declarations and preserves `GetMemoryMan` as a file-level helper.
- C37J-031 no-edit readback: `by-file/MemoryMan.md` SHA256 `CC798C04D653795B74EDFB5581EA6AAFA24AB4FF07D62ED9B31C5F79B9352AB1` owns `MemoryMan.h`/`.cpp`, the `GetMemoryMan` declaration/definition, and `ReallocateBufferMemory` route.
- C37J-032 no-edit readback: `by-memory/-ignored.md` SHA256 `731B6A817734311150F210B0EC565146C9C58781F6EEE8FB60131E45C79DDF6A` retains exact `0x004f3681-0x004f3690` and `0x004f377b-0x004f3780` `0xcc` padding spans in the full SortedList alignment list.
- Historical initial report-only phase: the initial IDB worker rolled over after completing bounded reads; evidence-time session 32a23a83 immediately revalidated the actionable prestates and target body. No evidence route remained failed and no IDA mutation/save occurred. No validator ran during that initial report-only phase; the later accepted ordinary callback ran exactly the five scoped validators recorded under Validator Results.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Expected readback | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| C37J-001 | 00037J | Comparator scan, page growth, tail shift, count increment, fixed-width copy, return order, and invalid-input/failure behavior | very strong | target bytes/decompile/callees | by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md / Behavior, Raw Code Evidence | incorporate | all listed operations and exact ordering present without modern guards | applied |
| C37J-002 | 00037J | Exact 13 caller addresses and caller roles | very strong | live xrefs and caller checks | by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md / Callers And Relationships | incorporate | all 13 addresses and one ChangeMan/twelve Message roles present | applied |
| C37J-003 | 00037J | Exact twelve InsertSorted-to-normalizer EAX pairs and duplicate-sequence meaning | very strong | raw Message call sequences/current docs | by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md / Callers And Relationships | incorporate | all twelve ordered address pairs and EAX-index contract present | applied |
| C37J-004 | 00037J | Exact formal int SortedList::InsertSorted(const void *) body | very strong | binary control/data flow/accepted helper APIs | by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md / RECONSTRUCTION_CPP | incorporate | formal CPP equals report target payload byte-for-byte | applied |
| C37J-005 | 00037J | Target H stays blank because class UID0000DF owns the declaration | very strong | by-structure channel ownership | by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md / RECONSTRUCTION_H | already-present | H block remains blank and prose names UID0000DF declaration owner | already-present |
| C37J-006 | 00037J | Score 91/94 to 96/96; owner/emitter 0000DF and reconstructable true unchanged | strong | closed blocker audit/formal body | by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md / metadata, Score Rationale | incorporate | metadata reads 96/96, 0000DF, true, CPP nonblank, H blank | applied |
| C37J-007 | 0000DF | Class CPP includes SortedList.h and MemoryMan.h before children | very strong | target dependencies/accepted class-emitter pattern | by-class/SortedList.md / RECONSTRUCTION_CPP | incorporate | exact class CPP payload present with two includes and one children marker | applied |
| C37J-008 | 0000DF | Exact SortedList declaration, methods, private comparator, size guard, and children route | strong | constructor/layout/vtable/List declaration | by-class/SortedList.md / RECONSTRUCTION_H | incorporate | formal H equals report class-H payload byte-for-byte | applied |
| C37J-009 | 0000DF | Source-facing methods/access/layout | strong | live IDA/List H/callers/vtable | by-class/SortedList.md / method map, layout, source-quality sections | incorporate | InsertSorted/FindFirstEqual/RemoveAt/RemoveAll, public APIs, private m_compare, 0x18 layout present | applied |
| C37J-010 | 0000DF | Exact vtable, callers, after-equals invariant, allocation/failure behavior | very strong | vtable bytes/xrefs/target/callers | by-class/SortedList.md / vtable, behavior, consumers | incorporate | complete slot/caller/invariant/failure evidence present | applied |
| C37J-011 | 0000DF | Standalone SortedList.h/.cpp is the current source route | strong | tree/by-file/generator/RTTI/island | by-class/SortedList.md / source placement | incorporate | standalone route stated as current decision | applied |
| C37J-012 | 0000DF | List.cpp folding is a rejected historical alternative | strong | weaker proximity evidence superseded by current route | by-class/SortedList.md / historical assumptions | historicalize | old fold retained only as dated/rejected history with reason | applied |
| C37J-013 | 0000DF | Score 91/90 to 94/94; owner/emitter 0000NU unchanged | strong | complete declaration/support evidence | by-class/SortedList.md / metadata, score rationale | incorporate | metadata reads 94/94 with owner/emitter 0000NU | applied |
| C37J-014 | 0000NU | Standalone NexusTK/util/SortedList.cpp and SortedList.h route | strong | tree/root/generator/RTTI | by-file/SortedList.md / module, source placement | incorporate | standalone CPP/H route stated as current | applied |
| C37J-015 | 0000NU | List.cpp folding is retained only as rejected history | strong | weaker historical proximity evidence | by-file/SortedList.md / historical assumptions | historicalize | fold remains only in historical section with rejection reason | applied |
| C37J-016 | 0000NU | Complete class/method/vtable/caller/behavior inventory and neighboring List exclusion | strong | exact child inventory/ownership | by-file/SortedList.md / purpose, contents, evidence | incorporate | full emission inventory present and UID00037L excluded | applied |
| C37J-017 | 0000NU | Score 86/86 to 92/92 | strong | completed source-root/formal class route | by-file/SortedList.md / metadata, score rationale | incorporate | metadata reads 92/92 | applied |
| C37J-018 | 000193 | Current exact-child ownership and non-emitting mixed-index rationale | very strong | current child/class/file scores/mixed List bytes | by-memory/0x004f3600-0x004f3a43.SortedList.md / Item Summary, status | incorporate | current non-emitting split rationale present | applied |
| C37J-019 | 000193 | Stale below-85 assignment/gate wording | very strong | all exact source children now clear gate | by-memory/0x004f3600-0x004f3a43.SortedList.md / historical assumptions | historicalize | stale wording retained only as superseded history with reason | applied |
| C37J-020 | 000193 | Score 90/92 to 91/93; NONE/FALSE/blank emitter/code unchanged | strong | complete child split/persistent mixed ownership | by-memory/0x004f3600-0x004f3a43.SortedList.md / metadata, score rationale | incorporate | metadata reads 91/93, NONE, false, blank emitter/CPP/H | applied |
| C37J-021 | 0003OL | Correct locator 0x00649d78, exact ten slots, constructor-only xref | very strong | live bytes/xrefs | by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md / data inventory, evidence | incorporate | locator, ten ordered slots, and xref 0x4f3669 present | applied |
| C37J-022 | 0003OL | Declaration-generated/no-handwritten-vtable disposition and List scalar-wrapper route | very strong | compiler RTTI/vtable/current formal marker | by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md / rebuild handling, history | incorporate | generated marker/no handwritten initializer and List wrapper route present | applied |
| C37J-023 | 0003OL | Score 88/92 to 90/94; owner/emitter 0000KS/generated marker unchanged | strong | corrected complete inventory | by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md / metadata, score rationale | incorporate | metadata reads 90/94, owner/emitter 0000KS, generated marker retained | applied |
| C37J-024 | 0002Y5 | MessageCore already has same-or-greater helper/comparator/normalizer/tag/duplicate detail | very strong | supervisor exact SHA `E808EF5C...B28AD` readback | by-memory/0x00520e30-0x00521d94.MessageCore.md | already-present | exact 24-helper/InsertSorted/normalizer/comparator detail; no edit | applied |
| C37J-025 | 000084 | Message class already has same-or-greater SortedList consumer/record detail | very strong | supervisor exact SHA `C2FDCA40...393D2` readback | by-class/Message.md | already-present | owned SortedList, 0x98 MessageEntry, comparator/duplicateOrdinal; no edit | applied |
| C37J-026 | 0000ZW | ChangeMan Register already states ignored InsertSorted return and entry route | very strong | supervisor exact SHA `93DA1DA0...4C75A` readback | by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md | already-present | exact ignored-result/ChangeManEntry route; no edit | applied |
| C37J-027 | 0001BG | Reallocator page already has exact method source/realloc-or-throw behavior | very strong | supervisor exact SHA `D2256B28...C559F` readback | by-memory/0x00516190-0x00516210.ReallocateOrThrow.md | already-present | exact formal method/realloc-or-throw/source route; no edit | applied |
| C37J-028 | 000079 | List class already supplies base layout, typedef, virtual vocabulary, formal-H style | very strong | supervisor exact SHA `9C69E4F3...D2011` readback | by-class/List.md | already-present | exact typedef/0x14 declaration/virtual vocabulary/four fields; no edit | applied |
| C37J-029 | 0000KS | List file already supplies exact base source route/sibling ownership | very strong | supervisor exact SHA `61A1347B...E68E` readback | by-file/List.md | already-present | exact List.cpp/List.h route and sibling ownership; no edit | applied |
| C37J-030 | 00007U | MemoryMan class already owns MemoryMan/GetMemoryMan/member declarations required by CPP | very strong | supervisor exact SHA `9D18E2E0...05A5` readback | by-class/MemoryMan.md | already-present | required member declarations plus file-level GetMemoryMan; no edit | applied |
| C37J-031 | 0000L7 | MemoryMan file already owns the MemoryMan.h/.cpp source route | very strong | supervisor exact SHA `CC798C04...52AB1` readback | by-file/MemoryMan.md | already-present | MemoryMan.h/.cpp, GetMemoryMan, and reallocator route; no edit | applied |
| C37J-032 | 0000VN | Target pre/post padding is already recorded exactly | very strong | supervisor exact SHA `731B6A81...DDF6A` readback | by-memory/-ignored.md / UID0000VN entries | already-present | exact two `0xcc` spans remain in full alignment list; no edit | applied |
| C37J-033 | 00037J | Define exact flat 0x18 SortedList UDT/comparator typedef with one-element-array `declare_type` request | strong | supervisor transaction from exact `400BFA...` prestate and fresh matching backup; saved/fresh-reopen readback at `92CD98...` | IDA Gate 2B / T1 | incorporate | exact typedef and six-member 0x18 UDT read back; List/MemoryMan unchanged | applied |
| C37J-034 | 00037J | Rename sub_4F3690 to SortedList_InsertSorted | strong | literal supervisor F1 rename plus pre-save and `b005-persist-reopen` readback | IDA Gate 2B / F1 name | incorporate | exact name reads back at 0x004f3690 | applied |
| C37J-035 | 00037J | Apply exact F1 multi-step binding transaction: semantic function `set_type`; require exact `func_profile` while physical `Src`/`void *` remains at +0x1c; dry-run and execute literal occupied-row rename `Src` -> `element`; apply literal stack `set_type` `element` -> `const void *`; read the complete frame after every step; protect +0x0c var_8/struct MemoryMan *, +0x10 var_4/_DWORD, +0x14 __saved_registers/special, and +0x18 __return_address/special unchanged | very strong | completed literal semantic-plus-physical transaction; exact pre-save and fresh-reopen frame/profile/xref/comment/byte readbacks | IDA Gate 2B / F1 deterministic binding table and literal request sequence | incorporate | exact semantic prototype/ECX binding plus sole physical delta +0x1c; unaffected rows, row count, stack size, range, 96 instructions, 13 xrefs, 11 internal comments, and bytes match baselines | applied |
| C37J-036 | 00037J | Set exact target function-repeatable comment | strong | exact supervisor comment mutation plus four-channel pre-save/fresh-reopen readback | IDA Gate 2B / F1 comment | incorporate | function-repeatable equals payload; other three entry/function comments remain absent | applied |
| C37J-037 | 0001BG | Rename sub_516190 to MemoryMan_ReallocateBufferMemory | strong | literal supervisor F2 rename plus pre-save and `b005-persist-reopen` readback | IDA Gate 2B / F2 name | incorporate | exact name reads back at 0x00516190 | applied |
| C37J-038 | 0001BG | Apply exact F2 multi-step `__stdcall`-to-`__thiscall` transaction: semantic function `set_type`; require exact desired `func_profile` while physical +0x18 remains `Block`/`void *` and +0x1c remains `pExceptionObject`/`int`; dry-run/execute literal rename then stack-type `Block` -> `block`/`void *`; dry-run/execute literal rename then stack-type `pExceptionObject` -> `newSize`/`size_t`; read the complete frame after every step; protect +0x04 var_C/_DWORD, +0x0c var_4/_DWORD, +0x10 __saved_registers/special, and +0x14 __return_address/special unchanged | very strong | completed literal semantic-plus-physical transaction; exact pre-save and fresh-reopen profile/frame/EH/xref/comment/byte readbacks | IDA Gate 2B / F2 deterministic binding table and literal request sequence | incorporate | exact desired prototype/implicit ECX plus explicit physical +0x18/+0x1c poststate; protected rows, row count, stack size, range, EH, 52 instructions, ten xrefs, comments, and bytes match baselines | applied |
| C37J-039 | 0001BG | Set exact reallocator function-repeatable comment | strong | exact supervisor comment mutation plus four-channel pre-save/fresh-reopen readback | IDA Gate 2B / F2 comment | incorporate | function-repeatable equals payload; other three comments remain absent | applied |
| C37J-040 | 00037I | Protect constructor prestate | very strong | supervisor immediate prestate, full pre-save verification, and fresh-reopen persistence readback | IDA Gate 2B / P1 | already-present | name/type/four comments/frame/two xrefs/SHA baseline unchanged | applied |
| C37J-041 | 00037K | Protect FindFirstEqual prestate | very strong | supervisor immediate prestate, full pre-save verification, and fresh-reopen persistence readback | IDA Gate 2B / P2 | already-present | name/type/comments/frame/14 xrefs/SHA baseline unchanged | applied |
| C37J-042 | 00037M | Protect scalar deleting wrapper current prototype `LObject *__thiscall(LObject *Block, char)` and exact physical frame | very strong | supervisor immediate prestate, full pre-save verification, and fresh-reopen persistence readback | IDA Gate 2B / P3 | already-present | `LObject *__thiscall(LObject *Block, char)`, all four comments, complete frame, vtable ref, and SHA baseline remain unchanged | applied |
| C37J-043 | 00037N | Protect GetElementAt sibling prestate | very strong | supervisor immediate prestate, full pre-save verification, and fresh-reopen persistence readback | IDA Gate 2B / P4 | already-present | identity/type/comments/frame/vtable ref/SHA baseline unchanged | applied |
| C37J-044 | 00037O | Protect RemoveAll sibling prestate | very strong | supervisor immediate prestate, full pre-save verification, and fresh-reopen persistence readback | IDA Gate 2B / P5 | already-present | identity/type/comments/frame/vtable ref/SHA baseline unchanged | applied |
| C37J-045 | 00037P | Protect RemoveAt sibling prestate | very strong | supervisor immediate prestate, full pre-save verification, and fresh-reopen persistence readback | IDA Gate 2B / P6 | already-present | identity/type/comments/frame/vtable ref/SHA baseline unchanged | applied |
| C37J-046 | 0001BC | Protect GetMemoryMan prestate | very strong | supervisor pre-save and fresh-reopen verification of 612 literal xrefs/inventory, comments, frame, and bytes | IDA Gate 2B / P7 | already-present | identity/type/comments/frame/612-xref inventory/xref hash/byte hash unchanged | applied |
| C37J-047 | 0001BD | Protect AllocateBufferMemory prestate | very strong | supervisor pre-save and fresh-reopen verification of 132 literal xrefs/inventory, comments, frame/EH, and bytes | IDA Gate 2B / P8 | already-present | identity/type/comments/frame/EH/132-xref inventory/xref hash/byte hash unchanged | applied |
| C37J-048 | 0001BH | Protect MemmoveWrapper prestate | very strong | supervisor pre-save and fresh-reopen verification of exact identity/type/frame/comments/604 xrefs/bytes | IDA Gate 2B / P9 | already-present | identity/type/comments/frame/xrefs/byte hash unchanged | applied |
| C37J-049 | 0001BI | Protect MoveBufferMemory prestate | very strong | supervisor pre-save and fresh-reopen verification of exact identity/type/frame/comments/19 xrefs/bytes | IDA Gate 2B / P10 | already-present | identity/type/comments/frame/19 xrefs/byte hash unchanged | applied |
| C37J-050 | 0003OL | Protect decorated vtable data prestate | very strong | supervisor pre-save and fresh-reopen verification of exact items/types/comments/xref/slots/bytes | IDA Gate 2B / P11 | already-present | name, absent type, comments, slots, locator, xref, byte hash unchanged | applied |
| C37J-051 | 000193 | Literal M01 aggregate coverage replacement | strong | supervisor verbatim application plus command-20960 validation/readback | by-memory/-coverage-report.md / UID000193 row | incorporate | exact M01 line appears once at line 2085 | applied |
| C37J-052 | 00037J | Literal M02 target coverage insertion | strong | supervisor verbatim application plus command-20960 validation/readback | by-memory/-coverage-report.md / immediately after UID000193 | incorporate | exact M02 line appears once at line 2086 immediately after M01 | applied |
| C37J-053 | 0003OL | Literal M03 vtable coverage insertion | strong | supervisor verbatim application plus command-20960 validation/readback | by-memory/-coverage-report.md / UID00025N after UID0003OK before UID00025O | incorporate | exact M03 appears once at line 4347 between UID0003OK/UID00025O | applied |
| C37J-054 | 0000DF | Literal M04 class coverage replacement | strong | supervisor verbatim application plus command-20961 validation/readback | by-class/-coverage-report.md / UID0000DF row | incorporate | exact M04 line appears once at line 506 | applied |
| C37J-055 | 0000NU | Literal M05 file coverage replacement | strong | supervisor verbatim application plus command-20962 validation/readback | by-file/-coverage-report.md / UID0000NU row | incorporate | exact M05 line appears once at line 257 | applied |
| C37J-056 | 00037J | Scoped target callback validation | very strong | validator requirement | by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md | not-applicable | exact scoped command exits 0 with recorded command ID/hash/warnings | applied |
| C37J-057 | 0000DF | Scoped class callback validation | very strong | validator requirement | by-class/SortedList.md | not-applicable | exact scoped command exits 0 with recorded command ID/hash/warnings | applied |
| C37J-058 | 0000NU | Scoped file callback validation | very strong | validator requirement | by-file/SortedList.md | not-applicable | exact scoped command exits 0 with recorded command ID/hash/warnings | applied |
| C37J-059 | 000193 | Scoped mixed-index callback validation | very strong | validator requirement | by-memory/0x004f3600-0x004f3a43.SortedList.md | not-applicable | exact scoped command exits 0 with recorded command ID/hash/warnings | applied |
| C37J-060 | 0003OL | Scoped vtable-page callback validation | very strong | validator requirement | by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md | not-applicable | exact scoped command exits 0 with recorded command ID/hash/warnings | applied |
| C37J-061 | 000193 | Validate M01 in manual by-memory coverage | very strong | supervisor command 000000020960 exited 0/ok 1/generated skipped | by-memory/-coverage-report.md / UID000193 | not-applicable | exact M01 reads back once in current hash 173A511B... | applied |
| C37J-062 | 00037J | Validate M02 in manual by-memory coverage | very strong | supervisor command 000000020960 exited 0/ok 1/generated skipped | by-memory/-coverage-report.md / UID00037J | not-applicable | exact M02 reads back once in current hash 173A511B... | applied |
| C37J-063 | 0003OL | Validate M03 in manual by-memory coverage | very strong | supervisor command 000000020960 exited 0/ok 1/generated skipped | by-memory/-coverage-report.md / UID0003OL | not-applicable | exact M03 reads back once in current hash 173A511B... | applied |
| C37J-064 | 0000DF | Validate M04 in manual class coverage | very strong | supervisor command 000000020961 exited 0/ok 1/generated skipped | by-class/-coverage-report.md / UID0000DF | not-applicable | exact M04 reads back once in current hash 3912BCDD... | applied |
| C37J-065 | 0000NU | Validate M05 in manual file coverage | very strong | supervisor command 000000020962 exited 0/ok 1/generated deferred | by-file/-coverage-report.md / UID0000NU | not-applicable | exact M05 reads back once in current hash 871595E2... | applied |
| C37J-066 | 0000DF | Evidence-time generated class CPP shell | very strong | supervisor command-20963 generation and direct readback | auto-generated/NexusTK/util/SortedList.cpp / UID0000DF contribution | not-applicable | exact two-include shell appears and UID0000DF empty marker is absent | applied |
| C37J-067 | 00037J | Evidence-time generated target CPP body | very strong | supervisor command-20963 generation and direct readback | auto-generated/NexusTK/util/SortedList.cpp / UID00037J contribution | not-applicable | exact target body appears once and UID00037J empty marker is absent | applied |
| C37J-068 | 0000DF | Evidence-time generated class H declaration | very strong | supervisor command-20963 generation and direct readback | auto-generated/NexusTK/util/SortedList.h / UID0000DF contribution | not-applicable | header exists with exact class-H payload and one children expansion | applied |
| C37J-069 | 00037J | Evidence-time generated target H no-contribution disposition | very strong | supervisor command-20963 generation and direct readback | auto-generated/NexusTK/util/SortedList.h / UID00037J contribution | not-applicable | no duplicate method declaration is emitted from UID00037J | applied |
| C37J-070 | 00037J | Evidence-time generated target owner/emitter/CPP/H/output route | very strong | command-20963 memory coverage direct row readback | auto-generated/-ag-memory-coverage.md / UID00037J row | not-applicable | bounded row reads 0000DF route, CPP yes, H no, SortedList.cpp output | applied |
| C37J-071 | 000193 | Evidence-time generated mixed-index no-emitter route | very strong | command-20963 memory coverage direct row readback | auto-generated/-ag-memory-coverage.md / UID000193 row | not-applicable | bounded row preserves NONE/false/no CPP/H output | applied |
| C37J-072 | 0003OL | Evidence-time generated vtable-data route | very strong | command-20963 memory coverage direct row readback | auto-generated/-ag-memory-coverage.md / UID0003OL row | not-applicable | bounded row preserves 0000KS route and generated List.cpp data output | applied |
| C37J-073 | 00037J | Evidence-time research-tracker target score/queue snapshot | very strong | command-20963 tracker direct row readback | auto-generated/-ag-research-tracker.md / UID00037J evidence-time row excluding lifecycle authority | not-applicable | bounded row reads 96/96 true and zero report counts at that evidence time; no current registration state is asserted | applied |
| C37J-074 | 0000DF | Evidence-time research-tracker class score snapshot | very strong | command-20963 tracker direct row readback | auto-generated/-ag-research-tracker.md / UID0000DF evidence-time row | not-applicable | bounded row reads 94/94 true and zero report counts at that evidence time; no current registration state is asserted | applied |
| C37J-075 | 0000NU | Evidence-time research-tracker file score snapshot | very strong | command-20963 tracker direct row readback | auto-generated/-ag-research-tracker.md / UID0000NU evidence-time row | not-applicable | bounded row reads 92/92 and zero report counts at that evidence time; no current registration state is asserted | applied |
| C37J-076 | 000193 | Evidence-time research-tracker mixed-index score/state snapshot | very strong | command-20963 tracker direct row readback | auto-generated/-ag-research-tracker.md / UID000193 evidence-time row | not-applicable | bounded row reads 91/93 false and zero report counts at that evidence time; no current registration state is asserted | applied |
| C37J-077 | 0003OL | Evidence-time research-tracker vtable score/state snapshot | very strong | command-20963 tracker direct row readback | auto-generated/-ag-research-tracker.md / UID0003OL evidence-time row | not-applicable | bounded row reads 90/94 true and zero report counts at that evidence time; no current registration state is asserted | applied |
| C37J-078 | 00037J | Lifecycle-neutral external-authority contract | very strong | artifact current path plus validator-owned status/history/registry | report artifact and validator lifecycle authority | not-applicable | before or after any movement, report execution/archive registration is determined only from external authority; this body encodes no static count, path, or transition state | applied |
| C37J-079 | 00037J | Reconcile every claim, destination identity, validator result, failed Gate 2B/rollback fact, repaired semantic-versus-physical transaction, and checklist state in this same report | very strong | lifecycle-neutral report standard plus exact supervisor failure/rollback evidence | tools/leaser/Agents/Agent-B005/research/00037J-SortedListInsertSorted-empty-emitter-source-quality.md | incorporate | same report records callback and repair evidence without stale lifecycle claims or failed-attempt credit | applied |

## Positive Evidence Summary

- Exact modeled function: 235 bytes, standard prologue, final int return and retn 4.
- Exactly 13 direct code xrefs: one ChangeMan plus twelve Message insertion helpers.
- Comparator is called new-first/current-second and equality advances, proving after-equals insertion.
- Every Message insertion call is followed by the normalizer, proving EAX is the inserted index.
- Constructor writes comparator at +0x14, class vtable at 0x0061ce58, and exact base fields.
- Target uses accepted MemoryMan helper vocabulary/style from current List source.
- Current source structure already routes the class/target into standalone SortedList.cpp.
- Historical command `000000020822` exposed only class/target empty markers and no `SortedList.h`; evidence-time supervisor-verified command `000000020963` confirms that the accepted formal class CPP/H plus target CPP repaired both source channels, with nonempty `SortedList.cpp`/`.h` and no former class/target Empty Emitter Marker. Commands 20957/20946/20906/20892 are earlier historical confirmations of the same substantive result.

## IDA MCP Facts

- Target transaction prestate: `sub_4F3690`, 0x004f3690-0x004f377b, size 0xeb, type `int __thiscall(int this, void *Src)`, 96 instructions, 15 blocks, complexity 8. Current saved poststate is `SortedList_InsertSorted` with semantic type `int __thiscall SortedList_InsertSorted(SortedList *this, const void *element)` and physical `element`/`const void *` at `+0x1c`.
- Target frame prestate: `var_8` at `+0x0c`, width 4, `struct MemoryMan *`; `var_4` at `+0x10`, width 4, `_DWORD`; `__saved_registers` at `+0x14`, width 4, IDA special/no user type; `__return_address` at `+0x18`, width 4, IDA special/no user type; `Src` at `+0x1c`, width 4, `void *`. Implicit width-4 ECX binding is `this`/`int` and has no physical frame row.
- Target comment prestate: address regular absent; address repeatable absent; function regular absent; function repeatable absent. Current saved poststate adds only the exact function-repeatable comment; the other three channels remain absent.
- Existing internal regular comments to preserve: 4f3702 this; 4f370e size; 4f3722 Block; 4f3742 size; 4f3745 source; 4f374c this; 4f3751 destination; 4f375d size; 4f375e source; 4f3767 destination; 4f3768 this.
- Boundaries: fifteen CC bytes at 4f3681-4f3690; epilogue ends 5f 5e 8b c3 5b 8b e5 5d c2 04 00; five CC bytes at 4f377b-4f3780.
- Vtable bytes at 61ce54 decode to locator 649d78; slots 4f38b0, 4f4b10, 41b6c0, 4f32a0, 4f3950, 4f32e0, 4f33c0, 4f3990, 4f3980, 4f34b0; successor locator 649dc8.
- Vtable base 61ce58 has one xref at constructor store 4f3669.
- Transaction prestate had no SortedList UDT or SortedListCompareFunction; List and MemoryMan were opaque non-UDT types. Current saved poststate contains the exact pointer typedef and six-member 0x18 SortedList UDT while List and MemoryMan remain opaque.
- Desired function names were collision-free before mutation; current saved poststate applies `SortedList_InsertSorted` and `MemoryMan_ReallocateBufferMemory` while preserving compiler-owned RTTI/vtable artifacts.
- Reallocator transaction prestate: `sub_516190`, 516190-516210, size 0x80, type `void *__stdcall(void *Block, _DWORD *pExceptionObject)`, all four entry/function comments absent, ten xrefs, realloc-or-throw behavior. The decompiler casts the second parameter to `size_t` for `realloc`, then overwrites that same storage with the `Win32Error *` exception object before `_CxxThrowException`, explaining the prestate function-level pointer rendering. Exact physical frame prestate was `var_C` at `+0x04`, width 4, `_DWORD`; `var_4` at `+0x0c`, width 4, `_DWORD`; `__saved_registers` at `+0x10`, width 4, IDA special/no user type; `__return_address` at `+0x14`, width 4, IDA special/no user type; `Block` at `+0x18`, width 4, `void *`; `pExceptionObject` at `+0x1c`, width 4, `int`, with no implicit ECX parameter. Current saved poststate is `MemoryMan_ReallocateBufferMemory`, semantic `void *__thiscall(MemoryMan *this, void *block, size_t newSize)`, physical `block`/`void *` and `newSize`/`size_t`, and only the exact function-repeatable comment added.
- Evidence-time baseline plus clean rollback proof: P7 GetMemoryMan has exactly 612 literal code xrefs, P8 AllocateBufferMemory exactly 132, P9 MemmoveWrapper exactly 604, and P10 MoveBufferMemory exactly 19; full pagination reproduced the normalized-list hashes recorded under Evidence Checked. `inspect_items` reported every P11 slot as a separate four-byte data item with blank type, and `get_bytes` reproduced every exact SHA256 baseline for F1/F2 and P1-P11. Clean session `b005-rollback-clean` restored T1 absence and the original F1/F2 names/prototypes/frames/comments after the failed no-save transaction. Pre-transaction session `b002-persist-reopen` repeated those exact prestates before the successful transaction; saved current-authority session `b005-persist-reopen` now proves the exact accepted T1/F1/F2 poststates and unchanged P1-P11 protections against canonical SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0`.
- Historical physical-binding fact: F1 semantic `set_type` returned success and `func_profile` read the exact desired semantic prototype, while immediate `stack_frame` retained `Src`/`void *` at `+0x1c`. Function-prototype success is therefore not physical-row success. No F1 comment, F2 action, manual/generated edit, validation, or save occurred after this mismatch.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| 0x004f3600-0x004f3681 | 00037I / by-memory/0x004f3600-0x004f3681.SortedListConstructor.md | SortedList constructor sibling | true | 0000DF | 88/91 | protect; no target change |
| 0x004f3681-0x004f3690 | by-memory/-ignored.md | compiler alignment | not applicable | none | not scored | exact; no change |
| 0x004f3690-0x004f377b | 00037J / by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md | assigned InsertSorted method | true | 0000DF | 91/94 -> 96/96 | populate CPP and complete evidence |
| 0x004f377b-0x004f3780 | by-memory/-ignored.md | compiler alignment | not applicable | none | not scored | exact; no change |
| 0x004f3780-0x004f3803 | 00037K / by-memory/0x004f3780-0x004f3803.SortedListFindFirstEqual.md | FindFirstEqual sibling | true | 0000DF | 87/91 | protect; no target change |
| 0x004f3810-0x004f38a7 | 00037L / by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md | neighboring List scalar wrapper | true | 000079 | 87/92 | exclude from SortedList source |
| 0x004f38b0-0x004f3947 | 00037M / by-memory/0x004f38b0-0x004f3947.SortedListScalarDeletingDestructor.md | SortedList scalar wrapper | true | 0000DF | 86/90 | compiler wrapper; protect |
| 0x004f3950-0x004f397a | 00037N / by-memory/0x004f3950-0x004f397a.SortedListGetElementAt.md | GetElementAt sibling | true | 0000DF | 86/91 | protect; no target change |
| 0x004f3980-0x004f398b | 00037O / by-memory/0x004f3980-0x004f398b.SortedListClear.md | source-facing RemoveAll sibling | true | 0000DF | 85/90 | protect; class vocabulary only |
| 0x004f3990-0x004f3a43 | 00037P / by-memory/0x004f3990-0x004f3a43.SortedListRemoveRange.md | source-facing RemoveAt sibling | true | 0000DF | 88/91 | protect; class vocabulary only |
| 0x004f3600-0x004f3a43 | 000193 / by-memory/0x004f3600-0x004f3a43.SortedList.md | mixed address-island index | false | none | 90/92 -> 91/93 | remain non-emitting; repair stale prose |
| 0x0061ce28-0x0061ce84 | 0003OL / by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md | List/SortedList generated vtable data | true | 0000KS | 88/92 -> 90/94 | correct locator/slots; keep generated marker |
| 0x00516190-0x00516210 | 0001BG / by-memory/0x00516190-0x00516210.ReallocateOrThrow.md | MemoryMan reallocator dependency | true | 00007U | 90/90 | source exact; IDA F2 applied and persisted |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| 0x0047ed75 | ChangeMan_Register -> InsertSorted | Inserts one 0x10-byte ChangeManEntry and intentionally ignores EAX. |
| 0x00520f4c -> 0x00520f54 | raw Message tag-0 helper -> InsertSorted -> sub_521C80 | EAX is the inserted index passed to duplicate-sequence normalization. |
| 0x00520fbc -> 0x00520fc4 | raw Message tag-1 helper -> InsertSorted -> sub_521C80 | Same index-consumer contract. |
| 0x0052102e -> 0x00521036 | raw Message tag-2 helper -> InsertSorted -> sub_521C80 | Same index-consumer contract. |
| 0x0052109e -> 0x005210a6 | raw Message tag-3 helper -> InsertSorted -> sub_521C80 | Same index-consumer contract. |
| 0x0052110c -> 0x00521114 | raw Message tag-4 helper -> InsertSorted -> sub_521C80 | Same index-consumer contract. |
| 0x0052117c -> 0x00521184 | raw Message tag-5 helper -> InsertSorted -> sub_521C80 | Same index-consumer contract. |
| 0x005211f2 -> 0x005211fa | raw Message tag-6 helper -> InsertSorted -> sub_521C80 | Same index-consumer contract. |
| 0x00521261 -> 0x00521269 | raw Message tag-7 helper -> InsertSorted -> sub_521C80 | Same index-consumer contract. |
| 0x005212cd -> 0x005212d5 | raw Message tag-8 helper -> InsertSorted -> sub_521C80 | Same index-consumer contract. |
| 0x0052133d -> 0x00521345 | raw Message tag-9 helper -> InsertSorted -> sub_521C80 | Same index-consumer contract. |
| 0x005213ff -> 0x00521407 | raw Message tag-10 wide-string helper -> InsertSorted -> sub_521C80 | Same index-consumer contract for the wide-string record. |
| 0x005214a2 -> 0x005214aa | raw Message tag-11 blob helper -> InsertSorted -> sub_521C80 | Same index-consumer contract for the blob record. |

Target callees: GetMemoryMan; AllocateBufferMemory; ReallocateBufferMemory; MoveBufferMemory; MemmoveWrapper.

## Documentation Evidence And IDA Status

- Supporting docs already establish base fields/typedef/style, reallocator source, Message helper spans/record/normalizer/comparator, ChangeMan ignored return, and utility source placement.
- Historical repair scope was target formal source/callers/order/invariants; class declaration/names/file decision; mixed-index stale gate; vtable locator/slots; and manual rows. The ordinary by-* portion is applied; the five exact manual payloads remain supervisor-owned and are still absent from the current manual coverage files.
- IDA Gate 2B disposition is complete for target/reallocator source names, semantic types, explicit physical stack rows, exact repeatable comments, the flat SortedList analysis type, and all P1-P11 protections. The historical failed/no-save F1 transaction remains the proof that semantic typing alone was insufficient; the successful supervisor retry used the explicit stack-member requests, passed all pre-save checks, saved once, and passed fresh-session persistence readback at canonical SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0`.
- Historical command `000000020822` had UID0000DF/UID00037J empty markers and no generated `SortedList.h`. Evidence-time supervisor command `000000020963` emitted the exact accepted nonempty `SortedList.cpp` and `SortedList.h`; its bounded memory/class/file coverage rows show coded output through the accepted owner/file routes, the stale class/target markers are absent, and its bounded research-tracker rows preserve the accepted scores and evidence-time zero report counts. Commands 20957/20946/20906/20892 recorded the same substantive state at earlier historical times. B005 independently re-read but did not create or refresh these artifacts; dynamic report registration remains external validator authority.

## Ranked Ownership Analysis

### 1. Existing SortedList class UID0000DF

- For: constructor/vtable/comparator/layout, class-local sibling island, existing owner/emitter, unrelated method consumers.
- Against: no original symbol spelling.
- Decision: retain owner/emitter. Infer human spelling rather than defer.

### 2. Existing SortedList file UID0000NU

- For: dedicated by-file root, proposed-tree entry, generator route, separate RTTI/vtable, class-local cluster.
- Against: proximity to List permits historical folding.
- Decision: use standalone SortedList.cpp/.h now; List.cpp fold is historical only.

### 3. List, ChangeMan, Message, MemoryMan

- For: base, consumers, dependencies.
- Against: none owns this method body.
- Decision: reject as direct owners.

### Proposed new file/grouping, if applicable

- No new by-file page. Existing UID0000NU is sufficient.
- Contents: class CPP/H shell plus exact method children.
- Exclude UID00037L List scalar wrapper.
- Narrow standalone utility file is the current reconstruction.

## Source Placement

- Place in NexusTK/util/SortedList.cpp with SortedList.h.
- This is cross-subsystem utility code, not a UI list pane.
- Independent project-level evidence selects standalone placement even though original physical filename is unprovable.
- Reject List.cpp for current reconstruction, ChangeMan/Message consumer ownership, and MemoryMan dependency ownership.
- Original disk filename uncertainty remains historical, not actionable.

## Range / Split / Padding / Reclassification Analysis

- Exact target remains 4f3690-4f377b.
- Pre-padding 4f3681-4f3690 and post-padding 4f377b-4f3780 are compiler alignment.
- No literal pool, table, second body, EH island, or List-owned bytes occur inside target.
- No split/merge/new child/reclassification.
- UID000193 remains mixed false/no-owner/no-emitter and receives prose only.

## Negative Evidence Summary

- No symbol proves spelling/access, but role/API evidence supports a best human reconstruction.
- No data/table/pointer xrefs; all 13 are code calls.
- No caller treats return as bool/pointer; twelve consume index, one ignores it.
- No comparator current-first/new-second call and no equality break.
- No null comparator/element, zero page-size, overflow, or allocation-return guard; do not add modern behavior.
- No source bytes in padding, aggregate emitter, handwritten vtable need, or duplicate body.
- No evidence supports assuming that semantic function `set_type` propagates argument names/types into occupied physical frame rows. The failed no-save Gate 2B attempt disproved that assumption at F1: semantic `element`/`const void *` read back in `func_profile` while physical `Src`/`void *` remained unchanged. The repaired contract explicitly edits and verifies each occupied row instead of treating this mismatch as cosmetic.

## IDA Rename / Type / Comment Recommendations

The exact request objects, session/process bindings, backup/save/reopen sequence, and rollback program formerly in this section are preserved only in [00037J-SortedListInsertSorted-empty-emitter-source-quality-removed.md](00037J-SortedListInsertSorted-empty-emitter-source-quality-removed.md). That companion is non-authoritative and must never be executed.

The following are declarative recommendations and historical accepted outcomes. The failed first attempt received no action credit and left its prestate unchanged. The successful supervisor result persisted the accepted T1/F1/F2 state and all P1-P11 protections in canonical SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0`, size `143,196,412`.

| ID | Exact entity/range/width | Exact transaction prestate | Evidence, xrefs, collision result | Exact action/classification | Accepted readback/protection |
| --- | --- | --- | --- | --- | --- |
| T1 | local type database; desired SortedList size 0x18 | SortedList: absent. SortedListCompareFunction: absent. List: present only as opaque non-UDT with no size/members. MemoryMan: present only as opaque non-UDT with no size/members. | Constructor and target prove +00 vtable, +04 element size, +08 page size, +0c count, +10 data, +14 comparator. No SortedList or typedef collision. Historical Gate 2B proved the declaration succeeds when `decls` is a one-element array; scalar text was rejected by comma splitting without mutation. | Proposed human outcome: declare the exact `SortedListCompareFunction` and six-member `SortedList` types while preserving opaque `List` and `MemoryMan`. | `type_inspect` reports SortedListCompareFunction exists with exact cdecl pointer declaration and SortedList exists as a UDT of size 0x18 with six exact members/offsets/types; List and MemoryMan remain unchanged opaque types. |
| F1 | function 0x004f3690-0x004f377b; width 0xeb | Name sub_4F3690. Type int __thiscall(int this, void *Src). Address regular comment absent; address repeatable comment absent; function regular comment absent; function repeatable comment absent. Frame rows: var_8 +0x0c width 4 struct MemoryMan *; var_4 +0x10 width 4 _DWORD; __saved_registers +0x14 width 4 special/no user type; __return_address +0x18 width 4 special/no user type; Src +0x1c width 4 void *. Implicit ECX binding: this, width 4, int; no physical frame row. | Thirteen code xrefs: 47ed75, 520f4c, 520fbc, 52102e, 52109e, 52110c, 52117c, 5211f2, 521261, 5212cd, 52133d, 5213ff, 5214a2. Name SortedList_InsertSorted is collision-free. Exact body has 96 instructions. Historical no-save transaction proves semantic `set_type` succeeds without changing physical `Src`/`void *`. | Proposed human outcome: name `SortedList_InsertSorted`; assign exact semantic type `int __thiscall SortedList_InsertSorted(SortedList *this, const void *element)`; change only physical argument row `Src`/`void *` to `element`/`const void *`; set the accepted function-repeatable comment. | Exact name/type/function-repeatable comment; address regular/repeatable and function regular remain absent. Semantic readback must succeed while the physical row remains prestate until explicitly edited. Final +0x1c changes exactly to `element`/`const void *`; ECX binds as `SortedList *this`; every protected row, range, 96 instructions, 13 xrefs, bytes, and internal comments remain unchanged. |
| F2 | function 0x00516190-0x00516210; width 0x80 | Transaction-prestate name sub_516190 and type `void *__stdcall(void *Block, _DWORD *pExceptionObject)`. Address regular/repeatable and function regular/repeatable comments absent. Frame rows: var_C +0x04 width 4 _DWORD; var_4 +0x0c width 4 _DWORD; __saved_registers +0x10 width 4 special/no user type; __return_address +0x14 width 4 special/no user type; Block +0x18 width 4 void *; pExceptionObject +0x1c width 4 int. No implicit ECX parameter existed. The function-level `_DWORD *` and physical-frame `int` renderings were distinct prestate facts. | Ten code xrefs: 4b6247, 4bb2a6, 4f324d, 4f3285, 4f3354, 4f3476, 4f358a, 4f35ca, 4f3723, 4f3a26. Name MemoryMan_ReallocateBufferMemory was collision-free. The body casts the second argument to `size_t` for realloc and reuses the stack storage for the thrown pointer; accepted UID0001BG and MemoryMan H prove the source ABI. F1 proves semantic and physical bindings must be handled separately. | Accepted human outcome: name `MemoryMan_ReallocateBufferMemory`; assign exact semantic type `void *__thiscall MemoryMan_ReallocateBufferMemory(MemoryMan *this, void *block, size_t newSize)`; normalize only the two stated physical argument rows; set the accepted function-repeatable comment. | Exact name/type/function-repeatable comment persisted; address regular/repeatable and function regular remain absent. Semantic `__thiscall`/ECX readback and physical +0x18/+0x1c rows passed independently. Every protected row, range, EH/throw body, ten xrefs, comments, and bytes remain unchanged. |

### F1 Deterministic Prototype-To-Frame Binding Contract

Applying the F1 semantic prototype and editing its occupied physical argument are separate required operations. `this` is an implicit register argument and is not a physical stack-frame row; the only physical row allowed to change is the existing four-byte explicit argument at `+0x1c`. Historical Gate 2B proved that successful semantic function typing can leave that physical row unchanged, so `func_profile` and `stack_frame` are independent acceptance surfaces.

| Binding/row | Offset/register | Width | Exact prestate name/type | Exact poststate name/type | Disposition/readback |
| --- | --- | --- | --- | --- | --- |
| implicit receiver | `ECX` | 4 | `this` / `int`; implicit `__thiscall` binding, no frame row | `this` / `SortedList *`; implicit `__thiscall` binding, no frame row | Required type refinement; must not create or shift a stack row. |
| local | `+0x0c` | 4 | `var_8` / `struct MemoryMan *` | `var_8` / `struct MemoryMan *` | Protected unchanged. |
| local | `+0x10` | 4 | `var_4` / `_DWORD` | `var_4` / `_DWORD` | Protected unchanged. |
| saved-register row | `+0x14` | 4 | `__saved_registers` / IDA special frame row with no user type | `__saved_registers` / IDA special frame row with no user type | Protected unchanged. |
| return-address row | `+0x18` | 4 | `__return_address` / IDA special frame row with no user type | `__return_address` / IDA special frame row with no user type | Protected unchanged. |
| explicit argument 0 | `+0x1c` | 4 | `Src` / `void *` | `element` / `const void *` | The sole physical frame-row delta. |

For F1, the semantic prototype and occupied physical argument are independent acceptance surfaces. The only permitted physical-frame delta is `Src +0x1c/4/void *` to `element +0x1c/4/const void *`; ECX remains implicit as `SortedList *this`. Every other row, offset, width, range, xref, comment, and byte identity is protected.

### F2 Deterministic Calling-Convention And Frame Binding Contract

The F2 semantic change deliberately converts the function type from `__stdcall` to `__thiscall`. The receiver is added only as an implicit width-four ECX binding. It consumes no stack slot and therefore must not move the two existing four-byte physical arguments at `+0x18` and `+0x1c`. As with F1, semantic prototype application does not receive credit for occupied physical-row names/types; each F2 row has its own literal rename/type requests and immediate complete-frame readbacks.

| Binding/row | Offset/register | Width | Exact prestate name/type | Exact poststate name/type | Disposition/readback |
| --- | --- | --- | --- | --- | --- |
| implicit receiver | `ECX` | 4 | absent from current `void *__stdcall(void *Block, _DWORD *pExceptionObject)`; no implicit receiver and no frame row | `this` / `MemoryMan *`; implicit `__thiscall` binding, no frame row | Required ECX addition; must not create or shift a stack row. |
| local | `+0x04` | 4 | `var_C` / `_DWORD` | `var_C` / `_DWORD` | Protected unchanged. |
| local | `+0x0c` | 4 | `var_4` / `_DWORD` | `var_4` / `_DWORD` | Protected unchanged. |
| saved-register row | `+0x10` | 4 | `__saved_registers` / IDA special frame row with no user type | `__saved_registers` / IDA special frame row with no user type | Protected unchanged. |
| return-address row | `+0x14` | 4 | `__return_address` / IDA special frame row with no user type | `__return_address` / IDA special frame row with no user type | Protected unchanged. |
| explicit argument 0 | `+0x18` | 4 | `Block` / `void *` | `block` / `void *` | Required spelling normalization; offset, width, and pointer type unchanged. |
| explicit argument 1 | `+0x1c` | 4 | function prototype parameter `_DWORD *pExceptionObject`; physical frame row `pExceptionObject` / `int` | `newSize` / `size_t` in both function prototype and physical argument row | Required name/type correction at the same physical row; do not preserve the exception-reuse inference in the source-facing prototype. |

For F2, the semantic `__stdcall` to `__thiscall` correction adds only an implicit `MemoryMan *this` ECX receiver. Physical `Block +0x18/4/void *` becomes `block +0x18/4/void *`, and `pExceptionObject +0x1c/4/int` becomes `newSize +0x1c/4/size_t`. No row moves, appears, or disappears.

Protected dependencies:

| ID | Exact entity and current identity/type | Exact comments/frame/xrefs | Protection and expected readback |
| --- | --- | --- | --- |
| P1 | 0x004f3600-0x004f3681, width 0x81; sub_4F3600; _DWORD *__thiscall(_DWORD *this, int, int, int) | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. Frame: var_10 +08 LObject *, var_C +0c _DWORD, var_4 +14 _DWORD, saved +18, return +1c, arg_0/+4/+8 at +20/+24/+28. Xrefs: 47eced and 520e94. | No action. Preserve exact constructor body/name/type/comments/frame/two xrefs/bytes; this target does not source-audit the sibling constructor. |
| P2 | 0x004f3780-0x004f3803, width 0x83; sub_4F3780; int __thiscall(int this, void *Key) | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. Frame: var_4 +04, saved +08, return +0c, Key +10 void *. Fourteen code xrefs: 47ed98, 47ee37, 521519, 5215b9, 521659, 5216f9, 521799, 521829, 5218b9, 521969, 521a09, 521aa9, 521b4d, 521c0d. | No action. Preserve exact FindFirstEqual sibling body/name/type/comments/frame/xrefs/bytes. |
| P3 | 0x004f38b0-0x004f3947, width 0x97; sub_4F38B0; current prototype `LObject *__thiscall(LObject *Block, char)` with implicit width-4 ECX `Block`/`LObject *` and return type `LObject *` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. Complete physical frame: `var_C` +08 width 4 `_DWORD`; `var_4` +10 width 4 `_DWORD`; `__saved_registers` +14 width 4 `_DWORD`; `__return_address` +18 width 4 `_UNKNOWN *`; `arg_0` +1c width 4 `_DWORD`. One data xref at vtable slot 61ce58. | No action. Preserve the exact current `LObject *__thiscall(LObject *Block, char)` compiler-wrapper prototype, implicit ECX/return types, all four comment states, complete physical frame, vtable ref, and bytes; do not rename/retype it as a source destructor. |
| P4 | 0x004f3950-0x004f397a, width 0x2a; sub_4F3950; int __thiscall(_DWORD *this, int) | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. Frame: saved +00, return +04, arg_0 +08. One data xref at vtable slot 61ce68. | No action. Preserve sibling GetElementAt identity/type/comments/frame/vtable ref/bytes. |
| P5 | 0x004f3980-0x004f398b, width 0x0b; sub_4F3980; int __thiscall(_DWORD *this) | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. Frame contains return at +00 only. One data xref at vtable slot 61ce78. | No action. Preserve sibling RemoveAll wrapper identity/type/comments/frame/vtable ref/bytes. |
| P6 | 0x004f3990-0x004f3a43, width 0xb3; sub_4F3990; int __thiscall(_DWORD *this, int, int) | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. Frame: var_4 +0c, saved +10, return +14, arg_0 +18, arg_4 +1c. One data xref at vtable slot 61ce74. | No action. Preserve sibling RemoveAt identity/type/comments/frame/vtable ref/bytes. |
| P7 | 0x00516030-0x00516036, width 0x06; GetMemoryMan; MemoryMan *__cdecl GetMemoryMan() | Address regular absent; address repeatable absent; function regular is exactly Returns the process MemoryMan singleton used as receiver for overlap-safe MoveBufferMemory operations.; function repeatable absent. Frame contains return at +00 only. Exactly 612 code xrefs, literal inventory below; normalized lowercase comma-separated inventory SHA256 0C756CF243C102471CFC4A7D25BAB6D6AC3A8FB156D26BE381074104D0BC9178. Target calls are 4f36be and 4f36fa. | No action. Preserve accepted name/type/literal comment/frame, all 612 literal xrefs, xref-inventory hash, and byte hash. |
| P8 | 0x00516050-0x005160ce, width 0x7e; MemoryMan_AllocateBufferMemory; void *__thiscall MemoryMan_AllocateBufferMemory(MemoryMan *this, size_t size) | Address regular absent; address repeatable absent; function regular is exactly MemoryMan::AllocateBufferMemory(size_t). Callers pass the singleton in ECX even though this body does not dereference it; returns malloc storage or throws a Win32Error pointer on failure.; function repeatable absent. Current frame includes Block +04, var_C +08, var_4 +10, saved +14, return +18, pExceptionObject +1c, arg_4 +20. Exactly 132 code xrefs, literal inventory below; normalized lowercase comma-separated inventory SHA256 98C59AE04B8C12B813484245F0D9542D77B105B74C027B3C73FDE2974BAE79AD. Target call is 4f3713. | No action. Preserve accepted name/type/literal comment/frame/EH, all 132 literal xrefs, xref-inventory hash, and byte hash. |
| P9 | 0x00516220-0x00516238, width 0x18; MemoryMan_MemmoveWrapper; void *__thiscall MemoryMan_MemmoveWrapper(MemoryMan *this, void *destination, const void *source, size_t size) | Address regular absent; address repeatable absent; function regular is exactly MemoryMan::MemmoveWrapper(destination, source, size). Callers preserve/reload the MemoryMan singleton in ECX; thin overlap-safe memmove wrapper.; function repeatable absent. Frame: saved +00, return +04, destination +08 void *, Src +0c void *, Size +10 size_t. Target call at 4f376b; current accepted raw-PE fanout is 604. | No action. Preserve accepted name/type/literal comment/frame/xrefs/bytes. |
| P10 | 0x00516240-0x00516258, width 0x18; MemoryMan_MoveBufferMemory; void *__thiscall MemoryMan_MoveBufferMemory(MemoryMan *this, void *destination, const void *source, size_t size) | Address regular absent; address repeatable absent; function regular is exactly MemoryMan overlap-safe buffer move wrapper over memmove; receiver is semantically the MemoryMan singleton even though this compact body does not consume it.; function repeatable absent. Frame: saved +00, return +04, destination +08 void *, Src +0c void *, Size +10 size_t. Target call at 4f3752; exact shared fanout is 19. | No action. Preserve accepted name/type/literal comment/frame/19 xrefs/bytes. |
| P11 | data 0x0061ce58-0x0061ce80, width 0x28; ten separate 4-byte data items at 61ce58/5c/60/64/68/6c/70/74/78/7c. Base item name ??_7SortedList@@6B@; other nine names blank. Current IDA data type is blank/absent on every item; no aggregate/array type exists. | Base address regular absent; base address repeatable absent; function regular/repeatable and frame not applicable because this is data. One constructor data xref at 4f3669. Slots: 4f38b0, 4f4b10, 41b6c0, 4f32a0, 4f3950, 4f32e0, 4f33c0, 4f3990, 4f3980, 4f34b0. | No action. Preserve ten item boundaries, decorated compiler-owned base name, blank types, comments, slots, locator adjacency, constructor xref, and byte hash; do not hand-author, aggregate-type, or rename vtable data. |

Exact byte baselines for every actionable/protected range whose readback promises unchanged bytes:

| ID | Exact range / width | Current byte SHA256 |
| --- | --- | --- |
| P1 | 0x004f3600-0x004f3681 / 0x81 | A35E9F0414CBED494F42819F07CF2D6D07EA8F45A7AEDB1C3C6885EEAF4A4349 |
| F1 | 0x004f3690-0x004f377b / 0xeb | 9C1F40D2F7BEA980924AD322AF568A22F62745CC87FE8CAA2172417AC276C0D9 |
| P2 | 0x004f3780-0x004f3803 / 0x83 | E46770A613E7F18214435B72580E4ABBE3BB21FC1CD9148CD77D6CB45EDF17D0 |
| P3 | 0x004f38b0-0x004f3947 / 0x97 | 0D6E86603C70D31052C0C716FC1A267101C77E6E963C99B5AAEEB1B7905520A7 |
| P4 | 0x004f3950-0x004f397a / 0x2a | 44810F2561A7EC891F1EE7237B5694789F30138BE66DAD596820D69414CF1B3B |
| P5 | 0x004f3980-0x004f398b / 0x0b | E71C4E6B9D7DE83452E0937778DD6674E77D35C225FD844382D0FBCFA91175C3 |
| P6 | 0x004f3990-0x004f3a43 / 0xb3 | 08893E39F93942DAE16DE87A735169487F540F8BB9D4E3B075DF0E9EC03C0290 |
| P7 | 0x00516030-0x00516036 / 0x06 | 208756678E715EF53B49586D4530A514ABAEE90813DD347C836943EC07222327 |
| P8 | 0x00516050-0x005160ce / 0x7e | 99006135CEAC5923120ECDE403D0DB926D805D6FEB9E98C8D2FCC158DC069B3B |
| F2 | 0x00516190-0x00516210 / 0x80 | 8B0432A1F5E34F241F38C092C18B986700EFAF09BAD0E7C5B95F903C95A4B2CA |
| P9 | 0x00516220-0x00516238 / 0x18 | B5A8648EB3914D883E7D3D92AE3CFE0A391689D691346400F3791A8AE638F33A |
| P10 | 0x00516240-0x00516258 / 0x18 | 30888A5036BC2B61C7CE54B492A49B1D05491DDE0066E217EDB66DFE0A96E2C3 |
| P11 | 0x0061ce58-0x0061ce80 / 0x28 | F637D86D908BB138D6831C6161FF6057C8695945C979A17A6A81BF2E5AD6F990 |

P7 literal 612-xref baseline, sorted ascending:

- P7[001-048]: 0x457aca, 0x457c7a, 0x457e09, 0x457e18, 0x457f39, 0x45801d, 0x45802e, 0x45828d, 0x4583ef, 0x458451, 0x4584b5, 0x4584c8, 0x458504, 0x45c3f1, 0x45c6c9, 0x45c98d, 0x45cc93, 0x45d830, 0x45d8ac, 0x45d92b, 0x45d9ef, 0x465353, 0x465469, 0x466139, 0x46d5a5, 0x46eac1, 0x4720fb, 0x47248d, 0x472d2b, 0x473337, 0x474296, 0x474367, 0x474490, 0x4746e7, 0x474803, 0x475478, 0x475ba5, 0x47690d, 0x476a23, 0x47733d, 0x477483, 0x4775b2, 0x47781c, 0x477ce0, 0x47868a, 0x47898d, 0x478ad3, 0x478c02
- P7[049-096]: 0x47919b, 0x47973d, 0x47a405, 0x47a540, 0x47a793, 0x47b2b5, 0x47bb3f, 0x47ca3d, 0x47cb73, 0x47da6d, 0x47dba3, 0x47dcd2, 0x47f1a3, 0x47f2f3, 0x47f346, 0x47fda1, 0x47feac, 0x47ffb5, 0x4804aa, 0x4834ce, 0x483583, 0x483e9a, 0x4842d1, 0x484ff6, 0x4850c5, 0x48513e, 0x48518b, 0x4851ec, 0x48524d, 0x4852a5, 0x485358, 0x4853b9, 0x4855a9, 0x4859e8, 0x485ae4, 0x485cd8, 0x485e38, 0x485f98, 0x4860f8, 0x486258, 0x486354, 0x486728, 0x4877f3, 0x487a04, 0x487c71, 0x487d94, 0x487e43, 0x487edd
- P7[097-144]: 0x488194, 0x488244, 0x4882f4, 0x488394, 0x488484, 0x488533, 0x48869b, 0x488a20, 0x488bb8, 0x489198, 0x4892c8, 0x4893f8, 0x489528, 0x48967a, 0x48a234, 0x48a884, 0x48aef5, 0x48b253, 0x48b945, 0x48c71a, 0x48da0f, 0x48dd2a, 0x48e1e1, 0x48e896, 0x48f416, 0x48f4ec, 0x48f6f0, 0x48fcd4, 0x490526, 0x490826, 0x490b50, 0x4910e6, 0x491466, 0x4917a6, 0x4950d6, 0x4950fb, 0x49517a, 0x4951bb, 0x49575b, 0x499a1a, 0x49b341, 0x49b7f1, 0x49db78, 0x49dbcf, 0x49ff38, 0x4a315b, 0x4a352e, 0x4a3672
- P7[145-192]: 0x4a3e31, 0x4a407b, 0x4a50ce, 0x4a5173, 0x4a526c, 0x4a53a3, 0x4a5450, 0x4a54b1, 0x4a556b, 0x4a583a, 0x4a58fa, 0x4a59a2, 0x4a5b0f, 0x4a5c16, 0x4a5caf, 0x4a8ba4, 0x4a9b97, 0x4a9d47, 0x4aab07, 0x4aacb7, 0x4ab527, 0x4ab75d, 0x4ac90e, 0x4ad3cb, 0x4ad5af, 0x4ad68c, 0x4adb2f, 0x4add77, 0x4ade93, 0x4b052e, 0x4b5fb7, 0x4b6237, 0x4b63b2, 0x4b9aa0, 0x4bad99, 0x4bb148, 0x4bb268, 0x4bb29f, 0x4bc0bc, 0x4c0fb8, 0x4c61b2, 0x4c61c4, 0x4c628e, 0x4c629d, 0x4c646f, 0x4c6525, 0x4c6534, 0x4c7039
- P7[193-240]: 0x4c704f, 0x4c72da, 0x4c8b61, 0x4ccd11, 0x4ce478, 0x4ce5b1, 0x4ce88a, 0x4ce9da, 0x4d00a0, 0x4d0153, 0x4d03bf, 0x4d0ddd, 0x4d0f0f, 0x4d0f81, 0x4d15d5, 0x4d1665, 0x4d19d0, 0x4d1bab, 0x4d2a33, 0x4d4b03, 0x4d4b27, 0x4d4b4b, 0x4d4b6f, 0x4d4b93, 0x4d4bb7, 0x4d4bdb, 0x4d4bff, 0x4d4c23, 0x4d4c47, 0x4d4c6b, 0x4d4c8f, 0x4d4cb3, 0x4d4cd7, 0x4d4cfb, 0x4d4d1f, 0x4d4d43, 0x4d4d67, 0x4d4d90, 0x4d4dad, 0x4d4dca, 0x4db8db, 0x4dbc8e, 0x4dbf9c, 0x4dc39f, 0x4dc760, 0x4dcfbe, 0x4dd211, 0x4dd272
- P7[241-288]: 0x4dda8b, 0x4dde3a, 0x4de128, 0x4de44b, 0x4dfe8c, 0x4e02bb, 0x4e0e64, 0x4e1093, 0x4e1a01, 0x4e1f35, 0x4e63cf, 0x4e64d7, 0x4e66d7, 0x4e68e7, 0x4e69ca, 0x4e6a35, 0x4e90c1, 0x4e9283, 0x4f0081, 0x4f02bd, 0x4f0404, 0x4f04c0, 0x4f05e8, 0x4f1b8f, 0x4f309b, 0x4f3113, 0x4f3149, 0x4f3171, 0x4f321f, 0x4f3279, 0x4f32eb, 0x4f332b, 0x4f33ec, 0x4f346a, 0x4f34b8, 0x4f3566, 0x4f35bc, 0x4f363b, 0x4f36be, 0x4f36fa, 0x4f384a, 0x4f38ea, 0x4f399c, 0x4f3a1a, 0x4f4aa6, 0x4f4ae2, 0x4f4bcd, 0x4f7110
- P7[289-336]: 0x4f7204, 0x4f8d45, 0x4f8d8e, 0x4f8e62, 0x4fa3d1, 0x4fa5e9, 0x4fab43, 0x4fb2eb, 0x4fcb43, 0x4fe7ca, 0x4fea11, 0x4fec23, 0x4fee79, 0x4ff0c2, 0x4ff482, 0x50093a, 0x50331a, 0x503359, 0x5034c0, 0x503654, 0x503891, 0x5041fc, 0x504647, 0x5083bb, 0x5086ce, 0x50f63a, 0x50ff1d, 0x50ffed, 0x510188, 0x51050d, 0x5109b7, 0x510ea1, 0x511df3, 0x513685, 0x513ad4, 0x513cad, 0x517fd0, 0x518557, 0x51912b, 0x519261, 0x5193a8, 0x51961e, 0x519736, 0x519980, 0x519e23, 0x51a2e7, 0x51a43a, 0x51a5b0
- P7[337-384]: 0x51ad39, 0x51afff, 0x51b1ab, 0x51b917, 0x51be4a, 0x51cadd, 0x51d024, 0x51d5a9, 0x51d7ff, 0x51d91b, 0x51dbd7, 0x51e07d, 0x51ea30, 0x52137e, 0x52144b, 0x521b75, 0x521c35, 0x522a76, 0x522c00, 0x522cf8, 0x522df8, 0x522f0c, 0x522f77, 0x5231fc, 0x5235cc, 0x5238a8, 0x523b9d, 0x52483f, 0x524963, 0x524a15, 0x52bbf1, 0x52c010, 0x52c159, 0x52d5e1, 0x52d9e0, 0x52db29, 0x52ef81, 0x52f3d0, 0x52f519, 0x530f1f, 0x53128e, 0x533f8b, 0x5347f8, 0x54321a, 0x543b4d, 0x54567f, 0x54578f, 0x54589c
- P7[385-432]: 0x547b3c, 0x547c6c, 0x547d6c, 0x549c94, 0x54abb1, 0x54ce8f, 0x54d4b7, 0x54dc0f, 0x54e23a, 0x54e9a5, 0x54f117, 0x54fbb5, 0x55032a, 0x5515a6, 0x551b1d, 0x55218f, 0x55292b, 0x5531e0, 0x55336b, 0x5534e5, 0x553688, 0x553a1b, 0x553a93, 0x553ac6, 0x553b16, 0x553baa, 0x554e1e, 0x5557f8, 0x55611b, 0x55640e, 0x556513, 0x556587, 0x5565f7, 0x5567ea, 0x5582d9, 0x56585e, 0x5658cf, 0x56a667, 0x56cb4a, 0x56dddd, 0x56e240, 0x56e5ba, 0x5700ae, 0x570119, 0x5735d1, 0x5736c5, 0x5737b5, 0x57398a
- P7[433-480]: 0x573a61, 0x573ad6, 0x573b3b, 0x573b88, 0x573bca, 0x573c09, 0x573cb6, 0x574853, 0x574bbc, 0x574bd9, 0x574c4b, 0x574c6d, 0x574d0a, 0x574df2, 0x574e04, 0x57525a, 0x57527b, 0x5755f7, 0x57563e, 0x575b95, 0x575cb6, 0x575f93, 0x575fc4, 0x57669e, 0x576711, 0x57687d, 0x577036, 0x577170, 0x577378, 0x577b11, 0x577e23, 0x578265, 0x5783e8, 0x578863, 0x57a627, 0x57a63c, 0x57a64f, 0x57b445, 0x57b45a, 0x57b46d, 0x5851ac, 0x585531, 0x58597f, 0x585b35, 0x585bbc, 0x585ed5, 0x586512, 0x5865bd
- P7[481-528]: 0x58662f, 0x586a29, 0x586a95, 0x586c81, 0x586d0e, 0x586db8, 0x586e4d, 0x58703d, 0x5870cd, 0x587177, 0x587204, 0x58736b, 0x587544, 0x587880, 0x5879ae, 0x587a43, 0x588f32, 0x5890b2, 0x589148, 0x589445, 0x58971f, 0x5898d5, 0x58994f, 0x58a56b, 0x58a744, 0x58aa80, 0x58ab8a, 0x58e389, 0x58e4d3, 0x58e62f, 0x5901be, 0x5901c6, 0x590220, 0x5902b4, 0x5902c7, 0x590311, 0x590441, 0x590450, 0x5904b4, 0x59059a, 0x590ba1, 0x590ba9, 0x590bba, 0x5917f8, 0x591800, 0x591814, 0x59183f, 0x59184f
- P7[529-576]: 0x591a28, 0x591a30, 0x591ba1, 0x591bcc, 0x591bdc, 0x591c10, 0x591c1d, 0x591cbe, 0x591d6e, 0x594f9c, 0x594ff4, 0x595058, 0x59506c, 0x5950a8, 0x5950b7, 0x5950e7, 0x5950f9, 0x595147, 0x595157, 0x5951ab, 0x595275, 0x5952e7, 0x595300, 0x59533b, 0x59534b, 0x5956e3, 0x595c26, 0x595d4e, 0x595f5a, 0x59609a, 0x599ad2, 0x599b5f, 0x599c46, 0x599d3a, 0x59b5e2, 0x59bd2a, 0x59de03, 0x59e6a7, 0x59ef4f, 0x59f648, 0x5a16c4, 0x5a21a8, 0x5a3895, 0x5a39a5, 0x5a3c6b, 0x5a3d58, 0x5a77bd, 0x5a8046
- P7[577-612]: 0x5aa735, 0x5aaaaf, 0x5ab8ae, 0x5ac0a5, 0x5ac391, 0x5ac6ea, 0x5ad18a, 0x5ae0d4, 0x5ae1cb, 0x5b16ba, 0x5b1842, 0x5b1ada, 0x5b1d72, 0x5b1ffa, 0x5b2182, 0x5b240a, 0x5b2592, 0x5b3705, 0x5b3808, 0x5b3ad5, 0x5b3bd8, 0x5b42e6, 0x5b43d8, 0x5b547a, 0x5b5568, 0x5b6ee3, 0x5b7029, 0x5b7263, 0x5b7379, 0x5b857a, 0x5bac4a, 0x5bac9b, 0x5bdbba, 0x5bfdf1, 0x5bfeb1, 0x5bff71

P8 literal 132-xref baseline, sorted ascending:

- P8[001-048]: 0x457c24, 0x457dc3, 0x457e5a, 0x457ebf, 0x457eea, 0x457f0c, 0x457f7b, 0x457fa8, 0x457fca, 0x4580ec, 0x4581e6, 0x45834b, 0x4583f6, 0x458458, 0x4584bc, 0x4584cf, 0x465391, 0x4654b1, 0x466145, 0x4834f9, 0x495102, 0x49dbd6, 0x4b624e, 0x4bb17d, 0x4c61b9, 0x4c61cb, 0x4c7040, 0x4cdd76, 0x4cdd87, 0x4ce899, 0x4d01a9, 0x4d03f9, 0x4d0de4, 0x4d112d, 0x4d1266, 0x4d143f, 0x4d149e, 0x4d169d, 0x4d16cb, 0x4d1c3c, 0x4d1d62, 0x4d2a86, 0x4d2ed8, 0x4d2f7c, 0x4db96c, 0x4dba92, 0x4dc02e, 0x4dd004
- P8[049-096]: 0x4dd05e, 0x4ddb1c, 0x4ddc42, 0x4dde84, 0x4ddedd, 0x4de4dc, 0x4de602, 0x4e1ab7, 0x4e1bd0, 0x4e1d91, 0x4e1de3, 0x4e90c8, 0x4f00bf, 0x4f0192, 0x4f01f5, 0x4f04c7, 0x4f31a7, 0x4f3238, 0x4f3344, 0x4f34ce, 0x4f357c, 0x4f3713, 0x4f4aad, 0x4ff0fb, 0x4ff4bb, 0x50431f, 0x511f63, 0x51205a, 0x5213d1, 0x52147b, 0x523211, 0x523226, 0x523baf, 0x523bc8, 0x543221, 0x573add, 0x573b42, 0x573c10, 0x574864, 0x57488c, 0x574be0, 0x574c74, 0x574d17, 0x574e0b, 0x575282, 0x57672d, 0x57678b, 0x57689e
- P8[097-132]: 0x5865e9, 0x586a4f, 0x586caa, 0x586de9, 0x587069, 0x5871a0, 0x5879d9, 0x588f3d, 0x5890d9, 0x58e636, 0x590289, 0x5902ce, 0x5903a2, 0x590457, 0x590bc1, 0x59181b, 0x591856, 0x591ac8, 0x591afe, 0x591b55, 0x591be3, 0x591c24, 0x591d1d, 0x591df5, 0x595073, 0x5950be, 0x595100, 0x59515e, 0x5951c6, 0x595307, 0x595352, 0x595c6c, 0x595fa2, 0x599ae0, 0x5a38a3, 0x5a39b3

Historical accepted readback: all target and protected prestates/poststates matched. The accepted T1 declarations, exact F1/F2 semantic and physical bindings, comments, complete xref inventories, byte hashes, boundaries, EH state, and vtable item protections persisted. A verifier truncation was resolved by individual complete F1/F2 xref reads; it did not relax the inventories.

## First-Draft C++ Recommendation

- Eligible: yes.
- Target CPP exact insertion:

~~~cpp
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int SortedList::InsertSorted(const void *element)
{
    int index = 0;
    unsigned char *current = static_cast<unsigned char *>(m_data);
    while (index < m_count) {
        if (m_compare(element, current) < 0) {
            break;
        }

        current += m_elementSize;
        ++index;
    }

    MemoryMan *memoryMan = GetMemoryMan();
    int oldCount = m_count;

    int oldPageCount = 1;
    if (oldCount > 0) {
        oldPageCount = ((oldCount - 1) / m_pageSize) + 1;
    }

    int newPageCount = 1;
    if (oldCount >= 0) {
        newPageCount = (oldCount / m_pageSize) + 1;
    }

    if (oldPageCount < newPageCount) {
        size_t byteCount = newPageCount * m_pageSize * m_elementSize;
        MemoryMan *allocator = GetMemoryMan();
        if (m_data != NULL) {
            m_data = allocator->ReallocateBufferMemory(m_data, byteCount);
        } else {
            m_data = allocator->AllocateBufferMemory(byteCount);
        }
    }

    unsigned char *data = static_cast<unsigned char *>(m_data);
    memoryMan->MoveBufferMemory(
        data + ((index + 1) * m_elementSize),
        data + (index * m_elementSize),
        (oldCount - index) * m_elementSize);

    ++m_count;
    memoryMan->MemmoveWrapper(
        data + (index * m_elementSize),
        element,
        m_elementSize);

    return index;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
~~~

- Target H remains blank because declaration belongs to class H.
- Class CPP exact insertion:

~~~cpp
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SortedList.h"
#include "MemoryMan.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
~~~

- Class H exact insertion:

~~~cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "List.h"

class SortedList : public List
{
public:
    SortedList(int elementSize,
               ListCompareFunction compare,
               int pageSize);
    virtual ~SortedList();
    virtual void *GetElementAt(int index);
    virtual void RemoveAt(int index, int count);
    virtual void RemoveAll();

    int InsertSorted(const void *element);
    int FindFirstEqual(const void *key);

private:
    ListCompareFunction m_compare;
};

typedef char SortedListSizeMustBe24[sizeof(SortedList) == 0x18 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
~~~

- Behavior preserved: comparator order/negative break, signed page branches, two GetMemoryMan calls on growth, null/non-null allocation, 32-bit arithmetic, shift/count/copy/return order.
- Dependency legality: `SortedList.h` owns the class declaration; `MemoryMan.h` supplies `MemoryMan`, `GetMemoryMan`, `size_t`, and the invoked MemoryMan members in the translation unit. No MemoryMan declaration is added to the public SortedList header.
- UID000193 formal CPP/H disposition: both remain blank because the page is a nonreconstructable mixed address index; it receives prose/metadata only and must not duplicate children.
- UID0003OL formal CPP/H disposition: retain the existing declaration-generated CPP marker, add no handwritten vtable initializer, and keep H blank because the ordinary class declaration in UID0000DF causes the compiler to generate the vtable/RTTI data.
- Source shape: ordinary C++03-era class, project MemoryMan methods, NULL, no templates/modern wrappers/decompiler names.
- Third-party import: not applicable.

## Final Recommendation

- Ordinary claims C37J-001 through C37J-023 are applied and read back at the exact post-validator destination identities recorded in Current Target State. Supervisor direct support readbacks close same-or-greater/no-edit C37J-024 through C37J-032 at the exact identities above. Scoped validator C37J-056 through C37J-060 and report reconciliation C37J-079 are likewise applied.
- Keep only UID00037J declared as target.
- Keep owner/emitter UID0000DF and reconstructable true.
- Create no child/source owner/file root.
- Do not emit UID000193 or handwritten vtable data.
- Supervisor-owned verification records close the ordinary results, IDA/protection C37J-033 through C37J-050, manual coverage/application/readback C37J-051 through C37J-055 and C37J-061 through C37J-065, and evidence-time generated readbacks C37J-066 through C37J-077. C37J-078 is the applied external-authority contract: report execution/archive state is always determined from the artifact's current path plus validator-owned status/history/registry, never from a static report-body count or path.
- IDA completion evidence is exact: historical recheck/rollback established the original eighteen prestates and proved semantic typing did not propagate to F1's occupied physical row; the successful retry used canonical prestate/backup SHA `400BFA5A1AE2E6C16906DB75060D2A1FDE30BB8DE8DDAB22758FDDC557A84948`, literal semantic-plus-physical calls, exact comments, full P1-P11 verification, one successful save, and fresh persistence session `b005-persist-reopen` PID `2652`. Current canonical IDB SHA256 is `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0`, size `143,196,412`. F2's prior semantic/physical discrepancy and P3's `LObject *` return/receiver remain reconciled and protected.
- No target-affecting research blocker remains. A later concrete contradiction requires an additive same-report repair rather than a new target/report.

## Recommended Target Doc Changes

- Path: by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md.
- Applied disposition: complete semantics/invariants/failure behavior, exact thirteen callers, twelve return pairs, equal-order rule, field layout, source rationale, rejected alternatives, source placement, and history are present.
- Applied disposition: exact CPP is present byte-for-byte; H remains blank with class-declaration rationale.
- Applied disposition: score is `96/96`; owner/emitter UID0000DF, reconstructable true, blank position, exact UID/range/Nested remain unchanged.
- Applied disposition: Item Summary is current and target-specific without duplicating metadata fields.

## Recommended Support Doc Changes

- by-class/SortedList.md: applied exact CPP with both `SortedList.h` and `MemoryMan.h`, exact H, RemoveAt/RemoveAll names, public methods/private m_compare, exact vtable/callers/invariants, standalone route, and `94/94` metadata.
- by-file/SortedList.md: applied standalone CPP/H current decision, historicalized fold, complete emission inventory, and `92/92` metadata.
- by-memory/0x004f3600-0x004f3a43.SortedList.md: preserved NONE/FALSE/no-emitter/blank code, repaired stale gate, and applied `91/93` metadata.
- by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md: corrected locator/ten slots/successor locator, preserved the generated marker, and applied `90/94` metadata.
- No edits to MessageCore, Message, ChangeMan Register, ReallocateOrThrow, List class/file, MemoryMan class/file, proposed tree, or ignored padding because current detail is same-or-greater. MemoryMan class/file are nonetheless explicit legal-dependency evidence for the `MemoryMan.h` CPP include.

## Score And Metadata Recommendation

- Target UID00037J: 91/94 to 96/96; same owner/emitter 0000DF, reconstructable true, CPP nonblank, H blank. Reason higher: exact body/callers/return use/equal ordering/failure behavior/source route and a legal `MemoryMan.h` dependency route are complete. Reason not lower: behavior, ABI, range, route, and formal source are direct or very-strong, and the evidence-time supervisor command-20963 readback visibly emits the accepted body without the former empty marker. Reason not higher: 96 is already the recommended ceiling while original spelling/source text remain inferred.
- Class UID0000DF: 91/90 to 94/94; owner/emitter 0000NU unchanged. Reason higher: complete declaration, exact CPP dependency shell, method/vtable/layout/caller inventory, and resolved standalone route. Reason not lower: constructor/vtable/layout and current owner route are direct. Reason not higher: this report does not final-audit every sibling body and no original declaration survives.
- File UID0000NU: 86/86 to 92/92. Reason higher: current standalone CPP/H route and complete owned-content/exclusion inventory are resolved. Reason not lower: the existing dedicated by-file root/tree/generator route is coherent. Reason not higher: original physical filename remains unprovable.
- Mixed index UID000193: 90/92 to 91/93, owner NONE, reconstructable false, emitter/CPP/H blank. Reason higher: exact child ownership and current source completion replace the stale gate while preserving non-emission. Reason not lower: mixed List/SortedList ownership and exact split are direct. Reason not higher: the range intentionally cannot become one source-emitting unit.
- Vtable UID0003OL: 88/92 to 90/94, owner/emitter 0000KS and declaration-generated marker unchanged. Reason higher: corrected locator, ten exact slots, item/type state, constructor xref, and no-handwritten-code route are complete. Reason not lower: bytes/slot order/xref/compiler-generated role are direct. Reason not higher: original compiler metadata spelling/source declaration text do not survive and this page intentionally emits no handwritten initializer.
- Blocker audit:
  - name/access resolved by symbols/callers/layout/style inference
  - caller/return resolved by 13 xrefs and 12 consumers
  - comparator/order resolved by call/branch
  - layout/type resolved by constructor/target/vtable/type DB
  - failure/helper resolved by allocator docs/body
  - split resolved by exact bytes
  - placement resolved by tree/by-file/generator/RTTI
  - final C++ resolved by exact CPP/H plus the explicit `MemoryMan.h` translation-unit dependency
  - lifecycle authority resolved as a timeless external invariant: current artifact path plus validator-owned status/history/registry determines execution/archive registration

## Open Questions With Attempted Resolution

- Method spelling: checked names, RTTI, reports, docs, callers, project style; adopt InsertSorted.
- Access: checked unrelated direct callers and no friendship/inheritance; adopt public.
- Field spelling/access: checked typedef, assignment, calls, no external direct use; adopt private m_compare.
- Source file: checked tree/root/generator/RTTI/cluster; adopt standalone cpp/h.
- Equal order: checked branch and Message normalization; after-equals.
- Reallocator: checked body/xrefs/doc/collision; adopt MemoryMan::ReallocateBufferMemory.
- F1 prototype/frame binding: checked the restored `__thiscall` type and every physical frame row. Historical Gate 2B then tested and disproved one-step propagation: semantic `set_type` and `func_profile` reached `SortedList *this` plus `const void *element`, but the occupied physical row stayed `Src`/`void *`. The repaired contract therefore requires semantic typing, literal stack-rename dry/actual, literal stack type, and complete frame readbacks; final physical delta remains only `+0x1c`, with `var_8`, `var_4`, saved, and return rows exact.
- F2 calling convention/frame binding: evidence and clean rollback render the complete function as `void *__stdcall(void *Block, _DWORD *pExceptionObject)` while `stack_frame` renders the second physical row at `+0x1c` as `pExceptionObject`/`int`. The body explains the discrepancy by using the value as realloc size and later reusing its storage for the exception pointer. The repaired source-facing transaction first applies and verifies semantic `__thiscall`, then independently renames/retypes `Block` -> `block`/`void *` and `pExceptionObject` -> `newSize`/`size_t` with literal request objects and complete-frame checkpoints. It adds only implicit ECX `MemoryMan *this`, preserves offsets/widths, and separately protects both locals plus saved/return rows.
- P3 protected prototype: evidence-time and rollback state render `LObject *__thiscall(LObject *Block, char)`, including `LObject *` return and implicit ECX receiver, not the earlier generic `_DWORD *` rendering. The exact prototype, all four absent comments, complete five-row physical frame, one vtable data xref, and byte hash remain the no-action protection contract.
- Invalid inputs: checked all branches/callees; preserve absence of validation.
- Translation-unit declarations: checked the proposed SortedList H, accepted List H, target body, and MemoryMan class/file route; include `MemoryMan.h` in SortedList.cpp and keep it out of SortedList.h.
- Report lifecycle authority: checked validator rules; generated CPP/H, routing, scores, and command-20963 tracker rows are bounded evidence-time readbacks, while execution/archive registration is always read from the artifact's current path plus validator-owned status/history/registry. The report body therefore does not encode a static lifecycle count, path, or transition state.
- Unresolved target blocker: none. The empirical F1 propagation failure is closed by the completed explicit semantic-versus-physical operations, save, and fresh-session persistence verification; M01-M05 are applied/validated; bounded command-20963 evidence proves the generated source/routes/scores. Prior F2/P3 contradictions, stale-session defects, manual snapshot drift, generated-command drift, and original-source inference are resolved by the preserved evidence and adopted human-source choices. No raw/decompiler name remains in reconstructed source, and lifecycle is external authority rather than an open research question.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Read-only manual snapshots:

- Current `by-memory/-coverage-report.md`: SHA256 `173A511B7867D262ED36E8E6B834376B71F07C3394736A9856041C7EA903D1A6`, 2,165,505 bytes, 4,869 lines. Exact M01 is line 2085, M02 line 2086 immediately after it, and M03 line 4347 under UID00025N after UID0003OK/before UID00025O. Supervisor command `000000020960` exited 0/`ok:1` with generated refresh skipped.
- Current `by-class/-coverage-report.md`: SHA256 `3912BCDD5DE33E5345354649FFCB2B8EAE830F968ECB0F65DA45D1EE9B8C1F6E`, 276,446 bytes, 625 lines. Exact M04 is line 506 between UID0000DE/UID0000DG. Supervisor command `000000020961` exited 0/`ok:1` with generated refresh skipped.
- Current `by-file/-coverage-report.md`: SHA256 `871595E24D2D53F21AC864689EE0DFCCE8A3294668A829E0FD3018FCE34D1790`, 167,575 bytes, 319 lines. Exact M05 is line 257 between UID0000NT/UID0000NV. Supervisor command `000000020962` exited 0/`ok:1` with generated refresh deferred, followed by coherent full autogen command `000000020963`.
- Superseded pre-application manual identities retained as historical evidence only: by-memory SHA256 `51A04EEA45A7597CFB9374DE4225F1738C3E58C4538B1AC329E5606BFFE7D558`, by-class SHA256 `95E376573DCAE907BDCA842E2A0BDDDED00DC0D1300A534F05D9AFD57F5B36EF`, and by-file SHA256 `74AF672A27E840880F2BD7260B0FE68A66B8A01044854606449E2288D975A135`. Earlier `B130C...`/`6B280...`/`22D7...` and older snapshots remain deeper history.
- Current disposition: all five payloads below were applied verbatim by the supervisor, validated, and independently read back once. B005 did not apply or validate any manual coverage row.

M01 exact applied UID000193 row at current line 2085:

~~~text
    - [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md) 0x004f3600-0x004f3a43 | mixed address-island index | SortedList : not_reconstructable : 91% : very-strong : Non-emitting mixed index over exact SortedList source children plus the neighboring List scalar deleting destructor; UID00037J now carries formal after-equals sorted insertion source, exact 13-caller return-use evidence, complete class/file routing, and no duplicate aggregate emission, while every child retains its own owner/emitter and all internal alignment remains ignored.
~~~

M02 exact applied row immediately after UID000193 at current line 2086:

~~~text
        - [UID:00037J][0x004f3690-0x004f377b.SortedListInsertSorted](by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md) 0x004f3690-0x004f377b | method | SortedList::InsertSorted : reconstructable : 96% : very-strong : Exact int SortedList::InsertSorted(const void *) source body; comparator scans new-versus-current and inserts after equals, minimum-one-page growth uses MemoryMan allocation/reallocation, overlap-safe tail shift and fixed-width copy update count, ChangeMan ignores the returned index, and twelve raw Message helpers consume it for duplicate-sequence normalization.
~~~

M03 exact applied row under UID00025N, after UID0003OK and before UID00025O at current line 4347:

~~~text
        - [UID:0003OL][0x0061ce28-0x0061ce84.ListSortedListVtableData](by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md) 0x0061ce28-0x0061ce84 | vtable-data | List and SortedList RTTI/vtable data : reconstructable : 90% : very-strong : Exact current List/SortedList locator and slot inventory, including SortedList locator 0x00649d78, ten inherited/override slots, constructor-only vtable xref, declaration-generated disposition, List scalar-wrapper route, and no handwritten vtable initializer.
~~~

M04 exact applied class UID0000DF row 506:

~~~text
- [UID:0000DF][SortedList](by-class/SortedList.md) : reconstructable : 94% : very-strong : Complete 0x18 List-derived declaration with ListCompareFunction m_compare at +0x14, exact constructor argument order, inherited/override vtable map, public InsertSorted and FindFirstEqual API, standalone SortedList.h/.cpp route, exact child ownership, ChangeMan and twelve Message insertion consumers, after-equals ordering, and compiler-generated destructor/vtable exclusions.
~~~

M05 exact applied file UID0000NU row 257:

~~~text
- [UID:0000NU][SortedList](by-file/SortedList.md) : reconstructable : 92% : very-strong : NexusTK/util/SortedList.cpp plus SortedList.h source root with complete class declaration, exact child-body routing, comparator/layout/vtable evidence, formal UID00037J after-equals insertion body, ChangeMan and twelve raw Message caller routes, and standalone utility placement selected over the weaker historical List.cpp fold.
~~~

B005 did not apply these rows. Their supervisor-owned application and validator-owned generated refresh are now completed evidence.

## Follow-Up Actions

- Stable actor/order invariants:
  - The accepted ordinary callback remains preserved; no duplicate ordinary implementation callback is implied unless a concrete documentary defect is independently identified.
  - Supervisor verification records directly close C37J-024 through C37J-032 at the exact support hashes and close C37J-033 through C37J-077 through IDA/save/persistence, manual application/validation, and bounded evidence-time command-20963 generated readback.
  - Only the primary supervisor may run report lifecycle commands, and any such action is governed by external audit/verification records rather than scheduled by this report body.
  - Before or after any validator-owned movement, the artifact's current path plus validator-owned status/history/registry is the sole authority for execution/archive registration; C37J-078 records this invariant without a static report count or archive path.
- A-agent actions: none.
- B005: no new target is implied. Repair this same report additively if a specific claim fails; otherwise act only under exact callback.
- These are timeless role/order rules, not mutable lifecycle-state claims.

## Confidence

- Recommendation/runtime/body: very strong.
- Name/access/source-file text: strong.
- Scores: strong.
- Residual uncertainty: original source spelling/file history only, not behavior/current routing.

## Validator Results

- The additive semantic-versus-physical F1/F2 transaction repair after exact artifact `65AE7225834057257148C2488B135EB256EA94F75583E9DD5346B1826F6D2E56` ran no validator and did not reopen the completed ordinary callback. It records the supervisor's failed no-save Gate 2B transaction and clean rollback, then replaces one-step physical propagation assumptions with literal database-scoped stack rename/type requests and readbacks.
- All five authorized commands ran serially from `source-3/project-documentation` with `--apply --no-generated-refresh --queue-timeout 240`; every command exited `0`, reported `ok: 1`, and explicitly reported `generated_refresh: skipped`.
- C37J-056 target: command `000000020835`, timestamp `2026-08-03T00:27:34-04:00`; score/autogen-registry fields updated and one link label normalized; no `missing_ref_uid` warning. Final SHA256 `5190C47498F158A2B084F7892ECE6533D81233BD973F2EF9DE4AC3A37D4825F8`.
- C37J-057 class: command `000000020836`, timestamp `2026-08-03T00:27:50-04:00`; 18 `missing_ref_uid` warnings for pre-existing exact-child references absent from `validator.ini`, plus one link-label normalization. The warnings do not reject the scanned file (`ok: 1`) and B005 did not edit validator-owned registry state. Final SHA256 `311745D5D8826C5096F7F55D7AEFE006D33DBC8F3AE416E7D5C3857799F85BD3`.
- C37J-058 file root: command `000000020837`, timestamp `2026-08-03T00:28:23-04:00`; 12 `missing_ref_uid` warnings for the same pre-existing exact-child references, two link-label normalizations, one reference-index addition, and projected-stats maintenance. Final SHA256 `CD5F763D50E93C2CF607117EA94FCE5BA6FDBBBB5EB8D0A0636D83344E6C8C4F`.
- C37J-059 mixed index: command `000000020838`, timestamp `2026-08-03T00:28:39-04:00`; 18 `missing_ref_uid` warnings for the same pre-existing exact-child references, one reference-index addition, and projected-stats maintenance. Final SHA256 `4906E29A134EB264AB4515BA6B1230B5BAF0EF876C4B12A259F51BB201CDF03C`.
- C37J-060 vtable page: command `000000020839`, timestamp `2026-08-03T00:28:57-04:00`; no `missing_ref_uid` warning, one reference-index addition, and projected-stats maintenance. Final SHA256 `7F2B7219589B8A1ACFCA237AA14D701A5FA72A4E812D561F2FB3F9CEE1375A2A`.
- Post-validator readback compared the target CPP, class CPP, and class H against this report byte-for-byte; all three matched. Target H and mixed-index CPP/H remained blank. All thirteen caller addresses, twelve normalizer addresses, locator `0x00649d78`, ten vtable slots, and xref `0x004f3669` were present.
- Supervisor manual validation: command `000000020960` validated by-memory coverage with `ok:1`/generated skipped; command `000000020961` validated by-class coverage with `ok:1`/generated skipped; command `000000020962` validated by-file coverage with `ok:1`/generated deferred. Current manual hashes are `173A511B7867D262ED36E8E6B834376B71F07C3394736A9856041C7EA903D1A6`, `3912BCDD5DE33E5345354649FFCB2B8EAE830F968ECB0F65DA45D1EE9B8C1F6E`, and `871595E24D2D53F21AC864689EE0DFCCE8A3294668A829E0FD3018FCE34D1790`.
- Coherent full autogen command `000000020963` completed as a bounded evidence-time validation fact. Its snapshot hashes were tracker `EA0B1EFBDD60C9EC3587C24D7770CC2A7A7D6C28269204CA1DDB407CA016BD58`, memory `CEAFBEFFB6782C2D19C272B59809B53303AE565047EF4016E88A198527D3D2E8`, class `DB6E59E30D40A5EBDBD49EAFB95739C7A8D28DAC202CA0B880D4C97B89CDC58A`, file `0208F2A995375DC0F25FA013A943870A5C30DC6A1B9A66FEBDDDD9E55E1CD4C7`, global `58EB72E4B78721D123CE6C56627705F3556C77AED93446AAC13C39B636E02E2A`, SortedList.cpp `3A53E5B0273780257B285015567E2149455559B3E51E75CDD828FDBD45DC4E19`, and SortedList.h `81467431B89434E01BCCD8FA0475417A2B7A5E84D4C51392DA3AB7BFD4762319`. Those bounded rows prove all C37J-066 through C37J-077 semantics; the tracker hash and report counts are not asserted as dynamic current lifecycle truth.
- Report execution and archive registration are external validator-owned state determined from the artifact's current path plus validator-owned status/history/registry, and are not asserted as static state by this report body. B005 did not run a validator, generated refresh, lifecycle command, `execute_report`, or any IDA mutation/save during this reconciliation.

## Changed Files

- B005 ordinary callback destinations:
  - `by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md`
  - `by-class/SortedList.md`
  - `by-file/SortedList.md`
  - `by-memory/0x004f3600-0x004f3a43.SortedList.md`
  - `by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md`
- Same-report additive reconciliation: this report only. It preserves all research, ordinary implementation, failed/no-save history, successful IDA save/persistence proof, exact C++/manual payloads, and physical-stack plan; it records exact no-edit support readbacks C37J-024 through C37J-032, supervisor M01-M05 application/validation, and bounded evidence-time command-20963 generated readback. C37J-001 through C37J-079 are applied, including C37J-078's lifecycle-neutral external-authority contract. Report identity is returned after final write/readback rather than embedded as a self-invalidating hash.
- B005 changed only this report. B005 made no edit to ordinary by-* docs, IDA, manual coverage, generated/tracker, audit, catalog, validator, or lifecycle artifacts. The five historical authorized scoped validators performed their recorded validator-owned `tools/validator.ini` registry and `project-level/-auto-completion-stats.md` projected-stat maintenance; this additive reconciliation ran no validator or refresh.
- Report movement is not asserted by this body; current location and any movement history are external validator-owned authority.
- Callback lease history: B005 leased each ordinary destination immediately before its edit and released it immediately afterward, then reacquired each destination only for its scoped validator and released it immediately after. During the earlier additive reconciliation, the first report-only lease expired before cleanup and the shared lease report showed no surviving B005 lock; a correction/readback lease was then released normally. During the semantic-versus-physical repair, B005 again acquired only the report lease; it expired during the additive edit/readback pass, the explicit cleanup command found no active lease, and shared readback confirmed zero surviving B005/report locks. For the current-authority rebase, B005 acquired only this report lease; the first short lease expired during the evidence/edit/readback pass with no surviving lock, then B005 reacquired the report only for this lease-history correction and released it immediately. No ordinary destination was leased or edited during this repair.
- At any time, lifecycle status is authoritative only from the artifact's current path plus validator-owned status/history/registry metadata. B005 did not run/probe `execute_report` or move/archive the report.

## Implementation Tracking Checklist

Report-only preflight:

- [x] Goal, skill, literal template, by-structure, score-blocker rules read.
- [x] Evidence-time prestates, historical failed/no-save Gate 2B attempt and rollback, successful supervisor retry from exact `400BFA...` canonical/backup prestate, single save, and fresh `b005-persist-reopen` persistence proof against current canonical SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0` are reconciled. B005 performed no IDA mutation/save/process control during this repair.
- [x] Every named blocker resolved or converted to exact action.
- [x] All 33 literal headings present.
- [x] Formal CPP/H uses correct channels.
- [x] One target UID only.

Claim checklist:

- Ledger/checklist parity remains exactly 79 claims in identical C37J-001 through C37J-079 order. Supervisor exact support readbacks close C37J-024 through C37J-032; IDA/save/persistence closes C37J-033 through C37J-050; M01-M05 plus commands 20960/20961/20962 close C37J-051 through C37J-055 and C37J-061 through C37J-065; bounded evidence-time command-20963 readback closes C37J-066 through C37J-077; and C37J-078 closes the lifecycle-neutral external-authority contract. All 79 claim rows are checked.

- [x] C37J-001 incorporated and read back exact target behavior/failure operations in their binary order without modern guards.
- [x] C37J-002 incorporated and read back all thirteen target callers: one ChangeMan caller plus twelve Message callers.
- [x] C37J-003 incorporated and read back all twelve ordered InsertSorted-to-normalizer EAX pairs and their index contract.
- [x] C37J-004 incorporated exact target CPP; post-validator regex comparison against this report was byte-for-byte equal.
- [x] C37J-005 verified target H remains blank and target prose names UID0000DF as declaration owner.
- [x] C37J-006 read back target 96/96, owner/emitter 0000DF, reconstructable true, nonblank CPP, and blank H.
- [x] C37J-007 incorporated class CPP with SortedList.h, MemoryMan.h, and one children marker; post-validator comparison was exact.
- [x] C37J-008 incorporated exact class H declaration; post-validator comparison against this report was byte-for-byte equal.
- [x] C37J-009 read back source-facing InsertSorted/FindFirstEqual/RemoveAt/RemoveAll, public APIs, private m_compare, and 0x18 layout.
- [x] C37J-010 read back the complete class vtable, caller pairs, after-equals invariant, and allocator/failure behavior.
- [x] C37J-011 read back standalone SortedList.h/.cpp as the current class route.
- [x] C37J-012 read back List.cpp folding only in the rejected historical section with its supersession reason.
- [x] C37J-013 read back class 94/94 with owner/emitter 0000NU unchanged.
- [x] C37J-014 read back the standalone CPP/H file route and current NexusTK/util placement.
- [x] C37J-015 read back List.cpp folding only as rejected file-root history.
- [x] C37J-016 read back complete file inventory and explicit UID00037L exclusion.
- [x] C37J-017 read back file metadata 92/92.
- [x] C37J-018 read back the mixed index's exact-child/non-emitting rationale.
- [x] C37J-019 read back stale below-85 wording only as superseded dated history.
- [x] C37J-020 read back mixed index 91/93, NONE, false, blank emitter, and blank CPP/H.
- [x] C37J-021 read back locator 0x00649d78, ten ordered slots, successor locator, and constructor xref 0x004f3669.
- [x] C37J-022 read back declaration-generated/no-handwritten-vtable disposition and the List scalar-wrapper route.
- [x] C37J-023 read back vtable page 90/94, owner/emitter 0000KS, retained generated marker, and blank H.
- [x] C37J-024 supervisor verified MessageCore SHA `E808EF5CF74920B8ACBDA79604E3822E213553E0DA95BB60850D95CF551B28AD` contains same-or-greater exact 24-helper, InsertSorted-call, duplicate-sequence-normalizer, and comparator detail; no edit was required.
- [x] C37J-025 supervisor verified Message class SHA `C2FDCA40E3026B3A1AAB4A6EC8DE6B9555A45A0A9ED215A3EC16ABA626E393D2` contains the owned SortedList, exact 0x98 MessageEntry schema, comparator, and duplicateOrdinal behavior; no edit was required.
- [x] C37J-026 supervisor verified ChangeManRegister SHA `93DA1DA022C55C144D1136AC4EB2B2C08C2263F02FF3CBBEB2CC97C02244C75A` states the exact ignored InsertSorted return and ChangeManEntry route; no edit was required.
- [x] C37J-027 supervisor verified ReallocateOrThrow SHA `D2256B28E9607DE22E8BAE846DE8539A0DB62F4FA1218B98FD420C6B4D1C559F` contains the formal `MemoryMan::ReallocateBufferMemory(void *, size_t)` declaration, realloc-or-throw-new-Win32Error behavior, and source route; no ordinary-doc edit was required.
- [x] C37J-028 supervisor verified List class SHA `9C69E4F370A64A0F15217DB58D2A8BC74D62691DC088E6811EB6888421FD2011` contains `ListCompareFunction`, the exact 0x14 declaration, virtual vocabulary, and four state fields; no edit was required.
- [x] C37J-029 supervisor verified List file SHA `61A1347B4FB168105E191239D6EDAD585752FFE8530FCC24FDB087DF5E98E68E` contains the exact `NexusTK/util/List.cpp`/`List.h` route and sibling ownership; no edit was required.
- [x] C37J-030 supervisor verified MemoryMan class SHA `9D18E2E0FBAD341A2273A016F7C9C042A60A21935514A6FAA3B7AC773D1605A5` owns the required member declarations and preserves GetMemoryMan as a file-level helper; no edit was required.
- [x] C37J-031 supervisor verified MemoryMan file SHA `CC798C04D653795B74EDFB5581EA6AAFA24AB4FF07D62ED9B31C5F79B9352AB1` owns `MemoryMan.h`/`.cpp`, the GetMemoryMan declaration/definition, and ReallocateBufferMemory route; no edit was required.
- [x] C37J-032 supervisor verified ignored-page SHA `731B6A817734311150F210B0EC565146C9C58781F6EEE8FB60131E45C79DDF6A` retains exact `0x004f3681-0x004f3690` and `0x004f377b-0x004f3780` `0xcc` padding spans in the full SortedList alignment list; no edit was required.
- [x] C37J-033 supervisor applied T1 with the exact one-element-array `declare_type` request; exact typedef/0x18 six-member UDT persisted, and List/MemoryMan remained opaque and unchanged. Historical failed/unsaved T1 receives no completion credit.
- [x] C37J-034 supervisor renamed F1; `SortedList_InsertSorted` persisted at 0x004f3690.
- [x] C37J-035 supervisor applied semantic F1 `set_type`, confirmed the expected unchanged physical intermediate, performed literal stack-rename dry/actual `Src` -> `element` and literal stack type `element` -> `const void *`, and read back each complete frame. Fresh persistence readback proves implicit ECX `SortedList *this`, sole physical delta at `+0x1c`, unchanged protected rows/count/stack/range, 96 instructions, 13 exact xrefs, 11 internal comments, and bytes.
- [x] C37J-036 supervisor applied the exact F1 repeatable function comment; fresh readback proves its payload and three absent sibling comment states.
- [x] C37J-037 supervisor renamed F2; `MemoryMan_ReallocateBufferMemory` persisted at 0x00516190.
- [x] C37J-038 supervisor matched semantic/physical F2 prestates, applied semantic `__thiscall` with the expected unchanged physical intermediate, then performed literal dry/actual rename and stack-type actions for `Block` -> `block`/`void *` and `pExceptionObject` -> `newSize`/`size_t`. Fresh persistence readback proves exact semantic prototype/implicit ECX, exact +0x18/+0x1c rows, unchanged protected rows/count/stack/range/EH, 52 instructions, ten exact xrefs, comments, and bytes.
- [x] C37J-039 supervisor applied the exact F2 repeatable function comment; fresh readback proves its payload and three absent sibling comment states.
- [x] C37J-040 supervisor verified P1 name/type/comments/frame/two xrefs/byte hash unchanged before save and after fresh reopen.
- [x] C37J-041 supervisor verified P2 name/type/comments/frame/14 xrefs/byte hash unchanged before save and after fresh reopen.
- [x] C37J-042 supervisor verified P3 remains exactly `sub_4F38B0`, `LObject *__thiscall(LObject *Block, char)`, with implicit `LObject *` ECX receiver/return, all four comments absent, complete `+0x08/+0x10/+0x14/+0x18/+0x1c` frame, sole vtable ref `0x0061ce58`, and byte hash unchanged before save and after fresh reopen.
- [x] C37J-043 supervisor verified P4 identity/type/comments/frame/vtable ref/byte hash unchanged before save and after fresh reopen.
- [x] C37J-044 supervisor verified P5 identity/type/comments/frame/vtable ref/byte hash unchanged before save and after fresh reopen.
- [x] C37J-045 supervisor verified P6 identity/type/comments/frame/vtable ref/byte hash unchanged before save and after fresh reopen.
- [x] C37J-046 supervisor verified P7 identity/type/comments/frame/all 612 xrefs/xref hash/byte hash unchanged before save and after fresh reopen.
- [x] C37J-047 supervisor verified P8 identity/type/comments/frame/EH/all 132 xrefs/xref hash/byte hash unchanged before save and after fresh reopen.
- [x] C37J-048 supervisor verified P9 identity/type/comments/frame/all 604 xrefs/byte hash unchanged before save and after fresh reopen.
- [x] C37J-049 supervisor verified P10 identity/type/comments/frame/19 xrefs/byte hash unchanged before save and after fresh reopen.
- [x] C37J-050 supervisor verified P11 ten item bounds/base name/blank types/comments/slots/locator/xref/byte hash unchanged before save and after fresh reopen.
- [x] C37J-051 supervisor applied exact M01 at UID000193 line 2085; read back once.
- [x] C37J-052 supervisor applied exact M02 immediately after M01 at line 2086; read back once.
- [x] C37J-053 supervisor applied exact M03 at UID00025N sibling anchor line 4347; read back once.
- [x] C37J-054 supervisor applied exact M04 at UID0000DF line 506; read back once.
- [x] C37J-055 supervisor applied exact M05 at UID0000NU line 257; read back once.
- [x] C37J-056 target validator command 000000020835 exited 0/ok 1; hash and no-missing-ref warning state recorded.
- [x] C37J-057 class validator command 000000020836 exited 0/ok 1; hash and 18 missing-ref warnings recorded.
- [x] C37J-058 file validator command 000000020837 exited 0/ok 1; hash and 12 missing-ref warnings recorded.
- [x] C37J-059 mixed-index validator command 000000020838 exited 0/ok 1; hash and 18 missing-ref warnings recorded.
- [x] C37J-060 vtable validator command 000000020839 exited 0/ok 1; hash and no-missing-ref warning state recorded.
- [x] C37J-061 supervisor command 20960 validated/read back manual UID000193 M01 once; current by-memory hash `173A511B7867D262ED36E8E6B834376B71F07C3394736A9856041C7EA903D1A6`.
- [x] C37J-062 supervisor command 20960 validated/read back manual UID00037J M02 once in the same identity.
- [x] C37J-063 supervisor command 20960 validated/read back manual UID0003OL M03 once in the same identity.
- [x] C37J-064 supervisor command 20961 validated/read back manual UID0000DF M04 once; current class hash `3912BCDD5DE33E5345354649FFCB2B8EAE830F968ECB0F65DA45D1EE9B8C1F6E`.
- [x] C37J-065 supervisor command 20962 validated/read back manual UID0000NU M05 once; current file hash `871595E24D2D53F21AC864689EE0DFCCE8A3294668A829E0FD3018FCE34D1790`.
- [x] C37J-066 supervisor verified evidence-time command-20963 UID0000DF generated CPP two-include shell and no class empty marker at SortedList.cpp SHA256 `3A53E5B0273780257B285015567E2149455559B3E51E75CDD828FDBD45DC4E19`.
- [x] C37J-067 supervisor verified evidence-time command-20963 UID00037J generated CPP body once and no target empty marker in the same SortedList.cpp identity.
- [x] C37J-068 supervisor verified evidence-time command-20963 UID0000DF generated H exact declaration/children expansion at SortedList.h SHA256 `81467431B89434E01BCCD8FA0475417A2B7A5E84D4C51392DA3AB7BFD4762319`.
- [x] C37J-069 supervisor verified evidence-time command-20963 UID00037J contributes no duplicate H declaration in the same SortedList.h identity.
- [x] C37J-070 supervisor verified evidence-time command-20963 UID00037J coded owner/emitter 0000DF, CPP yes/H no, SortedList.cpp row at memory-coverage SHA256 `CEAFBEFFB6782C2D19C272B59809B53303AE565047EF4016E88A198527D3D2E8`.
- [x] C37J-071 supervisor verified evidence-time command-20963 UID000193 not_reconstructable/NONE/no-output row in the same memory-coverage identity.
- [x] C37J-072 supervisor verified evidence-time command-20963 UID0003OL coded 0000KS/generated List.cpp row in the same memory-coverage identity.
- [x] C37J-073 supervisor verified evidence-time command-20963 tracker SHA256 `EA0B1EFBDD60C9EC3587C24D7770CC2A7A7D6C28269204CA1DDB407CA016BD58` UID00037J 96/96 true with zero report counts in that bounded snapshot; no current registration state is asserted.
- [x] C37J-074 supervisor verified evidence-time command-20963 UID0000DF 94/94 true with zero report counts in that bounded tracker snapshot; no current registration state is asserted.
- [x] C37J-075 supervisor verified evidence-time command-20963 UID0000NU 92/92 with zero report counts in that bounded tracker snapshot; no current registration state is asserted.
- [x] C37J-076 supervisor verified evidence-time command-20963 UID000193 91/93 false with zero report counts in that bounded tracker snapshot; no current registration state is asserted.
- [x] C37J-077 supervisor verified evidence-time command-20963 UID0003OL 90/94 true with zero report counts in that bounded tracker snapshot; no current registration state is asserted.
- [x] C37J-078 records the lifecycle-neutral contract that the artifact's current path plus validator-owned status/history/registry is the sole authority for report execution/archive registration before or after any movement; this body encodes no static report count, archive path, or transition state.
- [x] C37J-079 reconciled this same report with destination identities, validator evidence, failed Gate 2B/rollback facts, literal repaired F1/F2 transactions, ledger/checklist parity, actor provenance, and lifecycle-neutral wording.

Implementation boundary:

- [x] Historical exact report SHA 88598C88818D1CF175510EB252D516DD5DF4DE9A8EEE7DF8574CFEC51A337158 received supervisor Gate 1 acceptance before ordinary callback.
- [x] B005 callback evidence and validator identities are reconciled into this same report.
- [x] Exact-artifact report-quality audits are supervisor-owned external evidence and are neither scheduled nor asserted as current state by this report body.
- [x] Ordinary-evidence rebind/verification is independently supervisor-owned; this report preserves the verified facts without asserting mutable gate state.
- [x] Supervisor Gate 2B IDA/save/fresh-reopen persistence closure for C37J-033 through C37J-050.
- [x] Supervisor manual and bounded evidence-time generated closure for C37J-051 through C37J-077.
- [x] Any report lifecycle command is primary-supervisor-only and is governed by external audit/verification records rather than scheduled by this report body.
- [x] Before or after validator-owned movement, the artifact's current path plus validator-owned status/history/registry is the sole lifecycle authority; this report never encodes a static report count or archive path.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000020965","destination_path":"executed-b-agent-research/B005/00037J-SortedListInsertSorted-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00037J-SortedListInsertSorted-empty-emitter-source-quality.md","timestamp":"2026-08-04T00:08:57-04:00","uid":"00037J"} -->
<!-- {"agent":"B005","command_id":"000000020967","destination_path":"tools/leaser/Agents/Agent-B005/research/00037J-SortedListInsertSorted-empty-emitter-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B005/00037J-SortedListInsertSorted-empty-emitter-source-quality.md","timestamp":"2026-08-04T00:12:27-04:00","uid":"00037J"} -->
<!-- {"agent":"B005","command_id":"000000020968","destination_path":"executed-b-agent-research/B005/00037J-SortedListInsertSorted-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00037J-SortedListInsertSorted-empty-emitter-source-quality.md","timestamp":"2026-08-04T00:34:27-04:00","uid":"00037J"} -->
<!-- {"agent":"B005","command_id":"000000023052","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00037J-SortedListInsertSorted-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00037J-SortedListInsertSorted-empty-emitter-source-quality.md","timestamp":"2026-08-13T03:35:41-04:00","uid":"00037J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
