** TARGET-REPORT-UID:0003IO **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003IO **
# 0003IO SharedGmWideString Current No-Owner Research

## Final Recommendation

Keep [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](../../../../../by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) as:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000KU,0000M4
COMPLETION:88
CONFIDENCE:93
```

No canonical owner, emitter change, split, merge, reclassification, IDA-safe rename, or by-memory repair is warranted. The item is a pooled UTF-16 `GM` literal with direct source-use evidence in three separate map-side source roots: [UID:0000L3][MapPane](../../../../../by-file/MapPane.md), [UID:0000KU][LivingObjectPane](../../../../../by-file/LivingObjectPane.md), and [UID:0000M4][ObjectList](../../../../../by-file/ObjectList.md). The xref distribution is not ownership proof for any one file.

Code-entry impact: no final C++ should be entered for this by-memory page. Although the page is marked reconstructable and has nonblank emitters, this page is the pooled data literal itself, not a source-level declaration with a defensible single owner. Current generated map source files are present but zero-length placeholders, so there is no proven non-dead-end source insertion point for a standalone declaration.

## Target And Scope

- Assignment: current Goal 2 no-owner memory sweep.
- Target: `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`.
- Prior report reviewed as background only: `Agent-B003/research/executed/0003IO-SharedGmWideString-current-no-owner-sweep.md`.
- Current tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` assigns `0003IO` to Agent-B002 for 2026-06-14.
- Current generated status in `auto-generated/-ag-memory-coverage.md`: no-owner, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000L3,0000KU,0000M4`.

This pass did not edit by-memory pages, generated reports, or shared coverage reports.

## Evidence Standard Used

I treated the current documentation and prior reports as leads, then rechecked:

- live IDA MCP session `b001_0002bd` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`;
- raw PE bytes from the read-only executable;
- current by-memory target and parent pages;
- current file-owner pages for MapPane, LivingObjectPane, and ObjectList;
- current generated memory coverage rows and tracker rows;
- generated source file presence and source-surface state.

The owner test applied is the current by-structure owner/emitter model: pooled/shared literals may remain `CANONICAL_OWNER:NONE` when no single source declaration owner is proven, while `EMITTER_UIDS` should name all proven source-use output routes.

## Current Documentation State

The target header currently says:

```text
UID:0003IO
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000KU,0000M4
```

The target body describes `0x0061e6f8-0x0061e700` as UTF-16 `GM` plus padding/alignment, with 20 executable xrefs. The current parent [UID:0003C1][MapNameMiniMapResourceStrings](../../../../../by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) is already a non-emitting mixed string-data index. It correctly splits the physical string cluster into separate exact children:

| UID | Range | Role | Current routing |
| --- | --- | --- | --- |
| `0003IL` | `0x0061e6c0-0x0061e6d8` | `MAPNAME.EPF` | MapNamePane |
| `0003IM` | `0x0061e6d8-0x0061e6f0` | `MMAPBUT.EPF` | MiniMapButtonPane |
| `0003IN` | `0x0061e6f0-0x0061e6f8` | ANSI `CMAP` | MapPane through pointer anchor |
| `0003IO` | `0x0061e6f8-0x0061e700` | UTF-16 `GM` | no owner, emitters `0000L3,0000KU,0000M4` |

The parent/child boundary is still appropriate. `0x0061e700` is not another string start for this item, and `0x0061e704` belongs to separate successor data.

## Live IDA MCP Facts

Session health:

```text
server_health: ok
imagebase: 0x400000
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
hexrays_ready: true
auto_analysis_ready: true
```

String and byte checks:

```text
get_string 0x0061e6f8 -> "GM"
get_string 0x0061e700 -> no string
get_string 0x0061e704 -> "PMQ"
make_signature_for_range 0x0061e6f8-0x0061e700 -> 47 00 4D 00 00 00 00 00, unique:true
```

IDA byte window from `0x0061e6c0` shows the target and successor boundary:

```text
... 43 4d 41 50 00 00 00 00 47 00 4d 00 00 00 00 00 d4 b2 64 00 50 4d 51 00 ...
                         ^ CMAP tail        ^ target GM           ^ successor dword / PMQ-adjacent data
```

Xrefs to `0x0061e6f8`:

- `0x00505505` in `sub_505430` (`0x00505430`, size `0x19a`) - MapPane movement/object gate consumer.
- `0x00514ec5` in `sub_514EA0` (`0x00514ea0`, size `0x3d`) - LivingObjectPane GM suffix check.
- `0x0053321a`, `0x005332b5`, `0x0053334c` in `sub_533170`.
- `0x00533445`, `0x00533515`, `0x005335b7` in `sub_5333B0`.
- `0x005336a5`, `0x00533738`, `0x005337d7` in `sub_533600`.
- `0x005338dc`, `0x0053397a`, `0x00533a1b` in `sub_533850`.
- `0x00533b3a`, `0x00533bfa`, `0x00533ca5` in `sub_533A90`.
- `0x00533d9a`, `0x00533e6a`, `0x00533f19` in `sub_533D00`.

Negative xref evidence:

- `xrefs_to 0x0061e6fa`, `0x0061e6fc`, `0x0061e6fe`, and `0x0061e700` returned zero refs.
- `xrefs_to 0x0061e704` returned five separate successor-data refs, confirming the target should not absorb successor data.
- `find_bytes 68 F8 E6 61 00` returned exactly the 20 push-immediate sites above.
- `find_bytes F8 E6 61 00` returned exactly the 20 embedded absolute-address operands.
- `find_bytes FA E6 61 00`, `FC E6 61 00`, `FE E6 61 00`, and `00 E7 61 00` returned zero hits.

## Function And Consumer Inventory

IDA decompilation confirms the literal is used as a suffix/type filter, not as a constructed global object.

MapPane route, emitter `0000L3`:

```text
0x00505430 sub_505430
if (_wcsicmp(..., L"GM") && !*(byte *)(object + 466)) ...
refs: __wcsicmp, aGm at 0x0061e6f8
```

LivingObjectPane route, emitter `0000KU`:

```text
0x00514ea0 sub_514EA0
return _wcsicmp((const wchar_t *)&this[... + 294], L"GM") == 0;
refs: __wcsicmp, aGm at 0x0061e6f8
```

ObjectList route, emitter `0000M4`:

```text
0x00533170 sub_533170: three _wcsicmp(..., L"GM") checks
0x005333b0 sub_5333B0: three _wcsicmp(..., L"GM") checks
0x00533600 sub_533600: three _wcsicmp(..., L"GM") checks
0x00533850 sub_533850: three _wcsicmp(..., L"GM") checks
0x00533a90 sub_533A90: three _wcsicmp(..., L"GM") checks
0x00533d00 sub_533D00: three _wcsicmp(..., L"GM") checks
refs: __wcsicmp, aGm at 0x0061e6f8
```

The ObjectList helpers account for 18 of 20 direct code xrefs, but the other two xrefs are not incidental address-taken references. They are direct `_wcsicmp(..., L"GM")` consumers in separate MapPane and LivingObjectPane contexts.

## Raw PE Evidence

Raw file inspected: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

```text
imagebase: 0x400000
target VA: 0x0061e6f8
target RVA: 0x21e6f8
section: .rdata, VA 0x20d000, raw pointer 0x20ba00
raw offset: 0x21d0f8
target bytes: 47 00 4d 00 00 00 00 00 d4 b2 64 00 50 4d 51 00
```

Whole-file raw search:

```text
47 00 4d 00 00 00 00 00 -> 1 hit at raw 0x21d0f8
68 f8 e6 61 00 -> 20 hits
f8 e6 61 00 -> 20 hits, all as operands of the same push sites
fa e6 61 00 -> 0 hits
fc e6 61 00 -> 0 hits
00 e7 61 00 -> 0 hits
04 e7 61 00 -> 5 hits, matching successor-data refs
f8 e6 21 00 -> 0 hits
```

This supports the current exact range and rejects an interior split, an end-at-`0x0061e704` merge, or a pointer-table/RVA-style owner.

## Generated Source Surface

The current generated coverage rows route this no-owner item through `auto-generated/NexusTK/map/LivingObjectPane.cpp` while listing all three emitter UIDs. The actual files under `auto-generated/NexusTK/map/` currently include `MapPane.cpp`, `LivingObjectPane.cpp`, and `ObjectList.cpp`, but these map source files are zero-length placeholders. Searches for `SharedGmWideString`, `0x0061e6f8`, and `L"GM"` under `auto-generated/NexusTK` returned no source text.

That means the emitter metadata is still useful as routing/provenance, but it does not justify entering standalone C++ on this pooled literal page.

## Ownership Alternatives Rejected

1. `CANONICAL_OWNER:NONE` with emitters `0000L3,0000KU,0000M4` - accepted.

   This matches by-structure rules for a pooled source literal with multiple direct consumers and no declaration-level owner. Every direct use is a source-use route; none proves storage ownership.

