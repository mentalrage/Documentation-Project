** TARGET-REPORT-UID:0001BA **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001BA MemoryMan / Allocation Helper Source-Split Research

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:0001BA] `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md` from an emitting reconstructable aggregate to a reviewed non-emitting split index over exact MemoryMan class methods, file-level allocation/copy helpers, ignored padding, and one ignored no-xref return-zero stub.
- Final disposition: keep the source family in [UID:0000L7] `by-file/MemoryMan.md` / `NexusTK/util/MemoryMan.cpp`; exact children carry all source-bearing ownership and emission routes.
- Required action: supervisor should create one exact ignored child page for `0x00516040-0x00516045`, add internal ignored padding rows, update existing child/source-owner metadata where noted, and replace the shared `by-memory/-coverage-report.md` rows with the executable text below.
- Confidence: high for range boundaries, raw bytes, xrefs, call fanout, static lifetime wiring, and source-family placement; medium-high for final public helper names and header factoring.

## Target

- Target UID: [UID:0001BA]
- Target path: `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md`
- Assignment slug: `B001-goal2-memoryman-allocation-source-split-0001BA-20260616`
- Source queue/report row: `project-level/-auto-completion-stats.md` lists [UID:0001BA] at `82/86`; supervisor notes route it to B001 because the visible blocker is the `MemoryMan.cpp` / allocation helper / global operator source split.
- Current state: `COMPLETION:82`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`.

## Executive Recommendation

[UID:0001BA] should not remain a source-emitting by-memory object. The real source roots are the existing exact child pages and related non-contiguous pages:

- [UID:00007U] `MemoryMan` class owns the constructor, ordinary destructor/reset body, and scalar deleting destructor.
- [UID:0000L7] `MemoryMan.cpp` owns the process-level allocation API helpers, copy wrappers, `GetMemoryMan`, `g_pMemoryMan`, and the global `operator new` / `operator delete` implementations.
- [UID:0000WA] and [UID:0001O7] are compiler/static-lifetime glue; they should remain non-reconstructable and regenerated from source static object declarations.
- `0x00516040-0x00516045` is real code bytes but has no IDA function object, no xrefs, and no raw pointer/call hits. It should get a small exact ignored child page, assumed [UID:0003VP], rather than being silently hidden inside the parent.
- All internal `0xcc` gaps should be recorded in [UID:0000VN] `by-memory/-ignored.md` and in nested coverage rows under [UID:0001BA].

After those changes, [UID:0001BA] can be `88/90`, `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:0000L7`, blank `EMITTER_UIDS`. No final C++ should be placed on [UID:0001BA].

## Supervisor Active Recheck

- The supervisor assigned this to Agent-B001 as report-only heavy source-split work. No leases were acquired.
- The assigned item required split repair before a final recommendation because the parent currently overlaps exact children and still omits the `0x00516040-0x00516045` no-xref stub plus internal ignored padding rows.
- This report is executable but does not directly edit `by-*`, generated reports, IDA DB, or `by-memory/-coverage-report.md`.

## Current Working-Tree Target Page Review

The local target page `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md` is dirty from the earlier Agent-A001 role collision and is not supervisor-accepted as A001 work. I reviewed the current working-tree content and its `git diff` against the checked-in page before making this B001 recommendation.

### What A001 Changed

- Metadata changed from `COMPLETION:82`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID:0000L7`, and `AUTOGEN_PARENT_POSITION_OPTIONAL:` to `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000L7`, `EMITTER_UIDS:0000L7`, and `EMITTER_POSITION_OPTIONAL:`.
- The page still has `RECONSTRUCTABLE:TRUE` and still emits through [UID:0000L7][MemoryMan](by-file/MemoryMan.md).
- A001 added a `2026-06-16 A001 Source-Quality Refresh` section with useful IDA facts for starts, xrefs, callees, the `0x00516040-0x00516045` raw stub, padding, source-name search limits, and generated-output state.
- A001 concluded "No split/merge/rename is justified" and recommended keeping `0x00516040-0x00516045` documented inside the aggregate rather than promoting an exact child page.

### B001 Disposition Of Those Edits

- Valid evidence to salvage: most of the IDA facts are consistent with this B001 audit, including exact helper boundaries, `0x00516290` successor, singleton/static-object/vtable xrefs, operator-wrapper callees, broad helper reachability, the `33 c0 c2 04 00` no-xref stub bytes, and blank generated `MemoryMan.cpp`.
- Incomplete evidence handling: A001 did not turn the internal `0xcc` spans into exact ignored rows, did not make an exact page for the code-shaped no-xref stub, did not reroute constructor/destructor ownership to [UID:00007U][MemoryMan](by-class/MemoryMan.md), did not repair [UID:000196]/[UID:000197], [UID:0000WA], or [UID:0001O7] scoring, and did not provide executable coverage/support-doc rows.
- Invalid conclusion under B workflow: the parent should not stay `RECONSTRUCTABLE:TRUE` / `EMITTER_UIDS:0000L7`. That keeps an overbroad aggregate as a source-emitting object while exact children already own the reconstructable bodies, and it leaves the memory-tool internal gap/stub issue unresolved.
- Superseded recommendation: reject the A001 "No split/merge/rename is justified" conclusion. Replace it with the B001 split-index recommendation in this report: [UID:0001BA] becomes non-reconstructable/non-emitting at `88/90`; exact reconstructable children and support pages carry source ownership; [UID:0003VP] is the assumed exact ignored child page for `0x00516040-0x00516045`.

### Supervisor Action For The Dirty Target Page

