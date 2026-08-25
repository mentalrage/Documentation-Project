*** UID:0000RL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MetaMan *g_pMetaMan = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMetaMan

## ObjectStatusBlob read consumer

- Full parser UID0004LL reads `g_pMetaMan` to call `MetaMan::FindEntry` for table `RidableAnimals`, key text derived from nonzero riding appearance id, and columns 1-3. Converted results populate ObjectStatusBlob riding definition index, packed palette/render flags, and signed Y offset.
- Historical title-metadata naming for these outputs is superseded. This read does not change global ownership/emitter decisions, score, lifetime evidence, or MetaMan API; ObjectStatusBlob remains UID00009S/UID0000M6 source.


## Status

- Symbol kind: process-wide singleton pointer / global data
- Address: [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md)
- Final source type: `MetaMan* g_pMetaMan`.
- Proposed owner module: [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Confidence: strong for identity, owner, lifetime, saved lifecycle function labels, and major consumer families; medium-high for complete consumer method naming and final data-label cleanup.
- Rebuild handling: source-declared MetaMan singleton pointer. Current MCP bytes and PE file mapping support loader-zero-filled storage, so the source initializer is `0`. Older `0xffffffff` / `(MetaMan *)-1` evidence is stale historical support evidence, not current output proof.

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

Application startup constructs `MetaMan`; application shutdown/session cleanup reads the pointer during teardown. Live IDA MCP `xrefs_to 0x0069b410` on 2026-06-16 reconfirmed 24 xrefs across MetaMan lifecycle code and metadata consumers. C001 saved low-risk function labels for `MetaMan_Constructor`, `MetaMan_Destructor`, `ClearMetaManSingleton`, and `MetaMan_ScalarDeletingDestructor`; the data slot itself still decompiles as `unk_69B410` because the current MCP rename tool only accepts existing data names and rejected both `dword_69B410` and address-based data rename attempts.

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
- 2026-06-16 C001 IDA refresh: lifecycle function labels are now saved, but the storage label was not applied. The supported `rename` tool reported `Global 'dword_69B410' not found` and `Global '0x0069b410' not found`, while `entity_query names 0x0069b408-0x0069b420` showed no current explicit name at the slot. Do not force a data-label mutation through an unsupported path.

## Source Declaration

The sole storage definition remains `MetaMan *g_pMetaMan = 0;` in this CPP child. Formal H stays blank because the single declaration is now exposed by [UID:000088][MetaMan](by-class/MetaMan.md) through guarded `metadata/MetaMan.h`. Consumers include that owner header and keep using the manager API rather than declaring or owning duplicate storage.

The older `MetaMan *g_pMetaMan = (MetaMan *)-1;` declaration came from stale support evidence that treated [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md) as initialized to `ff ff ff ff`. The UID0000LC accepted report rechecked the current file-backed image on 2026-07-02: MCP `get_bytes` returned `00 00 00 00`, and PE mapping placed the slot in `.data` virtual storage beyond raw initialized data, which means the loader supplies zero-fill. The lifecycle and xref evidence remains valid; only the initializer source expression changes.

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

- 2026-08-16 Agent-B008 UID0003FA accepted callback: preserved the sole zero-initialized CPP definition and blank global H, and synchronized the one-definition route with UID000088's guarded `MetaMan.h` extern. No duplicate extern, local declaration, or storage definition was added; score and ownership remain `89/90`, UID0000LC.
- 2026-07-02 Agent-B007 UID0000LC implementation callback:
  - Changed to: `COMPLETION:89`, `CONFIDENCE:90`.
  - Summary/evidence: changed the formal source declaration from stale `MetaMan *g_pMetaMan = (MetaMan *)-1;` to `MetaMan *g_pMetaMan = 0;` after current MCP bytes and PE file mapping showed loader-zero-filled storage at `0x0069b410`. Preserved lifecycle writes/clears, 24-xref consumer evidence, owner route through [UID:0000LC][MetaMan](by-file/MetaMan.md), and historicalized the old `ff ff ff ff` / `(MetaMan *)-1` initializer as stale support evidence.
- 2026-06-19 Agent-B009 source-quality pass:
  - Score unchanged at `COMPLETION:88`, `CONFIDENCE:88`.
  - Summary/evidence: replaced stale blank-C++ gate wording with a first-draft source declaration `MetaMan *g_pMetaMan = (MetaMan *)-1;`, preserving the caveat that exact sentinel macro/name was not proven. The 2026-07-02 UID0000LC callback later historicalized that initializer as stale and corrected the formal declaration to `MetaMan *g_pMetaMan = 0;`.
- 2026-06-16 C001 Goal 2 global/IDA refresh:
  - Changed to: `COMPLETION:88` and `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed zero-filled nearby bytes, exactly 24 xrefs to `0x0069b410`, MetaMan lifecycle writes/clears, consumer families, and the adjacent `g_pWillBeChangedItemPane` boundary. Saved function labels now cover the constructor, destructor, tiny clear helper, and scalar deleting destructor. Confidence remains below final-audit because the explicit data label could not be applied through the supported rename tool, complete consumer method naming is still broad, and final C++ remains blank pending final declaration/header placement.

- 2026-06-06 metadata global evidence pass:
  - Changed to: `COMPLETION:86` and `CONFIDENCE:86`.
  - Summary/evidence: expanded the page with exact lifecycle sites, consumer-family ownership separation, adjacent global boundary caveat, and relationships to `g_metaAliasTableName` and `g_emptySimpleUString`. The global remained attached to [UID:0000LC][MetaMan](by-file/MetaMan.md) without C++ at that time; the 2026-06-19 source-quality pass later added the role-accurate first-draft declaration.

- Completion/confidence score update:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`, with role, lifetime, and consumer notes already present.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:80`, with final source type, lifecycle writes/clears, consumer evidence, and naming caveats documented.
  - Summary/evidence: exact storage is documented at [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md); MetaMan class/file pages document constructor, destructor, packet sync, lookup, and consumer relationships. Confidence is capped because every consumer method has not yet been named and the longer `g_pMetaManager` spelling remains only an alias lead.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LC`; the reconstruction block was left empty at that time and was later filled by the 2026-06-19 source-quality pass.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069b410` and decompilation of `0x005227d0`, `0x00522860`, `0x00524460`, and `0x005244e0` prove NexusTK-owned `MetaMan` singleton storage owned by [UID:0000LC][MetaMan](by-file/MetaMan.md). No source declaration was added at that time; the 2026-06-19 source-quality pass later filled the reconstruction block.
