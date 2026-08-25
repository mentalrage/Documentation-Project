*** UID:0000S2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class RankingDialog;

RankingDialog *g_pRankingDialog = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pRankingDialog

## Status

- Address: `0x0067a7e4` (`g_pRankingDialog` in current IDA)
- Symbol kind: process-wide singleton pointer
- Likely owner file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Confidence: strong.

## Purpose

`g_pRankingDialog` points to the active ranking dialog. Source-level `Singleton<RankingDialog>` base construction publishes the complete dialog pointer before later member construction; base destruction clears it on constructor failure and normal/scalar teardown. Ranking child panes use the published pointer to reach category/user data through the ranking-dialog object.

## Evidence

- Live IDA MCP check on 2026-05-30 confirms `0x0067a7e4` is `dword_67A7E4`, a 4-byte `.data` item with 17 data xrefs; [UID:00028U][0x0067a7e4-0x0067a7e8.g_pRankingDialog](by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md) records the exact storage row.
- Constructor storage is at `0x00458666` in the `0x00458610-0x0045894b` constructor, using `lea eax, [ecx-26Ch]` before assigning the adjusted `RankingDialog` pointer to `dword_67A7E4`; the null fallback at `0x0045866d` clears the singleton when the adjusted pointer is absent.
- `0x0045897a`, `0x00459810`, and `0x0045986d` clear `dword_67A7E4`. The first is ordinary destructor lowering, the second is the EH-only out-of-line `Singleton<RankingDialog>` base-destructor instantiation, and the third is the scalar deleting wrapper's inlined base-destructor effect before lower-base teardown and delete-flag handling.
- Ranking child-pane methods read the singleton and walk into the `+0x26c` member/subobject: `0x0045b089`, `0x0045b333`, `0x0045b4f0`, `0x0045b527`, `0x0045b5cb`, `0x0045dcd9`, `0x0045de2d`, `0x0045e4b0`, `0x0045ea70`, and `0x0045f440`.
- `0x005bd27d` checks whether `dword_67A7E4` is non-null in jump-table case 8 before allocating or showing the ranking dialog.
- `0x0045bd21` is another live read of `dword_67A7E4`; IDA does not currently attach that address to a containing function, so its source-level method name remains unresolved.
- Live IDA decompilation on 2026-06-05 confirms `0x00458610` stores `this` into `dword_67A7E4` and installs the `RankingDialog` vtables; `0x00459810` and `0x00459840` clear the singleton during cleanup/destruction.
- 2026-06-16 C001 live MCP refresh reconfirmed the zeroed `0x0067a7e0` singleton-adjacent byte window, current IDA name `g_pRankingDialog`, all 17 singleton refs, and the command-dispatch constructor edge (`xrefs_to 0x00458610` reports `0x005bd2ab` from dispatcher `0x005bd000`). That historical pass recorded custom name `RankingDialog_ClearSingletonHelper`; the later UID0000Y0 evidence-time IDB again names it `sub_459810`, and RTTI/EH evidence supersedes the helper identity with `Singleton<RankingDialog>` base destruction. `g_pRankingDialog` remains the accepted source reconstruction name.
- 2026-06-30 B006 current MCP request id `2006` reconfirmed the full 17-data-xref lifecycle set, and request id `2010` reconfirmed zero-filled singleton storage at `0x0067a7e4`.

## Singleton Base Lifetime And Source Route

- Original RTTI proves direct non-virtual `Singleton<RankingDialog>` base descriptor `0x00641b30` at `+0x26c`. The empty base overlaps the category collection at the same displacement through EBO, so no separate guard-storage field exists.
- Constructor `0x00458610` forms the base address, publishes complete `this` at `0x00458666`, executes adjusted-null fallback clear `0x0045866d`, and advances to EH state `1` before constructing the category member and advancing to state `2`.
- `FuncInfo 0x006589ac` / unwind map `0x006589d0` routes state `1` through action `0x005fa138`; that action adjusts `ecx` to `+0x26c` and tail-jumps at `0x005fa141` to non-emitting [UID:0000Y0][0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor](by-memory/0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor.md). State `2` destroys the category collection first through `0x005fa146/0x005fa14f`.
- Exact zero-store bytes occur only at `0x0045866d`, `0x0045897a`, `0x00459810`, and `0x0045986d`, covering adjusted-null fallback, ordinary destruction, constructor EH, and scalar destruction. These are compiler-lowered copies of one source-level base lifetime, not calls to a handwritten clear helper.
- All 17 xrefs remain meaningful: constructor publish/fallback, three destruction clears, ranking event/reward/user consumers, and dispatcher case-8 duplicate-open check. Successful construction leaves the pointer published; any failure after state `1`, ordinary destruction, and scalar deletion clear it.
- Source output remains exactly the existing forward declaration and `RankingDialog *g_pRankingDialog = 0;` definition below. The original source may have expressed backing storage as a template specialization/static member, but no PDB/source symbol proves that spelling. Preserve the accepted name without adding another definition or explicit specialization.
- Rejected alternatives are a class `ClearSingletonHelper`, manual catch/cleanup call, stored RAII guard, late-success publication, and target-local explicit specialization. `Singleton<RankingRewardInfoDialog>` and BrowserDialog are comparator families only; UID0000YA is unchanged.

