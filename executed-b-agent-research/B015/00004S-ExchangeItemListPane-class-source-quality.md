** TARGET-REPORT-UID:00004S **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00004S ExchangeItemListPane Class Source-Quality Reanalysis

Agent: B015  
Date: 2026-06-19  
Target: [UID:00004S] `by-class/ExchangeItemListPane.md`  
Required output path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\00004S-ExchangeItemListPane-class-source-quality.md`  
Pass type: report-only B-agent source-quality pass. No `by-*` documentation files and no `by-memory/-coverage-report.md` were edited for this report.

## Executive Recommendation

Recommend updating [UID:00004S] from `COMPLETION:85` / `CONFIDENCE:86` to `COMPLETION:87` / `CONFIDENCE:89`, while keeping:

- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0000J9`
- `EMITTER_UIDS:0000J9`
- formal C++ block blank for now

The class is source-owned by `ExchangeDialog.cpp` as a private exchange-dialog list widget, not by `MyItemListPane.cpp`, `ListPane.cpp`, or a standalone source file. The raw constructor, raw upsert helper, raw find helper, primary/secondary/tertiary vtable views, null virtual, and draw virtual all support the `ExchangeItemListPane` identity. The row layout is now strong enough to name as `ExchangeItemListRow`, with row key at `+0`, item id at `+2`, color/style byte at `+4`, wide item name at `+6`, and total row size `0x206`.

Do not emit first-draft C++ on the class page yet. The class page is a container/declaration page, the live packet dispatcher currently emits equivalent item-row update logic inline, the raw upsert/find starts still have no branch/pointer/data route, and the current generator order places the dispatcher body before the `ExchangeItemListPane` marker. A future implementation callback should first add or position stable row/class declarations and split the vtable-routed null/draw virtuals into exact child docs before emitting source code.

## Evidence Checked

Primary target and source-owner docs:

- `by-class/ExchangeItemListPane.md`
- `by-class/ExchangeDialog.md`
- `by-file/ExchangeDialog.md`
- `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`
- `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`

Direct child/support docs:

- `by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md`
- `by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md`
- `by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md`
- `by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md`
- `by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md`
- `by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md`
- `by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md`

Render/list-pane/type/resource context:

- `by-file/ListPane.md`
- `by-class/ListPane.md`
- `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`
- `by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md`
- `by-type/by-struct/MyItemListPaneEntryLayouts.md`
- `by-global/g_pItemObjImageLib.md`
- `by-item/GetItemGlyphBounds_004DF460.md`
- `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`
- `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
- `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
- `by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-resource/exchange-dialog-resources.md`

Read-only raw PE recheck:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5 observed in local scanner: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- Relevant sections observed:
  - `.text` `0x00401000-0x0060c4ac`
  - `.rdata` `0x0060d000-0x0066c0be`

## Exact Range, Padding, And Raw-Modeling Recheck

The target class currently aggregates multiple exact ranges. Local PE scanning confirmed that the documented half-open ranges and padding boundaries are valid:

| Range | Size | Modeling status | Boundary / padding result |
| --- | ---: | --- | --- |
| `0x004ae060-0x004ae0a4` | `0x44` / 68 bytes | raw constructor, not IDA function | next `0x004ae0a4-0x004ae0b0` is 12 bytes of `0xcc` |
| `0x004ae0b0-0x004ae167` | `0xb7` / 183 bytes | raw upsert helper, not IDA function | next `0x004ae167-0x004ae170` is 9 bytes of `0xcc` |
| `0x004ae170-0x004ae1ac` | `0x3c` / 60 bytes | raw find helper, not IDA function | next `0x004ae1ac-0x004ae1b0` is 4 bytes of `0xcc` |
| `0x004ae1b0-0x004ae1b3` | 3 bytes | primary-vtable null virtual, IDA `nullsub_29` in aggregate docs | `c2 08 00`; next `0x004ae1b3-0x004ae1c0` is 13 bytes of `0xcc` |
| `0x004ae1c0-0x004ae4b6` | `0x2f6` / 758 bytes | primary-vtable draw virtual | ends with `ret 0xc`; next `0x004ae4b6-0x004ae4c0` is 10 bytes of `0xcc` |

The raw constructor/upsert/find starts are still not directly address-taken by code or data in the local scan. Positive-control vtable slots do resolve for the successor virtuals:

- `0x00619e40 -> 0x004ae1b0`
- `0x00619e48 -> 0x004ae1c0`

This means the raw helper no-route conclusion is not caused by a broken scan: the same scan finds vtable data for the routed virtuals and shared destructor entries.

## Caller / Reachability / Source Route

### Constructor Route

`ExchangeItemListPane` instances are constructed from `ExchangeDialog` setup code. Current docs record primary vtable store references from:

- `0x004acbef`
- `0x004acd9c`
- `0x004ae083`

The local dword scan found the primary/secondary/tertiary vtable pointer stores as code references:

- `0x00619dc8` references in code at `0x004acbf1`, `0x004acd9e`, `0x004ae085`
- `0x00619e50` references in code at `0x004acbfb`, `0x004acda8`, `0x004ae091`
- `0x00619e80` references in code at `0x004acc05`, `0x004acdb2`, `0x004ae09b`

The slight two-byte difference from some doc offsets is instruction-start versus immediate-position notation, not a semantic conflict. The route is still through `ExchangeDialog.cpp`.

### Raw Upsert Helper Route

