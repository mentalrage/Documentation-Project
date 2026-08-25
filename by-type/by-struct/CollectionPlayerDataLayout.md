*** UID:0001TZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../../util/StringUtil.h"

struct CollectionEntryRecord
{
    SimpleUString shortName;
    SimpleUString entryName;
    SimpleUString description;
    unsigned char collectedFlag;
    unsigned char reserved[3];
};

struct CollectionGroupRecord
{
    unsigned char loadedFlag;
    unsigned char groupType;
    unsigned char totalEntries;
    unsigned char collectedEntries;
    CollectionEntryRecord entries[128];
};

struct CollectionPlayerDataView
{
    CollectionGroupRecord groups[128];
    signed char groupCount;
    unsigned char metadataLoaded;
};

typedef char CollectionEntryRecordSizeMustBe0x4C[
    sizeof(CollectionEntryRecord) == 0x4C ? 1 : -1];
typedef char CollectionGroupRecordSizeMustBe0x2604[
    sizeof(CollectionGroupRecord) == 0x2604 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## B001 UID0002QY Accepted Callback Synchronization - 2026-07-14

- Historical callback state was `91/92` with the declarations in CPP at position 5. The 2026-08-16 UID0003FA callback preserves that position and the exact declarations while moving them to H, adding complete `StringUtil.h` visibility and exact size guards.
- Exact `0x4c` and `0x2604` sizes, 128 groups, count/load tail, one-storage typed-access contract, callers, layout evidence, and unrelated history remain preserved.
- Position 5 makes CollectionPlayerDataView complete before the authoritative UserPane declaration at position 10 embeds it by value. This is a compile-order correction, not a type-body or source-owner change.

# CollectionPlayerDataLayout

## Status

- Entity kind: inferred collection substructure/view inside the active `UserPane` local-player object
- Owning global/view: [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- Storage doc: [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- Likely owner header/source: [UID:0000P1][UserPane](by-file/UserPane.md) / `UserPane *g_pUserPane` local-player state, consumed by [UID:0000IC][CollectionPane](by-file/CollectionPane.md) and [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md).
- Autogen parent: [UID:0000P1][UserPane](by-file/UserPane.md).
- Confidence: very strong for the exact entry/group/view sizes, 128-record boundary, `g_pUserPane` lifetime owner, typed accessor contract, and all producer/consumer offsets. Source-facing private field spellings remain inferred.

## Declaration Hypothesis

The collection feature stores its data inside the large `UserPane` local-player object reached through `g_pUserPane` at `0x0067a748`. [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) emits the one pointer `UserPane *g_pUserPane = 0`; `g_pCollectionData`, `g_pPlayerData`, and `g_collectionProgressTable` are historical feature-view aliases, not separate globals. The accepted source contract exposes this storage through mutable/const `UserPane::GetCollectionData()` accessors returning `CollectionPlayerDataView`. The names are source-facing feature names, not proof that the original headers exposed these structs publicly rather than as nested/private layout types.

Two independent boundary equalities close the enclosing view: `sizeof(CollectionEntryRecord) == 0x4c`, so `sizeof(CollectionGroupRecord) == 4 + 128 * 0x4c == 0x2604`; and `128 * 0x2604 == 0x130200`, so a view beginning at `g_pUserPane + 0x3ec8` ends its group array at `+0x1340c8`, exactly where `groupCount` is observed, followed by `metadataLoaded` at `+0x1340c9`.

```cpp
struct CollectionEntryRecord {
    // Entry base: groupBase + 0x04 + entryIndex * 0x4c.
    SimpleUString column2Text;     // +0x00, MetaMan Collections column 2
    SimpleUString lookupName;      // +0x18, row name/key copied from MetaMan
    SimpleUString column3Text;     // +0x30, MetaMan Collections column 3
    unsigned char stateFlag;       // +0x48, dialog packet bit / collected state
    unsigned char unknown_49[3];   // +0x49..+0x4b
};

struct CollectionGroupRecord {
    // Base inside g_pUserPane local-player state:
    // groupIndex * 0x2604 + 0x3ec8.
    unsigned char loadedFlag;      // +0x3ec8
    unsigned char groupType;       // +0x3ec9
    unsigned char totalEntries;    // +0x3eca
    unsigned char collectedEntries;// +0x3ecb
    CollectionEntryRecord entries[/* variable count */]; // +0x04
};
```

The code block above is preserved as a historical decompiler-offset sketch. Its `entries[/* variable count */]` notation is superseded by the managed formal declaration, which proves exactly 128 entries per group and 128 groups per enclosing view.

Collection view fields inside `g_pUserPane`:

| Offset from `g_pUserPane` | Meaning |
| --- | --- |
| `0x1340c8` | group count |
| `0x1340c9` | collection metadata loaded flag |
| `0x13eb1d` | local input lock byte; collection input-lock feature-view alias |
| `0x28de5a` from `g_pConfig` | alternate click/input mode, not in player data |

## Layout Map

| Player-data offset expression | Relative group offset | Meaning | Evidence |
| --- | ---: | --- | --- |
| `+0x1340c8` | n/a | collection group count | Written by `0x0056ea30`; consumed by draw/scroll paths. |
| `+0x1340c9` | n/a | collection metadata loaded flag | Set by `0x0056ea30` after collection metadata is parsed. |
| `+group * 0x2604 + 0x3ec8` | `+0x00` | group loaded/active flag | Checked by collection detail opener and dialog readers. |
| `+group * 0x2604 + 0x3ec9` | `+0x01` | group type / volume id | Written by the metadata loader and read by list/dialog rendering. |
| `+group * 0x2604 + 0x3eca` | `+0x02` | total entry count | Read by list and progress-bar rendering. |
| `+group * 0x2604 + 0x3ecb` | `+0x03` | collected entry count | Read by list and progress-bar rendering. |
| `+group * 0x2604 + 0x3ecc + entry * 0x4c` | `+0x04 + entry * 0x4c` | logical entry record base | `0x0056f810` uses the working anchor `groupBase + 76 * entryIndex`, then stores the first entry string at anchor `+0x04`; `76 == 0x4c` (Verified with int_convert.py). |
| entry record `+0x00` | entry-local | `SimpleUString` metadata column-2 text | `0x0056f810` stores `MetaMan` `Collections` column `2` here; `0x0048d4a0` renders it after measuring its UTF-16 length. |
| entry record `+0x18` | entry-local | `SimpleUString` lookup/name text | `0x0056f810` copies the row name/key here, uses it as the `Collections` lookup key for columns `2` and `3`, and `0x0048d4a0` renders it first in the collected-entry branch. |
| entry record `+0x30` | entry-local | `SimpleUString` metadata column-3 text | `0x0056f810` stores `MetaMan` `Collections` column `3` here; `0x0048d4a0` renders it as the lower description/body text. |
| entry record `+0x48` | entry-local | collected/unlocked state byte from the detail-dialog packet bitset | `0x0048c640` writes packet bits to `groupBase + 0x4c + entry * 0x4c`; `0x0048d4a0` checks the same byte before drawing the collected-entry detail branch. |
| `+0x13eb1d` | n/a | local input lock byte; collection input-lock feature-view alias | Checked by `0x0056f670` before mouse/detail input; Chatting UI also uses this UserPane/local input-lock view. |

## Evidence

- IDA MCP `lookup_funcs` confirms the main collection-pane island functions inside `0x0056e940-0x0056fe75`, including `0x0056ea30`, `0x0056edc0`, `0x0056f810`, and `0x0056fc80`.
- IDA MCP lifetime evidence on [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) confirms `dword_67A748` is the `UserPane *g_pUserPane` singleton: `UserPane` construction stores `this`, cleanup/destructor/clear paths clear it, the raw PE pass found 505 direct operand xrefs, and all collection/player/spell/chat/item/fitting/heartbeat references are typed views of the same object.
- IDA decompilation of `0x0056ea30` stores packet group count to `g_pUserPane + 1261768` (`+0x1340c8`, Verified with int_convert.py), sets the collection metadata loaded flag at `+0x1340c9`, and loops over groups using `v15 += 9732` (`0x2604`, Verified with int_convert.py) while writing group type at `groupBase + 0x3ec9` and collected count at `groupBase + 0x3ecb`.
- The same `0x0056ea30` path passes `g_pUserPane + group * 0x2604 + 0x3ec8` to `0x0056f810`, confirming `+0x3ec8` as the group-record base.
- IDA disassembly/decompilation of `0x0056f810` walks `MetaMan` collection records and writes selected entries through a working anchor `groupBase + 76 * entryIndex` (`76 == 0x4c`, Verified with int_convert.py), confirming the logical entry record starts at `groupBase + 0x04 + entryIndex * 0x4c` rather than at `groupBase + 0x34`. It copies the row name/key to record `+0x18`, then `Collections` column `2` to record `+0x00`, and `Collections` column `3` to record `+0x30`; after the walk it writes the matched count to group byte `+0x02`.
- IDA decompilation of `0x0048c640` constructs the collection detail dialog and reads/writes the same group structure: it uses `9732 * groupIndex`, checks group loaded flag `+0x3ec8`, reads group type `+0x3ec9`, reads total entries `+0x3eca`, and uses `0x4c` entry stepping for dialog bit/state population.
- IDA decompilation of `0x0048d3a0` stores the selected group index at `CollectionEntryControlPane + 0x108` and entry index at `+0x109`, then formats `CLTVOL`/`CLTICON` resource names from group type byte `groupBase + 0x01`.
- IDA disassembly of `0x0048c640` writes detail-dialog packet bits to absolute `group * 0x2604 + 0x3f14 + entry * 0x4c`, which is logical entry record `+0x48`. IDA decompilation of `0x0048d4a0` gates each slot with group total byte `+0x02`, checks that same entry-local `+0x48` state byte before drawing populated detail data, and renders entry-local strings at record `+0x18`, `+0x00`, and `+0x30`. Decimal forms `16076`, `16100`, `16124`, and `16148` were verified with `tools/int_convert.py`.
- IDA decompilation of `0x0056edc0` draws the main collection list using group count at `+0x1340c8`, group type at `+0x3ec9`, total entries at `+0x3eca`, and collected entries at `+0x3ecb`, then formats collection progress.
- IDA decompilation of `0x0056f670` checks the collection input-lock feature view at `g_pUserPane + 1305373` (`+0x13eb1d`) before processing mouse/detail input. The owning global page also records Chatting UI consumers of this same local input-lock byte, so keep exact broad member spelling provisional.

## Consumer Matrix

| Consumer | Offsets used | Layout implication |
| --- | --- | --- |
| [UID:0000P1][UserPane](by-file/UserPane.md) / [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) | `g_pUserPane` global pointer lifetime plus collection-group initialization/destruction | The collection view is nested inside the large `UserPane` local-player object rather than owned by collection UI code. |
| [UID:00002X][CollectionPane](by-class/CollectionPane.md) metadata loader | `+0x1340c8`, `+0x1340c9`, `group * 0x2604 + 0x3ec8`, `+0x3ec9`, `+0x3ecb` | Establishes the process-level group count/load flags, `0x2604` group stride, and group header bytes. |
| [UID:00002X][CollectionPane](by-class/CollectionPane.md) list renderer | `+0x1340c8`, group header bytes `+0x3ec9/+0x3eca/+0x3ecb` | Confirms the group header fields are not loader-only scratch values; they drive visible progress and row text. |
| [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md) / detail controls | group loaded/type/count bytes and `0x4c` entry stepping | Confirms the same records feed the detailed collection dialog, not just the summary pane. |
| [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md) | entry base `groupBase + 0x04 + entry * 0x4c`; strings at record `+0x18/+0x00/+0x30`; state byte at record `+0x48` | Confirms the detail controls consume the same three-string record layout produced by `0x0056f810` and the packet-bit state byte populated by `0x0048c640`; semantic string names remain provisional. |
| Non-collection UserPane/local-player consumers documented on [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) | `+0xa4`, `+0x1a0`, `+0x3cb1`, `+0x3eb4`, `+0x3ec0`, `+0x13a6ec + slot * 0x148`, `+0x13ead4`, `+0x13eb1d` | Confirms the final type is the active `UserPane` object with collection as one nested typed view. |

## CollectionEntryControlPane Consumer Names

B010 source-quality reanalysis of [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md) supports the following feature-view names for the entry record while preserving `UserPane` as the owning storage type:

| Entry-local offset | Recommended source-facing role | Evidence / caveat |
| ---: | --- | --- |
| `+0x00` | `shortName` / `subtitleText` | `0x0056f810` stores `MetaMan` `Collections` column `2` here; `CollectionEntryControlPane::OnDraw` renders it after the entry number. Exact original column label remains unproven. |
| `+0x18` | `entryName` / `lookupName` | Producer copies the row name/key here and uses it for later column lookups; `OnDraw` renders it first in the collected branch. |
| `+0x30` | `description` | Producer stores `Collections` column `3`; `OnDraw` renders it as lower body text. |
| `+0x48` | `collectedFlag` / `unlockedFlag` | Detail-dialog packet-bit decoding writes this byte and `OnDraw` uses nonzero to choose collected-detail rendering over locked/placeholder rendering. |

These names are high-probability consumer names, not proof that the original headers exposed public fields with these exact spellings. The formal feature-view C++ is nevertheless source-ready because its layout, types, and all emitted uses are internally consistent and avoid raw `UserPane` offsets; identifier uncertainty remains documented rather than forcing decompiler-shaped source.

## Boundary And Naming Caveats

- The previous `groupBase + 0x34` entry-region model is superseded. Fresh IDA evidence shows `+0x3efc` is the third `SimpleUString` field of entry 0, while the logical entry record starts at `groupBase + 0x04 + entryIndex * 0x4c`. The state byte lives late in each record at `+0x48`, leaving three tail bytes still semantically unnamed.
- The name `CollectionGroupRecord` is a feature-view name. Final source may expose it as nested fields inside a larger `UserPane` or local-player record rather than as a standalone public struct.
- The three `SimpleUString` fields at entry-local `+0x00`, `+0x18`, and `+0x30` are intentionally described by provenance/render order because existing docs prove their use but not source-quality semantic names.
- The dialog packet supplies a signed/trusted byte count copied into a 32-byte local buffer and used to populate `entries[byteIndex * 8 + bitIndex].collectedFlag` without a reconstructed clamp. The view proves the record destination; it does not sanitize or alter that binary behavior.

## Reconstruction Notes

- Treat this as a `UserPane`/local-player-state nested layout view reached through `g_pUserPane`, not as a separate process-wide allocation. The collection-oriented names are useful for feature documentation but should not imply that collection code owns `dword_67A748`.
- Formal layout CPP is blank; the complete feature-view structs now live in H so `UserPane.h` can embed `CollectionPlayerDataView` by value and CollectionPane consumers can dereference the records. The global pointer C++ itself remains on [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md). Keep caveats that exact broader `UserPane` member names and original table-column labels remain inferred.
- Treat the entry-local `+0x00/+0x18/+0x30` fields as 24-byte SSO-style string objects compatible with [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md). Emit through the accepted feature-view structs and accessor contract; do not replace them with byte arrays, casts, a standalone allocation, or a second process global.

## Score Rationale

- Completion is `93` because the page resolves the stale entry-base mistake, records the exact `0x4c` entry and `0x2604` group sizes, adds the 128-group enclosing view, proves the count/load boundary equalities, identifies all string/state fields, preserves `UserPane` ownership, and now supplies a declaration-visible H route with complete `SimpleUString` visibility and exact size guards.
- Confidence is `94` because pointer lifetime, producer, renderer, dialog, entry-control, progress-bar, `SimpleUString`, and header-order evidence all cross-support the layout. Exact original private struct/field spellings remain inferred, but standalone-global, raw-offset, variable-count, byte-cast, and CPP-local declaration alternatives are rejected.

## Open Questions

- Broader canonical global name is closed as `g_pUserPane`; the remaining question is only the exact nested member/type name for the collection view inside `UserPane`.
- Assign source-quality names to the three entry-local string fields after the `Collections` table column meanings are documented outside the decompiler's numeric column ids.
- Confirm whether byte `+0x1340c9` is best named `collectionMetadataLoaded`, `collectionGroupsLoaded`, or a broader player-data flag.
- No layout or emitter blocker remains; the open naming questions are historical provenance only.

## Cross-References

- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md)
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)

## Changes

- 2026-08-16 Agent-B008 UID0003FA accepted callback: raised `91/92 -> 93/94`, moved the exact three collection declarations unchanged from formal CPP to formal H, included `../../util/StringUtil.h`, added exact `0x4c` and `0x2604` size guards, and preserved owner/emitter UID0000P1 at position 5. This makes the collection view complete before `UserPane.h` embeds it and before CollectionPane consumers dereference it.
- Reclassified the page from unevaluated to reconstructable layout documentation with conservative scores. Evidence: IDA MCP lookup/decompile checks on 2026-05-31 verify the group count/load offsets, `0x2604` group stride, `+0x3ec8` group base, `+0x3ec9/+0x3eca/+0x3ecb` group header bytes, `0x4c` entry stride, and `+0x13eb1d` input lock; exact per-entry field names and final broader player-state owner remain unresolved.
- 2026-06-02: Raised scoring from `64/78` to `72/84` and attached autogen parent [UID:0000P1][UserPane](by-file/UserPane.md).
  - Before: the page kept the broader player-state owner unresolved and implied the entry array followed immediately after the four group header bytes.
  - After: the page uses the IDA-backed `UserPane` lifetime owner from [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md), maps the group-relative entry base at `+0x34`, and preserves unresolved per-entry names/final type names.
  - Evidence: existing IDA MCP notes for `0x0056ea30`, `0x0056f810`, `0x0048c640`, `0x0056edc0`, `0x0056f670`, and the `dword_67A748` lifetime/xref storage page.
- 2026-06-07:
  - Before: the page had strong offset evidence but did not summarize which consumers prove each part of the nested layout.
  - After: raised scoring to `78/86`, added a consumer matrix, and added an explicit detail-control boundary/naming caveat for the entry region.
  - Evidence: [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md), [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md), [UID:00002X][CollectionPane](by-class/CollectionPane.md), [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md), and [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md) jointly support the stronger layout-view documentation while preserving the unresolved final type/entry-field names.
- 2026-06-13:
  - Before: the page still treated `groupBase + 0x34` / absolute `+0x3efc` as the entry-region base and left the detail-control offsets unresolved.
  - After: raised scoring to `86/88`, corrected the entry record base to `groupBase + 0x04 + entryIndex * 0x4c`, documented the three 24-byte `SimpleUString` fields at record local `+0x00/+0x18/+0x30`, identified the entry-local `+0x48` packet/draw state byte, and synchronized the consumer matrix and reconstruction notes.
  - Evidence: live IDA MCP session `a001_goal2_0002UM` reported healthy auto-analysis/Hex-Rays against `NexusTK.exe`; `lookup_funcs` confirmed `0x0056ea30`, `0x0056f810`, `0x0048c640`, `0x0048d3a0`, `0x0048d4a0`, and `0x0048dc30`; `analyze_function`/`disasm` confirmed the corrected loader and draw offsets; `tools/int_convert.py` verified the decimal/hex offset pairs cited above.
- 2026-06-19 B001 accepted `g_pUserPane` implementation:
  - Scores remain `86/88`.
  - Updated ownership/source wording from broader unresolved player-data block to collection typed view inside source-facing `UserPane *g_pUserPane`.
  - Evidence: [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) now emits `UserPane *g_pUserPane = 0`, preserves `g_pCollectionData`/`g_pPlayerData`/`g_collectionProgressTable` as aliases, and closes `0x0067a748` lifetime ownership to UserPane constructor/destructor/clear writes only.
- 2026-06-21 B010 `CollectionEntryControlPane` consumer-name update:
  - Scores remain `86/88`.
  - Added the detail-control consumer naming evidence for entry-local `+0x00/+0x18/+0x30/+0x48`: `shortName`/`subtitleText`, `entryName`/`lookupName`, `description`, and `collectedFlag`/`unlockedFlag`.
  - Evidence: B010 reanalysis of `CollectionEntryControlPane::OnDraw` confirms render order and branch usage while preserving the caveat that exact original table column labels and the broader `UserPane` nested type names are not final.
- 2026-07-13 B004 UID00010X split callback: raised from `88/89` to `91/92` and extended the managed block with exact `CollectionPlayerDataView { groups[128], groupCount, metadataLoaded }` while preserving the accepted entry/group payload byte-for-byte.
  - Exact arithmetic: `sizeof(CollectionEntryRecord)==0x4c`, `sizeof(CollectionGroupRecord)==0x2604`, and `0x3ec8 + 128*0x2604 == 0x1340c8`, followed by metadata byte `0x1340c9`.
  - Preserved behavior/evidence: all producer/consumer offsets, `SimpleUString` layout, packet no-clamp behavior, source-facing naming caveats, one-pointer `g_pUserPane` lifetime, input-lock separation, and rejection of standalone-global/raw-offset/variable-count source.
