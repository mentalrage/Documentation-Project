** TARGET-REPORT-UID:0003ZO **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003ZO **
# B003 Source-Quality Report: [UID:0003ZO] UnreferencedLegacyAssetRemapTailTriplet

Assignment id: `B003-goal2-unreferenced-legacy-asset-remap-tail-triplet-source-quality-0003ZO-20260618`

Target: [UID:0003ZO] `by-memory/0x0066dae0-0x0066daec.UnreferencedLegacyAssetRemapTailTriplet.md`

Report-only status: no by-* documentation, generated reports/source, IDA database, or `by-memory/-coverage-report.md` files were edited. This report is the only file created for supervisor review/application.

## Current Recommendation

Keep [UID:0003ZO] as an exact standalone no-owner, non-emitting child. Raise it from `83/88` to `85/90` after B003's fresh PE recheck, source-family ranking, placeholder-name cleanup, and exact no-code proof.

Recommended metadata:

```text
COMPLETION:85
CONFIDENCE:90
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE: blank
```

Recommended documentation aliases:

```text
g_legacyAssetRemapTailMaxId       = 0x0093
g_currentAssetRemapTailFirstId    = 0x00a9
g_currentAssetRemapTailLastId     = 0x00aa
```

These aliases intentionally drop `UnknownTail`. The target still has no proven source owner, but the family and role are now strong enough to name the triplet as the tail of the legacy/current asset-remap constants island rather than as an unknown object. Do not emit these aliases into formal C++ unless a real owner/emitter route is later proven.

## Evidence Checked