Do not accept the current A001-edited target page as complete. Either revert that page to the checked-in baseline first or directly replace the A001 metadata/status/conclusion sections with the B001 text in "Exact Existing Page Updates" below. The supervisor-owned final target page should have:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Preserve A001's raw IDA facts only as supporting evidence if desired, but remove or supersede the A001 statements that the aggregate is reconstructable, source-emitting, complete at `86/88`, and not split-worthy.

## Evidence Standards Used

- IDA MCP session: `a002_goal65_20260616`, IDB path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, Hex-Rays ready.
- IDA tools used: `server_health`, `lookup_funcs`, `disasm`, `decompile`, `xrefs_to`, `analyze_component`, `get_bytes`.
- Raw PE audit: read-only parse of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x400000`, `.text` section mapped directly from PE headers; scanned exact bytes, rel32 calls, and absolute dword pointer hits.
- Documentation evidence checked: assigned parent, all children [UID:0001B9]-[UID:0001BJ], [UID:000196], [UID:000197], [UID:0000WA], [UID:0001O7], [UID:0000L7], [UID:00007U], [UID:0000T8], [UID:0000RH], [UID:0001V4], [UID:00029R], [UID:0002B0], `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, `auto-generated/-ag-memory-coverage.md`, `by-project-structure/proposed-source-tree.md`, and current generated/simroot MemoryMan output.
- Generated evidence is treated as a lead only. The final recommendation relies on IDA and raw byte facts.

## IDA / PE Facts

### Function And Range Facts

| Range | IDA state | Role | Recommendation |
| --- | --- | --- | --- |
| `0x00516000-0x0051600f` | function `sub_516000`, size `0xf` | `MemoryMan` constructor; writes vtable and `g_pMemoryMan` | Keep reconstructable, reroute owner/emitter to [UID:00007U]. |
| `0x00516010-0x00516021` | tail chunk resolved through `sub_60C260` | ordinary `MemoryMan` destructor/reset body; writes vtable and clears `g_pMemoryMan` | Rename from `MemoryManGlobalResetTail` to `MemoryManDestructor`, reroute owner/emitter to [UID:00007U]. |
| `0x00516030-0x00516036` | function `sub_516030`, size `0x6` | `GetMemoryMan`, returns `g_pMemoryMan` | Keep with [UID:0000L7]. |
| `0x00516040-0x00516045` | no IDA function; disassembles as `xor eax,eax; retn 4` | no-xref return-zero stub | Create ignored/non-emitting child [UID:0003VP]. |
| `0x00516050-0x005160ce` | function `sub_516050`, size `0x7e` | `malloc` or throw `Win32Error` | Keep with [UID:0000L7]. |
| `0x005160d0-0x00516162` | function `sub_5160D0`, size `0x92` | `malloc`, zero-fill, or throw `Win32Error` | Keep with [UID:0000L7]. |
| `0x00516170-0x00516184` | function `sub_516170`, size `0x14` | `free(block); return 0` | Keep with [UID:0000L7]. |
| `0x00516190-0x00516210` | function `sub_516190`, size `0x80` | `realloc` or throw `Win32Error` | Keep with [UID:0000L7]. |
| `0x00516220-0x00516238` | function `sub_516220`, size `0x18` | `memmove` wrapper | Keep with [UID:0000L7], raise to `86/88`. |
| `0x00516240-0x00516258` | function `sub_516240`, size `0x18` | alternate `memmove_0` wrapper | Keep with [UID:0000L7], raise to `86/88`. |
| `0x00516260-0x0051628e` | function `sub_516260`, size `0x2e` | scalar deleting destructor; vtable slot at `0x0061eb08` | Already correctly routed through [UID:00007U]. |
| `0x00516290` | successor function | unrelated `MenuPane` island | Confirms [UID:0001BA] end. |

### Byte Audit

Raw PE bytes prove the internal gaps are pure `0xcc` except the `0x00516040` stub:

| Range | Bytes / classification |
| --- | --- |
| `0x0051600f-0x00516010` | one `0xcc` byte |
| `0x00516021-0x00516030` | fifteen `0xcc` bytes |
| `0x00516036-0x00516040` | ten `0xcc` bytes |
| `0x00516040-0x00516045` | `33 c0 c2 04 00`, `xor eax,eax; retn 4` |
| `0x00516045-0x00516050` | eleven `0xcc` bytes |
| `0x005160ce-0x005160d0` | two `0xcc` bytes |
| `0x00516162-0x00516170` | fourteen `0xcc` bytes |
| `0x00516184-0x00516190` | twelve `0xcc` bytes |
| `0x00516210-0x00516220` | sixteen `0xcc` bytes |
| `0x00516238-0x00516240` | eight `0xcc` bytes |
| `0x00516258-0x00516260` | eight `0xcc` bytes |
| `0x0051628e-0x00516290` | two `0xcc` bytes; already recorded in [UID:0000VN] |

### Xref / Caller Facts

