** TARGET-REPORT-UID:0003VH **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003VH **
# 0003VH ArgumentedMenuMenuItemListRawAppendEntryHelper Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003VH] owned/emitted by [UID:00000I] `ArgumentedMenuMenuItemList`; update the target from `85/86` to `88/89`; replace the stale no-C++ blocker with a current source-quality analysis and first-draft C++.
- Final disposition: reconstructable raw out-of-line class helper. It has no direct start refs, but its row-building body has a live inline analogue inside the argumented-menu constructor at `0x0051ed05-0x0051ed79`, and the shared row consumers prove the source-level shape.
- Required action: update the target by-memory page, `by-class/ArgumentedMenuMenuItemList.md`, and the relevant argumented-menu support docs with the row layout and helper signature. Do not edit `by-memory/-coverage-report.md`; use the exact replacement row in this report.
- Confidence: strong for range, behavior, owner/emitter route, row layout, and first-draft C++ readiness; capped below final audit by the missing IDA function object, no direct raw-start refs, and inferred/descriptive source names.

## Target

- Target UID: `0003VH`
- Target path: `source-3/project-documentation/by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0003VH-ArgumentedMenuMenuItemListRawAppendEntryHelper-source-quality.md`
- Current target state: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:00000I`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000I`, blank formal C++.
- Current generated route: `0003VH -> 00000I ArgumentedMenuMenuItemList -> 0000HI ArgumentedMenuDialogs -> auto-generated/NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp`.

## Evidence Checked

- Target doc [UID:0003VH].
- Support docs: [UID:00000I] `by-class/ArgumentedMenuMenuItemList.md`, [UID:0000HI] `by-file/ArgumentedMenuDialogs.md`, [UID:0001BS] `by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md`, sibling list-tail pages [UID:0003VF]-[UID:0003VO], [UID:000320] `ArgumentedMenuDialogVtables.md`, [UID:0001Y5] `MerchantMenuDialogVtableFamily.md`, [UID:00007A] `ListPane`, [UID:0000KT] `ListPane`, and [UID:0003U0] `ListPaneItemSelectionStorageHelpers`.
- Sibling row precedents: [UID:0001BP] `ServerItemMenuItemList` and [UID:0001BQ] `ClientItemMenuItemList`.
- Coverage/generated state: `by-memory/-coverage-report.md` current row for [UID:0003VH], `auto-generated/-ag-memory-coverage.md`, and `project-level/-auto-completion-stats.md`.
- Existing B001 tail split report `Agent-B001/research/executed/older/0001BS-argumented-menu-dialogs-tail-split.md`.
- Local byte/disassembly evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x00400000`, using a local PE parser and Capstone. IDA MCP was attempted at `http://127.0.0.1:13337/mcp` and was not reachable in this session, so current-session live IDA calls were unavailable. Existing docs still preserve B001's live IDA MCP no-function/xref findings from 2026-06-16.

## Raw Facts And Range

- Exact target range remains `0x0051f3c0-0x0051f44e` half-open.
- Predecessor bytes:
  - `0x0051f380-0x0051f3b5` is the existing ignored duplicate non-deleting destructor body ending with a jump to `0x004f3b60`.
  - `0x0051f3b5-0x0051f3c0` is `0xcc` padding.
- Successor bytes:
  - `0x0051f44e-0x0051f450` is two `0xcc` padding bytes.
  - `0x0051f450` starts [UID:0003VI] `ArgumentedMenuOpenBuyConfirmDialog`.
- Target prologue/body:
  - Stack-cookie frame with `sub esp, 0x414`.
  - Builds a stack row record at `[ebp-0x414]`.
  - Copies two wide strings with `_wcscpy_s` at `0x005cd657`, each with capacity `0x100`.
  - Calls `0x004f3c50` at `0x0051f437`.
  - Returns with `ret 0x1c`, so the helper has seven stack arguments.
- Local scan found no absolute VA, RVA, `E8/E9 rel32`, or `0F 8x rel32` references to `0x0051f3c0`. This agrees with B001's IDA MCP `xrefs_to` and raw pointer scan.

## Source-Facing Name And Signature

Best source-facing name:

```cpp
void ArgumentedMenuMenuItemList::AppendItem(
    unsigned short itemId,
    unsigned char itemStyle,
    unsigned int price,
    const wchar_t *name,
    const wchar_t *description,
    unsigned int argumentId,
    unsigned char maxQuantity)
```

Confidence:

- `AppendItem` is inferred/descriptive, not original-name proof. It matches the sibling `ServerItemMenuItemList::AppendItem` source-quality precedent and the target's direct role as an inherited `ListPane::AddEntry` wrapper.
- Argument order is confirmed by raw stack reads:
  - `[ebp+0x08]` -> row `+0x000` word.
  - `[ebp+0x0c]` -> row `+0x002` byte.
  - `[ebp+0x10]` -> row `+0x004` dword.
  - `[ebp+0x14]` -> row `+0x008` wide string.
  - `[ebp+0x18]` -> row `+0x208` wide string.
  - `[ebp+0x1c]` -> row `+0x408` dword.
  - `[ebp+0x20]` byte -> zero-extended row `+0x40c` dword.
- Return type should be `void`: `ListPane::AddEntry` returns with stack cleanup, and the wrapper has no meaningful return write.

## Row Record Layout

Recommended descriptive type name: `ArgumentedMenuItemEntry`.

```cpp
struct ArgumentedMenuItemEntry
{
    unsigned short itemId;          // +0x000
    unsigned char itemStyle;        // +0x002
    unsigned int price;             // +0x004
    wchar_t name[0x100];            // +0x008
    wchar_t description[0x100];     // +0x208
    unsigned int argumentId;        // +0x408
    unsigned int maxQuantity;       // +0x40c
};
```

Evidence:

- [UID:0003VF] constructor passes `0x410` as the `ListPane` row stride, so the record is `0x410` bytes.
- Target [UID:0003VH] writes a word at `+0x000`, byte at `+0x002`, dword at `+0x004`, first string at `+0x008`, second string at `+0x208`, dword at `+0x408`, and zero-extended byte/dword at `+0x40c`.
- [UID:0003VK] selection update fetches selected row and passes `row+0x208` into owner control id `7`, so the second copied string is the detail/description text.
- [UID:0003VN] item-help path passes `row+0x008` to `ItemHelpPane`, so the first copied string is the display/help name text.
- [UID:0003VO] draw method uses:
  - `word [row+0x000]` and `byte [row+0x002]` for item-image lookup/draw helpers.
  - `row+0x008` for row name text, with ellipsis fitting.
  - `row+0x40c` formatted with `L"%d"` for quantity/count display.
  - `row+0x004` formatted with `L"%u"` for price/value display, with comma insertion and `L"1gold "` prefix behavior when `row+0x40c > 1`.
- [UID:0003VI] buy-confirm helper passes `row+0x40c`, `row+0x004`, and `row+0x408` into the confirm dialog constructor.
- [UID:0003VJ] quantity helper treats the first argument as a count/quantity gate and the second argument as the item argument id passed onward to [UID:0003VL].
- [UID:0003VL] packet helper serializes its first stack argument as a dword argument id and its second stack argument as a byte quantity after opcode `0x39`, context byte/dword/word fields, and subcommand `1`.
- Live inline row construction inside [UID:0002TW] at `0x0051ed05-0x0051ed79` writes the same offsets and calls `0x004f3c50`, proving the row layout is not just a no-route wrapper artifact.

Uncertainty:

- `itemStyle`, `price`, `argumentId`, and `maxQuantity` are descriptive names. The original source names are not recovered.
- The byte parsed into the display name through `L"(%d%%)"` at `0x0051ecc1-0x0051ecf3` is not stored as its own row field by [UID:0003VH]; it decorates the display string before insertion. Do not model a separate row `percent` field unless another source path proves it.
- The row has natural padding after `itemStyle`. The binary does not clear that padding, which is consistent with ordinary stack local struct assignment.

## Shared List Append Helper

`0x004f3c50` should be documented/used as:

```cpp
void ListPane::AddEntry(const void *entry);
```

or the existing project spelling `ListPane::AppendItem`/`ListPane::AddEntry` if one is later selected globally.

Evidence:

- [UID:0003U0] identifies `0x004f3c50-0x004f3ca4` as the modeled `ListPane` append helper.
- Disassembly of `0x004f3c50`:
  - Reads primary list pointer at `this+0x130`.
  - Uses `primaryList->count` as tail index.
  - Inserts the caller's entry pointer into the primary list.
  - Inserts a cleared byte into the parallel selection list at `this+0x138`.
  - Calls scroll/viewport sync `0x0055e990`.
  - Dispatches the invalidation/content update virtual through vtable slot `+0x20` with `this+0x110`.
  - Returns with `ret 4`.
- Cross-feature refs to `0x004f3c50` include item menus, argumented menus, chat-color lists, exchange/mix helpers, and menu-question raw rows, confirming generic `ListPane` ownership rather than an argumented-menu-local helper.

## Liveness / No-Xref Reanalysis

The raw start `0x0051f3c0` has no direct refs. That should stay in the target as a confidence caveat, but it is not a no-code proof.

Best interpretation:

- `0x0051f3c0` is a retained out-of-line source method for appending one argumented menu row.
- The observed live row insertion in the dialog constructor builds the same record inline and calls `ListPane::AddEntry` at `0x0051ed79`. This strongly suggests the source had an append helper whose call was inlined into the constructor, while an out-of-line copy remained in the object/binary.
- Sibling item-menu raw appenders show the same project pattern. [UID:0001BP] now emits first-draft source despite raw no-function/no-direct-xref helper starts because the class row layout and consumers are proven. [UID:0001BQ] records equivalent raw helper caveats for the client item list.

Rejected interpretations:

- Padding: rejected. The body has a valid stack-cookie function prologue, secure wide-string copies, field writes, `ListPane::AddEntry`, cookie check, and `ret 0x1c`.
- Compiler thunk/glue: rejected. The body performs source-level row construction and string copies; it is not an adjustor, scalar deleting destructor, or alias jump.
- Generic `ListPane` helper: rejected. It consumes argumented-menu row fields and belongs to the `ArgumentedMenuMenuItemList` class context.
- `ArgumentedItemInputDialogs` owner: rejected. Input dialogs consume/call list-context helpers later, but this helper appends rows to the menu list and has no input-pane object state.
- Hard no-code/no-emits: rejected. The target is `RECONSTRUCTABLE:TRUE`, has a valid emitter route, clears the current combined score gate after this pass, and has a source-quality helper shape.

## First-Draft C++ Recommendation

Populate target formal C++ after supervisor acceptance. This is mid-2000s source-style C++ and avoids decompiler temporaries.

Recommended support type declaration, preferably in `ArgumentedMenuMenuItemList` class/support documentation or a future row-layout type page:

```cpp
struct ArgumentedMenuItemEntry
{
    unsigned short itemId;
    unsigned char itemStyle;
    unsigned int price;
    wchar_t name[0x100];
    wchar_t description[0x100];
    unsigned int argumentId;
    unsigned int maxQuantity;
};
```

Recommended target method body:

```cpp
void ArgumentedMenuMenuItemList::AppendItem(
    unsigned short itemId,
    unsigned char itemStyle,
    unsigned int price,
    const wchar_t *name,
    const wchar_t *description,
    unsigned int argumentId,
    unsigned char maxQuantity)
{
    ArgumentedMenuItemEntry entry;

    entry.itemId = itemId;
    entry.itemStyle = itemStyle;
    entry.price = price;
    wcscpy_s(entry.name, _countof(entry.name), name);
    wcscpy_s(entry.description, _countof(entry.description), description);
    entry.argumentId = argumentId;
    entry.maxQuantity = maxQuantity;

    AddEntry(&entry);
}
```

Notes:

- Do not add `name != NULL ? name : L""` guards; the binary passes the source pointers directly to `_wcscpy_s`.
- Do not zero-initialize the local struct in the target draft; the binary has no memset/zero-init sequence and leaves natural padding uninitialized.
- If implementation does not yet have a shared row type location, the target page may include the struct declaration in the draft block as temporary source-support. Prefer a class/type support declaration later to avoid duplicate row-struct definitions when [UID:0003VK], [UID:0003VN], [UID:0003VO], and [UID:0003VL] receive C++.

