** TARGET-REPORT-UID:0000FL **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000FL UserHairSelectControlPane Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000FL] `UserHairSelectControlPane` as reconstructable, source-authored old create-user UI code owned/emitted by [UID:0000OX] `UserCreateAppearanceControls`.
- Final disposition: report-only. Do not edit target/support by-* docs until supervisor sends an implementation callback. Do not edit `by-memory/-coverage-report.md`.
- Recommended metadata: `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000OX`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OX`.
- C++ recommendation: eligible under the current average >85 emitter gate. Add a first-draft class/source-shape section for the source-authored constructor, mouse handler, paint handler, selection helper, and style helpers. Do not emit raw scalar deleting destructor or adjustor thunk bodies; source should contain only an implicit/defaulted ordinary destructor declaration if needed.
- Main support correction: `0x00501620` and `0x00501640` are stale when documented only as `UserShapeSelectControlPane` helpers. Current caller evidence uses them on old dialog child slot `6`, the hair selector, and the bodies set `UserHairSelectControlPane +0x10c` to style/gender mode `0` or `1` and invalidate.
- Confidence: high for behavior, layout, caller routing, vtable/adjustor policy, and owner/emitter route; below final-audit range because original source-file split, final event enum names, exact render helper spellings, and byte `+0x108` remain inferred or unresolved.

## Target

- Assignment id: `B009-goal2-user-hair-select-control-pane-source-quality-0000FL-20260619`
- Target UID: `0000FL`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\UserHairSelectControlPane.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B009\research\0000FL-UserHairSelectControlPane-source-quality.md`
- Current target state: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OX`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OX`, formal C++ blank.
- Existing generated output row: `auto-generated/NexusTK/login/UserCreateAppearanceControls.cpp` has an empty marker for UID `0000FL`.

## Supervisor Active Recheck

- The user requested report-only B-agent source-quality research before supervisor review.
- No by-* target/support docs were edited.
- No coverage report was edited.
- Existing reports `00012L`, `00013H`, `00016T`, `0002PX`, `0001CN`, `0001N4`, `0002JG`, and `0001K5` were not touched.

## Evidence Checked

Primary static/export evidence:

- `source-3/core/data/readonly/prewave/exported-functions/0x00501150.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x005012b0.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x00501360.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x00501590.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x00501620.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x00501640.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x005025d4.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x005025df.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x00502d90.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x0052dd30.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x0052e850.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x0052e8c0.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x0052e930.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x0052ea80.json`
- `resources/exported_data/master_vtables.json`
- `resources/exported_data/master_globals.json`
- `resources/exported_data/master_names.json`

Raw PE evidence:

- Local PE used: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- Manual PE parser and Capstone 5.0.7 used to map VAs, raw offsets, padding, vtable dwords, direct `E8/E9` references, and VA dword references.

Documentation evidence reviewed:

- Target: `by-class/UserHairSelectControlPane.md`
- Source parent: `by-file/UserCreateAppearanceControls.md`
- Alternate umbrella: `by-file/CreateUserDialogs.md`
- Caller/support: `by-class/CreateUserDialogPane.md`, `by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md`
- Aggregate: `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md`
- Thunk/destructor support: `by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md`, `by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md`
- Sibling docs: `by-class/UserFaceSelectControlPane.md`, `by-class/UserHairColorSelectListPane.md`, `by-class/UserCreatePreviewControlPane.md`, `by-class/UserShapeSelectControlPane.md`
- Read-only data docs: `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`, `by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md`

Not used as authoritative evidence:

- Wave2 recovered source was not used as proof per B009 rules. Old wave/report text was treated only as historical/search lead when encountered.
- Live IDA MCP endpoint `127.0.0.1:13337` was unavailable in this run; local exported IDA/Ghidra records plus raw PE checks were used.

## Raw PE And Function Facts

| Item | VA range | Size | Raw offset | Key evidence |
| --- | --- | ---: | ---: | --- |
| Constructor | `0x00501150-0x005012af` | `0x15f` / 351 | `0x00100550` | Direct `E8` caller only at `0x0052e0af`; calls `ControlPane` constructor; writes primary, `+0xa0`, `+0xa4` vtables and fields through `+0x168`. |
| `OnMouseEvent` | `0x005012b0-0x0050135a` | `0xaa` / 170 | `0x001006b0` | Vtable-only VA ref at `.rdata:0x0061dde8`; no direct `E8/E9` caller; calls `0x004b7e80`, `0x00501590`, `0x00544db0`, security check. |
| `OnPaintFrame` | `0x00501360-0x0050158a` | `0x22a` / 554 | `0x00100760` | Vtable-only VA ref at `.rdata:0x0061ddc0`; no direct `E8/E9` caller; calls EPF context, NewHumanImageLib, PaletteLib, EPFLib/resource-layout, and render callbacks. |
| `SelectHairAtPoint` | `0x00501590-0x00501612` | `0x82` / 130 | `0x00100990` | Direct caller only `0x00501300` inside `OnMouseEvent`; clamps 82x58 cell coordinates and invalidates inherited bounds `this+0x44`. |
| Style mode `0` helper | `0x00501620-0x00501631` | `0x11` / 17 | `0x00100a20` | Direct caller only `0x0052e89b`; writes byte `this+0x10c = 0`; invalidates inherited bounds. |
| Style mode `1` helper | `0x00501640-0x00501651` | `0x11` / 17 | `0x00100a40` | Direct caller only `0x0052e90b`; writes byte `this+0x10c = 1`; invalidates inherited bounds. |
| Destructor thunk `+0xa0` | `0x005025d4-0x005025df` | `0x0b` / 11 | `0x001019d4` | `sub ecx,0xa0; jmp 0x00502d90`; VA ref only at `.rdata:0x0061dde4`. |
| Destructor thunk `+0xa4` | `0x005025df-0x005025ea` | `0x0b` / 11 | `0x001019df` | `sub ecx,0xa4; jmp 0x00502d90`; VA ref only at `.rdata:0x0061de14`. |
| Scalar deleting destructor | `0x00502d90-0x00502dcb` | `0x3b` / 59 | `0x00102190` | Calls `0x00544580`; flags `1/4`; calls `0x004f4ac0` or guard helper with `this,0x16c`; VA ref at `.rdata:0x0061dd7c`; jump refs only from the two thunks. |