- `0x00516040`: `xrefs_to` reports zero refs. Raw PE scan found zero rel32 call hits and zero absolute dword pointers to `0x00516040`.
- `0x004f4aa0`: raw PE scan found `1785` rel32 calls to the global allocation wrapper.
- `0x004f4ac0`: raw PE scan found `2129` rel32 calls to the global delete wrapper.
- `0x00516030`: raw PE scan found `612` rel32 calls to `GetMemoryMan`.
- `0x00516050`: raw PE scan found `132` rel32 calls to `AllocateBufferMemory`.
- `0x005160d0`: raw PE scan found `13` rel32 calls to the zero-allocation helper.
- `0x00516170`: raw PE scan found `210` rel32 calls to `FreeBufferMemory`.
- `0x00516190`: raw PE scan found `10` rel32 calls to `ReallocateOrThrow`.
- `0x00516220`: raw PE scan found `604` rel32 calls to the primary `memmove` wrapper.
- `0x00516240`: raw PE scan found `19` rel32 calls to the alternate `memmove_0` wrapper.
- `0x00516260`: IDA `xrefs_to` reports one data ref from the MemoryMan vtable slot at `0x0061eb08`.
- `0x0061eb08`: IDA `xrefs_to` reports constructor, destructor/reset, and scalar deleting destructor refs.
- `0x0069b3a8`: IDA `xrefs_to` reports only the static initializer and atexit thunk.
- `0x0069b4fc`: IDA `xrefs_to` reports constructor write, destructor/reset clear, accessor read, and scalar deleting destructor clear.

### Decompilation Facts

- `0x00419f70`: `sub_516000(&unk_69B3A8); return atexit(sub_60C260);`
- `0x0060c260`: writes `unk_69B3A8 = &MemoryMan::vftable` and `unk_69B4FC = 0`.
- `0x004f4aa0`: calls `GetMemoryMan`, then returns `AllocateBufferMemory(size)`.
- `0x004f4ac0`: calls `GetMemoryMan`, then returns `FreeBufferMemory(block)`.
- `0x00516050`, `0x005160d0`, and `0x00516190`: call CRT allocation routines and throw `Win32Error` through `_CxxThrowException` on failure.
- `0x00516260`: writes the `MemoryMan` vtable, clears `g_pMemoryMan`, optionally calls delete helper based on the low deletion flag, and returns `this`.

## Function / Child Inventory

| Item | Current UID / Path | Current route | Recommended route | Score |
| --- | --- | --- | --- | --- |
| Parent island | [UID:0001BA] `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md` | `TRUE`, owner/emitter [UID:0000L7] | split index, `FALSE`, semantic owner [UID:0000L7], blank emitter | `88/90` |
| Constructor | [UID:0001B9] `0x00516000-0x0051600f.MemoryManConstructor` | owner/emitter [UID:0000L7] | owner/emitter [UID:00007U] | `86/90` |
| Ordinary destructor/reset | [UID:0001BB] `0x00516010-0x00516021.MemoryManGlobalResetTail` | owner/emitter [UID:0000L7] | rename to `MemoryManDestructor`, owner/emitter [UID:00007U] | `86/90` |
| Accessor | [UID:0001BC] `0x00516030-0x00516036.GetMemoryMan` | owner/emitter [UID:0000L7] | no route change; score raise only | `86/90` |
| No-xref stub | assumed [UID:0003VP] `0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub` | missing | ignored/non-emitting | `85/88` |
| Allocate | [UID:0001BD] `0x00516050-0x005160ce.AllocateBufferMemory` | owner/emitter [UID:0000L7] | no route change | `85/88` |
| Zero allocate | [UID:0001BE] `0x005160d0-0x00516162.ZeroAllocateBufferMemory` | owner/emitter [UID:0000L7] | no route change | `85/88` |
| Free | [UID:0001BF] `0x00516170-0x00516184.FreeBufferMemory` | owner/emitter [UID:0000L7] | no route change | `85/89` |
| Reallocate | [UID:0001BG] `0x00516190-0x00516210.ReallocateOrThrow` | owner/emitter [UID:0000L7] | no route change | `85/88` |
| Copy wrapper | [UID:0001BH] `0x00516220-0x00516238.MemmoveWrapper` | owner/emitter [UID:0000L7] | no route change; source placement resolved to MemoryMan utility family | `86/88` |
| Alternate copy wrapper | [UID:0001BI] `0x00516240-0x00516258.Memmove0Wrapper` | owner/emitter [UID:0000L7] | no route change; source placement resolved to MemoryMan utility family | `86/88` |
| Scalar deleting destructor | [UID:0001BJ] `0x00516260-0x0051628e.MemoryManScalarDeletingDestructor` | owner/emitter [UID:00007U] | no route change | `86/90` |
| Static initializer | [UID:0000WA] `0x00419f70-0x00419f86.MemoryManStaticInitializer` | `FALSE`, no owner/emitter | no route change; score to `85/90` | `85/90` |
| Atexit thunk | [UID:0001O7] `0x0060c260-0x0060c26a.MemoryManAtexitResetThunk` | `FALSE`, no owner/emitter | no route change; score to `85/90` | `85/90` |
| Global operator new | [UID:000196] `0x004f4aa0-0x004f4ab4.OperatorNewWrapper` | owner/emitter [UID:0000L7], `82/90` | no route change; score to `85/90`, source name `operator new` | `85/90` |
| Global operator delete | [UID:000197] `0x004f4ac0-0x004f4b00.OperatorDeleteWrapper` | owner/emitter [UID:0000L7], `82/90` | no route change; score to `85/90`, source name `operator delete` | `85/90` |

## Ranked Ownership Analysis

### 1. `NexusTK/util/MemoryMan.cpp` As Source Family

- Evidence for: proposed source tree already places this family in `util/MemoryMan.cpp`; Wave2/simroot provenance imports `MemoryMan` from `MemoryMan.cpp`; live IDA shows the static object, singleton pointer, accessor, allocation wrappers, copy wrappers, and global operators are a coherent utility family; broad call fanout rules out feature ownership.
- Evidence against: generated output currently fragments bodies across class/global/recovered files and has raw-address trampoline source-quality failures.
- Decision: accepted. Use [UID:0000L7] as the file-level owner/emitter for free helpers, global operators, globals, and source declarations.

### 2. `MemoryMan` Class [UID:00007U]

