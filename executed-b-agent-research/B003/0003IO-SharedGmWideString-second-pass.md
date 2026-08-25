** TARGET-REPORT-UID:0003IO **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003IO **
# B003-0003IO Second-Pass Report - SharedGmWideString

## Final Recommendation

Keep [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](../../../../../by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) exactly as it is:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000KU,0000M4
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE:
```

No coverage-row change is recommended. Score remains `88/93`.

This is a valid current-model state: `CANONICAL_OWNER:NONE` means no single semantic declaration/source owner is proven for the pooled literal, while `EMITTER_UIDS:0000L3,0000KU,0000M4` means the item is not non-emitting. It has three proven source-use output routes: [UID:0000L3][MapPane](../../../../../by-file/MapPane.md), [UID:0000KU][LivingObjectPane](../../../../../by-file/LivingObjectPane.md), and [UID:0000M4][ObjectList](../../../../../by-file/ObjectList.md). The source reconstruction should spell the local wide literal `L"GM"` at each proven use site when those consumers are ready, not invent a standalone global or assign ownership to the consumer with the most xrefs.

No split, non-reconstructable reclassification, canonical owner, or IDA/documentation repair is needed for this item.

## Target And Current State

Target page: [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](../../../../../by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md)

Current header:

```text
UID:0003IO
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000KU,0000M4
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE:
```

Memory range: `0x0061e6f8-0x0061e700`.

Literal bytes: `47 00 4D 00 00 00 00 00`, UTF-16LE `GM` plus terminator and alignment.

Containing index: [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](../../../../../by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md), a reviewed `RECONSTRUCTABLE:FALSE` mixed string-data index. The exact child remains reconstructable.

## Prior Report Comparison

Prior executed report: `tools/leaser/Agents/Agent-B002/research/executed/0003IO-SharedGmWideString.md`.

The prior report concluded that the old parentless state should now be interpreted as `CANONICAL_OWNER:NONE` plus source-use emitters `0000L3,0000KU,0000M4`. This second pass independently rechecked the current by-structure owner/emitter rules, current by-memory/by-file/by-class documentation, and raw PE reference evidence. I found no new fact that weakens the prior recommendation.

Before: `88/93`, no owner, emitters `0000L3,0000KU,0000M4`.

After: `88/93`, no owner, emitters `0000L3,0000KU,0000M4`.

## Current Owner/Emitter Rule Check

[by-structure.md](../../../../../by-structure.md) separates semantic ownership from generated-output routing:

- `CANONICAL_OWNER` is the narrowest proven semantic owner.
- `EMITTER_UIDS` is output routing and may contain multiple UIDs.
- Compiler/linker-pooled string literals with no defensible single owner can remain `CANONICAL_OWNER:NONE` and still carry multiple emitters for proven source-use contexts.
- This state is not the same as non-emitting.

`0003IO` is exactly that case. IDA and raw PE evidence prove multiple direct source-use contexts, but do not prove a shared declaration owner, source-local static object, helper, header constant, or single class/file owner. Keeping `RECONSTRUCTABLE:TRUE` is correct because the bytes represent source-authored `L"GM"` literal use that must be recreated in source. Keeping the C++ block blank is also correct because this page does not represent a standalone declaration; the reconstructed literal belongs inside the eventual consumer bodies.

The item is below the practical code-entry gate on completion (`88`) even though confidence is high (`93`), and the source shape is "repeat literal at proven use sites" rather than a standalone memory-range C++ declaration.

## IDA MCP Evidence From Current Documentation

The target page records a live IDA MCP refresh from 2026-06-12 using session `b001_nexustk` against `NexusTK.exe.i64`:

- IDA name: `aGm`.
- Listing representation: `text "UTF-16LE", 'GM',0`.
- Surrounding `.rdata` query found `aCmap` at `0x0061e6f0`, `aGm` at `0x0061e6f8`, and successor `ProtectedArray<GameServerConfig::NationEntry>` vtable data at `0x0061e704`.
- `make_signature_for_range 0x0061e6f8-0x0061e700` returned the unique byte signature `47 00 4D 00 00 00 00 00`.
- `trace_data_flow` shows the use sites push `offset aGm`.

Documented direct executable xrefs:

```text
MapPane:
  0x00505505 inside sub_505430

