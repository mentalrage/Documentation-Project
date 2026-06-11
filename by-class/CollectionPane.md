*** UID:00002X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CollectionPane

## Status

- Likely source file: [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- Address range: [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md), plus destructor `0x00573370-0x005733d7` in [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md)
- Current recovered file: `source-3/simroot_v2/class_CollectionPane.cpp`
- Confidence: strong for class responsibility, medium for omitted helper ownership until Wave3 is corrected.

## Class Purpose

`CollectionPane` is the in-game collection summary panel. It loads `Collections` and `GroupNames` metadata, stores group records in the player-data collection block, renders five visible group rows with completion counts, owns a `ScrollCollectionPane` child, and dispatches clicks to the detailed collection dialog/request path.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CollectionPane` | `0x0056e940-0x0056e9e1` | Constructs `PanelPane`, installs three vtable views, creates the `ScrollCollectionPane` child, and initializes scrolling. |
| `Initialize` | `0x0056ea30-0x0056ec43` | Loads metadata tables, parses server collection group data, and populates group records. |
| `UpdateRenderRegion` | `0x0056ec50-0x0056ecd7` | Places the scroll child inside the pane bounds. |
| `UpdateScrollRange` | `0x0056ece0-0x0056edb0` | Synchronizes scrollbar range and packed current/total count state. |
| `OnPaint` | `0x0056edc0-0x0056f654` | Draws `CLTINV`/`CLTLIST` frames, group names, completion percentages, and fractions. |
| `0x0056f800` | `0x0056f800-0x0056f805` | [UID:0001HE][0x0056f800-0x0056f805.CollectionPaneFalseStub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md) returning false. |
| `HandleInput` | `0x0056f670-0x0056f7f3` | Handles click/wheel input, adjusts scroll position, and forwards input to the scroll child. |
| `LoadCollectionGroupData` | `0x0056f810-0x0056fa89` | Copies collection item metadata from `MetaMan` into group records. |
| `OnScrollPositionChanged` | `0x0056fa90-0x0056fac7` | Updates packed scroll state and invalidates. |
| `AttachToLayer` | `0x0056fad0-0x0056fb35` | Attaches pane and scroll child. |
| `DetachFromLayer` | `0x0056fb40-0x0056fb55` | Detaches scroll child and base pane. |
| `HitTestSlot` | `0x0056fbe0-0x0056fc72` | Maps mouse coordinates to one of five visible group slots. |
| `ShowCollectionGroup` | `0x0056fc80-0x0056fd61` | [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md). Sends a detail request if group data is absent, otherwise opens `CollectionDialogPane`. |
| `~CollectionPane` | `0x00573370-0x005733d7` | Deletes the scroll child, chains to `PanelPane`, and optionally frees storage; scalar wrapper is documented with neighboring destructor bodies in [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md). |

## Data And Globals

- Uses [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) for group/entry records.
- Uses [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md) for `Collections` and `GroupNames` lookups.
- Uses [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) indirectly through the omitted `ShowCollectionGroup` helper.
- Uses `g_pConfig + 0x28de5a` to select alternate click behavior.

## Open Questions

- Wave3 should restore or explicitly emit `0x0056f800` and `0x0056fc80`.
- Final source placement should keep `ScrollCollectionPane` as a dependency unless later evidence proves it was collection-private.

## Cross-References

- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md)
- [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md)
- [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md)
- [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md)
- [UID:00023Y][0x00573247-0x00573273.CollectionPaneAdjustorThunks](by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md)
- [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md)

## Changes

- Before: the destructor was listed as `0x00573370-0x005733d6`, leaving the exact IDA function end and adjustor thunks outside the class-level references.
- Changed to: the destructor endpoint is corrected to `0x005733d7`, and the collection adjustor/destructor memory pages are now cross-referenced.
- Evidence: 2026-05-28 IDA MCP reports `sub_573370` as `0x00573370-0x005733d7`, with `0x0057325d` and `0x00573268` as `-0xa0`/`-0xa4` adjustor thunks into it.
- What existed before: the page documented the collection summary panel, metadata loading, scroll behavior, draw path, omitted helper caveats, and destructor correction, but metadata was still `0/0`.
- What it was changed to: scores were set to `82/84`.
- Summary and evidence: constructor, initialization, scroll calculations, painting, hit-testing, detail request/opening, globals, and destructor island are covered; Wave3 omissions and final helper ownership/layout details remain open.
- 2026-06-05: Marked reconstructable and attached to [UID:0000IC][CollectionPane](by-file/CollectionPane.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000IC`.
  - Evidence: live IDA MCP confirms modeled method starts at `0x0056e940`, `0x0056ea30`, `0x0056edc0`, `0x0056f810`, `0x0056fc80`, and `0x00573370`, with a constructor caller from `GeneralPurposePanel` at `0x004b851f`; this class and the parent file both meet the 80% completion/confidence attachment gate.
