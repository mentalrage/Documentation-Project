*** UID:00006T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KD | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemCatalog

## Status

- Confidence: strong for embedded fitting-room catalog lookup behavior.
- Proposed source module: [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md), or folded into [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Memory range: [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md)
- Evidence basis: live IDA MCP function, caller, call-site, and decompilation checks on 2026-06-04.

## Role

Small catalog lookup facade over fitting-room item-shop category storage. Consumers ask for the number of entries in a category and retrieve a category entry by index.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00422690-0x004226cc` | `GetItemCount` | Counts entries for a category. |
| `0x004226d0-0x0042273e` | `GetItemByIndex` | Retrieves one category entry by index. |

## Evidence

- 2026-06-04 IDA MCP confirms the method ranges as `0x00422690-0x004226cd` and `0x004226d0-0x0042273f`.
- Live call sites pass `this + 0x504` or `g_pFittingRoomDialog + 0x504` as the object, including `0x0041ce50`, `0x0041fc43`, and `0x00420d0b`.
- `GetItemCount` is called from fitting-room category rebuild, list scroll update, paint, key scroll, and selection validation paths.
- `GetItemByIndex` is called from fitting-room list scroll update, paint, input, and selection validation paths.
- Decompilation confirms both methods use category lookup storage at `this + 544` with sentinel at `this + 548`; the first returns vector count and the second returns a category entry pointer only when the index is valid.
- Local padding checks isolate the class methods from neighboring fitting-room item-state functions at `0x0042268f-0x00422690`, `0x004226cc-0x004226d0`, and `0x0042273f-0x00422740`.

## Reconstruction Notes

Keep this reconstructable and attached to [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md). Do not emit final C++ yet because field names, category-entry type spelling, and the final standalone-vs-embedded source split remain below the 95/95 gate.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | The class page records the two exact methods, fitting-room call-site ownership, category-tree/vector behavior, parent file attachment, reconstructable status, and final-source blockers. |
| Confidence | 88 | Live IDA confirms the method boundaries, caller set, `+0x504` embedded-object placement, local padding, and decompiled behavior. Confidence is capped only by original source-file split and final field/type names. |
| Reconstructable | true | This is source-authored fitting-room/cash-shop helper code; C++ remains blank until the final reconstruction threshold is met. |

## Cross-References

- [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md)
- [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md)
- [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md)

## Changes

- 2026-06-04: Raised from `72/84` to `82/88`, marked reconstructable, and attached to [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md).
  - Before: the class page identified the two-method facade but still relied on stale non-IDA provenance, lacked reconstructable/autogen metadata, and did not record the current call-site proof for `g_pFittingRoomDialog + 0x504`.
  - After: the page records live method boundaries, fitting-room caller set, embedded-object call sites, decompiled tree/vector behavior, score rationale, and final C++ blockers.
  - Evidence: 2026-06-04 IDA MCP `py_eval` confirmed `0x00422690-0x004226cd`, `0x004226d0-0x0042273f`, callers from `sub_41CDC0`, `sub_41EE10`, `sub_41F2B0`, `sub_41FBA0`, `sub_41FCD0`, and `sub_420D00`, `+0x504` object setup at live call sites, and category-tree decompilation using `this + 544` / `this + 548`.

- Completion/confidence score update: existed before as `0/0`; changed to `72/84`. Summary: fitting-room catalog lookup facade role, two confirmed methods, embedded-object placement, caller evidence, and source-module alternatives are documented with strong confidence; completion is capped because the page is intentionally small and category storage internals live in related fitting-room docs. Evidence: `ItemCatalogLookup`, `FittingRoomUiCore`, `FittingRoomListPane`, and `FittingRoomDialogItemState`.
