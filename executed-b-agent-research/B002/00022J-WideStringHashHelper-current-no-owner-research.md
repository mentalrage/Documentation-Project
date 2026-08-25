** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022J WideStringHashHelper Current No-Owner Research

## Final Recommendation

- Recommendation: keep [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](../../../../../by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- No canonical owner is defensible in the current evidence. [UID:0000OB][StringUtil](../../../../../by-file/StringUtil.md) is still the strongest semantic candidate, but current IDA/PE evidence gives only behavior affinity, not a direct source-owner link.
- No emitter route is defensible. The helper has no proven caller, source-use context, generated output path, code/data xref, raw VA/RVA pointer, table route, or external branch/call route.
- No split, merge, range repair, reclassification, or IDA-safe name repair is recommended. The target is one exact source-shaped function already named `WideStringHashHelper` in the current IDB.
- Scores stay unchanged: before `88/92`, after `88/92`. The current code-entry gate is still blocked because `EMITTER_UIDS` is blank and no valid generated-source route is proven, even though `(88 + 92) / 2 = 90`.

## Target And Scope

- Target UID: `00022J`.
- Target path: `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`.
- Current generated state checked: `auto-generated/-ag-memory-coverage.md` lists `no-owner`, `CANONICAL_OWNER:NONE`, blank emitters, no output path, and no source route.
- Current header state: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.
- Prior reports reviewed only as history: `Agent-B003/research/executed/00022J-WideStringHashHelper-restart-no-owner-research.md` and `Agent-B002/research/executed/00022J-WideStringHashHelper-current-no-owner-recheck.md`.

## Evidence Standard

This pass used the current owner/emitter model from `goal.md`, `Supervisor.md`, and the by-structure guidance:

- `CANONICAL_OWNER` requires a defensible semantic declaration/source owner, not proximity or general utility behavior.
- `EMITTER_UIDS` requires a proven source-use output route, not just a plausible module.
- Reconstructable code may remain `CANONICAL_OWNER:NONE` when the binary function is real but no owner or output route is proven.
- Final C++ is not entered without confirmed nonblank emitters that surface to valid generated source, plus sufficient score/quality. This target has adequate behavior confidence but no emitter.

## Live IDA MCP Facts

IDA MCP session `b001_0002bd` is active for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reports imagebase `0x400000`, Hex-Rays ready, auto-analysis ready, and strings cache ready.

Function and boundary evidence:

| Query | Current result |
| --- | --- |
| `lookup_funcs 0x004b8194` | not a function |
| `lookup_funcs 0x004b81a0` / `WideStringHashHelper` | function at `0x004b81a0`, size `0x4b` |
| `lookup_funcs 0x004b81eb` | not a function |
| `lookup_funcs 0x004b81f0` | `sub_4B81F0`, size `0x2e` |
| `lookup_funcs 0x004b8220` | `sub_4B8220`, size `0x64` |
| `lookup_funcs 0x004b8290` | `sub_4B8290`, size `0x11e` |

`entity_query` over `0x004b7f80-0x004b83d0` lists only five modeled functions: `WideStringHashHelper`, `sub_4B81F0`, `sub_4B8220`, `sub_4B8290`, and `sub_4B83D0`. This keeps the target as a standalone modeled function between padding and unrelated neighbors.

`get_bytes` confirms:

- `0x004b8194-0x004b81a0`: twelve `0xcc` bytes after the rect-anchor transform table/padding boundary.
- `0x004b81a0-0x004b81eb`: exact 75-byte function body from `55 8b ec` through `5d c3`.
- `0x004b81eb-0x004b81f0`: five `0xcc` bytes before `sub_4B81F0`.

Hex-Rays currently decompiles:

```c
unsigned int __cdecl WideStringHashHelper(const unsigned __int16 *a1)
{
  v2 = wcslen(a1);
  v3 = *a1 << 7;
  for ( i = v2 - 1; i >= 0; --i )
    v3 = *v1++ ^ (1000003 * v3);
  return v2 ^ v3;
}
```

Disassembly confirms the helper has no call instructions, no global writes, and no side effects beyond reading the input UTF-16 string. The notable immediate `0x0f4243` / decimal `1000003` appears at `0x004b81d6`.

## Xrefs And Raw PE Evidence

IDA xrefs:

| Target | Incoming xrefs |
| --- | --- |
| `0x004b81a0` | none |
| `WideStringHashHelper` | none |
| `0x004b81f0` | `0x0049c87c`, `0x0049c88f`, `0x004dbcb5` |
| `0x004b8220` | `0x004b0c0d` |
| `0x004b8290` | `0x004b803e`, `0x004b809f`, `0x004b80ff`, `0x004b8161` |

`find code_ref`, `find data_ref`, and `find immediate` for `0x004b81a0` and RVA `0x000b81a0` all return zero matches. The neighboring helpers retain expected xrefs, so the reference gap is local to `00022J`, not a tool-wide failure.

Raw PE scan on `NexusTK.exe`:

- VA `0x004b81a0`, RVA `0x000b81a0`, raw file offset `0x000b75a0`, section `.text`.
- Full 75-byte body pattern occurs once, at `0x004b81a0`.
- `69 d2 43 42 0f 00` occurs once, at `0x004b81d6`.
- Little-endian immediate `43 42 0f 00` occurs once, at `0x004b81d8`.
- Little-endian VA bytes `a0 81 4b 00`: 0 hits.
- Little-endian RVA bytes `a0 81 0b 00`: 0 hits.
- `push 0x004b81a0` bytes `68 a0 81 4b 00`: 0 hits.
- Direct rel32/short branch scan found no external branch/call into `0x004b81a0-0x004b81eb`. Neighbor exact-start rel32 hits match IDA: `0x004b81f0` has three, `0x004b8220` has one, and `0x004b8290` has four.

## Function And Neighborhood Inventory

| Range | Doc | Classification | Owner/emitter state | Current conclusion |
| --- | --- | --- | --- | --- |
| `0x004b7f90-0x004b8194` | [UID:00022I][RectAnchorTransformHelpers](../../../../../by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) | raw geometry helper cluster | owner/emitter `0000N2` | RectBounds evidence is layout/callee-specific and does not route through `00022J`. |
| `0x004b8194-0x004b81a0` | `by-memory/-ignored.md` | padding | ignored | Confirmed `0xcc`; no child needed. |
| `0x004b81a0-0x004b81eb` | [UID:00022J][WideStringHashHelper](../../../../../by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | exact raw-function | `NONE`, blank emitters | Keep no-owner/non-emitting. |
| `0x004b81eb-0x004b81f0` | `by-memory/-ignored.md` | padding | ignored | Confirmed `0xcc`; no child needed. |
| `0x004b81f0-0x004b821e` | [UID:00022K][FileExists](../../../../../by-memory/0x004b81f0-0x004b821e.FileExists.md) | path helper | owner/emitter `0000MI` | Direct `_wfopen` callers prove PathUtil only for this neighbor. |
| `0x004b8220-0x004b8284` | [UID:00015U][BuildFieldMapPath](../../../../../by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md) | path-stem helper | owner/emitter `0000JA` | Constructor-only FieldMapPane route does not touch `00022J`. |
| `0x004b8290-0x004b83c5` | [UID:00022L][RectAnchorAxisAdjustHelper](../../../../../by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) | geometry helper | owner/emitter `0000N2` | Four xrefs from rect-anchor transform cluster; unrelated to hash helper. |
| `0x004b83d0+` | [GeneralPurposePanel](../../../../../by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md) | panel class/method range | UI panel ownership | Successor neighborhood does not reference `00022J`. |

## Documentation Evidence Checked

- Target page already records the exact function, no-reference state, no side effects, unique `1000003` pattern, C001 IDA function/name repair, rejected owners, and current `NONE`/blank emitter decision. Current IDA and raw PE checks confirm those key facts.
- `auto-generated/-ag-memory-coverage.md` currently lists the item as no-owner with blank emitters and no output path. That is consistent with this pass.
- `by-memory/-coverage-report.md` currently records the same no-owner/non-emitting decision and cites no callers/xrefs/raw pointer/table/branch route plus normal adjacent helper references. No supervisor edit is needed.
- [UID:0000OB][StringUtil](../../../../../by-file/StringUtil.md) explicitly excludes attaching `00022J` solely from wide-string hash semantics and requires caller/xref/raw pointer/table/source-family evidence. This pass did not find such evidence.
- [UID:0000OA][StringBase](../../../../../by-file/StringBase.md) owns ref-counted string-buffer mechanics around `0x00582500+`; `00022J` has no `StringBase` buffer header, sentinel, pool, compare/append call, or template evidence.
- [UID:0000HZ][CachedHashTable](../../../../../by-file/CachedHashTable.md) is a separate fixed-entry class/vtable/helper island around `0x004c6160+`; `00022J` has no receiver, slot-state layout, vtable/RTTI link, or class-local call route.
- [UID:0000N2][RectBounds](../../../../../by-file/RectBounds.md), [UID:0000MI][PathUtil](../../../../../by-file/PathUtil.md), and [UID:0000JA][FieldMapPane](../../../../../by-file/FieldMapPane.md) have positive evidence for neighboring helpers, but none reference or consume the hash helper.
- `find_regex` for debug/source breadcrumbs found only RTTI-like strings for `FieldMapPane` and `CachedHashTable`; no PDB/source path/StringUtil/WideStringHash artifact was found in the string cache.

## Ownership Alternatives Rejected

1. `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
   - Accepted. The function is real and reconstructable, but there is no direct owner or output route. This is the least misleading state under the current model.

2. `StringUtil` / `0000OB`
   - Rejected for assignment. The behavior is string utility code, but the only positive evidence is semantic. The current `StringUtil` page explicitly blocks `00022J` without caller/xref/raw pointer/table/source-family evidence.

3. `StringBase` / `0000OA`
   - Rejected. This helper hashes a raw UTF-16 pointer and has no ref-counted string-buffer layout, sentinel, pool, formatter, comparator, or preserved `mystr::StringBase` metadata relation.

4. `CachedHashTable` / `0000HZ`
   - Rejected. Hash-domain similarity is insufficient. CachedHashTable has a distinct class layout, vtable, helper island, and no link to this raw wide-string hash.

5. `RectBounds` / `0000N2`
   - Rejected. RectBounds owns adjacent geometry and anchor helpers through layout/call evidence. `00022J` does not read/write rectangles and is separated by padding.

6. `PathUtil` / `0000MI` or `FieldMapPane` / `0000JA`
   - Rejected. Neighbor helpers have direct path/file/map caller evidence, but `00022J` has no file/path behavior and no caller route from those modules.

7. New source file or external/library owner
   - Rejected for current metadata. A source-authored utility file may have existed, but no source path, debug artifact, import name, caller, or table route identifies one. Creating a new owner would encode speculation.

## Split, Merge, Reclassification, And Name Analysis

- Split: not needed. The body is one function from `0x004b81a0` through return at `0x004b81ea`; surrounding bytes are padding.
- Merge: not justified. Neighbors belong to unrelated geometry, file/path, field-map, and panel contexts with their own evidence.
- Reclassify as not reconstructable: not justified. The helper is source-shaped code with clear ABI, behavior, and exact boundaries. The problem is output routing, not reconstructability.
- IDA-safe name repair: not needed. Current IDA name `WideStringHashHelper` is descriptive and synchronized with the target page, but should remain treated as an inferred name, not original-source proof.

## Exact Required Edits

No by-memory, by-file, generated coverage, or shared coverage edit is required.

Retain target metadata as-is:

```text
*** UID:00022J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No replacement row is needed for `by-memory/-coverage-report.md`. Current row remains accurate:

```text
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : B003 second-pass review keeps `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`; C001-009 defined the exact raw body as IDA function `WideStringHashHelper`, and fresh PE/raw scans reconfirm isolated `0x4b` prologue/body/return range, adjacent `0xcc` padding, unique `wcslen` plus `1000003` wide-string hash recurrence, no callers/xrefs/raw VA/RVA pointer/table reference, no external branch/call route, and normal xrefs to adjacent FileExists/BuildFieldMapPath/RectAnchor helpers. `StringUtil` remains semantic only and no direct owner/emitter evidence is proven.
```

No generated coverage replacement is needed. Current generated row remains the correct outcome:

```text
| [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` |  |
```

Optional tracker close-out text for supervisor application:

```text
| `00022J` | 0x004b81a0-0x004b81eb.WideStringHashHelper | `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` | Agent-B002 | 2026-06-14 | complete-no-change | `Agent-B002/research/00022J-WideStringHashHelper-current-no-owner-research.md` | `Agent-B003/research/executed/00022J-WideStringHashHelper-restart-no-owner-research.md` |
```

## Validation, Leases, And Changed Files

- Changed files: created this report only.
- by-* documentation edits: none.
- `by-memory/-coverage-report.md` edits: none.
- Validator: not run because no by-* or generated documentation files were modified.
- Dry runs: none used.
- Lease state: no lease required for a new B002-owned research report under `Agent-B002/research`; no shared or by-* files were edited.

## Confidence

Recommendation confidence is high. Positive evidence proves the exact function and behavior; repeated negative evidence blocks owner/emitter assignment. The only residual uncertainty is historical source provenance, and assigning a canonical owner or emitter on that basis would weaken the current documentation model.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00022J-WideStringHashHelper-current-no-owner-research.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
