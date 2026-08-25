** TARGET-REPORT-UID:0002DF **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Source-Quality Report: FittingRoomListPane Paint/Input/Scroll Cluster

Assignment: `B003-goal2-fittingroom-listpane-paint-input-scroll-source-quality-0002DF-0002DL-0002DN-0002DQ-20260618`

Targets:

- [UID:0002DF] `by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md`
- [UID:0002DL] `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md`
- [UID:0002DN] `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md`
- [UID:0002DQ] `by-memory/0x00420d00-0x00420d50.ValidateFittingSelectionIndex.md`

Report-only result: no by-* docs, generated reports, generated source, IDA DB, or coverage reports were edited.

## Evidence Checked

Workflow and policy documents checked:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B003/goal.md`
- `tools/leaser/Agents/Agent-B003/notes.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`

Target and direct support docs checked:

- `0002DF`, `0002DL`, `0002DN`, `0002DQ`
- [UID:000053] `by-class/FittingRoomListPane.md`
- [UID:0000JE] `by-file/FittingRoom.md`
- [UID:0002DO] `FittingRoomListPaneOnInputEventJumpTables`
- [UID:0002DH] `FittingRoomListPaneOnScrollPositionChanged`
- [UID:0002DM] `FittingRoomListPaneOnKeyScroll`
- [UID:0002DS] `FittingRoomListPaneOnScrollStep`
- [UID:0002DT]/[UID:0002DP]/[UID:0002DU] slot-geometry pages
- [UID:0002DR] selection/vector aggregate and exact children [UID:00030Q]/[UID:00030R]/[UID:00030T]/[UID:00030V]/[UID:00030X]/[UID:00030Z]
- [UID:00006T] `ItemCatalog`
- [UID:00028I] `g_pFittingRoomDialog`
- [UID:000051] `FittingRoomDialogItemState`
- [UID:0001UH] `FittingEquipmentStateLayout`
- [UID:00004Z] `FittingEquipmentState`
- [UID:0000WS] `FittingEquipmentStateResetEntries`
- [UID:0002E4] `FittingRoomCatalogEntryFromJson`
- [UID:0000WU] `FittingRoomItemShopCatalogState`
- Render/text support [UID:000162], [UID:00016A], [UID:00016C], [UID:00016D], [UID:00016I], [UID:000167], [UID:0001PI]
- [UID:00004O] `EventMan`

Generated and coverage state checked:

- `by-memory/-coverage-report.md` rows for `0002DF`, `0002DL`, `0002DN`, `0002DQ`
- `by-class/-coverage-report.md` row for `000053`
- `project-documentation/auto-generated/NexusTK/cashshop/FittingRoom.cpp`
- `source-3/simroot_v2/class_FittingRoomListPane.cpp`

Executable evidence checked from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` using a minimal PE reader and Capstone disassembly:

- Image base `0x00400000`; `.text` covers `0x00401000-0x0060c600`, `.rdata` covers `0x0060d000-0x0066c200`, `.data` covers `0x0066d000-0x0069ce24`.
- `0002DF` exact body `0x0041ee10-0x0041f0b0`, length `0x2a0`, previous eight bytes all `cc`, start bytes `55 8b ec 83 ec 20 ...`.
- `0002DL` exact body `0x0041f2b0-0x0041fb9b`, length `0x8eb`, previous bytes all `cc`, following bytes begin `cc cc cc cc cc 55...`; only non-text absolute VA pointer is vtable cell `0x0060dd54`.
- `0002DN` exact body `0x0041fcd0-0x004207ce`, length `0xafe`, previous bytes all `cc`, following bytes are jump-table data; only non-text absolute VA pointer is vtable cell `0x0060dd7c`.
- `0002DQ` exact body `0x00420d00-0x00420d50`, length `0x50`, previous padding before start, following bytes start raw helper `0x00420d50`.
- Direct relative calls to `0x0041ee10`: `0x0041eb01`, `0x0041ed71`, `0x0041f0e8`, `0x0041f1ed`, `0x0041f26f`, `0x0041f4cd`, `0x0041fc02`, `0x004208b5`, `0x00420921`.
- Direct relative call to `0x00420d00`: `0x0041fded`.
- Direct relative call to `HitTestSlot 0x00420b60`: `0x0041fdaf`.
- Direct relative calls to `OnScrollPositionChanged 0x0041f0b0`: `0x0041fd74`, `0x0041fd8f`.
- No direct call/jump hits to `OnPaint` or `OnInputEvent`; vtable-only reachability remains correct.
- `OnPaint` has an indirect `call dword ptr [0x0069b3fc]` at `0x0041f6bd`, used after setting draw color `0x8a` and building the highlight rectangle.
- `OnInputEvent` item-part switch table dwords start at `0x004207d0`; byte selector table starts at `0x00420810`.
- No MCP resources were exposed in this session; this pass is a docs plus PE-byte reanalysis rather than a live IDA pass.

Validation/tooling state:

- `python tools/validator.py --help` was run only to confirm supported validation modes. No validator apply command was run.
- `capstone` was installed in the user Python environment to disassemble the executable for this report. No project file was modified by that install.

## Heuristic / Inference Reanalysis And Validation

### Source Placement And Owner Route

Keep all four target pages under [UID:000053] `FittingRoomListPane`, emitted through [UID:0000JE] `FittingRoom`. The class/file route remains the narrowest defensible source route because:

- `UpdateScrollBar` is called by the list-pane constructor/resize/move/insert/key/input/scroll-step/scroll-pane callback cluster and reads list-pane fields at `+0x108`, `+0x10a`, `+0x10c`, and `+0x11c`.
- `OnPaint` and `OnInputEvent` are vtable entries at `0x0060dd54` and `0x0060dd7c` in the FittingRoomListPane vtable neighborhood.
- `ValidateFittingSelectionIndex` has exactly one direct caller, `OnInputEvent` at `0x0041fded`, and exists only to validate this list-pane slot-to-catalog selection path.
- The broader source file remains `cashshop/FittingRoom.cpp`; generic GrafPort/Surface/Event/Vector/String helpers are dependencies, not fitting-room-owned source.

Rejected owner alternatives:

- `ItemCatalog`: it provides `GetItemCount` and `GetItemByIndex`, but the scroll, paint, and input decisions live in list-pane UI code.
- `FittingRoomDialogItemState`: it owns catalog storage and the `+0x240` item-entry vector tail, but this cluster is the consumer UI.
- `FittingRoomScrollPane`: it owns the scrollbar child and local drag/timer drawing methods. `UpdateScrollBar` manipulates that child from the parent list pane, so it should not move to the child class.
- `GrafPort`/`Surface`: render callbacks, text helpers, and color/move helpers are dependencies.

### Scroll Fields And Page/Range Math

Recommended field roles for the list pane:

- `this+0x108`: `m_scrollPosition` / first visible catalog row. It is mirrored into child scroll pane `+0xfe`.
- `this+0x10a`: `m_enabledItemCount` / active visible-entry count. It is written by `UpdateScrollBar` after scanning catalog entries whose entry byte `+4` is nonzero. It is read by `OnPaint` to decide whether to start grid painting at `m_scrollPosition * 6` or zero.
- `this+0x10c`: `m_displayMode`; `0` is row/list mode, nonzero is grid mode. Slot-geometry pages support names `FittingRoomListDisplayMode_Rows` and `FittingRoomListDisplayMode_Grid`.
- `this+0x11c`: `m_scrollPane`, the owned `FittingRoomScrollPane*`.

Important correction: `UpdateScrollBar` stores the enabled-entry count into `+0x10a`, but the scrollbar range math uses the `ItemCatalog::GetItemCount` return value, not the enabled-entry count. In row mode it uses page size `26` and range `max(totalCount - 26, 0)`. In grid mode it uses page size `3` rows and range `max(ceil(totalCount / 6) - 3, 0)`. Both paths clamp to `0..30000` before writing child `+0x100` and child `+0xfe`.

`OnPaint` does not read `this+0x10c`; it paints the six-column grid using `m_scrollPosition * 6` and a visible cap of 18 cells. The row/list display-mode behavior is present in `UpdateScrollBar`, `OnKeyScroll`, `HitTestSlot`, `GetItemSlotRect`, and `GetItemSlotOrigin`, but this paint body itself does not prove a separate row renderer.

### Event Record Fields And Event Types

EventMan support resolves the event type values:

- `event+4 == 3`: left-button release family. `OnInputEvent` uses this for slot hit-test and cart/selection update.
- `event+4 == 7`: mouse wheel. `OnInputEvent` tests the point against the list-pane rect, reads wheel delta at `event+0x14`, and calls `OnScrollPositionChanged`.
- `event+4 == 8`: key down / translated key event. This is handled by sibling `OnKeyScroll`, not directly by `OnInputEvent`.

Recommended event field names:

- `event+4`: `type`
- `event+8`: `x` / mouse X / key byte in key events depending on event type
- `event+0x0c`: `y`
- `event+0x14`: `wheelDelta`
- `event+0x10a`: key modifier/fallback byte used by `OnKeyScroll`

Rejected alternatives:

- Treating type `3` as generic mouse press is weaker than EventMan evidence. It is the left-button release member of the left-button family `1/2/3`.
- Treating type `7` as a scrollbar child command is wrong; EventMan documents it as mouse wheel, and the body reads `event+0x14` as a delta.

### Active Category And Catalog Lookup

`g_pFittingRoomDialog+0x504` is the embedded fitting-room item-state/catalog object. `g_pFittingRoomDialog+0x784` is the active category/filter dword; the low byte is passed to `ItemCatalog::GetItemCount` and `GetItemByIndex`.

`ValidateFittingSelectionIndex` uses the same category route. Its binary comparison is `candidate > count` invalid, then `GetItemByIndex(category, candidate)`, then accepts only non-null entries whose byte `+4` is nonzero.

`OnInputEvent` translates slot to catalog candidate as:

- row/list mode: `candidate = m_scrollPosition + slotIndex`
- grid mode: `candidate = m_scrollPosition * 6 + slotIndex`

`OnPaint` scans catalog entries, skips null entries, and draws active entries (`entry+4 != 0`) using grid coordinates. It also scans the selected/cart vector before the active-byte draw branch, so highlight checks are tied to selected entries by category/index rather than only to drawn active content.

### Selection Vector And 0xb4 Entry Layout

The active selection/cart vector is the `FittingRoomDialogItemState` vector at item-state `+0x240/+0x244/+0x248`, which is dialog-relative `g_pFittingRoomDialog+0x744/+0x748/+0x74c`. Because the item-state object begins at `g_pFittingRoomDialog+0x504`, reads such as `[itemState+0x240]` are the same storage as dialog `+0x744`. This resolves the apparent catalog-versus-dialog-base contradiction.

Recommended role name: `m_selectedFittingItems` or `m_cartEntries`; "selection vector" is safer than "cart" if no final UI label is required.

`0xb4` entry layout:

- `+0x00`: active category/filter id copied from `g_pFittingRoomDialog+0x784`.
- `+0x04..+0xa3`: item name buffer, `wchar_t[0x50]`, copied from catalog entry `+0x0a` via `_wcscpy_s(..., 0x50, ...)`.
- `+0xa4`: signed 16-bit selected catalog index.
- `+0xa6`: padding/unproven word.
- `+0xa8/+0xac/+0xb0`: vector of 4-byte item part type codes built from the catalog entry part records.

When adding a new item, the input handler builds a temporary entry, collects non-`0xff` part codes from the item part records, removes existing entries whose part-code vector overlaps with the new entry, then inserts the new `0xb4` entry through [UID:00030R] `FittingRoomItemEntryVectorInsert`. When clicking an already selected category/index pair, it removes that exact entry and sets the local `removing` flag.

### Catalog Entry And Part Record Fields

Catalog entry fields used here:

- `entry+4`: enabled/active byte.
- `entry+6`: top-level icon/tile id for paint.
- `entry+8`: icon color/variant byte.
- `entry+0x0a`: UTF-16 item name buffer.
- `entry+0xb4/+0xb8/+0xbc`: nested 6-byte part-record vector.

Part-record fields used by input:

- `partRecord+0`: item/equipment part type code.
- `partRecord+2`: 16-bit tile/appearance value.
- `partRecord+4`: color/variant byte.
- `partRecord+5`: documented by parser as gender byte, not directly used in this input switch.

The `part` byte is not a category id, slot id, animation id, or direction. It is the fitting-equipment/avatar part code from the JSON `items[].part` field.

