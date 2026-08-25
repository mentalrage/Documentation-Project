** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022J WideStringHashHelper Current Source Routing Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00022J] `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal reconstruction C++.
- Final disposition: source-shaped retained UTF-16/wide-string hash helper with strong byte, range, behavior, and no-route evidence, but no defensible current direct semantic owner or generated output route.
- Required action: do not route to `StringUtil`, `StringBase`, `CachedHashTable`, `RectBounds`, `PathUtil`, `FieldMapPane`, `GeneralPurposePanel`, `GrafPort`, or a new synthetic utility file from current evidence. Do not add emitters. Do not populate `RECONSTRUCTION_CPP CODE`.
- Confidence: high for keeping the current no-owner/non-emitting state; high for behavior and exact range; medium for any original-source placement guess because no caller, pointer, table, symbol, or source-family artifact currently identifies one.
- Target score recommendation: keep `COMPLETION:88`, `CONFIDENCE:92`. The target is already above the behavior/evidence gate, but ownership/source-output uncertainty still prevents final-audit scoring.

Retain the target metadata exactly:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

This recommendation supersedes older wording that said the target failed a `90/90+` code-entry gate. Under the current by-structure gate, the average score is high enough, but the target still fails final C++ eligibility because it has no confirmed nonblank `EMITTER_UIDS` route to a generated source root.

## Supporting Research

### Target

- Target UID: `00022J`.
- Target path: `source-3/project-documentation/by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`.
- Assignment id: `B001-goal2-wide-string-hash-helper-current-source-routing-00022J-20260618`.
- Source queue/report row: active row in `tools/leaser/Agents/no_owner_b-agent-tracker.md` assigned to Agent-B001 on 2026-06-18; generated memory coverage lists the item as no-owner with owner `NONE`, blank emitters, no output path, and non-emitting.
- Current target header state: `88/92`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank formal C++.
- Scope: report-only. No by-* docs, generated reports, IDA database, generated source, or `by-memory/-coverage-report.md` were edited.

### Current Function / Behavior Summary

Observed function shape:

- Address range: `0x004b81a0-0x004b81eb`, size `0x4b` / 75 bytes, end-exclusive.
- Current IDA state from target page and prior executed reports: C001-009 created an exact IDA function at `0x004b81a0`, named it `WideStringHashHelper`, and post-fix lookup reported size `0x4b`. Hex-Rays decompiled it as a `const unsigned __int16 *` argument and unsigned-int hash return.
- Local PE evidence from this pass: the exact 75-byte body occurs once at raw file offset `0x000b75a0` / VA `0x004b81a0`; the preceding bytes `0x004b8194-0x004b81a0` are twelve `0xcc` alignment bytes; the following bytes `0x004b81eb-0x004b81f0` are five `0xcc` alignment bytes.
- Likely source-facing signature, descriptive rather than original-proof: `uint32_t __cdecl WideStringHashHelper(const wchar_t *text)` or, if later routed as a file-local helper, `static uint32_t HashWideString(const wchar_t *text)`. Windows `wchar_t` is compatible with the observed 16-bit code-unit reads in this 32-bit MSVC-era client.
- Side effects: none beyond reading the caller-provided NUL-terminated UTF-16/wide string. The function calls no other functions, touches no globals, and writes no output buffer.
- Safety contract: no null-pointer check. Callers, if any existed in original source, had to pass a valid NUL-terminated wide string.

The raw bytes from the current PE scan are:

```text
55 8b ec 56 8b 75 08 8b ce 57 8d 51 02 0f 1f 00
66 8b 01 83 c1 02 66 85 c0 75 f5 2b ca 0f b7 16
d1 f9 8b f9 c1 e2 07 83 e9 01 78 17 0f 1f 40 00
0f b7 06 8d 76 02 69 d2 43 42 0f 00 33 d0 83 e9
01 79 ed 33 d7 5f 8b c2 5e 5d c3
```

Behavior:

1. Reads the only argument from `[ebp+8]` into `esi`.
2. Scans 16-bit code units until a zero word to compute the length.
3. Seeds the hash with the first code unit shifted left by seven bits.
4. Iterates over each code unit, including the first, and applies `hash = code_unit ^ (1000003 * hash)`.
5. XORs the code-unit length into the final hash.
6. Returns the final 32-bit value in `eax`.

This is source-shaped utility code, not padding, not a thunk, not a switch table, not an import stub, and not compiler-only EH/RTTI glue.

### Current IDA Function Definition Recheck

Live IDA MCP could not be reached in this session. The `tools/list` JSON-RPC request to `http://127.0.0.1:13337/mcp` returned `Unable to connect to the remote server`. Because of that, this pass could not independently query current IDA function metadata, xrefs, or Hex-Rays output.

