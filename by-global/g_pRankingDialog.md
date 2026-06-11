*** UID:0000S2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pRankingDialog

## Status

- Address: `0x0067a7e4` (`dword_67A7E4` in IDA)
- Symbol kind: process-wide singleton pointer
- Likely owner file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Confidence: strong.

## Purpose

`g_pRankingDialog` points to the active ranking dialog. The constructor publishes the adjusted dialog pointer, constructor-failure/unwind paths clear it, the scalar deleting destructor clears it again, and ranking child panes use it to reach category/user data through the ranking-dialog subobject.

## Evidence

- Live IDA MCP check on 2026-05-30 confirms `0x0067a7e4` is `dword_67A7E4`, a 4-byte `.data` item with 17 data xrefs; [UID:00028U][0x0067a7e4-0x0067a7e8.g_pRankingDialog](by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md) records the exact storage row.
- Constructor storage is at `0x00458666` in the `0x00458610-0x0045894b` constructor, using `lea eax, [ecx-26Ch]` before assigning the adjusted `RankingDialog` pointer to `dword_67A7E4`; the null fallback at `0x0045866d` clears the singleton when the adjusted pointer is absent.
- `0x0045897a`, `0x00459810`, and `0x0045986d` clear `dword_67A7E4`; the final clear is in the `0x00459840-0x004598ac` scalar deleting destructor path after ranking-dialog vftable/base cleanup and before the destructor flag check.
- Ranking child-pane methods read the singleton and walk into the `+0x26c` member/subobject: `0x0045b089`, `0x0045b333`, `0x0045b4f0`, `0x0045b527`, `0x0045b5cb`, `0x0045dcd9`, `0x0045de2d`, `0x0045e4b0`, `0x0045ea70`, and `0x0045f440`.
- `0x005bd27d` checks whether `dword_67A7E4` is non-null in jump-table case 8 before allocating or showing the ranking dialog.
- `0x0045bd21` is another live read of `dword_67A7E4`; IDA does not currently attach that address to a containing function, so its source-level method name remains unresolved.
- Live IDA decompilation on 2026-06-05 confirms `0x00458610` stores `this` into `dword_67A7E4` and installs the `RankingDialog` vtables; `0x00459810` and `0x00459840` clear the singleton during cleanup/destruction.

## Lifecycle Evidence

| Address | Access | Meaning |
| --- | --- | --- |
| `0x00458666` | write | `RankingDialog` constructor publishes the adjusted dialog pointer to `dword_67A7E4`. |
| `0x0045866d` | clear | Constructor fallback clears the singleton when the adjusted pointer is absent. |
| `0x0045897a` | clear | Constructor-adjacent unwind cleanup clears the published singleton slot. |
| `0x00459810` | clear | [UID:0000Y0][0x00459810-0x0045981a.RankingDialogClearSingletonHelper](by-memory/0x00459810-0x0045981a.RankingDialogClearSingletonHelper.md) performs the compact constructor-unwind clear. |
| `0x0045986d` | clear | Scalar deleting destructor path clears the singleton after ranking-dialog/base cleanup. |
| `0x005bd27d` | read | Command dispatcher case 8 tests whether the ranking dialog already exists. |

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000Y0][0x00459810-0x0045981a.RankingDialogClearSingletonHelper](by-memory/0x00459810-0x0045981a.RankingDialogClearSingletonHelper.md)
- [UID:00028U][0x0067a7e4-0x0067a7e8.g_pRankingDialog](by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md)

## Changes

- 2026-06-06: What existed before: the page had live xref bullets but still sat at `78/86`, lacked the exact data-memory page link, and left the clear sites in prose only. What changed: raised to `84/88`, linked the exact `0x0067a7e4-0x0067a7e8` storage page, normalized raw constructor/destructor labels to address ranges, and added a lifecycle table for constructor publish, fallback/unwind/helper clears, destructor clear, and command-dispatch read. Summary/evidence: [UID:00028U][0x0067a7e4-0x0067a7e8.g_pRankingDialog](by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md) records the zero-initialized four-byte slot, 17 direct data xrefs, constructor publish at `0x00458666`, fallback clear at `0x0045866d`, unwind/helper clears at `0x0045897a` and `0x00459810`, destructor clear at `0x0045986d`, ranking-pane consumers, and dispatcher existence check at `0x005bd27d`.

- 2026-05-30: What existed before: the page identified the global and its broad role but had no completion/confidence score and only a short xref summary. What changed: set completion/confidence to `78/86` and expanded evidence from a live IDA MCP xref pass. Summary/evidence: IDA reports 17 xrefs to the 4-byte `.data` item, covering constructor assignment, fallback clearing, destructor/unwind clearing, child-pane reads through the `+0x26c` ranking subobject, and the command-dispatch existence check at `0x005bd27d`. The score remains below full because several consumer xrefs still need exact source-level method names and the page does not yet document every ranking sub-flow in detail.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000MZ`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067a7e4` and decompilation of `0x00458610`, `0x00459810`, and `0x00459840` prove NexusTK-owned `RankingDialog` singleton storage owned by [UID:0000MZ][RankingDialog](by-file/RankingDialog.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
