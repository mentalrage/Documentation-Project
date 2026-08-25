*** UID:0000Q2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SimpleUString g_metaAliasTableName;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_metaAliasTableName

## Status

- Symbol kind: global `SimpleUString` / metadata lookup key
- Storage: [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md)
- Proposed owner module: [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Confidence: strong for storage, owner, lookup role, and saved IDA labels; medium-high for final source spelling.
- Rebuild handling: source-declared static/global `SimpleUString` object owned by `metadata/MetaMan.cpp`. The observed initializer is empty/default; no source literal such as `"Alias"` is proven.

## Role

`g_metaAliasTableName` is the static `SimpleUString` key object consulted by [UID:000088][MetaMan](by-class/MetaMan.md) lookup helpers. `MetaMan::FindEntry` and `MetaMan::LoadStatValues` first try the alias-aware lookup path with this key, compare the result against the shared empty return string, then fall back to the caller-provided table name when no alias applies.

This global should stay near `MetaMan` and `MetaTable` source, not with any one UI consumer. Item help and collection panes depend on alias-aware metadata lookup but do not own the alias table itself.

## Storage And Lifetime

The exact static object is [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md), a 24-byte `SimpleUString`-style object:

| Address / range | Role |
| --- | --- |
| `0x0066de18-0x0066de28` | SSO pointer/inline buffer area, zeroed in the image. |
| `0x0066de28` | Current length field, initialized to `0`. |
| `0x0066de2c` | Capacity/state field, initialized to `7`. |
| `0x0066de30` | First byte of the following data item, excluded from this object. |

The startup wrapper now labeled `InitializeMetaAliasTableNameStatic` at `0x00419ff0` constructs the object with the shared empty wide-string initializer at `word_60DB20` and registers the static destructor now labeled `MetaAliasTableNameCleanup` at `0x0060c2a0`. The destructor path frees heap-backed storage only if the capacity guard requires it, then restores the empty SSO shape (`length = 0`, `capacity = 7`, first word cleared).

This means the current generated name is best understood as a role name: the object is the MetaMan alias lookup key, but the observed initializer is empty and does not prove a source literal such as `"Alias"` or a final original identifier spelling.

## Source Declaration

The first-draft global declaration is now emitted as `SimpleUString g_metaAliasTableName;`. This intentionally models the source-level object and lets compiler/runtime static-initialization glue produce the startup wrapper and destructor wrapper. Do not hand-port `InitializeMetaAliasTableNameStatic` or `MetaAliasTableNameCleanup` as ordinary source functions unless a later final-source pass proves they were explicitly authored.

The declaration uses the best-supported role name. Current bytes and the `word_60DB20` initializer show an empty/default `SimpleUString`; they do not prove a non-empty table-name literal or the exact original source identifier spelling.

## Lookup Users

| Site | Use of the global |
| --- | --- |
| `0x00523120-0x005231e5` | `MetaManFindEntry` probes the direct lookup helper with `&g_metaAliasTableName` first, then falls back to the caller table name if the result is the shared empty string. |
| `0x005231f0-0x00523325` | `MetaManLoadStatValues` uses the same alias-first pattern for multi-value row materialization. |
| `0x00523a70-0x00523b38` | The indexed lookup helper returns [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md) on missing alias rows, giving the callers their fallback signal. |
| `0x00523b40-0x00523c98` | The multi-value helper mirrors the same table/materialization/row-tree path for `LoadStatValues`. |

## Evidence

- IDA evidence identifies [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md) as the fixed static string object used by `FindEntry` and `LoadStatValues`.
- The memory page records exact xrefs to construction (`0x00419ff7`), lookup use (`0x00523047`, `0x00523137`, `0x00523247`), and destruction (`0x0060c2ab`, `0x0060c2f6`).
- 2026-06-16 C001 live IDA MCP recheck reconfirmed bytes `00` across the 20-byte SSO storage prefix plus capacity `07 00 00 00`, six base-object xrefs, length/capacity destructor refs, alias-first decompilation in `0x00523120` and `0x005231f0`, and startup-table-only reachability for the static initializer. C001 saved IDA labels `g_metaAliasTableName`, `InitializeMetaAliasTableNameStatic`, `MetaAliasTableNameCleanup`, `MetaManFindEntry`, and `MetaManLoadStatValues`.
- Startup constructs the object from `word_60DB20`, which currently behaves as a shared empty wide-string initializer. Treat the exact source literal/table-name spelling as provisional until stronger source-level evidence appears.
- Callers using the public lookup API include [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md), [UID:00002X][CollectionPane](by-class/CollectionPane.md), image/resource helper code, and metadata packet/session flow through [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md).

## Cross-References

- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:000088][MetaMan](by-class/MetaMan.md)
- [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md)
- [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md)
- [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md)

## Changes

- 2026-06-19 Agent-B009 source-quality pass:
  - Score unchanged at `COMPLETION:88`, `CONFIDENCE:89`.
  - Summary/evidence: replaced stale blank-C++ rationale with first-draft source declaration `SimpleUString g_metaAliasTableName;`, preserving the caveat that the object is currently initialized empty and that exact original literal/symbol spelling is not proven.
- 2026-06-16 C001 global-storage/IDA refresh:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:89`.
  - Summary/evidence: live IDA MCP reconfirmed the exact 24-byte `SimpleUString` bytes, constructor/destructor lifetime, alias-first lookup/fallback behavior, caller reachability, and saved source-quality labels for the global, static-lifetime wrappers, and two primary MetaMan API bodies. Owner/emitter remain [UID:0000LC][MetaMan](by-file/MetaMan.md). The reconstruction block was still blank at that time because the original alias key spelling and exact source symbol spelling were not final-source quality; the later 2026-06-19 pass added a role-name first draft with the caveat retained.
- 2026-06-06 cross-page evidence pass:
  - Changed to: `COMPLETION:86` and `CONFIDENCE:86`.
  - Summary/evidence: expanded this global page with exact object subranges, startup/destructor lifetime, alias-first lookup users, shared-empty-string fallback behavior, and the key caveat that the object is initialized empty so the generated name is a role name rather than proven original spelling. The supporting facts come from the IDA-backed memory and MetaMan pages linked above; live MCP retries during this pass timed out, so the score remains below final-audit quality.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/78`. Summary/evidence: the page documents the static `SimpleUString` storage, MetaMan lookup role, startup construction note, owner, API consumers, and refs; exact source literal/table-name spelling remains provisional.
- 2026-06-05: Marked reconstructable under [UID:0000LC][MetaMan](by-file/MetaMan.md). Evidence: live IDA MCP xrefs to `0x0066de18` include the static initializer at `0x00419ff0`, cleanup at `0x0060c2a0`, and metadata lookup helpers at `0x00523120`/`0x005231f0`; decompilation shows those helpers pass `&dword_66DE18` into the alias-aware lookup path.
