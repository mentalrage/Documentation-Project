*** UID:0000FL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class UserHairSelectControlPane : public ControlPane
{
public:
    enum { kColumns = 9, kRows = 2, kCellWidth = 82, kCellHeight = 58 };

    UserHairSelectControlPane(short selectedHair,
                              unsigned char hairColor,
                              unsigned char gender,
                              const RectBounds *bounds,
                              unsigned char controlFlags);
    virtual ~UserHairSelectControlPane() {}

    virtual bool OnMouseEvent(const MouseEvent *event);
    virtual void OnPaintFrame();

    void SelectHairAtPoint(int mouseY, int mouseX);
    void SetMaleMode();
    void SetFemaleMode();
    void SetHairColorIndex(unsigned char color) { m_hairColor = color; }
    short GetSelectedHairSlot() const { return m_selectedHair; }
    unsigned short GetSelectedHairPartFrame() const
    {
        return m_hairPartFrames[m_gender][m_selectedHair];
    }

private:
    unsigned char m_reservedState;
    short m_selectedHair;
    unsigned char m_gender;
    unsigned char m_hairColor;
    bool m_mouseTracking;
    unsigned short m_hairPartFrames[2][18];
    unsigned char m_columnCount;
    RectBounds m_hitBounds;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserHairSelectControlPane

## Status

- Confidence: very strong for class identity, method inventory, caller routes, field/table layout, destructor/thunk policy, and declaration-level C++; medium-high for exact event typedef names, render-helper spellings, final original source split, and byte `+0x108`.
- Likely source file: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Current recovered file lead: `source-3/simroot_v2/class_UserHairSelectControlPane.cpp`; use local exported IDA records, raw PE checks, and the linked by-* support docs as the current authority.
- Address range: [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- Autogen handling: this class emits its complete declaration from formal H at source position `20` through [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md); formal CPP retains only `[[CHILDREN]]` for exact constructor/mouse/paint/select/style-helper definitions. Scalar deleting destructor and adjustor-thunk pages remain compiler-generated support regenerated from the inline empty virtual destructor declaration.

## Class Purpose

`UserHairSelectControlPane` is the hair thumbnail selector used by the older create-user dialog. It draws a two-row by nine-column grid of hair parts, tracks mouse selection, stores the selected hair slot and hair color, and exposes the gender/style-banked hair part frame used by [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) when refreshing the old create-user preview or building the create-character request.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00501150-0x005012af` | `UserHairSelectControlPane::UserHairSelectControlPane(short initialHairSlot, unsigned char hairColor, unsigned char genderStyle, const RectBounds *bounds, unsigned char controlFlag)`. The constructor calls `ControlPane::ControlPane(this, 8, bounds)`, installs primary/EventHandler/TimerHandler vtables, stores selector state, normalizes a local hit rect, and seeds two 18-entry hair-part-frame banks. |
| `OnMouseEvent` | `0x005012b0-0x0050135a` | Secondary/EventHandler vtable entry at `0x0061dde8`; the receiver is the EventHandler subobject (`object + 0xa0`). It hit-tests the local grid, tracks press/release state, calls `SelectHairAtPoint`, and falls back to the inherited mouse handler for non-captured non-grid events. |
| `OnPaintFrame` | `0x00501360-0x0050158a` | Primary vtable entry at `0x0061ddc0`; draws the 9x2 hair thumbnail grid through NewHumanImageLib, PaletteLib, EPFLib/resource-layout helpers, and Surface callbacks, then draws the `USERPART.EPF`/`USERPART.PAL` selection frame over the selected cell. |
| `SelectHairAtPoint` | `0x00501590-0x00501612` | `void SelectHairAtPoint(int mouseY, int mouseX)`. Divides by 82x58 cell dimensions, clamps column to `m_gridColumns - 1`, clamps row to `1`, writes `m_selectedHairSlot = col + row * m_gridColumns`, and invalidates the pane bounds through the primary vtable refresh slot. |
| `SetMaleMode` / `SetFemaleMode` | `0x00501620`, `0x00501640` | Updates the hair selector gender/style bank at `+0x10c` to `0` or `1` and invalidates; called by `CreateUserDialogPane::SelectMale`/`SelectFemale` on old-dialog control id `6`. These helpers were previously misattributed to `UserShapeSelectControlPane`. |
| destructor/thunks | [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md), `0x00502d90` | Adjustor thunks are ignored compiler support; `0x00502d90` is the scalar deleting destructor wrapper for implicit/defaulted source destructor `UserHairSelectControlPane::~UserHairSelectControlPane()`. No derived cleanup body is proven; base `Pane::~Pane()`, delete flags, guard helper, and `operator delete` are compiler/base output. |

## Field Map

| Offset | Type | Recommended name | Evidence |
| --- | --- | --- | --- |
| `+0x108` | `unsigned char` | `m_reserved108` | Constructor clears this byte, and checked hair-selector methods plus old-dialog caller paths do not read it. Keep it explicit but unresolved; it caps final naming confidence. |
| `+0x10a` | `short` | `m_selectedHairSlot` | Constructor seeds it from `rand() % 10`; `SelectHairAtPoint` writes `col + row * m_gridColumns`; paint and preview routes read it. |
| `+0x10c` | `unsigned char` | `m_genderStyle` | Constructor receives `0`; `SetMaleMode` writes `0`, `SetFemaleMode` writes `1`; paint and preview routes use it as the 18-entry hair-part-bank selector. `m_styleMode` or `m_partTableBank` are acceptable fallbacks, but `m_genderStyle` best matches the dialog gender handlers. |
| `+0x10d` | `unsigned char` | `m_hairColor` | Constructor seeds `12`; `CreateUserDialogPane::SetHairColorIndex` writes this byte on control id `6`; paint uses `m_hairColor >> 5` for palette selection. |
| `+0x10e` | `bool` / `unsigned char` | `m_mouseDownInGrid` | Constructor clears; `OnMouseEvent` sets it on mouse-down inside the grid, clears it on outside press, and requires it for release-time reselection. |
| `+0x110` | `uint16_t[18]` | `m_hairPartFrames[0]` | Constructor writes the style/gender bank `0` part-frame ids `{2, 60, 1, 8, 34, 48, 80, 36, 3, 83, 0, 15, 17, 24, 49, 71, 51, 59}`. These are hair part frame ids, not coordinate pairs. |
| `+0x134` | `uint16_t[18]` | `m_hairPartFrames[1]` | Constructor writes the style/gender bank `1` part-frame ids `{33, 74, 78, 50, 91, 10, 31, 4, 7, 45, 5, 13, 25, 54, 65, 80, 52, 58}`. |
| `+0x158` | `unsigned char` | `m_gridColumns` | Constructor writes `9`; paint and selection use it for grid column count and row stride. |
| `+0x15c` | `RectBounds` | `m_localHitRect` | Constructor copies the input bounds, subtracts left/top from right/bottom, and zeros left/top. `OnMouseEvent` uses this local rectangle from the EventHandler view (`secondary this + 0xbc == complete object + 0x15c`). |

The object allocation in `CreateUserDialogPane::CreateUserDialogPane` is `0x16c` bytes, and constructor writes extend through `+0x168..+0x16b`. Do not use the older OOAnalyzer/Ghidra `712`-byte class-size artifact for final layout.

## Grid, Mouse, And Selection Behavior

- Source constants are `kHairColumns = 9`, `kHairRows = 2`, `kHairCellWidth = 82`, `kHairCellHeight = 58`, and `kHairSlotsPerGender = 18`.
- The constructor call rectangle is `{170, 342, 926, 477}` in the old dialog, producing a normalized hit rectangle width `756` and height `135`.
- `OnMouseEvent` receives the secondary-base pointer. Raw reads of `secondary this + 0xbc` and `secondary this + 0x6e` correspond to complete-object `m_localHitRect` at `+0x15c` and `m_mouseDownInGrid` at `+0x10e`.
- Event code `1` starts or clears capture; event code `0` continues selection only when a prior in-grid down was captured. Exact enum names remain common mouse-event work.
- `SelectHairAtPoint` clamps `mouseX / 82` into `[0, m_gridColumns - 1]`, clamps `mouseY / 58` into `[0, 1]`, stores the resulting slot at `+0x10a`, and invalidates inherited bounds at `this + 0x44`. Do not describe this as a direct paint call.

## Paint And Resource Dependencies

- `OnPaintFrame` initializes temporary EPF/frame contexts, prepares the pane/GrafPort draw context, and iterates two rows by nine columns.
- For each cell it reads `m_hairPartFrames[m_genderStyle][row * m_gridColumns + column]`, calls the NewHumanImageLib part-frame draw path with part category `5`, centers the part in an 82x58 cell, selects a palette family using category `14` and `m_hairColor >> 5`, and draws through the shared Surface render callbacks.
- The selected-cell overlay is loaded from `USERPART.EPF` / `USERPART.PAL` through the EPFLib/resource-layout path and centered over `(m_selectedHairSlot % m_gridColumns, m_selectedHairSlot / m_gridColumns)`.
- Exact final helper names for the EPF contexts, NewHumanImageLib load/draw calls, PaletteLib lookup, and Surface callback typedefs remain unresolved. Use descriptive source helpers in drafts, not raw `sub_` or `dword_` names.

## Dialog Caller Semantics

- `CreateUserDialogPane::CreateUserDialogPane` allocates `0x16c` bytes for this selector, builds bounds `{170,342,926,477}`, and calls the constructor with `initialHairSlot = rand() % 10`, `hairColor = 12`, `genderStyle = 0`, the bounds pointer, and `controlFlag = 0`.
- In the old create-user dialog, control id `6` is this hair selector, control id `7` is [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md), and control id `18` / `0x12` is [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md).
- `CreateUserDialogPane::SetHairColorIndex` at `0x0052e930` looks up control id `6`, writes the selected hair color to `+0x10d`, invalidates this selector, and refreshes the preview. The hair selector is the callee/state owner; the dialog remains the callback coordinator.
- `CreateUserDialogPane::SelectMale` writes dialog gender byte `+0x279 = 0`, calls `SetMaleMode` at `0x00501620` on control id `6`, writes face selector `+0x10c = 0` on control id `7`, invalidates the face selector, and refreshes the preview.
- `CreateUserDialogPane::SelectFemale` mirrors this with dialog gender byte `+0x279 = 1`, `SetFemaleMode` at `0x00501640`, face selector `+0x10c = 1`, invalidation, and preview refresh.
- Preview setup reads the hair frame as `m_hairPartFrames[m_genderStyle][m_selectedHairSlot]` by indexing `+0x110 + 2 * (selectedHair + 18 * hairStyle)`, reads `m_hairColor`, and passes both into `UserCreatePreviewControlPane::UpdatePreview`/constructor together with face frame, face color, and dialog `m_isFemale`.

## Multiple-Inheritance And Vtable Notes

- Primary vtable `0x0061dd7c` begins with scalar deleting destructor `0x00502d90`; its paint slot at `0x0061ddc0` points to `0x00501360`.
- Secondary vtable `0x0061dde4` is installed at complete-object `+0xa0`; its first slot is adjustor thunk `0x005025d4`, and the mouse-event slot at `0x0061dde8` points to `0x005012b0`.
- Tertiary vtable `0x0061de14` is installed at complete-object `+0xa4`; its first slot is adjustor thunk `0x005025df`, followed by inherited/default handler slots.
- The source declaration must model the inherited base set that produces the primary, `+0xa0`, and `+0xa4` vptrs, but source must not hand-port the 11-byte destructor adjustors.

## Raw PE And Boundary Evidence

| Item | Range | Size | Raw offset | Route facts |
| --- | --- | ---: | ---: | --- |
| constructor | `0x00501150-0x005012af` | `0x15f` | `0x00100550` | Direct caller only at `0x0052e0af`; writes vtables and fields through `+0x168`. |
| `OnMouseEvent` | `0x005012b0-0x0050135a` | `0xaa` | `0x001006b0` | Vtable-only VA ref at `.rdata:0x0061dde8`; no direct `E8/E9` caller. |
| `OnPaintFrame` | `0x00501360-0x0050158a` | `0x22a` | `0x00100760` | Vtable-only VA ref at `.rdata:0x0061ddc0`; no direct `E8/E9` caller. |
| `SelectHairAtPoint` | `0x00501590-0x00501612` | `0x82` | `0x00100990` | Direct caller only from `OnMouseEvent` at `0x00501300`. |
| `SetMaleMode` | `0x00501620-0x00501631` | `0x11` | `0x00100a20` | Direct caller only at `0x0052e89b`; writes `+0x10c = 0` and invalidates. |
| `SetFemaleMode` | `0x00501640-0x00501651` | `0x11` | `0x00100a40` | Direct caller only at `0x0052e90b`; writes `+0x10c = 1` and invalidates. |
| destructor adjustors | `0x005025d4-0x005025ea` | two `0x0b` thunks | `0x001019d4` / `0x001019df` | Back up receiver by `0xa0` or `0xa4`, then jump to `0x00502d90`; vtable refs only. |
| scalar deleting destructor | `0x00502d90-0x00502dcb` | `0x3b` | `0x00102190` | Calls `Pane::~Pane()`, handles delete flags `1/4`, calls global delete wrapper or guard helper with object size `0x16c`. |

Confirmed padding: one `0xcc` byte at `0x005012af-0x005012b0`; six at `0x0050135a-0x00501360`; six at `0x0050158a-0x00501590`; fourteen at `0x00501612-0x00501620`; fifteen at `0x00501631-0x00501640`; fifteen at `0x00501651-0x00501660`; and five at `0x00502dcb-0x00502dd0`.

## Ownership And Rejected Alternatives

- Accepted owner/emitter: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md). It owns the old create-user appearance-control classes, including the hair selector, face selector, preview pane, and color lists.
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) / [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) are direct callers and coordinators, but they do not own this reusable selector class.
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) remains an aggregate support range, not a precise source owner for formal method bodies.
- Rejected alternatives: no-owner/non-emitting classification is wrong for the constructor, mouse handler, paint handler, selection helper, and gender-bank helpers; raw scalar deleting destructor C++ is wrong because `0x00502d90` is compiler wrapper glue; assigning `0x00501620`/`0x00501640` to [UID:0000FR][UserShapeSelectControlPane](by-class/UserShapeSelectControlPane.md) is stale because current callers use old-dialog control id `6` and write hair selector `+0x10c`.

## Historical Source-Quality Caveats

- Exact original source file remains `UserCreateAppearanceControls.cpp` versus a private section inside `CreateUserDialogPane.cpp`; the current project owner/emitter remains [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).
- Exact event type and event-code enum names are still inherited-event-system work, but the offsets and press/release behavior are strong enough for declaration-level C++.
- Exact coordinate field names remain pending; the raw select helper proves which argument divides by `58` and which divides by `82`.
- The `+0x108` byte is only constructor-cleared in checked evidence and should stay reserved/unknown.
- Exact render helper API names/types for `OnPaintFrame` should be synchronized with the EPF/NewHumanImageLib/PaletteLib/Surface documentation before final method-body C++ is emitted.

## Evidence Notes

- IDA confirms all active method starts.
- `xrefs_to 0x00501150` reports construction from `CreateUserDialogPane::CreateUserDialogPane`.
- Wave2 memory-report notes also restored `0x00501590` as the real `SelectHairAtPoint` method after retiring a stale helper-class projection.
- IDA confirms `0x005025d4` and `0x005025df` as real 0xb adjustor thunks; `0x005025df` is a secondary `this - 41` thunk currently marked as missing code in disabled generated output.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x00502d90` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-06-19 B005 source-quality recheck resolves the destructor-specific C++ policy: the deleting-destructor target is compiler wrapper evidence for an implicit/defaulted ordinary destructor, not a hand-authored source body. `0x00544580` is ordinary `Pane::~Pane()` and `0x004f4ac0` is the MemoryMan-backed global `operator delete` wrapper.
- 2026-06-21 supplied the historical sibling lead. Current exact evidence retains `0x00501620`/`0x00501640` as hair mode setters and separately assigns face mode setters `0x00501b00`/`0x00501b20`; none belongs to UserShapeSelectControlPane.

## Cross-References

- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000FK][UserHairColorSelectListPane](by-class/UserHairColorSelectListPane.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md)

## 2026-07-14 UID0001A6 Implemented Source Contract

- Current metadata: `91/93`, owner/emitter UID0000OX, position 20, reconstructable true.
- The exact managed declaration is in formal H and closes with `};`; formal CPP contains `[[CHILDREN]]`, so only registered method children emit out-of-line definitions.
- Source route is dedicated `NexusTK/login/UserCreateAppearanceControls.h/.cpp` through [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).

| Exact child | Source method | Behavior |
| --- | --- | --- |
| [UID:0004OG][0x00501150-0x005012af.UserHairSelectControlPaneConstructor](by-memory/0x00501150-0x005012af.UserHairSelectControlPaneConstructor.md) | `constructor` | 0x16c state, normalized bounds, two exact 18-entry frame banks |
| [UID:0004OH][0x005012b0-0x0050135a.UserHairSelectControlPaneOnMouseEvent](by-memory/0x005012b0-0x0050135a.UserHairSelectControlPaneOnMouseEvent.md) | `OnMouseEvent` | kind 0 movement while tracking; kind 1 down-hit selection |
| [UID:0004OI][0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame](by-memory/0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame.md) | `OnPaintFrame` | 9x2 grid, category 5, slot-14 palette, USERPART resources |
| [UID:0004OJ][0x00501590-0x00501612.UserHairSelectControlPaneSelectHairAtPoint](by-memory/0x00501590-0x00501612.UserHairSelectControlPaneSelectHairAtPoint.md) | `SelectHairAtPoint` | 82x58 clamped row-major selection and invalidation |
| [UID:0004OK][0x00501620-0x00501631.UserHairSelectControlPaneSetMaleMode](by-memory/0x00501620-0x00501631.UserHairSelectControlPaneSetMaleMode.md) | `SetMaleMode` | write bank 0 and invalidate; live caller 0x0052e89b |
| [UID:0004OL][0x00501640-0x00501651.UserHairSelectControlPaneSetFemaleMode](by-memory/0x00501640-0x00501651.UserHairSelectControlPaneSetFemaleMode.md) | `SetFemaleMode` | write bank 1 and invalidate; live caller 0x0052e90b |

- Layout: Exact size 0x16c; selected +0x10a, gender +0x10c, color +0x10d, tracking +0x10e, frame banks +0x110/+0x134, columns +0x158, bounds +0x15c; 9x2 cells at 82x58.
- Liveness/ABI: Constructor caller 0x0052e0af; paint vtable 0x0061ddc0; event vtable 0x0061dde8; complete-object/EventHandler/TimerHandler ABI remains compiler-generated.
- Shared type/table support is [UID:0004P6][UserCreateAppearanceControlLayouts](by-type/by-struct/UserCreateAppearanceControlLayouts.md) and [UID:0004P7][0x0061e570-0x0061e5b0.UserCreateAppearanceColorValueTable](by-memory/0x0061e570-0x0061e5b0.UserCreateAppearanceColorValueTable.md).
- [UID:0004P8][UserCreateAppearanceControlVtables](by-type/by-vtable/UserCreateAppearanceControlVtables.md) and [UID:0004P9][0x0061dd78-0x0061e0ec.UserCreateAppearanceControlVtableData](by-memory/0x0061dd78-0x0061e0ec.UserCreateAppearanceControlVtableData.md) remain compiler-generated/non-emitting; normal virtual destructors regenerate deleting wrappers and adjustors.
- Exact addresses, bytes, fields, calls, branches, constants, and side effects are binary facts. Source spellings/file split are bounded inference because no authentic source/PDB survives.
- Rejected: broad-parent output, dialog ownership, renderer/palette ownership, raw offset/decompiler C++, explicit vptr/cookie/adjustor source, guards absent from the binary, and duplicate aggregate/class/child emission.
- Historical notes below remain provenance snapshots; this implemented contract supersedes stale blank-C++, missing-child, old-name, inline-only, and unresolved-placement assertions.

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, mouse handler, paint method, hair-selection helper, adjustor thunks, and scalar deleting destructor at `0x00501150`, `0x005012b0`, `0x00501360`, `0x00501590`, `0x005025d4`, `0x005025df`, and `0x00502d90`; this page and parent [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) both met the then-current documentation gate. Formal C++ remains blank pending a dedicated source-quality pass for the hair selector class.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: scored from the constructor/mouse/paint/select method map, create-user owner xrefs, restored `SelectHairAtPoint` evidence, and adjustor-thunk/destructor references.
- 2026-06-21 B007 support correction:
  - Score unchanged.
  - Summary/evidence: added `SetMaleMode`/`SetFemaleMode` at `0x00501620`/`0x00501640` as hair-selector gender-bank helpers based on old-dialog control id `6` call sites, replacing stale shape-selector wording in the aggregate/file docs.
- 2026-06-21 B009 Rule 26 source-quality incorporation:
  - Before: `84/88`, blank formal C++, broad method notes, unresolved style-helper naming, and only partial caller/table/detail coverage.
  - After: `87/90`, owner/emitter unchanged [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md), declaration-level C++ populated, and method bodies deliberately deferred to exact child pages or a reviewed method aggregate.
  - Summary/evidence: incorporated B009's raw PE/exported-function source-quality recheck: exact method extents and padding, `0x16c` allocation, constructor signature, primary/secondary/tertiary vtable roles, `+0x108`, `+0x10a`, `+0x10c`, `+0x10d`, `+0x10e`, `+0x110/+0x134`, `+0x158`, and `+0x15c` field map, 9x2 82x58 grid constants, decoded two-bank 18-entry hair-part table, mouse capture and coordinate-clamp behavior, old-dialog control id `6` gender/color routes, preview table-index formula, generated destructor/thunk no-code policy, stale shape-helper rejection, and remaining below-final-source caveats.