### Item Part Type Switch And Preview Side Effects

The switch table at `0x00420810` maps `part - 1` to 16 local targets. Decoded type-to-target mapping:

| Part code | Side effect summary |
| --- | --- |
| `0x01` | Writes tile word `dialog+0x486` and color byte `+0x4b2`; removal restores from `+0x4ca/+0x4f6`. |
| `0x02` | Writes tile word `+0x484` and color byte `+0x4b1`; removal restores from `+0x4c8/+0x4f5`. |
| `0x03` | Writes tile word `+0x488` and color byte `+0x4b3`; removal restores from `+0x4cc/+0x4f7`. |
| `0x04` | Writes byte `+0x48a`, color byte `+0x4b4`, and sets byte `+0x49c=1`; removal restores `+0x4ce/+0x4f8`. |
| `0x06` | Writes tile word `+0x494` and color byte `+0x4b9`; removal restores `+0x4d8/+0x4fd`. |
| `0x0d` | Writes tile word `+0x496` and color byte `+0x4ba`; removal restores `+0x4da/+0x4fe`. |
| `0x0e` | Writes tile word `+0x492` and color byte `+0x4b8`; removal restores `+0x4d6/+0x4fc`. |
| `0x10` | Composite/paired part. Removal restores `+0x498`, `+0x484/+0x4b1`, and `+0x496`. Add path splits tile values by `10000`, writes `+0x498`, clamps `+0x484`, writes `+0x4b1`, and conditionally clears `+0x496`. |
| `0x16` | Writes tile word `+0x48c` and color byte `+0x4b5`; removal restores `+0x4d0/+0x4f9`. |
| `0x17` | Writes tile word `+0x48e`, color byte `+0x4b6`, and may derive bytes `+0x48a`, `+0x482`, and `+0x4af` from tile ranges `10000` and `20000`; removal restores `+0x4d2/+0x4fa`. |
| `0x18` | Writes tile word `+0x490` and color byte `+0x4b7`; removal restores `+0x4d4/+0x4fb`. |
| `0x1e` | Writes tile word `+0x480` and color byte `+0x4ae`; removal restores `+0x4c4/+0x4f2`. |
| `0x1f` | Writes byte `+0x482`; removal restores `+0x4c6`. |
| `0x20` | Writes color/variant byte `+0x4af`; removal restores `+0x4f3`. |
| `0x21` | Special/set preview path. Add path sets `+0x49e=3`, writes `+0x4a8=partRecord.tile`, `+0x4aa=partRecord.color`, and clears `+0x4ac`. Removal path sets `+0x49e=0` and restores `+0x4a8/+0x4aa/+0x4ac` from `+0x4ec/+0x4ee/+0x4f0`. |

Recommended field directions:

- `dialog+0x49e`: special/set preview mode byte. It is cleared before normal part application and set to `3` by part code `0x21`. This aligns with `ResetScrollPosition`, which sets `+0x49e=3` when category `3` is present in the selected-entry vector.
- `dialog+0x4a8/+0x4aa/+0x4ac`: special/set preview triple. The first is a 16-bit tile/value, the second stores a color/variant as a word, and the third is a 16-bit extra value currently cleared on add and restored on removal.

Remaining item-type blocker: exact original enum names for part codes are not recoverable from the checked docs, generated source, JSON parser field names, or PE switch side effects alone. The defensible output is an inferred/descriptive enum such as `FittingRoomItemPartType` with numeric constants and side-effect comments, not names like weapon/head/coat unless a later item schema/source dump proves them.

### Paint Resource, Text, Icon, And Highlight Helpers

`OnPaint` resources and helpers:

- `WBOARDBK.EPF` at `0x0060db5c` and `WBOARDBK.PAL` at `0x0060db78` are direct resource string refs.
- `0x00457a60` initializes EPF tile contexts.
- `0x004d02f0` loads the background frame through the resource manager at `0x0067a744`.
- `0x004b9980` is the tile/frame blit forwarder used by the manual background tiling loop.
- `0x004b7e10` offsets rectangles during background tiling.
- `0x004df460` queries item glyph bounds through the item object image library at `0x0067a758`.
- `0x004defc0` and `0x004df1e0` are item icon draw/render helpers; the large-icon path centers using glyph bounds before drawing.
- `0x004b9660`, `0x004b9680`, `0x004b9600`, `0x004ba9a0`, and `0x004bab70` are shared GrafPort draw-state/text helpers, not FittingRoomListPane methods.
- `0x00421260` and `0x00421230` are fixed wide-format wrappers owned by StringUtil, used for `%s` and `%s %s` formatting in item-name wrapping.
- The indirect highlight call at `0x0041f6bd` is `dword_69B3FC`, SurfaceRenderCallbackTable slot 7. In this paint method it is best named an invalidation/fill/highlight callback. Reject generated `g_pfnLockSurface` for this callsite.

### ValidateFittingSelectionIndex Signature

The function body is tiny and source-quality. It has one direct caller and no independent source purpose outside list-pane input.

ABI evidence has a nuance: the caller sets `ecx` to the list-pane pointer before `call 0x00420d00`, and the callee returns with `ret 4` but never reads `ecx`. This supports either a private `FittingRoomListPane` `__thiscall` helper with unused `this`, or a file-local/static `__stdcall`-shaped helper. Because the class is the direct owner and the callsite passes `this`, the recommended formal C++ is:

```cpp
FittingRoomSlotIndex FittingRoomListPane::ValidateFittingSelectionIndex(FittingRoomSlotIndex candidate) const;
```

If the supervisor prefers not to introduce an unused `this` member, this source-equivalent file-local alternative is acceptable and should keep owner/emitter `000053`:

```cpp
static FittingRoomSlotIndex ValidateFittingSelectionIndex(FittingRoomSlotIndex candidate);
```

The old Wave2/global spelling `ValidateFittingSelectionIndex_420D00` should remain historical evidence only; the source-facing name should drop the address suffix.

### Generated Output And Stale Blank-C++ Wording

The active generated file `project-documentation/auto-generated/NexusTK/cashshop/FittingRoom.cpp` is non-empty and currently contains the just-applied slot-geometry C++ from `0002DT/0002DP/0002DU`, but it does not contain first-draft code for `0002DF`, `0002DL`, `0002DN`, or `0002DQ`. The stale blockers are therefore target-page C++ omissions, not a missing file route.

