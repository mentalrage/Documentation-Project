** TARGET-REPORT-UID:0004A0 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B004 Report: [UID:0004A0] ExchangeItemListPaneDrawItemEntry

Report-only research for `by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md`.

## Current Target State

- Current metadata: `COMPLETION:83`, `CONFIDENCE:87`, `CANONICAL_OWNER:00004S`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Current disposition: exact `ExchangeItemListPane` draw virtual, but non-emitting because inherited draw signature, renderer helper names, item-image declarations, row/image dependency names, emitter route, and first-draft C++ readiness were unresolved.
- Required result for implementation: keep the direct owner [UID:00004S][ExchangeItemListPane](by-class/ExchangeItemListPane.md), route emitted child code through `EMITTER_UIDS:00004S`, and use [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) as the class file route.

## MCP Status And Evidence Checked

Current IDA MCP was used. The first `idb_list` session `3fa0535f` disappeared and target calls returned `Session not found: 3fa0535f`. The listener remained active at `127.0.0.1:13337` with owning process `7364`; processes included `idalib-mcp` pid `16824` and Python workers. A fresh `idb_list` returned active session `B005_00049P_20260629` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, backend worker pid `16832`. All target MCP evidence below comes from that active read-only session.

`server_health` reported module `NexusTK.exe`, imagebase `0x400000`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, `auto_analysis_ready:true`, `hexrays_ready:true`, and strings cache ready.

Target-specific MCP checks:

- `lookup_funcs` confirms `0x004ae1c0` is `sub_4AE1C0`, size `0x2f6` / 758 bytes, covering through `0x004ae4b5`; `0x004ae4b6` is not a function; successor `0x004ae4c0` is `sub_4AE4C0`.
- `xrefs_to 0x004ae1c0` reports exactly one data xref, from `0x00619e48`. There are no direct code callers.
- `get_int 0x00619e48` returned `4907456`, which converts to `0x004ae1c0`; sibling slot `0x00619e40` returned `0x004ae1b0`.
- `get_bytes 0x004ae1b0` confirms `0x004ae1b0` bytes `c2 08 00`, thirteen `0xcc` bytes at `0x004ae1b3-0x004ae1c0`, target body bytes from `0x004ae1c0`, final `ret 0x0c` ending at `0x004ae4b6`, and ten `0xcc` bytes at `0x004ae4b6-0x004ae4c0` before the AddItemDialog successor.
- `analyze_function 0x004ae1c0` reports prototype shape `void __thiscall(int this, int, int, int *)`, size `0x2f6`, cyclomatic complexity `4`, no direct callers, one data xref at `0x619e48`, and callees `sub_457A60`, `sub_4DF460`, `sub_4B7CC0`, `sub_4DF2C0`, `sub_4DEE50`, `sub_4B9600`, `sub_4B9680`, `sub_4B9690`, `sub_4BAB70`, `_wcscpy_s`, and `@__security_check_cookie@4`.
- `decompile 0x004ae1c0` confirms the second explicit argument is unused, the third explicit argument is the row payload pointer, and the fourth explicit argument is the row bounds pointer.

## Positive Evidence

The target is a routed virtual child, not an orphan body. The primary vtable slot `0x00619e48` points to `0x004ae1c0`; the neighboring null virtual at `0x00619e40 -> 0x004ae1b0` is already resolved as the `ListPane` selection-change override [UID:00049Z]. The target's `ret 0x0c` confirms three stack arguments after `this`.

The inherited draw signature is now source-quality enough for first draft. [UID:0003U3][0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry](by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md) records that the generic `ListPane` paint loop dispatches derived row drawing with `(rowIndex, itemPayload, rowBounds)`. This matches the target: argument 1 is unused row index, argument 2 is an `ExchangeItemListRow *`, and argument 3 is a `RectBounds *`.

The row layout is no longer open. [UID:00004S] already documents `ExchangeItemListRow` as `key +0`, reserved `+1`, `unsigned short itemId +2`, `unsigned char color +4`, reserved `+5`, and `wchar_t name[256] +6`, size `0x206`. The target reads `+2`, `+4`, and `+6`, matching constructor/upsert/dispatcher row evidence.

Renderer/helper names are source-facing enough for this consumer:

- `sub_457A60` is `EPFTileContext::Initialize` / `InitTileContext`. In this target it initializes a stack context whose embedded `bounds` field is reused for item glyph bounds.
- `sub_4DF460` is the free helper `GetItemGlyphBounds(short itemId, RectBounds *outRect)`.
- `sub_4B7CC0` is the file-level free geometry helper `IntersectRects`.
- `sub_4DF2C0` is `ItemObjImageLib::DrawItemImageScaled(Pane *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags)`.
- `sub_4DEE50` is `ItemObjImageLib::DrawItemImage(Pane *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength)`.
- `dword_67A758` is the backing storage for `g_pItemObjImageLib`.
- `byte_66DA97` is the documented `g_useEpfAssets` / EPF asset-mode selector.
- `sub_4B9600` is `GrafPort::MoveTo`, `sub_4B9680` is primary `GrafPort::SetTextColor`, `sub_4B9690` is secondary/background `SetTextBackColor`, and `sub_4BAB70` is `GrafPort::DrawWideText`.
- The direct byte write at `this+0x88` matches GrafPort `m_textDrawMode`.

Behavior is stable:

- EPF/high branch: initializes the item context, calls `GetItemGlyphBounds`, halves the glyph width and height, centers that half-size rectangle on `x=25` and the vertical center of the row, clips it against row bounds with `IntersectRects`, and calls `DrawItemImageScaled`.
- Legacy branch: initializes the same context, calls `GetItemGlyphBounds`, uses the full glyph width and height, centers at `x=25` and row center, and calls `DrawItemImage` with overlay mask `0` and overlay strength `0.0`.
- Both branches then set `m_textDrawMode = 1`, text color `37`, background/secondary color `0`, copy the row name into a 256-wide-character stack buffer, move the text cursor to `(50, rowCenterY + 6)`, and call `DrawWideText` with `wcslen` of the copied text.

## Negative Evidence And Exclusions

- There are no direct code callers; the only live route is the vtable data xref at `0x00619e48`. This supports a virtual override, not a standalone helper.
- `0x004ae4b6` has no xrefs and is padding start, not an executable successor. `0x004ae4c0` is AddItemDialog territory and must remain outside the target.
- `ItemObjImageLib`, `GrafPort`, `RectBounds`, `EPFTileContext`, `PaletteLib`, `ResourceLayoutTable`, and Surface callbacks are dependencies only. They do not own exchange row semantics.
- `MyItemListPaneDrawListEntry` is a close analog for item row rendering, but it is not ownership evidence for the exchange pane.
- `DLGEXC1.EPF` / `.PAL` belong to exchange dialog background/resource setup, not this row renderer.
- The exact original base virtual name is still inferred. Use `DrawItemEntry` as the target name and keep `DrawListEntry` as the documented alternate if `ListPane` naming later standardizes on that spelling.
- The called ItemObjImageLib draw child pages still keep their own formal bodies blank because internal render callback/source-shape details are unresolved. That does not block this target from calling their documented source-facing interfaces.

## Heuristic And Source-Quality Reanalysis

The old blank-emitter reason is now stale. The target already had exact boundaries, vtable route, row offsets, and broad behavior; the missing pieces were the inherited callback shape and helper names. Those now have enough support from `ListPanePaintHitTestGeometry`, `ExchangeItemListPane`, `EPFTileContext`, `ItemObjImageLib`, `RectBounds`, `g_pItemObjImageLib`, and `GrafPort` pages.

The source-quality bar is satisfied for a first-draft child method because the body is self-contained UI row composition. It does not need the internal implementation bodies of `DrawItemImage` or `DrawItemImageScaled`; it only needs their declarations, which the ItemObjImageLib pages already provide as source-facing signatures. Remaining uncertainty is original spelling and declaration/source-order cleanup, not behavior.

## Ranked Ownership Disposition

1. Keep direct owner [UID:00004S][ExchangeItemListPane](by-class/ExchangeItemListPane.md). The method consumes `ExchangeItemListRow` layout and is a routed override in that class's primary vtable.
2. Route emission through [UID:00004S], whose class route is [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) / `NexusTK/ui/dialogs/ExchangeDialog.cpp`.
3. Reject direct [UID:0000J9] ownership for the method body. The file is the source root, but the semantic owner is the private class.
4. Reject shared dependency owners (`ListPane`, `ItemObjImageLib`, `GrafPort`, `RectBounds`, `EPFTileContext`): they provide callback convention or helper APIs only.
5. Reject `MyItemListPane`: analog only.

## Score And Metadata Recommendation

Recommended target metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00004S`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00004S`
- `EMITTER_POSITION_OPTIONAL:` unchanged blank