No direct branch, immediate, VA, RVA, or file-offset reference to `0x004ae0b0` was found. The only internal branch into the upsert tail is from inside the same raw helper:

- `0x004ae0ed` conditionally branches to `0x004ae156`.

The live packet dispatcher [UID:00014L] implements the same row-update behavior inline for packet subcommand `2`. It decodes:

- packet `+2`: local/remote side selector
- packet `+3`: offer-row key
- packet `+4`: item id word
- packet `+6`: color/style byte
- packet `+7`: item-name byte length
- packet `+8`: counted CP_ACP item-name bytes

It converts the name to wide characters, selects control `5` or `8`, scans existing rows by key, removes a duplicate row, and inserts a new row. That is exactly the behavior of `0x004ae0b0-0x004ae167`, but the raw helper itself remains no-route.

Best conclusion: the helper represents source-like private logic that the current binary retains as a raw code island or clone, but the live reconstructed source route for packet subcommand `2` is currently inline in `ExchangeDialogPacketDispatcher`. It should be documented and named, but not emitted as callable source until a real route is found or a supervisor intentionally reconstructs the original helper abstraction.

### Raw Find Helper Route

No direct branch, immediate, VA, RVA, or file-offset reference to `0x004ae170` was found. It loops over the list item count, fetches each row by index, compares the row key at `+0`, returns the found index, or returns `-1`.

Best conclusion: this is a no-route retained/private helper candidate. It is strongly class-local, but not live-reachable enough for emitted C++.

### Null And Draw Virtual Route

The null and draw virtuals are routed through the primary vtable:

- Primary vtable slot `0x00619e40` points at `0x004ae1b0`
- Primary vtable slot `0x00619e48` points at `0x004ae1c0`

These should not remain merely buried in the aggregate forever. They deserve exact child docs under [UID:00004S], especially the draw virtual. The null virtual is source-relevant as a class vtable slot but its original source-facing name is not safely recoverable until the inherited `ListPane` virtual slot map is named more completely.

### Data Pointers, Vtables, Computed Calls, Timers, And Adjacent State

Checked evidence did not reveal a data-pointer/callback/timer route to the raw constructor/upsert/find helper starts. This target is UI-dialog/list-pane code, not timer-managed code. The relevant dynamic route is the vtable route for the null/draw virtuals and the direct constructor/vtable-store route from `ExchangeDialog` setup. Adjacent `MyItemListPane` code is a strong structural analogue for row drawing, but it is not ownership evidence for this class.

## Heuristic / Inference Reanalysis And Validation

### Class Name And Source Placement

Best-supported source-facing class name: `ExchangeItemListPane`.

Evidence:

- Target class doc, vtable data doc, and ExchangeDialog docs all consistently use `ExchangeItemListPane`.
- Constructor stores class-specific primary/secondary/tertiary vtable views at `0x00619dc8`, `0x00619e50`, and `0x00619e80`.
- ExchangeDialog creates two offered-item lists, one for local offered items and one for remote offered items, matching controls `5` and `8`.
- `by-file/ExchangeDialog.md` states that `ExchangeDialog.cpp` owns the private `ExchangeItemListPane`.

Rejected alternatives:

- `MyItemListPane`: rejected as owner/source placement. It shares row/draw design patterns, but has its own source file and separate class identity. It is an analogue only.
- `ListPane`: rejected as owner/source placement. `ListPane` owns generic list storage helpers, not the exchange-offer row semantics.
- standalone `ExchangeItemListPane.cpp`: rejected because proposed source tree and by-file docs place it in `ExchangeDialog.cpp`, and no standalone file route is documented.

Recommendation: keep `CANONICAL_OWNER:0000J9` and `EMITTER_UIDS:0000J9` on the class page. Children that are class methods should use `CANONICAL_OWNER:00004S` and `EMITTER_UIDS:00004S`, with source output routed through `ExchangeDialog.cpp`.

### Row Type Name And Field Names

Best-supported row type name: `ExchangeItemListRow`.

This name is already used by the generated dispatcher source in `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`. It is also consistent with the class name and avoids overclaiming protocol-specific original wording.

Best-supported row layout:

```cpp
struct ExchangeItemListRow {
    unsigned char key;       // +0, offer-row key from exchange packet +3
    unsigned char pad1;      // +1, alignment/reserved
    unsigned short itemId;   // +2
    unsigned char color;     // +4, item color/style byte from packet +6
    unsigned char pad5;      // +5, alignment/reserved
    wchar_t name[256];       // +6
}; // sizeof == 0x206
```

Field inference:

- `key` / `offerKey` is better supported than `slot` as the primary source-facing name because the dispatcher obtains it from the exchange packet row-key field at `packet + 3`; it is used only for duplicate detection/find within the offered-item list. It may correspond to an inventory slot upstream, but the local code treats it as the exchange-offer row key.
- `itemId` at `+2` is supported by raw upsert copying a word from its second argument and draw virtual passing the word into item-image lookup/render helpers.
- `color` or `itemColor` at `+4` is supported by the dispatcher packet byte at `+6`, raw upsert byte copy, and draw virtual's item-render branch. Existing generated code uses `color`; keep that unless broader item-render docs standardize the field as `style` or `palette`.
- `name[256]` at `+6` is supported by `_wcscpy_s` capacity `0x100` and draw virtual copying from row `+6` before drawing text.
- `pad1` and `pad5` are alignment/reserved bytes. No semantic evidence supports naming them as flags.