The current IDA function state is therefore validated from the target page and executed prior reports, not from a fresh live MCP call:

- Target page records C001-009 making the IDA 9.1 database fix: `define_func 0x004b81a0-0x004b81eb`, rename `sub_4B81A0` to `WideStringHashHelper`, and `idb_save`.
- Target page records post-fix `lookup_funcs` returning `WideStringHashHelper` at `0x004b81a0`, size `0x4b`, with successor `sub_4B81F0` at `0x004b81f0`, size `0x2e`.
- Target page records post-fix Hex-Rays decompilation equivalent to `unsigned int __cdecl WideStringHashHelper(const unsigned __int16 *a1)`, with a `wcslen`-style scan, seed `*a1 << 7`, multiplier `1000003`, and final `length ^ hash`.
- Local filesystem check found `e:\NTK\Resources\NexusTK\NexusTK.exe.i64`, timestamp `2026-06-12 10:45:05`, matching the date of the C001 repair. The IDB was not opened, parsed, or modified.

The raw PE recheck in this report independently confirms that the byte range and behavior described by the IDA evidence still match the project binary. The only current evidence gap is the absence of a live MCP query for the IDA database state on 2026-06-18.

### Current PE / Raw Evidence

Read-only executable checked:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
size: 2679296 bytes
MD5: 4247e04e20b65d6414c7238aa8ff5515
image base: 0x00400000
.text: VA 0x00401000-0x0060c4ac, raw 0x00000400-0x0020ba00
target VA: 0x004b81a0-0x004b81eb
target RVA: 0x000b81a0
target raw: 0x000b75a0
```

The second local copy at `e:\NTK\Resources\NexusTK\NexusTK.exe` has the same MD5.

Raw scan results from this pass:

| Check | Result | Meaning |
| --- | --- | --- |
| Exact 75-byte target body | one hit at file `0x000b75a0` / VA `0x004b81a0` | no duplicate full body |
| Predecessor bytes `0x004b8194-0x004b81a0` | twelve `0xcc` bytes | clean padding before target |
| Successor bytes `0x004b81eb-0x004b81f0` | five `0xcc` bytes | clean padding after target |
| Exact `imul edx, 0x0f4243` bytes `69 d2 43 42 0f 00` | one hit at file `0x000b75d6` / VA `0x004b81d6` | unique multiply instruction |
| Immediate bytes `43 42 0f 00` / decimal `1000003` | one hit at file `0x000b75d8` / VA `0x004b81d8` | unique multiplier immediate |
| Absolute VA dword `a0 81 4b 00` | zero hits | no raw VA pointer to target start |
| RVA dword `a0 81 0b 00` | zero hits | no raw RVA pointer to target start |
| `push 0x004b81a0` bytes `68 a0 81 4b 00` | zero hits | no obvious pushed function pointer |
| Direct `E8/E9`/short/conditional branch or call to `0x004b81a0` | zero hits | no hidden direct branch/call route to target start |
| Direct branch/call into target range from outside target | zero hits | no external entry into the body |
| Absolute VA dword into any byte of target body | zero hits | no absolute pointer into body |
| RVA dword into target body | three raw hits, all instruction-byte coincidences | not data/table refs |

The three RVA-like dword hits are not owner evidence:

| File / VA | Decoded value | Context |
| --- | --- | --- |
| file `0x000a616a` / VA `0x004a6d6a` | `0x000b81e8` | bytes inside an instruction stream, not data |
| file `0x0010e977` / VA `0x0050f577` | `0x000b81b4` | bytes inside an instruction stream, not data |
| file `0x0017d07a` / VA `0x0057dc7a` | `0x000b81e8` | bytes inside an instruction stream, not data |

Positive controls prove the branch/call scan can see neighboring real references:

| Destination | Direct branch/call hits |
| --- | --- |
| `0x004b81f0` / `FileExists` | `0x0049c87c`, `0x0049c88f`, `0x004dbcb5` |
| `0x004b8220` / `BuildFieldMapPath` | `0x004b0c0d` |
| `0x004b8290` / `RectAnchorAxisAdjustHelper` | `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161` |

This keeps the no-route result local to `00022J`. It is not a failure of the scan across the mixed helper neighborhood.

### Function / Neighbor Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent / Route | Current Status |
| --- | --- | --- | --- | --- | --- |
| `0x004b7f90-0x004b8194` | [UID:00022I] `RectAnchorTransformHelpers` | raw 3x3 anchor remap and rectangle-pair transform helpers | `TRUE` | `RectBounds` / [UID:0000N2] | separate predecessor; corrected end `0x004b8194` |
| `0x004b8194-0x004b81a0` | [UID:0000VN] `-ignored.md` | alignment padding | `FALSE` | ignored | confirmed `0xcc`; manual coverage row is stale |
| `0x004b81a0-0x004b81eb` | [UID:00022J] target | UTF-16/wide-string hash helper | `TRUE` | `NONE`; blank emitters | keep no-owner/non-emitting |
| `0x004b81eb-0x004b81f0` | [UID:0000VN] `-ignored.md` | alignment padding | `FALSE` | ignored | confirmed `0xcc` |
| `0x004b81f0-0x004b821e` | [UID:00022K] `FileExists` | `_wfopen`/`_fclose` wide-path existence helper | `TRUE` | `PathUtil` / [UID:0000MI] | separate successor with three callers |
| `0x004b8220-0x004b8284` | [UID:00015U] `BuildFieldMapPath` | FieldMapPane path-stem copy helper | `TRUE` | `FieldMapPane` / [UID:0000JA] | separate successor with FieldMapPane constructor caller |
| `0x004b8290-0x004b83c5` | [UID:00022L] `RectAnchorAxisAdjustHelper` | RectBounds anchor-axis primitive plus compiler switch data | `TRUE` | `RectBounds` / [UID:0000N2] | called only by [UID:00022I] |
| `0x004b83d0-0x004b8bd3` | [UID:00015V] `GeneralPurposePanel` | panel constructor/destructor/accessor/switch island | `TRUE` | `GeneralPurposePanel` / [UID:0000JQ] | separate following UI panel island |
| `0x004b8be0-0x004b8be8` | [UID:00022M] `GrafPortDirtyFlagSetter` legacy path | `GrafPort::EnableSoftwareBuffer` | `TRUE` | `GrafPort` class [UID:00005V] via [UID:0000JR] | separate render-port method |
| `0x004b8bf0-0x004bb8c4` | [UID:000160] `GrafPort` split index | mixed GrafPort/render neighborhood | parent `FALSE`; children vary | split index | not source-route evidence for target |

The target sits in a demonstrably mixed address neighborhood. The neighborhood itself cannot be used as a direct-owner signal because adjacent items route to different source families by their own positive evidence.

### Current Documentation Evidence

Current target page supports keeping the state unchanged:

- It records exact bounds, padding, current C001 IDA function definition/name, signature shape, no-call/no-global side-effect profile, unique `1000003` multiply, and repeated no-caller/no-xref/no-pointer checks.
- It already states `StringUtil` is the best semantic candidate but not a direct owner because no caller, pointer, table reference, or source-family artifact proves the route.
- It already rejects `CachedHashTable`, `RectBounds`, `PathUtil`, `FieldMapPane`, and `GeneralPurposePanel` as direct parents.

Current candidate-owner pages support the same conclusion:

- `StringUtil.md` explicitly says not to attach [UID:00022J] solely from wide-string hash semantics. It requires a caller, xref, raw VA/RVA pointer hit, table reference, or source-family artifact tying the helper to `StringUtil`.
- `StringBase.md` owns the ref-counted `mystr::StringBase` ANSI/UTF-16 buffer family around `0x00582500-0x00584d7e`. The target does not use `StringBase` object state, buffer headers, sentinels, pools, copy-on-write fields, or helper callees.
- `CachedHashTable.md` documents a separate fixed-entry cache/hash table class and helper island around `0x004c6160-0x004c659c`, with class/vtable/layout evidence and per-instance hash bytes. It has no receiver/table/caller relation to `0x004b81a0`.
- `RectBounds.md`, [UID:00022I], and [UID:00022L] document the geometry family and the four calls from the transform cluster into the axis helper. Those calls skip the hash helper, and the body shape is unrelated to geometry.
- `PathUtil.md` and [UID:00022K] own `FileExists` through `_wfopen`/`_fclose` path-probe behavior and three callers. That positive evidence starts at `0x004b81f0`, after padding, and does not transfer backward to `00022J`.
- `FieldMapPane.md` and [UID:00015U] own `BuildFieldMapPath` through a single FieldMapPane constructor caller and `.EPF` suffix context. The target has no FieldMapPane receiver, field access, path-stem behavior, or `.EPF` dependency.
- `GeneralPurposePanel.md` / [UID:00015V] cover the following panel island starting at `0x004b83d0`, separated by the rect-axis helper and padding. It has panel constructors, child-pane arrays, singleton globals, and active-tab switching, none of which appear in the target.
- `GrafPort.md`, [UID:00022M], and [UID:000160] document a later render-port neighborhood beginning at `0x004b8be0`/`0x004b8bf0`. GrafPort evidence is receiver-field and render-state based; it does not reach backward to the string hash target.

Generated and support report state:

- `auto-generated/-ag-memory-coverage.md` correctly lists [UID:00022J] as no-owner with owner `NONE`, blank emitters, no generated path, and non-emitting.
- `by-memory/-coverage-report.md` is stale for this immediate neighborhood. It still lists [UID:00022I] as ending textually at `0x004b8198`, the padding row as `0x004b8198-0x004b81a0`, and [UID:00022J] as `82%` with "no IDA function object." The exact replacement text is in the `Exact Supervisor Changes Needed` section below.
- `by-memory/-ignored.md` is already current for this subrange. It lists `0x004b8194-0x004b81a0` and `0x004b81eb-0x004b81f0` as alignment padding around the mixed geometry/hash/file helpers.

### Ranked Ownership / Routing Analysis

#### 1. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` - accepted

