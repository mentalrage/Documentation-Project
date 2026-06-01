*** UID:0000RL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMetaMan

## Status

- Symbol kind: process-wide singleton pointer / global data
- Address: [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md)
- Final source type: `MetaMan* g_pMetaMan`.
- Current generated declaration lead: `global-data:g_pMetaMan` in `source-3/simroot_v2/metadata/MetaMan.cpp`
- Proposed owner module: [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Confidence: strong for identity and owner; medium-high for generated-data memory coverage because the active source map leaves the global-data memory range unresolved.

## Role

`g_pMetaMan` points to the process-wide [UID:000088][MetaMan](by-class/MetaMan.md) instance. UI, resource, collection, and session/network code read this pointer before metadata lookup or synchronization calls.

The global should stay with `metadata/MetaMan.cpp`. Callers consume metadata state but do not own the singleton.

## Lifetime Evidence

- `MetaMan::MetaMan` writes `g_pMetaMan = this`.
- `MetaMan::~MetaMan`, `MetaMan::ScalarDeletingDestructor`, and the small helper at `0x00524460` clear the global.
- Application startup constructs `MetaMan`; application shutdown/session cleanup reads the pointer during teardown.
- Active `simroot_v2/metadata/MetaMan.cpp` shows constructor/destructor/scalar-deleting destructor writes and clears at `0x005227d0`, `0x00522860`, and `0x005244e0`.

## Consumer Pattern

IDA MCP xrefs on 2026-05-24 show reads from:

- [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md) population paths around `0x004ccca0`;
- image/resource helper code around `0x004d1fa0`;
- session/network handlers around `0x004f6d80` and `0x004f8d00`;
- [UID:00002X][CollectionPane](by-class/CollectionPane.md) initialization, paint, and group-data paths around `0x0056ea30`, `0x0056edc0`, and `0x0056f810`.

## Source-Map And Alias Caveats

- `simroot_v2/metadata/MetaMan.cpp.source_map.json` records `global-data:g_pMetaMan`, but the `global-data` entry has `missing_memory_range_line_count: 2`; use [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md) and IDA xrefs as the address authority.
- `simroot_v2/class_Application.cpp` contains an unresolved generated reference named `g_pMetaManager` in shutdown cleanup. Treat it as a consumer/alias lead only; do not rename the canonical `g_pMetaMan` global from that generated name without a live IDA address check.
- IDA MCP was unavailable during the 2026-05-30 score pass, so this update relies on prior recorded IDA xrefs, exact by-memory storage, and current simroot source-map state.

## Cross-References

- [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:000088][MetaMan](by-class/MetaMan.md)
- [UID:000089][MetaTable](by-class/MetaTable.md)
- [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md)

## Changes

- Completion/confidence score update:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`, with role, lifetime, and consumer notes already present.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:80`, with current simroot path, final source type, lifecycle writes/clears, consumer evidence, and source-map/alias caveats documented.
  - Summary/evidence: exact storage is documented at [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md); MetaMan class/file pages document constructor, destructor, packet sync, lookup, and consumer relationships; active `metadata/MetaMan.cpp` shows the writes/clears. Confidence is capped because generated global-data memory ranges for `g_pMetaMan` remain unresolved and `g_pMetaManager` appears as a separate unresolved Application-side generated alias.