- Evidence for: constructor and destructor/reset body write the `MemoryMan` vtable; scalar deleting destructor is the vtable slot; class page and layout page clear `85/85`.
- Evidence against: the object has only one observed data field, and much allocation behavior is implemented as free helpers rather than members.
- Decision: accepted for constructor, ordinary destructor/reset body, scalar deleting destructor, and layout. Reject direct class ownership for global allocation helpers and operators.

### 3. `MemoryAllocationHelpers` Global Page [UID:0000T8]

- Evidence for: it is the correct name-centric index over helper APIs and includes all relevant helper pages.
- Evidence against: by-structure says `CANONICAL_OWNER` should be a direct semantic owner. This page is an index/helper family, not a source root or C++ declaration owner for individual free functions.
- Decision: keep as an index attached to [UID:0000L7], not the direct canonical owner of by-memory helper bodies.

### 4. Separate Runtime / CRT Wrapper Source

- Evidence for: `0x00516220` and `0x00516240` are thin wrappers over CRT `memmove` variants; global operators are language/runtime-looking entry points.
- Evidence against: all are clustered in the MemoryMan source island, generated provenance already groups them with `class_MemoryMan.cpp`, there is no stronger neighboring CRT-wrapper source owner, and the global operators explicitly call `GetMemoryMan` and the MemoryMan allocation helpers.
- Decision: rejected for now. Keep global operators and copy wrappers in the MemoryMan utility family. This resolves the placement blocker enough for `85/85+`; final C++ still needs exact declarations and project style.

### 5. No-Owner / Non-Emitting For `0x00516040`

- Evidence for: code-shaped bytes exist, but IDA has no function object, `xrefs_to` finds no refs, raw PE rel32 and absolute pointer scans find no refs, and no generated/source metadata attaches it to a source entity.
- Evidence against: address adjacency makes [UID:0000L7] the best candidate if future evidence proves source use.
- Decision: create an ignored/non-emitting exact child page. Do not attach it to [UID:0000L7] until reachability or source-use context is proven.

## Source-Quality Blocker Resolution

- Method/member/helper names:
  - Resolved: [UID:0001B9] is `MemoryMan::MemoryMan`.
  - Resolved: [UID:0001BB] should be `MemoryMan::~MemoryMan` / `MemoryManDestructor`, not `MemoryManGlobalResetTail`.
  - Resolved: [UID:000196] and [UID:000197] are source-level global `operator new` and `operator delete`, not unrelated recovered globals.
  - Still open: exact public helper spellings for `ZeroAllocateBufferMemory`, `ReallocateOrThrow`, and the two copy wrappers. Current names are adequate documentation names but not final-C++ API names.
- Field/global names:
  - Resolved enough: `g_pMemoryMan` remains the process-wide singleton pointer at `0x0069b4fc`.
  - Resolved enough: static object storage at `0x0069b3a8` should be a source-declared static `MemoryMan` object in `MemoryMan.cpp`; exact original variable name remains unknown.
- Source-file placement:
  - Resolved: `MemoryMan.cpp` is the best-supported file family for the class, singleton, helper APIs, global operators, and copy wrappers.
  - Rejected: separate CRT wrapper source for the copy wrappers; no stronger evidence than the MemoryMan island.
- Generated-output omissions:
  - Current `auto-generated/NexusTK/util/MemoryMan.cpp` is empty because child pages carry blank C++.
  - Current `simroot_v2/class_MemoryMan.cpp` is a useful lead but has raw-address trampolines, duplicate throw helpers, modern `nullptr`, explicit calling-convention artifacts, and generated class/global fragmentation.
- Compiler-shaped helpers:
  - [UID:0000WA] and [UID:0001O7] should stay `RECONSTRUCTABLE:FALSE`.
  - [UID:0001BJ] is compiler-emitted scalar deleting destructor code but remains reconstructable documentation because it is a vtable-slot class destructor wrapper; final C++ should likely express the ordinary destructor and let the compiler regenerate the scalar deleting wrapper.
- Final-C++ eligibility:
  - All reconstructable recommended routes clear the strict routing gate after this report.
  - Do not add final C++ yet. The minimum combined-score/emitter gate can be met, but final source still needs exact helper declarations, non-duplicated throw helper factoring, correct `operator new/delete` signatures, C-style rather than generated trampoline style, and header placement.

## Exact New Child Page Markdown

Assumption: [UID:0003VF]-[UID:0003VO] are already proposed by the current B001 ArgumentedMenu report, and public docs/reports show no use of [UID:0003VP] at the time of this audit. Use [UID:0003VP] for this child unless the supervisor has newer private allocations; if consumed before application, allocate the next available UID and update every reference consistently.

### `by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md`

````markdown
*** UID:0003VP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x00516040-0x00516045 MemoryMan No-Xref Return-Zero Stub

## Status

- Disposition: ignored/non-emitting exact stub inside the MemoryMan helper island.
- Entity kind: no-xref raw code-shaped stub.
- Rebuild handling: unknown/no source-use context; do not reconstruct as standalone source.
- Best candidate if future evidence appears: [UID:0000L7][MemoryMan](by-file/MemoryMan.md).

## Bytes And Behavior

```text
0x00516040: 33 c0        xor eax, eax
0x00516042: c2 04 00     retn 4
```

The body returns zero and callee-cleans one stack argument. It sits between [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) and [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md).

## Evidence