## Metadata / Score Recommendation

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:00000I
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00000I
```

Rationale:

- Completion improves because the report resolves the row-record layout, argument order, two string roles, shared append helper signature, live inline row-construction analogue, source name/signature recommendation, owner/source route, and first-draft C++ readiness.
- Confidence improves because local byte-level disassembly and existing IDA-backed docs agree on the target range and no-xref status, while independent consumers prove the row fields.
- Confidence stays below `90+`/final audit because IDA MCP was not live in this session, the raw start still has no direct route, the original method and field names are inferred, and sibling [UID:0003VG] has a support-range correction pending.

## Support Doc Updates Recommended

Do not apply these until supervisor implementation callback.

1. `by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md`
   - Change score to `88/89`.
   - Keep owner/emitter [UID:00000I], reconstructable true.
   - Replace stale "Final C++ remains blank pending original helper and row-record names" with current gate analysis: target clears the active combined-score/emitter route and is first-draft C++ ready.
   - Add exact row layout, argument order, `ListPane::AddEntry` role, no-xref caveat, and inline row-construction evidence at `0x0051ed05-0x0051ed79`.
   - Add the first-draft C++ above.

2. `by-class/ArgumentedMenuMenuItemList.md`
   - Add `ArgumentedMenuItemEntry` layout:
     - `+0x000 itemId`
     - `+0x002 itemStyle`
     - `+0x004 price`
     - `+0x008 name[0x100]`
     - `+0x208 description[0x100]`
     - `+0x408 argumentId`
     - `+0x40c maxQuantity`
   - Update [UID:0003VH] method-map role to `AppendItem` / raw retained out-of-line append helper.
   - Document that the first copied string is display/help name text and the second copied string is owner description/control text.
   - Document that no direct refs to `0x0051f3c0` remain, but the same row construction appears inline at `0x0051ed05-0x0051ed79`.
   - Consider raising class score only if related sibling pages are also updated; current `87/89` can remain if only [UID:0003VH] is updated.

3. `by-file/ArgumentedMenuDialogs.md`
   - Add row-layout/source-quality note under `ArgumentedMenuMenuItemList`.
   - Replace old file-root C++ blocker wording that mentions a `95/95` gate with the current combined-score/emitter policy where relevant. The file root can remain an empty marker/bucket until child code is populated.

4. `by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md`
   - Add the inline row construction at `0x0051ed05-0x0051ed79` as evidence for [UID:0003VH] and for the row layout.
   - Keep the aggregate non-emitting.

5. `by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md`
   - Add row-field names used by the draw path if accepted: item id/style, name, price, quantity/count, and `1gold` price-prefix behavior for `maxQuantity > 1`.

6. `by-memory/0x0051f5b0-0x0051f63d.ArgumentedMenuMenuItemListSelectItemAndUpdateText.md`
   - Add `row+0x208` as `description`, written to owner text/control id `7`.

7. `by-memory/0x0051f720-0x0051f840.ArgumentedMenuMenuItemListHandleMouseEvent.md`
   - Add `row+0x008` as `name` / item-help display text.

8. `by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md`
   - Add `argumentId` and quantity/maxQuantity naming bridge from row fields.

9. `by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md` and `by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md`
   - Add field names for selected-row `price`, `argumentId`, and `maxQuantity`.

10. Incidental split-support correction, if supervisor widens scope:
    - Current [UID:0003VG] `0x0051f310-0x0051f37a` appears two bytes short. Local bytes show `ret 0x10` at `0x0051f379-0x0051f37b` and padding begins at `0x0051f37c`, so the exact half-open body should be `0x0051f310-0x0051f37c`, with padding `0x0051f37c-0x0051f380`.
    - Affected support docs/rows: [UID:0003VG] filename/title/range, [UID:0001BS], `by-memory/-ignored.md`, and the sibling rows in `by-memory/-coverage-report.md`.
    - This does not change [UID:0003VH]'s range.

## Exact Supervisor-Owned Coverage Row

Replace only the [UID:0003VH] row in `by-memory/-coverage-report.md` if the supervisor accepts this report and leaves the wider sibling range correction for a separate callback:

```text
        - [UID:0003VH][0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper](by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md) 0x0051f3c0-0x0051f44e | raw class helper | ArgumentedMenuMenuItemListRawAppendEntryHelper : reconstructable : 88% : strong : Raw retained out-of-line `ArgumentedMenuMenuItemList::AppendItem` helper; local disassembly and B001 IDA evidence show a stack-cookie frame, seven-argument `ret 0x1c` signature, `0x410` row-record construction, two `_wcscpy_s` copies into `name[0x100]` and `description[0x100]`, fields `itemId/itemStyle/price/argumentId/maxQuantity`, `ListPane::AddEntry` call at `0x004f3c50`, and no direct raw-start refs. Live inline row construction at `0x0051ed05-0x0051ed79`, draw/selection/help/packet consumers, and sibling item-menu appenders make first-draft C++ ready; original helper/field names remain inferred.
