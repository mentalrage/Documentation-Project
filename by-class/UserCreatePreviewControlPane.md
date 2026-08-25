*** UID:0000FH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class UserCreatePreviewControlPane : public ControlPane
{
public:
    UserCreatePreviewControlPane(short faceFrame,
                                 unsigned char faceColor,
                                 short hairFrame,
                                 unsigned char hairColor,
                                 unsigned char gender,
                                 const RectBounds *bounds,
                                 int reserved = 0);
    virtual ~UserCreatePreviewControlPane() {}

    virtual void OnPaint();

    HumanImageRenderParams *BuildPreviewParams(
        HumanImageRenderParams *params) const;
    void AdvanceDirection();
    void UpdatePreview(short faceFrame,
                       short hairFrame,
                       unsigned char gender);
    void UpdatePreview(short faceFrame,
                       unsigned char faceColor,
                       short hairFrame,
                       unsigned char hairColor,
                       unsigned char gender);

private:
    unsigned short m_faceFrameBase;
    unsigned short m_hairFrame;
    unsigned char m_gender;
    unsigned char m_direction;
    unsigned char m_hairColor;
    unsigned char m_faceColor;
    unsigned char m_reservedState;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserCreatePreviewControlPane

## Status

- Confidence: very strong for class identity, method inventory, fields, dialog routes, and declaration-level C++; medium-high for the final source spelling of the unused constructor argument and render-parameter typedef.
- Likely source file: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Current recovered file: `source-3/simroot_v2/class_UserCreatePreviewControlPane.cpp`
- Address range: [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- Autogen handling: this class emits its complete declaration from formal H at source position `40` through [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md); formal CPP retains only `[[CHILDREN]]` for exact executable method definitions. The scalar deleting destructor and `this`-adjustor thunks are compiler-generated support regenerated from the inline empty virtual destructor declaration.

## Class Purpose

`UserCreatePreviewControlPane` renders the final character preview in the older create-user dialog. It stores face, hair, face color, hair color, gender, and direction state, builds the NewHumanImageLib render descriptor used by both painting and packet payload construction, and supports direction cycling from the dialog action path.

The class does not directly track the old body-shape button selection. [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) owns the body-shape state and updates the separate body-shape button controls; this preview pane refreshes from face/hair/color/gender inputs plus its own direction. Do not preserve stale "body/shape preview field" wording for this class unless a later reader for `m_reservedPreviewState` is found.

## Method Notes

| Method | Address | Route evidence | Source-quality decision |
| --- | --- | --- |
| constructor | `0x00501b40-0x00501bba` | Direct call at `0x0052e64b`; installs primary/secondary/tertiary vtable pointers. | Source-authored constructor; the trailing seventh stack argument is unused but binary-visible. |
| `BuildPreviewParams` | `0x00501bc0-0x00501c58` | Direct calls at `0x00501ccc`, `0x00501d20`, and `0x0052f1e8`. | Source-authored helper, probably public/accessor-level because the old dialog packet builder calls it. |
| `OnPaint` | `0x00501c60-0x00501d45` | Vtable-only through primary slot `0x0061df08`; no direct rel32 caller. | Source-authored paint override, not dead code. |
| `AdvanceDirection` | `0x00501d50-0x00501d74` | Direct call at `0x0052eafe` and tail helper at `0x0052e730-0x0052e744`; invalidates through virtual slot `+0x20`. | Source-authored UI action method. |
| `UpdatePreview` | `0x00501d80-0x00501dbc` | Function-shaped bytes with `0xcc` padding around the body; no rel32 caller, vtable pointer, or dword table pointer found in the B005 local PE scan. | Retained source-shaped helper. Best name is `UpdatePreview`; lower-confidence alternate is `UpdatePreviewWithoutColors`. Do not classify it as padding or generated code. |
| `UpdatePreview` | `0x00501dc0-0x00501e05` | Direct call at `0x0052eb68` from `CreateUserDialogPane::OnDialogAction`. | Source-authored refresh/update method. |
| destructor/thunks | [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md), `0x00502d10` | Vtable entries `0x0061dec4`, `0x0061df2c`, and `0x0061df5c`; adjustor thunks subtract `0xa0` / `0xa4` then jump to scalar deleting destructor. | Compiler-generated support. Source C++ should expose only a normal/defaulted `virtual ~UserCreatePreviewControlPane()`, not raw deleting-wrapper or thunk methods. |

Raw PE/Capstone boundary notes from the B005 pass:

| Range | Boundary note |
| --- | --- |
| `0x00501b40-0x00501bba` | Constructor returns with `ret 0x1c`, then padding to `0x00501bc0`. |
| `0x00501bc0-0x00501c58` | `BuildPreviewParams` returns with `ret 4`, then padding to `0x00501c60`. |
| `0x00501c60-0x00501d45` | `OnPaint` body padded to `0x00501d50`. |
| `0x00501d50-0x00501d74` | `AdvanceDirection` body padded to `0x00501d80`. |
| `0x00501d80-0x00501dbc` | Newly recovered retained helper, padded before `UpdatePreview`. |
| `0x00501dc0-0x00501e05` | `UpdatePreview` body padded to `0x00501e10`. |

## Field Map

| Offset | Type | Best name | Evidence |
| --- | --- | --- | --- |
| `+0x108` | `uint16_t` | `m_faceFrameBase` | Constructor and update helpers store `faceFrame + 0xc8`; `BuildPreviewParams` writes it to descriptor offset `+0x04`. |
| `+0x10a` | `uint16_t` | `m_hairFrame` | Constructor and update helpers store the selected hair frame; descriptor offset `+0x06`. |
| `+0x10c` | `uint8_t` | `m_gender` | The old dialog passes `CreateUserDialogPane+0x279`; descriptor offsets `+0x21` and `+0x08` depend on it. |
| `+0x10d` | `uint8_t` | `m_direction` | Constructor initializes `2`; `AdvanceDirection` increments modulo four; NewHumanImageLib draw/bounds calls consume it. |
| `+0x10e` | `uint8_t` | `m_hairColor` | Supplied by the hair selector's color byte; descriptor offset `+0x33`; `UpdatePreview` clears it. |
| `+0x10f` | `uint8_t` | `m_faceColor` | Supplied by the face selector's color byte; descriptor offset `+0x32`; `UpdatePreview` clears it. |
| `+0x110` | `uint8_t` | `m_reservedPreviewState` | Constructor clears it; no local reader was found in the B005 pass. |

## Constructor And Dialog Routes

The constructor call at `0x0052e64b` is inside the old [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) setup path for control id `0x12` / decimal `18`. The call computes preview inputs from the older hair and face selector controls, then pushes:

1. `0` as a trailing reserved/unused constructor argument.
2. a `RectBounds *` for the pane bounds.
3. dialog gender byte from `CreateUserDialogPane+0x279`.
4. hair color byte from the hair selector `+0x10d`.
5. hair frame word read from [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) as `m_hairPartFrames[m_genderStyle][m_selectedHairSlot]`, indexed in memory as `+0x110 + 2 * (selectedHair + 18 * hairStyle)`.
6. face color byte from the face selector `+0x10d`.
7. face frame word, selected face plus `12 * gender`.

The constructor calls `ControlPane::ControlPane` at `0x004949e0` with control-pane type id `8` and the bounds pointer, stores vtable pointers at `[this] = 0x0061dec4`, `[this+0xa0] = 0x0061df2c`, and `[this+0xa4] = 0x0061df5c`, then seeds `m_faceFrameBase`, `m_hairFrame`, `m_gender`, `m_direction`, `m_hairColor`, `m_faceColor`, and `m_reservedPreviewState`.

The ABI consumes seven stack arguments (`ret 0x1c`) even though the body reads only six semantic inputs. Keep a conservative `int reserved = 0` source-facing argument until stronger source-style evidence proves the unused zero came from an inline wrapper or should be elided.

Dialog interactions through control id `0x12`:

- `0x0052e64b`: constructs this preview pane during old-dialog setup.
- `0x0052eafe`: advances direction from the dialog action path.
- `0x0052e730-0x0052e744`: raw/tail helper fetches control id `0x12` and jumps to `AdvanceDirection`.
- `0x0052eb68`: refreshes the preview after hair, face, color, and gender changes by calling `UpdatePreview`.
- `0x0052f1e8`: packet/payload builder fetches control id `0x12` and calls `BuildPreviewParams`.

[UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) remains the runtime coordinator. [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) remains the emitting owner for this preview class.

B009's hair-selector source-quality pass refines the preview input contract: the preview pane stores the already-resolved hair frame id, not the raw selected hair slot. The old dialog resolves that frame through [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md)'s 18-entry-per-gender table and separately passes the hair color byte from selector `+0x10d`.

## Render And Preview Behavior

`BuildPreviewParams` initializes a NewHumanImageLib-compatible descriptor. The final project typedef is unresolved; use `HumanImageRenderParams`, `NewHumanImageDescriptor`, or `NewHumanPreviewParams` as descriptive names until the type-name sweep settles it. The helper writes:

- descriptor type/palette byte set by `OnPaint` at offset `+0x28` to `0x50` before calling `BuildPreviewParams`;
- gender at `+0x21`, plus a gender-derived word at `+0x08`;
- face frame at `+0x04` and face color at `+0x32`;
- hair frame at `+0x06` and hair color at `+0x33`;
- sentinel/default values at offsets including `+0x0e`, `+0x10`, `+0x14`, `+0x18`, `+0x1a`, `+0x1e`, `+0x22`, `+0x34`, `+0x35`, `+0x38`, and `+0x3a`.

`OnPaint` is a normal vtable-only paint override. It initializes a local render/context helper through `0x00457a60`, clears drawing state through broad GrafPort helper `0x004b9660(this, 0)`, fills or clears the active pane rectangle by calling [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `0x0069b3fc` with inherited bounds at `this+0x44`, builds a base `RectBounds(0, 0, 82, 117)` through `0x004b7c50`, calls `BuildPreviewParams`, calls `NewHumanImageLib::CalculateBounds` at `0x004e09e0` through [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md), offsets the draw rectangle through `0x004b78f0` with final visible offset `(15, 75)`, rebuilds params, and calls `NewHumanImageLib::Draw` at `0x004e06a0`.

Use source-facing helper descriptions such as `FillRect`, `SetRect`, `OffsetRect`, `g_pNewHumanImageLib->CalculateBounds`, and `g_pNewHumanImageLib->Draw`; do not copy generated helper/global names into human C++.

The recovered helper at `0x00501d80-0x00501dbc` has this source shape:

```cpp
void UserCreatePreviewControlPane::UpdatePreview(short faceFrame,
                                                     short hairFrame,
                                                     unsigned char gender)
{
    m_faceFrameBase = static_cast<unsigned short>(faceFrame + 200);
    m_hairFrame = static_cast<unsigned short>(hairFrame);
    m_gender = gender;
    m_hairColor = 0;
    m_faceColor = 0;
    InvalidateBounds();
}
```

`InvalidateBounds()` is descriptive for the virtual slot `+0x20` call with `this+0x44`; the exact original method name remains unproven.

## First-Draft Method Body Notes

The formal class C++ above is intentionally declaration-only. If exact child pages are later created for the preview methods, the current high-probability body drafts are:

```cpp
UserCreatePreviewControlPane::UserCreatePreviewControlPane(
    short faceFrame,
    unsigned char faceColor,
    short hairFrame,
    unsigned char hairColor,
    unsigned char gender,
    const RectBounds *bounds,
    int /*reserved*/)
    : ControlPane(8, bounds),
      m_faceFrameBase(static_cast<unsigned short>(faceFrame + 200)),
      m_hairFrame(static_cast<unsigned short>(hairFrame)),
      m_gender(gender),
      m_direction(2),
      m_hairColor(hairColor),
      m_faceColor(faceColor),
      m_reservedPreviewState(0)
{
}
```

```cpp
void UserCreatePreviewControlPane::AdvanceDirection()
{
    m_direction = static_cast<unsigned char>((m_direction + 1) & 3);
    InvalidateBounds();
}
```

```cpp
void UserCreatePreviewControlPane::UpdatePreview(short faceFrame,
                                                 unsigned char faceColor,
                                                 short hairFrame,
                                                 unsigned char hairColor,
                                                 unsigned char gender)
{
    m_faceFrameBase = static_cast<unsigned short>(faceFrame + 200);
    m_hairFrame = static_cast<unsigned short>(hairFrame);
    m_gender = gender;
    m_hairColor = hairColor;
    m_faceColor = faceColor;
    InvalidateBounds();
}
```

```cpp
void UserCreatePreviewControlPane::OnPaint()
{
    HumanImageRenderParams params;
    RectBounds drawRect;

    SetDrawState(0);
    FillRect(&m_bounds);
    SetRect(&drawRect, 0, 0, 82, 117);

    params.kind = 0x50;
    BuildPreviewParams(&params);
    g_pNewHumanImageLib->CalculateBounds(&params, m_direction, &drawRect);

    OffsetRect(&drawRect, 15, 75);

    params.kind = 0x50;
    BuildPreviewParams(&params);
    g_pNewHumanImageLib->Draw(this, &drawRect, &params, m_direction);
}
```

The `OnPaint` draft is descriptive source shape, not a direct decompiler translation; the binary has extra local setup and intermediate offset arithmetic around `CalculateBounds`.

## Evidence Notes

- IDA confirms all listed starts.
- `xrefs_to 0x00501b40` reports construction from `CreateUserDialogPane::CreateUserDialogPane`.
- `xrefs_to 0x00501d50` and `0x00501dc0` ties direction/update calls to `CreateUserDialogPane` command handling.
- IDA confirms `0x005025a8` and `0x005025b3` as real 0xb adjustor thunks; `0x005025b3` is a secondary `this - 41` thunk currently marked as missing code in disabled generated output.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x00502d10` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-06-19 B005 source-quality recheck resolves the destructor-specific C++ policy: the deleting-destructor target is compiler wrapper evidence for an implicit/defaulted ordinary destructor, not a hand-authored source body. `0x00544580` is ordinary `Pane::~Pane()` and `0x004f4ac0` is the MemoryMan-backed global `operator delete` wrapper.
- 2026-06-20 B005 Rule 26 recheck used local PE/Capstone and direct image-offset scans to refine the preview body inventory. It confirms `.text` coverage for these bodies, exact `0xcc` padding boundaries, the previously undocumented retained helper at `0x00501d80-0x00501dbc`, no static rel32/table route to that helper, vtable-only `OnPaint`, constructor and dialog-call routes, and the field map at `+0x108..+0x110`.

## Ownership And Rejected Alternatives

- Keep owner/emitter [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md). The constructor, preview helpers, vtable entries, sibling selector controls, destructor thunks, and scalar deleting destructor cluster all sit in the old appearance-controls family.
- Treat [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) and [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) as caller/coordinator pages. They construct the pane and invoke it through control id `0x12`, but they do not own this class's source emission.
- Treat [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) as an aggregate/range container. It should index the preview methods, including `0x00501d80`, but exact method bodies should be split/emitted through exact child/class pages.
- Reject no-owner/non-emitting policy: the class has vtables, a constructor, normal paint/update methods, and live dialog routes.
- Reject scalar deleting destructor and adjustor thunk source emission: those bodies are generated binary artifacts from the ordinary destructor relationship.

## Historical Remaining Issues

- Exact original source spelling of the unused seventh constructor argument is not proven. Current source-facing name is `reserved`.
- Final project typedef for the NewHumanImageLib descriptor remains unresolved; `HumanImageRenderParams` is descriptive.
- `0x00501d80-0x00501dbc` has no direct static caller or data pointer in the B005 scan. The body is source-shaped and padded, so it remains documented as retained/no-direct-xref rather than generated or padding.

## Cross-References

- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md)
- [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md)

## 2026-07-14 UID0001A6 Implemented Source Contract

- Current metadata: `90/92`, owner/emitter UID0000OX, position 40, reconstructable true.
- The exact managed declaration is in formal H and closes with `};`; formal CPP contains `[[CHILDREN]]`, so only registered method children emit out-of-line definitions.
- Source route is dedicated `NexusTK/login/UserCreateAppearanceControls.h/.cpp` through [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).

| Exact child | Source method | Behavior |
| --- | --- | --- |
| [UID:0004OS][0x00501b40-0x00501bba.UserCreatePreviewControlPaneConstructor](by-memory/0x00501b40-0x00501bba.UserCreatePreviewControlPaneConstructor.md) | `constructor` | 0x114 state, face+200, direction 2, reserved zero |
| [UID:0004OT][0x00501bc0-0x00501c58.UserCreatePreviewControlPaneBuildPreviewParams](by-memory/0x00501bc0-0x00501c58.UserCreatePreviewControlPaneBuildPreviewParams.md) | `BuildPreviewParams` | exact descriptor defaults/sentinels; kind remains caller-owned |
| [UID:0004OU][0x00501c60-0x00501d45.UserCreatePreviewControlPaneOnPaint](by-memory/0x00501c60-0x00501d45.UserCreatePreviewControlPaneOnPaint.md) | `OnPaint` | clear, kind 0x50, 82x117 bounds, 15/75 offset, draw |
| [UID:0004OV][0x00501d50-0x00501d74.UserCreatePreviewControlPaneAdvanceDirection](by-memory/0x00501d50-0x00501d74.UserCreatePreviewControlPaneAdvanceDirection.md) | `AdvanceDirection` | modulo-four step and invalidation |
| [UID:0004OW][0x00501d80-0x00501dbc.UserCreatePreviewControlPaneUpdatePreviewFaceHairGender](by-memory/0x00501d80-0x00501dbc.UserCreatePreviewControlPaneUpdatePreviewFaceHairGender.md) | `UpdatePreview(3 args)` | retained zero-xref overload clears colors and invalidates |
| [UID:0004OX][0x00501dc0-0x00501e05.UserCreatePreviewControlPaneUpdatePreviewFull](by-memory/0x00501dc0-0x00501e05.UserCreatePreviewControlPaneUpdatePreviewFull.md) | `UpdatePreview(5 args)` | live full update at caller 0x0052eb68 |

- Layout: Exact size 0x114; face base +0x108, hair +0x10a, gender +0x10c, direction +0x10d, hair/face colors +0x10e/+0x10f, reserved +0x110.
- Liveness/ABI: Constructor caller 0x0052e64b; builder callers 0x00501ccc/0x00501d20/0x0052f1e8; paint vtable 0x0061df08; direction callers 0x0052e73f/0x0052eafe. UpdateBasePreview is rejected in favor of the accepted overload.
- Shared type/table support is [UID:0004P6][UserCreateAppearanceControlLayouts](by-type/by-struct/UserCreateAppearanceControlLayouts.md) and [UID:0004P7][0x0061e570-0x0061e5b0.UserCreateAppearanceColorValueTable](by-memory/0x0061e570-0x0061e5b0.UserCreateAppearanceColorValueTable.md).
- [UID:0004P8][UserCreateAppearanceControlVtables](by-type/by-vtable/UserCreateAppearanceControlVtables.md) and [UID:0004P9][0x0061dd78-0x0061e0ec.UserCreateAppearanceControlVtableData](by-memory/0x0061dd78-0x0061e0ec.UserCreateAppearanceControlVtableData.md) remain compiler-generated/non-emitting; normal virtual destructors regenerate deleting wrappers and adjustors.
- Exact addresses, bytes, fields, calls, branches, constants, and side effects are binary facts. Source spellings/file split are bounded inference because no authentic source/PDB survives.
- Rejected: broad-parent output, dialog ownership, renderer/palette ownership, raw offset/decompiler C++, explicit vptr/cookie/adjustor source, guards absent from the binary, and duplicate aggregate/class/child emission.
- Historical notes below remain provenance snapshots; this implemented contract supersedes stale blank-C++, missing-child, old-name, inline-only, and unresolved-placement assertions.

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, preview parameter builder, paint method, direction advance, preview update, adjustor thunks, and scalar deleting destructor at `0x00501b40`, `0x00501bc0`, `0x00501c60`, `0x00501d50`, `0x00501dc0`, `0x005025a8`, `0x005025b3`, and `0x00502d10`; this page and parent [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: scored from the preview rendering/update method map, constructor/caller xrefs, appearance-control file grouping, and adjustor-thunk/destructor evidence.
- 2026-06-20 B005 Rule 26 source-quality incorporation:
  - Changed to: `COMPLETION:87`, `CONFIDENCE:90`, owner/emitter unchanged as [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md), and formal C++ populated with a declaration shell plus `[[CHILDREN]]`.
  - Summary/evidence: incorporated local PE/Capstone source-quality recheck, exact preview method inventory and padding, retained/no-direct-xref `UpdateBasePreview` at `0x00501d80-0x00501dbc`, field map, constructor ABI/caller shape, old-dialog control-id routes, NewHumanImageLib render/bounds dependencies, SurfaceRenderCallbackTable fill dependency, generated destructor/thunk exclusion, source-owner ranking, and remaining final-name issues.
- 2026-06-21 B009 hair-selector input sync:
  - Score unchanged.
  - Summary/evidence: corrected the preview input prose to state that the old dialog passes a resolved hair frame id from `UserHairSelectControlPane::m_hairPartFrames[m_genderStyle][m_selectedHairSlot]`, plus hair color byte `+0x10d`, rather than a raw selected-hair index.
