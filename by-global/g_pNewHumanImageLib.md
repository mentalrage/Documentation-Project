*** UID:0000RT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
NewHumanImageLib *g_pNewHumanImageLib = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern NewHumanImageLib *g_pNewHumanImageLib;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pNewHumanImageLib

## ObjectStatusBlob full-parser read

- Full child UID0004LL reads this canonical singleton pointer at `0x0067a760`. The pointed NewHumanImageLib owns the `HAIRCOL.TBL` byte vector with begin/end at object `+0x54/+0x58`; when ObjectStatusBlob hair id is in range, its entry offsets the low five bits of hair color modulo 32 while upper three bits are retained.
- Address `0x0067a760` is therefore not a standalone or generic appearance-remap table. Any historical use of `dword_67A760` for that generic role is superseded, while the observed remap behavior remains retained as a NewHumanImageLib member-vector operation.
- NewHuman composition also consumes ObjectStatusBlob decimal `+34` mode, `+44/+46/+48` riding fields, and `+50..+62` colors. Parser ownership remains UID00009S/UID0000M6. Existing singleton owner/emitter, score, vtable/lifecycle, and other consumers remain unchanged.


## Status

- Confidence: strong for address and owner, medium for final original symbol spelling.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md), saved IDA label `g_pNewHumanImageLib`.
- Canonical owner: [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) in [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
- Project symbol: `g_pNewHumanImageLib`; saved IDA storage name: `g_pNewHumanImageLib`.

## Meaning

`g_pNewHumanImageLib` is the global pointer to the newer table-driven human sprite composition library. New-human render, bounds, look/profile, and composition paths read it before resolving `Motion.tbl`, `Layer.tbl`, `Part.tbl`, per-part descriptor tables, `acc2drw.tbl`, `HAIRCOL.TBL`, and part EPF frame archives.

Keep this global with `render/NewHumanImageLib.cpp`. Do not confuse it with the older [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md) singleton at `0x0069b43c`.

## Write Evidence

IDA MCP on 2026-05-26 reports these writes to `0x0067a760`:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004dfd67` | `NewHumanImageLib::NewHumanImageLib` | Stores the constructed `NewHumanImageLib*` singleton. |
| `0x004dfd6e` | `NewHumanImageLib::NewHumanImageLib` | Constructor guard/fallback path clears the singleton. |
| `0x004e059e` | [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) | Clears the singleton during non-deleting cleanup. |
| `0x004e5be0` | [UID:000182][0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper](by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md) | Tiny cleanup helper that clears the singleton. |

The constructor also installs the [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md), initializes the [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md), and loads the new-human table family.

## Consumer Evidence

IDA MCP reports 52 xrefs to `0x0067a760` as of 2026-05-26. Representative readers include:

- `0x004f65f2` in `Application::Shutdown`, which checks the singleton during image-library teardown.
- `0x00424452` / `0x004244b3`, early composition/helper consumers.
- `0x004d23f7`, an old/new human image bridge consumer.
- `0x004fb8ae`, `0x004fd33b`, `0x004fd468`, `0x004fd4fe`, and related `0x004fdxxx` look/profile consumers.
- `0x00520619`, `0x00520697`, `0x0057108e`, and later render/UI consumers.

The [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md) family provides an exact local consumer map. Constructor `0x004fd520` reads the shape count to set `m_maxShapeIndex`; retained steppers `0x004fd6c0`/`0x004fd730` and page methods `0x004fd790`/`0x004fd850` use the count for signed-short slot/page bounds; paint `0x004fda30` calls bounds and draw services. [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) passes the complete packed [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md), a shared NewHumanImageLib-facing H type, rather than raw offsets or an incomplete forward declaration.

## Ownership Decision

`g_pNewHumanImageLib` is source-owned by `NewHumanImageLib`, not by [UID:0000HG][Application](by-file/Application.md), old [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md), look/profile panes, or shared render primitives.

When rebuilding source, preserve this singleton as the canonical global for `0x0067a760` and treat the many composition/read callers as consumers.

The 2026-07-01 accepted empty-emitter callback emits the source-level declaration `NewHumanImageLib *g_pNewHumanImageLib = 0;` from this page.  Exact storage bytes remain documented by [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md) and are not emitted as a duplicate storage definition.

The owner/emitter route to [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) remains correct. The strict child/direct-parent gate clears for the global-to-file relationship because this page is `90/93` and direct parent UID0000LR is `90/89`. The exact storage child [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md) remains `87/92`, with live-backed evidence for zeroed storage, 52 xrefs, lifecycle writes/clears, and shutdown access. The H extern at position 30 follows the complete class; this page's CPP remains the one zero-initialized definition.

## Score Rationale

- Completion `90`: exact singleton storage, 52 xrefs, constructor publish/fallback clear, destructor clear, static cleanup-helper clear, shutdown access, representative render/look/profile consumers, old/new HumanImageLib separation, exact storage-page support, direct file-parent gate clearance, one compile-visible H extern after the complete class, and the sole source-level zero-initialized CPP definition are documented.
- Confidence `93`: existing IDA-backed docs consistently prove the storage, lifecycle, owner, consumer role, null initialization, and declaration/definition route. Confidence stays below final-audit quality because original header/global spelling is inferred and the semantic classification of all 52 xrefs is not complete.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0067a760` is `dword_67A760`, size `4`, in `.data`, with 52 data xrefs.
- Live IDA xrefs confirm constructor writes at `0x004dfd67` and `0x004dfd6e` in `sub_4DFD10`, destructor clear at `0x004e059e` in `sub_4E0250`, singleton clear at `0x004e5be0` in `sub_4E5BE0`, and application shutdown access at `0x004f65f2` in `sub_4F6490`.
- Live IDA xrefs confirm the representative consumer clusters already documented around `0x00424452`, `0x004d23f7`, `0x004fb8ae`, the `0x004fdxxx` look/profile neighborhood, `0x00520619`, `0x0057108e`, and later UI/render functions.
- Live IDA decompilation on 2026-06-05 confirms `0x004dfd10` stores the adjusted object pointer into `dword_67A760` and installs the `NewHumanImageLib` vtable; `0x004e0250` and `0x004e5be0` clear the singleton during cleanup/destruction.
- [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md) remains the canonical memory page for this slot and matches the live IDA check.
- The 52 xrefs are not all semantically classified yet, so completion remains below full despite strong confidence in address and owner.
- 2026-06-16 C001 live IDA refresh in session `b001_mappane_0001AW_20260616` reconfirmed the zero-filled `0x0067a738-0x0067a777` singleton window, the same 52 xrefs, constructor/destructor/helper/shutdown lifecycle sites, and the absence of a function at the adjacent data slot; saved labels `g_pNewHumanImageLib`, `NewHumanImageLib_Constructor`, `NewHumanImageLib_Destructor`, and `ClearNewHumanImageLibSingleton`. The broader `Application::Shutdown` label was dry-run accepted but intentionally skipped because the final source-facing name for that Application method is outside this global batch.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md)
- [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md)
- [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md)
- [UID:00017R][0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster](by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md)
- [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md)
- [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md)
- [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md)
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md)