```

If the supervisor also accepts the incidental [UID:0003VG] range correction, then the neighboring `0003VG` and ignored padding coverage rows must be adjusted from `0x0051f310-0x0051f37a` / `0x0051f37a-0x0051f380` to `0x0051f310-0x0051f37c` / `0x0051f37c-0x0051f380`. Do not apply that from this report unless the callback explicitly includes it.

## Validation Commands Needed

Run from `source-3/project-documentation` after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0003VH-ArgumentedMenuMenuItemListRawAppendEntryHelper-source-quality-removed.md](0003VH-ArgumentedMenuMenuItemListRawAppendEntryHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the formal C++ block changes generated output, run:

> Executable block R002 was removed from this report and preserved verbatim in [0003VH-ArgumentedMenuMenuItemListRawAppendEntryHelper-source-quality-removed.md](0003VH-ArgumentedMenuMenuItemListRawAppendEntryHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor includes the [UID:0003VG] range correction, validate the renamed/updated [UID:0003VG] target, [UID:0001BS], `by-memory/-ignored.md`, and all affected references.

## IDA Rename / Type / Comment Recommendations

- Rename/comment raw `0x0051f3c0` as descriptive `ArgumentedMenuMenuItemList::AppendItem` or `ArgumentedMenuMenuItemList_AppendItem_RawNoRefs`.
- Apply or record type:
  ```cpp
  void __thiscall ArgumentedMenuMenuItemList::AppendItem(
      unsigned short itemId,
      unsigned char itemStyle,
      unsigned int price,
      const wchar_t *name,
      const wchar_t *description,
      unsigned int argumentId,
      unsigned char maxQuantity);
  ```
- Define row struct as `ArgumentedMenuItemEntry`, size `0x410`.
- Rename/comment `0x004f3c50` as `ListPane::AddEntry(const void *entry)` if no better canonical local spelling exists.
- Comment `0x0051ed79` in [UID:0002TW] as live inline construction of the same `ArgumentedMenuItemEntry` layout.
- Comment `0x0051f437` as inherited `ListPane::AddEntry(&entry)`.
- Comment [UID:0003VG] range issue for supervisor review: `ret 0x10` occupies `0x0051f379-0x0051f37b`; padding begins at `0x0051f37c`.

## Remaining Issues / Impact

- IDA MCP was unavailable in this session; I used existing IDA-backed docs and local binary disassembly. The report should be considered strong, but a live IDA MCP recheck during implementation would be useful if the endpoint is restored.
- Original source names are not proven. `AppendItem`, `ArgumentedMenuItemEntry`, `itemStyle`, `price`, `argumentId`, and `maxQuantity` are best descriptive names supported by consumers.
- [UID:0003VG] likely has a two-byte range truncation. This does not affect [UID:0003VH]'s range or source shape but should be corrected in a support callback.
- The row struct should eventually move to one canonical support/type location so future C++ for draw/selection/packet helpers does not duplicate the declaration.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0003VH-ArgumentedMenuMenuItemListRawAppendEntryHelper-source-quality.md`
- Modified: none outside the B004 research folder.
- `by-memory/-coverage-report.md`: not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003VH","source_path":"executed-b-agent-research/B004/0003VH-ArgumentedMenuMenuItemListRawAppendEntryHelper-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
