*** UID:0001TZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:64 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CollectionPlayerDataLayout

## Status

- Entity kind: inferred player-data substructure/view
- Owning global/view: [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- Storage doc: [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- Likely owner header: unresolved player-state header, consumed by [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- Confidence: strong for the group stride/header offsets and broad player-data pointer use; medium for exact per-entry field names and final canonical owner of the broader player-state block.

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

## Evidence

- IDA MCP `lookup_funcs` confirms the main collection-pane island functions inside `0x0056e940-0x0056fe75`, including `0x0056ea30`, `0x0056edc0`, `0x0056f810`, and `0x0056fc80`.
- IDA decompilation of `0x0056ea30` stores packet group count to `dword_67A748 + 1261768` (`+0x1340c8`), sets the collection metadata loaded flag at `+0x1340c9`, and loops over groups using `v16 += 9732` (`0x2604`) while writing group type at `groupBase + 0x3ec9` and collected count at `groupBase + 0x3ecb`.
- The same `0x0056ea30` path passes `dword_67A748 + group * 0x2604 + 0x3ec8` to `0x0056f810`, confirming `+0x3ec8` as the group-record base.
- IDA decompilation of `0x0056f810` walks `MetaMan` collection records and writes selected entry slots with `v4 + 76 * entryIndex`, confirming the `0x4c` entry stride. It copies three string-like values into relative dword/string fields at `+0x04`, `+0x1c`, and `+0x34` inside the selected slot.
- IDA decompilation of `0x0048c640` constructs the collection detail dialog and reads/writes the same group structure: it uses `9732 * groupIndex`, checks group loaded flag `+0x3ec8`, reads group type `+0x3ec9`, reads total entries `+0x3eca`, and uses `0x4c` entry stepping for dialog bit/state population.
- IDA decompilation of `0x0056edc0` draws the main collection list using group count at `+0x1340c8`, group type at `+0x3ec9`, total entries at `+0x3eca`, and collected entries at `+0x3ecb`, then formats collection progress.
- IDA decompilation of `0x0056f670` checks the collection input lock byte at `dword_67A748 + 1305373` (`+0x13eb1d`) before processing mouse/detail input.

## Open Questions

- Determine the broader canonical name for the `0x0067a748` player-data block.
- Split exact per-entry `std::wstring`/small-string offsets into named fields after one more focused decompilation pass through the `0x0056f810` MetaMan materialization path and the `0x0048c640` detail-dialog readers.
- Confirm whether byte `+0x1340c9` is best named `collectionMetadataLoaded`, `collectionGroupsLoaded`, or a broader player-data flag.

## Cross-References

- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md)
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)

## Changes

- Reclassified the page from unevaluated to reconstructable layout documentation with conservative scores. Evidence: IDA MCP lookup/decompile checks on 2026-05-31 verify the group count/load offsets, `0x2604` group stride, `+0x3ec8` group base, `+0x3ec9/+0x3eca/+0x3ecb` group header bytes, `0x4c` entry stride, and `+0x13eb1d` input lock; exact per-entry field names and final broader player-state owner remain unresolved.
