** TARGET-REPORT-UID:0001D2 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001D2 MapPaneSpatialIndex Source-Quality Research

Agent: Agent-B012  
Assignment: `B012-report-0001D2-MapPaneSpatialIndex-source-quality-20260627`  
UID: `0001D2`  
Current target: `by-memory/0x00532530-0x0053272e.MapPaneSpatialIndex.md`  
Recommended target name/path after validation: `by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md`  
Report date: 2026-06-27  
Mode: report-only research; no target/support by-* docs, generated files, coverage reports, validator state, tool state, leases, or IDA DB state were modified.

## Finalized Report

UID `0001D2` should not remain source-facing `MapPaneSpatialIndex`. It should be reclassified and renamed as an exact ObjectList accessor-method page, preferably `0x00532530-0x0053272e.ObjectListAccessorMethods.md`, while the ignored class page `[UID:00007R] MapPaneSpatialIndex` remains only a compatibility/search alias.

The implementation target should route through the direct class owner:

```text
COMPLETION:90
CONFIDENCE:91
CANONICAL_OWNER:00009Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00009Q
```

This is not a standalone `MapPaneSpatialIndex` class, not a `MapPane` method family, and not a no-code duplicate of `[UID:0001D3] ObjectListAccessorsAndSweeps`. It is the exact source-authored accessor subset at the front of the broader ObjectList accessor/sweep island. The parent `[UID:0001D3]` should remain a broad aggregate with blank C++; this exact child should carry the first-draft accessor method C++.

The remaining generated/manual tracker rows that still show stale `80/86` or "not covered by an executed B report" are queue/coverage debt, not current source-page state. The current page is already `85/88`; this B012 pass resolves the specific source-quality blockers left by A002: alias identity, class owner/emitter routing, method names, first-draft C++, and exact live MCP boundary/caller proof.

## MCP Availability And Use

Live IDA MCP was available and used. No offline-only report is being finalized.

