** TARGET-REPORT-UID:0001VA **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001VA MonsterArchiveBoundsBucket Ownership / Split Research

## Current Recommendation

Assign [UID:0001VA][MonsterArchiveBoundsBucket](../../../../../by-type/by-struct/MonsterArchiveBoundsBucket.md) to [UID:00008N][MonsterImageLib](../../../../../by-class/MonsterImageLib.md).

Final disposition: source-owned `MonsterImageLib` private/archive bucket record. No split is needed. The target page has been repaired from `82/88` with blank parent to `86/90` with `AUTOGEN_PARENT_UID:00008N`; the direct parent class is `85/85`, and its file parent [UID:0000LJ][MonsterImageLib](../../../../../by-file/MonsterImageLib.md) is `86/86`.

Do not emit C++ for this type yet. The exact original names for the two middle header metrics and the full archive payload contract are still below the `95+` final-source gate.

## Final Inventory

| UID | Page | Score | Parent | Final status |
| --- | --- | ---: | --- | --- |
| `0001VA` | `by-type/by-struct/MonsterArchiveBoundsBucket.md` | `86/90` | `00008N` | Repaired and assigned. |
| `0001VB` | `by-type/by-struct/MonsterArchiveBoundsEntry.md` | `80/88` | `00008N` | Inspected; related entry row type, not edited in B001-032. |
| `0001VD` | `by-type/by-struct/MonsterImageLibLayout.md` | `78/86` | blank | Inspected; layout evidence only, not the direct parent for this bucket type. |
| `00017E` | `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md` | `78/88` | `0000LJ` | Loader evidence page inspected. |
| `00017D` | `by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md` | `76/86` | `0000LJ` | Destructor/cleanup evidence page inspected. |
| `00003K` | `by-class/DATIndexVector.md` | `85/86` | `0000IP` | Reusable cache helper; rejected as semantic owner. |
| `00008N` | `by-class/MonsterImageLib.md` | `85/85` | `0000LJ` | Direct parent clears strict gate. |
| `0000LJ` | `by-file/MonsterImageLib.md` | `86/86` | source root | File parent clears strict gate. |

No new by-* child pages were created for B001-032. The only repaired by-* page is `0001VA`.

## IDA Facts

IDA MCP was used against `NexusTK.exe` (`MD5 4247e04e20b65d6414c7238aa8ff5515`, `SHA256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`).

| Address | IDA fact | Ownership/field implication |
| --- | --- | --- |
| `0x004dbe60` | `lookup_funcs` reports `sub_4DBE60`, size `0x315`. Callers are `0x004db647` in `sub_4DB5C0` and `0x004dc1b9` in `sub_4DC180`; `xrefs_to` also reports `0x004dc279`. | This is the lazy `MonsterImageLib` bucket loader, not a generic DAT helper. |
| `0x004dbe60` | Decompilation allocates a 0x0c bucket, inserts it into `this + 0x3c`, reads exactly 8 header bytes, allocates `24 * (entryCount + 1)` bytes, and stores the entry pointer at `bucket + 8`. | Proves bucket size, `+0x00` count, `+0x08` entry pointer, and `MonsterImageLibLayout +0x3c` cache ownership. |
| `0x004dbe60` | The entry loop reads four 16-bit bounds and two 32-bit payload offsets, rebases offsets by the DAT payload base, and writes a zero-bounds sentinel row. | Confirms the bucket owns an array of 0x18 `MonsterArchiveBoundsEntry` rows. |
| `0x004dc180` | Resolver callers are `RenderMonster` at `0x004db1a5` and `RenderMonsterImage` at `0x004db47a`; it calls `0x004dbe60`. | Shows live render paths consume the bucket through `MonsterImageLib`. |
| `0x004db5c0` | Render-bounds consumer calls `0x004dbe60`, checks `frameIndex < entryCount`, and copies the entry `RectBounds`. | Confirms runtime consumers use `entryCount` and `entries`; they do not consume the middle header metrics directly. |
| `0x004dc2e0` | Cleanup callers are the ordinary destructor, scalar deleting destructor, and cache-clear path. Decompilation frees `bucket->entries`, then frees the 0x0c bucket while clearing the `+0x3c` cache. | Confirms source-owned lifetime and cleanup responsibility. |
| `0x004db8b0` | `xrefs_to`/`callers` report no callers. Decompilation scans `MON%d.EPF`, reads the same 8-byte headers, sums entry counts, takes maxima over `+0x02` and low `+0x04`, zeroes high `+0x06`, and builds the same 0x18 entry array with sentinel. | Proves the old unknown middle fields are active 16-bit max/extent metrics, while `+0x06` remains neutral. |
| `0x0061c07c` | Wide string bytes decode to `DATA/MON%d.DAT`; xrefs are from archive scan/load paths. | Confirms numbered monster DAT resource ownership. |
| `0x0061c09c` | Wide string bytes decode to `MON%d.EPF`; xrefs are from `0x004db8b0`. | Ties the unreferenced builder to the same monster image/bounds archive format. |

