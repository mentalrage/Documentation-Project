*** UID:0000RR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMonsterImageLib

## Status

- Confidence: strong for address and owner, medium for final original symbol spelling.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001PN][0x0069b440-0x0069b444.g_pMonsterImageLib](by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md), IDA `dword_69B440`.
- Canonical owner: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) in [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md).
- Project symbol: `g_pMonsterImageLib`; IDA storage name: `dword_69B440`.

## Meaning

`g_pMonsterImageLib` is the global pointer to the monster sprite image library. Monster rendering, bounds/projection, and cache-clear paths read it before resolving `MONSTER.DNA`/`MONSTER.DND` table rows and numbered `DATA/MON%d.DAT` archive data.

Keep this global with `render/MonsterImageLib.cpp`. Consumers should not adopt it just because they draw or inspect monster sprites.

## Write Evidence

IDA MCP on 2026-05-26 reports these writes to `0x0069b440`:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004daef7` | `MonsterImageLib::MonsterImageLib` | Stores the constructed `MonsterImageLib*` singleton. |
| `0x004daefe` | `MonsterImageLib::MonsterImageLib` | Constructor guard/fallback path clears the singleton. |
| `0x004db0d7` | [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) | Clears the singleton during non-deleting cleanup. |
| `0x004e5bd0` | [UID:000181][0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper](by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md) | Tiny cleanup helper that clears the singleton. |
| `0x004e681e` | `MonsterImageLib::ScalarDeletingDestructor` | Clears the singleton during deleting cleanup. |

The constructor also installs the [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md), initializes the [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md), loads monster table data, and scans numbered monster DAT archives.

## Consumer Evidence

Representative readers include:

- `0x004f6602` in `Application::Shutdown`, which checks the singleton during image-library teardown.
- `0x0050504e` / `0x00505054`, an external cache-clear path that reaches `MonsterImageLib::ClearLoadedData`.
- Render and game-object consumer ranges around `0x005206ca`, `0x005397e3`, `0x0053a2dd`, `0x0053a823`, `0x0053aa7f`, `0x00570fd3`, `0x005a0653`, and `0x005a37ac`.

## Ownership Decision

`g_pMonsterImageLib` is source-owned by `MonsterImageLib`, not by [UID:0000HG][Application](by-file/Application.md), map panes, object panes, or the shared [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md).

When rebuilding source, preserve this singleton as the canonical global for `0x0069b440` and keep it distinct from the adjacent old-human singleton at `0x0069b43c` and riding singleton at `0x0069b444`.

`AUTOGEN_PARENT_UID:0000LJ` remains the correct file assignment. The strict child/direct-parent gate clears for the global-to-file relationship because this page is now `86/88` and direct parent [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) is `86/86`. The exact storage child [UID:0001PN][0x0069b440-0x0069b444.g_pMonsterImageLib](by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md) is also above gate at `86/90` and confirms the storage/lifecycle evidence.

## Score Rationale

- Completion `86`: exact singleton storage, 22 xrefs, constructor publish/fallback clear, ordinary destructor clear, static cleanup-helper clear, scalar deleting destructor clear, shutdown and cache-clear reads, representative monster render/object/UI consumers, adjacent image-library singleton separation, exact storage child, and direct file-parent gate clearance are documented.
- Confidence `88`: existing IDA-backed docs consistently prove the storage, lifecycle, owner, and consumer role. Confidence stays below final-audit quality because final original symbol spelling, all consumer roles, and final helper/source split details remain open.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069b440` is `dword_69B440`, size `4`, in `.data`, with 22 data xrefs.
- Live IDA xrefs confirm constructor writes at `0x004daef7` / `0x004daefe`, destructor/helper clears at `0x004db0d7`, `0x004e5bd0`, and `0x004e681e`, and teardown access at `0x004f6602`.
- Live IDA xrefs also confirm the representative consumer set around `0x0050504e`, `0x005206ca`, `0x005397e3`, `0x0053a2dd`, `0x0053a823`, `0x0053aa7f`, `0x00570fd3`, `0x005a0653`, and `0x005a37ac`.
- Live IDA decompilation on 2026-06-05 confirms `0x004daec0` stores `this` into `dword_69B440` and installs the `MonsterImageLib` vtable; `0x004db010`, `0x004e5bd0`, and `0x004e6750` clear the singleton during cleanup/destruction.
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) and [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) document the owner-side render, archive, table, bounds, and singleton responsibilities that explain why consumer panes should not own this global.
- [UID:0001PN][0x0069b440-0x0069b444.g_pMonsterImageLib](by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md) remains the canonical memory page for this slot and matches the live IDA check.

## Cross-References

- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:00017C][0x004dac40-0x004e685f.MonsterImageLib](by-memory/0x004dac40-0x004e685f.MonsterImageLib.md)
- [UID:0001PN][0x0069b440-0x0069b444.g_pMonsterImageLib](by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md)
- [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md)
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `88`.
- Summary/evidence: the page now reflects live IDA MCP verification of exact storage, singleton lifecycle writes/clears, and consumer xrefs, plus class/file ownership evidence. Confidence is strong for storage and owner, but not absolute because final original symbol spelling and every consumer role are not fully named.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LJ`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069b440` and decompilation of `0x004daec0`, `0x004db010`, `0x004e5bd0`, and `0x004e6750` prove NexusTK-owned `MonsterImageLib` singleton storage owned by [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-10 A001 strict gate repair:
  - Changed completion from `84` to `86`; confidence remains `88`.
  - Summary/evidence: direct parent [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) is `86/86`, exact storage child [UID:0001PN][0x0069b440-0x0069b444.g_pMonsterImageLib](by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md) is `86/90`, and this page now documents the singleton lifecycle and owner evidence enough to clear the corrected strict `85/85` assignment gate. C++ remains blank below the final `95/95` gate.
