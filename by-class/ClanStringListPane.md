*** UID:00002L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanStringListPane

## Status

- Confidence: strong for raw constructor-shaped setup, shared list-text helper behavior, shared draw behavior, and vtable evidence; medium for final class declaration details and normal reachability of the raw no-xref helpers.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Memory evidence: [UID:00010I][0x00488610-0x004888f1.ClanListPaneVirtuals](by-memory/0x00488610-0x004888f1.ClanListPaneVirtuals.md), [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md), [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md), [UID:00035E][0x00488740-0x00488754.ClanStringListPaneClearRowsRaw](by-memory/0x00488740-0x00488754.ClanStringListPaneClearRowsRaw.md), [UID:00035F][0x00488760-0x004887c7.ClanStringListPaneFindTextRaw](by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md), [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md), and [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- Parent attachment: attached to [UID:0000I8][Clan](by-file/Clan.md) because the class page and Clan source-layout page are above the parent-attachment gate.

## Class Purpose

`ClanStringListPane` is a small clan string-list base/variant for storing and drawing clan-related strings. Its row insertion/update helper is called by the Clan join/enlist packet handlers, and its row draw implementation is reused by the `ClanJoinListPane` and `ClanEnlistListPane` vtables.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor-shaped block | [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md) | Calls the shared list-pane base constructor and installs `ClanStringListPane` vtables; live IDA reports this is not a function and has no xrefs. |
| `InsertOrReplaceText` | [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md) | Searches existing row text, removes a duplicate row when present, and inserts the incoming wide string; called by Clan join/enlist packet handlers. |
| raw clear-rows helper | [UID:00035E][0x00488740-0x00488754.ClanStringListPaneClearRowsRaw](by-memory/0x00488740-0x00488754.ClanStringListPaneClearRowsRaw.md) | No-xref raw helper that removes all list rows through shared `ListPane` count/remove helpers. |
| raw find-text helper | [UID:00035F][0x00488760-0x004887c7.ClanStringListPaneFindTextRaw](by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md) | No-xref raw helper that returns the matching row index for a wide string or `-1`. |
| `DrawItem` | [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) | Draws one clan string list row; shared by `ClanStringListPane`, `ClanJoinListPane`, and `ClanEnlistListPane` vtables. |

## Evidence Notes

- 2026-06-05 live IDA refresh of [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md) reconfirms no function object at `0x00488630`, no inbound xrefs to the start/end, exact padding before/after, constructor-shaped bytes ending at `0x00488673`, the shared list-pane base constructor call at `0x004f3a50`, and three `ClanStringListPane` vtable stores.
- 2026-06-10 live IDA refresh of [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md) confirms `sub_488680` size `0xbe`, callers only from [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) at `0x00487b56` and `0x0048807b`, child offsets `0x2514` and `0x2518`, and shared `ListPane` count/get/insert/remove callees.
- 2026-06-10 raw-byte audit splits the formerly ignored `0x00488674-0x004887d0` span into exact padding plus [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md), [UID:00035E][0x00488740-0x00488754.ClanStringListPaneClearRowsRaw](by-memory/0x00488740-0x00488754.ClanStringListPaneClearRowsRaw.md), and [UID:00035F][0x00488760-0x004887c7.ClanStringListPaneFindTextRaw](by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md). The raw clear/find helpers have no inbound xrefs and therefore remain below the child assignment gate.
- 2026-06-05 live IDA refresh of [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) reconfirms a function body at `0x004887d0` with size `0xf1`, no direct callers, and vtable-only xrefs at `0x0061572c`, `0x006157f0`, and `0x006158b4`.
- The shared draw routine highlights selected rows with background color `128`, uses text color/index `143`, sets object flag `+0x88`, truncates text with `L"..."` to `right - 50`, and draws at `x = 50` near the row vertical center.
- Adjacent function `0x004888d0-0x004888f1` is a `ClanJoinListPane` selected-row action vtable slot, not a generic `ClanStringListPane` method.
- With the constructor, insert/replace, raw clear/find, and draw evidence mapped, this class now clears the semantic parent gate for the fully evidenced children. The no-xref raw clear/find children stay unassigned until their own child scores clear `85/85`.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00010I][0x00488610-0x004888f1.ClanListPaneVirtuals](by-memory/0x00488610-0x004888f1.ClanListPaneVirtuals.md)
- [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md)
- [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md)
- [UID:00035E][0x00488740-0x00488754.ClanStringListPaneClearRowsRaw](by-memory/0x00488740-0x00488754.ClanStringListPaneClearRowsRaw.md)
- [UID:00035F][0x00488760-0x004887c7.ClanStringListPaneFindTextRaw](by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md)
- [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:00002H][ClanJoinListPane](by-class/ClanJoinListPane.md)
- [UID:00002C][ClanEnlistListPane](by-class/ClanEnlistListPane.md)

## Changes

- What existed before: the page documented shared row drawing, vtable data refs, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `74/82`.
- Summary and evidence: shared renderer behavior and vtable evidence are strong; standalone constructor modeling and final class declaration remain incomplete.
- 2026-05-31: Replaced raw constructor/draw addresses with exact by-memory links. Evidence: IDA MCP `lookup_funcs`, `decompile`, `xrefs_to`, and raw disassembly split the constructor-shaped block and shared draw method into exact child pages.
- 2026-06-05: Raised from `74/82` to `82/88`, attached to [UID:0000I8][Clan](by-file/Clan.md), removed stale recovered-file and issue-note provenance, and promoted [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md) plus [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) from file-parent routing to semantic class parent `00002L`. Evidence: live IDA MCP child refreshes reconfirm the raw constructor-shaped block/no-xref caveat, the exact `0xf1` draw method, vtable-only draw refs, shared draw behavior, adjacent `ClanJoinListPane` action boundary, and the continued no-code rationale below the final-source gate.
- 2026-06-10 A001: Raised from `82/88` to `85/89` after splitting the previously hidden Clan string-list helper cluster out of the `ClanListPaneVirtuals` padding span.
  - What existed before: the class only linked the raw constructor and draw method, while `0x00488680-0x004887c7` was either misattributed to `ArticleListPane` or hidden in a false padding span.
  - Changed to: added [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md), [UID:00035E][0x00488740-0x00488754.ClanStringListPaneClearRowsRaw](by-memory/0x00488740-0x00488754.ClanStringListPaneClearRowsRaw.md), and [UID:00035F][0x00488760-0x004887c7.ClanStringListPaneFindTextRaw](by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md) to the class inventory.
  - Summary/evidence: live IDA MCP confirms `0x00488680` is a real function called only by Clan packet handlers for child offsets `0x2514`/`0x2518`, while `0x00488740` and `0x00488760` are no-xref raw list helpers bounded by exact `0xcc` padding. This clears the class side of the strict `85/85` gate for the insert/replace child while keeping raw no-xref helpers below assignment.
