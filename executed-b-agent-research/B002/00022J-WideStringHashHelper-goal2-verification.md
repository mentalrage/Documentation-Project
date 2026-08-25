** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Final Recommendation

Keep [UID:00022J] `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` unchanged.

- Final state: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP`.
- Owner decision: no canonical owner is currently defensible. `StringUtil` is the best semantic candidate if forced, but current IDA/PE evidence still provides no caller, xref, raw pointer, table, branch, source/debug, or source-family route that ties this exact helper to `StringUtil` or any other source root.
- Emitter decision: keep emitters blank. This is not a pooled literal/shared-constant case with proven source-use contexts; it has no proven source-use context at all, so any output route would be speculative.
- Split/reclass decision: no split, merge, child page, reclassification, or IDA repair is justified. The current IDA session already models `WideStringHashHelper` as one exact `0x4b`-byte function bounded by `0xcc` padding.
- Coverage report: no exact `by-memory/-coverage-report.md` replacement row is required. The current row is semantically correct and already records the no-owner/non-emitting rationale; do not edit it for this pass.
- Score/C++ decision: keep `88/92`; do not add reconstruction C++ because there is no confirmed emitter route.
- Confidence: high for the no-owner/non-emitting recommendation, high for the exact behavior and boundary, medium-high for original source provenance because the helper remains unreferenced.

---

## Supporting Research

## Target

- Agent: `Agent-B002`.
- Assignment: fresh Goal 2 no-owner memory verification from the supervisor.
- Target UID: `00022J`.
- Target path: `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`.
- Coverage source: `auto-generated/-ag-memory-coverage.md`.
- Current generated state: no-owner row, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, no generated output path, no code.
- Prior executed report reviewed as evidence only: `Agent-B002/research/executed/00022J-WideStringHashHelper-live-goal2-no-owner-pass.md`.
- Final report path: `tools/leaser/Agents/Agent-B002/research/00022J-WideStringHashHelper-goal2-verification.md`.

Current target header checked:

```text
*** UID:00022J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No lease was used because this pass created only this Agent-B002 research report and did not edit any non-agent documentation file.

## Executive Recommendation

The current no-owner/non-emitting state is legitimate. The helper is real source-like code and should remain `RECONSTRUCTABLE:TRUE`, but every owner/emitter candidate still depends on semantic fit or address proximity rather than a direct source route.

The strongest positive facts are about behavior and boundaries: current IDA models `WideStringHashHelper` at `0x004b81a0`, size `0x4b`, and Hex-Rays/disassembly show a UTF-16 rolling hash using decimal `1000003` / `0x0f4243`. The strongest ownership facts are negative: no callers, no incoming xrefs, no data refs, no raw VA/RVA pointer bytes, no raw call/jump/branch route, and no source-family artifact.

Therefore:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE:[[[]]]
```

## Evidence Standards Used

This pass followed the current `by-structure.md` owner/emitter split:

- `CANONICAL_OWNER` requires a defensible direct semantic owner.
- `EMITTER_UIDS` are output routes and must surface to valid source roots.
- `RECONSTRUCTABLE:TRUE` can remain ownerless/non-emitting when code is source-like but its source route is not known.
- Do not emit C++ merely because behavior is understood or because a semantic owner is plausible.

This pass also applied `inference_research.md` guidance:

- Direct machine-code facts, xrefs, callers/callees, and raw pointer evidence outweigh address adjacency or naming intuition.
- Nearby utility code and semantic similarity are useful leads, not ownership proof.
- Source-file ownership without debug/source metadata must be probabilistic and should not be asserted when the evidence chain is absent.

Evidence collected:

- Current target page.
- Current `auto-generated/-ag-memory-coverage.md` row.
- Current `by-memory/-coverage-report.md` row.
- Current tracker row history for `00022J`.
- Current candidate owner docs: `StringUtil`, `CachedHashTable`, `RectBounds`, `PathUtil`, and `proposed-source-tree.md`.
- Neighboring memory docs: `RectAnchorTransformHelpers`, `FileExists`, and `RectAnchorAxisAdjustHelper`.
- Live IDA MCP evidence from session `a001_goal2_class_batch`.
- Independent raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## Current Documentation Evidence

The target page currently documents:

- likely signature `uint32_t __cdecl WideStringHashHelper(const uint16_t *text)`;
- no side effects, no calls, no globals;
- UTF-16 length scan, seed from first code unit shifted left by seven, `1000003` multiply/XOR loop, final XOR with string length;
- exact boundary `0x004b81a0-0x004b81eb`;
- preceding padding `0x004b8194-0x004b81a0`;
- following padding `0x004b81eb-0x004b81f0`;
- rejected owner candidates, with `StringUtil` as the best semantic but still unproven candidate.

The current generated memory coverage row reports:

```text
[UID:00022J] ... | no-owner | `NONE` |  |  | no |  | ...
```

The current `by-memory/-coverage-report.md` row is already semantically correct. It says the B002 live Goal 2 pass keeps `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`, and cites current-style evidence: modeled function, exact hash body, no callers/xrefs/callees/code refs/data refs/VA/RVA immediates, unique `1000003` encoding, adjacent padding, neighboring-helper contrast, and no raw PE pointer or branch route. No replacement row is required.

## Live IDA MCP Facts

IDA MCP session used:

```text
session_id: a001_goal2_class_batch
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
```

Function lookup:

```text
0x004b8194: not a function
0x004b8198: not a function
0x004b81a0: WideStringHashHelper, size 0x4b
0x004b81eb: not a function
0x004b81f0: sub_4B81F0, size 0x2e
0x004b8220: sub_4B8220, size 0x64
0x004b8290: sub_4B8290, size 0x11e
```

Boundary bytes:

```text
0x004b8194-0x004b81a0:
cc cc cc cc cc cc cc cc cc cc cc cc

