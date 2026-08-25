** TARGET-REPORT-UID:0003ZL **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003ZL **
# B003 Source-Quality Report: [UID:0003ZL] UnreferencedLegacyAssetRemapTriplets

Assignment id: `B003-goal2-unreferenced-legacy-asset-remap-leading-triplets-source-quality-0003ZL-20260618`

Primary target: [UID:0003ZL] `by-memory/0x0066daa4-0x0066dabc.UnreferencedLegacyAssetRemapTriplets.md`

Evidence snapshot: 2026-06-18. B003 did not edit by-* docs, generated reports/source, IDA DB, or `by-memory/-coverage-report.md`.

## Recommendation

Raise the target from `84/88` to `85/90`, keep `CANONICAL_OWNER:NONE`, keep `RECONSTRUCTABLE:TRUE`, keep blank `EMITTER_UIDS`, and keep formal C++ blank.

The current data classification is right: this is source-shaped initialized `.data`, not padding and not a compiler artifact. The current owner/emitter classification is also right: there is still no direct source route. The current weak point is naming: do not keep `Unknown0` / `Unknown1` as the best descriptive names. Replace those with a grouped positional alias:

```text
g_leadingLegacyAssetRemapTriplets[0].legacyMaxId
g_leadingLegacyAssetRemapTriplets[0].currentFirstId
g_leadingLegacyAssetRemapTriplets[0].currentLastId
g_leadingLegacyAssetRemapTriplets[1].legacyMaxId
g_leadingLegacyAssetRemapTriplets[1].currentFirstId
g_leadingLegacyAssetRemapTriplets[1].currentLastId
```

These are not proven original symbols. They are the strongest non-misleading descriptive aliases because they preserve the two triplet records, remove the stale `Unknown` tokens, and avoid falsely assigning a resource family or source file.

## Evidence Checked

- Read the updated B003 goal and notes, `Supervisor.md`, `by-structure.md`, `inference_research.md`, and the proposed source-tree guide.
- Read target [UID:0003ZL], parent [UID:00027I], predecessor padding [UID:0003ZK], live successors [UID:0003ZM] and [UID:0003ZN], executed tail target [UID:0003ZO], and successor [UID:00027J] / `g_emptySimpleUString` references.
- Checked support context for `MapPane`, `ItemObjImageLib`, `MapTileImageLib`, `ImageLib`, `g_useEpfAssets`, generated memory coverage, current project-level stats, and executed B-agent reports around the same data island.
- IDA MCP was attempted and was unavailable: `IDA_MCP_UNAVAILABLE: Unable to connect to the remote server`. This is not a documentation blocker because the existing docs already contain prior IDA-backed evidence, and B003 performed fresh raw PE checks.
- Ran a fresh local PE parser over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Verified integer conversions with `int_convert.py` for `0x0268`, `0x02a6`, `0x02de`, `0x00c3`, `0x00ca`, `0x00dc`, `0x18`, `0x0c`, `0x0066daa4`, and `0x0066dabc`.
- Ran `python tools/validator.py --mode file --file by-memory/0x0066daa4-0x0066dabc.UnreferencedLegacyAssetRemapTriplets.md` as a dry run. It returned `ok: 1`; no changes were applied. The dry run also reported two link-label normalization edits for [UID:0003ZM] and [UID:0003ZN] in the target page.
- Confirmed the required report file did not already exist before writing it with `Test-Path`, which returned `False`.

## Boundary, Bytes, And Values

The target remains exactly `0x0066daa4-0x0066dabc`, size `0x18` / decimal 24 bytes. It is six initialized 32-bit little-endian slots in `.data`; each value uses a low word and has a zero high word.

Fresh PE section mapping:

| Section | VA range | Raw range |
| --- | --- | --- |
| `.text` | `0x00401000-0x0060c4ac` | `0x00000400-0x0020ba00` |
| `.rdata` | `0x0060d000-0x0066c0be` | `0x0020ba00-0x0026ac00` |
| `.data` | `0x0066d000-0x0069ce24` | `0x0026ac00-0x00278400` |
| `.rsrc` | `0x0069d000-0x006b2c38` | `0x00278400-0x0028e200` |

Raw bytes for `0x0066daa0-0x0066dac0`:

```text
30 00 00 00 68 02 00 00 a6 02 00 00 de 02 00 00
c3 00 00 00 ca 00 00 00 dc 00 00 00 e2 74 00 00
```

Boundary interpretation:

| Range/address | Interpretation |
| --- | --- |
| `0x0066daa0-0x0066daa2` | predecessor `g_mapTilePixelHeight` word, value `0x0030` / 48 |
| `0x0066daa2-0x0066daa4` | [UID:0003ZK] two zero bytes of padding after the height word |
| `0x0066daa4-0x0066dabc` | this target, two leading no-xref legacy/current remap triplets |
| `0x0066dabc` | first dword of [UID:0003ZM], value `0x74e2`; successor starts exactly here |

Target slots:

| Address | Raw file offset | Dword | Decimal | Recommended descriptive alias |
| --- | ---: | ---: | ---: | --- |
| `0x0066daa4` | `0x0026b6a4` | `0x00000268` | 616 | `g_leadingLegacyAssetRemapTriplets[0].legacyMaxId` |
| `0x0066daa8` | `0x0026b6a8` | `0x000002a6` | 678 | `g_leadingLegacyAssetRemapTriplets[0].currentFirstId` |
| `0x0066daac` | `0x0026b6ac` | `0x000002de` | 734 | `g_leadingLegacyAssetRemapTriplets[0].currentLastId` |
| `0x0066dab0` | `0x0026b6b0` | `0x000000c3` | 195 | `g_leadingLegacyAssetRemapTriplets[1].legacyMaxId` |
| `0x0066dab4` | `0x0026b6b4` | `0x000000ca` | 202 | `g_leadingLegacyAssetRemapTriplets[1].currentFirstId` |
| `0x0066dab8` | `0x0026b6b8` | `0x000000dc` | 220 | `g_leadingLegacyAssetRemapTriplets[1].currentLastId` |

The first successor slot at `0x0066dabc` has raw offset `0x0026b6bc`, dword `0x000074e2`, decimal 29922. This confirms the half-open end and prevents absorbing the first live MapPane constant into [UID:0003ZL].

## Xref, Pointer, And Literal Findings

B003 rescanned VA, RVA, and raw-file-offset encodings for the target and nearby positive controls.

Negative target result:

- No VA/RVA/raw-offset hits were found for `0x0066daa2`, `0x0066daa4`, `0x0066daa8`, `0x0066daac`, `0x0066dab0`, `0x0066dab4`, or `0x0066dab8` in `.text`, `.rdata`, `.data`, or `.rsrc`.
- No direct address, pointer-table, or raw-pointer route was found for this target.

Positive controls from the successor live MapPane group:

- `0x0066dabc` has a VA operand hit in `.text` at VA `0x0050c1b3` / raw `0x0010b5b3`.
- `0x0066dabc` raw-offset encoding `0x0026b6bc` appears in `.rdata` at VA `0x0060d65c` / raw `0x0020c05c` and VA `0x0066a3b0` / raw `0x00268db0`.
- `0x0066dac0` has a VA operand hit at `0x0050c18c`.
- `0x0066dac4` has a VA operand hit at `0x0050c19a`.
- `0x0066dac8` has a VA operand hit at `0x0050c1f9`.
- `0x0066dacc` has a VA operand hit at `0x0050c1c4`.
- `0x0066dad0` has a VA operand hit at `0x0050c1d2` and a raw-offset encoding hit in `.rdata` at VA `0x00669cfc`.

The positive controls matter: the scanner sees the adjacent live group, so the absence of target hits is meaningful, not a scanner failure.

Literal/immediate checks:

| Value | 16-bit byte-pattern count in `.text` | 32-bit byte-pattern count in `.text` | Cluster result |
| --- | ---: | ---: | --- |
| `0x0268` | 68 | 39 | no cluster with `0x02a6` and `0x02de` |
| `0x02a6` | 6 | 4 | no cluster with `0x0268` and `0x02de` |
| `0x02de` | 9 | 4 | no cluster with `0x0268` and `0x02a6` |
| `0x00c3` | 83 | 48 | no cluster with `0x00ca` and `0x00dc` |
| `0x00ca` | 66 | 45 | no cluster with `0x00c3` and `0x00dc` |
| `0x00dc` | 140 | 106 | no cluster with `0x00c3` and `0x00ca` |