Rejected alternatives:

- `ExchangeOfferItemRow`: semantically attractive, but not currently used in generated source and does not match the class name as closely.
- `itemStyle` instead of `color`: possible if future item-render docs standardize the byte as style/category. Current packet and generated-source naming support `color` most directly.
- `slot` instead of `key`: possible if packet field `+3` is proven to be inventory slot. Current binary evidence only proves row-key behavior.

### Constructor Name And Signature

Best-supported source-facing constructor: `ExchangeItemListPane::ExchangeItemListPane()`.

The raw constructor pushes these arguments before calling `0x004f3a50`:

- `0x206`: row payload size
- `8`: visible/list row count
- `0x9c`: pane/list width argument
- `0x18`: row height
- `0`
- `1`
- `1`

It then installs primary, secondary, and tertiary vtable views at offsets:

- `+0`
- `+0xa0`
- `+0xa4`

Do not emit constructor C++ yet because final `ListPane` constructor parameter names and the class declaration/vtable layout are not stable enough for a source-quality constructor body. The behavior and source name are strong enough for docs.

### Upsert Helper Name And Signature

Best-supported source-facing helper name:

```cpp
void ExchangeItemListPane::SetOfferItem(
    unsigned char key,
    unsigned short itemId,
    unsigned char color,
    const wchar_t *name);
```

Evidence:

- `ret 0x10` proves four stack arguments.
- The receiver is in `ecx`.
- The helper scans existing rows and compares row `+0` against the first byte argument.
- If a matching row exists, it removes one row at that index and continues to the insert path.
- It writes row `+0`, `+2`, `+4`, and wide string at `+6`.
- It uses `_wcscpy_s` with capacity `0x100`, matching a 256-wide-character row name buffer.
- It calls shared list helpers corresponding to item count, item pointer/access, remove, and insert.

Rejected alternatives:

- `AddItem`: rejected because the duplicate-key path removes an existing row first; the operation is set/upsert, not unconditional add.
- `InsertItem`: rejected because that collides with the generic `ListPane::InsertItem` callee and hides the duplicate-key semantics.
- `UpdateItem`: plausible but less precise than `SetOfferItem`; the packet case may create a row if absent.
- `SetItem`: plausible but too generic for a private class with exchange offer semantics.

Ownership recommendation for [UID:00014R]: change direct owner/emitter from [UID:0000J9] to [UID:00004S]. It is a class method/helper. The class then routes to [UID:0000J9] for source output.

Emission recommendation for [UID:00014R]: keep C++ blank until a real route or intentional abstraction callback exists. The live dispatcher already emits equivalent case-2 logic inline.

### Find Helper Name And Signature

Best-supported source-facing helper name:

```cpp
int ExchangeItemListPane::FindOfferItemRowByKey(unsigned char key) const;
```

Evidence:

- `ret 4` proves one stack argument.
- The receiver is in `ecx`.
- The helper calls list item count helper `0x004f3bd0`.
- It calls list row access helper `0x004f3dc0` with an explicit index.
- It compares the row byte at `+0` against the argument.
- It returns the matching index or `-1`.

Rejected alternatives:

- `FindOfferItem`: acceptable if the project prefers compact names, but less exact because the function returns a row index, not an item pointer.
- `FindItem`: too generic and conflicts with inventory/item library terminology.
- `FindSlot`: overclaims that the key is an inventory slot.

Ownership recommendation for [UID:00014S]: change direct owner/emitter from [UID:0000J9] to [UID:00004S]. It is a class method/helper. The class then routes to [UID:0000J9].

Emission recommendation for [UID:00014S]: keep C++ blank because no route proves the retained helper should be emitted.

### Null Virtual Name And Signature

Current code at `0x004ae1b0-0x004ae1b3` is:

- `ret 8`

The primary vtable routes to it at slot `0x00619e40`. It is not safe to assign a final source-facing method name yet because the inherited `ListPane` virtual slot immediately before the draw slot is not fully named in the checked evidence. It likely corresponds to a per-row/list action callback that this class intentionally leaves empty, but the exact callback contract is not proven.

Best documentation name for now: `ExchangeItemListPaneNullVirtual` or `ExchangeItemListPaneNoopListVirtual`.

Rejected alternatives:

- `OnClick`: possible but unsupported by the current slot evidence.
- `OnSelect`: possible but unsupported by the current slot evidence.
- `DrawItemEntry`: rejected for the null slot because the following slot at `0x00619e48` is the actual draw virtual.

Recommendation: split it into an exact by-memory child only if the supervisor wants coverage granularity. Keep C++ blank until the ListPane vtable slot map names the callback.

### Draw Virtual Name, Helper Names, And Source-Like Role

Best-supported source-facing method name: `DrawItemEntry`.

Acceptable alternate if ListPane virtual naming is standardized: `DrawListEntry`.

Evidence:

- It is vtable-routed through `0x00619e48`.
- It is the visual row renderer for exchange offered-item rows.
- It draws item glyphs and wide item names using the same row payload layout as upsert/find.
- `MyItemListPaneDrawListEntry` is a close analogue, but `ExchangeItemListPane` has its own simpler no-selection row drawing behavior.

Observed draw helper calls:

- `0x00457a60`: initializes a 0x28-byte tile/image context. Source-facing owner is `EPFTileContext`.
- `0x004df460`: best documented as `GetItemGlyphBounds`.
- `0x004b7cc0`: rectangle intersection helper, documented as `IntersectRects`.
- `0x004df2c0`: documented in item image cluster as scaled item draw helper.
- `0x004dee50`: documented in item image cluster as unscaled item draw helper.
- `0x004b9680`: `GrafPort` draw/text color setter/accessor family.
- `0x004b9690`: `GrafPort` secondary/background/outline color setter/accessor family.
- `0x004b9600`: `GrafPort::MoveTo`.
- `0x004bab70`: `GrafPort::DrawWideText`.
- `_wcscpy_s`: copies row name into a local wide buffer.
- `0x005c772f`: security-cookie check.

Global/resource ownership:

- `g_pItemObjImageLib` at `0x0067a758` is consumed by the draw virtual but owned by `ItemObjImageLib`.
- `DLGEXC1.EPF` / `.PAL` belong to the exchange dialog background/resource path, not to the offered-item list row renderer.
- `g_useEpfAssets` / `0x0066da97` branch controls high/EPF-style rendering versus legacy item-image rendering. The draw virtual consumes this global mode but does not own it.

Rejected alternatives:

- Assigning draw helpers to `ExchangeItemListPane`: rejected. They are shared render/list helpers and item-image library methods.
- Treating the draw virtual as `MyItemListPane` code: rejected. Similar row fields are analogue evidence, not ownership.
- Emitting draw C++ inside the class page now: rejected because the draw virtual lacks an exact by-memory child page and final inherited virtual signature.

Recommendation: create a child page for `0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md` owned by [UID:00004S], then decide C++ after the signature and helper names are stabilized.

### Shared Destructor And Adjustor Thunks

`0x0047ea50-0x0047ea8b` is a shared scalar deleting destructor used by multiple `ListPane`-derived classes:

- BoardListPane
- ClanStringListPane
- ClanJoinListPane
- ClanEnlistListPane
- ExchangeItemListPane
- MyItemListPane

It calls normal `ListPane` cleanup and conditionally frees storage. It is compiler-generated glue, not an `ExchangeItemListPane` source method to emit in `ExchangeDialog.cpp`.

`0x0047e8ad` and `0x0047e8b8` are secondary/tertiary destructor adjustor thunks that target the shared destructor. They are also compiler-generated and should remain non-source/ignored.

Recommendation: the class doc should keep the shared destructor caveat explicit, but [UID:0000ZR] and [UID:0000ZP] should not be direct-owned by [UID:00004S].

### Vtable/Base Layout

Best-supported facts:

- Primary table starts at `0x00619dc8`.
- Secondary table starts at `0x00619e50`.
- Tertiary table starts at `0x00619e80`.
- Constructor writes the views at `this+0`, `this+0xa0`, and `this+0xa4`.
- The RTTI/COL pointer before the primary table is `0x00619dc4 -> 0x0064728c`.
- Successor AddItemDialog COL boundary at `0x00619e88` is the exact end boundary for ExchangeItemListPane vtable data.

Best-supported inference:

- The class inherits from a `ListPane` family with multiple base/view subobjects. The exact base names for the secondary and tertiary views should not be guessed from offsets alone.

Rejected alternative:

- Declaring named secondary/tertiary base classes now. The current evidence proves vtable views and offsets, not source base-class names.

### Generated-Source Gap

Current generated `ExchangeDialog.cpp` emits the packet dispatcher first, and the dispatcher uses `ExchangeItemListRow` and `ExchangeItemListPane *`. Later, the file contains only empty marker comments for `ExchangeItemListPane`, the raw constructor, raw helpers, and vtable data.

This is a real generated-source gap:

- The row struct is strongly supported but is not emitted before the dispatcher use.
- The class declaration is not emitted before the dispatcher use.
- Adding a class-page C++ block without solving emitter order could still place declarations too late.

Recommendation:

- Do not patch generated source by hand.
- In the implementation callback, either add a declaration/type child that emits before [UID:00014L] or assign the class/row declaration an emitter position that precedes the dispatcher in `ExchangeDialog.cpp`.
- Keep method bodies on by-memory children, not on the class page.

## Source-Facing Name Recommendations

