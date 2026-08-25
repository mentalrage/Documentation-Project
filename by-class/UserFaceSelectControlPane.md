*** UID:0000FJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class UserFaceSelectControlPane : public ControlPane
{
public:
    enum { kColumns = 6, kRows = 2, kCellWidth = 82, kCellHeight = 58 };

    UserFaceSelectControlPane(short selectedFace,
                              unsigned char faceColor,
                              unsigned char gender,
                              const RectBounds *bounds,
                              unsigned char controlFlags);
    virtual ~UserFaceSelectControlPane() {}

    virtual bool OnMouseEvent(const MouseEvent *event);
    virtual void OnPaintFrame();

    void SelectFaceAtPoint(int mouseY, int mouseX);
    void SetMaleMode();
    void SetFemaleMode();
    void SetFaceColorIndex(unsigned char color) { m_faceColor = color; }
    short GetSelectedFace() const { return m_selectedFace; }
    unsigned short GetSelectedFacePartId() const
    {
        return m_facePartIds[m_gender][m_selectedFace];
    }

private:
    unsigned char m_reservedState;
    short m_selectedFace;
    unsigned char m_gender;
    unsigned char m_faceColor;
    bool m_mouseTracking;
    unsigned short m_facePartIds[2][12];
    unsigned char m_columnCount;
    RectBounds m_hitBounds;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserFaceSelectControlPane

## Status

- Confidence: very strong for class identity, source-bearing method inventory, field map, create-user caller routes, resource dependencies, and declaration-level C++; medium-high for exact event typedef names and final Surface callback typedefs.
- Likely source file: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Current recovered file lead: `source-3/simroot_v2/class_UserFaceSelectControlPane.cpp`; use local IDA exports and the linked by-* support docs as the current authority.
- Address range: [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- Autogen handling: this class emits its complete declaration from formal H at source position `30` through [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md); formal CPP retains only `[[CHILDREN]]` for exact method definitions. Scalar deleting destructor and adjustor-thunk pages remain compiler-generated support regenerated from the inline empty virtual destructor declaration.

## Class Purpose

`UserFaceSelectControlPane` is the face thumbnail selector used by the older create-user dialog. It draws a two-row by six-column grid of face parts, handles mouse selection, stores the selected face slot, and exposes the face-part id and color state used by [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) when refreshing the preview or building the create-character request.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00501660-0x00501783` | `UserFaceSelectControlPane::UserFaceSelectControlPane(short selectedFace, unsigned char faceColor, unsigned char gender, const RectBounds *bounds, unsigned char controlFlag)`. The constructor calls `ControlPane::ControlPane(this, 8, bounds)`, installs primary/EventHandler/TimerHandler vtables, stores selector state, normalizes a local hit rect, and seeds two 12-entry face-id banks. |
| `OnMouseEvent` | `0x00501790-0x0050183a` | Secondary/EventHandler vtable entry at `0x0061de8c`; the receiver is the EventHandler subobject (`object + 0xa0`). It hit-tests the local grid, tracks press/release state, calls `SelectFaceAtPoint`, and falls back to the inherited mouse handler for non-captured non-grid events. |
| `OnPaintFrame` | `0x00501840-0x00501a6a` | Primary vtable entry at `0x0061de64`; draws the 6x2 face thumbnail grid through NewHumanImageLib, PaletteLib, and Surface callbacks, then draws the `USERPART.EPF`/`USERPART.PAL` selection frame over the selected cell. |
| `SelectFaceAtPoint` | `0x00501a70-0x00501af2` | `void SelectFaceAtPoint(int mouseY, int mouseX)`. Divides by 82x58 cell dimensions, clamps column to `m_columnCount - 1`, clamps row to `1`, writes `m_selectedFace = col + row * m_columnCount`, and invalidates the pane bounds. |
| destructor/thunks | [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md), `0x00502d50` | Adjustor thunks are ignored compiler support; `0x00502d50` is the scalar deleting destructor wrapper for implicit/defaulted source destructor `UserFaceSelectControlPane::~UserFaceSelectControlPane()`. No derived cleanup body is proven; base `Pane::~Pane()`, delete flags, and `operator delete` are compiler/base output. |

## Field Map

| Offset | Type | Recommended name | Evidence |
| --- | --- | --- | --- |
| `+0x108` | `unsigned char` | `m_reserved108` | Constructor clears this byte, and checked face-selector methods do not read it. No semantic name is safe yet. |
| `+0x10a` | `short` | `m_selectedFace` | Constructor seeds it from `rand() % 10`; `SelectFaceAtPoint` writes `col + row * m_columnCount`; paint and preview routes read it. |
| `+0x10c` | `unsigned char` | `m_gender` | Constructor receives `0`; `CreateUserDialogPane::SelectMale`/`SelectFemale` write `0`/`1` on control id `7`; paint uses it as the face-id bank selector. `m_faceSet` remains only a weaker descriptive fallback. |
| `+0x10d` | `unsigned char` | `m_faceColor` | Constructor seeds `1`; `CreateUserDialogPane::SetFaceColorIndex` writes this byte on control id `7`; paint uses `m_faceColor >> 5` for the face-palette slot. |
| `+0x10e` | `bool` | `m_mouseDownInGrid` | Constructor clears; `OnMouseEvent` sets it on mouse-down inside the grid, clears it on outside press, and requires it for release-time reselection. |
| `+0x110` | `uint16_t[12]` | `m_facePartIds[0]` | Constructor writes face ids `0..11` as packed dwords `0x00010000` through `0x000b000a`. These are face part ids, not coordinate pairs. |
| `+0x128` | `uint16_t[12]` | `m_facePartIds[1]` | Constructor writes a second identical bank; `m_gender` selects the bank through a 12-entry stride. |
| `+0x140` | `unsigned char` | `m_columnCount` | Constructor writes `6`; paint and selection use it for grid column count and row stride. |
| `+0x144` | `RectBounds` | `m_localHitRect` | Constructor copies the input bounds, subtracts left/top from right/bottom, and zeros left/top. `OnMouseEvent` uses this local rectangle from the EventHandler view. |

## Grid, Mouse, And Selection Behavior

- Source constants are `kFaceColumns = 6`, `kFaceRows = 2`, `kFaceCellWidth = 82`, `kFaceCellHeight = 58`, and `kFaceSlotsPerGender = 12`.
- No `-1` selected-face sentinel is used here. The constructor randomizes only slots `0..9`, but the mouse path can select all twelve visible slots.
- `OnMouseEvent` uses event code `1` as press/down and `0` as release/up. Current evidence maps `event+8` to mouse Y and `event+0xc` to mouse X for row/column math.
- A down event inside `m_localHitRect` sets `m_mouseDownInGrid = true`, selects immediately, invalidates, and returns true. A release inside the grid selects only if the prior down was captured. A down event outside the grid clears capture and still returns true; other outside events fall back to the inherited EventHandler route.

## Paint And Resource Dependencies

- `OnPaintFrame` asks the Surface callback table slot currently documented through `dword_69B3FC` to prepare/present the pane bounds, then iterates two rows by six columns.
- For each cell it builds a `RectBounds(left, top, left + 82, top + 58)`, looks up `m_facePartIds[m_gender][row * m_columnCount + col]`, calls [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) / [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md) `LoadPartFrameDrawRecord` with part category `2`, centers the returned frame bounds, shifts Y by `60`, selects [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md) slot family `13` with `m_faceColor >> 5`, and draws through the Surface render callback slot currently documented through `dword_69B3E8`.
- The selection frame uses `USERPART.EPF` tile index `0` via [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `ResourceLayoutTableLookupLayoutEntry`, centers it over the selected cell, and draws it with `USERPART.PAL` through the shared tile blit helper. The apparent `off_61E3C0` and `off_61E420` pointer labels are UTF-16 string fragments: the leading dword bytes encode `U\0S\0`, followed by `ERPART.EPF` or `ERPART.PAL`.

## Dialog Caller Semantics

- `CreateUserDialogPane::CreateUserDialogPane` allocates `0x154` bytes for this selector, builds bounds `{170,545,676,662}`, and calls the constructor with `selectedFace = rand() % 10`, `faceColor = 1`, `gender = 0`, the bounds pointer, and `controlFlag = 0`.
- In the old create-user dialog, control id `6` is [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) and control id `7` is this face selector.
- `CreateUserDialogPane::SelectMale` / `SelectFemale` write dialog `m_isFemale`, update gender button state, call the hair selector gender-bank helper on control id `6`, directly write `m_gender` at face selector `+0x10c` on control id `7`, and invalidate the face selector. The face selector does not have an out-of-line gender setter in the executable even though `SetGender` is source-plausible declaration-level guidance.
- `CreateUserDialogPane::SetFaceColorIndex` looks up control id `7`, writes `m_faceColor` at `+0x10d`, invalidates this selector, and refreshes the preview.
- Preview setup reads `m_facePartIds[m_gender][m_selectedFace]` and `m_faceColor`, while the dialog passes its own `m_isFemale` byte into [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md).
- B009's hair-selector companion remains distinct. This face selector now has its own exact out-of-line `SetMaleMode` and `SetFemaleMode` children at `0x00501b00` and `0x00501b20`, with live callers `0x0052e8b2` and `0x0052e922`; do not collapse the two layouts or assign hair helpers `0x00501620`/`0x00501640` to this class.

## Ownership And Source Placement

- Accepted owner/emitter: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md). It owns the old create-user appearance-control classes, including the hair selector, face selector, preview pane, and color lists.
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) / [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) are direct callers and coordinators, but they do not own this reusable selector class.
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) remains an aggregate support range, not a precise source owner for formal method bodies.
- Rejected alternatives: no-owner/non-emitting classification is wrong for the constructor, mouse handler, paint handler, and selection helper; raw scalar deleting destructor C++ is wrong because `0x00502d50` is compiler wrapper glue; the old "packed face-coordinate table" label is wrong because the table holds face part ids, not grid coordinates.

## Historical Source-Quality Caveats

- Exact original spelling for the `+0x10c` bank field could be `m_gender`, `m_sex`, or `m_faceSet`; current docs prefer `m_gender` because the old dialog writes it from male/female selection and project docs use "gender".
- Exact `MouseEvent` type and event-code enum names are still inherited-event-system work, but the offsets and press/release semantics are strong enough for behavior documentation and draft C++.
- The inherited `+0xff` byte written from the constructor's `controlFlag` argument should not be named as a face-specific field.
- Final typedef names for Surface callback slots behind `dword_69B3E8` and `dword_69B3FC` remain [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) work.

## Evidence Notes

- IDA confirms all active method starts.
- `xrefs_to 0x00501660` reports construction from `CreateUserDialogPane::CreateUserDialogPane`.
- Wave2 memory-report notes restored `0x00501a70` as the real `SelectFaceAtPoint` method after retiring a stale helper-class projection.
- IDA confirms `0x005025be` and `0x005025c9` as real 0xb adjustor thunks; `0x005025c9` is a secondary `this - 41` thunk currently marked as missing code in disabled generated output.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x00502d50` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-06-19 B005 source-quality recheck resolves the destructor-specific C++ policy: the deleting-destructor target is compiler wrapper evidence for an implicit/defaulted ordinary destructor, not a hand-authored source body. `0x00544580` is ordinary `Pane::~Pane()` and `0x004f4ac0` is the MemoryMan-backed global `operator delete` wrapper.
- 2026-06-19 B007 source-quality recheck resolves the class above the current code-entry gate and supplies the declaration-level C++ now emitted here. It corrects the face-id table model, field names, old-dialog control id `7` routes, `USERPART.EPF`/`USERPART.PAL` literal decoding, and the source-placement split between this selector class, the appearance-control file owner, the old dialog coordinator, and compiler-generated destructor/thunk support.

## Cross-References

- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000FI][UserFaceColorSelectListPane](by-class/UserFaceColorSelectListPane.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md)

## 2026-07-14 UID0001A6 Implemented Source Contract

- Current metadata: `91/93`, owner/emitter UID0000OX, position 30, reconstructable true.
- The exact managed declaration is in formal H and closes with `};`; formal CPP contains `[[CHILDREN]]`, so only registered method children emit out-of-line definitions.
- Source route is dedicated `NexusTK/login/UserCreateAppearanceControls.h/.cpp` through [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).

| Exact child | Source method | Behavior |
| --- | --- | --- |
| [UID:0004OM][0x00501660-0x00501783.UserFaceSelectControlPaneConstructor](by-memory/0x00501660-0x00501783.UserFaceSelectControlPaneConstructor.md) | `constructor` | 0x154 state, normalized bounds, two exact 0..11 banks |
| [UID:0004ON][0x00501790-0x0050183a.UserFaceSelectControlPaneOnMouseEvent](by-memory/0x00501790-0x0050183a.UserFaceSelectControlPaneOnMouseEvent.md) | `OnMouseEvent` | kind 0 movement while tracking; kind 1 down-hit selection |
| [UID:0004OO][0x00501840-0x00501a6a.UserFaceSelectControlPaneOnPaintFrame](by-memory/0x00501840-0x00501a6a.UserFaceSelectControlPaneOnPaintFrame.md) | `OnPaintFrame` | 6x2 grid, category 2, slot-13 palette, USERPART resources |
| [UID:0004OP][0x00501a70-0x00501af2.UserFaceSelectControlPaneSelectFaceAtPoint](by-memory/0x00501a70-0x00501af2.UserFaceSelectControlPaneSelectFaceAtPoint.md) | `SelectFaceAtPoint` | 82x58 clamped row-major selection and invalidation |
| [UID:0004OQ][0x00501b00-0x00501b11.UserFaceSelectControlPaneSetMaleMode](by-memory/0x00501b00-0x00501b11.UserFaceSelectControlPaneSetMaleMode.md) | `SetMaleMode` | write bank 0 and invalidate; live caller 0x0052e8b2 |
| [UID:0004OR][0x00501b20-0x00501b31.UserFaceSelectControlPaneSetFemaleMode](by-memory/0x00501b20-0x00501b31.UserFaceSelectControlPaneSetFemaleMode.md) | `SetFemaleMode` | write bank 1 and invalidate; live caller 0x0052e922 |

- Layout: Exact size 0x154; selected +0x10a, gender +0x10c, color +0x10d, tracking +0x10e, face banks +0x110/+0x128, columns +0x140, bounds +0x144; 6x2 cells at 82x58.
- Liveness/ABI: Constructor caller 0x0052e114; paint vtable 0x0061de64; event vtable 0x0061de8c. The historical inline-only face-gender claim is superseded by the two exact live bodies.
- Shared type/table support is [UID:0004P6][UserCreateAppearanceControlLayouts](by-type/by-struct/UserCreateAppearanceControlLayouts.md) and [UID:0004P7][0x0061e570-0x0061e5b0.UserCreateAppearanceColorValueTable](by-memory/0x0061e570-0x0061e5b0.UserCreateAppearanceColorValueTable.md).
- [UID:0004P8][UserCreateAppearanceControlVtables](by-type/by-vtable/UserCreateAppearanceControlVtables.md) and [UID:0004P9][0x0061dd78-0x0061e0ec.UserCreateAppearanceControlVtableData](by-memory/0x0061dd78-0x0061e0ec.UserCreateAppearanceControlVtableData.md) remain compiler-generated/non-emitting; normal virtual destructors regenerate deleting wrappers and adjustors.
- Exact addresses, bytes, fields, calls, branches, constants, and side effects are binary facts. Source spellings/file split are bounded inference because no authentic source/PDB survives.
- Rejected: broad-parent output, dialog ownership, renderer/palette ownership, raw offset/decompiler C++, explicit vptr/cookie/adjustor source, guards absent from the binary, and duplicate aggregate/class/child emission.
- Historical notes below remain provenance snapshots; this implemented contract supersedes stale blank-C++, missing-child, old-name, inline-only, and unresolved-placement assertions.

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, mouse handler, paint method, face-selection helper, adjustor thunks, and scalar deleting destructor at `0x00501660`, `0x00501790`, `0x00501840`, `0x00501a70`, `0x005025be`, `0x005025c9`, and `0x00502d50`; this page and parent [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) both met the then-current documentation gate. Formal C++ was still blank at that time; the 2026-06-21 B007 pass supersedes this with declaration-level C++ under the current `85/85` code-entry policy.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: scored from the constructor/mouse/paint/select method map, create-user owner xrefs, restored `SelectFaceAtPoint` evidence, and adjustor-thunk/destructor references.
- 2026-06-21 B007 Rule 26 source-quality incorporation:
  - Before: `84/88`, blank formal C++, stale below-95 code wording, broad method notes, "packed face-coordinate" wording, and missing field/resource/caller accounting.
  - After: `88/90`, owner/emitter unchanged [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md), declaration-level C++ populated, and method bodies deliberately deferred to exact child pages or a reviewed method aggregate.
  - Summary/evidence: incorporated B007's full report-level details: constructor signature and `0x154` allocation; primary/EventHandler/TimerHandler vtable views; `+0x108`, `+0x10a`, `+0x10c`, `+0x10d`, `+0x10e`, `+0x110`, `+0x128`, `+0x140`, and `+0x144` field map; 6x2 grid constants using 82x58 cells; press/release mouse semantics; face-id bank interpretation; `CreateUserDialogPane` control id `7` gender/color/preview routes; `USERPART.EPF`/`USERPART.PAL` selection-frame decoding; NewHumanImageLib, PaletteLib, g_pEPFLib, and Surface callback dependencies; destructor/thunk no-code proof; rejected owner/helper/table interpretations; and remaining exact-name caveats.
- 2026-06-21 B009 hair-selector companion sync:
  - Score unchanged.
  - Summary/evidence: added the companion selector distinction from B009: `0x00501620`/`0x00501640` are hair selector helpers for old-dialog control id `6`, while this face selector uses direct old-dialog writes to `+0x10c`; the hair selector has a 9x2 18-entry-per-bank table, while this face selector keeps the documented 6x2 12-entry-per-bank table.