- MCP listener: `127.0.0.1:13337`, observed listening under Python process PID `21700`.
- Active IDB session: `398b87c1`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Worker PID: `23700`.
- MCP health: `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- Module/image base: `NexusTK.exe`, `0x400000`.
- Read-only MCP tools used: `idb_list`, `server_health`, `entity_query`, `lookup_funcs`, `get_bytes`, `decompile`, `disasm`, `xrefs_to`, `callees`, `make_signature_for_range`.
- No MCP mutation tools were used. No IDA names, comments, types, bytes, functions, or database state were changed.

## Current Target State

Current target header:

```text
UID:0001D2
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:0000M4
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000M4
RECONSTRUCTION_CPP: blank
```

Current content describes a compatibility/provisional `MapPaneSpatialIndex` alias over ObjectList accessors. It already records the correct exclusive endpoint `0x0053272e`, the `0x0053272e-0x00532730` padding gap, ObjectList field offsets, MapPane/FpsPane caller context, and the parent `[UID:0001D3] ObjectListAccessorsAndSweeps` relationship. Its explicit blockers are the final accessor names and alias cleanup; those are now resolvable in this pass.

The current `Covered Ranges` table uses inclusive-looking end labels for several functions. The implementation should switch the table to half-open ranges matching IDA function sizes:

| Start | Exclusive end | IDA name | Size |
| --- | --- | --- | ---: |
| `0x00532530` | `0x00532534` | `sub_532530` | `0x4` |
| `0x00532540` | `0x00532544` | `sub_532540` | `0x4` |
| `0x00532550` | `0x005325ae` | `sub_532550` | `0x5e` |
| `0x005325b0` | `0x0053260e` | `sub_5325B0` | `0x5e` |
| `0x00532610` | `0x00532614` | `sub_532610` | `0x4` |
| `0x00532620` | `0x00532624` | `sub_532620` | `0x4` |
| `0x00532630` | `0x00532634` | `sub_532630` | `0x4` |
| `0x00532640` | `0x00532644` | `sub_532640` | `0x4` |
| `0x00532650` | `0x00532654` | `sub_532650` | `0x4` |
| `0x00532660` | `0x00532664` | `sub_532660` | `0x4` |
| `0x00532670` | `0x005326ce` | `sub_532670` | `0x5e` |
| `0x005326d0` | `0x0053272e` | `sub_5326D0` | `0x5e` |

## Documentation Evidence Checked

Primary and parent docs:

- `[UID:0001D2] by-memory/0x00532530-0x0053272e.MapPaneSpatialIndex.md`
- `[UID:0001D3] by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md`
- `[UID:00009Q] by-class/ObjectList.md`
- `[UID:0000M4] by-file/ObjectList.md`
- `[UID:00007R] by-class/MapPaneSpatialIndex.md`
- `[UID:0001VG] by-type/by-struct/ObjectListLayout.md`
- `by-project-structure/proposed-source-tree.md`
- `by-class/-ignored.md`

Relevant executed reports and support docs:

- B001 `0002BC-ObjectListTierInsertRemoveHelpers-source-quality.md`: establishes high direct-tier names `tertiaryGlobalList`, `quaternaryGlobalList`, `quinaryGlobalList`, row-table taxonomy, and rejection of `MapPaneSpatialIndex` ownership.
- B005/B006/B009 ObjectList exact child implementations: confirm existing ObjectList formal C++ style, field names, `InitRectBounds`, `PointInRect`, `m_primaryCellList`, row arrays, and class owner `00009Q`.
- B010 `00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md`: rejects `MapPaneSpatialIndex` for later ObjectList helper ownership and accepts ObjectList helper/tier vocabulary.
- B013 `00015H-FpsPaneUpdateStatistics-source-quality.md`: documents dependent first-draft FpsPane code calling `GetFrontRowBucket`, `GetBackRowBucket`, and `GetVisibleObjectList`.
- B005/B006 MapPane hit-test/render reports: confirm `0x0050c470`/`0x0050c550` and render/effect paths are MapPane consumers of ObjectList, not owners of these accessors.

## Live MCP Evidence

### Function Inventory

`entity_query` over `0x00532520-0x00532740` returned exactly the twelve accessor functions plus successor `sub_532730`:

```text
0x532530 sub_532530 size 0x4
0x532540 sub_532540 size 0x4
0x532550 sub_532550 size 0x5e
0x5325b0 sub_5325B0 size 0x5e
0x532610 sub_532610 size 0x4
0x532620 sub_532620 size 0x4
0x532630 sub_532630 size 0x4
0x532640 sub_532640 size 0x4
0x532650 sub_532650 size 0x4
0x532660 sub_532660 size 0x4
0x532670 sub_532670 size 0x5e
0x5326d0 sub_5326D0 size 0x5e
0x532730 sub_532730 size 0x442
```

`lookup_funcs` confirmed each exclusive end or padding address is not a function: `0x00532534`, `0x00532544`, `0x005325ae`, `0x0053260e`, `0x00532614`, `0x00532624`, `0x00532634`, `0x00532644`, `0x00532654`, `0x00532664`, `0x005326ce`, and `0x0053272e` all returned `Not a function`. `0x00532730` returned successor `sub_532730`.

### Bytes And Padding

`get_bytes` proves the direct accessors load stored `List *` values, not addresses of embedded lists:

```text
0x00532530: 8b 41 14 c3  -> mov eax,[ecx+0x14]; ret
0x00532540: 8b 41 18 c3  -> mov eax,[ecx+0x18]; ret
0x00532610: 8b 41 2c c3  -> mov eax,[ecx+0x2c]; ret
0x00532620: 8b 41 30 c3  -> mov eax,[ecx+0x30]; ret
0x00532630: 8b 41 34 c3  -> mov eax,[ecx+0x34]; ret
0x00532640: 8b 41 38 c3  -> mov eax,[ecx+0x38]; ret
0x00532650: 8b 41 3c c3  -> mov eax,[ecx+0x3c]; ret
0x00532660: 8b 41 40 c3  -> mov eax,[ecx+0x40]; ret
```

The gaps between tiny functions are `0xcc` alignment, for example `0x00532534-0x00532540`, `0x00532544-0x00532550`, `0x00532614-0x00532620`, and the analogous gaps after the other four-byte accessors.

Boundary bytes at the end of the target:

```text
0x0053272c: 04 00 cc cc
0x00532730: 55 8b ec 83
```

The `04 00` at `0x0053272c-0x0053272e` is the final `retn 4` immediate for `sub_5326D0`; only `0x0053272e-0x00532730` is two bytes of `0xcc` padding. `0x00532730` is the next function prologue.

### Row-Bucket Decompilation

MCP `decompile` and `disasm` confirm four row-bucket accessors with the same source pattern:

```text
sub_532550(this,row):
  Init bounds from m_minX - 2, m_minY - 2,
  m_minX + m_gridWidth + 2, m_minY + m_gridHeight + 2;
  return m_primaryRowLists[row - bounds.top];

