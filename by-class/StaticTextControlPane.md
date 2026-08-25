*** UID:0000E3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "StaticTextControlPane.h"
#include "TextEditPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../core/ControlPane.h"

class TextEditPane;

class StaticTextControlPane : public ControlPane
{
public:
    StaticTextControlPane(const wchar_t *text,
                          bool useAlternateStyle,
                          int textColor,
                          int shadowColor,
                          const RectBounds *bounds,
                          bool useWideContentWidth,
                          bool inputMode);

    virtual unsigned char GetControlType(int, int);

private:
    unsigned short m_textStateFlags;
    TextEditPane *m_textEditPane;
    unsigned char m_savedTextPaneState;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaticTextControlPane

## Status

- Confidence: strong for broad static text control role, live method boundaries, vtable placement, constructor fan-in, embedded text-pane behavior, and fixed type code; medium for final field names.
- Likely source file: [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- Main address ranges: shared helpers at `0x00498dd0-0x00499021`, constructor at `0x00499030-0x004991ec`, and type id at `0x0049b920-0x0049b925`
- Parent attachment: [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md) has a documented `NexusTK/ui/controls/` reconstruction path and covers the same static-text control family.

## Class Purpose

`StaticTextControlPane` is an older static text control wrapper used broadly by dialogs. It exposes a fixed pane/control type code `19` and has helper virtuals that switch an embedded text pane between inactive and active/selectable display states.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) | shared state/border helper band | Shared by StaticText, TextEdit, and ExchangeMoneyEdit vtables; handles active/inactive text-pane state and optional frame/highlight paint. |
| [UID:00011I][0x00499030-0x004991ec.StaticTextControlPaneConstructor](by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md) | `StaticTextControlPane::StaticTextControlPane` | Source-ready emitting constructor through UID0000E3. It calls `ControlPane(5, bounds)`, installs three `StaticTextControlPane` vtables, allocates a 372-byte embedded `TextEditPane`, applies owner-relative bounds, sets child mode/edit state, seeds optional text, and finalizes owner state through inherited control state and `SetMode(4)`. |
| [UID:000222][0x0049b920-0x0049b925.StaticTextControlPaneTypeId](by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md) | `GetControlType` | Returns fixed type code `19`; source-facing spelling is inferred from the control hierarchy while the machine body is exact. |

## Evidence Notes

- IDA MCP reports shared helpers `sub_498DD0`, `sub_498E10`, `sub_498E60`, `sub_498ED0`, and `sub_498F50` with exact end-exclusive ranges `0x00498e0e`, `0x00498e5e`, `0x00498eca`, `0x00498f4c`, and `0x00499021`; those helpers are now documented separately because TextEdit and ExchangeMoneyEdit vtables reference the same bodies.
- IDA MCP reports `sub_499030` and `sub_49B920` with exact end-exclusive ranges `0x004991ec` and `0x0049b925`.
- IDA MCP reports 104 direct constructor call sites across 43 caller functions, including dialog/control constructors such as `sub_472CA0`, `sub_4753E0`, `sub_51A520`, `sub_51B880`, `sub_58D750`, and `sub_59BC90`, which strongly supports a generic control role.
- Live IDA names three `StaticTextControlPane` vtables at `0x006181a4`, `0x0061820c`, and `0x0061823c`, with constructor stores at `0x004990be`, `0x004990c4`, and `0x004990ce`.
- Vtable data references place shared helper methods at StaticText cells `0x00618144`, `0x0061814c`, `0x00618150`, `0x00618158`, `0x0061815c`, `0x006181e8`, `0x006181f0`, `0x006181f4`, `0x006181fc`, and `0x00618200`; TextEdit and ExchangeMoneyEdit vtables also reference the same helper bodies.
- The archived B001 `0003LQ` audit correctly rejected assigning the whole shared state/border helper band to StaticText solely from these vtable cells. Later RTTI evidence resolves the cells as inherited `TextEditControlPane` base virtuals; StaticText remains a derived consumer with its own constructor/type-id pages, not the source owner for [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md).
- B008 raw RTTI reanalysis confirms the `StaticTextControlPane` destructor vtable cells that point at [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md) are inherited `TextEditControlPane` base slots. They do not create a StaticText-authored destructor body or change [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md)'s owner/emitter route.
- B009 source-quality reconciliation preserves that interpretation with exact cells: `0x006181a4` points at the inherited primary TextEdit scalar deleting destructor wrapper, while `0x0061820c` and `0x0061823c` point at the inherited `+0xa0` and `+0xa4` TextEdit adjustor thunks. Current evidence does not require a separate StaticText destructor body for the shared cleanup.
- Constructor decompilation shows embedded text-pane allocation through `sub_4F4AA0(372)` and `sub_58DCE0`, child pointer storage at owner offset `+0x10c`, child state calls `sub_5446B0(..., 1)` and `sub_58EA80(..., 0, 0)`, optional text seeding through `sub_58E270`, and final owner state `sub_5446B0(this, 4)`.
- 2026-07-04 B007 source-quality implementation for [UID:00011I][0x00499030-0x004991ec.StaticTextControlPaneConstructor](by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md) replaces the previous blank-constructor disposition with formal source emission through this class. Current MCP session `73c77998` reports `sub_499030` at `0x00499030-0x004991ec` with size `0x1bc`, predecessor padding `cc` x15, target epilogue `c2 1c 00`, four `cc` bytes before successor `sub_4991F0`, StaticText vtable stores at `0x004990be`, `0x004990c4`, and `0x004990ce`, 104 direct constructor xrefs, and caller samples showing the stable seven-argument order: text pointer, style selector, two color/style integers, bounds pointer, wide-content-width selector, and input-mode byte.
- The UID00011I formal constructor uses source-facing names `m_textEditPane`, `m_textStateFlags`, `IsLegacyAssetMode()`, `OffsetRect`, `SetMode`, `SetTextEditMode(false, false)`, and `SetText(text, 0)`. Exact public parameter names, `m_textStateFlags`, style/color parameter names, packed `+0xfe/+0xff` control-state spelling, child bounds setter name, and the two-argument text setter overload remain confidence caps, not source-readiness blockers.
- Dialog constructors instantiate this class for prompts and labels beside buttons and editable text controls.
- `GetPaneTypeCode` returns `0x13` / `19`.

## Current Caveats

- UID00011I is now source-ready and emitting, but exact original field names, vtable-slot names, and the public constructor signature names remain inferred. Treat them as confidence caps on the constructor, not as a reason to blank its formal C++ block.
- The class remains below the highest source-confidence threshold because some field names and exact public API names are not proven across the whole class. That does not change UID00011I's accepted constructor body or owner/emitter route.

## Cross-References

- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md)
- [UID:00011I][0x00499030-0x004991ec.StaticTextControlPaneConstructor](by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md)
- [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md)