| Binary/raw name or unclear item | Recommended source-facing name/type | Confidence | Rationale |
| --- | --- | ---: | --- |
| class `ExchangeItemListPane` | `ExchangeItemListPane` | high | Consistent class/vtable/source-owner evidence |
| row payload type | `ExchangeItemListRow` | high | Already used by generated dispatcher, class-local row payload |
| row `+0` | `key` or `offerKey` | high | Packet row key and duplicate-search key |
| row `+1` | `pad1` / reserved | medium-high | Alignment byte, no semantic use found |
| row `+2` | `itemId` | high | Packet word, item image lookup/render input |
| row `+4` | `color` or `itemColor` | medium-high | Packet byte and item-render style/color input |
| row `+5` | `pad5` / reserved | medium-high | Alignment byte, no semantic use found |
| row `+6` | `name[256]` | high | `_wcscpy_s` capacity `0x100`, draw text source |
| `0x004ae060` | `ExchangeItemListPane::ExchangeItemListPane()` | high | Constructor body and vtable stores |
| `0x004ae0b0` | `SetOfferItem(unsigned char key, unsigned short itemId, unsigned char color, const wchar_t *name)` | high for role/name, low for original spelling | Upsert semantics and four-arg `ret 0x10` |
| `0x004ae170` | `FindOfferItemRowByKey(unsigned char key) const` | high for role/name, low for original spelling | Key scan returning index or `-1` |
| `0x004ae1b0` | no final source name; doc as null/no-op list virtual | medium role, low exact name | Vtable slot but inherited virtual contract unresolved |
| `0x004ae1c0` | `DrawItemEntry` or `DrawListEntry` | high role, medium exact spelling | Vtable row renderer; MyItemListPane analogue |
| `0x004f3bd0` | `ListPane::GetItemCount` | high | Existing ListPane docs |
| `0x004f3dc0` | `ListPane::GetItemData` / `GetItem` / current docs `GetSelectedEntry` | medium | Explicit index row access; current helper name may be too selection-specific |
| `0x004f3d60` | `ListPane::RemoveItems` | high | Existing docs and two-arg remove behavior |
| `0x004f3c00` | `ListPane::InsertItem` | high | Existing docs |
| `0x004df460` | `GetItemGlyphBounds` | high | Existing item helper docs |
| `0x004df2c0` | `ItemObjImageLib::DrawItemImageScaled` | high | Existing item image docs |
| `0x004dee50` | `ItemObjImageLib::DrawItemImage` | high | Existing item image docs |
| `0x004b9600` | `GrafPort::MoveTo` | high | Existing GrafPort docs |
| `0x004bab70` | `GrafPort::DrawWideText` | high | Existing GrafPort text docs |

## First-Draft C++ Recommendation / Target-Specific No-Code Proof

Do not emit formal first-draft C++ for [UID:00004S] in this pass.

This is not a generic "not ready" conclusion. The target-specific proof is:

1. [UID:00004S] is a class/container page. The project rules say class/container pages should emit declarations or declarations-only material, while child by-memory pages own method bodies. Emitting constructor/upsert/find/draw bodies on the class page would put code in the wrong owner surface.

2. The row struct is strong, but the current generated `ExchangeDialog.cpp` emits [UID:00014L] dispatcher code before the `ExchangeItemListPane` marker. If a row/class declaration is added to the target without solving emitter ordering, generated code may still use `ExchangeItemListRow` before declaration.

3. The raw constructor/upsert/find code starts still have no direct branch, immediate, VA, RVA, file-offset, callback, or data-pointer route. The raw upsert logic is already represented in live dispatcher case `2` as inline code. Emitting the raw helper bodies now would duplicate behavior without a proven source route.

4. The vtable-routed draw virtual is source-bearing, but it lacks an exact child page and final inherited virtual signature. It should be split before C++ is emitted.

5. The vtable-routed null virtual is source-relevant but the original method name and callback contract are not safely known.

Recommended future declaration direction, not a formal C++ block for this target yet:

```cpp
struct ExchangeItemListRow {
    unsigned char key;
    unsigned char pad1;
    unsigned short itemId;
    unsigned char color;
    unsigned char pad5;
    wchar_t name[256];
};
```

Potential class declaration after emitter-order and ListPane slot naming are solved:

```cpp
class ExchangeItemListPane : public ListPane {
private:
    void SetOfferItem(unsigned char key, unsigned short itemId, unsigned char color, const wchar_t *name);
    int FindOfferItemRowByKey(unsigned char key) const;
    // inherited virtual override declarations require final ListPane slot names
};
```

The declaration above is source-quality guidance only. It should not be copied into `by-class/ExchangeItemListPane.md` until the callback also solves declaration placement before [UID:00014L].

## Score, Owner, Emitter, And Reconstructable Recommendations

| UID | Current / recommended | Recommendation |
| --- | --- | --- |
| [UID:00004S] `ExchangeItemListPane` | current `85/86`; recommend `87/89` | Keep reconstructable true, owner/emitter [UID:0000J9], blank C++; add Rule 26 reanalysis and no-code proof |
| [UID:00014Q] raw constructor | current `86/88`; keep or raise confidence to `86/89` | Owner/emitter already [UID:00004S]; keep blank C++; clarify exact no-route/declaration blocker |
| [UID:00014R] raw upsert | current `85/87`; recommend `86/89` | Change direct owner/emitter from [UID:0000J9] to [UID:00004S]; keep blank C++; name as `SetOfferItem` |
| [UID:00014S] raw find | current `85/88`; recommend `86/89` | Change direct owner/emitter from [UID:0000J9] to [UID:00004S]; keep blank C++; name as `FindOfferItemRowByKey` |
| [UID:0003NF] vtable data | current `85/90`; keep | Owner/emitter [UID:00004S]; sync coverage row if missing |
| [UID:0000ZR] shared destructor | current `85/90`; keep ignored/non-reconstructable | Keep `CANONICAL_OWNER:NONE`; do not source-own to ExchangeItemListPane |
| [UID:0000ZP] adjustor thunks | current `82/90`; keep ignored/non-reconstructable | Keep compiler-generated; do not source-own to ExchangeItemListPane |
| new child for `0x004ae1b0-0x004ae1b3` | no exact child currently | Recommend exact child doc if supervisor wants granular coverage; likely owner [UID:00004S], C++ blank |
| new child for `0x004ae1c0-0x004ae4b6` | no exact child currently | Recommend exact child doc for `DrawItemEntry`; owner [UID:00004S], likely reconstructable after signature work |

The class score should remain below 90 because final declaration/emitter ordering, the ListPane virtual slot names, and child split coverage for null/draw are still unresolved. The confidence can rise because the negative evidence for raw helper liveness and positive vtable/source-owner evidence are now directly rechecked.

