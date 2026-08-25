** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022J WideStringHashHelper Post-C001 Ownership Research

Revision: B001-00022J, 2026-06-12

## Finalized Report / Current Recommendation

- Target: [UID:00022J] `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`
- Final recommendation: keep [UID:00022J] reconstructable, scored `88/92`, and parent-blank. Do not assign it to `StringUtil`, `StringBase`, `CachedHashTable`, `RectBounds`, `PathUtil`, `FieldMapPane`, or a new source file from current evidence.
- Source-owner conclusion: the best semantic candidate remains [UID:0000OB] `StringUtil`, but it is not assignment-quality. The post-C001 IDA function/name repair proves the helper body; it does not reveal any caller, code/data xref, raw VA/RVA pointer, table entry, import/name artifact, or source-family breadcrumb tying the helper to a direct owner.
- Split/repair conclusion: no split or child repair is justified. The helper is one exact `0x4b` function with verified padding before and after. The adjacent helpers have separate positive ownership evidence and should remain in their current pages.
- Documentation action recommended: no by-* page edits in this pass. The current target page and `StringUtil` exclusion already match the live evidence.
- Coverage action recommended: no direct edit to `by-memory/-coverage-report.md`. The current row is already correct after C001; exact no-op row is included below for supervisor verification.
- Confidence: `94/100` for exact range/body/side-effect facts, `92/100` for "do not assign now", `68/100` for `StringUtil` as the best semantic original-source candidate. The semantic candidate stays below the strict direct-parent threshold.

## Exact Supervisor Actions

1. Mark B001-00022J / [UID:00022J] reviewed with parent still blank.
2. Do not create a new parent page for this isolated helper.
3. Do not alter `by-memory/-coverage-report.md` unless the supervisor wants to re-apply the existing no-op row.

Exact `by-memory/-coverage-report.md` row to keep unchanged:

```text
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : C001-009 defined the exact raw body as IDA function `WideStringHashHelper` after reconfirming the isolated `0x4b` prologue/body/return range, adjacent `0xcc` padding, `wcslen` plus `1000003` wide-string hash recurrence, no callers/xrefs/raw VA/RVA pointer/table reference, and normal xrefs to adjacent FileExists/BuildFieldMapPath/RectAnchor helpers. Parent remains blank because `StringUtil` is semantic only and no direct owner evidence is proven.
```

Exact `auto-generated/-ag-memory-coverage.md` row to keep unchanged:

```text
| [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | unassigned |  |  | no |  | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` |  |
```

## Supporting Research

## Target State

- Current target metadata: `COMPLETION:88`, `CONFIDENCE:92`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:` blank.
- C001-009 state: IDA 9.1 now has a real function at `0x004b81a0`, named `WideStringHashHelper`, size `0x4b`.
- B001-00022J scope: deeper ownership/source-family inference after that IDA repair, not behavior recovery.
- Lease workflow: B001 target lease was acquired/renewed for the by-memory target before finalizing this report. No by-* file edits were made.

## Live IDA MCP Evidence, 2026-06-12

### Function identity and boundaries

`lookup_funcs` now reports:

| Query | IDA result |
| --- | --- |
| `0x004b8198` | not a function |
| `0x004b81a0` | `WideStringHashHelper`, size `0x4b` |
| `WideStringHashHelper` | `0x004b81a0`, size `0x4b` |
| `0x004b81eb` | not a function |
| `0x004b81f0` | `sub_4B81F0`, size `0x2e` |
| `0x004b8220` | `sub_4B8220`, size `0x64` |
| `0x004b8290` | `sub_4B8290`, size `0x11e` |

Byte reads confirm the local boundary:

- `0x004b8198-0x004b81a0`: eight `0xcc` padding bytes after `RectAnchorTransformHelpers`.
- `0x004b81a0-0x004b81eb`: one prologue/body/return helper.
- `0x004b81eb-0x004b81f0`: five `0xcc` padding bytes before `FileExists`.

No range split is supported. The successor `0x004b81f0` starts a separate `_wfopen`/`fclose` path helper; `0x004b8220` starts the FieldMapPane path-stem helper; `0x004b8290` is the rect-anchor axis helper.