Evidence for:

- Target is a real source-shaped helper, but no current route proves where the original declaration lived.
- Repeated IDA documentation and current PE scans show no caller, code xref, data xref, raw VA pointer, raw RVA pointer, `push` pointer, external direct branch/call route, function table, vtable slot, or source-use context.
- The body has no callees or owner-specific dependencies that would point to a source family.
- Neighboring functions have positive route evidence while the target does not, proving the target's no-route state is specific.
- Current by-structure rules allow a reconstructable item to remain `CANONICAL_OWNER:NONE` and non-emitting until direct owner/output routing is safe.

Evidence against:

- The function is source-shaped and likely had some original source owner or came from copied utility code.
- `StringUtil` is a plausible semantic fit.

Decision:

- Accepted. This is the only current state that does not invent ownership or output routing.

#### 2. `StringUtil` / `NexusTK/util/StringUtil.cpp` - strongest semantic candidate, rejected for current assignment

Evidence for:

- The helper hashes a NUL-terminated UTF-16/wide string.
- `StringUtil` is the broad utility-string coordination module in the proposed source tree and current docs.
- `StringUtil` owns accepted wide-format wrappers, SimpleUString/SSO-7 support, shared string vector routing, and related Unicode/string infrastructure.

Evidence against:

- No caller, xref, raw pointer, table entry, source symbol, source string, import, or repeated sibling family ties `0x004b81a0` to `StringUtil`.
- The current `StringUtil.md` page explicitly excludes [UID:00022J] absent direct route evidence.
- Accepted `StringUtil` children have concrete route evidence, such as callers, layout coupling, or source-family helper relationships. [UID:00022J] has only behavior similarity.

