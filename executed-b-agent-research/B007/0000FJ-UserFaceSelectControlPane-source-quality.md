** TARGET-REPORT-UID:0000FJ **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B007 Source-Quality Report: [UID:0000FJ] UserFaceSelectControlPane

Assignment id: `B007-goal2-user-face-select-control-pane-source-quality-0000FJ-20260619`

Status: FINISHED report-only. No target/support by-* documentation was edited. `by-memory/-coverage-report.md` was not edited.

## Target And Report Paths

- Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\UserFaceSelectControlPane.md`
- Required report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B007\research\0000FJ-UserFaceSelectControlPane-source-quality.md`
- Main support aggregate: `source-3/project-documentation/by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md`
- Source-file parent: `source-3/project-documentation/by-file/UserCreateAppearanceControls.md`

## Executive Recommendation

Keep [UID:0000FJ] `UserFaceSelectControlPane` source-bearing, reconstructable, and emitted through [UID:0000OX] `UserCreateAppearanceControls`. Raise the target from `84/88` to `88/90`; keep `CANONICAL_OWNER:0000OX`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OX`.

The class is not compiler glue and should not stay blank solely because of the stale `95/95` wording. The scalar deleting destructor and adjustor thunks remain no-code compiler support, but the constructor, `OnMouseEvent`, `OnPaintFrame`, and `SelectFaceAtPoint` are source-authored UI control methods. The class page is ready for declaration-level C++. Method-body C++ is also draftable, but exact method bodies should ideally live in future exact by-memory child pages or a reviewed method aggregate, not as overbroad bodies in the class page.

Main correction found during this pass: the current support aggregate mislabels `0x00501620` and `0x00501640` as `UserShapeSelectControlPane` helpers. Current decompilation and dialog call sites support them as `UserHairSelectControlPane::SetMaleMode` and `UserHairSelectControlPane::SetFemaleMode`; the face selector equivalent is inlined in `CreateUserDialogPane::SelectMale/SelectFemale` by writing byte `+0x10c` on control id `7` and invalidating.

## Evidence Checked

- Read required instructions: `Supervisor.md`, `.codex/AGENTS.md`, `Agent-B007/goal.md`, plus `by-structure.md` and inference guidance.
- Target class doc: `by-class/UserFaceSelectControlPane.md`.
- Source parent and aggregate docs: `by-file/UserCreateAppearanceControls.md`, `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md`, `by-class/UserHairSelectControlPane.md`.
- Destructor/thunk support: `by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md`, `by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md`, and B005 executed destructor report.
- Dialog caller/coordinator docs: `by-file/CreateUserDialogs.md`, `by-file/CreateUserDialogPane.md`, `by-class/CreateUserDialogPane.md`, `by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md`.
- Render/resource support docs: `ControlPane`, `GrafPort`, `NewHumanImageLib`, `PaletteLib`, `g_pEPFLib`, `g_pNewHumanImageLib`, `g_pPaletteLib`, `SurfaceRenderCallbackTable`, and `ResourceLayoutTableLookupLayoutEntry`.
- Local IDA exports:
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c`
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
- Live IDA MCP attempt: POST to `http://127.0.0.1:13337/mcp` failed with connection refusal. This report therefore uses checked-in local IDA `.c/.lst` exports plus existing IDA-backed docs. No wave2/wave3 source output was used as authority.
- `int_convert.py` verified key constants: `0x154 == 340`, `0xa0 == 160`, `0xa4 == 164`, `0x10a == 266`, `0x10c == 268`, `0x10d == 269`, `0x10e == 270`, `0x110 == 272`, `0x128 == 296`, `0x140 == 320`, `0x144 == 324`, `0x52 == 82`, `0x3a == 58`, `0x1fc == 508`, `0x221 == 545`, `0x2a4 == 676`.

## Binary Findings

### Method Ranges And Source Names

