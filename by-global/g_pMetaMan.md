*** UID:0000RL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMetaMan

## Status

- Symbol kind: process-wide singleton pointer / global data
- Address: [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md)
- Final source type: `MetaMan* g_pMetaMan`.
- Proposed owner module: [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Confidence: strong for identity, owner, lifetime, and major consumer families; medium-high for complete consumer method naming.

## Role

`g_pMetaMan` points to the process-wide [UID:000088][MetaMan](by-class/MetaMan.md) instance. UI, resource, collection, and session/network code read this pointer before metadata lookup or synchronization calls.

The global should stay with `metadata/MetaMan.cpp`. Callers consume metadata state but do not own the singleton.

## Lifetime Evidence

| Site | Lifetime role |
| --- | --- |
| `0x005227d0-0x0052285c` | `MetaMan::MetaMan` constructs manager storage and writes `g_pMetaMan = this`. |
| `0x00522860-0x005228e2` | `MetaMan::~MetaMan` destroys the owned table structures and clears the global. |
| `0x00524460-0x0052446a` | Small singleton-clear helper used near teardown metadata. |
| `0x005244e0-0x00524580` | Scalar deleting destructor wrapper clears the global through the destructor path before optional delete. |

Application startup constructs `MetaMan`; application shutdown/session cleanup reads the pointer during teardown. Live IDA MCP `xrefs_to 0x0069b410` on 2026-06-05 reported 24 xrefs across MetaMan lifecycle code and metadata consumers.

## Consumer Pattern

IDA MCP xrefs on 2026-06-05 show reads from:

- [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md) population paths around `0x004ccca0`;
- image/resource helper code around `0x004d1fa0`;
- session/network handlers around `0x004f6d80` and `0x004f8d00`;
- [UID:00002X][CollectionPane](by-class/CollectionPane.md) initialization, paint, and group-data paths around `0x0056ea30`, `0x0056edc0`, and `0x0056f810`.

These users are evidence of subsystem consumers, not source ownership. `ItemHelpPane`, `CollectionPane`, resource helpers, and session handlers call into the metadata manager; they should not absorb `g_pMetaMan` or the table tree state.

## Related Metadata Globals

- [UID:0000Q2][g_metaAliasTableName](by-global/g_metaAliasTableName.md) is a MetaMan-owned static lookup key used by the `FindEntry` and `LoadStatValues` alias-first paths.
- [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md) is the shared empty return object used by failed metadata lookups; it is adjacent support state, not the singleton pointer.
- [UID:0000SS][g_pWillBeChangedItemPane](by-global/g_pWillBeChangedItemPane.md) starts immediately after this slot at `0x0069b414`, so the four-byte singleton range for `g_pMetaMan` should remain exact.

## Naming Caveat

- Keep the canonical documentation name `g_pMetaMan` for `0x0069b410`. Any longer `g_pMetaManager` spelling should remain an alias lead only unless a source-level declaration or direct IDA-backed address comparison proves it names the same slot.

## Cross-References

- [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:000088][MetaMan](by-class/MetaMan.md)
- [UID:000089][MetaTable](by-class/MetaTable.md)
- [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md)
- [UID:0000Q2][g_metaAliasTableName](by-global/g_metaAliasTableName.md)
- [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md)
- [UID:0000SS][g_pWillBeChangedItemPane](by-global/g_pWillBeChangedItemPane.md)

## Changes

- 2026-06-06 metadata global evidence pass:
  - Changed to: `COMPLETION:86` and `CONFIDENCE:86`.
  - Summary/evidence: expanded the page with exact lifecycle sites, consumer-family ownership separation, adjacent global boundary caveat, and relationships to `g_metaAliasTableName` and `g_emptySimpleUString`. The global remains attached to [UID:0000LC][MetaMan](by-file/MetaMan.md) without C++ because complete consumer method naming and final source declarations are still below the 95/95 reconstruction gate.

- Completion/confidence score update:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`, with role, lifetime, and consumer notes already present.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:80`, with final source type, lifecycle writes/clears, consumer evidence, and naming caveats documented.
  - Summary/evidence: exact storage is documented at [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md); MetaMan class/file pages document constructor, destructor, packet sync, lookup, and consumer relationships. Confidence is capped because every consumer method has not yet been named and the longer `g_pMetaManager` spelling remains only an alias lead.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LC`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069b410` and decompilation of `0x005227d0`, `0x00522860`, `0x00524460`, and `0x005244e0` prove NexusTK-owned `MetaMan` singleton storage owned by [UID:0000LC][MetaMan](by-file/MetaMan.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