`simroot_v2/class_FittingRoomListPane.cpp` remains useful as a decompilation lead but should not be treated as source-quality:

- It names `OnInputEvent` as `virt_deldtor_0x41fcd0`, which is wrong for the vtable slot.
- It carries 95/95-era comments and autograder penalties that contradict the active 85/85 code-entry gate.
- It uses generated classes like `cls_0x422690` and address-suffixed helper names.
- Its paint commentary can blur item-state vector base (`dialog+0x744` / item-state `+0x240`) with catalog API ownership.

## Recommended Metadata And Score Changes

Recommended target metadata:

| UID | Current | Recommended | Owner/emitter | C++ |
| --- | --- | --- | --- | --- |
| `0002DF` | `84/88` | `87/90` | keep `000053` / `000053` | populate first-draft C++ |
| `0002DL` | `84/90` | `86/90` | keep `000053` / `000053` | populate first-draft C++ |
| `0002DN` | `84/88` | `86/89` | keep `000053` / `000053` | populate first-draft C++ |
| `0002DQ` | `84/88` | `87/90` | keep `000053` / `000053` | populate first-draft C++ |

Rationale:

- `0002DF` can rise because the PE pass confirms nine direct callers, exact field roles, exact row/grid page math, range/current clamping, child visibility toggling, and the correction that range uses total catalog count while `+0x10a` stores enabled count.
- `0002DL` can rise modestly because render/helper ownership and the `0x0069b3fc` callback are resolved, but exact item-part enum names and some GrafPort/Surface callback names remain provisional.
- `0002DN` can rise because event types, event fields, selection-vector layout, item-part switch side effects, and preview fields are now decoded. It should not go above `86/89` until original item-part enum names and final preview-field names are proven.
- `0002DQ` can rise because the helper has exact range, sole caller, exact catalog validation behavior, and a defensible source name/signature. The member-vs-static nuance caps confidence below final.

Recommended support-doc score handling:

- Keep [UID:000053] `FittingRoomListPane` at `85/87` unless the supervisor wants to raise it to `86/88` after applying all four child C++ blocks. The class still has unresolved final list-entry/item-part field names and should not receive full formal class C++ yet.
- Keep [UID:0000JE] `FittingRoom` at `85/87`. The file route is strengthened but still broad, and no new file split is recommended.

## First-Draft C++ Recommendation

These snippets are intended as first-draft reconstruction content for the target pages. Supporting type names are descriptive and should be placed in class/support docs rather than repeated in every by-memory page.

Recommended shared support names:

```cpp
typedef short FittingRoomSlotIndex;

static const FittingRoomSlotIndex kInvalidFittingRoomSlot = -1;
static const int kFittingRoomRowPageSize = 26;
static const int kFittingRoomGridPageRows = 3;
static const int kFittingRoomGridColumns = 6;
static const int kFittingRoomGridVisibleCells = 18;
static const short kFittingRoomMaxScroll = 30000;

enum FittingRoomListDisplayMode {
    FittingRoomListDisplayMode_Rows = 0,
    FittingRoomListDisplayMode_Grid = 1
};

struct FittingRoomCatalogPartRecord {
    signed char partType;
    unsigned char reserved;
    unsigned short tile;
    unsigned char color;
    unsigned char gender;
};

struct FittingRoomSelectionEntry {
    int category;
    wchar_t name[0x50];
    FittingRoomSlotIndex catalogIndex;
    unsigned short reserved;
    IntVector partTypes;
};
```

### [UID:0002DF] `FittingRoomListPane::UpdateScrollBar`

```cpp
void FittingRoomListPane::UpdateScrollBar()
{
    FittingRoomDialog* dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState* itemState = &dialog->m_itemState;
    const unsigned char category = static_cast<unsigned char>(dialog->m_activeCategory);

    const short totalItems = itemState->GetItemCount(category);
    short enabledItems = 0;

    for (short index = 0; index < totalItems; ++index) {
        FittingRoomCatalogEntry* entry = itemState->GetItemByIndex(category, index);
        if (entry != 0 && entry->enabled != 0) {
            ++enabledItems;
        }
    }

    m_enabledItemCount = enabledItems;

    const bool rowMode = (m_displayMode == FittingRoomListDisplayMode_Rows);
    const int pageSize = rowMode ? kFittingRoomRowPageSize : kFittingRoomGridPageRows;
    const int contentRows = rowMode ? totalItems : ((totalItems + 5) / kFittingRoomGridColumns);

    short maxScroll = 0;
    if (contentRows > pageSize) {
        maxScroll = static_cast<short>(contentRows - pageSize);
        if (maxScroll > kFittingRoomMaxScroll) {
            maxScroll = kFittingRoomMaxScroll;
        }
    }

    FittingRoomScrollPane* scrollPane = m_scrollPane;
    if (scrollPane->m_maxPosition != maxScroll) {
        if (maxScroll < scrollPane->m_currentPosition) {
            scrollPane->m_currentPosition = maxScroll;
            scrollPane->Invalidate();
        }

        scrollPane->m_maxPosition = maxScroll;
        scrollPane->Invalidate();

        const bool shouldShowScroll = (maxScroll > 0);
        if (scrollPane->m_visible != shouldShowScroll) {
            scrollPane->m_visible = shouldShowScroll;
            scrollPane->Invalidate();
        }
    }

    short clampedScroll = m_scrollPosition;
    if (clampedScroll < 0) {
        clampedScroll = 0;
    }

    const int maxCurrent = rowMode
        ? (totalItems - pageSize)
        : (((totalItems + 5) / kFittingRoomGridColumns) - pageSize);

    if (clampedScroll > maxCurrent) {
        clampedScroll = static_cast<short>(maxCurrent);
    }
    if (clampedScroll < 0) {
        clampedScroll = 0;
    }
    if (clampedScroll > kFittingRoomMaxScroll) {
        clampedScroll = kFittingRoomMaxScroll;
    }

    if (scrollPane->m_currentPosition != clampedScroll) {
        scrollPane->m_currentPosition = clampedScroll;
        scrollPane->Invalidate();
    }

    m_scrollPosition = clampedScroll;
}
```

### [UID:0002DL] `FittingRoomListPane::OnPaint`