Decision:

- Do not set `CANONICAL_OWNER:0000OB`. Do not set `EMITTER_UIDS:0000OB`. If future evidence appears, recheck `StringUtil` first.

#### 3. `StringBase` / `NexusTK/util/StringBase.cpp` - rejected

Evidence for:

- The helper consumes 16-bit string code units, so it is string-adjacent at the broad semantic level.

Evidence against:

- It accepts a raw wide pointer, not a `StringBase` object.
- It does not read or write ref-counted string buffer headers, sentinel storage, pool globals, capacity fields, COW state, vector slots, or `mystr::StringBase` RTTI/vtable state.
- It does not call the `0x00582500+` StringBase helper family.

Decision:

- Reject as owner/emitter. `StringBase` remains only semantic context.

#### 4. `CachedHashTable` / `NexusTK/util/CachedHashTable.cpp` - rejected

Evidence for:

- It is a utility hash/cache source candidate.

Evidence against:

- Current `CachedHashTable` docs describe a class/vtable/layout-backed fixed-entry cache at `0x004c6160+`, not a free UTF-16 string hash helper.
- The target has no `this` pointer, no slot state, no table walk, no per-instance random hash bytes, no vtable/RTTI relation, and no caller/data link to the CachedHashTable island.

Decision:

- Reject as owner/emitter.

#### 5. `RectBounds` / adjacent geometry support - rejected

Evidence for:

