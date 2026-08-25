*** UID:00004S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ExchangeItemListRow
{
    unsigned char key;
    unsigned char reserved1;
    unsigned short itemId;
    unsigned char color;
    unsigned char reserved5;
    wchar_t name[256];
};

class ExchangeItemListPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ExchangeItemListPane

## Status

- Likely source file: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Address range: [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md) now acts as the non-emitting split inventory/source-route container, plus shared list-pane destructor [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md)
- Historical recovered-file lead: old `source-3/simroot_v2/class_ExchangeItemListPane.cpp` references are lead material only; current by-* docs, MCP evidence, and generated output control.
- Confidence: very strong for role, row layout, vtable slots, raw helper byte boundaries, source-file routing, and negative route evidence; medium-high for final original helper/draw-virtual names.
- C++ note: this class page now emits only the safe `ExchangeItemListRow` declaration, a narrow class declaration, and `[[CHILDREN]]`. Child pages still own exact source-bearing or covered-by decisions. [UID:00014Q][0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor](by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md) carries guarded first-draft constructor C++ using `sizeof(ExchangeItemListRow)`. [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md) and [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md) are reconstructable/class-owned retained helpers with formal covered-by markers tied to [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) case `2`, not standalone emitted helper bodies. [UID:00049Z][0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual](by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md) now emits first-draft no-op `ExchangeItemListPane::OnItemSelected(int, int)` through this class route at `88/91`; [UID:0004A0][0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry](by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md) now emits first-draft `ExchangeItemListPane::DrawItemEntry(int, ExchangeItemListRow *, RectBounds *)` through this class route at `88/90`.

## Class Purpose

`ExchangeItemListPane` is the private row list used by `ExchangeDialog` for local and remote offered items. Each row stores an item slot/key byte, item id, color byte, and wide item name. The draw path renders the item image and name in the exchange list.