```cpp
void FittingRoomListPane::OnPaint()
{
    EPFTileContext boardFrame;
    Region savedClip;

    EPFTileContext::Construct(&boardFrame);
    Region::Construct(&savedClip);

    if (g_pResourceMan->LoadFrame(L"WBOARDBK.EPF", 0, &boardFrame)) {
        RectBounds visible = m_bounds;
        m_drawMode = 1;
        SaveClipRegion(&savedClip);
        IntersectClipRect(visible);

        const int tileWidth = boardFrame.source.right - boardFrame.source.left;
        const int tileHeight = boardFrame.source.bottom - boardFrame.source.top;
        if (tileWidth > 0 && tileHeight > 0) {
            for (int y = visible.top; y < visible.bottom; y += tileHeight) {
                for (int x = visible.left; x < visible.right; x += tileWidth) {
                    RectBounds dst;
                    SetRectLTRB(&dst, x, y, x + tileWidth, y + tileHeight);
                    ForwardToTileFrameBlitHelper(this, &boardFrame, &boardFrame.source, &dst, m_drawMode, L"WBOARDBK.PAL");
                }
            }
        }

        RestoreClipRegion(&savedClip);
    }

    Region::Destroy(&savedClip);

    FittingRoomDialog* dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState* itemState = &dialog->m_itemState;
    const unsigned char category = static_cast<unsigned char>(dialog->m_activeCategory);

    EPFTileContext itemFrameA;
    EPFTileContext itemFrameB;
    EPFTileContext::Construct(&itemFrameA);
    EPFTileContext::Construct(&itemFrameB);

    UpdateScrollBar();

    const short totalItems = itemState->GetItemCount(category);
    short firstIndex = static_cast<short>(m_scrollPosition * kFittingRoomGridColumns);
    if (m_enabledItemCount == 0 || totalItems < m_scrollPosition + kFittingRoomGridVisibleCells) {
        firstIndex = 0;
    }

    Point cell;
    SetPoint(&cell, 31, 17);
    m_drawMode = 1;

    unsigned char cellIndex = 0;
    short drawnCells = 0;

    for (short catalogIndex = firstIndex;
         catalogIndex < totalItems && drawnCells < kFittingRoomGridVisibleCells;
         ++catalogIndex) {
        FittingRoomCatalogEntry* entry = itemState->GetItemByIndex(category, catalogIndex);
        if (entry == 0) {
            continue;
        }

        if (SelectionVectorContains(dialog->m_selectedFittingItems, category, catalogIndex)) {
            RectBounds highlight;
            SetRectLTRB(&highlight, cell.x, cell.y, cell.x + 50, cell.y + 50);
            SetDrawColor(0x8a);
            SurfaceFillOrInvalidate(this, &highlight);
        }

        if (entry->enabled != 0) {
            RectBounds glyphBounds;
            g_pItemObjImageLib->GetItemGlyphBounds(entry->tile, &glyphBounds);

            RectBounds iconRect;
            const int glyphWidth = glyphBounds.right - glyphBounds.left;
            const int glyphHeight = glyphBounds.bottom - glyphBounds.top;
            if (glyphWidth < 0x33 && glyphHeight < 0x33) {
                SetRectLTRB(&iconRect, cell.x, cell.y, cell.x + 50, cell.y + 50);
                g_pItemObjImageLib->DrawItem(this, &iconRect, entry->tile, entry->color);
            } else {
                CenterItemGlyphInCell(&iconRect, cell, glyphBounds, 50, 50);
                g_pItemObjImageLib->DrawLargeItem(this, &iconRect, entry->tile, entry->color);
            }

            SetBkColor(0x8f);
            DrawWrappedFittingRoomItemName(entry->name, cell.x - 6, cell.y + 0x42);
        }

        ++drawnCells;
        cellIndex = static_cast<unsigned char>((cellIndex + 1) % kFittingRoomGridColumns);
        cell.x = cellIndex * 0x60 + 0x11;
        if (cellIndex == 0) {
            cell.y += 0x70;
        }
    }

    SetDrawColor(0x8f);
    m_drawMode = 2;
}
```

Notes for this draft:

- `SurfaceFillOrInvalidate` is the callsite role of `dword_69B3FC`, not a proven original name.
- `DrawWrappedFittingRoomItemName` should lower to the current `0x00421230/0x00421260`, tokenization, `MeasureTextWidth`, `MoveTo`, and `DrawWideText` sequence if supervisor wants the formal C++ to be more literal.
- The paint body does not read `m_displayMode`; do not add row-mode paint branches to this exact by-memory page unless new evidence proves them.

### [UID:0002DN] `FittingRoomListPane::OnInputEvent`

```cpp
bool FittingRoomListPane::OnInputEvent(Event* event)
{
    FittingRoomDialog* dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState* itemState = &dialog->m_itemState;
    const unsigned char category = static_cast<unsigned char>(dialog->m_activeCategory);

    if (event->type == EventType_LeftButtonRelease) {
        FittingRoomSlotIndex slot = HitTestSlot(event->x, event->y);
        if (static_cast<unsigned short>(slot) <= 0x1a) {
            FittingRoomSlotIndex candidate;
            if (m_displayMode == FittingRoomListDisplayMode_Rows) {
                candidate = static_cast<FittingRoomSlotIndex>(m_scrollPosition + slot);
            } else {
                candidate = static_cast<FittingRoomSlotIndex>(m_scrollPosition * kFittingRoomGridColumns + slot);
            }

            candidate = ValidateFittingSelectionIndex(candidate);
            if (candidate != kInvalidFittingRoomSlot && g_pGlobalState->fittingRoomInputLocked == 0) {
                FittingRoomCatalogEntry* catalogEntry = itemState->GetItemByIndex(category, candidate);
                bool removing = false;

                FittingRoomSelectionEntry newEntry;
                ConstructSelectionEntry(&newEntry, category, candidate, catalogEntry);

                for (FittingRoomSelectionEntry* it = dialog->m_selectedFittingItems.begin;
                     it != dialog->m_selectedFittingItems.end;
                     ++it) {
                    if (it->category == category && it->catalogIndex == candidate) {
                        RemoveSelectionEntry(dialog->m_selectedFittingItems, it);
                        removing = true;
                        break;
                    }
                }

                if (!removing && !newEntry.partTypes.empty()) {
                    wcscpy_s(newEntry.name, 0x50, catalogEntry->name);
                    RemoveEntriesWithOverlappingParts(dialog->m_selectedFittingItems, newEntry.partTypes);
                    dialog->m_selectedFittingItems.push_back(newEntry);
                }

                DestroyTemporarySelectionEntry(&newEntry);

                dialog->m_specialSetPreviewMode = 0;

                for (int partIndex = 0; partIndex < catalogEntry->GetPartCount(); ++partIndex) {
                    const FittingRoomCatalogPartRecord* part = catalogEntry->GetPart(partIndex);
                    if (part == 0 || part->tile == 0xffff) {
                        continue;
                    }

                    ApplyFittingRoomPartRecord(dialog, *part, removing);
                }
            }
        }
    } else if (event->type == EventType_MouseWheel) {
        if (PointInRect(&m_bounds, event->x, event->y)) {
            const short oldPosition = m_scrollPane->m_currentPosition;
            short newPosition = static_cast<short>(oldPosition - event->wheelDelta);
            if (newPosition < 0) {
                newPosition = 0;
            }
            if (newPosition > m_scrollPane->m_maxPosition) {
                newPosition = m_scrollPane->m_maxPosition;
            }
            OnScrollPositionChanged(0, oldPosition, newPosition);
        }
    }

    Point childOrigin;
    m_scrollPane->GetOrigin(&childOrigin);
    event->x -= childOrigin.x;
    event->y -= childOrigin.y;
    const bool handled = m_scrollPane->OnInputEvent(event);
    event->x += childOrigin.x;
    event->y += childOrigin.y;
    return handled;
}
```

