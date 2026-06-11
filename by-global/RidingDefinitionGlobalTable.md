*** UID:0000TJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RidingDefinitionGlobalTable

## Status

- Confidence: strong for address, helper type, riding owner, lifetime, and fallback use; medium for final original symbol name.
- Kind: module-scope global helper object.
- Backing storage: [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md), IDA `dword_69B430`.
- Owner: [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md), with helper implementation shared through [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md).
- Autogen parent: [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md), because the file page clears the parent gate and documents this table as riding-specific `RIDINGS.DNA` state.
- Generated aliases: `g_ridingDefinitionGroups` for the object, `g_ridingDefinitionBuckets` for its `+0x08` entry-pointer field.
- Reconstruction status: attach as source-declared riding definition table storage; keep final C++ blank until the shared helper type, field names, and generated alias split are final-source quality.

## Meaning

This global object is the process-wide default riding definition group table initialized by [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md). It uses the same 12-byte outer table helper documented under [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md).

IDA disassembly shows `g_ridingDefinitionBuckets` is not a separate global allocation. It is the `+0x08` pointer field of the 12-byte object at `0x0069b430`; current generated metadata splitting it as independent global-data should be treated as a projection artifact.

## Initialization And Lifetime

| Address | Behavior |
| --- | --- |
| `0x00419fd0` | Static initializer calls the `0x00528930` helper constructor on `offset dword_69B430` and registers `0x0060c290` with `atexit`. |
| `0x0060c290` | Static shutdown thunk calls the `0x00528950` helper destructor on `offset dword_69B430`. |
| `0x004dc4ce` | [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md) ensures the global table has `0x15` child groups. |
| `0x004dc4f0-0x004dc527` | The loader iterates the `+0x08` entry pointer field and seeds each default group with one bucket entry spanning `0..30000` and flag `0`. |
| `0x004dca20` | Helper returns `&dword_69B430` as an out-of-range fallback table. |

## Ownership Decision

Keep this storage with `RidingImageLib` resource-definition state, but keep the helper type itself shared with [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md). This is not a general project singleton and should not be moved into `Application`.

## Parent Attachment Guidance

Use [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) as the autogen parent for this table. The parent file records the `RIDINGS.DNA` parser, riding-definition layout, singleton/vtable evidence, resource inputs, destructor lifetime, and this exact `0x0069b430-0x0069b43c` global table. The shared table helper implementation remains documented through [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md), but that shared helper relationship does not make the concrete riding table storage a MonsterImageLib-owned global.

The strict parent gate is now satisfied for this global page: this page is `86/86`, and the direct file parent [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) is `85/85`. Keep the parent as `0000N6` unless later evidence proves the concrete storage was declared in a different riding-specific source unit.

## Cross-References

- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)
- [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md)
- [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md)
- [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents backing storage, owner, generated aliases, initialization/shutdown, loader uses, fallback helper, and ownership decision; final original symbol name remains provisional.

- 2026-05-31: Marked the global table reconstructable and linked exact parser evidence.
  - Before: `RECONSTRUCTABLE` was blank and loader references named the method without linking its exact memory page.
  - After: `RECONSTRUCTABLE:TRUE`, with loader references pointing to [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md).
  - Evidence: IDA MCP confirms the global object is initialized by static setup/destructor helpers and actively seeded/read by the constructor-only `RIDINGS.DNA` parser.
- 2026-06-07 A007 parent attachment:
  - Before: `AUTOGEN_PARENT_UID` was blank even though the page already named [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) as owner and the parent file records the table as riding-specific global state.
  - After: set `AUTOGEN_PARENT_UID:0000N6`, added explicit autogen-parent/reconstruction status bullets, and recorded parent attachment guidance.
  - Evidence: [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md), [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md), [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md), and [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md) form the source-root chain. No score or final C++ change was made because helper type/name finalization remains open.
- 2026-06-07 A002 Batch 042 confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:80`, and parent `0000N6`.
  - After: `COMPLETION:86`, `CONFIDENCE:86`, and parent `0000N6` retained after [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) was raised to `85/85`.
  - Evidence: the exact memory child records start/entry-pointer xrefs, static init/shutdown wrappers, `RIDINGS.DNA` allocation and seeding, repeated render/lookup fallback use, and adjacent boundaries; the file parent records the riding-specific parser/resource/singleton/vtable chain. Final symbol/type names remain provisional, so confidence stays below final-audit range.
