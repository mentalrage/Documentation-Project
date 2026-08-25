*** UID:0000FR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../ui/controls/ListPane.h"
#include "../ui/core/ControlPane.h"
#include "../ui/core/RectBounds.h"

class CreateUserDialogPane;
struct HumanImageRenderParams;
struct MouseEvent;
struct UserCreateColorSwatchItem;

class UserShapeSelectControlPane : public ControlPane
{
public:
    UserShapeSelectControlPane(short initialShapeIndex,
                               bool useMaleShapeBank,
                               const RectBounds *bounds,
                               unsigned char controlFlags);
    virtual ~UserShapeSelectControlPane() {}

    virtual bool OnTimerEvent(int timerId, int, int);
    virtual bool OnMouseEvent(const MouseEvent *event);
    virtual void OnPaint();

    HumanImageRenderParams *BuildPreviewParams(
        HumanImageRenderParams *outParams) const;
    void SetMaleShapeBank();
    void SetFemaleShapeBank();
    short StepShapeForward();
    short StepShapeBackward();
    bool IsSelected() const;
    void SetSelected(bool selected);

private:
    unsigned short m_reservedShapeState;
    unsigned short m_shapeIndexLimit;
    short m_selectedShapeIndex;
    unsigned short m_shapeBank;
    unsigned short m_animationFrame;
    unsigned short m_direction;
    unsigned short m_animationTick;
    bool m_selected;
    unsigned short m_shapeSpriteIds[2][10];
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserShapeSelectControlPane

## Status

- Confidence: very strong for the complete source-ready declaration, exact `0x140` layout, local behavior, exact core child route, virtual method set, and short step-result contract; final original member/type spellings remain descriptive.
- Likely source file: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- Current recovered file: `source-3/simroot_v2/class_UserShapeSelectControlPane.cpp`
- Primary ranges: [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md) and [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- Parent route: this class attaches to [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md); this page emits the complete declaration at source position `0`, and the exact source-ready core method island [UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md) attaches here at source position `10`.

## Class Purpose

`UserShapeSelectControlPane` is a `0x140`-byte `ControlPane`-derived body-shape preview/selection control used by both old and alternate create-user dialogs. It stores male/female sprite tables, the selected signed-short shape index, direction/frame/tick state, and a selected-state byte, and it draws a centered body preview through the sprite library. Its complete declaration is in formal H at source position `0`; formal CPP retains only `[[CHILDREN]]` for exact method definitions, while deleting wrappers, adjustors, and vtable data remain compiler-only.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetSelectionValue` | `0x004fcd80-0x004fcda4` | Stores a selected option value and refreshes when it changes. |
| constructor | `0x004fce80-0x004fcfb5` | Builds the control, starts the `0xc8` / 200 ms timer, and seeds two body-shape sprite-id tables (Verified with int_convert.py). |
| `BuildPreviewParams` | `0x004fcfc0-0x004fd02a` | Builds the body-preview render params/descriptor for the current shape bank/index; callers serialize packets separately. Paint calls this helper before bounds and draw calls, and dialog packet paths call it before writing opcode `4` payload fields. |
| `SetMaleShapeBank` | `0x004fd030-0x004fd043` | Stores bank `0` at `+0x10e` / 270 and invalidates. |
| `SetFemaleShapeBank` | `0x004fd050-0x004fd066` | Stores bank `1` at `+0x10e` / 270 and invalidates. |
| `StepShapeForward` | `0x004fd070-0x004fd0c9` | Advances shape index at `+0x10c` / 268, invalidates, and returns `-1` on the edge transition from `8` to `9`. |
| `StepShapeBackward` | `0x004fd0d0-0x004fd126` | Decrements shape index at `+0x10c` / 268, invalidates, and returns `-1` on the edge transition from `1` to `0`. |
| `IsSelected` | `0x004fd130-0x004fd137` | Retained no-xref selected-state getter returning byte `+0x116` / 278; live IDA models this as a 7-byte function, not padding. |
| `SetSelected` | `0x004fd140-0x004fd164` | Toggles byte `+0x116` / 278 and refreshes only when the value changes. |
| `OnTimerEvent` | `0x004fd170-0x004fd1de` | Vtable-only timer handler; advances frame/tick/direction state, rolls direction after 16 ticks, invalidates, and restarts the `0xc8` / 200 ms timer. |
| `OnMouseEvent` | `0x004fd1e0-0x004fd228` | Vtable-only mouse handler; tracks mouse event type `3`, hit-tests through `sub_4B7E80`, sets selected state, and invalidates on entry. |
| `OnPaint` | `0x004fd230-0x004fd520` | Vtable-only paint; branches on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), uses [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) to populate `EPFTileContext::bounds` for the optional frame, then measures and renders body preview through [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md). |
| historical stale `SetMaleMode` / `SetFemaleMode` attribution | `0x00501620`, `0x00501640` | Rejected for this class. B007/B009 caller evidence routes these helpers to [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) control id `6`; the real shape gender/table helpers are `0x004fd030` and `0x004fd050`, which switch shape `+0x10e`. |
| historical stale `SetActive` attribution | `0x0054b700-0x0054b719` | Rejected for this class. Exact [UID:0004E5][0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder](by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md) writes PrettyButton `m_selected` at `+0x118` and invalidates; NewUserDialogPane2 gender selectors call it on button ids `4/5`, not UserShape objects. |
| destructor/thunks | [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md), `0x00502dd0` | Adjustor thunks are ignored compiler support; `0x00502dd0` is the scalar deleting destructor wrapper for implicit/defaulted source destructor `UserShapeSelectControlPane::~UserShapeSelectControlPane()`. No derived cleanup body is proven; base `Pane::~Pane()`, delete flags, and `operator delete` are compiler/base output. |

## NewUserDialogPane2 Gender-Bank Callers

- [UID:00043R][0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode](by-memory/0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode.md) calls `SetMaleShapeBank()` on exact UserShape children `8`, `9`, `10`, and `11` in literal order. Its exact 136-byte body has SHA256 `318E714C08908DCE721179A703BFBCBED42A2FF353F4D0A7EE03A18D3176F109` and constructor/command-id-`4` callers.
- [UID:00043S][0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode](by-memory/0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode.md) is the exact symmetric caller of `SetFemaleShapeBank()` on children `8-11`; its 136-byte body has SHA256 `F9C237761B1388EEF54ED332579E1FFF9715284DF6FBA40F0E81BAF00C1B0135` and constructor/command-id-`5` callers.
- `SetMaleShapeBank()` at `0x004fd030` stores bank `0` at `+0x10e`; `SetFemaleShapeBank()` at `0x004fd050` stores bank `1`. Both invalidate the shape control.
- The dialog methods separately call UID0004E5 on [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md) children `4/5`. That paired evidence closes the historical `0x0054b700` owner pollution: it is not a UserShape method, base-control method, or generic `SetActive` helper.
- The gender methods do not call `SelectShapeSlot`, access the selected-slot field, or synthesize a loop. Their source-ready bodies use inherited typed lookup and four explicit bank calls.

## Source Field Map

| Offset | Source-facing field | Evidence |
| --- | --- | --- |
| `+0xff` | `m_controlFlags` | Constructor stores the fifth argument directly. |
| `+0x108` | `m_reservedShapeState` | Constructor clears it; no current reader is proven. |
| `+0x10a` | `m_shapeIndexLimit` / fixed last shape index | Constructor writes `9`; steppers operate within the same `0..9` range. |
| `+0x10c` | `m_selectedShapeIndex` | Constructor argument; steppers mutate it; `BuildPreviewParams` indexes the sprite table with it. |
| `+0x10e` | `m_shapeBank` | Male/primary bank `0`, female/secondary bank `1`; bank setters and preview builder consume it. |
| `+0x110` | `m_animationFrame` | Timer increments modulo four and paint passes it into preview rendering. |
| `+0x112` | `m_direction` | Constructor seeds `2`; timer advances it every sixteen ticks; paint consumes it. |
| `+0x114` | `m_animationTick` | Timer counter reset after reaching `16`. |
| `+0x116` | `m_selected` | Getter, setter, mouse handler, and paint consume this selected-pane byte. |
| `+0x117` | implicit alignment padding | Natural one-byte alignment before the two-dimensional `unsigned short` sprite table; no authored reserve member is claimed. |
| `+0x118..+0x12b` | `m_shapeSpriteIds[0][10]` | Bank 0: `{2, 60, 1, 8, 34, 48, 80, 36, 3, 83}`. |
| `+0x12c..+0x13f` | `m_shapeSpriteIds[1][10]` | Bank 1: `{33, 74, 78, 50, 91, 10, 31, 4, 7, 45}`. |

## Evidence Notes

- IDA MCP confirms all listed starts.
- 2026-06-25 B007 live IDA MCP rework confirms the core range [UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md) as eleven modeled functions with exact starts/sizes from `0x004fce80` through `0x004fd230`, including the retained no-xref `IsSelected` getter at `0x004fd130-0x004fd137`, raw `0xcc` padding between methods, and immediate successor `0x004fd520`.
- `trace_data_flow 0x004fce80 backward depth 1` reports eight constructor call sites: four inside [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md) and four inside `0x0052a540` (`NewUserDialogPane2` path), so this class is reusable within the create-user family.
- 2026-06-13 live IDA MCP `analyze_function` confirms helper fanout from `0x004fc010`, `0x004fc5f0`, `0x0052b090`, `0x0052b1d0`, `0x0052b470`, `0x0052b530`, and `0x0052bdd0`; those callers use the descriptor, table-selector, active-state, and forward/backward selection helpers as class methods.
- 2026-06-13 live IDA MCP `get_global_value` confirms representative vtable slots for this class: primary table entries `0x0061d564 -> 0x00502dd0`, `0x0061d568 -> 0x004f4b10`, secondary/tertiary entries `0x0061d5cc -> 0x005025ea`, `0x0061d5d0 -> 0x004fd1e0`, `0x0061d5fc -> 0x005025f5`, `0x0061d600 -> 0x004fd170`, and paint slot `0x0061d5a8 -> 0x004fd230`.
- 2026-06-25 live IDA MCP decompile/disassembly of `0x004fd230` confirms the paint method reads [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97`, uses `USERPART.EPF` / `NEWBUTT.PAL` in the current branch and `CAPSULE.EPD` / `NPAL3.PAL` in the legacy branch, calls `BuildPreviewParams` twice, and reads [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md) / `dword_67A760` at `0x004fd33b`, `0x004fd468`, and `0x004fd4fe`.
- Rework MCP specifically confirms the optional frame's source rectangle is `EPFTileContext::bounds` populated by [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) `LookupLayoutEntry`, not an independent uninitialized local rectangle.
- Rework MCP decompile/disassembly of `0x004fcfc0` confirms `BuildPreviewParams` writes descriptor fields but does not read or clear the descriptor-kind byte at offset `+0x28`; target C++ assigns the kind after each builder call.
- Historical broad `xrefs_to 0x0054b700` evidence was insufficient to assign the helper to this control. Exact UID0004E5 field, paint-reader, class-vtable, and old/new selection-caller evidence now proves `PrettyButtonControlPane::SetSelected(bool)` ownership; UserShape retains only its own `0x004fd140` `SetSelected(bool)` member at offset `+0x116`.
- IDA confirms `0x005025ea` and `0x005025f5` as real 0xb adjustor thunks; `0x005025f5` is a secondary `this - 41` thunk currently marked as missing code in disabled generated output.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x00502dd0` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-06-19 B005 source-quality recheck resolves the destructor-specific C++ policy: the deleting-destructor target is compiler wrapper evidence for an implicit/defaulted ordinary destructor, not a hand-authored source body. `0x00544580` is ordinary `Pane::~Pane()` and `0x004f4ac0` is the MemoryMan-backed global `operator delete` wrapper.
- 2026-06-21 B009 hair-selector recheck confirms the old `0x00501620`/`0x00501640` shape-helper label was historical owner pollution. Current direct callers use old-dialog control id `6`, the bodies write [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) `+0x10c`, and this shape selector's own gender/table switch remains `0x004fd030`/`0x004fd050` on shape offset `+0x10e`.

## Declaration And Direct Parent Gate

[UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md) attaches directly to this `92/93` class page and emits its exact method definitions at position `10`; [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) remains the source-file owner. The class page emits the declaration at position `0`, including the exact virtual contract, public helper signatures, private field order, natural `+0x117` alignment, and `0x140` terminal size. This keeps method ownership under the class instead of attaching source-bearing methods directly to a file fallback. The signed-short return types for `StepShapeForward` and `StepShapeBackward` preserve the callers' `-1` sentinel comparison, while the empty source destructor excludes scalar wrappers, adjustor thunks, base teardown, delete flags, and storage release from handwritten source.

## Cross-References

- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md)
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)
- [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md)

## Changes

- 2026-07-22 B002 UID00043R implementation callback support sync:
  - Kept `92/93`, owner/emitter UID0000OX, declaration, layout, and exact method bodies unchanged.
  - Added UID00043R/UID00043S as exact four-control callers of the male/female bank methods with ranges, hashes, caller roles, child ids, and no-reselect evidence.
  - Reclassified historical `0x0054b700 SetActive` attribution as rejected owner pollution and routed the exact helper to UID0004E5 PrettyButtonControlPane without pruning the prior assumption.

- 2026-07-22 B002 UID00043N implementation callback declaration completion:
  - Raised the class to `92/93`, set source position `0`, and installed the complete `ControlPane`-derived source declaration before `[[CHILDREN]]`.
  - Preserved the exact `0x140` field order, documented implicit `+0x117` alignment without inventing a reserve member, and corrected both shape-step methods to signed-short returns required by the `-1` edge sentinel.
  - Preserved all existing B007/B009 method, vtable, resource, caller, and superseded hair-helper evidence; exact bodies remain on UID0002Q8 at position `10`.

- 2026-06-25 B007 0002Q8 implementation callback sync:
  - Score unchanged.
  - Summary/evidence: synchronized the class method map and field map with accepted [UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md) evidence. The class now names `BuildPreviewParams`, `SetMaleShapeBank`, `SetFemaleShapeBank`, `StepShapeForward`, `StepShapeBackward`, retained no-xref `IsSelected`, `SetSelected`, `OnTimerEvent`, `OnMouseEvent`, and `OnPaint`; records sprite-id banks and selected/timer fields; preserves the `0x00501620`/`0x00501640` hair-selector rejection; and points to the target's source-ready first-draft C++ with the corrected `frameContext.bounds` paint path.
- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the selector, constructor, sprite/shape/timer/paint helpers, shared active-state helper, adjustor thunks, and scalar deleting destructor starts from `0x004fcd80` through `0x00502dd0`; the class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted from this class overview; the exact [UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md) now owns formal first-draft C++.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Historical summary/evidence: scored from the body-shape selector method map, constructor xrefs, timer/paint/sprite behavior, create-user-family reuse notes, and adjustor-thunk/destructor evidence; at that time confidence remained moderate on the source split and then-unresolved `SetActive` ownership. The 2026-07-22 UID00043R pass supersedes that ownership uncertainty with exact PrettyButtonControlPane evidence.
- 2026-06-13 Agent-A002 Goal2 direct-parent refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:82`; [UID:0002Q8][0x004fce80-0x004fd520.UserShapeSelectControlPaneCore](by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md) still attached directly to the file fallback because this class had not cleared `85/85`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, with the core method island documented as a direct child of this class.
  - Summary/evidence: live IDA MCP reconfirmed exact method boundaries, constructor call sites in [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md) and `0x0052a540`, helper caller fanout, vtable slot targets, timer/selection/hover offsets, and the paint path's `byte_66DA97` plus `dword_67A760` dependencies. C++ remains blank because field/descriptor/source-file naming is still below final-source quality.
- 2026-06-21 B009 stale-helper correction:
  - Score unchanged.
  - Summary/evidence: marked the old `0x00501620`/`0x00501640` `SetMaleMode`/`SetFemaleMode` attribution as rejected for this class. Those functions are now documented as [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) gender/style-bank setters, while this class keeps `0x004fd030`/`0x004fd050` as its real source-facing male/female sprite helpers.
