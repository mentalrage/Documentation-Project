*** UID:0000RT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pNewHumanImageLib

## Status

- Confidence: strong for address and owner, medium for final original symbol spelling.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md), IDA `dword_67A760`.
- Canonical owner: [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) in [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
- Project symbol: `g_pNewHumanImageLib`; IDA storage name: `dword_67A760`.

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

## Ownership Decision

`g_pNewHumanImageLib` is source-owned by `NewHumanImageLib`, not by [UID:0000HG][Application](by-file/Application.md), old [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md), look/profile panes, or shared render primitives.

When rebuilding source, preserve this singleton as the canonical global for `0x0067a760` and treat the many composition/read callers as consumers.

`AUTOGEN_PARENT_UID:0000LR` remains the correct file assignment. The strict child/direct-parent gate clears for the global-to-file relationship because this page is now `85/88` and direct parent [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) is `87/85`. The exact storage child [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md) is strong supporting evidence at `84/90`, but it remains below 85 completion and is not used as a child-gate claim.

## Score Rationale

- Completion `85`: exact singleton storage, 52 xrefs, constructor publish/fallback clear, destructor clear, static cleanup-helper clear, shutdown access, representative render/look/profile consumers, old/new HumanImageLib separation, exact storage-page support, and direct file-parent gate clearance are documented.
- Confidence `88`: existing IDA-backed docs consistently prove the storage, lifecycle, owner, and consumer role. Confidence stays below final-audit quality because the final original symbol spelling and semantic classification of all 52 xrefs remain open.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0067a760` is `dword_67A760`, size `4`, in `.data`, with 52 data xrefs.
- Live IDA xrefs confirm constructor writes at `0x004dfd67` and `0x004dfd6e` in `sub_4DFD10`, destructor clear at `0x004e059e` in `sub_4E0250`, singleton clear at `0x004e5be0` in `sub_4E5BE0`, and application shutdown access at `0x004f65f2` in `sub_4F6490`.
- Live IDA xrefs confirm the representative consumer clusters already documented around `0x00424452`, `0x004d23f7`, `0x004fb8ae`, the `0x004fdxxx` look/profile neighborhood, `0x00520619`, `0x0057108e`, and later UI/render functions.
- Live IDA decompilation on 2026-06-05 confirms `0x004dfd10` stores the adjusted object pointer into `dword_67A760` and installs the `NewHumanImageLib` vtable; `0x004e0250` and `0x004e5be0` clear the singleton during cleanup/destruction.
- [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md) remains the canonical memory page for this slot and matches the live IDA check.
- The 52 xrefs are not all semantically classified yet, so completion remains below full despite strong confidence in address and owner.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:00017R][0x004dfd10-0x004e68a8.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a8.NewHumanImageLib.md)
- [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md)
- [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md)
- [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md)
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `88`.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 52 xrefs, lifecycle writes/clears, shutdown access, and representative consumer clusters. Completion remains below full because every consumer xref has not been individually named/classified and final original symbol spelling remains medium confidence.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LR`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067a760` and decompilation/disassembly of `0x004dfd10`, `0x004e0250`, and `0x004e5be0` prove NexusTK-owned `NewHumanImageLib` singleton storage owned by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-10 A001 strict gate repair:
  - Changed completion from `82` to `85`; confidence remains `88`.
  - Summary/evidence: direct parent [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) is `87/85`, this global now documents the singleton lifecycle and owner evidence enough to clear the corrected strict `85/85` assignment gate, and exact storage page [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md) supports the address/lifecycle evidence at `84/90` without being treated as a child-gate pass. C++ remains blank below the final `95/95` gate.
