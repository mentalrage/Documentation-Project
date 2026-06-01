*** UID:0001Y0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Look Pane Vtable Family

## Status

- Disposition: vtable family inventory for reconstructable NexusTK look/status/profile panel code.
- Covered source owners: [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md), [UID:0000NZ][SpelledPane](by-file/SpelledPane.md), [UID:0000KM][LegendPane](by-file/LegendPane.md), and [UID:0000P0][UserLookPane](by-file/UserLookPane.md).
- Confidence: strong for table bases, RTTI presence, key slot targets, and store xrefs; medium for final original source-file split between standalone child panes and broader look-pane sources.
- Verification: IDA MCP `list_globals` checks on 2026-05-26; IDA MCP `py_eval`/`list_globals` recheck on 2026-05-31. Current `simroot_v2` metadata reports `vtable_count: 0` for every checked class in this family, but that generated-data issue is not used as authority.

## Self-Look And Shared Child Tables

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Extra view | Proposed file |
| --- | --- | --- | --- | --- | --- |
| `SelfLookPane` | `0x00624188` | `0x006241d8` | `0x00624208` | none | [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) |
| `SpelledPane` | `0x006242c8` | `0x00624340` | `0x00624370` | `0x0062437c` | [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) |
| `LegendPane` | `0x00624388` | `0x00624400` | `0x00624430` | none | [UID:0000KM][LegendPane](by-file/LegendPane.md) |
| `SelfLookPane2` | `0x006246f8` | `0x00624748` | `0x00624778` | none | [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) |

`SpelledPane` exposes an extra vtable view beyond the common primary/secondary/tertiary pane layout. Current behavioral docs tie one callback path to a frame-handler-style subobject at `0x0056c300`; keep the extra view as layout evidence until the final class declaration is reconstructed.

## User-Look Tables

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Proposed file |
| --- | --- | --- | --- | --- |
| `UserLookPane` | `0x0062eccc` | `0x0062ed1c` | `0x0062ed4c` | [UID:0000P0][UserLookPane](by-file/UserLookPane.md) |
| `MoreInfoPane` | `0x0062ed58` | `0x0062edd0` | `0x0062ee00` | [UID:0000P0][UserLookPane](by-file/UserLookPane.md) |
| `ProfilePane` | `0x0062ee0c` | `0x0062ee84` | `0x0062eeb4` | [UID:0000P0][UserLookPane](by-file/UserLookPane.md) |

## Layout Evidence

- `SelfLookPane` and `SelfLookPane2` are separate panel classes but belong to the same self-look/status source family.
- `SpelledPane` is constructed by `SelfLookPane`, `SelfLookPane2`, and a system-message/new-system-message path, so it should not be duplicated into only one self-look source.
- `LegendPane` is constructed by `SelfLookPane`, `SelfLookPane2`, and `UserLookPane`, so it remains a shared look/status child source candidate.
- `MoreInfoPane` and `ProfilePane` are tiny user-look child panes with their own vtables, but current caller evidence keeps them local to [UID:0000P0][UserLookPane](by-file/UserLookPane.md).
- The adjustor-thunk strip at `0x005732b5-0x00573302` is compiler-generated layout glue for `SelfLookPane2`, `SelfLookPane`, and `SpelledPane`; final source should model normal inheritance/destructors instead of reconstructing those stubs as handwritten methods.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for the checked look-pane classes even though IDA exposes complete vtable and RTTI records for each class listed above. This is tracked in [wave3 data issues](../../wave3_data_issues.md).

## Current IDA Recheck

2026-05-31 IDA MCP `py_eval` walked every listed vtable base using IDA names, dword reads, function containment, and data xrefs. The pass confirmed:

- `SelfLookPane`, `SpelledPane`, `LegendPane`, `SelfLookPane2`, `UserLookPane`, `MoreInfoPane`, and `ProfilePane` all have the documented decorated vtable names at their primary, secondary, and tertiary table bases;
- `SpelledPane` has the documented fourth/extra view table at `0x0062437c`, with slot `+0x04 -> 0x0056c300` and data refs from the `SpelledPane` constructor/raw setup path;
- primary tables point to scalar deleting destructor families or inherited pane destructors, while secondary and tertiary first slots point to the expected compiler adjustor thunks;
- key owner/action slots line up with documented executable ranges: `SelfLookPane` primary `+0x48 -> 0x00565890`, `SelfLookPane2` primary `+0x48 -> 0x005700e0`, `UserLookPane` primary `+0x48 -> 0x0059f610`, and the user-look child panes reuse common child-pane behavior;
- store xrefs match the constructor/destructor-reset paths already documented in the executable by-memory pages, including `SelfLookPane` `0x00565610/0x005657e0/0x00573730`, `SelfLookPane2` `0x0056fe80/0x00570030/0x00573640`, `SpelledPane` `0x0056bb20` plus raw setup stores, and `UserLookPane` `0x0059f260/0x0059f500/0x005a23f0`;
- by-memory aggregate coverage exists at [UID:00026E][0x00624188-0x00624c64.LookGroupCollectionReadOnlyData](by-memory/0x00624188-0x00624c64.LookGroupCollectionReadOnlyData.md) and [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md), but exact child pages are not yet split for every look-pane vtable island.

## Cross-References

- [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md)
- [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- [UID:0001HN][0x005732b5-0x00573302.LookPaneAdjustorThunks](by-memory/0x005732b5-0x00573302.LookPaneAdjustorThunks.md)
- [UID:00026E][0x00624188-0x00624c64.LookGroupCollectionReadOnlyData](by-memory/0x00624188-0x00624c64.LookGroupCollectionReadOnlyData.md)
- [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md)

## Changes

### 2026-05-31 - Scored IDA-verified look-pane vtable family

- Before: validator metadata marked this page `COMPLETION:0`, `CONFIDENCE:0`, and left `RECONSTRUCTABLE` blank despite a documented vtable inventory.
- Changed to: `COMPLETION:80`, `CONFIDENCE:87`, and `RECONSTRUCTABLE:TRUE`. No parent attachment or C++ reconstruction code was added because final source-file split and exact by-memory child splits for every vtable island are still incomplete.
- Evidence: IDA MCP `py_eval` and `list_globals` on 2026-05-31 confirmed decorated vtable names, slot targets, store xrefs, the `SpelledPane` extra view table, and the aggregate read-only-data ownership boundaries.