Padding confirmed from raw bytes:

- `0x005012af-0x005012b0`: one `0xcc`.
- `0x0050135a-0x00501360`: six `0xcc`.
- `0x0050158a-0x00501590`: six `0xcc`.
- `0x00501612-0x00501620`: fourteen `0xcc`.
- `0x00501631-0x00501640`: fifteen `0xcc`.
- `0x00501651-0x00501660`: fifteen `0xcc`.
- `0x00502dcb-0x00502dd0`: five `0xcc`.

## Vtable / Multiple-Inheritance Facts

Raw vtable dwords and `master_vtables.json` agree:

- Primary vtable `0x0061dd7c`:
  - first slot `0x00502d90`, scalar deleting destructor wrapper.
  - paint slot at `0x0061ddc0 -> 0x00501360`.
  - inherited/base slots include `0x004f4b10`, `0x0041b6c0`, Pane methods `0x00544730` through `0x00544d70`, FittingRoom/RadioGroup-like inherited methods, and tail `0x004214c0`.
- Secondary vtable `0x0061dde4`:
  - first slot `0x005025d4`, destructor adjustor thunk backing up `this` by `0xa0`.
  - next slot `0x005012b0`, `OnMouseEvent` compiled with secondary-base receiver.
  - remaining slots are inherited/base event helpers.
- Tertiary vtable `0x0061de14`:
  - first slot `0x005025df`, destructor adjustor thunk backing up `this` by `0xa4`.
  - second slot `0x00544e90`, inherited/base virtual.

Interpretation:

- The class declaration/source must model the same inherited base set that produces primary, `+0xa0`, and `+0xa4` vptrs, but source must not hand-port the two 11-byte destructor adjustors.
- `OnMouseEvent` receives the secondary-base pointer. Raw disassembly reads hit rect at `secondary this + 0xbc == complete object + 0x15c`, tracking byte at `secondary this + 0x6e == complete object + 0x10e`, then calls `SelectHairAtPoint` with `ecx = secondary this - 0xa0`.

## Field / Layout Inference

Object allocation at `CreateUserDialogPane::CreateUserDialogPane` is `0x16c` bytes. The constructor's last proven object writes reach `+0x168..+0x16b`, matching that allocation. The Ghidra/OOAnalyzer 712-byte class-size artifact should not be used for final layout.

| Offset | Recommended field direction | Evidence and status |
| ---: | --- | --- |
| `+0x00` | primary vptr / primary base | Constructor stores `0x0061dd7c`; primary vtable owns paint and scalar deleting destructor. |
| `+0x44` | inherited Pane bounds / invalidation rect | `SelectHairAtPoint` and style helpers pass `this+0x44` to primary vtable slot `+0x20`, matching Pane invalidation. |
| `+0xa0` | secondary base vptr | Constructor stores `0x0061dde4`; `OnMouseEvent` and first destructor adjustor route through this subobject. |
| `+0xa4` | tertiary base vptr | Constructor stores `0x0061de14`; second destructor adjustor route. |
| `+0xff` | inherited/base control flag from constructor `param_5` | Written from constructor's last byte argument. Exact source name unresolved; use `paneFlag` or existing base name if one exists. |
| `+0x108` | reserved or currently unobserved selector flag | Constructor writes zero; no reads/writes found in checked hair selector methods or dialog caller paths. Keep as `m_reserved108` / `m_unknownFlag108` until a reader is found; it should cap final naming confidence, not behavior. |
| `+0x10a` | `int16_t m_selectedHairSlot` | Constructor stores `rand()%10`; `SelectHairAtPoint` writes `row * 9 + col`; dialog preview code reads this as hair table index. |
| `+0x10c` | `uint8_t m_genderStyle` or `m_styleMode` | Constructor argument initially `0`; style helper `0x00501620` writes `0`, helper `0x00501640` writes `1`; `OnPaintFrame` and dialog preview read it as table bank selector. High-probability: `0=male`, `1=female`, by `CreateUserDialogPane` gender handlers. |
| `+0x10d` | `uint8_t m_hairColor` | Constructor initial value `12`; `CreateUserDialogPane::SetHairColorIndex` writes child slot `6 +0x10d`; `OnPaintFrame` passes it into palette/render parameters and uses `m_hairColor >> 5` for palette lookup. |
| `+0x10e` | `uint8_t m_mouseTracking` | Constructor zeroes; secondary-base `OnMouseEvent` reads/writes it as `secondary +0x6e`; controls selection while event type `0` continues after event type `1`. |
| `+0x110` | `uint16_t m_hairPartFrames[2][18]` | Constructor seeds 36 packed 16-bit part/frame ids; `OnPaintFrame` reads `selected = col + row*9 + style*18`; dialog preview uses the same formula. |
| `+0x158` | `uint8_t m_gridColumns` | Constructor writes `9`; paint and selection loops use it as column count. |
| `+0x15c` | `RectBounds m_gridHitRect` / normalized local hit rect | Constructor copies input rect, converts right/bottom to width/height, then zeroes left/top; `OnMouseEvent` hit-tests it via secondary `this + 0xbc`. |

