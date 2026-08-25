** TARGET-REPORT-UID:0000FH **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000FH UserCreatePreviewControlPane Source-Quality Report

Agent: B005  
Assignment: `B005-goal2-user-create-preview-control-pane-source-quality-0000FH-20260619`  
Target: `source-3/project-documentation/by-class/UserCreatePreviewControlPane.md`  
Target UID: `0000FH`  
Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/0000FH-UserCreatePreviewControlPane-source-quality.md`

## Recommendation

Keep [UID:0000FH] source-bearing and reconstructable under [UID:0000OX] `UserCreateAppearanceControls`. Raise the target from `COMPLETION:84` / `CONFIDENCE:88` to `COMPLETION:87` / `CONFIDENCE:90`, keep `RECONSTRUCTABLE:TRUE`, keep `CANONICAL_OWNER:0000OX`, and keep `EMITTER_UIDS:0000OX`.

The class is ready for first-draft declaration C++ on the by-class page, with method bodies delegated to exact child/memory pages. The old blank-C++ rationale should be replaced with current combined-score/emitter-gate reasoning: the class clears the 85/85 source-quality gate after this pass, but the by-class formal C++ should be a declaration shell with `[[CHILDREN]]` because the executable bodies belong to exact ranges. The scalar deleting destructor and secondary-base thunks remain generated binary artifacts and should not be emitted as source methods beyond a normal/defaulted virtual destructor declaration.

Add the missing source-shaped body at `0x00501d80-0x00501dbc` to the target notes and support inventory. It is a retained/no-direct-xref preview update helper, not padding and not a compiler-generated thunk. Best source-facing name: `UpdateBasePreview`. Lower-confidence alternate: `UpdatePreviewWithoutColors`. It stores face/hair/gender preview state, clears both color bytes, and invalidates the pane.

## Evidence Checked

Instruction and support docs checked:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B005/goal.md`
- `by-class/UserCreatePreviewControlPane.md`
- `by-file/UserCreateAppearanceControls.md`
- `by-file/CreateUserDialogs.md`
- `by-class/CreateUserDialogPane.md`
- `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md`
- `by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md`
- `by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md`
- sibling old create-user control docs: `UserFaceSelectControlPane`, `UserHairSelectControlPane`, `UserShapeSelectControlPane`
- `by-global/g_pNewHumanImageLib.md`, `by-file/NewHumanImageLib.md`, `by-class/NewHumanImageLib.md`, and `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`

IDA MCP could not be used in this pass; the local connection returned `Unable to connect to the remote server`. Raw verification used the read-only PE `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` with Capstone disassembly and direct image-offset scans. Generated `simroot_v2` / wave output was treated only as a pollution/lead source, not as authority.

Important raw PE facts:

- `.text` covers `0x00401000-0x0060c600`, `.rdata` covers `0x0060d000-0x0066c200`, and `.data` covers `0x0066d000-0x0069ce24`.
- Constructor `0x00501b40-0x00501bba`, `ret 0x1c`, padded to `0x00501bc0` with `0xcc`.
- `BuildPreviewParams` `0x00501bc0-0x00501c58`, `ret 4`, padded to `0x00501c60`.
- `OnPaint` `0x00501c60-0x00501d45`, vtable-only, padded to `0x00501d50`.
- `AdvanceDirection` `0x00501d50-0x00501d74`, padded to `0x00501d80`.
- Newly recovered helper `0x00501d80-0x00501dbc`, padded before and after, no direct rel32 caller and no data-pointer hit.
- `UpdatePreview` `0x00501dc0-0x00501e05`, padded to `0x00501e10`.
- Preview adjustor thunks are `0x005025a8` (`this - 0xa0`) and `0x005025b3` (`this - 0xa4`), both jumping to scalar deleting destructor `0x00502d10`.

## Method Inventory And Routes

