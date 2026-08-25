*** UID:0000S3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class RankingRewardInfoDialog;

RankingRewardInfoDialog *g_pRankingRewardInfoDialog = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pRankingRewardInfoDialog

## Status

- Address: `0x0067a7e8` (`g_pRankingRewardInfoDialog` in IDA after the 2026-06-16 C001 refresh)
- Symbol kind: process-wide singleton pointer
- Likely owner file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Confidence: strong.

## Purpose

`g_pRankingRewardInfoDialog` guards the active ranking reward-info dialog so the main ranking dialog does not open duplicate reward dialogs.

## Evidence

- 2026-06-16 C001 live IDA MCP recheck confirms `0x0067a7e8` is a zero-filled 4-byte `.data` slot with the same six direct data xrefs; the surrounding `0x0067a7d0-0x0067a7f0` window is also zero-filled.
- IDA labels saved during this pass: `g_pRankingRewardInfoDialog`, `RankingRewardInfoDialog_Constructor`, `ClearRankingRewardInfoDialogSingleton`, and `RankingRewardInfoDialog_ScalarDeletingDestructor`.
- `0x00458a97` in `sub_458A10` checks `g_pRankingRewardInfoDialog` in jump-table case 5; if the singleton is already non-null, execution skips the allocation path. The allocation path pushes `0x278` and calls `sub_4F4AA0`.
- `0x0045dbf7` in `RankingRewardInfoDialog_Constructor` stores the adjusted constructed pointer into `g_pRankingRewardInfoDialog`; the nearby code uses `lea eax, [ecx-26Ch]` and then writes the `RankingRewardInfoDialog` vftables.
- `0x0045dbfe` clears the singleton on the null-adjustment path in the same constructor block.
- `0x0045dd8a` clears the singleton during the constructor/unwind cleanup path; IDA does not currently attach that address to a containing function, but the local window shows `RankingRewardInfoDialog` vftable setup followed by `sub_45F020` cleanup and the clear.
- `0x0045efe0` is the saved `ClearRankingRewardInfoDialogSingleton` helper for this slot.
- `0x0045f0ed` in `RankingRewardInfoDialog_ScalarDeletingDestructor` clears the singleton before running the base destructor and scalar-deleting destructor flag checks.
- 2026-06-30 B006 current MCP request id `2006` reconfirmed the six-data-xref lifecycle set, and request id `2010` reconfirmed the zero-filled neighboring singleton storage.

## Source-Quality Notes

- Owner/emitter remains [UID:0000MZ][RankingDialog](by-file/RankingDialog.md). The singleton is published and cleared by the reward-info dialog class, but its duplicate-open guard and source neighborhood are the ranking dialog module.
- Formal C++ now emits the source-level pointer definition. The exact declaration type is strongly `RankingRewardInfoDialog *`, and the type blocker is resolved by a source-visible forward declaration. The constructor-adjacent clear at `0x0045dd8a` remains important lifecycle evidence even though IDA does not attach it to a modeled function; it is no longer a blocker for the global declaration.
- Skipped unsafe IDA edits: no prototypes, member layouts, locals, or raw function creation were changed; only the backed global/function labels were saved.

## Source Declaration

The global now emits a source-level pointer definition:

```cpp
class RankingRewardInfoDialog;

RankingRewardInfoDialog *g_pRankingRewardInfoDialog = 0;
```

The full `RankingRewardInfoDialog` class declaration is not required for this pointer definition; a forward declaration is enough for the file-level singleton storage. The exact storage row [UID:00028V][0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog](by-memory/0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog.md) is non-emitting duplicate evidence and should not emit a second definition.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000YA][0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper](by-memory/0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper.md)

## Changes

### 2026-07-12 - B002 UID0001ZG lifecycle child sync

- Added exact lifecycle context for [UID:0004I7][0x0045dba0-0x0045dd56.RankingRewardInfoDialogConstructor](by-memory/0x0045dba0-0x0045dd56.RankingRewardInfoDialogConstructor.md), [UID:0004I8][0x0045dd60-0x0045dd9a.RankingRewardInfoDialogConstructorUnwindCleanup](by-memory/0x0045dd60-0x0045dd9a.RankingRewardInfoDialogConstructorUnwindCleanup.md), and [UID:0004IE][0x0045f0c0-0x0045f12c.RankingRewardInfoDialogScalarDeletingDestructor](by-memory/0x0045f0c0-0x0045f12c.RankingRewardInfoDialogScalarDeletingDestructor.md).
- The constructor publishes the `0x278`-byte object, unwind cleanup and the scalar wrapper clear the pointer on their respective failure/destruction paths, and existing UID0000YA remains the exact singleton-clear helper. Score, owner/emitter, and formal pointer definition are unchanged.

- 2026-06-30 B006 narrowed empty-emitter callback:
  - Before: `87/91`, owner/emitter [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), formal C++ blank due declaration/source-placement concerns.
  - Changed to: `88/92`; owner/emitter remain [UID:0000MZ][RankingDialog](by-file/RankingDialog.md); formal C++ now emits `class RankingRewardInfoDialog;` and `RankingRewardInfoDialog *g_pRankingRewardInfoDialog = 0;`.
  - Evidence: current MCP request id `2006` reconfirmed all 6 data xrefs and request id `2010` reconfirmed zero-filled neighboring singleton storage. The previous type blocker is resolved by a source-visible forward declaration; the unmodeled constructor-adjacent clear remains lifecycle evidence, not a blocker for the pointer definition.

- 2026-06-05: Marked reconstructable and attached to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton guard, constructor assignment/fallback, clear helper, and destructor clear to the ranking reward-info dialog inside the ranking dialog module; the parent file is already documented at high confidence. No score change and no reconstruction C++ were added.
- 2026-05-30: What existed before: the page identified the singleton and four important sites but had no completion/confidence score. What changed: set completion/confidence to `84/90` and expanded the xref evidence from live IDA MCP. Summary/evidence: IDA reports a bounded six-xref set for the 4-byte `.data` item, covering duplicate guarding, constructor assignment, null fallback, unwind/helper clearing, and destructor clearing. The score remains below full because one clear site is not attached to an IDA function and the surrounding ranking reward request flow still needs source-level reconstruction elsewhere.
- 2026-06-16 C001 Goal 2 refresh: Raised `84/90` to `87/91` after live IDA reconfirmed zero storage, the six-xref lifecycle set, and decompilation for constructor, clear helper, and scalar deleting destructor. Saved safe IDA labels for the singleton, constructor, clear helper, and scalar deleting destructor; final C++ remains blocked by declaration/source-placement details and the unmodeled constructor-adjacent clear site.