- Physical proximity: the predecessor [UID:00022I] and later [UID:00022L] are RectBounds/geometry-owned.

Evidence against:

- The target body hashes a wide string and does not read/write four-int rectangle layouts, anchor indices, edge pointers, or geometry fields.
- The predecessor RectAnchorTransformHelpers call `0x004b8290`, not `0x004b81a0`.
- Current PE positive controls find the four direct calls to `0x004b8290` but none to `0x004b81a0`.
- The address neighborhood is mixed and contains PathUtil, FieldMapPane, GeneralPurposePanel, and GrafPort items nearby.

Decision:

- Reject as owner/emitter. Proximity is insufficient and contradicted by body semantics.

#### 6. `PathUtil` / adjacent `FileExists` - rejected

Evidence for:

- Immediate successor [UID:00022K] at `0x004b81f0` is a PathUtil-owned wide-path helper.

Evidence against:

- Target has no file/path behavior, no `_wfopen`, no `_wstat`, no `_fclose`, no dispatch-table read, no path string, and no call/caller relation to `FileExists`.
- Five bytes of `0xcc` padding separate the target from `FileExists`.
- The successor's three callers are detectable by raw scan, while the target has none.

Decision:

- Reject as owner/emitter.

#### 7. `FieldMapPane` / `BuildFieldMapPath` - rejected

Evidence for:

- Nearby [UID:00015U] at `0x004b8220` is a FieldMapPane constructor helper.

Evidence against:

- The target does not copy path stems, scan for dots, call `_memmove`, append or relate to `.EPF`, receive `this+0xf8`, or have the FieldMapPane constructor caller at `0x004b0c0d`.
- The current PE positive control finds `0x004b0c0d -> 0x004b8220`, but no route to `0x004b81a0`.

Decision:

- Reject as owner/emitter.

#### 8. `GeneralPurposePanel` and `GrafPort` adjacent support - rejected

Evidence for:

- The broader physical neighborhood continues into `GeneralPurposePanel` at `0x004b83d0`, `GrafPort::EnableSoftwareBuffer` at `0x004b8be0`, and the `GrafPort` split index at `0x004b8bf0`.

Evidence against:

- `GeneralPurposePanel` evidence is child-pane arrays, panel constructors/destructors, singleton clears, active-child switching, and UI frame/effect helpers. None appear in the target.
- `GrafPort` evidence is receiver-based render-port state, software-buffer field `this+0x94`, DirectDraw/software backing, clip/draw-state/text helpers, and later render helper islands. None appear in the target.
- There is no code/data/pointer route from those modules to `0x004b81a0`.
- The target's only domain signal is a string hash algorithm, not UI panel or render-port state.

Decision:

- Reject as owner/emitter.

#### 9. External/library/runtime string hash helper - not enough for reclassification

Evidence for:

- The decimal `1000003` multiply/XOR recurrence resembles well-known string hash idioms, including Python-like hash shapes.
- The function is retained but currently unreferenced, which can happen with copied or stale utility fragments.

Evidence against:

- The body uses UTF-16 code units and lacks the `hash == -1 ? -2` sentinel repair associated with CPython string hash finalization.
- No Python/third-party import, symbol, source string, version marker, namespace, table, or broader external library island ties this helper to a known external source package.
- Reclassifying to runtime/third-party would be unsupported; it remains plausible NexusTK-owned or copied source-authored utility code.

Decision:

- Do not mark `RECONSTRUCTABLE:FALSE`. Do not create a third-party embed or external source route. Keep reconstructable but no-owner/non-emitting.

#### 10. New standalone utility owner/grouping - rejected for current evidence

Evidence for:

- If future evidence found related string-hash helpers or table users, a narrow `StringHash` helper group or `StringUtil` sub-family could be reasonable.

Evidence against:

- Current evidence supports exactly one isolated, unreferenced function and no callers, data users, sibling functions, source symbols, or output route.
- Creating `StringHash.cpp`, `WideStringHash.cpp`, or a new by-file utility owner from one orphan would add generated source structure without source-root evidence.
- A new grouping would still have no safe emitter path and would not improve reconstruction correctness.

Decision:

- Do not create a new owner/grouping now.

#### 11. `CANONICAL_OWNER:NONE` with one or more emitters - rejected

Evidence for:

- Current rules allow no canonical owner plus multiple emitters for shared constants, pooled literals, or other data with proven multiple source-use contexts.

Evidence against:

- [UID:00022J] is a function, not a pooled string literal, shared constant, or source-declared data object.
- There are zero proven source-use contexts.
- No generated file currently needs this helper inserted to compile or preserve behavior.