The switch body for `ApplyFittingRoomPartRecord` belongs to this exact target if the supervisor wants literal first-draft code instead of a named helper. Use the decoded side-effect table above. For source readability, this helper name is preferable in support docs, but formal by-memory code should either inline it or clearly mark it as a local reconstruction helper for the switch at `0x00420203-0x00420743`.

### [UID:0002DQ] `ValidateFittingSelectionIndex`

Preferred member-shape draft:

```cpp
FittingRoomSlotIndex FittingRoomListPane::ValidateFittingSelectionIndex(FittingRoomSlotIndex candidate) const
{
    FittingRoomDialog* dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState* itemState = &dialog->m_itemState;
    const unsigned char category = static_cast<unsigned char>(dialog->m_activeCategory);

    if (candidate > itemState->GetItemCount(category)) {
        return kInvalidFittingRoomSlot;
    }

    FittingRoomCatalogEntry* entry = itemState->GetItemByIndex(category, candidate);
    if (entry != 0 && entry->enabled != 0) {
        return candidate;
    }

    return kInvalidFittingRoomSlot;
}
```

Acceptable file-local alternative:

```cpp
static FittingRoomSlotIndex ValidateFittingSelectionIndex(FittingRoomSlotIndex candidate)
{
    FittingRoomDialog* dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState* itemState = &dialog->m_itemState;
    const unsigned char category = static_cast<unsigned char>(dialog->m_activeCategory);

    if (candidate > itemState->GetItemCount(category)) {
        return kInvalidFittingRoomSlot;
    }

    FittingRoomCatalogEntry* entry = itemState->GetItemByIndex(category, candidate);
    return (entry != 0 && entry->enabled != 0) ? candidate : kInvalidFittingRoomSlot;
}
```

## Exact Supervisor Changes Required

### Target Metadata/Header Changes

Apply these metadata changes only after adding the supporting evidence and C++ blocks:

- `0002DF`: set `COMPLETION:87`, `CONFIDENCE:90`, keep `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:000053`, `EMITTER_UIDS:000053`.
- `0002DL`: set `COMPLETION:86`, `CONFIDENCE:90`, keep `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:000053`, `EMITTER_UIDS:000053`.
- `0002DN`: set `COMPLETION:86`, `CONFIDENCE:89`, keep `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:000053`, `EMITTER_UIDS:000053`.
- `0002DQ`: set `COMPLETION:87`, `CONFIDENCE:90`, keep `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:000053`, `EMITTER_UIDS:000053`.

### Target Page Text Updates

For `0002DF`, add a source-quality update section near the existing behavior/score rationale:

```markdown
## 2026-06-18 B003 Source-Quality Reanalysis

B003 PE-byte reanalysis against `NexusTK.exe` reconfirmed the exact `0x0041ee10-0x0041f0b0` body, eight bytes of `0xcc` before the function, and nine direct callers at `0x0041eb01`, `0x0041ed71`, `0x0041f0e8`, `0x0041f1ed`, `0x0041f26f`, `0x0041f4cd`, `0x0041fc02`, `0x004208b5`, and `0x00420921`. `this+0x108` is the list scroll position, `this+0x10a` is the enabled-entry count written after scanning catalog entries whose byte `+4` is nonzero, `this+0x10c` is the row/grid display mode, and `this+0x11c` is the owned `FittingRoomScrollPane*`. The scrollbar range math uses `ItemCatalog::GetItemCount`, not `this+0x10a`: row mode uses page size `26`, grid mode uses `ceil(totalCount / 6)` and page size `3`, then clamps to `0..30000`. Child scroll pane `+0xfe/+0x100/+0x102` are current, max/range, and visible/enabled state bytes. Source placement remains `FittingRoomListPane` under `FittingRoom.cpp`; first-draft C++ is now appropriate under the active 85/85 code-entry gate.
```

For `0002DL`, add:

```markdown
## 2026-06-18 B003 Source-Quality Reanalysis

B003 PE-byte and support-doc reanalysis reconfirmed `OnPaint` as vtable-only through `.rdata` cell `0x0060dd54`, with no direct call/jmp hits. The body draws `WBOARDBK.EPF` / `WBOARDBK.PAL` through EPF tile context and shared tile blit helpers, calls `UpdateScrollBar`, scans the active category from `g_pFittingRoomDialog+0x784` through the item-state/catalog object at `+0x504`, and paints the six-column grid starting from `this+0x108 * 6` unless `this+0x10a` / bounds checks force zero. The selected-item vector scanned for highlights is item-state `+0x240/+0x244`, dialog-relative `g_pFittingRoomDialog+0x744/+0x748`, with `0xb4` entries and selected index at entry `+0xa4`. The highlight callback at `0x0041f6bd` is `SurfaceRenderCallbackTable` slot `dword_69B3FC`, used here as a fill/invalidation/highlight callback; reject generated `g_pfnLockSurface` naming for this callsite. `OnPaint` itself does not read display mode `this+0x10c`, so do not claim a proven row-mode paint branch in this exact target. First-draft C++ is now appropriate, with helper names for shared GrafPort/Surface/StringUtil calls kept descriptive.
```