| Address range | Recommended source name/signature | Evidence |
| --- | --- | --- |
| `0x00501660-0x00501783` | `UserFaceSelectControlPane::UserFaceSelectControlPane(short selectedFace, unsigned char faceColor, unsigned char gender, const RectBounds *bounds, unsigned char controlFlag)` | Constructor body calls `ControlPane::ControlPane(this, 8, bounds)`, installs three `UserFaceSelectControlPane` vtables, stores selector state, builds local hit rect, and seeds two face-id banks. |
| `0x00501790-0x0050183a` | `bool UserFaceSelectControlPane::OnMouseEvent(MouseEvent *event)` | Secondary/EventHandler vtable entry at `0x0061de8c`; receives `this` as `object + 0xa0`, checks `m_localHitRect`, tracks press/release, calls `SelectFaceAtPoint`. |
| `0x00501840-0x00501a6a` | `void UserFaceSelectControlPane::OnPaintFrame()` | Primary vtable entry at `0x0061de64`; draws the face grid, then draws the selected frame. |
| `0x00501a70-0x00501af2` | `void UserFaceSelectControlPane::SelectFaceAtPoint(int mouseY, int mouseX)` | Direct local call from `OnMouseEvent`; divides by cell size, clamps col/row, writes selected slot, invalidates. |

The existing method names are good. The exact constructor signature is inferred from stack order and call site: `selectedFace`, `faceColor`, `gender`, `bounds`, `controlFlag`. `controlFlag` writes inherited `ControlPane` byte `+0xff`, not a face-specific field; final source spelling remains open.

### Constructor And Fields

`CreateUserDialogPane::CreateUserDialogPane` allocates `0x154` bytes for the face selector, constructs bounds `{170,545,676,662}`, and calls:

```text
sub_501660(facePane, rand() % 10, 1, 0, &bounds, 0)
```

`0x154` / 340 is the class allocation size for the face selector. The class has three vtable views: primary at object `+0x0`, secondary/EventHandler at `+0xa0`, and tertiary/TimerHandler at `+0xa4`. RTTI lists 7 base-class entries: `UserFaceSelectControlPane`, `ControlPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler`.

Recommended field map:

| Offset | Type | Recommended name | Evidence |
| --- | --- | --- | --- |
| `+0x108` | `unsigned char` | `m_reserved108` or leave unnamed | Constructor writes zero; no face-method read found. Do not invent a semantic name. |
| `+0x10a` | `short` | `m_selectedFace` or `m_selectedFaceIndex` | Constructor seeds from `rand() % 10`; `SelectFaceAtPoint` writes `col + row * columns`; paint and preview read it. |
| `+0x10c` | `unsigned char` | `m_gender` | Constructor passes `0`; `CreateUserDialogPane::SelectMale/SelectFemale` writes `0/1` on control id `7`; paint uses it as face-id table bank selector. `m_faceSet` is a weaker fallback name. |
| `+0x10d` | `unsigned char` | `m_faceColor` or `m_faceColorIndex` | Constructor seeds `1`; `CreateUserDialogPane::SetFaceColorIndex` writes this byte on control id `7`; paint uses `m_faceColor >> 5` for palette slot. |
| `+0x10e` | `bool` | `m_mouseDownInGrid` | Constructor clears; `OnMouseEvent` sets on mouse-down inside hit rect and clears on outside press. |
| `+0x110` | `uint16_t[12]` | `m_facePartIds[0]` | Constructor writes face ids `0..11` as packed dwords `0x00010000` through `0x000b000a`. |
| `+0x128` | `uint16_t[12]` | `m_facePartIds[1]` | Constructor writes a second bank identical to bank 0. `m_gender` selects `12 * bank`. |
| `+0x140` | `unsigned char` | `m_columnCount` | Constructor writes `6`; paint and selection use it as the column count. |
| `+0x144` | `RectBounds` | `m_localHitRect` or `m_localBounds` | Constructor copies input rect, subtracts left/top from right/bottom, then zeros left/top. Mouse hit-test uses this local rect from the EventHandler view. |

The current wording "packed face-coordinate tables" should be changed to "packed face-id table" or "face part id banks". The values are resource part/frame ids, not grid coordinates.

### Grid Constants And Selection

The source constants should be documented as:

```text
kFaceColumns = 6
kFaceRows = 2
kFaceCellWidth = 82
kFaceCellHeight = 58
kVisibleFaceSlots = 12
```

`SelectFaceAtPoint(int mouseY, int mouseX)` computes:

- `col = max(0, mouseX / 82)`, then clamps to `m_columnCount - 1`.
- `row = max(0, mouseY / 58)`, then clamps to `1`.
- `m_selectedFace = col + row * m_columnCount`.
- It invalidates using the primary vtable slot `+0x20` and `this + 0x44` bounds.

No `-1` sentinel is used in this class. The constructor randomizes only `0..9`, even though the grid supports `0..11`; mouse selection can select all 12 visible slots.

