*** UID:0001TZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CollectionPlayerDataLayout

## Status

- Entity kind: inferred player-data substructure/view
- Owning global/view: [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- Storage doc: [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- Likely owner header/source: [UID:0000P1][UserPane](by-file/UserPane.md) / local-player state, consumed by [UID:0000IC][CollectionPane](by-file/CollectionPane.md) and [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md).
- Autogen parent: [UID:0000P1][UserPane](by-file/UserPane.md).
- Confidence: strong for the group stride/header offsets, broad player-data pointer use, and `UserPane` lifetime owner; medium for exact per-entry field names and final canonical C++ type names.

## Declaration Hypothesis

The collection feature stores its data inside the large player-data block at `0x0067a748`. It is not yet clear whether the original source declared a named collection struct or used fixed offsets inside a larger player/status record.

```cpp
struct CollectionEntryRecord {
    // Offset details are still partial; IDA confirms a 0x4c-byte stride.
    // Observed string-like fields are populated from MetaMan at relative
    // +0x04, +0x1c, and +0x34 inside the selected entry slot.
    // Dialog bit/state rendering also touches bytes inside these slots.
};

struct CollectionGroupRecord {
    // Base inside player data: groupIndex * 0x2604 + 0x3ec8.
    unsigned char loadedFlag;      // +0x3ec8
    unsigned char groupType;       // +0x3ec9
    unsigned char totalEntries;    // +0x3eca
    unsigned char collectedEntries;// +0x3ecb
    unsigned char unknown_04[0x30];// +0x3ecc..+0x3efb, still needs field split
    CollectionEntryRecord entries[/* up to 255 */];
};
```

Process-wide collection fields:

| Offset from `g_pCollectionData` | Meaning |
| --- | --- |
| `0x1340c8` | group count |
| `0x1340c9` | collection metadata loaded flag |
| `0x13eb1d` | input lock flag |
| `0x28de5a` from `g_pConfig` | alternate click/input mode, not in player data |

## Layout Map

| Player-data offset expression | Relative group offset | Meaning | Evidence |
| --- | ---: | --- | --- |
| `+0x1340c8` | n/a | collection group count | Written by `0x0056ea30`; consumed by draw/scroll paths. |
| `+0x1340c9` | n/a | collection metadata loaded flag | Set by `0x0056ea30` after collection metadata is parsed. |
| `+group * 0x2604 + 0x3ec8` | `+0x00` | group loaded/active flag | Checked by collection detail opener and dialog readers. |
| `+group * 0x2604 + 0x3ec9` | `+0x01` | group type / volume id | Written by the metadata loader and read by list/dialog rendering. |
| `+group * 0x2604 + 0x3eca` | `+0x02` | total entry count | Read by list and progress-bar rendering. |
| `+group * 0x2604 + 0x3ecb` | `+0x03` | collected entry count | Read by list and progress-bar rendering. |
| `+group * 0x2604 + 0x3efc + entry * 0x4c` | `+0x34 + entry * 0x4c` | entry record base | `0x0056f810` uses `76 * entryIndex`; global layout docs record the entry-region base at `+0x3efc`. |
| entry base `+0x04`, `+0x1c`, `+0x34` | entry-local | string-like collection fields | Populated from `MetaMan` records and later consumed by collection entry controls. |
| `+0x13eb1d` | n/a | collection input lock flag | Checked by `0x0056f670` before mouse/detail input. |

## Evidence

- IDA MCP `lookup_funcs` confirms the main collection-pane island functions inside `0x0056e940-0x0056fe75`, including `0x0056ea30`, `0x0056edc0`, `0x0056f810`, and `0x0056fc80`.
- IDA MCP lifetime evidence on [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) confirms `dword_67A748` is a `UserPane`/local-player state pointer: `UserPane` construction stores `this`, cleanup/destructor paths clear it, and 505 direct xrefs use the same storage through multiple typed views.
- IDA decompilation of `0x0056ea30` stores packet group count to `dword_67A748 + 1261768` (`+0x1340c8`), sets the collection metadata loaded flag at `+0x1340c9`, and loops over groups using `v16 += 9732` (`0x2604`) while writing group type at `groupBase + 0x3ec9` and collected count at `groupBase + 0x3ecb`.
- The same `0x0056ea30` path passes `dword_67A748 + group * 0x2604 + 0x3ec8` to `0x0056f810`, confirming `+0x3ec8` as the group-record base.
- IDA decompilation of `0x0056f810` walks `MetaMan` collection records and writes selected entry slots with `v4 + 76 * entryIndex`, confirming the `0x4c` entry stride. It copies three string-like values into relative dword/string fields at `+0x04`, `+0x1c`, and `+0x34` inside the selected slot.
- IDA decompilation of `0x0048c640` constructs the collection detail dialog and reads/writes the same group structure: it uses `9732 * groupIndex`, checks group loaded flag `+0x3ec8`, reads group type `+0x3ec9`, reads total entries `+0x3eca`, and uses `0x4c` entry stepping for dialog bit/state population.
- IDA decompilation of `0x0056edc0` draws the main collection list using group count at `+0x1340c8`, group type at `+0x3ec9`, total entries at `+0x3eca`, and collected entries at `+0x3ecb`, then formats collection progress.
- IDA decompilation of `0x0056f670` checks the collection input lock byte at `dword_67A748 + 1305373` (`+0x13eb1d`) before processing mouse/detail input.

## Consumer Matrix

| Consumer | Offsets used | Layout implication |
| --- | --- | --- |
| [UID:0000P1][UserPane](by-file/UserPane.md) / [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) | global pointer lifetime plus collection-group initialization/destruction | The collection view is nested inside the large `UserPane` player-state object rather than owned by collection UI code. |
| [UID:00002X][CollectionPane](by-class/CollectionPane.md) metadata loader | `+0x1340c8`, `+0x1340c9`, `group * 0x2604 + 0x3ec8`, `+0x3ec9`, `+0x3ecb` | Establishes the process-level group count/load flags, `0x2604` group stride, and group header bytes. |
| [UID:00002X][CollectionPane](by-class/CollectionPane.md) list renderer | `+0x1340c8`, group header bytes `+0x3ec9/+0x3eca/+0x3ecb` | Confirms the group header fields are not loader-only scratch values; they drive visible progress and row text. |
| [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md) / detail controls | group loaded/type/count bytes and `0x4c` entry stepping | Confirms the same records feed the detailed collection dialog, not just the summary pane. |
| [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md) | entry text/state fields near the `+0x3efc` entry region | Confirms the entry slots store display strings and state used by item-slot rendering, while exact entry-local names still need reconciliation. |
| Non-collection player-state consumers documented on [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) | `+0x3ec0`, `+0x13a6ec + slot * 0x148`, `+0x13ead4` | Confirms the final type should be a broader player/client-state layout with collection as one nested view. |

## Boundary And Naming Caveats

- The group entry region starts at `groupBase + 0x34` (`playerData + group * 0x2604 + 0x3efc`) in the current layout model. [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md) also records detail-render offsets around `+0x3ee4`, `+0x3efc`, `+0x3f14`, and `+0x3f2c`; keep these visible until one focused detail-control audit reconciles whether those are group-local metadata, first-entry fields, or adjusted entry-field accesses.
- The name `CollectionGroupRecord` is a feature-view name. Final source may expose it as nested fields inside a larger `UserPane` or local-player record rather than as a standalone public struct.
- The three string-like fields at entry-local `+0x04`, `+0x1c`, and `+0x34` are intentionally unnamed because existing docs prove their use but not source-quality semantic names.

## Reconstruction Notes

- Treat this as a `UserPane`/local-player-state nested layout view, not as a separate process-wide allocation. The collection-oriented names are useful for feature documentation but should not imply that collection code owns `dword_67A748`.
- Keep final C++ out of the autogen block until the broader `UserPane` state layout is named and the three entry-local string fields have source-quality names.
- The current declaration hypothesis intentionally leaves the `+0x04..+0x33` group-local gap unnamed because existing docs prove the entry base at `groupBase + 0x34`, but do not yet split the intervening bytes.

## Score Rationale

- Completion is raised to `78` because the page now records the `UserPane` ownership evidence, explicit autogen parent, group-relative offset map, entry-base correction, non-collection pointer caveat, cross-consumer matrix, and detail-control boundary caveat.
- Confidence is raised to `86` because the backing pointer lifetime is documented through IDA MCP evidence in the storage page and the collection offset claims are cross-supported by loader, renderer, detail-dialog, and entry-control readers. It remains below high-final confidence because per-entry field names and the broader local-player state type are not final.

## Open Questions

- Determine the broader canonical name for the `0x0067a748` player-data block.
- Split exact per-entry `std::wstring`/small-string offsets into named fields after one more focused decompilation pass through the `0x0056f810` MetaMan materialization path and the `0x0048c640` detail-dialog readers.
- Confirm whether byte `+0x1340c9` is best named `collectionMetadataLoaded`, `collectionGroupsLoaded`, or a broader player-data flag.

## Cross-References

- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md)
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)