LivingObjectPane:
  0x00514ec5 inside sub_514EA0

ObjectList:
  0x0053321a
  0x005332b5
  0x0053334c
  0x00533445
  0x00533515
  0x005335b7
  0x005336a5
  0x00533738
  0x005337d7
  0x005338dc
  0x0053397a
  0x00533a1b
  0x00533b3a
  0x00533bfa
  0x00533ca5
  0x00533d9a
  0x00533e6a
  0x00533f19
```

Current consumer documentation supports the three-way split:

- [UID:0001AP][MapPaneWeatherCoordinateObjectCore](../../../../../by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) contains `0x00505430-0x005055ca`, a MapPane movement collision/nation-mask helper that performs the MapPane-side GM/object status check.
- [UID:000233][LivingObjectPaneGmNameSuffixCheck](../../../../../by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md) is an exact `0x3d` byte LivingObjectPane helper. It scans the actor name buffer and calls `__wcsicmp(..., L"GM") == 0`; the only direct caller is a MapPane update/render helper, but the accessed state and method ownership remain LivingObjectPane.
- [UID:00023F][ObjectListExtendedTypeLookupHelpers](../../../../../by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) is an ObjectList helper family. Its `0x00533170-0x00533f6d` subrange contains six type-specific add/lookup helpers called from MapPane wrappers, but operating on ObjectList fields and encoded object-list keys.

## Fresh Raw PE Evidence

Raw PE scan target: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

PE facts from the scan:

```text
imagebase=0x00400000
target_section=.rdata
target_rva=0x0021e6f8
target_raw=0x0021d0f8
target_bytes=47 00 4D 00 00 00 00 00
```

Exact byte-pattern scan:

```text
exact_pattern_hits=1
  off=0x0021d0f8 va=0x0061e6f8 sect=.rdata