### Mouse Behavior

`OnMouseEvent` is entered through the EventHandler subobject (`this == object + 0xa0`). It copies `object + 0x144` as the local hit rect and uses the event coordinates at `event+8` and `event+0xc`. Current evidence supports:

- `event+4 == 1`: press/down.
- `event+4 == 0`: release/up.
- `event+8`: mouse Y for row math.
- `event+0xc`: mouse X for column math.

Inside hit rect:

- Down sets `m_mouseDownInGrid = true`, selects immediately, returns true.
- Up/release selects only if `m_mouseDownInGrid` is true, returns true.

Outside hit rect:

- A down event clears `m_mouseDownInGrid` and still returns true.
- Other events fall back to `sub_544DB0(event)`, likely inherited `EventHandler::OnMouseEvent`.

### Paint Behavior

`OnPaintFrame` clears/prepares draw state, asks the Surface callback table slot at `dword_69B3FC` to prepare/present the pane bounds, then draws two rows of six face thumbnails. For each cell:

- Builds cell rect with `InitRectBounds(left, top, left + 82, top + 58)`.
- Looks up the face part id from `m_facePartIds[m_gender][row * m_columnCount + col]`.
- Calls `NewHumanImageLib::LoadPartFrameDrawRecord(g_pNewHumanImageLib, 2, facePartId, 2, 0, frameContext)`. Existing `NewHumanImageLib` docs name `0x004e0d70` as `LoadPartFrameDrawRecord`; the `2` part category is the face category in this context.
- Centers the returned frame bounds inside the cell and shifts Y by `60`.
- Calls `PaletteLib::GetSlotPalette(g_pPaletteLib, 13, 0, m_faceColor >> 5)`. Slot `13` is inferred as the face-palette family from this call; keep it descriptive until PaletteLib slot names are finalized.
- Calls Surface render callback slot `dword_69B3E8` to draw the frame.

After thumbnails are drawn:

- It loads selection-frame tile index `0` from `USERPART.EPF` through `g_pEPFLib` / `ResourceLayoutTableLookupLayoutEntry`.
- It centers that frame over the selected cell.
- It draws with `USERPART.PAL` through the shared tile blit helper (`sub_4B9980` in local exports).

The resource literal is a source-quality correction. IDA shows `off_61E3C0 dd offset byte_530055` followed by `ERPART.EPF`; interpreted as UTF-16 data this is `USERPART.EPF` because the dword bytes are `U\0S\0`. Likewise `off_61E420` plus `ERPART.PAL` is `USERPART.PAL`.

### Dialog Caller Semantics

Relevant `CreateUserDialogPane` control ids:

- Control id `6`: `UserHairSelectControlPane`.
- Control id `7`: `UserFaceSelectControlPane`.

`CreateUserDialogPane::SelectMale` (`0x0052e850`) sets dialog gender byte `+633` to `0`, updates gender button states, calls the hair selector male-bank helper on control id `6`, writes face selector byte `+0x10c = 0` on control id `7`, and invalidates the face selector.

`CreateUserDialogPane::SelectFemale` (`0x0052e8c0`) mirrors this with `+633 = 1`, hair female-bank helper, and face selector byte `+0x10c = 1`.

`CreateUserDialogPane::SetFaceColorIndex` (`0x0052e950`) looks up control id `7` and writes byte `+0x10d`.

The preview setup reads the face selector as:

```text
facePartId = faceSelector->m_facePartIds[faceSelector->m_gender][faceSelector->m_selectedFace]
faceColor  = faceSelector->m_faceColor
```

and passes the dialog gender byte into `UserCreatePreviewControlPane`.

## Destructor, Thunks, And Generated Names

`0x00502d50` is not a source-authored face destructor body. It is the MSVC scalar deleting destructor wrapper for `UserFaceSelectControlPane`, with vtable/thunk-only reachability. It calls `Pane::~Pane()` at `0x00544580`, uses guard/delete helper behavior, and conditionally calls the MemoryMan-backed global `operator delete` wrapper at `0x004f4ac0`. No derived cleanup is present.

The adjustor thunks at `0x005025be` and `0x005025c9` are compiler-generated wrappers for the secondary/tertiary vtable views. They adjust `this` by `-0xa0` and `-0xa4`, then forward to `0x00502d50`. Keep them no-code/ignored and do not emit raw thunk C++.

