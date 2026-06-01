*** UID:0000S2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

`g_pRankingDialog` points to the active ranking dialog. The constructor stores `this`, the scalar deleting destructor clears it, and ranking child panes use it to reach category/user data.

## Evidence

- Live IDA MCP check on 2026-05-30 confirms `0x0067a7e4` is `dword_67A7E4`, a 4-byte `.data` item with 17 data xrefs.
- Constructor storage is at `0x00458666` in `sub_458610`, using `lea eax, [ecx-26Ch]` before assigning the adjusted `RankingDialog` pointer to `dword_67A7E4`; the null fallback at `0x0045866d` clears the singleton when the adjusted pointer is absent.
- `0x0045897a`, `0x00459810`, and `0x0045986d` clear `dword_67A7E4`; the latter is in `sub_459840`, after ranking-dialog vftable/base cleanup and before the scalar-deleting destructor flag check.
- Ranking child-pane methods read the singleton and walk into the `+0x26c` member/subobject: `0x0045b089`, `0x0045b333`, `0x0045b4f0`, `0x0045b527`, `0x0045b5cb`, `0x0045dcd9`, `0x0045de2d`, `0x0045e4b0`, `0x0045ea70`, and `0x0045f440`.
- `0x005bd27d` checks whether `dword_67A7E4` is non-null in jump-table case 8 before allocating or showing the ranking dialog.
- `0x0045bd21` is another live read of `dword_67A7E4`; IDA does not currently attach that address to a containing function, so its source-level method name remains unresolved.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000Y0][0x00459810-0x0045981a.RankingDialogClearSingletonHelper](by-memory/0x00459810-0x0045981a.RankingDialogClearSingletonHelper.md)

## Changes

- 2026-05-30: What existed before: the page identified the global and its broad role but had no completion/confidence score and only a short xref summary. What changed: set completion/confidence to `78/86` and expanded evidence from a live IDA MCP xref pass. Summary/evidence: IDA reports 17 xrefs to the 4-byte `.data` item, covering constructor assignment, fallback clearing, destructor/unwind clearing, child-pane reads through the `+0x26c` ranking subobject, and the command-dispatch existence check at `0x005bd27d`. The score remains below full because several consumer xrefs still need exact source-level method names and the page does not yet document every ranking sub-flow in detail.