- Active B003 rules: `Agent-B003/goal.md`, `Agent-B003/notes.md`, `Supervisor.md`, `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.
- Target page [UID:0003ZO] `0x0066dae0-0x0066daec.UnreferencedLegacyAssetRemapTailTriplet.md`.
- Parent/index [UID:00027I] `0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland.md`.
- Sibling children:
  - [UID:0003ZL] `0x0066daa4-0x0066dabc.UnreferencedLegacyAssetRemapTriplets.md`.
  - [UID:0003ZM] `0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md`.
  - [UID:0003ZN] `0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md`.
- Successor [UID:00027J] `0x0066daec-0x0066db04.g_emptySimpleUString.md`.
- Support docs for [UID:0000L3]/[UID:00007Q] `MapPane`, [UID:0000KH]/[UID:00006W] `ItemObjImageLib`, [UID:0000L5]/[UID:00007T] `MapTileImageLib`, [UID:0000K2]/[UID:00006E] `ImageLib`, [UID:0000SW] `g_useEpfAssets`, [UID:0001OH] exact `g_useEpfAssets` storage, and [UID:0001Z8] `.data`.
- Executed B002 report `Agent-B002/research/executed/00027I-MapPaneCoordinateClampConstants-source-quality.md`.
- Generated state:
  - `auto-generated/-ag-memory-coverage.md` shows [UID:0003ZO] as `no-owner`, no output file, no C++.
  - Generated `MapPane.cpp` and `ItemObjImageLib.cpp` contain the accepted emitted siblings [UID:0003ZM] and [UID:0003ZN], not [UID:0003ZO].
- Shared coverage row in `by-memory/-coverage-report.md` currently lists [UID:0003ZO] at `83% : strong`.
- IDA MCP check failed on 2026-06-18: `IDA_MCP_UNAVAILABLE: Unable to connect to the remote server`. I continued with current IDA-backed docs plus read-only PE checks.
- Read-only PE inspected: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - Image base: `0x00400000`.
  - `.text`: `0x00401000-0x0060c4ac`, raw `0x00000400-0x0020ba00`.
  - `.rdata`: `0x0060d000-0x0066c0be`, raw `0x0020ba00-0x0026ac00`.
  - `.data`: `0x0066d000-0x0069ce24`, raw `0x0026ac00-0x00278400`.
  - `.rsrc`: `0x0069d000-0x006b2c38`, raw `0x00278400-0x0028e200`.
- Decimal conversions were verified with `tools/int_convert.py`: `0x93 = 147`, `0xa9 = 169`, `0xaa = 170`, `0xc = 12`, `0x6 = 6`.

## Exact Boundary And Xref Findings

Fresh B003 byte dump for `0x0066daa2-0x0066daf0`:

```text
00 00
68 02 00 00  a6 02 00 00  de 02 00 00
c3 00 00 00  ca 00 00 00  dc 00 00 00
e2 74 00 00  92 79 00 00  c1 79 00 00
8e 36 00 00  0a 38 00 00  22 38 00 00
72 09 00 00  20 0a 00 00  56 0a 00 00
93 00 00 00  a9 00 00 00  aa 00 00 00
00 00 00 00
```

Target slots:

| VA | Raw offset | Section | Dword | Low word / decimal |
| --- | ---: | --- | ---: | ---: |
| `0x0066dae0` | `0x0026b6e0` | `.data` | `0x00000093` | `0x0093` / 147 |
| `0x0066dae4` | `0x0026b6e4` | `.data` | `0x000000a9` | `0x00a9` / 169 |
| `0x0066dae8` | `0x0026b6e8` | `.data` | `0x000000aa` | `0x00aa` / 170 |
| `0x0066daec` | `0x0026b6ec` | `.data` | `0x00000000` | start of [UID:00027J] `g_emptySimpleUString` |

Boundary conclusion:

- [UID:0003ZO] is exactly `0x0c` bytes, three four-byte slots.
- It is not padding: each slot is nonzero before the successor object.
- It is not part of [UID:00027J] `g_emptySimpleUString`; the first zero dword of the string object starts exactly at `0x0066daec`.
- It should not merge with [UID:0003ZN]; [UID:0003ZN] has direct ItemObjImageLib consumers and ends exactly before this no-xref tail.
- It should not merge with [UID:0003ZL] as a single memory child because live MapPane and ItemObjImageLib children intervene. It is semantically related to [UID:0003ZL] as another unreferenced remap triplet, but exact half-open memory rows must remain separate.

Address/pointer scan:

- No VA, RVA, or raw-file-offset dword encoding hits were found for `0x0066dae0`, `0x0066dae4`, or `0x0066dae8`.
- Neighboring live MapPane child hits were present, confirming the scan can see real direct references:
  - `0x0066dabc` through `0x0066dad0` have VA hits in `.text` around `0x0050c18c-0x0050c1f9`.
- Neighboring live ItemObjImageLib child hits were present:
  - `0x0066dad4`, `0x0066dad8`, and `0x0066dadc` have VA hits in `.text` at `0x004df00c-0x004df49e`.
- `0x0066daec` has many VA hits in `.text`, but those route to [UID:00027J] `g_emptySimpleUString`, not this tail.

Literal-immediate scan:

- Raw small-literal scans found many isolated `.text` occurrences of `0x0093`, `0x00a9`, and `0x00aa`, as expected for common small constants.
- A focused clustering pass found no `.text` window containing all three values together:
  - 32-bit pattern cluster counts for windows 32, 64, 128, and 256 bytes: all `0`.
  - 16-bit pattern cluster counts for windows 32, 64, 128, and 256 bytes: all `0`.
- I therefore reject the isolated literal hits as evidence for an inlined remap rule. A real inlined tail-remap check would be expected to use the max/lower/upper values in the same short control-flow neighborhood.

## Heuristic / Inference Reanalysis And Validation

### Data Shape

The best interpretation remains a source-shaped legacy/current asset remap triplet:

```text
legacy max/fallback threshold
current-mode remap first id
current-mode remap last id
```

Evidence:

- The layout is three four-byte-spaced dword slots with small low-word values.
- The live [UID:0003ZM] MapPane group and [UID:0003ZN] ItemObjImageLib group use the same three-slot pattern.
- [UID:0003ZN] immediately precedes this tail and is a proven item-image current-to-legacy remap triplet; [UID:0003ZO] is the next triplet-shaped tail before a hard object boundary.
- [UID:0003ZL] is another no-xref remap-triplet child with the same storage grammar.

Rejected alternatives:

- Padding: rejected because all three dwords are nonzero and pattern-matched to nearby live triplets.
- `g_emptySimpleUString` prefix fields: rejected because the string object begins at `0x0066daec`; the target's three dwords precede that boundary and do not share the string object's zero/sentinel layout.
- A raw table pointer or jump table: rejected because no raw VA/RVA/raw pointer route targets this child, and the values are threshold-like small ids rather than code/data pointers.

### Naming

Recommended documentation aliases:

```text
g_legacyAssetRemapTailMaxId
g_currentAssetRemapTailFirstId
g_currentAssetRemapTailLastId
```

Why this is stronger than the current `UnknownTail` names:

- `AssetRemap` is validated by the neighboring live remap groups and `g_useEpfAssets` branch context.
- `legacy` / `current` / `first` / `last` are validated by the live current-to-legacy remap behavior in [UID:0003ZM] and [UID:0003ZN].
- `Tail` is the only honest resource-family qualifier left after xref rejection; it records the source-shaped location without inventing a resource type.
- `Unknown` is stale as a name component. The exact resource category remains unknown, but the structural role is no longer unknown.

Rejected name directions:

- `ItemObjImageLibLegacyItem...`: adjacency after [UID:0003ZN] is real, but no ItemObjImageLib code reads this tail. Assigning item ownership would be adjacency-only.
- `MapPaneLegacyMapTile...`: the MapPane consumer reads [UID:0003ZM] only and has no direct route to the tail.
- `MapTileImageLib...`: plausible resource-family hypothesis, but current `MapTileImageLib::DrawTile` receives remapped ids from MapPane and does not read this address family.
- `ImageLib` / `ResourceLayoutTable` names: too broad. Shared EPF/EPD lookup explains asset mode infrastructure, but there is no direct lookup/table owner evidence for these three dwords.
- `Reserved...`: possible, but it claims source intent that the binary cannot prove. `Tail` is less speculative.
- `Unused...`: accurate for current binary references, but not source-facing; it should remain prose, not the alias.

### Owner And Source-Family Ranking

1. Accepted: exact no-owner legacy/current asset-remap tail child under [UID:00027I].
   - Positive evidence: exact source-shaped data; strong relationship to [UID:0003ZL], [UID:0003ZM], and [UID:0003ZN]; no direct source-file consumer.
   - Negative evidence: no VA/RVA/raw-pointer hits, no clustered literal-immediate route, no generated output, no support doc consumer.
   - Source handling: `CANONICAL_OWNER:NONE`, blank emitters, blank formal C++.

2. Rejected: route to [UID:0000KH] `ItemObjImageLib`.
   - Positive evidence: physical adjacency after the live ItemObjImageLib remap triplet.
   - Rejection: all direct ItemObjImageLib reads stop at `0x0066dadc`; no read of `0x0066dae0`, `0x0066dae4`, or `0x0066dae8` exists. Emission through `ItemObjImageLib.cpp` would be adjacency-based source pollution.

3. Rejected: route to [UID:0000L3] `MapPane`.
   - Positive evidence: same parent island contains a live MapPane remap group.
   - Rejection: MapPane's direct address references are to `0x0066dabc-0x0066dad0` only. The tail follows the ItemObjImageLib child, not the MapPane child.

4. Rejected: route to [UID:0000L5] `MapTileImageLib`.
   - Positive evidence: remap constants concern asset ids, and tile-image code is part of the legacy/current asset family.
   - Rejection: support docs place tile-id remapping in MapPane before `MapTileImageLib::DrawTile`; no `MapTileImageLib` address or literal route reaches this tail.

5. Rejected: route to [UID:0000K2] `ImageLib` or `ResourceLayoutTable`.
   - Positive evidence: `ImageLib` owns broad EPF/EPD resource lookup infrastructure.
   - Rejection: these dwords are not frame lookup records, strings, pointers, vtables, or layout structures, and no ImageLib/ResourceLayoutTable helper reads them.

6. Rejected as direct owner: [UID:0000SW] `g_useEpfAssets`.
   - Positive evidence: `g_useEpfAssets` gates the live map/item legacy remap branches and explains why current/legacy asset id thresholds exist.
   - Rejection: a mode byte is not a declaration owner for neighboring threshold constants. It is a cross-subsystem condition used by consumers.

7. Rejected for now: new shared `LegacyAssetRemapConstants.cpp` / `AssetRemapConstants.cpp`.
   - Positive evidence: all non-padding values in the island share one remap-triplet grammar.
   - Rejection: no proposed-source-tree file, initializer, writer, pointer table, xref cluster, or generated output proves such a source file. Creating it now would make the no-xref tail look more source-certain than it is.

### Validation Or Contradiction Of Current Docs

Validated:

- Exact range `0x0066dae0-0x0066daec`.
- Values `0x0093`, `0x00a9`, `0x00aa`.
- Successor boundary at `0x0066daec`.
- No-owner/non-emitting state.
- Reconstructable source-shaped data classification.
- Rejection of padding, `g_emptySimpleUString` ownership, broad MapPane ownership, and ItemObjImageLib ownership.

Needs update:

- Replace `g_legacyAssetRemapUnknownTailMaxId`, `g_currentAssetRemapUnknownTailFirstId`, and `g_currentAssetRemapUnknownTailLastId` with `g_legacyAssetRemapTailMaxId`, `g_currentAssetRemapTailFirstId`, and `g_currentAssetRemapTailLastId`.
- Replace the generic "literal-immediate scanning found no meaningful uses" wording with the stronger B003 result: many isolated small literal hits exist, but no 16-bit or 32-bit `.text` cluster contains all three values within 256 bytes, and no direct address/pointer route exists.
- Raise score from `83/88` to `85/90`.

## Recommended Metadata And Score Changes

Recommended target header:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion rises to `85` because this pass records fresh exact bytes, raw offsets, section boundaries, successor boundary, address/pointer scan results, literal-cluster rejection, owner ranking, source-family naming, and exact no-code proof.
- Confidence rises to `90` because the no-owner/no-emitter result is now backed by independent B003 PE scanning and support-doc comparison, not just inherited B002 text.
- Do not raise higher: original source symbol spelling and declaration owner remain unrecovered, and no current evidence proves whether the tail was retained from an obsolete resource family, a disabled build branch, or an unused shared constants block.

## First-Draft C++ Recommendation

Do not populate formal C++ for [UID:0003ZO].

Target-specific no-code proof:

- The child has no direct VA/RVA/raw-pointer/data-table route in the PE.
- The child has no meaningful inlined literal-immediate route; isolated `0x0093`, `0x00a9`, and `0x00aa` hits are common small constants, and no 16-bit or 32-bit `.text` window within 256 bytes contains all three values together.
- The child has no proven source-file owner. `MapPane.cpp` and `ItemObjImageLib.cpp` own adjacent live child ranges, but neither reads this target.
- Emitting through [UID:0000KH] would assign data from adjacency after the item remap group.
- Emitting through [UID:0000L3] would assign data from the old mixed parent page, which B002 already proved was source-polluted.
- Emitting through [UID:0000L5], [UID:0000K2], or a new shared file would create a source grouping that current xrefs and proposed-source-tree docs do not prove.
- A no-owner target with blank `EMITTER_UIDS` fails the source placement part of the code-entry policy even though its data shape is reconstructable.

If future evidence proves a real owner or an explicit orphan-data emission policy, this is the candidate declaration shape, but it should not be copied into [UID:0003ZO] formal C++ now:

```cpp
namespace
{
    static short g_legacyAssetRemapTailMaxId = 0x0093;
    static short g_currentAssetRemapTailFirstId = 0x00a9;
    static short g_currentAssetRemapTailLastId = 0x00aa;
}
```

Use writable `static short`, not `static const`, if later emitted, because the storage lives in writable `.data` and neighboring emitted children use the same writable file-static convention.

## Exact Supervisor Changes Required

### Target [UID:0003ZO]

Header replacement: use the metadata block in `Recommended Metadata And Score Changes`.

Replace the current `## Layout` table with:

```text
## Layout

| Address | Value | Best descriptive treatment |
| --- | ---: | --- |
| `0x0066dae0` | `0x0093` / 147 | `g_legacyAssetRemapTailMaxId` |
| `0x0066dae4` | `0x00a9` / 169 | `g_currentAssetRemapTailFirstId` |
| `0x0066dae8` | `0x00aa` / 170 | `g_currentAssetRemapTailLastId` |

Decimals are verified with `int_convert.py`.
```

Insert under `## Evidence`, after the existing B002 scan bullets:

```text
- 2026-06-18 B003 read-only PE recheck of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reconfirmed image base `0x00400000`, `.data` section `0x0066d000-0x0069ce24`, raw offsets `0x0026b6e0`, `0x0026b6e4`, and `0x0026b6e8`, and dwords `0x00000093`, `0x000000a9`, and `0x000000aa`.
- The same B003 scan found no VA/RVA/raw-file-offset dword encoding hits for `0x0066dae0`, `0x0066dae4`, or `0x0066dae8`; neighboring live children still produced direct `.text` hits, so the negative result is not a scanner failure.
- B003 literal checking found many isolated `.text` byte-pattern hits for `0x0093`, `0x00a9`, and `0x00aa`, but no 16-bit or 32-bit `.text` cluster containing all three values within 256 bytes. Treat isolated hits as unrelated small constants, not an inlined remap consumer.
```