0x004b81a0-0x004b81eb:
55 8b ec 56 8b 75 08 8b ce 57 8d 51 02 0f 1f 00
66 8b 01 83 c1 02 66 85 c0 75 f5 2b ca 0f b7 16
d1 f9 8b f9 c1 e2 07 83 e9 01 78 17 0f 1f 40 00
0f b7 06 8d 76 02 69 d2 43 42 0f 00 33 d0 83 e9
01 79 ed 33 d7 5f 8b c2 5e 5d c3

0x004b81eb-0x004b81f0:
cc cc cc cc cc
```

Disassembly facts:

```text
4b81a0: push ebp
4b81a4: mov esi, [ebp+arg_0]
4b81b0: mov ax, [ecx]
4b81b6: test ax, ax
4b81b9: jnz short loc_4B81B0
4b81bd: movzx edx, word ptr [esi]
4b81c4: shl edx, 7
4b81d0: movzx eax, word ptr [esi]
4b81d6: imul edx, 0F4243h
4b81dc: xor edx, eax
4b81e3: xor edx, edi
4b81e6: mov eax, edx
4b81ea: retn
```

Hex-Rays currently renders:

```text
unsigned int __cdecl WideStringHashHelper(const unsigned __int16 *a1)
{
  const unsigned __int16 *v1;
  unsigned int v2;
  int v3;
  int i;
  int v5;

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

`analyze_function 0x004b81a0` reports:

```text
name: WideStringHashHelper
prototype: unsigned int __cdecl(const unsigned __int16 *)
size: 75
strings: none
callees: none
callers: none
xrefs to: none
xrefs from: internal code-flow only at 0x4b81a1
basic blocks: 6
cyclomatic complexity: 4
```

Direct xref checks:

```text
xrefs_to 0x004b81a0: 0
xrefs_to 0x004b8194: 0
xrefs_to 0x004b8198: 0
xrefs_to 0x004b81eb: 0
```

Neighbor contrast xrefs:

```text
xrefs_to 0x004b81f0: 3
  0x0049c87c in sub_49C800
  0x0049c88f in sub_49C800
  0x004dbcb5 in sub_4DBC60

xrefs_to 0x004b8220: 1
  0x004b0c0d in sub_4B0BB0

xrefs_to 0x004b8290: 4
  0x004b803e
  0x004b809f
  0x004b80ff
  0x004b8161
```

Uniqueness checks:

```text
find_bytes "69 d2 43 42 0f 00": 0x004b81d6 only
find_bytes "43 42 0f 00": 0x004b81d8 only
find_bytes "a0 81 4b 00": 0 hits
find_bytes "a0 81 0b 00": 0 hits
```

The uniqueness of the immediate supports behavior identification, not source ownership. The absence of VA/RVA byte hits supports the no-emitter conclusion.

## Raw PE Verification

Raw executable checked:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
MD5: 4247e04e20b65d6414c7238aa8ff5515
```

Relevant section mapping:

```text
.text  RVA 0x1000-0x20c600 raw 0x400-0x20ba00
.rdata RVA 0x20d000-0x26c200 raw 0x20ba00-0x26ac00
.data  RVA 0x26d000-0x27a800 raw 0x26ac00-0x278400
.rsrc  RVA 0x29d000-0x2b2e00 raw 0x278400-0x28e200
```

Target mapping:

```text
VA 0x004b81a0 -> raw 0x0b75a0
```

Raw scan results:

```text
imul 1000003 encoding 69 d2 43 42 0f 00:
  raw 0x0b75d6 -> VA 0x004b81d6

little-endian immediate 1000003 / 43 42 0f 00:
  raw 0x0b75d8 -> VA 0x004b81d8

little-endian VA 0x004b81a0 / a0 81 4b 00:
  0 hits

little-endian RVA 0x000b81a0 / a0 81 0b 00:
  0 hits

rel32 call/jmp target 0x004b81a0:
  0 hits

rel8 branch target 0x004b81a0:
  0 hits
```

Execution note: an initial raw branch-scan script failed on PowerShell signed-byte conversion and was rerun with explicit signed conversion; the successful results above are the evidence used for this report.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b8194-0x004b81a0` | `by-memory/-ignored.md` coverage row | alignment padding before helper | false/ignored | none | coverage `100/strong` | no child needed |
| `0x004b81a0-0x004b81eb` | `00022J` / `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` | UTF-16 rolling hash helper | true | none | `88/92` | keep no-owner/non-emitting |
| `0x004b81eb-0x004b81f0` | `by-memory/-ignored.md` coverage row | alignment padding after helper | false/ignored | none | coverage `100/strong` | no child needed |

No nested function, local table, literal, vtable, switch data, or mixed-owner subrange exists inside `0x004b81a0-0x004b81eb`.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`

Evidence for:

- Live IDA reports zero incoming xrefs and zero callers to `0x004b81a0`.
- `analyze_function` reports zero callees, zero strings, no external xref route, and only internal code flow.
- Raw PE scan finds no VA pointer bytes, no RVA pointer bytes, no rel32 call/jmp target, and no rel8 branch target to `0x004b81a0`.
- Neighboring functions have normal reference surfaces, proving the no-reference result is specific to this helper and not a tooling-wide blind spot.
- Current candidate owner docs explicitly require a caller/source-family route before assignment.

Evidence against:

- The helper is source-like and string-related, making `StringUtil` semantically attractive.
- It is in `.text`, not padding or import/runtime data, so it should not be ignored.

Decision: accepted. This is a valid reconstructable no-owner/non-emitting helper. The behavior is known, but no canonical owner or output route is proven.

### 2. [UID:0000OB] `StringUtil`

Evidence for:

- The helper consumes UTF-16 input and Hex-Rays recognizes a `wcslen`-style scan.
- The recurrence is a string hash, and `StringUtil.cpp` is the current broad Unicode/string utility source root.
- `StringUtil` is at `87/88`, so it clears the parent score gate if evidence later appears.

Evidence against:

- No caller or data reference links this exact helper to `StringUtil`.
- No raw VA/RVA pointer, branch route, table entry, source string, debug artifact, or family-local call edge exists.
- Current `StringUtil.md` explicitly excludes `00022J` without a caller/xref/raw pointer/table/source-family artifact.
- The documented `StringUtil` children cluster around SimpleUString, StringBase, StringIter, wide-format wrappers, map-node support, and static string storage; this helper is not connected to those clusters.

Decision: rejected for assignment or emitter routing. If forced to choose a best semantic candidate, choose `StringUtil`, but current rules require more than semantic fit.

### 3. New `HashUtil` / `StringHashUtil` source file

Evidence for:

- The body is a compact standalone string-hash helper.
- The proposed source tree already has utility algorithm roots such as `MD5.cpp` and `Crc16.cpp`.

Evidence against:

- No other helper shares this `1000003` recurrence.
- No caller, table, global, source name, or adjacent hash-family cluster suggests a real source file.
- Creating a one-function source root would encode invented structure for an unreferenced function.

Decision: rejected. No new source file/grouping is justified.

### 4. [UID:0000N2] `RectBounds`

Evidence for:

- Physical neighborhood: the helper sits between RectBounds anchor-transform helpers and later RectBounds axis-adjust helper.
- `RectBounds` is a strong parent for the surrounding geometry cluster.

Evidence against:

- The helper hashes UTF-16 strings and touches no rectangle fields, geometry structs, anchors, offsets, or switch tables.
- `RectAnchorTransformHelpers` has no xrefs to the hash helper.
- The axis helper at `0x004b8290` has exactly four calls, all from the transform cluster, not from this helper.
- Padding separates the hash helper from surrounding geometry/path helpers.

Decision: rejected. Address proximity is weak evidence and is directly contradicted by behavior and xref separation.

### 5. [UID:0000MI] `PathUtil`

Evidence for:

- Immediate successor `0x004b81f0` is the assigned `FileExists` helper owned by `PathUtil`.

Evidence against:

- The target has no path/file/CRT dispatch behavior.
- It does not reference the `_wfopen` dispatch table, `_fclose`, file paths, archive loaders, or the adjacent `FileExists` helper.
- No xref edge ties it to `PathUtil`.

Decision: rejected.

### 6. [UID:0000HZ] `CachedHashTable`

Evidence for:

- The helper is a hash-like algorithm and `CachedHashTable` is a utility hash/cache source root.

Evidence against:

- `CachedHashTable` is a separate class/vtable/helper island at `0x004c6160-0x004c659c`.
- The target has no object layout, vtable store, entry-buffer access, slot-state access, constructor/destructor relationship, or class-local xref.
- `CachedHashTable` currently scores `84/88`, so it does not clear the strict parent completion gate even if there were evidence.

Decision: rejected.

### 7. Existing algorithm utility roots such as `MD5` or `Crc16`

Evidence for:

- The helper computes a hash value, and those modules are algorithm/hash-related utility roots.

Evidence against:

- The helper does not share constants, xrefs, wrappers, caller clusters, inputs/outputs, or algorithm structure with MD5/Crc16 docs.
- The MD5/Crc16 roots have their own well-defined helper islands and cross-subsystem caller evidence.

Decision: rejected.

## Split, Merge, Reclassification, And IDA Repair Review

No split is justified:

- The page covers one modeled function at `0x004b81a0-0x004b81eb`.
- The body is exactly `0x4b` bytes and has no embedded child function/data item.
- Padding before and after is already represented as ignored coverage.

No merge is justified:

- The previous RectBounds helper cluster ends at `0x004b8194`.
- The successor `FileExists` starts at `0x004b81f0`.
- The following `BuildFieldMapPath` and `RectAnchorAxisAdjustHelper` have separate behavior and separate ownership evidence.

No reclassification is justified:

- This is not compiler padding, jump table data, import/runtime glue, vtable data, or a known third-party library body.
- It is a source-like helper function and should remain `RECONSTRUCTABLE:TRUE`.

No IDA repair is required:

- Current IDA already has the exact function defined and named as `WideStringHashHelper`.
- The predecessor/successor padding and adjacent function starts are coherent.

## Why Reconstructable But Non-Emitting Is Correct

`RECONSTRUCTABLE:TRUE` is correct because the helper is real code in `.text` with a normal prologue/epilogue, stable behavior, no runtime/import-only signature, and a custom string-hash body. It is not disposable alignment, compiler scaffolding, or purely external dependency code.

Blank `EMITTER_UIDS` is also correct because emitter routing is an output-source decision. There must be a proven source-use context or valid source root route. Current evidence has no caller or address-taken route at all. Unlike pooled strings/constants with multiple proven consumers, this helper has zero proven consumers. Adding `StringUtil` or any other emitter would be a guess.

The correct model is therefore:

```text
source-like helper retained for documentation and future reconstruction
no proven declaration owner
no proven output route
```

## Exact Recommended Changes

Target page:

```text
No change.
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE:[[[]]]
```

Coverage report:

```text
No direct edit to by-memory/-coverage-report.md.
No replacement row is required.
```

Generated reports:

```text
No manual generated-file change.
The generated no-owner/non-emitting state is the intended current state.
```

Children/splits:

```text
No child pages.
No split.
```

## Follow-Up Actions

- Supervisor: accept as complete-no-change if this verification is sufficient; no coverage row action required.
- A-agents: no immediate edit needed.
- Future B-agent/string utility work: revisit only if new evidence finds a caller, indirect table entry, raw pointer, source/debug artifact, or source-family cluster tying `0x004b81a0` to a real source root.

## Confidence

- Recommendation confidence: high.
- Boundary/behavior confidence: high. Current IDA function modeling, bytes, decompilation, and disassembly agree.
- Ownership/source confidence: intentionally unresolved. `StringUtil` remains the best semantic fallback, but current evidence does not support assignment.
- Remaining uncertainty: original source provenance cannot be recovered from current static evidence because no source-use route is visible.

## Validator Results

- Commands run: none.
- Reason: report-only verification; no by-* page, generated file, coverage report, or split child was edited.
- Unresolved validator issues: not checked in this pass.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/00022J-WideStringHashHelper-goal2-verification.md`
- Modified: none outside this Agent-B002 research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00022J-WideStringHashHelper-goal2-verification.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
