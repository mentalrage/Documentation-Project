** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022J WideStringHashHelper Current No-Owner Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_UIDS`.
- Final disposition: real reconstructable source-shaped helper function, currently ownerless and non-emitting because no caller, xref, raw pointer, table, vtable, source-family artifact, or output-use route is proven.
- Required action: no by-memory split, merge, reclassification, IDA rename repair, canonical owner assignment, emitter assignment, C++ entry, or shared coverage-report edit is recommended from this pass.
- Confidence: high for behavior, range, IDA function identity, no-reference state, and rejected candidate owners; medium-high for the original source explanation because the binary exposes no source-file breadcrumb.

## Supporting Research

## Target

- Target UID: `00022J`
- Target path: `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`
- Source queue/report row: current `auto-generated/-ag-memory-coverage.md` no-owner row for `0x004b81a0-0x004b81eb.WideStringHashHelper`.
- Current supervisor classification: Goal 2 current no-owner memory research, assigned by user priority change.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.

## Executive Recommendation

The best current disposition is unchanged: keep the helper as a reconstructable but ownerless/non-emitting exact by-memory function. The function is not padding or an aggregate; IDA now models it as `WideStringHashHelper` at `0x004b81a0`, size `0x4b`, with surrounding `0xcc` padding and a complete UTF-16 hash body. However, the owner/emitter gate is not satisfied. `StringUtil` remains the best semantic candidate, but the only positive link is the wide-string hash behavior. `by-structure.md` requires direct semantic ownership and separate output routing evidence; behavior-only affinity is not enough.

No C++ should be entered or recommended. The item is below the active `90/90+` code-entry gate for output purposes because completion is `88`, the owner/emitter route is unproven, and no source placement is defensible.

## Supervisor Active Recheck

- Trigger: user-assigned Goal 2 B-agent pass for `[UID:00022J] by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`.
- Current generated state rechecked: `auto-generated/-ag-memory-coverage.md` lists this item as `no-owner`, owner `NONE`, blank emitters, non-emitting.
- Split requirement: no split repair is needed. Current IDA and byte evidence show one exact function from `0x004b81a0` through the `retn` at `0x004b81ea`, followed by padding at `0x004b81eb-0x004b81f0`.
- Direct repair requirement: no in-scope by-memory edit is needed. The target already records the same current no-owner/non-emitting conclusion and the IDA-safe function name is already present.

## Inference Research Guidance Check

- `by-structure.md` separates `CANONICAL_OWNER` from `EMITTER_UIDS`. A reconstructable item may remain ownerless and non-emitting when source-owned code is real but no owner/output route is proven.
- `by-structure.md` also allows `CANONICAL_OWNER:NONE` with emitters for pooled/shared literals or constants when source-use contexts are proven. That model does not apply here because no consumer or source-use context is proven.
- `inference_research.md` treats adjacency as weak evidence and xrefs/callers/raw references as stronger evidence. Here, adjacency points to several unrelated neighbors, while direct xref and raw-reference evidence is negative.
- Existing target and prior reports were used as leads only. The current recommendation rests on fresh IDA MCP and PE/raw checks plus current by-* documentation.

## Evidence Standards Used

- IDA MCP: `server_health`, `lookup_funcs`, `entity_query`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `get_bytes`, and `find_bytes`.
- Raw PE scan: section-aware scan of `NexusTK.exe` for absolute VA literals, RVA literals, `E8/E9` rel32 direct calls/jumps, rel32 conditional branches, short branches, and the unique `imul edx, 0x0f4243` byte pattern.
- Documentation evidence: current target page, generated coverage row, manual coverage row, `StringUtil`, `StringBase`/string-family project-tree notes, `CachedHashTable`, `RectBounds`, `PathUtil`, `FileExists`, `BuildFieldMapPath`, rect-anchor helper pages, and padding ledger.
- Negative evidence is assignment-blocking, not behavior-blocking: it prevents owner/emitter routing but does not make the function unreal or non-reconstructable.

## IDA MCP Facts

- Active IDB: `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, IDB path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.
- Function/range facts: `lookup_funcs` reports `WideStringHashHelper` at `0x004b81a0`, size `0x4b`; no function at `0x004b8194`, `0x004b81eb`, or `0x004b821e`; adjacent modeled starts are `sub_4B81F0` at `0x004b81f0`, `sub_4B8220` at `0x004b8220`, and `sub_4B8290` at `0x004b8290`.
- Data/table/padding facts: `get_bytes 0x004b8194 size 12` returns twelve `0xcc` bytes; `get_bytes 0x004b81eb size 5` returns five `0xcc` bytes. The four bytes at `0x004b8190-0x004b8193` are predecessor local switch-table data, so the corrected padding begins at `0x004b8194`.
- Behavior facts: Hex-Rays decompiles `unsigned int __cdecl WideStringHashHelper(const unsigned __int16 *a1)`, computes `wcslen(a1)`, seeds from `*a1 << 7`, loops with `v5 ^ (1000003 * v3)`, and returns `length ^ hash`.
- Disassembly facts: one argument is read from `[ebp+arg_0]`; the loop scans 16-bit words until zero; `imul edx, 0F4243h` is at `0x004b81d6`; the body has no calls, no global reads/writes, no allocation, and returns at `0x004b81ea`.
- Xref facts: `xrefs_to 0x004b81a0` reports zero incoming xrefs. `xref_query both 0x004b81a0` reports only the internal fall-through/code-flow edge from `0x004b81a0` to `0x004b81a1`, not a caller or data/table reference.
- Adjacent contrast: `xrefs_to 0x004b81f0` reports calls at `0x0049c87c`, `0x0049c88f`, and `0x004dbcb5`; `xrefs_to 0x004b8220` reports the FieldMapPane constructor call at `0x004b0c0d`; `xrefs_to 0x004b8290` reports four rect-anchor code refs at `0x004b803e`, `0x004b809f`, `0x004b80ff`, and `0x004b8161`.
- Pattern facts: IDA `find_bytes` finds no `A0 81 4B 00` VA literal and no `A0 81 0B 00` RVA literal. It finds `69 D2 43 42 0F 00` only at `0x004b81d6` and the immediate bytes `43 42 0F 00` only at `0x004b81d8`.