Decoded part table from constructor dword writes, little-endian 16-bit entries:

- Style/gender bank `0` (`+0x110`, 18 entries): `{ 2, 60, 1, 8, 34, 48, 80, 36, 3, 83, 0, 15, 17, 24, 49, 71, 51, 59 }`
- Style/gender bank `1` (`+0x134` as the 19th entry onward, 18 entries): `{ 33, 74, 78, 50, 91, 10, 31, 4, 7, 45, 5, 13, 25, 54, 65, 80, 52, 58 }`

Grid constants:

- Columns: `9`.
- Rows: fixed two-row loop (`rowY = 0, 58`, stop when `rowY >= 116`).
- Cell width: `82` / `0x52`.
- Cell height: `58` / `0x3a`.
- Constructor call rect: `SetRect(170,342,926,477)` in the old dialog, giving a normalized hit rect width `756` and height `135`.

## Caller / Dialog Semantics

`CreateUserDialogPane::CreateUserDialogPane` proves the constructor source shape:

- Allocates `0x16c` bytes for the hair selector.
- Calls `sub_501150(v16, rand() % 10, 12, 0, rect, 0)` at `0x0052e0af`.
- The rect is built immediately before as `(170,342,926,477)`.
- The constructed object is added to the dialog child manager immediately after construction.

Dialog child-slot evidence:

- `CreateUserDialogPane::SetHairColorIndex` (`0x0052e930`) fetches child slot `6` and writes `*(slot6 + 269) = color`, proving child slot `6` is the hair selector and `+0x10d` is the hair-color byte.
- `CreateUserDialogPane::SetFaceColorIndex` (`0x0052e950`) fetches child slot `7` and writes `+0x10d`, proving the neighboring face selector mirrors the hair color field.
- `CreateUserDialogPane::OnDialogAction` (`0x0052ea80`) fetches child slots `6`, `7`, and `18`, then computes preview inputs from both selectors:
  - hair frame: `*(uint16_t *)(hair + 0x110 + 2 * (selectedHair + 18 * hairStyle))`
  - hair color: `*(uint8_t *)(hair + 0x10d)`
  - face frame: `*(uint16_t *)(face + 0x110 + 2 * (selectedFace + 12 * faceStyle))`
  - face color: `*(uint8_t *)(face + 0x10d)`
  - gender flag: dialog byte `+0x279` / decimal `633`
  - then calls `UserCreatePreviewControlPane::UpdatePreview(faceFrame, faceColor, hairFrame, hairColor, gender)`.
- `CreateUserDialogPane` gender handlers:
  - `0x0052e850` high-probability `SelectMale` / `SetMaleGender`: sets dialog gender byte `+633 = 0`, calls `0x00501620` on child slot `6`, then directly writes child slot `7 +0x10c = 0`, refreshes face, and calls preview gender helper `0x00501b00`.
  - `0x0052e8c0` high-probability `SelectFemale` / `SetFemaleGender`: sets dialog gender byte `+633 = 1`, calls `0x00501640` on child slot `6`, then directly writes child slot `7 +0x10c = 1`, refreshes face, and calls preview gender helper `0x00501b20`.

This resolves the old shallow "style/gender unknown" question: `+0x10c` is a style/table bank selected by dialog gender controls. The source-facing name can be `m_genderStyle`, `m_styleMode`, or `m_partTableBank`; `m_genderStyle` is the best current name because the dialog gender handlers choose it.

## Method Shape

Constructor:

- Source-facing signature direction:
  - `UserHairSelectControlPane(short initialHairSlot, unsigned char hairColor, unsigned char genderStyle, const RectBounds *bounds, unsigned char paneFlag)`
  - If project style uses references, `const RectBounds& bounds` is also plausible; binary passes a pointer.
- Behavior:
  - Chains to `ControlPane::ControlPane(this, 8, bounds)`.
  - Stores base flag at inherited `+0xff`.
  - Stores selected hair, style/gender bank, and hair color.
  - Installs three vptrs.
  - Sets `m_gridColumns = 9`.
  - Copies constructor rect into `m_gridHitRect`, normalizes to `{0,0,width,height}`.
  - Seeds the two-bank 36-entry hair part table.
  - Clears `+0x108` and `m_mouseTracking`.

`OnMouseEvent`:

- Source-facing name: `bool UserHairSelectControlPane::OnMouseEvent(const MouseEvent& event)` or local project event type equivalent.
- Compiled receiver is the `+0xa0` secondary base; source should still be the class virtual override.
- Behavior:
  - Copies normalized hit rect from complete object `+0x15c`.
  - Calls point-in-rect helper `0x004b7e80` with event coordinates and the local hit rect.
  - If inside and event kind byte is `1`, sets `m_mouseTracking = 1` and selects.
  - If inside and event kind byte is `0` while tracking is true, selects.
  - If outside and event kind byte is `1`, clears tracking and consumes the event.
  - Otherwise delegates to inherited/base event handler `0x00544db0`.
- Open naming caveat: existing project notes use `SelectHairAtPoint(mouseY, mouseX)` because `SelectHairAtPoint` divides its second argument by `82` and first argument by `58`. Keep coordinate names consistent with the existing project event layout, but avoid claiming original field names until the common event struct is finalized.