Source-facing destructor recommendation: `virtual ~UserFaceSelectControlPane() {}` only if an explicit class declaration needs the destructor for readability. An implicit/defaulted destructor is equally plausible. Do not hand-write scalar deleting destructor code.

## Ownership And Source Placement Ranking

1. [UID:0000OX] `UserCreateAppearanceControls`: accepted owner/emitter. It owns the old create-user appearance controls, including hair selector, face selector, preview, and color lists. The face class is a reusable control class with its own vtables and method bodies, not just an inline fragment of `CreateUserDialogPane`.
2. [UID:0000IK] `CreateUserDialogs` / `CreateUserDialogPane`: direct coordinator and caller, but not the best owner for the selector class. It constructs, updates gender/color fields, and reads selector state for preview/submission. Treat as caller/coordinator support.
3. [UID:0001A6] `UserCreateAppearanceSelectorControls`: good by-memory aggregate support, not a source owner. It spans multiple classes and should stay blank formal C++ unless split into exact child pages.
4. Selector aggregate as a separate source file: plausible physical grouping only as [UID:0000OX]; not a separate owner.
5. No-owner/non-emitting: rejected. Constructor/mouse/paint/select are source-authored class methods with direct vtables and caller routes.
6. Split child rows: not required before updating the class page with declaration-level C++. Exact method child pages would be useful for method-body C++ later, especially if the project wants full `OnPaintFrame` source rather than class declarations only.

## Heuristic And Inference Reanalysis

- `m_gender` versus `m_faceSet`: `m_gender` is the stronger source name. Direct evidence is `CreateUserDialogPane::SelectMale/SelectFemale` writing `0/1` into the face selector and the preview path passing the dialog gender. `m_faceSet` is only a descriptive fallback for the same bank selector.
- "Packed coordinate table": rejected. The constructor values are `uint16_t` face part ids, consumed by `NewHumanImageLib::LoadPartFrameDrawRecord`. Grid coordinates are immediate constants (`82`, `58`, row/column loops), not table data.
- `0x00501620` / `0x00501640` as shape helpers: rejected. Current call sites from `CreateUserDialogPane::SelectMale/SelectFemale` get control id `6`, and color setters prove control id `6` is the hair selector. These two helpers should be reclassified as hair selector male/female bank setters. Face selector bank changes are inlined in the dialog helper.
- `USERPART.EPF/PAL` resource literals: resolved. The apparent `off_61E3C0` / `off_61E420` pointer dwords are UTF-16 string fragments, not real pointer variables for source purposes.
- Method names: existing `OnMouseEvent`, `OnPaintFrame`, and `SelectFaceAtPoint` are source-quality. The constructor should be documented with argument semantics instead of raw `sub_501660`.
- Helper/global names: use `ControlPane::ControlPane`, `InitRectBounds`, `PointInRect`, `ResourceLayoutTableLookupLayoutEntry`, `NewHumanImageLib::LoadPartFrameDrawRecord`, `PaletteLib::GetSlotPalette`, `g_pEPFLib`, `g_pNewHumanImageLib`, `g_pPaletteLib`, and Surface render callback slots. Keep callback slot names descriptive until `SurfaceRenderCallbackTable` finalizes typedef names.
- Original source file split: still not symbol-proven. Evidence favors the current practical split `UserCreateAppearanceControls.cpp`; a private section inside `CreateUserDialogPane.cpp` remains plausible but lower-ranked because the selector classes have independent vtables and the source parent already groups all old appearance controls.

## Open Questions After Attempted Resolution

- Exact original spelling for the gender field: `m_gender`, `m_sex`, and `m_faceSet` are possible. Best recommendation is `m_gender` in docs; if matching older code style matters, `m_sex` may be a source-style alternative, but current project docs use "gender".
- Exact `MouseEvent` type and event-code names are not final from local exports. The offsets and `0/1` semantics are strong enough for behavior docs and draft C++; final enum names should follow the existing event system if/when it is audited.
- Byte `+0x108` is only cleared in the constructor in checked face code. No safe source-facing semantic name was found; leave as reserved/unknown in a layout table.
- Constructor byte at inherited `+0xff` is passed as `0` by the dialog and written after `ControlPane::ControlPane`; this is probably inherited control state. Do not name it as face-specific.
- Exact render callback typedefs for `dword_69B3E8` and `dword_69B3FC` remain Surface callback-table work. This does not block class declaration C++.

