** TARGET-REPORT-UID:0001J4 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001J4 SimpleUStringVectorPushBack Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: reroute [UID:0001J4] from direct [UID:0000OB] `StringUtil` ownership to direct [UID:0000DA] `SimpleUStringVector` ownership and emission. [UID:0000OB] should remain the source-family/file route because [UID:0000DA] itself emits through `StringUtil`.
- Final disposition: single exact reconstructable source-authored class method; no split or rename required.
- Required action: update target metadata to `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000DA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DA`, blank `EMITTER_POSITION_OPTIONAL`, and blank final C++.
- Confidence: high for behavior, range, caller/callee facts, direct class ownership, and source-authored/compiler-boundary classification; medium-high for exact original API spelling.

## Supporting Research

## Target

- Target UID: [UID:0001J4]
- Target path: `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md`
- Assignment: `B001-goal2-simple-ustring-vector-pushback-source-quality-0001J4-20260617`
- Source queue/report row: Agent-B001 `notes.md` 2026-06-17 assignment `0001J4`; `project-level/-auto-completion-stats.md` lists `0001J4` at `82/88`.
- Current supervisor classification: B-preferred source-quality/source-placement audit after [UID:00012G] `SimpleUStringVectorGrowAndInsert` was rerouted to [UID:0000DA].
- Current scores and parent state: target is `82/88`, `CANONICAL_OWNER:0000OB`, `EMITTER_UIDS:0000OB`, `RECONSTRUCTABLE:TRUE`, final C++ blank.

## Executive Recommendation

The direct semantic owner should be [UID:0000DA] `SimpleUStringVector`, not direct [UID:0000OB] `StringUtil`. The function reads and writes the vector triplet at `this+0x04` and `this+0x08`, constructs exactly one 4-byte pointer-backed wide string-handle slot at `end`, advances `end` by four, and delegates to [UID:00012G] `SimpleUStringVectorGrowAndInsert` when capacity is full. This is the same class-owned vector method pattern already accepted for [UID:000112] destructor and [UID:00012G] grow/insert.

`StringUtil` remains the correct file/source-family route because [UID:0000DA] is a utility string class owned and emitted through [UID:0000OB]. No new `SimpleUStringVector.cpp` file is justified from current evidence.

## Supervisor Active Recheck

- Supervisor instruction rechecked: produce only `tools/leaser/Agents/Agent-B001/research/0001J4-simple-ustring-vector-pushback-source-quality.md`; do not directly edit by-* docs, generated reports, source files, IDA DB, generated source, or `by-memory/-coverage-report.md`.
- Split repair: not required. [UID:0001J4] is already an exact IDA function child. The predecessor and successor padding are separate ignored spans.
- Source-bearing child scope: the target remains one source-bearing child; no additional child pages are needed.

## Inference Research Guidance Check

`by-structure.md` requires `CANONICAL_OWNER` to use the narrowest true semantic owner, not just the final source file. That rule is decisive here: `SimpleUStringVector` is now a documented class page at `85/88`, owns the layout [UID:0001W6], owns the destructor [UID:000112], and now owns grow/insert [UID:00012G] at `86/90`. Direct [UID:0000OB] ownership would keep the file route but bypass the narrower class owner.

`inference_research.md` guidance was applied by separating IDA facts from source-layout inference. Caller xrefs from StringBase code are consumer evidence, not ownership proof. Physical adjacency inside the StringBase helper island is also not ownership proof because the exact function uses only the vector triplet and was already split out from the mixed aggregate.

## Heuristic / Inference Reanalysis And Validation

### Direct owner and source route

- Best defensible direction: `SimpleUStringVector::PushBack` is a direct method of [UID:0000DA] `SimpleUStringVector`, emitted through [UID:0000DA] so the class-to-file route reaches [UID:0000OB] `StringUtil`.
- Evidence checked: live IDA `lookup_funcs`, `decompile`, `disasm`, `xref_query`, `callees`, and `get_bytes` on 2026-06-17; support docs for [UID:0000DA], [UID:0000OB], [UID:0001W6], [UID:00012G], and StringBase aggregates.
- Why accepted: target body uses `this[1]` and `this[2]` as `end` and `capacity`, stores into the slot at `end`, increments `end` by `4`, and calls class sibling [UID:00012G] on growth.
- Rejected alternative: direct [UID:0000OB] ownership. `StringUtil` is the correct file/source-family context but is too broad for `CANONICAL_OWNER` after the class page clears the gate.
- Rejected alternative: [UID:0000OA] `StringBase` direct ownership. The only StringBase relationship is caller/dependency context; the method is not a StringBase mutation method.
- Score/source impact: supports raising target to `86/90` and changing owner/emitter to `0000DA`.

