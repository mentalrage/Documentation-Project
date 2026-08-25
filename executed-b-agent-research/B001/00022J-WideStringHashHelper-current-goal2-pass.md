** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022J WideStringHashHelper Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00022J] `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, with blank `EMITTER_UIDS` and blank reconstruction C++.
- Final disposition: exact source-shaped UTF-16/wide-string hash helper with strong boundary and behavior evidence, but no current direct source-owner or output-route evidence.
- Required action: no metadata change, no coverage row replacement, no split, no merge, no reclassification, no IDA repair, and no reconstruction C++ entry.
- Confidence: high for the no-owner/non-emitting recommendation. `StringUtil` remains the best semantic candidate, but it is still behavior-only and blocked by the direct-owner evidence gate.

Retain the current target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No `by-memory/-coverage-report.md` edit is required. If the supervisor wants the current retained row restated, keep this exact row:

```text
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : B003 second-pass review keeps `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`; C001-009 defined the exact raw body as IDA function `WideStringHashHelper`, and fresh PE/raw scans reconfirm isolated `0x4b` prologue/body/return range, adjacent `0xcc` padding, unique `wcslen` plus `1000003` wide-string hash recurrence, no callers/xrefs/raw VA/RVA pointer/table reference, no external branch/call route, and normal xrefs to adjacent FileExists/BuildFieldMapPath/RectAnchor helpers. `StringUtil` remains semantic only and no direct owner/emitter evidence is proven.
```

The current generated no-owner row is also correct:

```text
| [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` |  |
```

## Supporting Research

## Target

- Target UID: `00022J`
- Target path: `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`
- Source queue/report row: current `auto-generated/-ag-memory-coverage.md` no-owner row for `00022J`.
- Current supervisor classification: current Goal 2 no-owner memory pass assigned to Agent-B001 by user instruction; `tools/leaser/Agents/no_owner_b-agent-tracker.md` also has `00022J` current-pass/pending context plus older complete-no-change history.
- Prior report reviewed as background: `tools/leaser/Agents/Agent-B001/research/executed/00022J-WideStringHashHelper-post-migration-recheck.md`; older B001 and B003 reports were also checked for prior evidence and stale assumptions.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.

## Executive Recommendation

Keep `00022J` as a single exact reconstructable no-owner/non-emitting function. The helper is source-shaped code: it has a normal `cdecl` prologue/epilogue, one raw UTF-16 pointer argument, no callees, no globals, no writes, clean padding before and after, and a fully understood wide-string hash loop.

Do not attach it to `StringUtil`, `StringBase`, `CachedHashTable`, `RectBounds`, `PathUtil`, `FieldMapPane`, `GeneralPurposePanel`, or a new source file from current evidence. The blocker is not behavior recovery; it is routing. Current IDA and raw PE evidence still show no caller, code/data xref, raw VA/RVA pointer, function pointer table, callback table, vtable slot, source symbol, import, or source-family artifact that proves a direct owner or an emitter.

Do not add reconstruction C++. The page is `88/92`, so completion is below the current `90/90+` code-entry gate, and the required owner/emitter route is absent.

The exact condition that would change this recommendation is a real source-use artifact: a direct call, indirect table pointer, raw VA/RVA pointer in data, source/debug/name breadcrumb, repeated owner-specific sibling pattern, or recovered caller passing UTF-16 keys from a proven string/hash container context.

## Supervisor Active Recheck

The supervisor/user requested exactly one current Goal 2 no-owner memory recheck for [UID:00022J], asking whether it should remain `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS`, gain an owner or emitters, be split/merged/reclassified, or require repair.

Recheck result:

- Split repair required: no. `0x004b81a0-0x004b81eb` is one exact `0x4b` function.
- Merge/container repair required: no. The neighboring rect, path, field-map, and panel helpers have separate documented owners and evidence.
- IDA repair required: no. The IDB already models `WideStringHashHelper` at `0x004b81a0`, size `0x4b`.
- Owner/emitter repair required: no. No candidate clears the direct evidence gate.
- Score change required: no. Keep `88/92`.
- Coverage-report change required: no. Retain the current shared row quoted above.

## Inference Research Guidance Check

IDA fact: the current IDB contains a named function at `0x004b81a0`, size `0x4b`, with no incoming xrefs and no callees. Its bytes and decompilation show a UTF-16 `wcslen`-style scan plus `1000003` rolling hash recurrence.

Documentation evidence: current `StringUtil.md` explicitly excludes `00022J` from `StringUtil` ownership solely from wide-string hash behavior. Neighboring docs assign the rect-anchor helpers to `RectBounds`, `FileExists` to `PathUtil`, `BuildFieldMapPath` to `FieldMapPane`, and the next panel island to `GeneralPurposePanel` based on their own caller/body evidence.

Inference: `StringUtil` is the best future candidate if a source-use route appears, but by-structure requires a direct semantic owner and treats `EMITTER_UIDS` as output routing, not an ownership guess. Because there are zero proven source-use contexts, blank emitters are correct. This is not a pooled literal/shared-data case.

Existing documentation was treated as a lead, not final authority. The current IDA and raw PE checks independently revalidate the no-owner/non-emitting conclusion.

## Evidence Standards Used

Evidence checked:

- Current target page and metadata.
- Current generated coverage rows in `auto-generated/-ag-memory-coverage.md`.
- Current manual coverage row in `by-memory/-coverage-report.md`.
- Current and older executed B-agent reports for `00022J`.
- `by-structure.md` rules for direct ownership, emitter routing, no-owner reconstructable items, multiple-emitter shared data, third-party/runtime handling, and the `90/90+` code-entry gate.
- `goal.md` and `inference_research.md` B001 guidance.
- `by-project-structure/proposed-source-tree.md` placements for `StringUtil.cpp`, `StringBase.cpp`, `CachedHashTable.cpp`, `RectBounds.cpp`, `PathUtil.cpp`, `FieldMapPane.cpp`, and `GeneralPurposePanel.cpp`.
- Candidate owner docs: [UID:0000OB] `StringUtil`, [UID:0000OA] `StringBase`, [UID:0000HZ] `CachedHashTable`, [UID:0000N2] `RectBounds`, [UID:0000MI] `PathUtil`, [UID:0000JA] `FieldMapPane`, and [UID:0000JQ] `GeneralPurposePanel`.
- Neighboring memory pages: [UID:00022I], [UID:00022K], [UID:00015U], [UID:00022L], and [UID:00015V].
- Live IDA MCP: `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `xref_query`, `callees`, `disasm`, `decompile`, `analyze_function`, `find_bytes`, `find_regex`, and `imports_query`.
- Read-only PE byte scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

The evidence is strong enough to keep the current no-owner/non-emitting state because both modeled IDA xrefs and raw PE scans fail to identify any owner or emitter route, while contrast scans find normal caller surfaces for neighboring helpers.

## IDA MCP Facts

Live IDA MCP session:

- Session/database: `b001_0003gy`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- `server_health`: `status: ok`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`

Function/range facts:

| Query | IDA result | Meaning |
| --- | --- | --- |
| `0x004b8194` | not a function | predecessor padding start |
| `0x004b8198` | not a function | padding inside predecessor gap |
| `0x004b81a0` | `WideStringHashHelper`, size `0x4b` | target function |
| `WideStringHashHelper` | `0x004b81a0`, size `0x4b` | current IDA name |
| `0x004b81eb` | not a function | target endpoint / padding start |
| `0x004b81f0` | `sub_4B81F0`, size `0x2e` | successor `FileExists` |
| `0x004b8220` | `sub_4B8220`, size `0x64` | successor `BuildFieldMapPath` |
| `0x004b8290` | `sub_4B8290`, size `0x11e` | successor rect-axis helper |
| `0x004b83d0` | `sub_4B83D0`, size `0x1ae` | following panel island |

Data/table/padding facts:

| Region | Current byte result | Meaning |
| --- | --- | --- |
| `0x004b8194` size `12` | twelve `0xcc` bytes | clean padding before target |
| `0x004b81a0` size `75` | exact target body from `55 8b ec` through `5d c3` | one complete function |
| `0x004b81eb` size `16` | five `0xcc` bytes, then `0x004b81f0` prologue | clean padding after target |
| `0x004b81f0` size `48` | `FileExists` body and two trailing `0xcc` bytes | successor is separate |

Xref facts:

| Query | Result | Meaning |
| --- | --- | --- |
| `xrefs_to 0x004b81a0` | zero | no caller/data ref to target start |
| `xrefs_to WideStringHashHelper` | zero | no name-resolved caller/data ref |
| `xref_query 0x004b81a0 to code` | zero | no code xref to target start |
| `xref_query 0x004b81a0 to data` | zero | no data xref to target start |
| `xrefs_to 0x004b81eb` | zero | endpoint is not a referenced subrange |
| `xrefs_to 0x004b81f0` | `0x0049c87c`, `0x0049c88f`, `0x004dbcb5` | successor has normal callers |
| `xrefs_to 0x004b8220` | `0x004b0c0d` | path-stem helper has FieldMapPane constructor caller |
| `xrefs_to 0x004b8290` | `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161` | rect-axis helper has local transform-cluster callers |
| `xrefs_to 0x004b81b0` | internal target loop xrefs only | no external source route |
| `xrefs_to 0x004b81d6` | internal target loop xref only | no external source route |

Callee facts:

| Function | Callees | Meaning |
| --- | --- | --- |
| `0x004b81a0` | none | target is self-contained |
| `0x004b81f0` | `unk_69BE14`, `_fclose` | successor is path/file probe |
| `0x004b8220` | `_memmove` | successor is path-stem copy helper |
| `0x004b8290` | none | rect-axis helper is separate |

Disassembly facts for `0x004b81a0`:

- Reads the only argument from `[ebp+arg_0]` into `esi`.
- Scans 16-bit units until zero at `0x004b81b0-0x004b81b9`.
- Seeds `edx` from the first wide character shifted left seven at `0x004b81bd-0x004b81c4`.
- Loops with `imul edx, 0F4243h` at `0x004b81d6` and `xor edx, eax` at `0x004b81dc`.
- XORs the code-unit length from `edi` into the final hash at `0x004b81e3`.
- Returns in `eax` at `0x004b81e6-0x004b81ea`.

Decompiler facts:

```text
unsigned int __cdecl WideStringHashHelper(const unsigned __int16 *a1)
{
  v1 = a1;
  v2 = wcslen(a1);
  v3 = *a1 << 7;
  for ( i = v2 - 1; i >= 0; --i )
  {
    v5 = *v1++;
    v3 = v5 ^ (1000003 * v3);
  }
  return v2 ^ v3;
}
```

Byte-pattern facts from IDA MCP:

| Pattern | Result | Meaning |
| --- | --- | --- |
| `69 D2 43 42 0F 00` | one match at `0x004b81d6` | exact `imul edx, 0x0f4243` encoding unique |
| `43 42 0F 00` | one match at `0x004b81d8` | `1000003` immediate bytes unique |
| exact target body | one match at `0x004b81a0` | no duplicate full body |
| `A0 81 4B 00` | zero | no raw VA literal for target start in IDA search |
| `A0 81 0B 00` | zero | no raw RVA literal for target start in IDA search |
| `68 A0 81 4B 00` | zero | no `push 0x004b81a0` literal |

Name/import facts:

- `find_regex` for `python|cpython|unicode_hash|hash|StringUtil|WideString|StringBase|SimpleUString` finds the minimap `HashList.txt` URL, `CachedHashTable` RTTI, and `StringBase`/callback-template RTTI strings, but no source breadcrumb tied to `0x004b81a0`.
- `imports_query` for `^Py`, `^_Py`, `python`, `py`, and `hash` returns no Python/hash import evidence. A broad `*Py*` check only found `_BinkCopyToBuffer@28` because of the substring in `Copy`, not Python.

Negative IDA facts:

- No incoming code xrefs, data xrefs, or callers for the target start.
- No callees, no string references, no global references, and no object receiver in the target.
- No IDA evidence for a vtable slot, callback table, source symbol, import, or owner-specific data table referencing this helper.

## PE / Raw Evidence

Read-only PE scan target:

```text
Executable: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
Image base: 0x00400000
Target VA: 0x004b81a0-0x004b81eb
Target RVA: 0x000b81a0
Target file offset: 0x000b75a0
Target section: .text
```

Raw scan facts:

| Check | Result | Meaning |
| --- | --- | --- |
| exact target body | one hit at file `0x000b75a0` / VA `0x004b81a0` | no duplicate body |
| exact `imul` encoding | one hit at file `0x000b75d6` / VA `0x004b81d6` | unique hash multiply site |
| immediate `0x0f4243` bytes | one hit at file `0x000b75d8` / VA `0x004b81d8` | unique multiplier immediate |
| target VA dword `a0 81 4b 00` | zero hits | no absolute pointer to target start |
| target RVA dword `a0 81 0b 00` | zero hits | no raw RVA pointer to target start |
| `push 0x004b81a0` | zero hits | no obvious push-pointer use |
| any VA dword into target body | zero hits | no absolute pointer into body |
| any RVA dword into target body | three `.text` instruction-byte coincidences | not table/data refs |
| relative branch/call to `0x004b81a0` | zero hits | no hidden direct code route |
| relative branch/call to `0x004b81f0` | `0x0049c87c`, `0x0049c88f`, `0x004dbcb5` | raw scan finds successor callers |
| relative branch/call to `0x004b8220` | `0x004b0c0d` | raw scan finds FieldMapPane helper caller |
| relative branch/call to `0x004b8290` | `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161` | raw scan finds rect-anchor calls |

The three RVA-like dword values into the target body occur in instruction streams, not data tables:

| File/VA | Decoded value | Context |
| --- | --- | --- |
| file `0x000a616a` / VA `0x004a6d6a` | `0x000b81e8` | `10 8d 55 e8 52 50 e8 81 0b 00 00 8b 45 f0 8b 55` |
| file `0x0010e977` / VA `0x0050f577` | `0x000b81b4` | `8b 4d fc 33 cd e8 b4 81 0b 00 8b e5 5d c2 04 00` |
| file `0x0017d07a` / VA `0x0057dc7a` | `0x000b81e8` | `ff ff ff ff 77 08 e8 81 0b 00 00 0f b7 d0 66 85` |

These are opcode/displacement bytes and do not justify an owner or emitter.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b7f90-0x004b8194` | [UID:00022I] `RectAnchorTransformHelpers` | raw rect-anchor transform cluster | TRUE | `0000N2` RectBounds | `86/88` | separate predecessor |
| `0x004b8194-0x004b81a0` | [UID:0000VN] `-ignored` | alignment padding | FALSE | n/a | `100/strong` | keep ignored |
| `0x004b81a0-0x004b81eb` | [UID:00022J] target | wide-string hash helper | TRUE | `NONE`; blank emitters | `88/92` | keep unchanged |
| `0x004b81eb-0x004b81f0` | [UID:0000VN] `-ignored` | alignment padding | FALSE | n/a | `100/strong` | keep ignored |
| `0x004b81f0-0x004b821e` | [UID:00022K] `FileExists` | `_wfopen`/`_fclose` path existence helper | TRUE | `0000MI` PathUtil | `88/90` | separate successor |
| `0x004b8220-0x004b8284` | [UID:00015U] `BuildFieldMapPath` | FieldMapPane path-stem helper | TRUE | `0000JA` FieldMapPane | `84/88` | separate successor |
| `0x004b8290-0x004b83c5` | [UID:00022L] `RectAnchorAxisAdjustHelper` | rect anchor axis adjustment plus local switch data | TRUE | `0000N2` RectBounds | `86/88` | separate successor |
| `0x004b83d0-0x004b8bd3` | [UID:00015V] `GeneralPurposePanel` | panel lifecycle/helper island | TRUE | `0000JQ` GeneralPurposePanel | `84/90` | separate following island |
| `0x004c6160-0x004c659c` | [UID:00016O] `CachedHashTableLifecycle` | fixed-entry cache/hash table class | TRUE | `0000HZ` CachedHashTable | documented | separate utility island |
| `0x00453820-0x00453904` | [UID:0001ZY] `WideStringMapNodeSupport` | wide-string keyed tree-node support | TRUE | `0000OB` StringUtil | documented | contrast: accepted string utility child with caller/layout proof |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b81a0` | zero incoming xrefs; no callers | no owner/source-use proof |
| `0x004b81a0` | no callees | target has no dependency trail to an owner |
| `0x004b81d6` | internal loop xref only; unique `1000003` site | algorithm pattern does not expose source owner |
| `0x004b81f0` | callers at `0x0049c87c`, `0x0049c88f`, `0x004dbcb5`; callees `_wfopen` dispatch and `_fclose` | successor has PathUtil evidence |
| `0x004b8220` | caller at `0x004b0c0d`; callee `_memmove` | successor has FieldMapPane constructor evidence |
| `0x004b8290` | xrefs from `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161`; no callees | rect-axis helper tied to transform cluster, not target |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page records exact bounds, C001 IDA function repair, behavior, no-caller/no-xref/no-raw-pointer state, unique `1000003` multiply, and rejected parent candidates.
- `StringUtil.md` explicitly says not to attach [UID:00022J] solely from wide-string hash semantics because no caller, xref, raw pointer, table reference, or source-family artifact proves this file as direct parent.
- `StringBase.md` documents the ref-counted string-buffer family around `0x00582500-0x00584d7d`; `00022J` does not touch StringBase object state.
- `CachedHashTable.md` and proposed-source-tree document a separate `0x004c6160-0x004c659c` fixed-entry cache/hash table island with no link to the target.
- `RectBounds.md`, [UID:00022I], and [UID:00022L] document the corrected rect-anchor transform/axis relationship and explicitly separate unrelated intervening hash/file/path helpers.
- `PathUtil.md` and [UID:00022K] own the successor `FileExists` through path/file behavior and caller spread; that evidence does not transfer backward.
- `FieldMapPane.md` and [UID:00015U] own `BuildFieldMapPath` through the constructor call at `0x004b0c0d`; the target has no such call.
- `GeneralPurposePanel.md` and [UID:00015V] document the following panel island, which starts after the rect-axis helper and has no target link.

Existing docs that are stale, incomplete, or contradicted:

- Older reports use legacy `unassigned` or `AUTOGEN_PARENT_UID` language. Under the current model, this maps to `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` for this target.
- Some older report text predates the C001 IDA function creation. The current IDA status is now repaired: `WideStringHashHelper` exists at `0x004b81a0`.
- Older `95/95` code-entry phrasing is superseded by the current `90/90+` gate, but `00022J` still does not qualify because completion is `88` and no owner/emitter route is proven.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` lists the target as no-owner, owner `NONE`, blank emitters, no generated path. This is correct.
- `by-memory/-coverage-report.md` current row is accurate and should be retained.
- No `by-memory-tool-report.md` or generated-state action is required from this pass.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` - accepted

- Evidence for: exact function body is understood, but current IDA and PE evidence find no caller, code/data xref, raw VA/RVA pointer, branch/call route, table slot, vtable slot, source-family artifact, or source-use context. `by-structure.md` explicitly allows reconstructable NexusTK-owned source to remain no-owner and non-emitting while final owner/emitter route is not ready.
- Evidence against: the helper likely had an original declaration somewhere, and semantically it resembles string/hash utility code.
- Decision: accept. This is the only evidence-safe current state.

### 2. [UID:0000OB] `StringUtil` / `NexusTK/util/StringUtil.cpp` - strongest semantic candidate, rejected for assignment

- Evidence for: target hashes a UTF-16 string; `StringUtil` owns shared Unicode/string utility infrastructure, fixed wide-format wrappers, `SimpleUString` coordination, and accepted wide-string keyed map/tree support.
- Evidence against: no caller, xref, raw pointer, table, source symbol, or source-family link ties this exact helper to `StringUtil`. The current `StringUtil.md` scope exclusion explicitly rejects attaching `00022J` from behavior alone.
- Decision: do not set `CANONICAL_OWNER:0000OB` or `EMITTER_UIDS:0000OB`.

### 3. [UID:0000OA] `StringBase` / `NexusTK/util/StringBase.cpp` - rejected

- Evidence for: target consumes UTF-16 code units, and `StringBase` owns pointer-backed wide string helpers elsewhere.
- Evidence against: target takes a raw `const uint16_t *`, not a `StringBase` object. It does not touch ref-counted headers, sentinels, pool storage, object fields, RTTI, vtables, copy-on-write state, capacity, allocator behavior, or accepted StringBase helper callees.
- Decision: reject as owner/emitter.

### 4. [UID:0000HZ] `CachedHashTable` / `NexusTK/util/CachedHashTable.cpp` - rejected

- Evidence for: the target is a hash routine, and `CachedHashTable` is a hash/cache utility page.
- Evidence against: `CachedHashTable` is a separate class/vtable/helper island at `0x004c6160-0x004c659c`, with fixed-entry buffers, slot-state bytes, per-instance hash bytes, and no constructor/method/table/vtable link to `0x004b81a0`.
- Decision: reject as owner/emitter.

### 5. [UID:0000N2] `RectBounds` / `NexusTK/ui/core/RectBounds.cpp` - rejected

- Evidence for: physical proximity to rect-anchor transform helpers before the target and rect-axis helper after nearby path helpers.
- Evidence against: target hashes a wide string and does not read or write rectangle fields. Rect-anchor xrefs route from [UID:00022I] to [UID:00022L] and skip the hash helper. The local address neighborhood is mixed by documented evidence.
- Decision: reject as owner/emitter.

### 6. [UID:0000MI] `PathUtil` / `NexusTK/util/PathUtil.cpp` - rejected

- Evidence for: the immediate successor [UID:00022K] `FileExists` is a PathUtil-owned wide-path helper.
- Evidence against: the target has no path/file behavior, no `_wfopen`/`_wstat`/`_fclose` dependency, no dispatch-table access, and no caller relation to `FileExists`. Padding separates the two functions.
- Decision: reject as owner/emitter.

### 7. [UID:0000JA] `FieldMapPane` and [UID:0000JQ] `GeneralPurposePanel` adjacency - rejected

- Evidence for: nearby later pages belong to field-map and panel code.
- Evidence against: those owners are proven by their own constructors, vtable stores, object fields, helper callers, and path/panel behavior. The target has no FieldMap constructor, `.EPF`, panel singleton, child-pane, or UI state evidence.
- Decision: reject as owner/emitter.

### 8. External/library/runtime hash source - rejected for reclassification

- Evidence for: the `1000003` multiply/XOR recurrence resembles known string-hash idioms.
- Evidence against: no Python/third-party import, source string, version marker, module name, broader library island, runtime call, or `-1` hash sentinel repair proves an external/runtime owner. Current IDA import queries for Python/hash evidence are negative.
- Decision: do not reclassify to `RECONSTRUCTABLE:FALSE`, do not create a third-party embed, and do not create a synthetic external emitter.

### 9. `CANONICAL_OWNER:NONE` with one or more emitters - rejected

- Evidence for: current `by-structure.md` supports no canonical owner plus emitters for pooled/shared data with proven source-use contexts.
- Evidence against: this is a standalone function, not pooled data or shared literal data. It has zero proven source-use contexts and no generated C++ block requiring output routing.
- Decision: keep `EMITTER_UIDS` blank.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new owner or source file is recommended from current evidence.
- Likely full contents: none supported. A future narrow `StringHash` or `StringUtil` sub-owner would require at least one real caller, table reference, sibling function family, or source breadcrumb.
- Candidate related items that belong: none currently proven.
- Candidate related items rejected: accepted `StringUtil` children such as [UID:0001ZY] have direct caller/layout evidence that this target lacks; `CachedHashTable` is a separate class island; neighboring rect/path/field-map/panel ranges have their own source-family evidence.
- Standalone, narrow, or broad source-file inference: current evidence is insufficient even for a standalone one-function file, because there is no source root, output route, or related item to define that file.

## Negative Evidence Summary

- No IDA xrefs to `0x004b81a0`.
- No IDA code xrefs or data xrefs to `0x004b81a0`.
- No IDA callers for `WideStringHashHelper`.
- No callees from target body.
- No global reads/writes, string refs, imports, object receiver, vtable refs, RTTI refs, or table refs in the target.
- No raw VA or RVA pointer to the target start in the PE scan.
- No `push 0x004b81a0`.
- No raw VA dword into any byte of the target body.
- No real external branch/call to the target start.
- RVA-like dword values into the target body are instruction-byte coincidences, not table/data refs.
- No Python/hash import or source string evidence for external-runtime reclassification.
- No `StringUtil`, `StringBase`, `CachedHashTable`, `RectBounds`, `PathUtil`, `FieldMapPane`, or `GeneralPurposePanel` xref reaches this target.
- Neighboring functions have normal positive caller/reference surfaces, proving that the no-reference result is local to `00022J`, not a general analysis failure in this address neighborhood.

## Final Recommendation

- Exact changes applied or recommended: created this research report only. No by-* documentation edit is recommended.
- Exact parent assignments applied or recommended: none. Keep `CANONICAL_OWNER:NONE`.
- Exact emitter assignments applied or recommended: none. Keep `EMITTER_UIDS:` blank.
- Exact items left no-owner/non-emitting and why: [UID:00022J], because no direct semantic owner and no source-use/output route clear the evidence gate.
- Exact future work outside this assignment scope: revisit only if future evidence identifies a caller, indirect table, raw pointer, source symbol/name, or repeated owner-specific source family that ties `0x004b81a0` to `StringUtil`, `StringBase`, a real hash utility source, or an external source package.

## Follow-Up Actions

- Supervisor actions: no immediate target metadata, coverage, generated-report, split, merge, or IDA repair action required.
- A-agent actions: none for this target unless new owner/emitter evidence appears.
- B001 future research actions: if another target reveals a string/hash table or UTF-16 key container that references `0x004b81a0`, recheck `StringUtil` first, then `StringBase`, then a narrow string-hash utility grouping.

## Confidence

- Recommendation confidence: 92/100.
- Boundary confidence: 99/100.
- Behavior confidence: 97/100.
- Confidence that no current emitter is justified: 96/100.
- Score recommendation confidence: 90/100 for keeping `88/92`.
- Remaining uncertainty: the original source declaration may have lived in `StringUtil`, a narrow hash helper, or a copied utility fragment. Current binary and documentation evidence do not identify which, and assigning one now would overclaim.

## Validator Results

- Commands run: none.
- Results: no validator was run because no validator-managed by-* files were edited.
- Any unresolved validator warnings/errors: none from this pass.
- Dry-run status: no dry-run validator mode was used.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/00022J-WideStringHashHelper-current-goal2-pass.md`
- Modified: none outside Agent-B001 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00022J-WideStringHashHelper-current-goal2-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