sub_5325B0(this,row):
  same normal bounds;
  return m_secondaryRowLists[row - bounds.top];

sub_532670(this,row):
  same normal bounds;
  return m_tertiaryRowLists[row - bounds.top];

sub_5326D0(this,row):
  same left/top/right but bottom is m_minY + m_gridHeight + 10;
  return m_extendedRowLists[row - bounds.top];
```

The binary calls `sub_4B7C50` for bounds initialization. Project docs and existing formal ObjectList C++ use `InitRectBounds(RectBounds*, int, int, int, int)` for this helper. The row accessors do not bounds-check the requested row; they compute `row - bounds.top` and index the selected row-table field directly.

### Caller Fan-In

MCP `xrefs_to` returned only code references from MapPane, FpsPane, and adjacent raw MapPane paths:

| Callee | Count | Caller/callsite evidence |
| --- | ---: | --- |
| `0x00532530` | 2 | `0x509897` in `sub_5094B0`, `0x50c569` in raw/secondary hit-test path near `sub_50C550` |
| `0x00532540` | 1 | `0x50992a` in `sub_5094B0` |
| `0x00532550` | 2 | `0x509a3b` in `sub_5094B0`, `0x50e967` in `sub_50E850` |
| `0x005325b0` | 3 | `0x509d98`, `0x509f97` in `sub_5094B0`; `0x50e8c0` in `sub_50E850` |
| `0x00532610` | 3 | `0x4b697b` in `sub_4B68B0`; `0x50630f` in `sub_5062F0`; `0x50a315` in `sub_5094B0` |
| `0x00532620` | 1 | `0x50a3a2` in `sub_5094B0` |
| `0x00532630` | 1 | `0x50a441` in `sub_5094B0` |
| `0x00532640` | 1 | `0x50a28f` in `sub_5094B0` |
| `0x00532650` | 2 | `0x509678` in `sub_5094B0`; raw `0x50aa80` |
| `0x00532660` | 1 | `0x5045f1` in `sub_504530` MapPane cleanup/destructor body |
| `0x00532670` | 6 | `0x4b6954` in `sub_4B68B0`; `0x5097d7`/`0x509be4` in `sub_5094B0`; `0x50b2f7`/`0x50b8a7` in `sub_50B2B0`; `0x50c4ca` in `sub_50C470` |
| `0x005326d0` | 6 | `0x4b6965` in `sub_4B68B0`; raw `0x506248`; `0x509ad0`/`0x509c80`/`0x509e87` in `sub_5094B0`; raw `0x50c647` |

This fan-in supports ObjectList ownership. `sub_5094B0` is the main MapPane render/view path, `sub_50E850` is MapPane coordinate/effect dispatch, `sub_4B68B0` is FpsPane statistics sampling, `sub_5062F0` is a MapPane object-intersection/collision consumer, `sub_50B2B0` and `sub_50C470` are MapPane render/hit-test consumers, and `sub_504530` is MapPane cleanup. These are all callers of the map object index, not evidence for a separate `MapPaneSpatialIndex` allocation or source file.

`callees` returned no callees for the tiny direct-list accessors. The four row accessors call only `sub_4B7C50` and the compiler security-cookie check.

### Signature

`make_signature_for_range 0x00532530-0x0053272e` with operand wildcards returned `unique:true`. This supports the exact physical subset boundary and rejects splitting the final two bytes of `sub_5326D0` into padding.

## Ownership And Reclassification

Ranked conclusion:

1. Accepted: `[UID:00009Q] ObjectList` class owns and emits these methods through `[UID:0000M4] ObjectList.cpp`.
2. Accepted as source root only: `[UID:0000M4] ObjectList` remains the file/module route, not the direct owner for a class method group now that the class clears the strict gate.
3. Retain only as compatibility alias: `[UID:00007R] MapPaneSpatialIndex` should stay ignored, `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, with links to the renamed ObjectList accessor page.
4. Rejected: `MapPane` ownership. MapPane owns the render/effect/hit-test/cleanup callers and has `m_objectList` around `+0x424`, but these functions dereference the ObjectList receiver layout and return ObjectList fields.
5. Rejected: generic `List` ownership. `List` supplies container vslots and stored list objects; it does not own the tier-selection/layout policy.
6. Rejected: no-owner/no-code. All twelve starts are IDA-modeled functions with normal code refs and a class owner/emitter route.