## PE / Raw Evidence

Section-aware scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

| Target | VA/RVA literal hits | rel32 branch/call hits | short branch hits |
| --- | --- | --- | --- |
| `0x004b81a0` | none | none | none |
| `0x004b81f0` | none | `0x0049c87c`, `0x0049c88f`, `0x004dbcb5` | none |
| `0x004b8220` | none | `0x004b0c0d` | none |
| `0x004b8290` | none | `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161` | none |

The raw scan independently supports the IDA xref conclusion and shows the reference gap is specific to `0x004b81a0`, not a scanner failure in the surrounding address neighborhood.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b8194-0x004b81a0` | `0000VN` / `by-memory/-ignored.md` | Alignment padding after rect-anchor local table | false/ignored | none | `100/strong` | No change |
| `0x004b81a0-0x004b81eb` | `00022J` / target page | UTF-16 rolling hash helper | true | `NONE` | `88/92` | Keep no-owner/non-emitting |
| `0x004b81eb-0x004b81f0` | `0000VN` / `by-memory/-ignored.md` | Alignment padding before `FileExists` | false/ignored | none | `100/strong` | No change |
| `0x004b81f0-0x004b821e` | `00022K` / `FileExists` | Wide-path `_wfopen` existence helper | true | `0000MI` PathUtil | `88/90` | Neighbor only |
| `0x004b8220-0x004b8284` | `00015U` / `BuildFieldMapPath` | FieldMapPane path-stem copy helper | true | `0000JA` FieldMapPane | `84/88` | Neighbor only |
| `0x004b8290-0x004b83c5` | `00022L` / `RectAnchorAxisAdjustHelper` | Rect anchor axis primitive plus local switch data | true | `0000N2` RectBounds | `86/88` | Neighbor only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b81a0` | IDA incoming xrefs: zero | No proven caller, table, or data reference |
| `0x004b81a0` | Raw PE VA/RVA/direct-branch hits: zero | No hidden direct output-use route found in file bytes |
| `0x004b81d6` | unique `imul edx, 0x0f4243` pattern | Hash behavior is unique in this executable |
| `0x004b81f0` | calls at `0x0049c87c`, `0x0049c88f`, `0x004dbcb5` | Adjacent path helper has normal owner evidence |
| `0x004b8220` | call at `0x004b0c0d` | Adjacent FieldMapPane helper has normal owner evidence |
| `0x004b8290` | calls from `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161` | Rect-anchor axis helper is tied to the preceding geometry cluster |

