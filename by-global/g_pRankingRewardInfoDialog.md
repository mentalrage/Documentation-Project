*** UID:0000S3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pRankingRewardInfoDialog

## Status

- Address: `0x0067a7e8` (`dword_67A7E8` in IDA)
- Symbol kind: process-wide singleton pointer
- Likely owner file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Confidence: strong.

## Purpose

`g_pRankingRewardInfoDialog` guards the active ranking reward-info dialog so the main ranking dialog does not open duplicate reward dialogs.

## Evidence

- Live IDA MCP check on 2026-05-30 confirms `0x0067a7e8` is `dword_67A7E8`, a 4-byte `.data` item with six data xrefs.
- `0x00458a97` in `sub_458A10` checks `dword_67A7E8` in jump-table case 5; if the singleton is already non-null, execution skips the allocation path. The allocation path pushes `0x278` and calls `sub_4F4AA0`.
- `0x0045dbf7` in `sub_45DBA0` stores the adjusted constructed pointer into `dword_67A7E8`; the nearby code uses `lea eax, [ecx-26Ch]` and then writes the `RankingRewardInfoDialog` vftables.
- `0x0045dbfe` clears the singleton on the null-adjustment path in the same constructor block.
- `0x0045dd8a` clears the singleton during the constructor/unwind cleanup path; IDA does not currently attach that address to a containing function, but the local window shows `RankingRewardInfoDialog` vftable setup followed by `sub_45F020` cleanup and the clear.
- `0x0045efe0` is the tiny clear helper for `dword_67A7E8`.
- `0x0045f0ed` in `sub_45F0C0` clears the singleton before running the base destructor and scalar-deleting destructor flag checks.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000YA][0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper](by-memory/0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper.md)

## Changes

- 2026-06-05: Marked reconstructable and attached to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton guard, constructor assignment/fallback, clear helper, and destructor clear to the ranking reward-info dialog inside the ranking dialog module; the parent file is already documented at high confidence. No score change and no reconstruction C++ were added.
- 2026-05-30: What existed before: the page identified the singleton and four important sites but had no completion/confidence score. What changed: set completion/confidence to `84/90` and expanded the xref evidence from live IDA MCP. Summary/evidence: IDA reports a bounded six-xref set for the 4-byte `.data` item, covering duplicate guarding, constructor assignment, null fallback, unwind/helper clearing, and destructor clearing. The score remains below full because one clear site is not attached to an IDA function and the surrounding ranking reward request flow still needs source-level reconstruction elsewhere.