The correct "folding" is not deleting UID `0001D2`. Keep the exact by-memory UID as the source-bearing child for this physical accessor subset, but change its source identity from `MapPaneSpatialIndex` to `ObjectListAccessorMethods`.

## Source-Facing Names

Recommended method names:

| Start | Formal method name | Field returned/indexed | Alias handling |
| --- | --- | --- | --- |
| `0x00532530` | `ObjectList::GetPrimaryCellList()` | `m_primaryCellList` / `+0x14` | `GetLayer0List` is a stale/search alias. |
| `0x00532540` | `ObjectList::GetSecondaryCellList()` | `m_secondaryCellList` / `+0x18` | `GetLayer1List` is a stale/search alias. |
| `0x00532550` | `ObjectList::GetPrimaryRowBucket(int row)` | `m_primaryRowLists` / `+0x1c` | Replaces `GetLayer0RowBucket`. |
| `0x005325b0` | `ObjectList::GetSecondaryRowBucket(int row)` | `m_secondaryRowLists` / `+0x20` | Replaces `GetLayer1RowBucket`. |
| `0x00532610` | `ObjectList::GetVisibleObjectList()` | `m_primaryGlobalList` / `+0x2c` | Keep this formal name because accepted FpsPane/MapPane docs already consume it; document `GetPrimaryGlobalList` as structural alias only. |
| `0x00532620` | `ObjectList::GetSecondaryGlobalList()` | `m_secondaryGlobalList` / `+0x30` | Structural placeholder name. |
| `0x00532630` | `ObjectList::GetAlternateGlobalList()` | `m_alternateGlobalList` / `+0x34` | Matches optional alternate tier docs. |
| `0x00532640` | `ObjectList::GetTertiaryGlobalList()` | `m_tertiaryGlobalList` / `+0x38` | B001/B010 structural name. |
| `0x00532650` | `ObjectList::GetQuaternaryGlobalList()` | `m_quaternaryGlobalList` / `+0x3c` | B001/B010 structural name. |
| `0x00532660` | `ObjectList::GetQuinaryGlobalList()` | `m_quinaryGlobalList` / `+0x40` | Reject `GetInternalList` as formal; keep as MapPane-cleanup alias. |
| `0x00532670` | `ObjectList::GetFrontRowBucket(int row)` | `m_tertiaryRowLists` / `+0x24` | Keep accepted dependent name used by FpsPane statistics and hit-test docs. |
| `0x005326d0` | `ObjectList::GetBackRowBucket(int row)` | `m_extendedRowLists` / `+0x28` | Keep accepted dependent name; bottom pad is `10`. |

