** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022J WideStringHashHelper Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](../../../../../by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Final disposition: reconstructable exact by-memory helper with no proven direct source owner and no proven output route.
- Required action: no by-memory split, merge, reclassification, IDA-safe rename repair, owner assignment, emitter assignment, score change, or C++ entry is justified by the current evidence.
- Confidence: high for the no-owner/non-emitting recommendation; current scores `COMPLETION:88`, `CONFIDENCE:92` remain defensible.

## Supporting Research

## Target
- Target UID: `00022J`.
- Target path: `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`.
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, section `Active 2026-06-14 Remaining No-Owner Memory Sweep`.
- Current generated classification: `auto-generated/-ag-memory-coverage.md` reports this item as `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, no generated output path, and `non-emitting`.
- Current scores and owner/emitter state: target page records `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank C++.

## Executive Recommendation
- Leave the item ownerless and non-emitting. The helper is real source-shaped code, but the binary still exposes no caller, code xref, data xref, raw VA/RVA pointer, direct branch route, table/vtable route, or source-family artifact that can distinguish a direct owner.
- Do not attach it to [UID:0000OB][StringUtil](../../../../../by-file/StringUtil.md) from wide-string hash semantics alone. `StringUtil` is the best semantic candidate, but current project rules require direct semantic-owner evidence and separate emitter-route evidence.
- Do not add emitters. A blank `EMITTER_UIDS` field is correct because no source-use output route is proven. This is different from shared-literal cases where `CANONICAL_OWNER:NONE` plus multiple emitters is correct.
- Do not enter C++. The page is below the current `90/90+` code-entry gate on completion, and the final owner/emitter/source placement is intentionally unresolved.
- The exact condition required before assignment changes: a future pass must find a real reference/use route or source artifact, such as a caller, non-IDA-modeled branch target, function pointer/table entry, raw VA/RVA relocation-like use, source-name/debug breadcrumb, or a closed family relationship strong enough to identify a direct owner and any output emitters.

## Supervisor Active Recheck
- Supervisor instruction: recheck current no-owner memory target `00022J` from current docs plus live IDA MCP evidence, treating the prior report as background only.
- Split requirement: no split is required. The live range is one exact `0x4b` function-shaped helper bounded by `0xcc` padding on both sides.
- Direct in-scope repairs: none. Current documentation already records the key behavior, range, IDA function identity, negative xref state, and rejected owner candidates. This pass found no new evidence requiring edits to the target page or related by-* docs.
- Source-bearing children: none were created. There is no uncovered subrange inside `0x004b81a0-0x004b81eb`.

## Inference Research Guidance Check
- `by-structure.md` separates semantic ownership (`CANONICAL_OWNER`) from generated output routing (`EMITTER_UIDS`). A reconstructable item may remain `CANONICAL_OWNER:NONE` and non-emitting when the function is real but no direct owner or source-use route is proven.
- `by-structure.md` also warns not to fill owner/emitter/code fields merely because ownership is plausible. This applies directly here: `StringUtil` is plausible by behavior, but not proven by xrefs or source-family evidence.
- `inference_research.md` treats adjacency and semantic similarity as weak evidence unless reinforced by xrefs, section/linkage evidence, constructors, globals, or other hard facts. That prevents attaching this helper to nearby `RectBounds`, `PathUtil`, or `FieldMapPane` items and prevents treating the hash algorithm alone as proof of `StringUtil`.
- Existing docs and prior reports were used as leads only. The current recommendation rests on the current generated rows, current by-* pages, live IDA MCP results, and a fresh raw PE scan.

## Evidence Standards Used
- Direct IDA MCP evidence: `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `get_bytes`, `find_bytes`, `callees`, and `make_signature_for_range`.
- Raw PE evidence: section mapping, VA/RVA literal scan, `push imm32` scan, executable-section rel8/rel32 branch scan, and unique hash-multiply byte-pattern scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Documentation evidence: current target page, current generated `-ag-memory-coverage.md`, current shared `by-memory/-coverage-report.md`, `StringUtil`, `StringBase`, `CachedHashTable`, `PathUtil`, `FieldMapPane`, `RectBounds`/anchor helper pages, `by-structure.md`, `inference_research.md`, and `proposed-source-tree.md`.
- Negative evidence is material here. The target is a freestanding helper with no observed call surface; the absence of caller/pointer/branch/table routes is exactly what blocks owner and emitter assignment.

## IDA MCP Facts
- Session: `idb_list` shows active session `b001_0003gy` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reports IDB `NexusTK.exe.i64`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Function/range facts: `lookup_funcs` reports `WideStringHashHelper` at `0x004b81a0`, size `0x4b`. It reports no function at `0x004b8194` or `0x004b81eb`. Neighboring modeled starts remain `sub_4B81F0` at `0x004b81f0`, `sub_4B8220` at `0x004b8220`, and `sub_4B8290` at `0x004b8290`.
- Behavior facts: Hex-Rays decompiles `unsigned int __cdecl WideStringHashHelper(const unsigned __int16 *a1)`, computes `wcslen(a1)`, seeds `v3 = *a1 << 7`, loops with `v5 ^ (1000003 * v3)`, and returns `length ^ hash`.
- Disassembly facts: the function starts with `push ebp; mov ebp, esp`, scans 16-bit code units until NUL, uses `imul edx, 0F4243h` at `0x004b81d6`, XORs each code unit, XORs the length, and returns at `0x004b81ea`.
- Data/table/padding facts: `get_bytes 0x004b8194 size 12` returns twelve `0xcc` bytes; `get_bytes 0x004b81a0 size 75` returns the exact body bytes; `get_bytes 0x004b81eb size 5` returns five `0xcc` bytes.
- Xref facts: `xrefs_to 0x004b81a0` reports zero incoming xrefs. `xref_query both 0x004b81a0` reports only the internal flow edge from `0x004b81a0` to `0x004b81a1`, not an external caller or data reference. `callees 0x004b81a0` reports no callees.
- Adjacent contrast: `xrefs_to 0x004b81f0` reports three code refs at `0x0049c87c`, `0x0049c88f`, and `0x004dbcb5`; `xrefs_to 0x004b8220` reports one code ref at `0x004b0c0d`; `xrefs_to 0x004b8290` reports four code refs at `0x004b803e`, `0x004b809f`, `0x004b80ff`, and `0x004b8161`.
- Pattern facts: IDA `find_bytes` finds no `A0 81 4B 00` VA literal and no `A0 81 0B 00` RVA literal. It finds `69 D2 43 42 0F 00` only at `0x004b81d6`, and the immediate bytes `43 42 0F 00` only at `0x004b81d8`.
- Signature fact: `make_signature_for_range 0x004b81a0-0x004b81eb` with operand wildcarding disabled reports the exact body signature as unique.

## PE / Raw Evidence
- PE path checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Imagebase: `0x00400000`.
- Target VA/RVA/raw: `0x004b81a0`, RVA `0x000b81a0`, raw file offset `0x000b75a0`, section `.text`.
- Clean raw scan result:

```text
LiteralVAHitCount: 0
LiteralRVAHitCount: 0
PushVAHitCount: 0
DirectBranchHitCount: 0
ExternalDirectBranchHitCount: 0
ImulPatternHitCount: 1
ImulPatternHits: raw 0xb75d6 / va 0x004b81d6
```

- Meaning: current raw PE evidence still finds no literal function pointer, no RVA pointer, no `push` pointer, and no direct rel8/rel32 branch or call route into the helper start. The only unique raw pattern is the helper's own `imul edx, 0x0f4243` instruction.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b8194-0x004b81a0` | `-ignored.md` padding row | Predecessor alignment after RectAnchorTransformHelpers | No | N/A | `100/strong` | Confirmed `0xcc` padding; no split issue. |
| `0x004b81a0-0x004b81eb` | [UID:00022J](../../../../../by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | Wide UTF-16 hash helper | `TRUE` | `NONE` | `88/92` | Keep no-owner, blank emitters, blank C++. |
| `0x004b81eb-0x004b81f0` | `-ignored.md` padding row | Successor alignment before FileExists | No | N/A | `100/strong` | Confirmed `0xcc` padding; no split issue. |
| `0x004b81f0-0x004b821e` | [UID:00022K](../../../../../by-memory/0x004b81f0-0x004b821e.FileExists.md) | Wide path existence probe | `TRUE` | `0000MI` PathUtil | `88/90` | Neighbor with normal callers; not related owner evidence. |
| `0x004b8220-0x004b8284` | [UID:00015U](../../../../../by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md) | FieldMap path-stem helper | `TRUE` | `0000JA` FieldMapPane | `84/88` | Neighbor with one FieldMapPane caller; not related owner evidence. |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b81a0` | `xrefs_to`: none | No caller/source-use route into the target. |
| `0x004b81a0` | `xref_query both`: one internal flow edge to `0x004b81a1` | Internal function control flow only; not ownership or emitter evidence. |
| `0x004b81a0` | `callees`: none | Self-contained helper; no callee family proves owner. |
| `0x004b81f0` | `0x0049c87c`, `0x0049c88f`, `0x004dbcb5` | Neighbor `FileExists` has normal caller evidence and a proven `PathUtil` route. |
| `0x004b8220` | `0x004b0c0d` | Neighbor `BuildFieldMapPath` has a FieldMapPane constructor route. |
| `0x004b8290` | `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161` | Nearby rect-axis helper has a localized RectBounds/geometry route. |

## Documentation Evidence And IDA Status
- Existing target page: already records `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:TRUE`, exact range, likely signature, full hash behavior, no-call/no-global side-effect profile, surrounding padding, no-reference state, current IDA function identity, and rejected owner candidates.
- Current generated report: `auto-generated/-ag-memory-coverage.md` still lists the item as `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, no output path, and `non-emitting`.
- Current shared coverage report: `by-memory/-coverage-report.md` already says B003 kept `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`, with evidence for exact body, no callers/xrefs/raw pointer/table/branch route, and `StringUtil` as semantic only.
- `StringUtil.md`: explicitly excludes `00022J` from attachment without caller, xref, raw pointer, table reference, or source-family evidence. Current IDA and raw PE evidence still do not provide that evidence.
- `StringBase.md`: documents the ref-counted string-buffer family and a separate `StringBaseAppendWideLiteral` child that calls shared string append code. `00022J` has no calls into that family, no refs from that family, and no StringBase metadata.
- `CachedHashTable.md`: documents a different hash/cache class with vtable/RTTI/lifecycle evidence. It has no direct link to this helper and its hash helper island is class-local at `0x004c62d0+`, not this free wide-string hash body.
- Neighbor docs: `RectAnchorTransformHelpers`, `FileExists`, `BuildFieldMapPath`, and `RectAnchorAxisAdjustHelper` show why nearby address order is not source ownership. Each neighbor has separate behavior and, where assigned, independent xref/caller evidence.
- Stale or historical text: the target page retains historical notes from before C001 created the IDA function object. Those are chronological evidence notes and are superseded by later target-page lines plus the current live IDA result; they do not require repair because the current status section and later change log are consistent.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Evidence for: exact function exists; behavior and range are well understood; no incoming xrefs; no callees; no raw VA/RVA/push pointer; no direct branch/call route; no source-use context; no table/vtable/global route; no direct source-family artifact.
- Evidence against: the function is source-shaped and semantically likely to belong to some utility code rather than hand-authored orphan assembly.
- Decision: retain this state. It is the only state that matches the current owner/emitter model without inventing unsupported source placement.

### 2. [UID:0000OB][StringUtil](../../../../../by-file/StringUtil.md)
- Evidence for: semantic fit. The helper takes a UTF-16 NUL-terminated string and computes a string hash using a recognizable `1000003` multiply/XOR recurrence. `StringUtil.cpp` is the broad Unicode/string utility source root in the proposed tree.
- Evidence against: no caller, data xref, raw VA/RVA pointer, branch route, table reference, source-file breadcrumb, or documented StringUtil child family ties this exact helper to `StringUtil`. The `StringUtil` page specifically says not to attach this UID from semantics alone.
- Decision: rejected as current canonical owner and emitter. It remains the best future candidate if real reference/source-family evidence appears.

### 3. [UID:0000OA][StringBase](../../../../../by-file/StringBase.md)
- Evidence for: broad string infrastructure owner, UTF-16 helper family, and current `util/StringBase.cpp` proposed root.
- Evidence against: this helper does not manipulate `StringBase` storage, sentinels, pool headers, ref counts, range compare helpers, format workers, or the documented `mystr::StringBase` metadata. It has no calls into or from the `0x00582500+` StringBase family.
- Decision: rejected.

### 4. [UID:0000HZ][CachedHashTable](../../../../../by-file/CachedHashTable.md)
- Evidence for: generic hash/cache utility domain.
- Evidence against: CachedHashTable has distinct class/vtable/layout evidence and its helper island is class-local around `0x004c62d0-0x004c64de`. `00022J` has no receiver, no vtable or RTTI relationship, no entry/slot state, no caller bridge, and hashes UTF-16 code units rather than CachedHashTable entries.
- Decision: rejected.

### 5. Nearby owners: RectBounds, PathUtil, FieldMapPane
- Evidence for: physical adjacency in `.text`.
- Evidence against: `RectBounds` owns the earlier/later anchor-transform and axis helpers through rectangle-layout behavior and internal xrefs; `PathUtil` owns `FileExists` through `_wfopen`/caller evidence; `FieldMapPane` owns `BuildFieldMapPath` through a constructor-only caller. None of those docs or live xrefs touch `0x004b81a0`.
- Decision: rejected. Address adjacency is weak evidence and is contradicted by mixed-owner neighbors in this exact neighborhood.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: none identified.
- Candidate related items rejected: the nearby geometry/path/FieldMap helpers are already separate, and the utility string/hash candidates lack direct evidence.
- Standalone, narrow, or broad source-file inference: a hidden or stripped utility source owner probably existed, but the current binary evidence does not prove which one.

## Negative Evidence Summary
- Checked and rejected direct IDA xrefs: `xrefs_to 0x004b81a0` is empty.
- Checked and rejected broader xref state: `xref_query both 0x004b81a0` only shows the internal flow edge to `0x004b81a1`.
- Checked and rejected raw literal routes: no little-endian VA `0x004b81a0`, no RVA `0x000b81a0`, and no `push 0x004b81a0` pattern in the PE.
- Checked and rejected direct executable branch routes: no executable-section rel8/rel32 branch or call targets the helper start.
- Checked and rejected table/vtable/global ownership: no data xrefs, no raw pointer hit, no vtable slot, no global page, and no by-file/source-family artifact points at this helper.
- Checked and rejected address adjacency: this address neighborhood is demonstrably mixed, with RectBounds, PathUtil, and FieldMapPane items separated by padding and independent xref evidence.
- Checked and rejected behavior-only ownership: wide-string hashing makes `StringUtil` plausible, but not provable under current rules.

## Final Recommendation
- Exact changes applied or recommended: no by-* documentation edits applied; no split/merge/rename/reclassify/score/code change recommended.
- Exact parent assignments applied or recommended: retain `CANONICAL_OWNER:NONE`.
- Exact emitter assignments applied or recommended: retain blank `EMITTER_UIDS` and blank `EMITTER_POSITION_OPTIONAL`.
- Exact items left no-owner/non-emitting and why: `00022J` remains no-owner/non-emitting because no direct owner or output route is proven by current IDA MCP, raw PE, or current documentation evidence.
- Exact future work outside this assignment scope: if future generated/imported code discovers a caller, function-pointer table, raw branch route, or source-family artifact, reopen the owner/emitter decision with `StringUtil` as the first candidate.

## Exact Supervisor-Owned Shared-Report Text
- `by-memory/-coverage-report.md`: no required replacement. The current row remains accurate and can be retained exactly:

```markdown
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : B003 second-pass review keeps `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`; C001-009 defined the exact raw body as IDA function `WideStringHashHelper`, and fresh PE/raw scans reconfirm isolated `0x4b` prologue/body/return range, adjacent `0xcc` padding, unique `wcslen` plus `1000003` wide-string hash recurrence, no callers/xrefs/raw VA/RVA pointer/table reference, no external branch/call route, and normal xrefs to adjacent FileExists/BuildFieldMapPath/RectAnchor helpers. `StringUtil` remains semantic only and no direct owner/emitter evidence is proven.
```

- Optional supervisor wording refresh only if current-pass provenance should be stamped into the shared report; not required for correctness:

```markdown
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : B002 2026-06-14 no-owner sweep keeps `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`; live IDA MCP session `b001_0003gy` reconfirms `WideStringHashHelper` as the exact `0x4b` function at `0x004b81a0-0x004b81eb`, adjacent `0xcc` padding, no incoming xrefs/callers/callees, unique `wcslen` plus `1000003` hash recurrence, and normal reference surfaces for neighboring FileExists/BuildFieldMapPath/RectAnchor helpers. Fresh raw PE scans find no VA/RVA pointer, no `push` pointer, no external direct branch/call route, and only the helper-local `69 D2 43 42 0F 00` multiply pattern at `0x004b81d6`; `StringUtil` remains semantic only and no direct owner or emitter route is proven.
```

- `auto-generated/-ag-memory-coverage.md`: no manual edit recommended. It is generated and currently reflects the correct state:

```markdown
| [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` |  |
```

## Follow-Up Actions
- Supervisor actions: mark this current B002 pass complete; no owner/emitter/code/split action required. If desired, apply the optional coverage-row provenance refresh above.
- A-agent actions: none.
- B002 future research actions: none for this target unless a new caller/source-use route appears in a future IDA/source-generation pass.

## Confidence
- Recommendation confidence: high. The no-owner/non-emitting result is backed by positive function/range evidence and repeated negative reference-route evidence.
- Score confidence: retain `88/92`. Completion is not raised because final source owner, output route, and original source name remain unresolved. Confidence remains high because the negative owner/emitter evidence is specific and current.
- Remaining uncertainty: the original source almost certainly had a logical owner, but the stripped binary and current docs do not prove it. The uncertainty is about source placement, not behavior or range.

## Validator Results
- Commands run: none.
- Results: not applicable. No by-* documentation files, generated reports, or validator-managed metadata were edited.
- Any unresolved validator warnings/errors introduced by this work: none.
- Dry runs: none used.

## Leases
- Leases acquired: none.
- Lease rationale: `goal.md` states no lease is needed for creating/updating research reports inside `Agent-B002/research`, and no leased-scope by-* file was edited.
- Lease state after work: no B002 active leases.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B002/research/00022J-WideStringHashHelper-current-no-owner-sweep.md`.
- Modified: none outside the created research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00022J-WideStringHashHelper-current-no-owner-sweep.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