### Source-facing method and type names

- Best method name: `SimpleUStringVector::PushBack`. `push_back` is plausible in STL style, but existing recovered project docs and companion vector helper naming use `PushBack`, and no symbols prove lowercase original spelling.
- Best descriptive signature direction: `void SimpleUStringVector::PushBack(const WideStringHandle &value)` or `const SimpleUString-like pointer-backed handle &value`. The binary-level argument is a pointer to a 4-byte handle slot (`const void **` in IDA), not an inline 24-byte SSO object.
- Rejected type alternative: inline `SimpleUString` SSO-7 / 24-byte element storage. The function increments `end` by four and the slow path computes element counts with pointer differences shifted by two.
- Rejected name alternative: `Append`. Behavior is append-only, but companion docs and the old source-facing lead use `PushBack`; `Append` would be a new descriptive rename with no added evidence.
- Final-C++ impact: final code should not be emitted until the project settles the exact public handle type name and the `SimpleUString` versus `StringBase<wchar_t>` facade split.

### Fast-path string-handle semantics

- Best inference: the fast path copy-constructs one pointer-backed UTF-16 string handle in the destination slot. It shares the source buffer when the source header refcount/state is non-negative and source is not the shared empty sentinel; it writes the shared empty sentinel unchanged when the source is `Src` at `0x00670278`; it private-copies the source buffer when the source header state is negative and the source is not the sentinel.
- Evidence checked: `sub_584910` decompile and disassembly; `sub_582A90` decompile for the same share-or-copy constructor pattern; `sub_584BA0`, `sub_582E30`, and `sub_5833A0` decompilation for wide allocation, ensure-capacity, and release behavior.
- Key IDA facts: `0x00584925` tests `[source-0x0c]`; `0x00584938` calls `InterlockedIncrement(source-0x0c)`; `0x00584944` stores the chosen pointer to `[end]`; `0x00584954` reads length from `[source-0x08]`; `0x0058495a` calls `sub_584BA0` on the destination slot; `0x0058496a` copies `2 * length` bytes by `memmove`.
- Rejected alternative: raw pointer append without ownership management. The refcount increment and private-copy branch prove copy-construction semantics.
- Rejected alternative: deep-copy always. The refcount increment branch shares when allowed.
- Rejected alternative: refcount-only share always. The negative-header branch allocates/copies privately.
- Score impact: this resolves the prior semantic uncertainty enough for `86/90`.

### Slow-path delegation

- Best inference: when `end == capacity`, the method delegates to [UID:00012G] `SimpleUStringVector::GrowAndInsert(this, end, value)`.
- Evidence checked: target disassembly at `0x0058497d-0x00584981`; `xref_query` to `0x0049cc40`; [UID:00012G] target/support docs; live decompile of `sub_49CC40`.
- Key IDA facts: target starts with `mov edi, [ebx+4]` and `cmp [ebx+8], edi`; the full case pushes the incoming value handle, pushes `edi` as insertion position, and calls `sub_49CC40` with `ecx` still holding the vector object. `xref_query` reports the slow-path xref at `0x00584981`.
- Rejected alternative: direct allocation inside `PushBack` for growth. Allocation/growth policy lives in `sub_49CC40`; `PushBack` only handles in-capacity construction.
- Score/source impact: reinforces class ownership because the only internal class edge is `PushBack -> GrowAndInsert`.

### Caller and reachability context

- Best inference: the two direct callers are append sites in StringBase wide replace/mutation helper `sub_5839C0`, which builds temporary wide handles and pushes them into a temporary `SimpleUStringVector`.
- Evidence checked: `xref_query` to `0x00584910`; decompile and disassembly of `sub_5839C0` around both call sites.
- Key IDA facts: xrefs to `sub_584910` are exactly `0x00583ddb` and `0x00583e3d`, both inside `sub_5839C0`. At both sites the caller sets `ecx` to `edi` (the vector receiver), pushes the address of the temporary wide string handle, calls `sub_584910`, and then releases the temporary through `sub_5833A0`.
- Rejected alternative: no-route or dead retained helper. The two code xrefs are ordinary direct calls.
- Rejected alternative: StringBase ownership from caller locality. The caller is a consumer of the vector method; it does not make the vector method a StringBase method.
- Final-C++ impact: caller context supports the behavioral name but does not resolve final public API names.

### Compiler/runtime boundary

