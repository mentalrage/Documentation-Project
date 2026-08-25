*** UID:00000B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "AlertPanes.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../core/DialogPane.h"
#include "../../util/FunctionObjects.h"

class Pane;

class AlertPane : public DialogPane
{
public:
    AlertPane(const wchar_t *messageText,
              Pane *layoutReference,
              const wchar_t *primaryButtonText,
              const wchar_t *secondaryButtonText);
    virtual ~AlertPane();

    virtual void DismissDialog(int buttonId, int unused);

protected:
    virtual void OnPrimaryButton();
    virtual void OnSecondaryButton();

    Pane *m_layoutReference;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AlertPane

## Status

- Likely source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- Address range: [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md), with shared destructor [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md)
- Vtables: [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md)
- Layout docs: [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- Documentation basis: IDA-confirmed constructor/dismiss/destructor ranges, vtable/layout docs, and the [UID:0000HE][AlertPanes](by-file/AlertPanes.md) source-family page.
- Reconstruction parent: attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md) now that the file page has a valid `NexusTK/ui/dialogs/` source root and clears the parent-side `80/80` gate.
- Confidence: strong.
- C++ reconstruction: populated with a first-draft class declaration only. Constructor/dismiss method bodies stay on [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md), and compiler-generated destructor/vtable bodies stay blank in their exact evidence pages.

## Class Purpose

`AlertPane` is the shared modal alert dialog base used across the client. It builds a dynamic `DialogPane` from a message string, an anchor/layout reference, and optional primary/secondary button labels. It handles text measurement, wrapped-height calculation, static-text versus scrollable body selection, default-button setup, centering/clamping to screen bounds, modal-list insertion, and slide-in/slide-out animation.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AlertPane` | `0x0049feb0-0x004a0575` | Constructs a dynamic modal alert with optional buttons and text body. |
| `DismissDialog(int buttonId, int unused)` | `0x004a0580-0x004a0686` | Handles primary/secondary button ids, animates out if visible, dispatches no-argument `OnPrimaryButton` or `OnSecondaryButton`, and dismisses the pane. |
| `ScalarDeletingDestructor` | [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) | Shared alert-family deleting destructor referenced by base and derived alert/dialog vtables. |

## Evidence Notes

- IDA MCP confirms both functions as real starts and shows broad constructor fan-in from many client subsystems.
- 2026-05-26 IDA `py_eval` recheck confirms `0x0049feb0-0x004a0575` constructor size `0x6c5`, `0x004a0580-0x004a0686` dismiss/dispatch size `0x106`, shared destructor `0x0048c550-0x0048c58b`, and adjustor thunks `0x0048c315-0x0048c32b`.
- The same recheck found 96 xrefs to the constructor, reinforcing `AlertPane` as shared UI infrastructure rather than feature-local code.
- 2026-05-26 IDA MCP confirms three `AlertPane` vtable bases at `0x00618b00`, `0x00618b68`, and `0x00618b98`, with constructor stores at `0x0049ff1e`, `0x0049ff24`, and `0x0049ff2e`.
- 2026-05-26 IDA layout pass confirms vptr offsets `+0x00`, `+0xa0`, and `+0xa4`, and confirms the constructor stores the caller layout reference at `+0x26c`; see [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- The constructor calls shared text measurement helpers, creates either `StaticTextControlPane` or a `TextEditPane` inside `ScrollableControlPane` for oversized dialogs, then calls dialog show/modal-list helpers.
- `DismissDialog` accepts only button ids `1` and `2`, matching primary and secondary alert button slots.
- `DismissDialog` dispatches through primary vtable slots `+0x5c` and `+0x60`; B002's 2026-06-17 source-quality recheck resolves these as no-argument `OnPrimaryButton` and `OnSecondaryButton` extension points. The ABI is `DismissDialog(int buttonId, int unused)` because the function returns with `retn 8`; `OnDialogAction` / `OnButtonAction` remains only a cross-dialog behavior alias.
- The `+0x26c` AlertPane tail field is best named `m_layoutReference`: it stores the caller layout/reference pane, is reused by BlueAlertPane, and is not proven to be an owning parent pointer.
- 2026-05-26 IDA MCP xrefs show the shared scalar deleting destructor at `0x0048c550` referenced by `AlertPane`, `BlueAlertPane`, `CopyWindow`, `QuitDialog`, and `ClanLeaveConfirmDialog` vtables. Treat current `boost::exception` / `TransferReplyAlert` teardown labels as type-owner pollution.

## Resolved Source-Quality Questions

- B002's 2026-06-17 pass selects descriptive source-facing names `OnPrimaryButton` and `OnSecondaryButton` for the base callback slots. Derived classes may use more specific accept/cancel/confirm names in their own pages, but the base class accepts arbitrary primary/secondary button labels.
- Several derived alert wrappers have projected constructor starts in neighboring feature files. They should not be pulled into the base class without feature-specific caller review.
- Method-body C++ remains deferred to exact by-memory children until shared `DialogPane` and control-helper declarations are source-quality, but the class declaration itself is ready and now emitted here.

## DeleteReplyAlert Derived Contract

[UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md) is an exact current derived consumer of both source-facing base contracts established here:

- [UID:0004WC][0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor](by-memory/0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor.md) passes `messageText`, `layoutReference`, `L"OK"`, and no secondary-button text to the AlertPane constructor.
- The base stores that `Pane *` at `m_layoutReference` (`+0x26c`). [UID:0004WF][0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton](by-memory/0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton.md) consumes it as `ArticleListDialog *` in multi mode or `ArticleDialog *` in single mode, exactly matching the constructor caller contexts.
- DeleteReplyAlert primary vtable slot `0x00614680` occupies the inherited `OnPrimaryButton` position (`+0x5c`). Historical `OnConfirm` text is a behavior alias, not the current source declaration.
- DeleteReplyAlert adds only derived bytes at `+0x270/+0x271`; they must not be added to this base class.

This relationship confirms the current base names without changing AlertPane ownership, score, or formal output.

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md)
- [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [UID:0002M5][0x00618b00-0x00618ba0.AlertPaneVtableData](by-memory/0x00618b00-0x00618ba0.AlertPaneVtableData.md)
- [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md)
- [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md)
- [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md)
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md)
- [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md)

## 2026-07-29 Supervisor Gate 2B Reconciliation (Catalog 0353)

- I12 was applied and verified at `0x0049feb0`: current name `AlertPane__AlertPane` and prototype `AlertPane *__thiscall(AlertPane *this, const wchar_t *messageText, Pane *layoutReference, const wchar_t *primaryButtonText, const wchar_t *secondaryButtonText)`. The second argument is a non-owning/ownership-unproven layout reference; no ownership claim was added.
- Only the accepted repeatable function comment is populated. Address regular/repeatable comments and the regular function-comment channel remain blank. The historical raw constructor identity is retained only as search provenance.
- Existing argument slots were normalized without changing ABI or storage: `messageText +0xb0/4`, `layoutReference +0xb4/4`, `primaryButtonText +0xb8/4`, and `secondaryButtonText +0xbc/4`, with the exact pointer types in the prototype. All nonargument frame storage, offsets, and widths remain unchanged.
- Persistence checkpoint: prestate IDB SHA256 `FD8282A51836D47961EA386D7C2D25F80D0BF88B96ACFF106FFA802277F78B16`; byte-identical backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B010-UID0003MQ-20260729-082218.i64`; saved IDB SHA256 `6D20767D448CC568508E462790D05678838216C6CFEE77E3CFF5C4B5905244AB`, `143190049` bytes, `2026-07-29T08:26:09.5759690-04:00`. Catalog entry `0353` is `APPLIED_VERIFIED_RECONCILIATION_PENDING`; B010 did not mutate IDA.

## 2026-08-11 UID0001CU Formal-Route Incorporation

- Metadata remains `88/92`; owner/emitter remain [UID:0000HE][AlertPanes](by-file/AlertPanes.md), reconstructable remains true, position remains blank, and `Nested:0` remains exact.
- The complete AlertPane declaration moved from the CPP channel into the owning H channel. The CPP now owns the single `AlertPanes.h` include followed by `[[CHILDREN]]`, so adjacent VersatileAlertPane code does not duplicate the preamble.
- The declaration preserves constructor parameters, virtual destructor, dismissal and primary/secondary handlers, and `m_layoutReference`. FunctionObject support is included for child declarations; registration-specific policy remains outside AlertPanes.

## Changes

- 2026-07-22 B005 UID0003Q0 callback: retained `88/92` and the existing base formal; added exact DeleteReplyAlert constructor/base-call, inherited `m_layoutReference`, primary-slot `OnPrimaryButton`, and derived-tail boundary evidence.
- What existed before: the page contained strong constructor/dismiss/vtable/layout evidence but still had unevaluated `0/0` metadata.
- What it was changed to: scores were set to `82/90`; no ownership change was made.
- Summary and evidence: existing IDA MCP checks confirm function boundaries, broad constructor fan-in, vtable bases, layout offsets, and derived alert dispatch behavior. Remaining uncertainty is mostly final callback naming and derived wrapper boundaries.
- What existed before: the class was documented as reconstructable in prose but validator `RECONSTRUCTABLE` metadata was blank.
- What it was changed to: `RECONSTRUCTABLE` is set to `TRUE`; C++ remains blank because final callback names and derived wrapper boundaries are below the `95+` final-source gate.
- Summary/evidence: 2026-05-31 IDA MCP reconfirmed the class vtable bases, constructor vptr stores, and exact vtable-data child range.
- 2026-06-06 provenance cleanup: replaced the stale recovered-file path with the current IDA/by-* evidence basis. Scores and ownership metadata are unchanged.
- 2026-06-07 parent attachment:
  - Before: the class was reconstructable but parentless even though its likely source file was documented.
  - Changed to: `AUTOGEN_PARENT_UID:0000HE`; final class C++ remains blank.
  - Evidence: [UID:0000HE][AlertPanes](by-file/AlertPanes.md) is now `82/86` with valid `NexusTK/ui/dialogs/` placement and records the base alert family, exact vtable-data children, shared destructor, layout, and feature-specific exclusions. This class remains below the final C++ gate because callback names and source-quality class declaration details still need audit.
- 2026-06-17 B002 source-quality execution:
  - Changed from: `82/90`, blank formal C++, and callback/signature questions still listed as open.
  - Changed to: `88/92` with declaration-only first-draft C++.
  - Evidence: live IDA reconfirmed the `0x6c5` constructor, `0x106` dismiss/action virtual, 96 constructor xrefs, three vtable stores, `DismissDialog(int buttonId, int unused)` ABI, no-argument `OnPrimaryButton`/`OnSecondaryButton` slots, `m_layoutReference` at `+0x26c`, shared scalar-destructor/thunk compiler policy, derived-wrapper boundaries, and `AlertPanes.cpp` ownership. Method bodies remain blank in child pages pending shared DialogPane/control-helper names.