IDA `search_structs` / `struct_info` found no named local IDA structs for `MonsterArchiveBoundsBucket`, `MonsterArchiveBoundsEntry`, `MonsterImageLibLayout`, or `DATIndexVector`. Field names remain recovered documentation vocabulary.

## Field Semantics

Final repaired layout:

```text
MonsterArchiveBoundsBucket
  +0x00  uint16 entryCount
  +0x02  uint16 maxExtent02
  +0x04  uint16 maxExtent04
  +0x06  uint16 header06
  +0x08  MonsterArchiveBoundsEntry* entries
```

`entryCount` and `entries` are fully supported by loader, consumers, and cleanup. The decisive new evidence is `0x004db8b0`: it does arithmetic on the former unknown middle header fields, keeping maxima over the `+0x02` and low `+0x04` halfwords when building an aggregate EPF bucket. That is enough to raise completion over the strict gate, but not enough to claim exact original axis names.

`+0x06` is still not decoded. The normal DAT loader preserves the high halfword from disk; the aggregate builder zeroes it; no inspected consumer reads it directly.

## Documentation Evidence

- Before B001-032, `0001VA` was `82/88`, reconstructable, parent blank, and classified as `reviewed-no-85` because the old check saw the child below `85` completion and the owner chain below gate.
- Current `MonsterImageLib` class page is `85/85` with parent `0000LJ`. It documents the singleton, vtable, method inventory, `GetArchiveBoundsBucket`, cache layout, and cleanup ownership.
- Current `MonsterImageLib` file page is `86/86` with projected root `auto-generated/NexusTK/render/MonsterImageLib.cpp`. It documents `DATA/MON%d.DAT`, `MON%d.EPF`, `MONSTER.DNA`, `MONSTER.DND`, and the monster image render/cache module role.
- `MonsterImageLibLayout` remains `78/86` and parent blank. That is not a strict gate blocker for `0001VA` because the direct semantic parent for the private bucket type is the `MonsterImageLib` class, not the layout evidence page.
- `DATIndexVector` is `85/86` and parented to its own file. It provides the cache container used at `MonsterImageLib +0x3c`, but caller spread across DAT, minimap, fitting-room, and monster-image code rules it out as the bucket owner.

The generated type coverage report now lists `0001VA` as assigned to `00008N`, destination `auto-generated/NexusTK/render/MonsterImageLib.cpp`.

## Ranked Ownership