Cluster windows of 32, 64, 128, 256, and 512 bytes found zero 16-bit clusters and zero 32-bit clusters for:

- the first triplet: `0x0268`, `0x02a6`, `0x02de`;
- the second triplet: `0x00c3`, `0x00ca`, `0x00dc`;
- all six target values together.

The small-value hits for `0x00c3`, `0x00ca`, and `0x00dc` are too common to prove a source route on their own. The missing triplet clusters argue against an inlined remap helper using these values as immediate constants.

## Heuristic / Inference Reanalysis And Validation

### Data Shape

Accepted: two source-shaped legacy/current remap triplets.

Evidence:

- Six nonzero dword slots are four-byte-spaced and aligned after a two-byte padding boundary.
- Each triplet has the same grammar as the live groups: a legacy maximum id, then a current-format first id and last id.
- [UID:0003ZM] uses the same grammar twice for live MapPane map-tile remapping.
- [UID:0003ZN] uses the same grammar once for live ItemObjImageLib item-entry remapping.
- [UID:0003ZO] uses the same grammar once for a no-xref tail triplet.

Rejected alternatives:

- Padding: rejected because all six slots are nonzero structured dwords; only [UID:0003ZK] is padding.
- String/object prefix: rejected because the next string object [UID:00027J] starts at `0x0066daec`, not here, and no `SimpleUString` field spans back to `0x0066daa4`.
- Compiler artifact: rejected because this is initialized `.data` source storage shape, not code padding, unwind metadata, vtable data, or jump-table data.

### Names

Accepted descriptive aliases:

```text
g_leadingLegacyAssetRemapTriplets[0].legacyMaxId
g_leadingLegacyAssetRemapTriplets[0].currentFirstId
g_leadingLegacyAssetRemapTriplets[0].currentLastId
g_leadingLegacyAssetRemapTriplets[1].legacyMaxId
g_leadingLegacyAssetRemapTriplets[1].currentFirstId
g_leadingLegacyAssetRemapTriplets[1].currentLastId
```

Rationale:

- `legacyMaxId`, `currentFirstId`, and `currentLastId` match the proven live grammar in [UID:0003ZM] and [UID:0003ZN].
- `leading` is positional and verifiable: this child is the leading no-xref remap data before the live MapPane and ItemObjImageLib groups.
- Array-style aliases preserve the two record structure without inventing a resource family.
- The names are suitable for documentation and possible future draft C++ if an owner is discovered, while still making clear that original symbol spelling is not proven.

Rejected naming alternatives:

- Keep `Unknown0` / `Unknown1`: rejected because it preserves stale uncertainty even though the record grammar and positional relationship are now clear.
- `MapPane` names: rejected because no MapPane xrefs hit this child; only [UID:0003ZM] has MapPane reads.
- `MapTileImageLib` names: plausible resource-family direction, but rejected as current names because no MapTileImageLib reads or pointer route exist.
- `ItemObjImageLib` names: rejected because item-image reads start at [UID:0003ZN], not [UID:0003ZL].
- `ImageLib` names: rejected as too broad; ImageLib is a possible conceptual resource umbrella but no source-level route is present.
- `Tail` names: rejected because [UID:0003ZO] is the tail no-xref triplet. This child is the leading no-xref pair.
- `Primary` / `secondary` resource names: rejected because they imply semantic ordering or resource type that current evidence does not prove.

### Owner And Source Placement

Accepted: no owner and no emitter for [UID:0003ZL].

Ranked candidates:

1. No-owner child under [UID:00027I] `LegacyAssetRemapConstantsDataIsland`. Accepted. It exactly matches the evidence: source-shaped data, no xrefs, no pointer route, and no defensible source file.
2. A future shared `LegacyAssetRemapConstants.cpp` or `AssetRemapConstants.cpp`. Best forced owner if the project later adopts a synthetic orphan-data emission policy, but rejected now. No proposed-source-tree entry, debug string, initializer, pointer table, source map, or call cluster proves such a file in the original program.
3. [UID:0000L3] `MapPane`. Rejected. The live successor group [UID:0003ZM] is MapPane-owned, but adjacency alone does not transfer ownership backward across an unreferenced child. B003 found no target address operands in MapPane code.
4. [UID:0000L5] `MapTileImageLib`. Rejected. The resource category is plausible because the live MapPane group remaps tile-layer ids before drawing, but current MapTileImageLib docs do not show reads of `0x0066daa4-0x0066dabb`; the live tile remap occurs in MapPane helper logic before draw.
5. [UID:0000KH] `ItemObjImageLib`. Rejected. ItemObjImageLib owns [UID:0003ZN], where direct item-image/glyph reads start. It does not read this leading child.
6. [UID:0000K2] `ImageLib` or a broad render resource table. Rejected. Too broad and no direct address/reference evidence.
7. [UID:0000SW] `g_useEpfAssets`. Rejected as owner. The flag explains why live remap thresholds exist in old/new asset mode, but it is a mode selector/global, not the declaration owner for this unreferenced data.

Impact:

- Keep `CANONICAL_OWNER:NONE`.
- Keep blank `EMITTER_UIDS`.
- Do not route this child through MapPane, ItemObjImageLib, MapTileImageLib, ImageLib, or a synthetic shared file.

### Split Or Merge Decision

Keep [UID:0003ZL] as one 24-byte child, not two separate triplet children.

Evidence:

- The two triplets are contiguous and share one evidence state: no xrefs, no pointer route, no literal cluster, same remap grammar, same unresolved owner.
- Splitting into two 12-byte children would not isolate different owners, emitters, code behavior, or confidence levels.
- The current target already has exact half-open bounds and does not include padding or live referenced data.

Rejected alternatives:

- Split into `0x0066daa4-0x0066dab0` and `0x0066dab0-0x0066dabc`: rejected until one triplet gains a distinct owner/consumer/source role.
- Merge with [UID:0003ZO]: rejected because [UID:0003ZM] and [UID:0003ZN] live referenced children sit between the leading no-xref pair and the tail no-xref triplet. They are semantically related but not a contiguous exact memory item.
- Merge into [UID:00027I]: rejected because [UID:00027I] is a non-emitting split/index, and exact child rows are needed to prevent mixed-owner source pollution.

Future evidence that would change this decision:

- A direct address/pointer route to only one of the two triplets.
- A literal-immediate cluster or helper body that uses only one triplet.
- Source/debug metadata that names one resource category independently from the other.

### Relation To Adjacent Children

- [UID:0003ZK] remains exact padding. It gives the clean predecessor boundary after `g_mapTilePixelHeight`.
- [UID:0003ZM] remains live MapPane data. Its direct code operands at `0x0050c120` begin at `0x0066dabc`, after this target.
- [UID:0003ZN] remains live ItemObjImageLib data. Its direct item-image/glyph reads begin at `0x0066dad4`.
- [UID:0003ZO] remains a no-owner tail triplet. Its executed B003 report provides a useful policy comparison: raise no-xref source-shaped remap data to `85/90` when fresh no-xref/no-cluster proof and non-placeholder aliases are documented, but keep no owner/emitter/C++.
- [UID:00027J] starts at `0x0066daec`; it is a separate `g_emptySimpleUString` object and does not consume or own either no-xref remap child.

### Validation Or Contradiction Of Current Docs

Validated current docs:

- Exact target range and values are correct.
- Reconstructable data classification is correct.
- No-owner/non-emitting policy is correct.
- Rejection of padding, MapPane ownership, ItemObjImageLib ownership, MapTileImageLib ownership, and `g_useEpfAssets` ownership is directionally correct.
- Blank formal C++ is correct for current ownership evidence.

Contradicted or improved current docs:

- The `Unknown0` / `Unknown1` names are now stale. The report should replace them with `g_leadingLegacyAssetRemapTriplets[0/1]` field aliases.
- Current evidence text only cites B002 scans. Add B003 raw offsets, PE positive controls, and no-cluster literal results.
- Current score can clear the current `85/85` code-quality gate for documentation quality, but C++ remains blank because owner/emitter evidence is absent. Do not use stale `95/95` wording.

## Recommended Metadata And Score Changes

Recommended [UID:0003ZL] metadata:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Score rationale:

- `COMPLETION:85`: exact bytes, raw offsets, boundaries, decimals, no-address/no-pointer status, literal no-cluster status, relation to live/remap children, rejected owner alternatives, no split/merge decision, non-placeholder descriptive aliases, and no-code proof are now documented. Completion should not go higher because the actual original source owner and resource category remain unrecovered.
- `CONFIDENCE:90`: confidence in the data shape and no-owner/non-emitting decision is very strong after the B003 PE recheck and positive-control scan. Confidence should not go higher because a future source map, resource-table discovery, or direct consumer could still identify the real resource category.

No metadata changes are recommended for [UID:00027I], [UID:0003ZK], [UID:0003ZM], [UID:0003ZN], [UID:0003ZO], or [UID:00027J].

## First-Draft C++ Recommendation

Do not populate formal C++ for [UID:0003ZL] now.

Target-specific no-code proof:

- The target has no proven canonical owner.
- The target has blank emitters, and no source-bearing file/class/global target has a direct route to it.
- B003 found no VA/RVA/raw-pointer/direct-address hits for the target addresses.
- B003 found no 16-bit or 32-bit `.text` literal cluster containing either target triplet together.
- MapPane reads begin at `0x0066dabc`, after this target.
- ItemObjImageLib reads begin at `0x0066dad4`, after the MapPane group.
- MapTileImageLib, ImageLib, and `g_useEpfAssets` remain context candidates, not declaration owners.
- A formal C++ declaration emitted through any current source owner would be adjacency-based, not evidence-based.

If a future supervisor policy permits synthetic orphan-data declarations or a future evidence pass proves a shared resource owner, the best first-draft shape should be a writable/static record array, not six `Unknown` globals:

```cpp
struct LegacyAssetRemapTriplet
{
    unsigned int legacyMaxId;
    unsigned int currentFirstId;
    unsigned int currentLastId;
};

static LegacyAssetRemapTriplet g_leadingLegacyAssetRemapTriplets[2] =
{
    {0x0268, 0x02a6, 0x02de},
    {0x00c3, 0x00ca, 0x00dc},
};
```

Do not paste that draft into the target today. It is a future-shape recommendation only. The data lives in `.data`, so a future formal declaration should not force `const` unless separate compiler/linker evidence explains why writable initialized storage was produced.

## Exact Supervisor Changes Required

Apply these only in the target by-memory page and generated coverage row. B003 did not apply them.

### Target Metadata

Replace:

```text
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

with:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Leave owner/emitter/reconstructable/formal C++ metadata unchanged.

### Target Summary Replacement

Replace the current second summary paragraph:

```text
This child covers two nonzero four-byte-spaced low-word triplets immediately before the live MapPane map-tile remap constants. The values have the same legacy-max/current-band shape as the live MapPane and ItemObjImageLib remap groups, but B002's scan found no direct address, pointer-table, or meaningful immediate consumer.
```

with:

```text
This child covers two nonzero four-byte-spaced low-word triplets immediately before the live MapPane map-tile remap constants. The values have the same legacy-max/current-band shape as the live MapPane, ItemObjImageLib, and no-xref tail remap groups. B003's 2026-06-18 raw PE recheck confirmed the exact `.data` raw offsets, found no VA/RVA/raw-pointer/direct-address route for any target slot, and found no 16-bit or 32-bit `.text` literal cluster containing either triplet together. Keep the child reconstructable but no-owner/non-emitting until a direct source route is proven.
```

### Target Layout Table Replacement

Replace the target `## Layout` table with:

```markdown
| Address | Raw file offset | Value | Best descriptive treatment |
| --- | ---: | ---: | --- |
| `0x0066daa4` | `0x0026b6a4` | `0x0268` / 616 | `g_leadingLegacyAssetRemapTriplets[0].legacyMaxId` |
| `0x0066daa8` | `0x0026b6a8` | `0x02a6` / 678 | `g_leadingLegacyAssetRemapTriplets[0].currentFirstId` |
| `0x0066daac` | `0x0026b6ac` | `0x02de` / 734 | `g_leadingLegacyAssetRemapTriplets[0].currentLastId` |
| `0x0066dab0` | `0x0026b6b0` | `0x00c3` / 195 | `g_leadingLegacyAssetRemapTriplets[1].legacyMaxId` |
| `0x0066dab4` | `0x0026b6b4` | `0x00ca` / 202 | `g_leadingLegacyAssetRemapTriplets[1].currentFirstId` |
| `0x0066dab8` | `0x0026b6b8` | `0x00dc` / 220 | `g_leadingLegacyAssetRemapTriplets[1].currentLastId` |
```