| Range | Best source-facing role | Route evidence | Source-quality decision |
| --- | --- | --- | --- |
| `0x00501b40-0x00501bba` | `UserCreatePreviewControlPane::UserCreatePreviewControlPane(...)` | direct call at `0x0052e64b`; writes primary and secondary vtable pointers | source-authored constructor; exact original spelling of trailing reserved arg remains unproven |
| `0x00501bc0-0x00501c58` | `BuildPreviewParams(HumanImageRenderParams *out) const` | direct calls at `0x00501ccc`, `0x00501d20`, `0x0052f1e8` | source-authored helper; public/accessible because CreateUserDialogPane payload builder uses it |
| `0x00501c60-0x00501d45` | `OnPaint()` | sole dword pointer at vtable slot `0x0061df08`; no direct rel32 caller | source-authored paint override |
| `0x00501d50-0x00501d74` | `AdvanceDirection()` | call at `0x0052eafe`; tail-jump helper at `0x0052e73f`; invalidates via vtable slot `+0x20` | source-authored UI action method |
| `0x00501d80-0x00501dbc` | `UpdateBasePreview(short faceFrame, short hairFrame, unsigned char gender)` | exact function-shaped bytes and padding; no rel32 or table route found | retained source-shaped helper; document no-xref status instead of treating as padding |
| `0x00501dc0-0x00501e05` | `UpdatePreview(short faceFrame, unsigned char faceColor, short hairFrame, unsigned char hairColor, unsigned char gender)` | direct call at `0x0052eb68` from `CreateUserDialogPane::OnDialogAction` | source-authored refresh/update method |
| `0x005025a8-0x005025be` | secondary/tertiary destructor adjustor thunks | vtable entries `0x0061df2c` and `0x0061df5c`; subtract `0xa0` / `0xa4`; jump to `0x00502d10` | compiler-generated; no source C++ body |
| `0x00502d10-0x00502d4b` | scalar deleting destructor | primary vtable dtor slot `0x0061dec4`; called through thunks | compiler-generated deleting destructor; source declaration may be implicit/defaulted |

The vtable neighborhood supports the class identity:

- `0x0061dec4 -> 0x00502d10` primary scalar deleting destructor.
- `0x0061df08 -> 0x00501c60` primary paint override.
- `0x0061df2c -> 0x005025a8` secondary-base deleting destructor thunk.
- `0x0061df5c -> 0x005025b3` tertiary-base deleting destructor thunk.

## Constructor And Caller Shape

The constructor calls `ControlPane::ControlPane` at `0x004949e0` with control-pane type id `8` and the bounds pointer argument. It then stores:

- `[this] = 0x0061dec4`
- `[this+0xa0] = 0x0061df2c`
- `[this+0xa4] = 0x0061df5c`
- `[this+0x108] = faceFrame + 0xc8`
- `[this+0x10a] = hairFrame`
- `[this+0x10c] = gender`
- `[this+0x10d] = 2`
- `[this+0x10e] = hairColor`
- `[this+0x10f] = faceColor`
- `[this+0x110] = 0`

The caller at `0x0052e64b` is in `CreateUserDialogPane` setup. It computes preview inputs from the old hair and face selector controls, then pushes:

1. `0` as a trailing reserved/unused constructor argument.
2. a `RectBounds *` for the pane bounds.
3. dialog gender byte from `CreateUserDialogPane+0x279`.
4. hair color byte from the hair selector `+0x10d`.
5. hair frame word, using selected hair plus `18 * gender`.
6. face color byte from the face selector `+0x10d`.
7. face frame word, using selected face plus `12 * gender`.

The binary ABI therefore consumes seven stack arguments (`ret 0x1c`) even though the constructor only reads six of them. The source-facing declaration should keep a conservative trailing `int reserved = 0` or document the unused ABI argument. Do not silently drop this from the evidence notes.

## Fields And Preview Parameters

Recommended field map:

| Offset | Type | Best name | Evidence |
| --- | --- | --- | --- |
| `+0x108` | `uint16_t` | `m_faceFrameBase` | constructor/update stores input frame plus `0xc8`; `BuildPreviewParams` writes it into descriptor offset `+0x04` |
| `+0x10a` | `uint16_t` | `m_hairFrame` | constructor/update stores hair frame; descriptor offset `+0x06` |
| `+0x10c` | `uint8_t` | `m_gender` | caller uses dialog gender; descriptor offsets `+0x21` and `+0x08` depend on it |
| `+0x10d` | `uint8_t` | `m_direction` | initialized to `2`; `AdvanceDirection` increments modulo four; passed to `NewHumanImageLib` draw/bounds methods |
| `+0x10e` | `uint8_t` | `m_hairColor` | caller supplies hair selector color; descriptor offset `+0x33`; `0x00501d80` clears it |
| `+0x10f` | `uint8_t` | `m_faceColor` | caller supplies face selector color; descriptor offset `+0x32`; `0x00501d80` clears it |
| `+0x110` | `uint8_t` | `m_reservedPreviewState` | constructor clears it; no local reader found in this pass |

