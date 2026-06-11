# 00022J WideStringHashHelper Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00022J] parent-blank. The child is now repaired to `COMPLETION:85`, `CONFIDENCE:88`, but no direct owner is proven.
- Final disposition: reconstructable retained source-authored wide-string hash helper, unresolved direct source parent.
- Required action: no assignment to StringUtil, CachedHashTable, RectBounds, PathUtil, FieldMapPane, or GeneralPurposePanel until a direct caller, table entry, raw pointer, import/name artifact, or source-family evidence ties `0x004b81a0` to that owner.
- Confidence: high for exact bytes, boundaries, algorithm, side-effect profile, and no-reference state; medium for original source ownership because the binary exposes no reachability path.

## Supporting Research

## Target

- Target UID: `00022J`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004b81a0-0x004b81eb.WideStringHashHelper.md`
- Source queue/report row: Supervisor B001-031 assignment; Batch 118 had raised the child from `82/84` to `83/85` but left it unassigned because no live xref/callback/raw pointer path was proven.
- Current supervisor classification: `reviewed-no-85-under-review`
- Current scores and parent state after this pass: `COMPLETION:85`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:` blank.

## Executive Recommendation

The target should remain a single exact `by-memory` child and should not be assigned. The behavior is strong enough to repair the child itself to `85/88`: it is a bounded raw helper that hashes a NUL-terminated UTF-16 string using a unique decimal `1000003` multiply/XOR recurrence, has no calls or globals, and is surrounded by verified `0xcc` padding. The strict parent gate still blocks assignment because IDA exposes no function object, caller, xref, VA/RVA pointer, vtable slot, callback table, or source-family link for `0x004b81a0`.

Best semantic candidate is `StringUtil`, but behavior-only string affinity is not a direct owner link. The exact condition for any future assignment is a new reachability or source-layout artifact that distinguishes StringUtil or another source parent from a retained unreferenced/external-style helper.

## Supervisor Active Recheck

- Rechecked the assigned B001-031 item only.
- No split repair was needed: `0x004b81a0-0x004b81eb` is one prologue/epilogue-bounded body with exact padding before and after.
- No additional child pages were created. The one in-scope source-bearing child was repaired and validated.

## Inference Research Guidance Check

- `by-structure.md` strict assignment rules require both child and direct parent to clear `85/85` and require a defensible direct owner. The child now clears the child gate, but direct ownership remains unresolved.
- `inference_research.md` supports making a ranked best inference instead of stopping at generic uncertainty. The ranked result is: retained unreferenced helper as final disposition, StringUtil as best candidate parent, all other candidates rejected or blocked.
- Existing documentation was treated as evidence, not authority. Neighbor pages prove a mixed address neighborhood and explicitly warn against proximity ownership.

## Evidence Standards Used

- IDA MCP: `idb_meta`, `lookup_funcs`, `disasm`, `decompile`, `callees`, `callers`, `xrefs_to`, `search`, `find_insn_operands`, and `py_eval`.
- Byte-level checks: exact target bytes, padding bytes, raw dword pointer scans for VA/RVA, and unique immediate/encoding scan for `1000003`.
- Documentation checks: target page, generated memory coverage, by-memory coverage, StringUtil, StringBase, CachedHashTable, RectBounds, PathUtil, FieldMapPane, GeneralPurposePanel, and neighboring by-memory docs.
- Negative evidence is treated as decisive for assignment, not for reconstructability: it proves the parent link is missing, while the body itself remains reconstructable.

## IDA MCP Facts