## Target / Support / Generated Implementation Checklist

Use this checklist only after supervisor acceptance. Do not apply during the report-only pass.

### Target [UID:00004S] `by-class/ExchangeItemListPane.md`

- Update metadata to `COMPLETION:87` and `CONFIDENCE:89`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `CANONICAL_OWNER:0000J9`.
- Keep `EMITTER_UIDS:0000J9`.
- Keep formal C++ blank.
- Add or replace the source-quality analysis with a full `## Heuristic / Inference Reanalysis And Validation` section.
- Record `ExchangeItemListRow` as the best-supported row type:
  - `+0 key` / `offerKey`
  - `+1 pad1`
  - `+2 itemId`
  - `+4 color` / `itemColor`
  - `+5 pad5`
  - `+6 wchar_t name[256]`
  - `sizeof 0x206`
- Record best helper names:
  - constructor: `ExchangeItemListPane::ExchangeItemListPane()`
  - upsert: `SetOfferItem`
  - find: `FindOfferItemRowByKey`
  - null virtual: no final name; document as no-op/slot-name pending
  - draw virtual: `DrawItemEntry` preferred; `DrawListEntry` acceptable if ListPane slot naming standardizes that wording
- Record target-specific no-code proof:
  - class page is a declaration/container page;
  - generated dispatcher currently precedes class marker;
  - raw helpers have no-route evidence;
  - vtable draw needs exact child split and signature work.

### Support [UID:00014Q] `0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md`

- Keep owner/emitter [UID:00004S].
- Keep formal C++ blank.
- Incorporate the local PE range/padding confirmation:
  - exact body `0x44` / 68 bytes;
  - next padding `0x004ae0a4-0x004ae0b0` is 12 bytes of `0xcc`.
- Replace old generic "90/90+ code gate" wording with the current target-specific blocker:
  - constructor behavior is well understood, but class declaration/order and final `ListPane` constructor spelling should be solved before emission.

### Support [UID:00014R] `0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md`

- Update direct metadata:
  - `CANONICAL_OWNER:00004S`
  - `EMITTER_UIDS:00004S`
  - recommended `COMPLETION:86`
  - recommended `CONFIDENCE:89`
- Keep formal C++ blank.
- Incorporate B012/B015 conclusion:
  - best source name `SetOfferItem`;
  - four stack args with `ret 0x10`;
  - duplicate-key remove/reinsert path;
  - no branch/VA/RVA/file-offset route to `0x004ae0b0`;
  - dispatcher case `2` emits equivalent live logic inline.

### Support [UID:00014S] `0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md`

- Update direct metadata:
  - `CANONICAL_OWNER:00004S`
  - `EMITTER_UIDS:00004S`
  - recommended `COMPLETION:86`
  - recommended `CONFIDENCE:89`
- Keep formal C++ blank.
- Add best source name/signature:
  - `int FindOfferItemRowByKey(unsigned char key) const`
- Add local PE confirmation:
  - exact body `0x3c` / 60 bytes;
  - next padding `0x004ae1ac-0x004ae1b0` is 4 bytes of `0xcc`;
  - no branch/VA/RVA/file-offset route to `0x004ae170`.

### Support New Child: `0x004ae1b0-0x004ae1b3`

- Create an exact by-memory child if supervisor wants coverage granularity.
- Suggested title: `ExchangeItemListPaneNullVirtual`.
- Owner/emitter: [UID:00004S].
- Record:
  - bytes `c2 08 00`;
  - primary vtable slot `0x00619e40`;
  - source callback role not safely named;
  - blank C++ until `ListPane` slot names are resolved.

### Support New Child: `0x004ae1c0-0x004ae4b6`

- Create an exact by-memory child for the draw virtual.
- Suggested title: `ExchangeItemListPaneDrawItemEntry`.
- Owner/emitter: [UID:00004S].
- Record:
  - exact body `0x2f6` / 758 bytes;
  - primary vtable slot `0x00619e48`;
  - high/EPF branch controlled by `0x0066da97`;
  - item image render helpers `0x004df460`, `0x004df2c0`, `0x004dee50`;
  - `GrafPort` text/color helpers;
  - row `+2`, `+4`, `+6` usage;
  - C++ decision deferred until signature and ListPane slot naming are solved.

### Support [UID:0003NF] `0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md`

- Existing doc is strong; sync coverage if stale/missing.
- Preserve successor boundary at `0x00619e88`.
- Preserve primary/secondary/tertiary vtable refs and shared destructor caveat.

### Support [UID:0000ZR] / [UID:0000ZP]

- Do not reassign to [UID:00004S].
- Keep shared/compiler-generated status.
- If target doc mentions destructor, keep caveat that the destructor is shared scalar deleting glue, not source-owned Exchange code.

### Source-Owner / Generated Files

- Update `by-file/ExchangeDialog.md` only if a later callback asks for support synchronization:
  - clarify that `ExchangeItemListPane` is a private class in `ExchangeDialog.cpp`;
  - clarify raw helper direct owners are [UID:00004S].