Rationale: exact live IDA function body, vtable route, padding, row fields, branch behavior, text behavior, inherited callback shape, helper declarations, and source route are now all documented. Keep below final-audit scores because the exact original draw method spelling, `Pane *drawOwner` helper static type, and source-order declarations remain inferred rather than symbol-proven.

## First-Draft Formal C++ Recommendation

Insert this exact content into [UID:0004A0]'s `RECONSTRUCTION_CPP CODE` block:

```cpp
void ExchangeItemListPane::DrawItemEntry(int, ExchangeItemListRow *row, RectBounds *rowBounds)
{
    EPFTileContext itemContext;
    RectBounds imageBounds;
    wchar_t text[256];

    itemContext.Initialize();
    GetItemGlyphBounds(static_cast<short>(row->itemId), &itemContext.bounds);

    const int itemWidth = itemContext.bounds.right - itemContext.bounds.left;
    const int itemHeight = itemContext.bounds.bottom - itemContext.bounds.top;
    const int rowCenterY = (rowBounds->top + rowBounds->bottom) / 2;

    if (g_useEpfAssets == 1) {
        const int scaledWidth = itemWidth / 2;
        const int scaledHeight = itemHeight / 2;

        imageBounds.left = 25 - scaledWidth / 2;
        imageBounds.top = rowCenterY - scaledHeight / 2;
        imageBounds.right = imageBounds.left + scaledWidth;
        imageBounds.bottom = imageBounds.top + scaledHeight;

        IntersectRects(&imageBounds, rowBounds, &imageBounds);
        g_pItemObjImageLib->DrawItemImageScaled(this, &imageBounds, static_cast<short>(row->itemId), row->color);
    } else {
        imageBounds.left = 25 - itemWidth / 2;
        imageBounds.top = rowCenterY - itemHeight / 2;
        imageBounds.right = imageBounds.left + itemWidth;
        imageBounds.bottom = imageBounds.top + itemHeight;

        g_pItemObjImageLib->DrawItemImage(this, &imageBounds, static_cast<short>(row->itemId), row->color, nullptr, 0.0f);
    }

    m_textDrawMode = 1;
    SetTextColor(37);
    SetTextBackColor(0);

    wcscpy_s(text, 0x100, row->name);
    MoveTo(50, rowCenterY + 6);
    DrawWideText(text, static_cast<int>(wcslen(text)));
}
```

Implementation notes:

- `EPFTileContext itemContext` is not an unused temporary. The binary initializes the stack context and then passes its embedded `bounds` field to `GetItemGlyphBounds`.
- `IntersectRects(&imageBounds, rowBounds, &imageBounds)` intentionally aliases input/output, matching the binary call.
- Do not add `ReleaseBuffers`; the binary does not call it, and the initialized context has no allocated buffers on this path.
- Keep `DrawItemEntry` as the formal name. Add prose that `DrawListEntry` is the only acceptable alternate if a future `ListPane` naming pass requires it.

## Recommended Edits For Supervisor Callback

Target page [UID:0004A0]:

- Update header metadata to `88/90`, `EMITTER_UIDS:00004S`.
- Replace stale blocker prose with the MCP evidence above.
- Add the formal C++ block exactly as written.
- Add call/helper table for `EPFTileContext::Initialize`, `GetItemGlyphBounds`, `IntersectRects`, `DrawItemImageScaled`, `DrawItemImage`, `MoveTo`, `SetTextColor`, `SetTextBackColor`, and `DrawWideText`.
- Record negative evidence: no direct callers, vtable-only route, `0x004ae4b6-0x004ae4c0` padding, and dependency-only owners.

Support docs:

- [UID:00004S][ExchangeItemListPane](by-class/ExchangeItemListPane.md): replace statements that UID0004A0 is non-emitting pending draw signature/helper names. Record the resolved signature `void DrawItemEntry(int, ExchangeItemListRow *, RectBounds *)`, `EMITTER_UIDS:00004S`, score `88/90`, and exact first-draft child status. Keep the class page declaration/container policy, but add or require a row declaration/source-order note so `ExchangeItemListRow` is available before constructor/draw child bodies.
- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md): update the private list notes to say UID0004A0 now emits through [UID:00004S] and depends on shared ItemObjImageLib/GrafPort/RectBounds helpers.
- [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md): update the covered-range row for UID0004A0 from blank-emitter blocker to routed first-draft child; preserve split-container non-emitting status for the aggregate.
- [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md): if it still says the item-list draw child is blank pending helper names, update to the resolved state.
- [UID:00049Z][0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual](by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md): update the cross-note saying UID0004A0 remains non-emitting; it should now say UID0004A0 is separately resolved by this report/callback.