## Documentation Evidence And IDA Status

- Target page status: already records `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:TRUE`, exact range, behavior, padding, no-reference state, and rejected owner candidates. Current IDA confirms the important facts.
- Generated coverage status: `auto-generated/-ag-memory-coverage.md` currently lists the item as `no-owner`, owner `NONE`, blank emitters, non-emitting. That is consistent with this pass.
- Manual coverage status: `by-memory/-coverage-report.md` row states B003 kept no-owner/blank emitters and cites C001 IDA function definition, unique recurrence, no callers/xrefs/raw VA/RVA pointer/table reference, and normal adjacent helper xrefs. That row remains accurate.
- `StringUtil.md`: broad string utility file is the best semantic candidate, but it explicitly excludes `00022J` from attachment without caller/xref/raw pointer/table/source-family evidence. Current IDA still does not provide that evidence.
- `RectBounds.md` and rect-anchor pages: document the neighboring geometry cluster and corrected padding at `0x004b8194-0x004b81a0`; the geometry xrefs go to `0x004b8290`, not through the hash helper.
- `PathUtil.md` and `FileExists.md`: support `FileExists` as the successor path helper, but that owner evidence is based on `_wfopen` behavior and concrete calls, neither of which applies to `00022J`.
- Prior B002/B001 reports: read as background only. Their no-owner conclusion is independently confirmed by the current IDA MCP and PE/raw pass.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`

- Evidence for: exact isolated helper body; no incoming xrefs; no raw VA/RVA pointer; no direct branch/call encoding; no table/vtable/source-use context; no calls or globals; adjacent helpers have positive xrefs, proving the absence is local to this helper.
- Evidence against: the helper is source-shaped and likely came from some utility source originally; leaving it no-owner does not recover that original file.
- Decision: accepted. This is the only defensible current state under by-structure rules.

### 2. [UID:0000OB] `StringUtil`

- Evidence for: strongest semantic fit. The helper hashes a NUL-terminated UTF-16 string and `StringUtil` owns broad Unicode/string infrastructure.
- Evidence against: no caller, xref, source-family artifact, string class layout dependency, table entry, global, or raw pointer ties this address to `StringUtil`. The page's own scope exclusion says not to attach this UID from semantics alone.
- Decision: rejected as canonical owner and emitter for now. If forced to choose a best future owner, `StringUtil` would be first to revisit, but current evidence is below the gate.

### 3. [UID:0000OA] `StringBase` / string-buffer family

- Evidence for: UTF-16 data handling and wide string length behavior.
- Evidence against: no `mystr::StringBase` receiver, buffer header, ref-count state, sentinel, pool, COW path, template RTTI, or `StringBase` object layout appears in the function. It takes a raw wide pointer and returns a scalar hash.
- Decision: rejected.

### 4. [UID:0000HZ] `CachedHashTable`

- Evidence for: broad utility/hash domain and existing `CachedHashTable.cpp` source candidate.
- Evidence against: documented CachedHashTable code is a separate class/vtable/helper island around `0x004c6160-0x004c659c`, with object state and RTTI. No current doc or IDA evidence links it to this UTF-16 pointer hash function.
- Decision: rejected.

### 5. [UID:0000N2] `RectBounds`

- Evidence for: physical adjacency to rect-anchor transform code and later rect-anchor axis helper.
- Evidence against: `00022J` reads UTF-16 words and computes a scalar hash; it does not read/write four-int rect records. RectBounds' positive evidence is the geometry helper layout and the internal calls to `0x004b8290`, not the intervening hash helper.
- Decision: rejected. Proximity alone is too weak.

### 6. [UID:0000MI] `PathUtil` / [UID:0000JA] `FieldMapPane`

- Evidence for: immediate successor helpers are owned by these files.
- Evidence against: `00022J` does not open files, copy path stems, append `.EPF`, touch caller buffers, call CRT file APIs, or have either helper's caller set.
- Decision: rejected as owner and emitter.

### 7. New `util/StringHash.cpp` or external/library hash owner

- Evidence for: the `1000003` multiply/XOR recurrence resembles known string-hash idioms, and a narrow hash utility file would be plausible if related code existed.
- Evidence against: no related helpers, tables, names, imports, source strings, version marker, source-family docs, or consumers are present. The body also lacks a sentinel repair that would prove a specific external implementation. Creating a new file for one unreferenced helper would invent source structure.
- Decision: do not create a new owner/file/grouping.

## Negative Evidence Summary

- No incoming IDA xrefs to `0x004b81a0`.
- No raw VA or RVA dword literal for `0x004b81a0` / `0x000b81a0`.
- No `E8/E9` rel32 branch/call, rel32 conditional branch, or short branch to the target in the executable `.text` section.
- No vtable slot, callback table, source-local table, import, string, or global reference found for this address.
- No `StringUtil`/`StringBase` object evidence, no CachedHashTable object evidence, no RectBounds geometry evidence, no PathUtil file-open evidence, and no FieldMapPane path-buffer evidence appears in the target body.
- Existing neighborhood evidence is not ambiguous: the surrounding helpers each have their own distinct owner/caller evidence, while this one does not.

## Final Recommendation

- Exact changes applied or recommended: no by-* documentation changes applied. Keep target metadata unchanged.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:NONE`; do not assign `0000OB`, `0000OA`, `0000HZ`, `0000N2`, `0000MI`, `0000JA`, or a new source file.
- Exact emitter assignments applied or recommended: keep `EMITTER_UIDS:` blank. There are no proven source-use contexts and no file/class output route.
- Exact split/merge/reclassification recommendation: none. Keep one exact function page at `0x004b81a0-0x004b81eb`, with neighboring padding and helper pages separate.
- IDA-safe name recommendation: no repair needed. Current IDA name `WideStringHashHelper` is descriptive and already applied, but it should be treated as an inferred documentation/IDA name, not proven original source spelling.
- C++ recommendation: keep `RECONSTRUCTION_CPP CODE` blank. The active `90/90+` code-entry gate is not met for source-output purposes.