- Best classification: source-authored NexusTK utility class method with compiler-generated prologue/epilogue and external runtime dependencies.
- Source-authored parts: capacity comparison, handle copy/share/private-copy branch, slot write, `end += 4`, and slow delegation to the class grow/insert method.
- Compiler/runtime/dependency parts: `InterlockedIncrement`, CRT `memmove`, string buffer allocation/release helpers, and `0xcc` alignment padding. `sub_584BA0` contains C++ EH/security-cookie scaffolding, but its wide-string ensure-capacity behavior is source-level StringBase support.
- Rejected alternative: pure STL/runtime vector append. The code uses project string sentinels/pools and the project-specific `SimpleUStringVector` triplet.
- Rejected alternative: compiler-generated thunk. The body has real branch/copy/allocation behavior and direct callers.

### Range and padding

- Best range decision: keep the target filename/display range `0x00584910-0x0058498b`; document the half-open IDA function body as `0x00584910-0x0058498c`.
- Evidence checked: `lookup_funcs 0x00584910` returns `sub_584910` size `0x7c`; `get_bytes 0x0058498c size 8` returns four `0xcc` bytes followed by the next prologue at `0x00584990`.
- Predecessor padding: `get_bytes 0x0058490f` shows a single `0xcc` before the function start.
- Successor padding: `0x0058498c-0x00584990` is four `0xcc` alignment bytes.
- Rejected alternative: extend into `0x00584990`. That is the next StringBase splice/grow helper, not part of the vector push-back method.

## Evidence Standards Used

- Direct IDA facts: `lookup_funcs`, `decompile`, `disasm`, `xref_query`, `callees`, and `get_bytes` from MCP session `b002_00011G_scrollable_control_20260616` on 2026-06-17.
- Documentation evidence: current target page, [UID:0000DA] `SimpleUStringVector`, [UID:0000OB] `StringUtil`, [UID:0001W6] layout, [UID:00012G] grow/insert, [UID:0000OA] `StringBase`, and exact StringBase helper/container pages.
- Negative evidence: caller locality and physical adjacency were checked but rejected as direct ownership proof.
- Strength: enough for ownership/score update; not enough for final C++ because exact original type/API spellings remain inferred.

## IDA MCP Facts

- Function/range facts:
  - `lookup_funcs 0x00584910`: `sub_584910`, size `0x7c`; last executable byte `0x0058498b`, half-open end `0x0058498c`.
  - `lookup_funcs 0x005839c0`: `sub_5839C0`, size `0x4a5`.
  - `lookup_funcs 0x0049cc40`: `sub_49CC40`, size `0x209`.
  - `lookup_funcs 0x00584ba0`: `sub_584BA0`, size `0x91`.
- Data/table/padding facts:
  - `get_bytes 0x0058490f` begins with `0xcc` then the `sub_584910` prologue.
  - `get_bytes 0x0058498c size 8`: `0xcc 0xcc 0xcc 0xcc 0x55 0x8b 0xec 0x6a`; four successor padding bytes then `sub_584990`.
- Xref facts:
  - `xref_query` to `0x00584910`: two code xrefs, `0x00583ddb` and `0x00583e3d`, both in `sub_5839C0`.
  - `xref_query` to `0x0049cc40`: seven code xrefs, including `0x00584981` from `sub_584910`.
- Callee facts:
  - `sub_584910` calls `InterlockedIncrement`, `sub_584BA0`, `_memmove`, and `sub_49CC40`.
  - `sub_584BA0` calls `sub_582E30`, `_memmove`, and `sub_5833A0`.
  - `sub_582A90` has the same share-or-copy constructor semantics used by grow/insert range-copy helpers.