No edits are required to `ItemObjImageLib`, `GrafPort`, `RectBounds`, `EPFTileContext`, or `g_pItemObjImageLib` pages unless the supervisor wants to add a cross-reference. Their current source-facing declarations are sufficient for this target.

## Validators For Implementation Callback

Run after target/support edits, not during this report-only pass:

> Executable block R001 was removed from this report and preserved verbatim in [0004A0-ExchangeItemListPaneDrawItemEntry-source-quality-removed.md](0004A0-ExchangeItemListPaneDrawItemEntry-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated refresh: `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` should gain UID0004A0's method after UID00049Z and update coverage/tracker rows through validator-owned generated files. Do not edit generated output by hand.

Supervisor execution command after report acceptance:

> Executable block R002 was removed from this report and preserved verbatim in [0004A0-ExchangeItemListPaneDrawItemEntry-source-quality-removed.md](0004A0-ExchangeItemListPaneDrawItemEntry-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Claim And Incorporation Ledger

| Claim | Evidence | Destination | Verification |
| --- | --- | --- | --- |
| Target half-open range is `0x004ae1c0-0x004ae4b6` with size `0x2f6` and post-padding `0x004ae4b6-0x004ae4c0`. | MCP `lookup_funcs`, `get_bytes`, `analyze_function`. | UID0004A0 Status/Evidence; UID00014K split inventory. | applied: UID0004A0 Status/MCP Evidence/Boundary Notes and UID00014K covered row/change entry record exact range, size, final `ret 0x0c`, and padding. Validators `000000001229` and `000000001232` both `ok: 1`. |
| Vtable route is `0x00619e48 -> 0x004ae1c0`; no direct code callers. | MCP `xrefs_to`, `get_int`, `analyze_function`. | UID0004A0 Evidence; UID00004S Method Notes. | applied: UID0004A0 MCP/negative evidence, UID00004S method row/evidence, UID0000J9 private-list note, UID00014K row, and UID00004R cross-note now record `0x00619e48 -> 0x004ae1c0` and no direct callers. Validators `000000001229`, `000000001230`, `000000001231`, `000000001232`, and `000000001233` all `ok: 1`. |
| Inherited draw callback shape is `(rowIndex, itemPayload, rowBounds)`. | [UID:0003U3] ListPane paint dispatch documentation plus target `ret 0x0c`/argument use. | UID0004A0 signature; UID00004S method row. | applied: UID0004A0 Signature And Row Layout records `DrawItemEntry(int, ExchangeItemListRow *, RectBounds *)` and inherited `(rowIndex,itemPayload,rowBounds)`; UID00004S/UID0000J9/UID00014K changes carry the same shape. Validators `000000001229`, `000000001230`, and `000000001231` were `ok: 1` with `missing_ref_uid 0003U3` warnings because the accepted ListPane evidence UID is not present in `validator.ini`. |
| Row payload is `ExchangeItemListRow *` with `itemId +2`, `color +4`, `name +6`. | Target decompile plus UID00004S row layout and constructor/upsert/dispatcher support. | UID0004A0 Behavior; UID00004S Class Purpose. | applied: UID0004A0 Signature And Row Layout and Behavior record the exact field reads; UID00004S Class Purpose/method row and UID0000J9 private-list note preserve the full row layout. Validators `000000001229`, `000000001230`, and `000000001231` all `ok: 1`. |
| EPF branch uses half-size glyph rect, clips with `IntersectRects`, and calls `DrawItemImageScaled`. | Target decompile/callees; RectBounds and ItemObjImageLib docs. | UID0004A0 Behavior/C++ block. | applied: exact formal C++ inserted into UID0004A0 and generated `ExchangeDialog.cpp`; UID0004A0 Behavior/Helper table and support notes record EPF half-size clipped branch. Validator `000000001229` `ok: 1`; latest generated header `validator-command-id: 000000001237` contains UID0004A0 block. |
| Legacy branch uses full-size glyph rect and calls `DrawItemImage(..., nullptr, 0.0f)`. | Target decompile/callees; ItemObjImageLib `DrawItemImage` signature. | UID0004A0 Behavior/C++ block. | applied: exact formal C++ inserted into UID0004A0 and generated `ExchangeDialog.cpp`; UID0004A0 Behavior/Helper table records legacy full-size branch. Validator `000000001229` `ok: 1`; latest generated header `000000001237` contains the block. |
| Text path sets `m_textDrawMode`, colors `37/0`, copies name, moves to `(50,rowCenterY+6)`, and draws wide text. | Target decompile; GrafPort draw-state/text-run helper docs. | UID0004A0 Behavior/C++ block. | applied: UID0004A0 C++/Behavior/Helper table record `m_textDrawMode`, colors `37/0`, `_wcscpy_s`, `MoveTo(50,rowCenterY+6)`, and `DrawWideText`; generated `ExchangeDialog.cpp` contains the same code. Validator `000000001229` `ok: 1`. |
| Direct owner remains [UID:00004S], source route remains [UID:0000J9]. | Vtable/class docs, ExchangeDialog file route, dependency exclusions. | UID0004A0 metadata; UID00004S/UID0000J9 support notes. | applied: UID0004A0 keeps `CANONICAL_OWNER:00004S`; UID00004S, UID0000J9, UID00014K, UID00004R, and UID00049Z record routing through `ExchangeItemListPane` to `ExchangeDialog.cpp`. Validators `000000001229` through `000000001234` all `ok: 1`. |
| `EMITTER_UIDS` should become `00004S`. | Direct class owner clears route through existing class/file parent and score recommendation is above C++ gate. | UID0004A0 header. | applied: UID0004A0 header now has `EMITTER_UIDS:00004S`; validator `000000001229` reports `autogen_registry_update 0004A0 ... -> 00004S`, `completion_update 88`, `confidence_update 90`, and `ok: 1`. |
| ItemObjImageLib/GrafPort/RectBounds/EPFTileContext pages are dependency support only. | Existing source-facing helper ownership docs and broad fan-in. | UID0004A0 negative evidence; no support doc body edits required. | applied/excluded-with-reason: UID0004A0 Ownership, Exclusions, And Negative Evidence and UID0000J9/UID00004S support notes record those pages as dependency support only. No ItemObjImageLib, GrafPort, RectBounds, EPFTileContext, or `g_pItemObjImageLib` docs were edited because no concrete stale contradictory cross-reference was found. |
| Prior "non-emitting pending helper names" prose is stale. | This report resolves inherited signature/helper naming and supplies formal C++. | UID0004A0, UID00004S, UID00014K, UID00049Z, optional UID00004R. | applied: stale target/support wording was replaced in UID0004A0, UID00004S, UID0000J9, UID00014K, UID00049Z, and UID00004R. UID00004R did contain historical stale child-split wording, so it was edited and validated by `000000001233` (`ok: 1`). |

## Implementation Checklist

- [x] Update [UID:0004A0] metadata to `88/90`, `EMITTER_UIDS:00004S`. Proof: UID0004A0 header updated; validator `000000001229` at `2026-06-29T21:31:24-04:00`, exit `0`, `ok: 1`, reported completion/confidence/autogen registry updates for UID0004A0.
- [x] Add the exact formal C++ block to [UID:0004A0]. Proof: UID0004A0 `RECONSTRUCTION_CPP CODE` block contains the exact report C++; generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` now contains UID0004A0 after UID00049Z under latest observed validator header `000000001237`.
- [x] Replace stale blocker text on [UID:0004A0] with current MCP evidence, helper table, behavior, and negative evidence. Proof: UID0004A0 now has MCP Status And Evidence, Signature And Row Layout, Helper And Callee Table, Behavior, Ownership/Exclusions, Boundary Notes, and score rationale; validator `000000001229` `ok: 1`.
- [x] Update [UID:00004S] to show UID0004A0 resolved as first-draft emitting `DrawItemEntry(int, ExchangeItemListRow *, RectBounds *)`. Proof: UID00004S C++ note, method row, evidence notes, no-code proof, exact-child paragraph, and Changes entry updated; validator `000000001230` at `2026-06-29T21:31:33-04:00`, exit `0`, `ok: 1`.
- [x] Ensure [UID:00004S] or source-order support makes `ExchangeItemListRow` available before emitted constructor/draw child bodies. Proof: UID00004S exact-child paragraph now records row declaration/order handling before generated constructor and draw child uses; class C++ remains blank by declaration/container policy; validator `000000001230` `ok: 1`.
- [x] Update [UID:0000J9] private list notes and generated-output caveats for UID0004A0 emission. Proof: UID0000J9 private-list notes and Changes entry now record UID0004A0 emitting through [UID:00004S] and depending on shared ItemObjImageLib/GrafPort/RectBounds/EPFTileContext helpers; validator `000000001231` at `2026-06-29T21:31:41-04:00`, exit `0`, `ok: 1`.
- [x] Update [UID:00014K] split inventory row for UID0004A0. Proof: UID00014K covered-range row and Changes entry now show routed first-draft child `88/90` while aggregate remains non-emitting split container; validator `000000001232` at `2026-06-29T21:31:47-04:00`, exit `0`, `ok: 1`.
- [x] Update stale UID0004A0 non-emitter references in [UID:00004R] and [UID:00049Z] if present. Proof: UID00004R had historical stale "null/draw virtuals remain child-split work" wording, so it was updated and validated by `000000001233` at `2026-06-29T21:31:56-04:00`, exit `0`, `ok: 1`; UID00049Z sibling note was updated and validated by `000000001234` at `2026-06-29T21:32:06-04:00`, exit `0`, `ok: 1`.
- [x] Run the listed validators with `--apply`. Proof: scoped file validators run for all six changed by-* docs: `000000001229` UID0004A0 `ok:1`; `000000001230` UID00004S `ok:1`; `000000001231` UID0000J9 `ok:1`; `000000001232` UID00014K `ok:1`; `000000001233` UID00004R `ok:1`; `000000001234` UID00049Z `ok:1`. Validators for UID0004A0/UID00004S/UID0000J9 warned `missing_ref_uid 0003U3` because accepted evidence references a UID absent from `validator.ini`.
- [x] Confirm generated `ExchangeDialog.cpp` contains UID0004A0 after UID00049Z and that generated output is validator-refreshed only. Proof: latest generated header reads `validator-command-id: 000000001237`, `validator-refreshed-at: 2026-06-29T21:33:24-04:00`, `validator-refresh-source: foreground-generated-refresh`; UID0004A0 appears immediately after UID00049Z. Generated/project-level files were not edited by hand.

## Implementation Callback Audit

Changed by-* docs:

- `by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md`
- `by-class/ExchangeItemListPane.md`
- `by-file/ExchangeDialog.md`
- `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`
- `by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md`
- `by-class/ExchangeDialog.md`

Leases:

- Initial lease command succeeded for UID0004A0 target, UID00004S class, UID0000J9 file, UID00014K aggregate, and UID00049Z sibling.
- Additional lease command succeeded for UID00004R class after a stale historical class-page phrase was found.
- Release command after validators returned `Rejected[No active lease]` for the first five files, meaning those short leases had already expired before release; it returned `Success` for `by-class/ExchangeDialog.md`.

Validator commands:

| File | command_id | command_timestamp | exit | ok | Notes |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md` | `000000001229` | `2026-06-29T21:31:24-04:00` | `0` | `1` | `completion_update 88`, `confidence_update 90`, `autogen_registry_update -> 00004S`; `missing_ref_uid 0003U3` x2. |
| `by-class/ExchangeItemListPane.md` | `000000001230` | `2026-06-29T21:31:33-04:00` | `0` | `1` | `missing_ref_uid 0003U3` x1. |
| `by-file/ExchangeDialog.md` | `000000001231` | `2026-06-29T21:31:41-04:00` | `0` | `1` | `missing_ref_uid 0003U3` x1. |
| `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md` | `000000001232` | `2026-06-29T21:31:47-04:00` | `0` | `1` | no missing-reference warnings. |
| `by-class/ExchangeDialog.md` | `000000001233` | `2026-06-29T21:31:56-04:00` | `0` | `1` | added reference index entries for UID00049Z and UID0004A0. |
| `by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md` | `000000001234` | `2026-06-29T21:32:06-04:00` | `0` | `1` | scoped validator reported deferred generated refresh. |

Generated refresh state:

- Each scoped file validator reported `generated_refresh: deferred`.
- The latest observed `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` header records `validator-command-id: 000000001237`, `validator-refreshed-at: 2026-06-29T21:33:24-04:00`, and `validator-refresh-source: foreground-generated-refresh`.
- Read-only generated check confirms UID0004A0 appears after UID00049Z with the exact accepted `ExchangeItemListPane::DrawItemEntry(int, ExchangeItemListRow *, RectBounds *)` body.

Unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0004A0-ExchangeItemListPaneDrawItemEntry-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0004A0-ExchangeItemListPaneDrawItemEntry-source-quality.md","timestamp":"2026-06-29T21:39:06","uid":"0004A0"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0004A0-ExchangeItemListPaneDrawItemEntry-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0004A0-ExchangeItemListPaneDrawItemEntry-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0004A0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
