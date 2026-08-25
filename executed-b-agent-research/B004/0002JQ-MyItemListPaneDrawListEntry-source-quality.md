** TARGET-REPORT-UID:0002JQ **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0002JQ MyItemListPaneDrawListEntry Source-Quality Report

## Assignment And Provenance

- Assignment: `B004-report-0002JQ-MyItemListPaneDrawListEntry-20260702`
- Original mode: report-only research for supervisor validation. Callback implementation has now applied the accepted details to by-* docs; see the ledger, checklist, and validator results below.
- Target: `by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md`
- Current target metadata at assignment time: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000LO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LO`.
- Required skill used: project-level `ntk-b-agent-workflow`.
- Required references used: `b-agent-research-and-implementation-workflow.md`, `score-blocker-audit-standard.md`, and project `by-structure.md` guidance relevant to B-agent reports, MCP evidence, ownership, emitters, C++ gates, and no-child/split discipline.
- IDA MCP status: available and healthy. Active database `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`.
- MCP schema note: current server tools require plural `addrs` for `xrefs_to`/`callees`; initial singular-parameter probes were rejected as schema errors and immediately retried with valid parameters. `py_eval` is not exposed by the current server schema; this was not treated as MCP failure because `lookup_funcs`, `xrefs_to`, `callees`, `analyze_function`, `decompile`, and `disasm` all worked.
- Original report-only pass did not run validators or acquire leases. The implementation callback acquired short leases, ran scoped validators, and released/expired leases as recorded below.

## Target

- UID: `0002JQ`
- Target file: `by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md`
- Binary range: `0x004aec90-0x004af031`
- IDA function: `sub_4AEC90`, live-MCP size `0x3a1`
- Source placement: `MyItemListPane::DrawListEntry`, a virtual row-renderer override dispatched by `ListPane`
- Recommended owner/emitter route: class UID00008W (`by-class/MyItemListPane.md`) emitting through file UID0000LO (`by-file/MyItemListPane.md`)
- Report-only output: this file only. No target/support by-* docs, generated files, validator state, queues, archives, supervisor ledgers, or lifecycle commands were touched.

## Current Target State

`by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md` already identifies the routine as the `MyItemListPane` virtual row renderer at `sub_4AEC90`, range `0x004aec90-0x004af031`, with a blank formal C++ block. It records the major behavior correctly: row selection background/text color handling, item glyph bounds, EPF scaled icon branch, legacy icon branch, wide-name fitting, cursor movement, and wide text drawing.

At report-acceptance time, the target page remained under file owner/emitter `UID0000LO` even though the semantic receiver is class `UID00008W MyItemListPane`. The related class page already named this routine as `DrawListEntry`, the vtable page placed it in the primary virtual slot, and the constructor/row-layout support docs provided enough type evidence to write a source-facing body. The generated file `auto-generated/NexusTK/ui/dialogs/MyItemListPane.cpp` showed UID0002JQ only as an empty emitter marker in refresh command `000000004547`, so the generated state was stale relative to the now-sufficient evidence. The implementation callback has since updated UID0002JQ to class owner/emitter `00008W` and refreshed generated output through scoped validators.

## Evidence Checked

Primary target/support docs:

- `by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md`
- `by-class/MyItemListPane.md`
- `by-file/MyItemListPane.md`
- `by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md`
- `by-memory/0x004aeb30-0x004af031.MyItemListPane.md`
- `by-type/by-struct/MyItemListPaneEntryLayouts.md`
- `by-type/by-vtable/MyItemListPaneVtables.md`
- `by-file/ListPane.md`
- `by-class/ListPane.md`
- `by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md`
- `by-global/g_pItemObjImageLib.md`
- `by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md`
- `by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md`
- `by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md`
- `by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md`
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
- `by-memory/0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress.md`

Prior B-agent evidence and analogs:

- Accepted/executed B004 report `0004A0-ExchangeItemListPaneDrawItemEntry-source-quality.md`, the closest item-list row renderer analog. It resolves the same inherited ListPane callback shape, item glyph bounds path, EPF scaled-image path, legacy item-image path, text fitting, and GrafPort draw-state helpers, and was accepted for first-draft C++ at `88/90`.
- Executed B006 report `0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality.md`, used as row-record provenance. Its current target doc is incorporated and documents the inventory slot source fields copied by the MyItemListPane constructor.

Searches performed:

- Repository searches for `0002JQ`, `004aec90`, `004af031`, `MyItemListPaneDrawListEntry`, `MyItemListPane`, and `DrawListEntry`.
- Support/analog searches for `0003U3`, `ListPanePaintHitTestGeometry`, `DrawItemEntry`, `DrawItem`, `GetItemGlyphBounds`, `DrawItemImageScaled`, and `FitTextAndAppendSuffix`.

Generated-state check:

- `auto-generated/NexusTK/ui/dialogs/MyItemListPane.cpp` currently contains empty markers for `UID00008W`, `UID0001VE`, `UID0001Y8`, `UID0002JO`, `UID0002JP`, and `UID0002JQ`; UID0002JQ is still `Completion:85 | Confidence:88 | Empty Emitter Marker`.

## Live IDA MCP Evidence

Function inventory from `lookup_funcs`:

- `0x004aec90`: `sub_4AEC90`, size `0x3a1`.
- `0x004af031`: not a function, confirming this is the end boundary rather than a separate routine.
- Neighbor/support functions: `0x004aeb30 sub_4AEB30`, `0x004aec80 sub_4AEC80`, `0x004df2c0 sub_4DF2C0`, `0x004dee50 sub_4DEE50`, `0x004df460 sub_4DF460`, `0x004bab70 sub_4BAB70`, `0x004ba820 sub_4BA820`, `0x004f3f00 sub_4F3F00`.

Xref/vtable evidence:

- `xrefs_to 0x004aec90`: exactly one data xref at `0x00619fa8`.
- `xrefs_to 0x00619f28`: constructor store xref at `0x004aeb9a` in `sub_4AEB30`.
- `xrefs_to 0x00619fb0`: constructor store xref at `0x004aeba5` in `sub_4AEB30`.
- `xrefs_to 0x00619fe0`: constructor store xref at `0x004aebb1` in `sub_4AEB30`.
- `xrefs_to 0x00619fa8`: no direct xrefs, consistent with vtable-slot data rather than a normal code callsite.
- Interpretation: the routine is reached through the `MyItemListPane` primary vtable draw slot at `0x00619fa8`, populated by the constructor, not by direct code callers.

Caller/callee evidence:

- `analyze_function 0x004aec90`: prototype shape `void __thiscall(int this, int, int, int *)`, size `929`, no direct callers, one data xref at the vtable slot.
- Callees: `0x00457a60`, `0x004f3f00`, `0x004b9660`, callback pointer `0x0069b3fc`, `0x004b9680`, `0x004df460`, `0x004b7cc0`, `0x004df2c0`, `0x004b9690`, `_wcscpy_s`, `0x004ba820`, `0x004b9600`, `0x004dee50`, `0x004bab70`, and `@__security_check_cookie@4`.
- Decompile argument use: `a2` is row index, `a3` is row payload, and `a4` is row bounds. This matches `ListPanePaintHitTestGeometry` evidence that the base ListPane dispatch calls derived row draw with `(rowIndex, itemPayload, rowBounds)`.

Disassembly/decompile boundary inventory:

- Function prologue allocates `0x248` bytes and uses security-cookie protection.
- Branch condition is global `byte_66DA97 == 1`.
- EPF branch appears first and uses half-size glyph dimensions plus `sub_4B7CC0` clipping before calling `sub_4DF2C0`.
- Legacy branch uses full glyph dimensions and calls `sub_4DEE50` with overlay mask `0` and overlay strength `0.0`.
- Both branches converge to text-state setup, local text copy, fit/truncation, cursor move, manual `wcslen`, and wide text draw.

## Function And Raw Boundary Inventory

Target function:

- Range: `0x004aec90-0x004af031`
- IDA name: `sub_4AEC90`
- Proposed source method: `MyItemListPane::DrawListEntry`
- Source-facing callback shape: `void MyItemListPane::DrawListEntry(int rowIndex, const MyItemListEntry *entry, const RectBounds *rowBounds)`. The accepted report's `MyItemListPaneEntry` spelling was normalized during implementation to the current support-doc `MyItemListEntry` declaration.

Adjacent functions in the containing aggregate:

- `0x004aeb30-0x004aec77`: `MyItemListPane` constructor, UID0002JO. It builds the row payload consumed here.
- `0x004aec80-0x004aec8d`: selected-slot helper, UID0002JP.
- `0x004aec90-0x004af031`: draw-list-entry method, UID0002JQ.

No child page is needed for the draw routine. The whole renderer is one coherent ListPane virtual override with no independent helper subrange inside the function. The local EPF/legacy branches are source-level conditionals, not split-worthy routines.

## Action Switch And Drawing-State Mapping

The routine has one top-level asset-mode switch:

- `byte_66DA97 == 1`: EPF/compact asset path.
- Otherwise: legacy item-image path.

Shared pre-icon state:

- Calls `sub_457A60` to initialize local draw/tile context state.
- Calls `ListPane::IsItemSelected` helper at `0x004f3f00` with `rowIndex`.
- If the row is selected, sets draw color `37`, invokes callback pointer `0x0069b3fc(this, rowBounds)` to fill/mark the row bounds, and selects text color `128`.
- If not selected, selects text color `37`.
- Calls `GrafPort` text color setter `0x004b9680`.

Shared post-icon state:

- Writes `this+0x88 = 1`, documented in GrafPort accessor evidence as text draw/background mode, not a dirty byte.
- Calls secondary/background text color setter `0x004b9690` with `0`.
- Copies the row wide string from payload `+0x06` to a 256-wide-char local buffer.
- Calls `GrafPort::FitTextAndAppendSuffix` at `0x004ba820` with suffix `L"..."` and width `rowBounds->right - 50`.
- Calls `GrafPort::MoveTo` at `0x004b9600` with x `50`, y `(rowBounds->top + rowBounds->bottom) / 2 + 6`.
- Calls `GrafPort::DrawWideText` at `0x004bab70` with the fitted string and computed length.

## Packet Fields And Subcommands

The constructor UID0002JO is the direct source for the packet consumed by UID0002JQ:

- Constructor reads a `LocalInventorySlotRecord` via `LivingObjectPane::GetInventorySlotAddress`.
- It filters on active byte `+0x00`.
- It appends ListPane rows containing:
  - `+0x00`: source inventory slot index, unsigned byte.
  - `+0x01`: padding/unused byte.
  - `+0x02`: item id, unsigned short.
  - `+0x04`: icon category/style byte.
  - `+0x05`: padding/unused byte.
  - `+0x06`: inline wide item display name.

UID0002JQ consumes the row payload as:

- `entry->itemId` from `payload+0x02` for `GetItemGlyphBounds`, `DrawItemImageScaled`, and `DrawItemImage`.
- `entry->iconStyle` from `payload+0x04` for item-image palette/category flags.
- `entry->displayName` from `payload+0x06` for the fitted text label.

No network packet subcommand or dialog command opcode is involved in this target. It is a local ListPane paint callback over inventory-derived row payloads.

## Helper Roles

Accepted source-facing helper roles are now strong enough for first-draft C++:

- `ListPane::IsItemSelected(rowIndex)` at `0x004f3f00`: selection test used before selected-row fill/text color changes.
- `GetItemGlyphBounds(itemId, &bounds)` at `0x004df460`: free item-image helper that returns source glyph rectangle dimensions.
- `IntersectRects(&dst, rowBounds, &dst)` at `0x004b7cc0`: EPF path clips the scaled icon destination to the row bounds.
- `ItemObjImageLib::DrawItemImageScaled(this, &dst, itemId, iconStyle)` at `0x004df2c0`: EPF half-size icon draw helper.
- `ItemObjImageLib::DrawItemImage(this, &dst, itemId, iconStyle, NULL, 0.0f)` at `0x004dee50`: legacy full-size item draw helper.
- `GrafPort::SetDrawColor(37)` at `0x004b9660`: selected fill color state.
- Surface callback pointer `0x0069b3fc(this, rowBounds)`: selected-row fill or invalidate callback. The exact source symbol remains provisional, but the call shape is fixed.
- `GrafPort::SetTextColor(37/128)` at `0x004b9680`: active text color setter.
- `GrafPort::SetTextBackColor(0)` / secondary text color setter at `0x004b9690`: background/secondary text state.
- `_wcscpy_s(localText, 0x100, entry->displayName)`: local text copy before fitting.
- `GrafPort::FitTextAndAppendSuffix(localText, 0x100, L"...", rowBounds->right - 50)` at `0x004ba820`.
- `GrafPort::MoveTo(50, centerY + 6)` at `0x004b9600`.
- `GrafPort::DrawWideText(localText, wcslen(localText))` at `0x004bab70`.

## Positive Evidence Summary

- Function range and size are live-MCP confirmed.
- The vtable slot is live-MCP confirmed at `0x00619fa8`, with constructor stores for all three `MyItemListPane` vtables at `0x004aeb9a`, `0x004aeba5`, and `0x004aebb1`.
- No direct callers exist; this is expected for a virtual ListPane row-draw override and is not negative evidence.
- `ListPanePaintHitTestGeometry` supplies the inherited callback signature `(rowIndex, itemPayload, rowBounds)`.
- Constructor UID0002JO supplies the exact row payload layout and field provenance.
- `LivingObjectPaneGetInventorySlotAddress` supplies the source inventory record fields copied into rows.
- Item-image helpers and GrafPort helpers have sufficient source-facing names/signature shapes, even where their own internal C++ remains blank.
- The accepted ExchangeItemListPane row-renderer report establishes a close project precedent for turning this same helper set into formal first-draft C++.
- The generated output is marker-only only because UID0002JQ has not yet been incorporated, not because current evidence is insufficient.

## Negative Evidence Summary

- No direct code callers were found for `0x004aec90`. This does not argue against reconstructability because the routine is a virtual draw callback referenced from a vtable slot.
- `0x004af031` is not a separate function. There is no evidence for splitting a trailing helper or child page from the target range.
- No independent child page should be created for EPF versus legacy draw. The branches are ordinary source-level conditionals sharing the same row payload and text tail.
- No evidence supports assigning storage ownership of `g_pItemObjImageLib` to MyItemListPane; the global remains owned by ItemObjImageLib.
- No evidence supports moving this method to `ListPane`; ListPane only dispatches the callback and provides selection/geometry services.
- No evidence supports treating `this+0x88` as a dirty flag; GrafPort accessor evidence identifies it as text draw/background mode.
- No evidence supports retaining formal C++ as blank after incorporation. The remaining open names are source-symbol spelling choices, not behavior blockers.
- No evidence supports a generated-body-first approach. The current generated marker is stale, and older simroot output should be used only as a lead; the authoritative body should be written from the live decompile plus incorporated support docs.

## Heuristic / Inference Reanalysis And Validation

Resolved and implementation-ready:

- Row layout: constructor UID0002JO and the entry-layout support doc independently support `MyItemListEntry` with `slotIndex` at `+0x00`, `itemId` at `+0x02`, `iconStyle` at `+0x04`, and `displayName` at `+0x06`. UID0002JQ does not consume the slot byte, but the struct should retain it because the constructor and selected-slot helper do. This implementation normalizes the accepted report's `MyItemListPaneEntry` spelling to the existing support-doc declaration `MyItemListEntry`.
- Function signature: `ListPanePaintHitTestGeometry` establishes the inherited draw callback shape, and live decompile confirms `a2` is row index, `a3` is row payload, and `a4` is row bounds. The implemented source-facing method is `void MyItemListPane::DrawListEntry(int rowIndex, const MyItemListEntry *entry, const RectBounds *rowBounds)`.
- Helper names: `GetItemGlyphBounds`, `DrawItemImageScaled`, `DrawItemImage`, `FitTextAndAppendSuffix`, `MoveTo`, and `DrawWideText` are supported by existing by-* helper docs and the accepted Exchange analog. `SetTextBackColor` is the preferred source-facing name for the `0x004b9690` secondary/background text setter, while the doc should also preserve the raw address evidence.
- Owner/emitter route: class UID00008W is the semantic owner because this is a virtual method in the `MyItemListPane` vtable. File UID0000LO remains the source file route, not the direct method owner. This resolves the current stale file-owner/file-emitter metadata.
- Source placement blockers: no placement blocker remains. The only symbol still provisional is callback pointer `0x0069b3fc`; it is implementation-ready as a documented source-facing placeholder such as `g_pfnFillOrInvalidateRect(this, rowBounds)` because the call shape and role are exact.

Explicit exclusions:

- No child pages: excluded because the function is one coherent renderer and `0x004af031` is not a function boundary.
- No aggregate body: excluded because `by-memory/0x004aeb30-0x004af031.MyItemListPane.md` is a split inventory page and remains non-emitting.
- No ItemObjImageLib ownership move: excluded because item-image helpers/global storage are dependencies only.
- No blank/no-code target proof: excluded because the current blocker set is resolved below the first-draft C++ threshold.

## Owner, Emitter, And Source-Placement Recommendation

Ranked recommendation:

1. `CANONICAL_OWNER:00008W`, `EMITTER_UIDS:00008W`, source method on `MyItemListPane`. This is the best source-quality route because the routine is a virtual method of the `MyItemListPane` class, appears in the class vtable, receives `this` as a `MyItemListPane`, and is semantically class-owned. The file route remains through `by-file/MyItemListPane.md` / UID0000LO.
2. `CANONICAL_OWNER:0000LO`, `EMITTER_UIDS:0000LO`, direct file emission. This is the current state and remains buildable, but it is less precise than class ownership now that class, vtable, and callback evidence are sufficient.
3. `CANONICAL_OWNER:0000KT` or `UID00007A ListPane`: reject. ListPane dispatches the callback but does not own the MyItemListPane row renderer.
4. `CANONICAL_OWNER:0000RA ItemObjImageLib`: reject. ItemObjImageLib owns the icon helpers/global storage, not this UI method.
5. `CANONICAL_OWNER:NONE`: reject. This is not a split/aggregate page; it is a reconstructable method.

Implementation callback should update UID0002JQ from file-owner/file-emitter metadata to class-owner/class-emitter metadata and keep `RECONSTRUCTABLE:TRUE`.

Because changing UID0002JQ to class emission may require a class-level child placeholder if the validator does not already route class children automatically, `by-class/MyItemListPane.md` should be checked during implementation. If the validator rejects class-emitted child placement without a class marker/child insertion point, stop and report the exact blocker rather than inventing child pages.

## Score And Metadata Recommendation

Recommended target metadata after incorporation:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00008W`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00008W`

Score rationale:

- Raise completion from `85` to `88` because the target can now carry a source-facing formal C++ body, exact row layout, exact branch mapping, exact helper roles, vtable route, and generated-state correction.
- Raise confidence from `88` to `90` because live MCP reconfirmed the current binary evidence and the support docs resolve the main row-payload and inherited-callback uncertainties.
- Do not raise higher than `88/90` because exact original source spellings for the method name, row struct type, selected-fill callback symbol at `0x0069b3fc`, and some helper names remain reconstructed rather than proven from symbols. The function is source-ready but not symbol-perfect.

Recommended support-doc score handling:

- `by-class/MyItemListPane.md`: update details and source-order notes; score may remain `85/86` unless the supervisor wants the class page re-scored separately.
- `by-file/MyItemListPane.md`: update generated-state and child contents notes; score may remain `87/86`.
- `by-memory/0x004aeb30-0x004af031.MyItemListPane.md`: update aggregate inventory and child score/status; aggregate remains `RECONSTRUCTABLE:FALSE`.
- `by-type/by-struct/MyItemListPaneEntryLayouts.md`: already contains the core layout; update with the preferred source-facing row struct name only if needed; score can remain unchanged.
- `by-type/by-vtable/MyItemListPaneVtables.md`: already contains the slot; update first-draft readiness note only if needed; score can remain unchanged.

## First-Draft C++ Recommendation

Recommended exact formal `RECONSTRUCTION_CPP CODE` insertion text for UID0002JQ:

**RECONSTRUCTION_CPP CODE**

```cpp
void MyItemListPane::DrawListEntry(int rowIndex, const MyItemListEntry *entry, const RectBounds *rowBounds)
{
    EPFTileContext tileContext;
    RectBounds glyphBounds;
    RectBounds iconBounds;
    wchar_t text[256];

    tileContext.Initialize();

    if (IsItemSelected(rowIndex))
    {
        SetDrawColor(37);
        g_pfnFillOrInvalidateRect(this, rowBounds);
        SetTextColor(128);
    }
    else
    {
        SetTextColor(37);
    }

    GetItemGlyphBounds(static_cast<short>(entry->itemId), &glyphBounds);

    const int rowCenterY = (rowBounds->top + rowBounds->bottom) / 2;
    const int glyphWidth = glyphBounds.right - glyphBounds.left;
    const int glyphHeight = glyphBounds.bottom - glyphBounds.top;

    if (g_useEpfAssets == 1)
    {
        const int scaledWidth = glyphWidth / 2;
        const int scaledHeight = glyphHeight / 2;

        iconBounds.left = 25 - (scaledWidth / 2);
        iconBounds.top = rowCenterY - (scaledHeight / 2);
        iconBounds.right = iconBounds.left + scaledWidth;
        iconBounds.bottom = iconBounds.top + scaledHeight;

        IntersectRects(&iconBounds, rowBounds, &iconBounds);
        g_pItemObjImageLib->DrawItemImageScaled(this, &iconBounds, static_cast<short>(entry->itemId), entry->iconStyle);
    }
    else
    {
        iconBounds.left = 25 - (glyphWidth / 2);
        iconBounds.top = rowCenterY - (glyphHeight / 2);
        iconBounds.right = iconBounds.left + glyphWidth;
        iconBounds.bottom = iconBounds.top + glyphHeight;

        g_pItemObjImageLib->DrawItemImage(this, &iconBounds, static_cast<short>(entry->itemId), entry->iconStyle, NULL, 0.0f);
    }

    m_textDrawMode = 1;
    SetTextBackColor(0);

    wcscpy_s(text, 0x100, entry->displayName);
    FitTextAndAppendSuffix(text, 0x100, L"...", rowBounds->right - 50);
    MoveTo(50, rowCenterY + 6);
    DrawWideText(text, wcslen(text));
}
```

Recommended adjacent row type if the implementation callback needs a support declaration/note:

```cpp
struct MyItemListEntry
{
    unsigned char slotIndex;
    unsigned char reserved1;
    unsigned short itemId;
    unsigned char iconStyle;
    unsigned char reserved5;
    wchar_t displayName[259];
};
```

Notes for implementation:

- `tileContext.Initialize()` corresponds to `sub_457A60` and is initialized even though later item-image helper calls carry the visible work. If no stable source-facing `EPFTileContext` name is available in the support docs, keep the target C++ body but add a short evidence note explaining the raw initialization call rather than blocking emission.
- `g_pfnFillOrInvalidateRect` is a source-facing placeholder for callback pointer `0x0069b3fc(this, rowBounds)`. If the project already has a better standardized Surface/GrafPort callback name, use that name in the implementation while preserving the call shape and evidence.
- `g_useEpfAssets` is the source-facing name for `byte_66DA97`, consistent with surrounding docs that describe EPF/legacy mode.
- `m_textDrawMode` is the source-facing field for `this+0x88`; do not document it as dirty state.

## Claim And Incorporation Ledger

| Claim ID | Claim | Destination | Action | Verification State |
|---|---|---|---|---|
| C01 | UID0002JQ is exactly `sub_4AEC90`, size `0x3a1`, ending at non-function boundary `0x004af031`. | Target page `by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md`. | Applied: target IDA Verification Notes now record live MCP size and non-function end boundary. | applied |
| C02 | The routine is a `MyItemListPane` virtual row draw override reached through vtable slot `0x00619fa8`. | Target page, class page, vtable page, aggregate page. | Applied: target/support pages now record class ownership, vtable-only xref, zero direct callers, and constructor store evidence. | applied |
| C03 | Source callback shape is `(rowIndex, rowPayload, rowBounds)`. | Target page and class page. | Applied: target formal C++ uses `DrawListEntry(int rowIndex, const MyItemListEntry *entry, const RectBounds *rowBounds)` and target notes cite inherited ListPane dispatch. The report spelling `MyItemListPaneEntry` was normalized to existing support name `MyItemListEntry`. | applied |
| C04 | Row payload fields are slot at `+0x00`, item id at `+0x02`, icon style at `+0x04`, wide display text at `+0x06`. | Target page, entry-layout page, class/file support pages. | Applied/already-present: offsets were already in type/support docs; target, class, file, aggregate, and struct pages now add `MyItemListEntry` draw-consumer proof and padding fields. | applied |
| C05 | Selected rows set draw color `37`, call callback `0x0069b3fc(this,rowBounds)`, and use text color `128`; unselected rows use text color `37`. | Target page and class/file support pages. | Applied: target Behavior/Reconstructability Notes and file Draw Path Details now preserve the exact selected-row branch and raw callback address. | applied |
| C06 | EPF branch halves glyph dimensions, clips to row bounds, and calls `DrawItemImageScaled`. | Target page and file/class/aggregate support pages. | Applied: target formal C++ and support draw-path notes describe clipped half-size EPF branch and helper. | applied |
| C07 | Legacy branch centers full glyph dimensions and calls `DrawItemImage` with no overlay and zero overlay strength. | Target page and file/class/aggregate support pages. | Applied: target formal C++ and support draw-path notes describe full-size legacy branch, NULL overlay, and zero strength. | applied |
| C08 | Text tail sets text mode/background, copies 256 wchar buffer, fits with `L"..."`, moves to `(50, centerY+6)`, and draws wide text. | Target page, file page, aggregate page. | Applied: target formal C++ plus target/file/aggregate prose record text mode, background clear, `_wcscpy_s`, fit suffix, MoveTo, and DrawWideText. | applied |
| C09 | Helper globals belong to their support owners and should not be re-owned by this target. | Target page dependency notes; file/aggregate dependency notes. | Applied/excluded-with-reason: target notes explicitly keep `g_pItemObjImageLib` and helper ownership on support owners and reject ListPane/ItemObjImageLib ownership moves. | applied |
| C10 | Best owner/emitter route is class UID00008W, not file UID0000LO direct emission. | Target metadata; class/file/aggregate/vtable support pages. | Applied: UID0002JQ metadata changed to `CANONICAL_OWNER:00008W` and `EMITTER_UIDS:00008W`; support docs describe class route through file UID0000LO. | applied |
| C11 | Formal first-draft C++ is now safe. | Target formal C++ block and generated-refresh expectations. | Applied: target score raised to `88/90` and the formal `RECONSTRUCTION_CPP CODE` block contains the accepted `DrawListEntry` body. | applied |
| C12 | No child pages are needed. | Target page and aggregate page. | Applied/excluded-with-reason: target and aggregate state the routine is one coherent renderer, `0x004af031` is not a function, and no child pages or aggregate body are needed. | excluded-with-reason |
| C13 | Current generated `MyItemListPane.cpp` marker-only state is stale. | Target, file, aggregate support pages; final implementation response. | Applied: docs record pre-callback marker-only generated state and validator-refresh expectation; generated files were not edited manually. | applied |

## Implementation Tracking Checklist

- [x] Lease only files about to be edited. Proof: acquired B004 leases for the six changed by-* docs: target, class, file, aggregate, entry-layout, and vtable pages. B003 leases on class/file/struct were allowed to expire before editing. The first B004 lease window expired before cleanup during the edit/validator cycle; after the generated type-name mismatch was found, B004 reacquired fresh leases for the four follow-up files before the second validator batch.
- [x] Update `by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md` metadata to `88/90`, `CANONICAL_OWNER:00008W`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008W`. Proof: target header now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00008W`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008W`.
- [x] Insert the formal C++ body for `MyItemListPane::DrawListEntry` or an equivalent source-facing body preserving every live-MCP operation above. Proof: target `RECONSTRUCTION_CPP CODE` block contains the accepted body with the row type normalized to existing support declaration `DrawListEntry(int rowIndex, const MyItemListEntry *entry, const RectBounds *rowBounds)`.
- [x] Update target evidence with live MCP function size, vtable xrefs, zero direct-call evidence, callees, branch mapping, row payload fields, helper roles, generated marker state, rejected alternatives, and score rationale. Proof: target Status, Behavior, Row Payload Reads, IDA Verification Notes, Reconstructability Notes, Source-Disposition Notes, Score Rationale, and Changes sections were updated.
- [x] Update `by-class/MyItemListPane.md` with UID0002JQ first-draft readiness/body ownership notes and any needed class child-emission marker/ordering note. Stop and report if class child routing cannot be made validator-consistent without creating new child pages. Proof: class page now preserves B003's `[[CHILDREN]]` route marker, adds UID0002JQ route comments, and records UID0002JQ `88/90` first-draft C++ ownership/emission; no child-routing blocker found before validation.
- [x] Update `by-file/MyItemListPane.md` with UID0002JQ now emitting through class/file route and replace stale marker-only caveats for this child. Proof: file Status, Proposed Contents, Draw Path Details, Data Caveats, Score Rationale, and Changes sections now describe UID0002JQ class/file route and current marker-only generated state.
- [x] Update `by-memory/0x004aeb30-0x004af031.MyItemListPane.md` aggregate inventory with UID0002JQ `88/90`, class-owned emitting status, and no-child conclusion; keep aggregate non-emitting. Proof: aggregate Status, Range Contents, Child Attachment Map, Draw Behavior, Data Caveats, Reconstructability Notes, Score Rationale, and Changes sections updated; metadata remains `RECONSTRUCTABLE:FALSE`, owner `NONE`, no emitters.
- [x] Update `by-type/by-struct/MyItemListPaneEntryLayouts.md` only if needed to record the preferred source-facing struct name and draw-consumer field usage. Proof: struct page records the existing emitted `MyItemListEntry` declaration as the normalized name, includes the first-draft declaration shape, and records UID0002JQ consuming `itemId`, `iconStyle`, and `displayName`.
- [x] Update `by-type/by-vtable/MyItemListPaneVtables.md` only if needed to record that slot `0x00619fa8` now has a first-draft method body. Proof: vtable page now notes primary `+0x80`/`0x00619fa8` target UID0002JQ is `88/90` and carries first-draft source C++; score unchanged.
- [x] Do not edit generated reports, generated C++, coverage reports, validator state, queues, archives, supervisor ledgers, or manual coverage files. Proof: only the six listed by-* docs and this B004 report file were edited manually.
- [x] Run scoped validators for each changed by-* file from `source-3/project-documentation` with `--apply --queue-timeout 240`. Proof: all scoped validators exited 0 with `ok:1`. Initial changed-file validators: target `000000004591` / `2026-07-02T15:12:54-04:00`, class `000000004592` / `15:12:56`, file `000000004593` / `15:12:58`, aggregate `000000004594` / `15:13:00`, entry-layout `000000004595` / `15:13:10`, vtable `000000004596` / `15:13:18`. Follow-up validators after normalizing `MyItemListEntry`: target `000000004598` / `15:15:51`, class `000000004599` / `15:15:53`, file `000000004600` / `15:15:55`, entry-layout `000000004601` / `15:16:06`, plus by-file no-op/generated-refresh probe `000000004602` / `15:16:30`.
- [x] Report generated-refresh state after scoped validators; do not manually edit generated output. Proof: generated output was validator-refreshed, not manually edited. `auto-generated/NexusTK/ui/dialogs/MyItemListPane.cpp` header after the final content-changing validator shows `validator-command-id: 000000004601`, `validator-refreshed-at: 2026-07-02T15:16:06-04:00`, and contains both `struct MyItemListEntry` and UID0002JQ `DrawListEntry(int rowIndex, const MyItemListEntry *entry, const RectBounds *rowBounds)`. The later by-file no-op validator `000000004602` reported deferred generated refresh but did not advance the header; generated content is current for the last content-changing source update.
- [x] Release leases immediately after edit/validator batch. Proof: fresh active B004 leases were released for target, class, file, and entry-layout pages. Release attempts for the aggregate and vtable pages returned `Rejected[No active lease]` because their first-window leases had already expired. Current lease report shows no active leases.