Replace `## Ownership And Naming` with:

~~~markdown
## Ownership And Naming

Best current documentation aliases:

```text
g_legacyAssetRemapTailMaxId
g_currentAssetRemapTailFirstId
g_currentAssetRemapTailLastId
```

These replace the stale `UnknownTail` aliases. The exact resource family remains unrecovered, but the legacy/current asset-remap role is strongly supported by the neighboring live remap triplets. `Tail` records the only defensible qualifier: this is the terminal no-xref triplet in the remap constants island before `g_emptySimpleUString`.

Rejected alternatives:

- `g_emptySimpleUString` prefix: rejected because [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md) starts exactly at `0x0066daec`; this triplet precedes it and is not a string object field.
- Padding: rejected because the values are nonzero and structured.
- ItemObjImageLib ownership: plausible from adjacency after [UID:0003ZN], but rejected because no ItemObjImageLib code reads `0x0066dae0`, `0x0066dae4`, or `0x0066dae8`.
- MapPane ownership: rejected because MapPane reads [UID:0003ZM] only.
- MapTileImageLib, ImageLib, ResourceLayoutTable, or `g_useEpfAssets` ownership: rejected because these are broader asset-mode/resource systems with no direct address, pointer-table, literal-cluster, writer, or declaration-owner route to this child.
- New shared `LegacyAssetRemapConstants.cpp`: possible future recovery target, but rejected now because no source-tree entry, initializer, xref cluster, or generated output proves it.
~~~