`OnPaintFrame`:

- Source-facing name: `void UserHairSelectControlPane::OnPaintFrame()` or existing project paint override spelling.
- Behavior:
  - Initializes two temporary EPF/frame contexts.
  - Prepares the Pane/GrafPort draw context and render callbacks.
  - Uses `m_gridColumns`, two rows, cells `82 x 58`.
  - For each cell, reads `m_hairPartFrames[m_genderStyle][row * 9 + col]`.
  - Calls NewHumanImageLib with part type `5` and variant/mode arguments, draws through palette category `14` using `m_hairColor >> 5` and render callbacks.
  - Loads/draws selected marker from `USERPART.EPF` / `USERPART.PAL`, centered over selected cell derived from `m_selectedHairSlot`.

`SelectHairAtPoint`:

- Source-facing signature: `void UserHairSelectControlPane::SelectHairAtPoint(int mouseY, int mouseX)` pending final event coordinate type names.
- Raw disassembly proves:
  - column = `max(0, mouseX / 82)`, clamped to `m_gridColumns - 1`.
  - row = `max(0, mouseY / 58)`, clamped to `1`.
  - `m_selectedHairSlot = row * m_gridColumns + column`.
  - Invalidates inherited bounds via primary vtable slot `+0x20` with `this + 0x44`. Do not describe this as a direct `OnPaintFrame()` call in final source.

Style helpers:

- `0x00501620`: source-facing best name `UserHairSelectControlPane::SetMaleStyleMode()` or `SetGenderStyleMale()`. Body sets `m_genderStyle = 0` and invalidates.
- `0x00501640`: source-facing best name `UserHairSelectControlPane::SetFemaleStyleMode()` or `SetGenderStyleFemale()`. Body sets `m_genderStyle = 1` and invalidates.
- Confidence: medium-high for hair ownership due current exported caller evidence; exact original names are inferred. If future live IDA finds non-hair direct callers, prefer a shared descriptive helper name such as `SetAppearancePartTableBank0/1`, but do not leave them documented solely as `UserShapeSelectControlPane` helpers.

Destructor/thunk policy:

- `0x005025d4`: compiler-generated secondary-base deleting destructor adjustor; no source body.
- `0x005025df`: compiler-generated tertiary-base deleting destructor adjustor; no source body.
- `0x00502d90`: MSVC scalar deleting destructor wrapper; no hand-authored source body. Source-facing destructor should be implicit/defaulted or at most `virtual ~UserHairSelectControlPane() {}` if a declaration is needed to produce the vtable.
- Exact wrapper disassembly:
  - calls base destructor at `0x00544580`.
  - if `(flags & 1) == 0`, returns `this`.
  - if `(flags & 4) == 0`, calls `0x004f4ac0(this)` and returns `this`.
  - if `(flags & 4) != 0`, pushes `0x16c` and `this`, calls guard helper `0x0041b6a0`, then returns `this`.

## Heuristic / Inference Reanalysis And Validation

### Source Placement

Best direction: keep `UserHairSelectControlPane` in [UID:0000OX] `UserCreateAppearanceControls`.

Evidence:

- Direct constructor caller is `CreateUserDialogPane::CreateUserDialogPane`, but the same source family already owns hair selector, face selector, preview, and color-list controls.
- Source parent [UID:0000OX] is `87/85` and already projects to `NexusTK/login/UserCreateAppearanceControls.cpp`.
- The old appearance controls form a cohesive companion group with matching constructor patterns, vtables, destructor wrappers, and dialog callbacks.
- `CreateUserDialogs` is a higher umbrella and documents that these controls route through `UserCreateAppearanceControls`.

Rejected alternatives:

- `CreateUserDialogs` or `CreateUserDialogPane.cpp`: plausible original private-file alternative because current direct construction is old dialog-only for hair, but it would collapse companion controls into a broad dialog owner and conflict with existing source-family split. Keep as source-layout caveat, not a blocker.
- `UserCreateAppearanceSelectorControls` aggregate as direct owner: rejected as a final source owner because the aggregate mixes multiple classes, preview, color lists, style helpers, and compiler glue. It is useful support and may need exact child splits, but not the class owner.
- `CANONICAL_OWNER:NONE` / non-emitting: rejected. The class is source-authored, reconstructable, has a valid emitter route, and has enough behavior/layout evidence.
- `UserShapeSelectControlPane`: rejected for `0x00501620/40` based on current old-dialog caller facts. The existing shape docs likely inherited stale/generated helper ownership.

### Compiler-Generated Names And Raw Names

Recommended IDA/source names:

| Raw name/address | Recommended descriptive name | Confidence |
| --- | --- | --- |
| `sub_501150` / `UserHairSelectControlPane` | `UserHairSelectControlPane::UserHairSelectControlPane` | High |
| `sub_5012B0` / `virt_meth_0x5012b0` | `UserHairSelectControlPane::OnMouseEvent` | High, with secondary-base receiver note |
| `sub_501360` / `virt_meth_0x501360` | `UserHairSelectControlPane::OnPaintFrame` | High |
| `sub_501590` / `meth_0x501590` | `UserHairSelectControlPane::SelectHairAtPoint` | High |
| `sub_501620` | `UserHairSelectControlPane::SetMaleStyleMode` / `SetGenderStyleMale` | Medium-high |
| `sub_501640` | `UserHairSelectControlPane::SetFemaleStyleMode` / `SetGenderStyleFemale` | Medium-high |
| `sub_5025D4` | generated deleting-destructor adjustor from `+0xa0` base | High, no source C++ |
| `sub_5025DF` | generated deleting-destructor adjustor from `+0xa4` base | High, no source C++ |
| `sub_502D90` | MSVC scalar deleting destructor wrapper for `~UserHairSelectControlPane` | High, no wrapper C++ |
| `vftable_0061dd7c` | `UserHairSelectControlPane` primary vtable | High |
| `vftable_0061dde4` | `UserHairSelectControlPane` secondary/event-base vtable | High |
| `vftable_0061de14` | `UserHairSelectControlPane` tertiary/base vtable | High |