For `0002DN`, add:

```markdown
## 2026-06-18 B003 Source-Quality Reanalysis

B003 PE-byte reanalysis reconfirmed `OnInputEvent` as vtable-only through `.rdata` cell `0x0060dd7c`, exact body `0x0041fcd0-0x004207ce`, and adjacent compiler jump-table data at `0x004207ce-0x00420840`. EventMan resolves event type `3` as left-button release, type `7` as mouse wheel, and type `8` as key down handled by sibling `OnKeyScroll`. The event record fields used here are `+4` type, `+8/+0x0c` mouse coordinates, and `+0x14` wheel delta. Type `3` calls `HitTestSlot`, translates row/grid slot to catalog candidate using `this+0x108` and `this+0x10c`, validates through `ValidateFittingSelectionIndex`, blocks on global state byte `g_pGlobalState+0x1d1`, and updates the dialog/item-state selected-entry vector at dialog `+0x744/+0x748`. The selected-entry stride is `0xb4`: category at `+0`, UTF-16 name buffer at `+4`, selected catalog index at `+0xa4`, and a part-type vector at `+0xa8/+0xac/+0xb0`. The part-record switch reads `partRecord+0` as item part code, `+2` as tile/value, and `+4` as color/variant, then writes dialog preview fields around `+0x480..+0x4fe`. Part code `0x21` owns the special/set preview path: it sets `+0x49e=3` and writes `+0x4a8/+0x4aa/+0x4ac` on add, while removal restores from `+0x4ec/+0x4ee/+0x4f0` and clears `+0x49e`. Original enum names for part codes remain unproven, but numeric side effects are source-quality enough for first-draft C++ under descriptive names.
```

For `0002DQ`, add:

```markdown
## 2026-06-18 B003 Source-Quality Reanalysis

B003 PE-byte reanalysis reconfirmed exact range `0x00420d00-0x00420d50`, one direct caller at `0x0041fded`, no non-text VA/RVA pointer hits, and the following raw helper boundary at `0x00420d50`. The helper reads `g_pFittingRoomDialog`, uses item-state/catalog at dialog `+0x504`, active category low byte from dialog `+0x784`, calls `ItemCatalog::GetItemCount`, rejects only when `candidate > count`, then calls `GetItemByIndex` and accepts the candidate only if the returned entry is non-null and entry byte `+4` is nonzero. Caller ABI sets `ecx` to the list pane before the call and the callee returns with `ret 4` while not reading `this`; formal C++ may be a private `FittingRoomListPane::ValidateFittingSelectionIndex(FittingRoomSlotIndex) const` helper or a file-local static helper. The class-owned private member shape is recommended because the sole caller passes `this` and owner/emitter is already `000053`.
```

### FittingRoomListPane Support Page Updates

In `by-class/FittingRoomListPane.md`, replace these method-table rows:

```markdown
| [UID:0002DF][0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar](by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md) | `UpdateScrollBar` | Counts enabled catalog entries into `this+0x10a`, uses active category/catalog count plus display mode `this+0x10c` to compute row/grid scroll range, clamps child current/range, and toggles scroll child visibility. |
| [UID:0002DL][0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint](by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md) | `OnPaint` | Draws `WBOARDBK` tiled background, grid item cells, selected-entry highlights through `dword_69B3FC`, item icons, and wrapped item text; no direct `this+0x10c` row-mode paint branch is proven in this body. |
| [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md) | `OnInputEvent` | Handles EventMan type `3` left-button release selection/cart updates, EventMan type `7` mouse-wheel scrolling, fitting-equipment preview side effects, selected-entry vector maintenance, and adjusted child/base event delegation. |
| [UID:0002DQ][0x00420d00-0x00420d50.ValidateFittingSelectionIndex](by-memory/0x00420d00-0x00420d50.ValidateFittingSelectionIndex.md) | `ValidateFittingSelectionIndex` | Private/member-or-static list-pane helper that validates a signed 16-bit catalog candidate against active-category count/lookup and entry enabled byte `+4`. |
```

Add this evidence bullet after the existing 2026-06-18 slot-geometry bullet:

```markdown
- 2026-06-18 B003 paint/input/scroll source-quality reanalysis of [UID:0002DF][0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar](by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md), [UID:0002DL][0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint](by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md), [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md), and [UID:0002DQ][0x00420d00-0x00420d50.ValidateFittingSelectionIndex](by-memory/0x00420d00-0x00420d50.ValidateFittingSelectionIndex.md) resolves active-category/catalog lookup, `+0x108/+0x10a/+0x10c/+0x11c` scroll fields, EventMan type `3`/`7` meanings, selection vector layout at dialog `+0x744/+0x748`, `0xb4` selected-entry layout, part-record fields, special/set preview fields `+0x49e/+0x4a8/+0x4aa/+0x4ac`, `dword_69B3FC` as shared Surface highlight/fill callback, and first-draft C++ readiness for all four children. Remaining class-level C++ blockers are exact original item-part enum names and final preview-field names.
```

### FittingRoom File Support Page Update

In `by-file/FittingRoom.md`, insert after the existing 2026-06-18 slot-geometry source-placement note:

```markdown
- 2026-06-18 B003 paint/input/scroll source-quality reanalysis keeps [UID:0002DF][0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar](by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md), [UID:0002DL][0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint](by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md), [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md), and [UID:0002DQ][0x00420d00-0x00420d50.ValidateFittingSelectionIndex](by-memory/0x00420d00-0x00420d50.ValidateFittingSelectionIndex.md) under `FittingRoomListPane` in this file. The update resolves row/grid scroll range math, EventMan event types, item-state selected-entry vector use, `0xb4` selected-entry layout, fitting-equipment preview field side effects, and shared GrafPort/Surface/StringUtil dependency boundaries. Generic draw-state, text, tile, vector, and render callback helpers remain dependencies and should not be migrated into fitting-room ownership.
```