- Do not hand-edit `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- After by-doc changes, run the validator with `--apply` to regenerate output.
- If class/row declarations are accepted, solve declaration ordering so `ExchangeItemListRow` and `ExchangeItemListPane` appear before [UID:00014L] dispatcher output.

## Exact Supervisor-Owned Coverage Text

These are proposed exact rows for supervisor-owned coverage files. They were not applied during this report-only pass.

### `by-class/-coverage-report.md` replacement row

```md
- [UID:00004S][ExchangeItemListPane](by-class/ExchangeItemListPane.md) : reconstructable : 87% : strong : B015 2026-06-19 class source-quality reanalysis confirms ExchangeDialog-owned private offered-item list pane, exact constructor/upsert/find/null/draw half-open ranges and padding, row layout `ExchangeItemListRow` key `+0`, item id `+2`, color/style `+4`, wide name `+6`, total row size `0x206`, best helper names `SetOfferItem` and `FindOfferItemRowByKey`, direct class ownership for raw helpers [UID:00014R]/[UID:00014S], vtable-only null/draw slots at `0x00619e40/0x00619e48`, shared compiler destructor caveat, no direct branch/VA/RVA/file-offset route to raw constructor/upsert/find starts, inline dispatcher case-2 relationship, and blank formal C++ pending declaration/emitter-order and ListPane virtual signature cleanup.
```

### `by-memory/-coverage-report.md` replacement row for [UID:00014Q]

```md
    - [UID:00014Q][0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor](by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md) 0x004ae060-0x004ae0a4 | raw constructor | ExchangeItemListPaneRawConstructor : reconstructable : 86% : strong : Raw non-IDA ExchangeItemListPane constructor; exact `0x44` / 68-byte body calls `ListPane` constructor with row size `0x206`, visible rows `8`, pane width/height argument `0x9c`, row height `0x18`, flags `0,1,1`, installs primary/secondary/tertiary vtable views at offsets `+0/+0xa0/+0xa4`, has no direct branch/VA/RVA/file-offset route to the raw start, direct owner [UID:00004S] with source route [UID:0000J9] `ExchangeDialog.cpp`, and keeps formal C++ blank pending class declaration, emitter ordering, and final `ListPane` constructor spelling.
```

### `by-memory/-coverage-report.md` replacement row for [UID:00014R]

```md
    - [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md) 0x004ae0b0-0x004ae167 | raw helper | ExchangeItemListPaneRawUpsertHelper : reconstructable : 86% : strong : B012/B015 2026-06-19 source-quality reanalysis confirms exact `0xb7` / 183-byte raw non-IDA `ExchangeItemListPane` row-set helper, best source-facing signature `SetOfferItem(unsigned char key, unsigned short itemId, unsigned char color, const wchar_t *name)`, row layout key `+0`, item id `+2`, color/style `+4`, wide name `+6`, total row size `0x206`, duplicate-key remove/reinsert path through tail block `0x004ae156-0x004ae167`, outgoing shared ListPane calls `0x004f3bd0`/`0x004f3dc0`/`0x004f3d60`/`0x004f3c00`, `_wcscpy_s` name copy with capacity `0x100`, direct owner route through [UID:00004S] `ExchangeItemListPane` to [UID:0000J9] `ExchangeDialog.cpp`, no branch/immediate/VA/RVA/file-offset route to `0x004ae0b0`, positive-control vtable refs only for successor null/draw virtuals, and formal C++ intentionally blank because live dispatcher case `2` emits equivalent row-update logic inline while this raw helper remains a no-route retained/private helper candidate.
```

### `by-memory/-coverage-report.md` replacement row for [UID:00014S]

```md
    - [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md) 0x004ae170-0x004ae1ac | raw helper | ExchangeItemListPaneRawFindHelper : reconstructable : 86% : strong : B015 2026-06-19 class source-quality reanalysis confirms exact `0x3c` / 60-byte raw non-IDA `ExchangeItemListPane` key-scan helper, best source-facing signature `int FindOfferItemRowByKey(unsigned char key) const`, shared ListPane count/access calls `0x004f3bd0` and `0x004f3dc0`, row key comparison at `+0`, found return index path and not-found `-1` path, `ret 4`, direct owner route through [UID:00004S] to [UID:0000J9] `ExchangeDialog.cpp`, no branch/immediate/VA/RVA/file-offset route to `0x004ae170`, successor positive-control vtable refs at `0x00619e40 -> 0x004ae1b0` and `0x00619e48 -> 0x004ae1c0`, and formal C++ intentionally blank because no caller/source route proves the retained helper should be emitted.
```

### `by-memory/-coverage-report.md` replacement row for [UID:0000ZR]

```md
    - [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md) 0x0047ea50-0x0047ea8b | shared scalar deleting destructor | SharedListPaneScalarDeletingDestructor : ignored : 85% : strong : IDA-verified compiler-generated shared list-pane scalar deleting destructor target used by BoardListPane, ClanStringListPane, ClanJoinListPane, ClanEnlistListPane, ExchangeItemListPane, and MyItemListPane; current evidence records exact `0x3b` function size, `0xcc` padding at `0x0047ea8b`, normal ListPane cleanup call `0x004f3b60`, conditional storage free, vector-delete flag caveat, secondary/tertiary adjustor-thunk fan-in at `0x0047e8ad/0x0047e8b8`, six shared primary-vtable users including `0x00619dc8`, and non-source compiler-glue handling with blank emitter.
