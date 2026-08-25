** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022J WideStringHashHelper Post-Migration Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00022J] `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, with blank `EMITTER_UIDS`.
- Final disposition: exact source-shaped UTF-16/wide-string hash helper with strong behavior and boundary evidence, but still no caller, xref, raw VA/RVA pointer, table reference, branch/call route, vtable slot, source-family artifact, or source-use context proves a canonical owner or emitter.
- Required action: no target metadata change, no coverage row change, no split/merge, no reclassification, no IDA repair, and no reconstruction C++ entry.
- Exact metadata to retain:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Confidence: high for the no-owner/non-emitting recommendation. `StringUtil` remains the best semantic candidate, but behavior alone is not direct ownership. Blank `EMITTER_UIDS` is correct because no generated C++ is present and no source-use context clears the output-routing gate.

## Supporting Research

## Target

- Target UID: `00022J`
- Target path: `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`
- Required report path: `tools/leaser/Agents/Agent-B001/research/00022J-WideStringHashHelper-post-migration-recheck.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` current no-owner/non-emitting memory row.
- Tracker state: `tools/leaser/Agents/no_owner_b-agent-tracker.md` has a current B001 assignment row for this recheck and a prior executed B003 second-pass row.
- Current scores and state:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Current generated memory coverage row:

```text
| [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` |  |
```

Current manual coverage row:

```text
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : B003 second-pass review keeps `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`; C001-009 defined the exact raw body as IDA function `WideStringHashHelper`, and fresh PE/raw scans reconfirm isolated `0x4b` prologue/body/return range, adjacent `0xcc` padding, unique `wcslen` plus `1000003` wide-string hash recurrence, no callers/xrefs/raw VA/RVA pointer/table reference, no external branch/call route, and normal xrefs to adjacent FileExists/BuildFieldMapPath/RectAnchor helpers. `StringUtil` remains semantic only and no direct owner/emitter evidence is proven.
```

## Executive Recommendation

Keep the current no-owner/non-emitting state. The helper is real source-shaped code and should remain `RECONSTRUCTABLE:TRUE`:

- It has a conventional `cdecl` prologue/epilogue and one raw UTF-16 pointer argument.
- It scans a NUL-terminated UTF-16 buffer, computes a 32-bit rolling hash using the distinctive `1000003` multiplier, and returns `length ^ hash`.
- It has no callees, no global reads/writes, no heap/runtime calls, and no object receiver.
- It is surrounded by verified `0xcc` padding and is now an IDA-modeled function named `WideStringHashHelper`.

Do not assign it to `StringUtil` yet. `StringUtil` is the best semantic candidate because the behavior is a wide-string helper and that file owns broad Unicode/string utility infrastructure. The missing piece is direct source-owner evidence: no caller, xref, pointer, table, source symbol, or source-family artifact ties this exact function to `StringUtil`.

Do not add emitters. This is not a pooled/shared literal or multi-use shared data case. It is an unreferenced retained helper with zero proven source-use contexts. Emitting it through `StringUtil`, `CachedHashTable`, `RectBounds`, `PathUtil`, `FieldMapPane`, or multiple files would invent output routing from semantics or address adjacency.

No reconstruction C++ should be entered. The item is below the active `90/90+` code-entry gate on completion, and the owner/emitter route is absent.

## Supervisor Active Recheck

The supervisor requested a one-target post-migration no-owner memory recheck for UID `00022J`, specifically asking whether the item should stay no-owner/non-emitting or gain a canonical owner, one or more emitters, a split/merge/reclassification, IDA repair, or score changes.

Recheck result:

- Split repair required: no. The target is already one exact `0x4b` function at `0x004b81a0-0x004b81eb`.
- Merge/container repair required: no. Neighboring rect, path, field-map, and panel helpers have separate evidence and source routes.
- IDA repair required: no. C001 already defined and named the helper in the IDA database.
- Owner/emitter repair required: no. No candidate clears the direct evidence gate.
- Score change required: no. Keep `88/92`.
- Coverage row change required: no. Retain the current row quoted above.

## Inference Research Guidance Check

Facts:

- Live IDA MCP confirms `WideStringHashHelper` at `0x004b81a0`, size `0x4b`.
- Live IDA MCP and raw PE scans confirm no incoming reference to the function start.
- The helper body has no calls, no globals, no object receiver, and no side effects beyond reading the input string.
- The surrounding helpers have normal xref surfaces, proving that the no-reference result is local to `00022J`, not a general xref failure in the neighborhood.

Inference:

- The helper is source-shaped and reconstructable because the binary contains a complete retained function body.
- `StringUtil` is the strongest semantic candidate, but the assignment remains below gate because wide-string behavior alone is not direct source ownership.
- The `1000003` recurrence resembles known string-hash idioms, but no Python/runtime/library import, source string, or broader third-party body is present. Algorithm similarity is not enough to reclassify this as external runtime code.

The prior executed B001, B002, and B003 reports were reviewed as background. This report independently refreshed the live IDA MCP evidence, current candidate docs, generated/manual coverage rows, and raw PE reference state.

## Evidence Standards Used

Evidence checked:

- Current target page and metadata.
- Prior executed reports:
  - `tools/leaser/Agents/Agent-B001/research/executed/00022J-WideStringHashHelper.md`
  - `tools/leaser/Agents/Agent-B001/research/executed/00022J-WideStringHashHelper-B001-00022J.md`
  - `tools/leaser/Agents/Agent-B002/research/executed/00022J-WideStringHashHelper-post-migration.md`
  - `tools/leaser/Agents/Agent-B003/research/executed/00022J-WideStringHashHelper-second-pass.md`
- Current generated coverage in `auto-generated/-ag-memory-coverage.md`.
- Current manual coverage in `by-memory/-coverage-report.md`.
- Current tracker row in `tools/leaser/Agents/no_owner_b-agent-tracker.md`.
- `by-structure.md` rules for direct semantic ownership, emitter routing, no-owner/non-emitting reconstructable items, multi-emitter pooled-data cases, runtime/library classification, and the active `90/90+` code-entry gate.
- `inference_research.md` guidance that address adjacency and broad semantic similarity are weak without xrefs, metadata, initialization, or repeated usage patterns.
- Candidate owner docs: [UID:0000OB] `StringUtil`, [UID:0000OA] `StringBase`, [UID:0000HZ] `CachedHashTable`, [UID:0000N2] `RectBounds`, [UID:0000MI] `PathUtil`, and neighboring memory pages.
- Live IDA MCP `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `callees`, `disasm`, `decompile`, and `find_bytes`.
- Read-only raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## IDA MCP Facts

Live IDA MCP session:

- Session/database: `b001_0003gy`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- `server_health`: `status: ok`, imagebase `0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`

Function/range facts:

| Query | IDA result | Meaning |
| --- | --- | --- |
| `0x004b8194` | not a function | corrected predecessor padding start |
| `0x004b8198` | not a function | padding inside predecessor gap |
| `0x004b81a0` | `WideStringHashHelper`, size `0x4b` | target function |
| `WideStringHashHelper` | `0x004b81a0`, size `0x4b` | current IDA function name |
| `0x004b81eb` | not a function | target endpoint / padding start |
| `0x004b81f0` | `sub_4B81F0`, size `0x2e` | successor `FileExists` helper |
| `0x004b8220` | `sub_4B8220`, size `0x64` | successor `BuildFieldMapPath` helper |
| `0x004b8290` | `sub_4B8290`, size `0x11e` | successor rect-anchor axis helper |
| `0x004b83c5` | not a function | end/padding after rect-anchor axis helper |
| `0x004b83d0` | `sub_4B83D0`, size `0x1ae` | following GeneralPurposePanel-region helper |

Boundary byte facts:

| Region | Bytes / Result | Meaning |
| --- | --- | --- |
| `0x004b8194` size `12` | twelve `0xcc` bytes | clean padding before target |
| `0x004b81a0` size `75` | exact target body from `55 8b ec` through `5d c3` | one complete `0x4b` function |
| `0x004b81eb` size `16` | five `0xcc` bytes then `0x004b81f0` prologue | clean padding after target |
| `0x004b81f0` size `48` | `FileExists` body starts with `push ebp; mov ebp, esp; push ebx` | successor is separate |

Xref facts:

| Query | Result | Meaning |
| --- | --- | --- |
| `xrefs_to 0x004b81a0` | zero | no caller/data ref to target start |
| `xrefs_to 0x004b81eb` | zero | endpoint is not a referenced subrange |
| `xrefs_to 0x004b81f0` | three code refs at `0x0049c87c`, `0x0049c88f`, `0x004dbcb5` | successor has normal caller surface |
| `xrefs_to 0x004b8220` | one code ref at `0x004b0c0d` | successor path helper has known caller |
| `xrefs_to 0x004b8290` | four code refs from `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161` | rect-anchor axis helper has known internal xrefs |
| `xrefs_to 0x004b81b0` | internal loop xrefs from target body only | no external source-use route |
| `xrefs_to 0x004b81d6` | internal loop xref from target body only | no external source-use route |

Callee facts:

| Function | Callees | Meaning |
| --- | --- | --- |
| `0x004b81a0` | none | target is self-contained; no import/library call route |
| `0x004b81f0` | wide file-open dispatch slot and `_fclose` | path/file behavior belongs to successor |
| `0x004b8220` | `_memmove` | path/string construction behavior belongs to successor |
| `0x004b8290` | none | rect-axis helper separate from target |

Disassembly facts for `0x004b81a0`:

- Loads the only argument from `[ebp+arg_0]` into `esi`.
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
  for (i = v2 - 1; i >= 0; --i) {
    v5 = *v1++;
    v3 = v5 ^ (1000003 * v3);
  }
  return v2 ^ v3;
}
```

Byte-pattern facts:

| Pattern | Result | Meaning |
| --- | --- | --- |
| `69 D2 43 42 0F 00` | one match at `0x004b81d6` | exact `imul edx, 0x0f4243` encoding unique |
| `43 42 0F 00` | one match at `0x004b81d8` | `1000003` immediate bytes unique |
| `A0 81 4B 00` | zero matches | no raw VA literal for target start |
| `A0 81 0B 00` | zero matches | no raw RVA literal for target start |

## PE / Raw Evidence

Read-only raw PE scan target:

```text
Executable: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
Target VA: 0x004b81a0-0x004b81eb
Target RVA: 0x000b81a0
Target section: .text
Target file offset: 0x000b75a0
```

Target bytes:

```text
55 8b ec 56 8b 75 08 8b ce 57 8d 51 02 0f 1f 00
66 8b 01 83 c1 02 66 85 c0 75 f5 2b ca 0f b7 16
d1 f9 8b f9 c1 e2 07 83 e9 01 78 17 0f 1f 40 00
0f b7 06 8d 76 02 69 d2 43 42 0f 00 33 d0 83 e9
01 79 ed 33 d7 5f 8b c2 5e 5d c3
```

Neighbor bytes:

```text
0x004b8194: cc cc cc cc cc cc cc cc cc cc cc cc 55 8b ec 56 ...
0x004b81eb: cc cc cc cc cc 55 8b ec 53 68 20 df 60 00 ff 75 ...
0x004b81f0: 55 8b ec 53 68 20 df 60 00 ff 75 08 32 db ff 15 ...
```

Raw scan facts:

| Check | Result | Meaning |
| --- | --- | --- |
| target VA dword `a0 81 4b 00` | zero hits | no absolute pointer to target start |
| target RVA dword `a0 81 0b 00` | zero hits | no raw RVA pointer to target start |
| exact target body | one hit at file `0x000b75a0` / VA `0x004b81a0` | no duplicate exact body |
| exact `imul` encoding | one hit at file `0x000b75d6` / VA `0x004b81d6` | hash multiplier site is unique |
| immediate `0x0f4243` bytes | one hit at file `0x000b75d8` / VA `0x004b81d8` | hash multiplier immediate is unique |
| any VA dword into target body | zero hits | no direct absolute pointer into the body |
| any RVA dword into target body | three byte-pattern coincidences in `.text` instruction streams | not pointer/table evidence |
| branch/call to `0x004b81a0` | zero hits | no hidden direct code route to target start |
| branch/call to `0x004b81f0` | three hits | raw scan finds successor's real callers |
| branch/call to `0x004b8220` | one hit | raw scan finds successor's real caller |
| branch/call to `0x004b8290` | four hits | raw scan finds rect-axis helper xrefs |

The three RVA-like dword coincidences into the target body occur inside unrelated instruction byte streams:

| File/VA | Decoded value | Context |
| --- | --- | --- |
| file `0x000a616a` / VA `0x004a6d6a` | `0x000b81e8` | inside `... 52 50 e8 81 0b 00 00 ...` |
| file `0x0010e977` / VA `0x0050f577` | `0x000b81b4` | inside `... 33 cd e8 b4 81 0b 00 ...` |
| file `0x0017d07a` / VA `0x0057dc7a` | `0x000b81e8` | inside `... ff 77 08 e8 81 0b 00 00 ...` |

They are not loaded data references, table entries, or start pointers and do not justify an emitter.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent / Route | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b7f90-0x004b8194` | [UID:00022I] `RectAnchorTransformHelpers` | raw rect-anchor transform cluster | TRUE | RectBounds route | `86/88` | separate predecessor |
| `0x004b8194-0x004b81a0` | [UID:0000VN] padding | alignment | FALSE | n/a | `100/strong` | keep ignored |
| `0x004b81a0-0x004b81eb` | [UID:00022J] target | wide-string hash helper | TRUE | `NONE`; blank emitters | `88/92` | keep unchanged |
| `0x004b81eb-0x004b81f0` | [UID:0000VN] padding | alignment | FALSE | n/a | `100/strong` | keep ignored |
| `0x004b81f0-0x004b821e` | [UID:00022K] `FileExists` | `_wfopen`/`_fclose` path existence helper | TRUE | PathUtil route | documented | separate successor |
| `0x004b8220-0x004b8284` | `BuildFieldMapPath` | FieldMapPane path-building helper | TRUE | FieldMapPane route | documented | separate successor |
| `0x004b8290-0x004b83c5` | `RectAnchorAxisAdjustHelper` | rect anchor axis adjustment | TRUE | RectBounds route | documented | separate successor |
| `0x004c6160-0x004c659c` | `CachedHashTableLifecycle` | fixed-entry cache/hash table class | TRUE | CachedHashTable route | documented | separate utility island |
| `0x00453820-0x00453904` | `WideStringMapNodeSupport` | wide-string keyed tree-node support | TRUE | StringUtil route | `86/88` | contrast: has caller/layout proof |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b81a0` | zero incoming xrefs | no owner/source-use proof |
| `0x004b81d6` | internal loop xref only | `1000003` site does not expose an owner |
| `0x004b81f0` | callers at `0x0049c87c`, `0x0049c88f`, `0x004dbcb5` | successor path helper has direct source-use evidence |
| `0x004b8220` | caller at `0x004b0c0d` | successor FieldMapPane path helper has direct source-use evidence |
| `0x004b8290` | xrefs from `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161` | rect-anchor axis helper is tied to RectBounds transform cluster |
| `0x00453820-0x00453904` | documented minimap/metadata caller spread | accepted StringUtil child has evidence the target lacks |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page records exact bounds, behavior, no-caller/no-xref/no-raw-pointer state, unique `1000003` multiply, C001 IDA function repair, and rejected parent candidates.
- B002 and B003 prior reports independently kept `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` after post-migration owner/emitter review.
- `StringUtil.md` explicitly says not to attach UID `00022J` to `StringUtil` solely from wide-string hash semantics because no caller, xref, raw pointer, table reference, or source-family artifact proves it as the actual direct parent.
- `RectBounds.md` and the rect-anchor pages document the corrected predecessor range and confirm the intervening hash/file/path helpers are unrelated to RectBounds despite physical proximity.
- `PathUtil.md` owns the successor `FileExists` helper because of wide-path behavior and caller spread; that evidence does not transfer backward to the hash helper.
- `CachedHashTable.md` documents a separate class/vtable/helper island around `0x004c6160-0x004c659c`; it has no link to `0x004b81a0`.
- `WideStringMapNodeSupport.md` shows what sufficient StringUtil evidence looks like: wide-string payload layout plus minimap and metadata caller spread. UID `00022J` has behavior only, not use-context proof.

Existing docs that are stale or incomplete:

- Some older reports and rows use legacy `unassigned` terminology; under the current system this maps to `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`.
- Related pages may still mention the older `95/95` final-code gate. The active code-entry gate is `90/90+`, but UID `00022J` still fails code entry because completion is `88` and the owner/emitter route is absent.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently lists UID `00022J` as no-owner, owner `NONE`, blank emitters, no generated path. This is correct.
- `by-memory/-coverage-report.md` current row is accurate and should be retained.
- No `by-memory-tool-report.md` action is required for this target unless the supervisor regenerates reports for broader project state.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` - accepted

- Evidence for: exact function body is understood, but no caller, data xref, raw VA/RVA pointer, branch/call route, vtable/table slot, source-family artifact, or source-use context exists. Current `by-structure.md` allows confirmed reconstructable items to remain no-owner/non-emitting while owner/emitter route and final source shape are unproven.
- Evidence against: the helper likely had an original declaration somewhere and semantically resembles a string utility helper.
- Decision: accept. This is the only evidence-safe current-model state.

### 2. [UID:0000OB] `StringUtil` / `NexusTK/util/StringUtil.cpp` - strongest semantic candidate, rejected for assignment

- Evidence for: target hashes a UTF-16 string; `StringUtil` owns broad Unicode/string utility infrastructure, fixed wide-format wrappers, `SimpleUString` coordination, and accepted wide-string keyed map/tree support.
- Evidence against: no caller, xref, raw pointer, table, name artifact, or source-family link ties this exact helper to `StringUtil`. `StringUtil.md` already documents an explicit scope exclusion for UID `00022J`.
- Decision: do not set `CANONICAL_OWNER:0000OB` or `EMITTER_UIDS:0000OB`.

### 3. [UID:0000OA] `StringBase` / `NexusTK/util/StringBase.cpp` - rejected

- Evidence for: target consumes wide characters.
- Evidence against: it takes a raw `const uint16_t *`, not a `StringBase` object; it does not touch ref-counted headers, sentinel buffers, pool storage, object fields, RTTI, vtables, COW state, capacity, or allocator behavior.
- Decision: reject as owner/emitter.

### 4. [UID:0000HZ] `CachedHashTable` / `NexusTK/util/CachedHashTable.cpp` - rejected

- Evidence for: name contains "hash", and the target is a hash routine.
- Evidence against: `CachedHashTable` is a separate class/vtable/helper island at `0x004c6160-0x004c659c`, with per-instance hash bytes and cache slots. No constructor, method, table, or vtable link reaches `0x004b81a0`.
- Decision: reject as owner/emitter.

### 5. [UID:0000N2] `RectBounds` / `NexusTK/ui/core/RectBounds.cpp` - rejected

- Evidence for: physical proximity to rect-anchor helpers before and after the target.
- Evidence against: target hashes a wide string and does not read/write rectangle fields. Rect-anchor xrefs stay inside the rect transform cluster and skip this helper. Address adjacency crosses multiple source families here.
- Decision: reject as owner/emitter.

### 6. [UID:0000MI] `PathUtil` / FileIO path helpers - rejected

- Evidence for: immediate successor `FileExists` is PathUtil-owned.
- Evidence against: target has no path/file API behavior and no caller relation to the successor. Padding separates both helpers.
- Decision: reject as owner/emitter.

### 7. FieldMapPane / GeneralPurposePanel adjacency - rejected

- Evidence for: nearby successor pages belong to UI/map panel code.
- Evidence against: those owners are proven by their own callers and behavior, not by physical neighborhood. The target has neither map path behavior nor panel state.
- Decision: reject as owner/emitter.

### 8. External/library/runtime hash source - rejected for reclassification

- Evidence for: the `1000003` multiply/XOR recurrence resembles known string-hash idioms.
- Evidence against: no import, source string, version marker, module name, larger library island, runtime call, or sentinel fixup proves an external/runtime owner. The helper is one retained source-shaped function in `.text`.
- Decision: do not reclassify to `RECONSTRUCTABLE:FALSE` and do not create a synthetic external emitter.

### 9. `CANONICAL_OWNER:NONE` with one or more emitters - rejected

- Evidence for: current model supports no canonical owner plus emitters when pooled/shared data has proven source-use contexts.
- Evidence against: this is not pooled data, and it has zero proven source-use contexts. There is no generated C++ block that needs routing.
- Decision: keep `EMITTER_UIDS` blank.

## Negative Evidence Summary

- No IDA xrefs to `0x004b81a0`.
- No IDA xrefs to endpoint `0x004b81eb`.
- No callees from target body.
- No global reads/writes or object receiver.
- No raw VA or RVA pointer to the target start.
- No raw VA dword into any byte of the target body.
- No real external branch/call to target start.
- RVA-like dword values into the body are instruction-byte coincidences, not table/data refs.
- No vtable, RTTI, callback table, import, or source-symbol evidence.
- No `StringUtil`, `StringBase`, `CachedHashTable`, `RectBounds`, `PathUtil`, FieldMapPane, or panel xref reaches this target.
- No evidence for a multiple-emitter source-use case.

## Final Recommendation

Exact changes applied or recommended:

- No by-* documentation edits were made by B001.
- No metadata change is recommended.
- No coverage row replacement is recommended.
- No generated coverage row change is recommended.
- No reconstruction C++ should be entered.

Exact item left no-owner/non-emitting:

- UID `00022J` should remain:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Why no-owner/non-emitting is still correct:

- `CANONICAL_OWNER:NONE` is correct because no direct semantic owner clears the evidence gate.
- Blank `EMITTER_UIDS` is correct because no source-use context or output route is proven.
- This is not an invalid dead route; it is a route-blocked reconstructable helper whose original source owner remains unproven.

Exact condition that would change the recommendation:

- Revisit if future evidence identifies a real caller, function pointer/table entry, source symbol, source map, import/library breadcrumb, or repeated owner-specific use that ties `0x004b81a0` to `StringUtil`, `StringBase`, `CachedHashTable`, another utility owner, or an external source file.

## Follow-Up Actions

- Supervisor: no immediate target metadata, coverage, or generated-report edit is required.
- Future IDA/database work: no function repair is needed. The current IDA function definition and name are already useful.
- Future B-agent/A-agent work: revisit only if new reachability/source-family evidence appears.

## Confidence

- Recommendation confidence: 91/100.
- Boundary confidence: 99/100.
- Behavior confidence: 97/100.
- Confidence that no current emitter is justified: 96/100.
- Score recommendation confidence: 90/100 for keeping `88/92`.
- Remaining uncertainty: the helper may originally have lived in `StringUtil`, a small hash utility, or an imported-source utility fragment, but current binary and documentation evidence do not identify which.

## Validator Results

- No validator was run because no validator-managed by-* files were edited.
- No dry-run validator mode was used.
- No memory-range repair mode was used.

Commands/evidence collected:

- Live IDA MCP `server_health`: ok.
- Live IDA MCP `lookup_funcs`: target, padding endpoints, and neighboring helpers.
- Live IDA MCP `get_bytes`: target body and neighbor padding.
- Live IDA MCP `xrefs_to`: target, endpoint, internal loop sites, and neighboring helper starts.
- Live IDA MCP `callees`: target and neighboring helpers.
- Live IDA MCP `disasm` and `decompile`: target.
- Live IDA MCP `find_bytes`: hash multiply encoding, hash immediate, and raw VA/RVA target-start literals.
- Read-only raw PE scan: corrected PE section mapping, target bytes, VA/RVA pointer search, exact-body search, hash-pattern search, branch/call scan to target and contrast neighbor starts, and RVA-coincidence review.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/00022J-WideStringHashHelper-post-migration-recheck.md`
- Modified: none outside B001 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00022J-WideStringHashHelper-post-migration-recheck.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