- Negative IDA facts:
  - `0x0058498c` is not a function.
  - No data/vtable evidence ties this method to a new standalone file or to StringBase as a class owner.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00584910-0x0058498b` | [UID:0001J4] `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md` | one-slot vector append with slow grow/insert delegation | TRUE | recommend [UID:0000DA] | recommend `86/90` | update metadata/evidence |
| `0x0058498c-0x00584990` | [UID:0000VN] `by-memory/-ignored.md` | four-byte successor alignment | FALSE | none | `100/strong` | no change |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00583ddb` | direct call to `sub_584910` from `sub_5839C0` | final/tail segment append in StringBase wide replace worker; caller sets `ecx=edi` vector receiver and pushes temporary handle address |
| `0x00583e3d` | direct call to `sub_584910` from `sub_5839C0` | no-first-match or trailing append case in the same replace worker; caller releases temporary handle afterward |
| `0x00584981` | direct call from `sub_584910` to `sub_49CC40` | slow path when `end == capacity`; inserts at current `end` |
| `0x00584938` | call to `InterlockedIncrement` | shared-buffer fast path for non-sentinel shareable source |
| `0x0058495a` | call to `sub_584BA0` | private-copy/ensure-capacity branch for non-shareable source |
| `0x0058496a` | call to `_memmove` | copies `2 * length` UTF-16 bytes into newly ensured destination buffer |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:0000DA] `SimpleUStringVector` now lists destructor, grow/insert, and push-back, and records class ownership for [UID:00012G].
  - [UID:0001W6] `SimpleUStringVectorLayout` states the `begin/end/capacity` triplet and 4-byte string-handle slot model.
  - [UID:00012G] `SimpleUStringVectorGrowAndInsert` is already rerouted to [UID:0000DA] with [UID:0000OB] as source-family route.
  - [UID:0000OB] `StringUtil` explicitly says exact `SimpleUStringVector` method children should route through [UID:0000DA] where a class parent exists.
- Existing docs that are stale or incomplete:
  - Target [UID:0001J4] still has `CANONICAL_OWNER:0000OB` and `EMITTER_UIDS:0000OB`.
  - `by-memory/-coverage-report.md` row still says the method is attached to `StringUtil`.
  - Some StringBase aggregate text still describes [UID:0001J4] as routing to [UID:0000OB] directly; that should become "direct [UID:0000DA], source route [UID:0000OB]".
- Generated/coverage state:
  - `auto-generated/-ag-memory-coverage.md` currently routes [UID:0001J4] directly through `0000OB`.
  - `project-level/-auto-completion-stats.md` still lists [UID:0001J4] at `82/88`.

## Ranked Ownership Analysis

### 1. [UID:0000DA] SimpleUStringVector

- Evidence for: target uses vector triplet fields, appends exactly one 4-byte slot, calls class sibling [UID:00012G] on growth, and matches [UID:0001W6] layout evidence. The class parent clears `85/85`.
- Evidence against: original public method spelling is not proven; final source could have placed the implementation in a flatter utility source file.
- Decision: accepted as direct owner and emitter.

### 2. [UID:0000OB] StringUtil

- Evidence for: the vector class belongs to the StringUtil utility string family, `StringUtil` is projected to `NexusTK/util/StringUtil.cpp`, and [UID:0000DA] emits through [UID:0000OB].
- Evidence against: by-structure says the class is the narrower direct semantic owner. Direct file ownership would be stale after the destructor and grow/insert class reroutes.
- Decision: keep as source-family/file route only, not direct owner.

### 3. [UID:0000OA] StringBase

- Evidence for: both observed direct callers are in a StringBase wide replace worker, and the method uses StringBase wide-handle allocation/refcount helpers.
- Evidence against: caller/dependency evidence is not ownership proof; target body operates on a vector object, not a StringBase object. Existing mixed StringBase containers deliberately split [UID:0001J4] out as a separate vector child.
- Decision: rejected as direct owner.

### 4. New `util/SimpleUStringVector.cpp` file

- Evidence for: if future original-source evidence proves a narrower file split, the likely file contents would be the destructor [UID:000112], grow/insert [UID:00012G], push-back [UID:0001J4], and layout/type declarations [UID:0001W6].
- Evidence against: no debug/source path, string literal, object-file marker, or caller/source-tree evidence proves a standalone file. Current proposed source tree and support docs intentionally keep the string utility family under `StringUtil.cpp` with class-level ownership.
- Decision: not recommended now. This remains a plausible future split only if stronger original-source evidence appears.

## Negative Evidence Summary

- The two direct caller sites in `sub_5839C0` prove reachability but not StringBase ownership.
- Physical location between StringBase search and splice/grow helpers is not source ownership proof; exact child splits already isolate the vector method and surrounding `0xcc` padding.
- The shared empty wide sentinel `Src` at `0x00670278`, `InterlockedIncrement`, `sub_582E30`, `sub_5833A0`, and `sub_584BA0` are dependencies of the element handle implementation, not owners of the vector method.
- No current IDA symbol, PDB/source path, or string evidence proves a standalone `SimpleUStringVector.cpp` file.

## Final Recommendation

- Exact metadata changes recommended for target [UID:0001J4]:
  - `COMPLETION:86`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:0000DA`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000DA`
  - `EMITTER_POSITION_OPTIONAL:` blank
  - `RECONSTRUCTION_CPP CODE` remains blank