### Field/Type Names

Best names are listed in the field table above. Only three items should remain explicitly provisional:

- `+0xff`: inherited/base flag name depends on the recovered `ControlPane`/`Pane` layout.
- `+0x108`: constructor-zeroed byte with no checked reader. Leave documented as unresolved/reserved.
- event struct fields and enum names: behavior is known, but exact source enum names for event kind `0` and `1` should be synchronized with the common UI event documentation.

### Split / Merge / Range

No direct split is required during this report-only pass. However:

- The broad by-memory aggregate [UID:0001A6] should be corrected because it currently labels `0x00501620/40` as `UserShapeSelectControlPane` male/female helpers.
- If the supervisor wants formal method-body C++ rather than a class declaration only, create exact by-memory children for the hair class methods:
  - `0x00501150-0x005012af.UserHairSelectControlPaneConstructor`
  - `0x005012b0-0x0050135a.UserHairSelectControlPaneOnMouseEvent`
  - `0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame`
  - `0x00501590-0x00501612.UserHairSelectControlPaneSelectHairAtPoint`
  - `0x00501620-0x00501631.UserHairSelectControlPaneSetMaleStyleMode`
  - `0x00501640-0x00501651.UserHairSelectControlPaneSetFemaleStyleMode`
- Do not fold destructor thunks or scalar deleting destructor into source method bodies.

### Final C++ Gate

The target already has a valid emitter route and the recommended score `87/90` averages `88.5`. It qualifies for first-draft code under current gate. The code should remain below final-audit confidence because:

- class pages should generally emit declaration-level code, while exact method bodies are better emitted by exact by-memory children;
- the event type names and render helper APIs are still descriptive;
- `+0x108` field role is unresolved;
- original source split `UserCreateAppearanceControls.cpp` vs private `CreateUserDialogPane.cpp` is likely but not proven.

These caveats cap the score but do not justify a blank C++ block solely due the obsolete `95/95` rule.

## Ranked Ownership Analysis

### 1. [UID:0000OX] UserCreateAppearanceControls

- Evidence for: existing file route, companion old appearance controls, constructor and callback grouping, valid generated path, parent clears gate, source family already includes this class.
- Evidence against: hair selector appears old-dialog-only in currently checked direct constructor xrefs.
- Decision: accepted. Keep canonical owner/emitter `0000OX`.

### 2. [UID:0000IK] CreateUserDialogs / CreateUserDialogPane family

- Evidence for: sole constructor caller is old `CreateUserDialogPane`; dialog owns slot semantics and preview propagation.
- Evidence against: broader umbrella, companion appearance controls already split into a dedicated source family, and `UserShapeSelectControlPane` reuse argues against collapsing all appearance controls into the dialog source file.
- Decision: rejected as direct owner; keep as alternate/source-layout caveat and cross-reference.

### 3. [UID:0001A6] UserCreateAppearanceSelectorControls aggregate

- Evidence for: exact executable aggregate contains hair, face, preview, and color-list functions.
- Evidence against: mixed class/method aggregate, not a single source declaration owner, currently code marker only, and contains stale helper ownership.
- Decision: support/container only; update evidence but do not make it direct class owner.

### 4. No-owner / non-emitting

- Evidence for: none after current recheck except final original file-name uncertainty.
- Evidence against: source-authored methods, valid owner/emitter route, vtables and direct callers, layout and behavior resolved enough for source draft.
- Decision: rejected.

## First-Draft C++ Recommendation

Formal target recommendation:

- Prefer placing declaration-level code on the class page and method-body code on exact by-memory method children if those children are created.
- If supervisor elects to populate the current class page without splitting, include the source-shaped methods below as a first draft and mark helper/API names as descriptive where needed.
- Do not include `sub_5025D4`, `sub_5025DF`, or scalar deleting wrapper code.

Declaration-level draft:

```cpp
class UserHairSelectControlPane : public ControlPane {
public:
    UserHairSelectControlPane(short initialHairSlot,
                              unsigned char hairColor,
                              unsigned char genderStyle,
                              const RectBounds *bounds,
                              unsigned char paneFlag);

    virtual ~UserHairSelectControlPane() {}

    virtual bool OnMouseEvent(const MouseEvent &event);
    virtual void OnPaintFrame();

    void SelectHairAtPoint(int mouseY, int mouseX);
    void SetMaleStyleMode();
    void SetFemaleStyleMode();

private:
    unsigned char m_reserved108;
    short m_selectedHairSlot;
    unsigned char m_genderStyle;
    unsigned char m_hairColor;
    unsigned char m_mouseTracking;
    unsigned short m_hairPartFrames[2][18];
    unsigned char m_gridColumns;
    RectBounds m_gridHitRect;
};
```

Source-body draft for method-level children or a richer class page:

```cpp
static const unsigned short kHairPartFrames[2][18] = {
    { 2, 60, 1, 8, 34, 48, 80, 36, 3, 83, 0, 15, 17, 24, 49, 71, 51, 59 },
    { 33, 74, 78, 50, 91, 10, 31, 4, 7, 45, 5, 13, 25, 54, 65, 80, 52, 58 }
};

UserHairSelectControlPane::UserHairSelectControlPane(short initialHairSlot,
                                                     unsigned char hairColor,
                                                     unsigned char genderStyle,
                                                     const RectBounds *bounds,
                                                     unsigned char paneFlag)
    : ControlPane(8, bounds),
      m_reserved108(0),
      m_selectedHairSlot(initialHairSlot),
      m_genderStyle(genderStyle),
      m_hairColor(hairColor),
      m_mouseTracking(0),
      m_gridColumns(9)
{
    m_controlFlag = paneFlag; // Use the recovered inherited field name when available.

    m_gridHitRect = *bounds;
    m_gridHitRect.right -= m_gridHitRect.left;
    m_gridHitRect.bottom -= m_gridHitRect.top;
    m_gridHitRect.left = 0;
    m_gridHitRect.top = 0;

    memcpy(m_hairPartFrames, kHairPartFrames, sizeof(m_hairPartFrames));
}

bool UserHairSelectControlPane::OnMouseEvent(const MouseEvent &event)
{
    if (PointInRect(event.mouseY, event.mouseX, m_gridHitRect)) {
        if (event.kind == 1) {
            m_mouseTracking = 1;
        } else if (event.kind != 0 || !m_mouseTracking) {
            return ControlPane::OnMouseEvent(event);
        }

        SelectHairAtPoint(event.mouseY, event.mouseX);
        return true;
    }

    if (event.kind == 1) {
        m_mouseTracking = 0;
        return true;
    }

    return ControlPane::OnMouseEvent(event);
}

void UserHairSelectControlPane::SelectHairAtPoint(int mouseY, int mouseX)
{
    int column = mouseX >= 0 ? mouseX / 82 : 0;
    if (column >= m_gridColumns) {
        column = m_gridColumns - 1;
    }

    int row = mouseY >= 0 ? mouseY / 58 : 0;
    if (row > 1) {
        row = 1;
    }

    m_selectedHairSlot = static_cast<short>(row * m_gridColumns + column);
    InvalidateRect(m_bounds);
}

void UserHairSelectControlPane::SetMaleStyleMode()
{
    m_genderStyle = 0;
    InvalidateRect(m_bounds);
}

void UserHairSelectControlPane::SetFemaleStyleMode()
{
    m_genderStyle = 1;
    InvalidateRect(m_bounds);
}
```

Paint method draft should be added only after matching project helper names are chosen for EPF contexts, NewHumanImageLib part drawing, PaletteLib lookup, and surface render callbacks. Current source-shaped pseudocode:

```cpp
void UserHairSelectControlPane::OnPaintFrame()
{
    EPFFrameContext partFrame;
    EPFFrameContext selectionFrame;

    BeginControlPaint(false);
    LockRenderTargetForPane();

    for (int row = 0; row < 2; ++row) {
        for (int column = 0; column < m_gridColumns; ++column) {
            RectBounds cell(column * 82, row * 58,
                            column * 82 + 82, row * 58 + 58);
            const unsigned short partFrameId =
                m_hairPartFrames[m_genderStyle][row * m_gridColumns + column];

            g_pNewHumanImageLib->LoadPartFrameDrawRecord(5, partFrameId, 2, 0, partFrame);
            CenterPartFrameInCell(partFrame, cell);
            DrawPartFrame(partFrame, g_pPaletteLib->GetPalette(14, 0, m_hairColor >> 5));
        }
    }

    g_pEPFLib->LookupLayoutEntry(L"USERPART.EPF", 0, selectionFrame);
    RectBounds selectedCell((m_selectedHairSlot % m_gridColumns) * 82,
                            (m_selectedHairSlot / m_gridColumns) * 58,
                            (m_selectedHairSlot % m_gridColumns) * 82 + 82,
                            (m_selectedHairSlot / m_gridColumns) * 58 + 58);
    CenterSelectionFrameInCell(selectionFrame, selectedCell);
    DrawFrame(selectionFrame, L"USERPART.PAL");
}
```

This paint draft is intentionally not ready for final formal insertion until helper names/types are aligned with existing render docs. It is still useful as first-draft source shape and should replace the stale "no C++ because below 95" rationale.

## Recommended Exact Target Changes

`by-class/UserHairSelectControlPane.md`:

- Change metadata:
  - `COMPLETION:87`
  - `CONFIDENCE:90`
  - Keep `CANONICAL_OWNER:0000OX`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OX`.
- Replace stale no-C++/below-95 wording with current gate analysis:
  - The class is eligible under the current average >85 + emitter route gate.
  - Formal output should not include compiler-generated thunk or scalar deleting destructor wrapper code.
  - If method bodies are considered too detailed for class page policy, emit a class declaration and create exact by-memory method children for bodies.
- Add current constructor signature and caller evidence:
  - `UserHairSelectControlPane(short initialHairSlot, unsigned char hairColor, unsigned char genderStyle, const RectBounds *bounds, unsigned char paneFlag)`
  - `CreateUserDialogPane::CreateUserDialogPane` allocation `0x16c`, call args `rand()%10`, `12`, `0`, rect `(170,342,926,477)`, flag `0`.
- Add a field/layout table with offsets from this report.
- Add grid/table constants:
  - columns `9`, rows `2`, cell `82 x 58`, hit rect normalized copy at `+0x15c`.
  - two 18-entry `uint16_t` banks exactly as decoded above.
- Add style/gender helper rows:
  - `0x00501620-0x00501631` `SetMaleStyleMode` / `SetGenderStyleMale`
  - `0x00501640-0x00501651` `SetFemaleStyleMode` / `SetGenderStyleFemale`
- Correct `SelectHairAtPoint` description:
  - clamp column from `mouseX / 82`;
  - clamp row from `mouseY / 58`;
  - write `+0x10a`;
  - invalidate `this+0x44`, not direct paint call.
- Add multiple-inheritance/vtable note:
  - primary `0x0061dd7c`, secondary `0x0061dde4` at complete-object `+0xa0`, tertiary `0x0061de14` at `+0xa4`.
  - `OnMouseEvent` is a secondary-base virtual but source-facing class method.
- Add destructor no-code proof:
  - thunks are `sub ecx,0xa0/a4; jmp 0x00502d90`;
  - scalar deleting wrapper calls `0x00544580`, handles flags `1/4`, calls `0x004f4ac0` or guard helper with object size `0x16c`;
  - source destructor implicit/defaulted.
- Add raw PE evidence:
  - raw offsets, padding facts, vtable refs, rel32 refs, and VA pointer refs summarized above.
- Add score rationale:
  - `84/88 -> 87/90` due raw PE exactness, field/table resolution, dialog caller semantics, style helper resolution, vtable/thunk no-code proof, owner/emitter validation, and first-draft C++ readiness.
  - Confidence capped below final audit by original source-file split, final event enum/helper spellings, render helper names, and unresolved `+0x108`.

## Support-Doc Update Checklist

Required or strongly recommended support changes if supervisor accepts this report:

- [UID:0000OX] `by-file/UserCreateAppearanceControls.md`
  - Add `UserHairSelectControlPane` method contents at report detail, including `0x00501620/40` style helpers.
  - Remove or qualify the current `UserShapeSelectControlPane` row claim that `0x00501620/40` are shape helpers.
  - Preserve source route `NexusTK/login/UserCreateAppearanceControls.cpp`.
- [UID:0001A6] `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md`
  - Relabel rows `0x00501620-0x00501631` and `0x00501640-0x00501651` from `UserShapeSelectControlPane` male/female mode helpers to old appearance/hair selector style-mode helpers, with caller evidence from `0x0052e850` and `0x0052e8c0`.
  - Add raw padding facts for `0x00501612-0x00501620`, `0x00501631-0x00501640`, and `0x00501651-0x00501660`.
  - Add field/table summary for hair selector or point to target class page.
- [UID:0000FR] `by-class/UserShapeSelectControlPane.md`
  - Remove `0x00501620/40` as class method rows or mark them as stale/cross-owner until contrary caller evidence is found.
  - Keep the real shape gender helpers at `0x004fd030/0x004fd050`; those switch shape `+0x10e` and are distinct from the old hair selector `+0x10c` helpers.
- [UID:0000FJ] `by-class/UserFaceSelectControlPane.md`
  - Add parallel note: face selector `+0x10c` is style/gender bank, but old dialog updates it inline rather than through `0x00501620/40`; `+0x10d` is face color; table has `6 x 2`, 12 entries per bank.
- [UID:0000FH] `by-class/UserCreatePreviewControlPane.md`
  - Add preview update contract from `0x0052ea80`: `(faceFrame, faceColor, hairFrame, hairColor, gender)`, with hair frame formula using `selectedHair + 18 * hairStyle`.
- [UID:00003B] `by-class/CreateUserDialogPane.md` and/or [UID:0000IJ] `by-file/CreateUserDialogPane.md`
  - Add child-slot semantics: slot `6` hair selector, slot `7` face selector, slot `18` preview.
  - Add `SetHairColorIndex` writes child slot `6 +0x10d`.
  - Add gender handlers route to `0x00501620/40`, face inline `+0x10c`, and preview gender update.
- [UID:0001AF] `by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md`
  - Already mostly correct; optionally add this report's raw bytes and exact vtable refs for the hair pair.
- [UID:00022X] `by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md`
  - Already mostly correct; optionally add the object-size `0x16c` for `UserHairSelectControlPane` flag-4 guard branch if not already present.
- Read-only/vtable support:
  - Add a small `UserHairSelectControlPane` vtable note to `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` or a future exact vtable child if split: primary `0x0061dd7c`, secondary `0x0061dde4`, tertiary `0x0061de14`, key slots as above.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` directly. Supervisor-owned replacement text if support aggregate row is updated:

```text
        - [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) 0x00501150-0x00502383 | class method cluster | UserCreateAppearanceSelectorControls : reconstructable : 85% : strong : Live/exported IDA plus raw PE recheck confirms the 21 selector, preview, and color-list functions, exact padding around the old hair selector methods, constructor/callback xrefs from create-user code, vtable-only paint/mouse routes, image/palette/render dependencies, and corrected `0x00501620`/`0x00501640` semantics as old hair selector style-mode helpers used by dialog gender controls rather than standalone shape-selector methods.
```

Recommended `by-class/-coverage-report.md` replacement row for the target:

```text
- [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) : reconstructable : 87% : very strong : B009 source-quality recheck resolves the old hair selector as source-authored create-user appearance code under [UID:0000OX], with constructor caller/0x16c allocation, 9x2 grid constants, decoded two-style 18-entry hair-part table, selected slot/color/gender-style/tracking fields, secondary-base mouse-event route, preview/update caller semantics, generated destructor/thunk no-code policy, and first-draft class/method C++ readiness; remaining caveats are exact original source-file split, final event/helper spellings, render helper type names, and unused byte +0x108.
```