## Changes

- Reclassified the page from unevaluated to reconstructable layout documentation with conservative scores. Evidence: IDA MCP lookup/decompile checks on 2026-05-31 verify the group count/load offsets, `0x2604` group stride, `+0x3ec8` group base, `+0x3ec9/+0x3eca/+0x3ecb` group header bytes, `0x4c` entry stride, and `+0x13eb1d` input lock; exact per-entry field names and final broader player-state owner remain unresolved.
- 2026-06-02: Raised scoring from `64/78` to `72/84` and attached autogen parent [UID:0000P1][UserPane](by-file/UserPane.md).
  - Before: the page kept the broader player-state owner unresolved and implied the entry array followed immediately after the four group header bytes.
  - After: the page uses the IDA-backed `UserPane` lifetime owner from [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md), maps the group-relative entry base at `+0x34`, and preserves unresolved per-entry names/final type names.
  - Evidence: existing IDA MCP notes for `0x0056ea30`, `0x0056f810`, `0x0048c640`, `0x0056edc0`, `0x0056f670`, and the `dword_67A748` lifetime/xref storage page.
- 2026-06-07:
  - Before: the page had strong offset evidence but did not summarize which consumers prove each part of the nested layout.
  - After: raised scoring to `78/86`, added a consumer matrix, and added an explicit detail-control boundary/naming caveat for the entry region.
  - Evidence: [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md), [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md), [UID:00002X][CollectionPane](by-class/CollectionPane.md), [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md), and [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md) jointly support the stronger layout-view documentation while preserving the unresolved final type/entry-field names.