The class does not directly track the old body-shape button selection. `CreateUserDialogPane::OnDialogAction` updates body shape buttons through separate `SelectBodyShape` cases, while preview refreshes are driven by face/hair/gender/color and direction. Any stale "body/shape preview field" wording should be narrowed unless later IDA evidence finds a route into `m_reservedPreviewState`.

`BuildPreviewParams` initializes a NewHumanImageLib-compatible descriptor. The exact project typedef is still not settled, so the safest source-facing names are `HumanImageRenderParams`, `NewHumanImageDescriptor`, or `NewHumanPreviewParams`. It writes descriptor fields including:

- descriptor type/palette byte set by `OnPaint` at offset `+0x28` to `0x50` before calling `BuildPreviewParams`;
- gender at `+0x21`, and a gender-derived word at `+0x08`;
- face frame at `+0x04`, face color at `+0x32`;
- hair frame at `+0x06`, hair color at `+0x33`;
- sentinel/default values at offsets including `+0x0e`, `+0x10`, `+0x14`, `+0x18`, `+0x1a`, `+0x1e`, `+0x22`, `+0x34`, `+0x35`, `+0x38`, and `+0x3a`.

## Paint Behavior

`OnPaint` is vtable-only, not dead. Its source shape is a normal paint override:

1. Initializes a local render/context helper through `0x00457a60`.
2. Sets/clears drawing state with broad helper `0x004b9660(this, 0)`.
3. Fills or clears the active pane rectangle through `SurfaceRenderCallbackTable` slot `0x0069b3fc`, passing the inherited bounds at `this+0x44`.
4. Builds a base `RectBounds` of `(0, 0, 82, 117)` through helper `0x004b7c50`.
5. Calls `BuildPreviewParams`.
6. Calls `NewHumanImageLib::CalculateBounds` at `0x004e09e0` through `g_pNewHumanImageLib` (`0x0067a760`) using the current direction.
7. Offsets the draw rectangle through `0x004b78f0`, including a final visible offset of `(15, 75)`.
8. Calls `BuildPreviewParams` again, then `NewHumanImageLib::Draw` at `0x004e06a0`.

Use descriptive helper wording in documentation and C++ drafts: `FillRect` / active rectangle fill wrapper for `0x0069b3fc`, `SetRect` for `0x004b7c50`, `OffsetRect` for `0x004b78f0`, and `g_pNewHumanImageLib->CalculateBounds/Draw` for the NewHumanImageLib calls. Do not import generated names for these helpers into source-facing C++.

## Dialog Caller Interactions

`CreateUserDialogPane` reaches the preview pane through control id `0x12`:

- setup/constructor call at `0x0052e64b`;
- direction advance through action path call at `0x0052eafe`;
- raw/tail helper at `0x0052e730-0x0052e744`, which fetches control id `0x12` and jumps to `AdvanceDirection`;
- refresh/update after hair, face, color, and gender changes at `0x0052eb68`;
- packet/payload builder call at `0x0052f1e8`, which fetches control id `0x12` and calls `BuildPreviewParams`.

`SelectMale` / `SelectFemale` store `CreateUserDialogPane+0x279` as `0` / `1`, update active states, and reconfigure hair/face selector controls. `SetHairColor` writes the hair selector color byte at selector `+0x10d`; `SetFaceColor` writes the face selector color byte at selector `+0x10d`. `OnDialogAction` then pushes selected face frame, face color, hair frame, hair color, and gender into `UpdatePreview`.

This route supports `UserCreateAppearanceControls` as the emitting owner while documenting `CreateUserDialogPane` as the runtime coordinator.

## Missing Helper At 0x00501d80

The body at `0x00501d80-0x00501dbc` should be documented. It is not padding:

```cpp
void UserCreatePreviewControlPane::UpdateBasePreview(short faceFrame,
                                                     short hairFrame,
                                                     unsigned char gender)
{
    m_faceFrameBase = faceFrame + 200;
    m_hairFrame = hairFrame;
    m_gender = gender;
    m_hairColor = 0;
    m_faceColor = 0;
    InvalidateBounds();
}
```

`InvalidateBounds()` is descriptive for the vtable-slot `+0x20` call with `this+0x44`; the exact original method name remains unproven. No direct rel32 call, vtable pointer, or dword table reference was found for `0x00501d80`, so mark it as a retained/no-direct-xref helper. It should not be classified as generated or ignored.

## Destructor And Thunk Policy

The destructor-related executable ranges are generated:

- `0x00502d10-0x00502d4b` is the scalar deleting destructor body. It calls `Pane::~Pane()` at `0x00544580`, conditionally calls the `operator delete` wrapper at `0x004f4ac0`, and uses guard/helper `0x0041b6a0`.
- `0x005025a8-0x005025b3` adjusts `this` by `-0xa0` and jumps to `0x00502d10`.
- `0x005025b3-0x005025be` adjusts `this` by `-0xa4` and jumps to `0x00502d10`.

Recommended source policy: keep normal class declaration spelling only, such as `virtual ~UserCreatePreviewControlPane();` or a defaulted destructor if the project style permits. Do not emit scalar deleting destructor code, raw adjustor thunk methods, or generated thunk names in source-facing C++.

## Owner And Source Placement Ranking

1. `UserCreateAppearanceControls` [UID:0000OX] is the best owner/emitter. The constructor, preview methods, vtable entries, sibling selector controls, and destructor/thunk cluster all sit in the old appearance-controls family.
2. `CreateUserDialogs` / `CreateUserDialogPane` is a caller/coordinator, not the emitting owner. It constructs the pane and invokes update/build methods through control id `0x12`.
3. `UserCreateAppearanceSelectorControls` [UID:0001A6] is an aggregate/range container. It should record the preview method inventory, including the recovered `0x00501d80` helper, but should not own the final class source.
4. A no-owner/non-emitting policy is rejected because the class has a vtable, constructor, normal paint/update methods, and live dialog routes.
5. Split child rows would improve implementation quality. The by-class page should emit a declaration shell; exact method bodies should be placed in existing or future by-memory child pages rather than pasted into the class overview.

## First-Draft Class C++ Recommendation

Recommended by-class formal C++ shape:

```cpp
struct RectBounds;
struct HumanImageRenderParams;

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
    virtual ~UserCreatePreviewControlPane();

protected:
    virtual void OnPaint();

public:
    HumanImageRenderParams *BuildPreviewParams(HumanImageRenderParams *outParams) const;
    void AdvanceDirection();
    void UpdatePreview(short faceFrame,
                       unsigned char faceColor,
                       short hairFrame,
                       unsigned char hairColor,
                       unsigned char gender);

private:
    void UpdateBasePreview(short faceFrame, short hairFrame, unsigned char gender);

    unsigned short m_faceFrameBase;
    unsigned short m_hairFrame;
    unsigned char m_gender;
    unsigned char m_direction;
    unsigned char m_hairColor;
    unsigned char m_faceColor;
    unsigned char m_reservedPreviewState;

    [[CHILDREN]]
};
```

The trailing `reserved` constructor parameter is an ABI/evidence preservation choice. If later source-style evidence proves the original constructor hid or wrapped that unused zero argument, it can be removed from the human source signature, but the current by-class notes should retain the `ret 0x1c`/caller-push evidence.

Method-body drafts for future child pages:

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

`OnPaint` above is intentionally descriptive, not exact decompiler output. The real binary performs extra local helper setup and intermediate offset calculations around `CalculateBounds`.

## Exact Recommended Target Changes

For `by-class/UserCreatePreviewControlPane.md`:

- Change metadata to `COMPLETION:87`, `CONFIDENCE:90`, keep `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000OX`, and `EMITTER_UIDS:0000OX`.
- Replace the stale blank-C++ / below-95 rationale with the current combined-score/emitter gate rationale.
- Add method inventory rows for constructor, `BuildPreviewParams`, `OnPaint`, `AdvanceDirection`, `UpdateBasePreview` at `0x00501d80-0x00501dbc`, `UpdatePreview`, generated adjustor thunks, and scalar deleting destructor policy.
- Add the field map for `+0x108` through `+0x110`.
- Document the constructor caller at `0x0052e64b` and the unused trailing ABI argument.
- Document `CreateUserDialogPane` control id `0x12` routes: constructor, `AdvanceDirection`, `UpdatePreview`, and `BuildPreviewParams` payload builder.
- Document `OnPaint` dependencies on `SurfaceRenderCallbackTable` slot `0x0069b3fc`, `g_pNewHumanImageLib`, `NewHumanImageLib::CalculateBounds` at `0x004e09e0`, and `NewHumanImageLib::Draw` at `0x004e06a0`.
- Add the declaration-only C++ block above with `[[CHILDREN]]`.
- Explicitly reject generated scalar-deleting-destructor and adjustor-thunk source emission.
- Add remaining issues: original spelling of `reserved`, final descriptor typedef name, and no-direct-xref status of `0x00501d80`.

## Support-Doc Update Checklist

Recommended support updates if the implementation callback accepts this report:

- `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md`: add the recovered `0x00501d80-0x00501dbc` preview update helper between `AdvanceDirection` and `UpdatePreview`; state that IDA/project inventory previously counted 21 modeled functions but raw PE evidence shows one additional source-shaped retained helper. Keep this aggregate as a range container, not the emitting owner.
- `by-file/UserCreateAppearanceControls.md`: add a short note that B005 0000FH resolved preview-pane constructor/update/paint source shape, fields, and the recovered no-xref helper; owner/emitter remains [UID:0000OX].
- `by-file/CreateUserDialogs.md` and/or `by-class/CreateUserDialogPane.md`: optional note that control id `0x12` is `UserCreatePreviewControlPane`; it is constructed at `0x0052e64b`, advanced through `0x0052eafe`/`0x0052e730`, refreshed at `0x0052eb68`, and queried for packet payload params at `0x0052f1e8`.
- `by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md`: no required change if it already records the `-0xa0`/`-0xa4` preview thunks; otherwise add a one-line cross-reference to this class.
- `by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md`: no required change if it already records `0x00502d10` as generated; otherwise add cross-reference that by-class source uses only an ordinary/defaulted destructor declaration.
- `g_pNewHumanImageLib` / `NewHumanImageLib` docs: no change required; existing ownership and Draw/CalculateBounds identities are sufficient.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` or any coverage file during the report phase. If accepted, use this replacement text for the by-class coverage row:

```markdown
- [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md) : reconstructable : 87% : very strong : B005 source-quality recheck resolves the old create-user preview pane as a declaration-ready class under UserCreateAppearanceControls: raw PE/Capstone confirms constructor, BuildPreviewParams, OnPaint, AdvanceDirection, retained no-xref `0x00501d80-0x00501dbc` update helper, UpdatePreview, vtable-only OnPaint, constructor caller `0x0052e64b`, dialog action/update callers, packet payload BuildPreviewParams caller `0x0052f1e8`, face/hair/color/gender/direction fields at `+0x108..+0x110`, g_pNewHumanImageLib Draw/CalculateBounds use, SurfaceRenderCallbackTable slot `0x0069b3fc` background fill, and compiler-generated destructor/thunk exclusion; formal C++ should be declaration-only with `[[CHILDREN]]` while method bodies wait for exact child pages.
```

If the aggregate support page is updated and the by-memory coverage report needs a companion row, use this replacement text:

```markdown
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) 0x00501150-0x00502383 | aggregate/control cluster | UserCreateAppearanceSelectorControls : reconstructable : 86% : very strong : B005 0000FH recheck preserves the UserCreateAppearanceControls owner route and adds raw PE/Capstone evidence for the preview-control subrange: constructor/BuildPreviewParams/OnPaint/AdvanceDirection/UpdatePreview plus the retained no-direct-xref `0x00501d80-0x00501dbc` update helper, exact `0xcc` padding around the preview methods, vtable-only paint route, CreateUserDialogPane constructor/action/payload edges, resolved face/hair/color/gender/direction fields, NewHumanImageLib draw/bounds dependencies, and compiler-generated destructor/thunk exclusion. The aggregate remains a source-bearing container, but method bodies should be split/emitted through exact child/class pages rather than pasted into this aggregate.
```

## Validation Commands Needed After Implementation

No validator was run during this report-only pass because no by-* docs were edited. After implementation, run scoped validators from `source-3/project-documentation` for every touched doc:

> Executable block R001 was removed from this report and preserved verbatim in [0000FH-UserCreatePreviewControlPane-source-quality-removed.md](0000FH-UserCreatePreviewControlPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run the optional `CreateUserDialogs` / `CreateUserDialogPane` validators if those support docs are edited.

## IDA Rename, Type, And Comment Recommendations

High-confidence function names/types:

- `0x00501b40`: `UserCreatePreviewControlPane::UserCreatePreviewControlPane(short faceFrame, uint8_t faceColor, short hairFrame, uint8_t hairColor, uint8_t gender, const RectBounds *bounds, int reserved)`.
- `0x00501bc0`: `UserCreatePreviewControlPane::BuildPreviewParams(HumanImageRenderParams *outParams) const`.
- `0x00501c60`: `UserCreatePreviewControlPane::OnPaint()`.
- `0x00501d50`: `UserCreatePreviewControlPane::AdvanceDirection()`.
- `0x00501dc0`: `UserCreatePreviewControlPane::UpdatePreview(short faceFrame, uint8_t faceColor, short hairFrame, uint8_t hairColor, uint8_t gender)`.

Medium-confidence retained helper name:

- `0x00501d80`: `UserCreatePreviewControlPane::UpdateBasePreview(short faceFrame, short hairFrame, uint8_t gender)`. Comment: "No direct static xref found; source-shaped retained helper, clears hair/face color bytes and invalidates bounds."

Generated-binary comments:

- `0x005025a8`: secondary-base destructor adjustor thunk, `this -= 0xa0`, jumps to `0x00502d10`.
- `0x005025b3`: tertiary-base destructor adjustor thunk, `this -= 0xa4`, jumps to `0x00502d10`.
- `0x00502d10`: scalar deleting destructor for `UserCreatePreviewControlPane`; source declaration should be ordinary/defaulted destructor, not raw deleting wrapper.

Field comments:

- `this+0x108`: `m_faceFrameBase`, stored as input face frame plus `200`.
- `this+0x10a`: `m_hairFrame`.
- `this+0x10c`: `m_gender`.
- `this+0x10d`: `m_direction`, initialized to `2`, advanced modulo four.
- `this+0x10e`: `m_hairColor`.
- `this+0x10f`: `m_faceColor`.
- `this+0x110`: `m_reservedPreviewState`, constructor-cleared; no reader found in this pass.

Vtable/data comments:

- `0x0061df08`: primary `OnPaint` slot.
- `0x0061dec4`: primary scalar deleting destructor slot.
- `0x0061df2c` / `0x0061df5c`: secondary/tertiary destructor adjustor slots.
- `0x0069b3fc`: active rectangle fill callback used by `OnPaint`; keep project canonical SurfaceRenderCallbackTable naming rather than generated globals.

## Remaining Issues

- Exact original source spelling of the unused seventh constructor argument is not proven. Binary evidence requires recording it; source generator may later choose `reserved` or elide it through a higher-level construction wrapper if better source-style evidence appears.
- Final project typedef for the NewHumanImageLib descriptor remains unresolved. Use `HumanImageRenderParams` or `NewHumanImageDescriptor` descriptively until the type-name sweep settles it.
- The `0x00501d80-0x00501dbc` helper has no direct static caller or data pointer found in this pass. It is source-shaped and padded, so document it as retained/no-direct-xref rather than generated or padding.
- IDA MCP was unavailable, so this pass relies on local PE/Capstone evidence and existing project docs. The raw addresses and routes match the current documentation layout.

## Changed Files

Report-only. Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/0000FH-UserCreatePreviewControlPane-source-quality.md`

No by-* docs and no coverage docs were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0000FH-UserCreatePreviewControlPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0000FH"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000FH-UserCreatePreviewControlPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0000FH-UserCreatePreviewControlPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000FH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
