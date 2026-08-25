** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022J WideStringHashHelper Live Goal 2 No-Owner Pass

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](../../../../../by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Final disposition: complete-no-change for ownership/routing. This is a real source-authored/reconstructable helper body, but the current binary exposes no caller, code xref, data xref, raw VA/RVA pointer, branch target, table/vtable route, or source-use context. No canonical owner and no emitter are therefore the correct current state.
- Required action: no split, no child pages, no target metadata edit, and no required `by-memory/-coverage-report.md` row change. If the supervisor wants provenance refreshed, use the optional coverage row text in this report; do not route or emit this helper until new evidence identifies a real source-use path.
- Confidence: high for keeping no-owner/non-emitting under the current rules; medium-high for `RECONSTRUCTABLE:TRUE` because the function is custom source-like code in `.text`, but final original source ownership remains unproven by design.

---

## Supporting Research

## Target

- Target UID: `00022J`
- Target path: `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` still reports `no-owner`, canonical owner `NONE`, blank emitters, no generated output path.
- Current supervisor classification: active 2026-06-14 live Goal 2 no-owner memory pass in `tools/leaser/Agents/no_owner_b-agent-tracker.md`, assigned to Agent-B002 with current report path `Agent-B002/research/00022J-WideStringHashHelper-live-goal2-no-owner-pass.md`.
- Current scores and parent state: target page is `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.

## Executive Recommendation

The best current direct disposition is no canonical owner and no emitters. The helper is exactly bounded and behaviorally understood, but every owner/emitter candidate depends on semantics or address proximity rather than a source-use route.

`StringUtil` [UID:0000OB] is the best semantic candidate if forced, because this is a UTF-16 string hash helper and `StringUtil.cpp` already owns broad Unicode utility infrastructure. It is still too weak to assign: live IDA has no caller, no data reference, no raw pointer/table reference, and no source-family artifact tying this specific body to `StringUtil` or any other source root. The current `StringUtil` page explicitly excludes `00022J` for that reason, and the fresh pass confirms the exclusion remains correct.

No split is needed. The assigned range is a single 0x4b-byte function with only alignment padding before and after; no nested table, child function, vtable, literal, or mixed-owner data exists inside `0x004b81a0-0x004b81eb`.

## Supervisor Active Recheck

- Trigger: the tracker's "Active 2026-06-14 Live Goal 2 No-Owner Memory Pass" assigns `00022J` to Agent-B002 and requires a fresh check of no-owner/non-emitting generated memory rows.
- Split repair: not required. Live IDA and byte evidence show one exact function body, preceded by `0xcc` padding at `0x004b8194-0x004b81a0` and followed by `0xcc` padding at `0x004b81eb-0x004b81f0`.
- Source-bearing children: none to create. The whole source-bearing body is the existing `00022J` page.

## Inference Research Guidance Check

`by-structure.md` separates semantic ownership from generated-output routing. It allows `RECONSTRUCTABLE:TRUE` with no owner/emitter while a source-authored item is confirmed but the owner or emitter route is not ready. It also warns not to fill `EMITTER_UIDS` or add C++ just because ownership is plausible.

`inference_research.md` cautions that adjacency and broad semantic fit are weaker than xrefs, initialization/write sites, constructors/destructors, and source-family artifacts. That matters here because the only positive owner hints are the helper's string-hash behavior and its physical placement among unrelated utility/geometry/path helpers. Those are insufficient against the negative xref and raw pointer evidence.

Facts, documentation evidence, and inference are separated below. Existing reports were treated as leads only; the decisive evidence in this pass is the live IDA MCP and PE/raw scan on 2026-06-14.

## Evidence Standards Used

- IDA MCP tools used: `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `find` for `code_ref`/`data_ref`/`immediate`, `find_bytes`, `callees`, `get_bytes`, and `analyze_function`.
- Supplemental PE/raw check: local scan of the exact IDA-reported binary `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, for VA/RVA pointers and raw rel8/rel32 branches/calls to `0x004b81a0`.
- Documentation evidence: current target page, `StringUtil`, `CachedHashTable`, `RectBounds`, `PathUtil`, `proposed-source-tree.md`, `auto-generated/-ag-memory-coverage.md`, `by-memory/-coverage-report.md`, and the active tracker.
- Strength: strong enough to reject owner/emitter assignment now. The only blocker to stronger final confidence is the inherent absence of source/debug metadata or any source-use reference for an otherwise valid retained helper.

## IDA MCP Facts

- Function/range facts: live `lookup_funcs` reports `WideStringHashHelper` at `0x004b81a0`, size `0x4b`. `0x004b8194`, `0x004b8198`, and `0x004b81eb` are not functions. Adjacent modeled starts remain `sub_4B81F0` at `0x004b81f0`, `sub_4B8220` at `0x004b8220`, and `sub_4B8290` at `0x004b8290`.
- Decompilation facts: Hex-Rays returns `unsigned int __cdecl WideStringHashHelper(const unsigned __int16 *a1)`, computes `wcslen(a1)`, seeds `*a1 << 7`, loops with `v5 ^ (1000003 * v3)`, and returns `length ^ hash`.
- Disassembly facts: the body saves `esi`/`edi`, scans 16-bit units until a zero word, uses `imul edx, 0F4243h` at `0x004b81d6`, has no calls, no global reads/writes, and returns at `0x004b81ea`.
- Data/table/padding facts: `get_bytes` confirms `0x004b8194-0x004b81a0` is twelve `0xcc` bytes, `0x004b81a0-0x004b81eb` is the exact 75-byte body, `0x004b81eb-0x004b81f0` is five `0xcc` bytes, and `0x004b81f0` begins the next prologue.
- Xref facts: `xrefs_to`, `xref_query`, and `analyze_function` report zero incoming xrefs/callers to `0x004b81a0`. `callees` reports an empty callee list. `xref_query` from the function reports only the internal code-flow xref at `0x4b81a1`.
- Negative IDA facts: `find code_ref 0x004b81a0` returns zero; `find data_ref 0x004b81a0` returns zero; `find immediate` for decimal `4956576` (`0x004b81a0`) and `754080` (`0x000b81a0`) returns zero.
- Contrast facts: the no-reference result is local to this helper. `FileExists` at `0x004b81f0` has code refs at `0x49c87c`, `0x49c88f`, and `0x4dbcb5`; `BuildFieldMapPath` at `0x004b8220` has one code ref at `0x4b0c0d`; `RectAnchorAxisAdjustHelper` at `0x004b8290` has four code refs from the rect-anchor raw cluster at `0x4b803e`, `0x4b809f`, `0x4b80ff`, and `0x4b8161`.
- Uniqueness facts: `find immediate 1000003` returns only `0x4b81d6`. `find_bytes "69 d2 43 42 0f 00"` returns only `0x4b81d6`; `find_bytes "43 42 0f 00"` returns only `0x4b81d8`.
- Raw PE facts: the exact IDA-reported PE has no little-endian `0x004b81a0` VA bytes, no little-endian `0x000b81a0` RVA bytes, no raw rel32 `call`/`jmp` target to `0x004b81a0`, and no raw rel8 branch target to `0x004b81a0`. The same raw scan finds the `imul 1000003` encoding only at VA `0x004b81d6`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b8194-0x004b81a0` | `by-memory/-ignored.md` | alignment padding before helper | false/ignored | none | `100/strong` in coverage row | no child needed |
| `0x004b81a0-0x004b81eb` | `00022J` / `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` | UTF-16 rolling hash helper | true | none | `88/92` | keep no-owner/non-emitting |
| `0x004b81eb-0x004b81f0` | `by-memory/-ignored.md` | alignment padding after helper | false/ignored | none | `100/strong` in coverage row | no child needed |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b81a0` | zero incoming xrefs, zero callers, zero callees | no owner/source-use proof |
| `0x004b81a1` | only internal function-flow xref reported from `0x004b81a0` | not an external route |
| `0x004b81d6` | unique `imul edx, 0F4243h` / decimal `1000003` site | identifies algorithm, not owner |
| `0x004b81f0` | code refs from `0x49c87c`, `0x49c88f`, `0x4dbcb5` | adjacent path helper has normal references, unlike target |
| `0x004b8220` | code ref from `0x4b0c0d` | adjacent field-map path helper has a normal caller |
| `0x004b8290` | refs from `0x4b803e`, `0x4b809f`, `0x4b80ff`, `0x4b8161` | rect-anchor helper route stays within RectBounds cluster |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: the target page already records exact behavior, C001 function creation, no caller/xref state, raw pointer absence, and rejected parent candidates. The fresh 2026-06-14 pass reconfirms those material claims against current IDA and the current PE.
- Current `StringUtil` documentation explicitly excludes `00022J` from attachment unless a caller, xref, raw pointer, table reference, or source-family artifact appears. The fresh IDA/PE evidence does not provide one.
- `CachedHashTable` is a distinct class/vtable/helper island at `0x004c6160-0x004c659c`; it has no constructor/helper/vtable/table link to this helper. Its current completion is also `84`, below the strict direct-parent gate even if evidence existed.
- `RectBounds` owns the nearby geometry/anchor helpers, but live xrefs show the rect-anchor flow calls `0x004b8290` from the `0x004b7f90-0x004b8194` cluster and never touches `0x004b81a0`. The hash helper is separated by padding and unrelated behavior.
- `PathUtil` owns the adjacent `FileExists` helper at `0x004b81f0` and the later stat-based path probe. This target has no file/path behavior and no xrefs to or from those helpers.
- Generated/coverage report state: generated memory coverage lists `00022J` as `no-owner` with `NONE` and blank emitters; by-memory coverage row already describes the no-owner/non-emitting decision and evidence.
- Existing documentation caveat: some historical rows in older reports predate C001's IDA function creation. Current IDA now models `WideStringHashHelper` as a function; that does not create owner or emitter evidence.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`

- Evidence for: zero incoming xrefs/callers, zero callees, no code/data refs, no VA/RVA pointer bytes, no raw branch/call route, no source-family table/vtable/use context, exact isolated body, and adjacent helpers having normal references while this one does not.
- Evidence against: the body is source-like and semantically string-related, so `StringUtil` remains a tempting semantic home.
- Decision: accepted. Under `by-structure.md`, reconstructable confirmed source code may remain no-owner/non-emitting while no direct owner or output route is proven. This is not a pooled literal with multiple proven consumers; it has no proven consumers at all.

### 2. [UID:0000OB] `StringUtil`

- Evidence for: UTF-16 input, `wcslen`-style scan, broad string utility semantics, and proposed source tree already containing `util/StringUtil.cpp`.
- Evidence against: no caller, xref, raw pointer, table reference, source symbol, or related helper family ties this exact body to `StringUtil`. The algorithm's `1000003` recurrence is unique in the binary and not clustered with documented `SimpleUString`, `StringBase`, `StringIter`, or wide-format helper bodies. Current `StringUtil` docs explicitly reject this attachment without a stronger source-family link.
- Decision: rejected for assignment/emission now. If forced to pick a semantic parent, this is the least bad candidate, but the current rules require more than semantic fit.

### 3. New `HashUtil` / `StringHashUtil` source file

- Evidence for: the helper is a standalone string-hash function and the proposed tree has other utility algorithm files such as MD5/CRC-style helpers.
- Evidence against: no other related string-hash helper, no table data, no call site, no source name, no adjacent hash family, and no owner-specific route. Creating a one-item source file would invent original structure from an unreferenced function.
- Decision: rejected. No new owner/file/grouping is justified.

### 4. [UID:0000N2] `RectBounds`

- Evidence for: address proximity. The target sits between documented RectBounds anchor-transform support and the later axis-adjust helper.
- Evidence against: the function reads UTF-16 strings and hashes them; it does not touch four-int rectangle layouts, anchor indices, switch data, or geometry callers. The surrounding rect-anchor cluster has its own xrefs to `0x004b8290` and no xrefs to `0x004b81a0`. Padding separates the helper from both neighbors.
- Decision: rejected. Proximity is linker/layout evidence only, not direct ownership proof.

### 5. [UID:0000MI] `PathUtil`

- Evidence for: immediate successor `0x004b81f0` is an assigned PathUtil `FileExists` helper.
- Evidence against: target has no path, file, CRT dispatch, `_wfopen`, `_wstat`, archive, DAT, or caller overlap evidence. It has no reference edge to `FileExists`.
- Decision: rejected.

### 6. [UID:0000HZ] `CachedHashTable`

- Evidence for: the word "hash" and a generic cached hash table source root exist in `util/`.
- Evidence against: `CachedHashTable` has its own class lifecycle/vtable/helper island far away at `0x004c6160+`; this helper has no object layout, vtable, constructor, table, fixed-entry buffer, or xref relationship to that class. Parent completion is also below the strict `85/85` gate.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none recommended.
- Likely full contents: no evidence supports a broader file. The only candidate content is the single unreferenced function, which is not enough to create a new source root.
- Candidate related items that belong: none identified by current IDA. The `1000003` immediate and encoding are unique; no sibling hash recurrence exists.
- Candidate related items rejected: `StringUtil` helper families, `CachedHashTable`, RectBounds geometry helpers, `PathUtil` file probes, MD5/CRC algorithm utilities. They all have their own evidence clusters and no reference edge to this body.
- Standalone, narrow, or broad source-file inference: no new source-file inference is defensible.

## Negative Evidence Summary

- No IDA incoming xrefs to `0x004b81a0`.
- No IDA caller list for `WideStringHashHelper`.
- No IDA callees from `WideStringHashHelper`.
- No IDA `code_ref` or `data_ref` matches for `0x004b81a0`.
- No IDA immediate matches for `0x004b81a0` or RVA `0x000b81a0`.
- No byte matches for little-endian VA `a0 81 4b 00` or RVA `a0 81 0b 00`.
- No raw PE rel32 `call`/`jmp` target to `0x004b81a0`.
- No raw PE rel8 branch target to `0x004b81a0`.
- No vtable/table/global/string/source artifact references the helper.
- No adjacent-owner route: RectBounds, PathUtil, and FieldMap/path neighbors have their own normal reference surfaces; the gap is specific to this helper.

## Why Reconstructable But Non-Emitting Is Correct

The helper should stay `RECONSTRUCTABLE:TRUE` because it is not padding, CRT glue, import plumbing, vtable data, RTTI, compiler adjustor code, or a known third-party/runtime routine. It is a real `.text` function with a normal prologue/epilogue, a custom UTF-16 rolling hash body, and exact behavior that would need a source-level representation if the original source unit were later recovered.

Blank `EMITTER_UIDS` is still correct because emitter routing is not a statement that "the code is unimportant"; it is the generated-output path. `by-structure.md` requires a proven route to a valid source root before emitted C++ is added. Here there is no source-use context at all. Unlike pooled strings/constants with multiple proven consumers, this function has zero proven consumers, so assigning one or more emitters would be speculative. Emitting it through `StringUtil` would make generated source look more complete while encoding an ownership claim the binary does not support.

This is therefore a valid no-owner/non-emitting reconstructable item: understood and retained for audit/binary completeness, but withheld from generated source until an actual owner or emitter route appears.

## Final Recommendation

- Exact changes applied or recommended: no by-memory target edit, no split, no child page creation, no owner/emitter change.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:NONE`.
- Exact emitter assignments applied or recommended: keep `EMITTER_UIDS` blank.
- Exact coverage-report row text: no required semantic change. Optional provenance refresh, if the supervisor wants the row to reflect this live pass:

```text
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : B002 live Goal 2 pass on 2026-06-14 keeps `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`; live IDA MCP against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` confirms modeled function `WideStringHashHelper` at `0x004b81a0` size `0x4b`, exact UTF-16 `wcslen`/`1000003` rolling hash body, no callers/xrefs/callees/code refs/data refs/VA or RVA immediates, unique `1000003` immediate and encoding, exact adjacent `0xcc` padding, normal references to adjacent FileExists/BuildFieldMapPath/RectAnchor helpers, and no raw PE pointer or rel8/rel32 branch route to the helper. `StringUtil` remains the best semantic candidate but no direct owner or emitter evidence is proven.
```

- Exact future work outside this assignment scope: revisit only if a future pass finds an indirect table, raw pointer, source symbol, import/debug artifact, or a newly recovered caller that references `0x004b81a0`.

## Follow-Up Actions

- Supervisor actions: mark the live pass complete-no-change if accepting this report; optionally refresh the by-memory coverage row text above during supervisor-owned coverage maintenance.
- A-agent actions: none required.
- B002 future research actions: if future string/hash/container work uncovers a caller or source-family link, re-evaluate in this order: `StringUtil`, `StringBase`, a narrow hash utility source, then only weaker proximity candidates.

## Confidence

- Recommendation confidence: high. The negative owner/emitter evidence is direct and current.
- Score confidence: current `88/92` remains justified. No score change is recommended because behavior and boundaries are strong, while source ownership is intentionally unresolved.
- Remaining uncertainty: original source provenance cannot be proven without a caller, pointer/table reference, source/debug artifact, or matching source package evidence. That uncertainty blocks owner/emitter routing but does not block the no-owner/non-emitting recommendation.

## Validator Results

- Commands run: none.
- Results: no validation needed because no by-* documentation, target metadata, coverage report, or split child page was edited.
- Any unresolved validator warnings/errors: not checked in this pass; generated memory coverage already lists the item as no-owner/non-emitting and this report recommends no structural change.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/00022J-WideStringHashHelper-live-goal2-no-owner-pass.md`
- Modified: none outside this Agent-B002 research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00022J-WideStringHashHelper-live-goal2-no-owner-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
