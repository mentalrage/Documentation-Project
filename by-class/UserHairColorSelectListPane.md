*** UID:0000FK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class UserHairColorSelectListPane : public ListPane
{
public:
    explicit UserHairColorSelectListPane(CreateUserDialogPane *owner);
    virtual ~UserHairColorSelectListPane() {}

    int GetSelectedColorValue();
    virtual void DrawItem(int row,
                          const UserCreateColorSwatchItem *item,
                          const RectBounds *bounds);
    virtual void OnItemSelected(int row, int notify);

private:
    CreateUserDialogPane *m_owner;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserHairColorSelectListPane

## Status

- Confidence: strong for the swatch list, create-user ownership, and generic brush-helper exclusion.
- Likely source file: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Current recovered file: `source-3/simroot_v2/class_UserHairColorSelectListPane.cpp`
- Address range: [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- Owner/emitter: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md); formal H provides the exact closed class declaration at source position `50`, while formal CPP retains `[[CHILDREN]]` for registered definitions.

## Class Purpose

`UserHairColorSelectListPane` is the hair-color swatch list in the older create-user dialog. It adds 16 color entries, draws color swatches, and forwards the selected color byte to `CreateUserDialogPane::SetHairColorIndex`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00501e10-0x00501f12` | Builds a 4-column `ListPane`, seeds the hair-color order, selects the first item, and applies it to the owner dialog. |
| `DrawListItem` | `0x00501f30-0x00502087` | Draws selected highlight and inset color swatch through palette lookup. |
| `OnItemSelected` | `0x00502090-0x005020c3` | Calls base selection behavior and forwards the selected color to `CreateUserDialogPane::SetHairColorIndex`. |
| GrafPort `SetPalette` | [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md) | `DrawListItem` installs `PaletteLib::GetSlotPalette(14, 0, index)` at `0x00502037`, draws the hair-color swatch, and clears the borrowed GrafPort `DLPalette *` at `0x0050206f`. |

## Evidence Notes

- IDA confirms the active list-method starts.
- `xrefs_to 0x00501e10` reports construction from `CreateUserDialogPane::CreateUserDialogPane`.
- `xrefs_to 0x0052e930` reports calls from this constructor and `OnItemSelected`, confirming the owner callback.
- IDA direct callers for [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md) include `BalloonObjectPane::PaintBubble`, `ColorStringChattingMessage::Draw`, and the face-color list draw method. Constructor/destructor/DrawGlyph field evidence further proves `GetPalette` / `SetPalette` are GrafPort methods over borrowed `DLPalette *m_palette`, not `UserHairColorSelectListPane` methods.
- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) is `86/80` with a validated `NexusTK/login/` path and lists both color-list panes as proposed source contents.
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) is `70/85`, now reconstructable, and attached to [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md); it records the `0x00501e10-0x005020c3` hair-color constructor/draw/selection span.
- [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md) is attached to direct class parent [UID:00005V][GrafPort](by-class/GrafPort.md), emitted through [UID:0000JR][GrafPort](by-file/GrafPort.md), so the previous brush-helper ownership uncertainty no longer blocks this class's create-user placement.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed modeled starts at `0x00501e10`, `0x00501f30`, and `0x00502090`, with construction from `CreateUserDialogPane::CreateUserDialogPane` at `0x0052e17d`.
- Live vtable-slot xrefs reconfirm `0x0061dfe8 -> 0x00501f30` for the draw virtual and `0x0061dfe0 -> 0x00502090` for the selection-change virtual.
- Live decompilation of `0x00501e10` shows the list constructor building the 4-column swatch `ListPane`, loading the shared 16-entry color order from `0x0061e570`, `0x0061e580`, `0x0061e590`, and `0x0061e5a0`, installing the three `UserHairColorSelectListPane` vtables, storing the owner dialog at object slot `83`, adding all 16 rows, selecting row `0`, and calling `0x0052e930` with the first color byte.
- Live xrefs to `0x0052e930` show exactly two class-local callers: the constructor at `0x00501eee` and `OnItemSelected` at `0x005020b9`.

## Score Rationale

Completion is raised to `85` because the page now records live constructor/draw/selection boundaries, constructor caller, vtable slot refs, 16-entry shared color-order table, owner callback xrefs, generic brush-helper exclusion, direct source parent, and aggregate memory support. Confidence is raised to `88` because live IDA confirms the class vtables and owner callback path; it remains below final-source level because final field names and declaration shape are still not reconstructed.

## Cross-References

- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md)
- [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md)
- [Wave3 data issues](../wave3_data_issues.md)

## 2026-07-14 UID0001A6 Implemented Source Contract

- Current metadata: `90/92`, owner/emitter UID0000OX, position 50, reconstructable true.
- The exact managed declaration is in formal H and closes with `};`; formal CPP contains `[[CHILDREN]]`, so only registered method children emit out-of-line definitions.
- Source route is dedicated `NexusTK/login/UserCreateAppearanceControls.h/.cpp` through [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).

| Exact child | Source method | Behavior |
| --- | --- | --- |
| [UID:0004OY][0x00501e10-0x00501f12.UserHairColorSelectListPaneConstructor](by-memory/0x00501e10-0x00501f12.UserHairColorSelectListPaneConstructor.md) | `constructor` | 16 exact entries, no-notify initial selection, explicit owner callback |
| [UID:0004OZ][0x00501f20-0x00501f2f.UserHairColorSelectListPaneGetSelectedColorValue](by-memory/0x00501f20-0x00501f2f.UserHairColorSelectListPaneGetSelectedColorValue.md) | `GetSelectedColorValue` | retained zero-xref unguarded colorValue getter |
| [UID:0004P0][0x00501f30-0x00502087.UserHairColorSelectListPaneDrawItem](by-memory/0x00501f30-0x00502087.UserHairColorSelectListPaneDrawItem.md) | `DrawItem` | selected 128/143 fill, inset 3, mode 1, slot 14, palette clear |
| [UID:0004P1][0x00502090-0x005020c3.UserHairColorSelectListPaneOnItemSelected](by-memory/0x00502090-0x005020c3.UserHairColorSelectListPaneOnItemSelected.md) | `OnItemSelected` | base first, then SetHairColorIndex |

- Layout: Exact size 0x150; ListPane through +0x14b, non-owning CreateUserDialogPane *m_owner at +0x14c; each shared swatch entry is {int row,int colorValue}, eight bytes.
- Liveness/ABI: Constructor caller 0x0052e17d; draw vtable 0x0061dfe8; selection vtable 0x0061dfe0; owner callback 0x0052e930. Palette ownership remains GrafPort/PaletteLib, not this class.
- Shared type/table support is [UID:0004P6][UserCreateAppearanceControlLayouts](by-type/by-struct/UserCreateAppearanceControlLayouts.md) and [UID:0004P7][0x0061e570-0x0061e5b0.UserCreateAppearanceColorValueTable](by-memory/0x0061e570-0x0061e5b0.UserCreateAppearanceColorValueTable.md).
- [UID:0004P8][UserCreateAppearanceControlVtables](by-type/by-vtable/UserCreateAppearanceControlVtables.md) and [UID:0004P9][0x0061dd78-0x0061e0ec.UserCreateAppearanceControlVtableData](by-memory/0x0061dd78-0x0061e0ec.UserCreateAppearanceControlVtableData.md) remain compiler-generated/non-emitting; normal virtual destructors regenerate deleting wrappers and adjustors.
- Exact addresses, bytes, fields, calls, branches, constants, and side effects are binary facts. Source spellings/file split are bounded inference because no authentic source/PDB survives.
- Rejected: broad-parent output, dialog ownership, renderer/palette ownership, raw offset/decompiler C++, explicit vptr/cookie/adjustor source, guards absent from the binary, and duplicate aggregate/class/child emission.
- Historical notes below remain provenance snapshots; this implemented contract supersedes stale blank-C++, missing-child, old-name, inline-only, and unresolved-placement assertions.

## Changes

- 2026-07-12 B004 UID000163 consumer sync:
  - Score, metadata, and formal C++ remain unchanged.
  - Replaced historical generated brush-helper wording with exact slot-14 `DLPalette *` install at `0x00502037` and null clear at `0x0050206f`; direct ownership remains GrafPort, and no getter or ownership transfer is attributed to this class.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:74`.
  - Summary/evidence: scored from constructor/draw/selection behavior, owner callback xrefs, create-user appearance grouping, and explicit evidence that generated brush-helper ownership is suspect.
- 2026-06-03 autogen attachment pass:
  - Before: the page remained unparented at `80/74`, with confidence capped by generated brush-helper ownership.
  - Changed to: completion/confidence `82/84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OX`.
  - Evidence: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) is `86/80`; [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) is `70/85` and attached to the same parent; [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md) is separately attached through [UID:00005V][GrafPort](by-class/GrafPort.md) and [UID:0000JR][GrafPort](by-file/GrafPort.md), resolving the stale generated helper-owner caveat for this class. C++ remains blank because the final class declaration and field names are not at the `95+` threshold.
- 2026-06-14 A002 Goal 2 live class refresh:
  - Before: `82/84`.
  - After: `85/88`; owner and emitter remain [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).
  - Evidence: live IDA MCP session `a001_goal2_class_batch` reconfirmed constructor/draw/selection starts, create-user constructor caller, vtable slot refs, shared 16-entry color-order table refs, and the exact two `SetHairColorIndex` callback refs from this class.