## Supervisor-Owned Shared-Report Text

No `by-memory/-coverage-report.md` edit is recommended. The current row may remain as-is:

```markdown
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : B003 second-pass review keeps `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`; C001-009 defined the exact raw body as IDA function `WideStringHashHelper`, and fresh PE/raw scans reconfirm isolated `0x4b` prologue/body/return range, adjacent `0xcc` padding, unique `wcslen` plus `1000003` wide-string hash recurrence, no callers/xrefs/raw VA/RVA pointer/table reference, no external branch/call route, and normal xrefs to adjacent FileExists/BuildFieldMapPath/RectAnchor helpers. `StringUtil` remains semantic only and no direct owner/emitter evidence is proven.
```

No `auto-generated/-ag-memory-coverage.md` manual edit is allowed or needed. Its current generated row is also consistent:

```markdown
| [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` |  |
```

## Follow-Up Actions

- Supervisor actions: none for shared reports unless the tracker requires recording this B002 current-pass decision.
- A-agent actions: do not attach or emit this helper unless new direct evidence appears. If a future pass finds a caller/table/source artifact, revisit `StringUtil` first, then a narrow string-hash utility grouping.
- B002 future research actions: only reopen this target if another no-owner memory item exposes a string/hash source island, callback table, or raw pointer to `0x004b81a0`.

## Confidence

- Recommendation confidence: high for keeping no-owner/blank emitters.
- Score confidence: keep existing `88/92`; behavior and boundary are strong, but owner/output route remains unresolved.
- Remaining uncertainty: original source file and original helper name. The uncertainty is evidentiary, not a workflow blocker.

## Validator Results

- Commands run: none.
- Results: not applicable. No by-* documentation files were edited, no split was performed, and no validator-managed metadata changed.
- Dry runs: none.
- Any unresolved validator warnings/errors introduced by this work: none.

## Lease State

- Lease report checked: `tools/leaser/Agents/current_leases.md`.
- Leases taken: none.
- Leases released: none needed.
- Rationale: this pass created only a report under `Agent-B002/research`; no leased-scope by-* documentation was edited.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/00022J-WideStringHashHelper-current-no-owner-recheck.md`
- Modified: none outside the created report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00022J-WideStringHashHelper-current-no-owner-recheck.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