## Changes

- 2026-08-17 B010 ArgumentedItemInputDialogs dependency closure:
  - Raised `85/86` to `91/93`, populated the formal CPP/H channels, and preserved source position `10` in `StaticTextControlPane.cpp/.h`.
  - The header declares the exact seven-parameter constructor shape, fixed-return virtual `GetControlType(int, int)`, and natural source members needed to close the `0x114` allocation. The CPP includes its sibling header and `TextEditPane.h`, then emits exact children.
  - Shared TextEdit state/border helpers and inherited destructor wrappers remain dependency/compiler evidence; no duplicate StaticText-authored bodies were invented.

- 2026-07-13 B002 UID00011V callback ordering sync:
  - Set the existing older StaticTextControlPane file-emitter position to definite `10`.
  - This preserves its accepted source/body detail while establishing deterministic file order before [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md) at `20`; B005 alone owns the nested UID0000E5 position `30` update.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents generic static-text role, constructor/helper/type-id ranges, high caller count, and current generated caveats; completion remains limited because the constructor output is incomplete and helper field names are still overfit to fitting-room behavior.
- Before: the type-id helper was listed as `0x0049b920-0x0049b924`.
- Changed to: `0x0049b920-0x0049b925` and linked to its new by-memory page.
- Summary/evidence: IDA MCP reports `sub_49B920` size `0x5`, so the `mov al, 13h; retn 8` helper ends exclusive at `0x0049b925`.
- 2026-06-04: Raised completion/confidence from `78/76` to `82/84`, set `RECONSTRUCTABLE:TRUE`, and attached the class to [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md).
  - Evidence: live IDA rechecked all method boundaries, vtable references, and the constructor body; confirmed 104 direct constructor call sites across 43 functions; confirmed three `StaticTextControlPane` vtable installs at `0x004990be`, `0x004990c4`, and `0x004990ce`; confirmed embedded text-pane allocation/setup at owner offset `+0x10c`; and confirmed fixed type code `19`.
  - Remaining limits: scores stay below final-source level because exact member names, public API names, and full source-level constructor parameter names are still inferred rather than proven.
- 2026-06-12 C001 Goal 2 split: raised completion/confidence from `82/84` to `85/86` and reconciled the constructor's direct-parent gate.
  - Evidence: live IDA MCP confirmed the former `0x00498dd0-0x004991ec` memory page mixed shared helpers with the exact constructor. The shared helper page now records TextEdit, StaticText, and ExchangeMoneyEdit vtable refs, while [UID:00011I][0x00499030-0x004991ec.StaticTextControlPaneConstructor](by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md) records only `sub_499030`.
  - Remaining limits: class still stays below final-source level because source-quality field names, method names, and constructor signature names are not proven.
- 2026-06-19 B008 inherited destructor-slot note:
  - What existed before: the class recorded shared helper vtable refs but did not explicitly document the inherited TextEdit destructor-wrapper refs.
  - Changed to: added the [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md) caveat so StaticText pages do not claim the TextEdit scalar deleting wrapper as their source body.
  - Evidence: B008 raw RTTI shows `StaticTextControlPane` derives through `TextEditControlPane`, and its destructor cells reuse inherited TextEdit base slots.
- 2026-06-21 B009 source-quality reconciliation:
  - Score unchanged at `85/86`.
  - Added the exact inherited TextEdit destructor-slot cells `0x006181a4`, `0x0061820c`, and `0x0061823c` and kept StaticText from claiming a separate destructor body for [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md).
- 2026-06-22 Rule 26 incorporation for archived B001 report `0003LQ-TextControlSharedStateAndBorderHelpers.md`:
  - Score unchanged at `85/86`.
  - Added the explicit historical note that B001's no-owner audit rejected StaticText ownership for [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md), and that later RTTI now classifies those StaticText cells as inherited `TextEditControlPane` slots.
- 2026-07-04 B007 source-quality implementation for UID00011I:
  - Score unchanged at `85/86`.
  - Updated the constructor row and evidence notes to show [UID:00011I][0x00499030-0x004991ec.StaticTextControlPaneConstructor](by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md) is source-ready and emits through UID0000E3.
  - Preserved the accepted separation from [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) and rejected TextEditControlPane/TextEditPane/ControlPane/no-owner/raw-helper alternatives for the constructor.