The row payload is now documented as source-facing `ExchangeItemListRow`: key byte at `+0`, padding/reserved byte at `+1`, 16-bit item id at `+2`, color/style byte at `+4`, padding/reserved byte at `+5`, and `wchar_t name[256]` at `+6`, for total row size `0x206`. This layout is corroborated by constructor [UID:00014Q][0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor](by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md)'s row-size argument, [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md)'s write offsets, [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md)'s key scan, [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md)'s inline dispatcher row update, and the draw virtual's reads from `+2/+4/+6`. The constructor's formal C++ should keep `sizeof(ExchangeItemListRow)` instead of a raw `0x206` literal once declaration/order handling places this row declaration before dispatcher and constructor use; the raw literal remains only the binary-equivalent fallback.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScalarDeletingDestructor` | [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md) | Shared list-pane scalar deleting destructor target; also used by `MyItemListPane` and related list panes. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks; ignore for handwritten source. |
| `ExchangeItemListPane` | [UID:00014Q][0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor](by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md) | Raw non-IDA default constructor. It now emits guarded first-draft C++ as `ExchangeItemListPane::ExchangeItemListPane() : ListPane(sizeof(ExchangeItemListRow), 8, 0x9c, 0x18, 0, 1, 1) {}`; the vtable installs are compiler-generated construction side effects. |
| `SetOfferItem` / `UpsertOfferItemRaw` | [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md) | Raw non-IDA helper. Best inferred signature is `SetOfferItem(unsigned char key, unsigned short itemId, unsigned char color, const wchar_t *name)`. It finds/removes an existing row with the same key, reinserts the replacement at the same index, or appends a new row. Direct owner/emitter is this class, but formal C++ is only the covered-by marker for [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) case `2` because route scans found no inbound branch/pointer/vtable path and the live dispatcher case keeps equivalent logic inline. |
| `FindOfferItemRowByKey` | [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md) | Raw non-IDA helper. Best source-facing signature is `int FindOfferItemRowByKey(unsigned char key) const`; returns the row index for a key byte or `-1`; sibling ownership is this class, with source routed through [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md). B004 2026-06-27 current MCP session `398b87c1` keeps no-function/no-route status but adds a formal comment-only covered-by marker because [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) case `2` emits the live row-key scan/update path inline. Do not emit a standalone `FindOfferItemRowByKey` body without future source-route evidence. |
| `OnItemSelected` / no-op ListPane selection callback | [UID:00049Z][0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual](by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md) | Three-byte `ret 8` no-op virtual helper referenced from the primary vtable at `0x00619e40`. B003 current MCP session `691d4db6` resolves the inherited slot blocker by comparing derived slot `0x00619e40 -> 0x004ae1b0` with the base `by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md` primary slot `+0x78` / `0x0061cefc -> 0x004f45b0`, documented by `by-memory/0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md` as the selection update/change operation. The child is now first-draft emitting `88/91` as `void ExchangeItemListPane::OnItemSelected(int, int) {}` through this class route. |
| `DrawItemEntry` / `DrawListEntry` | [UID:0004A0][0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry](by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md) | First-draft emitting `88/90` row draw override `DrawItemEntry(int, ExchangeItemListRow *, RectBounds *)` through `EMITTER_UIDS:00004S`. The primary vtable slot `0x00619e48 -> 0x004ae1c0` draws the item glyph with EPF/high half-size clipped `DrawItemImageScaled` or legacy full-size `DrawItemImage`, then draws the wide item name at x=50. Preferred source-facing name is `DrawItemEntry`; `DrawListEntry` remains only a bounded alternate if inherited `ListPane` naming later standardizes that spelling. |

## Evidence Notes

- The main `ExchangeDialog` constructor creates two list instances through the same constructor bytes at `0x004ae060`.
- `DrawItemEntry` reads item id from row `+2`, item color from row `+4`, and the row name from `+6`.
- `0x004ae0b0` and `0x004ae170` are raw function bodies in IDA memory but not IDA function objects. They are listed here because their row layout matches `DrawItemEntry` and the exchange packet item update logic.
- The raw upsert helper extends through the duplicate-row branch block at `0x004ae156-0x004ae167`; older notes ending at `0x004ae153` were too short.
- 2026-05-26 IDA vtable checks show `0x0047ea50` is not exclusive to `ExchangeItemListPane`; [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) also points its primary destructor slot at this target. Keep feature ownership based on constructors/draw methods, not this shared scalar destructor alone.
- 2026-06-03 IDA MCP `py_eval` confirms exact exclusive raw helper ends: constructor `0x004ae060-0x004ae0a4`, upsert helper `0x004ae0b0-0x004ae167`, find helper `0x004ae170-0x004ae1ac`, null virtual `0x004ae1b0-0x004ae1b3`, and draw virtual `0x004ae1c0-0x004ae4b6`.
- The same IDA pass confirms alignment padding after each raw/helper body: twelve `0xcc` bytes at `0x004ae0a4-0x004ae0b0`, nine at `0x004ae167-0x004ae170`, four at `0x004ae1ac-0x004ae1b0`, thirteen at `0x004ae1b3-0x004ae1c0`, and ten at `0x004ae4b6-0x004ae4c0`.
- IDA named exchange/item read-only data shows `ExchangeItemListPane` vtable views at `0x00619dc8`, `0x00619e50`, and `0x00619e80`; `0x00619e40` points to `nullsub_29`, now source-facing `ExchangeItemListPane::OnItemSelected(int, int)`, and `0x00619e48` points to the draw method at `0x004ae1c0`.
- 2026-06-29 B003 current MCP session `691d4db6` confirms [UID:00049Z][0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual](by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md) as exact bytes `c2 08 00`, with no callers, no callees, no state effects, data xref `0x00619e40`, pre-padding `0x004ae1ac-0x004ae1b0`, and post-padding `0x004ae1b3-0x004ae1c0`. The base/derived vtable comparison resolves `0x00619e40` as the derived override of the `ListPane` primary `+0x78` selection update/change slot, so the no-op `OnItemSelected` child emits through this class. B004 later resolves sibling draw child [UID:0004A0][0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry](by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md) as first-draft emitting `DrawItemEntry(int, ExchangeItemListRow *, RectBounds *)`.
- 2026-06-30 B004 current MCP report evidence resolves [UID:0004A0][0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry](by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md) as exact range `0x004ae1c0-0x004ae4b6`, size `0x2f6`, vtable-only route `0x00619e48 -> 0x004ae1c0`, no direct code callers, inherited draw callback shape `(rowIndex, itemPayload, rowBounds)`, row payload `ExchangeItemListRow *`, EPF/legacy glyph branches, and text draw path. The child now carries `EMITTER_UIDS:00004S` and first-draft C++; shared ItemObjImageLib/GrafPort/RectBounds/EPFTileContext pages remain dependency support only.
- IDA xrefs to the primary vtable pointer `0x00619dc8` come from `ExchangeDialog` constructor stores at `0x004acbef` and `0x004acd9c`, and from this raw constructor at `0x004ae083`, matching the two list instances plus class-local construction path.
- 2026-06-13 B002 post-migration IDA MCP recheck confirms the exact `ExchangeItemListPane` RTTI/vtable child at `0x00619dc4-0x00619e88`: COL `0x00619dc4 -> 0x0064728c`, primary/secondary/tertiary table refs from `sub_4AC8A0` and the raw constructor bytes at `0x004ae083/0x004ae08b/0x004ae095`, and successor `AddItemDialog` COL at `0x00619e88`.
- 2026-06-19 B012 rechecked [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md) with direct PE/Capstone route scans. No branch, instruction-immediate, VA dword, RVA dword, file-offset dword, or vtable route reaches `0x004ae0b0`; positive-control vtable refs exist only for successor null/draw methods at `0x004ae1b0` and `0x004ae1c0`. That recheck resolves the direct owner/emitter to this class, keeps [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) as the source-file route, and explains why the live [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) should keep offered-item update logic inline rather than call the raw no-route helper.

## 2026-06-19 B015 Source-Quality Reanalysis

B015 rechecked the whole class rather than only the upsert helper and raises this page to `87/89`. The owner/emitter route stays [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md): `ExchangeItemListPane` is a private exchange-dialog control in `ExchangeDialog.cpp`, not `MyItemListPane.cpp`, `ListPane.cpp`, or a standalone `ExchangeItemListPane.cpp`. `MyItemListPane` is a structural analogue for item row drawing only, and `ListPane` owns shared storage/selection helpers but not the exchange offer-row semantics.

Exact local PE/range confirmation from the B015 pass:

| Range | Role | Boundary result |
| --- | --- | --- |
| `0x004ae060-0x004ae0a4` | raw constructor | `0x44` / 68-byte raw body; followed by twelve `0xcc` bytes at `0x004ae0a4-0x004ae0b0`. |
| `0x004ae0b0-0x004ae167` | raw upsert helper | `0xb7` / 183-byte raw body; followed by nine `0xcc` bytes at `0x004ae167-0x004ae170`. |
| `0x004ae170-0x004ae1ac` | raw find helper | `0x3c` / 60-byte raw body; followed by four `0xcc` bytes at `0x004ae1ac-0x004ae1b0`. |
| `0x004ae1b0-0x004ae1b3` | primary-vtable null virtual | bytes `c2 08 00`; followed by thirteen `0xcc` bytes at `0x004ae1b3-0x004ae1c0`. |
| `0x004ae1c0-0x004ae4b6` | primary-vtable draw virtual | `0x2f6` / 758-byte method ending with `ret 0x0c`; followed by ten `0xcc` bytes at `0x004ae4b6-0x004ae4c0`. |

Constructor/source route evidence remains through `ExchangeDialog` setup. Code references store the three class views at immediate positions for `0x00619dc8`, `0x00619e50`, and `0x00619e80` from the two `ExchangeDialog` construction paths and from the raw constructor; the report notes that two-byte differences from some older offsets are instruction-start versus immediate-position notation, not semantic disagreement. No branch, pointer, timer, callback, VA/RVA/file-offset, or computed route reaches the raw constructor/upsert/find helper starts. The positive-control scan does find the primary vtable slots `0x00619e40 -> 0x004ae1b0` and `0x00619e48 -> 0x004ae1c0`, proving the scan would have found routed virtuals if the raw helpers had such routes.

`ExchangeItemListRow` is the current best row type name because it matches the class name and current generated dispatcher source without overclaiming protocol wording. The layout is:

```cpp
struct ExchangeItemListRow {
    unsigned char key;       // +0, offer-row key from exchange packet +3
    unsigned char pad1;      // +1, alignment/reserved
    unsigned short itemId;   // +2
    unsigned char color;     // +4, packet color/style byte from +6
    unsigned char pad5;      // +5, alignment/reserved
    wchar_t name[256];       // +6
}; // sizeof == 0x206
```

Use `key` or `offerKey` instead of `slot` unless later protocol work proves packet byte `+3` is an inventory slot. Use `color` for the `+4` byte because packet and generated-source naming currently support color most directly; `style`/`palette` remains a bounded alternative if item-render docs later standardize that byte differently. Do not assign semantics to the padding bytes.

Best helper names and bounded alternatives:

- Constructor: `ExchangeItemListPane::ExchangeItemListPane()`.
- Upsert helper: `SetOfferItem(unsigned char key, unsigned short itemId, unsigned char color, const wchar_t *name)`. Reject `AddItem` because duplicate-key rows are removed/reinserted, reject `InsertItem` because that collides with generic `ListPane::InsertItem`, and treat `UpdateItem`/`SetItem` as less precise alternatives.
- Find helper: `FindOfferItemRowByKey(unsigned char key) const`. `FindOfferItem` is acceptable but less exact because the return value is an index; reject `FindItem` and `FindSlot` as too generic or overclaimed.
- Null virtual: document and emit as `ExchangeItemListPane::OnItemSelected(int, int)`, a no-op override of the inherited `ListPane` primary slot `+0x78` selection update/change callback. Reject `OnClick`/`OnSelect`; they are not supported by the current slot comparison or sibling override style.
- Draw virtual: `DrawItemEntry` is the preferred name, with `DrawListEntry` acceptable if the final `ListPane` virtual naming uses that spelling.

The draw virtual consumes `g_pItemObjImageLib`, `GetItemGlyphBounds`, item-image draw helpers, `EPFTileContext`, `RectBounds` intersection, and `GrafPort` text/color helpers. Those dependencies remain owned by their shared render/image/list modules. The global `g_useEpfAssets`/`0x0066da97` controls high/EPF-style versus legacy item-image rendering but is not owned by this class. `DLGEXC1.EPF`/`.PAL` belong to the exchange dialog background/resource path, not to the row renderer.

No complete class layout should be emitted. The target-specific class-container proof now allows only the formal row struct, forward class declaration, and `[[CHILDREN]]` route marker:

1. This class page is a container/declaration page; method bodies belong on exact by-memory children.
2. `ExchangeItemListRow` is source-quality from the row-size, row-offset, dispatcher, constructor, upsert/find, and draw-child evidence, so the declaration above is safe. A full inherited `ListPane` member layout and helper declarations are still not safe.
3. The raw constructor child [UID:00014Q][0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor](by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md) is the exception accepted for method-level first-draft C++: it has a complete default-constructor shape and now emits the `ListPane(sizeof(ExchangeItemListRow), 8, 0x9c, 0x18, 0, 1, 1)` initializer from its own exact page.
4. Raw upsert/find starts have no direct branch, immediate, VA, RVA, file-offset, callback, data-pointer, or vtable route; subcommand `2` in [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) already emits equivalent row-update behavior inline.
5. The draw virtual is no longer a class-page no-code blocker: [UID:0004A0][0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry](by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md) now emits first-draft `DrawItemEntry(int, ExchangeItemListRow *, RectBounds *)` from its exact child page. The class page remains blank because it is only the declaration/source-route container.
6. The null virtual [UID:00049Z][0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual](by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md) is no longer a class-page no-code blocker: B003 resolved it to a first-draft no-op `OnItemSelected(int, int)` method on the exact child page. The class page itself still does not emit a declaration block.

Exact children now exist for the no-op page [UID:00049Z][0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual](by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md) and draw page [UID:0004A0][0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry](by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md), both directly owned by this class and source-routed through [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md). UID00049Z has `EMITTER_UIDS:00004S` and formal first-draft C++ for the empty `OnItemSelected` override. UID0004A0 now has `EMITTER_UIDS:00004S`, score `88/90`, and formal first-draft C++ for `DrawItemEntry(int, ExchangeItemListRow *, RectBounds *)`. `ExchangeItemListRow` declaration/order handling must be available before the generated constructor and draw child bodies use `sizeof(ExchangeItemListRow)` and `ExchangeItemListRow *`. The shared scalar deleting destructor [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md) and adjustor thunks [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) stay compiler-generated/shared and must not be direct-owned by this class.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md)
- [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md)
- [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md)
- [UID:00014Q][0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor](by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md)
- [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md)
- [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md)
- [UID:00049Z][0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual](by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md)
- [UID:0004A0][0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry](by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md)
- ExchangeItemListPane vtable/read-only data evidence at `0x00619dc4-0x00619e88` and surrounding exchange/item `.rdata`.
- [UID:0001RA][exchange-dialog-resources](by-resource/exchange-dialog-resources.md)

## Changes

- 2026-06-30 B011 accepted UID0000J9 empty-emitter family implementation:
  - Before: `COMPLETION:87`, `CONFIDENCE:89`, blank formal block, with class-page wording still saying no declaration C++ should be emitted.
  - After: `COMPLETION:89`, `CONFIDENCE:90`; formal block now emits the accepted `ExchangeItemListRow` layout, a narrow `ExchangeItemListPane` declaration, and `[[CHILDREN]]`.
  - Summary/evidence: accepted report confirms `key +0`, reserved byte `+1`, `itemId +2`, `color +4`, reserved byte `+5`, `wchar_t name[256] +6`, and total row size `0x206` from the constructor, dispatcher, raw upsert/find helpers, and draw child. Full inherited `ListPane` layout and helper declarations remain intentionally un-emitted; [UID:00049Z][0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual](by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md) and [UID:0004A0][0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry](by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md) now carry exact child method bodies.
- 2026-06-30 B004 UID0004A0 implementation callback:
  - Score unchanged on the class page; class C++ remains blank by declaration/container policy.
  - Summary/evidence: [UID:0004A0][0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry](by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md) now emits first-draft `ExchangeItemListPane::DrawItemEntry(int, ExchangeItemListRow *, RectBounds *)` through this class route at `88/90` with `EMITTER_UIDS:00004S`. Accepted current MCP report evidence proves exact range `0x004ae1c0-0x004ae4b6`, size `0x2f6`, final `ret 0x0c`, vtable route `0x00619e48 -> 0x004ae1c0`, no direct callers, padding `0x004ae1b3-0x004ae1c0` and `0x004ae4b6-0x004ae4c0`, inherited [UID:0003U3][0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry](by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md) draw callback shape `(rowIndex, itemPayload, rowBounds)`, row fields `itemId +2`, `color +4`, `name +6`, EPF half-size clipped `DrawItemImageScaled`, legacy full-size `DrawItemImage(..., nullptr, 0.0f)`, and GrafPort text drawing. The row declaration/source-order caveat remains a class-container integration issue only, not a blocker for UID0004A0's exact child body.
- 2026-06-29 B003 UID00049Z implementation callback:
  - Score unchanged on the class page.
  - Summary/evidence: [UID:00049Z][0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual](by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md) now emits first-draft no-op `ExchangeItemListPane::OnItemSelected(int, int)` through this class route at `88/91`. Current MCP session `691d4db6` proves exact bytes `c2 08 00`, no callees/callers/state effects, vtable xref `0x00619e40`, pre/post padding, and the base/derived `ListPane` primary slot `+0x78` comparison against `0x0061cefc -> 0x004f45b0`. Raw upsert/find helpers remain formal covered-by markers for dispatcher case `2`; the sibling draw child [UID:0004A0][0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry](by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md) is separately resolved by the 2026-06-30 B004 implementation callback.
- 2026-06-28 B001 empty-emitter split implementation:
  - Score unchanged on the class page.
  - Summary/evidence: updated [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md) from blank nonblank emitter wording to a formal covered-by marker for [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) case `2`; added exact child links [UID:00049Z][0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual](by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md) and [UID:0004A0][0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry](by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md), both later resolved by exact implementation callbacks; and recorded [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md)'s non-emitting split/container disposition.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/76`.
  - Summary/evidence: row-list role, raw constructor/upsert/find helpers, draw method, shared destructor caveat, row layout evidence, and exchange-dialog ownership are documented; confidence remains limited by raw non-IDA helper boundaries.