Decision:

- Keep `EMITTER_UIDS` blank.

## Heuristic / Inference Reanalysis And Validation

### Issue: Is the current helper name original or descriptive?

- Evidence checked: target page, prior C001 IDA repair notes, StringUtil/StringBase/CachedHashTable docs, raw PE bytes, generated reports, and source-tree context.
- Best inference: `WideStringHashHelper` is a descriptive documentation/IDA name, not proven original source spelling.
- Rejected alternatives: `StringUtil::Hash`, `CachedHashTable` method, `StringBase` method, `UnicodeHash`, or Python/runtime name. None have caller/symbol/type evidence.
- Final direction: keep `WideStringHashHelper` as a stable descriptive doc/IDA name. If future source-route evidence appears, prefer a VC6-era simple helper spelling such as `HashWideString` or `GetWideStringHash`, but do not claim that now.
- Impact: name uncertainty blocks final source C++ but does not lower behavior confidence.

### Issue: Is the signature source-facing enough?

- Evidence checked: raw bytes and target decompilation notes.
- Best inference: `uint32_t __cdecl WideStringHashHelper(const wchar_t *text)` is the best source-facing descriptive signature. `const uint16_t *` is also technically accurate for documentation, but `wchar_t *` is more plausible in a Windows C++ source tree.
- Rejected alternatives: object method, `StringBase`/`SimpleUString` receiver, path helper, or hash-table member function. No receiver/object state appears.
- Impact: signature is strong for behavior, but source declaration should not be emitted without a route.

### Issue: Is the `1000003` multiply enough to infer source family?

- Evidence checked: PE pattern scan found `69 d2 43 42 0f 00` once at `0x004b81d6` and immediate bytes `43 42 0f 00` once at `0x004b81d8`; target page records previous IDA operand scans with the same uniqueness.
- Best inference: the multiplier uniquely identifies this helper's algorithm in the binary but does not identify the original source file.
- Rejected alternatives: CPython/runtime owner from algorithm similarity alone. The helper lacks Python imports, source strings, broader runtime island, and `-1` sentinel repair.
- Impact: uniqueness supports behavior confidence, not ownership.

### Issue: Could the helper be live through an unmodeled pointer or branch?

- Evidence checked: raw PE scans for absolute VA, RVA, `push` immediate, direct branch/call to start, and external direct branch/call into the body. Positive controls for `0x004b81f0`, `0x004b8220`, and `0x004b8290` succeeded.
- Best inference: no PE-visible direct or table route currently exists.
- Rejected alternatives: hidden direct call, fallthrough from predecessor, pointer table, jump table, vtable slot. `0xcc` padding blocks fallthrough; pointer/branch scans are negative; neighbors have independent references.
- Remaining blocker: fully indirect runtime-computed calls cannot be disproven from static PE bytes alone, but no evidence supports one.
- Impact: no emitter/source-use route is justified.

### Issue: Does address adjacency prove source ownership?

- Evidence checked: neighboring docs and PE positive controls.
- Best inference: this `0x004b7f90-0x004b8bf0` region is a mixed linker neighborhood, not one source file. It contains RectBounds raw geometry, this unowned string hash helper, PathUtil file existence, FieldMapPane path-stem helper, RectBounds axis helper, GeneralPurposePanel UI code, and then GrafPort render code.
- Rejected alternatives: assign target to the nearest predecessor or successor. Each neighbor has its own positive owner evidence; the target has none.
- Impact: adjacency must not be used to route [UID:00022J].

### Issue: Should scores change?

- Evidence checked: current target page already documents exact range, behavior, C001 IDA function repair, no-route evidence, unique multiplier, and rejected candidates; current PE scan confirms that evidence. Live MCP was unavailable, so current IDA state could not be freshly queried.
- Best inference: keep `88/92`. Raising completion would be inappropriate because source owner, output route, final source name, and formal C++ remain unresolved. Lowering confidence is not needed because the current raw PE pass confirms the most important no-route claims and the target docs already record current IDA repair evidence.
- Impact: no target metadata change recommended.

### Issue: Is final C++ blocked or should a first draft be recommended?

- Evidence checked: current by-structure C++ gate and target metadata.
- Best inference: formal C++ must remain blank. The target is reconstructable and `(88 + 92) / 2 = 90`, but it has no nonblank emitter route to a generated source root. The gate fails on emitters/source placement.
- Rejected alternatives: emit through `StringUtil` because it is semantically plausible; emit through multiple consumers; create a new source file just to host the helper.
- Impact: final C++ is unsafe and should not be populated.

