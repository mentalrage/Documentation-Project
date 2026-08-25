** TARGET-REPORT-UID:0002JN **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002JN MonsterImageLibLoadMonsterTables Source-Quality Rework

## Final Recommendation

Update [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](../../../../../by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) as the class-owned `MonsterImageLib::LoadMonsterTables` method and add a first-draft source-quality C++ block.

Recommended metadata:

| Field | Current | Recommended | Reason |
| --- | --- | --- | --- |
| `COMPLETION` | `86` | `90` | The rejected no-code blocker has been reworked. Loader control flow, owner route, helper bodies, default table seeding, and the 8-byte/10-byte record layouts are documented with current MCP evidence. |
| `CONFIDENCE` | `88` | `91` | Function boundary, only caller, resource branch, allocation widths, default constants, helper xrefs, row fields, and consumer evidence are consistent across target, riding sibling, lookup helpers, and render/scheduler callers. |
| `CANONICAL_OWNER` | `0000LJ` | `00008N` | The direct semantic owner is the `MonsterImageLib` class. [UID:0000LJ] remains the source file route through the class. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Project-owned source behavior with a stable method boundary and source-level class/file route. |
| `EMITTER_UIDS` | `0000LJ` | `00008N` | Emit through the class owner, which routes to [UID:0000LJ] `NexusTK/render/MonsterImageLib.cpp`. |
| `RECONSTRUCTION_CPP CODE` | blank | nonblank | Use the first-draft method in this report. The helper/type names are inferred and ledgered, not raw IDA names. |

The prior report's "do not add C++ yet" recommendation should be withdrawn. The unresolved helper/type names are no longer a sufficient blocker because the helper island has exact bodies, shared xrefs, record widths, fallback records, and downstream consumers. The implementation should still mark the helper and field names as inferred where they are not recovered symbols.

## Current Target State

The target currently says:

- `COMPLETION:86`, `CONFIDENCE:88`
- `CANONICAL_OWNER:0000LJ`, `EMITTER_UIDS:0000LJ`
- `RECONSTRUCTABLE:TRUE`
- C++ block blank
- Summary: constructor-only `MONSTER.DNA`/`MONSTER.DND` loader that allocates 0x0c monster rows, initializes global grouping tables, and fills nested animation records; final source names remain provisional.

That page is directionally correct, but it under-routes a class method through the file root and now needs the formal loader C++ plus a field-name confidence ledger.

## Evidence Checked

Current IDA MCP was mandatory and responsive for this rework.