- 2026-06-16 B001 IDA MCP `lookup_funcs` reports `0x00516040` is not a function.
- 2026-06-16 B001 IDA MCP `disasm 0x00516040` decodes `xor eax, eax; retn 4`, followed by `align 10h` and the next modeled function at `0x00516050`.
- 2026-06-16 B001 IDA MCP `xrefs_to 0x00516040` reports zero cross-references.
- 2026-06-16 B001 raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found zero rel32 calls and zero absolute dword pointer hits to `0x00516040`.
- Raw PE bytes confirm `0x00516036-0x00516040` and `0x00516045-0x00516050` are `0xcc` alignment around this exact body.

## Ownership Decision

Do not attach this stub to [UID:0000L7][MemoryMan](by-file/MemoryMan.md) yet. Address adjacency makes `MemoryMan.cpp` the best candidate if forced, but there is no caller, function pointer, vtable slot, absolute pointer, startup-table reference, generated source entity, or other source-use context proving the rebuilt source must contain this function.

## Score Rationale

Completion is `85` because the page records the exact bytes, behavior, neighboring boundaries, xref absence, raw pointer/call absence, best rejected owner candidate, and ignore policy. Confidence is `88` because the no-xref/no-pointer evidence is direct, but the original reason this stub was emitted remains unknown.

## Cross-References

- [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md)
- [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md)

## Changes

- 2026-06-16 B001 report recommendation:
  - Created as an exact ignored/non-emitting child split from [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md).
  - Evidence: IDA MCP reports no function object and no xrefs; raw PE scan reports no rel32 calls or absolute pointer hits; bytes decode as a five-byte return-zero stub surrounded by `0xcc` alignment.
````

## Exact Existing Page Updates

### [UID:0001BA] Parent Metadata

Replace the metadata header values:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Add or replace the status summary with:

```markdown
## Status

- Disposition: reviewed non-emitting split index over the MemoryMan source family.
- Entity kind: compact source-neighborhood inventory / split index.
- Semantic source-file owner: [UID:0000L7][MemoryMan](by-file/MemoryMan.md).
- Rebuild handling: parent is `RECONSTRUCTABLE:FALSE`; exact child pages carry source ownership and emission routes.
- C++: parent C++ remains blank. Do not emit source directly from this aggregate.
```

Add a split inventory table containing every child/padding row from the coverage block below.

### [UID:0001B9] Constructor

Recommended metadata route change:

```text
*** CANONICAL_OWNER:00007U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Add change note:

```markdown
- 2026-06-16 B001 source-split audit:
  - Changed route recommendation: owner/emitter should move from [UID:0000L7][MemoryMan](by-file/MemoryMan.md) to [UID:00007U][MemoryMan](by-class/MemoryMan.md).
  - Evidence: live IDA and raw PE evidence prove this is the `MemoryMan` class constructor: it writes `MemoryMan::vftable` to `this+0x00`, publishes `this` to `g_pMemoryMan`, and has the static initializer caller at `0x00419f75`. The class page is `86/88` and emits through [UID:0000L7], so the direct class route clears the gate.
```

### [UID:0001BB] Destructor Rename / Route

Rename:

```text
from: by-memory/0x00516010-0x00516021.MemoryManGlobalResetTail.md
to:   by-memory/0x00516010-0x00516021.MemoryManDestructor.md
```

Recommended metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Title:

```markdown
# 0x00516010-0x00516021 MemoryMan Destructor
```

Add change note:

```markdown
- 2026-06-16 B001 source-split audit:
  - Renamed from `MemoryManGlobalResetTail` to `MemoryManDestructor`.
  - Changed route recommendation: owner/emitter should move from [UID:0000L7][MemoryMan](by-file/MemoryMan.md) to [UID:00007U][MemoryMan](by-class/MemoryMan.md).
  - Evidence: the atexit thunk loads the static `MemoryMan` object as `ecx` and jumps here; the body writes the `MemoryMan` vtable and clears `g_pMemoryMan`. That is the ordinary class destructor/reset body for the source-declared static object. The separate atexit thunk remains compiler/static-lifetime glue.
```

### [UID:0001BC], [UID:0001BH], [UID:0001BI]

Recommended score/source-placement updates:

```text
[UID:0001BC] COMPLETION:86 CONFIDENCE:90
[UID:0001BH] COMPLETION:86 CONFIDENCE:88
[UID:0001BI] COMPLETION:86 CONFIDENCE:88
```

Add note to [UID:0001BH] and [UID:0001BI]:

```markdown
- 2026-06-16 B001 source-split audit:
  - Source-placement blocker narrowed: keep this copy wrapper in the [UID:0000L7][MemoryMan](by-file/MemoryMan.md) utility family rather than moving it to a hypothetical CRT-wrapper source.
  - Evidence: the wrappers are embedded in the exact MemoryMan helper island, have broad project utility fanout, and no stronger source owner exists. They remain thin wrappers over CRT `memmove` variants, so final C++ is still blocked on exact public helper names and declaration style.
```

### [UID:000196] / [UID:000197] Operator Wrappers

Recommended metadata scores:

```text
[UID:000196] COMPLETION:85 CONFIDENCE:90
[UID:000197] COMPLETION:85 CONFIDENCE:90
```

Add note to both:

```markdown
- 2026-06-16 B001 source-split audit:
  - Source placement resolved to [UID:0000L7][MemoryMan](by-file/MemoryMan.md). These are source-level global `operator new` / `operator delete` implementations for the MemoryMan allocation policy, not independent recovered-global files.
  - Evidence: raw PE scan found `1785` rel32 calls to `0x004f4aa0` and `2129` rel32 calls to `0x004f4ac0`; IDA decompilation shows `operator new` calls `GetMemoryMan` then `AllocateBufferMemory`, while `operator delete` calls `GetMemoryMan` then `FreeBufferMemory`.