### Validation Commands For Supervisor

After applying doc/C++ changes, run targeted file validation:

> Executable block R001 was removed from this report and preserved verbatim in [0002DF-0002DL-0002DN-0002DQ-FittingRoomListPanePaintInputScroll-source-quality-removed.md](0002DF-0002DL-0002DN-0002DQ-FittingRoomListPanePaintInputScroll-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Then refresh generated output if supervisor workflow permits:

> Executable block R002 was removed from this report and preserved verbatim in [0002DF-0002DL-0002DN-0002DQ-FittingRoomListPanePaintInputScroll-source-quality-removed.md](0002DF-0002DL-0002DN-0002DQ-FittingRoomListPanePaintInputScroll-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Coverage Report Replacement Text

Placement context: replace the existing four rows in `by-memory/-coverage-report.md` under the FittingRoomListPane neighborhood.

Replace current `0002DF` row with:

```markdown
        - [UID:0002DF][0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar](by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md) 0x0041ee10-0x0041f0b0 | method | FittingRoomListPaneUpdateScrollBar : reconstructable : 87% : very strong : B003 2026-06-18 source-quality reanalysis confirms exact bounds, nine direct callers, no non-text pointer routes, active category/item-state catalog calls, enabled-entry count stored at this+0x10a, row/grid display mode at this+0x10c, scroll state at this+0x108, child scroll pane at this+0x11c, row page size 26, grid page size 3 rows with ceil(totalCount/6), 0..30000 range/current clamping, child visibility toggling, invalidation calls, and first-draft C++ readiness under FittingRoomListPane.
```

Replace current `0002DL` row with:

```markdown
        - [UID:0002DL][0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint](by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md) 0x0041f2b0-0x0041fb9b | method | FittingRoomListPaneOnPaint : reconstructable : 86% : very strong : B003 2026-06-18 source-quality reanalysis confirms exact vtable-only reachability through 0x0060dd54, WBOARDBK.EPF/WBOARDBK.PAL tiling, active category/item-state catalog reads, UpdateScrollBar call, grid start from this+0x108 and enabled-count guard at this+0x10a, selected-entry highlight scan over item-state +0x240/+0x244 (dialog +0x744/+0x748), 0xb4 selected-entry category/index comparisons, item icon/glyph helper roles, wrapped text helper roles, dword_69B3FC as shared Surface highlight/fill callback rather than generated g_pfnLockSurface, and first-draft C++ readiness with shared GrafPort/Surface/StringUtil dependencies kept outside FittingRoom ownership.
```

Replace current `0002DN` row with:

```markdown
        - [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md) 0x0041fcd0-0x004207ce | method | FittingRoomListPaneOnInputEvent : reconstructable : 86% : strong : B003 2026-06-18 source-quality reanalysis confirms exact vtable-only reachability through 0x0060dd7c, EventMan type 3 left-button-release selection and type 7 mouse-wheel scroll handling, event fields +4/+8/+0xc/+0x14, HitTestSlot and ValidateFittingSelectionIndex caller routes, row/grid slot-to-catalog math through this+0x108/+0x10c, selected-entry vector at dialog +0x744/+0x748, 0xb4 entry layout with category/name/index/part-vector fields, item part record fields +0/+2/+4, decoded part-code switch side effects including +0x49e and +0x4a8/+0x4aa/+0x4ac special/set preview fields, adjusted child/base event delegation, and first-draft C++ readiness with original item-part enum names still a confidence cap.
```

Replace current `0002DQ` row with:

```markdown
        - [UID:0002DQ][0x00420d00-0x00420d50.ValidateFittingSelectionIndex](by-memory/0x00420d00-0x00420d50.ValidateFittingSelectionIndex.md) 0x00420d00-0x00420d50 | function | ValidateFittingSelectionIndex : reconstructable : 87% : very strong : B003 2026-06-18 source-quality reanalysis confirms exact 0x50-byte body, sole OnInputEvent direct caller at 0x0041fded, no non-text pointer routes, active item-state/catalog lookup through g_pFittingRoomDialog +0x504/+0x784, signed 16-bit candidate validation against ItemCatalog count/GetItemByIndex, entry enabled byte +4 acceptance, -1 miss return, private member-or-static source signature recommendation without address suffix, and first-draft C++ readiness under FittingRoomListPane.
```

No by-class/by-file coverage row replacement is mandatory if supervisor keeps `FittingRoomListPane` and `FittingRoom` scores unchanged.

## Remaining Blockers

- Original item-part enum names for numeric codes `0x01`, `0x02`, `0x03`, `0x04`, `0x06`, `0x0d`, `0x0e`, `0x10`, `0x16`, `0x17`, `0x18`, `0x1e`, `0x1f`, `0x20`, and `0x21` are still not proven. Evidence checked: JSON parser field names, item-state docs, slot-geometry docs, simroot generated source, and PE switch side effects. The source-quality output should use descriptive/numeric enum constants until a schema/source name appears.
- Exact field names for preview fields around dialog `+0x480..+0x4fe` remain below final quality. Side effects are decoded, but original names are not preserved in current docs or executable metadata.
- `ValidateFittingSelectionIndex` member-vs-static spelling remains a minor source-shape ambiguity. The binary is ABI-compatible with a private `thiscall` helper because the caller sets `ecx`; the body itself does not read `this`, so a file-local static helper is source-equivalent. This should cap confidence but not block first-draft C++.
- `OnPaint` shared helper names remain descriptive for GrafPort/Surface/StringUtil calls. This is a dependency naming blocker, not an owner/source-placement blocker.
- `OnPaint` does not prove a row-mode renderer. Row/list mode is implemented by neighboring scroll/key/hit-test/slot-geometry helpers; do not invent a row paint branch for this target.
- Full class-level `FittingRoomListPane` C++ should remain blank until the remaining exact field names, item-part enum, and helper typedefs are reconciled across constructor/destructor, scroll pane, selection vector, and dialog item-state support.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002DF-0002DL-0002DN-0002DQ-FittingRoomListPanePaintInputScroll-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002DF"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002DF-0002DL-0002DN-0002DQ-FittingRoomListPanePaintInputScroll-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002DF-0002DL-0002DN-0002DQ-FittingRoomListPanePaintInputScroll-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002DF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