- Exact source-facing state:
  - Keep current page/file name `SimpleUStringVectorPushBack`.
  - Document source-facing method as `SimpleUStringVector::PushBack`, descriptive rather than proven original.
  - Document argument as a pointer-backed wide string-handle reference, not inline 24-byte `SimpleUString` SSO storage.
- Exact final-C++ state:
  - Keep blank. Although the recommended score/emitter route clears the minimum combined-score gate, final code remains blocked by unsettled public type names, `SimpleUString`/`StringBase` facade split, and helper-wrapper policy for refcount/private-copy operations.

## Follow-Up Actions

- Supervisor actions:
  - Apply target metadata/evidence update if accepted.
  - Replace the [UID:0001J4] row in `by-memory/-coverage-report.md` with the text below.
  - Run scoped validation and memory report refresh after applying by-* changes.
- A-agent actions:
  - Update [UID:0000DA] `SimpleUStringVector` with a short change note that [UID:0001J4] now routes through the class.
  - Update [UID:0000OB] `StringUtil` only if needed to record [UID:0001J4] alongside the already-rerouted [UID:00012G].
  - Update StringBase aggregate/container text that still says [UID:0001J4] routes directly to `StringUtil`; preferred wording is "direct [UID:0000DA] `SimpleUStringVector`, source route [UID:0000OB] `StringUtil`."
- B001 future research actions:
  - None required for this target unless a later source-tree split audit revisits `StringUtil.cpp` versus a new `SimpleUStringVector.cpp`.

## Exact Supervisor-Owned Coverage Row

Placement context: replace the existing [UID:0001J4] row in `by-memory/-coverage-report.md`, keeping it between [UID:0002RR] / surrounding `0x005845f0+` rows and the existing padding row for `0x0058498c-0x00584990`.

Old row:

```text
    - [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md) 0x00584910-0x0058498b | function | SimpleUStringVectorPushBack : reconstructable : 82% : strong : Appends one pointer-backed string-handle slot or delegates to grow/insert when capacity is full, and is attached to StringUtil.
```

Replacement row:

```text
    - [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md) 0x00584910-0x0058498c | method | SimpleUStringVectorPushBack : reconstructable : 86% : strong : Direct method of [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md), emitting through [UID:0000OB][StringUtil](by-file/StringUtil.md); IDA confirms the half-open body `0x00584910-0x0058498c`, `+0x04/+0x08` vector end/capacity fields, 4-byte pointer-backed wide string-handle slot append, share/refcount and private-copy fast paths, slow-path delegation to [UID:00012G][SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md), two caller xrefs from the StringBase replace worker, and four-byte successor alignment.
```

The existing padding row can remain unchanged:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0058498c-0x00584990 | padding | SimpleUStringVectorPushBack alignment : ignored : 100% : strong : IDA byte check shows four `0xcc` alignment bytes.
```

## Validation Commands

Recommended after supervisor/A-agent applies by-* updates:

> Executable block R001 was removed from this report and preserved verbatim in [0001J4-simple-ustring-vector-pushback-source-quality-removed.md](0001J4-simple-ustring-vector-pushback-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If StringBase aggregate/container wording is also updated, validate those edited files individually:

> Executable block R002 was removed from this report and preserved verbatim in [0001J4-simple-ustring-vector-pushback-source-quality-removed.md](0001J4-simple-ustring-vector-pushback-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Confidence

- Recommendation confidence: high. Direct class ownership follows the already-accepted destructor/grow/insert route and current by-structure rules.
- Score confidence: high for `86/90`. Completion should not go higher until final source declarations and helper wrapper policy are settled.
- Remaining uncertainty: original spelling of `PushBack` versus `push_back`, exact public element type name, and whether future source-tree evidence justifies a `SimpleUStringVector.cpp` split.

## Validator Results

- Commands run by B001: no validator commands were run because this assignment was report-only and no by-* documentation was edited.
- Read-only commands/evidence used: PowerShell `Get-Content`, `Select-String`, `rg`, `git status --short` for this report path, and IDA MCP `lookup_funcs`, `decompile`, `disasm`, `xref_query`, `callees`, and `get_bytes`.
- Unresolved validator warnings/errors: none observed because no validator pass was executed.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0001J4-simple-ustring-vector-pushback-source-quality.md`
- Modified: none
- Renamed: none
- Moved to executed: none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001J4-simple-ustring-vector-pushback-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001J4"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001J4-simple-ustring-vector-pushback-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001J4-simple-ustring-vector-pushback-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001J4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
