*** UID:0000AQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000AP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MouseEvent;
struct PowerEntryRecord;
struct RectBounds;

class PowerListPane : public ListPane
{
public:
    PowerListPane(int entrySize, int listWidth);
    virtual ~PowerListPane();

protected:
    virtual bool OnMouseEvent(MouseEvent *event);
    virtual void DrawListItem(int rowIndex,
                              const PowerEntryRecord *entry,
                              const RectBounds *rowBounds);

private:
    void FillColorRect(const RectBounds *bounds, int palettePage, int colorIndex);
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Complete fieldless 0x14c ListPane-derived private PowerListPane declaration with public two-argument constructor and empty virtual destructor, protected mouse/draw overrides, private fill helper, three compiler vtable views, exact PowerDialogPane.cpp source ordering, and compiler-only deleting-wrapper/thunk exclusions. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PowerListPane

## Status

- Confidence: very strong for exact RTTI class spelling, ListPane inheritance, `0x14c` fieldless layout, constructor/destructor ABI, live method/vtable boundaries, `g_pPowerDialog` relationship, and private placement beside `PowerDialogPane`; only original parameter spelling and physical header filename remain inferred.
- Reconstructability: complete private list-control class in [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md). This page emits the full declaration through UID0000AP at position `10`; source-bearing definitions route directly through the same emitter with explicit positions, so the obsolete nested `[[CHILDREN]]` placeholder is intentionally removed.
- Parent source file: [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- Address range: [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- Current metadata: `92/94`, canonical owner UID0000MO retained, reconstructable true, emitter UID0000AP position `10`.

## Class Purpose

`PowerListPane` is the embedded [UID:00007A][ListPane](by-class/ListPane.md)-derived control used by [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md). It draws power entries with a color swatch and right-aligned label, manages drag/click/double-click selection, and clears selection from sibling power lists when a new list starts dragging.

The large routine at `0x00549c20` should not remain class-owned by the list control. It builds the containing `PowerDialogPane`, not a standalone list pane. The real list-control methods are the `0x0054b000-0x0054b5d5` block.

The temporary `g_activePowerListPane` label should also not remain list-owned. Live IDA xrefs show the storage is [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md) at `0x0069ba34`; `OnMouseEvent` reads it only to access the containing dialog's sibling list controls.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| [UID:0004RQ][0x0054aec0-0x0054af02.PowerListPaneConstructor](by-memory/0x0054aec0-0x0054af02.PowerListPaneConstructor.md) | `0x0054aec0-0x0054af02` | Exact retained two-argument constructor. Forwards entry size/list width plus fixed `96/12/false/true/true` to ListPane, installs three class vptr views, adds no fields, and is inlined in live UID0001F5 construction. |
| [UID:0004B4][0x0054af10-0x0054af2f.PowerListPaneDestructorBody](by-memory/0x0054af10-0x0054af2f.PowerListPaneDestructorBody.md) | `0x0054af10-0x0054af2f` | Exact empty source virtual destructor. Its binary restores three PowerListPane vtable views and tail-chains to no-argument `ListPane` teardown entirely through compiler lowering; source emits through UID0000AP position `100`. |
| [UID:0004B6][0x0054b000-0x0054b210.PowerListPaneOnMouseEvent](by-memory/0x0054b000-0x0054b210.PowerListPaneOnMouseEvent.md) | `0x0054b000-0x0054b210` | `90/91` class-emitted `bool PowerListPane::OnMouseEvent(MouseEvent *event)`. Handles move/down/double-click/up events, hit-tests rows through `ListPane`, clears sibling list selections through [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md) controls `7..10`, uses drag byte `this+0x149`, and starts/ends capture through [UID:00028L][0x0067a754-0x0067a758.g_pEventMan](by-memory/0x0067a754-0x0067a758.g_pEventMan.md). |
| [UID:0004B7][0x0054b220-0x0054b34b.PowerListPaneDrawListItem](by-memory/0x0054b220-0x0054b34b.PowerListPaneDrawListItem.md) | `0x0054b220-0x0054b34b` | `88/91` class-emitted `void PowerListPane::DrawListItem(int rowIndex, const PowerEntryRecord *entry, const RectBounds *rowBounds)`. Draws selected row frame, splits `displayColor + 4` into palette page/color index, fills the exact swatch rectangle, right-aligns the UTF-16 label, and leaves [UID:0004B8][0x0054b350-0x0054b4f0.PowerListPaneFillColorRect](by-memory/0x0054b350-0x0054b4f0.PowerListPaneFillColorRect.md) as the separate fill helper. |
| [UID:0004B8][0x0054b350-0x0054b4f0.PowerListPaneFillColorRect](by-memory/0x0054b350-0x0054b4f0.PowerListPaneFillColorRect.md) | `0x0054b350-0x0054b4f0` | `89/90` routed child with first-draft formal `PowerListPane::FillColorRect(const RectBounds *bounds, int palettePage, int colorIndex)` C++. Clips the swatch rectangle, maps `g_pPaletteLib->GetSlotPalette(3, 0, palettePage)` / `DLPalette::MapColor(colorIndex)`, gates on inherited draw state, and directly fills the 16-bit buffer. |
| Destructor thunks and wrapper | `0x0054b506-0x0054b5d5` | Compiler [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md) plus no-code compiler wrapper [UID:0004BA][0x0054b580-0x0054b5d5.PowerListPaneScalarDeletingDestructor](by-memory/0x0054b580-0x0054b5d5.PowerListPaneScalarDeletingDestructor.md). Source should define/destruct the class normally and let the compiler generate wrappers. |

## Entry Data

Constructor and drawing behavior point to an inline row record:

| Offset | Field | Type | Notes |
| --- | --- | --- |
| `+0x000` | `entryId` | `unsigned int` | Sent back by `PowerDialogPane::ApplyPowerSlot`. |
| `+0x004` | `listColumn` | `unsigned char` | Chooses one of the four embedded lists. Constructor packet values `1..4` map to dialog controls `7..10` through `listColumn + 6`; x86/MSVC natural alignment supplies implicit bytes `+0x005..+0x007` before `amount`. No explicit source padding field is required. |
| `+0x008` | `amount` | `unsigned int` | Accumulated into the dialog row-total grid. |
| `+0x00c..+0x20b` | `label[256]` | `wchar_t[256]` | Converted from packet text with `MultiByteToWideChar`. |
| `+0x20c` | `displayColor` | `int` | Encoded as `52 + 8 * thresholdValue`; drawing splits it into palette/page and color index, and the apply helper overwrites this field for the selected row. |

Natural 32-bit alignment retains exact offsets `entryId +0`, `listColumn +4`, `amount +8`, `label +0x0c`, and `displayColor +0x20c`, with `sizeof(PowerEntryRecord)==0x210`. An explicit `reserved0[3]` member is rejected as reverse-engineering source pollution.

[UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md) now formalizes this first-draft layout as `PowerEntryRecord`. That constructor-created control-id mapping is also what lets `PowerListPane::OnMouseEvent` use [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md) to clear sibling selections across controls `7..10`.

B012 UID0004B5 confirms the same row layout is consumed by the file-local [UID:0004B5][0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries](by-memory/0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries.md) callback: MCP session `eb7ce28b` shows the comparator reads `displayColor +0x20c`, ties on descending `amount +0x008`, and emits through [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md). This does not make the callback a `PowerListPane` method; it remains a file-local sort function passed into the list sort helper.

## Evidence Notes

- Live IDA MCP confirms function boundaries: `0x0054b000-0x0054b210`, `0x0054b220-0x0054b34b`, `0x0054b350-0x0054b4f0`, adjustor thunks at `0x0054b506-0x0054b511` and `0x0054b511-0x0054b51c`, scalar deleting destructor `0x0054b580-0x0054b5d5`, then `int3` padding through `0x0054b5df` before the next function at `0x0054b5e0`.
- Live vtable names bind the class: primary `??_7PowerListPane@@6B@` at `0x006221f4`, secondary `??_7PowerListPane@@6B@_0` at `0x0062227c`, and tertiary `??_7PowerListPane@@6B@_1` at `0x006222ac`. Constructor/setup writes occur at `0x00549f58`, `0x00549f5e`, `0x00549f68`, `0x0054af10`, `0x0054af16`, and `0x0054af20`; [UID:0004B4][0x0054af10-0x0054af2f.PowerListPaneDestructorBody](by-memory/0x0054af10-0x0054af2f.PowerListPaneDestructorBody.md) is now the exact non-deleting destructor body for the `0x0054af10` vtable-reset sequence, and [UID:0004BA][0x0054b580-0x0054b5d5.PowerListPaneScalarDeletingDestructor](by-memory/0x0054b580-0x0054b5d5.PowerListPaneScalarDeletingDestructor.md) covers the compiler wrapper reset at `0x0054b586`, `0x0054b58c`, and `0x0054b596`.
- Primary vtable slots include scalar deleting destructor `0x006221f4 -> 0x0054b580`, mouse handler `0x00622254 -> 0x0054b000`, and draw handler `0x00622274 -> 0x0054b220`. Secondary/tertiary slots point to the `this`-adjusting destructor thunks at `0x0062227c -> 0x0054b506` and `0x006222ac -> 0x0054b511`.
- IDA decompilation of `0x0054b000` shows a mouse-event switch on the byte at event offset `+4`, coordinates from `+8/+12`, drag state at `this+329` / `this+0x149`, hit tests through `0x004f4480`, visibility updates through `0x004f4920`, and sibling-list selection clearing through the owner dialog's control lookup at `g_pPowerDialog + 0x1fc`.
- B006 UID0004B6 implementation confirms `0x0054b000` is exact size `0x210`, `0x0054b210-0x0054b220` is padding before draw-list-item, no static callers exist, vtable data xref `0x00622254` dispatches the method, and the emitted source route is `PowerListPane::OnMouseEvent(MouseEvent *event)` in `NexusTK/ui/dialogs/PowerDialogPane.cpp`. Capture/release uses `dword_67A754` / [UID:00028L][0x0067a754-0x0067a758.g_pEventMan](by-memory/0x0067a754-0x0067a758.g_pEventMan.md), not `g_pMetaMan`; exact event enum and virtual slot names remain confidence caps only.
- B004 UID0004B7 implementation confirms `0x0054b220` is exact size `0x12b`, vtable slot `0x00622274 -> 0x0054b220` dispatches it, and the emitted source route is `PowerListPane::DrawListItem(int rowIndex, const PowerEntryRecord *entry, const RectBounds *rowBounds)` in `NexusTK/ui/dialogs/PowerDialogPane.cpp`. The report evidence fixes the row-index/entry/rowBounds argument roles, selected-row frame color `143`, `displayColor + 4` palette split, swatch bounds `left+5/top+1/left+15/bottom-1`, text color `37`, right-aligned label placement, explicit UTF-16 length scan, separate UID0004B8 helper call, and confidence caps for renderer helper spellings.
- B003 session `b003_powerdialog_0001f5_20260628` ties the constructor-created packet `listColumn` values `1..4` to controls `7..10` through `listColumn + 6`, matching the sibling-selection loop in `PowerListPane::OnMouseEvent`; this reinforces that `0x00549c20` is PowerDialogPane-owned setup, not list-owned code.
- `g_pPowerDialog` storage at `0x0069ba34` has the expected live xrefs: constructor write `0x0054a44c`, dialog reset/destructor clears `0x0054a49a` and `0x0054b540`, accessor read `0x0054a4b0`, and this list's read `0x0054b010`.
- IDA decompilation of `0x0054b220` shows selected-row decoration via `0x004f3f00`, swatch fill through local helper `0x0054b350`, color value from row offset `+0x20c`, and UTF-16 label rendering from row offset `+0x0c`.
- B001 UID0004B8 implementation confirms the fill helper is now an emitting child routed through this class. Fresh `supervisor_resume_20260629` MCP evidence records exact `0x0054b350-0x0054b4f0` range/size `0x1a0`, successor `0x0054b4f0`, one direct caller at `0x0054b2d7` inside UID0004B7, callees `GrafPort::GetClipRect`, `IntersectRects`, `IsRectEmptyOrInvalid`, `PaletteLib::GetSlotPalette`, `DLPalette::MapColor`, and security-cookie glue, plus bounded decompile/disasm proof of the clip gate, palette mapping, inherited draw-mode gate, and optimized direct 16-bit fill loop. The old blank-emitter/formal-C++ blocker is superseded.
- Historical IDA lookup reports `0x0054aec0` is not a function object, but bounded current instruction/byte analysis proves 22 defined instructions, a coherent two-argument constructor through `retn 8`, exact bytes SHA256 `FB2E37A7A01D1D93AB1296A9F5B6B1500C919C1D354F05F2614114B2C19057E8`, and an exact inlined live copy in UID0001F5. The prior generated-ghost/no-source conclusion is superseded.
- `0x0054b506` and `0x0054b511` are real `0xb` compiler adjustor thunk starts. They are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md), not as feature methods.

## Source Layout Decision

Keep `PowerListPane` adjacent to `PowerDialogPane` in `ui/dialogs/PowerDialogPane.cpp`. It is feature-private: current evidence only ties it to the power dialog, and it depends on the dialog's four-list selection model and packet row format. Generic list behavior stays in [UID:00007A][ListPane](by-class/ListPane.md). Direct UID0000AP routing is output ordering only; canonical class ownership remains here and canonical file ownership remains UID0000MO.

[UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md) remains a reviewed non-emitting source-island container. PowerListPane source is carried by exact constructor UID0004RQ, empty destructor UID0004B4, methods UID0004B6/B7/B8, and this complete class declaration; deleting wrapper UID0004BA and adjustor thunks UID0001F8 remain compiler-only. UID0000AP positions `10/90/100/120/130/140/150` provide legal declaration/definition order without broad-parent duplication.

## Cross-References

- [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md)
- [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md)
- [UID:0004RQ][0x0054aec0-0x0054af02.PowerListPaneConstructor](by-memory/0x0054aec0-0x0054af02.PowerListPaneConstructor.md)
- [UID:0004B4][0x0054af10-0x0054af2f.PowerListPaneDestructorBody](by-memory/0x0054af10-0x0054af2f.PowerListPaneDestructorBody.md)
- [UID:0004B6][0x0054b000-0x0054b210.PowerListPaneOnMouseEvent](by-memory/0x0054b000-0x0054b210.PowerListPaneOnMouseEvent.md)
- [UID:0004B7][0x0054b220-0x0054b34b.PowerListPaneDrawListItem](by-memory/0x0054b220-0x0054b34b.PowerListPaneDrawListItem.md)
- [UID:0004B8][0x0054b350-0x0054b4f0.PowerListPaneFillColorRect](by-memory/0x0054b350-0x0054b4f0.PowerListPaneFillColorRect.md)
- [UID:0004BA][0x0054b580-0x0054b5d5.PowerListPaneScalarDeletingDestructor](by-memory/0x0054b580-0x0054b5d5.PowerListPaneScalarDeletingDestructor.md)
- [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md)
- [UID:00007A][ListPane](by-class/ListPane.md)

## Score Rationale

- `COMPLETION:92`: exact constructor/destructor bodies, complete declaration, method island, vtable slots, fieldless `0x14c` layout, row type, compiler split, source ordering, and file placement are now implemented.
- `CONFIDENCE:94`: RTTI names, exact vptr triads, two-argument constructor/inlined copy, empty destructor/base chain, primary wrapper and adjustor routes, and all existing method evidence agree. Original parameter spelling and physical header filename cap the score below final-source proof.
- `RECONSTRUCTABLE:TRUE`: complete class source emits through UID0000AP in PowerDialogPane.cpp; deleting wrappers, thunks, base lowering, and raw vtable arrays remain compiler-generated exclusions.

## Changes

- 2026-07-15 B001 UID0004B4 accepted callback:
  - Raised `86/88 -> 92/94`, retained canonical owner UID0000MO/reconstructable true, changed output emitter to UID0000AP position `10`, and replaced the incomplete shell/`[[CHILDREN]]` placeholder with the complete public constructor/destructor, protected overrides, and private fill-helper declaration.
  - Added real constructor child UID0004RQ, exact two-argument/fixed-base/inlined-live evidence, empty destructor/compiler-base split, fieldless `0x14c` layout, natural `PowerEntryRecord` alignment and `0x210` size, direct source-order routing, wrapper/thunk/vtable exclusions, negative evidence, and historicalized generated-ghost assumptions.

- 2026-07-04 B012 UID0004B5 support sync:
  - Added the file-local comparator row-layout consumer note for [UID:0004B5][0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries](by-memory/0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries.md).
  - Summary/evidence: UID0004B5 MCP session `eb7ce28b` confirms the comparator reads `PowerEntryRecord::displayColor +0x20c` and `PowerEntryRecord::amount +0x008`, but has no `PowerListPane` receiver and emits through [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md) as a file-local callback.
- 2026-07-02 B004 accepted [UID:0004B7][0x0054b220-0x0054b34b.PowerListPaneDrawListItem](by-memory/0x0054b220-0x0054b34b.PowerListPaneDrawListItem.md) implementation:
  - Added the private `PowerListPane` declaration shell with `OnMouseEvent`, `DrawListItem`, `FillColorRect`, and `[[CHILDREN]]`, preserving the already-implemented UID0004B6 child.
  - Updated the method inventory, evidence, and source-layout decision so UID0004B7 is an emitting `void PowerListPane::DrawListItem(int rowIndex, const PowerEntryRecord *entry, const RectBounds *rowBounds)` child routed through this class into [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md).
  - Summary/evidence: B004 report/MCP evidence records exact range `0x0054b220-0x0054b34b` size `0x12b`, vtable slot `0x00622274 -> 0x0054b220`, selected-row frame, `displayColor + 4` split, exact swatch geometry, right-aligned UTF-16 label placement and length scan, separate UID0004B8 helper call, rejected no-code disposition, and confidence caps for inferred renderer helper spellings.
- 2026-07-02 B001 accepted [UID:0004B8][0x0054b350-0x0054b4f0.PowerListPaneFillColorRect](by-memory/0x0054b350-0x0054b4f0.PowerListPaneFillColorRect.md) implementation:
  - Updated the method inventory and evidence so UID0004B8 is the routed first-draft `PowerListPane::FillColorRect` child through [UID:0000AQ][PowerListPane](by-class/PowerListPane.md), with formal C++ for the clipped 16-bit swatch fill.
  - Summary/evidence: fresh MCP session `supervisor_resume_20260629` confirms exact `0x1a0` body, successor thunk at `0x0054b4f0`, single UID0004B7 call at `0x0054b2d7`, helper callees, direct buffer fill rather than slot `0x0069b3fc`, and score route from `84/88` blank-emitter state to `89/90` emitted helper. Inherited GrafPort field names remain inferred confidence caps only.
- 2026-07-02 B006 accepted [UID:0004B6][0x0054b000-0x0054b210.PowerListPaneOnMouseEvent](by-memory/0x0054b000-0x0054b210.PowerListPaneOnMouseEvent.md) implementation:
  - Updated the method inventory and evidence so UID0004B6 is the emitting `bool PowerListPane::OnMouseEvent(MouseEvent *event)` child through [UID:0000AQ][PowerListPane](by-class/PowerListPane.md), with sibling clearing through `g_pPowerDialog` controls `7..10`, drag byte `this+0x149`, and capture/release through `g_pEventMan` rather than stale `g_pMetaMan`.
- 2026-06-29 B002 accepted UID0001F6 split/container repair support sync:
  - Added exact child rows for [UID:0004B4][0x0054af10-0x0054af2f.PowerListPaneDestructorBody](by-memory/0x0054af10-0x0054af2f.PowerListPaneDestructorBody.md) non-deleting destructor body, [UID:0004B6][0x0054b000-0x0054b210.PowerListPaneOnMouseEvent](by-memory/0x0054b000-0x0054b210.PowerListPaneOnMouseEvent.md) mouse handler, [UID:0004B7][0x0054b220-0x0054b34b.PowerListPaneDrawListItem](by-memory/0x0054b220-0x0054b34b.PowerListPaneDrawListItem.md) draw item, [UID:0004B8][0x0054b350-0x0054b4f0.PowerListPaneFillColorRect](by-memory/0x0054b350-0x0054b4f0.PowerListPaneFillColorRect.md) fill color rectangle, and [UID:0004BA][0x0054b580-0x0054b5d5.PowerListPaneScalarDeletingDestructor](by-memory/0x0054b580-0x0054b5d5.PowerListPaneScalarDeletingDestructor.md) scalar deleting destructor wrapper.
  - Summary/evidence: MCP session `279422f0` reconfirmed the relevant starts; `0x0054af10` is now promoted from vtable setup note to exact `PowerListPane::~PowerListPane()` body, while `0x0054b580` remains a non-reconstructable compiler wrapper. [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md) is now a non-emitting container, so broad parent C++ must not duplicate these children.
- 2026-06-28 B003 accepted [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md) support sync:
  - Refined the row-record table to the 528-byte constructor/list layout with exact offsets and padding, and recorded the `listColumn + 6` control-id mapping for controls `7..10`.
  - Summary/evidence: B003 MCP session `b003_powerdialog_0001f5_20260628` confirmed the constructor's packet row parse, list append, grid accumulation, and sibling-selection relationship through `g_pPowerDialog`; `0x00549c20` remains corrected to [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md), not PowerListPane ownership.
- 2026-06-04: Raised completion/confidence from `82/76` to `86/88`, marked `RECONSTRUCTABLE:TRUE`, and attached the class to [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md). The increase is justified by fresh live IDA MCP research proving the exact function ranges, vtable slots at `0x006221f4`, `0x0062227c`, and `0x006222ac`, setup/destructor vtable writes, `g_pPowerDialog` xrefs, mouse-event switch behavior, drawing helper behavior, and the post-destructor padding boundary.
- Before: completion/confidence metadata were `0/0` even though the page already documented embedded-list behavior, constructor ownership pollution, method roles, entry data, vtable/thunk evidence, and source-layout decision.
- Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
- Evidence: `OnMouseEvent`, `DrawListItem`, `FillColorRect`, destructor/thunk behavior, row record fields, `g_pPowerDialog` ownership correction, and private `PowerDialogPane` placement are documented; confidence remained medium-high because final original class name and `0x00549c20` ownership cleanup were still open.