2. Canonical owner `0000M4` ObjectList - rejected.

   ObjectList has 18 of 20 direct xrefs and is the largest consumer, but by-structure rules do not assign ownership by xref majority. MapPane and LivingObjectPane each make direct semantic `_wcsicmp(..., L"GM")` uses of the same literal outside ObjectList. There is no ObjectList-specific declaration, table, initializer, or pointer anchor for the data.

3. Canonical owner `0000KU` LivingObjectPane - rejected.

   `sub_514EA0` is the clearest GM suffix helper and belongs to LivingObjectPane, but it has only one of the 20 direct literal refs. It explains one route, not the pooled literal's storage ownership.

4. Canonical owner `0000L3` MapPane - rejected.

   MapPane has one direct consumer at `sub_505430` and broader map orchestration context, but the same literal is directly used by LivingObjectPane and ObjectList helpers. The nearby `CMAP` child has a MapPane pointer-anchor route; `GM` does not.

5. Canonical owner `0003C1` parent range - rejected.

   The parent physical range mixes `MAPNAME.EPF`, `MMAPBUT.EPF`, `CMAP`, and `GM` children with different routing. The parent is correctly non-emitting and non-reconstructable; making it the owner would hide the proven per-child split.

6. New standalone global/string file - rejected.

   IDA and PE evidence show a single pooled `.rdata` literal with direct push-immediate use. There is no debug symbol, relocation/RVA table, source metadata, pointer slot, or isolated constant cluster supporting a standalone declaration owner.

## Split, Merge, Reclassification, And Rename Analysis

- Split: not needed. The target is already exact: `G\0M\0\0\0\0\0`.
- Merge with `CMAP` child: rejected. `CMAP` is ANSI/pointer-routed and ends at `0x0061e6f8`; `GM` is UTF-16/direct-push-routed.
- Merge with successor data at `0x0061e704`: rejected. `0x0061e700` is a dword and `0x0061e704` has separate xrefs.
- Reclassify to non-reconstructable: rejected for this pass. The page remains reconstructable as reviewed string-data with emitters; only final C++ entry remains unjustified.
- IDA-safe rename repair: not needed. IDA already labels the literal as `aGm`, which is accurate and not harmful.
- Emitter repair: not needed. The direct xrefs prove all three current emitter routes and do not prove any fourth route.

## Exact Required Edits

No in-scope documentation edits are required.

Do not edit `by-memory/-coverage-report.md` for this target. The current shared-report row is still correct and should be retained:

```text
            - [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) 0x0061e6f8-0x0061e700 | string-data | SharedGmWideString : reconstructable : 88% : very strong : UTF-16LE `GM` pooled source literal with `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000L3,0000KU,0000M4`; ownership reviews confirm 20 direct code xrefs across MapPane, LivingObjectPane, and ObjectList consumers, with no single semantic declaration owner.
```

No replacement row is needed for `auto-generated/-ag-memory-coverage.md`; it should be regenerated by the normal generator only if the supervisor wants generated output refreshed. The current canonical generated row should remain equivalent to:

```text
| [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) | no-owner | `NONE` | `0000L3`,`0000KU`,`0000M4` |  | no | `auto-generated/NexusTK/map/LivingObjectPane.cpp` | `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` |  |
```

Recommended tracker update for supervisor application:

```text
| `0003IO` | 0x0061e6f8-0x0061e700.SharedGmWideString | `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` | Agent-B002 | 2026-06-14 | complete-no-change | `Agent-B002/research/0003IO-SharedGmWideString-current-no-owner-research.md` | `Agent-B003/research/executed/0003IO-SharedGmWideString-current-no-owner-sweep.md` |
```

## Validation And Lease State

- Changed files: this report only.
- Leases: no by-* or shared/generated documentation files were edited. Per `goal.md`, no lease was required for this own-agent research report.
- Validator: not run because no by-* documentation file was changed.
- Dry runs: none used.
- Before score: `COMPLETION:88`, `CONFIDENCE:93`.
- After score recommendation: unchanged `COMPLETION:88`, `CONFIDENCE:93`.

## Confidence

Confidence is high for no-change routing. IDA MCP and raw PE checks independently confirm the byte range, unique UTF-16 literal, 20 direct address-use xrefs, absence of interior/end refs, and distinct successor-data refs. The remaining uncertainty is source-authorship-level: without original source or debug metadata, no single declaration owner can be proven. Under the current owner/emitter model, that uncertainty supports `CANONICAL_OWNER:NONE` with the three proven emitters rather than forcing a canonical owner.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003IO","source_path":"executed-b-agent-research/B002/0003IO-SharedGmWideString-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