Keep the existing decimal verification sentence, or replace it with:

```text
Decimals are verified with `int_convert.py`. B003 also verified the target size `0x18` / 24 bytes and the successor boundary at `0x0066dabc`.
```

### Target Evidence Replacement

Replace the current `## Evidence` bullets with:

```markdown
- B003 2026-06-18 raw PE recheck of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` maps the target into `.data` with raw offsets `0x0026b6a4`, `0x0026b6a8`, `0x0026b6ac`, `0x0026b6b0`, `0x0026b6b4`, and `0x0026b6b8`.
- Local bytes for `0x0066daa0-0x0066dac0` are `30 00 00 00 68 02 00 00 a6 02 00 00 de 02 00 00 c3 00 00 00 ca 00 00 00 dc 00 00 00 e2 74 00 00`: [UID:0001OK] `g_mapTilePixelHeight` ends at `0x0066daa2`, [UID:0003ZK] padding occupies `0x0066daa2-0x0066daa4`, this child occupies `0x0066daa4-0x0066dabc`, and [UID:0003ZM] begins at `0x0066dabc`.
- B003 found no VA/RVA/raw-offset encoding hits for `0x0066daa2`, `0x0066daa4`, `0x0066daa8`, `0x0066daac`, `0x0066dab0`, `0x0066dab4`, or `0x0066dab8` in `.text`, `.rdata`, `.data`, or `.rsrc`.
- Positive controls prove the scan is seeing the adjacent live group: `0x0066dabc` has a VA operand hit at `0x0050c1b3`, and successor slots `0x0066dac0/0x0066dac4/0x0066dac8/0x0066dacc/0x0066dad0` have the documented `0x0050c120` MapPane operand hits.
- Literal-pattern scanning found incidental individual hits for the small values, but no 16-bit or 32-bit `.text` cluster within 32, 64, 128, 256, or 512 bytes for `0x0268/0x02a6/0x02de`, for `0x00c3/0x00ca/0x00dc`, or for all six values together.
- The storage pattern is not padding: the values are nonzero, four-byte-spaced, and arranged as two `legacy max` plus `current remap first/last` triplets.
- The following child [UID:0003ZM][0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants](by-memory/0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md) uses the same triplet pattern with direct `0x0050c120` reads.
- The later child [UID:0003ZN][0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants](by-memory/0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md) uses the same triplet pattern with direct ItemObjImageLib/item-glyph reads.
- The tail child [UID:0003ZO][0x0066dae0-0x0066daec.UnreferencedLegacyAssetRemapTailTriplet](by-memory/0x0066dae0-0x0066daec.UnreferencedLegacyAssetRemapTailTriplet.md) has the same no-xref remap grammar and remains no-owner/non-emitting after B003's executed source-quality pass.
```

### Target Ownership And Naming Replacement

Replace the current `## Ownership And Naming` section with:

````markdown
## Ownership And Naming

Best current descriptive aliases are grouped by triplet rather than by unknown resource category:

```text
g_leadingLegacyAssetRemapTriplets[0].legacyMaxId
g_leadingLegacyAssetRemapTriplets[0].currentFirstId
g_leadingLegacyAssetRemapTriplets[0].currentLastId
g_leadingLegacyAssetRemapTriplets[1].legacyMaxId
g_leadingLegacyAssetRemapTriplets[1].currentFirstId
g_leadingLegacyAssetRemapTriplets[1].currentLastId
```

These are documentation aliases, not proven original symbols. They are stronger than `Unknown0` / `Unknown1` because the remap-triplet grammar and leading position are proven, while the specific resource family is not.

Rejected alternatives:

- Alignment padding: rejected because the values are nonzero structured triplets.
- MapPane ownership: rejected; adjacency to the live MapPane group is real, but B003 found no MapPane or all-section address route to this child.
- ItemObjImageLib ownership: rejected; the item readers start at `0x0066dad4`, not here.
- MapTileImageLib ownership: plausible as a resource-family hypothesis, but current `MapTileImageLib::DrawTile` does not read these addresses and `0x0050c120` handles the live map-tile remap before draw.
- ImageLib ownership: rejected as too broad without a direct data, table, or helper route.
- `g_useEpfAssets` ownership: rejected as a direct owner. The mode flag explains why remap thresholds exist, but it does not own this data.
- A new shared `LegacyAssetRemapConstants.cpp`: rejected for current formal output because no source-tree entry, initializer, pointer table, helper wrapper, or xref cluster proves that file in the original program.

Do not split the target into two 12-byte children now. Both triplets share the same no-xref/no-owner evidence state; splitting would add UID churn without isolating different owners, emitters, or behavior. Split only if future evidence routes one triplet separately.
````

### Target No-Code Proof Replacement

Replace the current `## No-Code Proof` section with:

```markdown
## No-Code Proof

Keep formal C++ blank.

- No function, vtable, data table, pointer route, or source-file route currently consumes this child.
- B003 found no VA/RVA/raw-pointer/direct-address hits for any target slot.
- B003 found no meaningful 16-bit or 32-bit `.text` literal cluster for either triplet.
- No owner/emitter is proven.
- Emitting these constants through MapPane, ItemObjImageLib, MapTileImageLib, ImageLib, or a synthetic shared file would assign data from adjacency or resource-family guesswork rather than evidence.

If a future source owner is proven, the best first-draft shape is a writable/static two-entry `LegacyAssetRemapTriplet` array using the aliases above. Do not emit that draft until owner/emitter evidence exists.
```

### Target Score Rationale Replacement

Replace the current `## Score Rationale` section with:

```markdown
## Score Rationale

- Completion `85`: exact bytes, raw offsets, decimal conversions, boundaries, no-address/no-pointer status, literal no-cluster status, relation to adjacent live/no-xref remap children, rejected owner alternatives, split/merge decision, descriptive aliases, and no-code proof are documented. Remaining work is original source-owner/resource-category recovery.
- Confidence `90`: the data shape and no-owner/non-emitting decision are very strong after B003's PE recheck and positive-control scan. Confidence remains below final-audit level because a future source map, resource-table discovery, or direct consumer could still identify the real resource category.
```

### Target Link Normalization

The validator dry run suggested two target-page link-label changes. Apply them if the supervisor is already editing the page:

```text
[MapPaneLegacyMapTileRemapConstants](by-memory/0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md)
```

to:

```text
[0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants](by-memory/0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md)
```

and:

```text
[ItemObjImageLibLegacyItemRemapConstants](by-memory/0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md)
```

to:

```text
[0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants](by-memory/0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md)
```

### Target Change Entry

Append to `## Changes`:

```markdown
- 2026-06-18 B003 source-quality pass: refreshed raw PE evidence for the leading no-xref triplets, confirmed exact `.data` raw offsets and `0x0066dabc` successor boundary, found no VA/RVA/raw-pointer/direct-address route for target slots, found no 16-bit or 32-bit `.text` literal cluster for either triplet, replaced stale `Unknown0` / `Unknown1` aliases with grouped `g_leadingLegacyAssetRemapTriplets[0/1]` field aliases, kept `CANONICAL_OWNER:NONE`, blank emitters, and blank formal C++, and recommended `85/90`.
```

### Support Docs

No non-target support-doc metadata changes are required.

Optional parent [UID:00027I] text refresh if the supervisor wants the parent to carry the improved aliases: in the `## Layout` row for `0x0066daa4-0x0066dabc`, replace:

```text
two no-xref legacy/current remap triplets. Decimal values are 616, 678, 734, 195, 202, and 220 (Verified with `int_convert.py`).
```

with:

```text
two no-xref leading legacy/current remap triplets, best documented as `g_leadingLegacyAssetRemapTriplets[0]` values `0x0268/0x02a6/0x02de` and `g_leadingLegacyAssetRemapTriplets[1]` values `0x00c3/0x00ca/0x00dc`. Decimal values are 616, 678, 734, 195, 202, and 220 (Verified with `int_convert.py`).
```