Generated coverage expectation after implementation:

- `auto-generated/-ag-class-coverage.md` should change UID `0000FL` from `Completion:84 Confidence:88 code:no` to a code-bearing or declaration-bearing row if formal C++ is inserted.
- If supervisor chooses class declaration only, generated output should contain class-level code for UID `0000FL` and leave method bodies to future exact by-memory children.

## Validator Needs

No validators were run because this is a report-only pass and no by-* docs were edited.

Required implementation validation commands from `E:\NTK\GhidraBridge\source-3\project-documentation` if edits are accepted:

> Executable block R001 was removed from this report and preserved verbatim in [0000FL-UserHairSelectControlPane-source-quality-removed.md](0000FL-UserHairSelectControlPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run validators for support docs actually edited. Do not validate or edit `by-memory/-coverage-report.md` as B009 unless the supervisor explicitly lifts the ban.

Recommended live/manual validation if IDA MCP becomes available:

- `lookup_funcs` for `0x00501150`, `0x005012b0`, `0x00501360`, `0x00501590`, `0x00501620`, `0x00501640`, `0x005025d4`, `0x005025df`, `0x00502d90`.
- `xrefs_to` for `0x00501620` and `0x00501640` to confirm no non-hair callers.
- `decompile` for `0x0052e850`, `0x0052e8c0`, and `0x0052ea80` to reconfirm child slots `6`, `7`, `18`.
- `get_global_value`/`py_eval` for vtable dwords at `0x0061dd7c`, `0x0061dde4`, `0x0061de14`.
- `get_bytes` around `0x00501612-0x00501660` and `0x00502d90-0x00502dd0` to match raw PE padding if desired.

## IDA Rename / Type / Comment Recommendations

High-confidence names:

- `sub_501150` -> `UserHairSelectControlPane::UserHairSelectControlPane`
- `sub_5012B0` -> `UserHairSelectControlPane::OnMouseEvent`
- `sub_501360` -> `UserHairSelectControlPane::OnPaintFrame`
- `sub_501590` -> `UserHairSelectControlPane::SelectHairAtPoint`
- `sub_5025D4` -> `UserHairSelectControlPane::deletingDestructorAdjustor_a0` or leave generated with comment
- `sub_5025DF` -> `UserHairSelectControlPane::deletingDestructorAdjustor_a4` or leave generated with comment
- `sub_502D90` -> `UserHairSelectControlPane::scalarDeletingDestructor` / `??_GUserHairSelectControlPane`

Medium-high confidence names:

- `sub_501620` -> `UserHairSelectControlPane::SetMaleStyleMode` or `SetGenderStyleMale`
- `sub_501640` -> `UserHairSelectControlPane::SetFemaleStyleMode` or `SetGenderStyleFemale`

Recommended comments:

- At `0x005012b0`: `Receiver is +0xa0 secondary base; complete UserHairSelectControlPane is ecx-0xa0. Hit rect at complete +0x15c, tracking byte at complete +0x10e.`
- At `0x00501620`: `Old create-user hair selector style/gender bank setter: writes +0x10c=0, invalidates +0x44; called from CreateUserDialogPane male handler.`
- At `0x00501640`: `Old create-user hair selector style/gender bank setter: writes +0x10c=1, invalidates +0x44; called from CreateUserDialogPane female handler.`
- At `0x005025d4` and `0x005025df`: `MSVC secondary-base deleting destructor adjustor thunk; generated, no handwritten source body.`
- At `0x00502d90`: `MSVC scalar deleting destructor wrapper for default/implicit UserHairSelectControlPane destructor; object size 0x16c on flag-4 path; source should not hand-call delete.`

Type recommendations:

- `m_selectedHairSlot`: `int16_t` / `short`.
- `m_genderStyle`: `uint8_t` / `unsigned char`, values `0` and `1`.
- `m_hairColor`: `uint8_t` / `unsigned char`.
- `m_mouseTracking`: `uint8_t` / `bool` if project convention permits.
- `m_hairPartFrames`: `uint16_t[2][18]`.
- `m_gridColumns`: `uint8_t`.
- `m_gridHitRect`: `RectBounds`.

## Remaining Open Questions

- Exact original source file: `UserCreateAppearanceControls.cpp` is the best current reconstruction bucket; original code may have placed old selector classes inside `CreateUserDialogPane.cpp`. This affects source-placement confidence but not owner/emitter under current docs.
- Exact event type names: event byte `1` starts/clears tracking and byte `0` continues selection while tracking. Synchronize with the common mouse-event enum before final code naming.
- Exact coordinate field names: the project has historical notes favoring `SelectHairAtPoint(mouseY, mouseX)`. The raw function itself proves only which argument divides by `58` vs `82`.
- `+0x108` byte role: constructor zeroes it, but no checked target/caller path uses it. Leave explicitly unresolved/reserved.
- Exact `0x00501620/40` original names: current evidence supports hair/gender-style helpers; if future xrefs prove shared use, use a generic appearance-selector style-bank name rather than shape-only ownership.
- Exact render helper API names/types for `OnPaintFrame`: behavior is clear, but final source should reuse the project's established EPF/NewHumanImageLib/PaletteLib wrapper names.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0000FL-UserHairSelectControlPane-source-quality.md`
- Modified: none
- Moved/archived: none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0000FL-UserHairSelectControlPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0000FL"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000FL-UserHairSelectControlPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0000FL-UserHairSelectControlPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000FL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