- Function/range facts: IDB `NexusTK.exe`, base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`. `lookup_funcs` reports no function at `0x004b8198`, `0x004b81a0`, or `0x004b81eb`. Neighbor functions remain `sub_4B81F0` at `0x004b81f0-0x004b821e`, `sub_4B8220` at `0x004b8220-0x004b8284`, and `sub_4B8290` at `0x004b8290-0x004b83ae`.
- Body facts: raw disassembly is `push ebp; mov ebp, esp`, reads `[ebp+8]` into `esi`, scans 16-bit units to zero, seeds `edx` from the first word shifted left seven, loops with `imul edx, 0x0f4243` and `xor edx, eax`, XORs the code-unit length, returns `eax=edx`, and has no calls, globals, or writes except stack/register saves.
- Data/table/padding facts: raw bytes for `0x004b8198-0x004b81a0` are eight `cc`; raw bytes for `0x004b81eb-0x004b81f0` are five `cc`. Raw dword scans find no little-endian `0x004b81a0` or `0x000b81a0` in loaded IDB segments.
- Xref facts: `xrefs_to`, `callers`, `search code_ref`, and `search data_ref` for `0x004b81a0` are empty. `find_insn_operands` finds no operand equal to `0x004b81a0` or `0x000b81a0`.
- Neighbor contrast facts: `0x004b81f0` has callers `0x0049c87c`, `0x0049c88f`, and `0x004dbcb5`; `0x004b8220` has caller `0x004b0c0d`; `0x004b8290` has raw geometry xrefs from `0x004b803e`, `0x004b809f`, `0x004b80ff`, and `0x004b8161`.
- Hash-pattern facts: `find_insn_operands` finds decimal `1000003` only at `0x004b81d6`; raw byte scan finds exact `69 d2 43 42 0f 00` only at `0x004b81d6`, and little-endian immediate bytes only at `0x004b81d8`.
- Negative IDA facts: decompilation and callees fail for `0x004b81a0` because there is no IDA function object; no vtable slot, callback table, raw pointer, or direct caller was found.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b81a0-0x004b81eb` | `00022J` / `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` | Raw UTF-16 string hash helper | `TRUE` | blank | `85/88` | Repaired; no assignment |
| `0x004b8198-0x004b81a0` | `0000VN` / `by-memory/-ignored.md` | Alignment padding | no | ignored | `100/strong` | Unmodified |
| `0x004b81eb-0x004b81f0` | `0000VN` / `by-memory/-ignored.md` | Alignment padding | no | ignored | `100/strong` | Unmodified |
| `0x004b81f0-0x004b821e` | `00022K` / `FileExists` | Adjacent path existence helper | `TRUE` | `0000MI` PathUtil | `88/90` | Neighbor only |
| `0x004b8220-0x004b8284` | `00015U` / `BuildFieldMapPath` | Adjacent FieldMapPane constructor helper | `TRUE` | `0000JA` FieldMapPane | `84/88` | Neighbor only |
| `0x004b8290-0x004b83c5` | `00022L` / `RectAnchorAxisAdjustHelper` | Adjacent rect-anchor helper plus switch data | `TRUE` | `0000N2` RectBounds | `78/86` | Neighbor only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b81a0` | no `xrefs_to`, no `callers`, no code/data search hits | No direct reachability for the hash helper |
| `0x004b81a0` / `0x000b81a0` | no raw dword scan hits | No hidden VA/RVA pointer in loaded segments |
| `0x004b81d6` | only `1000003` operand and only exact `imul` encoding | Algorithm pattern is unique in `.text` |
| `0x004b81f0` | callers `0x0049c87c`, `0x0049c88f`, `0x004dbcb5` | Adjacent FileExists has normal call evidence |
| `0x004b8220` | caller `0x004b0c0d` | Adjacent BuildFieldMapPath has FieldMapPane caller evidence |
| `0x004b8290` | xrefs `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161` | Adjacent rect-anchor helper is tied to the preceding geometry cluster |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: the target page already documented raw behavior and no-reference state; `by-memory/-ignored.md` documents the exact padding; `FileExists`, `BuildFieldMapPath`, and rect-anchor docs document the mixed neighborhood and their own separate caller evidence.
- Existing docs that were stale or incomplete: the target was below the completion gate even though the decisive negative evidence had accumulated. This pass raised it from `83/85` to `85/88` while keeping the parent blank.
- Generated/coverage report state: `auto-generated/-ag-memory-coverage.md` lists `00022J` unassigned. `by-memory/-coverage-report.md` still has an older row summary, but this pass did not directly edit generated reports.

## Ranked Ownership Analysis

### 1. Retained source-authored unreferenced wide-string hash helper

- Evidence for: exact source-shaped cdecl helper body, UTF-16 input, no side effects, no compiler thunk pattern, unique `1000003` hash recurrence, exact padding, and no reachability artifact.
- Evidence against: no direct source owner name or caller; retained/unreferenced status is inferred from absence of references, not a positive source label.
- Decision: accepted as the final disposition. Keep the page reconstructable and parent-blank.

### 2. StringUtil / broad string utility family

- Evidence for: `StringUtil` is `87/88`, owns shared UTF-16/string infrastructure, and is the best semantic fit for a wide-string hash helper.
- Evidence against: no caller, table ref, raw pointer, adjacent string island, StringBase/SimpleUString layout dependency, or generated output ties `0x004b81a0` to StringUtil. Behavior-only affinity is not enough for a strict direct parent assignment.
- Decision: best candidate parent, but not assigned.

### 3. External/library-style string hash helper

- Evidence for: the decimal `1000003` multiply/XOR shape resembles known string hashing idioms, and the helper is unreferenced in the current IDA graph.
- Evidence against: the body lacks the `-1` sentinel repair often associated with Python-style hashes, uses UTF-16 words, and has no import/library namespace evidence.
- Decision: plausible explanation for retained code shape, but no parent page or assignment action is justified.

### 4. CachedHashTable

- Evidence for: name and domain involve hashing; it is a util source candidate.
- Evidence against: `CachedHashTable` is `84/88`, below the strict completion gate; its documented helper island is at `0x004c62d0-0x004c64df`, uses fixed-entry cache object state and per-instance hash bytes, and has no link to a UTF-16 string hash helper at `0x004b81a0`.
- Decision: rejected as direct parent.

### 5. RectBounds and neighboring geometry helpers

- Evidence for: physical neighborhood includes `RectAnchorTransformHelpers` before the target and `RectAnchorAxisAdjustHelper` after `BuildFieldMapPath`; RectBounds docs list the mixed neighborhood.
- Evidence against: `RectBounds` is `90/82`, below strict confidence gate; geometry helpers pass rectangle/edge pointers and have direct xrefs between each other, while `00022J` takes one UTF-16 pointer and has no geometry calls or xrefs.
- Decision: rejected. Proximity is explicitly not ownership proof.

### 6. PathUtil / FieldMapPane / GeneralPurposePanel neighborhood

- Evidence for: `PathUtil` owns adjacent `FileExists` at `0x004b81f0`; `FieldMapPane` owns adjacent `BuildFieldMapPath`; `GeneralPurposePanel` starts at the next larger panel range.
- Evidence against: the helper does not open files, copy path stems, append `.EPF`, read panel fields, touch singletons, or call their helper surfaces. Their nearby functions have their own positive callers; `00022J` does not.
- Decision: rejected as direct parents.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new parent file is recommended from this one isolated unreferenced helper.
- Likely full contents: only `0x004b81a0-0x004b81eb` is currently supported.
- Candidate related items that belong: none proven.
- Candidate related items rejected: adjacent `FileExists`, `BuildFieldMapPath`, rect-anchor helpers, and GeneralPurposePanel belong to their documented source families.
- Standalone, narrow, or broad source-file inference: if future evidence finds related string-hash helpers, a narrow `StringHash` or `StringUtil` sub-owner may be justified. Current evidence supports only parent-blank retention.

## Negative Evidence Summary

- No function object at the target start.
- No direct callers or xrefs.
- No raw VA/RVA dword pointer to `0x004b81a0` in loaded segments.
- No operand/immediate references to `0x004b81a0` or `0x000b81a0`.
- No vtable slot, callback table, jump table, or import/name artifact references the helper.
- No CachedHashTable object layout, RectBounds geometry layout, PathUtil file API, FieldMapPane path-stem copy, or GeneralPurposePanel state appears in the body.
- Adjacent helpers have positive owner evidence; this helper remains the isolated no-reference item in the neighborhood.

## Final Recommendation

- Exact changes applied: updated `00022J` from `83/85` to `85/88`, added B001-031 IDA MCP/IDA Python reachability and uniqueness evidence, and clarified the corrected assignment gate.
- Exact parent assignments applied or recommended: none. `AUTOGEN_PARENT_UID` stays blank.
- Exact items left unassigned and why: `00022J`, because no direct owner link distinguishes StringUtil from retained external/library-style utility code.
- Exact future work outside this assignment scope: if a later pass discovers a raw pointer/table/name artifact or source-family reference to `0x004b81a0`, revisit StringUtil first, then external string-hash utility modeling.

## Follow-Up Actions

- Supervisor actions: review the repaired child score and blank-parent recommendation.
- A-agent actions: none unless new reachability evidence appears.
- B001 future research actions: only revisit if another target reveals a string/hash table, callback table, or source-owner artifact that references `0x004b81a0`.

## Confidence

- Recommendation confidence: high for "do not assign now"; medium for "retained source-authored utility" because that is an inference from a complete absence of references.
- Score confidence: `85/88` is defensible because function behavior, boundaries, side effects, uniqueness, and negative reachability are all freshly documented.
- Remaining uncertainty: original source placement. StringUtil remains the best semantic candidate but not an assignment-quality parent.

## Validator Results

- Commands run:
  - `python tools\validator.py --mode file --file "by-memory\0x004b81a0-0x004b81eb.WideStringHashHelper.md" --apply`
- Results:
  - `mode: file`
  - `apply: True`
  - `scanned markdown files: 1`
  - `ok: 1`
  - `autogen_report_noop` for generated coverage reports after the already-applied `85/88` metadata/documentation update.
- Any unresolved validator warnings/errors: none for the target file.

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B001/research/00022J-WideStringHashHelper.md`
- Modified:
  - `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`
  - `tools/leaser/Agents/Agent-B001/research/00022J-WideStringHashHelper.md`
- Renamed: none.
- Moved to executed: none.
