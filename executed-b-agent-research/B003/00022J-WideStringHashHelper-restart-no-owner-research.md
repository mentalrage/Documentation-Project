** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022J WideStringHashHelper Restart No-Owner Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](../../../../../by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Final disposition: reconstructable exact helper, still no-owner and non-emitting because no direct source owner or generated source-use route is proven.
- Required action: no split, merge, reclassification, rename repair, canonical-owner assignment, emitter assignment, score change, or C++ entry.
- Confidence: high for the no-owner/non-emitting recommendation; retain current target score `88/92`.

## Supporting Research

## Target
- Target UID: `00022J`.
- Target path: `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`.
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, active restart-pass row for Agent-B003 on 2026-06-14.
- Prior report reviewed first as background only: `tools/leaser/Agents/Agent-B002/research/executed/00022J-WideStringHashHelper-current-no-owner-sweep.md`.
- Current generated classification: `auto-generated/-ag-memory-coverage.md` lists this item as `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, no output path, and non-emitting.
- Current header state: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.

## Executive Recommendation
- Leave the item no-owner and non-emitting. The range is a real source-shaped helper, but current evidence still exposes no caller, code xref, data xref, raw VA/RVA pointer, `push` pointer, direct external branch/call route, table/vtable route, global route, or source-family artifact.
- Do not assign [UID:0000OB][StringUtil](../../../../../by-file/StringUtil.md). `StringUtil` is the best semantic candidate because the helper hashes a UTF-16 string, but current rules require more than behavior similarity for a direct owner.
- Do not add emitters. No source-use output route is proven, so blank `EMITTER_UIDS` remains correct. This is not a shared literal/data case with proven multiple source-use routes.
- Do not enter or recommend C++. The item is below the current `90/90+` code-entry gate on completion, and the source placement/emitter route remains intentionally unresolved.
- The condition for changing this result is a future direct route: caller, hidden branch target, function-pointer/table use, raw VA/RVA reference, source-name/debug breadcrumb, or a strong source-family relationship that identifies a direct owner and any emitted source contexts.

## Supervisor Active Recheck
- Supervisor instruction: restart-pass recheck of current no-owner non-emitting memory target [UID:00022J] using current docs plus live IDA MCP evidence, without assuming the B002 prior report is correct.
- Split requirement: no split is required. The target is one exact `0x4b` function body bounded by `0xcc` alignment padding on both sides.
- Direct in-scope repairs: none. Current target and related docs already encode the important range, behavior, IDA function identity, no-reference state, and rejected owner candidates.
- Source-bearing children created: none. No uncovered subrange exists inside `0x004b81a0-0x004b81eb`.

## Inference Research Guidance Check
- `by-structure.md` separates `CANONICAL_OWNER` from `EMITTER_UIDS`. A reconstructable item may remain `CANONICAL_OWNER:NONE` and non-emitting when the function is real but no direct owner or source-use route is proven.
- `by-structure.md` also blocks filling owner/emitter/C++ fields merely because a candidate is plausible. That rule matters here because `StringUtil` is plausible but not directly proven.
- `inference_research.md` treats adjacency, semantic similarity, and broad utility fit as weak without xrefs, table/layout evidence, source artifacts, constructor/destructor context, or repeated owner-specific source family. This rejects proximity-only owners in the mixed `0x004b7f90-0x004b83c5` neighborhood.
- Existing docs and prior reports were treated as leads. This pass rechecked current generated state, target docs, candidate parent docs, live IDA MCP results, and fresh raw PE evidence.

## Evidence Standards Used
- Direct IDA MCP evidence: active IDB/session health, `lookup_funcs`, `get_bytes`, `xrefs_to`, `xref_query`, and `find_bytes` for the target and neighboring helper starts.
- Raw PE evidence: PE section mapping, raw target bytes, adjacent padding bytes, VA/RVA literal scans, `push imm32` scan, executable-section branch/call target scan, and unique hash-multiply byte-pattern scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Documentation evidence: current target page, `auto-generated/-ag-memory-coverage.md`, `by-memory/-coverage-report.md`, `StringUtil`, `StringBase`, `CachedHashTable`, `PathUtil`, `RectBounds`, neighboring by-memory pages, `by-structure.md`, `inference_research.md`, and proposed source-tree context.
- Negative evidence is decisive here because owner/emitter assignment would require some source-use route or source-family proof. The target currently has none.

## IDA MCP Facts
- Session facts: live IDA MCP session `b001_0003gy` is active for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; server health reports IDB `NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Function/range facts: `lookup_funcs` reports `WideStringHashHelper` at `0x004b81a0`, size `0x4b`; no function at `0x004b8194` or `0x004b81eb`; neighboring starts remain `sub_4B81F0` at `0x004b81f0`, `sub_4B8220` at `0x004b8220`, and `sub_4B8290` at `0x004b8290`.
- Data/table/padding facts: `get_bytes 0x004b8194 size 12` returns twelve `0xcc` bytes; `get_bytes 0x004b81a0 size 75` returns the full target body from `55 8b ec` through `5d c3`; `get_bytes 0x004b81eb size 5` returns five `0xcc` bytes.
- Behavior facts from the current function body and target-page Hex-Rays record: the helper takes one wide-string pointer from `[ebp+8]`, scans 16-bit code units to NUL, seeds the hash from the first code unit shifted left by seven, uses `imul edx, 0F4243h` plus XOR in the loop, XORs the code-unit length, returns in `eax`, calls no functions, and touches no globals.
- Xref facts: `xrefs_to 0x004b81a0` reports zero incoming xrefs. `xref_query both 0x004b81a0` reports only an internal flow edge from `0x004b81a0` to `0x004b81a1`, not an external caller or data reference.
- Neighbor contrast: `xrefs_to 0x004b81f0` reports three code refs at `0x0049c87c`, `0x0049c88f`, and `0x004dbcb5`; `xrefs_to 0x004b8220` reports one code ref at `0x004b0c0d`; `xrefs_to 0x004b8290` reports four code refs at `0x004b803e`, `0x004b809f`, `0x004b80ff`, and `0x004b8161`. The reference gap is local to `00022J`, not a whole-neighborhood analysis failure.
- Pattern facts: IDA `find_bytes` finds no `A0 81 4B 00` VA literal, no `A0 81 0B 00` RVA literal, and no `68 A0 81 4B 00` `push` route. It finds the hash multiply encoding `69 D2 43 42 0F 00` only at `0x004b81d6`, and immediate bytes `43 42 0F 00` only at `0x004b81d8`.

## PE / Raw Evidence
- PE path checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- File size and digest: `2679296` bytes, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- PE facts: imagebase `0x00400000`; `.text` maps VA `0x00401000-0x0060c600` to raw `0x00000400-0x0020ba00`.
- Target VA/RVA/raw: VA `0x004b81a0`, RVA `0x000b81a0`, raw file offset `0x000b75a0`, section `.text`, length `75`.
- Target bytes:

```text
55 8b ec 56 8b 75 08 8b ce 57 8d 51 02 0f 1f 00
66 8b 01 83 c1 02 66 85 c0 75 f5 2b ca 0f b7 16
d1 f9 8b f9 c1 e2 07 83 e9 01 78 17 0f 1f 40 00
0f b7 06 8d 76 02 69 d2 43 42 0f 00 33 d0 83 e9
01 79 ed 33 d7 5f 8b c2 5e 5d c3
```

- Raw padding facts: preceding twelve bytes at `0x004b8194-0x004b81a0` are all `cc`; successor five bytes at `0x004b81eb-0x004b81f0` are all `cc`.

| Raw scan | Result |
| --- | --- |
| Little-endian VA `a0 81 4b 00` | 0 hits |
| Little-endian RVA `a0 81 0b 00` | 0 hits |
| `push 0x004b81a0` bytes `68 a0 81 4b 00` | 0 hits |
| Hash multiply bytes `69 d2 43 42 0f 00` | 1 hit, raw `0x000b75d6` / VA `0x004b81d6` |
| Immediate `1000003` bytes `43 42 0f 00` | 1 hit, raw `0x000b75d8` / VA `0x004b81d8` |
| Direct branch/call to exact target start | 0 hits |
| External direct branch/call into target range | 0 hits; the six branch hits into the range all originate inside the target body and are loop/local-control-flow edges |

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b8194-0x004b81a0` | `-ignored.md` padding row | Predecessor alignment after RectAnchorTransformHelpers | No | N/A | `100/strong` | Confirmed `0xcc`; no split issue. |
| `0x004b81a0-0x004b81eb` | [UID:00022J](../../../../../by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | Wide UTF-16 string hash helper | `TRUE` | `NONE` | `88/92` | Keep no-owner, blank emitters, blank C++. |
| `0x004b81eb-0x004b81f0` | `-ignored.md` padding row | Successor alignment before FileExists | No | N/A | `100/strong` | Confirmed `0xcc`; no split issue. |
| `0x004b81f0-0x004b821e` | [UID:00022K](../../../../../by-memory/0x004b81f0-0x004b821e.FileExists.md) | Wide path existence helper | `TRUE` | `0000MI` PathUtil | `88/90` | Neighbor with direct callers; not owner evidence for `00022J`. |
| `0x004b8220-0x004b8284` | [UID:00015U](../../../../../by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md) | FieldMap path-stem helper | `TRUE` | `0000JA` FieldMapPane | `84/88` | Neighbor with FieldMapPane caller; not owner evidence for `00022J`. |
| `0x004b8290-0x004b83c5` | [UID:00022L](../../../../../by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) | Rect anchor axis helper | `TRUE` | `0000N2` RectBounds | `86/88` | Neighbor with rect-anchor xrefs; not owner evidence for `00022J`. |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b81a0` | `xrefs_to`: none | No direct caller or data-use route to the target. |
| `0x004b81a0` | `xref_query both`: internal flow edge only | Not ownership or emitter evidence. |
| `0x004b81a0` | no callees observed in body | No dependency trail to a known owner. |
| `0x004b81f0` | callers at `0x0049c87c`, `0x0049c88f`, `0x004dbcb5` | Neighbor `FileExists` has normal caller evidence and a PathUtil route. |
| `0x004b8220` | caller at `0x004b0c0d` | Neighbor `BuildFieldMapPath` has FieldMapPane source-use evidence. |
| `0x004b8290` | refs from `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161` | Nearby rect-axis helper is tied to RectBounds/geometry helper flow. |

## Documentation Evidence And IDA Status
- Target page: already records the exact header state, likely signature, behavior, no-call/no-global side-effect profile, `0xcc` boundaries, current IDA function name, lack of direct references, and rejected owner candidates.
- Current generated row: `auto-generated/-ag-memory-coverage.md` still reports `no-owner`, `CANONICAL_OWNER:NONE`, blank emitters, and no output path.
- Current shared coverage row: `by-memory/-coverage-report.md` already states B003 kept `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` because the exact body has no callers/xrefs/raw pointer/table/branch route and `StringUtil` remains semantic only.
- `StringUtil.md`: explicitly says not to attach `00022J` solely from wide-string hash semantics; it requires caller, xref, raw pointer, table reference, or source-family evidence. Current IDA/PE checks still do not provide that evidence.
- `StringBase.md`: owns separate string-buffer mechanics; `00022J` has no StringBase storage, refcount, sentinel, pool, append, compare, or call evidence.
- `CachedHashTable.md`: documents a separate class/vtable/helper island around `0x004c6160+`; it has generic hash-domain similarity but no receiver, layout, vtable, caller, or table link to `00022J`.
- Neighbor docs: `RectBounds`, `PathUtil`, `FieldMapPane`, and neighboring by-memory pages show independent xref/behavior evidence for their own helpers. This address neighborhood is mixed and cannot provide owner proof by adjacency.
- Historical/stale concern: older target-page notes predate the C001 IDA function creation. They are chronological evidence and are superseded by current status/change-log lines; no documentation repair is required.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Evidence for: exact function exists; exact range and behavior are understood; no incoming xrefs; no external branch/call route; no raw VA/RVA/push pointer; no table/vtable/global route; no callees; no source-use context; no source-family artifact.
- Evidence against: the helper is source-shaped and almost certainly had some original utility owner.
- Decision: accepted. This is the only current state that does not invent unsupported source placement or output routing.

### 2. [UID:0000OB][StringUtil](../../../../../by-file/StringUtil.md)
- Evidence for: best semantic fit. The target hashes a UTF-16 NUL-terminated string using the distinctive `1000003` multiply/XOR recurrence, and `StringUtil.cpp` is the broad string utility source candidate in the proposed tree.
- Evidence against: no caller, xref, data pointer, raw pointer, table route, source breadcrumb, or documented StringUtil child family ties `0x004b81a0` to that file. The current `StringUtil` page explicitly excludes the assignment absent such proof.
- Decision: reject as current owner and emitter. Recheck first if future evidence identifies a real source-use route.

### 3. [UID:0000OA][StringBase](../../../../../by-file/StringBase.md)
- Evidence for: broad string infrastructure domain.
- Evidence against: no StringBase object, allocation, refcount, sentinel, append/format worker, range helper, or call-family link appears in the target. Address family is also unrelated to the documented StringBase function cluster.
- Decision: rejected.

### 4. [UID:0000HZ][CachedHashTable](../../../../../by-file/CachedHashTable.md)
- Evidence for: hash/cache domain similarity.
- Evidence against: CachedHashTable has separate class/vtable/lifecycle evidence and class-local helpers. `00022J` has no receiver, no slot state, no table walk, no vtable/RTTI relation, no callers, and hashes a raw UTF-16 string.
- Decision: rejected.

### 5. Nearby owners: RectBounds, PathUtil, FieldMapPane, GeneralPurposePanel
- Evidence for: physical adjacency in `.text`.
- Evidence against: live xrefs and docs assign neighboring helpers through independent behavior/caller evidence: RectBounds for rect-anchor helpers, PathUtil for `FileExists`, FieldMapPane for `BuildFieldMapPath`. None reference or call `0x004b81a0`.
- Decision: rejected. Adjacency is weak and this neighborhood is demonstrably mixed.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: none recommended.
- Likely full contents: not applicable.
- Candidate related items that belong: none proven.
- Candidate related items rejected: the nearby geometry/path/FieldMap helpers belong elsewhere; `StringUtil`, `StringBase`, and `CachedHashTable` remain unproven.
- Standalone, narrow, or broad source-file inference: a hidden stripped utility owner probably existed, but current evidence cannot safely name or model it.

## Negative Evidence Summary
- Checked and rejected direct IDA xrefs: none to `0x004b81a0`.
- Checked and rejected broad IDA xref state: only target-internal flow edge appears.
- Checked and rejected raw literal routes: no VA `0x004b81a0`, no RVA `0x000b81a0`, no `push 0x004b81a0`.
- Checked and rejected direct executable routes: no external rel8/rel32 branch or call targets the helper start or enters the range.
- Checked and rejected table/vtable/global ownership: no data xrefs, raw pointer hits, vtable slots, global docs, or source-family artifacts point at the helper.
- Checked and rejected address adjacency: neighboring helpers have separate owners/routes and are separated by padding.
- Checked and rejected behavior-only ownership: wide-string hash semantics are insufficient to assign `StringUtil` or an emitter.

## Final Recommendation
- Exact changes applied or recommended: no by-* documentation edits applied; no split/merge/rename/reclassify/score/code change recommended.
- Exact files to edit: none required.
- Exact parent assignment: retain `CANONICAL_OWNER:NONE`.
- Exact emitter assignment: retain blank `EMITTER_UIDS` and blank `EMITTER_POSITION_OPTIONAL`.
- Exact item left no-owner/non-emitting: [UID:00022J] remains no-owner/non-emitting because no direct owner or output route is proven.
- Exact future work outside this assignment scope: reopen only if future analysis finds a caller, function-pointer/table route, raw pointer/branch route, source-name breadcrumb, or strong source-family evidence.

## Exact Supervisor-Owned Shared-Report Text
- `by-memory/-coverage-report.md`: no required replacement. The current row remains accurate and can be retained exactly:

```markdown
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : B003 second-pass review keeps `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`; C001-009 defined the exact raw body as IDA function `WideStringHashHelper`, and fresh PE/raw scans reconfirm isolated `0x4b` prologue/body/return range, adjacent `0xcc` padding, unique `wcslen` plus `1000003` wide-string hash recurrence, no callers/xrefs/raw VA/RVA pointer/table reference, no external branch/call route, and normal xrefs to adjacent FileExists/BuildFieldMapPath/RectAnchor helpers. `StringUtil` remains semantic only and no direct owner/emitter evidence is proven.
```

- Optional supervisor provenance refresh only, not required for correctness:

```markdown
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : B003 2026-06-14 restart-pass recheck keeps `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`; live IDA MCP session `b001_0003gy` reconfirms `WideStringHashHelper` as the exact `0x4b` function at `0x004b81a0-0x004b81eb`, adjacent `0xcc` padding, zero incoming xrefs, no proven caller/callee/source-use route, unique `1000003` wide-string hash recurrence, and normal reference surfaces for neighboring FileExists/BuildFieldMapPath/RectAnchor helpers. Fresh raw PE scans find no VA/RVA pointer, no `push` pointer, no external direct branch/call route, and only the helper-local `69 D2 43 42 0F 00` multiply pattern at `0x004b81d6`; `StringUtil` remains semantic only and no direct owner or emitter route is proven.
```

- `auto-generated/-ag-memory-coverage.md`: no manual edit. It is generated and currently reflects the correct state:

```markdown
| [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` |  |
```

## Follow-Up Actions
- Supervisor actions: mark this B003 restart-pass assignment complete. No owner/emitter/code/split action is required. Optional provenance refresh above can be applied to `by-memory/-coverage-report.md` only if the supervisor wants the current pass stamped into the shared report.
- A-agent actions: none.
- B003 future research actions: none unless new reference/source-use evidence appears.

## Confidence
- Recommendation confidence: high. The no-owner/non-emitting result is supported by positive function/range evidence and repeated negative route evidence.
- Score confidence: retain `88/92`. Completion should not increase because final source owner, emitter route, and source filename remain unresolved. Confidence stays strong because the route-negative evidence is specific and current.
- Remaining uncertainty: original source ownership is still unknown. The uncertainty is about source placement and emission, not about bytes, range, behavior, or side effects.

## Validator Results
- Commands run: none.
- Results: not applicable. No by-* documentation, generated files, project-level files, or validator-managed metadata were edited.
- Dry runs: none used.
- Unresolved validator warnings/errors introduced by this work: none.

## Leases
- Lease state: report file was leased as B003 before writing the final body. An initial lease attempt before the new report existed was rejected as `File not found`; a one-line stub was then created, leased successfully, and a later lease refresh attempt returned `Already has lease`.
- By-* leases: none acquired because no by-* files were edited.
- Final lease state: the first report lease expired before the final unlease command, so that command returned `No active lease`; fresh B003 report leases were taken only to correct final report wording and then released. No active B003 lease remains from this assignment. `current_leases.md` is a shared leaser state file and may show other agents' active leases, but no B003/`00022J` lease remains.

## Changed Files
- Created/modified: `tools/leaser/Agents/Agent-B003/research/00022J-WideStringHashHelper-restart-no-owner-research.md`.
- Leaser side effect: `tools/leaser/Agents/current_leases.md` was rewritten by the lease tool during B003 acquire/release; final B003 lease state is released, and any remaining non-B003 rows are other agents' leases.
- Modified by-* files: none.
- Modified generated/project-level files: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00022J-WideStringHashHelper-restart-no-owner-research.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
