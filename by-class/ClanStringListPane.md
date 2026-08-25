*** UID:00002L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanStringListPane : public ListPane
{
public:
    ClanStringListPane();

    int InsertOrReplaceText(const wchar_t *text);

private:
    int FindText(const wchar_t *text);

protected:
    virtual void DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanStringListPane

## Status

- Confidence: strong for raw constructor-shaped setup, shared list-text helper behavior, shared draw behavior, vtable evidence, and Batch 240 raw-helper ownership; medium for final class declaration details and normal reachability of the raw no-xref helpers.
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
| `FindText(const wchar_t *text)` | [UID:00035F][0x00488760-0x004887c7.ClanStringListPaneFindTextRaw](by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md) | Source-ready retained helper that returns the matching row index for a wide string or `-1`; `FindText` is an inferred/descriptive support-method name, with no-function/no-xref/no-pointer evidence retained as a confidence cap. |
| `DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds)` | [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) | Draws one clan string list row; shared by `ClanStringListPane`, `ClanJoinListPane`, and `ClanEnlistListPane` vtables through the inherited `ListPane` draw slot `+0x80`. |

## Evidence Notes

- 2026-06-05 live IDA refresh of [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md) reconfirms no function object at `0x00488630`, no inbound xrefs to the start/end, exact padding before/after, constructor-shaped bytes ending at `0x00488673`, the shared list-pane base constructor call at `0x004f3a50`, and three `ClanStringListPane` vtable stores.
- 2026-06-10 live IDA refresh of [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md) confirms `sub_488680` size `0xbe`, callers only from [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) at `0x00487b56` and `0x0048807b`, child offsets `0x2514` and `0x2518`, and shared `ListPane` count/get/insert/remove callees.
- 2026-06-10 raw-byte audit splits the formerly ignored `0x00488674-0x004887d0` span into exact padding plus [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md), [UID:00035E][0x00488740-0x00488754.ClanStringListPaneClearRowsRaw](by-memory/0x00488740-0x00488754.ClanStringListPaneClearRowsRaw.md), and [UID:00035F][0x00488760-0x004887c7.ClanStringListPaneFindTextRaw](by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md).
- 2026-06-12 Batch 240 live IDA MCP reconfirmed the two raw clear/find children have no IDA function objects, no ordinary inbound xrefs, exact `ListPane` callees (`0x004f3bd0`/`0x004f3d60` and `0x004f3bd0`/`0x004f3dc0`), exact surrounding padding, and no little-endian VA/RVA pointer-pattern hits for their raw starts. The child pages now clear `85/89` and attach directly to this class; the no-xref status remains a reachability/name caveat, not a file-routing reason.
- 2026-07-03 B005 source-quality implementation reclassifies [UID:00035F][0x00488760-0x004887c7.ClanStringListPaneFindTextRaw](by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md) from blank no-code comment to first-draft `int FindText(const wchar_t *text)`. Current MCP session `3a33af0b` confirms healthy NexusTK IDB state, no function/decompile at `0x00488760`, exact `0x67` / 103-byte retained body, `ListPane` count/get callees `0x004f3bd0` and `0x004f3dc0`, zero inbound code/data xrefs, zero VA/RVA pointer hits, a unique byte signature, padding `0x00488754-0x00488760` and `0x004887c7-0x004887d0`, and successor draw boundary `0x004887d0` size `0xf1`. Route absence remains a confidence cap rather than a no-code proof because the exact body is class-local and source-shaped.
- 2026-06-05 live IDA refresh of [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) reconfirms a function body at `0x004887d0` with size `0xf1`, no direct callers, and vtable-only xrefs at `0x0061572c`, `0x006157f0`, and `0x006158b4`.
- 2026-06-20 Rule 26 incorporation of B001 source-quality research resolves the shared draw source route as first-draft `ClanStringListPane::DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds)`. `ListPane::OnPaint` supplies `(rowIndex, itemPayload, rowBounds)` to vtable slot `+0x80`; this override consumes the item payload as UTF-16 row text.
- The shared draw routine highlights selected rows with background color `128`, uses text color/index `143`, writes GrafPort text draw/background mode byte `+0x88`, truncates a 256-wide-character local buffer with `GrafPort::FitTextAndAppendSuffix(..., L"...", rowBounds->right - 50)`, moves the cursor to `x = 50` and vertical center `((top + bottom) / 2) + 6`, then draws through `GrafPort::DrawWideText`.
- 2026-06-22 B014 PE/Capstone revalidation for [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) confirms the exact `0xf1` / 241-byte body, `ret 0x0c` three-argument thiscall cleanup, `0x004887c7-0x004887d0` and `0x004888c1-0x004888d0` padding boundaries, no direct rel32 or RVA route to the function start, and the three absolute vtable refs at `0x0061572c`, `0x006157f0`, and `0x006158b4`.
- The same B014 pass resolves the class-level draw evidence with source-quality names: `EPFTileContext::InitTileContext`, `ListPane::IsItemSelected(rowIndex)`, selected fill color `128` through the active draw-color helper, `SurfaceRenderCallbackTable` slot `0x0069b3fc` as a fill/invalidation callback rather than the generated `g_pfnLockSurface` name, text color `143`, text draw/background mode byte `+0x88`, a 256-wide-character local copy, fixed text inset `50`, vertical center plus `6`, `GrafPort::FitTextAndAppendSuffix`, and `GrafPort::DrawWideText`.
- Direct helper fan-in remains incompatible with feature-local helper ownership: B014 counted 337 rel32 calls to `0x00457a60`, 26 to `0x004f3f00`, 319 to `0x004b9660`, 258 to `0x004b9680`, 40 to `0x004b9690`, 21 to `0x004ba820`, 218 to `0x004b9600`, 188 to `0x004bab70`, and 206 refs to callback slot `0x0069b3fc`.
- Adjacent function `0x004888d0-0x004888f1` is a `ClanJoinListPane` selected-row action vtable slot, not a generic `ClanStringListPane` method.
- With the constructor, insert/replace, raw clear/find, and draw evidence mapped, this class now clears the semantic parent gate for the fully evidenced children. The no-xref raw clear/find children are assigned here only after their own Batch 240 pages clear `85/85`.

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

- 2026-07-03 B005 UID00035F implementation callback:
  - Added private/support declaration `int FindText(const wchar_t *text);` to the formal class block and updated the method row/evidence from raw no-code wording to source-ready retained helper wording.
  - Evidence: [UID:00035F][0x00488760-0x004887c7.ClanStringListPaneFindTextRaw](by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md) now emits first-draft C++ through this class. The method name is inferred/descriptive, while no-function/no-xref/no-pointer facts from MCP session `3a33af0b` remain documented as confidence caps.
- 2026-06-12 A001 Batch 240 parent refresh:
  - Raised `85/89` to `86/90`.
  - Evidence: live IDA MCP reconfirmed [UID:00035E][0x00488740-0x00488754.ClanStringListPaneClearRowsRaw](by-memory/0x00488740-0x00488754.ClanStringListPaneClearRowsRaw.md) and [UID:00035F][0x00488760-0x004887c7.ClanStringListPaneFindTextRaw](by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md) as exact source-shaped raw helpers in this class cluster, with shared `ListPane` callees, exact padding, empty inbound xrefs, and no raw VA/RVA pointer-pattern hits.
  - Routing: both raw helper children now clear `85/89` and attach directly to this class; the class remains attached to [UID:0000I8][Clan](by-file/Clan.md).
- 2026-06-20 Rule 26 source-quality incorporation:
  - Updated the draw method row and evidence to use the typed first-draft source signature `DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds)`.
  - Evidence: B001 source-quality reanalysis connected the `ListPane` draw-slot call shape, the three shared vtable refs, GrafPort text/draw helper names, Surface callback slot caveat, and the first-draft C++ now populated in [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md).
- 2026-06-22 B014 Rule 26 source-quality incorporation:
  - Raised from `86/90` to `87/90` because the shared draw method now has direct PE/Capstone evidence, first-draft C++ with `rowIndex`/`InitTileContext`, and resolved helper/callback ownership caveats.
  - Evidence: B014 verified the exact body size, padding, no direct caller/RVA route, vtable-only reuse by the string/join/enlist pane slots, helper fan-in counts, and rejection of duplicate `ClanJoinListPane`/`ClanEnlistListPane` draw bodies. Confidence remains `90` because raw constructor/clear/find helper reachability and final class declaration details remain capped.
- What existed before: the page documented shared row drawing, vtable data refs, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `74/82`.
- Summary and evidence: shared renderer behavior and vtable evidence are strong; standalone constructor modeling and final class declaration remain incomplete.
- 2026-05-31: Replaced raw constructor/draw addresses with exact by-memory links. Evidence: IDA MCP `lookup_funcs`, `decompile`, `xrefs_to`, and raw disassembly split the constructor-shaped block and shared draw method into exact child pages.
- 2026-06-05: Raised from `74/82` to `82/88`, attached to [UID:0000I8][Clan](by-file/Clan.md), removed stale recovered-file and issue-note provenance, and promoted [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md) plus [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) from file-parent routing to semantic class parent `00002L`. Evidence: live IDA MCP child refreshes reconfirm the raw constructor-shaped block/no-xref caveat, the exact `0xf1` draw method, vtable-only draw refs, shared draw behavior, adjacent `ClanJoinListPane` action boundary, and the continued no-code rationale below the final-source gate.
- 2026-06-10 A001: Raised from `82/88` to `85/89` after splitting the previously hidden Clan string-list helper cluster out of the `ClanListPaneVirtuals` padding span.
  - What existed before: the class only linked the raw constructor and draw method, while `0x00488680-0x004887c7` was either misattributed to `ArticleListPane` or hidden in a false padding span.
  - Changed to: added [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md), [UID:00035E][0x00488740-0x00488754.ClanStringListPaneClearRowsRaw](by-memory/0x00488740-0x00488754.ClanStringListPaneClearRowsRaw.md), and [UID:00035F][0x00488760-0x004887c7.ClanStringListPaneFindTextRaw](by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md) to the class inventory.
  - Summary/evidence: live IDA MCP confirms `0x00488680` is a real function called only by Clan packet handlers for child offsets `0x2514`/`0x2518`, while `0x00488740` and `0x00488760` are no-xref raw list helpers bounded by exact `0xcc` padding. This clears the class side of the strict `85/85` gate for the insert/replace child while keeping raw no-xref helpers below assignment.