### Function behavior

`analyze_function 0x004b81a0` reports:

```c
int __cdecl WideStringHashHelper(const unsigned __int16 *a1)
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

Disassembly facts:

- Reads only `[ebp+8]` as the UTF-16 input pointer.
- Scans 16-bit words to NUL and computes a code-unit length.
- Seeds from the first word shifted left by seven.
- Loops with `imul edx, 0x0f4243` and `xor edx, eax`.
- Returns `length ^ hash` in `eax`.
- Has no callees, no global reads/writes, no table reads, no heap/runtime calls, and no strings.

The algorithm resembles a known `1000003` multiply/XOR string-hash idiom, but the body lacks a `hash == -1 ? -2` sentinel repair and has no Python/runtime/library import or name evidence. That resemblance is useful semantic context, not source ownership proof.

### Xrefs, callers, pointers, and constants

Post-C001 reachability checks still find no owner signal:

- `xrefs_to 0x004b81a0`: zero.
- `xrefs_to WideStringHashHelper`: zero.
- `xref_query both 0x004b81a0`: only an internal function-start fallthrough/xref from `0x004b81a0` to `0x004b81a1`; no external incoming reference.
- `find code_ref 0x004b81a0`: zero.
- `find data_ref 0x004b81a0`: zero.
- `find immediate 0x004b81a0`: zero.
- `find immediate 0x000b81a0`: zero.
- `find_bytes a0 81 4b 00`: zero raw VA pointer hits.
- `find_bytes a0 81 0b 00`: zero raw RVA pointer hits.

Hash-pattern uniqueness checks:

- `find immediate 1000003` / `0x0f4243`: one match at `0x004b81d6`.
- `find_bytes 43 42 0f 00`: one match at `0x004b81d8`, the immediate inside this helper.
- `find_bytes 69 d2 43 42 0f 00`: one match at `0x004b81d6`, the exact `imul edx, 0x0f4243` encoding.

Neighbor contrast:

| Address | Positive ref evidence |
| --- | --- |
| `0x004b81f0` / `FileExists` | callers at `0x0049c87c`, `0x0049c88f`, and `0x004dbcb5` |
| `0x004b8220` / `BuildFieldMapPath` | caller at `0x004b0c0d` in the FieldMapPane constructor |
| `0x004b8290` / rect-anchor axis helper | code refs from the rect-anchor raw cluster at `0x004b803e`, `0x004b809f`, `0x004b80ff`, and `0x004b8161` |

This contrast matters: IDA is not generally blind in this address neighborhood. The no-reference state is specific to [UID:00022J].

### Name, string, and import sweeps

IDA name/string sweeps did not reveal a source breadcrumb:

- Function-name query for `hash` finds only `WideStringHashHelper` among functions.
- Name query for `hash` finds `WideStringHashHelper` plus `CachedHashTable` RTTI/name records. It does not find a string-hash module, callback table, or project-source symbol.
- Name query for `WideString`, `StringUtil`, `StringBase`, and `SimpleUString` finds `WideStringHashHelper` and many `mystr::StringBase<wchar_t,...>` callback/template RTTI names, but no link from those names to `0x004b81a0`.
- String regex for `python|hash|StringUtil|WideString|StringBase|SimpleUString` finds the minimap `HashList.txt` URL, `CachedHashTable` RTTI, and `StringBase` RTTI strings. None reference this helper.
- Import query for Python/`Py*` and `hash` returns no matches.

Conclusion from IDA: the C001 function repair increases behavior confidence but does not create a direct source-owner link.

## Documentation Evidence

### Target page

The target page already records the C001 IDA function creation and post-fix decompilation, plus the absence of callers, xrefs, raw pointers, table refs, and owner artifacts. Its current `88/92` score is justified; no page edit is needed for this pass.

### StringUtil

[UID:0000OB] `StringUtil` is the best semantic candidate because it owns shared UTF-16/string infrastructure, `SimpleUString`, `SimpleUStringVector`, wide-format wrappers, and wide-string keyed container support. It also now contains an explicit scope exclusion:

- Do not attach [UID:00022J] solely from wide-string hash semantics.
- C001 proved the function body/name, but no caller/xref/raw pointer/table/source-family evidence links it to `StringUtil`.

That exclusion matches the live B001-00022J findings and should remain.

### StringBase / SimpleUString

[UID:0000OA] `StringBase` is the direct owner for the ref-counted ANSI/UTF-16 string-buffer implementation around `0x00582500-0x00584d7d`, with preserved `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>` RTTI/vtable evidence.

[UID:0000D9] `SimpleUString` is the SSO-7/string facade coordination page attached to `StringUtil`, while pointer-backed helpers stay with `StringBase`.

[UID:00022J] does not read or write a string object layout, sentinel, ref-counted header, capacity field, vector slot, allocator pool, or `mystr::StringBase` vtable. It takes one raw `const uint16_t *` and returns a scalar hash. The string-family pages therefore provide semantic context, not direct source placement.

### Accepted string-family contrast

[UID:0001ZY] `WideStringMapNodeSupport` is assigned to `StringUtil` because it has positive evidence: wide-string payload layout, 44-byte tree nodes, and caller spread across minimap and metadata code.

[UID:0002LN] `WideRangeCompare` is assigned to `StringBase` because it has positive evidence: exact function range, 29 start xrefs from 14 callers, no-callee comparator behavior, and the surrounding pointer-backed string-buffer family.

[UID:00022J] lacks the decisive element those pages have: a direct caller/layout/source-family surface.

### Neighbor docs

- [UID:00022I] `RectAnchorTransformHelpers` and [UID:00022L] `RectAnchorAxisAdjustHelper` have a direct geometry xref relationship and belong with `RectBounds`.
- [UID:00022K] `FileExists` belongs with `PathUtil` because its `_wfopen`/`fclose` behavior and callers tie it to path/file probing.
- [UID:00015U] `BuildFieldMapPath` belongs with `FieldMapPane` because it has one constructor caller and `.EPF` path context.
- Address adjacency alone would incorrectly merge at least four distinct source families in `0x004b7f90-0x004b83c5`.

## Ranked Ownership Analysis

### 1. Parent-blank retained source-authored helper

Recommendation rank: final disposition.

Evidence for:

- Exact standalone function body, valid cdecl shape, no compiler thunk/runtime pattern.
- Strong behavior evidence from post-C001 decompilation and disassembly.
- Exact padding before and after.
- No incoming caller/xref/pointer/table/name evidence after repeated raw and post-function IDA checks.
- Adjacent helpers have normal positive reference surfaces, isolating this helper as the no-reference item.

Evidence against:

- "Retained source-authored helper" explains binary presence but not original file declaration.

Decision: keep reconstructable and parent-blank. This is the only assignment-safe recommendation.

Confidence: `92/100`.

### 2. [UID:0000OB] StringUtil / `NexusTK/util/StringUtil.cpp`

Evidence for:

- Best semantic match: raw UTF-16 string hash helper.
- `StringUtil` already owns shared UTF-16/string utilities, SSO-7 support, wide-format wrappers, and wide-string map/tree support.
- Proposed source tree contains `util/StringUtil.cpp` and no better named project string-hash file.

Evidence against:

- No caller, xref, raw VA/RVA pointer, table entry, source string, RTTI link, or adjacent string helper island ties `0x004b81a0` to `StringUtil`.
- Existing accepted StringUtil children have direct positive evidence such as caller spread or layout coupling; [UID:00022J] does not.
- Assigning from behavior alone would violate the direct-owner rule and would make `StringUtil` absorb any unreferenced wide-string-shaped helper.

Decision: best future candidate, but do not assign now.

Confidence as original source owner: `68/100`; confidence as assignment-ready direct parent: below gate.

### 3. [UID:0000OA] StringBase / `mystr::StringBase`

Evidence for:

- The binary preserves many `StringBase<wchar_t,...>` RTTI/template names.
- `StringBase` owns the pointer-backed wide-string implementation and range comparison helpers.

Evidence against:

- [UID:00022J] has no `StringBase` object parameter, no ref-counted buffer layout, no sentinel or pool access, no known callers from the `0x00582500+` family, and no RTTI/vtable/table link.
- The function hashes a raw NUL-terminated wide pointer rather than a `StringBase` range or object.

Decision: reject as direct parent.

Confidence: `34/100`.

### 4. External/library-style hash idiom

Evidence for:

- The `1000003` multiply/XOR recurrence resembles known string-hash idioms.
- The helper is unreferenced, which is compatible with retained dead helper/library code.

Evidence against:

- No Python/third-party import, string, RTTI, or source name was found.
- The body lacks the common `-1` sentinel repair associated with Python-style string hashes.
- There is no existing source/documentation parent for a one-function external string-hash file.

Decision: plausible algorithm ancestry only. Do not create a parent page or assign.

Confidence: `45/100` for algorithm ancestry; `0/100` for actionable parent.

### 5. CachedHashTable

Evidence for:

- Hash-related utility page exists, and IDA hash-name search finds CachedHashTable RTTI.

Evidence against:

- `CachedHashTable` is a fixed-entry cache/table class with vtable/lifecycle/helper ranges around `0x004c6160-0x004c659c`, not a UTF-16 string-hash helper.
- No caller, data ref, RTTI, layout, or table link connects `0x004b81a0` to the CachedHashTable class.
- CachedHashTable file page is below the strict completion gate and would be a weak parent even if semantically closer.

Decision: reject.

Confidence: `12/100`.

### 6. RectBounds, PathUtil, FieldMapPane, GeneralPurposePanel, or physical-neighbor ownership

Evidence for:

- Physical neighborhood places the helper among RectBounds geometry helpers, PathUtil `FileExists`, FieldMapPane path helper, and GeneralPurposePanel code.

Evidence against:

- Each neighbor has its own positive owner evidence, while [UID:00022J] has none.
- The helper has no geometry parameters, file APIs, path suffix logic, panel object state, or map-field constructor context.
- Physical address order in this island is demonstrably mixed and cannot be used as source-file ownership proof.

Decision: reject all proximity owners.

Confidence: near zero as direct parents.

## Disconfirming Evidence Summary

- No external incoming xrefs or callers after the C001 function definition.
- No code/data refs to `0x004b81a0`.
- No raw VA/RVA pointer byte hits for `0x004b81a0` / `0x000b81a0`.
- No immediate operand hits for `0x004b81a0` / `0x000b81a0`.
- No vtable, callback table, jump table, static table, or import/name artifact points at the function.
- No IDA string/source/debug breadcrumb names `StringUtil`, `WideStringHash`, Python, or a hash module in connection with this address.
- No `StringBase`/`SimpleUString` object layout or string-buffer global appears in the function body.
- No nearby owner has behavior overlap; adjacency would merge unrelated geometry, path, map-path, and UI-panel code.

## Future Conditions That Would Change The Decision

Revisit assignment if any of these appear:

- A direct call or callback/table pointer to `0x004b81a0`.
- A raw VA/RVA pointer in a newly-modeled data table or unloaded segment.
- A source/debug/linker breadcrumb naming this helper or its compilation unit.
- A string/container/hash-table helper page that proves sibling functions using the same raw-hash helper.
- A caller recovered from an indirect call table that passes UTF-16 keys and belongs to `StringUtil` or `StringBase`.

If such evidence appears, check `StringUtil` first, then `StringBase`, then an external/library-style string-hash grouping. Do not prefer CachedHashTable or physical neighbors unless the new evidence specifically points there.

## Validator Results

Read-only target validation command:

_Executable command block removed from the research report; preserved in [00022J-WideStringHashHelper-B001-00022J-removed.md](00022J-WideStringHashHelper-B001-00022J-removed.md)._

Result summary:

- `mode: file`
- `apply: False`
- `scanned markdown files: 1`
- `ok: 1`
- Target row: `ok 00022J by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md UID header exists`
- No target validation errors.
- Generated report/status output was dry-run only; no coverage or generated files were edited.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/00022J-WideStringHashHelper-B001-00022J.md`
- Modified by this pass: none under `by-*`; no coverage-report edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00022J-WideStringHashHelper-B001-00022J.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00022J"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00022J-WideStringHashHelper-B001-00022J-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00022J-WideStringHashHelper-B001-00022J.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