## First-Draft C++ Recommendation

Because this is a by-class page, the formal C++ should be declaration-level. Avoid putting full method bodies in the class page unless the supervisor explicitly chooses to use the class page as the emitter for these methods. Method-body snippets below are implementation guidance for future exact method pages.

Recommended declaration-level C++ for `by-class/UserFaceSelectControlPane.md`:

```cpp
class UserFaceSelectControlPane : public ControlPane {
public:
    enum {
        kFaceColumns = 6,
        kFaceRows = 2,
        kFaceCellWidth = 82,
        kFaceCellHeight = 58,
        kFaceSlotsPerGender = kFaceColumns * kFaceRows
    };

    UserFaceSelectControlPane(short selectedFace,
                              unsigned char faceColor,
                              unsigned char gender,
                              const RectBounds *bounds,
                              unsigned char controlFlag);
    virtual ~UserFaceSelectControlPane() {}

    virtual bool OnMouseEvent(MouseEvent *event);
    virtual void OnPaintFrame();

    void SelectFaceAtPoint(int mouseY, int mouseX);
    void SetGender(unsigned char gender);
    void SetFaceColorIndex(unsigned char faceColor);

    short GetSelectedFace() const { return m_selectedFace; }
    unsigned short GetSelectedFacePartId() const {
        return m_facePartIds[m_gender][m_selectedFace];
    }

private:
    unsigned char m_reserved108;
    short m_selectedFace;
    unsigned char m_gender;
    unsigned char m_faceColor;
    bool m_mouseDownInGrid;
    unsigned short m_facePartIds[2][kFaceSlotsPerGender];
    unsigned char m_columnCount;
    RectBounds m_localHitRect;
};
```

Method-body source sketch, for future exact child pages:

```cpp
void UserFaceSelectControlPane::SelectFaceAtPoint(int mouseY, int mouseX)
{
    int col = mouseX / kFaceCellWidth;
    if (col < 0)
        col = 0;
    if (col >= m_columnCount)
        col = m_columnCount - 1;

    int row = mouseY / kFaceCellHeight;
    if (row < 0)
        row = 0;
    if (row >= kFaceRows)
        row = kFaceRows - 1;

    m_selectedFace = static_cast<short>(col + row * m_columnCount);
    InvalidateRect(&m_bounds);
}
```

Constructor body direction:

- Call `ControlPane(8, bounds)`.
- Store inherited control flag byte if the base declaration exposes it.
- Store `m_selectedFace`, `m_gender`, `m_faceColor`, `m_columnCount = 6`, `m_mouseDownInGrid = false`.
- Normalize `bounds` into `m_localHitRect` by subtracting left/top from right/bottom and zeroing left/top.
- Initialize both face-id banks to `{0,1,2,3,4,5,6,7,8,9,10,11}`.

`SetGender` direction:

```cpp
void UserFaceSelectControlPane::SetGender(unsigned char gender)
{
    m_gender = gender;
    InvalidateRect(&m_bounds);
}
```

This setter is source-plausible even though the executable inlines the face write in `CreateUserDialogPane::SelectMale/SelectFemale`.

## Recommended Exact Target Doc Changes

For `by-class/UserFaceSelectControlPane.md`:

1. Change metadata:
   - `COMPLETION:88`
   - `CONFIDENCE:90`
   - owner/emitter/reconstructable unchanged.
2. Replace stale "No C++ was emitted because below 95/95" wording with current gate wording: the class is now above the current code-entry gate and should emit declaration-level C++; scalar deleting/destructor thunk pages remain no-code for target-specific compiler-glue reasons.
3. Replace "Current recovered file: simroot..." with a note that generated output is a lead only; local IDA exports and support docs are the ground truth.
4. Update method table with the signatures and behavior above.
5. Add field map table with offsets `+0x108`, `+0x10a`, `+0x10c`, `+0x10d`, `+0x10e`, `+0x110`, `+0x128`, `+0x140`, `+0x144`.
6. Add grid constants and dialog caller semantics:
   - control id `7` is the face selector;
   - `SelectMale/SelectFemale` write `m_gender`;
   - `SetFaceColorIndex` writes `m_faceColor`;
   - preview reads `m_facePartIds[m_gender][m_selectedFace]`.
7. Add paint dependency/resource notes:
   - `USERPART.EPF` / `USERPART.PAL`, not raw `off_61E3C0` / `off_61E420`;
   - `g_pNewHumanImageLib`, `g_pPaletteLib`, `g_pEPFLib`, Surface render callback slots.