This naming set deliberately mixes field-structural names and the two established caller-facing names (`GetVisibleObjectList`, `GetFrontRowBucket`, `GetBackRowBucket`). Forcing every method to pure structural names would break accepted dependent first-draft C++ and obscure current caller evidence. Forcing stale `Layer0/Layer1` and `GetInternalList` names would preserve generated alias vocabulary after the ownership question is already resolved.

## First-Draft C++ Recommendation

Formal C++ should be inserted into UID `0001D2` after supervisor validation. This is not illustrative prose; it is the proposed `RECONSTRUCTION_CPP CODE` body for the renamed/reclassified target.

```cpp
List *ObjectList::GetPrimaryCellList()
{
    return m_primaryCellList;
}

List *ObjectList::GetSecondaryCellList()
{
    return m_secondaryCellList;
}

List *ObjectList::GetPrimaryRowBucket(int row)
{
    RectBounds bounds;
    InitRectBounds(&bounds,
                   m_minX - 2,
                   m_minY - 2,
                   m_minX + m_gridWidth + 2,
                   m_minY + m_gridHeight + 2);
    return m_primaryRowLists[row - bounds.top];
}

List *ObjectList::GetSecondaryRowBucket(int row)
{
    RectBounds bounds;
    InitRectBounds(&bounds,
                   m_minX - 2,
                   m_minY - 2,
                   m_minX + m_gridWidth + 2,
                   m_minY + m_gridHeight + 2);
    return m_secondaryRowLists[row - bounds.top];
}

List *ObjectList::GetVisibleObjectList()
{
    return m_primaryGlobalList;
}

List *ObjectList::GetSecondaryGlobalList()
{
    return m_secondaryGlobalList;
}

List *ObjectList::GetAlternateGlobalList()
{
    return m_alternateGlobalList;
}

List *ObjectList::GetTertiaryGlobalList()
{
    return m_tertiaryGlobalList;
}

List *ObjectList::GetQuaternaryGlobalList()
{
    return m_quaternaryGlobalList;
}

List *ObjectList::GetQuinaryGlobalList()
{
    return m_quinaryGlobalList;
}

List *ObjectList::GetFrontRowBucket(int row)
{
    RectBounds bounds;
    InitRectBounds(&bounds,
                   m_minX - 2,
                   m_minY - 2,
                   m_minX + m_gridWidth + 2,
                   m_minY + m_gridHeight + 2);
    return m_tertiaryRowLists[row - bounds.top];
}

List *ObjectList::GetBackRowBucket(int row)
{
    RectBounds bounds;
    InitRectBounds(&bounds,
                   m_minX - 2,
                   m_minY - 2,
                   m_minX + m_gridWidth + 2,
                   m_minY + m_gridHeight + 10);
    return m_extendedRowLists[row - bounds.top];
}
```

Why code is safe now:

- All twelve functions are exact IDA-modeled starts with known exclusive ends.
- Direct accessors are one `List *` load and `ret`.
- Row accessors are exact repeated `InitRectBounds` plus row-table indexing; there is no hidden conditional branch or bounds check to model.
- Existing ObjectList exact children already use the same field names and `RectBounds`/`InitRectBounds` vocabulary.
- Parent `[UID:0001D3]` is a broad aggregate and should stay blank, so this C++ does not duplicate another emitting page.

Rejected no-code alternatives:

- "Blank because names are unresolved" is no longer acceptable. Names can be resolved to project-stable structural/caller-facing names with explicit alias caveats.
- "Blank because `[UID:0001D3]` covers the same range" is wrong. `[UID:0001D3]` covers a larger mixed accessor/sweep island and should remain non-emitting; UID `0001D2` is the exact source-bearing child for these twelve methods.
- "Blank because `MapPaneSpatialIndex` is ignored" confuses the class alias page with this memory range. The ignored alias page is non-emitting; the ObjectList accessor methods are source-authored and reachable.

