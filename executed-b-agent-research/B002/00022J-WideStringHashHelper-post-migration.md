** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022J WideStringHashHelper Post-Migration Owner/Emitter Recheck

Revision: B002-00022J-post-migration, 2026-06-13

## Final Recommendation

Keep [UID:00022J] `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` unchanged:

```text
*** COMPLETION:88
*** CONFIDENCE:92
*** CANONICAL_OWNER:NONE
*** RECONSTRUCTABLE:TRUE
*** EMITTER_UIDS:
```

No split, merge, parent repair, reclassification, or by-memory coverage-report row change is recommended.

This is a valid post-migration no-owner/non-emitting reconstructable state. The helper is real source-like executable code, now modeled by IDA as `WideStringHashHelper`, so `RECONSTRUCTABLE:TRUE` remains correct. However, the current owner/emitter model requires direct owner or source-use evidence before filling `CANONICAL_OWNER` or `EMITTER_UIDS`. Current live IDA MCP and raw PE evidence still show no caller, xref, raw VA/RVA pointer, rel32 branch/call, short branch, table entry, vtable slot, source-family symbol, or import/name breadcrumb that ties `0x004b81a0` to `StringUtil`, `StringBase`, `CachedHashTable`, `RectBounds`, `PathUtil`, `FieldMapPane`, or any other emitter.

Blank `EMITTER_UIDS` is therefore not an invalid dead-end for this specific item. It means "real reconstructable code with no defensible output route yet," which `by-structure.md` allows for confirmed-but-ownerless items. Emitting this helper through `StringUtil` or any other candidate would invent a source placement from semantics alone.

## Required Supervisor Actions

1. Do not edit `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`.
2. Do not edit `by-memory/-coverage-report.md` for this target.
3. Do not manually edit `auto-generated/-ag-memory-coverage.md`; the current generated row is already correct.
4. Update the B-agent tracker row for `00022J` to the exact replacement below.

Exact tracker replacement row for `tools/leaser/Agents/no_owner_b-agent-tracker.md`:

```markdown
| `00022J` | `auto-generated/-ag-memory-coverage.md` | 0x004b81a0-0x004b81eb.WideStringHashHelper | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` | yes | Agent-B002 | 2026-06-13 | yes | yes | `CANONICAL_OWNER:NONE`; blank `EMITTER_UIDS` | yes | B002-00022J-post-migration executed on 2026-06-13. Final outcome: keep reconstructable `88/92` as no-owner/non-emitting. B002 rechecked current IDA MCP and raw PE evidence; no caller, xref, raw VA/RVA pointer, relative call/jump, short branch, table/vtable slot, or source-family emitter evidence exists for `0x004b81a0`, so `StringUtil` remains semantic only and no emitter route clears the current gate. Report: `Agent-B002/research/00022J-WideStringHashHelper-post-migration.md`. |
```

Current generated main row, no change recommended:

```markdown
| [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` |  |
```

Current manual by-memory coverage row, no change recommended:

```markdown
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : C001-009 defined the exact raw body as IDA function `WideStringHashHelper` after reconfirming the isolated `0x4b` prologue/body/return range, adjacent `0xcc` padding, `wcslen` plus `1000003` wide-string hash recurrence, no callers/xrefs/raw VA/RVA pointer/table reference, and normal xrefs to adjacent FileExists/BuildFieldMapPath/RectAnchor helpers. Parent remains blank because `StringUtil` is semantic only and no direct owner evidence is proven.
```

## Scope And Prior Evidence

| Source | Finding |
| --- | --- |
| Target page | Already has `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_UIDS`. It documents exact bounds, side-effect profile, no-reference state, unique `1000003` multiply, and rejected owner candidates. |
| Previous B001 report | Recommended keeping the item reconstructable and parent-blank after C001 defined the helper as an IDA function. B002 did not assume this was sufficient after migration; the current pass rechecked separate owner/emitter routing. |
| `by-structure.md` | Separates semantic ownership from output routing. It allows `RECONSTRUCTABLE:TRUE` with blank emitters when source-owned code is confirmed but final owner/emitter route is not ready. It also allows `CANONICAL_OWNER:NONE` with emitters for shared pooled items only when source-use contexts are proven. |
| `StringUtil.md` | Names `StringUtil` as broad string utility context but explicitly excludes [UID:00022J] from assignment without caller/xref/raw pointer/table/source-family evidence. |

## Live IDA MCP Evidence

Active IDB session:

| Check | Result |
| --- | --- |
| `idb_list` | Active session `b001_0003gy` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`. |
| `server_health` | `status: ok`; IDB path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; imagebase `0x400000`; auto-analysis ready; Hex-Rays ready; strings cache ready. |

Function and boundary evidence:

| MCP check | Result |
| --- | --- |
| `lookup_funcs 0x004b8194, 0x004b8198, 0x004b81a0, WideStringHashHelper, 0x004b81eb, 0x004b81f0, 0x004b8220, 0x004b8290` | No function at padding addresses `0x004b8194`, `0x004b8198`, or `0x004b81eb`; `WideStringHashHelper` exists at `0x004b81a0`, size `0x4b`; adjacent functions are `sub_4B81F0`, `sub_4B8220`, and `sub_4B8290`. |
| `entity_query functions 0x004b7f80-0x004b83d0` | Functions in the neighborhood: `0x004b81a0` `WideStringHashHelper`, `0x004b81f0` `sub_4B81F0`, `0x004b8220` `sub_4B8220`, `0x004b8290` `sub_4B8290`, `0x004b83d0` `sub_4B83D0`. |
| `get_bytes 0x004b8194 size 12` | Twelve `0xcc` bytes before the helper. |
| `get_bytes 0x004b81a0 size 75` | Exact function body bytes from `55 8b ec ... 5d c3`; size `0x4b`. |
| `get_bytes 0x004b81eb size 5` | Five `0xcc` bytes after the helper. |

Behavior evidence:

| MCP check | Result |
| --- | --- |
| `decompile 0x004b81a0` | Hex-Rays returns `unsigned int __cdecl WideStringHashHelper(const unsigned __int16 *a1)`. It computes `wcslen(a1)`, seeds from `*a1 << 7`, loops with `v5 ^ (1000003 * v3)`, and returns `length ^ hash`. |
| `disasm 0x004b81a0` | Confirms one raw UTF-16 pointer argument at `[ebp+arg_0]`, no calls in the body, no global access, word scan until zero, `imul edx, 0F4243h` at `0x004b81d6`, and `retn` at `0x004b81ea`. |
| `find_bytes 69 D2 43 42 0F 00` | One match at `0x004b81d6`. |
| `find_bytes 43 42 0F 00` | One match at `0x004b81d8`. |

Reference evidence:

| MCP check | Result |
| --- | --- |
| `xrefs_to 0x004b81a0` | Zero incoming xrefs. |
| `xrefs_to WideStringHashHelper` | Zero incoming xrefs. |
| `xref_query both 0x004b81a0` | Only internal fall-through/code-flow xref from `0x004b81a0` to `0x004b81a1`; no incoming caller/data/table reference. |
| `find code_ref 0x004b81a0` | Zero matches. |
| `find data_ref 0x004b81a0` | Zero matches. |
| `find immediate 0x004b81a0` | Zero matches. |
| `find immediate 0x000b81a0` | Zero matches. |
| `find_bytes A0 81 4B 00` | Zero raw VA literal matches. |
| `find_bytes A0 81 0B 00` | Zero raw RVA literal matches. |

Adjacent-helper contrast:

| Target | Current reference evidence |
| --- | --- |
| `0x004b81a0` `WideStringHashHelper` | No incoming xrefs, code refs, data refs, immediates, VA/RVA byte literals, rel32 branches, or short branches. |
| `0x004b81f0` `FileExists` | IDA `xrefs_to` reports calls at `0x0049c87c`, `0x0049c88f`, and `0x004dbcb5`. |
| `0x004b8220` `BuildFieldMapPath` | IDA `xrefs_to` reports call at `0x004b0c0d`. |
| `0x004b8290` `RectAnchorAxisAdjustHelper` | IDA `xrefs_to` reports four code refs from the rect-anchor transform cluster at `0x004b803e`, `0x004b809f`, `0x004b80ff`, and `0x004b8161`. |

This contrast matters: IDA is resolving real references in the same neighborhood. The no-reference result is specific to `WideStringHashHelper`, not a general xref failure around `0x004b81xx`.

## Raw PE Reference Scan

B002 also ran a section-aware local PE scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, checking absolute VA literals, RVA literals, `E8/E9` rel32 calls/jumps, rel32 conditional branches, and short branches to the helper and adjacent starts.

| Target | VA/RVA literal hits | rel32 branch/call hits | short branch hits |
| --- | --- | --- | --- |
| `0x004b81a0` | 0 | 0 | 0 |
| `0x004b81f0` | 0 | 3: `0x0049c87c`, `0x0049c88f`, `0x004dbcb5` | 0 |
| `0x004b8220` | 0 | 1: `0x004b0c0d` | 0 |
| `0x004b8290` | 0 | 4: `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161` | 0 |

The raw scan independently confirms that `0x004b81a0` lacks a hidden direct source-use path while adjacent helpers are discoverable by raw branch encodings.

## Candidate Owner And Emitter Review

| Candidate | Evidence for | Negative evidence | Decision |
| --- | --- | --- | --- |
| [UID:0000OB] `StringUtil` | Best semantic candidate. The helper takes a UTF-16 pointer and computes a wide-string hash with the distinctive `1000003` recurrence. `StringUtil` owns broad Unicode string utility infrastructure. | No caller, xref, VA/RVA pointer, table entry, source-family symbol, global, class/type layout, or StringUtil child relationship points to `0x004b81a0`. `StringUtil.md` already excludes this exact UID from assignment on this evidence. | Do not set `CANONICAL_OWNER:0000OB`; do not add `EMITTER_UIDS:0000OB`. This would be semantic placement only. |
| [UID:0000OA] `StringBase` | The function handles UTF-16 data and Hex-Rays prints `wcslen`. | It does not operate on a `mystr::StringBase` object, ref-counted buffer header, sentinel, pool, COW state, vtable, or `StringBase` template RTTI. It takes only a raw `const unsigned __int16 *` and returns a scalar. | Reject owner and emitter. |
| [UID:0000HZ] `CachedHashTable` | Name contains `Hash`; documented as a fixed-entry hash/cache utility class. | The `CachedHashTable` evidence lives in a separate class/vtable/helper island around `0x004c6160-0x004c659c` and RTTI/vtable data near `0x0061aac4`. Name search finds `CachedHashTable` RTTI/name records but no connection to `0x004b81a0`. | Reject owner and emitter. |
| [UID:0000N2] `RectBounds` | Physical proximity: predecessor rect-anchor transform cluster and successor axis helper are RectBounds-family geometry helpers. | The helper reads UTF-16 words and hashes them; it does not read or write rect fields. The RectBounds anchor helper xrefs stay inside the geometry cluster and bypass this helper. | Reject owner and emitter. |
| [UID:0000MI] `PathUtil` | Immediate successor `FileExists` is PathUtil-owned. | Physical adjacency is not source ownership. `FileExists` has cross-subsystem path callers and CRT file-open behavior; this helper has no path behavior and no callers. | Reject owner and emitter. |
| [UID:0000JA] `FieldMapPane` | `BuildFieldMapPath` at `0x004b8220` is called by the FieldMapPane constructor. | That evidence belongs to the successor helper only. No FieldMapPane code references `0x004b81a0`, and the target has no path-stem or `.EPF` behavior. | Reject owner and emitter. |
| External/library-style hash source | The `1000003` recurrence resembles known string-hash idioms. | No import, source string, version marker, module name, table, or statically embedded third-party source evidence ties this exact helper to an external file. | Do not reclassify as third-party or add a synthetic external emitter. |

## Why No Emitters Are Justified

The post-migration question is not only "who owns this?" but "who needs to emit this code?" For pooled constants and shared data, `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` can be correct when independent source-use contexts are proven. That model does not apply here:

- There are no proven consumers.
- There is no caller-local source-use context.
- There is no table/vtable/global pointer that would force declaration in a known file.
- There is no evidence that more than one source file used a pooled helper.
- There is no direct file root whose staged source would be incomplete without this helper.

The helper is reconstructable because it is real code. It is non-emitting because no file/class/source-use path clears the assignment gate. Keeping `EMITTER_UIDS` blank prevents generated output from materializing a dead utility function in the wrong source file.

## Split, Merge, And Reclassification Review

| Question | Decision | Evidence |
| --- | --- | --- |
| Split further? | No. | IDA models one exact function at `0x004b81a0`, size `0x4b`, with prologue, body, and return. Padding surrounds it: `0x004b8194-0x004b81a0` and `0x004b81eb-0x004b81f0` are `0xcc`. |
| Merge with predecessor/successor? | No. | Predecessor `RectAnchorTransformHelpers`, successor `FileExists`, `BuildFieldMapPath`, and `RectAnchorAxisAdjustHelper` have separate behavior and separate evidence routes. |
| Reclassify `RECONSTRUCTABLE:FALSE`? | No. | The target is not padding, runtime glue, compiler artifact, or a broad aggregate. It is a source-shaped helper function with deterministic behavior and no external side effects. |
| Add canonical owner? | No. | Semantics point most strongly to `StringUtil`, but direct owner evidence is absent. |
| Add emitters? | No. | No source-use context is proven, so any emitter would invent placement. |

## Commands And Results

IDA MCP evidence was gathered through the normal live MCP server at `http://127.0.0.1:13337/mcp`; no IDA dry-run or memory-range validator mode was used.

| Command/tool | Result summary |
| --- | --- |
| `idb_list` | Active `b001_0003gy` session for `NexusTK.exe`. |
| `server_health` | IDB ready, Hex-Rays ready, imagebase `0x400000`. |
| `lookup_funcs` | `WideStringHashHelper` exists at `0x004b81a0`, size `0x4b`; padding addresses are not functions. |
| `entity_query` in `0x004b7f80-0x004b83d0` | Confirms adjacent modeled helper starts and local function inventory. |
| `xrefs_to` / `xref_query` | No incoming references to `0x004b81a0`; adjacent helpers have expected local/caller refs. |
| `decompile` / `disasm` | Confirms UTF-16 hash behavior, no calls, no globals, no side effects, and exact return. |
| `get_bytes` | Confirms exact body and `0xcc` padding before/after. |
| `find code_ref`, `find data_ref`, `find immediate` | No code refs, data refs, VA immediates, or RVA immediates for `0x004b81a0`. |
| `find_bytes` | No raw VA/RVA literal bytes for `0x004b81a0`; unique `1000003` multiply encoding at `0x004b81d6`. |
| `entity_query` candidate search | Function search finds only `WideStringHashHelper` for hash/string candidates; name search finds unrelated `StringBase` template RTTI and `CachedHashTable` RTTI/name records with no link to the target. |
| `imports_query` for `wcslen`, `hash`, and `python` | No import breadcrumb linking the helper to a library/source owner. |
| Local section-aware PE scan | No absolute VA, RVA, rel32 call/jump, rel32 conditional branch, or short-branch target to `0x004b81a0`; adjacent helper starts produce the expected branch hits. |

## Validation And Lease Status

- By-* documentation edited: none.
- Generated/project-level reports edited manually: none.
- Target metadata edited: no.
- Split/child pages created: no.
- Leases taken: none required, because this report-only output is inside `Agent-B002/research` and no validator-managed by-* file was edited.
- Validator run: not run. There were no by-* edits to validate, and running validator would not change this recommendation.
- Dry-run validator mode: not used.
- Memory-range validator mode: not used.
- Unresolved validator warnings/errors introduced by this work: none.

## Changed Files

Created:

```text
tools/leaser/Agents/Agent-B002/research/00022J-WideStringHashHelper-post-migration.md
```

## Blockers

No external blocker prevented completion. The unresolved source owner is an evidence result, not a workflow blocker: current IDA MCP, raw PE, and documentation checks do not expose any direct owner or emitter route for this exact helper.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00022J-WideStringHashHelper-post-migration.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
