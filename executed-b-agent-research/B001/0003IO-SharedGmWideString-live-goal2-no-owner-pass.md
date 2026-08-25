** TARGET-REPORT-UID:0003IO **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003IO **
# Final Recommendation

- Keep `CANONICAL_OWNER:NONE`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000L3,0000KU,0000M4`.
- Do not split, merge, reclassify, create child pages, or assign a canonical owner.
- Do not edit `by-memory/-coverage-report.md` for this target. The current row remains accurate.

Recommended metadata remains:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000KU,0000M4
RECONSTRUCTION_CPP:
```

This is the valid strange split case: one physical pooled UTF-16LE `GM` literal is source-reconstructable, but no single source declaration owner is defensible. The three current emitters are source-use routes, not an ownership claim. Reconstructed source for [UID:0000L3] `MapPane`, [UID:0000KU] `LivingObjectPane`, and [UID:0000M4] `ObjectList` may each need a local `L"GM"` use, while the linker/compiler stores one pooled `.rdata` byte sequence.

Coverage row replacement is not needed. Retain the current row:

```text
            - [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) 0x0061e6f8-0x0061e700 | string-data | SharedGmWideString : reconstructable : 88% : very strong : UTF-16LE `GM` pooled source literal with `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000L3,0000KU,0000M4`; ownership reviews confirm 20 direct code xrefs across MapPane, LivingObjectPane, and ObjectList consumers, with no single semantic declaration owner.
```

---

# 0003IO SharedGmWideString Live Goal 2 No-Owner Pass

## Target