## Implementation Validator Results

All commands were run from `source-3/project-documentation` with `--apply --queue-timeout 240`; all exited `0` with `ok:1`.

| File | Final command_id | command_timestamp | Notes |
|---|---:|---|---|
| `by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md` | `000000004598` | `2026-07-02T15:15:51-04:00` | `missing_ref_uid 0003U3` remains a registry warning; target metadata/body accepted. |
| `by-class/MyItemListPane.md` | `000000004599` | `2026-07-02T15:15:53-04:00` | Stats rows updated; generated refresh deferred. |
| `by-file/MyItemListPane.md` | `000000004600` | `2026-07-02T15:15:55-04:00` | Generated MyItemListPane output refreshed; later no-op probe `000000004602` did not advance header. |
| `by-memory/0x004aeb30-0x004af031.MyItemListPane.md` | `000000004594` | `2026-07-02T15:13:00-04:00` | Aggregate non-emitting state accepted; no follow-up edits after this validator. |
| `by-type/by-struct/MyItemListPaneEntryLayouts.md` | `000000004601` | `2026-07-02T15:16:06-04:00` | `missing_ref_uid 0003U9` remains a registry warning; row type normalized to `MyItemListEntry`. |
| `by-type/by-vtable/MyItemListPaneVtables.md` | `000000004596` | `2026-07-02T15:13:18-04:00` | Vtable slot status accepted; no follow-up edits after this validator. |

Generated-refresh state: `auto-generated/NexusTK/ui/dialogs/MyItemListPane.cpp` is at `validator-command-id: 000000004601`, `validator-refreshed-at: 2026-07-02T15:16:06-04:00`, with UID0002JQ emitted as a body and no UID0002JQ empty marker. The file still has expected empty markers for unrelated emitters such as UID0001Y8 and UID0002JP.

## Final Recommendation

UID0002JQ is ready for implementation callback as a formal first-draft C++ target. The accepted incorporation should raise the target from `85/88` to `88/90`, move direct owner/emitter metadata from file UID0000LO to class UID00008W, keep `RECONSTRUCTABLE:TRUE`, preserve the file route through `by-file/MyItemListPane.md`, and avoid creating child pages. The only remaining uncertainties are source-symbol spelling details for the callback/global helper names and row-struct type, which are below the threshold for blocking a first-draft body.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004605","destination_path":"executed-b-agent-research/B004/0002JQ-MyItemListPaneDrawListEntry-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002JQ-MyItemListPaneDrawListEntry-source-quality.md","timestamp":"2026-07-02T15:21:06-04:00","uid":"0002JQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