```

### [UID:0000WA] / [UID:0001O7]

Recommended score-only update:

```text
[UID:0000WA] COMPLETION:85 CONFIDENCE:90
[UID:0001O7] COMPLETION:85 CONFIDENCE:90
```

No owner/emitter route change. Both remain `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitter.

## Exact `by-memory/-ignored.md` Insert Text

Placement: insert after the existing `0x00515ff2-0x00516000` MD5-to-MemoryMan padding entry and before the existing `0x0051628e-0x00516290` MemoryMan-to-MenuPane padding entry. Do not duplicate the already-present `0x0051628e-0x00516290` entry.

```markdown
- Internal MemoryMan helper-island alignment spans `0x0051600f-0x00516010`, `0x00516021-0x00516030`, `0x00516036-0x00516040`, `0x00516045-0x00516050`, `0x005160ce-0x005160d0`, `0x00516162-0x00516170`, `0x00516184-0x00516190`, `0x00516210-0x00516220`, `0x00516238-0x00516240`, and `0x00516258-0x00516260` - alignment padding between exact MemoryMan helper children.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between exact MemoryMan constructor/destructor/accessor/allocation/copy/destructor children; not standalone source.
  - Evidence: 2026-06-16 B001 raw PE audit over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirms each listed span is all `0xcc`; IDA MCP confirms adjacent function or raw-stub boundaries.
  - Replacement/procurement: no source replacement; emit neighboring source children and let the compiler/linker regenerate alignment.
  - Owner docs: [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md), [UID:0000L7][MemoryMan](by-file/MemoryMan.md), and the exact neighboring child pages.

- `0x00516040-0x00516045` - MemoryMan island no-xref return-zero stub.
  - Why ignored: code-shaped five-byte `xor eax,eax; retn 4` body, but no source-use context is proven. It is not an IDA function, has no direct xrefs, and raw PE scanning finds no rel32 calls or absolute pointer hits to the entry.
  - Evidence: 2026-06-16 B001 IDA MCP `lookup_funcs 0x00516040` reports not a function; `disasm 0x00516040` decodes `xor eax,eax; retn 4`; `xrefs_to 0x00516040` reports zero refs; raw PE scan reports zero rel32/absolute-pointer hits.
  - Replacement/procurement: no source reconstruction unless future evidence proves a source-use context. If forced, [UID:0000L7][MemoryMan](by-file/MemoryMan.md) is the best candidate by adjacency only.
  - Owner docs: [UID:0003VP][0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub](by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md) and [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md).
```

## Exact `by-memory/-coverage-report.md` Replacement Text

Placement A: replace the current [UID:000196]/[UID:000197] rows after [UID:000373] and before [UID:000199]:

```markdown
    - [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) 0x004f4aa0-0x004f4ab4 | global operator | operator new / OperatorNewWrapper : reconstructable : 85% : strong : MemoryMan-backed global `operator new`; B001 2026-06-16 confirms source placement in [UID:0000L7][MemoryMan](by-file/MemoryMan.md), exact boundary, `GetMemoryMan` -> `AllocateBufferMemory` callees, raw PE count of `1785` rel32 callers, and final C++ still blank pending final operator declaration style.
    - [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) 0x004f4ac0-0x004f4b00 | global operator | operator delete / OperatorDeleteWrapper : reconstructable : 85% : strong : MemoryMan-backed global `operator delete`; B001 2026-06-16 confirms source placement in [UID:0000L7][MemoryMan](by-file/MemoryMan.md), exact boundary, `GetMemoryMan` -> `FreeBufferMemory` callees, local EH/security-cookie scaffold, raw PE count of `2129` rel32 callers, and final C++ still blank pending final operator declaration style.
```

Placement B: replace the [UID:0000WA] row after [UID:0000W9]:

```markdown
    - [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md) : ignored : 85% : strong : IDA-confirmed MemoryMan static-object initializer and `atexit` registration wrapper; B001 2026-06-16 reconfirms startup-table ref `0x0060d6b4`, constructor target `0x00516000`, atexit target `0x0060c260`, static storage `0x0069b3a8`, and standalone-source exclusion. Regenerate from the source-level static `MemoryMan` object.
```

Placement C: replace the current [UID:0001BA] parent and same-level child rows from [UID:0001BA] through the existing `0x0051628e-0x00516290` padding row:

```markdown
    - [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md) 0x00516000-0x0051628e | split-index | MemoryManAndAllocationHelpers : ignored/non-emitting : 88% : strong : B001 2026-06-16 reclassifies this broad MemoryMan helper island as a reviewed non-emitting split index. Exact children carry MemoryMan class methods, file-level allocation/copy helpers, an ignored no-xref return-zero stub, and internal padding; parent C++ remains blank.
        - [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) 0x00516000-0x0051600f | constructor | MemoryManConstructor : reconstructable : 86% : strong : Exact `MemoryMan` constructor; B001 2026-06-16 recommends direct class owner/emitter [UID:00007U][MemoryMan](by-class/MemoryMan.md) after IDA/PE evidence reconfirmed vtable store `0x0061eb08`, `g_pMemoryMan` publication, static initializer caller `0x00419f75`, and surrounding padding.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051600f-0x00516010 | padding | MemoryMan constructor to destructor alignment : ignored : 100% : strong : B001 raw PE audit shows one `0xcc` byte.
        - [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md) 0x00516010-0x00516021 | destructor | MemoryManDestructor : reconstructable : 86% : strong : Rename/reclassify old `MemoryManGlobalResetTail` as the ordinary `MemoryMan` destructor/reset body; B001 2026-06-16 recommends direct class owner/emitter [UID:00007U][MemoryMan](by-class/MemoryMan.md) because the atexit thunk loads static `MemoryMan` storage as `ecx` and jumps here to restore the vtable and clear `g_pMemoryMan`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00516021-0x00516030 | padding | MemoryMan destructor to accessor alignment : ignored : 100% : strong : B001 raw PE audit shows fifteen `0xcc` bytes.
        - [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) 0x00516030-0x00516036 | singleton accessor | GetMemoryMan : reconstructable : 86% : strong : MemoryMan singleton accessor; B001 2026-06-16 raw PE scan found `612` rel32 callers and IDA decompilation confirms direct return of `g_pMemoryMan`. Keep owner/emitter [UID:0000L7][MemoryMan](by-file/MemoryMan.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00516036-0x00516040 | padding | GetMemoryMan to no-xref return-zero stub alignment : ignored : 100% : strong : B001 raw PE audit shows ten `0xcc` bytes.
        - [UID:0003VP][0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub](by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md) 0x00516040-0x00516045 | no-xref stub | MemoryManNoXrefReturnZeroStub : ignored : 85% : strong : Exact five-byte `xor eax,eax; retn 4` body inside the MemoryMan helper island; IDA has no function object, `xrefs_to` reports zero refs, raw PE rel32/absolute pointer scan finds zero entry refs, and no source-use context is proven. Keep non-reconstructable/non-emitting.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00516045-0x00516050 | padding | no-xref return-zero stub to allocation helper alignment : ignored : 100% : strong : B001 raw PE audit shows eleven `0xcc` bytes.
        - [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md) 0x00516050-0x005160ce | allocation helper | AllocateBufferMemory : reconstructable : 85% : strong : MemoryMan allocation helper; IDA confirms `malloc(size)` success path and `Win32Error` throw path, and B001 raw PE scan found `132` rel32 callers. Keep owner/emitter [UID:0000L7][MemoryMan](by-file/MemoryMan.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005160ce-0x005160d0 | padding | AllocateBufferMemory to zero-allocation helper alignment : ignored : 100% : strong : B001 raw PE audit shows two `0xcc` bytes.
        - [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md) 0x005160d0-0x00516162 | zero-fill allocation helper | ZeroAllocateBufferMemory : reconstructable : 85% : strong : MemoryMan zero-fill allocation helper; IDA confirms `malloc`, `memset(block, 0, size)`, and matching `Win32Error` throw path, and B001 raw PE scan found `13` rel32 callers. Keep owner/emitter [UID:0000L7][MemoryMan](by-file/MemoryMan.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00516162-0x00516170 | padding | zero-allocation helper to free helper alignment : ignored : 100% : strong : B001 raw PE audit shows fourteen `0xcc` bytes.
        - [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md) 0x00516170-0x00516184 | deallocation helper | FreeBufferMemory : reconstructable : 85% : strong : MemoryMan deallocation helper; IDA confirms `free(block); return 0`, operator-delete relationship, and B001 raw PE scan found `210` rel32 callers. Keep owner/emitter [UID:0000L7][MemoryMan](by-file/MemoryMan.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00516184-0x00516190 | padding | free helper to realloc helper alignment : ignored : 100% : strong : B001 raw PE audit shows twelve `0xcc` bytes.
        - [UID:0001BG][0x00516190-0x00516210.ReallocateOrThrow](by-memory/0x00516190-0x00516210.ReallocateOrThrow.md) 0x00516190-0x00516210 | allocation helper | ReallocateOrThrow : reconstructable : 85% : strong : MemoryMan realloc helper; IDA confirms `realloc` success path and matching `Win32Error` throw path, and B001 raw PE scan found `10` rel32 callers. Keep owner/emitter [UID:0000L7][MemoryMan](by-file/MemoryMan.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00516210-0x00516220 | padding | realloc helper to memmove wrapper alignment : ignored : 100% : strong : B001 raw PE audit shows sixteen `0xcc` bytes.
        - [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) 0x00516220-0x00516238 | copy helper | MemmoveWrapper : reconstructable : 86% : strong : Thin MemoryMan-island `_memmove` wrapper; B001 2026-06-16 resolves source placement to [UID:0000L7][MemoryMan](by-file/MemoryMan.md), confirms exact one-basic-block body, and raw PE scan found `604` rel32 callers. Final helper name remains a C++ blocker.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00516238-0x00516240 | padding | memmove wrapper to alternate memmove wrapper alignment : ignored : 100% : strong : B001 raw PE audit shows eight `0xcc` bytes.
        - [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) 0x00516240-0x00516258 | copy helper | Memmove0Wrapper : reconstructable : 86% : strong : Thin MemoryMan-island `_memmove_0` wrapper; B001 2026-06-16 resolves source placement to [UID:0000L7][MemoryMan](by-file/MemoryMan.md), confirms exact one-basic-block body, and raw PE scan found `19` rel32 callers. Final helper name remains a C++ blocker.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00516258-0x00516260 | padding | alternate memmove wrapper to scalar deleting destructor alignment : ignored : 100% : strong : B001 raw PE audit shows eight `0xcc` bytes.
        - [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) 0x00516260-0x0051628e | scalar deleting destructor | MemoryManScalarDeletingDestructor : reconstructable : 86% : strong : MemoryMan class vtable-slot scalar deleting destructor; IDA confirms vtable slot `0x0061eb08`, vtable reset, `g_pMemoryMan` clear, conditional delete flag path, and class owner/emitter route through [UID:00007U][MemoryMan](by-class/MemoryMan.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051628e-0x00516290 | padding | MemoryMan to MenuPane alignment : ignored : 100% : strong : Confirmed two `0xcc` alignment bytes between adjacent IDA functions.
```