Replace `## No-Code Proof` with:

```text
## No-Code Proof

Keep formal C++ blank.

- No function, vtable, data table, source-file route, or clustered literal route currently consumes this child.
- No owner/emitter is proven.
- Emitting this triplet through ItemObjImageLib, MapPane, MapTileImageLib, ImageLib, `g_useEpfAssets`, or a synthetic shared source file would assign data from adjacency or broad resource-family inference rather than evidence.
- The target remains reconstructable source-shaped data, but reconstruction must wait for a proven owner/emitter or a supervisor-approved orphan-data emission policy.
```

Replace `## Score Rationale` with:

```text
## Score Rationale

- Completion `85`: exact bytes, values, raw offsets, decimal conversions, no-xref/no-pointer status, successor boundary, no clustered literal-immediate route, remap-triplet interpretation, improved aliases, rejected owner/source alternatives, and no-code proof are documented. Remaining work is original source-owner recovery.
- Confidence `90`: the data shape, no-xref status, and boundary are very strong after independent B003 PE recheck. Confidence remains below final-audit quality because the exact original symbol names and declaration owner remain unknown.
```

No required changes to `MapPane`, `ItemObjImageLib`, `MapTileImageLib`, `ImageLib`, or `g_useEpfAssets` support docs. Current support docs already route the live children correctly and do not claim [UID:0003ZO] as a source-owned child. The target page and shared coverage row are the only required supervisor-owned documentation updates.