1. [UID:00008N][MonsterImageLib](../../../../../by-class/MonsterImageLib.md) - accepted direct parent. All observed loader, resolver, render-bounds consumer, cleanup, resource string, singleton, and cache evidence is inside `MonsterImageLib`; current score is `85/85`.
2. [UID:0000LJ][MonsterImageLib](../../../../../by-file/MonsterImageLib.md) - accepted file parent/root. It is the correct source module for the class and now clears `86/86`; it is one level too broad to be the direct by-type parent.
3. [UID:0001VD][MonsterImageLibLayout](../../../../../by-type/by-struct/MonsterImageLibLayout.md) - supporting evidence only. It proves `+0x3c` cache placement but remains below gate and is not the semantic owner.
4. [UID:00003K][DATIndexVector](../../../../../by-class/DATIndexVector.md) - rejected as owner. It is the reusable cache/index container; it does not define the monster archive bucket payload.
5. `DATArchive`, `EPFImageResources`, and `RectBounds` - rejected as direct owners. They supply reader/resource/geometry dependencies, while the bucket format and lifetime policy are monster-image-specific.

## Negative Evidence And Limits

- No IDA local type names were found for this struct family.
- No live consumer was found that reads `+0x02`, `+0x04`, or `+0x06` after normal DAT bucket load; the max/extent semantics come from the unreferenced aggregate builder.
- `0x004db8b0` has no ordinary callers or xrefs, so it is evidence for format semantics, not live reachability.
- Exact width/height axis names for `maxExtent02` and `maxExtent04` are not proved.
- The high halfword at `+0x06` is not decoded beyond preserved/zeroed header behavior.
- Full `DATA/MON%d.DAT` payload semantics remain incomplete. C++ emission stays blank.

These limits justify `86/90` rather than a higher final-source score; they do not block the strict `85/85` assignment gate.

## Edits Applied

`by-type/by-struct/MonsterArchiveBoundsBucket.md`:

- Set `COMPLETION:86`, `CONFIDENCE:90`, `AUTOGEN_PARENT_UID:00008N`.
- Replaced stale `reviewed-no-85` status with assigned status.
- Refined layout from `header02` / `uint32 header04` to `maxExtent02`, `maxExtent04`, and neutral `header06`.
- Added loader, resolver, render-bounds, cleanup, aggregate-builder, and parent-gate evidence.
- Recorded why `MonsterImageLibLayout` and `DATIndexVector` are supporting evidence rather than direct parent blockers.

## Validator Results

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001VA-MonsterArchiveBoundsBucket-removed.md](0001VA-MonsterArchiveBoundsBucket-removed.md). The archived block is non-authoritative and must not be executed.

Result: exit code `0`; scanned markdown files `1`; `ok: 1`.

Key validator lines:

```text
completion_update 0001VA by-type/by-struct/MonsterArchiveBoundsBucket.md 86
confidence_update 0001VA by-type/by-struct/MonsterArchiveBoundsBucket.md 90
autogen_registry_update 0001VA by-type/by-struct/MonsterArchiveBoundsBucket.md  -> 00008N
autogen_report_update ------ auto-generated/-ag-type-coverage.md validator-owned generated file
projected_stats_update ------ project-level/-auto-completion-stats.md updated projected path completion section
autogen_registry_rebuild ------ validator.ini 3581 metadata nodes, 2920 edges
```

The validator also created `tools/validator_autogen_backup/20260610-145738/` before rewriting generated coverage/registry outputs.

## Changed Files

- `by-type/by-struct/MonsterArchiveBoundsBucket.md`
- `auto-generated/-ag-type-coverage.md` (validator-owned generated update)
- `project-level/-auto-completion-stats.md` (validator-owned generated update)
- `tools/validator.ini` (validator registry rebuild)
- `tools/validator_autogen_backup/20260610-145738/` (validator backup)
- `tools/leaser/Agents/Agent-B001/research/0001VA-MonsterArchiveBoundsBucket.md`

`Supervisor_notes.md` was not edited. The report was not moved to `executed`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001VA-MonsterArchiveBoundsBucket.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001VA"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001VA-MonsterArchiveBoundsBucket-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001VA-MonsterArchiveBoundsBucket.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001VA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
