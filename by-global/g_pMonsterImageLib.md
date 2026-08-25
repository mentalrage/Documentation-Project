*** UID:0000RR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008N | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MonsterImageLib *g_pMonsterImageLib = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern MonsterImageLib *g_pMonsterImageLib;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMonsterImageLib

## 2026-08-18 External Singleton Definition Closure

- Formal CPP emits exactly one external-linkage definition: MonsterImageLib *g_pMonsterImageLib = NULL;. Formal H emits exactly one extern declaration. Both channels route through UID00008N at position `0`: CPP places the definition after `#include "MonsterImageLib.h"` and before remaining class children, while H places the extern at the class page's explicit guarded child insertion point. The prior static definition is retained below as superseded history and must not remain active source.
- Exact storage remains 0x0069b440 with zero initialization. Publish, clear, and read lifecycle remains owned by MonsterImageLib.cpp.
- The complete 22-reference set is 0x004daef7, 0x004daefe, 0x004db0d7, 0x004e5bd0, 0x004e681e, 0x004f6602, 0x0050504e, 0x005206ca, 0x00520740, 0x005397e3, 0x0053a2dd, 0x0053a823, 0x0053a899, 0x0053aa7f, 0x0053b736, 0x0053b9df, 0x0053bc31, 0x0053bd9a, 0x0053be72, 0x00570fd3, 0x005a0653, and 0x005a37ac.
- Cross-module readers make internal linkage impossible. Scores are 91/92; the remaining cap is original lexical certainty and absent rebuilt-binary comparison.

## Status

- Confidence: strong for address, owner, current zero-filled storage, lifecycle xrefs, and source declaration shape; medium-high for final original symbol spelling.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001PN][0x0069b440-0x0069b444.g_pMonsterImageLib](by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md), IDA `dword_69B440`.
- Canonical owner: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) in [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md).
- Project symbol: `g_pMonsterImageLib`; IDA storage name: `dword_69B440`.

## Meaning

`g_pMonsterImageLib` is the global pointer to the monster sprite image library. Monster rendering, bounds/projection, and cache-clear paths read it before resolving `MONSTER.DNA`/`MONSTER.DND` table rows and numbered `DATA/MON%d.DAT` archive data.

Keep this global with `render/MonsterImageLib.cpp`. Consumers should not adopt it just because they draw or inspect monster sprites.

Historical checkpoint: the former formal block emitted a file-local definition for this singleton pointer:

```cpp
static MonsterImageLib *g_pMonsterImageLib = NULL;
```

[UID:0001PN][0x0069b440-0x0069b444.g_pMonsterImageLib](by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md) documents the exact `.data` storage and emits only a covered-by marker so the rebuilt source does not define the pointer twice. B011 current MCP on 2026-06-30 reads `0x0069b440 == 0`, superseding stale `0xffffffff` storage text on the exact memory child.

## Write Evidence