## Coverage Report Replacement Text

Replace the current [UID:0003ZO] row under the [UID:00027I] child block in `by-memory/-coverage-report.md` with:

```text
        - [UID:0003ZO][0x0066dae0-0x0066daec.UnreferencedLegacyAssetRemapTailTriplet](by-memory/0x0066dae0-0x0066daec.UnreferencedLegacyAssetRemapTailTriplet.md) 0x0066dae0-0x0066daec | unreferenced legacy/current remap triplet | UnreferencedLegacyAssetRemapTailTriplet : reconstructable : 85% : very strong : Three source-shaped four-byte-spaced `.data` dword slots whose low words are `0x0093`, `0x00a9`, and `0x00aa` before [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md); B003 2026-06-18 PE recheck confirmed raw offsets `0x0026b6e0/0x0026b6e4/0x0026b6e8`, found no VA/RVA/raw-pointer/direct-address route for `0x0066dae0/0x0066dae4/0x0066dae8`, and found no 16-bit or 32-bit `.text` literal cluster containing `0x0093/0x00a9/0x00aa` together, so keep `CANONICAL_OWNER:NONE`, blank emitters, blank formal C++, and aliases `g_legacyAssetRemapTailMaxId`, `g_currentAssetRemapTailFirstId`, and `g_currentAssetRemapTailLastId` rather than padding, string-prefix, ItemObjImageLib, MapPane, MapTileImageLib, ImageLib, or synthetic shared-file ownership.
```

No direct edit was made to `by-memory/-coverage-report.md`.

## Validation / State Checks

Commands or checks run:

> Executable block R001 was removed from this report and preserved verbatim in [0003ZO-UnreferencedLegacyAssetRemapTailTriplet-source-quality-removed.md](0003ZO-UnreferencedLegacyAssetRemapTailTriplet-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validator dry run result for the target page:

```text
ok: 1
ok 0003ZO by-memory/0x0066dae0-0x0066daec.UnreferencedLegacyAssetRemapTailTriplet.md UID header exists
stats_incremental_skip 0003ZO project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows
```

The validator dry run also reported the known unrelated `auto-generated/NexusTK/input/IMEPanes.cpp` sentinel conflict; this report did not modify it.

Suggested supervisor validation after applying target/coverage changes:

> Executable block R002 was removed from this report and preserved verbatim in [0003ZO-UnreferencedLegacyAssetRemapTailTriplet-source-quality-removed.md](0003ZO-UnreferencedLegacyAssetRemapTailTriplet-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Remaining Blockers

- Original source symbol spelling is not recovered. Impact: use the descriptive aliases above; do not claim final source spelling.
- Source declaration owner is not recovered. Evidence checked: target/sibling/parent docs, live child consumers, support docs, generated output, coverage rows, all-section VA/RVA/raw-pointer scans, and focused literal clustering. Impact: keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and blank formal C++.
- Exact resource category behind the tail triplet is not defensible. It could be an obsolete map/item/static/effect/UI resource remap family, but no current consumer distinguishes those candidates. Impact: use `AssetRemapTail` rather than a resource-specific name, and cap completion/confidence at `85/90`.
- Evidence that would change the decision: a direct address or pointer-table xref to `0x0066dae0/0x0066dae4/0x0066dae8`; a function that uses all three values in a remap pattern; older binary/source/debug information naming this triplet; or a supervisor-approved shared orphan-data emission policy for unreferenced source-shaped constants.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003ZO","source_path":"executed-b-agent-research/B003/0003ZO-UnreferencedLegacyAssetRemapTailTriplet-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
