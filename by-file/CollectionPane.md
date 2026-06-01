*** UID:0000IC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CollectionPane

## Status

- Confidence: strong for the main collection inventory pane; medium for final split versus `CollectionDialogPane.cpp`.
- Proposed module folder: `ui/panels/`
- Proposed source file: `ui/panels/CollectionPane.cpp`
- Companion file: [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Evidence basis: `simroot_v2` active sources, `.meta_wave3` records, and IDA MCP boundary/decompilation checks on 2026-05-24 and 2026-05-25.

## Hypothesis

`CollectionPane.cpp` should own the in-game collection list panel shown inside the general purpose panel. It loads collection metadata, renders the five-row collection summary list, manages its `ScrollCollectionPane` child, opens the detailed collection dialog, and sends the request packet when a collection group is not loaded yet.

The detail dialog and its private controls are likely a companion source file rather than standalone one-class files. See [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md).

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:00002X][CollectionPane](by-class/CollectionPane.md) | `0x0056e940-0x0056fd61`, destructor `0x00573370-0x005733d7` | `class_CollectionPane.cpp` | Main five-row collection summary panel, metadata loader, scroll child owner, hit testing, input, and collection-detail dispatch. |
| [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md) | `0x0056fd70-0x0056fe75`, destructor `0x00573310-0x00573365` | `class_CollectionPane2.cpp` | Lightweight alternate collection inventory frame renderer with mostly stub virtuals. |
| [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) | `0x00561db0-0x0056325b` | `class_ScrollCollectionPane.cpp` | Generic EPF-backed scrollbar child. This is a dependency, not final collection ownership. |
| [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) | [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) alias/view | generated as `g_pCollectionData`, `g_pPlayerData`, and `g_collectionProgressTable` | Player-data block view used for collection group records. |

## Boundary Notes

- IDA MCP confirms real functions from `0x0056e940` through `0x0056fe75`; the next function at `0x0056fe80` is `SelfLookPane2` and must not be merged into collection.
- IDA did not initially mark `0x0056fd70` as a function, but raw IDA bytes show valid `CollectionPane2` constructor instructions from `0x0056fd70-0x0056fd9f`.
- Active Wave3 output omits `0x0056f800`, `0x0056fc80`, `0x0056fda0`, `0x0056fdc0`, and `0x0056fe70`.
- `0x0056fc80` is the key open/request helper: it checks `g_pCollectionData + groupIndex * 0x2604 + 0x3ec8`, sends a four-byte request packet when the group is not populated, or constructs `CollectionDialogPane` when data is ready and no dialog singleton is active.
- 2026-05-25 IDA MCP recheck reconfirmed `0x0056fd70` is still not a modeled function, while `0x0056f800`, `0x0056fc80`, `0x0056fda0`, `0x0056fdc0`, and `0x0056fe70` are modeled functions with exact pages.

## Data Layout

The collection feature uses a view over the large player-data block:

- group record stride: `0x2604`;
- per-entry record stride: `0x4c`;
- group active/loaded flag at record `+0x3ec8`;
- group type/volume at record `+0x3ec9`;
- total entry count at record `+0x3eca`;
- collected entry count at record `+0x3ecb`;
- global collection group count at `+0x1340c8`.

See [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md).

## Migration Notes

Create the main file before attaching classes:

```powershell
python source-3\wave3.py create file CollectionPane.cpp --kind source --simpath ui/panels/CollectionPane.cpp --dry-run
python source-3\wave3.py attach class CollectionPane --to-file CollectionPane.cpp --dry-run
python source-3\wave3.py attach class CollectionPane2 --to-file CollectionPane.cpp --dry-run
```

Do not attach [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) here unless a later scroll-control pass proves it was collection-private. Current evidence favors a generic `ui/core/ScrollCollectionPane.cpp` or a merge into `ScrollBar.cpp`.

## Cross-References

- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md)
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md)
- [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md)
- [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md)
- [UID:00023Y][0x00573247-0x00573273.CollectionPaneAdjustorThunks](by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md)
- [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md)
- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- [UID:0001R8][collection-ui-resources](by-resource/collection-ui-resources.md)

## Changes

- Before: file-level destructor ranges were listed only as start addresses.
- Changed to: `CollectionPane` and `CollectionPane2` now point to the exact IDA destructor endpoints and the new adjustor/destructor memory docs.
- Evidence: 2026-05-28 IDA MCP reports `sub_573310` as `0x00573310-0x00573365`, `sub_573370` as `0x00573370-0x005733d7`, and four collection adjustor thunks at `0x00573247-0x00573273`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: main collection pane role, companion dialog split, class/global/data-layout ownership, exact boundary notes, omitted helper functions, migration plan, and resource/data cross-references are documented; confidence remains below maximum because final split versus `CollectionDialogPane.cpp` is still provisional.