IDA MCP on 2026-05-26 reports these writes to `0x0069b440`:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004daef7` | `MonsterImageLib::MonsterImageLib` | Stores the constructed `MonsterImageLib*` singleton. |
| `0x004daefe` | `MonsterImageLib::MonsterImageLib` | Constructor guard/fallback path clears the singleton. |
| `0x004db0d7` | [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) | Observed clear during non-deleting cleanup; B011 source sync records this as compiler-lowered singleton subobject/static-lifetime cleanup, not a handwritten `g_pMonsterImageLib = 0` statement in the formal destructor body. |
| `0x004e5bd0` | [UID:000181][0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper](by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md) | Tiny cleanup helper that clears the singleton. |
| `0x004e681e` | `MonsterImageLib::ScalarDeletingDestructor` | Clears the singleton during deleting cleanup. |

The constructor also installs the [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md), initializes the [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md), loads monster table data, and scans numbered monster DAT archives.

## Consumer Evidence

Representative readers include:

- `0x004f6602` in `Application::Shutdown`, which checks the singleton during image-library teardown.
- `0x0050504e` / `0x00505054`, an external cache-clear path that reaches `MonsterImageLib::ClearLoadedData`.
- Render and game-object consumer ranges around `0x005206ca`, `0x005397e3`, `0x0053a2dd`, `0x0053a823`, `0x0053aa7f`, `0x00570fd3`, `0x005a0653`, and `0x005a37ac`.

### UID0003U8 Directional-Animation Consumer - 2026-07-15

- The read at `0x005a37ac` is inside [UID:0003U8][0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation](by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md), not a generic object-image consumer. The target reaches this global only when `m_objectStatus.m_statusKind == ObjectStatusBlob::MonsterObject`.
- The exact chain is singleton read, bounds-checked `MonsterImageLib::GetEntryByIndex(m_appearanceId - 0x8000)`, `MonsterImageEntry::GetGroup(direction + 5)`, `ImageAnimationGroup::GetFrame(m_moveFrame)`, and signed `ImageAnimationFrame::frameDuration` scheduling for UserPane event `20`.
- [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md) uses the same singleton/type route for animation playback and frame-timer advancement. This is consumer evidence only; `MonsterImageLib.cpp` retains the sole global definition and lifecycle ownership.
- Historical `g_pObjectImageLib` and HumanObject routing for these two animation families is superseded. Global score, formal definition, owner/emitter, storage child, lifecycle writes, and unrelated consumers remain unchanged.

## Ownership Decision

`g_pMonsterImageLib` is source-owned by `MonsterImageLib`, not by [UID:0000HG][Application](by-file/Application.md), map panes, object panes, or the shared [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md).

When rebuilding source, preserve this singleton as the canonical global for `0x0069b440` and keep it distinct from the adjacent old-human singleton at `0x0069b43c` and riding singleton at `0x0069b444`.

The semantic file owner remains [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), while generated CPP/H route through [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) to enforce the accepted singleton ordering. This global, the class, and the file are each `91/92`; exact storage child [UID:0001PN][0x0069b440-0x0069b444.g_pMonsterImageLib](by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md) remains `88/91` and confirms the storage/lifecycle evidence.

## Destructor Source-Shape Clarification

B011's 2026-06-25 destructor source sync preserves every observed write/clear to this singleton but keeps the formal [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) C++ body free of a manual `g_pMonsterImageLib = 0` statement.

Reason:

- Constructor disassembly publishes `g_pMonsterImageLib` through a `this+4` subobject sequence at `0x004daeef-0x004daefe` before the `LObject` base initializer call at `0x004daf11`.
- The ordinary destructor clears `g_pMonsterImageLib` after [UID:000370][0x004f4a90-0x004f4a97.LObjectDestructorBody](by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md) at `0x004db0d2`.
- That before-base-construction / after-base-destruction ordering is not the source shape of a normal handwritten statement inside `MonsterImageLib::~MonsterImageLib()`.
- The accepted formal destructor source is therefore `ClearLoadedData(); delete[] m_monsters;`, while the singleton clear remains modeled here as observed compiler-lowered singleton base/static-lifetime cleanup.

## Score Rationale

- Completion `91`: exact singleton storage, current zero-filled initial state, all 22 xrefs, constructor publish/fallback clear, ordinary destructor clear, static cleanup-helper clear, scalar deleting destructor clear, shutdown/cache-clear and representative render/object/UI readers, adjacent singleton separation, exact storage child, and one external CPP definition plus one guarded H extern are documented and routed in accepted source order.
- Confidence `92`: IDA-backed storage/lifecycle evidence, the complete xref set, cross-module linkage requirement, class/file ownership, and the generated definition/extern route agree. The cap remains original lexical certainty and absent rebuilt-binary comparison, not unresolved source placement or declaration shape.

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
- [UID:00017C][0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster](by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md)
- [UID:0001PN][0x0069b440-0x0069b444.g_pMonsterImageLib](by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md)
- [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md)
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md)

## Changes

- 2026-06-30 B011 empty-emitter family implementation callback:
  - Score changed from `86/88` to `88/90`.
  - Evidence: inserted the formal `static MonsterImageLib *g_pMonsterImageLib = NULL;` source definition, documented that [UID:0001PN][0x0069b440-0x0069b444.g_pMonsterImageLib](by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md) is covered by this single definition, and incorporated current MCP evidence that exact storage `0x0069b440` is zero-filled. Preserved constructor/destructor/helper/scalar writes, 22 xrefs, adjacent singleton separation, and rejection of consumer ownership.
- 2026-06-25 B011 destructor implementation callback:
  - Score unchanged at `86/88`.
  - Evidence: added lifecycle clarification for [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md). Observed constructor/destructor/scalar/helper clears remain documented, but the formal destructor C++ must not manually write `g_pMonsterImageLib = 0` because current constructor/destructor ordering indicates compiler-lowered singleton base/static-lifetime cleanup.
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