## First-Draft C++ Recommendation or exact do-not-populate proof

Do not populate `RECONSTRUCTION_CPP CODE` for [UID:00022J].

Exact proof:

1. The current code-entry gate requires `RECONSTRUCTABLE:TRUE`, one or more confirmed nonblank `EMITTER_UIDS` that surface to a valid generated source output path, and combined score greater than `85`.
2. [UID:00022J] satisfies only part of the gate: `RECONSTRUCTABLE:TRUE` and combined score `(88 + 92) / 2 = 90`.
3. [UID:00022J] has blank `EMITTER_UIDS`, no canonical owner, no proven source-use context, and no valid generated source root.
4. No candidate emitter is safe:
   - `StringUtil` is semantic only and explicitly excludes the helper without caller/pointer/table/source-family evidence.
   - `CachedHashTable`, `RectBounds`, `PathUtil`, `FieldMapPane`, `GeneralPurposePanel`, and `GrafPort` are rejected by body evidence and missing routes.
   - Multiple emitters are not justified because this is not shared data and no source-use context is proven.
   - A new standalone utility file would be synthetic and unsupported.
5. Formal code would therefore pollute generated output with an orphan helper in an invented source location.

Review-only semantic sketch, not to enter into the target page:

```cpp
// Review-only shape. Do not populate formal RECONSTRUCTION_CPP until an emitter/source route is proven.
static unsigned int WideStringHashHelper(const wchar_t *text)
{
    const wchar_t *cursor = text;
    while (*cursor != L'\0')
        ++cursor;

    unsigned int length = static_cast<unsigned int>(cursor - text);
    unsigned int hash = static_cast<unsigned int>(text[0]) << 7;

    for (unsigned int i = 0; i < length; ++i)
        hash = static_cast<unsigned int>(text[i]) ^ (1000003u * hash);

    return hash ^ length;
}
```

This sketch is behavior-equivalent to the documented helper but is intentionally not a source recommendation because the original owner, helper name, declaration style, and route are not proven.

## Exact Supervisor Changes Needed including coverage row text if any

### Target Metadata / Body

No target metadata change is recommended. Keep [UID:00022J] at `88/92`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and blank formal C++.

No target body replacement is required for correctness. The target page already contains the core no-owner/no-emitter evidence at report-level detail. The only caveat is that this report adds a fresh 2026-06-18 PE recheck but no fresh live IDA MCP recheck.

### Generated Reports

Do not manually edit `auto-generated/-ag-memory-coverage.md`. Its current generated no-owner rows are correct.

Current generated row for the owner table is correct:

```markdown
| [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` |  |
```

### `by-memory/-ignored.md`

No replacement needed. It already lists `0x004b8194-0x004b81a0` and `0x004b81eb-0x004b81f0` as alignment padding around the mixed geometry/hash/file helpers.

### `by-memory/-coverage-report.md`

Replacement is needed because the current rows around [UID:00022J] are stale. Placement context: in `source-3/project-documentation/by-memory/-coverage-report.md`, replace the current rows for [UID:00022I], the internal RectAnchor padding, the RectAnchor-to-WideStringHashHelper padding, and [UID:00022J]. These are currently between the existing `0x004b7f87-0x004b7f90` padding row and the existing `0x004b81eb-0x004b81f0` padding row.

Replace these current rows:

```markdown
    - [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) 0x004b7f90-0x004b8198 | raw-function-cluster | RectAnchorTransformHelpers : reconstructable : 76% : strong : RectBounds-owned raw 3x3 anchor remap and rectangle-pair transform helpers; range, padding, behavior, and axis-helper dependency are documented, while original names remain inferred.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004b8005-0x004b8010 | padding | internal RectAnchorTransform helper alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004b8198-0x004b81a0 | padding | RectAnchorTransformHelpers to WideStringHashHelper alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 82% : strong : Raw UTF-16 string hash helper with current IDA-confirmed const-uint16 input, no-call/no-global side-effect profile, exact `0xcc` boundaries, unique decimal `1000003` multiply/XOR site, no IDA function object, and no direct callers/xrefs, so source owner remains unassigned under the corrected gate.