## Lifecycle Evidence

| Address | Access | Meaning |
| --- | --- | --- |
| `0x00458666` | write | `RankingDialog` constructor publishes the adjusted dialog pointer to `dword_67A7E4`. |
| `0x0045866d` | clear | Constructor fallback clears the singleton when the adjusted pointer is absent. |
| `0x0045897a` | clear | Ordinary destructor lowering destroys the category collection, then inlines the `Singleton<RankingDialog>` base clear before lower-base teardown. |
| `0x00459810` | clear | [UID:0000Y0][0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor](by-memory/0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor.md) is the EH-only out-of-line base-destructor instantiation reached from state-1 action `0x005fa138/0x005fa141`. |
| `0x0045986d` | clear | Scalar deleting wrapper destroys the category collection, inlines the Singleton-base clear, then performs lower-base teardown and delete-flag handling. |
| `0x005bd27d` | read | Command dispatcher case 8 tests whether the ranking dialog already exists. |

## Source Declaration

The global now emits a source-level pointer definition:

```cpp
class RankingDialog;

RankingDialog *g_pRankingDialog = 0;
```

The full `RankingDialog` class declaration is not required for this pointer definition; a forward declaration is enough for the file-level singleton storage. The exact storage row [UID:00028U][0x0067a7e4-0x0067a7e8.g_pRankingDialog](by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md) is non-emitting duplicate evidence and should not emit a second definition.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000Y0][0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor](by-memory/0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor.md)
- [UID:00028U][0x0067a7e4-0x0067a7e8.g_pRankingDialog](by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md)

## Changes

- 2026-07-13 B004 UID0000Y0 Singleton-lifetime sync:
  - Preserved `88/92`, owner/emitter UID0000MZ, reconstructable true, the exact forward declaration/global definition, all 17 refs, and exact storage UID00028U's non-emitting ownership.
  - Corrected ordinary/EH/scalar clear roles; added RTTI direct-base/EBO, constructor states, FuncInfo action route, four exact zero-store copies, source-placement uncertainty, comparator boundary, and rejected helper/catch/guard/late-publication/specialization alternatives.
  - Historicalized `RankingDialog_ClearSingletonHelper` as a prior custom IDA alias. No score, formal C++, global spelling, owner/emitter, or UID0000YA change was made.

- 2026-06-30 B006 narrowed empty-emitter callback:
  - Before: `85/90`, owner/emitter [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), formal C++ blank due source-placement/type concerns.
  - Changed to: `88/92`; owner/emitter remain [UID:0000MZ][RankingDialog](by-file/RankingDialog.md); formal C++ now emits `class RankingDialog;` and `RankingDialog *g_pRankingDialog = 0;`.
  - Evidence: current MCP request id `2006` reconfirmed all 17 data xrefs and request id `2010` reconfirmed zero-filled storage. The previous type blocker is resolved by a source-visible forward declaration; the full `RankingDialog` class body is not needed for a pointer definition.

- 2026-06-06: What existed before: the page had live xref bullets but still sat at `78/86`, lacked the exact data-memory page link, and left the clear sites in prose only. What changed: raised to `84/88`, linked the exact `0x0067a7e4-0x0067a7e8` storage page, normalized raw constructor/destructor labels to address ranges, and added a lifecycle table for constructor publish, fallback/unwind/helper clears, destructor clear, and command-dispatch read. Summary/evidence: [UID:00028U][0x0067a7e4-0x0067a7e8.g_pRankingDialog](by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md) records the zero-initialized four-byte slot, 17 direct data xrefs, constructor publish at `0x00458666`, fallback clear at `0x0045866d`, unwind/helper clears at `0x0045897a` and `0x00459810`, destructor clear at `0x0045986d`, ranking-pane consumers, and dispatcher existence check at `0x005bd27d`.

- 2026-05-30: What existed before: the page identified the global and its broad role but had no completion/confidence score and only a short xref summary. What changed: set completion/confidence to `78/86` and expanded evidence from a live IDA MCP xref pass. Summary/evidence: IDA reports 17 xrefs to the 4-byte `.data` item, covering constructor assignment, fallback clearing, destructor/unwind clearing, child-pane reads through the `+0x26c` ranking subobject, and the command-dispatch existence check at `0x005bd27d`. The score remains below full because several consumer xrefs still need exact source-level method names and the page does not yet document every ranking sub-flow in detail.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000MZ`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067a7e4` and decompilation of `0x00458610`, `0x00459810`, and `0x00459840` prove NexusTK-owned `RankingDialog` singleton storage owned by [UID:0000MZ][RankingDialog](by-file/RankingDialog.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-16 C001 Goal 2 global/source-quality refresh:
  - Before: `84/88`, with strong singleton evidence but below the refreshed global gate and stale generated-name wording.
  - Changed to: `85/90`; owner/emitter remain [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), and reconstruction C++ remains blank.
  - Summary/evidence: live MCP reconfirmed current zero bytes, `g_pRankingDialog` IDA name, all 17 refs, dispatcher constructor reachability, and the already-saved ranking singleton helper names. Remaining blockers are source-quality field/helper names, unresolved function ownership for a few child-pane reads, and final generated-source cleanup for unrelated helper pollution.