- 2026-06-03 IDA range/vtable pass:
  - Before: class page stayed at `72/76`, unparented, with raw helper ranges named by final-byte addresses and incomplete vtable slot evidence.
  - Changed to: `78/84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000J9`.
  - Summary/evidence: IDA MCP proved exact exclusive helper ranges, byte padding, real null/draw virtual function objects, all three `ExchangeItemListPane` vtable views, and vtable pointer stores from both `ExchangeDialog` constructor paths plus the raw constructor. At that time class C++ stayed blank because helper names/source spelling remained below the then-active reconstruction-code bar.
- 2026-06-13 B002 post-migration split:
  - Before: the class page remained just below the strict owner gate at `78/84`, which blocked exact vtable child ownership despite strong constructor/helper evidence.
  - Changed to: `85/86`; kept [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) as canonical owner/emitter.
  - Summary/evidence: live IDA MCP and PE/raw checks reconfirmed the exact RTTI/vtable child `0x00619dc4-0x00619e88`, constructor stores from the two `ExchangeDialog` list instances, class-local raw constructor stores, helper/draw slot layout, and the shared-destructor caveat. This is enough for source routing of the vtable child while still below final rewrite confidence.
- 2026-06-19 B012 upsert-helper source-quality sync:
  - Changed to: `CONFIDENCE:87`; completion remains `85`.
  - Summary/evidence: incorporated [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md)'s best `SetOfferItem` signature, `ExchangeItemListRow` padding/size, duplicate remove/reinsert semantics, no-route PE/Capstone proof, class-owner correction, and dispatcher-inline source-shape decision. Class-level C++ remains blank because exact declarations/layout are still represented through child pages rather than a final integrated class header.