Placement D: replace the [UID:0001O7] row after [UID:00024F]:

```markdown
    - [UID:0001O7][0x0060c260-0x0060c26a.MemoryManAtexitResetThunk](by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md) 0x0060c260-0x0060c26a | compiler/static cleanup thunk | MemoryManAtexitResetThunk : ignored : 85% : strong : Live IDA confirms the atexit thunk, static object reference, jump to the ordinary MemoryMan destructor/reset body, sole registration xref from `0x00419f7a`, and post-thunk padding; regenerate it from the source-level static `MemoryMan` object.
```

## Exact Support-Doc Edits

### `by-file/MemoryMan.md`

Update `Proposed Contents` rows:

```markdown
| `MemoryMan` constructor/destructor | [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md), [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md), [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) | Exact class-owned MemoryMan lifecycle bodies; emit through [UID:00007U][MemoryMan](by-class/MemoryMan.md). |
| no-xref return-zero stub | [UID:0003VP][0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub](by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md) | Ignored/non-emitting; no function object, xrefs, rel32 calls, or absolute pointer hits. |
```

Add change note:

```markdown
- 2026-06-16 B001 source-split audit:
  - Reclassifies [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md) as a non-emitting split index.
  - Constructor/destructor/scalar-deleting destructor route through [UID:00007U][MemoryMan](by-class/MemoryMan.md); global operators, allocation helpers, copy wrappers, `g_pMemoryMan`, and static object declarations remain in this file family.
  - Internal `0xcc` gaps and the no-xref return-zero stub are excluded from source emission.
```

### `by-class/MemoryMan.md`

Update `Method Map`:

```markdown
| [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) | constructor | reconstructable child | Installs `MemoryMan` vtable and stores `this` into `g_pMemoryMan`; direct owner/emitter should be this class. |
| [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md) | ordinary destructor/reset body | reconstructable child | Reinstalls vtable and clears `g_pMemoryMan`; reached from the compiler atexit thunk for static object cleanup. |
| [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) | scalar deleting destructor | reconstructable child | Vtable-slot deleting destructor; clears `g_pMemoryMan` and conditionally frees `this`. |
```

### `by-global/MemoryAllocationHelpers.md`

Add source-split note:

```markdown
2026-06-16 B001 source-split audit resolves the helper/API placement for current documentation purposes: keep `operator new`, `operator delete`, `GetMemoryMan`, allocation/free/realloc helpers, and the two `memmove` wrappers with [UID:0000L7][MemoryMan](by-file/MemoryMan.md). Do not create a separate CRT-wrapper source unless future original-source metadata proves it. The no-xref return-zero stub [UID:0003VP][0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub](by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md) is excluded from this helper family because no source-use context is proven.
```

### `by-global/g_pMemoryMan.md`

No required route change. Optional wording update:

```markdown
- [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md) is the ordinary MemoryMan destructor/reset body reached from the atexit thunk; it clears `g_pMemoryMan`.
```

### `by-type/by-struct/MemoryManLayout.md`

No required route change. Optional wording update:

```markdown
- B001 2026-06-16 source-split audit confirms the constructor and ordinary destructor should route through [UID:00007U][MemoryMan](by-class/MemoryMan.md); `0x00516040-0x00516045` is an ignored no-xref stub and does not imply an extra `MemoryMan` field or method.
```

## Validation Order For Supervisor

Run after applying the docs and shared rows:

> Executable block R001 was removed from this report and preserved verbatim in [0001BA-memoryman-allocation-source-split-removed.md](0001BA-memoryman-allocation-source-split-removed.md). The archived block is non-authoritative and must not be executed.

If the rename from `MemoryManGlobalResetTail` to `MemoryManDestructor` leaves a stale UID path, run the validator missing-entry cleanup per `by-structure.md` guidance.

## Follow-Up Actions

- Supervisor actions:
  - Allocate [UID:0003VP] or the next available UID for the no-xref stub page.
  - Apply the exact child page, metadata, support-doc, ignored-ledger, and coverage-report updates above.
  - Validate in the order above.
- A-agent actions:
  - After supervisor application, A/C agents can continue source-quality work on final helper names and C++ only from the exact child pages, not from the parent aggregate.
- B001 future research:
  - Only needed if future evidence appears for `0x00516040-0x00516045` reachability or a separate CRT-wrapper source file.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `88/90` parent split-index and `85/85+` reconstructable child routing; medium-high for final public helper names.
- Remaining uncertainty: exact original names for zero-allocation/reallocation/copy helpers; exact static object variable spelling; final C++ header factoring; whether the unused return-zero stub had an original dead source declaration.

## Validator Results

- Commands run by B001: no validator commands that modify docs; this was report-only.
- Local report checks run by B001:
  - `git diff --check -- tools/leaser/Agents/Agent-B001/research/0001BA-memoryman-allocation-source-split.md` passed.
  - Targeted placeholder scan passed for UID placeholders and unfinished-note markers.
  - Public-doc/report scan found no `0003VP` use outside this MemoryMan report at the time of writing; [UID:0003VF]-[UID:0003VO] are already proposed by the current B001 ArgumentedMenu report, so this report assumes [UID:0003VP].
- IDA DB edits: none.

## Changed Files

- Created by B001: `tools/leaser/Agents/Agent-B001/research/0001BA-memoryman-allocation-source-split.md`
- Modified by B001: none outside the B001 research folder.
- Leases acquired: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001BA-memoryman-allocation-source-split.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001BA"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001BA-memoryman-allocation-source-split-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001BA-memoryman-allocation-source-split.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001BA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
