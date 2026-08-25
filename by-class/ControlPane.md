*** UID:000038 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ControlPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "Pane.h"

class Event;
struct RectBounds;

class ControlPane : public Pane
{
public:
    ControlPane(unsigned char controlType, const RectBounds *bounds);
    virtual ~ControlPane() {}
    virtual void SetVisualState(unsigned char visualState);
    virtual void Enable();
    virtual void Disable();
    bool IsEnabled() const { return m_enabled; }
    bool IsSelectable() const { return m_controlFlags != 0; }
    void SetSelectable(bool selectable)
    {
        m_controlFlags = selectable ? 1 : 0;
    }
    bool IgnoresHitTesting() const;
    virtual void SetIgnoreHitTesting(bool ignoreHitTesting);
    void SetHandlesEnterKey(bool handlesEnterKey)
    {
        m_handlesEnterKey = handlesEnterKey;
    }

protected:
    virtual void Deactivate();
    virtual void Activate();
    virtual unsigned char HitTestPart(int, int)
    {
        return 10;
    }

    short m_rangeStart;
    short m_rangeCurrent;
    short m_rangeEnd;
    unsigned char m_controlType;
    unsigned char m_controlFlags;
    bool m_handlesEnterKey;
    bool m_enabled;
    bool m_controlActive;
    unsigned char m_visualState;
    bool m_ignoreHitTesting;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ControlPane

## 2026-08-18 ObjectImage Consumer Contract

- [UID:00009O][ObjectImageControlPane](by-class/ObjectImageControlPane.md) derives directly from ControlPane and uses the exact base constructor `ControlPane(8, bounds)`; its authored constructor seeds then copies the `ObjectStatusBlob` and does not perform the later active/flags/Enter-state writes. Those inherited-state assignments belong to [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md): its constructor sets `m_controlActive = false`, `m_controlFlags = 1`, and `m_handlesEnterKey = true`.
- [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) supplies a non-const HitTestPart(int localY, int localX) override returning part code 11. This matches the inherited virtual slot; the shared physical body is compiler-folded and does not move ownership out of ControlPane-derived source.
- These are consumer/inheritance facts only. ControlPane retains the base declaration, storage, and virtual contract; ObjectImage owns only its derived declarations and authored overrides.

## 2026-08-14 B003 Header Route Closure

- The duplicate class definition was removed from the CPP channel. CPP now includes `ControlPane.h` and emits children; H is guarded, includes Pane, and forwards Event/RectBounds before the single class definition.
- The exact field order and behavior remain unchanged. This supplies the complete base required by EPFImageControlPane and ButtonControlPane without duplicate definitions; UID000038/UID0000IG remain `91/93`.

## Status

- Confidence: very strong for base-control role, direct file parent, exact child routes, and vtable evidence; medium-high for final source-facing names.
- Likely source file: [UID:0000IG][ControlPane](by-file/ControlPane.md)
- Main address ranges: [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md), state virtual children inside [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers](by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md), and destructor/thunk support.
- Type docs: [UID:0003J9][ControlPaneVtables](by-type/by-vtable/ControlPaneVtables.md), split from [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- Exact vtable data: [UID:0003J8][0x00617a8c-0x00617b30.ControlPaneVtableData](by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md)

## Class Purpose

## UID000312 Public Interaction Contract

- `SetVisualState(unsigned char)` is public in the source contract. Shared `DialogPane` code calls it through `ControlPane *`; keeping it protected would make the accepted ordinary source illegal without unsupported friendship.
- `IsSelectable() const` is the narrow inline accessor over `m_controlFlags != 0`. Interactive controls initialize the byte nonzero, passive/static controls clear it, and ModelessDialogPane checks it before changing the active/hover control.
- `SetSelectable(bool)` is the matching inline writer and stores exactly `1` or `0` in `m_controlFlags`. EditablePaperPane uses it to make the read-only text control nonselectable; the direct one-byte lowering adds no out-of-line body, include, field, padding, or vtable slot.
- The accessor exposes behavior, not storage. `m_controlFlags` and the remaining state band stay protected, preserving encapsulation and the exact `ControlPane` layout.
- `IsSelectable` is an inferred human source name because no out-of-line symbol can survive for an inline accessor. Constructor values and the exact UID000312 load/test are its positive evidence; the absence of an out-of-line xref is expected rather than a blocker.
- Earlier protected `SetVisualState` and missing-accessor declarations are retained in dated history as superseded source-shape assumptions.

`ControlPane` is a `Pane`-derived base for UI controls. It sets control type, shared vtables, optional bounds, inherited range/current state, Enter-forwarding, enabled/active state, visual-state defaults, and hit-test behavior. `m_handlesEnterKey` at `+0x100` is separate from control availability at `+0x101` and inherited Pane visibility at `+0xb4`.

## Autogen Status

- Parent file: [UID:0000IG][ControlPane](by-file/ControlPane.md)
- Reconstructable: `TRUE`
- C++ emission: the complete R7 class declaration now emits at source position `10`, closes before `[[CHILDREN]]`, and supplies the declaration and protected state required by the accepted constructor and derived-control definitions. The raw active-frame helper remains prose-only under its exact no-route proof; compiler vtable, RTTI, adjustor-thunk, and deleting-wrapper code remains excluded from handwritten source.

The class is now attached to the reviewed `ui/core/ControlPane.cpp` file parent. Exact reconstructable child pages cover the constructor, base state virtuals, activation/visibility/hit-test helpers, the hit-test suppression accessor, and the raw active-frame helper. The legacy local aggregates remain parentless because their old address spans intentionally cross `ProgressBarControlPane` and mixed control-family ownership.

## Exact Layout And Source Contract

The accepted declaration closes an exact `0x108` complete-object layout without synthetic padding members or raw offset access:

| Offset | Source member / region | Evidence and disposition |
| --- | --- | --- |
| `+0x000..+0x0f7` | inherited `Pane` subobject | Constructor delegates to `Pane(1)`; derived control allocation sizes and the first ControlPane-owned stores place the base boundary at `+0xf8`. |
| `+0x0f8` | `short m_rangeStart` | Constructor zeroes the first inherited range word. |
| `+0x0fa` | `short m_rangeCurrent` | Constructor zeroes the second range/current word. |
| `+0x0fc` | `short m_rangeEnd` | Constructor zeroes the third range word. |
| `+0x0fe` | `unsigned char m_controlType` | Constructor copies its first byte parameter. |
| `+0x0ff` | `unsigned char m_controlFlags` | Constructor clears it; `ButtonControlPane` and PrettyButton constructors write it directly through the protected base contract. |
| `+0x100` | `bool m_handlesEnterKey` | Constructor clears it. ProfileDialog construction sets it true on the selected-profile text control; `DialogPane::HandleKeyOrTextEvent` tests this focused-control byte to forward Enter to the control instead of activating the pending/default control. |
| `+0x101` | `bool m_enabled` | Constructor sets true; `Enable`/`Disable`, inline `IsEnabled() const`, Button/Pretty paint paths, and navigation/action consumers distinguish it from Pane visibility at `+0xb4`. UID00043M/UID00043N read it to gate terminal shape-page movement without exposing protected storage. |
| `+0x102` | `bool m_controlActive` | Constructor clears it; `Activate`/`Deactivate` and button construction use it directly. |
| `+0x103` | `unsigned char m_visualState` | Constructor initializes literal `10`; `SetVisualState` and derived state transitions use this byte. |
| `+0x104` | `bool m_ignoreHitTesting` | Constructor clears it; the getter, setter, and generic hit-test skip gate establish its positive-polarity meaning. |
| `+0x105..+0x107` | natural tail alignment | No source field is introduced. Derived `ButtonControlPane` begins its state at `+0x108`. |

The state band is protected, not private: current derived constructors and methods directly assign `m_controlFlags`, `m_handlesEnterKey`, `m_controlActive`, and related inherited state. The narrow public inline `SetSelectable(bool)` and `SetHandlesEnterKey(bool)` methods let caller-side dialog source configure those bytes without illegal protected access; neither adds an out-of-line body or vtable slot. Duplicate derived fields, raw-offset casts, and public storage would contradict the repeated source-shaped writes. The constructor uses canonical `RectBounds`; the inline empty virtual destructor is the human source cause of inherited destructor/deleting-wrapper output. The virtual declaration order preserves the observed primary sequence through terminal `HitTestPart(int,int)`, while access labels do not alter slot order.

Complete `Pane` is included because it is a base class. `RectBounds` remains a valid forward declaration because R7 uses only a pointer. Vtable/RTTI stores, adjustor thunks, scalar deleting wrappers, EH/cookie machinery, and object-layout padding are compiler effects and are not handwritten in the formal block.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetFixedValue10` | `0x0041d690-0x0041d694` | Small virtual returning `10`; semantic name remains open. |
| `ControlPane::ControlPane(unsigned char controlType, const RectBounds *bounds)` | [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) | Source-ready first-draft constructor: builds `Pane(1)`, stores `m_controlType` at `+0xfe`, optionally applies bounds through `Pane::SetBounds(bounds, 0)`, initializes neutral inherited range/current fields `+0xf8/+0xfa/+0xfc`, clears `m_controlFlags`/`m_handlesEnterKey` at `+0xff/+0x100`, sets `m_enabled=true`, clears `m_controlActive`, sets `m_visualState=10`, clears `m_ignoreHitTesting=false`, and omits compiler vptr stores from source. |
| state byte setter | [UID:0003N2][0x00494b80-0x00494bad.ControlPaneSetVisualState](by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md) | Writes byte `+0x103` and invalidates on change; source-facing name remains provisional. |
| `Enable` / `Disable` | [UID:0003N3][0x00494bb0-0x00494bca.ControlPaneEnable](by-memory/0x00494bb0-0x00494bca.ControlPaneEnable.md), [UID:0003N4][0x00494bd0-0x00494bea.ControlPaneDisable](by-memory/0x00494bd0-0x00494bea.ControlPaneDisable.md) | Primary virtual slots `+0x4c/+0x50`; set/clear inherited `m_enabled` at `+0x101` and invalidate only on transition. AddItem action-button, navigation availability, ScrollableControlPane, and ImageButtonControlPane consumers establish enablement rather than visibility. |
| inline `IsEnabled` | inlined at consumers including `0x0052b090` and `0x0052b1d0` | Source-safe public read accessor for protected `m_enabled +0x101`. NewUserDialogPane2 left/right shift helpers perform the exact direct byte test before terminal page stepping; an inline getter explains the absent standalone function and avoids illegal protected access, friendship, raw offsets, or public field exposure. |
| inline `SetSelectable` | inlined by `EditablePaperPane::InitializePaperContent` | Stores canonical Boolean `1` or `0` into protected `m_controlFlags +0xff`; the read-only paper path passes false after text insertion/selection, matching the direct child-byte write without a standalone symbol. |
| `IgnoresHitTesting` | [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md) | Source-ready first-draft `bool ControlPane::IgnoresHitTesting() const`; returns `m_ignoreHitTesting` at `+0x104` and supplies the post-rectangle-test skip gate used by generic hit testing. |
| `SetIgnoreHitTesting` | [UID:0003N5][0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting](by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md) | Source-ready first-draft `void ControlPane::SetIgnoreHitTesting(bool ignoreHitTesting)` directly assigns `m_ignoreHitTesting` at `+0x104`; it performs no normalization, invalidation, helper call, or source return and is paired with `IgnoresHitTesting`. |
| inline `SetHandlesEnterKey` | inlined by dialog constructors including [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md) | Public source-safe setter for protected `m_handlesEnterKey +0x100`. ProfileDialog sets it true on the focused text control; DialogPane Enter dispatch reads the same byte. The inline form explains the absent standalone body and preserves the exact one-byte write. |
| `Deactivate` / `Activate` | [UID:0003N6][0x00494c10-0x00494c2a.ControlPaneDeactivate](by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md), [UID:0003N7][0x00494c30-0x00494c4a.ControlPaneActivate](by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md) | Exact protected `void` virtual definitions clear/set `m_controlActive` and call `InvalidateRect(&m_visibleBounds)` only when the state changes. The H declarations and fields already present here are the owning declaration contract; child H blocks remain blank. |
| active-frame helper | [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) | Raw source-shaped helper now documented at `88/89`. Best source-facing behavior name is `ControlPane::DrawActiveFrame`: it checks `m_enabled` (`+0x101`) and `m_controlActive` (`+0x102`), uses `GrafPort::SetDrawColor` with active-frame color `0x80`, clears inherited `m_drawMode` (`+0x70`) to `0`, and draws inherited `m_bounds` at `+0x44` through `GrafPort::DrawRectFrame`. Formal C++ remains blank under the no-route/no-declaration proof, and this class page carries behavior prose only: no function object, entry xrefs, vtable slot, pointer encoding, direct branch target, or recovered caller/declaration evidence has been found. |
| vtable data | [UID:0003J8][0x00617a8c-0x00617b30.ControlPaneVtableData](by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md) | Three-view primary/secondary/tertiary vtable data, backed by source-local [UID:0003J9][ControlPaneVtables](by-type/by-vtable/ControlPaneVtables.md). |
| adjustor thunks | `0x0049af3d-0x0049af52` | Two IDA-confirmed 0xb-byte destructor adjustor thunks; compiler-generated. |
| `ScalarDeletingDestructor` | `0x0049b170-0x0049b1aa` | Destructor/delete thunk; generated body currently references a derived-base artifact. |

## 2026-08-17 B010 Activate/Deactivate Dependency Closure

- [UID:0003N6][0x00494c10-0x00494c2a.ControlPaneDeactivate](by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md) and [UID:0003N7][0x00494c30-0x00494c4a.ControlPaneActivate](by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md) now carry the exact formal CPP definitions required by this class. This page retains the single protected declarations `virtual void Deactivate();` and `virtual void Activate();`; no duplicate declaration, field, include, vtable slot, or H fragment was added.
- Fresh binary evidence fixes `m_controlActive` at `+0x102` and inherited `m_visibleBounds` at `+0x44`. `Deactivate` clears the Boolean only when set; `Activate` sets it only when clear; both invalidate through the inherited `Pane` path only on transition.
- Base vtable cells are exact: `0x00617ae8 -> 0x00494c10` for `Deactivate` and `0x00617aec -> 0x00494c30` for `Activate`. The latter is also the exact tail target of [UID:000340][0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md) after the exchange money editor enables edit/select-all state.
- Raw decompiler integer returns are historical artifacts of the virtual invalidation call. The protected declarations, matching slots, and transition-only behavior establish ordinary human source `void` methods.
- UID000038 remains `91/93`: its layout, declaration, owner/emitter, and source position were already correct. This support sync closes child definitions while preserving every existing field and header-route fact.

## Evidence Notes

- IDA MCP reports 52 direct constructor callers.
- Constructor callers include browser, minimap, checkbox, EPF image, fitting-room, popup, and text-button controls.
- 2026-06-26 B007 accepted source-quality pass resolves [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) to `89/92` with formal first-draft C++. Live MCP session `80de0a67` confirms the `0xa1` constructor, direct callees `0x00544460` / `0x00544bd0`, vtable-store refs `0x00617a90` / `0x00617af8` / `0x00617b28`, 52 constructor xrefs, `0x00494a81-0x00494a90` padding, and successor ProgressBar helper boundary. The constructor source signature is `ControlPane::ControlPane(unsigned char controlType, const RectBounds *bounds)`, with `Pane(1)` and optional `Pane::SetBounds(bounds, 0)`.
- B007's packed constructor offsets remain exact; the current source-facing spelling at `+0x101` is `m_enabled`, superseding its historical `m_controlVisible` spelling. The remaining fields are neutral base aliases `m_rangeStart` / `m_rangeCurrent` / `m_rangeEnd` at `+0xf8/+0xfa/+0xfc`, `m_controlType` at `+0xfe`, `m_controlFlags` at `+0xff`, behavior-backed `m_handlesEnterKey` at `+0x100`, `m_controlActive` at `+0x102`, `m_visualState=10` at `+0x103`, and `m_ignoreHitTesting=false` at `+0x104`.
- B006 UID0004E0 live evidence closes the former `m_reservedControlState` placeholder: ProfileDialog writes one to focused TextEditControlPane `+0x100`, and `DialogPane::HandleKeyOrTextEvent` tests that same inherited byte to decide whether Enter is forwarded to the control or activates the pending/default child. This supports `bool m_handlesEnterKey` plus inline `SetHandlesEnterKey(bool)` without changing size, offsets, access, or virtual order.
- Base primary vtable cells `0x00617adc/0x00617ae0` are relative slots `+0x4c/+0x50` and now emit exact `Enable`/`Disable` children at `90/93`. UID0004BP uses the pair for selector-1 action-button availability; ScrollableControlPane and ImageButtonControlPane override the same slots; navigation-control callers use the same state contract. Inherited Pane visibility at `+0xb4` rejects current Show/Hide/visible-field interpretations.
- [UID:00043M][0x0052b090-0x0052b1cb.NewUserDialogPane2ShiftShapesLeft](by-memory/0x0052b090-0x0052b1cb.NewUserDialogPane2ShiftShapesLeft.md) reads previous control `6` at `+0x101`; [UID:00043N][0x0052b1d0-0x0052b30d.NewUserDialogPane2ShiftShapesRight](by-memory/0x0052b1d0-0x0052b30d.NewUserDialogPane2ShiftShapesRight.md) reads next control `7` at the same offset. Both are unrelated dialog-derived consumers, so protected direct field access is illegal. The inline `IsEnabled() const` declaration is the narrowest source representation and adds no out-of-line binary body or vtable slot.
- [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md) inherits this entire `+0xff-0x104` state band. Its constructors write inherited `m_controlFlags +0xff`, and its shared state helpers use inherited visible/active/visual/hit-test state; TextEditControlPane-private layout begins at `+0x108` and must not redeclare these base bytes.
- Support-only constant note: class/file-level names for pane mode `1` and visual-state normal `10` remain future candidates, but this class page does not currently own shared `kControlPaneMode` or `kControlPaneVisualStateNormal` declarations. [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) therefore emits literal `Pane(1)` and `m_visualState(10)` rather than target-local enum/type/constant declarations or references to unowned constants.
- IDA `entity_query` confirms `ControlPane` vtable bases at `0x00617a90`, `0x00617af8`, and `0x00617b28`; the tertiary table is short and ends before neighboring `ProgressBarControlPane` RTTI.
- 2026-06-12 A004 live IDA MCP split [UID:0003J8][0x00617a8c-0x00617b30.ControlPaneVtableData](by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md) and [UID:0003J9][ControlPaneVtables](by-type/by-vtable/ControlPaneVtables.md). `trace_data_flow backward` reports constructor stores at `0x00494a23`, `0x00494a29`, and `0x00494a33`; `get_int` confirms the RTTI locator dwords, final tertiary inherited slot at `0x00617b2c`, and the `0x00617b30` `ProgressBarControlPane` boundary.
- 2026-06-01 IDA MCP recheck splits the old local `0x004949e0-0x00494bf6` memory page into exact canonical children for the constructor and hit-test suppression accessor. The address space between them includes padding, progress-bar range helpers, and later base state virtual helpers, so it is not one continuous `ControlPane` constructor body.
- [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) now records live IDA evidence for the constructor boundary, direct callees, vtable stores, packed field writes, and broad derived-control caller population.
- 2026-07-05 B015 implementation of accepted [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md) source-quality report records the getter as first-draft source-ready: `bool ControlPane::IgnoresHitTesting() const` returns `m_ignoreHitTesting`. Current MCP session `supervisor_recovery_20260705` confirmed exact bytes `8a 81 04 01 00 00 c3`, range `0x00494bf0-0x00494bf7`, no callees, sole caller at `0x0049fb7f`, caller skip semantics after rectangle testing, paired setter write at `0x00494c00`, and constructor initialization of the same `+0x104` byte false.
- 2026-07-12 B005 accepted UID0003N5 source-quality update records the paired setter as first-draft source-ready `void ControlPane::SetIgnoreHitTesting(bool ignoreHitTesting)`. Current MCP session `359c7886` confirms exact range/bytes/unique signature, nine-byte preceding alignment and immediate Deactivate successor, no callees or ordinary code callers, and 50 data refs: base primary slot `0x00617ae4` (`+0x54`) plus 49 inherited derived-control table copies. Constructor initialization, setter write, getter read, and sole getter consumer at `0x0049fb7f` establish positive-polarity `m_ignoreHitTesting`; retained setter `AL` is incidental store reuse rather than a source return. PopupMenu consumer context, inherited derived tables, ProgressBar/Button/RadioGroup adjacency, and raw decompiler types are rejected as narrower ownership or better source shape.
- 2026-06-13 B002 split repair confirms the modeled state helpers at `0x00494b80`, `0x00494bb0`, `0x00494bd0`, `0x00494c00`, `0x00494c10`, and `0x00494c30` are base `ControlPane` virtual slots. Vtable dwords read as `0x00617ad8 -> 0x00494b80`, `0x00617adc -> 0x00494bb0`, `0x00617ae0 -> 0x00494bd0`, `0x00617ae4 -> 0x00494c00`, `0x00617ae8 -> 0x00494c10`, and `0x00617aec -> 0x00494c30`.
- 2026-06-16 A001 live IDA MCP reconfirmed constructor `0x004949e0` size `0xa1`, state/accessor/destructor/fixed-virtual starts, 52 constructor xrefs, the `0x00617ad8-0x00617aec` state-helper vtable cells, `0x00617af0 -> 0x0041d690`, and `0x00617b30` as the successor boundary.
- The same pass reconfirmed `0x00494c50` is not an IDA function and has zero IDA xrefs; bytes at `0x00494c4a-0x00494c80` still show six `0xcc` bytes followed by the complete source-shaped active-frame helper.
- A section-mapped PE scan found zero absolute-VA, zero RVA, and zero direct `E8`/`E9` hits to `0x00494c50`; this keeps final C++ blocked on reachability/source representation even though ownership through base `ControlPane` state fields is strong.
- 2026-06-20 supervisor Rule 26 incorporation of B001 `0003N9` report kept the raw active-frame helper at `85/86` under this class while recording the then-current visible/shown interpretation for `+0x101`. That spelling is now superseded by `m_enabled`; its `+0x102` active/focus, `+0x44` bounds, `+0x70` draw mode, `0x004b9660` draw-color setup, and `0x004ba450` `DrawRectFrame` facts remain valid.
- 2026-06-23 B004 MCP-backed recheck raises child [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) to `88/89` while preserving blank formal C++. MCP session `80de0a67` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` reconfirmed no function at `0x00494c50`, decompile failure, exact `0x30`-byte body after six `0xcc` bytes, zero xref/code-ref/data-ref/immediate routes to the start or plausible entry interiors, no `ControlPane` vtable slot after `0x00617aec -> 0x00494c30`, and successor `0x00494c80` as the `ProgressBarControlPane` constructor boundary. The local PE `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632` also produced zero VA/RVA/raw-offset pointer hits and zero direct-transfer hits to `0x00494c50`, while positive controls found sibling `0x00494c30` and `0x00494b80` vtable/direct-call routes. This class keeps `ControlPane` ownership because the helper uses only base visible/active state, inherited bounds, and inherited draw mode; ProgressBar, Button/concrete-control, GrafPort-as-owner, standalone-file, and no-owner alternatives remain rejected.

## Score Rationale

Completion is `91` because the page now supplies the complete declaration-before-definition source cause, exact `0x108` layout, protected inherited-state contract, canonical constructor signature, inline empty virtual destructor, and exact primary virtual order while preserving the constructor/getter/setter, raw-helper, vtable, compiler, and neighborhood evidence. It remains below final-source quality because exact original field spellings, the fixed virtual name, raw-helper source representation, and exact original header split remain open.

Confidence is `93` because constructor lifecycle, exact `0x108` allocation boundary, base vtable slots, paired bodies, derived direct writes, independent action/navigation consumers, and separate Pane visibility converge on the accepted layout and access model. It remains capped by unresolved original spellings, the raw-helper reachability gap, and the mixed local aggregate around the constructor/accessor.

## Cross-References

- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:000114][0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude](by-memory/0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude.md)
- [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md)
- [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers](by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md)
- [UID:0003N2][0x00494b80-0x00494bad.ControlPaneSetVisualState](by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md)
- [UID:0003N3][0x00494bb0-0x00494bca.ControlPaneEnable](by-memory/0x00494bb0-0x00494bca.ControlPaneEnable.md)
- [UID:0003N4][0x00494bd0-0x00494bea.ControlPaneDisable](by-memory/0x00494bd0-0x00494bea.ControlPaneDisable.md)
- [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md)
- [UID:0003N5][0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting](by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md)
- [UID:0003N6][0x00494c10-0x00494c2a.ControlPaneDeactivate](by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md)
- [UID:0003N7][0x00494c30-0x00494c4a.ControlPaneActivate](by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md)
- [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md)
- [UID:0003J9][ControlPaneVtables](by-type/by-vtable/ControlPaneVtables.md)
- [UID:0003J8][0x00617a8c-0x00617b30.ControlPaneVtableData](by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:000120][0x0049af3d-0x0049af52.ControlPaneAdjustorThunks](by-memory/0x0049af3d-0x0049af52.ControlPaneAdjustorThunks.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md)
- [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md)

## Changes

- 2026-08-22 B010 UID0000M3 Gate 2A support repair: corrected the ObjectImage consumer attribution so `ObjectImageControlPane` owns only the `ControlPane(8, bounds)` base-construction relationship, while `ObjectImageButtonPane` owns the explicit `m_controlActive`, `m_controlFlags`, and `m_handlesEnterKey` assignments.
- 2026-08-16 B001 UID0002NC support callback: inserted exact inline `SetSelectable(bool)` immediately after `IsSelectable()` and before `IgnoresHitTesting()`. The body canonicalizes to byte `1/0` in existing protected `m_controlFlags`, adds no include/storage/padding/slot/out-of-line CPP, preserves exact `0x108` layout, and emits through existing file UID0000IG at class position 10. Score and unrelated ControlPane source remain unchanged.

- 2026-08-02 B006 UID0004E0 Gate 2A C019 repair:
  - Preserved the accepted CPP declaration and all prior class evidence, scores, ownership, emitter routing, layout, and child source unchanged.
  - Added the complete legal declaration to `RECONSTRUCTION_H CODE`, including the accepted public inline `SetHandlesEnterKey(bool)` and protected `bool m_handlesEnterKey` at `+0x100`; a standalone partial member fragment would not be valid C++ header source.

- 2026-08-01 B006 UID0004E0 support callback:
  - Preserved `91/93`, owner/emitter UID0000IG, reconstructable state, position 10, exact `0x108` layout, virtual order, method children, and unrelated history.
  - Replaced only protected `unsigned char m_reservedControlState` at `+0x100` with protected `bool m_handlesEnterKey`; inserted exact public inline `SetHandlesEnterKey(bool)` immediately after `SetIgnoreHitTesting`.
  - Added exact ProfileDialog write/DialogPane Enter-dispatch semantics, absent standalone-body source cause, and size/order/access proof. The historical reserved-state spelling is superseded rather than treated as current.

- 2026-07-22 B002 UID00043N bounded support callback:
  - Preserved `91/93`, owner/emitter UID0000IG, reconstructable true, source position 10, complete `0x108` layout, all existing virtuals/methods/children, and unrelated provenance.
  - Added only inline public `bool IsEnabled() const { return m_enabled; }` to represent exact direct `+0x101` reads legally from NewUserDialogPane2 UID00043M/UID00043N.
  - Recorded controls `6/7`, prior/next edge gating, absent standalone getter body, and rejection of public-field, friend, raw-offset, or vtable alternatives.
- 2026-07-16 B003 UID0004EL support implementation:
  - Raised `88/91 -> 91/93`, retained owner/emitter/file route and reconstructable state, and set source position `10`.
  - Installed exact R7 with complete `Pane` include, pointer-safe `RectBounds` forward declaration, inline empty virtual destructor, exact virtual ordering, protected `+0xf8..+0x104` state band, natural `+0x105..+0x107` alignment, and class closure before `[[CHILDREN]]`.
  - Incorporated the exact `0x108` layout, direct-derived-access proof, canonical rectangle spelling, source/compiler split, and rejection of private duplicate fields, invented setters, raw offsets, and handwritten ABI/vtable glue.
  - Preserved the raw active-frame helper's no-route/no-formal disposition, fixed-virtual naming cap, all constructor callers, vtable views, compiler thunks, historical evidence, and unrelated family material.

- 2026-07-13 B005 UID0004BP support implementation:
  - Raised `86/88 -> 88/91`; owner/emitter/file route and intentionally blank class formal block remain unchanged.
  - Synchronized constructor field `m_enabled`, UID0003N3/UID0003N4 names and renamed links, exact `+0x4c/+0x50` slots, action-button/navigation/ImageButton/Scrollable consumers, raw-helper enabled gate, separate Pane visibility at `+0xb4`, and explicitly superseded visible/show history.
  - Preserved all unrelated blockers for the fixed virtual, destructor representation, final field spellings, and raw active-frame liveness/source representation.

- 2026-07-13 B003 UID00011H support sync:
  - Score, owner/emitter route, formal C++, and all existing ControlPane method/field dispositions remain unchanged at `86/88`.
  - Added the narrow inherited-layout note proving TextEditControlPane consumes rather than privately owns `+0xff-0x104`; its private fields begin at `+0x108`.

- 2026-06-16 A001 Goal 2 file/class completion pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, with current live IDA and PE evidence for the class child set and raw active-frame helper.
  - Evidence: live `lookup_funcs`, `xrefs_to`, `analyze_component`, `get_int`, `get_bytes`, and section-mapped PE checks reconfirmed the constructor/state/accessor/destructor/fixed-virtual inventory, 52 constructor xrefs, state-helper vtable cells, zero xrefs/pointer/branch hits to `0x00494c50`, and direct parent [UID:0000IG][ControlPane](by-file/ControlPane.md) at `86/88`. Final C++ remains blank until field/helper names and raw-helper source representation are source-quality.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/82`.
  - Summary/evidence: base-control role, constructor, hit-test helper, destructor thunks, vtable addresses, broad caller set, and inheritance/file cross-references are documented; remaining work is exact semantic naming for tiny virtuals and final source-facing destructor representation.

- 2026-06-01:
  - Before: constructor and hit-test helper were referenced only through the broad local memory page.
  - After: exact canonical child pages were added for both functions and linked from the method table.
  - Summary/evidence: IDA MCP confirms function boundaries at `0x004949e0-0x00494a81` and `0x00494bf0-0x00494bf7`, and the neighborhood inventory shows non-`ControlPane` helper code between them.
- 2026-06-07:
  - Before: the class page stayed at `76/82`, was reconstructable but unattached, and still cited generated recovered source directly despite the parent file and exact child pages being reviewed.
  - After: raised to `82/84`, attached to [UID:0000IG][ControlPane](by-file/ControlPane.md), added autogen-status and score-rationale sections, and kept final C++ blank.
  - Summary/evidence: [UID:0000IG][ControlPane](by-file/ControlPane.md) is reviewed at `82/86` with projected `NexusTK/ui/core/` placement; [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) and [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md) document exact child behavior; [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md) records the ControlPane vtable family and constructor store evidence.
- 2026-06-12 A004 Batch 336:
  - Before: the class was `82/84` and could not serve as the strict direct parent for exact `ControlPane` vtable documentation.
  - Changed to: `85/86`, with exact [UID:0003J9][ControlPaneVtables](by-type/by-vtable/ControlPaneVtables.md) and [UID:0003J8][0x00617a8c-0x00617b30.ControlPaneVtableData](by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md) evidence.
  - Summary/evidence: live IDA MCP confirmed the three decorated bases, constructor store triad, adjustor/scalar-destructor function sizes, and `ProgressBarControlPane` successor boundary. The page now clears the strict child/direct-parent gate for the source-local vtable child while final C++ remains below the final-source threshold.
- 2026-06-13 B002 state-helper split repair:
  - Scores unchanged.
  - Added exact state virtual children [UID:0003N2][0x00494b80-0x00494bad.ControlPaneSetVisualState](by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md), UID0003N3 and UID0003N4 under their historical visible-flag titles (now [UID:0003N3][0x00494bb0-0x00494bca.ControlPaneEnable](by-memory/0x00494bb0-0x00494bca.ControlPaneEnable.md) and [UID:0003N4][0x00494bd0-0x00494bea.ControlPaneDisable](by-memory/0x00494bd0-0x00494bea.ControlPaneDisable.md)), [UID:0003N5][0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting](by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md), [UID:0003N6][0x00494c10-0x00494c2a.ControlPaneDeactivate](by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md), [UID:0003N7][0x00494c30-0x00494c4a.ControlPaneActivate](by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md), repaired [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md), and recorded [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) as a below-gate candidate helper.
  - Summary/evidence: live IDA/vtable evidence places the modeled `0x00494b80-0x00494c4a` helper slots in the base `ControlPane` vtable; the progress current setter at `0x00494b50` is excluded to [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md).
- 2026-06-14 B002 current Goal 2 pass:
  - Scores unchanged.
  - Updated [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) from a below-gate candidate to an assigned raw `ControlPane` helper at `85/86`.
  - Summary/evidence: live IDA MCP and raw PE checks still show no function object, external xref, vtable slot, pointer encoding, or direct branch/call route, so final C++ remains blank; ownership now clears because the helper uniquely consumes base `ControlPane` state bytes `+0x101/+0x102`, clears base draw state `+0x70`, draws `this+0x44`, and sits directly after the assigned base active-state virtuals.
- 2026-06-20 supervisor Rule 26 incorporation:
  - Scores unchanged.
  - Incorporated B001's raw-helper source-quality reanalysis for [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md), including field/helper name candidates, rejected ProgressBar/Button/GrafPort/no-owner routes, `ControlPane::DrawActiveFrame` as the best future source-facing name, and the no-C++ decision until reachability/source declaration evidence is recovered.
- 2026-06-23 B004 implementation of accepted [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) MCP-backed report:
  - Scores unchanged for this class page.
  - Synchronized the active-frame helper row and evidence notes to the child page's `88/89` disposition. That pass used the then-current `m_controlVisible` spelling, now superseded by `m_enabled`; its `ControlPane::DrawActiveFrame`, `m_controlActive`, `m_bounds`, `m_drawMode`, `GrafPort::SetDrawColor`, and `GrafPort::DrawRectFrame` names remain useful. Formal C++ remains blank because the route scan proved no entry route or source declaration.
- 2026-06-26 B007 implementation of accepted [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) source-quality report:
  - Scores unchanged for this class page.
  - Updated the constructor row and evidence notes with the source-ready constructor signature, `Pane(1)` base construction, optional `const RectBounds *` / `SetBounds(bounds, 0)` route, neutral inherited range/current aliases, control flags/reserved/visible/active/visual-state/hit-test defaults, 52 caller refs, vtable-store refs, range-safe literal-only formal C++ policy, and support-only constant caveat.
- 2026-07-05 B015 implementation of accepted [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md) source-quality report:
  - Scores unchanged for this class page.
  - Updated the `IgnoresHitTesting` method row and evidence notes to the child page's `88/92` first-draft source-ready disposition: exact getter bytes/range, no callees, sole caller skip gate, paired setter write, constructor initialization, and `m_ignoreHitTesting` field parity.
- 2026-07-12 B005 implementation of accepted UID0003N5 source-quality report:
  - Scores and class-level blank formal block unchanged at `86/88`.
  - Updated the method inventory, emission status, evidence, and score rationale to UID0003N5's `90/92` source-ready void-bool setter, current exact MCP/range/padding/vtable/caller-callee facts, complete field lifecycle, incidental-`AL` correction, and rejected narrower-owner/decompiler-shape alternatives. Owner/source routing remains class UID000038 through file UID0000IG.