- 2026-06-19 B015 class source-quality reanalysis:
  - Changed to: `COMPLETION:87`, `CONFIDENCE:89`; kept `CANONICAL_OWNER:0000J9`, `EMITTER_UIDS:0000J9`, and blank formal C++.
  - Summary/evidence: incorporated class-wide PE/range verification, constructor/upsert/find/null/draw padding, primary/secondary/tertiary vtable store refs, positive-control null/draw vtable slots, negative route scans for raw constructor/upsert/find starts, `ExchangeItemListRow` field naming, best helper names, rejected owner/name alternatives, shared destructor caveat, and the then-current target-specific no-code proof that declarations/emitter order plus null/draw child splits had to be solved before class-page C++. B003 and B004 later resolved the exact null/draw child bodies while preserving this class page's blank declaration/container policy.
- 2026-06-25 B009 accepted constructor implementation:
  - Score unchanged on the class page.
  - Summary/evidence: [UID:00014Q][0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor](by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md) now emits guarded first-draft default-constructor C++ with `ListPane(sizeof(ExchangeItemListRow), 8, 0x9c, 0x18, 0, 1, 1)`. The class page remains a declaration/container page; [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md) and [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md) now use formal covered-by markers because their no-route evidence remains unresolved.
- 2026-06-27 B004 find-helper covered-by implementation:
  - Score unchanged on the class page.
  - Summary/evidence: [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md) now carries `88/91` and a formal comment-only covered-by marker, not a standalone helper body. Current MCP session `398b87c1` reconfirmed the exact `0x3c` / 60-byte raw body (Verified with int_convert.py), row-key compare at `+0`, no start/end xrefs, no VA/RVA/file-offset pointer-pattern route, no focused ExchangeDialog-cluster immediate route, and positive-control vtable routes for the neighboring null/draw virtuals. The emitted behavior is represented by [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) case `2`.