## Changes

- 2026-08-16 B003 UID0003F8 dependency callback: raised `88/92 -> 90/93`, set H position 30, and added exactly one `extern NewHumanImageLib *g_pNewHumanImageLib;` immediately after the complete UID000092 class. The existing `NewHumanImageLib *g_pNewHumanImageLib = 0;` formal CPP remains the sole storage definition; no duplicate definition, class declaration, or consumer-owned storage was introduced.

- 2026-08-11 B005 UID0000LY consumer synchronization:
  - Added exact selector constructor, retained stepper, page, bounds, and draw consumer roles plus the complete packed HumanImageRenderParams H dependency. Existing score, owner/emitter, storage, and singleton definition remain unchanged.

- 2026-07-01 B011 empty-emitter implementation: raised the global to `88/92` and filled the formal block with the source-level zero-initialized singleton declaration, while leaving exact storage evidence to [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md).
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `88`.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 52 xrefs, lifecycle writes/clears, shutdown access, and representative consumer clusters. Completion remains below full because every consumer xref has not been individually named/classified and final original symbol spelling remains medium confidence.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LR`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067a760` and decompilation/disassembly of `0x004dfd10`, `0x004e0250`, and `0x004e5be0` prove NexusTK-owned `NewHumanImageLib` singleton storage owned by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-10 A001 strict gate repair:
  - Changed completion from `82` to `85`; confidence remains `88`.
  - Summary/evidence: direct parent [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) is `87/85`, this global now documents the singleton lifecycle and owner evidence enough to clear the corrected strict `85/85` assignment gate, and exact storage page [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md) supports the address/lifecycle evidence at `84/90` without being treated as a child-gate pass. The old blank C++ state was superseded by the 2026-07-01 zero-initialized singleton declaration.
- 2026-06-14 A001 storage-child sync:
  - Updated the storage-child note after [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md) moved from `84/90` to `85/90` with live IDA MCP confirmation of the zeroed slot, 52 direct xrefs, constructor/destructor/helper lifecycle writes, and shutdown read. No score, owner, emitter, or final C++ change in this global page.
- 2026-06-16 C001 safe IDA refresh:
  - Changed scores from `85/88` to `87/91`.
  - Summary/evidence: live IDA reconfirmed storage bytes, 52 direct refs, saved singleton data label, saved NewHumanImageLib constructor/destructor/clear-helper labels, lifecycle write/clear sites, adjacent data boundary, and representative consumer classes. Completion remains below final because all 52 consumers are not semantically classified and final field/layout/source declaration names remain open.