```

### `by-memory/-coverage-report.md` add/sync row for [UID:0003NF]

```md
        - [UID:0003NF][0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData](by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md) 0x00619dc4-0x00619e88 | vtable-data | ExchangeItemListPaneVtableData : reconstructable : 85% : very-strong : Exact ExchangeItemListPane RTTI/COL pointer and primary/secondary/tertiary vtable data owned by [UID:00004S]; `0x00619dc4 -> 0x0064728c`, primary table `0x00619dc8`, secondary `0x00619e50`, tertiary `0x00619e80`, primary null/draw slots `0x00619e40 -> 0x004ae1b0` and `0x00619e48 -> 0x004ae1c0`, constructor/raw-constructor store refs from `0x004acbef/0x004acd9c/0x004ae083`, `0x004acbf5/0x004acda2/0x004ae08b`, and `0x004acbff/0x004acdac/0x004ae095`, shared destructor caveat for `0x0047ea50`, and successor AddItemDialog COL boundary at `0x00619e88`.
```

### Future child coverage rows

No exact supervisor-owned row can be fully final for the null/draw child splits until UIDs and filenames exist. If the supervisor creates those child docs, use these exact row bodies after replacing `UID:TBD` and path names with allocated values:

```md
    - [UID:TBD][0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual](by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md) 0x004ae1b0-0x004ae1b3 | vtable null virtual | ExchangeItemListPaneNullVirtual : reconstructable : 85% : strong : Exact three-byte primary-vtable null/no-op virtual for [UID:00004S] `ExchangeItemListPane`; bytes `c2 08 00`, routed only through `0x00619e40`, surrounded by `0xcc` padding at `0x004ae1ac-0x004ae1b0` and `0x004ae1b3-0x004ae1c0`, likely an inherited ListPane callback intentionally left empty, with final source-facing name deferred until ListPane slot names are resolved and formal C++ blank.
```

```md
    - [UID:TBD][0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry](by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md) 0x004ae1c0-0x004ae4b6 | vtable draw virtual | ExchangeItemListPaneDrawItemEntry : reconstructable : 86% : strong : Exact `0x2f6` / 758-byte primary-vtable row draw virtual for [UID:00004S] `ExchangeItemListPane`; routed through `0x00619e48`, consumes `ExchangeItemListRow` item id `+2`, color/style `+4`, and wide name `+6`, branches on EPF/high-color mode at `0x0066da97`, uses `EPFTileContext` init `0x00457a60`, item glyph bounds `0x004df460`, item image draw helpers `0x004df2c0`/`0x004dee50`, rectangle helper `0x004b7cc0`, and `GrafPort` move/color/text helpers `0x004b9600`/`0x004b9680`/`0x004b9690`/`0x004bab70`, with formal C++ deferred pending final inherited virtual signature and helper-name synchronization.
```

## Validator Baseline

Scoped read-only validator baseline was run before creating this report.

Working directory:

```text
E:\NTK\GhidraBridge\source-3\project-documentation
```

Exact command:

> Executable block R001 was removed from this report and preserved verbatim in [00004S-ExchangeItemListPane-class-source-quality-removed.md](00004S-ExchangeItemListPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
Exit code: 0
root: C:\FastStorage\NTK_Sources\source-3\project-documentation
mode: file
scope: direct by-* folders under root
apply: False
scanned markdown files: 1
ok: 1
stats_incremental_skip: 1
ok           00004S by-class/ExchangeItemListPane.md UID header exists
stats_incremental_skip 00004S project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows
dry run only; pass --apply to write changes
```

The output also included unrelated repository-wide auto-generation fanout/no-op lines because the validator rebuilds registry and checks emitters even in file mode. No `--apply` was used.

## Open Questions Closed Or Bounded

- Raw constructor liveness: closed for this pass. It is class-local and constructor-shaped, but no direct route to raw start was found. Constructor behavior should be documented; emission waits for declaration/order and ListPane constructor spelling.
- Raw upsert liveness: closed for this pass. No direct route found; live dispatcher emits equivalent inline logic. Treat as named no-route private helper candidate, not emitted code.
- Raw find liveness: closed for this pass. No direct route found; document as named no-route private helper candidate.
- Row type: closed enough for implementation. Use `ExchangeItemListRow`; fields listed above.
- `key` versus `slot`: bounded. Use `key` or `offerKey` in source docs because binary proves row-key behavior, not inventory-slot identity.
- `color` versus `style`: bounded. Use `color` now because packet/generated code use color; note item-render style/category possibility if broader item docs standardize it.
- Source placement: closed. Target belongs in `ExchangeDialog.cpp` via [UID:0000J9].
- `MyItemListPane` relationship: closed. It is analogue/support evidence only, not owner.
- Shared destructor ownership: closed. Keep shared/compiler-generated, no [UID:00004S] direct ownership.
- Null virtual name: not safely resolvable from current evidence. Record no-op ListPane callback role and defer exact name until ListPane slot map is known.
- Draw virtual name: high-probability `DrawItemEntry` / acceptable `DrawListEntry`; exact source spelling depends on ListPane virtual naming. Behavior and owner are strong enough to split.
- First-draft C++ eligibility: closed for this pass. Do not emit class C++; future work should add declaration/order support and split draw/null children.

## Report-Only File Status

This report intentionally does not edit:

- `by-class/ExchangeItemListPane.md`
- any other `by-*` documentation
- `by-memory/-coverage-report.md`
- generated C++ files

Only this report and `tools/leaser/Agents/Agent-B015/notes.md` are intended to be changed for the assignment.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00004S-ExchangeItemListPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00004S"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00004S-ExchangeItemListPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00004S-ExchangeItemListPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00004S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
