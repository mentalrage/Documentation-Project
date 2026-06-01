*** UID:0000Q2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_metaAliasTableName

## Status

- Symbol kind: global `SimpleUString` / metadata lookup key
- Storage: [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md)
- Proposed owner module: [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Confidence: strong for role, medium for final symbol name.

## Role

`g_metaAliasTableName` is the static `SimpleUString` key object consulted by [UID:000088][MetaMan](by-class/MetaMan.md) lookup helpers. `MetaMan::FindEntry` and `MetaMan::LoadStatValues` first try the alias-aware lookup path with this key, then fall back to the caller-provided table name when no alias applies.

This global should stay near `MetaMan` and `MetaTable` source, not with any one UI consumer. Item help and collection panes depend on alias-aware metadata lookup but do not own the alias table itself.

## Evidence

- `source-3/simroot_v2/class_MetaMan.cpp` emits this global data in the MetaMan file.
- IDA evidence identifies [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md) as the fixed static string object used by `FindEntry` and `LoadStatValues`.
- Startup constructs the object from `word_60DB20`, which currently appears empty in IDA. Treat the exact source literal/table-name spelling as provisional until the data is explained.
- Callers using the public lookup API include [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md), [UID:00002X][CollectionPane](by-class/CollectionPane.md), and resource helper code.

## Cross-References

- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:000088][MetaMan](by-class/MetaMan.md)
- [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md)
- [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/78`. Summary/evidence: the page documents the static `SimpleUString` storage, MetaMan lookup role, startup construction note, generated owner, API consumers, and refs; exact source literal/table-name spelling remains provisional.