## Score Rationale

Recommended `90/91`:

- Completion rises from `85` to `90` because this pass resolves alias identity, owner/emitter routing, method names, formal C++ readiness, half-open function ranges, live caller fan-in, and exact padding.
- Confidence rises from `88` to `91` because live MCP confirms the function inventory, bytes, row decompilation, xrefs, callees, unique range signature, and ObjectList field shape. It remains below final audit because original semantic object-type names for every tier are still inferred/structural, and `GetVisibleObjectList`/front/back vocabulary is caller-supported rather than symbol-proven.
- Direct owner/emitter changes from file `[UID:0000M4]` to class `[UID:00009Q]` because ObjectList class and file both clear the gate, and neighboring ObjectList method children now route through the class.

## Required Implementation After Supervisor Validation

Do not implement during report-only mode. After supervisor validation and callback, lease only the files being edited and release the lease immediately after validation.

Implementation checklist:

- [x] Lease target/support docs only when ready to edit immediately. Proof: B012 leased the immediate edit/validation set for the renamed target and directly related support docs before editing; no read-only reservation leases were taken for this callback.
- [x] Rename/reclassify the target page to `by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md`, preserving UID `0001D2`. Proof: old `by-memory/0x00532530-0x0053272e.MapPaneSpatialIndex.md` no longer exists; new path exists with UID `0001D2`.
- [x] Update target headers to `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, blank optional position. Proof: new target header now carries those exact values.
- [x] Replace the target title/status from `MapPaneSpatialIndex` compatibility alias to `ObjectList Accessor Methods`; retain `MapPaneSpatialIndex`, `GetLayer0*`, `GetLayer1*`, and `GetInternalList` only as historical/search aliases. Proof: target now describes `ObjectList Accessor Methods` as the source-bearing identity and keeps the old names only in alias/history notes.
- [x] Replace the target covered-ranges table with half-open function ranges and the formal names listed in this report. Proof: target range table now lists the twelve half-open ObjectList accessor ranges and formal source-facing names.
- [x] Add a 2026-06-27 B012 live MCP evidence section with session `398b87c1`, listener/process status, function inventory, lookup negative endpoints, exact `0x0053272e-0x00532730` padding, row decompilation summary, xref fan-in, callees, and unique signature result. Proof: target now includes a B012 evidence section with those MCP facts and negative endpoint/padding/caller details.
- [x] Insert the formal C++ block from this report into the target `RECONSTRUCTION_CPP CODE` block. Proof: target formal C++ block now contains the twelve `ObjectList::Get*` accessor implementations and no side-section/example-only C++ was used.
- [x] Update `[UID:0001D3] by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md` to link the renamed child, use the accepted accessor names, keep its aggregate C++ blank, and state that UID `0001D2` now owns the exact accessor C++. Proof: parent aggregate now names/linkes `ObjectListAccessorMethods`, states exact accessor C++ lives in UID `0001D2`, and keeps aggregate C++ blank.
- [x] Update `[UID:00009Q] by-class/ObjectList.md` method family/open-question text: remove "alias cleanup unresolved" for UID `0001D2`, add the accepted accessor names, preserve broader semantic tier-name caveats. Proof: ObjectList now lists the accepted accessor names and retains only broader semantic tier-name uncertainty.
- [x] Update `[UID:0000M4] by-file/ObjectList.md` proposed contents/migration notes: replace compatibility-alias row with the renamed exact ObjectList accessor-method child and keep `MapPaneSpatialIndex` as search alias only. Proof: ObjectList file doc now routes the exact child through ObjectList and documents `MapPaneSpatialIndex` as an alias/search term only.
- [x] Update `[UID:0001VG] by-type/by-struct/ObjectListLayout.md` naming notes to reflect the accepted structural accessor names and the retained caller-facing aliases for visible/front/back accessors. Proof: struct layout doc now links the renamed child and lists the accepted accessor/field vocabulary.
- [x] Update `[UID:00007R] by-class/MapPaneSpatialIndex.md` and `by-class/-ignored.md` so the ignored alias points to the renamed ObjectList accessor-method page and remains non-reconstructable/non-emitting. Proof: ignored class alias remains `RECONSTRUCTABLE:FALSE`, non-emitting, and links to `ObjectListAccessorMethods`; `by-class/-ignored.md` carries the same alias disposition.
- [x] Update any by-* support links that still target `0x00532530-0x0053272e.MapPaneSpatialIndex.md`, including MapPane/FpsPane/ObjectList support docs discovered by `rg`; do not edit generated reports, executed reports, or coverage reports by hand. Proof: updated `by-class/FpsPane.md`, `by-class/MapPane.md`, `by-file/MapPane.md`, `by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md`, and `by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md`; `rg` over editable `by-memory`, `by-class`, `by-file`, and `by-type` docs found no remaining `0x00532530-0x0053272e.MapPaneSpatialIndex` references.
- [x] Run scoped validator for every touched by-* doc from `source-3/project-documentation` with `--apply --queue-timeout 240 --wait-generated`. Proof:

| File | command_id | command_timestamp / generated timestamp | exit | ok | generated refresh |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md` | `000000004507` | `2026-06-27T20:59:35-04:00` | `0` | `1` | completed |
| `by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md` | `000000004510` | `2026-06-27T20:59:45-04:00` | `0` | `1` | completed |
| `by-class/ObjectList.md` | `000000004512` | `2026-06-27T21:00:05-04:00` | `0` | `1` | completed |
| `by-file/ObjectList.md` | `000000004515` | `2026-06-27T21:00:24-04:00` | `0` | `1` | completed |
| `by-type/by-struct/ObjectListLayout.md` | `000000004518` | `2026-06-27T21:00:42-04:00` | `0` | `1` | completed |
| `by-class/MapPaneSpatialIndex.md` | `000000004521` | `2026-06-27T21:01:01-04:00` | `0` | `1` | completed |
| `by-class/-ignored.md` | `000000004524` | `2026-06-27T21:01:22-04:00` | `0` | `1` | completed |
| `by-class/FpsPane.md` | `000000004527` | `2026-06-27T21:01:42-04:00` | `0` | `1` | completed |
| `by-class/MapPane.md` | `000000004530` | `2026-06-27T21:02:03-04:00` | `0` | `1` | completed |
| `by-file/MapPane.md` | `000000004533` | `2026-06-27T21:02:24-04:00` | `0` | `1` | completed |
| `by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md` | `000000004536` | `2026-06-27T21:02:45-04:00` | `0` | `1` | completed |
| `by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md` | `000000004540` | `2026-06-27T21:03:05-04:00` | `0` | `1` | completed |

- [x] Record validator command ids, timestamps, exit code `0`, `ok` counts, generated-refresh state, and queue status in this checklist after callback implementation. Proof: final queue poll `000000004558` at `2026-06-27T21:04:50-04:00` reported worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, and processing generated refresh jobs `0`. Scoped validator output also repeated existing unrelated `memory_coverage_metadata_missing_file: 129` and stale registry diagnostics for other missing files; no target-specific validation failure was reported.
- [x] Release all B012 leases immediately after edit/validator batch and record lease release proof. Proof: `python .\tools\leaser\leaser.py B012 unlease` returned `B012: No active leases`; the post-release `current_leases.md` had no B012 rows.
- [x] Do not edit `by-memory/-coverage-report.md`, generated reports, generated C++ files, project-level generated files, validator/tool state, or IDA DB. Coverage/tracker refresh is supervisor/validator-owned. Proof: no manual edits were made to those files, no IDA mutation/start/stop/restart actions were performed, and this report remains active for supervisor verification/execution.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0001D2-MapPaneSpatialIndex-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0001D2-MapPaneSpatialIndex-source-quality.md","timestamp":"2026-06-27T21:24:47","uid":"0001D2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