- Target UID: `0003IO`
- Target path: `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`
- Range: `0x0061e6f8-0x0061e700`
- Entity kind: string-data
- Current state reviewed: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000KU,0000M4`
- Assignment tracker: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, section `Active 2026-06-14 Live Goal 2 No-Owner Memory Pass`
- Final report path: `tools/leaser/Agents/Agent-B001/research/0003IO-SharedGmWideString-live-goal2-no-owner-pass.md`

Prior reports and current documentation were treated as leads only. This pass rechecked the current documentation and fresh IDA MCP evidence before making the recommendation.

## Executive Recommendation

Keep the existing no-owner-with-three-emitters state.

The target is the exact 8-byte UTF-16LE `GM` literal child. `0x8` is 8 bytes and `0x2` is two UTF-16 code units, both verified with `tools/int_convert.py`. Fresh IDA evidence shows one exact physical byte sequence and exactly 20 direct code xrefs. The xrefs split across three source families:

| Source-use route | UID | Evidence summary |
| --- | --- | --- |
| `MapPane.cpp` | `0000L3` | One direct use at `0x00505505` inside `sub_505430`, a MapPane movement/occupancy/name check helper. |
| `LivingObjectPane.cpp` | `0000KU` | One direct use at `0x00514ec5` inside [UID:000233] `LivingObjectPaneGmNameSuffixCheck`, the actor-owned name suffix method. |
| `ObjectList.cpp` | `0000M4` | Eighteen direct uses across six ObjectList extended type lookup helpers: `sub_533170`, `sub_5333B0`, `sub_533600`, `sub_533850`, `sub_533A90`, and `sub_533D00`. |

None of those source roots owns the full observed use set. `ObjectList` is the largest consumer, but it does not own the MapPane direct check or the LivingObjectPane method. `MapPane` is the broad map-world module, but it owns only one direct use of this literal and also calls into ObjectList/LivingObjectPane surfaces. `LivingObjectPane` owns the suffix helper but not the MapPane/ObjectList lookup family. The physical container [UID:0003C1] `MapNameMiniMapResourceStrings` is a non-emitting mixed string index and is not a source declaration owner.

## Current Documentation Recheck

The target page currently records this literal as a source-authored pooled `.rdata` literal with no canonical owner and three emitters. It records all 20 executable xrefs and rejects the same over-broad candidate owners found in this pass.

The relevant source roots are scored and routed:

| UID | Page | Current source route | Current score | Relevance |
| --- | --- | --- | --- | --- |
| `0000L3` | `by-file/MapPane.md` | `NexusTK/map/` / `map/MapPane.cpp` | `89/85` | Main live game-world pane; owns the `sub_505430` direct use only. |
| `0000KU` | `by-file/LivingObjectPane.md` | `NexusTK/map/` / `map/LivingObjectPane.cpp` | `88/85` | Actor/entity source file; owns [UID:000233] suffix helper. |
| `0000M4` | `by-file/ObjectList.md` | `NexusTK/map/` / `map/ObjectList.cpp` | `85/88` | Map object index source file; owns the extended type lookup helpers. |

The current mixed parent [UID:0003C1] `0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings` is `90/94`, `RECONSTRUCTABLE:FALSE`, and non-emitting. Its child table separates `MAPNAME.EPF`, `MMAPBUT.EPF`, `CMAP`, and this shared `GM` literal. That parent page explicitly states that `GM` keeps `CANONICAL_OWNER:NONE` while emitting through the three proven source-use routes.

The current generated coverage state also matches the recommendation:

- `auto-generated/-ag-memory-coverage.md` lists [UID:0003IO] as `no-owner`, owner `NONE`, emitters `0000L3`,`0000KU`,`0000M4`.
- The generated summary rows list the emitter roots as [UID:0000L3] `MapPane`, [UID:0000KU] `LivingObjectPane`, and [UID:0000M4] `ObjectList`.

## IDA MCP Session

Fresh IDA MCP evidence was collected from the live session:

```text
session_id: a001_goal2_class_batch
idb_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
module: NexusTK.exe
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
strings_cache_size: 2067
```

Tools used: `server_health`, `get_bytes`, `get_string`, `xrefs_to`, `lookup_funcs`, `find_bytes`, `make_signature_for_range`, `disasm`, `decompile`, and `analyze_component`.

## IDA Byte And String Facts

`get_bytes(0x0061e6f0, 0x20)` returned the local byte layout:

```text
43 4d 41 50 00 00 00 00 47 00 4d 00 00 00 00 00 d4 b2 64 00 50 4d 51 00 34 b2 64 00 80 4d 51 00
```

Interpretation:

| Address | IDA string result | Meaning |
| --- | --- | --- |
| `0x0061e6f0` | `CMAP` | Predecessor ANSI `CMAP` child. |
| `0x0061e6f8` | `GM` | Target UTF-16LE `GM` literal. |
| `0x0061e6fc` | no string | Interior/tail null area, not a separate string. |
| `0x0061e700` | no string | End boundary. |
| `0x0061e704` | `PMQ` | Successor table/vtable data, outside this child. |

`make_signature_for_range(0x0061e6f8, 0x0061e700)` returned the unique signature:

```text
47 00 4D 00 00 00 00 00
```

`find_bytes` confirmed:

| Pattern | Result |
| --- | --- |
| `47 00 4D 00 00 00 00 00` | One match, `0x0061e6f8`. |
| `F8 E6 61 00` | Twenty matches, all immediate operands for the 20 xref instructions. |

The absolute address operand matches are at `0x00505506`, `0x00514ec6`, `0x0053321b`, `0x005332b6`, `0x0053334d`, `0x00533446`, `0x00533516`, `0x005335b8`, `0x005336a6`, `0x00533739`, `0x005337d8`, `0x005338dd`, `0x0053397b`, `0x00533a1c`, `0x00533b3b`, `0x00533bfb`, `0x00533ca6`, `0x00533d9b`, `0x00533e6b`, and `0x00533f1a`.

## IDA Xref Facts

`xrefs_to(0x0061e6f8)` returned exactly 20 data xrefs. `xrefs_to(0x0061e6fc)` and `xrefs_to(0x0061e700)` returned zero xrefs, so there is no interior/tail child and no end-boundary user.

| Xref | Function | Function size | Source-use route |
| --- | --- | --- | --- |
| `0x00505505` | `sub_505430` | `0x19a` | MapPane / `0000L3` |
| `0x00514ec5` | `sub_514EA0` | `0x3d` | LivingObjectPane / `0000KU` |
| `0x0053321a` | `sub_533170` | `0x240` | ObjectList / `0000M4` |
| `0x005332b5` | `sub_533170` | `0x240` | ObjectList / `0000M4` |
| `0x0053334c` | `sub_533170` | `0x240` | ObjectList / `0000M4` |
| `0x00533445` | `sub_5333B0` | `0x24e` | ObjectList / `0000M4` |
| `0x00533515` | `sub_5333B0` | `0x24e` | ObjectList / `0000M4` |
| `0x005335b7` | `sub_5333B0` | `0x24e` | ObjectList / `0000M4` |
| `0x005336a5` | `sub_533600` | `0x243` | ObjectList / `0000M4` |
| `0x00533738` | `sub_533600` | `0x243` | ObjectList / `0000M4` |
| `0x005337d7` | `sub_533600` | `0x243` | ObjectList / `0000M4` |
| `0x005338dc` | `sub_533850` | `0x23d` | ObjectList / `0000M4` |
| `0x0053397a` | `sub_533850` | `0x23d` | ObjectList / `0000M4` |
| `0x00533a1b` | `sub_533850` | `0x23d` | ObjectList / `0000M4` |
| `0x00533b3a` | `sub_533A90` | `0x267` | ObjectList / `0000M4` |
| `0x00533bfa` | `sub_533A90` | `0x267` | ObjectList / `0000M4` |
| `0x00533ca5` | `sub_533A90` | `0x267` | ObjectList / `0000M4` |
| `0x00533d9a` | `sub_533D00` | `0x26d` | ObjectList / `0000M4` |
| `0x00533e6a` | `sub_533D00` | `0x26d` | ObjectList / `0000M4` |
| `0x00533f19` | `sub_533D00` | `0x26d` | ObjectList / `0000M4` |

## Consumer Evidence

### MapPane Consumer

`lookup_funcs` maps `0x00505430` and xref `0x00505505` to `sub_505430`, size `0x19a`.

`disasm(0x00505430)` shows a MapPane-style helper using `[edi+424h]` to call `sub_533090`, then computing a UTF-16 suffix pointer on a returned object and executing:

```text
0x00505505 push offset aGm
0x0050550d push eax
0x0050550e call __wcsicmp
```

This proves a direct MapPane source-use context. It does not prove MapPane owns the literal globally, because the same bytes are also used by LivingObjectPane and ObjectList.

### LivingObjectPane Consumer

[UID:000233] `0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck` is `84/92`, `CANONICAL_OWNER:0000KU`, and `EMITTER_UIDS:0000KU`.

Fresh `decompile(0x00514ea0)` returns a compact actor-owned suffix helper:

```text
return _wcsicmp((const wchar_t *)&this[2 * ((v2 - v3) >> 1) + 294], L"GM") == 0;
```

The decompile refs include `0x0061e6f8` / `aGm`, and the function has one direct literal xref at `0x00514ec5`. This proves the LivingObjectPane source-use route. The method reads the actor name buffer; its MapPane caller is consumer evidence only.

### ObjectList Consumers

[UID:00023F] `0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers` is `85/86`, `CANONICAL_OWNER:00009Q`, and `EMITTER_UIDS:00009Q`. Its page assigns the helper family to [UID:00009Q] `ObjectList`, routed through [UID:0000M4] `ObjectList`.

Fresh `lookup_funcs` resolves the six repeated consumers:

| Function | Size | Callees from `analyze_component` |
| --- | --- | --- |
| `sub_533170` | `0x240` | `__wcsicmp`, `sub_535CE0` |
| `sub_5333B0` | `0x24e` | `__wcsicmp`, `sub_535CE0` |
| `sub_533600` | `0x243` | `__wcsicmp`, `sub_535CE0` |
| `sub_533850` | `0x23d` | `__wcsicmp`, `sub_535CE0` |
| `sub_533A90` | `0x267` | `__wcsicmp`, `sub_535CE0` |
| `sub_533D00` | `0x26d` | `__wcsicmp`, `sub_535CE0` |

`disasm(0x00533170)` shows the ObjectList pattern directly: `sub_535CE0` decodes a key, row/global object-list tiers are traversed, the candidate object name suffix is computed, and `0x0053321a` pushes `offset aGm` before `__wcsicmp`. The same pattern repeats across the six ObjectList helpers, producing 18 total xrefs.

This proves the ObjectList source-use route. It does not justify making ObjectList the canonical owner because ObjectList does not own the MapPane direct use or the separate LivingObjectPane suffix method.

## Component Analysis

`analyze_component` over the eight modeled consumers returned:

- Functions: `sub_505430`, `sub_514EA0`, `sub_533170`, `sub_5333B0`, `sub_533600`, `sub_533850`, `sub_533A90`, and `sub_533D00`.
- Shared global: `0x0061e6f8`, name `aGm`.
- Accessed by all eight modeled consumers.
- Internal call graph edges: none among the eight selected consumers.
- ObjectList functions call `__wcsicmp` and `sub_535CE0`.
- The LivingObjectPane suffix helper calls only `__wcsicmp`.
- The MapPane helper calls MapPane/object-index helpers and `__wcsicmp`.

The component result is decisive negative owner evidence. It proves `aGm` is the shared global across the selected consumer set, but it does not reveal a common helper, common source file, or declaration object that owns the literal across all use sites.

## Ownership Analysis

| Candidate | Verdict | Reason |
| --- | --- | --- |
| [UID:0000L3] `MapPane` | Reject as canonical owner; keep as emitter. | Valid source root and direct xref at `0x00505505`, but only covers one of 20 direct literal xrefs. |
| [UID:0000KU] `LivingObjectPane` | Reject as canonical owner; keep as emitter. | Valid source root and direct suffix helper owner, but covers only `sub_514EA0`. |
| [UID:0000M4] `ObjectList` | Reject as canonical owner; keep as emitter. | Valid source root and largest consumer with 18 xrefs, but cannot own the MapPane direct check or LivingObjectPane actor method. |
| [UID:0003C1] `MapNameMiniMapResourceStrings` | Reject as canonical owner and emitter. | Non-emitting mixed container over four literals with different source routes. |
| Standalone `GmString`, `StaffString`, or shared constants file | Reject. | No IDA symbol, xref pattern, source-tree entry, or documentation evidence supports a declaration object; all evidence is use-site literal comparison. |
| Split into children | Reject. | The target is already an exact child; `xrefs_to` found no refs to `0x0061e6fc` or `0x0061e700`; unique signature covers exactly the current 8-byte span. |
| Reclassify as non-reconstructable/non-emitting | Reject. | The source-facing item is reconstructable as a literal use at each proven source route; only canonical declaration ownership is absent. |

## Why Reconstructable With No Canonical Owner Is Correct

`RECONSTRUCTABLE:TRUE` is correct because the bytes correspond to a real source-level literal, `L"GM"`, used in suffix comparisons. The reconstruction target is not an address-stable global variable. It is the source literal content needed by each consuming source file.

`CANONICAL_OWNER:NONE` is correct because source ownership gates require a defensible declaration/source owner for the whole item. The single physical `.rdata` instance is shared by three independent source-use families. Any one-owner assignment would overclaim:

- `MapPane` would overclaim the LivingObjectPane and ObjectList use sites.
- `LivingObjectPane` would overclaim MapPane and ObjectList.
- `ObjectList` would overclaim MapPane and LivingObjectPane.
- The mixed `.rdata` parent would overclaim several unrelated child literals.

`EMITTER_UIDS:0000L3,0000KU,0000M4` is correct because it records where reconstructed source may need to spell or otherwise materialize `L"GM"` at use sites. This prevents the no-owner item from becoming lost/non-emitting while avoiding a false canonical declaration owner.

## Split And Child-Page Decision

No split is needed and no child files should be created.

The target already covers the exact literal plus alignment/tail nulls from `0x0061e6f8` through `0x0061e700`. The predecessor `CMAP` child ends at `0x0061e6f8`, and the successor table/vtable region begins after `0x0061e700`. IDA found no xrefs to the interior/tail at `0x0061e6fc` or to the boundary `0x0061e700`. The exact byte pattern is unique, and the immediate-address pattern accounts for all 20 direct code uses.

## Required Coverage Action

No coverage action is required.

If a supervisor still wants row text for review, retain the current row exactly as shown in the Final Recommendation section. Do not directly edit `by-memory/-coverage-report.md` as part of this B-agent report.

## Worktree And Lease Notes

Only this research report was created. No by-* file, tracker file, generated coverage file, or coverage report was edited by this pass. No lease was required because the only new file is inside Agent-B001's own research folder.

The working tree already showed unrelated dirty/untracked files in `by-memory`, generated coverage, tracker, and Agent-B001 folders before this report was written. Those files were not reverted or modified.

## Validator / Verification

- Current docs rechecked: target page, mixed parent page, coverage row, generated coverage rows, source file roots, and consumer memory pages.
- Fresh IDA MCP rechecked: server readiness, bytes, strings, xrefs, function containment, byte-pattern uniqueness, representative disassembly/decompile, and component analysis.
- Numeric checks: `0x8` = 8, `0x2` = 2, `0x14` = 20 via `tools/int_convert.py`.
- Recommended metadata: unchanged.
- Required edits outside this report: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003IO","source_path":"executed-b-agent-research/B001/0003IO-SharedGmWideString-live-goal2-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