```

With this exact block:

```markdown
    - [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) 0x004b7f90-0x004b8194 | raw-function-cluster | RectAnchorTransformHelpers : reconstructable : 86% : strong : RectBounds-owned raw 3x3 anchor remap and rectangle-pair transform helpers; current docs correct the cluster end to `0x004b8194`, internal padding to `0x004b8004-0x004b8010`, and successor padding to `0x004b8194-0x004b81a0`; behavior, axis-helper dependency, four calls to [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md), and RectBounds source-family ownership are documented while original helper names remain inferred.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004b8004-0x004b8010 | padding | internal RectAnchorTransform helper alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004b8194-0x004b81a0 | padding | RectAnchorTransformHelpers to WideStringHashHelper alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : B001 2026-06-18 current-source-routing review keeps `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and blank formal C++; C001-009 defined the exact raw body as IDA function `WideStringHashHelper`, and fresh PE/raw scans reconfirm the isolated `0x4b` prologue/body/return range, `0x004b8194-0x004b81a0` plus `0x004b81eb-0x004b81f0` `0xcc` padding, unique `1000003` wide-string hash multiply at `0x004b81d6`, no VA/RVA pointer, no `push` pointer, no external branch/call route, and normal positive route controls for adjacent FileExists/BuildFieldMapPath/RectAnchor helpers. `StringUtil` remains the best semantic candidate but no direct owner or emitter route is proven.
```

The existing next row should remain after this replacement:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004b81eb-0x004b81f0 | padding | WideStringHashHelper to FileExists alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
```

### Tracking Files

Supervisor should mark the active no-owner tracker row for assignment `B001-goal2-wide-string-hash-helper-current-source-routing-00022J-20260618` as complete-no-change and point it at this report:

```text
tools/leaser/Agents/Agent-B001/research/00022J-WideStringHashHelper-current-source-routing.md
```

No direct edit was made by B001.

## Validation Performed / Evidence Gaps

### Validation Performed

Read and followed:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`.
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/goal.md`.
- `source-3/project-documentation/by-structure.md`.
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/inference_research.md`.
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`.

Documentation reviewed:

- Target: `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`.
- Coverage/generated state: `auto-generated/-ag-memory-coverage.md`, `by-memory/-coverage-report.md`, `by-memory/-ignored.md`.
- Candidate source docs: `by-file/StringUtil.md`, `by-file/StringBase.md`, `by-file/CachedHashTable.md`, `by-file/RectBounds.md`, `by-file/PathUtil.md`, `by-file/FieldMapPane.md`, `by-file/GrafPort.md`.
- Neighbor docs: [UID:00022I], [UID:00022K], [UID:00015U], [UID:00022L], [UID:00015V], [UID:00022M], [UID:000160].
- Prior executed B-agent reports for [UID:00022J] under Agent-B001, Agent-B002, and Agent-B003 research archives.
- Current tracking context in `tools/leaser/Agents/no_owner_b-agent-tracker.md` and `Supervisor_notes.md`.

Tool / binary checks:

- Attempted live IDA MCP `tools/list` at `http://127.0.0.1:13337/mcp`; result: unable to connect to remote server.
- Verified PE copies:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247E04E20B65D6414C7238AA8FF5515`.
  - `e:\NTK\Resources\NexusTK\NexusTK.exe`, MD5 `4247E04E20B65D6414C7238AA8FF5515`.
- Parsed PE headers and section mapping.
- Recomputed target raw offset, body bytes, predecessor padding, successor padding.
- Scanned for exact target body, exact `imul edx, 0x0f4243`, decimal `1000003` immediate bytes, absolute VA/RVA target pointers, `push 0x004b81a0`, direct branch/call routes to target and into target, and direct branch/call positive controls for neighboring helpers.

No validator run was needed because no validator-managed by-* files were edited.

### Evidence Gaps

- Live IDA MCP was unavailable, so this pass did not freshly query `lookup_funcs`, `xrefs_to`, `callers`, `callees`, or `decompile` on 2026-06-18. Current IDA function-definition evidence is taken from the target page and accepted executed reports, while current raw PE evidence was independently rechecked.
- Static PE scans cannot absolutely disprove runtime-computed indirect calls, computed hashes of function pointers, packed/runtime-generated code, or manually constructed addresses. No documentation, IDA, or PE evidence currently supports any such route for [UID:00022J].
- Original source file/name proof remains absent. The best forced semantic candidate is `StringUtil`, but assigning it would rely on behavior similarity alone and would violate current direct-owner rules.

### Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/00022J-WideStringHashHelper-current-source-routing.md`.
- Modified outside Agent-B001 research: none.
- by-* docs edited: none.
- generated/project-level/IDA/generated-source files edited: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00022J-WideStringHashHelper-current-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
