** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022J WideStringHashHelper Current No-Owner Research

## Final Recommendation

Keep [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](../../../../../by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) as `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS`.

This is a real, reconstructable helper body and should not be reclassified as padding or ignored. It also should not be forced into `StringUtil`, `StringBase`, `CachedHashTable`, `RectBounds`, `PathUtil`, or `FieldMapPane`: current IDA and raw PE evidence still proves behavior and isolation, but not a source owner or a source-use output route.

Score/routing impact:

| Field | Before | Recommended after |
| --- | --- | --- |
| `COMPLETION` | `88` | `88` |
| `CONFIDENCE` | `92` | `92` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `CANONICAL_OWNER` | `NONE` | `NONE` |
| `EMITTER_UIDS` | blank | blank |
| Code-entry gate | blocked | blocked |

The average score is `90.0`, but the current reconstruction-code gate still fails because `EMITTER_UIDS` is blank. No final C++ should be entered or recommended until a confirmed nonblank emitter reaches valid generated source without a dead-end.

## Target And Scope

- Target: [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](../../../../../by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md)
- Current generated row: `auto-generated/-ag-memory-coverage.md` reports `no-owner`, owner `` `NONE` ``, blank emitters.
- Current target metadata: `COMPLETION:88`, `CONFIDENCE:92`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP`.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B002/research/executed/00022J-WideStringHashHelper-current-no-owner-research.md`.
- Direct edits allowed for this pass: final Agent-B002 research report only. The assignment explicitly bars direct edits to `by-memory/-coverage-report.md`; no by-* edits were made.

## Evidence Standard Applied

I used the current by-structure owner/emitter model:

- `CANONICAL_OWNER` needs direct source-ownership evidence, not just semantic fit or address proximity.
- `EMITTER_UIDS` needs a proven route to generated source output. A convenient utility file is not enough if no source-use, caller, pointer, table, or other output route is proven.
- `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` remains valid for a reconstructable item when the function is understood but no source owner/emitter route is defensible.
- C++ entry is blocked unless the item is reconstructable, has confirmed nonblank emitters that surface to generated source, and passes the combined score gate.

## Current Documentation Evidence

Current target page facts:

- The page documents one exact function-shaped body at `0x004b81a0-0x004b81eb`, size `0x4b`.
- Documented behavior is a `wcslen`-style UTF-16 scan, initial seed `*text << 7`, recurrence `hash = code_unit ^ (1000003 * hash)`, and final `length ^ hash`.
- The target page already records the C001 IDA repair: function creation at `0x004b81a0-0x004b81eb` and rename to `WideStringHashHelper`.
- It also records the same ownership block that matters now: no caller, no xref, no raw VA/RVA pointer, no table reference, and no source-family artifact proving an owner.

Current generated/tracker evidence:

- `auto-generated/-ag-memory-coverage.md` current main row:
```text
| [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` |  |
```
- `auto-generated/-ag-memory-coverage.md` current no-owner row:
```text
| [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | no-owner | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` |  |  |  |
```
- `tools/leaser/Agents/no_owner_b-agent-tracker.md` currently has an active 2026-06-14 assignment row for Agent-B002 and prior complete-no-change history.

Relevant source-family documentation:

- [StringUtil](../../../../../by-file/StringUtil.md) explicitly excludes assigning `00022J` solely from wide-string hash semantics. Its current text says no caller, xref, raw pointer, table reference, or source-family evidence proves `StringUtil` as the direct parent.
- [StringBase](../../../../../by-file/StringBase.md) owns the ref-counted ANSI/UTF-16 buffer implementation around `0x00582500-0x00584d7e`, not this isolated raw helper.
- [CachedHashTable](../../../../../by-file/CachedHashTable.md) owns a separate class/vtable/helper island around `0x004c6160+`; hash-domain similarity does not create an ownership edge.
- [RectBounds](../../../../../by-file/RectBounds.md), [PathUtil](../../../../../by-file/PathUtil.md), and [FieldMapPane](../../../../../by-file/FieldMapPane.md) own adjacent or nearby helpers, but those neighbors have their own direct xref evidence and do not reference this hash body.

## Live IDA MCP Evidence

IDA session checked:

- Database: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Image base: `0x400000`
- Auto-analysis and Hex-Rays were ready.

Function identity and boundary:

- `lookup_funcs 0x004b81a0` returns `WideStringHashHelper`, size `0x4b`.
- `lookup_funcs 0x004b8194`, `0x004b8198`, `0x004b81eb`, `0x004b821e`, and `0x004b8284` do not return function starts.
- Neighboring functions are still separate:
  - `0x004b81f0`: `sub_4B81F0`, size `0x2e`, documented as [FileExists](../../../../../by-memory/0x004b81f0-0x004b821e.FileExists.md).
  - `0x004b8220`: `sub_4B8220`, size `0x64`, documented as [BuildFieldMapPath](../../../../../by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md).
  - `0x004b8290`: `sub_4B8290`, size `0x11e`, documented as [RectAnchorAxisAdjustHelper](../../../../../by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md).

Byte evidence:

- `0x004b8194-0x004b81a0`: twelve `0xcc` padding bytes.
- `0x004b81a0-0x004b81eb`: exact 75-byte prologue/body/return sequence:
  `55 8b ec 56 8b 75 08 8b ce 57 8d 51 02 0f 1f 00 66 8b 01 83 c1 02 66 85 c0 75 f5 2b ca 0f b7 16 d1 f9 8b f9 c1 e2 07 83 e9 01 78 17 0f 1f 40 00 0f b7 06 8d 76 02 69 d2 43 42 0f 00 33 d0 83 e9 01 79 ed 33 d7 5f 8b c2 5e 5d c3`
- `0x004b81eb-0x004b81f0`: five `0xcc` padding bytes.

Current Hex-Rays decompilation:

```c
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

IDA xref/caller evidence:

- `xrefs_to 0x004b81a0`: zero.
- `xrefs_to WideStringHashHelper`: zero.
- `callees 0x004b81a0`: none.
- Neighboring references remain normal:
  - `0x004b81f0`: callers at `0x0049c87c`, `0x0049c88f`, and `0x004dbcb5`.
  - `0x004b8220`: caller at `0x004b0c0d`.
  - `0x004b8290`: raw rect-anchor cluster calls at `0x004b803e`, `0x004b809f`, `0x004b80ff`, and `0x004b8161`.

IDA string/source-breadcrumb search:

- Regex search for `WideStringHash`, `StringUtil`, `StringBase`, `CachedHashTable`, `.pdb`, `RSDS`, and `.cpp` found only current RTTI/mangled `CachedHashTable` and `mystr::StringBase` string material, not a source breadcrumb or owner link for `0x004b81a0`.

## PE And Raw Evidence

Raw executable checked:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Length: `0x28e200`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- `.text` mapping used for scan: raw `0x400-0x1f5000`, VA `0x401000-0x5f5c00`
- Target VA/raw: `0x004b81a0-0x004b81eb` maps to raw `0x000b75a0-0x000b75eb`.

Raw scan results:

- Full 75-byte target body: 1 hit, raw `0x000b75a0`, VA `0x004b81a0`.
- `imul edx, 0x0f4243` byte pattern `69 d2 43 42 0f 00`: 1 hit, raw `0x000b75d6`, VA `0x004b81d6`.
- Little-endian immediate `1000003` (`43 42 0f 00`): 1 hit, raw `0x000b75d8`, VA `0x004b81d8`.
- Little-endian VA pointer to `0x004b81a0`: 0 hits.
- Little-endian RVA pointer to `0x000b81a0`: 0 hits.
- `push 0x004b81a0` pattern: 0 hits.
- Rel32 exact-start branch/call scan:
  - `0x004b81a0`: 0
  - `0x004b81f0`: 3
  - `0x004b8220`: 1
  - `0x004b8290`: 4

The raw branch counts match the IDA picture: adjacent helpers have real reference surfaces, while the hash helper does not.

## Function And Neighbor Inventory

| Range | Current classification | Owner/emitter state | Evidence relevance |
| --- | --- | --- | --- |
| `0x004b7f90-0x004b8194` | Rect anchor transform raw cluster | owned/emitted by `RectBounds` | Ends before `0x004b8194`; calls axis helper; no route to hash helper. |
| `0x004b8194-0x004b81a0` | padding | ignored | Twelve `0xcc` bytes before target. |
| `0x004b81a0-0x004b81eb` | `WideStringHashHelper` | `NONE`, blank emitters | Current target; real isolated helper; no xrefs. |
| `0x004b81eb-0x004b81f0` | padding | ignored | Five `0xcc` bytes after target. |
| `0x004b81f0-0x004b821e` | `FileExists` | owned by `PathUtil` | Three callers and external `_wfopen`/`_fclose` route; separate owner. |
| `0x004b8220-0x004b8284` | `BuildFieldMapPath` | owned by `FieldMapPane` | One caller at `0x004b0c0d`; separate path-building helper. |
| `0x004b8290-0x004b83c5` | `RectAnchorAxisAdjustHelper` | owned by `RectBounds` | Four rect-anchor cluster calls; separate geometry helper. |

## Owner And Emitter Analysis

### Keep `CANONICAL_OWNER:NONE`

This is the only defensible current owner state. The helper's semantics are string-related, but the by-structure gate requires direct owner evidence. Current IDA and raw PE evidence show no callers, no xrefs, no VA/RVA pointer, no table reference, no source breadcrumb, and no neighboring-source tie. Assigning a direct source owner would be speculative.

### Keep blank `EMITTER_UIDS`

No emitter route is proven. An emitter must be a source-use output route, not merely a plausible place where a utility could live. Because no current file/class/global documentation proves that generated source will include or call this helper, adding `StringUtil` or any nearby file as an emitter would create a dead-end or guessed output path.

### Reject `StringUtil` owner/emitter

`StringUtil` is the strongest semantic candidate because the helper hashes UTF-16 input. It still fails the owner/emitter gate:

- The `StringUtil` by-file page explicitly excludes this child absent direct evidence.
- No function in the current IDA evidence calls `0x004b81a0`.
- No raw VA/RVA pointer or push-reference points at `0x004b81a0`.
- No source breadcrumb ties the helper to `NexusTK/util/StringUtil.cpp`.
- No documented `StringUtil` class/function has a source-use dependency on this helper.

### Reject `StringBase`

`StringBase` owns the ref-counted string buffer implementation and mystr string family. This helper takes a raw `uint16_t *`, performs no allocation/refcount work, has no StringBase structure access, and has no xref path into the documented StringBase ranges.

### Reject `CachedHashTable`

The multiplier and hash role are not enough to attach this helper to `CachedHashTable`. The cached hash table documentation covers a separate class/lifecycle island and vtable-backed object behavior. Current evidence proves no reference from that island to `0x004b81a0`.

### Reject Neighbor Owners

`RectBounds`, `PathUtil`, and `FieldMapPane` each own nearby functions through direct evidence. Their ownership does not transfer across padding:

- `RectBounds` evidence is geometry-specific and points to the transform/axis helpers.
- `PathUtil` evidence points to `FileExists`, which has distinct callers and external file API calls.
- `FieldMapPane` evidence points to `BuildFieldMapPath`, which has its own caller and path-stem behavior.

## Split, Merge, Reclassification, And IDA Repair

- Split: not needed. The target is one compact function body with a single prologue, one return, no embedded data island, and padding on both sides.
- Merge: not needed. Both adjacent sides are separated by `0xcc` padding and neighboring helpers have unrelated owners.
- Reclassification to non-reconstructable: rejected. The helper decompiles cleanly, has a stable signature, stable behavior, no unknown side effects, and exact raw byte support.
- Reclassification to ignored/padding: rejected. The body is executable code and has already been defined as an IDA function.
- IDA-safe name repair: not needed. Current IDA lookup returns `WideStringHashHelper` at `0x004b81a0`, size `0x4b`.
- Documentation repair: not needed for the target page. Older historical notes that mention the pre-C001 absence of a function object are superseded by later C001/current IDA entries and do not change the current owner/emitter conclusion.

## Failed Hypotheses

- Hypothesis: this is a hidden `StringUtil` child. Failed because no direct source-owner evidence, source-use route, pointer, xref, or breadcrumb exists.
- Hypothesis: this should emit through `StringUtil.cpp` because the generated source tree has a string utility file. Failed because emitter routing requires proven output use, and no use route is documented or present in IDA.
- Hypothesis: this is tied to `CachedHashTable` because it is a hash helper. Failed because the documented cached hash table island has no xref/pointer/caller relationship to this body.
- Hypothesis: adjacency to `FileExists` or `BuildFieldMapPath` proves a util/source file group. Failed because by-structure rules treat address proximity as weak, and those neighbors have independent direct evidence while this target has none.
- Hypothesis: the current no-owner state is a stale artifact from before the IDA function fix. Failed because the current IDA function is now defined and named, but the xref/pointer/source-owner gap remains.

## Exact Required Edits

No by-* documentation edits are recommended.

No direct edit to `by-memory/-coverage-report.md` is recommended. Retain the current shared coverage row:

```text
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : B003 second-pass review keeps `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`; C001-009 defined the exact raw body as IDA function `WideStringHashHelper`, and fresh PE/raw scans reconfirm isolated `0x4b` prologue/body/return range, adjacent `0xcc` padding, unique `wcslen` plus `1000003` wide-string hash recurrence, no callers/xrefs/raw VA/RVA pointer/table reference, no external branch/call route, and normal xrefs to adjacent FileExists/BuildFieldMapPath/RectAnchor helpers. `StringUtil` remains semantic only and no direct owner/emitter evidence is proven.
```

No direct edit to `auto-generated/-ag-memory-coverage.md` is recommended. The generator should continue to show `no-owner`, `` `NONE` ``, blank emitters.

Suggested tracker closeout row, if the supervisor updates `tools/leaser/Agents/no_owner_b-agent-tracker.md`:

```text
| `00022J` | 0x004b81a0-0x004b81eb.WideStringHashHelper | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` | Agent-B002 | 2026-06-14 | complete-no-change | `Agent-B002/research/00022J-WideStringHashHelper-current-no-owner-research.md` | `Agent-B002/research/executed/00022J-WideStringHashHelper-current-no-owner-research.md` |
```

## Validation And Lease State

- Files changed by this pass: `tools/leaser/Agents/Agent-B002/research/00022J-WideStringHashHelper-current-no-owner-research.md`.
- No by-* or generated/shared coverage files were edited.
- No validator was run because no in-scope by-* documentation was changed.
- Lease state: no lease was required or acquired for this root Agent-B002 research report under `goal.md`; no non-agent documentation file was edited.
- Dry runs: none.

## Confidence

Recommendation confidence: high for no owner/emitter change.

The helper's behavior, boundaries, uniqueness, and no-reference state are well supported by current IDA MCP evidence and raw PE checks. The remaining uncertainty is not about what the function does; it is about original source placement. Under current by-structure rules, that uncertainty blocks a canonical owner and blocks all emitter routes.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00022J-WideStringHashHelper-fresh-no-owner-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