- `initialize`: MCP server `ida-pro-mcp`, protocol `2025-06-18`.
- `idb_list`: active session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker PID `26892`.
- `server_health`: `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready.
- `lookup_funcs`: `sub_4DAC40` starts at `0x004dac40` with size `0x27d`; the riding sibling `sub_4DC420` starts at `0x004dc420` with size `0x26d`; helpers resolve at `0x00528930`, `0x00528950`, `0x005289d0`, `0x00528b10`, `0x00528b50`, `0x00528b60`, `0x00528be0`, `0x00528d00`, and `0x00528d30`.
- `decompile 0x004dac40`: confirms DAT reader construction, `byte_66DA97 == 1` resource branch, 12-byte row vector allocation, `MonsterImageLib +0x04` row pointer, `MonsterImageLib +0x08` row count, default table allocation at `0x0069b424`, 21 default groups, one default frame per group, per-row reads, per-group 8-byte records, per-frame 10-byte records, `DATFile::Close`, and destructor cleanup.
- `decompile 0x004dc420`: confirms the riding loader uses the same 12-byte/8-byte/10-byte schema and the same shared helpers for `RIDINGS.DNA`.
- `xrefs_to 0x005289d0`: four allocation calls, two from the monster loader (`0x4dad0f`, `0x4dadb5`) and two from the riding loader (`0x4dc4df`, `0x4dc585`).
- `xrefs_to 0x00528be0`: four frame-array allocation calls, two from the monster loader (`0x4dad2b`, `0x4dade4`) and two from the riding loader (`0x4dc4fb`, `0x4dc5b4`).
- `xrefs_to 0x00528b10`: 12 lookup calls across monster and riding render paths, including `0x4db154`, `0x4db185`, `0x4db42e`, `0x4db463`, `0x4db5f5`, and raw riding draw/helper refs.
- `xrefs_to 0x00528d00`: five inner-frame lookup callers at `0x53a30b`, `0x53aaae`, `0x53b780`, `0x53ba59`, and `0x5a37d6`.
- `xrefs_to 0x0066deb0`: only the two shared lookup fallback refs at `0x528b2f` and `0x528d11`.
- `xrefs_to 0x0069b424`: static init, this loader, monster entry fallback lookup, and static cleanup.
- `xrefs_to 0x0069b42c`: four default-group seeding refs in this loader.

Support documents checked:

- Target page [UID:0002JN].
- [UID:00008N] `MonsterImageLib` class page.
- [UID:0000LJ] `MonsterImageLib` file page.
- [UID:0000LK] `MonsterImageLibTables` file page.
- [UID:0001VC] `MonsterImageEntry` struct page.
- [UID:00008O] and [UID:00008P] address-derived helper class pages.
- [UID:0001CM] helper island page at `0x00528930-0x00528d51`.
- [UID:00027U] shared default frame record at `0x0066deb0`.
- [UID:00029K] concrete monster default table object at `0x0069b424`.
- [UID:0000N6], [UID:0000BZ], [UID:0002LA], [UID:0001VV], [UID:0000TJ], and [UID:0001PL] riding sibling/support pages.
- DATFile pages documenting `DATFile::DATFile`, `Open`, `Read`, `Close`, and destructor names.

## Target Loader Facts

`0x004dac40` is a complete class method, not a free helper:

- It is called by the `MonsterImageLib` constructor at `0x004daec0`.
- It writes the table pointer at `this + 0x04` and row count at `this + 0x08`.
- It uses `DATFile::DATFile`, `DATFile::Open`, repeated `DATFile::Read`, `DATFile::Close`, and `DATFile::~DATFile`.
- It chooses the monster table resource with `byte_66DA97 == 1`: the existing file docs identify the selected resources as `MONSTER.DNA` and `MONSTER.DND`.
- It reads a 4-byte row count, allocates a 12-byte row array, and constructs each row with the helper at `0x00528930`.
- It seeds the concrete monster default table object at `0x0069b424`.
- It reads each row as `+0 dword`, `+4 byte`, `+5 byte`, `+6 word`, then allocates row groups through `0x005289d0`.
- It reads each group as `+4 word frameCount`, then allocates 10-byte frame entries through `0x00528be0`.
- It reads each 10-byte entry in this order: `+0 word`, `+2 word`, `+6 word`, `+4 byte`, `+8 byte`, `+9 byte`.

The exact range remains stable. No split or new child page is needed for this method.

## Helper Recheck

| Helper | Current MCP fact | Source-quality disposition |
| --- | --- | --- |
| `sub_528930` (`0x00528930`) | 12-byte object constructor: zeroes three dwords. | Constructor for the outer animation table row/default table shape. This supports `MonsterImageEntry` construction and the default table object. |
| `sub_528950` (`0x00528950`) | 12-byte object destructor: destroys 8-byte group records with `sub_528B60`, frees the vector, clears count/pointer. | Destructor for the outer animation table shape. It is source-visible as normal cleanup, not a reason to keep the loader blank. |
| `sub_5289D0` (`0x005289d0`) | Allocates `8 * count + 4`, vector-constructs 8-byte groups with `sub_528B50`, stores group pointer at `+8`, stores count at `+4`. | Use as inferred `AllocateGroups`/`SetGroupCount` behavior. Shared between monster and riding. |
| `sub_528B10` (`0x00528b10`) | Outer lookup: checks group count and frame count, returns `group.frames[index]` or `0x0066deb0`. | Confirms outer row/default table semantics and fallback frame record. |
| `sub_528B50` (`0x00528b50`) | 8-byte group constructor: pointer null at `+0`, count zero at `+4`. | Constructor for inferred `ImageAnimationGroup`. |
| `sub_528B60` (`0x00528b60`) | 8-byte group destructor: destroys 10-byte records with `nullsub_13`, frees vector, clears pointer/count. | Destructor for inferred `ImageAnimationGroup`. |
| `sub_528BE0` (`0x00528be0`) | Allocates `10 * count + 4`, vector-constructs entries with `sub_528D30` and `nullsub_13`, stores frame pointer at `+0`, stores count at `+4`. | Use as inferred `AllocateFrames` behavior. Shared between monster and riding. |
| `sub_528D00` (`0x00528d00`) | Inner lookup: checks frame count and returns `frame[index]` or `0x0066deb0`. | Confirms `+4` on the 8-byte group is frame count and `+0` is frame pointer. |
| `sub_528D30` (`0x00528d30`) | 10-byte frame constructor: `+0=0`, `+4=0xff`, `+6=0xffff`, `+8=0`; `+5` is implicit zero/padding from vector allocation/constructor state. | Constructor for inferred `ImageAnimationFrame`. |
| `nullsub_13` | No-op element destructor for 10-byte records. | POD-style frame entry destructor. It should not appear as a source call in the target method. |

The helper names in support docs can remain address-backed during implementation, but the target C++ should not call raw `sub_` helpers. Use inferred source names and keep the evidence ledger.

## 8-Byte Group Record

The 8-byte record blocker is resolved:

| Offset | Recommended field | Evidence | Confidence |
| --- | --- | --- | --- |
| `+0x00` | `ImageAnimationFrame *frames` | `sub_528B50` clears it; `sub_528BE0` writes the vector pointer; `sub_528B60` frees it; `sub_528D00` indexes it as `base + 10 * frameIndex`. | Strong |
| `+0x04` | `uint16_t frameCount` | `sub_528B50` zeroes it; `sub_528BE0` writes the low-byte count into this word; `sub_528B10`/`sub_528D00` compare indices against it; loader reads it from the data file before frame allocation. | Strong |
| `+0x06` | `uint16_t reserved` | The 8-byte width leaves a trailing word. Constructor/destructor evidence does not show semantic reads in the checked helper bodies. | Medium |

This is source-quality enough to name a neutral shared group type. The old placeholder class names `MonsterImageLibTable_5289D0` and `MonsterImageLibTable_528BE0` are implementation documentation aids, not final source names.

## 10-Byte Frame Entry Record

The 10-byte record blocker is also reduced from "no-code" to a field-confidence ledger:

| Offset | Recommended field | Evidence | Confidence |
| --- | --- | --- | --- |
| `+0x00` | `int16_t frameOffset` | The monster render and bounds paths call `sub_528B10`, read word `+0`, sign-extend it, and add it to the row base frame before archive lookup/render. Riding raw draw/helper refs show the same pattern. | Strong |
| `+0x02` | `uint16_t frameDuration` | Inner lookup callers use `sub_528D00`, then pass word `+2` to scheduler/timing calls such as `sub_597910`. The default record seed writes 30000 here. This supersedes the weaker old `endFrame` wording. | Strong |
| `+0x04` | `uint8_t blendAlpha` | `0x004db3b0` reads byte `+4`, converts it to a float by dividing by 255.0, and selects render mode state. The default constructor uses `0xff`, while this loader's default table overwrites the default frame to zero. | Strong for monster render |
| `+0x05` | `uint8_t reserved` | Not read by the target parser. It is part of the 10-byte record width and is not explicitly populated by the loader. | Medium |
| `+0x06` | `int16_t auxFrameId` | Loader reads a word here and the frame constructor seeds it to `0xffff`. No direct consumer was confirmed in the checked monster render/bounds paths. Name remains inferred and should be documented as weaker than `+0/+2/+4`. | Medium-low |
| `+0x08` | `uint8_t paletteIndex` | Loader reads a byte here; constructor seeds the trailing word to zero. Existing riding struct docs describe this byte as palette-related. No target monster render consumer was confirmed. | Medium-low |
| `+0x09` | `uint8_t effectIndex` | Loader reads the final byte; existing riding struct docs describe it as effect-related. No target monster render consumer was confirmed. | Medium-low |

Rejected alternatives:

- `+0x02` should not remain `endFrame` without qualification. The live MCP recheck found scheduler/timing use, not range-end use.
- `+0x04` should not remain `direction` for the shared field. The monster render path treats it as alpha/mode intensity.
- The weak fields `+0x06`, `+0x08`, and `+0x09` should not block a target method C++ block because the loader simply copies serialized fields into a typed record and the record shape is exact.

## Default Table Recheck

`0x0069b424` is the concrete monster default animation table object:

- Static init and cleanup touch the object.
- This loader allocates 21 groups in it.
- The loader iterates 168 bytes at `0x0069b42c`, which is 21 8-byte groups.
- Each default group receives one 10-byte frame entry.
- Each default frame entry is seeded as frame offset `0`, frame duration `30000`, and blend alpha `0`; the constructor leaves the auxiliary word at `0xffff` and the trailing bytes at zero.
- `MonsterImageLib` fallback lookup returns this object for out-of-range monster entry indexes.

Source-facing recommendation: document this as `g_defaultMonsterAnimationTable` or an equivalent neutral static name in the file/class support docs. Keep [UID:00029K] as the concrete storage page.

## Ownership And Placement

Recommended ownership:

1. Direct owner: [UID:00008N] `MonsterImageLib`.
2. Source file route: [UID:0000LJ] `NexusTK/render/MonsterImageLib.cpp`.
3. Shared helper support: [UID:0000LK] `MonsterImageLibTables.cpp` or a neutral shared render animation helper page, as already represented by the helper island docs.

Reason:

- The method is a `thiscall` initializer for `MonsterImageLib`.
- The only direct caller is the class constructor.
- It populates `MonsterImageLib` instance fields at `+0x04/+0x08`.
- It uses the shared table helpers, but the target's source method belongs to the class, not to the helper island.

Do not create a new split and do not edit any coverage report. The target range and helper/default support pages are already present.

## First-Draft C++ For Target

Insert the following into the target's `RECONSTRUCTION_CPP CODE` block after supervisor acceptance. The names are source-facing inferred names; the page should keep the confidence ledger above so weaker field names do not look like recovered symbols.

```cpp
void MonsterImageLib::LoadMonsterTables()
{
    static const unsigned int kDefaultMonsterGroupCount = 21;
    static const unsigned short kDefaultFrameDuration = 30000;

    DATFile tableFile;

    if (g_usesCompactMonsterTable)
        tableFile.Open(L"MONSTER.DNA");
    else
        tableFile.Open(L"MONSTER.DND");

    unsigned int monsterCount = 0;
    tableFile.Read(&monsterCount, sizeof(monsterCount));

    if (monsterCount != 0)
        m_monsters = new MonsterImageEntry[monsterCount];
    else
        m_monsters = 0;

    m_monsterCount = monsterCount;

    g_defaultMonsterAnimationTable.AllocateGroups(kDefaultMonsterGroupCount);
    for (unsigned int groupIndex = 0; groupIndex < kDefaultMonsterGroupCount; ++groupIndex)
    {
        ImageAnimationGroup& group = g_defaultMonsterAnimationTable.groups[groupIndex];

        group.AllocateFrames(1);
        group.frames[0].frameOffset = 0;
        group.frames[0].frameDuration = kDefaultFrameDuration;
        group.frames[0].blendAlpha = 0;
    }

    for (unsigned int monsterIndex = 0; monsterIndex < monsterCount; ++monsterIndex)
    {
        MonsterImageEntry& monster = m_monsters[monsterIndex];

        tableFile.Read(&monster.baseFrameIndex, sizeof(monster.baseFrameIndex));
        tableFile.Read(&monster.animationGroupCount, sizeof(monster.animationGroupCount));
        tableFile.Read(&monster.projectionFlag, sizeof(monster.projectionFlag));
        tableFile.Read(&monster.paletteTableId, sizeof(monster.paletteTableId));

        monster.AllocateGroups(monster.animationGroupCount);

        for (unsigned int groupIndex = 0; groupIndex < monster.animationGroupCount; ++groupIndex)
        {
            ImageAnimationGroup& group = monster.groups[groupIndex];

            tableFile.Read(&group.frameCount, sizeof(group.frameCount));
            group.AllocateFrames(group.frameCount);

            for (unsigned int frameIndex = 0; frameIndex < group.frameCount; ++frameIndex)
            {
                ImageAnimationFrame& frame = group.frames[frameIndex];

                tableFile.Read(&frame.frameOffset, sizeof(frame.frameOffset));
                tableFile.Read(&frame.frameDuration, sizeof(frame.frameDuration));
                tableFile.Read(&frame.auxFrameId, sizeof(frame.auxFrameId));
                tableFile.Read(&frame.blendAlpha, sizeof(frame.blendAlpha));
                tableFile.Read(&frame.paletteIndex, sizeof(frame.paletteIndex));
                tableFile.Read(&frame.effectIndex, sizeof(frame.effectIndex));
            }
        }
    }

    tableFile.Close();
}
```

Behavioral match notes:

- `new MonsterImageEntry[monsterCount]` maps to the 12-byte vector constructor at `0x004dacc7`.
- `AllocateGroups` maps to the shared helper at `0x005289d0`.
- `AllocateFrames` maps to the shared helper at `0x00528be0`.
- The default table loop is expressed as 21 groups instead of the compiler's 168-byte pointer walk.
- The field read order exactly matches the decompile: row `+0,+4,+5,+6`; group `+4`; frame `+0,+2,+6,+4,+8,+9`.
- The `DATFile` destructor remains implicit at function exit, matching the compiler cleanup after `DATFile::Close`.

## Support Document Updates Needed

After supervisor acceptance, update the target and support docs, not generated reports:

- [UID:0002JN]: metadata, owner/emitter, summary, MCP evidence, helper ledger, field ledger, default table note, and C++ block above.
- [UID:00008N] `MonsterImageLib`: route this method through the class owner and note that the method now has first-draft C++.
- [UID:0000LJ] `MonsterImageLib`: keep file-level ownership route, add the default table source-facing name and resource branch evidence.
- [UID:0001VC] `MonsterImageEntry`: update the row field names to align with this loader and render consumers, especially `animationGroupCount`, `projectionFlag`, `paletteTableId`, and `groups`.
- [UID:0000LK], [UID:0001CM], [UID:00008O], and [UID:00008P]: record the neutral shared type names `ImageAnimationGroup` and `ImageAnimationFrame` as inferred source-facing names, while keeping raw helper addresses in evidence.
- [UID:00027U] and [UID:00029K]: connect the shared default frame record and concrete monster default table to the source-facing default table name.
- [UID:0002LA] and [UID:0001VV]: note the sibling parser evidence and revise the old `+0x02=endFrame` / `+0x04=direction` wording as weak or superseded by the current timing/alpha evidence.

## Implementation Tracking Checklist

- [x] Supervisor accepts this reworked report as satisfying the rejection.
  - Proof: supervisor implementation callback issued 2026-06-25 for assignment `B001-implement-0002JN-monster-image-lib-load-monster-tables-20260625`.
- [x] Update the target page [UID:0002JN] metadata to `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:00008N`, `EMITTER_UIDS:00008N`, `RECONSTRUCTABLE:TRUE`.
  - Proof: [UID:0002JN] now has `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:00008N`, `EMITTER_UIDS:00008N`, and `RECONSTRUCTABLE:TRUE`.
- [x] Insert the first-draft C++ method into [UID:0002JN].
  - Proof: [UID:0002JN] `RECONSTRUCTION_CPP` now contains `MonsterImageLib::LoadMonsterTables()` with DAT resource selection, row allocation, default table seeding, row/group/frame parse loops, and close/cleanup flow.
- [x] Add the MCP evidence ledger for `0x004dac40`, `0x004dc420`, helper xrefs, default table xrefs, and fallback frame xrefs.
  - Proof: [UID:0002JN] now records the implementation MCP probe against active IDB session `80de0a67`, including `lookup_funcs` for `0x004dac40`, `0x004dc420`, `0x005289d0`, and `0x00528be0`; default/fallback records remain data items, not functions.
- [x] Add the 8-byte group record and 10-byte frame entry confidence ledgers to [UID:0002JN].
  - Proof: [UID:0002JN] includes the helper role ledger plus the `ImageAnimationGroup` and `ImageAnimationFrame` field-confidence ledgers, with `int_convert.py`-verified constants.
- [x] Update [UID:00008N] and [UID:0000LJ] ownership/source-route language.
  - Proof: `by-class/MonsterImageLib.md` now routes the method through class owner [UID:00008N] and notes the first-draft method C++; `by-file/MonsterImageLib.md` keeps file ownership and records the default table/source-route evidence.
- [x] Update [UID:0001VC] row-field and nested-table language.
  - Proof: `by-type/by-struct/MonsterImageEntry.md` now records the 12-byte row fields plus nested `ImageAnimationGroup` and `ImageAnimationFrame` layouts and field-confidence notes.
- [x] Update helper/default support pages listed above without introducing raw `sub_` names into formal source C++.
  - Proof: helper/default/sibling pages [UID:0000LK], [UID:0001CM], [UID:00008O], [UID:00008P], [UID:00027U], [UID:00029K], [UID:0002LA], and [UID:0001VV] were synchronized with source-facing `ImageAnimationGroup`, `ImageAnimationFrame`, and `g_defaultMonsterAnimationTable` language; raw helper addresses remain only in evidence text, not in formal C++.
- [x] Do not edit generated reports, generated project files, validator state/cache, IDA DB, or any `-coverage-report.md`.
  - Proof: no manual edits were made to generated/project-level/coverage/validator-state/IDA DB files; IDA MCP use was read-only (`initialize`, `idb_list`, `server_health`, `lookup_funcs`). Validator-owned generated refresh side effects occurred only through the required validator runs.
- [x] Run only the required scoped validators after implementation edits, if the supervisor requests the implementation callback.
  - Proof: scoped file validators ran with `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 240 --wait-generated` for the 12 touched by-* files. Command IDs `000000001592` through `000000001603`, timestamps `2026-06-25T14:26:13-04:00` through `2026-06-25T14:28:16-04:00`, each returned `ok: 1`, generated refresh completed, and each exited `0`. Non-fatal pre-existing warnings remained for stale registry/missing Error pages and the stale [UID:00017C] registered path.
- [x] Release implementation leases after the edit/validator batch.
  - Proof: fresh leases were acquired for the 12 touched by-* files before the final edit/validation batch, released successfully after validation, and `tools/leaser/Agents/current_leases.md` has no active `Agent-B001` entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002JN-MonsterImageLibLoadMonsterTables-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002JN-MonsterImageLibLoadMonsterTables-source-quality.md","timestamp":"2026-06-25T14:37:41","uid":"0002JN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