Do not change [UID:0003ZM], [UID:0003ZN], [UID:0003ZO], MapPane, ItemObjImageLib, MapTileImageLib, ImageLib, or `g_useEpfAssets` ownership based on this pass.

## Coverage Report Replacement Text

Replace the existing [UID:0003ZL] child row under [UID:00027I] in `by-memory/-coverage-report.md` with exactly:

```markdown
        - [UID:0003ZL][0x0066daa4-0x0066dabc.UnreferencedLegacyAssetRemapTriplets](by-memory/0x0066daa4-0x0066dabc.UnreferencedLegacyAssetRemapTriplets.md) 0x0066daa4-0x0066dabc | unreferenced leading legacy/current remap triplets | UnreferencedLegacyAssetRemapTriplets : reconstructable : 85% : very strong : Six source-shaped four-byte-spaced `.data` dword slots whose low words are `0x0268/0x02a6/0x02de` and `0x00c3/0x00ca/0x00dc`; B003 2026-06-18 PE recheck confirmed raw offsets `0x0026b6a4/0x0026b6a8/0x0026b6ac/0x0026b6b0/0x0026b6b4/0x0026b6b8`, confirmed predecessor padding [UID:0003ZK] ends at `0x0066daa4` and live MapPane child [UID:0003ZM] begins at `0x0066dabc`, found no VA/RVA/raw-pointer/direct-address route for target slots, and found no 16-bit or 32-bit `.text` literal cluster containing either triplet together; keep `CANONICAL_OWNER:NONE`, blank emitters, blank formal C++, and grouped aliases `g_leadingLegacyAssetRemapTriplets[0].legacyMaxId/currentFirstId/currentLastId` and `g_leadingLegacyAssetRemapTriplets[1].legacyMaxId/currentFirstId/currentLastId` rather than padding, MapPane, ItemObjImageLib, MapTileImageLib, ImageLib, `g_useEpfAssets`, synthetic shared-file ownership, or split into two children.
```

No other coverage rows require replacement from this pass.

## Validation Commands Run

> Executable block R001 was removed from this report and preserved verbatim in [0003ZL-UnreferencedLegacyAssetRemapTriplets-source-quality-removed.md](0003ZL-UnreferencedLegacyAssetRemapTriplets-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result before report creation: `False`.

> Executable block R002 was removed from this report and preserved verbatim in [0003ZL-UnreferencedLegacyAssetRemapTriplets-source-quality-removed.md](0003ZL-UnreferencedLegacyAssetRemapTriplets-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Dry-run result: exit code 0, `ok: 1`. The validator did not apply changes. It reported `stats_incremental_skip` because this was a dry run and suggested two `uid_link_update` label normalizations for [UID:0003ZM] and [UID:0003ZN].

## Remaining Blockers

The only remaining blocker is original source-route recovery for the two leading remap triplets. Current evidence is insufficient to assign a resource category or source file.

Evidence checked and rejected:

- Raw target VA/RVA/raw-address encodings: none found.
- Pointer-table route: none found.
- Literal cluster route: none found for either triplet or all six values.
- MapPane route: rejected; direct reads begin at [UID:0003ZM].
- ItemObjImageLib route: rejected; direct reads begin at [UID:0003ZN].
- MapTileImageLib route: plausible but unproven; no direct reads or helper route found.
- ImageLib route: too broad without direct evidence.
- `g_useEpfAssets` route: mode-context only, not owner.
- Synthetic shared resource constants file: plausible future policy, not proven original source.

Evidence that would justify raising the score above `85/90` or assigning an emitter:

- A direct code/data xref to any target slot.
- A literal-immediate cluster in a recovered helper that uses a complete target triplet.
- A source map, debug string, linker symbol, or resource-table structure that names the resource category for the leading triplets.
- A discovered shared asset-remap declaration block whose layout includes [UID:0003ZL] and [UID:0003ZO] without relying on adjacency alone.

Until one of those appears, the correct state is source-shaped, reconstructable, no-owner, non-emitting, blank formal C++, with non-placeholder descriptive aliases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003ZL","source_path":"executed-b-agent-research/B003/0003ZL-UnreferencedLegacyAssetRemapTriplets-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