```

Absolute VA scan for `0x0061e6f8` found exactly 20 dword hits, all in `.text`, and all are `push 0x0061e6f8` instruction operands:

```text
0x00505505
0x00514ec5
0x0053321a
0x005332b5
0x0053334c
0x00533445
0x00533515
0x005335b7
0x005336a5
0x00533738
0x005337d7
0x005338dc
0x0053397a
0x00533a1b
0x00533b3a
0x00533bfa
0x00533ca5
0x00533d9a
0x00533e6a
0x00533f19
```

Negative raw scans:

```text
RVA 0x0021e6f8 hits: 0
Interior VA 0x0061e6fa hits: 0
Interior VA 0x0061e6fc hits: 0
Interior VA 0x0061e6fe hits: 0
End VA 0x0061e700 hits: 0
End RVA 0x0021e700 hits: 0
Dword values pointing inside 0x0061e6f8-0x0061e700 as RVA: 0
```

Surrounding raw bytes confirm the split:

```text
0x0061e6c0: 4D 00 41 00 50 00 4E 00 41 00 4D 00 45 00 2E 00
0x0061e6d0: 45 00 50 00 46 00 00 00 4D 00 4D 00 41 00 50 00
0x0061e6e0: 42 00 55 00 54 00 2E 00 45 00 50 00 46 00 00 00
0x0061e6f0: 43 4D 41 50 00 00 00 00 47 00 4D 00 00 00 00 00
0x0061e700: D4 B2 64 00 50 4D 51 00 34 B2 64 00 80 4D 51 00
```

Successor scan:

- `0x0061e700` has no pointer hits.
- `0x0061e704` has five pointer hits, consistent with the following vtable/table data being a separate referenced item.
- `0x0061e700` itself contains `0x0064b2d4`, and `0x0061e704` contains function pointer `0x00514d50`.

This independently confirms that `0x0061e6f8-0x0061e700` is an exact literal child, not a range that should absorb the successor vtable/table data.

## Documentation Evidence

Current file/class roots clear the emitter route:

- [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) is `89/85`, `CANONICAL_OWNER:FILE`, path `NexusTK/map/`.
- [UID:0000KU][LivingObjectPane](../../../../../by-file/LivingObjectPane.md) is `88/85`, `CANONICAL_OWNER:FILE`, path `NexusTK/map/`.
- [UID:0000M4][ObjectList](../../../../../by-file/ObjectList.md) is `85/88`, `CANONICAL_OWNER:FILE`, path `NexusTK/map/`.

Current class/root docs distinguish the three consumers:

- [UID:00007Q][MapPane](../../../../../by-class/MapPane.md) owns the live game-world pane, coordinate/movement helper surface, map packets, rendering, and object insertion/removal policy.
- [UID:00007B][LivingObjectPane](../../../../../by-class/LivingObjectPane.md) owns actor state, including the scattered GM suffix accessor [UID:000233].
- [UID:00009Q][ObjectList](../../../../../by-class/ObjectList.md) owns the map object-index layout and helper islands, including [UID:00023F].

[by-project-structure/proposed-source-tree.md](../../../../../by-project-structure/proposed-source-tree.md) places all three as distinct map source modules:

```text
map/MapPane.cpp
map/ObjectList.cpp
map/LivingObjectPane.cpp
```

[inference_research.md](../../../inference_research.md) cautions against assigning ownership from `.rdata` adjacency alone because linkers pool strings and reorder constants. Here, ownership must follow consumer/source-use evidence, not the physical neighborhood.

## Source-Use And Emitter Inventory

### Emitter `0000L3` - MapPane

Supported. The `0x00505505` direct `push offset aGm` occurs inside MapPane `sub_505430`, documented within [UID:0001AP][MapPaneWeatherCoordinateObjectCore](../../../../../by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md). This is a direct source-use site in MapPane code.

Use in source reconstruction: local `L"GM"` literal at the MapPane movement/collision/status check site when that method reaches code-entry quality.

### Emitter `0000KU` - LivingObjectPane

Supported. The `0x00514ec5` direct `push offset aGm` occurs inside [UID:000233][LivingObjectPaneGmNameSuffixCheck](../../../../../by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md). That helper reads a LivingObjectPane name buffer and returns whether the suffix equals `L"GM"`.

The helper is called from MapPane, but that is consumer/caller evidence only. The method's receiver and state ownership make `LivingObjectPane.cpp` the source-use emitter for this occurrence.

Use in source reconstruction: local `L"GM"` literal in the LivingObjectPane suffix helper when that helper reaches code-entry quality.

### Emitter `0000M4` - ObjectList

Supported. The remaining 18 direct `push offset aGm` instructions occur inside the [UID:00023F][ObjectListExtendedTypeLookupHelpers](../../../../../by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) family, particularly the six type-specific helpers from `0x00533170` through `0x00533d00`.

MapPane wrappers call the ObjectList helpers, but current ObjectList documentation shows the helpers operate on ObjectList layout fields, encoded object-list keys, and type-specific row/global list tiers. That makes `ObjectList.cpp` the correct source-use emitter for those occurrences.

Use in source reconstruction: local `L"GM"` literals in the ObjectList helper implementations when those helpers reach code-entry quality.

## Candidate Owners Ranked

1. `CANONICAL_OWNER:NONE` with emitters `0000L3,0000KU,0000M4` - accepted. It matches current by-structure guidance for pooled/shared literals with multiple proven source-use contexts and no proven single declaration owner.

2. [UID:00009Q][ObjectList](../../../../../by-class/ObjectList.md) or [UID:0000M4][ObjectList](../../../../../by-file/ObjectList.md) - rejected as canonical owner. ObjectList accounts for 18 of 20 xrefs, but not the direct MapPane `sub_505430` xref or the direct LivingObjectPane suffix-helper xref. Picking ObjectList would overclaim based on xref count.

3. [UID:00007B][LivingObjectPane](../../../../../by-class/LivingObjectPane.md) or [UID:0000KU][LivingObjectPane](../../../../../by-file/LivingObjectPane.md) - rejected as canonical owner. It owns one exact suffix helper, but the MapPane and ObjectList uses are independent direct pushes of the same pooled literal.

4. [UID:00007Q][MapPane](../../../../../by-class/MapPane.md) or [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) - rejected as canonical owner. MapPane has one direct in-method use and calls/wraps other consumers, but caller dominance is not declaration ownership. The LivingObjectPane and ObjectList helper bodies are not MapPane methods.

5. [UID:0003C1][MapNameMiniMapResourceStrings](../../../../../by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) - rejected as canonical owner/emitter. It is a non-emitting mixed index over unrelated exact children: `MAPNAME.EPF`, `MMAPBUT.EPF`, `CMAP`, and shared `GM`.

6. New shared helper/header/global constant - rejected. No current IDA MCP fact, raw pointer evidence, source-tree entry, common helper call, or documentation evidence proves an original `GmNameRules`, `ActorNameRules`, shared constants header, or standalone global declaration.

## Negative Evidence And Repair Check

- No single function, class, or file covers all 20 direct xrefs.
- No common GM/name helper is called by MapPane, LivingObjectPane, and ObjectList for this literal.
- The raw PE has exactly one byte-pattern hit for the literal, consistent with linker/string pooling.
- The raw PE has no RVA references to the literal.
- The raw PE has no pointer references to interior addresses `0x0061e6fa`, `0x0061e6fc`, or `0x0061e6fe`.
- The raw PE has no pointer references to end address `0x0061e700`.
- The following `0x0061e700+` data has its own vtable/table references, so the existing child boundary is clean.
- Physical `.rdata` adjacency is mixed and not ownership evidence.
- The current [UID:0003C1] container already performs the needed parent split and is correctly non-emitting.

No split or IDA/function repair is indicated. The item is exactly one source-authored pooled literal and should not be reclassified to `RECONSTRUCTABLE:FALSE`.

## Exact Required Changes

No metadata change is required.

Retain the current metadata:

```text
*** UID:0003IO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3,0000KU,0000M4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No `by-memory/-coverage-report.md` replacement row is required. If the supervisor wants a no-op validation target, the current row should remain:

```text
        - [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) 0x0061e6f8-0x0061e700 | string-data | SharedGmWideString : reconstructable : 88% : very-strong : UTF-16LE `GM` pooled source literal; A004 Batch345 live MCP reconfirmed `aGm` at `0x0061e6f8`, unique raw signature `47 00 4D 00 00 00 00 00`, 20 direct code xrefs across MapPane `sub_505430`, LivingObjectPane suffix check `0x00514ea0`, and six ObjectList lookup helpers from `0x00533170` through `0x00533d00`; `CANONICAL_OWNER:NONE` because MapPane, LivingObjectPane, ObjectList, and the physical mixed container each overclaim direct ownership, while `EMITTER_UIDS:0000L3,0000KU,0000M4` records the three proven source-use file roots.
```

## Validation Notes

Actions performed for this pass:

- Read Agent-B003 `goal.md`.
- Read the target page, prior executed B002 report, current coverage rows, `by-structure.md`, `inference_research.md`, source-tree/file/class docs, and the three xref-bearing memory pages.
- Searched current project docs for `0003IO`, `0061e6f8`, `SharedGmWideString`, `aGm`, and `L"GM"` to check for newer contradictory notes.
- Ran a fresh raw PE scan against `NexusTK.exe` for exact bytes, absolute VA/RVA references, interior/tail references, and successor boundary references.

No by-* files or coverage reports were edited. No lease was needed because this report is inside Agent-B003's assigned research folder.

## Confidence And Remaining Blockers

Confidence in the metadata recommendation is high. The only remaining uncertainty is original source spelling: the compiler could have pooled repeated `L"GM"` literals from three files, or the source could have used an unproven shared constant/header. Current evidence does not prove the shared-declaration case, so the current multiple-emitter/no-canonical-owner model is the least overclaiming representation.

This uncertainty does not block the current metadata because `EMITTER_UIDS` captures the proven source-use contexts without asserting a semantic owner.

## Changed Files

- `tools/leaser/Agents/Agent-B003/research/0003IO-SharedGmWideString-second-pass.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003IO","source_path":"executed-b-agent-research/B003/0003IO-SharedGmWideString-second-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