8. Add declaration-level C++ block from this report.

## Recommended Support Doc Updates

For `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md`:

- Replace these two rows:

```markdown
| `0x00501620-0x00501631` | `UserShapeSelectControlPane` male-mode helper | Sets one shape-selector gender mode and refreshes. |
| `0x00501640-0x00501651` | `UserShapeSelectControlPane` female-mode helper | Sets the paired shape-selector gender mode and refreshes. |
```

with:

```markdown
| `0x00501620-0x00501631` | `UserHairSelectControlPane::SetMaleMode` | Sets the hair selector gender bank to `0` and refreshes; called by `CreateUserDialogPane::SelectMale` for control id `6`. |
| `0x00501640-0x00501651` | `UserHairSelectControlPane::SetFemaleMode` | Sets the hair selector gender bank to `1` and refreshes; called by `CreateUserDialogPane::SelectFemale` for control id `6`. |
```

- Update the face constructor/paint/select notes with the constants and field names in this report.
- Add the `USERPART.EPF` / `USERPART.PAL` literal decoding note.
- Recommended aggregate metadata if supervisor accepts the helper-placement correction and target details: raise to `86/90`; C++ remains blank because the aggregate spans multiple classes and exact child method pages are still absent.

For `by-file/UserCreateAppearanceControls.md`:

- In `Proposed Contents`, remove `helpers 0x00501620, 0x00501640` from `UserShapeSelectControlPane`.
- Add those helpers to the `UserHairSelectControlPane` row as gender-bank setters.
- Expand the `UserFaceSelectControlPane` row to mention `m_gender`, `m_faceColor`, `m_selectedFace`, the 6x2 face grid, and `USERPART.EPF/PAL` selection-frame rendering.
- Score can remain `87/85`; source split still caps confidence.

For `by-class/UserHairSelectControlPane.md`:

- Add method rows for:

```markdown
| `SetMaleMode` / `SetFemaleMode` | `0x00501620`, `0x00501640` | Updates the hair selector gender bank at `+0x10c` and invalidates; called by `CreateUserDialogPane::SelectMale/SelectFemale` on control id `6`. |
```

For `by-class/CreateUserDialogPane.md` and `by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md`:

- Expand `SelectMale` / `SelectFemale`:
  - control id `6`: calls hair selector `SetMaleMode` / `SetFemaleMode`;
  - control id `7`: directly writes face selector gender bank byte `+0x10c` and invalidates.
- Expand `SetFaceColorIndex`: control id `7`, byte `+0x10d`.
- Expand constructor notes: face selector allocation `0x154`, bounds `{170,545,676,662}`, constructor args `rand() % 10, 1, 0, bounds, 0`.

For `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` or the relevant read-only data child if split later:

- Add that `0x0061e3c0` is the UTF-16 literal `USERPART.EPF` encoded as dword `0x00530055` (`"US"`) plus `ERPART.EPF`.
- Add that `0x0061e420` is `USERPART.PAL` encoded the same way.

## Exact Coverage Replacement Text

Do not edit `by-memory/-coverage-report.md` directly. If supervisor accepts these changes, use the following exact rows.

`by-class/-coverage-report.md` replacement row:

```markdown
- [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md) : reconstructable : 88% : very strong : B007 source-quality pass resolves the face selector as source-bearing appearance-control code under [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md), with exact constructor/mouse/paint/select signatures, 6x2 grid constants using 82x58 cells, field map for selected face `+0x10a`, gender bank `+0x10c`, face color `+0x10d`, mouse capture `+0x10e`, face-id banks `+0x110/+0x128`, column count `+0x140`, and local hit rect `+0x144`, `CreateUserDialogPane` control-id 7 gender/color/preview routes, `USERPART.EPF`/`USERPART.PAL` selection-frame resources, NewHumanImageLib/PaletteLib/Surface callback dependencies, destructor/thunk no-code policy, and declaration-level C++ readiness.
```

`by-memory/-coverage-report.md` replacement row for [UID:0001A6] if aggregate metadata/support text is updated:

```markdown
        - [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) 0x00501150-0x00502383 | class method cluster | UserCreateAppearanceSelectorControls : reconstructable : 86% : very strong : B007 source-quality pass corrects `0x00501620`/`0x00501640` from stale `UserShapeSelectControlPane` helper wording to `UserHairSelectControlPane::SetMaleMode`/`SetFemaleMode`, confirms the `UserFaceSelectControlPane` constructor/mouse/paint/select signatures, 6x2 face-grid constants, selected-face/gender/color/mouse-capture/face-id-table field map, `CreateUserDialogPane` control-id 6/7 gender and color routes, `USERPART.EPF`/`USERPART.PAL` selection-frame literals, NewHumanImageLib/PaletteLib/g_pEPFLib/Surface callback dependencies, exact vtable/thunk/destructor no-code policy, and keeps aggregate formal C++ blank because this by-memory page spans multiple classes and exact method-body child pages are still absent.
```

If the supervisor chooses not to change [UID:0001A6] metadata, keep the existing aggregate score and still apply the helper-placement text correction in the doc.

## Validator Needs

After implementation callback, run targeted validator scans:

> Executable block R001 was removed from this report and preserved verbatim in [0000FJ-UserFaceSelectControlPane-source-quality-removed.md](0000FJ-UserFaceSelectControlPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the by-memory coverage row, validate it separately:

> Executable block R002 was removed from this report and preserved verbatim in [0000FJ-UserFaceSelectControlPane-source-quality-removed.md](0000FJ-UserFaceSelectControlPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Live IDA validation desired when MCP returns:

- `lookup_funcs` / `decompile` / `xrefs_to` for `0x00501660`, `0x00501790`, `0x00501840`, `0x00501a70`.
- `xrefs_to 0x00501660`, `xrefs_to 0x00501a70`, `xrefs_to 0x0061de20`, `xrefs_to 0x0061de88`, `xrefs_to 0x0061deb8`.
- Byte/string check for `0x0061e3c0` and `0x0061e420` to confirm `USERPART.EPF/PAL` decoding.

## IDA Rename, Type, And Comment Recommendations

High confidence:

- `sub_501660` -> `UserFaceSelectControlPane::UserFaceSelectControlPane`
- `sub_501790` -> `UserFaceSelectControlPane::OnMouseEvent`
- `sub_501840` -> `UserFaceSelectControlPane::OnPaintFrame`
- `sub_501A70` -> `UserFaceSelectControlPane::SelectFaceAtPoint`
- `sub_501620` -> `UserHairSelectControlPane::SetMaleMode`
- `sub_501640` -> `UserHairSelectControlPane::SetFemaleMode`
- `0x0061e3c0` -> wide literal `aUserpartEpf`
- `0x0061e420` -> wide literal `aUserpartPal`

Recommended local type comments:

- `UserFaceSelectControlPane` size: `0x154`.
- `+0xa0`: EventHandler vtable view; destructor adjustor backs up by `0xa0`.
- `+0xa4`: TimerHandler vtable view; destructor adjustor backs up by `0xa4`.
- `+0x10a`: `short m_selectedFace`.
- `+0x10c`: `unsigned char m_gender`.
- `+0x10d`: `unsigned char m_faceColor`.
- `+0x10e`: `bool m_mouseDownInGrid`.
- `+0x110`: `uint16_t m_facePartIds[0][12]`.
- `+0x128`: `uint16_t m_facePartIds[1][12]`.
- `+0x140`: `unsigned char m_columnCount`.
- `+0x144`: `RectBounds m_localHitRect`.

Medium confidence / descriptive only:

- `dword_69B3E8`: Surface render callback table slot 2, primary tile/frame blit callback. Avoid final typedef rename until Surface callback signatures are audited.
- `dword_69B3FC`: Surface render callback table slot 7, pane presentation/fill/invalidation callback. Avoid generated alias `g_pfnLockSurface` for final source.
- `sub_544DB0`: inherited EventHandler fallback for mouse events.

## Implementation Readiness

Ready for supervisor implementation callback:

- Target class metadata and declaration-level C++.
- Field/constants/signature/resource/caller notes.
- Support doc correction for `0x00501620` / `0x00501640`.
- Coverage rows above.

Not recommended in this first implementation callback unless supervisor wants a broader split:

- Creating exact by-memory children for the four face methods. That would be useful for method-body C++, but it is not required to fix the class page and it would expand scope beyond this report-only assignment.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000FJ-UserFaceSelectControlPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0000FJ"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000FJ-UserFaceSelectControlPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0000FJ-UserFaceSelectControlPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000FJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
